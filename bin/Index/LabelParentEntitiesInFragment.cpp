// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PendingFragment.h"

#include <glog/logging.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <unordered_set>

#include "EntityMapper.h"
#include "Visitor.h"

namespace indexer {
namespace {

struct SaveRestoreEntity {
 public:
  mx::RawEntityId &ref;
  const void *&ref_ptr;
  const mx::RawEntityId old_val;
  const void *oldval_ptr;

  SaveRestoreEntity(mx::RawEntityId &ref_, const void *&ptr_,
                    mx::RawEntityId new_val, const void *newval_ptr)
      : ref(ref_), ref_ptr(ptr_),
        old_val(ref), oldval_ptr(ref_ptr) {
    ref = new_val;
    ref_ptr = newval_ptr;
  }

  ~SaveRestoreEntity(void) {
    ref = old_val;
    ref_ptr = oldval_ptr;
  }
};

class ParentTrackerVisitor : public EntityVisitor {
 public:
  EntityMapper &em;
  PendingFragment &fragment;

  mx::RawEntityId parent_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId parent_stmt_id{mx::kInvalidEntityId};

  const void *parent_decl{nullptr};
  const void *parent_stmt{nullptr};

  std::unordered_set<const void *> not_yet_seen;

  virtual ~ParentTrackerVisitor(void) = default;

  explicit ParentTrackerVisitor(PendingFragment &fragment_)
      : em(fragment_.em),
        fragment(fragment_) {}

  void AddToMaps(const void *entity) {
    if (parent_decl_id != mx::kInvalidEntityId && parent_decl) {
      em.parent_decl_ids.emplace(entity, parent_decl_id);
      em.parent_decls.emplace(entity, parent_decl);
    }

    if (parent_stmt_id != mx::kInvalidEntityId && parent_stmt) {
      em.parent_stmt_ids.emplace(entity, parent_stmt_id);
      em.parent_stmts.emplace(entity, parent_stmt);
    }
  }

  void Accept(const pasta::Decl &entity) final {
    mx::RawEntityId rid = em.EntityId(entity);
    mx::VariantId vid = mx::EntityId(rid).Unpack();
    if (!std::holds_alternative<mx::DeclId>(vid)) {
      return;
    }

    mx::DeclId eid = std::get<mx::DeclId>(vid);

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    if (eid.fragment_id != fragment.fragment_index) {
      return;
    }

    AddToMaps(entity.RawDecl());

    SaveRestoreEntity save_parent_decl(
        parent_decl_id, parent_decl, rid, entity.RawDecl());
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::Stmt &entity) final {
    mx::RawEntityId rid = em.EntityId(entity);
    mx::VariantId vid = mx::EntityId(rid).Unpack();
    if (!std::holds_alternative<mx::StmtId>(vid)) {
      return;
    }

    mx::StmtId eid = std::get<mx::StmtId>(vid);

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    if (eid.fragment_id != fragment.fragment_index) {
      return;
    }

    AddToMaps(entity.RawStmt());

    SaveRestoreEntity save_parent_stmt(
        parent_stmt_id, parent_stmt, rid, entity.RawStmt());
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::Attr &entity) final {
    AddToMaps(entity.RawAttr());
  }

  bool Enter(const pasta::Decl &entity) final {
    return not_yet_seen.erase(entity.RawDecl());
  }

  bool Enter(const pasta::Stmt &entity) final {
    return not_yet_seen.erase(entity.RawStmt());
  }

  bool Enter(const pasta::Type &) final {
    return false;
  }

  bool Enter(const pasta::Attr &entity) final {
    AddToMaps(entity.RawAttr());
    return false;
  }

  void Accept(const pasta::Type &) final {}

  void Accept(const pasta::TemplateParameterList &entity) final {
    AddToMaps(entity.RawTemplateParameterList());
  }

  void Accept(const pasta::TemplateArgument &entity) final {
    AddToMaps(entity.RawTemplateArgument());
  }

