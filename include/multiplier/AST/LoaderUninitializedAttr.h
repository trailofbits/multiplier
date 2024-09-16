// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Attr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class LoaderUninitializedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT LoaderUninitializedAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<LoaderUninitializedAttr> in(const Index &index);
  static gap::generator<LoaderUninitializedAttr> in(const Fragment &frag);
  static gap::generator<LoaderUninitializedAttr> in(const File &file);
  static gap::generator<LoaderUninitializedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOADER_UNINITIALIZED;
  }

  static std::optional<LoaderUninitializedAttr> by_id(const Index &, EntityId);

  static std::optional<LoaderUninitializedAttr> from_base(const Attr &parent);
  inline static std::optional<LoaderUninitializedAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<LoaderUninitializedAttr> from(const std::optional<Attr> &parent);
  static std::optional<LoaderUninitializedAttr> from(const Reference &r);
  static std::optional<LoaderUninitializedAttr> from(const VariantEntity &e);
  static std::optional<LoaderUninitializedAttr> from(const TokenContext &t);

};

static_assert(sizeof(LoaderUninitializedAttr) == sizeof(Attr));

#endif
} // namespace mx
