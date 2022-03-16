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
#include<set>

namespace mx {
class Executor;
class ProgressBar;
enum WorkerId : unsigned;
}  // namespace mx
namespace indexer {

enum : char {
  kMetaNameToId,
  kFileIdToPath,
  kFileIdToHash,
  kFileIdToSerializedFile,
  kFileIdToFragmentId,
  kFileIdAndLineNumberToFragmentId,
  kFileHashToFileId,
  kFilePathToFileId,
  kFragmentHashToFragmentId,
  kFragmentIdToSerializedFragment,
  kFragmentIdtoSourceIR
};

enum MetadataName : char {
  kNextFileId,
  kNextSmallCodeId,
  kNextBigCodeId
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

  mx::PersistentMap<kMetaNameToId, MetadataName, uint64_t> meta_to_id;

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

  // Maps an absolute path to a file's ID. Multiple files may map to the same
  // ID if their contents are identical.
  mx::PersistentMap<kFilePathToFileId, std::string, mx::FileId>
      file_path_to_file_id;

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

  void Flush(void);

  mx::PersistentMap<kFragmentIdtoSourceIR, mx::FragmentId, std::string>
      code_id_to_source_ir;

 public:
  ~ServerContext(void);

  explicit ServerContext(std::filesystem::path workspace_dir_);
};

template <typename K, typename V>
struct alignas(64) AtomicMap
    : public std::unordered_map<K, V>, public std::mutex {};

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

  // In-memory caches that gate read/write access to
  // `ServerContext::code_hash_to_fragment_id`, because a lot of CPU is spent
  // there.
  //
  // TODO(pag): Perhaps its related to RocksDB trying to maintain ordering?
  //            Would be nice to use a separate `rocksdb::ColumnFamily` and tell
  //            it to optimize for point queries.
  AtomicMap<std::string, AtomicMap<std::string, mx::FragmentId>>
      code_hash_to_fragment_id_maps;

  // Worker-local next counters for IDs.
  std::vector<NextId<mx::FileId>> local_next_file_id;
  std::vector<NextId<mx::FragmentId>> local_next_small_fragment_id;
  std::vector<NextId<mx::FragmentId>> local_next_big_fragment_id;

  std::unique_ptr<CodeGenerator> codegen;

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
  void PutSerializedFragment(mx::FragmentId code_id, std::string);

  // Save an entries of the form `(file_id, line_number, fragment_id)` over
  // the inclusive range `[start_line, end_line]` so that we can figure out
  // which fragments overlap which lines.
  void PutFragmentLineCoverage(mx::FileId file_id, mx::FragmentId fragment_id,
                               unsigned start_line, unsigned end_line);

  // Save the source ir contents for tlds
  void PutSourceIRs(mx::FragmentId code_id, std::string source_ir);

};

class SearchingContext {
 public:
  ServerContext &server_context;

  explicit SearchingContext(ServerContext &server_context_,
                            const mx::Executor &exe_);
  virtual ~SearchingContext(void);

  const unsigned num_workers;

  std::atomic<mx::FileId> local_next_file_id;

  std::set<std::tuple<mx::FileId, mx::FragmentId>> fragments_result;

  std::pair<mx::FileId, bool> GetNextFileId(void);

  std::optional<mx::FileId> GetMaxFileId(void);

  std::optional<std::string>
  GetSerializedFile(mx::FileId file_id);

  std::optional<std::string>
  GetSerializedFragment(mx::FragmentId fragment_id);

  template <typename P, typename C>
  void ScanFilePrefix(P prefix, C callback) const {
    server_context.file_fragment_ids.ScanPrefix(prefix, callback);
  }

};

}  // namespace indexer
