// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <memory>

namespace llvm {
namespace json {
class Object;
}  // namespace json
}  // namespace llvm
namespace mx {
class DatalogClient;
}  // namespace mx
namespace pasta {
class FileManager;
}  // namespace pasta
namespace importer {

class Importer {
 private:
  struct PrivateData;

  std::unique_ptr<PrivateData> d;

 public:
  ~Importer(void);
  Importer(void);

  bool ImportBlightCompileCommand(llvm::json::Object &o);
  bool ImportBlightCompileInfo(llvm::json::Object &o);
  bool ImportCMakeCompileCommand(llvm::json::Object &o);

  void Build(pasta::FileManager &fm, mx::DatalogClient &builder);
};

}  // namespace importer
