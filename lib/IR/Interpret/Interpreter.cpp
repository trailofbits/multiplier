// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/ValueFactory.h>
#include <multiplier/IR/Interpret/Memory.h>
#include <multiplier/IR/Interpret/Driver.h>
#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/Object.h>
#include <multiplier/IR/StructureKinds.h>
// NOTE: Entity.h defines VariantEntity which contains Fragment, Macro,
// Compilation, etc. The `from()` overload resolution needs all variant
// members to be complete types. Frontend.h provides the missing ones.
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <string>

namespace mx::ir::interpret {
namespace {

// ---------------------------------------------------------------------------
// Context struct — groups parameters every helper needs
// ---------------------------------------------------------------------------

struct Ctx {
  InterpreterState &state;
  Memory &memory;
  ValueFactory &factory;
  Driver &driver;

  CallFrame &Frame() { return state.Frame(); }
};

// ---------------------------------------------------------------------------
// Forward declarations
// ---------------------------------------------------------------------------

static size_t UnderlyingOpAccessSize(ir::OpCode op);
static void MemWriteValue(Memory &memory, uint64_t address,
                          const Value &val, size_t size);
static Value MemReadValue(Memory &memory, uint64_t address,
                          size_t size, bool is_float);
static uint64_t AllocateObject(CallFrame &frame, Memory &memory,
                               const IRObject &obj);
static void SetupFrame(CallFrame &frame, Memory &memory,
                       const IRFunction &func, const std::vector<Value> &args);
static Value GetValue(Ctx &ctx, CallFrame &frame, const IRInstruction &inst);
static Value EvalMemorySubOp(Ctx &ctx, CallFrame &frame, const MemoryInst &mi,
                             MemOp sub, const std::vector<Value> &ops);
static std::optional<uint64_t> ResolveVAListAddr(
    Ctx &ctx, CallFrame &frame, const IRInstruction &operand);
static Value DerefArgPointer(Ctx &ctx, CallFrame &frame,
                             const IRInstruction &arg);
static bool EvalCall(Ctx &ctx, const IRInstruction &inst);
static bool Eval(Ctx &ctx, const IRInstruction &inst);
static void RunToCompletion(Ctx &ctx, const IRFunction &func,
                            const std::vector<Value> &args);
static Value ReadReturnValue(Memory &memory, const CallFrame &frame,
                             const Value &ret_from_inst);

// ---------------------------------------------------------------------------
// UnderlyingOpAccessSize
// ---------------------------------------------------------------------------

static size_t UnderlyingOpAccessSize(ir::OpCode op) {
  using enum ir::OpCode;
  if (ir::IsFloatArithmetic(op)) {
    unsigned v = static_cast<unsigned>(op);
    return (v % 2 == 1) ? 4 : 8;
  }
  if (ir::IsFloatComparison(op)) {
    unsigned v = static_cast<unsigned>(op);
    return (v % 2 == 1) ? 4 : 8;
  }
  if (op >= ADD_8 && op <= SHR_64) {
    static constexpr size_t widths[] = {1, 2, 4, 8};
    unsigned base;
    if (op >= SHR_8) base = static_cast<unsigned>(SHR_8);
    else if (op >= SHL_8) base = static_cast<unsigned>(SHL_8);
    else if (op >= BIT_XOR_8) base = static_cast<unsigned>(BIT_XOR_8);
    else if (op >= BIT_OR_8) base = static_cast<unsigned>(BIT_OR_8);
    else if (op >= BIT_AND_8) base = static_cast<unsigned>(BIT_AND_8);
    else if (op >= USHR_8) base = static_cast<unsigned>(USHR_8);
    else if (op >= UREM_8) base = static_cast<unsigned>(UREM_8);
    else if (op >= UDIV_8) base = static_cast<unsigned>(UDIV_8);
    else if (op >= REM_8) base = static_cast<unsigned>(REM_8);
    else if (op >= DIV_8) base = static_cast<unsigned>(DIV_8);
    else if (op >= MUL_8) base = static_cast<unsigned>(MUL_8);
    else if (op >= SUB_8) base = static_cast<unsigned>(SUB_8);
    else base = static_cast<unsigned>(ADD_8);
    unsigned idx = static_cast<unsigned>(op) - base;
    return (idx < 4) ? widths[idx] : 8;
  }
  if (op >= ATOMIC_ADD_8 && op <= ATOMIC_EXCHANGE_64) {
    static constexpr size_t widths[] = {1, 2, 4, 8};
    unsigned v = static_cast<unsigned>(op) -
                 static_cast<unsigned>(ATOMIC_ADD_8);
    return widths[v % 4];
  }
  return 8;
}

// ---------------------------------------------------------------------------
// AllocateObject
// ---------------------------------------------------------------------------

static uint64_t AllocateObject(CallFrame &frame, Memory &memory,
                               const IRObject &obj) {
  auto eid = EntityId(obj.id()).Pack();
  auto it = frame.entity_to_address.find(eid);
  if (it != frame.entity_to_address.end()) {
    return it->second;
  }
  uint32_t size = obj.size_bytes();
  if (size == 0) size = 8;
  uint32_t align = obj.align_bytes();
  if (align == 0) align = 8;
  auto address = memory.Allocate(size, align);
  frame.entity_to_address[eid] = address;
  return address;
}

// ---------------------------------------------------------------------------
// MemWriteValue — serialize a Value into Memory
// ---------------------------------------------------------------------------

static void MemWriteValue(Memory &memory, uint64_t address,
                          const Value &val, size_t size) {
  if (auto *ptr = AsPointer(val)) {
    memory.WritePointer(address, ConcreteAddress(*ptr));
    return;
  }
  if (IsNull(val)) {
    int64_t zero = 0;
    memory.Write(address, &zero,
                 static_cast<uint32_t>(std::min(size, sizeof(zero))));
    return;
  }
  if (auto *s = std::get_if<ScalarValue>(&val)) {
    if (s->width == 4) {
      memory.Write(address, &s->bits,
                   static_cast<uint32_t>(std::min(size, size_t{4})));
    } else {
      memory.Write(address, &s->bits,
                   static_cast<uint32_t>(std::min(size, sizeof(s->bits))));
    }
  } else {
    int64_t zero = 0;
    memory.Write(address, &zero,
                 static_cast<uint32_t>(std::min(size, sizeof(zero))));
  }
}

// ---------------------------------------------------------------------------
// MemReadValue — deserialize a Value from Memory
// ---------------------------------------------------------------------------

static Value MemReadValue(Memory &memory, uint64_t address,
                          size_t size, bool is_float) {
  // Check for pointer provenance first.
  uint64_t ptr_val = 0;
  if (memory.ReadPointer(address, ptr_val)) {
    return MakePtr(ptr_val);
  }

  if (is_float) {
    if (size == 4) {
      float f = 0;
      memory.Read(address, &f, 4);
      return MakeFloat32(f);
    }
    double d = 0;
    memory.Read(address, &d, 8);
    return MakeFloat(d);
  }

  int64_t v = 0;
  memory.Read(address, &v,
              static_cast<uint32_t>(std::min(size, sizeof(v))));
  switch (size) {
    case 1: v = static_cast<int64_t>(static_cast<int8_t>(v)); break;
    case 2: v = static_cast<int64_t>(static_cast<int16_t>(v)); break;
    case 4: v = static_cast<int64_t>(static_cast<int32_t>(v)); break;
    default: break;
  }
  return MakeInt(v);
}

// ---------------------------------------------------------------------------
// ReadReturnValue — extract the callee's return value from its return slot
// ---------------------------------------------------------------------------

static Value ReadReturnValue(Memory &memory, const CallFrame &frame,
                             const Value &ret_from_inst) {
  auto *rp = AsPointer(frame.return_ptr);
  if (!rp || !IsConcrete(*rp)) return ret_from_inst;

  uint32_t sz = 0;
  if (auto fd = frame.func.declaration()) {
    if (auto bits = fd->return_type().size_in_bits()) {
      sz = static_cast<uint32_t>((*bits + 7) / 8);
    }
  }

  if (sz > 0 && sz <= 8) {
    return MemReadValue(memory, ConcreteAddress(*rp), sz, false);
  }
  if (sz > 8) {
    return frame.return_ptr;
  }
  return ret_from_inst;
}

// ---------------------------------------------------------------------------
// SetupFrame — initialize a CallFrame for a function invocation
// ---------------------------------------------------------------------------

static void SetupFrame(CallFrame &frame, Memory &memory,
                       const IRFunction &func,
                       const std::vector<Value> &args) {
  frame.func = func;
  frame.params = args;

  // Build block map.
  for (auto block : func.blocks()) {
    frame.block_map[EntityId(block.id()).Pack()] = block;
  }
  {
    auto entry = func.entry_block();
    frame.block_map[EntityId(entry.id()).Pack()] = entry;
  }

  // Allocate parameter storage.
  uint32_t param_idx = 0;
  for (auto obj : func.objects()) {
    auto k = obj.kind();
    if (k == ir::ObjectKind::PARAMETER ||
        k == ir::ObjectKind::PARAMETER_VALUE) {
      auto address = AllocateObject(frame, memory, obj);
      if (param_idx < args.size()) {
        uint32_t sz = obj.size_bytes();
        if (sz == 0) sz = 8;
        auto *arg_ptr = AsPointer(args[param_idx]);
        if (arg_ptr && IsConcrete(*arg_ptr) && sz > 8) {
          memory.Memcpy(address, ConcreteAddress(*arg_ptr), sz);
        } else {
          MemWriteValue(memory, address, args[param_idx], sz);
        }
      }
      frame.param_ptrs.push_back(MakePtr(address));
      ++param_idx;
    }
  }

  // GLOBAL_INITIALIZER functions receive the global's address as a direct
  // param_ptr, not through PARAMETER objects.
  if (func.kind() == ir::FunctionKind::GLOBAL_INITIALIZER) {
    for (auto &a : args) {
      frame.param_ptrs.push_back(a);
    }
    param_idx = static_cast<uint32_t>(args.size());
  }

  // Variadic args beyond fixed params.
  frame.variadic_start_index = param_idx;
  for (uint32_t i = param_idx; i < args.size(); ++i) {
    uint32_t sz = 8;
    auto address = memory.Allocate(sz, 8);
    MemWriteValue(memory, address, args[i], sz);
    frame.param_ptrs.push_back(MakePtr(address));
  }

  // Allocate return storage if not already set by the caller.
  if (IsUndefined(frame.return_ptr)) {
    if (auto fd = func.declaration()) {
      auto rt = fd->return_type();
      if (auto bits = rt.size_in_bits()) {
        uint32_t sz = static_cast<uint32_t>((*bits + 7) / 8);
        if (sz > 0) {
          auto addr = memory.Allocate(sz, 8);
          frame.return_ptr = MakePtr(addr);
        }
      }
    }
  }

  frame.current_block = func.entry_block();
}

// ---------------------------------------------------------------------------
// RunToCompletion — run a function synchronously (for global initializers)
// ---------------------------------------------------------------------------

static void RunToCompletion(Ctx &ctx, const IRFunction &func,
                            const std::vector<Value> &args) {
  auto saved_depth = ctx.state.call_stack.size();

  // Ensure capacity so the push doesn't reallocate, which would
  // invalidate frame references held by callers up the stack.
  if (ctx.state.call_stack.size() == ctx.state.call_stack.capacity()) {
    ctx.state.call_stack.reserve(ctx.state.call_stack.capacity() * 2);
  }

  ctx.state.call_stack.emplace_back();
  SetupFrame(ctx.state.Frame(), ctx.memory, func, args);

  while (ctx.state.call_stack.size() > saved_depth) {
    auto result = Step(ctx.state, ctx.memory, ctx.factory, ctx.driver);
    if (result.status != StepStatus::CONTINUE) {
      while (ctx.state.call_stack.size() > saved_depth) {
        ctx.state.call_stack.pop_back();
      }
      return;
    }
  }
}

// ---------------------------------------------------------------------------
// GetValue — look up or lazily evaluate an instruction's value
// ---------------------------------------------------------------------------

static Value GetValue(Ctx &ctx, CallFrame &frame, const IRInstruction &inst) {
  auto eid = EntityId(inst.id()).Pack();
  auto it = frame.values.find(eid);
  if (it != frame.values.end()) {
    return it->second;
  }

  auto op = inst.opcode();
  if (!ir::IsTerminator(op)) {
    Eval(ctx, inst);
    it = frame.values.find(eid);
    if (it != frame.values.end()) {
      return it->second;
    }
  }
  return MakeUndef();
}

// ---------------------------------------------------------------------------
// ResolveVAListAddr
// ---------------------------------------------------------------------------

static std::optional<uint64_t> ResolveVAListAddr(
    Ctx &ctx, CallFrame &frame, const IRInstruction &operand) {
  auto load_mi = MemoryInst::from(operand);
  Value addr = load_mi
      ? GetValue(ctx, frame, load_mi->address())
      : GetValue(ctx, frame, operand);
  auto *ptr = AsPointer(addr);
  if (!ptr || !IsConcrete(*ptr)) return std::nullopt;
  return ConcreteAddress(*ptr);
}

// ---------------------------------------------------------------------------
// DerefArgPointer — load the value from an ALLOCA/ARG pointer
// ---------------------------------------------------------------------------

static Value DerefArgPointer(Ctx &ctx, CallFrame &frame,
                             const IRInstruction &arg) {
  Value v = GetValue(ctx, frame, arg);
  auto *ptr = AsPointer(v);
  if (ptr && IsConcrete(*ptr)) {
    auto ai = AllocaInst::from(arg);
    uint32_t sz = ai ? ai->size_bytes() : 8;
    if (sz == 0) sz = 8;
    if (sz > 8) return v;
    return MemReadValue(ctx.memory, ConcreteAddress(*ptr), sz, false);
  }
  return v;
}

// ---------------------------------------------------------------------------
// EvalMemorySubOp — handle bulk memory/string sub-operations
// ---------------------------------------------------------------------------

static Value EvalMemorySubOp(Ctx &ctx, CallFrame &frame,
                             const MemoryInst &mi, MemOp sub,
                             const std::vector<Value> &ops) {
  Value result = MakeUndef();
  using MO = ir::MemOp;
  auto &memory = ctx.memory;

  switch (sub) {
    case MO::MEMSET: {
      if (ops.size() >= 3) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p) && AsInt(ops[2]) > 0) {
          memory.Memset(ConcreteAddress(*p),
                        static_cast<uint8_t>(AsInt(ops[1])),
                        static_cast<uint32_t>(AsInt(ops[2])));
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::MEMCPY:
    case MO::MEMMOVE: {
      if (ops.size() >= 3) {
        auto *dp = AsPointer(ops[0]);
        int64_t len = AsInt(ops[2]);
        if (dp && IsConcrete(*dp) && len > 0) {
          auto *sp = AsPointer(ops[1]);
          if (sp && IsConcrete(*sp)) {
            memory.Memcpy(ConcreteAddress(*dp), ConcreteAddress(*sp),
                          static_cast<uint32_t>(len));
          } else if (auto *sv = std::get_if<ScalarValue>(&ops[1])) {
            memory.Write(ConcreteAddress(*dp), &sv->bits,
                         static_cast<uint32_t>(
                             std::min(static_cast<size_t>(len),
                                      sizeof(sv->bits))));
          }
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::BZERO: {
      if (ops.size() >= 2) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p) && AsInt(ops[1]) > 0) {
          memory.Memset(ConcreteAddress(*p), 0,
                        static_cast<uint32_t>(AsInt(ops[1])));
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::STRLEN: {
      if (ops.size() >= 1) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          size_t len = 0;
          uint8_t byte = 0;
          while (true) {
            memory.Read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = MakeInt(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRNLEN: {
      if (ops.size() >= 2) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          size_t maxlen = static_cast<size_t>(AsInt(ops[1]));
          size_t len = 0;
          uint8_t byte = 0;
          while (len < maxlen) {
            memory.Read(addr + len, &byte, 1);
            if (byte == 0) break;
            ++len;
          }
          result = MakeInt(static_cast<int64_t>(len));
        }
      }
      break;
    }
    case MO::STRCMP: {
      if (ops.size() >= 2) {
        auto *p0 = AsPointer(ops[0]);
        auto *p1 = AsPointer(ops[1]);
        if (p0 && p1 && IsConcrete(*p0) && IsConcrete(*p1)) {
          uint64_t a0 = ConcreteAddress(*p0);
          uint64_t a1 = ConcreteAddress(*p1);
          int cmp = 0;
          for (size_t i = 0; ; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory.Read(a0 + i, &c0, 1);
            memory.Read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = MakeInt(cmp);
        }
      }
      break;
    }
    case MO::STRNCMP: {
      if (ops.size() >= 3) {
        auto *p0 = AsPointer(ops[0]);
        auto *p1 = AsPointer(ops[1]);
        if (p0 && p1 && IsConcrete(*p0) && IsConcrete(*p1)) {
          uint64_t a0 = ConcreteAddress(*p0);
          uint64_t a1 = ConcreteAddress(*p1);
          size_t n = static_cast<size_t>(AsInt(ops[2]));
          int cmp = 0;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c0 = 0, c1 = 0;
            memory.Read(a0 + i, &c0, 1);
            memory.Read(a1 + i, &c1, 1);
            if (c0 != c1) { cmp = (c0 < c1) ? -1 : 1; break; }
            if (c0 == 0) break;
          }
          result = MakeInt(cmp);
        }
      }
      break;
    }
    case MO::MEMCMP: {
      if (ops.size() >= 3) {
        auto *p0 = AsPointer(ops[0]);
        auto *p1 = AsPointer(ops[1]);
        if (p0 && p1 && IsConcrete(*p0) && IsConcrete(*p1)) {
          size_t len = static_cast<size_t>(AsInt(ops[2]));
          std::vector<uint8_t> buf0(len, 0), buf1(len, 0);
          memory.Read(ConcreteAddress(*p0), buf0.data(),
                      static_cast<uint32_t>(len));
          memory.Read(ConcreteAddress(*p1), buf1.data(),
                      static_cast<uint32_t>(len));
          result = MakeInt(std::memcmp(buf0.data(), buf1.data(), len));
        }
      }
      break;
    }
    case MO::MEMCHR: {
      if (ops.size() >= 3) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          size_t len = static_cast<size_t>(AsInt(ops[2]));
          uint8_t needle = static_cast<uint8_t>(AsInt(ops[1]));
          for (size_t i = 0; i < len; ++i) {
            uint8_t byte = 0;
            memory.Read(addr + i, &byte, 1);
            if (byte == needle) {
              result = MakePtr(addr + i);
              break;
            }
          }
        }
      }
      break;
    }
    case MO::STRCHR: {
      if (ops.size() >= 2) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          uint8_t needle = static_cast<uint8_t>(AsInt(ops[1]));
          bool found = false;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory.Read(addr + i, &byte, 1);
            if (byte == needle) {
              result = MakePtr(addr + i);
              found = true;
              break;
            }
            if (byte == 0) break;
          }
          if (!found) {
            if (needle == 0) {
              for (size_t i = 0; ; ++i) {
                uint8_t byte = 0;
                memory.Read(addr + i, &byte, 1);
                if (byte == 0) {
                  result = MakePtr(addr + i);
                  found = true;
                  break;
                }
              }
            }
            if (!found) {
              result = MakeNull();
            }
          }
        }
      }
      break;
    }
    case MO::STRRCHR: {
      if (ops.size() >= 2) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          uint8_t needle = static_cast<uint8_t>(AsInt(ops[1]));
          int64_t last_pos = -1;
          for (size_t i = 0; ; ++i) {
            uint8_t byte = 0;
            memory.Read(addr + i, &byte, 1);
            if (byte == needle) {
              last_pos = static_cast<int64_t>(i);
            }
            if (byte == 0) break;
          }
          if (last_pos >= 0) {
            result = MakePtr(addr + static_cast<uint64_t>(last_pos));
          } else {
            result = MakeNull();
          }
        }
      }
      break;
    }
    case MO::STRSTR: {
      if (ops.size() >= 2) {
        auto *p0 = AsPointer(ops[0]);
        auto *p1 = AsPointer(ops[1]);
        if (p0 && p1 && IsConcrete(*p0) && IsConcrete(*p1)) {
          uint64_t ha = ConcreteAddress(*p0);
          uint64_t na = ConcreteAddress(*p1);
          std::string haystack, needle_str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0;
            memory.Read(ha + i, &b, 1);
            if (b == 0) break;
            haystack.push_back(static_cast<char>(b));
          }
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0;
            memory.Read(na + i, &b, 1);
            if (b == 0) break;
            needle_str.push_back(static_cast<char>(b));
          }
          if (needle_str.empty()) {
            result = ops[0];
          } else {
            auto pos = haystack.find(needle_str);
            if (pos != std::string::npos) {
              result = MakePtr(ha + pos);
            } else {
              result = MakeNull();
            }
          }
        }
      }
      break;
    }
    case MO::STRCPY: {
      if (ops.size() >= 2) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0;
            memory.Read(sa + i, &c, 1);
            memory.Write(da + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::STRNCPY: {
      if (ops.size() >= 3) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          size_t n = static_cast<size_t>(AsInt(ops[2]));
          bool hit_null = false;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) {
              memory.Read(sa + i, &c, 1);
              if (c == 0) hit_null = true;
            }
            memory.Write(da + i, &c, 1);
          }
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::STRCAT: {
      if (ops.size() >= 2) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) {
            memory.Read(da + dlen, &byte, 1);
            if (byte == 0) break;
            ++dlen;
          }
          for (size_t i = 0; ; ++i) {
            uint8_t c = 0;
            memory.Read(sa + i, &c, 1);
            memory.Write(da + dlen + i, &c, 1);
            if (c == 0) break;
          }
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::STRNCAT: {
      if (ops.size() >= 3) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          size_t n = static_cast<size_t>(AsInt(ops[2]));
          size_t dlen = 0;
          uint8_t byte = 0;
          while (true) {
            memory.Read(da + dlen, &byte, 1);
            if (byte == 0) break;
            ++dlen;
          }
          size_t i = 0;
          for (; i < n; ++i) {
            uint8_t c = 0;
            memory.Read(sa + i, &c, 1);
            if (c == 0) break;
            memory.Write(da + dlen + i, &c, 1);
          }
          uint8_t nul = 0;
          memory.Write(da + dlen + i, &nul, 1);
        }
      }
      result = ops.empty() ? MakeUndef() : ops[0];
      break;
    }
    case MO::STPCPY: {
      if (ops.size() >= 2) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          size_t i = 0;
          for (; ; ++i) {
            uint8_t c = 0;
            memory.Read(sa + i, &c, 1);
            memory.Write(da + i, &c, 1);
            if (c == 0) break;
          }
          result = MakePtr(da + i);
        }
      }
      break;
    }
    case MO::STPNCPY: {
      if (ops.size() >= 3) {
        auto *dp = AsPointer(ops[0]);
        auto *sp = AsPointer(ops[1]);
        if (dp && sp && IsConcrete(*dp) && IsConcrete(*sp)) {
          uint64_t da = ConcreteAddress(*dp);
          uint64_t sa = ConcreteAddress(*sp);
          size_t n = static_cast<size_t>(AsInt(ops[2]));
          bool hit_null = false;
          size_t null_pos = n;
          for (size_t i = 0; i < n; ++i) {
            uint8_t c = 0;
            if (!hit_null) {
              memory.Read(sa + i, &c, 1);
              if (c == 0) { hit_null = true; null_pos = i; }
            }
            memory.Write(da + i, &c, 1);
          }
          result = MakePtr(da + null_pos);
        }
      }
      break;
    }
    case MO::STRTOI32: case MO::STRTOI64:
    case MO::STRTOU32: case MO::STRTOU64:
    case MO::STRTOF32: case MO::STRTOF64: {
      if (ops.size() >= 1) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          std::string str;
          for (size_t i = 0; ; ++i) {
            uint8_t b = 0;
            memory.Read(addr + i, &b, 1);
            if (b == 0) break;
            str.push_back(static_cast<char>(b));
          }
          switch (sub) {
            case MO::STRTOI32:
              result = MakeInt(static_cast<int64_t>(
                  std::strtol(str.c_str(), nullptr, 10)));
              break;
            case MO::STRTOI64:
              result = MakeInt(static_cast<int64_t>(
                  std::strtoll(str.c_str(), nullptr, 10)));
              break;
            case MO::STRTOU32:
              result = MakeInt(static_cast<int64_t>(
                  std::strtoul(str.c_str(), nullptr, 10)));
              break;
            case MO::STRTOU64:
              result = MakeInt(static_cast<int64_t>(
                  std::strtoull(str.c_str(), nullptr, 10)));
              break;
            case MO::STRTOF32:
              result = MakeFloat(static_cast<double>(
                  std::strtof(str.c_str(), nullptr)));
              break;
            case MO::STRTOF64:
              result = MakeFloat(
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
      if (ops.size() >= 1) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory.Read(addr + first_byte, buf.data(), num_bytes);
          uint64_t raw = 0;
          if (sub == MO::BIT_READ_LE) {
            for (uint32_t i = 0; i < num_bytes; ++i) {
              raw |= static_cast<uint64_t>(buf[i]) << (i * 8);
            }
            raw >>= (bo % 8);
          } else {
            for (uint32_t i = 0; i < num_bytes; ++i) {
              raw = (raw << 8) | buf[i];
            }
            uint32_t top_bits = num_bytes * 8;
            uint32_t shift = top_bits - (bo % 8) - bw;
            raw >>= shift;
          }
          uint64_t mask = (bw >= 64) ? ~uint64_t{0}
                                     : ((uint64_t{1} << bw) - 1);
          raw &= mask;
          result = MakeInt(static_cast<int64_t>(raw));
        }
      }
      break;
    }
    case MO::BIT_WRITE_LE: case MO::BIT_WRITE_BE: {
      if (ops.size() >= 2) {
        auto *p = AsPointer(ops[0]);
        if (p && IsConcrete(*p)) {
          uint64_t addr = ConcreteAddress(*p);
          uint32_t bo = mi.bit_offset();
          uint32_t bw = mi.bit_width();
          uint64_t val = static_cast<uint64_t>(AsInt(ops[1]));
          uint64_t mask = (bw >= 64) ? ~uint64_t{0}
                                     : ((uint64_t{1} << bw) - 1);
          val &= mask;
          uint32_t first_byte = bo / 8;
          uint32_t last_byte = (bo + bw - 1) / 8;
          uint32_t num_bytes = last_byte - first_byte + 1;
          std::vector<uint8_t> buf(num_bytes, 0);
          memory.Read(addr + first_byte, buf.data(), num_bytes);
          if (sub == MO::BIT_WRITE_LE) {
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
          memory.Write(addr + first_byte, buf.data(), num_bytes);
        }
      }
      break;
    }
    case MO::CONSUME_VA_PARAM:
      break;
    default:
      if (ir::IsCmpxchg(sub)) {
        result = MakeUndef();
      }
      break;
  }
  return result;
}

