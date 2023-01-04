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
#include "InheritableAttr.h"
#include "WarnUnusedResultAttrSpelling.h"

namespace mx {
class Attr;
class InheritableAttr;
class WarnUnusedResultAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using WarnUnusedResultAttrRange = DerivedEntityRange<AttrIterator, WarnUnusedResultAttr>;
using WarnUnusedResultAttrContainingTokenRange = DerivedEntityRange<TokenContextIterator, WarnUnusedResultAttr>;
class WarnUnusedResultAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  inline static WarnUnusedResultAttrRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static WarnUnusedResultAttrContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : WarnUnusedResultAttr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::WARN_UNUSED_RESULT;
  }

  static std::optional<WarnUnusedResultAttr> from(const TokenContext &c);
  static std::optional<WarnUnusedResultAttr> from(const InheritableAttr &parent);

  inline static std::optional<WarnUnusedResultAttr> from(const std::optional<InheritableAttr> &parent) {
    if (parent) {
      return WarnUnusedResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<WarnUnusedResultAttr> from(const Attr &parent);

  inline static std::optional<WarnUnusedResultAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return WarnUnusedResultAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  bool is_cxx11_no_discard(void) const;
  std::string_view message(void) const;
  WarnUnusedResultAttrSpelling semantic_spelling(void) const;
  std::string_view spelling(void) const;
};

static_assert(sizeof(WarnUnusedResultAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
