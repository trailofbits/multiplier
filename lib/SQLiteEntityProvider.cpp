// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"

#include <gap/core/generator.hpp>
#include <multiplier/Database.h>
#include <multiplier/Entities/TokenKind.h>
#include <zdict.h>
#include <zstd.h>

#include "API.h"
#include "Attr.h"
#include "Decl.h"
#include "File.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "SQLiteStore.h"
#include "Stmt.h"
#include "Type.h"

namespace mx {

// Holds on to the dictionaries.
class SQLiteDecompressionDictionary {
 private:
  SQLiteDecompressionDictionary(void) = delete;

 public:
  static constexpr size_t kNumEntityCategories = NumEnumerators(EntityCategory{});

  std::array<ZSTD_DDict *, kNumEntityCategories> dict;

  explicit SQLiteDecompressionDictionary(
      std::filesystem::path path,
      SQLiteDecompressionDictionary *prev = nullptr);

  ~SQLiteDecompressionDictionary(void);
};

class SQLiteEntityProviderImpl {
 public:
  const std::string entity_id_list;
  sqlite::Connection db;
  sqlite::Statement get_version_number;
  sqlite::Statement get_file_paths;
  sqlite::Statement get_file_fragments;
  sqlite::Statement clear_entity_id_list;
  sqlite::Statement add_entity_id_to_list;
  sqlite::Statement get_entity_ids;
  sqlite::Statement expand_entity_id_list_with_redecls;
  sqlite::Statement get_entities_by_name;
  sqlite::Statement get_uses;
  sqlite::Statement get_references;
  sqlite::Statement get_fragments_covered_by_tokens;

#define DECLARE_GETTERS(type_name, lower_name, ...) \
    sqlite::Statement get_ ## lower_name ## _ids_by_fragment ; \
    sqlite::Statement get_ ## lower_name ## _by_id ; \

  MX_FOR_EACH_ENTITY_CATEGORY(DECLARE_GETTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              DECLARE_GETTERS,
                              DECLARE_GETTERS)
#undef DECLARE_GETTERS

  // Context used to decompress compressed Cap'n Proto entity structures
  // (see AST.capnp).
  ZSTD_DCtx * const decompression_context;

