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
class File;
class InheritableAttr;
class OMPThreadPrivateDeclAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPThreadPrivateDeclAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<OMPThreadPrivateDeclAttr> in(const Index &index);
  static gap::generator<OMPThreadPrivateDeclAttr> in(const Fragment &frag);
  static gap::generator<OMPThreadPrivateDeclAttr> in(const File &file);
  static gap::generator<OMPThreadPrivateDeclAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::OMP_THREAD_PRIVATE_DECL;
  }

  static std::optional<OMPThreadPrivateDeclAttr> by_id(const Index &, EntityId);

  static std::optional<OMPThreadPrivateDeclAttr> from_base(const Attr &parent);
  inline static std::optional<OMPThreadPrivateDeclAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<OMPThreadPrivateDeclAttr> from(const std::optional<Attr> &parent);
  static std::optional<OMPThreadPrivateDeclAttr> from(const Reference &r);
  static std::optional<OMPThreadPrivateDeclAttr> from(const VariantEntity &e);
  static std::optional<OMPThreadPrivateDeclAttr> from(const TokenContext &t);

};

static_assert(sizeof(OMPThreadPrivateDeclAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
