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

#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

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
class Type;
class TypeDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
using ClassTemplatePartialSpecializationDeclRange = DerivedEntityRange<DeclIterator, ClassTemplatePartialSpecializationDecl>;
using ClassTemplatePartialSpecializationDeclContainingTokenRange = DerivedEntityRange<TokenContextIterator, ClassTemplatePartialSpecializationDecl>;
using ClassTemplatePartialSpecializationDeclContainingDeclRange = DerivedEntityRange<ParentDeclIteratorImpl<Decl>, ClassTemplatePartialSpecializationDecl>;

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
  inline static ClassTemplatePartialSpecializationDeclRange in(const Fragment &frag) {
    return in_internal(frag);
  }

  inline static ClassTemplatePartialSpecializationDeclContainingTokenRange containing(const Token &tok) {
    return TokenContextIterator(tok.context());
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : ClassTemplatePartialSpecializationDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION;
  }

  static ClassTemplatePartialSpecializationDeclContainingDeclRange containing(const Decl &decl);
  static ClassTemplatePartialSpecializationDeclContainingDeclRange containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TokenContext &c);
  static std::optional<ClassTemplatePartialSpecializationDecl> from(const ClassTemplateSpecializationDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<ClassTemplateSpecializationDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const CXXRecordDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<CXXRecordDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const RecordDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<RecordDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TagDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<TagDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const TypeDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<TypeDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const NamedDecl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ClassTemplatePartialSpecializationDecl> from(const Decl &parent);

  inline static std::optional<ClassTemplatePartialSpecializationDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ClassTemplatePartialSpecializationDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
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
