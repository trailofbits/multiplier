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
  auto v63 = e.IsAggregateType();
  if (v63) {
    b.setVal63(static_cast<bool>(v63.value()));
    b.setVal64(true);
  } else {
    b.setVal64(false);
  }
  b.setVal65(e.IsAlignValueT());
  b.setVal66(e.IsAnyCharacterType());
  b.setVal67(e.IsAnyComplexType());
  b.setVal68(e.IsAnyPointerType());
  b.setVal69(e.IsArithmeticType());
  b.setVal70(e.IsArrayType());
  b.setVal71(e.IsAtomicType());
  b.setVal72(e.IsBFloat16Type());
  b.setVal73(e.IsBitIntType());
  b.setVal74(e.IsBlockCompatibleObjCPointerType());
  b.setVal75(e.IsBlockPointerType());
  b.setVal76(e.IsBooleanType());
  b.setVal77(e.IsBuiltinType());
  b.setVal78(e.IsCARCBridgableType());
  b.setVal79(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal80(e.IsCUDADeviceBuiltinTextureType());
  b.setVal81(e.IsCanonicalUnqualified());
  b.setVal82(e.IsChar16Type());
  b.setVal83(e.IsChar32Type());
  b.setVal84(e.IsChar8Type());
  b.setVal85(e.IsCharacterType());
  b.setVal86(e.IsClassType());
  b.setVal87(e.IsClkEventT());
  b.setVal88(e.IsComplexIntegerType());
  b.setVal89(e.IsComplexType());
  b.setVal90(e.IsCompoundType());
  b.setVal91(e.IsConstantArrayType());
  b.setVal92(e.IsConstantMatrixType());
  auto v93 = e.IsConstantSizeType();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal95(e.IsDecltypeType());
  b.setVal96(e.IsDependentAddressSpaceType());
  b.setVal97(e.IsDependentSizedArrayType());
  b.setVal98(e.IsDependentType());
  b.setVal99(e.IsElaboratedTypeSpecifier());
  b.setVal100(e.IsEnumeralType());
  b.setVal101(e.IsEventT());
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
  b.setVal116(e.IsIbm128Type());
  b.setVal117(e.IsImageType());
  b.setVal118(e.IsIncompleteArrayType());
  b.setVal119(e.IsIncompleteOrObjectType());
  b.setVal120(e.IsIncompleteType());
  b.setVal121(e.IsInstantiationDependentType());
  b.setVal122(e.IsIntegerType());
  b.setVal123(e.IsIntegralOrEnumerationType());
  b.setVal124(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal125(e.IsIntegralType());
  b.setVal126(e.IsInterfaceType());
  b.setVal127(e.IsLValueReferenceType());
  b.setVal128(e.IsLinkageValid());
  auto v129 = e.IsLiteralType();
  if (v129) {
    b.setVal129(static_cast<bool>(v129.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  b.setVal131(e.IsMatrixType());
  b.setVal132(e.IsMemberDataPointerType());
  b.setVal133(e.IsMemberFunctionPointerType());
  b.setVal134(e.IsMemberPointerType());
  b.setVal135(e.IsNonOverloadPlaceholderType());
  b.setVal136(e.IsNothrowT());
  b.setVal137(e.IsNullPointerType());
  b.setVal138(e.IsOCLExtOpaqueType());
  b.setVal139(e.IsOCLImage1dArrayROType());
  b.setVal140(e.IsOCLImage1dArrayRWType());
  b.setVal141(e.IsOCLImage1dArrayWOType());
  b.setVal142(e.IsOCLImage1dBufferROType());
  b.setVal143(e.IsOCLImage1dBufferRWType());
  b.setVal144(e.IsOCLImage1dBufferWOType());
  b.setVal145(e.IsOCLImage1dROType());
  b.setVal146(e.IsOCLImage1dRWType());
  b.setVal147(e.IsOCLImage1dWOType());
  b.setVal148(e.IsOCLImage2dArrayDepthROType());
  b.setVal149(e.IsOCLImage2dArrayDepthRWType());
  b.setVal150(e.IsOCLImage2dArrayDepthWOType());
  b.setVal151(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal152(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal153(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal154(e.IsOCLImage2dArrayMSAAROType());
  b.setVal155(e.IsOCLImage2dArrayMSAARWType());
  b.setVal156(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal157(e.IsOCLImage2dArrayROType());
  b.setVal158(e.IsOCLImage2dArrayRWType());
  b.setVal159(e.IsOCLImage2dArrayWOType());
  b.setVal160(e.IsOCLImage2dDepthROType());
  b.setVal161(e.IsOCLImage2dDepthRWType());
  b.setVal162(e.IsOCLImage2dDepthWOType());
  b.setVal163(e.IsOCLImage2dMSAADepthROType());
  b.setVal164(e.IsOCLImage2dMSAADepthRWType());
  b.setVal165(e.IsOCLImage2dMSAADepthWOType());
  b.setVal166(e.IsOCLImage2dMSAAROType());
  b.setVal167(e.IsOCLImage2dMSAARWType());
  b.setVal168(e.IsOCLImage2dMSAAWOType());
  b.setVal169(e.IsOCLImage2dROType());
  b.setVal170(e.IsOCLImage2dRWType());
  b.setVal171(e.IsOCLImage2dWOType());
  b.setVal172(e.IsOCLImage3dROType());
  b.setVal173(e.IsOCLImage3dRWType());
  b.setVal174(e.IsOCLImage3dWOType());
  b.setVal175(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal176(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal177(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal178(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal179(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal180(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal181(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal182(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal183(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal184(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal185(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal186(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal187(e.IsOCLIntelSubgroupAVCType());
  b.setVal188(e.IsObjCARCBridgableType());
  auto v189 = e.IsObjCARCImplicitlyUnretainedType();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  b.setVal191(e.IsObjCBoxableRecordType());
  b.setVal192(e.IsObjCBuiltinType());
  b.setVal193(e.IsObjCClassOrClassKindOfType());
  b.setVal194(e.IsObjCClassType());
  b.setVal195(e.IsObjCIdType());
  b.setVal196(e.IsObjCIndependentClassType());
  b.setVal197(e.IsObjCIndirectLifetimeType());
  b.setVal198(e.IsObjCInertUnsafeUnretainedType());
  b.setVal199(e.IsObjCLifetimeType());
  b.setVal200(e.IsObjCNSObjectType());
  b.setVal201(e.IsObjCObjectOrInterfaceType());
  b.setVal202(e.IsObjCObjectPointerType());
  b.setVal203(e.IsObjCObjectType());
  b.setVal204(e.IsObjCQualifiedClassType());
  b.setVal205(e.IsObjCQualifiedIdType());
  b.setVal206(e.IsObjCQualifiedInterfaceType());
  b.setVal207(e.IsObjCRetainableType());
  b.setVal208(e.IsObjCSelType());
  b.setVal209(e.IsObjectPointerType());
  b.setVal210(e.IsObjectType());
  b.setVal211(e.IsOpenCLSpecificType());
  b.setVal212(e.IsOverloadableType());
  b.setVal213(e.IsPipeType());
  b.setVal214(e.IsPlaceholderType());
  b.setVal215(e.IsPointerType());
  b.setVal216(e.IsPromotableIntegerType());
  b.setVal217(e.IsQueueT());
  b.setVal218(e.IsRValueReferenceType());
  b.setVal219(e.IsRealFloatingType());
  b.setVal220(e.IsRealType());
  b.setVal221(e.IsRecordType());
  b.setVal222(e.IsReferenceType());
  b.setVal223(e.IsReserveIDT());
  b.setVal224(e.IsSamplerT());
  b.setVal225(e.IsSaturatedFixedPointType());
  b.setVal226(e.IsScalarType());
  b.setVal227(e.IsScopedEnumeralType());
  b.setVal228(e.IsSignedFixedPointType());
  b.setVal229(e.IsSignedIntegerOrEnumerationType());
  b.setVal230(e.IsSignedIntegerType());
  b.setVal231(e.IsSizelessBuiltinType());
  b.setVal232(e.IsSizelessType());
  b.setVal233(e.IsSpecifierType());
  auto v234 = e.IsStandardLayoutType();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  b.setVal236(e.IsStdByteType());
  auto v237 = e.IsStructuralType();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  b.setVal239(e.IsStructureOrClassType());
  b.setVal240(e.IsStructureType());
  b.setVal241(e.IsTemplateTypeParmType());
  b.setVal242(e.IsTypedefNameType());
  b.setVal243(e.IsUndeducedAutoType());
  b.setVal244(e.IsUndeducedType());
  b.setVal245(e.IsUnionType());
  b.setVal246(e.IsUnsaturatedFixedPointType());
  b.setVal247(e.IsUnscopedEnumerationType());
  b.setVal248(e.IsUnsignedFixedPointType());
  b.setVal249(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal250(e.IsUnsignedIntegerType());
  b.setVal251(e.IsVLSTBuiltinType());
  b.setVal252(e.IsVariableArrayType());
  b.setVal253(e.IsVariablyModifiedType());
  b.setVal254(e.IsVectorType());
  b.setVal255(e.IsVisibilityExplicit());
  b.setVal256(e.IsVoidPointerType());
  b.setVal257(e.IsVoidType());
  b.setVal258(e.IsWideCharacterType());
  b.setVal259(es.EntityId(e.IgnoreParentheses()));
  b.setVal260(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal261(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal262(es.EntityId(e.CanonicalType()));
  b.setVal263(es.EntityId(e.DesugaredType()));
  b.setVal264(es.EntityId(e.LocalUnqualifiedType()));
  b.setVal265(es.EntityId(e.NonLValueExpressionType()));
  b.setVal266(es.EntityId(e.NonPackExpansionType()));
  b.setVal267(es.EntityId(e.NonReferenceType()));
  b.setVal268(es.EntityId(e.SingleStepDesugaredType()));
  b.setVal269(e.HasAddressSpace());
  b.setVal270(e.HasLocalNonFastQualifiers());
  b.setVal271(e.HasLocalQualifiers());
  b.setVal272(e.HasNonTrivialObjCLifetime());
  b.setVal273(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal274(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal275(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal276(e.HasQualifiers());
  b.setVal277(e.HasStrongOrWeakObjCLifetime());
  b.setVal278(e.IsCForbiddenLValueType());
  b.setVal279(e.IsCXX11PODType());
  b.setVal280(e.IsCXX98PODType());
  b.setVal281(e.IsCanonical());
  b.setVal282(e.IsCanonicalAsParameter());
  b.setVal283(e.IsConstQualified());
  b.setVal284(e.IsConstant());
  b.setVal285(static_cast<unsigned char>(mx::FromPasta(e.IsDestructedType())));
  b.setVal286(e.IsLocalConstQualified());
  b.setVal287(e.IsLocalRestrictQualified());
  b.setVal288(e.IsLocalVolatileQualified());
  b.setVal289(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveCopy())));
  b.setVal290(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDefaultInitialize())));
  b.setVal291(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDestructiveMove())));
  b.setVal292(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal293(e.IsNull());
  b.setVal294(e.IsObjCGCStrong());
  b.setVal295(e.IsObjCGCWeak());
  b.setVal296(e.IsPODType());
  b.setVal297(e.IsRestrictQualified());
  b.setVal298(e.IsTrivialType());
  b.setVal299(e.IsTriviallyCopyableType());
  b.setVal300(e.IsVolatileQualified());
  b.setVal301(e.MayBeDynamicClass());
  b.setVal302(e.MayBeNotDynamicClass());
  b.setVal303(es.EntityId(e.StripObjCKindOfType()));
  b.setVal304(es.EntityId(e.WithConst()));
  b.setVal305(es.EntityId(e.WithRestrict()));
  b.setVal306(es.EntityId(e.WithVolatile()));
  b.setVal307(es.EntityId(e.WithoutLocalFastQualifiers()));
}

void SerializeTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto v309 = e.Declaration();
  if (v309) {
    auto id309 = es.EntityId(v309.value());    b.setVal309(id309);
    b.setVal310(id309 != mx::kInvalidEntityId);
  } else {
    b.setVal309(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  b.setVal311(e.IsParameterPack());
  b.setVal312(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto v309 = e.AliasedType();
  if (v309) {
    auto id309 = es.EntityId(v309.value());    b.setVal309(id309);
    b.setVal310(id309 != mx::kInvalidEntityId);
  } else {
    b.setVal309(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  b.setVal311(e.IsCurrentInstantiation());
  b.setVal312(e.IsSugared());
  b.setVal313(e.IsTypeAlias());
  do {
    auto v314 = e.TemplateArguments();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.PseudoId(e314));
      ++i314;
    }
  } while (false);
}

void SerializeTagType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Declaration()));
  b.setVal310(e.IsBeingDefined());
}

void SerializeRecordType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  b.setVal311(e.HasConstFields());
  b.setVal312(e.IsSugared());
}

void SerializeEnumType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  b.setVal311(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ReplacedParameter()));
  b.setVal315(es.EntityId(e.ReplacementType()));
  b.setVal310(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ReplacedParameter()));
  b.setVal310(e.IsSugared());
}

void SerializeReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal310(e.IsInnerReference());
  b.setVal311(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializeLValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializePointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializePipeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ElementType()));
  b.setVal310(e.IsReadOnly());
  b.setVal311(e.IsSugared());
}

void SerializeParenType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.InnerType()));
  b.setVal310(e.IsSugared());
}

void SerializePackExpansionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto v316 = e.NumExpansions();
  if (v316) {
    b.setVal316(static_cast<unsigned>(v316.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  b.setVal309(es.EntityId(e.Pattern()));
  b.setVal311(e.IsSugared());
}

void SerializeObjCTypeParamType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.Declaration()));
  b.setVal310(e.IsSugared());
}

void SerializeObjCObjectType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.BaseType()));
  b.setVal315(es.EntityId(e.Interface()));
  auto v317 = e.SuperClassType();
  if (v317) {
    auto id317 = es.EntityId(v317.value());    b.setVal317(id317);
    b.setVal310(id317 != mx::kInvalidEntityId);
  } else {
    b.setVal317(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  do {
    auto v318 = e.TypeArguments();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  do {
    auto v319 = e.TypeArgumentsAsWritten();
    auto sv319 = b.initVal319(static_cast<unsigned>(v319.size()));
    auto i319 = 0u;
    for (const auto &e319 : v319) {
      sv319.set(i319, es.EntityId(e319));
      ++i319;
    }
  } while (false);
  b.setVal311(e.IsKindOfType());
  b.setVal312(e.IsKindOfTypeAsWritten());
  b.setVal313(e.IsObjCClass());
  b.setVal320(e.IsObjCId());
  b.setVal321(e.IsObjCQualifiedClass());
  b.setVal322(e.IsObjCQualifiedId());
  b.setVal323(e.IsObjCUnqualifiedClass());
  b.setVal324(e.IsObjCUnqualifiedId());
  b.setVal325(e.IsObjCUnqualifiedIdOrClass());
  b.setVal326(e.IsSpecialized());
  b.setVal327(e.IsSpecializedAsWritten());
  b.setVal328(e.IsSugared());
  b.setVal329(e.IsUnspecialized());
  b.setVal330(e.IsUnspecializedAsWritten());
  b.setVal331(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
}

void SerializeObjCInterfaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal332(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.InterfaceDeclaration()));
  b.setVal315(es.EntityId(e.InterfaceType()));
  b.setVal317(es.EntityId(e.ObjectType()));
  b.setVal331(es.EntityId(e.SuperClassType()));
  do {
    auto v318 = e.TypeArguments();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  do {
    auto v319 = e.TypeArgumentsAsWritten();
    auto sv319 = b.initVal319(static_cast<unsigned>(v319.size()));
    auto i319 = 0u;
    for (const auto &e319 : v319) {
      sv319.set(i319, es.EntityId(e319));
      ++i319;
    }
  } while (false);
  b.setVal310(e.IsKindOfType());
  b.setVal311(e.IsObjCIdOrClassType());
  b.setVal312(e.IsSpecialized());
  b.setVal313(e.IsSpecializedAsWritten());
  b.setVal320(e.IsSugared());
  b.setVal321(e.IsUnspecialized());
  b.setVal322(e.IsUnspecializedAsWritten());
  do {
    auto v333 = e.Qualifieds();
    auto sv333 = b.initVal333(static_cast<unsigned>(v333.size()));
    auto i333 = 0u;
    for (const auto &e333 : v333) {
      sv333.set(i333, es.EntityId(e333));
      ++i333;
    }
  } while (false);
  b.setVal332(es.EntityId(e.StripObjCKindOfTypeAndQualifieds()));
  do {
    auto v334 = e.Protocols();
    auto sv334 = b.initVal334(static_cast<unsigned>(v334.size()));
    auto i334 = 0u;
    for (const auto &e334 : v334) {
      sv334.set(i334, es.EntityId(e334));
      ++i334;
    }
  } while (false);
}

void SerializeMemberPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.Class()));
  b.setVal315(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal310(e.IsMemberDataPointer());
  b.setVal311(e.IsMemberFunctionPointer());
  b.setVal312(e.IsSugared());
}

void SerializeMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ElementType()));
  b.setVal310(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  auto t315 = e.AttributeToken();
  b.setVal315(es.EntityId(t315));
  b.setVal317(es.EntityId(e.ColumnExpression()));
  b.setVal331(es.EntityId(e.RowExpression()));
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
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ModifiedType()));
  b.setVal315(es.EntityId(e.UnderlyingType()));
  b.setVal310(e.IsSugared());
}

void SerializeInjectedClassNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.Declaration()));
  b.setVal315(es.EntityId(e.InjectedSpecializationType()));
  b.setVal317(es.EntityId(e.InjectedTST()));
  b.setVal310(e.IsSugared());
}

void SerializeFunctionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal308(es.EntityId(e.CallResultType()));
  b.setVal310(e.CmseNSCallAttribute());
  b.setVal311(e.HasRegParm());
  b.setVal312(e.NoReturnAttribute());
  b.setVal309(es.EntityId(e.ReturnType()));
  b.setVal313(e.IsConst());
  b.setVal320(e.IsRestrict());
  b.setVal321(e.IsVolatile());
}

void SerializeFunctionProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  auto v336 = e.CanThrow();
  if (v336) {
    b.setVal336(static_cast<unsigned char>(v336.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  b.setVal315(es.EntityId(e.Desugar()));
  do {
    auto v318 = e.Exceptions();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  auto t317 = e.EllipsisToken();
  b.setVal317(es.EntityId(t317));
  auto v331 = e.ExceptionSpecDeclaration();
  if (v331) {
    auto id331 = es.EntityId(v331.value());    b.setVal331(id331);
    b.setVal323(id331 != mx::kInvalidEntityId);
  } else {
    b.setVal331(mx::kInvalidEntityId);
    b.setVal323(false);
  }
  auto v332 = e.ExceptionSpecTemplate();
  if (v332) {
    auto id332 = es.EntityId(v332.value());    b.setVal332(id332);
    b.setVal324(id332 != mx::kInvalidEntityId);
  } else {
    b.setVal332(mx::kInvalidEntityId);
    b.setVal324(false);
  }
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v338 = e.NoexceptExpression();
  if (v338) {
    auto id338 = es.EntityId(v338.value());    b.setVal338(id338);
    b.setVal325(id338 != mx::kInvalidEntityId);
  } else {
    b.setVal338(mx::kInvalidEntityId);
    b.setVal325(false);
  }
  do {
    auto v319 = e.ParameterTypes();
    auto sv319 = b.initVal319(static_cast<unsigned>(v319.size()));
    auto i319 = 0u;
    for (const auto &e319 : v319) {
      sv319.set(i319, es.EntityId(e319));
      ++i319;
    }
  } while (false);
  b.setVal339(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal326(e.HasDependentExceptionSpec());
  b.setVal327(e.HasDynamicExceptionSpec());
  b.setVal328(e.HasExceptionSpec());
  b.setVal329(e.HasExtParameterInfos());
  b.setVal330(e.HasInstantiationDependentExceptionSpec());
  b.setVal340(e.HasNoexceptExceptionSpec());
  b.setVal341(e.HasTrailingReturn());
  auto v342 = e.IsNothrow();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  b.setVal344(e.IsSugared());
  b.setVal345(e.IsTemplateVariadic());
  b.setVal346(e.IsVariadic());
  do {
    auto v333 = e.ExceptionTypes();
    auto sv333 = b.initVal333(static_cast<unsigned>(v333.size()));
    auto i333 = 0u;
    for (const auto &e333 : v333) {
      sv333.set(i333, es.EntityId(e333));
      ++i333;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal315(es.EntityId(e.Desugar()));
  b.setVal322(e.IsSugared());
}

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto t309 = e.AttributeToken();
  b.setVal309(es.EntityId(t309));
  b.setVal315(es.EntityId(e.ElementType()));
  b.setVal317(es.EntityId(e.SizeExpression()));
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal310(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto t309 = e.AttributeToken();
  b.setVal309(es.EntityId(t309));
  b.setVal315(es.EntityId(e.ElementType()));
  b.setVal317(es.EntityId(e.SizeExpression()));
  b.setVal310(e.IsSugared());
}

void SerializeDependentBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.NumBitsExpression()));
  b.setVal310(e.IsSigned());
  b.setVal311(e.IsSugared());
  b.setVal312(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.AddrSpaceExpression()));
  auto t315 = e.AttributeToken();
  b.setVal315(es.EntityId(t315));
  b.setVal310(e.IsSugared());
}

void SerializeDeducedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  auto v309 = e.ResolvedType();
  if (v309) {
    auto id309 = es.EntityId(v309.value());    b.setVal309(id309);
    b.setVal310(id309 != mx::kInvalidEntityId);
  } else {
    b.setVal309(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  b.setVal311(e.IsDeduced());
  b.setVal312(e.IsSugared());
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
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v314 = e.TypeConstraintArguments();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.PseudoId(e314));
      ++i314;
    }
  } while (false);
  auto v315 = e.TypeConstraintConcept();
  if (v315) {
    auto id315 = es.EntityId(v315.value());    b.setVal315(id315);
    b.setVal313(id315 != mx::kInvalidEntityId);
  } else {
    b.setVal315(mx::kInvalidEntityId);
    b.setVal313(false);
  }
  b.setVal320(e.IsConstrained());
  b.setVal321(e.IsDecltypeAuto());
}

void SerializeDecltypeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.UnderlyingExpression()));
  b.setVal315(es.EntityId(e.UnderlyingType()));
  b.setVal310(e.IsSugared());
}

void SerializeComplexType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ElementType()));
  b.setVal310(e.IsSugared());
}

void SerializeBuiltinType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal310(e.IsFloatingPoint());
  b.setVal311(e.IsInteger());
  b.setVal312(e.IsSignedInteger());
  b.setVal313(e.IsSugared());
  b.setVal320(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializeBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSigned());
  b.setVal311(e.IsSugared());
  b.setVal312(e.IsUnsigned());
}

void SerializeAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal347(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal309(es.EntityId(e.EquivalentType()));
  auto v335 = e.ImmediateNullability();
  if (v335) {
    b.setVal335(static_cast<unsigned char>(v335.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  b.setVal315(es.EntityId(e.ModifiedType()));
  b.setVal311(e.IsCallingConv());
  b.setVal312(e.IsMSTypeSpec());
  b.setVal313(e.IsQualifier());
  b.setVal320(e.IsSugared());
}

void SerializeAtomicType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ValueType()));
  b.setVal310(e.IsSugared());
}

void SerializeArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.ElementType()));
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  if (auto r315 = e.BracketsRange(); auto rs315 = r315.Size()) {
    b.setVal315(es.EntityId(r315[0]));
    b.setVal317(es.EntityId(r315[rs315 - 1u]));
  } else {
    b.setVal315(0);
    b.setVal317(0);
  }
  auto t331 = e.LBracketToken();
  b.setVal331(es.EntityId(t331));
  auto t332 = e.RBracketToken();
  b.setVal332(es.EntityId(t332));
  b.setVal338(es.EntityId(e.SizeExpression()));
  b.setVal310(e.IsSugared());
}

void SerializeIncompleteArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  if (auto r315 = e.BracketsRange(); auto rs315 = r315.Size()) {
    b.setVal315(es.EntityId(r315[0]));
    b.setVal317(es.EntityId(r315[rs315 - 1u]));
  } else {
    b.setVal315(0);
    b.setVal317(0);
  }
  auto t331 = e.LBracketToken();
  b.setVal331(es.EntityId(t331));
  auto t332 = e.RBracketToken();
  b.setVal332(es.EntityId(t332));
  b.setVal338(es.EntityId(e.SizeExpression()));
  b.setVal310(e.IsSugared());
}

void SerializeConstantArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal309(es.EntityId(e.Desugar()));
  auto v315 = e.SizeExpression();
  if (v315) {
    auto id315 = es.EntityId(v315.value());    b.setVal315(id315);
    b.setVal310(id315 != mx::kInvalidEntityId);
  } else {
    b.setVal315(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  b.setVal311(e.IsSugared());
}

void SerializeAdjustedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ResolvedType()));
  b.setVal315(es.EntityId(e.OriginalType()));
  b.setVal310(e.IsSugared());
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
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.NamedType()));
  auto v315 = e.OwnedTagDeclaration();
  if (v315) {
    auto id315 = es.EntityId(v315.value());    b.setVal315(id315);
    b.setVal310(id315 != mx::kInvalidEntityId);
  } else {
    b.setVal315(mx::kInvalidEntityId);
    b.setVal310(false);
  }
  b.setVal311(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
  do {
    auto v314 = e.TemplateArguments();
    auto sv314 = b.initVal314(static_cast<unsigned>(v314.size()));
    auto i314 = 0u;
    for (const auto &e314 : v314) {
      sv314.set(i314, es.PseudoId(e314));
      ++i314;
    }
  } while (false);
}

void SerializeDependentNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal310(e.IsSugared());
}

void SerializeVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.ElementType()));
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal310(e.IsSugared());
}

void SerializeExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(es, b, e);
}

void SerializeUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.FoundDeclaration()));
  b.setVal315(es.EntityId(e.UnderlyingType()));
  b.setVal310(e.IsSugared());
}

void SerializeUnresolvedUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.Declaration()));
  b.setVal310(e.IsSugared());
}

void SerializeUnaryTransformType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.BaseType()));
  b.setVal335(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal315(es.EntityId(e.UnderlyingType()));
  b.setVal310(e.IsSugared());
}

void SerializeTypedefType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.Declaration()));
  b.setVal310(e.IsSugared());
}

void SerializeTypeOfType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.UnderlyingType()));
  b.setVal310(e.IsSugared());
}

void SerializeTypeOfExprType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal308(es.EntityId(e.Desugar()));
  b.setVal309(es.EntityId(e.UnderlyingExpression()));
  b.setVal310(e.IsSugared());
}

void SerializeStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  if (auto r2 = ReferencedDecl(e)) {
    b.setVal2(es.EntityId(r2.value()));
  }
  b.setVal3(es.EntityId(e.IgnoreContainers()));
  do {
    auto v4 = e.Children();
    auto sv4 = b.initVal4(static_cast<unsigned>(v4.size()));
    auto i4 = 0u;
    for (const auto &e4 : v4) {
      sv4.set(i4, es.EntityId(e4));
      ++i4;
    }
  } while (false);
  if (auto r5 = e.Tokens(); auto rs5 = r5.Size()) {
    b.setVal5(es.EntityId(r5[0]));
    b.setVal6(es.EntityId(r5[rs5 - 1u]));
  } else {
    b.setVal5(0);
    b.setVal6(0);
  }
  b.setVal7(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal8(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ExceptHandler()));
  b.setVal10(es.EntityId(e.FinallyHandler()));
  b.setVal11(es.EntityId(e.Handler()));
  b.setVal12(e.IsCXXTry());
  b.setVal13(es.EntityId(e.TryBlock()));
  auto t14 = e.TryToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeSEHLeaveStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.LeaveToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeSEHFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.FinallyToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeSEHExceptStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.ExceptToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.NRVOCandidate();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal12(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v10 = e.ReturnValue();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal15(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto t11 = e.ReturnToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeObjCForCollectionStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Collection()));
  b.setVal11(es.EntityId(e.Element()));
  auto t13 = e.ForToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeObjCAutoreleasePoolStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtTryToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.FinallyStatement()));
  b.setVal11(es.EntityId(e.TryBody()));
  do {
    auto v16 = e.CatchStatements();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeObjCAtThrowStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ThrowExpression()));
  auto t10 = e.ThrowToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeObjCAtSynchronizedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtSynchronizedToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SynchBody()));
  b.setVal11(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtFinallyToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtCatchToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.CatchBody()));
  b.setVal11(es.EntityId(e.CatchParameterDeclaration()));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
  b.setVal12(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AssociatedStatement()));
  b.setVal10(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal11(es.EntityId(e.RawStatement()));
  b.setVal13(es.EntityId(e.StructuredBlock()));
  b.setVal12(e.HasAssociatedStatement());
  b.setVal15(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  auto t14 = e.TargetCallToken();
  b.setVal14(es.EntityId(t14));
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
  b.setVal14(es.EntityId(e.Expression()));
  b.setVal17(es.EntityId(e.UpdateExpression()));
  b.setVal18(es.EntityId(e.V()));
  b.setVal19(es.EntityId(e.X()));
  b.setVal20(e.IsPostfixUpdate());
  b.setVal21(e.IsXLHSInRHSPart());
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
  b.setVal14(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal20(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
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
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPSectionDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal20(e.HasCancel());
}

void SerializeOMPScanDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMetaDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.IfStatement()));
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

void SerializeOMPLoopTransformationDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal14(es.EntityId(e.PreInitializers()));
  b.setVal17(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPUnrollDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopTransformationDirective(es, b, e);
}

void SerializeOMPTileDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopTransformationDirective(es, b, e);
}

void SerializeOMPLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  do {
    auto v16 = e.Counters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  do {
    auto v22 = e.DependentCounters();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
  do {
    auto v23 = e.DependentInitializers();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
  do {
    auto v24 = e.Finals();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  do {
    auto v25 = e.FinalsConditions();
    auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
    auto i25 = 0u;
    for (const auto &e25 : v25) {
      sv25.set(i25, es.EntityId(e25));
      ++i25;
    }
  } while (false);
  b.setVal14(es.EntityId(e.Body()));
  b.setVal17(es.EntityId(e.CalculateLastIteration()));
  b.setVal18(es.EntityId(e.CombinedCondition()));
  b.setVal19(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal26(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal27(es.EntityId(e.CombinedInitializer()));
  b.setVal28(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal29(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal30(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal31(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal32(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal33(es.EntityId(e.Condition()));
  b.setVal34(es.EntityId(e.DistanceIncrement()));
  b.setVal35(es.EntityId(e.EnsureUpperBound()));
  b.setVal36(es.EntityId(e.Increment()));
  b.setVal37(es.EntityId(e.Initializer()));
  b.setVal38(es.EntityId(e.IsLastIterationVariable()));
  b.setVal39(es.EntityId(e.IterationVariable()));
  b.setVal40(es.EntityId(e.LastIteration()));
  b.setVal41(es.EntityId(e.LowerBoundVariable()));
  b.setVal42(es.EntityId(e.NextLowerBound()));
  b.setVal43(es.EntityId(e.NextUpperBound()));
  b.setVal44(es.EntityId(e.NumIterations()));
  b.setVal45(es.EntityId(e.PreCondition()));
  b.setVal46(es.EntityId(e.PreInitializers()));
  b.setVal47(es.EntityId(e.PrevEnsureUpperBound()));
  b.setVal48(es.EntityId(e.PrevLowerBoundVariable()));
  b.setVal49(es.EntityId(e.PrevUpperBoundVariable()));
  b.setVal50(es.EntityId(e.StrideVariable()));
  b.setVal51(es.EntityId(e.UpperBoundVariable()));
  do {
    auto v52 = e.Initializers();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v53 = e.PrivateCounters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v54 = e.Updates();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeOMPGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
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
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal20(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
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
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal20(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal20(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal20(e.HasCancel());
}

void SerializeOMPInteropDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal10(es.EntityId(e.LoopStatement()));
  b.setVal11(es.EntityId(e.LoopVariableFunc()));
  b.setVal13(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.SemiToken();
  b.setVal9(es.EntityId(t9));
  b.setVal12(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsIfExists());
  b.setVal15(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConstantTarget();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal12(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto t10 = e.GotoToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.StarToken();
  b.setVal11(es.EntityId(t11));
  b.setVal13(es.EntityId(e.Target()));
}

void SerializeIfStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Condition()));
  auto v10 = e.ConditionVariable();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal12(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v11 = e.ConditionVariableDeclarationStatement();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal15(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v13 = e.Else();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal20(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t14 = e.ElseToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.IfToken();
  b.setVal17(es.EntityId(t17));
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());    b.setVal18(id18);
    b.setVal21(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  auto t19 = e.LParenToken();
  b.setVal19(es.EntityId(t19));
  auto t26 = e.RParenToken();
  b.setVal26(es.EntityId(t26));
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal27(es.EntityId(e.Then()));
  b.setVal57(e.HasElseStorage());
  b.setVal58(e.HasInitializerStorage());
  b.setVal59(e.HasVariableStorage());
  b.setVal60(e.IsConsteval());
  b.setVal61(e.IsConstexpr());
  b.setVal62(e.IsNegatedConsteval());
  b.setVal63(e.IsNonNegatedConsteval());
  b.setVal64(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.GotoToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Label()));
  auto t11 = e.LabelToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeForStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  auto v10 = e.Condition();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal12(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal15(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal20(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto v17 = e.Increment();
  if (v17) {
    auto id17 = es.EntityId(v17.value());    b.setVal17(id17);
    b.setVal21(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());    b.setVal18(id18);
    b.setVal57(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal57(false);
  }
  auto t19 = e.LParenToken();
  b.setVal19(es.EntityId(t19));
  auto t26 = e.RParenToken();
  b.setVal26(es.EntityId(t26));
}

void SerializeDoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto t11 = e.DoToken();
  b.setVal11(es.EntityId(t11));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.WhileToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeDeclStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  do {
    auto v16 = e.Declarations();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto v9 = e.SingleDeclaration();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal12(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal15(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Allocate()));
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Deallocate()));
  b.setVal13(es.EntityId(e.ExceptionHandler()));
  b.setVal14(es.EntityId(e.FallthroughHandler()));
  b.setVal17(es.EntityId(e.FinalSuspendStatement()));
  b.setVal18(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v16 = e.ParameterMoves();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal19(es.EntityId(e.PromiseDeclaration()));
  b.setVal26(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal27(es.EntityId(e.ResultDeclaration()));
  b.setVal28(es.EntityId(e.ReturnStatement()));
  b.setVal29(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal30(es.EntityId(e.ReturnValueInitializer()));
  b.setVal12(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Operand()));
  b.setVal11(es.EntityId(e.PromiseCall()));
  b.setVal12(e.IsImplicit());
}

void SerializeContinueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.ContinueToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeCompoundStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.LeftBraceToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.RightBraceToken();
  b.setVal10(es.EntityId(t10));
  auto v11 = e.StatementExpressionResult();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
}

void SerializeCapturedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal11(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.TryBlock()));
  auto t10 = e.TryToken();
  b.setVal10(es.EntityId(t10));
  do {
    auto v16 = e.Handlers();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeCXXForRangeStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.BeginStatement()));
  b.setVal10(es.EntityId(e.Body()));
  auto t11 = e.CoawaitToken();
  b.setVal11(es.EntityId(t11));
  auto t13 = e.ColonToken();
  b.setVal13(es.EntityId(t13));
  b.setVal14(es.EntityId(e.Condition()));
  b.setVal17(es.EntityId(e.EndStatement()));
  auto t18 = e.ForToken();
  b.setVal18(es.EntityId(t18));
  b.setVal19(es.EntityId(e.Increment()));
  auto v26 = e.Initializer();
  if (v26) {
    auto id26 = es.EntityId(v26.value());    b.setVal26(id26);
    b.setVal12(id26 != mx::kInvalidEntityId);
  } else {
    b.setVal26(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal27(es.EntityId(e.LoopVariableStatement()));
  b.setVal28(es.EntityId(e.LoopVariable()));
  auto t29 = e.RParenToken();
  b.setVal29(es.EntityId(t29));
  b.setVal30(es.EntityId(e.RangeInitializer()));
  b.setVal31(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.CatchToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.CaughtType()));
  auto v11 = e.ExceptionDeclaration();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal13(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.BreakToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal65(e.GenerateAssemblyString());
  auto t9 = e.AssemblyToken();
  b.setVal9(es.EntityId(t9));
  do {
    auto v16 = e.Inputs();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal12(e.IsSimple());
  b.setVal15(e.IsVolatile());
  do {
    auto v22 = e.Outputs();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
  do {
    auto v66 = e.OutputConstraints();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
  do {
    auto v23 = e.OutputExpressions();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
  do {
    auto v67 = e.InputConstraints();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
  do {
    auto v24 = e.InputExpressions();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  do {
    auto v68 = e.Clobbers();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
    }
  } while (false);
}

void SerializeMSAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  do {
    auto v69 = e.AllConstraints();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
    }
  } while (false);
  do {
    auto v25 = e.AllExpressions();
    auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
    auto i25 = 0u;
    for (const auto &e25 : v25) {
      sv25.set(i25, es.EntityId(e25));
      ++i25;
    }
  } while (false);
  auto v70 = e.AssemblyString();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t10 = e.LBraceToken();
  b.setVal10(es.EntityId(t10));
  b.setVal20(e.HasBraces());
}

void SerializeGCCAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal10(es.EntityId(e.AssemblyString()));
  auto t11 = e.RParenToken();
  b.setVal11(es.EntityId(t11));
  b.setVal20(e.IsAssemblyGoto());
  do {
    auto v25 = e.Labels();
    auto sv25 = b.initVal25(static_cast<unsigned>(v25.size()));
    auto i25 = 0u;
    for (const auto &e25 : v25) {
      sv25.set(i25, es.EntityId(e25));
      ++i25;
    }
  } while (false);
  do {
    auto v52 = e.OutputConstraintLiterals();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v69 = e.OutputNames();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
    }
  } while (false);
  do {
    auto v53 = e.InputConstraintLiterals();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v71 = e.InputNames();
    auto sv71 = b.initVal71(static_cast<unsigned>(v71.size()));
    auto i71 = 0u;
    for (const auto &e71 : v71) {
      std::string se71(e71.data(), e71.size());
      sv71.set(i71, se71);
      ++i71;
    }
  } while (false);
  do {
    auto v54 = e.ClobberStringLiterals();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v72 = e.LabelExpressions();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      sv72.set(i72, es.EntityId(e72));
      ++i72;
    }
  } while (false);
  do {
    auto v73 = e.LabelNames();
    auto sv73 = b.initVal73(static_cast<unsigned>(v73.size()));
    auto i73 = 0u;
    for (const auto &e73 : v73) {
      std::string se73(e73.data(), e73.size());
      sv73.set(i73, se73);
      ++i73;
    }
  } while (false);
}

void SerializeWhileStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal15(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto t14 = e.LParenToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.RParenToken();
  b.setVal17(es.EntityId(t17));
  auto t18 = e.WhileToken();
  b.setVal18(es.EntityId(t18));
  b.setVal20(e.HasVariableStorage());
}

void SerializeValueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal12(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal12(false);
  }
}

void SerializeLabelStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal10(es.EntityId(e.Declaration()));
  auto t11 = e.IdentifierToken();
  b.setVal11(es.EntityId(t11));
  auto v65 = e.Name();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal13(es.EntityId(e.SubStatement()));
  b.setVal15(e.IsSideEntry());
}

void SerializeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal15(e.HasSideEffects());
  b.setVal10(es.EntityId(e.IgnoreCasts()));
  b.setVal11(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal13(es.EntityId(e.IgnoreImpCasts()));
  b.setVal14(es.EntityId(e.IgnoreImplicit()));
  b.setVal17(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal18(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal19(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal26(es.EntityId(e.IgnoreParenthesisImpCasts()));
  b.setVal27(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal28(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal29(es.EntityId(e.IgnoreParentheses()));
  b.setVal30(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal20(e.ContainsErrors());
  b.setVal21(e.ContainsUnexpandedParameterPack());
  b.setVal31(es.EntityId(e.BestDynamicClassTypeExpression()));
  auto t32 = e.ExpressionToken();
  b.setVal32(es.EntityId(t32));
  auto v33 = e.ObjCProperty();
  if (v33) {
    auto id33 = es.EntityId(v33.value());    b.setVal33(id33);
    b.setVal57(id33 != mx::kInvalidEntityId);
  } else {
    b.setVal33(mx::kInvalidEntityId);
    b.setVal57(false);
  }
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v34 = e.ReferencedDeclarationOfCallee();
  if (v34) {
    auto id34 = es.EntityId(v34.value());    b.setVal34(id34);
    b.setVal58(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto v35 = e.SourceBitField();
  if (v35) {
    auto id35 = es.EntityId(v35.value());    b.setVal35(id35);
    b.setVal59(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal59(false);
  }
  auto v36 = e.Type();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal60(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal60(false);
  }
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal61(e.HasNonTrivialCall());
  auto v62 = e.IsCXX98IntegralConstantExpression();
  if (v62) {
    b.setVal62(static_cast<bool>(v62.value()));
    b.setVal63(true);
  } else {
    b.setVal63(false);
  }
  b.setVal64(e.IsDefaultArgument());
  b.setVal75(e.IsGLValue());
  b.setVal76(e.IsImplicitCXXThis());
  b.setVal77(e.IsInstantiationDependent());
  auto v78 = e.IsIntegerConstantExpression();
  if (v78) {
    b.setVal78(static_cast<bool>(v78.value()));
    b.setVal79(true);
  } else {
    b.setVal79(false);
  }
  b.setVal80(e.IsKnownToHaveBooleanValue());
  b.setVal81(e.IsLValue());
  b.setVal82(e.IsOBJCGCCandidate());
  b.setVal83(e.IsObjCSelfExpression());
  b.setVal84(e.IsOrdinaryOrBitFieldObject());
  b.setVal85(e.IsPRValue());
  b.setVal86(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal87(e.IsTypeDependent());
  b.setVal88(e.IsValueDependent());
  b.setVal89(e.IsXValue());
  b.setVal90(e.RefersToBitField());
  b.setVal91(e.RefersToGlobalRegisterVariable());
  b.setVal92(e.RefersToMatrixElement());
  b.setVal93(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r37 = e.DesignatorsSourceRange(); auto rs37 = r37.Size()) {
    b.setVal37(es.EntityId(r37[0]));
    b.setVal38(es.EntityId(r37[rs37 - 1u]));
  } else {
    b.setVal37(0);
    b.setVal38(0);
  }
  auto t39 = e.EqualOrColonToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal94(e.IsDirectInitializer());
  b.setVal95(e.UsesGNUSyntax());
  do {
    auto v16 = e.SubExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.LAngleToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.TemplateKeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal94(e.HasExplicitTemplateArguments());
  b.setVal95(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.KeywordToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal39(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Declaration()));
  b.setVal38(es.EntityId(e.FoundDeclaration()));
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.TemplateKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal94(e.HadMultipleCandidates());
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasQualifier());
  b.setVal97(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal98(e.HasTemplateKeyword());
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal100(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.CommonExpression()));
  auto t38 = e.KeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.OpaqueValue()));
  b.setVal40(es.EntityId(e.ReadyExpression()));
  b.setVal41(es.EntityId(e.ResumeExpression()));
  b.setVal42(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal43(es.EntityId(e.Operand()));
  b.setVal94(e.IsImplicit());
}

void SerializeCoyieldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal43(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v101 = e.TemplateArguments();
    auto sv101 = b.initVal101(static_cast<unsigned>(v101.size()));
    auto i101 = 0u;
    for (const auto &e101 : v101) {
      sv101.set(i101, es.PseudoId(e101));
      ++i101;
    }
  } while (false);
  b.setVal94(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Initializer()));
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal94(e.IsFileScope());
}

void SerializeChooseExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.ChosenSubExpression()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RHS()));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal94(e.IsConditionDependent());
  b.setVal95(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v65 = e.CastKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto v37 = e.ConversionFunction();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.SubExpressionAsWritten()));
  auto v40 = e.TargetUnionField();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal96(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal97(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal41(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r42 = e.AngleBrackets(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  auto v70 = e.CastName();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXDynamicCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal97(e.IsAlwaysNull());
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
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal97(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeBuiltinBitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t42 = e.BridgeKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v70 = e.BridgeKindName();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.Callee()));
  auto v39 = e.CalleeDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal94(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v40 = e.DirectCallee();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal96(e.HasStoredFPFeatures());
  b.setVal97(e.HasUnusedResultAttribute());
  b.setVal98(e.IsBuiltinAssumeFalse());
  b.setVal100(e.IsCallToStdMove());
  b.setVal103(e.IsUnevaluatedBuiltinCall());
  b.setVal104(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  b.setVal105(e.IsAssignmentOperation());
  b.setVal106(e.IsComparisonOperation());
  b.setVal107(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal42(es.EntityId(e.ImplicitObjectArgument()));
  auto v43 = e.MethodDeclaration();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal105(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal105(false);
  }
  b.setVal44(es.EntityId(e.ObjectType()));
  b.setVal45(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal42(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal42(es.EntityId(e.CookedLiteral()));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t43 = e.UDSuffixToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.GuidDeclaration()));
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal95(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.TypeAsWritten()));
  b.setVal94(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.TypeOperand()));
  b.setVal39(es.EntityId(e.TypeOperandSourceInfo()));
  auto v95 = e.IsMostDerived();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal97(e.IsPotentiallyEvaluated());
  b.setVal98(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.SubExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t38 = e.ThrowToken();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeCXXRewrittenBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal94(e.IsAssignmentOperation());
  b.setVal95(e.IsComparisonOperation());
  b.setVal96(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto t38 = e.ColonColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.DestroyedType()));
  auto t40 = e.DestroyedTypeToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.ScopeType();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal94(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t43 = e.TildeToken();
  b.setVal43(es.EntityId(t43));
  b.setVal95(e.HasQualifier());
  b.setVal96(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal94(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.AllocatedType()));
  auto v38 = e.ArraySize();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v39 = e.ConstructExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  if (auto r40 = e.DirectInitializerRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v42 = e.Initializer();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal97(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal43(es.EntityId(e.OperatorDelete()));
  b.setVal44(es.EntityId(e.OperatorNew()));
  if (auto r45 = e.TypeIdParentheses(); auto rs45 = r45.Size()) {
    b.setVal45(es.EntityId(r45[0]));
    b.setVal46(es.EntityId(r45[rs45 - 1u]));
  } else {
    b.setVal45(0);
    b.setVal46(0);
  }
  b.setVal98(e.HasInitializer());
  b.setVal100(e.IsArray());
  b.setVal103(e.IsGlobalNew());
  b.setVal104(e.IsParenthesisTypeId());
  b.setVal105(e.PassAlignment());
  do {
    auto v16 = e.PlacementArguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal106(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.ConstructsVirtualBase());
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Callee()));
  auto t38 = e.EllipsisToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.LHS()));
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto v108 = e.NumExpansions();
  if (v108) {
    b.setVal108(static_cast<unsigned>(v108.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal95(e.IsLeftFold());
  b.setVal96(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.Base();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.BaseType()));
  auto v39 = e.FirstQualifierFoundInScope();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal95(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t40 = e.LAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.MemberToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RAngleToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.TemplateKeywordToken();
  b.setVal44(es.EntityId(t44));
  b.setVal96(e.HasExplicitTemplateArguments());
  b.setVal97(e.HasTemplateKeyword());
  b.setVal98(e.IsArrow());
  b.setVal100(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  b.setVal38(es.EntityId(e.DestroyedType()));
  b.setVal39(es.EntityId(e.OperatorDelete()));
  b.setVal95(e.IsArrayForm());
  b.setVal96(e.IsArrayFormAsWritten());
  b.setVal97(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.Expression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.Field()));
  auto t39 = e.UsedToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXDefaultArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Expression()));
  b.setVal38(es.EntityId(e.Parameter()));
  auto t39 = e.UsedToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  if (auto r39 = e.ParenthesisOrBraceRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal94(e.HadMultipleCandidates());
  b.setVal95(e.IsElidable());
  b.setVal96(e.IsListInitialization());
  b.setVal97(e.IsStdInitializerListInitialization());
  b.setVal98(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BlockDeclaration()));
  b.setVal38(es.EntityId(e.Body()));
  auto t39 = e.CaretToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal94(e.HasStoredFPFeatures());
  b.setVal95(e.IsAdditiveOperation());
  b.setVal96(e.IsAssignmentOperation());
  b.setVal97(e.IsBitwiseOperation());
  b.setVal98(e.IsCommaOperation());
  b.setVal100(e.IsComparisonOperation());
  b.setVal103(e.IsCompoundAssignmentOperation());
  b.setVal104(e.IsEqualityOperation());
  b.setVal105(e.IsLogicalOperation());
  b.setVal106(e.IsMultiplicativeOperation());
  b.setVal107(e.IsPointerMemoryOperation());
  b.setVal109(e.IsRelationalOperation());
  b.setVal110(e.IsShiftAssignOperation());
  b.setVal111(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
  b.setVal40(es.EntityId(e.ComputationLHSType()));
  b.setVal41(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal38(es.EntityId(e.Order()));
  auto v39 = e.OrderFail();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal94(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal40(es.EntityId(e.Pointer()));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.Scope();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal95(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v43 = e.Value1();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal96(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v44 = e.Value2();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal97(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal45(es.EntityId(e.ValueType()));
  auto v46 = e.Weak();
  if (v46) {
    auto id46 = es.EntityId(v46.value());    b.setVal46(id46);
    b.setVal98(id46 != mx::kInvalidEntityId);
  } else {
    b.setVal46(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal100(e.IsCmpXChg());
  b.setVal103(e.IsOpenCL());
  b.setVal104(e.IsVolatile());
  do {
    auto v16 = e.SubExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeAsTypeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.DimensionExpression()));
  b.setVal38(es.EntityId(e.QueriedType()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  b.setVal39(es.EntityId(e.LHS()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.CommonExpression()));
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AmpAmpToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Label()));
  auto t39 = e.LabelToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeAbstractConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.ColonToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Condition()));
  b.setVal39(es.EntityId(e.FalseExpression()));
  auto t40 = e.QuestionToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal42(es.EntityId(e.Common()));
  b.setVal43(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.WrittenType()));
  b.setVal94(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.CanOverflow());
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal95(e.HasStoredFPFeatures());
  b.setVal96(e.IsArithmeticOperation());
  b.setVal97(e.IsDecrementOperation());
  b.setVal98(e.IsIncrementDecrementOperation());
  b.setVal100(e.IsIncrementOperation());
  b.setVal103(e.IsPostfix());
  b.setVal104(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ArgumentExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v38 = e.ArgumentType();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.TypeOfArgument()));
  b.setVal96(e.IsArgumentType());
}

void SerializeTypoExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v94 = e.Value();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ParameterPack()));
  auto t38 = e.ParameterPackToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeSubstNonTypeTemplateParmExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.NameToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Parameter()));
  b.setVal39(es.EntityId(e.ParameterType()));
  b.setVal40(es.EntityId(e.Replacement()));
  b.setVal94(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  auto v94 = e.ContainsNonAscii();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto v96 = e.ContainsNonAsciiOrNull();
  if (v96) {
    b.setVal96(static_cast<bool>(v96.value()));
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
  auto v65 = e.Bytes();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto v70 = e.String();
  if (v70) {
    if (v70->empty()) {
      b.setVal70("");
    } else {
      std::string s70(v70->data(), v70->size());
      b.setVal70(s70);
    }
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal100(e.IsAscii());
  b.setVal103(e.IsPascal());
  b.setVal104(e.IsUTF16());
  b.setVal105(e.IsUTF32());
  b.setVal106(e.IsUTF8());
  b.setVal107(e.IsWide());
}

void SerializeStmtExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v65 = e.BuiltinString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.IsIntType());
  b.setVal95(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Pack()));
  auto v108 = e.PackLength();
  if (v108) {
    b.setVal108(static_cast<unsigned>(v108.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  auto t39 = e.PackToken();
  b.setVal39(es.EntityId(t39));
  do {
    auto ov101 = e.PartialArguments();
    if (!ov101) {
      b.setVal95(false);
      break;
    }
    b.setVal95(true);
    auto v101 = std::move(*ov101);
    auto sv101 = b.initVal101(static_cast<unsigned>(v101.size()));
    auto i101 = 0u;
    for (const auto &e101 : v101) {
      sv101.set(i101, es.PseudoId(e101));
      ++i101;
    }
  } while (false);
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal96(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeSYCLUniqueStableNameExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal65(e.ComputeName());
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeRequiresExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  do {
    auto v16 = e.LocalParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t38 = e.RBraceToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RequiresKeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal94(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.SubExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializePseudoObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ResultExpression()));
  b.setVal38(es.EntityId(e.SyntacticForm()));
  do {
    auto v16 = e.Semantics();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  do {
    auto v22 = e.SemanticExpressions();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
}

void SerializePredefinedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.FunctionName()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v65 = e.IdentifierKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeParenListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  do {
    auto v16 = e.Expressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeParenExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.EllipsisToken();
  b.setVal37(es.EntityId(t37));
  auto v108 = e.NumExpansions();
  if (v108) {
    b.setVal108(static_cast<unsigned>(v108.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal38(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.LAngleToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.NameToken();
  b.setVal38(es.EntityId(t38));
  auto v39 = e.NamingClass();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal94(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t40 = e.RAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.TemplateKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal42(es.EntityId(e.Base()));
  b.setVal43(es.EntityId(e.BaseType()));
  auto t44 = e.MemberToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  b.setVal97(e.HasUnresolvedUsing());
  b.setVal98(e.IsArrow());
  b.setVal100(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal97(e.IsOverloaded());
  b.setVal98(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal94(e.IsUnique());
}

void SerializeOffsetOfExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeObjCSubscriptRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.KeyExpression()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal94(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AtToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AtToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeObjCProtocolExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AtToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Protocol()));
  auto t39 = e.ProtocolIdToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ExplicitProperty()));
  b.setVal40(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal41(es.EntityId(e.ImplicitPropertySetter()));
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.ReceiverToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.ReceiverType()));
  b.setVal45(es.EntityId(e.SuperReceiverType()));
  b.setVal94(e.IsClassReceiver());
  b.setVal95(e.IsExplicitProperty());
  b.setVal96(e.IsImplicitProperty());
  b.setVal97(e.IsMessagingGetter());
  b.setVal98(e.IsMessagingSetter());
  b.setVal100(e.IsObjectReceiver());
  b.setVal103(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ClassReceiverType()));
  b.setVal40(es.EntityId(e.InstanceReceiver()));
  auto t41 = e.LeftToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.MethodDeclaration()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal43(es.EntityId(e.ReceiverInterface()));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r44 = e.ReceiverRange(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal46(es.EntityId(e.ReceiverType()));
  auto t47 = e.RightToken();
  b.setVal47(es.EntityId(t47));
  auto t48 = e.SelectorStartToken();
  b.setVal48(es.EntityId(t48));
  auto t49 = e.SuperToken();
  b.setVal49(es.EntityId(t49));
  b.setVal50(es.EntityId(e.SuperType()));
  b.setVal94(e.IsClassMessage());
  b.setVal95(e.IsDelegateInitializerCall());
  b.setVal96(e.IsImplicit());
  b.setVal97(e.IsInstanceMessage());
  do {
    auto v22 = e.SelectorTokens();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Declaration()));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.OperationToken();
  b.setVal40(es.EntityId(t40));
  b.setVal94(e.IsArrow());
  b.setVal95(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto t38 = e.BaseTokenEnd();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.IsaMemberToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.OperationToken();
  b.setVal40(es.EntityId(t40));
  b.setVal94(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal94(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AtToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.EncodedType()));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCDictionaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.AtToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.BoxingMethod()));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal94(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ArrayWithObjectsMethod()));
  do {
    auto v16 = e.Elements();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeOMPIteratorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.IteratorKwToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeOMPArrayShapingExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  do {
    auto v16 = e.Dimensions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeOMPArraySectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto t38 = e.FirstColonToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.SecondColonToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Length()));
  b.setVal41(es.EntityId(e.LowerBound()));
  auto t42 = e.RBracketToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.MemberDeclaration()));
  auto t40 = e.MemberToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal94(e.HadMultipleCandidates());
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasQualifier());
  b.setVal97(e.HasTemplateKeyword());
  b.setVal98(e.IsArrow());
  b.setVal100(e.IsImplicitAccess());
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  auto t39 = e.RBracketToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal94(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExtendingDeclaration();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v38 = e.LifetimeExtendedTemporaryDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal96(e.IsBoundToLvalueReference());
  b.setVal97(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  auto t39 = e.RBracketToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeMSPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.BaseExpression()));
  auto t38 = e.MemberToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.PropertyDeclaration()));
  b.setVal94(e.IsArrow());
  b.setVal95(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t39 = e.CaptureDefaultToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v16 = e.ExplicitTemplateParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
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
  auto v108 = e.TemplateParameterList();
  if (v108) {
    b.setVal108(es.PseudoId(v108.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  auto v44 = e.TrailingRequiresClause();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal95(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal96(e.HasExplicitParameters());
  b.setVal97(e.HasExplicitResultType());
  b.setVal98(e.IsGenericLambda());
  b.setVal100(e.IsMutable());
}

void SerializeIntegerLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeInitListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ArrayFiller();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v38 = e.InitializedFieldInUnion();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t39 = e.LBraceToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RBraceToken();
  b.setVal40(es.EntityId(t40));
  auto v41 = e.SemanticForm();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal96(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v42 = e.SyntacticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal97(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal98(e.HadArrayRangeDesignator());
  b.setVal100(e.HasArrayFiller());
  do {
    auto v16 = e.Initializers();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal103(e.IsExplicit());
  b.setVal104(e.IsSemanticForm());
  b.setVal105(e.IsStringLiteralInitializer());
  b.setVal106(e.IsSyntacticForm());
  auto v107 = e.IsTransparent();
  if (v107) {
    b.setVal107(static_cast<bool>(v107.value()));
    b.setVal109(true);
  } else {
    b.setVal109(false);
  }
}

void SerializeImplicitValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v16 = e.AssociationExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal37(es.EntityId(e.ControllingExpression()));
  auto t38 = e.DefaultToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.GenericToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.ResultExpression()));
  b.setVal94(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.TokenToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeFunctionParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.ParameterPack()));
  auto t38 = e.ParameterPackToken();
  b.setVal38(es.EntityId(t38));
  do {
    auto v16 = e.Expansions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeFullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal94(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal94(e.HasAPValueResult());
  b.setVal95(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal94(e.ContainsDuplicateElements());
  auto t37 = e.AccessorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Base()));
  b.setVal95(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal94(e.Value());
}

void SerializeAttributedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  auto t10 = e.AttributeToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal15(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v14 = e.Initializer();
  if (v14) {
    auto id14 = es.EntityId(v14.value());    b.setVal14(id14);
    b.setVal20(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t17 = e.LParenToken();
  b.setVal17(es.EntityId(t17));
  auto t18 = e.RParenToken();
  b.setVal18(es.EntityId(t18));
  auto v19 = e.FirstSwitchCase();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal21(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  auto t26 = e.SwitchToken();
  b.setVal26(es.EntityId(t26));
  b.setVal57(e.HasInitializerStorage());
  b.setVal58(e.HasVariableStorage());
  b.setVal59(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.ColonToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.KeywordToken();
  b.setVal10(es.EntityId(t10));
  auto v11 = e.NextSwitchCase();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal13(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  auto t14 = e.DefaultToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeCaseStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal15(e.CaseStatementIsGNURange());
  auto t14 = e.CaseToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.EllipsisToken();
  b.setVal17(es.EntityId(t17));
  b.setVal18(es.EntityId(e.LHS()));
  auto v19 = e.RHS();
  if (v19) {
    auto id19 = es.EntityId(v19.value());    b.setVal19(id19);
    b.setVal20(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal20(false);
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
  auto v5 = e.DescribedTemplateParameters();
  if (v5) {
    b.setVal5(es.PseudoId(v5.value()));
    b.setVal6(true);
  } else {
    b.setVal6(false);
  }
  b.setVal7(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v8 = e.FunctionType();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal9(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal9(false);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v11 = e.NonClosureContext();
  if (v11) {
    auto id11 = es.EntityId(v11.value());    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal13(e.HasAttributes());
  b.setVal14(e.HasDefiningAttribute());
  b.setVal15(e.HasOwningModule());
  b.setVal16(e.HasTagIdentifierNamespace());
  b.setVal17(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal18(e.IsDeprecated());
  b.setVal19(e.IsFunctionOrFunctionTemplate());
  b.setVal20(e.IsImplicit());
  b.setVal21(e.IsInAnonymousNamespace());
  b.setVal22(e.IsInExportDeclarationContext());
  b.setVal23(e.IsInLocalScopeForInstantiation());
  b.setVal24(e.IsInStdNamespace());
  b.setVal25(e.IsInvalidDeclaration());
  b.setVal26(e.IsModulePrivate());
  b.setVal27(e.IsOutOfLine());
  b.setVal28(e.IsParameterPack());
  b.setVal29(e.IsTemplateDeclaration());
  b.setVal30(e.IsTemplateParameter());
  b.setVal31(e.IsTemplateParameterPack());
  b.setVal32(e.IsTemplated());
  b.setVal33(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal34(e.IsUnavailable());
  b.setVal35(e.IsUnconditionallyVisible());
  b.setVal36(e.IsWeakImported());
  do {
    auto v37 = e.Redeclarations();
    auto sv37 = b.initVal37(static_cast<unsigned>(v37.size()));
    auto i37 = 0u;
    for (const auto &e37 : v37) {
      sv37.set(i37, es.EntityId(e37));
      ++i37;
    }
  } while (false);
  b.setVal38(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal39(static_cast<unsigned char>(mx::FromPasta(e.Category())));
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
  auto v71 = e.DefaultArgument();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal75(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  auto t74 = e.DefaultArgumentToken();
  b.setVal74(es.EntityId(t74));
  auto v143 = e.NumExpansionTypes();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal77(true);
  } else {
    b.setVal77(false);
  }
  auto v76 = e.PlaceholderTypeConstraint();
  if (v76) {
    auto id76 = es.EntityId(v76.value());    b.setVal76(id76);
    b.setVal79(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal79(false);
  }
  b.setVal87(e.HasDefaultArgument());
  b.setVal90(e.HasPlaceholderTypeConstraint());
  b.setVal91(e.IsExpandedParameterPack());
  b.setVal92(e.IsPackExpansion());
  do {
    auto v45 = e.ExpansionTypes();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
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
  b.setVal70(e.UsesFPIntrin());
  auto v75 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v75) {
    b.setVal75(static_cast<bool>(v75.value()));
    b.setVal77(true);
  } else {
    b.setVal77(false);
  }
  b.setVal79(e.DoesThisDeclarationHaveABody());
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
    b.setVal87(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal87(false);
  }
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v143 = e.ODRHash();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
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
    b.setVal91(id145 != mx::kInvalidEntityId);
  } else {
    b.setVal145(mx::kInvalidEntityId);
    b.setVal91(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal125(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal92(e.HasImplicitReturnZero());
  b.setVal93(e.HasInheritedPrototype());
  b.setVal94(e.HasOneParameterOrDefaultArguments());
  b.setVal95(e.HasPrototype());
  b.setVal96(e.HasSkippedBody());
  b.setVal97(e.HasTrivialBody());
  b.setVal98(e.HasWrittenPrototype());
  b.setVal99(e.InstantiationIsPending());
  b.setVal100(e.IsCPUDispatchMultiVersion());
  b.setVal101(e.IsCPUSpecificMultiVersion());
  b.setVal102(e.IsConsteval());
  b.setVal103(e.IsConstexpr());
  b.setVal104(e.IsConstexprSpecified());
  b.setVal105(e.IsDefaulted());
  b.setVal106(e.IsDeleted());
  b.setVal107(e.IsDeletedAsWritten());
  b.setVal108(e.IsDestroyingOperatorDelete());
  b.setVal109(e.IsExplicitlyDefaulted());
  b.setVal110(e.IsExternC());
  b.setVal111(e.IsFunctionTemplateSpecialization());
  b.setVal112(e.IsGlobal());
  b.setVal113(e.IsImplicitlyInstantiable());
  b.setVal114(e.IsInExternCContext());
  b.setVal115(e.IsInExternCXXContext());
  b.setVal116(e.IsInlineBuiltinDeclaration());
  auto v117 = e.IsInlineDefinitionExternallyVisible();
  if (v117) {
    b.setVal117(static_cast<bool>(v117.value()));
    b.setVal118(true);
  } else {
    b.setVal118(false);
  }
  b.setVal119(e.IsInlineSpecified());
  b.setVal120(e.IsInlined());
  b.setVal121(e.IsLateTemplateParsed());
  auto v122 = e.IsMSExternInline();
  if (v122) {
    b.setVal122(static_cast<bool>(v122.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  b.setVal124(e.IsMSVCRTEntryPoint());
  b.setVal127(e.IsMain());
  b.setVal133(e.IsMultiVersion());
  b.setVal134(e.IsNoReturn());
  b.setVal135(e.IsOverloadedOperator());
  b.setVal136(e.IsPure());
  b.setVal137(e.IsReplaceableGlobalAllocationFunction());
  auto v138 = e.IsReservedGlobalPlacementOperator();
  if (v138) {
    b.setVal138(static_cast<bool>(v138.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  b.setVal140(e.IsStatic());
  b.setVal146(e.IsTargetClonesMultiVersion());
  b.setVal147(e.IsTargetMultiVersion());
  b.setVal148(e.IsTemplateInstantiation());
  b.setVal149(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal150(e.IsTrivial());
  b.setVal151(e.IsTrivialForCall());
  b.setVal152(e.IsUserProvided());
  b.setVal153(e.IsVariadic());
  b.setVal154(e.IsVirtualAsWritten());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal155(e.UsesSEHTry());
  b.setVal156(e.WillHaveBody());
  auto v157 = e.Body();
  if (v157) {
    auto id157 = es.EntityId(v157.value());    b.setVal157(id157);
    b.setVal158(id157 != mx::kInvalidEntityId);
  } else {
    b.setVal157(mx::kInvalidEntityId);
    b.setVal158(false);
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
  auto v159 = e.ThisObjectType();
  if (v159) {
    auto id159 = es.EntityId(v159.value());    b.setVal159(id159);
    b.setVal160(id159 != mx::kInvalidEntityId);
  } else {
    b.setVal159(mx::kInvalidEntityId);
    b.setVal160(false);
  }
  auto v161 = e.ThisType();
  if (v161) {
    auto id161 = es.EntityId(v161.value());    b.setVal161(id161);
    b.setVal162(id161 != mx::kInvalidEntityId);
  } else {
    b.setVal161(mx::kInvalidEntityId);
    b.setVal162(false);
  }
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
  do {
    auto v171 = e.ParameterDeclarations();
    auto sv171 = b.initVal171(static_cast<unsigned>(v171.size()));
    auto i171 = 0u;
    for (const auto &e171 : v171) {
      sv171.set(i171, es.EntityId(e171));
      ++i171;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v172 = e.OperatorDelete();
  if (v172) {
    auto id172 = es.EntityId(v172.value());    b.setVal172(id172);
    b.setVal173(id172 != mx::kInvalidEntityId);
  } else {
    b.setVal172(mx::kInvalidEntityId);
    b.setVal173(false);
  }
  auto v174 = e.OperatorDeleteThisArgument();
  if (v174) {
    auto id174 = es.EntityId(v174.value());    b.setVal174(id174);
    b.setVal175(id174 != mx::kInvalidEntityId);
  } else {
    b.setVal174(mx::kInvalidEntityId);
    b.setVal175(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal172(es.EntityId(e.ConversionType()));
  b.setVal173(e.IsExplicit());
  b.setVal175(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v172 = e.TargetConstructor();
  if (v172) {
    auto id172 = es.EntityId(v172.value());    b.setVal172(id172);
    b.setVal173(id172 != mx::kInvalidEntityId);
  } else {
    b.setVal172(mx::kInvalidEntityId);
    b.setVal173(false);
  }
  b.setVal175(e.IsDefaultConstructor());
  b.setVal176(e.IsDelegatingConstructor());
  b.setVal177(e.IsExplicit());
  b.setVal178(e.IsInheritingConstructor());
  b.setVal179(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal159(es.EntityId(e.CorrespondingConstructor()));
  b.setVal160(e.IsCopyDeductionCandidate());
  b.setVal162(e.IsExplicit());
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
  auto v52 = e.DefaultArgument();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal70(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v53 = e.DefaultArgumentInfo();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal75(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  auto t61 = e.DefaultArgumentToken();
  b.setVal61(es.EntityId(t61));
  b.setVal77(e.HasDefaultArgument());
  b.setVal79(e.HasTypeConstraint());
  b.setVal87(e.IsExpandedParameterPack());
  b.setVal90(e.IsPackExpansion());
  b.setVal91(e.WasDeclaredWithTypename());
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
  b.setVal96(e.IsUnion());
  b.setVal97(e.MayHaveOutOfDateDefinition());
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
  b.setVal98(e.CanPassInRegisters());
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
  b.setVal99(e.HasFlexibleArrayMember());
  b.setVal100(e.HasLoadedFieldsFromExternalStorage());
  b.setVal101(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal102(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal103(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal104(e.HasObjectMember());
  b.setVal105(e.HasVolatileMember());
  b.setVal106(e.IsAnonymousStructOrUnion());
  b.setVal107(e.IsCapturedRecord());
  b.setVal108(e.IsInjectedClassName());
  b.setVal109(e.IsLambda());
  b.setVal110(e.IsMsStruct());
  b.setVal111(e.IsNonTrivialToPrimitiveCopy());
  b.setVal112(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal113(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal114(e.IsOrContainsUnion());
  b.setVal115(e.IsParameterDestroyedInCallee());
  b.setVal116(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v117 = e.AllowConstDefaultInitializer();
  if (v117) {
    b.setVal117(static_cast<bool>(v117.value()));
    b.setVal118(true);
  } else {
    b.setVal118(false);
  }
  do {
    auto ov141 = e.Bases();
    if (!ov141) {
      b.setVal119(false);
      break;
    }
    b.setVal119(true);
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
    b.setVal120(true);
  } else {
    b.setVal120(false);
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
    auto ov171 = e.Friends();
    if (!ov171) {
      b.setVal121(false);
      break;
    }
    b.setVal121(true);
    auto v171 = std::move(*ov171);
    auto sv171 = b.initVal171(static_cast<unsigned>(v171.size()));
    auto i171 = 0u;
    for (const auto &e171 : v171) {
      sv171.set(i171, es.EntityId(e171));
      ++i171;
    }
  } while (false);
  auto v71 = e.Destructor();
  if (v71) {
    auto id71 = es.EntityId(v71.value());    b.setVal71(id71);
    b.setVal122(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal122(false);
  }
  auto v143 = e.GenericLambdaTemplateParameterList();
  if (v143) {
    b.setVal143(es.PseudoId(v143.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  auto v74 = e.InstantiatedFromMemberClass();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal124(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal124(false);
  }
  auto v76 = e.LambdaCallOperator();
  if (v76) {
    auto id76 = es.EntityId(v76.value());    b.setVal76(id76);
    b.setVal127(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal127(false);
  }
  auto v83 = e.LambdaCaptureDefault();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  auto v78 = e.LambdaContextDeclaration();
  if (v78) {
    auto id78 = es.EntityId(v78.value());    b.setVal78(id78);
    b.setVal134(id78 != mx::kInvalidEntityId);
  } else {
    b.setVal78(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  do {
    auto ov180 = e.LambdaExplicitTemplateParameters();
    if (!ov180) {
      b.setVal135(false);
      break;
    }
    b.setVal135(true);
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
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v81 = e.LambdaType();
  if (v81) {
    auto id81 = es.EntityId(v81.value());    b.setVal81(id81);
    b.setVal137(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal137(false);
  }
  auto v84 = e.MSInheritanceModel();
  if (v84) {
    b.setVal84(static_cast<unsigned char>(v84.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v182 = e.NumBases();
  if (v182) {
    b.setVal182(static_cast<unsigned>(v182.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  auto v183 = e.NumVirtualBases();
  if (v183) {
    b.setVal183(static_cast<unsigned>(v183.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  auto v184 = e.ODRHash();
  if (v184) {
    b.setVal184(static_cast<unsigned>(v184.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v86 = e.TemplateInstantiationPattern();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal147(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal147(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v148 = e.HasAnyDependentBases();
  if (v148) {
    b.setVal148(static_cast<bool>(v148.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v150 = e.HasConstexprDefaultConstructor();
  if (v150) {
    b.setVal150(static_cast<bool>(v150.value()));
    b.setVal151(true);
  } else {
    b.setVal151(false);
  }
  auto v152 = e.HasConstexprDestructor();
  if (v152) {
    b.setVal152(static_cast<bool>(v152.value()));
    b.setVal153(true);
  } else {
    b.setVal153(false);
  }
  auto v154 = e.HasConstexprNonCopyMoveConstructor();
  if (v154) {
    b.setVal154(static_cast<bool>(v154.value()));
    b.setVal155(true);
  } else {
    b.setVal155(false);
  }
  auto v156 = e.HasCopyAssignmentWithConstParameter();
  if (v156) {
    b.setVal156(static_cast<bool>(v156.value()));
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  auto v160 = e.HasCopyConstructorWithConstParameter();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v163 = e.HasDefaultConstructor();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasDefinition();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasDirectFields();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasFriends();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v173 = e.HasInClassInitializer();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v176 = e.HasInheritedAssignment();
  if (v176) {
    b.setVal176(static_cast<bool>(v176.value()));
    b.setVal177(true);
  } else {
    b.setVal177(false);
  }
  auto v178 = e.HasInheritedConstructor();
  if (v178) {
    b.setVal178(static_cast<bool>(v178.value()));
    b.setVal179(true);
  } else {
    b.setVal179(false);
  }
  auto v185 = e.HasInitializerMethod();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v187 = e.HasIrrelevantDestructor();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasKnownLambdaInternalLinkage();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v191 = e.HasMoveAssignment();
  if (v191) {
    b.setVal191(static_cast<bool>(v191.value()));
    b.setVal192(true);
  } else {
    b.setVal192(false);
  }
  auto v193 = e.HasMoveConstructor();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasMutableFields();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasNonLiteralTypeFieldsOrBases();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasNonTrivialCopyAssignment();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasNonTrivialCopyConstructor();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasNonTrivialCopyConstructorForCall();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonTrivialDefaultConstructor();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialDestructor();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialDestructorForCall();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialMoveAssignment();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialMoveConstructor();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialMoveConstructorForCall();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasPrivateFields();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasProtectedFields();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasSimpleCopyAssignment();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasSimpleCopyConstructor();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasSimpleDestructor();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasSimpleMoveAssignment();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasSimpleMoveConstructor();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasTrivialCopyAssignment();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasTrivialCopyConstructor();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasTrivialCopyConstructorForCall();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasTrivialDefaultConstructor();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialDestructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialDestructorForCall();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialMoveAssignment();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialMoveConstructor();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialMoveConstructorForCall();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasUninitializedReferenceMember();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasUserDeclaredConstructor();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasUserDeclaredCopyAssignment();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasUserDeclaredCopyConstructor();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUserDeclaredDestructor();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredMoveAssignment();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredMoveConstructor();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredMoveOperation();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserProvidedDefaultConstructor();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasVariantMembers();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.ImplicitCopyConstructorHasConstParameter();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.IsAbstract();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.IsAggregate();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.IsAnyDestructorNoReturn();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.IsCLike();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsCXX11StandardLayout();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  b.setVal283(e.IsDependentLambda());
  auto v284 = e.IsDynamicClass();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  auto v286 = e.IsEffectivelyFinal();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v288 = e.IsEmpty();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  b.setVal290(e.IsGenericLambda());
  auto v291 = e.IsInterfaceLike();
  if (v291) {
    b.setVal291(static_cast<bool>(v291.value()));
    b.setVal292(true);
  } else {
    b.setVal292(false);
  }
  auto v293 = e.IsLiteral();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v126 = e.IsLocalClass();
  if (v126) {
    auto id126 = es.EntityId(v126.value());    b.setVal126(id126);
    b.setVal295(id126 != mx::kInvalidEntityId);
  } else {
    b.setVal126(mx::kInvalidEntityId);
    b.setVal295(false);
  }
  auto v296 = e.IsPOD();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  auto v298 = e.IsPolymorphic();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v300 = e.IsStandardLayout();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsStructural();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsTrivial();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.IsTriviallyCopyable();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.MayBeAbstract();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.MayBeDynamicClass();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.MayBeNonDynamicClass();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  do {
    auto ov316 = e.Methods();
    if (!ov316) {
      b.setVal317(false);
      break;
    }
    b.setVal317(true);
    auto v316 = std::move(*ov316);
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  auto v318 = e.NeedsImplicitCopyAssignment();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.NeedsImplicitCopyConstructor();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.NeedsImplicitDefaultConstructor();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.NeedsImplicitDestructor();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsImplicitMoveAssignment();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NeedsImplicitMoveConstructor();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsOverloadResolutionForDestructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NullFieldOffsetIsZero();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  do {
    auto ov142 = e.VirtualBases();
    if (!ov142) {
      b.setVal342(false);
      break;
    }
    b.setVal342(true);
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
    auto v343 = e.TemplateArguments();
    auto sv343 = b.initVal343(static_cast<unsigned>(v343.size()));
    auto i343 = 0u;
    for (const auto &e343 : v343) {
      sv343.set(i343, es.PseudoId(e343));
      ++i343;
    }
  } while (false);
  do {
    auto v344 = e.TemplateInstantiationArguments();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.PseudoId(e344));
      ++i344;
    }
  } while (false);
  auto t131 = e.TemplateKeywordToken();
  b.setVal131(es.EntityId(t131));
  auto v132 = e.TypeAsWritten();
  if (v132) {
    auto id132 = es.EntityId(v132.value());    b.setVal132(id132);
    b.setVal345(id132 != mx::kInvalidEntityId);
  } else {
    b.setVal132(mx::kInvalidEntityId);
    b.setVal345(false);
  }
  b.setVal346(e.IsClassScopeExplicitSpecialization());
  b.setVal347(e.IsExplicitInstantiationOrSpecialization());
  b.setVal348(e.IsExplicitSpecialization());
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
    b.setVal98(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v74 = e.IntegerType();
  if (v74) {
    auto id74 = es.EntityId(v74.value());    b.setVal74(id74);
    b.setVal99(id74 != mx::kInvalidEntityId);
  } else {
    b.setVal74(mx::kInvalidEntityId);
    b.setVal99(false);
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
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  b.setVal81(es.EntityId(e.PromotionType()));
  auto v86 = e.TemplateInstantiationPattern();
  if (v86) {
    auto id86 = es.EntityId(v86.value());    b.setVal86(id86);
    b.setVal101(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal102(e.IsClosed());
  b.setVal103(e.IsClosedFlag());
  b.setVal104(e.IsClosedNonFlag());
  b.setVal105(e.IsComplete());
  b.setVal106(e.IsFixed());
  b.setVal107(e.IsScoped());
  b.setVal108(e.IsScopedUsingClassTag());
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
  b.setVal53(es.EntityId(e.UnderlyingType()));
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
  auto v61 = e.DescribedAliasTemplate();
  if (v61) {
    auto id61 = es.EntityId(v61.value());    b.setVal61(id61);
    b.setVal77(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal77(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t61 = e.ColonToken();
  b.setVal61(es.EntityId(t61));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t62 = e.VarianceToken();
  b.setVal62(es.EntityId(t62));
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
  auto v51 = e.InstantiatedFromMemberTemplate();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal68(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal68(false);
  }
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
  b.setVal52(es.EntityId(e.ClassInterface()));
  b.setVal53(es.EntityId(e.CommandDeclaration()));
  auto t61 = e.DeclaratorEndToken();
  b.setVal61(es.EntityId(t61));
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal62(es.EntityId(e.ReturnType()));
  if (auto r63 = e.ReturnTypeSourceRange(); auto rs63 = r63.Size()) {
    b.setVal63(es.EntityId(r63[0]));
    b.setVal71(es.EntityId(r63[rs63 - 1u]));
  } else {
    b.setVal63(0);
    b.setVal71(0);
  }
  auto t74 = e.SelectorStartToken();
  b.setVal74(es.EntityId(t74));
  b.setVal76(es.EntityId(e.SelfDeclaration()));
  b.setVal69(e.HasParameterDestroyedInCallee());
  b.setVal70(e.HasRedeclaration());
  b.setVal75(e.HasRelatedResultType());
  b.setVal77(e.HasSkippedBody());
  b.setVal79(e.IsClassMethod());
  b.setVal87(e.IsDefined());
  b.setVal90(e.IsDesignatedInitializerForTheInterface());
  b.setVal91(e.IsDirectMethod());
  b.setVal92(e.IsInstanceMethod());
  b.setVal93(e.IsOptional());
  b.setVal94(e.IsOverriding());
  b.setVal95(e.IsPropertyAccessor());
  b.setVal96(e.IsRedeclaration());
  b.setVal97(e.IsSynthesizedAccessorStub());
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
    auto v171 = e.InstanceProperties();
    auto sv171 = b.initVal171(static_cast<unsigned>(v171.size()));
    auto i171 = 0u;
    for (const auto &e171 : v171) {
      sv171.set(i171, es.EntityId(e171));
      ++i171;
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
    auto v316 = e.Properties();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  pasta::DeclContext dc349(e);
  auto v349 = dc349.AlreadyLoadedDeclarations();
  auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
  auto i349 = 0u;
  for (const pasta::Decl &e349 : v349) {
    sv349.set(i349, es.EntityId(e349));
    ++i349;
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
    auto v350 = e.InstanceVariables();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
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
  do {
    auto v350 = e.ProtocolTokens();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
  do {
    auto v351 = e.Protocols();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v350 = e.AllReferencedProtocols();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
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
    auto v352 = e.KnownCategories();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.KnownExtensions();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.EntityId(e353));
      ++i353;
    }
  } while (false);
  do {
    auto v354 = e.ProtocolTokens();
    auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
    auto i354 = 0u;
    for (const auto &e354 : v354) {
      sv354.set(i354, es.EntityId(e354));
      ++i354;
    }
  } while (false);
  do {
    auto v355 = e.Protocols();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
  do {
    auto v356 = e.VisibleCategories();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
  do {
    auto v357 = e.VisibleExtensions();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
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
    auto v350 = e.PropertyImplementations();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
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
    auto v351 = e.InstanceVariables();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
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
  auto v52 = e.FriendType();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal47(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal47(false);
  }
  b.setVal48(e.IsUnsupportedFriend());
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
