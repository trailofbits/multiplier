// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/LLVM/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>

namespace mx::ir::llvm {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsLLVMIRAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
}

std::optional<CConvAttr> CConvAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_C_CONV) {
    return reinterpret_cast<const CConvAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::CConvAttr CConvAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::CConvAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ComdatAttr> ComdatAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_COMDAT) {
    return reinterpret_cast<const ComdatAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::ComdatAttr ComdatAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::ComdatAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LinkageAttr> LinkageAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LINKAGE) {
    return reinterpret_cast<const LinkageAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LinkageAttr LinkageAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LinkageAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<FramePointerKindAttr> FramePointerKindAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_FRAME_POINTER_KIND) {
    return reinterpret_cast<const FramePointerKindAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::FramePointerKindAttr FramePointerKindAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FramePointerKindAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopVectorizeAttr> LoopVectorizeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_VECTORIZE) {
    return reinterpret_cast<const LoopVectorizeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopVectorizeAttr LoopVectorizeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopVectorizeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopInterleaveAttr> LoopInterleaveAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_INTERLEAVE) {
    return reinterpret_cast<const LoopInterleaveAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopInterleaveAttr LoopInterleaveAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopInterleaveAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopUnrollAttr> LoopUnrollAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_UNROLL) {
    return reinterpret_cast<const LoopUnrollAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopUnrollAttr LoopUnrollAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopUnrollAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopUnrollAndJamAttr> LoopUnrollAndJamAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_UNROLL_AND_JAM) {
    return reinterpret_cast<const LoopUnrollAndJamAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopUnrollAndJamAttr LoopUnrollAndJamAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopUnrollAndJamAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopLICMAttr> LoopLICMAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_LICM) {
    return reinterpret_cast<const LoopLICMAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopLICMAttr LoopLICMAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopLICMAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopDistributeAttr> LoopDistributeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_DISTRIBUTE) {
    return reinterpret_cast<const LoopDistributeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopDistributeAttr LoopDistributeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopDistributeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopPipelineAttr> LoopPipelineAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_PIPELINE) {
    return reinterpret_cast<const LoopPipelineAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopPipelineAttr LoopPipelineAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopPipelineAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopPeeledAttr> LoopPeeledAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_PEELED) {
    return reinterpret_cast<const LoopPeeledAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopPeeledAttr LoopPeeledAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopPeeledAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopUnswitchAttr> LoopUnswitchAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_UNSWITCH) {
    return reinterpret_cast<const LoopUnswitchAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopUnswitchAttr LoopUnswitchAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopUnswitchAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoopAnnotationAttr> LoopAnnotationAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_LOOP_ANNOTATION) {
    return reinterpret_cast<const LoopAnnotationAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::LoopAnnotationAttr LoopAnnotationAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::LoopAnnotationAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIExpressionElemAttr> DIExpressionElemAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_EXPRESSION_ELEM) {
    return reinterpret_cast<const DIExpressionElemAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIExpressionElemAttr DIExpressionElemAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIExpressionElemAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIExpressionAttr> DIExpressionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_EXPRESSION) {
    return reinterpret_cast<const DIExpressionAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIExpressionAttr DIExpressionAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIExpressionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DINullTypeAttr> DINullTypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_NULL_TYPE) {
    return reinterpret_cast<const DINullTypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DINullTypeAttr DINullTypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DINullTypeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIBasicTypeAttr> DIBasicTypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_BASIC_TYPE) {
    return reinterpret_cast<const DIBasicTypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIBasicTypeAttr DIBasicTypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIBasicTypeAttr(this->::mx::ir::Attribute::attr_);
}

uint64_t DIBasicTypeAttr::size_in_bits(void) const {
  auto val = underlying_repr().getSizeInBits();
  return val;
}

std::optional<DICompileUnitAttr> DICompileUnitAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_COMPILE_UNIT) {
    return reinterpret_cast<const DICompileUnitAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DICompileUnitAttr DICompileUnitAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DICompileUnitAttr(this->::mx::ir::Attribute::attr_);
}

bool DICompileUnitAttr::is_optimized(void) const {
  auto val = underlying_repr().getIsOptimized();
  return val;
}

std::optional<DICompositeTypeAttr> DICompositeTypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_COMPOSITE_TYPE) {
    return reinterpret_cast<const DICompositeTypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DICompositeTypeAttr DICompositeTypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DICompositeTypeAttr(this->::mx::ir::Attribute::attr_);
}

