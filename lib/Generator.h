// Copyright (c) 2024-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <gap/core/generator.hpp>
#include <multiplier/Entity.h>
#include <optional>
#include <list>

namespace mx {

// Holds on to a stack of generators of type `V`, often a `std::variant`, and
// generate out values of type `T`.
template <typename V, typename T>
class VariantReducer {
 private:
  // Packaged GAP generator.
  struct Generator {
    VariantEntity lifetime;
    gap::generator<V> generator;
    gap::generator<V>::iterator iterator;

    template <typename E>
    inline Generator(E lifetime_, gap::generator<V> (*get_generator)(const E &))
        : lifetime(std::move(lifetime_)),
          generator(get_generator(std::get<E>(lifetime))),
          iterator(generator.begin()) {}
  };

  std::list<Generator> generators;
  std::optional<T> yield_val;
 
 public:
  template <typename E>
  void Enter(E lifetime_, gap::generator<V> (*get_generator)(const E &)) & {
    generators.emplace_back(std::move(lifetime_), get_generator);
  }

  void Yield(T val) & {
    assert(!yield_val.has_value());
    yield_val.emplace(std::move(val));
  }

  // Produce the next valye from the generator. The visitor may be a lambda
  // or a class type. It operates over a variant reducer or one of the variant
  // elements. The `VariantReducer` is done when `Next` returns `std::nullopt`.
  template <typename Vis>
  std::optional<T> Next(Vis &&visitor) & {
    yield_val.reset();

    while (!generators.empty() && !yield_val.has_value()) {
      auto &back = generators.back();
      if (back.iterator == back.generator.end()) {
        generators.pop_back();
        continue;
      }

      V val = std::move(*(back.iterator));
      ++back.iterator;
      if (back.iterator == back.generator.end()) {
        generators.pop_back();
      }

      visitor(*this, std::move(val));
    }

    return std::move(yield_val);
  }
};

}  // namespace mx
