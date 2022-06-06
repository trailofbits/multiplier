// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <cassert>
#include <functional>
#include <multiplier/File.h>
#include <multiplier/Iterator.h>
#include <multiplier/Types.h>
#include <multiplier/Use.h>
#include <optional>
#include <variant>

#include "Tables.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {

enum class ConstraintType { None, EntityId, FragmentId };

// FIXME(frabert): May the Lispers have mercy on my soul

static std::optional<mx::FragmentId> FragmentContaining(mx::EntityId id) {
  auto var{id.Unpack()};
  if (std::holds_alternative<mx::DeclarationId>(var)) {
    return std::get<mx::DeclarationId>(var).fragment_id;
  } else if (std::holds_alternative<mx::StatementId>(var)) {
    return std::get<mx::StatementId>(var).fragment_id;
  } else if (std::holds_alternative<mx::TypeId>(var)) {
    return std::get<mx::TypeId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FragmentTokenId>(var)) {
    return std::get<mx::FragmentTokenId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FileTokenId>(var)) {
    return std::nullopt;
  } else if (std::holds_alternative<mx::TokenSubstitutionId>(var)) {
    return std::get<mx::TokenSubstitutionId>(var).fragment_id;
  } else {
    assert(false);
  }
}

template <typename T> struct FromEntityId;

