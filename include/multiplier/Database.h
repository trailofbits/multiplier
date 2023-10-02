// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <string>

#include "Reference.h"
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
    m(NestedFragmentRecord) \
    m(FragmentFileRangeRecord) \
    m(RedeclarationRecord) \
    m(MangledNameRecord) \
    m(ReferenceRecord) \
    m(NamedEntityRecord) \
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
  std::string path;
};

// Tells us which file the "root" of a fragment belongs to. Note that a fragment
// can span/include other files internally.
struct FragmentFileRecord {
  static constexpr const char *kTableName = "fragment_file";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS fragment_file (
            fragment_id INTEGER NOT NULL PRIMARY KEY,
            file_id INTEGER NOT NULL
          ) WITHOUT ROWID)",
       R"(CREATE INDEX IF NOT EXISTS fragments_in_file
          ON fragment_file(file_id))"};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO fragment_file (fragment_id, file_id)
         VALUES (?1, ?2))";

  PackedFragmentId fragment_id;
  PackedFileId file_id;
};

struct NestedFragmentRecord {
  static constexpr const char *kTableName = "nested_fragment";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS nested_fragment (
            parent_id INTEGER NOT NULL,
            child_id INTEGER NOT NULL,
            PRIMARY KEY(parent_id, child_id)
          ) WITHOUT ROWID)",};

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO nested_fragment (parent_id, child_id)
         VALUES (?1, ?2))";

  PackedFragmentId parent_id;
  PackedFragmentId child_id;
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

// Tells us that `redecl_id` is a redeclaration of `decl_id`.
struct RedeclarationRecord {
  static constexpr const char *kTableName = "redeclaration";

  static constexpr const char *kInitStatements[] =
      {R"(CREATE TABLE IF NOT EXISTS redeclaration (
            decl_id INTEGER NOT NULL,
            redecl_id INTEGER NOT NULL,
            PRIMARY KEY(decl_id, redecl_id)
          ) WITHOUT ROWID)",
       R"(CREATE INDEX IF NOT EXISTS redecl_id_from_decl_id
          ON redeclaration(decl_id))",
       R"(CREATE INDEX IF NOT EXISTS decl_id_from_redecl_id
          ON redeclaration(redecl_id))"};

  static constexpr const char *kExitStatements[] = {nullptr};

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
          ) WITHOUT ROWID)",
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

  static constexpr const char *kExitStatements[] = {nullptr};

  static constexpr const char *kInsertStatement =
      R"(INSERT INTO mangled_name (entity_id, data)
         VALUES (?1, ?2))";

  // A `DeclId` or a `MacroId`.
  RawEntityId entity_id;

  std::string mangled_name;
};

// Represents the name of some symbol.
struct NamedEntityRecord {
  static constexpr const char *kTableName = "named_entity";

  static constexpr const char *kInitStatements[] = {
      R"(CREATE TABLE IF NOT EXISTS named_entity (
           entity_id INTEGER NOT NULL PRIMARY KEY,
           name TEXT NOT NULL
         ) WITHOUT ROWID)",

#if MX_DATABASE_HAS_FTS5
      R"(CREATE VIRTUAL TABLE IF NOT EXISTS named_entity_index
         USING fts5(name, content='named_entity', content_rowid='entity_id'))",

      R"(CREATE TRIGGER IF NOT EXISTS named_entity_ai AFTER INSERT ON named_entity BEGIN
           INSERT INTO named_entity_index (rowid, name) 
           VALUES (new.entity_id, new.name);
         END)"
