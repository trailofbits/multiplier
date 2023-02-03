/*
 * Reference.cpp
 *
 *  Created on: Feb. 3, 2023
 *      Author: pag
 */

#include <multiplier/Reference.h>

#include <cassert>

#include "Attr.h"
#include "Decl.h"
#include "File.h"
#include "Fragment.h"
#include "Macro.h"
#include "Pseudo.h"
#include "Stmt.h"
#include "Token.h"
#include "Type.h"
#include "Types.h"

namespace mx {

std::optional<Token> Reference::as_token(void) const noexcept {
  if (category_ != EntityCategory::TOKEN) {
    return std::nullopt;
  }
  if (!impl) {
    assert(false);
    return std::nullopt;
  }

  auto offset = FragmentOffsetFromEntityId(eid);
  if (!offset) {
    assert(false);
    return std::nullopt;
  }

  return Token(
      TokenReader::Ptr(impl, reinterpret_cast<const TokenReader *>(impl.get())),
      offset.value());
}

#define DEFINE_REF_GETTER(type_name, lower_name, enum_name, category) \
    std::optional<type_name> \
    Reference::as_ ## lower_name (void) const noexcept { \
      if (category_ != EntityCategory::enum_name) { \
        return std::nullopt; \
      } \
      if (!impl) { \
        assert(false); \
        return std::nullopt; \
      } \
      return type_name(type_name ## ImplPtr( \
          impl, reinterpret_cast<const type_name ## Impl *>(impl.get()))); \
    }

MX_FOR_EACH_ENTITY_CATEGORY(DEFINE_REF_GETTER,
                            MX_IGNORE_ENTITY_CATEGORY,
                            DEFINE_REF_GETTER,
                            DEFINE_REF_GETTER)

#undef DEFINE_REF_GETTER

}  // namespace mx
