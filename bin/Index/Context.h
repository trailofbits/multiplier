// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <cstdint>
#include <memory>
#include <multiplier/Datalog.h>
#include <multiplier/KeyValueStore.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>

#include <pasta/Util/FileManager.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <mutex>
#include <string>
#include <unordered_map>


namespace mx {
class Executor;
class ProgressBar;
}  // namespace mx
namespace indexer {

class GlobalContext {
 private:
  std::mutex tokenized_files_lock;
  mx::KeyValueStore tokenized_files;
  mx::KeyValueStore top_level_decl;

 public:

  std::unique_ptr<mx::ProgressBar> publish_progress;
  std::unique_ptr<mx::ProgressBar> command_progress;
  std::unique_ptr<mx::ProgressBar> ast_progress;
  std::unique_ptr<mx::ProgressBar> tokenizer_progress;

  std::atomic<mx::FileId> next_file_id;
  std::atomic<uint64_t> next_tlp_id;

  explicit GlobalContext(const mx::Executor &exe_,
                         const mx::DatalogClient &client_);

  std::pair<mx::FileId, bool> AddFileToSet(std::string path);
  std::pair<mx::DeclId, bool> AddDeclToSet(std::string decl);
};

class UpdateContext {
 private:
  UpdateContext(void) = delete;

 public:
  const mx::DatalogClient &client;
  const pasta::FileManager file_manager;
  std::shared_ptr<GlobalContext> global_context;

  const mx::ProgressBarWork publish_progress;
  mx::ProgressBar * const command_progress;
  mx::ProgressBar * const ast_progress;
  mx::ProgressBar * const tokenizer_progress;

  std::mutex builder_lock;
  mx::DatalogMessageBuilder builder;

  ~UpdateContext(void);
  UpdateContext(const mx::DatalogClient &client_,
                std::shared_ptr<GlobalContext> indexed_files_);

  inline std::pair<mx::FileId, bool> AddFileToSet(std::string path) {
    return global_context->AddFileToSet(std::move(path));
  }

  inline std::pair<mx::DeclId, bool> AddDeclToSet(std::string decl) {
    return global_context->AddDeclToSet(std::move(decl));
  }

};

class HashValue {
 public:
  using Ref = std::shared_ptr<HashValue>;

  static std::string ComputeHashValue(const std::vector<pasta::Decl> &decl_range,
                                      const pasta::TokenRange &toks,
                                      uint64_t begin_index, uint64_t end_index) {
    return Instance()->ComputeHash(decl_range, toks, begin_index, end_index);
  }

 private:
  static Ref Instance(void) {
    class HashValueImpl : public HashValue{};
    static auto I = std::make_shared<HashValueImpl>();
    return I;
  }

  std::string ComputeHash(const std::vector<pasta::Decl> &decl_range,
                          const pasta::TokenRange &toks,
                          uint64_t begin_index, uint64_t end_index);

};

}  // namespace indexer
