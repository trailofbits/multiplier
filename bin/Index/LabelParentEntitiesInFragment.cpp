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
#include "Util.h"
#include "Visitor.h"

namespace indexer {
namespace {

struct SaveRestoreEntity {
 public:
  mx::RawEntityId &ref;
  const void *&ref_ptr;
  const mx::RawEntityId old_val;
  const void * const oldval_ptr;

  SaveRestoreEntity(mx::RawEntityId &ref_, const void *&ptr_,
                    mx::EntityId new_val, const void *newval_ptr)
      : ref(ref_),
        ref_ptr(ptr_),
        old_val(ref),
        oldval_ptr(ref_ptr) {
    ref = new_val.Pack();
    ref_ptr = newval_ptr;
  }

  ~SaveRestoreEntity(void) {
    ref = old_val;
    ref_ptr = oldval_ptr;
  }
};

static const void *GetOrNullptr(EntityParentMap &map, const void *key) {
  if (auto it = map.find(key); it != map.end()) {
    return it->second;
  }
  return nullptr;
}

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

  template <typename EntityListMap>
  inline void AddUnseenEntities(const EntityListMap &entities) {
    for (auto entity : Entities(entities)) {
      not_yet_seen.emplace(RawEntity(entity));
    }
  }

  inline bool HasUnseen(void) const {
    return !not_yet_seen.empty();
  }

  inline bool HasBeenSeen(const void *raw_entity) const {
    return !not_yet_seen.count(raw_entity);
  }

  template <typename T>
  inline bool HasBeenSeen(const T &entity) const {
    return !not_yet_seen.count(RawEntity(entity));
  }

  void VisitOtherInitListExprImpl(const pasta::InitListExpr &stmt,
                                  std::optional<pasta::InitListExpr> other) {
    if (other.has_value() &&
        other.value() != stmt &&
        !HasBeenSeen(other.value()) &&
        Ascend()) {
      this->EntityVisitor::VisitInitListExpr(other.value());
    }
  }

  // `InitListExpr`s can have a semantic/syntactic form, and they logically
  // belong to the same parent.
  void VisitInitListExpr(const pasta::InitListExpr &stmt) {
    this->EntityVisitor::VisitInitListExpr(stmt);
    VisitOtherInitListExprImpl(stmt, stmt.SyntacticForm());
    VisitOtherInitListExprImpl(stmt, stmt.SemanticForm());
  }

  void AddToMaps(const void *entity) {
    if (parent_decl_id != mx::kInvalidEntityId && parent_decl) {
      assert(entity != parent_decl);
      assert(mx::EntityId(parent_decl_id).Extract<mx::DeclId>());
      em.parent_decl_ids.emplace(entity, parent_decl_id);
      em.parent_decls.emplace(entity, parent_decl);
    }

    if (parent_stmt_id != mx::kInvalidEntityId && parent_stmt) {
      assert(entity != parent_stmt);
      assert(mx::EntityId(parent_stmt_id).Extract<mx::StmtId>());
      em.parent_stmt_ids.emplace(entity, parent_stmt_id);
      em.parent_stmts.emplace(entity, parent_stmt);
    }
  }

