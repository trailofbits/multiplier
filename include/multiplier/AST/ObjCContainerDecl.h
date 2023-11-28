// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/NamedDecl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class NamedDecl;
class ObjCContainerDecl;
class ObjCMethodDecl;
class ObjCPropertyDecl;
class Stmt;
class Token;
class TokenRange;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCContainerDecl : public NamedDecl {
 private:
  friend class FragmentImpl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCContainerDecl> in(const Index &index);
  static gap::generator<ObjCContainerDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCContainerDecl> by_id(const Index &, EntityId);
  static gap::generator<ObjCContainerDecl> in(const Fragment &frag);
  static gap::generator<ObjCContainerDecl> in(const File &file);

  static gap::generator<ObjCContainerDecl> containing(const Decl &decl);
  static gap::generator<ObjCContainerDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCContainerDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCContainerDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCContainerDecl canonical_declaration(void) const;
  std::optional<ObjCContainerDecl> definition(void) const;
  gap::generator<ObjCContainerDecl> redeclarations(void) const &;
  static std::optional<ObjCContainerDecl> from_base(const Decl &parent);
  inline static std::optional<ObjCContainerDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<ObjCContainerDecl> from(const std::optional<Decl> &parent);
  static std::optional<ObjCContainerDecl> from(const Reference &r);
  static std::optional<ObjCContainerDecl> from(const VariantEntity &e);
  static std::optional<ObjCContainerDecl> from(const TokenContext &t);

  std::optional<ObjCMethodDecl> nth_class_method(unsigned n) const;
  unsigned num_class_methods(void) const;
  gap::generator<ObjCMethodDecl> class_methods(void) const &;
  std::optional<ObjCPropertyDecl> nth_class_propertie(unsigned n) const;
  unsigned num_class_properties(void) const;
  gap::generator<ObjCPropertyDecl> class_properties(void) const &;
  TokenRange at_end_range(void) const;
  Token at_start_token(void) const;
  std::optional<ObjCMethodDecl> nth_instance_method(unsigned n) const;
  unsigned num_instance_methods(void) const;
  gap::generator<ObjCMethodDecl> instance_methods(void) const &;
  std::optional<ObjCPropertyDecl> nth_instance_propertie(unsigned n) const;
  unsigned num_instance_properties(void) const;
  gap::generator<ObjCPropertyDecl> instance_properties(void) const &;
  std::optional<ObjCMethodDecl> nth_method(unsigned n) const;
  unsigned num_methods(void) const;
  gap::generator<ObjCMethodDecl> methods(void) const &;
  std::optional<ObjCPropertyDecl> nth_propertie(unsigned n) const;
  unsigned num_properties(void) const;
  gap::generator<ObjCPropertyDecl> properties(void) const &;
  gap::generator<Decl> declarations_in_context(void) const &;
};

static_assert(sizeof(ObjCContainerDecl) == sizeof(NamedDecl));

#endif
} // namespace mx
