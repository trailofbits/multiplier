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

class BaseUseIteratorImpl {
 public:
  std::shared_ptr<EntityProvider> ep;
  std::vector<RawEntityId> search_ids;
  std::vector<FragmentId> fragment_ids;

  inline BaseUseIteratorImpl(std::shared_ptr<EntityProvider> ep_)
      : ep(std::move(ep_)) {}

  void FillAndUniqueFragmentIds(void);
};

class UseIteratorImpl : public BaseUseIteratorImpl {
 public:

  UseIteratorImpl(EntityProvider::Ptr ep_, const Decl &entity);
  UseIteratorImpl(EntityProvider::Ptr ep_, const Stmt &entity);
  UseIteratorImpl(EntityProvider::Ptr ep_, const Type &entity);
  UseIteratorImpl(FragmentImpl::Ptr frag, const Token &entity);

  // Methods for finding the next user.
  bool FindNextDecl(UseIteratorBase &self);
  bool FindNextStmt(UseIteratorBase &self);
  bool FindNextType(UseIteratorBase &self);
  bool FindNextPseudo(UseIteratorBase &self);
  bool FindNext(UseIteratorBase &self);
};

class ReferenceIteratorImpl : public BaseUseIteratorImpl {
 public:

  ReferenceIteratorImpl(EntityProvider::Ptr ep_, const Decl &entity);
};

}  // namespace mx