uint32_t DICompositeTypeAttr::line(void) const {
  auto val = underlying_repr().getLine();
  return val;
}

uint64_t DICompositeTypeAttr::size_in_bits(void) const {
  auto val = underlying_repr().getSizeInBits();
  return val;
}

uint64_t DICompositeTypeAttr::align_in_bits(void) const {
  auto val = underlying_repr().getAlignInBits();
  return val;
}

std::optional<DIDerivedTypeAttr> DIDerivedTypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_DERIVED_TYPE) {
    return reinterpret_cast<const DIDerivedTypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIDerivedTypeAttr DIDerivedTypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIDerivedTypeAttr(this->::mx::ir::Attribute::attr_);
}

uint64_t DIDerivedTypeAttr::size_in_bits(void) const {
  auto val = underlying_repr().getSizeInBits();
  return val;
}

uint32_t DIDerivedTypeAttr::align_in_bits(void) const {
  auto val = underlying_repr().getAlignInBits();
  return val;
}

uint64_t DIDerivedTypeAttr::offset_in_bits(void) const {
  auto val = underlying_repr().getOffsetInBits();
  return val;
}

std::optional<DIFileAttr> DIFileAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_FILE) {
    return reinterpret_cast<const DIFileAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIFileAttr DIFileAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIFileAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIGlobalVariableExpressionAttr> DIGlobalVariableExpressionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_GLOBAL_VARIABLE_EXPRESSION) {
    return reinterpret_cast<const DIGlobalVariableExpressionAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIGlobalVariableExpressionAttr DIGlobalVariableExpressionAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIGlobalVariableExpressionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIGlobalVariableAttr> DIGlobalVariableAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_GLOBAL_VARIABLE) {
    return reinterpret_cast<const DIGlobalVariableAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIGlobalVariableAttr DIGlobalVariableAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIGlobalVariableAttr(this->::mx::ir::Attribute::attr_);
}

bool DIGlobalVariableAttr::is_local_to_unit(void) const {
  auto val = underlying_repr().getIsLocalToUnit();
  return val;
}

bool DIGlobalVariableAttr::is_defined(void) const {
  auto val = underlying_repr().getIsDefined();
  return val;
}

std::optional<DILexicalBlockAttr> DILexicalBlockAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_LEXICAL_BLOCK) {
    return reinterpret_cast<const DILexicalBlockAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DILexicalBlockAttr DILexicalBlockAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DILexicalBlockAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DILexicalBlockFileAttr> DILexicalBlockFileAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE) {
    return reinterpret_cast<const DILexicalBlockFileAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DILexicalBlockFileAttr DILexicalBlockFileAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DILexicalBlockFileAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DILocalVariableAttr> DILocalVariableAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_LOCAL_VARIABLE) {
    return reinterpret_cast<const DILocalVariableAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DILocalVariableAttr DILocalVariableAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DILocalVariableAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DISubprogramAttr> DISubprogramAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_SUBPROGRAM) {
    return reinterpret_cast<const DISubprogramAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DISubprogramAttr DISubprogramAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DISubprogramAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DIModuleAttr> DIModuleAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_MODULE) {
    return reinterpret_cast<const DIModuleAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DIModuleAttr DIModuleAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DIModuleAttr(this->::mx::ir::Attribute::attr_);
}

bool DIModuleAttr::is_decl(void) const {
  auto val = underlying_repr().getIsDecl();
  return val;
}

std::optional<DINamespaceAttr> DINamespaceAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_NAMESPACE) {
    return reinterpret_cast<const DINamespaceAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DINamespaceAttr DINamespaceAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DINamespaceAttr(this->::mx::ir::Attribute::attr_);
}

bool DINamespaceAttr::export_symbols(void) const {
  auto val = underlying_repr().getExportSymbols();
  return val;
}

