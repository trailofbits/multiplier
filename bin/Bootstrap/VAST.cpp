// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#ifdef MX_IN_BOOTSTRAP

#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/IR/BuiltinAttributes.h>
#include <mlir/IR/SymbolTable.h>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/ABI/ABIDialect.hpp>
#include <vast/Dialect/ABI/ABIOps.hpp>
#include <vast/Dialect/Core/CoreDialect.hpp>
#include <vast/Dialect/Core/CoreOps.hpp>
#include <vast/Dialect/Core/CoreTypes.hpp>
#include <vast/Dialect/HighLevel/HighLevelDialect.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelTypes.hpp>
#include <vast/Dialect/LowLevel/LowLevelDialect.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>
#include <vast/Dialect/Meta/MetaDialect.hpp>
#include <vast/Dialect/Meta/MetaAttributes.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>
#include <vast/Dialect/Unsupported/UnsupportedDialect.hpp>
#include <vast/Dialect/Unsupported/UnsupportedOps.hpp>
#include <vast/Dialect/Unsupported/UnsupportedTypes.hpp>
#include <vast/Util/DataLayout.hpp>

#else

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Macro.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "Bootstrap.h"

struct Op {
  std::string root_ns;
  std::string ns;
  std::string_view op_name;
  std::string name;
  pasta::CXXRecordDecl cls;
  std::vector<pasta::CXXMethodDecl> methods;
  std::vector<std::string_view> attributes;

  inline Op(const pasta::CXXRecordDecl &cls_)
      : cls(cls_) {}
};

struct Type {
  std::string root_ns;
  std::string ns;
  std::string_view mnemonic;
  std::string name;
  pasta::CXXRecordDecl cls;
  std::vector<pasta::CXXMethodDecl> methods;
  std::vector<pasta::CXXMethodDecl> datalayout_methods;

  inline Type(const pasta::CXXRecordDecl &cls_)
      : cls(cls_) {}
};

struct Attr {
  std::string root_ns;
  std::string ns;
  std::string_view mnemonic;
  std::string name;
  pasta::CXXRecordDecl cls;
  std::vector<pasta::CXXMethodDecl> methods;

  inline Attr(const pasta::CXXRecordDecl &cls_)
      : cls(cls_) {}
};

class CodeGenerator {
 private:

  std::vector<Op> ops;
  std::vector<Type> types;
  std::vector<Attr> attrs;
  std::set<const void *> seen_decls;

  std::map<std::string, std::string> included_by;
  std::map<std::string, std::map<uint64_t, std::string>> include_paths;

  void RunOnOpClass(const std::string &root_ns, const std::string &ns,
                    const pasta::CXXRecordDecl &cls,
                    std::vector<pasta::CXXMethodDecl> methods,
                    std::vector<std::string_view> attributes,
                    std::string_view op_name);

  void RunOnAttrClass(const std::string &root_ns, const std::string &ns,
                      const pasta::CXXRecordDecl &cls,
                      std::vector<pasta::CXXMethodDecl> methods,
                      std::string_view op_name);

  void RunOnTypeClass(const std::string &root_ns, const std::string &ns,
                      const pasta::CXXRecordDecl &cls,
                      std::vector<pasta::CXXMethodDecl> methods,
                      std::vector<pasta::CXXMethodDecl> dl_methods,
                      std::string_view op_name);

  void RunOnClasses(const std::string &root_ns, const std::string &ns,
                    std::vector<pasta::CXXRecordDecl> classes);
  void RunOnEnums(const std::string &root_ns, const std::string &ns,
                  std::vector<pasta::EnumDecl> enums);
  void RunOnNamespace(const pasta::NamespaceDecl &root_ns,
                      pasta::NamespaceDecl ns);

  void FillIncludePathsFor(const pasta::CXXRecordDecl &cls);
  void RunOnTranslationUnit(pasta::TranslationUnitDecl tu);
  void FindIncludePaths(pasta::MacroRange macros, pasta::File main_file);
  std::string TopIncludePath(std::string path);
 public:
  CodeGenerator(char *argv[]);
  void RunOnAST(pasta::AST ast);

  void Summarize(void);
  void RunOnOps(void);
  void RunOnTypes(void);
  void RunOnAttrs(void);
};

static std::string MethodName(const std::string &name) {
  std::string capital_name = Capitalize(name);

  if (capital_name.starts_with("Get") && !capital_name.starts_with("Gets")) {
    capital_name = capital_name.substr(3u);
  }

  return CapitalCaseToSnakeCase(capital_name);
}

static std::optional<pasta::Decl> GetDefinition(const pasta::NamedDecl &decl) {
  if (auto r = pasta::RecordDecl::From(decl)) {
    if (auto d = r->Definition()) {
      return d.value();
    }
    return decl;
  } else if (auto f = pasta::FunctionDecl::From(decl)) {
    if (auto d = f->Definition()) {
      return d.value();
    }
    return decl;
  } else if (pasta::TypedefNameDecl::From(decl)) {
    return decl;
  }

  return std::nullopt;
}

//// MLIR's TableGen produces `.h.inc` files, and often the `.h` actually includes
//// the `.h
//static std::filesystem::path FixupPath(std::filesystem::path p) {
//  if (p.extension() != ".inc") {
//    return p;
//  }
//
//  std::filesystem::path np = p;
//  np = np.replace_extension();
//
//  if (np.extension() == ".h" && std::filesystem::exists(np)) {
//    return np;
//  }
//
//  return p;
//}

// Calculate a relative path given an absolute path. We want relative paths
// located inside of Clang, LLVM, MLIR, or VAST.
static std::string RelativePath(std::filesystem::path file_path) {
  std::filesystem::path path;
  int seen_include = 0;
  for (auto part : file_path) {
    if (seen_include == 1) {
      if (part != "mlir" && part != "clang" && part != "llvm" && part != "vast") {
        return {};
      }
      path = part;
      ++seen_include;
    } else if (seen_include) {
      path /= part;
    } else if (part == "include") {
      seen_include = 1;
    }
  }

  if (seen_include < 2) {
    return {};
  }

  return path.generic_string();
//  return FixupPath(path).generic_string();
}

static std::string IncludePathFor(const pasta::NamedDecl &cls_) {
  auto def = GetDefinition(cls_);
  if (!def) {
    return {};
  }

  pasta::Decl cls = std::move(def.value());
  for (pasta::Token tok : cls.Tokens()) {
    std::optional<pasta::FileToken> ftok = tok.FileLocation();
    if (!ftok) {
      continue;
    }

    return RelativePath(pasta::File::Containing(ftok.value()).Path());
  }

  return {};
}

