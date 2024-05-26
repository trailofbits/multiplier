// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
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
class Token;
class TypeAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT TypeAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<TypeAttr> in(const Index &index);
  static gap::generator<TypeAttr> in(const Fragment &frag);
  static gap::generator<TypeAttr> in(const File &file);
  static gap::generator<TypeAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<TypeAttr> by_id(const Index &, EntityId);

  static std::optional<TypeAttr> from_base(const Attr &parent);
  inline static std::optional<TypeAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<TypeAttr> from(const std::optional<Attr> &parent);
  static std::optional<TypeAttr> from(const Reference &r);
  static std::optional<TypeAttr> from(const VariantEntity &e);
  static std::optional<TypeAttr> from(const TokenContext &t);

};

static_assert(sizeof(TypeAttr) == sizeof(Attr));

#endif
} // namespace mx
