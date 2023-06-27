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
class PipeType;
class Token;
class Type;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class PipeType : public Type {
 private:
  friend class FragmentImpl;
  friend class Type;
 public:
  static gap::generator<PipeType> in(const Fragment &frag);
  static gap::generator<PipeType> in(const File &file);
  static gap::generator<PipeType> in(const Index &index);
  static gap::generator<PipeType> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<PipeType> by_id(const Index &, EntityId);

  inline static constexpr TypeKind static_kind(void) {
    return TypeKind::PIPE;
  }

  static std::optional<PipeType> from(const Type &parent);

  inline static std::optional<PipeType> from(const std::optional<Type> &parent) {
    if (parent) {
      return PipeType::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<PipeType> from(const Reference &r);
  static std::optional<PipeType> from(const TokenContext &t);

  Type desugar(void) const;
  Type element_type(void) const;
  bool is_read_only(void) const;
  bool is_sugared(void) const;
};

static_assert(sizeof(PipeType) == sizeof(Type));

#endif
} // namespace mx
