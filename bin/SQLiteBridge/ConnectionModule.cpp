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
#include <algorithm>
#include <unordered_map>

namespace sqlite_bridge {

struct EntityProviderInfo {
  std::string name;
  std::string host;
  std::string port;
  mx::EntityProvider::Ptr ptr;
};

static std::unordered_map<std::string, EntityProviderInfo> entity_providers;

std::optional<mx::EntityProvider::Ptr>
GetEntityProvider(const std::string &name) {
  auto it{entity_providers.find(name)};
  if (it == entity_providers.end()) {
    return std::nullopt;
  }
  return it->second.ptr;
}

class ConnectionCursor : public VirtualTableCursor {
  std::vector<EntityProviderInfo> providers;
  size_t cur;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    providers.clear();
    cur = 0;
    for (auto info : entity_providers) {
      providers.push_back(info.second);
    }

    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == providers.size(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    auto &provider{providers[cur]};
    switch (idxCol) {
    case 0:
      sqlite3_result_text(ctx, provider.name.data(), provider.name.size(),
                          SQLITE_TRANSIENT);
      return SQLITE_OK;
    case 1:
      sqlite3_result_text(ctx, provider.host.data(), provider.host.size(),
                          SQLITE_TRANSIENT);
      return SQLITE_OK;
    case 2:
      sqlite3_result_text(ctx, provider.port.data(), provider.port.size(),
                          SQLITE_TRANSIENT);
      return SQLITE_OK;
    default:
      return SQLITE_ERROR;
    }
  }

  virtual mx::Result<std::int64_t, int> RowId() override {
    return std::int64_t(0);
  }
};

class ConnectionTable : public VirtualTable {
public:
  virtual std::optional<std::string> Init(sqlite3 *db) override {
    int err = sqlite3_declare_vtab(
        db, "CREATE TABLE vtab(name TEXT NOT NULL, host TEXT NOT NULL, port "
            "NOT NULL, PRIMARY KEY(name)) WITHOUT ROWID");
    if (err != SQLITE_OK) {
      return sqlite3_errmsg(db);
    }

    return std::nullopt;
  }

  virtual int BestIndex(sqlite3_index_info *info) override {
    // We just return all available connections and let SQLite sort it out. The
    // total number of connections in any given session should be very low, so I
    // don't foresee performance problems with this approach -- frabert
    return SQLITE_OK;
  }

  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override {
    auto ptr{std::make_unique<ConnectionCursor>()};
    return mx::Result<std::unique_ptr<VirtualTableCursor>, int>(std::move(ptr));
  }

  virtual int Update(const std::vector<sqlite3_value *> &args,
                     sqlite3_int64 *row_id) override {
    if (args.size() == 1) {
      // Delete query
      auto c_str{reinterpret_cast<const char *>(sqlite3_value_text(args[0]))};
      if (!c_str) {
        return SQLITE_CONSTRAINT_NOTNULL;
      }
      entity_providers.erase(c_str);
      return SQLITE_OK;
    }

    auto arg0_type{sqlite3_value_type(args[0])};
    auto old_rowid_str{
        reinterpret_cast<const char *>(sqlite3_value_text(args[0]))};
    auto new_rowid_str{
        reinterpret_cast<const char *>(sqlite3_value_text(args[1]))};
    auto name_str{reinterpret_cast<const char *>(sqlite3_value_text(args[2]))};
    auto host_str{reinterpret_cast<const char *>(sqlite3_value_text(args[3]))};
    auto port_str{reinterpret_cast<const char *>(sqlite3_value_text(args[4]))};

    if (!name_str || !host_str || !port_str) {
      return SQLITE_CONSTRAINT_NOTNULL;
    }

    auto ep{mx::EntityProvider::from_remote(host_str, port_str)};
    ep = mx::EntityProvider::in_memory_cache(ep);
    if (arg0_type == SQLITE_NULL) {
      // Insert query
      if (entity_providers.count(name_str)) {
        return SQLITE_CONSTRAINT_PRIMARYKEY;
      }
      entity_providers[name_str] = {name_str, host_str, port_str,
                                    std::move(ep)};
      return SQLITE_OK;
    }

    if (std::string(old_rowid_str) == std::string(new_rowid_str)) {
      // Update, no id change
      entity_providers[name_str].host = host_str;
      entity_providers[name_str].port = port_str;
      entity_providers[name_str].ptr = std::move(ep);
      return SQLITE_OK;
    }

    // Update, id change
    entity_providers.erase(old_rowid_str);
    entity_providers[name_str] = {name_str, host_str, port_str, std::move(ep)};
    return SQLITE_OK;
  }
};

using ResultType = mx::Result<std::unique_ptr<VirtualTable>, std::string>;
ResultType ConnectionModule::Create(sqlite3 *db,
                                    const std::vector<const char *> &args) {
  auto ptr{std::make_unique<ConnectionTable>()};
  if (auto res = ptr->Init(db)) {
    return ResultType(*res);
  }
  return ResultType(std::move(ptr));
}
} // namespace sqlite_bridge