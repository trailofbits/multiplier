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

using EntityIdListReader = capnp::List<uint64_t, capnp::Kind::PRIMITIVE>::Reader;

}  // namespace mx
