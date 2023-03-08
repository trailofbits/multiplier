// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "DeclOrStmtAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class NoInlineAttr;
class Token;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoInlineAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoInlineAttr> in(const Fragment &frag);
  static gap::generator<NoInlineAttr> in(const File &file);
  static gap::generator<NoInlineAttr> in(const Index &index);
  static gap::generator<NoInlineAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoInlineAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_INLINE;
  }

  static std::optional<NoInlineAttr> from(const Attr &parent);

  inline static std::optional<NoInlineAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NoInlineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<NoInlineAttr> from(const Reference &r);
  static std::optional<NoInlineAttr> from(const TokenContext &t);

  bool is_clang_no_inline(void) const;
};

static_assert(sizeof(NoInlineAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
