// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <multiplier/ProgressBar.h>
#include <multiplier/Types.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/FileManager.h>
#include <unordered_map>

#include "Context.h"

namespace pasta {
class AST;
class File;
class TokenRange;
}  // namespace pasta
namespace indexer {

struct FileIdMap;
struct FileHashMap;

class IndexCompileJobAction final : public mx::Action {
 private:
  const std::shared_ptr<IndexingContext> context;
  const pasta::FileManager file_manager;
  const pasta::CompileJob job;

  // Maps pasta files to their unique IDs.
  FileIdMap file_ids;

  // Maps pasta files to their hashes, represented as SHA256 checksums.
  FileHashMap file_hashes;

  // Look through all files referenced by the AST get their unique IDs. If this
  // is the first time seeing a file, then tokenize the file.
  void MaybePersistFile(mx::WorkerId worker_id, pasta::File file);

  void PersistParsedFiles(const pasta::AST &ast, mx::WorkerId worker_id);

 public:
  virtual ~IndexCompileJobAction(void);

  IndexCompileJobAction(std::shared_ptr<IndexingContext> context_,
                        pasta::FileManager file_manager_,
                        pasta::CompileJob job_);

  // Build and index the AST.
  void Run(mx::Executor exe, mx::WorkerId worker_id) final;
};

}  // namespace indexer
