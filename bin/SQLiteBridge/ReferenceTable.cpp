// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <cassert>
#include <optional>
#include <variant>

#include "Tables.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {

ReferenceTable::ReferenceTable(mx::EntityProvider::Ptr ep)
    : ep(ep), index(ep) {}

constexpr const char *schema = R"cpp(
CREATE TABLE vtable(
    use_id INTEGER NOT NULL,
    user_id INTEGER NOT NULL,
    PRIMARY KEY (use_id, user_id)) WITHOUT ROWID
)cpp";

std::optional<std::string> ReferenceTable::Init(sqlite3 *db) {
  int err = sqlite3_declare_vtab(db, schema);
  if (err != SQLITE_OK) {
    return sqlite3_errmsg(db);
  }

  return std::nullopt;
}

int ReferenceTable::BestIndex(sqlite3_index_info *info) {
  for (int i = 0; i < info->nConstraint; i++) {
    auto constraint = info->aConstraint[i];
    if (constraint.usable && constraint.iColumn == 0 &&
        constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
      info->aConstraintUsage[i].argvIndex = 1;
      info->estimatedCost = 1;
      info->idxNum = 1;
      return SQLITE_OK;
    }
  }
  return SQLITE_OK;
}

class ReferenceCursor : public VirtualTableCursor {
private:
  mx::Index index;
  mx::EntityId use;
  std::vector<mx::Reference> references;
  decltype(references)::iterator cur;

public:
  ReferenceCursor(mx::EntityProvider::Ptr ep) : index(ep) {}

  virtual ~ReferenceCursor() = default;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    references.clear();
    if (idxNum) {
      use = mx::EntityId(sqlite3_value_int64(args[0]));
      auto entity{index.entity(use)};
      if (std::holds_alternative<mx::Decl>(entity)) {
        for (auto ref : std::get<mx::Decl>(entity).references()) {
          references.push_back(ref);
        }
      }
    }
    cur = references.begin();
    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == references.end(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    case 0:
      sqlite3_result_int64(ctx, use);
      return SQLITE_OK;
    case 1: {
      sqlite3_result_int64(ctx, cur->statement().id());
      return SQLITE_OK;
    }
    default:
      return SQLITE_ERROR;
    }
  }

  virtual mx::Result<std::int64_t, int> RowId() override { return 0; }
};

using Result = mx::Result<std::unique_ptr<VirtualTableCursor>, int>;

Result ReferenceTable::Open() {
  auto cursor{std::make_unique<ReferenceCursor>(ep)};
  return Result(std::move(cursor));
}
} // namespace sqlite_bridge