// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>

namespace pasta {
class AST;
class Decl;
}  // namespace pasta
namespace indexer {

class NameManglerImpl;

// Convenience class for easily mangling named decls into `std::string`s.
class NameMangler {
 private:
  const std::unique_ptr<NameManglerImpl> impl;

 public:
  ~NameMangler(void);

  explicit NameMangler(const pasta::AST &ast);

  // Returns the mangled name of `decl`.
  //
  // NOTE(pag): The same string reference is returned upon each call.
  const std::string &Mangle(const pasta::Decl &decl) const;

  // This is not a very good API, but basically says that the mangled name
  // can probably be trusted.
  bool MangledNameIsPrecise(void) const;
};

}  // namespace indexer
