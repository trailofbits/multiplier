// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <fstream>
#include <iostream>
#include <llvm/ADT/APSInt.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/raw_ostream.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Forward.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define DECL_NAME(name) #name "Decl",
#define TYPE_NAME(name) #name "Type",
#define STR_NAME(name) #name,

static const std::unordered_set<std::string> gDeclNames{
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gStmtNames{
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gTypeNames{
//  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, STR_NAME)
};

#define NON_REF_TYPES \
    "IncludePath", \
    "Compiler", \
    "CompileCommand", \
    "CompileJob", \
    "TemplateParameter", \
    "TemplateArgument", \
    "CXXBaseSpecifier", \
    "TemplateParameterList"

static const std::unordered_set<std::string> gNotReferenceTypes{
  NON_REF_TYPES
};

static const std::unordered_set<std::string> gConcreteClassNames{
  "Token",
  "TokenRange",
  "FileToken",
  NON_REF_TYPES,
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, PASTA_IGNORE_ABSTRACT)
//  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, PASTA_IGNORE_ABSTRACT)
};

static const std::unordered_set<std::string> gEntityClassNames{
  "Token",
  "FileToken",
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, PASTA_IGNORE_ABSTRACT)
};

// These methods can trigger asserts deep in their internals that are hard
// to design around in PASTA. The auto-generated serialization code tries to
// call most methods, and we don't want to call a method that will crash the
// process with an assertion failure. So we just blacklist those methods here.
//
// Sometimes, those methods can be handled because their assertions are
// "shallow" and appear in the method body itself (and not inside of an
// internally called method), and in those cases, we can often modify PASTA
// itself (`pasta/bin/BootstrapTypes/Globals.cpp`, `kConditionalNullptr`)
// to check the conditions that would be asserted, and if those conditions
// aren't satisfied, then return `std::nullopt`.
static const std::set<std::pair<std::string, std::string>> kMethodBlackList{
  {"Expr", "ClassifyLValue"},  // Calls `clang::Expr::ClassifyImpl`.
  {"Expr", "IsBoundMemberFunction"},  // Calls `clang::Expr::ClassifyImpl`.
  {"Expr", "IsModifiableLvalue"},  // Calls `clang::Expr::ClassifyImpl`.
};

struct ClassHierarchy {
  const pasta::CXXRecordDecl record;
  ClassHierarchy *base{nullptr};
  std::vector<ClassHierarchy *> derived;

  inline ClassHierarchy(pasta::CXXRecordDecl record_)
      : record(std::move(record_)) {}
};

static void BuildHierarchy(
    std::vector<std::unique_ptr<ClassHierarchy>> &alloc,
    const std::vector<pasta::CXXRecordDecl> &classes,
    std::vector<ClassHierarchy *> &roots_out) {

  std::unordered_map<pasta::CXXRecordDecl, ClassHierarchy *> hmap;

  for (auto progress = true; progress; ) {
    progress = false;
    for (const pasta::CXXRecordDecl &cls : classes) {
      ClassHierarchy *&h = hmap[cls];
      if (h) {
        continue;
      }

      auto bases = cls.Bases();
      if (bases.empty()) {
       h = new ClassHierarchy(cls);
       alloc.emplace_back(h);
       roots_out.push_back(h);
       progress = true;

      } else {
        for (pasta::CXXBaseSpecifier parent : bases) {
          if (auto base = parent.BaseType().AsCXXRecordDeclaration()) {
            if (auto base_h = hmap[*base]) {
              h = new ClassHierarchy(cls);
              alloc.emplace_back(h);
              h->base = base_h;
              base_h->derived.push_back(h);
              progress = true;
              break;
            }
          }
        }
      }
    }
  }
}

static std::string Capitalize(std::string name) {
  name[0] = static_cast<char>(std::toupper(name[0]));
  return name;
}

