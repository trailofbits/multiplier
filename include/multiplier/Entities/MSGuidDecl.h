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

#include "DeclKind.h"
#include "ValueDecl.h"

namespace mx {
class Decl;
class MSGuidDecl;
class NamedDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MSGuidDecl : public ValueDecl {
 private:
  friend class FragmentImpl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<MSGuidDecl> in(const Fragment &frag);
  static gap::generator<MSGuidDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::MS_GUID;
  }

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<MSGuidDecl> containing(const Decl &decl);
  static gap::generator<MSGuidDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<MSGuidDecl> redeclarations(void) const;
  inline static std::optional<MSGuidDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<MSGuidDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<MSGuidDecl> from(const ValueDecl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSGuidDecl> from(const NamedDecl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<MSGuidDecl> from(const Decl &parent);

  inline static std::optional<MSGuidDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return MSGuidDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

};

static_assert(sizeof(MSGuidDecl) == sizeof(ValueDecl));

#endif
} // namespace mx
