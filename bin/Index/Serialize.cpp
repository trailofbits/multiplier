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
#include "Util.h"

namespace indexer {

void SerializeTemplateParameterList(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoEntityKind::kTemplateParameterList));
  b.setVal1(e.NumParameters());
  b.setVal2(e.NumRequiredParameters());
  b.setVal3(e.Depth());
  b.setVal4(e.HasUnexpandedParameterPack());
  b.setVal5(e.HasParameterPack());
  auto v6 = e.RequiresClause();
  if (v6) {
    auto id6 = es.EntityId(v6.value());    b.setVal6(id6);
    b.setVal7(id6 != mx::kInvalidEntityId);
  } else {
    b.setVal6(mx::kInvalidEntityId);
    b.setVal7(false);
  }
  b.setVal8(es.EntityId(e.TemplateKeywordToken()));
  b.setVal9(es.EntityId(e.LeftAngleToken()));
  b.setVal10(es.EntityId(e.RightAngleToken()));
  if (auto r11 = e.Tokens(); auto rs11 = r11.Size()) {
    b.setVal11(es.EntityId(r11[0]));
    b.setVal12(es.EntityId(r11[rs11 - 1u]));
  } else {
    b.setVal11(0);
    b.setVal12(0);
  }
  do {
    auto v13 = e.Parameters();
    auto sv13 = b.initVal13(static_cast<unsigned>(v13.size()));
    auto i13 = 0u;
    for (const auto &e13 : v13) {
      sv13.set(i13, es.EntityId(e13));
      ++i13;
    }
  } while (false);
}

void SerializeTemplateArgument(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoEntityKind::kTemplateArgument));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal4(e.IsNull());
  b.setVal5(e.IsDependent());
  b.setVal7(e.IsInstantiationDependent());
  b.setVal15(e.ContainsUnexpandedParameterPack());
  b.setVal16(e.IsPackExpansion());
  auto v6 = e.AsDeclaration();
  if (v6) {
    auto id6 = es.EntityId(v6.value());    b.setVal6(id6);
    b.setVal17(id6 != mx::kInvalidEntityId);
  } else {
    b.setVal6(mx::kInvalidEntityId);
    b.setVal17(false);
  }
  auto v8 = e.AsType();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal18(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal18(false);
  }
  auto v9 = e.ParameterTypeForDeclaration();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal19(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal19(false);
  }
  auto v10 = e.NullPointerType();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal20(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal20(false);
  }
}

