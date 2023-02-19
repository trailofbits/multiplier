// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "SQLiteEntityProvider.h"

#include <array>
#include <gap/core/generator.hpp>
#include <multiplier/Database.h>
#include <multiplier/Entities/TokenKind.h>
#include <multiplier/Reference.h>
#include <type_traits>
#include <zdict.h>
#include <zstd.h>

#include "API.h"
#include "Attr.h"
#include "Decl.h"
#include "File.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Reference.h"
#include "SQLiteStore.h"
#include "Stmt.h"
#include "Type.h"

#define MX_REFERENCE_PAGE_SIZE 128
#define MX_ID_LIST_PAGE_SIZE 128

#define MX_TO_STR_(a) #a
#define MX_TO_STR(a) MX_TO_STR_(a)

namespace mx {

// Holds on to the dictionaries.
class SQLiteDecompressionDictionary {
 private:
  SQLiteDecompressionDictionary(void) = delete;

 public:
  static constexpr size_t kNumEntityCategories = NumEnumerators(EntityCategory{});

  std::array<ZSTD_DDict *, kNumEntityCategories> dict;
  std::array<bool, kNumEntityCategories> has_dict;

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
  sqlite::Statement get_references;
  sqlite::Statement get_fragments_covered_by_tokens;

#define DECLARE_GETTERS(type_name, lower_name, ...) \
    sqlite::Statement get_ ## lower_name ## _ids ; \
    sqlite::Statement get_ ## lower_name ## _ids_by_fragment ; \
    sqlite::Statement get_ ## lower_name ## _ids_by_kind ; \
    sqlite::Statement get_ ## lower_name ## _ids_by_kind_fragment ; \
    sqlite::Statement get_ ## lower_name ## _by_id ; \

  MX_FOR_EACH_ENTITY_CATEGORY(DECLARE_GETTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
                              DECLARE_GETTERS,
                              DECLARE_GETTERS,
                              DECLARE_GETTERS)
#undef DECLARE_GETTERS

  sqlite::Statement get_ref_kind_by_id;
  sqlite::Statement get_ref_id_by_kind;
  sqlite::Statement add_reference;

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

  // Pull the dictionaries from the database.
  std::string data;
  while (dictionaries.ExecuteStep()) {
    unsigned category = 0u;
    data.clear();
    dictionaries.Row().Columns(category, data);
    if (!category || category >= kNumEntityCategories) {
      assert(false);
      continue;
    }

    if (!prev || !prev->has_dict[category]) {
      dict[category] = ZSTD_createDDict(data.data(), data.size());
      has_dict[category] = true;
    }
  }

  for (auto i = 0u; i < kNumEntityCategories; ++i) {
    if (dict[i]) {
      continue;
    }
    if (prev) {
      dict[i] = prev->dict[i];
      has_dict[i] = prev->has_dict[i];
      prev->dict[i] = nullptr;
    } else {
      dict[i] = ZSTD_createDDict("", 0);
      has_dict[i] = false;
    }
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
          "SELECT DISTINCT(rowid) "
          "FROM named_entity_index "
          "WHERE name MATCH ?1 || '*' "
          "  AND rowid > ?2 "
          "ORDER BY rowid ASC "
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))),
#else
      get_entities_by_name(db.Prepare(
          "SELECT DISTINCT(rowid) "
          "FROM named_entity "
          "WHERE name LIKE '%' || ?1 || '%' "
          "  AND entity_id > ?2 "
          "ORDER BY entity_id ASC "
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))),
#endif

      get_references(db.Prepare(
          "SELECT DISTINCT(r.from_entity_id), r.kind_id "
          "FROM reference AS r "
          "WHERE r.from_entity_id > ?1 "
          "  AND r.to_entity_id IN (SELECT l.entity_id "
          "                         FROM " + entity_id_list + " AS l "
          "                         ORDER BY l.entity_id ASC) "
          "ORDER BY r.from_entity_id ASC "
          "LIMIT " MX_TO_STR(MX_REFERENCE_PAGE_SIZE))),

      get_fragments_covered_by_tokens(db.Prepare(
          "SELECT DISTINCT(ffr.fragment_id) "
          "FROM fragment_file_range AS ffr "
          "JOIN " + entity_id_list + " AS el "
          "ON ffr.first_file_token_offset <= el.entity_id "
          "AND ffr.last_file_token_offset >= el.entity_id "
          "AND ffr.file_id = ?1")),

