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

#include "MacroKind.h"
#include "MacroUseSelector.h"

namespace mx {
class Macro;
class OffsetEntityImpl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using MacroOrToken = std::variant<Macro, Token>;
class Macro {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class UseBase;
  friend class UseIteratorImpl;
  std::shared_ptr<OffsetEntityImpl> impl;
 public:
  Macro(Macro &&) noexcept = default;
  Macro(const Macro &) = default;
  Macro &operator=(Macro &&) noexcept = default;
  Macro &operator=(const Macro &) = default;

  inline Macro(std::shared_ptr<OffsetEntityImpl> impl_)
      : impl(std::move(impl_)) {}

  inline static std::optional<Macro> from(const Macro &self) {
    return self;
  }

  inline static std::optional<Macro> from(const std::optional<Macro> &self) {
    return self;
  }

  SpecificEntityId<MacroId> id(void) const;
  gap::generator<Use<MacroUseSelector>> uses(void) const;

 protected:
  static gap::generator<Macro> in_internal(const Fragment &fragment);
  static gap::generator<Macro> containing_internal(const Token &token);

 public:
  inline static gap::generator<Macro> in(const Fragment &frag) {
    for (auto m : in_internal(frag)) {
      if (auto d = from(m)) {
        co_yield *d;
      }
    }
  }

  static gap::generator<Macro> containing(const Macro &macro);
  bool contains(const Macro &macro);

  static gap::generator<Macro> containing(const Token &token);
  bool contains(const Token &token);

  MacroKind kind(void) const;
  std::optional<Macro> parent(void) const;
  gap::generator<MacroOrToken> children(void) const;
};

#endif
} // namespace mx
