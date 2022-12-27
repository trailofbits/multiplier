// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"

#include <multiplier/Re2.h>
#include <multiplier/Types.h>

#include "API.h"
#include "Compress.h"
#include "File.h"
#include "Fragment.h"
#include "Re2.h"
#include "../Common/SQLiteStore.h"

namespace mx {
namespace {

static sqlite::Connection Connect(std::filesystem::path path,
                                  const std::string &entity_id_list) {
  sqlite::Connection db(path);
  db.Execute("pragma synchronous = off");
  db.Execute("pragma temp_store = memory");
  db.Execute("pragma journal_mode = memory");
  db.Execute(
      "CREATE TABLE IF NOT EXISTS " + entity_id_list + " ("
      "  entity_id INT NOT NULL,"
      "  PRIMARY KEY(entity_id)"
      ") WITHOUT rowid");

  return db;
}

}  // namespace

class SQLiteEntityProvider::Context {
 public:
  const std::string entity_id_list;
  sqlite::Connection db;
  sqlite::Statement get_file_by_id;
  sqlite::Statement get_frag_by_id;
  sqlite::Statement get_version_number;
  sqlite::Statement get_file_paths;
  sqlite::Statement get_file_fragments;
  sqlite::Statement get_file_data;
  sqlite::Statement get_fragment_data;
  sqlite::Statement clear_entity_id_list;
  sqlite::Statement add_entity_id_to_list;
  sqlite::Statement get_entity_ids;
  sqlite::Statement get_redecls_by_mangled_name;
  sqlite::Statement get_redecls_by_entity_id;
  sqlite::Statement get_entities_by_name;
  sqlite::Statement get_uses;
  sqlite::Statement get_references;