#define INIT_GETTERS(type_name, lower_name, enum_name, id) \
    get_ ## lower_name ## _ids(db.Prepare( \
          "SELECT " #lower_name "_id " \
          "FROM " #lower_name " " \
          "WHERE " #lower_name "_id > ?2 " \
          "ORDER BY " #lower_name "_id ASC " \
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))), \
    get_ ## lower_name ## _ids_by_fragment(db.Prepare( \
          "SELECT " #lower_name "_id " \
          "FROM " #lower_name " " \
          "WHERE entity_id_to_fragment_id(" #lower_name "_id) = ?1 " \
              "  AND " #lower_name "_id > ?2 " \
          "ORDER BY " #lower_name "_id ASC " \
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))), \
    get_ ## lower_name ## _ids_by_kind(db.Prepare( \
          "SELECT " #lower_name "_id " \
          "FROM " #lower_name " " \
          "WHERE entity_id_to_kind(" # lower_name "_id) = ?1 " \
          "  AND " #lower_name "_id > ?2 " \
          "ORDER BY " #lower_name "_id ASC " \
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))), \
    get_ ## lower_name ## _ids_by_kind_fragment(db.Prepare( \
          "SELECT " #lower_name "_id " \
          "FROM " #lower_name " " \
          "WHERE entity_id_to_kind(" # lower_name "_id) = ?1 " \
          "  AND entity_id_to_fragment_id(" #lower_name "_id) = ?2 " \
              "  AND " #lower_name "_id > ?3 " \
          "ORDER BY " #lower_name "_id ASC " \
          "LIMIT " MX_TO_STR(MX_ID_LIST_PAGE_SIZE))), \
    get_ ## lower_name ## _by_id(db.Prepare( \
          "SELECT data " \
          "FROM " #lower_name " " \
          "WHERE " #lower_name "_id = ?1")),

    MX_FOR_EACH_ENTITY_CATEGORY(INIT_GETTERS,
                                MX_IGNORE_ENTITY_CATEGORY,
                                INIT_GETTERS,
                                INIT_GETTERS,
                                INIT_GETTERS)
#undef INIT_GETTERS
      get_ref_kind_by_id(db.Prepare(
          "SELECT kind FROM reference_kind WHERE rowid = ?1")),
      get_ref_id_by_kind(db.Prepare(
          "INSERT INTO reference_kind (kind) VALUES (?1) "
          "ON CONFLICT DO UPDATE SET kind = kind "
          "RETURNING rowid")),
      add_reference(db.Prepare(
          "INSERT OR IGNORE INTO reference "
          "(from_entity_id, to_entity_id, kind_id) "
          "VALUES (?1, ?2, ?3)")),
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

ReferenceKindImplPtr SQLiteEntityProvider::ReferenceKindFor(
    const Ptr &self, RawEntityId kind_id) {
  ImplPtr context = impl.Lock();
  sqlite::Statement &add = context->get_ref_kind_by_id;
  add.BindValues(kind_id);
  if (!add.ExecuteStep()) {
    assert(false);
    add.Reset();
    return {};
  }

  std::string kind_data;
  add.Row().Columns(kind_data);
  add.Reset();
  return std::make_shared<ReferenceKindImpl>(
      self, kind_id, std::move(kind_data));
}