void CodeGenerator::FillIncludePathsFor(const pasta::CXXRecordDecl &cls) {

  std::set<std::string> seen;

  std::string cls_path = IncludePathFor(cls);
  if (cls_path.empty()) {
    return;
  }

  std::map<uint64_t, std::string> &ordered_paths
      = include_paths[cls_path];

  cls_path = TopIncludePath(cls_path);
  seen.insert(cls_path);

  ordered_paths.emplace(cls.Token().Index(), cls_path);

  auto pt = pasta::PrintedTokenRange::Create(cls);

  for (pasta::PrintedToken tok : pt) {
    for (std::optional<pasta::TokenContext> tc = tok.Context();
         tc; tc = tc->Parent()) {
      std::optional<pasta::Decl> tcd = pasta::Decl::From(tc.value());
      if (!tcd) {
        continue;
      }

      std::optional<pasta::NamedDecl> rd = pasta::NamedDecl::From(tcd.value());
      if (!rd) {
        continue;
      }

      std::string rd_path = TopIncludePath(IncludePathFor(rd.value()));
      if (!rd_path.empty() && seen.emplace(rd_path).second) {
        ordered_paths.emplace(rd->Token().Index(), rd_path);
      }
    }
  }
}

//static std::string ClassNameToOpName(std::string name) {
//  if (name.ends_with("Op")) {
//    return name;
//  } else if (name == "vscale") {
//    return "VScaleOp";
//  } else if (name.starts_with("masked_") || name.starts_with("vector_")) {
//    auto uc = true;
//    std::string ret;
//    for (char ch : name) {
//      if (ch == '_') {
//        uc = true;
//        continue;
//      } else if (uc) {
//        uc = false;
//        ret.push_back(static_cast<char>(std::toupper(ch)));
//      } else {
//        ret.push_back(ch);
//      }
//    }
//    ret.push_back('O');
//    ret.push_back('p');
//    return ret;
//  } else {
//    name.push_back('O');
//    name.push_back('p');
//    return name;
//  }
//}

static std::string OpNameToCapitalCase(std::string_view name) {
  if (name.ends_with("Op")) {
    name.remove_suffix(2);
  }

  if (name.starts_with("llvm") || name.starts_with("LLVM")) {
    name.remove_prefix(4);
  }

  if (name.starts_with('_')) {
    name.remove_prefix(1);
  }

  if (std::isupper(name[0])) {
    return std::string(name.begin(), name.end());
  }

  return Capitalize(SnakeCaseToCamelCase(name));
}

static std::string OpNameToEnumCase(std::string_view name) {
  std::string ret;
  for (char ch : name) {
    if (ch == '"') {
      continue;
    } else if (ch == '.') {
      ret.push_back('_');
    } else {
      ret.push_back(static_cast<char>(std::toupper(ch)));
    }
  }
  return ret;
}

static std::string OpNameToSnakeCase(std::string_view name) {
  std::string ret;
  for (char ch : name) {
    if (ch == '"') {
      continue;
    } else if (ch == '.') {
      ret.push_back('_');
    } else {
      ret.push_back(static_cast<char>(std::tolower(ch)));
    }
  }
  return ret;
}

// Try to find the MLIR operation name.
static std::string_view FindName(const pasta::CXXMethodDecl &decl) {
  for (pasta::Token tok : decl.Body()->Tokens()) {
    if (tok.Kind() == pasta::TokenKind::kStringLiteral) {
      return tok.Data();
    }
  }
  return {};
}

// Try to find the MLIR attribute names.
static std::vector<std::string_view> FindNames(
    const pasta::CXXMethodDecl &decl) {
  std::vector<std::string_view> names;
  for (pasta::Token tok : decl.Body()->Tokens()) {
    if (tok.Kind() == pasta::TokenKind::kStringLiteral) {
      names.emplace_back(tok.Data());
    }
  }
  return names;
}

static std::string TokensToString(const pasta::PrintedTokenRange &toks) {
  std::stringstream ss;
  for (pasta::PrintedToken tok : toks) {
    ss << tok.Data();
  }
  return ss.str();
}

struct Dialect {
  std::string_view name;
  std::filesystem::path our_dir_name;
  std::string_view our_ns_name;

  std::string_view ns_key;
  std::string_view root_ns;
  std::string_view ns;
  std::vector<Op *> ops;
  std::vector<Type *> types;
  std::vector<Attr *> attrs;
};

static Dialect gDialects[] = {
  // MLIR.
  {"Builtin", "MLIR/Builtin", "builtin", "mlir", "", "mlir", {}, {}, {}},
  {"LLVMIR", "MLIR/LLVM", "llvm", "mlir::LLVM", "mlir", "LLVM", {}, {}, {}},
  {"MemRef", "MLIR/MemRef", "memref", "mlir::memref", "mlir", "memref", {}, {}, {}},
  
  // TODO(pag): Including this seems to replicate `ModuleOp` and `UnrealizedConversionCastOp`.
  // {"DLTI", "MLIR/DLTI", "dlti", "mlir", "", "mlir", {}, {}, {}},

  // VAST.
  {"ABI", "VAST/ABI", "abi", "vast::abi", "vast", "abi", {}, {}, {}},
  {"LowLevel", "VAST/LL", "ll", "vast::ll", "vast", "ll", {}, {}, {}},
  {"HighLevel", "VAST/HL", "hl", "vast::hl", "vast", "hl", {}, {}, {}},
  {"Core", "VAST/Core", "core", "vast::core", "vast", "core", {}, {}, {}},
  {"Meta", "VAST/Meta", "meta", "vast::meta", "vast", "meta", {}, {}, {}},
  {"Unsupported", "VAST/Unsupported", "unsup", "vast::unsup", "vast", "unsup", {}, {}, {}},
};

class TypeWrapper {
 public:
  virtual ~TypeWrapper(void) {}
  virtual void ReturnType(std::ostream &, const pasta::CXXMethodDecl &) = 0;
  virtual std::string_view CallMethod(std::ostream &, const pasta::CXXMethodDecl &,
                                      const std::string &) {
    return {};
  }
  virtual void Implementation(std::ostream &, const pasta::CXXMethodDecl &,
                              const std::string &indent,
                              std::string_view val) = 0;
};

class IdentityWrapper final : public TypeWrapper {
 private:
  std::string_view type_name;

 public:
  virtual ~IdentityWrapper(void) = default;
  explicit IdentityWrapper(std::string_view type_name_)
      : type_name(type_name_) {}

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &) final {
    os << type_name;
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto val = underlying_op()." << m.Name() << "();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &,
                      const std::string &indent, std::string_view val) final {
    os << indent << "return " << val << ";\n";
  }
};

class OptionalTypeWrapper final : public TypeWrapper {
 private:
  TypeWrapper *next;

 public:
  virtual ~OptionalTypeWrapper(void) = default;

  explicit OptionalTypeWrapper(TypeWrapper *next_)
      : next(next_) {}

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &m) final {
    os << "std::optional<";
    next->ReturnType(os, m);
    os << ">";
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto opt_val = underlying_op()." << m.Name() << "();\n"
       << indent << "if (!opt_val) {\n"
       << indent << "  return std::nullopt;\n"
       << indent << "}\n"
       << indent << "auto &val = opt_val.value();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &m,
                      const std::string &indent, std::string_view val) final {
    next->Implementation(os, m, indent, val);
  }
};

class StringRefWrapper final : public TypeWrapper {
 public:
  virtual ~StringRefWrapper(void) = default;
  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &) final {
    os << "std::string_view";
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto val = underlying_op()." << m.Name() << "();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &,
                      const std::string &indent, std::string_view val) final {
    os
       << indent << "if (auto size = " << val << ".size()) {\n"
       << indent << "  return std::string_view(" << val << ".data(), size);\n"
       << indent << "} else {\n"
       << indent << "  return {};\n"
       << indent << "}\n";
  }
};

