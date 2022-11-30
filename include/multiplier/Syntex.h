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

class SyntexQuery;
class SyntexQueryImpl;

//
// Chunk of a fragment (potentially) matching a metavariable
//

class SyntexMetavarMatch {
private:
  std::string name;
  mx::EntityId entity;

public:
  SyntexMetavarMatch(const std::string &name_, mx::EntityId entity_)
    : name(std::move(name_)),
      entity(std::move(entity_)) {}

  const std::string &Name(void) const {
    return name;
  }

  mx::EntityId Entity(void) const {
    return entity;
  }
};

//
// Chunk of a ParsedQuery that matched against a part of a fragment
//

class SyntexMatch {
private:
  friend class SyntexQuery;

  mx::EntityId entity;

  std::vector<SyntexMetavarMatch> metavars;

public:
  SyntexMatch(mx::EntityId entity_, std::vector<SyntexMetavarMatch> matevars_)
    : entity(std::move(entity_)),
      metavars(std::move(matevars_)) {}

  const mx::EntityId &Entity(void) const {
    return entity;
  }

  const std::vector<SyntexMetavarMatch> &MetavarMatches(void) const {
    return metavars;
  }

  const SyntexMetavarMatch &MetavarMatch(size_t i) const {
    return metavars[i];
  }
};

}  // namespace mx
