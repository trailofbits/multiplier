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
// - COMPOUND_ASSIGN and INC_DEC are compound read-modify-write ops. They're
//   convenient for the AST mapping but make the interpreter more complex than
//   if they were decomposed into LOAD+op+STORE sequences.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
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
    case mx::ir::OpCode::CONST_INT: {
      if (auto ci = mx::ConstIntInst::from(inst)) {
        result = Value::Int(ci->signed_value());
      }
      break;
    }
    case mx::ir::OpCode::CONST_FLOAT: {
      if (auto cf = mx::ConstFloatInst::from(inst)) {
        result = Value::Float(cf->value());
      }
      break;
    }
    case mx::ir::OpCode::CONST_NULL: {
      result = Value::Ptr(mx::kInvalidEntityId, 0);
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
    case mx::ir::OpCode::LOAD: {
      if (auto li = mx::LoadInst::from(inst)) {
        Value addr = GetValue(li->address());
        if (addr.kind == Value::POINTER) {
          // Determine size from loaded_type.
          // CRITIQUE: We need the type system to know the size. For now,
          // default to 8 bytes (pointer-sized). A real interpreter would
          // query the type's size.
          result = MemReadValue(addr.ptr, 8, false);
        } else {
          LOG(WARNING) << "LOAD from non-pointer value";
        }
      }
      break;
    }
    case mx::ir::OpCode::STORE: {
      if (auto si = mx::StoreInst::from(inst)) {
        Value addr = GetValue(si->address());
        Value val = GetValue(si->stored_value());
        if (addr.kind == Value::POINTER) {
          MemWriteValue(addr.ptr, val, 8);
        } else {
          LOG(WARNING) << "STORE to non-pointer value";
        }
      }
      break;
    }
    case mx::ir::OpCode::ADDRESS_OF: {
      if (auto ao = mx::AddressOfInst::from(inst)) {
        auto obj = ao->object();
        auto obj_eid = mx::EntityId(obj.id()).Pack();
        result = Value::Ptr(obj_eid, 0);
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
    case mx::ir::OpCode::CAST_SEXT:
    case mx::ir::OpCode::CAST_ZEXT:
    case mx::ir::OpCode::CAST_TRUNC:
    case mx::ir::OpCode::CAST_INT_CAST: {
      auto c = mx::CastInst::from(inst);
      if (c) result = Value::Int(GetValue(c->operand()).as_int());
      break;
    }
    case mx::ir::OpCode::CAST_BITCAST: {
      auto c = mx::CastInst::from(inst);
      if (c) result = GetValue(c->operand());
      break;
    }
    case mx::ir::OpCode::CAST_PTR_TO_INT: {
      auto c = mx::CastInst::from(inst);
      if (c) {
        Value v = GetValue(c->operand());
        // Convert pointer to integer (offset only, object info lost).
        result = Value::Int(v.kind == Value::POINTER ? v.ptr.offset : v.ival);
      }
      break;
    }
    case mx::ir::OpCode::CAST_INT_TO_PTR: {
      auto c = mx::CastInst::from(inst);
      if (c) {
        Value v = GetValue(c->operand());
        result = Value::Ptr(mx::kInvalidEntityId, v.as_int());
      }
      break;
    }
    case mx::ir::OpCode::CAST_FP_TO_SI: {
      auto c = mx::CastInst::from(inst);
      if (c) result = Value::Int(static_cast<int64_t>(GetValue(c->operand()).as_float()));
      break;
    }
    case mx::ir::OpCode::CAST_SI_TO_FP: {
      auto c = mx::CastInst::from(inst);
      if (c) result = Value::Float(static_cast<double>(GetValue(c->operand()).as_int()));
      break;
    }
    case mx::ir::OpCode::CAST_FP_TRUNC:
    case mx::ir::OpCode::CAST_FP_EXT:
    case mx::ir::OpCode::CAST_FP_CAST: {
      auto c = mx::CastInst::from(inst);
      if (c) result = Value::Float(GetValue(c->operand()).as_float());
      break;
    }

    // --- Sizeof ---
    case mx::ir::OpCode::SIZE_OF: {
      if (auto so = mx::SizeOfInst::from(inst)) {
        result = Value::Int(so->static_size());
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

    // --- Copy ---
    case mx::ir::OpCode::COPY: {
      if (auto cp = mx::CopyInst::from(inst)) {
        result = GetValue(cp->source());
      }
      break;
    }

    // --- Inc/Dec ---
    // CRITIQUE: This is a compound read-modify-write. The IR could decompose
    // this into LOAD + ADD/SUB + STORE, which would be simpler for the
    // interpreter. As-is, we must handle the compound semantics.
    case mx::ir::OpCode::INC_DEC: {
      if (auto id = mx::IncDecInst::from(inst)) {
        Value addr = GetValue(id->address());
        if (addr.kind == Value::POINTER) {
          Value old_val = MemReadValue(addr.ptr, 8, false);
          int64_t delta = id->is_increment() ? 1 : -1;
          Value new_val = Value::Int(old_val.as_int() + delta);
          MemWriteValue(addr.ptr, new_val, 8);
          result = id->is_prefix() ? new_val : old_val;
        }
      }
      break;
    }

    // --- Compound assign ---
    // CRITIQUE: Same issue as INC_DEC. A LOAD + op + STORE decomposition
    // would be cleaner for the interpreter.
    case mx::ir::OpCode::COMPOUND_ASSIGN: {
      if (auto ca = mx::CompoundAssignInst::from(inst)) {
        Value addr = GetValue(ca->address());
        Value rhs = GetValue(ca->value());
        if (addr.kind == Value::POINTER) {
          Value old_val = MemReadValue(addr.ptr, 8, false);
          Value new_val;
          switch (ca->underlying_op()) {
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
            default: new_val = old_val; break;
          }
          MemWriteValue(addr.ptr, new_val, 8);
          result = new_val;
        }
      }
      break;
    }

    // --- Init list ---
    case mx::ir::OpCode::INIT_LIST: {
      // CRITIQUE: INIT_LIST produces an aggregate value. A concrete interpreter
      // needs to know the layout (field offsets, array element sizes). Without
      // decomposition into element stores, this is hard to handle generically.
      // For now, just pass through as undef.
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

    // --- Memory intrinsics ---
    case mx::ir::OpCode::MEMSET: {
      if (auto ms = mx::MemsetInst::from(inst)) {
        Value dest = GetValue(ms->dest());
        Value byte_val = GetValue(ms->byte_value());
        Value size = GetValue(ms->size());
        if (dest.kind == Value::POINTER && size.as_int() > 0) {
          auto it = memory_.find(dest.ptr.object_id);
          if (it != memory_.end()) {
            size_t start = static_cast<size_t>(dest.ptr.offset);
            size_t len = static_cast<size_t>(size.as_int());
            size_t end = std::min(start + len, it->second.bytes.size());
            std::memset(it->second.bytes.data() + start,
                        static_cast<int>(byte_val.as_int()), end - start);
          }
        }
        result = dest;  // memset returns dest.
      }
      break;
    }
    case mx::ir::OpCode::MEMCPY: {
      if (auto mc = mx::MemcpyInst::from(inst)) {
        Value dest = GetValue(mc->dest());
        Value src = GetValue(mc->src());
        Value size = GetValue(mc->size());
        if (dest.kind == Value::POINTER && src.kind == Value::POINTER
            && size.as_int() > 0) {
          size_t len = static_cast<size_t>(size.as_int());
          std::vector<uint8_t> tmp(len);
          MemRead(src.ptr, tmp.data(), len);
          MemWrite(dest.ptr, tmp.data(), len);
        }
        result = dest;  // memcpy returns dest.
      }
      break;
    }

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
    case mx::ir::OpCode::GLOBAL_ADDR: {
      // In a real interpreter, this would look up the global's storage.
      // For now, create a synthetic pointer using the target entity ID.
      result = Value::Ptr(inst.source_entity_id(), 0);
      break;
    }
    case mx::ir::OpCode::FUNC_ADDR: {
      // Function pointer — use the source entity ID as a handle.
      result = Value::Ptr(inst.source_entity_id(), 0);
      break;
    }

    // --- Scope markers (no-ops for concrete interpretation) ---
    case mx::ir::OpCode::ENTER_SCOPE:
    case mx::ir::OpCode::EXIT_SCOPE:
      break;

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
