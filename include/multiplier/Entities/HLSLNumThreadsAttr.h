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
class HLSLNumThreadsAttr;
class InheritableAttr;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class HLSLNumThreadsAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<HLSLNumThreadsAttr> in(const Index &index);
  static gap::generator<HLSLNumThreadsAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<HLSLNumThreadsAttr> by_id(const Index &, EntityId);
  static gap::generator<HLSLNumThreadsAttr> in(const Fragment &frag);
  static gap::generator<HLSLNumThreadsAttr> in(const File &file);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::HLSL_NUM_THREADS;
  }

  static std::optional<HLSLNumThreadsAttr> from(const Attr &parent);

  inline static std::optional<HLSLNumThreadsAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return HLSLNumThreadsAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<HLSLNumThreadsAttr> from(const Reference &r);
  static std::optional<HLSLNumThreadsAttr> from(const TokenContext &t);

};

static_assert(sizeof(HLSLNumThreadsAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
