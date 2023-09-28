// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Types.h>

#include <optional>

namespace mx {
namespace {

static constexpr RawEntityId kMinEntityIdIncrement = 1ull;

// If we have more than 2^16 tokens in a given code chunk, then we consider
// this a "big code" chunk. We assume that we'll have few of these, i.e. less
// than 2^16 of them.
//
// NOTE(pag): Fudge factors are to communicate that although we can put a tight
//            bound on the number of tokens, we're really using the number of
//            tokens as a proxy for estimating the size (of anything, e.g.
//            all AST nodes) that need to fit in the fragment.
static constexpr unsigned kBigFragmentIdNumBits = 16u;
static constexpr RawEntityId kMaxBigFragmentId = 1ull << kBigFragmentIdNumBits;

static constexpr uint64_t kNumTokensInBigFragment =
    (1ull << kBigFragmentIdNumBits) / 3u  /* fudge factor */;

static constexpr unsigned kFileIdNumBits = 20u;
static constexpr RawEntityId kMaxFileId = 1ull << kFileIdNumBits;

static constexpr unsigned kBigTypeIdNumBits = 26u;
static constexpr RawEntityId kMaxBigTypeId = 1ull << kBigTypeIdNumBits;

static constexpr unsigned kBigTypeOffsetNumBits = 18u;
static constexpr unsigned kSmallTypeIdNumBits = 36u;
static constexpr RawEntityId kMaxSmallTypeId = (1ull << kSmallTypeIdNumBits) + kMaxBigTypeId;

static constexpr unsigned kTypeOffsetNumBits = 8u;
static constexpr RawEntityId kNumTokensInBigType =
    (1ull << kTypeOffsetNumBits) / 2u  /* fudge factor */;

static constexpr unsigned kCompilationIdNumBits = kFileIdNumBits;
static constexpr RawEntityId kMaxCompilationId = 1ull << kCompilationIdNumBits;

}  // namespace

// Return the fragment offset from an entity ID. Returns `~0u` if it's not
// a fragment-specific entity ID.
std::optional<EntityOffset> FragmentOffsetFromEntityId(RawEntityId id);

// Returns the fragment ID corresponding with a fragment-specific entity ID.
std::optional<PackedFragmentId> FragmentIdFromEntityId(RawEntityId id);

std::optional<PackedTypeId> TypeIdFromEntityId(RawEntityId id);

// Returns the kind of an entity as an undifferentiated integer.
int KindFromEntityId(RawEntityId id);

// Returns the category of entity as an enum.
EntityCategory CategoryFromEntityId(RawEntityId);

}  // namespace mx
