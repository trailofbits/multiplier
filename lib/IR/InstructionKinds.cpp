// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/Structure.h>
#include <multiplier/AST/FunctionDecl.h>
#include <multiplier/AST/FieldDecl.h>
#include <multiplier/AST/VarDecl.h>

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

// NOTE: For MEMORY instructions, this returns true. Loads have a result type
// at position 2; stores/bulk ops do not (the serializer omits it).
// The MemoryInst read-side code handles this via the sub-opcode.
bool HasResultType(ir::OpCode op) {
  return !ir::IsTerminator(op) &&
         op != ir::OpCode::VA_START &&
         op != ir::OpCode::VA_END &&
         op != ir::OpCode::VA_COPY &&
         op != ir::OpCode::ENTER_SCOPE &&
         op != ir::OpCode::EXIT_SCOPE &&
         op != ir::OpCode::UNKNOWN;
}

// For MEMORY instructions, check the sub-opcode to determine if there's a
// result type. Stores don't have a result type; bulk/string ops do.
bool HasResultTypeForInst(const rpc::ir::Instruction::Reader &r,
                          const IntPool &int_pool) {
  auto op = static_cast<ir::OpCode>(r.getOpcode());
  if (!HasResultType(op)) return false;
  if (op == ir::OpCode::MEMORY) {
    auto mop = static_cast<ir::MemOp>(int_pool[r.getConstOffset()]);
    // Direct stores have no result type; everything else does.
    if (ir::IsDirectLoadStore(mop)) return ir::IsAnyLoad(mop);
    return true;  // bulk/string ops always have a result type
  }
  return true;
}

// Pool position of result type (only valid if HasResultType).
uint32_t TypePos(const rpc::ir::Instruction::Reader &r) {
  return r.getEntityOffset() + 2;
}

// Pool position of first operand.
uint32_t OpBase(const rpc::ir::Instruction::Reader &r,
                const IntPool &int_pool) {
  auto op = static_cast<ir::OpCode>(r.getOpcode());
  bool has_type = HasResultType(op);
  if (has_type && op == ir::OpCode::MEMORY) {
    auto mop = static_cast<ir::MemOp>(int_pool[r.getConstOffset()]);
    if (ir::IsDirectLoadStore(mop) && ir::IsAnyStore(mop)) has_type = false;
  }
  return r.getEntityOffset() + 2 + (has_type ? 1 : 0);
}

// Pool position of first extra (after operands).
uint32_t ExtraBase(const rpc::ir::Instruction::Reader &r,
                   const IntPool &int_pool) {
  return OpBase(r, int_pool) + r.getNumOperands();
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

IMPL_FROM_SINGLE(ConstInst, CONST)
IMPL_FROM_SINGLE(AllocaInst, ALLOCA)
IMPL_FROM_SINGLE(MemoryInst, MEMORY)
std::optional<GEPFieldInst> GEPFieldInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::GEP_FIELD_32 || op == ir::OpCode::GEP_FIELD_64)
    return GEPFieldInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<PtrAddInst> PtrAddInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::PTR_ADD_32 || op == ir::OpCode::PTR_ADD_64)
    return PtrAddInst(inst.impl_ptr());
  return std::nullopt;
}
IMPL_FROM_SINGLE(ReadModifyWriteInst, READ_MODIFY_WRITE)
IMPL_FROM_SINGLE(CallInst, CALL)
IMPL_FROM_SINGLE(LastValueInst, LAST_VALUE)
IMPL_FROM_SINGLE(SelectInst, SELECT)
IMPL_FROM_SINGLE(VAStartInst, VA_START)
IMPL_FROM_SINGLE(VAEndInst, VA_END)
IMPL_FROM_SINGLE(VACopyInst, VA_COPY)
std::optional<ParamPtrInst> ParamPtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::PARAM_PTR_32 || op == ir::OpCode::PARAM_PTR_64)
    return ParamPtrInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<GlobalPtrInst> GlobalPtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::GLOBAL_PTR_32 || op == ir::OpCode::GLOBAL_PTR_64)
    return GlobalPtrInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<ThreadLocalPtrInst> ThreadLocalPtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::THREAD_LOCAL_PTR_32 || op == ir::OpCode::THREAD_LOCAL_PTR_64)
    return ThreadLocalPtrInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<FuncPtrInst> FuncPtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::FUNC_PTR_32 || op == ir::OpCode::FUNC_PTR_64)
    return FuncPtrInst(inst.impl_ptr());
  return std::nullopt;
}
// MultimemInst removed: merged into MemoryInst.
std::optional<BitwiseOpInst> BitwiseOpInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op >= ir::OpCode::BITWISE_8 && op <= ir::OpCode::BITWISE_64)
    return BitwiseOpInst(inst.impl_ptr());
  return std::nullopt;
}
IMPL_FROM_SINGLE(FloatOpInst, FLOAT)
std::optional<FramePtrInst> FramePtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::FRAME_PTR_32 || op == ir::OpCode::FRAME_PTR_64)
    return FramePtrInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<ReturnAddressInst> ReturnAddressInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::RETURN_ADDRESS_32 || op == ir::OpCode::RETURN_ADDRESS_64)
    return ReturnAddressInst(inst.impl_ptr());
  return std::nullopt;
}
IMPL_FROM_SINGLE(EnterScopeInst, ENTER_SCOPE)
IMPL_FROM_SINGLE(ExitScopeInst, EXIT_SCOPE)
IMPL_FROM_SINGLE(UndefinedInst, UNDEFINED)
std::optional<ReturnPtrInst> ReturnPtrInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::RETURN_PTR_32 || op == ir::OpCode::RETURN_PTR_64)
    return ReturnPtrInst(inst.impl_ptr());
  return std::nullopt;
}

