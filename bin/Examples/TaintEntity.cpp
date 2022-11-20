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
#include <multiplier/AST.h>

DEFINE_uint64(entity_id, 0, "ID of the entity to print");
DEFINE_string(entity_name, "", "Name of the function to search for");

#define FG_BLACK 30
#define FG_RED 31
#define FG_GREEN 32
#define FG_YELLOW 33
#define FG_BLUE 34
#define FG_MAGENTA 35
#define FG_CYAN 36
#define FG_WHITE 37

#define BG_BLACK 40
#define BG_RED 41
#define BG_GREEN 42
#define BG_YELLOW 43
#define BG_BLUE 44
#define BG_MAGENTA 45
#define BG_CYAN 46
#define BG_WHITE 47

#define ATTR_RESET 0
#define ATTR_BRIGHT 1
#define ATTR_DIM 2
#define ATTR_UNDERLINE 3
#define ATTR_BLINK 4
#define ATTR_REVERSE 5
#define ATTR_HIDDEN 8

#define ESC_(x) "\x1B[" #x "m"
#define ESC(x) ESC_(x)

struct UsePath {
  const UsePath *prev{nullptr};
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
};

struct UserDAG {
  unsigned depth{0};
  bool is_alarming{false};
  std::vector<UserDAG *> users;
  std::vector<UserDAG *> uses;
  mx::RawEntityId entity_id{mx::kInvalidEntityId};
};

using SeenEntityMap = std::unordered_map<mx::RawEntityId,
                                         std::unique_ptr<UserDAG>>;

static UserDAG *AddPathToDAG(const UsePath &entry, SeenEntityMap &seen);

// Preferentially use the first redeclaration as the "canonical" version of
// any given decl. Every redecl presents the redecl list in the same order,
// and definitions are ordered before declarations.
static mx::Decl PreferDefinition(const mx::Decl &decl) {
  for (auto redecl : decl.redeclarations()) {
    return redecl;
  }
  return decl;
}

// If the path entry is derived from something, then add the use for this
// path entry as a child to that thing.
static void LinkUseToDAG(const UsePath &entry, UserDAG *use,
                         SeenEntityMap &seen) {
  if (!entry.prev || !entry.prev->entity_id) {
    return;
  }

  auto user = AddPathToDAG(*(entry.prev), seen);
  if (use->users.empty() ||
      std::find(use->users.begin(), use->users.end(), user) ==
          use->users.end()) {
    use->users.push_back(user);
    user->uses.push_back(use);
    use->depth = std::max(use->depth, user->depth + 1u);
  }
}

// Add the temporary entry `entry` into the seen map.
UserDAG *AddPathToDAG(const UsePath &entry, SeenEntityMap &seen) {
  auto &use = seen[entry.entity_id];
  if (!use) {
    use.reset(new UserDAG);
    use->entity_id = entry.entity_id;
  }

  LinkUseToDAG(entry, use.get(), seen);

  return use.get();
}

// Figure out if we've already seen `entry`, and if so, then record the
// provenance to `entry` in the prior record (if any).
inline static bool AlreadySeen(const UsePath &entry, SeenEntityMap &seen) {
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
  LinkUseToDAG(entry, res.first->second.get(), seen);

  return true;
}

// Go and find the entity that will be the source of our taints.
static std::optional<mx::ValueDecl> FindEntity(const mx::Index &index) {
  if (!FLAGS_entity_name.empty()) {
    for (mx::DeclCategory cat : {mx::DeclCategory::FUNCTION,
                                 mx::DeclCategory::INSTANCE_METHOD,
                                 mx::DeclCategory::CLASS_METHOD,
                                 mx::DeclCategory::PARAMETER_VARIABLE,
                                 mx::DeclCategory::LOCAL_VARIABLE,
                                 mx::DeclCategory::GLOBAL_VARIABLE,
                                 mx::DeclCategory::CLASS_MEMBER,
                                 mx::DeclCategory::INSTANCE_MEMBER,
                                 mx::DeclCategory::ENUMERATOR}) {
      for (mx::NamedDecl nd : index.query_entities(FLAGS_entity_name, cat)) {
        if (nd.name() == FLAGS_entity_name) {
          return mx::ValueDecl::from(nd);
        }
      }
    }
  } else if (FLAGS_entity_id) {
    mx::VariantEntity maybe_entity = index.entity(FLAGS_entity_id);
    if (std::holds_alternative<mx::Decl>(maybe_entity)) {
      return mx::ValueDecl::from(std::get<mx::Decl>(maybe_entity));
    }
  }
  return std::nullopt;
}

