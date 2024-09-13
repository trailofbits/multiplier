// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "../Attribute.h"

namespace vast::hl {
class AnnotationAttr;
class FormatAttr;
class SectionAttr;
class AliasAttr;
class ErrorAttr;
class CountedByAttr;
class CleanupAttr;
class AlignedAttr;
class AlwaysInlineAttr;
class NoInlineAttr;
class ConstAttr;
class LoaderUninitializedAttr;
class NoInstrumentFunctionAttr;
class PackedAttr;
class PureAttr;
class WarnUnusedResultAttr;
class RestrictAttr;
class NoThrowAttr;
class NonNullAttr;
class LeafAttr;
class ColdAttr;
class TransparentUnionAttr;
class ReturnsTwiceAttr;
class MayAliasAttr;
class UnusedAttr;
class UsedAttr;
class GNUInlineAttr;
class NoCfCheckAttr;
class AvailableOnlyInDefaultEvalMethodAttr;
class AvailabilityAttrAttr;
class FallthroughAttr;
class NoProfileInstrumentFunctionAttr;
class AsmLabelAttr;
class ModeAttr;
class BuiltinAttr;
class AllocAlignAttr;
class AllocSizeAttr;
class DeprecatedAttr;
class MaxFieldAlignmentAttr;
class VisibilityAttr;
class AssumeAlignedAttr;
class CVQualifiersAttr;
class UCVQualifiersAttr;
class CVRQualifiersAttr;
class OffsetOfNodeAttr;
}  // namespace vast::hl
namespace mx::ir::hl {

class MX_EXPORT Attribute : public ::mx::ir::Attribute {
 public:
  static std::optional<Attribute> from(const ::mx::ir::Attribute &);
};
static_assert(sizeof(Attribute) == sizeof(::mx::ir::Attribute));

class MX_EXPORT AnnotationAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ANNOTATION;
  }

  static std::optional<AnnotationAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AnnotationAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr name(void) const;
};
static_assert(sizeof(AnnotationAttr) == sizeof(Attribute));

class MX_EXPORT FormatAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_FORMAT;
  }

  static std::optional<FormatAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::FormatAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr name(void) const;
};
static_assert(sizeof(FormatAttr) == sizeof(Attribute));

class MX_EXPORT SectionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_SECTION;
  }

  static std::optional<SectionAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::SectionAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr name(void) const;
};
static_assert(sizeof(SectionAttr) == sizeof(Attribute));

class MX_EXPORT AliasAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ALIAS;
  }

  static std::optional<AliasAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AliasAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr name(void) const;
};
static_assert(sizeof(AliasAttr) == sizeof(Attribute));

class MX_EXPORT ErrorAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ERROR;
  }

  static std::optional<ErrorAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::ErrorAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr name(void) const;
};
static_assert(sizeof(ErrorAttr) == sizeof(Attribute));

class MX_EXPORT CountedByAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_COUNTED_BY;
  }

  static std::optional<CountedByAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::CountedByAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::FlatSymbolRefAttr symbol(void) const;
};
static_assert(sizeof(CountedByAttr) == sizeof(Attribute));

class MX_EXPORT CleanupAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_CLEANUP;
  }

  static std::optional<CleanupAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::CleanupAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::SymbolRefAttr symbol(void) const;
};
static_assert(sizeof(CleanupAttr) == sizeof(Attribute));

class MX_EXPORT AlignedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ALIGNED;
  }

  static std::optional<AlignedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AlignedAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(AlignedAttr) == sizeof(Attribute));

class MX_EXPORT AlwaysInlineAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ALWAYS_INLINE;
  }

  static std::optional<AlwaysInlineAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AlwaysInlineAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(AlwaysInlineAttr) == sizeof(Attribute));

class MX_EXPORT NoInlineAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NO_INLINE;
  }

  static std::optional<NoInlineAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NoInlineAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoInlineAttr) == sizeof(Attribute));

class MX_EXPORT ConstAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_CONST;
  }

  static std::optional<ConstAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::ConstAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ConstAttr) == sizeof(Attribute));

class MX_EXPORT LoaderUninitializedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_LOADER_UNINITIALIZED;
  }

  static std::optional<LoaderUninitializedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::LoaderUninitializedAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(LoaderUninitializedAttr) == sizeof(Attribute));

