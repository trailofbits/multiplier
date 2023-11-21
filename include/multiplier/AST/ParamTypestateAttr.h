// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "InheritableAttr.h"
#include "ParamTypestateAttrConsumedState.h"

namespace mx {
class EntityProvider;
class Index;
class Attr;
class InheritableAttr;
class ParamTypestateAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ParamTypestateAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ParamTypestateAttr> in(const Index &index);
  static gap::generator<ParamTypestateAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParamTypestateAttr> by_id(const Index &, EntityId);
  static gap::generator<ParamTypestateAttr> in(const Fragment &frag);
  static gap::generator<ParamTypestateAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::PARAM_TYPESTATE;
  }

  static std::optional<ParamTypestateAttr> from_base(const Attr &parent);
  inline static std::optional<ParamTypestateAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ParamTypestateAttr> from(const std::optional<Attr> &parent);
  static std::optional<ParamTypestateAttr> from(const Reference &r);
  static std::optional<ParamTypestateAttr> from(const VariantEntity &e);
  static std::optional<ParamTypestateAttr> from(const TokenContext &t);

  ParamTypestateAttrConsumedState parameter_state(void) const;
};

static_assert(sizeof(ParamTypestateAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
