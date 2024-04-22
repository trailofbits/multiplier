// Copyright (c) 2024-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cassert>
#include <gap/core/generator.hpp>
#include <list>
#include <multiplier/Entity.h>
#include <optional>
#include <type_traits>

namespace mx {

// Holds on to a stack of generators of type `V`, often a `std::variant`, and
// generate out values of type `T`.
template <typename V, typename T>
class VariantReducer {
 private:

  template <typename E>
  using GeneratorGetter = gap::generator<V> (E::*)(void) const &;

  template <typename X>
  struct Tag {};

  // Packaged GAP generator.
  struct Generator {
    const VariantEntity lifetime;
    gap::generator<V> generator;
    gap::generator<V>::iterator iterator;

    template <typename E, typename D>
    inline Generator(Tag<E>, Tag<D>, D lifetime_,
                     GeneratorGetter<D> get_generator)
        : lifetime(std::move(lifetime_)),
          generator((reinterpret_cast<const D &>(std::get<E>(lifetime)).*get_generator)()),
          iterator(generator.begin()) {}
  };

  std::list<Generator> generators;
  std::optional<T> yield_val;
 
 public:
  template <typename E, typename Base=E>
  void Enter(E lifetime_, GeneratorGetter<E> get_generator) & {
    generators.emplace_back(Tag<Base>{}, Tag<E>{},
                            std::move(lifetime_), get_generator);
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
