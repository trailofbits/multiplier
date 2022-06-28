// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <multiplier/Index.h>
#include <optional>
#include <sqlite3ext.h>
#include <type_traits>
#include <variant>

#include "Tables.h"
#include "VirtualTableCursor.h"

namespace sqlite_bridge {

enum ConstraintType {
  EntityId = 1 << 0,
  FragmentId = 1 << 1,
  Containing = 1 << 2
};

std::optional<mx::RawEntityId> FragmentContaining(mx::EntityId id);

template <typename T> struct FromEntityId;

template <> struct FromEntityId<mx::Decl> {
  std::optional<mx::Decl> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::DeclarationId>(vid)) {
      return std::nullopt;
    }

    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Decl>(variant)) {
      return std::get<mx::Decl>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Stmt> {
  std::optional<mx::Stmt> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::StatementId>(vid)) {
      return std::nullopt;
    }

    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Stmt>(variant)) {
      return std::get<mx::Stmt>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Type> {
  std::optional<mx::Type> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::TypeId>(vid)) {
      return std::nullopt;
    }

    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Type>(variant)) {
      return std::get<mx::Type>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::Token> {
  std::optional<mx::Token> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::FragmentTokenId>(vid) &&
        !std::holds_alternative<mx::FileTokenId>(vid)) {
      return std::nullopt;
    }

    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Token>(variant)) {
      return std::get<mx::Token>(variant);
    }
    return std::nullopt;
  }
};

template <> struct FromEntityId<mx::TokenSubstitution> {
  std::optional<mx::TokenSubstitution> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::TokenSubstitutionId>(vid)) {
      return std::nullopt;
    }

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

template <> struct FromEntityId<mx::Designator> {
  std::optional<mx::Designator> get(mx::Index &index, mx::EntityId id) {
    auto vid{id.Unpack()};
    if (!std::holds_alternative<mx::DesignatorId>(vid)) {
      return std::nullopt;
    }

    auto variant{index.entity(id)};
    if (std::holds_alternative<mx::Designator>(variant)) {
      return std::get<mx::Designator>(variant);
    }
    return std::nullopt;
  }
};

template <typename T> constexpr inline bool has_containing = false;
template <> constexpr inline bool has_containing<mx::Decl> = true;
template <> constexpr inline bool has_containing<mx::Stmt> = true;
template <> constexpr inline bool has_containing<mx::Type> = true;

using PredType = bool(mx::Index &index, mx::EntityId ancestor_eid,
                      mx::EntityId descendant_eid);

bool FalsePredicate(mx::Index &index, mx::EntityId ancestor_eid,
                    mx::EntityId descendant_eid);

template <typename T, typename Enable = void> struct ContainingPredicate {
  static bool Predicate(mx::Index &index, mx::EntityId ancestor_eid,
                        mx::EntityId descendant_eid) {
    return false;
  }
};

template <typename T>
struct ContainingPredicate<T,
                           std::enable_if_t<std::is_base_of_v<mx::Decl, T> ||
                                            std::is_base_of_v<mx::Stmt, T>>> {
  static bool Predicate(mx::Index &index, mx::EntityId ancestor_eid,
                        mx::EntityId descendant_eid) {
    auto ancestor_vid{ancestor_eid.Unpack()};
    auto descendant_vid{ancestor_eid.Unpack()};

    if (std::holds_alternative<mx::InvalidId>(ancestor_vid) ||
        std::holds_alternative<mx::InvalidId>(descendant_vid)) {
      return false;
    }

    auto ancestor_frag{FragmentContaining(ancestor_eid)};
    auto descendant_frag{FragmentContaining(descendant_eid)};
    if (!ancestor_frag || !descendant_frag ||
        *ancestor_frag != *descendant_frag) {
      return false;
    }

    FromEntityId<T> helper;
    auto ancestor{helper.get(index, ancestor_eid)};
    if (!ancestor) {
      return false;
    }

    auto descendant{index.entity(descendant_eid)};
    if (std::holds_alternative<mx::Decl>(descendant)) {
      auto descendant_decl{std::get<mx::Decl>(descendant)};
      for (auto parent : T::containing(descendant_decl)) {
        if (parent.id() == ancestor_eid) {
          return true;
        }
      }
    } else if (std::holds_alternative<mx::Stmt>(descendant)) {
      auto descendant_stmt{std::get<mx::Stmt>(descendant)};
      for (auto parent : T::containing(descendant_stmt)) {
        if (parent.id() == ancestor_eid) {
          return true;
        }
      }
    } else if (std::holds_alternative<mx::Token>(descendant)) {
      auto descendant_tok{std::get<mx::Token>(descendant)};
      for (auto parent : T::containing(descendant_tok)) {
        if (parent.id() == ancestor_eid) {
          return true;
        }
      }
    }

    return false;
  }
};

