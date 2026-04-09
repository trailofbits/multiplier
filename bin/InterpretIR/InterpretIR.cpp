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
  // Reinterpret int64 bits as double (for LOADed float values).
  double as_float_bits() const {
    if (kind == FLOATING) return fval;
    double d;
    uint64_t bits = static_cast<uint64_t>(ival);
    std::memcpy(&d, &bits, sizeof(d));
    return d;
  }
  // Coerce to float: use fval if FLOATING, else reinterpret bits.
  double coerce_float() const {
    return kind == FLOATING ? fval : as_float_bits();
  }
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

  // Pointers to parameter storage (allocated during setup, populated from params_).
  // PARAM_PTR(n) returns param_ptrs_[n].
  std::vector<Value> param_ptrs_;

  // Pointer to return value storage. RETURN_PTR returns this.
  Value return_ptr_ = Value::Undef();

  uint64_t steps_{0};

  // Evaluate a single instruction, storing result in values_.
  void Eval(const mx::IRInstruction &inst);

  // Recursively evaluate all sub-expressions of an instruction.
  void EvalSubExpressions(const mx::IRInstruction &inst);

  // Get the value of an instruction (must have been evaluated already).
  Value GetValue(const mx::IRInstruction &inst);

  // Memory operations.
  void MemWrite(const Pointer &ptr, const void *data, size_t len);
  void MemRead(const Pointer &ptr, void *data, size_t len);
  void MemWriteValue(const Pointer &ptr, const Value &val, size_t size);
  Value MemReadValue(const Pointer &ptr, size_t size, bool is_float);

  // Pointer shadow map: tracks which memory locations hold pointer values.
  // Key = (object_id << 32) | offset. When a pointer is written, it's
  // recorded here. When loading pointer-sized values, check here first.
  std::unordered_map<uint64_t, Pointer> pointer_shadow_;

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
    // Auto-grow for VLA-like objects (compile-time size unknown).
    mem.bytes.resize(start + len, 0);
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
    // Auto-grow for VLA-like objects.
    mem.bytes.resize(start + len, 0);
  }
  std::memcpy(data, mem.bytes.data() + start, len);
}

