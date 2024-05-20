// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>

#include <multiplier/Types.h>
#include <pasta/AST/Decl.h>

namespace clang {
class Decl;
class NamedDecl;
}  // namespace clang
namespace pasta {
class AST;
}  // namespace pasta
namespace indexer {

class NameManglerImpl;

// Convenience class for easily mangling named decls into `std::string`s.
class NameMangler {
 private:
  const std::unique_ptr<NameManglerImpl> impl;

 public:
  ~NameMangler(void);

  explicit NameMangler(const pasta::AST &ast, mx::PackedCompilationId tu_id);

  // Returns the mangled name of `decl`.
  //
  // NOTE(pag): The same string reference may be returned across calls.
  const std::string &Mangle(const clang::Decl *decl) const;

  inline const std::string &Mangle(const pasta::Decl &decl) const {
    return Mangle(decl.RawDecl());
  }
};

}  // namespace indexer