class MX_EXPORT NoInstrumentFunctionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NO_INSTRUMENT_FUNCTION;
  }

  static std::optional<NoInstrumentFunctionAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NoInstrumentFunctionAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoInstrumentFunctionAttr) == sizeof(Attribute));

class MX_EXPORT PackedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_PACKED;
  }

  static std::optional<PackedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::PackedAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(PackedAttr) == sizeof(Attribute));

class MX_EXPORT PureAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_PURE;
  }

  static std::optional<PureAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::PureAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(PureAttr) == sizeof(Attribute));

class MX_EXPORT WarnUnusedResultAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_WARN_UNUSED_RESULT;
  }

  static std::optional<WarnUnusedResultAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::WarnUnusedResultAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(WarnUnusedResultAttr) == sizeof(Attribute));

class MX_EXPORT RestrictAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_RESTRICT;
  }

  static std::optional<RestrictAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::RestrictAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(RestrictAttr) == sizeof(Attribute));

class MX_EXPORT NoThrowAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NO_THROW;
  }

  static std::optional<NoThrowAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NoThrowAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoThrowAttr) == sizeof(Attribute));

class MX_EXPORT NonNullAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NON_NULL;
  }

  static std::optional<NonNullAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NonNullAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NonNullAttr) == sizeof(Attribute));

class MX_EXPORT LeafAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_LEAF;
  }

  static std::optional<LeafAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::LeafAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(LeafAttr) == sizeof(Attribute));

class MX_EXPORT ColdAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_COLD;
  }

  static std::optional<ColdAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::ColdAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ColdAttr) == sizeof(Attribute));

class MX_EXPORT TransparentUnionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_TRANSPARENT_UNION;
  }

  static std::optional<TransparentUnionAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::TransparentUnionAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(TransparentUnionAttr) == sizeof(Attribute));

class MX_EXPORT ReturnsTwiceAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_RETURNS_TWICE;
  }

  static std::optional<ReturnsTwiceAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::ReturnsTwiceAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(ReturnsTwiceAttr) == sizeof(Attribute));

class MX_EXPORT MayAliasAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_MAY_ALIAS;
  }

  static std::optional<MayAliasAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::MayAliasAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(MayAliasAttr) == sizeof(Attribute));

class MX_EXPORT UnusedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_UNUSED;
  }

  static std::optional<UnusedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::UnusedAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UnusedAttr) == sizeof(Attribute));

class MX_EXPORT UsedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_USED;
  }

  static std::optional<UsedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::UsedAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(UsedAttr) == sizeof(Attribute));

class MX_EXPORT GNUInlineAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_GNU_INLINE;
  }

  static std::optional<GNUInlineAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::GNUInlineAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(GNUInlineAttr) == sizeof(Attribute));

class MX_EXPORT NoCfCheckAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NO_CF_CHECK;
  }

  static std::optional<NoCfCheckAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NoCfCheckAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoCfCheckAttr) == sizeof(Attribute));

class MX_EXPORT AvailableOnlyInDefaultEvalMethodAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD;
  }

  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AvailableOnlyInDefaultEvalMethodAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(AvailableOnlyInDefaultEvalMethodAttr) == sizeof(Attribute));

class MX_EXPORT AvailabilityAttrAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_AVAILABILITY_ATTR;
  }

  static std::optional<AvailabilityAttrAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AvailabilityAttrAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(AvailabilityAttrAttr) == sizeof(Attribute));

class MX_EXPORT FallthroughAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_FALLTHROUGH;
  }

  static std::optional<FallthroughAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::FallthroughAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(FallthroughAttr) == sizeof(Attribute));

class MX_EXPORT NoProfileInstrumentFunctionAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_NO_PROFILE_INSTRUMENT_FUNCTION;
  }

  static std::optional<NoProfileInstrumentFunctionAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::NoProfileInstrumentFunctionAttr underlying_repr(void) const noexcept;

  // Imported methods:
};
static_assert(sizeof(NoProfileInstrumentFunctionAttr) == sizeof(Attribute));

