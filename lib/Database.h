// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Tool.h>
#include <multiplier/Types.h>

#include <drlojekyll/Runtime/Bytes.h>
#include <drlojekyll/Runtime/Reference.h>
#include <drlojekyll/Runtime/StdRuntime.h>
#include <drlojekyll/Runtime/StdStorage.h>

#include <array>
#include <atomic>
#include <map>
#include <mutex>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace mx {

class Database {
 public:
  // Locks read/write access to all members in here.
  std::mutex lock;

  Database(void);
};

class DatabaseTool final : public Tool {
 public:
  std::shared_ptr<Database> db;

 private:

  void ApplyChanges(void);

 public:

  // Initialize the function manager tool by getting a list of all functions.
  DatabaseTool(const Executor &executor_, const DatalogClient &client_);

  // Return tool name.
  const char *Name(void) const final;

  // Each time new sections are added or removed, update the memory manager's
  // internal database.
  void Update(DatalogClientMessagePtr update) final;

  // Tear down this tool.
  void Stop(void) final;
};

}  // namespace mx
