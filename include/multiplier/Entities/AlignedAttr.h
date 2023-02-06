// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AlignedAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class AlignedAttr;
class Attr;
class Expr;
class InheritableAttr;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlignedAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AlignedAttr> in(const Fragment &frag);
  static gap::generator<AlignedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALIGNED;
  }

  inline static std::optional<AlignedAttr> from(const Reference &r) {
    return from(r.as_attribute());
  }

  inline static std::optional<AlignedAttr> from(const TokenContext &t) {
    return from(t.as_attribute());
  }

  static std::optional<AlignedAttr> from(const InheritableAttr &parent);

  inline static std::optional<AlignedAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return AlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AlignedAttr> from(const Attr &parent);

  inline static std::optional<AlignedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlignedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::optional<Expr> alignment_expression(void) const;
  std::optional<Type> alignment_type(void) const;
  AlignedAttrSpelling semantic_spelling(void) const;
  bool is_alignas(void) const;
  bool is_alignment_dependent(void) const;
  bool is_alignment_error_dependent(void) const;
  bool is_alignment_expression(void) const;
  bool is_c11(void) const;
  bool is_declspec(void) const;
  bool is_gnu(void) const;
};

static_assert(sizeof(AlignedAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
