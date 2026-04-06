// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/SwitchCase.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FieldDecl.h>

#include "Impl.h"
#include "../Fragment.h"
#include "../EntityProvider.h"

#include <cassert>

namespace mx {
namespace {

using Pool = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using IntPool = capnp::List<int64_t, capnp::Kind::PRIMITIVE>::Reader;

Pool GetPool(const IRInstructionImpl &impl) {
  return impl.frag->reader.getIrEntityPool();
}

IntPool GetIntPool(const IRInstructionImpl &impl) {
  return impl.frag->reader.getIrIntPool();
}

bool HasResultType(ir::OpCode op) {
  return !ir::IsTerminator(op) &&
         op != ir::OpCode::STORE &&
         op != ir::OpCode::VA_START &&
         op != ir::OpCode::VA_END &&
         op != ir::OpCode::VA_COPY &&
         op != ir::OpCode::VA_PACK &&
         op != ir::OpCode::UNKNOWN;
}

// Pool position of result type (only valid if HasResultType).
uint32_t TypePos(const rpc::ir::Instruction::Reader &r) {
  return r.getEntityOffset() + 2;
}

// Pool position of first operand.
uint32_t OpBase(const rpc::ir::Instruction::Reader &r) {
  auto op = static_cast<ir::OpCode>(r.getOpcode());
  return r.getEntityOffset() + 2 + (HasResultType(op) ? 1 : 0);
}

// Pool position of first extra (after operands).
uint32_t ExtraBase(const rpc::ir::Instruction::Reader &r) {
  return OpBase(r) + r.getNumOperands();
}

IRInstruction MakeInst(const IRInstructionImpl &parent, uint64_t eid) {
  auto vid = EntityId(eid).Unpack();
  if (auto *iid = std::get_if<IRInstructionId>(&vid)) {
    return IRInstruction(std::make_shared<IRInstructionImpl>(
        parent.frag, iid->offset, parent.fragment_id));
  }
  return {};
}

IRBlock MakeBlock(const IRInstructionImpl &parent, uint64_t eid) {
  auto vid = EntityId(eid).Unpack();
  if (auto *bid = std::get_if<IRBlockId>(&vid)) {
    return IRBlock(std::make_shared<IRBlockImpl>(
        parent.frag, bid->offset, parent.fragment_id));
  }
  return {};
}

IRObject MakeObj(const IRInstructionImpl &parent, uint64_t eid) {
  auto vid = EntityId(eid).Unpack();
  if (auto *oid = std::get_if<IRObjectId>(&vid)) {
    return IRObject(std::make_shared<IRObjectImpl>(
        parent.frag, oid->offset, parent.fragment_id));
  }
  return {};
}

Type ResolveType(const IRInstructionImpl &impl, uint64_t eid) {
  assert(eid != kInvalidEntityId && "Missing type entity ID");
  auto ptr = impl.frag->ep->TypeFor(impl.frag->ep, eid);
  assert(ptr && "Failed to resolve type entity ID");
  return Type(std::move(ptr));
}

// Optional version for CallInst result type (void calls).
std::optional<Type> MaybeResolveType(const IRInstructionImpl &impl, uint64_t eid) {
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl.frag->ep->TypeFor(impl.frag->ep, eid)) {
    return Type(std::move(ptr));
  }
  return std::nullopt;
}

std::optional<FunctionDecl> ResolveFunc(const IRInstructionImpl &impl, uint64_t eid) {
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl.frag->ep->DeclFor(impl.frag->ep, eid)) {
    return FunctionDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

FieldDecl ResolveField(const IRInstructionImpl &impl, uint64_t eid) {
  assert(eid != kInvalidEntityId && "Missing field entity ID");
  auto ptr = impl.frag->ep->DeclFor(impl.frag->ep, eid);
  assert(ptr && "Failed to resolve field entity ID");
  auto fd = FieldDecl::from(Decl(std::move(ptr)));
  assert(fd && "Entity is not a FieldDecl");
  return *fd;
}

}  // namespace

// ---- from() methods ----

#define IMPL_FROM_SINGLE(Class, opcode_val) \
  std::optional<Class> Class::from(const IRInstruction &inst) { \
    if (inst.opcode() == ir::OpCode::opcode_val) \
      return Class(inst.impl_ptr()); \
    return std::nullopt; \
  }

#define IMPL_FROM_RANGE(Class, first, last) \
  std::optional<Class> Class::from(const IRInstruction &inst) { \
    auto op = inst.opcode(); \
    if (op >= ir::OpCode::first && op <= ir::OpCode::last) \
      return Class(inst.impl_ptr()); \
    return std::nullopt; \
  }

IMPL_FROM_SINGLE(ConstIntInst, CONST_INT)
IMPL_FROM_SINGLE(ConstFloatInst, CONST_FLOAT)
IMPL_FROM_SINGLE(ConstNullInst, CONST_NULL)
IMPL_FROM_SINGLE(AllocaInst, ALLOCA)
IMPL_FROM_SINGLE(LoadInst, LOAD)
IMPL_FROM_SINGLE(StoreInst, STORE)
IMPL_FROM_SINGLE(AddressOfInst, ADDRESS_OF)
IMPL_FROM_SINGLE(GEPFieldInst, GEP_FIELD)
IMPL_FROM_SINGLE(PtrAddInst, PTR_ADD)
IMPL_FROM_SINGLE(SizeOfInst, SIZE_OF)
IMPL_FROM_SINGLE(CallInst, CALL)
IMPL_FROM_SINGLE(IncDecInst, INC_DEC)
IMPL_FROM_SINGLE(CompoundAssignInst, COMPOUND_ASSIGN)
IMPL_FROM_SINGLE(SelectInst, SELECT)
IMPL_FROM_SINGLE(CopyInst, COPY)
IMPL_FROM_SINGLE(InitListInst, INIT_LIST)
IMPL_FROM_SINGLE(VAStartInst, VA_START)
IMPL_FROM_SINGLE(VAEndInst, VA_END)
IMPL_FROM_SINGLE(VACopyInst, VA_COPY)
IMPL_FROM_SINGLE(VAArgInst, VA_ARG)
IMPL_FROM_SINGLE(VAPackInst, VA_PACK)

IMPL_FROM_SINGLE(RetInst, RET)
IMPL_FROM_SINGLE(CondBranchInst, COND_BRANCH)
IMPL_FROM_SINGLE(SwitchInst, SWITCH)
IMPL_FROM_SINGLE(UnreachableInst, UNREACHABLE)
IMPL_FROM_SINGLE(UnknownInst, UNKNOWN)

IMPL_FROM_RANGE(BinaryInst, ADD, PTR_DIFF)
IMPL_FROM_RANGE(ComparisonInst, CMP_EQ, CMP_GE)
IMPL_FROM_RANGE(UnaryInst, NEG, LOGICAL_NOT)
IMPL_FROM_RANGE(CastInst, CAST_SEXT, CAST_FP_CAST)

std::optional<BranchInst> BranchInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::GOTO || op == ir::OpCode::IMPLICIT_GOTO ||
      op == ir::OpCode::BREAK || op == ir::OpCode::CONTINUE ||
      op == ir::OpCode::FALLTHROUGH || op == ir::OpCode::IMPLICIT_FALLTHROUGH)
    return BranchInst(inst.impl_ptr());
  return std::nullopt;
}

