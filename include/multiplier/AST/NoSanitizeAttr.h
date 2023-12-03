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
class InheritableAttr;
class NoSanitizeAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT NoSanitizeAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NoSanitizeAttr> in(const Index &index);
  static gap::generator<NoSanitizeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NoSanitizeAttr> by_id(const Index &, EntityId);
  static gap::generator<NoSanitizeAttr> in(const Fragment &frag);
  static gap::generator<NoSanitizeAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NO_SANITIZE;
  }

  static std::optional<NoSanitizeAttr> from_base(const Attr &parent);
  inline static std::optional<NoSanitizeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<NoSanitizeAttr> from(const std::optional<Attr> &parent);
  static std::optional<NoSanitizeAttr> from(const Reference &r);
  static std::optional<NoSanitizeAttr> from(const VariantEntity &e);
  static std::optional<NoSanitizeAttr> from(const TokenContext &t);

  bool has_coverage(void) const;
};

static_assert(sizeof(NoSanitizeAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
