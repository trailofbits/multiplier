// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

#include <array>
#include <cstdint>
#include <filesystem>
#include <optional>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <flatbuffers/flatbuffers.h>
#include <drlojekyll/Runtime/Runtime.h>

namespace mx {

inline std::string source_path_bf(const hyde::rt::Bytes &bytes) {
  auto command = flatbuffers::GetRoot<CompileCommand>(bytes.data());
  return command->SourcePath()->str();
}

inline std::string parent_path_bf(const std::string &path_) {
  return std::filesystem::path(path_).parent_path().generic_string();
}

}  // namespace mx