std::optional<DISubrangeAttr> DISubrangeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_SUBRANGE) {
    return reinterpret_cast<const DISubrangeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DISubrangeAttr DISubrangeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DISubrangeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DISubroutineTypeAttr> DISubroutineTypeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_SUBROUTINE_TYPE) {
    return reinterpret_cast<const DISubroutineTypeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DISubroutineTypeAttr DISubroutineTypeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DISubroutineTypeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<DILabelAttr> DILabelAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_DI_LABEL) {
    return reinterpret_cast<const DILabelAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::DILabelAttr DILabelAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::DILabelAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<MemoryEffectsAttr> MemoryEffectsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_MEMORY_EFFECTS) {
    return reinterpret_cast<const MemoryEffectsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::MemoryEffectsAttr MemoryEffectsAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::MemoryEffectsAttr(this->::mx::ir::Attribute::attr_);
}

bool MemoryEffectsAttr::is_read_write(void) const {
  auto val = underlying_repr().isReadWrite();
  return val;
}

std::optional<AliasScopeDomainAttr> AliasScopeDomainAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN) {
    return reinterpret_cast<const AliasScopeDomainAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::AliasScopeDomainAttr AliasScopeDomainAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AliasScopeDomainAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AliasScopeAttr> AliasScopeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_ALIAS_SCOPE) {
    return reinterpret_cast<const AliasScopeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::AliasScopeAttr AliasScopeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AliasScopeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AccessGroupAttr> AccessGroupAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_ACCESS_GROUP) {
    return reinterpret_cast<const AccessGroupAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::AccessGroupAttr AccessGroupAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::AccessGroupAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<TBAARootAttr> TBAARootAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_TBAA_ROOT) {
    return reinterpret_cast<const TBAARootAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::TBAARootAttr TBAARootAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TBAARootAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<TBAAMemberAttr> TBAAMemberAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_TBAA_MEMBER) {
    return reinterpret_cast<const TBAAMemberAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::TBAAMemberAttr TBAAMemberAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TBAAMemberAttr(this->::mx::ir::Attribute::attr_);
}

int64_t TBAAMemberAttr::offset(void) const {
  auto val = underlying_repr().getOffset();
  return val;
}

std::optional<TBAATypeDescriptorAttr> TBAATypeDescriptorAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR) {
    return reinterpret_cast<const TBAATypeDescriptorAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::TBAATypeDescriptorAttr TBAATypeDescriptorAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TBAATypeDescriptorAttr(this->::mx::ir::Attribute::attr_);
}

std::string_view TBAATypeDescriptorAttr::id(void) const {
  auto val = underlying_repr().getId();
  if (auto size = val.size()) {
    return std::string_view(val.data(), size);
  } else {
    return {};
  }
}

std::optional<TBAATagAttr> TBAATagAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_TBAA_TAG) {
    return reinterpret_cast<const TBAATagAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::TBAATagAttr TBAATagAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TBAATagAttr(this->::mx::ir::Attribute::attr_);
}

int64_t TBAATagAttr::offset(void) const {
  auto val = underlying_repr().getOffset();
  return val;
}

bool TBAATagAttr::constant(void) const {
  auto val = underlying_repr().getConstant();
  return val;
}

std::optional<VScaleRangeAttr> VScaleRangeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_V_SCALE_RANGE) {
    return reinterpret_cast<const VScaleRangeAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::VScaleRangeAttr VScaleRangeAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::VScaleRangeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<TargetFeaturesAttr> TargetFeaturesAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_TARGET_FEATURES) {
    return reinterpret_cast<const TargetFeaturesAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::TargetFeaturesAttr TargetFeaturesAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::TargetFeaturesAttr(this->::mx::ir::Attribute::attr_);
}

bool TargetFeaturesAttr::null_or_empty(void) const {
  auto val = underlying_repr().nullOrEmpty();
  return val;
}

std::string TargetFeaturesAttr::features_string(void) const {
  auto val = underlying_repr().getFeaturesString();
  return val;
}

std::optional<IntegerOverflowFlagsAttr> IntegerOverflowFlagsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_INTEGER_OVERFLOW_FLAGS) {
    return reinterpret_cast<const IntegerOverflowFlagsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::IntegerOverflowFlagsAttr IntegerOverflowFlagsAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::IntegerOverflowFlagsAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<FastmathFlagsAttr> FastmathFlagsAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::LLVM_FASTMATH_FLAGS) {
    return reinterpret_cast<const FastmathFlagsAttr &>(that);
  }
  return std::nullopt;
}

::mlir::LLVM::FastmathFlagsAttr FastmathFlagsAttr::underlying_repr(void) const noexcept {
  return ::mlir::LLVM::FastmathFlagsAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::llvm
