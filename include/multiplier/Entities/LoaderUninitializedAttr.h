// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Attr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class LoaderUninitializedAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class LoaderUninitializedAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<LoaderUninitializedAttr> in(const Index &index);
  static gap::generator<LoaderUninitializedAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<LoaderUninitializedAttr> by_id(const Index &, EntityId);
  static gap::generator<LoaderUninitializedAttr> in(const Fragment &frag);
  static gap::generator<LoaderUninitializedAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::LOADER_UNINITIALIZED;
  }

  static std::optional<LoaderUninitializedAttr> from(const Attr &parent);

  inline static std::optional<LoaderUninitializedAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return LoaderUninitializedAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<LoaderUninitializedAttr> from(const Reference &r);
  static std::optional<LoaderUninitializedAttr> from(const TokenContext &t);

};

static_assert(sizeof(LoaderUninitializedAttr) == sizeof(Attr));

#endif
} // namespace mx
