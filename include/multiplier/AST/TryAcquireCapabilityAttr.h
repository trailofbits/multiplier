// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/TryAcquireCapabilityAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class Expr;
class InheritableAttr;
class Token;
class TryAcquireCapabilityAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class TryAcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<TryAcquireCapabilityAttr> in(const Index &index);
  static gap::generator<TryAcquireCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<TryAcquireCapabilityAttr> by_id(const Index &, EntityId);
  static gap::generator<TryAcquireCapabilityAttr> in(const Fragment &frag);
  static gap::generator<TryAcquireCapabilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::TRY_ACQUIRE_CAPABILITY;
  }

  static std::optional<TryAcquireCapabilityAttr> from_base(const Attr &parent);
  inline static std::optional<TryAcquireCapabilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<TryAcquireCapabilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<TryAcquireCapabilityAttr> from(const Reference &r);
  static std::optional<TryAcquireCapabilityAttr> from(const VariantEntity &e);
  static std::optional<TryAcquireCapabilityAttr> from(const TokenContext &t);

  TryAcquireCapabilityAttrSpelling semantic_spelling(void) const;
  Expr success_value(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(TryAcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
