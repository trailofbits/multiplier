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
class IFuncAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT IFuncAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<IFuncAttr> in(const Index &index);
  static gap::generator<IFuncAttr> in(const Fragment &frag);
  static gap::generator<IFuncAttr> in(const File &file);
  static gap::generator<IFuncAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::I_FUNC;
  }

  static std::optional<IFuncAttr> by_id(const Index &, EntityId);

  static std::optional<IFuncAttr> from_base(const Attr &parent);
  inline static std::optional<IFuncAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<IFuncAttr> from(const std::optional<Attr> &parent);
  static std::optional<IFuncAttr> from(const Reference &r);
  static std::optional<IFuncAttr> from(const VariantEntity &e);
  static std::optional<IFuncAttr> from(const TokenContext &t);

  std::string_view resolver(void) const;
};

static_assert(sizeof(IFuncAttr) == sizeof(Attr));

#endif
} // namespace mx