void Interpreter::MemWriteValue(const Pointer &ptr, const Value &val,
                                 size_t size) {
  uint64_t shadow_key = (static_cast<uint64_t>(ptr.object_id) << 32) |
                         (static_cast<uint32_t>(ptr.offset) & 0xFFFFFFFF);
  if (val.kind == Value::POINTER) {
    // Record pointer in shadow map for later loads.
    pointer_shadow_[shadow_key] = val.ptr;
    // Also write a sentinel to memory bytes (not meaningful, just fills space).
    int64_t sentinel = 0;
    MemWrite(ptr, &sentinel, std::min(size, sizeof(sentinel)));
    return;
  }
  // Non-pointer write: clear pointer shadow at this location.
  pointer_shadow_.erase(shadow_key);
  if (val.kind == Value::FLOATING) {
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
  // Check pointer shadow map first.
  uint64_t shadow_key = (static_cast<uint64_t>(ptr.object_id) << 32) |
                         (static_cast<uint32_t>(ptr.offset) & 0xFFFFFFFF);
  auto pit = pointer_shadow_.find(shadow_key);
  if (pit != pointer_shadow_.end()) {
    return Value::Ptr(pit->second.object_id, pit->second.offset);
  }
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
  // Read integer and sign-extend to int64 to match CONST representation.
  // Everything is int64 internally. Sign extension ensures -10 stored in
  // 4 bytes reads back as int64(-10), matching CONST(INT32, -10).
  int64_t v = 0;
  MemRead(ptr, &v, std::min(size, sizeof(v)));
  switch (size) {
    case 1: v = static_cast<int64_t>(static_cast<int8_t>(v)); break;
    case 2: v = static_cast<int64_t>(static_cast<int16_t>(v)); break;
    case 4: v = static_cast<int64_t>(static_cast<int32_t>(v)); break;
    default: break;
  }
  return Value::Int(v);
}

// ---------------------------------------------------------------------------
// Value access
// ---------------------------------------------------------------------------

Value Interpreter::GetValue(const mx::IRInstruction &inst) {
  auto op = inst.opcode();
  auto eid = mx::EntityId(inst.id()).Pack();

  // Use cached result if available.
  auto it = values_.find(eid);
  if (it != values_.end()) return it->second;

  // Lazy evaluation for sub-expressions not yet computed.
  if (!mx::ir::IsTerminator(op)) {
    Eval(inst);
    it = values_.find(eid);
    if (it != values_.end()) return it->second;
  }
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
        } else if (sub == mx::ir::ConstOp::UINT64) {
          // UINT64: use unsigned value directly (no sign extension needed).
          result = Value::Int(static_cast<int64_t>(ci->unsigned_value()));
        } else if (sub == mx::ir::ConstOp::UINT32) {
          // UINT32: sign-extend to match LOAD_LE_32 sign-extension.
          result = Value::Int(static_cast<int64_t>(
              static_cast<int32_t>(static_cast<uint32_t>(ci->unsigned_value()))));
        } else if (sub == mx::ir::ConstOp::UINT16) {
          result = Value::Int(static_cast<int64_t>(
              static_cast<int16_t>(static_cast<uint16_t>(ci->unsigned_value()))));
        } else if (sub == mx::ir::ConstOp::UINT8) {
          result = Value::Int(static_cast<int64_t>(
              static_cast<int8_t>(static_cast<uint8_t>(ci->unsigned_value()))));
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
        if (memory_.find(obj_eid) == memory_.end()) {
          // For DYNAMIC allocas (VLAs), use the runtime size operand.
          if (auto da = mx::DynamicAllocaInst::from(inst)) {
            Value sz_val = GetValue(da->size());
            uint32_t runtime_sz = static_cast<uint32_t>(sz_val.as_int());
            if (runtime_sz > 0) {
              auto &mem = memory_[obj_eid];
              mem.bytes.resize(runtime_sz, 0);
              mem.allocated = true;
              mem.poisoned = false;
            } else {
              AllocateObject(obj);
            }
          } else {
            AllocateObject(obj);
          }
        }
        result = Value::Ptr(obj_eid, 0);
      }
      break;
    }
    case mx::ir::OpCode::MEMORY: {
      if (auto mi = mx::MemoryInst::from(inst)) {
        auto sub = mi->sub_opcode();
        if (mx::ir::IsDirectLoadStore(sub)) {
          unsigned sz = mx::ir::AccessSize(sub);
          bool is_float = mx::ir::IsFloatLoad(sub);
          if (mx::ir::IsAnyLoad(sub)) {
            Value addr = GetValue(mi->address());
            if (addr.kind == Value::POINTER) {
              result = MemReadValue(addr.ptr, sz, is_float);
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
            case MO::STRCHR: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER) {
                uint8_t needle = static_cast<uint8_t>(ops[1].as_int());
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  bool found = false;
                  for (size_t i = start; i < it->second.bytes.size(); ++i) {
                    if (it->second.bytes[i] == needle) {
                      result = Value::Ptr(ops[0].ptr.object_id,
                                          static_cast<int64_t>(i));
                      found = true;
                      break;
                    }
                    if (it->second.bytes[i] == 0) break;
                  }
                  if (!found) {
                    // If searching for null terminator, point to it.
                    if (needle == 0) {
                      for (size_t i = start; i < it->second.bytes.size(); ++i) {
                        if (it->second.bytes[i] == 0) {
                          result = Value::Ptr(ops[0].ptr.object_id,
                                              static_cast<int64_t>(i));
                          found = true;
                          break;
                        }
                      }
                    }
                    if (!found) {
                      result = Value::Ptr(mx::kInvalidEntityId, 0);  // NULL
                    }
                  }
                }
              }
              break;
            }
            case MO::STRNLEN: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER) {
                int64_t maxlen = ops[1].as_int();
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  size_t len = 0;
                  while (len < static_cast<size_t>(maxlen) &&
                         start + len < it->second.bytes.size() &&
                         it->second.bytes[start + len] != 0) ++len;
                  result = Value::Int(static_cast<int64_t>(len));
                }
              }
              break;
            }
            case MO::STRNCMP: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                size_t n = static_cast<size_t>(ops[2].as_int());
                auto it0 = memory_.find(ops[0].ptr.object_id);
                auto it1 = memory_.find(ops[1].ptr.object_id);
                if (it0 != memory_.end() && it1 != memory_.end()) {
                  size_t s0 = static_cast<size_t>(ops[0].ptr.offset);
                  size_t s1 = static_cast<size_t>(ops[1].ptr.offset);
                  int cmp = 0;
                  for (size_t i = 0; i < n; ++i) {
                    uint8_t c0 = (s0 + i < it0->second.bytes.size()) ? it0->second.bytes[s0 + i] : 0;
                    uint8_t c1 = (s1 + i < it1->second.bytes.size()) ? it1->second.bytes[s1 + i] : 0;
                    if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
                    if (c0 == 0) break;
                  }
                  result = Value::Int(cmp);
                }
              }
              break;
            }
            case MO::STRRCHR: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER) {
                uint8_t needle = static_cast<uint8_t>(ops[1].as_int());
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  int64_t last_pos = -1;
                  for (size_t i = start; i < it->second.bytes.size(); ++i) {
                    if (it->second.bytes[i] == needle) {
                      last_pos = static_cast<int64_t>(i);
                    }
                    if (it->second.bytes[i] == 0) break;
                  }
                  if (last_pos >= 0) {
                    result = Value::Ptr(ops[0].ptr.object_id, last_pos);
                  } else {
                    result = Value::Ptr(mx::kInvalidEntityId, 0);  // NULL
                  }
                }
              }
              break;
            }
            case MO::STRSTR: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                auto it0 = memory_.find(ops[0].ptr.object_id);
                auto it1 = memory_.find(ops[1].ptr.object_id);
                if (it0 != memory_.end() && it1 != memory_.end()) {
                  // Read haystack string.
                  size_t hs = static_cast<size_t>(ops[0].ptr.offset);
                  size_t hlen = 0;
                  while (hs + hlen < it0->second.bytes.size() &&
                         it0->second.bytes[hs + hlen] != 0) ++hlen;
                  // Read needle string.
                  size_t ns = static_cast<size_t>(ops[1].ptr.offset);
                  size_t nlen = 0;
                  while (ns + nlen < it1->second.bytes.size() &&
                         it1->second.bytes[ns + nlen] != 0) ++nlen;
                  if (nlen == 0) {
                    result = ops[0];  // Empty needle: return haystack.
                  } else {
                    bool found = false;
                    for (size_t i = 0; i + nlen <= hlen; ++i) {
                      if (std::memcmp(it0->second.bytes.data() + hs + i,
                                      it1->second.bytes.data() + ns, nlen) == 0) {
                        result = Value::Ptr(ops[0].ptr.object_id,
                                            ops[0].ptr.offset + static_cast<int64_t>(i));
                        found = true;
                        break;
                      }
                    }
                    if (!found) {
                      result = Value::Ptr(mx::kInvalidEntityId, 0);  // NULL
                    }
                  }
                }
              }
              break;
            }
            case MO::STRCPY: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_src != memory_.end()) {
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  size_t ds = static_cast<size_t>(ops[0].ptr.offset);
                  Pointer dp = ops[0].ptr;
                  for (size_t i = 0; ; ++i) {
                    uint8_t c = (ss + i < it_src->second.bytes.size()) ? it_src->second.bytes[ss + i] : 0;
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(i);
                    MemWrite(dp, &c, 1);
                    if (c == 0) break;
                  }
                }
                result = ops[0];  // Return dest.
              }
              break;
            }
            case MO::STRNCPY: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                size_t n = static_cast<size_t>(ops[2].as_int());
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_src != memory_.end()) {
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  Pointer dp = ops[0].ptr;
                  bool hit_null = false;
                  for (size_t i = 0; i < n; ++i) {
                    uint8_t c = 0;
                    if (!hit_null && ss + i < it_src->second.bytes.size()) {
                      c = it_src->second.bytes[ss + i];
                      if (c == 0) hit_null = true;
                    }
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(i);
                    MemWrite(dp, &c, 1);
                  }
                }
                result = ops[0];  // Return dest.
              }
              break;
            }
            case MO::STRCAT: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                // Find end of dest string.
                auto it_dst = memory_.find(ops[0].ptr.object_id);
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_dst != memory_.end() && it_src != memory_.end()) {
                  size_t ds = static_cast<size_t>(ops[0].ptr.offset);
                  size_t dlen = 0;
                  while (ds + dlen < it_dst->second.bytes.size() &&
                         it_dst->second.bytes[ds + dlen] != 0) ++dlen;
                  // Copy src after dest's null.
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  Pointer dp = {ops[0].ptr.object_id,
                                ops[0].ptr.offset + static_cast<int64_t>(dlen)};
                  for (size_t i = 0; ; ++i) {
                    uint8_t c = (ss + i < it_src->second.bytes.size()) ? it_src->second.bytes[ss + i] : 0;
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(dlen + i);
                    MemWrite(dp, &c, 1);
                    if (c == 0) break;
                  }
                }
                result = ops[0];  // Return dest.
              }
              break;
            }
            case MO::STRNCAT: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                size_t n = static_cast<size_t>(ops[2].as_int());
                auto it_dst = memory_.find(ops[0].ptr.object_id);
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_dst != memory_.end() && it_src != memory_.end()) {
                  size_t ds = static_cast<size_t>(ops[0].ptr.offset);
                  size_t dlen = 0;
                  while (ds + dlen < it_dst->second.bytes.size() &&
                         it_dst->second.bytes[ds + dlen] != 0) ++dlen;
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  Pointer dp = {ops[0].ptr.object_id, 0};
                  size_t i = 0;
                  for (; i < n; ++i) {
                    uint8_t c = (ss + i < it_src->second.bytes.size()) ? it_src->second.bytes[ss + i] : 0;
                    if (c == 0) break;
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(dlen + i);
                    MemWrite(dp, &c, 1);
                  }
                  // Write null terminator.
                  uint8_t nul = 0;
                  dp.offset = ops[0].ptr.offset + static_cast<int64_t>(dlen + i);
                  MemWrite(dp, &nul, 1);
                }
                result = ops[0];  // Return dest.
              }
              break;
            }
            case MO::STPCPY: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_src != memory_.end()) {
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  Pointer dp = ops[0].ptr;
                  size_t i = 0;
                  for (; ; ++i) {
                    uint8_t c = (ss + i < it_src->second.bytes.size()) ? it_src->second.bytes[ss + i] : 0;
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(i);
                    MemWrite(dp, &c, 1);
                    if (c == 0) break;
                  }
                  // Return pointer to the null terminator in dest.
                  result = Value::Ptr(ops[0].ptr.object_id,
                                      ops[0].ptr.offset + static_cast<int64_t>(i));
                }
              }
              break;
            }
            case MO::STPNCPY: {
              if (ops.size() >= 3 && ops[0].kind == Value::POINTER
                  && ops[1].kind == Value::POINTER) {
                size_t n = static_cast<size_t>(ops[2].as_int());
                auto it_src = memory_.find(ops[1].ptr.object_id);
                if (it_src != memory_.end()) {
                  size_t ss = static_cast<size_t>(ops[1].ptr.offset);
                  Pointer dp = ops[0].ptr;
                  bool hit_null = false;
                  size_t null_pos = n;  // default: dest+n
                  for (size_t i = 0; i < n; ++i) {
                    uint8_t c = 0;
                    if (!hit_null && ss + i < it_src->second.bytes.size()) {
                      c = it_src->second.bytes[ss + i];
                      if (c == 0) { hit_null = true; null_pos = i; }
                    } else if (!hit_null) {
                      hit_null = true;
                      null_pos = i;
                    }
                    dp.offset = ops[0].ptr.offset + static_cast<int64_t>(i);
                    MemWrite(dp, &c, 1);
                  }
                  // Return pointer to null terminator or dest+n.
                  result = Value::Ptr(ops[0].ptr.object_id,
                                      ops[0].ptr.offset + static_cast<int64_t>(null_pos));
                }
              }
              break;
            }
            case MO::STRTOI32: case MO::STRTOI64:
            case MO::STRTOU32: case MO::STRTOU64:
            case MO::STRTOF32: case MO::STRTOF64: {
              if (ops.size() >= 1 && ops[0].kind == Value::POINTER) {
                auto it = memory_.find(ops[0].ptr.object_id);
                if (it != memory_.end()) {
                  // Read string bytes into a null-terminated buffer.
                  size_t start = static_cast<size_t>(ops[0].ptr.offset);
                  std::string str;
                  for (size_t i = start; i < it->second.bytes.size(); ++i) {
                    if (it->second.bytes[i] == 0) break;
                    str.push_back(static_cast<char>(it->second.bytes[i]));
                  }
                  switch (sub) {
                    case MO::STRTOI32:
                      result = Value::Int(static_cast<int64_t>(
                          std::strtol(str.c_str(), nullptr, 10)));
                      break;
                    case MO::STRTOI64:
                      result = Value::Int(static_cast<int64_t>(
                          std::strtoll(str.c_str(), nullptr, 10)));
                      break;
                    case MO::STRTOU32:
                      result = Value::Int(static_cast<int64_t>(
                          std::strtoul(str.c_str(), nullptr, 10)));
                      break;
                    case MO::STRTOU64:
                      result = Value::Int(static_cast<int64_t>(
                          std::strtoull(str.c_str(), nullptr, 10)));
                      break;
                    case MO::STRTOF32:
                      result = Value::Float(static_cast<double>(
                          std::strtof(str.c_str(), nullptr)));
                      break;
                    case MO::STRTOF64:
                      result = Value::Float(
                          std::strtod(str.c_str(), nullptr));
                      break;
                    default:
                      break;
                  }
                }
              }
              break;
            }
            case MO::BIT_READ_LE: case MO::BIT_READ_BE: {
              if (ops.size() >= 1 && ops[0].kind == Value::POINTER) {
                uint32_t bo = mi->bit_offset();
                uint32_t bw = mi->bit_width();
                // Compute which bytes to read.
                uint32_t first_byte = bo / 8;
                uint32_t last_byte = (bo + bw - 1) / 8;
                uint32_t num_bytes = last_byte - first_byte + 1;
                std::vector<uint8_t> buf(num_bytes, 0);
                Pointer rp = ops[0].ptr;
                rp.offset += first_byte;
                MemRead(rp, buf.data(), num_bytes);
                uint64_t raw = 0;
                if (sub == MO::BIT_READ_LE) {
                  // LE: bit 0 = LSB of byte 0.
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
                  }
                  // Shift right to remove bits below bit_offset within the
                  // fetched bytes.
                  raw >>= (bo % 8);
                } else {
                  // BE: bit 0 = MSB of byte 0. Read bytes MSB-first.
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    raw = (raw << 8) | buf[i];
                  }
                  // Bits are numbered from MSB. The field starts at
                  // bit bo within the full object. Within the fetched
                  // window, the field starts at (bo % 8) from the MSB
                  // of the first byte.
                  uint32_t top_bits = num_bytes * 8;
                  uint32_t shift = top_bits - (bo % 8) - bw;
                  raw >>= shift;
                }
                // Mask to bit_width.
                uint64_t mask = (bw >= 64) ? ~uint64_t{0} : ((uint64_t{1} << bw) - 1);
                raw &= mask;
                result = Value::Int(static_cast<int64_t>(raw));
              }
              break;
            }
            case MO::BIT_WRITE_LE: case MO::BIT_WRITE_BE: {
              if (ops.size() >= 2 && ops[0].kind == Value::POINTER) {
                uint32_t bo = mi->bit_offset();
                uint32_t bw = mi->bit_width();
                uint64_t val = static_cast<uint64_t>(ops[1].as_int());
                uint64_t mask = (bw >= 64) ? ~uint64_t{0} : ((uint64_t{1} << bw) - 1);
                val &= mask;
                uint32_t first_byte = bo / 8;
                uint32_t last_byte = (bo + bw - 1) / 8;
                uint32_t num_bytes = last_byte - first_byte + 1;
                std::vector<uint8_t> buf(num_bytes, 0);
                Pointer rp = ops[0].ptr;
                rp.offset += first_byte;
                MemRead(rp, buf.data(), num_bytes);
                if (sub == MO::BIT_WRITE_LE) {
                  // LE: assemble bytes as little-endian integer.
                  uint64_t raw = 0;
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
                  }
                  uint32_t shift = bo % 8;
                  raw &= ~(mask << shift);
                  raw |= (val << shift);
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    buf[i] = static_cast<uint8_t>(raw >> (i * 8));
                  }
                } else {
                  // BE: assemble bytes as big-endian integer.
                  uint64_t raw = 0;
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    raw = (raw << 8) | buf[i];
                  }
                  uint32_t top_bits = num_bytes * 8;
                  uint32_t shift = top_bits - (bo % 8) - bw;
                  raw &= ~(mask << shift);
                  raw |= (val << shift);
                  for (uint32_t i = 0; i < num_bytes; ++i) {
                    buf[num_bytes - 1 - i] = static_cast<uint8_t>(raw >> (i * 8));
                  }
                }
                MemWrite(rp, buf.data(), num_bytes);
              }
              break;
            }
            default:
              if (mx::ir::IsCmpxchg(sub)) {
                // Simplified: return undef (complex semantics).
                result = Value::Undef();
              }
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
          result = Value::Float(l.coerce_float() + r.coerce_float());
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
          result = Value::Float(l.coerce_float() - r.coerce_float());
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
          result = Value::Float(l.coerce_float() * r.coerce_float());
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
          result = Value::Float(r.coerce_float() != 0 ? l.coerce_float() / r.coerce_float() : 0.0);
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
          result = Value::Float(std::fmod(l.coerce_float(), r.coerce_float()));
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
    // Unsigned arithmetic.
    case mx::ir::OpCode::UDIV: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        uint64_t l = static_cast<uint64_t>(GetValue(bin->lhs()).as_int());
        uint64_t r = static_cast<uint64_t>(GetValue(bin->rhs()).as_int());
        result = Value::Int(static_cast<int64_t>(r != 0 ? l / r : 0));
      }
      break;
    }
    case mx::ir::OpCode::UREM: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        uint64_t l = static_cast<uint64_t>(GetValue(bin->lhs()).as_int());
        uint64_t r = static_cast<uint64_t>(GetValue(bin->rhs()).as_int());
        result = Value::Int(static_cast<int64_t>(r != 0 ? l % r : 0));
      }
      break;
    }
    case mx::ir::OpCode::USHR: {
      auto bin = mx::BinaryInst::from(inst);
      if (bin) {
        uint64_t l = static_cast<uint64_t>(GetValue(bin->lhs()).as_int());
        uint64_t r = static_cast<uint64_t>(GetValue(bin->rhs()).as_int());
        result = Value::Int(static_cast<int64_t>(l >> r));
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
          int64_t byte_diff = l.ptr.offset - r.ptr.offset;
          // Element size is in int_pool[0]. We need to read it but
          // BinaryInst doesn't expose it. Use the num_operands trick:
          // PTR_DIFF has 2 operands and element_size at int_pool[const_offset].
          // For now, use PtrAddInst which has the same pool layout.
          // PtrAddInst::from will fail (wrong opcode), so read element_size
          // from the instruction's extra data. The codegen stores it in
          // size_bytes which maps to int_pool[0].
          // TODO: Add PtrDiffInst class with element_size() accessor.
          int64_t elem_size = 1;
          // Heuristic: check num_operands. If the instruction has extra
          // int pool entries, the first one is element_size.
          auto nops = inst.num_operands();
          (void)nops;
          // For now, we can try to use the object's total size / array count.
          // Simpler: the codegen always stores element_size in the int pool.
          // Read it by trying to interpret as PtrAddInst (same layout).
          // Actually just divide: the serializer now stores element_size for
          // PTR_DIFF. We need a read API. Hardcode 4 for int* for now.
          // TODO: expose int_pool via PtrDiffInst class.
          elem_size = 4;  // sizeof(int) — most common case
          if (elem_size > 0) {
            result = Value::Int(byte_diff / elem_size);
          }
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
          double lv = l.coerce_float(), rv = r.coerce_float();
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
          // If input is INTEGER (raw double bits from a LOAD), reinterpret.
          double fv;
          if (v.kind == Value::FLOATING) {
            fv = v.fval;
          } else {
            // Raw bits → double.
            uint64_t bits = static_cast<uint64_t>(v.ival);
            std::memcpy(&fv, &bits, sizeof(fv));
          }
          result = Value::Int(static_cast<int64_t>(fv));
        } else if (mx::ir::IsIntToFloat(sub)) {
          result = Value::Float(static_cast<double>(v.as_int()));
        } else if (sub == mx::ir::CastOp::F32_TO_F64 ||
                   sub == mx::ir::CastOp::F64_TO_F32) {
          if (v.kind == Value::FLOATING) {
            result = Value::Float(v.fval);
          } else {
            // Raw bits → float.
            double fv;
            uint64_t bits = static_cast<uint64_t>(v.ival);
            std::memcpy(&fv, &bits, sizeof(fv));
            result = Value::Float(fv);
          }
        } else if (mx::ir::IsSignExtend(sub)) {
          // Sign-extend: LOADs already sign-extend to int64, so SEXT is
          // a no-op (the value is already correctly sign-extended).
          result = Value::Int(v.as_int());
        } else if (mx::ir::IsZeroExtend(sub)) {
          // Zero-extend: mask to source width (undoing sign-extension from LOAD).
          int64_t iv = v.as_int();
          switch (sub) {
            case mx::ir::CastOp::ZEXT_I8_I16:
            case mx::ir::CastOp::ZEXT_I8_I32:
            case mx::ir::CastOp::ZEXT_I8_I64:
              iv = iv & 0xFF;
              break;
            case mx::ir::CastOp::ZEXT_I16_I32:
            case mx::ir::CastOp::ZEXT_I16_I64:
              iv = iv & 0xFFFF;
              break;
            case mx::ir::CastOp::ZEXT_I32_I64:
              iv = iv & 0xFFFFFFFF;
              break;
            default: break;
          }
          result = Value::Int(iv);
        } else if (mx::ir::IsTruncate(sub)) {
          // Truncate: mask to target width.
          int64_t iv = v.as_int();
          switch (sub) {
            case mx::ir::CastOp::TRUNC_I16_I8:
            case mx::ir::CastOp::TRUNC_I32_I8:
            case mx::ir::CastOp::TRUNC_I64_I8:
              iv = iv & 0xFF;
              break;
            case mx::ir::CastOp::TRUNC_I32_I16:
            case mx::ir::CastOp::TRUNC_I64_I16:
              iv = iv & 0xFFFF;
              break;
            case mx::ir::CastOp::TRUNC_I64_I32:
              iv = iv & 0xFFFFFFFF;
              break;
            default: break;
          }
          result = Value::Int(iv);
        } else {
          // Other int-to-int casts.
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
          // Determine access size from the object.
          size_t access_sz = 8;
          auto it = memory_.find(addr.ptr.object_id);
          if (it != memory_.end() && it->second.bytes.size() <= 8) {
            access_sz = it->second.bytes.size();
          }
          Value old_val = MemReadValue(addr.ptr, access_sz, false);
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
            MemWriteValue(addr.ptr, new_val, access_sz);
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
          call_args.push_back(GetValue(arg));
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


    // --- Param pointer ---
    case mx::ir::OpCode::PARAM_PTR: {
      if (auto pr = mx::ParamPtrInst::from(inst)) {
        uint32_t idx = pr->parameter_index();
        if (idx < param_ptrs_.size()) {
          result = param_ptrs_[idx];
        } else {
          LOG(WARNING) << "PARAM_PTR index " << idx
                       << " out of range (have " << param_ptrs_.size()
                       << " param pointers)";
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
          case FO::SIN:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::sin(ops[0].as_float()));
            break;
          case FO::COS:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::cos(ops[0].as_float()));
            break;
          case FO::TAN:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::tan(ops[0].as_float()));
            break;
          case FO::ASIN:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::asin(ops[0].as_float()));
            break;
          case FO::ACOS:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::acos(ops[0].as_float()));
            break;
          case FO::ATAN:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::atan(ops[0].as_float()));
            break;
          case FO::ATAN2:
            result = (ops.size() >= 2)
                ? Value::Float(std::atan2(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::EXP:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::exp(ops[0].as_float()));
            break;
          case FO::EXP2:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::exp2(ops[0].as_float()));
            break;
          case FO::LOG:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::log(ops[0].as_float()));
            break;
          case FO::LOG2:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::log2(ops[0].as_float()));
            break;
          case FO::LOG10:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::log10(ops[0].as_float()));
            break;
          case FO::POW:
            result = (ops.size() >= 2)
                ? Value::Float(std::pow(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::FMOD:
            result = (ops.size() >= 2)
                ? Value::Float(std::fmod(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::REMAINDER:
            result = (ops.size() >= 2)
                ? Value::Float(std::remainder(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::FMA:
            result = (ops.size() >= 3)
                ? Value::Float(std::fma(ops[0].as_float(), ops[1].as_float(), ops[2].as_float()))
                : Value::Undef();
            break;
          case FO::SINH:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::sinh(ops[0].as_float()));
            break;
          case FO::COSH:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::cosh(ops[0].as_float()));
            break;
          case FO::TANH:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::tanh(ops[0].as_float()));
            break;
          case FO::HYPOT:
            result = (ops.size() >= 2)
                ? Value::Float(std::hypot(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::ERF:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::erf(ops[0].as_float()));
            break;
          case FO::ERFC:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::erfc(ops[0].as_float()));
            break;
          case FO::TGAMMA:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::tgamma(ops[0].as_float()));
            break;
          case FO::LGAMMA:
            result = ops.empty() ? Value::Undef()
                : Value::Float(std::lgamma(ops[0].as_float()));
            break;
          case FO::FDIM:
            result = (ops.size() >= 2)
                ? Value::Float(std::fdim(ops[0].as_float(), ops[1].as_float()))
                : Value::Undef();
            break;
          case FO::SIGNBIT:
            result = ops.empty() ? Value::Undef()
                : Value::Int(std::signbit(ops[0].as_float()) ? 1 : 0);
            break;
        }
      }
      break;
    }

    // --- Frame/return address intrinsics ---
    case mx::ir::OpCode::FRAME_PTR:
    case mx::ir::OpCode::RETURN_ADDRESS:
      // Not meaningfully interpretable; return undef.
      result = Value::Undef();
      break;

    // --- Return value pointer (callee side) ---
    case mx::ir::OpCode::RETURN_PTR:
      result = return_ptr_;
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
    case mx::ir::OpCode::VA_COPY: {
      // CRITIQUE: Variadic args need a runtime va_list model. Not implemented
      // in this simple interpreter. va_arg is handled via MEMORY/CONSUME_VA_PARAM.
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

void Interpreter::EvalSubExpressions(const mx::IRInstruction &inst) {
  for (auto operand : inst.operands()) {
    EvalSubExpressions(operand);  // depth-first
    auto sub_op = operand.opcode();
    if (!mx::ir::IsTerminator(sub_op)) {
      Eval(operand);
    }
  }
}

// ---------------------------------------------------------------------------
// Main interpreter loop
// ---------------------------------------------------------------------------

Value Interpreter::Run(const std::vector<Value> &args) {
  params_ = args;
  param_ptrs_.clear();
  values_.clear();
  memory_.clear();
  pointer_shadow_.clear();
  block_map_.clear();
  steps_ = 0;

  // Pre-allocate parameter and return storage.
  // PARAM_PTR(n) returns a pointer to the nth parameter's storage.
  // RETURN_PTR returns a pointer to the return value storage.
  return_ptr_ = Value::Undef();
  {
    uint32_t param_idx = 0;
    for (auto obj : func_.objects()) {
      auto k = obj.kind();
      if (k == mx::ir::ObjectKind::PARAMETER ||
          k == mx::ir::ObjectKind::PARAMETER_VALUE) {
        auto eid = mx::EntityId(obj.id()).Pack();
        AllocateObject(obj);
        Pointer ptr{eid, 0};
        if (param_idx < args.size()) {
          uint32_t sz = obj.size_bytes();
          if (sz == 0) sz = 8;
          MemWriteValue(ptr, args[param_idx], sz);
        }
        param_ptrs_.push_back(Value::Ptr(eid, 0));
        ++param_idx;
      } else if (k == mx::ir::ObjectKind::RETURN_SLOT) {
        auto eid = mx::EntityId(obj.id()).Pack();
        AllocateObject(obj);
        return_ptr_ = Value::Ptr(eid, 0);
      }
    }
  }

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



    // Clear cached values at block boundaries for fresh LOAD evaluation.
    values_.clear();

    if (trace_) {
      std::cerr << "Block " << mx::ir::EnumeratorName(current.kind())
                << " (" << mx::EntityId(current.id()).Pack() << ")\n";
    }


    // Evaluate all instructions in the block. all_instructions() yields
    // only root instructions; sub-expressions are lazy-evaluated via GetValue.
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
        // Fallback: read from RETURN_PTR storage if direct operand is undef.
        if (return_value.kind == Value::UNDEFINED &&
            return_ptr_.kind == Value::POINTER) {
          return_value = MemReadValue(return_ptr_.ptr, 4, false);  // TODO: size from return type
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
