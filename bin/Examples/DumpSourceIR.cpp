// Copyright (c) 2023-present, Trail of Bits, Inc.
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
#include <unordered_set>

#include <llvm/Support/JSON.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/SourceMgr.h>

#include <mlir/IR/Dialect.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/Parser/Parser.h>

#include <vast/Dialect/Dialects.hpp>
#include <vast/Translation/CodeGenContext.hpp>
#include <vast/Translation/CodeGenBuilder.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>

#include <multiplier/AST.h>

#include "Index.h"

DECLARE_bool(help);
DECLARE_string(db);

using vast_symbol_interface   = vast::VastSymbolOpInterface;
using mlir_symbol_interface   = mlir::SymbolOpInterface;

using SeenSet = std::set<mx::PackedDeclId>;
using WorkList = std::vector<mx::Decl>;

namespace {

static std::string SymbolName(vast_symbol_interface &value) {
  return value.getSymbolName().str();
}

static std::string SymbolName(mlir_symbol_interface &value) {
  return value.getName().str();
}

static std::string AttributeString(mlir::Attribute &attr) {
  std::string attr_string;
  llvm::raw_string_ostream os(attr_string);
  attr.print(os);
  return attr_string;
}

// Get the entity id from the location. It is embedded as `meta.id<>`
mx::RawEntityId MetaId(mlir::Location &loc) {
  if(loc.isa<mlir::FusedLoc>()) {
    auto fused = loc.cast<mlir::FusedLoc>();
    auto meta = fused.getMetadata();
    if (meta.isa<vast::meta::IdentifierAttr>()) {
      auto identifier = meta.cast<const vast::meta::IdentifierAttr>();
      return identifier.getValue();
    }
  }
  return mx::kInvalidEntityId;
}

std::string LocationString(mlir::Location &loc) {
  std::stringstream ss;
  if(loc.isa<mlir::FusedLoc>()) {
    auto fused = loc.cast<mlir::FusedLoc>();
    auto file_locs = fused.getLocations();
    ss << "[";
    for (auto &file_loc : file_locs) {
      if (file_loc.isa<mlir::FileLineColLoc>()) {
        auto file = file_loc.cast<mlir::FileLineColLoc>();
        ss << file.getFilename().getValue().str()
           << ":" << file.getLine()
           << ":" << file.getColumn();
      }
      if (file_loc != file_locs.back()) {
        ss << ", ";
      }
    }
    ss << "]";
    return ss.str();
  }
  return "unknown";
}

mx::Decl LongestDefinition(mx::Decl decl) {
  size_t num_toks = 0u;

  for (mx::Decl redecl : decl.redeclarations()) {
    if (decl.is_definition()) {
      if (auto redecl_num_toks = redecl.tokens().size();
          redecl_num_toks > num_toks) {
        decl = redecl;
        num_toks = redecl_num_toks;
      }
    }
  }

  return decl;
}

std::unordered_set<mx::RawEntityId> Uses(mx::SourceIR &ir, const mlir::Operation *op) {
  std::unordered_set<mx::RawEntityId> uses_set;
  for (auto &uses : (const_cast<mlir::Operation*>(op))->getUses()) {
    if (auto decl = ir.declaration_for(const_cast<const mlir::Operation*>(uses.getOwner())); decl) {
      uses_set.emplace(decl->id().Pack());
    } else if (auto stmt = ir.statement_for(const_cast<const mlir::Operation*>(uses.getOwner())); stmt) {
      uses_set.emplace(stmt->id().Pack());
    }
  }
  return uses_set;
}

std::string Stringify(std::unordered_set<mx::RawEntityId> uses) {
  std::stringstream ss;
  ss << "[";
  for (auto use: uses) {
      ss << use << ",";
  }
  auto result = ss.str().substr(0, ss.str().size()-1) + "]";
  return result;
}

}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0] << " [--db DATABASE]";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  SeenSet seen;
  WorkList wl;

  mx::Index index = InitExample();

  for (mx::File file : index.files()) {
    for (mx::Fragment frag : file.fragments()) {
      for (mx::FunctionDecl func : mx::FunctionDecl::in(frag)) {
        wl.emplace_back(LongestDefinition(func));
      }
    }
  }

  std::cout << "{\n";
  auto sep = "";

  while (!wl.empty()) {
    std::string str;
    llvm::raw_string_ostream os(str);
    mx::Decl decl = std::move(wl.back());
    wl.pop_back();

    if (seen.emplace(decl.id()).second) {
      os << sep;
      sep = ",\n";

      mx::Fragment frag = mx::Fragment::containing(decl);
      os << '"' << frag.id().Pack() << "\": ";

      llvm::json::Object obj;
      if (auto ir = frag.ir(); ir) {
        // Add entity id to the json
        obj["entity_id"] = decl.id().Pack();

        auto range = ir->for_declaration(decl);
        if (!range.has_value()) {
          continue;
        }

        for (auto iter = range.begin(); iter != range.end(); iter++) {
          auto func_op = *iter;
          auto name = const_cast<mlir::Operation*>(func_op.get())->getName();
          (void)name;
          obj["operation"] = name.getIdentifier().str();

          auto loc = const_cast<mlir::Operation*>(func_op.get())->getLoc();
          obj["meta_id"] = MetaId(loc);
          obj["loc"] = LocationString(loc);

          if (auto vast_symbol = mlir::dyn_cast<vast_symbol_interface>(func_op.get()); vast_symbol) {
            obj["name"] = SymbolName(vast_symbol);
            auto type = vast_symbol->getAttr("function_type");
            obj["function_type"]= AttributeString(type);

          } else if (auto mlir_symbol = mlir::dyn_cast<mlir_symbol_interface>(func_op.get()); mlir_symbol) {
            obj["name"] = SymbolName(mlir_symbol);
            auto type = mlir_symbol->getAttr("function_type");
            obj["function_type"]= AttributeString(type);

          }
          auto uses_set = Uses(*ir, func_op.get());
          if (!uses_set.empty()) {
            obj["uses"] = Stringify(uses_set);
          }
        }
      }
      llvm::json::Value val(std::move(obj));
      os << std::move(val);
    }
    std::cout << str;
  }

  std::cout << "\n}";

  return EXIT_SUCCESS;
}

