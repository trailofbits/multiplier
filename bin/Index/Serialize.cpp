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
  decl_builder = builder.initDeclarations(code.num_decl_entities);
  stmt_builder = builder.initStatements(code.num_stmt_entities);
  pseudo_builder = builder.initOthers(code.num_pseudo_entities);
  for (const pasta::Decl &decl : code.decls) {
    this->DeclVisitor::Accept(decl);
  }
  this->SerializeTypes(builder);
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
  auto v7 = e.AsType();
  if (v7) {
    if (auto id7 = es.EntityId(v7.value())) {
      b.setVal7(id7);
      b.setVal17(true);
    } else {
      b.setVal17(false);
    }
  } else {
    b.setVal17(false);
  }
  auto v8 = e.ParameterTypeForDeclaration();
  if (v8) {
    if (auto id8 = es.EntityId(v8.value())) {
      b.setVal8(id8);
      b.setVal18(true);
    } else {
      b.setVal18(false);
    }
  } else {
    b.setVal18(false);
  }
  auto v9 = e.NullPointerType();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal19(true);
    } else {
      b.setVal19(false);
    }
  } else {
    b.setVal19(false);
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
  b.setVal20(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal10(es.EntityId(e.BaseType()));
}

void SerializeType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::Type &e) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(e.IsQualified());
  b.setVal1(es.EntityId(e.UnqualifiedType()));
  b.setVal2(e.AcceptsObjCTypeParameters());
  b.setVal3(e.CanDecayToPointerType());
  b.setVal4(e.CanHaveNullability());
  b.setVal5(e.ContainsErrors());
  b.setVal6(e.ContainsUnexpandedParameterPack());
  auto v7 = e.ArrayElementTypeNoTypeQualified();
  if (v7) {
    if (auto id7 = es.EntityId(v7.value())) {
      b.setVal7(id7);
      b.setVal8(true);
    } else {
      b.setVal8(false);
    }
  } else {
    b.setVal8(false);
  }
  auto v9 = e.AsCXXRecordDeclaration();
  if (v9) {
    if (auto id9 = es.EntityId(v9.value())) {
      b.setVal9(id9);
      b.setVal10(true);
    } else {
      b.setVal10(false);
    }
  } else {
    b.setVal10(false);
  }
  auto v11 = e.AsComplexIntegerType();
  if (v11) {
    if (auto id11 = es.EntityId(v11.value())) {
      b.setVal11(id11);
      b.setVal12(true);
    } else {
      b.setVal12(false);
    }
  } else {
    b.setVal12(false);
  }
  auto v13 = e.AsObjCInterfacePointerType();
  if (v13) {
    if (auto id13 = es.EntityId(v13.value())) {
      b.setVal13(id13);
      b.setVal14(true);
    } else {
      b.setVal14(false);
    }
  } else {
    b.setVal14(false);
  }
  auto v15 = e.AsObjCInterfaceType();
  if (v15) {
    if (auto id15 = es.EntityId(v15.value())) {
      b.setVal15(id15);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  auto v17 = e.AsObjCQualifiedClassType();
  if (v17) {
    if (auto id17 = es.EntityId(v17.value())) {
      b.setVal17(id17);
      b.setVal18(true);
    } else {
      b.setVal18(false);
    }
  } else {
    b.setVal18(false);
  }
  auto v19 = e.AsObjCQualifiedIdType();
  if (v19) {
    if (auto id19 = es.EntityId(v19.value())) {
      b.setVal19(id19);
      b.setVal20(true);
    } else {
      b.setVal20(false);
    }
  } else {
    b.setVal20(false);
  }
  auto v21 = e.AsObjCQualifiedInterfaceType();
  if (v21) {
    if (auto id21 = es.EntityId(v21.value())) {
      b.setVal21(id21);
      b.setVal22(true);
    } else {
      b.setVal22(false);
    }
  } else {
    b.setVal22(false);
  }
  auto v23 = e.AsPlaceholderType();
  if (v23) {
    if (auto id23 = es.EntityId(v23.value())) {
      b.setVal23(id23);
      b.setVal24(true);
    } else {
      b.setVal24(false);
    }
  } else {
    b.setVal24(false);
  }
  auto v25 = e.AsRecordDeclaration();
  if (v25) {
    if (auto id25 = es.EntityId(v25.value())) {
      b.setVal25(id25);
      b.setVal26(true);
    } else {
      b.setVal26(false);
    }
  } else {
    b.setVal26(false);
  }
  auto v27 = e.AsStructureType();
  if (v27) {
    if (auto id27 = es.EntityId(v27.value())) {
      b.setVal27(id27);
      b.setVal28(true);
    } else {
      b.setVal28(false);
    }
  } else {
    b.setVal28(false);
  }
  auto v29 = e.AsTagDeclaration();
  if (v29) {
    if (auto id29 = es.EntityId(v29.value())) {
      b.setVal29(id29);
      b.setVal30(true);
    } else {
      b.setVal30(false);
    }
  } else {
    b.setVal30(false);
  }
  auto v31 = e.AsUnionType();
  if (v31) {
    if (auto id31 = es.EntityId(v31.value())) {
      b.setVal31(id31);
      b.setVal32(true);
    } else {
      b.setVal32(false);
    }
  } else {
    b.setVal32(false);
  }
  b.setVal33(es.EntityId(e.CanonicalTypeInternal()));
  auto v34 = e.ContainedAutoType();
  if (v34) {
    if (auto id34 = es.EntityId(v34.value())) {
      b.setVal34(id34);
      b.setVal35(true);
    } else {
      b.setVal35(false);
    }
  } else {
    b.setVal35(false);
  }
  auto v36 = e.ContainedDeducedType();
  if (v36) {
    if (auto id36 = es.EntityId(v36.value())) {
      b.setVal36(id36);
      b.setVal37(true);
    } else {
      b.setVal37(false);
    }
  } else {
    b.setVal37(false);
  }
  b.setVal38(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  b.setVal39(es.EntityId(e.LocallyUnqualifiedSingleStepDesugaredType()));
  auto v40 = e.Nullability();
  if (v40) {
    b.setVal40(static_cast<unsigned char>(v40.value()));
    b.setVal41(true);
  } else {
    b.setVal41(false);
  }
  auto v42 = e.PointeeCXXRecordDeclaration();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal43(true);
    } else {
      b.setVal43(false);
    }
  } else {
    b.setVal43(false);
  }
  auto v44 = e.PointeeOrArrayElementType();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal45(true);
    } else {
      b.setVal45(false);
    }
  } else {
    b.setVal45(false);
  }
  auto v46 = e.PointeeType();
  if (v46) {
    if (auto id46 = es.EntityId(v46.value())) {
      b.setVal46(id46);
      b.setVal47(true);
    } else {
      b.setVal47(false);
    }
  } else {
    b.setVal47(false);
  }
  auto v48 = e.ScalarTypeKind();
  if (v48) {
    b.setVal48(static_cast<unsigned char>(v48.value()));
    b.setVal49(true);
  } else {
    b.setVal49(false);
  }
  auto v50 = e.SveElementType();
  if (v50) {
    if (auto id50 = es.EntityId(v50.value())) {
      b.setVal50(id50);
      b.setVal51(true);
    } else {
      b.setVal51(false);
    }
  } else {
    b.setVal51(false);
  }
  b.setVal52(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal53(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal54(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal55(e.HasAutoForTrailingReturnType());
  b.setVal56(e.HasFloatingRepresentation());
  b.setVal57(e.HasIntegerRepresentation());
  b.setVal58(e.HasObjCPointerRepresentation());
  b.setVal59(e.HasPointerRepresentation());
  b.setVal60(e.HasSignedIntegerRepresentation());
  b.setVal61(e.HasSizedVLAType());
  b.setVal62(e.HasUnnamedOrLocalType());
  b.setVal63(e.HasUnsignedIntegerRepresentation());
  b.setVal64(e.IsAggregateType());
  b.setVal65(e.IsAlignValueT());
  b.setVal66(e.IsAnyCharacterType());
  b.setVal67(e.IsAnyComplexType());
  b.setVal68(e.IsAnyPointerType());
  b.setVal69(e.IsArithmeticType());
  b.setVal70(e.IsArrayType());
  b.setVal71(e.IsAtomicType());
  b.setVal72(e.IsBFloat16Type());
  b.setVal73(e.IsBlockCompatibleObjCPointerType());
  b.setVal74(e.IsBlockPointerType());
  b.setVal75(e.IsBooleanType());
  b.setVal76(e.IsBuiltinType());
  b.setVal77(e.IsCARCBridgableType());
  b.setVal78(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal79(e.IsCUDADeviceBuiltinTextureType());
  b.setVal80(e.IsCanonicalUnqualified());
  b.setVal81(e.IsChar16Type());
  b.setVal82(e.IsChar32Type());
  b.setVal83(e.IsChar8Type());
  b.setVal84(e.IsCharacterType());
  b.setVal85(e.IsClassType());
  b.setVal86(e.IsClkEventT());
  b.setVal87(e.IsComplexIntegerType());
  b.setVal88(e.IsComplexType());
  b.setVal89(e.IsCompoundType());
  b.setVal90(e.IsConstantArrayType());
  b.setVal91(e.IsConstantMatrixType());
  auto v92 = e.IsConstantSizeType();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.IsDecltypeType());
  b.setVal95(e.IsDependentAddressSpaceType());
  b.setVal96(e.IsDependentSizedArrayType());
  b.setVal97(e.IsDependentType());
  b.setVal98(e.IsElaboratedTypeSpecifier());
  b.setVal99(e.IsEnumeralType());
  b.setVal100(e.IsEventT());
  b.setVal101(e.IsExtIntType());
  b.setVal102(e.IsExtVectorType());
  b.setVal103(e.IsFixedPointOrIntegerType());
  b.setVal104(e.IsFixedPointType());
  b.setVal105(e.IsFloat128Type());
  b.setVal106(e.IsFloat16Type());
  b.setVal107(e.IsFloatingType());
  b.setVal108(e.IsFromAST());
  b.setVal109(e.IsFunctionNoProtoType());
  b.setVal110(e.IsFunctionPointerType());
  b.setVal111(e.IsFunctionProtoType());
  b.setVal112(e.IsFunctionReferenceType());
  b.setVal113(e.IsFunctionType());
  b.setVal114(e.IsFundamentalType());
  b.setVal115(e.IsHalfType());
  b.setVal116(e.IsImageType());
  b.setVal117(e.IsIncompleteArrayType());
  b.setVal118(e.IsIncompleteOrObjectType());
  b.setVal119(e.IsIncompleteType());
  b.setVal120(e.IsInstantiationDependentType());
  b.setVal121(e.IsIntegerType());
  b.setVal122(e.IsIntegralOrEnumerationType());
  b.setVal123(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal124(e.IsIntegralType());
  b.setVal125(e.IsInterfaceType());
  b.setVal126(e.IsLValueReferenceType());
  b.setVal127(e.IsLinkageValid());
  auto v128 = e.IsLiteralType();
  if (v128) {
    b.setVal128(static_cast<bool>(v128.value()));
    b.setVal129(true);
  } else {
    b.setVal129(false);
  }
  b.setVal130(e.IsMatrixType());
  b.setVal131(e.IsMemberDataPointerType());
  b.setVal132(e.IsMemberFunctionPointerType());
  b.setVal133(e.IsMemberPointerType());
  b.setVal134(e.IsNonOverloadPlaceholderType());
  b.setVal135(e.IsNothrowT());
  b.setVal136(e.IsNullPointerType());
  b.setVal137(e.IsOCLExtOpaqueType());
  b.setVal138(e.IsOCLImage1dArrayROType());
  b.setVal139(e.IsOCLImage1dArrayRWType());
  b.setVal140(e.IsOCLImage1dArrayWOType());
  b.setVal141(e.IsOCLImage1dBufferROType());
  b.setVal142(e.IsOCLImage1dBufferRWType());
  b.setVal143(e.IsOCLImage1dBufferWOType());
  b.setVal144(e.IsOCLImage1dROType());
  b.setVal145(e.IsOCLImage1dRWType());
  b.setVal146(e.IsOCLImage1dWOType());
  b.setVal147(e.IsOCLImage2dArrayDepthROType());
  b.setVal148(e.IsOCLImage2dArrayDepthRWType());
  b.setVal149(e.IsOCLImage2dArrayDepthWOType());
  b.setVal150(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal151(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal152(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal153(e.IsOCLImage2dArrayMSAAROType());
  b.setVal154(e.IsOCLImage2dArrayMSAARWType());
  b.setVal155(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal156(e.IsOCLImage2dArrayROType());
  b.setVal157(e.IsOCLImage2dArrayRWType());
  b.setVal158(e.IsOCLImage2dArrayWOType());
  b.setVal159(e.IsOCLImage2dDepthROType());
  b.setVal160(e.IsOCLImage2dDepthRWType());
  b.setVal161(e.IsOCLImage2dDepthWOType());
  b.setVal162(e.IsOCLImage2dMSAADepthROType());
  b.setVal163(e.IsOCLImage2dMSAADepthRWType());
  b.setVal164(e.IsOCLImage2dMSAADepthWOType());
  b.setVal165(e.IsOCLImage2dMSAAROType());
  b.setVal166(e.IsOCLImage2dMSAARWType());
  b.setVal167(e.IsOCLImage2dMSAAWOType());
  b.setVal168(e.IsOCLImage2dROType());
  b.setVal169(e.IsOCLImage2dRWType());
  b.setVal170(e.IsOCLImage2dWOType());
  b.setVal171(e.IsOCLImage3dROType());
  b.setVal172(e.IsOCLImage3dRWType());
  b.setVal173(e.IsOCLImage3dWOType());
  b.setVal174(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal175(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal176(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal177(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal178(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal179(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal180(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal181(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal182(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal183(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal184(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal185(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal186(e.IsOCLIntelSubgroupAVCType());
  b.setVal187(e.IsObjCARCBridgableType());
  auto v188 = e.IsObjCARCImplicitlyUnretainedType();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  b.setVal190(e.IsObjCBoxableRecordType());
  b.setVal191(e.IsObjCBuiltinType());
  b.setVal192(e.IsObjCClassOrClassKindOfType());
  b.setVal193(e.IsObjCClassType());
  b.setVal194(e.IsObjCIdType());
  b.setVal195(e.IsObjCIndependentClassType());
  b.setVal196(e.IsObjCIndirectLifetimeType());
  b.setVal197(e.IsObjCInertUnsafeUnretainedType());
  b.setVal198(e.IsObjCLifetimeType());
  b.setVal199(e.IsObjCNSObjectType());
  b.setVal200(e.IsObjCObjectOrInterfaceType());
  b.setVal201(e.IsObjCObjectPointerType());
  b.setVal202(e.IsObjCObjectType());
  b.setVal203(e.IsObjCQualifiedClassType());
  b.setVal204(e.IsObjCQualifiedIdType());
  b.setVal205(e.IsObjCQualifiedInterfaceType());
  b.setVal206(e.IsObjCRetainableType());
  b.setVal207(e.IsObjCSelType());
  b.setVal208(e.IsObjectPointerType());
  b.setVal209(e.IsObjectType());
  b.setVal210(e.IsOpenCLSpecificType());
  b.setVal211(e.IsOverloadableType());
  b.setVal212(e.IsPipeType());
  b.setVal213(e.IsPlaceholderType());
  b.setVal214(e.IsPointerType());
  b.setVal215(e.IsPromotableIntegerType());
  b.setVal216(e.IsQueueT());
  b.setVal217(e.IsRValueReferenceType());
  b.setVal218(e.IsRealFloatingType());
  b.setVal219(e.IsRealType());
  b.setVal220(e.IsRecordType());
  b.setVal221(e.IsReferenceType());
  b.setVal222(e.IsReserveIDT());
  b.setVal223(e.IsSamplerT());
  b.setVal224(e.IsSaturatedFixedPointType());
  b.setVal225(e.IsScalarType());
  b.setVal226(e.IsScopedEnumeralType());
  b.setVal227(e.IsSignedFixedPointType());
  b.setVal228(e.IsSignedIntegerOrEnumerationType());
  b.setVal229(e.IsSignedIntegerType());
  b.setVal230(e.IsSizelessBuiltinType());
  b.setVal231(e.IsSizelessType());
  b.setVal232(e.IsSpecifierType());
  auto v233 = e.IsStandardLayoutType();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  b.setVal235(e.IsStdByteType());
  b.setVal236(e.IsStructuralType());
  b.setVal237(e.IsStructureOrClassType());
  b.setVal238(e.IsStructureType());
  b.setVal239(e.IsTemplateTypeParmType());
  b.setVal240(e.IsTypedefNameType());
  b.setVal241(e.IsUndeducedAutoType());
  b.setVal242(e.IsUndeducedType());
  b.setVal243(e.IsUnionType());
  b.setVal244(e.IsUnsaturatedFixedPointType());
  b.setVal245(e.IsUnscopedEnumerationType());
  b.setVal246(e.IsUnsignedFixedPointType());
  b.setVal247(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal248(e.IsUnsignedIntegerType());
  b.setVal249(e.IsVLSTBuiltinType());
  b.setVal250(e.IsVariableArrayType());
  b.setVal251(e.IsVariablyModifiedType());
  b.setVal252(e.IsVectorType());
  b.setVal253(e.IsVisibilityExplicit());
  b.setVal254(e.IsVoidPointerType());
  b.setVal255(e.IsVoidType());
  b.setVal256(e.IsWideCharacterType());
  b.setVal257(es.EntityId(e.IgnoreParentheses()));
  b.setVal258(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal259(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal260(es.EntityId(e.CanonicalType()));
  b.setVal261(es.EntityId(e.DesugaredType()));
  b.setVal262(es.EntityId(e.LocalUnqualifiedType()));
  b.setVal263(es.EntityId(e.NonLValueExpressionType()));
  b.setVal264(es.EntityId(e.NonPackExpansionType()));
  b.setVal265(es.EntityId(e.NonReferenceType()));
  b.setVal266(es.EntityId(e.SingleStepDesugaredType()));
  b.setVal267(e.HasAddressSpace());
  b.setVal268(e.HasLocalNonFastQualifiers());
  b.setVal269(e.HasLocalQualifiers());
  b.setVal270(e.HasNonTrivialObjCLifetime());
  b.setVal271(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal272(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal273(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal274(e.HasQualifiers());
  b.setVal275(e.HasStrongOrWeakObjCLifetime());
  b.setVal276(e.IsCForbiddenLValueType());
  b.setVal277(e.IsCXX11PODType());
  b.setVal278(e.IsCXX98PODType());
  b.setVal279(e.IsCanonical());
  b.setVal280(e.IsCanonicalAsParameter());
  b.setVal281(e.IsConstQualified());
  b.setVal282(e.IsConstant());
  b.setVal283(static_cast<unsigned char>(mx::FromPasta(e.IsDestructedType())));
  b.setVal284(e.IsLocalConstQualified());
  b.setVal285(e.IsLocalRestrictQualified());
  b.setVal286(e.IsLocalVolatileQualified());
  b.setVal287(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveCopy())));
  b.setVal288(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDefaultInitialize())));
  b.setVal289(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDestructiveMove())));
  b.setVal290(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal291(e.IsNull());
  b.setVal292(e.IsObjCGCStrong());
  b.setVal293(e.IsObjCGCWeak());
  b.setVal294(e.IsPODType());
  b.setVal295(e.IsRestrictQualified());
  b.setVal296(e.IsTrivialType());
  b.setVal297(e.IsTriviallyCopyableType());
  b.setVal298(e.IsVolatileQualified());
  b.setVal299(e.MayBeDynamicClass());
  b.setVal300(e.MayBeNotDynamicClass());
  b.setVal301(es.EntityId(e.StripObjCKindOfType()));
  b.setVal302(es.EntityId(e.WithConst()));
  b.setVal303(es.EntityId(e.WithRestrict()));
  b.setVal304(es.EntityId(e.WithVolatile()));
  b.setVal305(es.EntityId(e.WithoutLocalFastQualifiers()));
}

void SerializeTemplateTypeParmType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsParameterPack());
  b.setVal309(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.AliasedType()));
  b.setVal308(e.IsCurrentInstantiation());
  b.setVal309(e.IsSugared());
  b.setVal310(e.IsTypeAlias());
  do {
    auto v311 = e.TemplateArguments();
    auto sv311 = b.initVal311(static_cast<unsigned>(v311.size()));
    auto i311 = 0u;
    for (const auto &e311 : v311) {
      auto o311 = es.next_pseudo_entity_offset++;
      sv311.set(i311, o311);
      SerializeTemplateArgument(es, es.pseudo_builder[o311], e311);
      ++i311;
    }
  } while (false);
}

void SerializeTagType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal308(e.IsBeingDefined());
}

void SerializeRecordType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal309(e.HasConstFields());
  b.setVal310(e.IsSugared());
}

void SerializeEnumType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal309(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ReplacedParameter()));
  b.setVal312(es.EntityId(e.ReplacementType()));
  b.setVal308(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ReplacedParameter()));
  b.setVal308(e.IsSugared());
}

void SerializeReferenceType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal308(e.IsInnerReference());
  b.setVal309(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializeLValueReferenceType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializePointerType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializePipeType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsReadOnly());
  b.setVal309(e.IsSugared());
}

void SerializeParenType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.InnerType()));
  b.setVal308(e.IsSugared());
}

void SerializePackExpansionType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  auto v313 = e.NumExpansions();
  if (v313) {
    b.setVal313(static_cast<unsigned>(v313.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  b.setVal307(es.EntityId(e.Pattern()));
  b.setVal309(e.IsSugared());
}

void SerializeObjCTypeParamType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeObjCObjectType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.BaseType()));
  b.setVal312(es.EntityId(e.Interface()));
  auto v314 = e.SuperClassType();
  if (v314) {
    if (auto id314 = es.EntityId(v314.value())) {
      b.setVal314(id314);
      b.setVal308(true);
    } else {
      b.setVal308(false);
    }
  } else {
    b.setVal308(false);
  }
  do {
    auto v315 = e.TypeArguments();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  do {
    auto v316 = e.TypeArgumentsAsWritten();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  b.setVal309(e.IsKindOfType());
  b.setVal310(e.IsKindOfTypeAsWritten());
  b.setVal317(e.IsObjCClass());
  b.setVal318(e.IsObjCId());
  b.setVal319(e.IsObjCQualifiedClass());
  b.setVal320(e.IsObjCQualifiedId());
  b.setVal321(e.IsObjCUnqualifiedClass());
  b.setVal322(e.IsObjCUnqualifiedId());
  b.setVal323(e.IsObjCUnqualifiedIdOrClass());
  b.setVal324(e.IsSpecialized());
  b.setVal325(e.IsSpecializedAsWritten());
  b.setVal326(e.IsSugared());
  b.setVal327(e.IsUnspecialized());
  b.setVal328(e.IsUnspecializedAsWritten());
  b.setVal329(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
}

void SerializeObjCInterfaceType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal330(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.InterfaceDeclaration()));
  b.setVal312(es.EntityId(e.InterfaceType()));
  b.setVal314(es.EntityId(e.ObjectType()));
  b.setVal329(es.EntityId(e.SuperClassType()));
  do {
    auto v315 = e.TypeArguments();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  do {
    auto v316 = e.TypeArgumentsAsWritten();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  b.setVal308(e.IsKindOfType());
  b.setVal309(e.IsObjCIdOrClassType());
  b.setVal310(e.IsSpecialized());
  b.setVal317(e.IsSpecializedAsWritten());
  b.setVal318(e.IsSugared());
  b.setVal319(e.IsUnspecialized());
  b.setVal320(e.IsUnspecializedAsWritten());
  do {
    auto v331 = e.Qualifieds();
    auto sv331 = b.initVal331(static_cast<unsigned>(v331.size()));
    auto i331 = 0u;
    for (const auto &e331 : v331) {
      sv331.set(i331, es.EntityId(e331));
      ++i331;
    }
  } while (false);
  b.setVal330(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
  do {
    auto v332 = e.Protocols();
    auto sv332 = b.initVal332(static_cast<unsigned>(v332.size()));
    auto i332 = 0u;
    for (const auto &e332 : v332) {
      sv332.set(i332, es.EntityId(e332));
      ++i332;
    }
  } while (false);
}

void SerializeMemberPointerType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Class()));
  b.setVal312(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal308(e.IsMemberDataPointer());
  b.setVal309(e.IsMemberFunctionPointer());
  b.setVal310(e.IsSugared());
}

void SerializeMatrixType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  b.setVal312(es.EntityId(e.AttributeToken()));
  b.setVal314(es.EntityId(e.ColumnExpression()));
  b.setVal329(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
}

void SerializeMacroQualifiedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ModifiedType()));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeInjectedClassNameType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal312(es.EntityId(e.InjectedSpecializationType()));
  b.setVal314(es.EntityId(e.InjectedTST()));
  b.setVal308(e.IsSugared());
}

void SerializeFunctionType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal306(es.EntityId(e.CallResultType()));
  b.setVal308(e.CmseNSCallAttribute());
  b.setVal309(e.HasRegParm());
  b.setVal310(e.NoReturnAttribute());
  b.setVal307(es.EntityId(e.ReturnType()));
  b.setVal317(e.IsConst());
  b.setVal318(e.IsRestrict());
  b.setVal319(e.IsVolatile());
}

void SerializeFunctionProtoType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal334(static_cast<unsigned char>(mx::FromPasta(e.CanThrow())));
  b.setVal312(es.EntityId(e.Desugar()));
  do {
    auto v315 = e.Exceptions();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal314(es.EntityId(e.EllipsisToken()));
  auto v329 = e.ExceptionSpecDeclaration();
  if (v329) {
    if (auto id329 = es.EntityId(v329.value())) {
      b.setVal329(id329);
      b.setVal320(true);
    } else {
      b.setVal320(false);
    }
  } else {
    b.setVal320(false);
  }
  auto v330 = e.ExceptionSpecTemplate();
  if (v330) {
    if (auto id330 = es.EntityId(v330.value())) {
      b.setVal330(id330);
      b.setVal321(true);
    } else {
      b.setVal321(false);
    }
  } else {
    b.setVal321(false);
  }
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v336 = e.NoexceptExpression();
  if (v336) {
    if (auto id336 = es.EntityId(v336.value())) {
      b.setVal336(id336);
      b.setVal322(true);
    } else {
      b.setVal322(false);
    }
  } else {
    b.setVal322(false);
  }
  do {
    auto v316 = e.ParameterTypes();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal323(e.HasDependentExceptionSpec());
  b.setVal324(e.HasDynamicExceptionSpec());
  b.setVal325(e.HasExceptionSpec());
  b.setVal326(e.HasExtParameterInfos());
  b.setVal327(e.HasInstantiationDependentExceptionSpec());
  b.setVal328(e.HasNoexceptExceptionSpec());
  b.setVal338(e.HasTrailingReturn());
  b.setVal339(e.IsNothrow());
  b.setVal340(e.IsSugared());
  b.setVal341(e.IsTemplateVariadic());
  b.setVal342(e.IsVariadic());
  do {
    auto v331 = e.ExceptionTypes();
    auto sv331 = b.initVal331(static_cast<unsigned>(v331.size()));
    auto i331 = 0u;
    for (const auto &e331 : v331) {
      sv331.set(i331, es.EntityId(e331));
      ++i331;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal312(es.EntityId(e.Desugar()));
  b.setVal320(e.IsSugared());
}

void SerializeExtIntType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ExtIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSigned());
  b.setVal309(e.IsSugared());
  b.setVal310(e.IsUnsigned());
}

void SerializeDependentVectorType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.AttributeToken()));
  b.setVal312(es.EntityId(e.ElementType()));
  b.setVal314(es.EntityId(e.SizeExpression()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal308(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.AttributeToken()));
  b.setVal312(es.EntityId(e.ElementType()));
  b.setVal314(es.EntityId(e.SizeExpression()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentExtIntType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentExtIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.NumBitsExpression()));
  b.setVal308(e.IsSigned());
  b.setVal309(e.IsSugared());
  b.setVal310(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.AddrSpaceExpression()));
  b.setVal312(es.EntityId(e.AttributeToken()));
  b.setVal308(e.IsSugared());
}

void SerializeDeducedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ResolvedType()));
  b.setVal308(e.IsDeduced());
  b.setVal309(e.IsSugared());
}

