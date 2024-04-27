// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Entity.h"
#include "PendingFragment.h"
#include "Util.h"

namespace pasta {
class File;
}  // namespace pasta
namespace indexer {

class TokenTree;
class TokenTreeNode;
class TypeMapper;

using NestedFragmentIntervals = interval_tree::IntervalTree<
    mx::EntityOffset, mx::PackedFragmentId>;

// Provides entity IDs and offsets to the serialization code.
class EntityMapper final {
 public:
  // Set of all top-level declarations (from the perspective of fragments).
  std::unordered_set<const void *> top_level_decls;

  // Locations of all fragments that are templates.
  NestedFragmentIntervals nested_fragment_bounds;

  // Globally (within a translation unit) entity ids. Generally, these are
  // things that can be referenced across fragments.
  EntityIdMap entity_ids;
  
  // Attributes that we've observed. Many attributes can be inherited, and so
  // they are actually copied/cloned from place-to-place. Ideally, we want to
  // only keep around the "original" or first version of an attribute.
  EntityIdMap attr_ids;
  EntityIdMap attr_token_ids;

  // Attributes location that we have seen in fragment. The Attributes in
  // template specialization can be used in different context and don't
  // want to de-duplicate them. The attribute location tells us if we are
  // referring to the original attribute or inherited one.
  EntityLocationMap attr_token_locs;

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

  // Entities map for tracking parent pointers
  EntityParentMap parent_decls;
  EntityParentMap parent_stmts;

  // If we're in a mode where we're generating source IR then we need the
  // entity IDs for all `Decl`s and `Stmt`s and such to be global.
  const bool generate_source_ir;

  inline explicit EntityMapper(TypeMapper &tm_, bool generate_source_ir_)
      : tm(tm_),
        generate_source_ir(generate_source_ir_) {}

  mx::RawEntityId ParentDeclId(const void *) const;
  mx::RawEntityId ParentStmtId(const void *) const;

  mx::RawEntityId ParentDeclId(const pasta::Decl &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::Stmt &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::Designator &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::TemplateArgument &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::TemplateParameterList &entity) const;
  mx::RawEntityId ParentDeclId(const pasta::CXXBaseSpecifier &entity) const;

  mx::RawEntityId ParentStmtId(const pasta::Decl &entity) const;
  mx::RawEntityId ParentStmtId(const pasta::Stmt &entity) const;
  mx::RawEntityId ParentStmtId(const pasta::Designator &entity) const;
  mx::RawEntityId ParentStmtId(const pasta::TemplateArgument &entity) const;

  inline mx::RawEntityId EntityId(std::nullptr_t entity) const noexcept {
    return mx::kInvalidEntityId;
  }

  mx::RawEntityId EntityId(const void *entity) const;
  mx::RawEntityId PerFragmentEntityId(const void *entity) const;
  mx::RawEntityId EntityId(const pasta::File &file) const;
  mx::RawEntityId EntityId(const pasta::Decl &entity) const;
  mx::RawEntityId EntityId(const pasta::Stmt &entity) const;
  mx::RawEntityId EntityId(const pasta::Token &entity) const;
  mx::RawEntityId EntityId(const pasta::DerivedToken &entity) const;
  mx::RawEntityId EntityId(const pasta::PrintedToken &entity) const;
  mx::RawEntityId EntityId(const pasta::FileToken &entity) const;
  mx::RawEntityId EntityId(const pasta::MacroToken &entity);
  mx::RawEntityId EntityId(const pasta::Type &entity) const;
  mx::RawEntityId EntityId(const pasta::Attr &entity) const;
  mx::RawEntityId EntityId(const pasta::Macro &entity) const;
  mx::RawEntityId EntityId(const TokenTree &entity) const;
  mx::RawEntityId EntityId(const TokenTreeNode &entity) const;
  mx::RawEntityId EntityId(const pasta::TemplateArgument &pseudo) const;
  mx::RawEntityId EntityId(const pasta::TemplateParameterList &pseudo) const;
  mx::RawEntityId EntityId(const pasta::CXXBaseSpecifier &pseudo) const;
  mx::RawEntityId EntityId(const pasta::Designator &pseudo) const;
  mx::RawEntityId EntityId(const pasta::CXXCtorInitializer &pseudo) const;

  std::pair<mx::RawEntityId, mx::RawEntityId> EntityIds(
      const pasta::TokenRange &range) const;

  template <typename T>
  inline mx::RawEntityId EntityId(const std::optional<T> &val) const {
    if (val) {
      return EntityId(val.value());
    }
    return mx::kInvalidEntityId;
  }

  inline mx::RawEntityId SelectiveEntityId(const void *entity) const {
    if (generate_source_ir) {
      return EntityId(entity);
    } else {
      return PerFragmentEntityId(entity);
    }
  }

  mx::RawEntityId EntityIdOfType(const void *type, uint32_t quals=0u) const;

  template <typename IdType>
  inline std::optional<IdType> SpecificEntityId(const void *raw_entity) const {
    return mx::EntityId(this->EntityId(raw_entity)).Extract<IdType>();
  }

  template <typename IdType, typename Entity>
  inline std::optional<IdType> SpecificEntityId(const Entity &entity) const {
    return mx::EntityId(this->EntityId(entity)).Extract<IdType>();
  }

  std::optional<const pasta::Decl> ParentDecl(
      const pasta::AST &ast, const pasta::Decl &entity) const;
  std::optional<const pasta::Decl> ParentDecl(
      const pasta::AST &ast, const pasta::Stmt &entity) const;
  std::optional<const pasta::Stmt> ParentStmt(
      const pasta::AST &ast, const pasta::Decl &entity) const;
  std::optional<const pasta::Stmt> ParentStmt(
      const pasta::AST &ast, const pasta::Stmt &entity) const;

  void ResetForFragment(void);

  inline void MarkAsTopLevel(const pasta::Decl &decl) {
    top_level_decls.insert(RawEntity(decl));
  }

  inline bool IsTopLevel(const pasta::Decl &decl) const {
    return IsTopLevel(RawEntity(decl));
  }

  inline bool IsTopLevel(const void *decl) const {
    return top_level_decls.count(decl) != 0u;
  }

  // ID of the parent fragment.
  mx::RawEntityId ParentFragmentId(const void *parent_entity) const;
};

}  // namespace indexer
