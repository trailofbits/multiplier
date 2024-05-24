// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableAttr.h>
#include <multiplier/AST/ReleaseCapabilityAttrSpelling.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class ReleaseCapabilityAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ReleaseCapabilityAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ReleaseCapabilityAttr> in(const Index &index);
  static gap::generator<ReleaseCapabilityAttr> in(const Fragment &frag);
  static gap::generator<ReleaseCapabilityAttr> in(const File &file);
  static gap::generator<ReleaseCapabilityAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::RELEASE_CAPABILITY;
  }

  static std::optional<ReleaseCapabilityAttr> by_id(const Index &, EntityId);

  static std::optional<ReleaseCapabilityAttr> from_base(const Attr &parent);
  inline static std::optional<ReleaseCapabilityAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ReleaseCapabilityAttr> from(const std::optional<Attr> &parent);
  static std::optional<ReleaseCapabilityAttr> from(const Reference &r);
  static std::optional<ReleaseCapabilityAttr> from(const VariantEntity &e);
  static std::optional<ReleaseCapabilityAttr> from(const TokenContext &t);

  ReleaseCapabilityAttrSpelling semantic_spelling(void) const;
  bool is_generic(void) const;
  bool is_shared(void) const;
};

static_assert(sizeof(ReleaseCapabilityAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
