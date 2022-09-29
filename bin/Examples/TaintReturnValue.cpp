// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <sstream>
#include <unordered_map>

#include "Index.h"

DEFINE_uint64(entity_id, 0, "ID of the entity to print");
DEFINE_bool(unparsed, false, "Show original source code?");
DEFINE_string(function_name, "", "Name of the function to search for");

struct TempPathEntry {
  const TempPathEntry *prev{nullptr};
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
};

struct PathEntry {
  std::vector<PathEntry *> prev;
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
};

using SeenEntityMap = std::unordered_map<mx::RawEntityId,
                                         std::unique_ptr<PathEntry>>;

// Add the temporary entry `entry` into the seen map.
static PathEntry *AddToPath(const TempPathEntry &entry, SeenEntityMap &seen) {
  auto &path = seen[entry.entity_id];
  if (!path) {
    path.reset(new PathEntry);
    path->entity_id = entry.entity_id;
  }

  if (entry.prev) {
    path->prev.push_back(AddToPath(*(entry.prev), seen));
  }
  return path.get();
}

// Figue out if we've already seen `entry`, and if so, then record the
// provenance to `entry` in the prior record (if any).
inline static bool AlreadySeen(const TempPathEntry &entry,
                               SeenEntityMap &seen) {
  auto res = seen.emplace(entry.entity_id, nullptr);

  // We just added this entry, i.e. we've not seen it yet.
  if (res.second) {
    return false;
  }

  // We've already come across this, and didn't previously taint it.
  if (!res.first->second) {
    return true;
  }

  // Record the previous path if this path was already seen and has a
  // positive hit.
  if (entry.prev) {
    res.first->second->prev.push_back(AddToPath(*(entry.prev), seen));
  }

  return true;
}

// Go and find the function that will be the source of our taints.
static std::optional<mx::FunctionDecl> FindFunction(const mx::Index &index) {
  if (!FLAGS_function_name.empty()) {
    for (mx::DeclCategory cat : {mx::DeclCategory::FUNCTION,
                                 mx::DeclCategory::INSTANCE_METHOD,
                                 mx::DeclCategory::CLASS_METHOD}) {
      for (mx::NamedDecl nd : index.query_entities(FLAGS_function_name, cat)) {
        if (nd.name() == FLAGS_function_name) {
          return mx::FunctionDecl::from(nd);
        }
      }
    }
  } else if (FLAGS_entity_id) {
    mx::VariantEntity maybe_entity = index.entity(FLAGS_entity_id);
    if (std::holds_alternative<mx::Decl>(maybe_entity)) {
      return mx::FunctionDecl::from(std::get<mx::Decl>(maybe_entity));
    }
  }
  return std::nullopt;
}


static void TaintTrackFunc(const mx::FunctionDecl &taint_source,
                           const TempPathEntry &prev, SeenEntityMap &seen);

static void TaintTrackVar(const mx::VarDecl &taint_source,
                          const TempPathEntry &prev, SeenEntityMap &seen);

