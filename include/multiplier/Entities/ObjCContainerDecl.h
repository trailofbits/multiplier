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

#include "DeclKind.h"
#include "NamedDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCContainerDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<ObjCContainerDecl> in(const Fragment &frag) {
    for (auto e : in_internal(frag)) {
      if (auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<ObjCContainerDecl> containing(const Token &tok) {
    for (auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if (auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ObjCContainerDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  static gap::generator<ObjCContainerDecl> containing(const Decl &decl);
  static gap::generator<ObjCContainerDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ObjCContainerDecl> from(const TokenContext &c);
  static std::optional<ObjCContainerDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCContainerDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCContainerDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCContainerDecl> from(const Decl &parent);

  inline static std::optional<ObjCContainerDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCContainerDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  std::vector<ObjCMethodDecl> class_methods(void) const;
  std::vector<ObjCPropertyDecl> class_properties(void) const;
  TokenRange at_end_range(void) const;
  Token at_start_token(void) const;
  std::vector<ObjCMethodDecl> instance_methods(void) const;
  std::vector<ObjCPropertyDecl> instance_properties(void) const;
  std::vector<ObjCMethodDecl> methods(void) const;
  std::vector<ObjCPropertyDecl> properties(void) const;
  std::vector<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(ObjCContainerDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
