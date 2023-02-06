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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"

namespace mx {
class Attr;
class AttrImpl;
class Reference;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Attr {
 protected:
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class Reference;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class AttrImpl;
  std::shared_ptr<const AttrImpl> impl;
 public:
  Attr(Attr &&) noexcept = default;
  Attr(const Attr &) = default;
  Attr &operator=(Attr &&) noexcept = default;
  Attr &operator=(const Attr &) = default;

  /* implicit */ inline Attr(std::shared_ptr<const AttrImpl> impl_)
      : impl(std::move(impl_)) {}

  PackedAttrId id(void) const;
  gap::generator<Reference> references(void) const;

 protected:
  static gap::generator<Attr> in_internal(const Fragment &fragment);

 public:
  static gap::generator<Attr> in(const Fragment &frag);
  static gap::generator<Attr> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static std::optional<Attr> from(const Attr &self) {
    return self;
  }

  inline static std::optional<Attr> from(const std::optional<Attr> &self) {
    return self;
  }

  inline static std::optional<Attr> from(const Reference &r) {
    return r.as_attribute();
  }

  inline static std::optional<Attr> from(const TokenContext &t) {
    return t.as_attribute();
  }

  Token token(void) const;
  bool is_implicit(void) const;
  bool is_inherited(void) const;
  bool is_late_parsed(void) const;
  bool is_pack_expansion(void) const;
  AttrKind kind(void) const;
  TokenRange tokens(void) const;
};

#endif
} // namespace mx
