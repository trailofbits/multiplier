/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "sourcecodemodel.h"

#include <QDebug>
#include <QMap>
#include <QRegularExpression>
#include <QString>

#include <fstream>
#include <iostream>
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
  std::vector<TokenID> token_list;
  std::unordered_map<TokenID, Token> token_map;
};

SourceCodeModel::SourceCodeModel(const QString &path, QObject *parent)
    : ITextModel(parent), d(new PrivateData) {
  generateTestData(path);
}

void SourceCodeModel::generateTestData(const QString &path) {
  static TokenID token_id_generator{kInvalidTokenID};
  static TokenColorID color_id_generator{kInvalidTokenColorID};

  qDebug() << "Opening:" << path;

  auto L_addToken = [&](const QString &str) {
    ++token_id_generator;
    color_id_generator = (color_id_generator + 1) % 7;

    d->token_list.push_back(token_id_generator);

    Token token;
    token.id = token_id_generator;
    token.data = str;
    token.color_id = color_id_generator;

    d->token_map.insert({token_id_generator, std::move(token)});
  };

  std::ifstream input_file;
  input_file.open(path.toStdString().c_str(), std::ios::in);
  if (!input_file) {
    throw std::runtime_error("Failed to open the input file");
  }

  std::string line;
  while (std::getline(input_file, line)) {
    auto token_list = QString(line.c_str()).split(QRegularExpression("\\b"));
    for (const auto &token : token_list) {
      L_addToken(token);
    }

    L_addToken("\n");
  }
}

SourceCodeModel::~SourceCodeModel() {}

TokenID SourceCodeModel::firstTokenID() const {
  if (d->token_list.empty()) {
    return kInvalidTokenID;
  }

  return d->token_list.at(0);
}

TokenID SourceCodeModel::lastTokenID() const {
  if (d->token_list.empty()) {
    return kInvalidTokenID;
  }

  return d->token_list.at(d->token_list.size() - 1);
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
