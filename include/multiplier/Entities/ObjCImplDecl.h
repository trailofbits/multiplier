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
#include "ObjCContainerDecl.h"

namespace mx {
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCInterfaceDecl;
class ObjCPropertyImplDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCImplDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCImplDecl> in(const Fragment &frag);
  static gap::generator<ObjCImplDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<DeclKind> derived_kinds(void);
  static gap::generator<ObjCImplDecl> containing(const Decl &decl);
  static gap::generator<ObjCImplDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCImplDecl> redeclarations(void) const;
  inline static std::optional<ObjCImplDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCImplDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ObjCImplDecl> from(const ObjCContainerDecl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<ObjCContainerDecl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplDecl> from(const NamedDecl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  ObjCInterfaceDecl class_interface(void) const;
  std::optional<ObjCPropertyImplDecl> nth_property_implementation(unsigned n) const;
  gap::generator<ObjCPropertyImplDecl> property_implementations(void) const;
};

static_assert(sizeof(ObjCImplDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
