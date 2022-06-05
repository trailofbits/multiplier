// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <cassert>
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

/* Schema definitions */
#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  constexpr const char *NAME##Table_schema =                                   \
      "CREATE TABLE vtab(id INTEGER NOT NULL, fragment_id INTEGER, "
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL(IGNORE, NAME, ...) "" #NAME " INTEGER NOT NULL, "
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_ENTITY MX_VISIT_BOOL
#define MX_VISIT_TEXT(IGNORE, NAME, ...) "" #NAME " TEXT NOT NULL, "
#define MX_VISIT_OPTIONAL_BOOL(IGNORE, NAME, ...) "" #NAME " INTEGER, "
#define MX_VISIT_OPTIONAL_INT MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENTITY MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_TEXT(IGNORE, NAME, ...) "" #NAME " TEXT, "

#define MX_END_VISIT_DECL(NAME) "PRIMARY KEY(id))";
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

/* Column numbers */
#define MX_BEGIN_VISIT_DECL(NAME)                                              \
  enum NAME##Table_columns {                                                   \
    NAME##Table_id, NAME##Table_fragment_id,
#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO MX_BEGIN_VISIT_DECL

#define MX_VISIT_BOOL(TABLE, NAME, ...) TABLE##Table_##NAME,
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_TEXT MX_VISIT_BOOL
#define MX_VISIT_ENTITY MX_VISIT_BOOL
#define MX_VISIT_OPTIONAL_BOOL MX_VISIT_BOOL
#define MX_VISIT_OPTIONAL_INT MX_VISIT_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_BOOL
#define MX_VISIT_OPTIONAL_TEXT MX_VISIT_BOOL
#define MX_VISIT_OPTIONAL_ENTITY MX_VISIT_BOOL

#define MX_END_VISIT_DECL(NAME)                                                \
  }                                                                            \
  ;
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO MX_END_VISIT_DECL
#include <multiplier/Visitor.inc.h>

/* Class definitions */
#define TABLE_CTOR(NAME)                                                       \
  NAME##Table::NAME##Table(mx::EntityProvider::Ptr ep) : ep(ep), index(ep) {}

#define TABLE_INIT(NAME)                                                       \
  std::optional<std::string> NAME##Table::Init(sqlite3 *db) {                  \
    int err = sqlite3_declare_vtab(db, NAME##Table_schema);                    \
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
    case NAME##Table_id:                                                       \
      sqlite3_result_int64(ctx, *cur);                                         \
      return SQLITE_OK;                                                        \
    case NAME##Table_fragment_id: {                                            \
      auto fragment{FragmentContaining(*cur)};                                 \
      if (fragment) {                                                          \
        sqlite3_result_int64(ctx, *fragment);                                  \
      } else {                                                                 \
        sqlite3_result_null(ctx);                                              \
      }                                                                        \
      return SQLITE_OK;                                                        \
    }

#define MX_BEGIN_VISIT_STMT MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_TYPE MX_BEGIN_VISIT_DECL
#define MX_BEGIN_VISIT_PSEUDO(NAME)                                            \
  template <typename IgnoreMePlease,                                           \
            template <typename> typename FromEntityId>                         \
  struct NAME##_IGNORE_ME {                                                    \
    int test(IgnoreMePlease index, int i, sqlite3_context *ctx, int *cur) {    \
      switch (i) {                                                             \
      default:                                                                 \
        return SQLITE_ERROR;

#define MX_VISIT_BOOL(TABLE, NAME, ...)                                        \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    sqlite3_result_int64(ctx, static_cast<std::int64_t>(entity->NAME()));      \
    return SQLITE_OK;                                                          \
  }
#define MX_VISIT_INT MX_VISIT_BOOL
#define MX_VISIT_ENUM MX_VISIT_BOOL
#define MX_VISIT_ENTITY(TABLE, NAME, ...)                                      \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    sqlite3_result_int64(ctx, static_cast<std::int64_t>(entity->NAME().id())); \
    return SQLITE_OK;                                                          \
  }
#define MX_VISIT_TEXT(TABLE, NAME, ...)                                        \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    auto view{entity->NAME()};                                                 \
    sqlite3_result_text(ctx, view.data(), view.size(), SQLITE_STATIC);         \
    return SQLITE_OK;                                                          \
  }
#define MX_VISIT_OPTIONAL_BOOL(TABLE, NAME, ...)                               \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    auto value{entity->NAME()};                                                \
    if (value) {                                                               \
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(*value));            \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
    return SQLITE_OK;                                                          \
  }
