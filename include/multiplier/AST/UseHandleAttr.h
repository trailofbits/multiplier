// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class File;
class InheritableAttr;
class InheritableParamAttr;
class Token;
class UseHandleAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT UseHandleAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UseHandleAttr> in(const Index &index);
  static gap::generator<UseHandleAttr> in(const Fragment &frag);
  static gap::generator<UseHandleAttr> in(const File &file);
  static gap::generator<UseHandleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::USE_HANDLE;
  }

  static std::optional<UseHandleAttr> by_id(const Index &, EntityId);

  static std::optional<UseHandleAttr> from_base(const Attr &parent);
  inline static std::optional<UseHandleAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<UseHandleAttr> from(const std::optional<Attr> &parent);
  static std::optional<UseHandleAttr> from(const Reference &r);
  static std::optional<UseHandleAttr> from(const VariantEntity &e);
  static std::optional<UseHandleAttr> from(const TokenContext &t);

  std::string_view handle_type(void) const;
  uint32_t handle_type_length(void) const;
};

static_assert(sizeof(UseHandleAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