#undef IMPL_FROM_SINGLE
#undef IMPL_FROM_RANGE

// ---- ConstIntInst ----

int64_t ConstIntInst::signed_value(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset()];
}

uint64_t ConstIntInst::unsigned_value(void) const {
  return static_cast<uint64_t>(GetIntPool(*impl)[impl->reader().getConstOffset() + 1]);
}

uint8_t ConstIntInst::width(void) const {
  return impl->reader().getConstWidth();
}

Type ConstIntInst::type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ConstFloatInst ----

double ConstFloatInst::value(void) const {
  int64_t bits = GetIntPool(*impl)[impl->reader().getConstOffset()];
  double result;
  memcpy(&result, &bits, sizeof(result));
  return result;
}

uint8_t ConstFloatInst::width(void) const {
  return impl->reader().getConstWidth();
}

Type ConstFloatInst::type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ConstNullInst ----

Type ConstNullInst::type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- AllocaInst ----

Type AllocaInst::allocated_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

IRObject AllocaInst::object(void) const {
  return MakeObj(*impl, GetPool(*impl)[ExtraBase(impl->reader())]);
}

// ---- LoadInst ----

IRInstruction LoadInst::address(void) const {
  return nth_operand(0);
}

Type LoadInst::loaded_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- StoreInst ----

