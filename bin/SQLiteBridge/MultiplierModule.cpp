// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <multiplier/Index.h>

#include "MultiplierModule.h"
#include "Tables.h"
#include "VirtualTable.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {
using ResultType = mx::Result<std::unique_ptr<VirtualTable>, std::string>;

ResultType MultiplierModule::Create(sqlite3 *db,
                                    const std::vector<const char *> &args) {
  if (args.size() != 5) {
    return ResultType("Exactly 2 arguments expected: table, connection name.");
  }

  std::string table{args[3]};
  std::string connection{args[4]};

  auto ep{GetEntityProvider(connection)};
  if (!ep) {
    return ResultType("No connection found with name '" + connection + "'");
  }

  std::unique_ptr<VirtualTable> vtab;
  if (table == "File") {
    vtab = std::make_unique<FileTable>(*ep);
  } else if (table == "Fragment") {
    vtab = std::make_unique<FragmentTable>(*ep);
  } else if (table == "Reference") {
    vtab = std::make_unique<ReferenceTable>(*ep);
  } else if (table == "RegexQuery") {
    vtab = std::make_unique<QueryTable>(*ep, QueryType::Regex);
  } else if (table == "WeggliQuery") {
    vtab = std::make_unique<QueryTable>(*ep, QueryType::Weggli);
  }

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  else if (table == #NAME) {                                                   \
    vtab = std::make_unique<NAME##Table>(*ep);                                 \
  }
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>
  else {
    vtab = GetListTable(*ep, table);
  }

  if (!vtab) {
    return ResultType("Unknown Multiplier table: " + table);
  }

  auto err{vtab->Init(db)};
  if (err) {
    return ResultType(*err);
  }

  return ResultType(std::move(vtab));
}
} // namespace sqlite_bridge