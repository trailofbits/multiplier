// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Decl.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class File;
class PragmaDetectMismatchDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT PragmaDetectMismatchDecl : public Decl {
 private:
  friend class FragmentImpl;
  friend class Decl;
 public:
  static gap::generator<PragmaDetectMismatchDecl> in(const Index &index);
  static gap::generator<PragmaDetectMismatchDecl> in(const Fragment &frag);
  static gap::generator<PragmaDetectMismatchDecl> in(const File &file);
  static gap::generator<PragmaDetectMismatchDecl> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<PragmaDetectMismatchDecl> from(const ir::Operation &op);
  static gap::generator<std::pair<PragmaDetectMismatchDecl, ir::Operation>> in(const Compilation &tu);
  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::PRAGMA_DETECT_MISMATCH;
  }

  static gap::generator<PragmaDetectMismatchDecl> containing(const Decl &decl);
  static gap::generator<PragmaDetectMismatchDecl> containing(const std::optional<Decl> &decl);

  static gap::generator<PragmaDetectMismatchDecl> containing(const Stmt &stmt);
  static gap::generator<PragmaDetectMismatchDecl> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  PragmaDetectMismatchDecl canonical_declaration(void) const;
  std::optional<PragmaDetectMismatchDecl> definition(void) const;
  gap::generator<PragmaDetectMismatchDecl> redeclarations(void) const &;
  static std::optional<PragmaDetectMismatchDecl> by_id(const Index &, EntityId);

  static std::optional<PragmaDetectMismatchDecl> from_base(const Decl &parent);
  inline static std::optional<PragmaDetectMismatchDecl> from(const Decl &parent) {
    return from_base(parent);
  }
  static std::optional<PragmaDetectMismatchDecl> from(const std::optional<Decl> &parent);
  static std::optional<PragmaDetectMismatchDecl> from(const Reference &r);
  static std::optional<PragmaDetectMismatchDecl> from(const VariantEntity &e);
  static std::optional<PragmaDetectMismatchDecl> from(const TokenContext &t);

  std::string_view name(void) const;
  std::string_view value(void) const;
};

static_assert(sizeof(PragmaDetectMismatchDecl) == sizeof(Decl));

#endif
} // namespace mx
