// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <optional>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "EntityMapper.h"

namespace indexer {

class PendingFragmentType {
 public:
  inline PendingFragmentType(mx::PackedFragmentId fragment_id_)
      : fragment_id(fragment_id_),
        fragment_index(fragment_id.Unpack().fragment_id) {}

  mx::PackedFragmentId fragment_id;
  mx::RawEntityId fragment_index;

  std::optional<FileLocationOfFragment> file_location;

  std::vector<pasta::Type> top_level_types;

  unsigned num_top_level_types{0u};
  unsigned begin_index{0u};
  unsigned end_index{0u};


  std::vector<pasta::Decl> decls_in_use;
  std::vector<pasta::Stmt> stmts_in_use;
  std::vector<pasta::Type> types_in_use;
  std::vector<pasta::Attr> attrs_in_use;

  void Uses(const pasta::Decl &entity);
  void Uses(const pasta::Stmt &entity);
  void Uses(const pasta::Type &entity);
  void Uses(const pasta::Attr &entity);

};

}
