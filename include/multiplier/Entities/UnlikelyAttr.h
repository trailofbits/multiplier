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
class StmtAttr;
class Token;
class UnlikelyAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UnlikelyAttr : public StmtAttr {
 private:
  friend class FragmentImpl;
  friend class StmtAttr;
  friend class Attr;
 public:
  static gap::generator<UnlikelyAttr> in(const Index &index);
  static gap::generator<UnlikelyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UnlikelyAttr> by_id(const Index &, EntityId);
  static gap::generator<UnlikelyAttr> in(const Fragment &frag);
  static gap::generator<UnlikelyAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::UNLIKELY;
  }

  static std::optional<UnlikelyAttr> from(const Attr &parent);

  inline static std::optional<UnlikelyAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UnlikelyAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UnlikelyAttr> from(const Reference &r);
  static std::optional<UnlikelyAttr> from(const TokenContext &t);

};

static_assert(sizeof(UnlikelyAttr) == sizeof(StmtAttr));

#endif
} // namespace mx