class ValueWrapper final : public TypeWrapper {
 public:
  virtual ~ValueWrapper(void) = default;

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &m) final {
    if (m.Name().ends_with("result")) {
      os << "::mx::ir::Result";
    } else {
      os << "::mx::ir::Value";
    }
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto val = underlying_op()." << m.Name() << "();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &m,
                      const std::string &indent, std::string_view val) final {
    if (m.Name().ends_with("result")) {
      os << indent << "return ::mx::ir::Result(module_, " << val
         << ".getAsOpaquePointer());\n";
    } else {
      os << indent << "return ::mx::ir::Value(module_, " << val
         << ".getAsOpaquePointer());\n";
    }
  }
};

class RegionWrapper final : public TypeWrapper {
 public:
  virtual ~RegionWrapper(void) = default;

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &) final {
    os << "::mx::ir::Region";
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto &val = underlying_op()." << m.Name() << "();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &m,
                      const std::string &indent, std::string_view val) final {
    os << indent << "return ::mx::ir::Region(module_, " << val << ");\n";
  }
};

class BlockWrapper final : public TypeWrapper {
 public:
  virtual ~BlockWrapper(void) = default;

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &) final {
    os << "::mx::ir::Block";
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto &val = underlying_op()." << m.Name() << "();\n";
    return "val";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &,
                      const std::string &indent, std::string_view val) final {
    os << indent << "return ::mx::ir::Block(module_, "<< val << ");\n";
  }
};

class ValueGeneratorWrapper final : public TypeWrapper {
 private:
  std::string_view type_name;

 public:
  virtual ~ValueGeneratorWrapper(void) = default;
  explicit ValueGeneratorWrapper(std::string_view type_name_)
      : type_name(type_name_) {}

  void ReturnType(std::ostream &os, const pasta::CXXMethodDecl &) final {
    os << "gap::generator<" << type_name << ">";
  }

  std::string_view CallMethod(std::ostream &os, const pasta::CXXMethodDecl &m,
                              const std::string &indent) {
    os << indent << "auto range = underlying_op()." << m.Name() << "();\n";
    return "range";
  }

  void Implementation(std::ostream &os, const pasta::CXXMethodDecl &m,
                      const std::string &indent, std::string_view val) final {
    os << indent << "for (auto val : " << val << ") {\n"
       << indent << "  co_yield " << type_name << "(module_, val.getAsOpaquePointer());\n"
       << indent << "}\n";
  }
};

#define IDENTITY_WRAPPER(t) {#t, new IdentityWrapper(#t)}

static std::unordered_map<std::string, TypeWrapper *> gReturnType{
  IDENTITY_WRAPPER(bool),
  IDENTITY_WRAPPER(char),
  IDENTITY_WRAPPER(short),
  IDENTITY_WRAPPER(int),
  IDENTITY_WRAPPER(long),
  IDENTITY_WRAPPER(long long),
  IDENTITY_WRAPPER(unsigned char),
  IDENTITY_WRAPPER(unsigned short),
  IDENTITY_WRAPPER(unsigned int),
  IDENTITY_WRAPPER(unsigned),
  IDENTITY_WRAPPER(unsigned long),
  IDENTITY_WRAPPER(unsigned long long),
  IDENTITY_WRAPPER(float),
  IDENTITY_WRAPPER(double),
  IDENTITY_WRAPPER(int8_t),
  IDENTITY_WRAPPER(int16_t),
  IDENTITY_WRAPPER(int32_t),
  IDENTITY_WRAPPER(int64_t),
  IDENTITY_WRAPPER(uint8_t),
  IDENTITY_WRAPPER(uint16_t),
  IDENTITY_WRAPPER(uint32_t),
  IDENTITY_WRAPPER(uint64_t),
  IDENTITY_WRAPPER(std::string),
  IDENTITY_WRAPPER(std::string_view),
  {"::llvm::StringRef", new StringRefWrapper},
  {"::mlir::Value", new ValueWrapper},
  {"::mlir::Region&", new RegionWrapper},
  {"::mlir::Block&", new BlockWrapper},
  {"::mlir::mlir::Operation::result_range", new ValueGeneratorWrapper("::mx::ir::Result")},
  {"::mlir::mlir::Operation::operand_range", new ValueGeneratorWrapper("::mx::ir::Operand")},
  {"::std::optional<::llvm::StringRef>", new OptionalTypeWrapper(new StringRefWrapper)},
  {"std::optional<StringRef>", new OptionalTypeWrapper(new StringRefWrapper)},
//  {"::mlir::Attribute", "::mx::ir::Attribute"},
//  {"::mlir::Value", "::mx::ir::Value"},
//  {"::mlir::Type", "::mx::ir::Type"},
//  {"::llvm::StringRef", "std::string_view"},
//  {"std::string_view", "std::string_view"},
//  {"std::string", "std::string_view"},
//  {"::mlir::Region&", "::mx::ir::Region"},
//  {"::std::optional<::mlir::Attribute>", "std::optional<::mx::ir::Attribute>"},
//  {"::std::optional<::mlir::Value>", "std::optional<::mx::ir::Value>"},
//  {"::std::optional<::mlir::Type>", "std::optional<::mx::ir::Type>"},
//  {"::std::optional<::llvm::StringRef>", "std::optional<std::string_view>"},
//  {"::std::optional<::mlir::Region>", "std::optional<::mx::ir::Region>"},
//  {"bool", "bool"},
//  {"short", "short"},
//  {"int", "int"},
//  {"unsigned", "unsigned"},
//  {"uint8_t", "uint8_t"},
//  {"uint16_t", "uint16_t"},
//  {"uint32_t", "uint32_t"},
//  {"int64_t", "uint64_t"},
//  {"int8_t", "int8_t"},
//  {"int16_t", "int16_t"},
//  {"int32_t", "int32_t"},
//  {"int64_t", "int64_t"},
//  {"::std::optional<unsigned>", "std::optional<unsigned>"},
//  {"::std::optional<uint8_t>", "std::optional<uint8_t>"},
//  {"::std::optional<uint16_t>", "std::optional<uint16_t>"},
//  {"::std::optional<uint32_t>", "std::optional<uint32_t>"},
//  {"::std::optional<int64_t>", "std::optional<uint64_t>"},
//  {"::std::optional<int8_t>", "std::optional<int8_t>"},
//  {"::std::optional<int16_t>", "std::optional<int16_t>"},
//  {"::std::optional<int32_t>", "std::optional<int32_t>"},
//  {"::std::optional<int64_t>", "std::optional<int64_t>"},
};

