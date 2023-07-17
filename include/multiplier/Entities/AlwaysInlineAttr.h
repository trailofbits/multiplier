// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "AlwaysInlineAttrSpelling.h"
#include "DeclOrStmtAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AlwaysInlineAttr;
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AlwaysInlineAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AlwaysInlineAttr> in(const Fragment &frag);
  static gap::generator<AlwaysInlineAttr> in(const File &file);
  static gap::generator<AlwaysInlineAttr> in(const Index &index);
  static gap::generator<AlwaysInlineAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AlwaysInlineAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ALWAYS_INLINE;
  }

  static std::optional<AlwaysInlineAttr> from(const Attr &parent);

  inline static std::optional<AlwaysInlineAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return AlwaysInlineAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<AlwaysInlineAttr> from(const Reference &r);
  static std::optional<AlwaysInlineAttr> from(const TokenContext &t);

  AlwaysInlineAttrSpelling semantic_spelling(void) const;
  bool is_clang_always_inline(void) const;
};

static_assert(sizeof(AlwaysInlineAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
