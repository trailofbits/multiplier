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

#include "Decl.h"
#include "DeclKind.h"

namespace mx {
class CXXMethodDecl;
class ClassScopeFunctionSpecializationDecl;
class Decl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ClassScopeFunctionSpecializationDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<ClassScopeFunctionSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ClassScopeFunctionSpecializationDecl> in(const Index &index);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<ClassScopeFunctionSpecializationDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_SCOPE_FUNCTION_SPECIALIZATION;
  }

  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<ClassScopeFunctionSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ClassScopeFunctionSpecializationDecl> redeclarations(void) const;
  inline static std::optional<ClassScopeFunctionSpecializationDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<ClassScopeFunctionSpecializationDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<ClassScopeFunctionSpecializationDecl> from(const Decl &parent);

  inline static std::optional<ClassScopeFunctionSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassScopeFunctionSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CXXMethodDecl specialization(void) const;
  bool has_explicit_template_arguments(void) const;
};

static_assert(sizeof(ClassScopeFunctionSpecializationDecl) == sizeof(Decl));

#endif
} // namespace mx
