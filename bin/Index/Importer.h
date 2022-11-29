// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <filesystem>
#include <memory>
#include <unordered_map>

#include <pasta/Compile/Command.h>

#include "Context.h"
#include "Executor.h"

namespace llvm {
namespace json {
class Object;
}  // namespace json
}  // namespace llvm
namespace indexer {

class EnvVariableMap : public std::unordered_map<std::string, std::string> {};

class Importer {
 private:

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  Importer(void) = delete;

 public:
  ~Importer(void);
  explicit Importer(std::filesystem::path cwd_,
    pasta::FileManager &fm,
    std::shared_ptr<GlobalIndexingState> context);

  bool ImportBlightCompileCommand(llvm::json::Object &o);
  bool ImportCMakeCompileCommand(llvm::json::Object &o, const EnvVariableMap &envp);

  void Import(mx::Executor &executor);
};

}  // namespace indexer