// ---------------------------------------------------------------------------
// EvalCall — resolve and execute a function call
// Returns true if a callee frame was pushed (caller must return CONTINUE).
// Returns false if the call was resolved inline (SKIP/MODEL).
// ---------------------------------------------------------------------------

static bool EvalCall(Ctx &ctx, const IRInstruction &inst) {
  auto ci = CallInst::from(inst);
  if (!ci) return false;

  auto &frame = ctx.Frame();
  auto eid = EntityId(inst.id()).Pack();

  // Collect arguments: dereference ALLOCA/ARG pointers.
  std::vector<Value> call_args;
  for (auto arg : ci->arguments()) {
    call_args.push_back(DerefArgPointer(ctx, frame, arg));
  }

  // Resolve the callee.
  std::optional<IRFunction> callee_ir;
  auto target_decl = ci->target();
  RawEntityId indirect_eid = kInvalidEntityId;

  if (target_decl) {
    callee_ir = IRFunction::from(*target_decl);
  }

  // Indirect call: read entity ID from the function pointer.
  if (!callee_ir && ci->is_indirect()) {
    Value callee_val = GetValue(ctx, frame, inst.nth_operand(0));
    if (auto *ptr = AsPointer(callee_val)) {
      if (IsConcrete(*ptr)) {
        ctx.memory.Read(ConcreteAddress(*ptr), &indirect_eid, 8);
      }
    }
  }

  // If inline resolution failed, consult the Driver.
  if (!callee_ir) {
    RawEntityId target_eid = target_decl
        ? target_decl->id().Pack() : kInvalidEntityId;

    Suspension s = NeedCallResolution{
        inst, target_eid, indirect_eid, call_args, ci->is_indirect()};
    auto resolution = ctx.driver.Resolve(s);
    auto *cr = std::get_if<CallResolution>(&resolution);
    if (!cr) {
      frame.values[eid] = MakeUndef();
      return false;
    }
    switch (cr->action) {
      case CallAction::INLINE:
        callee_ir = cr->callee_ir;
        break;
      case CallAction::MODEL:
      case CallAction::SKIP:
        frame.values[eid] = cr->return_value;
        return false;
    }
  }

  if (!callee_ir) {
    frame.values[eid] = MakeUndef();
    return false;
  }

  // Get return ptr from caller BEFORE pushing (frame ref invalidated by push).
  Value return_ptr{Undefined{}};
  auto ret_alloca = ci->return_alloca();
  if (ret_alloca) {
    return_ptr = GetValue(ctx, frame, *ret_alloca);
  }

  // Set resume point on the caller's frame.
  frame.resume_after_inst = eid;

  // Push callee frame. NOTE: `frame` reference is invalidated after this.
  if (ctx.state.call_stack.size() == ctx.state.call_stack.capacity()) {
    ctx.state.call_stack.reserve(ctx.state.call_stack.capacity() * 2);
  }
  ctx.state.call_stack.emplace_back();
  auto &callee_frame = ctx.state.Frame();
  if (!IsUndefined(return_ptr)) {
    callee_frame.return_ptr = return_ptr;
  }
  SetupFrame(callee_frame, ctx.memory, *callee_ir, call_args);

  return true;
}

