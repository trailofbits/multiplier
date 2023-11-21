// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "DeclOrStmtAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class DeclOrStmtAttr;
class InheritableAttr;
class NoMergeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NoMergeAttr : public DeclOrStmtAttr {
 private:
  friend class FragmentImpl;
  friend class DeclOrStmtAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoMergeAttr> in(const Index &index);
  static gap::generator<NoMergeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoMergeAttr> by_id(const Index &, EntityId);
  static gap::generator<NoMergeAttr> in(const Fragment &frag);
  static gap::generator<NoMergeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_MERGE;
  }

  static std::optional<NoMergeAttr> from_base(const Attr &parent);
  inline static std::optional<NoMergeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoMergeAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoMergeAttr> from(const Reference &r);
  static std::optional<NoMergeAttr> from(const VariantEntity &e);
  static std::optional<NoMergeAttr> from(const TokenContext &t);

};

static_assert(sizeof(NoMergeAttr) == sizeof(DeclOrStmtAttr));

#endif
} // namespace mx