void SerializeDeducedTemplateSpecializationType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DeducedTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e);
}

void SerializeAutoType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::AutoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e);
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v311 = e.TypeConstraintArguments();
    auto sv311 = b.initVal311(static_cast<unsigned>(v311.size()));
    auto i311 = 0u;
    for (const auto &e311 : v311) {
      auto o311 = es.next_pseudo_entity_offset++;
      sv311.set(i311, o311);
      SerializeTemplateArgument(es, es.pseudo_builder[o311], e311);
      ++i311;
    }
  } while (false);
  b.setVal312(es.EntityId(e.TypeConstraintConcept()));
  b.setVal310(e.IsConstrained());
  b.setVal317(e.IsDecltypeAuto());
}

void SerializeDecltypeType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingExpression()));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeComplexType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsSugared());
}

void SerializeBuiltinType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsFloatingPoint());
  b.setVal309(e.IsInteger());
  b.setVal310(e.IsSignedInteger());
  b.setVal317(e.IsSugared());
  b.setVal318(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeAttributedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal343(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal307(es.EntityId(e.EquivalentType()));
  auto v333 = e.ImmediateNullability();
  if (v333) {
    b.setVal333(static_cast<unsigned char>(v333.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  b.setVal312(es.EntityId(e.ModifiedType()));
  b.setVal309(e.IsCallingConv());
  b.setVal310(e.IsMSTypeSpec());
  b.setVal317(e.IsQualifier());
  b.setVal318(e.IsSugared());
}

void SerializeAtomicType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ValueType()));
  b.setVal308(e.IsSugared());
}

void SerializeArrayType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  if (auto r312 = e.BracketsRange(); auto rs312 = r312.Size()) {
    b.setVal312(es.EntityId(r312[0]));
    b.setVal314(es.EntityId(r312[rs312 - 1u]));
  } else {
    b.setVal312(0);
    b.setVal314(0);
  }
  b.setVal329(es.EntityId(e.LBracketToken()));
  b.setVal330(es.EntityId(e.RBracketToken()));
  b.setVal336(es.EntityId(e.SizeExpression()));
  b.setVal308(e.IsSugared());
}

