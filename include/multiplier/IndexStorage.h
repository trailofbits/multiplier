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
  kEntityIdReference
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

class IndexStorage final {
  sqlite::Connection &db;

 public:
  mx::PersistentAtomicStorage<mx::kNextFileId, mx::RawEntityId>
      next_file_id;

  mx::PersistentAtomicStorage<mx::kNextSmallCodeId, mx::RawEntityId>
      next_small_fragment_id;

  mx::PersistentAtomicStorage<mx::kNextBigCodeId, mx::RawEntityId>
      next_big_fragment_id;

  // The next indexing version number. This is incremented prior to starting
  // an indexing run, and just after. The double-increment is there just in
  // case some clients come along and issue some queries prior to indexing being
  // finished. We want best-effort resolution of definitions/redeclarations
  // during this time, but we don't want to commit to those results, just in
  // case there are more redeclarations that come in betwween the client request
  // and finishing indexing.
  mx::PersistentAtomic<kIndexingVersion, unsigned> version_number;

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
