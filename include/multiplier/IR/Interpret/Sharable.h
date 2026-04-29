// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.
//
// Sharable<T, Policy> — pick a ref-count system per (class, instantiation)
// at compile time.
//
//   StdShared : T inherits StdSharedBase; lives behind std::shared_ptr.
//   PyObjectRC: T is wrapped in a PyObject<O>; lives behind PyRef<T>.
//
// Class code stays policy-agnostic — only the type alias `ref_t<T>` and
// the allocator `make_sharable<T>` differ. The PyObjectRC arm lives in
// SharablePy.h so this header is Python-free for the CLI.

#pragma once

#include <memory>
#include <type_traits>
#include <utility>

namespace mx::ir::interpret {

// ---------------------------------------------------------------------------
// Policy tags.
// ---------------------------------------------------------------------------

struct StdShared {};
struct PyObjectRC {};

template <typename T, typename Policy>
class Sharable;

// ---------------------------------------------------------------------------
// StdSharedBase — empty, non-templated base. Holds the
// enable_shared_from_this so templates can stay templates without tripping
// libc++/libstdc++ "ambiguous shared_from_this base" checks.
// `ref_from_this()` downcasts via static_pointer_cast<T>.
// ---------------------------------------------------------------------------

class StdSharedBase
    : public std::enable_shared_from_this<StdSharedBase> {
 public:
  virtual ~StdSharedBase(void) = default;
};

// ---------------------------------------------------------------------------
// Sharable<T, StdShared> — pure marker carrying ref_type + ref_from_this.
// ---------------------------------------------------------------------------

template <typename T>
class Sharable<T, StdShared> : public StdSharedBase {
 public:
  using policy_t = StdShared;
  using ref_type = std::shared_ptr<T>;

  std::shared_ptr<T> ref_from_this(void) {
    return std::static_pointer_cast<T>(this->shared_from_this());
  }

  std::shared_ptr<const T> ref_from_this(void) const {
    return std::static_pointer_cast<const T>(this->shared_from_this());
  }
};

// ---------------------------------------------------------------------------
// ref_t<T> — pick the right reference type for T's policy.
// ---------------------------------------------------------------------------

template <typename T>
using ref_t = typename T::ref_type;

// ---------------------------------------------------------------------------
// make_sharable<T>(args...) — canonical allocator.
//
// StdShared arm dispatches to std::make_shared. The PyObjectRC overload
// lives in SharablePy.h; only translation units that include that header
// can allocate PyObjectRC classes.
// ---------------------------------------------------------------------------

template <typename T, typename... Args>
std::enable_if_t<std::is_same_v<typename T::policy_t, StdShared>, ref_t<T>>
make_sharable(Args &&...args) {
  static_assert(
      std::is_base_of_v<Sharable<T, StdShared>, T>,
      "T must inherit Sharable<T, StdShared>");
  return std::make_shared<T>(std::forward<Args>(args)...);
}

}  // namespace mx::ir::interpret
