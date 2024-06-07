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

namespace pasta {
class AST;
class Decl;
}  // namespace pasta
namespace indexer {

class EntityMapper;
class NameMangler;
class PendingFragment;

class CodeGeneratorImpl;
class CodeGenerator {
 private:
  bool enabled = true;
  std::unique_ptr<CodeGeneratorImpl> impl;

 public:
  CodeGenerator();

  ~CodeGenerator();

  void Disable();

  bool IsEnabled() const;

  // Generate Source IR from the top-level declarations. It uses vast
  // emit_module API to lower the top-level declarations and save them
  // to the persistent map with code ids.

  // If there are more than one `FunctionDecl` in the list, the Source
  // IR gets emitted to same module and saved with the same code ids. If
  // the top-level declaration is not `FunctionDecl`, it will visit
  // AST node and generate source ir for function decl found.
  std::string GenerateSourceIR(const pasta::AST &ast, const EntityMapper &em,
                               const NameMangler &nm);
};

}  // namespace indexer
