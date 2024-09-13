// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <pasta/AST/Decl.h>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace pasta {
class CXXRecordDecl;
class Type;
}  // namespace pasta

struct ClassHierarchy {
  const pasta::CXXRecordDecl record;
  ClassHierarchy *base{nullptr};
  std::vector<ClassHierarchy *> derived;

  inline ClassHierarchy(pasta::CXXRecordDecl record_)
      : record(std::move(record_)) {}

  static void Build(
      std::vector<std::unique_ptr<ClassHierarchy>> &alloc,
      const std::vector<pasta::CXXRecordDecl> &classes,
      std::vector<ClassHierarchy *> &roots_out);
};

struct AnyEntityStorage {
 public:
  std::unordered_map<std::string, std::vector<unsigned>> max_method_count;
  unsigned next_id{0};
};

struct SpecificEntityStorage {
 public:
  AnyEntityStorage &root;
  std::unordered_map<std::string, unsigned> method_count;

  SpecificEntityStorage(AnyEntityStorage &root_)
      : root(root_) {}

  SpecificEntityStorage(const SpecificEntityStorage &parent)
      : root(parent.root),
        method_count(parent.method_count) {}

  unsigned AddMethod(std::string capnp_type) {
    auto &count = method_count[capnp_type];
    auto &max_count = root.max_method_count[capnp_type];

    if ((count + 1u) > max_count.size()) {
      max_count.push_back(root.next_id++);
    }
    return max_count[count++];
  }
};

std::string SnakeCaseToAPICase(std::string name);

std::string Capitalize(std::string name);

// Convert a `CapitalCase` name into a `snake_case` name.
std::string CapitalCaseToSnakeCase(std::string_view name);

// Convert a `snake_case` name into a `camelCase` name.
std::string SnakeCaseToCamelCase(std::string_view name);

std::string SnakeCaseToEnumCase(std::string_view name);

const char *CxxIntType(const pasta::Type &type);

const char *CxxIntType(const std::optional<pasta::Type> &type);

const char *CxxIntType(const std::optional<pasta::Type> &type);
