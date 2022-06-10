// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <sqlite3ext.h>
SQLITE_EXTENSION_INIT3

#include <cassert>

#include "Tables.h"
#include "VirtualTableCursor.h"
#include <llvm/Support/JSON.h>
#include <llvm/Support/raw_ostream.h>
#include <multiplier/Query.h>
#include <multiplier/Re2.h>
#include <multiplier/Weggli.h>

namespace sqlite_bridge {

QueryTable::QueryTable(mx::EntityProvider::Ptr ep, QueryType type)
    : ep(ep), index(ep), type(type) {}

constexpr const char *schema = R"cpp(
CREATE TABLE vtable(
    query TEXT NOT NULL,
    variables TEXT NOT NULL,
    captures TEXT NOT NULL,
    PRIMARY KEY (query, variables, captures)
) WITHOUT ROWID)cpp";

std::optional<std::string> QueryTable::Init(sqlite3 *db) {
  int err = sqlite3_declare_vtab(db, schema);
  if (err != SQLITE_OK) {
    return sqlite3_errmsg(db);
  }

  return std::nullopt;
}

int QueryTable::BestIndex(sqlite3_index_info *info) {
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

class WeggliCursor : public VirtualTableCursor {
private:
  mx::Index index;
  std::string query_text;
  std::vector<mx::WeggliQueryMatch> matches;
  std::size_t cur;

public:
  WeggliCursor(mx::EntityProvider::Ptr ep) : index(ep), cur(0) {}

  virtual ~WeggliCursor() = default;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    matches.clear();
    cur = 0;
    if (!idxNum) {
      return SQLITE_OK;
    }

    auto query_str{reinterpret_cast<const char *>(sqlite3_value_text(args[0]))};
    if (!query_str) {
      return SQLITE_OK;
    }

    query_text = query_str;
    mx::WeggliQuery query{query_text, true};
    for (auto match : index.query_fragments(query)) {
      matches.push_back(match);
    }
    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == matches.size(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    case 0:
      sqlite3_result_text(ctx, query_text.data(), query_text.size(),
                          SQLITE_TRANSIENT);
      return SQLITE_OK;
    case 1: {
      std::string str;
      llvm::raw_string_ostream os{str};
      llvm::json::OStream j{os};
      j.array([&]() {
        for (auto variable : matches[cur].captured_variables()) {
          j.value(variable);
        }
      });

      sqlite3_result_text(ctx, str.data(), str.size(), SQLITE_TRANSIENT);
      return SQLITE_OK;
    }
    case 2: {
      std::string str;
      llvm::raw_string_ostream os{str};
      llvm::json::OStream j{os};
      j.object([&]() {
        for (auto variable : matches[cur].captured_variables()) {
          j.attributeObject(variable, [&]() {
            auto tokens{matches[cur].variable_capture(variable)};
            assert(tokens.has_value());
            j.attributeArray("tokens", [&]() {
              for (auto token : *tokens) {
                j.value(static_cast<std::uint64_t>(token.id()));
              }
            });
          });
        }
      });

      sqlite3_result_text(ctx, str.data(), str.size(), SQLITE_TRANSIENT);
      return SQLITE_OK;
    }
    default:
      return SQLITE_ERROR;
    }
  }

  virtual mx::Result<std::int64_t, int> RowId() override { return 0; }
};

class RegexCursor : public VirtualTableCursor {
private:
  mx::Index index;
  std::string query_text;
  std::vector<mx::RegexQueryMatch> matches;
  std::size_t cur;

public:
  RegexCursor(mx::EntityProvider::Ptr ep) : index(ep), cur(0) {}

  virtual ~RegexCursor() = default;

  virtual int Filter(int idxNum, const char *idxStr,
                     const std::vector<sqlite3_value *> &args) override {
    matches.clear();
    cur = 0;
    if (!idxNum) {
      return SQLITE_OK;
    }

    auto query_str{reinterpret_cast<const char *>(sqlite3_value_text(args[0]))};
    if (!query_str) {
      return SQLITE_OK;
    }

    query_text = query_str;
    mx::RegexQuery query{query_text};
    for (auto match : index.query_fragments(query)) {
      matches.push_back(match);
    }
    return SQLITE_OK;
  }

  virtual int Next() override {
    ++cur;
    return SQLITE_OK;
  }

  virtual int Eof() override { return cur == matches.size(); }

  virtual int Column(sqlite3_context *ctx, int idxCol) override {
    switch (idxCol) {
    case 0:
      sqlite3_result_text(ctx, query_text.data(), query_text.size(),
                          SQLITE_TRANSIENT);
      return SQLITE_OK;
    case 1: {
      std::string str;
      llvm::raw_string_ostream os{str};
      llvm::json::OStream j{os};
      j.array([&]() {
        for (auto variable : matches[cur].captured_variables()) {
          j.value(variable);
        }
      });

      sqlite3_result_text(ctx, str.data(), str.size(), SQLITE_TRANSIENT);
      return SQLITE_OK;
    }
    case 2: {
      std::string str;
      llvm::raw_string_ostream os{str};
      llvm::json::OStream j{os};
      j.object([&]() {
        j.attributeObject("named", [&] {
          for (auto variable : matches[cur].captured_variables()) {
            j.attributeObject(variable, [&] {
              auto tokens{matches[cur].captured_tokens(variable)};
              auto data{matches[cur].captured_data(variable)};
              if (data) {
                j.attribute("data", std::string(data->data(), data->size()));
              }
              j.attributeArray("tokens", [&]() {
                if (tokens) {
                  for (auto token : *tokens) {
                    j.value(static_cast<std::uint64_t>(token.id()));
                  }
                }
              });
            });
          }
        });

        j.attributeArray("indexed", [&] {
          for (auto i{0U}; i < matches[cur].num_captures(); ++i) {
            auto tokens{matches[cur].captured_tokens(i)};
            auto data{matches[cur].captured_data(i)};
            j.object([&] {
              if (data) {
                j.attribute("data", std::string(data->data(), data->size()));
              }
              j.attributeArray("tokens", [&]() {
                if (tokens) {
                  for (auto token : *tokens) {
                    j.value(static_cast<std::uint64_t>(token.id()));
                  }
                }
              });
            });
          }
        });
      });

      sqlite3_result_text(ctx, str.data(), str.size(), SQLITE_TRANSIENT);
      return SQLITE_OK;
    }
    default:
      return SQLITE_ERROR;
    }
  }

  virtual mx::Result<std::int64_t, int> RowId() override { return 0; }
};

using Result = mx::Result<std::unique_ptr<VirtualTableCursor>, int>;

Result QueryTable::Open() {
  std::unique_ptr<VirtualTableCursor> cursor;
  if (type == QueryType::Regex) {
    cursor = std::make_unique<RegexCursor>(ep);
  } else {
    cursor = std::make_unique<WeggliCursor>(ep);
  }
  return Result(std::move(cursor));
}
} // namespace sqlite_bridge