  void Accept(const pasta::Designator &entity) final {
    AddToMaps(entity.RawDesignator());
  }

  void Accept(const pasta::CXXBaseSpecifier &entity) final {
    AddToMaps(entity.RawCXXBaseSpecifier());
  }
};

struct ScanResult {
  bool seen_type{false};
  const void *child_stmt{nullptr};
  const void *parent_stmt{nullptr};
  const void *parent_decl{nullptr};
};

// Scan for a `Stmt` (`child_stmt`) nested inside of a `Type` (`seen_type`)
// nested inside of a `Stmt` (`parent_stmt`) or `Decl` (`parent_decl`).
static ScanResult ScanTokenContexts(pasta::PrintedToken tok) {
  ScanResult res;

  for (pasta::TokenContext ctx : TokenContexts(tok)) {
    auto raw_ctx = ctx.Data();
    switch (ctx.Kind()) {
      default:
        break;
      case pasta::TokenContextKind::kStmt:
        if (res.seen_type) {
          res.parent_stmt = raw_ctx;
          return res;
        } else {
          res.child_stmt = raw_ctx;
          break;
        }
      case pasta::TokenContextKind::kDecl:
        if (res.seen_type) {
          res.parent_decl = raw_ctx;
          return res;
        } else {
          res.child_stmt = nullptr;
          break;
        }
      case pasta::TokenContextKind::kType:
        if (res.child_stmt || res.seen_type) {
          res.seen_type = true;
        } else {
          res.child_stmt = nullptr;
        }
        break;
    }
  }
  return {};
}

static const void *GetOrNullptr(EntityParentMap &map, const void *key) {
  if (auto it = map.find(key); it != map.end()) {
    return it->second;
  }
  return nullptr;
}

// Sync up the pointers and IDs for parentage.
static bool ResolveParents(ParentTrackerVisitor &vis, const void *parent_stmt,
                           const void *parent_decl) {
  EntityMapper &em = vis.em;
  vis.parent_stmt = parent_stmt;
  vis.parent_decl = parent_decl;

  if (!vis.parent_stmt && vis.parent_decl) {
    vis.parent_stmt = GetOrNullptr(em.parent_stmts, vis.parent_decl);
  }

  if (!vis.parent_decl && vis.parent_stmt) {
    vis.parent_stmt = GetOrNullptr(em.parent_decls, vis.parent_stmt);
  }

  vis.parent_stmt_id = em.ParentStmtId(vis.parent_stmt);
  vis.parent_decl_id = em.ParentStmtId(vis.parent_decl);

  return (vis.parent_stmt && vis.parent_stmt_id != mx::kInvalidEntityId) ||
         (vis.parent_decl && vis.parent_decl_id != mx::kInvalidEntityId);
}

// Use the token contexts to try to find missing parents.
static void FindMissingParentageFromTokens(
    ParentTrackerVisitor &vis, PendingFragment &pf) {

  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    auto [seen_type, child_stmt, parent_stmt, parent_decl] =
        ScanTokenContexts(std::move(tok));

    if (!seen_type || !child_stmt) {
      continue;
    }

    if (!parent_stmt && !parent_decl) {
      continue;
    }

    // If we're already seen `child_stmt`, then it isn't one of the missing
    // ones.
    if (!vis.not_yet_seen.count(child_stmt)) {
      continue;
    }

    if (ResolveParents(vis, parent_stmt, parent_decl)) {
      auto ast = pasta::AST::From(pf.stmts_to_serialize.front());
      vis.Accept(ast.Adopt(reinterpret_cast<const clang::Stmt *>(child_stmt)));
    }
  }
}

// PASTA has a blind spot with expressions nested inside of attributes. For now,
// PASTA defers to Clang's pretty printer for most attributes, and so we don't
// have the token contexts from them.
static void FindMissingParentageFromAttributeTokens(
    ParentTrackerVisitor &vis, PendingFragment &pf) {

  if (pf.attrs_to_serialize.empty()) {
    return;
  }

  // Find the parsed tokens whose nearest context is an `Attr`.
  std::unordered_map<const void *, const void *> tok_to_attr;
  for (pasta::PrintedToken tok : pf.parsed_tokens) {
    auto parsed_tok = tok.DerivedLocation();
    if (!parsed_tok) {
      continue;
    }

    auto context = tok.Context();
    if (context && context->Kind() == pasta::TokenContextKind::kAttr) {
      tok_to_attr.emplace(parsed_tok->RawToken(), context->Data());
    }
  }

  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    if (!vis.not_yet_seen.count(stmt.RawStmt())) {
      continue;
    }

    // Look at the tokens of the statement
    for (pasta::Token tok : stmt.Tokens()) {
      auto attr_it = tok_to_attr.find(tok.RawToken());
      if (attr_it == tok_to_attr.end()) {
        continue;
      }

      auto parent_stmt = GetOrNullptr(pf.em.parent_stmts, attr_it->second);
      auto parent_decl = GetOrNullptr(pf.em.parent_decls, attr_it->second);

      if (ResolveParents(vis, parent_stmt, parent_decl)) {
        vis.Accept(stmt);
        break;
      }
    }
  }
}

}  // namespace

