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

#include "CXXMethodDecl.h"
#include "DeclKind.h"

namespace mx {
class CXXConversionDecl;
class CXXMethodDecl;
class Decl;
class DeclaratorDecl;
class FunctionDecl;
class NamedDecl;
class Type;
class ValueDecl;
#if !defined(MX_DISABLE_API) || defined(MX_ENABLE_API)
class CXXConversionDecl : public CXXMethodDecl {
 private:
  friend class FragmentImpl;
  friend class CXXMethodDecl;
  friend class FunctionDecl;
  friend class DeclaratorDecl;
  friend class ValueDecl;
  friend class NamedDecl;
  friend class Decl;
 public:
  inline static gap::generator<CXXConversionDecl> in(const Fragment &frag) {
    for(auto e : in_internal(frag)) {
      if(auto d = from(e)) {
        co_yield *d;
      }
    }
  }

  inline static gap::generator<CXXConversionDecl> containing(const Token &tok) {
    for(auto ctx = tok.context(); ctx.has_value(); ctx = ctx->parent()) {
      if(auto d = from(*ctx)) {
        co_yield *d;
      }
    }
  }

  inline bool contains(const Token &tok) {
    auto id_ = id();
    for (auto &parent : CXXConversionDecl::containing(tok)) {
      if (parent.id() == id_) { return true; }
    }
    return false;
  }

  inline static constexpr DeclKind static_kind(void) {
    return DeclKind::CXX_CONVERSION;
  }

  static gap::generator<CXXConversionDecl> containing(const Decl &decl);
  static gap::generator<CXXConversionDecl> containing(const Stmt &stmt);

  bool contains(const Decl &decl);
  bool contains(const Stmt &stmt);

  static std::optional<CXXConversionDecl> from(const TokenContext &c);
  static std::optional<CXXConversionDecl> from(const CXXMethodDecl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<CXXMethodDecl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConversionDecl> from(const FunctionDecl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<FunctionDecl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConversionDecl> from(const DeclaratorDecl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<DeclaratorDecl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConversionDecl> from(const ValueDecl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<ValueDecl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConversionDecl> from(const NamedDecl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<NamedDecl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  static std::optional<CXXConversionDecl> from(const Decl &parent);

  inline static std::optional<CXXConversionDecl> from(const std::optional<Decl> &parent) {
    if (parent) {
      return CXXConversionDecl::from(parent.value());
    } else {
      return std::nullopt;
    }
  }

  Type conversion_type(void) const;
  bool is_explicit(void) const;
  bool is_lambda_to_block_pointer_conversion(void) const;
};

static_assert(sizeof(CXXConversionDecl) == sizeof(CXXMethodDecl));

#endif
} // namespace mx
