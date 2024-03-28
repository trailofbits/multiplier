// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "EntityProvider.h"

namespace mx {

class TokenContextReader {
 public:
  using Ptr = std::shared_ptr<const TokenContextReader>;
  using Reader = mx::rpc::TokenContext::Reader;

  virtual ~TokenContextReader(void) noexcept {};

#define MX_FORWARD_DECLARE_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    virtual std::optional<type_name> as_ ## lower_name(RawEntityId entity_id) const = 0;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE_GETTER

  virtual std::optional<Reader> TokenContexts(EntityOffset) const = 0;

  virtual std::optional<unsigned> TokenContextOffsets(EntityOffset) const = 0;
};

class FragmentTokenContextReader : public TokenContextReader {
 private:
  friend class Token;
  friend class TokenReader;

  const FragmentImpl *impl;

 public:
  inline FragmentTokenContextReader(const FragmentImpl *impl_)
      : impl(impl_) {}

  virtual ~FragmentTokenContextReader(void) noexcept {};

#define MX_FORWARD_DECLARE_GETTER(ns_path, type_name, lower_name, enum_name, category) \
    std::optional<type_name> as_ ## lower_name(RawEntityId entity_id) const final;

MX_FOR_EACH_ENTITY_CATEGORY(MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_FORWARD_DECLARE_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            MX_IGNORE_ENTITY_CATEGORY)
#undef MX_FORWARD_DECLARE_GETTER

  std::optional<TokenContextReader::Reader> TokenContexts(EntityOffset) const final;
  std::optional<unsigned> TokenContextOffsets(EntityOffset) const final;
};

} // namespace mx

