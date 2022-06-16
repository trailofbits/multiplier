// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <multiplier/Index.h>
#include <optional>
#include <type_traits>
#include <variant>

#include "TableUtils.h"
#include "Tables.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {
// Macros _and_ template metaprogramming? Yes please
#define MX_VISIT_BASE(TYPE, BASE)                                              \
  template <> struct FromEntityId<mx::TYPE> {                                  \
    std::optional<mx::TYPE> get(mx::Index &index, mx::EntityId id);            \
  };
#include "ExtraDecls.inc.h"
#include <multiplier/Visitor.inc.h>

#define MX_VISIT_BASE(TYPE, BASE)                                              \
  std::optional<mx::TYPE> FromEntityId<mx::TYPE>::get(mx::Index &index,        \
                                                      mx::EntityId id) {       \
    FromEntityId<mx::BASE> helper;                                             \
    auto base{helper.get(index, id)};                                          \
    return mx::TYPE::from(base);                                               \
  }
#include "ExtraDecls.inc.h"
#include <multiplier/Visitor.inc.h>

#define MX_VISIT_BASE(NAME, BASE, ...)                                         \
  template <>                                                                  \
  static constexpr inline bool has_containing<mx::NAME> =                      \
      has_containing<mx::BASE>;
#include <multiplier/Visitor.inc.h>

/* Schema definitions */
#define MX_VISIT_BOOL(TYPE, NAME, ...)                                         \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    sqlite3_result_int64(ctx, static_cast<std::int64_t>(entity->NAME()));      \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    return std::nullopt;                                                       \
  }
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_ENTITY(TYPE, NAME, IGNORE0, IGNORE1, IGNORE2, ENTITY_TYPE,    \
                        ...)                                                   \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    sqlite3_result_int64(ctx, static_cast<std::int64_t>(entity->NAME().id())); \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    return entity->NAME().id();                                                \
  }
#define MX_VISIT_TEXT(TYPE, NAME, ...)                                         \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    auto str{entity->NAME()};                                                  \
    sqlite3_result_text(ctx, str.data(), str.size(), SQLITE_TRANSIENT);        \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    return std::nullopt;                                                       \
  }
#define MX_VISIT_OPTIONAL_BOOL(TYPE, NAME, ...)                                \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    auto val{entity->NAME()};                                                  \
    if (val) {                                                                 \
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(*val));              \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    return std::nullopt;                                                       \
  }
#define MX_VISIT_OPTIONAL_INT MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENTITY(TYPE, NAME, IGNORE0, IGNORE1, IGNORE2,        \
                                 ENTITY_TYPE, ...)                             \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    auto val{entity->NAME()};                                                  \
    if (val) {                                                                 \
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(val->id()));         \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    auto sub{entity->NAME()};                                                  \
    if (sub) {                                                                 \
      return sub->id();                                                        \
    } else {                                                                   \
      return std::nullopt;                                                     \
    }                                                                          \
  }
#define MX_VISIT_OPTIONAL_TEXT(TYPE, NAME, ...)                                \
  static void TYPE##SQliteGet##NAME(mx::Index &index, mx::EntityId id,         \
                                    sqlite3_context *ctx) {                    \
    FromEntityId<mx::TYPE> helper;                                             \
    auto entity{helper.get(index, id)};                                        \
    assert(entity.has_value());                                                \
    auto val{entity->NAME()};                                                  \
    if (val) {                                                                 \
      sqlite3_result_text(ctx, val->data(), val->size(), SQLITE_TRANSIENT);    \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
  }                                                                            \
  static std::optional<mx::EntityId> TYPE##Get##NAME##EntityId(                \
      mx::Index &index, mx::EntityId id) {                                     \
    return std::nullopt;                                                       \
  }

#include <multiplier/Visitor.inc.h>

