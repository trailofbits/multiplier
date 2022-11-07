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

//
// Chunk of a fragment (potentially) matching a metavariable
//

class MetavarMatch {
private:
  std::string_view name;
  mx::EntityId entity;

public:
  MetavarMatch(std::string_view name_, mx::EntityId entity_)
    : name(std::move(name_)),
      entity(std::move(entity_)) {}

  const std::string_view &Name(void) const {
    return name;
  }

  mx::EntityId Entity(void) const {
    return entity;
  }
};

//
// Chunk of a ParsedQuery that matched against a part of a fragment
//

class Match {
private:
  friend class ParsedQuery;

  mx::EntityId entity;

  std::vector<MetavarMatch> metavars;

public:
  Match(mx::EntityId entity_, std::vector<MetavarMatch> matevars_)
    : entity(std::move(entity_)),
      metavars(std::move(matevars_)) {}

  const mx::EntityId &Entity(void) const {
    return entity;
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