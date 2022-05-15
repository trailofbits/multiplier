// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Use.h>

#include <vector>

#include "API.h"

namespace mx {

class UseIteratorImpl {
 public:
  std::shared_ptr<EntityProvider> ep;
  std::vector<RawEntityId> search_ids;
  std::vector<FragmentId> fragment_ids;

  std::shared_ptr<const FragmentImpl> fragment;

  unsigned fragment_offset{0};
  unsigned list_offset{0};

  enum List {
    kDecl,
    kStmt,
    kType,
    kPseudo,
  } list{kDecl};

  UseIteratorImpl(std::shared_ptr<EntityProvider> ep_, Decl &entity);
  UseIteratorImpl(std::shared_ptr<EntityProvider> ep_, Stmt &entity);
  // TODO(pag): Add `Type` and `Token` use iterators!!

  bool FindNextDecl(std::optional<UseBase> &use);
  bool FindNextStmt(std::optional<UseBase> &use);
  bool FindNextType(std::optional<UseBase> &use);
  bool FindNextPseudo(std::optional<UseBase> &use);
  bool FindNext(std::optional<UseBase> &use);
};

}  // namespace mx
