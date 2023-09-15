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

namespace clang {
class ASTContext;
class QualType;
class Type;
}  // namespace clang

namespace mx {
class DatabaseWriter;
} // namespace mx

namespace indexer {

// This printing policy aims to maximize our ability to deduplicate types.
class TypePrintingPolicy final : public pasta::PrintingPolicy {
 public:
  virtual ~TypePrintingPolicy(void);
  bool ShouldPrintTagBodies(void) const final;
  bool ShouldPrintConstantExpressionsInTypes(void) const final;
  bool ShouldPrintOriginalTypeOfAdjustedType(void) const final;
  bool ShouldPrintOriginalTypeOfDecayedType(void) const final;
};

// The type mapper manages type deduplicating and compression. Clang, as well
// as our Clang patches, will generate a lot of types. From a program analysis
// point of view we don't actually care about knowing that something is an
// `auto` type or a `decltype`, what we care about is what the underlying/
// deduced/inferred type is. From a visual perspective, we don't want to over-
// eagerly walk through `typedef`s though, as they have semantically meaningful
// names. The type mapper plays this balancing act of taking in `pasta::Type`s
// and mangling them a bit to hopefully reduce the scope of the number of types
// saved to the database, while also improving our chances of deduplicating
// types. A key component to type deduplication is to bootstrap off of fragment-
// granularity declaration-based deduplication. That is, we mix in the entity
// IDs of declarations referenced by types into hashing process when doing our
// type deduplication.
class TypeMapper final {
 private:
  // When hashing a type, we come across declarations. We keep track of them
  // here, allowing ourselves to reuse the backing storage.
  using OpaqueOrderedDecl = std::pair<const void *, unsigned>;
  std::vector<OpaqueOrderedDecl> decls;

  // Hash a type, producing a string.
  std::string HashType(
      const EntityMapper &em, const pasta::Type &type,
      const pasta::PrintedTokenRange &range);

 public:
  TypeIdMap type_ids;

  mx::DatabaseWriter &database;

  bool read_only{false};

  inline explicit TypeMapper(mx::DatabaseWriter &database_)
      : database(database_) {
    decls.reserve(64);
  }

  inline void EnterReadOnly(void) {
    read_only = true;
  }

  inline void ExitReadOnly(void) {
    read_only = false;
  }

  mx::RawEntityId EntityId(const void *type, uint32_t quals=0u) const;
  mx::RawEntityId EntityId(const pasta::Type &entity) const;

  // NOTE(pag): `*entity` may be updated.
  bool AddEntityId(const EntityMapper &em, pasta::Type *entity);

  mx::PackedTypeId TypeId(const pasta::Type &entity) const;

  static clang::QualType Compress(clang::ASTContext &,
                                  const clang::QualType &type);
  static clang::QualType Compress(clang::ASTContext &, const clang::Type *type);
};

}  // namespace indexer

