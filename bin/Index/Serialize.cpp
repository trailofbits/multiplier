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

#include <glog/logging.h>
#include "EntityMapper.h"
#include "Util.h"

namespace indexer {

void SerializeTemplateParameterList(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateParameterList));
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
  auto t8 = e.TemplateKeywordToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.LeftAngleToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.RightAngleToken();
  b.setVal10(es.EntityId(t10));
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
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateArgument));
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
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kCXXBaseSpecifier));
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal8(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal8(0);
  }
  auto t9 = e.BaseTypeToken();
  b.setVal9(es.EntityId(t9));
  b.setVal4(e.IsVirtual());
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal5(e.IsPackExpansion());
  b.setVal7(e.ConstructorsAreInherited());
  auto v10 = e.EllipsisToken();
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
  auto v33 = e.ContainedAutoType();
  if (v33) {
    auto id33 = es.EntityId(v33.value());    b.setVal33(id33);
    b.setVal34(id33 != mx::kInvalidEntityId);
  } else {
    b.setVal33(mx::kInvalidEntityId);
    b.setVal34(false);
  }
  auto v35 = e.ContainedDeducedType();
  if (v35) {
    auto id35 = es.EntityId(v35.value());    b.setVal35(id35);
    b.setVal36(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal36(false);
  }
  b.setVal37(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  b.setVal38(es.EntityId(e.LocallyUnqualifiedSingleStepDesugaredType()));
  auto v39 = e.Nullability();
  if (v39) {
    b.setVal39(static_cast<unsigned char>(v39.value()));
    b.setVal40(true);
  } else {
    b.setVal40(false);
  }
  auto v41 = e.PointeeCXXRecordDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal42(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal42(false);
  }
  auto v43 = e.PointeeOrArrayElementType();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal44(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal44(false);
  }
  auto v45 = e.PointeeType();
  if (v45) {
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal46(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal46(false);
  }
  auto v47 = e.ScalarTypeKind();
  if (v47) {
    b.setVal47(static_cast<unsigned char>(v47.value()));
    b.setVal48(true);
  } else {
    b.setVal48(false);
  }
  auto v49 = e.SveElementType();
  if (v49) {
    auto id49 = es.EntityId(v49.value());    b.setVal49(id49);
    b.setVal50(id49 != mx::kInvalidEntityId);
  } else {
    b.setVal49(mx::kInvalidEntityId);
    b.setVal50(false);
  }
  b.setVal51(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal52(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal53(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal54(e.HasAutoForTrailingReturnType());
  b.setVal55(e.HasFloatingRepresentation());
  b.setVal56(e.HasIntegerRepresentation());
  b.setVal57(e.HasObjCPointerRepresentation());
  b.setVal58(e.HasPointerRepresentation());
  b.setVal59(e.HasSignedIntegerRepresentation());
  b.setVal60(e.HasSizedVLAType());
  b.setVal61(e.HasUnnamedOrLocalType());
  b.setVal62(e.HasUnsignedIntegerRepresentation());
  b.setVal63(e.IsAggregateType());
  b.setVal64(e.IsAlignValueT());
  b.setVal65(e.IsAnyCharacterType());
  b.setVal66(e.IsAnyComplexType());
  b.setVal67(e.IsAnyPointerType());
  b.setVal68(e.IsArithmeticType());
  b.setVal69(e.IsArrayType());
  b.setVal70(e.IsAtomicType());
  b.setVal71(e.IsBFloat16Type());
  b.setVal72(e.IsBlockCompatibleObjCPointerType());
  b.setVal73(e.IsBlockPointerType());
  b.setVal74(e.IsBooleanType());
  b.setVal75(e.IsBuiltinType());
  b.setVal76(e.IsCARCBridgableType());
  b.setVal77(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal78(e.IsCUDADeviceBuiltinTextureType());
  b.setVal79(e.IsCanonicalUnqualified());
  b.setVal80(e.IsChar16Type());
  b.setVal81(e.IsChar32Type());
  b.setVal82(e.IsChar8Type());
  b.setVal83(e.IsCharacterType());
  b.setVal84(e.IsClassType());
  b.setVal85(e.IsClkEventT());
  b.setVal86(e.IsComplexIntegerType());
  b.setVal87(e.IsComplexType());
  b.setVal88(e.IsCompoundType());
  b.setVal89(e.IsConstantArrayType());
  b.setVal90(e.IsConstantMatrixType());
  auto v91 = e.IsConstantSizeType();
  if (v91) {
    b.setVal91(static_cast<bool>(v91.value()));
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  b.setVal93(e.IsDecltypeType());
  b.setVal94(e.IsDependentAddressSpaceType());
  b.setVal95(e.IsDependentSizedArrayType());
  b.setVal96(e.IsDependentType());
  b.setVal97(e.IsElaboratedTypeSpecifier());
  b.setVal98(e.IsEnumeralType());
  b.setVal99(e.IsEventT());
  b.setVal100(e.IsExtIntType());
  b.setVal101(e.IsExtVectorType());
  b.setVal102(e.IsFixedPointOrIntegerType());
  b.setVal103(e.IsFixedPointType());
  b.setVal104(e.IsFloat128Type());
  b.setVal105(e.IsFloat16Type());
  b.setVal106(e.IsFloatingType());
  b.setVal107(e.IsFromAST());
  b.setVal108(e.IsFunctionNoProtoType());
  b.setVal109(e.IsFunctionPointerType());
  b.setVal110(e.IsFunctionProtoType());
  b.setVal111(e.IsFunctionReferenceType());
  b.setVal112(e.IsFunctionType());
  b.setVal113(e.IsFundamentalType());
  b.setVal114(e.IsHalfType());
  b.setVal115(e.IsImageType());
  b.setVal116(e.IsIncompleteArrayType());
  b.setVal117(e.IsIncompleteOrObjectType());
  b.setVal118(e.IsIncompleteType());
  b.setVal119(e.IsInstantiationDependentType());
  b.setVal120(e.IsIntegerType());
  b.setVal121(e.IsIntegralOrEnumerationType());
  b.setVal122(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal123(e.IsIntegralType());
  b.setVal124(e.IsInterfaceType());
  b.setVal125(e.IsLValueReferenceType());
  b.setVal126(e.IsLinkageValid());
  auto v127 = e.IsLiteralType();
  if (v127) {
    b.setVal127(static_cast<bool>(v127.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  b.setVal129(e.IsMatrixType());
  b.setVal130(e.IsMemberDataPointerType());
  b.setVal131(e.IsMemberFunctionPointerType());
  b.setVal132(e.IsMemberPointerType());
  b.setVal133(e.IsNonOverloadPlaceholderType());
  b.setVal134(e.IsNothrowT());
  b.setVal135(e.IsNullPointerType());
  b.setVal136(e.IsOCLExtOpaqueType());
  b.setVal137(e.IsOCLImage1dArrayROType());
  b.setVal138(e.IsOCLImage1dArrayRWType());
  b.setVal139(e.IsOCLImage1dArrayWOType());
  b.setVal140(e.IsOCLImage1dBufferROType());
  b.setVal141(e.IsOCLImage1dBufferRWType());
  b.setVal142(e.IsOCLImage1dBufferWOType());
  b.setVal143(e.IsOCLImage1dROType());
  b.setVal144(e.IsOCLImage1dRWType());
  b.setVal145(e.IsOCLImage1dWOType());
  b.setVal146(e.IsOCLImage2dArrayDepthROType());
  b.setVal147(e.IsOCLImage2dArrayDepthRWType());
  b.setVal148(e.IsOCLImage2dArrayDepthWOType());
  b.setVal149(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal150(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal151(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal152(e.IsOCLImage2dArrayMSAAROType());
  b.setVal153(e.IsOCLImage2dArrayMSAARWType());
  b.setVal154(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal155(e.IsOCLImage2dArrayROType());
  b.setVal156(e.IsOCLImage2dArrayRWType());
  b.setVal157(e.IsOCLImage2dArrayWOType());
  b.setVal158(e.IsOCLImage2dDepthROType());
  b.setVal159(e.IsOCLImage2dDepthRWType());
  b.setVal160(e.IsOCLImage2dDepthWOType());
  b.setVal161(e.IsOCLImage2dMSAADepthROType());
  b.setVal162(e.IsOCLImage2dMSAADepthRWType());
  b.setVal163(e.IsOCLImage2dMSAADepthWOType());
  b.setVal164(e.IsOCLImage2dMSAAROType());
  b.setVal165(e.IsOCLImage2dMSAARWType());
  b.setVal166(e.IsOCLImage2dMSAAWOType());
  b.setVal167(e.IsOCLImage2dROType());
  b.setVal168(e.IsOCLImage2dRWType());
  b.setVal169(e.IsOCLImage2dWOType());
  b.setVal170(e.IsOCLImage3dROType());
  b.setVal171(e.IsOCLImage3dRWType());
  b.setVal172(e.IsOCLImage3dWOType());
  b.setVal173(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal174(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal175(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal176(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal177(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal178(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal179(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal180(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal181(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal182(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal183(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal184(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal185(e.IsOCLIntelSubgroupAVCType());
  b.setVal186(e.IsObjCARCBridgableType());
  auto v187 = e.IsObjCARCImplicitlyUnretainedType();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  b.setVal189(e.IsObjCBoxableRecordType());
  b.setVal190(e.IsObjCBuiltinType());
  b.setVal191(e.IsObjCClassOrClassKindOfType());
  b.setVal192(e.IsObjCClassType());
  b.setVal193(e.IsObjCIdType());
  b.setVal194(e.IsObjCIndependentClassType());
  b.setVal195(e.IsObjCIndirectLifetimeType());
  b.setVal196(e.IsObjCInertUnsafeUnretainedType());
  b.setVal197(e.IsObjCLifetimeType());
  b.setVal198(e.IsObjCNSObjectType());
  b.setVal199(e.IsObjCObjectOrInterfaceType());
  b.setVal200(e.IsObjCObjectPointerType());
  b.setVal201(e.IsObjCObjectType());
  b.setVal202(e.IsObjCQualifiedClassType());
  b.setVal203(e.IsObjCQualifiedIdType());
  b.setVal204(e.IsObjCQualifiedInterfaceType());
  b.setVal205(e.IsObjCRetainableType());
  b.setVal206(e.IsObjCSelType());
  b.setVal207(e.IsObjectPointerType());
  b.setVal208(e.IsObjectType());
  b.setVal209(e.IsOpenCLSpecificType());
  b.setVal210(e.IsOverloadableType());
  b.setVal211(e.IsPipeType());
  b.setVal212(e.IsPlaceholderType());
  b.setVal213(e.IsPointerType());
  b.setVal214(e.IsPromotableIntegerType());
  b.setVal215(e.IsQueueT());
  b.setVal216(e.IsRValueReferenceType());
  b.setVal217(e.IsRealFloatingType());
  b.setVal218(e.IsRealType());
  b.setVal219(e.IsRecordType());
  b.setVal220(e.IsReferenceType());
  b.setVal221(e.IsReserveIDT());
  b.setVal222(e.IsSamplerT());
  b.setVal223(e.IsSaturatedFixedPointType());
  b.setVal224(e.IsScalarType());
  b.setVal225(e.IsScopedEnumeralType());
  b.setVal226(e.IsSignedFixedPointType());
  b.setVal227(e.IsSignedIntegerOrEnumerationType());
  b.setVal228(e.IsSignedIntegerType());
  b.setVal229(e.IsSizelessBuiltinType());
  b.setVal230(e.IsSizelessType());
  b.setVal231(e.IsSpecifierType());
  auto v232 = e.IsStandardLayoutType();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  b.setVal234(e.IsStdByteType());
  b.setVal235(e.IsStructuralType());
  b.setVal236(e.IsStructureOrClassType());
  b.setVal237(e.IsStructureType());
  b.setVal238(e.IsTemplateTypeParmType());
  b.setVal239(e.IsTypedefNameType());
  b.setVal240(e.IsUndeducedAutoType());
  b.setVal241(e.IsUndeducedType());
  b.setVal242(e.IsUnionType());
  b.setVal243(e.IsUnsaturatedFixedPointType());
  b.setVal244(e.IsUnscopedEnumerationType());
  b.setVal245(e.IsUnsignedFixedPointType());
  b.setVal246(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal247(e.IsUnsignedIntegerType());
  b.setVal248(e.IsVLSTBuiltinType());
  b.setVal249(e.IsVariableArrayType());
  b.setVal250(e.IsVariablyModifiedType());
  b.setVal251(e.IsVectorType());
  b.setVal252(e.IsVisibilityExplicit());
  b.setVal253(e.IsVoidPointerType());
  b.setVal254(e.IsVoidType());
  b.setVal255(e.IsWideCharacterType());
  b.setVal256(es.EntityId(e.IgnoreParentheses()));
  b.setVal257(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal258(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal259(es.EntityId(e.CanonicalType()));
  b.setVal260(es.EntityId(e.DesugaredType()));
  b.setVal261(es.EntityId(e.LocalUnqualifiedType()));
  b.setVal262(es.EntityId(e.NonLValueExpressionType()));
  b.setVal263(es.EntityId(e.NonPackExpansionType()));
  b.setVal264(es.EntityId(e.NonReferenceType()));
  b.setVal265(es.EntityId(e.SingleStepDesugaredType()));
  b.setVal266(e.HasAddressSpace());
  b.setVal267(e.HasLocalNonFastQualifiers());
  b.setVal268(e.HasLocalQualifiers());
  b.setVal269(e.HasNonTrivialObjCLifetime());
  b.setVal270(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal271(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal272(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal273(e.HasQualifiers());
  b.setVal274(e.HasStrongOrWeakObjCLifetime());
  b.setVal275(e.IsCForbiddenLValueType());
  b.setVal276(e.IsCXX11PODType());
  b.setVal277(e.IsCXX98PODType());
  b.setVal278(e.IsCanonical());
  b.setVal279(e.IsCanonicalAsParameter());
  b.setVal280(e.IsConstQualified());
  b.setVal281(e.IsConstant());
  b.setVal282(static_cast<unsigned char>(mx::FromPasta(e.IsDestructedType())));
  b.setVal283(e.IsLocalConstQualified());
  b.setVal284(e.IsLocalRestrictQualified());
  b.setVal285(e.IsLocalVolatileQualified());
  b.setVal286(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveCopy())));
  b.setVal287(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDefaultInitialize())));
  b.setVal288(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDestructiveMove())));
  b.setVal289(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal290(e.IsNull());
  b.setVal291(e.IsObjCGCStrong());
  b.setVal292(e.IsObjCGCWeak());
  b.setVal293(e.IsPODType());
  b.setVal294(e.IsRestrictQualified());
  b.setVal295(e.IsTrivialType());
  b.setVal296(e.IsTriviallyCopyableType());
  b.setVal297(e.IsVolatileQualified());
  b.setVal298(e.MayBeDynamicClass());
  b.setVal299(e.MayBeNotDynamicClass());
  b.setVal300(es.EntityId(e.StripObjCKindOfType()));
  b.setVal301(es.EntityId(e.WithConst()));
  b.setVal302(es.EntityId(e.WithRestrict()));
  b.setVal303(es.EntityId(e.WithVolatile()));
  b.setVal304(es.EntityId(e.WithoutLocalFastQualifiers()));
}

void SerializeTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal307(e.IsParameterPack());
  b.setVal308(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.AliasedType()));
  b.setVal307(e.IsCurrentInstantiation());
  b.setVal308(e.IsSugared());
  b.setVal309(e.IsTypeAlias());
  do {
    auto v310 = e.TemplateArguments();
    auto sv310 = b.initVal310(static_cast<unsigned>(v310.size()));
    auto i310 = 0u;
    for (const auto &e310 : v310) {
      sv310.set(i310, es.PseudoId(e310));
      ++i310;
    }
  } while (false);
}

void SerializeTagType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Declaration()));
  b.setVal307(e.IsBeingDefined());
}

void SerializeRecordType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.HasConstFields());
  b.setVal309(e.IsSugared());
}

void SerializeEnumType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ReplacedParameter()));
  b.setVal311(es.EntityId(e.ReplacementType()));
  b.setVal307(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ReplacedParameter()));
  b.setVal307(e.IsSugared());
}

void SerializeReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal307(e.IsInnerReference());
  b.setVal308(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal309(e.IsSugared());
}

void SerializeLValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal309(e.IsSugared());
}

void SerializePointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSugared());
}

void SerializePipeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal307(e.IsReadOnly());
  b.setVal308(e.IsSugared());
}

void SerializeParenType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.InnerType()));
  b.setVal307(e.IsSugared());
}

void SerializePackExpansionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  auto v312 = e.NumExpansions();
  if (v312) {
    b.setVal312(static_cast<unsigned>(v312.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  b.setVal306(es.EntityId(e.Pattern()));
  b.setVal308(e.IsSugared());
}

void SerializeObjCTypeParamType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal307(e.IsSugared());
}

void SerializeObjCObjectType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.BaseType()));
  b.setVal311(es.EntityId(e.Interface()));
  auto v313 = e.SuperClassType();
  if (v313) {
    auto id313 = es.EntityId(v313.value());    b.setVal313(id313);
    b.setVal307(id313 != mx::kInvalidEntityId);
  } else {
    b.setVal313(mx::kInvalidEntityId);
    b.setVal307(false);
  }
  do {
    auto v314 = e.TypeArguments();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.EntityId(e314));
      ++i314;
    }
  } while (false);
  do {
    auto v315 = e.TypeArgumentsAsWritten();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal308(e.IsKindOfType());
  b.setVal309(e.IsKindOfTypeAsWritten());
  b.setVal316(e.IsObjCClass());
  b.setVal317(e.IsObjCId());
  b.setVal318(e.IsObjCQualifiedClass());
  b.setVal319(e.IsObjCQualifiedId());
  b.setVal320(e.IsObjCUnqualifiedClass());
  b.setVal321(e.IsObjCUnqualifiedId());
  b.setVal322(e.IsObjCUnqualifiedIdOrClass());
  b.setVal323(e.IsSpecialized());
  b.setVal324(e.IsSpecializedAsWritten());
  b.setVal325(e.IsSugared());
  b.setVal326(e.IsUnspecialized());
  b.setVal327(e.IsUnspecializedAsWritten());
  b.setVal328(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
}

void SerializeObjCInterfaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal329(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.InterfaceDeclaration()));
  b.setVal311(es.EntityId(e.InterfaceType()));
  b.setVal313(es.EntityId(e.ObjectType()));
  b.setVal328(es.EntityId(e.SuperClassType()));
  do {
    auto v314 = e.TypeArguments();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.EntityId(e314));
      ++i314;
    }
  } while (false);
  do {
    auto v315 = e.TypeArgumentsAsWritten();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal307(e.IsKindOfType());
  b.setVal308(e.IsObjCIdOrClassType());
  b.setVal309(e.IsSpecialized());
  b.setVal316(e.IsSpecializedAsWritten());
  b.setVal317(e.IsSugared());
  b.setVal318(e.IsUnspecialized());
  b.setVal319(e.IsUnspecializedAsWritten());
  do {
    auto v330 = e.Qualifieds();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
    }
  } while (false);
  b.setVal329(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
  do {
    auto v331 = e.Protocols();
    auto sv331 = b.initVal331(static_cast<unsigned>(v331.size()));
    auto i331 = 0u;
    for (const auto &e331 : v331) {
      sv331.set(i331, es.EntityId(e331));
      ++i331;
    }
  } while (false);
}

void SerializeMemberPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Class()));
  b.setVal311(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal307(e.IsMemberDataPointer());
  b.setVal308(e.IsMemberFunctionPointer());
  b.setVal309(e.IsSugared());
}

void SerializeMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal307(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  auto t311 = e.AttributeToken();
  b.setVal311(es.EntityId(t311));
  b.setVal313(es.EntityId(e.ColumnExpression()));
  b.setVal328(es.EntityId(e.RowExpression()));
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
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ModifiedType()));
  b.setVal311(es.EntityId(e.UnderlyingType()));
  b.setVal307(e.IsSugared());
}

void SerializeInjectedClassNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal311(es.EntityId(e.InjectedSpecializationType()));
  b.setVal313(es.EntityId(e.InjectedTST()));
  b.setVal307(e.IsSugared());
}

void SerializeFunctionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal305(es.EntityId(e.CallResultType()));
  b.setVal307(e.CmseNSCallAttribute());
  b.setVal308(e.HasRegParm());
  b.setVal309(e.NoReturnAttribute());
  b.setVal306(es.EntityId(e.ReturnType()));
  b.setVal316(e.IsConst());
  b.setVal317(e.IsRestrict());
  b.setVal318(e.IsVolatile());
}

void SerializeFunctionProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.CanThrow())));
  b.setVal311(es.EntityId(e.Desugar()));
  do {
    auto v314 = e.Exceptions();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.EntityId(e314));
      ++i314;
    }
  } while (false);
  auto t313 = e.EllipsisToken();
  b.setVal313(es.EntityId(t313));
  auto v328 = e.ExceptionSpecDeclaration();
  if (v328) {
    auto id328 = es.EntityId(v328.value());    b.setVal328(id328);
    b.setVal319(id328 != mx::kInvalidEntityId);
  } else {
    b.setVal328(mx::kInvalidEntityId);
    b.setVal319(false);
  }
  auto v329 = e.ExceptionSpecTemplate();
  if (v329) {
    auto id329 = es.EntityId(v329.value());    b.setVal329(id329);
    b.setVal320(id329 != mx::kInvalidEntityId);
  } else {
    b.setVal329(mx::kInvalidEntityId);
    b.setVal320(false);
  }
  b.setVal334(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v335 = e.NoexceptExpression();
  if (v335) {
    auto id335 = es.EntityId(v335.value());    b.setVal335(id335);
    b.setVal321(id335 != mx::kInvalidEntityId);
  } else {
    b.setVal335(mx::kInvalidEntityId);
    b.setVal321(false);
  }
  do {
    auto v315 = e.ParameterTypes();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal336(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal322(e.HasDependentExceptionSpec());
  b.setVal323(e.HasDynamicExceptionSpec());
  b.setVal324(e.HasExceptionSpec());
  b.setVal325(e.HasExtParameterInfos());
  b.setVal326(e.HasInstantiationDependentExceptionSpec());
  b.setVal327(e.HasNoexceptExceptionSpec());
  b.setVal337(e.HasTrailingReturn());
  b.setVal338(e.IsNothrow());
  b.setVal339(e.IsSugared());
  b.setVal340(e.IsTemplateVariadic());
  b.setVal341(e.IsVariadic());
  do {
    auto v330 = e.ExceptionTypes();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal319(e.IsSugared());
}

void SerializeExtIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSigned());
  b.setVal308(e.IsSugared());
  b.setVal309(e.IsUnsigned());
}

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  auto t306 = e.AttributeToken();
  b.setVal306(es.EntityId(t306));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal313(es.EntityId(e.SizeExpression()));
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal307(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  auto t306 = e.AttributeToken();
  b.setVal306(es.EntityId(t306));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal313(es.EntityId(e.SizeExpression()));
  b.setVal307(e.IsSugared());
}

void SerializeDependentExtIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentExtIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.NumBitsExpression()));
  b.setVal307(e.IsSigned());
  b.setVal308(e.IsSugared());
  b.setVal309(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.AddrSpaceExpression()));
  auto t311 = e.AttributeToken();
  b.setVal311(es.EntityId(t311));
  b.setVal307(e.IsSugared());
}

void SerializeDeducedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ResolvedType()));
  b.setVal307(e.IsDeduced());
  b.setVal308(e.IsSugared());
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
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v310 = e.TypeConstraintArguments();
    auto sv310 = b.initVal310(static_cast<unsigned>(v310.size()));
    auto i310 = 0u;
    for (const auto &e310 : v310) {
      sv310.set(i310, es.PseudoId(e310));
      ++i310;
    }
  } while (false);
  b.setVal311(es.EntityId(e.TypeConstraintConcept()));
  b.setVal309(e.IsConstrained());
  b.setVal316(e.IsDecltypeAuto());
}

void SerializeDecltypeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.UnderlyingExpression()));
  b.setVal311(es.EntityId(e.UnderlyingType()));
  b.setVal307(e.IsSugared());
}

void SerializeComplexType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal307(e.IsSugared());
}

void SerializeBuiltinType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsFloatingPoint());
  b.setVal308(e.IsInteger());
  b.setVal309(e.IsSignedInteger());
  b.setVal316(e.IsSugared());
  b.setVal317(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSugared());
}

void SerializeAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal342(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal306(es.EntityId(e.EquivalentType()));
  auto v332 = e.ImmediateNullability();
  if (v332) {
    b.setVal332(static_cast<unsigned char>(v332.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  b.setVal311(es.EntityId(e.ModifiedType()));
  b.setVal308(e.IsCallingConv());
  b.setVal309(e.IsMSTypeSpec());
  b.setVal316(e.IsQualifier());
  b.setVal317(e.IsSugared());
}

void SerializeAtomicType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ValueType()));
  b.setVal307(e.IsSugared());
}

void SerializeArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.ElementType()));
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  if (auto r311 = e.BracketsRange(); auto rs311 = r311.Size()) {
    b.setVal311(es.EntityId(r311[0]));
    b.setVal313(es.EntityId(r311[rs311 - 1u]));
  } else {
    b.setVal311(0);
    b.setVal313(0);
  }
  auto t328 = e.LBracketToken();
  b.setVal328(es.EntityId(t328));
  auto t329 = e.RBracketToken();
  b.setVal329(es.EntityId(t329));
  b.setVal335(es.EntityId(e.SizeExpression()));
  b.setVal307(e.IsSugared());
}

void SerializeIncompleteArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  if (auto r311 = e.BracketsRange(); auto rs311 = r311.Size()) {
    b.setVal311(es.EntityId(r311[0]));
    b.setVal313(es.EntityId(r311[rs311 - 1u]));
  } else {
    b.setVal311(0);
    b.setVal313(0);
  }
  auto t328 = e.LBracketToken();
  b.setVal328(es.EntityId(t328));
  auto t329 = e.RBracketToken();
  b.setVal329(es.EntityId(t329));
  b.setVal335(es.EntityId(e.SizeExpression()));
  b.setVal307(e.IsSugared());
}

void SerializeConstantArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  auto v311 = e.SizeExpression();
  if (v311) {
    auto id311 = es.EntityId(v311.value());    b.setVal311(id311);
    b.setVal307(id311 != mx::kInvalidEntityId);
  } else {
    b.setVal311(mx::kInvalidEntityId);
    b.setVal307(false);
  }
  b.setVal308(e.IsSugared());
}

void SerializeAdjustedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ResolvedType()));
  b.setVal311(es.EntityId(e.OriginalType()));
  b.setVal307(e.IsSugared());
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
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.NamedType()));
  auto v311 = e.OwnedTagDeclaration();
  if (v311) {
    auto id311 = es.EntityId(v311.value());    b.setVal311(id311);
    b.setVal307(id311 != mx::kInvalidEntityId);
  } else {
    b.setVal311(mx::kInvalidEntityId);
    b.setVal307(false);
  }
  b.setVal308(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSugared());
  do {
    auto v310 = e.TemplateArguments();
    auto sv310 = b.initVal310(static_cast<unsigned>(v310.size()));
    auto i310 = 0u;
    for (const auto &e310 : v310) {
      sv310.set(i310, es.PseudoId(e310));
      ++i310;
    }
  } while (false);
}

void SerializeDependentNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal307(e.IsSugared());
}

void SerializeVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.ElementType()));
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal307(e.IsSugared());
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
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal307(e.IsSugared());
}

void SerializeUnaryTransformType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.BaseType()));
  b.setVal332(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal311(es.EntityId(e.UnderlyingType()));
  b.setVal307(e.IsSugared());
}

void SerializeTypedefType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.Declaration()));
  b.setVal307(e.IsSugared());
}

void SerializeTypeOfType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.UnderlyingType()));
  b.setVal307(e.IsSugared());
}

void SerializeTypeOfExprType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal305(es.EntityId(e.Desugar()));
  b.setVal306(es.EntityId(e.UnderlyingExpression()));
  b.setVal307(e.IsSugared());
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
  auto t4 = e.BeginToken();
  b.setVal4(es.EntityId(t4));
  auto t5 = e.EndToken();
  b.setVal5(es.EntityId(t5));
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
  auto t15 = e.TryToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeSEHLeaveStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.LeaveToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeSEHFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  auto t11 = e.FinallyToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeSEHExceptStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Block()));
  auto t11 = e.ExceptToken();
  b.setVal11(es.EntityId(t11));
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
  auto t12 = e.ReturnToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeObjCForCollectionStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Collection()));
  b.setVal12(es.EntityId(e.Element()));
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto t15 = e.RParenToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeObjCAutoreleasePoolStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.AtToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.AtTryToken();
  b.setVal10(es.EntityId(t10));
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
  auto t11 = e.ThrowToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeObjCAtSynchronizedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.AtSynchronizedToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SynchBody()));
  b.setVal12(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.AtFinallyToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.AtCatchToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.CatchBody()));
  b.setVal12(es.EntityId(e.CatchParameterDeclaration()));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
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
  auto t15 = e.TargetCallToken();
  b.setVal15(es.EntityId(t15));
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
  auto t10 = e.SemiToken();
  b.setVal10(es.EntityId(t10));
  b.setVal13(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.KeywordToken();
  b.setVal10(es.EntityId(t10));
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
  auto t11 = e.GotoToken();
  b.setVal11(es.EntityId(t11));
  auto t12 = e.StarToken();
  b.setVal12(es.EntityId(t12));
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
  auto t15 = e.ElseToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.IfToken();
  b.setVal18(es.EntityId(t18));
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal22(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal22(false);
  }
  auto t20 = e.LParenToken();
  b.setVal20(es.EntityId(t20));
  auto t27 = e.RParenToken();
  b.setVal27(es.EntityId(t27));
  b.setVal28(es.EntityId(e.Then()));
  b.setVal57(e.HasElseStorage());
  b.setVal58(e.HasInitializerStorage());
  b.setVal59(e.HasVariableStorage());
  b.setVal60(e.IsConstexpr());
  b.setVal61(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.GotoToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.Label()));
  auto t12 = e.LabelToken();
  b.setVal12(es.EntityId(t12));
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
  auto t15 = e.ForToken();
  b.setVal15(es.EntityId(t15));
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
  auto t20 = e.LParenToken();
  b.setVal20(es.EntityId(t20));
  auto t27 = e.RParenToken();
  b.setVal27(es.EntityId(t27));
}

void SerializeDoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto t12 = e.DoToken();
  b.setVal12(es.EntityId(t12));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
  auto t15 = e.WhileToken();
  b.setVal15(es.EntityId(t15));
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
  auto t10 = e.KeywordToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.Operand()));
  b.setVal12(es.EntityId(e.PromiseCall()));
  b.setVal13(e.IsImplicit());
}

void SerializeContinueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.ContinueToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeCompoundStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.LeftBraceToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.RightBraceToken();
  b.setVal11(es.EntityId(t11));
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
  auto t11 = e.TryToken();
  b.setVal11(es.EntityId(t11));
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
  auto t12 = e.CoawaitToken();
  b.setVal12(es.EntityId(t12));
  auto t14 = e.ColonToken();
  b.setVal14(es.EntityId(t14));
  b.setVal15(es.EntityId(e.Condition()));
  b.setVal18(es.EntityId(e.EndStatement()));
  auto t19 = e.ForToken();
  b.setVal19(es.EntityId(t19));
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
  auto t30 = e.RParenToken();
  b.setVal30(es.EntityId(t30));
  b.setVal31(es.EntityId(e.RangeInitializer()));
  b.setVal32(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.CatchToken();
  b.setVal10(es.EntityId(t10));
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
  auto t10 = e.BreakToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal63(e.GenerateAssemblyString());
  auto t10 = e.AssemblyToken();
  b.setVal10(es.EntityId(t10));
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
  auto t11 = e.LBraceToken();
  b.setVal11(es.EntityId(t11));
  b.setVal21(e.HasBraces());
}

void SerializeGCCAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal11(es.EntityId(e.AssemblyString()));
  auto t12 = e.RParenToken();
  b.setVal12(es.EntityId(t12));
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
  auto t15 = e.LParenToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.RParenToken();
  b.setVal18(es.EntityId(t18));
  auto t19 = e.WhileToken();
  b.setVal19(es.EntityId(t19));
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
  auto t12 = e.IdentifierToken();
  b.setVal12(es.EntityId(t12));
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
  auto t33 = e.ExpressionToken();
  b.setVal33(es.EntityId(t33));
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
  auto t40 = e.EqualOrColonToken();
  b.setVal40(es.EntityId(t40));
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
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.KeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal40(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Declaration()));
  b.setVal39(es.EntityId(e.FoundDeclaration()));
  auto t40 = e.LAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
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
  auto t39 = e.KeywordToken();
  b.setVal39(es.EntityId(t39));
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
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
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
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.IsFileScope());
}

void SerializeChooseExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.ChosenSubExpression()));
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal42(es.EntityId(e.RHS()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal98(e.IsConditionDependent());
  b.setVal99(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
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
}

void SerializeCXXNamedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r43 = e.AngleBrackets(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  auto v68 = e.CastName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
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
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal101(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeBuiltinBitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t43 = e.BridgeKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
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
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
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
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
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
  auto t44 = e.UDSuffixToken();
  b.setVal44(es.EntityId(t44));
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
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.TypeAsWritten()));
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
  auto t39 = e.ThrowToken();
  b.setVal39(es.EntityId(t39));
  b.setVal99(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal98(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXRewrittenBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal41(es.EntityId(e.SemanticForm()));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  auto t39 = e.ColonColonToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.DestroyedType()));
  auto t41 = e.DestroyedTypeToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.ScopeTypeInfo()));
  auto t44 = e.TildeToken();
  b.setVal44(es.EntityId(t44));
  b.setVal98(e.HasQualifier());
  b.setVal99(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
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
  auto v39 = e.ArraySize();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal99(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v40 = e.ConstructExpression();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal100(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  if (auto r41 = e.DirectInitializerRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v43 = e.Initializer();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal101(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal44(es.EntityId(e.OperatorDelete()));
  b.setVal45(es.EntityId(e.OperatorNew()));
  if (auto r46 = e.TypeIdParentheses(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal99(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Callee()));
  auto t39 = e.EllipsisToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal41(es.EntityId(e.LHS()));
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
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
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
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
  auto t41 = e.LAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.MemberToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RAngleToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.TemplateKeywordToken();
  b.setVal45(es.EntityId(t45));
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
  auto t40 = e.UsedToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeCXXDefaultArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  auto t40 = e.UsedToken();
  b.setVal40(es.EntityId(t40));
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
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
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
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
  auto t40 = e.CaretToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
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
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
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
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
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
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DimensionExpression()));
  b.setVal39(es.EntityId(e.QueriedType()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.LHS()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
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
  auto t38 = e.AmpAmpToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Label()));
  auto t40 = e.LabelToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeAbstractConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.ColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.FalseExpression()));
  auto t41 = e.QuestionToken();
  b.setVal41(es.EntityId(t41));
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
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.WrittenTypeInfo()));
  b.setVal98(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.CanOverflow());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
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
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TypeOfArgument()));
  b.setVal100(e.IsArgumentType());
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
  auto t39 = e.ParameterPackToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSubstNonTypeTemplateParmExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.NameToken();
  b.setVal38(es.EntityId(t38));
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
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v63 = e.BuiltinString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal98(e.IsIntType());
  b.setVal99(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Pack()));
  auto v112 = e.PackLength();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto t40 = e.PackToken();
  b.setVal40(es.EntityId(t40));
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
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal100(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSYCLUniqueStableNameExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal63(e.ComputeName());
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
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
  auto t39 = e.RBraceToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RequiresKWToken();
  b.setVal40(es.EntityId(t40));
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeParenListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
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
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.EllipsisToken();
  b.setVal38(es.EntityId(t38));
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
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.NameToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.NamingClass()));
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  auto t45 = e.MemberToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
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
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal98(e.IsUnique());
}

void SerializeOffsetOfExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCSubscriptRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal39(es.EntityId(e.BaseExpression()));
  b.setVal40(es.EntityId(e.KeyExpression()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal98(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCProtocolExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Protocol()));
  auto t40 = e.ProtocolIdToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeObjCPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ClassReceiver()));
  b.setVal40(es.EntityId(e.ExplicitProperty()));
  b.setVal41(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal42(es.EntityId(e.ImplicitPropertySetter()));
  auto t43 = e.Token();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.ReceiverToken();
  b.setVal44(es.EntityId(t44));
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
  auto t42 = e.LeftToken();
  b.setVal42(es.EntityId(t42));
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
  auto t48 = e.RightToken();
  b.setVal48(es.EntityId(t48));
  auto t49 = e.SelectorStartToken();
  b.setVal49(es.EntityId(t49));
  auto t50 = e.SuperToken();
  b.setVal50(es.EntityId(t50));
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
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperationToken();
  b.setVal41(es.EntityId(t41));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  auto t39 = e.BaseTokenEnd();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.IsaMemberToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperationToken();
  b.setVal41(es.EntityId(t41));
  b.setVal98(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal98(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.EncodedType()));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCDictionaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.BoxingMethod()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal98(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
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
  auto t38 = e.IteratorKwToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
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
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeOMPArraySectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  auto t39 = e.FirstColonToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.SecondColonToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.Length()));
  b.setVal42(es.EntityId(e.LowerBound()));
  auto t43 = e.RBracketToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.MemberDeclaration()));
  auto t41 = e.MemberToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RAngleToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.TemplateKeywordToken();
  b.setVal44(es.EntityId(t44));
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
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
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
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeMSPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BaseExpression()));
  auto t39 = e.MemberToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.PropertyDeclaration()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CallOperator()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t40 = e.CaptureDefaultToken();
  b.setVal40(es.EntityId(t40));
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
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
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
  auto t40 = e.LBraceToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RBraceToken();
  b.setVal41(es.EntityId(t41));
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
  auto t39 = e.DefaultToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.GenericToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.ResultExpression()));
  b.setVal98(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.TokenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeFunctionParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ParameterPack()));
  auto t39 = e.ParameterPackToken();
  b.setVal39(es.EntityId(t39));
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
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal98(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ContainsDuplicateElements());
  auto t38 = e.AccessorToken();
  b.setVal38(es.EntityId(t38));
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
  auto t11 = e.AttributeToken();
  b.setVal11(es.EntityId(t11));
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
  auto t18 = e.LParenToken();
  b.setVal18(es.EntityId(t18));
  auto t19 = e.RParenToken();
  b.setVal19(es.EntityId(t19));
  auto v20 = e.FirstSwitchCase();
  if (v20) {
    auto id20 = es.EntityId(v20.value());    b.setVal20(id20);
    b.setVal22(id20 != mx::kInvalidEntityId);
  } else {
    b.setVal20(mx::kInvalidEntityId);
    b.setVal22(false);
  }
  auto t27 = e.SwitchToken();
  b.setVal27(es.EntityId(t27));
  b.setVal57(e.HasInitializerStorage());
  b.setVal58(e.HasVariableStorage());
  b.setVal59(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  auto t10 = e.ColonToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.KeywordToken();
  b.setVal11(es.EntityId(t11));
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
  auto t15 = e.DefaultToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeCaseStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal16(e.CaseStatementIsGNURange());
  auto t15 = e.CaseToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.EllipsisToken();
  b.setVal18(es.EntityId(t18));
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
  auto t5 = e.BeginToken();
  b.setVal5(es.EntityId(t5));
  auto v6 = e.DescribedTemplateParameters();
  if (v6) {
    b.setVal6(es.PseudoId(v6.value()));
    b.setVal7(true);
  } else {
    b.setVal7(false);
  }
  auto t8 = e.EndToken();
  b.setVal8(es.EntityId(t8));
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
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
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
  auto t51 = e.CaretToken();
  b.setVal51(es.EntityId(t51));
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
  auto t43 = e.AccessSpecifierToken();
  b.setVal43(es.EntityId(t43));
  auto t51 = e.ColonToken();
  b.setVal51(es.EntityId(t51));
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
  auto t52 = e.RParenToken();
  b.setVal52(es.EntityId(t52));
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
  auto t61 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal61(es.EntityId(t61));
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
  b.setVal58(e.Name());
  auto v64 = e.ObjCFStringFormattingFamily();
  if (v64) {
    b.setVal64(static_cast<unsigned char>(v64.value()));
    b.setVal44(true);
  } else {
    b.setVal44(false);
  }
  b.setVal59(e.QualifiedNameAsString());
  b.setVal43(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal47(e.HasExternalFormalLinkage());
  b.setVal48(e.HasLinkage());
  b.setVal49(e.HasLinkageBeenComputed());
  b.setVal50(e.IsCXXClassMember());
  b.setVal54(e.IsCXXInstanceMember());
  b.setVal55(e.IsExternallyDeclarable());
  b.setVal56(e.IsExternallyVisible());
  b.setVal66(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v67 = e.MSAssemblyLabel();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  b.setVal51(es.EntityId(e.Statement()));
  b.setVal68(e.IsGnuLocal());
  b.setVal69(e.IsMSAssemblyLabel());
  b.setVal70(e.IsResolvedMSAssemblyLabel());
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
  auto t52 = e.EnumToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.UsingToken();
  b.setVal53(es.EntityId(t53));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t51 = e.UsingToken();
  b.setVal51(es.EntityId(t51));
  b.setVal68(e.HasTypename());
  b.setVal69(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.Type()));
  b.setVal68(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t52 = e.EllipsisToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.UsingToken();
  b.setVal53(es.EntityId(t53));
  b.setVal69(e.IsAccessDeclaration());
  b.setVal70(e.IsPackExpansion());
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
  b.setVal71(es.EntityId(e.Initializer()));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
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
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto v53 = e.VariableDeclaration();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal70(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal70(false);
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
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t52 = e.FirstInnerToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.FirstOuterToken();
  b.setVal53(es.EntityId(t53));
  auto v61 = e.TrailingRequiresClause();
  if (v61) {
    auto id61 = es.EntityId(v61.value());    b.setVal61(id61);
    b.setVal69(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto t62 = e.TypeSpecEndToken();
  b.setVal62(es.EntityId(t62));
  auto t63 = e.TypeSpecStartToken();
  b.setVal63(es.EntityId(t63));
  do {
    auto v73 = e.TemplateParameterLists();
    auto sv73 = b.initVal73(static_cast<unsigned>(v73.size()));
    auto i73 = 0u;
    for (const auto &e73 : v73) {
      sv73.set(i73, es.PseudoId(e73));
      ++i73;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v71 = e.ActingDefinition();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal70(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v74 = e.Initializer();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal75(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v76 = e.InitializingDeclaration();
  if (v76) {
    auto id76 = es.EntityId(v76.value());    b.setVal76(id76);
    b.setVal77(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  auto v78 = e.InstantiatedFromStaticDataMember();
  if (v78) {
    auto id78 = es.EntityId(v78.value());    b.setVal78(id78);
    b.setVal79(id78 != mx::kInvalidEntityId);
  } else {
    b.setVal78(mx::kInvalidEntityId);
    b.setVal79(false);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t81 = e.PointOfInstantiation();
  b.setVal81(es.EntityId(t81));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v86 = e.TemplateInstantiationPattern();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal87(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal87(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal90(e.HasConstantInitialization());
  b.setVal91(e.HasDependentAlignment());
  b.setVal92(e.HasExternalStorage());
  b.setVal93(e.HasGlobalStorage());
  auto v94 = e.HasICEInitializer();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal96(e.HasInitializer());
  b.setVal97(e.HasLocalStorage());
  b.setVal98(e.IsARCPseudoStrong());
  b.setVal99(e.IsCXXForRangeDeclaration());
  b.setVal100(e.IsConstexpr());
  b.setVal101(e.IsDirectInitializer());
  b.setVal102(e.IsEscapingByref());
  b.setVal103(e.IsExceptionVariable());
  b.setVal104(e.IsExternC());
  b.setVal105(e.IsFileVariableDeclaration());
  b.setVal106(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal107(e.IsInExternCContext());
  b.setVal108(e.IsInExternCXXContext());
  b.setVal109(e.IsInitializerCapture());
  b.setVal110(e.IsInline());
  b.setVal111(e.IsInlineSpecified());
  b.setVal112(e.IsKnownToBeDefined());
  b.setVal113(e.IsLocalVariableDeclaration());
  b.setVal114(e.IsLocalVariableDeclarationOrParm());
  b.setVal115(e.IsNRVOVariable());
  b.setVal116(e.IsNoDestroy());
  b.setVal117(e.IsNonEscapingByref());
  b.setVal118(e.IsObjCForDeclaration());
  b.setVal119(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal120(e.IsStaticDataMember());
  b.setVal121(e.IsStaticLocal());
  b.setVal122(e.IsThisDeclarationADemotedDefinition());
  b.setVal123(e.IsUsableInConstantExpressions());
  b.setVal124(e.MightBeUsableInConstantExpressions());
  b.setVal125(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v126 = e.DefaultArgument();
  if (v126) {
    auto id126 = es.EntityId(v126.value());    b.setVal126(id126);
    b.setVal127(id126 != mx::kInvalidEntityId);
  } else {
    b.setVal126(mx::kInvalidEntityId);
    b.setVal127(false);
  }
  if (auto r128 = e.DefaultArgumentRange(); auto rs128 = r128.Size()) {
    b.setVal128(es.EntityId(r128[0]));
    b.setVal129(es.EntityId(r128[rs128 - 1u]));
  } else {
    b.setVal128(0);
    b.setVal129(0);
  }
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal131(es.EntityId(e.OriginalType()));
  auto v132 = e.UninstantiatedDefaultArgument();
  if (v132) {
    auto id132 = es.EntityId(v132.value());    b.setVal132(id132);
    b.setVal133(id132 != mx::kInvalidEntityId);
  } else {
    b.setVal132(mx::kInvalidEntityId);
    b.setVal133(false);
  }
  b.setVal134(e.HasDefaultArgument());
  b.setVal135(e.HasInheritedDefaultArgument());
  b.setVal136(e.HasUninstantiatedDefaultArgument());
  b.setVal137(e.HasUnparsedDefaultArgument());
  b.setVal138(e.IsDestroyedInCallee());
  b.setVal139(e.IsKNRPromoted());
  b.setVal140(e.IsObjCMethodParameter());
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
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
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
  auto t126 = e.ExternToken();
  b.setVal126(es.EntityId(t126));
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v141 = e.TemplateArguments();
    auto sv141 = b.initVal141(static_cast<unsigned>(v141.size()));
    auto i141 = 0u;
    for (const auto &e141 : v141) {
      sv141.set(i141, es.PseudoId(e141));
      ++i141;
    }
  } while (false);
  do {
    auto v142 = e.TemplateInstantiationArguments();
    auto sv142 = b.initVal142(static_cast<unsigned>(v142.size()));
    auto i142 = 0u;
    for (const auto &e142 : v142) {
      sv142.set(i142, es.PseudoId(e142));
      ++i142;
    }
  } while (false);
  auto t128 = e.TemplateKeywordToken();
  b.setVal128(es.EntityId(t128));
  b.setVal129(es.EntityId(e.TypeAsWritten()));
  b.setVal127(e.IsClassScopeExplicitSpecialization());
  b.setVal133(e.IsExplicitInstantiationOrSpecialization());
  b.setVal134(e.IsExplicitSpecialization());
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
  b.setVal70(e.DefaultArgumentWasInherited());
  b.setVal71(es.EntityId(e.DefaultArgument()));
  auto t74 = e.DefaultArgumentToken();
  b.setVal74(es.EntityId(t74));
  b.setVal76(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal75(e.HasDefaultArgument());
  b.setVal77(e.HasPlaceholderTypeConstraint());
  b.setVal79(e.IsExpandedParameterPack());
  b.setVal87(e.IsPackExpansion());
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
  b.setVal70(e.HasGetter());
  b.setVal75(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v70) {
    b.setVal70(static_cast<bool>(v70.value()));
    b.setVal75(true);
  } else {
    b.setVal75(false);
  }
  b.setVal77(e.DoesThisDeclarationHaveABody());
  b.setVal71(es.EntityId(e.CallResultType()));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal74(es.EntityId(e.DeclaredReturnType()));
  auto t76 = e.EllipsisToken();
  b.setVal76(es.EntityId(t76));
  if (auto r78 = e.ExceptionSpecSourceRange(); auto rs78 = r78.Size()) {
    b.setVal78(es.EntityId(r78[0]));
    b.setVal81(es.EntityId(r78[rs78 - 1u]));
  } else {
    b.setVal78(0);
    b.setVal81(0);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v86 = e.InstantiatedFromMemberFunction();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal79(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal79(false);
  }
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v143 = e.ODRHash();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal87(true);
  } else {
    b.setVal87(false);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r126 = e.ParametersSourceRange(); auto rs126 = r126.Size()) {
    b.setVal126(es.EntityId(r126[0]));
    b.setVal128(es.EntityId(r126[rs126 - 1u]));
  } else {
    b.setVal126(0);
    b.setVal128(0);
  }
  auto t129 = e.PointOfInstantiation();
  b.setVal129(es.EntityId(t129));
  b.setVal131(es.EntityId(e.ReturnType()));
  if (auto r132 = e.ReturnTypeSourceRange(); auto rs132 = r132.Size()) {
    b.setVal132(es.EntityId(r132[0]));
    b.setVal144(es.EntityId(r132[rs132 - 1u]));
  } else {
    b.setVal132(0);
    b.setVal144(0);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v145 = e.TemplateInstantiationPattern();
  if (v145) {
    auto id145 = es.EntityId(v145.value());    b.setVal145(id145);
    b.setVal90(id145 != mx::kInvalidEntityId);
  } else {
    b.setVal145(mx::kInvalidEntityId);
    b.setVal90(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal125(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal91(e.HasImplicitReturnZero());
  b.setVal92(e.HasInheritedPrototype());
  b.setVal93(e.HasOneParameterOrDefaultArguments());
  b.setVal94(e.HasPrototype());
  b.setVal95(e.HasSkippedBody());
  b.setVal96(e.HasTrivialBody());
  b.setVal97(e.HasWrittenPrototype());
  b.setVal98(e.InstantiationIsPending());
  b.setVal99(e.IsCPUDispatchMultiVersion());
  b.setVal100(e.IsCPUSpecificMultiVersion());
  b.setVal101(e.IsConsteval());
  b.setVal102(e.IsConstexpr());
  b.setVal103(e.IsConstexprSpecified());
  b.setVal104(e.IsDefaulted());
  b.setVal105(e.IsDeleted());
  b.setVal106(e.IsDeletedAsWritten());
  b.setVal107(e.IsDestroyingOperatorDelete());
  b.setVal108(e.IsExplicitlyDefaulted());
  b.setVal109(e.IsExternC());
  b.setVal110(e.IsFunctionTemplateSpecialization());
  b.setVal111(e.IsGlobal());
  b.setVal112(e.IsImplicitlyInstantiable());
  b.setVal113(e.IsInExternCContext());
  b.setVal114(e.IsInExternCXXContext());
  b.setVal115(e.IsInlineBuiltinDeclaration());
  auto v116 = e.IsInlineDefinitionExternallyVisible();
  if (v116) {
    b.setVal116(static_cast<bool>(v116.value()));
    b.setVal117(true);
  } else {
    b.setVal117(false);
  }
  b.setVal118(e.IsInlineSpecified());
  b.setVal119(e.IsInlined());
  b.setVal120(e.IsLateTemplateParsed());
  auto v121 = e.IsMSExternInline();
  if (v121) {
    b.setVal121(static_cast<bool>(v121.value()));
    b.setVal122(true);
  } else {
    b.setVal122(false);
  }
  b.setVal123(e.IsMSVCRTEntryPoint());
  b.setVal124(e.IsMain());
  b.setVal127(e.IsMultiVersion());
  b.setVal133(e.IsNoReturn());
  b.setVal134(e.IsOverloadedOperator());
  b.setVal135(e.IsPure());
  b.setVal136(e.IsReplaceableGlobalAllocationFunction());
  auto v137 = e.IsReservedGlobalPlacementOperator();
  if (v137) {
    b.setVal137(static_cast<bool>(v137.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  b.setVal139(e.IsStatic());
  b.setVal140(e.IsTargetMultiVersion());
  b.setVal146(e.IsTemplateInstantiation());
  b.setVal147(e.IsThisDeclarationADefinition());
  b.setVal148(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal149(e.IsTrivial());
  b.setVal150(e.IsTrivialForCall());
  b.setVal151(e.IsUserProvided());
  b.setVal152(e.IsVariadic());
  b.setVal153(e.IsVirtualAsWritten());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal154(e.UsesSEHTry());
  b.setVal155(e.WillHaveBody());
  auto v156 = e.Body();
  if (v156) {
    auto id156 = es.EntityId(v156.value());    b.setVal156(id156);
    b.setVal157(id156 != mx::kInvalidEntityId);
  } else {
    b.setVal156(mx::kInvalidEntityId);
    b.setVal157(false);
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
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal158(es.EntityId(e.ThisObjectType()));
  b.setVal159(es.EntityId(e.ThisType()));
  b.setVal160(e.HasInlineBody());
  b.setVal161(e.IsConst());
  b.setVal162(e.IsCopyAssignmentOperator());
  b.setVal163(e.IsInstance());
  b.setVal164(e.IsLambdaStaticInvoker());
  b.setVal165(e.IsMoveAssignmentOperator());
  b.setVal166(e.IsVirtual());
  b.setVal167(e.IsVolatile());
  do {
    auto v57 = e.OverriddenMethods();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  do {
    auto v168 = e.ParameterDeclarations();
    auto sv168 = b.initVal168(static_cast<unsigned>(v168.size()));
    auto i168 = 0u;
    for (const auto &e168 : v168) {
      sv168.set(i168, es.EntityId(e168));
      ++i168;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v169 = e.OperatorDelete();
  if (v169) {
    auto id169 = es.EntityId(v169.value());    b.setVal169(id169);
    b.setVal170(id169 != mx::kInvalidEntityId);
  } else {
    b.setVal169(mx::kInvalidEntityId);
    b.setVal170(false);
  }
  auto v171 = e.OperatorDeleteThisArgument();
  if (v171) {
    auto id171 = es.EntityId(v171.value());    b.setVal171(id171);
    b.setVal172(id171 != mx::kInvalidEntityId);
  } else {
    b.setVal171(mx::kInvalidEntityId);
    b.setVal172(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal169(es.EntityId(e.ConversionType()));
  b.setVal170(e.IsExplicit());
  b.setVal172(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v169 = e.TargetConstructor();
  if (v169) {
    auto id169 = es.EntityId(v169.value());    b.setVal169(id169);
    b.setVal170(id169 != mx::kInvalidEntityId);
  } else {
    b.setVal169(mx::kInvalidEntityId);
    b.setVal170(false);
  }
  b.setVal172(e.IsDefaultConstructor());
  b.setVal173(e.IsDelegatingConstructor());
  b.setVal174(e.IsExplicit());
  b.setVal175(e.IsInheritingConstructor());
  b.setVal176(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal158(es.EntityId(e.CorrespondingConstructor()));
  b.setVal160(e.IsCopyDeductionCandidate());
  b.setVal161(e.IsExplicit());
  do {
    auto v57 = e.ParameterDeclarations();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v71 = e.BitWidth();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal70(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v74 = e.CapturedVLAType();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal75(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v76 = e.InClassInitializer();
  if (v76) {
    auto id76 = es.EntityId(v76.value());    b.setVal76(id76);
    b.setVal77(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  b.setVal79(e.HasCapturedVLAType());
  b.setVal87(e.HasInClassInitializer());
  b.setVal90(e.IsAnonymousStructOrUnion());
  b.setVal91(e.IsBitField());
  b.setVal92(e.IsMutable());
  b.setVal93(e.IsUnnamedBitfield());
  b.setVal94(e.IsZeroLengthBitField());
  b.setVal95(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal78(es.EntityId(e.ContainingInterface()));
  b.setVal81(es.EntityId(e.NextInstanceVariable()));
  b.setVal96(e.Synthesize());
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
    b.setVal68(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  b.setVal53(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal69(e.ConstructsVirtualBase());
  b.setVal61(es.EntityId(e.ConstructedBaseClass()));
  auto v62 = e.ConstructedBaseClassShadowDeclaration();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal70(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal63(es.EntityId(e.NominatedBaseClass()));
  auto v71 = e.NominatedBaseClassShadowDeclaration();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal75(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal75(false);
  }
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
  auto t51 = e.IdentifierToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.NamespaceKeyToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t61 = e.UsingToken();
  b.setVal61(es.EntityId(t61));
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
    b.setVal68(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal68(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal69(e.DefaultArgumentWasInherited());
  b.setVal52(es.EntityId(e.DefaultArgument()));
  b.setVal53(es.EntityId(e.DefaultArgumentInfo()));
  auto t61 = e.DefaultArgumentToken();
  b.setVal61(es.EntityId(t61));
  b.setVal70(e.HasDefaultArgument());
  b.setVal75(e.HasTypeConstraint());
  b.setVal77(e.IsExpandedParameterPack());
  b.setVal79(e.IsPackExpansion());
  b.setVal87(e.WasDeclaredWithTypename());
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
  auto t61 = e.FirstInnerToken();
  b.setVal61(es.EntityId(t61));
  auto t62 = e.FirstOuterToken();
  b.setVal62(es.EntityId(t62));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v63 = e.TypedefNameForAnonymousDeclaration();
  if (v63) {
    auto id63 = es.EntityId(v63.value());    b.setVal63(id63);
    b.setVal69(id63 != mx::kInvalidEntityId);
  } else {
    b.setVal63(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal70(e.HasNameForLinkage());
  b.setVal75(e.IsBeingDefined());
  b.setVal77(e.IsClass());
  b.setVal79(e.IsCompleteDefinition());
  b.setVal87(e.IsCompleteDefinitionRequired());
  b.setVal90(e.IsDependentType());
  b.setVal91(e.IsEmbeddedInDeclarator());
  b.setVal92(e.IsEnum());
  b.setVal93(e.IsFreeStanding());
  b.setVal94(e.IsInterface());
  b.setVal95(e.IsStruct());
  b.setVal96(e.IsThisDeclarationADefinition());
  b.setVal97(e.IsUnion());
  b.setVal98(e.MayHaveOutOfDateDefinition());
  do {
    auto v73 = e.TemplateParameterLists();
    auto sv73 = b.initVal73(static_cast<unsigned>(v73.size()));
    auto i73 = 0u;
    for (const auto &e73 : v73) {
      sv73.set(i73, es.PseudoId(e73));
      ++i73;
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
  b.setVal99(e.CanPassInRegisters());
  do {
    auto v46 = e.Fields();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal100(e.HasFlexibleArrayMember());
  b.setVal101(e.HasLoadedFieldsFromExternalStorage());
  b.setVal102(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal103(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal104(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal105(e.HasObjectMember());
  b.setVal106(e.HasVolatileMember());
  b.setVal107(e.IsAnonymousStructOrUnion());
  b.setVal108(e.IsCapturedRecord());
  b.setVal109(e.IsInjectedClassName());
  b.setVal110(e.IsLambda());
  b.setVal111(e.IsMsStruct());
  b.setVal112(e.IsNonTrivialToPrimitiveCopy());
  b.setVal113(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal114(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal115(e.IsOrContainsUnion());
  b.setVal116(e.IsParameterDestroyedInCallee());
  b.setVal117(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v118 = e.AllowConstDefaultInitializer();
  if (v118) {
    b.setVal118(static_cast<bool>(v118.value()));
    b.setVal119(true);
  } else {
    b.setVal119(false);
  }
  do {
    auto ov141 = e.Bases();
    if (!ov141) {
      b.setVal120(false);
      break;
    }
    b.setVal120(true);
    auto v141 = std::move(*ov141);
    auto sv141 = b.initVal141(static_cast<unsigned>(v141.size()));
    auto i141 = 0u;
    for (const auto &e141 : v141) {
      sv141.set(i141, es.PseudoId(e141));
      ++i141;
    }
  } while (false);
  auto v82 = e.CalculateInheritanceModel();
  if (v82) {
    b.setVal82(static_cast<unsigned char>(v82.value()));
    b.setVal121(true);
  } else {
    b.setVal121(false);
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
    auto ov168 = e.Friends();
    if (!ov168) {
      b.setVal122(false);
      break;
    }
    b.setVal122(true);
    auto v168 = std::move(*ov168);
    auto sv168 = b.initVal168(static_cast<unsigned>(v168.size()));
    auto i168 = 0u;
    for (const auto &e168 : v168) {
      sv168.set(i168, es.EntityId(e168));
      ++i168;
    }
  } while (false);
  auto v71 = e.Destructor();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal123(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal123(false);
  }
  auto v143 = e.GenericLambdaTemplateParameterList();
  if (v143) {
    b.setVal143(es.PseudoId(v143.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  auto v74 = e.InstantiatedFromMemberClass();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal127(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal127(false);
  }
  auto v76 = e.LambdaCallOperator();
  if (v76) {
    auto id76 = es.EntityId(v76.value());    b.setVal76(id76);
    b.setVal133(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal133(false);
  }
  auto v83 = e.LambdaCaptureDefault();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  auto v78 = e.LambdaContextDeclaration();
  if (v78) {
    auto id78 = es.EntityId(v78.value());    b.setVal78(id78);
    b.setVal135(id78 != mx::kInvalidEntityId);
  } else {
    b.setVal78(mx::kInvalidEntityId);
    b.setVal135(false);
  }
  do {
    auto ov177 = e.LambdaExplicitTemplateParameters();
    if (!ov177) {
      b.setVal136(false);
      break;
    }
    b.setVal136(true);
    auto v177 = std::move(*ov177);
    auto sv177 = b.initVal177(static_cast<unsigned>(v177.size()));
    auto i177 = 0u;
    for (const auto &e177 : v177) {
      sv177.set(i177, es.EntityId(e177));
      ++i177;
    }
  } while (false);
  auto v178 = e.LambdaManglingNumber();
  if (v178) {
    b.setVal178(static_cast<unsigned>(v178.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  auto v81 = e.LambdaTypeInfo();
  if (v81) {
    auto id81 = es.EntityId(v81.value());    b.setVal81(id81);
    b.setVal138(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal138(false);
  }
  auto v84 = e.MSInheritanceModel();
  if (v84) {
    b.setVal84(static_cast<unsigned char>(v84.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v179 = e.NumBases();
  if (v179) {
    b.setVal179(static_cast<unsigned>(v179.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  auto v180 = e.NumVirtualBases();
  if (v180) {
    b.setVal180(static_cast<unsigned>(v180.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v181 = e.ODRHash();
  if (v181) {
    b.setVal181(static_cast<unsigned>(v181.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v86 = e.TemplateInstantiationPattern();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal148(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal148(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v149 = e.HasAnyDependentBases();
  if (v149) {
    b.setVal149(static_cast<bool>(v149.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  auto v151 = e.HasConstexprDefaultConstructor();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v153 = e.HasConstexprDestructor();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasConstexprNonCopyMoveConstructor();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v160 = e.HasCopyAssignmentWithConstParameter();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v162 = e.HasCopyConstructorWithConstParameter();
  if (v162) {
    b.setVal162(static_cast<bool>(v162.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v164 = e.HasDefaultConstructor();
  if (v164) {
    b.setVal164(static_cast<bool>(v164.value()));
    b.setVal165(true);
  } else {
    b.setVal165(false);
  }
  auto v166 = e.HasDefinition();
  if (v166) {
    b.setVal166(static_cast<bool>(v166.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v170 = e.HasDirectFields();
  if (v170) {
    b.setVal170(static_cast<bool>(v170.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  auto v173 = e.HasFriends();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasInClassInitializer();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v182 = e.HasInheritedAssignment();
  if (v182) {
    b.setVal182(static_cast<bool>(v182.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
  }
  auto v184 = e.HasInheritedConstructor();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v186 = e.HasIrrelevantDestructor();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v188 = e.HasKnownLambdaInternalLinkage();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  auto v190 = e.HasMoveAssignment();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasMoveConstructor();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasMutableFields();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasNonLiteralTypeFieldsOrBases();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonTrivialCopyAssignment();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialCopyConstructor();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialCopyConstructorForCall();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialDefaultConstructor();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialDestructor();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialDestructorForCall();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialMoveAssignment();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialMoveConstructor();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasNonTrivialMoveConstructorForCall();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasPrivateFields();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasProtectedFields();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasSimpleCopyAssignment();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasSimpleCopyConstructor();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasSimpleDestructor();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasSimpleMoveAssignment();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasSimpleMoveConstructor();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasTrivialCopyAssignment();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialCopyConstructor();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialCopyConstructorForCall();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialDefaultConstructor();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialDestructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialDestructorForCall();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialMoveAssignment();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialMoveConstructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasTrivialMoveConstructorForCall();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasUninitializedReferenceMember();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUserDeclaredConstructor();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserDeclaredCopyAssignment();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUserDeclaredCopyConstructor();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredDestructor();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserDeclaredMoveAssignment();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUserDeclaredMoveConstructor();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserDeclaredMoveOperation();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasUserProvidedDefaultConstructor();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.HasVariantMembers();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.ImplicitCopyConstructorHasConstParameter();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.IsAbstract();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsAggregate();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.IsAnyDestructorNoReturn();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.IsCLike();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  auto v280 = e.IsCXX11StandardLayout();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  b.setVal282(e.IsDependentLambda());
  auto v283 = e.IsDynamicClass();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsEffectivelyFinal();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsEmpty();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  b.setVal289(e.IsGenericLambda());
  auto v290 = e.IsInterfaceLike();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v292 = e.IsLiteral();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v126 = e.IsLocalClass();
  if (v126) {
    auto id126 = es.EntityId(v126.value());    b.setVal126(id126);
    b.setVal294(id126 != mx::kInvalidEntityId);
  } else {
    b.setVal126(mx::kInvalidEntityId);
    b.setVal294(false);
  }
  auto v295 = e.IsPOD();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsPolymorphic();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsStandardLayout();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.IsStructural();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsTrivial();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.IsTriviallyCopyable();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.MayBeAbstract();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.MayBeDynamicClass();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.MayBeNonDynamicClass();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  do {
    auto ov315 = e.Methods();
    if (!ov315) {
      b.setVal316(false);
      break;
    }
    b.setVal316(true);
    auto v315 = std::move(*ov315);
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  auto v317 = e.NeedsImplicitCopyAssignment();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.NeedsImplicitCopyConstructor();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.NeedsImplicitDefaultConstructor();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.NeedsImplicitDestructor();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsImplicitMoveAssignment();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsImplicitMoveConstructor();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsOverloadResolutionForDestructor();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.NullFieldOffsetIsZero();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
  do {
    auto ov142 = e.VirtualBases();
    if (!ov142) {
      b.setVal341(false);
      break;
    }
    b.setVal341(true);
    auto v142 = std::move(*ov142);
    auto sv142 = b.initVal142(static_cast<unsigned>(v142.size()));
    auto i142 = 0u;
    for (const auto &e142 : v142) {
      sv142.set(i142, es.PseudoId(e142));
      ++i142;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t128 = e.ExternToken();
  b.setVal128(es.EntityId(t128));
  auto t129 = e.PointOfInstantiation();
  b.setVal129(es.EntityId(t129));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v342 = e.TemplateArguments();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.PseudoId(e342));
      ++i342;
    }
  } while (false);
  do {
    auto v343 = e.TemplateInstantiationArguments();
    auto sv343 = b.initVal343(static_cast<unsigned>(v343.size()));
    auto i343 = 0u;
    for (const auto &e343 : v343) {
      sv343.set(i343, es.PseudoId(e343));
      ++i343;
    }
  } while (false);
  auto t131 = e.TemplateKeywordToken();
  b.setVal131(es.EntityId(t131));
  b.setVal132(es.EntityId(e.TypeAsWritten()));
  b.setVal344(e.IsClassScopeExplicitSpecialization());
  b.setVal345(e.IsExplicitInstantiationOrSpecialization());
  b.setVal346(e.IsExplicitSpecialization());
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
  auto v71 = e.InstantiatedFromMemberEnum();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal99(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v74 = e.IntegerType();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal100(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  if (auto r76 = e.IntegerTypeRange(); auto rs76 = r76.Size()) {
    b.setVal76(es.EntityId(r76[0]));
    b.setVal78(es.EntityId(r76[rs76 - 1u]));
  } else {
    b.setVal76(0);
    b.setVal78(0);
  }
  auto v143 = e.ODRHash();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal101(true);
  } else {
    b.setVal101(false);
  }
  b.setVal81(es.EntityId(e.PromotionType()));
  auto v86 = e.TemplateInstantiationPattern();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal102(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal102(false);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal103(e.IsClosed());
  b.setVal104(e.IsClosedFlag());
  b.setVal105(e.IsClosedNonFlag());
  b.setVal106(e.IsComplete());
  b.setVal107(e.IsFixed());
  b.setVal108(e.IsScoped());
  b.setVal109(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto t52 = e.EllipsisToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.TypenameToken();
  b.setVal53(es.EntityId(t53));
  auto t61 = e.UsingToken();
  b.setVal61(es.EntityId(t61));
  b.setVal69(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v52 = e.AnonymousDeclarationWithTypedefName();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal53(es.EntityId(e.TypeSourceInfo()));
  b.setVal61(es.EntityId(e.UnderlyingType()));
  b.setVal70(e.IsModed());
  b.setVal75(e.IsTransparentTag());
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
    b.setVal77(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal77(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t62 = e.ColonToken();
  b.setVal62(es.EntityId(t62));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t63 = e.VarianceToken();
  b.setVal63(es.EntityId(t63));
  b.setVal77(e.HasExplicitBound());
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
  b.setVal51(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal52(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal51(es.EntityId(e.ConstraintExpression()));
  b.setVal68(e.IsTypeConcept());
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
  auto t51 = e.AtToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.GetterMethodDeclaration()));
  auto t53 = e.GetterNameToken();
  b.setVal53(es.EntityId(t53));
  auto t61 = e.LParenToken();
  b.setVal61(es.EntityId(t61));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal62(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal63(es.EntityId(e.SetterMethodDeclaration()));
  auto t71 = e.SetterNameToken();
  b.setVal71(es.EntityId(t71));
  b.setVal74(es.EntityId(e.Type()));
  b.setVal68(e.IsAtomic());
  b.setVal69(e.IsClassProperty());
  b.setVal70(e.IsDirectProperty());
  b.setVal75(e.IsInstanceProperty());
  b.setVal77(e.IsOptional());
  b.setVal79(e.IsReadOnly());
  b.setVal87(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal68(e.DefinedInNSObject());
  b.setVal51(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal52(es.EntityId(e.Category()));
  b.setVal53(es.EntityId(e.ClassInterface()));
  b.setVal61(es.EntityId(e.CommandDeclaration()));
  auto t62 = e.DeclaratorEndToken();
  b.setVal62(es.EntityId(t62));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal63(es.EntityId(e.ReturnType()));
  if (auto r71 = e.ReturnTypeSourceRange(); auto rs71 = r71.Size()) {
    b.setVal71(es.EntityId(r71[0]));
    b.setVal74(es.EntityId(r71[rs71 - 1u]));
  } else {
    b.setVal71(0);
    b.setVal74(0);
  }
  auto t76 = e.SelectorStartToken();
  b.setVal76(es.EntityId(t76));
  b.setVal78(es.EntityId(e.SelfDeclaration()));
  b.setVal69(e.HasRedeclaration());
  b.setVal70(e.HasRelatedResultType());
  b.setVal75(e.HasSkippedBody());
  b.setVal77(e.IsClassMethod());
  b.setVal79(e.IsDefined());
  b.setVal87(e.IsDesignatedInitializerForTheInterface());
  b.setVal90(e.IsDirectMethod());
  b.setVal91(e.IsInstanceMethod());
  b.setVal92(e.IsOptional());
  b.setVal93(e.IsOverriding());
  b.setVal94(e.IsPropertyAccessor());
  b.setVal95(e.IsRedeclaration());
  b.setVal96(e.IsSynthesizedAccessorStub());
  b.setVal97(e.IsThisDeclarationADefinition());
  b.setVal98(e.IsThisDeclarationADesignatedInitializer());
  b.setVal99(e.IsVariadic());
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
  auto t53 = e.AtStartToken();
  b.setVal53(es.EntityId(t53));
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
    auto v168 = e.InstanceProperties();
    auto sv168 = b.initVal168(static_cast<unsigned>(v168.size()));
    auto i168 = 0u;
    for (const auto &e168 : v168) {
      sv168.set(i168, es.EntityId(e168));
      ++i168;
    }
  } while (false);
  do {
    auto v177 = e.Methods();
    auto sv177 = b.initVal177(static_cast<unsigned>(v177.size()));
    auto i177 = 0u;
    for (const auto &e177 : v177) {
      sv177.set(i177, es.EntityId(e177));
      ++i177;
    }
  } while (false);
  do {
    auto v315 = e.Properties();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  pasta::DeclContext dc347(e);
  auto v347 = dc347.AlreadyLoadedDeclarations();
  auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
  auto i347 = 0u;
  for (const pasta::Decl &e347 : v347) {
    sv347.set(i347, es.EntityId(e347));
    ++i347;
  }
}

void SerializeObjCCategoryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal68(e.IsClassExtension());
  auto t61 = e.CategoryNameToken();
  b.setVal61(es.EntityId(t61));
  b.setVal62(es.EntityId(e.ClassInterface()));
  b.setVal63(es.EntityId(e.Implementation()));
  auto t71 = e.InstanceVariableLBraceToken();
  b.setVal71(es.EntityId(t71));
  auto t74 = e.InstanceVariableRBraceToken();
  b.setVal74(es.EntityId(t74));
  b.setVal76(es.EntityId(e.NextClassCategory()));
  do {
    auto v348 = e.InstanceVariables();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
  do {
    auto v349 = e.ProtocolTokens();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
  do {
    auto v350 = e.Protocols();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  auto v67 = e.ObjCRuntimeNameAsString();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  b.setVal68(e.HasDefinition());
  b.setVal69(e.IsNonRuntimeProtocol());
  b.setVal70(e.IsThisDeclarationADefinition());
  do {
    auto v348 = e.ProtocolTokens();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
  do {
    auto v349 = e.Protocols();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v348 = e.AllReferencedProtocols();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
  b.setVal68(e.DeclaresOrInheritsDesignatedInitializers());
  auto t61 = e.EndOfDefinitionToken();
  b.setVal61(es.EntityId(t61));
  b.setVal62(es.EntityId(e.Implementation()));
  auto v67 = e.ObjCRuntimeNameAsString();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  auto v63 = e.SuperClass();
  if (v63) {
    auto id63 = es.EntityId(v63.value());    b.setVal63(id63);
    b.setVal69(id63 != mx::kInvalidEntityId);
  } else {
    b.setVal63(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto t71 = e.SuperClassToken();
  b.setVal71(es.EntityId(t71));
  auto v74 = e.SuperClassTypeInfo();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal70(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal76(es.EntityId(e.TypeForDeclaration()));
  b.setVal75(e.HasDefinition());
  b.setVal77(e.HasDesignatedInitializers());
  b.setVal79(e.IsArcWeakrefUnavailable());
  b.setVal87(e.IsImplicitInterfaceDeclaration());
  b.setVal78(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal90(e.IsThisDeclarationADefinition());
  do {
    auto v349 = e.InstanceVariables();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
  do {
    auto v350 = e.KnownCategories();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
  do {
    auto v351 = e.KnownExtensions();
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
  do {
    auto v354 = e.VisibleCategories();
    auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
    auto i354 = 0u;
    for (const auto &e354 : v354) {
      sv354.set(i354, es.EntityId(e354));
      ++i354;
    }
  } while (false);
  do {
    auto v355 = e.VisibleExtensions();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
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
    auto v348 = e.PropertyImplementations();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal62(es.EntityId(e.CategoryDeclaration()));
  auto t63 = e.CategoryNameToken();
  b.setVal63(es.EntityId(t63));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t62 = e.InstanceVariableLBraceToken();
  b.setVal62(es.EntityId(t62));
  auto t63 = e.InstanceVariableRBraceToken();
  b.setVal63(es.EntityId(t63));
  auto v67 = e.ObjCRuntimeNameAsString();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  b.setVal71(es.EntityId(e.SuperClass()));
  auto t74 = e.SuperClassToken();
  b.setVal74(es.EntityId(t74));
  b.setVal68(e.HasDestructors());
  b.setVal69(e.HasNonZeroConstructors());
  do {
    auto v349 = e.InstanceVariables();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
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
  auto t51 = e.AliasToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.AliasedNamespace()));
  auto t53 = e.NamespaceToken();
  b.setVal53(es.EntityId(t53));
  auto t61 = e.TargetNameToken();
  b.setVal61(es.EntityId(t61));
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
  auto t51 = e.FriendToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.FriendType()));
  b.setVal47(e.IsUnsupportedFriend());
  do {
    auto v73 = e.FriendTypeTemplateParameterLists();
    auto sv73 = b.initVal73(static_cast<unsigned>(v73.size()));
    auto i73 = 0u;
    for (const auto &e73 : v73) {
      sv73.set(i73, es.PseudoId(e73));
      ++i73;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t43 = e.AssemblyToken();
  b.setVal43(es.EntityId(t43));
  b.setVal51(es.EntityId(e.AssemblyString()));
  auto t52 = e.RParenToken();
  b.setVal52(es.EntityId(t52));
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
  auto t43 = e.ExportToken();
  b.setVal43(es.EntityId(t43));
  auto t51 = e.RBraceToken();
  b.setVal51(es.EntityId(t51));
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
