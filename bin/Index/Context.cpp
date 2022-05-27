// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Context.h"

#include <chrono>
#include <glog/logging.h>
#include <multiplier/AST.h>
#include <multiplier/Executor.h>
#include <multiplier/ProgressBar.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

#include "Codegen.h"
#include "Database.h"
#include "NameMangler.h"
#include "PendingFragment.h"

namespace indexer {

ServerContext::ServerContext(std::filesystem::path workspace_dir_)
    : workspace_dir(std::move(workspace_dir_)),
      meta_to_value(workspace_dir),
      file_id_to_path(workspace_dir),
      file_id_to_serialized_file(workspace_dir),
      file_fragment_ids(workspace_dir),
      file_fragment_lines(workspace_dir),
      file_hash_to_file_id(workspace_dir),
      file_path_to_file_id(workspace_dir),
      code_hash_to_fragment_id(workspace_dir),
      fragment_id_to_serialized_fragment(workspace_dir),
      entity_redecls(workspace_dir),
      entity_id_to_mangled_name(workspace_dir),
      mangled_name_to_entity_id(workspace_dir),
      entity_id_use_to_fragment_id(workspace_dir),
      entity_id_reference(workspace_dir) {

  // Clients all default-initialize their version numbers to `0`, so we default
  // the server to `1` so that clients are always out-of-date.
  version_number.store(static_cast<unsigned>(meta_to_value.GetOrSet(
      MetadataName::kIndexingVersion, 1u)));

  next_file_id.store(meta_to_value.GetOrSet(
      MetadataName::kNextFileId, mx::kMinEntityIdIncrement));
  next_small_fragment_id.store(meta_to_value.GetOrSet(
      MetadataName::kNextSmallCodeId, mx::kMaxBigFragmentId));
  next_big_fragment_id.store(meta_to_value.GetOrSet(
      MetadataName::kNextBigCodeId, mx::kMinEntityIdIncrement));
}

ServerContext::~ServerContext(void) {
  Flush();
}

void ServerContext::Flush(void) {
  meta_to_value.Set(MetadataName::kIndexingVersion, version_number.load());
  meta_to_value.Set(MetadataName::kNextFileId, next_file_id.load());
  meta_to_value.Set(MetadataName::kNextSmallCodeId, next_small_fragment_id.load());
  meta_to_value.Set(MetadataName::kNextBigCodeId, next_big_fragment_id.load());
}

void IndexingCounter::ResetAll(void) {
  for(auto id = 0u; id < kStatSourceIRFragment + 1u; id++) {
    counter[id].store(mx::kInvalidEntityId);
  }
}

void IndexingCounter::PrintAll(void) {
  const char *id_name[6] = {
      "StatCompileCommand", "StatCompileJob", "StatAST",
      "StatCodeFragment", "StatUniqueCodeFragment",
      "StatSourceIRFragment"
  };
  for(auto id = 0u; id < kStatSourceIRFragment + 1u; id++) {
    std::cerr << id_name[id] << " : " <<  counter[id].load() << "\n";
  }
}

IndexingContext::IndexingContext(ServerContext &server_context_,
                                 const mx::Executor &exe_)
    : server_context(server_context_),
      num_workers(exe_.NumWorkers()),
      version_number(static_cast<unsigned>(
          server_context.version_number.fetch_add(1u))),
      local_next_file_id(num_workers),
      local_next_small_fragment_id(num_workers),
      local_next_big_fragment_id(num_workers),
      codegen(nullptr) {

  // Save the updated version number.
  server_context.Flush();

  // Initialize database instance for each worker
  for (auto i = 0U; i < num_workers; ++i) {
    database.emplace_back(new Database(
        sqlite_dbname(server_context_.workspace_dir)));
  }
}

IndexingContext::~IndexingContext(void) {

  // Second increment (first is in constructor) so that client requests during
  // the indexing process can be re-refreshed later for possibly newer info.
  server_context.version_number.fetch_add(1u);

  // Save the updated version number.
  server_context.Flush();

  // Create the virtual table using fts5 module that will enable
  // index based searching.
  for (auto i = 0U; i < num_workers; ++i) {
    if (auto db = database[i].get()) {
      db->CreateIndexedTable();
    }
  }

}

void IndexingContext::InitializeProgressBars(void) {
  command_progress.reset(new mx::ProgressBar("1) Command interpretation",
                                             std::chrono::seconds(1)));
  ast_progress.reset(new mx::ProgressBar("2) Parsing / AST building",
                                         std::chrono::seconds(1)));
  file_progress.reset(new mx::ProgressBar("3) File serialization",
                                          std::chrono::seconds(1)));
  partitioning_progress.reset(new mx::ProgressBar("4) Fragment partitioning",
                                                  std::chrono::seconds(1)));
  identification_progress.reset(new mx::ProgressBar("5) Fragment identification",
                                                    std::chrono::seconds(1)));
  serialization_progress.reset(new mx::ProgressBar("6) Fragment serialization",
                                              std::chrono::seconds(1)));

  command_progress->SetNumWorkers(num_workers);
  ast_progress->SetNumWorkers(num_workers);
  file_progress->SetNumWorkers(num_workers);
  partitioning_progress->SetNumWorkers(num_workers);
  identification_progress->SetNumWorkers(num_workers);
  serialization_progress->SetNumWorkers(num_workers);
}

// Return the set of redeclarations of an entity.
std::vector<mx::RawEntityId> ServerContext::FindRedeclarations(
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
      entity_id_to_mangled_name.ScanPrefix(
          next_new_ids[0],
          [&next_new_ids, this] (mx::RawEntityId, std::string mangled_name) {

            mangled_name_to_entity_id.ScanPrefix(
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

      entity_redecls.ScanPrefix(
          new_id,
          [&next_new_ids] (mx::RawEntityId new_id, mx::RawEntityId other_id) {
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

void IndexingContext::InitializeCodeGenerator(void) {
  codegen = std::make_unique<CodeGenerator>();
}

// Get or create a file ID for the file at `file_path` with contents
// `contents_hash`.
std::pair<mx::FileId, bool> IndexingContext::GetOrCreateFileId(
    mx::WorkerId worker_id_, std::filesystem::path file_path,
    const std::string &contents_hash) {

  const auto worker_id = static_cast<unsigned>(worker_id_);
  auto &maybe_id = this->local_next_file_id[worker_id].id;
  mx::FileId created_id = mx::kInvalidEntityId;
  if (!maybe_id.has_value()) {
    created_id = server_context.next_file_id.fetch_add(
        mx::kMinEntityIdIncrement);;
  } else {
    created_id = std::move(maybe_id.value());
    maybe_id = {};
  }

  mx::FileId file_id = server_context.file_hash_to_file_id.GetOrSet(
      contents_hash, created_id);

  CHECK_LT(file_id, mx::kMaxFileId);

  std::string path_str = file_path.lexically_normal().generic_string();
  server_context.file_id_to_path.Insert(file_id, path_str);
  server_context.file_path_to_file_id.Set(path_str, file_id);
  if (file_id == created_id) {
    return {file_id, true};

  } else {
    maybe_id = created_id;  // Put it back in the worker-specific cache.
    return {file_id, false};
  }
}

// Get or create a code ID for the top-level declarations that hash to
// `code_hash`.
std::pair<mx::FragmentId, bool> IndexingContext::GetOrCreateFragmentId(
    mx::WorkerId worker_id_, const std::string &code_hash,
    uint64_t num_tokens) {

  const auto worker_id = static_cast<unsigned>(worker_id_);

  // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
  if (num_tokens >= mx::kNumTokensInBigFragment) {
    auto &maybe_id = this->local_next_big_fragment_id[worker_id].id;
    mx::FileId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.next_big_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }

    mx::FragmentId code_id = server_context.code_hash_to_fragment_id.GetOrSet(
        code_hash, created_id);

    CHECK_LT(code_id, mx::kMaxBigFragmentId);
    if (code_id == created_id) {
      return {code_id, true};

    } else {
      maybe_id = created_id;  // Put it back in the worker-specific cache.
      return {code_id, false};
    }

  // "Small codes" have IDs in the range `[mx::mx::kMaxNumBigPendingFragments, ...)`.
  } else {
    auto &maybe_id = this->local_next_small_fragment_id[worker_id].id;
    mx::FileId created_id = mx::kInvalidEntityId;
    if (!maybe_id.has_value()) {
      created_id = server_context.next_small_fragment_id.fetch_add(
          mx::kMinEntityIdIncrement);;
    } else {
      created_id = std::move(maybe_id.value());
      maybe_id = {};
    }

    mx::FragmentId code_id = server_context.code_hash_to_fragment_id.GetOrSet(
        code_hash, created_id);

    CHECK_GE(code_id, mx::kMaxBigFragmentId);
    if (code_id == created_id) {
      return {code_id, true};

    } else {
      maybe_id = created_id;  // Put it back in the worker-specific cache.
      return {code_id, false};
    }
  }
}

// Save the tokenized contents of a file.
void IndexingContext::PutSerializedFile(mx::FileId id, std::string data) {
  server_context.file_id_to_serialized_file.Set(id, std::move(data));
}

// Save the serialized top-level entities and the parsed tokens.
void IndexingContext::PutSerializedFragment(mx::FragmentId id,
                                            std::string data) {
  server_context.fragment_id_to_serialized_fragment.Set(id, std::move(data));
}

// Link fragment declarations.
void IndexingContext::LinkDeclarations(mx::RawEntityId a, mx::RawEntityId b) {
  if (a != b && a != mx::kInvalidEntityId && b != mx::kInvalidEntityId) {
    server_context.entity_redecls.Insert(a, b);
    server_context.entity_redecls.Insert(b, a);
  }
}

// Link the mangled name of something to its entity ID.
void IndexingContext::LinkMangledName(const std::string &name,
                                      mx::RawEntityId eid) {
  if (!name.empty() && eid != mx::kInvalidEntityId) {
    server_context.entity_id_to_mangled_name.Insert(eid, name);
    server_context.mangled_name_to_entity_id.Insert(name, eid);
  }
}

// Link an entity to the fragment that uses the entity.
void IndexingContext::LinkUseInFragment(mx::RawEntityId use,
                                        mx::FragmentId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    server_context.entity_id_use_to_fragment_id.Insert(use, user);
  }
}

// Link a direct reference to an entity from another entity.
void IndexingContext::LinkReferenceInFragment(mx::RawEntityId use,
                                              mx::FragmentId user) {
  if (use != mx::kInvalidEntityId && user != mx::kInvalidEntityId) {
    server_context.entity_id_reference.Insert(use, user);
  }
}

// Save an entries of the form `(file_id, line_number, fragment_id)` over
// the inclusive range `[start_line, end_line]` so that we can figure out
// which fragments overlap which lines. We use this index to go from regular
// expression matches or Weggli syntax matches on files into matches inside of
// fragments.
//
// TODO(pag): Eventually implement an async writer for `PersistentMap` and
//            `PersistentSet` using a RocksDB `WriteBatch`.
void IndexingContext::PutFragmentLineCoverage(
    mx::FileId file_id, mx::FragmentId fragment_id,
    unsigned start_line, unsigned end_line) {
  server_context.file_fragment_ids.Insert(file_id, fragment_id);
  for (auto i = start_line; i <= end_line; ++i) {
    server_context.file_fragment_lines.Insert(file_id, i, fragment_id);
  }
}

void IndexingContext::PrepareDatabase(mx::WorkerId id) {
  if (id >= database.size()) {
    return;
  }
  if (auto db = database[id].get()) {
    db->Prepare();
  }
}

void IndexingContext::CommitDatabase(mx::WorkerId id) {
  if (id >= database.size()) {
    return;
  }
  if (auto db = database[id].get()) {
    db->Commit();
  }
}

SearchingContext::SearchingContext(ServerContext &server_context_)
    : server_context(server_context_),
      local_next_file_id(mx::kMinEntityIdIncrement) {}

SearchingContext::~SearchingContext(void) {}

std::optional<std::string>
SearchingContext::GetSerializedFile(mx::FileId file_id) {
  return server_context.file_id_to_serialized_file.TryGet(file_id);
}

}  // namespace indexer
