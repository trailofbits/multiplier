// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Attribute.h>

#include <multiplier/IR/Type.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>

namespace mx::ir::hl {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsHighLevelAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
}

std::optional<AnnotationAttr> AnnotationAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ANNOTATION) {
    return reinterpret_cast<const AnnotationAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AnnotationAttr AnnotationAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AnnotationAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<FormatAttr> FormatAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_FORMAT) {
    return reinterpret_cast<const FormatAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::FormatAttr FormatAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::FormatAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<SectionAttr> SectionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_SECTION) {
    return reinterpret_cast<const SectionAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::SectionAttr SectionAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::SectionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AliasAttr> AliasAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ALIAS) {
    return reinterpret_cast<const AliasAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AliasAttr AliasAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AliasAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ErrorAttr> ErrorAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ERROR) {
    return reinterpret_cast<const ErrorAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ErrorAttr ErrorAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ErrorAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<CountedByAttr> CountedByAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_COUNTED_BY) {
    return reinterpret_cast<const CountedByAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::CountedByAttr CountedByAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::CountedByAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<CleanupAttr> CleanupAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_CLEANUP) {
    return reinterpret_cast<const CleanupAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::CleanupAttr CleanupAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::CleanupAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AlignedAttr> AlignedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ALIGNED) {
    return reinterpret_cast<const AlignedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AlignedAttr AlignedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AlignedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AlwaysInlineAttr> AlwaysInlineAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ALWAYS_INLINE) {
    return reinterpret_cast<const AlwaysInlineAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AlwaysInlineAttr AlwaysInlineAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AlwaysInlineAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NoInlineAttr> NoInlineAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_INLINE) {
    return reinterpret_cast<const NoInlineAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoInlineAttr NoInlineAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoInlineAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ConstAttr> ConstAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_CONST) {
    return reinterpret_cast<const ConstAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ConstAttr ConstAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ConstAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LoaderUninitializedAttr> LoaderUninitializedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_LOADER_UNINITIALIZED) {
    return reinterpret_cast<const LoaderUninitializedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::LoaderUninitializedAttr LoaderUninitializedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::LoaderUninitializedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NoInstrumentFunctionAttr> NoInstrumentFunctionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_INSTRUMENT_FUNCTION) {
    return reinterpret_cast<const NoInstrumentFunctionAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoInstrumentFunctionAttr NoInstrumentFunctionAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoInstrumentFunctionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<PackedAttr> PackedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_PACKED) {
    return reinterpret_cast<const PackedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::PackedAttr PackedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::PackedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<PureAttr> PureAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_PURE) {
    return reinterpret_cast<const PureAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::PureAttr PureAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::PureAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_WARN_UNUSED_RESULT) {
    return reinterpret_cast<const WarnUnusedResultAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::WarnUnusedResultAttr WarnUnusedResultAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::WarnUnusedResultAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<RestrictAttr> RestrictAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_RESTRICT) {
    return reinterpret_cast<const RestrictAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::RestrictAttr RestrictAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::RestrictAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NoThrowAttr> NoThrowAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_THROW) {
    return reinterpret_cast<const NoThrowAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoThrowAttr NoThrowAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoThrowAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NonNullAttr> NonNullAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NON_NULL) {
    return reinterpret_cast<const NonNullAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NonNullAttr NonNullAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NonNullAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<LeafAttr> LeafAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_LEAF) {
    return reinterpret_cast<const LeafAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::LeafAttr LeafAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::LeafAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ColdAttr> ColdAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_COLD) {
    return reinterpret_cast<const ColdAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ColdAttr ColdAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ColdAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<TransparentUnionAttr> TransparentUnionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_TRANSPARENT_UNION) {
    return reinterpret_cast<const TransparentUnionAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::TransparentUnionAttr TransparentUnionAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::TransparentUnionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<ReturnsTwiceAttr> ReturnsTwiceAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_RETURNS_TWICE) {
    return reinterpret_cast<const ReturnsTwiceAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ReturnsTwiceAttr ReturnsTwiceAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ReturnsTwiceAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<MayAliasAttr> MayAliasAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_MAY_ALIAS) {
    return reinterpret_cast<const MayAliasAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::MayAliasAttr MayAliasAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::MayAliasAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<UnusedAttr> UnusedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_UNUSED) {
    return reinterpret_cast<const UnusedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::UnusedAttr UnusedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::UnusedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<UsedAttr> UsedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_USED) {
    return reinterpret_cast<const UsedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::UsedAttr UsedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::UsedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<GNUInlineAttr> GNUInlineAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_GNU_INLINE) {
    return reinterpret_cast<const GNUInlineAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::GNUInlineAttr GNUInlineAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::GNUInlineAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NoCfCheckAttr> NoCfCheckAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_CF_CHECK) {
    return reinterpret_cast<const NoCfCheckAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoCfCheckAttr NoCfCheckAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoCfCheckAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AvailableOnlyInDefaultEvalMethodAttr> AvailableOnlyInDefaultEvalMethodAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD) {
    return reinterpret_cast<const AvailableOnlyInDefaultEvalMethodAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AvailableOnlyInDefaultEvalMethodAttr AvailableOnlyInDefaultEvalMethodAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AvailableOnlyInDefaultEvalMethodAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AvailabilityAttrAttr> AvailabilityAttrAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_AVAILABILITY_ATTR) {
    return reinterpret_cast<const AvailabilityAttrAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AvailabilityAttrAttr AvailabilityAttrAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AvailabilityAttrAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<FallthroughAttr> FallthroughAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_FALLTHROUGH) {
    return reinterpret_cast<const FallthroughAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::FallthroughAttr FallthroughAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::FallthroughAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<NoProfileInstrumentFunctionAttr> NoProfileInstrumentFunctionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_PROFILE_INSTRUMENT_FUNCTION) {
    return reinterpret_cast<const NoProfileInstrumentFunctionAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoProfileInstrumentFunctionAttr NoProfileInstrumentFunctionAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoProfileInstrumentFunctionAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AsmLabelAttr> AsmLabelAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ASM_LABEL) {
    return reinterpret_cast<const AsmLabelAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AsmLabelAttr AsmLabelAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AsmLabelAttr(this->::mx::ir::Attribute::attr_);
}