template <> struct FromEntityId<mx::Decl> {
  std::optional<mx::Decl> get(mx::Index &index, mx::EntityId id) {
    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Decl>(variant)) {
      return std::get<mx::Decl>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Stmt> {
  std::optional<mx::Stmt> get(mx::Index &index, mx::EntityId id) {
    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Stmt>(variant)) {
      return std::get<mx::Stmt>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Type> {
  std::optional<mx::Type> get(mx::Index &index, mx::EntityId id) {
    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Type>(variant)) {
      return std::get<mx::Type>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Token> {
  std::optional<mx::Token> get(mx::Index &index, mx::EntityId id) {
    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Token>(variant)) {
      return std::get<mx::Token>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::TokenSubstitution> {
  std::optional<mx::TokenSubstitution> get(mx::Index &index, mx::EntityId id) {
    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::TokenSubstitution>(variant)) {
      return std::get<mx::TokenSubstitution>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::TemplateParameterList> {
  std::optional<mx::TemplateParameterList> get(mx::Index &index,
                                               mx::EntityId id) {
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::TemplateArgument> {
  std::optional<mx::TemplateArgument> get(mx::Index &index, mx::EntityId id) {
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::CXXBaseSpecifier> {
  std::optional<mx::CXXBaseSpecifier> get(mx::Index &index, mx::EntityId id) {
    return std::nullopt;
  }
};

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

enum class FieldType { Integer, Text };

using FieldGetter = void(mx::Index index, mx::EntityId id,
                         sqlite3_context *ctx);

struct FieldDescriptor {
  std::string name;
  FieldType type;
  bool nullable;
  FieldGetter *getter;

  FieldDescriptor(std::string name, FieldType type, bool nullable,
                  FieldGetter *getter)
      : name(name), type(type), nullable(nullable), getter(getter) {}
};

/* Schema definitions */
#define MX_BEGIN_VISIT_DECL(NAME) static std::vector<FieldDescriptor> NAME##Table_fields({
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL(TYPE, NAME, ...)                                         \
  FieldDescriptor(#NAME, FieldType::Integer, false,                            \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    sqlite3_result_int64(                                      \
                        ctx, static_cast<std::int64_t>(entity->NAME()));       \
                  }),
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_ENTITY(TYPE, NAME, ...)                                       \
  FieldDescriptor(#NAME, FieldType::Integer, false,                            \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    sqlite3_result_int64(                                      \
                        ctx, static_cast<std::int64_t>(entity->NAME().id()));  \
                  }),
#define MX_VISIT_TEXT(TYPE, NAME, ...)                                         \
  FieldDescriptor(#NAME, FieldType::Text, false,                               \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    auto str{entity->NAME()};                                  \
                    sqlite3_result_text(ctx, str.data(), str.size(),           \
                                        SQLITE_STATIC);                        \
                  }),
#define MX_VISIT_OPTIONAL_BOOL(TYPE, NAME, ...)                                \
  FieldDescriptor(#NAME, FieldType::Integer, true,                             \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    auto val{entity->NAME()};                                  \
                    if (val) {                                                 \
                      sqlite3_result_int64(ctx,                                \
                                           static_cast<std::int64_t>(*val));   \
                    } else {                                                   \
                      sqlite3_result_null(ctx);                                \
                    }                                                          \
                  }),
#define MX_VISIT_OPTIONAL_INT MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENTITY(TYPE, NAME, ...)                              \
  FieldDescriptor(#NAME, FieldType::Integer, true,                             \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    auto val{entity->NAME()};                                  \
                    if (val) {                                                 \
                      sqlite3_result_int64(                                    \
                          ctx, static_cast<std::int64_t>(val->id()));          \
                    } else {                                                   \
                      sqlite3_result_null(ctx);                                \
                    }                                                          \
                  }),
#define MX_VISIT_OPTIONAL_TEXT(TYPE, NAME, ...)                                \
  FieldDescriptor(#NAME, FieldType::Text, true,                                \
                  [](mx::Index index, mx::EntityId id, sqlite3_context *ctx) { \
                    FromEntityId<mx::TYPE> helper;                             \
                    auto entity{helper.get(index, id)};                        \
                    assert(entity.has_value());                                \
                    auto val{entity->NAME()};                                  \
                    if (val) {                                                 \
                      sqlite3_result_text(ctx, val->data(), val->size(),       \
                                          SQLITE_STATIC);                      \
                    } else {                                                   \
                      sqlite3_result_null(ctx);                                \
                    }                                                          \
                  }),
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

static std::string
GetCreateTableStatement(const std::vector<FieldDescriptor> &fields) {
  std::string schema{
      "CREATE TABLE vtab(id INTEGER NOT NULL, fragment_id INTEGER, "};
  for (auto desc : fields) {
    schema += desc.name + ' ';
    switch (desc.type) {
    case FieldType::Integer:
      schema += "INTEGER";
      break;
    case FieldType::Text:
      schema += "TEXT";
      break;
    }
    if (desc.nullable) {
      schema += " NOT NULL";
    }
    schema += ", ";
  }
  schema += "PRIMARY KEY(id))";
  return schema;
}

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
    for (int i = 0; i < info->nConstraint; i++) {                              \
      auto constraint = info->aConstraint[i];                                  \
      if (constraint.usable && constraint.iColumn == 0 &&                      \
          constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {                       \
        info->aConstraintUsage[i].argvIndex = 1;                               \
        info->estimatedCost = 1;                                               \
        info->idxNum = static_cast<int>(ConstraintType::EntityId);             \
        return SQLITE_OK;                                                      \
      }                                                                        \
                                                                               \
      if (constraint.usable && constraint.iColumn == 1 &&                      \
          constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {                       \
        info->aConstraintUsage[i].argvIndex = 1;                               \
        info->estimatedCost = 1;                                               \
        info->idxNum = static_cast<int>(ConstraintType::FragmentId);           \
        return SQLITE_OK;                                                      \
      }                                                                        \
    }                                                                          \
                                                                               \
    return SQLITE_OK;                                                          \
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
      entities.clear();                                                        \
      auto constraint{static_cast<ConstraintType>(idxNum)};                    \
      if (constraint == ConstraintType::EntityId) {                            \
        FromEntityId<mx::NAME> helper;                                         \
        auto entity{helper.get(index, sqlite3_value_int64(args[0]))};          \
        if (entity) {                                                          \
          entities.push_back(entity->id());                                    \
        }                                                                      \
      } else if (constraint == ConstraintType::FragmentId) {                   \
        auto fragment{index.fragment(sqlite3_value_int64(args[0]))};           \
        if (fragment) {                                                        \
          for (auto entity : mx::NAME::in(*fragment)) {                        \
            entities.push_back(entity.id());                                   \
          }                                                                    \
        }                                                                      \
      } else {                                                                 \
        for (auto file : mx::File::in(index)) {                                \
          for (auto fragment : mx::Fragment::in(file)) {                       \
            for (auto entity : mx::NAME::in(fragment)) {                       \
              entities.push_back(entity.id());                                 \
            }                                                                  \
          }                                                                    \
        }                                                                      \
      }                                                                        \
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
  TABLE_BESTINDEX(NAME)

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

/* Column extraction */

#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  int NAME##Cursor::Column(sqlite3_context *ctx, int idxCol) {                 \
    switch (idxCol) {                                                          \
    default: {                                                                 \
      if (idxCol - 2 >= NAME##TableSchema.size()) {                            \
        return SQLITE_ERROR;                                                   \
      }                                                                        \
      NAME##TableSchema[idxCol - 2].getter(index, *cur, ctx);                  \
      return SQLITE_OK;                                                        \
    }                                                                          \
    case 0:                                                                    \
      sqlite3_result_int64(ctx, *cur);                                         \
      return SQLITE_OK;                                                        \
    case 1: {                                                                  \
      auto fragment{FragmentContaining(*cur)};                                 \
      if (fragment) {                                                          \
        sqlite3_result_int64(ctx, *fragment);                                  \
      } else {                                                                 \
        sqlite3_result_null(ctx);                                              \
      }                                                                        \
      return SQLITE_OK;                                                        \
    }                                                                          \
    }                                                                          \
  }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#include <multiplier/Visitor.inc.h>

using ListGen = void(mx::Index index, std::int64_t id,
                     std::vector<std::int64_t> &int_results,
                     std::vector<std::string_view> &text_results);

class IntegerListCursor : public VirtualTableCursor {
private:
  mx::Index index;
  mx::EntityId id;
  ListGen *gen;
  std::vector<std::int64_t> values;
  std::size_t cur;

public:
  IntegerListCursor(mx::EntityProvider::Ptr ep, ListGen *gen)
      : index(ep), gen(gen) {}
  virtual ~IntegerListCursor() = default;
  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    values.clear();
    if (idxNum) {
      id = sqlite3_value_int64(args[0]);
      std::vector<std::string_view> tmp;
      gen(index, id, values, tmp);
    }
    cur = 0;
    return SQLITE_OK;
  }
  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }
  virtual int Eof() override { return cur == values.size(); }
  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    default:
      return SQLITE_ERROR;
    case 0:
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(id));
      return SQLITE_OK;
    case 1:
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(cur));
      return SQLITE_OK;
    case 2:
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(values[cur]));
      return SQLITE_OK;
    }
  }
  virtual mx::Result<std::int64_t, int> RowId() override { return 0; }
};

class TextListCursor : public VirtualTableCursor {
private:
  mx::Index index;
  mx::EntityId id;
  ListGen *gen;
  std::vector<std::string_view> values;
  std::size_t cur;

public:
  TextListCursor(mx::EntityProvider::Ptr ep, ListGen *gen)
      : index(ep), gen(gen) {}
  virtual ~TextListCursor() = default;
  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    values.clear();
    if (idxNum) {
      id = sqlite3_value_int64(args[0]);
      std::vector<std::int64_t> tmp;
      gen(index, id, tmp, values);
    }
    cur = 0;
    return SQLITE_OK;
  }
  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }
  virtual int Eof() override { return cur == values.size(); }
  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    default:
      return SQLITE_ERROR;
    case 0:
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(id));
      return SQLITE_OK;
    case 1:
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(cur));
      return SQLITE_OK;
    case 2:
      sqlite3_result_text(ctx, values[cur].data(), values[cur].size(),
                          SQLITE_STATIC);
      return SQLITE_OK;
    }
  }
  virtual mx::Result<std::int64_t, int> RowId() override { return 0; }
};

