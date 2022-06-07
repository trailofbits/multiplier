// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include "VirtualTable.h"
#include <multiplier/Index.h>
#include <multiplier/Use.h>

namespace sqlite_bridge {
class FileTable : public VirtualTable {
private:
  mx::Index index;

public:
  FileTable(mx::EntityProvider::Ptr ep);
  virtual ~FileTable() = default;
  virtual std::optional<std::string> Init(sqlite3 *db) override;
  virtual int BestIndex(sqlite3_index_info *info) override;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override;
};

class FragmentTable : public VirtualTable {
private:
  mx::EntityProvider::Ptr ep;
  mx::Index index;

public:
  FragmentTable(mx::EntityProvider::Ptr ep);
  virtual ~FragmentTable() = default;
  virtual std::optional<std::string> Init(sqlite3 *db) override;
  virtual int BestIndex(sqlite3_index_info *info) override;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override;
};

class ReferenceTable : public VirtualTable {
private:
  mx::EntityProvider::Ptr ep;
  mx::Index index;

public:
  ReferenceTable(mx::EntityProvider::Ptr ep);
  virtual ~ReferenceTable() = default;
  virtual std::optional<std::string> Init(sqlite3 *db) override;
  virtual int BestIndex(sqlite3_index_info *info) override;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override;
};

enum class QueryType { Regex, Weggli };

class QueryTable : public VirtualTable {
private:
  mx::EntityProvider::Ptr ep;
  mx::Index index;
  QueryType type;

public:
  QueryTable(mx::EntityProvider::Ptr ep, QueryType type);
  virtual ~QueryTable() = default;
  virtual std::optional<std::string> Init(sqlite3 *db) override;
  virtual int BestIndex(sqlite3_index_info *info) override;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override;
};

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  class NAME##Table : public VirtualTable {                                    \
  private:                                                                     \
    mx::EntityProvider::Ptr ep;                                                \
    mx::Index index;                                                           \
                                                                               \
  public:                                                                      \
    NAME##Table(mx::EntityProvider::Ptr ep);                                   \
    virtual ~NAME##Table() = default;                                          \
    virtual std::optional<std::string> Init(sqlite3 *db) override;             \
    virtual int BestIndex(sqlite3_index_info *info) override;                  \
    virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int>               \
    Open() override;                                                           \
  };
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

std::unique_ptr<VirtualTable> GetListTable(mx::EntityProvider::Ptr ep,
                                           const std::string &name);

} // namespace sqlite_bridge