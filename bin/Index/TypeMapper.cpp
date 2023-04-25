// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TypeMapper.h"

#include <pasta/AST/Printer.h>
#include <pasta/AST/Type.h>
#include <sstream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/ADT/FoldingSet.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/SHA256.h>
#pragma clang diagnostic pop

#include <multiplier/Database.h>

namespace indexer {

namespace {

// It creates the minimal hash from raw pointers and
// qualifiers. It will be extended to cover more generic
// cases.
static std::string HashType(const pasta::Type &type) {
  std::stringstream ss;
  llvm::FoldingSetNodeID fs;
  fs.AddInteger(type.RawQualifiers());
  fs.AddPointer(type.RawType());
  ss << fs.ComputeHash();
  return ss.str();
}

} // namespace


mx::RawEntityId
TypeMapper::EntityId(const void *type, uint32_t quals) const {
  TypeKey type_key(type, quals);
  assert(type_key.first != nullptr);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId
TypeMapper::EntityId(const pasta::Type &entity) const {
  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  assert(type_key.first != nullptr);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    assert(false);
    return mx::kInvalidEntityId;
  }
}

mx::PackedFragmentId
TypeMapper::GetOrCreateFragmentIdForType(const pasta::Type &type) {
  bool is_new_fragment_id;
  auto token_range = pasta::PrintedTokenRange::Create(type);
  auto fragment_id = database.GetOrCreateFragmentIdForHash(
      mx::kInvalidEntityId, HashType(type),
      token_range.size(), is_new_fragment_id);
  return fragment_id;
}

} // namespace



