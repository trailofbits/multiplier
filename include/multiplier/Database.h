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

#define MX_SQLITE_HAS_FTS5 0

namespace mx {
class DatabaseWriterImpl;

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

  SpecificEntityId<FileId> file_id;
  std::filesystem::path path;
};

// Maps a file id to the file's serialized data.
struct SerializedFileRecord {
  static constexpr const char *kTableName = "file";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS file (
            file_id INT NOT NULL,
            data TEXT NOT NULL,
            PRIMARY KEY(file_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      "INSERT OR IGNORE INTO file (file_id, data) VALUES (?1, ?2)";

  SpecificEntityId<FileId> file_id;
  std::string data;
};

// Tells us a the inclusive range of lines of a file covered by a fragment.
struct FragmentLineCoverageRecord {
  static constexpr const char *kTableName = "fragment_line";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS fragment_line (
            fragment_id INT NOT NULL,
            file_id INT NOT NULL,
            first_line_number INT NOT NULL,
            last_line_number INT NOT NULL
          ))"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS file_fragments 
         ON fragment_line(file_id))",
      R"(CREATE INDEX IF NOT EXISTS fragment_by_first_line
         ON fragment_line(file_id, first_line_number))",
      R"(CREATE INDEX IF NOT EXISTS fragment_by_last_line
         ON fragment_line(file_id, last_line_number))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment_line
         (fragment_id, file_id, first_line_number, last_line_number)
         VALUES (?1, ?2, ?3, ?4))";

  SpecificEntityId<FragmentId> fragment_id;
  SpecificEntityId<FileId> file_id;
  unsigned first_line_number;
  unsigned last_line_number;
};

// Maps a fragment id to the fragment's serialized data.
struct SerializedFragmentRecord {
  static constexpr const char *kTableName = "fragment";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS fragment (
            fragment_id INT NOT NULL,
            data TEXT NOT NULL,
            PRIMARY KEY(fragment_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment (fragment_id, data)
         VALUES (?1, ?2))";

  SpecificEntityId<FragmentId> fragment_id;
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
         ON redeclaration(decl_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO redeclaration (decl_id, redecl_id)
         VALUES (?1, ?2))";

  SpecificEntityId<DeclarationId> decl_id;
  SpecificEntityId<DeclarationId> redecl_id;
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
         ON mangled_name(data))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO mangled_name (entity_id, data)
         VALUES (?1, ?2))";

  // A `DeclarationId` or a `MacroId`.
  RawEntityId entity_id;

  std::string mangled_name;
};

// Represents the name of some symbol.
struct SymbolNameRecord {
  static constexpr const char *kTableName = "symbol";

#if MX_SQLITE_HAS_FTS5
  static constexpr const char *kInitStatements[] = {
      R"(CREATE VIRTUAL TABLE IF NOT EXISTS symbol
         USING fts5(name, content=''))"};

  static constexpr const char *kExitStatements[] = {
      R"(INSERT INTO name(name) VALUES('optimize'))"};

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
struct FragmentUsingEntityRecord {
  static constexpr const char *kTableName = "entity_use";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS entity_use (
            fragment_id INT NOT NULL,
            entity_id INT NOT NULL,

            PRIMARY KEY(fragment_id, entity_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS fragments_using_entities
         ON entity_use(entity_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO entity_use (fragment_id, entity_id)
         VALUES (?1, ?2))";

  SpecificEntityId<FragmentId> fragment_id;
  RawEntityId entity_id;
};

// Records an entry telling us that one entity references another entity.
// a reference has a from-entity-specific meaning, and so we don't need an
// edge label.
struct EntityReferenceRecord {
  static constexpr const char *kTableName = "entity_reference";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS entity_reference (
            fragment_id INT NOT NULL,
            entity_id INT NOT NULL,

            PRIMARY KEY(fragment_id, entity_id)
          ) WITHOUT rowid)"};

  static constexpr const char *kExitStatements[] = {
      R"(CREATE INDEX IF NOT EXISTS fragments_referencing_entities
         ON entity_reference(entity_id))"};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO entity_reference (fragment_id, entity_id)
         VALUES (?1, ?2))";

  SpecificEntityId<FragmentId> fragment_id;
  RawEntityId entity_id;
};

#define MX_FOR_EACH_ASYNC_RECORD_TYPE(m) \
    m(FilePathRecord) \
    m(SerializedFileRecord) \
    m(FragmentLineCoverageRecord) \
    m(SerializedFragmentRecord) \
    m(RedeclarationRecord) \
    m(MangledNameRecord) \
    m(FragmentUsingEntityRecord) \
    m(EntityReferenceRecord) \
    m(SymbolNameRecord)

// API for write access to the Multiplier database.
class DatabaseWriter final {
 private:
  std::shared_ptr<DatabaseWriterImpl> impl;

  DatabaseWriter(void) = delete;

 public:

  static constexpr const char *kInitStatements[] = {

      // Generated by rolling a 4,294,967,296-sided die.
      // Guaranteed to be random.
      "PRAGMA application_id = 0xce9ccea7",

      R"(CREATE TABLE IF NOT EXISTS metadata (
           next_file_id INT NOT NULL,
           next_small_fragment_id INT NOT NULL,
           next_big_fragment_id INT NOT NULL
         ))",

      R"(CREATE TABLE IF NOT EXISTS version (
           action INT NOT NULL
         ))",

      R"(CREATE INDEX IF NOT EXISTS version_action ON version(action))",

      R"(CREATE TABLE IF NOT EXISTS file_hash (
           file_id INT NOT NULL,
           hash TEXT NOT NULL,
           PRIMARY KEY(hash),
           UNIQUE(file_id)
         ) WITHOUT rowid)",

      R"(CREATE TABLE IF NOT EXISTS fragment_hash (
           fragment_id INT NOT NULL,
           file_token_id INT NOT NULL,
           hash TEXT NOT NULL,
           PRIMARY KEY(hash, file_token_id),
           UNIQUE(fragment_id)
         ) WITHOUT rowid)"};

//  static constexpr const char *kExitStatments[] = {
//      };

  ~DatabaseWriter(void);

  explicit DatabaseWriter(std::filesystem::path db_path);

  // Schedule all outstanding asynchronous writes to be flushed. This operation
  // is itself asynchronous, and when it returns, there are no guarantees that
  // the database writes have actually happened.
  void AsyncFlush(void);

  // Get, or create and return, a file ID for the specific file contents hash.
  SpecificEntityId<FileId> GetOrCreateFileIdForHash(
      std::string hash, bool &is_new);

  // Get, or create and return, a fragment ID for the specific fragment hash.
  SpecificEntityId<FragmentId> GetOrCreateSmallFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  // Get, or create and return, a fragment ID for the specific fragment hash.
  SpecificEntityId<FragmentId> GetOrCreateLargeFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  SpecificEntityId<FragmentId> GetOrCreateFragmentIdForHash(
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
