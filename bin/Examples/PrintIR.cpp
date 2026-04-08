// Copyright (c) 2024-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Prints the IR for a named function in human-readable form.
// Usage: mx-print-ir --db DATABASE --entity_name FUNC_NAME [--all]
//
// With --all, prints IR for every function in the index.

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <sstream>
#include <string>

#include "Index.h"
#include <multiplier/AST.h>
#include <multiplier/Entity.h>
#include <multiplier/IR/InstructionKinds.h>
#include <multiplier/IR/StructureKinds.h>

DEFINE_uint64(entity_id, mx::kInvalidEntityId, "ID of the entity");
DEFINE_string(entity_name, "", "Name of the function to print IR for");
DEFINE_bool(all, false, "Print IR for all functions");

namespace {

// Format an entity ID as hex.
std::string Hex(mx::RawEntityId eid) {
  std::ostringstream ss;
  ss << "0x" << std::hex << eid;
  return ss.str();
}

// Print a single instruction.
void PrintInstruction(std::ostream &os, const mx::IRInstruction &inst,
                      const std::string &indent, bool is_root) {
  auto op = inst.opcode();
  auto eid = mx::EntityId(inst.id()).Pack();

  os << indent;
  if (is_root) os << ">> ";
  else os << "   ";

  os << "%" << (eid & 0xFFFF) << " = ";

  // Opcode name.
  os << static_cast<unsigned>(op);

  // Sub-opcode for grouped opcodes.
  if (op == mx::ir::OpCode::CONST) {
    if (auto ci = mx::ConstInst::from(inst)) {
      os << "(";
      auto sub = ci->sub_opcode();
      os << static_cast<unsigned>(sub);
      if (sub >= mx::ir::ConstOp::FLOAT32 && sub <= mx::ir::ConstOp::FLOAT64) {
        os << " " << ci->float_value();
      } else if (sub == mx::ir::ConstOp::NULL_PTR) {
        os << " null";
      } else {
        os << " " << ci->signed_value();
      }
      os << ")";
    }
  } else if (op == mx::ir::OpCode::MEMORY) {
    if (auto mi = mx::MemoryInst::from(inst)) {
      os << "(";
      auto sub = mi->sub_opcode();
      os << static_cast<unsigned>(sub);
      if (mx::ir::IsBitAccess(sub)) {
        os << " off=" << mi->bit_offset() << " w=" << mi->bit_width();
      }
      os << ")";
    }
  } else if (op == mx::ir::OpCode::CAST) {
    if (auto ci = mx::CastInst::from(inst)) {
      os << "(" << static_cast<unsigned>(ci->sub_opcode()) << ")";
    }
  } else if (op == mx::ir::OpCode::READ_MODIFY_WRITE) {
    if (auto ri = mx::ReadModifyWriteInst::from(inst)) {
      os << "(underlying=" << static_cast<unsigned>(ri->underlying_op());
      if (ri->is_atomic()) os << " atomic";
      if (ri->is_big_endian()) os << " BE";
      if (ri->returns_new_value()) os << " new";
      else os << " old";
      os << ")";
    }
  } else if (op == mx::ir::OpCode::BITWISE) {
    if (auto bi = mx::BitwiseOpInst::from(inst)) {
      os << "(" << static_cast<unsigned>(bi->sub_opcode()) << ")";
    }
  } else if (op == mx::ir::OpCode::FLOAT) {
    if (auto fi = mx::FloatOpInst::from(inst)) {
      os << "(" << static_cast<unsigned>(fi->sub_opcode()) << ")";
    }
  } else if (op == mx::ir::OpCode::PARAM_READ) {
    if (auto pr = mx::ParamReadInst::from(inst)) {
      os << " param" << pr->parameter_index();
    }
  } else if (op == mx::ir::OpCode::ALLOCA) {
    if (auto ai = mx::AllocaInst::from(inst)) {
      os << " size=" << ai->size_bytes() << " align=" << ai->align_bytes();
    }
  } else if (op == mx::ir::OpCode::ENTER_SCOPE) {
    if (auto es = mx::EnterScopeInst::from(inst)) {
      auto scope = es->scope();
      os << " scope_kind=" << static_cast<unsigned>(scope.kind());
    }
  } else if (op == mx::ir::OpCode::EXIT_SCOPE) {
    if (auto es = mx::ExitScopeInst::from(inst)) {
      auto scope = es->scope();
      os << " scope_kind=" << static_cast<unsigned>(scope.kind());
    }
  }

  // Operands.
  unsigned n = inst.num_operands();
  if (n > 0) {
    os << " [";
    for (unsigned i = 0; i < n; ++i) {
      if (i) os << ", ";
      auto operand = inst.nth_operand(i);
      os << "%" << (mx::EntityId(operand.id()).Pack() & 0xFFFF);
    }
    os << "]";
  }

  // Source provenance.
  if (auto src = inst.source_statement()) {
    auto toks = src->tokens();
    auto data = toks.data();
    if (!data.empty()) {
      // Truncate to first 40 chars.
      std::string s(data.begin(), data.end());
      if (s.size() > 40) s = s.substr(0, 37) + "...";
      // Replace newlines.
      for (auto &c : s) { if (c == '\n' || c == '\r') c = ' '; }
      os << "  // " << s;
    }
  }

  os << "\n";
}

// Print a block.
void PrintBlock(std::ostream &os, const mx::IRBlock &block) {
  auto kind = block.kind();
  auto eid = mx::EntityId(block.id()).Pack();

  os << "  block_" << (eid & 0xFFFF) << " ("
     << static_cast<unsigned>(kind) << ")";

  // Predecessors.
  {
    bool first = true;
    for (auto pred : block.predecessors()) {
      if (first) { os << "  <- ["; first = false; }
      else os << ", ";
      os << "block_" << (mx::EntityId(pred.id()).Pack() & 0xFFFF);
    }
    if (!first) os << "]";
  }

  os << ":\n";

  // Top-level instructions (roots).
  for (auto inst : block.instructions()) {
    // Print the full expression tree for this root.
    // First print sub-expressions, then the root.
    for (auto sub : inst.operands()) {
      PrintInstruction(os, sub, "      ", false);
    }
    PrintInstruction(os, inst, "    ", true);
  }

  // Successors.
  {
    bool first = true;
    for (auto succ : block.successors()) {
      if (first) { os << "    -> ["; first = false; }
      else os << ", ";
      os << "block_" << (mx::EntityId(succ.id()).Pack() & 0xFFFF);
    }
    if (!first) os << "]\n";
  }
}

// Print a function's IR.
void PrintFunction(std::ostream &os, const mx::IRFunction &func) {
  auto kind = func.kind();
  os << "function ";

  if (auto decl = func.source_declaration()) {
    if (auto nd = mx::NamedDecl::from(*decl)) {
      os << nd->name();
    } else {
      os << Hex(mx::EntityId(decl->id()).Pack());
    }
  }

  os << " (kind=" << static_cast<unsigned>(kind) << ")";
  os << " {\n";

  // Objects.
  os << "  objects:\n";
  for (auto obj : func.objects()) {
    os << "    obj_" << (mx::EntityId(obj.id()).Pack() & 0xFFFF)
       << " kind=" << static_cast<unsigned>(obj.kind())
       << " size=" << obj.size_bytes()
       << " align=" << obj.align_bytes();
    if (auto vd = obj.source_declaration()) {
      os << " (" << vd->name() << ")";
    }
    os << "\n";
  }

  // Structure tree.
  if (auto scope = func.body_scope()) {
    os << "  body_scope: kind=" << static_cast<unsigned>(scope->kind()) << "\n";
  }

  // Blocks in RPO.
  os << "\n  blocks:\n";
  // Also print entry block (FRAME) which may not be in RPO.
  auto entry = func.entry_block();
  PrintBlock(os, entry);

  for (auto block : func.blocks()) {
    // Skip if same as entry (already printed).
    if (mx::EntityId(block.id()).Pack() == mx::EntityId(entry.id()).Pack())
      continue;
    PrintBlock(os, block);
  }

  os << "}\n\n";
}

}  // namespace