// ConsumeVAParamInst: matches MEMORY with CONSUME_VA_PARAM sub-opcode.
std::optional<ConsumeVAParamInst> ConsumeVAParamInst::from(const IRInstruction &inst) {
  if (inst.opcode() != ir::OpCode::MEMORY) return std::nullopt;
  // Check sub-opcode from int pool.
  auto &i = *inst.impl_ptr();
  auto int_pool = GetIntPool(i);
  auto r = i.reader();
  auto mop = static_cast<ir::MemOp>(int_pool[r.getConstOffset()]);
  if (mop != ir::MemOp::CONSUME_VA_PARAM) return std::nullopt;
  return ConsumeVAParamInst(inst.impl_ptr());
}

IMPL_FROM_SINGLE(RetInst, RET)
IMPL_FROM_SINGLE(CondBranchInst, COND_BRANCH)
IMPL_FROM_SINGLE(SwitchInst, SWITCH)
std::optional<UnreachableInst> UnreachableInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::UNREACHABLE || op == ir::OpCode::IMPLICIT_UNREACHABLE)
    return UnreachableInst(inst.impl_ptr());
  return std::nullopt;
}
IMPL_FROM_SINGLE(UnknownInst, UNKNOWN)

std::optional<BinaryInst> BinaryInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (ir::IsBinaryOp(op))
    return BinaryInst(inst.impl_ptr());
  return std::nullopt;
}
std::optional<ComparisonInst> ComparisonInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (ir::IsComparison(op))
    return ComparisonInst(inst.impl_ptr());
  return std::nullopt;
}
std::optional<PtrDiffInst> PtrDiffInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (op == ir::OpCode::PTR_DIFF_32 || op == ir::OpCode::PTR_DIFF_64)
    return PtrDiffInst(inst.impl_ptr());
  return std::nullopt;
}
std::optional<UnaryInst> UnaryInst::from(const IRInstruction &inst) {
  auto op = inst.opcode();
  if (ir::IsUnaryOp(op))
    return UnaryInst(inst.impl_ptr());
  return std::nullopt;
}
IMPL_FROM_SINGLE(CastInst, CAST)

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

// ---- ConstInst ----

ir::ConstOp ConstInst::sub_opcode(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::ConstOp>(int_pool[r.getConstOffset()]);
}

int64_t ConstInst::signed_value(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset() + 1];
}

uint64_t ConstInst::unsigned_value(void) const {
  return static_cast<uint64_t>(GetIntPool(*impl)[impl->reader().getConstOffset() + 2]);
}

double ConstInst::float_value(void) const {
  int64_t bits = GetIntPool(*impl)[impl->reader().getConstOffset() + 1];
  double result;
  memcpy(&result, &bits, sizeof(result));
  return result;
}

Type ConstInst::type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- AllocaInst and derived kinds ----

ir::AllocaKind AllocaInst::alloca_kind(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::AllocaKind>(int_pool[r.getConstOffset()]);
}