#endif
      };

  static constexpr const char *kExitStatements[] = {
#if MX_DATABASE_HAS_FTS5
      R"(INSERT INTO named_entity_index(named_entity_index) VALUES('optimize'))"
#else
      nullptr
#endif
      };

  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO named_entity (entity_id, name)
         VALUES (?1, ?2))";

  // A `DeclId` or a `MacroId`.
  RawEntityId entity_id;

  // A name, e.g. `std::abs`.
  std::string name;
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
            context_id INTEGER NOT NULL,
            kind_id INTEGER NOT NULL,
            PRIMARY KEY(to_entity_id ASC,
                        from_entity_id ASC,
                        context_id ASC,
                        kind_id)
          ) WITHOUT ROWID)",

       R"(CREATE TABLE IF NOT EXISTS reference_kind (
            kind BLOB NOT NULL PRIMARY KEY
          ))",

       // The reference kind values should be in sync with the enum
       // `BuildinReferenceKind` (include/multiplier/Reference.h:29).
       // The reference_kind table is used to convert the reference kind
       // into string that appears in the info browser.
       R"(INSERT OR IGNORE INTO reference_kind (rowid, kind)
          VALUES (0, "Use"),
                 (1, "Address of"),
                 (2, "Assigned To"),
                 (3, "Assignment"),
                 (4, "Called By"),
                 (5, "Call Argument"),
                 (6, "Used By"),
                 (7, "Dereference"),
                 (8, "Enumeration"),
                 (9, "Expansion"),
                 (10, "Included By"),
                 (11, "Initialization"),
                 (12, "Influencing Condition"),
                 (13, "Type Cast"),
                 (14, "Statement Use"),
                 (15, "Type Trait Use")
          )"};

  static constexpr const char *kExitStatements[] = {nullptr};

  // NOTE(pag): Reference id `0` is the id of an "explicit code reference."
  static constexpr const char *kInsertStatement =
      R"(INSERT OR IGNORE INTO reference (from_entity_id,
         to_entity_id, context_id, kind_id)
         VALUES (?1, ?2, ?3, ?4))";

  // Entity id of the referer
  RawEntityId from_entity_id;

  // Entity id of the reference
  RawEntityId to_entity_id;

  // Entity id of the context in which reference has happened. It will
  // be either same as `from_entity_id` or ancestor of `from_entity_id`.
  RawEntityId context_id;
  mx::BuiltinReferenceKind kind;
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
          ) WITHOUT ROWID)",
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
                                  MX_CREATE_ENTITY_VIEW,
                                  MX_CREATE_ENTITY_VIEW,
                                  MX_CREATE_ENTITY_VIEW,
                                  MX_CREATE_ENTITY_VIEW)
      #undef MX_CREATE_ENTITY_VIEW
  };

  static constexpr const char *kExitStatements[] = {nullptr};

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

  // Get, or create and return, a fragment ID for the specific fragment hash.
  PackedFragmentId GetOrCreateSmallFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  // Get, or create and return, a fragment ID for the specific fragment hash.
  PackedFragmentId GetOrCreateBigFragmentIdForHash(
      RawEntityId tok_id, std::string hash, bool &is_new);

  // Get, or create and return, a type ID for the specific type.
  PackedTypeId GetOrCreateSmallTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, bool &is_new);

  // Get, or create and return, a type ID for the specific type.
  PackedTypeId GetOrCreateBigTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, bool &is_new);

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
           next_big_fragment_index INTEGER NOT NULL,
           next_small_type_index INTEGER NOT NULL,
           next_big_type_index INTEGER NOT NULL,
           next_compilation_index INTEGER NOT NULL
         ))",

      R"(CREATE TABLE IF NOT EXISTS version (
           action INTEGER NOT NULL
         ))",

      R"(CREATE INDEX IF NOT EXISTS version_action ON version(action))"};

//  static constexpr const char *kExitStatments[] = {
//      };

  ~DatabaseWriter(void);

  explicit DatabaseWriter(std::filesystem::path db_path,
                          size_t max_queue_size_in_bytes);

  // Schedule all outstanding asynchronous writes to be flushed. This operation
  // is itself asynchronous, and when it returns, there are no guarantees that
  // the database writes have actually happened.
  void AsyncFlush(void);

  // Get, or create and return, a file ID for the specific file contents hash.
  PackedFileId GetOrCreateFileIdForHash(
      std::string hash, bool &is_new);

  PackedFragmentId GetOrCreateFragmentIdForHash(
      RawEntityId tok_id, std::string hash, size_t num_tokens, bool &is_new);

  PackedTypeId GetOrCreateTypeIdForHash(
      mx::TypeKind type_kind, uint32_t type_qualifiers,
      std::string hash, size_t num_tokens, bool &is_new);

  // Get, or create and return, a translation unit ID for the specific compile
  // command hash.
  PackedCompilationId GetOrCreateCompilationId(
      RawEntityId file_id, std::string hash, bool &is_new);

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
