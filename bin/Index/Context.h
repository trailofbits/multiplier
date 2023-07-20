// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <atomic>
#include <cstdint>
#include <filesystem>
#include <memory>
#include <multiplier/Database.h>
#include <string>

#include "Codegen.h"
#include "Executor.h"
#include "ProgressBar.h"
#include "Util.h"

namespace pasta {
class CompileJob;
class Compiler;
class File;
class TokenRange;
}  // namespace pasta
namespace mx {
class Executor;
class ProgressBar;
enum class DeclKind : unsigned char;
}  // namespace mx
namespace indexer {

class CodeGenerator;
class GlobalIndexingState;
class NameMangler;
class PendingFragment;
class TokenProvenanceCalculator;

// State that needs to live only as long as there are active indexing jobs
// underway.
class GlobalIndexingState {
 public:

  // Tracks progress in evaluating compile commands.
  std::unique_ptr<ProgressBar> command_progress;

  // Tracks progress in evaluating compile commands.
  std::unique_ptr<ProgressBar> eval_command_progress;

  // Tracks progress in running compile jobs to produce ASTs.
  std::unique_ptr<ProgressBar> ast_progress;

  // Tracks progress in partitioning an AST into fragments.
  std::unique_ptr<ProgressBar> partitioning_progress;

  // Tracks progress in serializing fragments.
  std::unique_ptr<ProgressBar> fragment_progress;

  // Tracks progress in serializing types.
  std::unique_ptr<ProgressBar> type_progress;

  // Tracks progress in saving tokenized files.
  std::unique_ptr<ProgressBar> file_progress;

  // Number of fragments for which we are attempting to generate source ir.
  std::unique_ptr<ProgressBar> sourceir_progress;

  const unsigned num_workers;

  // Worker pool.
  Executor executor;

  // MLIR code generator.
  CodeGenerator codegen;

  // Write access to the index database.
  mx::DatabaseWriter &database;

  explicit GlobalIndexingState(mx::DatabaseWriter &database_,
                               const Executor &exe_);

  ~GlobalIndexingState(void);

  void InitializeProgressBars(void);

  // Persist a file. Our representation includes stuff not in the file to enable
  // us to improve performance of common operations, like search. That is, we
  // could store a file as a list of tokens, where each token has its own data;
  // however, we want to able to run regular expression searches over files, and
  // so it's convenient to not have to reconstruct the file data from the tokens
  // for every such query. Similarly, we often want to map from matches in files
  // to matches in fragments, and so we create and persist a mapping of file
  // offsets to line numbers here to help us with those translations later.
  void PersistFile(mx::SpecificEntityId<mx::FileId> file_id,
                   const pasta::File &file);

  // Persist a fragment. A fragment is Multiplier's "unit of granularity" of
  // deduplication and indexing. It roughly corresponds to a sequence of one-or-
  // more syntactically overlapping "top-level declarations." For us, a top-
  // level declaration is one that only nested inside of a namespace, a linkage
  // specifier, a translation unit, etc. Thus, things like global variables,
  // functions, and classes are all top-level declarations. These things tend
  // to contain lots of other declarations/statements, and those all get lumped
  // into and persisted a TLD's fragment.
  //
  // Fragments separate out their lists of persistent entities. This enables
  // some downstream benefits. For example, all declarations are persisted in a
  // separate list from all statements. This allows us to more easily jump into
  // the middle of the "sub-AST" persisted in a fragment. For example, if we
  // want to find all `VarDecl`s, we can iterate the list of declarations, check
  // the decl kinds, and then yield only the discovered `VarDecl`s. No recursive
  // visitor needed!
  //
  // Fragments also store things like the macro substitution tree, and parsed
  // tokens associated with the covered declarations/statements. This is
  // partially because our serialized decls/stmts/etc. reference these tokens,
  // and partially so that we can do things like print out fragments, or chunks
  // thereof.
  void PersistFragment(const pasta::AST &ast, const pasta::TokenRange &tokens,
                       NameMangler &mangler, EntityMapper &em,
                       TokenProvenanceCalculator &provenance,
                       PendingFragment &fragment);

  // Persist a type fragment into the database. Type fragments are special
  // fragments that are created to persist the types collected for
  // serialization. Storing types into a different fragment will help with type
  // de-duplication which is a by product of inlining the types in each
  // fragment.
  //
  // The pending fragment passed as one of the arguments holds the list of types
  // that needs to be serialized in a fragment.
  void PersistTypes(const pasta::AST &ast, NameMangler &mangler,
                    EntityMapper &em, const PendingFragment &fragment);

  // Persist the compilation.
  void PersistCompilation(const pasta::Compiler &compiler,
                          const pasta::CompileJob &job, const pasta::AST &ast,
                          const EntityMapper &em, mx::PackedCompilationId tu_id,
                          const std::vector<PendingFragment> &fragments);
};

}  // namespace indexer
