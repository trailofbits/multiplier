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
#include <vector>

#include <gap/core/generator.hpp>
#include "../Iterator.h"
#include "../Types.h"
#include "../Token.h"
#include "../Use.h"

#include "DeclUseSelector.h"
#include "PseudoKind.h"

namespace mx {
class Designator;
class FieldDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class Designator {
 protected:
  friend class Attr;
  friend class Decl;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Macro;
  friend class ReferenceIteratorImpl;
  friend class Stmt;
  friend class TokenContext;
  friend class Type;
  friend class UseBase;
  friend class UseIteratorImpl;
  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  Designator(Designator &&) noexcept = default;
  Designator(const Designator &) = default;
  Designator &operator=(Designator &&) noexcept = default;
  Designator &operator=(const Designator &) = default;

  inline Designator(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  bool is_field_designator(void) const;
  bool is_array_designator(void) const;
  bool is_array_range_designator(void) const;
  std::optional<FieldDecl> field(void) const;
  TokenRange tokens(void) const;
  Token dot_token(void) const;
  Token field_token(void) const;
  Token left_bracket_token(void) const;
  Token right_bracket_token(void) const;
  Token ellipsis_token(void) const;
  std::optional<unsigned> first_expression_index(void) const;
};

#endif
} // namespace mx
