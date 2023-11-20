// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "multiplier/Entities/FunctionDecl.h"
#include "multiplier/Entities/ReturnStmt.h"
#include "multiplier/Entities/Stmt.h"
#include "multiplier/Reference.h"
#include "multiplier/Types.h"

#include <multiplier/Analysis/CallAnalysis.h>

namespace mx {

CallAnalysis::CallAnalysis(Index &index) : index(index) {}

// For this call expression, preview the set of potential return values.
// TODO: resolve tail calls
std::unordered_set<PackedStmtId> CallAnalysis::return_value_set(const CallExpr &expr) {
    std::unordered_set<PackedStmtId> ret_val_set;
    std::stack<Stmt> stmt_stack;

    std::optional<mx::FunctionDecl> function_decl = expr.direct_callee();
    if (!function_decl) {
        return ret_val_set;
    }

    // TODO/WIP: ASTVisitor style instead of maintaining a stack

    auto function_body = function_decl->body();
    if (!function_body) {
        return ret_val_set;
    }
    stmt_stack.push(*function_body);

    while (!stmt_stack.empty()) {
        Stmt curr_stmt = stmt_stack.top();
        stmt_stack.pop();

        if (auto ret_stmt = ReturnStmt::from(curr_stmt)) {
            // TODO: what if it's a tail call? Resolve that and be sure to annotate
            if (auto return_value = ret_stmt->return_value()) {
                ret_val_set.insert(return_value->id());
            }
        }

        // Add all children to the stack
        for (Stmt child : curr_stmt.children()) {
            stmt_stack.push(child);
        }
    }

    return ret_val_set;
}

void CallAnalysis::call_graph_to(const FunctionDecl &function_decl) {
    if (auto named = mx::NamedDecl::from(function_decl)) {
    }

    auto decls = Decl::containing(function_decl);
    auto decl = decls.begin();
    if (decl != decls.end()) {
    } else {
        for (Reference ref : function_decl.references()) {
            if (auto ref_stmt = ref.as_statement()) {

            } else if (auto ref_decl = ref.as_declaration()) {

            }
        }
    }
}

void CallAnalysis::call_graph_from(const FunctionDecl &function_decl) {
    
}

}; // namespace mx