class MX_EXPORT AsmLabelAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ASM_LABEL;
  }

  static std::optional<AsmLabelAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AsmLabelAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr label(void) const;
  bool is_literal(void) const;
};
static_assert(sizeof(AsmLabelAttr) == sizeof(Attribute));

class MX_EXPORT ModeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_MODE;
  }

  static std::optional<ModeAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::ModeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr mode(void) const;
};
static_assert(sizeof(ModeAttr) == sizeof(Attribute));

class MX_EXPORT BuiltinAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_BUILTIN;
  }

  static std::optional<BuiltinAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::BuiltinAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int id(void) const;
};
static_assert(sizeof(BuiltinAttr) == sizeof(Attribute));

class MX_EXPORT AllocAlignAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ALLOC_ALIGN;
  }

  static std::optional<AllocAlignAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AllocAlignAttr underlying_repr(void) const noexcept;

  // Imported methods:
  int alignment(void) const;
};
static_assert(sizeof(AllocAlignAttr) == sizeof(Attribute));

class MX_EXPORT AllocSizeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ALLOC_SIZE;
  }

  static std::optional<AllocSizeAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AllocSizeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  int size_arg_pos(void) const;
  int num_arg_pos(void) const;
};
static_assert(sizeof(AllocSizeAttr) == sizeof(Attribute));

class MX_EXPORT DeprecatedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_DEPRECATED;
  }

  static std::optional<DeprecatedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::DeprecatedAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::mlir::StringAttr message(void) const;
  //::mlir::StringAttr fixit(void) const;
};
static_assert(sizeof(DeprecatedAttr) == sizeof(Attribute));

class MX_EXPORT MaxFieldAlignmentAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_MAX_FIELD_ALIGNMENT;
  }

  static std::optional<MaxFieldAlignmentAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::MaxFieldAlignmentAttr underlying_repr(void) const noexcept;

  // Imported methods:
  unsigned int alignment(void) const;
};
static_assert(sizeof(MaxFieldAlignmentAttr) == sizeof(Attribute));

class MX_EXPORT VisibilityAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_VISIBILITY;
  }

  static std::optional<VisibilityAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::VisibilityAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //::vast::hl::Visibility value(void) const;
};
static_assert(sizeof(VisibilityAttr) == sizeof(Attribute));

class MX_EXPORT AssumeAlignedAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_ASSUME_ALIGNED;
  }

  static std::optional<AssumeAlignedAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::AssumeAlignedAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //llvm::APInt alignment(void) const;
  //llvm::APInt offset(void) const;
};
static_assert(sizeof(AssumeAlignedAttr) == sizeof(Attribute));

class MX_EXPORT CVQualifiersAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_CV_QUALIFIERS;
  }

  static std::optional<CVQualifiersAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::CVQualifiersAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_const(void) const;
  bool is_volatile(void) const;
};
static_assert(sizeof(CVQualifiersAttr) == sizeof(Attribute));

class MX_EXPORT UCVQualifiersAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_UCV_QUALIFIERS;
  }

  static std::optional<UCVQualifiersAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::UCVQualifiersAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_unsigned(void) const;
  bool is_const(void) const;
  bool is_volatile(void) const;
};
static_assert(sizeof(UCVQualifiersAttr) == sizeof(Attribute));

class MX_EXPORT CVRQualifiersAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_CVR_QUALIFIERS;
  }

  static std::optional<CVRQualifiersAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::CVRQualifiersAttr underlying_repr(void) const noexcept;

  // Imported methods:
  bool is_const(void) const;
  bool is_volatile(void) const;
  bool is_restrict(void) const;
};
static_assert(sizeof(CVRQualifiersAttr) == sizeof(Attribute));

class MX_EXPORT OffsetOfNodeAttr final : public Attribute {
 public:
  inline static constexpr AttributeKind static_kind(void) {
    return AttributeKind::HL_OFFSET_OF_NODE;
  }

  static std::optional<OffsetOfNodeAttr> from(const ::mx::ir::Attribute &that);

  ::vast::hl::OffsetOfNodeAttr underlying_repr(void) const noexcept;

  // Imported methods:
  //std::variant<unsigned int, StringAttr> value(void) const;
};
static_assert(sizeof(OffsetOfNodeAttr) == sizeof(Attribute));

}  // namespace mx::ir::hl
