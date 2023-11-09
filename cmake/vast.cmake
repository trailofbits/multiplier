#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

set(VAST_LIBS
  ${MX_BEGIN_LIBRARY_GROUP}

  VAST::VASTTargetLLVMIR
  VAST::VASTAliasTypeInterface
  VAST::VASTElementTypeInterface
  VAST::VASTCodeGen

  ${MX_END_LIBRARY_GROUP}
)
