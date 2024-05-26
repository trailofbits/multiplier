// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/DeclOrStmtAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class DeclOrStmtAttr;
class File;
class InheritableAttr;
class NoInlineAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NoInlineAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoInlineAttr> in(const Index &index);
  static gap::generator<NoInlineAttr> in(const Fragment &frag);
  static gap::generator<NoInlineAttr> in(const File &file);
  static gap::generator<NoInlineAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_INLINE;
  }

  static std::optional<NoInlineAttr> by_id(const Index &, EntityId);

  static std::optional<NoInlineAttr> from_base(const Attr &parent);
  inline static std::optional<NoInlineAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoInlineAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoInlineAttr> from(const Reference &r);
  static std::optional<NoInlineAttr> from(const VariantEntity &e);
  static std::optional<NoInlineAttr> from(const TokenContext &t);

  bool is_clang_no_inline(void) const;
};

static_assert(sizeof(NoInlineAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
