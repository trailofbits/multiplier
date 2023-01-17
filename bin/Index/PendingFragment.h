// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <cstdint>
#include <multiplier/Types.h>
#include <optional>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <variant>

#include "TokenTree.h"
#include "Util.h"

namespace indexer {

using Pseudo = std::variant<pasta::TemplateArgument,
                            pasta::CXXBaseSpecifier,
                            pasta::TemplateParameterList,
                            pasta::Designator>;

class FileLocationOfFragment {
 public:
  mx::RawEntityId file_index;
  mx::SpecificEntityId<mx::FileId> file_id;
  mx::SpecificEntityId<mx::FileTokenId> first_file_token_id;
  mx::SpecificEntityId<mx::FileTokenId> last_file_token_id;
  unsigned first_line_number;
  unsigned last_line_number;

  FileLocationOfFragment(const mx::FileId &fid,
                         const mx::FileTokenId &begin,
                         const pasta::FileToken &begin_tok,
                         const mx::FileTokenId &end,
                         const pasta::FileToken &end_tok)
      : file_index(fid.file_id),
        file_id(fid),
        first_file_token_id(begin),
        last_file_token_id(end),
        first_line_number(begin_tok.Line()),
        last_line_number(end_tok.Line()) {}
};

// Summary information about a group of top-level declarations that are
// somehow lexically/syntactically "stuck together" and thus serialized
// together. For example, `int optind, opterr, optopt;` is one example of
// being syntactically stuck together. Another example would be a C macro
// that expands into two separate top-level declarations. We don't want to
// break this macro expansion into two, as in the original source file it
// represents a single logical thing.
class PendingFragment {
 public:
  inline PendingFragment(mx::PackedFragmentId fragment_id_)
      : fragment_id(fragment_id_),
        fragment_index(fragment_id.Unpack().fragment_id) {}

  // Unique ID of the fragment containing the top-level declarations `decls`.
  mx::PackedFragmentId fragment_id;
  mx::RawEntityId fragment_index;

  // Inclusive range of indices into the parsed tokens.
  uint64_t begin_index{0u};
  uint64_t end_index{0u};

  std::optional<FileLocationOfFragment> file_location;

  // Top-level declarations. These are the roots of serialization.
  std::vector<pasta::Decl> top_level_decls;
  std::vector<pasta::Macro> top_level_macros;

  // Entity IDs for parentage tracking.
  EntityIdMap parent_decl_ids;
  EntityIdMap parent_stmt_ids;

  // Offsets of the serialized version of pseudo entities in this fragment.
  PseudoOffsetMap pseudo_offsets;

  unsigned num_top_level_declarations{0u};
  unsigned num_top_level_macros{0u};

  // Macros, declarations, statements, types, and pseudo-entities to serialize,
  // in their order of appearance and serialization.
  std::vector<std::optional<TokenTree>> macros_to_serialize;
  std::vector<pasta::Decl> decls_to_serialize;
  std::vector<pasta::Stmt> stmts_to_serialize;
  std::vector<pasta::Type> types_to_serialize;
  std::vector<pasta::Attr> attrs_to_serialize;

  // We distinguish entities from "pseudo" entities, where an entity is uniquely
  // identifiable via an `mx::EntityId`, whereas a pseudo entity is not uniquely
  // identifiable, but is attached to some other entity. For example, a
  // `TemplateParamterList` or a `TemplateArgument` is a pseudo entity.
  std::vector<Pseudo> pseudos_to_serialize;

  // Find and initialize `parent_decl_ids` and `last_file_token_id`.
  void InitFileLocationRange(
      EntityIdMap &entity_ids, const pasta::TokenRange &toks);
};

}  // namespace indexer
