// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// NoOpScheduler's result methods are header-inlined alongside its
// declaration in Policy.h. This translation unit exists only to anchor the
// library target — keep Interpreter.cpp present so existing build rules
// don't have to drop a source file.

#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/Policy.h>