#define MX_BEGIN_VISIT_DECL(NAME) static std::vector<FieldDescriptor> NAME##Table_fields({
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL(TYPE, NAME, ...)                                         \
  FieldDescriptor(#NAME, FieldType::Integer, false, &TYPE##SQliteGet##NAME,    \
                  &TYPE##Get##NAME##EntityId, &FalsePredicate),
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_ENTITY(TYPE, NAME, IGNORE0, IGNORE1, IGNORE2, ENTITY_TYPE,    \
                        ...)                                                   \
  FieldDescriptor(#NAME, FieldType::Integer, false, &TYPE##SQliteGet##NAME,    \
                  &TYPE##Get##NAME##EntityId,                                  \
                  &ContainingPredicate<mx::ENTITY_TYPE>::Predicate),
#define MX_VISIT_TEXT(TYPE, NAME, ...)                                         \
  FieldDescriptor(#NAME, FieldType::Text, false, &TYPE##SQliteGet##NAME,       \
                  &TYPE##Get##NAME##EntityId, &FalsePredicate),
#define MX_VISIT_OPTIONAL_BOOL(TYPE, NAME, ...)                                \
  FieldDescriptor(#NAME, FieldType::Integer, true, &TYPE##SQliteGet##NAME,     \
                  &TYPE##Get##NAME##EntityId, &FalsePredicate),
#define MX_VISIT_OPTIONAL_INT MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENTITY(TYPE, NAME, IGNORE0, IGNORE1, IGNORE2,        \
                                 ENTITY_TYPE, ...)                             \
  FieldDescriptor(#NAME, FieldType::Integer, true, &TYPE##SQliteGet##NAME,     \
                  &TYPE##Get##NAME##EntityId,                                  \
                  &ContainingPredicate<mx::TYPE>::Predicate),
#define MX_VISIT_OPTIONAL_TEXT(TYPE, NAME, ...)                                \
  FieldDescriptor(#NAME, FieldType::Text, true, &TYPE##SQliteGet##NAME,        \
                  &TYPE##Get##NAME##EntityId, &FalsePredicate),
#define MX_END_VISIT_DECL(NAME)                                                \
  });
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  static std::vector<FieldDescriptor> Get##NAME##TableSchema() {               \
    std::vector<FieldDescriptor> fields;                                       \
    auto out_it{std::back_inserter(fields)};
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BASE(NAME, BASE)                                              \
  std::copy(BASE##TableSchema.begin(), BASE##TableSchema.end(), out_it);

#define MX_END_VISIT_DECL(NAME)                                                \
  std::copy(NAME##Table_fields.begin(), NAME##Table_fields.end(), out_it);     \
  return fields;                                                               \
  }                                                                            \
  static std::vector<FieldDescriptor> NAME##TableSchema =                      \
      Get##NAME##TableSchema();
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

/* Class definitions */
#define TABLE_CTOR(NAME)                                                       \
  NAME##Table::NAME##Table(mx::EntityProvider::Ptr ep) : ep(ep), index(ep) {}

#define TABLE_INIT(NAME)                                                       \
  std::optional<std::string> NAME##Table::Init(sqlite3 *db) {                  \
    auto statement{GetCreateTableStatement(NAME##TableSchema)};                \
    int err = sqlite3_declare_vtab(db, statement.c_str());                     \
    if (err != SQLITE_OK) {                                                    \
      return sqlite3_errmsg(db);                                               \
    }                                                                          \
    return std::nullopt;                                                       \
  }

#define TABLE_OPEN(NAME)                                                       \
  mx::Result<std::unique_ptr<VirtualTableCursor>, int> NAME##Table::Open() {   \
    auto cursor{std::make_unique<NAME##Cursor>(ep)};                           \
    return mx::Result<std::unique_ptr<VirtualTableCursor>, int>(               \
        std::move(cursor));                                                    \
  }

#define TABLE_BESTINDEX(NAME)                                                  \
  int NAME##Table::BestIndex(sqlite3_index_info *info) {                       \
    return ::sqlite_bridge::BestIndex(info);                                   \
  }

#define TABLE_FINDFUNCTION(NAME)                                               \
  int NAME##Table::FindFunction(                                               \
      int nArg, const std::string &name,                                       \
      void (**pxFunc)(sqlite3_context *, int, sqlite3_value **),               \
      void **ppArg) {                                                          \
    return ::sqlite_bridge::FindFunction(nArg, name, pxFunc, ppArg);           \
  }

#define TABLE_CURSOR(NAME)                                                     \
  class NAME##Cursor : public VirtualTableCursor {                             \
  private:                                                                     \
    mx::Index index;                                                           \
    std::vector<mx::EntityId> entities;                                        \
    typename std::vector<mx::EntityId>::iterator cur;                          \
                                                                               \
  public:                                                                      \
    NAME##Cursor(mx::EntityProvider::Ptr ep) : index(ep) {}                    \
    virtual ~NAME##Cursor() = default;                                         \
    virtual int Filter(int idxNum, const char *idxStr,                         \
                       const std::vector<sqlite3_value *> &args) override {    \
      ::sqlite_bridge::Filter<mx::NAME>(idxNum, idxStr, args, index, entities, \
                                        NAME##TableSchema);                    \
      cur = entities.begin();                                                  \
      return SQLITE_OK;                                                        \
    }                                                                          \
    virtual int Next() override {                                              \
      ++cur;                                                                   \
      return SQLITE_OK;                                                        \
    }                                                                          \
    virtual int Eof() override { return cur == entities.end(); }               \
    virtual int Column(sqlite3_context *ctx, int idxCol) override;             \
    virtual mx::Result<std::int64_t, int> RowId() override {                   \
      return static_cast<std::int64_t>(*cur);                                  \
    }                                                                          \
  };

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  TABLE_CURSOR(NAME)                                                           \
  TABLE_CTOR(NAME)                                                             \
  TABLE_INIT(NAME)                                                             \
  TABLE_OPEN(NAME)                                                             \
  TABLE_BESTINDEX(NAME)                                                        \
  TABLE_FINDFUNCTION(NAME)

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  int NAME##Cursor::Column(sqlite3_context *ctx, int idxCol) {                 \
    return ::sqlite_bridge::Column(ctx, idxCol, index, *cur,                   \
                                   NAME##TableSchema);                         \
  }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

#define MX_BEGIN_VISIT_DECL(NAME) static std::vector<ListDescriptor> NAME##Table_lists({
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, NAME, ...)      \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &result,                         \
                    std::vector<std::string_view> &tmp) {                      \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   for (auto value : coll) {                                   \
                     result.push_back(static_cast<std::int64_t>(value));       \
                   }                                                           \
                 }),
