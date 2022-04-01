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
  b.setVal0(es.EntityId(e.IgnoreContainers()));
  auto v1 = e.Children();
  auto sv1 = b.initVal1(static_cast<unsigned>(v1.size()));
  auto i1 = 0u;
  for (const auto &e1 : v1) {
    sv1.set(i1, es.EntityId(e1));
    ++i1;
  }
  b.setVal2(es.EntityId(e.BeginToken()));
  b.setVal3(es.EntityId(e.EndToken()));
  if (auto r4 = e.TokenRange(); auto rs4 = r4.Size()) {
    b.setVal4(es.EntityId(r4[0]));
    b.setVal5(es.EntityId(r4[rs4 - 1u]));
  } else {
    b.setVal4(0);
    b.setVal5(0);
  }
  b.setVal6(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal7(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ExceptHandler()));
  b.setVal9(es.EntityId(e.FinallyHandler()));
  b.setVal10(es.EntityId(e.Handler()));
  b.setVal11(e.IsCXXTry());
  b.setVal12(es.EntityId(e.TryBlock()));
  b.setVal13(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Block()));
  b.setVal9(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Block()));
  b.setVal9(es.EntityId(e.ExceptToken()));
  b.setVal10(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v8 = e.NRVOCandidate();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  auto v9 = e.ReturnValue();
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
  b.setVal10(es.EntityId(e.ReturnToken()));
}

void SerializeObjCForCollectionStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Collection()));
  b.setVal10(es.EntityId(e.Element()));
  b.setVal12(es.EntityId(e.ForToken()));
  b.setVal13(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AtToken()));
  b.setVal9(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AtTryToken()));
  b.setVal9(es.EntityId(e.FinallyStatement()));
  b.setVal10(es.EntityId(e.TryBody()));
  auto v15 = e.CatchStatements();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeObjCAtThrowStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ThrowExpression()));
  b.setVal9(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AtSynchronizedToken()));
  b.setVal9(es.EntityId(e.SynchBody()));
  b.setVal10(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AtFinallyToken()));
  b.setVal9(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AtCatchToken()));
  b.setVal9(es.EntityId(e.CatchBody()));
  b.setVal10(es.EntityId(e.CatchParameterDeclaration()));
  b.setVal12(es.EntityId(e.RParenToken()));
  b.setVal11(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AssociatedStatement()));
  b.setVal9(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal10(es.EntityId(e.RawStatement()));
  b.setVal12(es.EntityId(e.StructuredBlock()));
  b.setVal11(e.HasAssociatedStatement());
  b.setVal14(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TargetCallToken()));
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
  b.setVal13(es.EntityId(e.Expression()));
  b.setVal16(es.EntityId(e.UpdateExpression()));
  b.setVal17(es.EntityId(e.V()));
  b.setVal18(es.EntityId(e.X()));
  b.setVal19(e.IsPostfixUpdate());
  b.setVal20(e.IsXLHSInRHSPart());
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
  b.setVal13(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPSectionDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPScanDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal13(es.EntityId(e.PreInitializers()));
  b.setVal16(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPTileDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal13(es.EntityId(e.PreInitializers()));
  b.setVal16(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  auto v15 = e.Counters();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  auto v21 = e.DependentCounters();
  auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
  auto i21 = 0u;
  for (const auto &e21 : v21) {
    sv21.set(i21, es.EntityId(e21));
    ++i21;
  }
  auto v22 = e.DependentInitializers();
  auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
  auto i22 = 0u;
  for (const auto &e22 : v22) {
    sv22.set(i22, es.EntityId(e22));
    ++i22;
  }
  auto v23 = e.Finals();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
  auto v24 = e.FinalsConditions();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
  b.setVal13(es.EntityId(e.Body()));
  b.setVal16(es.EntityId(e.CalculateLastIteration()));
  b.setVal17(es.EntityId(e.CombinedCondition()));
  b.setVal18(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal25(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal26(es.EntityId(e.CombinedInitializer()));
  b.setVal27(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal28(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal29(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal30(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal31(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal32(es.EntityId(e.Condition()));
  b.setVal33(es.EntityId(e.DistanceIncrement()));
  b.setVal34(es.EntityId(e.EnsureUpperBound()));
  b.setVal35(es.EntityId(e.Increment()));
  b.setVal36(es.EntityId(e.Initializer()));
  b.setVal37(es.EntityId(e.IsLastIterationVariable()));
  b.setVal38(es.EntityId(e.IterationVariable()));
  b.setVal39(es.EntityId(e.LastIteration()));
  b.setVal40(es.EntityId(e.LowerBoundVariable()));
  b.setVal41(es.EntityId(e.NextLowerBound()));
  b.setVal42(es.EntityId(e.NextUpperBound()));
  b.setVal43(es.EntityId(e.NumIterations()));
  b.setVal44(es.EntityId(e.PreCondition()));
  b.setVal45(es.EntityId(e.PreInitializers()));
  b.setVal46(es.EntityId(e.PrevEnsureUpperBound()));
  b.setVal47(es.EntityId(e.PrevLowerBoundVariable()));
  b.setVal48(es.EntityId(e.PrevUpperBoundVariable()));
  b.setVal49(es.EntityId(e.StrideVariable()));
  b.setVal50(es.EntityId(e.UpperBoundVariable()));
  auto v51 = e.Initializers();
  auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
  auto i51 = 0u;
  for (const auto &e51 : v51) {
    sv51.set(i51, es.EntityId(e51));
    ++i51;
  }
  auto v52 = e.PrivateCounters();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const auto &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
  auto v53 = e.Updates();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeOMPForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPInteropDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.DistanceFunc()));
  b.setVal9(es.EntityId(e.LoopStatement()));
  b.setVal10(es.EntityId(e.LoopVariableFunc()));
  b.setVal12(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.SemiToken()));
  b.setVal11(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.KeywordToken()));
  b.setVal9(es.EntityId(e.SubStatement()));
  b.setVal11(e.IsIfExists());
  b.setVal14(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ConstantTarget()));
  b.setVal9(es.EntityId(e.GotoToken()));
  b.setVal10(es.EntityId(e.StarToken()));
  b.setVal12(es.EntityId(e.Target()));
}

void SerializeIfStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Condition()));
  auto v9 = e.ConditionVariable();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  auto v10 = e.ConditionVariableDeclarationStatement();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  auto v12 = e.Else();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal19(true);
    } else {
      b.setVal19(false);
    }
  } else {
    b.setVal19(false);
  }
  b.setVal13(es.EntityId(e.ElseToken()));
  b.setVal16(es.EntityId(e.IfToken()));
  auto v17 = e.Initializer();
  if (v17) {
    if (auto id17 = es.EntityId(v17.value())) {
      b.setVal17(id17);
      b.setVal20(true);
    } else {
      b.setVal20(false);
    }
  } else {
    b.setVal20(false);
  }
  b.setVal18(es.EntityId(e.LParenToken()));
  b.setVal25(es.EntityId(e.RParenToken()));
  b.setVal26(es.EntityId(e.Then()));
  b.setVal55(e.HasElseStorage());
  b.setVal56(e.HasInitializerStorage());
  b.setVal57(e.HasVariableStorage());
  b.setVal58(e.IsConstexpr());
  b.setVal59(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.GotoToken()));
  b.setVal9(es.EntityId(e.Label()));
  b.setVal10(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  auto v9 = e.Condition();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  auto v10 = e.ConditionVariable();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal19(true);
    } else {
      b.setVal19(false);
    }
  } else {
    b.setVal19(false);
  }
  b.setVal13(es.EntityId(e.ForToken()));
  auto v16 = e.Increment();
  if (v16) {
    if (auto id16 = es.EntityId(v16.value())) {
      b.setVal16(id16);
      b.setVal20(true);
    } else {
      b.setVal20(false);
    }
  } else {
    b.setVal20(false);
  }
  auto v17 = e.Initializer();
  if (v17) {
    if (auto id17 = es.EntityId(v17.value())) {
      b.setVal17(id17);
      b.setVal55(true);
    } else {
      b.setVal55(false);
    }
  } else {
    b.setVal55(false);
  }
  b.setVal18(es.EntityId(e.LParenToken()));
  b.setVal25(es.EntityId(e.RParenToken()));
}

void SerializeDoStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  b.setVal10(es.EntityId(e.DoToken()));
  b.setVal12(es.EntityId(e.RParenToken()));
  b.setVal13(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  auto v15 = e.Declarations();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  auto v8 = e.SingleDeclaration();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal14(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Allocate()));
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Deallocate()));
  b.setVal12(es.EntityId(e.ExceptionHandler()));
  b.setVal13(es.EntityId(e.FallthroughHandler()));
  b.setVal16(es.EntityId(e.FinalSuspendStatement()));
  b.setVal17(es.EntityId(e.InitializerSuspendStatement()));
  auto v15 = e.ParameterMoves();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal18(es.EntityId(e.PromiseDeclaration()));
  b.setVal25(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal26(es.EntityId(e.ResultDeclaration()));
  b.setVal27(es.EntityId(e.ReturnStatement()));
  b.setVal28(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal29(es.EntityId(e.ReturnValueInitializer()));
  b.setVal11(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.KeywordToken()));
  b.setVal9(es.EntityId(e.Operand()));
  b.setVal10(es.EntityId(e.PromiseCall()));
  b.setVal11(e.IsImplicit());
}

void SerializeContinueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.LeftBraceToken()));
  b.setVal9(es.EntityId(e.RightBraceToken()));
  auto v10 = e.StatementExpressionResult();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
}

void SerializeCapturedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.CapturedDeclaration()));
  b.setVal9(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal60(static_cast<unsigned short>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal10(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.TryBlock()));
  b.setVal9(es.EntityId(e.TryToken()));
  auto v15 = e.Handlers();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeCXXForRangeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.BeginStatement()));
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.CoawaitToken()));
  b.setVal12(es.EntityId(e.ColonToken()));
  b.setVal13(es.EntityId(e.Condition()));
  b.setVal16(es.EntityId(e.EndStatement()));
  b.setVal17(es.EntityId(e.ForToken()));
  b.setVal18(es.EntityId(e.Increment()));
  b.setVal25(es.EntityId(e.Initializer()));
  b.setVal26(es.EntityId(e.LoopVariableStatement()));
  b.setVal27(es.EntityId(e.LoopVariable()));
  b.setVal28(es.EntityId(e.RParenToken()));
  b.setVal29(es.EntityId(e.RangeInitializer()));
  b.setVal30(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.CatchToken()));
  b.setVal9(es.EntityId(e.ExceptionDeclaration()));
  b.setVal10(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal61(e.GenerateAssemblyString());
  b.setVal8(es.EntityId(e.AssemblyToken()));
  auto v15 = e.Inputs();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal11(e.IsSimple());
  b.setVal14(e.IsVolatile());
  auto v21 = e.Outputs();
  auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
  auto i21 = 0u;
  for (const auto &e21 : v21) {
    sv21.set(i21, es.EntityId(e21));
    ++i21;
  }
  auto v62 = e.OutputConstraints();
  auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
  auto i62 = 0u;
  for (const auto &e62 : v62) {
    std::string se62(e62.data(), e62.size());
    sv62.set(i62, se62);
    ++i62;
  }
  auto v22 = e.OutputExpressions();
  auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
  auto i22 = 0u;
  for (const auto &e22 : v22) {
    sv22.set(i22, es.EntityId(e22));
    ++i22;
  }
  auto v63 = e.InputConstraints();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    std::string se63(e63.data(), e63.size());
    sv63.set(i63, se63);
    ++i63;
  }
  auto v23 = e.InputExpressions();
  auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
  auto i23 = 0u;
  for (const auto &e23 : v23) {
    sv23.set(i23, es.EntityId(e23));
    ++i23;
  }
  auto v64 = e.Clobbers();
  auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
  auto i64 = 0u;
  for (const auto &e64 : v64) {
    std::string se64(e64.data(), e64.size());
    sv64.set(i64, se64);
    ++i64;
  }
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  auto v65 = e.AllConstraints();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    std::string se65(e65.data(), e65.size());
    sv65.set(i65, se65);
    ++i65;
  }
  auto v24 = e.AllExpressions();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
  auto v66 = e.AssemblyString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal9(es.EntityId(e.LBraceToken()));
  b.setVal19(e.HasBraces());
}

void SerializeGCCAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal9(es.EntityId(e.AssemblyString()));
  b.setVal10(es.EntityId(e.RParenToken()));
  b.setVal19(e.IsAssemblyGoto());
  auto v24 = e.Labels();
  auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
  auto i24 = 0u;
  for (const auto &e24 : v24) {
    sv24.set(i24, es.EntityId(e24));
    ++i24;
  }
  auto v51 = e.OutputConstraintLiterals();
  auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
  auto i51 = 0u;
  for (const auto &e51 : v51) {
    sv51.set(i51, es.EntityId(e51));
    ++i51;
  }
  auto v65 = e.OutputNames();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const auto &e65 : v65) {
    std::string se65(e65.data(), e65.size());
    sv65.set(i65, se65);
    ++i65;
  }
  auto v52 = e.InputConstraintLiterals();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const auto &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
  auto v67 = e.InputNames();
  auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
  auto i67 = 0u;
  for (const auto &e67 : v67) {
    std::string se67(e67.data(), e67.size());
    sv67.set(i67, se67);
    ++i67;
  }
  auto v53 = e.ClobberStringLiterals();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v68 = e.LabelExpressions();
  auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
  auto i68 = 0u;
  for (const auto &e68 : v68) {
    sv68.set(i68, es.EntityId(e68));
    ++i68;
  }
  auto v69 = e.LabelNames();
  auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
  auto i69 = 0u;
  for (const auto &e69 : v69) {
    std::string se69(e69.data(), e69.size());
    sv69.set(i69, se69);
    ++i69;
  }
}

void SerializeWhileStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  auto v10 = e.ConditionVariable();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  b.setVal13(es.EntityId(e.LParenToken()));
  b.setVal16(es.EntityId(e.RParenToken()));
  b.setVal17(es.EntityId(e.WhileToken()));
  b.setVal19(e.HasVariableStorage());
}

void SerializeValueStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v8 = e.ExpressionStatement();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
}

void SerializeLabelStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal9(es.EntityId(e.Declaration()));
  b.setVal10(es.EntityId(e.IdentifierToken()));
  auto v61 = e.Name();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal12(es.EntityId(e.SubStatement()));
  b.setVal14(e.IsSideEntry());
}

void SerializeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal14(e.HasSideEffects());
  b.setVal9(es.EntityId(e.IgnoreCasts()));
  b.setVal10(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal12(es.EntityId(e.IgnoreImpCasts()));
  b.setVal13(es.EntityId(e.IgnoreImplicit()));
  b.setVal16(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal17(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal18(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal25(es.EntityId(e.IgnoreParenthesisImpCasts()));
  b.setVal26(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal27(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal28(es.EntityId(e.IgnoreParentheses()));
  b.setVal29(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal19(e.ContainsErrors());
  b.setVal20(e.ContainsUnexpandedParameterPack());
  b.setVal30(es.EntityId(e.BestDynamicClassTypeExpression()));
  b.setVal31(es.EntityId(e.ExpressionToken()));
  auto v32 = e.ObjCProperty();
  if (v32) {
    if (auto id32 = es.EntityId(v32.value())) {
      b.setVal32(id32);
      b.setVal55(true);
    } else {
      b.setVal55(false);
    }
  } else {
    b.setVal55(false);
  }
  b.setVal60(static_cast<unsigned short>(mx::FromPasta(e.ObjectKind())));
  auto v33 = e.ReferencedDeclarationOfCallee();
  if (v33) {
    if (auto id33 = es.EntityId(v33.value())) {
      b.setVal33(id33);
      b.setVal56(true);
    } else {
      b.setVal56(false);
    }
  } else {
    b.setVal56(false);
  }
  auto v34 = e.SourceBitField();
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
  b.setVal70(static_cast<unsigned short>(mx::FromPasta(e.ValueKind())));
  b.setVal58(e.HasNonTrivialCall());
  b.setVal59(e.IsDefaultArgument());
  b.setVal71(e.IsGLValue());
  b.setVal72(e.IsImplicitCXXThis());
  b.setVal73(e.IsInstantiationDependent());
  b.setVal74(e.IsKnownToHaveBooleanValue());
  b.setVal75(e.IsLValue());
  b.setVal76(e.IsOBJCGCCandidate());
  b.setVal77(e.IsObjCSelfExpression());
  b.setVal78(e.IsOrdinaryOrBitFieldObject());
  b.setVal79(e.IsPRValue());
  b.setVal80(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal81(e.IsTypeDependent());
  b.setVal82(e.IsValueDependent());
  b.setVal83(e.IsXValue());
  b.setVal84(e.RefersToBitField());
  b.setVal85(e.RefersToGlobalRegisterVariable());
  b.setVal86(e.RefersToMatrixElement());
  b.setVal87(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r35 = e.DesignatorsSourceRange(); auto rs35 = r35.Size()) {
    b.setVal35(es.EntityId(r35[0]));
    b.setVal36(es.EntityId(r35[rs35 - 1u]));
  } else {
    b.setVal35(0);
    b.setVal36(0);
  }
  b.setVal37(es.EntityId(e.EqualOrColonToken()));
  b.setVal38(es.EntityId(e.Initializer()));
  b.setVal88(e.IsDirectInitializer());
  b.setVal89(e.UsesGNUSyntax());
  auto v15 = e.SubExpressions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LAngleToken()));
  b.setVal36(es.EntityId(e.RAngleToken()));
  b.setVal37(es.EntityId(e.TemplateKeywordToken()));
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.KeywordToken()));
  b.setVal36(es.EntityId(e.Operand()));
  b.setVal37(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Declaration()));
  b.setVal36(es.EntityId(e.FoundDeclaration()));
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.RAngleToken()));
  b.setVal39(es.EntityId(e.TemplateKeywordToken()));
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasQualifier());
  b.setVal91(e.HasTemplateKWAndArgumentsInfo());
  b.setVal92(e.HasTemplateKeyword());
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal94(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.CommonExpression()));
  b.setVal36(es.EntityId(e.KeywordToken()));
  b.setVal37(es.EntityId(e.OpaqueValue()));
  b.setVal38(es.EntityId(e.ReadyExpression()));
  b.setVal39(es.EntityId(e.ResumeExpression()));
  b.setVal40(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal41(es.EntityId(e.Operand()));
  b.setVal88(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal41(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  b.setVal37(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  auto v95 = e.TemplateArguments();
  auto sv95 = b.initVal95(static_cast<unsigned>(v95.size()));
  auto i95 = 0u;
  for (const auto &e95 : v95) {
    auto o95 = es.next_pseudo_entity_offset++;
    sv95.set(i95, o95);
    SerializeTemplateArgument(es, es.pseudo_builder[o95], e95);
    ++i95;
  }
  b.setVal88(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Initializer()));
  b.setVal36(es.EntityId(e.LParenToken()));
  b.setVal88(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal36(es.EntityId(e.ChosenSubExpression()));
  b.setVal37(es.EntityId(e.Condition()));
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal88(e.IsConditionDependent());
  b.setVal89(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.CastKind())));
  auto v61 = e.CastKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto v35 = e.ConversionFunction();
  if (v35) {
    if (auto id35 = es.EntityId(v35.value())) {
      b.setVal35(id35);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal36(es.EntityId(e.SubExpression()));
  b.setVal37(es.EntityId(e.SubExpressionAsWritten()));
  auto v38 = e.TargetUnionField();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal90(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal91(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r39 = e.AngleBrackets(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  auto v66 = e.CastName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal42(es.EntityId(e.RParenToken()));
}

void SerializeCXXDynamicCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal91(e.IsAlwaysNull());
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
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal91(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal39(es.EntityId(e.BridgeKeywordToken()));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.BridgeKind())));
  auto v66 = e.BridgeKindName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal40(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.Arguments();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.ADLCallKind())));
  b.setVal35(es.EntityId(e.Callee()));
  auto v36 = e.CalleeDeclaration();
  if (v36) {
    if (auto id36 = es.EntityId(v36.value())) {
      b.setVal36(id36);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  auto v37 = e.DirectCallee();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.HasUnusedResultAttribute());
  b.setVal92(e.IsBuiltinAssumeFalse());
  b.setVal94(e.IsCallToStdMove());
  b.setVal97(e.IsUnevaluatedBuiltinCall());
  b.setVal98(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal39(es.EntityId(e.OperatorToken()));
  b.setVal99(e.IsAssignmentOperation());
  b.setVal100(e.IsComparisonOperation());
  b.setVal101(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal39(es.EntityId(e.ImplicitObjectArgument()));
  b.setVal40(es.EntityId(e.MethodDeclaration()));
  b.setVal41(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal39(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal39(es.EntityId(e.CookedLiteral()));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal40(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ExpressionOperand()));
  b.setVal36(es.EntityId(e.GuidDeclaration()));
  b.setVal88(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.Arguments();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal35(es.EntityId(e.LParenToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  b.setVal88(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ExpressionOperand()));
  b.setVal88(e.IsMostDerived());
  b.setVal89(e.IsPotentiallyEvaluated());
  b.setVal90(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
  b.setVal36(es.EntityId(e.ThrowToken()));
  b.setVal88(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
  b.setVal88(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.RParenToken()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LHS()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal36(es.EntityId(e.OperatorToken()));
  b.setVal37(es.EntityId(e.RHS()));
  b.setVal38(es.EntityId(e.SemanticForm()));
  b.setVal88(e.IsAssignmentOperation());
  b.setVal89(e.IsComparisonOperation());
  b.setVal90(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.ColonColonToken()));
  b.setVal37(es.EntityId(e.DestroyedTypeToken()));
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.TildeToken()));
  b.setVal88(e.HasQualifier());
  b.setVal89(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Operand()));
  b.setVal88(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.DoesUsualArrayDeleteWantSize());
  auto v35 = e.ArraySize();
  if (v35) {
    if (auto id35 = es.EntityId(v35.value())) {
      b.setVal35(id35);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal36(es.EntityId(e.ConstructExpression()));
  if (auto r37 = e.DirectInitializerRange(); auto rs37 = r37.Size()) {
    b.setVal37(es.EntityId(r37[0]));
    b.setVal38(es.EntityId(r37[rs37 - 1u]));
  } else {
    b.setVal37(0);
    b.setVal38(0);
  }
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.InitializationStyle())));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal41(es.EntityId(e.OperatorNew()));
  if (auto r42 = e.TypeIdParentheses(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  b.setVal90(e.HasInitializer());
  b.setVal91(e.IsArray());
  b.setVal92(e.IsGlobalNew());
  b.setVal94(e.IsParenthesisTypeId());
  b.setVal97(e.PassAlignment());
  auto v15 = e.PlacementArguments();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal98(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.ConstructsVirtualBase());
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal35(es.EntityId(e.Constructor()));
  b.setVal36(es.EntityId(e.Token()));
  b.setVal89(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Callee()));
  b.setVal36(es.EntityId(e.EllipsisToken()));
  b.setVal37(es.EntityId(e.Initializer()));
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Operator())));
  b.setVal40(es.EntityId(e.Pattern()));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.RParenToken()));
  b.setVal88(e.IsLeftFold());
  b.setVal89(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.FirstQualifierFoundInScope()));
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.MemberToken()));
  b.setVal39(es.EntityId(e.OperatorToken()));
  b.setVal40(es.EntityId(e.RAngleToken()));
  b.setVal41(es.EntityId(e.TemplateKeywordToken()));
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.DoesUsualArrayDeleteWantSize());
  b.setVal35(es.EntityId(e.Argument()));
  b.setVal36(es.EntityId(e.OperatorDelete()));
  b.setVal89(e.IsArrayForm());
  b.setVal90(e.IsArrayFormAsWritten());
  b.setVal91(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Expression()));
  b.setVal36(es.EntityId(e.Field()));
  b.setVal37(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Expression()));
  b.setVal36(es.EntityId(e.Parameter()));
  b.setVal37(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.Arguments();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.ConstructionKind())));
  b.setVal35(es.EntityId(e.Constructor()));
  b.setVal36(es.EntityId(e.Token()));
  if (auto r37 = e.ParenthesisOrBraceRange(); auto rs37 = r37.Size()) {
    b.setVal37(es.EntityId(r37[0]));
    b.setVal38(es.EntityId(r37[rs37 - 1u]));
  } else {
    b.setVal37(0);
    b.setVal38(0);
  }
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.IsElidable());
  b.setVal90(e.IsListInitialization());
  b.setVal91(e.IsStdInitializerListInitialization());
  b.setVal92(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
  b.setVal88(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BlockDeclaration()));
  b.setVal36(es.EntityId(e.Body()));
  b.setVal37(es.EntityId(e.CaretToken()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LHS()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal36(es.EntityId(e.OperatorToken()));
  b.setVal37(es.EntityId(e.RHS()));
  b.setVal88(e.HasStoredFPFeatures());
  b.setVal89(e.IsAdditiveOperation());
  b.setVal90(e.IsAssignmentOperation());
  b.setVal91(e.IsBitwiseOperation());
  b.setVal92(e.IsCommaOperation());
  b.setVal94(e.IsComparisonOperation());
  b.setVal97(e.IsCompoundAssignmentOperation());
  b.setVal98(e.IsEqualityOperation());
  b.setVal99(e.IsLogicalOperation());
  b.setVal100(e.IsMultiplicativeOperation());
  b.setVal101(e.IsPointerMemoryOperation());
  b.setVal102(e.IsRelationalOperation());
  b.setVal103(e.IsShiftAssignOperation());
  b.setVal104(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Operation())));
  b.setVal36(es.EntityId(e.Order()));
  auto v37 = e.OrderFail();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal38(es.EntityId(e.Pointer()));
  b.setVal39(es.EntityId(e.RParenToken()));
  auto v40 = e.Scope();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  auto v41 = e.Value1();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  auto v42 = e.Value2();
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
  auto v43 = e.Weak();
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
  b.setVal94(e.IsCmpXChg());
  b.setVal97(e.IsOpenCL());
  b.setVal98(e.IsVolatile());
  auto v15 = e.SubExpressions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeAsTypeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  b.setVal37(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.DimensionExpression()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.Index()));
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal38(es.EntityId(e.RBracketToken()));
  b.setVal39(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.CommonExpression()));
  b.setVal36(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AmpAmpToken()));
  b.setVal36(es.EntityId(e.Label()));
  b.setVal37(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ColonToken()));
  b.setVal36(es.EntityId(e.Condition()));
  b.setVal37(es.EntityId(e.FalseExpression()));
  b.setVal38(es.EntityId(e.QuestionToken()));
  b.setVal39(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal40(es.EntityId(e.Common()));
  b.setVal41(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal88(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.CanOverflow());
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Opcode())));
  b.setVal35(es.EntityId(e.OperatorToken()));
  b.setVal36(es.EntityId(e.SubExpression()));
  b.setVal89(e.HasStoredFPFeatures());
  b.setVal90(e.IsArithmeticOperation());
  b.setVal91(e.IsDecrementOperation());
  b.setVal92(e.IsIncrementDecrementOperation());
  b.setVal94(e.IsIncrementOperation());
  b.setVal97(e.IsPostfix());
  b.setVal98(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v35 = e.ArgumentExpression();
  if (v35) {
    if (auto id35 = es.EntityId(v35.value())) {
      b.setVal35(id35);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal36(es.EntityId(e.OperatorToken()));
  b.setVal37(es.EntityId(e.RParenToken()));
  b.setVal89(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal88(e.Value());
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ParameterPack()));
  b.setVal36(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.NameToken()));
  b.setVal36(es.EntityId(e.Parameter()));
  b.setVal37(es.EntityId(e.Replacement()));
  b.setVal88(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.ContainsNonAscii());
  b.setVal89(e.ContainsNonAsciiOrNull());
  auto v61 = e.Bytes();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto v66 = e.String();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal90(e.IsAscii());
  b.setVal91(e.IsPascal());
  b.setVal92(e.IsUTF16());
  b.setVal94(e.IsUTF32());
  b.setVal97(e.IsUTF8());
  b.setVal98(e.IsWide());
}

void SerializeStmtExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LParenToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  b.setVal37(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v61 = e.BuiltinString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  b.setVal35(es.EntityId(e.Token()));
  b.setVal88(e.IsIntType());
  b.setVal89(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.OperatorToken()));
  b.setVal36(es.EntityId(e.Pack()));
  b.setVal37(es.EntityId(e.PackToken()));
  auto v95 = e.PartialArguments();
  auto sv95 = b.initVal95(static_cast<unsigned>(v95.size()));
  auto i95 = 0u;
  for (const auto &e95 : v95) {
    auto o95 = es.next_pseudo_entity_offset++;
    sv95.set(i95, o95);
    SerializeTemplateArgument(es, es.pseudo_builder[o95], e95);
    ++i95;
  }
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal88(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BuiltinToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(e.ComputeName());
  b.setVal35(es.EntityId(e.LParenToken()));
  b.setVal36(es.EntityId(e.Token()));
  b.setVal37(es.EntityId(e.RParenToken()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Body()));
  auto v15 = e.LocalParameters();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal36(es.EntityId(e.RBraceToken()));
  b.setVal37(es.EntityId(e.RequiresKWToken()));
  b.setVal88(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.SubExpressions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ResultExpression()));
  b.setVal36(es.EntityId(e.SyntacticForm()));
  auto v15 = e.Semantics();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  auto v21 = e.SemanticExpressions();
  auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
  auto i21 = 0u;
  for (const auto &e21 : v21) {
    sv21.set(i21, es.EntityId(e21));
    ++i21;
  }
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.FunctionName()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.IdentifierKind())));
  auto v61 = e.IdentifierKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal36(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LParenToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
  auto v15 = e.Expressions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeParenExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LParen()));
  b.setVal36(es.EntityId(e.RParen()));
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.EllipsisToken()));
  b.setVal36(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.LAngleToken()));
  b.setVal36(es.EntityId(e.NameToken()));
  b.setVal37(es.EntityId(e.NamingClass()));
  b.setVal38(es.EntityId(e.RAngleToken()));
  b.setVal39(es.EntityId(e.TemplateKeywordToken()));
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal40(es.EntityId(e.Base()));
  b.setVal41(es.EntityId(e.MemberToken()));
  b.setVal42(es.EntityId(e.OperatorToken()));
  b.setVal90(e.HasUnresolvedUsing());
  b.setVal91(e.IsArrow());
  b.setVal92(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal90(e.IsOverloaded());
  b.setVal91(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
  b.setVal36(es.EntityId(e.SourceExpression()));
  b.setVal88(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.OperatorToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal36(es.EntityId(e.BaseExpression()));
  b.setVal37(es.EntityId(e.KeyExpression()));
  b.setVal38(es.EntityId(e.RBracket()));
  b.setVal88(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtToken()));
  b.setVal36(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtToken()));
  b.setVal36(es.EntityId(e.Protocol()));
  b.setVal37(es.EntityId(e.ProtocolIdToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.ClassReceiver()));
  b.setVal37(es.EntityId(e.ExplicitProperty()));
  b.setVal38(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal39(es.EntityId(e.ImplicitPropertySetter()));
  b.setVal40(es.EntityId(e.Token()));
  b.setVal41(es.EntityId(e.ReceiverToken()));
  b.setVal88(e.IsClassReceiver());
  b.setVal89(e.IsExplicitProperty());
  b.setVal90(e.IsImplicitProperty());
  b.setVal91(e.IsMessagingGetter());
  b.setVal92(e.IsMessagingSetter());
  b.setVal94(e.IsObjectReceiver());
  b.setVal97(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.Arguments();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal35(es.EntityId(e.InstanceReceiver()));
  b.setVal36(es.EntityId(e.LeftToken()));
  b.setVal37(es.EntityId(e.MethodDeclaration()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal38(es.EntityId(e.ReceiverInterface()));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.ReceiverKind())));
  if (auto r39 = e.ReceiverRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal41(es.EntityId(e.RightToken()));
  b.setVal42(es.EntityId(e.SelectorStartToken()));
  b.setVal43(es.EntityId(e.SuperToken()));
  b.setVal88(e.IsClassMessage());
  b.setVal89(e.IsDelegateInitializerCall());
  b.setVal90(e.IsImplicit());
  b.setVal91(e.IsInstanceMessage());
  auto v21 = e.SelectorTokens();
  auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
  auto i21 = 0u;
  for (const auto &e21 : v21) {
    sv21.set(i21, es.EntityId(e21));
    ++i21;
  }
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.Declaration()));
  b.setVal37(es.EntityId(e.Token()));
  b.setVal38(es.EntityId(e.OperationToken()));
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.BaseTokenEnd()));
  b.setVal37(es.EntityId(e.IsaMemberToken()));
  b.setVal38(es.EntityId(e.OperationToken()));
  b.setVal88(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
  b.setVal88(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtToken()));
  b.setVal36(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.AtToken()));
  b.setVal36(es.EntityId(e.BoxingMethod()));
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal88(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
  b.setVal88(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ArrayWithObjectsMethod()));
  auto v15 = e.Elements();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeOMPIteratorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.IteratorKwToken()));
  b.setVal36(es.EntityId(e.LParenToken()));
  b.setVal37(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  auto v15 = e.Dimensions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal36(es.EntityId(e.LParenToken()));
  b.setVal37(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.ColonTokenFirst()));
  b.setVal37(es.EntityId(e.ColonTokenSecond()));
  b.setVal38(es.EntityId(e.Length()));
  b.setVal39(es.EntityId(e.LowerBound()));
  b.setVal40(es.EntityId(e.RBracketToken()));
  b.setVal41(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.LAngleToken()));
  b.setVal37(es.EntityId(e.MemberDeclaration()));
  b.setVal38(es.EntityId(e.MemberToken()));
  b.setVal39(es.EntityId(e.OperatorToken()));
  b.setVal40(es.EntityId(e.RAngleToken()));
  b.setVal41(es.EntityId(e.TemplateKeywordToken()));
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasQualifier());
  b.setVal91(e.HasTemplateKeyword());
  b.setVal92(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.ColumnIndex()));
  b.setVal37(es.EntityId(e.RBracketToken()));
  b.setVal38(es.EntityId(e.RowIndex()));
  b.setVal88(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ExtendingDeclaration()));
  b.setVal36(es.EntityId(e.LifetimeExtendedTemporaryDeclaration()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal88(e.IsBoundToLvalueReference());
  b.setVal89(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Base()));
  b.setVal36(es.EntityId(e.Index()));
  b.setVal37(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.BaseExpression()));
  b.setVal36(es.EntityId(e.MemberToken()));
  b.setVal37(es.EntityId(e.PropertyDeclaration()));
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Body()));
  b.setVal36(es.EntityId(e.CallOperator()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.CaptureDefault())));
  b.setVal37(es.EntityId(e.CaptureDefaultToken()));
  b.setVal38(es.EntityId(e.CompoundStatementBody()));
  auto v15 = e.ExplicitTemplateParameters();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  if (auto r39 = e.IntroducerRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal41(es.EntityId(e.LambdaClass()));
  auto v105 = e.TemplateParameterList();
  if (v105) {
    auto o105 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o105], v105.value());
    b.setVal105(o105);
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  auto v42 = e.TrailingRequiresClause();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal90(e.HasExplicitParameters());
  b.setVal91(e.HasExplicitResultType());
  b.setVal92(e.IsGenericLambda());
  b.setVal94(e.IsMutable());
}

void SerializeIntegerLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v35 = e.ArrayFiller();
  if (v35) {
    if (auto id35 = es.EntityId(v35.value())) {
      b.setVal35(id35);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  auto v36 = e.InitializedFieldInUnion();
  if (v36) {
    if (auto id36 = es.EntityId(v36.value())) {
      b.setVal36(id36);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal37(es.EntityId(e.LBraceToken()));
  b.setVal38(es.EntityId(e.RBraceToken()));
  auto v39 = e.SemanticForm();
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
  auto v40 = e.SyntacticForm();
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
  b.setVal92(e.HadArrayRangeDesignator());
  b.setVal94(e.HasArrayFiller());
  auto v15 = e.Initializers();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal97(e.IsExplicit());
  b.setVal98(e.IsSemanticForm());
  b.setVal99(e.IsStringLiteralInitializer());
  b.setVal100(e.IsSyntacticForm());
  b.setVal101(e.IsTransparent());
}

void SerializeImplicitValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  auto v15 = e.AssociationExpressions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
  b.setVal35(es.EntityId(e.ControllingExpression()));
  b.setVal36(es.EntityId(e.DefaultToken()));
  b.setVal37(es.EntityId(e.GenericToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.ResultExpression()));
  b.setVal88(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.ParameterPack()));
  b.setVal36(es.EntityId(e.ParameterPackToken()));
  auto v15 = e.Expansions();
  auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
  auto i15 = 0u;
  for (const auto &e15 : v15) {
    sv15.set(i15, es.EntityId(e15));
    ++i15;
  }
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal88(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal88(e.HasAPValueResult());
  b.setVal89(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
  b.setVal88(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal88(e.ContainsDuplicateElements());
  b.setVal35(es.EntityId(e.AccessorToken()));
  b.setVal36(es.EntityId(e.Base()));
  b.setVal89(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal35(es.EntityId(e.QueriedExpression()));
  b.setVal93(static_cast<unsigned short>(mx::FromPasta(e.Trait())));
  b.setVal88(e.Value());
}

void SerializeAttributedStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal9(es.EntityId(e.AttributeToken()));
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  auto v10 = e.ConditionVariable();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    if (auto id12 = es.EntityId(v12.value())) {
      b.setVal12(id12);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  auto v13 = e.Initializer();
  if (v13) {
    if (auto id13 = es.EntityId(v13.value())) {
      b.setVal13(id13);
      b.setVal19(true);
    } else {
      b.setVal19(false);
    }
  } else {
    b.setVal19(false);
  }
  b.setVal16(es.EntityId(e.LParenToken()));
  b.setVal17(es.EntityId(e.RParenToken()));
  auto v18 = e.FirstSwitchCase();
  if (v18) {
    if (auto id18 = es.EntityId(v18.value())) {
      b.setVal18(id18);
      b.setVal20(true);
    } else {
      b.setVal20(false);
    }
  } else {
    b.setVal20(false);
  }
  b.setVal25(es.EntityId(e.SwitchToken()));
  b.setVal55(e.HasInitializerStorage());
  b.setVal56(e.HasVariableStorage());
  b.setVal57(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ColonToken()));
  b.setVal9(es.EntityId(e.KeywordToken()));
  auto v10 = e.NextSwitchCase();
  if (v10) {
    if (auto id10 = es.EntityId(v10.value())) {
      b.setVal10(id10);
      b.setVal11(true);
    } else {
      b.setVal11(false);
    }
  } else {
    b.setVal11(false);
  }
  b.setVal12(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal13(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal14(e.CaseStatementIsGNURange());
  b.setVal13(es.EntityId(e.CaseToken()));
  b.setVal16(es.EntityId(e.EllipsisToken()));
  b.setVal17(es.EntityId(e.LHS()));
  auto v18 = e.RHS();
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
}

void SerializeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  b.setVal0(static_cast<unsigned short>(mx::FromPasta(e.Access())));
  b.setVal1(static_cast<unsigned short>(mx::FromPasta(e.AccessUnsafe())));
  b.setVal2(static_cast<unsigned short>(mx::FromPasta(e.Availability())));
  b.setVal3(es.EntityId(e.BeginToken()));
  b.setVal4(es.EntityId(e.BodyRBrace()));
  b.setVal5(es.EntityId(e.CanonicalDeclaration()));
  auto v6 = e.DescribedTemplateParameters();
  if (v6) {
    auto o6 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o6], v6.value());
    b.setVal6(o6);
    b.setVal7(true);
  } else {
    b.setVal7(false);
  }
  b.setVal8(es.EntityId(e.EndToken()));
  b.setVal9(static_cast<unsigned short>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal10(static_cast<unsigned short>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setVal11(es.EntityId(e.MostRecentDeclaration()));
  auto v12 = e.NextDeclarationInContext();
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
  auto v14 = e.NonClosureContext();
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
  auto v16 = e.PreviousDeclaration();
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
  b.setVal18(e.HasAttributes());
  b.setVal19(e.HasDefiningAttribute());
  b.setVal20(e.HasOwningModule());
  b.setVal21(e.HasTagIdentifierNamespace());
  b.setVal22(e.IsCanonicalDeclaration());
  b.setVal23(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal24(e.IsDeprecated());
  b.setVal25(e.IsFirstDeclaration());
  b.setVal26(e.IsFunctionOrFunctionTemplate());
  b.setVal27(e.IsImplicit());
  b.setVal28(e.IsInAnonymousNamespace());
  b.setVal29(e.IsInLocalScopeForInstantiation());
  b.setVal30(e.IsInStdNamespace());
  b.setVal31(e.IsInvalidDeclaration());
  b.setVal32(e.IsModulePrivate());
  b.setVal33(e.IsOutOfLine());
  b.setVal34(e.IsParameterPack());
  b.setVal35(e.IsReferenced());
  b.setVal36(e.IsTemplateDeclaration());
  b.setVal37(e.IsTemplateParameter());
  b.setVal38(e.IsTemplateParameterPack());
  b.setVal39(e.IsTemplated());
  b.setVal40(e.IsThisDeclarationReferenced());
  b.setVal41(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal42(e.IsUnavailable());
  b.setVal43(e.IsUnconditionallyVisible());
  b.setVal44(e.IsUsed());
  b.setVal45(e.IsWeakImported());
  auto v46 = e.Redeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const auto &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
  b.setVal47(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  b.setVal48(es.EntityId(e.Token()));
  if (auto r49 = e.TokenRange(); auto rs49 = r49.Size()) {
    b.setVal49(es.EntityId(r49[0]));
    b.setVal50(es.EntityId(r49[rs49 - 1u]));
  } else {
    b.setVal49(0);
    b.setVal50(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.Specialization()));
  b.setVal52(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.ContextParameter()));
  b.setVal52(e.IsNothrow());
  auto v53 = e.Parameters();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal52(e.BlockMissingReturnType());
  b.setVal55(e.CanAvoidCopyToHeap());
  b.setVal56(e.CapturesCXXThis());
  b.setVal57(e.DoesNotEscape());
  b.setVal51(es.EntityId(e.BlockManglingContextDeclaration()));
  b.setVal58(es.EntityId(e.CaretToken()));
  b.setVal59(es.EntityId(e.CompoundBody()));
  b.setVal60(e.HasCaptures());
  b.setVal61(e.IsConversionFromLambda());
  b.setVal62(e.IsVariadic());
  auto v53 = e.Parameters();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v54 = e.ParameterDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  pasta::DeclContext dc63(e);
  auto v63 = dc63.AlreadyLoadedDeclarations();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const pasta::Decl &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.AccessSpecifierToken()));
  b.setVal58(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  auto v53 = e.Varlists();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeOMPRequiresDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e) {
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  auto v53 = e.Varlists();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.AssertExpression()));
  b.setVal58(es.EntityId(e.Message()));
  b.setVal59(es.EntityId(e.RParenToken()));
  b.setVal52(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  SerializeDecl(es, b, e);
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  SerializeDecl(es, b, e);
  auto v64 = e.Name();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto v65 = e.Value();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  SerializeDecl(es, b, e);
  auto v64 = e.Argument();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal66(static_cast<unsigned short>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.GetterCXXConstructor()));
  b.setVal58(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal59(es.EntityId(e.PropertyDeclaration()));
  b.setVal66(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal67(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal68(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal69(es.EntityId(e.SetterCXXAssignment()));
  b.setVal70(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal52(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal66(static_cast<unsigned short>(mx::FromPasta(e.FormalLinkage())));
  b.setVal71(static_cast<unsigned short>(mx::FromPasta(e.LinkageInternal())));
  b.setVal64(e.Name());
  b.setVal72(static_cast<unsigned short>(mx::FromPasta(e.ObjCFStringFormattingFamily())));
  b.setVal65(e.QualifiedNameAsString());
  b.setVal51(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal73(static_cast<unsigned short>(mx::FromPasta(e.Visibility())));
  b.setVal52(e.HasExternalFormalLinkage());
  b.setVal55(e.HasLinkage());
  b.setVal56(e.HasLinkageBeenComputed());
  b.setVal57(e.IsCXXClassMember());
  b.setVal60(e.IsCXXInstanceMember());
  b.setVal61(e.IsExternallyDeclarable());
  b.setVal62(e.IsExternallyVisible());
  b.setVal74(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v75 = e.MSAssemblyLabel();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal58(es.EntityId(e.Statement()));
  b.setVal76(e.IsGnuLocal());
  b.setVal77(e.IsMSAssemblyLabel());
  b.setVal78(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v53 = e.Shadows();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal58(es.EntityId(e.EnumDeclaration()));
  b.setVal59(es.EntityId(e.EnumToken()));
  b.setVal67(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  SerializeBaseUsingDecl(es, b, e);
  b.setVal58(es.EntityId(e.UsingToken()));
  b.setVal76(e.HasTypename());
  b.setVal77(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal76(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal58(es.EntityId(e.EllipsisToken()));
  b.setVal59(es.EntityId(e.UsingToken()));
  b.setVal77(e.IsAccessDeclaration());
  b.setVal78(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal58(es.EntityId(e.Combiner()));
  b.setVal59(es.EntityId(e.CombinerIn()));
  b.setVal67(es.EntityId(e.CombinerOut()));
  b.setVal68(es.EntityId(e.InitializerOriginal()));
  b.setVal69(es.EntityId(e.InitializerPrivate()));
  b.setVal70(es.EntityId(e.Initializer()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.InitializerKind())));
  b.setVal80(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeMSGuidDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e) {
  SerializeValueDecl(es, b, e);
  auto v53 = e.Chain();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v58 = e.AnonymousField();
  if (v58) {
    if (auto id58 = es.EntityId(v58.value())) {
      b.setVal58(id58);
      b.setVal77(true);
    } else {
      b.setVal77(false);
    }
  } else {
    b.setVal77(false);
  }
  auto v59 = e.VariableDeclaration();
  if (v59) {
    if (auto id59 = es.EntityId(v59.value())) {
      b.setVal59(id59);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  SerializeValueDecl(es, b, e);
  auto v58 = e.InitializerExpression();
  if (v58) {
    if (auto id58 = es.EntityId(v58.value())) {
      b.setVal58(id58);
      b.setVal77(true);
    } else {
      b.setVal77(false);
    }
  } else {
    b.setVal77(false);
  }
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal58(es.EntityId(e.InnerTokenStart()));
  b.setVal59(es.EntityId(e.OuterTokenStart()));
  auto v67 = e.TrailingRequiresClause();
  if (v67) {
    if (auto id67 = es.EntityId(v67.value())) {
      b.setVal67(id67);
      b.setVal77(true);
    } else {
      b.setVal77(false);
    }
  } else {
    b.setVal77(false);
  }
  b.setVal68(es.EntityId(e.TypeSpecEndToken()));
  b.setVal69(es.EntityId(e.TypeSpecStartToken()));
  auto v81 = e.TemplateParameterLists();
  auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
  auto i81 = 0u;
  for (const auto &e81 : v81) {
    auto o81 = es.next_pseudo_entity_offset++;
    sv81.set(i81, o81);
    SerializeTemplateParameterList(es, es.pseudo_builder[o81], e81);
    ++i81;
  }
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.ActingDefinition();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
  auto v80 = e.Initializer();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.InitializerStyle())));
  auto v83 = e.InitializingDeclaration();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  auto v85 = e.InstantiatedFromStaticDataMember();
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
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal88(es.EntityId(e.PointOfInstantiation()));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  b.setVal90(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.TLSKind())));
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.TSCSpec())));
  auto v93 = e.TemplateInstantiationPattern();
  if (v93) {
    if (auto id93 = es.EntityId(v93.value())) {
      b.setVal93(id93);
      b.setVal94(true);
    } else {
      b.setVal94(false);
    }
  } else {
    b.setVal94(false);
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal97(e.HasConstantInitialization());
  b.setVal98(e.HasDependentAlignment());
  b.setVal99(e.HasExternalStorage());
  b.setVal100(e.HasGlobalStorage());
  b.setVal101(e.HasInitializer());
  b.setVal102(e.HasLocalStorage());
  b.setVal103(e.IsARCPseudoStrong());
  b.setVal104(e.IsCXXForRangeDeclaration());
  b.setVal105(e.IsConstexpr());
  b.setVal106(e.IsDirectInitializer());
  b.setVal107(e.IsEscapingByref());
  b.setVal108(e.IsExceptionVariable());
  b.setVal109(e.IsExternC());
  b.setVal110(e.IsFileVariableDeclaration());
  b.setVal111(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal112(e.IsInExternCContext());
  b.setVal113(e.IsInExternCXXContext());
  b.setVal114(e.IsInitializerCapture());
  b.setVal115(e.IsInline());
  b.setVal116(e.IsInlineSpecified());
  b.setVal117(e.IsKnownToBeDefined());
  b.setVal118(e.IsLocalVariableDeclaration());
  b.setVal119(e.IsLocalVariableDeclarationOrParm());
  b.setVal120(e.IsNRVOVariable());
  b.setVal121(e.IsNoDestroy());
  b.setVal122(e.IsNonEscapingByref());
  b.setVal123(e.IsObjCForDeclaration());
  b.setVal124(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal125(e.IsStaticDataMember());
  b.setVal126(e.IsStaticLocal());
  b.setVal127(e.IsThisDeclarationADemotedDefinition());
  b.setVal128(e.IsUsableInConstantExpressions());
  b.setVal129(e.MightBeUsableInConstantExpressions());
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  SerializeVarDecl(es, b, e);
  auto v131 = e.DefaultArgument();
  if (v131) {
    if (auto id131 = es.EntityId(v131.value())) {
      b.setVal131(id131);
      b.setVal132(true);
    } else {
      b.setVal132(false);
    }
  } else {
    b.setVal132(false);
  }
  if (auto r133 = e.DefaultArgumentRange(); auto rs133 = r133.Size()) {
    b.setVal133(es.EntityId(r133[0]));
    b.setVal134(es.EntityId(r133[rs133 - 1u]));
  } else {
    b.setVal133(0);
    b.setVal134(0);
  }
  b.setVal135(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  auto v136 = e.UninstantiatedDefaultArgument();
  if (v136) {
    if (auto id136 = es.EntityId(v136.value())) {
      b.setVal136(id136);
      b.setVal137(true);
    } else {
      b.setVal137(false);
    }
  } else {
    b.setVal137(false);
  }
  b.setVal138(e.HasDefaultArgument());
  b.setVal139(e.HasInheritedDefaultArgument());
  b.setVal140(e.HasUninstantiatedDefaultArgument());
  b.setVal141(e.HasUnparsedDefaultArgument());
  b.setVal142(e.IsDestroyedInCallee());
  b.setVal143(e.IsKNRPromoted());
  b.setVal144(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal135(static_cast<unsigned short>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  SerializeVarDecl(es, b, e);
  auto v53 = e.Bindings();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  SerializeVarDecl(es, b, e);
  b.setVal131(es.EntityId(e.ExternToken()));
  b.setVal135(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v145 = e.TemplateArguments();
  auto sv145 = b.initVal145(static_cast<unsigned>(v145.size()));
  auto i145 = 0u;
  for (const auto &e145 : v145) {
    auto o145 = es.next_pseudo_entity_offset++;
    sv145.set(i145, o145);
    SerializeTemplateArgument(es, es.pseudo_builder[o145], e145);
    ++i145;
  }
  auto v146 = e.TemplateInstantiationArguments();
  auto sv146 = b.initVal146(static_cast<unsigned>(v146.size()));
  auto i146 = 0u;
  for (const auto &e146 : v146) {
    auto o146 = es.next_pseudo_entity_offset++;
    sv146.set(i146, o146);
    SerializeTemplateArgument(es, es.pseudo_builder[o146], e146);
    ++i146;
  }
  b.setVal133(es.EntityId(e.TemplateKeywordToken()));
  b.setVal132(e.IsClassScopeExplicitSpecialization());
  b.setVal137(e.IsExplicitInstantiationOrSpecialization());
  b.setVal138(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
}

void SerializeNonTypeTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal78(e.DefaultArgumentWasInherited());
  b.setVal70(es.EntityId(e.DefaultArgument()));
  b.setVal80(es.EntityId(e.DefaultArgumentToken()));
  b.setVal83(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal82(e.HasDefaultArgument());
  b.setVal84(e.HasPlaceholderTypeConstraint());
  b.setVal86(e.IsExpandedParameterPack());
  b.setVal94(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal78(e.HasGetter());
  b.setVal82(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  b.setVal78(e.DoesThisDeclarationHaveABody());
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.ConstexprKind())));
  auto v70 = e.Definition();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal80(es.EntityId(e.EllipsisToken()));
  if (auto r83 = e.ExceptionSpecSourceRange(); auto rs83 = r83.Size()) {
    b.setVal83(es.EntityId(r83[0]));
    b.setVal85(es.EntityId(r83[rs83 - 1u]));
  } else {
    b.setVal83(0);
    b.setVal85(0);
  }
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.ExceptionSpecType())));
  auto v88 = e.InstantiatedFromMemberFunction();
  if (v88) {
    if (auto id88 = es.EntityId(v88.value())) {
      b.setVal88(id88);
      b.setVal84(true);
    } else {
      b.setVal84(false);
    }
  } else {
    b.setVal84(false);
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal90(static_cast<unsigned short>(mx::FromPasta(e.MultiVersionKind())));
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r93 = e.ParametersSourceRange(); auto rs93 = r93.Size()) {
    b.setVal93(es.EntityId(r93[0]));
    b.setVal131(es.EntityId(r93[rs93 - 1u]));
  } else {
    b.setVal93(0);
    b.setVal131(0);
  }
  b.setVal133(es.EntityId(e.PointOfInstantiation()));
  if (auto r134 = e.ReturnTypeSourceRange(); auto rs134 = r134.Size()) {
    b.setVal134(es.EntityId(r134[0]));
    b.setVal136(es.EntityId(r134[rs134 - 1u]));
  } else {
    b.setVal134(0);
    b.setVal136(0);
  }
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.StorageClass())));
  auto v147 = e.TemplateInstantiationPattern();
  if (v147) {
    if (auto id147 = es.EntityId(v147.value())) {
      b.setVal147(id147);
      b.setVal86(true);
    } else {
      b.setVal86(false);
    }
  } else {
    b.setVal86(false);
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal130(static_cast<unsigned short>(mx::FromPasta(e.TemplatedKind())));
  b.setVal94(e.HasImplicitReturnZero());
  b.setVal97(e.HasInheritedPrototype());
  b.setVal98(e.HasOneParameterOrDefaultArguments());
  b.setVal99(e.HasPrototype());
  b.setVal100(e.HasSkippedBody());
  b.setVal101(e.HasTrivialBody());
  b.setVal102(e.HasWrittenPrototype());
  b.setVal103(e.InstantiationIsPending());
  b.setVal104(e.IsCPUDispatchMultiVersion());
  b.setVal105(e.IsCPUSpecificMultiVersion());
  b.setVal106(e.IsConsteval());
  b.setVal107(e.IsConstexpr());
  b.setVal108(e.IsConstexprSpecified());
  b.setVal109(e.IsDefaulted());
  b.setVal110(e.IsDeleted());
  b.setVal111(e.IsDeletedAsWritten());
  b.setVal112(e.IsDestroyingOperatorDelete());
  b.setVal113(e.IsExplicitlyDefaulted());
  b.setVal114(e.IsExternC());
  b.setVal115(e.IsFunctionTemplateSpecialization());
  b.setVal116(e.IsGlobal());
  b.setVal117(e.IsImplicitlyInstantiable());
  b.setVal118(e.IsInExternCContext());
  b.setVal119(e.IsInExternCXXContext());
  b.setVal120(e.IsInlineBuiltinDeclaration());
  b.setVal121(e.IsInlineSpecified());
  b.setVal122(e.IsInlined());
  b.setVal123(e.IsLateTemplateParsed());
  b.setVal124(e.IsMSVCRTEntryPoint());
  b.setVal125(e.IsMain());
  b.setVal126(e.IsMultiVersion());
  b.setVal127(e.IsNoReturn());
  b.setVal128(e.IsOverloadedOperator());
  b.setVal129(e.IsPure());
  b.setVal132(e.IsReplaceableGlobalAllocationFunction());
  b.setVal137(e.IsStatic());
  b.setVal138(e.IsTargetMultiVersion());
  b.setVal139(e.IsTemplateInstantiation());
  b.setVal140(e.IsThisDeclarationADefinition());
  b.setVal141(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal142(e.IsTrivial());
  b.setVal143(e.IsTrivialForCall());
  b.setVal144(e.IsUserProvided());
  b.setVal148(e.IsVariadic());
  b.setVal149(e.IsVirtualAsWritten());
  auto v53 = e.Parameters();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  b.setVal150(e.UsesSEHTry());
  b.setVal151(e.WillHaveBody());
  auto v152 = e.Body();
  if (v152) {
    if (auto id152 = es.EntityId(v152.value())) {
      b.setVal152(id152);
      b.setVal153(true);
    } else {
      b.setVal153(false);
    }
  } else {
    b.setVal153(false);
  }
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal154(es.EntityId(e.Parent()));
  b.setVal135(static_cast<unsigned short>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal155(e.HasInlineBody());
  b.setVal156(e.IsConst());
  b.setVal157(e.IsCopyAssignmentOperator());
  b.setVal158(e.IsInstance());
  b.setVal159(e.IsLambdaStaticInvoker());
  b.setVal160(e.IsMoveAssignmentOperator());
  b.setVal161(e.IsVirtual());
  b.setVal162(e.IsVolatile());
  auto v63 = e.OverriddenMethods();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal163(es.EntityId(e.OperatorDelete()));
  b.setVal164(es.EntityId(e.OperatorDeleteThisArgument()));
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal165(e.IsExplicit());
  b.setVal166(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  SerializeCXXMethodDecl(es, b, e);
  b.setVal163(es.EntityId(e.TargetConstructor()));
  b.setVal165(e.IsDefaultConstructor());
  b.setVal166(e.IsDelegatingConstructor());
  b.setVal167(e.IsExplicit());
  b.setVal168(e.IsInheritingConstructor());
  b.setVal169(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  SerializeFunctionDecl(es, b, e);
  b.setVal154(es.EntityId(e.CorrespondingConstructor()));
  b.setVal155(e.IsCopyDeductionCandidate());
  b.setVal156(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.BitWidth();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v80 = e.InClassInitializer();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal83(es.EntityId(e.Parent()));
  b.setVal84(e.HasCapturedVLAType());
  b.setVal86(e.HasInClassInitializer());
  b.setVal94(e.IsAnonymousStructOrUnion());
  b.setVal97(e.IsBitField());
  b.setVal98(e.IsMutable());
  b.setVal99(e.IsUnnamedBitfield());
  b.setVal100(e.IsZeroLengthBitField());
  b.setVal101(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  SerializeFieldDecl(es, b, e);
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.AccessControl())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal85(es.EntityId(e.ContainingInterface()));
  b.setVal88(es.EntityId(e.NextInstanceVariable()));
  b.setVal102(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e) {
  SerializeValueDecl(es, b, e);
  b.setVal58(es.EntityId(e.Binding()));
  b.setVal59(es.EntityId(e.DecomposedDeclaration()));
  b.setVal67(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal58(es.EntityId(e.MapperVariableReference()));
  b.setVal59(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal58(es.EntityId(e.Introducer()));
  b.setVal59(es.EntityId(e.NextUsingShadowDeclaration()));
  b.setVal67(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  SerializeUsingShadowDecl(es, b, e);
  b.setVal76(e.ConstructsVirtualBase());
  b.setVal68(es.EntityId(e.ConstructedBaseClass()));
  auto v69 = e.ConstructedBaseClassShadowDeclaration();
  if (v69) {
    if (auto id69 = es.EntityId(v69.value())) {
      b.setVal69(id69);
      b.setVal77(true);
    } else {
      b.setVal77(false);
    }
  } else {
    b.setVal77(false);
  }
  b.setVal70(es.EntityId(e.NominatedBaseClass()));
  auto v80 = e.NominatedBaseClassShadowDeclaration();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal78(true);
    } else {
      b.setVal78(false);
    }
  } else {
    b.setVal78(false);
  }
  b.setVal83(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v53 = e.Expansions();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  b.setVal58(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal58(es.EntityId(e.IdentifierToken()));
  b.setVal59(es.EntityId(e.NamespaceKeyToken()));
  b.setVal67(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal68(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e) {
  SerializeNamedDecl(es, b, e);
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal76(e.DefaultArgumentWasInherited());
  b.setVal58(es.EntityId(e.DefaultArgumentToken()));
  b.setVal77(e.HasDefaultArgument());
  b.setVal78(e.HasTypeConstraint());
  b.setVal82(e.IsExpandedParameterPack());
  b.setVal84(e.IsPackExpansion());
  b.setVal86(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  SerializeTypeDecl(es, b, e);
  if (auto r58 = e.BraceRange(); auto rs58 = r58.Size()) {
    b.setVal58(es.EntityId(r58[0]));
    b.setVal59(es.EntityId(r58[rs58 - 1u]));
  } else {
    b.setVal58(0);
    b.setVal59(0);
  }
  auto v67 = e.Definition();
  if (v67) {
    if (auto id67 = es.EntityId(v67.value())) {
      b.setVal67(id67);
      b.setVal76(true);
    } else {
      b.setVal76(false);
    }
  } else {
    b.setVal76(false);
  }
  b.setVal68(es.EntityId(e.InnerTokenStart()));
  b.setVal69(es.EntityId(e.OuterTokenStart()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.TagKind())));
  auto v70 = e.TypedefNameForAnonymousDeclaration();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal77(true);
    } else {
      b.setVal77(false);
    }
  } else {
    b.setVal77(false);
  }
  b.setVal78(e.HasNameForLinkage());
  b.setVal82(e.IsBeingDefined());
  b.setVal84(e.IsClass());
  b.setVal86(e.IsCompleteDefinition());
  b.setVal94(e.IsCompleteDefinitionRequired());
  b.setVal97(e.IsDependentType());
  b.setVal98(e.IsEmbeddedInDeclarator());
  b.setVal99(e.IsEnum());
  b.setVal100(e.IsFreeStanding());
  b.setVal101(e.IsInterface());
  b.setVal102(e.IsStruct());
  b.setVal103(e.IsThisDeclarationADefinition());
  b.setVal104(e.IsUnion());
  b.setVal105(e.MayHaveOutOfDateDefinition());
  auto v81 = e.TemplateParameterLists();
  auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
  auto i81 = 0u;
  for (const auto &e81 : v81) {
    auto o81 = es.next_pseudo_entity_offset++;
    sv81.set(i81, o81);
    SerializeTemplateParameterList(es, es.pseudo_builder[o81], e81);
    ++i81;
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

void SerializeRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  SerializeTagDecl(es, b, e);
  b.setVal106(e.CanPassInRegisters());
  auto v54 = e.Fields();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  auto v80 = e.FindFirstNamedDataMember();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal107(true);
    } else {
      b.setVal107(false);
    }
  } else {
    b.setVal107(false);
  }
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal108(e.HasFlexibleArrayMember());
  b.setVal109(e.HasLoadedFieldsFromExternalStorage());
  b.setVal110(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal111(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal112(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal113(e.HasObjectMember());
  b.setVal114(e.HasVolatileMember());
  b.setVal115(e.IsAnonymousStructOrUnion());
  b.setVal116(e.IsCapturedRecord());
  b.setVal117(e.IsInjectedClassName());
  b.setVal118(e.IsLambda());
  b.setVal119(e.IsMsStruct());
  b.setVal120(e.IsNonTrivialToPrimitiveCopy());
  b.setVal121(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal122(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal123(e.IsOrContainsUnion());
  b.setVal124(e.IsParameterDestroyedInCallee());
  b.setVal125(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  SerializeRecordDecl(es, b, e);
  b.setVal126(e.AllowConstDefaultInitializer());
  auto v145 = e.Bases();
  auto sv145 = b.initVal145(static_cast<unsigned>(v145.size()));
  auto i145 = 0u;
  for (const auto &e145 : v145) {
    auto o145 = es.next_pseudo_entity_offset++;
    sv145.set(i145, o145);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o145], e145);
    ++i145;
  }
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.CalculateInheritanceModel())));
  auto v63 = e.Constructors();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
  b.setVal127(e.DefaultedCopyConstructorIsDeleted());
  b.setVal128(e.DefaultedDefaultConstructorIsConstexpr());
  b.setVal129(e.DefaultedDestructorIsConstexpr());
  b.setVal132(e.DefaultedDestructorIsDeleted());
  b.setVal137(e.DefaultedMoveConstructorIsDeleted());
  auto v170 = e.Friends();
  auto sv170 = b.initVal170(static_cast<unsigned>(v170.size()));
  auto i170 = 0u;
  for (const auto &e170 : v170) {
    sv170.set(i170, es.EntityId(e170));
    ++i170;
  }
  auto v83 = e.Destructor();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal138(true);
    } else {
      b.setVal138(false);
    }
  } else {
    b.setVal138(false);
  }
  auto v171 = e.GenericLambdaTemplateParameterList();
  if (v171) {
    auto o171 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o171], v171.value());
    b.setVal171(o171);
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  auto v85 = e.InstantiatedFromMemberClass();
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
  auto v88 = e.LambdaCallOperator();
  if (v88) {
    if (auto id88 = es.EntityId(v88.value())) {
      b.setVal88(id88);
      b.setVal141(true);
    } else {
      b.setVal141(false);
    }
  } else {
    b.setVal141(false);
  }
  b.setVal90(static_cast<unsigned short>(mx::FromPasta(e.LambdaCaptureDefault())));
  b.setVal93(es.EntityId(e.LambdaContextDeclaration()));
  auto v172 = e.LambdaExplicitTemplateParameters();
  auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
  auto i172 = 0u;
  for (const auto &e172 : v172) {
    sv172.set(i172, es.EntityId(e172));
    ++i172;
  }
  b.setVal91(static_cast<unsigned short>(mx::FromPasta(e.MSInheritanceModel())));
  b.setVal92(static_cast<unsigned short>(mx::FromPasta(e.MSVtorDispMode())));
  b.setVal131(es.EntityId(e.MostRecentNonInjectedDeclaration()));
  auto v133 = e.TemplateInstantiationPattern();
  if (v133) {
    if (auto id133 = es.EntityId(v133.value())) {
      b.setVal133(id133);
      b.setVal142(true);
    } else {
      b.setVal142(false);
    }
  } else {
    b.setVal142(false);
  }
  b.setVal95(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal143(e.HasAnyDependentBases());
  b.setVal144(e.HasConstexprDefaultConstructor());
  b.setVal148(e.HasConstexprDestructor());
  b.setVal149(e.HasConstexprNonCopyMoveConstructor());
  b.setVal150(e.HasCopyAssignmentWithConstParameter());
  b.setVal151(e.HasCopyConstructorWithConstParameter());
  b.setVal153(e.HasDefaultConstructor());
  b.setVal155(e.HasDefinition());
  b.setVal156(e.HasDirectFields());
  b.setVal157(e.HasFriends());
  b.setVal158(e.HasInClassInitializer());
  b.setVal159(e.HasInheritedAssignment());
  b.setVal160(e.HasInheritedConstructor());
  b.setVal161(e.HasIrrelevantDestructor());
  b.setVal162(e.HasKnownLambdaInternalLinkage());
  b.setVal165(e.HasMoveAssignment());
  b.setVal166(e.HasMoveConstructor());
  b.setVal167(e.HasMutableFields());
  b.setVal168(e.HasNonLiteralTypeFieldsOrBases());
  b.setVal169(e.HasNonTrivialCopyAssignment());
  b.setVal173(e.HasNonTrivialCopyConstructor());
  b.setVal174(e.HasNonTrivialCopyConstructorForCall());
  b.setVal175(e.HasNonTrivialDefaultConstructor());
  b.setVal176(e.HasNonTrivialDestructor());
  b.setVal177(e.HasNonTrivialDestructorForCall());
  b.setVal178(e.HasNonTrivialMoveAssignment());
  b.setVal179(e.HasNonTrivialMoveConstructor());
  b.setVal180(e.HasNonTrivialMoveConstructorForCall());
  b.setVal181(e.HasPrivateFields());
  b.setVal182(e.HasProtectedFields());
  b.setVal183(e.HasSimpleCopyAssignment());
  b.setVal184(e.HasSimpleCopyConstructor());
  b.setVal185(e.HasSimpleDestructor());
  b.setVal186(e.HasSimpleMoveAssignment());
  b.setVal187(e.HasSimpleMoveConstructor());
  b.setVal188(e.HasTrivialCopyAssignment());
  b.setVal189(e.HasTrivialCopyConstructor());
  b.setVal190(e.HasTrivialCopyConstructorForCall());
  b.setVal191(e.HasTrivialDefaultConstructor());
  b.setVal192(e.HasTrivialDestructor());
  b.setVal193(e.HasTrivialDestructorForCall());
  b.setVal194(e.HasTrivialMoveAssignment());
  b.setVal195(e.HasTrivialMoveConstructor());
  b.setVal196(e.HasTrivialMoveConstructorForCall());
  b.setVal197(e.HasUninitializedReferenceMember());
  b.setVal198(e.HasUserDeclaredConstructor());
  b.setVal199(e.HasUserDeclaredCopyAssignment());
  b.setVal200(e.HasUserDeclaredCopyConstructor());
  b.setVal201(e.HasUserDeclaredDestructor());
  b.setVal202(e.HasUserDeclaredMoveAssignment());
  b.setVal203(e.HasUserDeclaredMoveConstructor());
  b.setVal204(e.HasUserDeclaredMoveOperation());
  b.setVal205(e.HasUserProvidedDefaultConstructor());
  b.setVal206(e.HasVariantMembers());
  b.setVal207(e.ImplicitCopyAssignmentHasConstParameter());
  b.setVal208(e.ImplicitCopyConstructorHasConstParameter());
  b.setVal209(e.IsAbstract());
  b.setVal210(e.IsAggregate());
  b.setVal211(e.IsAnyDestructorNoReturn());
  b.setVal212(e.IsCLike());
  b.setVal213(e.IsCXX11StandardLayout());
  b.setVal214(e.IsDependentLambda());
  b.setVal215(e.IsDynamicClass());
  b.setVal216(e.IsEffectivelyFinal());
  b.setVal217(e.IsEmpty());
  b.setVal218(e.IsGenericLambda());
  b.setVal219(e.IsInterfaceLike());
  b.setVal220(e.IsLiteral());
  auto v134 = e.IsLocalClass();
  if (v134) {
    if (auto id134 = es.EntityId(v134.value())) {
      b.setVal134(id134);
      b.setVal221(true);
    } else {
      b.setVal221(false);
    }
  } else {
    b.setVal221(false);
  }
  b.setVal222(e.IsPOD());
  b.setVal223(e.IsParsingBaseSpecifiers());
  b.setVal224(e.IsPolymorphic());
  b.setVal225(e.IsStandardLayout());
  b.setVal226(e.IsStructural());
  b.setVal227(e.IsTrivial());
  b.setVal228(e.IsTriviallyCopyable());
  b.setVal229(e.LambdaIsDefaultConstructibleAndAssignable());
  b.setVal230(e.MayBeAbstract());
  b.setVal231(e.MayBeDynamicClass());
  b.setVal232(e.MayBeNonDynamicClass());
  auto v233 = e.Methods();
  auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
  auto i233 = 0u;
  for (const auto &e233 : v233) {
    sv233.set(i233, es.EntityId(e233));
    ++i233;
  }
  b.setVal234(e.NeedsImplicitCopyAssignment());
  b.setVal235(e.NeedsImplicitCopyConstructor());
  b.setVal236(e.NeedsImplicitDefaultConstructor());
  b.setVal237(e.NeedsImplicitDestructor());
  b.setVal238(e.NeedsImplicitMoveAssignment());
  b.setVal239(e.NeedsImplicitMoveConstructor());
  b.setVal240(e.NeedsOverloadResolutionForCopyAssignment());
  b.setVal241(e.NeedsOverloadResolutionForCopyConstructor());
  b.setVal242(e.NeedsOverloadResolutionForDestructor());
  b.setVal243(e.NeedsOverloadResolutionForMoveAssignment());
  b.setVal244(e.NeedsOverloadResolutionForMoveConstructor());
  b.setVal245(e.NullFieldOffsetIsZero());
  auto v146 = e.VirtualBases();
  auto sv146 = b.initVal146(static_cast<unsigned>(v146.size()));
  auto i146 = 0u;
  for (const auto &e146 : v146) {
    auto o146 = es.next_pseudo_entity_offset++;
    sv146.set(i146, o146);
    SerializeCXXBaseSpecifier(es, es.pseudo_builder[o146], e146);
    ++i146;
  }
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  SerializeCXXRecordDecl(es, b, e);
  b.setVal136(es.EntityId(e.ExternToken()));
  b.setVal147(es.EntityId(e.PointOfInstantiation()));
  b.setVal96(static_cast<unsigned short>(mx::FromPasta(e.SpecializationKind())));
  auto v246 = e.TemplateArguments();
  auto sv246 = b.initVal246(static_cast<unsigned>(v246.size()));
  auto i246 = 0u;
  for (const auto &e246 : v246) {
    auto o246 = es.next_pseudo_entity_offset++;
    sv246.set(i246, o246);
    SerializeTemplateArgument(es, es.pseudo_builder[o246], e246);
    ++i246;
  }
  auto v247 = e.TemplateInstantiationArguments();
  auto sv247 = b.initVal247(static_cast<unsigned>(v247.size()));
  auto i247 = 0u;
  for (const auto &e247 : v247) {
    auto o247 = es.next_pseudo_entity_offset++;
    sv247.set(i247, o247);
    SerializeTemplateArgument(es, es.pseudo_builder[o247], e247);
    ++i247;
  }
  b.setVal152(es.EntityId(e.TemplateKeywordToken()));
  b.setVal248(e.IsClassScopeExplicitSpecialization());
  b.setVal249(e.IsExplicitInstantiationOrSpecialization());
  b.setVal250(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
}

void SerializeEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e) {
  SerializeTagDecl(es, b, e);
  auto v54 = e.Enumerators();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  auto v80 = e.InstantiatedFromMemberEnum();
  if (v80) {
    if (auto id80 = es.EntityId(v80.value())) {
      b.setVal80(id80);
      b.setVal106(true);
    } else {
      b.setVal106(false);
    }
  } else {
    b.setVal106(false);
  }
  if (auto r83 = e.IntegerTypeRange(); auto rs83 = r83.Size()) {
    b.setVal83(es.EntityId(r83[0]));
    b.setVal85(es.EntityId(r83[rs83 - 1u]));
  } else {
    b.setVal83(0);
    b.setVal85(0);
  }
  auto v88 = e.TemplateInstantiationPattern();
  if (v88) {
    if (auto id88 = es.EntityId(v88.value())) {
      b.setVal88(id88);
      b.setVal107(true);
    } else {
      b.setVal107(false);
    }
  } else {
    b.setVal107(false);
  }
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal108(e.IsClosed());
  b.setVal109(e.IsClosedFlag());
  b.setVal110(e.IsClosedNonFlag());
  b.setVal111(e.IsComplete());
  b.setVal112(e.IsFixed());
  b.setVal113(e.IsScoped());
  b.setVal114(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  SerializeTypeDecl(es, b, e);
  b.setVal58(es.EntityId(e.EllipsisToken()));
  b.setVal59(es.EntityId(e.TypenameToken()));
  b.setVal67(es.EntityId(e.UsingToken()));
  b.setVal76(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  SerializeTypeDecl(es, b, e);
  auto v58 = e.AnonymousDeclarationWithTypedefName();
  if (v58) {
    if (auto id58 = es.EntityId(v58.value())) {
      b.setVal58(id58);
      b.setVal76(true);
    } else {
      b.setVal76(false);
    }
  } else {
    b.setVal76(false);
  }
  b.setVal77(e.IsModed());
  b.setVal78(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  auto v59 = e.DescribedAliasTemplate();
  if (v59) {
    if (auto id59 = es.EntityId(v59.value())) {
      b.setVal59(id59);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  SerializeTypedefNameDecl(es, b, e);
  b.setVal59(es.EntityId(e.ColonToken()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.Variance())));
  b.setVal67(es.EntityId(e.VarianceToken()));
  b.setVal82(e.HasExplicitBound());
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
  b.setVal58(es.EntityId(e.ConstraintExpression()));
  b.setVal76(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e) {
}

void SerializeTemplateTemplateParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
}

void SerializeObjCPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal58(es.EntityId(e.AtToken()));
  b.setVal59(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal67(es.EntityId(e.GetterNameToken()));
  b.setVal68(es.EntityId(e.LParenToken()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal69(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.QueryKind())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.SetterKind())));
  b.setVal70(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal80(es.EntityId(e.SetterNameToken()));
  b.setVal76(e.IsAtomic());
  b.setVal77(e.IsClassProperty());
  b.setVal78(e.IsDirectProperty());
  b.setVal82(e.IsInstanceProperty());
  b.setVal84(e.IsOptional());
  b.setVal86(e.IsReadOnly());
  b.setVal94(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal76(e.DefinedInNSObject());
  b.setVal58(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal59(es.EntityId(e.Category()));
  b.setVal67(es.EntityId(e.ClassInterface()));
  b.setVal68(es.EntityId(e.CmdDeclaration()));
  b.setVal69(es.EntityId(e.DeclaratorEndToken()));
  b.setVal79(static_cast<unsigned short>(mx::FromPasta(e.ImplementationControl())));
  b.setVal87(static_cast<unsigned short>(mx::FromPasta(e.MethodFamily())));
  b.setVal89(static_cast<unsigned short>(mx::FromPasta(e.ObjCDeclQualifier())));
  if (auto r70 = e.ReturnTypeSourceRange(); auto rs70 = r70.Size()) {
    b.setVal70(es.EntityId(r70[0]));
    b.setVal80(es.EntityId(r70[rs70 - 1u]));
  } else {
    b.setVal70(0);
    b.setVal80(0);
  }
  b.setVal83(es.EntityId(e.SelectorStartToken()));
  b.setVal85(es.EntityId(e.SelfDeclaration()));
  b.setVal77(e.HasRedeclaration());
  b.setVal78(e.HasRelatedResultType());
  b.setVal82(e.HasSkippedBody());
  b.setVal84(e.IsClassMethod());
  b.setVal86(e.IsDefined());
  b.setVal94(e.IsDesignatedInitializerForTheInterface());
  b.setVal97(e.IsDirectMethod());
  b.setVal98(e.IsInstanceMethod());
  b.setVal99(e.IsOptional());
  b.setVal100(e.IsOverriding());
  b.setVal101(e.IsPropertyAccessor());
  b.setVal102(e.IsRedeclaration());
  b.setVal103(e.IsSynthesizedAccessorStub());
  b.setVal104(e.IsThisDeclarationADefinition());
  b.setVal105(e.IsThisDeclarationADesignatedInitializer());
  b.setVal106(e.IsVariadic());
  auto v53 = e.Parameters();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v54 = e.SelectorTokens();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  pasta::DeclContext dc63(e);
  auto v63 = dc63.AlreadyLoadedDeclarations();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const pasta::Decl &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  SerializeNamedDecl(es, b, e);
  auto v53 = e.ClassMethods();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  auto v54 = e.ClassProperties();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const auto &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
  if (auto r58 = e.AtEndRange(); auto rs58 = r58.Size()) {
    b.setVal58(es.EntityId(r58[0]));
    b.setVal59(es.EntityId(r58[rs58 - 1u]));
  } else {
    b.setVal58(0);
    b.setVal59(0);
  }
  b.setVal67(es.EntityId(e.AtStartToken()));
  auto v63 = e.InstanceMethods();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const auto &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
  auto v170 = e.InstanceProperties();
  auto sv170 = b.initVal170(static_cast<unsigned>(v170.size()));
  auto i170 = 0u;
  for (const auto &e170 : v170) {
    sv170.set(i170, es.EntityId(e170));
    ++i170;
  }
  auto v172 = e.Methods();
  auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
  auto i172 = 0u;
  for (const auto &e172 : v172) {
    sv172.set(i172, es.EntityId(e172));
    ++i172;
  }
  auto v233 = e.Properties();
  auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
  auto i233 = 0u;
  for (const auto &e233 : v233) {
    sv233.set(i233, es.EntityId(e233));
    ++i233;
  }
  pasta::DeclContext dc251(e);
  auto v251 = dc251.AlreadyLoadedDeclarations();
  auto sv251 = b.initVal251(static_cast<unsigned>(v251.size()));
  auto i251 = 0u;
  for (const pasta::Decl &e251 : v251) {
    sv251.set(i251, es.EntityId(e251));
    ++i251;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal76(e.IsClassExtension());
  b.setVal68(es.EntityId(e.CategoryNameToken()));
  b.setVal69(es.EntityId(e.ClassInterface()));
  b.setVal70(es.EntityId(e.Implementation()));
  b.setVal80(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal83(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal85(es.EntityId(e.NextClassCategory()));
  b.setVal88(es.EntityId(e.NextClassCategoryRaw()));
  auto v252 = e.InstanceVariables();
  auto sv252 = b.initVal252(static_cast<unsigned>(v252.size()));
  auto i252 = 0u;
  for (const auto &e252 : v252) {
    sv252.set(i252, es.EntityId(e252));
    ++i252;
  }
  auto v253 = e.ProtocolTokens();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const auto &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
  auto v254 = e.Protocols();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal68(es.EntityId(e.Definition()));
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal76(e.HasDefinition());
  b.setVal77(e.IsNonRuntimeProtocol());
  b.setVal78(e.IsThisDeclarationADefinition());
  auto v252 = e.ProtocolTokens();
  auto sv252 = b.initVal252(static_cast<unsigned>(v252.size()));
  auto i252 = 0u;
  for (const auto &e252 : v252) {
    sv252.set(i252, es.EntityId(e252));
    ++i252;
  }
  auto v253 = e.Protocols();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const auto &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  auto v252 = e.AllReferencedProtocols();
  auto sv252 = b.initVal252(static_cast<unsigned>(v252.size()));
  auto i252 = 0u;
  for (const auto &e252 : v252) {
    sv252.set(i252, es.EntityId(e252));
    ++i252;
  }
  b.setVal76(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal68(es.EntityId(e.CategoryListRaw()));
  b.setVal69(es.EntityId(e.Definition()));
  b.setVal70(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal80(es.EntityId(e.Implementation()));
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal83(es.EntityId(e.SuperClass()));
  b.setVal85(es.EntityId(e.SuperClassToken()));
  b.setVal77(e.HasDefinition());
  b.setVal78(e.HasDesignatedInitializers());
  b.setVal82(e.IsArcWeakrefUnavailable());
  b.setVal84(e.IsImplicitInterfaceDeclaration());
  b.setVal88(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal86(e.IsThisDeclarationADefinition());
  auto v253 = e.InstanceVariables();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const auto &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
  auto v254 = e.KnownCategories();
  auto sv254 = b.initVal254(static_cast<unsigned>(v254.size()));
  auto i254 = 0u;
  for (const auto &e254 : v254) {
    sv254.set(i254, es.EntityId(e254));
    ++i254;
  }
  auto v255 = e.KnownExtensions();
  auto sv255 = b.initVal255(static_cast<unsigned>(v255.size()));
  auto i255 = 0u;
  for (const auto &e255 : v255) {
    sv255.set(i255, es.EntityId(e255));
    ++i255;
  }
  auto v256 = e.ProtocolTokens();
  auto sv256 = b.initVal256(static_cast<unsigned>(v256.size()));
  auto i256 = 0u;
  for (const auto &e256 : v256) {
    sv256.set(i256, es.EntityId(e256));
    ++i256;
  }
  auto v257 = e.Protocols();
  auto sv257 = b.initVal257(static_cast<unsigned>(v257.size()));
  auto i257 = 0u;
  for (const auto &e257 : v257) {
    sv257.set(i257, es.EntityId(e257));
    ++i257;
  }
  auto v258 = e.VisibleCategories();
  auto sv258 = b.initVal258(static_cast<unsigned>(v258.size()));
  auto i258 = 0u;
  for (const auto &e258 : v258) {
    sv258.set(i258, es.EntityId(e258));
    ++i258;
  }
  auto v259 = e.VisibleExtensions();
  auto sv259 = b.initVal259(static_cast<unsigned>(v259.size()));
  auto i259 = 0u;
  for (const auto &e259 : v259) {
    sv259.set(i259, es.EntityId(e259));
    ++i259;
  }
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  SerializeObjCContainerDecl(es, b, e);
  b.setVal68(es.EntityId(e.ClassInterface()));
  auto v252 = e.PropertyImplementations();
  auto sv252 = b.initVal252(static_cast<unsigned>(v252.size()));
  auto i252 = 0u;
  for (const auto &e252 : v252) {
    sv252.set(i252, es.EntityId(e252));
    ++i252;
  }
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal69(es.EntityId(e.CategoryDeclaration()));
  b.setVal70(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  SerializeObjCImplDecl(es, b, e);
  b.setVal69(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal70(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal80(es.EntityId(e.SuperClass()));
  b.setVal83(es.EntityId(e.SuperClassToken()));
  b.setVal76(e.HasDestructors());
  b.setVal77(e.HasNonZeroConstructors());
  auto v253 = e.InstanceVariables();
  auto sv253 = b.initVal253(static_cast<unsigned>(v253.size()));
  auto i253 = 0u;
  for (const auto &e253 : v253) {
    sv253.set(i253, es.EntityId(e253));
    ++i253;
  }
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal58(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  SerializeNamedDecl(es, b, e);
  b.setVal58(es.EntityId(e.AliasToken()));
  b.setVal59(es.EntityId(e.AliasedNamespace()));
  b.setVal67(es.EntityId(e.NamespaceToken()));
  b.setVal68(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  SerializeDecl(es, b, e);
  auto v53 = e.ChildrenExpression();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
  b.setVal51(es.EntityId(e.ExtendingDeclaration()));
  b.setVal66(static_cast<unsigned short>(mx::FromPasta(e.StorageDuration())));
  b.setVal58(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  SerializeDecl(es, b, e);
  auto v53 = e.IdentifierTokens();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const auto &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeFriendTemplateDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e) {
}

void SerializeFriendDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.FriendDeclaration()));
  b.setVal58(es.EntityId(e.FriendToken()));
  b.setVal52(e.IsUnsupportedFriend());
  auto v81 = e.FriendTypeTemplateParameterLists();
  auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
  auto i81 = 0u;
  for (const auto &e81 : v81) {
    auto o81 = es.next_pseudo_entity_offset++;
    sv81.set(i81, o81);
    SerializeTemplateParameterList(es, es.pseudo_builder[o81], e81);
    ++i81;
  }
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.AssemblyToken()));
  b.setVal58(es.EntityId(e.AssemblyString()));
  b.setVal59(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.ExportToken()));
  b.setVal58(es.EntityId(e.RBraceToken()));
  b.setVal52(e.HasBraces());
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  SerializeDecl(es, b, e);
}

}  // namespace indexer
