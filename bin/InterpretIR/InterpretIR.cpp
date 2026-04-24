// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// A concrete interpreter for the Multiplier IR. Thin CLI wrapper around the
// interpreter library at lib/IR/Interpret/.
//
// Usage: mx-interpret-ir --db /path/to/index.db --entity_name "function_name"

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Index.h"
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/IR/Interpret/ConcretePolicy.h>
#include <multiplier/IR/Interpret/Interpreter.h>
#include <multiplier/IR/Interpret/Policy.h>

DEFINE_uint64(entity_id, mx::kInvalidEntityId, "ID of the entity to interpret");
DEFINE_string(entity_name, "", "Name of the function to interpret");
DEFINE_bool(trace, false, "Print each instruction as it executes");
DEFINE_uint64(max_steps, 100000, "Maximum instruction steps before aborting");

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss << "Usage: " << argv[0] << " --db DATABASE --entity_name FUNC_NAME\n"
     << "Interprets the IR of the named function.";
  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(false);

  // Find the function.
  std::optional<mx::IRFunction> ir_func;

  if (FLAGS_entity_id != mx::kInvalidEntityId) {
    LOG(ERROR) << "Direct IRFunction ID lookup not yet supported. "
               << "Use --entity_name.";
    return 1;
  }

  if (!FLAGS_entity_name.empty()) {
    for (auto frag : mx::Fragment::in(index)) {
      for (auto decl : mx::Decl::in(frag)) {
        auto func_decl = mx::FunctionDecl::from(decl);
        if (!func_decl) continue;
        if (std::string(func_decl->name()) != FLAGS_entity_name) continue;
        ir_func = mx::IRFunction::from(*func_decl);
        if (ir_func) break;
      }
      if (ir_func) break;
    }
  }

  if (!ir_func) {
    LOG(ERROR) << "Could not find IR for function '" << FLAGS_entity_name
               << "'";
    return 1;
  }

  auto decl = ir_func->source_declaration();
  std::cout << "Interpreting IR for: "
            << (decl ? "decl" : "unknown")
            << " (kind=" << static_cast<unsigned>(ir_func->kind()) << ")\n";

  // Print summary.
  unsigned num_blocks = 0, num_insts = 0, num_objs = 0;
  for (auto b : ir_func->blocks()) {
    ++num_blocks;
    for (auto i : b.all_instructions()) { ++num_insts; (void)i; }
  }
  for (auto o : ir_func->objects()) { ++num_objs; (void)o; }
  std::cout << num_blocks << " blocks, " << num_insts << " instructions, "
            << num_objs << " objects\n";

  // Build zero-initialized arguments.
  using namespace mx::ir::interpret;
  std::vector<Value> args;
  if (auto fd = mx::FunctionDecl::from(*decl)) {
    for (auto p : fd->parameters()) {
      (void)p;
      args.push_back(make_int(0));
    }
  }
  std::cout << "Running with " << args.size()
            << " zero-initialized arguments...\n\n";

  // Resolve entity ID → IRFunction.
  FunctionResolver func_resolver =
      [&index](mx::RawEntityId eid) -> std::optional<mx::IRFunction> {
    auto entity = index.entity(mx::EntityId(eid));
    if (auto *decl = std::get_if<mx::Decl>(&entity)) {
      if (auto fd = mx::FunctionDecl::from(*decl)) {
        return mx::IRFunction::from(*fd);
      }
    }
    if (auto *stmt = std::get_if<mx::Stmt>(&entity)) {
      if (auto dre = mx::DeclRefExpr::from(*stmt)) {
        if (auto fd = mx::FunctionDecl::from(dre->declaration())) {
          return mx::IRFunction::from(*fd);
        }
      }
    }
    return std::nullopt;
  };

  // Resolve global variable entity ID → GlobalInfo.
  GlobalResolver global_resolver =
      [&index](mx::RawEntityId eid) -> std::optional<GlobalInfo> {
    auto entity = index.entity(mx::EntityId(eid));
    std::optional<mx::VarDecl> vd;
    if (auto *decl = std::get_if<mx::Decl>(&entity)) {
      vd = mx::VarDecl::from(*decl);
    } else if (auto *stmt = std::get_if<mx::Stmt>(&entity)) {
      if (auto dre = mx::DeclRefExpr::from(*stmt)) {
        vd = mx::VarDecl::from(dre->declaration());
      }
    }
    if (!vd) return std::nullopt;
    GlobalInfo info;
    info.canonical_eid = vd->id().Pack();
    auto ty = vd->type();
    if (auto bits = ty.size_in_bits())
      info.size = static_cast<uint32_t>((*bits + 7) / 8);
    if (auto al = ty.alignment())
      info.align = static_cast<uint32_t>(*al / 8);
    if (info.align == 0) info.align = 8;
    info.initializer = mx::IRFunction::from(*vd);
    return info;
  };

  // Run using the new policy-based interpreter.
  ConcreteMemory memory;
  ConcretePolicy policy(memory, std::move(func_resolver),
                        std::move(global_resolver));
  InterpreterState<Value> state;
  NoOpScheduler sched;

  policy.init_state(state, *ir_func, args);

  while (policy.step(state, sched, FLAGS_max_steps)) {}

  std::cout << "Interpreter finished after " << state.steps << " steps.\n";

  if (sched.result && sched.result->kind() == Continuation::COMPLETED) {
    const auto &ret = sched.result->return_value();
    if (auto *s = std::get_if<ScalarValue>(&ret)) {
      if (s->width == 4) {
        std::cout << "Return value: " << s->as_f32() << " (float)\n";
      } else {
        std::cout << "Return value: " << s->as_i64() << "\n";
      }
    } else if (auto *p = as_pointer(ret)) {
      std::cout << "Return value: ptr(" << concrete_address(*p) << ")\n";
    } else if (is_null(ret)) {
      std::cout << "Return value: null\n";
    } else {
      std::cout << "Return value: void/undef\n";
    }
  } else if (sched.result && sched.result->kind() == Continuation::ERRORED) {
    std::cerr << "Interpreter error (kind=" << static_cast<int>(sched.result->error())
              << ") after " << state.steps << " steps.\n";
    std::cout << "Return value: void/undef\n";
  } else {
    std::cerr << "Step budget exhausted after " << state.steps
              << " steps.\n";
    std::cout << "Return value: void/undef\n";
  }

  return 0;
}