void SerializeCXXBaseSpecifier(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoEntityKind::kCXXBaseSpecifier));
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal8(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal8(0);
  }
  b.setVal9(es.EntityId(e.BaseTypeToken()));
  b.setVal4(e.IsVirtual());
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal5(e.IsPackExpansion());
  b.setVal7(e.ConstructorsAreInherited());
  auto v10 = e.Ellipsis();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal15(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal22(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal11(es.EntityId(e.BaseType()));
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
    auto id7 = es.EntityId(v7.value());    b.setVal7(id7);
    b.setVal8(id7 != mx::kInvalidEntityId);
  } else {
    b.setVal7(mx::kInvalidEntityId);
    b.setVal8(false);
  }
  auto v9 = e.AsCXXRecordDeclaration();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal10(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal10(false);
  }
  auto v11 = e.AsComplexIntegerType();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.AsObjCInterfacePointerType();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal14(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto v15 = e.AsObjCInterfaceType();
  if (v15) {
    auto id15 = es.EntityId(v15.value());    b.setVal15(id15);
    b.setVal16(id15 != mx::kInvalidEntityId);
  } else {
    b.setVal15(mx::kInvalidEntityId);
    b.setVal16(false);
  }
  auto v17 = e.AsObjCQualifiedClassType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());    b.setVal17(id17);
    b.setVal18(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal18(false);
  }
  auto v19 = e.AsObjCQualifiedIdType();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal20(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto v21 = e.AsObjCQualifiedInterfaceType();
  if (v21) {
    auto id21 = es.EntityId(v21.value());    b.setVal21(id21);
    b.setVal22(id21 != mx::kInvalidEntityId);
  } else {
    b.setVal21(mx::kInvalidEntityId);
    b.setVal22(false);
  }
  auto v23 = e.AsPlaceholderType();
  if (v23) {
    auto id23 = es.EntityId(v23.value());    b.setVal23(id23);
    b.setVal24(id23 != mx::kInvalidEntityId);
  } else {
    b.setVal23(mx::kInvalidEntityId);
    b.setVal24(false);
  }
  auto v25 = e.AsRecordDeclaration();
  if (v25) {
    auto id25 = es.EntityId(v25.value());    b.setVal25(id25);
    b.setVal26(id25 != mx::kInvalidEntityId);
  } else {
    b.setVal25(mx::kInvalidEntityId);
    b.setVal26(false);
  }
  auto v27 = e.AsStructureType();
  if (v27) {
    auto id27 = es.EntityId(v27.value());    b.setVal27(id27);
    b.setVal28(id27 != mx::kInvalidEntityId);
  } else {
    b.setVal27(mx::kInvalidEntityId);
    b.setVal28(false);
  }
  auto v29 = e.AsTagDeclaration();
  if (v29) {
    auto id29 = es.EntityId(v29.value());    b.setVal29(id29);
    b.setVal30(id29 != mx::kInvalidEntityId);
  } else {
    b.setVal29(mx::kInvalidEntityId);
    b.setVal30(false);
  }
  auto v31 = e.AsUnionType();
  if (v31) {
    auto id31 = es.EntityId(v31.value());    b.setVal31(id31);
    b.setVal32(id31 != mx::kInvalidEntityId);
  } else {
    b.setVal31(mx::kInvalidEntityId);
    b.setVal32(false);
  }
  b.setVal33(es.EntityId(e.CanonicalTypeInternal()));
  auto v34 = e.ContainedAutoType();
  if (v34) {
    auto id34 = es.EntityId(v34.value());    b.setVal34(id34);
    b.setVal35(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal35(false);
  }
  auto v36 = e.ContainedDeducedType();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal37(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
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
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal43(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal43(false);
  }
  auto v44 = e.PointeeOrArrayElementType();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal45(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal45(false);
  }
  auto v46 = e.PointeeType();
  if (v46) {
    auto id46 = es.EntityId(v46.value());    b.setVal46(id46);
    b.setVal47(id46 != mx::kInvalidEntityId);
  } else {
    b.setVal46(mx::kInvalidEntityId);
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
    auto id50 = es.EntityId(v50.value());    b.setVal50(id50);
    b.setVal51(id50 != mx::kInvalidEntityId);
  } else {
    b.setVal50(mx::kInvalidEntityId);
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
    auto id314 = es.EntityId(v314.value());    b.setVal314(id314);
    b.setVal308(id314 != mx::kInvalidEntityId);
  } else {
    b.setVal314(mx::kInvalidEntityId);
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
    auto id329 = es.EntityId(v329.value());    b.setVal329(id329);
    b.setVal320(id329 != mx::kInvalidEntityId);
  } else {
    b.setVal329(mx::kInvalidEntityId);
    b.setVal320(false);
  }
  auto v330 = e.ExceptionSpecTemplate();
  if (v330) {
    auto id330 = es.EntityId(v330.value());    b.setVal330(id330);
    b.setVal321(id330 != mx::kInvalidEntityId);
  } else {
    b.setVal330(mx::kInvalidEntityId);
    b.setVal321(false);
  }
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v336 = e.NoexceptExpression();
  if (v336) {
    auto id336 = es.EntityId(v336.value());    b.setVal336(id336);
    b.setVal322(id336 != mx::kInvalidEntityId);
  } else {
    b.setVal336(mx::kInvalidEntityId);
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
    auto id312 = es.EntityId(v312.value());    b.setVal312(id312);
    b.setVal308(id312 != mx::kInvalidEntityId);
  } else {
    b.setVal312(mx::kInvalidEntityId);
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
    auto id312 = es.EntityId(v312.value());    b.setVal312(id312);
    b.setVal308(id312 != mx::kInvalidEntityId);
  } else {
    b.setVal312(mx::kInvalidEntityId);
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
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
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
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal13(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v11 = e.ReturnValue();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal16(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
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
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal13(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
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
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal13(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal16(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal16(false);
  }
  auto v14 = e.Else();
  if (v14) {
    auto id14 = es.EntityId(v14.value());    b.setVal14(id14);
    b.setVal21(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  b.setVal15(es.EntityId(e.ElseToken()));
  b.setVal18(es.EntityId(e.IfToken()));
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal22(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
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
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal13(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v12 = e.ConditionVariable();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal16(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal16(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());    b.setVal14(id14);
    b.setVal21(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  b.setVal15(es.EntityId(e.ForToken()));
  auto v18 = e.Increment();
  if (v18) {
    auto id18 = es.EntityId(v18.value());    b.setVal18(id18);
    b.setVal22(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal22(false);
  }
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal57(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
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
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal13(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
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
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal13(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
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
    auto id27 = es.EntityId(v27.value());    b.setVal27(id27);
    b.setVal13(id27 != mx::kInvalidEntityId);
  } else {
    b.setVal27(mx::kInvalidEntityId);
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
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal13(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
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
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal13(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());    b.setVal14(id14);
    b.setVal16(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
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
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal13(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
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
    auto id34 = es.EntityId(v34.value());    b.setVal34(id34);
    b.setVal57(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal57(false);
  }
  b.setVal62(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v35 = e.ReferencedDeclarationOfCallee();
  if (v35) {
    auto id35 = es.EntityId(v35.value());    b.setVal35(id35);
    b.setVal58(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto v36 = e.SourceBitField();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal59(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.SubExpressionAsWritten()));
  auto v41 = e.TargetUnionField();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal99(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
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
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal98(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v41 = e.DirectCallee();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal99(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
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
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal109(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
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
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal99(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v41 = e.ConstructExpression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal100(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
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
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal101(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
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
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal98(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
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
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal98(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal41(es.EntityId(e.Pointer()));
  b.setVal42(es.EntityId(e.RParenToken()));
  auto v43 = e.Scope();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal99(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v44 = e.Value1();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal100(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  auto v45 = e.Value2();
  if (v45) {
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal101(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal46(es.EntityId(e.ValueType()));
  auto v47 = e.Weak();
  if (v47) {
    auto id47 = es.EntityId(v47.value());    b.setVal47(id47);
    b.setVal102(id47 != mx::kInvalidEntityId);
  } else {
    b.setVal47(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v39 = e.ArgumentType();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal99(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v40 = e.ArgumentTypeInfo();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal100(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v39 = e.LifetimeExtendedTemporaryDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal99(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
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
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal99(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
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
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal98(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v39 = e.InitializedFieldInUnion();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal99(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  b.setVal40(es.EntityId(e.LBraceToken()));
  b.setVal41(es.EntityId(e.RBraceToken()));
  auto v42 = e.SemanticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal100(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  auto v43 = e.SyntacticForm();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal101(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
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
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal13(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());    b.setVal14(id14);
    b.setVal16(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal16(false);
  }
  auto v15 = e.Initializer();
  if (v15) {
    auto id15 = es.EntityId(v15.value());    b.setVal15(id15);
    b.setVal21(id15 != mx::kInvalidEntityId);
  } else {
    b.setVal15(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  b.setVal18(es.EntityId(e.LParenToken()));
  b.setVal19(es.EntityId(e.RParenToken()));
  auto v20 = e.FirstSwitchCase();
  if (v20) {
    auto id20 = es.EntityId(v20.value());    b.setVal20(id20);
    b.setVal22(id20 != mx::kInvalidEntityId);
  } else {
    b.setVal20(mx::kInvalidEntityId);
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
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal13(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
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
    auto id20 = es.EntityId(v20.value());    b.setVal20(id20);
    b.setVal21(id20 != mx::kInvalidEntityId);
  } else {
    b.setVal20(mx::kInvalidEntityId);
    b.setVal21(false);
  }
}

void SerializeDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(IsDefinition(e));
  b.setVal3(static_cast<unsigned char>(mx::FromPasta(e.Access())));
  b.setVal4(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  b.setVal5(es.EntityId(e.BeginToken()));
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
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v13 = e.NonClosureContext();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal14(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  b.setVal15(e.HasAttributes());
  b.setVal16(e.HasDefiningAttribute());
  b.setVal17(e.HasOwningModule());
  b.setVal18(e.HasTagIdentifierNamespace());
  b.setVal19(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal20(e.IsDeprecated());
  b.setVal21(e.IsFunctionOrFunctionTemplate());
  b.setVal22(e.IsImplicit());
  b.setVal23(e.IsInAnonymousNamespace());
  b.setVal24(e.IsInLocalScopeForInstantiation());
  b.setVal25(e.IsInStdNamespace());
  b.setVal26(e.IsInvalidDeclaration());
  b.setVal27(e.IsModulePrivate());
  b.setVal28(e.IsOutOfLine());
  b.setVal29(e.IsParameterPack());
  b.setVal30(e.IsTemplateDeclaration());
  b.setVal31(e.IsTemplateParameter());
  b.setVal32(e.IsTemplateParameterPack());
  b.setVal33(e.IsTemplated());
  b.setVal34(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal35(e.IsUnavailable());
  b.setVal36(e.IsUnconditionallyVisible());
  b.setVal37(e.IsWeakImported());
  do {
    auto v38 = e.Redeclarations();
    auto sv38 = b.initVal38(static_cast<unsigned>(v38.size()));
    auto i38 = 0u;
    for (const auto &e38 : v38) {
      sv38.set(i38, es.EntityId(e38));
      ++i38;
    }
  } while (false);
  b.setVal39(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal40(es.EntityId(e.Token()));
  if (auto r41 = e.Tokens(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.Specialization()));
  b.setVal44(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.ContextParameter()));
  b.setVal44(e.IsNothrow());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(e.BlockMissingReturnType());
  b.setVal47(e.CanAvoidCopyToHeap());
  b.setVal48(e.CapturesCXXThis());
  b.setVal49(e.DoesNotEscape());
  auto v43 = e.BlockManglingContextDeclaration();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal50(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal50(false);
  }
  b.setVal51(es.EntityId(e.CaretToken()));
  b.setVal52(es.EntityId(e.CompoundBody()));
  b.setVal53(es.EntityId(e.SignatureAsWritten()));
  b.setVal54(e.HasCaptures());
  b.setVal55(e.IsConversionFromLambda());
  b.setVal56(e.IsVariadic());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  do {
    auto v46 = e.ParameterDeclarations();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
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

void SerializeAccessSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.AccessSpecifierToken()));
  b.setVal51(es.EntityId(e.ColonToken()));
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
    auto v45 = e.Varlists();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
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
    auto v45 = e.Varlists();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.AssertExpression()));
  b.setVal51(es.EntityId(e.Message()));
  b.setVal52(es.EntityId(e.RParenToken()));
  b.setVal44(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializePragmaDetectMismatchDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v58 = e.Name();
  std::string s58(v58.data(), v58.size());
  b.setVal58(s58);
  auto v59 = e.Value();
  std::string s59(v59.data(), v59.size());
  b.setVal59(s59);
}

void SerializePragmaCommentDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v58 = e.Argument();
  std::string s58(v58.data(), v58.size());
  b.setVal58(s58);
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.GetterCXXConstructor()));
  b.setVal51(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal52(es.EntityId(e.PropertyDeclaration()));
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal53(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal61(es.EntityId(e.PropertyInstanceVariableDeclarationToken()));
  b.setVal62(es.EntityId(e.SetterCXXAssignment()));
  b.setVal63(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal44(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.LinkageInternal())));
  b.setVal58(e.Name());
  auto v65 = e.ObjCFStringFormattingFamily();
  if (v65) {
    b.setVal65(static_cast<unsigned char>(v65.value()));
    b.setVal44(true);
  } else {
    b.setVal44(false);
  }
  b.setVal59(e.QualifiedNameAsString());
  b.setVal43(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal47(e.HasExternalFormalLinkage());
  b.setVal48(e.HasLinkage());
  b.setVal49(e.HasLinkageBeenComputed());
  b.setVal50(e.IsCXXClassMember());
  b.setVal54(e.IsCXXInstanceMember());
  b.setVal55(e.IsExternallyDeclarable());
  b.setVal56(e.IsExternallyVisible());
  b.setVal67(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v68 = e.MSAssemblyLabel();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal51(es.EntityId(e.Statement()));
  b.setVal69(e.IsGnuLocal());
  b.setVal70(e.IsMSAssemblyLabel());
  b.setVal71(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v45 = e.Shadows();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal51(es.EntityId(e.EnumDeclaration()));
  b.setVal52(es.EntityId(e.EnumToken()));
  b.setVal53(es.EntityId(e.UsingToken()));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal51(es.EntityId(e.UsingToken()));
  b.setVal69(e.HasTypename());
  b.setVal70(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.Type()));
  b.setVal69(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal52(es.EntityId(e.EllipsisToken()));
  b.setVal53(es.EntityId(e.UsingToken()));
  b.setVal70(e.IsAccessDeclaration());
  b.setVal71(e.IsPackExpansion());
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
  b.setVal52(es.EntityId(e.Combiner()));
  b.setVal53(es.EntityId(e.CombinerIn()));
  b.setVal61(es.EntityId(e.CombinerOut()));
  b.setVal62(es.EntityId(e.InitializerOriginal()));
  b.setVal63(es.EntityId(e.InitializerPrivate()));
  b.setVal72(es.EntityId(e.Initializer()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  b.setVal74(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
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
    auto v45 = e.Chain();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  auto v52 = e.AnonymousField();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal70(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v53 = e.VariableDeclaration();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal71(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal71(false);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v52 = e.InitializerExpression();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal70(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal70(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal52(es.EntityId(e.InnerTokenStart()));
  b.setVal53(es.EntityId(e.OuterTokenStart()));
  auto v61 = e.TrailingRequiresClause();
  if (v61) {
    auto id61 = es.EntityId(v61.value());    b.setVal61(id61);
    b.setVal70(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v62 = e.TypeSourceInfo();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal71(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  b.setVal63(es.EntityId(e.TypeSpecEndToken()));
  b.setVal72(es.EntityId(e.TypeSpecStartToken()));
  do {
    auto v75 = e.TemplateParameterLists();
    auto sv75 = b.initVal75(static_cast<unsigned>(v75.size()));
    auto i75 = 0u;
    for (const auto &e75 : v75) {
      sv75.set(i75, es.PseudoId(e75));
      ++i75;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v74 = e.ActingDefinition();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal76(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  auto v77 = e.Initializer();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal78(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v79 = e.InitializingDeclaration();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal80(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  auto v81 = e.InstantiatedFromStaticDataMember();
  if (v81) {
    auto id81 = es.EntityId(v81.value());    b.setVal81(id81);
    b.setVal82(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal82(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal84(es.EntityId(e.PointOfInstantiation()));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v89 = e.TemplateInstantiationPattern();
  if (v89) {
    auto id89 = es.EntityId(v89.value());    b.setVal89(id89);
    b.setVal90(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
    b.setVal90(false);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal93(e.HasConstantInitialization());
  b.setVal94(e.HasDependentAlignment());
  b.setVal95(e.HasExternalStorage());
  b.setVal96(e.HasGlobalStorage());
  auto v97 = e.HasICEInitializer();
  if (v97) {
    b.setVal97(static_cast<bool>(v97.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal99(e.HasInitializer());
  b.setVal100(e.HasLocalStorage());
  b.setVal101(e.IsARCPseudoStrong());
  b.setVal102(e.IsCXXForRangeDeclaration());
  b.setVal103(e.IsConstexpr());
  b.setVal104(e.IsDirectInitializer());
  b.setVal105(e.IsEscapingByref());
  b.setVal106(e.IsExceptionVariable());
  b.setVal107(e.IsExternC());
  b.setVal108(e.IsFileVariableDeclaration());
  b.setVal109(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal110(e.IsInExternCContext());
  b.setVal111(e.IsInExternCXXContext());
  b.setVal112(e.IsInitializerCapture());
  b.setVal113(e.IsInline());
  b.setVal114(e.IsInlineSpecified());
  b.setVal115(e.IsKnownToBeDefined());
  b.setVal116(e.IsLocalVariableDeclaration());
  b.setVal117(e.IsLocalVariableDeclarationOrParm());
  b.setVal118(e.IsNRVOVariable());
  b.setVal119(e.IsNoDestroy());
  b.setVal120(e.IsNonEscapingByref());
  b.setVal121(e.IsObjCForDeclaration());
  b.setVal122(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal123(e.IsStaticDataMember());
  b.setVal124(e.IsStaticLocal());
  b.setVal125(e.IsThisDeclarationADemotedDefinition());
  b.setVal126(e.IsUsableInConstantExpressions());
  b.setVal127(e.MightBeUsableInConstantExpressions());
  b.setVal128(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v129 = e.DefaultArgument();
  if (v129) {
    auto id129 = es.EntityId(v129.value());    b.setVal129(id129);
    b.setVal130(id129 != mx::kInvalidEntityId);
  } else {
    b.setVal129(mx::kInvalidEntityId);
    b.setVal130(false);
  }
  if (auto r131 = e.DefaultArgumentRange(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal132(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal132(0);
  }
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal134(es.EntityId(e.OriginalType()));
  auto v135 = e.UninstantiatedDefaultArgument();
  if (v135) {
    auto id135 = es.EntityId(v135.value());    b.setVal135(id135);
    b.setVal136(id135 != mx::kInvalidEntityId);
  } else {
    b.setVal135(mx::kInvalidEntityId);
    b.setVal136(false);
  }
  b.setVal137(e.HasDefaultArgument());
  b.setVal138(e.HasInheritedDefaultArgument());
  b.setVal139(e.HasUninstantiatedDefaultArgument());
  b.setVal140(e.HasUnparsedDefaultArgument());
  b.setVal141(e.IsDestroyedInCallee());
  b.setVal142(e.IsKNRPromoted());
  b.setVal143(e.IsObjCMethodParameter());
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
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v45 = e.Bindings();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal129(es.EntityId(e.ExternToken()));
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v144 = e.TemplateArguments();
    auto sv144 = b.initVal144(static_cast<unsigned>(v144.size()));
    auto i144 = 0u;
    for (const auto &e144 : v144) {
      sv144.set(i144, es.PseudoId(e144));
      ++i144;
    }
  } while (false);
  do {
    auto v145 = e.TemplateInstantiationArguments();
    auto sv145 = b.initVal145(static_cast<unsigned>(v145.size()));
    auto i145 = 0u;
    for (const auto &e145 : v145) {
      sv145.set(i145, es.PseudoId(e145));
      ++i145;
    }
  } while (false);
  b.setVal131(es.EntityId(e.TemplateKeywordToken()));
  b.setVal132(es.EntityId(e.TypeAsWritten()));
  b.setVal130(e.IsClassScopeExplicitSpecialization());
  b.setVal136(e.IsExplicitInstantiationOrSpecialization());
  b.setVal137(e.IsExplicitSpecialization());
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
  b.setVal76(e.DefaultArgumentWasInherited());
  b.setVal74(es.EntityId(e.DefaultArgument()));
  b.setVal77(es.EntityId(e.DefaultArgumentToken()));
  b.setVal79(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal78(e.HasDefaultArgument());
  b.setVal80(e.HasPlaceholderTypeConstraint());
  b.setVal82(e.IsExpandedParameterPack());
  b.setVal90(e.IsPackExpansion());
  do {
    auto v45 = e.ExpansionTypes();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  do {
    auto v46 = e.ExpansionTypeSourceInfos();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal76(e.HasGetter());
  b.setVal78(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v76 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v76) {
    b.setVal76(static_cast<bool>(v76.value()));
    b.setVal78(true);
  } else {
    b.setVal78(false);
  }
  b.setVal80(e.DoesThisDeclarationHaveABody());
  b.setVal74(es.EntityId(e.CallResultType()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal77(es.EntityId(e.DeclaredReturnType()));
  b.setVal79(es.EntityId(e.EllipsisToken()));
  if (auto r81 = e.ExceptionSpecSourceRange(); auto rs81 = r81.Size()) {
    b.setVal81(es.EntityId(r81[0]));
    b.setVal84(es.EntityId(r81[rs81 - 1u]));
  } else {
    b.setVal81(0);
    b.setVal84(0);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v89 = e.InstantiatedFromMemberFunction();
  if (v89) {
    auto id89 = es.EntityId(v89.value());    b.setVal89(id89);
    b.setVal82(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
    b.setVal82(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v146 = e.ODRHash();
  if (v146) {
    b.setVal146(static_cast<unsigned>(v146.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r129 = e.ParametersSourceRange(); auto rs129 = r129.Size()) {
    b.setVal129(es.EntityId(r129[0]));
    b.setVal131(es.EntityId(r129[rs129 - 1u]));
  } else {
    b.setVal129(0);
    b.setVal131(0);
  }
  b.setVal132(es.EntityId(e.PointOfInstantiation()));
  b.setVal134(es.EntityId(e.ReturnType()));
  if (auto r135 = e.ReturnTypeSourceRange(); auto rs135 = r135.Size()) {
    b.setVal135(es.EntityId(r135[0]));
    b.setVal147(es.EntityId(r135[rs135 - 1u]));
  } else {
    b.setVal135(0);
    b.setVal147(0);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v148 = e.TemplateInstantiationPattern();
  if (v148) {
    auto id148 = es.EntityId(v148.value());    b.setVal148(id148);
    b.setVal93(id148 != mx::kInvalidEntityId);
  } else {
    b.setVal148(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal128(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
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
  auto v119 = e.IsInlineDefinitionExternallyVisible();
  if (v119) {
    b.setVal119(static_cast<bool>(v119.value()));
    b.setVal120(true);
  } else {
    b.setVal120(false);
  }
  b.setVal121(e.IsInlineSpecified());
  b.setVal122(e.IsInlined());
  b.setVal123(e.IsLateTemplateParsed());
  auto v124 = e.IsMSExternInline();
  if (v124) {
    b.setVal124(static_cast<bool>(v124.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
  }
  b.setVal126(e.IsMSVCRTEntryPoint());
  b.setVal127(e.IsMain());
  b.setVal130(e.IsMultiVersion());
  b.setVal136(e.IsNoReturn());
  b.setVal137(e.IsOverloadedOperator());
  b.setVal138(e.IsPure());
  b.setVal139(e.IsReplaceableGlobalAllocationFunction());
  auto v140 = e.IsReservedGlobalPlacementOperator();
  if (v140) {
    b.setVal140(static_cast<bool>(v140.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  b.setVal142(e.IsStatic());
  b.setVal143(e.IsTargetMultiVersion());
  b.setVal149(e.IsTemplateInstantiation());
  b.setVal150(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal151(e.IsTrivial());
  b.setVal152(e.IsTrivialForCall());
  b.setVal153(e.IsUserProvided());
  b.setVal154(e.IsVariadic());
  b.setVal155(e.IsVirtualAsWritten());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal156(e.UsesSEHTry());
  b.setVal157(e.WillHaveBody());
  auto v158 = e.Body();
  if (v158) {
    auto id158 = es.EntityId(v158.value());    b.setVal158(id158);
    b.setVal159(id158 != mx::kInvalidEntityId);
  } else {
    b.setVal158(mx::kInvalidEntityId);
    b.setVal159(false);
  }
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal160(es.EntityId(e.Parent()));
  b.setVal133(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal161(es.EntityId(e.ThisObjectType()));
  b.setVal162(es.EntityId(e.ThisType()));
  b.setVal163(e.HasInlineBody());
  b.setVal164(e.IsConst());
  b.setVal165(e.IsCopyAssignmentOperator());
  b.setVal166(e.IsInstance());
  b.setVal167(e.IsLambdaStaticInvoker());
  b.setVal168(e.IsMoveAssignmentOperator());
  b.setVal169(e.IsVirtual());
  b.setVal170(e.IsVolatile());
  do {
    auto v57 = e.OverriddenMethods();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v171 = e.OperatorDelete();
  if (v171) {
    auto id171 = es.EntityId(v171.value());    b.setVal171(id171);
    b.setVal172(id171 != mx::kInvalidEntityId);
  } else {
    b.setVal171(mx::kInvalidEntityId);
    b.setVal172(false);
  }
  auto v173 = e.OperatorDeleteThisArgument();
  if (v173) {
    auto id173 = es.EntityId(v173.value());    b.setVal173(id173);
    b.setVal174(id173 != mx::kInvalidEntityId);
  } else {
    b.setVal173(mx::kInvalidEntityId);
    b.setVal174(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal171(es.EntityId(e.ConversionType()));
  b.setVal172(e.IsExplicit());
  b.setVal174(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v171 = e.TargetConstructor();
  if (v171) {
    auto id171 = es.EntityId(v171.value());    b.setVal171(id171);
    b.setVal172(id171 != mx::kInvalidEntityId);
  } else {
    b.setVal171(mx::kInvalidEntityId);
    b.setVal172(false);
  }
  b.setVal174(e.IsDefaultConstructor());
  b.setVal175(e.IsDelegatingConstructor());
  b.setVal176(e.IsExplicit());
  b.setVal177(e.IsInheritingConstructor());
  b.setVal178(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal160(es.EntityId(e.CorrespondingConstructor()));
  b.setVal163(e.IsCopyDeductionCandidate());
  b.setVal164(e.IsExplicit());
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v74 = e.BitWidth();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal76(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  auto v77 = e.CapturedVLAType();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal78(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v79 = e.InClassInitializer();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal80(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  b.setVal81(es.EntityId(e.Parent()));
  b.setVal82(e.HasCapturedVLAType());
  b.setVal90(e.HasInClassInitializer());
  b.setVal93(e.IsAnonymousStructOrUnion());
  b.setVal94(e.IsBitField());
  b.setVal95(e.IsMutable());
  b.setVal96(e.IsUnnamedBitfield());
  b.setVal97(e.IsZeroLengthBitField());
  b.setVal98(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal84(es.EntityId(e.ContainingInterface()));
  b.setVal89(es.EntityId(e.NextInstanceVariable()));
  b.setVal99(e.Synthesize());
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
  b.setVal52(es.EntityId(e.Binding()));
  b.setVal53(es.EntityId(e.DecomposedDeclaration()));
  b.setVal61(es.EntityId(e.HoldingVariable()));
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
  b.setVal52(es.EntityId(e.MapperVariableReference()));
  b.setVal53(es.EntityId(e.PrevDeclarationInScope()));
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.Introducer()));
  auto v52 = e.NextUsingShadowDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal53(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal70(e.ConstructsVirtualBase());
  b.setVal61(es.EntityId(e.ConstructedBaseClass()));
  auto v62 = e.ConstructedBaseClassShadowDeclaration();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal71(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  b.setVal63(es.EntityId(e.NominatedBaseClass()));
  auto v72 = e.NominatedBaseClassShadowDeclaration();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal76(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal74(es.EntityId(e.Parent()));
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v45 = e.Expansions();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal51(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.IdentifierToken()));
  b.setVal52(es.EntityId(e.NamespaceKeyToken()));
  b.setVal53(es.EntityId(e.NominatedNamespaceAsWritten()));
  b.setVal61(es.EntityId(e.UsingToken()));
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
  auto v51 = e.TypeForDeclaration();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal69(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal69(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal70(e.DefaultArgumentWasInherited());
  b.setVal52(es.EntityId(e.DefaultArgument()));
  b.setVal53(es.EntityId(e.DefaultArgumentInfo()));
  b.setVal61(es.EntityId(e.DefaultArgumentToken()));
  b.setVal71(e.HasDefaultArgument());
  b.setVal76(e.HasTypeConstraint());
  b.setVal78(e.IsExpandedParameterPack());
  b.setVal80(e.IsPackExpansion());
  b.setVal82(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r52 = e.BraceRange(); auto rs52 = r52.Size()) {
    b.setVal52(es.EntityId(r52[0]));
    b.setVal53(es.EntityId(r52[rs52 - 1u]));
  } else {
    b.setVal52(0);
    b.setVal53(0);
  }
  b.setVal61(es.EntityId(e.InnerTokenStart()));
  b.setVal62(es.EntityId(e.OuterTokenStart()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v63 = e.TypedefNameForAnonymousDeclaration();
  if (v63) {
    auto id63 = es.EntityId(v63.value());    b.setVal63(id63);
    b.setVal70(id63 != mx::kInvalidEntityId);
  } else {
    b.setVal63(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal71(e.HasNameForLinkage());
  b.setVal76(e.IsBeingDefined());
  b.setVal78(e.IsClass());
  b.setVal80(e.IsCompleteDefinition());
  b.setVal82(e.IsCompleteDefinitionRequired());
  b.setVal90(e.IsDependentType());
  b.setVal93(e.IsEmbeddedInDeclarator());
  b.setVal94(e.IsEnum());
  b.setVal95(e.IsFreeStanding());
  b.setVal96(e.IsInterface());
  b.setVal97(e.IsStruct());
  b.setVal98(e.IsUnion());
  b.setVal99(e.MayHaveOutOfDateDefinition());
  do {
    auto v75 = e.TemplateParameterLists();
    auto sv75 = b.initVal75(static_cast<unsigned>(v75.size()));
    auto i75 = 0u;
    for (const auto &e75 : v75) {
      sv75.set(i75, es.PseudoId(e75));
      ++i75;
    }
  } while (false);
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal100(e.CanPassInRegisters());
  do {
    auto v46 = e.Fields();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  auto v72 = e.FindFirstNamedDataMember();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal101(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal102(e.HasFlexibleArrayMember());
  b.setVal103(e.HasLoadedFieldsFromExternalStorage());
  b.setVal104(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal105(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal106(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal107(e.HasObjectMember());
  b.setVal108(e.HasVolatileMember());
  b.setVal109(e.IsAnonymousStructOrUnion());
  b.setVal110(e.IsCapturedRecord());
  b.setVal111(e.IsInjectedClassName());
  b.setVal112(e.IsLambda());
  b.setVal113(e.IsMsStruct());
  b.setVal114(e.IsNonTrivialToPrimitiveCopy());
  b.setVal115(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal116(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal117(e.IsOrContainsUnion());
  b.setVal118(e.IsParameterDestroyedInCallee());
  b.setVal119(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v120 = e.AllowConstDefaultInitializer();
  if (v120) {
    b.setVal120(static_cast<bool>(v120.value()));
    b.setVal121(true);
  } else {
    b.setVal121(false);
  }
  do {
    auto ov144 = e.Bases();
    if (!ov144) {
      b.setVal122(false);
      break;
    }
    b.setVal122(true);
    auto v144 = std::move(*ov144);
    auto sv144 = b.initVal144(static_cast<unsigned>(v144.size()));
    auto i144 = 0u;
    for (const auto &e144 : v144) {
      sv144.set(i144, es.PseudoId(e144));
      ++i144;
    }
  } while (false);
  auto v85 = e.CalculateInheritanceModel();
  if (v85) {
    b.setVal85(static_cast<unsigned char>(v85.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  do {
    auto v57 = e.Constructors();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  do {
    auto ov179 = e.Friends();
    if (!ov179) {
      b.setVal124(false);
      break;
    }
    b.setVal124(true);
    auto v179 = std::move(*ov179);
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  auto v74 = e.Destructor();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal125(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal125(false);
  }
  auto v146 = e.GenericLambdaTemplateParameterList();
  if (v146) {
    b.setVal146(es.PseudoId(v146.value()));
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  auto v77 = e.InstantiatedFromMemberClass();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal127(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal127(false);
  }
  auto v79 = e.LambdaCallOperator();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal130(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal130(false);
  }
  auto v86 = e.LambdaCaptureDefault();
  if (v86) {
    b.setVal86(static_cast<unsigned char>(v86.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v81 = e.LambdaContextDeclaration();
  if (v81) {
    auto id81 = es.EntityId(v81.value());    b.setVal81(id81);
    b.setVal137(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal137(false);
  }
  do {
    auto ov180 = e.LambdaExplicitTemplateParameters();
    if (!ov180) {
      b.setVal138(false);
      break;
    }
    b.setVal138(true);
    auto v180 = std::move(*ov180);
    auto sv180 = b.initVal180(static_cast<unsigned>(v180.size()));
    auto i180 = 0u;
    for (const auto &e180 : v180) {
      sv180.set(i180, es.EntityId(e180));
      ++i180;
    }
  } while (false);
  auto v181 = e.LambdaManglingNumber();
  if (v181) {
    b.setVal181(static_cast<unsigned>(v181.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  auto v84 = e.LambdaTypeInfo();
  if (v84) {
    auto id84 = es.EntityId(v84.value());    b.setVal84(id84);
    b.setVal140(id84 != mx::kInvalidEntityId);
  } else {
    b.setVal84(mx::kInvalidEntityId);
    b.setVal140(false);
  }
  auto v87 = e.MSInheritanceModel();
  if (v87) {
    b.setVal87(static_cast<unsigned char>(v87.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v182 = e.NumBases();
  if (v182) {
    b.setVal182(static_cast<unsigned>(v182.value()));
    b.setVal142(true);
  } else {
    b.setVal142(false);
  }
  auto v183 = e.NumVirtualBases();
  if (v183) {
    b.setVal183(static_cast<unsigned>(v183.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v184 = e.ODRHash();
  if (v184) {
    b.setVal184(static_cast<unsigned>(v184.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v89 = e.TemplateInstantiationPattern();
  if (v89) {
    auto id89 = es.EntityId(v89.value());    b.setVal89(id89);
    b.setVal150(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
    b.setVal150(false);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v151 = e.HasAnyDependentBases();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v153 = e.HasConstexprDefaultConstructor();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasConstexprDestructor();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v157 = e.HasConstexprNonCopyMoveConstructor();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v163 = e.HasCopyAssignmentWithConstParameter();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasCopyConstructorWithConstParameter();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasDefaultConstructor();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasDefinition();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v172 = e.HasDirectFields();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasFriends();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasInClassInitializer();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v185 = e.HasInheritedAssignment();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v187 = e.HasInheritedConstructor();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasIrrelevantDestructor();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v191 = e.HasKnownLambdaInternalLinkage();
  if (v191) {
    b.setVal191(static_cast<bool>(v191.value()));
    b.setVal192(true);
  } else {
    b.setVal192(false);
  }
  auto v193 = e.HasMoveAssignment();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasMoveConstructor();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasMutableFields();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasNonLiteralTypeFieldsOrBases();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasNonTrivialCopyAssignment();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasNonTrivialCopyConstructor();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonTrivialCopyConstructorForCall();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialDefaultConstructor();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialDestructor();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialDestructorForCall();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialMoveAssignment();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialMoveConstructor();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialMoveConstructorForCall();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasPrivateFields();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasProtectedFields();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasSimpleCopyAssignment();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasSimpleCopyConstructor();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasSimpleDestructor();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasSimpleMoveAssignment();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasSimpleMoveConstructor();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasTrivialCopyAssignment();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasTrivialCopyConstructor();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasTrivialCopyConstructorForCall();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialDefaultConstructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialDestructor();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialDestructorForCall();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialMoveAssignment();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialMoveConstructor();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialMoveConstructorForCall();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasUninitializedReferenceMember();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasUserDeclaredConstructor();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasUserDeclaredCopyAssignment();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUserDeclaredCopyConstructor();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredDestructor();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredMoveAssignment();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredMoveConstructor();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserDeclaredMoveOperation();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserProvidedDefaultConstructor();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasVariantMembers();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.ImplicitCopyConstructorHasConstParameter();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.IsAbstract();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.IsAggregate();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.IsAnyDestructorNoReturn();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsCLike();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsCXX11StandardLayout();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  b.setVal285(e.IsDependentLambda());
  auto v286 = e.IsDynamicClass();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v288 = e.IsEffectivelyFinal();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  auto v290 = e.IsEmpty();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  b.setVal292(e.IsGenericLambda());
  auto v293 = e.IsInterfaceLike();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v295 = e.IsLiteral();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v129 = e.IsLocalClass();
  if (v129) {
    auto id129 = es.EntityId(v129.value());    b.setVal129(id129);
    b.setVal297(id129 != mx::kInvalidEntityId);
  } else {
    b.setVal129(mx::kInvalidEntityId);
    b.setVal297(false);
  }
  auto v298 = e.IsPOD();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v300 = e.IsPolymorphic();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsStandardLayout();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsStructural();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.IsTrivial();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.IsTriviallyCopyable();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.MayBeAbstract();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.MayBeDynamicClass();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.MayBeNonDynamicClass();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  do {
    auto ov318 = e.Methods();
    if (!ov318) {
      b.setVal319(false);
      break;
    }
    b.setVal319(true);
    auto v318 = std::move(*ov318);
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  auto v320 = e.NeedsImplicitCopyAssignment();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.NeedsImplicitCopyConstructor();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.NeedsImplicitDefaultConstructor();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsImplicitDestructor();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NeedsImplicitMoveAssignment();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsImplicitMoveConstructor();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsOverloadResolutionForDestructor();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NullFieldOffsetIsZero();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  do {
    auto ov145 = e.VirtualBases();
    if (!ov145) {
      b.setVal344(false);
      break;
    }
    b.setVal344(true);
    auto v145 = std::move(*ov145);
    auto sv145 = b.initVal145(static_cast<unsigned>(v145.size()));
    auto i145 = 0u;
    for (const auto &e145 : v145) {
      sv145.set(i145, es.PseudoId(e145));
      ++i145;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  b.setVal131(es.EntityId(e.ExternToken()));
  b.setVal132(es.EntityId(e.PointOfInstantiation()));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v345 = e.TemplateArguments();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.PseudoId(e345));
      ++i345;
    }
  } while (false);
  do {
    auto v346 = e.TemplateInstantiationArguments();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.PseudoId(e346));
      ++i346;
    }
  } while (false);
  b.setVal134(es.EntityId(e.TemplateKeywordToken()));
  b.setVal135(es.EntityId(e.TypeAsWritten()));
  b.setVal347(e.IsClassScopeExplicitSpecialization());
  b.setVal348(e.IsExplicitInstantiationOrSpecialization());
  b.setVal349(e.IsExplicitSpecialization());
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
    auto v46 = e.Enumerators();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  auto v72 = e.InstantiatedFromMemberEnum();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal100(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  auto v74 = e.IntegerType();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal101(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  if (auto r77 = e.IntegerTypeRange(); auto rs77 = r77.Size()) {
    b.setVal77(es.EntityId(r77[0]));
    b.setVal79(es.EntityId(r77[rs77 - 1u]));
  } else {
    b.setVal77(0);
    b.setVal79(0);
  }
  auto v81 = e.IntegerTypeSourceInfo();
  if (v81) {
    auto id81 = es.EntityId(v81.value());    b.setVal81(id81);
    b.setVal102(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal102(false);
  }
  auto v146 = e.ODRHash();
  if (v146) {
    b.setVal146(static_cast<unsigned>(v146.value()));
    b.setVal103(true);
  } else {
    b.setVal103(false);
  }
  b.setVal84(es.EntityId(e.PromotionType()));
  auto v89 = e.TemplateInstantiationPattern();
  if (v89) {
    auto id89 = es.EntityId(v89.value());    b.setVal89(id89);
    b.setVal104(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
    b.setVal104(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal105(e.IsClosed());
  b.setVal106(e.IsClosedFlag());
  b.setVal107(e.IsClosedNonFlag());
  b.setVal108(e.IsComplete());
  b.setVal109(e.IsFixed());
  b.setVal110(e.IsScoped());
  b.setVal111(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal52(es.EntityId(e.EllipsisToken()));
  b.setVal53(es.EntityId(e.TypenameToken()));
  b.setVal61(es.EntityId(e.UsingToken()));
  b.setVal70(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v52 = e.AnonymousDeclarationWithTypedefName();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal70(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal53(es.EntityId(e.TypeSourceInfo()));
  b.setVal61(es.EntityId(e.UnderlyingType()));
  b.setVal71(e.IsModed());
  b.setVal76(e.IsTransparentTag());
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
  auto v62 = e.DescribedAliasTemplate();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal78(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal78(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  b.setVal62(es.EntityId(e.ColonToken()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  b.setVal63(es.EntityId(e.VarianceToken()));
  b.setVal78(e.HasExplicitBound());
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
  b.setVal51(es.EntityId(e.ConstraintExpression()));
  b.setVal69(e.IsTypeConcept());
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
  b.setVal51(es.EntityId(e.AtToken()));
  b.setVal52(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal53(es.EntityId(e.GetterNameToken()));
  b.setVal61(es.EntityId(e.LParenToken()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal62(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal63(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal72(es.EntityId(e.SetterNameToken()));
  b.setVal74(es.EntityId(e.Type()));
  b.setVal77(es.EntityId(e.TypeSourceInfo()));
  b.setVal69(e.IsAtomic());
  b.setVal70(e.IsClassProperty());
  b.setVal71(e.IsDirectProperty());
  b.setVal76(e.IsInstanceProperty());
  b.setVal78(e.IsOptional());
  b.setVal80(e.IsReadOnly());
  b.setVal82(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal69(e.DefinedInNSObject());
  b.setVal51(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal52(es.EntityId(e.Category()));
  b.setVal53(es.EntityId(e.ClassInterface()));
  b.setVal61(es.EntityId(e.CmdDeclaration()));
  b.setVal62(es.EntityId(e.DeclaratorEndToken()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal63(es.EntityId(e.ReturnType()));
  b.setVal72(es.EntityId(e.ReturnTypeSourceInfo()));
  if (auto r74 = e.ReturnTypeSourceRange(); auto rs74 = r74.Size()) {
    b.setVal74(es.EntityId(r74[0]));
    b.setVal77(es.EntityId(r74[rs74 - 1u]));
  } else {
    b.setVal74(0);
    b.setVal77(0);
  }
  b.setVal79(es.EntityId(e.SelectorStartToken()));
  b.setVal81(es.EntityId(e.SelfDeclaration()));
  b.setVal70(e.HasRedeclaration());
  b.setVal71(e.HasRelatedResultType());
  b.setVal76(e.HasSkippedBody());
  b.setVal78(e.IsClassMethod());
  b.setVal80(e.IsDefined());
  b.setVal82(e.IsDesignatedInitializerForTheInterface());
  b.setVal90(e.IsDirectMethod());
  b.setVal93(e.IsInstanceMethod());
  b.setVal94(e.IsOptional());
  b.setVal95(e.IsOverriding());
  b.setVal96(e.IsPropertyAccessor());
  b.setVal97(e.IsRedeclaration());
  b.setVal98(e.IsSynthesizedAccessorStub());
  b.setVal99(e.IsThisDeclarationADesignatedInitializer());
  b.setVal100(e.IsVariadic());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  do {
    auto v46 = e.SelectorTokens();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
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

void SerializeObjCContainerDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v45 = e.ClassMethods();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  do {
    auto v46 = e.ClassProperties();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  if (auto r51 = e.AtEndRange(); auto rs51 = r51.Size()) {
    b.setVal51(es.EntityId(r51[0]));
    b.setVal52(es.EntityId(r51[rs51 - 1u]));
  } else {
    b.setVal51(0);
    b.setVal52(0);
  }
  b.setVal53(es.EntityId(e.AtStartToken()));
  do {
    auto v57 = e.InstanceMethods();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  do {
    auto v179 = e.InstanceProperties();
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  do {
    auto v180 = e.Methods();
    auto sv180 = b.initVal180(static_cast<unsigned>(v180.size()));
    auto i180 = 0u;
    for (const auto &e180 : v180) {
      sv180.set(i180, es.EntityId(e180));
      ++i180;
    }
  } while (false);
  do {
    auto v318 = e.Properties();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  pasta::DeclContext dc350(e);
  auto v350 = dc350.AlreadyLoadedDeclarations();
  auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
  auto i350 = 0u;
  for (const pasta::Decl &e350 : v350) {
    sv350.set(i350, es.EntityId(e350));
    ++i350;
  }
}

void SerializeObjCCategoryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal69(e.IsClassExtension());
  b.setVal61(es.EntityId(e.CategoryNameToken()));
  b.setVal62(es.EntityId(e.ClassInterface()));
  b.setVal63(es.EntityId(e.Implementation()));
  b.setVal72(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal74(es.EntityId(e.InstanceVariableRBraceToken()));
  b.setVal77(es.EntityId(e.NextClassCategory()));
  b.setVal79(es.EntityId(e.NextClassCategoryRaw()));
  do {
    auto v351 = e.InstanceVariables();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
  do {
    auto v352 = e.ProtocolTokens();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.Protocols();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.EntityId(e353));
      ++i353;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal69(e.HasDefinition());
  b.setVal70(e.IsNonRuntimeProtocol());
  do {
    auto v351 = e.ProtocolTokens();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
  do {
    auto v352 = e.Protocols();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v351 = e.AllReferencedProtocols();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
  b.setVal69(e.DeclaresOrInheritsDesignatedInitializers());
  b.setVal61(es.EntityId(e.CategoryListRaw()));
  b.setVal62(es.EntityId(e.EndOfDefinitionToken()));
  b.setVal63(es.EntityId(e.Implementation()));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto v72 = e.SuperClass();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal70(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal74(es.EntityId(e.SuperClassToken()));
  auto v77 = e.SuperClassTypeInfo();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal71(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  auto v79 = e.SuperClassType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal76(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal81(es.EntityId(e.TypeForDeclaration()));
  b.setVal78(e.HasDefinition());
  b.setVal80(e.HasDesignatedInitializers());
  b.setVal82(e.IsArcWeakrefUnavailable());
  b.setVal90(e.IsImplicitInterfaceDeclaration());
  b.setVal84(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  do {
    auto v352 = e.InstanceVariables();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.KnownCategories();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.EntityId(e353));
      ++i353;
    }
  } while (false);
  do {
    auto v354 = e.KnownExtensions();
    auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
    auto i354 = 0u;
    for (const auto &e354 : v354) {
      sv354.set(i354, es.EntityId(e354));
      ++i354;
    }
  } while (false);
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
  do {
    auto v357 = e.VisibleCategories();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
    }
  } while (false);
  do {
    auto v358 = e.VisibleExtensions();
    auto sv358 = b.initVal358(static_cast<unsigned>(v358.size()));
    auto i358 = 0u;
    for (const auto &e358 : v358) {
      sv358.set(i358, es.EntityId(e358));
      ++i358;
    }
  } while (false);
}

void SerializeObjCImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal61(es.EntityId(e.ClassInterface()));
  do {
    auto v351 = e.PropertyImplementations();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal62(es.EntityId(e.CategoryDeclaration()));
  b.setVal63(es.EntityId(e.CategoryNameToken()));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal62(es.EntityId(e.InstanceVariableLBraceToken()));
  b.setVal63(es.EntityId(e.InstanceVariableRBraceToken()));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal72(es.EntityId(e.SuperClass()));
  b.setVal74(es.EntityId(e.SuperClassToken()));
  b.setVal69(e.HasDestructors());
  b.setVal70(e.HasNonZeroConstructors());
  do {
    auto v352 = e.InstanceVariables();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeNamespaceAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.AliasToken()));
  b.setVal52(es.EntityId(e.AliasedNamespace()));
  b.setVal53(es.EntityId(e.NamespaceToken()));
  b.setVal61(es.EntityId(e.TargetNameToken()));
}

void SerializeLinkageSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v45 = e.ChildrenExpression();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal43(es.EntityId(e.ExtendingDeclaration()));
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal51(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v45 = e.IdentifierTokens();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
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
  auto v43 = e.FriendDeclaration();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal44(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal44(false);
  }
  b.setVal51(es.EntityId(e.FriendToken()));
  b.setVal52(es.EntityId(e.FriendType()));
  b.setVal47(e.IsUnsupportedFriend());
  do {
    auto v75 = e.FriendTypeTemplateParameterLists();
    auto sv75 = b.initVal75(static_cast<unsigned>(v75.size()));
    auto i75 = 0u;
    for (const auto &e75 : v75) {
      sv75.set(i75, es.PseudoId(e75));
      ++i75;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.AssemblyToken()));
  b.setVal51(es.EntityId(e.AssemblyString()));
  b.setVal52(es.EntityId(e.RParenToken()));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(es.EntityId(e.ExportToken()));
  b.setVal51(es.EntityId(e.RBraceToken()));
  b.setVal44(e.HasBraces());
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
