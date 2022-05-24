// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <multiplier/Index.h>
#include <sstream>

DECLARE_bool(help);
DEFINE_string(host, "localhost", "Hostname of mx-server. Use 'unix' for a UNIX domain socket.");
DEFINE_string(port, "50051", "Port of mx-server. Use a path and 'unix' for the host for a UNIX domain socket.");
DEFINE_uint64(entity_id, 0, "ID of the entity to print");
DEFINE_bool(unparsed, false, "Show original source code?");

static void HighlightToken(mx::Token token) {
  std::cout << "\u001b[35m\033[1m" << token.data() << "\033[0m";
}

static void PrintToken(mx::Token token) {
  std::cout << token.data(); 
}

static bool ContainsHighlightedTokens(mx::TokenSubstitutionList nodes,
                                      const mx::TokenRange &entity_tokens) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      if (entity_tokens.index_of(std::get<mx::Token>(node))) {
        return true;
      }
    } else {
      if (ContainsHighlightedTokens(
              std::get<mx::TokenSubstitution>(node).after(), entity_tokens)) {
        return true;
      }
    }
  }
  return false;
}

static void PrintUnparsedTokens(mx::TokenSubstitutionList nodes,
                                const mx::TokenRange &entity_tokens,
                                bool force_highlight=false) {
  for (auto node : nodes) {
    if (std::holds_alternative<mx::Token>(node)) {
      auto token = std::get<mx::Token>(node);
      if (force_highlight || entity_tokens.index_of(token)) {
        HighlightToken(std::move(token));
      } else {
        PrintToken(std::move(token));
      }
    } else {
      auto sub = std::get<mx::TokenSubstitution>(node);
      PrintUnparsedTokens(
          sub.before(), entity_tokens,
          (force_highlight ||
           ContainsHighlightedTokens(sub.after(), entity_tokens)));
    }
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --fragment_id ID\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  if (FLAGS_help) {
    std::cerr << google::ProgramUsage() << std::endl;
    return EXIT_FAILURE;
  }

  mx::Index index(mx::EntityProvider::in_memory_cache(
      mx::EntityProvider::from_remote(
          FLAGS_host, FLAGS_port)));
  
  mx::TokenRange entity_tokens;
  std::optional<mx::Fragment> fragment;

  auto maybe_entity = index.entity(FLAGS_entity_id);
  if (std::holds_alternative<mx::Decl>(maybe_entity)) {
    auto entity = std::get<mx::Decl>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Stmt>(maybe_entity)) {
    auto entity = std::get<mx::Stmt>(maybe_entity);
    fragment.emplace(mx::Fragment::containing(entity));
    entity_tokens = entity.tokens();

  } else if (std::holds_alternative<mx::Token>(maybe_entity)) {
    auto entity = std::get<mx::Token>(maybe_entity);
    fragment = mx::Fragment::containing(entity);
    entity_tokens = entity;
  }

  if (!fragment) {
    std::cerr
        << "Invalid or unsupported entity id " << FLAGS_entity_id << std::endl;
    return EXIT_FAILURE;
  }

  // Print out the tokens of this fragment as they appear in the file.
  if (FLAGS_unparsed) {
    PrintUnparsedTokens(fragment->substitutions(), entity_tokens);

  // Print out the tokens of this fragment that were actually parsed. These
  // are post-macro expansion tokens, and generally don't include whitespace
  // or comments. There can be empty tokens, however.
  } else {
    for (mx::Token token : mx::Token::in(*fragment)) {
      if (entity_tokens.index_of(token)) {
        HighlightToken(std::move(token));
      } else {
        PrintToken(std::move(token));
      }
      std::cout << ' ';
    }
    std::cout << '\n';
  }

  return EXIT_SUCCESS;
}
