// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once
#include <memory>
#include <filesystem>

namespace mx {

class Index;
class Fragment;

}

namespace syntex {

class GrammarImpl;
class QueryImpl;
class Query;

class Grammar {
private:
  friend class Query;
  std::shared_ptr<GrammarImpl> impl;
  Grammar() = delete;
public:
  explicit Grammar(std::filesystem::path grammar_dir);

  // Import a fragment into the grammar. This extends the persisted grammar with
  // the features from this fragment.
  void Import(const mx::Fragment &fragment);
};

class Query {
private:
  std::shared_ptr<QueryImpl> impl;
  Query() = delete;
public:
  explicit Query(const Grammar &grammar, std::string_view query);

  void Execute(const mx::Index &index);
};

}