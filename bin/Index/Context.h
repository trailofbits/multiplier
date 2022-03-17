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
  kFileHashToTokens,
  kFileHashToFileId,
  kFilePathToFileId,
  kCodeHashToCodeId,
  kCodeIdToIndexedCode,
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

 private:
  friend class IndexingContext;

  mx::PersistentMap<kMetaNameToId, MetadataName, uint64_t> meta_to_id;

  std::atomic<mx::FileId> next_file_id;
  std::atomic<mx::CodeId> next_small_code_id;
  std::atomic<mx::CodeId> next_big_code_id;

  // Maps file IDs to their absolute path, as well as to their token lists.
  mx::PersistentMap<kFileIdToPath, mx::FileId, std::string> file_id_to_path;
  mx::PersistentMap<kFileIdToHash, mx::FileId, std::string> file_id_to_hash;

  // Maps file IDs to the tokenized file contents.
  mx::PersistentMap<kFileHashToTokens, mx::FileId, kj::Array<capnp::word>>
      file_id_to_tokens;

  // Maps a sha256 hash of a file's contents to an ID for that file.
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
  // to "code ids," that is, the ID of the serialized code containing one or
  // more top-level declarations.
  mx::PersistentMap<kCodeHashToCodeId, std::string, mx::CodeId>
      code_hash_to_code_id;

  // Maps a code ID to the serialized `rpc::IndexedCode` data structure.
  mx::PersistentMap<kCodeIdToIndexedCode, mx::CodeId, kj::Array<capnp::word>>
      code_id_to_indexed_code;

  void Flush(void);

 public:
  ~ServerContext(void);

  explicit ServerContext(std::filesystem::path workspace_dir_);
};

// State that needs to live only as long as there are active indexing jobs
// underway.
class IndexingContext {
 private:

 public:
  const std::shared_ptr<ServerContext> server_context;
  std::unique_ptr<mx::ProgressBar> command_progress;
  std::unique_ptr<mx::ProgressBar> ast_progress;
  std::unique_ptr<mx::ProgressBar> tokenizer_progress;

  explicit IndexingContext(std::shared_ptr<ServerContext> server_context_);

  ~IndexingContext(void);

  void InitializeProgressBars(const mx::Executor &exe_);

  // Get or create a file ID for the file at `file_path` with contents
  // `contents_hash`.
  std::pair<mx::FileId, bool> GetOrCreateFileId(
      std::filesystem::path file_path, const std::string &contents_hash);

  // Get or create a code ID for the top-level declarations that hash to
  // `code_hash`.
  std::pair<mx::CodeId, bool> GetOrCreateCodeId(const std::string &code_hash,
                                                uint64_t num_tokens);

  // Save the serialized contents of a file as a token list.
  void PutFileTokens(mx::FileId file_id, kj::Array<capnp::word> tokens);

  // Save the serialized top-level entities and the parsed tokens.
  void PutIndexedCode(mx::CodeId code_id, kj::Array<capnp::word> code);
};

}  // namespace indexer
