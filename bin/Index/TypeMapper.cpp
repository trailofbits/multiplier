// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TypeMapper.h"

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
#pragma clang diagnostic pop

#include <multiplier/Database.h>

#include "PASTA.h"

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


mx::RawEntityId TypeMapper::EntityId(const void *type,
                                     uint32_t quals) const {
  TypeKey type_key(type, quals);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId TypeMapper::EntityId(const pasta::Type &entity) const {
  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

bool TypeMapper::AddEntityId(const pasta::Type &entity) {
  assert(!read_only);

  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  assert(type_key.first != nullptr);

  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return false;
  }

  bool is_new_type_id = false;
  auto token_range = pasta::PrintedTokenRange::Create(entity);
  mx::TypeId tid = GetOrCreateFragmentIdForType(
      entity, token_range, is_new_type_id).Unpack();
  assert(is_new_type_id);

  (void)types_token_range.emplace(type_key, std::move(token_range));
  return type_ids.emplace(type_key, tid).second;
}

mx::PackedTypeId TypeMapper::TypeId(const pasta::Type &type) const {
  mx::VariantId vid = mx::EntityId(this->EntityId(type)).Unpack();
  assert(std::holds_alternative<mx::TypeId>(vid));
  return std::get<mx::TypeId>(vid);
}

std::optional<pasta::PrintedTokenRange>
TypeMapper::TypeTokenRange(const pasta::Type &entity) const {
  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  assert(type_key.first != nullptr);
  if (auto it = types_token_range.find(type_key); it != types_token_range.end()) {
    return it->second;
  }

  assert(false);
  return std::nullopt;
}

mx::PackedTypeId TypeMapper::GetOrCreateFragmentIdForType(
    const pasta::Type &entity, const pasta::PrintedTokenRange &token_range,
    bool &is_new_type_id) const {
  auto type_id_ = database.GetOrCreateTypeIdForHash(
      mx::FromPasta(entity.Kind()), HashType(entity), token_range.size(),
      is_new_type_id);
  return type_id_;
}

} // namespace



