/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "astmodel.h"

#include <QDebug>
#include <QMap>
#include <QRegularExpression>
#include <QString>
#include <QTimer>

#include <fstream>
#include <future>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include "astbuilder.h"

namespace multiplier {
namespace {

class ASTDumper final : public pasta::DeclVisitor {
public:
  virtual ~ASTDumper(void) = default;

  explicit ASTDumper(const pasta::AST &ast_, std::stringstream &output_)
      : ast(ast_), output(output_) {}

  pasta::AST ast;
  std::string indent;
  std::stringstream &output;

  void PushIndent(void) { indent += "  "; }

  void PopIndent(void) { indent.resize(indent.size() - 2); }

  void VisitDeclContext(const pasta::DeclContext &dc) {
    output << " {\n";
    PushIndent();
    for (const auto &decl : dc.AlreadyLoadedDecls()) {
      Accept(decl);
    }
    PopIndent();
    output << indent << "}\n";
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitTagDecl(const pasta::TagDecl &decl) final {
    output << indent << decl.KindName();
    VisitDeclContext(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    output << indent << decl.KindName() << "\n";
  }
};

void DumpAST(std::stringstream &output, pasta::AST ast) {
  ASTDumper dumper(ast, output);
  dumper.Accept(ast.TranslationUnit());
}

} // namespace

struct Token final {
  TokenID id{kInvalidTokenID};
  TokenGroupID group_id{kInvalidTokenGroupID};
  QString data;
  TokenColorID color_id{kInvalidTokenColorID};
  QMap<int, QVariant> property_bag;
  TokenAttribute attributes;
};

struct ASTModel::PrivateData final {
  std::vector<TokenID> token_list;
  std::unordered_map<TokenID, Token> token_map;
};

ASTModel::ASTModel(QObject *parent)
    : ITextModel(parent), d(new PrivateData) {}

ASTModel::~ASTModel() {}

TokenID ASTModel::firstTokenID() const {
  if (d->token_list.empty()) {
    return kInvalidTokenID;
  }

  return d->token_list.at(0);
}

TokenID ASTModel::lastTokenID() const {
  if (d->token_list.empty()) {
    return kInvalidTokenID;
  }

  return d->token_list.at(d->token_list.size() - 1);
};

TokenGroupID ASTModel::tokenGroupID(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return kInvalidTokenGroupID;
  }

  const auto &token = token_map_it->second;
  return token.group_id;
}

QString ASTModel::tokenData(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return QString();
  }

  const auto &token = token_map_it->second;
  return token.data;
}

TokenColorID ASTModel::tokenColor(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return kInvalidTokenGroupID;
  }

  const auto &token = token_map_it->second;
  return token.color_id;
}

QVariant ASTModel::tokenProperty(TokenID token_id, int property_id) const {
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

TokenAttribute ASTModel::tokenAttributes(TokenID token_id) const {
  auto token_map_it = d->token_map.find(token_id);
  if (token_map_it == d->token_map.end()) {
    return static_cast<TokenAttribute>(0);
  }

  const auto &token = token_map_it->second;
  return token.attributes;
}

void ASTModel::gotAST(std::shared_ptr<pasta::AST> ast) {

  static TokenID token_id_generator{kInvalidTokenID};
  static TokenColorID color_id_generator{kInvalidTokenColorID};
  static TokenGroupID token_group_id_generator{kInvalidTokenGroupID};

  auto group_id_step = 0;

  auto L_addToken = [&](const QString &str) {
    ++token_id_generator;
    color_id_generator = (color_id_generator + 1) % 7;

    ++group_id_step;
    if (group_id_step == 30) {
      token_group_id_generator = (token_group_id_generator + 1) % 5;
      group_id_step = 0;
    }

    Token token;
    token.id = token_id_generator;
    token.data = str;
    token.color_id = color_id_generator;
    token.group_id = token_group_id_generator + 1;

    d->token_list.push_back(token_id_generator);
    d->token_map.try_emplace(token_id_generator, std::move(token));
  };

  std::stringstream ast_stream;
  DumpAST(ast_stream, *ast);

  std::string line;
  while (std::getline(ast_stream, line)) {
    auto token_list = QString(line.c_str()).split(QRegularExpression("\\b"));
    for (const auto &token : token_list) {
      L_addToken(token);
    }

    L_addToken("\n");
  }

  emit modelReset();
}

} // namespace multiplier
