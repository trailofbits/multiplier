// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Action.h>
#include <multiplier/Types.h>
#include <pasta/AST/Decl.h>
#include <string>
#include <vector>

namespace indexer {

class IndexingContext;

class CodeGenerator {
 public:
  virtual ~CodeGenerator(void);

  CodeGenerator(void);

  void GenerateSourceIRFromTLDs(
      std::string mod_id, const std::vector<pasta::Decl> &tlds,
      std::string &sourceir);

 private:
  class Impl;

  Impl *impl;
};

// Generate Source IR from the top-level declarations. It uses vast
// emit_module API to lower the top-level declarations and save them
// to the persistent map with code ids.

// If there are more than one `FunctionDecl` in the list, the Source
// IR gets emitted to same module and saved with the same code ids. If
// the top-level declaration is not `FunctionDecl`, it will visit
// AST node and generate source ir for function decl found.

std::string ConvertToSourceIR(
    IndexingContext &context, mx::RawEntityId fragment_id,
    const std::vector<pasta::Decl> &decls);

}  // namespace indexer
