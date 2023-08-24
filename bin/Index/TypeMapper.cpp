// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TypeMapper.h"

#include <sstream>

#include <multiplier/Database.h>

#include "EntityMapper.h"
#include "PASTA.h"

namespace indexer {

// Hash a type.
std::string TypeMapper::HashType(
    const EntityMapper &em, const pasta::Type &type,
    const pasta::PrintedTokenRange &range) {

  decls.clear();

  std::stringstream ss;
  ss << 'k' << static_cast<int>(type.Kind())
     << 'q' << type.RawQualifiers();

  pasta::Type canonical_type = type.CanonicalType();
  if (canonical_type.IsBuiltinType() || canonical_type.IsPointerType()) {
    if (auto size = canonical_type.SizeInBits()) {
      ss << 's' << size.value();
    }
    if (auto align = canonical_type.Alignment()) {
      ss << 'a' << align.value();
    }
  }

  // Integrate the printed tokens, while also opaquely keeping track of
  // the declarations which we've come across.
  unsigned i = 0u;
  ss << 't';
  const void *last_decl = nullptr;
  for (pasta::PrintedToken tok : range) {
    ss << ' ' << tok.Data();

    for (std::optional<pasta::TokenContext> c = tok.Context();
         c; c = c->Parent()) {
      if (c->Kind() == pasta::TokenContextKind::kDecl) {
        if (const void *decl = c->Data(); decl != last_decl) {
          decls.emplace_back(decl, i++);
          last_decl = decl;
        }

        // We only care about the shallowest decl in the context chain; anything
        // deeper (i.e. closer to the root of the AST) will end up being present
        // somewhere in `decls`.
        break;
      }
    }
  }

  // Now go and unique the decls and convert them to entity IDs, preserving
  // their original order.
  if (!decls.empty()) {
    std::stable_sort(decls.begin(), decls.end(),
                     [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                       return a.first < b.first;
                     });

    auto it = std::unique(decls.begin(), decls.end(),
                          [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                            return a.first == b.first;
                          });

    decls.erase(it, decls.end());

    std::sort(decls.begin(), decls.end(),
              [] (OpaqueOrderedDecl a, OpaqueOrderedDecl b) {
                return a.second < b.second;
              });

    ss << " d";
    for (OpaqueOrderedDecl od : decls) {
      auto eid = em.EntityId(od.first);
      assert(eid != mx::kInvalidEntityId);
      ss << ' ' << eid;
    }
  }

  return ss.str();
}

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

bool TypeMapper::AddEntityId(const EntityMapper &em,
                             const pasta::Type &entity) {
  assert(!read_only);

  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  assert(type_key.first != nullptr);

  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return false;
  }

  bool is_new_type_id = false;
  auto token_range = pasta::PrintedTokenRange::Create(entity);

  mx::PackedTypeId tid = database.GetOrCreateTypeIdForHash(
      mx::FromPasta(entity.Kind()), entity.RawQualifiers(),
      HashType(em, entity, token_range), token_range.size(),
      is_new_type_id).Unpack();

  type_ids.emplace(type_key, tid);

  if (!is_new_type_id) {
    return false;
  }

  types_token_range.emplace(type_key, std::move(token_range));
  return true;
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
  if (auto it = types_token_range.find(type_key);
      it != types_token_range.end()) {
    return it->second;
  }

  assert(false);
  return std::nullopt;
}

} // namespace
