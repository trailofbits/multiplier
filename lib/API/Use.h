// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Use.h>
#include <multiplier/Reference.h>

#include <vector>

#include "API.h"
#include "Fragment.h"

namespace mx {

class UseIteratorImpl final {
 public:
  std::shared_ptr<EntityProvider> ep;
  std::vector<RawEntityId> search_ids;
  std::vector<RawEntityId> fragment_ids;
  unsigned fragment_offset{0u};
  unsigned list_offset{0u};

  UseIteratorImpl(EntityProvider::Ptr ep_, const Decl &entity);
  UseIteratorImpl(EntityProvider::Ptr ep_, const Stmt &entity);
  UseIteratorImpl(EntityProvider::Ptr ep_, const Type &entity);
  UseIteratorImpl(EntityProvider::Ptr ep_, const Attr &entity);
  UseIteratorImpl(FragmentImpl::Ptr frag, const Token &entity);

  void FillAndUniqueFragmentIds(void);

  // Methods for finding the next user.
  bool FindNextDecl(UseBase &use);
  bool FindNextStmt(UseBase &use);
  bool FindNextType(UseBase &use);
  bool FindNextAttr(UseBase &use);
  bool FindNextPseudo(UseBase &use);
  bool FindNext(UseBase &use);

  template<typename Selector>
  gap::generator<Use<Selector>> enumerate(void) {
    Use<Selector> use;
    while(!FindNext(use)) {
      co_yield use;
    }
  }
};

}  // namespace mx
