// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// A concrete interpreter for the Multiplier IR. Walks the CFG, evaluates
// instructions, and tracks memory state. Designed as testing infrastructure
// to shake out IR generation bugs and validate the API surface.
//
// Usage: mx-interpret-ir --db /path/to/index.db --entity_name "function_name"
//
// Critique notes (embedded for future reference):
// - The IR API requires downcasting to get result_type() from most instructions.
//   A base-class result_type() would simplify the interpreter significantly.
// - IRObject doesn't expose string literal bytes, so STRING_LITERAL objects
//   are initialized to zero. An interpreter needs this data.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <limits>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <variant>
#include <vector>

#include "Index.h"
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/StructureKinds.h>

DEFINE_uint64(entity_id, mx::kInvalidEntityId, "ID of the entity to interpret");
DEFINE_string(entity_name, "", "Name of the function to interpret");
DEFINE_bool(trace, false, "Print each instruction as it executes");
DEFINE_uint64(max_steps, 100000, "Maximum instruction steps before aborting");

namespace {

// ---------------------------------------------------------------------------
// Value representation
// ---------------------------------------------------------------------------

// A value is either an integer, a float, or a pointer (object + byte offset).
struct Pointer {
  mx::RawEntityId object_id{mx::kInvalidEntityId};
  int64_t offset{0};

  bool operator==(const Pointer &o) const {
    return object_id == o.object_id && offset == o.offset;
  }
};

struct Value {
  enum Kind { UNDEFINED, INTEGER, FLOATING, POINTER } kind{UNDEFINED};
  int64_t ival{0};
  double fval{0.0};
  Pointer ptr{};

  static Value Int(int64_t v) { return {INTEGER, v, 0.0, {}}; }
  static Value Float(double v) { return {FLOATING, 0, v, {}}; }
  static Value Ptr(mx::RawEntityId obj, int64_t off = 0) {
    return {POINTER, 0, 0.0, {obj, off}};
  }
  static Value Undef() { return {}; }

  bool is_truthy() const {
    switch (kind) {
      case INTEGER: return ival != 0;
      case FLOATING: return fval != 0.0;
      case POINTER: return ptr.object_id != mx::kInvalidEntityId;
      default: return false;
    }
  }

  int64_t as_int() const { return ival; }
  double as_float() const { return fval; }
};

// ---------------------------------------------------------------------------
// Memory model
// ---------------------------------------------------------------------------

struct MemoryObject {
  std::vector<uint8_t> bytes;
  bool allocated{false};
  bool poisoned{false};  // Set when scope exits
};

// ---------------------------------------------------------------------------
// Interpreter state
// ---------------------------------------------------------------------------

class Interpreter {
 public:
  Interpreter(const mx::IRFunction &func, bool trace)
      : func_(func), trace_(trace) {}

  // Run the interpreter. Returns the return value (or UNDEFINED for void).
  Value Run(const std::vector<Value> &args);

 private:
  const mx::IRFunction &func_;
  bool trace_;

  // Instruction ID → computed value.
  std::unordered_map<mx::RawEntityId, Value> values_;

  // Object ID → memory.
  std::unordered_map<mx::RawEntityId, MemoryObject> memory_;

  // Block ID → IRBlock (for CFG navigation).
  std::unordered_map<mx::RawEntityId, mx::IRBlock> block_map_;

  // Parameter values passed to the function.
  std::vector<Value> params_;

  uint64_t steps_{0};

  // Evaluate a single instruction, storing result in values_.
  void Eval(const mx::IRInstruction &inst);

  // Get the value of an instruction (must have been evaluated already).
  Value GetValue(const mx::IRInstruction &inst);

  // Memory operations.
  void MemWrite(const Pointer &ptr, const void *data, size_t len);
  void MemRead(const Pointer &ptr, void *data, size_t len);
  void MemWriteValue(const Pointer &ptr, const Value &val, size_t size);
  Value MemReadValue(const Pointer &ptr, size_t size, bool is_float);

  // Allocate memory for an object.
  void AllocateObject(const mx::IRObject &obj);

