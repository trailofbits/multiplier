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

#include "DeclKind.h"
#include "FunctionDecl.h"

namespace mx {
class CXXConstructorDecl;
class CXXDeductionGuideDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class TemplateDecl;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXDeductionGuideDecl : public FunctionDecl {
 private:
  friend class FragmentImpl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<CXXDeductionGuideDecl> in(const Fragment &frag);
  static gap::generator<CXXDeductionGuideDecl> in(const Index &index);
  static gap::generator<CXXDeductionGuideDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  std::optional<CXXDeductionGuideDecl> by(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_DEDUCTION_GUIDE;
  }

  static gap::generator<CXXDeductionGuideDecl> containing(const Decl &decl);
  static gap::generator<CXXDeductionGuideDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<CXXDeductionGuideDecl> containing(const Stmt &stmt);
  static gap::generator<CXXDeductionGuideDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<CXXDeductionGuideDecl> redeclarations(void) const;
  inline static std::optional<CXXDeductionGuideDecl> from(const Reference &r) {
    return from(r.as_declaration());
  }

  inline static std::optional<CXXDeductionGuideDecl> from(const TokenContext &t) {
    return from(t.as_declaration());
  }

  static std::optional<CXXDeductionGuideDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXDeductionGuideDecl> from(const Decl &parent);

  inline static std::optional<CXXDeductionGuideDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXDeductionGuideDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  CXXConstructorDecl corresponding_constructor(void) const;
  TemplateDecl deduced_template(void) const;
  bool is_copy_deduction_candidate(void) const;
  bool is_explicit(void) const;
};

static_assert(sizeof(CXXDeductionGuideDecl) == sizeof(FunctionDecl));

#endif
} // namespace mx
