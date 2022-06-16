// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <capnp/message.h>
#include <cstdint>
#include <filesystem>
#include <kj/array.h>
#include <memory>
#include <multiplier/PersistentMap.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>
#include <mutex>
#include <pasta/Util/FileManager.h>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

namespace mx {
class Executor;
class ProgressBar;
enum WorkerId : unsigned;
enum class DeclKind : unsigned char;
}  // namespace mx
namespace indexer {

class Database;

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

enum CounterType : unsigned {
  kStatCompileCommand = 0u,
  kStatCompileJob,
  kStatAST,
  kStatCodeFragment,
  kStatUniqueCodeFragment,
  kStatSourceIRFragment
};

class IndexingContext;
class CodeGenerator;

template <typename T>
struct alignas(64) NextId {
  std::optional<T> id;
};

// State that lives at least as long as the server itself.
class ServerContext {
 public:
  const std::filesystem::path workspace_dir;

  mx::PersistentMap<kMetaNameToId, MetadataName, uint64_t> meta_to_value;

  // The next indexing version number. This is incremented prior to starting
  // an indexing run, and just after. The double-increment is there just in
  // case some clients come along and issue some queries prior to indexing being
  // finished. We want best-effort resolution of definitions/redeclarations
  // during this time, but we don't want to commit to those results, just in
  // case there are more redeclarations that come in betwween the client request
  // and finishing indexing.
  std::atomic<unsigned> version_number;

  // The next file ID that can be assigned. This represents an upper bound on
  // the total number of file IDs.
  std::atomic<mx::FileId> next_file_id;

  // The next ID for a "small fragment." A small fragment has fewer than
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Small fragments
  // are more common, and require fewer bits to encode token offsets inside of
  // the packed `mx::EntityId` for tokens.
  std::atomic<mx::FragmentId> next_small_fragment_id;

  // The next ID for a "big fragment." A big fragment has at least
  // `mx::kNumTokensInBigFragment` tokens (likely 2^16) in it. Big fragments
  // are less common, so we reserve space for fewer of them (typically there is
  // a maximum of 2^16 big fragments allowed). Big fragments require more bits
  // to represent token offsets inside of the packed `mx::EntityId` for tokens,
  // but because we reserve the low ID space for big fragment IDs, we know that
  // we need fewer bits to represent the fragment IDs. Thus, we trade fragment
  // bit for token offset bits.
  std::atomic<mx::FragmentId> next_big_fragment_id;

  // Maps file IDs to their absolute path, as well as to their token lists.
  mx::PersistentSet<kFileIdToPath, mx::FileId, std::string> file_id_to_path;

  // Maps file IDs to a serialized `rpc::File` data structure.
  mx::PersistentMap<kFileIdToSerializedFile, mx::FileId, std::string>
      file_id_to_serialized_file;

  // A set of `(file_id, fragment_id)` pairs for mapping from files to the
  // fragments contained in those files.
  mx::PersistentSet<kFileIdToFragmentId, mx::FileId, mx::FragmentId>
      file_fragment_ids;

  // A set of `(file_id, line number, fragment_id)` triples for mapping from
  // search results to the fragments that might overlap with those search
  // results.
  mx::PersistentSet<kFileIdAndLineNumberToFragmentId,
                    mx::FileId, unsigned, mx::FragmentId>
      file_fragment_lines;

  // Maps a hash of a file's contents to an ID for that file.
  mx::PersistentMap<kFileHashToFileId, std::string, mx::FileId>
      file_hash_to_file_id;

  // Maps an aggregate key of the form
  //
  //    <file hash>:<line>:<column>:<tokens hash>:<odr hash 0>:...:<odr hash N>
  //
  // to "fragment ids," that is, the ID of the serialized code containing one or
  // more top-level declarations.
  mx::PersistentMap<kFragmentHashToFragmentId, std::string, mx::FragmentId>
      code_hash_to_fragment_id;

  // Maps a fragment ID to the serialized `rpc::Fragment` data structure.
  mx::PersistentMap<kFragmentIdToSerializedFragment,
                    mx::FragmentId, std::string>
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
  mx::PersistentSet<kEntityIdUseToFragmentId, mx::RawEntityId, mx::FragmentId>
      entity_id_use_to_fragment_id;

  // Keeps track of references, e.g. `DeclRefExpr`, the fields accessed by
  // `MemberExpr`, etc.
  mx::PersistentSet<kEntityIdReference, mx::RawEntityId, mx::FragmentId>
      entity_id_reference;

  std::unique_ptr<Database> connection;

  void Flush(void);

  ~ServerContext(void);

  explicit ServerContext(std::filesystem::path workspace_dir_);

  // Return the set of redeclarations of an entity.
  std::vector<mx::RawEntityId> FindRedeclarations(mx::EntityId eid);
};

// Indexing Context counter
class IndexingCounter {
 public:
  virtual ~IndexingCounter() {
    PrintAll();
  }

