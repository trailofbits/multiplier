// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Serialize.h"

#include <multiplier/RPC.capnp.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include "EntityMapper.h"

namespace indexer {

void SerializeTemplateParameterList(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
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

void SerializeTemplateArgument(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
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

void SerializeCXXBaseSpecifier(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
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

void SerializeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::Type &e) {
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

void SerializeTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsParameterPack());
  b.setVal309(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
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
      sv311.set(i311, es.PseudoId(e311));
      ++i311;
    }
  } while (false);
}

void SerializeTagType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal308(e.IsBeingDefined());
}

void SerializeRecordType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal309(e.HasConstFields());
  b.setVal310(e.IsSugared());
}

void SerializeEnumType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal309(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ReplacedParameter()));
  b.setVal312(es.EntityId(e.ReplacementType()));
  b.setVal308(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ReplacedParameter()));
  b.setVal308(e.IsSugared());
}

void SerializeReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal308(e.IsInnerReference());
  b.setVal309(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializeLValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializePointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializePipeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsReadOnly());
  b.setVal309(e.IsSugared());
}

void SerializeParenType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.InnerType()));
  b.setVal308(e.IsSugared());
}

void SerializePackExpansionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
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

void SerializeObjCTypeParamType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeObjCObjectType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
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

void SerializeObjCInterfaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal330(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
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

void SerializeMemberPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
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

void SerializeMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  b.setVal312(es.EntityId(e.AttributeToken()));
  b.setVal314(es.EntityId(e.ColumnExpression()));
  b.setVal329(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
}

void SerializeMacroQualifiedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ModifiedType()));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeInjectedClassNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
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

void SerializeFunctionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
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

void SerializeFunctionProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
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

void SerializeFunctionNoProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal312(es.EntityId(e.Desugar()));
  b.setVal320(e.IsSugared());
}

void SerializeExtIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSigned());
  b.setVal309(e.IsSugared());
  b.setVal310(e.IsUnsigned());
}

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
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

void SerializeDependentSizedExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
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

void SerializeDependentExtIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentExtIntType &e) {
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

void SerializeDependentAddressSpaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.AddrSpaceExpression()));
  b.setVal312(es.EntityId(e.AttributeToken()));
  b.setVal308(e.IsSugared());
}

void SerializeDeducedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ResolvedType()));
  b.setVal308(e.IsDeduced());
  b.setVal309(e.IsSugared());
}

void SerializeDeducedTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e);
}

void SerializeAutoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AutoType &e) {
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
      sv311.set(i311, es.PseudoId(e311));
      ++i311;
    }
  } while (false);
  b.setVal312(es.EntityId(e.TypeConstraintConcept()));
  b.setVal310(e.IsConstrained());
  b.setVal317(e.IsDecltypeAuto());
}

void SerializeDecltypeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingExpression()));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeComplexType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal308(e.IsSugared());
}

void SerializeBuiltinType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
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

void SerializeBlockPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
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

void SerializeAtomicType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ValueType()));
  b.setVal308(e.IsSugared());
}

void SerializeArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
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

void SerializeIncompleteArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal307(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
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

void SerializeConstantArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
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

void SerializeAdjustedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ResolvedType()));
  b.setVal312(es.EntityId(e.OriginalType()));
  b.setVal308(e.IsSugared());
}

void SerializeDecayedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(es, b, e);
}

void SerializeTypeWithKeyword(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
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

void SerializeDependentTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
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
      sv311.set(i311, es.PseudoId(e311));
      ++i311;
    }
  } while (false);
}

void SerializeDependentNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.ElementType()));
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal308(e.IsSugared());
}

void SerializeExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(es, b, e);
}

void SerializeUnresolvedUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeUnaryTransformType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
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

void SerializeTypedefType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.Declaration()));
  b.setVal308(e.IsSugared());
}

void SerializeTypeOfType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
}

void SerializeTypeOfExprType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.UnderlyingExpression()));
  b.setVal308(e.IsSugared());
}

void SerializeStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
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

void SerializeSEHTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ExceptHandler()));
  b.setVal11(es.EntityId(e.FinallyHandler()));
  b.setVal12(es.EntityId(e.Handler()));
  b.setVal13(e.IsCXXTry());
  b.setVal14(es.EntityId(e.TryBlock()));
  b.setVal15(es.EntityId(e.TryToken()));
}

void SerializeSEHLeaveStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.LeaveToken()));
}

void SerializeSEHFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  b.setVal11(es.EntityId(e.FinallyToken()));
}

void SerializeSEHExceptStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  b.setVal11(es.EntityId(e.ExceptToken()));
  b.setVal12(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
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

void SerializeObjCForCollectionStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Collection()));
  b.setVal12(es.EntityId(e.Element()));
  b.setVal14(es.EntityId(e.ForToken()));
  b.setVal15(es.EntityId(e.RParenToken()));
}

void SerializeObjCAutoreleasePoolStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtToken()));
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
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

void SerializeObjCAtThrowStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ThrowExpression()));
  b.setVal11(es.EntityId(e.ThrowToken()));
}

void SerializeObjCAtSynchronizedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtSynchronizedToken()));
  b.setVal11(es.EntityId(e.SynchBody()));
  b.setVal12(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtFinallyToken()));
  b.setVal11(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AtCatchToken()));
  b.setVal11(es.EntityId(e.CatchBody()));
  b.setVal12(es.EntityId(e.CatchParameterDeclaration()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal13(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.AssociatedStatement()));
  b.setVal11(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal12(es.EntityId(e.RawStatement()));
  b.setVal14(es.EntityId(e.StructuredBlock()));
  b.setVal13(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TargetCallToken()));
}

void SerializeOMPDepobjDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCriticalDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancellationPointDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPBarrierDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPAtomicDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.Expression()));
  b.setVal18(es.EntityId(e.UpdateExpression()));
  b.setVal19(es.EntityId(e.V()));
  b.setVal20(es.EntityId(e.X()));
  b.setVal21(e.IsPostfixUpdate());
  b.setVal22(e.IsXLHSInRHSPart());
}

void SerializeOMPTeamsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskyieldDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskwaitDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskgroupDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetEnterDataDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDataDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSingleDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSectionsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPSectionDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPScanDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMasterDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMaskedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPLoopBasedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPUnrollDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPTileDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
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

void SerializeOMPForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal21(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal21(e.HasCancel());
}

void SerializeOMPInteropDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.DistanceFunc()));
  b.setVal11(es.EntityId(e.LoopStatement()));
  b.setVal12(es.EntityId(e.LoopVariableFunc()));
  b.setVal14(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.SemiToken()));
  b.setVal13(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.KeywordToken()));
  b.setVal11(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
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

void SerializeIfStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
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

void SerializeGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.GotoToken()));
  b.setVal11(es.EntityId(e.Label()));
  b.setVal12(es.EntityId(e.LabelToken()));
}

void SerializeForStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
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

void SerializeDoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  b.setVal12(es.EntityId(e.DoToken()));
  b.setVal14(es.EntityId(e.RParenToken()));
  b.setVal15(es.EntityId(e.WhileToken()));
}

void SerializeDeclStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
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

void SerializeCoroutineBodyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
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

void SerializeCoreturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.KeywordToken()));
  b.setVal11(es.EntityId(e.Operand()));
  b.setVal12(es.EntityId(e.PromiseCall()));
  b.setVal13(e.IsImplicit());
}

void SerializeContinueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.ContinueToken()));
}

void SerializeCompoundStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
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

void SerializeCapturedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.CapturedDeclaration()));
  b.setVal11(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal62(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal12(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
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

void SerializeCXXForRangeStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
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

void SerializeCXXCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
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

void SerializeBreakStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.BreakToken()));
}

void SerializeAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
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

void SerializeMSAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
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

void SerializeGCCAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
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

void SerializeWhileStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
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

void SerializeValueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
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

void SerializeLabelStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal11(es.EntityId(e.Declaration()));
  b.setVal12(es.EntityId(e.IdentifierToken()));
  auto v63 = e.Name();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal14(es.EntityId(e.SubStatement()));
  b.setVal16(e.IsSideEntry());
}

void SerializeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
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

void SerializeDesignatedInitUpdateExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
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

void SerializeDependentScopeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LAngleToken()));
  b.setVal39(es.EntityId(e.RAngleToken()));
  b.setVal40(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.KeywordToken()));
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal40(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
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

void SerializeCoroutineSuspendExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.KeywordToken()));
  b.setVal40(es.EntityId(e.OpaqueValue()));
  b.setVal41(es.EntityId(e.ReadyExpression()));
  b.setVal42(es.EntityId(e.ResumeExpression()));
  b.setVal43(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal44(es.EntityId(e.Operand()));
  b.setVal98(e.IsImplicit());
}

void SerializeCoyieldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal44(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SrcExpression()));
  b.setVal41(es.EntityId(e.TypeSourceInfo()));
}

void SerializeConceptSpecializationExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v105 = e.TemplateArguments();
    auto sv105 = b.initVal105(static_cast<unsigned>(v105.size()));
    auto i105 = 0u;
    for (const auto &e105 : v105) {
      sv105.set(i105, es.PseudoId(e105));
      ++i105;
    }
  } while (false);
  b.setVal98(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Initializer()));
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.TypeSourceInfo()));
  b.setVal98(e.IsFileScope());
}

void SerializeChooseExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
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

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
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

void SerializeImplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal101(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal42(es.EntityId(e.TypeAsWritten()));
  b.setVal43(es.EntityId(e.TypeInfoAsWritten()));
}

void SerializeCXXNamedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
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

void SerializeCXXDynamicCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal101(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXAddrspaceCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXStaticCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXReinterpretCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXFunctionalCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal44(es.EntityId(e.LParenToken()));
  b.setVal45(es.EntityId(e.RParenToken()));
  b.setVal101(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal44(es.EntityId(e.LParenToken()));
  b.setVal45(es.EntityId(e.RParenToken()));
}

void SerializeBuiltinBitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  b.setVal44(es.EntityId(e.BridgeKeywordToken()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal45(es.EntityId(e.LParenToken()));
}

void SerializeCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
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

void SerializeCXXOperatorCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal43(es.EntityId(e.OperatorToken()));
  b.setVal109(e.IsAssignmentOperation());
  b.setVal110(e.IsComparisonOperation());
  b.setVal111(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
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

void SerializeCUDAKernelCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.CookedLiteral()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  b.setVal44(es.EntityId(e.UDSuffixToken()));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
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

void SerializeCXXUnresolvedConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
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

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
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

void SerializeCXXThrowExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
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

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.RParenToken()));
  b.setVal39(es.EntityId(e.TypeSourceInfo()));
}

void SerializeCXXRewrittenBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
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

void SerializeCXXPseudoDestructorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
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

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal98(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
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

void SerializeCXXInheritedCtorInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ConstructsVirtualBase());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal38(es.EntityId(e.Constructor()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal99(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
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

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
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

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal99(e.IsArrayForm());
  b.setVal100(e.IsArrayFormAsWritten());
  b.setVal101(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
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

void SerializeCXXDefaultArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.UsedToken()));
}

void SerializeCXXConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
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

void SerializeCXXTemporaryObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
  b.setVal42(es.EntityId(e.TypeSourceInfo()));
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BlockDeclaration()));
  b.setVal39(es.EntityId(e.Body()));
  b.setVal40(es.EntityId(e.CaretToken()));
  b.setVal41(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
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

void SerializeCompoundAssignOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
  b.setVal41(es.EntityId(e.ComputationLHSType()));
  b.setVal42(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
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

void SerializeAsTypeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DimensionExpression()));
  b.setVal39(es.EntityId(e.QueriedType()));
  b.setVal40(es.EntityId(e.QueriedTypeSourceInfo()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RBracketToken()));
  b.setVal42(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AmpAmpToken()));
  b.setVal39(es.EntityId(e.Label()));
  b.setVal40(es.EntityId(e.LabelToken()));
}

void SerializeAbstractConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ColonToken()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.FalseExpression()));
  b.setVal41(es.EntityId(e.QuestionToken()));
  b.setVal42(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.LHS()));
  b.setVal44(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.Common()));
  b.setVal44(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.WrittenTypeInfo()));
  b.setVal98(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
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

void SerializeUnaryExprOrTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
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

void SerializeTypoExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
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

void SerializeSubstNonTypeTemplateParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ParameterPack()));
  b.setVal39(es.EntityId(e.ParameterPackToken()));
}

void SerializeSubstNonTypeTemplateParmExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.NameToken()));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
  b.setVal98(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
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

void SerializeStmtExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v63 = e.BuiltinString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsIntType());
  b.setVal99(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
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
      sv105.set(i105, es.PseudoId(e105));
      ++i105;
    }
  } while (false);
  b.setVal41(es.EntityId(e.RParenToken()));
  b.setVal100(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BuiltinToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeSYCLUniqueStableNameExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal63(e.ComputeName());
  b.setVal38(es.EntityId(e.LParenToken()));
  b.setVal39(es.EntityId(e.Token()));
  b.setVal40(es.EntityId(e.RParenToken()));
  b.setVal41(es.EntityId(e.TypeSourceInfo()));
}

void SerializeRequiresExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
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

void SerializeRecoveryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
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

void SerializePseudoObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
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

void SerializePredefinedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.FunctionName()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v63 = e.IdentifierKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal39(es.EntityId(e.Token()));
}

void SerializeParenListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
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

void SerializeParenExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LParen()));
  b.setVal39(es.EntityId(e.RParen()));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
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

void SerializeOverloadExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LAngleToken()));
  b.setVal39(es.EntityId(e.NameToken()));
  b.setVal40(es.EntityId(e.NamingClass()));
  b.setVal41(es.EntityId(e.RAngleToken()));
  b.setVal42(es.EntityId(e.TemplateKeywordToken()));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  b.setVal45(es.EntityId(e.MemberToken()));
  b.setVal46(es.EntityId(e.OperatorToken()));
  b.setVal100(e.HasUnresolvedUsing());
  b.setVal101(e.IsArrow());
  b.setVal102(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal100(e.IsOverloaded());
  b.setVal101(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal98(e.IsUnique());
}

void SerializeOffsetOfExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.OperatorToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
  b.setVal40(es.EntityId(e.TypeSourceInfo()));
}

void SerializeObjCSubscriptRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal39(es.EntityId(e.BaseExpression()));
  b.setVal40(es.EntityId(e.KeyExpression()));
  b.setVal41(es.EntityId(e.RBracket()));
  b.setVal98(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.RParenToken()));
}

void SerializeObjCProtocolExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.Protocol()));
  b.setVal40(es.EntityId(e.ProtocolIdToken()));
  b.setVal41(es.EntityId(e.RParenToken()));
}

void SerializeObjCPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
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

void SerializeObjCMessageExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
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

void SerializeObjCIvarRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Declaration()));
  b.setVal40(es.EntityId(e.Token()));
  b.setVal41(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.BaseTokenEnd()));
  b.setVal40(es.EntityId(e.IsaMemberToken()));
  b.setVal41(es.EntityId(e.OperationToken()));
  b.setVal98(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal98(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.EncodedType()));
  b.setVal40(es.EntityId(e.EncodedTypeSourceInfo()));
  b.setVal41(es.EntityId(e.RParenToken()));
}

void SerializeObjCDictionaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtToken()));
  b.setVal39(es.EntityId(e.BoxingMethod()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal98(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
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

void SerializeOMPIteratorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.IteratorKwToken()));
  b.setVal39(es.EntityId(e.LParenToken()));
  b.setVal40(es.EntityId(e.RParenToken()));
}

void SerializeOMPArrayShapingExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
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

void SerializeOMPArraySectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColonTokenFirst()));
  b.setVal40(es.EntityId(e.ColonTokenSecond()));
  b.setVal41(es.EntityId(e.Length()));
  b.setVal42(es.EntityId(e.LowerBound()));
  b.setVal43(es.EntityId(e.RBracketToken()));
  b.setVal44(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
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

void SerializeMatrixSubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  b.setVal40(es.EntityId(e.RBracketToken()));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal98(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
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

void SerializeMSPropertySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.RBracketToken()));
}

void SerializeMSPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.MemberToken()));
  b.setVal40(es.EntityId(e.PropertyDeclaration()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
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
    b.setVal112(es.PseudoId(v112.value()));
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

void SerializeIntegerLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeInitListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
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
  auto v111 = e.IsTransparent();
  if (v111) {
    b.setVal111(static_cast<bool>(v111.value()));
    b.setVal113(true);
  } else {
    b.setVal113(false);
  }
}

void SerializeImplicitValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
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

void SerializeGNUNullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.TokenToken()));
}

void SerializeFunctionParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
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

void SerializeFullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal98(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal98(e.HasAPValueResult());
  b.setVal99(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
  b.setVal98(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Token()));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ContainsDuplicateElements());
  b.setVal38(es.EntityId(e.AccessorToken()));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal99(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.QueriedExpression()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal98(e.Value());
}

void SerializeAttributedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal11(es.EntityId(e.AttributeToken()));
  b.setVal12(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
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

void SerializeSwitchCase(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
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

void SerializeDefaultStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal15(es.EntityId(e.DefaultToken()));
}

void SerializeCaseStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
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

void SerializeDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(static_cast<unsigned char>(mx::FromPasta(e.Access())));
  b.setVal3(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  b.setVal4(es.EntityId(e.BeginToken()));
  b.setVal5(es.EntityId(e.CanonicalDeclaration()));
  auto v6 = e.DescribedTemplateParameters();
  if (v6) {
    b.setVal6(es.PseudoId(v6.value()));
    b.setVal7(true);
  } else {
    b.setVal7(false);
  }
  b.setVal8(es.EntityId(e.EndToken()));
  b.setVal9(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v10 = e.FunctionType();
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
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v13 = e.NonClosureContext();
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
  b.setVal15(e.HasAttributes());
  b.setVal16(e.HasDefiningAttribute());
  b.setVal17(e.HasOwningModule());
  b.setVal18(e.HasTagIdentifierNamespace());
  b.setVal19(e.IsCanonicalDeclaration());
  b.setVal20(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal21(e.IsDeprecated());
  b.setVal22(e.IsFirstDeclaration());
  b.setVal23(e.IsFunctionOrFunctionTemplate());
  b.setVal24(e.IsImplicit());
  b.setVal25(e.IsInAnonymousNamespace());
  b.setVal26(e.IsInLocalScopeForInstantiation());
  b.setVal27(e.IsInStdNamespace());
  b.setVal28(e.IsInvalidDeclaration());
  b.setVal29(e.IsModulePrivate());
  b.setVal30(e.IsOutOfLine());
  b.setVal31(e.IsParameterPack());
  b.setVal32(e.IsReferenced());
  b.setVal33(e.IsTemplateDeclaration());
  b.setVal34(e.IsTemplateParameter());
  b.setVal35(e.IsTemplateParameterPack());
  b.setVal36(e.IsTemplated());
  b.setVal37(e.IsThisDeclarationReferenced());
  b.setVal38(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal39(e.IsUnavailable());
  b.setVal40(e.IsUnconditionallyVisible());
  b.setVal41(e.IsUsed());
  b.setVal42(e.IsWeakImported());
  do {
    auto v43 = e.Redeclarations();
    auto sv43 = b.initVal43(static_cast<unsigned>(v43.size()));
    auto i43 = 0u;
    for (const auto &e43 : v43) {
      sv43.set(i43, es.EntityId(e43));
      ++i43;
    }
  } while (false);
  b.setVal44(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal45(es.EntityId(e.Token()));
  if (auto r46 = e.TokenRange(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.Specialization()));
  b.setVal49(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.ContextParameter()));
  b.setVal49(e.IsNothrow());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  pasta::DeclContext dc51(e);
  auto v51 = dc51.AlreadyLoadedDeclarations();
  auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
  auto i51 = 0u;
  for (const pasta::Decl &e51 : v51) {
    sv51.set(i51, es.EntityId(e51));
    ++i51;
  }
}

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal49(e.BlockMissingReturnType());
  b.setVal52(e.CanAvoidCopyToHeap());
  b.setVal53(e.CapturesCXXThis());
  b.setVal54(e.DoesNotEscape());
  auto v48 = e.BlockManglingContextDeclaration();
  if (v48) {
    if (auto id48 = es.EntityId(v48.value())) {
      b.setVal48(id48);
      b.setVal55(true);
    } else {
      b.setVal55(false);
    }
  } else {
    b.setVal55(false);
  }
  b.setVal56(es.EntityId(e.CaretToken()));
  b.setVal57(es.EntityId(e.CompoundBody()));
  b.setVal58(es.EntityId(e.SignatureAsWritten()));
  b.setVal59(e.HasCaptures());
  b.setVal60(e.IsConversionFromLambda());
  b.setVal61(e.IsVariadic());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  do {
    auto v51 = e.ParameterDeclarations();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  pasta::DeclContext dc62(e);
  auto v62 = dc62.AlreadyLoadedDeclarations();
  auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
  auto i62 = 0u;
  for (const pasta::Decl &e62 : v62) {
    sv62.set(i62, es.EntityId(e62));
    ++i62;
  }
}

void SerializeAccessSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.AccessSpecifierToken()));
  b.setVal56(es.EntityId(e.ColonToken()));
}

void SerializeOMPDeclarativeDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  do {
    auto v50 = e.Varlists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeOMPRequiresDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
  do {
    auto v50 = e.Varlists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.AssertExpression()));
  b.setVal56(es.EntityId(e.Message()));
  b.setVal57(es.EntityId(e.RParenToken()));
  b.setVal49(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializePragmaDetectMismatchDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v63 = e.Name();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v64 = e.Value();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
}

void SerializePragmaCommentDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v63 = e.Argument();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.GetterCXXConstructor()));
  b.setVal56(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal57(es.EntityId(e.PropertyDeclaration()));
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal58(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal66(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal67(es.EntityId(e.SetterCXXAssignment()));
  b.setVal68(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal49(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.LinkageInternal())));
  b.setVal63(e.Name());
  auto v70 = e.ObjCFStringFormattingFamily();
  if (v70) {
    b.setVal70(static_cast<unsigned char>(v70.value()));
    b.setVal49(true);
  } else {
    b.setVal49(false);
  }
  b.setVal64(e.QualifiedNameAsString());
  b.setVal48(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal52(e.HasExternalFormalLinkage());
  b.setVal53(e.HasLinkage());
  b.setVal54(e.HasLinkageBeenComputed());
  b.setVal55(e.IsCXXClassMember());
  b.setVal59(e.IsCXXInstanceMember());
  b.setVal60(e.IsExternallyDeclarable());
  b.setVal61(e.IsExternallyVisible());
  b.setVal72(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v73 = e.MSAssemblyLabel();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal56(es.EntityId(e.Statement()));
  b.setVal74(e.IsGnuLocal());
  b.setVal75(e.IsMSAssemblyLabel());
  b.setVal76(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v50 = e.Shadows();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal56(es.EntityId(e.EnumDeclaration()));
  b.setVal57(es.EntityId(e.EnumToken()));
  b.setVal58(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal56(es.EntityId(e.UsingToken()));
  b.setVal74(e.HasTypename());
  b.setVal75(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.Type()));
  b.setVal74(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal57(es.EntityId(e.EllipsisToken()));
  b.setVal58(es.EntityId(e.UsingToken()));
  b.setVal75(e.IsAccessDeclaration());
  b.setVal76(e.IsPackExpansion());
}

void SerializeTemplateParamObjectDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal57(es.EntityId(e.Combiner()));
  b.setVal58(es.EntityId(e.CombinerIn()));
  b.setVal66(es.EntityId(e.CombinerOut()));
  b.setVal67(es.EntityId(e.InitializerOriginal()));
  b.setVal68(es.EntityId(e.InitializerPrivate()));
  b.setVal77(es.EntityId(e.Initializer()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  b.setVal79(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeMSGuidDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  do {
    auto v50 = e.Chain();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  auto v57 = e.AnonymousField();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
  auto v58 = e.VariableDeclaration();
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
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v57 = e.InitializerExpression();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal57(es.EntityId(e.InnerTokenStart()));
  b.setVal58(es.EntityId(e.OuterTokenStart()));
  auto v66 = e.TrailingRequiresClause();
  if (v66) {
    if (auto id66 = es.EntityId(v66.value())) {
      b.setVal66(id66);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
  auto v67 = e.TypeSourceInfo();
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
  b.setVal68(es.EntityId(e.TypeSpecEndToken()));
  b.setVal77(es.EntityId(e.TypeSpecStartToken()));
  do {
    auto v80 = e.TemplateParameterLists();
    auto sv80 = b.initVal80(static_cast<unsigned>(v80.size()));
    auto i80 = 0u;
    for (const auto &e80 : v80) {
      sv80.set(i80, es.PseudoId(e80));
      ++i80;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v79 = e.ActingDefinition();
  if (v79) {
    if (auto id79 = es.EntityId(v79.value())) {
      b.setVal79(id79);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  auto v82 = e.Initializer();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal83(true);
    } else {
      b.setVal83(false);
    }
  } else {
    b.setVal83(false);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v84 = e.InitializingDeclaration();
  if (v84) {
    if (auto id84 = es.EntityId(v84.value())) {
      b.setVal84(id84);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
  auto v86 = e.InstantiatedFromStaticDataMember();
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
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal89(es.EntityId(e.PointOfInstantiation()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v94 = e.TemplateInstantiationPattern();
  if (v94) {
    if (auto id94 = es.EntityId(v94.value())) {
      b.setVal94(id94);
      b.setVal95(true);
    } else {
      b.setVal95(false);
    }
  } else {
    b.setVal95(false);
  }
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal98(e.HasConstantInitialization());
  b.setVal99(e.HasDependentAlignment());
  b.setVal100(e.HasExternalStorage());
  b.setVal101(e.HasGlobalStorage());
  auto v102 = e.HasICEInitializer();
  if (v102) {
    b.setVal102(static_cast<bool>(v102.value()));
    b.setVal103(true);
  } else {
    b.setVal103(false);
  }
  b.setVal104(e.HasInitializer());
  b.setVal105(e.HasLocalStorage());
  b.setVal106(e.IsARCPseudoStrong());
  b.setVal107(e.IsCXXForRangeDeclaration());
  b.setVal108(e.IsConstexpr());
  b.setVal109(e.IsDirectInitializer());
  b.setVal110(e.IsEscapingByref());
  b.setVal111(e.IsExceptionVariable());
  b.setVal112(e.IsExternC());
  b.setVal113(e.IsFileVariableDeclaration());
  b.setVal114(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal115(e.IsInExternCContext());
  b.setVal116(e.IsInExternCXXContext());
  b.setVal117(e.IsInitializerCapture());
  b.setVal118(e.IsInline());
  b.setVal119(e.IsInlineSpecified());
  b.setVal120(e.IsKnownToBeDefined());
  b.setVal121(e.IsLocalVariableDeclaration());
  b.setVal122(e.IsLocalVariableDeclarationOrParm());
  b.setVal123(e.IsNRVOVariable());
  b.setVal124(e.IsNoDestroy());
  b.setVal125(e.IsNonEscapingByref());
  b.setVal126(e.IsObjCForDeclaration());
  b.setVal127(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal128(e.IsStaticDataMember());
  b.setVal129(e.IsStaticLocal());
  b.setVal130(e.IsThisDeclarationADemotedDefinition());
  b.setVal131(e.IsUsableInConstantExpressions());
  b.setVal132(e.MightBeUsableInConstantExpressions());
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v134 = e.DefaultArgument();
  if (v134) {
    if (auto id134 = es.EntityId(v134.value())) {
      b.setVal134(id134);
      b.setVal135(true);
    } else {
      b.setVal135(false);
    }
  } else {
    b.setVal135(false);
  }
  if (auto r136 = e.DefaultArgumentRange(); auto rs136 = r136.Size()) {
    b.setVal136(es.EntityId(r136[0]));
    b.setVal137(es.EntityId(r136[rs136 - 1u]));
  } else {
    b.setVal136(0);
    b.setVal137(0);
  }
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal139(es.EntityId(e.OriginalType()));
  auto v140 = e.UninstantiatedDefaultArgument();
  if (v140) {
    if (auto id140 = es.EntityId(v140.value())) {
      b.setVal140(id140);
      b.setVal141(true);
    } else {
      b.setVal141(false);
    }
  } else {
    b.setVal141(false);
  }
  b.setVal142(e.HasDefaultArgument());
  b.setVal143(e.HasInheritedDefaultArgument());
  b.setVal144(e.HasUninstantiatedDefaultArgument());
  b.setVal145(e.HasUnparsedDefaultArgument());
  b.setVal146(e.IsDestroyedInCallee());
  b.setVal147(e.IsKNRPromoted());
  b.setVal148(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v50 = e.Bindings();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal134(es.EntityId(e.ExternToken()));
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v149 = e.TemplateArguments();
    auto sv149 = b.initVal149(static_cast<unsigned>(v149.size()));
    auto i149 = 0u;
    for (const auto &e149 : v149) {
      sv149.set(i149, es.PseudoId(e149));
      ++i149;
    }
  } while (false);
  do {
    auto v150 = e.TemplateInstantiationArguments();
    auto sv150 = b.initVal150(static_cast<unsigned>(v150.size()));
    auto i150 = 0u;
    for (const auto &e150 : v150) {
      sv150.set(i150, es.PseudoId(e150));
      ++i150;
    }
  } while (false);
  b.setVal136(es.EntityId(e.TemplateKeywordToken()));
  b.setVal137(es.EntityId(e.TypeAsWritten()));
  b.setVal135(e.IsClassScopeExplicitSpecialization());
  b.setVal141(e.IsExplicitInstantiationOrSpecialization());
  b.setVal142(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeNonTypeTemplateParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.DefaultArgumentWasInherited());
  b.setVal79(es.EntityId(e.DefaultArgument()));
  b.setVal82(es.EntityId(e.DefaultArgumentToken()));
  b.setVal84(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal83(e.HasDefaultArgument());
  b.setVal85(e.HasPlaceholderTypeConstraint());
  b.setVal87(e.IsExpandedParameterPack());
  b.setVal95(e.IsPackExpansion());
  do {
    auto v50 = e.ExpansionTypes();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  do {
    auto v51 = e.ExpansionTypeSourceInfos();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal81(e.HasGetter());
  b.setVal83(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v81 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v81) {
    b.setVal81(static_cast<bool>(v81.value()));
    b.setVal83(true);
  } else {
    b.setVal83(false);
  }
  b.setVal85(e.DoesThisDeclarationHaveABody());
  b.setVal79(es.EntityId(e.CallResultType()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal82(es.EntityId(e.DeclaredReturnType()));
  auto v84 = e.Definition();
  if (v84) {
    if (auto id84 = es.EntityId(v84.value())) {
      b.setVal84(id84);
      b.setVal87(true);
    } else {
      b.setVal87(false);
    }
  } else {
    b.setVal87(false);
  }
  b.setVal86(es.EntityId(e.EllipsisToken()));
  if (auto r89 = e.ExceptionSpecSourceRange(); auto rs89 = r89.Size()) {
    b.setVal89(es.EntityId(r89[0]));
    b.setVal94(es.EntityId(r89[rs89 - 1u]));
  } else {
    b.setVal89(0);
    b.setVal94(0);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v134 = e.InstantiatedFromMemberFunction();
  if (v134) {
    if (auto id134 = es.EntityId(v134.value())) {
      b.setVal134(id134);
      b.setVal95(true);
    } else {
      b.setVal95(false);
    }
  } else {
    b.setVal95(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v151 = e.ODRHash();
  if (v151) {
    b.setVal151(static_cast<unsigned>(v151.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r136 = e.ParametersSourceRange(); auto rs136 = r136.Size()) {
    b.setVal136(es.EntityId(r136[0]));
    b.setVal137(es.EntityId(r136[rs136 - 1u]));
  } else {
    b.setVal136(0);
    b.setVal137(0);
  }
  b.setVal139(es.EntityId(e.PointOfInstantiation()));
  b.setVal140(es.EntityId(e.ReturnType()));
  if (auto r152 = e.ReturnTypeSourceRange(); auto rs152 = r152.Size()) {
    b.setVal152(es.EntityId(r152[0]));
    b.setVal153(es.EntityId(r152[rs152 - 1u]));
  } else {
    b.setVal152(0);
    b.setVal153(0);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v154 = e.TemplateInstantiationPattern();
  if (v154) {
    if (auto id154 = es.EntityId(v154.value())) {
      b.setVal154(id154);
      b.setVal99(true);
    } else {
      b.setVal99(false);
    }
  } else {
    b.setVal99(false);
  }
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal100(e.HasImplicitReturnZero());
  b.setVal101(e.HasInheritedPrototype());
  b.setVal102(e.HasOneParameterOrDefaultArguments());
  b.setVal103(e.HasPrototype());
  b.setVal104(e.HasSkippedBody());
  b.setVal105(e.HasTrivialBody());
  b.setVal106(e.HasWrittenPrototype());
  b.setVal107(e.InstantiationIsPending());
  b.setVal108(e.IsCPUDispatchMultiVersion());
  b.setVal109(e.IsCPUSpecificMultiVersion());
  b.setVal110(e.IsConsteval());
  b.setVal111(e.IsConstexpr());
  b.setVal112(e.IsConstexprSpecified());
  b.setVal113(e.IsDefaulted());
  b.setVal114(e.IsDeleted());
  b.setVal115(e.IsDeletedAsWritten());
  b.setVal116(e.IsDestroyingOperatorDelete());
  b.setVal117(e.IsExplicitlyDefaulted());
  b.setVal118(e.IsExternC());
  b.setVal119(e.IsFunctionTemplateSpecialization());
  b.setVal120(e.IsGlobal());
  b.setVal121(e.IsImplicitlyInstantiable());
  b.setVal122(e.IsInExternCContext());
  b.setVal123(e.IsInExternCXXContext());
  b.setVal124(e.IsInlineBuiltinDeclaration());
  auto v125 = e.IsInlineDefinitionExternallyVisible();
  if (v125) {
    b.setVal125(static_cast<bool>(v125.value()));
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  b.setVal127(e.IsInlineSpecified());
  b.setVal128(e.IsInlined());
  b.setVal129(e.IsLateTemplateParsed());
  auto v130 = e.IsMSExternInline();
  if (v130) {
    b.setVal130(static_cast<bool>(v130.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  b.setVal132(e.IsMSVCRTEntryPoint());
  b.setVal135(e.IsMain());
  b.setVal141(e.IsMultiVersion());
  b.setVal142(e.IsNoReturn());
  b.setVal143(e.IsOverloadedOperator());
  b.setVal144(e.IsPure());
  b.setVal145(e.IsReplaceableGlobalAllocationFunction());
  auto v146 = e.IsReservedGlobalPlacementOperator();
  if (v146) {
    b.setVal146(static_cast<bool>(v146.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  b.setVal148(e.IsStatic());
  b.setVal155(e.IsTargetMultiVersion());
  b.setVal156(e.IsTemplateInstantiation());
  b.setVal157(e.IsThisDeclarationADefinition());
  b.setVal158(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal159(e.IsTrivial());
  b.setVal160(e.IsTrivialForCall());
  b.setVal161(e.IsUserProvided());
  b.setVal162(e.IsVariadic());
  b.setVal163(e.IsVirtualAsWritten());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal164(e.UsesSEHTry());
  b.setVal165(e.WillHaveBody());
  auto v166 = e.Body();
  if (v166) {
    if (auto id166 = es.EntityId(v166.value())) {
      b.setVal166(id166);
      b.setVal167(true);
    } else {
      b.setVal167(false);
    }
  } else {
    b.setVal167(false);
  }
  pasta::DeclContext dc51(e);
  auto v51 = dc51.AlreadyLoadedDeclarations();
  auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
  auto i51 = 0u;
  for (const pasta::Decl &e51 : v51) {
    sv51.set(i51, es.EntityId(e51));
    ++i51;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal168(es.EntityId(e.Parent()));
  b.setVal138(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal169(es.EntityId(e.ThisObjectType()));
  b.setVal170(es.EntityId(e.ThisType()));
  b.setVal171(e.HasInlineBody());
  b.setVal172(e.IsConst());
  b.setVal173(e.IsCopyAssignmentOperator());
  b.setVal174(e.IsInstance());
  b.setVal175(e.IsLambdaStaticInvoker());
  b.setVal176(e.IsMoveAssignmentOperator());
  b.setVal177(e.IsVirtual());
  b.setVal178(e.IsVolatile());
  do {
    auto v62 = e.OverriddenMethods();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      sv62.set(i62, es.EntityId(e62));
      ++i62;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v179 = e.OperatorDelete();
  if (v179) {
    if (auto id179 = es.EntityId(v179.value())) {
      b.setVal179(id179);
      b.setVal180(true);
    } else {
      b.setVal180(false);
    }
  } else {
    b.setVal180(false);
  }
  auto v181 = e.OperatorDeleteThisArgument();
  if (v181) {
    if (auto id181 = es.EntityId(v181.value())) {
      b.setVal181(id181);
      b.setVal182(true);
    } else {
      b.setVal182(false);
    }
  } else {
    b.setVal182(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal179(es.EntityId(e.ConversionType()));
  b.setVal180(e.IsExplicit());
  b.setVal182(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v179 = e.TargetConstructor();
  if (v179) {
    if (auto id179 = es.EntityId(v179.value())) {
      b.setVal179(id179);
      b.setVal180(true);
    } else {
      b.setVal180(false);
    }
  } else {
    b.setVal180(false);
  }
  b.setVal182(e.IsDefaultConstructor());
  b.setVal183(e.IsDelegatingConstructor());
  b.setVal184(e.IsExplicit());
  b.setVal185(e.IsInheritingConstructor());
  b.setVal186(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal168(es.EntityId(e.CorrespondingConstructor()));
  b.setVal171(e.IsCopyDeductionCandidate());
  b.setVal172(e.IsExplicit());
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v79 = e.BitWidth();
  if (v79) {
    if (auto id79 = es.EntityId(v79.value())) {
      b.setVal79(id79);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  auto v82 = e.CapturedVLAType();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal83(true);
    } else {
      b.setVal83(false);
    }
  } else {
    b.setVal83(false);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v84 = e.InClassInitializer();
  if (v84) {
    if (auto id84 = es.EntityId(v84.value())) {
      b.setVal84(id84);
      b.setVal85(true);
    } else {
      b.setVal85(false);
    }
  } else {
    b.setVal85(false);
  }
  b.setVal86(es.EntityId(e.Parent()));
  b.setVal87(e.HasCapturedVLAType());
  b.setVal95(e.HasInClassInitializer());
  b.setVal98(e.IsAnonymousStructOrUnion());
  b.setVal99(e.IsBitField());
  b.setVal100(e.IsMutable());
  b.setVal101(e.IsUnnamedBitfield());
  b.setVal102(e.IsZeroLengthBitField());
  b.setVal103(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal89(es.EntityId(e.ContainingInterface()));
  b.setVal94(es.EntityId(e.NextInstanceVariable()));
  b.setVal104(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal57(es.EntityId(e.Binding()));
  b.setVal58(es.EntityId(e.DecomposedDeclaration()));
  b.setVal66(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal57(es.EntityId(e.MapperVariableReference()));
  b.setVal58(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.Introducer()));
  auto v57 = e.NextUsingShadowDeclaration();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal74(true);
    } else {
      b.setVal74(false);
    }
  } else {
    b.setVal74(false);
  }
  b.setVal58(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal75(e.ConstructsVirtualBase());
  b.setVal66(es.EntityId(e.ConstructedBaseClass()));
  auto v67 = e.ConstructedBaseClassShadowDeclaration();
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
  b.setVal68(es.EntityId(e.NominatedBaseClass()));
  auto v77 = e.NominatedBaseClassShadowDeclaration();
  if (v77) {
    if (auto id77 = es.EntityId(v77.value())) {
      b.setVal77(id77);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal79(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v50 = e.Expansions();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal56(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.IdentifierToken()));
  b.setVal57(es.EntityId(e.NamespaceKeyToken()));
  b.setVal58(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal66(es.EntityId(e.UsingToken()));
}

void SerializeUnresolvedUsingIfExistsDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v56 = e.TypeForDeclaration();
  if (v56) {
    if (auto id56 = es.EntityId(v56.value())) {
      b.setVal56(id56);
      b.setVal74(true);
    } else {
      b.setVal74(false);
    }
  } else {
    b.setVal74(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal75(e.DefaultArgumentWasInherited());
  b.setVal57(es.EntityId(e.DefaultArgument()));
  b.setVal58(es.EntityId(e.DefaultArgumentInfo()));
  b.setVal66(es.EntityId(e.DefaultArgumentToken()));
  b.setVal76(e.HasDefaultArgument());
  b.setVal81(e.HasTypeConstraint());
  b.setVal83(e.IsExpandedParameterPack());
  b.setVal85(e.IsPackExpansion());
  b.setVal87(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r57 = e.BraceRange(); auto rs57 = r57.Size()) {
    b.setVal57(es.EntityId(r57[0]));
    b.setVal58(es.EntityId(r57[rs57 - 1u]));
  } else {
    b.setVal57(0);
    b.setVal58(0);
  }
  auto v66 = e.Definition();
  if (v66) {
    if (auto id66 = es.EntityId(v66.value())) {
      b.setVal66(id66);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
  b.setVal67(es.EntityId(e.InnerTokenStart()));
  b.setVal68(es.EntityId(e.OuterTokenStart()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v77 = e.TypedefNameForAnonymousDeclaration();
  if (v77) {
    if (auto id77 = es.EntityId(v77.value())) {
      b.setVal77(id77);
      b.setVal76(true);
    } else {
      b.setVal76(false);
    }
  } else {
    b.setVal76(false);
  }
  b.setVal81(e.HasNameForLinkage());
  b.setVal83(e.IsBeingDefined());
  b.setVal85(e.IsClass());
  b.setVal87(e.IsCompleteDefinition());
  b.setVal95(e.IsCompleteDefinitionRequired());
  b.setVal98(e.IsDependentType());
  b.setVal99(e.IsEmbeddedInDeclarator());
  b.setVal100(e.IsEnum());
  b.setVal101(e.IsFreeStanding());
  b.setVal102(e.IsInterface());
  b.setVal103(e.IsStruct());
  b.setVal104(e.IsThisDeclarationADefinition());
  b.setVal105(e.IsUnion());
  b.setVal106(e.MayHaveOutOfDateDefinition());
  do {
    auto v80 = e.TemplateParameterLists();
    auto sv80 = b.initVal80(static_cast<unsigned>(v80.size()));
    auto i80 = 0u;
    for (const auto &e80 : v80) {
      sv80.set(i80, es.PseudoId(e80));
      ++i80;
    }
  } while (false);
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal107(e.CanPassInRegisters());
  do {
    auto v51 = e.Fields();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  auto v79 = e.FindFirstNamedDataMember();
  if (v79) {
    if (auto id79 = es.EntityId(v79.value())) {
      b.setVal79(id79);
      b.setVal108(true);
    } else {
      b.setVal108(false);
    }
  } else {
    b.setVal108(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal109(e.HasFlexibleArrayMember());
  b.setVal110(e.HasLoadedFieldsFromExternalStorage());
  b.setVal111(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal112(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal113(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal114(e.HasObjectMember());
  b.setVal115(e.HasVolatileMember());
  b.setVal116(e.IsAnonymousStructOrUnion());
  b.setVal117(e.IsCapturedRecord());
  b.setVal118(e.IsInjectedClassName());
  b.setVal119(e.IsLambda());
  b.setVal120(e.IsMsStruct());
  b.setVal121(e.IsNonTrivialToPrimitiveCopy());
  b.setVal122(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal123(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal124(e.IsOrContainsUnion());
  b.setVal125(e.IsParameterDestroyedInCallee());
  b.setVal126(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v127 = e.AllowConstDefaultInitializer();
  if (v127) {
    b.setVal127(static_cast<bool>(v127.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  do {
    auto ov149 = e.Bases();
    if (!ov149) {
      b.setVal129(false);
      break;
    }
    b.setVal129(true);
    auto v149 = std::move(*ov149);
    auto sv149 = b.initVal149(static_cast<unsigned>(v149.size()));
    auto i149 = 0u;
    for (const auto &e149 : v149) {
      sv149.set(i149, es.PseudoId(e149));
      ++i149;
    }
  } while (false);
  auto v90 = e.CalculateInheritanceModel();
  if (v90) {
    b.setVal90(static_cast<unsigned char>(v90.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  do {
    auto v62 = e.Constructors();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      sv62.set(i62, es.EntityId(e62));
      ++i62;
    }
  } while (false);
  do {
    auto ov187 = e.Friends();
    if (!ov187) {
      b.setVal131(false);
      break;
    }
    b.setVal131(true);
    auto v187 = std::move(*ov187);
    auto sv187 = b.initVal187(static_cast<unsigned>(v187.size()));
    auto i187 = 0u;
    for (const auto &e187 : v187) {
      sv187.set(i187, es.EntityId(e187));
      ++i187;
    }
  } while (false);
  auto v82 = e.Destructor();
  if (v82) {
    if (auto id82 = es.EntityId(v82.value())) {
      b.setVal82(id82);
      b.setVal132(true);
    } else {
      b.setVal132(false);
    }
  } else {
    b.setVal132(false);
  }
  auto v151 = e.GenericLambdaTemplateParameterList();
  if (v151) {
    b.setVal151(es.PseudoId(v151.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  auto v84 = e.InstantiatedFromMemberClass();
  if (v84) {
    if (auto id84 = es.EntityId(v84.value())) {
      b.setVal84(id84);
      b.setVal141(true);
    } else {
      b.setVal141(false);
    }
  } else {
    b.setVal141(false);
  }
  auto v86 = e.LambdaCallOperator();
  if (v86) {
    if (auto id86 = es.EntityId(v86.value())) {
      b.setVal86(id86);
      b.setVal142(true);
    } else {
      b.setVal142(false);
    }
  } else {
    b.setVal142(false);
  }
  auto v91 = e.LambdaCaptureDefault();
  if (v91) {
    b.setVal91(static_cast<unsigned char>(v91.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v89 = e.LambdaContextDeclaration();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal144(true);
    } else {
      b.setVal144(false);
    }
  } else {
    b.setVal144(false);
  }
  do {
    auto ov188 = e.LambdaExplicitTemplateParameters();
    if (!ov188) {
      b.setVal145(false);
      break;
    }
    b.setVal145(true);
    auto v188 = std::move(*ov188);
    auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
    auto i188 = 0u;
    for (const auto &e188 : v188) {
      sv188.set(i188, es.EntityId(e188));
      ++i188;
    }
  } while (false);
  auto v189 = e.LambdaManglingNumber();
  if (v189) {
    b.setVal189(static_cast<unsigned>(v189.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v94 = e.LambdaTypeInfo();
  if (v94) {
    if (auto id94 = es.EntityId(v94.value())) {
      b.setVal94(id94);
      b.setVal147(true);
    } else {
      b.setVal147(false);
    }
  } else {
    b.setVal147(false);
  }
  auto v92 = e.MSInheritanceModel();
  if (v92) {
    b.setVal92(static_cast<unsigned char>(v92.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v190 = e.NumBases();
  if (v190) {
    b.setVal190(static_cast<unsigned>(v190.value()));
    b.setVal155(true);
  } else {
    b.setVal155(false);
  }
  auto v191 = e.NumVirtualBases();
  if (v191) {
    b.setVal191(static_cast<unsigned>(v191.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v192 = e.ODRHash();
  if (v192) {
    b.setVal192(static_cast<unsigned>(v192.value()));
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v134 = e.TemplateInstantiationPattern();
  if (v134) {
    if (auto id134 = es.EntityId(v134.value())) {
      b.setVal134(id134);
      b.setVal158(true);
    } else {
      b.setVal158(false);
    }
  } else {
    b.setVal158(false);
  }
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v159 = e.HasAnyDependentBases();
  if (v159) {
    b.setVal159(static_cast<bool>(v159.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v161 = e.HasConstexprDefaultConstructor();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v163 = e.HasConstexprDestructor();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasConstexprNonCopyMoveConstructor();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v171 = e.HasCopyAssignmentWithConstParameter();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  auto v173 = e.HasCopyConstructorWithConstParameter();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasDefaultConstructor();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasDefinition();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v180 = e.HasDirectFields();
  if (v180) {
    b.setVal180(static_cast<bool>(v180.value()));
    b.setVal182(true);
  } else {
    b.setVal182(false);
  }
  auto v183 = e.HasFriends();
  if (v183) {
    b.setVal183(static_cast<bool>(v183.value()));
    b.setVal184(true);
  } else {
    b.setVal184(false);
  }
  auto v185 = e.HasInClassInitializer();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v193 = e.HasInheritedAssignment();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasInheritedConstructor();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasIrrelevantDestructor();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasKnownLambdaInternalLinkage();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasMoveAssignment();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasMoveConstructor();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasMutableFields();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonLiteralTypeFieldsOrBases();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialCopyAssignment();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialCopyConstructor();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialCopyConstructorForCall();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialDefaultConstructor();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialDestructor();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasNonTrivialDestructorForCall();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasNonTrivialMoveAssignment();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasNonTrivialMoveConstructor();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasNonTrivialMoveConstructorForCall();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasPrivateFields();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasProtectedFields();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasSimpleCopyAssignment();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasSimpleCopyConstructor();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasSimpleDestructor();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasSimpleMoveAssignment();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasSimpleMoveConstructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialCopyAssignment();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialCopyConstructor();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialCopyConstructorForCall();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialDefaultConstructor();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialDestructor();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasTrivialDestructorForCall();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasTrivialMoveAssignment();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasTrivialMoveConstructor();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasTrivialMoveConstructorForCall();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUninitializedReferenceMember();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredConstructor();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredCopyAssignment();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserDeclaredCopyConstructor();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserDeclaredDestructor();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasUserDeclaredMoveAssignment();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.HasUserDeclaredMoveConstructor();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.HasUserDeclaredMoveOperation();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.HasUserProvidedDefaultConstructor();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.HasVariantMembers();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.ImplicitCopyConstructorHasConstParameter();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsAbstract();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsAggregate();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsAnyDestructorNoReturn();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  auto v289 = e.IsCLike();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  auto v291 = e.IsCXX11StandardLayout();
  if (v291) {
    b.setVal291(static_cast<bool>(v291.value()));
    b.setVal292(true);
  } else {
    b.setVal292(false);
  }
  b.setVal293(e.IsDependentLambda());
  auto v294 = e.IsDynamicClass();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  auto v296 = e.IsEffectivelyFinal();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  auto v298 = e.IsEmpty();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  b.setVal300(e.IsGenericLambda());
  auto v301 = e.IsInterfaceLike();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsLiteral();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v136 = e.IsLocalClass();
  if (v136) {
    if (auto id136 = es.EntityId(v136.value())) {
      b.setVal136(id136);
      b.setVal305(true);
    } else {
      b.setVal305(false);
    }
  } else {
    b.setVal305(false);
  }
  auto v306 = e.IsPOD();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.IsPolymorphic();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.IsStandardLayout();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.IsStructural();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.IsTrivial();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.IsTriviallyCopyable();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.MayBeAbstract();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.MayBeDynamicClass();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.MayBeNonDynamicClass();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  do {
    auto ov326 = e.Methods();
    if (!ov326) {
      b.setVal327(false);
      break;
    }
    b.setVal327(true);
    auto v326 = std::move(*ov326);
    auto sv326 = b.initVal326(static_cast<unsigned>(v326.size()));
    auto i326 = 0u;
    for (const auto &e326 : v326) {
      sv326.set(i326, es.EntityId(e326));
      ++i326;
    }
  } while (false);
  auto v328 = e.NeedsImplicitCopyAssignment();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsImplicitCopyConstructor();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsImplicitDefaultConstructor();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsImplicitDestructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsImplicitMoveAssignment();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsImplicitMoveConstructor();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  auto v344 = e.NeedsOverloadResolutionForDestructor();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  auto v346 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v346) {
    b.setVal346(static_cast<bool>(v346.value()));
    b.setVal347(true);
  } else {
    b.setVal347(false);
  }
  auto v348 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v348) {
    b.setVal348(static_cast<bool>(v348.value()));
    b.setVal349(true);
  } else {
    b.setVal349(false);
  }
  auto v350 = e.NullFieldOffsetIsZero();
  if (v350) {
    b.setVal350(static_cast<bool>(v350.value()));
    b.setVal351(true);
  } else {
    b.setVal351(false);
  }
  do {
    auto ov150 = e.VirtualBases();
    if (!ov150) {
      b.setVal352(false);
      break;
    }
    b.setVal352(true);
    auto v150 = std::move(*ov150);
    auto sv150 = b.initVal150(static_cast<unsigned>(v150.size()));
    auto i150 = 0u;
    for (const auto &e150 : v150) {
      sv150.set(i150, es.PseudoId(e150));
      ++i150;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  b.setVal137(es.EntityId(e.ExternToken()));
  b.setVal139(es.EntityId(e.PointOfInstantiation()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v353 = e.TemplateArguments();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.PseudoId(e353));
      ++i353;
    }
  } while (false);
  do {
    auto v354 = e.TemplateInstantiationArguments();
    auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
    auto i354 = 0u;
    for (const auto &e354 : v354) {
      sv354.set(i354, es.PseudoId(e354));
      ++i354;
    }
  } while (false);
  b.setVal140(es.EntityId(e.TemplateKeywordToken()));
  b.setVal152(es.EntityId(e.TypeAsWritten()));
  b.setVal355(e.IsClassScopeExplicitSpecialization());
  b.setVal356(e.IsExplicitInstantiationOrSpecialization());
  b.setVal357(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  do {
    auto v51 = e.Enumerators();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  auto v79 = e.InstantiatedFromMemberEnum();
  if (v79) {
    if (auto id79 = es.EntityId(v79.value())) {
      b.setVal79(id79);
      b.setVal107(true);
    } else {
      b.setVal107(false);
    }
  } else {
    b.setVal107(false);
  }
  auto v82 = e.IntegerType();
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
  if (auto r84 = e.IntegerTypeRange(); auto rs84 = r84.Size()) {
    b.setVal84(es.EntityId(r84[0]));
    b.setVal86(es.EntityId(r84[rs84 - 1u]));
  } else {
    b.setVal84(0);
    b.setVal86(0);
  }
  auto v89 = e.IntegerTypeSourceInfo();
  if (v89) {
    if (auto id89 = es.EntityId(v89.value())) {
      b.setVal89(id89);
      b.setVal109(true);
    } else {
      b.setVal109(false);
    }
  } else {
    b.setVal109(false);
  }
  auto v151 = e.ODRHash();
  if (v151) {
    b.setVal151(static_cast<unsigned>(v151.value()));
    b.setVal110(true);
  } else {
    b.setVal110(false);
  }
  b.setVal94(es.EntityId(e.PromotionType()));
  auto v134 = e.TemplateInstantiationPattern();
  if (v134) {
    if (auto id134 = es.EntityId(v134.value())) {
      b.setVal134(id134);
      b.setVal111(true);
    } else {
      b.setVal111(false);
    }
  } else {
    b.setVal111(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal112(e.IsClosed());
  b.setVal113(e.IsClosedFlag());
  b.setVal114(e.IsClosedNonFlag());
  b.setVal115(e.IsComplete());
  b.setVal116(e.IsFixed());
  b.setVal117(e.IsScoped());
  b.setVal118(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal57(es.EntityId(e.EllipsisToken()));
  b.setVal58(es.EntityId(e.TypenameToken()));
  b.setVal66(es.EntityId(e.UsingToken()));
  b.setVal75(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v57 = e.AnonymousDeclarationWithTypedefName();
  if (v57) {
    if (auto id57 = es.EntityId(v57.value())) {
      b.setVal57(id57);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
  b.setVal58(es.EntityId(e.TypeSourceInfo()));
  b.setVal66(es.EntityId(e.UnderlyingType()));
  b.setVal76(e.IsModed());
  b.setVal81(e.IsTransparentTag());
}

void SerializeTypedefDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto v67 = e.DescribedAliasTemplate();
  if (v67) {
    if (auto id67 = es.EntityId(v67.value())) {
      b.setVal67(id67);
      b.setVal83(true);
    } else {
      b.setVal83(false);
    }
  } else {
    b.setVal83(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  b.setVal67(es.EntityId(e.ColonToken()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  b.setVal68(es.EntityId(e.VarianceToken()));
  b.setVal83(e.HasExplicitBound());
}

void SerializeTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeRedeclarableTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFunctionTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeClassTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeVarTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTypeAliasTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e);
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal56(es.EntityId(e.ConstraintExpression()));
  b.setVal74(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTemplateTemplateParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeObjCPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.AtToken()));
  b.setVal57(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal58(es.EntityId(e.GetterNameToken()));
  b.setVal66(es.EntityId(e.LParenToken()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal67(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal68(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal77(es.EntityId(e.SetterNameToken()));
  b.setVal79(es.EntityId(e.Type()));
  b.setVal82(es.EntityId(e.TypeSourceInfo()));
  b.setVal74(e.IsAtomic());
  b.setVal75(e.IsClassProperty());
  b.setVal76(e.IsDirectProperty());
  b.setVal81(e.IsInstanceProperty());
  b.setVal83(e.IsOptional());
  b.setVal85(e.IsReadOnly());
  b.setVal87(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal74(e.DefinedInNSObject());
  b.setVal56(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal57(es.EntityId(e.Category()));
  b.setVal58(es.EntityId(e.ClassInterface()));
  b.setVal66(es.EntityId(e.CmdDeclaration()));
  b.setVal67(es.EntityId(e.DeclaratorEndToken()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal68(es.EntityId(e.ReturnType()));
  b.setVal77(es.EntityId(e.ReturnTypeSourceInfo()));
  if (auto r79 = e.ReturnTypeSourceRange(); auto rs79 = r79.Size()) {
    b.setVal79(es.EntityId(r79[0]));
    b.setVal82(es.EntityId(r79[rs79 - 1u]));
  } else {
    b.setVal79(0);
    b.setVal82(0);
  }
  b.setVal84(es.EntityId(e.SelectorStartToken()));
  b.setVal86(es.EntityId(e.SelfDeclaration()));
  b.setVal75(e.HasRedeclaration());
  b.setVal76(e.HasRelatedResultType());
  b.setVal81(e.HasSkippedBody());
  b.setVal83(e.IsClassMethod());
  b.setVal85(e.IsDefined());
  b.setVal87(e.IsDesignatedInitializerForTheInterface());
  b.setVal95(e.IsDirectMethod());
  b.setVal98(e.IsInstanceMethod());
  b.setVal99(e.IsOptional());
  b.setVal100(e.IsOverriding());
  b.setVal101(e.IsPropertyAccessor());
  b.setVal102(e.IsRedeclaration());
  b.setVal103(e.IsSynthesizedAccessorStub());
  b.setVal104(e.IsThisDeclarationADefinition());
  b.setVal105(e.IsThisDeclarationADesignatedInitializer());
  b.setVal106(e.IsVariadic());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  do {
    auto v51 = e.SelectorTokens();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  pasta::DeclContext dc62(e);
  auto v62 = dc62.AlreadyLoadedDeclarations();
  auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
  auto i62 = 0u;
  for (const pasta::Decl &e62 : v62) {
    sv62.set(i62, es.EntityId(e62));
    ++i62;
  }
}

void SerializeObjCContainerDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v50 = e.ClassMethods();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  do {
    auto v51 = e.ClassProperties();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  if (auto r56 = e.AtEndRange(); auto rs56 = r56.Size()) {
    b.setVal56(es.EntityId(r56[0]));
    b.setVal57(es.EntityId(r56[rs56 - 1u]));
  } else {
    b.setVal56(0);
    b.setVal57(0);
  }
  b.setVal58(es.EntityId(e.AtStartToken()));
  do {
    auto v62 = e.InstanceMethods();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      sv62.set(i62, es.EntityId(e62));
      ++i62;
    }
  } while (false);
  do {
    auto v187 = e.InstanceProperties();
    auto sv187 = b.initVal187(static_cast<unsigned>(v187.size()));
    auto i187 = 0u;
    for (const auto &e187 : v187) {
      sv187.set(i187, es.EntityId(e187));
      ++i187;
    }
  } while (false);
  do {
    auto v188 = e.Methods();
    auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
    auto i188 = 0u;
    for (const auto &e188 : v188) {
      sv188.set(i188, es.EntityId(e188));
      ++i188;
    }
  } while (false);
  do {
    auto v326 = e.Properties();
    auto sv326 = b.initVal326(static_cast<unsigned>(v326.size()));
    auto i326 = 0u;
    for (const auto &e326 : v326) {
      sv326.set(i326, es.EntityId(e326));
      ++i326;
    }
  } while (false);
  pasta::DeclContext dc358(e);
  auto v358 = dc358.AlreadyLoadedDeclarations();
  auto sv358 = b.initVal358(static_cast<unsigned>(v358.size()));
  auto i358 = 0u;
  for (const pasta::Decl &e358 : v358) {
    sv358.set(i358, es.EntityId(e358));
    ++i358;
  }
}

void SerializeObjCCategoryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal74(e.IsClassExtension());
  b.setVal66(es.EntityId(e.CategoryNameToken()));
  b.setVal67(es.EntityId(e.ClassInterface()));
  b.setVal68(es.EntityId(e.Implementation()));
  b.setVal77(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal79(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal82(es.EntityId(e.NextClassCategory()));
  b.setVal84(es.EntityId(e.NextClassCategoryRaw()));
  do {
    auto v359 = e.InstanceVariables();
    auto sv359 = b.initVal359(static_cast<unsigned>(v359.size()));
    auto i359 = 0u;
    for (const auto &e359 : v359) {
      sv359.set(i359, es.EntityId(e359));
      ++i359;
    }
  } while (false);
  do {
    auto v360 = e.ProtocolTokens();
    auto sv360 = b.initVal360(static_cast<unsigned>(v360.size()));
    auto i360 = 0u;
    for (const auto &e360 : v360) {
      sv360.set(i360, es.EntityId(e360));
      ++i360;
    }
  } while (false);
  do {
    auto v361 = e.Protocols();
    auto sv361 = b.initVal361(static_cast<unsigned>(v361.size()));
    auto i361 = 0u;
    for (const auto &e361 : v361) {
      sv361.set(i361, es.EntityId(e361));
      ++i361;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal66(es.EntityId(e.Definition()));
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal74(e.HasDefinition());
  b.setVal75(e.IsNonRuntimeProtocol());
  b.setVal76(e.IsThisDeclarationADefinition());
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
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v359 = e.AllReferencedProtocols();
    auto sv359 = b.initVal359(static_cast<unsigned>(v359.size()));
    auto i359 = 0u;
    for (const auto &e359 : v359) {
      sv359.set(i359, es.EntityId(e359));
      ++i359;
    }
  } while (false);
  b.setVal74(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal66(es.EntityId(e.CategoryListRaw()));
  b.setVal67(es.EntityId(e.Definition()));
  b.setVal68(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal77(es.EntityId(e.Implementation()));
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  auto v79 = e.SuperClass();
  if (v79) {
    if (auto id79 = es.EntityId(v79.value())) {
      b.setVal79(id79);
      b.setVal75(true);
    } else {
      b.setVal75(false);
    }
  } else {
    b.setVal75(false);
  }
  b.setVal82(es.EntityId(e.SuperClassToken()));
  auto v84 = e.SuperClassTypeInfo();
  if (v84) {
    if (auto id84 = es.EntityId(v84.value())) {
      b.setVal84(id84);
      b.setVal76(true);
    } else {
      b.setVal76(false);
    }
  } else {
    b.setVal76(false);
  }
  auto v86 = e.SuperClassType();
  if (v86) {
    if (auto id86 = es.EntityId(v86.value())) {
      b.setVal86(id86);
      b.setVal81(true);
    } else {
      b.setVal81(false);
    }
  } else {
    b.setVal81(false);
  }
  b.setVal89(es.EntityId(e.TypeForDeclaration()));
  b.setVal83(e.HasDefinition());
  b.setVal85(e.HasDesignatedInitializers());
  b.setVal87(e.IsArcWeakrefUnavailable());
  b.setVal95(e.IsImplicitInterfaceDeclaration());
  b.setVal94(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal98(e.IsThisDeclarationADefinition());
  do {
    auto v360 = e.InstanceVariables();
    auto sv360 = b.initVal360(static_cast<unsigned>(v360.size()));
    auto i360 = 0u;
    for (const auto &e360 : v360) {
      sv360.set(i360, es.EntityId(e360));
      ++i360;
    }
  } while (false);
  do {
    auto v361 = e.KnownCategories();
    auto sv361 = b.initVal361(static_cast<unsigned>(v361.size()));
    auto i361 = 0u;
    for (const auto &e361 : v361) {
      sv361.set(i361, es.EntityId(e361));
      ++i361;
    }
  } while (false);
  do {
    auto v362 = e.KnownExtensions();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
  do {
    auto v363 = e.ProtocolTokens();
    auto sv363 = b.initVal363(static_cast<unsigned>(v363.size()));
    auto i363 = 0u;
    for (const auto &e363 : v363) {
      sv363.set(i363, es.EntityId(e363));
      ++i363;
    }
  } while (false);
  do {
    auto v364 = e.Protocols();
    auto sv364 = b.initVal364(static_cast<unsigned>(v364.size()));
    auto i364 = 0u;
    for (const auto &e364 : v364) {
      sv364.set(i364, es.EntityId(e364));
      ++i364;
    }
  } while (false);
  do {
    auto v365 = e.VisibleCategories();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
  do {
    auto v366 = e.VisibleExtensions();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
}

void SerializeObjCImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal66(es.EntityId(e.ClassInterface()));
  do {
    auto v359 = e.PropertyImplementations();
    auto sv359 = b.initVal359(static_cast<unsigned>(v359.size()));
    auto i359 = 0u;
    for (const auto &e359 : v359) {
      sv359.set(i359, es.EntityId(e359));
      ++i359;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal67(es.EntityId(e.CategoryDeclaration()));
  b.setVal68(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal67(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal68(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal77(es.EntityId(e.SuperClass()));
  b.setVal79(es.EntityId(e.SuperClassToken()));
  b.setVal74(e.HasDestructors());
  b.setVal75(e.HasNonZeroConstructors());
  do {
    auto v360 = e.InstanceVariables();
    auto sv360 = b.initVal360(static_cast<unsigned>(v360.size()));
    auto i360 = 0u;
    for (const auto &e360 : v360) {
      sv360.set(i360, es.EntityId(e360));
      ++i360;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeNamespaceAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.AliasToken()));
  b.setVal57(es.EntityId(e.AliasedNamespace()));
  b.setVal58(es.EntityId(e.NamespaceToken()));
  b.setVal66(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v50 = e.ChildrenExpression();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal48(es.EntityId(e.ExtendingDeclaration()));
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal56(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v50 = e.IdentifierTokens();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFriendDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v48 = e.FriendDeclaration();
  if (v48) {
    if (auto id48 = es.EntityId(v48.value())) {
      b.setVal48(id48);
      b.setVal49(true);
    } else {
      b.setVal49(false);
    }
  } else {
    b.setVal49(false);
  }
  b.setVal56(es.EntityId(e.FriendToken()));
  b.setVal57(es.EntityId(e.FriendType()));
  b.setVal52(e.IsUnsupportedFriend());
  do {
    auto v80 = e.FriendTypeTemplateParameterLists();
    auto sv80 = b.initVal80(static_cast<unsigned>(v80.size()));
    auto i80 = 0u;
    for (const auto &e80 : v80) {
      sv80.set(i80, es.PseudoId(e80));
      ++i80;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.AssemblyToken()));
  b.setVal56(es.EntityId(e.AssemblyString()));
  b.setVal57(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal48(es.EntityId(e.ExportToken()));
  b.setVal56(es.EntityId(e.RBraceToken()));
  b.setVal49(e.HasBraces());
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
