// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <fstream>
#include <iostream>
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

static std::string MethodName(std::string_view name) {
  std::stringstream ss;
  std::optional<char> last_c;
  auto sep = "";
  for (auto c : name) {
    if (last_c) {
      if (std::isupper(*last_c) && !std::isupper(c)) {
        ss << sep;
      }
      ss << static_cast<char>(std::tolower(*last_c));
      sep = "_";
    }
    last_c = c;
  }
  if (last_c) {
    ss << static_cast<char>(std::tolower(*last_c));
  }
  return ss.str();
}

static const char *IntType(const std::string &method_name, pasta::Type type) {
  auto t = type;
  if (auto bt = pasta::BuiltinType::From(type.UnqualifiedType())) {
    auto ret = ([&](void) -> const char * {
      switch (bt->Kind()) {
        case pasta::BuiltinTypeKind::kChar_U: return "uint8";
        case pasta::BuiltinTypeKind::kSChar: return "uint8";
        case pasta::BuiltinTypeKind::kUChar: return "int8";
        case pasta::BuiltinTypeKind::kShort: return "int16";
        case pasta::BuiltinTypeKind::kUShort: return "uint16";
        case pasta::BuiltinTypeKind::kInt: return "int32";
        case pasta::BuiltinTypeKind::kUInt: return "uint32";
        case pasta::BuiltinTypeKind::kLong: return "int64";
        case pasta::BuiltinTypeKind::kULong: return "uint64";
        case pasta::BuiltinTypeKind::kLongLong: return "int64";
        case pasta::BuiltinTypeKind::kULongLong: return "uint64";
        // TODO(pag): Think about `bool`.
        default: return nullptr;
      }
    })();
    if (ret) {
      std::cerr << method_name << '\t' << bt->KindName()  << '\t' << ret << '\t';
      for (auto tok : pasta::PrintedTokenRange::Create(t)) {
        std::cerr << ' ' << tok.Data();
      }
      std::cerr << '\n';

      if (method_name == "Redeclarations") {
        assert(false);
      }
      return ret;
    }
  }
  return nullptr;
}

static int GenerateFromHierarchies(ClassHierarchy *decl,
                                   ClassHierarchy *stmt,
                                   ClassHierarchy *type,
                                   std::ostream &os) {

  using MethodList = std::unordered_set<std::string>;

  std::vector<std::pair<ClassHierarchy *, std::shared_ptr<MethodList>>> work_list;
  auto empty_list = std::make_shared<MethodList>();
  work_list.emplace_back(type, empty_list);
  work_list.emplace_back(stmt, empty_list);
  work_list.emplace_back(decl, std::move(empty_list));

  std::unordered_set<pasta::EnumDecl> seen_enums;

  os << "// Auto-generated file; do not modify!\n\n";


  // Buffers the struct output so that we can output tag types on an as-
  // needed basis.
  std::stringstream ss;
  ss << "struct TokenOffset {\n"
     << "  offset:uint;\n"
     << "}\n\n"
     << "struct TokenRange {\n"
     << "  begin_offset:uint;\n"
     << "  end_offset:uint;  // Inclusive.\n"
     << "}\n\n";

  auto dump_enum = [&] (const std::string &method_name,
                        pasta::EnumDecl enum_decl) -> bool {
    if (auto enum_type = IntType(method_name, enum_decl.IntegerType())) {
      if (seen_enums.emplace(enum_decl).second) {
        os << "enum " << enum_decl.Name() << " : " << enum_type
           << " {";
        auto sep = "\n  ";
        for (pasta::EnumConstantDecl val : enum_decl.Enumerators()) {
          std::string val_str;
          llvm::raw_string_ostream val_os(val_str);
          auto ap_val = val.InitializerVal();
          ap_val.print(val_os, ap_val.isSigned());
          os << sep << val.Name() << " = " << val_str;
          sep = ",\n  ";
        }
        os << "\n}\n\n";
      }
      return true;
    }
    return false;
  };

  while (!work_list.empty()) {
    auto [cls, parent_methods] = work_list.back();
    auto seen_methods = std::make_shared<MethodList>(*parent_methods);

    work_list.pop_back();
    for (auto derived_cls : cls->derived) {
      work_list.emplace_back(derived_cls, seen_methods);
    }

    ss << "struct " << cls->record.Name() << " {\n";
    if (cls->base) {
      ss << "  _base:" << cls->base->record.Name() << ";\n";
    }

    for (pasta::CXXMethodDecl method : cls->record.Methods()) {
      auto method_name = method.Name();
      if (!seen_methods->emplace(method_name).second) {
        continue;
      }

      for (auto redecl : method.Redeclarations()) {
        (void) redecl;
      }

      auto return_type = method.ReturnType();
      if (auto record = return_type.AsRecordDeclaration()) {
        auto rname = record->Name();
        if (rname == "Token") {
          ss << "  " << MethodName(method_name) << ":TokenOffset;\n";
        } else if (rname == "TokenRange") {
          ss << "  " << MethodName(method_name) << ":TokenRange;\n";
        }
      } else if (auto tag = return_type.AsTagDeclaration()) {
        if (auto enum_decl = pasta::EnumDecl::From(*tag)) {
          if (dump_enum(method_name, std::move(*enum_decl))) {
            ss << "  " << MethodName(method_name) << ":" << tag->Name() << ";\n";
          }
        }
      } else if (auto int_type = IntType(method_name, return_type)) {
        ss << "  " << MethodName(method_name) << ":" << int_type << ";\n";
      }
    }

    ss << "}\n\n";
  }
  os << ss.str();
  return EXIT_SUCCESS;
}

