// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/StmtAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class CodeAlignAttr;
class Expr;
class File;
class StmtAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CodeAlignAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<CodeAlignAttr> in(const Index &index);
  static gap::generator<CodeAlignAttr> in(const Fragment &frag);
  static gap::generator<CodeAlignAttr> in(const File &file);
  static gap::generator<CodeAlignAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CODE_ALIGN;
  }

  static std::optional<CodeAlignAttr> by_id(const Index &, EntityId);

  static std::optional<CodeAlignAttr> from_base(const Attr &parent);
  inline static std::optional<CodeAlignAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CodeAlignAttr> from(const std::optional<Attr> &parent);
  static std::optional<CodeAlignAttr> from(const Reference &r);
  static std::optional<CodeAlignAttr> from(const VariantEntity &e);
  static std::optional<CodeAlignAttr> from(const TokenContext &t);

  Expr alignment(void) const;
};

static_assert(sizeof(CodeAlignAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
