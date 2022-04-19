// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <iostream>
#include <multiplier/Re2.h>

#include <re2/re2.h>

namespace mx {

class RegExprImpl {
 public:
  explicit RegExprImpl(std::string_view pattern_)
        : pattern(pattern_),
          re(std::make_shared<RE2>("(" + std::string(pattern_) + ")")) {}

  void ForEachMatch(std::string_view contents,
                    std::function<bool(const std::string &pattern,
                                       unsigned begin_offset,
                                       unsigned end_offset)> cb) {
    re2::StringPiece input(contents);
    re2::StringPiece result;
    while(re2::RE2::FindAndConsume(&input, *re.get(), &result)) {
      if (result.empty()) {
        break;
      }
      unsigned begin_offset = static_cast<unsigned>(result.data() - contents.data());
      unsigned end_offset = static_cast<unsigned>(begin_offset + result.size());
      cb(result.data(), begin_offset, end_offset);
    }
  }


 private:
  friend class RegExpr;

  std::shared_ptr<RE2> re;
  std::string_view pattern;
};

RegExpr::RegExpr(std::string_view pattern)
    : impl(std::make_unique<RegExprImpl>(pattern)) {}

RegExpr::~RegExpr(void) {}

void RegExpr::ForEachMatch(
    std::string_view source, std::function<bool(
        const std::string &pattern, unsigned begin_offset,
        unsigned end_offset)> cb) const {
  impl->ForEachMatch(source, cb);
}

bool RegExpr::IsValid(void) const {
  return impl->re != nullptr;
}

}