ReferenceKindImplPtr SQLiteEntityProvider::ReferenceKindFor(
    const Ptr &self, std::string_view kind_data) {
  RawEntityId id = kInvalidEntityId;
  do {
    ImplPtr context = impl.Lock();
    sqlite::Statement &add = context->get_ref_id_by_kind;
    add.BindValues(kind_data);
    if (!add.ExecuteStep()) {
      assert(false);
      add.Reset();
      return {};
    }

    add.Row().Columns(id);
    add.Reset();
  } while (false);

  return self->ReferenceKindFor(self, id);
}

bool SQLiteEntityProvider::AddReference(const Ptr &, RawEntityId kind_id,
                                        RawEntityId from_id,
                                        RawEntityId to_id) {
  ImplPtr context = impl.Lock();
  sqlite::Statement &add = context->add_reference;
  add.BindValues(from_id, to_id, kind_id);
  add.Execute();
  return true;
}

gap::generator<RawEntityId>
SQLiteEntityProvider::Redeclarations(const Ptr &, RawEntityId raw_id) & {
  EntityCategory category = CategoryFromEntityId(raw_id);
  if (EntityCategory::NOT_AN_ENTITY == category) {
    assert(false);
    co_return;
  }

  RawEntityIdList redecl_list;
  do {
    ImplPtr context = impl.Lock();
    auto add_entity_id = context->add_entity_id_to_list;

    sqlite::AbortingTransaction temporary_changes_only(context->db);

    // Clear our old entity id list.
    context->clear_entity_id_list.Execute();

    // Initialize the new entity ID list.
    add_entity_id.BindValues(raw_id);
    add_entity_id.Execute();

    redecl_list = ReadRedeclarations(*context, category);
  } while (false);

  for (RawEntityId redecl_id : redecl_list) {
    co_yield redecl_id;
  }
}

