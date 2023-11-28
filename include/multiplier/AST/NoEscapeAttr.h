// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class NoEscapeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoEscapeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<NoEscapeAttr> in(const Index &index);
  static gap::generator<NoEscapeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoEscapeAttr> by_id(const Index &, EntityId);
  static gap::generator<NoEscapeAttr> in(const Fragment &frag);
  static gap::generator<NoEscapeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_ESCAPE;
  }

  static std::optional<NoEscapeAttr> from_base(const Attr &parent);
  inline static std::optional<NoEscapeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoEscapeAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoEscapeAttr> from(const Reference &r);
  static std::optional<NoEscapeAttr> from(const VariantEntity &e);
  static std::optional<NoEscapeAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoEscapeAttr) == sizeof(Attr));

#endif
} // namespace mx
