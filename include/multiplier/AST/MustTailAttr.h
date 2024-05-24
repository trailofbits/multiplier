// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class File;
class MustTailAttr;
class StmtAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT MustTailAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<MustTailAttr> in(const Index &index);
  static gap::generator<MustTailAttr> in(const Fragment &frag);
  static gap::generator<MustTailAttr> in(const File &file);
  static gap::generator<MustTailAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::MUST_TAIL;
  }

  static std::optional<MustTailAttr> by_id(const Index &, EntityId);

  static std::optional<MustTailAttr> from_base(const Attr &parent);
  inline static std::optional<MustTailAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<MustTailAttr> from(const std::optional<Attr> &parent);
  static std::optional<MustTailAttr> from(const Reference &r);
  static std::optional<MustTailAttr> from(const VariantEntity &e);
  static std::optional<MustTailAttr> from(const TokenContext &t);

};

static_assert(sizeof(MustTailAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
