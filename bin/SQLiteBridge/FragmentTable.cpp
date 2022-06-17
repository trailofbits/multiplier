// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <cassert>
#include <multiplier/File.h>
#include <multiplier/Types.h>
#include <multiplier/Use.h>
#include <optional>

#include "Tables.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {

FragmentTable::FragmentTable(mx::EntityProvider::Ptr ep) : ep(ep), index(ep) {}

constexpr const char *schema = R"cpp(
CREATE TABLE vtable(
    id INTEGER NOT NULL,
    file_id INTEGER NOT NULL,
    PRIMARY KEY (id))
)cpp";

enum class ConstraintType : int { None, FragmentId, FileId };

std::optional<std::string> FragmentTable::Init(sqlite3 *db) {
  int err = sqlite3_declare_vtab(db, schema);
  if (err != SQLITE_OK) {
    return sqlite3_errmsg(db);
  }

  return std::nullopt;
}

int FragmentTable::BestIndex(sqlite3_index_info *info) {
  for (int i = 0; i < info->nConstraint; i++) {
    auto constraint = info->aConstraint[i];
    if (constraint.usable && constraint.iColumn == 0 &&
        constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
      info->aConstraintUsage[i].argvIndex = 1;
      info->estimatedCost = 1;
      info->idxNum = static_cast<int>(ConstraintType::FragmentId);
      return SQLITE_OK;
    }

    if (constraint.usable && constraint.iColumn == 1 &&
        constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
      info->aConstraintUsage[i].argvIndex = 1;
      info->estimatedCost = 1;
      info->idxNum = static_cast<int>(ConstraintType::FileId);
      return SQLITE_OK;
    }
  }
  info->idxNum = static_cast<int>(ConstraintType::None);

  return SQLITE_OK;
}

class FragmentCursor : public VirtualTableCursor {
private:
  mx::Index index;
  std::vector<mx::FragmentId> fragments;
  decltype(fragments)::iterator cur;

public:
  FragmentCursor(mx::EntityProvider::Ptr ep) : index(ep) {}

  virtual ~FragmentCursor() = default;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    fragments.clear();
    auto constraint{static_cast<ConstraintType>(idxNum)};
    if (constraint == ConstraintType::FragmentId) {
      auto fragment{index.fragment({static_cast<uint64_t>(sqlite3_value_int64(args[0]))})};
      if (fragment) {
        fragments.push_back(fragment->id());
      }
    } else if (constraint == ConstraintType::FileId) {
      auto file{index.file({static_cast<uint64_t>(sqlite3_value_int64(args[0]))})};
      if (file) {
        for (auto fragment : mx::Fragment::in(*file)) {
          fragments.push_back(fragment.id());
        }
      }
    } else {
      for (auto file : mx::File::in(index)) {
        for (auto fragment : mx::Fragment::in(file)) {
          fragments.push_back(fragment.id());
        }
      }
    }
    cur = fragments.begin();
    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == fragments.end(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    case 0:
      sqlite3_result_int64(ctx, *cur);
      return SQLITE_OK;
    case 1: {
      auto fragment{index.fragment(*cur)};
      assert(fragment.has_value());
      auto file{mx::File::containing(*fragment)};
      sqlite3_result_int64(ctx, file.id());
      return SQLITE_OK;
    }
    default:
      return SQLITE_ERROR;
    }
  }

  virtual mx::Result<std::int64_t, int> RowId() override {
    return static_cast<std::int64_t>(*cur);
  }
};

using Result = mx::Result<std::unique_ptr<VirtualTableCursor>, int>;

Result FragmentTable::Open() {
  auto cursor{std::make_unique<FragmentCursor>(ep)};
  return Result(std::move(cursor));
}
} // namespace sqlite_bridge