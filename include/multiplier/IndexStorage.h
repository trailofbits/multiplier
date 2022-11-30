// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Types.h"
#include "SQLiteStore.h"
#include "SymbolDatabase.h"
#include "PersistentMap.h"
#include "PersistentAtomicStorage.h"

namespace mx {
enum : char {
  kMetaNameToId,
  kFileIdToPath,
  kFileIdToHash,
  kFileIdToSerializedFile,
  kFileIdToFragmentId,
  kFileIdAndLineNumberToFragmentId,
  kFileHashToFileId,
  kFragmentHashToFragmentId,
  kFragmentIdToSerializedFragment,
  kFragmentIdToVersionNumber,
  kEntityIdRedecls,
  kEntityIdToMangledName,
  kMangledNameToEntityId,
  kEntityIdUseToFragmentId,
  kEntityIdReference,
  kSpellingToTokenKind,
};

enum MetadataName : char {
  // The next file ID that we can assign. File IDs are assigned in generally
  // increasing order. The assignment isn't necessarily strictly linear, i.e.
  // there may be some gaps, mostly just due to benign race conditions when
  // multiple indexer threads are used.
  kNextFileId,

  // The next ID for a "small code" fragment. Small code fragments have less
  // than 2^16 tokens in them, i.e. most fragments are small code fragments.
  // Fragment IDs for small code fragments fall in the range `[2^16, inf)`.
  kNextSmallCodeId,

  // The next ID for a "big code" fragment. Big code fragments have at least
  // 2^16 tokens in them. Most fragments do not fit this category; likely this
  // is the result of auto-generated code. We rely on there being fewer than
  // 2^16 of such fragments, and the IDs for these fall in the range of
  // `[1, 2^16)`,
  kNextBigCodeId,

  // Fragments are tagged with a version code. The version code tells us
  // if some of the info might be out-of-date. For example, when we serialize
  // a fragment, we treat it as implicitly out-of-date. The idea is that we
  // want to be able to know when we should possibly re-compute the definition
  // and re-declarations list for a given entity.
  kIndexingVersion,
};

struct ASTNode {
  std::optional<std::uint64_t> prev;
  unsigned short kind;
  RawEntityId entity;
  std::optional<std::string> spelling;
};

class PersistentAST final {
  struct Impl;
  std::unique_ptr<Impl> impl;

 public:
  PersistentAST(sqlite::Connection &db);

  std::vector<std::uint64_t> Root(RawEntityId fragment);

  std::uint64_t AddNode(const ASTNode& node);

  void AddNodeToRoot(RawEntityId fragment, std::uint64_t node_id);
  
  ASTNode GetNode(std::uint64_t node_id);

  std::optional<std::uint64_t> GetNodeInIndex(
    RawEntityId fragment,
    unsigned short kind);

  void SetNodeInIndex(
    RawEntityId fragment,
    unsigned short kind,
    std::uint64_t node_id);

  std::vector<mx::RawEntityId> GetFragments();

  std::vector<std::uint64_t> GetChildren(std::uint64_t parent);

  void AddChild(std::uint64_t parent, std::uint64_t child);
};

struct GrammarNode {
  bool is_production;
};

class PersistentGrammar final {
  struct Impl;
  std::unique_ptr<Impl> impl;

 public:
  PersistentGrammar(sqlite::Connection &db);

  std::vector<std::pair<unsigned short, std::uint64_t>> GetChildren(std::uint64_t parent);

  std::uint64_t GetChild(std::uint64_t parent, unsigned short kind);

  std::vector<std::pair<unsigned short, std::uint64_t>> GetChildLeaves(std::uint64_t parent, unsigned short kind);

  void UpdateNode(std::uint64_t id, const GrammarNode &node);

  GrammarNode GetNode(std::uint64_t id);
};

class IndexStorage final {
  sqlite::Connection &db;

