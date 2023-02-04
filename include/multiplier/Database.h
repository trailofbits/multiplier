// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <string>

#include "Types.h"

#define MX_DATABASE_HAS_FTS5 1
#define MX_DATABASE_PRAGMA_SYNCHRONOUS "NORMAL"
#define MX_DATABASE_TEMP_STORE "MEMORY"
#define MX_DATABASE_JOURNAL_MODE "WAL"

namespace mx {
class DatabaseWriterImpl;

#define MX_FOR_EACH_ASYNC_RECORD_TYPE(m) \
    m(FilePathRecord) \
    m(FragmentFileRecord) \
    m(FragmentFileRangeRecord) \
    m(RedeclarationRecord) \
    m(MangledNameRecord) \
    m(UseRecord) \
    m(ReferenceRecord) \
    m(SymbolNameRecord) \
    m(DictionaryRecord)


// Tells us one of the valid file paths associated with a file id.
struct FilePathRecord {
  static constexpr const char *kTableName = "file_path";

  static constexpr const char *kInitStatements[] = {
      R"(CREATE TABLE IF NOT EXISTS file_path (
           file_id INTEGER NOT NULL,
           path TEXT NOT NULL,
           PRIMARY KEY(path)
         ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      "INSERT OR IGNORE INTO file_path (file_id, path) VALUES (?1, ?2)";

  PackedFileId file_id;
  std::filesystem::path path;
};

// Maps a file id to the file's serialized data.
struct FileRecord {
  static constexpr const char *kTableName = "file";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS file (
            file_id INTEGER NOT NULL,
            data BLOB NOT NULL,
            PRIMARY KEY(file_id)
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      "INSERT OR IGNORE INTO file (file_id, data) VALUES (?1, zstd_compress(?2))";

  PackedFileId file_id;
  std::string data;
};

// Tells us which file the "root" of a fragment belongs to. Note that a fragment
// can span/include other files internally.
struct FragmentFileRecord {
  static constexpr const char *kTableName = "fragment_file";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS fragment_file (
            fragment_id INTEGER NOT NULL PRIMARY KEY,
            file_id INTEGER NOT NULL
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS fragments_in_file
         ON fragment_file(file_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment_file (fragment_id, file_id)
         VALUES (?1, ?2))";

  PackedFragmentId fragment_id;
  PackedFileId file_id;
};

// Tells us a the inclusive range of file tokens of a file covered by a
// fragment.
struct FragmentFileRangeRecord {
  static constexpr const char *kTableName = "fragment_file_range";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE VIRTUAL TABLE IF NOT EXISTS fragment_file_range USING rtree_i32(
            fragment_id INTEGER PRIMARY KEY NOT NULL,
            first_file_token_offset INTEGER NOT NULL,
            last_file_token_offset INTEGER NOT NULL,
            +file_id INTEGER NOT NULL
          ))"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment_file_range
         (fragment_id, first_file_token_offset, last_file_token_offset, file_id)
         VALUES (?1, ?2, ?3, ?4))";

  PackedFragmentId fragment_id;
  PackedFileTokenId first_file_token;
  PackedFileTokenId last_file_token;
};

// Maps a fragment id to the fragment's serialized data.
struct FragmentRecord {
  static constexpr const char *kTableName = "fragment";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS fragment (
            fragment_id INTEGER NOT NULL,
            data BLOB NOT NULL,
            PRIMARY KEY(fragment_id)
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment (fragment_id, data)
         VALUES (?1, zstd_compress(?2)))";

  PackedFragmentId fragment_id;
  std::string data;
};

// Tells us that `redecl_id` is a redeclaration of `decl_id`.
struct RedeclarationRecord {
  static constexpr const char *kTableName = "redeclaration";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS redeclaration (
            decl_id INTEGER NOT NULL,
            redecl_id INTEGER NOT NULL,
            PRIMARY KEY(decl_id, redecl_id)
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS redecl_id_from_decl_id
         ON redeclaration(decl_id))",
      R"(CREATE INDEX IF NOT EXISTS decl_id_from_redecl_id
         ON redeclaration(redecl_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO redeclaration (decl_id, redecl_id)
         VALUES (?1, ?2))";

  PackedDeclId decl_id;
  PackedDeclId redecl_id;
};

// Maps a declaration ID to a mangled name. We use mangled names to help us
// improve redeclaration discovery when there is a logical connection between
// two independent declarations, but there is no "path" connecting them via
// a sequence of two or more declarations that are both resident in a
// translation unit.
struct MangledNameRecord {
  static constexpr const char *kTableName = "mangled_name";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS mangled_name (
            entity_id INTEGER NOT NULL,
            data TEXT NOT NULL,
            PRIMARY KEY(entity_id)
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS mangled_name_from_entity_id
         ON mangled_name(data))",

