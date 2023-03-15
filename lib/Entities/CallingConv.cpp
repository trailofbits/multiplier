// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Entities/CallingConv.h>

namespace mx {
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

const char *EnumeratorName(CallingConv e) {
  switch (e) {
    case CallingConv::C: return "C";
    case CallingConv::X86_STD_CALL: return "X86_STD_CALL";
    case CallingConv::X86_FAST_CALL: return "X86_FAST_CALL";
    case CallingConv::X86_THIS_CALL: return "X86_THIS_CALL";
    case CallingConv::X86_VECTOR_CALL: return "X86_VECTOR_CALL";
    case CallingConv::X86_PASCAL: return "X86_PASCAL";
    case CallingConv::WIN64: return "WIN64";
    case CallingConv::X8664_SYS_V: return "X8664_SYS_V";
    case CallingConv::X86_REG_CALL: return "X86_REG_CALL";
    case CallingConv::AAPCS: return "AAPCS";
    case CallingConv::AAPCSVFP: return "AAPCSVFP";
    case CallingConv::INTEL_OCL_BICC: return "INTEL_OCL_BICC";
    case CallingConv::SPIR_FUNCTION: return "SPIR_FUNCTION";
    case CallingConv::OPEN_CL_KERNEL: return "OPEN_CL_KERNEL";
    case CallingConv::SWIFT: return "SWIFT";
    case CallingConv::SWIFT_ASYNC: return "SWIFT_ASYNC";
    case CallingConv::PRESERVE_MOST: return "PRESERVE_MOST";
    case CallingConv::PRESERVE_ALL: return "PRESERVE_ALL";
    case CallingConv::A_ARCH64_VECTOR_CALL: return "A_ARCH64_VECTOR_CALL";
    case CallingConv::A_ARCH64_SVEPCS: return "A_ARCH64_SVEPCS";
    case CallingConv::AMDGPU_KERNEL_CALL: return "AMDGPU_KERNEL_CALL";
    default: return "<invalid>";
  }
}

#pragma GCC diagnostic pop
#endif
}  // namespace mx