#define MX_VISIT_OPTIONAL_INT MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENUM MX_VISIT_OPTIONAL_BOOL
#define MX_VISIT_OPTIONAL_ENTITY(TABLE, NAME, ...)                             \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    auto value{entity->NAME()};                                                \
    if (value) {                                                               \
      sqlite3_result_int64(ctx, static_cast<std::int64_t>(value->id()));       \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
    return SQLITE_OK;                                                          \
  }
#define MX_VISIT_OPTIONAL_TEXT(TABLE, NAME, ...)                               \
  case TABLE##Table_##NAME: {                                                  \
    FromEntityId<mx::TABLE> helper;                                            \
    auto entity{helper.get(index, *cur)};                                      \
    assert(entity.has_value());                                                \
    auto value{entity->NAME()};                                                \
    if (value) {                                                               \
      sqlite3_result_text(ctx, value->data(), value->size(), SQLITE_STATIC);   \
    } else {                                                                   \
      sqlite3_result_null(ctx);                                                \
    }                                                                          \
    return SQLITE_OK;                                                          \
  }

#define MX_END_VISIT_DECL(NAME)                                                \
  default:                                                                     \
    return SQLITE_ERROR;                                                       \
    }                                                                          \
    }
#define MX_END_VISIT_STMT MX_END_VISIT_DECL
#define MX_END_VISIT_TYPE MX_END_VISIT_DECL
#define MX_END_VISIT_PSEUDO(NAME)                                              \
  }                                                                            \
  }                                                                            \
  }                                                                            \
  ;
#include <multiplier/Visitor.inc.h>

/* Schema definitions for lists */
#define MX_VISIT_BOOL_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  constexpr const char *TABLE##NAME##Table_schema =                            \
      "CREATE TABLE vtab(parent_id INTEGER NOT NULL, pos INTEGER NOT NULL, "   \
      "value INTEGER NOT NULL, PRIMARY KEY(parent_id, pos)) WITHOUT ROWID";
#define MX_VISIT_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_TEXT_LIST(TABLE, IGNORE0, IGNORE1, IGNORE2, IGNORE3, NAME,    \
                           ...)                                                \
  constexpr const char *TABLE##NAME##Table_schema =                            \
      "CREATE TABLE vtab(parent_id INTEGER NOT NULL, pos INTEGER NOT NULL, "   \
      "value TEXT NOT NULL, PRIMARY KEY(parent_id, pos)) WITHOUT ROWID";
#define MX_VISIT_ENTITY_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_BOOL_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_OPTIONAL_TEXT_LIST MX_VISIT_TEXT_LIST
#define MX_VISIT_OPTIONAL_ENTITY_LIST MX_VISIT_BOOL_LIST
#include <multiplier/Visitor.inc.h>

/* Class definitions */
#define LIST_CTOR(TABLE, NAME)                                                 \
  TABLE##NAME##Table::TABLE##NAME##Table(mx::EntityProvider::Ptr ep)           \
      : ep(ep), index(ep) {}

#define LIST_INIT(TABLE, NAME)                                                 \
  std::optional<std::string> TABLE##NAME##Table::Init(sqlite3 *db) {           \
    int err = sqlite3_declare_vtab(db, TABLE##NAME##Table_schema);             \
    if (err != SQLITE_OK) {                                                    \
      return sqlite3_errmsg(db);                                               \
    }                                                                          \
    return std::nullopt;                                                       \
  }

#define LIST_OPEN(TABLE, NAME)                                                 \
  mx::Result<std::unique_ptr<VirtualTableCursor>, int>                         \
      TABLE##NAME##Table::Open() {                                             \
    auto cursor{std::make_unique<TABLE##NAME##Cursor>(ep)};                    \
    return mx::Result<std::unique_ptr<VirtualTableCursor>, int>(               \
        std::move(cursor));                                                    \
  }

#define LIST_BESTINDEX(TABLE, NAME)                                            \
  int TABLE##NAME##Table::BestIndex(sqlite3_index_info *info) {                \
    for (int i = 0; i < info->nConstraint; i++) {                              \
      auto constraint = info->aConstraint[i];                                  \
      if (constraint.usable && constraint.iColumn == 0 &&                      \
          constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {                       \
        info->aConstraintUsage[i].argvIndex = 1;                               \
        info->estimatedCost = 1;                                               \
        info->idxNum = 1;                                                      \
        return SQLITE_OK;                                                      \
      }                                                                        \
    }                                                                          \
    return SQLITE_OK;                                                          \
  }

