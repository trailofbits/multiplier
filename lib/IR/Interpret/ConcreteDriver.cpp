// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/IR/Interpret/ConcreteDriver.h>

namespace mx::ir::interpret {

ConcreteDriver::ConcreteDriver(FunctionResolver func_resolver,
                               GlobalResolver global_resolver)
    : func_resolver_(std::move(func_resolver)),
      global_resolver_(std::move(global_resolver)) {}

Resolution ConcreteDriver::Resolve(const Suspension &s) {
  return std::visit([&](const auto &susp) -> Resolution {
    using T = std::decay_t<decltype(susp)>;

    if constexpr (std::is_same_v<T, NeedBranchDecision>) {
      // Concrete: branch conditions should always be concrete.
      // Default to true path.
      return BranchDecision{.take_true = true, .take_false = false};
    }

    else if constexpr (std::is_same_v<T, NeedCallResolution>) {
      if (func_resolver_) {
        // Try direct target first, then indirect.
        for (auto eid : {susp.target_eid, susp.indirect_target_eid}) {
          if (eid != kInvalidEntityId) {
            if (auto ir = func_resolver_(eid)) {
              return CallResolution{.action = CallAction::INLINE,
                                    .return_value = Undefined{},
                                    .callee_ir = *std::move(ir)};
            }
          }
        }
      }
      return CallResolution{.action = CallAction::SKIP,
                            .return_value = Undefined{}};
    }

    else if constexpr (std::is_same_v<T, NeedGlobalResolution>) {
      if (global_resolver_) {
        if (auto info = global_resolver_(susp.entity_id)) {
          return GlobalResolution{.info = *std::move(info)};
        }
      }
      return GlobalResolution{};
    }

    else if constexpr (std::is_same_v<T, NeedConcretePointer>) {
      // Concrete mode: this shouldn't happen. Return 0.
      return ConcretePointerResolution{.address = 0};
    }

    else {
      // Unreachable for well-typed variants.
      return ConcretePointerResolution{.address = 0};
    }
  }, s);
}

}  // namespace mx::ir::interpret