template <typename T>
struct ContainingPredicate<T,
                           std::enable_if_t<std::is_base_of_v<mx::Type, T>>> {
  static bool Predicate(mx::Index &index, mx::EntityId ancestor_eid,
                        mx::EntityId descendant_eid) {
    auto ancestor_vid{ancestor_eid.Unpack()};
    auto descendant_vid{ancestor_eid.Unpack()};

    if (std::holds_alternative<mx::InvalidId>(ancestor_vid) ||
        std::holds_alternative<mx::InvalidId>(descendant_vid)) {
      return false;
    }

    auto ancestor_frag{FragmentContaining(ancestor_eid)};
    auto descendant_frag{FragmentContaining(descendant_eid)};
    if (!ancestor_frag || !descendant_frag ||
        *ancestor_frag != *descendant_frag) {
      return false;
    }

    FromEntityId<mx::Type> helper;
    auto ancestor{helper.get(index, ancestor_eid)};
    if (!ancestor) {
      return false;
    }

    auto descendant{index.entity(descendant_eid)};
    if (std::holds_alternative<mx::Token>(descendant)) {
      auto descendant_tok{std::get<mx::Token>(descendant)};
      for (auto parent : mx::Type::containing(descendant_tok)) {
        if (parent.id() == ancestor_eid) {
          return true;
        }
      }
    }

    return false;
  }
};

template <typename T, typename Enable = void> struct GenerateContaining {
  static void Generate(mx::Index &index, mx::EntityId descendant_eid,
                       std::vector<mx::EntityId> &entities) {}
};

template <typename T>
struct GenerateContaining<T, std::enable_if_t<std::is_base_of_v<mx::Type, T>>> {
  static void Generate(mx::Index &index, mx::EntityId descendant_eid,
                       std::vector<mx::EntityId> &entities) {
    auto descendant_vid{descendant_eid.Unpack()};

    if (std::holds_alternative<mx::InvalidId>(descendant_vid)) {
      return;
    }

    auto descendant{index.entity(descendant_eid)};
    if (std::holds_alternative<mx::Token>(descendant)) {
      auto descendant_tok{std::get<mx::Token>(descendant)};
      for (auto parent : T::containing(descendant_tok)) {
        entities.push_back(parent.id());
      }
    }
  }
};

template <typename T>
struct GenerateContaining<T, std::enable_if_t<std::is_base_of_v<mx::Decl, T> ||
                                              std::is_base_of_v<mx::Stmt, T>>> {
  static void Generate(mx::Index &index, mx::EntityId descendant_eid,
                       std::vector<mx::EntityId> &entities) {
    auto descendant_vid{descendant_eid.Unpack()};

    if (std::holds_alternative<mx::InvalidId>(descendant_vid)) {
      return;
    }

    auto descendant{index.entity(descendant_eid)};
    if (std::holds_alternative<mx::Decl>(descendant)) {
      auto descendant_decl{std::get<mx::Decl>(descendant)};
      for (auto parent : T::containing(descendant_decl)) {
        entities.push_back(parent.id());
      }
    } else if (std::holds_alternative<mx::Stmt>(descendant)) {
      auto descendant_stmt{std::get<mx::Stmt>(descendant)};
      for (auto parent : T::containing(descendant_stmt)) {
        entities.push_back(parent.id());
      }
    } else if (std::holds_alternative<mx::Token>(descendant)) {
      auto descendant_tok{std::get<mx::Token>(descendant)};
      for (auto parent : T::containing(descendant_tok)) {
        entities.push_back(parent.id());
      }
    }
  }
};

enum class FieldType { Integer, Text };

using SQLiteFieldGetter = void(mx::Index &index, mx::EntityId id,
                               sqlite3_context *ctx);
using EntityFieldGetter = std::optional<mx::EntityId>(mx::Index &index,
                                                      mx::EntityId id);

struct FieldDescriptor {
  // Name of the field
  std::string name;

  // SQL type of the field
  FieldType type;

  // Whether it is nullable or not
  bool nullable;

  // Sets the result of a SQL function to the value of the field
  SQLiteFieldGetter *sqliteGetter;

  // Returns the entity id of the field, if the field _is_ an entity. Otherwise,
  // nullopt.
  EntityFieldGetter *entityGetter;

  // The predicate function to use when evaluating the `containing` function on
  // this field
  PredType *containingPredicate;

  FieldDescriptor(std::string name, FieldType type, bool nullable,
                  SQLiteFieldGetter *sqliteGetter,
                  EntityFieldGetter *entityGetter,
                  PredType *containingPredicate)
      : name(name), type(type), nullable(nullable), sqliteGetter(sqliteGetter),
        entityGetter(entityGetter), containingPredicate(containingPredicate) {}
};

std::string GetCreateTableStatement(const std::vector<FieldDescriptor> &fields);

