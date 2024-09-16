// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <multiplier/Frontend/TokenTree.h>

#include "SharedPyPtr.h"

namespace mx {

// A proxy token tree visitor that lets native code call Python overrides of the
// token tree visitor.
class ProxyTokenTreeVisitor final : public TokenTreeVisitor {
 private:
  ProxyTokenTreeVisitor(void) = delete;

  SharedPyPtr obj;

 public:
  virtual ~ProxyTokenTreeVisitor(void);

  inline explicit ProxyTokenTreeVisitor(::PyObject *obj_)
      : obj(obj_) {}

  // Return `true` if the input substitution should be expanded or not.
  virtual bool should_expand(const MacroSubstitution &sub) const final;

  // Choose which fragment to show.
  virtual Fragment choose(const std::vector<Fragment> &fragments) const final;
};

}  // namespace mx