  Context(unsigned worker_index, std::filesystem::path path)
      : entity_id_list("entity_id_list_" + std::to_string(worker_index)),
        db(Connect(path, entity_id_list)),
        get_file_by_id(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_frag_by_id(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        get_version_number(db.Prepare(
            "SELECT COUNT(rowid) FROM version WHERE version = ?1")),
        get_file_paths(db.Prepare(
            "SELECT file_id, path FROM file_path")),
        get_file_fragments(db.Prepare(
            "SELECT UNIQUE(fragment_id) FROM fragment_line WHERE file_id = ?1")),
        get_file_data(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_fragment_data(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        clear_entity_id_list(db.Prepare(
            "DELETE FROM " + entity_id_list)),
        add_entity_id_to_list(db.Prepare(
            "INSERT INTO " + entity_id_list + " (entity_id) VALUES (?1)")),
        get_entity_ids(db.Prepare(
            "SELECT entity_id FROM " + entity_id_list)),
        get_redecls_by_mangled_name(db.Prepare(
            "INSERT INTO " + entity_id_list + " (entity_id) "
            "WITH RECURSIVE transitive_mangled_names(entity_id) "
            "AS (SELECT l.entity_id FROM " + entity_id_list + " AS l"
            "    UNION"
            "    SELECT r.redecl_id"
            "    FROM transitive_mangled_names AS tc"
            "    JOIN mangled_name AS mn1 ON tc.entity_id = mn.entity_id"
            "    JOIN mangled_name AS mn2 ON mn1.data = mn2.data"
            ") SELECT entity_id FROM transitive_mangled_names")),
        get_redecls_by_entity_id(db.Prepare(
            "INSERT INTO " + entity_id_list + " (entity_id) "
            "WITH RECURSIVE transitive_redeclaration(entity_id) "
            "AS (SELECT l.entity_id FROM " + entity_id_list + " AS l"
            "    UNION"
            "    SELECT r.redecl_id"
            "    FROM transitive_redeclaration AS tc"
            "    JOIN redeclaration AS r ON tc.entity_id = r.entity_id"
            ") SELECT entity_id FROM transitive_redeclaration")),
#if MX_SQLITE_HAS_FTS5
        get_entities_by_name(db.Prepare(
            "SELECT rowid FROM symbol WHERE name MATCH ?1 || '*'")),
#else
        get_entities_by_name(db.Prepare(
            "SELECT rowid FROM symbol WHERE name LIKE '%' || ?1 || '%'")),
#endif
        get_uses(db.Prepare(
            "SELECT fragment_id FROM entity_use WHERE entity_id "
            "IN (SELECT entity_id FROM " + entity_id_list + ")")),
        get_references(db.Prepare(
            "SELECT fragment_id FROM entity_reference WHERE entity_id "
            "IN (SELECT entity_id FROM " + entity_id_list + ")")) {}
};

SQLiteEntityProvider::SQLiteEntityProvider(std::filesystem::path path)
    : db_path(path),
      thread_context(
          [this] (unsigned worker_id) -> Context * {
            return new Context(worker_id, db_path);
          },
          [] (void *ptr) {
            delete reinterpret_cast<Context *>(ptr);
          }) {}

SQLiteEntityProvider::~SQLiteEntityProvider(void) noexcept {}

void SQLiteEntityProvider::ClearCache(void) {}

unsigned SQLiteEntityProvider::VersionNumber(void) {
  unsigned start_version_number = 0u;
  unsigned end_version_number = 0u;

  std::shared_ptr<Context> context = thread_context.Lock();

//  try {
    sqlite::Transaction locker(context->db);
    sqlite::Statement &stmt = context->get_version_number;
    stmt.BindValues(0u);
    if (!stmt.ExecuteStep()) {
      return 0u;
    }

    auto result = stmt.Row();
    result.Columns(start_version_number);

    stmt.BindValues(1u);
    if (!stmt.ExecuteStep()) {
      return 0u;
    }
    result = stmt.Row();
    result.Columns(end_version_number);

//  } catch (...) {
//    assert(false);
//    return 0u;
//  }

  if (!start_version_number || !end_version_number) {
    return 0u;  // Uninitialized.

  } else if (start_version_number == end_version_number) {
    return 2u;  // Indexed.

  } else {
    return 1u;  // In-progress.
  }
}

unsigned SQLiteEntityProvider::VersionNumber(const Ptr &) {
  return VersionNumber();
}

void SQLiteEntityProvider::VersionNumberChanged(unsigned) {}

FilePathMap SQLiteEntityProvider::ListFiles(const Ptr &) {
  FilePathMap res;
  std::shared_ptr<Context> context = thread_context.Lock();
  sqlite::Statement &query = context->get_file_paths;
  while (query.ExecuteStep()) {
    RawEntityId id = kInvalidEntityId;
    std::filesystem::path path;
    query.Row().Columns(id, path);

    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FileId>(vid)) {
      res.emplace(std::move(path), std::get<FileId>(vid));
    } else {
      assert(false);
    }
  }

  return res;
}

FragmentIdList SQLiteEntityProvider::ListFragmentsInFile(
    const Ptr &, SpecificEntityId<FileId> file_id) {

  FragmentIdList res;
  res.reserve(128u);

  std::shared_ptr<Context> context = thread_context.Lock();
  sqlite::Statement &query = context->get_file_fragments;
  query.BindValues(file_id.Pack());

  while (query.ExecuteStep()) {
    RawEntityId id = kInvalidEntityId;
    query.Row().Columns(id);

    VariantId vid = EntityId(id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      res.emplace_back(std::get<FragmentId>(vid));
    } else {
      assert(false);
    }
  }

  return res;
}

std::shared_ptr<const FileImpl> SQLiteEntityProvider::FileFor(
    const Ptr &self, SpecificEntityId<FileId> file_id) {

  std::shared_ptr<Context> context = thread_context.Lock();
  sqlite::Statement &query = context->get_file_data;
  query.BindValues(file_id.Pack());

  if (!query.ExecuteStep()) {
    return {};
  }

  std::string data;
  query.Row().Columns(data);
  if (data.empty()) {
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<PackedFileImpl>(
      file_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FileImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<const FragmentImpl> SQLiteEntityProvider::FragmentFor(
    const Ptr &self, SpecificEntityId<FragmentId> fragment_id) {

  std::shared_ptr<Context> context = thread_context.Lock();
  sqlite::Statement &query = context->get_file_data;
  query.BindValues(fragment_id.Pack());
  if (!query.ExecuteStep()) {
    return {};
  }

  std::string data;
  query.Row().Columns(data);
  if (data.empty()) {
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<PackedFragmentImpl>(
      fragment_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FragmentImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<WeggliQueryResultImpl> SQLiteEntityProvider::Query(
    const Ptr &self, const WeggliQuery &query_tree) {
  (void) self;
  (void) query_tree;
  return {};

//  std::map<unsigned, unsigned> eol_offset_to_line_num;
//  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
//  auto &storage = d->GetStorage();
//  for(RawEntityId file_id = kMinEntityIdIncrement;
//        file_id < d->next_file_id;
//        ++file_id) {
//
//    // Get the contents of the file. We may fail, which is OK, and generally
//    // implies a bad file id. There can be small gaps in the file ID space,
//    // which otherwise mostly occupies the range `[1, N)`.
//    auto maybe_contents = storage.GetSerializedFile(file_id);
//    if (!maybe_contents) {
//      continue;  // Bad file ID. This is expected for the way we get them.
//    }
//
//    WithUncompressedMessageImpl(
//      "file", maybe_contents.value(),
//      [=, this, &eol_offset_to_line_num, &line_results]
//      (capnp::MessageReader &reader) {
//        mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
//        std::string_view file_contents(file.getData().cStr(),
//                                       file.getData().size());
//
//        eol_offset_to_line_num.clear();
//        for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
//          eol_offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
//        }
//
//        query_tree.ForEachMatch(
//            file_contents,
//            [=, this, &line_results] (const mx::WeggliMatchData &match) -> bool {
//              unsigned prev_line = 0;
//              for (auto i = match.begin_offset; i < match.end_offset; ++i) {
//                auto line_it = eol_offset_to_line_num.upper_bound(i);
//                if (line_it != eol_offset_to_line_num.end()) {
//                  auto line = line_it->second;
//                  if (line != prev_line) {
//                    prev_line = line;
//                    line_results.emplace(file_id, line);
//                  }
//                }
//              }
//              return true;
//            });
//        });
//  }
//
//  std::vector<mx::RawEntityId> fragment_ids;
//  fragment_ids.reserve(128u);
//
//  // Convert the file file:line pairs into overlapping fragment IDs.
//  for (auto prefix : line_results) {
//    storage.file_fragment_lines.GetByPrefix(
//        prefix,
//        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
//          if (fragment_ids.empty() || fragment_ids.back() != id) {
//            fragment_ids.push_back(id);
//          }
//          return true;
//        });
//  }
//
//  // Keep only unique fragment ids.
//  std::sort(fragment_ids.begin(), fragment_ids.end());
//  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
//  fragment_ids.erase(it, fragment_ids.end());
//
//  return std::make_shared<WeggliQueryResultImpl>(
//      query_tree, self, std::move(fragment_ids));
}

std::shared_ptr<RegexQueryResultImpl> SQLiteEntityProvider::Query(
    const Ptr &self, const RegexQuery &regex) {
  (void) self;
  (void) regex;
  return {};

//  std::map<unsigned, unsigned> offset_to_line_num;
//  std::set<std::tuple<mx::RawEntityId, unsigned>> line_results;
//  auto &storage = d->GetStorage();
//  for(RawEntityId file_id = kMinEntityIdIncrement;
//        file_id < d->next_file_id;
//        ++file_id) {
//    // Get the contents of the file. We may fail, which is OK, and generally
//    // implies a bad file id. There can be small gaps in the file ID space, which
//    // otherwise mostly occupies the range `[1, N)`.
//    auto maybe_contents = storage.GetSerializedFile(file_id);
//    if (!maybe_contents) {
//      continue;  // Bad file ID. This is expected for the way we get them.
//    }
//
//    WithUncompressedMessageImpl(
//        "file", maybe_contents.value(),
//        [=, this, &offset_to_line_num, &line_results]
//        (capnp::MessageReader &reader) {
//          mx::rpc::File::Reader file = reader.getRoot<mx::rpc::File>();
//          std::string_view file_contents(file.getData().cStr(),
//                                         file.getData().size());
//
//          offset_to_line_num.clear();
//          for (mx::rpc::UpperBound::Reader ubr : file.getEolOffsets()) {
//            offset_to_line_num.emplace(ubr.getOffset(), ubr.getVal());
//          }
//
//          regex.ForEachMatch(
//              file_contents,
//              [=, this, &line_results] (std::string_view, unsigned begin,
//                                        unsigned end) -> bool {
//                unsigned prev_line = 0;
//                for (auto i = begin; i < end; ++i) {
//                  auto line_it = offset_to_line_num.upper_bound(i);
//                  if (line_it != offset_to_line_num.end()) {
//                    auto line = line_it->second;
//                    if (line != prev_line) {
//                      prev_line = line;
//                      line_results.emplace(file_id, line);
//                    }
//                  }
//                }
//                return true;
//              });
//        });
//  }
//
//  std::vector<mx::RawEntityId> fragment_ids;
//  fragment_ids.reserve(128u);
//  // Convert the file file:line pairs into overlapping fragment IDs.
//  for (auto prefix : line_results) {
//    storage.file_fragment_lines.GetByPrefix(
//        prefix,
//        [&fragment_ids] (mx::RawEntityId, unsigned, mx::RawEntityId id) {
//          if (fragment_ids.empty() || fragment_ids.back() != id) {
//            fragment_ids.push_back(id);
//          }
//          return true;
//        });
//  }
//  // Keep only unique fragment ids.
//  std::sort(fragment_ids.begin(), fragment_ids.end());
//  auto it = std::unique(fragment_ids.begin(), fragment_ids.end());
//  fragment_ids.erase(it, fragment_ids.end());
//
//  return std::make_shared<RegexQueryResultImpl>(
//      regex, self, std::move(fragment_ids));
}

DeclarationIdList SQLiteEntityProvider::Redeclarations(
    const Ptr &, SpecificEntityId<DeclarationId> id) {

  std::shared_ptr<Context> context = thread_context.Lock();
  auto add_entity_id = context->add_entity_id_to_list;
  sqlite::Transaction transaction(context->db);

  // Clear our old entity id list.
  context->clear_entity_id_list.Execute();

  // Initialize the new entity ID list.
  add_entity_id.BindValues(id.Pack());
  add_entity_id.Execute();

  FillEntityIdsWithRedeclarations(*context, id);

  auto ret = ReadRedeclarations(*context);

  return ret;
}

void SQLiteEntityProvider::FillEntityIdsWithRedeclarations(
      Context &context, SpecificEntityId<DeclarationId> id) {
  RawEntityId raw_id = id.Pack();
  sqlite::Statement &mangled_name_query = context.get_redecls_by_mangled_name;
  sqlite::Statement &redecl_query = context.get_redecls_by_entity_id;

  // Expand the set of IDs via name mangling.
  switch (id.Unpack().kind) {
    case DeclKind::FUNCTION:
    case DeclKind::CXX_METHOD:
    case DeclKind::CXX_DESTRUCTOR:
    case DeclKind::CXX_CONVERSION:
    case DeclKind::CXX_CONSTRUCTOR:
    case DeclKind::CXX_DEDUCTION_GUIDE:

    case DeclKind::VAR:
    case DeclKind::DECOMPOSITION:
    case DeclKind::IMPLICIT_PARAM:
    case DeclKind::OMP_CAPTURED_EXPR:
    case DeclKind::PARM_VAR:
    case DeclKind::VAR_TEMPLATE_SPECIALIZATION:
    case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      mangled_name_query.Execute();
      break;

    default:
      break;
  }

  redecl_query.Execute();
}

DeclarationIdList SQLiteEntityProvider::ReadRedeclarations(Context &context) {
  DeclarationIdList ret;
  ret.reserve(8u);

  sqlite::Statement &get_entity_ids = context.get_entity_ids;
  while (get_entity_ids.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_entity_ids.Row().Columns(raw_id);

    VariantId vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      ret.emplace_back(std::get<DeclarationId>(vid));
    } else {
      assert(false);
    }
  }

  // Sort the redeclaration IDs to that they are always in the same order,
  // regardless of which one we ask for first, then partition them and move
  // the definitions before the declarations.
  std::sort(ret.begin(), ret.end());
  auto it = std::unique(ret.begin(), ret.end());
  ret.erase(it, ret.end());
  std::partition(
      ret.begin(), ret.end(),
      [] (SpecificEntityId<DeclarationId> eid) {
        return eid.Unpack().is_definition;
      });

  return ret;
}

void SQLiteEntityProvider::FillFragments(
    Context &context, sqlite::Statement &get_fragments,
    RawEntityId raw_id, DeclarationIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  sqlite::Statement &add_entity_id = context.add_entity_id_to_list;
  sqlite::Statement &get_entity_ids = context.get_entity_ids;

  sqlite::Transaction transaction(context.db);

  // Clear our old entity id list.
  context.clear_entity_id_list.Execute();

  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  EntityId eid(raw_id);
  VariantId vid = eid.Unpack();

  // We need to find uses of declarations.
  if (std::holds_alternative<DeclarationId>(vid)) {
    DeclarationId id = std::get<DeclarationId>(vid);

    // If we don't have a set of redeclarations, then calculate them.
    if (redecl_ids_out.empty()) {
      add_entity_id.BindValues(eid);
      add_entity_id.Execute();
      FillEntityIdsWithRedeclarations(context, id);
      redecl_ids_out = ReadRedeclarations(context);
      assert(!redecl_ids_out.empty());
      assert(std::find(redecl_ids_out.begin(), redecl_ids_out.end(), eid) !=
             redecl_ids_out.end());

    // If we already have a set then use them.
    } else {
      for (SpecificEntityId<DeclarationId> did : redecl_ids_out) {
        add_entity_id.BindValues(did.Pack());
        add_entity_id.Execute();
      }
    }

    // Make sure all fragments containing each redeclaration are present in
    // the output fragment ID list.
    for (SpecificEntityId<DeclarationId> did : redecl_ids_out) {
      fragment_ids_out.emplace_back(FragmentId(id.fragment_id));
    }

  // We need to find uses of macros.
  } else if (std::holds_alternative<MacroId>(vid)) {
    MacroId id = std::get<MacroId>(vid);

    fragment_ids_out.emplace_back(FragmentId(id.fragment_id));
    add_entity_id.BindValues(raw_id);
    add_entity_id.Execute();

  // We need to find uses of files.
  } else if (std::holds_alternative<FileId>(vid)) {
    add_entity_id.BindValues(raw_id);
    add_entity_id.Execute();

  } else {
    assert(false);
    return;
  }

  // Get the using fragments.
  while (get_fragments.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_fragments.Row().Columns(raw_id);

    VariantId vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      fragment_ids_out.emplace_back(std::get<FragmentId>(vid));
    } else {
      assert(false);
    }
  }

  // Keep only unique fragment IDs.
  std::sort(fragment_ids_out.begin(), fragment_ids_out.end());
  auto it = std::unique(fragment_ids_out.begin(), fragment_ids_out.end());
  fragment_ids_out.erase(it, fragment_ids_out.end());
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for uses.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid, DeclarationIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  std::shared_ptr<Context> context = thread_context.Lock();
  FillFragments(*context, context->get_uses, eid, redecl_ids_out,
                fragment_ids_out);
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for references.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid, DeclarationIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  std::shared_ptr<Context> context = thread_context.Lock();
  FillFragments(*context, context->get_references, eid, redecl_ids_out,
                fragment_ids_out);
}

void SQLiteEntityProvider::FindSymbol(const Ptr &, std::string symbol,
                                      std::vector<RawEntityId> &entity_ids) {
  entity_ids.clear();

  std::shared_ptr<Context> context = thread_context.Lock();
  sqlite::Statement &symbol_query = context->get_entities_by_name;
  for (symbol_query.BindValues(symbol); symbol_query.ExecuteStep(); ) {
    RawEntityId entity_id = kInvalidEntityId;
    symbol_query.BindValues(entity_id);
    VariantId vid = EntityId(entity_id).Unpack();
    if (std::holds_alternative<MacroId>(vid) ||
        std::holds_alternative<DeclarationId>(vid)) {
      entity_ids.push_back(entity_id);

    } else {
      assert(false);
    }
  }

  std::sort(entity_ids.begin(), entity_ids.end());
  auto it = std::unique(entity_ids.begin(), entity_ids.end());
  entity_ids.erase(it, entity_ids.end());
}

EntityProvider::Ptr EntityProvider::from_database(std::filesystem::path path) {
  return std::make_shared<SQLiteEntityProvider>(path);
}

}  // namespace mx
