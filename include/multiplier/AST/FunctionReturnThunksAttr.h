// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/FunctionReturnThunksAttrKind.h>
#include <multiplier/AST/InheritableAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class FunctionReturnThunksAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT FunctionReturnThunksAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<FunctionReturnThunksAttr> in(const Index &index);
  static gap::generator<FunctionReturnThunksAttr> in(const Fragment &frag);
  static gap::generator<FunctionReturnThunksAttr> in(const File &file);
  static gap::generator<FunctionReturnThunksAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::FUNCTION_RETURN_THUNKS;
  }

  static std::optional<FunctionReturnThunksAttr> by_id(const Index &, EntityId);

  static std::optional<FunctionReturnThunksAttr> from_base(const Attr &parent);
  inline static std::optional<FunctionReturnThunksAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<FunctionReturnThunksAttr> from(const std::optional<Attr> &parent);
  static std::optional<FunctionReturnThunksAttr> from(const Reference &r);
  static std::optional<FunctionReturnThunksAttr> from(const VariantEntity &e);
  static std::optional<FunctionReturnThunksAttr> from(const TokenContext &t);

  FunctionReturnThunksAttrKind thunk_type(void) const;
};

static_assert(sizeof(FunctionReturnThunksAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
