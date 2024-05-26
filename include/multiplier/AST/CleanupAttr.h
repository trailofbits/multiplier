// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class CleanupAttr;
class File;
class FunctionDecl;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CleanupAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CleanupAttr> in(const Index &index);
  static gap::generator<CleanupAttr> in(const Fragment &frag);
  static gap::generator<CleanupAttr> in(const File &file);
  static gap::generator<CleanupAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CLEANUP;
  }

  static std::optional<CleanupAttr> by_id(const Index &, EntityId);

  static std::optional<CleanupAttr> from_base(const Attr &parent);
  inline static std::optional<CleanupAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CleanupAttr> from(const std::optional<Attr> &parent);
  static std::optional<CleanupAttr> from(const Reference &r);
  static std::optional<CleanupAttr> from(const VariantEntity &e);
  static std::optional<CleanupAttr> from(const TokenContext &t);

  FunctionDecl function_declaration(void) const;
};

static_assert(sizeof(CleanupAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
