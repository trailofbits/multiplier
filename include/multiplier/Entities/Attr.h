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
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "AttrKind.h"
#include "AttrUseSelector.h"

namespace mx {
class Attr;
class PackedReaderState;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Attr {
 protected:
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class UseBase;
  friend class UseIteratorImpl;
  std::shared_ptr<PackedReaderState> package;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Attr(Attr &&) noexcept = default;
  Attr(const Attr &) = default;
  Attr &operator=(Attr &&) noexcept = default;
  Attr &operator=(const Attr &) = default;

  inline Attr(std::shared_ptr<PackedReaderState> package_, std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : package(std::move(package_)),
        fragment(std::move(fragment_)),
        offset_(offset__) {}

  inline static std::optional<Attr> from(const Attr &self) {
    return self;
  }

  inline static std::optional<Attr> from(const std::optional<Attr> &self) {
    return self;
  }

  inline static std::optional<Attr> from(const TokenContext &c) {
    return c.as_attribute();
  }

  SpecificEntityId<AttributeId> id(void) const;
  gap::generator<Use<AttrUseSelector>> uses(void) const;

 protected:
  static gap::generator<Attr> in_internal(const Fragment &fragment);

 public:
  inline static gap::generator<Attr> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<Attr> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : Attr::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
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