static int GenerateFromClasses(std::vector<pasta::CXXRecordDecl> decls,
                               std::vector<pasta::CXXRecordDecl> stmts,
                               std::vector<pasta::CXXRecordDecl> types,
                               std::ostream &os) {
  std::vector<std::unique_ptr<ClassHierarchy>> alloc;
  auto decl = BuildHierarchy(alloc, std::move(decls));
  auto stmt = BuildHierarchy(alloc, std::move(stmts));
  auto type = BuildHierarchy(alloc, std::move(types));

  if (!decl) {
    std::cerr << "Could not locate `pasta::Decl`.\n";
    return EXIT_FAILURE;

  } else if (!stmt) {
    std::cerr << "Could not locate `pasta::Stmt`.\n";
    return EXIT_FAILURE;

  } else if (!type) {
    std::cerr << "Could not locate `pasta::Type`.\n";
    return EXIT_FAILURE;

  } else {
    return GenerateFromHierarchies(decl, stmt, type, os);
  }

  return EXIT_SUCCESS;
}

static int GenerateFromNamespaces(std::vector<pasta::NamespaceDecl> pastas,
                                  std::ostream &os) {
  std::vector<pasta::CXXRecordDecl> decls;
  std::vector<pasta::CXXRecordDecl> stmts;
  std::vector<pasta::CXXRecordDecl> types;
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

  } else {
    return GenerateFromClasses(std::move(decls), std::move(stmts),
                               std::move(types), os);
  }
}

static int Generate(pasta::TranslationUnitDecl tu, std::ostream &os) {
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
    return GenerateFromNamespaces(std::move(pastas), os);
  }
}

int main(int argc, char *argv[]) {
  if (4 != argc) {
    std::cerr
        << "Usage: " << argv[0]
        << " PASTA_INCLUDE_PATH LLVM_INCLUDE_PATH OUTPUT_FILE"
        << std::endl;
    return EXIT_FAILURE;
  }

  std::ofstream os(argv[3], std::ios::trunc | std::ios::out);

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
    std::cerr << job.Arguments().Join() << '\n';
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      return Generate(maybe_ast.TakeValue().TranslationUnit(), os);
    }
  }

  std::cerr << "No compile jobs.\n";
  return EXIT_FAILURE;
}
