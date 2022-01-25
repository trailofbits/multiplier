// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <pasta/Util/FileManager.h>
#include <pasta/Util/FileSystem.h>

namespace mx {
class DatalogClient;  // Auto-generated from Datalog.
}  // namespace mx
namespace indexer {

class Context {
 private:
  Context(void) = delete;

 public:
  const mx::DatalogClient &client;
  const pasta::FileManager file_manager;

  inline Context(const mx::DatalogClient &client_)
      : client(client_),
        file_manager(pasta::FileSystem::CreateNative()) {}
};

}  // namespace indexer