#define MX_VISIT_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, NAME, ...)      \
  ListDescriptor(#NAME, FieldType::Text,                                       \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &tmp,                            \
                    std::vector<std::string_view> &result) {                   \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   for (auto value : coll) {                                   \
                     result.push_back(value);                                  \
                   }                                                           \
                 }),
#define MX_VISIT_ENTITY_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, NAME, ...)    \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &result,                         \
                    std::vector<std::string_view> &tmp) {                      \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   for (auto value : coll) {                                   \
                     result.push_back(static_cast<std::int64_t>(value.id()));  \
                   }                                                           \
                 }),

#define MX_VISIT_OPTIONAL_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, NAME,  \
                                    ...)                                       \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &result,                         \
                    std::vector<std::string_view> &tmp) {                      \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   if (!coll) {                                                \
                     return;                                                   \
                   }                                                           \
                   for (auto value : *coll) {                                  \
                     result.push_back(static_cast<std::int64_t>(value));       \
                   }                                                           \
                 }),
#define MX_VISIT_OPTIONAL_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, NAME,  \
                                    ...)                                       \
  ListDescriptor(#NAME, FieldType::Text,                                       \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &tmp,                            \
                    std::vector<std::string_view> &result) {                   \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   if (!coll) {                                                \
                     return;                                                   \
                   }                                                           \
                   for (auto value : *coll) {                                  \
                     result.push_back(value);                                  \
                   }                                                           \
                 }),
#define MX_VISIT_OPTIONAL_ENTITY_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,      \
                                      NAME, ...)                               \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index &index, std::int64_t id,                         \
                    std::vector<std::int64_t> &result,                         \
                    std::vector<std::string_view> &tmp) {                      \
                   FromEntityId<mx::TABLE> helper;                             \
                   auto entity{helper.get(index, id)};                         \
                   if (!entity) {                                              \
                     return;                                                   \
                   }                                                           \
                   auto coll = entity->LOWERCASE();                            \
                   if (!coll) {                                                \
                     return;                                                   \
                   }                                                           \
                   for (auto value : *coll) {                                  \
                     result.push_back(static_cast<std::int64_t>(value.id()));  \
                   }                                                           \
                 }),

#define MX_END_VISIT_DECL(NAME)                                                \
  });
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  static std::vector<ListDescriptor> Get##NAME##TableLists() {                 \
    std::vector<ListDescriptor> fields;                                        \
    auto out_it{std::back_inserter(fields)};
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BASE(NAME, BASE)                                              \
  std::copy(BASE##TableLists.begin(), BASE##TableLists.end(), out_it);

#define MX_END_VISIT_DECL(NAME)                                                \
  std::copy(NAME##Table_lists.begin(), NAME##Table_lists.end(), out_it);       \
  return fields;                                                               \
  }                                                                            \
  static std::vector<ListDescriptor> NAME##TableLists = Get##NAME##TableLists();
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

std::unique_ptr<VirtualTable> GetListTable(mx::EntityProvider::Ptr ep,
                                           const std::string &name) {
  std::string s;
#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  s = #NAME;                                                                   \
  for (auto &list : NAME##TableLists) {                                        \
    if (name == s + list.name) {                                               \
      return std::make_unique<ListTable>(ep, list.type, list.gen);             \
    }                                                                          \
  }
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>
  return nullptr;
}

} // namespace sqlite_bridge