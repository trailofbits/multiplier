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
  if (args.size() != 6) {
    return ResultType("Exactly 3 arguments expected: table, host, port.");
  }

  std::string table{args[3]};
  std::string host{args[4]};
  std::string port{args[5]};

  auto ep{mx::EntityProvider::from_remote(host, port)};
  std::unique_ptr<VirtualTable> vtab;
  if (table == "File") {
    vtab = std::make_unique<FileTable>(ep);
  } else if (table == "Fragment") {
    vtab = std::make_unique<FragmentTable>(ep);
  }

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  else if (table == #NAME) {                                                   \
    vtab = std::make_unique<NAME##Table>(ep);                                  \
  }
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_VISIT_BOOL_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_INT_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,     \
                          ...)                                                 \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_ENUM_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_TEXT_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_ENTITY_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,  \
                             ...)                                              \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_OPTIONAL_BOOL_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, \
                                    NAME, ...)                                 \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_OPTIONAL_INT_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3,  \
                                   NAME, ...)                                  \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_OPTIONAL_ENUM_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, \
                                    NAME, ...)                                 \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_OPTIONAL_TEXT_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, \
                                    NAME, ...)                                 \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#define MX_VISIT_OPTIONAL_ENTITY_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2,        \
                                      IGNORE3, NAME, ...)                      \
  MX_BEGIN_VISIT_DECL(TABLE##NAME)
#include <multiplier/Visitor.inc.h>

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