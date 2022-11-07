// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <assert.h>

#include <multiplier/SQLiteStore.h>
#include <multiplier/SymbolDatabase.h>
#include <multiplier/IndexStorage.h>
#include <multiplier/Entities/DeclKind.h>

namespace mx {
PersistentAST::PersistentAST(sqlite::Connection &db) : db(db) {
  db.Execute(
    "CREATE TABLE IF NOT EXISTS "
    "'mx::syntex::ASTNode'(prev, kind, entity, spelling)");
  db.Execute(
    "CREATE TABLE IF NOT EXISTS "
    "'mx::syntex::ASTChildren'(parent, child, PRIMARY KEY(parent, child))");
  db.Execute(
    "CREATE TABLE IF NOT EXISTS "
    "'mx::syntex::ASTIndex'(fragment, kind, node, PRIMARY KEY(fragment, kind))");
  db.Execute(
    "CREATE TABLE IF NOT EXISTS 'mx::syntex::ASTRoot'(fragment, node)");

  get_root_stmt = db.Prepare(
    "SELECT node FROM 'mx::syntex::ASTRoot' WHERE fragment = ?1");
  create_node_stmt = db.Prepare(
    "INSERT INTO 'mx::syntex::ASTNode'(prev, kind, entity, spelling) "
    "VALUES (?1, ?2, ?3, ?4) RETURNING rowid");
  add_root_stmt = db.Prepare(
    "INSERT INTO 'mx::syntex::ASTRoot'(fragment, node) VALUES (?1, ?2)");
  get_node_stmt = db.Prepare(
    "SELECT prev, kind, entity, spelling "
    "FROM 'mx::syntex::ASTNode' WHERE rowid = ?1");
  get_index_stmt = db.Prepare(
    "SELECT node FROM 'mx::syntex::ASTIndex' "
    "WHERE fragment = ?1 AND kind = ?2");
  set_index_stmt = db.Prepare(
    "INSERT OR REPLACE INTO 'mx::syntex::ASTIndex'(fragment, kind, node) "
    "VALUES(?1, ?2, ?3)"
  );
  get_fragments_stmt = db.Prepare(
    "SELECT DISTINCT fragment FROM 'mx::syntex::ASTRoot'"
  );
  get_children_stmt = db.Prepare(
    "SELECT child FROM 'mx::syntex::ASTChildren' WHERE parent = ?1"
  );
  add_child_stmt = db.Prepare(
    "INSERT INTO 'mx::syntex::ASTChildren'(parent, child) VALUES (?1, ?2)"
  );
}

std::vector<std::uint64_t> PersistentAST::Root(RawEntityId fragment) {
  std::vector<std::uint64_t> results;
  get_root_stmt->BindValues(fragment);
  while(get_root_stmt->ExecuteStep()) {
    get_root_stmt->GetResult().Columns(results.emplace_back());
  }
  return results;
}

std::uint64_t PersistentAST::AddNode(const ASTNode& node) {
  create_node_stmt->BindValues(node.prev, node.kind,
                               node.entity, node.spelling);
  create_node_stmt->ExecuteStep();
  std::uint64_t rowid;
  create_node_stmt->GetResult().Columns(rowid);
  return rowid;
}

void PersistentAST::AddNodeToRoot(RawEntityId fragment, std::uint64_t node_id) {
  add_root_stmt->BindValues(fragment, node_id);
  add_root_stmt->Execute();
}

ASTNode PersistentAST::GetNode(std::uint64_t node_id) {
  ASTNode node;
  get_node_stmt->BindValues(node_id);
  get_node_stmt->ExecuteStep();
  get_node_stmt->GetResult().Columns(node.prev, node.kind,
                                     node.entity, node.spelling);
  get_node_stmt->ExecuteStep();
  return node;
}

std::optional<std::uint64_t> PersistentAST::GetNodeInIndex(
  RawEntityId fragment,
  unsigned short kind) {
  get_index_stmt->BindValues(fragment, kind);
  if(get_index_stmt->ExecuteStep()) {
    std::uint64_t rowid;
    get_index_stmt->GetResult().Columns(rowid);
    return rowid;
  }
  return {};
}

void PersistentAST::SetNodeInIndex(
  RawEntityId fragment,
  unsigned short kind,
  std::uint64_t node_id) {
  set_index_stmt->BindValues(fragment, kind, node_id);
  set_index_stmt->Execute();
}

std::vector<mx::RawEntityId> PersistentAST::GetFragments() {
  std::vector<mx::RawEntityId> fragments;
  while(get_fragments_stmt->ExecuteStep()) {
    get_fragments_stmt->GetResult().Columns(fragments.emplace_back());
  }
  return fragments;
}

std::vector<std::uint64_t> PersistentAST::GetChildren(std::uint64_t parent) {
  std::vector<std::uint64_t> children;
  get_children_stmt->BindValues(parent);
  while(get_children_stmt->ExecuteStep()) {
    get_children_stmt->GetResult().Columns(children.emplace_back());
  }
  return children;
}

void PersistentAST::AddChild(std::uint64_t parent, std::uint64_t child) {
  add_child_stmt->BindValues(parent, child);
  add_child_stmt->Execute();
}

IndexStorage::IndexStorage(sqlite::Connection& db)
    : db(db)
    , version_number(db)
    , next_file_id(db)
    , next_small_fragment_id(db)
    , next_big_fragment_id(db)
    , file_id_to_path(db)
    , file_id_to_serialized_file(db)
    , file_fragment_ids(db)
    , file_fragment_lines(db)
    , file_hash_to_file_id(db)
    , code_hash_to_fragment_id(db)
    , fragment_id_to_serialized_fragment(db)
    , entity_redecls(db)
    , entity_id_to_mangled_name(db)
    , mangled_name_to_entity_id(db)
    , entity_id_use_to_fragment_id(db)
    , entity_id_reference(db)
    , spelling_to_token_kind(db)
    , grammar_root(db)
    , grammar_nodes(db)
    , grammar_children(db)
    , ast(db)
    , database(db) {}

IndexStorage::~IndexStorage() {}

void IndexStorage::Flush() {
    database.Flush();
}


// Return the set of redeclarations of an entity.
std::vector<mx::RawEntityId> IndexStorage::FindRedeclarations(
    mx::EntityId eid) {
  mx::VariantId vid = eid.Unpack();
  assert(std::holds_alternative<mx::DeclarationId>(vid));

  // All of the declaration kinds need to actually match.
  mx::DeclarationId did = std::get<mx::DeclarationId>(vid);
  std::vector<mx::RawEntityId> next_new_ids;
  std::vector<mx::RawEntityId> all_ids;
  std::vector<mx::RawEntityId> new_ids;
  next_new_ids.reserve(16);
  all_ids.reserve(16);
  new_ids.reserve(16);
  next_new_ids.push_back(eid);

  // Expand the set of IDs via name mangling.
  switch (did.kind) {
    case mx::DeclKind::FUNCTION:
    case mx::DeclKind::CXX_METHOD:
    case mx::DeclKind::CXX_DESTRUCTOR:
    case mx::DeclKind::CXX_CONVERSION:
    case mx::DeclKind::CXX_CONSTRUCTOR:
    case mx::DeclKind::CXX_DEDUCTION_GUIDE:

    case mx::DeclKind::VAR:
    case mx::DeclKind::DECOMPOSITION:
    case mx::DeclKind::IMPLICIT_PARAM:
    case mx::DeclKind::OMP_CAPTURED_EXPR:
    case mx::DeclKind::PARM_VAR:
    case mx::DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case mx::DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      entity_id_to_mangled_name.GetByField<0>(
          next_new_ids[0],
          [&next_new_ids, this] (mx::RawEntityId, std::string mangled_name) {

            mangled_name_to_entity_id.GetByField<0>(
                std::move(mangled_name),
                [&next_new_ids] (std::string, mx::RawEntityId new_id) {
                  next_new_ids.push_back(new_id);
                  return true;
                });
            return true;
          });
      break;

    default:
      break;
  }

  all_ids.reserve(next_new_ids.size());

  // Expand the set of declarations via fixpoint using the redeclaration
  // graph.
  while (!next_new_ids.empty()) {
    next_new_ids.swap(new_ids);
    next_new_ids.clear();
    for (mx::RawEntityId new_id : new_ids) {
      if (std::find(all_ids.begin(), all_ids.end(), new_id) != all_ids.end()) {
        continue;
      }

      const mx::EntityId new_eid(new_id);
      const mx::VariantId new_vid = new_eid.Unpack();
      if (!std::holds_alternative<mx::DeclarationId>(new_vid)) {
        assert(false);
        continue;
      }

      const mx::DeclarationId new_did = std::get<mx::DeclarationId>(new_vid);
      if (new_did.kind != did.kind) {
        assert(false);
        continue;
      }

      all_ids.push_back(new_id);

      entity_redecls.GetByField<0>(
          new_id,
          [&next_new_ids] (mx::RawEntityId, mx::RawEntityId other_id) {
            next_new_ids.push_back(other_id);
            return true;
          });
    }
  }

  // Sort the redeclaration IDs to that they are always in the same order,
  // regardless of which one we ask for first, then partition them and move
  // the definitions before the declarations.
  std::sort(all_ids.begin(), all_ids.end());
  std::partition(
      all_ids.begin(), all_ids.end(),
      [] (mx::RawEntityId eid) {
        return std::get<mx::DeclarationId>(
            mx::EntityId(eid).Unpack()).is_definition;
      });

  return all_ids;
}

std::optional<std::string>
IndexStorage::GetSerializedFile(mx::RawEntityId file_id) {
  return file_id_to_serialized_file.TryGet(file_id);
}
} // namespace mx
