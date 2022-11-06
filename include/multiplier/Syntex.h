// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <filesystem>
#include "Entities/Attr.h"
#include "Entities/Decl.h"
#include "Entities/Designator.h"
#include "Entities/Stmt.h"
#include "Entities/Type.h"
#include "File.h"
#include "Index.h"
#include "Token.h"

namespace mx {
namespace syntex {

class Grammar;
class GrammarImpl;
class ParsedQuery;
class ParsedQueryImpl;
class Match;

//
// Handle to a persistent grammar
//

class Grammar {
private:
  friend class ParsedQuery;

  std::shared_ptr<GrammarImpl> impl;
  Grammar() = delete;

public:
  explicit Grammar(const mx::Index &index, std::filesystem::path grammar_dir);
};

//
// Chunk of a fragment (potentially) matching a metavariable
//

class MetavarMatch {
private:
  std::string_view name;
  mx::VariantEntity entity;
  mx::TokenRange token_range;

public:
  MetavarMatch(std::string_view name_, mx::VariantEntity entity_,
               mx::TokenRange token_range_)
    : name(std::move(name_)),
      entity(std::move(entity_)),
      token_range(std::move(token_range_)) {}

  const std::string_view &Name(void) const {
    return name;
  }

  const mx::VariantEntity &Entity(void) const {
    return entity;
  }

  const mx::TokenRange &TokenRange(void) const {
    return token_range;
  }
};


//
// Result of parsing a query
//

class ParsedQuery {
 private:
  std::shared_ptr<ParsedQueryImpl> impl;
  ParsedQuery(void) = delete;

 public:
  explicit ParsedQuery(const Grammar &grammar, std::string_view query);

  bool IsValid() const;

  bool AddMetavarPredicate(const std::string_view &name,
                           std::function<bool(const MetavarMatch&)> predicate);

  void ForEachMatch(const mx::Fragment &frag,
                    std::function<bool(Match)> pred) const;
  void ForEachMatch(const mx::File &file,
                    std::function<bool(Match)> pred) const;
  void ForEachMatch(std::function<bool(Match)> pred) const;

  std::vector<Match> Find(const mx::Fragment &frag) const;
  std::vector<Match> Find(const mx::File &file) const;
  std::vector<Match> Find(void) const;

  std::vector<Match> FindInFragment(mx::RawEntityId fragment_id) const;
};

//
// Chunk of a ParsedQuery that matched against a part of a fragment
//

class Match {
private:
  friend class ParsedQuery;

  mx::Fragment fragment;
  mx::VariantEntity entity;
  mx::TokenRange token_range;

  std::vector<MetavarMatch> metavars;

public:
  Match(mx::Fragment fragment_, mx::VariantEntity entity_,
        mx::TokenRange token_range_, std::vector<MetavarMatch> matevars_)
    : fragment(std::move(fragment_)),
      entity(std::move(entity_)),
      token_range(std::move(token_range_)),
      metavars(std::move(matevars_)) {}

  const mx::Fragment &Fragment(void) const {
    return fragment;
  }

  const mx::VariantEntity &Entity(void) const {
    return entity;
  }

  const mx::TokenRange &TokenRange(void) const {
    return token_range;
  }

  mx::RawEntityId FirstTokenId(void) const {
    return TokenRange().front().id();
  }

  mx::RawEntityId LastTokenId(void) const {
    return TokenRange().back().id();
  }

  const std::vector<MetavarMatch> &MetavarMatches(void) const {
    return metavars;
  }

  const MetavarMatch &MetavarMatch(size_t i) const {
    return metavars[i];
  }
};

}  // namespace syntex
}  // namespace mx