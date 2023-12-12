// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/Stmt.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class CapturedStmt;
class Decl;
class OMPExecutableDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPExecutableDirective : public Stmt {
 private:
  friend class FragmentImpl;
  friend class Stmt;
 public:
  static gap::generator<OMPExecutableDirective> in(const Index &index);
  static gap::generator<OMPExecutableDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPExecutableDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPExecutableDirective> in(const Fragment &frag);
  static gap::generator<OMPExecutableDirective> in(const File &file);

#ifndef MX_DISABLE_VAST
  static std::optional<OMPExecutableDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPExecutableDirective, ir::Operation>> in(const Compilation &tu);
#endif  // MX_DISABLE_VAST

  static gap::generator<OMPExecutableDirective> containing(const Decl &decl);
  static gap::generator<OMPExecutableDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPExecutableDirective> containing(const Stmt &stmt);
  static gap::generator<OMPExecutableDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPExecutableDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPExecutableDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPExecutableDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPExecutableDirective> from(const Reference &r);
  static std::optional<OMPExecutableDirective> from(const VariantEntity &e);
  static std::optional<OMPExecutableDirective> from(const TokenContext &t);

  Stmt associated_statement(void) const;
  CapturedStmt innermost_captured_statement(void) const;
  Stmt raw_statement(void) const;
  Stmt structured_block(void) const;
  bool has_associated_statement(void) const;
  bool is_standalone_directive(void) const;
};

static_assert(sizeof(OMPExecutableDirective) == sizeof(Stmt));

#endif
} // namespace mx