bool AsmLabelAttr::is_literal(void) const {
  auto val = underlying_repr().getIsLiteral();
  return val;
}

std::optional<ModeAttr> ModeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_MODE) {
    return reinterpret_cast<const ModeAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ModeAttr ModeAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ModeAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<BuiltinAttr> BuiltinAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_BUILTIN) {
    return reinterpret_cast<const BuiltinAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::BuiltinAttr BuiltinAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::BuiltinAttr(this->::mx::ir::Attribute::attr_);
}

unsigned int BuiltinAttr::id(void) const {
  auto val = underlying_repr().getID();
  return val;
}

std::optional<AllocAlignAttr> AllocAlignAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ALLOC_ALIGN) {
    return reinterpret_cast<const AllocAlignAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AllocAlignAttr AllocAlignAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AllocAlignAttr(this->::mx::ir::Attribute::attr_);
}

int AllocAlignAttr::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<AllocSizeAttr> AllocSizeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ALLOC_SIZE) {
    return reinterpret_cast<const AllocSizeAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AllocSizeAttr AllocSizeAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AllocSizeAttr(this->::mx::ir::Attribute::attr_);
}

int AllocSizeAttr::size_arg_pos(void) const {
  auto val = underlying_repr().getSizeArgPos();
  return val;
}

int AllocSizeAttr::num_arg_pos(void) const {
  auto val = underlying_repr().getNumArgPos();
  return val;
}

std::optional<DeprecatedAttr> DeprecatedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_DEPRECATED) {
    return reinterpret_cast<const DeprecatedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::DeprecatedAttr DeprecatedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::DeprecatedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<MaxFieldAlignmentAttr> MaxFieldAlignmentAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_MAX_FIELD_ALIGNMENT) {
    return reinterpret_cast<const MaxFieldAlignmentAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::MaxFieldAlignmentAttr MaxFieldAlignmentAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::MaxFieldAlignmentAttr(this->::mx::ir::Attribute::attr_);
}

unsigned int MaxFieldAlignmentAttr::alignment(void) const {
  auto val = underlying_repr().getAlignment();
  return val;
}

std::optional<VisibilityAttr> VisibilityAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_VISIBILITY) {
    return reinterpret_cast<const VisibilityAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::VisibilityAttr VisibilityAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::VisibilityAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<AssumeAlignedAttr> AssumeAlignedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ASSUME_ALIGNED) {
    return reinterpret_cast<const AssumeAlignedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AssumeAlignedAttr AssumeAlignedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AssumeAlignedAttr(this->::mx::ir::Attribute::attr_);
}

std::optional<CVQualifiersAttr> CVQualifiersAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_CV_QUALIFIERS) {
    return reinterpret_cast<const CVQualifiersAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::CVQualifiersAttr CVQualifiersAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::CVQualifiersAttr(this->::mx::ir::Attribute::attr_);
}

bool CVQualifiersAttr::is_const(void) const {
  auto val = underlying_repr().getIsConst();
  return val;
}

bool CVQualifiersAttr::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<UCVQualifiersAttr> UCVQualifiersAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_UCV_QUALIFIERS) {
    return reinterpret_cast<const UCVQualifiersAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::UCVQualifiersAttr UCVQualifiersAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::UCVQualifiersAttr(this->::mx::ir::Attribute::attr_);
}

bool UCVQualifiersAttr::is_unsigned(void) const {
  auto val = underlying_repr().getIsUnsigned();
  return val;
}

bool UCVQualifiersAttr::is_const(void) const {
  auto val = underlying_repr().getIsConst();
  return val;
}

bool UCVQualifiersAttr::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

std::optional<CVRQualifiersAttr> CVRQualifiersAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_CVR_QUALIFIERS) {
    return reinterpret_cast<const CVRQualifiersAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::CVRQualifiersAttr CVRQualifiersAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::CVRQualifiersAttr(this->::mx::ir::Attribute::attr_);
}

bool CVRQualifiersAttr::is_const(void) const {
  auto val = underlying_repr().getIsConst();
  return val;
}

bool CVRQualifiersAttr::is_volatile(void) const {
  auto val = underlying_repr().getIsVolatile();
  return val;
}

bool CVRQualifiersAttr::is_restrict(void) const {
  auto val = underlying_repr().getIsRestrict();
  return val;
}

std::optional<OffsetOfNodeAttr> OffsetOfNodeAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_OFFSET_OF_NODE) {
    return reinterpret_cast<const OffsetOfNodeAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::OffsetOfNodeAttr OffsetOfNodeAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::OffsetOfNodeAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::hl
