// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "CXX11NoReturnAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class CXX11NoReturnAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXX11NoReturnAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CXX11NoReturnAttr> in(const Index &index);
  static gap::generator<CXX11NoReturnAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<CXX11NoReturnAttr> by_id(const Index &, EntityId);
  static gap::generator<CXX11NoReturnAttr> in(const Fragment &frag);
  static gap::generator<CXX11NoReturnAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CXX11_NO_RETURN;
  }

  static std::optional<CXX11NoReturnAttr> from(const Attr &parent);

  inline static std::optional<CXX11NoReturnAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return CXX11NoReturnAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXX11NoReturnAttr> from(const Reference &r);
  static std::optional<CXX11NoReturnAttr> from(const TokenContext &t);

  CXX11NoReturnAttrSpelling semantic_spelling(void) const;
};

static_assert(sizeof(CXX11NoReturnAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
