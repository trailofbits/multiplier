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
class FallThroughAttr;
class File;
class StmtAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FallThroughAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<FallThroughAttr> in(const Index &index);
  static gap::generator<FallThroughAttr> in(const Fragment &frag);
  static gap::generator<FallThroughAttr> in(const File &file);
  static gap::generator<FallThroughAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FALL_THROUGH;
  }

  static std::optional<FallThroughAttr> by_id(const Index &, EntityId);

  static std::optional<FallThroughAttr> from_base(const Attr &parent);
  inline static std::optional<FallThroughAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<FallThroughAttr> from(const std::optional<Attr> &parent);
  static std::optional<FallThroughAttr> from(const Reference &r);
  static std::optional<FallThroughAttr> from(const VariantEntity &e);
  static std::optional<FallThroughAttr> from(const TokenContext &t);

};

static_assert(sizeof(FallThroughAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