static void TaintTrackFunc(const mx::FunctionDecl &taint_source,
                           const UsePath &prev, SeenEntityMap &seen);

static void TaintTrackVarOrVarLike(const mx::Decl &taint_source,
                                   const UsePath &prev, SeenEntityMap &seen);

static void ReportTaintedChild(const mx::Stmt &parent, const mx::Stmt &child) {
  auto child_toks = child.tokens().file_tokens();
  for (mx::Token tok : parent.tokens().file_tokens()) {
    if (child_toks.index_of(tok)) {
      std::cerr
          << ESC(ATTR_BRIGHT) ESC(FG_RED) << tok.data() << ESC(ATTR_RESET);
    } else {
      std::cerr
          << ESC(FG_YELLOW) << tok.data() << ESC(ATTR_RESET);
    }
  }
  std::cerr << ESC(ATTR_RESET);
}

static void ReportUnhandledAssign(
    const mx::Stmt &assign, const mx::Stmt &lhs, const mx::Stmt &taint_source) {
  std::cerr
      << ESC(ATTR_BRIGHT) "Unhandled assignment "
      << mx::EnumeratorName(lhs.kind()) << " at " << lhs.id()
      << ":" ESC(ATTR_RESET) << "\n";

  auto lhs_toks = lhs.tokens().file_tokens();
  auto rhs_toks = taint_source.tokens().file_tokens();

  for (auto tok : assign.tokens().file_tokens()) {
    if (lhs_toks.index_of(tok)) {
      std::cerr << ESC(FG_MAGENTA) << tok.data() << ESC(ATTR_RESET);
    } else if (rhs_toks.index_of(tok)) {
      std::cerr
          << ESC(FG_RED) ESC(ATTR_BRIGHT) << tok.data() << ESC(ATTR_RESET);
    } else {
      std::cerr << ESC(ATTR_DIM) << tok.data() << ESC(ATTR_RESET);
    }
  }
  if (auto ref_decl = lhs.referenced_declaration()) {
    std:: cerr << "\nDECL: " ESC(FG_YELLOW);
    for (auto tok : ref_decl->tokens().file_tokens()) {
      std::cerr << tok.data();
    }
  }
  std::cerr << ESC(ATTR_RESET) "\n\n";
}

// This is a dereference of something, e.g. `foo[tainted]`, this is where
// our analysis bottoms out.
static void TaintTrackDeref(const mx::Stmt &op, const UsePath &prev,
                            SeenEntityMap &seen) {
  const UsePath entry{&prev, op.id()};
  UserDAG *dag = AddPathToDAG(entry, seen);
  dag->is_alarming = true;
}