void SerializeIncompleteArrayType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  if (auto r312 = e.BracketsRange(); auto rs312 = r312.Size()) {
    b.setVal312(es.EntityId(r312[0]));
    b.setVal314(es.EntityId(r312[rs312 - 1u]));
  } else {
    b.setVal312(0);
    b.setVal314(0);
  }
  b.setVal329(es.EntityId(e.LBracketToken()));
  b.setVal330(es.EntityId(e.RBracketToken()));
  b.setVal336(es.EntityId(e.SizeExpression()));
  b.setVal308(e.IsSugared());
}

void SerializeConstantArrayType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  auto v312 = e.SizeExpression();
  if (v312) {
    if (auto id312 = es.EntityId(v312.value())) {
      b.setVal312(id312);
      b.setVal308(true);
    } else {
      b.setVal308(false);
    }
  } else {
    b.setVal308(false);
  }
  b.setVal309(e.IsSugared());
}

void SerializeAdjustedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ResolvedType()));
  b.setVal312(es.EntityId(e.OriginalType()));
  b.setVal308(e.IsSugared());
}

void SerializeDecayedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DecayedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(es, b, e);
}

void SerializeTypeWithKeyword(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.NamedType()));
  auto v312 = e.OwnedTagDeclaration();
  if (v312) {
    if (auto id312 = es.EntityId(v312.value())) {
      b.setVal312(id312);
      b.setVal308(true);
    } else {
      b.setVal308(false);
    }
  } else {
    b.setVal308(false);
  }
  b.setVal309(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
  do {
    auto v311 = e.TemplateArguments();
    auto sv311 = b.initVal311(static_cast<unsigned>(v311.size()));
    auto i311 = 0u;
    for (const auto &e311 : v311) {
      auto o311 = es.next_pseudo_entity_offset++;
      sv311.set(i311, o311);
      SerializeTemplateArgument(es, es.pseudo_builder[o311], e311);
      ++i311;
    }
  } while (false);
}

void SerializeDependentNameType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeVectorType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal308(e.IsSugared());
}

void SerializeExtVectorType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(es, b, e);
}

void SerializeUnresolvedUsingType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeUnaryTransformType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.BaseType()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeTypedefType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeTypeOfType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeTypeOfExprType(EntitySerializer &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingExpression()));
  b.setVal308(e.IsSugared());
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
  auto v10 = e.ConstantTarget();
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
  b.setVal11(es.EntityId(e.CaughtType()));
  auto v12 = e.ExceptionDeclaration();
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
  b.setVal14(es.EntityId(e.HandlerBlock()));
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
  b.setVal37(es.EntityId(e.Type()));
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
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r38 = e.DesignatorsSourceRange(); auto rs38 = r38.Size()) {
    b.setVal38(es.EntityId(r38[0]));
    b.setVal39(es.EntityId(r38[rs38 - 1u]));
  } else {
    b.setVal38(0);
    b.setVal39(0);
  }
  b.setVal40(es.EntityId(e.EqualOrColonToken()));
  b.setVal41(es.EntityId(e.Initializer()));
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
  b.setVal38(es.EntityId(e.LAngleToken()));
  b.setVal39(es.EntityId(e.RAngleToken()));
  b.setVal40(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.KeywordToken()));
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal40(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Declaration()));
  b.setVal39(es.EntityId(e.FoundDeclaration()));
  b.setVal40(es.EntityId(e.LAngleToken()));
  b.setVal41(es.EntityId(e.RAngleToken()));
  b.setVal42(es.EntityId(e.TemplateKeywordToken()));
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
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.KeywordToken()));
  b.setVal40(es.EntityId(e.OpaqueValue()));
  b.setVal41(es.EntityId(e.ReadyExpression()));
  b.setVal42(es.EntityId(e.ResumeExpression()));
  b.setVal43(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal44(es.EntityId(e.Operand()));
  b.setVal98(e.IsImplicit());
}

void SerializeCoyieldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal44(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SrcExpression()));
  b.setVal41(es.EntityId(e.TypeSourceInfo()));
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
  b.setVal38(es.EntityId(e.Initializer()));
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.TypeSourceInfo()));
  b.setVal98(e.IsFileScope());
}

void SerializeChooseExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.ChosenSubExpression()));
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal42(es.EntityId(e.RHS()));
  b.setVal43(es.EntityId(e.RParenToken()));
  b.setVal98(e.IsConditionDependent());
  b.setVal99(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v63 = e.CastKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v38 = e.ConversionFunction();
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
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.SubExpressionAsWritten()));
  auto v41 = e.TargetUnionField();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
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
  b.setVal42(es.EntityId(e.TypeAsWritten()));
  b.setVal43(es.EntityId(e.TypeInfoAsWritten()));
}

void SerializeCXXNamedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r44 = e.AngleBrackets(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  auto v68 = e.CastName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal46(es.EntityId(e.OperatorToken()));
  b.setVal47(es.EntityId(e.RParenToken()));
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
  b.setVal44(es.EntityId(e.LParenToken()));
  b.setVal45(es.EntityId(e.RParenToken()));
  b.setVal101(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal44(es.EntityId(e.LParenToken()));
  b.setVal45(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal44(es.EntityId(e.BridgeKeywordToken()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal45(es.EntityId(e.LParenToken()));
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
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.Callee()));
  auto v40 = e.CalleeDeclaration();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  auto v41 = e.DirectCallee();
  if (v41) {
    if (auto id41 = es.EntityId(v41.value())) {
      b.setVal41(id41);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal42(es.EntityId(e.RParenToken()));
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
  b.setVal43(es.EntityId(e.OperatorToken()));
  b.setVal109(e.IsAssignmentOperation());
  b.setVal110(e.IsComparisonOperation());
  b.setVal111(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.ImplicitObjectArgument()));
  auto v44 = e.MethodDeclaration();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  b.setVal45(es.EntityId(e.ObjectType()));
  b.setVal46(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.CookedLiteral()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal44(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
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
  b.setVal39(es.EntityId(e.GuidDeclaration()));
  b.setVal40(es.EntityId(e.TypeOperand()));
  b.setVal41(es.EntityId(e.TypeOperandSourceInfo()));
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
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.TypeAsWritten()));
  b.setVal41(es.EntityId(e.TypeSourceInfo()));
  b.setVal98(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
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
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
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
  auto v38 = e.SubExpression();
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
  b.setVal39(es.EntityId(e.ThrowToken()));
  b.setVal99(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.TypeSourceInfo()));
}

void SerializeCXXRewrittenBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal39(es.EntityId(e.OperatorToken()));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal41(es.EntityId(e.SemanticForm()));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColonColonToken()));
  b.setVal40(es.EntityId(e.DestroyedType()));
  b.setVal41(es.EntityId(e.DestroyedTypeInfo()));
  b.setVal42(es.EntityId(e.DestroyedTypeToken()));
  b.setVal43(es.EntityId(e.OperatorToken()));
  b.setVal44(es.EntityId(e.ScopeTypeInfo()));
  b.setVal45(es.EntityId(e.TildeToken()));
  b.setVal98(e.HasQualifier());
  b.setVal99(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal98(e.Value());
}

void SerializeCXXNewExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.AllocatedType()));
  b.setVal39(es.EntityId(e.AllocatedTypeSourceInfo()));
  auto v40 = e.ArraySize();
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
  auto v41 = e.ConstructExpression();
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
  if (auto r42 = e.DirectInitializerRange(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v44 = e.Initializer();
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
  b.setVal45(es.EntityId(e.OperatorDelete()));
  b.setVal46(es.EntityId(e.OperatorNew()));
  if (auto r47 = e.TypeIdParentheses(); auto rs47 = r47.Size()) {
    b.setVal47(es.EntityId(r47[0]));
    b.setVal48(es.EntityId(r47[rs47 - 1u]));
  } else {
    b.setVal47(0);
    b.setVal48(0);
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
  b.setVal38(es.EntityId(e.Constructor()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal99(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Callee()));
  b.setVal39(es.EntityId(e.EllipsisToken()));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal42(es.EntityId(e.LParenToken()));
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal43(es.EntityId(e.Pattern()));
  b.setVal44(es.EntityId(e.RHS()));
  b.setVal45(es.EntityId(e.RParenToken()));
  b.setVal99(e.IsLeftFold());
  b.setVal100(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.BaseType()));
  auto v40 = e.FirstQualifierFoundInScope();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal41(es.EntityId(e.LAngleToken()));
  b.setVal42(es.EntityId(e.MemberToken()));
  b.setVal43(es.EntityId(e.OperatorToken()));
  b.setVal44(es.EntityId(e.RAngleToken()));
  b.setVal45(es.EntityId(e.TemplateKeywordToken()));
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasTemplateKeyword());
  b.setVal101(e.IsArrow());
  b.setVal102(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal99(e.IsArrayForm());
  b.setVal100(e.IsArrayFormAsWritten());
  b.setVal101(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.Expression();
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
  b.setVal39(es.EntityId(e.Field()));
  b.setVal40(es.EntityId(e.UsedToken()));
}

void SerializeCXXDefaultArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.UsedToken()));
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
  b.setVal38(es.EntityId(e.Constructor()));
  b.setVal39(es.EntityId(e.Token()));
  if (auto r40 = e.ParenthesisOrBraceRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
  b.setVal98(e.HadMultipleCandidates());
  b.setVal99(e.IsElidable());
  b.setVal100(e.IsListInitialization());
  b.setVal101(e.IsStdInitializerListInitialization());
  b.setVal102(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
  b.setVal42(es.EntityId(e.TypeSourceInfo()));
}

void SerializeCXXBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BlockDeclaration()));
  b.setVal39(es.EntityId(e.Body()));
  b.setVal40(es.EntityId(e.CaretToken()));
  b.setVal41(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal39(es.EntityId(e.OperatorToken()));
  b.setVal40(es.EntityId(e.RHS()));
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
  b.setVal41(es.EntityId(e.ComputationLHSType()));
  b.setVal42(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal39(es.EntityId(e.Order()));
  auto v40 = e.OrderFail();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal98(true);
    } else {
      b.setVal98(false);
    }
  } else {
    b.setVal98(false);
  }
  b.setVal41(es.EntityId(e.Pointer()));
  b.setVal42(es.EntityId(e.RParenToken()));
  auto v43 = e.Scope();
  if (v43) {
    if (auto id43 = es.EntityId(v43.value())) {
      b.setVal43(id43);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  auto v44 = e.Value1();
  if (v44) {
    if (auto id44 = es.EntityId(v44.value())) {
      b.setVal44(id44);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  auto v45 = e.Value2();
  if (v45) {
    if (auto id45 = es.EntityId(v45.value())) {
      b.setVal45(id45);
      b.setVal101(true);
    } else {
      b.setVal101(false);
    }
  } else {
    b.setVal101(false);
  }
  b.setVal46(es.EntityId(e.ValueType()));
  auto v47 = e.Weak();
  if (v47) {
    if (auto id47 = es.EntityId(v47.value())) {
      b.setVal47(id47);
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
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DimensionExpression()));
  b.setVal39(es.EntityId(e.QueriedType()));
  b.setVal40(es.EntityId(e.QueriedTypeSourceInfo()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RBracketToken()));
  b.setVal42(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AmpAmpToken()));
  b.setVal39(es.EntityId(e.Label()));
  b.setVal40(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ColonToken()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.FalseExpression()));
  b.setVal41(es.EntityId(e.QuestionToken()));
  b.setVal42(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.LHS()));
  b.setVal44(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.Common()));
  b.setVal44(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.WrittenTypeInfo()));
  b.setVal98(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.CanOverflow());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.SubExpression()));
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
  auto v38 = e.ArgumentExpression();
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
  auto v39 = e.ArgumentType();
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
  auto v40 = e.ArgumentTypeInfo();
  if (v40) {
    if (auto id40 = es.EntityId(v40.value())) {
      b.setVal40(id40);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  b.setVal41(es.EntityId(e.OperatorToken()));
  b.setVal42(es.EntityId(e.RParenToken()));
  b.setVal43(es.EntityId(e.TypeOfArgument()));
  b.setVal101(e.IsArgumentType());
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
  do {
    auto v17 = e.Arguments();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ParameterPack()));
  b.setVal39(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.NameToken()));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
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
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v63 = e.BuiltinString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsIntType());
  b.setVal99(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.Pack()));
  auto v112 = e.PackLength();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.PackToken()));
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
  b.setVal41(es.EntityId(e.RParenToken()));
  b.setVal100(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal63(e.ComputeName());
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal41(es.EntityId(e.TypeSourceInfo()));
}

void SerializeRequiresExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Body()));
  do {
    auto v17 = e.LocalParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal39(es.EntityId(e.RBraceToken()));
  b.setVal40(es.EntityId(e.RequiresKWToken()));
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
  b.setVal38(es.EntityId(e.ResultExpression()));
  b.setVal39(es.EntityId(e.SyntacticForm()));
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
  b.setVal38(es.EntityId(e.FunctionName()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v63 = e.IdentifierKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal39(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
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
  b.setVal38(es.EntityId(e.LParen()));
  b.setVal39(es.EntityId(e.RParen()));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.EllipsisToken()));
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal39(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LAngleToken()));
  b.setVal39(es.EntityId(e.NameToken()));
  b.setVal40(es.EntityId(e.NamingClass()));
  b.setVal41(es.EntityId(e.RAngleToken()));
  b.setVal42(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  b.setVal45(es.EntityId(e.MemberToken()));
  b.setVal46(es.EntityId(e.OperatorToken()));
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
  b.setVal38(es.EntityId(e.Token()));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal98(e.IsUnique());
}

void SerializeOffsetOfExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.TypeSourceInfo()));
}

void SerializeObjCSubscriptRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal39(es.EntityId(e.BaseExpression()));
  b.setVal40(es.EntityId(e.KeyExpression()));
  b.setVal41(es.EntityId(e.RBracket()));
  b.setVal98(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.Protocol()));
  b.setVal40(es.EntityId(e.ProtocolIdToken()));
  b.setVal41(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ClassReceiver()));
  b.setVal40(es.EntityId(e.ExplicitProperty()));
  b.setVal41(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal42(es.EntityId(e.ImplicitPropertySetter()));
  b.setVal43(es.EntityId(e.Token()));
  b.setVal44(es.EntityId(e.ReceiverToken()));
  b.setVal45(es.EntityId(e.ReceiverType()));
  b.setVal46(es.EntityId(e.SuperReceiverType()));
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
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.ClassReceiver()));
  b.setVal40(es.EntityId(e.ClassReceiverTypeInfo()));
  b.setVal41(es.EntityId(e.InstanceReceiver()));
  b.setVal42(es.EntityId(e.LeftToken()));
  b.setVal43(es.EntityId(e.MethodDeclaration()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal44(es.EntityId(e.ReceiverInterface()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r45 = e.ReceiverRange(); auto rs45 = r45.Size()) {
    b.setVal45(es.EntityId(r45[0]));
    b.setVal46(es.EntityId(r45[rs45 - 1u]));
  } else {
    b.setVal45(0);
    b.setVal46(0);
  }
  b.setVal47(es.EntityId(e.ReceiverType()));
  b.setVal48(es.EntityId(e.RightToken()));
  b.setVal49(es.EntityId(e.SelectorStartToken()));
  b.setVal50(es.EntityId(e.SuperToken()));
  b.setVal51(es.EntityId(e.SuperType()));
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
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Declaration()));
  b.setVal40(es.EntityId(e.Token()));
  b.setVal41(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.BaseTokenEnd()));
  b.setVal40(es.EntityId(e.IsaMemberToken()));
  b.setVal41(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal98(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.EncodedType()));
  b.setVal40(es.EntityId(e.EncodedTypeSourceInfo()));
  b.setVal41(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.BoxingMethod()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal98(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ArrayWithObjectsMethod()));
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
  b.setVal38(es.EntityId(e.IteratorKwToken()));
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  do {
    auto v17 = e.Dimensions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
}

void SerializeOMPArraySectionExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColonTokenFirst()));
  b.setVal40(es.EntityId(e.ColonTokenSecond()));
  b.setVal41(es.EntityId(e.Length()));
  b.setVal42(es.EntityId(e.LowerBound()));
  b.setVal43(es.EntityId(e.RBracketToken()));
  b.setVal44(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.LAngleToken()));
  b.setVal40(es.EntityId(e.MemberDeclaration()));
  b.setVal41(es.EntityId(e.MemberToken()));
  b.setVal42(es.EntityId(e.OperatorToken()));
  b.setVal43(es.EntityId(e.RAngleToken()));
  b.setVal44(es.EntityId(e.TemplateKeywordToken()));
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
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  b.setVal40(es.EntityId(e.RBracketToken()));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal98(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExtendingDeclaration();
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
  auto v39 = e.LifetimeExtendedTemporaryDeclaration();
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
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal100(e.IsBoundToLvalueReference());
  b.setVal101(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.MemberToken()));
  b.setVal40(es.EntityId(e.PropertyDeclaration()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CallOperator()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  b.setVal40(es.EntityId(e.CaptureDefaultToken()));
  b.setVal41(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v17 = e.ExplicitTemplateParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  if (auto r42 = e.IntroducerRange(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  b.setVal44(es.EntityId(e.LambdaClass()));
  auto v112 = e.TemplateParameterList();
  if (v112) {
    auto o112 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o112], v112.value());
    b.setVal112(o112);
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto v45 = e.TrailingRequiresClause();
  if (v45) {
    if (auto id45 = es.EntityId(v45.value())) {
      b.setVal45(id45);
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
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ArrayFiller();
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
  auto v39 = e.InitializedFieldInUnion();
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
  b.setVal40(es.EntityId(e.LBraceToken()));
  b.setVal41(es.EntityId(e.RBraceToken()));
  auto v42 = e.SemanticForm();
  if (v42) {
    if (auto id42 = es.EntityId(v42.value())) {
      b.setVal42(id42);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  auto v43 = e.SyntacticForm();
  if (v43) {
    if (auto id43 = es.EntityId(v43.value())) {
      b.setVal43(id43);
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
  b.setVal38(es.EntityId(e.SubExpression()));
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
  b.setVal38(es.EntityId(e.ControllingExpression()));
  b.setVal39(es.EntityId(e.DefaultToken()));
  b.setVal40(es.EntityId(e.GenericToken()));
  b.setVal41(es.EntityId(e.RParenToken()));
  b.setVal42(es.EntityId(e.ResultExpression()));
  b.setVal98(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ParameterPack()));
  b.setVal39(es.EntityId(e.ParameterPackToken()));
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
  b.setVal38(es.EntityId(e.SubExpression()));
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
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsExact());
}

void SerializeFixedPointLiteral(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ContainsDuplicateElements());
  b.setVal38(es.EntityId(e.AccessorToken()));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal99(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntitySerializer &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.QueriedExpression()));
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
  b.setVal3(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  b.setVal4(es.EntityId(e.BeginToken()));
  b.setVal5(es.EntityId(e.BodyRBrace()));
  b.setVal6(es.EntityId(e.CanonicalDeclaration()));
  auto v7 = e.DescribedTemplateParameters();
  if (v7) {
    auto o7 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o7], v7.value());
    b.setVal7(o7);
    b.setVal8(true);
  } else {
    b.setVal8(false);
  }
  b.setVal9(es.EntityId(e.EndToken()));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v11 = e.FunctionType();
  if (v11) {
    if (auto id11 = es.EntityId(v11.value())) {
      b.setVal11(id11);
      b.setVal12(true);
    } else {
      b.setVal12(false);
    }
  } else {
    b.setVal12(false);
  }
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  b.setVal14(es.EntityId(e.MostRecentDeclaration()));
  auto v15 = e.NextDeclarationInContext();
  if (v15) {
    if (auto id15 = es.EntityId(v15.value())) {
      b.setVal15(id15);
      b.setVal16(true);
    } else {
      b.setVal16(false);
    }
  } else {
    b.setVal16(false);
  }
  auto v17 = e.NonClosureContext();
  if (v17) {
    if (auto id17 = es.EntityId(v17.value())) {
      b.setVal17(id17);
      b.setVal18(true);
    } else {
      b.setVal18(false);
    }
  } else {
    b.setVal18(false);
  }
  auto v19 = e.PreviousDeclaration();
  if (v19) {
    if (auto id19 = es.EntityId(v19.value())) {
      b.setVal19(id19);
      b.setVal20(true);
    } else {
      b.setVal20(false);
    }
  } else {
    b.setVal20(false);
  }
  b.setVal21(e.HasAttributes());
  b.setVal22(e.HasDefiningAttribute());
  b.setVal23(e.HasOwningModule());
  b.setVal24(e.HasTagIdentifierNamespace());
  b.setVal25(e.IsCanonicalDeclaration());
  b.setVal26(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal27(e.IsDeprecated());
  b.setVal28(e.IsFirstDeclaration());
  b.setVal29(e.IsFunctionOrFunctionTemplate());
  b.setVal30(e.IsImplicit());
  b.setVal31(e.IsInAnonymousNamespace());
  b.setVal32(e.IsInLocalScopeForInstantiation());
  b.setVal33(e.IsInStdNamespace());
  b.setVal34(e.IsInvalidDeclaration());
  b.setVal35(e.IsModulePrivate());
  b.setVal36(e.IsOutOfLine());
  b.setVal37(e.IsParameterPack());
  b.setVal38(e.IsReferenced());
  b.setVal39(e.IsTemplateDeclaration());
  b.setVal40(e.IsTemplateParameter());
  b.setVal41(e.IsTemplateParameterPack());
  b.setVal42(e.IsTemplated());
  b.setVal43(e.IsThisDeclarationReferenced());
  b.setVal44(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal45(e.IsUnavailable());
  b.setVal46(e.IsUnconditionallyVisible());
  b.setVal47(e.IsUsed());
  b.setVal48(e.IsWeakImported());
  do {
    auto v49 = e.Redeclarations();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  b.setVal50(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal51(es.EntityId(e.Token()));
  if (auto r52 = e.TokenRange(); auto rs52 = r52.Size()) {
    b.setVal52(es.EntityId(r52[0]));
    b.setVal53(es.EntityId(r52[rs52 - 1u]));
  } else {
    b.setVal52(0);
    b.setVal53(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.Specialization()));
  b.setVal55(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.ContextParameter()));
  b.setVal55(e.IsNothrow());
  do {
    auto v56 = e.Parameters();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  pasta::DeclContext dc57(e);
  auto v57 = dc57.AlreadyLoadedDeclarations();
  auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
  auto i57 = 0u;
  for (const pasta::Decl &e57 : v57) {
    sv57.set(i57, es.EntityId(e57));
    ++i57;
  }
}

void SerializeBlockDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal55(e.BlockMissingReturnType());
  b.setVal58(e.CanAvoidCopyToHeap());
  b.setVal59(e.CapturesCXXThis());
  b.setVal60(e.DoesNotEscape());
  auto v54 = e.BlockManglingContextDeclaration();
  if (v54) {
    if (auto id54 = es.EntityId(v54.value())) {
      b.setVal54(id54);
      b.setVal61(true);
    } else {
      b.setVal61(false);
    }
  } else {
    b.setVal61(false);
  }
  b.setVal62(es.EntityId(e.CaretToken()));
  b.setVal63(es.EntityId(e.CompoundBody()));
  b.setVal64(es.EntityId(e.SignatureAsWritten()));
  b.setVal65(e.HasCaptures());
  b.setVal66(e.IsConversionFromLambda());
  b.setVal67(e.IsVariadic());
  do {
    auto v56 = e.Parameters();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v57 = e.ParameterDeclarations();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  pasta::DeclContext dc68(e);
  auto v68 = dc68.AlreadyLoadedDeclarations();
  auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
  auto i68 = 0u;
  for (const pasta::Decl &e68 : v68) {
    sv68.set(i68, es.EntityId(e68));
    ++i68;
  }
}

void SerializeAccessSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.AccessSpecifierToken()));
  b.setVal62(es.EntityId(e.ColonToken()));
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
    auto v56 = e.Varlists();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
    auto v56 = e.Varlists();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeStaticAssertDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.AssertExpression()));
  b.setVal62(es.EntityId(e.Message()));
  b.setVal63(es.EntityId(e.RParenToken()));
  b.setVal55(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializePragmaDetectMismatchDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v69 = e.Name();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  auto v70 = e.Value();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
}

void SerializePragmaCommentDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v69 = e.Argument();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.GetterCXXConstructor()));
  b.setVal62(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal63(es.EntityId(e.PropertyDeclaration()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal64(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal72(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal73(es.EntityId(e.SetterCXXAssignment()));
  b.setVal74(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal55(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal75(static_cast<unsigned char>(mx::FromPasta(e.LinkageInternal())));
  b.setVal69(e.Name());
  auto v76 = e.ObjCFStringFormattingFamily();
  if (v76) {
    b.setVal76(static_cast<unsigned char>(v76.value()));
    b.setVal55(true);
  } else {
    b.setVal55(false);
  }
  b.setVal70(e.QualifiedNameAsString());
  b.setVal54(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal58(e.HasExternalFormalLinkage());
  b.setVal59(e.HasLinkage());
  b.setVal60(e.HasLinkageBeenComputed());
  b.setVal61(e.IsCXXClassMember());
  b.setVal65(e.IsCXXInstanceMember());
  b.setVal66(e.IsExternallyDeclarable());
  b.setVal67(e.IsExternallyVisible());
  b.setVal78(e.IsLinkageValid());
}

void SerializeLabelDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v79 = e.MSAssemblyLabel();
  std::string s79(v79.data(), v79.size());
  b.setVal79(s79);
  b.setVal62(es.EntityId(e.Statement()));
  b.setVal80(e.IsGnuLocal());
  b.setVal81(e.IsMSAssemblyLabel());
  b.setVal82(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v56 = e.Shadows();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal62(es.EntityId(e.EnumDeclaration()));
  b.setVal63(es.EntityId(e.EnumToken()));
  b.setVal64(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal62(es.EntityId(e.UsingToken()));
  b.setVal80(e.HasTypename());
  b.setVal81(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal62(es.EntityId(e.Type()));
  b.setVal80(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal63(es.EntityId(e.EllipsisToken()));
  b.setVal64(es.EntityId(e.UsingToken()));
  b.setVal81(e.IsAccessDeclaration());
  b.setVal82(e.IsPackExpansion());
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
  b.setVal63(es.EntityId(e.Combiner()));
  b.setVal64(es.EntityId(e.CombinerIn()));
  b.setVal72(es.EntityId(e.CombinerOut()));
  b.setVal73(es.EntityId(e.InitializerOriginal()));
  b.setVal74(es.EntityId(e.InitializerPrivate()));
  b.setVal83(es.EntityId(e.Initializer()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  b.setVal85(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
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
    auto v56 = e.Chain();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  auto v63 = e.AnonymousField();
  if (v63) {
    if (auto id63 = es.EntityId(v63.value())) {
      b.setVal63(id63);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  auto v64 = e.VariableDeclaration();
  if (v64) {
    if (auto id64 = es.EntityId(v64.value())) {
      b.setVal64(id64);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
}

void SerializeEnumConstantDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v63 = e.InitializerExpression();
  if (v63) {
    if (auto id63 = es.EntityId(v63.value())) {
      b.setVal63(id63);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
}

void SerializeDeclaratorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal63(es.EntityId(e.InnerTokenStart()));
  b.setVal64(es.EntityId(e.OuterTokenStart()));
  auto v72 = e.TrailingRequiresClause();
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
  b.setVal73(es.EntityId(e.TypeSourceInfo()));
  b.setVal74(es.EntityId(e.TypeSpecEndToken()));
  b.setVal83(es.EntityId(e.TypeSpecStartToken()));
  do {
    auto v86 = e.TemplateParameterLists();
    auto sv86 = b.initVal86(static_cast<unsigned>(v86.size()));
    auto i86 = 0u;
    for (const auto &e86 : v86) {
      auto o86 = es.next_pseudo_entity_offset++;
      sv86.set(i86, o86);
      SerializeTemplateParameterList(es, es.pseudo_builder[o86], e86);
      ++i86;
    }
  } while (false);
}

void SerializeVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v85 = e.ActingDefinition();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  auto v87 = e.Initializer();
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
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v89 = e.InitializingDeclaration();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  auto v91 = e.InstantiatedFromStaticDataMember();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal92(true);
    } else {
      b.setVal92(false);
    }
  } else {
    b.setVal92(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal94(es.EntityId(e.PointOfInstantiation()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v99 = e.TemplateInstantiationPattern();
  if (v99) {
    if (auto id99 = es.EntityId(v99.value())) {
      b.setVal99(id99);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal103(e.HasConstantInitialization());
  b.setVal104(e.HasDependentAlignment());
  b.setVal105(e.HasExternalStorage());
  b.setVal106(e.HasGlobalStorage());
  auto v107 = e.HasICEInitializer();
  if (v107) {
    b.setVal107(static_cast<bool>(v107.value()));
    b.setVal108(true);
  } else {
    b.setVal108(false);
  }
  b.setVal109(e.HasInitializer());
  b.setVal110(e.HasLocalStorage());
  b.setVal111(e.IsARCPseudoStrong());
  b.setVal112(e.IsCXXForRangeDeclaration());
  b.setVal113(e.IsConstexpr());
  b.setVal114(e.IsDirectInitializer());
  b.setVal115(e.IsEscapingByref());
  b.setVal116(e.IsExceptionVariable());
  b.setVal117(e.IsExternC());
  b.setVal118(e.IsFileVariableDeclaration());
  b.setVal119(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal120(e.IsInExternCContext());
  b.setVal121(e.IsInExternCXXContext());
  b.setVal122(e.IsInitializerCapture());
  b.setVal123(e.IsInline());
  b.setVal124(e.IsInlineSpecified());
  b.setVal125(e.IsKnownToBeDefined());
  b.setVal126(e.IsLocalVariableDeclaration());
  b.setVal127(e.IsLocalVariableDeclarationOrParm());
  b.setVal128(e.IsNRVOVariable());
  b.setVal129(e.IsNoDestroy());
  b.setVal130(e.IsNonEscapingByref());
  b.setVal131(e.IsObjCForDeclaration());
  b.setVal132(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal133(e.IsStaticDataMember());
  b.setVal134(e.IsStaticLocal());
  b.setVal135(e.IsThisDeclarationADemotedDefinition());
  b.setVal136(e.IsUsableInConstantExpressions());
  b.setVal137(e.MightBeUsableInConstantExpressions());
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v139 = e.DefaultArgument();
  if (v139) {
    if (auto id139 = es.EntityId(v139.value())) {
      b.setVal139(id139);
      b.setVal140(true);
    } else {
      b.setVal140(false);
    }
  } else {
    b.setVal140(false);
  }
  if (auto r141 = e.DefaultArgumentRange(); auto rs141 = r141.Size()) {
    b.setVal141(es.EntityId(r141[0]));
    b.setVal142(es.EntityId(r141[rs141 - 1u]));
  } else {
    b.setVal141(0);
    b.setVal142(0);
  }
  b.setVal143(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal144(es.EntityId(e.OriginalType()));
  auto v145 = e.UninstantiatedDefaultArgument();
  if (v145) {
    if (auto id145 = es.EntityId(v145.value())) {
      b.setVal145(id145);
      b.setVal146(true);
    } else {
      b.setVal146(false);
    }
  } else {
    b.setVal146(false);
  }
  b.setVal147(e.HasDefaultArgument());
  b.setVal148(e.HasInheritedDefaultArgument());
  b.setVal149(e.HasUninstantiatedDefaultArgument());
  b.setVal150(e.HasUnparsedDefaultArgument());
  b.setVal151(e.IsDestroyedInCallee());
  b.setVal152(e.IsKNRPromoted());
  b.setVal153(e.IsObjCMethodParameter());
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
  b.setVal143(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v56 = e.Bindings();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal139(es.EntityId(e.ExternToken()));
  b.setVal143(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v154 = e.TemplateArguments();
    auto sv154 = b.initVal154(static_cast<unsigned>(v154.size()));
    auto i154 = 0u;
    for (const auto &e154 : v154) {
      auto o154 = es.next_pseudo_entity_offset++;
      sv154.set(i154, o154);
      SerializeTemplateArgument(es, es.pseudo_builder[o154], e154);
      ++i154;
    }
  } while (false);
  do {
    auto v155 = e.TemplateInstantiationArguments();
    auto sv155 = b.initVal155(static_cast<unsigned>(v155.size()));
    auto i155 = 0u;
    for (const auto &e155 : v155) {
      auto o155 = es.next_pseudo_entity_offset++;
      sv155.set(i155, o155);
      SerializeTemplateArgument(es, es.pseudo_builder[o155], e155);
      ++i155;
    }
  } while (false);
  b.setVal141(es.EntityId(e.TemplateKeywordToken()));
  b.setVal142(es.EntityId(e.TypeAsWritten()));
  b.setVal140(e.IsClassScopeExplicitSpecialization());
  b.setVal146(e.IsExplicitInstantiationOrSpecialization());
  b.setVal147(e.IsExplicitSpecialization());
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
  b.setVal82(e.DefaultArgumentWasInherited());
  b.setVal85(es.EntityId(e.DefaultArgument()));
  b.setVal87(es.EntityId(e.DefaultArgumentToken()));
  b.setVal89(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal88(e.HasDefaultArgument());
  b.setVal90(e.HasPlaceholderTypeConstraint());
  b.setVal92(e.IsExpandedParameterPack());
  b.setVal100(e.IsPackExpansion());
  do {
    auto v56 = e.ExpansionTypes();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v57 = e.ExpansionTypeSourceInfos();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal82(e.HasGetter());
  b.setVal88(e.HasSetter());
}

void SerializeFunctionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v82 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v82) {
    b.setVal82(static_cast<bool>(v82.value()));
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  b.setVal90(e.DoesThisDeclarationHaveABody());
  b.setVal85(es.EntityId(e.CallResultType()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal87(es.EntityId(e.DeclaredReturnType()));
  auto v89 = e.Definition();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal92(true);
    } else {
      b.setVal92(false);
    }
  } else {
    b.setVal92(false);
  }
  b.setVal91(es.EntityId(e.EllipsisToken()));
  if (auto r94 = e.ExceptionSpecSourceRange(); auto rs94 = r94.Size()) {
    b.setVal94(es.EntityId(r94[0]));
    b.setVal99(es.EntityId(r94[rs94 - 1u]));
  } else {
    b.setVal94(0);
    b.setVal99(0);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v139 = e.InstantiatedFromMemberFunction();
  if (v139) {
    if (auto id139 = es.EntityId(v139.value())) {
      b.setVal139(id139);
      b.setVal100(true);
    } else {
      b.setVal100(false);
    }
  } else {
    b.setVal100(false);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v156 = e.ODRHash();
  if (v156) {
    b.setVal156(static_cast<unsigned>(v156.value()));
    b.setVal103(true);
  } else {
    b.setVal103(false);
  }
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r141 = e.ParametersSourceRange(); auto rs141 = r141.Size()) {
    b.setVal141(es.EntityId(r141[0]));
    b.setVal142(es.EntityId(r141[rs141 - 1u]));
  } else {
    b.setVal141(0);
    b.setVal142(0);
  }
  b.setVal144(es.EntityId(e.PointOfInstantiation()));
  b.setVal145(es.EntityId(e.ReturnType()));
  if (auto r157 = e.ReturnTypeSourceRange(); auto rs157 = r157.Size()) {
    b.setVal157(es.EntityId(r157[0]));
    b.setVal158(es.EntityId(r157[rs157 - 1u]));
  } else {
    b.setVal157(0);
    b.setVal158(0);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v159 = e.TemplateInstantiationPattern();
  if (v159) {
    if (auto id159 = es.EntityId(v159.value())) {
      b.setVal159(id159);
      b.setVal104(true);
    } else {
      b.setVal104(false);
    }
  } else {
    b.setVal104(false);
  }
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal105(e.HasImplicitReturnZero());
  b.setVal106(e.HasInheritedPrototype());
  b.setVal107(e.HasOneParameterOrDefaultArguments());
  b.setVal108(e.HasPrototype());
  b.setVal109(e.HasSkippedBody());
  b.setVal110(e.HasTrivialBody());
  b.setVal111(e.HasWrittenPrototype());
  b.setVal112(e.InstantiationIsPending());
  b.setVal113(e.IsCPUDispatchMultiVersion());
  b.setVal114(e.IsCPUSpecificMultiVersion());
  b.setVal115(e.IsConsteval());
  b.setVal116(e.IsConstexpr());
  b.setVal117(e.IsConstexprSpecified());
  b.setVal118(e.IsDefaulted());
  b.setVal119(e.IsDeleted());
  b.setVal120(e.IsDeletedAsWritten());
  b.setVal121(e.IsDestroyingOperatorDelete());
  b.setVal122(e.IsExplicitlyDefaulted());
  b.setVal123(e.IsExternC());
  b.setVal124(e.IsFunctionTemplateSpecialization());
  b.setVal125(e.IsGlobal());
  b.setVal126(e.IsImplicitlyInstantiable());
  b.setVal127(e.IsInExternCContext());
  b.setVal128(e.IsInExternCXXContext());
  b.setVal129(e.IsInlineBuiltinDeclaration());
  auto v130 = e.IsInlineDefinitionExternallyVisible();
  if (v130) {
    b.setVal130(static_cast<bool>(v130.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  b.setVal132(e.IsInlineSpecified());
  b.setVal133(e.IsInlined());
  b.setVal134(e.IsLateTemplateParsed());
  auto v135 = e.IsMSExternInline();
  if (v135) {
    b.setVal135(static_cast<bool>(v135.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  b.setVal137(e.IsMSVCRTEntryPoint());
  b.setVal140(e.IsMain());
  b.setVal146(e.IsMultiVersion());
  b.setVal147(e.IsNoReturn());
  b.setVal148(e.IsOverloadedOperator());
  b.setVal149(e.IsPure());
  b.setVal150(e.IsReplaceableGlobalAllocationFunction());
  auto v151 = e.IsReservedGlobalPlacementOperator();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  b.setVal153(e.IsStatic());
  b.setVal160(e.IsTargetMultiVersion());
  b.setVal161(e.IsTemplateInstantiation());
  b.setVal162(e.IsThisDeclarationADefinition());
  b.setVal163(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal164(e.IsTrivial());
  b.setVal165(e.IsTrivialForCall());
  b.setVal166(e.IsUserProvided());
  b.setVal167(e.IsVariadic());
  b.setVal168(e.IsVirtualAsWritten());
  do {
    auto v56 = e.Parameters();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  b.setVal169(e.UsesSEHTry());
  b.setVal170(e.WillHaveBody());
  auto v171 = e.Body();
  if (v171) {
    if (auto id171 = es.EntityId(v171.value())) {
      b.setVal171(id171);
      b.setVal172(true);
    } else {
      b.setVal172(false);
    }
  } else {
    b.setVal172(false);
  }
  pasta::DeclContext dc57(e);
  auto v57 = dc57.AlreadyLoadedDeclarations();
  auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
  auto i57 = 0u;
  for (const pasta::Decl &e57 : v57) {
    sv57.set(i57, es.EntityId(e57));
    ++i57;
  }
}

void SerializeCXXMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal173(es.EntityId(e.Parent()));
  b.setVal143(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal174(es.EntityId(e.ThisObjectType()));
  b.setVal175(es.EntityId(e.ThisType()));
  b.setVal176(e.HasInlineBody());
  b.setVal177(e.IsConst());
  b.setVal178(e.IsCopyAssignmentOperator());
  b.setVal179(e.IsInstance());
  b.setVal180(e.IsLambdaStaticInvoker());
  b.setVal181(e.IsMoveAssignmentOperator());
  b.setVal182(e.IsVirtual());
  b.setVal183(e.IsVolatile());
  do {
    auto v68 = e.OverriddenMethods();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      sv68.set(i68, es.EntityId(e68));
      ++i68;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v184 = e.OperatorDelete();
  if (v184) {
    if (auto id184 = es.EntityId(v184.value())) {
      b.setVal184(id184);
      b.setVal185(true);
    } else {
      b.setVal185(false);
    }
  } else {
    b.setVal185(false);
  }
  auto v186 = e.OperatorDeleteThisArgument();
  if (v186) {
    if (auto id186 = es.EntityId(v186.value())) {
      b.setVal186(id186);
      b.setVal187(true);
    } else {
      b.setVal187(false);
    }
  } else {
    b.setVal187(false);
  }
}

void SerializeCXXConversionDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal184(es.EntityId(e.ConversionType()));
  b.setVal185(e.IsExplicit());
  b.setVal187(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v184 = e.TargetConstructor();
  if (v184) {
    if (auto id184 = es.EntityId(v184.value())) {
      b.setVal184(id184);
      b.setVal185(true);
    } else {
      b.setVal185(false);
    }
  } else {
    b.setVal185(false);
  }
  b.setVal187(e.IsDefaultConstructor());
  b.setVal188(e.IsDelegatingConstructor());
  b.setVal189(e.IsExplicit());
  b.setVal190(e.IsInheritingConstructor());
  b.setVal191(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal173(es.EntityId(e.CorrespondingConstructor()));
  b.setVal176(e.IsCopyDeductionCandidate());
  b.setVal177(e.IsExplicit());
}

void SerializeFieldDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v85 = e.BitWidth();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  auto v87 = e.CapturedVLAType();
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
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v89 = e.InClassInitializer();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
  b.setVal91(es.EntityId(e.Parent()));
  b.setVal92(e.HasCapturedVLAType());
  b.setVal100(e.HasInClassInitializer());
  b.setVal103(e.IsAnonymousStructOrUnion());
  b.setVal104(e.IsBitField());
  b.setVal105(e.IsMutable());
  b.setVal106(e.IsUnnamedBitfield());
  b.setVal107(e.IsZeroLengthBitField());
  b.setVal108(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal94(es.EntityId(e.ContainingInterface()));
  b.setVal99(es.EntityId(e.NextInstanceVariable()));
  b.setVal109(e.Synthesize());
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
  b.setVal63(es.EntityId(e.Binding()));
  b.setVal64(es.EntityId(e.DecomposedDeclaration()));
  b.setVal72(es.EntityId(e.HoldingVariable()));
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
  b.setVal63(es.EntityId(e.MapperVariableReference()));
  b.setVal64(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal62(es.EntityId(e.Introducer()));
  auto v63 = e.NextUsingShadowDeclaration();
  if (v63) {
    if (auto id63 = es.EntityId(v63.value())) {
      b.setVal63(id63);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
  b.setVal64(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal81(e.ConstructsVirtualBase());
  b.setVal72(es.EntityId(e.ConstructedBaseClass()));
  auto v73 = e.ConstructedBaseClassShadowDeclaration();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal74(es.EntityId(e.NominatedBaseClass()));
  auto v83 = e.NominatedBaseClassShadowDeclaration();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal85(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v56 = e.Expansions();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  b.setVal62(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal62(es.EntityId(e.IdentifierToken()));
  b.setVal63(es.EntityId(e.NamespaceKeyToken()));
  b.setVal64(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal72(es.EntityId(e.UsingToken()));
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
  auto v62 = e.TypeForDeclaration();
  if (v62) {
    if (auto id62 = es.EntityId(v62.value())) {
      b.setVal62(id62);
      b.setVal80(true);
    } else {
      b.setVal80(false);
    }
  } else {
    b.setVal80(false);
  }
}

void SerializeTemplateTypeParmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal81(e.DefaultArgumentWasInherited());
  b.setVal63(es.EntityId(e.DefaultArgument()));
  b.setVal64(es.EntityId(e.DefaultArgumentInfo()));
  b.setVal72(es.EntityId(e.DefaultArgumentToken()));
  b.setVal82(e.HasDefaultArgument());
  b.setVal88(e.HasTypeConstraint());
  b.setVal90(e.IsExpandedParameterPack());
  b.setVal92(e.IsPackExpansion());
  b.setVal100(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r63 = e.BraceRange(); auto rs63 = r63.Size()) {
    b.setVal63(es.EntityId(r63[0]));
    b.setVal64(es.EntityId(r63[rs63 - 1u]));
  } else {
    b.setVal63(0);
    b.setVal64(0);
  }
  auto v72 = e.Definition();
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
  b.setVal73(es.EntityId(e.InnerTokenStart()));
  b.setVal74(es.EntityId(e.OuterTokenStart()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v83 = e.TypedefNameForAnonymousDeclaration();
  if (v83) {
    if (auto id83 = es.EntityId(v83.value())) {
      b.setVal83(id83);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  b.setVal88(e.HasNameForLinkage());
  b.setVal90(e.IsBeingDefined());
  b.setVal92(e.IsClass());
  b.setVal100(e.IsCompleteDefinition());
  b.setVal103(e.IsCompleteDefinitionRequired());
  b.setVal104(e.IsDependentType());
  b.setVal105(e.IsEmbeddedInDeclarator());
  b.setVal106(e.IsEnum());
  b.setVal107(e.IsFreeStanding());
  b.setVal108(e.IsInterface());
  b.setVal109(e.IsStruct());
  b.setVal110(e.IsThisDeclarationADefinition());
  b.setVal111(e.IsUnion());
  b.setVal112(e.MayHaveOutOfDateDefinition());
  do {
    auto v86 = e.TemplateParameterLists();
    auto sv86 = b.initVal86(static_cast<unsigned>(v86.size()));
    auto i86 = 0u;
    for (const auto &e86 : v86) {
      auto o86 = es.next_pseudo_entity_offset++;
      sv86.set(i86, o86);
      SerializeTemplateParameterList(es, es.pseudo_builder[o86], e86);
      ++i86;
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

void SerializeRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal113(e.CanPassInRegisters());
  do {
    auto v57 = e.Fields();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  auto v85 = e.FindFirstNamedDataMember();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal114(true);
    } else {
      b.setVal114(false);
    }
  } else {
    b.setVal114(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal115(e.HasFlexibleArrayMember());
  b.setVal116(e.HasLoadedFieldsFromExternalStorage());
  b.setVal117(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal118(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal119(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal120(e.HasObjectMember());
  b.setVal121(e.HasVolatileMember());
  b.setVal122(e.IsAnonymousStructOrUnion());
  b.setVal123(e.IsCapturedRecord());
  b.setVal124(e.IsInjectedClassName());
  b.setVal125(e.IsLambda());
  b.setVal126(e.IsMsStruct());
  b.setVal127(e.IsNonTrivialToPrimitiveCopy());
  b.setVal128(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal129(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal130(e.IsOrContainsUnion());
  b.setVal131(e.IsParameterDestroyedInCallee());
  b.setVal132(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v133 = e.AllowConstDefaultInitializer();
  if (v133) {
    b.setVal133(static_cast<bool>(v133.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  do {
    auto ov154 = e.Bases();
    if (!ov154) {
      b.setVal135(false);
      break;
    }
    b.setVal135(true);
    auto v154 = std::move(*ov154);
    auto sv154 = b.initVal154(static_cast<unsigned>(v154.size()));
    auto i154 = 0u;
    for (const auto &e154 : v154) {
      auto o154 = es.next_pseudo_entity_offset++;
      sv154.set(i154, o154);
      SerializeCXXBaseSpecifier(es, es.pseudo_builder[o154], e154);
      ++i154;
    }
  } while (false);
  auto v95 = e.CalculateInheritanceModel();
  if (v95) {
    b.setVal95(static_cast<unsigned char>(v95.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  do {
    auto v68 = e.Constructors();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      sv68.set(i68, es.EntityId(e68));
      ++i68;
    }
  } while (false);
  do {
    auto ov192 = e.Friends();
    if (!ov192) {
      b.setVal137(false);
      break;
    }
    b.setVal137(true);
    auto v192 = std::move(*ov192);
    auto sv192 = b.initVal192(static_cast<unsigned>(v192.size()));
    auto i192 = 0u;
    for (const auto &e192 : v192) {
      sv192.set(i192, es.EntityId(e192));
      ++i192;
    }
  } while (false);
  auto v87 = e.Destructor();
  if (v87) {
    if (auto id87 = es.EntityId(v87.value())) {
      b.setVal87(id87);
      b.setVal140(true);
    } else {
      b.setVal140(false);
    }
  } else {
    b.setVal140(false);
  }
  auto v156 = e.GenericLambdaTemplateParameterList();
  if (v156) {
    auto o156 = es.next_pseudo_entity_offset++;
    SerializeTemplateParameterList(es, es.pseudo_builder[o156], v156.value());
    b.setVal156(o156);
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v89 = e.InstantiatedFromMemberClass();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal147(true);
    } else {
      b.setVal147(false);
    }
  } else {
    b.setVal147(false);
  }
  auto v91 = e.LambdaCallOperator();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal148(true);
    } else {
      b.setVal148(false);
    }
  } else {
    b.setVal148(false);
  }
  auto v96 = e.LambdaCaptureDefault();
  if (v96) {
    b.setVal96(static_cast<unsigned char>(v96.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v94 = e.LambdaContextDeclaration();
  if (v94) {
    if (auto id94 = es.EntityId(v94.value())) {
      b.setVal94(id94);
      b.setVal150(true);
    } else {
      b.setVal150(false);
    }
  } else {
    b.setVal150(false);
  }
  do {
    auto ov193 = e.LambdaExplicitTemplateParameters();
    if (!ov193) {
      b.setVal151(false);
      break;
    }
    b.setVal151(true);
    auto v193 = std::move(*ov193);
    auto sv193 = b.initVal193(static_cast<unsigned>(v193.size()));
    auto i193 = 0u;
    for (const auto &e193 : v193) {
      sv193.set(i193, es.EntityId(e193));
      ++i193;
    }
  } while (false);
  auto v194 = e.LambdaManglingNumber();
  if (v194) {
    b.setVal194(static_cast<unsigned>(v194.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v99 = e.LambdaTypeInfo();
  if (v99) {
    if (auto id99 = es.EntityId(v99.value())) {
      b.setVal99(id99);
      b.setVal153(true);
    } else {
      b.setVal153(false);
    }
  } else {
    b.setVal153(false);
  }
  auto v97 = e.MSInheritanceModel();
  if (v97) {
    b.setVal97(static_cast<unsigned char>(v97.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v195 = e.NumBases();
  if (v195) {
    b.setVal195(static_cast<unsigned>(v195.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v196 = e.NumVirtualBases();
  if (v196) {
    b.setVal196(static_cast<unsigned>(v196.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v197 = e.ODRHash();
  if (v197) {
    b.setVal197(static_cast<unsigned>(v197.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v139 = e.TemplateInstantiationPattern();
  if (v139) {
    if (auto id139 = es.EntityId(v139.value())) {
      b.setVal139(id139);
      b.setVal164(true);
    } else {
      b.setVal164(false);
    }
  } else {
    b.setVal164(false);
  }
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v165 = e.HasAnyDependentBases();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasConstexprDefaultConstructor();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasConstexprDestructor();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v172 = e.HasConstexprNonCopyMoveConstructor();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasCopyAssignmentWithConstParameter();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v179 = e.HasCopyConstructorWithConstParameter();
  if (v179) {
    b.setVal179(static_cast<bool>(v179.value()));
    b.setVal180(true);
  } else {
    b.setVal180(false);
  }
  auto v181 = e.HasDefaultConstructor();
  if (v181) {
    b.setVal181(static_cast<bool>(v181.value()));
    b.setVal182(true);
  } else {
    b.setVal182(false);
  }
  auto v183 = e.HasDefinition();
  if (v183) {
    b.setVal183(static_cast<bool>(v183.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v187 = e.HasDirectFields();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasFriends();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v191 = e.HasInClassInitializer();
  if (v191) {
    b.setVal191(static_cast<bool>(v191.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasInheritedAssignment();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasInheritedConstructor();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasIrrelevantDestructor();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasKnownLambdaInternalLinkage();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasMoveAssignment();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasMoveConstructor();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasMutableFields();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonLiteralTypeFieldsOrBases();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialCopyAssignment();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialCopyConstructor();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasNonTrivialCopyConstructorForCall();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasNonTrivialDefaultConstructor();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasNonTrivialDestructor();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasNonTrivialDestructorForCall();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasNonTrivialMoveAssignment();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasNonTrivialMoveConstructor();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasNonTrivialMoveConstructorForCall();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasPrivateFields();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasProtectedFields();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasSimpleCopyAssignment();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasSimpleCopyConstructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasSimpleDestructor();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasSimpleMoveAssignment();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasSimpleMoveConstructor();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialCopyAssignment();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialCopyConstructor();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasTrivialCopyConstructorForCall();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasTrivialDefaultConstructor();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasTrivialDestructor();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasTrivialDestructorForCall();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasTrivialMoveAssignment();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasTrivialMoveConstructor();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasTrivialMoveConstructorForCall();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUninitializedReferenceMember();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserDeclaredConstructor();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasUserDeclaredCopyAssignment();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.HasUserDeclaredCopyConstructor();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.HasUserDeclaredDestructor();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.HasUserDeclaredMoveAssignment();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.HasUserDeclaredMoveConstructor();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.HasUserDeclaredMoveOperation();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.HasUserProvidedDefaultConstructor();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.HasVariantMembers();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.ImplicitCopyConstructorHasConstParameter();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  auto v289 = e.IsAbstract();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  auto v291 = e.IsAggregate();
  if (v291) {
    b.setVal291(static_cast<bool>(v291.value()));
    b.setVal292(true);
  } else {
    b.setVal292(false);
  }
  auto v293 = e.IsAnyDestructorNoReturn();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v295 = e.IsCLike();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsCXX11StandardLayout();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  b.setVal299(e.IsDependentLambda());
  auto v300 = e.IsDynamicClass();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsEffectivelyFinal();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsEmpty();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  b.setVal306(e.IsGenericLambda());
  auto v307 = e.IsInterfaceLike();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.IsLiteral();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v141 = e.IsLocalClass();
  if (v141) {
    if (auto id141 = es.EntityId(v141.value())) {
      b.setVal141(id141);
      b.setVal311(true);
    } else {
      b.setVal311(false);
    }
  } else {
    b.setVal311(false);
  }
  auto v312 = e.IsPOD();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.IsPolymorphic();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.IsStandardLayout();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.IsStructural();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.IsTrivial();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.IsTriviallyCopyable();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.MayBeAbstract();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.MayBeDynamicClass();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.MayBeNonDynamicClass();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  do {
    auto ov332 = e.Methods();
    if (!ov332) {
      b.setVal333(false);
      break;
    }
    b.setVal333(true);
    auto v332 = std::move(*ov332);
    auto sv332 = b.initVal332(static_cast<unsigned>(v332.size()));
    auto i332 = 0u;
    for (const auto &e332 : v332) {
      sv332.set(i332, es.EntityId(e332));
      ++i332;
    }
  } while (false);
  auto v334 = e.NeedsImplicitCopyAssignment();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsImplicitCopyConstructor();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsImplicitDefaultConstructor();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsImplicitDestructor();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NeedsImplicitMoveAssignment();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  auto v344 = e.NeedsImplicitMoveConstructor();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  auto v346 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v346) {
    b.setVal346(static_cast<bool>(v346.value()));
    b.setVal347(true);
  } else {
    b.setVal347(false);
  }
  auto v348 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v348) {
    b.setVal348(static_cast<bool>(v348.value()));
    b.setVal349(true);
  } else {
    b.setVal349(false);
  }
  auto v350 = e.NeedsOverloadResolutionForDestructor();
  if (v350) {
    b.setVal350(static_cast<bool>(v350.value()));
    b.setVal351(true);
  } else {
    b.setVal351(false);
  }
  auto v352 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v352) {
    b.setVal352(static_cast<bool>(v352.value()));
    b.setVal353(true);
  } else {
    b.setVal353(false);
  }
  auto v354 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v354) {
    b.setVal354(static_cast<bool>(v354.value()));
    b.setVal355(true);
  } else {
    b.setVal355(false);
  }
  auto v356 = e.NullFieldOffsetIsZero();
  if (v356) {
    b.setVal356(static_cast<bool>(v356.value()));
    b.setVal357(true);
  } else {
    b.setVal357(false);
  }
  do {
    auto ov155 = e.VirtualBases();
    if (!ov155) {
      b.setVal358(false);
      break;
    }
    b.setVal358(true);
    auto v155 = std::move(*ov155);
    auto sv155 = b.initVal155(static_cast<unsigned>(v155.size()));
    auto i155 = 0u;
    for (const auto &e155 : v155) {
      auto o155 = es.next_pseudo_entity_offset++;
      sv155.set(i155, o155);
      SerializeCXXBaseSpecifier(es, es.pseudo_builder[o155], e155);
      ++i155;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  b.setVal142(es.EntityId(e.ExternToken()));
  b.setVal144(es.EntityId(e.PointOfInstantiation()));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v359 = e.TemplateArguments();
    auto sv359 = b.initVal359(static_cast<unsigned>(v359.size()));
    auto i359 = 0u;
    for (const auto &e359 : v359) {
      auto o359 = es.next_pseudo_entity_offset++;
      sv359.set(i359, o359);
      SerializeTemplateArgument(es, es.pseudo_builder[o359], e359);
      ++i359;
    }
  } while (false);
  do {
    auto v360 = e.TemplateInstantiationArguments();
    auto sv360 = b.initVal360(static_cast<unsigned>(v360.size()));
    auto i360 = 0u;
    for (const auto &e360 : v360) {
      auto o360 = es.next_pseudo_entity_offset++;
      sv360.set(i360, o360);
      SerializeTemplateArgument(es, es.pseudo_builder[o360], e360);
      ++i360;
    }
  } while (false);
  b.setVal145(es.EntityId(e.TemplateKeywordToken()));
  b.setVal157(es.EntityId(e.TypeAsWritten()));
  b.setVal361(e.IsClassScopeExplicitSpecialization());
  b.setVal362(e.IsExplicitInstantiationOrSpecialization());
  b.setVal363(e.IsExplicitSpecialization());
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
    auto v57 = e.Enumerators();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  auto v85 = e.InstantiatedFromMemberEnum();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal113(true);
    } else {
      b.setVal113(false);
    }
  } else {
    b.setVal113(false);
  }
  auto v87 = e.IntegerType();
  if (v87) {
    if (auto id87 = es.EntityId(v87.value())) {
      b.setVal87(id87);
      b.setVal114(true);
    } else {
      b.setVal114(false);
    }
  } else {
    b.setVal114(false);
  }
  if (auto r89 = e.IntegerTypeRange(); auto rs89 = r89.Size()) {
    b.setVal89(es.EntityId(r89[0]));
    b.setVal91(es.EntityId(r89[rs89 - 1u]));
  } else {
    b.setVal89(0);
    b.setVal91(0);
  }
  auto v94 = e.IntegerTypeSourceInfo();
  if (v94) {
    if (auto id94 = es.EntityId(v94.value())) {
      b.setVal94(id94);
      b.setVal115(true);
    } else {
      b.setVal115(false);
    }
  } else {
    b.setVal115(false);
  }
  auto v156 = e.ODRHash();
  if (v156) {
    b.setVal156(static_cast<unsigned>(v156.value()));
    b.setVal116(true);
  } else {
    b.setVal116(false);
  }
  b.setVal99(es.EntityId(e.PromotionType()));
  auto v139 = e.TemplateInstantiationPattern();
  if (v139) {
    if (auto id139 = es.EntityId(v139.value())) {
      b.setVal139(id139);
      b.setVal117(true);
    } else {
      b.setVal117(false);
    }
  } else {
    b.setVal117(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal118(e.IsClosed());
  b.setVal119(e.IsClosedFlag());
  b.setVal120(e.IsClosedNonFlag());
  b.setVal121(e.IsComplete());
  b.setVal122(e.IsFixed());
  b.setVal123(e.IsScoped());
  b.setVal124(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal63(es.EntityId(e.EllipsisToken()));
  b.setVal64(es.EntityId(e.TypenameToken()));
  b.setVal72(es.EntityId(e.UsingToken()));
  b.setVal81(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v63 = e.AnonymousDeclarationWithTypedefName();
  if (v63) {
    if (auto id63 = es.EntityId(v63.value())) {
      b.setVal63(id63);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal64(es.EntityId(e.TypeSourceInfo()));
  b.setVal72(es.EntityId(e.UnderlyingType()));
  b.setVal82(e.IsModed());
  b.setVal88(e.IsTransparentTag());
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
  auto v73 = e.DescribedAliasTemplate();
  if (v73) {
    if (auto id73 = es.EntityId(v73.value())) {
      b.setVal73(id73);
      b.setVal90(true);
    } else {
      b.setVal90(false);
    }
  } else {
    b.setVal90(false);
  }
}

void SerializeObjCTypeParamDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  b.setVal73(es.EntityId(e.ColonToken()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  b.setVal74(es.EntityId(e.VarianceToken()));
  b.setVal90(e.HasExplicitBound());
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
  b.setVal62(es.EntityId(e.ConstraintExpression()));
  b.setVal80(e.IsTypeConcept());
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
  b.setVal62(es.EntityId(e.AtToken()));
  b.setVal63(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal64(es.EntityId(e.GetterNameToken()));
  b.setVal72(es.EntityId(e.LParenToken()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal73(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal74(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal83(es.EntityId(e.SetterNameToken()));
  b.setVal85(es.EntityId(e.Type()));
  b.setVal87(es.EntityId(e.TypeSourceInfo()));
  b.setVal80(e.IsAtomic());
  b.setVal81(e.IsClassProperty());
  b.setVal82(e.IsDirectProperty());
  b.setVal88(e.IsInstanceProperty());
  b.setVal90(e.IsOptional());
  b.setVal92(e.IsReadOnly());
  b.setVal100(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal80(e.DefinedInNSObject());
  b.setVal62(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal63(es.EntityId(e.Category()));
  b.setVal64(es.EntityId(e.ClassInterface()));
  b.setVal72(es.EntityId(e.CmdDeclaration()));
  b.setVal73(es.EntityId(e.DeclaratorEndToken()));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal74(es.EntityId(e.ReturnType()));
  b.setVal83(es.EntityId(e.ReturnTypeSourceInfo()));
  if (auto r85 = e.ReturnTypeSourceRange(); auto rs85 = r85.Size()) {
    b.setVal85(es.EntityId(r85[0]));
    b.setVal87(es.EntityId(r85[rs85 - 1u]));
  } else {
    b.setVal85(0);
    b.setVal87(0);
  }
  b.setVal89(es.EntityId(e.SelectorStartToken()));
  b.setVal91(es.EntityId(e.SelfDeclaration()));
  b.setVal81(e.HasRedeclaration());
  b.setVal82(e.HasRelatedResultType());
  b.setVal88(e.HasSkippedBody());
  b.setVal90(e.IsClassMethod());
  b.setVal92(e.IsDefined());
  b.setVal100(e.IsDesignatedInitializerForTheInterface());
  b.setVal103(e.IsDirectMethod());
  b.setVal104(e.IsInstanceMethod());
  b.setVal105(e.IsOptional());
  b.setVal106(e.IsOverriding());
  b.setVal107(e.IsPropertyAccessor());
  b.setVal108(e.IsRedeclaration());
  b.setVal109(e.IsSynthesizedAccessorStub());
  b.setVal110(e.IsThisDeclarationADefinition());
  b.setVal111(e.IsThisDeclarationADesignatedInitializer());
  b.setVal112(e.IsVariadic());
  do {
    auto v56 = e.Parameters();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v57 = e.SelectorTokens();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  pasta::DeclContext dc68(e);
  auto v68 = dc68.AlreadyLoadedDeclarations();
  auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
  auto i68 = 0u;
  for (const pasta::Decl &e68 : v68) {
    sv68.set(i68, es.EntityId(e68));
    ++i68;
  }
}

void SerializeObjCContainerDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v56 = e.ClassMethods();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v57 = e.ClassProperties();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  if (auto r62 = e.AtEndRange(); auto rs62 = r62.Size()) {
    b.setVal62(es.EntityId(r62[0]));
    b.setVal63(es.EntityId(r62[rs62 - 1u]));
  } else {
    b.setVal62(0);
    b.setVal63(0);
  }
  b.setVal64(es.EntityId(e.AtStartToken()));
  do {
    auto v68 = e.InstanceMethods();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      sv68.set(i68, es.EntityId(e68));
      ++i68;
    }
  } while (false);
  do {
    auto v192 = e.InstanceProperties();
    auto sv192 = b.initVal192(static_cast<unsigned>(v192.size()));
    auto i192 = 0u;
    for (const auto &e192 : v192) {
      sv192.set(i192, es.EntityId(e192));
      ++i192;
    }
  } while (false);
  do {
    auto v193 = e.Methods();
    auto sv193 = b.initVal193(static_cast<unsigned>(v193.size()));
    auto i193 = 0u;
    for (const auto &e193 : v193) {
      sv193.set(i193, es.EntityId(e193));
      ++i193;
    }
  } while (false);
  do {
    auto v332 = e.Properties();
    auto sv332 = b.initVal332(static_cast<unsigned>(v332.size()));
    auto i332 = 0u;
    for (const auto &e332 : v332) {
      sv332.set(i332, es.EntityId(e332));
      ++i332;
    }
  } while (false);
  pasta::DeclContext dc364(e);
  auto v364 = dc364.AlreadyLoadedDeclarations();
  auto sv364 = b.initVal364(static_cast<unsigned>(v364.size()));
  auto i364 = 0u;
  for (const pasta::Decl &e364 : v364) {
    sv364.set(i364, es.EntityId(e364));
    ++i364;
  }
}

void SerializeObjCCategoryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal80(e.IsClassExtension());
  b.setVal72(es.EntityId(e.CategoryNameToken()));
  b.setVal73(es.EntityId(e.ClassInterface()));
  b.setVal74(es.EntityId(e.Implementation()));
  b.setVal83(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal85(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal87(es.EntityId(e.NextClassCategory()));
  b.setVal89(es.EntityId(e.NextClassCategoryRaw()));
  do {
    auto v365 = e.InstanceVariables();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
  do {
    auto v366 = e.ProtocolTokens();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
  do {
    auto v367 = e.Protocols();
    auto sv367 = b.initVal367(static_cast<unsigned>(v367.size()));
    auto i367 = 0u;
    for (const auto &e367 : v367) {
      sv367.set(i367, es.EntityId(e367));
      ++i367;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal72(es.EntityId(e.Definition()));
  auto v79 = e.ObjCRuntimeNameAsString();
  std::string s79(v79.data(), v79.size());
  b.setVal79(s79);
  b.setVal80(e.HasDefinition());
  b.setVal81(e.IsNonRuntimeProtocol());
  b.setVal82(e.IsThisDeclarationADefinition());
  do {
    auto v365 = e.ProtocolTokens();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
  do {
    auto v366 = e.Protocols();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v365 = e.AllReferencedProtocols();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
  b.setVal80(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal72(es.EntityId(e.CategoryListRaw()));
  b.setVal73(es.EntityId(e.Definition()));
  b.setVal74(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal83(es.EntityId(e.Implementation()));
  auto v79 = e.ObjCRuntimeNameAsString();
  std::string s79(v79.data(), v79.size());
  b.setVal79(s79);
  auto v85 = e.SuperClass();
  if (v85) {
    if (auto id85 = es.EntityId(v85.value())) {
      b.setVal85(id85);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal87(es.EntityId(e.SuperClassToken()));
  auto v89 = e.SuperClassTypeInfo();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal82(true);
    } else {
      b.setVal82(false);
    }
  } else {
    b.setVal82(false);
  }
  auto v91 = e.SuperClassType();
  if (v91) {
    if (auto id91 = es.EntityId(v91.value())) {
      b.setVal91(id91);
      b.setVal88(true);
    } else {
      b.setVal88(false);
    }
  } else {
    b.setVal88(false);
  }
  b.setVal94(es.EntityId(e.TypeForDeclaration()));
  b.setVal90(e.HasDefinition());
  b.setVal92(e.HasDesignatedInitializers());
  b.setVal100(e.IsArcWeakrefUnavailable());
  b.setVal103(e.IsImplicitInterfaceDeclaration());
  b.setVal99(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal104(e.IsThisDeclarationADefinition());
  do {
    auto v366 = e.InstanceVariables();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
  do {
    auto v367 = e.KnownCategories();
    auto sv367 = b.initVal367(static_cast<unsigned>(v367.size()));
    auto i367 = 0u;
    for (const auto &e367 : v367) {
      sv367.set(i367, es.EntityId(e367));
      ++i367;
    }
  } while (false);
  do {
    auto v368 = e.KnownExtensions();
    auto sv368 = b.initVal368(static_cast<unsigned>(v368.size()));
    auto i368 = 0u;
    for (const auto &e368 : v368) {
      sv368.set(i368, es.EntityId(e368));
      ++i368;
    }
  } while (false);
  do {
    auto v369 = e.ProtocolTokens();
    auto sv369 = b.initVal369(static_cast<unsigned>(v369.size()));
    auto i369 = 0u;
    for (const auto &e369 : v369) {
      sv369.set(i369, es.EntityId(e369));
      ++i369;
    }
  } while (false);
  do {
    auto v370 = e.Protocols();
    auto sv370 = b.initVal370(static_cast<unsigned>(v370.size()));
    auto i370 = 0u;
    for (const auto &e370 : v370) {
      sv370.set(i370, es.EntityId(e370));
      ++i370;
    }
  } while (false);
  do {
    auto v371 = e.VisibleCategories();
    auto sv371 = b.initVal371(static_cast<unsigned>(v371.size()));
    auto i371 = 0u;
    for (const auto &e371 : v371) {
      sv371.set(i371, es.EntityId(e371));
      ++i371;
    }
  } while (false);
  do {
    auto v372 = e.VisibleExtensions();
    auto sv372 = b.initVal372(static_cast<unsigned>(v372.size()));
    auto i372 = 0u;
    for (const auto &e372 : v372) {
      sv372.set(i372, es.EntityId(e372));
      ++i372;
    }
  } while (false);
}

void SerializeObjCImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal72(es.EntityId(e.ClassInterface()));
  do {
    auto v365 = e.PropertyImplementations();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal73(es.EntityId(e.CategoryDeclaration()));
  b.setVal74(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal73(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal74(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v79 = e.ObjCRuntimeNameAsString();
  std::string s79(v79.data(), v79.size());
  b.setVal79(s79);
  b.setVal83(es.EntityId(e.SuperClass()));
  b.setVal85(es.EntityId(e.SuperClassToken()));
  b.setVal80(e.HasDestructors());
  b.setVal81(e.HasNonZeroConstructors());
  do {
    auto v366 = e.InstanceVariables();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal62(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeNamespaceAliasDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal62(es.EntityId(e.AliasToken()));
  b.setVal63(es.EntityId(e.AliasedNamespace()));
  b.setVal64(es.EntityId(e.NamespaceToken()));
  b.setVal72(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v56 = e.ChildrenExpression();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  b.setVal54(es.EntityId(e.ExtendingDeclaration()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal62(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v56 = e.IdentifierTokens();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
  auto v54 = e.FriendDeclaration();
  if (v54) {
    if (auto id54 = es.EntityId(v54.value())) {
      b.setVal54(id54);
      b.setVal55(true);
    } else {
      b.setVal55(false);
    }
  } else {
    b.setVal55(false);
  }
  b.setVal62(es.EntityId(e.FriendToken()));
  b.setVal63(es.EntityId(e.FriendType()));
  b.setVal58(e.IsUnsupportedFriend());
  do {
    auto v86 = e.FriendTypeTemplateParameterLists();
    auto sv86 = b.initVal86(static_cast<unsigned>(v86.size()));
    auto i86 = 0u;
    for (const auto &e86 : v86) {
      auto o86 = es.next_pseudo_entity_offset++;
      sv86.set(i86, o86);
      SerializeTemplateParameterList(es, es.pseudo_builder[o86], e86);
      ++i86;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.AssemblyToken()));
  b.setVal62(es.EntityId(e.AssemblyString()));
  b.setVal63(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeExportDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal54(es.EntityId(e.ExportToken()));
  b.setVal62(es.EntityId(e.RBraceToken()));
  b.setVal55(e.HasBraces());
  pasta::DeclContext dc56(e);
  auto v56 = dc56.AlreadyLoadedDeclarations();
  auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
  auto i56 = 0u;
  for (const pasta::Decl &e56 : v56) {
    sv56.set(i56, es.EntityId(e56));
    ++i56;
  }
}

void SerializeEmptyDecl(EntitySerializer &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