IRInstruction StoreInst::address(void) const {
  return nth_operand(0);
}

IRInstruction StoreInst::stored_value(void) const {
  return nth_operand(1);
}

// ---- AddressOfInst ----

Type AddressOfInst::type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

IRObject AddressOfInst::object(void) const {
  return MakeObj(*impl, GetPool(*impl)[ExtraBase(impl->reader())]);
}

// ---- GEPFieldInst ----

IRInstruction GEPFieldInst::base(void) const {
  return nth_operand(0);
}

Type GEPFieldInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

FieldDecl GEPFieldInst::field(void) const {
  auto pool = GetPool(*impl);
  return ResolveField(*impl, pool[ExtraBase(impl->reader())]);
}

int64_t GEPFieldInst::byte_offset(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset()];
}

// ---- PtrAddInst ----

IRInstruction PtrAddInst::base(void) const {
  return nth_operand(0);
}

IRInstruction PtrAddInst::index(void) const {
  return nth_operand(1);
}

Type PtrAddInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

Type PtrAddInst::element_type(void) const {
  auto pool = GetPool(*impl);
  return ResolveType(*impl, pool[ExtraBase(impl->reader())]);
}

int64_t PtrAddInst::element_size(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset()];
}

// ---- BinaryInst ----

IRInstruction BinaryInst::lhs(void) const { return nth_operand(0); }
IRInstruction BinaryInst::rhs(void) const { return nth_operand(1); }
Type BinaryInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ComparisonInst ----

IRInstruction ComparisonInst::lhs(void) const { return nth_operand(0); }
IRInstruction ComparisonInst::rhs(void) const { return nth_operand(1); }
Type ComparisonInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- UnaryInst ----

IRInstruction UnaryInst::operand(void) const { return nth_operand(0); }
Type UnaryInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- CastInst ----

IRInstruction CastInst::operand(void) const { return nth_operand(0); }
Type CastInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- SizeOfInst ----

Type SizeOfInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

Type SizeOfInst::measured_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[ExtraBase(impl->reader())]);
}

int64_t SizeOfInst::static_size(void) const {
  // sizeOf stores the static size in the int pool via EmitInstructionConsts
  // but only if it was computed. Check if constOffset is valid.
  return 0;  // TODO: store in int pool
}

// ---- CallInst ----

std::optional<Type> CallInst::result_type(void) const {
  return MaybeResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

std::optional<FunctionDecl> CallInst::target(void) const {
  auto pool = GetPool(*impl);
  return ResolveFunc(*impl, pool[ExtraBase(impl->reader())]);
}

bool CallInst::is_indirect(void) const {
  auto pool = GetPool(*impl);
  auto eid = pool[ExtraBase(impl->reader())];
  return eid == kInvalidEntityId;
}

gap::generator<IRInstruction> CallInst::arguments(void) const & {
  // For direct calls: all operands are arguments.
  // For indirect calls: operand 0 is the callee pointer, rest are args.
  bool indirect = is_indirect();
  unsigned start = indirect ? 1 : 0;
  for (unsigned i = start; i < num_operands(); ++i) {
    co_yield nth_operand(i);
  }
}

// ---- IncDecInst ----

IRInstruction IncDecInst::address(void) const { return nth_operand(0); }

Type IncDecInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

bool IncDecInst::is_increment(void) const {
  return (impl->reader().getFlags() & 0x1) != 0;
}

bool IncDecInst::is_prefix(void) const {
  return (impl->reader().getFlags() & 0x2) != 0;
}

int64_t IncDecInst::pointer_element_size(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset()];
}

// ---- CompoundAssignInst ----

