// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Attribute.h"

namespace mlir::LLVM {
class CConvAttr;
class ComdatAttr;
class LinkageAttr;
class FramePointerKindAttr;
class LoopVectorizeAttr;
class LoopInterleaveAttr;
class LoopUnrollAttr;
class LoopUnrollAndJamAttr;
class LoopLICMAttr;
class LoopDistributeAttr;
class LoopPipelineAttr;
class LoopPeeledAttr;
class LoopUnswitchAttr;
class LoopAnnotationAttr;
class DIExpressionElemAttr;
class DIExpressionAttr;
class DINullTypeAttr;
class DIBasicTypeAttr;
class DICompileUnitAttr;
class DICompositeTypeAttr;
class DIDerivedTypeAttr;
class DIFileAttr;
class DIGlobalVariableExpressionAttr;
class DIGlobalVariableAttr;
class DILexicalBlockAttr;
class DILexicalBlockFileAttr;
class DILocalVariableAttr;
class DISubprogramAttr;
class DIModuleAttr;
class DINamespaceAttr;
class DISubrangeAttr;
class DISubroutineTypeAttr;
class DILabelAttr;
class MemoryEffectsAttr;
class AliasScopeDomainAttr;
class AliasScopeAttr;
class AccessGroupAttr;
class TBAARootAttr;
class TBAAMemberAttr;
class TBAATypeDescriptorAttr;
class TBAATagAttr;
class VScaleRangeAttr;
class TargetFeaturesAttr;
class IntegerOverflowFlagsAttr;
class FastmathFlagsAttr;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {

class MX_EXPORT Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class MX_EXPORT CConvAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_C_CONV;
  }

  static std::optional<CConvAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::CConvAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //CConv calling_conv(void) const;
};
static_assert(sizeof(CConvAttr) == sizeof(Attribute));

class MX_EXPORT ComdatAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_COMDAT;
  }

  static std::optional<ComdatAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::ComdatAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //comdat::Comdat comdat(void) const;
};
static_assert(sizeof(ComdatAttr) == sizeof(Attribute));

class MX_EXPORT LinkageAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LINKAGE;
  }

  static std::optional<LinkageAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LinkageAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //linkage::Linkage linkage(void) const;
};
static_assert(sizeof(LinkageAttr) == sizeof(Attribute));

class MX_EXPORT FramePointerKindAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_FRAME_POINTER_KIND;
  }

  static std::optional<FramePointerKindAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::FramePointerKindAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //framePointerKind::FramePointerKind frame_pointer_kind(void) const;
};
static_assert(sizeof(FramePointerKindAttr) == sizeof(Attribute));

class MX_EXPORT LoopVectorizeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_VECTORIZE;
  }

  static std::optional<LoopVectorizeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopVectorizeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //BoolAttr predicate_enable(void) const;
  //BoolAttr scalable_enable(void) const;
  //IntegerAttr width(void) const;
  //LoopAnnotationAttr followup_vectorized(void) const;
  //LoopAnnotationAttr followup_epilogue(void) const;
  //LoopAnnotationAttr followup_all(void) const;
};
static_assert(sizeof(LoopVectorizeAttr) == sizeof(Attribute));

class MX_EXPORT LoopInterleaveAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_INTERLEAVE;
  }

  static std::optional<LoopInterleaveAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopInterleaveAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr count(void) const;
};
static_assert(sizeof(LoopInterleaveAttr) == sizeof(Attribute));

class MX_EXPORT LoopUnrollAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_UNROLL;
  }

  static std::optional<LoopUnrollAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopUnrollAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //IntegerAttr count(void) const;
  //BoolAttr runtime_disable(void) const;
  //BoolAttr full(void) const;
  //LoopAnnotationAttr followup_unrolled(void) const;
  //LoopAnnotationAttr followup_remainder(void) const;
  //LoopAnnotationAttr followup_all(void) const;
};
static_assert(sizeof(LoopUnrollAttr) == sizeof(Attribute));

class MX_EXPORT LoopUnrollAndJamAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_UNROLL_AND_JAM;
  }

  static std::optional<LoopUnrollAndJamAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopUnrollAndJamAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //IntegerAttr count(void) const;
  //LoopAnnotationAttr followup_outer(void) const;
  //LoopAnnotationAttr followup_inner(void) const;
  //LoopAnnotationAttr followup_remainder_outer(void) const;
  //LoopAnnotationAttr followup_remainder_inner(void) const;
  //LoopAnnotationAttr followup_all(void) const;
};
static_assert(sizeof(LoopUnrollAndJamAttr) == sizeof(Attribute));

