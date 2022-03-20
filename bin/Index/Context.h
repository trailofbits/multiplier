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

#include <pasta/Util/FileManager.h>

#include <string>
#include <unordered_map>

namespace mx {
class Executor;
class ProgressBar;
}  // namespace mx
namespace indexer {

enum : char {
  kMetaNameToId,
  kFileIdToPath,
  kFileIdToHash,
  kFileIdToSerializedFile,
  kFileHashToFileId,
  kFilePathToFileId,
  kFragmentHashToFragmentId,
  kFragmentIdToSerializedFragment,
};

enum MetadataName : char {
  kNextFileId,
  kNextSmallCodeId,
  kNextBigCodeId
};

class IndexingContext;

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
  mx::PersistentMap<kFileIdToPath, std::pair<mx::FileId, std::string>,
                    mx::Empty> file_id_to_path;

  // Maps file IDs to a serialized `rpc::File` data structure.
  mx::PersistentMap<kFileIdToSerializedFile, mx::FileId, kj::Array<capnp::word>>
      file_id_to_serialized_file;

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

  // Maps a code ID to the serialized `rpc::Fragment` data structure.
  mx::PersistentMap<kFragmentIdToSerializedFragment,
                    mx::FragmentId, kj::Array<capnp::word>>
      code_id_to_indexed_code;

  void Flush(void);

  ~ServerContext(void);

  explicit ServerContext(std::filesystem::path workspace_dir_);
};

// State that needs to live only as long as there are active indexing jobs
// underway.
class IndexingContext {
 public:
  ServerContext &server_context;

  // Tracks progress in parsing compile commands and turning them into compile
  // jobs.
  std::unique_ptr<mx::ProgressBar> command_progress;

  // Tracks progress in running compile jobs to produce ASTs.
  std::unique_ptr<mx::ProgressBar> ast_progress;

  // Tracks progress in saving tokenized files.
  std::unique_ptr<mx::ProgressBar> tokenizer_progress;

  explicit IndexingContext(ServerContext &server_context_);

  ~IndexingContext(void);

  void InitializeProgressBars(const mx::Executor &exe_);

  // Get or create a file ID for the file at `file_path` with contents
  // `contents_hash`.
  std::pair<mx::FileId, bool> GetOrCreateFileId(
      std::filesystem::path file_path, const std::string &contents_hash);

  // Get or create a code ID for the top-level declarations that hash to
  // `code_hash`.
  std::pair<mx::FragmentId, bool> GetOrCreateFragmentId(
      const std::string &code_hash, uint64_t num_tokens);

  // Save the serialized contents of a file as a token list.
  void PutSerializedFile(mx::FileId file_id, kj::Array<capnp::word> tokens);

  // Save the serialized top-level entities and the parsed tokens.
  void PutSerializedFragment(mx::FragmentId code_id,
                             kj::Array<capnp::word> code);
};

}  // namespace indexer
