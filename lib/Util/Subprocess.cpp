// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Subprocess.h>

#include <gflags/gflags.h>

#include <reproc++/drain.hpp>
#include <reproc++/reproc.hpp>
#include <sstream>

namespace mx {

// Execute the command specified in `args` with the ability to feed the
// command input and capture output. Passing `nullptr` to any of `input`,
// `output`, or `error` is acceptable.
Result<int, std::error_code> Subprocess::Execute(
    const std::vector<std::string> &cmd,
    const std::unordered_map<std::string, std::string> *env,
    std::string *input, std::string *output, std::string *error) {

  reproc::process process;
  reproc::arguments args(cmd);
  reproc::options options;
  options.env.behavior = reproc::env::empty;
  if (env) {
    options.env.extra = reproc::env(*env);
  }

  if (input) {
    options.redirect.in.type = reproc::redirect::pipe;
  }
  if (output) {
    options.redirect.out.type = reproc::redirect::pipe;
  } else {
    options.redirect.out.type = reproc::redirect::discard;
  }
  if (error) {
    options.redirect.err.type = reproc::redirect::pipe;
  } else {
    options.redirect.err.type = reproc::redirect::discard;
  }

  std::error_code ec = process.start(args, options);
  if (ec) {
    return ec;
  }

  // Write input to the child process.
  if (input && !input->empty()) {
    size_t next_i = 0u;
    auto data = reinterpret_cast<const uint8_t *>(input->data());
    for (auto max_i = input->size(); next_i < max_i; ) {
      auto [num_written_bytes, write_ec] = process.write(
          &(data[next_i]), max_i - next_i);
      if (write_ec) {
        return write_ec;
      } else {
        next_i += num_written_bytes;
      }
    }
  }

  // Drain output from the child process.
  if (output && error) {
    reproc::sink::string stdout_sink(*output);
    reproc::sink::string stderr_sink(*error);
    ec = reproc::drain(process, stdout_sink, stderr_sink);
    if (ec) {
      return ec;
    }
  } else if (output) {
    reproc::sink::string stdout_sink(*output);
    ec = reproc::drain(process, stdout_sink, reproc::sink::null);
    if (ec) {
      return ec;
    }
  } else if (error) {
    reproc::sink::string stderr_sink(*error);
    ec = reproc::drain(process, reproc::sink::null, stderr_sink);
    if (ec) {
      return ec;
    }
  }

  // Wait for completion.
  int status = 0;
  std::tie(status, ec) = process.wait(reproc::infinite);
  if (ec) {
    return ec;
  }

  return status;
}

}  // namespace mx
