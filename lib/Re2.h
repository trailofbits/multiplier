/*
 * Re2.h
 *
 *  Created on: Apr. 21, 2022
 *      Author: pag
 */

#pragma once

#include <multiplier/Re2.h>

#include <re2/re2.h>
#include <string>

namespace mx {

class RegexQueryImpl {
 public:
  // NOTE(pag): `RE2::FindAndConsume` is a variadic function taking additional
  //            arguments per sub-match, hence the requirement for enclosing
  //            `pattern_` in a match group with `(` and `)`.
  explicit RegexQueryImpl(std::string pattern_);

  void ForEachMatch(std::string_view contents,
                    std::function<bool(std::string_view /* match */,
                                       unsigned /* begin_offset */,
                                       unsigned /* end_offset */)> cb);

  inline bool IsValid(void) const noexcept {
    return re.ok();
  }

  const std::string real_pattern;
  const std::string pattern;
  re2::RE2 re;
};

}  // namespace mx
