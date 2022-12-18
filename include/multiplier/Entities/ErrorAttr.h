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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "ErrorAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ErrorAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ErrorAttrRange = DerivedEntityRange<AttrIterator, ErrorAttr>;
using ErrorAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ErrorAttr>;
class ErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ErrorAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ErrorAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(TokenContext::of(tok));
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ErrorAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ERROR;
  }

  static std::optional<ErrorAttr> from(const TokenContext &c);
  static std::optional<ErrorAttr> from(const InheritableAttr &parent);

  inline static std::optional<ErrorAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ErrorAttr> from(const Attr &parent);

  inline static std::optional<ErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ErrorAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
  std::string_view user_diagnostic(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(ErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
