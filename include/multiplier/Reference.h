// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

namespace mx {

#define MX_FORWARD_DECLARE(type_name, lower_name, enum_name, category) \
    class type_name;

MX_FOR_EACH_ENTITY_CATEGORY(MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE,
                            MX_FORWARD_DECLARE)
#undef MX_FORWARD_DECLARE

enum ReferenceKind : unsigned {
  INVALID_REFERENCE = 0,
  EXPLICIT_CODE_REFERENCE = 1,
  FIRST_USER_REFERENCE,
  LAST_USER_REFERENCE = ~0u
};

inline static constexpr uint64_t NumEnumerators(ReferenceKind) {
  return static_cast<uint64_t>(~0u) + 1ull;
}

class Reference {
 private:
  std::shared_ptr<const void> impl;
  ReferenceKind kind_{};
  EntityCategory category_{EntityCategory::NOT_AN_ENTITY};
  RawEntityId eid{kInvalidEntityId};

 public:

  inline EntityCategory category(void) const noexcept {
    return category_;
  }

  inline ReferenceKind kind(void) const noexcept {
    return kind_;
  }

#define MX_DECLARE_REF_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name (void) const noexcept;

  MX_FOR_EACH_ENTITY_CATEGORY(MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER,
                              MX_DECLARE_REF_GETTER)
#undef MX_DECLARE_REF_GETTER
};

}  // namespace mx
