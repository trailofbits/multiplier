/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

//
// SAMPLE CODE
//

#include "sourcecodemodel.h"

#include <QDebug>
#include <QMap>
#include <QRegularExpression>
#include <QString>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace multiplier {

struct Token final {
  TokenID id{kInvalidTokenID};
  TokenGroupID group_id{kInvalidTokenGroupID};
  QString data;
  TokenColorID color_id{kInvalidTokenColorID};
  QMap<int, QVariant> property_bag;
  TokenAttribute attributes;
};

struct SourceCodeModel::PrivateData final {
  std::optional<TokenID> min_token_id;
  std::optional<TokenID> max_token_id;
  std::unordered_map<TokenID, Token> token_map;
};

SourceCodeModel::SourceCodeModel(QObject *parent)
    : ITextModel(parent), d(new PrivateData) {}

SourceCodeModel::SourceCodeModel(pasta::File file, QObject *parent)
    : SourceCodeModel(parent) {
  renderFile(file);
}

void SourceCodeModel::gotAST(std::shared_ptr<pasta::AST> ast) {
  renderFile(ast->MainFile());
}

void SourceCodeModel::renderFile(pasta::File file) {
  static TokenGroupID token_group_id_generator{kInvalidTokenGroupID};

  auto group_id_step = 0;

  auto L_addToken = [&](const pasta::FileToken &tok) {

    ++group_id_step;
    if (group_id_step == 30) {
      token_group_id_generator = (token_group_id_generator + 1) % 5;
      group_id_step = 0;
    }

    auto tok_data = tok.Data();

    Token token;
    token.id = tok.Index();
    token.data = QString::fromLocal8Bit(
        tok_data.data(), static_cast<int>(tok_data.size()));
    token.color_id = tok.Kind() % 7u;
    token.group_id = token_group_id_generator + 1;

    if (!d->min_token_id) {
      d->min_token_id = tok.Index();
    }

    d->max_token_id = tok.Index();
    d->token_map.try_emplace(tok.Index(), std::move(token));
  };

  for (auto token : file.Tokens()) {
    L_addToken(token);
  }

  emit modelReset();
}

SourceCodeModel::~SourceCodeModel() {}

TokenID SourceCodeModel::firstTokenID() const {
  if (d->min_token_id.has_value()) {
    return d->min_token_id.value();
  } else {
    return kInvalidTokenID;
  }
}

TokenID SourceCodeModel::lastTokenID() const {
  if (d->max_token_id.has_value()) {
    return d->max_token_id.value();
  } else {
    return kInvalidTokenID;
  }
};

TokenGroupID SourceCodeModel::tokenGroupID(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return kInvalidTokenGroupID;
  }

  const auto &token = token_map_it->second;
  return token.group_id;
}

QString SourceCodeModel::tokenData(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return QString();
  }

  const auto &token = token_map_it->second;
  return token.data;
}

TokenColorID SourceCodeModel::tokenColor(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return kInvalidTokenGroupID;
  }

  const auto &token = token_map_it->second;
  return token.color_id;
}

QVariant SourceCodeModel::tokenProperty(TokenID token_id, int property_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return QVariant();
  }

  const auto &token = token_map_it->second;

  auto property_bag_it = token.property_bag.find(property_id);
  if (property_bag_it == token.property_bag.end()) {
    return QVariant();
  }

  return *property_bag_it;
}

TokenAttribute SourceCodeModel::tokenAttributes(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return static_cast<TokenAttribute>(0);
  }

  const auto &token = token_map_it->second;
  return token.attributes;
}

} // namespace multiplier
