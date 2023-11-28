// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Reference.h>

#include <multiplier/Index.h>
#include <utility>

#pragma GCC visibility push(hidden)
namespace mx {

class ReferenceKindImpl {
 public:
  const EntityProviderPtr ep;
  const RawEntityId kind_id;
  const std::string kind_data;

  inline ReferenceKindImpl(EntityProviderPtr ep_, RawEntityId kind_id_,
                           std::string kind_data_)
      : ep(std::move(ep_)),
        kind_id(kind_id_),
        kind_data(std::move(kind_data_)) {}
};

gap::generator<Reference> EmptyReferences(void);

gap::generator<Reference> References(EntityProviderPtr ep, RawEntityId raw_id);

}  // namespace mx
#pragma GCC visibility pop
