// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <pasta/AST/Printer.h>
#include <pasta/AST/Type.h>

#include <multiplier/Types.h>

#include "Entity.h"
#include "Util.h"

namespace mx {
class DatabaseWriter;
} // namespace mx

namespace indexer {

class TypeMapper final {
 private:
  using TypeTokenRangeMap = std::map<TypeKey, pasta::PrintedTokenRange>;
  using OpaqueOrderedDecl = std::pair<const void *, unsigned>;
  std::vector<OpaqueOrderedDecl> decls;
  TypeTokenRangeMap types_token_range;

  std::string HashType(
      const EntityMapper &em, const pasta::Type &type,
      const pasta::PrintedTokenRange &range);

 public:
  TypeIdMap type_ids;

  mx::DatabaseWriter &database;

  bool read_only{false};

  inline explicit TypeMapper(mx::DatabaseWriter &database_)
      : database(database_) {}

  inline void EnterReadOnly(void) {
    read_only = true;
  }

  inline void ExitReadOnly(void) {
    read_only = false;
  }

  mx::RawEntityId EntityId(const void *type, uint32_t quals=0u) const;
  mx::RawEntityId EntityId(const pasta::Type &entity) const;

  bool AddEntityId(const EntityMapper &em, const pasta::Type &entity);

  mx::PackedTypeId TypeId(const pasta::Type &entity) const;

  std::optional<pasta::PrintedTokenRange>
  TypeTokenRange(const pasta::Type &entity) const;
};

}  // namespace indexer

