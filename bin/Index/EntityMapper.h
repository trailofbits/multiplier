// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "PendingFragment.h"
#include "Entity.h"

namespace pasta {
class File;
}  // namespace pasta
namespace indexer {

class TokenTree;
class TokenTreeNode;
class TypeMapper;

// Provides entity IDs and offsets to the serialization code.
class EntityMapper final {
 public:
  EntityIdMap &entity_ids;

  // An instance of TypeMapper that will hold type_ids of the
  // new types encountered in a translation unit. It will be used
  // to create the type fragments for the types that are newly
  // encountered.
  TypeMapper &tm;

  // Note: Reset the token trees and parent ids before processing
  //       the pending fragments.

  // Token tree ids per fragment. It may occupy the same memory location
  // and should be reset before processing each fragment.
  EntityIdMap token_tree_ids;

  // Entity IDs for tracking parentage
  EntityIdMap parent_decl_ids;
  EntityIdMap parent_stmt_ids;

  inline explicit EntityMapper(EntityIdMap &entity_ids_, TypeMapper &tm_)
      : entity_ids(entity_ids_),
        tm(tm_), token_tree_ids(entity_ids_) {}

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
  mx::RawEntityId EntityId(const pasta::TemplateArgument &pseudo) const;
  mx::RawEntityId EntityId(const pasta::TemplateParameterList &pseudo) const;
  mx::RawEntityId EntityId(const pasta::CXXBaseSpecifier &pseudo) const;
  mx::RawEntityId EntityId(const pasta::Designator &pseudo) const;

  mx::RawEntityId EntityIdOfType(const void *type, uint32_t quals=0u) const;

  void ResetForFragment(void);
};

}  // namespace indexer
