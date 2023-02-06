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
#include <set>
#include <vector>
#include <unordered_map>

#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>

#include "Index.h"
#include <multiplier/AST.h>

DEFINE_uint32(tab_width, 4, "Number of spaces in a tab");

using SeenSet = std::set<mx::PackedDeclId>;
using WorkList = std::vector<mx::Decl>;

// Sometimes we see two separate definitions of an entity, e.g.
//
// `typedef void CURL;` and `typedef struct { ... } CURL;` where the former
// is an opaque, exported type, and the latter is the internal type. We want
// to find the internal version.
static mx::Decl LongestDefinition(mx::Decl decl) {
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

static void DumpDeclToJSON(llvm::json::Object &obj, mx::Decl decl,
                           WorkList &wl);
static void DumpTypeToJSON(llvm::json::Object &obj, mx::Type type,
                           WorkList &wl);

static void DumpBuiltinTypeToJSON(llvm::json::Object &obj,
                                  mx::BuiltinType type,
                                  WorkList &) {
  obj["builtin_kind"] = mx::EnumeratorName(type.builtin_kind());
}

static void DumpPointerTypeToJSON(llvm::json::Object &obj,
                                  mx::PointerType type,
                                  WorkList &wl) {
  llvm::json::Object pointee_o;
  if (auto pt = type.pointee_type()) {
    DumpTypeToJSON(pointee_o, std::move(pt.value()), wl);
  }
  llvm::json::Value pointee_v(std::move(pointee_o));
  obj["pointee_type"] = std::move(pointee_v);
}

static void DumpArrayTypeToJSON(llvm::json::Object &obj,
                                mx::ArrayType type,
                                WorkList &wl) {
  llvm::json::Object elem_o;
  DumpTypeToJSON(elem_o, type.element_type(), wl);

  llvm::json::Value elem_v(std::move(elem_o));
  obj["element_type"] = std::move(elem_v);
}

template <typename T>
static void DumpIndirectTypeToJSON(llvm::json::Object &obj,
                                   T type, WorkList &wl) {
  DumpTypeToJSON(obj, type.underlying_type(), wl);
}

static void DumpElaboratedTypeToJSON(llvm::json::Object &obj,
                                     mx::ElaboratedType type, WorkList &wl) {
  DumpTypeToJSON(obj, type.named_type(), wl);
}

void DumpTypeToJSON(llvm::json::Object &obj, mx::Type type,
                    WorkList &wl) {

  llvm::json::Array qualifiers_a;

  if (type.is_const_qualified()) {
    qualifiers_a.push_back("const");
  }
  if (type.is_volatile_qualified()) {
    qualifiers_a.push_back("volatile");
  }
  if (type.is_restrict_qualified()) {
    qualifiers_a.push_back("restrict");
  }

  if (!qualifiers_a.empty()) {
    llvm::json::Value qualifiers_v(std::move(qualifiers_a));
    obj["qualifiers"] = std::move(qualifiers_v);
  }

  obj["kind"] = mx::EnumeratorName(type.kind());

  if (auto builtin = mx::BuiltinType::from(type)) {
    DumpBuiltinTypeToJSON(obj, std::move(builtin.value()), wl);

  } else if (auto ptr = mx::PointerType::from(type)) {
    DumpPointerTypeToJSON(obj, std::move(ptr.value()), wl);

  } else if (auto arr = mx::ArrayType::from(type)) {
    DumpArrayTypeToJSON(obj, std::move(arr.value()), wl);

  } else if (auto tag = mx::TagType::from(type)) {
    mx::Decl ref_decl = LongestDefinition(tag->declaration());
    obj["decl_id"] = std::to_string(ref_decl.id().Pack());
    wl.emplace_back(std::move(ref_decl));

  } else if (auto td = mx::TypedefType::from(type)) {
    mx::Decl ref_decl = LongestDefinition(td->declaration());
    obj["decl_id"] = std::to_string(ref_decl.id().Pack());
    wl.emplace_back(std::move(ref_decl));

  } else if (auto td2 = mx::MacroQualifiedType::from(type)) {
    DumpIndirectTypeToJSON(obj, std::move(td2.value()), wl);

  } else if (auto td3 = mx::DecltypeType::from(type)) {
    DumpIndirectTypeToJSON(obj, std::move(td3.value()), wl);

  } else if (auto td4 = mx::UsingType::from(type)) {
    DumpIndirectTypeToJSON(obj, std::move(td4.value()), wl);

  } else if (auto td5 = mx::UnaryTransformType::from(type)) {
    DumpIndirectTypeToJSON(obj, std::move(td5.value()), wl);

  } else if (auto td6 = mx::TypeOfType::from(type)) {
    DumpIndirectTypeToJSON(obj, std::move(td6.value()), wl);

  } else if (auto el = mx::ElaboratedType::from(type)) {
    DumpElaboratedTypeToJSON(obj, std::move(el.value()), wl);
  }
}

static void DumpVarDeclToJSON(llvm::json::Object &obj, mx::VarDecl decl,
                              WorkList &wl) {
  llvm::json::Object type_o;
  DumpTypeToJSON(type_o, decl.type(), wl);
  llvm::json::Value type_v(std::move(type_o));
  obj["type"] = std::move(type_v);
}

static void DumpFieldDeclToJSON(llvm::json::Object &obj, mx::FieldDecl decl,
                                WorkList &wl) {
  llvm::json::Object type_o;
  DumpTypeToJSON(type_o, decl.type(), wl);
  llvm::json::Value type_v(std::move(type_o));
  obj["type"] = std::move(type_v);
}

static void DumpRecordDeclToJSON(llvm::json::Object &obj, mx::RecordDecl decl,
                                 WorkList &wl) {
  llvm::json::Array fields_a;
  for (mx::FieldDecl field : decl.fields()) {
    llvm::json::Object field_o;
    DumpDeclToJSON(field_o, field, wl);

    llvm::json::Value field_v(std::move(field_o));
    fields_a.push_back(std::move(field_v));
  }

  if (decl.is_definition() || !fields_a.empty()) {
    llvm::json::Value fields_v(std::move(fields_a));
    obj["fields"] = std::move(fields_v);
  }
}

static void DumpEnumDeclToJSON(llvm::json::Object &obj, mx::EnumDecl decl,
                               WorkList &wl) {
  if (std::optional<mx::Type> it = decl.integer_type()) {
    llvm::json::Object type_o;
    DumpTypeToJSON(type_o, std::move(it.value()), wl);

    llvm::json::Value type_v(std::move(type_o));
    obj["integer_type"] = std::move(type_v);
  }
}

static void DumpTypedefNameDeclToJSON(llvm::json::Object &obj,
                                      mx::TypedefNameDecl decl,
                                      WorkList &wl) {
  llvm::json::Object type_o;
  DumpTypeToJSON(type_o, decl.underlying_type(), wl);

  llvm::json::Value type_v(std::move(type_o));
  obj["underlying_type"] = std::move(type_v);
}

static void DumpFunctionDeclToJSON(llvm::json::Object &obj,
                                   mx::FunctionDecl decl,
                                   WorkList &wl) {
  llvm::json::Object ret_type_o;
  DumpTypeToJSON(ret_type_o, decl.return_type(), wl);
  llvm::json::Value ret_type_v(std::move(ret_type_o));
  obj["return_type"] = std::move(ret_type_v);

  llvm::json::Array params_a;
  for (mx::ParmVarDecl param : decl.parameters()) {
    llvm::json::Object param_o;
    DumpDeclToJSON(param_o, param, wl);

    llvm::json::Value param_v(std::move(param_o));
    params_a.push_back(std::move(param_v));
  }

  llvm::json::Value params_v(std::move(params_a));
  obj["parameters"] = std::move(params_v);
  obj["is_variadic"] = decl.is_variadic();
}

void DumpDeclToJSON(llvm::json::Object &obj, mx::Decl decl,
                    WorkList &wl) {
  if (auto nd = mx::NamedDecl::from(decl)) {
    std::string name_s(nd->name().data(), nd->name().size());
    obj["name"] = std::move(name_s);
  }

  if (auto func = mx::FunctionDecl::from(decl)) {
    DumpFunctionDeclToJSON(obj, std::move(func.value()), wl);

  } else if (auto var = mx::VarDecl::from(decl)) {
    DumpVarDeclToJSON(obj, std::move(var.value()), wl);

  } else if (auto field = mx::FieldDecl::from(decl)) {
    DumpFieldDeclToJSON(obj, std::move(field.value()), wl);

  } else if (auto record = mx::RecordDecl::from(decl)) {
    DumpRecordDeclToJSON(obj, std::move(record.value()), wl);

  } else if (auto ed = mx::EnumDecl::from(decl)) {
    DumpEnumDeclToJSON(obj, std::move(ed.value()), wl);

  } else if (auto td = mx::TypedefNameDecl::from(decl)) {
    DumpTypedefNameDeclToJSON(obj, std::move(td.value()), wl);
  }
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--db DATABASE]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(true);

  SeenSet seen;
  WorkList wl;

  mx::FileLocationConfiguration config;
  config.tab_width = FLAGS_tab_width;

  mx::FileLocationCache cache(config);

  // Go find all functions.
  for (mx::File file : index.files()) {
    for (mx::Fragment frag : file.fragments()) {
      for (mx::FunctionDecl func : mx::FunctionDecl::in(frag)) {
        wl.emplace_back(LongestDefinition(func));
      }
    }
  }

  llvm::outs() << "{\n";
  auto sep = "";

  while (!wl.empty()) {
    mx::Decl decl = std::move(wl.back());
    wl.pop_back();

    if (seen.emplace(decl.id()).second) {
      llvm::outs() << sep;
      sep = ",\n";

      mx::Fragment frag = mx::Fragment::containing(decl);
      llvm::outs() << '"' << decl.id().Pack() << "\": ";

      llvm::json::Object obj;
      obj["kind"] = mx::EnumeratorName(decl.kind());

      if (auto file = mx::File::containing(frag)) {
        auto file_path = file_paths.find(file->id());
        obj["file"] = file_path->second.generic_string();
        if (auto line_col = decl.token().nearest_location(cache)) {
          obj["line"] = line_col->first;
          obj["column"] = line_col->second;
        }
      }

      DumpDeclToJSON(obj, std::move(decl), wl);

      llvm::json::Value val(std::move(obj));
      llvm::outs() << std::move(val);
    }
  }

  llvm::outs() << "\n}";

  return EXIT_SUCCESS;
}
