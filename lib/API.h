// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once


#include <cstdint>
#include <multiplier/AST.capnp.h>
#include <multiplier/Index.h>
#include <multiplier/RPC.capnp.h>
#include <optional>
#include <string>

#include "Entity.h"

namespace mx {

class Decl;

using NodeReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;
using FragmentReader = rpc::Fragment::Reader;
using FileReader = rpc::File::Reader;
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

}  // namespace mx
