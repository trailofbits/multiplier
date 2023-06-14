// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#ifdef MX_IN_BOOTSTRAP

#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/IR/BuiltinAttributes.h>
#include <mlir/Dialect/SCF/IR/SCF.h>
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/MemRef/IR/MemRef.h>
#include <vast/Dialect/Dialects.hpp>
#include <vast/Dialect/Core/CoreOps.hpp>
#include <vast/Dialect/Core/CoreTypes.hpp>
#include <vast/Dialect/HighLevel/HighLevelOps.hpp>
#include <vast/Dialect/HighLevel/HighLevelTypes.hpp>
#include <vast/Dialect/HighLevel/HighLevelLinkage.hpp>
#include <vast/Dialect/LowLevel/LowLevelOps.hpp>
#include <vast/Dialect/Meta/MetaAttributes.hpp>
#include <vast/Dialect/Meta/MetaTypes.hpp>

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
#include <fstream>
#include <iostream>
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

 public:
  CodeGenerator(char *argv[]);
  void RunOnTranslationUnit(pasta::TranslationUnitDecl tu);

  void RunOnOps(std::ostream &hpp, std::ostream &cpp);
  void RunOnTypes(std::ostream &hpp, std::ostream &cpp);
  void RunOnAttrs(std::ostream &hpp, std::ostream &cpp);
};

static std::string MethodName(const std::string &name) {
  std::string capital_name = Capitalize(name);

  if (capital_name.starts_with("Get") && !capital_name.starts_with("Gets")) {
    capital_name = capital_name.substr(3u);
  }

  return CapitalCaseToSnakeCase(capital_name);
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
  std::string_view ns_key;
  std::string_view root_ns;
  std::string_view ns;
  std::vector<Op *> ops;
  std::vector<Type *> types;
  std::vector<Attr *> attrs;
};

static Dialect gDialects[] = {
  {"Builtin", "mlir", "", "mlir", {}, {}, {}},
  {"LLVMIR", "mlir::LLVM", "mlir", "LLVM", {}, {}, {}},
  {"SCF", "mlir::scf", "mlir", "scf", {}, {}, {}},
  {"MemRef", "mlir::memref", "mlir", "memref", {}, {}, {}},
  {"LowLevel", "vast::ll", "vast", "ll", {}, {}, {}},
  {"HighLevel", "vast::hl", "vast", "hl", {}, {}, {}},
  {"Core", "vast::core", "vast", "core", {}, {}, {}},
  {"Meta", "vast::meta", "vast", "meta", {}, {}, {}},
};

static std::unordered_map<std::string, std::string_view> gReturnType{
  {"::mlir::Attribute", "::mx::ir::Attribute"},
  {"::mlir::Value", "::mx::ir::Value"},
  {"::mlir::Type", "::mx::ir::Type"},
  {"::llvm::StringRef", "std::string_view"},
  {"std::string_view", "std::string_view"},
  {"std::string", "std::string_view"},
  {"::mlir::Region&", "::mx::ir::Region"},
  {"::std::optional<::mlir::Attribute>", "std::optional<::mx::ir::Attribute>"},
  {"::std::optional<::mlir::Value>", "std::optional<::mx::ir::Value>"},
  {"vstd::optional<::mlir::Type>", "std::optional<::mx::ir::Type>"},
  {"::std::optional<::llvm::StringRef>", "std::optional<std::string_view>"},
  {"::std::optional<::mlir::Region>", "std::optional<::mx::ir::Region>"},
  {"bool", "bool"},
  {"short", "short"},
  {"int", "int"},
  {"unsigned", "unsigned"},
  {"uint8_t", "uint8_t"},
  {"uint16_t", "uint16_t"},
  {"uint32_t", "uint32_t"},
  {"int64_t", "uint64_t"},
  {"int8_t", "int8_t"},
  {"int16_t", "int16_t"},
  {"int32_t", "int32_t"},
  {"int64_t", "int64_t"},
  {"::std::optional<unsigned>", "std::optional<unsigned>"},
  {"::std::optional<uint8_t>", "std::optional<uint8_t>"},
  {"::std::optional<uint16_t>", "std::optional<uint16_t>"},
  {"::std::optional<uint32_t>", "std::optional<uint32_t>"},
  {"::std::optional<int64_t>", "std::optional<uint64_t>"},
  {"::std::optional<int8_t>", "std::optional<int8_t>"},
  {"::std::optional<int16_t>", "std::optional<int16_t>"},
  {"::std::optional<int32_t>", "std::optional<int32_t>"},
  {"::std::optional<int64_t>", "std::optional<int64_t>"},
};

