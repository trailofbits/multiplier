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
do {
    auto v12 = e.Parameters();
    auto sv12 = b.initVal12(static_cast<unsigned>(v12.size()));
    auto i12 = 0u;
    for (const auto &e12 : v12) {
      sv12.set(i12, es.EntityId(e12));
      ++i12;
    }
  } while (false);
}

void SerializeTemplateArgument(EntitySerializer &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
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
  b.setVal17(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal18(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
}

void SerializeStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setVal0(es.parent_decl_id);
  b.setVal1(es.parent_stmt_id);
  b.setVal2(es.EntityId(e.IgnoreContainers()));
do {
    auto v3 = e.Children();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  } while (false);
  b.setVal4(es.EntityId(e.BeginToken()));
  b.setVal5(es.EntityId(e.EndToken()));
  if (auto r6 = e.TokenRange(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal7(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal7(0);
  }
  b.setVal8(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
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
do {
    auto v17 = e.CatchStatements();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
do {
    auto v17 = e.Counters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
do {
    auto v23 = e.DependentCounters();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
do {
    auto v24 = e.DependentInitializers();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
do {
    auto v25 = e.Finals();
    auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
    auto i25 = 0u;
    for (const auto &e25 : v25) {
      sv25.set(i25, es.EntityId(e25));
      ++i25;
    }
  } while (false);
do {
    auto v26 = e.FinalsConditions();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
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
do {
    auto v53 = e.Initializers();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
do {
    auto v54 = e.PrivateCounters();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
do {
    auto v55 = e.Updates();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
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
do {
    auto v17 = e.Declarations();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
do {
    auto v17 = e.ParameterMoves();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
  b.setVal62(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal12(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.TryBlock()));
  b.setVal11(es.EntityId(e.TryToken()));
do {
    auto v17 = e.Handlers();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
  auto v27 = e.Initializer();
  if (v27) {
    if (auto id27 = es.EntityId(v27.value())) {
      b.setVal27(id27);
      b.setVal13(true);
    } else {
      b.setVal13(false);
    }
  } else {
    b.setVal13(false);
  }
  b.setVal28(es.EntityId(e.LoopVariableStatement()));
  b.setVal29(es.EntityId(e.LoopVariable()));
  b.setVal30(es.EntityId(e.RParenToken()));
  b.setVal31(es.EntityId(e.RangeInitializer()));
  b.setVal32(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.CatchToken()));
  auto v11 = e.ExceptionDeclaration();
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
do {
    auto v17 = e.Inputs();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal13(e.IsSimple());
  b.setVal16(e.IsVolatile());
do {
    auto v23 = e.Outputs();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
do {
    auto v64 = e.OutputConstraints();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
    }
  } while (false);
do {
    auto v24 = e.OutputExpressions();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
do {
    auto v65 = e.InputConstraints();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
    }
  } while (false);
do {
    auto v25 = e.InputExpressions();
    auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
    auto i25 = 0u;
    for (const auto &e25 : v25) {
      sv25.set(i25, es.EntityId(e25));
      ++i25;
    }
  } while (false);
do {
    auto v66 = e.Clobbers();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
}

void SerializeMSAsmStmt(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
do {
    auto v67 = e.AllConstraints();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
do {
    auto v26 = e.AllExpressions();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
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
do {
    auto v26 = e.Labels();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
do {
    auto v53 = e.OutputConstraintLiterals();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
do {
    auto v67 = e.OutputNames();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
do {
    auto v54 = e.InputConstraintLiterals();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
do {
    auto v69 = e.InputNames();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
    }
  } while (false);
do {
    auto v55 = e.ClobberStringLiterals();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
do {
    auto v70 = e.LabelExpressions();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      sv70.set(i70, es.EntityId(e70));
      ++i70;
    }
  } while (false);
do {
    auto v71 = e.LabelNames();
    auto sv71 = b.initVal71(static_cast<unsigned>(v71.size()));
    auto i71 = 0u;
    for (const auto &e71 : v71) {
      std::string se71(e71.data(), e71.size());
      sv71.set(i71, se71);
      ++i71;
    }
  } while (false);
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
  b.setVal62(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
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
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal60(e.HasNonTrivialCall());
  auto v61 = e.IsCXX11ConstantExpression();
  if (v61) {
    b.setVal61(static_cast<bool>(v61.value()));
    b.setVal73(true);
  } else {
    b.setVal73(false);
  }
  auto v74 = e.IsCXX98IntegralConstantExpression();
  if (v74) {
    b.setVal74(static_cast<bool>(v74.value()));
    b.setVal75(true);
  } else {
    b.setVal75(false);
  }
  b.setVal76(e.IsDefaultArgument());
  auto v77 = e.IsEvaluatable();
  if (v77) {
    b.setVal77(static_cast<bool>(v77.value()));
    b.setVal78(true);
  } else {
    b.setVal78(false);
  }
  b.setVal79(e.IsGLValue());
  b.setVal80(e.IsImplicitCXXThis());
  b.setVal81(e.IsInstantiationDependent());
  auto v82 = e.IsIntegerConstantExpression();
  if (v82) {
    b.setVal82(static_cast<bool>(v82.value()));
    b.setVal83(true);
  } else {
    b.setVal83(false);
  }
  b.setVal84(e.IsKnownToHaveBooleanValue());
  b.setVal85(e.IsLValue());
  b.setVal86(e.IsOBJCGCCandidate());
  b.setVal87(e.IsObjCSelfExpression());
  b.setVal88(e.IsOrdinaryOrBitFieldObject());
  b.setVal89(e.IsPRValue());
  b.setVal90(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal91(e.IsTypeDependent());
  b.setVal92(e.IsValueDependent());
  b.setVal93(e.IsXValue());
  b.setVal94(e.RefersToBitField());
  b.setVal95(e.RefersToGlobalRegisterVariable());
  b.setVal96(e.RefersToMatrixElement());
  b.setVal97(e.RefersToVectorElement());
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
  b.setVal98(e.IsDirectInitializer());
  b.setVal99(e.UsesGNUSyntax());
do {
    auto v17 = e.SubExpressions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.RAngleToken()));
  b.setVal39(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
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
  b.setVal98(e.HadMultipleCandidates());
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasQualifier());
  b.setVal101(e.HasTemplateKWAndArgumentsInfo());
  b.setVal102(e.HasTemplateKeyword());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal104(e.RefersToEnclosingVariableOrCapture());
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
  b.setVal98(e.IsImplicit());
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
do {
    auto v105 = e.TemplateArguments();
    auto sv105 = b.initVal105(static_cast<unsigned>(v105.size()));
    auto i105 = 0u;
    for (const auto &e105 : v105) {
      auto o105 = es.next_pseudo_entity_offset++;
      sv105.set(i105, o105);
      SerializeTemplateArgument(es, es.pseudo_builder[o105], e105);
      ++i105;
    }
  } while (false);
  b.setVal98(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Initializer()));
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal98(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal38(es.EntityId(e.ChosenSubExpression()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.RParenToken()));
  b.setVal98(e.IsConditionDependent());
  b.setVal99(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v63 = e.CastKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v37 = e.ConversionFunction();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.SubExpressionAsWritten()));
  auto v40 = e.TargetUnionField();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal100(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal101(e.IsPartOfExplicitCast());
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
  b.setVal101(e.IsAlwaysNull());
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
  b.setVal101(e.IsListInitialization());
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
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal42(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
do {
    auto v17 = e.Arguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal37(es.EntityId(e.Callee()));
  auto v38 = e.CalleeDeclaration();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  auto v39 = e.DirectCallee();
  if (v39) {
    if (auto id39 = es.EntityId(v39.value())) {
      b.setVal39(id39);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal100(e.HasStoredFPFeatures());
  b.setVal101(e.HasUnusedResultAttribute());
  b.setVal102(e.IsBuiltinAssumeFalse());
  b.setVal104(e.IsCallToStdMove());
  b.setVal107(e.IsUnevaluatedBuiltinCall());
  b.setVal108(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal109(e.IsAssignmentOperation());
  b.setVal110(e.IsComparisonOperation());
  b.setVal111(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.ImplicitObjectArgument()));
  auto v42 = e.MethodDeclaration();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  b.setVal43(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.CookedLiteral()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal42(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal38(es.EntityId(e.GuidDeclaration()));
  b.setVal99(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
do {
    auto v17 = e.Arguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal98(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  auto v99 = e.IsMostDerived();
  if (v99) {
    b.setVal99(static_cast<bool>(v99.value()));
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  b.setVal101(e.IsPotentiallyEvaluated());
  b.setVal102(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.SubExpression();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal38(es.EntityId(e.ThrowToken()));
  b.setVal99(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal98(e.IsImplicit());
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
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColonColonToken()));
  b.setVal39(es.EntityId(e.DestroyedTypeToken()));
  b.setVal40(es.EntityId(e.OperatorToken()));
  b.setVal41(es.EntityId(e.TildeToken()));
  b.setVal98(e.HasQualifier());
  b.setVal99(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal98(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  auto v37 = e.ArraySize();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  auto v38 = e.ConstructExpression();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  if (auto r39 = e.DirectInitializerRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v41 = e.Initializer();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
      b.setVal101(true);
    } else {
      b.setVal101(false);
    }
  } else {
    b.setVal101(false);
  }
  b.setVal42(es.EntityId(e.OperatorDelete()));
  b.setVal43(es.EntityId(e.OperatorNew()));
  if (auto r44 = e.TypeIdParentheses(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal102(e.HasInitializer());
  b.setVal104(e.IsArray());
  b.setVal107(e.IsGlobalNew());
  b.setVal108(e.IsParenthesisTypeId());
  b.setVal109(e.PassAlignment());
do {
    auto v17 = e.PlacementArguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal110(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ConstructsVirtualBase());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  b.setVal38(es.EntityId(e.Token()));
  b.setVal99(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Callee()));
  b.setVal38(es.EntityId(e.EllipsisToken()));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.LParenToken()));
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  b.setVal44(es.EntityId(e.RParenToken()));
  b.setVal99(e.IsLeftFold());
  b.setVal100(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto v38 = e.FirstQualifierFoundInScope();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal39(es.EntityId(e.LAngleToken()));
  b.setVal40(es.EntityId(e.MemberToken()));
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal42(es.EntityId(e.RAngleToken()));
  b.setVal43(es.EntityId(e.TemplateKeywordToken()));
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasTemplateKeyword());
  b.setVal101(e.IsArrow());
  b.setVal102(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  b.setVal38(es.EntityId(e.OperatorDelete()));
  b.setVal99(e.IsArrayForm());
  b.setVal100(e.IsArrayFormAsWritten());
  b.setVal101(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.Expression();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
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
do {
    auto v17 = e.Arguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  b.setVal38(es.EntityId(e.Token()));
  if (auto r39 = e.ParenthesisOrBraceRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal98(e.HadMultipleCandidates());
  b.setVal99(e.IsElidable());
  b.setVal100(e.IsListInitialization());
  b.setVal101(e.IsStdInitializerListInitialization());
  b.setVal102(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal98(e.Value());
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
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal98(e.HasStoredFPFeatures());
  b.setVal99(e.IsAdditiveOperation());
  b.setVal100(e.IsAssignmentOperation());
  b.setVal101(e.IsBitwiseOperation());
  b.setVal102(e.IsCommaOperation());
  b.setVal104(e.IsComparisonOperation());
  b.setVal107(e.IsCompoundAssignmentOperation());
  b.setVal108(e.IsEqualityOperation());
  b.setVal109(e.IsLogicalOperation());
  b.setVal110(e.IsMultiplicativeOperation());
  b.setVal111(e.IsPointerMemoryOperation());
  b.setVal113(e.IsRelationalOperation());
  b.setVal114(e.IsShiftAssignOperation());
  b.setVal115(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BuiltinToken()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal38(es.EntityId(e.Order()));
  auto v39 = e.OrderFail();
  if (v39) {
    if (auto id39 = es.EntityId(v39.value())) {
      b.setVal39(id39);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.Pointer()));
  b.setVal41(es.EntityId(e.RParenToken()));
  auto v42 = e.Scope();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  auto v43 = e.Value1();
  if (v43) {
    if (auto id43 = es.EntityId(v43.value())) {
      b.setVal43(id43);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  auto v44 = e.Value2();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal101(true);
    } else {
      b.setVal101(false);
    }
  } else {
    b.setVal101(false);
  }
  auto v45 = e.Weak();
  if (v45) {
    if (auto id45 = es.EntityId(v45.value())) {
      b.setVal45(id45);
      b.setVal102(true);
    } else {
      b.setVal102(false);
    }
  } else {
    b.setVal102(false);
  }
  b.setVal104(e.IsCmpXChg());
  b.setVal107(e.IsOpenCL());
  b.setVal108(e.IsVolatile());
do {
    auto v17 = e.SubExpressions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  b.setVal98(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.CanOverflow());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  b.setVal37(es.EntityId(e.OperatorToken()));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal99(e.HasStoredFPFeatures());
  b.setVal100(e.IsArithmeticOperation());
  b.setVal101(e.IsDecrementOperation());
  b.setVal102(e.IsIncrementDecrementOperation());
  b.setVal104(e.IsIncrementOperation());
  b.setVal107(e.IsPostfix());
  b.setVal108(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ArgumentExpression();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal99(e.IsArgumentType());
}

void SerializeTypoExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v98 = e.Value();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
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
  b.setVal98(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  auto v98 = e.ContainsNonAscii();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  auto v100 = e.ContainsNonAsciiOrNull();
  if (v100) {
    b.setVal100(static_cast<bool>(v100.value()));
    b.setVal101(true);
  } else {
    b.setVal101(false);
  }
  auto v63 = e.Bytes();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v68 = e.String();
  if (v68) {
    if (v68->empty()) {
      b.setVal68("");
    } else {
      std::string s68(v68->data(), v68->size());
      b.setVal68(s68);
    }
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
  b.setVal104(e.IsAscii());
  b.setVal107(e.IsPascal());
  b.setVal108(e.IsUTF16());
  b.setVal109(e.IsUTF32());
  b.setVal110(e.IsUTF8());
  b.setVal111(e.IsWide());
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
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  b.setVal37(es.EntityId(e.Token()));
  b.setVal98(e.IsIntType());
  b.setVal99(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.OperatorToken()));
  b.setVal38(es.EntityId(e.Pack()));
  auto v112 = e.PackLength();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal39(es.EntityId(e.PackToken()));
do {
    auto ov105 = e.PartialArguments();
    if (!ov105) {
      b.setVal99(false);
      break;
    }
    b.setVal99(true);
    auto v105 = std::move(*ov105);
    auto sv105 = b.initVal105(static_cast<unsigned>(v105.size()));
    auto i105 = 0u;
    for (const auto &e105 : v105) {
      auto o105 = es.next_pseudo_entity_offset++;
      sv105.set(i105, o105);
      SerializeTemplateArgument(es, es.pseudo_builder[o105], e105);
      ++i105;
    }
  } while (false);
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal100(e.IsPartiallySubstituted());
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
do {
    auto v17 = e.LocalParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal38(es.EntityId(e.RBraceToken()));
  b.setVal39(es.EntityId(e.RequiresKWToken()));
  b.setVal98(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
do {
    auto v17 = e.SubExpressions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
}

void SerializePseudoObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ResultExpression()));
  b.setVal38(es.EntityId(e.SyntacticForm()));
do {
    auto v17 = e.Semantics();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
do {
    auto v23 = e.SemanticExpressions();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
}

void SerializePredefinedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.FunctionName()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v63 = e.IdentifierKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LParenToken()));
  b.setVal38(es.EntityId(e.RParenToken()));
do {
    auto v17 = e.Expressions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal38(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LAngleToken()));
  b.setVal38(es.EntityId(e.NameToken()));
  b.setVal39(es.EntityId(e.NamingClass()));
  b.setVal40(es.EntityId(e.RAngleToken()));
  b.setVal41(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal42(es.EntityId(e.Base()));
  b.setVal43(es.EntityId(e.MemberToken()));
  b.setVal44(es.EntityId(e.OperatorToken()));
  b.setVal100(e.HasUnresolvedUsing());
  b.setVal101(e.IsArrow());
  b.setVal102(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal100(e.IsOverloaded());
  b.setVal101(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal98(e.IsUnique());
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
  b.setVal98(e.IsArraySubscriptReferenceExpression());
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
  b.setVal98(e.IsClassReceiver());
  b.setVal99(e.IsExplicitProperty());
  b.setVal100(e.IsImplicitProperty());
  b.setVal101(e.IsMessagingGetter());
  b.setVal102(e.IsMessagingSetter());
  b.setVal104(e.IsObjectReceiver());
  b.setVal107(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
do {
    auto v17 = e.Arguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal37(es.EntityId(e.InstanceReceiver()));
  b.setVal38(es.EntityId(e.LeftToken()));
  b.setVal39(es.EntityId(e.MethodDeclaration()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal40(es.EntityId(e.ReceiverInterface()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  b.setVal98(e.IsClassMessage());
  b.setVal99(e.IsDelegateInitializerCall());
  b.setVal100(e.IsImplicit());
  b.setVal101(e.IsInstanceMessage());
do {
    auto v23 = e.SelectorTokens();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Declaration()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal40(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.BaseTokenEnd()));
  b.setVal39(es.EntityId(e.IsaMemberToken()));
  b.setVal40(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal98(e.ShouldCopy());
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
  b.setVal98(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal98(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ArrayWithObjectsMethod()));
do {
    auto v17 = e.Elements();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
do {
    auto v17 = e.Dimensions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
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
  b.setVal98(e.HadMultipleCandidates());
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasQualifier());
  b.setVal101(e.HasTemplateKeyword());
  b.setVal102(e.IsArrow());
  b.setVal104(e.IsImplicitAccess());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  b.setVal39(es.EntityId(e.RBracketToken()));
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal98(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExtendingDeclaration();
  if (v37) {
    if (auto id37 = es.EntityId(v37.value())) {
      b.setVal37(id37);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  auto v38 = e.LifetimeExtendedTemporaryDeclaration();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal100(e.IsBoundToLvalueReference());
  b.setVal101(e.IsUsableInConstantExpressions());
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
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  b.setVal39(es.EntityId(e.CaptureDefaultToken()));
  b.setVal40(es.EntityId(e.CompoundStatementBody()));
do {
    auto v17 = e.ExplicitTemplateParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  if (auto r41 = e.IntroducerRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal43(es.EntityId(e.LambdaClass()));
  auto v112 = e.TemplateParameterList();
  if (v112) {
    auto o112 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o112], v112.value());
    b.setVal112(o112);
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto v44 = e.TrailingRequiresClause();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal100(e.HasExplicitParameters());
  b.setVal101(e.HasExplicitResultType());
  b.setVal102(e.IsGenericLambda());
  b.setVal104(e.IsMutable());
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
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  auto v38 = e.InitializedFieldInUnion();
  if (v38) {
    if (auto id38 = es.EntityId(v38.value())) {
      b.setVal38(id38);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal39(es.EntityId(e.LBraceToken()));
  b.setVal40(es.EntityId(e.RBraceToken()));
  auto v41 = e.SemanticForm();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  auto v42 = e.SyntacticForm();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal101(true);
    } else {
      b.setVal101(false);
    }
  } else {
    b.setVal101(false);
  }
  b.setVal102(e.HadArrayRangeDesignator());
  b.setVal104(e.HasArrayFiller());
do {
    auto v17 = e.Initializers();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal107(e.IsExplicit());
  b.setVal108(e.IsSemanticForm());
  b.setVal109(e.IsStringLiteralInitializer());
  b.setVal110(e.IsSyntacticForm());
  b.setVal111(e.IsTransparent());
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
do {
    auto v17 = e.AssociationExpressions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal37(es.EntityId(e.ControllingExpression()));
  b.setVal38(es.EntityId(e.DefaultToken()));
  b.setVal39(es.EntityId(e.GenericToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal41(es.EntityId(e.ResultExpression()));
  b.setVal98(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ParameterPack()));
  b.setVal38(es.EntityId(e.ParameterPackToken()));
do {
    auto v17 = e.Expansions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
}

void SerializeFullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal98(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal98(e.HasAPValueResult());
  b.setVal99(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
  b.setVal98(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ContainsDuplicateElements());
  b.setVal37(es.EntityId(e.AccessorToken()));
  b.setVal38(es.EntityId(e.Base()));
  b.setVal99(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal98(e.Value());
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
  b.setVal2(static_cast<unsigned char>(mx::FromPasta(e.Access())));
  b.setVal3(static_cast<unsigned char>(mx::FromPasta(e.AccessUnsafe())));
  b.setVal4(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
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
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
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
do {
    auto v48 = e.Redeclarations();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
  b.setVal49(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
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
do {
    auto v55 = e.Parameters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
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
  auto v53 = e.BlockManglingContextDeclaration();
  if (v53) {
    if (auto id53 = es.EntityId(v53.value())) {
      b.setVal53(id53);
      b.setVal60(true);
    } else {
      b.setVal60(false);
    }
  } else {
    b.setVal60(false);
  }
  b.setVal61(es.EntityId(e.CaretToken()));
  b.setVal62(es.EntityId(e.CompoundBody()));
  b.setVal63(e.HasCaptures());
  b.setVal64(e.IsConversionFromLambda());
  b.setVal65(e.IsVariadic());
do {
    auto v55 = e.Parameters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
do {
    auto v56 = e.ParameterDeclarations();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  pasta::DeclContext dc66(e);
  auto v66 = dc66.AlreadyLoadedDeclarations();
  auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
  auto i66 = 0u;
  for (const pasta::Decl &e66 : v66) {
    sv66.set(i66, es.EntityId(e66));
    ++i66;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.AccessSpecifierToken()));
  b.setVal61(es.EntityId(e.ColonToken()));
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
do {
    auto v55 = e.Varlists();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
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
do {
    auto v55 = e.Varlists();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
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
  b.setVal61(es.EntityId(e.Message()));
  b.setVal62(es.EntityId(e.RParenToken()));
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
  auto v67 = e.Name();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  auto v68 = e.Value();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v67 = e.Argument();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.GetterCXXConstructor()));
  b.setVal61(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal62(es.EntityId(e.PropertyDeclaration()));
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal70(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal71(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal72(es.EntityId(e.SetterCXXAssignment()));
  b.setVal73(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal54(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.LinkageInternal())));
  b.setVal67(e.Name());
  auto v75 = e.ObjCFStringFormattingFamily();
  if (v75) {
    b.setVal75(static_cast<unsigned char>(v75.value()));
    b.setVal54(true);
  } else {
    b.setVal54(false);
  }
  b.setVal68(e.QualifiedNameAsString());
  b.setVal53(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal76(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal57(e.HasExternalFormalLinkage());
  b.setVal58(e.HasLinkage());
  b.setVal59(e.HasLinkageBeenComputed());
  b.setVal60(e.IsCXXClassMember());
  b.setVal63(e.IsCXXInstanceMember());
  b.setVal64(e.IsExternallyDeclarable());
  b.setVal65(e.IsExternallyVisible());
  b.setVal77(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v78 = e.MSAssemblyLabel();
  std::string s78(v78.data(), v78.size());
  b.setVal78(s78);
  b.setVal61(es.EntityId(e.Statement()));
  b.setVal79(e.IsGnuLocal());
  b.setVal80(e.IsMSAssemblyLabel());
  b.setVal81(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
do {
    auto v55 = e.Shadows();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal61(es.EntityId(e.EnumDeclaration()));
  b.setVal62(es.EntityId(e.EnumToken()));
  b.setVal70(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal61(es.EntityId(e.UsingToken()));
  b.setVal79(e.HasTypename());
  b.setVal80(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal79(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal61(es.EntityId(e.EllipsisToken()));
  b.setVal62(es.EntityId(e.UsingToken()));
  b.setVal80(e.IsAccessDeclaration());
  b.setVal81(e.IsPackExpansion());
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
  b.setVal61(es.EntityId(e.Combiner()));
  b.setVal62(es.EntityId(e.CombinerIn()));
  b.setVal70(es.EntityId(e.CombinerOut()));
  b.setVal71(es.EntityId(e.InitializerOriginal()));
  b.setVal72(es.EntityId(e.InitializerPrivate()));
  b.setVal73(es.EntityId(e.Initializer()));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  b.setVal83(es.EntityId(e.PrevDeclarationInScope()));
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
do {
    auto v55 = e.Chain();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  auto v61 = e.AnonymousField();
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
  auto v62 = e.VariableDeclaration();
  if (v62) {
    if (auto id62 = es.EntityId(v62.value())) {
      b.setVal62(id62);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v61 = e.InitializerExpression();
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

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal61(es.EntityId(e.InnerTokenStart()));
  b.setVal62(es.EntityId(e.OuterTokenStart()));
  auto v70 = e.TrailingRequiresClause();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  b.setVal71(es.EntityId(e.TypeSpecEndToken()));
  b.setVal72(es.EntityId(e.TypeSpecStartToken()));
do {
    auto v84 = e.TemplateParameterLists();
    auto sv84 = b.initVal84(static_cast<unsigned>(v84.size()));
    auto i84 = 0u;
    for (const auto &e84 : v84) {
      auto o84 = es.next_pseudo_entity_offset++;
      sv84.set(i84, o84);
      SerializeTemplateParameterList(es, es.pseudo_builder[o84], e84);
      ++i84;
    }
  } while (false);
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v73 = e.ActingDefinition();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  auto v83 = e.Initializer();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v86 = e.InitializingDeclaration();
  if (v86) {
    if (auto id86 = es.EntityId(v86.value())) {
      b.setVal86(id86);
      b.setVal87(true);
    } else {
      b.setVal87(false);
    }
  } else {
    b.setVal87(false);
  }
  auto v88 = e.InstantiatedFromStaticDataMember();
  if (v88) {
    if (auto id88 = es.EntityId(v88.value())) {
      b.setVal88(id88);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal91(es.EntityId(e.PointOfInstantiation()));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v96 = e.TemplateInstantiationPattern();
  if (v96) {
    if (auto id96 = es.EntityId(v96.value())) {
      b.setVal96(id96);
      b.setVal97(true);
    } else {
      b.setVal97(false);
    }
  } else {
    b.setVal97(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal100(e.HasConstantInitialization());
  b.setVal101(e.HasDependentAlignment());
  b.setVal102(e.HasExternalStorage());
  b.setVal103(e.HasGlobalStorage());
  auto v104 = e.HasICEInitializer();
  if (v104) {
    b.setVal104(static_cast<bool>(v104.value()));
    b.setVal105(true);
  } else {
    b.setVal105(false);
  }
  b.setVal106(e.HasInitializer());
  b.setVal107(e.HasLocalStorage());
  b.setVal108(e.IsARCPseudoStrong());
  b.setVal109(e.IsCXXForRangeDeclaration());
  b.setVal110(e.IsConstexpr());
  b.setVal111(e.IsDirectInitializer());
  b.setVal112(e.IsEscapingByref());
  b.setVal113(e.IsExceptionVariable());
  b.setVal114(e.IsExternC());
  b.setVal115(e.IsFileVariableDeclaration());
  b.setVal116(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal117(e.IsInExternCContext());
  b.setVal118(e.IsInExternCXXContext());
  b.setVal119(e.IsInitializerCapture());
  b.setVal120(e.IsInline());
  b.setVal121(e.IsInlineSpecified());
  b.setVal122(e.IsKnownToBeDefined());
  b.setVal123(e.IsLocalVariableDeclaration());
  b.setVal124(e.IsLocalVariableDeclarationOrParm());
  b.setVal125(e.IsNRVOVariable());
  b.setVal126(e.IsNoDestroy());
  b.setVal127(e.IsNonEscapingByref());
  b.setVal128(e.IsObjCForDeclaration());
  b.setVal129(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal130(e.IsStaticDataMember());
  b.setVal131(e.IsStaticLocal());
  b.setVal132(e.IsThisDeclarationADemotedDefinition());
  b.setVal133(e.IsUsableInConstantExpressions());
  b.setVal134(e.MightBeUsableInConstantExpressions());
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v136 = e.DefaultArgument();
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
  if (auto r138 = e.DefaultArgumentRange(); auto rs138 = r138.Size()) {
    b.setVal138(es.EntityId(r138[0]));
    b.setVal139(es.EntityId(r138[rs138 - 1u]));
  } else {
    b.setVal138(0);
    b.setVal139(0);
  }
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  auto v141 = e.UninstantiatedDefaultArgument();
  if (v141) {
    if (auto id141 = es.EntityId(v141.value())) {
      b.setVal141(id141);
      b.setVal142(true);
    } else {
      b.setVal142(false);
    }
  } else {
    b.setVal142(false);
  }
  b.setVal143(e.HasDefaultArgument());
  b.setVal144(e.HasInheritedDefaultArgument());
  b.setVal145(e.HasUninstantiatedDefaultArgument());
  b.setVal146(e.HasUnparsedDefaultArgument());
  b.setVal147(e.IsDestroyedInCallee());
  b.setVal148(e.IsKNRPromoted());
  b.setVal149(e.IsObjCMethodParameter());
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
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
do {
    auto v55 = e.Bindings();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal136(es.EntityId(e.ExternToken()));
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
do {
    auto v150 = e.TemplateArguments();
    auto sv150 = b.initVal150(static_cast<unsigned>(v150.size()));
    auto i150 = 0u;
    for (const auto &e150 : v150) {
      auto o150 = es.next_pseudo_entity_offset++;
      sv150.set(i150, o150);
      SerializeTemplateArgument(es, es.pseudo_builder[o150], e150);
      ++i150;
    }
  } while (false);
do {
    auto v151 = e.TemplateInstantiationArguments();
    auto sv151 = b.initVal151(static_cast<unsigned>(v151.size()));
    auto i151 = 0u;
    for (const auto &e151 : v151) {
      auto o151 = es.next_pseudo_entity_offset++;
      sv151.set(i151, o151);
      SerializeTemplateArgument(es, es.pseudo_builder[o151], e151);
      ++i151;
    }
  } while (false);
  b.setVal138(es.EntityId(e.TemplateKeywordToken()));
  b.setVal137(e.IsClassScopeExplicitSpecialization());
  b.setVal142(e.IsExplicitInstantiationOrSpecialization());
  b.setVal143(e.IsExplicitSpecialization());
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
  b.setVal81(e.DefaultArgumentWasInherited());
  b.setVal73(es.EntityId(e.DefaultArgument()));
  b.setVal83(es.EntityId(e.DefaultArgumentToken()));
  b.setVal86(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal85(e.HasDefaultArgument());
  b.setVal87(e.HasPlaceholderTypeConstraint());
  b.setVal89(e.IsExpandedParameterPack());
  b.setVal97(e.IsPackExpansion());
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.HasGetter());
  b.setVal85(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v81 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v81) {
    b.setVal81(static_cast<bool>(v81.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  b.setVal87(e.DoesThisDeclarationHaveABody());
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  auto v73 = e.Definition();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal89(true);
    } else {
      b.setVal89(false);
    }
  } else {
    b.setVal89(false);
  }
  b.setVal83(es.EntityId(e.EllipsisToken()));
  if (auto r86 = e.ExceptionSpecSourceRange(); auto rs86 = r86.Size()) {
    b.setVal86(es.EntityId(r86[0]));
    b.setVal88(es.EntityId(r86[rs86 - 1u]));
  } else {
    b.setVal86(0);
    b.setVal88(0);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v91 = e.InstantiatedFromMemberFunction();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal97(true);
    } else {
      b.setVal97(false);
    }
  } else {
    b.setVal97(false);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v152 = e.ODRHash();
  if (v152) {
    b.setVal152(static_cast<unsigned>(v152.value()));
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r96 = e.ParametersSourceRange(); auto rs96 = r96.Size()) {
    b.setVal96(es.EntityId(r96[0]));
    b.setVal136(es.EntityId(r96[rs96 - 1u]));
  } else {
    b.setVal96(0);
    b.setVal136(0);
  }
  b.setVal138(es.EntityId(e.PointOfInstantiation()));
  if (auto r139 = e.ReturnTypeSourceRange(); auto rs139 = r139.Size()) {
    b.setVal139(es.EntityId(r139[0]));
    b.setVal141(es.EntityId(r139[rs139 - 1u]));
  } else {
    b.setVal139(0);
    b.setVal141(0);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v153 = e.TemplateInstantiationPattern();
  if (v153) {
    if (auto id153 = es.EntityId(v153.value())) {
      b.setVal153(id153);
      b.setVal101(true);
    } else {
      b.setVal101(false);
    }
  } else {
    b.setVal101(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal102(e.HasImplicitReturnZero());
  b.setVal103(e.HasInheritedPrototype());
  b.setVal104(e.HasOneParameterOrDefaultArguments());
  b.setVal105(e.HasPrototype());
  b.setVal106(e.HasSkippedBody());
  b.setVal107(e.HasTrivialBody());
  b.setVal108(e.HasWrittenPrototype());
  b.setVal109(e.InstantiationIsPending());
  b.setVal110(e.IsCPUDispatchMultiVersion());
  b.setVal111(e.IsCPUSpecificMultiVersion());
  b.setVal112(e.IsConsteval());
  b.setVal113(e.IsConstexpr());
  b.setVal114(e.IsConstexprSpecified());
  b.setVal115(e.IsDefaulted());
  b.setVal116(e.IsDeleted());
  b.setVal117(e.IsDeletedAsWritten());
  b.setVal118(e.IsDestroyingOperatorDelete());
  b.setVal119(e.IsExplicitlyDefaulted());
  b.setVal120(e.IsExternC());
  b.setVal121(e.IsFunctionTemplateSpecialization());
  b.setVal122(e.IsGlobal());
  b.setVal123(e.IsImplicitlyInstantiable());
  b.setVal124(e.IsInExternCContext());
  b.setVal125(e.IsInExternCXXContext());
  b.setVal126(e.IsInlineBuiltinDeclaration());
  auto v127 = e.IsInlineDefinitionExternallyVisible();
  if (v127) {
    b.setVal127(static_cast<bool>(v127.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  b.setVal129(e.IsInlineSpecified());
  b.setVal130(e.IsInlined());
  b.setVal131(e.IsLateTemplateParsed());
  auto v132 = e.IsMSExternInline();
  if (v132) {
    b.setVal132(static_cast<bool>(v132.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  b.setVal134(e.IsMSVCRTEntryPoint());
  b.setVal137(e.IsMain());
  b.setVal142(e.IsMultiVersion());
  b.setVal143(e.IsNoReturn());
  b.setVal144(e.IsOverloadedOperator());
  b.setVal145(e.IsPure());
  b.setVal146(e.IsReplaceableGlobalAllocationFunction());
  auto v147 = e.IsReservedGlobalPlacementOperator();
  if (v147) {
    b.setVal147(static_cast<bool>(v147.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  b.setVal149(e.IsStatic());
  b.setVal154(e.IsTargetMultiVersion());
  b.setVal155(e.IsTemplateInstantiation());
  b.setVal156(e.IsThisDeclarationADefinition());
  b.setVal157(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal158(e.IsTrivial());
  b.setVal159(e.IsTrivialForCall());
  b.setVal160(e.IsUserProvided());
  b.setVal161(e.IsVariadic());
  b.setVal162(e.IsVirtualAsWritten());
do {
    auto v55 = e.Parameters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  b.setVal163(e.UsesSEHTry());
  b.setVal164(e.WillHaveBody());
  auto v165 = e.Body();
  if (v165) {
    if (auto id165 = es.EntityId(v165.value())) {
      b.setVal165(id165);
      b.setVal166(true);
    } else {
      b.setVal166(false);
    }
  } else {
    b.setVal166(false);
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
  b.setVal167(es.EntityId(e.Parent()));
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal168(e.HasInlineBody());
  b.setVal169(e.IsConst());
  b.setVal170(e.IsCopyAssignmentOperator());
  b.setVal171(e.IsInstance());
  b.setVal172(e.IsLambdaStaticInvoker());
  b.setVal173(e.IsMoveAssignmentOperator());
  b.setVal174(e.IsVirtual());
  b.setVal175(e.IsVolatile());
do {
    auto v66 = e.OverriddenMethods();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      sv66.set(i66, es.EntityId(e66));
      ++i66;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v176 = e.OperatorDelete();
  if (v176) {
    if (auto id176 = es.EntityId(v176.value())) {
      b.setVal176(id176);
      b.setVal177(true);
    } else {
      b.setVal177(false);
    }
  } else {
    b.setVal177(false);
  }
  auto v178 = e.OperatorDeleteThisArgument();
  if (v178) {
    if (auto id178 = es.EntityId(v178.value())) {
      b.setVal178(id178);
      b.setVal179(true);
    } else {
      b.setVal179(false);
    }
  } else {
    b.setVal179(false);
  }
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal177(e.IsExplicit());
  b.setVal179(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v176 = e.TargetConstructor();
  if (v176) {
    if (auto id176 = es.EntityId(v176.value())) {
      b.setVal176(id176);
      b.setVal177(true);
    } else {
      b.setVal177(false);
    }
  } else {
    b.setVal177(false);
  }
  b.setVal179(e.IsDefaultConstructor());
  b.setVal180(e.IsDelegatingConstructor());
  b.setVal181(e.IsExplicit());
  b.setVal182(e.IsInheritingConstructor());
  b.setVal183(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal167(es.EntityId(e.CorrespondingConstructor()));
  b.setVal168(e.IsCopyDeductionCandidate());
  b.setVal169(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v73 = e.BitWidth();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v83 = e.InClassInitializer();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
  b.setVal86(es.EntityId(e.Parent()));
  b.setVal87(e.HasCapturedVLAType());
  b.setVal89(e.HasInClassInitializer());
  b.setVal97(e.IsAnonymousStructOrUnion());
  b.setVal100(e.IsBitField());
  b.setVal101(e.IsMutable());
  b.setVal102(e.IsUnnamedBitfield());
  b.setVal103(e.IsZeroLengthBitField());
  b.setVal104(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal88(es.EntityId(e.ContainingInterface()));
  b.setVal91(es.EntityId(e.NextInstanceVariable()));
  b.setVal105(e.Synthesize());
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
  b.setVal61(es.EntityId(e.Binding()));
  b.setVal62(es.EntityId(e.DecomposedDeclaration()));
  b.setVal70(es.EntityId(e.HoldingVariable()));
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
  b.setVal61(es.EntityId(e.MapperVariableReference()));
  b.setVal62(es.EntityId(e.PrevDeclarationInScope()));
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
  b.setVal61(es.EntityId(e.Introducer()));
  auto v62 = e.NextUsingShadowDeclaration();
  if (v62) {
    if (auto id62 = es.EntityId(v62.value())) {
      b.setVal62(id62);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal70(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal80(e.ConstructsVirtualBase());
  b.setVal71(es.EntityId(e.ConstructedBaseClass()));
  auto v72 = e.ConstructedBaseClassShadowDeclaration();
  if (v72) {
    if (auto id72 = es.EntityId(v72.value())) {
      b.setVal72(id72);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal73(es.EntityId(e.NominatedBaseClass()));
  auto v83 = e.NominatedBaseClassShadowDeclaration();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
  b.setVal86(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
do {
    auto v55 = e.Expansions();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  b.setVal61(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal61(es.EntityId(e.IdentifierToken()));
  b.setVal62(es.EntityId(e.NamespaceKeyToken()));
  b.setVal70(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal71(es.EntityId(e.UsingToken()));
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
  b.setVal79(e.DefaultArgumentWasInherited());
  b.setVal61(es.EntityId(e.DefaultArgumentToken()));
  b.setVal80(e.HasDefaultArgument());
  b.setVal81(e.HasTypeConstraint());
  b.setVal85(e.IsExpandedParameterPack());
  b.setVal87(e.IsPackExpansion());
  b.setVal89(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r61 = e.BraceRange(); auto rs61 = r61.Size()) {
    b.setVal61(es.EntityId(r61[0]));
    b.setVal62(es.EntityId(r61[rs61 - 1u]));
  } else {
    b.setVal61(0);
    b.setVal62(0);
  }
  auto v70 = e.Definition();
  if (v70) {
    if (auto id70 = es.EntityId(v70.value())) {
      b.setVal70(id70);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal71(es.EntityId(e.InnerTokenStart()));
  b.setVal72(es.EntityId(e.OuterTokenStart()));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v73 = e.TypedefNameForAnonymousDeclaration();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  b.setVal81(e.HasNameForLinkage());
  b.setVal85(e.IsBeingDefined());
  b.setVal87(e.IsClass());
  b.setVal89(e.IsCompleteDefinition());
  b.setVal97(e.IsCompleteDefinitionRequired());
  b.setVal100(e.IsDependentType());
  b.setVal101(e.IsEmbeddedInDeclarator());
  b.setVal102(e.IsEnum());
  b.setVal103(e.IsFreeStanding());
  b.setVal104(e.IsInterface());
  b.setVal105(e.IsStruct());
  b.setVal106(e.IsThisDeclarationADefinition());
  b.setVal107(e.IsUnion());
  b.setVal108(e.MayHaveOutOfDateDefinition());
do {
    auto v84 = e.TemplateParameterLists();
    auto sv84 = b.initVal84(static_cast<unsigned>(v84.size()));
    auto i84 = 0u;
    for (const auto &e84 : v84) {
      auto o84 = es.next_pseudo_entity_offset++;
      sv84.set(i84, o84);
      SerializeTemplateParameterList(es, es.pseudo_builder[o84], e84);
      ++i84;
    }
  } while (false);
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
  b.setVal109(e.CanPassInRegisters());
do {
    auto v56 = e.Fields();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  auto v83 = e.FindFirstNamedDataMember();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal110(true);
    } else {
      b.setVal110(false);
    }
  } else {
    b.setVal110(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal111(e.HasFlexibleArrayMember());
  b.setVal112(e.HasLoadedFieldsFromExternalStorage());
  b.setVal113(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal114(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal115(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal116(e.HasObjectMember());
  b.setVal117(e.HasVolatileMember());
  b.setVal118(e.IsAnonymousStructOrUnion());
  b.setVal119(e.IsCapturedRecord());
  b.setVal120(e.IsInjectedClassName());
  b.setVal121(e.IsLambda());
  b.setVal122(e.IsMsStruct());
  b.setVal123(e.IsNonTrivialToPrimitiveCopy());
  b.setVal124(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal125(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal126(e.IsOrContainsUnion());
  b.setVal127(e.IsParameterDestroyedInCallee());
  b.setVal128(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v129 = e.AllowConstDefaultInitializer();
  if (v129) {
    b.setVal129(static_cast<bool>(v129.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
do {
    auto ov150 = e.Bases();
    if (!ov150) {
      b.setVal131(false);
      break;
    }
    b.setVal131(true);
    auto v150 = std::move(*ov150);
    auto sv150 = b.initVal150(static_cast<unsigned>(v150.size()));
    auto i150 = 0u;
    for (const auto &e150 : v150) {
      auto o150 = es.next_pseudo_entity_offset++;
      sv150.set(i150, o150);
      SerializeCXXBaseSpecifier(es, es.pseudo_builder[o150], e150);
      ++i150;
    }
  } while (false);
  auto v92 = e.CalculateInheritanceModel();
  if (v92) {
    b.setVal92(static_cast<unsigned char>(v92.value()));
    b.setVal132(true);
  } else {
    b.setVal132(false);
  }
do {
    auto v66 = e.Constructors();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      sv66.set(i66, es.EntityId(e66));
      ++i66;
    }
  } while (false);
do {
    auto ov184 = e.Friends();
    if (!ov184) {
      b.setVal133(false);
      break;
    }
    b.setVal133(true);
    auto v184 = std::move(*ov184);
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  auto v86 = e.Destructor();
  if (v86) {
    if (auto id86 = es.EntityId(v86.value())) {
      b.setVal86(id86);
      b.setVal134(true);
    } else {
      b.setVal134(false);
    }
  } else {
    b.setVal134(false);
  }
  auto v152 = e.GenericLambdaTemplateParameterList();
  if (v152) {
    auto o152 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o152], v152.value());
    b.setVal152(o152);
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  auto v88 = e.InstantiatedFromMemberClass();
  if (v88) {
    if (auto id88 = es.EntityId(v88.value())) {
      b.setVal88(id88);
      b.setVal142(true);
    } else {
      b.setVal142(false);
    }
  } else {
    b.setVal142(false);
  }
  auto v91 = e.LambdaCallOperator();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal143(true);
    } else {
      b.setVal143(false);
    }
  } else {
    b.setVal143(false);
  }
  auto v93 = e.LambdaCaptureDefault();
  if (v93) {
    b.setVal93(static_cast<unsigned char>(v93.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  auto v96 = e.LambdaContextDeclaration();
  if (v96) {
    if (auto id96 = es.EntityId(v96.value())) {
      b.setVal96(id96);
      b.setVal145(true);
    } else {
      b.setVal145(false);
    }
  } else {
    b.setVal145(false);
  }
do {
    auto ov185 = e.LambdaExplicitTemplateParameters();
    if (!ov185) {
      b.setVal146(false);
      break;
    }
    b.setVal146(true);
    auto v185 = std::move(*ov185);
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
    }
  } while (false);
  auto v186 = e.LambdaManglingNumber();
  if (v186) {
    b.setVal186(static_cast<unsigned>(v186.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v94 = e.MSInheritanceModel();
  if (v94) {
    b.setVal94(static_cast<unsigned char>(v94.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v187 = e.NumBases();
  if (v187) {
    b.setVal187(static_cast<unsigned>(v187.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v188 = e.NumVirtualBases();
  if (v188) {
    b.setVal188(static_cast<unsigned>(v188.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v189 = e.ODRHash();
  if (v189) {
    b.setVal189(static_cast<unsigned>(v189.value()));
    b.setVal155(true);
  } else {
    b.setVal155(false);
  }
  auto v136 = e.TemplateInstantiationPattern();
  if (v136) {
    if (auto id136 = es.EntityId(v136.value())) {
      b.setVal136(id136);
      b.setVal156(true);
    } else {
      b.setVal156(false);
    }
  } else {
    b.setVal156(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v157 = e.HasAnyDependentBases();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  auto v159 = e.HasConstexprDefaultConstructor();
  if (v159) {
    b.setVal159(static_cast<bool>(v159.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v161 = e.HasConstexprDestructor();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v163 = e.HasConstexprNonCopyMoveConstructor();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v166 = e.HasCopyAssignmentWithConstParameter();
  if (v166) {
    b.setVal166(static_cast<bool>(v166.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasCopyConstructorWithConstParameter();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v171 = e.HasDefaultConstructor();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  auto v173 = e.HasDefinition();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasDirectFields();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal177(true);
  } else {
    b.setVal177(false);
  }
  auto v179 = e.HasFriends();
  if (v179) {
    b.setVal179(static_cast<bool>(v179.value()));
    b.setVal180(true);
  } else {
    b.setVal180(false);
  }
  auto v181 = e.HasInClassInitializer();
  if (v181) {
    b.setVal181(static_cast<bool>(v181.value()));
    b.setVal182(true);
  } else {
    b.setVal182(false);
  }
  auto v183 = e.HasInheritedAssignment();
  if (v183) {
    b.setVal183(static_cast<bool>(v183.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v191 = e.HasInheritedConstructor();
  if (v191) {
    b.setVal191(static_cast<bool>(v191.value()));
    b.setVal192(true);
  } else {
    b.setVal192(false);
  }
  auto v193 = e.HasIrrelevantDestructor();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasKnownLambdaInternalLinkage();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasMoveAssignment();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasMoveConstructor();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasMutableFields();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasNonLiteralTypeFieldsOrBases();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonTrivialCopyAssignment();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialCopyConstructor();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialCopyConstructorForCall();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialDefaultConstructor();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialDestructor();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialDestructorForCall();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialMoveAssignment();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasNonTrivialMoveConstructor();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasNonTrivialMoveConstructorForCall();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasPrivateFields();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasProtectedFields();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasSimpleCopyAssignment();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasSimpleCopyConstructor();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasSimpleDestructor();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasSimpleMoveAssignment();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasSimpleMoveConstructor();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasTrivialCopyAssignment();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialCopyConstructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialCopyConstructorForCall();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialDefaultConstructor();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialDestructor();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialDestructorForCall();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialMoveAssignment();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasTrivialMoveConstructor();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasTrivialMoveConstructorForCall();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasUninitializedReferenceMember();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUserDeclaredConstructor();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredCopyAssignment();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredCopyConstructor();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredDestructor();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserDeclaredMoveAssignment();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserDeclaredMoveConstructor();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasUserDeclaredMoveOperation();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.HasUserProvidedDefaultConstructor();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.HasVariantMembers();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.ImplicitCopyConstructorHasConstParameter();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.IsAbstract();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsAggregate();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsAnyDestructorNoReturn();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsCLike();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsCXX11StandardLayout();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  b.setVal289(e.IsDependentLambda());
  auto v290 = e.IsDynamicClass();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v292 = e.IsEffectivelyFinal();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v294 = e.IsEmpty();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  b.setVal296(e.IsGenericLambda());
  auto v297 = e.IsInterfaceLike();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsLiteral();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v138 = e.IsLocalClass();
  if (v138) {
    if (auto id138 = es.EntityId(v138.value())) {
      b.setVal138(id138);
      b.setVal301(true);
    } else {
      b.setVal301(false);
    }
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsPOD();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsPolymorphic();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.IsStandardLayout();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.IsStructural();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.IsTrivial();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.IsTriviallyCopyable();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.MayBeAbstract();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.MayBeDynamicClass();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.MayBeNonDynamicClass();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
do {
    auto ov322 = e.Methods();
    if (!ov322) {
      b.setVal323(false);
      break;
    }
    b.setVal323(true);
    auto v322 = std::move(*ov322);
    auto sv322 = b.initVal322(static_cast<unsigned>(v322.size()));
    auto i322 = 0u;
    for (const auto &e322 : v322) {
      sv322.set(i322, es.EntityId(e322));
      ++i322;
    }
  } while (false);
  auto v324 = e.NeedsImplicitCopyAssignment();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsImplicitCopyConstructor();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NeedsImplicitDefaultConstructor();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsImplicitDestructor();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsImplicitMoveAssignment();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsImplicitMoveConstructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsOverloadResolutionForDestructor();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  auto v344 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  auto v346 = e.NullFieldOffsetIsZero();
  if (v346) {
    b.setVal346(static_cast<bool>(v346.value()));
    b.setVal347(true);
  } else {
    b.setVal347(false);
  }
do {
    auto ov151 = e.VirtualBases();
    if (!ov151) {
      b.setVal348(false);
      break;
    }
    b.setVal348(true);
    auto v151 = std::move(*ov151);
    auto sv151 = b.initVal151(static_cast<unsigned>(v151.size()));
    auto i151 = 0u;
    for (const auto &e151 : v151) {
      auto o151 = es.next_pseudo_entity_offset++;
      sv151.set(i151, o151);
      SerializeCXXBaseSpecifier(es, es.pseudo_builder[o151], e151);
      ++i151;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  b.setVal139(es.EntityId(e.ExternToken()));
  b.setVal141(es.EntityId(e.PointOfInstantiation()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
do {
    auto v349 = e.TemplateArguments();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      auto o349 = es.next_pseudo_entity_offset++;
      sv349.set(i349, o349);
      SerializeTemplateArgument(es, es.pseudo_builder[o349], e349);
      ++i349;
    }
  } while (false);
do {
    auto v350 = e.TemplateInstantiationArguments();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      auto o350 = es.next_pseudo_entity_offset++;
      sv350.set(i350, o350);
      SerializeTemplateArgument(es, es.pseudo_builder[o350], e350);
      ++i350;
    }
  } while (false);
  b.setVal153(es.EntityId(e.TemplateKeywordToken()));
  b.setVal351(e.IsClassScopeExplicitSpecialization());
  b.setVal352(e.IsExplicitInstantiationOrSpecialization());
  b.setVal353(e.IsExplicitSpecialization());
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
do {
    auto v56 = e.Enumerators();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  auto v83 = e.InstantiatedFromMemberEnum();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  if (auto r86 = e.IntegerTypeRange(); auto rs86 = r86.Size()) {
    b.setVal86(es.EntityId(r86[0]));
    b.setVal88(es.EntityId(r86[rs86 - 1u]));
  } else {
    b.setVal86(0);
    b.setVal88(0);
  }
  auto v152 = e.ODRHash();
  if (v152) {
    b.setVal152(static_cast<unsigned>(v152.value()));
    b.setVal110(true);
  } else {
    b.setVal110(false);
  }
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal111(true);
    } else {
      b.setVal111(false);
    }
  } else {
    b.setVal111(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal112(e.IsClosed());
  b.setVal113(e.IsClosedFlag());
  b.setVal114(e.IsClosedNonFlag());
  b.setVal115(e.IsComplete());
  b.setVal116(e.IsFixed());
  b.setVal117(e.IsScoped());
  b.setVal118(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal61(es.EntityId(e.EllipsisToken()));
  b.setVal62(es.EntityId(e.TypenameToken()));
  b.setVal70(es.EntityId(e.UsingToken()));
  b.setVal79(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v61 = e.AnonymousDeclarationWithTypedefName();
  if (v61) {
    if (auto id61 = es.EntityId(v61.value())) {
      b.setVal61(id61);
      b.setVal79(true);
    } else {
      b.setVal79(false);
    }
  } else {
    b.setVal79(false);
  }
  b.setVal80(e.IsModed());
  b.setVal81(e.IsTransparentTag());
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
  auto v62 = e.DescribedAliasTemplate();
  if (v62) {
    if (auto id62 = es.EntityId(v62.value())) {
      b.setVal62(id62);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  b.setVal62(es.EntityId(e.ColonToken()));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  b.setVal70(es.EntityId(e.VarianceToken()));
  b.setVal85(e.HasExplicitBound());
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
  b.setVal61(es.EntityId(e.ConstraintExpression()));
  b.setVal79(e.IsTypeConcept());
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
  b.setVal61(es.EntityId(e.AtToken()));
  b.setVal62(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal70(es.EntityId(e.GetterNameToken()));
  b.setVal71(es.EntityId(e.LParenToken()));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal72(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal73(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal83(es.EntityId(e.SetterNameToken()));
  b.setVal79(e.IsAtomic());
  b.setVal80(e.IsClassProperty());
  b.setVal81(e.IsDirectProperty());
  b.setVal85(e.IsInstanceProperty());
  b.setVal87(e.IsOptional());
  b.setVal89(e.IsReadOnly());
  b.setVal97(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal79(e.DefinedInNSObject());
  b.setVal61(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal62(es.EntityId(e.Category()));
  b.setVal70(es.EntityId(e.ClassInterface()));
  b.setVal71(es.EntityId(e.CmdDeclaration()));
  b.setVal72(es.EntityId(e.DeclaratorEndToken()));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  if (auto r73 = e.ReturnTypeSourceRange(); auto rs73 = r73.Size()) {
    b.setVal73(es.EntityId(r73[0]));
    b.setVal83(es.EntityId(r73[rs73 - 1u]));
  } else {
    b.setVal73(0);
    b.setVal83(0);
  }
  b.setVal86(es.EntityId(e.SelectorStartToken()));
  b.setVal88(es.EntityId(e.SelfDeclaration()));
  b.setVal80(e.HasRedeclaration());
  b.setVal81(e.HasRelatedResultType());
  b.setVal85(e.HasSkippedBody());
  b.setVal87(e.IsClassMethod());
  b.setVal89(e.IsDefined());
  b.setVal97(e.IsDesignatedInitializerForTheInterface());
  b.setVal100(e.IsDirectMethod());
  b.setVal101(e.IsInstanceMethod());
  b.setVal102(e.IsOptional());
  b.setVal103(e.IsOverriding());
  b.setVal104(e.IsPropertyAccessor());
  b.setVal105(e.IsRedeclaration());
  b.setVal106(e.IsSynthesizedAccessorStub());
  b.setVal107(e.IsThisDeclarationADefinition());
  b.setVal108(e.IsThisDeclarationADesignatedInitializer());
  b.setVal109(e.IsVariadic());
do {
    auto v55 = e.Parameters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
do {
    auto v56 = e.SelectorTokens();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  pasta::DeclContext dc66(e);
  auto v66 = dc66.AlreadyLoadedDeclarations();
  auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
  auto i66 = 0u;
  for (const pasta::Decl &e66 : v66) {
    sv66.set(i66, es.EntityId(e66));
    ++i66;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
do {
    auto v55 = e.ClassMethods();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
do {
    auto v56 = e.ClassProperties();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  if (auto r61 = e.AtEndRange(); auto rs61 = r61.Size()) {
    b.setVal61(es.EntityId(r61[0]));
    b.setVal62(es.EntityId(r61[rs61 - 1u]));
  } else {
    b.setVal61(0);
    b.setVal62(0);
  }
  b.setVal70(es.EntityId(e.AtStartToken()));
do {
    auto v66 = e.InstanceMethods();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      sv66.set(i66, es.EntityId(e66));
      ++i66;
    }
  } while (false);
do {
    auto v184 = e.InstanceProperties();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
do {
    auto v185 = e.Methods();
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
    }
  } while (false);
do {
    auto v322 = e.Properties();
    auto sv322 = b.initVal322(static_cast<unsigned>(v322.size()));
    auto i322 = 0u;
    for (const auto &e322 : v322) {
      sv322.set(i322, es.EntityId(e322));
      ++i322;
    }
  } while (false);
  pasta::DeclContext dc354(e);
  auto v354 = dc354.AlreadyLoadedDeclarations();
  auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
  auto i354 = 0u;
  for (const pasta::Decl &e354 : v354) {
    sv354.set(i354, es.EntityId(e354));
    ++i354;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal79(e.IsClassExtension());
  b.setVal71(es.EntityId(e.CategoryNameToken()));
  b.setVal72(es.EntityId(e.ClassInterface()));
  b.setVal73(es.EntityId(e.Implementation()));
  b.setVal83(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal86(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal88(es.EntityId(e.NextClassCategory()));
  b.setVal91(es.EntityId(e.NextClassCategoryRaw()));
do {
    auto v355 = e.InstanceVariables();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
do {
    auto v356 = e.ProtocolTokens();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
do {
    auto v357 = e.Protocols();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal71(es.EntityId(e.Definition()));
  auto v78 = e.ObjCRuntimeNameAsString();
  std::string s78(v78.data(), v78.size());
  b.setVal78(s78);
  b.setVal79(e.HasDefinition());
  b.setVal80(e.IsNonRuntimeProtocol());
  b.setVal81(e.IsThisDeclarationADefinition());
do {
    auto v355 = e.ProtocolTokens();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
do {
    auto v356 = e.Protocols();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
do {
    auto v355 = e.AllReferencedProtocols();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
  b.setVal79(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal71(es.EntityId(e.CategoryListRaw()));
  b.setVal72(es.EntityId(e.Definition()));
  b.setVal73(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal83(es.EntityId(e.Implementation()));
  auto v78 = e.ObjCRuntimeNameAsString();
  std::string s78(v78.data(), v78.size());
  b.setVal78(s78);
  b.setVal86(es.EntityId(e.SuperClass()));
  b.setVal88(es.EntityId(e.SuperClassToken()));
  b.setVal80(e.HasDefinition());
  b.setVal81(e.HasDesignatedInitializers());
  b.setVal85(e.IsArcWeakrefUnavailable());
  b.setVal87(e.IsImplicitInterfaceDeclaration());
  b.setVal91(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal89(e.IsThisDeclarationADefinition());
do {
    auto v356 = e.InstanceVariables();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
do {
    auto v357 = e.KnownCategories();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
    }
  } while (false);
do {
    auto v358 = e.KnownExtensions();
    auto sv358 = b.initVal358(static_cast<unsigned>(v358.size()));
    auto i358 = 0u;
    for (const auto &e358 : v358) {
      sv358.set(i358, es.EntityId(e358));
      ++i358;
    }
  } while (false);
do {
    auto v359 = e.ProtocolTokens();
    auto sv359 = b.initVal359(static_cast<unsigned>(v359.size()));
    auto i359 = 0u;
    for (const auto &e359 : v359) {
      sv359.set(i359, es.EntityId(e359));
      ++i359;
    }
  } while (false);
do {
    auto v360 = e.Protocols();
    auto sv360 = b.initVal360(static_cast<unsigned>(v360.size()));
    auto i360 = 0u;
    for (const auto &e360 : v360) {
      sv360.set(i360, es.EntityId(e360));
      ++i360;
    }
  } while (false);
do {
    auto v361 = e.VisibleCategories();
    auto sv361 = b.initVal361(static_cast<unsigned>(v361.size()));
    auto i361 = 0u;
    for (const auto &e361 : v361) {
      sv361.set(i361, es.EntityId(e361));
      ++i361;
    }
  } while (false);
do {
    auto v362 = e.VisibleExtensions();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal71(es.EntityId(e.ClassInterface()));
do {
    auto v355 = e.PropertyImplementations();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal72(es.EntityId(e.CategoryDeclaration()));
  b.setVal73(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal72(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal73(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v78 = e.ObjCRuntimeNameAsString();
  std::string s78(v78.data(), v78.size());
  b.setVal78(s78);
  b.setVal83(es.EntityId(e.SuperClass()));
  b.setVal86(es.EntityId(e.SuperClassToken()));
  b.setVal79(e.HasDestructors());
  b.setVal80(e.HasNonZeroConstructors());
do {
    auto v356 = e.InstanceVariables();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal61(es.EntityId(e.ClassInterface()));
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
  b.setVal61(es.EntityId(e.AliasToken()));
  b.setVal62(es.EntityId(e.AliasedNamespace()));
  b.setVal70(es.EntityId(e.NamespaceToken()));
  b.setVal71(es.EntityId(e.TargetNameToken()));
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
do {
    auto v55 = e.ChildrenExpression();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  b.setVal53(es.EntityId(e.ExtendingDeclaration()));
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal61(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
do {
    auto v55 = e.IdentifierTokens();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
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
  auto v53 = e.FriendDeclaration();
  if (v53) {
    if (auto id53 = es.EntityId(v53.value())) {
      b.setVal53(id53);
      b.setVal54(true);
    } else {
      b.setVal54(false);
    }
  } else {
    b.setVal54(false);
  }
  b.setVal61(es.EntityId(e.FriendToken()));
  b.setVal57(e.IsUnsupportedFriend());
do {
    auto v84 = e.FriendTypeTemplateParameterLists();
    auto sv84 = b.initVal84(static_cast<unsigned>(v84.size()));
    auto i84 = 0u;
    for (const auto &e84 : v84) {
      auto o84 = es.next_pseudo_entity_offset++;
      sv84.set(i84, o84);
      SerializeTemplateParameterList(es, es.pseudo_builder[o84], e84);
      ++i84;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal53(es.EntityId(e.AssemblyToken()));
  b.setVal61(es.EntityId(e.AssemblyString()));
  b.setVal62(es.EntityId(e.RParenToken()));
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
  b.setVal61(es.EntityId(e.RBraceToken()));
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
