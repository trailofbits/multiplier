// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "PendingFragment.h"

#include <glog/logging.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <unordered_set>

#include "EntityMapper.h"
#include "Visitor.h"

namespace indexer {
namespace {

struct SaveRestoreEntityId {
 public:
  mx::RawEntityId &ref;
  const mx::RawEntityId old_val;

  SaveRestoreEntityId(mx::RawEntityId &ref_, mx::RawEntityId new_val)
      : ref(ref_),
        old_val(ref) {
    ref = new_val;
  }

  ~SaveRestoreEntityId(void) {
    ref = old_val;
  }
};

class ParentTrackerVisitor : public EntityVisitor {
 public:
  EntityMapper &em;
  PendingFragment &fragment;

  mx::RawEntityId parent_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId parent_stmt_id{mx::kInvalidEntityId};

  std::unordered_set<const void *> not_yet_seen;

  virtual ~ParentTrackerVisitor(void) = default;

  ParentTrackerVisitor(EntityMapper &em_, PendingFragment &fragment_)
      : em(em_),
        fragment(fragment_) {}

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

    if (parent_decl_id != mx::kInvalidEntityId) {
      em.parent_decl_ids.emplace(entity.RawDecl(), parent_decl_id);
    }

    if (parent_stmt_id != mx::kInvalidEntityId) {
      em.parent_stmt_ids.emplace(entity.RawDecl(), parent_stmt_id);
    }

    SaveRestoreEntityId save_parent_decl(parent_decl_id, rid);
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

    if (parent_decl_id != mx::kInvalidEntityId) {
      em.parent_decl_ids.emplace(entity.RawStmt(), parent_decl_id);
    }

    if (parent_stmt_id != mx::kInvalidEntityId) {
      em.parent_stmt_ids.emplace(entity.RawStmt(), parent_stmt_id);
    }

    SaveRestoreEntityId save_parent_stmt(parent_stmt_id, rid);
    this->EntityVisitor::Accept(entity);
  }

  bool Enter(const pasta::Decl &entity) final {
    return not_yet_seen.erase(entity.RawDecl());
  }

  bool Enter(const pasta::Stmt &entity) final {
    return not_yet_seen.erase(entity.RawStmt());
  }

  bool Enter(const pasta::Type &entity) final {
    return not_yet_seen.erase(entity.RawType());
  }
};

}  // namespace

// Maps the child-to-parent relationships in the fragment, storing the
// relationships in `parent_decls` and `parent_stmts`.
void LabelParentsInPendingFragment(
    PendingFragment &pf, EntityMapper &em) {
  ParentTrackerVisitor vis(em, pf);
  for (const pasta::Decl &decl : pf.decls_to_serialize) {
    vis.not_yet_seen.emplace(decl.RawDecl());
  }

  for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
    vis.not_yet_seen.emplace(stmt.RawStmt());
  }

  for (const pasta::Type &type : pf.types_to_serialize) {
    vis.not_yet_seen.emplace(type.RawType());
  }

  // Visit the top-level decls first.

  for (const pasta::Decl &decl : pf.top_level_decls) {
    vis.Accept(decl);
  }

  // Expand the set of decls.
  for (size_t i = 0u, max_i = pf.decls_to_serialize.size(); i < max_i; ++i) {
    pasta::Decl decl = pf.decls_to_serialize[i];
    if (vis.not_yet_seen.count(decl.RawDecl())) {
      vis.Accept(decl);
      DCHECK_EQ(max_i, pf.decls_to_serialize.size());
      max_i = pf.decls_to_serialize.size();
    }
  }

#ifndef NDEBUG
  // NOTE(pag): If this assertion is hit, then it suggests that the manually-
  //            written traversals in `Visitor.cpp` are missing something that
  //            the automatically generated visitors created from
  //            `Visitor.inc.h` have found. Missing things is not the end of the
  //            world, but it suggests a blindspot, hence we want to loudly
  //            detect them here if possible. Missing things can also be an
  //            indication that we're not fully linking something to its parent
  //            decls/statements.
  for (const pasta::Decl &decl : pf.decls_to_serialize) {
    assert(!vis.not_yet_seen.count(decl.RawDecl()));
  }
#endif

// #ifndef NDEBUG
  // TODO(kumarak): Does the manually written Visitor.cpp should have traverse function
  //                for all stmt types. If not then we can probably remove assert here.
  // for (const pasta::Stmt &stmt : pf.stmts_to_serialize) {
  //   assert(!vis.not_yet_seen.count(stmt.RawStmt()));
  // }
// #endif
}

}  // namespace indexer