  void Accept(const pasta::Decl &entity) final {
    if (ShouldHideFromIndexer(entity)) {
      return;
    }

    // Handle the serializable decl context differently
    auto eid = em.SpecificEntityId<mx::DeclId>(entity);
    if (!eid) {
      // TODO(kumarak): I see an unlinked instance of TemplateTypeParmDecl that is 
      //                not available in AST. Adding check to avoid assert
      assert((false
              || entity.Kind() == pasta::DeclKind::kTemplateTypeParm
              || entity.Kind() == pasta::DeclKind::kNonTypeTemplateParm
              || entity.IsImplicit()));
      return;
    }

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    //
    // TODO(pag): Assert as a signal to find when it happens?
    // Putting assert here will always be triggered for templates specialization if
    // we add all template and its specialization node as top-level decls in fragments.
    // Adding them as TLD may make it reachable from two fragments cause the fragment ids
    // to mismatch.
    if (eid->fragment_id != fragment.fragment_index) {
      // assert(false);
      return;
    }

    auto raw_entity = RawEntity(entity);
    AddToMaps(raw_entity);

    SaveRestoreEntity save_parent_decl(
        parent_decl_id, parent_decl, eid.value(), raw_entity);
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::Stmt &entity) final {
    auto eid = em.SpecificEntityId<mx::StmtId>(entity);
    if (!eid) {
      // TODO(kumarak): Log error instead of assert. See the assert
      //                while visiting dependent types.
      LOG(ERROR)
        << "Fragment has statment missing from Entity Mapper: "
        << DiagnosePrintedTokens(
              pasta::PrintedTokenRange::Create(entity));
      //assert(false);
      return;
    }

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    //
    // TODO(pag): Assert as a signal to find when it happens?
    if (eid->fragment_id != fragment.fragment_index) {
      assert(false);
      return;
    }

    auto raw_entity = RawEntity(entity);
    AddToMaps(raw_entity);

    SaveRestoreEntity save_parent_stmt(
        parent_stmt_id, parent_stmt, eid.value(), raw_entity);
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::Attr &entity) final {
    AddToMaps(RawEntity(entity));
    this->EntityVisitor::Accept(entity);
  }

  bool Enter(const pasta::Decl &entity) final {
    return not_yet_seen.erase(RawEntity(entity));
  }

  bool Enter(const pasta::Stmt &entity) final {
    return not_yet_seen.erase(RawEntity(entity));
  }

  bool Enter(const pasta::Type &) final {
    return true;
  }

  bool Enter(const pasta::Attr &entity) final {
    AddToMaps(RawEntity(entity));
    return false;
  }

  void Accept(const pasta::Type &entity) final {
    if (!entity.IsDependentType()) {
      this->EntityVisitor::Accept(entity);
    }
  }

  void Accept(const pasta::TemplateParameterList &entity) final {
    AddToMaps(RawEntity(entity));
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::TemplateArgument &entity) final {
    AddToMaps(RawEntity(entity));
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::Designator &entity) final {
    AddToMaps(RawEntity(entity));
    this->EntityVisitor::Accept(entity);
  }

  void Accept(const pasta::CXXBaseSpecifier &entity) final {
    AddToMaps(RawEntity(entity));
    this->EntityVisitor::Accept(entity);
  }

  bool ResolveParentIds(void) {
    parent_stmt_id = em.EntityId(parent_stmt);
    parent_decl_id = em.EntityId(parent_decl);

    return (parent_stmt && parent_stmt_id != mx::kInvalidEntityId) ||
           (parent_decl && parent_decl_id != mx::kInvalidEntityId);
  }

  const void *GetParentStmt(const void *decl_or_stmt) const {
    return GetOrNullptr(em.parent_stmts, decl_or_stmt);
  }

  const void *GetParentDecl(const void *decl_or_stmt) const {
    return GetOrNullptr(em.parent_decls, decl_or_stmt);
  }

  // Sync up the pointers and IDs for parentage.
  bool SetParents(const void *new_parent_stmt, const void *new_parent_decl) {
    parent_stmt = new_parent_stmt;
    parent_decl = new_parent_decl;

    if (!parent_stmt && parent_decl) {
      parent_stmt = GetParentStmt(parent_decl);
    }

    if (!parent_decl && parent_stmt) {
      parent_decl = GetParentDecl(parent_stmt);
    }

    return ResolveParentIds();
  }

  bool ResolveParents(const void *entity) {
    return SetParents(GetParentStmt(entity), GetParentDecl(entity));
  }

