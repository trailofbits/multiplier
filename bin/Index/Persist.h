// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <pasta/Util/File.h>

#include "PendingFragment.h"

namespace indexer {

class IndexingContext;

void PersistFile(mx::WorkerId worker_id, IndexingContext &context, mx::RawEntityId file_id,
                 std::string file_hash, pasta::File file);

void PersistFragment(mx::WorkerId worker_id, IndexingContext &context,
                     pasta::AST &ast,
                     NameMangler &mangler,
                     EntityIdMap &entity_ids,
                     FileIdMap &file_ids,
                     const pasta::TokenRange &tokens,
                     PendingFragment fragment);

}  // namespace indexer
