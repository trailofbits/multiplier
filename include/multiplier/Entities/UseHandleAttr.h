// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableParamAttr.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class Token;
class UseHandleAttr;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class UseHandleAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<UseHandleAttr> in(const Fragment &frag);
  static gap::generator<UseHandleAttr> in(const File &file);
  static gap::generator<UseHandleAttr> in(const Index &index);
  static gap::generator<UseHandleAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<UseHandleAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::USE_HANDLE;
  }

  static std::optional<UseHandleAttr> from(const Attr &parent);

  inline static std::optional<UseHandleAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return UseHandleAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<UseHandleAttr> from(const Reference &r);
  static std::optional<UseHandleAttr> from(const TokenContext &t);

  std::string_view handle_type(void) const;
};

static_assert(sizeof(UseHandleAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
