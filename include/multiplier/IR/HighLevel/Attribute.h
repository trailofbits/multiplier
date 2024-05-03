// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
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
class AlwaysInlineAttr;
class ConstAttr;
class LoaderUninitializedAttr;
class NoInstrumentFunctionAttr;
class PackedAttr;
class PureAttr;
class WarnUnusedResultAttr;
class RestrictAttr;
class NoThrowAttr;
class NonNullAttr;
class AsmLabelAttr;
class ModeAttr;
class BuiltinAttr;
class AllocAlignAttr;
class AllocSizeAttr;
class CVQualifiersAttr;
class UCVQualifiersAttr;
class CVRQualifiersAttr;
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
  //unsignedint id(void) const;
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

}  // namespace mx::ir::hl
