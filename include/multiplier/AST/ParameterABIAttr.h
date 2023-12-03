// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/InheritableParamAttr.h>
#include <multiplier/AST/ParameterABI.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Attr;
class InheritableAttr;
class InheritableParamAttr;
class ParameterABIAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT ParameterABIAttr : public InheritableParamAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableParamAttr;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ParameterABIAttr> in(const Index &index);
  static gap::generator<ParameterABIAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ParameterABIAttr> by_id(const Index &, EntityId);
  static gap::generator<ParameterABIAttr> in(const Fragment &frag);
  static gap::generator<ParameterABIAttr> in(const File &file);

  static std::optional<ParameterABIAttr> from_base(const Attr &parent);
  inline static std::optional<ParameterABIAttr> from(const Attr &parent) {
    return from_base(parent);
  }
  static std::optional<ParameterABIAttr> from(const std::optional<Attr> &parent);
  static std::optional<ParameterABIAttr> from(const Reference &r);
  static std::optional<ParameterABIAttr> from(const VariantEntity &e);
  static std::optional<ParameterABIAttr> from(const TokenContext &t);

  ParameterABI abi(void) const;
};

static_assert(sizeof(ParameterABIAttr) == sizeof(InheritableParamAttr));

#endif
} // namespace mx
