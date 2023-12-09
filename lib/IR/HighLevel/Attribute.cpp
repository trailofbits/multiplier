// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Attribute.h>

#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>

namespace mx::ir::hl {
std::optional<Attribute> Attribute::from(const ::mx::ir::Attribute &that) {
  if (IsHighLevelAttributeKind(that.kind())) {
    return reinterpret_cast<const Attribute &>(that);
  }
  return std::nullopt;
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

std::optional<AnnotationAttr> AnnotationAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_ANNOTATION) {
    return reinterpret_cast<const AnnotationAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::AnnotationAttr AnnotationAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::AnnotationAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<BuiltinAttr> BuiltinAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_BUILTIN) {
    return reinterpret_cast<const BuiltinAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::BuiltinAttr BuiltinAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::BuiltinAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<ConstAttr> ConstAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_CONST) {
    return reinterpret_cast<const ConstAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::ConstAttr ConstAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::ConstAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<LoaderUninitializedAttr> LoaderUninitializedAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_LOADER_UNINITIALIZED) {
    return reinterpret_cast<const LoaderUninitializedAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::LoaderUninitializedAttr LoaderUninitializedAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::LoaderUninitializedAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<NoInstrumentFunctionAttr> NoInstrumentFunctionAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_NO_INSTRUMENT_FUNCTION) {
    return reinterpret_cast<const NoInstrumentFunctionAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::NoInstrumentFunctionAttr NoInstrumentFunctionAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::NoInstrumentFunctionAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<RestrictAttr> RestrictAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_RESTRICT) {
    return reinterpret_cast<const RestrictAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::RestrictAttr RestrictAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::RestrictAttr(this->::mx::ir::Attribute::attr_);
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

std::optional<WarnUnusedResultAttr> WarnUnusedResultAttr::from(const ::mx::ir::Attribute &that) {
  if (that.kind() == AttributeKind::HL_WARN_UNUSED_RESULT) {
    return reinterpret_cast<const WarnUnusedResultAttr &>(that);
  }
  return std::nullopt;
}

::vast::hl::WarnUnusedResultAttr WarnUnusedResultAttr::underlying_repr(void) const noexcept {
  return ::vast::hl::WarnUnusedResultAttr(this->::mx::ir::Attribute::attr_);
}

}  // namespace mx::ir::hl