void CodeGenerator::Summarize(void) {
  for (Dialect &dialect : gDialects) {

    for (Op &op : ops) {
      if (op.root_ns == dialect.root_ns && op.ns == dialect.ns) {
        dialect.ops.push_back(&op);
      }
    }
    for (Type &type : types) {
      if (type.root_ns == dialect.root_ns && type.ns == dialect.ns) {
        dialect.types.push_back(&type);
      }
    }
    for (Attr &attr : attrs) {
      if (attr.root_ns == dialect.root_ns && attr.ns == dialect.ns) {
        dialect.attrs.push_back(&attr);
      }
    }
  }

  for (Dialect &dialect : gDialects) {
    for (Op *op : dialect.ops) {
      FillIncludePathsFor(op->cls);
    }
    for (Type *ty : dialect.types) {
      FillIncludePathsFor(ty->cls);
    }
    for (Attr *attr : dialect.attrs) {
      FillIncludePathsFor(attr->cls);
    }
  }
}

template <typename Ent>
static void DoMethod(const pasta::CXXMethodDecl &meth,
                     std::ostream &hpp, std::ostream &cpp,
                     Ent *ent, std::string_view ent_class_name) {
  std::string meth_name = meth.Name();
  std::string api_name = MethodName(meth_name);
  pasta::Type return_type = meth.ReturnType();
  std::string return_type_str =
      TokensToString(pasta::PrintedTokenRange::Create(return_type));

  TypeWrapper *ret_wrapper = gReturnType[return_type_str];
  if (ret_wrapper) {
    hpp << "  ";
    ret_wrapper->ReturnType(hpp, meth);
    hpp << " " << api_name << "(void) const;\n";

    ret_wrapper->ReturnType(cpp, meth);
    cpp << " " << ent_class_name << "::" << api_name << "(void) const {\n";
    std::string_view val = ret_wrapper->CallMethod(cpp, meth, "  ");
    ret_wrapper->Implementation(cpp, meth, "  ", val);
    cpp << "}\n\n";

  } else {
    hpp << "  //" << return_type_str << " " << api_name
        << "(void) const;\n";
  }
}

void CodeGenerator::RunOnOps(void) {
  // "/Users/pag/Code/multiplier/bin/Bootstrap/VAST.cpp"
  std::filesystem::path file = __FILE__;
  std::filesystem::path mx_root = file.parent_path().parent_path().parent_path();
  std::filesystem::path mx_inc = mx_root / "include" / "multiplier";
  std::filesystem::path mx_lib = mx_root / "lib";

  std::error_code ec;
  (void) std::filesystem::create_directory(mx_inc / "IR", ec);
  (void) std::filesystem::create_directory(mx_lib / "IR", ec);


  std::ofstream summary_irhpp(mx_inc / "IR.h");
  std::ofstream hpp(mx_inc / "IR" / "OperationKind.h");
  std::ofstream cpp(mx_lib / "IR" / "Operation.h");  // In lib.

  summary_irhpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include \"IR/Attribute.h\"\n"
      << "#include \"IR/AttributeKind.h\"\n"
      << "#include \"IR/Block.h\"\n"
      << "#include \"IR/Operation.h\"\n"
      << "#include \"IR/OperationKind.h\"\n"
      << "#include \"IR/Region.h\"\n"
      << "#include \"IR/Type.h\"\n"
      << "#include \"IR/TypeKind.h\"\n"
      << "#include \"IR/Value.h\"\n\n";

  hpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "namespace mx {\n"
      << "namespace ir {\n\n"
      << "enum class OperationKind : unsigned {\n"
      << "  UNKNOWN,\n";

  auto num_ops = 0u;
  for (Dialect &dialect : gDialects) {

    summary_irhpp << "#include \"IR/" << dialect.our_dir_name.generic_string() << "/Dialect.h\"\n";

    std::ofstream dialect_hpp(mx_inc / "IR" / dialect.our_dir_name / "Dialect.h");
    dialect_hpp
        << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#pragma once\n\n";

    for (Attr *attr : dialect.attrs) {
      dialect_hpp << "#include \"" << attr->cls.Name() << ".h\"\n";
    }

    for (Type *type : dialect.types) {
      dialect_hpp << "#include \"" << type->cls.Name() << ".h\"\n";
    }

    for (Op *op : dialect.ops) {
      auto oname = op->op_name;
      oname.remove_prefix(1);
      oname.remove_suffix(1);
      hpp << "  " << OpNameToEnumCase(op->op_name) << ",  // "
          << oname << '\n';
      ++num_ops;

      dialect_hpp << "#include \"" << op->cls.Name() << ".h\"\n";
    }
  }

  hpp
      << "};\n\n"
      << "}  // namespace ir\n\n"
      << "inline static const char *EnumerationName(ir::OperationKind) {\n"
      << "  return \"OperationKind\";\n"
      << "}\n\n"
      << "inline static constexpr unsigned NumEnumerators(ir::OperationKind) {\n"
      << "  return " << num_ops << ";\n"
      << "}\n\n"
      << "const char *EnumeratorName(ir::OperationKind);\n\n"
      << "}  // namespace mx\n";

  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n";

  auto sep = "#define MX_IR_FOR_EACH_MLIR_OP(";

  for (Dialect &dialect : gDialects) {
    cpp << sep << '_' << dialect.our_ns_name;
    sep = ", ";
  }

  cpp << ")";

  for (Dialect &dialect : gDialects) {
    for (Op *op : dialect.ops) {
      cpp << " \\\n   _" << dialect.our_ns_name << "(" << op->op_name << ", OperationKind::"
          << OpNameToEnumCase(op->op_name) << ", " << dialect.ns_key << "::"
          << op->name << ")";
    }
  }

  cpp
      << "\n\n"
      << "#define MX_IR_NUM_MLIR_OPS " << num_ops << "\n\n";

  cpp.close();
  cpp.open(mx_lib / "IR" / "OperationKind.cpp");  // In lib.
  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include <multiplier/IR/OperationKind.h>\n\n"
      << "namespace mx {\n\n"
      << "const char *EnumeratorName(ir::OperationKind kind) {\n"
      << "  switch (kind) {\n"
      << "    default: return \"UNKNOWN\";\n";

  for (Dialect &dialect : gDialects) {
    for (Op *op : dialect.ops) {
      std::string ec = OpNameToEnumCase(op->op_name);
      cpp << "    case ir::OperationKind::" << ec << ": return \"" << ec << "\";\n";
    }
  }

  cpp << "  }\n"
      << "}\n\n"
      << "}  // namespace mx\n";

  for (Dialect &dialect : gDialects) {
    if (dialect.ops.empty()) {
      continue;
    }

    hpp.close();

    std::error_code ec;
    (void) std::filesystem::create_directories(mx_inc / "IR" / dialect.our_dir_name, ec);
    (void) std::filesystem::create_directories(mx_lib / "IR" / dialect.our_dir_name, ec);
    
    hpp.open(mx_inc / "IR" / dialect.our_dir_name / "Operation.h");

    cpp.close();
    cpp.open(mx_lib / "IR" / dialect.our_dir_name / "Operation.cpp");

    hpp
        << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#pragma once\n\n"
        << "#include \"../../Operation.h\"\n\n"
        << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
        << "class Operation : public ::mx::ir::Operation {\n"
        << " public:\n"
        << "  static std::optional<Operation> from(const ::mx::ir::Operation &);\n"
        << "};\n"
        << "static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));\n\n"
        << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";

    cpp
        << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#include <multiplier/IR/" << dialect.our_dir_name.generic_string()
        << "/Operation.h>\n\n"
        << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
        << "std::optional<Operation> Operation::from(const ::mx::ir::Operation &that) {\n"
        << "  switch (that.kind()) {\n"
        << "    default: return std::nullopt;\n";

    auto any = false;
    for (Op *op : dialect.ops) {
      std::string enum_name = OpNameToEnumCase(op->op_name);
      cpp << "    case mx::ir::OperationKind::" << enum_name << ":\n";
      any = true;
    }

    if (any) {
      cpp
          << "      return reinterpret_cast<const Operation &>(that);\n";
    }

    cpp
        << "  }\n"
        << "}\n\n"
        << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";


    for (Op *op : dialect.ops) {
      auto op_name = OpNameToCapitalCase(op->name);

      hpp.close();
      hpp.open(mx_inc / "IR" / dialect.our_dir_name / (op_name + ".h"));

      cpp.close();
      cpp.open(mx_lib / "IR" / dialect.our_dir_name / (op_name + ".cpp"));

      std::string snake_name = OpNameToSnakeCase(op->op_name);
      std::string enum_name = OpNameToEnumCase(op->op_name);

      hpp
          << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
          << "// All rights reserved.\n"
          << "//\n"
          << "// This source code is licensed in accordance with the terms specified in\n"
          << "// the LICENSE file found in the root directory of this source tree.\n\n"
          << "// Auto-generated file; do not modify!\n\n"
          << "#pragma once\n\n"
          << "#include \"Operation.h\"\n\n"
          << "namespace " << dialect.ns_key << " {\n"
          << "class " << op->name << ";\n"
          << "}  // namespace " << dialect.ns_key << "\n"
          << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
          << "class " << op_name << " final : public Operation {\n"
          << " public:\n"
          << "  inline static OperationKind static_kind(void) {\n"
          << "    return OperationKind::" << enum_name
          << ";\n"
          << "  }\n\n"
          << "  static std::optional<" << op_name << "> from(const ::mx::ir::Operation &that);\n"
          << "  static std::optional<" << op_name << "> producing(const ::mx::ir::Value &val);\n\n"
          << "  ::" << dialect.ns_key
          << "::" << op->name << " underlying_op(void) const noexcept;\n\n"
          << "  // Imported methods:\n";

      cpp
          << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
          << "// All rights reserved.\n"
          << "//\n"
          << "// This source code is licensed in accordance with the terms specified in\n"
          << "// the LICENSE file found in the root directory of this source tree.\n\n"
          << "// Auto-generated file; do not modify!\n\n"
          << "#include <multiplier/IR/" << dialect.our_dir_name.generic_string()
          << "/" << op_name << ".h>\n"
          << "#include <multiplier/IR/Attribute.h>\n"
          << "#include <multiplier/IR/Block.h>\n"
          << "#include <multiplier/IR/Region.h>\n"
          << "#include <multiplier/IR/Type.h>\n\n";

      std::set<std::string> seen;
      for (const auto &[id, path] : include_paths[IncludePathFor(op->cls)]) {
        if (seen.emplace(path).second) {
          cpp << "#include <" << path << ">\n";
        }
      }

      cpp
          << "\n"
          << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
          << "std::optional<" << op_name << "> " << op_name
          << "::from(const ::mx::ir::Operation &that) {\n"
          << "  if (that.kind() == OperationKind::" << enum_name << ") {\n"
          << "    return reinterpret_cast<const " << op_name << " &>(that);\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n"
          << "std::optional<" << op_name << "> " << op_name
          << "::producing(const ::mx::ir::Value &that) {\n"
          << "  if (auto op = ::mx::ir::Operation::producing(that)) {\n"
          << "    return from(op.value());\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n"
          << "::" << dialect.ns_key << "::" << op->name
          << " " << op_name << "::underlying_op(void) const noexcept {\n"
          << "  return ::" << dialect.ns_key << "::" << op->name << "(this->Operation::op_);\n"
          << "}\n\n";

      for (const pasta::CXXMethodDecl &meth : op->methods) {
        DoMethod(meth, hpp, cpp, op, op_name);
      }

      hpp
          << "};\n"
          << "static_assert(sizeof(" << op_name << ") == sizeof(Operation));\n\n"
          << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";

      cpp
          << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";
    }
  }
}