class ListTable : public VirtualTable {
private:
  mx::EntityProvider::Ptr ep;
  mx::Index index;
  FieldType type;
  ListGen *gen;

public:
  ListTable(mx::EntityProvider::Ptr ep, FieldType type, ListGen *gen)
      : ep(ep), type(type), gen(gen) {}
  virtual ~ListTable() = default;

  virtual std::optional<std::string> Init(sqlite3 *db) override {
    int err;
    switch (type) {
    case FieldType::Integer:
      err = sqlite3_declare_vtab(
          db, "CREATE TABLE vtab(parent_id INTEGER NOT NULL, pos INTEGER "
              "NOT NULL, value INTEGER NOT NULL, PRIMARY KEY(parent_id, pos)) "
              "WITHOUT ROWID");
      break;
    case FieldType::Text:
      err = sqlite3_declare_vtab(
          db, "CREATE TABLE vtab(parent_id INTEGER NOT NULL, pos INTEGER "
              "NOT NULL, value TEXT NOT NULL, PRIMARY KEY(parent_id, pos)) "
              "WITHOUT ROWID");
      break;
    }
    if (err != SQLITE_OK) {
      return sqlite3_errmsg(db);
    }
    return std::nullopt;
  }

  virtual int BestIndex(sqlite3_index_info *info) override {
    for (int i = 0; i < info->nConstraint; i++) {
      auto constraint = info->aConstraint[i];
      if (constraint.usable && constraint.iColumn == 0 &&
          constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
        info->aConstraintUsage[i].argvIndex = 1;
        info->estimatedCost = 1;
        info->idxNum = 1;
        return SQLITE_OK;
      }
    }
    return SQLITE_OK;
  }

  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override {
    std::unique_ptr<VirtualTableCursor> cursor;
    if (type == FieldType::Integer) {
      cursor = std::make_unique<IntegerListCursor>(ep, gen);
    } else {
      cursor = std::make_unique<TextListCursor>(ep, gen);
    }
    return mx::Result<std::unique_ptr<VirtualTableCursor>, int>(
        std::move(cursor));
  }
};

struct ListDescriptor {
  std::string name;
  ListGen *gen;
  FieldType type;
  ListDescriptor(std::string name, FieldType type, ListGen *gen)
      : name(name), type(type), gen(gen) {}
};

#define MX_BEGIN_VISIT_DECL(NAME) static std::vector<ListDescriptor> NAME##Table_lists({
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3, NAME,  \
                           ...)                                                \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index index, std::int64_t id,                          \
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
#define MX_VISIT_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3, NAME,  \
                           ...)                                                \
  ListDescriptor(#NAME, FieldType::Text,                                       \
                 [](mx::Index index, std::int64_t id,                          \
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
#define MX_VISIT_ENTITY_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3,      \
                             NAME, ...)                                        \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index index, std::int64_t id,                          \
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

#define MX_VISIT_OPTIONAL_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,        \
                                    IGNORE3, NAME, ...)                        \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index index, std::int64_t id,                          \
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
#define MX_VISIT_OPTIONAL_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,        \
                                    IGNORE3, NAME, ...)                        \
  ListDescriptor(#NAME, FieldType::Text,                                       \
                 [](mx::Index index, std::int64_t id,                          \
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
                                      IGNORE3, NAME, ...)                      \
  ListDescriptor(#NAME, FieldType::Integer,                                    \
                 [](mx::Index index, std::int64_t id,                          \
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