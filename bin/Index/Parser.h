// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <string_view>
#include <unordered_map>

namespace llvm {
namespace object {
class Archive;
class Binary;
class IRObjectFile;
class MachOUniversalBinary;
class ObjectFile;
}  // namespace object
namespace json {
class Value;
}  // namespace json
class LLVMContext;
class MemoryBuffer;
class Module;
}  // namespace llvm

namespace indexer {

class EnvVariableMap;
class Importer;

class Parser {
 public:
  llvm::LLVMContext &context;
  Importer &importer;

  explicit Parser(llvm::LLVMContext &context_, Importer &importer_)
      : context(context_),
        importer(importer_) {}

  // Parse a memory buffer as a binary/object of some form.
  bool Parse(const llvm::MemoryBuffer &buffer, const EnvVariableMap &envp);

 private:
  // Parse a binary.
  bool ParseBinary(llvm::object::Binary *bin);

  // Recursively import any commands from each object embedded in this archive.
  bool ParseArchive(llvm::object::Archive *archive);

  // Parse compile commands from an LLVM module.
  bool ParseModule(const llvm::Module &module);

  // Parse compile commands data from an LLVM IR object file containing one or
  // more modules.
  bool ParseIR(llvm::object::IRObjectFile *ir);

  // Parse all targets contained within this universal binary.
  //
  // TODO(pag): Should we provide a command-line option or interactivity to
  //            ask if only one of these objects should be "in scope"?
  bool ParseUB(llvm::object::MachOUniversalBinary *ub);

  // Parse an object file. This goes through and tries to identify Blight-
  // inserted sections, and then import them.
  bool ParseObject(llvm::object::ObjectFile *object);

  // Parse a compile command as embedded in a binary.
  bool ParseBinaryJSONCommands(std::string_view file_name,
                               std::string_view data);

  // Parse a compile command as embedded in a binary.
  bool ParseBinaryJSONCommand(llvm::json::Value &json);

  // Parse a `compile_commands.json`-type file.
  bool ParseCompileCommandsJSON(std::string_view file_name,
                                llvm::json::Value &json,
                                const EnvVariableMap &envp);
};

}  // namespace indexer
