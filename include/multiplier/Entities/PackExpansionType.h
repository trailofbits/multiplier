// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "Type.h"

namespace mx {
class EntityProvider;
class Index;
class PackExpansionType;
class Token;
class Type;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PackExpansionType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<PackExpansionType> in(const Fragment &frag);
  static gap::generator<PackExpansionType> in(const File &file);
  static gap::generator<PackExpansionType> in(const Index &index);
  static gap::generator<PackExpansionType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PackExpansionType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::PACK_EXPANSION;
  }

  static std::optional<PackExpansionType> from(const Type &parent);

  inline static std::optional<PackExpansionType> from(const std::optional<Type> &parent) {
    if (parent) {
      return PackExpansionType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PackExpansionType> from(const Reference &r);
  static std::optional<PackExpansionType> from(const TokenContext &t);

  Type desugar(void) const;
  Type pattern(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(PackExpansionType) == sizeof(Type));

#endif
} // namespace mx
