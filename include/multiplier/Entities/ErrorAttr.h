// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ErrorAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ErrorAttr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ErrorAttr> in(const Fragment &frag);
  static gap::generator<ErrorAttr> in(const File &file);
  static gap::generator<ErrorAttr> in(const Index &index);
  static gap::generator<ErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ErrorAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ERROR;
  }

  static std::optional<ErrorAttr> from(const Attr &parent);

  inline static std::optional<ErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ErrorAttr> from(const Reference &r);
  static std::optional<ErrorAttr> from(const TokenContext &t);

  ErrorAttrSpelling semantic_spelling(void) const;
  std::string_view user_diagnostic(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(ErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
