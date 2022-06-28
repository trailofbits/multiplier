// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdlib>
#include <iostream>
#include <multiplier/Index.h>
#include <string>
#include <unordered_map>

extern std::unordered_map<mx::RawEntityId, std::filesystem::path> file_paths;
extern mx::FileLocationCache location_cache;

mx::Index InitExample(bool fill_locations=false);

void HighlightToken(std::ostream &os, mx::Token token);

void PrintToken(std::ostream &os, mx::Token token);

bool ContainsHighlightedTokens(mx::TokenSubstitutionList nodes,
                               const mx::TokenRange &entity_tokens);

void PrintUnparsedTokens(std::ostream &os, mx::TokenSubstitutionList nodes,
                         const mx::TokenRange &entity_tokens=mx::TokenRange(),
                         bool force_highlight=false);

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    const mx::TokenRange &entity_tokens,
                    std::string indent="", bool print_line_numbers=false);
