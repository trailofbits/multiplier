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
  parent_decl_id = mx::kInvalidEntityId;
  parent_stmt_id = mx::kInvalidEntityId;
  current_decl_id = mx::kInvalidEntityId;
  current_stmt_id = mx::kInvalidEntityId;
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
  auto v5 = e.RequiresClause();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal6(true);
    } else {
      b.setVal6(false);
    }
  } else {
    b.setVal6(false);
  }
  b.setVal7(es.EntityId(e.TemplateKeywordToken()));
  b.setVal8(es.EntityId(e.LeftAngleToken()));
  b.setVal9(es.EntityId(e.RightAngleToken()));
  if (auto r10 = e.TokenRange(); auto rs10 = r10.Size()) {
    b.setVal10(es.EntityId(r10[0]));
    b.setVal11(es.EntityId(r10[rs10 - 1u]));
  } else {
    b.setVal10(0);
    b.setVal11(0);
  }
  auto v12 = e.Parameters();
  auto sv12 = b.initVal12(static_cast<unsigned>(v12.size()));
  auto i12 = 0u;
  for (const auto &e12 : v12) {
    sv12.set(i12, es.EntityId(e12));
    ++i12;
  }
}

void SerializeTemplateArgument(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
  b.setVal13(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal3(e.IsNull());
  b.setVal4(e.IsDependent());
  b.setVal6(e.IsInstantiationDependent());
  b.setVal14(e.ContainsUnexpandedParameterPack());
  b.setVal15(e.IsPackExpansion());
  auto v5 = e.AsDeclaration();
  if (v5) {
    if (auto id5 = es.EntityId(v5.value())) {
      b.setVal5(id5);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
}

void SerializeCXXBaseSpecifier(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
  if (auto r5 = e.TokenRange(); auto rs5 = r5.Size()) {
    b.setVal5(es.EntityId(r5[0]));
    b.setVal7(es.EntityId(r5[rs5 - 1u]));
  } else {
    b.setVal5(0);
    b.setVal7(0);
  }
  b.setVal8(es.EntityId(e.BaseTypeToken()));
  b.setVal3(e.IsVirtual());
  b.setVal13(static_cast<unsigned short>(mx::FromPasta(e.BaseKind())));
  b.setVal4(e.IsPackExpansion());
  b.setVal6(e.ConstructorsAreInherited());
  auto v9 = e.Ellipsis();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  b.setVal17(static_cast<unsigned short>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal18(static_cast<unsigned short>(mx::FromPasta(e.LexicalAccessSpecifier())));
}

void SerializeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setVal0(es.parent_decl_id);
  b.setVal1(es.parent_stmt_id);
  b.setVal2(es.EntityId(e.IgnoreContainers()));
  auto v3 = e.Children();
  auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
  auto i3 = 0u;
  for (const auto &e3 : v3) {
    sv3.set(i3, es.EntityId(e3));
    ++i3;
  }
  b.setVal4(es.EntityId(e.BeginToken()));
  b.setVal5(es.EntityId(e.EndToken()));
  if (auto r6 = e.TokenRange(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal7(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal7(0);
  }
  b.setVal8(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal9(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ExceptHandler()));
  b.setVal11(es.EntityId(e.FinallyHandler()));
  b.setVal12(es.EntityId(e.Handler()));
  b.setVal13(e.IsCXXTry());
  b.setVal14(es.EntityId(e.TryBlock()));
  b.setVal15(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  b.setVal11(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  b.setVal11(es.EntityId(e.ExceptToken()));
  b.setVal12(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v10 = e.NRVOCandidate();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  auto v11 = e.ReturnValue();
  if (v11) {
    if (auto id11 = es.EntityId(v11.value())) {
      b.setVal11(id11);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  b.setVal12(es.EntityId(e.ReturnToken()));
}

void SerializeObjCForCollectionStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Collection()));
  b.setVal12(es.EntityId(e.Element()));
  b.setVal14(es.EntityId(e.ForToken()));
  b.setVal15(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtToken()));
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtTryToken()));
  b.setVal11(es.EntityId(e.FinallyStatement()));
  b.setVal12(es.EntityId(e.TryBody()));
  auto v17 = e.CatchStatements();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeObjCAtThrowStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ThrowExpression()));
  b.setVal11(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtSynchronizedToken()));
  b.setVal11(es.EntityId(e.SynchBody()));
  b.setVal12(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtFinallyToken()));
  b.setVal11(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtCatchToken()));
  b.setVal11(es.EntityId(e.CatchBody()));
  b.setVal12(es.EntityId(e.CatchParameterDeclaration()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal13(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AssociatedStatement()));
  b.setVal11(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal12(es.EntityId(e.RawStatement()));
  b.setVal14(es.EntityId(e.StructuredBlock()));
  b.setVal13(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TargetCallToken()));
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
  b.setVal15(es.EntityId(e.Expression()));
  b.setVal18(es.EntityId(e.UpdateExpression()));
  b.setVal19(es.EntityId(e.V()));
  b.setVal20(es.EntityId(e.X()));
  b.setVal21(e.IsPostfixUpdate());
  b.setVal22(e.IsXLHSInRHSPart());
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
  b.setVal15(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
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
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPSectionDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPScanDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
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
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPTileDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  auto v17 = e.Counters();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  auto v23 = e.DependentCounters();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
  auto v24 = e.DependentInitializers();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
  auto v25 = e.Finals();
  auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
  auto i25 = 0u;
  for (const auto &e25 : v25) {
    sv25.set(i25, es.EntityId(e25));
    ++i25;
  }
  auto v26 = e.FinalsConditions();
  auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
  auto i26 = 0u;
  for (const auto &e26 : v26) {
    sv26.set(i26, es.EntityId(e26));
    ++i26;
  }
  b.setVal15(es.EntityId(e.Body()));
  b.setVal18(es.EntityId(e.CalculateLastIteration()));
  b.setVal19(es.EntityId(e.CombinedCondition()));
  b.setVal20(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal27(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal28(es.EntityId(e.CombinedInitializer()));
  b.setVal29(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal30(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal31(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal32(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal33(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal34(es.EntityId(e.Condition()));
  b.setVal35(es.EntityId(e.DistanceIncrement()));
  b.setVal36(es.EntityId(e.EnsureUpperBound()));
  b.setVal37(es.EntityId(e.Increment()));
  b.setVal38(es.EntityId(e.Initializer()));
  b.setVal39(es.EntityId(e.IsLastIterationVariable()));
  b.setVal40(es.EntityId(e.IterationVariable()));
  b.setVal41(es.EntityId(e.LastIteration()));
  b.setVal42(es.EntityId(e.LowerBoundVariable()));
  b.setVal43(es.EntityId(e.NextLowerBound()));
  b.setVal44(es.EntityId(e.NextUpperBound()));
  b.setVal45(es.EntityId(e.NumIterations()));
  b.setVal46(es.EntityId(e.PreCondition()));
  b.setVal47(es.EntityId(e.PreInitializers()));
  b.setVal48(es.EntityId(e.PrevEnsureUpperBound()));
  b.setVal49(es.EntityId(e.PrevLowerBoundVariable()));
  b.setVal50(es.EntityId(e.PrevUpperBoundVariable()));
  b.setVal51(es.EntityId(e.StrideVariable()));
  b.setVal52(es.EntityId(e.UpperBoundVariable()));
  auto v53 = e.Initializers();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v54 = e.PrivateCounters();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  auto v55 = e.Updates();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeOMPForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
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
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
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
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPInteropDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.DistanceFunc()));
  b.setVal11(es.EntityId(e.LoopStatement()));
  b.setVal12(es.EntityId(e.LoopVariableFunc()));
  b.setVal14(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.SemiToken()));
  b.setVal13(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.KeywordToken()));
  b.setVal11(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ConstantTarget()));
  b.setVal11(es.EntityId(e.GotoToken()));
  b.setVal12(es.EntityId(e.StarToken()));
  b.setVal14(es.EntityId(e.Target()));
}

void SerializeIfStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.ConditionVariable();
  if (v11) {
    if (auto id11 = es.EntityId(v11.value())) {
      b.setVal11(id11);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  auto v14 = e.Else();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal21(true);
    } else {
      b.setVal21(false);
    }
  } else {
    b.setVal21(false);
  }
  b.setVal15(es.EntityId(e.ElseToken()));
  b.setVal18(es.EntityId(e.IfToken()));
  auto v19 = e.Initializer();
  if (v19) {
    if (auto id19 = es.EntityId(v19.value())) {
      b.setVal19(id19);
      b.setVal22(true);
    } else {
      b.setVal22(false);
    }
  } else {
    b.setVal22(false);
  }
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal27(es.EntityId(e.RParenToken()));
  b.setVal28(es.EntityId(e.Then()));
  b.setVal57(e.HasElseStorage());
  b.setVal58(e.HasInitializerStorage());
  b.setVal59(e.HasVariableStorage());
  b.setVal60(e.IsConstexpr());
  b.setVal61(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.GotoToken()));
  b.setVal11(es.EntityId(e.Label()));
  b.setVal12(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  auto v11 = e.Condition();
  if (v11) {
    if (auto id11 = es.EntityId(v11.value())) {
      b.setVal11(id11);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  auto v12 = e.ConditionVariable();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal21(true);
    } else {
      b.setVal21(false);
    }
  } else {
    b.setVal21(false);
  }
  b.setVal15(es.EntityId(e.ForToken()));
  auto v18 = e.Increment();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal22(true);
    } else {
      b.setVal22(false);
    }
  } else {
    b.setVal22(false);
  }
  auto v19 = e.Initializer();
  if (v19) {
    if (auto id19 = es.EntityId(v19.value())) {
      b.setVal19(id19);
      b.setVal57(true);
    } else {
      b.setVal57(false);
    }
  } else {
    b.setVal57(false);
  }
  b.setVal20(es.EntityId(e.LParenToken()));
  b.setVal27(es.EntityId(e.RParenToken()));
}

void SerializeDoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  b.setVal12(es.EntityId(e.DoToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal15(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  auto v17 = e.Declarations();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  auto v10 = e.SingleDeclaration();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal16(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Allocate()));
  b.setVal11(es.EntityId(e.Body()));
  b.setVal12(es.EntityId(e.Deallocate()));
  b.setVal14(es.EntityId(e.ExceptionHandler()));
  b.setVal15(es.EntityId(e.FallthroughHandler()));
  b.setVal18(es.EntityId(e.FinalSuspendStatement()));
  b.setVal19(es.EntityId(e.InitializerSuspendStatement()));
  auto v17 = e.ParameterMoves();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal20(es.EntityId(e.PromiseDeclaration()));
  b.setVal27(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal28(es.EntityId(e.ResultDeclaration()));
  b.setVal29(es.EntityId(e.ReturnStatement()));
  b.setVal30(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal31(es.EntityId(e.ReturnValueInitializer()));
  b.setVal13(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.KeywordToken()));
  b.setVal11(es.EntityId(e.Operand()));
  b.setVal12(es.EntityId(e.PromiseCall()));
  b.setVal13(e.IsImplicit());
}

void SerializeContinueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.LeftBraceToken()));
  b.setVal11(es.EntityId(e.RightBraceToken()));
  auto v12 = e.StatementExpressionResult();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
}

void SerializeCapturedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.CapturedDeclaration()));
  b.setVal11(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal62(static_cast<unsigned short>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal12(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.TryBlock()));
  b.setVal11(es.EntityId(e.TryToken()));
  auto v17 = e.Handlers();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeCXXForRangeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.BeginStatement()));
  b.setVal11(es.EntityId(e.Body()));
  b.setVal12(es.EntityId(e.CoawaitToken()));
  b.setVal14(es.EntityId(e.ColonToken()));
  b.setVal15(es.EntityId(e.Condition()));
  b.setVal18(es.EntityId(e.EndStatement()));
  b.setVal19(es.EntityId(e.ForToken()));
  b.setVal20(es.EntityId(e.Increment()));
  b.setVal27(es.EntityId(e.Initializer()));
  b.setVal28(es.EntityId(e.LoopVariableStatement()));
  b.setVal29(es.EntityId(e.LoopVariable()));
  b.setVal30(es.EntityId(e.RParenToken()));
  b.setVal31(es.EntityId(e.RangeInitializer()));
  b.setVal32(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.CatchToken()));
  b.setVal11(es.EntityId(e.ExceptionDeclaration()));
  b.setVal12(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal63(e.GenerateAssemblyString());
  b.setVal10(es.EntityId(e.AssemblyToken()));
  auto v17 = e.Inputs();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal13(e.IsSimple());
  b.setVal16(e.IsVolatile());
  auto v23 = e.Outputs();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
  auto v64 = e.OutputConstraints();
  auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
  auto i64 = 0u;
  for (const auto &e64 : v64) {
    std::string se64(e64.data(), e64.size());
    sv64.set(i64, se64);
    ++i64;
  }
  auto v24 = e.OutputExpressions();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
  auto v65 = e.InputConstraints();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    std::string se65(e65.data(), e65.size());
    sv65.set(i65, se65);
    ++i65;
  }
  auto v25 = e.InputExpressions();
  auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
  auto i25 = 0u;
  for (const auto &e25 : v25) {
    sv25.set(i25, es.EntityId(e25));
    ++i25;
  }
  auto v66 = e.Clobbers();
  auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
  auto i66 = 0u;
  for (const auto &e66 : v66) {
    std::string se66(e66.data(), e66.size());
    sv66.set(i66, se66);
    ++i66;
  }
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  auto v67 = e.AllConstraints();
  auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
  auto i67 = 0u;
  for (const auto &e67 : v67) {
    std::string se67(e67.data(), e67.size());
    sv67.set(i67, se67);
    ++i67;
  }
  auto v26 = e.AllExpressions();
  auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
  auto i26 = 0u;
  for (const auto &e26 : v26) {
    sv26.set(i26, es.EntityId(e26));
    ++i26;
  }
  auto v68 = e.AssemblyString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal11(es.EntityId(e.LBraceToken()));
  b.setVal21(e.HasBraces());
}

void SerializeGCCAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal11(es.EntityId(e.AssemblyString()));
  b.setVal12(es.EntityId(e.RParenToken()));
  b.setVal21(e.IsAssemblyGoto());
  auto v26 = e.Labels();
  auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
  auto i26 = 0u;
  for (const auto &e26 : v26) {
    sv26.set(i26, es.EntityId(e26));
    ++i26;
  }
  auto v53 = e.OutputConstraintLiterals();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v67 = e.OutputNames();
  auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
  auto i67 = 0u;
  for (const auto &e67 : v67) {
    std::string se67(e67.data(), e67.size());
    sv67.set(i67, se67);
    ++i67;
  }
  auto v54 = e.InputConstraintLiterals();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  auto v69 = e.InputNames();
  auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
  auto i69 = 0u;
  for (const auto &e69 : v69) {
    std::string se69(e69.data(), e69.size());
    sv69.set(i69, se69);
    ++i69;
  }
  auto v55 = e.ClobberStringLiterals();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  auto v70 = e.LabelExpressions();
  auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
  auto i70 = 0u;
  for (const auto &e70 : v70) {
    sv70.set(i70, es.EntityId(e70));
    ++i70;
  }
  auto v71 = e.LabelNames();
  auto sv71 = b.initVal71(static_cast<unsigned>(v71.size()));
  auto i71 = 0u;
  for (const auto &e71 : v71) {
    std::string se71(e71.data(), e71.size());
    sv71.set(i71, se71);
    ++i71;
  }
}

void SerializeWhileStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto v12 = e.ConditionVariable();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  b.setVal15(es.EntityId(e.LParenToken()));
  b.setVal18(es.EntityId(e.RParenToken()));
  b.setVal19(es.EntityId(e.WhileToken()));
  b.setVal21(e.HasVariableStorage());
}

void SerializeValueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v10 = e.ExpressionStatement();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
}

void SerializeLabelStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal11(es.EntityId(e.Declaration()));
  b.setVal12(es.EntityId(e.IdentifierToken()));
  auto v63 = e.Name();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal14(es.EntityId(e.SubStatement()));
  b.setVal16(e.IsSideEntry());
}

void SerializeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal16(e.HasSideEffects());
  b.setVal11(es.EntityId(e.IgnoreCasts()));
  b.setVal12(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal14(es.EntityId(e.IgnoreImpCasts()));
  b.setVal15(es.EntityId(e.IgnoreImplicit()));
  b.setVal18(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal19(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal20(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal27(es.EntityId(e.IgnoreParenthesisImpCasts()));
  b.setVal28(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal29(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal30(es.EntityId(e.IgnoreParentheses()));
  b.setVal31(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal21(e.ContainsErrors());
  b.setVal22(e.ContainsUnexpandedParameterPack());
  b.setVal32(es.EntityId(e.BestDynamicClassTypeExpression()));
  b.setVal33(es.EntityId(e.ExpressionToken()));
  auto v34 = e.ObjCProperty();
  if (v34) {
    if (auto id34 = es.EntityId(v34.value())) {
      b.setVal34(id34);
      b.setVal57(true);
    } else {
      b.setVal57(false);
    }
  } else {
    b.setVal57(false);
  }
  b.setVal62(static_cast<unsigned short>(mx::FromPasta(e.ObjectKind())));
  auto v35 = e.ReferencedDeclarationOfCallee();
  if (v35) {
    if (auto id35 = es.EntityId(v35.value())) {
      b.setVal35(id35);
      b.setVal58(true);
    } else {
      b.setVal58(false);
    }
  } else {
    b.setVal58(false);
  }
  auto v36 = e.SourceBitField();
  if (v36) {
    if (auto id36 = es.EntityId(v36.value())) {
      b.setVal36(id36);
      b.setVal59(true);
    } else {
      b.setVal59(false);
    }
  } else {
    b.setVal59(false);
  }
  b.setVal72(static_cast<unsigned short>(mx::FromPasta(e.ValueKind())));
  b.setVal60(e.HasNonTrivialCall());
  b.setVal61(e.IsDefaultArgument());
  b.setVal73(e.IsGLValue());
  b.setVal74(e.IsImplicitCXXThis());
  b.setVal75(e.IsInstantiationDependent());
  b.setVal76(e.IsKnownToHaveBooleanValue());
  b.setVal77(e.IsLValue());
  b.setVal78(e.IsOBJCGCCandidate());
  b.setVal79(e.IsObjCSelfExpression());
  b.setVal80(e.IsOrdinaryOrBitFieldObject());
  b.setVal81(e.IsPRValue());
  b.setVal82(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal83(e.IsTypeDependent());
  b.setVal84(e.IsValueDependent());
  b.setVal85(e.IsXValue());
  b.setVal86(e.RefersToBitField());
  b.setVal87(e.RefersToGlobalRegisterVariable());
  b.setVal88(e.RefersToMatrixElement());
  b.setVal89(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r37 = e.DesignatorsSourceRange(); auto rs37 = r37.Size()) {
    b.setVal37(es.EntityId(r37[0]));
    b.setVal38(es.EntityId(r37[rs37 - 1u]));
  } else {
    b.setVal37(0);
    b.setVal38(0);
  }
  b.setVal39(es.EntityId(e.EqualOrColonToken()));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal90(e.IsDirectInitializer());
  b.setVal91(e.UsesGNUSyntax());
  auto v17 = e.SubExpressions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.RAngleToken()));
  b.setVal39(es.EntityId(e.TemplateKeywordToken()));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.KeywordToken()));
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal39(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Declaration()));
  b.setVal38(es.EntityId(e.FoundDeclaration()));
  b.setVal39(es.EntityId(e.LAngleToken()));
  b.setVal40(es.EntityId(e.RAngleToken()));
  b.setVal41(es.EntityId(e.TemplateKeywordToken()));
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKWAndArgumentsInfo());
  b.setVal94(e.HasTemplateKeyword());
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal96(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.CommonExpression()));
  b.setVal38(es.EntityId(e.KeywordToken()));
  b.setVal39(es.EntityId(e.OpaqueValue()));
  b.setVal40(es.EntityId(e.ReadyExpression()));
  b.setVal41(es.EntityId(e.ResumeExpression()));
  b.setVal42(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal43(es.EntityId(e.Operand()));
  b.setVal90(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal43(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  auto v97 = e.TemplateArguments();
  auto sv97 = b.initVal97(static_cast<unsigned>(v97.size()));
  auto i97 = 0u;
  for (const auto &e97 : v97) {
    auto o97 = es.next_pseudo_entity_offset++;
    sv97.set(i97, o97);
    SerializeTemplateArgument(es, es.pseudo_builder[o97], e97);
    ++i97;
  }
  b.setVal90(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Initializer()));
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal90(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.ChosenSubExpression()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.RParenToken()));
  b.setVal90(e.IsConditionDependent());
  b.setVal91(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.CastKind())));
  auto v63 = e.CastKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v37 = e.ConversionFunction();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.SubExpressionAsWritten()));
  auto v40 = e.TargetUnionField();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal92(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal93(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r41 = e.AngleBrackets(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  auto v68 = e.CastName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal43(es.EntityId(e.OperatorToken()));
  b.setVal44(es.EntityId(e.RParenToken()));
}

void SerializeCXXDynamicCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal93(e.IsAlwaysNull());
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
  b.setVal41(es.EntityId(e.LParenToken()));
  b.setVal42(es.EntityId(e.RParenToken()));
  b.setVal93(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal41(es.EntityId(e.LParenToken()));
  b.setVal42(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal41(es.EntityId(e.BridgeKeywordToken()));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal42(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.Arguments();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.ADLCallKind())));
  b.setVal37(es.EntityId(e.Callee()));
  auto v38 = e.CalleeDeclaration();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  auto v39 = e.DirectCallee();
  if (v39) {
    if (auto id39 = es.EntityId(v39.value())) {
      b.setVal39(id39);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal92(e.HasStoredFPFeatures());
  b.setVal93(e.HasUnusedResultAttribute());
  b.setVal94(e.IsBuiltinAssumeFalse());
  b.setVal96(e.IsCallToStdMove());
  b.setVal99(e.IsUnevaluatedBuiltinCall());
  b.setVal100(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal101(e.IsAssignmentOperation());
  b.setVal102(e.IsComparisonOperation());
  b.setVal103(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.ImplicitObjectArgument()));
  b.setVal42(es.EntityId(e.MethodDeclaration()));
  b.setVal43(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.CookedLiteral()));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal42(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ExpressionOperand()));
  b.setVal38(es.EntityId(e.GuidDeclaration()));
  b.setVal90(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.Arguments();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal90(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ExpressionOperand()));
  b.setVal90(e.IsMostDerived());
  b.setVal91(e.IsPotentiallyEvaluated());
  b.setVal92(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal38(es.EntityId(e.ThrowToken()));
  b.setVal90(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal90(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.RParenToken()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal90(e.IsAssignmentOperation());
  b.setVal91(e.IsComparisonOperation());
  b.setVal92(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColonColonToken()));
  b.setVal39(es.EntityId(e.DestroyedTypeToken()));
  b.setVal40(es.EntityId(e.OperatorToken()));
  b.setVal41(es.EntityId(e.TildeToken()));
  b.setVal90(e.HasQualifier());
  b.setVal91(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal90(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  auto v37 = e.ArraySize();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal38(es.EntityId(e.ConstructExpression()));
  if (auto r39 = e.DirectInitializerRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.InitializationStyle())));
  b.setVal41(es.EntityId(e.Initializer()));
  b.setVal42(es.EntityId(e.OperatorDelete()));
  b.setVal43(es.EntityId(e.OperatorNew()));
  if (auto r44 = e.TypeIdParentheses(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal92(e.HasInitializer());
  b.setVal93(e.IsArray());
  b.setVal94(e.IsGlobalNew());
  b.setVal96(e.IsParenthesisTypeId());
  b.setVal99(e.PassAlignment());
  auto v17 = e.PlacementArguments();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal100(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ConstructsVirtualBase());
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  b.setVal38(es.EntityId(e.Token()));
  b.setVal91(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Callee()));
  b.setVal38(es.EntityId(e.EllipsisToken()));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.LParenToken()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  b.setVal44(es.EntityId(e.RParenToken()));
  b.setVal90(e.IsLeftFold());
  b.setVal91(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.FirstQualifierFoundInScope()));
  b.setVal39(es.EntityId(e.LAngleToken()));
  b.setVal40(es.EntityId(e.MemberToken()));
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal42(es.EntityId(e.RAngleToken()));
  b.setVal43(es.EntityId(e.TemplateKeywordToken()));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  b.setVal38(es.EntityId(e.OperatorDelete()));
  b.setVal91(e.IsArrayForm());
  b.setVal92(e.IsArrayFormAsWritten());
  b.setVal93(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Expression()));
  b.setVal38(es.EntityId(e.Field()));
  b.setVal39(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Expression()));
  b.setVal38(es.EntityId(e.Parameter()));
  b.setVal39(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.Arguments();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  b.setVal38(es.EntityId(e.Token()));
  if (auto r39 = e.ParenthesisOrBraceRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.IsElidable());
  b.setVal92(e.IsListInitialization());
  b.setVal93(e.IsStdInitializerListInitialization());
  b.setVal94(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal90(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BlockDeclaration()));
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CaretToken()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.IsAdditiveOperation());
  b.setVal92(e.IsAssignmentOperation());
  b.setVal93(e.IsBitwiseOperation());
  b.setVal94(e.IsCommaOperation());
  b.setVal96(e.IsComparisonOperation());
  b.setVal99(e.IsCompoundAssignmentOperation());
  b.setVal100(e.IsEqualityOperation());
  b.setVal101(e.IsLogicalOperation());
  b.setVal102(e.IsMultiplicativeOperation());
  b.setVal103(e.IsPointerMemoryOperation());
  b.setVal104(e.IsRelationalOperation());
  b.setVal105(e.IsShiftAssignOperation());
  b.setVal106(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Operation())));
  b.setVal38(es.EntityId(e.Order()));
  auto v39 = e.OrderFail();
  if (v39) {
    if (auto id39 = es.EntityId(v39.value())) {
      b.setVal39(id39);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  b.setVal40(es.EntityId(e.Pointer()));
  b.setVal41(es.EntityId(e.RParenToken()));
  auto v42 = e.Scope();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  auto v43 = e.Value1();
  if (v43) {
    if (auto id43 = es.EntityId(v43.value())) {
      b.setVal43(id43);
      b.setVal92(true);
    } else {
      b.setVal92(false);
    }
  } else {
    b.setVal92(false);
  }
  auto v44 = e.Value2();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal93(true);
    } else {
      b.setVal93(false);
    }
  } else {
    b.setVal93(false);
  }
  auto v45 = e.Weak();
  if (v45) {
    if (auto id45 = es.EntityId(v45.value())) {
      b.setVal45(id45);
      b.setVal94(true);
    } else {
      b.setVal94(false);
    }
  } else {
    b.setVal94(false);
  }
  b.setVal96(e.IsCmpXChg());
  b.setVal99(e.IsOpenCL());
  b.setVal100(e.IsVolatile());
  auto v17 = e.SubExpressions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeAsTypeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.DimensionExpression()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal40(es.EntityId(e.RBracketToken()));
  b.setVal41(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.CommonExpression()));
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AmpAmpToken()));
  b.setVal38(es.EntityId(e.Label()));
  b.setVal39(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ColonToken()));
  b.setVal38(es.EntityId(e.Condition()));
  b.setVal39(es.EntityId(e.FalseExpression()));
  b.setVal40(es.EntityId(e.QuestionToken()));
  b.setVal41(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal42(es.EntityId(e.Common()));
  b.setVal43(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.CanOverflow());
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  b.setVal37(es.EntityId(e.OperatorToken()));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal91(e.HasStoredFPFeatures());
  b.setVal92(e.IsArithmeticOperation());
  b.setVal93(e.IsDecrementOperation());
  b.setVal94(e.IsIncrementDecrementOperation());
  b.setVal96(e.IsIncrementOperation());
  b.setVal99(e.IsPostfix());
  b.setVal100(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ArgumentExpression();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal91(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal90(e.Value());
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ParameterPack()));
  b.setVal38(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.NameToken()));
  b.setVal38(es.EntityId(e.Parameter()));
  b.setVal39(es.EntityId(e.Replacement()));
  b.setVal90(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ContainsNonAscii());
  b.setVal91(e.ContainsNonAsciiOrNull());
  auto v63 = e.Bytes();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v68 = e.String();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal92(e.IsAscii());
  b.setVal93(e.IsPascal());
  b.setVal94(e.IsUTF16());
  b.setVal96(e.IsUTF32());
  b.setVal99(e.IsUTF8());
  b.setVal100(e.IsWide());
}

void SerializeStmtExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v63 = e.BuiltinString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  b.setVal37(es.EntityId(e.Token()));
  b.setVal90(e.IsIntType());
  b.setVal91(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.OperatorToken()));
  b.setVal38(es.EntityId(e.Pack()));
  b.setVal39(es.EntityId(e.PackToken()));
  auto v97 = e.PartialArguments();
  auto sv97 = b.initVal97(static_cast<unsigned>(v97.size()));
  auto i97 = 0u;
  for (const auto &e97 : v97) {
    auto o97 = es.next_pseudo_entity_offset++;
    sv97.set(i97, o97);
    SerializeTemplateArgument(es, es.pseudo_builder[o97], e97);
    ++i97;
  }
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal90(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal63(e.ComputeName());
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.Token()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  auto v17 = e.LocalParameters();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal38(es.EntityId(e.RBraceToken()));
  b.setVal39(es.EntityId(e.RequiresKWToken()));
  b.setVal90(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.SubExpressions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ResultExpression()));
  b.setVal38(es.EntityId(e.SyntacticForm()));
  auto v17 = e.Semantics();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  auto v23 = e.SemanticExpressions();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.FunctionName()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  auto v63 = e.IdentifierKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  auto v17 = e.Expressions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeParenExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LParen()));
  b.setVal38(es.EntityId(e.RParen()));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.EllipsisToken()));
  b.setVal38(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.NameToken()));
  b.setVal39(es.EntityId(e.NamingClass()));
  b.setVal40(es.EntityId(e.RAngleToken()));
  b.setVal41(es.EntityId(e.TemplateKeywordToken()));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal42(es.EntityId(e.Base()));
  b.setVal43(es.EntityId(e.MemberToken()));
  b.setVal44(es.EntityId(e.OperatorToken()));
  b.setVal92(e.HasUnresolvedUsing());
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal92(e.IsOverloaded());
  b.setVal93(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal90(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.OperatorToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.KeyExpression()));
  b.setVal40(es.EntityId(e.RBracket()));
  b.setVal90(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtToken()));
  b.setVal38(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtToken()));
  b.setVal38(es.EntityId(e.Protocol()));
  b.setVal39(es.EntityId(e.ProtocolIdToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ExplicitProperty()));
  b.setVal40(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal41(es.EntityId(e.ImplicitPropertySetter()));
  b.setVal42(es.EntityId(e.Token()));
  b.setVal43(es.EntityId(e.ReceiverToken()));
  b.setVal90(e.IsClassReceiver());
  b.setVal91(e.IsExplicitProperty());
  b.setVal92(e.IsImplicitProperty());
  b.setVal93(e.IsMessagingGetter());
  b.setVal94(e.IsMessagingSetter());
  b.setVal96(e.IsObjectReceiver());
  b.setVal99(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.Arguments();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal37(es.EntityId(e.InstanceReceiver()));
  b.setVal38(es.EntityId(e.LeftToken()));
  b.setVal39(es.EntityId(e.MethodDeclaration()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal40(es.EntityId(e.ReceiverInterface()));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.ReceiverKind())));
  if (auto r41 = e.ReceiverRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal43(es.EntityId(e.RightToken()));
  b.setVal44(es.EntityId(e.SelectorStartToken()));
  b.setVal45(es.EntityId(e.SuperToken()));
  b.setVal90(e.IsClassMessage());
  b.setVal91(e.IsDelegateInitializerCall());
  b.setVal92(e.IsImplicit());
  b.setVal93(e.IsInstanceMessage());
  auto v23 = e.SelectorTokens();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Declaration()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal40(es.EntityId(e.OperationToken()));
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.BaseTokenEnd()));
  b.setVal39(es.EntityId(e.IsaMemberToken()));
  b.setVal40(es.EntityId(e.OperationToken()));
  b.setVal90(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal90(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtToken()));
  b.setVal38(es.EntityId(e.BoxingMethod()));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal90(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ArrayWithObjectsMethod()));
  auto v17 = e.Elements();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeOMPIteratorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.IteratorKwToken()));
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto v17 = e.Dimensions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColonTokenFirst()));
  b.setVal39(es.EntityId(e.ColonTokenSecond()));
  b.setVal40(es.EntityId(e.Length()));
  b.setVal41(es.EntityId(e.LowerBound()));
  b.setVal42(es.EntityId(e.RBracketToken()));
  b.setVal43(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.LAngleToken()));
  b.setVal39(es.EntityId(e.MemberDeclaration()));
  b.setVal40(es.EntityId(e.MemberToken()));
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal42(es.EntityId(e.RAngleToken()));
  b.setVal43(es.EntityId(e.TemplateKeywordToken()));
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKeyword());
  b.setVal94(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  b.setVal39(es.EntityId(e.RBracketToken()));
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal90(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ExtendingDeclaration()));
  b.setVal38(es.EntityId(e.LifetimeExtendedTemporaryDeclaration()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsBoundToLvalueReference());
  b.setVal91(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  b.setVal39(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BaseExpression()));
  b.setVal38(es.EntityId(e.MemberToken()));
  b.setVal39(es.EntityId(e.PropertyDeclaration()));
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.CaptureDefault())));
  b.setVal39(es.EntityId(e.CaptureDefaultToken()));
  b.setVal40(es.EntityId(e.CompoundStatementBody()));
  auto v17 = e.ExplicitTemplateParameters();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  if (auto r41 = e.IntroducerRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal43(es.EntityId(e.LambdaClass()));
  auto v107 = e.TemplateParameterList();
  if (v107) {
    auto o107 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o107], v107.value());
    b.setVal107(o107);
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  auto v44 = e.TrailingRequiresClause();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal92(e.HasExplicitParameters());
  b.setVal93(e.HasExplicitResultType());
  b.setVal94(e.IsGenericLambda());
  b.setVal96(e.IsMutable());
}

void SerializeIntegerLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ArrayFiller();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  auto v38 = e.InitializedFieldInUnion();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal91(true);
    } else {
      b.setVal91(false);
    }
  } else {
    b.setVal91(false);
  }
  b.setVal39(es.EntityId(e.LBraceToken()));
  b.setVal40(es.EntityId(e.RBraceToken()));
  auto v41 = e.SemanticForm();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
      b.setVal92(true);
    } else {
      b.setVal92(false);
    }
  } else {
    b.setVal92(false);
  }
  auto v42 = e.SyntacticForm();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal93(true);
    } else {
      b.setVal93(false);
    }
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.HadArrayRangeDesignator());
  b.setVal96(e.HasArrayFiller());
  auto v17 = e.Initializers();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal99(e.IsExplicit());
  b.setVal100(e.IsSemanticForm());
  b.setVal101(e.IsStringLiteralInitializer());
  b.setVal102(e.IsSyntacticForm());
  b.setVal103(e.IsTransparent());
}

void SerializeImplicitValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  auto v17 = e.AssociationExpressions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
  b.setVal37(es.EntityId(e.ControllingExpression()));
  b.setVal38(es.EntityId(e.DefaultToken()));
  b.setVal39(es.EntityId(e.GenericToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal41(es.EntityId(e.ResultExpression()));
  b.setVal90(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ParameterPack()));
  b.setVal38(es.EntityId(e.ParameterPackToken()));
  auto v17 = e.Expansions();
  auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
  auto i17 = 0u;
  for (const auto &e17 : v17) {
    sv17.set(i17, es.EntityId(e17));
    ++i17;
  }
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal90(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal90(e.HasAPValueResult());
  b.setVal91(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal90(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ContainsDuplicateElements());
  b.setVal37(es.EntityId(e.AccessorToken()));
  b.setVal38(es.EntityId(e.Base()));
  b.setVal91(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal90(e.Value());
}

void SerializeAttributedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal11(es.EntityId(e.AttributeToken()));
  b.setVal12(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto v12 = e.ConditionVariable();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  auto v15 = e.Initializer();
  if (v15) {
    if (auto id15 = es.EntityId(v15.value())) {
      b.setVal15(id15);
      b.setVal21(true);
    } else {
      b.setVal21(false);
    }
  } else {
    b.setVal21(false);
  }
  b.setVal18(es.EntityId(e.LParenToken()));
  b.setVal19(es.EntityId(e.RParenToken()));
  auto v20 = e.FirstSwitchCase();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal22(true);
    } else {
      b.setVal22(false);
    }
  } else {
    b.setVal22(false);
  }
  b.setVal27(es.EntityId(e.SwitchToken()));
  b.setVal57(e.HasInitializerStorage());
  b.setVal58(e.HasVariableStorage());
  b.setVal59(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ColonToken()));
  b.setVal11(es.EntityId(e.KeywordToken()));
  auto v12 = e.NextSwitchCase();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal14(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal15(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal16(e.CaseStatementIsGNURange());
  b.setVal15(es.EntityId(e.CaseToken()));
  b.setVal18(es.EntityId(e.EllipsisToken()));
  b.setVal19(es.EntityId(e.LHS()));
  auto v20 = e.RHS();
  if (v20) {
    if (auto id20 = es.EntityId(v20.value())) {
      b.setVal20(id20);
      b.setVal21(true);
    } else {
      b.setVal21(false);
    }
  } else {
    b.setVal21(false);
  }
}

void SerializeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.parent_decl_id);
  b.setVal1(es.parent_stmt_id);
  b.setVal2(static_cast<unsigned short>(mx::FromPasta(e.Access())));
  b.setVal3(static_cast<unsigned short>(mx::FromPasta(e.AccessUnsafe())));
  b.setVal4(static_cast<unsigned short>(mx::FromPasta(e.Availability())));
  b.setVal5(es.EntityId(e.BeginToken()));
  b.setVal6(es.EntityId(e.BodyRBrace()));
  b.setVal7(es.EntityId(e.CanonicalDeclaration()));
  auto v8 = e.DescribedTemplateParameters();
  if (v8) {
    auto o8 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o8], v8.value());
    b.setVal8(o8);
    b.setVal9(true);
  } else {
    b.setVal9(false);
  }
  b.setVal10(es.EntityId(e.EndToken()));
  b.setVal11(static_cast<unsigned short>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal12(static_cast<unsigned short>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setVal13(es.EntityId(e.MostRecentDeclaration()));
  auto v14 = e.NextDeclarationInContext();
  if (v14) {
    if (auto id14 = es.EntityId(v14.value())) {
      b.setVal14(id14);
      b.setVal15(true);
    } else {
      b.setVal15(false);
    }
  } else {
    b.setVal15(false);
  }
  auto v16 = e.NonClosureContext();
  if (v16) {
    if (auto id16 = es.EntityId(v16.value())) {
      b.setVal16(id16);
      b.setVal17(true);
    } else {
      b.setVal17(false);
    }
  } else {
    b.setVal17(false);
  }
  auto v18 = e.PreviousDeclaration();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal19(true);
    } else {
      b.setVal19(false);
    }
  } else {
    b.setVal19(false);
  }
  b.setVal20(e.HasAttributes());
  b.setVal21(e.HasDefiningAttribute());
  b.setVal22(e.HasOwningModule());
  b.setVal23(e.HasTagIdentifierNamespace());
  b.setVal24(e.IsCanonicalDeclaration());
  b.setVal25(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal26(e.IsDeprecated());
  b.setVal27(e.IsFirstDeclaration());
  b.setVal28(e.IsFunctionOrFunctionTemplate());
  b.setVal29(e.IsImplicit());
  b.setVal30(e.IsInAnonymousNamespace());
  b.setVal31(e.IsInLocalScopeForInstantiation());
  b.setVal32(e.IsInStdNamespace());
  b.setVal33(e.IsInvalidDeclaration());
  b.setVal34(e.IsModulePrivate());
  b.setVal35(e.IsOutOfLine());
  b.setVal36(e.IsParameterPack());
  b.setVal37(e.IsReferenced());
  b.setVal38(e.IsTemplateDeclaration());
  b.setVal39(e.IsTemplateParameter());
  b.setVal40(e.IsTemplateParameterPack());
  b.setVal41(e.IsTemplated());
  b.setVal42(e.IsThisDeclarationReferenced());
  b.setVal43(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal44(e.IsUnavailable());
  b.setVal45(e.IsUnconditionallyVisible());
  b.setVal46(e.IsUsed());
  b.setVal47(e.IsWeakImported());
  auto v48 = e.Redeclarations();
  auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
  auto i48 = 0u;
  for (const auto &e48 : v48) {
    sv48.set(i48, es.EntityId(e48));
    ++i48;
  }
  b.setVal49(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal50(es.EntityId(e.Token()));
  if (auto r51 = e.TokenRange(); auto rs51 = r51.Size()) {
    b.setVal51(es.EntityId(r51[0]));
    b.setVal52(es.EntityId(r51[rs51 - 1u]));
  } else {
    b.setVal51(0);
    b.setVal52(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.Specialization()));
  b.setVal54(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.ContextParameter()));
  b.setVal54(e.IsNothrow());
  auto v55 = e.Parameters();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(e.BlockMissingReturnType());
  b.setVal57(e.CanAvoidCopyToHeap());
  b.setVal58(e.CapturesCXXThis());
  b.setVal59(e.DoesNotEscape());
  b.setVal53(es.EntityId(e.BlockManglingContextDeclaration()));
  b.setVal60(es.EntityId(e.CaretToken()));
  b.setVal61(es.EntityId(e.CompoundBody()));
  b.setVal62(e.HasCaptures());
  b.setVal63(e.IsConversionFromLambda());
  b.setVal64(e.IsVariadic());
  auto v55 = e.Parameters();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  auto v56 = e.ParameterDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const auto &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
  pasta::DeclContext dc65(e);
  auto v65 = dc65.AlreadyLoadedDeclarations();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const pasta::Decl &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.AccessSpecifierToken()));
  b.setVal60(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  auto v55 = e.Varlists();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeOMPRequiresDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  auto v55 = e.Varlists();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.AssertExpression()));
  b.setVal60(es.EntityId(e.Message()));
  b.setVal61(es.EntityId(e.RParenToken()));
  b.setVal54(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v66 = e.Name();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v67 = e.Value();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v66 = e.Argument();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.GetterCXXConstructor()));
  b.setVal60(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal61(es.EntityId(e.PropertyDeclaration()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal69(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal70(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal71(es.EntityId(e.SetterCXXAssignment()));
  b.setVal72(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal54(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.FormalLinkage())));
  b.setVal73(static_cast<unsigned short>(mx::FromPasta(e.LinkageInternal())));
  b.setVal66(e.Name());
  b.setVal74(static_cast<unsigned short>(mx::FromPasta(e.ObjCFStringFormattingFamily())));
  b.setVal67(e.QualifiedNameAsString());
  b.setVal53(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal75(static_cast<unsigned short>(mx::FromPasta(e.Visibility())));
  b.setVal54(e.HasExternalFormalLinkage());
  b.setVal57(e.HasLinkage());
  b.setVal58(e.HasLinkageBeenComputed());
  b.setVal59(e.IsCXXClassMember());
  b.setVal62(e.IsCXXInstanceMember());
  b.setVal63(e.IsExternallyDeclarable());
  b.setVal64(e.IsExternallyVisible());
  b.setVal76(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v77 = e.MSAssemblyLabel();
  std::string s77(v77.data(), v77.size());
  b.setVal77(s77);
  b.setVal60(es.EntityId(e.Statement()));
  b.setVal78(e.IsGnuLocal());
  b.setVal79(e.IsMSAssemblyLabel());
  b.setVal80(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v55 = e.Shadows();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal60(es.EntityId(e.EnumDeclaration()));
  b.setVal61(es.EntityId(e.EnumToken()));
  b.setVal69(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal60(es.EntityId(e.UsingToken()));
  b.setVal78(e.HasTypename());
  b.setVal79(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal78(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal60(es.EntityId(e.EllipsisToken()));
  b.setVal61(es.EntityId(e.UsingToken()));
  b.setVal79(e.IsAccessDeclaration());
  b.setVal80(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal60(es.EntityId(e.Combiner()));
  b.setVal61(es.EntityId(e.CombinerIn()));
  b.setVal69(es.EntityId(e.CombinerOut()));
  b.setVal70(es.EntityId(e.InitializerOriginal()));
  b.setVal71(es.EntityId(e.InitializerPrivate()));
  b.setVal72(es.EntityId(e.Initializer()));
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.InitializerKind())));
  b.setVal82(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeMSGuidDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v55 = e.Chain();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  auto v60 = e.AnonymousField();
  if (v60) {
    if (auto id60 = es.EntityId(v60.value())) {
      b.setVal60(id60);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  auto v61 = e.VariableDeclaration();
  if (v61) {
    if (auto id61 = es.EntityId(v61.value())) {
      b.setVal61(id61);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v60 = e.InitializerExpression();
  if (v60) {
    if (auto id60 = es.EntityId(v60.value())) {
      b.setVal60(id60);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal60(es.EntityId(e.InnerTokenStart()));
  b.setVal61(es.EntityId(e.OuterTokenStart()));
  auto v69 = e.TrailingRequiresClause();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal70(es.EntityId(e.TypeSpecEndToken()));
  b.setVal71(es.EntityId(e.TypeSpecStartToken()));
  auto v83 = e.TemplateParameterLists();
  auto sv83 = b.initVal83(static_cast<unsigned>(v83.size()));
  auto i83 = 0u;
  for (const auto &e83 : v83) {
    auto o83 = es.next_pseudo_entity_offset++;
    sv83.set(i83, o83);
    SerializeTemplateParameterList(es, es.pseudo_builder[o83], e83);
    ++i83;
  }
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.ActingDefinition();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  auto v82 = e.Initializer();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.InitializerStyle())));
  auto v85 = e.InitializingDeclaration();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal86(true);
    } else {
      b.setVal86(false);
    }
  } else {
    b.setVal86(false);
  }
  auto v87 = e.InstantiatedFromStaticDataMember();
  if (v87) {
    if (auto id87 = es.EntityId(v87.value())) {
      b.setVal87(id87);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal90(es.EntityId(e.PointOfInstantiation()));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.TLSKind())));
  b.setVal94(static_cast<unsigned short>(mx::FromPasta(e.TSCSpec())));
  auto v95 = e.TemplateInstantiationPattern();
  if (v95) {
    if (auto id95 = es.EntityId(v95.value())) {
      b.setVal95(id95);
      b.setVal96(true);
    } else {
      b.setVal96(false);
    }
  } else {
    b.setVal96(false);
  }
  b.setVal97(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal99(e.HasConstantInitialization());
  b.setVal100(e.HasDependentAlignment());
  b.setVal101(e.HasExternalStorage());
  b.setVal102(e.HasGlobalStorage());
  b.setVal103(e.HasInitializer());
  b.setVal104(e.HasLocalStorage());
  b.setVal105(e.IsARCPseudoStrong());
  b.setVal106(e.IsCXXForRangeDeclaration());
  b.setVal107(e.IsConstexpr());
  b.setVal108(e.IsDirectInitializer());
  b.setVal109(e.IsEscapingByref());
  b.setVal110(e.IsExceptionVariable());
  b.setVal111(e.IsExternC());
  b.setVal112(e.IsFileVariableDeclaration());
  b.setVal113(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal114(e.IsInExternCContext());
  b.setVal115(e.IsInExternCXXContext());
  b.setVal116(e.IsInitializerCapture());
  b.setVal117(e.IsInline());
  b.setVal118(e.IsInlineSpecified());
  b.setVal119(e.IsKnownToBeDefined());
  b.setVal120(e.IsLocalVariableDeclaration());
  b.setVal121(e.IsLocalVariableDeclarationOrParm());
  b.setVal122(e.IsNRVOVariable());
  b.setVal123(e.IsNoDestroy());
  b.setVal124(e.IsNonEscapingByref());
  b.setVal125(e.IsObjCForDeclaration());
  b.setVal126(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal127(e.IsStaticDataMember());
  b.setVal128(e.IsStaticLocal());
  b.setVal129(e.IsThisDeclarationADemotedDefinition());
  b.setVal130(e.IsUsableInConstantExpressions());
  b.setVal131(e.MightBeUsableInConstantExpressions());
  b.setVal132(static_cast<unsigned short>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v133 = e.DefaultArgument();
  if (v133) {
    if (auto id133 = es.EntityId(v133.value())) {
      b.setVal133(id133);
      b.setVal134(true);
    } else {
      b.setVal134(false);
    }
  } else {
    b.setVal134(false);
  }
  if (auto r135 = e.DefaultArgumentRange(); auto rs135 = r135.Size()) {
    b.setVal135(es.EntityId(r135[0]));
    b.setVal136(es.EntityId(r135[rs135 - 1u]));
  } else {
    b.setVal135(0);
    b.setVal136(0);
  }
  b.setVal137(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  auto v138 = e.UninstantiatedDefaultArgument();
  if (v138) {
    if (auto id138 = es.EntityId(v138.value())) {
      b.setVal138(id138);
      b.setVal139(true);
    } else {
      b.setVal139(false);
    }
  } else {
    b.setVal139(false);
  }
  b.setVal140(e.HasDefaultArgument());
  b.setVal141(e.HasInheritedDefaultArgument());
  b.setVal142(e.HasUninstantiatedDefaultArgument());
  b.setVal143(e.HasUnparsedDefaultArgument());
  b.setVal144(e.IsDestroyedInCallee());
  b.setVal145(e.IsKNRPromoted());
  b.setVal146(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal137(static_cast<unsigned short>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v55 = e.Bindings();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal133(es.EntityId(e.ExternToken()));
  b.setVal137(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v147 = e.TemplateArguments();
  auto sv147 = b.initVal147(static_cast<unsigned>(v147.size()));
  auto i147 = 0u;
  for (const auto &e147 : v147) {
    auto o147 = es.next_pseudo_entity_offset++;
    sv147.set(i147, o147);
    SerializeTemplateArgument(es, es.pseudo_builder[o147], e147);
    ++i147;
  }
  auto v148 = e.TemplateInstantiationArguments();
  auto sv148 = b.initVal148(static_cast<unsigned>(v148.size()));
  auto i148 = 0u;
  for (const auto &e148 : v148) {
    auto o148 = es.next_pseudo_entity_offset++;
    sv148.set(i148, o148);
    SerializeTemplateArgument(es, es.pseudo_builder[o148], e148);
    ++i148;
  }
  b.setVal135(es.EntityId(e.TemplateKeywordToken()));
  b.setVal134(e.IsClassScopeExplicitSpecialization());
  b.setVal139(e.IsExplicitInstantiationOrSpecialization());
  b.setVal140(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeNonTypeTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal80(e.DefaultArgumentWasInherited());
  b.setVal72(es.EntityId(e.DefaultArgument()));
  b.setVal82(es.EntityId(e.DefaultArgumentToken()));
  b.setVal85(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal84(e.HasDefaultArgument());
  b.setVal86(e.HasPlaceholderTypeConstraint());
  b.setVal88(e.IsExpandedParameterPack());
  b.setVal96(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal80(e.HasGetter());
  b.setVal84(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal80(e.DoesThisDeclarationHaveABody());
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.ConstexprKind())));
  auto v72 = e.Definition();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal82(es.EntityId(e.EllipsisToken()));
  if (auto r85 = e.ExceptionSpecSourceRange(); auto rs85 = r85.Size()) {
    b.setVal85(es.EntityId(r85[0]));
    b.setVal87(es.EntityId(r85[rs85 - 1u]));
  } else {
    b.setVal85(0);
    b.setVal87(0);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.ExceptionSpecType())));
  auto v90 = e.InstantiatedFromMemberFunction();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal86(true);
    } else {
      b.setVal86(false);
    }
  } else {
    b.setVal86(false);
  }
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.MultiVersionKind())));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r95 = e.ParametersSourceRange(); auto rs95 = r95.Size()) {
    b.setVal95(es.EntityId(r95[0]));
    b.setVal133(es.EntityId(r95[rs95 - 1u]));
  } else {
    b.setVal95(0);
    b.setVal133(0);
  }
  b.setVal135(es.EntityId(e.PointOfInstantiation()));
  if (auto r136 = e.ReturnTypeSourceRange(); auto rs136 = r136.Size()) {
    b.setVal136(es.EntityId(r136[0]));
    b.setVal138(es.EntityId(r136[rs136 - 1u]));
  } else {
    b.setVal136(0);
    b.setVal138(0);
  }
  b.setVal94(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  auto v149 = e.TemplateInstantiationPattern();
  if (v149) {
    if (auto id149 = es.EntityId(v149.value())) {
      b.setVal149(id149);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal97(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal132(static_cast<unsigned short>(mx::FromPasta(e.TemplatedKind())));
  b.setVal96(e.HasImplicitReturnZero());
  b.setVal99(e.HasInheritedPrototype());
  b.setVal100(e.HasOneParameterOrDefaultArguments());
  b.setVal101(e.HasPrototype());
  b.setVal102(e.HasSkippedBody());
  b.setVal103(e.HasTrivialBody());
  b.setVal104(e.HasWrittenPrototype());
  b.setVal105(e.InstantiationIsPending());
  b.setVal106(e.IsCPUDispatchMultiVersion());
  b.setVal107(e.IsCPUSpecificMultiVersion());
  b.setVal108(e.IsConsteval());
  b.setVal109(e.IsConstexpr());
  b.setVal110(e.IsConstexprSpecified());
  b.setVal111(e.IsDefaulted());
  b.setVal112(e.IsDeleted());
  b.setVal113(e.IsDeletedAsWritten());
  b.setVal114(e.IsDestroyingOperatorDelete());
  b.setVal115(e.IsExplicitlyDefaulted());
  b.setVal116(e.IsExternC());
  b.setVal117(e.IsFunctionTemplateSpecialization());
  b.setVal118(e.IsGlobal());
  b.setVal119(e.IsImplicitlyInstantiable());
  b.setVal120(e.IsInExternCContext());
  b.setVal121(e.IsInExternCXXContext());
  b.setVal122(e.IsInlineBuiltinDeclaration());
  b.setVal123(e.IsInlineSpecified());
  b.setVal124(e.IsInlined());
  b.setVal125(e.IsLateTemplateParsed());
  b.setVal126(e.IsMSVCRTEntryPoint());
  b.setVal127(e.IsMain());
  b.setVal128(e.IsMultiVersion());
  b.setVal129(e.IsNoReturn());
  b.setVal130(e.IsOverloadedOperator());
  b.setVal131(e.IsPure());
  b.setVal134(e.IsReplaceableGlobalAllocationFunction());
  b.setVal139(e.IsStatic());
  b.setVal140(e.IsTargetMultiVersion());
  b.setVal141(e.IsTemplateInstantiation());
  b.setVal142(e.IsThisDeclarationADefinition());
  b.setVal143(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal144(e.IsTrivial());
  b.setVal145(e.IsTrivialForCall());
  b.setVal146(e.IsUserProvided());
  b.setVal150(e.IsVariadic());
  b.setVal151(e.IsVirtualAsWritten());
  auto v55 = e.Parameters();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  b.setVal152(e.UsesSEHTry());
  b.setVal153(e.WillHaveBody());
  auto v154 = e.Body();
  if (v154) {
    if (auto id154 = es.EntityId(v154.value())) {
      b.setVal154(id154);
      b.setVal155(true);
    } else {
      b.setVal155(false);
    }
  } else {
    b.setVal155(false);
  }
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal156(es.EntityId(e.Parent()));
  b.setVal137(static_cast<unsigned short>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal157(e.HasInlineBody());
  b.setVal158(e.IsConst());
  b.setVal159(e.IsCopyAssignmentOperator());
  b.setVal160(e.IsInstance());
  b.setVal161(e.IsLambdaStaticInvoker());
  b.setVal162(e.IsMoveAssignmentOperator());
  b.setVal163(e.IsVirtual());
  b.setVal164(e.IsVolatile());
  auto v65 = e.OverriddenMethods();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal165(es.EntityId(e.OperatorDelete()));
  b.setVal166(es.EntityId(e.OperatorDeleteThisArgument()));
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal167(e.IsExplicit());
  b.setVal168(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal165(es.EntityId(e.TargetConstructor()));
  b.setVal167(e.IsDefaultConstructor());
  b.setVal168(e.IsDelegatingConstructor());
  b.setVal169(e.IsExplicit());
  b.setVal170(e.IsInheritingConstructor());
  b.setVal171(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal156(es.EntityId(e.CorrespondingConstructor()));
  b.setVal157(e.IsCopyDeductionCandidate());
  b.setVal158(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.BitWidth();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v82 = e.InClassInitializer();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal85(es.EntityId(e.Parent()));
  b.setVal86(e.HasCapturedVLAType());
  b.setVal88(e.HasInClassInitializer());
  b.setVal96(e.IsAnonymousStructOrUnion());
  b.setVal99(e.IsBitField());
  b.setVal100(e.IsMutable());
  b.setVal101(e.IsUnnamedBitfield());
  b.setVal102(e.IsZeroLengthBitField());
  b.setVal103(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.AccessControl())));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal87(es.EntityId(e.ContainingInterface()));
  b.setVal90(es.EntityId(e.NextInstanceVariable()));
  b.setVal104(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal60(es.EntityId(e.Binding()));
  b.setVal61(es.EntityId(e.DecomposedDeclaration()));
  b.setVal69(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal60(es.EntityId(e.MapperVariableReference()));
  b.setVal61(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal60(es.EntityId(e.Introducer()));
  b.setVal61(es.EntityId(e.NextUsingShadowDeclaration()));
  b.setVal69(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal78(e.ConstructsVirtualBase());
  b.setVal70(es.EntityId(e.ConstructedBaseClass()));
  auto v71 = e.ConstructedBaseClassShadowDeclaration();
  if (v71) {
    if (auto id71 = es.EntityId(v71.value())) {
      b.setVal71(id71);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal72(es.EntityId(e.NominatedBaseClass()));
  auto v82 = e.NominatedBaseClassShadowDeclaration();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  b.setVal85(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v55 = e.Expansions();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  b.setVal60(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal60(es.EntityId(e.IdentifierToken()));
  b.setVal61(es.EntityId(e.NamespaceKeyToken()));
  b.setVal69(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal70(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal78(e.DefaultArgumentWasInherited());
  b.setVal60(es.EntityId(e.DefaultArgumentToken()));
  b.setVal79(e.HasDefaultArgument());
  b.setVal80(e.HasTypeConstraint());
  b.setVal84(e.IsExpandedParameterPack());
  b.setVal86(e.IsPackExpansion());
  b.setVal88(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r60 = e.BraceRange(); auto rs60 = r60.Size()) {
    b.setVal60(es.EntityId(r60[0]));
    b.setVal61(es.EntityId(r60[rs60 - 1u]));
  } else {
    b.setVal60(0);
    b.setVal61(0);
  }
  auto v69 = e.Definition();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
  b.setVal70(es.EntityId(e.InnerTokenStart()));
  b.setVal71(es.EntityId(e.OuterTokenStart()));
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.TagKind())));
  auto v72 = e.TypedefNameForAnonymousDeclaration();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal80(e.HasNameForLinkage());
  b.setVal84(e.IsBeingDefined());
  b.setVal86(e.IsClass());
  b.setVal88(e.IsCompleteDefinition());
  b.setVal96(e.IsCompleteDefinitionRequired());
  b.setVal99(e.IsDependentType());
  b.setVal100(e.IsEmbeddedInDeclarator());
  b.setVal101(e.IsEnum());
  b.setVal102(e.IsFreeStanding());
  b.setVal103(e.IsInterface());
  b.setVal104(e.IsStruct());
  b.setVal105(e.IsThisDeclarationADefinition());
  b.setVal106(e.IsUnion());
  b.setVal107(e.MayHaveOutOfDateDefinition());
  auto v83 = e.TemplateParameterLists();
  auto sv83 = b.initVal83(static_cast<unsigned>(v83.size()));
  auto i83 = 0u;
  for (const auto &e83 : v83) {
    auto o83 = es.next_pseudo_entity_offset++;
    sv83.set(i83, o83);
    SerializeTemplateParameterList(es, es.pseudo_builder[o83], e83);
    ++i83;
  }
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal108(e.CanPassInRegisters());
  auto v56 = e.Fields();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const auto &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
  auto v82 = e.FindFirstNamedDataMember();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal110(e.HasFlexibleArrayMember());
  b.setVal111(e.HasLoadedFieldsFromExternalStorage());
  b.setVal112(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal113(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal114(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal115(e.HasObjectMember());
  b.setVal116(e.HasVolatileMember());
  b.setVal117(e.IsAnonymousStructOrUnion());
  b.setVal118(e.IsCapturedRecord());
  b.setVal119(e.IsInjectedClassName());
  b.setVal120(e.IsLambda());
  b.setVal121(e.IsMsStruct());
  b.setVal122(e.IsNonTrivialToPrimitiveCopy());
  b.setVal123(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal124(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal125(e.IsOrContainsUnion());
  b.setVal126(e.IsParameterDestroyedInCallee());
  b.setVal127(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  b.setVal128(e.AllowConstDefaultInitializer());
  auto v147 = e.Bases();
  auto sv147 = b.initVal147(static_cast<unsigned>(v147.size()));
  auto i147 = 0u;
  for (const auto &e147 : v147) {
    auto o147 = es.next_pseudo_entity_offset++;
    sv147.set(i147, o147);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o147], e147);
    ++i147;
  }
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.CalculateInheritanceModel())));
  auto v65 = e.Constructors();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
  b.setVal129(e.DefaultedCopyConstructorIsDeleted());
  b.setVal130(e.DefaultedDefaultConstructorIsConstexpr());
  b.setVal131(e.DefaultedDestructorIsConstexpr());
  b.setVal134(e.DefaultedDestructorIsDeleted());
  b.setVal139(e.DefaultedMoveConstructorIsDeleted());
  auto v172 = e.Friends();
  auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
  auto i172 = 0u;
  for (const auto &e172 : v172) {
    sv172.set(i172, es.EntityId(e172));
    ++i172;
  }
  auto v85 = e.Destructor();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal140(true);
    } else {
      b.setVal140(false);
    }
  } else {
    b.setVal140(false);
  }
  auto v173 = e.GenericLambdaTemplateParameterList();
  if (v173) {
    auto o173 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o173], v173.value());
    b.setVal173(o173);
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v87 = e.InstantiatedFromMemberClass();
  if (v87) {
    if (auto id87 = es.EntityId(v87.value())) {
      b.setVal87(id87);
      b.setVal142(true);
    } else {
      b.setVal142(false);
    }
  } else {
    b.setVal142(false);
  }
  auto v90 = e.LambdaCallOperator();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal143(true);
    } else {
      b.setVal143(false);
    }
  } else {
    b.setVal143(false);
  }
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.LambdaCaptureDefault())));
  b.setVal95(es.EntityId(e.LambdaContextDeclaration()));
  auto v174 = e.LambdaExplicitTemplateParameters();
  auto sv174 = b.initVal174(static_cast<unsigned>(v174.size()));
  auto i174 = 0u;
  for (const auto &e174 : v174) {
    sv174.set(i174, es.EntityId(e174));
    ++i174;
  }
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.MSInheritanceModel())));
  b.setVal94(static_cast<unsigned short>(mx::FromPasta(e.MSVtorDispMode())));
  b.setVal133(es.EntityId(e.MostRecentNonInjectedDeclaration()));
  auto v135 = e.TemplateInstantiationPattern();
  if (v135) {
    if (auto id135 = es.EntityId(v135.value())) {
      b.setVal135(id135);
      b.setVal144(true);
    } else {
      b.setVal144(false);
    }
  } else {
    b.setVal144(false);
  }
  b.setVal97(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal145(e.HasAnyDependentBases());
  b.setVal146(e.HasConstexprDefaultConstructor());
  b.setVal150(e.HasConstexprDestructor());
  b.setVal151(e.HasConstexprNonCopyMoveConstructor());
  b.setVal152(e.HasCopyAssignmentWithConstParameter());
  b.setVal153(e.HasCopyConstructorWithConstParameter());
  b.setVal155(e.HasDefaultConstructor());
  b.setVal157(e.HasDefinition());
  b.setVal158(e.HasDirectFields());
  b.setVal159(e.HasFriends());
  b.setVal160(e.HasInClassInitializer());
  b.setVal161(e.HasInheritedAssignment());
  b.setVal162(e.HasInheritedConstructor());
  b.setVal163(e.HasIrrelevantDestructor());
  b.setVal164(e.HasKnownLambdaInternalLinkage());
  b.setVal167(e.HasMoveAssignment());
  b.setVal168(e.HasMoveConstructor());
  b.setVal169(e.HasMutableFields());
  b.setVal170(e.HasNonLiteralTypeFieldsOrBases());
  b.setVal171(e.HasNonTrivialCopyAssignment());
  b.setVal175(e.HasNonTrivialCopyConstructor());
  b.setVal176(e.HasNonTrivialCopyConstructorForCall());
  b.setVal177(e.HasNonTrivialDefaultConstructor());
  b.setVal178(e.HasNonTrivialDestructor());
  b.setVal179(e.HasNonTrivialDestructorForCall());
  b.setVal180(e.HasNonTrivialMoveAssignment());
  b.setVal181(e.HasNonTrivialMoveConstructor());
  b.setVal182(e.HasNonTrivialMoveConstructorForCall());
  b.setVal183(e.HasPrivateFields());
  b.setVal184(e.HasProtectedFields());
  b.setVal185(e.HasSimpleCopyAssignment());
  b.setVal186(e.HasSimpleCopyConstructor());
  b.setVal187(e.HasSimpleDestructor());
  b.setVal188(e.HasSimpleMoveAssignment());
  b.setVal189(e.HasSimpleMoveConstructor());
  b.setVal190(e.HasTrivialCopyAssignment());
  b.setVal191(e.HasTrivialCopyConstructor());
  b.setVal192(e.HasTrivialCopyConstructorForCall());
  b.setVal193(e.HasTrivialDefaultConstructor());
  b.setVal194(e.HasTrivialDestructor());
  b.setVal195(e.HasTrivialDestructorForCall());
  b.setVal196(e.HasTrivialMoveAssignment());
  b.setVal197(e.HasTrivialMoveConstructor());
  b.setVal198(e.HasTrivialMoveConstructorForCall());
  b.setVal199(e.HasUninitializedReferenceMember());
  b.setVal200(e.HasUserDeclaredConstructor());
  b.setVal201(e.HasUserDeclaredCopyAssignment());
  b.setVal202(e.HasUserDeclaredCopyConstructor());
  b.setVal203(e.HasUserDeclaredDestructor());
  b.setVal204(e.HasUserDeclaredMoveAssignment());
  b.setVal205(e.HasUserDeclaredMoveConstructor());
  b.setVal206(e.HasUserDeclaredMoveOperation());
  b.setVal207(e.HasUserProvidedDefaultConstructor());
  b.setVal208(e.HasVariantMembers());
  b.setVal209(e.ImplicitCopyAssignmentHasConstParameter());
  b.setVal210(e.ImplicitCopyConstructorHasConstParameter());
  b.setVal211(e.IsAbstract());
  b.setVal212(e.IsAggregate());
  b.setVal213(e.IsAnyDestructorNoReturn());
  b.setVal214(e.IsCLike());
  b.setVal215(e.IsCXX11StandardLayout());
  b.setVal216(e.IsDependentLambda());
  b.setVal217(e.IsDynamicClass());
  b.setVal218(e.IsEffectivelyFinal());
  b.setVal219(e.IsEmpty());
  b.setVal220(e.IsGenericLambda());
  b.setVal221(e.IsInterfaceLike());
  b.setVal222(e.IsLiteral());
  auto v136 = e.IsLocalClass();
  if (v136) {
    if (auto id136 = es.EntityId(v136.value())) {
      b.setVal136(id136);
      b.setVal223(true);
    } else {
      b.setVal223(false);
    }
  } else {
    b.setVal223(false);
  }
  b.setVal224(e.IsPOD());
  b.setVal225(e.IsParsingBaseSpecifiers());
  b.setVal226(e.IsPolymorphic());
  b.setVal227(e.IsStandardLayout());
  b.setVal228(e.IsStructural());
  b.setVal229(e.IsTrivial());
  b.setVal230(e.IsTriviallyCopyable());
  b.setVal231(e.LambdaIsDefaultConstructibleAndAssignable());
  b.setVal232(e.MayBeAbstract());
  b.setVal233(e.MayBeDynamicClass());
  b.setVal234(e.MayBeNonDynamicClass());
  auto v235 = e.Methods();
  auto sv235 = b.initVal235(static_cast<unsigned>(v235.size()));
  auto i235 = 0u;
  for (const auto &e235 : v235) {
    sv235.set(i235, es.EntityId(e235));
    ++i235;
  }
  b.setVal236(e.NeedsImplicitCopyAssignment());
  b.setVal237(e.NeedsImplicitCopyConstructor());
  b.setVal238(e.NeedsImplicitDefaultConstructor());
  b.setVal239(e.NeedsImplicitDestructor());
  b.setVal240(e.NeedsImplicitMoveAssignment());
  b.setVal241(e.NeedsImplicitMoveConstructor());
  b.setVal242(e.NeedsOverloadResolutionForCopyAssignment());
  b.setVal243(e.NeedsOverloadResolutionForCopyConstructor());
  b.setVal244(e.NeedsOverloadResolutionForDestructor());
  b.setVal245(e.NeedsOverloadResolutionForMoveAssignment());
  b.setVal246(e.NeedsOverloadResolutionForMoveConstructor());
  b.setVal247(e.NullFieldOffsetIsZero());
  auto v148 = e.VirtualBases();
  auto sv148 = b.initVal148(static_cast<unsigned>(v148.size()));
  auto i148 = 0u;
  for (const auto &e148 : v148) {
    auto o148 = es.next_pseudo_entity_offset++;
    sv148.set(i148, o148);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o148], e148);
    ++i148;
  }
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  b.setVal138(es.EntityId(e.ExternToken()));
  b.setVal149(es.EntityId(e.PointOfInstantiation()));
  b.setVal98(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v248 = e.TemplateArguments();
  auto sv248 = b.initVal248(static_cast<unsigned>(v248.size()));
  auto i248 = 0u;
  for (const auto &e248 : v248) {
    auto o248 = es.next_pseudo_entity_offset++;
    sv248.set(i248, o248);
    SerializeTemplateArgument(es, es.pseudo_builder[o248], e248);
    ++i248;
  }
  auto v249 = e.TemplateInstantiationArguments();
  auto sv249 = b.initVal249(static_cast<unsigned>(v249.size()));
  auto i249 = 0u;
  for (const auto &e249 : v249) {
    auto o249 = es.next_pseudo_entity_offset++;
    sv249.set(i249, o249);
    SerializeTemplateArgument(es, es.pseudo_builder[o249], e249);
    ++i249;
  }
  b.setVal154(es.EntityId(e.TemplateKeywordToken()));
  b.setVal250(e.IsClassScopeExplicitSpecialization());
  b.setVal251(e.IsExplicitInstantiationOrSpecialization());
  b.setVal252(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  auto v56 = e.Enumerators();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const auto &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
  auto v82 = e.InstantiatedFromMemberEnum();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal108(true);
    } else {
      b.setVal108(false);
    }
  } else {
    b.setVal108(false);
  }
  if (auto r85 = e.IntegerTypeRange(); auto rs85 = r85.Size()) {
    b.setVal85(es.EntityId(r85[0]));
    b.setVal87(es.EntityId(r85[rs85 - 1u]));
  } else {
    b.setVal85(0);
    b.setVal87(0);
  }
  auto v90 = e.TemplateInstantiationPattern();
  if (v90) {
    if (auto id90 = es.EntityId(v90.value())) {
      b.setVal90(id90);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal110(e.IsClosed());
  b.setVal111(e.IsClosedFlag());
  b.setVal112(e.IsClosedNonFlag());
  b.setVal113(e.IsComplete());
  b.setVal114(e.IsFixed());
  b.setVal115(e.IsScoped());
  b.setVal116(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal60(es.EntityId(e.EllipsisToken()));
  b.setVal61(es.EntityId(e.TypenameToken()));
  b.setVal69(es.EntityId(e.UsingToken()));
  b.setVal78(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v60 = e.AnonymousDeclarationWithTypedefName();
  if (v60) {
    if (auto id60 = es.EntityId(v60.value())) {
      b.setVal60(id60);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
  b.setVal79(e.IsModed());
  b.setVal80(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto v61 = e.DescribedAliasTemplate();
  if (v61) {
    if (auto id61 = es.EntityId(v61.value())) {
      b.setVal61(id61);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  b.setVal61(es.EntityId(e.ColonToken()));
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.Variance())));
  b.setVal69(es.EntityId(e.VarianceToken()));
  b.setVal84(e.HasExplicitBound());
}

void SerializeTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeRedeclarableTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFunctionTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeClassTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeVarTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTypeAliasTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e);
}

void SerializeConceptDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal60(es.EntityId(e.ConstraintExpression()));
  b.setVal78(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTemplateTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeObjCPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal60(es.EntityId(e.AtToken()));
  b.setVal61(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal69(es.EntityId(e.GetterNameToken()));
  b.setVal70(es.EntityId(e.LParenToken()));
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal71(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.QueryKind())));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.SetterKind())));
  b.setVal72(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal82(es.EntityId(e.SetterNameToken()));
  b.setVal78(e.IsAtomic());
  b.setVal79(e.IsClassProperty());
  b.setVal80(e.IsDirectProperty());
  b.setVal84(e.IsInstanceProperty());
  b.setVal86(e.IsOptional());
  b.setVal88(e.IsReadOnly());
  b.setVal96(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal78(e.DefinedInNSObject());
  b.setVal60(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal61(es.EntityId(e.Category()));
  b.setVal69(es.EntityId(e.ClassInterface()));
  b.setVal70(es.EntityId(e.CmdDeclaration()));
  b.setVal71(es.EntityId(e.DeclaratorEndToken()));
  b.setVal81(static_cast<unsigned short>(mx::FromPasta(e.ImplementationControl())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  if (auto r72 = e.ReturnTypeSourceRange(); auto rs72 = r72.Size()) {
    b.setVal72(es.EntityId(r72[0]));
    b.setVal82(es.EntityId(r72[rs72 - 1u]));
  } else {
    b.setVal72(0);
    b.setVal82(0);
  }
  b.setVal85(es.EntityId(e.SelectorStartToken()));
  b.setVal87(es.EntityId(e.SelfDeclaration()));
  b.setVal79(e.HasRedeclaration());
  b.setVal80(e.HasRelatedResultType());
  b.setVal84(e.HasSkippedBody());
  b.setVal86(e.IsClassMethod());
  b.setVal88(e.IsDefined());
  b.setVal96(e.IsDesignatedInitializerForTheInterface());
  b.setVal99(e.IsDirectMethod());
  b.setVal100(e.IsInstanceMethod());
  b.setVal101(e.IsOptional());
  b.setVal102(e.IsOverriding());
  b.setVal103(e.IsPropertyAccessor());
  b.setVal104(e.IsRedeclaration());
  b.setVal105(e.IsSynthesizedAccessorStub());
  b.setVal106(e.IsThisDeclarationADefinition());
  b.setVal107(e.IsThisDeclarationADesignatedInitializer());
  b.setVal108(e.IsVariadic());
  auto v55 = e.Parameters();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  auto v56 = e.SelectorTokens();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const auto &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
  pasta::DeclContext dc65(e);
  auto v65 = dc65.AlreadyLoadedDeclarations();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const pasta::Decl &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v55 = e.ClassMethods();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  auto v56 = e.ClassProperties();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const auto &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
  if (auto r60 = e.AtEndRange(); auto rs60 = r60.Size()) {
    b.setVal60(es.EntityId(r60[0]));
    b.setVal61(es.EntityId(r60[rs60 - 1u]));
  } else {
    b.setVal60(0);
    b.setVal61(0);
  }
  b.setVal69(es.EntityId(e.AtStartToken()));
  auto v65 = e.InstanceMethods();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
  auto v172 = e.InstanceProperties();
  auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
  auto i172 = 0u;
  for (const auto &e172 : v172) {
    sv172.set(i172, es.EntityId(e172));
    ++i172;
  }
  auto v174 = e.Methods();
  auto sv174 = b.initVal174(static_cast<unsigned>(v174.size()));
  auto i174 = 0u;
  for (const auto &e174 : v174) {
    sv174.set(i174, es.EntityId(e174));
    ++i174;
  }
  auto v235 = e.Properties();
  auto sv235 = b.initVal235(static_cast<unsigned>(v235.size()));
  auto i235 = 0u;
  for (const auto &e235 : v235) {
    sv235.set(i235, es.EntityId(e235));
    ++i235;
  }
  pasta::DeclContext dc253(e);
  auto v253 = dc253.AlreadyLoadedDeclarations();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const pasta::Decl &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal78(e.IsClassExtension());
  b.setVal70(es.EntityId(e.CategoryNameToken()));
  b.setVal71(es.EntityId(e.ClassInterface()));
  b.setVal72(es.EntityId(e.Implementation()));
  b.setVal82(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal85(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal87(es.EntityId(e.NextClassCategory()));
  b.setVal90(es.EntityId(e.NextClassCategoryRaw()));
  auto v254 = e.InstanceVariables();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
  auto v255 = e.ProtocolTokens();
  auto sv255 = b.initVal255(static_cast<unsigned>(v255.size()));
  auto i255 = 0u;
  for (const auto &e255 : v255) {
    sv255.set(i255, es.EntityId(e255));
    ++i255;
  }
  auto v256 = e.Protocols();
  auto sv256 = b.initVal256(static_cast<unsigned>(v256.size()));
  auto i256 = 0u;
  for (const auto &e256 : v256) {
    sv256.set(i256, es.EntityId(e256));
    ++i256;
  }
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal70(es.EntityId(e.Definition()));
  auto v77 = e.ObjCRuntimeNameAsString();
  std::string s77(v77.data(), v77.size());
  b.setVal77(s77);
  b.setVal78(e.HasDefinition());
  b.setVal79(e.IsNonRuntimeProtocol());
  b.setVal80(e.IsThisDeclarationADefinition());
  auto v254 = e.ProtocolTokens();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
  auto v255 = e.Protocols();
  auto sv255 = b.initVal255(static_cast<unsigned>(v255.size()));
  auto i255 = 0u;
  for (const auto &e255 : v255) {
    sv255.set(i255, es.EntityId(e255));
    ++i255;
  }
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  auto v254 = e.AllReferencedProtocols();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
  b.setVal78(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal70(es.EntityId(e.CategoryListRaw()));
  b.setVal71(es.EntityId(e.Definition()));
  b.setVal72(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal82(es.EntityId(e.Implementation()));
  auto v77 = e.ObjCRuntimeNameAsString();
  std::string s77(v77.data(), v77.size());
  b.setVal77(s77);
  b.setVal85(es.EntityId(e.SuperClass()));
  b.setVal87(es.EntityId(e.SuperClassToken()));
  b.setVal79(e.HasDefinition());
  b.setVal80(e.HasDesignatedInitializers());
  b.setVal84(e.IsArcWeakrefUnavailable());
  b.setVal86(e.IsImplicitInterfaceDeclaration());
  b.setVal90(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal88(e.IsThisDeclarationADefinition());
  auto v255 = e.InstanceVariables();
  auto sv255 = b.initVal255(static_cast<unsigned>(v255.size()));
  auto i255 = 0u;
  for (const auto &e255 : v255) {
    sv255.set(i255, es.EntityId(e255));
    ++i255;
  }
  auto v256 = e.KnownCategories();
  auto sv256 = b.initVal256(static_cast<unsigned>(v256.size()));
  auto i256 = 0u;
  for (const auto &e256 : v256) {
    sv256.set(i256, es.EntityId(e256));
    ++i256;
  }
  auto v257 = e.KnownExtensions();
  auto sv257 = b.initVal257(static_cast<unsigned>(v257.size()));
  auto i257 = 0u;
  for (const auto &e257 : v257) {
    sv257.set(i257, es.EntityId(e257));
    ++i257;
  }
  auto v258 = e.ProtocolTokens();
  auto sv258 = b.initVal258(static_cast<unsigned>(v258.size()));
  auto i258 = 0u;
  for (const auto &e258 : v258) {
    sv258.set(i258, es.EntityId(e258));
    ++i258;
  }
  auto v259 = e.Protocols();
  auto sv259 = b.initVal259(static_cast<unsigned>(v259.size()));
  auto i259 = 0u;
  for (const auto &e259 : v259) {
    sv259.set(i259, es.EntityId(e259));
    ++i259;
  }
  auto v260 = e.VisibleCategories();
  auto sv260 = b.initVal260(static_cast<unsigned>(v260.size()));
  auto i260 = 0u;
  for (const auto &e260 : v260) {
    sv260.set(i260, es.EntityId(e260));
    ++i260;
  }
  auto v261 = e.VisibleExtensions();
  auto sv261 = b.initVal261(static_cast<unsigned>(v261.size()));
  auto i261 = 0u;
  for (const auto &e261 : v261) {
    sv261.set(i261, es.EntityId(e261));
    ++i261;
  }
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal70(es.EntityId(e.ClassInterface()));
  auto v254 = e.PropertyImplementations();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal71(es.EntityId(e.CategoryDeclaration()));
  b.setVal72(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal71(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal72(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v77 = e.ObjCRuntimeNameAsString();
  std::string s77(v77.data(), v77.size());
  b.setVal77(s77);
  b.setVal82(es.EntityId(e.SuperClass()));
  b.setVal85(es.EntityId(e.SuperClassToken()));
  b.setVal78(e.HasDestructors());
  b.setVal79(e.HasNonZeroConstructors());
  auto v255 = e.InstanceVariables();
  auto sv255 = b.initVal255(static_cast<unsigned>(v255.size()));
  auto i255 = 0u;
  for (const auto &e255 : v255) {
    sv255.set(i255, es.EntityId(e255));
    ++i255;
  }
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal60(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal60(es.EntityId(e.AliasToken()));
  b.setVal61(es.EntityId(e.AliasedNamespace()));
  b.setVal69(es.EntityId(e.NamespaceToken()));
  b.setVal70(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v55 = e.ChildrenExpression();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
  b.setVal53(es.EntityId(e.ExtendingDeclaration()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal60(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v55 = e.IdentifierTokens();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const auto &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeFriendTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFriendDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.FriendDeclaration()));
  b.setVal60(es.EntityId(e.FriendToken()));
  b.setVal54(e.IsUnsupportedFriend());
  auto v83 = e.FriendTypeTemplateParameterLists();
  auto sv83 = b.initVal83(static_cast<unsigned>(v83.size()));
  auto i83 = 0u;
  for (const auto &e83 : v83) {
    auto o83 = es.next_pseudo_entity_offset++;
    sv83.set(i83, o83);
    SerializeTemplateParameterList(es, es.pseudo_builder[o83], e83);
    ++i83;
  }
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.AssemblyToken()));
  b.setVal60(es.EntityId(e.AssemblyString()));
  b.setVal61(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.ExportToken()));
  b.setVal60(es.EntityId(e.RBraceToken()));
  b.setVal54(e.HasBraces());
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
