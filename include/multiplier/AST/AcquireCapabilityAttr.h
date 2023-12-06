// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/AcquireCapabilityAttrSpelling.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class AcquireCapabilityAttr;
class Attr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT AcquireCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AcquireCapabilityAttr> in(const Index &index);
  static gap::generator<AcquireCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AcquireCapabilityAttr> by_id(const Index &, EntityId);
  static gap::generator<AcquireCapabilityAttr> in(const Fragment &frag);
  static gap::generator<AcquireCapabilityAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ACQUIRE_CAPABILITY;
  }

  static std::optional<AcquireCapabilityAttr> from_base(const Attr &parent);
  inline static std::optional<AcquireCapabilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AcquireCapabilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<AcquireCapabilityAttr> from(const Reference &r);
  static std::optional<AcquireCapabilityAttr> from(const VariantEntity &e);
  static std::optional<AcquireCapabilityAttr> from(const TokenContext &t);

  AcquireCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(AcquireCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