// Maps the child-to-parent relationships in the fragment, storing the
// relationships in `parent_decls` and `parent_stmts`.
void LabelParentsInPendingFragment(PendingFragment &pf) {

  ParentTrackerVisitor vis(pf);
  for (const pasta::Decl &decl : pf.decls_to_serialize) {
    vis.not_yet_seen.emplace(decl.RawDecl());
  }

  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    vis.not_yet_seen.emplace(stmt.RawStmt());
  }

  // Visit the top-level decls first.

  for (const pasta::Decl &decl : pf.top_level_decls) {
    vis.Accept(decl);
  }

  // Expand the set of decls.
  for (size_t i = 0u, max_i = pf.decls_to_serialize.size(); i < max_i; ++i) {
    pasta::Decl decl = pf.decls_to_serialize[i];
    auto raw_entity = decl.RawDecl();
    
    if (vis.not_yet_seen.count(raw_entity)) {
      vis.Accept(decl);
      
      // NOTE(pag): If this assertion is hit, then it suggests that the
      //            manually-written traversals in `Visitor.cpp` are missing
      //            something that the automatically generated visitors created
      //            from `Visitor.inc.h` have found. Missing things is not the
      //            end of the world, but it suggests a blindspot, hence we want
      //            to loudly detect them here if possible. Missing things can
      //            also be an indication that we're not fully linking something
      //            to its parent decls/statements.
      DCHECK(!vis.not_yet_seen.count(raw_entity));

      DCHECK_EQ(max_i, pf.decls_to_serialize.size());
      max_i = pf.decls_to_serialize.size();
    }
  }

  // We may have expressions inside of types, e.g. `int foo[stmt_here];`.
  if (vis.not_yet_seen.empty()) {
    return;
  }

  FindMissingParentageFromTokens(vis, pf);
  if (vis.not_yet_seen.empty()) {
    return;
  }

  FindMissingParentageFromAttributeTokens(vis, pf);
  if (vis.not_yet_seen.empty()) {
    return;
  }

  // Log the error.

  std::optional<pasta::Stmt> first_missing_stmt;
  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    if (vis.not_yet_seen.count(stmt.RawStmt())) {
      first_missing_stmt.emplace(stmt);
      break;
    }
  }

  CHECK(first_missing_stmt.has_value());

  auto ast = pasta::AST::From(pf.stmts_to_serialize.front());
  LOG(ERROR)
      << "Fragment"
      << PrefixedLocation(pf.decls_to_serialize.front(), " at or near ")
      << " main job file " << ast.MainFile().Path().generic_string()
      << " has statements without parents: "
      << DiagnosePrintedTokens(
             pasta::PrintedTokenRange::Create(first_missing_stmt.value()));
}

}  // namespace indexer
