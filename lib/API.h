// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once


#include <cstdint>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include <capnp/serialize-packed.h>
#include <kj/io.h>
#include <multiplier/AST.capnp.h>
#include <multiplier/Index.h>
#include <multiplier/RPC.capnp.h>
#include <optional>
#include <string>

namespace mx {

class Decl;

using NodeReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using FragmentReader = rpc::Fragment::Reader;
using DeclReader = ast::Decl::Reader;
using StmtReader = ast::Stmt::Reader;
using TypeReader = ast::Type::Reader;
using AttrReader = ast::Attr::Reader;
using MacroReader = ast::Macro::Reader;
using PseudoReader = ast::Pseudo::Reader;
using DeclListReader = capnp::List<ast::Decl, capnp::Kind::STRUCT>::Reader;
using StmtListReader = capnp::List<ast::Stmt, capnp::Kind::STRUCT>::Reader;
using TypeListReader = capnp::List<ast::Type, capnp::Kind::STRUCT>::Reader;
using AttrListReader = capnp::List<ast::Attr, capnp::Kind::STRUCT>::Reader;
using MacroListReader = capnp::List<ast::Macro, capnp::Kind::STRUCT>::Reader;
using PseudoListReader = capnp::List<ast::Pseudo, capnp::Kind::STRUCT>::Reader;
using EntityIdListReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;

struct PackedReaderState {
 private:
  std::string storage;
  std::optional<kj::ArrayInputStream> stream;
  std::optional<capnp::PackedMessageReader> packed_reader;

  PackedReaderState(void) = delete;

 public:
  explicit PackedReaderState(capnp::Data::Reader data);
  explicit PackedReaderState(const std::string& data);

  template <typename T>
  auto Reader(void) -> typename T::Reader {
    return packed_reader->getRoot<T>();
  }
};

}  // namespace mx
