// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <filesystem>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <fstream>
#include <sstream>

#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>

#include "Index.h"

DEFINE_string(output_dir, "", "Path to the directory into which all output will be dumped");

static llvm::json::Object UnparsedToken(mx::Token tok);
static llvm::json::Object UnparsedSubstitution(mx::TokenSubstitution sub);

static llvm::json::Array UnparsedTokens(mx::TokenSubstitutionList list) {
  llvm::json::Array tokens;
  for (std::variant<mx::Token, mx::TokenSubstitution> val : list) {
    if (std::holds_alternative<mx::Token>(val)) {
      tokens.emplace_back(UnparsedToken(std::get<mx::Token>(val)));
    } else {
      tokens.emplace_back(
          UnparsedSubstitution(std::get<mx::TokenSubstitution>(val)));
    }
  }
  return tokens;
}

llvm::json::Object UnparsedToken(mx::Token token) {
  llvm::json::Object obj;
  obj["data"] = token.data().data();
  obj["id"] = static_cast<uint64_t>(token.id());
  obj["kind"] = static_cast<unsigned>(token.kind());

  mx::VariantId vid = token.id().Unpack();
  if (std::holds_alternative<mx::FileTokenId>(vid)) {
    auto ft = std::get<mx::FileTokenId>(vid);
    obj["file_id"] = ft.file_id;
    obj["file_offset"] = ft.offset;
    obj["type"] = "file_token";

  } else if (std::holds_alternative<mx::FragmentTokenId>(vid)) {
    auto ft = std::get<mx::FragmentTokenId>(vid);
    obj["fragment_id"] = ft.fragment_id;
    obj["fragment_offset"] = ft.offset;
    obj["type"] = "fragment_token";
  }
  return obj;
}

llvm::json::Object UnparsedSubstitution(mx::TokenSubstitution sub) {
  llvm::json::Object obj;
  switch (sub.kind()) {
    case mx::TokenSubstitutionKind::FUNCTION_LIKE_MACRO_EXPANSION:
      obj["kind"] = "FUNCTION_LIKE_MACRO_EXPANSION";
      break;
    case mx::TokenSubstitutionKind::MACRO_EXPANSION:
      obj["kind"] = "MACRO_EXPANSION";
      break;
    case mx::TokenSubstitutionKind::INCLUDE_EXPANSION:
      obj["kind"] = "INCLUDE_EXPANSION";
      break;
  }
  obj["before"] = UnparsedTokens(sub.before());
  obj["after"] = UnparsedTokens(sub.after());
  return obj;
}

static void OutputSourceIR(const mx::Fragment &frag,
                           const std::filesystem::path &output_dir) {
  if (auto mlir = frag.source_ir(); mlir) {
    llvm::json::Object obj;
    obj["id"] = static_cast<uint64_t>(frag.id());
    obj["source_ir"] = llvm::StringRef(mlir->data(), mlir->size());

    std::string file_name = "mlir.fragment." + std::to_string(frag.id()) + ".json";
    llvm::json::Value val(std::move(obj));
    std::ofstream file_os((output_dir / file_name).generic_string(),
                          std::ios::trunc | std::ios::out);

    std::string file_data;
    llvm::raw_string_ostream file_data_os(file_data);
    file_data_os << std::move(val);
    file_os << file_data;
  }
}

static void OutputFileInfo(mx::File file, std::filesystem::path file_path) {
  std::filesystem::path output_dir =
      FLAGS_output_dir + "/." + file_path.generic_string();
  output_dir = output_dir.lexically_normal();
  std::error_code ec;
  std::filesystem::create_directories(output_dir, ec);
  if (ec) {
    LOG(ERROR)
        << "Skipping producing json for " << file_path << ": " << ec.message();
    return;
  }

  LOG(INFO)
      << "Saving JSON output related to file " << file_path << " to "
      << output_dir;

  llvm::json::Array tokens;
  llvm::json::Array fragment_ids;

  for(mx::Fragment frag : mx::Fragment::in(file)) {
    fragment_ids.push_back(frag.id());

    for (mx::Token token : mx::Token::in(frag)) {
      llvm::json::Object tok;
      tok["data"] = token.data().data();
      tok["id"] = static_cast<uint64_t>(token.id());
      tok["kind"] = static_cast<unsigned>(token.kind());
      tokens.emplace_back(std::move(tok));
    }


    llvm::json::Object obj;
    obj["id"] = static_cast<uint64_t>(frag.id());
    obj["tokens"] = std::move(tokens);
    obj["unparsed_tokens"] = UnparsedTokens(frag.substitutions());

    std::string file_name = "source.fragment." + std::to_string(frag.id()) + ".json";

    llvm::json::Value val(std::move(obj));
    std::ofstream file_os((output_dir / file_name).generic_string(),
                          std::ios::trunc | std::ios::out);

    std::string file_data;
    llvm::raw_string_ostream file_data_os(file_data);
    file_data_os << std::move(val);
    file_os << file_data;

    OutputSourceIR(frag, output_dir);
  }

  for (mx::Token token : mx::Token::in(file)) {
    llvm::json::Object tok;
    tok["data"] = token.data().data();
    tok["id"] = static_cast<uint64_t>(token.id());
    tok["kind"] = static_cast<unsigned>(token.kind());
    tokens.emplace_back(std::move(tok));
  }

  {
    std::string file_name = "file." + std::to_string(file.id()) + ".json";

    llvm::json::Object obj;
    obj["path"] = file_path.generic_string();
    obj["id"] = file.id();
    obj["fragments"] = std::move(fragment_ids);
    obj["tokens"] = std::move(tokens);

    llvm::json::Value val(std::move(obj));
    std::ofstream file_os((output_dir / file_name).generic_string(),
                          std::ios::trunc | std::ios::out);

    std::string file_data;
    llvm::raw_string_ostream file_data_os(file_data);
    file_data_os << std::move(val);
    file_os << file_data;
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] --output_dir DIR\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  if (FLAGS_output_dir.empty()) {
    std::cerr << "--output_dir must not be empty";
    return EXIT_FAILURE;
  }

  for (auto [path, id] : index.file_paths()) {
    if (auto maybe_file = index.file(id)) {
      OutputFileInfo(std::move(*maybe_file), std::move(path));
    }
  }

  return EXIT_SUCCESS;
}