class MX_EXPORT LoopLICMAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_LICM;
  }

  static std::optional<LoopLICMAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopLICMAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //BoolAttr versioning_disable(void) const;
};
static_assert(sizeof(LoopLICMAttr) == sizeof(Attribute));

class MX_EXPORT LoopDistributeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_DISTRIBUTE;
  }

  static std::optional<LoopDistributeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopDistributeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //LoopAnnotationAttr followup_coincident(void) const;
  //LoopAnnotationAttr followup_sequential(void) const;
  //LoopAnnotationAttr followup_fallback(void) const;
  //LoopAnnotationAttr followup_all(void) const;
};
static_assert(sizeof(LoopDistributeAttr) == sizeof(Attribute));

class MX_EXPORT LoopPipelineAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_PIPELINE;
  }

  static std::optional<LoopPipelineAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopPipelineAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //IntegerAttr initiationinterval(void) const;
};
static_assert(sizeof(LoopPipelineAttr) == sizeof(Attribute));

class MX_EXPORT LoopPeeledAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_PEELED;
  }

  static std::optional<LoopPeeledAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopPeeledAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr count(void) const;
};
static_assert(sizeof(LoopPeeledAttr) == sizeof(Attribute));

class MX_EXPORT LoopUnswitchAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_UNSWITCH;
  }

  static std::optional<LoopUnswitchAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopUnswitchAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr partial_disable(void) const;
};
static_assert(sizeof(LoopUnswitchAttr) == sizeof(Attribute));

class MX_EXPORT LoopAnnotationAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_ANNOTATION;
  }

  static std::optional<LoopAnnotationAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopAnnotationAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable_nonforced(void) const;
  //LoopVectorizeAttr vectorize(void) const;
  //LoopInterleaveAttr interleave(void) const;
  //LoopUnrollAttr unroll(void) const;
  //LoopUnrollAndJamAttr unroll_and_jam(void) const;
  //LoopLICMAttr licm(void) const;
  //LoopDistributeAttr distribute(void) const;
  //LoopPipelineAttr pipeline(void) const;
  //LoopPeeledAttr peeled(void) const;
  //LoopUnswitchAttr unswitch(void) const;
  //BoolAttr must_progress(void) const;
  //BoolAttr is_vectorized(void) const;
  //FusedLoc start_loc(void) const;
  //FusedLoc end_loc(void) const;
  //::llvm::ArrayRef<AccessGroupAttr> parallel_accesses(void) const;
};
static_assert(sizeof(LoopAnnotationAttr) == sizeof(Attribute));

class MX_EXPORT DIExpressionElemAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_EXPRESSION_ELEM;
  }

  static std::optional<DIExpressionElemAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIExpressionElemAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int opcode(void) const;
  //::llvm::ArrayRef<unsigned long long> arguments(void) const;
};
static_assert(sizeof(DIExpressionElemAttr) == sizeof(Attribute));

class MX_EXPORT DIExpressionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_EXPRESSION;
  }

  static std::optional<DIExpressionAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIExpressionAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::llvm::ArrayRef<DIExpressionElemAttr> operations(void) const;
};
static_assert(sizeof(DIExpressionAttr) == sizeof(Attribute));

class MX_EXPORT DINullTypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_NULL_TYPE;
  }

  static std::optional<DINullTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DINullTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DINullTypeAttr) == sizeof(Attribute));

class MX_EXPORT DIBasicTypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_BASIC_TYPE;
  }

  static std::optional<DIBasicTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIBasicTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int tag(void) const;
  //StringAttr name(void) const;
  uint64_t size_in_bits(void) const;
  unsigned int encoding(void) const;
};
static_assert(sizeof(DIBasicTypeAttr) == sizeof(Attribute));

class MX_EXPORT DICompileUnitAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_COMPILE_UNIT;
  }

  static std::optional<DICompileUnitAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DICompileUnitAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
  unsigned int source_language(void) const;
  //DIFileAttr file(void) const;
  //StringAttr producer(void) const;
  bool is_optimized(void) const;
  //DIEmissionKind emission_kind(void) const;
};
static_assert(sizeof(DICompileUnitAttr) == sizeof(Attribute));

class MX_EXPORT DICompositeTypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_COMPOSITE_TYPE;
  }

  static std::optional<DICompositeTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DICompositeTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int tag(void) const;
  //StringAttr name(void) const;
  //DIFileAttr file(void) const;
  uint32_t line(void) const;
  //DIScopeAttr scope(void) const;
  //DITypeAttr base_type(void) const;
  //DIFlags flags(void) const;
  uint64_t size_in_bits(void) const;
  uint64_t align_in_bits(void) const;
  //::llvm::ArrayRef<DINodeAttr> elements(void) const;
};
static_assert(sizeof(DICompositeTypeAttr) == sizeof(Attribute));

