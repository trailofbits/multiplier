//===-- ScopedPrinter.h ----------------------------------------*- C++ -*--===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#pragma once

// Hack to get around `std::unique_ptr` issue with a `struct DelimitedScope`.
#define LLVM_SUPPORT_SCOPEDPRINTER_H

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wshadow"
#pragma clang diagnostic ignored "-Wcast-align"
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/ScopedPrinter.h>
#pragma clang diagnostic pop

namespace llvm {

template <typename T> struct EnumEntry {
  StringRef Name;
  // While Name suffices in most of the cases, in certain cases
  // GNU style and LLVM style of ELFDumper do not
  // display same string for same enum. The AltName if initialized appropriately
  // will hold the string that GNU style emits.
  // Example:
  // "EM_X86_64" string on LLVM style for Elf_Ehdr->e_machine corresponds to
  // "Advanced Micro Devices X86-64" on GNU style
  StringRef AltName;
  T Value;
  constexpr EnumEntry(StringRef N, StringRef A, T V)
      : Name(N), AltName(A), Value(V) {}
  constexpr EnumEntry(StringRef N, T V) : Name(N), AltName(N), Value(V) {}
};

}  // namespace llvm
