// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#if defined(__x86_64__) || defined(__x86_64) || \
    defined(__amd64__) || defined(__amd64) || \
    defined(__i386__) || defined(__i386) || \
    defined(__i486__) || defined(__i586__) || \
    defined(__i686__) || defined(__IA32__) || \
    defined(_M_I86) || defined(_M_IX86)
#include "X86Builtins.inc"
#endif
