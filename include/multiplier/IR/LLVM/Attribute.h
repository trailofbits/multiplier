// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Attribute.h"

namespace mlir::LLVM {
class CConvAttr;
class ComdatAttr;
class AccessGroupAttr;
class AliasScopeAttr;
class AliasScopeDomainAttr;
class DIBasicTypeAttr;
class DICompileUnitAttr;
class DICompositeTypeAttr;
class DIDerivedTypeAttr;
class DIFileAttr;
class DILabelAttr;
class DILexicalBlockAttr;
class DILexicalBlockFileAttr;
class DILocalVariableAttr;
class DINamespaceAttr;
class DINullTypeAttr;
class DISubprogramAttr;
class DISubrangeAttr;
class DISubroutineTypeAttr;
class FastmathFlagsAttr;
class MemoryEffectsAttr;
class TBAAMemberAttr;
class TBAARootAttr;
class TBAATagAttr;
class TBAATypeDescriptorAttr;
class LinkageAttr;
class LoopAnnotationAttr;
class LoopDistributeAttr;
class LoopInterleaveAttr;
class LoopLICMAttr;
class LoopPeeledAttr;
class LoopPipelineAttr;
class LoopUnrollAndJamAttr;
class LoopUnrollAttr;
class LoopUnswitchAttr;
class LoopVectorizeAttr;
}  // namespace mlir::LLVM
namespace mx::ir::llvm {

class Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class CConvAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_C_CONV;
  }

  static std::optional<CConvAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::CConvAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //CConv calling_conv(void) const;
};
static_assert(sizeof(CConvAttr) == sizeof(Attribute));

class ComdatAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_COMDAT;
  }

  static std::optional<ComdatAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::ComdatAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //comdat::Comdat comdat(void) const;
};
static_assert(sizeof(ComdatAttr) == sizeof(Attribute));

class AccessGroupAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_ACCESS_GROUP;
  }

  static std::optional<AccessGroupAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::AccessGroupAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
};
static_assert(sizeof(AccessGroupAttr) == sizeof(Attribute));

class AliasScopeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class AliasScopeDomainAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_ALIAS_SCOPE_DOMAIN;
  }

  static std::optional<AliasScopeDomainAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::AliasScopeDomainAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DistinctAttr id(void) const;
  //StringAttr description(void) const;
};
static_assert(sizeof(AliasScopeDomainAttr) == sizeof(Attribute));

class DIBasicTypeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_BASIC_TYPE;
  }

  static std::optional<DIBasicTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIBasicTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //unsignedint tag(void) const;
  //StringAttr name(void) const;
  uint64_t size_in_bits(void) const;
  //unsignedint encoding(void) const;
};
static_assert(sizeof(DIBasicTypeAttr) == sizeof(Attribute));

class DICompileUnitAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_COMPILE_UNIT;
  }

  static std::optional<DICompileUnitAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DICompileUnitAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //unsignedint source_language(void) const;
  //DIFileAttr file(void) const;
  //StringAttr producer(void) const;
  bool is_optimized(void) const;
  //DIEmissionKind emission_kind(void) const;
};
static_assert(sizeof(DICompileUnitAttr) == sizeof(Attribute));

class DICompositeTypeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_COMPOSITE_TYPE;
  }

  static std::optional<DICompositeTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DICompositeTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //unsignedint tag(void) const;
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

class DIDerivedTypeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_DERIVED_TYPE;
  }

  static std::optional<DIDerivedTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIDerivedTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //unsignedint tag(void) const;
  //StringAttr name(void) const;
  //DITypeAttr base_type(void) const;
  uint64_t size_in_bits(void) const;
  uint32_t align_in_bits(void) const;
  uint64_t offset_in_bits(void) const;
};
static_assert(sizeof(DIDerivedTypeAttr) == sizeof(Attribute));

class DIFileAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_FILE;
  }

  static std::optional<DIFileAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DIFileAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr name(void) const;
  //StringAttr directory(void) const;
};
static_assert(sizeof(DIFileAttr) == sizeof(Attribute));

class DILabelAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LABEL;
  }

  static std::optional<DILabelAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILabelAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //DIFileAttr file(void) const;
  //unsignedint line(void) const;
};
static_assert(sizeof(DILabelAttr) == sizeof(Attribute));

class DILexicalBlockAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LEXICAL_BLOCK;
  }

  static std::optional<DILexicalBlockAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILexicalBlockAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //DIFileAttr file(void) const;
  //unsignedint line(void) const;
  //unsignedint column(void) const;
};
static_assert(sizeof(DILexicalBlockAttr) == sizeof(Attribute));

class DILexicalBlockFileAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LEXICAL_BLOCK_FILE;
  }

  static std::optional<DILexicalBlockFileAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILexicalBlockFileAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //DIFileAttr file(void) const;
  //unsignedint discriminator(void) const;
};
static_assert(sizeof(DILexicalBlockFileAttr) == sizeof(Attribute));

class DILocalVariableAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_LOCAL_VARIABLE;
  }

  static std::optional<DILocalVariableAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DILocalVariableAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //DIFileAttr file(void) const;
  //unsignedint line(void) const;
  //unsignedint arg(void) const;
  //unsignedint align_in_bits(void) const;
  //DITypeAttr type(void) const;
};
static_assert(sizeof(DILocalVariableAttr) == sizeof(Attribute));

class DINamespaceAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class DINullTypeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_NULL_TYPE;
  }

  static std::optional<DINullTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DINullTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(DINullTypeAttr) == sizeof(Attribute));

class DISubprogramAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_SUBPROGRAM;
  }

  static std::optional<DISubprogramAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DISubprogramAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //DICompileUnitAttr compile_unit(void) const;
  //DIScopeAttr scope(void) const;
  //StringAttr name(void) const;
  //StringAttr linkage_name(void) const;
  //DIFileAttr file(void) const;
  //unsignedint line(void) const;
  //unsignedint scope_line(void) const;
  //DISubprogramFlags subprogram_flags(void) const;
  //DISubroutineTypeAttr type(void) const;
};
static_assert(sizeof(DISubprogramAttr) == sizeof(Attribute));

class DISubrangeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class DISubroutineTypeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_DI_SUBROUTINE_TYPE;
  }

  static std::optional<DISubroutineTypeAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::DISubroutineTypeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //unsignedint calling_convention(void) const;
  //::llvm::ArrayRef<DITypeAttr> types(void) const;
};
static_assert(sizeof(DISubroutineTypeAttr) == sizeof(Attribute));

class FastmathFlagsAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_FASTMATH_FLAGS;
  }

  static std::optional<FastmathFlagsAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::FastmathFlagsAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::LLVM::FastmathFlags value(void) const;
};
static_assert(sizeof(FastmathFlagsAttr) == sizeof(Attribute));

class MemoryEffectsAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class TBAAMemberAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_MEMBER;
  }

  static std::optional<TBAAMemberAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAAMemberAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //TBAANodeAttr type_desc(void) const;
  int64_t offset(void) const;
};
static_assert(sizeof(TBAAMemberAttr) == sizeof(Attribute));

class TBAARootAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_ROOT;
  }

  static std::optional<TBAARootAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAARootAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //StringAttr id(void) const;
};
static_assert(sizeof(TBAARootAttr) == sizeof(Attribute));

class TBAATagAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class TBAATypeDescriptorAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_TBAA_TYPE_DESCRIPTOR;
  }

  static std::optional<TBAATypeDescriptorAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::TBAATypeDescriptorAttr underlying_repr(void) const noexcept;

  // Imported methods:
  std::string_view id(void) const;
  //::llvm::ArrayRef<TBAAMemberAttr> members(void) const;
};
static_assert(sizeof(TBAATypeDescriptorAttr) == sizeof(Attribute));

class LinkageAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LINKAGE;
  }

  static std::optional<LinkageAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LinkageAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //linkage::Linkage linkage(void) const;
};
static_assert(sizeof(LinkageAttr) == sizeof(Attribute));

class LoopAnnotationAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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
  //::llvm::ArrayRef<AccessGroupAttr> parallel_accesses(void) const;
  //FusedLoc start_loc(void) const;
  //FusedLoc end_loc(void) const;
};
static_assert(sizeof(LoopAnnotationAttr) == sizeof(Attribute));

class LoopDistributeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class LoopInterleaveAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_INTERLEAVE;
  }

  static std::optional<LoopInterleaveAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopInterleaveAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr count(void) const;
};
static_assert(sizeof(LoopInterleaveAttr) == sizeof(Attribute));

class LoopLICMAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_LICM;
  }

  static std::optional<LoopLICMAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopLICMAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //BoolAttr versioning_disable(void) const;
};
static_assert(sizeof(LoopLICMAttr) == sizeof(Attribute));

class LoopPeeledAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_PEELED;
  }

  static std::optional<LoopPeeledAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopPeeledAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //IntegerAttr count(void) const;
};
static_assert(sizeof(LoopPeeledAttr) == sizeof(Attribute));

class LoopPipelineAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_PIPELINE;
  }

  static std::optional<LoopPipelineAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopPipelineAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr disable(void) const;
  //IntegerAttr initiationinterval(void) const;
};
static_assert(sizeof(LoopPipelineAttr) == sizeof(Attribute));

class LoopUnrollAndJamAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class LoopUnrollAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

class LoopUnswitchAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
    return AttributeKind::LLVM_LOOP_UNSWITCH;
  }

  static std::optional<LoopUnswitchAttr> from(const ::mx::ir::Attribute &that);

  ::mlir::LLVM::LoopUnswitchAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //BoolAttr partial_disable(void) const;
};
static_assert(sizeof(LoopUnswitchAttr) == sizeof(Attribute));

class LoopVectorizeAttr final : public Attribute {
 public:
  inline static AttributeKind static_kind(void) {
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

}  // namespace mx::ir::llvm