static std::string TypeNameToSnakeCase(std::string_view type_name) {
  if (type_name.ends_with("Type")) {
    type_name.remove_suffix(4);
  }

  return CapitalCaseToSnakeCase(type_name);
}

static std::string TypeNameToEnumCase(std::string_view type_name) {
  return OpNameToEnumCase(TypeNameToSnakeCase(type_name));
}

void CodeGenerator::RunOnTypes(void) {
  // "/Users/pag/Code/multiplier/bin/Bootstrap/VAST.cpp"
  std::filesystem::path file = __FILE__;
  std::filesystem::path mx_root = file.parent_path().parent_path().parent_path();
  std::filesystem::path mx_inc = mx_root / "include" / "multiplier";
  std::filesystem::path mx_lib = mx_root / "lib";

  std::ofstream hpp(mx_inc / "IR" / "TypeKind.h");
  std::ofstream cpp(mx_lib / "IR" / "Type.h");  // In lib.

  hpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "namespace mx {\n"
      << "namespace ir {\n\n"
      << "enum class TypeKind : unsigned {\n"
      << "  UNKNOWN,\n";

  auto num_types = 0u;
  for (Dialect &dialect : gDialects) {
    for (Type *type : dialect.types) {
      hpp << "  " << TypeNameToEnumCase(type->name) << ",  // "
          << type->mnemonic << '\n';
      ++num_types;
    }
  }

  hpp
      << "};\n\n"
      << "}  // namespace ir\n\n"
      << "inline static const char *EnumerationName(ir::TypeKind) {\n"
      << "  return \"TypeKind\";\n"
      << "}\n\n"
      << "inline static constexpr unsigned NumEnumerators(ir::TypeKind) {\n"
      << "  return " << num_types << ";\n"
      << "}\n\n"
      << "const char *EnumeratorName(ir::TypeKind);\n\n"
      << "}  // namespace mx\n";

  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n";

  auto sep = "#define MX_IR_FOR_EACH_MLIR_TYPE(";

  for (Dialect &dialect : gDialects) {
    cpp << sep << '_' << dialect.our_ns_name;
    sep = ", ";
  }

  cpp << ")";

  for (Dialect &dialect : gDialects) {
    for (Type *type : dialect.types) {
      cpp << " \\\n   _" << dialect.our_ns_name << "(" << type->name << ", TypeKind::"
          << TypeNameToEnumCase(type->name) << ", " << dialect.ns_key << "::"
          << type->name << ")";
    }
  }

  cpp
      << "\n\n"
      << "#define MX_IR_NUM_MLIR_TYPES " << num_types << "\n\n";

  cpp.close();
  cpp.open(mx_lib / "IR" / "TypeKind.cpp");  // In lib.
  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include <multiplier/IR/TypeKind.h>\n\n"
      << "namespace mx {\n\n"
      << "const char *EnumeratorName(ir::TypeKind kind) {\n"
      << "  switch (kind) {\n"
      << "    default: return \"UNKNOWN\";\n";

  for (Dialect &dialect : gDialects) {
    for (Type *type : dialect.types) {
      std::string ec = TypeNameToEnumCase(type->name);
      cpp << "    case ir::TypeKind::" << ec << ": return \"" << ec << "\";\n";
    }
  }

  cpp << "  }\n"
      << "}\n\n"
      << "}  // namespace mx\n";


  for (const Dialect &dialect : gDialects) {
    hpp.close();
    hpp.open(mx_inc / "IR" / dialect.our_dir_name / "Type.h");

    cpp.close();
    cpp.open(mx_lib / "IR" / dialect.our_dir_name / "Type.cpp");

    hpp
        << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#pragma once\n\n"
        << "#include \"../../Type.h\"\n\n"
        << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
        << "class Type : public ::mx::ir::Type {\n"
        << " public:\n"
        << "  static std::optional<Type> from(const ::mx::ir::Type &);\n"
        << "};\n"
        << "static_assert(sizeof(Type) == sizeof(::mx::ir::Type));\n\n"
        << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";

    cpp
        << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
        << "// All rights reserved.\n"
        << "//\n"
        << "// This source code is licensed in accordance with the terms specified in\n"
        << "// the LICENSE file found in the root directory of this source tree.\n\n"
        << "// Auto-generated file; do not modify!\n\n"
        << "#include <multiplier/IR/" << dialect.our_dir_name.generic_string()
        << "/Type.h>\n\n"
        << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
        << "std::optional<Type> Type::from(const ::mx::ir::Type &that) {\n"
        << "  switch (that.kind()) {\n"
        << "    default: return std::nullopt;\n";

    auto any = false;
    for (Type *type : dialect.types) {
      std::string enum_name = TypeNameToEnumCase(type->name);
      cpp << "    case mx::ir::TypeKind::" << enum_name << ":\n";
      any = true;
    }

    if (any) {
      cpp
          << "      return reinterpret_cast<const Type &>(that);\n";
    }

    cpp
        << "  }\n"
        << "}\n\n"
        << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";

    for (Type *type : dialect.types) {
      hpp.close();
      hpp.open(mx_inc / "IR" / dialect.our_dir_name / (type->name + ".h"));

      cpp.close();
      cpp.open(mx_lib / "IR" / dialect.our_dir_name / (type->name + ".cpp"));

      std::string enum_name = TypeNameToEnumCase(type->name);

      hpp
          << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
          << "// All rights reserved.\n"
          << "//\n"
          << "// This source code is licensed in accordance with the terms specified in\n"
          << "// the LICENSE file found in the root directory of this source tree.\n\n"
          << "// Auto-generated file; do not modify!\n\n"
          << "#pragma once\n\n"
          << "#include \"Type.h\"\n\n"
          << "namespace " << dialect.ns_key << " {\n"
          << "class " << type->name << ";\n"
          << "}  // namespace " << dialect.ns_key << "\n"
          << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
          << "class " << type->name << " final : public Type {\n"
          << " public:\n"
          << "  inline static TypeKind static_kind(void) {\n"
          << "    return TypeKind::" << enum_name
          << ";\n"
          << "  }\n\n"
          << "  static std::optional<" << type->name << "> from(const ::mx::ir::Type &that);\n"
          << "  ::" << dialect.ns_key
          << "::" << type->name << " underlying_type(void) const noexcept;\n\n"
          << "  // Imported methods:\n";

      cpp
          << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
          << "// All rights reserved.\n"
          << "//\n"
          << "// This source code is licensed in accordance with the terms specified in\n"
          << "// the LICENSE file found in the root directory of this source tree.\n\n"
          << "// Auto-generated file; do not modify!\n\n"
          << "#include <multiplier/IR/" << dialect.our_dir_name.generic_string()
          << "/" << type->name << ".h>\n"
          << "#include <multiplier/IR/Attribute.h>\n"
          << "#include <multiplier/IR/Type.h>\n\n";

      std::set<std::string> seen;
      for (const auto &[id, path] : include_paths[IncludePathFor(type->cls)]) {
        if (seen.emplace(path).second) {
          cpp << "#include <" << path << ">\n";
        }
      }

      cpp
          << "\n"
          << "namespace mx::ir::" << dialect.our_ns_name << " {\n"
          << "std::optional<" << type->name << "> " << type->name
          << "::from(const ::mx::ir::Type &that) {\n"
          << "  if (that.kind() == TypeKind::" << enum_name << ") {\n"
          << "    return reinterpret_cast<const " << type->name << " &>(that);\n"
          << "  }\n"
          << "  return std::nullopt;\n"
          << "}\n\n"
          << "::" << dialect.ns_key << "::" << type->name
          << " " << type->name << "::underlying_type(void) const noexcept {\n"
          << "  return ::" << dialect.ns_key << "::" << type->name << "(this->Type::type_);\n"
          << "}\n\n";

      for (const pasta::CXXMethodDecl &meth : type->methods) {
        DoMethod(meth, hpp, cpp, type, type->name);
      }

      hpp
          << "};\n"
          << "static_assert(sizeof(" << type->name << ") == sizeof(Type));\n\n"
          << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";

      cpp
          << "}  // namespace mx::ir::" << dialect.our_ns_name << "\n";
    }
  }
}

