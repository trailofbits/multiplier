// Copyright (c) 2019-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <string>
#include <system_error>
#include <unordered_map>
#include <variant>
#include <vector>

namespace indexer {

class Subprocess {
 public:

  // Execute the command specified in `args` with the ability to feed the
  // command input and capture output. Passing `nullptr` to any of `input`,
  // `output`, or `error` is acceptable.
  static std::variant<int, std::error_code> Execute(
      const std::vector<std::string> &args,
      const std::unordered_map<std::string, std::string> *env=nullptr,
      std::string *input=nullptr,
      std::string *output=nullptr,
      std::string *error=nullptr);
 private:
  static std::variant<int, std::error_code> ExecuteFork(
      const std::vector<std::string> &cmd,
      const std::unordered_map<std::string, std::string> *env,
      std::string *input, std::string *output, std::string *error);
  static bool IsRunningInDocker();
};

}  // namespace indexer