  // Trace output.
  void Trace(const mx::IRInstruction &inst, const Value &result);
};

// ---------------------------------------------------------------------------
// Memory implementation
// ---------------------------------------------------------------------------

void Interpreter::AllocateObject(const mx::IRObject &obj) {
  auto eid = mx::EntityId(obj.id()).Pack();
  auto &mem = memory_[eid];
  uint32_t size = obj.size_bytes();
  if (size == 0) size = 8;  // Default for unknown-size objects.
  mem.bytes.resize(size, 0);
  mem.allocated = true;
  mem.poisoned = false;
}

void Interpreter::MemWrite(const Pointer &ptr, const void *data, size_t len) {
  auto it = memory_.find(ptr.object_id);
  if (it == memory_.end()) {
    LOG(WARNING) << "Write to unallocated object " << ptr.object_id;
    return;
  }
  auto &mem = it->second;
  if (mem.poisoned) {
    LOG(WARNING) << "Write to poisoned (out-of-scope) object " << ptr.object_id;
  }
  size_t start = static_cast<size_t>(ptr.offset);
  if (start + len > mem.bytes.size()) {
    LOG(WARNING) << "Write out of bounds: offset=" << start
                 << " len=" << len << " size=" << mem.bytes.size();
    return;
  }
  std::memcpy(mem.bytes.data() + start, data, len);
}

void Interpreter::MemRead(const Pointer &ptr, void *data, size_t len) {
  auto it = memory_.find(ptr.object_id);
  if (it == memory_.end()) {
    LOG(WARNING) << "Read from unallocated object " << ptr.object_id;
    std::memset(data, 0, len);
    return;
  }
  auto &mem = it->second;
  if (mem.poisoned) {
    LOG(WARNING) << "Read from poisoned (out-of-scope) object " << ptr.object_id;
  }
  size_t start = static_cast<size_t>(ptr.offset);
  if (start + len > mem.bytes.size()) {
    LOG(WARNING) << "Read out of bounds: offset=" << start
                 << " len=" << len << " size=" << mem.bytes.size();
    std::memset(data, 0, len);
    return;
  }
  std::memcpy(data, mem.bytes.data() + start, len);
}

void Interpreter::MemWriteValue(const Pointer &ptr, const Value &val,
                                 size_t size) {
  if (val.kind == Value::POINTER) {
    // Store pointer as raw bytes (object_id + offset).
    MemWrite(ptr, &val.ptr, sizeof(val.ptr));
  } else if (val.kind == Value::FLOATING) {
    if (size == 4) {
      float f = static_cast<float>(val.fval);
      MemWrite(ptr, &f, 4);
    } else {
      MemWrite(ptr, &val.fval, 8);
    }
  } else {
    // Integer or undefined — write as int.
    MemWrite(ptr, &val.ival, std::min(size, sizeof(val.ival)));
  }
}

Value Interpreter::MemReadValue(const Pointer &ptr, size_t size,
                                 bool is_float) {
  if (is_float) {
    if (size == 4) {
      float f = 0;
      MemRead(ptr, &f, 4);
      return Value::Float(static_cast<double>(f));
    }
    double d = 0;
    MemRead(ptr, &d, 8);
    return Value::Float(d);
  }
  int64_t v = 0;
  MemRead(ptr, &v, std::min(size, sizeof(v)));
  return Value::Int(v);
}

// ---------------------------------------------------------------------------
// Value access
// ---------------------------------------------------------------------------

Value Interpreter::GetValue(const mx::IRInstruction &inst) {
  auto eid = mx::EntityId(inst.id()).Pack();
  auto it = values_.find(eid);
  if (it != values_.end()) return it->second;
  return Value::Undef();
}

// ---------------------------------------------------------------------------
// Trace
// ---------------------------------------------------------------------------

void Interpreter::Trace(const mx::IRInstruction &inst, const Value &result) {
  if (!trace_) return;
  std::cerr << "  [" << steps_ << "] "
            << static_cast<unsigned>(inst.opcode());
  switch (result.kind) {
    case Value::INTEGER:
      std::cerr << " → " << result.ival;
      break;
    case Value::FLOATING:
      std::cerr << " → " << result.fval;
      break;
    case Value::POINTER:
      std::cerr << " → ptr(" << result.ptr.object_id
                << "+" << result.ptr.offset << ")";
      break;
    default:
      std::cerr << " → undef";
      break;
  }
  std::cerr << "\n";
}

// ---------------------------------------------------------------------------
// Instruction evaluation
// ---------------------------------------------------------------------------

void Interpreter::Eval(const mx::IRInstruction &inst) {
  auto op = inst.opcode();
  auto eid = mx::EntityId(inst.id()).Pack();
  Value result = Value::Undef();

  switch (op) {

    // --- Constants ---
    case mx::ir::OpCode::CONST: {
      if (auto ci = mx::ConstInst::from(inst)) {
        auto sub = ci->sub_opcode();
        if (sub == mx::ir::ConstOp::NULL_PTR) {
          result = Value::Ptr(mx::kInvalidEntityId, 0);
        } else if (sub == mx::ir::ConstOp::FLOAT32 ||
                   sub == mx::ir::ConstOp::FLOAT64 ||
                   sub == mx::ir::ConstOp::FLOAT16) {
          result = Value::Float(ci->float_value());
        } else {
          result = Value::Int(ci->signed_value());
        }
      }
      break;
    }

    // --- Memory ---
    case mx::ir::OpCode::ALLOCA: {
      if (auto ai = mx::AllocaInst::from(inst)) {
        auto obj = ai->object();
        auto obj_eid = mx::EntityId(obj.id()).Pack();
        AllocateObject(obj);
        result = Value::Ptr(obj_eid, 0);
      }
      break;
    }
    case mx::ir::OpCode::MEMORY: {
      if (auto mi = mx::MemoryInst::from(inst)) {
        auto sub = mi->sub_opcode();
        if (mx::ir::IsDirectLoadStore(sub)) {
          unsigned sz = mx::ir::AccessSize(sub);
          if (mx::ir::IsAnyLoad(sub)) {
            Value addr = GetValue(mi->address());
            if (addr.kind == Value::POINTER) {
              result = MemReadValue(addr.ptr, sz, false);
            } else {
              LOG(WARNING) << "MEMORY load from non-pointer value";
            }
          } else {
            // Store.
            Value addr = GetValue(mi->address());
            Value val = GetValue(mi->stored_value());
            if (addr.kind == Value::POINTER) {
              MemWriteValue(addr.ptr, val, sz);
            } else {
              LOG(WARNING) << "MEMORY store to non-pointer value";
            }
          }
        } else {
          // Bulk memory/string operations.
          auto ops_gen = inst.operands();
          std::vector<Value> ops;
          for (auto op_inst : ops_gen) {
            ops.push_back(GetValue(op_inst));
          }
          using MO = mx::ir::MemOp;
          switch (sub) {
            case MO::MEMSET: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER && ops[2].as_int() > 0) {
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  size_t len = static_cast<size_t>(ops[2].as_int());
                  size_t end = std::min(start + len, it->second.bytes.size());
                  std::memset(it->second.bytes.data() + start,
                              static_cast<int>(ops[1].as_int()), end - start);
                }
              }
              result = ops.empty() ? Value::Undef() : ops[0];
              break;
            }
            case MO::MEMCPY:
            case MO::MEMMOVE: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER && ops[2].as_int() > 0) {
                size_t len = static_cast<size_t>(ops[2].as_int());
                std::vector<uint8_t> tmp(len);
                MemRead(ops[1].ptr, tmp.data(), len);
                MemWrite(ops[0].ptr, tmp.data(), len);
              }
              result = ops.empty() ? Value::Undef() : ops[0];
              break;
            }
            case MO::BZERO: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER && ops[1].as_int() > 0) {
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  size_t len = static_cast<size_t>(ops[1].as_int());
                  size_t end = std::min(start + len, it->second.bytes.size());
                  std::memset(it->second.bytes.data() + start, 0, end - start);
                }
              }
              result = ops.empty() ? Value::Undef() : ops[0];
              break;
            }
            case MO::STRLEN: {
              if (ops.size() >= 1 && ops[0].kind == Value::POINTER) {
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  size_t len = 0;
                  while (start + len < it->second.bytes.size() &&
                         it->second.bytes[start + len] != 0) ++len;
                  result = Value::Int(static_cast<int64_t>(len));
                }
              }
              break;
            }
            case MO::STRCMP: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                auto it0 = memory_.find(ops[0].ptr.object_id);
                auto it1 = memory_.find(ops[1].ptr.object_id);
                if (it0 != memory_.end() && it1 != memory_.end()) {
                  size_t s0 = static_cast<size_t>(ops[0].ptr.offset);
                  size_t s1 = static_cast<size_t>(ops[1].ptr.offset);
                  int cmp = 0;
                  while (true) {
                    uint8_t c0 = (s0 < it0->second.bytes.size()) ? it0->second.bytes[s0] : 0;
                    uint8_t c1 = (s1 < it1->second.bytes.size()) ? it1->second.bytes[s1] : 0;
                    if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
                    if (c0 == 0) break;
                    ++s0; ++s1;
                  }
                  result = Value::Int(cmp);
                }
              }
              break;
            }
            case MO::MEMCMP: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                size_t len = static_cast<size_t>(ops[2].as_int());
                std::vector<uint8_t> buf0(len, 0), buf1(len, 0);
                MemRead(ops[0].ptr, buf0.data(), len);
                MemRead(ops[1].ptr, buf1.data(), len);
                result = Value::Int(std::memcmp(buf0.data(), buf1.data(), len));
              }
              break;
            }
            case MO::MEMCHR: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER) {
                size_t len = static_cast<size_t>(ops[2].as_int());
                uint8_t needle = static_cast<uint8_t>(ops[1].as_int());
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  for (size_t i = 0; i < len && start + i < it->second.bytes.size(); ++i) {
                    if (it->second.bytes[start + i] == needle) {
                      result = Value::Ptr(ops[0].ptr.object_id,
                                          ops[0].ptr.offset + static_cast<int64_t>(i));
                      break;
                    }
                  }
                }
              }
              break;
            }
            default:
              break;
          }
        }
      }
      break;
    }
    case mx::ir::OpCode::GEP_FIELD: {
      if (auto gep = mx::GEPFieldInst::from(inst)) {
        Value base = GetValue(gep->base());
        int64_t off = gep->byte_offset();
        if (base.kind == Value::POINTER) {
          result = Value::Ptr(base.ptr.object_id, base.ptr.offset + off);
        }
      }
      break;
    }
    case mx::ir::OpCode::PTR_ADD: {
      if (auto pa = mx::PtrAddInst::from(inst)) {
        Value base = GetValue(pa->base());
        Value idx = GetValue(pa->index());
        int64_t elem_size = pa->element_size();
        if (base.kind == Value::POINTER) {
          result = Value::Ptr(base.ptr.object_id,
                              base.ptr.offset + idx.as_int() * elem_size);
        }
      }
      break;
    }

    // --- Binary arithmetic ---
    case mx::ir::OpCode::ADD: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::FLOATING || r.kind == Value::FLOATING)
          result = Value::Float(l.as_float() + r.as_float());
        else
          result = Value::Int(l.as_int() + r.as_int());
      }
      break;
    }
    case mx::ir::OpCode::SUB: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::FLOATING || r.kind == Value::FLOATING)
          result = Value::Float(l.as_float() - r.as_float());
        else
          result = Value::Int(l.as_int() - r.as_int());
      }
      break;
    }
    case mx::ir::OpCode::MUL: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::FLOATING || r.kind == Value::FLOATING)
          result = Value::Float(l.as_float() * r.as_float());
        else
          result = Value::Int(l.as_int() * r.as_int());
      }
      break;
    }
    case mx::ir::OpCode::DIV: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::FLOATING || r.kind == Value::FLOATING)
          result = Value::Float(r.as_float() != 0 ? l.as_float() / r.as_float() : 0.0);
        else
          result = Value::Int(r.as_int() != 0 ? l.as_int() / r.as_int() : 0);
      }
      break;
    }
    case mx::ir::OpCode::REM: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::FLOATING || r.kind == Value::FLOATING)
          result = Value::Float(std::fmod(l.as_float(), r.as_float()));
        else
          result = Value::Int(r.as_int() != 0 ? l.as_int() % r.as_int() : 0);
      }
      break;
    }
    case mx::ir::OpCode::BIT_AND: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) result = Value::Int(GetValue(bin->lhs()).as_int() & GetValue(bin->rhs()).as_int());
      break;
    }
    case mx::ir::OpCode::BIT_OR: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) result = Value::Int(GetValue(bin->lhs()).as_int() | GetValue(bin->rhs()).as_int());
      break;
    }
    case mx::ir::OpCode::BIT_XOR: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) result = Value::Int(GetValue(bin->lhs()).as_int() ^ GetValue(bin->rhs()).as_int());
      break;
    }
    case mx::ir::OpCode::SHL: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) result = Value::Int(GetValue(bin->lhs()).as_int() << GetValue(bin->rhs()).as_int());
      break;
    }
    case mx::ir::OpCode::SHR: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        // Arithmetic shift right (sign-extending).
        result = Value::Int(GetValue(bin->lhs()).as_int() >> GetValue(bin->rhs()).as_int());
      }
      break;
    }
    case mx::ir::OpCode::LOGICAL_AND: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        // Short-circuit: IR keeps both sides evaluated in the tree.
        // The conditionally-executed flag handles the real short-circuit.
        bool l = GetValue(bin->lhs()).is_truthy();
        bool r = GetValue(bin->rhs()).is_truthy();
        result = Value::Int(l && r ? 1 : 0);
      }
      break;
    }
    case mx::ir::OpCode::LOGICAL_OR: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        bool l = GetValue(bin->lhs()).is_truthy();
        bool r = GetValue(bin->rhs()).is_truthy();
        result = Value::Int(l || r ? 1 : 0);
      }
      break;
    }
    case mx::ir::OpCode::PTR_DIFF: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        Value l = GetValue(bin->lhs()), r = GetValue(bin->rhs());
        if (l.kind == Value::POINTER && r.kind == Value::POINTER) {
          result = Value::Int(l.ptr.offset - r.ptr.offset);
        }
      }
      break;
    }

    // --- Comparisons ---
    case mx::ir::OpCode::CMP_EQ:
    case mx::ir::OpCode::CMP_NE:
    case mx::ir::OpCode::CMP_LT:
    case mx::ir::OpCode::CMP_LE:
    case mx::ir::OpCode::CMP_GT:
    case mx::ir::OpCode::CMP_GE: {
      auto cmp = mx::ComparisonInst::from(inst);
      if (cmp) {
        Value l = GetValue(cmp->lhs()), r = GetValue(cmp->rhs());
        bool use_float = (l.kind == Value::FLOATING || r.kind == Value::FLOATING);
        bool res = false;
        if (use_float) {
          double lv = l.as_float(), rv = r.as_float();
          switch (op) {
            case mx::ir::OpCode::CMP_EQ: res = lv == rv; break;
            case mx::ir::OpCode::CMP_NE: res = lv != rv; break;
            case mx::ir::OpCode::CMP_LT: res = lv < rv; break;
            case mx::ir::OpCode::CMP_LE: res = lv <= rv; break;
            case mx::ir::OpCode::CMP_GT: res = lv > rv; break;
            case mx::ir::OpCode::CMP_GE: res = lv >= rv; break;
            default: break;
          }
        } else {
          int64_t lv = l.as_int(), rv = r.as_int();
          switch (op) {
            case mx::ir::OpCode::CMP_EQ: res = lv == rv; break;
            case mx::ir::OpCode::CMP_NE: res = lv != rv; break;
            case mx::ir::OpCode::CMP_LT: res = lv < rv; break;
            case mx::ir::OpCode::CMP_LE: res = lv <= rv; break;
            case mx::ir::OpCode::CMP_GT: res = lv > rv; break;
            case mx::ir::OpCode::CMP_GE: res = lv >= rv; break;
            default: break;
          }
        }
        result = Value::Int(res ? 1 : 0);
      }
      break;
    }

    // --- Unary ---
    case mx::ir::OpCode::NEG: {
      auto u = mx::UnaryInst::from(inst);
      if (u) {
        Value v = GetValue(u->operand());
        if (v.kind == Value::FLOATING) result = Value::Float(-v.fval);
        else result = Value::Int(-v.ival);
      }
      break;
    }
    case mx::ir::OpCode::BIT_NOT: {
      auto u = mx::UnaryInst::from(inst);
      if (u) result = Value::Int(~GetValue(u->operand()).as_int());
      break;
    }
    case mx::ir::OpCode::LOGICAL_NOT: {
      auto u = mx::UnaryInst::from(inst);
      if (u) result = Value::Int(GetValue(u->operand()).is_truthy() ? 0 : 1);
      break;
    }

    // --- Casts ---
    case mx::ir::OpCode::CAST: {
      auto c = mx::CastInst::from(inst);
      if (c) {
        auto sub = c->sub_opcode();
        Value v = GetValue(c->operand());
        if (sub == mx::ir::CastOp::BITCAST || sub == mx::ir::CastOp::IDENTITY) {
          result = v;
        } else if (sub >= mx::ir::CastOp::PTR_TO_I32 &&
                   sub <= mx::ir::CastOp::PTR_TO_I64) {
          result = Value::Int(v.kind == Value::POINTER ? v.ptr.offset : v.ival);
        } else if (sub >= mx::ir::CastOp::I32_TO_PTR &&
                   sub <= mx::ir::CastOp::I64_TO_PTR) {
          result = Value::Ptr(mx::kInvalidEntityId, v.as_int());
        } else if (mx::ir::IsFloatToInt(sub)) {
          result = Value::Int(static_cast<int64_t>(v.as_float()));
        } else if (mx::ir::IsIntToFloat(sub)) {
          result = Value::Float(static_cast<double>(v.as_int()));
        } else if (sub == mx::ir::CastOp::F32_TO_F64 ||
                   sub == mx::ir::CastOp::F64_TO_F32) {
          result = Value::Float(v.as_float());
        } else {
          // Sign/zero extend, truncate -- all int-to-int.
          result = Value::Int(v.as_int());
        }
      }
      break;
    }

    // --- Read-modify-write (inc/dec, compound assign) ---
    case mx::ir::OpCode::READ_MODIFY_WRITE: {
      if (auto rmw = mx::ReadModifyWriteInst::from(inst)) {
        Value addr = GetValue(rmw->address());
        if (addr.kind == Value::POINTER) {
          Value old_val = MemReadValue(addr.ptr, 8, false);
          // Collect RHS operands (typically one value).
          Value rhs = Value::Int(0);
          for (auto rhs_op : rmw->rhs_operands()) {
            rhs = GetValue(rhs_op);
            break;  // Use first RHS operand.
          }
          Value new_val;
          auto underlying = rmw->underlying_op();
          switch (underlying) {
            case mx::ir::OpCode::ADD: new_val = Value::Int(old_val.as_int() + rhs.as_int()); break;
            case mx::ir::OpCode::SUB: new_val = Value::Int(old_val.as_int() - rhs.as_int()); break;
            case mx::ir::OpCode::MUL: new_val = Value::Int(old_val.as_int() * rhs.as_int()); break;
            case mx::ir::OpCode::DIV: new_val = Value::Int(rhs.as_int() ? old_val.as_int() / rhs.as_int() : 0); break;
            case mx::ir::OpCode::REM: new_val = Value::Int(rhs.as_int() ? old_val.as_int() % rhs.as_int() : 0); break;
            case mx::ir::OpCode::BIT_AND: new_val = Value::Int(old_val.as_int() & rhs.as_int()); break;
            case mx::ir::OpCode::BIT_OR: new_val = Value::Int(old_val.as_int() | rhs.as_int()); break;
            case mx::ir::OpCode::BIT_XOR: new_val = Value::Int(old_val.as_int() ^ rhs.as_int()); break;
            case mx::ir::OpCode::SHL: new_val = Value::Int(old_val.as_int() << rhs.as_int()); break;
            case mx::ir::OpCode::SHR: new_val = Value::Int(old_val.as_int() >> rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_ADD: new_val = Value::Int(old_val.as_int() + rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_SUB: new_val = Value::Int(old_val.as_int() - rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_AND: new_val = Value::Int(old_val.as_int() & rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_OR: new_val = Value::Int(old_val.as_int() | rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_XOR: new_val = Value::Int(old_val.as_int() ^ rhs.as_int()); break;
            case mx::ir::OpCode::ATOMIC_NAND: new_val = Value::Int(~(old_val.as_int() & rhs.as_int())); break;
            case mx::ir::OpCode::ATOMIC_EXCHANGE: new_val = rhs; break;
            case mx::ir::OpCode::PTR_ADD: {
              int64_t elem_sz = rmw->element_size();
              if (elem_sz <= 0) elem_sz = 1;
              if (old_val.kind == Value::POINTER) {
                new_val = Value::Ptr(old_val.ptr.object_id,
                                     old_val.ptr.offset + rhs.as_int() * elem_sz);
              } else {
                new_val = Value::Int(old_val.as_int() + rhs.as_int() * elem_sz);
              }
              break;
            }
            // Overflow-checked arithmetic: RMW stores the result, returns
            // the overflow flag (bool).
            case mx::ir::OpCode::ADD_OVERFLOW:
            case mx::ir::OpCode::SUB_OVERFLOW:
            case mx::ir::OpCode::MUL_OVERFLOW: {
              Value a = Value::Int(0), b = Value::Int(0);
              int rhs_i = 0;
              for (auto rhs_op : rmw->rhs_operands()) {
                if (rhs_i == 0) a = GetValue(rhs_op);
                else if (rhs_i == 1) b = GetValue(rhs_op);
                ++rhs_i;
              }
              __int128 wide;
              if (underlying == mx::ir::OpCode::ADD_OVERFLOW)
                wide = static_cast<__int128>(a.as_int()) + static_cast<__int128>(b.as_int());
              else if (underlying == mx::ir::OpCode::SUB_OVERFLOW)
                wide = static_cast<__int128>(a.as_int()) - static_cast<__int128>(b.as_int());
              else
                wide = static_cast<__int128>(a.as_int()) * static_cast<__int128>(b.as_int());
              new_val = Value::Int(static_cast<int64_t>(wide));
              bool overflow = (wide != static_cast<__int128>(static_cast<int64_t>(wide)));
              MemWriteValue(addr.ptr, new_val, 8);
              result = Value::Int(overflow ? 1 : 0);
              break;
            }
            default: new_val = old_val; break;
          }
          if (underlying != mx::ir::OpCode::ADD_OVERFLOW &&
              underlying != mx::ir::OpCode::SUB_OVERFLOW &&
              underlying != mx::ir::OpCode::MUL_OVERFLOW) {
            MemWriteValue(addr.ptr, new_val, 8);
            result = rmw->returns_new_value() ? new_val : old_val;
          }
        }
      }
      break;
    }

    // --- Call ---
    case mx::ir::OpCode::CALL: {
      if (auto ci = mx::CallInst::from(inst)) {
        // Collect argument values.
        std::vector<Value> call_args;
        for (auto arg : ci->arguments()) {
          // VA_PACK groups variadic args — flatten them.
          if (arg.opcode() == mx::ir::OpCode::VA_PACK) {
            for (auto va_arg : arg.operands()) {
              call_args.push_back(GetValue(va_arg));
            }
          } else {
            call_args.push_back(GetValue(arg));
          }
        }

        auto target = ci->target();
        if (target) {
          // Try to find IR for the callee.
          auto callee_ir = mx::IRFunction::from(*target);
          if (callee_ir) {
            if (trace_) {
              std::cerr << "  >> Entering call to " << target->name() << "\n";
            }
            Interpreter callee_interp(*callee_ir, trace_);
            result = callee_interp.Run(call_args);
            if (trace_) {
              std::cerr << "  << Returned from " << target->name() << "\n";
            }
          } else {
            LOG(INFO) << "CALL to " << target->name()
                      << " (no IR available, returning undef)";
          }
        } else {
          LOG(INFO) << "Indirect CALL (not interpreted)";
        }
      }
      break;
    }

    // --- Select (ternary) ---
    case mx::ir::OpCode::SELECT: {
      if (auto sel = mx::SelectInst::from(inst)) {
        Value cond = GetValue(sel->condition());
        result = cond.is_truthy() ? GetValue(sel->true_value())
                                  : GetValue(sel->false_value());
      }
      break;
    }

    // --- Last value (comma operator) ---
    case mx::ir::OpCode::LAST_VALUE: {
      // All operands already evaluated (post-order). Return the last.
      if (auto lv = mx::LastValueInst::from(inst)) {
        result = GetValue(lv->last());
      }
      break;
    }


    // --- Param read ---
    case mx::ir::OpCode::PARAM_READ: {
      if (auto pr = mx::ParamReadInst::from(inst)) {
        uint32_t idx = pr->parameter_index();
        if (idx < params_.size()) {
          result = params_[idx];
        } else {
          LOG(WARNING) << "PARAM_READ index " << idx
                       << " out of range (have " << params_.size() << " args)";
        }
      }
      break;
    }

    // MULTIMEM removed: merged into MEMORY case above.

    // --- Bitwise/intrinsic operations ---
    case mx::ir::OpCode::BITWISE: {
      if (auto bw = mx::BitwiseOpInst::from(inst)) {
        // Get the primary operand (op[0]).
        Value val = Value::Undef();
        auto ops = inst.operands();
        for (auto op_inst : ops) {
          val = GetValue(op_inst);
          break;
        }
        int64_t v = val.as_int();
        using BO = mx::ir::BitwiseOp;
        switch (bw->sub_opcode()) {
          case BO::BSWAP16:
            result = Value::Int(static_cast<int64_t>(__builtin_bswap16(
                static_cast<uint16_t>(v))));
            break;
          case BO::BSWAP32:
            result = Value::Int(static_cast<int64_t>(__builtin_bswap32(
                static_cast<uint32_t>(v))));
            break;
          case BO::BSWAP64:
            result = Value::Int(static_cast<int64_t>(__builtin_bswap64(
                static_cast<uint64_t>(v))));
            break;
          case BO::POPCOUNT:
            result = Value::Int(__builtin_popcountll(static_cast<uint64_t>(v)));
            break;
          case BO::CLZ:
            result = v ? Value::Int(__builtin_clzll(static_cast<uint64_t>(v)))
                       : Value::Undef();
            break;
          case BO::CTZ:
            result = v ? Value::Int(__builtin_ctzll(static_cast<uint64_t>(v)))
                       : Value::Undef();
            break;
          case BO::FFS:
            result = Value::Int(__builtin_ffsll(v));
            break;
          case BO::PARITY:
            result = Value::Int(__builtin_parityll(static_cast<uint64_t>(v)));
            break;
          case BO::ABS:
            result = Value::Int(v < 0 ? -v : v);
            break;
          case BO::EXPECT:
            result = val;  // identity
            break;
          case BO::ASSUME:
            result = Value::Undef();  // no-op
            break;
          default:
            result = val;
            break;
        }
      }
      break;
    }

    // --- Floating-point operations ---
    case mx::ir::OpCode::FLOAT: {
      if (auto fo = mx::FloatOpInst::from(inst)) {
        // Collect operands.
        std::vector<Value> ops;
        for (auto op_inst : inst.operands()) {
          ops.push_back(GetValue(op_inst));
        }
        using FO = mx::ir::FloatOp;
        switch (fo->sub_opcode()) {
          case FO::FABS:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::fabs(ops[0].as_float()));
            break;
          case FO::SQRT:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::sqrt(ops[0].as_float()));
            break;
          case FO::CEIL:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::ceil(ops[0].as_float()));
            break;
          case FO::FLOOR:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::floor(ops[0].as_float()));
            break;
          case FO::ROUND:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::round(ops[0].as_float()));
            break;
          case FO::TRUNC:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::trunc(ops[0].as_float()));
            break;
          case FO::FMIN:
            result = (ops.size() >= 2)
                ? Value::Float(std::fmin(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::FMAX:
            result = (ops.size() >= 2)
                ? Value::Float(std::fmax(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::COPYSIGN:
            result = (ops.size() >= 2)
                ? Value::Float(std::copysign(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::ISNAN:
            result = ops.empty() ? Value::Undef()
                : Value::Int(std::isnan(ops[0].as_float()) ? 1 : 0);
            break;
          case FO::ISINF:
            result = ops.empty() ? Value::Undef()
                : Value::Int(std::isinf(ops[0].as_float()) ? 1 : 0);
            break;
          case FO::ISFINITE:
            result = ops.empty() ? Value::Undef()
                : Value::Int(std::isfinite(ops[0].as_float()) ? 1 : 0);
            break;
          case FO::INF:
            result = Value::Float(std::numeric_limits<double>::infinity());
            break;
          case FO::NAN_VAL:
            result = Value::Float(std::numeric_limits<double>::quiet_NaN());
            break;
          case FO::FLOAT_HUGE:
            result = Value::Float(std::numeric_limits<double>::infinity());
            break;
          default:
            result = Value::Undef();
            break;
        }
      }
      break;
    }

    // --- Dynamic alloca / frame-return address ---
    case mx::ir::OpCode::DYNAMIC_ALLOCA:
    case mx::ir::OpCode::FRAME_PTR:
    case mx::ir::OpCode::RETURN_PTR:
      // Not meaningfully interpretable; return undef.
      result = Value::Undef();
      break;

    // --- Atomic operations ---
    case mx::ir::OpCode::ATOMIC_CMPXCHG:
      // Simplified: return undef (complex semantics).
      result = Value::Undef();
      break;

    // --- Undefined/poison value ---
    case mx::ir::OpCode::UNDEFINED:
      result = Value::Undef();
      break;

    // --- Overflow opcodes (only valid as RMW underlying ops, not standalone) ---
    case mx::ir::OpCode::ADD_OVERFLOW:
    case mx::ir::OpCode::SUB_OVERFLOW:
    case mx::ir::OpCode::MUL_OVERFLOW:
    case mx::ir::OpCode::ATOMIC_ADD:
    case mx::ir::OpCode::ATOMIC_SUB:
    case mx::ir::OpCode::ATOMIC_AND:
    case mx::ir::OpCode::ATOMIC_OR:
    case mx::ir::OpCode::ATOMIC_XOR:
    case mx::ir::OpCode::ATOMIC_NAND:
    case mx::ir::OpCode::ATOMIC_EXCHANGE:
      LOG(WARNING) << "RMW-only opcode used as standalone instruction";
      break;

    // --- Variadic ---
    case mx::ir::OpCode::VA_START:
    case mx::ir::OpCode::VA_END:
    case mx::ir::OpCode::VA_COPY:
    case mx::ir::OpCode::VA_ARG:
    case mx::ir::OpCode::VA_PACK: {
      // CRITIQUE: Variadic args need a runtime va_list model. Not implemented
      // in this simple interpreter. VA_ARG returns undef.
      break;
    }

    // --- Global/function address ---
    case mx::ir::OpCode::GLOBAL_PTR:
    case mx::ir::OpCode::THREAD_LOCAL_PTR: {
      // In a real interpreter, this would look up the global/TLS storage.
      // For now, create a synthetic pointer using the target entity ID.
      result = Value::Ptr(inst.source_entity_id(), 0);
      break;
    }
    case mx::ir::OpCode::FUNC_PTR: {
      // Function pointer — use the source entity ID as a handle.
      result = Value::Ptr(inst.source_entity_id(), 0);
      break;
    }

    // --- Scope markers: track object lifetimes ---
    case mx::ir::OpCode::ENTER_SCOPE: {
      if (auto esi = mx::EnterScopeInst::from(inst)) {
        auto scope = esi->scope();
        for (auto obj : scope.objects()) {
          auto oid = mx::EntityId(obj.id()).Pack();
          auto it = memory_.find(oid);
          if (it != memory_.end()) {
            it->second.poisoned = false;  // Re-entering scope (loop iteration).
          }
        }
      }
      break;
    }
    case mx::ir::OpCode::EXIT_SCOPE: {
      if (auto esi = mx::ExitScopeInst::from(inst)) {
        auto scope = esi->scope();
        for (auto obj : scope.objects()) {
          auto oid = mx::EntityId(obj.id()).Pack();
          auto it = memory_.find(oid);
          if (it != memory_.end()) {
            it->second.poisoned = true;  // Object lifetime ended.
          }
        }
      }
      break;
    }

    // --- Terminators are handled by the CFG walker, not here ---
    case mx::ir::OpCode::COND_BRANCH:
    case mx::ir::OpCode::SWITCH:
    case mx::ir::OpCode::RET:
    case mx::ir::OpCode::UNREACHABLE:
    case mx::ir::OpCode::IMPLICIT_UNREACHABLE:
    case mx::ir::OpCode::BREAK:
    case mx::ir::OpCode::CONTINUE:
    case mx::ir::OpCode::GOTO:
    case mx::ir::OpCode::IMPLICIT_GOTO:
    case mx::ir::OpCode::FALLTHROUGH:
    case mx::ir::OpCode::IMPLICIT_FALLTHROUGH:
      break;

    case mx::ir::OpCode::UNKNOWN:
      LOG(WARNING) << "Encountered UNKNOWN opcode";
      break;
  }

  values_[eid] = result;
  Trace(inst, result);
}

// ---------------------------------------------------------------------------
// Main interpreter loop
// ---------------------------------------------------------------------------

Value Interpreter::Run(const std::vector<Value> &args) {
  params_ = args;
  values_.clear();
  memory_.clear();
  block_map_.clear();
  steps_ = 0;

  // Build block map for CFG navigation.
  for (auto block : func_.blocks()) {
    block_map_[mx::EntityId(block.id()).Pack()] = block;
  }
  // Also add the entry block (which might be FRAME, not in RPO).
  {
    auto entry = func_.entry_block();
    block_map_[mx::EntityId(entry.id()).Pack()] = entry;
  }

  // Start at the entry block (FRAME).
  mx::IRBlock current = func_.entry_block();
  Value return_value = Value::Undef();

  while (true) {
    if (steps_ >= FLAGS_max_steps) {
      LOG(ERROR) << "Interpreter exceeded max steps (" << FLAGS_max_steps << ")";
      break;
    }

    if (trace_) {
      std::cerr << "Block " << static_cast<unsigned>(current.kind())
                << " (" << mx::EntityId(current.id()).Pack() << ")\n";
    }

    // Evaluate all instructions in the block (post-order: children before
    // parents). This means sub-expressions are evaluated before their roots.
    for (auto inst : current.all_instructions()) {
      ++steps_;
      auto op = inst.opcode();

      // Non-terminator: evaluate and store result.
      if (!mx::ir::IsTerminator(op)) {
        Eval(inst);
        continue;
      }

      // --- Terminator handling ---
      if (op == mx::ir::OpCode::RET) {
        auto ri = mx::RetInst::from(inst);
        if (ri) {
          if (auto rv = ri->return_value()) {
            return_value = GetValue(*rv);
          }
        }
        goto done;
      }

      if (op == mx::ir::OpCode::UNREACHABLE ||
          op == mx::ir::OpCode::IMPLICIT_UNREACHABLE) {
        LOG(ERROR) << "Reached UNREACHABLE instruction";
        goto done;
      }

      if (op == mx::ir::OpCode::COND_BRANCH) {
        auto cb = mx::CondBranchInst::from(inst);
        if (cb) {
          Value cond = GetValue(cb->condition());
          auto target = cond.is_truthy() ? cb->true_block() : cb->false_block();
          current = target;
          goto next_block;
        }
        break;
      }

      if (op == mx::ir::OpCode::SWITCH) {
        auto sw = mx::SwitchInst::from(inst);
        if (sw) {
          Value sel = GetValue(sw->selector());
          int64_t sel_val = sel.as_int();
          bool found = false;
          mx::IRBlock default_block{};
          for (auto sc : sw->cases()) {
            if (sc.is_default()) {
              default_block = sc.target_block();
              continue;
            }
            if (sel_val >= sc.low() && sel_val <= sc.high()) {
              current = sc.target_block();
              found = true;
              break;
            }
          }
          if (!found) {
            if (default_block.id().Pack()) {
              current = default_block;
            } else {
              LOG(ERROR) << "Switch: no matching case and no default";
              goto done;
            }
          }
          goto next_block;
        }
        break;
      }

      // All other terminators (GOTO, IMPLICIT_GOTO, BREAK, CONTINUE,
      // FALLTHROUGH, IMPLICIT_FALLTHROUGH) are unconditional branches.
      {
        auto br = mx::BranchInst::from(inst);
        if (br) {
          current = br->target_block();
          goto next_block;
        }
      }
      break;
    }

    // If we fell through without a terminator (shouldn't happen with
    // well-formed IR), break.
    LOG(ERROR) << "Block ended without terminator";
    break;

    next_block:
    continue;
  }

  done:
  std::cout << "Interpreter finished after " << steps_ << " steps.\n";
  switch (return_value.kind) {
    case Value::INTEGER:
      std::cout << "Return value: " << return_value.ival << "\n";
      break;
    case Value::FLOATING:
      std::cout << "Return value: " << return_value.fval << "\n";
      break;
    case Value::POINTER:
      std::cout << "Return value: ptr(" << return_value.ptr.object_id
                << "+" << return_value.ptr.offset << ")\n";
      break;
    default:
      std::cout << "Return value: void/undef\n";
      break;
  }

  return return_value;
}

}  // namespace

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss << "Usage: " << argv[0] << " --db DATABASE --entity_name FUNC_NAME\n"
     << "Interprets the IR of the named function.";
  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(false);

  // Find the function.
  std::optional<mx::IRFunction> ir_func;

  if (FLAGS_entity_id != mx::kInvalidEntityId) {
    auto vid = mx::EntityId(FLAGS_entity_id).Unpack();
    if (auto *fid = std::get_if<mx::IRFunctionId>(&vid)) {
      // Direct entity ID lookup would go here.
      LOG(ERROR) << "Direct IRFunction ID lookup not yet supported. Use --entity_name.";
      return 1;
    }
  }

  if (!FLAGS_entity_name.empty()) {
    for (auto frag : mx::Fragment::in(index)) {
      for (auto decl : mx::Decl::in(frag)) {
        auto func_decl = mx::FunctionDecl::from(decl);
        if (!func_decl) continue;
        if (std::string(func_decl->name()) != FLAGS_entity_name) continue;
        ir_func = mx::IRFunction::from(*func_decl);
        if (ir_func) break;
      }
      if (ir_func) break;
    }
  }

  if (!ir_func) {
    LOG(ERROR) << "Could not find IR for function '" << FLAGS_entity_name << "'";
    return 1;
  }

  auto decl = ir_func->source_declaration();
  std::cout << "Interpreting IR for: "
            << (decl ? "decl" : "unknown")
            << " (kind=" << static_cast<unsigned>(ir_func->kind()) << ")\n";

  // Print summary.
  unsigned num_blocks = 0, num_insts = 0, num_objs = 0;
  for (auto b : ir_func->blocks()) {
    ++num_blocks;
    for (auto i : b.all_instructions()) { ++num_insts; (void)i; }
  }
  for (auto o : ir_func->objects()) { ++num_objs; (void)o; }
  std::cout << num_blocks << " blocks, " << num_insts << " instructions, "
            << num_objs << " objects\n";

  // Run with zero-initialized arguments.
  // A real testing harness would supply concrete values.
  std::vector<Value> args;
  if (auto fd = mx::FunctionDecl::from(*decl)) {
    for (auto p : fd->parameters()) {
      (void)p;
      args.push_back(Value::Int(0));
    }
  }
  std::cout << "Running with " << args.size() << " zero-initialized arguments...\n\n";

  Interpreter interp(*ir_func, FLAGS_trace);
  interp.Run(args);

  return 0;
}
