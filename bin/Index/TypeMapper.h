// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

#include "Entity.h"
#include "Util.h"

namespace mx {
class DatabaseWriter;
} // namespace mx

namespace indexer {

class TypeMapper final {
 public:
  TypeIdMap type_ids;

  mx::DatabaseWriter &database;

  inline explicit TypeMapper(mx::DatabaseWriter &database_)
      : database(database_) {}

  mx::RawEntityId EntityId(const void *type, uint32_t quals=0u) const;
  mx::RawEntityId EntityId(const pasta::Type &entity) const;

  bool AddEntityId(const pasta::Type &entity);

  mx::PackedFragmentId
  GetOrCreateFragmentIdForType(const pasta::Type &type) const;

};

}  // namespace indexer

