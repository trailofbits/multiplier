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

#define MX_FOR_EACH_ENTITY_RECORD(m, ...) \
    m(Decl, decl __VA_OPT__(,) __VA_ARGS__) \
    m(Type, type __VA_OPT__(,) __VA_ARGS__) \
    m(Stmt, stmt __VA_OPT__(,) __VA_ARGS__) \
    m(Attr, attr __VA_OPT__(,) __VA_ARGS__) \
    m(Macro, macro __VA_OPT__(,) __VA_ARGS__) \
    m(Pseudo, pseudo __VA_OPT__(,) __VA_ARGS__)

#define MX_ASYNC_REORD_TYPE(name, lower_name, m) m(name ## EntityRecord)

#define MX_FOR_EACH_ASYNC_RECORD_TYPE(m) \
    m(FilePathRecord) \
    m(FileRecord) \
    m(FragmentFileRecord) \
    m(FragmentFileRangeRecord) \
    m(FragmentRecord) \
    m(RedeclarationRecord) \
    m(MangledNameRecord) \
    m(UseRecord) \
    m(ReferenceRecord) \
    m(SymbolNameRecord) \
    MX_FOR_EACH_ENTITY_RECORD(MX_ASYNC_REORD_TYPE, m)


// Tells us one of the valid file paths associated with a file id.
struct FilePathRecord {
  static constexpr const char *kTableName = "file_path";

  static constexpr const char *kInitStatements[] = {
      R"(CREATE TABLE IF NOT EXISTS file_path (
           file_id INT NOT NULL,
           path TEXT NOT NULL,
           PRIMARY KEY(path)
         ) WITHOUT rowid)"};

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
            file_id INT NOT NULL,
            data BLOB NOT NULL,
            PRIMARY KEY(file_id)
          ) WITHOUT rowid)"};

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
            fragment_id INT NOT NULL PRIMARY KEY,
            file_id INT NOT NULL
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS fragments_in_file
         ON fragment_file(file_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment_file
         (fragment_id, file_id)
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
            fragment_id INT PRIMARY KEY NOT NULL,
            first_file_token_offset INT NOT NULL,
            last_file_token_offset INT NOT NULL,
            +file_id INT NOT NULL
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
            fragment_id INT NOT NULL,
            data BLOB NOT NULL,
            PRIMARY KEY(fragment_id)
          ) WITHOUT rowid)"};

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
            decl_id INT NOT NULL,
            redecl_id INT NOT NULL,
            PRIMARY KEY(decl_id, redecl_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS redecl_id_from_decl_id
         ON redeclaration(decl_id))",
      R"(CREATE INDEX IF NOT EXISTS decl_id_from_redecl_id
         ON redeclaration(redecl_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO redeclaration (decl_id, redecl_id)
         VALUES (?1, ?2))";

  PackedDeclarationId decl_id;
  PackedDeclarationId redecl_id;
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
            entity_id INT NOT NULL,
            data TEXT NOT NULL,
            PRIMARY KEY(entity_id)
          ) WITHOUT rowid)"};

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

  // A `DeclarationId` or a `MacroId`.
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

  // A `DeclarationId` or a `MacroId`.
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
            fragment_id INT NOT NULL,
            entity_id INT NOT NULL,
            PRIMARY KEY(fragment_id, entity_id)
          ) WITHOUT rowid)"};

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
            from_entity_id INT NOT NULL,
            to_entity_id INT NOT NULL,
            PRIMARY KEY(from_entity_id, to_entity_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS references_by_target
         ON reference(to_entity_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO reference (from_entity_id, to_entity_id)
         VALUES (?1, ?2))";

  RawEntityId from_entity_id;
  RawEntityId to_entity_id;
};

#define DEFINE_ENTITY_TABLE(name, lower_name) \
  struct name ## EntityRecord { \
    static constexpr const char *kTableName = #lower_name; \
    \
    static constexpr const char *kInitStatements[] = { \
        "CREATE TABLE IF NOT EXISTS " #lower_name "(" \
        "  " #lower_name "_id INT PRIMARY KEY, " \
        "  fragment_id INT NOT NULL, " \
        "  fragment_offset INT NOT NULL, " \
        "  data BLOB NOT NULL " \
        ") WITHOUT rowid"}; \
    \
    static constexpr const char *kExitStatements[] = { \
        "CREATE INDEX IF NOT EXISTS " #lower_name "_fragment_index " \
        "ON " #lower_name "(fragment_id)", \
        \
        "CREATE INDEX IF NOT EXISTS " #lower_name "_offset_index " \
        "ON " #lower_name "(fragment_id, fragment_offset)"}; \
    \
    static constexpr const char *kInsertStatement = \
        "INSERT INTO " #lower_name " (" #lower_name "_id, fragment_id, " \
        "                             fragment_offset, data) "\
        "VALUES (?1, ?2, ?3, zstd_compress(?4))"; \
    \
    mx::RawEntityId id; \
    std::string data; \
  };

MX_FOR_EACH_ENTITY_RECORD(DEFINE_ENTITY_TABLE)
#undef DEFINE_ENTITY_TABLE

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
           next_file_index INT NOT NULL,
           next_small_fragment_index INT NOT NULL,
           next_big_fragment_index INT NOT NULL
         ))",

      R"(CREATE TABLE IF NOT EXISTS version (
           action INT NOT NULL
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

#undef MX_DECLARE_ADD_RECORD

  template <typename T1, typename T2, typename... Ts>
  inline void AddAsync(T1 r1, T2 r2, Ts... rs) {
    AddAsync(std::move(r1));
    AddAsync(std::move(r2), std::move(rs)...);
  }
};

} // namespace mx
