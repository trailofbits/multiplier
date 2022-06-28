#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include "TableUtils.h"

namespace sqlite_bridge {
std::optional<mx::RawEntityId> FragmentContaining(mx::EntityId id) {
  auto var{id.Unpack()};
  mx::RawEntityId frag_id;
  if (std::holds_alternative<mx::DeclarationId>(var)) {
    frag_id = std::get<mx::DeclarationId>(var).fragment_id;
  } else if (std::holds_alternative<mx::StatementId>(var)) {
    frag_id = std::get<mx::StatementId>(var).fragment_id;
  } else if (std::holds_alternative<mx::TypeId>(var)) {
    frag_id = std::get<mx::TypeId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FragmentTokenId>(var)) {
    frag_id = std::get<mx::FragmentTokenId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FileTokenId>(var)) {
    return std::nullopt;
  } else if (std::holds_alternative<mx::TokenSubstitutionId>(var)) {
    frag_id = std::get<mx::TokenSubstitutionId>(var).fragment_id;
  } else if (std::holds_alternative<mx::DesignatorId>(var)) {
    frag_id = std::get<mx::DesignatorId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FragmentId>(var)) {
    frag_id = std::get<mx::FragmentId>(var).fragment_id;
  } else if (std::holds_alternative<mx::FileId>(var)) {
    return std::nullopt;
  } else {
    assert(false);
    return std::nullopt;
  }

  return mx::EntityId(mx::FragmentId(frag_id));
}

bool FalsePredicate(mx::Index &index, mx::EntityId ancestor_eid,
                    mx::EntityId descendant_eid) {
  return false;
}

std::string
GetCreateTableStatement(const std::vector<FieldDescriptor> &fields) {
  std::string schema{"CREATE TABLE vtab(id INTEGER NOT "
                     "NULL, fragment_id INTEGER, "};
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

int BestIndex(sqlite3_index_info *info) {
  /* This function is called multiple times by SQLite whenever a table is about
   * to be queried. SQLite will pass different combinations of available
   * constraints, and choose the cheapest index. For example, if a query is
   * specified as
   *
   *   SELECT * FROM Decl WHERE id = 3 AND fragment_id = 1 SQLite
   *
   * might call BestIndex four times, once with only a constraint on id, once
   * with fragment_id, once with both and once with none.
   *
   * Once the best index has been found, SQLite communicates the choice to the
   * Filter method using the idxNum and idxStr fields. If idxNum is zero, SQLite
   * assumes that no index was available, and an exhaustive scan is needed.
   *
   * The method I chose to communicate what information is available to Filter
   * is the following: the first bit in idxNum is whether equality on id is
   * available, the second communicates whether equality on fragment id is
   * available, and the third whether there are any "containing" parent-child
   * relations requested.
   *
   * This method cannot be scaled to represent each column on which a
   * "containing" constraint is present, because the total number of columns for
   * any given table can be greater than the number of bits in idxNum. To work
   * around this limitation, we abuse the idxStr field by allocating an
   * auxiliary structure containing a list of columns on which such a constraint
   * is present. This structure must be trivial as no constructor nor destructor
   * will be called on it.
   */
  int argvIndex{0};
  ConstraintData data;
  data.fill(-1);

  info->estimatedCost = 10e9;
  // Search for index id constraint
  // Having a query search by exact id is cheapest, and the preferred method if
  // available.
  for (int i = 0; i < info->nConstraint; i++) {
    auto constraint = info->aConstraint[i];
    if (!constraint.usable) {
      continue;
    }
    if (constraint.iColumn == 0 &&
        constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
      info->aConstraintUsage[i].argvIndex = ++argvIndex;
      info->aConstraintUsage[i].omit = 1;
      info->idxNum |= EntityId;
      info->estimatedCost = 1;
      break;
    }
  }

  // Search for fragment id constraint
  // Searching for all of the entities in a fragment is more expensive than
  // searching by entity id, but still cheaper than searching by parent-child
  // relation.
  for (int i = 0; i < info->nConstraint; i++) {
    auto constraint = info->aConstraint[i];
    if (!constraint.usable) {
      continue;
    }
    if (constraint.iColumn == 1 &&
        constraint.op == SQLITE_INDEX_CONSTRAINT_EQ) {
      info->aConstraintUsage[i].argvIndex = ++argvIndex;
      info->aConstraintUsage[i].omit = 1;
      info->idxNum |= FragmentId;
      info->estimatedCost = std::min(info->estimatedCost, 2.0);
      break;
    }
  }

  size_t constraint_i{1};
  // Search for fragment id constraints
  // This is the most expensive option, especially if not based on the actual
  // entity id.
  for (int i = 0; i < info->nConstraint; i++) {
    auto constraint = info->aConstraint[i];
    if (!constraint.usable && constraint.op == CONTAINING_OP) {
      return SQLITE_CONSTRAINT;
    }
    if (constraint.op == CONTAINING_OP) {
      if (i >= MaxNumContaining) {
        return SQLITE_ERROR;
      }
      info->aConstraintUsage[i].argvIndex = ++argvIndex;
      info->aConstraintUsage[i].omit = 1;
      info->idxNum |= Containing;
      data[constraint_i++] = constraint.iColumn;

      if (constraint.iColumn == 0) {
        info->estimatedCost = std::min(info->estimatedCost, 4.0);
      } else {
        info->estimatedCost = std::min(info->estimatedCost, 8.0);
      }
    }
  }

  info->idxStr = static_cast<char *>(sqlite3_malloc(sizeof(data) + 1));
  info->idxStr[0] = 0;
  // Skip the first character, so that when the index name is printed as a
  // null-terminated string by EXPLAIN QUERY PLAN we don't get ugly data on the
  // terminal.
  std::memcpy(info->idxStr + 1, data.data(), sizeof(data));
  info->needToFreeIdxStr = 1;

  return SQLITE_OK;
}

int FindFunction(int nArg, const std::string &name,
                 void (**pxFunc)(sqlite3_context *, int, sqlite3_value **),
                 void **ppArg) {
  if (nArg == 2 && name == "containing") {
    *pxFunc = [](sqlite3_context *ctx, int, sqlite3_value **) {
      sqlite3_result_int(ctx, 0);
    };
    return CONTAINING_OP;
  }
  return 0;
}

int Column(sqlite3_context *ctx, int idxCol, mx::Index &index, mx::EntityId cur,
           const std::vector<FieldDescriptor> &schema) {
  switch (idxCol) {
  default: {
    if (idxCol - 2 >= schema.size()) {
      return SQLITE_ERROR;
    }
    schema[idxCol - 2].sqliteGetter(index, cur, ctx);
    return SQLITE_OK;
  }
  case 0:
    sqlite3_result_int64(ctx, cur);
    return SQLITE_OK;
  case 1: {
    auto fragment{FragmentContaining(cur)};
    if (fragment) {
      sqlite3_result_int64(ctx, *fragment);
    } else {
      sqlite3_result_null(ctx);
    }
    return SQLITE_OK;
  }
  }
}

int IntegerListCursor::Filter(int idxNum, const char *idxStr,
                              const std::vector<sqlite3_value *> &args) {
  values.clear();
  if (idxNum) {
    id = sqlite3_value_int64(args[0]);
    std::vector<std::string_view> tmp;
    gen(index, id, values, tmp);
  }
  cur = 0;
  return SQLITE_OK;
}

int IntegerListCursor::Next() {
  ++cur;
  return SQLITE_OK;
}

int IntegerListCursor::Eof() { return cur == values.size(); }

int IntegerListCursor::Column(sqlite3_context *ctx, int idxCol) {
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

mx::Result<std::int64_t, int> IntegerListCursor::RowId() { return 0; }

int TextListCursor::Filter(int idxNum, const char *idxStr,
                           const std::vector<sqlite3_value *> &args) {
  values.clear();
  if (idxNum) {
    id = sqlite3_value_int64(args[0]);
    std::vector<std::int64_t> tmp;
    gen(index, id, tmp, values);
  }
  cur = 0;
  return SQLITE_OK;
}

int TextListCursor::Next() {
  ++cur;
  return SQLITE_OK;
}

int TextListCursor::Eof() { return cur == values.size(); }

int TextListCursor::Column(sqlite3_context *ctx, int idxCol) {
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
                        SQLITE_TRANSIENT);
    return SQLITE_OK;
  }
}

mx::Result<std::int64_t, int> TextListCursor::RowId() { return 0; }

std::optional<std::string> ListTable::Init(sqlite3 *db) {
  int err;
  switch (type) {
  case FieldType::Integer:
    err = sqlite3_declare_vtab(db, "CREATE TABLE vtab(parent_id "
                                   "INTEGER "
                                   "NOT NULL, pos INTEGER "
                                   "NOT NULL, value INTEGER NOT "
                                   "NULL, "
                                   "PRIMARY KEY(parent_id, pos)) "
                                   "WITHOUT ROWID");
    break;
  case FieldType::Text:
    err = sqlite3_declare_vtab(db, "CREATE TABLE vtab(parent_id "
                                   "INTEGER "
                                   "NOT NULL, pos INTEGER "
                                   "NOT NULL, value TEXT NOT NULL, "
                                   "PRIMARY KEY(parent_id, pos)) "
                                   "WITHOUT ROWID");
    break;
  }
  if (err != SQLITE_OK) {
    return sqlite3_errmsg(db);
  }
  return std::nullopt;
}

int ListTable::BestIndex(sqlite3_index_info *info) {
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
  return SQLITE_CONSTRAINT;
}

mx::Result<std::unique_ptr<VirtualTableCursor>, int> ListTable::Open() {
  std::unique_ptr<VirtualTableCursor> cursor;
  if (type == FieldType::Integer) {
    cursor = std::make_unique<IntegerListCursor>(ep, gen);
  } else {
    cursor = std::make_unique<TextListCursor>(ep, gen);
  }
  return mx::Result<std::unique_ptr<VirtualTableCursor>, int>(
      std::move(cursor));
}

sqlite3_int64 get_int64(sqlite3_value *val) { return sqlite3_value_int64(val); }

} // namespace sqlite_bridge