RawEntityIdList SQLiteEntityProvider::ReadRedeclarations(
    SQLiteEntityProviderImpl &context, EntityCategory category) {
  RawEntityIdList ret;
  ret.reserve(8u);

  context.expand_entity_id_list_with_redecls.Execute();

  sqlite::Statement &get_redecl_ids = context.get_entity_ids;
  while (get_redecl_ids.ExecuteStep()) {
    RawEntityId raw_id = kInvalidEntityId;
    get_redecl_ids.Row().Columns(raw_id);
    if (CategoryFromEntityId(raw_id) != category) {
      assert(false);
      continue;
    }

    ret.emplace_back(raw_id);
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
// to analyze when looking for references.
//
// NOTE(pag): `fragment_ids_out` will always contain the fragment associated
//            with `eid` if `eid` resides in a fragment.
gap::generator<std::pair<RawEntityId, RawEntityId>>
SQLiteEntityProvider::References(const Ptr &self, RawEntityId raw_id) & {

  ImplPtr context = impl.Lock();
  sqlite::Statement &get_references = context->get_references;
  sqlite::Statement &add_entity_id = context->add_entity_id_to_list;

  EntityId eid(raw_id);
  VariantId vid = eid.Unpack();

  // First, read the redeclarations for whatever this entity is.
  RawEntityIdList redecl_ids;
  do {
    for (RawEntityId raw_redecl_id : self->Redeclarations(self, raw_id)) {
      redecl_ids.push_back(raw_redecl_id);
    }
  } while (false);

  // Sanity check the redeclarations.
  if (std::find(redecl_ids.begin(), redecl_ids.end(), raw_id) ==
      redecl_ids.end()) {
    assert(false);
    co_return;
  }

  // NOTE(pag): SQLite doesn't understand unsigned integers. When it sees our
  //            entity IDs, if the high bit is `1`, then it treats those as
  //            negative numbers. To get pagination-like effects, we iterate
  //            from one lower bound to the next lower bound. So, we can't
  //            start with `kInvalidEntityId` (zero) as our initial lower bound,
  //            which would be natural given the unsigned representation of
  //            raw entity IDs, so instead we use the minimum signed 64-bit
  //            integer.
  auto lower_bound = std::numeric_limits<int64_t>::min();

  std::array<std::pair<RawEntityId, RawEntityId>, MX_REFERENCE_PAGE_SIZE>
      paged_results;

  auto version = self->VersionNumber();
  for (auto found = true; found; ) {
    found = false;
    auto num_paged_results = 0u;

    // Go collect a "page" of reference entries. We go one page at a time so
    // that we can avoid having do to any kind of clever query caching to make
    // generators / coroutines work.
    do {
      sqlite::AbortingTransaction temporary_changes_only(context->db);

      // Clear our old entity id list.
      context->clear_entity_id_list.Execute();

      // Fill the entity id list with the redeclarations.
      for (RawEntityId raw_redecl_id : redecl_ids) {
        add_entity_id.BindValues(raw_redecl_id);
        add_entity_id.Execute();
      }

      // (Re)do the join to get the next page of entity references.
      get_references.BindValues(lower_bound);
      while (get_references.ExecuteStep()) {
        found = true;
        RawEntityId from_id = kInvalidEntityId;
        RawEntityId kind_id = kInvalidEntityId;

        get_references.Row().Columns(from_id, kind_id);

        // For next page.
        lower_bound = std::max(lower_bound, static_cast<int64_t>(from_id));

        vid = EntityId(from_id).Unpack();
        if (std::holds_alternative<InvalidId>(vid)) {
          assert(from_id == kInvalidEntityId);
          continue;
        }

        paged_results[num_paged_results].first = from_id;
        paged_results[num_paged_results].second = kind_id;
        ++num_paged_results;
      }

      get_references.Reset();
    } while (false);

    for (auto i = 0u; i < num_paged_results; ++i) {
      co_yield paged_results[i];
    }

    // Index changed on us; exit early.
    if (found && version != self->VersionNumber()) {
      co_return;
    }
  }
}

gap::generator<RawEntityId> SQLiteEntityProvider::FindSymbol(
    const Ptr &self, std::string symbol) & {

  ImplPtr context = impl.Lock();
  sqlite::Statement &list_ids = context->get_entities_by_name;

  // NOTE(pag): SQLite doesn't understand unsigned integers. When it sees our
  //            entity IDs, if the high bit is `1`, then it treats those as
  //            negative numbers. To get pagination-like effects, we iterate
  //            from one lower bound to the next lower bound. So, we can't
  //            start with `kInvalidEntityId` (zero) as our initial lower bound,
  //            which would be natural given the unsigned representation of
  //            raw entity IDs, so instead we use the minimum signed 64-bit
  //            integer.
  auto lower_bound = std::numeric_limits<int64_t>::min();

  std::array<RawEntityId, MX_ID_LIST_PAGE_SIZE> paged_results;

  auto version = self->VersionNumber();
  for (auto found = true; found; ) {
    found = false;
    auto num_paged_results = 0u;

    // Go collect a "page" of matched name entries. We go one page at a time so
    // that we can avoid having do to any kind of clever query caching to make
    // generators / coroutines work.
    do {

      // (Re)do the join to get the next page of entity references.
      list_ids.BindValuesWithoutCopying(symbol, lower_bound);
      while (list_ids.ExecuteStep()) {
        found = true;
        RawEntityId found_id = kInvalidEntityId;
        list_ids.Row().Columns(found_id);

        // For next page.
        lower_bound = std::max(lower_bound, static_cast<int64_t>(found_id));

        VariantId vid = EntityId(found_id).Unpack();
        if (std::holds_alternative<InvalidId>(vid)) {
          assert(found_id == kInvalidEntityId);
          continue;
        } else if (std::holds_alternative<MacroId>(vid) ||
                   std::holds_alternative<DeclId>(vid) ||
                   std::holds_alternative<FileId>(vid)) {
          paged_results[num_paged_results] = found_id;
          ++num_paged_results;
        } else {
          assert(false);
          continue;
        }
      }

      list_ids.Reset();
    } while (false);

    for (auto i = 0u; i < num_paged_results; ++i) {
      co_yield paged_results[i];
    }

    // Index changed on us; exit early.
    if (found && version != self->VersionNumber()) {
      co_return;
    }
  }
}

#define MX_DECLARE_ENTITY_GETTER(type_name, lower_name, enum_name, category) \
    type_name ## ImplPtr SQLiteEntityProvider:: type_name ## For( \
        const Ptr &self, RawEntityId raw_id) { \
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
      try { \
        return std::make_shared<type_name ## Impl>( \
            self, \
            Decompress(context->decompression_context, dict->dict[cat_index], \
                       std::move(data)), \
            raw_id); \
      } catch (...) { \
        assert(false); \
        return {}; \
      } \
    } \
    \
    gap::generator<type_name ## ImplPtr> SQLiteEntityProvider::type_name ## sFor( \
        const Ptr &self) & { \
      ImplPtr context = impl.Lock(); \
      sqlite::Statement &list_ids = context->get_ ## lower_name ## _ids; \
      \
      auto lower_bound = std::numeric_limits<int64_t>::min(); \
      std::array<RawEntityId, MX_ID_LIST_PAGE_SIZE> paged_results; \
      auto version = self->VersionNumber(); \
      for (auto found = true; found; ) { \
        found = false; \
        auto num_paged_results = 0u; \
        do { \
          list_ids.BindValues(lower_bound); \
          while (list_ids.ExecuteStep()) { \
            found = true; \
            RawEntityId listed_id = kInvalidEntityId; \
            list_ids.Row().Columns(listed_id); \
            lower_bound = std::max(lower_bound, static_cast<int64_t>(listed_id)); \
            \
            VariantId vid = EntityId(listed_id).Unpack(); \
            if (std::holds_alternative<InvalidId>(vid)) { \
              assert(false); \
              continue; \
            } \
            \
            paged_results[num_paged_results] = listed_id; \
            ++num_paged_results; \
          } \
          \
          list_ids.Reset(); \
        } while (false); \
        \
        for (auto i = 0u; i < num_paged_results; ++i) { \
          if (type_name ## ImplPtr eptr = self->type_name ## For( \
                  self, paged_results[i])) { \
            co_yield eptr; \
          } \
        } \
        \
        if (found && version != self->VersionNumber()) { \
          co_return; \
        } \
      } \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_ENTITY_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER,
                            MX_DECLARE_ENTITY_GETTER)
