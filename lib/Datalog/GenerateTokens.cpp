// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <clang/Basic/TokenKinds.h>

#include <cstring>
#include <fstream>

int main(int argc, char *argv[]) {
  auto num_tokens = static_cast<unsigned>(clang::tok::TokenKind::NUM_TOKENS);

  std::vector<std::string> token_kinds;
  token_kinds.resize(num_tokens);

  std::ofstream fs(argv[1]);

  fs
      << ";\n"
      << "; Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "; All rights reserved.\n"
      << ";\n"
      << "; This source code is licensed in accordance with the terms specified in\n"
      << "; the LICENSE file found in the root directory of this source tree.\n"
      << ";\n"
      << "; Auto-generated file, do not modify!\n\n"
      << "#enum TokenKind u16.\n";

  auto i = 0u;

#define TOK(X) \
    if (clang::tok::X == clang::tok::raw_identifier) { \
      fs << "#constant TokenKind TK_whitespace " << (i++) << " @unique.\n"; \
    } else { \
      fs << "#constant TokenKind TK_" #X << ' ' << (i++) << " @unique.\n"; \
    }
#include "clang/Basic/TokenKinds.def"

#define PPKEYWORD(X) \
    fs << "#constant TokenKind TK_pp_" #X << ' ' << (i++) << " @unique.\n";
#include "clang/Basic/TokenKinds.def"

#define OBJC_AT_KEYWORD(X) \
    fs << "#constant TokenKind TK_objc_" #X << ' ' << (i++) << " @unique.\n";
#include "clang/Basic/TokenKinds.def"

  fs << "#constant TokenKind TK_begin_macro_expansion "
     << (i++) << " @unique.\n";

  fs << "#constant TokenKind TK_end_macro_expansion "
     << (i++) << " @unique.\n";

  fs << "#constant TokenKind TK_begin_file " << (i++) << " @unique.\n";
  fs << "#constant TokenKind TK_end_file " << (i++) << " @unique.\n";
  fs << "#constant TokenKind TK_begin_directive " << (i++) << " @unique.\n";
  fs << "#constant TokenKind TK_end_directive " << (i++) << " @unique.\n";
  fs << '\n';

  return 0;
}
