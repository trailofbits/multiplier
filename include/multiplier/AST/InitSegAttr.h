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
class InitSegAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InitSegAttr : public Attr {
 private:
  friend class FragmentImpl;
  friend class Attr;
 public:
  static gap::generator<InitSegAttr> in(const Index &index);
  static gap::generator<InitSegAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InitSegAttr> by_id(const Index &, EntityId);
  static gap::generator<InitSegAttr> in(const Fragment &frag);
  static gap::generator<InitSegAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::INIT_SEG;
  }

  static std::optional<InitSegAttr> from_base(const Attr &parent);
  inline static std::optional<InitSegAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<InitSegAttr> from(const std::optional<Attr> &parent);
  static std::optional<InitSegAttr> from(const Reference &r);
  static std::optional<InitSegAttr> from(const VariantEntity &e);
  static std::optional<InitSegAttr> from(const TokenContext &t);

  std::string_view section(void) const;
};

static_assert(sizeof(InitSegAttr) == sizeof(Attr));

#endif
} // namespace mx
