// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <Python.h>

#include <sstream>

#pragma GCC visibility push(hidden)
namespace mx {

class PyErrorStreamer {
 public:
  explicit PyErrorStreamer(::PyObject *exc_) : exc(exc_) {}

  ~PyErrorStreamer(void);

  template <typename T>
  inline PyErrorStreamer &operator<<(const T &val) {
    ss << val;
    return *this;
  }

 private:
  PyErrorStreamer(void) = delete;

  ::PyObject * const exc;
  std::stringstream ss;
};

}  // namespace mx
#pragma GCC visibility pop
