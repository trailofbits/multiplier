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

#include "ArgumentWithTypeTagAttrSpelling.h"
#include "AttrKind.h"
#include "InheritableAttr.h"

namespace mx {
class ArgumentWithTypeTagAttr;
class Attr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ArgumentWithTypeTagAttrRange = DerivedEntityRange<AttrIterator, ArgumentWithTypeTagAttr>;
using ArgumentWithTypeTagAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, ArgumentWithTypeTagAttr>;
class ArgumentWithTypeTagAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static ArgumentWithTypeTagAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ArgumentWithTypeTagAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ArgumentWithTypeTagAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ARGUMENT_WITH_TYPE_TAG;
  }

  static std::optional<ArgumentWithTypeTagAttr> from(const TokenContext &c);
  static std::optional<ArgumentWithTypeTagAttr> from(const InheritableAttr &parent);

  inline static std::optional<ArgumentWithTypeTagAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return ArgumentWithTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ArgumentWithTypeTagAttr> from(const Attr &parent);

  inline static std::optional<ArgumentWithTypeTagAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ArgumentWithTypeTagAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_pointer(void) const;
  ArgumentWithTypeTagAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(ArgumentWithTypeTagAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
