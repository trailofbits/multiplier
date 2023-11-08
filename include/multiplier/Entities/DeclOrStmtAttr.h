// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class AlwaysInlineAttr;
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class NoInlineAttr;
class NoMergeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DeclOrStmtAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DeclOrStmtAttr> in(const Index &index);
  static gap::generator<DeclOrStmtAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DeclOrStmtAttr> by_id(const Index &, EntityId);
  static gap::generator<DeclOrStmtAttr> in(const Fragment &frag);
  static gap::generator<DeclOrStmtAttr> in(const File &file);

  static std::optional<DeclOrStmtAttr> from(const Attr &parent);

  inline static std::optional<DeclOrStmtAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DeclOrStmtAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DeclOrStmtAttr> from(const Reference &r);
  static std::optional<DeclOrStmtAttr> from(const TokenContext &t);

};

static_assert(sizeof(DeclOrStmtAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
