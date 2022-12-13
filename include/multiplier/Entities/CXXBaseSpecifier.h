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

#include "AccessSpecifier.h"
#include "TagTypeKind.h"
#include "TokenUseSelector.h"

namespace mx {
class CXXBaseSpecifier;
class Token;
class Type;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXBaseSpecifier {
 protected:
  friend class Attr;
  friend class AttrIterator;
  friend class Decl;
  friend class DeclIterator;
  friend class File;
  friend class Fragment;
  friend class FragmentImpl;
  friend class Index;
  friend class Stmt;
  friend class StmtIterator;
  friend class TokenContext;
  friend class Type;
  friend class TypeIterator;
  friend class UseBase;
  friend class UseIteratorImpl;
  template <typename> friend class UseIterator;

  std::shared_ptr<const FragmentImpl> fragment;
  unsigned offset_;

 public:
  CXXBaseSpecifier(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier(const CXXBaseSpecifier &) = default;
  CXXBaseSpecifier &operator=(CXXBaseSpecifier &&) noexcept = default;
  CXXBaseSpecifier &operator=(const CXXBaseSpecifier &) = default;

  inline CXXBaseSpecifier(std::shared_ptr<const FragmentImpl> fragment_, unsigned offset__)
      : fragment(std::move(fragment_)),
        offset_(offset__) {}

  TokenRange tokens(void) const;
  Token base_type_token(void) const;
  bool is_virtual(void) const;
  TagTypeKind base_kind(void) const;
  bool is_pack_expansion(void) const;
  bool constructors_are_inherited(void) const;
  std::optional<Token> ellipsis_token(void) const;
  AccessSpecifier semantic_access_specifier(void) const;
  AccessSpecifier lexical_access_specifier(void) const;
  Type base_type(void) const;
};

#endif
} // namespace mx