  ~SQLiteEntityProviderImpl(void);
  SQLiteEntityProviderImpl(unsigned worker_index, std::filesystem::path path);
};

namespace {

static sqlite::Connection Connect(std::filesystem::path path,
                                  const std::string &entity_id_list) {
  sqlite::Connection db(path);

  db.Execute("PRAGMA synchronous = " MX_DATABASE_PRAGMA_SYNCHRONOUS);
  db.Execute("PRAGMA temp_store = " MX_DATABASE_TEMP_STORE);
  db.Execute("PRAGMA journal_mode = " MX_DATABASE_JOURNAL_MODE);

  db.Execute(
      "CREATE TEMPORARY TABLE IF NOT EXISTS " + entity_id_list + " ("
      "  entity_id INT NOT NULL,"
      "  PRIMARY KEY(entity_id)"
      ") WITHOUT rowid");

  return db;
}

// Get all of the entity IDs from a query.
//
// TODO(pag): Eventually, we'd want to just query and generate, but we don't
//            yet support query reuse/caching.
static std::vector<RawEntityId> GetEntityIds(sqlite::Statement &query,
                                             PackedFragmentId frag_id) {
  std::vector<RawEntityId> ids;
  query.BindValues(frag_id.Pack());
  while (query.ExecuteStep()) {
    auto row = query.Row();
    RawEntityId id = kInvalidEntityId;
    std::string storage;
    row.Columns(id);
    ids.push_back(id);
  }
  query.Reset();
  return ids;
}

// Decompress a compressed entity into a kj array, or use by `EntityImpl`.
static kj::Array<capnp::word> Decompress(ZSTD_DCtx *context, ZSTD_DDict *dict,
                                         std::string data) {
  size_t bound = ZSTD_getFrameContentSize(data.data(), data.size());
  kj::Array<capnp::word> array = kj::heapArray<capnp::word>(
      (bound + sizeof(capnp::word) - 1u) / sizeof(capnp::word));

  size_t ret = ZSTD_decompress_usingDDict(
      context, array.asPtr().begin(), bound,
      data.data(), data.size(), dict);

  assert(!ZSTD_isError(ret));
  assert(ret <= bound);
  (void) ret;

  return array;
}

}  // namespace

SQLiteDecompressionDictionary::SQLiteDecompressionDictionary(
    std::filesystem::path path,
    SQLiteDecompressionDictionary *prev) {

  sqlite::Connection db(path, true  /* read_only */);
  sqlite::Statement dictionaries = db.Prepare(
      "SELECT entity_category, data FROM entity_dictionary");

  std::string data;
  while (dictionaries.ExecuteStep()) {
    unsigned category = 0u;
    data.clear();
    dictionaries.Row().Columns(category, data);
    if (!category || category >= kNumEntityCategories) {
      assert(false);
      continue;
    }

    // ZSTD dictionaries must be at least 8 bytes (for the header).
    if (8u > data.size()) {
      assert(false);
      continue;
    }

    // Steal the old dictionary.
    if (prev && prev->dict[category]) {
      dict[category] = prev->dict[category];
      prev->dict[category] = nullptr;
      continue;
    }

    dict[category] = ZSTD_createDDict(data.data(), data.size());
  }

  dictionaries.Reset();
}

SQLiteDecompressionDictionary::~SQLiteDecompressionDictionary(void) {
  for (ZSTD_DDict *d : dict) {
    if (d) {
      ZSTD_freeDDict(d);
    }
  }
}

SQLiteEntityProviderImpl::~SQLiteEntityProviderImpl(void) {
  ZSTD_freeDCtx(decompression_context);
}

SQLiteEntityProviderImpl::SQLiteEntityProviderImpl(unsigned worker_index,
                                                   std::filesystem::path path)
    : entity_id_list("entity_id_list_" + std::to_string(worker_index)),
      db(Connect(path, entity_id_list)),
      get_version_number(db.Prepare(
          "SELECT COUNT(rowid) FROM version WHERE action = ?1")),
      get_file_paths(db.Prepare(
          "SELECT file_id, path FROM file_path")),
      get_file_fragments(db.Prepare(
          "SELECT DISTINCT(fragment_id) "
          "FROM fragment_file "
          "WHERE file_id = ?1")),
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

#if MX_DATABASE_HAS_FTS5
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
          "SELECT DISTINCT(r.from_entity_id) FROM reference AS r "
          "JOIN " + entity_id_list + " AS l "
          "ON r.to_entity_id = l.entity_id")),

      get_fragments_covered_by_tokens(db.Prepare(
          "SELECT DISTINCT(ffr.fragment_id) "
          "FROM fragment_file_range AS ffr "
          "JOIN " + entity_id_list + " AS el "
          "ON ffr.first_file_token_offset <= el.entity_id "
          "AND ffr.last_file_token_offset >= el.entity_id "
          "AND ffr.file_id = ?1")),

#define INIT_GETTERS(type_name, lower_name, enum_name, id) \
    get_ ## lower_name ## _ids_by_fragment(db.Prepare( \
          "SELECT " #lower_name "_id " \
          "FROM " #lower_name " " \
          "WHERE entity_id_to_fragment_id(" #lower_name "_id) = ?1 " \
          "ORDER BY " #lower_name "_id ASC")), \
    get_ ## lower_name ## _by_id(db.Prepare( \
          "SELECT data " \
          "FROM " #lower_name " " \
          "WHERE " #lower_name "_id = ?1")),

    MX_FOR_EACH_ENTITY_CATEGORY(INIT_GETTERS,
                                MX_IGNORE_ENTITY_CATEGORY,
                                INIT_GETTERS,
                                INIT_GETTERS)
