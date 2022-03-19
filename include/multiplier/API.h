// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <set>

#include "AST.h"
#include "Types.h"

namespace mx {

class RemoteEntityProviderImpl;

// Provides the APIs with entities.
class EntityProvider {
 public:
  virtual ~EntityProvider(void);

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  virtual std::set<std::pair<std::filesystem::path, FileId>>
  list_files(void) const = 0;
};

// Provides entities from a remote source, i.e. a remote
// server available via `host:port`, or another process
// available over a UNIX domain socket `unix:/path`.
class RemoteEntityProvider final : public EntityProvider {
 private:
  const std::unique_ptr<RemoteEntityProviderImpl> impl;

 public:
  RemoteEntityProvider(RemoteEntityProviderImpl *impl_);

  virtual ~RemoteEntityProvider(void);

  static std::shared_ptr<EntityProvider> Create(
      std::string host, std::string port);

  // Get the current list of parsed files, where the minimum ID
  // in the returned list of fetched files will be `start_at`.
  std::set<std::pair<std::filesystem::path, FileId>>
  list_files(void) const final;
};

}  // namespace mx
