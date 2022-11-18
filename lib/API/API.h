// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Index.h>

#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <kj/io.h>
#include <multiplier/Weggli.h>
#include <multiplier/Re2.h>
#include <mutex>
#include <optional>
#include <string>

#include <multiplier/AST.capnp.h>
#include <multiplier/RPC.capnp.h>

namespace mx {

bool MayHaveRemoteRedeclarations(const mx::Decl &decl);
bool MayHaveRemoteUses(const mx::Decl &decl);

using NodeReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using MacroSubstitutionsReader = capnp::List<rpc::MacroSubstitution,
                                             capnp::Kind::STRUCT>::Reader;
using FragmentReader = rpc::Fragment::Reader;
using DeclReader = ast::Decl::Reader;
using StmtReader = ast::Stmt::Reader;
using TypeReader = ast::Type::Reader;
using AttrReader = ast::Attr::Reader;
using PseudoReader = ast::Pseudo::Reader;
using DeclListReader = capnp::List<ast::Decl, capnp::Kind::STRUCT>::Reader;
using StmtListReader = capnp::List<ast::Stmt, capnp::Kind::STRUCT>::Reader;
using TypeListReader = capnp::List<ast::Type, capnp::Kind::STRUCT>::Reader;
using TypeAttrReader = capnp::List<ast::Attr, capnp::Kind::STRUCT>::Reader;
using PseudoListReader = capnp::List<ast::Pseudo, capnp::Kind::STRUCT>::Reader;
using TopLevelDeclListReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;

struct PackedReaderState {
 private:
  std::string storage;
  std::optional<kj::ArrayInputStream> stream;
  std::optional<capnp::PackedMessageReader> packed_reader;

  PackedReaderState(void) = delete;

 public:
  explicit PackedReaderState(capnp::Data::Reader data);

  template <typename T>
  auto Reader(void) -> typename T::Reader {
    return packed_reader->getRoot<T>();
  }
};

}  // namespace mx
