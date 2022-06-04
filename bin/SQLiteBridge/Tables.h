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

#define MX_VISIT_BOOL_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  class TABLE##NAME##Table : public VirtualTable {                             \
  private:                                                                     \
    mx::EntityProvider::Ptr ep;                                                \
    mx::Index index;                                                           \
                                                                               \
  public:                                                                      \
    TABLE##NAME##Table(mx::EntityProvider::Ptr ep);                            \
    virtual ~TABLE##NAME##Table() = default;                                   \
    virtual std::optional<std::string> Init(sqlite3 *db) override;             \
    virtual int BestIndex(sqlite3_index_info *info) override;                  \
    virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int>               \
    Open() override;                                                           \
  };
#define MX_VISIT_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_TEXT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_ENTITY_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_BOOL_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_TEXT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_ENTITY_LIST MX_VISIT_BOOL_LIST
#include <multiplier/Visitor.inc.h>

} // namespace sqlite_bridge