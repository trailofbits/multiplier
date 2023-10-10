// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "StmtAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class FallThroughAttr;
class StmtAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class FallThroughAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<FallThroughAttr> in(const Index &index);
  static gap::generator<FallThroughAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<FallThroughAttr> by_id(const Index &, EntityId);
  static gap::generator<FallThroughAttr> in(const Fragment &frag);
  static gap::generator<FallThroughAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FALL_THROUGH;
  }

  static std::optional<FallThroughAttr> from(const Attr &parent);

  inline static std::optional<FallThroughAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return FallThroughAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<FallThroughAttr> from(const Reference &r);
  static std::optional<FallThroughAttr> from(const TokenContext &t);

};

static_assert(sizeof(FallThroughAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
