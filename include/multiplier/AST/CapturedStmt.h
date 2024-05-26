// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/CapturedRegionKind.h>
#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CapturedDecl;
class CapturedStmt;
class Decl;
class File;
class RecordDecl;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT CapturedStmt : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<CapturedStmt> in(const Index &index);
  static gap::generator<CapturedStmt> in(const Fragment &frag);
  static gap::generator<CapturedStmt> in(const File &file);
  static gap::generator<CapturedStmt> containing(const Token &tok);
  bool contains(const Token &tok) const;

  static std::optional<CapturedStmt> from(const ir::Operation &op);
  static gap::generator<std::pair<CapturedStmt, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::CAPTURED_STMT;
  }

  static gap::generator<CapturedStmt> containing(const Decl &decl);
  static gap::generator<CapturedStmt> containing(const std::optional<Decl> &decl);

  static gap::generator<CapturedStmt> containing(const Stmt &stmt);
  static gap::generator<CapturedStmt> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CapturedStmt> by_id(const Index &, EntityId);

  static std::optional<CapturedStmt> from_base(const Stmt &parent);
  inline static std::optional<CapturedStmt> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<CapturedStmt> from(const std::optional<Stmt> &parent);
  static std::optional<CapturedStmt> from(const Reference &r);
  static std::optional<CapturedStmt> from(const VariantEntity &e);
  static std::optional<CapturedStmt> from(const TokenContext &t);

  CapturedDecl captured_declaration(void) const;
  RecordDecl captured_record_declaration(void) const;
  CapturedRegionKind captured_region_kind(void) const;
  Stmt captured_statement(void) const;
};

static_assert(sizeof(CapturedStmt) == sizeof(Stmt));

#endif
} // namespace mx