// ---------------------------------------------------------------------------
// Eval — evaluate a single non-terminator instruction
// Returns true if a callee frame was pushed (CALL).
// ---------------------------------------------------------------------------

static bool Eval(Ctx &ctx, const IRInstruction &inst) {
  auto &frame = ctx.Frame();
  auto op = inst.opcode();
  auto eid = EntityId(inst.id()).Pack();
  Value result = MakeUndef();

  switch (op) {

    // --- Constants ---
    case OpCode::CONST: {
      auto ci = ConstInst::from(inst);
      if (!ci) break;
      auto sub = ci->sub_opcode();
      if (sub == ir::ConstOp::NULL_PTR) {
        result = ctx.factory.MakeNullPtr();
      } else if (sub == ir::ConstOp::FLOAT32 ||
                 sub == ir::ConstOp::FLOAT16) {
        result = MakeFloat32(static_cast<float>(ci->float_value()));
      } else if (sub == ir::ConstOp::FLOAT64) {
        result = MakeFloat(ci->float_value());
      } else if (sub == ir::ConstOp::INF32) {
        result = MakeFloat32(std::numeric_limits<float>::infinity());
      } else if (sub == ir::ConstOp::INF64) {
        result = MakeFloat(std::numeric_limits<double>::infinity());
      } else if (sub == ir::ConstOp::NAN32) {
        result = MakeFloat32(std::numeric_limits<float>::quiet_NaN());
      } else if (sub == ir::ConstOp::NAN64) {
        result = MakeFloat(std::numeric_limits<double>::quiet_NaN());
      } else {
        result = ctx.factory.MakeConst(sub, ci->signed_value(),
                                       ci->unsigned_value());
      }
      break;
    }

    // --- Memory: ALLOCA ---
    case OpCode::ALLOCA: {
      auto ai = AllocaInst::from(inst);
      if (!ai) break;
      auto obj = ai->object();
      auto obj_eid = EntityId(obj.id()).Pack();
      if (frame.entity_to_address.find(obj_eid) ==
          frame.entity_to_address.end()) {
        if (auto da = DynamicAllocaInst::from(inst)) {
          Value sz_val = GetValue(ctx, frame, da->size());
          uint32_t runtime_sz = static_cast<uint32_t>(AsInt(sz_val));
          if (runtime_sz > 0) {
            auto addr = ctx.memory.Allocate(runtime_sz, ai->align_bytes());
            frame.entity_to_address[obj_eid] = addr;
          } else {
            AllocateObject(frame, ctx.memory, obj);
          }
        } else {
          AllocateObject(frame, ctx.memory, obj);
        }
      }
      result = MakePtr(frame.entity_to_address[obj_eid]);
      break;
    }

    // --- String pointer ---
    case OpCode::STRING_PTR_32:
    case OpCode::STRING_PTR_64: {
      auto inst_eid = EntityId(inst.id()).Pack();
      if (frame.entity_to_address.find(inst_eid) ==
          frame.entity_to_address.end()) {
        if (auto src = inst.source_statement()) {
          if (auto sl = StringLiteral::from(*src)) {
            auto bytes = sl->bytes();
            uint32_t char_width = sl->character_byte_width();
            uint32_t total = sl->byte_length() + char_width;
            auto addr = ctx.memory.Allocate(total, 1);
            frame.entity_to_address[inst_eid] = addr;
            ctx.memory.Write(addr, bytes.data(),
                             std::min<uint32_t>(
                                 static_cast<uint32_t>(bytes.size()), total));
          }
        }
      }
      auto it = frame.entity_to_address.find(inst_eid);
      result = (it != frame.entity_to_address.end())
                   ? MakePtr(it->second) : MakeUndef();
      break;
    }

    // --- Memory: loads, stores, bulk ops ---
    case OpCode::MEMORY: {
      auto mi = MemoryInst::from(inst);
      if (!mi) break;
      auto sub = mi->sub_opcode();

      // CONSUME_VA_PARAM: handled here because we need both the va_list
      // address and the frame's param_ptrs.
      if (sub == ir::MemOp::CONSUME_VA_PARAM) {
        auto cvp = ConsumeVAParamInst::from(inst);
        if (cvp) {
          auto va_addr = ResolveVAListAddr(ctx, frame,
                                           cvp->va_list_operand());
          if (va_addr) {
            uint32_t idx = 0;
            ctx.memory.Read(*va_addr, &idx, 4);
            if (idx < frame.param_ptrs.size()) {
              result = frame.param_ptrs[idx];
              ++idx;
              ctx.memory.Write(*va_addr, &idx, 4);
            }
          }
        }
        break;
      }

      if (ir::IsDirectLoadStore(sub)) {
        unsigned sz = ir::AccessSize(sub);
        bool is_float = ir::IsFloatLoad(sub);
        if (ir::IsAnyLoad(sub)) {
          Value addr = GetValue(ctx, frame, mi->address());
          auto *ptr = AsPointer(addr);
          if (ptr && IsConcrete(*ptr)) {
            result = MemReadValue(ctx.memory, ConcreteAddress(*ptr),
                                  sz, is_float);
          }
        } else {
          Value addr = GetValue(ctx, frame, mi->address());
          Value val = GetValue(ctx, frame, mi->stored_value());
          auto *ptr = AsPointer(addr);
          if (ptr && IsConcrete(*ptr)) {
            MemWriteValue(ctx.memory, ConcreteAddress(*ptr), val, sz);
          }
        }
      } else {
        std::vector<Value> ops;
        for (auto op_inst : inst.operands()) {
          ops.push_back(GetValue(ctx, frame, op_inst));
        }
        result = EvalMemorySubOp(ctx, frame, *mi, sub, ops);
      }
      break;
    }

    // --- GEP field ---
    case OpCode::GEP_FIELD_32:
    case OpCode::GEP_FIELD_64: {
      auto gep = GEPFieldInst::from(inst);
      if (!gep) break;
      Value base = GetValue(ctx, frame, gep->base());
      int64_t off = gep->byte_offset();
      auto *ptr = AsPointer(base);
      if (ptr && IsConcrete(*ptr)) {
        result = MakePtr(ConcreteAddress(*ptr) + off);
      }
      break;
    }

    // --- Pointer arithmetic ---
    case OpCode::PTR_ADD_32:
    case OpCode::PTR_ADD_64: {
      auto pa = PtrAddInst::from(inst);
      if (!pa) break;
      Value base = GetValue(ctx, frame, pa->base());
      Value idx = GetValue(ctx, frame, pa->index());
      int64_t elem_size = pa->element_size();
      result = ctx.factory.PtrAdd(base, idx, elem_size);
      break;
    }

    case OpCode::PTR_DIFF_32:
    case OpCode::PTR_DIFF_64: {
      auto pd = PtrDiffInst::from(inst);
      if (!pd) break;
      Value lhs = GetValue(ctx, frame, pd->lhs());
      Value rhs = GetValue(ctx, frame, pd->rhs());
      result = ctx.factory.PtrDiff(lhs, rhs, pd->element_size());
      break;
    }

    // --- Binary arithmetic ---
    case OpCode::ADD_8: case OpCode::ADD_16:
    case OpCode::ADD_32: case OpCode::ADD_64:
    case OpCode::SUB_8: case OpCode::SUB_16:
    case OpCode::SUB_32: case OpCode::SUB_64:
    case OpCode::MUL_8: case OpCode::MUL_16:
    case OpCode::MUL_32: case OpCode::MUL_64:
    case OpCode::DIV_8: case OpCode::DIV_16:
    case OpCode::DIV_32: case OpCode::DIV_64:
    case OpCode::REM_8: case OpCode::REM_16:
    case OpCode::REM_32: case OpCode::REM_64:
    case OpCode::UDIV_8: case OpCode::UDIV_16:
    case OpCode::UDIV_32: case OpCode::UDIV_64:
    case OpCode::UREM_8: case OpCode::UREM_16:
    case OpCode::UREM_32: case OpCode::UREM_64:
    case OpCode::USHR_8: case OpCode::USHR_16:
    case OpCode::USHR_32: case OpCode::USHR_64:
    case OpCode::BIT_AND_8: case OpCode::BIT_AND_16:
    case OpCode::BIT_AND_32: case OpCode::BIT_AND_64:
    case OpCode::BIT_OR_8: case OpCode::BIT_OR_16:
    case OpCode::BIT_OR_32: case OpCode::BIT_OR_64:
    case OpCode::BIT_XOR_8: case OpCode::BIT_XOR_16:
    case OpCode::BIT_XOR_32: case OpCode::BIT_XOR_64:
    case OpCode::SHL_8: case OpCode::SHL_16:
    case OpCode::SHL_32: case OpCode::SHL_64:
    case OpCode::SHR_8: case OpCode::SHR_16:
    case OpCode::SHR_32: case OpCode::SHR_64:
    case OpCode::FADD_32: case OpCode::FADD_64:
    case OpCode::FSUB_32: case OpCode::FSUB_64:
    case OpCode::FMUL_32: case OpCode::FMUL_64:
    case OpCode::FDIV_32: case OpCode::FDIV_64:
    case OpCode::FREM_32: case OpCode::FREM_64: {
      auto bin = BinaryInst::from(inst);
      if (bin) {
        Value lhs_val = GetValue(ctx, frame, bin->lhs());
        Value rhs_val = GetValue(ctx, frame, bin->rhs());
        result = ctx.factory.BinaryOp(op, lhs_val, rhs_val);
      }
      break;
    }

    // --- Logical ---
    case OpCode::LOGICAL_AND: case OpCode::LOGICAL_OR: {
      auto bin = BinaryInst::from(inst);
      if (bin) {
        Value lhs_val = GetValue(ctx, frame, bin->lhs());
        Value rhs_val = GetValue(ctx, frame, bin->rhs());
        result = ctx.factory.BinaryOp(op, lhs_val, rhs_val);
      }
      break;
    }

    // --- Comparisons ---
    case OpCode::CMP_EQ_8: case OpCode::CMP_EQ_16:
    case OpCode::CMP_EQ_32: case OpCode::CMP_EQ_64:
    case OpCode::CMP_NE_8: case OpCode::CMP_NE_16:
    case OpCode::CMP_NE_32: case OpCode::CMP_NE_64:
    case OpCode::CMP_LT_8: case OpCode::CMP_LT_16:
    case OpCode::CMP_LT_32: case OpCode::CMP_LT_64:
    case OpCode::CMP_LE_8: case OpCode::CMP_LE_16:
    case OpCode::CMP_LE_32: case OpCode::CMP_LE_64:
    case OpCode::CMP_GT_8: case OpCode::CMP_GT_16:
    case OpCode::CMP_GT_32: case OpCode::CMP_GT_64:
    case OpCode::CMP_GE_8: case OpCode::CMP_GE_16:
    case OpCode::CMP_GE_32: case OpCode::CMP_GE_64:
    case OpCode::UCMP_LT_8: case OpCode::UCMP_LT_16:
    case OpCode::UCMP_LT_32: case OpCode::UCMP_LT_64:
    case OpCode::UCMP_LE_8: case OpCode::UCMP_LE_16:
    case OpCode::UCMP_LE_32: case OpCode::UCMP_LE_64:
    case OpCode::UCMP_GT_8: case OpCode::UCMP_GT_16:
    case OpCode::UCMP_GT_32: case OpCode::UCMP_GT_64:
    case OpCode::UCMP_GE_8: case OpCode::UCMP_GE_16:
    case OpCode::UCMP_GE_32: case OpCode::UCMP_GE_64:
    case OpCode::FCMP_EQ_32: case OpCode::FCMP_EQ_64:
    case OpCode::FCMP_NE_32: case OpCode::FCMP_NE_64:
    case OpCode::FCMP_LT_32: case OpCode::FCMP_LT_64:
    case OpCode::FCMP_LE_32: case OpCode::FCMP_LE_64:
    case OpCode::FCMP_GT_32: case OpCode::FCMP_GT_64:
    case OpCode::FCMP_GE_32: case OpCode::FCMP_GE_64: {
      auto cmp = ComparisonInst::from(inst);
      if (cmp) {
        Value lhs_val = GetValue(ctx, frame, cmp->lhs());
        Value rhs_val = GetValue(ctx, frame, cmp->rhs());
        result = ctx.factory.Compare(op, lhs_val, rhs_val);
      }
      break;
    }

    // --- Unary ---
    case OpCode::NEG_8: case OpCode::NEG_16:
    case OpCode::NEG_32: case OpCode::NEG_64:
    case OpCode::FNEG_32: case OpCode::FNEG_64:
    case OpCode::BIT_NOT_8: case OpCode::BIT_NOT_16:
    case OpCode::BIT_NOT_32: case OpCode::BIT_NOT_64:
    case OpCode::LOGICAL_NOT:
    case OpCode::ABS_8: case OpCode::ABS_16:
    case OpCode::ABS_32: case OpCode::ABS_64: {
      auto u = UnaryInst::from(inst);
      if (u) {
        Value operand_val = GetValue(ctx, frame, u->operand());
        result = ctx.factory.UnaryOp(op, operand_val);
      }
      break;
    }

    // --- Cast ---
    case OpCode::CAST: {
      auto c = CastInst::from(inst);
      if (c) {
        Value operand_val = GetValue(ctx, frame, c->operand());
        result = ctx.factory.Cast(c->sub_opcode(), operand_val);
      }
      break;
    }

    // --- Read-modify-write ---
    case OpCode::READ_MODIFY_WRITE: {
      auto rmw = ReadModifyWriteInst::from(inst);
      if (!rmw) break;
      Value addr = GetValue(ctx, frame, rmw->address());
      auto *ptr = AsPointer(addr);
      if (!ptr || !IsConcrete(*ptr)) break;
      uint64_t address = ConcreteAddress(*ptr);

      auto underlying = rmw->underlying_op();
      size_t access_sz = UnderlyingOpAccessSize(underlying);
      bool rmw_is_float = ir::IsFloatArithmetic(underlying);
      Value old_val = MemReadValue(ctx.memory, address, access_sz,
                                   rmw_is_float);

      Value rhs = MakeInt(0);
      for (auto rhs_op : rmw->rhs_operands()) {
        rhs = GetValue(ctx, frame, rhs_op);
        break;
      }

      // Overflow-checked arithmetic.
      if (underlying >= OpCode::ADD_OVERFLOW_8 &&
          underlying <= OpCode::MUL_OVERFLOW_64) {
        Value a = MakeInt(0), b = MakeInt(0);
        int rhs_i = 0;
        for (auto rhs_op : rmw->rhs_operands()) {
          if (rhs_i == 0) a = GetValue(ctx, frame, rhs_op);
          else if (rhs_i == 1) b = GetValue(ctx, frame, rhs_op);
          ++rhs_i;
        }
        __int128 wide;
        if (underlying >= OpCode::ADD_OVERFLOW_8 &&
            underlying <= OpCode::ADD_OVERFLOW_64)
          wide = static_cast<__int128>(AsInt(a)) +
                 static_cast<__int128>(AsInt(b));
        else if (underlying >= OpCode::SUB_OVERFLOW_8 &&
                 underlying <= OpCode::SUB_OVERFLOW_64)
          wide = static_cast<__int128>(AsInt(a)) -
                 static_cast<__int128>(AsInt(b));
        else
          wide = static_cast<__int128>(AsInt(a)) *
                 static_cast<__int128>(AsInt(b));

        Value new_val = MakeInt(static_cast<int64_t>(wide));
        bool overflow =
            (wide != static_cast<__int128>(static_cast<int64_t>(wide)));
        MemWriteValue(ctx.memory, address, new_val, access_sz);
        result = MakeInt(overflow ? 1 : 0);
        break;
      }

      // PTR_ADD in RMW.
      if (underlying == OpCode::PTR_ADD_32 ||
          underlying == OpCode::PTR_ADD_64) {
        int64_t elem_sz = rmw->element_size();
        if (elem_sz <= 0) elem_sz = 1;
        Value new_val = ctx.factory.PtrAdd(old_val, rhs, elem_sz);
        MemWriteValue(ctx.memory, address, new_val, access_sz);
        result = rmw->returns_new_value() ? new_val : old_val;
        break;
      }

      // Atomic exchange.
      if (underlying >= OpCode::ATOMIC_EXCHANGE_8 &&
          underlying <= OpCode::ATOMIC_EXCHANGE_64) {
        MemWriteValue(ctx.memory, address, rhs, access_sz);
        result = rmw->returns_new_value() ? rhs : old_val;
        break;
      }

      // General case: delegate to factory.
      Value new_val = ctx.factory.BinaryOp(underlying, old_val, rhs);
      MemWriteValue(ctx.memory, address, new_val, access_sz);
      result = rmw->returns_new_value() ? new_val : old_val;
      break;
    }

    // --- Call ---
    case OpCode::CALL: {
      if (EvalCall(ctx, inst)) {
        // Callee frame was pushed. EvalCall already set resume_after_inst
        // and the call result will be stored by the RET handler.
        return true;
      }
      // SKIP/MODEL: EvalCall already set frame.values[eid].
      return false;
    }

    // --- Select ---
    case OpCode::SELECT: {
      auto sel = SelectInst::from(inst);
      if (sel) {
        Value cond = GetValue(ctx, frame, sel->condition());
        Value if_true = GetValue(ctx, frame, sel->true_value());
        Value if_false = GetValue(ctx, frame, sel->false_value());
        result = ctx.factory.Select(cond, if_true, if_false);
      }
      break;
    }

    // --- Last value (comma operator) ---
    case OpCode::LAST_VALUE: {
      auto lv = LastValueInst::from(inst);
      if (lv) {
        result = GetValue(ctx, frame, lv->last());
      }
      break;
    }

    // --- Param pointer ---
    case OpCode::PARAM_PTR_32:
    case OpCode::PARAM_PTR_64: {
      auto pr = ParamPtrInst::from(inst);
      if (pr) {
        uint32_t idx = pr->parameter_index();
        if (idx < frame.param_ptrs.size()) {
          result = frame.param_ptrs[idx];
        }
      }
      break;
    }

    // --- Bitwise intrinsics ---
    case OpCode::BITWISE_8: case OpCode::BITWISE_16:
    case OpCode::BITWISE_32: case OpCode::BITWISE_64: {
      auto bw = BitwiseOpInst::from(inst);
      if (bw) {
        Value val = MakeUndef();
        Value val2 = MakeUndef();
        int count = 0;
        for (auto op_inst : inst.operands()) {
          if (count == 0) val = GetValue(ctx, frame, op_inst);
          else if (count == 1) val2 = GetValue(ctx, frame, op_inst);
          ++count;
        }
        result = ctx.factory.BitwiseIntrinsic(op, bw->sub_opcode(),
                                              val, val2);
      }
      break;
    }

    // --- Float operations ---
    case OpCode::FLOAT: {
      auto fo = FloatOpInst::from(inst);
      if (fo) {
        std::vector<Value> ops;
        for (auto op_inst : inst.operands()) {
          ops.push_back(GetValue(ctx, frame, op_inst));
        }
        result = ctx.factory.FloatIntrinsic(fo->sub_opcode(), ops);
      }
      break;
    }

    // --- Global/thread-local pointers ---
    case OpCode::GLOBAL_PTR_32: case OpCode::GLOBAL_PTR_64:
    case OpCode::THREAD_LOCAL_PTR_32: case OpCode::THREAD_LOCAL_PTR_64: {
      auto src_eid = inst.source_entity_id();

      // Fast path: already resolved.
      auto git = ctx.state.global_addresses.find(src_eid);
      if (git != ctx.state.global_addresses.end()) {
        result = MakePtr(git->second);
        break;
      }

      // Ask the driver for global info.
      Suspension s = NeedGlobalResolution{src_eid};
      auto resolution = ctx.driver.Resolve(s);
      auto *gr = std::get_if<GlobalResolution>(&resolution);
      if (!gr || gr->info.size == 0) break;

      auto &info = gr->info;
      auto key = (info.canonical_eid != kInvalidEntityId)
                     ? info.canonical_eid : src_eid;

      // Check again with canonical key.
      git = ctx.state.global_addresses.find(key);
      if (git != ctx.state.global_addresses.end()) {
        if (key != src_eid) ctx.state.global_addresses[src_eid] = git->second;
        result = MakePtr(git->second);
        break;
      }

      // Allocate and initialize.
      uint32_t align = info.align;
      if (align == 0) align = 8;
      auto addr = ctx.memory.Allocate(info.size, align);
      ctx.state.global_addresses[key] = addr;
      if (key != src_eid) ctx.state.global_addresses[src_eid] = addr;

      if (info.initializer) {
        RunToCompletion(ctx, *info.initializer, {MakePtr(addr)});
      }

      result = MakePtr(addr);
      break;
    }

    // --- Function pointer ---
    case OpCode::FUNC_PTR_32:
    case OpCode::FUNC_PTR_64: {
      auto src_eid = inst.source_entity_id();
      if (frame.entity_to_address.find(src_eid) ==
          frame.entity_to_address.end()) {
        auto addr = ctx.memory.Allocate(8, 8);
        frame.entity_to_address[src_eid] = addr;
        ctx.memory.Write(addr, &src_eid, 8);
      }
      result = MakePtr(frame.entity_to_address[src_eid]);
      break;
    }

    // --- Return value pointer ---
    case OpCode::RETURN_PTR_32:
    case OpCode::RETURN_PTR_64:
      result = frame.return_ptr;
      break;

    // --- Scope markers ---
    case OpCode::ENTER_SCOPE: {
      auto esi = EnterScopeInst::from(inst);
      if (esi) {
        auto scope = esi->scope();
        for (auto obj : scope.objects()) {
          auto oid = EntityId(obj.id()).Pack();
          auto it = frame.entity_to_address.find(oid);
          if (it != frame.entity_to_address.end()) {
            ctx.memory.Unpoison(it->second);
          }
        }
      }
      break;
    }
    case OpCode::EXIT_SCOPE: {
      auto esi = ExitScopeInst::from(inst);
      if (esi) {
        auto scope = esi->scope();
        for (auto obj : scope.objects()) {
          auto oid = EntityId(obj.id()).Pack();
          auto it = frame.entity_to_address.find(oid);
          if (it != frame.entity_to_address.end()) {
            ctx.memory.Poison(it->second);
          }
        }
      }
      break;
    }

    // --- Undefined/poison ---
    case OpCode::UNDEFINED:
      result = MakeUndef();
      break;

    // --- Frame/return address intrinsics ---
    case OpCode::FRAME_PTR_32: case OpCode::FRAME_PTR_64:
    case OpCode::RETURN_ADDRESS_32: case OpCode::RETURN_ADDRESS_64:
      result = MakeUndef();
      break;

    // --- Variadic ---
    case OpCode::VA_START: {
      auto vai = VAStartInst::from(inst);
      if (vai) {
        auto va_addr = ResolveVAListAddr(ctx, frame,
                                         vai->va_list_operand());
        if (va_addr) {
          uint32_t idx = frame.variadic_start_index;
          ctx.memory.Write(*va_addr, &idx, 4);
        }
      }
      break;
    }
    case OpCode::VA_END: {
      auto vei = VAEndInst::from(inst);
      if (vei) {
        auto va_addr = ResolveVAListAddr(ctx, frame,
                                         vei->va_list_operand());
        if (va_addr) {
          uint32_t sentinel = ~0u;
          ctx.memory.Write(*va_addr, &sentinel, 4);
        }
      }
      break;
    }
    case OpCode::VA_COPY: {
      auto vci = VACopyInst::from(inst);
      if (vci) {
        auto src_addr = ResolveVAListAddr(ctx, frame, vci->src());
        auto dst_addr = ResolveVAListAddr(ctx, frame, vci->dest());
        if (src_addr && dst_addr) {
          uint32_t idx = 0;
          ctx.memory.Read(*src_addr, &idx, 4);
          ctx.memory.Write(*dst_addr, &idx, 4);
        }
      }
      break;
    }

    // --- Overflow/atomic opcodes (only valid as RMW underlying ops) ---
    case OpCode::ADD_OVERFLOW_8: case OpCode::ADD_OVERFLOW_16:
    case OpCode::ADD_OVERFLOW_32: case OpCode::ADD_OVERFLOW_64:
    case OpCode::SUB_OVERFLOW_8: case OpCode::SUB_OVERFLOW_16:
    case OpCode::SUB_OVERFLOW_32: case OpCode::SUB_OVERFLOW_64:
    case OpCode::MUL_OVERFLOW_8: case OpCode::MUL_OVERFLOW_16:
    case OpCode::MUL_OVERFLOW_32: case OpCode::MUL_OVERFLOW_64:
    case OpCode::ATOMIC_ADD_8: case OpCode::ATOMIC_ADD_16:
    case OpCode::ATOMIC_ADD_32: case OpCode::ATOMIC_ADD_64:
    case OpCode::ATOMIC_SUB_8: case OpCode::ATOMIC_SUB_16:
    case OpCode::ATOMIC_SUB_32: case OpCode::ATOMIC_SUB_64:
    case OpCode::ATOMIC_AND_8: case OpCode::ATOMIC_AND_16:
    case OpCode::ATOMIC_AND_32: case OpCode::ATOMIC_AND_64:
    case OpCode::ATOMIC_OR_8: case OpCode::ATOMIC_OR_16:
    case OpCode::ATOMIC_OR_32: case OpCode::ATOMIC_OR_64:
    case OpCode::ATOMIC_XOR_8: case OpCode::ATOMIC_XOR_16:
    case OpCode::ATOMIC_XOR_32: case OpCode::ATOMIC_XOR_64:
    case OpCode::ATOMIC_NAND_8: case OpCode::ATOMIC_NAND_16:
    case OpCode::ATOMIC_NAND_32: case OpCode::ATOMIC_NAND_64:
    case OpCode::ATOMIC_EXCHANGE_8: case OpCode::ATOMIC_EXCHANGE_16:
    case OpCode::ATOMIC_EXCHANGE_32: case OpCode::ATOMIC_EXCHANGE_64:
      break;

    // --- Terminators (handled by Step) ---
    case OpCode::COND_BRANCH:
    case OpCode::SWITCH:
    case OpCode::RET:
    case OpCode::UNREACHABLE:
    case OpCode::IMPLICIT_UNREACHABLE:
    case OpCode::BREAK:
    case OpCode::CONTINUE:
    case OpCode::GOTO:
    case OpCode::IMPLICIT_GOTO:
    case OpCode::FALLTHROUGH:
    case OpCode::IMPLICIT_FALLTHROUGH:
      break;

    case OpCode::UNKNOWN:
      break;
  }

  // Re-fetch frame: RunToCompletion (for global initializers) may have
  // reallocated the call stack, invalidating the cached `frame` reference.
  ctx.Frame().values[eid] = result;
  return false;
}

}  // namespace