// If we have an operator `op` like `lhs = taint_source`, then try to taint
// the uses of `lhs`.
static void TaintTrackAssign(mx::BinaryOperator op, mx::Expr taint_source,
                             const TempPathEntry &prev, SeenEntityMap &seen) {

  const TempPathEntry entry{&prev, op.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  // TODO(pag): TODO TODO TODO
}


// If `taint_source` is an operand in the binary operator `op` then try to
// see if the binary operator is an assignment or accumulation, and then taint
// the left hand side.
static bool TaintTrackBinOp(mx::BinaryOperator op, const mx::Expr &taint_source,
                            const TempPathEntry &prev, SeenEntityMap &seen) {

  // TODO(pag): Inspect the entity to which we've accumulated values in the
  //            case that `taint_source` is the LHS of something like a
  //            `MUL_ASSIGN`.
  if (op.rhs().id() != taint_source.id()) {
    return false;
  }

  switch (op.opcode()) {
    case mx::BinaryOperatorKind::ASSIGN:
    case mx::BinaryOperatorKind::MUL_ASSIGN:
    case mx::BinaryOperatorKind::DIV_ASSIGN:
    case mx::BinaryOperatorKind::REM_ASSIGN:
    case mx::BinaryOperatorKind::ADD_ASSIGN:
    case mx::BinaryOperatorKind::SUB_ASSIGN:
    case mx::BinaryOperatorKind::SHL_ASSIGN:
    case mx::BinaryOperatorKind::SHR_ASSIGN:
    case mx::BinaryOperatorKind::AND_ASSIGN:
    case mx::BinaryOperatorKind::XOR_ASSIGN:
    case mx::BinaryOperatorKind::OR_ASSIGN:
      break;
    default:
      return false;
  }

  TaintTrackAssign(std::move(op), std::move(taint_source), prev, seen);
  return true;
}

// If `taint_source` is an argument to `call`, then try to taint the parameter
// of the function.
static void TaintTrackCallArg(mx::CallExpr call, mx::Expr taint_source,
                              const TempPathEntry &prev, SeenEntityMap &seen) {

  const TempPathEntry entry{&prev, taint_source.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  std::optional<mx::Decl> callee = call.callee_declaration();
  if (!callee) {
    return;
  }

  // TODO(pag): Call through a global/local function pointer-typed variable.
  auto called_func = mx::FunctionDecl::from(callee.value());
  if (!called_func) {
    return;
  }

  // Can't see into the definition of the callee, so we can't propagate taints
  // to that argument.
  std::optional<mx::Decl> def = called_func->definition();
  if (!def) {
    return;
  }

  auto arg_num = 0u;
  for (mx::Expr arg : call.arguments()) {
    if (arg.id() != taint_source.id()) {
      ++arg_num;
      continue;
    }

    // TODO(pag): Taint `va_arg` macro use when variadic arguments are used.
    std::optional<mx::FunctionDecl> func_def = mx::FunctionDecl::from(def);
    std::vector<mx::ParmVarDecl> params = func_def->parameters();
    if (arg_num >= params.size()) {
      return;
    }

    // Found the parameter associated with this call argument.
    TaintTrackVar(std::move(params[arg_num]), entry, seen);
    break;
  }
}

// This is a dereference of something, e.g. `foo[tainted]`, this is where
// our analysis bottoms out.
static void TaintTrackDeref(const mx::Expr &op, const TempPathEntry &prev,
                            SeenEntityMap &seen) {
  const TempPathEntry entry{&prev, op.id()};
  AddToPath(entry, seen);
}

// If we find `return taint_source`, then taint the function.
static void TaintTrackReturn(mx::ReturnStmt ret, const TempPathEntry &prev,
                             SeenEntityMap &seen) {
  const TempPathEntry entry{&prev, ret.id()};
  if (auto func = mx::FunctionDecl::containing(ret)) {
    TaintTrackFunc(*func, entry, seen);
  }
}

// If `taint_source` is a tainted expression, then try to propagate the
// taints to where the expression is used.
static void TaintTrackExpr(const mx::Expr &taint_source,
                           const TempPathEntry &prev, SeenEntityMap &seen) {
  const TempPathEntry entry{&prev, taint_source.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  mx::Expr child = taint_source;
  for (mx::Expr parent : mx::Expr::containing(taint_source)) {
    switch (parent.kind()) {
      // E.g. DECL_REF_EXPR.
      default:
        break;

      // Something like `foo(taint_source())`.
      case mx::StmtKind::CALL_EXPR:
        TaintTrackCallArg(mx::CallExpr::from(parent).value(), child,
                          entry, seen);
        return;

      // Something like `foo = taint_source()`, `foo += taint_source()`.
      case mx::StmtKind::BINARY_OPERATOR:
        if (TaintTrackBinOp(mx::BinaryOperator::from(parent).value(),
                            child, entry, seen)) {
          return;
        }
        break;

      // Something like `*taint_source()`.
      case mx::StmtKind::UNARY_OPERATOR:
        if (mx::UnaryOperator::from(parent)->opcode() ==
                mx::UnaryOperatorKind::DEREF) {
          TaintTrackDeref(parent, entry, seen);
        }
        return;

      // Something like `foo[taint_source()]`.
      //
      // This is what we want to find!
      case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:
        if (mx::ArraySubscriptExpr::from(parent)->index().id() == child.id()) {
          TaintTrackDeref(parent, entry, seen);
        }
        return;
    }

    child = parent;
  }

  // Something like `return taint_source;`.
  if (auto ret = mx::ReturnStmt::containing(child)) {
    TaintTrackReturn(*ret, entry, seen);
    return;
  }

  // Look for `type var = taint_source;`.
  if (auto parent_var = mx::VarDecl::from(child.parent_declaration())) {
    TaintTrackVar(*parent_var, entry, seen);
  }
}

// If `call` is a call to `taint_source`, then try to propagate the taints of
// the call to where the call is used.
static void TaintTrackCallRet(mx::CallExpr call, mx::FunctionDecl taint_source,
                              const TempPathEntry &prev, SeenEntityMap &seen) {



  std::optional<mx::Decl> callee = call.callee_declaration();
  if (!callee) {
    return;
  }

  if (callee->id() == taint_source.id()) {
    TaintTrackExpr(call, prev, seen);
    return;
  }

  for (mx::Decl redecl : taint_source.redeclarations()) {
    if (redecl.id() == callee->id()) {
      TaintTrackExpr(call, prev, seen);
      return;
    }
  }
}

// If `taint_source` is a function whose return value should be tainted, then
// look for every call to `taint_source` and then taint the values used at the
// call sites.
void TaintTrackFunc(const mx::FunctionDecl &taint_source,
                    const TempPathEntry &prev, SeenEntityMap &seen) {
  if (!taint_source.return_type().unqualified_desugared_type().is_void_type()) {
    TempPathEntry entry{&prev, taint_source.id()};
    if (!AlreadySeen(entry, seen)) {
      for (mx::Reference ref : taint_source.references()) {
        if (auto call = mx::CallExpr::containing(ref.statement())) {
          TaintTrackCallRet(call.value(), taint_source, entry, seen);
        }
      }
    }
  }
}

// If `taint_source` is a variable that can be tainted, then find every use of
// `taint_source` and taint the users.
void TaintTrackVar(const mx::VarDecl &taint_source,
                   const TempPathEntry &prev, SeenEntityMap &seen) {

  TempPathEntry entry{&prev, taint_source.id()};
  if (!AlreadySeen(entry, seen)) {
    for (mx::Reference ref : taint_source.references()) {
      mx::Stmt stmt = ref.statement();
      if (auto expr = mx::Expr::from(stmt)) {
        TaintTrackExpr(*expr, entry, seen);
      }
    }
  }
}

static std::pair<const char *, const char *>
KindAndColor(mx::RawEntityId id) {
  mx::VariantId vid = mx::EntityId(id).Unpack();
  if (std::holds_alternative<mx::DeclarationId>(vid)) {
    auto eid = std::get<mx::DeclarationId>(vid);
    return {mx::EnumeratorName(eid.kind), "antiquewhite"};

  } else if (std::holds_alternative<mx::StatementId>(vid)) {
    auto eid = std::get<mx::StatementId>(vid);
    return {mx::EnumeratorName(eid.kind), "aquamarine"};

  } else if (std::holds_alternative<mx::TypeId>(vid)) {
    auto eid = std::get<mx::TypeId>(vid);
    return {mx::EnumeratorName(eid.kind), "cadetblue1"};

  } else if (std::holds_alternative<mx::FragmentTokenId>(vid)) {
    auto eid = std::get<mx::FragmentTokenId>(vid);
    return {mx::EnumeratorName(eid.kind), "deepskyblue3"};

  } else if (std::holds_alternative<mx::FileTokenId>(vid)) {
    auto eid = std::get<mx::FileTokenId>(vid);
    return {mx::EnumeratorName(eid.kind), "deepskyblue3"};

  } else if (std::holds_alternative<mx::AttributeId>(vid)) {
    auto eid = std::get<mx::AttributeId>(vid);
    return {mx::EnumeratorName(eid.kind), "antiquewhite3"};

  } else if (std::holds_alternative<mx::DesignatorId>(vid)) {
    auto eid = std::get<mx::DesignatorId>(vid);
    return {"Designator", "chartreuse3"};

  } else {
    return {"Other", "darkseagreen2"};
  }
}

static std::ostream &TokData(mx::Token tok, std::ostream &ss) {
  for (auto ch : tok.data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      default: ss << ch; break;
    }
  }
  return ss;
}

extern "C" int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss
    << "Usage: " << argv[0]
    << " [--host HOST] [--port PORT] [--entity_id ID | --function_name STR]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  mx::TokenRange entity_tokens;
  std::optional<mx::Fragment> fragment;

  std::optional<mx::FunctionDecl> func = FindFunction(index);
  if (!func) {
    std::cerr << "Could not find function for entity ID or function name\n";
    return EXIT_FAILURE;
  }

  TempPathEntry root;
  SeenEntityMap seen;
  TaintTrackFunc(*func, root, seen);

  std::cout << "digraph {\n";
  for (const auto &[id, entry] : seen) {
    if (!entry) {
      continue;
    }

    auto [kind, color] = KindAndColor(id);
    if (FLAGS_entity_id == func->id()) {
      color = "red";
    }

    std::cout
        << "e" << id
        << " [label=<<TABLE border=\"1\" cellpadding=\"1\" cellspacing=\"0\" bgcolor=\""
        << color << "\"><TR><TD>";

    mx::VariantEntity entity = index.entity(id);
    if (std::holds_alternative<mx::Decl>(entity)) {
      std::cout << id;
      if (auto vd = mx::VarDecl::from(std::get<mx::Decl>(entity))) {
        std::cout << "</TD></TR><TR><TD>";
        for (mx::Token tok : vd->tokens().file_tokens()) {
          TokData(tok, std::cout);
          std::cout << ' ';
        }
      } else if (auto nd = mx::NamedDecl::from(std::get<mx::Decl>(entity))) {
        std::cout << "</TD></TR><TR><TD>";
        TokData(nd->token(), std::cout);
      }

    } else if (std::holds_alternative<mx::Stmt>(entity)) {
      for (mx::Token tok : std::get<mx::Stmt>(entity).tokens().file_tokens()) {
        TokData(tok, std::cout);
        std::cout << ' ';
      }
    }

    std::cout
        << "</TD></TR><TR><TD>"
        << kind << "</TD></TR></TABLE>>];\n";

    std::sort(entry->prev.begin(), entry->prev.end());
    auto it = std::unique(entry->prev.begin(), entry->prev.end());
    entry->prev.erase(it, entry->prev.end());

    for (const PathEntry *prev : entry->prev) {
      if (prev) {
        std::cout << "e" << id << " -> e" << prev->entity_id << ";\n";
      }
    }
  }
  std::cout << "}\n";

  return EXIT_SUCCESS;
}
