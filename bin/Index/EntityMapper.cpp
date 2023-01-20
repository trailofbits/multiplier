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

#include "Util.h"

namespace indexer {

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Decl &entity) const {
  if (auto it = fragment.parent_decl_ids.find(entity.RawDecl());
      it != fragment.parent_decl_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentDeclId(const pasta::Stmt &entity) const {
  if (auto it = fragment.parent_decl_ids.find(entity.RawStmt());
      it != fragment.parent_decl_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Decl &entity) const {
  if (auto it = fragment.parent_stmt_ids.find(entity.RawDecl());
      it != fragment.parent_stmt_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::ParentStmtId(const pasta::Stmt &entity) const {
  if (auto it = fragment.parent_stmt_ids.find(entity.RawStmt());
      it != fragment.parent_stmt_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const void *entity) const {
  if (auto it = entity_ids.find(entity); it != entity_ids.end()) {
    return it->second.Pack();

  } else if (auto it2 = token_tree_ids.find(entity);
             it2 != token_tree_ids.end()) {
    return it2->second.Pack();

  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Decl &entity) const {
  return EntityId(entity.RawDecl());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Stmt &entity) const {
  return EntityId(entity.RawStmt());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Attr &entity) const {
  return EntityId(entity.RawAttr());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Macro &entity) const {
  if (auto mt = pasta::MacroToken::From(entity)) {
    return EntityId(mt->ParsedLocation());
  }

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

mx::RawEntityId EntityMapper::EntityId(const pasta::Token &entity) const {
  if (auto it = entity_ids.find(entity.RawToken()); it != entity_ids.end()) {
    return it->second.Pack();

  // If this token is derived from another one, and we don't have an entity
  // ID for it, then try to get the entity ID for the derived token.
  } else if (auto dt = entity.DerivedLocation()) {
    return EntityId(dt.value());

  // If we fail to resolve the parsed token to an entity ID, then try to
  // see if it's associated with a `pasta::FileToken`, and if so, then form
  // an entity ID for that. We unify `Token` and `FileToken` in our serialized
  // representation, because we always want references to "point somewhere."
  } else if (auto ft = entity.FileLocation()) {
    return this->EntityId(ft.value());
  
  } else {
    return mx::kInvalidEntityId;
  }
}

mx::RawEntityId EntityMapper::EntityId(const pasta::MacroToken &entity) {
  return EntityId(entity.ParsedLocation());
}

mx::RawEntityId EntityMapper::EntityId(const pasta::File &file) const {
  if (auto fit = entity_ids.find(file.RawFile()); fit != entity_ids.end()) {
    return fit->second.Pack();

  } else {
    return mx::kInvalidEntityId;
  }
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
  id.offset = static_cast<uint32_t>(entity.Index());
  ::mx::EntityId ret_id(id);
  return ret_id.Pack();
}

mx::RawEntityId EntityMapper::EntityId(const pasta::Type &entity) const {
  TypeKey type_key(entity.RawType(), entity.RawQualifiers());
  assert(type_key.first != nullptr);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    assert(false);
    return mx::kInvalidEntityId;
  }
}

uint32_t EntityMapper::PseudoId(const pasta::TemplateArgument &pseudo) const {
  if (auto it = fragment.pseudo_offsets.find(pseudo.RawTemplateArgument());
      it != fragment.pseudo_offsets.end()) {
    return it->second;
  } else {
    assert(false);
    return ~0u;
  }
}

uint32_t EntityMapper::PseudoId(
    const pasta::TemplateParameterList &pseudo) const {
  if (auto it = fragment.pseudo_offsets.find(pseudo.RawTemplateParameterList());
      it != fragment.pseudo_offsets.end()) {
    return it->second;
  } else {
    assert(false);
    return ~0u;
  }
}

uint32_t EntityMapper::PseudoId(const pasta::CXXBaseSpecifier &pseudo) const {
  if (auto it = fragment.pseudo_offsets.find(pseudo.RawCXXBaseSpecifier());
      it != fragment.pseudo_offsets.end()) {
    return it->second;
  } else {
    assert(false);
    return ~0u;
  }
}

uint32_t EntityMapper::PseudoId(const pasta::Designator &pseudo) const {
  if (auto it = fragment.pseudo_offsets.find(pseudo.RawDesignator());
      it != fragment.pseudo_offsets.end()) {
    return it->second;
  } else {
    assert(false);
    return ~0u;
  }
}

mx::RawEntityId EntityMapper::EntityIdOfType(const void *type, uint32_t quals) const {
  TypeKey type_key(type, quals);
  assert(type_key.first != nullptr);
  if (auto it = type_ids.find(type_key); it != type_ids.end()) {
    return it->second.Pack();
  } else {
    return mx::kInvalidEntityId;
  }
}

}  // namespace indexer
