// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <fstream>
#include <iostream>
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

struct ClassHierarchy {
  const pasta::CXXRecordDecl record;
  ClassHierarchy *base{nullptr};
  std::vector<ClassHierarchy *> derived;

  inline ClassHierarchy(pasta::CXXRecordDecl record_)
      : record(std::move(record_)) {}
};

static ClassHierarchy *BuildHierarchy(
    std::vector<std::unique_ptr<ClassHierarchy>> &alloc,
    std::vector<pasta::CXXRecordDecl> classes) {

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
        if (std::islower(name[i + 1u])) {
          ss << '_';
          added_sep = true;
        }
      }
      ss << static_cast<char>(std::tolower(c));
      added_sep = false;
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

static const char *IntType(const std::string &method_name, pasta::Type type) {
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

static int GenerateFromHierarchies(ClassHierarchy *decl,
                                   ClassHierarchy *stmt,
                                   ClassHierarchy *type,
                                   ClassHierarchy *token,
                                   std::ostream &schema_os,
                                   std::ostream &header_os,
                                   std::ostream &impl_os) {

  using MethodList = std::unordered_set<std::string>;

  std::vector<std::pair<ClassHierarchy *, std::shared_ptr<MethodList>>> work_list;
  auto empty_list = std::make_shared<MethodList>();
  work_list.emplace_back(type, empty_list);
  work_list.emplace_back(stmt, empty_list);
  work_list.emplace_back(decl, empty_list);
  work_list.emplace_back(token, std::move(empty_list));

  std::unordered_set<pasta::EnumDecl> seen_enums;

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

  header_os
      << "// Copyright (c) 2022-present, Trail of Bits, Inc.\n"
      << "// All rights reserved.\n"
      << "//\n"
      << "// This source code is licensed in accordance with the terms specified in\n"
      << "// the LICENSE file found in the root directory of this source tree.\n\n"
      << "// Auto-generated file; do not modify!\n\n"
      << "#include <pasta/AST/Decl.h>\n"
      << "#include <pasta/AST/Stmt.h>\n"
      << "#include <pasta/AST/Type.h>\n"
      << "#include \"AST.capnp.h\"\n\n"
      << "namespace mx {\n";

  impl_os
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
  std::stringstream schema_classes_ss;
  std::stringstream header_enum_ss;
  schema_classes_ss
      << NameAndHash("struct TokenOffset") << " {\n"
      << "  offset @0 :UInt32 $Cxx.name(\"offset\");\n"
      << "}\n\n"
      << NameAndHash("struct TokenRange") << " {\n"
      << "  beginOffset @0 :UInt32 $Cxx.name(\"begin_offset\");\n"
      << "  endOffset @1 :UInt32 $Cxx.name(\"end_offset\");  # Inclusive.\n"
      << "}\n\n";

  auto dump_enum = [&] (const std::string &method_name,
                        pasta::EnumDecl enum_decl) -> bool {
    if (seen_enums.emplace(enum_decl).second) {
      auto enum_name = enum_decl.Name();
      schema_os << NameAndHash("enum " + enum_name) << " {\n";
      auto i = 0u;
      for (pasta::EnumConstantDecl val : enum_decl.Enumerators()) {
        auto val_name = val.Name();

        // Take over `kRawIdentifier`, and change it to `kWhitespace`, so that
        // we can use `kUnknown` for errors and such.
        if (val_name == "kRawIdentifier" && enum_name == "TokenKind") {
          val_name = "kWhitespace";
        }

        std::string_view val_name_view = val_name;
        if (val_name_view[0] == 'k') {
          val_name_view = val_name_view.substr(1);
        }

        auto snake_name = CapitalCaseToSnakeCase(val_name_view);
        auto camel_name = SnakeCaseToCamelCase(snake_name);
        schema_os
            << "  " << camel_name << " @" << i << " $Cxx.name(\""
            << snake_name << "\");\n";
        ++i;
      }

      // Add a last item to every enumeration so that we can easily get the
      // number of enumerators.
      schema_os
          << "  numEnumerators @" << i << " $Cxx.name(\"num_enumerators\");\n"
          << "}\n\n";
    }
    return true;
  };

  std::vector<std::string> class_names;

  while (!work_list.empty()) {
    auto [cls, parent_methods] = work_list.back();
    auto seen_methods = std::make_shared<MethodList>(*parent_methods);

    work_list.pop_back();
    for (auto derived_cls : cls->derived) {
      work_list.emplace_back(derived_cls, seen_methods);
    }

    auto name = cls->record.Name();
    schema_classes_ss << NameAndHash("struct " + name) << " {\n";
    class_names.emplace_back(std::move(name));
    auto i = 0u;

    if (cls->base) {
      auto base_name = cls->base->record.Name();
      auto snake_name = CapitalCaseToSnakeCase(base_name);
      auto camel_name = SnakeCaseToCamelCase(snake_name);
      schema_classes_ss << "  " << camel_name << " @" << i << ":"
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
          schema_classes_ss << "  " << camel_name << " @" << i << " :TokenOffset;\n";
          ++i;

        // Handle `pasta::TokenRange`.
        } else if (record_name == "TokenRange") {
          schema_classes_ss << "  " << camel_name << " @" << i << " :TokenRange;\n";
          ++i;

        // Handle `std::string` and `std::string_view`.
        } else if (record_name == "string" || record_name == "basic_string" ||
                   record_name == "string_view" ||
                   record_name == "basic_string_view") {
          schema_classes_ss << "  " << camel_name << " @" << i << " :Text;\n";
          ++i;
        }

      // Handle enumerations return types.
      } else if (auto tag = return_type.AsTagDeclaration()) {
        if (auto enum_decl = pasta::EnumDecl::From(*tag)) {
          if (dump_enum(method_name, std::move(*enum_decl))) {
            schema_classes_ss << "  " << camel_name << " @" << i << " :" << tag->Name()
               << ";\n";
            ++i;
          }
        }

      // Handle integral return types.
      } else if (auto int_type = IntType(method_name, return_type)) {
        schema_classes_ss << "  " << camel_name << " @" << i << " :" << int_type
           << ";\n";
        ++i;
      }
    }

    schema_classes_ss << "}\n\n";
  }

  schema_os << schema_classes_ss.str();

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

  return EXIT_SUCCESS;
}

