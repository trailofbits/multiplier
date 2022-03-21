// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <multiplier/Types.h>
#include <pasta/Util/File.h>

#include "Serializer.h"

namespace indexer {

class IndexingContext;

void PersistFile(IndexingContext &context, mx::FileId file_id,
                 std::string file_hash, pasta::File file);

void PersistFragment(IndexingContext &context, EntitySerializer &serializer,
                     CodeChunk fragment_info);

}  // namespace indexer