  bool Ascend(void) {
    auto old_stmt = parent_stmt;
    auto old_decl = parent_decl;

    parent_stmt = GetParentStmt(old_stmt);
    if (!parent_stmt) {
      parent_stmt = GetParentStmt(old_decl);
    }

    parent_decl = GetParentDecl(old_decl);
    if (!parent_decl) {
      parent_decl = GetParentDecl(old_stmt);
    }

    return ResolveParentIds();
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
        }
        res.child_stmt = raw_ctx;
        break;
      case pasta::TokenContextKind::kDecl:
        if (res.seen_type) {
          res.parent_decl = raw_ctx;
          return res;
        } else if (!res.parent_decl && res.child_stmt) {
          res.parent_decl = raw_ctx;
        }
        break;
      case pasta::TokenContextKind::kType:
      case pasta::TokenContextKind::kTemplateParameterList:
      case pasta::TokenContextKind::kTemplateArgument:
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
    if (vis.HasBeenSeen(child_stmt)) {
      continue;
    }

    if (vis.SetParents(parent_stmt, parent_decl)) {
      auto ast = pasta::AST::From(pf.top_level_decls.front());
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

  for (pasta::Stmt stmt : Entities(pf.stmts_to_serialize)) {
    if (vis.HasBeenSeen(stmt)) {
      continue;
    }

    // Look at the tokens of the statement
    for (const pasta::Token &tok : stmt.Tokens()) {
      auto attr_it = tok_to_attr.find(tok.RawToken());
      if (attr_it == tok_to_attr.end()) {
        continue;
      }

      if (vis.ResolveParents(attr_it->second)) {
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
  vis.AddUnseenEntities(pf.decls_to_serialize);
  vis.AddUnseenEntities(pf.stmts_to_serialize);

  // Visit the top-level decls first.

  for (pasta::Decl decl : Entities(pf.top_level_decls)) {
    vis.Accept(decl);
  }

#ifndef NDEBUG
  size_t num_entities = NumEntities(pf.decls_to_serialize);
#endif

  // Expand the set of decls.
  for (pasta::Decl decl : Entities(pf.decls_to_serialize)) {  
    if (vis.HasBeenSeen(decl)) {
      continue;
    }

    vis.Accept(decl);
    
    // NOTE(pag): If this assertion is hit, then it suggests that the
    //            manually-written traversals in `Visitor.cpp` are missing
    //            something that the automatically generated visitors created
    //            from `Visitor.inc.h` have found. Missing things is not the
    //            end of the world, but it suggests a blindspot, hence we want
    //            to loudly detect them here if possible. Missing things can
    //            also be an indication that we're not fully linking something
    //            to its parent decls/statements.
    DCHECK(vis.HasBeenSeen(decl));
  }

#ifndef NDEBUG
  CHECK_EQ(num_entities, NumEntities(pf.decls_to_serialize));
#endif

  // We may have expressions inside of types, e.g. `int foo[stmt_here];`.
  if (!vis.HasUnseen()) {
    return;
  }

  FindMissingParentageFromTokens(vis, pf);
  if (!vis.HasUnseen()) {
    return;
  }

  FindMissingParentageFromAttributeTokens(vis, pf);
  if (!vis.HasUnseen()) {
    return;
  }

  // Log the error.

  std::optional<pasta::Stmt> first_missing_stmt;
  for (pasta::Stmt stmt : Entities(pf.stmts_to_serialize)) {
    if (!vis.HasBeenSeen(stmt)) {
      first_missing_stmt.emplace(stmt);
      break;
    }
  }

  CHECK(first_missing_stmt.has_value());

  auto ast = pasta::AST::From(pf.top_level_decls.front());
  LOG(ERROR)
      << "Fragment"
      << PrefixedLocation(pf.top_level_decls.front(), " at or near ")
      << " main job file " << ast.MainFile().Path().generic_string()
      << " has statements without parents: "
      << DiagnosePrintedTokens(
             pasta::PrintedTokenRange::Create(first_missing_stmt.value()));
}

}  // namespace indexer