// Alloca sub-kind from() implementations.
static ir::AllocaKind GetAllocaKind(const IRInstruction &inst) {
  if (inst.opcode() != ir::OpCode::ALLOCA)
    return static_cast<ir::AllocaKind>(255);  // invalid sentinel
  auto &i = *inst.impl_ptr();
  auto int_pool = GetIntPool(i);
  auto r = i.reader();
  return static_cast<ir::AllocaKind>(int_pool[r.getConstOffset()]);
}

std::optional<LocalAllocaInst> LocalAllocaInst::from(const IRInstruction &inst) {
  if (GetAllocaKind(inst) == ir::AllocaKind::LOCAL)
    return LocalAllocaInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<ArgAllocaInst> ArgAllocaInst::from(const IRInstruction &inst) {
  if (GetAllocaKind(inst) == ir::AllocaKind::ARG)
    return ArgAllocaInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<ReturnAllocaInst> ReturnAllocaInst::from(const IRInstruction &inst) {
  if (GetAllocaKind(inst) == ir::AllocaKind::RETURN)
    return ReturnAllocaInst(inst.impl_ptr());
  return std::nullopt;
}

std::optional<DynamicAllocaInst> DynamicAllocaInst::from(const IRInstruction &inst) {
  if (GetAllocaKind(inst) == ir::AllocaKind::DYNAMIC)
    return DynamicAllocaInst(inst.impl_ptr());
  return std::nullopt;
}

Type AllocaInst::allocated_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

IRObject AllocaInst::object(void) const {
  return MakeObj(*impl, GetPool(*impl)[ExtraBase(impl->reader(), GetIntPool(*impl))]);
}

uint32_t AllocaInst::size_bytes(void) const {
  return object().size_bytes();
}

uint32_t AllocaInst::align_bytes(void) const {
  return object().align_bytes();
}

// ---- MemoryInst ----

ir::MemOp MemoryInst::sub_opcode(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::MemOp>(int_pool[r.getConstOffset()]);
}

IRInstruction MemoryInst::address(void) const {
  return nth_operand(0);
}

IRInstruction MemoryInst::stored_value(void) const {
  return nth_operand(1);
}

Type MemoryInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

uint32_t MemoryInst::bit_offset(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  // int_pool layout for MEMORY: [sub_opcode, bit_offset, bit_width]
  return static_cast<uint32_t>(int_pool[r.getConstOffset() + 1]);
}

uint32_t MemoryInst::bit_width(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<uint32_t>(int_pool[r.getConstOffset() + 2]);
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
  return ResolveField(*impl, pool[ExtraBase(impl->reader(), GetIntPool(*impl))]);
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
  return ResolveType(*impl, pool[ExtraBase(impl->reader(), GetIntPool(*impl))]);
}

int64_t PtrAddInst::element_size(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset()];
}

// ---- PtrDiffInst ----

IRInstruction PtrDiffInst::lhs(void) const { return nth_operand(0); }
IRInstruction PtrDiffInst::rhs(void) const { return nth_operand(1); }

Type PtrDiffInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

int64_t PtrDiffInst::element_size(void) const {
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

ir::CastOp CastInst::sub_opcode(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::CastOp>(int_pool[r.getConstOffset()]);
}

IRInstruction CastInst::operand(void) const { return nth_operand(0); }
Type CastInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ReadModifyWriteInst ----

IRInstruction ReadModifyWriteInst::address(void) const { return nth_operand(0); }

ir::OpCode ReadModifyWriteInst::underlying_op(void) const {
  return static_cast<ir::OpCode>(
      GetIntPool(*impl)[impl->reader().getConstOffset()]);
}

int64_t ReadModifyWriteInst::element_size(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset() + 1];
}

bool ReadModifyWriteInst::is_big_endian(void) const {
  return GetIntPool(*impl)[impl->reader().getConstOffset() + 2] != 0;
}

bool ReadModifyWriteInst::is_atomic(void) const {
  auto op = underlying_op();
  return op >= ir::OpCode::ATOMIC_ADD_8 && op <= ir::OpCode::ATOMIC_EXCHANGE_64;
}

bool ReadModifyWriteInst::returns_new_value(void) const {
  return (impl->reader().getFlags() & 1) != 0;
}

Type ReadModifyWriteInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

gap::generator<IRInstruction> ReadModifyWriteInst::rhs_operands(void) const & {
  for (unsigned i = 1; i < num_operands(); ++i) {
    co_yield nth_operand(i);
  }
}

// ---- CallInst ----

std::optional<Type> CallInst::result_type(void) const {
  return MaybeResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

std::optional<FunctionDecl> CallInst::target(void) const {
  auto pool = GetPool(*impl);
  return ResolveFunc(*impl, pool[ExtraBase(impl->reader(), GetIntPool(*impl))]);
}

bool CallInst::is_indirect(void) const {
  auto pool = GetPool(*impl);
  auto eid = pool[ExtraBase(impl->reader(), GetIntPool(*impl))];
  return eid == kInvalidEntityId;
}

bool CallInst::has_return_value(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader(), GetIntPool(*impl));
  auto eid = pool[base + 1];  // extras[1] = return alloca entity ID
  return eid != kInvalidEntityId;
}

std::optional<AllocaInst> CallInst::return_alloca(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader(), GetIntPool(*impl));
  auto eid = pool[base + 1];  // extras[1] = return alloca entity ID
  if (eid == kInvalidEntityId) return std::nullopt;
  auto inst = MakeInst(*impl, eid);
  return AllocaInst::from(inst);
}