      // Mangle name data columns use space-delimited data. Having a view that
      // can give us access to just the normal names is nifty when we're trying
      // to diagnose issues where we have logically the same entity mangled to
      // two different names, e.g. `static inline` functions in headers.
      R"(CREATE VIEW IF NOT EXISTS base_mangled_name AS
         SELECT m.entity_id AS entity_id,
                substr(m.data||' ', 0, instr(m.data||' ',' ')) AS data
         FROM mangled_name AS m)"};

  static constexpr const char *kInsertStatement =
      R"(INSERT INTO mangled_name (entity_id, data)
         VALUES (?1, ?2))";

  // A `DeclId` or a `MacroId`.
  RawEntityId entity_id;

  std::string mangled_name;
};

// Represents the name of some symbol.
struct SymbolNameRecord {
  static constexpr const char *kTableName = "symbol";

#if MX_DATABASE_HAS_FTS5
  static constexpr const char *kInitStatements[] = {
      R"(CREATE VIRTUAL TABLE IF NOT EXISTS symbol
         USING fts5(name, content=''))"};

  static constexpr const char *kExitStatements[] = {
      R"(INSERT INTO symbol(symbol) VALUES('optimize'))"};

#else
  static constexpr const char *kInitStatements[] = {
      R"(CREATE TABLE IF NOT EXISTS symbol (
           name TEXT NOT NULL
         ))"};

  static constexpr const char *kExitStatements[] = {nullptr};
#endif

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO symbol (rowid, name)
         VALUES (?1, ?2))";

  // A `DeclId` or a `MacroId`.
  RawEntityId entity_id;

  // A name, e.g. `std::abs`.
  std::string name;
};

// Records an entry telling us that something in a particular fragment uses
// `entity_id`. An entity use is an API method that returns an entity, or an
// optional entity. The type of use (the edge label) is not recorded; instead
// we determine those at runtime by visiting all entities serialized in the
// fragment and looking for the uses.
//
// NOTE(pag): We opportunistically assume all entities are used by their own
//            fragments, so we don't record edges between a fragment and its
//            own entities.
struct UseRecord {
  static constexpr const char *kTableName = "use";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS use (
            fragment_id INTEGER NOT NULL,
            entity_id INTEGER NOT NULL,
            PRIMARY KEY(fragment_id, entity_id)
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS fragments_using_entities
         ON use(entity_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO use (fragment_id, entity_id)
         VALUES (?1, ?2))";

  PackedFragmentId fragment_id;
  RawEntityId entity_id;
};

// Records an entry telling us that one entity references another entity.
// A reference has a to-entity-specific meaning, and so we don't need an
// edge label.
struct ReferenceRecord {
  static constexpr const char *kTableName = "reference";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS reference (
            from_entity_id INTEGER NOT NULL,
            to_entity_id INTEGER NOT NULL,
            kind_id INTEGER NOT NULL,
            PRIMARY KEY(from_entity_id, to_entity_id, kind_id)
          ) WITHOUT ROWID)",

       R"(CREATE TABLE IF NOT EXISTS reference_kind (
            kind_id INTEGER PRIMARY KEY,
            description TEXT NOT NULL
          ) WITHOUT ROWID)",

       R"(INSERT OR IGNORE INTO reference_kind (kind_id, description)
          VALUES (1, "Explicit code reference"))"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS references_by_target
         ON reference(to_entity_id))"};

  // NOTE(pag): Reference id `1` is `ReferenceKind::EXPLICIT_CODE_REFERENCE`.
  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO reference (from_entity_id, to_entity_id, kind_id)
         VALUES (?1, ?2, 1))";

  RawEntityId from_entity_id;
  RawEntityId to_entity_id;
};

// Records a ZSTD dictionary for a category of entities into the database.
struct DictionaryRecord {
  static constexpr const char *kTableName = "entity_dictionary";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS entity_dictionary (
            entity_category INT PRIMARY KEY,
            data BLOB NOT NULL
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      "INSERT INTO entity_dictionary (entity_category, data) VALUES (?1, ?2)";

  EntityCategory category;
  std::string data;
};

// Records an entity into the database
struct EntityRecord {
  static constexpr const char *kTableName = "entity";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS entity (
            entity_id INTEGER PRIMARY KEY,
            data BLOB NOT NULL
          ) WITHOUT ROWID)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS entities_by_category
         ON entity(entity_id_to_category(entity_id) ASC))",

      R"(CREATE INDEX IF NOT EXISTS entities_by_fragment
         ON entity(entity_id_to_category(entity_id) ASC,
                   entity_id_to_fragment_id(entity_id) ASC))",

      R"(CREATE INDEX IF NOT EXISTS entities_by_kind
         ON entity(entity_id_to_category(entity_id) ASC,
                   entity_id_to_kind(entity_id) ASC,
                   entity_id_to_fragment_id(entity_id) ASC))",

