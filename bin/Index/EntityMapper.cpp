// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "EntityMapper.h"

#include <cassert>
#include <glog/logging.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Token.h>
#include <pasta/Util/File.h>

#include "TypeMapper.h"
#include "Util.h"

namespace indexer {

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Decl &entity) const {
  if (auto it = parent_decl_ids.find(entity.RawDecl());
      it != parent_decl_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Stmt &entity) const {
  if (auto it = parent_decl_ids.find(entity.RawStmt());
      it != parent_decl_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Decl &entity) const {
  if (auto it = parent_stmt_ids.find(entity.RawDecl());
      it != parent_stmt_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Stmt &entity) const {
  if (auto it = parent_stmt_ids.find(entity.RawStmt());
      it != parent_stmt_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const void *entity) const {
  if (auto it = entity_ids.find(entity); it != entity_ids.end()) {
    if (mx::RawEntityId eid = it->second.Pack(); eid != mx::kInvalidEntityId) {
      return eid;
    }
  }
  return PerFragmentEntityId(entity);
}


mx::RawEntityId EntityMapper::PerFragmentEntityId(const void *entity) const {
  if (auto it = token_tree_ids.find(entity); it != token_tree_ids.end()) {
    return it->second.Pack();

  } else {
    return tm.EntityId(entity);
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Decl &entity) const {
  return EntityId(entity.RawDecl());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Stmt &entity) const {
  return PerFragmentEntityId(entity.RawStmt());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Attr &entity) const {
  if (auto tok = entity.Token().RawToken()) {
    if (auto it = attr_ids.find(tok); it != attr_ids.end()) {
      return it->second.Pack();
    }
  }
  return PerFragmentEntityId(entity.RawAttr());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Macro &entity) const {
  if (auto mt = pasta::MacroToken::From(entity)) {
    return EntityId(mt->ParsedLocation());
  }

  // NOTE(pag): May be part of a directive, which may be referenced by other
  //            fragments, so we use `EntityId`, which falls back on
  //            `PerFragmentEntityId`.
  auto ret = EntityId(entity.RawMacro());
  if (ret || entity.Kind() != pasta::MacroKind::kExpansion) {
    return ret;
  }

  // The `TokenTree` merges macro expansions with argument pre-expansions, which
  // are separately represented in PASTA. The `TokenTree::Macro()` node
  // preserved is the top-level, non-argument pre-expansion phase of the
  // expansion, just in case `TokenTree` building fails and we revert to a
  // backup path of serialization (where we might already have entity IDs for
  // these top-level expansions from the `EntityLabeller`). However, there
  // may be children nodes of the argument pre-expansion that point to that
  // rather than the top-level node, so here we try to recover to enable
  // `mx::Macro::parent` serialization to succeed.

  auto exp = pasta::MacroExpansion::From(entity);
  if (!exp || !exp->IsArgumentPreExpansion()) {
    return ret;
  }

  if (std::optional<pasta::Macro> parent = exp->Parent()) {
    ret = EntityId(parent.value());
  }

  return ret;
}

mx::RawEntityId EntityMapper::EntityId(const TokenTree &entity) const {
  return EntityId(entity.RawNode());
}

mx::RawEntityId EntityMapper::EntityId(const TokenTreeNode &entity) const {
  return EntityId(entity.RawNode());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Token &entity) const {
  if (!entity) {
    return mx::kInvalidEntityId;
  }

  // NOTE(pag): May be part of a directive, which may be referenced by other
  //            fragments, so we use `EntityId`, which falls back on
  //            `PerFragmentEntityId`.
  auto eid = EntityId(entity.RawToken());
  if (eid != mx::kInvalidEntityId) {
    return eid;
  }

  // We shouldn't get parsed tokens here, though when serializing types, we
  // might
  if (IsParsedToken(entity)) {
    assert(false);
    //assert(entity.Kind() == pasta::TokenKind::kEllipsis);
    return eid;
  }

  if (auto mt = entity.MacroLocation()) {
    eid = EntityId(mt->RawMacro());
    if (eid != mx::kInvalidEntityId) {
      return eid;
    }
  }

  // If this token is derived from another one, and we don't have an entity
  // ID for it, then try to get the entity ID for the derived token.
  if (auto dt = entity.DerivedLocation()) {
    eid = EntityId(dt.value());
    if (eid != mx::kInvalidEntityId) {
      return eid;
    }
  }

  // If we fail to resolve the parsed token to an entity ID, then try to
  // see if it's associated with a `pasta::FileToken`, and if so, then form
  // an entity ID for that. We unify `Token` and `FileToken` in our serialized
  // representation, because we always want references to "point somewhere."
  if (auto ft = entity.FileLocation()) {
    eid = EntityId(ft.value());  
  }

  return eid;
}

mx::RawEntityId EntityMapper::EntityId(const pasta::PrintedToken &entity) const {
  if (auto id = PerFragmentEntityId(entity.RawToken());
      id != mx::kInvalidEntityId) {
    return id;

  } else if (auto pt = entity.DerivedLocation()) {
    return EntityId(pt.value());
  
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::MacroToken &entity) {
  return EntityId(entity.ParsedLocation());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::File &file) const {
  return EntityId(file.RawFile());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::FileToken &entity) const {
  mx::RawEntityId file_id = EntityId(entity.RawFile());
  if (file_id == mx::kInvalidEntityId) {
    return mx::kInvalidEntityId;
  }

  mx::VariantId vid = mx::EntityId(file_id).Unpack();
  if (!std::holds_alternative<mx::FileId>(vid)) {
    return mx::kInvalidEntityId;
  }

  mx::FileTokenId id;
  id.file_id = std::get<mx::FileId>(vid).file_id;
  id.kind = TokenKindFromPasta(entity);
  id.offset = static_cast<mx::EntityOffset>(entity.Index());
  ::mx::EntityId ret_id(id);
  return ret_id.Pack();
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Type &entity) const {
  return tm.EntityId(entity);
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::TemplateArgument &pseudo) const {
  return PerFragmentEntityId(pseudo.RawTemplateArgument());
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::TemplateParameterList &pseudo) const {
  return PerFragmentEntityId(pseudo.RawTemplateParameterList());
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::CXXBaseSpecifier &pseudo) const {
  return PerFragmentEntityId(pseudo.RawCXXBaseSpecifier());
}

mx::RawEntityId EntityMapper::EntityId(
    const pasta::Designator &pseudo) const {
  return PerFragmentEntityId(pseudo.RawDesignator());
}

mx::RawEntityId EntityMapper::EntityIdOfType(
    const void *type, uint32_t quals) const {
  return tm.EntityId(type, quals);
}

void EntityMapper::ResetForFragment(void) {
  // clear token tree ids, parent_decl_ids, and parent_stmt_ids before
  // processing new pending fragments. Not clearing them will cause issue
  // with fragment specific token trees and parentage tracking
  token_tree_ids.clear();
  parent_decl_ids.clear();
  parent_stmt_ids.clear();
}

}  // namespace indexer