#undef INIT_GETTERS

    decompression_context(ZSTD_createDCtx()) {}

SQLiteEntityProvider::SQLiteEntityProvider(std::filesystem::path path)
    : db_path(path),
      dict(new SQLiteDecompressionDictionary(path)),
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

void SQLiteEntityProvider::VersionNumberChanged(unsigned) {
  dict.reset(new SQLiteDecompressionDictionary(db_path, dict.get()));
}

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
    if (!std::holds_alternative<FragmentId>(vid)) {
      assert(false);
      continue;
    }

    res.emplace_back(std::get<FragmentId>(vid));
  }
  query.Reset();

  return res;
}

// Return the list of fragments covering / overlapping some tokens in a file.
FragmentIdList SQLiteEntityProvider::FragmentsCoveringTokens(
    const Ptr &, PackedFileId file_id, std::vector<EntityOffset> offsets) {

  ImplPtr context = impl.Lock();
  sqlite::Statement &add_token_offset = context->add_entity_id_to_list;
  sqlite::Statement &get_fragment_ids = context->get_fragments_covered_by_tokens;

  sqlite::AbortingTransaction temporary_changes_only(context->db);

  std::sort(offsets.begin(), offsets.end());
  auto it = std::unique(offsets.begin(), offsets.end());
  offsets.erase(it, offsets.end());
  it = std::remove_if(offsets.begin(), offsets.end(),
                      +[] (EntityOffset offset) { return offset == ~0u; });
  offsets.erase(it, offsets.end());

  for (EntityOffset token_offset : offsets) {
    add_token_offset.BindValues(token_offset);
    add_token_offset.Execute();
  }

  FragmentIdList ret;

  get_fragment_ids.BindValues(file_id.Pack());
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

  get_fragment_ids.Reset();

  return ret;
}