void CodeGenerator::RunOnOps(std::ostream &hpp, std::ostream &cpp) {
  hpp
      << "// Copyright (c) 2023-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n"
      << "#include <gap/core/generator.hpp>\n"
      << "#include <optional>\n"
      << "#include <memory>\n"
      << "#include <string_view>\n\n";

  // Forward declare a whole bunch of stuff.
  for (Dialect &dialect : gDialects) {
    hpp << "namespace " << dialect.ns_key << " {\n";
    if (dialect.ns_key == "mlir") {
      hpp << "class Attribute;\n"
          << "class Operation;\n"
          << "class Value;\n"
          << "class ValueImpl;\n"
          << "class BlockArgument;\n"
          << "class OpResult;\n";
    }

    for (Op &op : ops) {
      if (op.root_ns == dialect.root_ns && op.ns == dialect.ns) {
        dialect.ops.push_back(&op);
        hpp << "class " << op.name << ";\n";
      }
    }
    for (Type &type : types) {
      if (type.root_ns == dialect.root_ns && type.ns == dialect.ns) {
        dialect.types.push_back(&type);
        hpp << "class " << type.name << ";\n";
      }
    }
    for (Attr &attr : attrs) {
      if (attr.root_ns == dialect.root_ns && attr.ns == dialect.ns) {
        dialect.attrs.push_back(&attr);
        hpp << "class " << attr.name << ";\n";
      }
    }
    hpp << "}  // namespace " << dialect.ns_key << '\n';
  }

  hpp
      << "namespace mx {\n"
      << "class SourceIRImpl;\n"
      << "}\n"
      << "namespace mx::ir {\n\n"
      << "enum class OperationKind : unsigned {\n"
      << "  UNKNOWN,\n";

  for (Dialect &dialect : gDialects) {
    for (Op *op : dialect.ops) {
      hpp << "  " << OpNameToEnumCase(op->op_name) << ",\n";
    }
  }

  hpp << "};\n\n"
      << "class Attribute;\n"
      << "class Operation;\n"
      << "class Block;\n"
      << "class BlockArgument;\n"
      << "class Region;\n"
      << "class Type;\n\n"
      << "// The result of an operation, or an argument to a block. Values can\n"
      << "// have an arbitrary number of users.\n"
      << "class Value {\n"
      << " private:\n"
      << "  friend class Operation;\n"
      << "  friend class Block;\n"
      << "  friend class BlockArgument;\n\n"
      << "  std::shared_ptr<const SourceIRImpl> module_;\n"
      << "  mlir::ValueImpl *value_;\n"
      << " public:\n"
      << "  inline Value(std::shared_ptr<const SourceIRImpl> module,\n"
      << "               mlir::ValueImpl *value)\n"
      << "      : module_(std::move(module)),\n"
      << "        value_(value) {}\n\n"
      << "  std::optional<Operation> as_result(void) const noexcept;\n"
      << "  std::optional<BlockArgument> as_argument(void) const noexcept;\n"
      << "  Type type(void) const noexcept;\n"
      << "};\n\n"
      << "// A region is owned by an operation (not all operations own regions)\n"
      << "// and contain one or more blocks.\n"
      << "class Region {\n"
      << " private:\n"
      << "  friend class Operation;\n"
      << "  friend class Block;\n"
      << "  friend class BlockArgument;\n\n"
      << "  std::shared_ptr<const SourceIRImpl> module_;\n"
      << "  mlir::ValueImpl *value_;\n"
      << " public:\n"
      << "  inline Value(std::shared_ptr<const SourceIRImpl> module,\n"
      << "               mlir::ValueImpl *value)\n"
      << "      : module_(std::move(module)),\n"
      << "        value_(value) {}\n\n"
      << "  static Region containing(const Block &);\n"
      << "  gap::generator<Block> blocks(void) const & noexcept;\n"
      << "};\n\n"
      << "// An operation is like an 'instruction', but can contain arbitrary\n"
      << "// complexity in the form or one or more regions, each of which can\n"
      << "// embed their own control-flow graphs of blocks containing operations.\n"
      << "class Operation {\n"
      << " private:\n"
      << "  friend class SourceIR;\n"
      << "  friend class SourceIRImpl;\n\n"
      << "  Operation(void) = delete;\n\n"
      << " protected:\n"
      << "  std::shared_ptr<const SourceIRImpl> module_;\n"
      << "  OperationKind kind_;\n"
      << "  union {\n"
      << "    mlir::Operation *unknown;\n";

  for (Dialect &dialect : gDialects) {
    for (Op *op : dialect.ops) {
      hpp << "    " << dialect.ns_key << "::" << op->name << " *"
          << OpNameToSnakeCase(op->op_name) << ";\n";
    }
  }

  hpp << "  } op_;\n\n"
      << " public:\n"
      << "  static OperationKind op_kind(mlir::Operation *);\n"
      << "  static OperationKind op_kind(std::string_view);\n\n"
      << "  inline Operation(std::shared_ptr<const SourceIRImpl> module,\n"
      << "                   mlir::Operation *opaque)\n"
      << "      : module_(std::move(module)),\n"
      << "        kind_(op_kind(opaque)) {\n"
      << "    op_.unknown = opaque;\n"
      << "  }\n\n"
      << "  std::string_view op_name(void) const noexcept;\n"
      << "  inline OperationKind op_kind(void) const noexcept {\n"
      << "    return kind_;\n"
      << "  }\n"
      << "  inline std::shared_ptr<mlir::Operation> raw_op(void) const noexcept {\n"
      << "    return std::shared_ptr<mlir::Operation>(module_, op_.unknown);\n"
      << "  }\n"
      << "  inline static std::optional<Operation> producing(const Value &val) {\n"
      << "    return val.as_result();\n"
      << "  }\n"
      << "  static Operation containing(const Region &);\n"
      << "  static Operation containing(const Block &);\n"
      << "};\n\n";

  std::string_view builtin = "builtin";

  for (Dialect &dialect : gDialects) {
    if (dialect.ops.empty()) {
      continue;
    }

    std::string_view ns_name = dialect.root_ns.empty() ? builtin : dialect.ns;

    hpp
        << "namespace " << ns_name << " {\n"
        << "class Operation : public ::mx::ir::Operation {\n"
        << " public:\n"
        << "  static std::optional<Operation> from(const ::mx::ir::Operation &);\n"
        << "};\n"
        << "static_assert(sizeof(Operation) == sizeof(::mx::ir::Operation));\n\n";

    for (Op *op : dialect.ops) {
      std::string snake_name = OpNameToSnakeCase(op->op_name);

      hpp << "class " << op->name << " final : public Operation {\n"
          << " public:\n"
          << "  static std::optional<" << op->name << "> from(const ::mx::ir::Operation &);\n"
          << "  inline static std::optional<" << op->name << "> producing(const ::mx::ir::Value &val) {\n"
          << "    if (auto op = val.as_result()) {\n"
          << "      return from(op.value());\n"
          << "    }\n"
          << "    return std::nullopt;\n"
          << "  }\n"
          << "  inline static OperationKind static_op_kind(void) {\n"
          << "    return OperationKind::" << OpNameToEnumCase(op->op_name)
          << ";\n"
          << "  }\n"
          << "  " << dialect.ns_key
          << "::" << op->name << " raw_op(void) const noexcept;\n";

      for (const pasta::CXXMethodDecl &meth : op->methods) {
        std::string meth_name = meth.Name();
        std::string api_name = MethodName(meth_name);
        pasta::Type return_type = meth.ReturnType();
        std::string return_type_str =
            TokensToString(pasta::PrintedTokenRange::Create(return_type));
        if (auto rit = gReturnType.find(return_type_str); rit != gReturnType.end()) {

          hpp << "  " << rit->second << " " << api_name << "(void) const;\n";
        } else {

          hpp << "  //" << return_type_str << " " << api_name
              << "(void) const;\n";
        }
      }

      hpp
          << "};\n"
          << "static_assert(sizeof(" << op->name << ") == sizeof(Operation));\n\n";
    }

    hpp << "}  // namespace " << ns_name << "\n";
  }

  hpp << "}  // namespace mx::ir\n";
}

void CodeGenerator::RunOnTypes(std::ostream &hpp, std::ostream &cpp) {

}

void CodeGenerator::RunOnAttrs(std::ostream &hpp, std::ostream &cpp) {

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

//  std::cerr << "OP: " << root_ns << "::" << ns << "::" << name << " = "
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
      std::cerr << "\n";
    } else {
      std::cerr << "Skipping: " << root_ns << "::" << ns << "::"
                << name << "\n\n";
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
        ns_name != "core") {
      return;
    }
  } else if (root_ns_name == "mlir") {
    if (ns_name != "LLVM" && ns_name != "scf" && ns_name != "memref") {
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
      cg.RunOnTranslationUnit(maybe_ast.TakeValue().TranslationUnit());
    }
  }

  std::ofstream hpp("/tmp/test.h");
  std::ofstream cpp("/tmp/test.cpp");

  cg.RunOnOps(hpp, cpp);
  cg.RunOnTypes(hpp, cpp);
  cg.RunOnAttrs(hpp, cpp);

  return EXIT_SUCCESS;
}

#endif  // !defined(MX_IN_BOOTSTRAP)
