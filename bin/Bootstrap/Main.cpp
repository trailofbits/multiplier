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
  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, STR_NAME)
};

static const std::unordered_set<std::string> gConcreteClassNames{
  PASTA_FOR_EACH_DECL_IMPL(DECL_NAME, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_STMT_IMPL(STR_NAME, STR_NAME, STR_NAME, STR_NAME, STR_NAME, PASTA_IGNORE_ABSTRACT)
  PASTA_FOR_EACH_TYPE_IMPL(TYPE_NAME, PASTA_IGNORE_ABSTRACT)
};

struct ClassHierarchy {
  const pasta::CXXRecordDecl record;
  ClassHierarchy *base{nullptr};
  std::vector<ClassHierarchy *> derived;

  inline ClassHierarchy(pasta::CXXRecordDecl record_)
      : record(std::move(record_)) {}
};

static ClassHierarchy *BuildHierarchy(
    std::vector<std::unique_ptr<ClassHierarchy>> &alloc,
    const std::vector<pasta::CXXRecordDecl> &classes) {

  std::unordered_map<pasta::CXXRecordDecl, ClassHierarchy *> hmap;

  ClassHierarchy *root = nullptr;
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
       assert(!root);
       root = h;
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

  return root;
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
        if (std::islower(name[i + 1u]) || std::isdigit(name[i + 1u])) {
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
  for (auto c : name) {
    if ('_' == c) {
      ++uc;

    } else if (!uc) {
      ss << c;
      cs = true;

    // Multiple `_`s inside of something else, e.g. `kw__attribute`.
    } else if (cs) {
      if (!cs) {
        ss << "uc";
        --uc;
        cs = true;
      }
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
      case pasta::BuiltinTypeKind::kCharacterS: return "int8_t";  // `char`.
      case pasta::BuiltinTypeKind::kCharacterU: return "uint8_t";  // `char`.
      case pasta::BuiltinTypeKind::kSChar: return "int8_t";  // `signed char`.
      case pasta::BuiltinTypeKind::kUChar: return "uint8_t";  // `unsigned char`.
      case pasta::BuiltinTypeKind::kShort: return "int16_t";
      case pasta::BuiltinTypeKind::kUShort: return "uint16_t";
      case pasta::BuiltinTypeKind::kInt: return "int32_t";
      case pasta::BuiltinTypeKind::kUInt: return "uint32_t";
      case pasta::BuiltinTypeKind::kLong: return "int64_t";
      case pasta::BuiltinTypeKind::kULong: return "uint64_t";
      case pasta::BuiltinTypeKind::kLongLong: return "int64_t";
      case pasta::BuiltinTypeKind::kULongLong: return "uint64_t";
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
  ClassHierarchy *decl{nullptr};
  ClassHierarchy *stmt{nullptr};
  ClassHierarchy *type{nullptr};
  ClassHierarchy *token{nullptr};

  std::ofstream schema_os;
  std::ofstream lib_h_os;
  std::ofstream lib_cpp_os;
  std::ofstream include_h_os;

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
  schema_os << NameAndHash("enum " + enum_name) << " {\n";
  include_h_os << "enum class " << enum_name << " : unsigned short {\n";
  lib_cpp_os
      << enum_name << " FromPasta(pasta::" << enum_name << " e) {\n"
      << "  switch (e) {\n";

  std::unordered_set<std::string> seen_initializers;
  std::string initializer;
  llvm::raw_string_ostream initializer_ss(initializer);

  auto i = 0u;
  for (pasta::EnumConstantDecl val : enum_decl.Enumerators()) {
    auto val_name = val.Name();
    auto orig_val_name = val_name;

    // Don't allow repeats of the underlying values.
    auto ap_val = val.InitializerVal();
    ap_val.print(initializer_ss, ap_val.isSigned());
    initializer_ss.flush();
    if (!seen_initializers.emplace(std::move(initializer)).second) {
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
          << "    case pasta::TokenKind::kRawIdentifier: return TokenKind::IDENTIFIER;\n";
    } else {
      lib_cpp_os
          << "    case pasta::" << enum_name << "::" << orig_val_name
          << ": return " << enum_name << "::" << enum_case << ";\n";
    }

    schema_os
        << "  " << camel_name << " @" << i << " $Cxx.name(\""
        << snake_name << "\");\n";

    include_h_os
        << "  " << enum_case << ",\n";
    ++i;
  }

  lib_cpp_os
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

MethodListPtr CodeGenerator::RunOnClass(
    ClassHierarchy *cls, MethodListPtr parent_methods) {
  auto seen_methods = std::make_shared<MethodList>(*parent_methods);
  auto record_name = cls->record.Name();

  // We have our own representation for these.
  if (record_name == "Token" || record_name == "TokenRange") {
    return parent_methods;
  }

  schema_os << NameAndHash("struct " + record_name) << " {\n";
  auto i = 0u;

  if (cls->base) {
    auto base_name = cls->base->record.Name();
    auto snake_name = CapitalCaseToSnakeCase(base_name);
    auto camel_name = SnakeCaseToCamelCase(snake_name);
    schema_os
        << "  " << camel_name << " @" << i << ":"
        << base_name << ";\n";
    ++i;
  }

  for (pasta::CXXMethodDecl method : cls->record.Methods()) {
    auto method_name = method.Name();
    if (method_name == "KindName" ||
        llvm::StringRef(method_name).startswith("operator")) {
      continue;  // E.g. `Decl::KindName()`, `operator==`.
    }
    if (!seen_methods->emplace(method_name).second) {
      continue;
    }

    auto snake_name = CapitalCaseToSnakeCase(method_name);
    auto camel_name = SnakeCaseToCamelCase(snake_name);
    auto return_type = method.ReturnType();
    if (auto record = return_type.AsRecordDeclaration()) {
      auto record_name = record->Name();

      // Handle `pasta::Token`.
      if (record_name == "Token") {
        schema_os << "  " << camel_name << " @" << i << " :Token;\n";
        ++i;

      // Handle `pasta::TokenRange`.
      } else if (record_name == "TokenRange") {
        schema_os << "  " << camel_name << " @" << i << " :TokenRange;\n";
        ++i;

      // Handle `std::string` and `std::string_view`.
      } else if (record_name == "string" || record_name == "basic_string" ||
                 record_name == "string_view" ||
                 record_name == "basic_string_view") {
        schema_os << "  " << camel_name << " @" << i << " :Text;\n";
        ++i;
      }

    // Handle enumerations return types.
    } else if (auto tag = return_type.AsTagDeclaration()) {
      if (auto enum_decl = pasta::EnumDecl::From(*tag)) {
        schema_os
            << "  " << camel_name << " @" << i << " :" << enum_decl->Name()
            << ";\n";
        ++i;
      }

    // Handle integral return types.
    } else if (auto int_type = SchemaIntType(return_type)) {
      schema_os
          << "  " << camel_name << " @" << i << " :" << int_type
          << ";\n";
      ++i;
    }
  }

  schema_os << "}\n\n";
  return seen_methods;
}

int CodeGenerator::RunOnClassHierarchies(void) {

  std::vector<std::pair<ClassHierarchy *, std::shared_ptr<MethodList>>> work_list;
  auto empty_list = std::make_shared<MethodList>();
  work_list.emplace_back(type, empty_list);
  work_list.emplace_back(stmt, empty_list);
  work_list.emplace_back(decl, empty_list);
  work_list.emplace_back(token, std::move(empty_list));

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
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Forward.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Token.h>\n"
      << "#include <pasta/AST/Type.h>\n\n"
      << "#include <pasta/Compile/Compiler.h>\n"
      << "#include <pasta/Util/FileSystem.h>\n\n"
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

  // Buffers the struct output so that we can output tag types on an as-
  // needed basis.
  schema_os
      << NameAndHash("struct Token") << " {\n"
      << "  offset @0 :UInt32 $Cxx.name(\"offset\");\n"
      << "}\n\n"
      << NameAndHash("struct TokenRange") << " {\n"
      << "  beginOffset @0 :UInt32 $Cxx.name(\"begin_offset\");\n"
      << "  endOffset @1 :UInt32 $Cxx.name(\"end_offset\");  # Inclusive.\n"
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
    include_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::CXXRecordDecl &record : stmts) {
    include_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::CXXRecordDecl &record : types) {
    include_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::CXXRecordDecl &record : tokens) {
    include_h_os << "class " << record.Name() << ";\n";
  }
  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = CxxIntType(tag.IntegerType())) {
      include_h_os << "enum class " << tag.Name() << " : " << itype << ";\n";
    }
  }
  include_h_os
      << "}  // namespace pasta\n"
      << "namespace mx {\n";

  std::vector<std::string> class_names;

  for (const pasta::EnumDecl &tag : enums) {
    if (auto itype = CxxIntType(tag.IntegerType())) {
      RunOnEnum(tag);
    }
  }

  while (!work_list.empty()) {
    auto [cls, parent_methods] = work_list.back();
    work_list.pop_back();
    auto seen_methods = RunOnClass(cls, std::move(parent_methods));
    for (auto derived_cls : cls->derived) {
      work_list.emplace_back(derived_cls, seen_methods);
    }

    auto class_name = cls->record.Name();
    if (gConcreteClassNames.count(class_name)) {
      class_names.emplace_back(std::move(class_name));
    }
  }

  // The entity list is a storage for zero-or-more entities.
  schema_os << "struct EntityList @0xf26db0d046aab9c9 {\n";
  auto i = 0u;
  for (const auto &class_name : class_names) {
    auto snake_name = CapitalCaseToSnakeCase(class_name);
    auto camel_name = SnakeCaseToCamelCase(snake_name);
    schema_os
        << "  " << camel_name << " @" << i
        << " :List(" << class_name << ");\n";
    ++i;
  }
  schema_os << "}\n";

  lib_cpp_os << "}  // namespace mx\n";
  lib_h_os << "}  // namespace mx\n";
  include_h_os << "}  // namespace mx\n";

  return EXIT_SUCCESS;
}

int CodeGenerator::RunOnClasses(void) {
  std::vector<std::unique_ptr<ClassHierarchy>> alloc;
  decl = BuildHierarchy(alloc, decls);
  stmt = BuildHierarchy(alloc, stmts);
  type = BuildHierarchy(alloc, types);
  token = BuildHierarchy(alloc, tokens);

  if (!decl) {
    std::cerr << "Could not locate `pasta::Decl`.\n";
    return EXIT_FAILURE;

  } else if (!stmt) {
    std::cerr << "Could not locate `pasta::Stmt`.\n";
    return EXIT_FAILURE;

  } else if (!type) {
    std::cerr << "Could not locate `pasta::Type`.\n";
    return EXIT_FAILURE;

  } else if (!token) {
    std::cerr << "Could not locate `pasta::Token`.\n";
    return EXIT_FAILURE;

  } else {
    return RunOnClassHierarchies();
  }

  return EXIT_SUCCESS;
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
        } else if (name == "Token") {
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

  } else if (types.empty()) {
    std::cerr << "Could not locate any types.\n";
    return EXIT_FAILURE;

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
      include_h_os(argv[6], std::ios::trunc | std::ios::out) {}

int main(int argc, char *argv[]) {
  if (7 != argc) {
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
