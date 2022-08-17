// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "PendingFragment.h"

namespace pasta {
class File;
}  // namespace pasta
namespace indexer {

class TokenTree;
class TokenTreeNode;

// Provides entity IDs and offsets to the serialization code.
class EntityMapper final {
 public:
  EntityIdMap &entity_ids;

  // Offsets of the serialized version of types in this fragment.
  //
  // NOTE(pag): Types are redundantly represented in/across fragments; no
  //            de-duplication is done.
  //
  // TODO(pag): Eventually split PASTA's `Type` back into a `QualType` and
  //            a `Type`?
  TypeIdMap &type_ids;

  // These are "fresh" for each instance of the entity mapper, because we
  // create different token trees per fragment, though they may occupy the
  // same memory locations.
  EntityIdMap token_tree_ids;

  const PendingFragment &fragment;

  inline explicit EntityMapper(
      EntityIdMap &entity_ids_, TypeIdMap &type_ids_,
      const PendingFragment &fragment_)
      : entity_ids(entity_ids_),
        type_ids(type_ids_),
        token_tree_ids(entity_ids_),
        fragment(fragment_) {}

  mx::RawEntityId ParentDeclId(const pasta::Decl &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::Stmt &entity) const;
  mx::RawEntityId ParentStmtId(const pasta::Decl &entity) const;
  mx::RawEntityId ParentStmtId(const pasta::Stmt &entity) const;
  mx::RawEntityId EntityId(const void *entity) const;
  mx::RawEntityId EntityId(const pasta::File &file) const;
  mx::RawEntityId EntityId(const pasta::Decl &entity) const;
  mx::RawEntityId EntityId(const pasta::Stmt &entity) const;
  mx::RawEntityId EntityId(const pasta::Token &entity) const;
  mx::RawEntityId EntityId(const pasta::FileToken &entity) const;
  mx::RawEntityId EntityId(const pasta::MacroToken &entity);
  mx::RawEntityId EntityId(const pasta::Type &entity) const;
  mx::RawEntityId EntityId(const pasta::Attr &entity) const;
  mx::RawEntityId EntityId(const pasta::Macro &entity) const;

  mx::RawEntityId EntityIdOfType(const void *type, uint32_t quals=0u) const;

  uint32_t PseudoId(const pasta::TemplateArgument &pseudo) const;
  uint32_t PseudoId(const pasta::TemplateParameterList &pseudo) const;
  uint32_t PseudoId(const pasta::CXXBaseSpecifier &pseudo) const;
  uint32_t PseudoId(const pasta::Designator &pseudo) const;
};

}  // namespace indexer
