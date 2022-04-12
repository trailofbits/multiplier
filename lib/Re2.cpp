// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <multiplier/Re2.h>

#include <re2/re2.h>

namespace mx {

class ReExprImpl {
 public:
  explicit ReExprImpl(std::string_view regex_, bool is_cpp_)
       : qtree(weggli_new_query(query.data(), is_cpp_)),
         is_cpp(is_cpp_) {}
};

ReExpr::ReExpr(std::string_view, bool)
    : impl() {}

ReExpr::~ReExpr(void) {}

void ReExpr::ForEachMatch(
    std::string_view, std::function<bool(const ExprMatchData &)>) const {}

bool ReExpr::IsValid(void) const {
  return true;
}

}
