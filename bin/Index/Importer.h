// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>

namespace llvm {
namespace json {
class Object;
}  // namespace json
}  // namespace llvm
namespace pasta {
class FileManager;
}
namespace indexer {

class GlobalIndexingState;
class EnvVariableMap : public std::unordered_map<std::string, std::string> {};
class Executor;

class Importer {
 private:

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

  Importer(void) = delete;

 public:
  ~Importer(void);

  explicit Importer(std::filesystem::path cwd_,
                    const pasta::FileManager &fm,
                    std::shared_ptr<GlobalIndexingState> context);

  bool ImportBlightCompileCommand(llvm::json::Object &o);
  bool ImportCMakeCompileCommand(llvm::json::Object &o,
                                 const EnvVariableMap &envp);

  void Import(Executor &executor);
};

}  // namespace indexer
