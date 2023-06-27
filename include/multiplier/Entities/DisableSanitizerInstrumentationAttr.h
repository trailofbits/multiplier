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
class DisableSanitizerInstrumentationAttr;
class InheritableAttr;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class DisableSanitizerInstrumentationAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<DisableSanitizerInstrumentationAttr> in(const Fragment &frag);
  static gap::generator<DisableSanitizerInstrumentationAttr> in(const File &file);
  static gap::generator<DisableSanitizerInstrumentationAttr> in(const Index &index);
  static gap::generator<DisableSanitizerInstrumentationAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<DisableSanitizerInstrumentationAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::DISABLE_SANITIZER_INSTRUMENTATION;
  }

  static std::optional<DisableSanitizerInstrumentationAttr> from(const Attr &parent);

  inline static std::optional<DisableSanitizerInstrumentationAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return DisableSanitizerInstrumentationAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<DisableSanitizerInstrumentationAttr> from(const Reference &r);
  static std::optional<DisableSanitizerInstrumentationAttr> from(const TokenContext &t);

};

static_assert(sizeof(DisableSanitizerInstrumentationAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