// If we have an operator `op` like `lhs = taint_source`, then try to taint
// the uses of `lhs`.
static void TaintTrackAssign(const mx::Stmt &assign,
                             const mx::Stmt &lhs,
                             const mx::Stmt &taint_source,
                             const UsePath &prev, SeenEntityMap &seen) {

  const UsePath entry{&prev, assign.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  switch (lhs.kind()) {
    default:
    case mx::StmtKind::ARRAY_SUBSCRIPT_EXPR:  // E.g. `foo[index] = taint;`.
    case mx::StmtKind::UNARY_OPERATOR:  // E.g. `*foo = taint;`.
      ReportUnhandledAssign(assign, lhs, taint_source);
      return;

    case mx::StmtKind::MEMBER_EXPR:  // E.g. `foo->bar = taint;`.
    case mx::StmtKind::DECL_REF_EXPR:  // E.g. `foo = taint;`.
      if (std::optional<mx::Decl> ref_decl = lhs.referenced_declaration()) {
        TaintTrackVarOrVarLike(*ref_decl, entry, seen);
      }
      break;
  }
}

// If `taint_source` is an operand in the binary operator `op` then try to
// see if the binary operator is an assignment or accumulation, and then taint
// the left hand side.
static bool TaintTrackBinOp(const mx::Stmt &op, mx::BinaryOperatorKind opcode,
                            const mx::Stmt &lhs, const mx::Stmt &rhs,
                            const mx::Stmt &taint_source,
                            const UsePath &prev, SeenEntityMap &seen) {

  switch (opcode) {
    // Focus on assignment and accumulation operations, e.g.
    // `foo = taint_source;` or `foo += taint_source;`. Other types of binary
    // operators become tainted if one of their operands is tainted.
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

    // Something like `foo + taint_source`. Here we return `false` to say that
    // the caller should keep ascending the tree of expressions because now
    // the result of `foo op taint_source` itself is tainted.
    default:
      return false;
  }

  // Something like `taint_source = foo;`. Here we return `true` to tell the
  // caller that taint propagation has happened (as if the left-hand side is
  // tainted, then it's likely some decl that is tainted, and so we're already
  // visiting all of its uses). The `true` tells the caller "don't ascend any
  // further when looking for taint propagation."
  if (lhs.id() == taint_source.id()) {
    return true;
  }

  TaintTrackAssign(op, lhs, taint_source, prev, seen);
  return true;
}

static bool TaintTrackUnaryOp(const mx::UnaryOperator &op,
                              const mx::Stmt &taint_source,
                              const UsePath &prev, SeenEntityMap &seen) {
  switch (op.opcode()) {
    case mx::UnaryOperatorKind::DEREF:
      TaintTrackDeref(op, prev, seen);
      return true;

    case mx::UnaryOperatorKind::ADDRESS_OF:
      std::cerr
          << ESC(ATTR_BRIGHT) "Unhandled address of tainted value at "
          << op.id() << ":" ESC(ATTR_RESET) "\n";
      ReportTaintedChild(op, taint_source);
      std::cerr << "\n\n";
      return true;

    // Tell the caller to keep ascending to the parent statement to treat it
    // as tainted.
    default:
      return false;
  }
}

// If `taint_source` is a tainted expression, then try to propagate the
// taints to where the expression is used.
static void TaintTrackExpr(const mx::Expr &taint_source,
                           const UsePath &prev, SeenEntityMap &seen);

struct LibraryModel {
  std::string_view func_name;
  unsigned arg_index;
  bool (*propagate_taint)(const mx::CallExpr &, const mx::FunctionDecl &,
                          const mx::ParmVarDecl &, const mx::Stmt &,
                          unsigned, const UsePath &, SeenEntityMap &);
};

static bool AlarmOnLibraryArgument(
    const mx::CallExpr &, const mx::FunctionDecl &, const mx::ParmVarDecl &,
    const mx::Stmt &, unsigned, const UsePath &prev, SeenEntityMap &seen) {
  UserDAG *dag = AddPathToDAG(prev, seen);
  dag->is_alarming = true;
  return true;
}

static bool TaintLibraryReturnValue(const mx::CallExpr &call,
                                    const mx::FunctionDecl &called_func,
                                    const mx::ParmVarDecl &param,
                                    const mx::Stmt &tainted_arg,
                                    unsigned param_index,
                                    const UsePath &prev, SeenEntityMap &seen) {
  TaintTrackExpr(call, prev, seen);
  return true;
}


static bool Ignore(const mx::CallExpr &, const mx::FunctionDecl &,
                   const mx::ParmVarDecl &, const mx::Stmt &, unsigned ,
                   const UsePath &, SeenEntityMap &) {
  return true;
}

static const LibraryModel kLibraryModels[] = {
    {"memcpy", 0u, TaintLibraryReturnValue},
    {"memcpy", 0u, AlarmOnLibraryArgument},
    {"memcpy", 1u, AlarmOnLibraryArgument},
    {"memcpy", 2u, AlarmOnLibraryArgument},

    {"strchr", 0u, TaintLibraryReturnValue},
    {"strstr", 0u, TaintLibraryReturnValue},

    {"strlen", 0u, AlarmOnLibraryArgument},

    {"strcpy", 0u, TaintLibraryReturnValue},
    {"strcpy", 0u, AlarmOnLibraryArgument},
    {"strcpy", 1u, AlarmOnLibraryArgument},

    {"__builtin___strcpy_chk", 0u, TaintLibraryReturnValue},
    {"__builtin___strcpy_chk", 0u, AlarmOnLibraryArgument},
    {"__builtin___strcpy_chk", 1u, AlarmOnLibraryArgument},

    {"memmove", 0u, TaintLibraryReturnValue},
    {"memmove", 0u, AlarmOnLibraryArgument},
    {"memmove", 1u, AlarmOnLibraryArgument},
    {"memmove", 2u, AlarmOnLibraryArgument},

    {"__builtin___memmove_chk", 0u, TaintLibraryReturnValue},
    {"__builtin___memmove_chk", 0u, AlarmOnLibraryArgument},
    {"__builtin___memmove_chk", 1u, AlarmOnLibraryArgument},
    {"__builtin___memmove_chk", 2u, AlarmOnLibraryArgument},

    {"__builtin_object_size", 0u, Ignore},

    {"malloc", 0u, AlarmOnLibraryArgument},
    {"calloc", 1u, AlarmOnLibraryArgument},
    {"__builtin_bswap16", 0u, TaintLibraryReturnValue},
    {"__builtin_bswap32", 0u, TaintLibraryReturnValue},
    {"__builtin_bswap64", 0u, TaintLibraryReturnValue},
    {"ntoh", 0u, TaintLibraryReturnValue},
    {"hton", 0u, TaintLibraryReturnValue},
};

static void ModelLibraryFunction(const mx::CallExpr &call,
                                 const mx::FunctionDecl &called_func,
                                 const mx::ParmVarDecl &param,
                                 const mx::Stmt &tainted_arg,
                                 unsigned param_index,
                                 const UsePath &prev, SeenEntityMap &seen) {
  std::string_view func_name = called_func.name();
  for (const LibraryModel &model : kLibraryModels) {
    if (model.arg_index == param_index && model.func_name == func_name &&
        model.propagate_taint(call, called_func, param, tainted_arg,
                              param_index, prev, seen)) {
      return;
    }
  }

  std::cerr
      << ESC(ATTR_BRIGHT) "Tainted argument escapes into library function "
      << called_func.name() << " ("
      << called_func.id() << ") at "
      << call.id() << ":" ESC(ATTR_RESET) "\n";
  ReportTaintedChild(call, tainted_arg);
  std::cerr << "\n\n";
}

// If `taint_source` is an argument to `call`, then try to taint the parameter
// of the function.
static void TaintTrackCallArg(const mx::CallExpr &call,
                              const mx::Stmt &taint_source,
                              const UsePath &prev, SeenEntityMap &seen) {

  const UsePath entry{&prev, taint_source.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  std::optional<mx::Decl> callee = call.callee_declaration();
  if (!callee) {
    std::cerr
        << ESC(ATTR_BRIGHT) "Unhandled call expression with no callee "
           "declaration at " << call.id() << ":" ESC(ATTR_RESET) "\n";
    ReportTaintedChild(call, taint_source);
    std::cerr << "\n\n";
    return;
  }

  // TODO(pag): Call through a global/local function pointer-typed variable.
  auto called_func = mx::FunctionDecl::from(callee.value());
  if (!called_func) {
    std::cerr
        << ESC(ATTR_BRIGHT) "Unhandled call expression with non-function "
           "callee at " << call.id() << ":" ESC(ATTR_RESET) "\n";
    ReportTaintedChild(call, taint_source);
    std::cerr << "\n\n";
    return;
  }

  std::vector<mx::ParmVarDecl> params = called_func->parameters();

  // Go try to match the argument to a parameter.
  auto arg_num = 0u;
  auto matched = false;
  for (mx::Expr arg : call.arguments()) {
    if (arg.id() != taint_source.id()) {
      ++arg_num;
      continue;
    }

    // TODO(pag): Taint `va_arg` macro use when variadic arguments are used.
    if (arg_num >= params.size()) {
      break;
    }

    // Found the parameter associated with this call argument.
    matched = true;
    break;
  }

  // Didn't match the argument to a parameter.
  if (!matched) {
    std::cerr
        << ESC(ATTR_BRIGHT) "Tainted argument cannot be matched with "
           "function parameter at "
        << call.id() << "; function " << called_func->name() << " ("
        << called_func->id() << ") ";

    if (called_func->is_variadic()) {
      std::cerr << "is variadic";
    } else {
      std::cerr
          << ESC(ATTR_UNDERLINE) "isn't variadic"
             ESC(ATTR_RESET) ESC(ATTR_BRIGHT);
    }

    std::cerr << ":" ESC(ATTR_RESET) "\n";
    ReportTaintedChild(call, taint_source);
    std::cerr << "\n\n";
    return;
  }

  // Can't see into the definition of the callee, so we can't propagate taints
  // to that argument.
  std::optional<mx::Decl> def = called_func->definition();

  if (std::optional<mx::FunctionDecl> func_def = mx::FunctionDecl::from(def)) {
    TaintTrackVarOrVarLike(func_def->parameters()[arg_num], entry, seen);

  } else {
    ModelLibraryFunction(call, called_func.value(), params[arg_num],
                         taint_source, arg_num, entry, seen);
  }
}

// If we find `return taint_source`, then taint the function.
static void TaintTrackReturn(const mx::Stmt &ret, const UsePath &prev,
                             SeenEntityMap &seen) {
  const UsePath entry{&prev, ret.id()};
  if (auto func = mx::FunctionDecl::containing(ret)) {
    TaintTrackFunc(*func, entry, seen);
  }
}

// If `taint_source` is a tainted expression, then try to propagate the
// taints to where the expression is used.
void TaintTrackExpr(const mx::Expr &taint_source,
                           const UsePath &prev, SeenEntityMap &seen) {
  const UsePath entry{&prev, taint_source.id()};
  if (AlreadySeen(entry, seen)) {
    return;
  }

  mx::Stmt child = taint_source;
  for (mx::Stmt parent : mx::Stmt::containing(taint_source)) {
    switch (parent.kind()) {
      // E.g. `if (a < tainted_source)`. Here we just want to ignore the tainted
      // control-flow.
      case mx::StmtKind::IF_STMT:
      case mx::StmtKind::DO_STMT:
      case mx::StmtKind::WHILE_STMT:
      case mx::StmtKind::FOR_STMT:
      case mx::StmtKind::SWITCH_STMT:
      case mx::StmtKind::COMPOUND_STMT:
      case mx::StmtKind::CASE_STMT:
      case mx::StmtKind::DEFAULT_STMT:
        return;

      // E.g. DECL_REF_EXPR.
      default:
        break;

      // Something like `return taint_source;`.
      case mx::StmtKind::RETURN_STMT:
        TaintTrackReturn(parent, entry, seen);
        return;

      // Something like `foo->bar = taint_source;`.
      case mx::StmtKind::COMPOUND_ASSIGN_OPERATOR:
        if (auto assign = mx::CompoundAssignOperator::from(parent)) {
          (void) TaintTrackBinOp(
              *assign, assign->opcode(), assign->lhs(), assign->rhs(),
              child, entry, seen);
        }
        return;

      // Something like `foo(taint_source())`.
      case mx::StmtKind::CALL_EXPR:
        TaintTrackCallArg(mx::CallExpr::from(parent).value(), child,
                          entry, seen);
        return;

      // Something like `foo = taint_source()`, `foo += taint_source()`.
      case mx::StmtKind::BINARY_OPERATOR:
        if (auto binop = mx::BinaryOperator::from(parent);
            TaintTrackBinOp(*binop, binop->opcode(), binop->lhs(), binop->rhs(),
                            child, entry, seen)) {
          return;
        }
        break;

      // Something like `*taint_source()`.
      case mx::StmtKind::UNARY_OPERATOR:
        if (auto unop = mx::UnaryOperator::from(parent);
            TaintTrackUnaryOp(*unop, child, entry, seen)) {
          return;
        }
        break;

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

  // Look for `type var = taint_source;`.
  if (auto parent_var = mx::VarDecl::from(child.parent_declaration())) {
    TaintTrackVarOrVarLike(*parent_var, entry, seen);
    return;
  }

  std::cerr
      << ESC(ATTR_BRIGHT) "Unable to propagate taint through expression at "
      << child.id() << ":" ESC(ATTR_RESET) "\n";
  ReportTaintedChild(child, taint_source);
  std::cerr << "\n\n";
}

// If `call` is a call to `taint_source`, then try to propagate the taints of
// the call to where the call is used.
static void TaintTrackCallRet(const mx::CallExpr &call,
                              const mx::Stmt &taint_source,
                              const mx::FunctionDecl &tainted_func,
                              const UsePath &prev, SeenEntityMap &seen) {

  std::optional<mx::Decl> callee = call.callee_declaration();
  if (!callee) {
    std::cerr
        << ESC(ATTR_BRIGHT) "Unhandled call expression with no callee "
           "declaration at " << call.id() << ":" ESC(ATTR_RESET) "\n";
    ReportTaintedChild(call, taint_source);
    std::cerr << "\n\n";
    return;
  }

  if (PreferDefinition(*callee).id() != PreferDefinition(tainted_func).id()) {
    std::cerr
        << ESC(ATTR_BRIGHT) "Not tainting call using tainted function, "
           "but not calling it at " << call.id() << ":" ESC(ATTR_RESET) "\n";
    ReportTaintedChild(call, taint_source);
    std::cerr << "\n\n";
    return;
  }

  TaintTrackExpr(call, prev, seen);
}

// If `taint_source` is a function whose return value should be tainted, then
// look for every call to `taint_source` and then taint the values used at the
// call sites.
void TaintTrackFunc(const mx::FunctionDecl &taint_source,
                    const UsePath &prev, SeenEntityMap &seen) {
  if (!taint_source.return_type().unqualified_desugared_type().is_void_type()) {
    UsePath entry{&prev, PreferDefinition(taint_source).id()};
    if (!AlreadySeen(entry, seen)) {
      for (mx::Reference ref : taint_source.references()) {
        mx::Stmt stmt_taint_source = ref.statement();
        if (auto call = mx::CallExpr::containing(stmt_taint_source)) {
          TaintTrackCallRet(call.value(), stmt_taint_source, taint_source,
                            entry, seen);
        }
      }
    }
  }
}

// If `taint_source` is a variable that can be tainted, then find every use of
// `taint_source` and taint the users.
void TaintTrackVarOrVarLike(const mx::Decl &taint_source,
                            const UsePath &prev, SeenEntityMap &seen) {

  UsePath entry{&prev, PreferDefinition(taint_source).id()};
  if (!AlreadySeen(entry, seen)) {
    for (mx::Reference ref : taint_source.references()) {
      mx::Stmt stmt = ref.statement();
      if (std::optional<mx::Expr> expr = mx::Expr::from(stmt)) {
        TaintTrackExpr(*expr, entry, seen);
      } else {
        std::cerr
            << ESC(ATTR_BRIGHT) "Not tainting non-expression use at "
            << stmt.id() << ":" ESC(ATTR_RESET) "\n";
        ReportTaintedChild(stmt, stmt);
        std::cerr << "\n\n";
        return;
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

  } else if (std::holds_alternative<mx::ParsedTokenId>(vid)) {
    auto eid = std::get<mx::ParsedTokenId>(vid);
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
    << " [--db DATABASE] [--entity_id ID | --entity_name NAME]\n";

  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample();

  mx::TokenRange entity_tokens;
  std::optional<mx::Fragment> fragment;

  UsePath root;
  SeenEntityMap seen;
  std::optional<mx::ValueDecl> entity = FindEntity(index);
  if (!entity) {
    std::cerr << "Could not find entity by id or name.\n";
    return EXIT_FAILURE;
  }

  if (std::optional<mx::FunctionDecl> func = mx::FunctionDecl::from(entity)) {
    TaintTrackFunc(*func, root, seen);
  } else {
    TaintTrackVarOrVarLike(*entity, root, seen);
  }

  auto code = EXIT_FAILURE;

  for (const auto &[id, entry] : seen) {
    if (!entry) {
      continue;
    }

    if (code == EXIT_FAILURE) {
      std::cout
          << "digraph {\n"
          << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";
      code = EXIT_SUCCESS;
    }

    auto [kind, color] = KindAndColor(id);
    if (entry->is_alarming) {
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

    for (const UserDAG *next : entry->uses) {
      std::cout << "e" << id << " -> e" << next->entity_id << ";\n";
    }
  }

  if (code == EXIT_SUCCESS) {
    std::cout << "}\n";


    std::cerr
        << ESC(ATTR_BRIGHT) ESC(FG_MAGENTA)
           "Tainted data reached a memory dereferences."
           ESC(ATTR_RESET) "\n";
    return code;
  }

  std::cerr
      << ESC(ATTR_BRIGHT) ESC(FG_CYAN)
         "Tainted data didn't reach any memory dereferences."
         ESC(ATTR_RESET) "\n";
  return code;
}
