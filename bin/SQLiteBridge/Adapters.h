// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include "VirtualTableCursor.h"
#include <iostream>
#include <sqlite3ext.h>
#include <type_traits>
#include <vector>

namespace sqlite_bridge {
template <typename T> struct TypeAdapter;

template <typename TCollection,
          typename TIterator = typename TCollection::iterator,
          typename TValue = typename TCollection::value_type,
          typename Adapter = TypeAdapter<TValue>>
class CollectionAdapter : public VirtualTableCursor {
  TCollection coll;
  TIterator cur;
  Adapter adapter;

public:
  CollectionAdapter(const TCollection &c, Adapter adapter = Adapter())
      : coll(c), cur(coll.begin()), adapter(adapter) {}

  virtual ~CollectionAdapter() = default;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    cur = coll.begin();
    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == coll.end(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    return adapter.GetColumn(*cur, ctx, idxCol);
  }

  virtual mx::Result<std::int64_t, int> RowId() override {
    return adapter.GetRowId(*cur);
  }
};
} // namespace sqlite_bridge