#define LIST_CURSOR_BOOL(TABLE, NAME, LOWERCASE)                               \
  class TABLE##NAME##Cursor : public VirtualTableCursor {                      \
  private:                                                                     \
    mx::Index index;                                                           \
    mx::EntityId id;                                                           \
    std::vector<std::int64_t> values;                                          \
    std::size_t cur;                                                           \
                                                                               \
  public:                                                                      \
    TABLE##NAME##Cursor(mx::EntityProvider::Ptr ep) : index(ep) {}             \
    virtual ~TABLE##NAME##Cursor() = default;                                  \
    virtual int Filter(int idxNum, const char *idxStr,                         \
                       const std::vector<sqlite3_value *> &args) override;     \
    virtual int Next() override {                                              \
      ++cur;                                                                   \
      return SQLITE_OK;                                                        \
    }                                                                          \
    virtual int Eof() override { return cur == values.size(); }                \
    virtual int Column(sqlite3_context *ctx, int idxCol) override {            \
      switch (idxCol) {                                                        \
      default:                                                                 \
        return SQLITE_ERROR;                                                   \
      case 0:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(id));              \
        return SQLITE_OK;                                                      \
      case 1:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(cur));             \
        return SQLITE_OK;                                                      \
      case 2:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(values[cur]));     \
        return SQLITE_OK;                                                      \
      }                                                                        \
    }                                                                          \
    virtual mx::Result<std::int64_t, int> RowId() override { return 0; }       \
  };

#define LIST_CURSOR_TEXT(TABLE, NAME, LOWERCASE)                               \
  class TABLE##NAME##Cursor : public VirtualTableCursor {                      \
  private:                                                                     \
    mx::Index index;                                                           \
    mx::EntityId id;                                                           \
    std::vector<std::string_view> values;                                      \
    std::size_t cur;                                                           \
                                                                               \
  public:                                                                      \
    TABLE##NAME##Cursor(mx::EntityProvider::Ptr ep) : index(ep) {}             \
    virtual ~TABLE##NAME##Cursor() = default;                                  \
    virtual int Filter(int idxNum, const char *idxStr,                         \
                       const std::vector<sqlite3_value *> &args) override;     \
    virtual int Next() override {                                              \
      ++cur;                                                                   \
      return SQLITE_OK;                                                        \
    }                                                                          \
    virtual int Eof() override { return cur == values.size(); }                \
    virtual int Column(sqlite3_context *ctx, int idxCol) override {            \
      switch (idxCol) {                                                        \
      default:                                                                 \
        return SQLITE_ERROR;                                                   \
      case 0:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(id));              \
        return SQLITE_OK;                                                      \
      case 1:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(cur));             \
        return SQLITE_OK;                                                      \
      case 2:                                                                  \
        sqlite3_result_text(ctx, values[cur].data(), values[cur].size(),       \
                            SQLITE_TRANSIENT);                                 \
        return SQLITE_OK;                                                      \
      }                                                                        \
    }                                                                          \
    virtual mx::Result<std::int64_t, int> RowId() override { return 0; }       \
  };

#define LIST_CURSOR_ENTITY(TABLE, NAME, LOWERCASE)                             \
  class TABLE##NAME##Cursor : public VirtualTableCursor {                      \
  private:                                                                     \
    mx::Index index;                                                           \
    mx::EntityId id;                                                           \
    std::vector<std::int64_t> values;                                          \
    std::size_t cur;                                                           \
                                                                               \
  public:                                                                      \
    TABLE##NAME##Cursor(mx::EntityProvider::Ptr ep) : index(ep) {}             \
    virtual ~TABLE##NAME##Cursor() = default;                                  \
    virtual int Filter(int idxNum, const char *idxStr,                         \
                       const std::vector<sqlite3_value *> &args) override;     \
    virtual int Next() override {                                              \
      ++cur;                                                                   \
      return SQLITE_OK;                                                        \
    }                                                                          \
    virtual int Eof() override { return cur == values.size(); }                \
    virtual int Column(sqlite3_context *ctx, int idxCol) override {            \
      switch (idxCol) {                                                        \
      default:                                                                 \
        return SQLITE_ERROR;                                                   \
      case 0:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(id));              \
        return SQLITE_OK;                                                      \
      case 1:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(cur));             \
        return SQLITE_OK;                                                      \
      case 2:                                                                  \
        sqlite3_result_int64(ctx, static_cast<std::int64_t>(values[cur]));     \
        return SQLITE_OK;                                                      \
      }                                                                        \
    }                                                                          \
    virtual mx::Result<std::int64_t, int> RowId() override { return 0; }       \
  };

