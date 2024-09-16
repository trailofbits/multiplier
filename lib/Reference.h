// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Reference.h>

#include <type_traits>
#include <utility>

#include "EntityProvider.h"

namespace mx {

enum class BuiltinReferenceKind : int;

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

// Generate references to a specific type of decl.
template <typename Derived>
static gap::generator<Derived> BuiltinDeclReferences(
    EntityProvider::Ptr ep, RawEntityId id, BuiltinReferenceKind kind_id,
    EntityProvider::ReferenceDirection direction, bool get_redecls=true) {

  const auto kKindId = static_cast<RawEntityId>(kind_id);

  for (auto [to_id, context_id] : ep->SpecificReferences(ep, id, kKindId,
                                                         direction,
                                                         get_redecls)) {

    auto decl_id = EntityId(to_id).Extract<DeclId>();
    if (!decl_id) {
      continue;
    }

    auto eptr = ep->DeclFor(ep, to_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    if constexpr (std::is_same_v<Derived, Decl>) {
      co_yield Decl(std::move(eptr));
    } else {
      Decl base_decl(std::move(eptr));
      if (auto derived_decl = Derived::from(base_decl)) {
        co_yield std::move(derived_decl.value());
      }
    }
  }
}

}  // namespace mx