gap::generator<IRInstruction> CallInst::arguments(void) const & {
  // For direct calls: all operands are ARG allocas.
  // For indirect calls: operand 0 is the callee pointer, rest are ARG allocas.
  bool indirect = is_indirect();
  unsigned start = indirect ? 1 : 0;
  for (unsigned i = start; i < num_operands(); ++i) {
    co_yield nth_operand(i);
  }
}

// ---- SelectInst ----

// ---- LastValueInst ----

IRInstruction LastValueInst::last(void) const {
  return nth_operand(num_operands() - 1);
}

Type LastValueInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- SelectInst ----

IRInstruction SelectInst::condition(void) const { return nth_operand(0); }
IRInstruction SelectInst::true_value(void) const { return nth_operand(1); }
IRInstruction SelectInst::false_value(void) const { return nth_operand(2); }

Type SelectInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// CopyInst removed: use CastInst with CastOp::IDENTITY instead.

// RetInst is a pure terminator: its return value (if any) lives in
// the slot pointed to by the preceding RETURN_PTR + MEMORY/STORE,
// not as an SSA operand on the RET itself.

// ---- BranchInst ----

IRBlock BranchInst::target_block(void) const {
  auto pool = GetPool(*impl);
  // For branch terminators, the target block is the first extra.
  return MakeBlock(*impl, pool[ExtraBase(impl->reader(), GetIntPool(*impl))]);
}

// ---- CondBranchInst ----

IRInstruction CondBranchInst::condition(void) const { return nth_operand(0); }

IRBlock CondBranchInst::true_block(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader(), GetIntPool(*impl));
  return MakeBlock(*impl, pool[base]);
}

IRBlock CondBranchInst::false_block(void) const {
  auto pool = GetPool(*impl);
  auto base = ExtraBase(impl->reader(), GetIntPool(*impl));
  return MakeBlock(*impl, pool[base + 1]);
}

// ---- SwitchInst ----

IRInstruction SwitchInst::selector(void) const { return nth_operand(0); }

// ---- VA* instructions ----

IRInstruction VAStartInst::va_list_operand(void) const { return nth_operand(0); }
IRInstruction VAEndInst::va_list_operand(void) const { return nth_operand(0); }
IRInstruction VACopyInst::dest(void) const { return nth_operand(0); }
IRInstruction VACopyInst::src(void) const { return nth_operand(1); }
// ---- ConsumeVAParamInst ----

IRInstruction ConsumeVAParamInst::va_list_operand(void) const { return nth_operand(0); }

Type ConsumeVAParamInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ParamPtrInst ----

uint32_t ParamPtrInst::parameter_index(void) const {
  auto r = impl->reader();
  auto int_pool = GetIntPool(*impl);
  return static_cast<uint32_t>(int_pool[r.getConstOffset()]);
}

Type ParamPtrInst::parameter_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- GlobalPtrInst / ThreadLocalPtrInst / FuncPtrInst ----

std::optional<VarDecl> GlobalPtrInst::variable(void) const {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, GetIntPool(*impl));
  auto eid = pool[extra_base];
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return VarDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

std::optional<VarDecl> ThreadLocalPtrInst::variable(void) const {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, GetIntPool(*impl));
  auto eid = pool[extra_base];
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return VarDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

