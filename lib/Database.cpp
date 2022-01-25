// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.


#include "Database.h"

#include <glog/logging.h>

#include <set>
#include <unordered_set>
#include <vector>

#include <glog/logging.h>

namespace mx {

Database::Database(void) {}

// Initialize the function manager tool by getting a list of all functions.
DatabaseTool::DatabaseTool(const Executor &executor_,
                           const DatalogClient &client_)
    : Tool(executor_, client_),
      db(std::make_shared<Database>()) {

  ApplyChanges();
}

// Return tool name.
const char *DatabaseTool::Name(void) const {
  return "mx:database";
}

// Tear down this tool.
void DatabaseTool::Stop(void) {
  db.reset();
}

void DatabaseTool::ApplyChanges(void) {
  std::unique_lock<std::mutex> locker(db->lock);

}

// Each time new sections are added or removed, update the memory manager's
// internal database.
void DatabaseTool::Update(DatalogClientMessagePtr update) {

  ApplyChanges();
}

}  // namespace mx
