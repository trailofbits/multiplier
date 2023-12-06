// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>
#include <multiplier/AST/LoopHintAttrLoopHintState.h>
#include <multiplier/AST/LoopHintAttrOptionType.h>
#include <multiplier/AST/LoopHintAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Expr;
class LoopHintAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LoopHintAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<LoopHintAttr> in(const Index &index);
  static gap::generator<LoopHintAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LoopHintAttr> by_id(const Index &, EntityId);
  static gap::generator<LoopHintAttr> in(const Fragment &frag);
  static gap::generator<LoopHintAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOOP_HINT;
  }

  static std::optional<LoopHintAttr> from_base(const Attr &parent);
  inline static std::optional<LoopHintAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<LoopHintAttr> from(const std::optional<Attr> &parent);
  static std::optional<LoopHintAttr> from(const Reference &r);
  static std::optional<LoopHintAttr> from(const VariantEntity &e);
  static std::optional<LoopHintAttr> from(const TokenContext &t);

  LoopHintAttrOptionType option(void) const;
  LoopHintAttrSpelling semantic_spelling(void) const;
  LoopHintAttrLoopHintState state(void) const;
  std::optional<Expr> value(void) const;
};

static_assert(sizeof(LoopHintAttr) == sizeof(Attr));

#endif
} // namespace mx