 public:
  // The next indexing version number. This is incremented prior to starting
  // an indexing run, and just after. The double-increment is there just in
  // case some clients come along and issue some queries prior to indexing being
  // finished. We want best-effort resolution of definitions/redeclarations
  // during this time, but we don't want to commit to those results, just in
  // case there are more redeclarations that come in betwween the client request
  // and finishing indexing.
  mx::PersistentAtomic<kIndexingVersion, unsigned> version_number;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  mx::PersistentAtomic<kNextFileId, mx::RawEntityId> next_file_id;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  mx::PersistentAtomic<kNextSmallCodeId, mx::RawEntityId> next_small_fragment_id;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  mx::PersistentAtomic<kNextBigCodeId, mx::RawEntityId> next_big_fragment_id;

  // Maps file IDs to their absolute path, as well as to their token lists.
  mx::PersistentSet<kFileIdToPath, mx::RawEntityId, std::string>
      file_id_to_path;

  // Maps file IDs to a serialized `rpc::File` data structure.
  mx::PersistentMap<kFileIdToSerializedFile, mx::RawEntityId, std::string>
      file_id_to_serialized_file;

  // A set of `(file_id, fragment_id)` pairs for mapping from files to the
  // fragments contained in those files.
  mx::PersistentSet<kFileIdToFragmentId,
                    mx::RawEntityId  /* file id */,
                    mx::RawEntityId  /* fragment id */>
      file_fragment_ids;

  // A set of `(file_id, line number, fragment_id)` triples for mapping from
  // search results to the fragments that might overlap with those search
  // results.
  mx::PersistentSet<kFileIdAndLineNumberToFragmentId,
                    mx::RawEntityId  /* file id */,
                    unsigned  /* line number */,
                    mx::RawEntityId  /* fragment id */>
      file_fragment_lines;

  // Maps a hash of a file's contents to an ID for that file.
  mx::PersistentMap<kFileHashToFileId, std::string, mx::RawEntityId>
      file_hash_to_file_id;

  // Maps an aggregate key of the form
  //
  //    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
  //
  // to "fragment ids," that is, the ID of the serialized code containing one or
  // more top-level declarations.
  mx::PersistentMap<kFragmentHashToFragmentId, std::string, mx::RawEntityId>
      code_hash_to_fragment_id;

  // Maps a fragment ID to the serialized `rpc::Fragment` data structure.
  mx::PersistentMap<kFragmentIdToSerializedFragment,
                    mx::RawEntityId, std::string>
      fragment_id_to_serialized_fragment;

  // Each time we come across a redeclarable declaration, we add in the TU-
  // specific complete graph of `(redecl_i, redecl_j)` pairs to this set, so
  // that given a declaration ID, we can try to expand out and find the set of
  // all redeclarations by hopping from one of these graphs to another.
  mx::PersistentSet<kEntityIdRedecls, mx::RawEntityId, mx::RawEntityId>
      entity_redecls;

  // Maps entity IDs of functions and (non-local) variables to their mangled
  // names. We use this in combination with `mangled_name_to_entity_id` to
  // find redeclarations of a given entity.
  mx::PersistentSet<kEntityIdToMangledName, mx::RawEntityId, std::string>
      entity_id_to_mangled_name;

  // Maps mangled names of functions and (non-local) variables to their
  // entity IDs.
  mx::PersistentSet<kMangledNameToEntityId, std::string, mx::RawEntityId>
      mangled_name_to_entity_id;

  // Maps uses of entities to the IDs of fragments that use the entities.
  mx::PersistentSet<kEntityIdUseToFragmentId, mx::RawEntityId, mx::RawEntityId>
      entity_id_use_to_fragment_id;

  // Keeps track of references, e.g. `DeclRefExpr`, the fields accessed by
  // `MemberExpr`, etc.
  mx::PersistentSet<kEntityIdReference, mx::RawEntityId, mx::RawEntityId>
      entity_id_reference;

  mx::PersistentMap<kSpellingToTokenKind, std::string_view, mx::TokenKind>
      spelling_to_token_kind;

  PersistentAST ast;

  PersistentGrammar grammar;

  // SQLite database. Used for things like symbol searches.
  SymbolDatabase database;

  void Flush(void);

  ~IndexStorage(void);

  explicit IndexStorage(sqlite::Connection &db);

  // Return the set of redeclarations of an entity.
  std::vector<mx::RawEntityId> FindRedeclarations(mx::EntityId eid);
  
  std::optional<std::string>
  GetSerializedFile(mx::RawEntityId file_id);
};

} // namespace mx
