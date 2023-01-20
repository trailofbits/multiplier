// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <string>
#include <vector>

#include "Action.h"

namespace pasta {
class AST;
class Decl;
}  // namespace pasta
namespace indexer {

class EntityMapper;
class GlobalIndexingState;

class CodeGeneratorImpl;
class CodeGenerator {
 private:
  std::unique_ptr<CodeGeneratorImpl> impl;

 public:
  ~CodeGenerator(void);

  CodeGenerator(void);

  void Disable(void);

  // Generate Source IR from the top-level declarations. It uses vast
  // emit_module API to lower the top-level declarations and save them
  // to the persistent map with code ids.

  // If there are more than one `FunctionDecl` in the list, the Source
  // IR gets emitted to same module and saved with the same code ids. If
  // the top-level declaration is not `FunctionDecl`, it will visit
  // AST node and generate source ir for function decl found.
  std::string GenerateSourceIRFromTLDs(
      const pasta::AST &ast, mx::RawEntityId frag_id,
      const EntityMapper &em, const std::vector<pasta::Decl> &tlds,
      unsigned num_decls);
};

}  // namespace indexer