static int GenerateFromClasses(std::vector<pasta::CXXRecordDecl> decls,
                               std::vector<pasta::CXXRecordDecl> stmts,
                               std::vector<pasta::CXXRecordDecl> types,
                               pasta::CXXRecordDecl token,
                               std::ostream &schema_os,
                               std::ostream &header_os,
                               std::ostream &impl_os) {
  std::vector<pasta::CXXRecordDecl> token_vec;
  token_vec.emplace_back(std::move(token));

  std::vector<std::unique_ptr<ClassHierarchy>> alloc;
  auto decl = BuildHierarchy(alloc, std::move(decls));
  auto stmt = BuildHierarchy(alloc, std::move(stmts));
  auto type = BuildHierarchy(alloc, std::move(types));
  auto token_class = BuildHierarchy(alloc, std::move(token_vec));

  if (!decl) {
    std::cerr << "Could not locate `pasta::Decl`.\n";
    return EXIT_FAILURE;

  } else if (!stmt) {
    std::cerr << "Could not locate `pasta::Stmt`.\n";
    return EXIT_FAILURE;

  } else if (!type) {
    std::cerr << "Could not locate `pasta::Type`.\n";
    return EXIT_FAILURE;

  } else if (!token_class) {
    std::cerr << "Could not locate `pasta::Token`.\n";
    return EXIT_FAILURE;

  } else {
    return GenerateFromHierarchies(decl, stmt, type, token_class,
                                   schema_os, header_os, impl_os);
  }

  return EXIT_SUCCESS;
}

static int GenerateFromNamespaces(std::vector<pasta::NamespaceDecl> pastas,
                                  std::ostream &schema_os,
                                  std::ostream &header_os,
                                  std::ostream &impl_os) {
  std::vector<pasta::CXXRecordDecl> decls;
  std::vector<pasta::CXXRecordDecl> stmts;
  std::vector<pasta::CXXRecordDecl> types;
  std::optional<pasta::CXXRecordDecl> token;
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
          token.swap(cls);
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

  } else if (!token.has_value()) {
    std::cerr << "Could not locate pasta::Token.\n";
    return EXIT_FAILURE;

  } else {
    return GenerateFromClasses(std::move(decls), std::move(stmts),
                               std::move(types), std::move(token.value()),
                               schema_os, header_os,
                               impl_os);
  }
}

static int Generate(pasta::TranslationUnitDecl tu, std::ostream &schema_os,
                    std::ostream &header_os, std::ostream &impl_os) {
  std::vector<pasta::NamespaceDecl> pastas;
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
    return GenerateFromNamespaces(std::move(pastas), schema_os, header_os,
                                  impl_os);
  }
}

int main(int argc, char *argv[]) {
  if (6 != argc) {
    std::cerr
        << "Usage: " << argv[0]
        << " PASTA_INCLUDE_PATH LLVM_INCLUDE_PATH OUTPUT_SCHEMA OUTPUT_HEADER OUTPUT_IMPL"
        << std::endl;
    return EXIT_FAILURE;
  }

  std::ofstream schema_os(argv[3], std::ios::trunc | std::ios::out);
  std::ofstream header_os(argv[4], std::ios::trunc | std::ios::out);
  std::ofstream impl_os(argv[5], std::ios::trunc | std::ios::out);

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
      return Generate(maybe_ast.TakeValue().TranslationUnit(), schema_os,
                      header_os, impl_os);
    }
  }

  std::cerr << "No compile jobs.\n";
  return EXIT_FAILURE;
}
