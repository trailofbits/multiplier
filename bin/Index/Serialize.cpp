// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Serialize.h"

#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include "Serializer.h"

namespace indexer {

void EntitySerializer::SerializeCodeEntities(
    PendingFragment code, FragmentBuilder &builder) {
  serialized_entities.clear();
  code_id = code.fragment_id;
  next_pseudo_entity_offset = code.num_entities;
  entity_builder = builder.initEntities(
      code.num_entities + code.num_pseudo_entities);
  for (const pasta::Decl &decl : code.decls) {
    this->DeclVisitor::Accept(decl);
  }
}

void SerializeTemplateParameterList(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateParameterList &e) {
  b.setVal0(e.NumParameters());
  b.setVal1(e.NumRequiredParameters());
  b.setVal2(e.Depth());
  b.setVal3(e.HasUnexpandedParameterPack());
  b.setVal4(e.HasParameterPack());
  b.setVal5(es.EntityId(e.TemplateKeywordToken()));
  b.setVal6(es.EntityId(e.LeftAngleToken()));
  b.setVal7(es.EntityId(e.RightAngleToken()));
  if (auto r8 = e.TokenRange(); auto rs8 = r8.Size()) {
    b.setVal8(es.EntityId(r8[0]));
    b.setVal9(es.EntityId(r8[rs8 - 1u]));
  } else {
    b.setVal8(0);
    b.setVal9(0);
  }
  auto v10 = e.Parameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeTemplateArgument(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateArgument &e) {
  b.setVal11(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal3(e.IsNull());
  b.setVal4(e.IsDependent());
  b.setVal12(e.IsInstantiationDependent());
  b.setVal13(e.ContainsUnexpandedParameterPack());
  b.setVal14(e.IsPackExpansion());
  auto v5 = e.AsDeclaration();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal15(true);
    } else {
      b.setVal15(false);
    }
  } else {
    b.setVal15(false);
  }
}

void SerializeCXXBaseSpecifier(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXBaseSpecifier &e) {
  if (auto r5 = e.TokenRange(); auto rs5 = r5.Size()) {
    b.setVal5(es.EntityId(r5[0]));
    b.setVal6(es.EntityId(r5[rs5 - 1u]));
  } else {
    b.setVal5(0);
    b.setVal6(0);
  }
  b.setVal7(es.EntityId(e.BaseTypeToken()));
  b.setVal3(e.IsVirtual());
  b.setVal11(static_cast<unsigned short>(mx::FromPasta(e.BaseKind())));
  b.setVal4(e.IsPackExpansion());
  b.setVal12(e.ConstructorsAreInherited());
  auto v8 = e.Ellipsis();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal16(static_cast<unsigned short>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal17(static_cast<unsigned short>(mx::FromPasta(e.LexicalAccessSpecifier())));
}

void SerializeStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::Stmt &e) {
  b.setVal5(es.EntityId(e.BeginToken()));
  b.setVal6(es.EntityId(e.EndToken()));
  if (auto r7 = e.TokenRange(); auto rs7 = r7.Size()) {
    b.setVal7(es.EntityId(r7[0]));
    b.setVal8(es.EntityId(r7[rs7 - 1u]));
  } else {
    b.setVal7(0);
    b.setVal8(0);
  }
  b.setVal11(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
}

void SerializeSEHTryStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ExceptHandler()));
  b.setVal18(es.EntityId(e.FinallyHandler()));
  b.setVal3(e.IsCXXTry());
  b.setVal19(es.EntityId(e.TryBlock()));
  b.setVal20(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  b.setVal18(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  b.setVal18(es.EntityId(e.ExceptToken()));
}

void SerializeReturnStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.NRVOCandidate();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal3(true);
    } else {
      b.setVal3(false);
    }
  } else {
    b.setVal3(false);
  }
  b.setVal18(es.EntityId(e.ReturnToken()));
}

void SerializeObjCForCollectionStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ForToken()));
  b.setVal18(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
}

void SerializeObjCAtTryStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AtTryToken()));
  b.setVal18(es.EntityId(e.FinallyStatement()));
  auto v10 = e.CatchStatements();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeObjCAtThrowStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AtSynchronizedToken()));
  b.setVal18(es.EntityId(e.SynchBody()));
}

void SerializeObjCAtFinallyStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AtFinallyToken()));
}

void SerializeObjCAtCatchStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AtCatchToken()));
  b.setVal18(es.EntityId(e.CatchParameterDeclaration()));
  b.setVal19(es.EntityId(e.RParenToken()));
  b.setVal3(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal3(e.HasAssociatedStatement());
  b.setVal4(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal18(es.EntityId(e.TargetCallToken()));
}

void SerializeOMPDepobjDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDepobjDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCriticalDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPCriticalDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancellationPointDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPCancellationPointDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancelDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPCancelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPBarrierDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPBarrierDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPAtomicDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPAtomicDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.IsPostfixUpdate());
  b.setVal13(e.IsXLHSInRHSPart());
}

void SerializeOMPTeamsDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskyieldDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskyieldDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskwaitDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskwaitDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskgroupDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskgroupDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetExitDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetEnterDataDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetEnterDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDataDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSingleDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPSingleDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSectionsDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPSectionDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPScanDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMasterDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMaskedDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPLoopBasedDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPLoopBasedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPUnrollDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPTileDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPLoopDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPDistributeDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPInteropDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal18(es.EntityId(e.LoopVariableFunc()));
  b.setVal19(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.SemiToken()));
  b.setVal3(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.KeywordToken()));
  b.setVal18(es.EntityId(e.SubStatement()));
  b.setVal3(e.IsIfExists());
  b.setVal4(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ConstantTarget()));
  b.setVal18(es.EntityId(e.GotoToken()));
  b.setVal19(es.EntityId(e.StarToken()));
}

void SerializeIfStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConditionVariable();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal3(true);
    } else {
      b.setVal3(false);
    }
  } else {
    b.setVal3(false);
  }
  auto v18 = e.ConditionVariableDeclarationStatement();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal4(true);
    } else {
      b.setVal4(false);
    }
  } else {
    b.setVal4(false);
  }
  b.setVal19(es.EntityId(e.ElseToken()));
  b.setVal20(es.EntityId(e.IfToken()));
  b.setVal21(es.EntityId(e.LParenToken()));
  b.setVal22(es.EntityId(e.RParenToken()));
  b.setVal12(e.HasElseStorage());
  b.setVal13(e.HasInitializerStorage());
  b.setVal14(e.HasVariableStorage());
  b.setVal15(e.IsConstexpr());
  b.setVal23(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.GotoToken()));
  b.setVal18(es.EntityId(e.Label()));
  b.setVal19(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConditionVariable();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal3(true);
    } else {
      b.setVal3(false);
    }
  } else {
    b.setVal3(false);
  }
  auto v18 = e.ConditionVariableDeclarationStatement();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal4(true);
    } else {
      b.setVal4(false);
    }
  } else {
    b.setVal4(false);
  }
  b.setVal19(es.EntityId(e.ForToken()));
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeDoStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.DoToken()));
  b.setVal18(es.EntityId(e.RParenToken()));
  b.setVal19(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal3(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.PromiseDeclaration()));
  b.setVal3(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.KeywordToken()));
  b.setVal3(e.IsImplicit());
}

void SerializeContinueStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.LBracToken()));
  b.setVal18(es.EntityId(e.RBracToken()));
}

void SerializeCapturedStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal18(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal16(static_cast<unsigned short>(mx::FromPasta(e.CapturedRegionKind())));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.TryBlock()));
  b.setVal18(es.EntityId(e.TryToken()));
  auto v10 = e.Handlers();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeCXXForRangeStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.BeginStatement()));
  b.setVal18(es.EntityId(e.CoawaitToken()));
  b.setVal19(es.EntityId(e.ColonToken()));
  b.setVal20(es.EntityId(e.EndStatement()));
  b.setVal21(es.EntityId(e.ForToken()));
  b.setVal22(es.EntityId(e.LoopVariableStatement()));
  b.setVal24(es.EntityId(e.LoopVariable()));
  b.setVal25(es.EntityId(e.RParenToken()));
  b.setVal26(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.CatchToken()));
  b.setVal18(es.EntityId(e.ExceptionDeclaration()));
}

void SerializeBreakStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal27(e.GenerateAssemblyString());
  b.setVal9(es.EntityId(e.AssemblyToken()));
  b.setVal3(e.IsSimple());
  b.setVal4(e.IsVolatile());
  auto v28 = e.OutputConstraints();
  auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
  auto i28 = 0u;
  for (const auto &e28 : v28) {
    std::string se28(e28.data(), e28.size());
    sv28.set(i28, se28);
    ++i28;
  }
  auto v29 = e.InputConstraints();
  auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
  auto i29 = 0u;
  for (const auto &e29 : v29) {
    std::string se29(e29.data(), e29.size());
    sv29.set(i29, se29);
    ++i29;
  }
  auto v30 = e.Clobbers();
  auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
  auto i30 = 0u;
  for (const auto &e30 : v30) {
    std::string se30(e30.data(), e30.size());
    sv30.set(i30, se30);
    ++i30;
  }
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  auto v31 = e.AllConstraints();
  auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
  auto i31 = 0u;
  for (const auto &e31 : v31) {
    std::string se31(e31.data(), e31.size());
    sv31.set(i31, se31);
    ++i31;
  }
  auto v32 = e.AssemblyString();
  std::string s32(v32.data(), v32.size());
  b.setVal32(s32);
  b.setVal18(es.EntityId(e.LBraceToken()));
  b.setVal12(e.HasBraces());
}

void SerializeGCCAsmStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal18(es.EntityId(e.AssemblyString()));
  b.setVal19(es.EntityId(e.RParenToken()));
  b.setVal12(e.IsAssemblyGoto());
  auto v10 = e.Labels();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v33 = e.OutputConstraintLiterals();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  auto v31 = e.OutputNames();
  auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
  auto i31 = 0u;
  for (const auto &e31 : v31) {
    std::string se31(e31.data(), e31.size());
    sv31.set(i31, se31);
    ++i31;
  }
  auto v34 = e.InputConstraintLiterals();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const auto &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
  auto v35 = e.InputNames();
  auto sv35 = b.initVal35(static_cast<unsigned>(v35.size()));
  auto i35 = 0u;
  for (const auto &e35 : v35) {
    std::string se35(e35.data(), e35.size());
    sv35.set(i35, se35);
    ++i35;
  }
  auto v36 = e.ClobberStringLiterals();
  auto sv36 = b.initVal36(static_cast<unsigned>(v36.size()));
  auto i36 = 0u;
  for (const auto &e36 : v36) {
    sv36.set(i36, es.EntityId(e36));
    ++i36;
  }
  auto v37 = e.LabelExpressions();
  auto sv37 = b.initVal37(static_cast<unsigned>(v37.size()));
  auto i37 = 0u;
  for (const auto &e37 : v37) {
    sv37.set(i37, es.EntityId(e37));
    ++i37;
  }
  auto v38 = e.LabelNames();
  auto sv38 = b.initVal38(static_cast<unsigned>(v38.size()));
  auto i38 = 0u;
  for (const auto &e38 : v38) {
    std::string se38(e38.data(), e38.size());
    sv38.set(i38, se38);
    ++i38;
  }
}

void SerializeWhileStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConditionVariable();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal3(true);
    } else {
      b.setVal3(false);
    }
  } else {
    b.setVal3(false);
  }
  auto v18 = e.ConditionVariableDeclarationStatement();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal4(true);
    } else {
      b.setVal4(false);
    }
  } else {
    b.setVal4(false);
  }
  b.setVal19(es.EntityId(e.LParenToken()));
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal21(es.EntityId(e.WhileToken()));
  b.setVal12(e.HasVariableStorage());
}

void SerializeValueStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
}

void SerializeLabelStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal9(es.EntityId(e.Declaration()));
  b.setVal18(es.EntityId(e.IdentifierToken()));
  auto v27 = e.Name();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal3(e.IsSideEntry());
}

void SerializeExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal3(e.HasSideEffects());
  b.setVal4(e.ContainsErrors());
  b.setVal12(e.ContainsUnexpandedParameterPack());
  b.setVal9(es.EntityId(e.ExpressionToken()));
  auto v18 = e.ObjCProperty();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal16(static_cast<unsigned short>(mx::FromPasta(e.ObjectKind())));
  auto v19 = e.SourceBitField();
  if (v19) {
    if (auto id19 = es.EntityId(v19.value())) {
      b.setVal19(id19);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  b.setVal17(static_cast<unsigned short>(mx::FromPasta(e.ValueKind())));
  b.setVal15(e.HasNonTrivialCall());
  b.setVal23(e.IsDefaultArgument());
  b.setVal39(e.IsGLValue());
  b.setVal40(e.IsImplicitCXXThis());
  b.setVal41(e.IsInstantiationDependent());
  b.setVal42(e.IsKnownToHaveBooleanValue());
  b.setVal43(e.IsLValue());
  b.setVal44(e.IsOBJCGCCandidate());
  b.setVal45(e.IsObjCSelfExpression());
  b.setVal46(e.IsOrdinaryOrBitFieldObject());
  b.setVal47(e.IsPRValue());
  b.setVal48(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal49(e.IsTypeDependent());
  b.setVal50(e.IsValueDependent());
  b.setVal51(e.IsXValue());
  b.setVal52(e.RefersToBitField());
  b.setVal53(e.RefersToGlobalRegisterVariable());
  b.setVal54(e.RefersToMatrixElement());
  b.setVal55(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r20 = e.DesignatorsSourceRange(); auto rs20 = r20.Size()) {
    b.setVal20(es.EntityId(r20[0]));
    b.setVal21(es.EntityId(r20[rs20 - 1u]));
  } else {
    b.setVal20(0);
    b.setVal21(0);
  }
  b.setVal22(es.EntityId(e.EqualOrColonToken()));
  b.setVal56(e.IsDirectInitializer());
  b.setVal57(e.UsesGNUSyntax());
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LAngleToken()));
  b.setVal21(es.EntityId(e.RAngleToken()));
  b.setVal22(es.EntityId(e.TemplateKeywordToken()));
  b.setVal56(e.HasExplicitTemplateArguments());
  b.setVal57(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.KeywordToken()));
  b.setVal21(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal21(es.EntityId(e.FoundDeclaration()));
  b.setVal22(es.EntityId(e.LAngleToken()));
  b.setVal24(es.EntityId(e.RAngleToken()));
  b.setVal25(es.EntityId(e.TemplateKeywordToken()));
  b.setVal56(e.HadMultipleCandidates());
  b.setVal57(e.HasExplicitTemplateArguments());
  b.setVal58(e.HasQualifier());
  b.setVal59(e.HasTemplateKWAndArgumentsInfo());
  b.setVal60(e.HasTemplateKeyword());
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal62(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.KeywordToken()));
  b.setVal21(es.EntityId(e.OpaqueValue()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal56(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeConceptSpecializationExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  auto v63 = e.TemplateArguments();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    auto o63 = es.next_pseudo_entity_offset++;
    sv63.set(i63, o63);
    SerializeTemplateArgument(es, es.entity_builder[o63], e63);
    ++i63;
  }
  b.setVal56(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal56(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsConditionDependent());
  b.setVal57(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.CastKind())));
  auto v27 = e.CastKindName();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  auto v20 = e.ConversionFunction();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal56(true);
    } else {
      b.setVal56(false);
    }
  } else {
    b.setVal56(false);
  }
  auto v21 = e.TargetUnionField();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setVal21(id21);
      b.setVal57(true);
    } else {
      b.setVal57(false);
    }
  } else {
    b.setVal57(false);
  }
  b.setVal58(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal59(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r22 = e.AngleBrackets(); auto rs22 = r22.Size()) {
    b.setVal22(es.EntityId(r22[0]));
    b.setVal24(es.EntityId(r22[rs22 - 1u]));
  } else {
    b.setVal22(0);
    b.setVal24(0);
  }
  auto v32 = e.CastName();
  std::string s32(v32.data(), v32.size());
  b.setVal32(s32);
  b.setVal25(es.EntityId(e.OperatorToken()));
  b.setVal26(es.EntityId(e.RParenToken()));
}

void SerializeCXXDynamicCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal59(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXConstCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXAddrspaceCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXAddrspaceCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXStaticCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXStaticCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXReinterpretCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXReinterpretCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXFunctionalCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXFunctionalCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal22(es.EntityId(e.LParenToken()));
  b.setVal24(es.EntityId(e.RParenToken()));
  b.setVal59(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal22(es.EntityId(e.LParenToken()));
  b.setVal24(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal22(es.EntityId(e.BridgeKeywordToken()));
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.BridgeKind())));
  auto v32 = e.BridgeKindName();
  std::string s32(v32.data(), v32.size());
  b.setVal32(s32);
  b.setVal24(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ADLCallKind())));
  auto v20 = e.DirectCallee();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal56(true);
    } else {
      b.setVal56(false);
    }
  } else {
    b.setVal56(false);
  }
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal57(e.HasStoredFPFeatures());
  b.setVal58(e.HasUnusedResultAttribute());
  b.setVal59(e.IsBuiltinAssumeFalse());
  b.setVal60(e.IsCallToStdMove());
  b.setVal62(e.IsUnevaluatedBuiltinCall());
  b.setVal65(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal22(es.EntityId(e.OperatorToken()));
  b.setVal66(e.IsAssignmentOperation());
  b.setVal67(e.IsComparisonOperation());
  b.setVal68(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal22(es.EntityId(e.MethodDeclaration()));
  b.setVal24(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal22(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal22(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.GuidDeclaration()));
  b.setVal56(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.IsMostDerived());
  b.setVal57(e.IsPotentiallyEvaluated());
  b.setVal58(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ThrowToken()));
  b.setVal56(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.RParenToken()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v27 = e.OpcodeString();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal56(e.IsAssignmentOperation());
  b.setVal57(e.IsComparisonOperation());
  b.setVal58(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ColonColonToken()));
  b.setVal21(es.EntityId(e.DestroyedTypeToken()));
  b.setVal22(es.EntityId(e.OperatorToken()));
  b.setVal24(es.EntityId(e.TildeToken()));
  b.setVal56(e.HasQualifier());
  b.setVal57(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.DoesUsualArrayDeleteWantSize());
  b.setVal20(es.EntityId(e.ConstructExpression()));
  if (auto r21 = e.DirectInitializerRange(); auto rs21 = r21.Size()) {
    b.setVal21(es.EntityId(r21[0]));
    b.setVal22(es.EntityId(r21[rs21 - 1u]));
  } else {
    b.setVal21(0);
    b.setVal22(0);
  }
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.InitializationStyle())));
  b.setVal24(es.EntityId(e.OperatorDelete()));
  b.setVal25(es.EntityId(e.OperatorNew()));
  if (auto r26 = e.TypeIdParentheses(); auto rs26 = r26.Size()) {
    b.setVal26(es.EntityId(r26[0]));
    b.setVal69(es.EntityId(r26[rs26 - 1u]));
  } else {
    b.setVal26(0);
    b.setVal69(0);
  }
  b.setVal57(e.HasInitializer());
  b.setVal58(e.IsArray());
  b.setVal59(e.IsGlobalNew());
  b.setVal60(e.IsParenthesisTypeId());
  b.setVal62(e.PassAlignment());
  b.setVal65(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.ConstructsVirtualBase());
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal20(es.EntityId(e.Constructor()));
  b.setVal21(es.EntityId(e.Token()));
  b.setVal57(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Callee()));
  b.setVal21(es.EntityId(e.EllipsisToken()));
  b.setVal22(es.EntityId(e.LParenToken()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal24(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsLeftFold());
  b.setVal57(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.FirstQualifierFoundInScope()));
  b.setVal21(es.EntityId(e.LAngleToken()));
  b.setVal22(es.EntityId(e.MemberToken()));
  b.setVal24(es.EntityId(e.OperatorToken()));
  b.setVal25(es.EntityId(e.RAngleToken()));
  b.setVal26(es.EntityId(e.TemplateKeywordToken()));
  b.setVal56(e.HasExplicitTemplateArguments());
  b.setVal57(e.HasTemplateKeyword());
  b.setVal58(e.IsArrow());
  b.setVal59(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.DoesUsualArrayDeleteWantSize());
  b.setVal20(es.EntityId(e.OperatorDelete()));
  b.setVal57(e.IsArrayForm());
  b.setVal58(e.IsArrayFormAsWritten());
  b.setVal59(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Field()));
  b.setVal21(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Parameter()));
  b.setVal21(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal20(es.EntityId(e.Constructor()));
  b.setVal21(es.EntityId(e.Token()));
  if (auto r22 = e.ParenthesisOrBraceRange(); auto rs22 = r22.Size()) {
    b.setVal22(es.EntityId(r22[0]));
    b.setVal24(es.EntityId(r22[rs22 - 1u]));
  } else {
    b.setVal22(0);
    b.setVal24(0);
  }
  b.setVal56(e.HadMultipleCandidates());
  b.setVal57(e.IsElidable());
  b.setVal58(e.IsListInitialization());
  b.setVal59(e.IsStdInitializerListInitialization());
  b.setVal60(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BlockDeclaration()));
  b.setVal21(es.EntityId(e.CaretToken()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v27 = e.OpcodeString();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal56(e.HasStoredFPFeatures());
  b.setVal57(e.IsAdditiveOperation());
  b.setVal58(e.IsAssignmentOperation());
  b.setVal59(e.IsBitwiseOperation());
  b.setVal60(e.IsCommaOperation());
  b.setVal62(e.IsComparisonOperation());
  b.setVal65(e.IsCompoundAssignmentOperation());
  b.setVal66(e.IsEqualityOperation());
  b.setVal67(e.IsLogicalOperation());
  b.setVal68(e.IsMultiplicativeOperation());
  b.setVal70(e.IsPointerMemoryOperation());
  b.setVal71(e.IsRelationalOperation());
  b.setVal72(e.IsShiftAssignOperation());
  b.setVal73(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Operation())));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsCmpXChg());
  b.setVal57(e.IsOpenCL());
  b.setVal58(e.IsVolatile());
}

void SerializeAsTypeExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.RBracketToken()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.CommonExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AmpAmpToken()));
  b.setVal21(es.EntityId(e.Label()));
  b.setVal22(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ColonToken()));
  b.setVal21(es.EntityId(e.QuestionToken()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal22(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.CanOverflow());
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal57(e.HasStoredFPFeatures());
  b.setVal58(e.IsArithmeticOperation());
  b.setVal59(e.IsDecrementOperation());
  b.setVal60(e.IsIncrementDecrementOperation());
  b.setVal62(e.IsIncrementOperation());
  b.setVal65(e.IsPostfix());
  b.setVal66(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal56(e.Value());
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ParameterPack()));
  b.setVal21(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.NameToken()));
  b.setVal21(es.EntityId(e.Parameter()));
  b.setVal56(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.ContainsNonAscii());
  b.setVal57(e.ContainsNonAsciiOrNull());
  auto v27 = e.Bytes();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  auto v32 = e.String();
  std::string s32(v32.data(), v32.size());
  b.setVal32(s32);
  b.setVal58(e.IsAscii());
  b.setVal59(e.IsPascal());
  b.setVal60(e.IsUTF16());
  b.setVal62(e.IsUTF32());
  b.setVal65(e.IsUTF8());
  b.setVal66(e.IsWide());
}

void SerializeStmtExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal22(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v27 = e.BuiltinString();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.IsIntType());
  b.setVal57(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal21(es.EntityId(e.Pack()));
  b.setVal22(es.EntityId(e.PackToken()));
  auto v63 = e.PartialArguments();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    auto o63 = es.next_pseudo_entity_offset++;
    sv63.set(i63, o63);
    SerializeTemplateArgument(es, es.entity_builder[o63], e63);
    ++i63;
  }
  b.setVal24(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BuiltinToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal27(e.ComputeName());
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.Token()));
  b.setVal22(es.EntityId(e.RParenToken()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Body()));
  auto v10 = e.LocalParameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  b.setVal21(es.EntityId(e.RBraceToken()));
  b.setVal22(es.EntityId(e.RequiresKWToken()));
  b.setVal56(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.FunctionName()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  auto v27 = e.IdentifierKindName();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal21(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeParenExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParen()));
  b.setVal21(es.EntityId(e.RParen()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.EllipsisToken()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LAngleToken()));
  b.setVal21(es.EntityId(e.NameToken()));
  b.setVal22(es.EntityId(e.NamingClass()));
  b.setVal24(es.EntityId(e.RAngleToken()));
  b.setVal25(es.EntityId(e.TemplateKeywordToken()));
  b.setVal56(e.HasExplicitTemplateArguments());
  b.setVal57(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal26(es.EntityId(e.MemberToken()));
  b.setVal69(es.EntityId(e.OperatorToken()));
  b.setVal58(e.HasUnresolvedUsing());
  b.setVal59(e.IsArrow());
  b.setVal60(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal58(e.IsOverloaded());
  b.setVal59(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal21(es.EntityId(e.RBracket()));
  b.setVal56(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.Protocol()));
  b.setVal22(es.EntityId(e.ProtocolIdToken()));
  b.setVal24(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ClassReceiver()));
  b.setVal21(es.EntityId(e.ExplicitProperty()));
  b.setVal22(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal24(es.EntityId(e.ImplicitPropertySetter()));
  b.setVal25(es.EntityId(e.Token()));
  b.setVal26(es.EntityId(e.ReceiverToken()));
  b.setVal56(e.IsClassReceiver());
  b.setVal57(e.IsExplicitProperty());
  b.setVal58(e.IsImplicitProperty());
  b.setVal59(e.IsMessagingGetter());
  b.setVal60(e.IsMessagingSetter());
  b.setVal62(e.IsObjectReceiver());
  b.setVal65(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LeftToken()));
  b.setVal21(es.EntityId(e.MethodDeclaration()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal22(es.EntityId(e.ReceiverInterface()));
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.ReceiverKind())));
  if (auto r24 = e.ReceiverRange(); auto rs24 = r24.Size()) {
    b.setVal24(es.EntityId(r24[0]));
    b.setVal25(es.EntityId(r24[rs24 - 1u]));
  } else {
    b.setVal24(0);
    b.setVal25(0);
  }
  b.setVal26(es.EntityId(e.RightToken()));
  b.setVal69(es.EntityId(e.SelectorStartToken()));
  b.setVal74(es.EntityId(e.SuperToken()));
  b.setVal56(e.IsClassMessage());
  b.setVal57(e.IsDelegateInitializerCall());
  b.setVal58(e.IsImplicit());
  b.setVal59(e.IsInstanceMessage());
  auto v10 = e.SelectorTokens();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal21(es.EntityId(e.Token()));
  b.setVal22(es.EntityId(e.OperationToken()));
  b.setVal56(e.IsArrow());
  b.setVal57(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.BaseTokenEnd()));
  b.setVal21(es.EntityId(e.IsaMemberToken()));
  b.setVal22(es.EntityId(e.OperationToken()));
  b.setVal56(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.BoxingMethod()));
  b.setVal56(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ArrayWithObjectsMethod()));
}

void SerializeOMPIteratorExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.IteratorKwToken()));
  b.setVal21(es.EntityId(e.LParenToken()));
  b.setVal22(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ColonTokenFirst()));
  b.setVal21(es.EntityId(e.ColonTokenSecond()));
  b.setVal22(es.EntityId(e.RBracketToken()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.LAngleToken()));
  b.setVal21(es.EntityId(e.MemberDeclaration()));
  b.setVal22(es.EntityId(e.MemberToken()));
  b.setVal24(es.EntityId(e.OperatorToken()));
  b.setVal25(es.EntityId(e.RAngleToken()));
  b.setVal26(es.EntityId(e.TemplateKeywordToken()));
  b.setVal56(e.HadMultipleCandidates());
  b.setVal57(e.HasExplicitTemplateArguments());
  b.setVal58(e.HasQualifier());
  b.setVal59(e.HasTemplateKeyword());
  b.setVal60(e.IsArrow());
  b.setVal62(e.IsImplicitAccess());
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.RBracketToken()));
  b.setVal56(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ExtendingDeclaration()));
  b.setVal21(es.EntityId(e.LifetimeExtendedTemporaryDeclaration()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal56(e.IsBoundToLvalueReference());
  b.setVal57(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.MemberToken()));
  b.setVal21(es.EntityId(e.PropertyDeclaration()));
  b.setVal56(e.IsArrow());
  b.setVal57(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.CallOperator()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.CaptureDefault())));
  b.setVal21(es.EntityId(e.CaptureDefaultToken()));
  b.setVal22(es.EntityId(e.CompoundStatementBody()));
  auto v10 = e.ExplicitTemplateParameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  if (auto r24 = e.IntroducerRange(); auto rs24 = r24.Size()) {
    b.setVal24(es.EntityId(r24[0]));
    b.setVal25(es.EntityId(r24[rs24 - 1u]));
  } else {
    b.setVal24(0);
    b.setVal25(0);
  }
  b.setVal26(es.EntityId(e.LambdaClass()));
  auto v0 = e.TemplateParameterList();
  if (v0) {
    auto o0 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.entity_builder[o0], v0.value());
    b.setVal0(o0);
    b.setVal56(true);
  } else {
    b.setVal56(false);
  }
  b.setVal57(e.HasExplicitParameters());
  b.setVal58(e.HasExplicitResultType());
  b.setVal59(e.IsGenericLambda());
  b.setVal60(e.IsMutable());
}

void SerializeIntegerLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v20 = e.InitializedFieldInUnion();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal56(true);
    } else {
      b.setVal56(false);
    }
  } else {
    b.setVal56(false);
  }
  b.setVal21(es.EntityId(e.LBraceToken()));
  b.setVal22(es.EntityId(e.RBraceToken()));
  auto v24 = e.SemanticForm();
  if (v24) {
    if (auto id24 = es.EntityId(v24.value())) {
      b.setVal24(id24);
      b.setVal57(true);
    } else {
      b.setVal57(false);
    }
  } else {
    b.setVal57(false);
  }
  auto v25 = e.SyntacticForm();
  if (v25) {
    if (auto id25 = es.EntityId(v25.value())) {
      b.setVal25(id25);
      b.setVal58(true);
    } else {
      b.setVal58(false);
    }
  } else {
    b.setVal58(false);
  }
  b.setVal59(e.HadArrayRangeDesignator());
  b.setVal60(e.HasArrayFiller());
  b.setVal62(e.IsExplicit());
  b.setVal65(e.IsSemanticForm());
  b.setVal66(e.IsStringLiteralInitializer());
  b.setVal67(e.IsSyntacticForm());
  b.setVal68(e.IsTransparent());
}

void SerializeImplicitValueInitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
}

void SerializeGenericSelectionExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.DefaultToken()));
  b.setVal21(es.EntityId(e.GenericToken()));
  b.setVal22(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.ParameterPack()));
  b.setVal21(es.EntityId(e.ParameterPackToken()));
  auto v10 = e.Expansions();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal56(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal56(e.HasAPValueResult());
  b.setVal57(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
  b.setVal56(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal20(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal56(e.ContainsDuplicateElements());
  b.setVal20(es.EntityId(e.AccessorToken()));
  b.setVal57(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal56(e.Value());
}

void SerializeAttributedStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal9(es.EntityId(e.AttributeToken()));
}

void SerializeSwitchStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConditionVariable();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal3(true);
    } else {
      b.setVal3(false);
    }
  } else {
    b.setVal3(false);
  }
  auto v18 = e.ConditionVariableDeclarationStatement();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal4(true);
    } else {
      b.setVal4(false);
    }
  } else {
    b.setVal4(false);
  }
  b.setVal19(es.EntityId(e.LParenToken()));
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal21(es.EntityId(e.SwitchToken()));
  b.setVal12(e.HasInitializerStorage());
  b.setVal13(e.HasVariableStorage());
  b.setVal14(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ColonToken()));
  b.setVal18(es.EntityId(e.KeywordToken()));
}

void SerializeDefaultStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal19(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal3(e.CaseStatementIsGNURange());
  b.setVal19(es.EntityId(e.CaseToken()));
  b.setVal20(es.EntityId(e.EllipsisToken()));
}

void SerializeDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::Decl &e) {
  b.setVal11(static_cast<unsigned short>(mx::FromPasta(e.Access())));
  b.setVal16(static_cast<unsigned short>(mx::FromPasta(e.AccessUnsafe())));
  b.setVal17(static_cast<unsigned short>(mx::FromPasta(e.Availability())));
  b.setVal5(es.EntityId(e.BeginToken()));
  b.setVal6(es.EntityId(e.BodyRBrace()));
  auto v0 = e.DescribedTemplateParameters();
  if (v0) {
    auto o0 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.entity_builder[o0], v0.value());
    b.setVal0(o0);
    b.setVal3(true);
  } else {
    b.setVal3(false);
  }
  b.setVal7(es.EntityId(e.EndToken()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal64(static_cast<unsigned short>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setVal4(e.HasAttributes());
  b.setVal12(e.HasDefiningAttribute());
  b.setVal13(e.HasOwningModule());
  b.setVal14(e.HasTagIdentifierNamespace());
  b.setVal15(e.IsCanonicalDeclaration());
  b.setVal23(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal39(e.IsDeprecated());
  b.setVal40(e.IsFirstDeclaration());
  b.setVal41(e.IsFunctionOrFunctionTemplate());
  b.setVal42(e.IsImplicit());
  b.setVal43(e.IsInAnonymousNamespace());
  b.setVal44(e.IsInLocalScopeForInstantiation());
  b.setVal45(e.IsInStdNamespace());
  b.setVal46(e.IsInvalidDeclaration());
  b.setVal47(e.IsModulePrivate());
  b.setVal48(e.IsOutOfLine());
  b.setVal49(e.IsParameterPack());
  b.setVal50(e.IsReferenced());
  b.setVal51(e.IsTemplateDeclaration());
  b.setVal52(e.IsTemplateParameter());
  b.setVal53(e.IsTemplateParameterPack());
  b.setVal54(e.IsTemplated());
  b.setVal55(e.IsThisDeclarationReferenced());
  b.setVal56(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal57(e.IsUnavailable());
  b.setVal58(e.IsUnconditionallyVisible());
  b.setVal59(e.IsUsed());
  b.setVal60(e.IsWeakImported());
  b.setVal75(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal8(es.EntityId(e.Token()));
  if (auto r9 = e.TokenRange(); auto rs9 = r9.Size()) {
    b.setVal9(es.EntityId(r9[0]));
    b.setVal18(es.EntityId(r9[rs9 - 1u]));
  } else {
    b.setVal9(0);
    b.setVal18(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.Specialization()));
  b.setVal62(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CapturedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.ContextParameter()));
  b.setVal62(e.IsNothrow());
  auto v10 = e.Parameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  pasta::DeclContext dc33(e);
  auto v33 = dc33.AlreadyLoadedDeclarations();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const pasta::Decl &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BlockDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal62(e.BlockMissingReturnType());
  b.setVal65(e.CanAvoidCopyToHeap());
  b.setVal66(e.CapturesCXXThis());
  b.setVal67(e.DoesNotEscape());
  b.setVal19(es.EntityId(e.CaretToken()));
  b.setVal20(es.EntityId(e.CompoundBody()));
  b.setVal68(e.HasCaptures());
  b.setVal70(e.IsConversionFromLambda());
  b.setVal71(e.IsVariadic());
  auto v10 = e.Parameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v33 = e.ParameterDeclarations();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  pasta::DeclContext dc34(e);
  auto v34 = dc34.AlreadyLoadedDeclarations();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const pasta::Decl &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::AccessSpecDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.AccessSpecifierToken()));
  b.setVal20(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPRequiresDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPRequiresDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPAllocateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TranslationUnitDecl &e) {
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::StaticAssertDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.Message()));
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal62(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::RequiresExprBodyDecl &e) {
  SerializeDecl(es, b, e);
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  SerializeDecl(es, b, e);
  auto v27 = e.Name();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  auto v32 = e.Value();
  std::string s32(v32.data(), v32.size());
  b.setVal32(s32);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::PragmaCommentDecl &e) {
  SerializeDecl(es, b, e);
  auto v27 = e.Argument();
  std::string s27(v27.data(), v27.size());
  b.setVal27(s27);
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal20(es.EntityId(e.PropertyDeclaration()));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal21(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal22(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal24(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal62(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NamedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.FormalLinkage())));
  b.setVal77(static_cast<unsigned short>(mx::FromPasta(e.LinkageInternal())));
  b.setVal27(e.Name());
  b.setVal78(static_cast<unsigned short>(mx::FromPasta(e.ObjCFStringFormattingFamily())));
  b.setVal32(e.QualifiedNameAsString());
  b.setVal19(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.Visibility())));
  b.setVal62(e.HasExternalFormalLinkage());
  b.setVal65(e.HasLinkage());
  b.setVal66(e.HasLinkageBeenComputed());
  b.setVal67(e.IsCXXClassMember());
  b.setVal68(e.IsCXXInstanceMember());
  b.setVal70(e.IsExternallyDeclarable());
  b.setVal71(e.IsExternallyVisible());
  b.setVal72(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::LabelDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v80 = e.MSAssemblyLabel();
  std::string s80(v80.data(), v80.size());
  b.setVal80(s80);
  b.setVal20(es.EntityId(e.Statement()));
  b.setVal73(e.IsGnuLocal());
  b.setVal81(e.IsMSAssemblyLabel());
  b.setVal82(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BaseUsingDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v10 = e.Shadows();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UsingEnumDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal20(es.EntityId(e.EnumDeclaration()));
  b.setVal21(es.EntityId(e.EnumToken()));
  b.setVal22(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UsingDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal20(es.EntityId(e.UsingToken()));
  b.setVal73(e.HasTypename());
  b.setVal81(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ValueDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal73(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal20(es.EntityId(e.EllipsisToken()));
  b.setVal21(es.EntityId(e.UsingToken()));
  b.setVal81(e.IsAccessDeclaration());
  b.setVal82(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateParamObjectDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.InitializerKind())));
  b.setVal20(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeMSGuidDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSGuidDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::IndirectFieldDecl &e) {
  SerializeValueDecl(es, b, e);
  auto v10 = e.Chain();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v20 = e.AnonymousField();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  auto v21 = e.VariableDeclaration();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setVal21(id21);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::EnumConstantDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DeclaratorDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal20(es.EntityId(e.InnerTokenStart()));
  b.setVal21(es.EntityId(e.OuterTokenStart()));
  b.setVal22(es.EntityId(e.TypeSpecEndToken()));
  b.setVal24(es.EntityId(e.TypeSpecStartToken()));
  auto v63 = e.TemplateParameterLists();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    auto o63 = es.next_pseudo_entity_offset++;
    sv63.set(i63, o63);
    SerializeTemplateParameterList(es, es.entity_builder[o63], e63);
    ++i63;
  }
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::VarDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  auto v25 = e.ActingDefinition();
  if (v25) {
    if (auto id25 = es.EntityId(v25.value())) {
      b.setVal25(id25);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.InitializerStyle())));
  auto v26 = e.InitializingDeclaration();
  if (v26) {
    if (auto id26 = es.EntityId(v26.value())) {
      b.setVal26(id26);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  auto v69 = e.InstantiatedFromStaticDataMember();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal74(es.EntityId(e.PointOfInstantiation()));
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal88(static_cast<unsigned short>(mx::FromPasta(e.TLSKind())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.TSCSpec())));
  auto v90 = e.TemplateInstantiationPattern();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal94(e.HasConstantInitialization());
  b.setVal95(e.HasDependentAlignment());
  b.setVal96(e.HasExternalStorage());
  b.setVal97(e.HasGlobalStorage());
  b.setVal98(e.HasInitializer());
  b.setVal99(e.HasLocalStorage());
  b.setVal100(e.IsARCPseudoStrong());
  b.setVal101(e.IsCXXForRangeDeclaration());
  b.setVal102(e.IsConstexpr());
  b.setVal103(e.IsDirectInitializer());
  b.setVal104(e.IsEscapingByref());
  b.setVal105(e.IsExceptionVariable());
  b.setVal106(e.IsExternC());
  b.setVal107(e.IsFileVariableDeclaration());
  b.setVal108(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal109(e.IsInExternCContext());
  b.setVal110(e.IsInExternCXXContext());
  b.setVal111(e.IsInitializerCapture());
  b.setVal112(e.IsInline());
  b.setVal113(e.IsInlineSpecified());
  b.setVal114(e.IsKnownToBeDefined());
  b.setVal115(e.IsLocalVariableDeclaration());
  b.setVal116(e.IsLocalVariableDeclarationOrParm());
  b.setVal117(e.IsNRVOVariable());
  b.setVal118(e.IsNoDestroy());
  b.setVal119(e.IsNonEscapingByref());
  b.setVal120(e.IsObjCForDeclaration());
  b.setVal121(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal122(e.IsStaticDataMember());
  b.setVal123(e.IsStaticLocal());
  b.setVal124(e.IsThisDeclarationADemotedDefinition());
  b.setVal125(e.IsUsableInConstantExpressions());
  b.setVal126(e.MightBeUsableInConstantExpressions());
  b.setVal127(static_cast<unsigned short>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ParmVarDecl &e) {
  SerializeVarDecl(es, b, e);
  if (auto r128 = e.DefaultArgumentRange(); auto rs128 = r128.Size()) {
    b.setVal128(es.EntityId(r128[0]));
    b.setVal129(es.EntityId(r128[rs128 - 1u]));
  } else {
    b.setVal128(0);
    b.setVal129(0);
  }
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal131(e.HasDefaultArgument());
  b.setVal132(e.HasInheritedDefaultArgument());
  b.setVal133(e.HasUninstantiatedDefaultArgument());
  b.setVal134(e.HasUnparsedDefaultArgument());
  b.setVal135(e.IsDestroyedInCallee());
  b.setVal136(e.IsKNRPromoted());
  b.setVal137(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPCapturedExprDecl &e) {
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ImplicitParamDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::DecompositionDecl &e) {
  SerializeVarDecl(es, b, e);
  auto v10 = e.Bindings();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal128(es.EntityId(e.ExternToken()));
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v138 = e.TemplateArguments();
  auto sv138 = b.initVal138(static_cast<unsigned>(v138.size()));
  auto i138 = 0u;
  for (const auto &e138 : v138) {
    auto o138 = es.next_pseudo_entity_offset++;
    sv138.set(i138, o138);
    SerializeTemplateArgument(es, es.entity_builder[o138], e138);
    ++i138;
  }
  auto v139 = e.TemplateInstantiationArguments();
  auto sv139 = b.initVal139(static_cast<unsigned>(v139.size()));
  auto i139 = 0u;
  for (const auto &e139 : v139) {
    auto o139 = es.next_pseudo_entity_offset++;
    sv139.set(i139, o139);
    SerializeTemplateArgument(es, es.entity_builder[o139], e139);
    ++i139;
  }
  b.setVal129(es.EntityId(e.TemplateKeywordToken()));
  b.setVal131(e.IsClassScopeExplicitSpecialization());
  b.setVal132(e.IsExplicitInstantiationOrSpecialization());
  b.setVal133(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
}

void SerializeNonTypeTemplateParmDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.DefaultArgumentWasInherited());
  b.setVal25(es.EntityId(e.DefaultArgumentToken()));
  b.setVal82(e.HasDefaultArgument());
  b.setVal84(e.HasPlaceholderTypeConstraint());
  b.setVal91(e.IsExpandedParameterPack());
  b.setVal94(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::MSPropertyDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.HasGetter());
  b.setVal82(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FunctionDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.DoesThisDeclarationHaveABody());
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.ConstexprKind())));
  auto v25 = e.Definition();
  if (v25) {
    if (auto id25 = es.EntityId(v25.value())) {
      b.setVal25(id25);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal26(es.EntityId(e.EllipsisToken()));
  if (auto r69 = e.ExceptionSpecSourceRange(); auto rs69 = r69.Size()) {
    b.setVal69(es.EntityId(r69[0]));
    b.setVal74(es.EntityId(r69[rs69 - 1u]));
  } else {
    b.setVal69(0);
    b.setVal74(0);
  }
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.ExceptionSpecType())));
  auto v90 = e.InstantiatedFromMemberFunction();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.MultiVersionKind())));
  b.setVal88(static_cast<unsigned short>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r128 = e.ParametersSourceRange(); auto rs128 = r128.Size()) {
    b.setVal128(es.EntityId(r128[0]));
    b.setVal129(es.EntityId(r128[rs128 - 1u]));
  } else {
    b.setVal128(0);
    b.setVal129(0);
  }
  b.setVal140(es.EntityId(e.PointOfInstantiation()));
  if (auto r141 = e.ReturnTypeSourceRange(); auto rs141 = r141.Size()) {
    b.setVal141(es.EntityId(r141[0]));
    b.setVal142(es.EntityId(r141[rs141 - 1u]));
  } else {
    b.setVal141(0);
    b.setVal142(0);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  auto v143 = e.TemplateInstantiationPattern();
  if (v143) {
    if (auto id143 = es.EntityId(v143.value())) {
      b.setVal143(id143);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal127(static_cast<unsigned short>(mx::FromPasta(e.TemplatedKind())));
  b.setVal94(e.HasImplicitReturnZero());
  b.setVal95(e.HasInheritedPrototype());
  b.setVal96(e.HasOneParameterOrDefaultArguments());
  b.setVal97(e.HasPrototype());
  b.setVal98(e.HasSkippedBody());
  b.setVal99(e.HasTrivialBody());
  b.setVal100(e.HasWrittenPrototype());
  b.setVal101(e.InstantiationIsPending());
  b.setVal102(e.IsCPUDispatchMultiVersion());
  b.setVal103(e.IsCPUSpecificMultiVersion());
  b.setVal104(e.IsConsteval());
  b.setVal105(e.IsConstexpr());
  b.setVal106(e.IsConstexprSpecified());
  b.setVal107(e.IsDefaulted());
  b.setVal108(e.IsDeleted());
  b.setVal109(e.IsDeletedAsWritten());
  b.setVal110(e.IsDestroyingOperatorDelete());
  b.setVal111(e.IsExplicitlyDefaulted());
  b.setVal112(e.IsExternC());
  b.setVal113(e.IsFunctionTemplateSpecialization());
  b.setVal114(e.IsGlobal());
  b.setVal115(e.IsImplicitlyInstantiable());
  b.setVal116(e.IsInExternCContext());
  b.setVal117(e.IsInExternCXXContext());
  b.setVal118(e.IsInlineBuiltinDeclaration());
  b.setVal119(e.IsInlineSpecified());
  b.setVal120(e.IsInlined());
  b.setVal121(e.IsLateTemplateParsed());
  b.setVal122(e.IsMSVCRTEntryPoint());
  b.setVal123(e.IsMain());
  b.setVal124(e.IsMultiVersion());
  b.setVal125(e.IsNoReturn());
  b.setVal126(e.IsOverloadedOperator());
  b.setVal131(e.IsPure());
  b.setVal132(e.IsReplaceableGlobalAllocationFunction());
  b.setVal133(e.IsStatic());
  b.setVal134(e.IsTargetMultiVersion());
  b.setVal135(e.IsTemplateInstantiation());
  b.setVal136(e.IsThisDeclarationADefinition());
  b.setVal137(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal144(e.IsTrivial());
  b.setVal145(e.IsTrivialForCall());
  b.setVal146(e.IsUserProvided());
  b.setVal147(e.IsVariadic());
  b.setVal148(e.IsVirtualAsWritten());
  auto v10 = e.Parameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  b.setVal149(e.UsesSEHTry());
  b.setVal150(e.WillHaveBody());
  pasta::DeclContext dc33(e);
  auto v33 = dc33.AlreadyLoadedDeclarations();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const pasta::Decl &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXMethodDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal151(es.EntityId(e.Parent()));
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal152(e.HasInlineBody());
  b.setVal153(e.IsConst());
  b.setVal154(e.IsCopyAssignmentOperator());
  b.setVal155(e.IsInstance());
  b.setVal156(e.IsLambdaStaticInvoker());
  b.setVal157(e.IsMoveAssignmentOperator());
  b.setVal158(e.IsVirtual());
  b.setVal159(e.IsVolatile());
  auto v34 = e.OverriddenMethods();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const auto &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDestructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal160(es.EntityId(e.OperatorDelete()));
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXConversionDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal161(e.IsExplicit());
  b.setVal162(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXConstructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal160(es.EntityId(e.TargetConstructor()));
  b.setVal161(e.IsDefaultConstructor());
  b.setVal162(e.IsDelegatingConstructor());
  b.setVal163(e.IsExplicit());
  b.setVal164(e.IsInheritingConstructor());
  b.setVal165(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal151(es.EntityId(e.CorrespondingConstructor()));
  b.setVal152(e.IsCopyDeductionCandidate());
  b.setVal153(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FieldDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.InClassInitializerStyle())));
  b.setVal25(es.EntityId(e.Parent()));
  b.setVal81(e.HasCapturedVLAType());
  b.setVal82(e.HasInClassInitializer());
  b.setVal84(e.IsAnonymousStructOrUnion());
  b.setVal91(e.IsBitField());
  b.setVal94(e.IsMutable());
  b.setVal95(e.IsUnnamedBitfield());
  b.setVal96(e.IsZeroLengthBitField());
  b.setVal97(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCIvarDecl &e) {
  SerializeFieldDecl(es, b, e);
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.AccessControl())));
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal26(es.EntityId(e.ContainingInterface()));
  b.setVal69(es.EntityId(e.NextInstanceVariable()));
  b.setVal98(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BindingDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal20(es.EntityId(e.DecomposedDeclaration()));
  b.setVal21(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal20(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UsingShadowDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal20(es.EntityId(e.Introducer()));
  b.setVal21(es.EntityId(e.NextUsingShadowDeclaration()));
  b.setVal22(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  SerializeUsingShadowDecl(es, b, e);
  b.setVal73(e.ConstructsVirtualBase());
  b.setVal24(es.EntityId(e.ConstructedBaseClass()));
  auto v25 = e.ConstructedBaseClassShadowDeclaration();
  if (v25) {
    if (auto id25 = es.EntityId(v25.value())) {
      b.setVal25(id25);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal26(es.EntityId(e.NominatedBaseClass()));
  auto v69 = e.NominatedBaseClassShadowDeclaration();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal74(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UsingPackDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v10 = e.Expansions();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  b.setVal20(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UsingDirectiveDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal20(es.EntityId(e.IdentifierToken()));
  b.setVal21(es.EntityId(e.NamespaceKeyToken()));
  b.setVal22(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal24(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypeDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateTypeParmDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal73(e.DefaultArgumentWasInherited());
  b.setVal20(es.EntityId(e.DefaultArgumentToken()));
  b.setVal81(e.HasDefaultArgument());
  b.setVal82(e.HasTypeConstraint());
  b.setVal84(e.IsExpandedParameterPack());
  b.setVal91(e.IsPackExpansion());
  b.setVal94(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TagDecl &e) {
  SerializeTypeDecl(es, b, e);
  if (auto r20 = e.BraceRange(); auto rs20 = r20.Size()) {
    b.setVal20(es.EntityId(r20[0]));
    b.setVal21(es.EntityId(r20[rs20 - 1u]));
  } else {
    b.setVal20(0);
    b.setVal21(0);
  }
  auto v22 = e.Definition();
  if (v22) {
    if (auto id22 = es.EntityId(v22.value())) {
      b.setVal22(id22);
      b.setVal73(true);
    } else {
      b.setVal73(false);
    }
  } else {
    b.setVal73(false);
  }
  b.setVal24(es.EntityId(e.InnerTokenStart()));
  b.setVal25(es.EntityId(e.OuterTokenStart()));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.TagKind())));
  auto v26 = e.TypedefNameForAnonymousDeclaration();
  if (v26) {
    if (auto id26 = es.EntityId(v26.value())) {
      b.setVal26(id26);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal82(e.HasNameForLinkage());
  b.setVal84(e.IsBeingDefined());
  b.setVal91(e.IsClass());
  b.setVal94(e.IsCompleteDefinition());
  b.setVal95(e.IsCompleteDefinitionRequired());
  b.setVal96(e.IsDependentType());
  b.setVal97(e.IsEmbeddedInDeclarator());
  b.setVal98(e.IsEnum());
  b.setVal99(e.IsFreeStanding());
  b.setVal100(e.IsInterface());
  b.setVal101(e.IsStruct());
  b.setVal102(e.IsThisDeclarationADefinition());
  b.setVal103(e.IsUnion());
  b.setVal104(e.MayHaveOutOfDateDefinition());
  auto v63 = e.TemplateParameterLists();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    auto o63 = es.next_pseudo_entity_offset++;
    sv63.set(i63, o63);
    SerializeTemplateParameterList(es, es.entity_builder[o63], e63);
    ++i63;
  }
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeRecordDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::RecordDecl &e) {
  SerializeTagDecl(es, b, e);
  b.setVal105(e.CanPassInRegisters());
  auto v33 = e.Fields();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  auto v69 = e.FindFirstNamedDataMember();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal106(true);
    } else {
      b.setVal106(false);
    }
  } else {
    b.setVal106(false);
  }
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal107(e.HasFlexibleArrayMember());
  b.setVal108(e.HasLoadedFieldsFromExternalStorage());
  b.setVal109(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal110(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal111(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal112(e.HasObjectMember());
  b.setVal113(e.HasVolatileMember());
  b.setVal114(e.IsAnonymousStructOrUnion());
  b.setVal115(e.IsCapturedRecord());
  b.setVal116(e.IsInjectedClassName());
  b.setVal117(e.IsLambda());
  b.setVal118(e.IsMsStruct());
  b.setVal119(e.IsNonTrivialToPrimitiveCopy());
  b.setVal120(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal121(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal122(e.IsOrContainsUnion());
  b.setVal123(e.IsParameterDestroyedInCallee());
  b.setVal124(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::CXXRecordDecl &e) {
  SerializeRecordDecl(es, b, e);
  b.setVal125(e.AllowConstDefaultInitializer());
  auto v138 = e.Bases();
  auto sv138 = b.initVal138(static_cast<unsigned>(v138.size()));
  auto i138 = 0u;
  for (const auto &e138 : v138) {
    auto o138 = es.next_pseudo_entity_offset++;
    sv138.set(i138, o138);
    SerializeCXXBaseSpecifier(es, es.entity_builder[o138], e138);
    ++i138;
  }
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.CalculateInheritanceModel())));
  auto v34 = e.Constructors();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const auto &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
  b.setVal126(e.DefaultedCopyConstructorIsDeleted());
  b.setVal131(e.DefaultedDefaultConstructorIsConstexpr());
  b.setVal132(e.DefaultedDestructorIsConstexpr());
  b.setVal133(e.DefaultedDestructorIsDeleted());
  b.setVal134(e.DefaultedMoveConstructorIsDeleted());
  auto v36 = e.Friends();
  auto sv36 = b.initVal36(static_cast<unsigned>(v36.size()));
  auto i36 = 0u;
  for (const auto &e36 : v36) {
    sv36.set(i36, es.EntityId(e36));
    ++i36;
  }
  auto v74 = e.Destructor();
  if (v74) {
    if (auto id74 = es.EntityId(v74.value())) {
      b.setVal74(id74);
      b.setVal135(true);
    } else {
      b.setVal135(false);
    }
  } else {
    b.setVal135(false);
  }
  auto v1 = e.GenericLambdaTemplateParameterList();
  if (v1) {
    auto o1 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.entity_builder[o1], v1.value());
    b.setVal1(o1);
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v90 = e.InstantiatedFromMemberClass();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal137(true);
    } else {
      b.setVal137(false);
    }
  } else {
    b.setVal137(false);
  }
  auto v128 = e.LambdaCallOperator();
  if (v128) {
    if (auto id128 = es.EntityId(v128.value())) {
      b.setVal128(id128);
      b.setVal144(true);
    } else {
      b.setVal144(false);
    }
  } else {
    b.setVal144(false);
  }
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.LambdaCaptureDefault())));
  auto v37 = e.LambdaExplicitTemplateParameters();
  auto sv37 = b.initVal37(static_cast<unsigned>(v37.size()));
  auto i37 = 0u;
  for (const auto &e37 : v37) {
    sv37.set(i37, es.EntityId(e37));
    ++i37;
  }
  b.setVal88(static_cast<unsigned short>(mx::FromPasta(e.MSInheritanceModel())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.MSVtorDispMode())));
  b.setVal129(es.EntityId(e.MostRecentNonInjectedDeclaration()));
  auto v140 = e.TemplateInstantiationPattern();
  if (v140) {
    if (auto id140 = es.EntityId(v140.value())) {
      b.setVal140(id140);
      b.setVal145(true);
    } else {
      b.setVal145(false);
    }
  } else {
    b.setVal145(false);
  }
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal146(e.HasAnyDependentBases());
  b.setVal147(e.HasConstexprDefaultConstructor());
  b.setVal148(e.HasConstexprDestructor());
  b.setVal149(e.HasConstexprNonCopyMoveConstructor());
  b.setVal150(e.HasCopyAssignmentWithConstParameter());
  b.setVal152(e.HasCopyConstructorWithConstParameter());
  b.setVal153(e.HasDefaultConstructor());
  b.setVal154(e.HasDefinition());
  b.setVal155(e.HasDirectFields());
  b.setVal156(e.HasFriends());
  b.setVal157(e.HasInClassInitializer());
  b.setVal158(e.HasInheritedAssignment());
  b.setVal159(e.HasInheritedConstructor());
  b.setVal161(e.HasIrrelevantDestructor());
  b.setVal162(e.HasKnownLambdaInternalLinkage());
  b.setVal163(e.HasMoveAssignment());
  b.setVal164(e.HasMoveConstructor());
  b.setVal165(e.HasMutableFields());
  b.setVal166(e.HasNonLiteralTypeFieldsOrBases());
  b.setVal167(e.HasNonTrivialCopyAssignment());
  b.setVal168(e.HasNonTrivialCopyConstructor());
  b.setVal169(e.HasNonTrivialCopyConstructorForCall());
  b.setVal170(e.HasNonTrivialDefaultConstructor());
  b.setVal171(e.HasNonTrivialDestructor());
  b.setVal172(e.HasNonTrivialDestructorForCall());
  b.setVal173(e.HasNonTrivialMoveAssignment());
  b.setVal174(e.HasNonTrivialMoveConstructor());
  b.setVal175(e.HasNonTrivialMoveConstructorForCall());
  b.setVal176(e.HasPrivateFields());
  b.setVal177(e.HasProtectedFields());
  b.setVal178(e.HasSimpleCopyAssignment());
  b.setVal179(e.HasSimpleCopyConstructor());
  b.setVal180(e.HasSimpleDestructor());
  b.setVal181(e.HasSimpleMoveAssignment());
  b.setVal182(e.HasSimpleMoveConstructor());
  b.setVal183(e.HasTrivialCopyAssignment());
  b.setVal184(e.HasTrivialCopyConstructor());
  b.setVal185(e.HasTrivialCopyConstructorForCall());
  b.setVal186(e.HasTrivialDefaultConstructor());
  b.setVal187(e.HasTrivialDestructor());
  b.setVal188(e.HasTrivialDestructorForCall());
  b.setVal189(e.HasTrivialMoveAssignment());
  b.setVal190(e.HasTrivialMoveConstructor());
  b.setVal191(e.HasTrivialMoveConstructorForCall());
  b.setVal192(e.HasUninitializedReferenceMember());
  b.setVal193(e.HasUserDeclaredConstructor());
  b.setVal194(e.HasUserDeclaredCopyAssignment());
  b.setVal195(e.HasUserDeclaredCopyConstructor());
  b.setVal196(e.HasUserDeclaredDestructor());
  b.setVal197(e.HasUserDeclaredMoveAssignment());
  b.setVal198(e.HasUserDeclaredMoveConstructor());
  b.setVal199(e.HasUserDeclaredMoveOperation());
  b.setVal200(e.HasUserProvidedDefaultConstructor());
  b.setVal201(e.HasVariantMembers());
  b.setVal202(e.ImplicitCopyAssignmentHasConstParameter());
  b.setVal203(e.ImplicitCopyConstructorHasConstParameter());
  b.setVal204(e.IsAbstract());
  b.setVal205(e.IsAggregate());
  b.setVal206(e.IsAnyDestructorNoReturn());
  b.setVal207(e.IsCLike());
  b.setVal208(e.IsCXX11StandardLayout());
  b.setVal209(e.IsDependentLambda());
  b.setVal210(e.IsDynamicClass());
  b.setVal211(e.IsEffectivelyFinal());
  b.setVal212(e.IsEmpty());
  b.setVal213(e.IsGenericLambda());
  b.setVal214(e.IsInterfaceLike());
  b.setVal215(e.IsLiteral());
  auto v141 = e.IsLocalClass();
  if (v141) {
    if (auto id141 = es.EntityId(v141.value())) {
      b.setVal141(id141);
      b.setVal216(true);
    } else {
      b.setVal216(false);
    }
  } else {
    b.setVal216(false);
  }
  b.setVal217(e.IsPOD());
  b.setVal218(e.IsParsingBaseSpecifiers());
  b.setVal219(e.IsPolymorphic());
  b.setVal220(e.IsStandardLayout());
  b.setVal221(e.IsStructural());
  b.setVal222(e.IsTrivial());
  b.setVal223(e.IsTriviallyCopyable());
  b.setVal224(e.LambdaIsDefaultConstructibleAndAssignable());
  b.setVal225(e.MayBeAbstract());
  b.setVal226(e.MayBeDynamicClass());
  b.setVal227(e.MayBeNonDynamicClass());
  auto v228 = e.Methods();
  auto sv228 = b.initVal228(static_cast<unsigned>(v228.size()));
  auto i228 = 0u;
  for (const auto &e228 : v228) {
    sv228.set(i228, es.EntityId(e228));
    ++i228;
  }
  b.setVal229(e.NeedsImplicitCopyAssignment());
  b.setVal230(e.NeedsImplicitCopyConstructor());
  b.setVal231(e.NeedsImplicitDefaultConstructor());
  b.setVal232(e.NeedsImplicitDestructor());
  b.setVal233(e.NeedsImplicitMoveAssignment());
  b.setVal234(e.NeedsImplicitMoveConstructor());
  b.setVal235(e.NeedsOverloadResolutionForCopyAssignment());
  b.setVal236(e.NeedsOverloadResolutionForCopyConstructor());
  b.setVal237(e.NeedsOverloadResolutionForDestructor());
  b.setVal238(e.NeedsOverloadResolutionForMoveAssignment());
  b.setVal239(e.NeedsOverloadResolutionForMoveConstructor());
  b.setVal240(e.NullFieldOffsetIsZero());
  auto v139 = e.VirtualBases();
  auto sv139 = b.initVal139(static_cast<unsigned>(v139.size()));
  auto i139 = 0u;
  for (const auto &e139 : v139) {
    auto o139 = es.next_pseudo_entity_offset++;
    sv139.set(i139, o139);
    SerializeCXXBaseSpecifier(es, es.entity_builder[o139], e139);
    ++i139;
  }
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  SerializeCXXRecordDecl(es, b, e);
  b.setVal142(es.EntityId(e.ExternToken()));
  b.setVal143(es.EntityId(e.PointOfInstantiation()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v241 = e.TemplateArguments();
  auto sv241 = b.initVal241(static_cast<unsigned>(v241.size()));
  auto i241 = 0u;
  for (const auto &e241 : v241) {
    auto o241 = es.next_pseudo_entity_offset++;
    sv241.set(i241, o241);
    SerializeTemplateArgument(es, es.entity_builder[o241], e241);
    ++i241;
  }
  auto v242 = e.TemplateInstantiationArguments();
  auto sv242 = b.initVal242(static_cast<unsigned>(v242.size()));
  auto i242 = 0u;
  for (const auto &e242 : v242) {
    auto o242 = es.next_pseudo_entity_offset++;
    sv242.set(i242, o242);
    SerializeTemplateArgument(es, es.entity_builder[o242], e242);
    ++i242;
  }
  b.setVal151(es.EntityId(e.TemplateKeywordToken()));
  b.setVal243(e.IsClassScopeExplicitSpecialization());
  b.setVal244(e.IsExplicitInstantiationOrSpecialization());
  b.setVal245(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
}

void SerializeEnumDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::EnumDecl &e) {
  SerializeTagDecl(es, b, e);
  auto v33 = e.Enumerators();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  auto v69 = e.InstantiatedFromMemberEnum();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal105(true);
    } else {
      b.setVal105(false);
    }
  } else {
    b.setVal105(false);
  }
  if (auto r74 = e.IntegerTypeRange(); auto rs74 = r74.Size()) {
    b.setVal74(es.EntityId(r74[0]));
    b.setVal90(es.EntityId(r74[rs74 - 1u]));
  } else {
    b.setVal74(0);
    b.setVal90(0);
  }
  auto v128 = e.TemplateInstantiationPattern();
  if (v128) {
    if (auto id128 = es.EntityId(v128.value())) {
      b.setVal128(id128);
      b.setVal106(true);
    } else {
      b.setVal106(false);
    }
  } else {
    b.setVal106(false);
  }
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal107(e.IsClosed());
  b.setVal108(e.IsClosedFlag());
  b.setVal109(e.IsClosedNonFlag());
  b.setVal110(e.IsComplete());
  b.setVal111(e.IsFixed());
  b.setVal112(e.IsScoped());
  b.setVal113(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal20(es.EntityId(e.EllipsisToken()));
  b.setVal21(es.EntityId(e.TypenameToken()));
  b.setVal22(es.EntityId(e.UsingToken()));
  b.setVal73(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypedefNameDecl &e) {
  SerializeTypeDecl(es, b, e);
  auto v20 = e.AnonymousDeclarationWithTypedefName();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal73(true);
    } else {
      b.setVal73(false);
    }
  } else {
    b.setVal73(false);
  }
  b.setVal81(e.IsModed());
  b.setVal82(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypedefDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypeAliasDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  auto v21 = e.DescribedAliasTemplate();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setVal21(id21);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCTypeParamDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  b.setVal21(es.EntityId(e.ColonToken()));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.Variance())));
  b.setVal22(es.EntityId(e.VarianceToken()));
  b.setVal84(e.HasExplicitBound());
}

void SerializeTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateDecl &e) {
}

void SerializeRedeclarableTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::RedeclarableTemplateDecl &e) {
}

void SerializeFunctionTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FunctionTemplateDecl &e) {
}

void SerializeClassTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ClassTemplateDecl &e) {
}

void SerializeVarTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::VarTemplateDecl &e) {
}

void SerializeTypeAliasTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b, e);
}

void SerializeConceptDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ConceptDecl &e) {
  SerializeTemplateDecl(es, b, e);
  b.setVal73(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::BuiltinTemplateDecl &e) {
}

void SerializeTemplateTemplateParmDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::TemplateTemplateParmDecl &e) {
}

void SerializeObjCPropertyDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCPropertyDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal20(es.EntityId(e.AtToken()));
  b.setVal21(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal22(es.EntityId(e.GetterNameToken()));
  b.setVal24(es.EntityId(e.LParenToken()));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal25(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.QueryKind())));
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.SetterKind())));
  b.setVal26(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal69(es.EntityId(e.SetterNameToken()));
  b.setVal73(e.IsAtomic());
  b.setVal81(e.IsClassProperty());
  b.setVal82(e.IsDirectProperty());
  b.setVal84(e.IsInstanceProperty());
  b.setVal91(e.IsOptional());
  b.setVal94(e.IsReadOnly());
  b.setVal95(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCMethodDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal73(e.DefinedInNSObject());
  b.setVal20(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal21(es.EntityId(e.Category()));
  b.setVal22(es.EntityId(e.ClassInterface()));
  b.setVal24(es.EntityId(e.CmdDeclaration()));
  b.setVal25(es.EntityId(e.DeclaratorEndToken()));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.ImplementationControl())));
  b.setVal85(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal86(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  if (auto r26 = e.ReturnTypeSourceRange(); auto rs26 = r26.Size()) {
    b.setVal26(es.EntityId(r26[0]));
    b.setVal69(es.EntityId(r26[rs26 - 1u]));
  } else {
    b.setVal26(0);
    b.setVal69(0);
  }
  b.setVal74(es.EntityId(e.SelectorStartToken()));
  b.setVal90(es.EntityId(e.SelfDeclaration()));
  b.setVal81(e.HasRedeclaration());
  b.setVal82(e.HasRelatedResultType());
  b.setVal84(e.HasSkippedBody());
  b.setVal91(e.IsClassMethod());
  b.setVal94(e.IsDefined());
  b.setVal95(e.IsDesignatedInitializerForTheInterface());
  b.setVal96(e.IsDirectMethod());
  b.setVal97(e.IsInstanceMethod());
  b.setVal98(e.IsOptional());
  b.setVal99(e.IsOverriding());
  b.setVal100(e.IsPropertyAccessor());
  b.setVal101(e.IsRedeclaration());
  b.setVal102(e.IsSynthesizedAccessorStub());
  b.setVal103(e.IsThisDeclarationADefinition());
  b.setVal104(e.IsThisDeclarationADesignatedInitializer());
  b.setVal105(e.IsVariadic());
  auto v10 = e.Parameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v33 = e.SelectorTokens();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  pasta::DeclContext dc34(e);
  auto v34 = dc34.AlreadyLoadedDeclarations();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const pasta::Decl &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCContainerDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v10 = e.ClassMethods();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v33 = e.ClassProperties();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  if (auto r20 = e.AtEndRange(); auto rs20 = r20.Size()) {
    b.setVal20(es.EntityId(r20[0]));
    b.setVal21(es.EntityId(r20[rs20 - 1u]));
  } else {
    b.setVal20(0);
    b.setVal21(0);
  }
  b.setVal22(es.EntityId(e.AtStartToken()));
  auto v34 = e.InstanceMethods();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const auto &e34 : v34) {
    sv34.set(i34, es.EntityId(e34));
    ++i34;
  }
  auto v36 = e.InstanceProperties();
  auto sv36 = b.initVal36(static_cast<unsigned>(v36.size()));
  auto i36 = 0u;
  for (const auto &e36 : v36) {
    sv36.set(i36, es.EntityId(e36));
    ++i36;
  }
  auto v37 = e.Methods();
  auto sv37 = b.initVal37(static_cast<unsigned>(v37.size()));
  auto i37 = 0u;
  for (const auto &e37 : v37) {
    sv37.set(i37, es.EntityId(e37));
    ++i37;
  }
  auto v228 = e.Properties();
  auto sv228 = b.initVal228(static_cast<unsigned>(v228.size()));
  auto i228 = 0u;
  for (const auto &e228 : v228) {
    sv228.set(i228, es.EntityId(e228));
    ++i228;
  }
  pasta::DeclContext dc246(e);
  auto v246 = dc246.AlreadyLoadedDeclarations();
  auto sv246 = b.initVal246(static_cast<unsigned>(v246.size()));
  auto i246 = 0u;
  for (const pasta::Decl &e246 : v246) {
    sv246.set(i246, es.EntityId(e246));
    ++i246;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCCategoryDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal73(e.IsClassExtension());
  b.setVal24(es.EntityId(e.CategoryNameToken()));
  b.setVal25(es.EntityId(e.ClassInterface()));
  b.setVal26(es.EntityId(e.Implementation()));
  b.setVal69(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal74(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal90(es.EntityId(e.NextClassCategory()));
  b.setVal128(es.EntityId(e.NextClassCategoryRaw()));
  auto v247 = e.InstanceVariables();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    sv247.set(i247, es.EntityId(e247));
    ++i247;
  }
  auto v248 = e.ProtocolTokens();
  auto sv248 = b.initVal248(static_cast<unsigned>(v248.size()));
  auto i248 = 0u;
  for (const auto &e248 : v248) {
    sv248.set(i248, es.EntityId(e248));
    ++i248;
  }
  auto v249 = e.Protocols();
  auto sv249 = b.initVal249(static_cast<unsigned>(v249.size()));
  auto i249 = 0u;
  for (const auto &e249 : v249) {
    sv249.set(i249, es.EntityId(e249));
    ++i249;
  }
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCProtocolDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal24(es.EntityId(e.Definition()));
  auto v80 = e.ObjCRuntimeNameAsString();
  std::string s80(v80.data(), v80.size());
  b.setVal80(s80);
  b.setVal73(e.HasDefinition());
  b.setVal81(e.IsNonRuntimeProtocol());
  b.setVal82(e.IsThisDeclarationADefinition());
  auto v247 = e.ProtocolTokens();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    sv247.set(i247, es.EntityId(e247));
    ++i247;
  }
  auto v248 = e.Protocols();
  auto sv248 = b.initVal248(static_cast<unsigned>(v248.size()));
  auto i248 = 0u;
  for (const auto &e248 : v248) {
    sv248.set(i248, es.EntityId(e248));
    ++i248;
  }
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCInterfaceDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  auto v247 = e.AllReferencedProtocols();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    sv247.set(i247, es.EntityId(e247));
    ++i247;
  }
  b.setVal73(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal24(es.EntityId(e.CategoryListRaw()));
  b.setVal25(es.EntityId(e.Definition()));
  b.setVal26(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal69(es.EntityId(e.Implementation()));
  auto v80 = e.ObjCRuntimeNameAsString();
  std::string s80(v80.data(), v80.size());
  b.setVal80(s80);
  b.setVal74(es.EntityId(e.SuperClass()));
  b.setVal90(es.EntityId(e.SuperClassToken()));
  b.setVal81(e.HasDefinition());
  b.setVal82(e.HasDesignatedInitializers());
  b.setVal84(e.IsArcWeakrefUnavailable());
  b.setVal91(e.IsImplicitInterfaceDeclaration());
  b.setVal128(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal94(e.IsThisDeclarationADefinition());
  auto v248 = e.InstanceVariables();
  auto sv248 = b.initVal248(static_cast<unsigned>(v248.size()));
  auto i248 = 0u;
  for (const auto &e248 : v248) {
    sv248.set(i248, es.EntityId(e248));
    ++i248;
  }
  auto v249 = e.KnownCategories();
  auto sv249 = b.initVal249(static_cast<unsigned>(v249.size()));
  auto i249 = 0u;
  for (const auto &e249 : v249) {
    sv249.set(i249, es.EntityId(e249));
    ++i249;
  }
  auto v250 = e.KnownExtensions();
  auto sv250 = b.initVal250(static_cast<unsigned>(v250.size()));
  auto i250 = 0u;
  for (const auto &e250 : v250) {
    sv250.set(i250, es.EntityId(e250));
    ++i250;
  }
  auto v251 = e.ProtocolTokens();
  auto sv251 = b.initVal251(static_cast<unsigned>(v251.size()));
  auto i251 = 0u;
  for (const auto &e251 : v251) {
    sv251.set(i251, es.EntityId(e251));
    ++i251;
  }
  auto v252 = e.Protocols();
  auto sv252 = b.initVal252(static_cast<unsigned>(v252.size()));
  auto i252 = 0u;
  for (const auto &e252 : v252) {
    sv252.set(i252, es.EntityId(e252));
    ++i252;
  }
  auto v253 = e.VisibleCategories();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const auto &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
  auto v254 = e.VisibleExtensions();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCImplDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal24(es.EntityId(e.ClassInterface()));
  auto v247 = e.PropertyImplementations();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    sv247.set(i247, es.EntityId(e247));
    ++i247;
  }
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal25(es.EntityId(e.CategoryDeclaration()));
  b.setVal26(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCImplementationDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal25(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal26(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v80 = e.ObjCRuntimeNameAsString();
  std::string s80(v80.data(), v80.size());
  b.setVal80(s80);
  b.setVal69(es.EntityId(e.SuperClass()));
  b.setVal74(es.EntityId(e.SuperClassToken()));
  b.setVal73(e.HasDestructors());
  b.setVal81(e.HasNonZeroConstructors());
  auto v248 = e.InstanceVariables();
  auto sv248 = b.initVal248(static_cast<unsigned>(v248.size()));
  auto i248 = 0u;
  for (const auto &e248 : v248) {
    sv248.set(i248, es.EntityId(e248));
    ++i248;
  }
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal20(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NamespaceDecl &e) {
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::NamespaceAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal20(es.EntityId(e.AliasToken()));
  b.setVal21(es.EntityId(e.AliasedNamespace()));
  b.setVal22(es.EntityId(e.NamespaceToken()));
  b.setVal24(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::LinkageSpecDecl &e) {
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.ExtendingDeclaration()));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ImportDecl &e) {
  SerializeDecl(es, b, e);
  auto v10 = e.IdentifierTokens();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeFriendTemplateDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FriendTemplateDecl &e) {
}

void SerializeFriendDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FriendDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.FriendDeclaration()));
  b.setVal20(es.EntityId(e.FriendToken()));
  b.setVal62(e.IsUnsupportedFriend());
  auto v63 = e.FriendTypeTemplateParameterLists();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    auto o63 = es.next_pseudo_entity_offset++;
    sv63.set(i63, o63);
    SerializeTemplateParameterList(es, es.entity_builder[o63], e63);
    ++i63;
  }
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::FileScopeAsmDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.AssemblyToken()));
  b.setVal20(es.EntityId(e.AssemblyString()));
  b.setVal21(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExternCContextDecl &e) {
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::ExportDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal19(es.EntityId(e.ExportToken()));
  b.setVal20(es.EntityId(e.RBraceToken()));
  b.setVal62(e.HasBraces());
  pasta::DeclContext dc10(e);
  auto v10 = dc10.AlreadyLoadedDeclarations();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const pasta::Decl &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::Entity::Builder b, const pasta::EmptyDecl &e) {
  SerializeDecl(es, b, e);
}

}  // namespace indexer
