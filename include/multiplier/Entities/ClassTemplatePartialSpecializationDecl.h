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

#include "ClassTemplateSpecializationDecl.h"
#include "DeclKind.h"

namespace mx {
class CXXRecordDecl;
class ClassTemplatePartialSpecializationDecl;
class ClassTemplateSpecializationDecl;
class Decl;
class NamedDecl;
class RecordDecl;
class TagDecl;
class TemplateParameterList;
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ClassTemplatePartialSpecializationDecl : public ClassTemplateSpecializationDecl {
 private:
  friend class FragmentImpl;
  friend class ClassTemplateSpecializationDecl;
  friend class CXXRecordDecl;
  friend class RecordDecl;
  friend class TagDecl;
  friend class TypeDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const Fragment &frag);
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const File &file);
  static gap::generator<ClassTemplatePartialSpecializationDecl> in(const Index &index);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ClassTemplatePartialSpecializationDecl> by_id(const Index &, EntityId);

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
  }

  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Decl &decl);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const Stmt &stmt);
  static gap::generator<ClassTemplatePartialSpecializationDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  gap::generator<ClassTemplatePartialSpecializationDecl> redeclarations(void) const;
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const Decl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const Reference &r) {
    return ClassTemplatePartialSpecializationDecl::from(r.as_declaration());
  }

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const TokenContext &t) {
    return ClassTemplatePartialSpecializationDecl::from(t.as_declaration());
  }

  Type injected_specialization_type(void) const;
  ClassTemplatePartialSpecializationDecl instantiated_from_member(void) const;
  ClassTemplatePartialSpecializationDecl instantiated_from_member_template(void) const;
  TemplateParameterList template_parameters(void) const;
  bool has_associated_constraints(void) const;
};

static_assert(sizeof(ClassTemplatePartialSpecializationDecl) == sizeof(ClassTemplateSpecializationDecl));

#endif
} // namespace mx
