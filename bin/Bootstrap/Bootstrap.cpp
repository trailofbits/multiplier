// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Bootstrap.h"

#include <pasta/AST/Decl.h>
#include <pasta/AST/Type.h>
#include <sstream>
#include <string_view>
#include <string>
#include <unordered_map>

void ClassHierarchy::Build(
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
      if (!bases || bases->empty()) {
       h = new ClassHierarchy(cls);
       alloc.emplace_back(h);
       roots_out.push_back(h);
       progress = true;

      } else {
        for (pasta::CXXBaseSpecifier parent : *bases) {
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

std::string SnakeCaseToAPICase(std::string name) {
  if (name == "operator" || name == "namespace" || name == "struct" ||
      name == "class" || name == "if" || name == "else" || name == "default") {
    name.push_back('_');
  }
  return name;
}

std::string Capitalize(std::string name) {
  name[0] = static_cast<char>(std::toupper(name[0]));
  return name;
}

// Convert a `CapitalCase` name into a `snake_case` name.
std::string CapitalCaseToSnakeCase(std::string_view name) {
  std::stringstream ss;

  auto i = 0u;
  auto added_sep = false;
  auto last_was_uc = false;
  auto skip = false;
  for (auto c : name) {
    if (skip) {
      skip = false;
      ++i;
      continue;
    }
    if ('_' == c || '.' == c) {
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

      // Special case `1d`, `2d`, and `3d`.
      if (!added_sep && (i + 2u) < name.size() &&
          (c == '1' || c == '2' || c == '3') &&
           name[i + 1u] == 'd' &&
           std::isupper(name[i + 2u])) {
        ss << '_' << c << 'd' << '_';
        skip = true; // Skip the `d`.
        added_sep = true;

      } else {
        ss << c;
        if (!added_sep && (i + 1u) < name.size()) {
          if (!std::isdigit(name[i + 1u]) && !std::islower(name[i + 1u])) {
            ss << '_';
            added_sep = true;
          }
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
std::string SnakeCaseToCamelCase(std::string_view name) {
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

std::string SnakeCaseToEnumCase(std::string_view name) {
  if (name == "mig_server_routine") {
    return "MIG_SERVER_ROUTINE_";
  } else if (name == "null") {
    return "NULL_";
  } else if (name == "domain") {
    return "DOMAIN_";
  } else if (name == "l_brace_token") {
    return "L_BRACE";
  } else if (name == "r_brace_token") {
    return "R_BRACE";
  }

  std::stringstream ss;
  for (auto c : name) {
    ss << static_cast<char>(std::toupper(c));
  }
  return ss.str();
}

const char *CxxIntType(const pasta::Type &type) {
  auto t = type;
  if (auto bt = pasta::BuiltinType::From(type.UnqualifiedType())) {
    switch (bt->BuiltinKind()) {
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

const char *CxxIntType(const std::optional<pasta::Type> &type) {
  if (type) {
    return CxxIntType(std::move(type.value()));
  } else {
    return nullptr;
  }
}