  explicit IndexingCounter(void) {
    ResetAll();
  }

  uint64_t Increament(CounterType id) {
    if (id < kStatSourceIRFragment + 1) {
      return counter[id].fetch_add(mx::kMinEntityIdIncrement);
    }
    return 0ull;
  }

  uint64_t Decrement(CounterType id) {
    if (id < kStatSourceIRFragment + 1) {
      return counter[id].fetch_sub(mx::kMinEntityIdIncrement);
    }
    return 0ull;
  }

  private :

  void ResetAll(void);
  void PrintAll(void);

  std::atomic<uint64_t> counter[kStatSourceIRFragment + 1];
};

class IndexingCounterRes {
 public:
  inline explicit IndexingCounterRes(
      IndexingCounter &stat_, CounterType id) {
    stat_.Increament(id);
  }
};

// State that needs to live only as long as there are active indexing jobs
// underway.
class IndexingContext {
 public:
  ServerContext &server_context;

  IndexingCounter stat;

  // Tracks progress in parsing compile commands and turning them into compile
  // jobs.
  std::unique_ptr<mx::ProgressBar> command_progress;

  // Tracks progress in running compile jobs to produce ASTs.
  std::unique_ptr<mx::ProgressBar> ast_progress;

  // Tracks progress in partitioning an AST into fragments.
  std::unique_ptr<mx::ProgressBar> partitioning_progress;

  // Tracks progress in identifying fragments with IDs.
  std::unique_ptr<mx::ProgressBar> identification_progress;

  // Tracks progress in serializing fragments.
  std::unique_ptr<mx::ProgressBar> serialization_progress;

  // Tracks progress in saving tokenized files.
  std::unique_ptr<mx::ProgressBar> file_progress;

  const unsigned num_workers;

  // Version number to assign to all created fragments.
  //
  // NOTE(pag): This is explicitly out-of-data w.r.t. the backing storage. The
  //            purpose is to save an older version number so that when a client
  //            requests a fragment, we can see if we need to fixup the
  //            canonical declarations of things.
  const unsigned version_number;

  // Worker-local next counters for IDs.
  std::vector<NextId<mx::FileId>> local_next_file_id;
  std::vector<NextId<mx::FragmentId>> local_next_small_fragment_id;
  std::vector<NextId<mx::FragmentId>> local_next_big_fragment_id;

  std::unique_ptr<CodeGenerator> codegen;

  std::vector<std::unique_ptr<Database>> databases;

  explicit IndexingContext(ServerContext &server_context_,
                           const mx::Executor &exe_);

  ~IndexingContext(void);

  void InitializeProgressBars(void);

  void InitializeCodeGenerator(void);

  // Get or create a file ID for the file at `file_path` with contents
  // `contents_hash`.
  std::pair<mx::FileId, bool> GetOrCreateFileId(
      mx::WorkerId worker_id, std::filesystem::path file_path,
      const std::string &contents_hash);

  // Get or create a code ID for the top-level declarations that hash to
  // `code_hash`.
  std::pair<mx::FragmentId, bool> GetOrCreateFragmentId(
      mx::WorkerId worker_id, const std::string &code_hash,
      uint64_t num_tokens);

  // Save the serialized contents of a file as a token list.
  void PutSerializedFile(mx::FileId file_id, std::string);

  // Save the serialized top-level entities and the parsed tokens.
  void PutSerializedFragment(mx::FragmentId id, std::string);

  // Link fragment declarations.
  void LinkDeclarations(mx::RawEntityId a, mx::RawEntityId b);

  // Link the mangled name of something to its entity ID.
  void LinkMangledName(const std::string &name, mx::RawEntityId eid);

  // Link an entity to the fragment that uses the entity.
  void LinkUseInFragment(mx::RawEntityId use, mx::FragmentId user);

  // Link a direct reference to an entity from another entity.
  void LinkReferenceInFragment(mx::RawEntityId use, mx::FragmentId user);

  // Save an entries of the form `(file_id, line_number, fragment_id)` over
  // the inclusive range `[start_line, end_line]` so that we can figure out
  // which fragments overlap which lines.
  void PutFragmentLineCoverage(mx::FileId file_id, mx::FragmentId fragment_id,
                               unsigned start_line, unsigned end_line);

  // Prepare database
  void PrepareDatabase(mx::WorkerId id);

  // Commit database
  void CommitDatabase(mx::WorkerId id);
};

class SearchingContext {
 public:
  ServerContext &server_context;

  explicit SearchingContext(ServerContext &server_context_);
  virtual ~SearchingContext(void);

  // Next file ID for any `SearchingAction` to look at.
  std::atomic<mx::FileId> local_next_file_id;

  // Set of `file_id:line_number` pairs where matches were approximately
  // found.
  std::set<std::tuple<mx::FileId, unsigned>> line_results;
  std::mutex line_results_lock;

  std::optional<std::string>
  GetSerializedFile(mx::FileId file_id);
};

}  // namespace indexer
