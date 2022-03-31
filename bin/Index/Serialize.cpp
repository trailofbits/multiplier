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
  next_pseudo_entity_offset = 0;
  decl_builder = builder.initDeclarations(code.num_decl_entities);
  stmt_builder = builder.initStatements(code.num_stmt_entities);
  pseudo_builder = builder.initOthers(code.num_pseudo_entities);
  for (const pasta::Decl &decl : code.decls) {
    this->DeclVisitor::Accept(decl);
  }
}

void SerializeTemplateParameterList(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
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

void SerializeTemplateArgument(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
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

void SerializeCXXBaseSpecifier(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
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

void SerializeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setVal0(es.EntityId(e.BeginToken()));
  b.setVal1(es.EntityId(e.EndToken()));
  if (auto r2 = e.TokenRange(); auto rs2 = r2.Size()) {
    b.setVal2(es.EntityId(r2[0]));
    b.setVal3(es.EntityId(r2[rs2 - 1u]));
  } else {
    b.setVal2(0);
    b.setVal3(0);
  }
  b.setVal4(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
}

void SerializeSEHTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ExceptHandler()));
  b.setVal6(es.EntityId(e.FinallyHandler()));
  b.setVal7(e.IsCXXTry());
  b.setVal8(es.EntityId(e.TryBlock()));
  b.setVal9(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.Block()));
  b.setVal6(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.Block()));
  b.setVal6(es.EntityId(e.ExceptToken()));
}

void SerializeReturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v5 = e.NRVOCandidate();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal7(true);
    } else {
      b.setVal7(false);
    }
  } else {
    b.setVal7(false);
  }
  b.setVal6(es.EntityId(e.ReturnToken()));
}

void SerializeObjCForCollectionStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ForToken()));
  b.setVal6(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.AtToken()));
}

void SerializeObjCAtTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.AtTryToken()));
  b.setVal6(es.EntityId(e.FinallyStatement()));
  auto v10 = e.CatchStatements();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeObjCAtThrowStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.AtSynchronizedToken()));
  b.setVal6(es.EntityId(e.SynchBody()));
}

void SerializeObjCAtFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.AtFinallyToken()));
}

void SerializeObjCAtCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.AtCatchToken()));
  b.setVal6(es.EntityId(e.CatchParameterDeclaration()));
  b.setVal8(es.EntityId(e.RParenToken()));
  b.setVal7(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal7(e.HasAssociatedStatement());
  b.setVal11(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal6(es.EntityId(e.TargetCallToken()));
}

void SerializeOMPDepobjDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCriticalDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancellationPointDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPBarrierDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPAtomicDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.IsPostfixUpdate());
  b.setVal13(e.IsXLHSInRHSPart());
}

void SerializeOMPTeamsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskyieldDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskwaitDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskgroupDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetEnterDataDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDataDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSingleDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSectionsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPSectionDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPScanDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMasterDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMaskedDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPLoopBasedDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPUnrollDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPTileDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
}

void SerializeOMPForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPDistributeDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal12(e.HasCancel());
}

void SerializeOMPInteropDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.DistanceFunc()));
  b.setVal6(es.EntityId(e.LoopVariableFunc()));
  b.setVal8(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.SemiToken()));
  b.setVal7(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.KeywordToken()));
  b.setVal6(es.EntityId(e.SubStatement()));
  b.setVal7(e.IsIfExists());
  b.setVal11(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ConstantTarget()));
  b.setVal6(es.EntityId(e.GotoToken()));
  b.setVal8(es.EntityId(e.StarToken()));
}

void SerializeIfStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  auto v5 = e.ConditionVariable();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal7(true);
    } else {
      b.setVal7(false);
    }
  } else {
    b.setVal7(false);
  }
  auto v6 = e.ConditionVariableDeclarationStatement();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setVal6(id6);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal8(es.EntityId(e.ElseToken()));
  b.setVal9(es.EntityId(e.IfToken()));
  b.setVal14(es.EntityId(e.LParenToken()));
  b.setVal15(es.EntityId(e.RParenToken()));
  b.setVal12(e.HasElseStorage());
  b.setVal13(e.HasInitializerStorage());
  b.setVal16(e.HasVariableStorage());
  b.setVal17(e.IsConstexpr());
  b.setVal18(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.GotoToken()));
  b.setVal6(es.EntityId(e.Label()));
  b.setVal8(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  auto v5 = e.ConditionVariable();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal7(true);
    } else {
      b.setVal7(false);
    }
  } else {
    b.setVal7(false);
  }
  auto v6 = e.ConditionVariableDeclarationStatement();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setVal6(id6);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal8(es.EntityId(e.ForToken()));
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeDoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.DoToken()));
  b.setVal6(es.EntityId(e.RParenToken()));
  b.setVal8(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal7(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.PromiseDeclaration()));
  b.setVal7(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.KeywordToken()));
  b.setVal7(e.IsImplicit());
}

void SerializeContinueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.LBracToken()));
  b.setVal6(es.EntityId(e.RBracToken()));
}

void SerializeCapturedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.CapturedDeclaration()));
  b.setVal6(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal19(static_cast<unsigned short>(mx::FromPasta(e.CapturedRegionKind())));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.TryBlock()));
  b.setVal6(es.EntityId(e.TryToken()));
  auto v10 = e.Handlers();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeCXXForRangeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.BeginStatement()));
  b.setVal6(es.EntityId(e.CoawaitToken()));
  b.setVal8(es.EntityId(e.ColonToken()));
  b.setVal9(es.EntityId(e.EndStatement()));
  b.setVal14(es.EntityId(e.ForToken()));
  b.setVal15(es.EntityId(e.LoopVariableStatement()));
  b.setVal20(es.EntityId(e.LoopVariable()));
  b.setVal21(es.EntityId(e.RParenToken()));
  b.setVal22(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.CatchToken()));
  b.setVal6(es.EntityId(e.ExceptionDeclaration()));
}

void SerializeBreakStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal23(e.GenerateAssemblyString());
  b.setVal5(es.EntityId(e.AssemblyToken()));
  b.setVal7(e.IsSimple());
  b.setVal11(e.IsVolatile());
  auto v24 = e.OutputConstraints();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    std::string se24(e24.data(), e24.size());
    sv24.set(i24, se24);
    ++i24;
  }
  auto v25 = e.InputConstraints();
  auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
  auto i25 = 0u;
  for (const auto &e25 : v25) {
    std::string se25(e25.data(), e25.size());
    sv25.set(i25, se25);
    ++i25;
  }
  auto v26 = e.Clobbers();
  auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
  auto i26 = 0u;
  for (const auto &e26 : v26) {
    std::string se26(e26.data(), e26.size());
    sv26.set(i26, se26);
    ++i26;
  }
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  auto v27 = e.AllConstraints();
  auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
  auto i27 = 0u;
  for (const auto &e27 : v27) {
    std::string se27(e27.data(), e27.size());
    sv27.set(i27, se27);
    ++i27;
  }
  auto v28 = e.AssemblyString();
  std::string s28(v28.data(), v28.size());
  b.setVal28(s28);
  b.setVal6(es.EntityId(e.LBraceToken()));
  b.setVal12(e.HasBraces());
}

void SerializeGCCAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal6(es.EntityId(e.AssemblyString()));
  b.setVal8(es.EntityId(e.RParenToken()));
  b.setVal12(e.IsAssemblyGoto());
  auto v10 = e.Labels();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  auto v29 = e.OutputConstraintLiterals();
  auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
  auto i29 = 0u;
  for (const auto &e29 : v29) {
    sv29.set(i29, es.EntityId(e29));
    ++i29;
  }
  auto v27 = e.OutputNames();
  auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
  auto i27 = 0u;
  for (const auto &e27 : v27) {
    std::string se27(e27.data(), e27.size());
    sv27.set(i27, se27);
    ++i27;
  }
  auto v30 = e.InputConstraintLiterals();
  auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
  auto i30 = 0u;
  for (const auto &e30 : v30) {
    sv30.set(i30, es.EntityId(e30));
    ++i30;
  }
  auto v31 = e.InputNames();
  auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
  auto i31 = 0u;
  for (const auto &e31 : v31) {
    std::string se31(e31.data(), e31.size());
    sv31.set(i31, se31);
    ++i31;
  }
  auto v32 = e.ClobberStringLiterals();
  auto sv32 = b.initVal32(static_cast<unsigned>(v32.size()));
  auto i32 = 0u;
  for (const auto &e32 : v32) {
    sv32.set(i32, es.EntityId(e32));
    ++i32;
  }
  auto v33 = e.LabelExpressions();
  auto sv33 = b.initVal33(static_cast<unsigned>(v33.size()));
  auto i33 = 0u;
  for (const auto &e33 : v33) {
    sv33.set(i33, es.EntityId(e33));
    ++i33;
  }
  auto v34 = e.LabelNames();
  auto sv34 = b.initVal34(static_cast<unsigned>(v34.size()));
  auto i34 = 0u;
  for (const auto &e34 : v34) {
    std::string se34(e34.data(), e34.size());
    sv34.set(i34, se34);
    ++i34;
  }
}

void SerializeWhileStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  auto v5 = e.ConditionVariable();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal7(true);
    } else {
      b.setVal7(false);
    }
  } else {
    b.setVal7(false);
  }
  auto v6 = e.ConditionVariableDeclarationStatement();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setVal6(id6);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal8(es.EntityId(e.LParenToken()));
  b.setVal9(es.EntityId(e.RParenToken()));
  b.setVal14(es.EntityId(e.WhileToken()));
  b.setVal12(e.HasVariableStorage());
}

void SerializeValueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
}

void SerializeLabelStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal5(es.EntityId(e.Declaration()));
  b.setVal6(es.EntityId(e.IdentifierToken()));
  auto v23 = e.Name();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  b.setVal7(e.IsSideEntry());
}

void SerializeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal7(e.HasSideEffects());
  b.setVal11(e.ContainsErrors());
  b.setVal12(e.ContainsUnexpandedParameterPack());
  b.setVal5(es.EntityId(e.ExpressionToken()));
  auto v6 = e.ObjCProperty();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setVal6(id6);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal19(static_cast<unsigned short>(mx::FromPasta(e.ObjectKind())));
  auto v8 = e.SourceBitField();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  b.setVal35(static_cast<unsigned short>(mx::FromPasta(e.ValueKind())));
  b.setVal17(e.HasNonTrivialCall());
  b.setVal18(e.IsDefaultArgument());
  b.setVal36(e.IsGLValue());
  b.setVal37(e.IsImplicitCXXThis());
  b.setVal38(e.IsInstantiationDependent());
  b.setVal39(e.IsKnownToHaveBooleanValue());
  b.setVal40(e.IsLValue());
  b.setVal41(e.IsOBJCGCCandidate());
  b.setVal42(e.IsObjCSelfExpression());
  b.setVal43(e.IsOrdinaryOrBitFieldObject());
  b.setVal44(e.IsPRValue());
  b.setVal45(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal46(e.IsTypeDependent());
  b.setVal47(e.IsValueDependent());
  b.setVal48(e.IsXValue());
  b.setVal49(e.RefersToBitField());
  b.setVal50(e.RefersToGlobalRegisterVariable());
  b.setVal51(e.RefersToMatrixElement());
  b.setVal52(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r9 = e.DesignatorsSourceRange(); auto rs9 = r9.Size()) {
    b.setVal9(es.EntityId(r9[0]));
    b.setVal14(es.EntityId(r9[rs9 - 1u]));
  } else {
    b.setVal9(0);
    b.setVal14(0);
  }
  b.setVal15(es.EntityId(e.EqualOrColonToken()));
  b.setVal53(e.IsDirectInitializer());
  b.setVal54(e.UsesGNUSyntax());
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LAngleToken()));
  b.setVal14(es.EntityId(e.RAngleToken()));
  b.setVal15(es.EntityId(e.TemplateKeywordToken()));
  b.setVal53(e.HasExplicitTemplateArguments());
  b.setVal54(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.KeywordToken()));
  b.setVal14(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Declaration()));
  b.setVal14(es.EntityId(e.FoundDeclaration()));
  b.setVal15(es.EntityId(e.LAngleToken()));
  b.setVal20(es.EntityId(e.RAngleToken()));
  b.setVal21(es.EntityId(e.TemplateKeywordToken()));
  b.setVal53(e.HadMultipleCandidates());
  b.setVal54(e.HasExplicitTemplateArguments());
  b.setVal55(e.HasQualifier());
  b.setVal56(e.HasTemplateKWAndArgumentsInfo());
  b.setVal57(e.HasTemplateKeyword());
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal59(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.KeywordToken()));
  b.setVal14(es.EntityId(e.OpaqueValue()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal53(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeConceptSpecializationExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  auto v60 = e.TemplateArguments();
  auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
  auto i60 = 0u;
  for (const auto &e60 : v60) {
    auto o60 = es.next_pseudo_entity_offset++;
    sv60.set(i60, o60);
    SerializeTemplateArgument(es, es.pseudo_builder[o60], e60);
    ++i60;
  }
  b.setVal53(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal53(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsConditionDependent());
  b.setVal54(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.CastKind())));
  auto v23 = e.CastKindName();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  auto v9 = e.ConversionFunction();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal53(true);
    } else {
      b.setVal53(false);
    }
  } else {
    b.setVal53(false);
  }
  auto v14 = e.TargetUnionField();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal54(true);
    } else {
      b.setVal54(false);
    }
  } else {
    b.setVal54(false);
  }
  b.setVal55(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal56(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r15 = e.AngleBrackets(); auto rs15 = r15.Size()) {
    b.setVal15(es.EntityId(r15[0]));
    b.setVal20(es.EntityId(r15[rs15 - 1u]));
  } else {
    b.setVal15(0);
    b.setVal20(0);
  }
  auto v28 = e.CastName();
  std::string s28(v28.data(), v28.size());
  b.setVal28(s28);
  b.setVal21(es.EntityId(e.OperatorToken()));
  b.setVal22(es.EntityId(e.RParenToken()));
}

void SerializeCXXDynamicCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal56(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXAddrspaceCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXStaticCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXReinterpretCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXFunctionalCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal15(es.EntityId(e.LParenToken()));
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal56(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal15(es.EntityId(e.LParenToken()));
  b.setVal20(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal15(es.EntityId(e.BridgeKeywordToken()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.BridgeKind())));
  auto v28 = e.BridgeKindName();
  std::string s28(v28.data(), v28.size());
  b.setVal28(s28);
  b.setVal20(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.ADLCallKind())));
  auto v9 = e.DirectCallee();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal53(true);
    } else {
      b.setVal53(false);
    }
  } else {
    b.setVal53(false);
  }
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal54(e.HasStoredFPFeatures());
  b.setVal55(e.HasUnusedResultAttribute());
  b.setVal56(e.IsBuiltinAssumeFalse());
  b.setVal57(e.IsCallToStdMove());
  b.setVal59(e.IsUnevaluatedBuiltinCall());
  b.setVal62(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal15(es.EntityId(e.OperatorToken()));
  b.setVal63(e.IsAssignmentOperation());
  b.setVal64(e.IsComparisonOperation());
  b.setVal65(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal15(es.EntityId(e.MethodDeclaration()));
  b.setVal20(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal15(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal15(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.GuidDeclaration()));
  b.setVal53(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.IsMostDerived());
  b.setVal54(e.IsPotentiallyEvaluated());
  b.setVal55(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ThrowToken()));
  b.setVal53(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.RParenToken()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v23 = e.OpcodeString();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal53(e.IsAssignmentOperation());
  b.setVal54(e.IsComparisonOperation());
  b.setVal55(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ColonColonToken()));
  b.setVal14(es.EntityId(e.DestroyedTypeToken()));
  b.setVal15(es.EntityId(e.OperatorToken()));
  b.setVal20(es.EntityId(e.TildeToken()));
  b.setVal53(e.HasQualifier());
  b.setVal54(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.DoesUsualArrayDeleteWantSize());
  b.setVal9(es.EntityId(e.ConstructExpression()));
  if (auto r14 = e.DirectInitializerRange(); auto rs14 = r14.Size()) {
    b.setVal14(es.EntityId(r14[0]));
    b.setVal15(es.EntityId(r14[rs14 - 1u]));
  } else {
    b.setVal14(0);
    b.setVal15(0);
  }
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.InitializationStyle())));
  b.setVal20(es.EntityId(e.OperatorDelete()));
  b.setVal21(es.EntityId(e.OperatorNew()));
  if (auto r22 = e.TypeIdParentheses(); auto rs22 = r22.Size()) {
    b.setVal22(es.EntityId(r22[0]));
    b.setVal66(es.EntityId(r22[rs22 - 1u]));
  } else {
    b.setVal22(0);
    b.setVal66(0);
  }
  b.setVal54(e.HasInitializer());
  b.setVal55(e.IsArray());
  b.setVal56(e.IsGlobalNew());
  b.setVal57(e.IsParenthesisTypeId());
  b.setVal59(e.PassAlignment());
  b.setVal62(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.ConstructsVirtualBase());
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal9(es.EntityId(e.Constructor()));
  b.setVal14(es.EntityId(e.Token()));
  b.setVal54(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Callee()));
  b.setVal14(es.EntityId(e.EllipsisToken()));
  b.setVal15(es.EntityId(e.LParenToken()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsLeftFold());
  b.setVal54(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.FirstQualifierFoundInScope()));
  b.setVal14(es.EntityId(e.LAngleToken()));
  b.setVal15(es.EntityId(e.MemberToken()));
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal21(es.EntityId(e.RAngleToken()));
  b.setVal22(es.EntityId(e.TemplateKeywordToken()));
  b.setVal53(e.HasExplicitTemplateArguments());
  b.setVal54(e.HasTemplateKeyword());
  b.setVal55(e.IsArrow());
  b.setVal56(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.DoesUsualArrayDeleteWantSize());
  b.setVal9(es.EntityId(e.OperatorDelete()));
  b.setVal54(e.IsArrayForm());
  b.setVal55(e.IsArrayFormAsWritten());
  b.setVal56(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Field()));
  b.setVal14(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Parameter()));
  b.setVal14(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal9(es.EntityId(e.Constructor()));
  b.setVal14(es.EntityId(e.Token()));
  if (auto r15 = e.ParenthesisOrBraceRange(); auto rs15 = r15.Size()) {
    b.setVal15(es.EntityId(r15[0]));
    b.setVal20(es.EntityId(r15[rs15 - 1u]));
  } else {
    b.setVal15(0);
    b.setVal20(0);
  }
  b.setVal53(e.HadMultipleCandidates());
  b.setVal54(e.IsElidable());
  b.setVal55(e.IsListInitialization());
  b.setVal56(e.IsStdInitializerListInitialization());
  b.setVal57(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BlockDeclaration()));
  b.setVal14(es.EntityId(e.CaretToken()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v23 = e.OpcodeString();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal53(e.HasStoredFPFeatures());
  b.setVal54(e.IsAdditiveOperation());
  b.setVal55(e.IsAssignmentOperation());
  b.setVal56(e.IsBitwiseOperation());
  b.setVal57(e.IsCommaOperation());
  b.setVal59(e.IsComparisonOperation());
  b.setVal62(e.IsCompoundAssignmentOperation());
  b.setVal63(e.IsEqualityOperation());
  b.setVal64(e.IsLogicalOperation());
  b.setVal65(e.IsMultiplicativeOperation());
  b.setVal67(e.IsPointerMemoryOperation());
  b.setVal68(e.IsRelationalOperation());
  b.setVal69(e.IsShiftAssignOperation());
  b.setVal70(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Operation())));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsCmpXChg());
  b.setVal54(e.IsOpenCL());
  b.setVal55(e.IsVolatile());
}

void SerializeAsTypeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.RBracketToken()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.CommonExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AmpAmpToken()));
  b.setVal14(es.EntityId(e.Label()));
  b.setVal15(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ColonToken()));
  b.setVal14(es.EntityId(e.QuestionToken()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal15(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.CanOverflow());
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal54(e.HasStoredFPFeatures());
  b.setVal55(e.IsArithmeticOperation());
  b.setVal56(e.IsDecrementOperation());
  b.setVal57(e.IsIncrementDecrementOperation());
  b.setVal59(e.IsIncrementOperation());
  b.setVal62(e.IsPostfix());
  b.setVal63(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal53(e.Value());
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ParameterPack()));
  b.setVal14(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.NameToken()));
  b.setVal14(es.EntityId(e.Parameter()));
  b.setVal53(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.ContainsNonAscii());
  b.setVal54(e.ContainsNonAsciiOrNull());
  auto v23 = e.Bytes();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  auto v28 = e.String();
  std::string s28(v28.data(), v28.size());
  b.setVal28(s28);
  b.setVal55(e.IsAscii());
  b.setVal56(e.IsPascal());
  b.setVal57(e.IsUTF16());
  b.setVal59(e.IsUTF32());
  b.setVal62(e.IsUTF8());
  b.setVal63(e.IsWide());
}

void SerializeStmtExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal15(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v23 = e.BuiltinString();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.IsIntType());
  b.setVal54(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal14(es.EntityId(e.Pack()));
  b.setVal15(es.EntityId(e.PackToken()));
  auto v60 = e.PartialArguments();
  auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
  auto i60 = 0u;
  for (const auto &e60 : v60) {
    auto o60 = es.next_pseudo_entity_offset++;
    sv60.set(i60, o60);
    SerializeTemplateArgument(es, es.pseudo_builder[o60], e60);
    ++i60;
  }
  b.setVal20(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BuiltinToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal23(e.ComputeName());
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.Token()));
  b.setVal15(es.EntityId(e.RParenToken()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  auto v10 = e.LocalParameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  b.setVal14(es.EntityId(e.RBraceToken()));
  b.setVal15(es.EntityId(e.RequiresKWToken()));
  b.setVal53(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.FunctionName()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  auto v23 = e.IdentifierKindName();
  std::string s23(v23.data(), v23.size());
  b.setVal23(s23);
  b.setVal14(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeParenExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParen()));
  b.setVal14(es.EntityId(e.RParen()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.EllipsisToken()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LAngleToken()));
  b.setVal14(es.EntityId(e.NameToken()));
  b.setVal15(es.EntityId(e.NamingClass()));
  b.setVal20(es.EntityId(e.RAngleToken()));
  b.setVal21(es.EntityId(e.TemplateKeywordToken()));
  b.setVal53(e.HasExplicitTemplateArguments());
  b.setVal54(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal22(es.EntityId(e.MemberToken()));
  b.setVal66(es.EntityId(e.OperatorToken()));
  b.setVal55(e.HasUnresolvedUsing());
  b.setVal56(e.IsArrow());
  b.setVal57(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal55(e.IsOverloaded());
  b.setVal56(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.OperatorToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal14(es.EntityId(e.RBracket()));
  b.setVal53(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
  b.setVal14(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
  b.setVal14(es.EntityId(e.Protocol()));
  b.setVal15(es.EntityId(e.ProtocolIdToken()));
  b.setVal20(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ClassReceiver()));
  b.setVal14(es.EntityId(e.ExplicitProperty()));
  b.setVal15(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal20(es.EntityId(e.ImplicitPropertySetter()));
  b.setVal21(es.EntityId(e.Token()));
  b.setVal22(es.EntityId(e.ReceiverToken()));
  b.setVal53(e.IsClassReceiver());
  b.setVal54(e.IsExplicitProperty());
  b.setVal55(e.IsImplicitProperty());
  b.setVal56(e.IsMessagingGetter());
  b.setVal57(e.IsMessagingSetter());
  b.setVal59(e.IsObjectReceiver());
  b.setVal62(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LeftToken()));
  b.setVal14(es.EntityId(e.MethodDeclaration()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal15(es.EntityId(e.ReceiverInterface()));
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ReceiverKind())));
  if (auto r20 = e.ReceiverRange(); auto rs20 = r20.Size()) {
    b.setVal20(es.EntityId(r20[0]));
    b.setVal21(es.EntityId(r20[rs20 - 1u]));
  } else {
    b.setVal20(0);
    b.setVal21(0);
  }
  b.setVal22(es.EntityId(e.RightToken()));
  b.setVal66(es.EntityId(e.SelectorStartToken()));
  b.setVal71(es.EntityId(e.SuperToken()));
  b.setVal53(e.IsClassMessage());
  b.setVal54(e.IsDelegateInitializerCall());
  b.setVal55(e.IsImplicit());
  b.setVal56(e.IsInstanceMessage());
  auto v10 = e.SelectorTokens();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Declaration()));
  b.setVal14(es.EntityId(e.Token()));
  b.setVal15(es.EntityId(e.OperationToken()));
  b.setVal53(e.IsArrow());
  b.setVal54(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.BaseTokenEnd()));
  b.setVal14(es.EntityId(e.IsaMemberToken()));
  b.setVal15(es.EntityId(e.OperationToken()));
  b.setVal53(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.AtToken()));
  b.setVal14(es.EntityId(e.BoxingMethod()));
  b.setVal53(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ArrayWithObjectsMethod()));
}

void SerializeOMPIteratorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.IteratorKwToken()));
  b.setVal14(es.EntityId(e.LParenToken()));
  b.setVal15(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LParenToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ColonTokenFirst()));
  b.setVal14(es.EntityId(e.ColonTokenSecond()));
  b.setVal15(es.EntityId(e.RBracketToken()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.LAngleToken()));
  b.setVal14(es.EntityId(e.MemberDeclaration()));
  b.setVal15(es.EntityId(e.MemberToken()));
  b.setVal20(es.EntityId(e.OperatorToken()));
  b.setVal21(es.EntityId(e.RAngleToken()));
  b.setVal22(es.EntityId(e.TemplateKeywordToken()));
  b.setVal53(e.HadMultipleCandidates());
  b.setVal54(e.HasExplicitTemplateArguments());
  b.setVal55(e.HasQualifier());
  b.setVal56(e.HasTemplateKeyword());
  b.setVal57(e.IsArrow());
  b.setVal59(e.IsImplicitAccess());
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.RBracketToken()));
  b.setVal53(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ExtendingDeclaration()));
  b.setVal14(es.EntityId(e.LifetimeExtendedTemporaryDeclaration()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal53(e.IsBoundToLvalueReference());
  b.setVal54(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.MemberToken()));
  b.setVal14(es.EntityId(e.PropertyDeclaration()));
  b.setVal53(e.IsArrow());
  b.setVal54(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.CallOperator()));
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.CaptureDefault())));
  b.setVal14(es.EntityId(e.CaptureDefaultToken()));
  b.setVal15(es.EntityId(e.CompoundStatementBody()));
  auto v10 = e.ExplicitTemplateParameters();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
  if (auto r20 = e.IntroducerRange(); auto rs20 = r20.Size()) {
    b.setVal20(es.EntityId(r20[0]));
    b.setVal21(es.EntityId(r20[rs20 - 1u]));
  } else {
    b.setVal20(0);
    b.setVal21(0);
  }
  b.setVal22(es.EntityId(e.LambdaClass()));
  auto v72 = e.TemplateParameterList();
  if (v72) {
    auto o72 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o72], v72.value());
    b.setVal72(o72);
    b.setVal53(true);
  } else {
    b.setVal53(false);
  }
  b.setVal54(e.HasExplicitParameters());
  b.setVal55(e.HasExplicitResultType());
  b.setVal56(e.IsGenericLambda());
  b.setVal57(e.IsMutable());
}

void SerializeIntegerLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v9 = e.InitializedFieldInUnion();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal53(true);
    } else {
      b.setVal53(false);
    }
  } else {
    b.setVal53(false);
  }
  b.setVal14(es.EntityId(e.LBraceToken()));
  b.setVal15(es.EntityId(e.RBraceToken()));
  auto v20 = e.SemanticForm();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal54(true);
    } else {
      b.setVal54(false);
    }
  } else {
    b.setVal54(false);
  }
  auto v21 = e.SyntacticForm();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setVal21(id21);
      b.setVal55(true);
    } else {
      b.setVal55(false);
    }
  } else {
    b.setVal55(false);
  }
  b.setVal56(e.HadArrayRangeDesignator());
  b.setVal57(e.HasArrayFiller());
  b.setVal59(e.IsExplicit());
  b.setVal62(e.IsSemanticForm());
  b.setVal63(e.IsStringLiteralInitializer());
  b.setVal64(e.IsSyntacticForm());
  b.setVal65(e.IsTransparent());
}

void SerializeImplicitValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
}

void SerializeGenericSelectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.DefaultToken()));
  b.setVal14(es.EntityId(e.GenericToken()));
  b.setVal15(es.EntityId(e.RParenToken()));
  b.setVal53(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.ParameterPack()));
  b.setVal14(es.EntityId(e.ParameterPackToken()));
  auto v10 = e.Expansions();
  auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
  auto i10 = 0u;
  for (const auto &e10 : v10) {
    sv10.set(i10, es.EntityId(e10));
    ++i10;
  }
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal53(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal53(e.HasAPValueResult());
  b.setVal54(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
  b.setVal53(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal9(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal53(e.ContainsDuplicateElements());
  b.setVal9(es.EntityId(e.AccessorToken()));
  b.setVal54(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal58(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal53(e.Value());
}

void SerializeAttributedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal5(es.EntityId(e.AttributeToken()));
}

void SerializeSwitchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  auto v5 = e.ConditionVariable();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal7(true);
    } else {
      b.setVal7(false);
    }
  } else {
    b.setVal7(false);
  }
  auto v6 = e.ConditionVariableDeclarationStatement();
  if (v6) {
    if (auto id6 = es.EntityId(v6.value())) {
      b.setVal6(id6);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal8(es.EntityId(e.LParenToken()));
  b.setVal9(es.EntityId(e.RParenToken()));
  b.setVal14(es.EntityId(e.SwitchToken()));
  b.setVal12(e.HasInitializerStorage());
  b.setVal13(e.HasVariableStorage());
  b.setVal16(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  b.setVal5(es.EntityId(e.ColonToken()));
  b.setVal6(es.EntityId(e.KeywordToken()));
}

void SerializeDefaultStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal8(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal7(e.CaseStatementIsGNURange());
  b.setVal8(es.EntityId(e.CaseToken()));
  b.setVal9(es.EntityId(e.EllipsisToken()));
}

void SerializeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  b.setVal0(static_cast<unsigned short>(mx::FromPasta(e.Access())));
  b.setVal1(static_cast<unsigned short>(mx::FromPasta(e.AccessUnsafe())));
  b.setVal2(static_cast<unsigned short>(mx::FromPasta(e.Availability())));
  b.setVal3(es.EntityId(e.BeginToken()));
  b.setVal4(es.EntityId(e.BodyRBrace()));
  auto v5 = e.DescribedTemplateParameters();
  if (v5) {
    auto o5 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o5], v5.value());
    b.setVal5(o5);
    b.setVal6(true);
  } else {
    b.setVal6(false);
  }
  b.setVal7(es.EntityId(e.EndToken()));
  b.setVal8(static_cast<unsigned short>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal9(static_cast<unsigned short>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setVal10(e.HasAttributes());
  b.setVal11(e.HasDefiningAttribute());
  b.setVal12(e.HasOwningModule());
  b.setVal13(e.HasTagIdentifierNamespace());
  b.setVal14(e.IsCanonicalDeclaration());
  b.setVal15(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal16(e.IsDeprecated());
  b.setVal17(e.IsFirstDeclaration());
  b.setVal18(e.IsFunctionOrFunctionTemplate());
  b.setVal19(e.IsImplicit());
  b.setVal20(e.IsInAnonymousNamespace());
  b.setVal21(e.IsInLocalScopeForInstantiation());
  b.setVal22(e.IsInStdNamespace());
  b.setVal23(e.IsInvalidDeclaration());
  b.setVal24(e.IsModulePrivate());
  b.setVal25(e.IsOutOfLine());
  b.setVal26(e.IsParameterPack());
  b.setVal27(e.IsReferenced());
  b.setVal28(e.IsTemplateDeclaration());
  b.setVal29(e.IsTemplateParameter());
  b.setVal30(e.IsTemplateParameterPack());
  b.setVal31(e.IsTemplated());
  b.setVal32(e.IsThisDeclarationReferenced());
  b.setVal33(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal34(e.IsUnavailable());
  b.setVal35(e.IsUnconditionallyVisible());
  b.setVal36(e.IsUsed());
  b.setVal37(e.IsWeakImported());
  b.setVal38(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal39(es.EntityId(e.Token()));
  if (auto r40 = e.TokenRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.Specialization()));
  b.setVal43(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.ContextParameter()));
  b.setVal43(e.IsNothrow());
  auto v44 = e.Parameters();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal43(e.BlockMissingReturnType());
  b.setVal46(e.CanAvoidCopyToHeap());
  b.setVal47(e.CapturesCXXThis());
  b.setVal48(e.DoesNotEscape());
  b.setVal42(es.EntityId(e.CaretToken()));
  b.setVal49(es.EntityId(e.CompoundBody()));
  b.setVal50(e.HasCaptures());
  b.setVal51(e.IsConversionFromLambda());
  b.setVal52(e.IsVariadic());
  auto v44 = e.Parameters();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  auto v45 = e.ParameterDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const auto &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.AccessSpecifierToken()));
  b.setVal49(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPRequiresDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.Message()));
  b.setVal49(es.EntityId(e.RParenToken()));
  b.setVal43(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  SerializeDecl(es, b, e);
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  SerializeDecl(es, b, e);
  auto v54 = e.Name();
  std::string s54(v54.data(), v54.size());
  b.setVal54(s54);
  auto v55 = e.Value();
  std::string s55(v55.data(), v55.size());
  b.setVal55(s55);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  SerializeDecl(es, b, e);
  auto v54 = e.Argument();
  std::string s54(v54.data(), v54.size());
  b.setVal54(s54);
  b.setVal56(static_cast<unsigned short>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal49(es.EntityId(e.PropertyDeclaration()));
  b.setVal56(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal57(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal58(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal59(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal43(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal56(static_cast<unsigned short>(mx::FromPasta(e.FormalLinkage())));
  b.setVal60(static_cast<unsigned short>(mx::FromPasta(e.LinkageInternal())));
  b.setVal54(e.Name());
  b.setVal61(static_cast<unsigned short>(mx::FromPasta(e.ObjCFStringFormattingFamily())));
  b.setVal55(e.QualifiedNameAsString());
  b.setVal42(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal62(static_cast<unsigned short>(mx::FromPasta(e.Visibility())));
  b.setVal43(e.HasExternalFormalLinkage());
  b.setVal46(e.HasLinkage());
  b.setVal47(e.HasLinkageBeenComputed());
  b.setVal48(e.IsCXXClassMember());
  b.setVal50(e.IsCXXInstanceMember());
  b.setVal51(e.IsExternallyDeclarable());
  b.setVal52(e.IsExternallyVisible());
  b.setVal63(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v64 = e.MSAssemblyLabel();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal49(es.EntityId(e.Statement()));
  b.setVal65(e.IsGnuLocal());
  b.setVal66(e.IsMSAssemblyLabel());
  b.setVal67(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v44 = e.Shadows();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal49(es.EntityId(e.EnumDeclaration()));
  b.setVal57(es.EntityId(e.EnumToken()));
  b.setVal58(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal49(es.EntityId(e.UsingToken()));
  b.setVal65(e.HasTypename());
  b.setVal66(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal65(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal49(es.EntityId(e.EllipsisToken()));
  b.setVal57(es.EntityId(e.UsingToken()));
  b.setVal66(e.IsAccessDeclaration());
  b.setVal67(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.InitializerKind())));
  b.setVal49(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeMSGuidDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e) {
  SerializeValueDecl(es, b, e);
  auto v44 = e.Chain();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  auto v49 = e.AnonymousField();
  if (v49) {
    if (auto id49 = es.EntityId(v49.value())) {
      b.setVal49(id49);
      b.setVal66(true);
    } else {
      b.setVal66(false);
    }
  } else {
    b.setVal66(false);
  }
  auto v57 = e.VariableDeclaration();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal67(true);
    } else {
      b.setVal67(false);
    }
  } else {
    b.setVal67(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal49(es.EntityId(e.InnerTokenStart()));
  b.setVal57(es.EntityId(e.OuterTokenStart()));
  b.setVal58(es.EntityId(e.TypeSpecEndToken()));
  b.setVal59(es.EntityId(e.TypeSpecStartToken()));
  auto v69 = e.TemplateParameterLists();
  auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
  auto i69 = 0u;
  for (const auto &e69 : v69) {
    auto o69 = es.next_pseudo_entity_offset++;
    sv69.set(i69, o69);
    SerializeTemplateParameterList(es, es.pseudo_builder[o69], e69);
    ++i69;
  }
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.ActingDefinition();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal66(true);
    } else {
      b.setVal66(false);
    }
  } else {
    b.setVal66(false);
  }
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.InitializerStyle())));
  auto v71 = e.InitializingDeclaration();
  if (v71) {
    if (auto id71 = es.EntityId(v71.value())) {
      b.setVal71(id71);
      b.setVal67(true);
    } else {
      b.setVal67(false);
    }
  } else {
    b.setVal67(false);
  }
  auto v72 = e.InstantiatedFromStaticDataMember();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal73(true);
    } else {
      b.setVal73(false);
    }
  } else {
    b.setVal73(false);
  }
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal75(es.EntityId(e.PointOfInstantiation()));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  b.setVal77(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal78(static_cast<unsigned short>(mx::FromPasta(e.TLSKind())));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.TSCSpec())));
  auto v80 = e.TemplateInstantiationPattern();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal82(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal84(e.HasConstantInitialization());
  b.setVal85(e.HasDependentAlignment());
  b.setVal86(e.HasExternalStorage());
  b.setVal87(e.HasGlobalStorage());
  b.setVal88(e.HasInitializer());
  b.setVal89(e.HasLocalStorage());
  b.setVal90(e.IsARCPseudoStrong());
  b.setVal91(e.IsCXXForRangeDeclaration());
  b.setVal92(e.IsConstexpr());
  b.setVal93(e.IsDirectInitializer());
  b.setVal94(e.IsEscapingByref());
  b.setVal95(e.IsExceptionVariable());
  b.setVal96(e.IsExternC());
  b.setVal97(e.IsFileVariableDeclaration());
  b.setVal98(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal99(e.IsInExternCContext());
  b.setVal100(e.IsInExternCXXContext());
  b.setVal101(e.IsInitializerCapture());
  b.setVal102(e.IsInline());
  b.setVal103(e.IsInlineSpecified());
  b.setVal104(e.IsKnownToBeDefined());
  b.setVal105(e.IsLocalVariableDeclaration());
  b.setVal106(e.IsLocalVariableDeclarationOrParm());
  b.setVal107(e.IsNRVOVariable());
  b.setVal108(e.IsNoDestroy());
  b.setVal109(e.IsNonEscapingByref());
  b.setVal110(e.IsObjCForDeclaration());
  b.setVal111(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal112(e.IsStaticDataMember());
  b.setVal113(e.IsStaticLocal());
  b.setVal114(e.IsThisDeclarationADemotedDefinition());
  b.setVal115(e.IsUsableInConstantExpressions());
  b.setVal116(e.MightBeUsableInConstantExpressions());
  b.setVal117(static_cast<unsigned short>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  SerializeVarDecl(es, b, e);
  if (auto r118 = e.DefaultArgumentRange(); auto rs118 = r118.Size()) {
    b.setVal118(es.EntityId(r118[0]));
    b.setVal119(es.EntityId(r118[rs118 - 1u]));
  } else {
    b.setVal118(0);
    b.setVal119(0);
  }
  b.setVal120(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal121(e.HasDefaultArgument());
  b.setVal122(e.HasInheritedDefaultArgument());
  b.setVal123(e.HasUninstantiatedDefaultArgument());
  b.setVal124(e.HasUnparsedDefaultArgument());
  b.setVal125(e.IsDestroyedInCallee());
  b.setVal126(e.IsKNRPromoted());
  b.setVal127(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal120(static_cast<unsigned short>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  SerializeVarDecl(es, b, e);
  auto v44 = e.Bindings();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal118(es.EntityId(e.ExternToken()));
  b.setVal120(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v128 = e.TemplateArguments();
  auto sv128 = b.initVal128(static_cast<unsigned>(v128.size()));
  auto i128 = 0u;
  for (const auto &e128 : v128) {
    auto o128 = es.next_pseudo_entity_offset++;
    sv128.set(i128, o128);
    SerializeTemplateArgument(es, es.pseudo_builder[o128], e128);
    ++i128;
  }
  auto v129 = e.TemplateInstantiationArguments();
  auto sv129 = b.initVal129(static_cast<unsigned>(v129.size()));
  auto i129 = 0u;
  for (const auto &e129 : v129) {
    auto o129 = es.next_pseudo_entity_offset++;
    sv129.set(i129, o129);
    SerializeTemplateArgument(es, es.pseudo_builder[o129], e129);
    ++i129;
  }
  b.setVal119(es.EntityId(e.TemplateKeywordToken()));
  b.setVal121(e.IsClassScopeExplicitSpecialization());
  b.setVal122(e.IsExplicitInstantiationOrSpecialization());
  b.setVal123(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
}

void SerializeNonTypeTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal66(e.DefaultArgumentWasInherited());
  b.setVal70(es.EntityId(e.DefaultArgumentToken()));
  b.setVal67(e.HasDefaultArgument());
  b.setVal73(e.HasPlaceholderTypeConstraint());
  b.setVal81(e.IsExpandedParameterPack());
  b.setVal84(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal66(e.HasGetter());
  b.setVal67(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal66(e.DoesThisDeclarationHaveABody());
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.ConstexprKind())));
  auto v70 = e.Definition();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal67(true);
    } else {
      b.setVal67(false);
    }
  } else {
    b.setVal67(false);
  }
  b.setVal71(es.EntityId(e.EllipsisToken()));
  if (auto r72 = e.ExceptionSpecSourceRange(); auto rs72 = r72.Size()) {
    b.setVal72(es.EntityId(r72[0]));
    b.setVal75(es.EntityId(r72[rs72 - 1u]));
  } else {
    b.setVal72(0);
    b.setVal75(0);
  }
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.ExceptionSpecType())));
  auto v80 = e.InstantiatedFromMemberFunction();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal73(true);
    } else {
      b.setVal73(false);
    }
  } else {
    b.setVal73(false);
  }
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal77(static_cast<unsigned short>(mx::FromPasta(e.MultiVersionKind())));
  b.setVal78(static_cast<unsigned short>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r118 = e.ParametersSourceRange(); auto rs118 = r118.Size()) {
    b.setVal118(es.EntityId(r118[0]));
    b.setVal119(es.EntityId(r118[rs118 - 1u]));
  } else {
    b.setVal118(0);
    b.setVal119(0);
  }
  b.setVal130(es.EntityId(e.PointOfInstantiation()));
  if (auto r131 = e.ReturnTypeSourceRange(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal132(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal132(0);
  }
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  auto v133 = e.TemplateInstantiationPattern();
  if (v133) {
    if (auto id133 = es.EntityId(v133.value())) {
      b.setVal133(id133);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal82(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal117(static_cast<unsigned short>(mx::FromPasta(e.TemplatedKind())));
  b.setVal84(e.HasImplicitReturnZero());
  b.setVal85(e.HasInheritedPrototype());
  b.setVal86(e.HasOneParameterOrDefaultArguments());
  b.setVal87(e.HasPrototype());
  b.setVal88(e.HasSkippedBody());
  b.setVal89(e.HasTrivialBody());
  b.setVal90(e.HasWrittenPrototype());
  b.setVal91(e.InstantiationIsPending());
  b.setVal92(e.IsCPUDispatchMultiVersion());
  b.setVal93(e.IsCPUSpecificMultiVersion());
  b.setVal94(e.IsConsteval());
  b.setVal95(e.IsConstexpr());
  b.setVal96(e.IsConstexprSpecified());
  b.setVal97(e.IsDefaulted());
  b.setVal98(e.IsDeleted());
  b.setVal99(e.IsDeletedAsWritten());
  b.setVal100(e.IsDestroyingOperatorDelete());
  b.setVal101(e.IsExplicitlyDefaulted());
  b.setVal102(e.IsExternC());
  b.setVal103(e.IsFunctionTemplateSpecialization());
  b.setVal104(e.IsGlobal());
  b.setVal105(e.IsImplicitlyInstantiable());
  b.setVal106(e.IsInExternCContext());
  b.setVal107(e.IsInExternCXXContext());
  b.setVal108(e.IsInlineBuiltinDeclaration());
  b.setVal109(e.IsInlineSpecified());
  b.setVal110(e.IsInlined());
  b.setVal111(e.IsLateTemplateParsed());
  b.setVal112(e.IsMSVCRTEntryPoint());
  b.setVal113(e.IsMain());
  b.setVal114(e.IsMultiVersion());
  b.setVal115(e.IsNoReturn());
  b.setVal116(e.IsOverloadedOperator());
  b.setVal121(e.IsPure());
  b.setVal122(e.IsReplaceableGlobalAllocationFunction());
  b.setVal123(e.IsStatic());
  b.setVal124(e.IsTargetMultiVersion());
  b.setVal125(e.IsTemplateInstantiation());
  b.setVal126(e.IsThisDeclarationADefinition());
  b.setVal127(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal134(e.IsTrivial());
  b.setVal135(e.IsTrivialForCall());
  b.setVal136(e.IsUserProvided());
  b.setVal137(e.IsVariadic());
  b.setVal138(e.IsVirtualAsWritten());
  auto v44 = e.Parameters();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  b.setVal139(e.UsesSEHTry());
  b.setVal140(e.WillHaveBody());
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal141(es.EntityId(e.Parent()));
  b.setVal120(static_cast<unsigned short>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal142(e.HasInlineBody());
  b.setVal143(e.IsConst());
  b.setVal144(e.IsCopyAssignmentOperator());
  b.setVal145(e.IsInstance());
  b.setVal146(e.IsLambdaStaticInvoker());
  b.setVal147(e.IsMoveAssignmentOperator());
  b.setVal148(e.IsVirtual());
  b.setVal149(e.IsVolatile());
  auto v53 = e.OverriddenMethods();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal150(es.EntityId(e.OperatorDelete()));
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal151(e.IsExplicit());
  b.setVal152(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal150(es.EntityId(e.TargetConstructor()));
  b.setVal151(e.IsDefaultConstructor());
  b.setVal152(e.IsDelegatingConstructor());
  b.setVal153(e.IsExplicit());
  b.setVal154(e.IsInheritingConstructor());
  b.setVal155(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal141(es.EntityId(e.CorrespondingConstructor()));
  b.setVal142(e.IsCopyDeductionCandidate());
  b.setVal143(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.InClassInitializerStyle())));
  b.setVal70(es.EntityId(e.Parent()));
  b.setVal66(e.HasCapturedVLAType());
  b.setVal67(e.HasInClassInitializer());
  b.setVal73(e.IsAnonymousStructOrUnion());
  b.setVal81(e.IsBitField());
  b.setVal84(e.IsMutable());
  b.setVal85(e.IsUnnamedBitfield());
  b.setVal86(e.IsZeroLengthBitField());
  b.setVal87(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  SerializeFieldDecl(es, b, e);
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.AccessControl())));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal71(es.EntityId(e.ContainingInterface()));
  b.setVal72(es.EntityId(e.NextInstanceVariable()));
  b.setVal88(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal49(es.EntityId(e.DecomposedDeclaration()));
  b.setVal57(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal49(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal49(es.EntityId(e.Introducer()));
  b.setVal57(es.EntityId(e.NextUsingShadowDeclaration()));
  b.setVal58(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  SerializeUsingShadowDecl(es, b, e);
  b.setVal65(e.ConstructsVirtualBase());
  b.setVal59(es.EntityId(e.ConstructedBaseClass()));
  auto v70 = e.ConstructedBaseClassShadowDeclaration();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal66(true);
    } else {
      b.setVal66(false);
    }
  } else {
    b.setVal66(false);
  }
  b.setVal71(es.EntityId(e.NominatedBaseClass()));
  auto v72 = e.NominatedBaseClassShadowDeclaration();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal67(true);
    } else {
      b.setVal67(false);
    }
  } else {
    b.setVal67(false);
  }
  b.setVal75(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v44 = e.Expansions();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  b.setVal49(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal49(es.EntityId(e.IdentifierToken()));
  b.setVal57(es.EntityId(e.NamespaceKeyToken()));
  b.setVal58(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal59(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal65(e.DefaultArgumentWasInherited());
  b.setVal49(es.EntityId(e.DefaultArgumentToken()));
  b.setVal66(e.HasDefaultArgument());
  b.setVal67(e.HasTypeConstraint());
  b.setVal73(e.IsExpandedParameterPack());
  b.setVal81(e.IsPackExpansion());
  b.setVal84(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  SerializeTypeDecl(es, b, e);
  if (auto r49 = e.BraceRange(); auto rs49 = r49.Size()) {
    b.setVal49(es.EntityId(r49[0]));
    b.setVal57(es.EntityId(r49[rs49 - 1u]));
  } else {
    b.setVal49(0);
    b.setVal57(0);
  }
  auto v58 = e.Definition();
  if (v58) {
    if (auto id58 = es.EntityId(v58.value())) {
      b.setVal58(id58);
      b.setVal65(true);
    } else {
      b.setVal65(false);
    }
  } else {
    b.setVal65(false);
  }
  b.setVal59(es.EntityId(e.InnerTokenStart()));
  b.setVal70(es.EntityId(e.OuterTokenStart()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.TagKind())));
  auto v71 = e.TypedefNameForAnonymousDeclaration();
  if (v71) {
    if (auto id71 = es.EntityId(v71.value())) {
      b.setVal71(id71);
      b.setVal66(true);
    } else {
      b.setVal66(false);
    }
  } else {
    b.setVal66(false);
  }
  b.setVal67(e.HasNameForLinkage());
  b.setVal73(e.IsBeingDefined());
  b.setVal81(e.IsClass());
  b.setVal84(e.IsCompleteDefinition());
  b.setVal85(e.IsCompleteDefinitionRequired());
  b.setVal86(e.IsDependentType());
  b.setVal87(e.IsEmbeddedInDeclarator());
  b.setVal88(e.IsEnum());
  b.setVal89(e.IsFreeStanding());
  b.setVal90(e.IsInterface());
  b.setVal91(e.IsStruct());
  b.setVal92(e.IsThisDeclarationADefinition());
  b.setVal93(e.IsUnion());
  b.setVal94(e.MayHaveOutOfDateDefinition());
  auto v69 = e.TemplateParameterLists();
  auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
  auto i69 = 0u;
  for (const auto &e69 : v69) {
    auto o69 = es.next_pseudo_entity_offset++;
    sv69.set(i69, o69);
    SerializeTemplateParameterList(es, es.pseudo_builder[o69], e69);
    ++i69;
  }
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  SerializeTagDecl(es, b, e);
  b.setVal95(e.CanPassInRegisters());
  auto v45 = e.Fields();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const auto &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
  auto v72 = e.FindFirstNamedDataMember();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal96(true);
    } else {
      b.setVal96(false);
    }
  } else {
    b.setVal96(false);
  }
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal97(e.HasFlexibleArrayMember());
  b.setVal98(e.HasLoadedFieldsFromExternalStorage());
  b.setVal99(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal100(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal101(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal102(e.HasObjectMember());
  b.setVal103(e.HasVolatileMember());
  b.setVal104(e.IsAnonymousStructOrUnion());
  b.setVal105(e.IsCapturedRecord());
  b.setVal106(e.IsInjectedClassName());
  b.setVal107(e.IsLambda());
  b.setVal108(e.IsMsStruct());
  b.setVal109(e.IsNonTrivialToPrimitiveCopy());
  b.setVal110(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal111(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal112(e.IsOrContainsUnion());
  b.setVal113(e.IsParameterDestroyedInCallee());
  b.setVal114(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  SerializeRecordDecl(es, b, e);
  b.setVal115(e.AllowConstDefaultInitializer());
  auto v128 = e.Bases();
  auto sv128 = b.initVal128(static_cast<unsigned>(v128.size()));
  auto i128 = 0u;
  for (const auto &e128 : v128) {
    auto o128 = es.next_pseudo_entity_offset++;
    sv128.set(i128, o128);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o128], e128);
    ++i128;
  }
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.CalculateInheritanceModel())));
  auto v53 = e.Constructors();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  b.setVal116(e.DefaultedCopyConstructorIsDeleted());
  b.setVal121(e.DefaultedDefaultConstructorIsConstexpr());
  b.setVal122(e.DefaultedDestructorIsConstexpr());
  b.setVal123(e.DefaultedDestructorIsDeleted());
  b.setVal124(e.DefaultedMoveConstructorIsDeleted());
  auto v156 = e.Friends();
  auto sv156 = b.initVal156(static_cast<unsigned>(v156.size()));
  auto i156 = 0u;
  for (const auto &e156 : v156) {
    sv156.set(i156, es.EntityId(e156));
    ++i156;
  }
  auto v75 = e.Destructor();
  if (v75) {
    if (auto id75 = es.EntityId(v75.value())) {
      b.setVal75(id75);
      b.setVal125(true);
    } else {
      b.setVal125(false);
    }
  } else {
    b.setVal125(false);
  }
  auto v157 = e.GenericLambdaTemplateParameterList();
  if (v157) {
    auto o157 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o157], v157.value());
    b.setVal157(o157);
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  auto v80 = e.InstantiatedFromMemberClass();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal127(true);
    } else {
      b.setVal127(false);
    }
  } else {
    b.setVal127(false);
  }
  auto v118 = e.LambdaCallOperator();
  if (v118) {
    if (auto id118 = es.EntityId(v118.value())) {
      b.setVal118(id118);
      b.setVal134(true);
    } else {
      b.setVal134(false);
    }
  } else {
    b.setVal134(false);
  }
  b.setVal77(static_cast<unsigned short>(mx::FromPasta(e.LambdaCaptureDefault())));
  auto v158 = e.LambdaExplicitTemplateParameters();
  auto sv158 = b.initVal158(static_cast<unsigned>(v158.size()));
  auto i158 = 0u;
  for (const auto &e158 : v158) {
    sv158.set(i158, es.EntityId(e158));
    ++i158;
  }
  b.setVal78(static_cast<unsigned short>(mx::FromPasta(e.MSInheritanceModel())));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.MSVtorDispMode())));
  b.setVal119(es.EntityId(e.MostRecentNonInjectedDeclaration()));
  auto v130 = e.TemplateInstantiationPattern();
  if (v130) {
    if (auto id130 = es.EntityId(v130.value())) {
      b.setVal130(id130);
      b.setVal135(true);
    } else {
      b.setVal135(false);
    }
  } else {
    b.setVal135(false);
  }
  b.setVal82(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal136(e.HasAnyDependentBases());
  b.setVal137(e.HasConstexprDefaultConstructor());
  b.setVal138(e.HasConstexprDestructor());
  b.setVal139(e.HasConstexprNonCopyMoveConstructor());
  b.setVal140(e.HasCopyAssignmentWithConstParameter());
  b.setVal142(e.HasCopyConstructorWithConstParameter());
  b.setVal143(e.HasDefaultConstructor());
  b.setVal144(e.HasDefinition());
  b.setVal145(e.HasDirectFields());
  b.setVal146(e.HasFriends());
  b.setVal147(e.HasInClassInitializer());
  b.setVal148(e.HasInheritedAssignment());
  b.setVal149(e.HasInheritedConstructor());
  b.setVal151(e.HasIrrelevantDestructor());
  b.setVal152(e.HasKnownLambdaInternalLinkage());
  b.setVal153(e.HasMoveAssignment());
  b.setVal154(e.HasMoveConstructor());
  b.setVal155(e.HasMutableFields());
  b.setVal159(e.HasNonLiteralTypeFieldsOrBases());
  b.setVal160(e.HasNonTrivialCopyAssignment());
  b.setVal161(e.HasNonTrivialCopyConstructor());
  b.setVal162(e.HasNonTrivialCopyConstructorForCall());
  b.setVal163(e.HasNonTrivialDefaultConstructor());
  b.setVal164(e.HasNonTrivialDestructor());
  b.setVal165(e.HasNonTrivialDestructorForCall());
  b.setVal166(e.HasNonTrivialMoveAssignment());
  b.setVal167(e.HasNonTrivialMoveConstructor());
  b.setVal168(e.HasNonTrivialMoveConstructorForCall());
  b.setVal169(e.HasPrivateFields());
  b.setVal170(e.HasProtectedFields());
  b.setVal171(e.HasSimpleCopyAssignment());
  b.setVal172(e.HasSimpleCopyConstructor());
  b.setVal173(e.HasSimpleDestructor());
  b.setVal174(e.HasSimpleMoveAssignment());
  b.setVal175(e.HasSimpleMoveConstructor());
  b.setVal176(e.HasTrivialCopyAssignment());
  b.setVal177(e.HasTrivialCopyConstructor());
  b.setVal178(e.HasTrivialCopyConstructorForCall());
  b.setVal179(e.HasTrivialDefaultConstructor());
  b.setVal180(e.HasTrivialDestructor());
  b.setVal181(e.HasTrivialDestructorForCall());
  b.setVal182(e.HasTrivialMoveAssignment());
  b.setVal183(e.HasTrivialMoveConstructor());
  b.setVal184(e.HasTrivialMoveConstructorForCall());
  b.setVal185(e.HasUninitializedReferenceMember());
  b.setVal186(e.HasUserDeclaredConstructor());
  b.setVal187(e.HasUserDeclaredCopyAssignment());
  b.setVal188(e.HasUserDeclaredCopyConstructor());
  b.setVal189(e.HasUserDeclaredDestructor());
  b.setVal190(e.HasUserDeclaredMoveAssignment());
  b.setVal191(e.HasUserDeclaredMoveConstructor());
  b.setVal192(e.HasUserDeclaredMoveOperation());
  b.setVal193(e.HasUserProvidedDefaultConstructor());
  b.setVal194(e.HasVariantMembers());
  b.setVal195(e.ImplicitCopyAssignmentHasConstParameter());
  b.setVal196(e.ImplicitCopyConstructorHasConstParameter());
  b.setVal197(e.IsAbstract());
  b.setVal198(e.IsAggregate());
  b.setVal199(e.IsAnyDestructorNoReturn());
  b.setVal200(e.IsCLike());
  b.setVal201(e.IsCXX11StandardLayout());
  b.setVal202(e.IsDependentLambda());
  b.setVal203(e.IsDynamicClass());
  b.setVal204(e.IsEffectivelyFinal());
  b.setVal205(e.IsEmpty());
  b.setVal206(e.IsGenericLambda());
  b.setVal207(e.IsInterfaceLike());
  b.setVal208(e.IsLiteral());
  auto v131 = e.IsLocalClass();
  if (v131) {
    if (auto id131 = es.EntityId(v131.value())) {
      b.setVal131(id131);
      b.setVal209(true);
    } else {
      b.setVal209(false);
    }
  } else {
    b.setVal209(false);
  }
  b.setVal210(e.IsPOD());
  b.setVal211(e.IsParsingBaseSpecifiers());
  b.setVal212(e.IsPolymorphic());
  b.setVal213(e.IsStandardLayout());
  b.setVal214(e.IsStructural());
  b.setVal215(e.IsTrivial());
  b.setVal216(e.IsTriviallyCopyable());
  b.setVal217(e.LambdaIsDefaultConstructibleAndAssignable());
  b.setVal218(e.MayBeAbstract());
  b.setVal219(e.MayBeDynamicClass());
  b.setVal220(e.MayBeNonDynamicClass());
  auto v221 = e.Methods();
  auto sv221 = b.initVal221(static_cast<unsigned>(v221.size()));
  auto i221 = 0u;
  for (const auto &e221 : v221) {
    sv221.set(i221, es.EntityId(e221));
    ++i221;
  }
  b.setVal222(e.NeedsImplicitCopyAssignment());
  b.setVal223(e.NeedsImplicitCopyConstructor());
  b.setVal224(e.NeedsImplicitDefaultConstructor());
  b.setVal225(e.NeedsImplicitDestructor());
  b.setVal226(e.NeedsImplicitMoveAssignment());
  b.setVal227(e.NeedsImplicitMoveConstructor());
  b.setVal228(e.NeedsOverloadResolutionForCopyAssignment());
  b.setVal229(e.NeedsOverloadResolutionForCopyConstructor());
  b.setVal230(e.NeedsOverloadResolutionForDestructor());
  b.setVal231(e.NeedsOverloadResolutionForMoveAssignment());
  b.setVal232(e.NeedsOverloadResolutionForMoveConstructor());
  b.setVal233(e.NullFieldOffsetIsZero());
  auto v129 = e.VirtualBases();
  auto sv129 = b.initVal129(static_cast<unsigned>(v129.size()));
  auto i129 = 0u;
  for (const auto &e129 : v129) {
    auto o129 = es.next_pseudo_entity_offset++;
    sv129.set(i129, o129);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o129], e129);
    ++i129;
  }
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  SerializeCXXRecordDecl(es, b, e);
  b.setVal132(es.EntityId(e.ExternToken()));
  b.setVal133(es.EntityId(e.PointOfInstantiation()));
  b.setVal83(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v234 = e.TemplateArguments();
  auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
  auto i234 = 0u;
  for (const auto &e234 : v234) {
    auto o234 = es.next_pseudo_entity_offset++;
    sv234.set(i234, o234);
    SerializeTemplateArgument(es, es.pseudo_builder[o234], e234);
    ++i234;
  }
  auto v235 = e.TemplateInstantiationArguments();
  auto sv235 = b.initVal235(static_cast<unsigned>(v235.size()));
  auto i235 = 0u;
  for (const auto &e235 : v235) {
    auto o235 = es.next_pseudo_entity_offset++;
    sv235.set(i235, o235);
    SerializeTemplateArgument(es, es.pseudo_builder[o235], e235);
    ++i235;
  }
  b.setVal141(es.EntityId(e.TemplateKeywordToken()));
  b.setVal236(e.IsClassScopeExplicitSpecialization());
  b.setVal237(e.IsExplicitInstantiationOrSpecialization());
  b.setVal238(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
}

void SerializeEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e) {
  SerializeTagDecl(es, b, e);
  auto v45 = e.Enumerators();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const auto &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
  auto v72 = e.InstantiatedFromMemberEnum();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal95(true);
    } else {
      b.setVal95(false);
    }
  } else {
    b.setVal95(false);
  }
  if (auto r75 = e.IntegerTypeRange(); auto rs75 = r75.Size()) {
    b.setVal75(es.EntityId(r75[0]));
    b.setVal80(es.EntityId(r75[rs75 - 1u]));
  } else {
    b.setVal75(0);
    b.setVal80(0);
  }
  auto v118 = e.TemplateInstantiationPattern();
  if (v118) {
    if (auto id118 = es.EntityId(v118.value())) {
      b.setVal118(id118);
      b.setVal96(true);
    } else {
      b.setVal96(false);
    }
  } else {
    b.setVal96(false);
  }
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal97(e.IsClosed());
  b.setVal98(e.IsClosedFlag());
  b.setVal99(e.IsClosedNonFlag());
  b.setVal100(e.IsComplete());
  b.setVal101(e.IsFixed());
  b.setVal102(e.IsScoped());
  b.setVal103(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal49(es.EntityId(e.EllipsisToken()));
  b.setVal57(es.EntityId(e.TypenameToken()));
  b.setVal58(es.EntityId(e.UsingToken()));
  b.setVal65(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  SerializeTypeDecl(es, b, e);
  auto v49 = e.AnonymousDeclarationWithTypedefName();
  if (v49) {
    if (auto id49 = es.EntityId(v49.value())) {
      b.setVal49(id49);
      b.setVal65(true);
    } else {
      b.setVal65(false);
    }
  } else {
    b.setVal65(false);
  }
  b.setVal66(e.IsModed());
  b.setVal67(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  auto v57 = e.DescribedAliasTemplate();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal73(true);
    } else {
      b.setVal73(false);
    }
  } else {
    b.setVal73(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  b.setVal57(es.EntityId(e.ColonToken()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.Variance())));
  b.setVal58(es.EntityId(e.VarianceToken()));
  b.setVal73(e.HasExplicitBound());
}

void SerializeTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e) {
}

void SerializeRedeclarableTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e) {
}

void SerializeFunctionTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e) {
}

void SerializeClassTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e) {
}

void SerializeVarTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e) {
}

void SerializeTypeAliasTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  SerializeRedeclarableTemplateDecl(es, b, e);
}

void SerializeConceptDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  SerializeTemplateDecl(es, b, e);
  b.setVal65(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e) {
}

void SerializeTemplateTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
}

void SerializeObjCPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal49(es.EntityId(e.AtToken()));
  b.setVal57(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal58(es.EntityId(e.GetterNameToken()));
  b.setVal59(es.EntityId(e.LParenToken()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal70(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.QueryKind())));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.SetterKind())));
  b.setVal71(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal72(es.EntityId(e.SetterNameToken()));
  b.setVal65(e.IsAtomic());
  b.setVal66(e.IsClassProperty());
  b.setVal67(e.IsDirectProperty());
  b.setVal73(e.IsInstanceProperty());
  b.setVal81(e.IsOptional());
  b.setVal84(e.IsReadOnly());
  b.setVal85(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal65(e.DefinedInNSObject());
  b.setVal49(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal57(es.EntityId(e.Category()));
  b.setVal58(es.EntityId(e.ClassInterface()));
  b.setVal59(es.EntityId(e.CmdDeclaration()));
  b.setVal70(es.EntityId(e.DeclaratorEndToken()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.ImplementationControl())));
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal76(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  if (auto r71 = e.ReturnTypeSourceRange(); auto rs71 = r71.Size()) {
    b.setVal71(es.EntityId(r71[0]));
    b.setVal72(es.EntityId(r71[rs71 - 1u]));
  } else {
    b.setVal71(0);
    b.setVal72(0);
  }
  b.setVal75(es.EntityId(e.SelectorStartToken()));
  b.setVal80(es.EntityId(e.SelfDeclaration()));
  b.setVal66(e.HasRedeclaration());
  b.setVal67(e.HasRelatedResultType());
  b.setVal73(e.HasSkippedBody());
  b.setVal81(e.IsClassMethod());
  b.setVal84(e.IsDefined());
  b.setVal85(e.IsDesignatedInitializerForTheInterface());
  b.setVal86(e.IsDirectMethod());
  b.setVal87(e.IsInstanceMethod());
  b.setVal88(e.IsOptional());
  b.setVal89(e.IsOverriding());
  b.setVal90(e.IsPropertyAccessor());
  b.setVal91(e.IsRedeclaration());
  b.setVal92(e.IsSynthesizedAccessorStub());
  b.setVal93(e.IsThisDeclarationADefinition());
  b.setVal94(e.IsThisDeclarationADesignatedInitializer());
  b.setVal95(e.IsVariadic());
  auto v44 = e.Parameters();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  auto v45 = e.SelectorTokens();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const auto &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v44 = e.ClassMethods();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
  auto v45 = e.ClassProperties();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const auto &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
  if (auto r49 = e.AtEndRange(); auto rs49 = r49.Size()) {
    b.setVal49(es.EntityId(r49[0]));
    b.setVal57(es.EntityId(r49[rs49 - 1u]));
  } else {
    b.setVal49(0);
    b.setVal57(0);
  }
  b.setVal58(es.EntityId(e.AtStartToken()));
  auto v53 = e.InstanceMethods();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v156 = e.InstanceProperties();
  auto sv156 = b.initVal156(static_cast<unsigned>(v156.size()));
  auto i156 = 0u;
  for (const auto &e156 : v156) {
    sv156.set(i156, es.EntityId(e156));
    ++i156;
  }
  auto v158 = e.Methods();
  auto sv158 = b.initVal158(static_cast<unsigned>(v158.size()));
  auto i158 = 0u;
  for (const auto &e158 : v158) {
    sv158.set(i158, es.EntityId(e158));
    ++i158;
  }
  auto v221 = e.Properties();
  auto sv221 = b.initVal221(static_cast<unsigned>(v221.size()));
  auto i221 = 0u;
  for (const auto &e221 : v221) {
    sv221.set(i221, es.EntityId(e221));
    ++i221;
  }
  pasta::DeclContext dc239(e);
  auto v239 = dc239.AlreadyLoadedDeclarations();
  auto sv239 = b.initVal239(static_cast<unsigned>(v239.size()));
  auto i239 = 0u;
  for (const pasta::Decl &e239 : v239) {
    sv239.set(i239, es.EntityId(e239));
    ++i239;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal65(e.IsClassExtension());
  b.setVal59(es.EntityId(e.CategoryNameToken()));
  b.setVal70(es.EntityId(e.ClassInterface()));
  b.setVal71(es.EntityId(e.Implementation()));
  b.setVal72(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal75(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal80(es.EntityId(e.NextClassCategory()));
  b.setVal118(es.EntityId(e.NextClassCategoryRaw()));
  auto v240 = e.InstanceVariables();
  auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
  auto i240 = 0u;
  for (const auto &e240 : v240) {
    sv240.set(i240, es.EntityId(e240));
    ++i240;
  }
  auto v241 = e.ProtocolTokens();
  auto sv241 = b.initVal241(static_cast<unsigned>(v241.size()));
  auto i241 = 0u;
  for (const auto &e241 : v241) {
    sv241.set(i241, es.EntityId(e241));
    ++i241;
  }
  auto v242 = e.Protocols();
  auto sv242 = b.initVal242(static_cast<unsigned>(v242.size()));
  auto i242 = 0u;
  for (const auto &e242 : v242) {
    sv242.set(i242, es.EntityId(e242));
    ++i242;
  }
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal59(es.EntityId(e.Definition()));
  auto v64 = e.ObjCRuntimeNameAsString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal65(e.HasDefinition());
  b.setVal66(e.IsNonRuntimeProtocol());
  b.setVal67(e.IsThisDeclarationADefinition());
  auto v240 = e.ProtocolTokens();
  auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
  auto i240 = 0u;
  for (const auto &e240 : v240) {
    sv240.set(i240, es.EntityId(e240));
    ++i240;
  }
  auto v241 = e.Protocols();
  auto sv241 = b.initVal241(static_cast<unsigned>(v241.size()));
  auto i241 = 0u;
  for (const auto &e241 : v241) {
    sv241.set(i241, es.EntityId(e241));
    ++i241;
  }
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  auto v240 = e.AllReferencedProtocols();
  auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
  auto i240 = 0u;
  for (const auto &e240 : v240) {
    sv240.set(i240, es.EntityId(e240));
    ++i240;
  }
  b.setVal65(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal59(es.EntityId(e.CategoryListRaw()));
  b.setVal70(es.EntityId(e.Definition()));
  b.setVal71(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal72(es.EntityId(e.Implementation()));
  auto v64 = e.ObjCRuntimeNameAsString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal75(es.EntityId(e.SuperClass()));
  b.setVal80(es.EntityId(e.SuperClassToken()));
  b.setVal66(e.HasDefinition());
  b.setVal67(e.HasDesignatedInitializers());
  b.setVal73(e.IsArcWeakrefUnavailable());
  b.setVal81(e.IsImplicitInterfaceDeclaration());
  b.setVal118(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal84(e.IsThisDeclarationADefinition());
  auto v241 = e.InstanceVariables();
  auto sv241 = b.initVal241(static_cast<unsigned>(v241.size()));
  auto i241 = 0u;
  for (const auto &e241 : v241) {
    sv241.set(i241, es.EntityId(e241));
    ++i241;
  }
  auto v242 = e.KnownCategories();
  auto sv242 = b.initVal242(static_cast<unsigned>(v242.size()));
  auto i242 = 0u;
  for (const auto &e242 : v242) {
    sv242.set(i242, es.EntityId(e242));
    ++i242;
  }
  auto v243 = e.KnownExtensions();
  auto sv243 = b.initVal243(static_cast<unsigned>(v243.size()));
  auto i243 = 0u;
  for (const auto &e243 : v243) {
    sv243.set(i243, es.EntityId(e243));
    ++i243;
  }
  auto v244 = e.ProtocolTokens();
  auto sv244 = b.initVal244(static_cast<unsigned>(v244.size()));
  auto i244 = 0u;
  for (const auto &e244 : v244) {
    sv244.set(i244, es.EntityId(e244));
    ++i244;
  }
  auto v245 = e.Protocols();
  auto sv245 = b.initVal245(static_cast<unsigned>(v245.size()));
  auto i245 = 0u;
  for (const auto &e245 : v245) {
    sv245.set(i245, es.EntityId(e245));
    ++i245;
  }
  auto v246 = e.VisibleCategories();
  auto sv246 = b.initVal246(static_cast<unsigned>(v246.size()));
  auto i246 = 0u;
  for (const auto &e246 : v246) {
    sv246.set(i246, es.EntityId(e246));
    ++i246;
  }
  auto v247 = e.VisibleExtensions();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    sv247.set(i247, es.EntityId(e247));
    ++i247;
  }
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal59(es.EntityId(e.ClassInterface()));
  auto v240 = e.PropertyImplementations();
  auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
  auto i240 = 0u;
  for (const auto &e240 : v240) {
    sv240.set(i240, es.EntityId(e240));
    ++i240;
  }
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal70(es.EntityId(e.CategoryDeclaration()));
  b.setVal71(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal70(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal71(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v64 = e.ObjCRuntimeNameAsString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal72(es.EntityId(e.SuperClass()));
  b.setVal75(es.EntityId(e.SuperClassToken()));
  b.setVal65(e.HasDestructors());
  b.setVal66(e.HasNonZeroConstructors());
  auto v241 = e.InstanceVariables();
  auto sv241 = b.initVal241(static_cast<unsigned>(v241.size()));
  auto i241 = 0u;
  for (const auto &e241 : v241) {
    sv241.set(i241, es.EntityId(e241));
    ++i241;
  }
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal49(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal49(es.EntityId(e.AliasToken()));
  b.setVal57(es.EntityId(e.AliasedNamespace()));
  b.setVal58(es.EntityId(e.NamespaceToken()));
  b.setVal59(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.ExtendingDeclaration()));
  b.setVal56(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  SerializeDecl(es, b, e);
  auto v44 = e.IdentifierTokens();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const auto &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeFriendTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e) {
}

void SerializeFriendDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.FriendDeclaration()));
  b.setVal49(es.EntityId(e.FriendToken()));
  b.setVal43(e.IsUnsupportedFriend());
  auto v69 = e.FriendTypeTemplateParameterLists();
  auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
  auto i69 = 0u;
  for (const auto &e69 : v69) {
    auto o69 = es.next_pseudo_entity_offset++;
    sv69.set(i69, o69);
    SerializeTemplateParameterList(es, es.pseudo_builder[o69], e69);
    ++i69;
  }
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.AssemblyToken()));
  b.setVal49(es.EntityId(e.AssemblyString()));
  b.setVal57(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.ExportToken()));
  b.setVal49(es.EntityId(e.RBraceToken()));
  b.setVal43(e.HasBraces());
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  SerializeDecl(es, b, e);
}

}  // namespace indexer