void CodeGenerator::RunOnAttrs(void) {
  // "/Users/pag/Code/multiplier/bin/Bootstrap/VAST.cpp"
  std::filesystem::path file = __FILE__;
  std::filesystem::path mx_root = file.parent_path().parent_path().parent_path();
  std::filesystem::path mx_inc = mx_root / "include" / "multiplier";
  std::filesystem::path mx_lib = mx_root / "lib";

  std::ofstream hpp(mx_inc / "IR" / "AttributeKind.h");
  std::ofstream cpp(mx_lib / "IR" / "Attribute.h");  // In lib.

  hpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "namespace mx {\n"
      << "namespace ir {\n"
      << "enum class AttributeKind : unsigned {\n"
      << "  UNKNOWN,\n";

  auto num_attrs = 0u;
  for (Dialect &dialect : gDialects) {
    for (Attr *attr : dialect.attrs) {
      hpp << "  " << OpNameToEnumCase(attr->name) << ",\n";
      ++num_attrs;
    }
  }

  hpp
      << "};\n\n"
      << "}  // namespace ir\n\n"
      << "inline static const char *EnumerationName(ir::AttributeKind) {\n"
      << "  return \"AttributeKind\";\n"
      << "}\n\n"
      << "inline static constexpr unsigned NumEnumerators(ir::AttributeKind) {\n"
      << "  return " << num_attrs << ";\n"
      << "}\n\n"
      << "const char *EnumeratorName(ir::AttributeKind);\n\n"
      << "}  // namespace mx\n";

  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n";

  auto sep = "#define MX_IR_FOR_EACH_MLIR_ATTRIBUTE(";

  for (Dialect &dialect : gDialects) {
    cpp << sep << '_' << dialect.our_ns_name;
    sep = ", ";
  }

  cpp << ")";

  for (Dialect &dialect : gDialects) {
    for (Attr *attr : dialect.attrs) {
      cpp << " \\\n   _" << dialect.our_ns_name << "(" << attr->name << ", AttributeKind::"
          << OpNameToEnumCase(attr->name) << ", " << dialect.ns_key << "::"
          << attr->name << ")";
    }
  }

  cpp
      << "\n\n"
      << "#define MX_IR_NUM_MLIR_ATTRIBUTES " << num_attrs << "\n\n";

  cpp.close();
  cpp.open(mx_lib / "IR" / "AttributeKind.cpp");  // In lib.
  cpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include <multiplier/IR/AttributeKind.h>\n\n"
      << "namespace mx {\n\n"
      << "const char *EnumeratorName(ir::AttributeKind kind) {\n"
      << "  switch (kind) {\n"
      << "    default: return \"UNKNOWN\";\n";

  for (Dialect &dialect : gDialects) {
    for (Attr *attr : dialect.attrs) {
      std::string ec = OpNameToEnumCase(attr->name);
      cpp << "    case ir::AttributeKind::" << ec << ": return \"" << ec << "\";\n";
    }
  }

  cpp << "  }\n"
      << "}\n\n"
      << "}  // namespace mx\n";
}

