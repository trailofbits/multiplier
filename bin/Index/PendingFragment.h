// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <cstdint>
#include <memory>
#include <multiplier/Types.h>
#include <optional>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>
#include <pasta/Util/File.h>
#include <variant>

#include "TokenTree.h"
#include "Util.h"

namespace indexer {

class EntityMapper;
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
  inline PendingFragment(mx::PackedFragmentId fragment_id_, bool is_new_,
                         mx::PackedCompilationId tu_id_,
                         uint64_t first_parsed_token_index_,
                         uint64_t last_parsed_token_index_,
                         EntityMapper &em_,
                         const pasta::TokenRange *original_tokens_,
                         pasta::PrintedTokenRange parsed_tokens_,
                         std::optional<FileLocationOfFragment> file_location_)
      : fragment_id(fragment_id_),
        fragment_index(fragment_id.Unpack().fragment_id),
        compilation_id(tu_id_),
        em(em_),
        parsed_tokens(std::move(parsed_tokens_)),
        file_location(std::move(file_location_)),
        first_parsed_token_index(first_parsed_token_index_),
        last_parsed_token_index(last_parsed_token_index_),
        is_new(is_new_) {
    if (original_tokens_) {
      original_tokens = *original_tokens_;
    }
  }

  // Unique ID of the fragment containing the top-level declarations `decls`.
  mx::PackedFragmentId fragment_id;
  mx::RawEntityId fragment_index;

  // Provenance back to the root fragment.
  std::vector<mx::PackedFragmentId> parent_fragment_ids;

  // The ID of the compilation from which this fragment is derived.
  mx::PackedCompilationId compilation_id;

  // Instance of entity mapper that will hold a map of entity ids
  // and type mapper. Each translation unit will have single instance
  // of entity mapper.
  EntityMapper &em;

  // The original tokens of the fragment.
  std::optional<pasta::TokenRange> original_tokens;

  // Adopted tokens from `original_tokens`, or tokens created by printing a
  // implicit declaration.
  //
  // In the adoption case, we try to align the original tokens with the
  // parsed tokens, so that parsed tokens are associated with rich token
  // contexts.
  pasta::PrintedTokenRange parsed_tokens;

  std::optional<FileLocationOfFragment> file_location;

  // Top-level declarations. These are the roots of serialization.
  std::vector<pasta::Decl> top_level_decls;
  std::vector<pasta::Macro> top_level_macros;

  // These are original PASTA parsed token indexes, representing the bounds of
  // this fragment, even if this is a freestanding fragment. These bounds help
  // us to avoid oddities in Clang, e.g. where clang will associate struct
  // attributes on forward declarations with prior definitions if they already
  // exist.
  const uint64_t first_parsed_token_index;
  const uint64_t last_parsed_token_index;  // Inclusive.

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

  // Did we encounter an error during serialization?
  bool has_error{false};

  // Is this a new fragment? This affects whether or not we keep track of types.
  // We don't want `PendingFragment` for a pre-existing type to "take ownership"
  // of a type, only to have that pending fragment "thrown away" later (due to
  // it being redundant), yet have other fragments in the TU point to type IDs
  // that logically belong to this type.
  const bool is_new;

  // Keep track on if we've labelled some top-level entities in the entity
  // mapper.
  bool has_labelled_decls{false};
  bool has_labelled_tokens{false};

  // Should we drop token provenance after we've labelled tokens? This helps
  bool drop_token_provenance{false};

  bool Add(const pasta::Decl &entity);
  bool Add(const pasta::Stmt &entity);
  bool Add(pasta::Type entity);
  bool Add(const pasta::Attr &entity);
  bool Add(const pasta::TemplateArgument &pseudo);
  bool Add(const pasta::CXXBaseSpecifier &pseudo);
  bool Add(const pasta::TemplateParameterList &pseudo);
  bool Add(const pasta::Designator &pseudo);

  // Go and try to find the entity ID to be used for `Decl::Token`. We might
  // not have any return values for that for builtin types/declarations, and
  // that prevents a lot of API users (especially the GUI) from using the
  // declaration token to render the entity name.
  mx::RawEntityId DeclTokenEntityId(const pasta::Decl &) const;

  // Find and initialize `parent_decl_ids` and `last_file_token_id`.
  void InitFileLocationRange(EntityIdMap &entity_ids,
                             const pasta::TokenRange &toks);
};

using PendingFragmentPtr = std::unique_ptr<PendingFragment>;

}  // namespace indexer
