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
  static gap::generator<ObjCContainerDecl> in(const Fragment &frag);
  static gap::generator<ObjCContainerDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static gap::generator<ObjCContainerDecl> containing(const Decl &decl);
  static gap::generator<ObjCContainerDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ObjCContainerDecl> redeclarations(void) const;
  inline static std::optional<ObjCContainerDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ObjCContainerDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

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

  std::optional<ObjCMethodDecl> nth_class_method(unsigned n) const;
  gap::generator<ObjCMethodDecl> class_methods(void) const;
  std::optional<ObjCPropertyDecl> nth_class_propertie(unsigned n) const;
  gap::generator<ObjCPropertyDecl> class_properties(void) const;
  TokenRange at_end_range(void) const;
  Token at_start_token(void) const;
  std::optional<ObjCMethodDecl> nth_instance_method(unsigned n) const;
  gap::generator<ObjCMethodDecl> instance_methods(void) const;
  std::optional<ObjCPropertyDecl> nth_instance_propertie(unsigned n) const;
  gap::generator<ObjCPropertyDecl> instance_properties(void) const;
  std::optional<ObjCMethodDecl> nth_method(unsigned n) const;
  gap::generator<ObjCMethodDecl> methods(void) const;
  std::optional<ObjCPropertyDecl> nth_propertie(unsigned n) const;
  gap::generator<ObjCPropertyDecl> properties(void) const;
  gap::generator<Decl> declarations_in_context(void) const;
};

static_assert(sizeof(ObjCContainerDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
