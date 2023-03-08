// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "InheritableAttr.h"

namespace mx {
class Attr;
class InheritableAttr;
class NSErrorDomainAttr;
class Token;
class VarDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class NSErrorDomainAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<NSErrorDomainAttr> in(const Fragment &frag);
  static gap::generator<NSErrorDomainAttr> in(const File &file);
  static gap::generator<NSErrorDomainAttr> in(const Index &index);
  static gap::generator<NSErrorDomainAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<NSErrorDomainAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::NS_ERROR_DOMAIN;
  }

  static std::optional<NSErrorDomainAttr> from(const Attr &parent);

  inline static std::optional<NSErrorDomainAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return NSErrorDomainAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<NSErrorDomainAttr> from(const Reference &r) {
    return NSErrorDomainAttr::from(r.as_attribute());
  }

  inline static std::optional<NSErrorDomainAttr> from(const TokenContext &t) {
    return NSErrorDomainAttr::from(t.as_attribute());
  }

  VarDecl error_domain(void) const;
};

static_assert(sizeof(NSErrorDomainAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
