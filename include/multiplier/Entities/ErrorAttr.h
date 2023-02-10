// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Reference.h"
#include "../Types.h"
#include "../Token.h"

#include "AttrKind.h"
#include "ErrorAttrSpelling.h"
#include "InheritableAttr.h"

namespace mx {
class Attr;
class ErrorAttr;
class InheritableAttr;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class ErrorAttr : public InheritableAttr {
 private:
  friend class FragmentImpl;
  friend class InheritableAttr;
  friend class Attr;
 public:
  static gap::generator<ErrorAttr> in(const Fragment &frag);
  static gap::generator<ErrorAttr> in(const File &file);
  static gap::generator<ErrorAttr> in(const Index &index);
  static gap::generator<ErrorAttr> containing(const Token &tok);
  bool contains(const Token &tok) const;
  static std::optional<ErrorAttr> by_id(const Index &, EntityId);

  inline static constexpr AttrKind static_kind(void) {
    return AttrKind::ERROR;
  }

  static std::optional<ErrorAttr> from(const Attr &parent);

  inline static std::optional<ErrorAttr> from(const std::optional<Attr> &parent) {
    if (parent) {
      return ErrorAttr::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  inline static std::optional<ErrorAttr> from(const Reference &r) {
    return ErrorAttr::from(r.as_attribute());
  }

  inline static std::optional<ErrorAttr> from(const TokenContext &t) {
    return ErrorAttr::from(t.as_attribute());
  }

  ErrorAttrSpelling semantic_spelling(void) const;
  std::string_view user_diagnostic(void) const;
  bool is_error(void) const;
  bool is_warning(void) const;
};

static_assert(sizeof(ErrorAttr) == sizeof(InheritableAttr));

#endif
} // namespace mx