#undef MX_DECLARE_ENTITY_GETTER

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
  gap::generator<type_name ## ImplPtr> SQLiteEntityProvider::type_name ## sFor( \
      const Ptr &self, type_name ## Kind kind) & { \
    ImplPtr context = impl.Lock(); \
    sqlite::Statement &list_ids = context->get_ ## lower_name ## _ids_by_kind; \
    \
    auto lower_bound = std::numeric_limits<int64_t>::min(); \
    std::array<RawEntityId, MX_ID_LIST_PAGE_SIZE> paged_results; \
    auto version = self->VersionNumber(); \
    for (auto found = true; found; ) { \
      found = false; \
      auto num_paged_results = 0u; \
      do { \
        list_ids.BindValues(static_cast<unsigned>(kind), lower_bound); \
        while (list_ids.ExecuteStep()) { \
          found = true; \
          RawEntityId listed_id = kInvalidEntityId; \
          list_ids.Row().Columns(listed_id); \
          lower_bound = std::max(lower_bound, static_cast<int64_t>(listed_id)); \
          \
          VariantId vid = EntityId(listed_id).Unpack(); \
          if (std::holds_alternative<InvalidId>(vid)) { \
            assert(false); \
            continue; \
          } \
          \
          paged_results[num_paged_results] = listed_id; \
          ++num_paged_results; \
        } \
        \
        list_ids.Reset(); \
      } while (false); \
      \
      for (auto i = 0u; i < num_paged_results; ++i) { \
        if (type_name ## ImplPtr eptr = self->type_name ## For( \
                self, paged_results[i])) { \
          co_yield eptr; \
        } \
      } \
      \
      if (found && version != self->VersionNumber()) { \
        co_return; \
      } \
    } \
  } \
  \
  gap::generator<type_name ## ImplPtr> SQLiteEntityProvider::type_name ## sFor( \
      const Ptr &self, type_name ## Kind kind, PackedFragmentId frag_id) & { \
    ImplPtr context = impl.Lock(); \
    sqlite::Statement &list_ids = context->get_ ## lower_name ## _ids_by_kind_fragment; \
    \
    auto lower_bound = std::numeric_limits<int64_t>::min(); \
    std::array<RawEntityId, MX_ID_LIST_PAGE_SIZE> paged_results; \
    auto version = self->VersionNumber(); \
    for (auto found = true; found; ) { \
      found = false; \
      auto num_paged_results = 0u; \
      do { \
        list_ids.BindValues(static_cast<unsigned>(kind), frag_id.Pack(), lower_bound); \
        while (list_ids.ExecuteStep()) { \
          found = true; \
          RawEntityId listed_id = kInvalidEntityId; \
          list_ids.Row().Columns(listed_id); \
          lower_bound = std::max(lower_bound, static_cast<int64_t>(listed_id)); \
          \
          VariantId vid = EntityId(listed_id).Unpack(); \
          if (std::holds_alternative<InvalidId>(vid)) { \
            assert(false); \
            continue; \
          } \
          \
          paged_results[num_paged_results] = listed_id; \
          ++num_paged_results; \
        } \
        \
        list_ids.Reset(); \
      } while (false); \
      \
      for (auto i = 0u; i < num_paged_results; ++i) { \
        if (type_name ## ImplPtr eptr = self->type_name ## For( \
                self, paged_results[i])) { \
          co_yield eptr; \
        } \
      } \
      \
      if (found && version != self->VersionNumber()) { \
        co_return; \
      } \
    } \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_DECLARE_ENTITY_LISTERS