class MX_EXPORT DIDerivedTypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_DERIVED_TYPE;
  }

  static std::optional<DIDerivedTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIDerivedTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int tag(void) const;
  //StringAttr name(void) const;
  //DITypeAttr base_type(void) const;
  uint64_t size_in_bits(void) const;
  uint32_t align_in_bits(void) const;
  uint64_t offset_in_bits(void) const;
};
static_assert(sizeof(DIDerivedTypeAttr) == sizeof(Attribute));

class MX_EXPORT DIFileAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_FILE;
  }

  static std::optional<DIFileAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIFileAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr name(void) const;
  //StringAttr directory(void) const;
};
static_assert(sizeof(DIFileAttr) == sizeof(Attribute));

class MX_EXPORT DIGlobalVariableExpressionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_GLOBAL_VARIABLE_EXPRESSION;
  }

  static std::optional<DIGlobalVariableExpressionAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIGlobalVariableExpressionAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIGlobalVariableAttr var(void) const;
  //DIExpressionAttr expression(void) const;
};
static_assert(sizeof(DIGlobalVariableExpressionAttr) == sizeof(Attribute));

class MX_EXPORT DIGlobalVariableAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_GLOBAL_VARIABLE;
  }

  static std::optional<DIGlobalVariableAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIGlobalVariableAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //StringAttr linkage_name(void) const;
  //DIFileAttr file(void) const;
  unsigned int line(void) const;
  //DITypeAttr type(void) const;
  bool is_local_to_unit(void) const;
  bool is_defined(void) const;
  unsigned int align_in_bits(void) const;
};
static_assert(sizeof(DIGlobalVariableAttr) == sizeof(Attribute));

class MX_EXPORT DILexicalBlockAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LEXICAL_BLOCK;
  }

  static std::optional<DILexicalBlockAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILexicalBlockAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //DIFileAttr file(void) const;
  unsigned int line(void) const;
  unsigned int column(void) const;
};
static_assert(sizeof(DILexicalBlockAttr) == sizeof(Attribute));

class MX_EXPORT DILexicalBlockFileAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE;
  }

  static std::optional<DILexicalBlockFileAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILexicalBlockFileAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //DIFileAttr file(void) const;
  unsigned int discriminator(void) const;
};
static_assert(sizeof(DILexicalBlockFileAttr) == sizeof(Attribute));

class MX_EXPORT DILocalVariableAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LOCAL_VARIABLE;
  }

  static std::optional<DILocalVariableAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILocalVariableAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //DIFileAttr file(void) const;
  unsigned int line(void) const;
  unsigned int argument(void) const;
  unsigned int align_in_bits(void) const;
  //DITypeAttr type(void) const;
};
static_assert(sizeof(DILocalVariableAttr) == sizeof(Attribute));

class MX_EXPORT DISubprogramAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_SUBPROGRAM;
  }

  static std::optional<DISubprogramAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DISubprogramAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
  //DICompileUnitAttr compile_unit(void) const;
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //StringAttr linkage_name(void) const;
  //DIFileAttr file(void) const;
  unsigned int line(void) const;
  unsigned int scope_line(void) const;
  //DISubprogramFlags subprogram_flags(void) const;
  //DISubroutineTypeAttr type(void) const;
};
static_assert(sizeof(DISubprogramAttr) == sizeof(Attribute));

class MX_EXPORT DIModuleAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_MODULE;
  }

  static std::optional<DIModuleAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIModuleAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIFileAttr file(void) const;
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //StringAttr config_macros(void) const;
  //StringAttr include_path(void) const;
  //StringAttr apinotes(void) const;
  unsigned int line(void) const;
  bool is_decl(void) const;
};
static_assert(sizeof(DIModuleAttr) == sizeof(Attribute));

class MX_EXPORT DINamespaceAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_NAMESPACE;
  }

  static std::optional<DINamespaceAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DINamespaceAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr name(void) const;
  //DIScopeAttr scope(void) const;
  bool export_symbols(void) const;
};
static_assert(sizeof(DINamespaceAttr) == sizeof(Attribute));

class MX_EXPORT DISubrangeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_SUBRANGE;
  }

  static std::optional<DISubrangeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DISubrangeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr count(void) const;
  //IntegerAttr lower_bound(void) const;
  //IntegerAttr upper_bound(void) const;
  //IntegerAttr stride(void) const;
};
static_assert(sizeof(DISubrangeAttr) == sizeof(Attribute));

