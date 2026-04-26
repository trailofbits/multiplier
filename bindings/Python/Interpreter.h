// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/SharablePy.h>

#include "SharedPyPtr.h"

namespace mx {

using namespace ir::interpret;

// PyObjectRC instantiation of the symbolic interpreter state. Mirrors the
// alias in SymbolicInterpreter.h; defined here too so consumers that only
// pull in this header can name `MakeSymbolicStateWrapper`'s parameter.
using SymbolicState = InterpreterState<SharedPyPtr, PyObjectRC>;

// PyObjectRC instantiation of the concrete interpreter state. The Python
// wrapper holds a strong reference to a PyObject backed by this type;
// continuations from the concrete arm hold `PyRef<ConcreteState>` and
// release the inner state automatically on destruction.
using ConcreteState = InterpreterState<Value, PyObjectRC>;

// Create a new Python InterpreterStateWrapper from a PyObjectRC-managed
// symbolic state. The wrapper steals the strong reference from `state`.
PyObject *MakeSymbolicStateWrapper(ir::interpret::ref_t<SymbolicState> state);

}  // namespace mx