// ===========================================================================
// Public API
// ===========================================================================

void InitState(InterpreterState &state, Memory &memory,
               const IRFunction &func, const std::vector<Value> &args) {
  state.call_stack.clear();
  state.call_stack.reserve(256);
  state.steps = 0;

  state.call_stack.emplace_back();
  SetupFrame(state.Frame(), memory, func, args);
}

StepResult Step(InterpreterState &state, Memory &memory,
                ValueFactory &factory, Driver &driver) {
  if (state.Empty()) {
    return {StepStatus::ERROR};
  }

  Ctx ctx{state, memory, factory, driver};

  // If not resuming from a call, clear cached values for fresh evaluation.
  bool resuming = (state.Frame().resume_after_inst != kInvalidEntityId);
  if (!resuming) {
    state.Frame().values.clear();
  }

  // Save and clear the resume point. We'll skip instructions up to this ID.
  RawEntityId skip_until = state.Frame().resume_after_inst;
  state.Frame().resume_after_inst = kInvalidEntityId;
  bool skipping = (skip_until != kInvalidEntityId);

  auto stack_depth = state.call_stack.size();

  // Save the block before iterating — the generator must outlive any frame
  // push that might reallocate the call stack vector.
  auto current_block = state.Frame().current_block;

  for (auto inst : current_block.all_instructions()) {
    auto inst_eid = EntityId(inst.id()).Pack();

    // Skip instructions until we pass the one we're resuming from.
    if (skipping) {
      if (inst_eid == skip_until) {
        skipping = false;
      }
      continue;
    }

    ++state.steps;
    auto op = inst.opcode();

    if (!ir::IsTerminator(op)) {
      if (Eval(ctx, inst)) {
        // A callee frame was pushed (CALL). Return to let the driver
        // loop call Step() on the callee.
        return {StepStatus::CONTINUE};
      }
      continue;
    }

    // ----- Terminator handling -----

    // We need a fresh frame reference since Eval might have mutated state
    // (e.g., RunToCompletion for globals). The frame is still valid because
    // we only get here if Eval didn't push (returned false).
    auto &frame = state.Frame();

    if (op == OpCode::RET) {
      auto ri = RetInst::from(inst);
      Value ret_from_inst = MakeUndef();
      if (ri) {
        if (auto rv = ri->return_value()) {
          ret_from_inst = GetValue(ctx, frame, *rv);
        }
      }

      if (state.call_stack.size() > 1) {
        // Read return value from callee's return slot.
        Value callee_result = ReadReturnValue(memory, frame, ret_from_inst);

        state.call_stack.pop_back();

        // Store the return value for the CALL instruction in the caller.
        auto &caller = state.Frame();
        if (caller.resume_after_inst != kInvalidEntityId) {
          caller.values[caller.resume_after_inst] = callee_result;
        }

        return {StepStatus::CONTINUE};
      }

      // Top-level return.
      Value final_result = ReadReturnValue(memory, frame, ret_from_inst);
      return {StepStatus::COMPLETED, {}, final_result};
    }

    if (op == OpCode::UNREACHABLE || op == OpCode::IMPLICIT_UNREACHABLE) {
      return {StepStatus::ERROR};
    }

    if (op == OpCode::COND_BRANCH) {
      auto cb = CondBranchInst::from(inst);
      if (cb) {
        Value cond = GetValue(ctx, frame, cb->condition());
        auto truth = factory.IsTrue(cond);
        if (truth.has_value()) {
          frame.current_block = *truth ? cb->true_block()
                                       : cb->false_block();
          return {StepStatus::CONTINUE};
        }
        // Symbolic/unknown: ask driver.
        Suspension s = NeedBranchDecision{cond, cb->true_block(),
                                          cb->false_block()};
        auto resolution = driver.Resolve(s);
        if (auto *bd = std::get_if<BranchDecision>(&resolution)) {
          frame.current_block = bd->take_true ? cb->true_block()
                                              : cb->false_block();
          return {StepStatus::CONTINUE};
        }
        return {StepStatus::SUSPENDED, std::move(s)};
      }
      return {StepStatus::ERROR};
    }

    if (op == OpCode::SWITCH) {
      auto sw = SwitchInst::from(inst);
      if (sw) {
        Value sel = GetValue(ctx, frame, sw->selector());
        int64_t sel_val = AsInt(sel);
        bool found = false;
        IRBlock default_block{};
        for (auto sc : sw->cases()) {
          if (sc.is_default()) {
            default_block = sc.target_block();
            continue;
          }
          if (sel_val >= sc.low() && sel_val <= sc.high()) {
            frame.current_block = sc.target_block();
            found = true;
            break;
          }
        }
        if (!found) {
          if (EntityId(default_block.id()).Pack()) {
            frame.current_block = default_block;
          } else {
            return {StepStatus::ERROR};
          }
        }
        return {StepStatus::CONTINUE};
      }
      return {StepStatus::ERROR};
    }

    // All other terminators: unconditional branch.
    {
      auto br = BranchInst::from(inst);
      if (br) {
        frame.current_block = br->target_block();
        return {StepStatus::CONTINUE};
      }
    }
    return {StepStatus::ERROR};
  }

  // Block ended without terminator.
  return {StepStatus::ERROR};
}

}  // namespace mx::ir::interpret
