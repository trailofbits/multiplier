// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Storage.h"

#include <glog/logging.h>
#include <multiplier/Types.h>
#include <optional>
#include <string>

#include <drlojekyll/Runtime/Runtime.h>

namespace mx {

// NOTE(pag): The `DatabaseFunctors` template is defined in the auto-generated
//            `mx.db.h`, and `Server/functors.dr` uses an `#inline` statement
//            to place an `#include` of this file into `mx.db.h`, after
//            `DatabaseFunctors` has been declared.
template <>
class DatabaseFunctors<hyde::rt::StdStorage> {
 private:
  Storage storage;
 public:

  // Allocate `reserve_size` file IDs, where we expect the last allocated
  // reservation to end at `last_id`.
  std::optional<FileId> allocate_file_ids_bbf(int64_t, uint32_t reserve_size) {
    auto ret = storage.ReserveFileIds(reserve_size);
    if (ret.Succeeded()) {
      return ret.TakeValue();
    } else {
      LOG(ERROR) << ret.TakeError();
      return std::nullopt;
    }
  }

  // Persist a file by adding it to the bulk inserter thread.
  bool persist_file_bbb(FileId id, std::string path, ::hyde::rt::Bytes tokens) {
    File file;
    file.id = id;
    file.path = std::move(path);
    file.tokens = std::move(tokens);
    storage.StoreFile(std::move(file));
    return true;
  }

  std::vector<std::tuple<FileId, std::string>> list_file_ids_bff(int64_t) {
    return {};
  }

//  inline static std::string source_path_bf(const hyde::rt::Bytes &bytes) {
//    auto command = flatbuffers::GetRoot<CompileCommand>(bytes.data());
//    return command->SourcePath()->str();
//  }
//
//  inline static std::string parent_path_bf(const std::string &path_) {
//    return std::filesystem::path(path_).parent_path().generic_string();
//  }
};

}  // namespace mx