#define MX_DECLARE_ENTITY_LISTERS(type_name, lower_name, enum_name, category) \
  gap::generator<type_name ## ImplPtr> SQLiteEntityProvider::type_name ## sFor( \
      const Ptr &self, PackedFragmentId frag_id) & { \
    ImplPtr context = impl.Lock(); \
    sqlite::Statement &list_ids = context->get_ ## lower_name ## _ids_by_fragment; \
    \
    auto lower_bound = std::numeric_limits<int64_t>::min(); \
    std::array<RawEntityId, MX_ID_LIST_PAGE_SIZE> paged_results; \
    auto version = self->VersionNumber(); \
    for (auto found = true; found; ) { \
      found = false; \
      auto num_paged_results = 0u; \
      do { \
        list_ids.BindValues(frag_id.Pack(), lower_bound); \
        while (list_ids.ExecuteStep()) { \
          found = true; \
          RawEntityId listed_id = kInvalidEntityId; \
          list_ids.Row().Columns(listed_id); \
          lower_bound = std::max(lower_bound, static_cast<int64_t>(listed_id)); \
          \
          VariantId vid = EntityId(listed_id).Unpack(); \
          if (std::holds_alternative<InvalidId>(vid)) { \
            assert(false); \
            continue; \
          } \
          \
          paged_results[num_paged_results] = listed_id; \
          ++num_paged_results; \
        } \
        \
        list_ids.Reset(); \
      } while (false); \
      \
      for (auto i = 0u; i < num_paged_results; ++i) { \
        if (type_name ## ImplPtr eptr = self->type_name ## For( \
                self, paged_results[i])) { \
          co_yield eptr; \
        } \
      } \
      \
      if (found && version != self->VersionNumber()) { \
        co_return; \
      } \
    } \
  }

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_DECLARE_ENTITY_LISTERS,
                            MX_DECLARE_ENTITY_LISTERS)
#undef MX_DECLARE_ENTITY_LISTERS

EntityProvider::Ptr EntityProvider::from_database(std::filesystem::path path) {
  return std::make_shared<SQLiteEntityProvider>(path);
}

}  // namespace mx