void CodeGenerator::RunOnOpClass(const std::string &root_ns, const std::string &ns,
                                 const pasta::CXXRecordDecl &cls,
                                 std::vector<pasta::CXXMethodDecl> methods,
                                 std::vector<std::string_view> attributes,
                                 std::string_view op_name) {
  Op &op = ops.emplace_back(cls);
  op.root_ns = root_ns;
  op.ns = ns;
  op.name = cls.Name();
  op.op_name = op_name;
  op.methods = std::move(methods);
  op.attributes = std::move(attributes);

//  std::cerr << "OP: " << root_ns << "::" << ns << "::" << cls.Name() << " = "
//            << op_name << '\n';
//  for (const pasta::CXXMethodDecl &meth : methods) {
//    std::string meth_name = meth.Name();
//    std::string api_name = MethodName(meth_name);
//    std::cerr << "\t" << meth_name << " -> " << api_name << '\n';
//  }
}

void CodeGenerator::RunOnTypeClass(
    const std::string &root_ns, const std::string &ns,
    const pasta::CXXRecordDecl &cls, std::vector<pasta::CXXMethodDecl> methods,
    std::vector<pasta::CXXMethodDecl> dl_methods, std::string_view op_name) {

  Type &op = types.emplace_back(cls);
  op.root_ns = root_ns;
  op.ns = ns;
  op.name = cls.Name();
  op.mnemonic = op_name;
  op.methods = std::move(methods);
  op.datalayout_methods = std::move(dl_methods);

//  std::string name = cls.Name();
//  std::cerr << "TYPE: " << root_ns << "::" << ns << "::" << name << " = "
//            << op_name << '\n';
//
//  for (const pasta::CXXMethodDecl &meth : dl_methods) {
//    std::string meth_name = meth.Name();
//    std::string api_name = MethodName(meth_name);
//    std::cerr << "\t" << meth_name << " -> " << api_name << '\n';
//  }
//
//  for (const pasta::CXXMethodDecl &meth : methods) {
//    std::string meth_name = meth.Name();
//    std::string api_name = MethodName(meth_name);
//    std::cerr << "\t" << meth_name << " -> " << api_name << '\n';
//  }
}

void CodeGenerator::RunOnAttrClass(
    const std::string &root_ns, const std::string &ns,
    const pasta::CXXRecordDecl &cls, std::vector<pasta::CXXMethodDecl> methods,
    std::string_view op_name) {

  Attr &op = attrs.emplace_back(cls);
  op.root_ns = root_ns;
  op.ns = ns;
  op.name = cls.Name();
  op.mnemonic = op_name;
  op.methods = std::move(methods);

//  std::string name = cls.Name();
//  std::cerr << "ATTR: " << root_ns << "::" << ns << "::" << name << " = "
//            << op_name << '\n';
//  for (const pasta::CXXMethodDecl &meth : methods) {
//    std::string meth_name = meth.Name();
//    std::string api_name = MethodName(meth_name);
//    std::cerr << "\t" << meth_name << " -> " << api_name << '\n';
//  }
}

static std::unordered_map<std::string, std::string_view> kOpName{
  {"LLVMVoidType", "llvm.void"},
  {"LLVMX86MMXType", "llvm.x86_mmx"},
  {"LLVMPPCFP128Type", "llvm.ppc_fp128"},
  {"LLVMTokenType", "llvm.token"},
  {"LLVMMetadataType", "llvm.metadata"},
  {"LLVMLabelType", "llvm.label"},
  {"LLVMStructType", "llvm.struct"},
};

void CodeGenerator::RunOnClasses(const std::string &root_ns, const std::string &ns,
                                 std::vector<pasta::CXXRecordDecl> classes) {
  for (const pasta::CXXRecordDecl &cls : classes) {
    if (!seen_decls.emplace(cls.RawDecl()).second) {
      continue;
    }

    if (!seen_decls.emplace(cls.CanonicalDeclaration().RawDecl()).second) {
      continue;
    }

    std::string name = cls.Name();
    if (name.ends_with("Adaptor") || name.ends_with("Builder") ||
        name.ends_with("Interface") || name.ends_with("Parser") ||
        name.ends_with("Pattern") || name.ends_with("Benefit") ||
        name.ends_with("Handler") || name.ends_with("Engine") ||
        name.ends_with("Result") || name.ends_with("Rewriter")) {
      continue;
    }

    std::optional<std::vector<pasta::CXXMethodDecl>> methods = cls.Methods();
    std::vector<pasta::CXXMethodDecl> methods_to_wrap;
    std::vector<pasta::CXXMethodDecl> datalayout_methods;
    std::vector<std::string_view> attributes;

    std::string_view op_name = kOpName[name];

    for (pasta::CXXMethodDecl &meth : methods.value()) {

      switch (meth.Kind()) {
        case pasta::DeclKind::kCXXConstructor:
        case pasta::DeclKind::kCXXConversion:
        case pasta::DeclKind::kCXXDeductionGuide:
        case pasta::DeclKind::kCXXDestructor:
          continue;
        default:
          break;
      }

      std::string meth_name = meth.Name();
      if (meth_name.starts_with("getODS") || meth_name.starts_with("verify") ||
          meth_name.starts_with("set") || meth_name == "build" ||
          meth_name == "print" || meth_name == "parse" ||
          meth_name.ends_with("Mutable") || meth_name.starts_with("remove") ||
          (meth_name.starts_with("get") && meth_name.ends_with("AttrName"))) {
        continue;
      }

      if (meth_name == "getOperationName") {
        op_name = FindName(meth);
        continue;
      } else if (meth_name == "getMnemonic") {
        op_name = FindName(meth);
        continue;

      } else if (meth_name == "getAttributeNames") {
        attributes = FindNames(meth);
        continue;
      }

      if (meth.NumParameters()) {
        if (meth_name == "getTypeSizeInBits" ||
            meth_name == "getABIAlignment" ||
            meth_name == "getPreferredAlignment") {
          datalayout_methods.emplace_back(std::move(meth));
        }
        continue;
      }

      // We often see things like `getNameAttr` followed by `getName`. Identify
      // these and keep only the latter.
      if (!methods_to_wrap.empty() &&
          methods_to_wrap.back().Name() == (meth_name + "Attr")) {
        methods_to_wrap.pop_back();
      }

      methods_to_wrap.emplace_back(std::move(meth));
    }

    if (!op_name.empty()) {
      if (name.ends_with("Attr")) {
        RunOnAttrClass(root_ns, ns, cls, std::move(methods_to_wrap), op_name);

      } else if (name.ends_with("Type")) {
        RunOnTypeClass(root_ns, ns, cls, std::move(methods_to_wrap),
                       std::move(datalayout_methods), op_name);
      } else {
        RunOnOpClass(root_ns, ns, cls, std::move(methods_to_wrap),
                     std::move(attributes), op_name);
      }
    }
  }
}

