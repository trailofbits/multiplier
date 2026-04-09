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

// Extract offset from an entity ID for readable printing.
uint32_t OffsetOf(mx::EntityId eid) {
  auto vid = eid.Unpack();
  if (auto *p = std::get_if<mx::IRInstructionId>(&vid)) return p->offset;
  if (auto *p = std::get_if<mx::IRBlockId>(&vid)) return p->offset;
  if (auto *p = std::get_if<mx::IRObjectId>(&vid)) return p->offset;
  if (auto *p = std::get_if<mx::IRStructureId>(&vid)) return p->offset;
  if (auto *p = std::get_if<mx::IRFunctionId>(&vid)) return p->offset;
  return static_cast<uint32_t>(eid.Pack() & 0xFFFF);
}

// Truncate and clean a string for display.
std::string Truncate(std::string_view data, size_t max_len = 50) {
  std::string s(data.begin(), data.end());
  for (auto &c : s) { if (c == '\n' || c == '\r') c = ' '; }
  if (s.size() > max_len) s = s.substr(0, max_len - 3) + "...";
  return s;
}

// Print a single instruction (recursive for expression trees).
void PrintInstruction(std::ostream &os, const mx::IRInstruction &inst,
                      const std::string &indent, bool is_root) {
  auto op = inst.opcode();

  os << indent;
  if (is_root) os << ">> ";
  else os << "   ";

  os << "%" << OffsetOf(inst.id()) << " = ";

  // Opcode name.
  os << mx::ir::EnumeratorName(op);

  // Sub-opcode / extra info for grouped opcodes.
  if (auto ci = mx::ConstInst::from(inst)) {
    auto sub = ci->sub_opcode();
    os << "/" << mx::ir::EnumeratorName(sub);
    if (sub >= mx::ir::ConstOp::FLOAT32 && sub <= mx::ir::ConstOp::FLOAT64) {
      os << " " << ci->float_value();
    } else if (sub == mx::ir::ConstOp::NULL_PTR) {
      // no extra
    } else {
      os << " " << ci->signed_value();
    }
  } else if (auto mi = mx::MemoryInst::from(inst)) {
    auto sub = mi->sub_opcode();
    os << "/" << mx::ir::EnumeratorName(sub);
    if (mx::ir::IsBitAccess(sub)) {
      os << " off=" << mi->bit_offset() << " w=" << mi->bit_width();
    }
  } else if (auto ci = mx::CastInst::from(inst)) {
    os << "/" << mx::ir::EnumeratorName(ci->sub_opcode());
  } else if (auto ri = mx::ReadModifyWriteInst::from(inst)) {
    os << "(" << mx::ir::EnumeratorName(ri->underlying_op());
    if (ri->is_atomic()) os << " atomic";
    if (ri->is_big_endian()) os << " BE";
    os << " " << (ri->returns_new_value() ? "new" : "old");
    os << ")";
  } else if (auto bi = mx::BitwiseOpInst::from(inst)) {
    os << "/" << mx::ir::EnumeratorName(bi->sub_opcode());
  } else if (auto fi = mx::FloatOpInst::from(inst)) {
    os << "/" << mx::ir::EnumeratorName(fi->sub_opcode());
  } else if (auto ai = mx::AllocaInst::from(inst)) {
    os << "/" << mx::ir::EnumeratorName(ai->alloca_kind());
    os << " size=" << ai->size_bytes() << " align=" << ai->align_bytes();
  } else if (op == mx::ir::OpCode::PARAM_PTR) {
    if (auto pr = mx::ParamPtrInst::from(inst)) {
      os << " idx=" << pr->parameter_index();
    }
  } else if (op == mx::ir::OpCode::ENTER_SCOPE ||
             op == mx::ir::OpCode::EXIT_SCOPE) {
    mx::IRStructure scope;
    if (auto es = mx::EnterScopeInst::from(inst)) scope = es->scope();
    else if (auto es = mx::ExitScopeInst::from(inst)) scope = es->scope();
    if (scope.id() != mx::EntityId()) {
      os << " " << mx::ir::EnumeratorName(scope.kind());
    }
  } else if (op == mx::ir::OpCode::GEP_FIELD) {
    if (auto gi = mx::GEPFieldInst::from(inst)) {
      os << " offset=" << gi->byte_offset();
      auto fd = gi->field();
      os << " ." << fd.name();
    }
  } else if (op == mx::ir::OpCode::PTR_ADD) {
    if (auto pi = mx::PtrAddInst::from(inst)) {
      os << " elem_size=" << pi->element_size();
    }
  } else if (op == mx::ir::OpCode::CALL) {
    if (auto ci = mx::CallInst::from(inst)) {
      if (auto target = ci->target()) {
        os << " @" << target->name();
      } else if (ci->is_indirect()) {
        os << " indirect";
      }
    }
  } else if (op == mx::ir::OpCode::SWITCH) {
    if (auto si = mx::SwitchInst::from(inst)) {
      os << " cases=" << si->num_cases();
    }
  }

  // Operands.
  unsigned n = inst.num_operands();
  if (n > 0) {
    os << " [";
    for (unsigned i = 0; i < n; ++i) {
      if (i) os << ", ";
      auto operand = inst.nth_operand(i);
      os << "%" << OffsetOf(operand.id());
    }
    os << "]";
  }

  // Source provenance.
  if (auto src = inst.source_statement()) {
    auto data = src->tokens().data();
    if (!data.empty()) {
      os << "  // " << Truncate(data);
    }
  }

  os << "\n";
}

// Print a block.
void PrintBlock(std::ostream &os, const mx::IRBlock &block) {
  auto kind = block.kind();

  os << "  block_" << OffsetOf(block.id()) << " "
     << mx::ir::EnumeratorName(kind);

  // Predecessors.
  {
    bool first = true;
    for (auto pred : block.predecessors()) {
      if (first) { os << "  <- ["; first = false; }
      else os << ", ";
      os << "block_" << OffsetOf(pred.id());
    }
    if (!first) os << "]";
  }

  os << ":\n";

  // Top-level instructions (roots).
  for (auto inst : block.instructions()) {
    // Print sub-expressions first, then the root.
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
      os << "block_" << OffsetOf(succ.id());
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
    }
  }

  os << " (" << mx::ir::EnumeratorName(kind) << ") {\n";

  // Objects.
  os << "  objects:\n";
  for (auto obj : func.objects()) {
    os << "    obj_" << OffsetOf(obj.id())
       << " " << mx::ir::EnumeratorName(obj.kind())
       << " size=" << obj.size_bytes()
       << " align=" << obj.align_bytes();
    if (auto vd = obj.source_declaration()) {
      os << " (" << vd->name() << ")";
    }
    os << "\n";
  }

  // Structure tree.
  if (auto scope = func.body_scope()) {
    os << "  body_scope: " << mx::ir::EnumeratorName(scope->kind()) << "\n";
  }

  // Blocks in RPO.
  os << "\n  blocks:\n";
  auto entry = func.entry_block();
  PrintBlock(os, entry);

  for (auto block : func.blocks()) {
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

    if (auto *ir = std::get_if<mx::IRFunction>(&entity)) {
      PrintFunction(std::cout, *ir);
    } else if (auto *decl = std::get_if<mx::Decl>(&entity)) {
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