std::optional<FunctionDecl> FuncPtrInst::function(void) const {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, GetIntPool(*impl));
  auto eid = pool[extra_base];
  if (eid == kInvalidEntityId) return std::nullopt;
  if (auto ptr = impl->frag->ep->DeclFor(impl->frag->ep, eid)) {
    return FunctionDecl::from(Decl(std::move(ptr)));
  }
  return std::nullopt;
}

// MultimemInst removed: merged into MemoryInst.

// ---- BitwiseOpInst ----

ir::BitwiseOp BitwiseOpInst::sub_opcode(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::BitwiseOp>(int_pool[r.getConstOffset()]);
}

Type BitwiseOpInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- FloatOpInst ----

ir::FloatOp FloatOpInst::sub_opcode(void) const {
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  return static_cast<ir::FloatOp>(int_pool[r.getConstOffset()]);
}

Type FloatOpInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- DynamicAllocaInst ----

// ---- DynamicAllocaInst ----

IRInstruction DynamicAllocaInst::size(void) const { return nth_operand(0); }

// ---- FramePtrInst ----

IRInstruction FramePtrInst::level(void) const { return nth_operand(0); }
Type FramePtrInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ReturnAddressInst ----

IRInstruction ReturnAddressInst::level(void) const { return nth_operand(0); }
Type ReturnAddressInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- ReturnPtrInst ----

Type ReturnPtrInst::return_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- EnterScopeInst / ExitScopeInst ----

IRStructure EnterScopeInst::scope(void) const {
  auto pool = GetPool(*impl);
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, int_pool);
  auto eid = pool[extra_base];
  auto vid = EntityId(eid).Unpack();
  if (auto *sid = std::get_if<IRStructureId>(&vid)) {
    return IRStructure(std::make_shared<IRStructureImpl>(
        impl->frag, sid->offset, impl->fragment_id));
  }
  return {};
}

IRStructure ExitScopeInst::scope(void) const {
  auto pool = GetPool(*impl);
  auto int_pool = GetIntPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, int_pool);
  auto eid = pool[extra_base];
  auto vid = EntityId(eid).Unpack();
  if (auto *sid = std::get_if<IRStructureId>(&vid)) {
    return IRStructure(std::make_shared<IRStructureImpl>(
        impl->frag, sid->offset, impl->fragment_id));
  }
  return {};
}

// ---- UndefinedInst ----

Type UndefinedInst::result_type(void) const {
  return ResolveType(*impl, GetPool(*impl)[TypePos(impl->reader())]);
}

// ---- SwitchInst ----

unsigned SwitchInst::num_cases(void) const {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, GetIntPool(*impl));
  // Extras: [caseType, case0_eid, case1_eid, ...]
  // Count by checking how many pool entries after caseType are
  // IRStructureId with SWITCH_CASE kind.
  unsigned count = 0;
  for (uint32_t i = extra_base + 1; ; ++i) {
    if (i >= pool.size()) break;
    auto vid = EntityId(pool[i]).Unpack();
    if (auto *sid = std::get_if<IRStructureId>(&vid)) {
      if (sid->structure_kind == ir::StructureKind::SWITCH_CASE) {
        ++count;
        continue;
      }
    }
    break;
  }
  return count;
}

std::optional<Type> SwitchInst::case_type(void) const {
  auto pool = GetPool(*impl);
  return MaybeResolveType(*impl, pool[ExtraBase(impl->reader(), GetIntPool(*impl))]);
}

gap::generator<IRSwitchCaseStructure> SwitchInst::cases(void) const & {
  auto pool = GetPool(*impl);
  auto r = impl->reader();
  auto extra_base = ExtraBase(r, GetIntPool(*impl));

  // Extras: [caseType, case0_eid, case1_eid, ...]
  for (uint32_t i = extra_base + 1; ; ++i) {
    if (i >= pool.size()) break;
    auto vid = EntityId(pool[i]).Unpack();
    if (auto *sid = std::get_if<IRStructureId>(&vid)) {
      if (sid->structure_kind == ir::StructureKind::SWITCH_CASE) {
        co_yield IRSwitchCaseStructure(std::make_shared<IRStructureImpl>(
            impl->frag, sid->offset, impl->fragment_id));
        continue;
      }
    }
    break;
  }
}

}  // namespace mx