IRInstruction CompoundAssignInst::address(void) const { return nth_operand(0); }
IRInstruction CompoundAssignInst::value(void) const { return nth_operand(1); }

Type CompoundAssignInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

ir::OpCode CompoundAssignInst::underlying_op(void) const {
  return static_cast<ir::OpCode>(
      GetIntPool(*impl)[impl->reader().getConstOffset()]);
}

// ---- SelectInst ----

IRInstruction SelectInst::condition(void) const { return nth_operand(0); }
IRInstruction SelectInst::true_value(void) const { return nth_operand(1); }
IRInstruction SelectInst::false_value(void) const { return nth_operand(2); }

Type SelectInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- CopyInst ----

IRInstruction CopyInst::source(void) const { return nth_operand(0); }
Type CopyInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- InitListInst ----

gap::generator<IRInstruction> InitListInst::elements(void) const & {
  for (unsigned i = 0; i < num_operands(); ++i) {
    co_yield nth_operand(i);
  }
}

Type InitListInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- RetInst ----

std::optional<IRInstruction> RetInst::return_value(void) const {
  if (num_operands() > 0) return nth_operand(0);
  return std::nullopt;
}

// ---- BranchInst ----

IRBlock BranchInst::target_block(void) const {
  auto pool = GetPool(*impl);
  // For branch terminators, the target block is the first extra.
  return MakeBlock(*impl, pool[ExtraBase(impl->reader())]);
}

// ---- CondBranchInst ----

IRInstruction CondBranchInst::condition(void) const { return nth_operand(0); }

IRBlock CondBranchInst::true_block(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader());
  return MakeBlock(*impl, pool[base]);
}

IRBlock CondBranchInst::false_block(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader());
  return MakeBlock(*impl, pool[base + 1]);
}

// ---- SwitchInst ----

IRInstruction SwitchInst::selector(void) const { return nth_operand(0); }

// ---- VA* instructions ----

IRInstruction VAStartInst::va_list_operand(void) const { return nth_operand(0); }
IRInstruction VAEndInst::va_list_operand(void) const { return nth_operand(0); }
IRInstruction VACopyInst::dest(void) const { return nth_operand(0); }
IRInstruction VACopyInst::src(void) const { return nth_operand(1); }
IRInstruction VAArgInst::va_list_operand(void) const { return nth_operand(0); }

Type VAArgInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

gap::generator<IRInstruction> VAPackInst::arguments(void) const & {
  for (unsigned i = 0; i < num_operands(); ++i) {
    co_yield nth_operand(i);
  }
}

// ---- SwitchInst ----

unsigned SwitchInst::num_cases(void) const {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r);
  // Extras: [caseType, case0_eid, case1_eid, ...]
  // Count = total extras - 1 (for caseType).
  // But we don't know total extras directly. Use the switch_cases count
  // from the SwitchCaseIR data that was serialized.
  // Actually, we can count by checking how many pool entries after caseType
  // are IRSwitchCaseId.
  unsigned count = 0;
  for (uint32_t i = extra_base + 1; ; ++i) {
    if (i >= pool.size()) break;
    auto vid = EntityId(pool[i]).Unpack();
    if (!std::holds_alternative<IRSwitchCaseId>(vid)) break;
    ++count;
  }
  return count;
}

std::optional<Type> SwitchInst::case_type(void) const {
  auto pool = GetPool(*impl);
  return MaybeResolveType(*impl, pool[ExtraBase(impl->reader())]);
}

gap::generator<IRSwitchCase> SwitchInst::cases(void) const & {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r);

  // Extras: [caseType, case0_eid, case1_eid, ...]
  for (uint32_t i = extra_base + 1; ; ++i) {
    if (i >= pool.size()) break;
    auto vid = EntityId(pool[i]).Unpack();
    if (auto *scid = std::get_if<IRSwitchCaseId>(&vid)) {
      co_yield IRSwitchCase(std::make_shared<IRSwitchCaseImpl>(
          impl->frag, scid->offset, impl->fragment_id));
    } else {
      break;
    }
  }
}

}  // namespace mx