#define MX_CREATE_ENTITY_VIEW(type, name, enum_, id) \
     "CREATE VIEW IF NOT EXISTS " #name " AS " \
     "SELECT entity_id AS " #name "_id, data " \
     "FROM entity " \
     "WHERE entity_id_to_category(entity_id) = " #id,

MX_FOR_EACH_ENTITY_CATEGORY(MX_CREATE_ENTITY_VIEW,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_CREATE_ENTITY_VIEW,
                            MX_CREATE_ENTITY_VIEW)
#undef MX_CREATE_ENTITY_VIEW
      };

  static constexpr const char *kInsertStatement =
      "INSERT OR IGNORE INTO entity (entity_id, data) VALUES (?1, ?2)";

  RawEntityId id;
  std::string data;
};

// API for write access to the Multiplier database.
class DatabaseWriter final {
 private:
  std::shared_ptr<DatabaseWriterImpl> impl;

  DatabaseWriter(void) = delete;

 public:
  static constexpr const char *kInitStatements[] = {
      "PRAGMA application_id = 0xce9ccea7",
      "PRAGMA cache_size = -262144",  // 256 MiB / 1 KiB
      "PRAGMA page_size = 16384",  // 16 KiB.
      "PRAGMA synchronous = " MX_DATABASE_PRAGMA_SYNCHRONOUS,
      "PRAGMA temp_store = " MX_DATABASE_TEMP_STORE,
      "PRAGMA journal_mode = DELETE",
      "PRAGMA journal_mode = " MX_DATABASE_JOURNAL_MODE,

      R"(CREATE TABLE IF NOT EXISTS metadata (
           next_file_index INTEGER NOT NULL,
           next_small_fragment_index INTEGER NOT NULL,
           next_big_fragment_index INTEGER NOT NULL
         ))",

      R"(CREATE TABLE IF NOT EXISTS version (
           action INTEGER NOT NULL
         ))",

      R"(CREATE INDEX IF NOT EXISTS version_action ON version(action))"};

//  static constexpr const char *kExitStatments[] = {
//      };

  ~DatabaseWriter(void);

  explicit DatabaseWriter(std::filesystem::path db_path);

  // Schedule all outstanding asynchronous writes to be flushed. This operation
  // is itself asynchronous, and when it returns, there are no guarantees that
  // the database writes have actually happened.
  void AsyncFlush(void);

  // Get, or create and return, a file ID for the specific file contents hash.
  PackedFileId GetOrCreateFileIdForHash(
      std::string hash, bool &is_new);

  // Get, or create and return, a fragment ID for the specific fragment hash.
  PackedFragmentId GetOrCreateSmallFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  // Get, or create and return, a fragment ID for the specific fragment hash.
  PackedFragmentId GetOrCreateLargeFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  PackedFragmentId GetOrCreateFragmentIdForHash(
      RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new) {

    // "Big codes" have IDs in the range [1, mx::kMaxNumBigPendingFragments)`.
    //
    // NOTE(pag): We have a fudge factor here of `3x` to account for macro
    //            expansions.
    if ((num_tokens * 3u) >= mx::kNumTokensInBigFragment) {
      return GetOrCreateLargeFragmentIdForHash(
          tok_id, std::move(hash), is_new);
    } else {
      return GetOrCreateSmallFragmentIdForHash(
          tok_id, std::move(hash), is_new);
    }
  }

//  // Flush all outstanding writes to the database.
//  void Flush(void);

#define MX_DECLARE_ADD_RECORD(name) \
    void AddAsync(name);

  MX_FOR_EACH_ASYNC_RECORD_TYPE(MX_DECLARE_ADD_RECORD)
  MX_DECLARE_ADD_RECORD(EntityRecord)
#undef MX_DECLARE_ADD_RECORD

  template <typename T1, typename T2, typename... Ts>
  inline void AddAsync(T1 r1, T2 r2, Ts... rs) {
    AddAsync(std::move(r1));
    AddAsync(std::move(r2), std::move(rs)...);
  }
};

} // namespace mx
