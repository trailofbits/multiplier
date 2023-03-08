// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/AtomicExprAtomicOp.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(AtomicExprAtomicOp e) {
  switch (e) {
    case AtomicExprAtomicOp::C11_ATOMIC_INITIALIZER: return "C11_ATOMIC_INITIALIZER";
    case AtomicExprAtomicOp::C11_ATOMIC_LOAD: return "C11_ATOMIC_LOAD";
    case AtomicExprAtomicOp::C11_ATOMIC_STORE: return "C11_ATOMIC_STORE";
    case AtomicExprAtomicOp::C11_ATOMIC_EXCHANGE: return "C11_ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_STRONG: return "C11_ATOMIC_COMPARE_EXCHANGE_STRONG";
    case AtomicExprAtomicOp::C11_ATOMIC_COMPARE_EXCHANGE_WEAK: return "C11_ATOMIC_COMPARE_EXCHANGE_WEAK";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_ADD: return "C11_ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_SUB: return "C11_ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_AND: return "C11_ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_OR: return "C11_ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_XOR: return "C11_ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_NAND: return "C11_ATOMIC_FETCH_NAND";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_MAX: return "C11_ATOMIC_FETCH_MAX";
    case AtomicExprAtomicOp::C11_ATOMIC_FETCH_MIN: return "C11_ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::ATOMIC_LOAD: return "ATOMIC_LOAD";
    case AtomicExprAtomicOp::ATOMIC_LOAD_N: return "ATOMIC_LOAD_N";
    case AtomicExprAtomicOp::ATOMIC_STORE: return "ATOMIC_STORE";
    case AtomicExprAtomicOp::ATOMIC_STORE_N: return "ATOMIC_STORE_N";
    case AtomicExprAtomicOp::ATOMIC_EXCHANGE: return "ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::ATOMIC_EXCHANGE_N: return "ATOMIC_EXCHANGE_N";
    case AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE: return "ATOMIC_COMPARE_EXCHANGE";
    case AtomicExprAtomicOp::ATOMIC_COMPARE_EXCHANGE_N: return "ATOMIC_COMPARE_EXCHANGE_N";
    case AtomicExprAtomicOp::ATOMIC_FETCH_ADD: return "ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::ATOMIC_FETCH_SUB: return "ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::ATOMIC_FETCH_AND: return "ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::ATOMIC_FETCH_OR: return "ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::ATOMIC_FETCH_XOR: return "ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::ATOMIC_FETCH_NAND: return "ATOMIC_FETCH_NAND";
    case AtomicExprAtomicOp::ATOMIC_ADD_FETCH: return "ATOMIC_ADD_FETCH";
    case AtomicExprAtomicOp::ATOMIC_SUB_FETCH: return "ATOMIC_SUB_FETCH";
    case AtomicExprAtomicOp::ATOMIC_AND_FETCH: return "ATOMIC_AND_FETCH";
    case AtomicExprAtomicOp::ATOMIC_OR_FETCH: return "ATOMIC_OR_FETCH";
    case AtomicExprAtomicOp::ATOMIC_XOR_FETCH: return "ATOMIC_XOR_FETCH";
    case AtomicExprAtomicOp::ATOMIC_MAX_FETCH: return "ATOMIC_MAX_FETCH";
    case AtomicExprAtomicOp::ATOMIC_MIN_FETCH: return "ATOMIC_MIN_FETCH";
    case AtomicExprAtomicOp::ATOMIC_NAND_FETCH: return "ATOMIC_NAND_FETCH";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_INITIALIZER: return "OPENCL_ATOMIC_INITIALIZER";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_LOAD: return "OPENCL_ATOMIC_LOAD";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_STORE: return "OPENCL_ATOMIC_STORE";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_EXCHANGE: return "OPENCL_ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG: return "OPENCL_ATOMIC_COMPARE_EXCHANGE_STRONG";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK: return "OPENCL_ATOMIC_COMPARE_EXCHANGE_WEAK";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_ADD: return "OPENCL_ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_SUB: return "OPENCL_ATOMIC_FETCH_SUB";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_AND: return "OPENCL_ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_OR: return "OPENCL_ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_XOR: return "OPENCL_ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MIN: return "OPENCL_ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::OPENCL_ATOMIC_FETCH_MAX: return "OPENCL_ATOMIC_FETCH_MAX";
    case AtomicExprAtomicOp::ATOMIC_FETCH_MIN: return "ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::ATOMIC_FETCH_MAX: return "ATOMIC_FETCH_MAX";
    case AtomicExprAtomicOp::HIP_ATOMIC_LOAD: return "HIP_ATOMIC_LOAD";
    case AtomicExprAtomicOp::HIP_ATOMIC_STORE: return "HIP_ATOMIC_STORE";
    case AtomicExprAtomicOp::HIP_ATOMIC_COMPARE_EXCHANGE_WEAK: return "HIP_ATOMIC_COMPARE_EXCHANGE_WEAK";
    case AtomicExprAtomicOp::HIP_ATOMIC_COMPARE_EXCHANGE_STRONG: return "HIP_ATOMIC_COMPARE_EXCHANGE_STRONG";
    case AtomicExprAtomicOp::HIP_ATOMIC_EXCHANGE: return "HIP_ATOMIC_EXCHANGE";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_ADD: return "HIP_ATOMIC_FETCH_ADD";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_AND: return "HIP_ATOMIC_FETCH_AND";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_OR: return "HIP_ATOMIC_FETCH_OR";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_XOR: return "HIP_ATOMIC_FETCH_XOR";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_MIN: return "HIP_ATOMIC_FETCH_MIN";
    case AtomicExprAtomicOp::HIP_ATOMIC_FETCH_MAX: return "HIP_ATOMIC_FETCH_MAX";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
