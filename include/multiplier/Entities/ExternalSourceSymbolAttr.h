// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class ExternalSourceSymbolAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ExternalSourceSymbolAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ExternalSourceSymbolAttr> in(const Fragment &frag);
  static gap::generator<ExternalSourceSymbolAttr> in(const File &file);
  static gap::generator<ExternalSourceSymbolAttr> in(const Index &index);
  static gap::generator<ExternalSourceSymbolAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ExternalSourceSymbolAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::EXTERNAL_SOURCE_SYMBOL;
  }

  static std::optional<ExternalSourceSymbolAttr> from(const Attr &parent);

  inline static std::optional<ExternalSourceSymbolAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ExternalSourceSymbolAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ExternalSourceSymbolAttr> from(const Reference &r);
  static std::optional<ExternalSourceSymbolAttr> from(const TokenContext &t);

  std::string_view defined_in(void) const;
  bool generated_declaration(void) const;
  std::string_view language(void) const;
};

static_assert(sizeof(ExternalSourceSymbolAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