// Convert a `CapitalCase` name into a `snake_case` name.
static std::string CapitalCaseToSnakeCase(std::string_view name) {
  std::stringstream ss;

  auto i = 0u;
  auto added_sep = false;
  auto last_was_uc = false;
  for (auto c : name) {
    if ('_' == c) {
      if (last_was_uc || !i) {
        ss << '_';
      } else {
        ss << "__";
      }
      added_sep = true;
      last_was_uc = true;

    } else if (std::isupper(c)) {
      if (!added_sep && i && (i + 1u) < name.size()) {
        if (std::islower(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      ss << static_cast<char>(std::tolower(c));
      added_sep = false;
      last_was_uc = false;

    } else if (std::isdigit(c)) {
      ss << c;
      if (!added_sep && (i + 1u) < name.size()) {
        if (!std::isdigit(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      last_was_uc = false;

    } else {
      ss << c;

      if (!added_sep && (i + 1u) < name.size()) {
        if (std::isupper(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      last_was_uc = false;
    }
    ++i;
  }
  auto res = ss.str();

  // If it's ending with three underscores, then make it end with two
  // underscores. This is a dumb hack to deal with some special keywords/
  // token kinds that show up in PASTA.
  if (auto s = res.size(); s > 3u) {
    if (res[s - 1u] == '_' && res[s - 2u] == '_' && res[s - 3u] == '_') {
      res.pop_back();
    }
  }

  return res;
}

// Convert a `snake_case` name into a `camelCase` name.
static std::string SnakeCaseToCamelCase(std::string_view name) {
  std::stringstream ss;
  auto uc = 0;
  auto cs = false;
  auto i = 0u;
  for (auto c : name) {
    ++i;
    if ('_' == c) {
      ++uc;

    } else if (!uc) {
      ss << c;
      cs = true;

    // Underscore used to separate two things, e.g. `foo_bar`.
    } else if (uc == 1) {
      if (!cs) {  // Leading underscore, e.g. `_foo`.
        ss << "uc";

      } else if (i == name.size()) { // Trailing underscore.
        ss << "Uc";
      }
      ss << static_cast<char>(std::toupper(c));
      uc = 0;
      cs = true;

    // Multiple `_`s inside of something else, e.g. `kw___attribute`.
    } else if (cs) {
      --uc;  // The first is a separator, drop it.
      while (uc--) {
        ss << "Uc";
        cs = true;
      }
      ss << static_cast<char>(std::toupper(c));
      uc = 0;
      cs = true;

    // Multiple leading underscore, e.g. `__attribute`.
    } else {
      if (!cs) {
        ss << "uc";
        --uc;
        cs = true;
      }
      while (uc--) {
        ss << "Uc";
      }
      ss << static_cast<char>(std::toupper(c));
      uc = 0;
      cs = true;
    }
  }
  return ss.str();
}

static std::string SnakeCaseToEnumCase(std::string_view name) {
  std::stringstream ss;
  for (auto c : name) {
    ss << static_cast<char>(std::toupper(c));
  }
  return ss.str();
}

static const char *CxxIntType(pasta::Type type) {
  auto t = type;
  if (auto bt = pasta::BuiltinType::From(type.UnqualifiedType())) {
    switch (bt->Kind()) {
      case pasta::BuiltinTypeKind::kBoolean: return "bool";
      case pasta::BuiltinTypeKind::kCharacterS: return "char";  // `char`.
      case pasta::BuiltinTypeKind::kCharacterU: return "char";  // `char`.
      case pasta::BuiltinTypeKind::kSChar: return "signed char";  // `signed char`.
      case pasta::BuiltinTypeKind::kUChar: return "unsigned char";  // `unsigned char`.
      case pasta::BuiltinTypeKind::kShort: return "short";
      case pasta::BuiltinTypeKind::kUShort: return "unsigned short";
      case pasta::BuiltinTypeKind::kInt: return "int";
      case pasta::BuiltinTypeKind::kUInt: return "unsigned";
      case pasta::BuiltinTypeKind::kLong: return "long";
      case pasta::BuiltinTypeKind::kULong: return "unsigned long";
      case pasta::BuiltinTypeKind::kLongLong: return "long long";
      case pasta::BuiltinTypeKind::kULongLong: return "unsigned long long";
      default: break;
    }
  } else if (type.IsTypedefNameType()) {
    return CxxIntType(type.DesugaredType());
  }
  return nullptr;
}

static const char *SchemaIntType(pasta::Type type) {
  auto t = type;
  if (auto bt = pasta::BuiltinType::From(type.UnqualifiedType())) {
    switch (bt->Kind()) {
      case pasta::BuiltinTypeKind::kBoolean: return "Bool";
      case pasta::BuiltinTypeKind::kCharacterS: return "Int8";  // `char`.
      case pasta::BuiltinTypeKind::kCharacterU: return "UInt8";  // `char`.
      case pasta::BuiltinTypeKind::kSChar: return "Int8";  // `signed char`.
      case pasta::BuiltinTypeKind::kUChar: return "UInt8";  // `unsigned char`.
      case pasta::BuiltinTypeKind::kShort: return "Int16";
      case pasta::BuiltinTypeKind::kUShort: return "UInt16";
      case pasta::BuiltinTypeKind::kInt: return "Int32";
      case pasta::BuiltinTypeKind::kUInt: return "UInt32";
      case pasta::BuiltinTypeKind::kLong: return "Int64";
      case pasta::BuiltinTypeKind::kULong: return "UInt64";
      case pasta::BuiltinTypeKind::kLongLong: return "Int64";
      case pasta::BuiltinTypeKind::kULongLong: return "UInt64";
      default: break;
    }
  }
  return nullptr;
}

static std::string NameAndHash(std::string name) {
  std::hash<std::string> hasher;
  std::stringstream ss;
  uint64_t hash_val = hasher(name);
  if (static_cast<int64_t>(hash_val) > 0) {
    hash_val = ~hash_val;
  }
  ss << name << " @0x" << std::hex << hash_val;
  return ss.str();
}

using MethodList = std::unordered_set<std::string>;
using MethodListPtr = std::shared_ptr<MethodList>;

class CodeGenerator {
 private:
  std::vector<ClassHierarchy *> roots;

  std::ofstream schema_os;
  std::ofstream lib_h_os;
  std::ofstream lib_cpp_os;
  std::ofstream include_h_os;
  std::ofstream serialize_h_os;
  std::ofstream serialize_cpp_os;

  std::vector<pasta::NamespaceDecl> pastas;

  std::vector<pasta::EnumDecl> enums;
  std::vector<pasta::CXXRecordDecl> decls;
  std::vector<pasta::CXXRecordDecl> stmts;
  std::vector<pasta::CXXRecordDecl> types;
  std::vector<pasta::CXXRecordDecl> tokens;

  std::stringstream header_enum_ss;

  void RunOnEnum(pasta::EnumDecl enum_decl);

  MethodListPtr RunOnClass(ClassHierarchy *, MethodListPtr parent_methods);
  int RunOnClassHierarchies(void);
  int RunOnClasses(void);
  int RunOnNamespaces(void);

 public:
  CodeGenerator(char *argv[]);
  int RunOnTranslationUnit(pasta::TranslationUnitDecl tu);
};

void CodeGenerator::RunOnEnum(pasta::EnumDecl enum_decl) {
  auto enum_name = enum_decl.Name();
  auto itype = CxxIntType(enum_decl.IntegerType());
  schema_os << NameAndHash("enum " + enum_name) << " {\n";
  include_h_os << "enum class " << enum_name << " : unsigned short {\n";
  lib_cpp_os
      << enum_name << " FromPasta(pasta::" << enum_name << " e) {\n"
      << "  switch (static_cast<";
  if (!strcmp(itype, "bool")) {
    lib_cpp_os << "int";  // Avoid switching on `bool` types.
  } else {
    lib_cpp_os << itype;
  }
  lib_cpp_os << ">(e)) {\n";

  std::unordered_set<std::string> seen_initializers;
  std::string initializer;
  llvm::raw_string_ostream initializer_ss(initializer);

  auto i = 0u;
  for (pasta::EnumConstantDecl val : enum_decl.Enumerators()) {
    initializer.clear();

    auto val_name = val.Name();
    auto orig_val_name = val_name;

    // Don't allow repeats of the underlying values.
    auto ap_val = val.InitializerVal();
    ap_val.print(initializer_ss, ap_val.isSigned());
    initializer_ss.flush();
    if (!seen_initializers.emplace(initializer).second) {
      schema_os << "  # Skipped repeat pasta::" << orig_val_name << "\n";
      include_h_os << "  // Skipped repeat pasta::" << orig_val_name << "\n";
      continue;
    }

    // Some of these are numbers.
    if (enum_name == "SYCLMajorVersion") {
      val_name = "Version" + val_name.substr(1);

    } else if (enum_name == "SanitizerOrdinal" && val_name == "kNull") {
      val_name = "Null_";
    }

    std::string_view val_name_view = val_name;
    if (val_name_view[0] == 'k') {
      val_name_view = val_name_view.substr(1);
    }

    auto snake_name = CapitalCaseToSnakeCase(val_name_view);
    auto camel_name = SnakeCaseToCamelCase(snake_name);
    auto enum_case = SnakeCaseToEnumCase(snake_name);

    // Take over `kRawIdentifier`, and change it to `kWhitespace`, so that
    // we can use `kUnknown` for errors and such.
    if (val_name == "kRawIdentifier" && enum_name == "TokenKind") {
      snake_name = "whitespace";
      camel_name = "whitespace";
      enum_case = "WHITESPACE";

      lib_cpp_os
          << "    case " << initializer << ": return TokenKind::IDENTIFIER;\n";
    } else {
      lib_cpp_os
          << "    case " << initializer << ": return "
          << enum_name << "::" << enum_case << ";\n";
    }

    schema_os
        << "  " << camel_name << " @" << i << " $Cxx.name(\""
        << snake_name << "\");\n";

    include_h_os
        << "  " << enum_case << ",\n";
    ++i;
  }

  lib_cpp_os
      << "    default: __builtin_unreachable();\n"
      << "  }\n"  // End of `switch`.
      << "}\n\n";  // End of `FromPasta`.

  // Add a last item to every enumeration so that we can easily get the
  // number of enumerators.
  schema_os
      << "}\n\n";

  include_h_os
      << "  NUM_ENUMERATORS\n"
      << "};\n\n"
      << enum_name << " FromPasta(pasta::" << enum_name << " pasta_val);\n\n";
}

static std::optional<std::string> GetFirstTemplateParameterType(
    const std::optional<pasta::RecordDecl> &record) {
  if (record) {
    if (auto cspec = pasta::ClassTemplateSpecializationDecl::From(*record)) {
      for (pasta::TemplateArgument arg : cspec->TemplateArguments()) {
        if (auto arg_type = arg.AsType()) {
          if (auto arg_record = arg_type->AsRecordDeclaration()) {
            return arg_record->Name();
          }
        }
      }
    }
  }
  return std::nullopt;
}

MethodListPtr CodeGenerator::RunOnClass(
    ClassHierarchy *cls, MethodListPtr parent_methods) {
  auto seen_methods = std::make_shared<MethodList>(*parent_methods);
  auto class_name = cls->record.Name();

  // We have our own representation for these.
  if (class_name == "Token" || class_name == "TokenRange") {
    return parent_methods;
  }

  serialize_cpp_os
      << "void Serialize" << class_name << "(EntitySerializer &es, mx::ast::"
      << class_name << "::Builder b, const pasta::" << class_name << " &e) {\n";

  schema_os << NameAndHash("struct " + class_name) << " {\n";
  auto i = 0u;

  if (cls->base) {
    std::string base_name = cls->base->record.Name();
    std::string snake_name = CapitalCaseToSnakeCase(base_name);
    std::string camel_name = SnakeCaseToCamelCase(snake_name);
    std::string init_name = "init" + Capitalize(camel_name);
    schema_os
        << "  " << camel_name << " @" << i << ":"
        << base_name << ";\n";

    // Parent class serialization.
    serialize_cpp_os
        << "  Serialize" << base_name << "(es, b." << init_name << "(), e);\n";

    ++i;
  }

  for (pasta::CXXMethodDecl method : cls->record.Methods()) {
    if (method.NumParams()) {
      continue;  // Skip methods with parameters.
    }
    auto method_name = method.Name();
    llvm::StringRef method_name_ref(method_name);
    if (method_name == "KindName" ||
        method_name_ref.startswith("operator") ||
        method_name_ref.startswith("~")) {
      continue;  // E.g. `Decl::KindName()`, `operator==`.
    }
    if (!seen_methods->emplace(method_name).second) {
      continue;
    }

    std::pair<std::string, std::string> method_key{class_name, method_name};
    if (kMethodBlackList.count(method_key)) {
      continue;
    }

    std::string snake_name = CapitalCaseToSnakeCase(method_name);
    std::string camel_name = SnakeCaseToCamelCase(snake_name);
    std::string setter_name = "set" + Capitalize(camel_name);
    std::string init_name = "init" + Capitalize(camel_name);
    auto return_type = method.ReturnType().UnqualifiedType();
    if (auto return_type_ref = pasta::ReferenceType::From(return_type)) {
      return_type = return_type_ref->PointeeType().UnqualifiedType();
    }

    if (auto record = return_type.AsRecordDeclaration()) {
      std::string record_name = record->Name();

      // Handle `pasta::Token`.
      if (record_name == "Token") {
        serialize_cpp_os
            << "  b." << setter_name << "(es.EntityId(e."
            << method_name << "()));\n";

        schema_os
            << "  " << camel_name << " @" << i << " :UInt64;\n";  // Reference.
        ++i;

      // Handle `pasta::TokenRange`.
      } else if (record_name == "TokenRange") {
        serialize_cpp_os
            << "  auto sr" << i << " = b." << init_name << "();\n"
            << "  if (auto r" << i << " = e." << method_name << "(); auto rs"
            << i << " = r" << i << ".Size()) {\n"
            << "    sr" << i << ".setBeginId(es.EntityId(r" << i << "[0]));\n"
            << "    sr" << i << ".setEndId(es.EntityId(r" << i << "[rs" << i << " - 1u]));\n"
            << "  } else {\n"
            << "    sr" << i << ".setBeginId(0);\n"
            << "    sr" << i << ".setEndId(0);\n"
            << "  }\n";

        schema_os << "  " << camel_name << " @" << i << " :TokenRange;\n";
        ++i;

      // Handle `std::string`
      } else if (record_name == "string" || record_name == "basic_string") {
        serialize_cpp_os
            << "  b." << setter_name << "(e." << method_name << "());\n";

        schema_os << "  " << camel_name << " @" << i << " :Text;\n";
        ++i;

      // Handle `std::string_view`. Cap'n Proto requires that `:Text` fields
      // are `NUL`-terminated, so we convert the string view into a
      // `std::string`.
      } else if (record_name == "string_view" ||
                 record_name == "basic_string_view") {
        serialize_cpp_os
            << "  auto v" << i << " = e." << method_name << "();\n"
            << "  std::string s" << i << "(v" << i << ".data(), v"
            << i << ".size());\n  b." << setter_name << "(s" << i << ");\n";

        schema_os << "  " << camel_name << " @" << i << " :Text;\n";
        ++i;

      // In pasta.
      } else if (record_name == "ArgumentVector") {

        serialize_cpp_os
            << "  const auto &v" << i << " = e." << method_name << "();\n"
            << "  auto b" << i << " = b." << init_name
            << "(static_cast<unsigned>(v" << i << ".Size()));\n"
            << "  auto i" << i << " = 0u;\n"
            << "  for (const auto &arg : v" << i << ") {\n"
            << "    b" << i << ".set(i" << i << "++, arg);\n"
            << "  }\n";

        schema_os << "  " << camel_name << " @" << i << " :List(Text);\n";
        ++i;

      // Probably `std::filesystem::path`.
      } else if (record_name == "path") {
        serialize_cpp_os
            << "  b." << setter_name << "(e." << method_name << "().generic_string());\n";

        schema_os << "  " << camel_name << " @" << i << " :Text;\n";
        ++i;

      // TODO(pag): Figure out optionals in Cap'n Proto.
      } else if (record_name == "optional") {
//        std::optional<std::string> element_name =
//            GetFirstTemplateParameterType(record);
//        std::string capn_element_name;
//        if (!element_name) {
//
//        } else if (*element_name == "string" ||
//                   *element_name == "basic_string" ||
//                   *element_name == "string_view" ||
//                   *element_name == "basic_string_view" ||
//                   *element_name == "path") {
//          capn_element_name = "Text";
//
//        } else if (gNotReferenceTypes.count(*element_name)) {
//          capn_element_name = element_name.value();
//
//        } else if (gEntityClassNames.count(*element_name)) {
//          capn_element_name = "UInt64";  // Reference.
//        }
//
//        if (!capn_element_name.empty()) {
//          schema_os
//              << "  " << camel_name << " @" << i << " :List("
//              << capn_element_name << ");\n";
//          ++i;
//        }

      // List of things; figure out what.
      } else if (record_name == "vector") {
        std::optional<std::string> element_name =
            GetFirstTemplateParameterType(record);
        std::string capn_element_name;
        if (!element_name) {

        } else if (*element_name == "string" ||
                   *element_name == "basic_string" ||
                   *element_name == "string_view" ||
                   *element_name == "basic_string_view" ||
                   *element_name == "path") {
          capn_element_name = "Text";

        } else if (gEntityClassNames.count(*element_name)) {
          capn_element_name = "UInt64";  // Reference.

        } else if (gNotReferenceTypes.count(*element_name)) {
          capn_element_name = element_name.value();
        }

        if (capn_element_name.empty()) {
          continue;
        }

        serialize_cpp_os
            << "  auto v" << i << " = e." << method_name << "();\n"
            << "  auto sv" << i << " = b." << init_name << "(static_cast<unsigned>(v"
            << i << ".size()));\n"
            << "  auto i" << i << " = 0u;\n"
            << "  for (const auto &e" << i << " : v" << i << ") {\n";


        if (*element_name == "string" || *element_name == "basic_string") {
          serialize_cpp_os
              << "    sv" << i << ".set(i" << i << ", e" << i << ");\n";

        // String views need to be converted to `std::string` because Cap'n
        // Proto requires `:Text` fields to be `NUL`-terminated.
        } else if (*element_name == "string_view" ||
                   *element_name == "basic_string_view") {
          serialize_cpp_os
              << "    std::string se" << i << "(e" << i << ".data(), e"
              << i << ".size());\n"
              << "    sv" << i << ".set(i" << i << ", se" << i << ");\n";

        // Filesystem paths.
        } else if (*element_name == "path") {
          serialize_cpp_os
              << "    sv" << i << ".set(i" << i << ", e" << i
              << ".generic_string());\n";

        // Reference types.
        } else if (gEntityClassNames.count(*element_name)) {
          serialize_cpp_os
              << "    sv" << i << ".set(i" << i << ", es.EntityId(e" << i
              << "));\n";

        // Not reference types.
        } else {
          serialize_cpp_os
              << "    Serialize" << (*element_name)
              << "(es, sv" << i << "[i" << i << "], e" << i << ");\n";
        }

        serialize_cpp_os
            << "    ++i" << i << ";\n"
            << "  }\n";

        schema_os
            << "  " << camel_name << " @" << i << " :List("
            << capn_element_name << ");\n";
        ++i;

      } else if (gNotReferenceTypes.count(record_name)) {
        schema_os
            << "  " << camel_name << " @" << i << " :" << record_name
            << ";\n";
        ++i;

      } else if (gEntityClassNames.count(record_name)) {
        schema_os
            << "  " << camel_name << " @" << i << " :UInt64;\n";  // Ref.
        ++i;
      }

    // Handle enumerations return types.
    } else if (auto tag = return_type.AsTagDeclaration()) {
      if (auto enum_decl = pasta::EnumDecl::From(*tag)) {
        auto enum_name = enum_decl->Name();
        serialize_cpp_os
            << "  b." << setter_name << "(static_cast<mx::ast::"
            << enum_name << ">(mx::FromPasta(e." << method_name << "())));\n";

        schema_os
            << "  " << camel_name << " @" << i << " :" << enum_name
            << ";\n";
        ++i;
      }

    // Handle integral return types.
    } else if (auto int_type = SchemaIntType(return_type)) {
      serialize_cpp_os
          << "  b." << setter_name << "(e." << method_name << "());\n";

      schema_os
          << "  " << camel_name << " @" << i << " :" << int_type
          << ";\n";
      ++i;
    }
  }
  serialize_cpp_os << "}\n\n";
  schema_os << "}\n\n";
  return seen_methods;
}

int CodeGenerator::RunOnClassHierarchies(void) {

  std::vector<std::pair<ClassHierarchy *, std::shared_ptr<MethodList>>> work_list;
  auto empty_list = std::make_shared<MethodList>();
  for (auto root : roots) {
    work_list.emplace_back(root, empty_list);
  }

  schema_os
      << "# Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "# All rights reserved.\n"
      << "#\n"
      << "# This source code is licensed in accordance with the terms specified in\n"
      << "# the LICENSE file found in the root directory of this source tree.\n\n"
      << "# Auto-generated file; do not modify!\n\n"
      << "@0xa04be7b45e95b659;\n\n"
      << "using Cxx = import \"/capnp/c++.capnp\";\n"
      << "$Cxx.namespace(\"mx::ast\");\n\n";

  lib_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <multiplier/AST.h>\n\n"
      << "#include \"AST.capnp.h\"\n\n"
      << "namespace mx {\n";

  lib_cpp_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include \"AST.h\"\n\n"
      << "namespace mx {\n";

  serialize_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <multiplier/AST.h>\n"
      << "#include <multiplier/AST.capnp.h>\n\n"
      << "namespace pasta {\n";

  serialize_cpp_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include \"Serialize.h\"\n\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include <pasta/Compile/Command.h>\n"
      << "#include <pasta/Compile/Compiler.h>\n"
      << "#include <pasta/Compile/Job.h>\n"
      << "#include <pasta/Util/ArgumentVector.h>\n\n"
      << "#include \"Serializer.h\"\n\n"
      << "namespace indexer {\n\n"
      << "void EntitySerializer::SerializeCodeEntities(\n"
      << "    CodeChunk code, mx::ast::EntityList::Builder builder) {\n"
      << "  serialized_entities.clear();\n"
      << "  code_id = code.code_id;\n"
      << "  auto tokens_builder = builder.initToken(\n"
      << "      static_cast<unsigned>(code.end_index - code.begin_index + 1u));\n"
      << "  for (auto i = code.begin_index; i <= code.end_index; ++i) {\n"
      << "    Serialize(tokens_builder[static_cast<unsigned>(i - code.begin_index)], range[i]);\n"
      << "  }\n";

  // Buffers the struct output so that we can output tag types on an as-
  // needed basis.
  schema_os
      << NameAndHash("struct Token") << " {\n"
      << "  kind @0 :TokenKind;\n"
      << "  data @1 :Text;\n"
      << "}\n\n"
      << NameAndHash("struct TokenRange") << " {\n"
      << "  beginId @0 :UInt64;\n"  // References.
      << "  endId @1 :UInt64;  # Inclusive.\n"
      << "}\n\n";

  include_h_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#pragma once\n\n"
      << "#include <cstdint>\n\n"
      << "namespace pasta {\n";

  // Forward declarations.
  for (const pasta::CXXRecordDecl &record : decls) {
    std::string name = record.Name();
    serialize_h_os << "class " << name << ";\n";

    if (gEntityClassNames.count(name)) {
      std::string snake_name = CapitalCaseToSnakeCase(name);
      std::string camel_name = SnakeCaseToCamelCase(snake_name);
      std::string init_name = "init" + Capitalize(camel_name);
      serialize_cpp_os
          << "  " << name << "_builder = builder." << init_name
          << "(code.num_decls_of_kind[pasta::DeclKind::k"
          << name.substr(0, name.size() - 4) << "]);\n";
    }
  }
  for (const pasta::CXXRecordDecl &record : stmts) {
    std::string name = record.Name();
    serialize_h_os << "class " << name << ";\n";

    if (gEntityClassNames.count(name)) {
      std::string snake_name = CapitalCaseToSnakeCase(name);
      std::string camel_name = SnakeCaseToCamelCase(snake_name);
      std::string init_name = "init" + Capitalize(camel_name);
      serialize_cpp_os
          << "  " << name << "_builder = builder." << init_name
          << "(code.num_stmts_of_kind[pasta::StmtKind::k"
          << name << "]);\n";
    }
  }
  for (const pasta::CXXRecordDecl &record : types) {
    serialize_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::CXXRecordDecl &record : tokens) {
    serialize_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = CxxIntType(tag.IntegerType())) {
      serialize_h_os << "enum class " << tag.Name() << " : " << itype << ";\n";
      include_h_os << "enum class " << tag.Name() << " : " << itype << ";\n";
    }
  }
  serialize_h_os
      << "}  // namespace pasta\n"
      << "namespace indexer {\n";
  include_h_os
      << "}  // namespace pasta\n"
      << "namespace mx {\n";

  std::vector<std::string> class_names;

  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = CxxIntType(tag.IntegerType())) {
      RunOnEnum(tag);
    }
  }

  serialize_h_os
      << "class EntitySerializer;\n"
      << "void Serialize(EntitySerializer &, const pasta::Decl &);\n";

  // Forward declarations.
  for (const pasta::CXXRecordDecl &record : decls) {
    std::string name = record.Name();
    serialize_h_os
        << "void Serialize" << name << "(EntitySerializer &, mx::ast::"
        << name << "::Builder, const pasta::" << name << " &);\n";
  }
  for (const pasta::CXXRecordDecl &record : stmts) {
    auto name = record.Name();
    serialize_h_os
        << "void Serialize" << name << "(EntitySerializer &, mx::ast::"
        << name << "::Builder, const pasta::" << name << " &);\n";
  }

  serialize_cpp_os
      << "  for (const pasta::Decl &decl : code.decls) {\n"
      << "    this->DeclVisitor::Accept(decl);\n"
      << "  }\n"
      << "}\n\n";

  for (const pasta::CXXRecordDecl &record : types) {
    auto name = record.Name();
    serialize_h_os
        << "void Serialize" << name << "(EntitySerializer &, mx::ast::"
        << name << "::Builder, const pasta::" << name << " &);\n";
  }
  for (const pasta::CXXRecordDecl &record : tokens) {
    auto name = record.Name();
    if (name != "Token" && name != "TokenRange") {
      serialize_h_os
          << "void Serialize" << name << "(EntitySerializer &, mx::ast::"
          << name << "::Builder, const pasta::" << name << " &);\n";
    }
  }

  while (!work_list.empty()) {
    auto [cls, parent_methods] = work_list.back();
    work_list.pop_back();
    auto seen_methods = RunOnClass(cls, std::move(parent_methods));
    for (auto derived_cls : cls->derived) {
      work_list.emplace_back(derived_cls, seen_methods);
    }

    // Collect class names for `EntityList`.
    auto class_name = cls->record.Name();
  }

  // The entity list is a storage for zero-or-more entities.
  schema_os << "struct EntityList @0xf26db0d046aab9c9 {\n";
  auto i = 0u;
  for (const auto &class_name : gEntityClassNames) {
    if (class_name != "FileToken") {
      std::string snake_name = CapitalCaseToSnakeCase(class_name);
      std::string camel_name = SnakeCaseToCamelCase(snake_name);
      schema_os
          << "  " << camel_name << " @" << i
          << " :List(" << class_name << ");\n";
      ++i;
    }
  }
  schema_os << "}\n";

  lib_cpp_os << "}  // namespace mx\n";
  lib_h_os << "}  // namespace mx\n";
  include_h_os << "}  // namespace mx\n";
  serialize_h_os << "}  // namespace indexer\n";
  serialize_cpp_os << "}  // namespace indexer\n";

  return EXIT_SUCCESS;
}

int CodeGenerator::RunOnClasses(void) {
  std::vector<std::unique_ptr<ClassHierarchy>> alloc;
  BuildHierarchy(alloc, decls, roots);
  BuildHierarchy(alloc, stmts, roots);
  BuildHierarchy(alloc, types, roots);
  BuildHierarchy(alloc, tokens, roots);
  return RunOnClassHierarchies();
}

int CodeGenerator::RunOnNamespaces(void) {
  for (pasta::NamespaceDecl pasta : pastas) {
    for (auto decl : pasta::DeclContext(pasta).Declarations()) {
      if (auto cls = pasta::CXXRecordDecl::From(decl);
          cls && cls->IsThisDeclarationADefinition()) {
        auto name = cls->Name();
        if (gDeclNames.count(name)) {
          decls.emplace_back(std::move(*cls));
        } else if (gStmtNames.count(name)) {
          stmts.emplace_back(std::move(*cls));
        } else if (gTypeNames.count(name)) {
          types.emplace_back(std::move(*cls));
        } else if (gConcreteClassNames.count(name)) {
          tokens.emplace_back(std::move(*cls));
        }
      } else if (auto e = pasta::EnumDecl::From(decl);
                 e && e->IsThisDeclarationADefinition()) {
        auto name = e->Name();
        if (name != "TokenRole" && name != "TokenContextKind") {
          enums.emplace_back(std::move(*e));
        }
      }
    }
  }

  if (decls.empty()) {
    std::cerr << "Could not locate any declarations.\n";
    return EXIT_FAILURE;

  } else if (stmts.empty()) {
    std::cerr << "Could not locate any statements.\n";
    return EXIT_FAILURE;

//  } else if (types.empty()) {
//    std::cerr << "Could not locate any types.\n";
//    return EXIT_FAILURE;

  } else if (tokens.empty()) {
    std::cerr << "Could not locate pasta::Token.\n";
    return EXIT_FAILURE;

  } else {
    return RunOnClasses();
  }
}

int CodeGenerator::RunOnTranslationUnit(pasta::TranslationUnitDecl tu) {
  for (auto decl : pasta::DeclContext(tu).Declarations()) {
    if (auto ns = pasta::NamespaceDecl::From(decl);
        ns && ns->Name() == "pasta") {
      pastas.emplace_back(std::move(*ns));
    }
  }
  if (pastas.empty()) {
    std::cerr << "Unable to locate 'pasta' namespace.\n";
    return EXIT_FAILURE;
  } else {
    return RunOnNamespaces();
  }
}

CodeGenerator::CodeGenerator(char *argv[])
    : schema_os(argv[3], std::ios::trunc | std::ios::out),
      lib_h_os(argv[4], std::ios::trunc | std::ios::out),
      lib_cpp_os(argv[5], std::ios::trunc | std::ios::out),
      include_h_os(argv[6], std::ios::trunc | std::ios::out),
      serialize_h_os(argv[7], std::ios::trunc | std::ios::out),
      serialize_cpp_os(argv[8], std::ios::trunc | std::ios::out) {}

int main(int argc, char *argv[]) {
  if (9 != argc) {
    std::cerr
        << "Usage: " << argv[0]
        << " PASTA_INCLUDE_PATH LLVM_INCLUDE_PATH LIB_CAPNP LIB_H LIB_CPP INCLUDE_H"
        << std::endl;
    return EXIT_FAILURE;
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto exe_path = maybe_compiler->ExecutablePath();
  std::vector<const char *> cc_args{
      exe_path.c_str(),
      "-x", "c++", "-std=c++20", "-c", __FILE__, "-o", "/dev/null",
      "-isystem", argv[1], "-isystem", argv[2]};

  const pasta::ArgumentVector args(cc_args);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = maybe_command.TakeValue();
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      CodeGenerator cg(argv);
      return cg.RunOnTranslationUnit(maybe_ast.TakeValue().TranslationUnit());
    }
  }

  std::cerr << "No compile jobs.\n";
  return EXIT_FAILURE;
}
