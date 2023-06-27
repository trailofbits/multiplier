// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include "ObjCContainerDecl.h"

namespace mx {
class EntityProvider;
class Index;
class Decl;
class NamedDecl;
class ObjCCategoryImplDecl;
class ObjCContainerDecl;
class ObjCImplDecl;
class ObjCImplementationDecl;
class ObjCInterfaceDecl;
class ObjCPropertyImplDecl;
class Stmt;
class Token;
namespace mx {
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ObjCImplDecl : public ObjCContainerDecl {
 private:
  friend class FragmentImpl;
  friend class ObjCContainerDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  static gap::generator<ObjCImplDecl> in(const Fragment &frag);
  static gap::generator<ObjCImplDecl> in(const File &file);
  static gap::generator<ObjCImplDecl> in(const Index &index);
  static gap::generator<ObjCImplDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ObjCImplDecl> by_id(const Index &, EntityId);

  static gap::generator<ObjCImplDecl> containing(const Decl &decl);
  static gap::generator<ObjCImplDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<ObjCImplDecl> containing(const Stmt &stmt);
  static gap::generator<ObjCImplDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  ObjCImplDecl canonical_declaration(void) const;
  std::optional<ObjCImplDecl> definition(void) const;
  gap::generator<ObjCImplDecl> redeclarations(void) const &;
  static std::optional<ObjCImplDecl> from(const Decl &parent);

  inline static std::optional<ObjCImplDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return ObjCImplDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<ObjCImplDecl> from(const Reference &r);
  static std::optional<ObjCImplDecl> from(const TokenContext &t);

  ObjCInterfaceDecl class_interface(void) const;
  std::optional<ObjCPropertyImplDecl> nth_property_implementation(unsigned n) const;
  unsigned num_property_implementations(void) const;
  gap::generator<ObjCPropertyImplDecl> property_implementations(void) const &;
};

static_assert(sizeof(ObjCImplDecl) == sizeof(ObjCContainerDecl));

#endif
} // namespace mx
