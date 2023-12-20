// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <multiplier/AST/OMPExecutableDirective.h>

namespace mx {
class EntityProvider;
class Fragment;
class Index;
class Decl;
class Expr;
class OMPExecutableDirective;
class OMPSectionsDirective;
class Stmt;
class Token;
namespace ir {
class Operation;
class Value;
}  // namespace ir

#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class MX_EXPORT OMPSectionsDirective : public OMPExecutableDirective {
 private:
  friend class FragmentImpl;
  friend class OMPExecutableDirective;
  friend class Stmt;
 public:
  static gap::generator<OMPSectionsDirective> in(const Index &index);
  static gap::generator<OMPSectionsDirective> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<OMPSectionsDirective> by_id(const Index &, EntityId);
  static gap::generator<OMPSectionsDirective> in(const Fragment &frag);
  static gap::generator<OMPSectionsDirective> in(const File &file);

  static std::optional<OMPSectionsDirective> from(const ir::Operation &op);
  static gap::generator<std::pair<OMPSectionsDirective, ir::Operation>> in(const Compilation &tu);
  inline static constexpr StmtKind static_kind(void) {
    return StmtKind::OMP_SECTIONS_DIRECTIVE;
  }

  static gap::generator<OMPSectionsDirective> containing(const Decl &decl);
  static gap::generator<OMPSectionsDirective> containing(const std::optional<Decl> &decl);

  static gap::generator<OMPSectionsDirective> containing(const Stmt &stmt);
  static gap::generator<OMPSectionsDirective> containing(const std::optional<Stmt> &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<OMPSectionsDirective> from_base(const Stmt &parent);
  inline static std::optional<OMPSectionsDirective> from(const Stmt &parent) {
    return from_base(parent);
  }
  static std::optional<OMPSectionsDirective> from(const std::optional<Stmt> &parent);
  static std::optional<OMPSectionsDirective> from(const Reference &r);
  static std::optional<OMPSectionsDirective> from(const VariantEntity &e);
  static std::optional<OMPSectionsDirective> from(const TokenContext &t);

  Expr task_reduction_reference_expression(void) const;
  bool has_cancel(void) const;
};

static_assert(sizeof(OMPSectionsDirective) == sizeof(OMPExecutableDirective));

#endif
} // namespace mx
