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
    sqlite::Statement get_ ## lower_name ## _ids_by_fragment ; \
    sqlite::Statement get_ ## lower_name ## _by_id ; \

  MX_FOR_EACH_ENTITY_CATEGORY(DECLARE_GETTERS,
                              MX_IGNORE_ENTITY_CATEGORY,
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
          "SELECT DISTINCT(rowid) FROM symbol WHERE name MATCH ?1 || '*' "
          "ORDER BY rowid ASC")),
#else
      get_entities_by_name(db.Prepare(
          "SELECT DISTINCT(rowid) FROM symbol WHERE name LIKE '%' || ?1 || '%' "
          "ORDER BY rowid ASC")),
#endif

      get_references(db.Prepare(
          "SELECT DISTINCT(r.from_entity_id), r.kind_id "
          "FROM reference AS r "
          "JOIN " + entity_id_list + " AS l "
          "ON r.to_entity_id = l.entity_id "
          "WHERE r.from_entity_id > ?1 "
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
SQLiteEntityProvider::Redeclarations(const Ptr &, RawEntityId raw_id) {
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
SQLiteEntityProvider::References(const Ptr &self, RawEntityId raw_id) {

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
    // that we can avoid the
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
        lower_bound = static_cast<int64_t>(from_id);  // For next page.

        vid = EntityId(from_id).Unpack();
        if (std::holds_alternative<InvalidId>(vid)) {
          assert(false);
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
