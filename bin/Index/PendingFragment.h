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

class TypeMapper;

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

  FileLocationOfFragment(const mx::FileId &fid,
                         const mx::FileTokenId &begin,
                         const mx::FileTokenId &end)
      : file_index(fid.file_id),
        file_id(fid),
        first_file_token_id(begin),
        last_file_token_id(end) {}
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
  inline PendingFragment(mx::PackedFragmentId fragment_id_,
                         mx::PackedCompilationId tu_id_,
                         EntityMapper &em_)
      : fragment_id(fragment_id_),
        fragment_index(fragment_id.Unpack().fragment_id),
        compilation_id(tu_id_),
        em(em_){}

  // Unique ID of the fragment containing the top-level declarations `decls`.
  mx::PackedFragmentId fragment_id;
  mx::RawEntityId fragment_index;

  // The ID of the compilation from which this fragment is derived.
  mx::PackedCompilationId compilation_id;

  // Instance of entity mapper that will hold a map of entity ids
  // and type mapper. Each translation unit will have single instance
  // of entity mapper.
  EntityMapper &em;

  // Inclusive range of indices into the parsed tokens.
  uint64_t begin_index{0u};
  uint64_t end_index{0u};

  std::optional<FileLocationOfFragment> file_location;

  // Top-level declarations. These are the roots of serialization.
  std::vector<pasta::Decl> top_level_decls;
  std::vector<pasta::Macro> top_level_macros;

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
  std::vector<pasta::TemplateArgument> template_arguments_to_serialize;
  std::vector<pasta::TemplateParameterList> template_parameter_lists_to_serialize;
  std::vector<pasta::CXXBaseSpecifier> cxx_base_specifiers_to_serialize;
  std::vector<pasta::Designator> designators_to_serialize;

  // We distinguish entities from "pseudo" entities, where an entity is uniquely
  // identifiable via an `mx::EntityId`, whereas a pseudo entity is not uniquely
  // identifiable, but is attached to some other entity. For example, a
  // `TemplateParamterList` or a `TemplateArgument` is a pseudo entity.
  std::vector<Pseudo> pseudos_to_serialize;

  // Did we encounter an error during serialization?
  bool has_error{false};

  bool Add(const pasta::Decl &entity, EntityIdMap &entity_ids);
  bool Add(const pasta::Stmt &entity, EntityIdMap &entity_ids);
  bool Add(const pasta::Type &entity, TypeMapper &type_map);
  bool Add(const pasta::Attr &entity, EntityIdMap &entity_ids);
  bool Add(const pasta::TemplateArgument &pseudo, EntityIdMap &entity_ids);
  bool Add(const pasta::CXXBaseSpecifier &pseudo, EntityIdMap &entity_ids);
  bool Add(const pasta::TemplateParameterList &pseudo, EntityIdMap &entity_ids);
  bool Add(const pasta::Designator &pseudo, EntityIdMap &entity_ids);

  // Find and initialize `parent_decl_ids` and `last_file_token_id`.
  void InitFileLocationRange(
      EntityIdMap &entity_ids, const pasta::TokenRange &toks);
};

}  // namespace indexer