int main(int argc, char *argv[]) {
  std::stringstream ss;
  ss << "Usage: " << argv[0]
     << " --db DATABASE [--entity_name NAME | --entity_id ID | --all]";
  google::SetUsageMessage(ss.str());
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);

  mx::Index index = InitExample(false);

  if (FLAGS_entity_id != mx::kInvalidEntityId) {
    auto entity = index.entity(FLAGS_entity_id);

    // If it's directly an IRFunction, print it.
    if (auto *ir = std::get_if<mx::IRFunction>(&entity)) {
      PrintFunction(std::cout, *ir);
    }
    // If it's a Decl, find its IR.
    else if (auto *decl = std::get_if<mx::Decl>(&entity)) {
      if (auto ir_var = decl->ir()) {
        if (auto *ir = std::get_if<mx::IRFunction>(&*ir_var)) {
          PrintFunction(std::cout, *ir);
        } else {
          LOG(ERROR) << "Entity " << FLAGS_entity_id << " has IR but not an IRFunction";
          return 1;
        }
      } else {
        LOG(ERROR) << "No IR for entity " << FLAGS_entity_id;
        return 1;
      }
    } else {
      LOG(ERROR) << "Entity " << FLAGS_entity_id << " is not a Decl or IRFunction";
      return 1;
    }
  } else if (FLAGS_all) {
    // Print IR for every function.
    for (auto frag : mx::Fragment::in(index)) {
      for (auto decl : mx::Decl::in(frag)) {
        auto func_decl = mx::FunctionDecl::from(decl);
        if (!func_decl) continue;
        auto ir = mx::IRFunction::from(*func_decl);
        if (!ir) continue;
        PrintFunction(std::cout, *ir);
      }
    }
  } else if (!FLAGS_entity_name.empty()) {
    bool found = false;
    for (auto frag : mx::Fragment::in(index)) {
      for (auto decl : mx::Decl::in(frag)) {
        auto func_decl = mx::FunctionDecl::from(decl);
        if (!func_decl) continue;
        if (std::string(func_decl->name()) != FLAGS_entity_name) continue;
        auto ir = mx::IRFunction::from(*func_decl);
        if (!ir) continue;
        PrintFunction(std::cout, *ir);
        found = true;
        break;
      }
      if (found) break;
    }
    if (!found) {
      LOG(ERROR) << "No IR found for '" << FLAGS_entity_name << "'";
      return 1;
    }
  } else {
    LOG(ERROR) << "Specify --entity_name or --all";
    return 1;
  }

  return 0;
}
