// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "../../Compiler.h"
#include "Driver.h"
#include <functional>

namespace mx::ir::interpret {

// Function resolver: given an entity ID (FunctionDecl or DeclRefExpr),
// return its IRFunction. Used for both direct and indirect calls.
using FunctionResolver =
    std::function<std::optional<IRFunction>(RawEntityId)>;

// Global resolver: given a global variable's entity ID, return its info.
using GlobalResolver =
    std::function<std::optional<GlobalInfo>(RawEntityId)>;

// Concrete driver: resolves all suspensions with simple default policies.
class MX_EXPORT ConcreteDriver final : public Driver {
 public:
  explicit ConcreteDriver(FunctionResolver func_resolver = {},
                          GlobalResolver global_resolver = {});
  ~ConcreteDriver(void) override = default;

  Resolution Resolve(const Suspension &s) override;

 private:
  FunctionResolver func_resolver_;
  GlobalResolver global_resolver_;
};

}  // namespace mx::ir::interpret
