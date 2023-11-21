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
class AvailableOnlyInDefaultEvalMethodAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class AvailableOnlyInDefaultEvalMethodAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<AvailableOnlyInDefaultEvalMethodAttr> in(const Index &index);
  static gap::generator<AvailableOnlyInDefaultEvalMethodAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> by_id(const Index &, EntityId);
  static gap::generator<AvailableOnlyInDefaultEvalMethodAttr> in(const Fragment &frag);
  static gap::generator<AvailableOnlyInDefaultEvalMethodAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::AVAILABLE_ONLY_IN_DEFAULT_EVAL_METHOD;
  }

  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from_base(const Attr &parent);
  inline static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const std::optional<Attr> &parent);
  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const Reference &r);
  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const VariantEntity &e);
  static std::optional<AvailableOnlyInDefaultEvalMethodAttr> from(const TokenContext &t);

};

static_assert(sizeof(AvailableOnlyInDefaultEvalMethodAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
