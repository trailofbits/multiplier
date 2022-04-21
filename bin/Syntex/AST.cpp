// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "AST.h"

#include <multiplier/API.h>
#include <ostream>
#include <sstream>

namespace syntex {

ASTNode::ASTNode(const mx::Fragment &)
    : kind(kFragment),
      kind_val(0),
      data(ChildVector()) {}

ASTNode::ASTNode(const mx::Decl &decl)
    : kind(kDeclKind),
      kind_val(static_cast<unsigned short>(decl.kind())),
      data(ChildVector()) {}

ASTNode::ASTNode(const mx::Stmt &stmt)
    : kind(kStmtKind),
      kind_val(static_cast<unsigned short>(stmt.kind())),
      data(ChildVector()) {}

ASTNode::ASTNode(const mx::Type &type)
    : kind(kTypeKind),
      kind_val(static_cast<unsigned short>(type.kind())),
      data(ChildVector()) {}

ASTNode::ASTNode(const mx::Token &tok)
    : kind(kTokenKind),
      kind_val(static_cast<unsigned short>(tok.kind())),
      data(std::string(tok.data().data(), tok.data().size())) {}

bool ASTNode::operator==(const ASTNode &that) const noexcept {

  if (kind != that.kind || kind_val != that.kind_val) {
    return false;
  }

  if (kind == kTokenKind) {
    return std::get<std::string>(data) == std::get<std::string>(that.data);
  } else {
    const ChildVector &this_children = std::get<ChildVector>(data);
    const ChildVector &that_children = std::get<ChildVector>(that.data);
    auto num_children = this_children.size();
    if (num_children != that_children.size()) {
      return false;
    }

    for (auto i = 0u; i < num_children; ++i) {
      if (!(*(this_children[i]) == *(that_children[i]))) {
        return false;
      }
    }
  }

  return true;
}

AST::AST(void) {
  index.resize(mx::NumEnumerators(mx::DeclKind{}) +
               mx::NumEnumerators(mx::StmtKind{}) +
               mx::NumEnumerators(mx::TypeKind{}) +
               mx::NumEnumerators(mx::TokenKind{}));
}

const ASTNode *AST::LastNodeOfKind(mx::DeclKind kind) {
  return index[static_cast<unsigned>(kind)];
}

const ASTNode *AST::LastNodeOfKind(mx::StmtKind kind) {
  return index[mx::NumEnumerators(mx::DeclKind{}) +
               static_cast<unsigned>(kind)];
}

const ASTNode *AST::LastNodeOfKind(mx::TypeKind kind) {
  return index[mx::NumEnumerators(mx::DeclKind{}) +
               mx::NumEnumerators(mx::StmtKind{}) +
               static_cast<unsigned>(kind)];
}

const ASTNode *AST::LastNodeOfKind(mx::TokenKind kind) {
  return index[mx::NumEnumerators(mx::DeclKind{}) +
               mx::NumEnumerators(mx::StmtKind{}) +
               mx::NumEnumerators(mx::TypeKind{}) +
               static_cast<unsigned>(kind)];
}

AST AST::Build(mx::Fragment fragment) {
  AST self;
  ASTNode *root = &(self.nodes.emplace_back(fragment));

  std::vector<mx::TokenContext> contexts;

  for (mx::Token tok : mx::Token::in(fragment)) {
    switch (tok.kind()) {
      case mx::TokenKind::UNKNOWN:
      case mx::TokenKind::WHITESPACE:
      case mx::TokenKind::COMMENT:
        continue;
      default:
        if (tok.data().empty()) {
          continue;
        }
        break;
    }

    const ASTNode *curr = root;

    contexts.clear();
    for (auto context = mx::TokenContext::of(tok); context;
         context = context->parent()) {
      if (!context->is_alias()) {
        contexts.emplace_back(*context);
      }
    }

    for (auto c_it = contexts.rbegin(), c_end = contexts.rend();
         c_it != c_end; ++c_it) {
      const mx::TokenContext &c = *c_it;
      std::optional<ASTNode> dummy;
      const ASTNode **last_ptr = nullptr;

      // Declarations.
      if (auto decl = mx::Decl::from(c)) {
        dummy.emplace(*decl);
        last_ptr = &(self.index[dummy->kind_val]);

      // Statements.
      } else if (auto stmt = mx::Stmt::from(c)) {
        switch (stmt->kind()) {
          case mx::StmtKind::IMPLICIT_CAST_EXPR:
          case mx::StmtKind::DECL_REF_EXPR:
            continue;  // Skip these; they are spam.
          default:
            dummy.emplace(*stmt);
            last_ptr =
                &(self.index[mx::NumEnumerators(mx::DeclKind{}) +
                             dummy->kind_val]);
            break;
        }

      // Types.
      } else if (auto type = mx::Type::from(c)) {
        dummy.emplace(*type);
        last_ptr = &(self.index[mx::NumEnumerators(mx::DeclKind{}) +
                                mx::NumEnumerators(mx::StmtKind{}) +
                                dummy->kind_val]);

      } else {
        continue;
      }

      ASTNode::ChildVector &curr_children =
          std::get<ASTNode::ChildVector>(curr->data);

      // Need to add a new branch.
      if (curr_children.empty()) {
        auto next_curr = &(self.nodes.emplace_back(std::move(*dummy)));
        next_curr->prev_of_kind = *last_ptr;
        *last_ptr = next_curr;
        curr_children.emplace_back(next_curr);
        curr = next_curr;
        continue;
      }

      // The last thing doesn't match.
      const ASTNode *last_child = curr_children.back();
      if (last_child->kind != dummy->kind ||
          last_child->kind_val != dummy->kind_val) {
        auto next_curr = &(self.nodes.emplace_back(std::move(*dummy)));
        next_curr->prev_of_kind = *last_ptr;
        *last_ptr = next_curr;
        curr_children.emplace_back(next_curr);
        curr = next_curr;
        continue;
      }

      // The last thing matches, use it.
      curr = last_child;
    }

    // Add the token.
    ASTNode *tok_node = &(self.nodes.emplace_back(tok));
    const ASTNode **last_tok_ptr =
        &(self.index[mx::NumEnumerators(mx::DeclKind{}) +
                     mx::NumEnumerators(mx::StmtKind{}) +
                     mx::NumEnumerators(mx::TypeKind{}) +
                     tok_node->kind_val]);
    tok_node->prev_of_kind = *last_tok_ptr;
    *last_tok_ptr = tok_node;
    std::get<ASTNode::ChildVector>(curr->data).emplace_back(tok_node);
  }

  return self;
}

namespace {

static std::string Data(const std::string &data) {
  std::stringstream ss;
  for (auto ch : data) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << "<BR>"; break;
      case '&': ss << "&amp;"; break;
      case '\t': ss << "&nbsp; "; break;
      case '\r': break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

}  // namespace

void AST::PrintDOT(std::ostream &os) const {
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
  for (const ASTNode &node : nodes) {
    os << "x" << std::hex << reinterpret_cast<uintptr_t>(&node) << std::dec
       << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" "
       << "border=\"1\"><TR><TD";

    switch (node.kind) {
      case ASTNode::kFragment:
        os
          << " bgcolor=\"darksalmon\"> </TD></TR></TABLE>>];\n";
        break;

      case ASTNode::kDeclKind:
        os
          << " bgcolor=\"aquamarine\">"
          << mx::EnumeratorName(static_cast<mx::DeclKind>(node.kind_val))
          << "</TD></TR></TABLE>>];\n";
        break;
      case ASTNode::kStmtKind:
        os
          << " bgcolor=\"darkolivegreen3\">"
          << mx::EnumeratorName(static_cast<mx::StmtKind>(node.kind_val))
          << "</TD></TR></TABLE>>];\n";
        break;
      case ASTNode::kTypeKind:
        os
          << " bgcolor=\"goldenrod\">"
          << mx::EnumeratorName(static_cast<mx::TypeKind>(node.kind_val))
          << "</TD></TR></TABLE>>];\n";
        break;
      case ASTNode::kTokenKind:
        os
          << " bgcolor=\"cornsilk2\">"
          << mx::EnumeratorName(static_cast<mx::TokenKind>(node.kind_val))
          << "</TD></TR><TR><TD bgcolor=\"antiquewhite\">"
          << Data(std::get<std::string>(node.data))
          << "</TD></TR></TABLE>>];\n";
        break;

    }

    if (std::holds_alternative<ASTNode::ChildVector>(node.data)) {
      for (const ASTNode *child : std::get<ASTNode::ChildVector>(node.data)) {
        os << "x" << std::hex << reinterpret_cast<uintptr_t>(&node)
           << " -> x" << std::hex << reinterpret_cast<uintptr_t>(child)
           << std::dec << ";\n";
      }
    }
  }
  os << "}\n";
}

}  // namespace syntex
