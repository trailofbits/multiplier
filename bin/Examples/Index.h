// Copyright (c) 2022-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cassert>
#include <cstdlib>
#include <gap/coro/generator.hpp>
#include <iostream>
#include <multiplier/Index.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

extern std::unordered_map<mx::PackedFileId, std::filesystem::path> file_paths;
extern mx::FileLocationCache location_cache;

mx::Index InitExample(bool fill_locations=false);

void HighlightToken(std::ostream &os, mx::Token token);

void PrintToken(std::ostream &os, mx::Token token);

std::unordered_set<mx::RawEntityId> FileTokenIdsFor(
    const mx::TokenRange &entity_tokens);

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    const mx::TokenRange &entity_tokens,
                    std::string indent="", bool print_line_numbers=false);

void RenderFragment(std::ostream &os, const mx::Fragment &fragment,
                    std::unordered_set<mx::RawEntityId> highlight_tokens_ids={},
                    std::string indent="", bool print_line_numbers=false);

void RenderTokens(std::ostream &os, const mx::TokenRange &tokens,
                  const mx::TokenRange &entity_tokens,
                  std::string indent="", bool print_line_numbers=false);

void RenderTokens(std::ostream &os, const mx::TokenRange &tokens,
                    std::unordered_set<mx::RawEntityId> highlight_tokens_ids={},
                    std::string indent="", bool print_line_numbers=false);
