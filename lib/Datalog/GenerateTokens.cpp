// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <clang/Basic/TokenKinds.h>

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

  for (auto i = 0u; i < num_tokens; ++i) {
    auto tok = static_cast<clang::tok::TokenKind>(i);
    fs << "#constant TokenKind TK_";
    if (auto kw = clang::tok::getKeywordSpelling(tok)) {
      fs << "kw_";
    }
    fs << clang::tok::getTokenName(tok) << ' ' << i << " @unique.\n";
  }

  fs << '\n';

  return 0;
}