class MX_EXPORT DISubroutineTypeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_SUBROUTINE_TYPE;
  }

  static std::optional<DISubroutineTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DISubroutineTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int calling_convention(void) const;
  //::llvm::ArrayRef<DITypeAttr> types(void) const;
};
static_assert(sizeof(DISubroutineTypeAttr) == sizeof(Attribute));

class MX_EXPORT DILabelAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LABEL;
  }

  static std::optional<DILabelAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILabelAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //DIFileAttr file(void) const;
  unsigned int line(void) const;
};
static_assert(sizeof(DILabelAttr) == sizeof(Attribute));

class MX_EXPORT MemoryEffectsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_MEMORY_EFFECTS;
  }

  static std::optional<MemoryEffectsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::MemoryEffectsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_read_write(void) const;
  //ModRefInfo other(void) const;
  //ModRefInfo arg_mem(void) const;
  //ModRefInfo inaccessible_mem(void) const;
};
static_assert(sizeof(MemoryEffectsAttr) == sizeof(Attribute));

class MX_EXPORT AliasScopeDomainAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN;
  }

  static std::optional<AliasScopeDomainAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::AliasScopeDomainAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
  //StringAttr description(void) const;
};
static_assert(sizeof(AliasScopeDomainAttr) == sizeof(Attribute));

class MX_EXPORT AliasScopeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_ALIAS_SCOPE;
  }

  static std::optional<AliasScopeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::AliasScopeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
  //AliasScopeDomainAttr domain(void) const;
  //StringAttr description(void) const;
};
static_assert(sizeof(AliasScopeAttr) == sizeof(Attribute));

class MX_EXPORT AccessGroupAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_ACCESS_GROUP;
  }

  static std::optional<AccessGroupAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::AccessGroupAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
};
static_assert(sizeof(AccessGroupAttr) == sizeof(Attribute));

class MX_EXPORT TBAARootAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_ROOT;
  }

  static std::optional<TBAARootAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAARootAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr id(void) const;
};
static_assert(sizeof(TBAARootAttr) == sizeof(Attribute));

class MX_EXPORT TBAAMemberAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_MEMBER;
  }

  static std::optional<TBAAMemberAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAAMemberAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //TBAANodeAttr type_desc(void) const;
  int64_t offset(void) const;
};
static_assert(sizeof(TBAAMemberAttr) == sizeof(Attribute));

class MX_EXPORT TBAATypeDescriptorAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR;
  }

  static std::optional<TBAATypeDescriptorAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAATypeDescriptorAttr underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view id(void) const;
  //::llvm::ArrayRef<TBAAMemberAttr> members(void) const;
};
static_assert(sizeof(TBAATypeDescriptorAttr) == sizeof(Attribute));

class MX_EXPORT TBAATagAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_TAG;
  }

  static std::optional<TBAATagAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAATagAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //TBAATypeDescriptorAttr base_type(void) const;
  //TBAATypeDescriptorAttr access_type(void) const;
  int64_t offset(void) const;
  bool constant(void) const;
};
static_assert(sizeof(TBAATagAttr) == sizeof(Attribute));

class MX_EXPORT VScaleRangeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_V_SCALE_RANGE;
  }

  static std::optional<VScaleRangeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::VScaleRangeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr min_range(void) const;
  //IntegerAttr max_range(void) const;
};
static_assert(sizeof(VScaleRangeAttr) == sizeof(Attribute));

class MX_EXPORT TargetFeaturesAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TARGET_FEATURES;
  }

  static std::optional<TargetFeaturesAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TargetFeaturesAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool null_or_empty(void) const;
  std::string features_string(void) const;
  //StringLiteral attribute_name(void) const;
  //::llvm::ArrayRef<StringAttr> features(void) const;
};
static_assert(sizeof(TargetFeaturesAttr) == sizeof(Attribute));

class MX_EXPORT IntegerOverflowFlagsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_INTEGER_OVERFLOW_FLAGS;
  }

  static std::optional<IntegerOverflowFlagsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::IntegerOverflowFlagsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::IntegerOverflowFlags value(void) const;
};
static_assert(sizeof(IntegerOverflowFlagsAttr) == sizeof(Attribute));

class MX_EXPORT FastmathFlagsAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::LLVM_FASTMATH_FLAGS;
  }

  static std::optional<FastmathFlagsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::FastmathFlagsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::FastmathFlags value(void) const;
};
static_assert(sizeof(FastmathFlagsAttr) == sizeof(Attribute));

}  // namespace mx::ir::llvm
