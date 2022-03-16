// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>

namespace mx {

using FileId = uint64_t;
using CodeId = uint64_t;

enum class EntityKind : uint16_t {
  kDeclaration,
  kStatement,
  kType,
  kCodeToken,
  kFileToken
};

static constexpr uint64_t kMinEntityIdIncrement = 1u;

struct EntityId {
  // The ID of the entity. This can be a `FileId` or a `CodeId`.
  uint64_t id;

  // The "offset" of this entity.
  //
  //    Declarations, Statements:
  //        The index into one of the lists in a serialized `ast::EntityList`
  //        inside of an `rpc::Code`. The entity lists are specific to
  //        `sub_kind`.
  //
  //    Types:
  //        TODO(pag): The qualifiers of the type.
  //
  //    Files:
  //        TODO(pag): The size of the file, in bytes.
  //
  //    File tokens:
  //        TODO(pag): Index of the token in the file.
  //
  //    Code tokens:
  //        TODO(pag): Index of the token inside of the code chunk.
  uint32_t offset;

  // What kind of entity is this?
  EntityKind kind;

  // The "sub_kind" of this entity.
  //
  //    Declarations:
  //        Encodes a `mx::DeclKind`.
  //
  //    Statements:
  //        Encodes a `mx::StmtKind`.
  //
  //    Types:
  //        Encodes a `mx::TypeKind`.
  //
  //    File:
  //        N/A
  //
  //    File tokens, code tokens:
  //        Encodes a `mx::TokenKind`.
  uint16_t sub_kind;
};

}  // namespace mx