void CodeGenerator::RunOnEnums(
    const std::string &root_ns, const std::string &ns,
    std::vector<pasta::EnumDecl> enums) {

  for (const pasta::EnumDecl &e : enums) {
    std::string name = e.Name();
    std::cerr << "ENUM: " << root_ns << "::" << ns << "::" << name << '\n';
  }
}

void CodeGenerator::RunOnNamespace(const pasta::NamespaceDecl &root_ns,
                                   pasta::NamespaceDecl ns) {
  std::string root_ns_name = root_ns.Name();
  std::string ns_name = ns.Name();

  if (root_ns_name == "vast") {
    if (ns_name != "hl" && ns_name != "ll" && ns_name != "meta" &&
        ns_name != "core" && ns_name != "unsup" && ns_name != "abi") {
      return;
    }
  } else if (root_ns_name == "mlir") {
    if (ns_name != "LLVM" && ns_name != "memref") {
      return;
    }

  } else {
    return;
  }

  std::vector<pasta::CXXRecordDecl> classes;
  std::vector<pasta::EnumDecl> enums;

  for (auto decl : pasta::DeclContext(ns).Declarations()) {
    if (auto cls = pasta::CXXRecordDecl::From(decl);
        cls && cls->IsThisDeclarationADefinition()) {
      classes.emplace_back(std::move(cls.value()));
    } else if (auto e = pasta::EnumDecl::From(decl);
               e && e->IsThisDeclarationADefinition()) {
      enums.emplace_back(std::move(e.value()));
    }
  }

  RunOnEnums(root_ns_name, ns_name, std::move(enums));
  RunOnClasses(root_ns_name, ns_name, std::move(classes));
}

std::string CodeGenerator::TopIncludePath(std::string path) {
  for (auto end = included_by.end(); ;) {
    auto it = included_by.find(path);
    if (it == end) {
      break;
    } else {
      path = it->second;
    }
  }
  return path;
}

void CodeGenerator::FindIncludePaths(pasta::MacroRange macros,
                                     pasta::File main_file) {
  for (pasta::Macro m : macros) {
    auto inc = pasta::IncludeMacroDirective::From(m);
    if (!inc) {
      continue;
    }

    auto dest_file = inc->IncludedFile();
    if (!dest_file) {
      continue;
    }

    auto bt = inc->BeginToken();
    if (!bt) {
      continue;
    }

    auto fbt = bt->FileLocation();
    if (!fbt) {
      continue;
    }

    auto src_file = pasta::File::Containing(fbt.value());
    if (src_file == main_file) {
      continue;
    }

    auto dest_path = RelativePath(dest_file->Path());
    auto src_path = RelativePath(src_file.Path());
    if (!dest_path.empty() && !src_path.empty()) {
      included_by.emplace(dest_path, src_path);
    }
  }
}

void CodeGenerator::RunOnAST(pasta::AST ast) {
  FindIncludePaths(ast.Macros(), ast.MainFile());
  RunOnTranslationUnit(ast.TranslationUnit());
}

void CodeGenerator::RunOnTranslationUnit(pasta::TranslationUnitDecl tu) {

  std::vector<pasta::CXXRecordDecl> classes;
  std::vector<pasta::EnumDecl> enums;

  // TODO(pag): Need to go deeper into vast::hl, ::ll

  for (auto decl : pasta::DeclContext(tu).Declarations()) {
    auto ns = pasta::NamespaceDecl::From(decl);
    if (!ns) {
      continue;
    }

    std::string ns_name = ns->Name();

    for (pasta::Decl sub_decl : pasta::DeclContext(ns.value()).Declarations()) {
      if (auto sub_ns = pasta::NamespaceDecl::From(sub_decl)) {
        RunOnNamespace(ns.value(), std::move(sub_ns.value()));

      } else if (ns_name == "mlir") {
        if (auto cls = pasta::CXXRecordDecl::From(sub_decl);
            cls && cls->IsThisDeclarationADefinition()) {
          classes.emplace_back(std::move(cls.value()));

        } else if (auto e = pasta::EnumDecl::From(sub_decl);
                   e && e->IsThisDeclarationADefinition()) {
          enums.emplace_back(std::move(e.value()));
        }
      }
    }
  }

  if (!enums.empty()) {
    RunOnEnums("", "mlir", std::move(enums));
  }
  if (!classes.empty()) {
    RunOnClasses("", "mlir", std::move(classes));
  }
}

CodeGenerator::CodeGenerator(char *[]) {}

int main(int argc, char *argv[]) {
//  if (12 != argc) {
//    std::cerr
//        << "Usage: " << argv[0]
//        << " VAST_INCLUDE_PATH DEPENDENCIES_INC_PATH LLVM_INCLUDE_PATH "
//        << std::endl;
//    return EXIT_FAILURE;
//  }

  std::cerr  << "Bootstrap command:\n";
  auto sep = "\t";
  for (auto i = 0; i < argc; ++i) {
    std::cerr << sep << argv[i];
    sep = " ";
  }
  std::cerr << "\n\n";


  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto fs = pasta::FileSystem::From(maybe_compiler.Value());
  auto maybe_cwd = fs->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto exe_path = maybe_compiler->ExecutablePath();
  std::vector<const char *> cc_args{
      exe_path.c_str(),
      "-x", "c++",
      "-std=c++20",
      "-c", __FILE__,
      "-o", "/dev/null",
      "-isystem", argv[1],  // Install include dir.
      "-isystem", argv[2],  // Dependencies include dir.
      "-isystem", argv[3],  // LLVM include dir.
      "-DMX_IN_BOOTSTRAP",
      "-DGAP_ENABLE_COROUTINES"};

  const pasta::ArgumentVector args(cc_args);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::CompileCommand command = maybe_command.TakeValue();

  std::cerr
      << "Self-parsing with:\n\t"
      << command.Arguments().Join() << "\n\n";

  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  CodeGenerator cg(argv);

  for (const pasta::CompileJob &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      cg.RunOnAST(maybe_ast.TakeValue());
    }
  }

  cg.Summarize();
  cg.RunOnOps();
  cg.RunOnTypes();
  cg.RunOnAttrs();

  return EXIT_SUCCESS;
}

#endif  // !defined(MX_IN_BOOTSTRAP)