RawEntityIdList SQLiteEntityProvider::Redeclarations(
    const Ptr &, SpecificEntityId<DeclId> id) {

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

RawEntityIdList SQLiteEntityProvider::ReadRedeclarations(
    SQLiteEntityProviderImpl &context) {
  RawEntityIdList ret;
  ret.reserve(8u);

  context.expand_entity_id_list_with_redecls.Execute();

  sqlite::Statement &get_redecl_ids = context.get_entity_ids;
  while (get_redecl_ids.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_redecl_ids.Row().Columns(raw_id);

    VariantId vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<DeclId>(vid)) {
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
        return std::get<DeclId>(EntityId(eid).Unpack()).is_definition;
      });

  return ret;
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for uses.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillUses(
    const Ptr &, RawEntityId raw_id, RawEntityIdList &redecl_ids_out,
    FragmentIdList &fragment_ids_out) {

  ImplPtr context = impl.Lock();
  sqlite::Statement &get_fragments = context->get_uses;
  sqlite::Statement &add_entity_id = context->add_entity_id_to_list;
  sqlite::AbortingTransaction temporary_changes_only(context->db);

  // Clear our old entity id list.
  context->clear_entity_id_list.Execute();

  fragment_ids_out.clear();
  fragment_ids_out.reserve(16u);

  EntityId eid(raw_id);
  VariantId vid = eid.Unpack();

  // We need to find uses of declarations.
  if (std::holds_alternative<DeclId>(vid)) {

    // If we don't have a set of redeclarations, then calculate them.
    if (redecl_ids_out.empty()) {
      add_entity_id.BindValues(eid);
      add_entity_id.Execute();

      redecl_ids_out = ReadRedeclarations(*context);
      assert(!redecl_ids_out.empty());
      assert(std::find(redecl_ids_out.begin(), redecl_ids_out.end(),
                       eid.Pack()) != redecl_ids_out.end());

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
    raw_id = kInvalidEntityId;
    get_fragments.Row().Columns(raw_id);

    vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<FragmentId>(vid)) {
      fragment_ids_out.emplace_back(std::get<FragmentId>(vid));
    } else {
      assert(false);
    }
  }

  get_fragments.Reset();
}

// Fill out `redecl_ids_out` and `fragment_ids_out` with the set of things
// to analyze when looking for references.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
void SQLiteEntityProvider::FillReferences(
    const Ptr &, RawEntityId raw_id, RawEntityIdList &redecl_ids_out,
    RawEntityIdList &references_ids_out) {

  ImplPtr context = impl.Lock();
  sqlite::Statement &get_references = context->get_references;
  sqlite::Statement &add_entity_id = context->add_entity_id_to_list;
  sqlite::AbortingTransaction temporary_changes_only(context->db);

  // Clear our old entity id list.
  context->clear_entity_id_list.Execute();

  references_ids_out.clear();
  references_ids_out.reserve(16u);

  EntityId eid(raw_id);
  VariantId vid = eid.Unpack();

  // We need to find uses of declarations.
  if (std::holds_alternative<DeclId>(vid)) {

    // If we don't have a set of redeclarations, then calculate them.
    if (redecl_ids_out.empty()) {
      add_entity_id.BindValues(eid);
      add_entity_id.Execute();

      redecl_ids_out = ReadRedeclarations(*context);
      assert(!redecl_ids_out.empty());
      assert(std::find(redecl_ids_out.begin(), redecl_ids_out.end(),
                       eid.Pack()) != redecl_ids_out.end());

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
  while (get_references.ExecuteStep()) {
    raw_id = kInvalidEntityId;
    get_references.Row().Columns(raw_id);

    vid = EntityId(raw_id).Unpack();
    if (std::holds_alternative<StmtId>(vid) ||
        std::holds_alternative<MacroId>(vid)) {
      references_ids_out.emplace_back(raw_id);
    } else {
      assert(false);
    }
  }

  get_references.Reset();
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
        std::holds_alternative<DeclId>(vid)) {
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

#define DEFINE_GETTERS(type_name, lower_name, enum_name, category_) \
    gap::generator<type_name ## ImplPtr> SQLiteEntityProvider:: type_name ## sFor( \
        const Ptr &ep, PackedFragmentId id) { \
      ImplPtr context = impl.Lock(); \
      for (RawEntityId eid : GetEntityIds( \
               context->get_ ## lower_name ## _ids_by_fragment, id)) { \
        if (type_name ## ImplPtr ptr = ep->type_name ## For(ep, eid)) { \
          co_yield ptr; \
        } \
      } \
    } \
    \
    type_name ## ImplPtr SQLiteEntityProvider:: type_name ## For( \
        const Ptr &ep, RawEntityId raw_id) { \
      if (raw_id == kInvalidEntityId) { \
        return {}; \
      } \
      \
      assert(CategoryFromEntityId(raw_id) == EntityCategory::enum_name); \
      const auto cat_index = static_cast<unsigned>(EntityCategory::enum_name); \
      auto ddict = dict->dict[cat_index]; \
      if (!ddict) { \
        return {}; \
      } \
      ImplPtr context = impl.Lock(); \
      sqlite::Statement &query = context->get_ ## lower_name ## _by_id; \
      query.BindValues(raw_id); \
      if (!query.ExecuteStep()) { \
        query.Reset(); \
        return {}; \
      } \
      \
      std::string data; \
      query.Row().Columns(data); \
      query.Reset(); \
      \
      return std::make_shared<type_name ## Impl>( \
          ep, \
          Decompress(context->decompression_context, dict->dict[cat_index], \
                     std::move(data)), \
          raw_id); \
    }

MX_FOR_EACH_ENTITY_CATEGORY(DEFINE_GETTERS,
                            MX_IGNORE_ENTITY_CATEGORY,
                            DEFINE_GETTERS,
                            DEFINE_GETTERS)
#undef DEFINE_GETTERS

EntityProvider::Ptr EntityProvider::from_database(std::filesystem::path path) {
  return std::make_shared<SQLiteEntityProvider>(path);
}

}  // namespace mx
