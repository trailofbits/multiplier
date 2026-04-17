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
#include <multiplier/IR/Interpret/ConcreteValueFactory.h>
#include <multiplier/IR/Interpret/ConcreteMemory.h>
#include <multiplier/IR/Interpret/ConcreteDriver.h>
#include <multiplier/IR/Interpret/Interpreter.h>

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
      args.push_back(MakeInt(0));
    }
  }
  std::cout << "Running with " << args.size()
            << " zero-initialized arguments...\n\n";

  // Create policy objects with function resolvers for interprocedural calls.
  ConcreteValueFactory factory;
  ConcreteMemory memory;

  // Resolve entity ID → IRFunction. Handles both FunctionDecl entity IDs
  // (direct calls) and DeclRefExpr entity IDs (indirect calls via FUNC_PTR).
  FunctionResolver func_resolver =
      [&index](mx::RawEntityId eid) -> std::optional<mx::IRFunction> {
    auto entity = index.entity(mx::EntityId(eid));

    if (auto *decl = std::get_if<mx::Decl>(&entity)) {
      if (auto fd = mx::FunctionDecl::from(*decl)) {
        return mx::IRFunction::from(*fd);
      }
      return std::nullopt;
    }

    if (auto *stmt = std::get_if<mx::Stmt>(&entity)) {
      if (auto dre = mx::DeclRefExpr::from(*stmt)) {
        if (auto fd = mx::FunctionDecl::from(dre->declaration())) {
          return mx::IRFunction::from(*fd);
        }
      }
      return std::nullopt;
    }

    return std::nullopt;
  };

  // Resolve global variable entity ID → GlobalInfo (size, initializer).
  GlobalResolver global_resolver =
      [&index](mx::RawEntityId eid) -> std::optional<GlobalInfo> {
    auto entity = index.entity(mx::EntityId(eid));

    // Get the VarDecl.
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
    if (auto bits = ty.size_in_bits()) {
      info.size = static_cast<uint32_t>((*bits + 7) / 8);
    }
    if (auto al = ty.alignment()) {
      info.align = static_cast<uint32_t>(*al / 8);
    }
    if (info.align == 0) info.align = 8;

    // Direct lookup: VarDecl → GLOBAL_INITIALIZER IRFunction.
    info.initializer = mx::IRFunction::from(*vd);
    return info;
  };

  ConcreteDriver driver(std::move(func_resolver), std::move(global_resolver));

  // Run the interpreter.
  InterpreterState state;
  InitState(state, memory, *ir_func, args);

  StepResult last_result{StepStatus::ERROR};
  while (true) {
    if (state.steps >= FLAGS_max_steps) {
      std::cerr << "Step budget exhausted after " << state.steps
                << " steps.\n";
      break;
    }
    last_result = Step(state, memory, factory, driver);
    if (last_result.status == StepStatus::COMPLETED) break;
    if (last_result.status == StepStatus::ERROR) {
      std::cerr << "Interpreter error after " << state.steps
                << " steps.\n";
      break;
    }
    if (last_result.status == StepStatus::SUSPENDED) {
      std::cerr << "Interpreter suspended (unexpected in concrete mode).\n";
      break;
    }
  }

  std::cout << "Interpreter finished after " << state.steps
            << " steps.\n";

  // Print the return value.
  const auto &ret = last_result.return_value;
  if (auto *s = std::get_if<ScalarValue>(&ret)) {
    if (s->width == 4) {
      std::cout << "Return value: " << s->as_f32() << " (float)\n";
    } else {
      std::cout << "Return value: " << s->as_i64() << "\n";
    }
  } else if (auto *p = AsPointer(ret)) {
    std::cout << "Return value: ptr(" << ConcreteAddress(*p) << ")\n";
  } else if (IsNull(ret)) {
    std::cout << "Return value: null\n";
  } else {
    std::cout << "Return value: void/undef\n";
  }

  return 0;
}
