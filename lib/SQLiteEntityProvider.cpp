// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"

#include <multiplier/Database.h>
#include <multiplier/Types.h>

#include "API.h"
#include "Compress.h"
#include "File.h"
#include "Fragment.h"
#include "SQLiteStore.h"

namespace mx {
namespace {

static sqlite::Connection Connect(std::filesystem::path path,
                                  const std::string &entity_id_list,
                                  const std::string &line_number_list) {
  sqlite::Connection db(path);

  db.Execute("PRAGMA synchronous = " MX_DATABASE_PRAGMA_SYNCHRONOUS);
  db.Execute("PRAGMA temp_store = " MX_DATABASE_TEMP_STORE);
  db.Execute("PRAGMA journal_mode = " MX_DATABASE_JOURNAL_MODE);

  db.Execute(
      "CREATE TEMPORARY TABLE IF NOT EXISTS " + entity_id_list + " ("
      "  entity_id INT NOT NULL,"
      "  PRIMARY KEY(entity_id)"
      ") WITHOUT rowid");

  db.Execute(
      "CREATE TEMPORARY TABLE IF NOT EXISTS " + line_number_list + " ("
      "  file_id INT NOT NULL,"
      "  line_number INT NOT NULL,"
      "  PRIMARY KEY(line_number)"
      ") WITHOUT rowid");

  return db;
}

}  // namespace

class SQLiteEntityProviderImpl {
 public:
  const std::string entity_id_list;
  const std::string line_number_list;
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
  sqlite::Statement expand_entity_id_list_with_redecls;
  sqlite::Statement get_entities_by_name;
  sqlite::Statement get_uses;
  sqlite::Statement get_references;
  sqlite::Statement add_line_number_to_list;
  sqlite::Statement get_fragments_covered_by_lines;

