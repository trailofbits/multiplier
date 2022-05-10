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
  EntityIdMap &entity_ids;
  PendingFragment &fragment;

  mx::RawEntityId parent_decl_id{mx::kInvalidEntityId};
  mx::RawEntityId parent_stmt_id{mx::kInvalidEntityId};

  std::unordered_set<const void *> seen;

  virtual ~ParentTrackerVisitor(void) = default;

  ParentTrackerVisitor(EntityIdMap &entity_ids_, PendingFragment &fragment_)
      : entity_ids(entity_ids_),
        fragment(fragment_) {}

  void Accept(const pasta::Decl &decl) final {
    if (parent_decl_id != mx::kInvalidEntityId) {
      fragment.parent_decl_ids.emplace(decl.RawDecl(), parent_decl_id);
    }

    if (parent_stmt_id != mx::kInvalidEntityId) {
      fragment.parent_stmt_ids.emplace(decl.RawDecl(), parent_stmt_id);
    }

    auto it = entity_ids.find(decl.RawDecl());
    if (it == entity_ids.end()) {
      return;
    }

    const mx::EntityId ent_id = it->second;

    mx::VariantId unpacked_id = ent_id.Unpack();
    CHECK(std::holds_alternative<mx::DeclarationId>(unpacked_id));
    mx::DeclarationId decl_id = std::get<mx::DeclarationId>(unpacked_id);

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    if (decl_id.fragment_id != fragment.fragment_id) {
      return;
    }

    SaveRestoreEntityId save_parent_decl(parent_decl_id, ent_id);
    this->EntityVisitor::Accept(decl);
  }

  void Accept(const pasta::Stmt &stmt) final {
    if (parent_decl_id != mx::kInvalidEntityId) {
      fragment.parent_decl_ids.emplace(stmt.RawStmt(), parent_decl_id);
    }

    if (parent_stmt_id != mx::kInvalidEntityId) {
      fragment.parent_stmt_ids.emplace(stmt.RawStmt(), parent_stmt_id);
    }

    auto it = entity_ids.find(stmt.RawStmt());
    if (it == entity_ids.end()) {
      return;
    }

    const mx::EntityId ent_id = it->second;
    mx::VariantId unpacked_id = ent_id.Unpack();
    CHECK(std::holds_alternative<mx::StatementId>(unpacked_id));
    mx::StatementId stmt_id = std::get<mx::StatementId>(unpacked_id);

    // This entity doesn't belong in this code chunk. Not sure if/when this will
    // happen.
    if (stmt_id.fragment_id != fragment.fragment_id) {
      return;
    }

    SaveRestoreEntityId save_parent_stmt(parent_stmt_id, ent_id);
    this->EntityVisitor::Accept(stmt);
  }

  bool Enter(const pasta::Decl &entity) final {
    return seen.insert(entity.RawDecl()).second;
  }

  bool Enter(const pasta::Stmt &entity) final {
    return seen.insert(entity.RawStmt()).second;
  }
};

}  // namespace

// Maps the child-to-parent relationships in the fragment, storing the
// relationships in `parent_decls` and `parent_stmts`.
void PendingFragment::LabelParents(EntityIdMap &entity_ids) {
  ParentTrackerVisitor vis(entity_ids, *this);
  for (const pasta::Decl &decl : decls) {
    vis.Accept(decl);
  }

  // Do a second pass through to handle any implicit declarations that were
  // internalized into this fragment.
  for (const pasta::Decl &decl : decls_to_serialize) {
    vis.Accept(decl);
  }
}

}  // namespace indexer
