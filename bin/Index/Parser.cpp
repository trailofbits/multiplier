// Copyright (c) 2021-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Parser.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "ScopedPrinter.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Object/Archive.h>
#include <llvm/Object/Binary.h>
#include <llvm/Object/COFF.h>
#include <llvm/Object/COFFImportFile.h>
#include <llvm/Object/ELF.h>
#include <llvm/Object/ELFObjectFile.h>
#include <llvm/Object/IRObjectFile.h>
#include <llvm/Object/MachO.h>
#include <llvm/Object/MachOUniversal.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Object/Wasm.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/TargetSelect.h>
#pragma clang diagnostic pop

#include <gflags/gflags.h>
#include <glog/logging.h>

#include "Importer.h"
#include "Log.h"

namespace indexer {
namespace {

static std::vector<std::string> SplitCompileCommands(std::string_view cmd_str) {
  std::vector<std::string> cmd_vec;
  std::stringstream ss;
  ss << cmd_str;
  for (std::string line; std::getline(ss, line, '\0');) {
    auto found = line.find_first_of("{");
    if (found != std::string::npos) {
      cmd_vec.push_back(line);
    }
  }
  return cmd_vec;
}

static std::string_view SanitizeJsonString(std::string_view str,
                                           std::string_view start_chars,
                                           std::string_view end_chars) {
  return str.substr(str.find_first_of(start_chars),
                    str.find_last_of(end_chars) + 1u);
}

}  // namespace

// Parse an object file. This goes through and tries to identify Blight-
// inserted sections, and then import them.
bool Parser::ParseObject(llvm::object::ObjectFile *object) {
  const llvm::StringRef file_name = object->getFileName();
  const std::string file_name_str = file_name.str();

  auto ret = true;

  // Inspect each section in this object file.
  for (const llvm::object::SectionRef &sec : object->sections()) {
    auto maybe_name = sec.getName();
    if (llvm::errorToBool(maybe_name.takeError())) {
      LOG(WARNING)
          << "Missing section name in object file " << file_name;
      continue;
    }

    llvm::StringRef name = std::move(*maybe_name);
    if (name.empty()) {
      LOG(WARNING)
          << "Empty section name in object file " << file_name;
      continue;
    }

    LOG(INFO) << "section name: " << name.str();

    // If we've found a section with embedded compile commands, then
    // try to parse them and import them.
    if (!name.contains_insensitive("trailofbits_cc")) {
      continue;
    }

    LOG(INFO)
        << "Found compile commands section in " << file_name;

    auto maybe_data = sec.getContents();
    if (llvm::errorToBool(maybe_data.takeError())) {
      LOG(ERROR)
          << "Unable to get data for the compile commands section '"
          << name.str() << "' from object file "
          << file_name;

      ret = false;
      continue;
    }

    std::string_view commands_view(maybe_data->data(), maybe_data->size());
    ret &= ParseBinaryJSONCommands(file_name_str, commands_view);
  }

  return ret;
}

// Recursively import any commands from each object embedded in this archive.
bool Parser::ParseArchive(llvm::object::Archive *archive) {
  auto err = llvm::Error::success();
  auto ret = true;
  for (const llvm::object::Archive::Child &child
          : archive->children(err, false  /* SkipInternal */)) {
    auto maybe_bin = child.getAsBinary(&context);
    if (llvm::errorToBool(maybe_bin.takeError())) {
      ret = false;
      continue;
    }

    ret &= ParseBinary(maybe_bin.get().get());
  }
  return err ? false : ret;
}

// Parse compile commands from an LLVM module.
bool Parser::ParseModule(const llvm::Module &module) {
  auto ret = true;
  for (const llvm::GlobalVariable &var : module.globals()) {
    if (!var.hasInitializer()) {
      continue;
    }

    auto init = llvm::dyn_cast<llvm::ConstantDataArray>(var.getInitializer());
    if (!init || !init->isString()) {
      continue;
    }

    auto section_name = var.getSection();
    if (section_name.contains_insensitive("trailofbits_cc")) {
      LOG(INFO)
          << "Found compile command variable '" << var.getName()
          << "' in bitcode module " << module.getName();

      auto file_name = module.getName();
      auto data = init->getAsString();
      std::string_view commands_view(data.data(), data.size());
      ret &= ParseBinaryJSONCommands(file_name.str(), commands_view);
    }
  }
  return ret;
}

// Parse compile commands data from an LLVM IR object file containing one or
// more modules.
bool Parser::ParseIR(llvm::object::IRObjectFile *ir) {
  auto ret = false;
  for (const llvm::Module &module : ir->modules()) {
    ret &= ParseModule(module);
  }
  return ret;
}

// Parse all targets contained within this universal binary.
//
// TODO(pag): Should we provide a command-line option or interactivity to
//            ask if only one of these objects should be "in scope"?
bool Parser::ParseUB(llvm::object::MachOUniversalBinary *ub) {
  auto ret = true;
  using ObjectForArch = llvm::object::MachOUniversalBinary::ObjectForArch;
  for (const ObjectForArch &object : ub->objects()) {
    auto archive = object.getAsArchive();
    auto object_file = object.getAsObjectFile();
    if (!archive && !object_file) {
      LOG(ERROR)
          << "Non-archive, non-object file at offset 0x"
          << std::hex << object.getOffset() << std::dec
          << " of " << ub->getFileName();
      ret = false;

    } else if (!object_file) {
      ret &= ParseArchive(archive.get().get());
    } else {
      ret &= ParseObject(object_file.get().get());
    }
  }
  return ret;
}

// Parse a binary.
bool Parser::ParseBinary(llvm::object::Binary *bin) {
  const llvm::StringRef file_name = bin->getFileName();
  LOG(INFO) << "Parsing binary " << file_name;

  if (auto ub = llvm::dyn_cast<llvm::object::MachOUniversalBinary>(bin)) {
    LOG(INFO) << file_name << " is a Mach-O Universal Binary";
    return ParseUB(ub);

  } else if (auto archive = llvm::dyn_cast<llvm::object::Archive>(bin)) {
    LOG(INFO) << file_name << " is an archive";
    return ParseArchive(archive);

  } else if (llvm::isa<llvm::object::COFFImportFile>(bin)) {
    LOG(WARNING) << "Ignoring COFF import file " << file_name;
    return true;

  } else if (auto ir = llvm::dyn_cast<llvm::object::IRObjectFile>(bin)) {
    LOG(INFO) << file_name << " is an LLVM IR file";
    return ParseIR(ir);

  // This handles ELF, Mach-O, and COFF object files.
  } else if (auto object = llvm::dyn_cast<llvm::object::ObjectFile>(bin)) {
    LOG(INFO) << file_name << " is an object file";
    return ParseObject(object);

  } else if (bin->isWinRes()) {
    LOG(WARNING) << "Ignoring Windows resource file " << file_name;
    return true;

  } else {
    LOG(ERROR) << "Binary type of " << file_name << " is not supported";
    return false;
  }
}

// Parse a compile command as embedded in a binary.
bool Parser::ParseBinaryJSONCommands(std::string_view file_name,
                                           std::string_view data) {
  bool ret = true;
  for (auto command_ : SplitCompileCommands(data)) {
    auto command = SanitizeJsonString(command_, "{", "}");
    auto maybe_json = llvm::json::parse(command);
    if (llvm::errorToBool(maybe_json.takeError())) {
      LOG(ERROR)
           << "Unable to parse split and sanitized compile commands from object file "
           << file_name;
      ret = false;
      continue;
    }

    ret &= ParseBinaryJSONCommand(*maybe_json);
  }
  return ret;
}

// Parse a compile command as embedded in a binary.
bool Parser::ParseBinaryJSONCommand(llvm::json::Value &json) {
  if (auto obj = json.getAsObject()) {
    return importer.ImportBlightCompileCommand(*obj);
  } else {
    return false;
  }
}

// Parse a `compile_commands.json`-type file.
bool Parser::ParseCompileCommandsJSON(std::string_view file_name,
                                      llvm::json::Value &json,
                                      const EnvVariableMap &envp) {
  auto arr = json.getAsArray();
  if (!arr) {
    DLOG(ERROR)
        << "JSON object in " << file_name << " is not an array of objects";
    return false;
  }

  auto ret = true;
  for (llvm::json::Value &val : *arr) {
    llvm::json::Object *obj = val.getAsObject();
    if (!obj) {
      DLOG(ERROR)
          << "Entry in top-level array of JSON file " << file_name
          << " is not an object";
      ret = false;
      continue;
    }

    if (obj->getString("wrapped_tool")) {
      ret &= importer.ImportBlightCompileCommand(*obj);
    } else {
      ret &= importer.ImportCMakeCompileCommand(*obj, envp);
    }
  }

  return ret;
}

// Parse a memory buffer as a binary/object of some form.
bool Parser::Parse(const llvm::MemoryBuffer &buff, const EnvVariableMap &envp) {
  auto file_name = buff.getBufferIdentifier().str();
  LOG(INFO) << "Parsing buffer " << file_name;

  auto maybe_json = llvm::json::parse(buff.getBuffer());
  if (!llvm::errorToBool(maybe_json.takeError())) {
    LOG(INFO) << "Buffer is JSON; parsing commands";
    return ParseCompileCommandsJSON(file_name, *maybe_json, envp);
  }

  auto maybe_bin = llvm::object::createBinary(buff, &context);
  if (!llvm::errorToBool(maybe_bin.takeError())) {
    LOG(INFO) << "Buffer is a binary; parsing sections";
    return ParseBinary(maybe_bin.get().get());
  }

  LOG(ERROR)
      << "Unable to parse " << file_name << " as either JSON or a binary.";
  return false;
}

}  // namespace indexer
