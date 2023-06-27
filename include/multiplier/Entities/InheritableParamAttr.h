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
class AnnotateAttr;
class Attr;
class CFConsumedAttr;
class CarriesDependencyAttr;
class InheritableAttr;
class InheritableParamAttr;
class NSConsumedAttr;
class NonNullAttr;
class OSConsumedAttr;
class PassObjectSizeAttr;
class ReleaseHandleAttr;
class SwiftAsyncContextAttr;
class SwiftContextAttr;
class SwiftErrorResultAttr;
class SwiftIndirectResultAttr;
class Token;
class UseHandleAttr;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class InheritableParamAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<InheritableParamAttr> in(const Fragment &frag);
  static gap::generator<InheritableParamAttr> in(const File &file);
  static gap::generator<InheritableParamAttr> in(const Index &index);
  static gap::generator<InheritableParamAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<InheritableParamAttr> by_id(const Index &, EntityId);

  static std::optional<InheritableParamAttr> from(const Attr &parent);

  inline static std::optional<InheritableParamAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return InheritableParamAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<InheritableParamAttr> from(const Reference &r);
  static std::optional<InheritableParamAttr> from(const TokenContext &t);

};

static_assert(sizeof(InheritableParamAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
