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
class CarriesDependencyAttr;
class File;
class InheritableAttr;
class InheritableParamAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CarriesDependencyAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<CarriesDependencyAttr> in(const Index &index);
  static gap::generator<CarriesDependencyAttr> in(const Fragment &frag);
  static gap::generator<CarriesDependencyAttr> in(const File &file);
  static gap::generator<CarriesDependencyAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::CARRIES_DEPENDENCY;
  }

  static std::optional<CarriesDependencyAttr> by_id(const Index &, EntityId);

  static std::optional<CarriesDependencyAttr> from_base(const Attr &parent);
  inline static std::optional<CarriesDependencyAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<CarriesDependencyAttr> from(const std::optional<Attr> &parent);
  static std::optional<CarriesDependencyAttr> from(const Reference &r);
  static std::optional<CarriesDependencyAttr> from(const VariantEntity &e);
  static std::optional<CarriesDependencyAttr> from(const TokenContext &t);

};

static_assert(sizeof(CarriesDependencyAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
