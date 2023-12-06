// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Error.h"

namespace mx {

PyErrorStreamer::~PyErrorStreamer(void) {
  PyErr_Clear();
  PyErr_SetString(exc, ss.str().c_str());
}

}  // namespace mx