enum FunctionConstraints { CONTAINING_OP = SQLITE_INDEX_CONSTRAINT_FUNCTION };

static constexpr size_t MaxNumContaining = 128;
using ConstraintData = std::array<int, MaxNumContaining>;
static_assert(std::is_trivial_v<ConstraintData>);

int BestIndex(sqlite3_index_info *info);

int FindFunction(int nArg, const std::string &name,
                 void (**pxFunc)(sqlite3_context *, int, sqlite3_value **),
                 void **ppArg);

sqlite3_int64 get_int64(sqlite3_value *);

template <typename T>
void Filter(int idxNum, const char *idxStr,
            const std::vector<sqlite3_value *> &args, mx::Index &index,
            std::vector<mx::EntityId> &entities,
            const std::vector<FieldDescriptor> &fields) {
  entities.clear();
  ConstraintData data;
  std::memcpy(data.data(), idxStr + 1, sizeof(data));
  int argIndex{0};
  bool generatedEntities{false};
  if ((idxNum & EntityId) == EntityId) {
    FromEntityId<T> helper;
    auto entity{helper.get(index, get_int64(args[argIndex++]))};
    if (entity) {
      entities.push_back(entity->id());
    }
    generatedEntities = true;
  }
  if ((idxNum & FragmentId) == FragmentId) {
    auto frag_id{get_int64(args[argIndex++])};
    auto fragment{index.fragment(frag_id)};
    if (fragment) {
      if (generatedEntities) {
        entities.erase(std::remove_if(entities.begin(), entities.end(),
                                      [&](mx::EntityId id) {
                                        auto frag{FragmentContaining(id)};
                                        if (!frag) {
                                          return true;
                                        }
                                        return frag_id != *frag;
                                      }));
      } else {
        for (auto entity : T::in(*fragment)) {
          entities.push_back(entity.id());
        }
        generatedEntities = true;
      }
    } else {
      entities.clear();
      generatedEntities = true;
    }
  }

  if (!generatedEntities) {
    if ((idxNum & Containing) == Containing) {
      int argIndexSave{argIndex};
      for (size_t i = 0; i < MaxNumContaining && data[i] >= 0; ++i) {
        auto col{data[i]};
        auto descendant_id{get_int64(args[argIndex++])};
        if (col == 0) {
          GenerateContaining<T>::Generate(index, descendant_id, entities);
          generatedEntities = true;
          break;
        }
      }
      argIndex = argIndexSave;
    }
  }

  if (!generatedEntities) {
    for (auto file : mx::File::in(index)) {
      for (auto fragment : mx::Fragment::in(file)) {
        for (auto entity : T::in(fragment)) {
          entities.push_back(entity.id());
        }
      }
    }
  }

  if ((idxNum & Containing) == Containing) {
    for (size_t i = 0; i < MaxNumContaining && data[i] >= 0; ++i) {
      auto col{data[i]};
      auto descendant_id{get_int64(args[argIndex++])};
      if (col == 0 && !generatedEntities) {
        entities.erase(std::remove_if(
            entities.begin(), entities.end(), [&](mx::EntityId id) {
              return !ContainingPredicate<T>::Predicate(index, id,
                                                        descendant_id);
            }));
      } else if (col == 1) {
        entities.clear();
      } else if (col > 1) {
        entities.erase(std::remove_if(
            entities.begin(), entities.end(), [&](mx::EntityId id) {
              auto field{fields[col - 2]};
              auto value{field.entityGetter(index, id)};
              if (value) {
                return !field.containingPredicate(index, *value, descendant_id);
              } else {
                return true;
              }
            }));
      }
    }
  }
}

int Column(sqlite3_context *ctx, int idxCol, mx::Index &index, mx::EntityId cur,
           const std::vector<FieldDescriptor> &schema);

using ListGen = void(mx::Index &index, std::int64_t id,
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
                     const std::vector<sqlite3_value *> &args) override;
  virtual int Next() override;
  virtual int Eof() override;
  virtual int Column(sqlite3_context *ctx, int idxCol) override;
  virtual mx::Result<std::int64_t, int> RowId() override;
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
                     const std::vector<sqlite3_value *> &args) override;
  virtual int Next() override;
  virtual int Eof() override;
  virtual int Column(sqlite3_context *ctx, int idxCol) override;
  virtual mx::Result<std::int64_t, int> RowId() override;
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
  virtual std::optional<std::string> Init(sqlite3 *db) override;
  virtual int BestIndex(sqlite3_index_info *info) override;
  virtual mx::Result<std::unique_ptr<VirtualTableCursor>, int> Open() override;
};

struct ListDescriptor {
  std::string name;
  ListGen *gen;
  FieldType type;
  ListDescriptor(std::string name, FieldType type, ListGen *gen)
      : name(name), type(type), gen(gen) {}
};

} // namespace sqlite_bridge