#define LIST_FILTER_BOOL(TABLE, NAME, LOWERCASE)                               \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        for (auto value : entity->LOWERCASE()) {                               \
          values.push_back(static_cast<std::int64_t>(value));                  \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define LIST_FILTER_TEXT(TABLE, NAME, LOWERCASE)                               \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        values = entity->LOWERCASE();                                          \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define LIST_FILTER_ENTITY(TABLE, NAME, LOWERCASE)                             \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        for (auto value : entity->LOWERCASE()) {                               \
          values.push_back(static_cast<std::int64_t>(value.id()));             \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define LIST_FILTER_OPTIONAL_BOOL(TABLE, NAME, LOWERCASE)                      \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        auto coll = entity->LOWERCASE();                                       \
        if (coll) {                                                            \
          for (auto value : *coll) {                                           \
            values.push_back(static_cast<std::int64_t>(value));                \
          }                                                                    \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define LIST_FILTER_OPTIONAL_TEXT(TABLE, NAME, LOWERCASE)                      \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        auto coll = entity->LOWERCASE();                                       \
        if (coll) {                                                            \
          values = *coll;                                                      \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define LIST_FILTER_OPTIONAL_ENTITY(TABLE, NAME, LOWERCASE)                    \
  int TABLE##NAME##Cursor::Filter(int idxNum, const char *idxStr,              \
                                  const std::vector<sqlite3_value *> &args) {  \
    values.clear();                                                            \
    if (idxNum) {                                                              \
      id = sqlite3_value_int64(args[0]);                                       \
      FromEntityId<mx::TABLE> helper;                                          \
      auto entity{helper.get(index, id)};                                      \
      if (entity) {                                                            \
        auto coll = entity->LOWERCASE();                                       \
        if (coll) {                                                            \
          for (auto value : *coll) {                                           \
            values.push_back(static_cast<std::int64_t>(value.id()));           \
          }                                                                    \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    cur = 0;                                                                   \
    return SQLITE_OK;                                                          \
  }

#define MX_VISIT_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3, NAME,  \
                           ...)                                                \
  LIST_CURSOR_BOOL(TABLE, NAME, LOWERCASE)                                     \
  LIST_FILTER_BOOL(TABLE, NAME, LOWERCASE)                                     \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#define MX_VISIT_INT_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_ENUM_LIST MX_VISIT_BOOL_LIST
#define MX_VISIT_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3, NAME,  \
                           ...)                                                \
  LIST_CURSOR_TEXT(TABLE, NAME, LOWERCASE)                                     \
  LIST_FILTER_TEXT(TABLE, NAME, LOWERCASE)                                     \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#define MX_VISIT_ENTITY_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2, IGNORE3,      \
                             NAME, ...)                                        \
  LIST_CURSOR_ENTITY(TABLE, NAME, LOWERCASE)                                   \
  LIST_FILTER_ENTITY(TABLE, NAME, LOWERCASE)                                   \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#define MX_VISIT_OPTIONAL_BOOL_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,        \
                                    IGNORE3, NAME, ...)                        \
  LIST_CURSOR_BOOL(TABLE, NAME, LOWERCASE)                                     \
  LIST_FILTER_OPTIONAL_BOOL(TABLE, NAME, LOWERCASE)                            \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#define MX_VISIT_OPTIONAL_INT_LIST MX_VISIT_OPTIONAL_BOOL_LIST
#define MX_VISIT_OPTIONAL_ENUM_LIST MX_VISIT_OPTIONAL_BOOL_LIST
#define MX_VISIT_OPTIONAL_TEXT_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,        \
                                    IGNORE3, NAME, ...)                        \
  LIST_CURSOR_TEXT(TABLE, NAME, LOWERCASE)                                     \
  LIST_FILTER_OPTIONAL_TEXT(TABLE, NAME, LOWERCASE)                            \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#define MX_VISIT_OPTIONAL_ENTITY_LIST(TABLE, LOWERCASE, IGNORE1, IGNORE2,      \
                                      IGNORE3, NAME, ...)                      \
  LIST_CURSOR_BOOL(TABLE, NAME, LOWERCASE)                                     \
  LIST_FILTER_OPTIONAL_ENTITY(TABLE, NAME, LOWERCASE)                          \
  LIST_CTOR(TABLE, NAME)                                                       \
  LIST_INIT(TABLE, NAME)                                                       \
  LIST_OPEN(TABLE, NAME)                                                       \
  LIST_BESTINDEX(TABLE, NAME)
#include <multiplier/Visitor.inc.h>
} // namespace sqlite_bridge