  SQLiteEntityProviderImpl(unsigned worker_index, std::filesystem::path path)
      : entity_id_list("entity_id_list_" + std::to_string(worker_index)),
        line_number_list("line_number_list_" + std::to_string(worker_index)),
        db(Connect(path, entity_id_list, line_number_list)),
        get_file_by_id(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_frag_by_id(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        get_version_number(db.Prepare(
            "SELECT COUNT(rowid) FROM version WHERE action = ?1")),
        get_file_paths(db.Prepare(
            "SELECT file_id, path FROM file_path")),
        get_file_fragments(db.Prepare(
            "SELECT DISTINCT(fragment_id) FROM fragment_line WHERE file_id = ?1")),
        get_file_data(db.Prepare(
            "SELECT data FROM file WHERE file_id = ?1")),
        get_fragment_data(db.Prepare(
            "SELECT data FROM fragment WHERE fragment_id = ?1")),
        clear_entity_id_list(db.Prepare(
            "DELETE FROM " + entity_id_list)),
        add_entity_id_to_list(db.Prepare(
            "INSERT OR IGNORE INTO " + entity_id_list +
            " (entity_id) VALUES (?1)")),
        get_entity_ids(db.Prepare(
            "SELECT entity_id FROM " + entity_id_list)),
        expand_entity_id_list_with_redecls(db.Prepare(
            "INSERT OR IGNORE INTO " + entity_id_list  + " (entity_id) "
            "WITH RECURSIVE transitive_redeclaration(entity_id) "
            "AS NOT MATERIALIZED ("
            "      SELECT l.entity_id FROM " + entity_id_list + " AS l"
            "    UNION"
            "      SELECT r1.redecl_id"
            "      FROM transitive_redeclaration AS tc1"
            "      JOIN redeclaration AS r1 ON tc1.entity_id = r1.decl_id"
            "    UNION"
            "      SELECT r2.decl_id"
            "      FROM transitive_redeclaration AS tc2"
            "      JOIN redeclaration AS r2 ON tc2.entity_id = r2.redecl_id"
            "    UNION"
            "      SELECT mn2.entity_id"
            "      FROM transitive_redeclaration AS tc3"
            "      JOIN mangled_name AS mn1 ON tc3.entity_id = mn1.entity_id"
            "      JOIN mangled_name AS mn2 ON mn1.data = mn2.data"
            ") SELECT entity_id FROM transitive_redeclaration")),

#if MX_SQLITE_HAS_FTS5
        get_entities_by_name(db.Prepare(
            "SELECT rowid FROM symbol WHERE name MATCH ?1 || '*'")),
#else
        get_entities_by_name(db.Prepare(
            "SELECT rowid FROM symbol WHERE name LIKE '%' || ?1 || '%'")),
#endif
        get_uses(db.Prepare(
            "SELECT DISTINCT(u.fragment_id) FROM use AS u "
            "JOIN " + entity_id_list + " AS l "
            "ON u.entity_id = l.entity_id")),

        get_references(db.Prepare(
            "SELECT DISTINCT(r.fragment_id) FROM reference AS r "
            "JOIN " + entity_id_list + " AS l "
            "ON r.entity_id = l.entity_id")),
        add_line_number_to_list(db.Prepare(
            "INSERT OR IGNORE INTO " + line_number_list +
            " (file_id, line_number) VALUES (?1, ?2)")),
        get_fragments_covered_by_lines(db.Prepare(
            "SELECT DISTINCT(fln.fragment_id) "
            "FROM fragment_line AS fln "
            "JOIN " + line_number_list + " AS lnl "
            "ON fln.file_id = lnl.file_id "
            "WHERE fln.first_line_number <= lnl.line_number "
            "AND fln.last_line_number >= lnl.line_number")) {}
};

SQLiteEntityProvider::SQLiteEntityProvider(std::filesystem::path path)
    : db_path(path),
      impl(
          [this] (unsigned worker_id) -> SQLiteEntityProviderImpl * {
            return new SQLiteEntityProviderImpl(worker_id, db_path);
          },
          [] (void *ptr) {
            delete reinterpret_cast<SQLiteEntityProviderImpl *>(ptr);
          }) {}

SQLiteEntityProvider::~SQLiteEntityProvider(void) noexcept {}

void SQLiteEntityProvider::ClearCache(void) {}

unsigned SQLiteEntityProvider::VersionNumber(void) {
  unsigned start_version_number = 0u;
  unsigned end_version_number = 0u;

  ImplPtr context = impl.Lock();

//  try {
    sqlite::Transaction locker(context->db);
    sqlite::Statement &stmt = context->get_version_number;
    stmt.BindValues(0u);
    if (!stmt.ExecuteStep()) {
      stmt.Reset();
      return 0u;
    }

    stmt.Row().Columns(start_version_number);
    stmt.Reset();

    stmt.BindValues(1u);
    if (!stmt.ExecuteStep()) {
      stmt.Reset();
      return 0u;
    }

    stmt.Row().Columns(end_version_number);
    stmt.Reset();

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
  ImplPtr context = impl.Lock();
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
  query.Reset();

  return res;
}

FragmentIdList SQLiteEntityProvider::ListFragmentsInFile(
    const Ptr &, SpecificEntityId<FileId> file_id) {

  FragmentIdList res;
  res.reserve(128u);

  ImplPtr context = impl.Lock();
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
  query.Reset();

  return res;
}

std::shared_ptr<const FileImpl> SQLiteEntityProvider::FileFor(
    const Ptr &self, SpecificEntityId<FileId> file_id) {

  ImplPtr context = impl.Lock();
  sqlite::Statement &query = context->get_file_data;
  query.BindValues(file_id.Pack());

  if (!query.ExecuteStep()) {
    query.Reset();
    return {};
  }

  std::string data;
  query.Row().Columns(data);
  query.Reset();

  if (data.empty()) {
    assert(false);
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<FileImpl>(
      file_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FileImpl::Ptr(std::move(ret), ret_ptr);
}

std::shared_ptr<const FragmentImpl> SQLiteEntityProvider::FragmentFor(
    const Ptr &self, SpecificEntityId<FragmentId> fragment_id) {

  ImplPtr context = impl.Lock();
  sqlite::Statement &query = context->get_fragment_data;
  query.BindValues(fragment_id.Pack());
  if (!query.ExecuteStep()) {
    query.Reset();
    return {};
  }

  std::string data;
  query.Row().Columns(data);
  query.Reset();

  if (data.empty()) {
    assert(false);
    return {};
  }

  // TODO(pag): This is a yolo-ducated of a guess.
  capnp::MessageSize size{((data.size() + 7u / 8u)), 0u};
  capnp::Data::Reader contents_reader(
      reinterpret_cast<const capnp::byte *>(data.data()),
      data.size());

  auto ret = std::make_shared<FragmentImpl>(
      fragment_id.Unpack(), self, contents_reader);
  auto ret_ptr = ret.get();
  return FragmentImpl::Ptr(std::move(ret), ret_ptr);
}

// Return the list of fragments covering / overlapping some lines in a file.
FragmentIdList SQLiteEntityProvider::FragmentsCoveringLines(
    const Ptr &self, PackedFileId file_id, std::vector<unsigned> lines) {

  RawEntityId raw_file_id = file_id.Pack();

  ImplPtr context = impl.Lock();
  sqlite::Statement &add_line_number = context->add_line_number_to_list;
  sqlite::Statement &get_fragment_ids = context->get_fragments_covered_by_lines;

  sqlite::AbortingTransaction temporary_changes_only(context->db);

  std::sort(lines.begin(), lines.end());
  auto it = std::unique(lines.begin(), lines.end());
  lines.erase(it, lines.end());

  for (unsigned line : lines) {
    add_line_number.BindValues(raw_file_id, line);
    add_line_number.Execute();
  }

  FragmentIdList ret;
  while (get_fragment_ids.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_fragment_ids.Row().Columns(raw_id);

    VariantId vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      ret.emplace_back(std::get<FragmentId>(vid));
    } else {
      assert(false);
    }
  }

  return ret;
}

RawEntityIdList SQLiteEntityProvider::Redeclarations(
    const Ptr &, SpecificEntityId<DeclarationId> id) {

  ImplPtr context = impl.Lock();
  auto add_entity_id = context->add_entity_id_to_list;

  sqlite::AbortingTransaction temporary_changes_only(context->db);

  // Clear our old entity id list.
  context->clear_entity_id_list.Execute();

  // Initialize the new entity ID list.
  add_entity_id.BindValues(id.Pack());
  add_entity_id.Execute();

  return ReadRedeclarations(*context);
}

RawEntityIdList SQLiteEntityProvider::ReadRedeclarations(SQLiteEntityProviderImpl &context) {
  RawEntityIdList ret;
  ret.reserve(8u);

  context.expand_entity_id_list_with_redecls.Execute();

  sqlite::Statement &get_redecl_ids = context.get_entity_ids;
  while (get_redecl_ids.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_redecl_ids.Row().Columns(raw_id);

    VariantId vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<DeclarationId>(vid)) {
      ret.emplace_back(raw_id);
    } else {
      assert(false);
    }
  }
  get_redecl_ids.Reset();

  // Sort the redeclaration IDs to that they are always in the same order,
  // regardless of which one we ask for first, then partition them and move
  // the definitions before the declarations.
  std::sort(ret.begin(), ret.end());
  auto it = std::unique(ret.begin(), ret.end());
  ret.erase(it, ret.end());

  std::partition(
      ret.begin(), ret.end(),
      [] (RawEntityId eid) {
        return std::get<DeclarationId>(EntityId(eid).Unpack()).is_definition;
      });

  return ret;
}

void SQLiteEntityProvider::FillFragments(
    SQLiteEntityProviderImpl &context, sqlite::Statement &get_fragments,
    RawEntityId raw_id, RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  sqlite::Statement &add_entity_id = context.add_entity_id_to_list;
  sqlite::Statement &get_entity_ids = context.get_entity_ids;

  sqlite::AbortingTransaction temporary_changes_only(context.db);

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

      redecl_ids_out = ReadRedeclarations(context);
      assert(!redecl_ids_out.empty());
      assert(std::find(redecl_ids_out.begin(), redecl_ids_out.end(), eid) !=
             redecl_ids_out.end());

    // If we already have a set then use them.
    } else {
      for (RawEntityId raw_redecl_id : redecl_ids_out) {
        add_entity_id.BindValues(raw_redecl_id);
        add_entity_id.Execute();
      }
    }

  // Macros, files, tokens, etc.
  } else {
    assert(redecl_ids_out.empty());
    add_entity_id.BindValues(raw_id);
    add_entity_id.Execute();
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

  get_fragments.Reset();
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for uses.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillUses(
    const Ptr &self, RawEntityId eid, RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {
  ImplPtr context = impl.Lock();
  FillFragments(*context, context->get_uses, eid, redecl_ids_out,
                fragment_ids_out);
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for references.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillReferences(
    const Ptr &self, RawEntityId eid, RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  ImplPtr context = impl.Lock();
  FillFragments(*context, context->get_references, eid, redecl_ids_out,
                fragment_ids_out);
}

void SQLiteEntityProvider::FindSymbol(const Ptr &, std::string symbol,
                                      std::vector<RawEntityId> &entity_ids) {
  entity_ids.clear();

  ImplPtr context = impl.Lock();
  sqlite::Statement &symbol_query = context->get_entities_by_name;
  for (symbol_query.BindValues(symbol); symbol_query.ExecuteStep(); ) {
    RawEntityId entity_id = kInvalidEntityId;
    symbol_query.Row().Columns(entity_id);
    VariantId vid = EntityId(entity_id).Unpack();
    if (std::holds_alternative<MacroId>(vid) ||
        std::holds_alternative<DeclarationId>(vid)) {
      entity_ids.push_back(entity_id);

    } else {
      assert(false);
    }
  }
  symbol_query.Reset();

  std::sort(entity_ids.begin(), entity_ids.end());
  auto it = std::unique(entity_ids.begin(), entity_ids.end());
  entity_ids.erase(it, entity_ids.end());
}

EntityProvider::Ptr EntityProvider::from_database(std::filesystem::path path) {
  return std::make_shared<SQLiteEntityProvider>(path);
}

}  // namespace mx
