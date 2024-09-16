// Copyright (c) 2021-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <ostream>
#include <string>
#include <string_view>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wshadow"
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/raw_ostream.h>
#pragma GCC diagnostic pop

inline static std::ostream &operator<<(std::ostream &os, llvm::Error val) {
  std::string out;
  llvm::raw_string_ostream ss(out);
  ss << val;
  ss.flush();
  os << out;
  return os;
}

inline static std::ostream &operator<<(std::ostream &os, llvm::StringRef val) {
  std::string_view out(val.data(), val.size());
  os << out;
  return os;
}
