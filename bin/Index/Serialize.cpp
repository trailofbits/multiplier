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
  if (auto r4 = e.Tokens(); auto rs4 = r4.Size()) {
    b.setVal4(es.EntityId(r4[0]));
    b.setVal5(es.EntityId(r4[rs4 - 1u]));
  } else {
    b.setVal4(0);
    b.setVal5(0);
  }
  b.setVal6(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal7(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ExceptHandler()));
  b.setVal9(es.EntityId(e.FinallyHandler()));
  b.setVal10(es.EntityId(e.Handler()));
  b.setVal11(e.IsCXXTry());
  b.setVal12(es.EntityId(e.TryBlock()));
  auto t13 = e.TryToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeSEHLeaveStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.LeaveToken();
  b.setVal8(es.EntityId(t8));
}

void SerializeSEHFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Block()));
  auto t9 = e.FinallyToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeSEHExceptStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Block()));
  auto t9 = e.ExceptToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
  SerializeStmt(es, b, e);
  auto v8 = e.NRVOCandidate();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal11(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto v9 = e.ReturnValue();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal14(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto t10 = e.ReturnToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeObjCForCollectionStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Collection()));
  b.setVal10(es.EntityId(e.Element()));
  auto t12 = e.ForToken();
  b.setVal12(es.EntityId(t12));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeObjCAutoreleasePoolStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.AtToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.AtTryToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.FinallyStatement()));
  b.setVal10(es.EntityId(e.TryBody()));
  do {
    auto v15 = e.CatchStatements();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeObjCAtThrowStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.ThrowExpression()));
  auto t9 = e.ThrowToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeObjCAtSynchronizedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.AtSynchronizedToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.SynchBody()));
  b.setVal10(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.AtFinallyToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.AtCatchToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.CatchBody()));
  b.setVal10(es.EntityId(e.CatchParameterDeclaration()));
  auto t12 = e.RParenToken();
  b.setVal12(es.EntityId(t12));
  b.setVal11(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.AssociatedStatement()));
  b.setVal9(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal10(es.EntityId(e.RawStatement()));
  b.setVal12(es.EntityId(e.StructuredBlock()));
  b.setVal11(e.HasAssociatedStatement());
  b.setVal14(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  auto t13 = e.TargetCallToken();
  b.setVal13(es.EntityId(t13));
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
  b.setVal13(es.EntityId(e.Expression()));
  b.setVal16(es.EntityId(e.UpdateExpression()));
  b.setVal17(es.EntityId(e.V()));
  b.setVal18(es.EntityId(e.X()));
  b.setVal19(e.IsPostfixUpdate());
  b.setVal20(e.IsXLHSInRHSPart());
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
  b.setVal13(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPSectionDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPScanDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPOrderedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMetaDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal13(es.EntityId(e.IfStatement()));
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
  b.setVal13(es.EntityId(e.PreInitializers()));
  b.setVal16(es.EntityId(e.TransformedStatement()));
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
    auto v15 = e.Counters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  do {
    auto v21 = e.DependentCounters();
    auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
    auto i21 = 0u;
    for (const auto &e21 : v21) {
      sv21.set(i21, es.EntityId(e21));
      ++i21;
    }
  } while (false);
  do {
    auto v22 = e.DependentInitializers();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
  do {
    auto v23 = e.Finals();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
  do {
    auto v24 = e.FinalsConditions();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
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
  do {
    auto v51 = e.Initializers();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  do {
    auto v52 = e.PrivateCounters();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v53 = e.Updates();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
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
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
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
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal54(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal19(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal19(e.HasCancel());
}

void SerializeOMPInteropDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.DistanceFunc()));
  b.setVal9(es.EntityId(e.LoopStatement()));
  b.setVal10(es.EntityId(e.LoopVariableFunc()));
  b.setVal12(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.SemiToken();
  b.setVal8(es.EntityId(t8));
  b.setVal11(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.KeywordToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.SubStatement()));
  b.setVal11(e.IsIfExists());
  b.setVal14(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  auto v8 = e.ConstantTarget();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal11(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto t9 = e.GotoToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.StarToken();
  b.setVal10(es.EntityId(t10));
  b.setVal12(es.EntityId(e.Target()));
}

void SerializeIfStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Condition()));
  auto v9 = e.ConditionVariable();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal11(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto v10 = e.ConditionVariableDeclarationStatement();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal14(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto v12 = e.Else();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal19(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal19(false);
  }
  auto t13 = e.ElseToken();
  b.setVal13(es.EntityId(t13));
  auto t16 = e.IfToken();
  b.setVal16(es.EntityId(t16));
  auto v17 = e.Initializer();
  if (v17) {
    auto id17 = es.EntityId(v17.value());    b.setVal17(id17);
    b.setVal20(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t18 = e.LParenToken();
  b.setVal18(es.EntityId(t18));
  auto t25 = e.RParenToken();
  b.setVal25(es.EntityId(t25));
  b.setVal55(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal26(es.EntityId(e.Then()));
  b.setVal56(e.HasElseStorage());
  b.setVal57(e.HasInitializerStorage());
  b.setVal58(e.HasVariableStorage());
  b.setVal59(e.IsConsteval());
  b.setVal60(e.IsConstexpr());
  b.setVal61(e.IsNegatedConsteval());
  b.setVal62(e.IsNonNegatedConsteval());
  b.setVal63(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.GotoToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.Label()));
  auto t10 = e.LabelToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeForStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  auto v9 = e.Condition();
  if (v9) {
    auto id9 = es.EntityId(v9.value());    b.setVal9(id9);
    b.setVal11(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto v10 = e.ConditionVariable();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal14(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal19(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal19(false);
  }
  auto t13 = e.ForToken();
  b.setVal13(es.EntityId(t13));
  auto v16 = e.Increment();
  if (v16) {
    auto id16 = es.EntityId(v16.value());    b.setVal16(id16);
    b.setVal20(id16 != mx::kInvalidEntityId);
  } else {
    b.setVal16(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto v17 = e.Initializer();
  if (v17) {
    auto id17 = es.EntityId(v17.value());    b.setVal17(id17);
    b.setVal56(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal56(false);
  }
  auto t18 = e.LParenToken();
  b.setVal18(es.EntityId(t18));
  auto t25 = e.RParenToken();
  b.setVal25(es.EntityId(t25));
}

void SerializeDoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  auto t10 = e.DoToken();
  b.setVal10(es.EntityId(t10));
  auto t12 = e.RParenToken();
  b.setVal12(es.EntityId(t12));
  auto t13 = e.WhileToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeDeclStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
  SerializeStmt(es, b, e);
  do {
    auto v15 = e.Declarations();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto v8 = e.SingleDeclaration();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal11(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal14(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Allocate()));
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Deallocate()));
  b.setVal12(es.EntityId(e.ExceptionHandler()));
  b.setVal13(es.EntityId(e.FallthroughHandler()));
  b.setVal16(es.EntityId(e.FinalSuspendStatement()));
  b.setVal17(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v15 = e.ParameterMoves();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal18(es.EntityId(e.PromiseDeclaration()));
  b.setVal25(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal26(es.EntityId(e.ResultDeclaration()));
  b.setVal27(es.EntityId(e.ReturnStatement()));
  b.setVal28(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal29(es.EntityId(e.ReturnValueInitializer()));
  b.setVal11(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.KeywordToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.Operand()));
  b.setVal10(es.EntityId(e.PromiseCall()));
  b.setVal11(e.IsImplicit());
}

void SerializeContinueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.ContinueToken();
  b.setVal8(es.EntityId(t8));
}

void SerializeCompoundStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.LeftBraceToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.RightBraceToken();
  b.setVal9(es.EntityId(t9));
  auto v10 = e.StatementExpressionResult();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
}

void SerializeCapturedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.CapturedDeclaration()));
  b.setVal9(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal55(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal10(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.TryBlock()));
  auto t9 = e.TryToken();
  b.setVal9(es.EntityId(t9));
  do {
    auto v15 = e.Handlers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeCXXForRangeStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.BeginStatement()));
  b.setVal9(es.EntityId(e.Body()));
  auto t10 = e.CoawaitToken();
  b.setVal10(es.EntityId(t10));
  auto t12 = e.ColonToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.Condition()));
  b.setVal16(es.EntityId(e.EndStatement()));
  auto t17 = e.ForToken();
  b.setVal17(es.EntityId(t17));
  b.setVal18(es.EntityId(e.Increment()));
  auto v25 = e.Initializer();
  if (v25) {
    auto id25 = es.EntityId(v25.value());    b.setVal25(id25);
    b.setVal11(id25 != mx::kInvalidEntityId);
  } else {
    b.setVal25(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal26(es.EntityId(e.LoopVariableStatement()));
  b.setVal27(es.EntityId(e.LoopVariable()));
  auto t28 = e.RParenToken();
  b.setVal28(es.EntityId(t28));
  b.setVal29(es.EntityId(e.RangeInitializer()));
  b.setVal30(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.CatchToken();
  b.setVal8(es.EntityId(t8));
  b.setVal9(es.EntityId(e.CaughtType()));
  auto v10 = e.ExceptionDeclaration();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal12(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.BreakToken();
  b.setVal8(es.EntityId(t8));
}

void SerializeAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal64(e.GenerateAssemblyString());
  auto t8 = e.AssemblyToken();
  b.setVal8(es.EntityId(t8));
  do {
    auto v15 = e.Inputs();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal11(e.IsSimple());
  b.setVal14(e.IsVolatile());
  do {
    auto v21 = e.Outputs();
    auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
    auto i21 = 0u;
    for (const auto &e21 : v21) {
      sv21.set(i21, es.EntityId(e21));
      ++i21;
    }
  } while (false);
  do {
    auto v65 = e.OutputConstraints();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
    }
  } while (false);
  do {
    auto v22 = e.OutputExpressions();
    auto sv22 = b.initVal22(static_cast<unsigned>(v22.size()));
    auto i22 = 0u;
    for (const auto &e22 : v22) {
      sv22.set(i22, es.EntityId(e22));
      ++i22;
    }
  } while (false);
  do {
    auto v66 = e.InputConstraints();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
  do {
    auto v23 = e.InputExpressions();
    auto sv23 = b.initVal23(static_cast<unsigned>(v23.size()));
    auto i23 = 0u;
    for (const auto &e23 : v23) {
      sv23.set(i23, es.EntityId(e23));
      ++i23;
    }
  } while (false);
  do {
    auto v67 = e.Clobbers();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
}

void SerializeMSAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  do {
    auto v68 = e.AllConstraints();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
    }
  } while (false);
  do {
    auto v24 = e.AllExpressions();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  auto v69 = e.AssemblyString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  auto t9 = e.LBraceToken();
  b.setVal9(es.EntityId(t9));
  b.setVal19(e.HasBraces());
}

void SerializeGCCAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal9(es.EntityId(e.AssemblyString()));
  auto t10 = e.RParenToken();
  b.setVal10(es.EntityId(t10));
  b.setVal19(e.IsAssemblyGoto());
  do {
    auto v24 = e.Labels();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  do {
    auto v51 = e.OutputConstraintLiterals();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  do {
    auto v68 = e.OutputNames();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
    }
  } while (false);
  do {
    auto v52 = e.InputConstraintLiterals();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v70 = e.InputNames();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      std::string se70(e70.data(), e70.size());
      sv70.set(i70, se70);
      ++i70;
    }
  } while (false);
  do {
    auto v53 = e.ClobberStringLiterals();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v71 = e.LabelExpressions();
    auto sv71 = b.initVal71(static_cast<unsigned>(v71.size()));
    auto i71 = 0u;
    for (const auto &e71 : v71) {
      sv71.set(i71, es.EntityId(e71));
      ++i71;
    }
  } while (false);
  do {
    auto v72 = e.LabelNames();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      std::string se72(e72.data(), e72.size());
      sv72.set(i72, se72);
      ++i72;
    }
  } while (false);
}

void SerializeWhileStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  auto v10 = e.ConditionVariable();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal14(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto t13 = e.LParenToken();
  b.setVal13(es.EntityId(t13));
  auto t16 = e.RParenToken();
  b.setVal16(es.EntityId(t16));
  auto t17 = e.WhileToken();
  b.setVal17(es.EntityId(t17));
  b.setVal19(e.HasVariableStorage());
}

void SerializeValueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v8 = e.ExpressionStatement();
  if (v8) {
    auto id8 = es.EntityId(v8.value());    b.setVal8(id8);
    b.setVal11(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal11(false);
  }
}

void SerializeLabelStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal9(es.EntityId(e.Declaration()));
  auto t10 = e.IdentifierToken();
  b.setVal10(es.EntityId(t10));
  auto v64 = e.Name();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal12(es.EntityId(e.SubStatement()));
  b.setVal14(e.IsSideEntry());
}

void SerializeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
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
  auto t31 = e.ExpressionToken();
  b.setVal31(es.EntityId(t31));
  auto v32 = e.ObjCProperty();
  if (v32) {
    auto id32 = es.EntityId(v32.value());    b.setVal32(id32);
    b.setVal56(id32 != mx::kInvalidEntityId);
  } else {
    b.setVal32(mx::kInvalidEntityId);
    b.setVal56(false);
  }
  b.setVal55(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v33 = e.ReferencedDeclarationOfCallee();
  if (v33) {
    auto id33 = es.EntityId(v33.value());    b.setVal33(id33);
    b.setVal57(id33 != mx::kInvalidEntityId);
  } else {
    b.setVal33(mx::kInvalidEntityId);
    b.setVal57(false);
  }
  auto v34 = e.SourceBitField();
  if (v34) {
    auto id34 = es.EntityId(v34.value());    b.setVal34(id34);
    b.setVal58(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto v35 = e.Type();
  if (v35) {
    auto id35 = es.EntityId(v35.value());    b.setVal35(id35);
    b.setVal59(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal59(false);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal60(e.HasNonTrivialCall());
  auto v61 = e.IsCXX98IntegralConstantExpression();
  if (v61) {
    b.setVal61(static_cast<bool>(v61.value()));
    b.setVal62(true);
  } else {
    b.setVal62(false);
  }
  b.setVal63(e.IsDefaultArgument());
  b.setVal74(e.IsGLValue());
  b.setVal75(e.IsImplicitCXXThis());
  b.setVal76(e.IsInstantiationDependent());
  auto v77 = e.IsIntegerConstantExpression();
  if (v77) {
    b.setVal77(static_cast<bool>(v77.value()));
    b.setVal78(true);
  } else {
    b.setVal78(false);
  }
  b.setVal79(e.IsKnownToHaveBooleanValue());
  b.setVal80(e.IsLValue());
  b.setVal81(e.IsOBJCGCCandidate());
  b.setVal82(e.IsObjCSelfExpression());
  b.setVal83(e.IsOrdinaryOrBitFieldObject());
  b.setVal84(e.IsPRValue());
  b.setVal85(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal86(e.IsTypeDependent());
  b.setVal87(e.IsValueDependent());
  b.setVal88(e.IsXValue());
  b.setVal89(e.RefersToBitField());
  b.setVal90(e.RefersToGlobalRegisterVariable());
  b.setVal91(e.RefersToMatrixElement());
  b.setVal92(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r36 = e.DesignatorsSourceRange(); auto rs36 = r36.Size()) {
    b.setVal36(es.EntityId(r36[0]));
    b.setVal37(es.EntityId(r36[rs36 - 1u]));
  } else {
    b.setVal36(0);
    b.setVal37(0);
  }
  auto t38 = e.EqualOrColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal93(e.IsDirectInitializer());
  b.setVal94(e.UsesGNUSyntax());
  do {
    auto v15 = e.SubExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.LAngleToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RAngleToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.TemplateKeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal93(e.HasExplicitTemplateArguments());
  b.setVal94(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.KeywordToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal38(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Declaration()));
  b.setVal37(es.EntityId(e.FoundDeclaration()));
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal93(e.HadMultipleCandidates());
  b.setVal94(e.HasExplicitTemplateArguments());
  b.setVal95(e.HasQualifier());
  b.setVal96(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal97(e.HasTemplateKeyword());
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal99(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.CommonExpression()));
  auto t37 = e.KeywordToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.OpaqueValue()));
  b.setVal39(es.EntityId(e.ReadyExpression()));
  b.setVal40(es.EntityId(e.ResumeExpression()));
  b.setVal41(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal42(es.EntityId(e.Operand()));
  b.setVal93(e.IsImplicit());
}

void SerializeCoyieldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal42(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v100 = e.TemplateArguments();
    auto sv100 = b.initVal100(static_cast<unsigned>(v100.size()));
    auto i100 = 0u;
    for (const auto &e100 : v100) {
      sv100.set(i100, es.PseudoId(e100));
      ++i100;
    }
  } while (false);
  b.setVal93(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Initializer()));
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal93(e.IsFileScope());
}

void SerializeChooseExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.ChosenSubExpression()));
  b.setVal38(es.EntityId(e.Condition()));
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal40(es.EntityId(e.RHS()));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal93(e.IsConditionDependent());
  b.setVal94(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v64 = e.CastKindName();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto v36 = e.ConversionFunction();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal38(es.EntityId(e.SubExpressionAsWritten()));
  auto v39 = e.TargetUnionField();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal94(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal95(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal96(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal40(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  if (auto r41 = e.AngleBrackets(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  auto v69 = e.CastName();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeCXXDynamicCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal96(e.IsAlwaysNull());
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
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal96(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeBuiltinBitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t41 = e.BridgeKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v69 = e.BridgeKindName();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal36(es.EntityId(e.CallReturnType()));
  b.setVal37(es.EntityId(e.Callee()));
  auto v38 = e.CalleeDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal93(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto v39 = e.DirectCallee();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal94(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal95(e.HasStoredFPFeatures());
  b.setVal96(e.HasUnusedResultAttribute());
  b.setVal97(e.IsBuiltinAssumeFalse());
  b.setVal99(e.IsCallToStdMove());
  b.setVal102(e.IsUnevaluatedBuiltinCall());
  b.setVal103(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  b.setVal104(e.IsAssignmentOperation());
  b.setVal105(e.IsComparisonOperation());
  b.setVal106(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.ImplicitObjectArgument()));
  auto v42 = e.MethodDeclaration();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal104(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal104(false);
  }
  b.setVal43(es.EntityId(e.ObjectType()));
  b.setVal44(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal41(es.EntityId(e.CookedLiteral()));
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t42 = e.UDSuffixToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.ExpressionOperand();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.GuidDeclaration()));
  b.setVal38(es.EntityId(e.TypeOperand()));
  b.setVal39(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal94(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto t36 = e.LParenToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.TypeAsWritten()));
  b.setVal93(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.ExpressionOperand();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.TypeOperand()));
  b.setVal38(es.EntityId(e.TypeOperandSourceInfo()));
  auto v94 = e.IsMostDerived();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal96(e.IsPotentiallyEvaluated());
  b.setVal97(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.SubExpression();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto t37 = e.ThrowToken();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal93(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.RParenToken();
  b.setVal36(es.EntityId(t36));
}

void SerializeCXXRewrittenBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.LHS()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v64 = e.OpcodeString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.RHS()));
  b.setVal39(es.EntityId(e.SemanticForm()));
  b.setVal93(e.IsAssignmentOperation());
  b.setVal94(e.IsComparisonOperation());
  b.setVal95(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  auto t37 = e.ColonColonToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.DestroyedType()));
  auto t39 = e.DestroyedTypeToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto v41 = e.ScopeType();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal93(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto t42 = e.TildeToken();
  b.setVal42(es.EntityId(t42));
  b.setVal94(e.HasQualifier());
  b.setVal95(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Operand()));
  b.setVal93(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.DoesUsualArrayDeleteWantSize());
  b.setVal36(es.EntityId(e.AllocatedType()));
  auto v37 = e.ArraySize();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v38 = e.ConstructExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  if (auto r39 = e.DirectInitializerRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v41 = e.Initializer();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal96(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal96(false);
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
  b.setVal97(e.HasInitializer());
  b.setVal99(e.IsArray());
  b.setVal102(e.IsGlobalNew());
  b.setVal103(e.IsParenthesisTypeId());
  b.setVal104(e.PassAlignment());
  do {
    auto v15 = e.PlacementArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal105(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.ConstructsVirtualBase());
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal36(es.EntityId(e.Constructor()));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal94(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Callee()));
  auto t37 = e.EllipsisToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Initializer()));
  b.setVal39(es.EntityId(e.LHS()));
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  auto v107 = e.NumExpansions();
  if (v107) {
    b.setVal107(static_cast<unsigned>(v107.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal41(es.EntityId(e.Pattern()));
  b.setVal42(es.EntityId(e.RHS()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal94(e.IsLeftFold());
  b.setVal95(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.Base();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.BaseType()));
  auto v38 = e.FirstQualifierFoundInScope();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal94(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.MemberToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasTemplateKeyword());
  b.setVal97(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.DoesUsualArrayDeleteWantSize());
  b.setVal36(es.EntityId(e.Argument()));
  b.setVal37(es.EntityId(e.DestroyedType()));
  b.setVal38(es.EntityId(e.OperatorDelete()));
  b.setVal94(e.IsArrayForm());
  b.setVal95(e.IsArrayFormAsWritten());
  b.setVal96(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.Expression();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.Field()));
  auto t38 = e.UsedToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXDefaultArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Expression()));
  b.setVal37(es.EntityId(e.Parameter()));
  auto t38 = e.UsedToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXConstructExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal36(es.EntityId(e.Constructor()));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  if (auto r38 = e.ParenthesisOrBraceRange(); auto rs38 = r38.Size()) {
    b.setVal38(es.EntityId(r38[0]));
    b.setVal39(es.EntityId(r38[rs38 - 1u]));
  } else {
    b.setVal38(0);
    b.setVal39(0);
  }
  b.setVal93(e.HadMultipleCandidates());
  b.setVal94(e.IsElidable());
  b.setVal95(e.IsListInitialization());
  b.setVal96(e.IsStdInitializerListInitialization());
  b.setVal97(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal93(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.BlockDeclaration()));
  b.setVal37(es.EntityId(e.Body()));
  auto t38 = e.CaretToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.LHS()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v64 = e.OpcodeString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.RHS()));
  b.setVal93(e.HasStoredFPFeatures());
  b.setVal94(e.IsAdditiveOperation());
  b.setVal95(e.IsAssignmentOperation());
  b.setVal96(e.IsBitwiseOperation());
  b.setVal97(e.IsCommaOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal102(e.IsCompoundAssignmentOperation());
  b.setVal103(e.IsEqualityOperation());
  b.setVal104(e.IsLogicalOperation());
  b.setVal105(e.IsMultiplicativeOperation());
  b.setVal106(e.IsPointerMemoryOperation());
  b.setVal108(e.IsRelationalOperation());
  b.setVal109(e.IsShiftAssignOperation());
  b.setVal110(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
  b.setVal39(es.EntityId(e.ComputationLHSType()));
  b.setVal40(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal37(es.EntityId(e.Order()));
  auto v38 = e.OrderFail();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal93(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  b.setVal39(es.EntityId(e.Pointer()));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  auto v41 = e.Scope();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal94(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto v42 = e.Value1();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal95(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v43 = e.Value2();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal96(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal44(es.EntityId(e.ValueType()));
  auto v45 = e.Weak();
  if (v45) {
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal97(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal99(e.IsCmpXChg());
  b.setVal102(e.IsOpenCL());
  b.setVal103(e.IsVolatile());
  do {
    auto v15 = e.SubExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeAsTypeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.DimensionExpression()));
  b.setVal37(es.EntityId(e.QueriedType()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.Index()));
  b.setVal38(es.EntityId(e.LHS()));
  auto t39 = e.RBracketToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.CommonExpression()));
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AmpAmpToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Label()));
  auto t38 = e.LabelToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeAbstractConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.ColonToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Condition()));
  b.setVal38(es.EntityId(e.FalseExpression()));
  auto t39 = e.QuestionToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal42(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal41(es.EntityId(e.Common()));
  b.setVal42(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.WrittenType()));
  b.setVal93(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.CanOverflow());
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t36 = e.OperatorToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal94(e.HasStoredFPFeatures());
  b.setVal95(e.IsArithmeticOperation());
  b.setVal96(e.IsDecrementOperation());
  b.setVal97(e.IsIncrementDecrementOperation());
  b.setVal99(e.IsIncrementOperation());
  b.setVal102(e.IsPostfix());
  b.setVal103(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.ArgumentExpression();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto v37 = e.ArgumentType();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.TypeOfArgument()));
  b.setVal95(e.IsArgumentType());
}

void SerializeTypoExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v93 = e.Value();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeSubstNonTypeTemplateParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.ParameterPack()));
  auto t37 = e.ParameterPackToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeSubstNonTypeTemplateParmExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.NameToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Parameter()));
  b.setVal38(es.EntityId(e.ParameterType()));
  b.setVal39(es.EntityId(e.Replacement()));
  b.setVal93(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  auto v93 = e.ContainsNonAscii();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  auto v95 = e.ContainsNonAsciiOrNull();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  auto v64 = e.Bytes();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto v69 = e.String();
  if (v69) {
    if (v69->empty()) {
      b.setVal69("");
    } else {
      std::string s69(v69->data(), v69->size());
      b.setVal69(s69);
    }
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
  b.setVal99(e.IsAscii());
  b.setVal102(e.IsPascal());
  b.setVal103(e.IsUTF16());
  b.setVal104(e.IsUTF32());
  b.setVal105(e.IsUTF8());
  b.setVal106(e.IsWide());
}

void SerializeStmtExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.LParenToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v64 = e.BuiltinString();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal93(e.IsIntType());
  b.setVal94(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.OperatorToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Pack()));
  auto v107 = e.PackLength();
  if (v107) {
    b.setVal107(static_cast<unsigned>(v107.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  auto t38 = e.PackToken();
  b.setVal38(es.EntityId(t38));
  do {
    auto ov100 = e.PartialArguments();
    if (!ov100) {
      b.setVal94(false);
      break;
    }
    b.setVal94(true);
    auto v100 = std::move(*ov100);
    auto sv100 = b.initVal100(static_cast<unsigned>(v100.size()));
    auto i100 = 0u;
    for (const auto &e100 : v100) {
      sv100.set(i100, es.PseudoId(e100));
      ++i100;
    }
  } while (false);
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal95(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.BuiltinToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeSYCLUniqueStableNameExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal64(e.ComputeName());
  auto t36 = e.LParenToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeRequiresExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Body()));
  do {
    auto v15 = e.LocalParameters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto t37 = e.RBraceToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RequiresKeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal93(e.IsSatisfied());
}

void SerializeRecoveryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.SubExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializePseudoObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.ResultExpression()));
  b.setVal37(es.EntityId(e.SyntacticForm()));
  do {
    auto v15 = e.Semantics();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  do {
    auto v21 = e.SemanticExpressions();
    auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
    auto i21 = 0u;
    for (const auto &e21 : v21) {
      sv21.set(i21, es.EntityId(e21));
      ++i21;
    }
  } while (false);
}

void SerializePredefinedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.FunctionName()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v64 = e.IdentifierKindName();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeParenListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.LParenToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  do {
    auto v15 = e.Expressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeParenExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.LParenToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.EllipsisToken();
  b.setVal36(es.EntityId(t36));
  auto v107 = e.NumExpansions();
  if (v107) {
    b.setVal107(static_cast<unsigned>(v107.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal37(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.LAngleToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.NameToken();
  b.setVal37(es.EntityId(t37));
  auto v38 = e.NamingClass();
  if (v38) {
    auto id38 = es.EntityId(v38.value());    b.setVal38(id38);
    b.setVal93(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal94(e.HasExplicitTemplateArguments());
  b.setVal95(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.BaseType()));
  auto t43 = e.MemberToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal96(e.HasUnresolvedUsing());
  b.setVal97(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal96(e.IsOverloaded());
  b.setVal97(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.SourceExpression()));
  b.setVal93(e.IsUnique());
}

void SerializeOffsetOfExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.OperatorToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeObjCSubscriptRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal37(es.EntityId(e.BaseExpression()));
  b.setVal38(es.EntityId(e.KeyExpression()));
  auto t39 = e.RBracketToken();
  b.setVal39(es.EntityId(t39));
  b.setVal93(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AtToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AtToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.RParenToken();
  b.setVal37(es.EntityId(t37));
}

void SerializeObjCProtocolExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AtToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Protocol()));
  auto t38 = e.ProtocolIdToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.ClassReceiver()));
  b.setVal38(es.EntityId(e.ExplicitProperty()));
  b.setVal39(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal40(es.EntityId(e.ImplicitPropertySetter()));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.ReceiverToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.ReceiverType()));
  b.setVal44(es.EntityId(e.SuperReceiverType()));
  b.setVal93(e.IsClassReceiver());
  b.setVal94(e.IsExplicitProperty());
  b.setVal95(e.IsImplicitProperty());
  b.setVal96(e.IsMessagingGetter());
  b.setVal97(e.IsMessagingSetter());
  b.setVal99(e.IsObjectReceiver());
  b.setVal102(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal36(es.EntityId(e.CallReturnType()));
  b.setVal37(es.EntityId(e.ClassReceiver()));
  b.setVal38(es.EntityId(e.ClassReceiverType()));
  b.setVal39(es.EntityId(e.InstanceReceiver()));
  auto t40 = e.LeftToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.MethodDeclaration()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal42(es.EntityId(e.ReceiverInterface()));
  b.setVal101(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r43 = e.ReceiverRange(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  b.setVal45(es.EntityId(e.ReceiverType()));
  auto t46 = e.RightToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.SelectorStartToken();
  b.setVal47(es.EntityId(t47));
  auto t48 = e.SuperToken();
  b.setVal48(es.EntityId(t48));
  b.setVal49(es.EntityId(e.SuperType()));
  b.setVal93(e.IsClassMessage());
  b.setVal94(e.IsDelegateInitializerCall());
  b.setVal95(e.IsImplicit());
  b.setVal96(e.IsInstanceMessage());
  do {
    auto v21 = e.SelectorTokens();
    auto sv21 = b.initVal21(static_cast<unsigned>(v21.size()));
    auto i21 = 0u;
    for (const auto &e21 : v21) {
      sv21.set(i21, es.EntityId(e21));
      ++i21;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.Declaration()));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.OperationToken();
  b.setVal39(es.EntityId(t39));
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  auto t37 = e.BaseTokenEnd();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.IsaMemberToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.OperationToken();
  b.setVal39(es.EntityId(t39));
  b.setVal93(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.SubExpression()));
  b.setVal93(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AtToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.EncodedType()));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeObjCDictionaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.AtToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.BoxingMethod()));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal93(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal93(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.ArrayWithObjectsMethod()));
  do {
    auto v15 = e.Elements();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeOMPIteratorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.IteratorKwToken();
  b.setVal36(es.EntityId(t36));
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeOMPArrayShapingExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  do {
    auto v15 = e.Dimensions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeOMPArraySectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  auto t37 = e.FirstColonToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.SecondColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Length()));
  b.setVal40(es.EntityId(e.LowerBound()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  auto t37 = e.LAngleToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.MemberDeclaration()));
  auto t39 = e.MemberToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal93(e.HadMultipleCandidates());
  b.setVal94(e.HasExplicitTemplateArguments());
  b.setVal95(e.HasQualifier());
  b.setVal96(e.HasTemplateKeyword());
  b.setVal97(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.ColumnIndex()));
  auto t38 = e.RBracketToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.RowIndex()));
  b.setVal93(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.ExtendingDeclaration();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto v37 = e.LifetimeExtendedTemporaryDeclaration();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal95(e.IsBoundToLvalueReference());
  b.setVal96(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Base()));
  b.setVal37(es.EntityId(e.Index()));
  auto t38 = e.RBracketToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeMSPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.BaseExpression()));
  auto t37 = e.MemberToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.PropertyDeclaration()));
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.Body()));
  b.setVal37(es.EntityId(e.CallOperator()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t38 = e.CaptureDefaultToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v15 = e.ExplicitTemplateParameters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  if (auto r40 = e.IntroducerRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
  b.setVal42(es.EntityId(e.LambdaClass()));
  auto v107 = e.TemplateParameterList();
  if (v107) {
    b.setVal107(es.PseudoId(v107.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  auto v43 = e.TrailingRequiresClause();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal94(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  b.setVal95(e.HasExplicitParameters());
  b.setVal96(e.HasExplicitResultType());
  b.setVal97(e.IsGenericLambda());
  b.setVal99(e.IsMutable());
}

void SerializeIntegerLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
}

void SerializeInitListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v36 = e.ArrayFiller();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal93(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal93(false);
  }
  auto v37 = e.InitializedFieldInUnion();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal94(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal94(false);
  }
  auto t38 = e.LBraceToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RBraceToken();
  b.setVal39(es.EntityId(t39));
  auto v40 = e.SemanticForm();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v41 = e.SyntacticForm();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal96(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal97(e.HadArrayRangeDesignator());
  b.setVal99(e.HasArrayFiller());
  do {
    auto v15 = e.Initializers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal102(e.IsExplicit());
  b.setVal103(e.IsSemanticForm());
  b.setVal104(e.IsStringLiteralInitializer());
  b.setVal105(e.IsSyntacticForm());
  auto v106 = e.IsTransparent();
  if (v106) {
    b.setVal106(static_cast<bool>(v106.value()));
    b.setVal108(true);
  } else {
    b.setVal108(false);
  }
}

void SerializeImplicitValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v15 = e.AssociationExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal36(es.EntityId(e.ControllingExpression()));
  auto t37 = e.DefaultToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.GenericToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.ResultExpression()));
  b.setVal93(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.TokenToken();
  b.setVal36(es.EntityId(t36));
}

void SerializeFunctionParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.ParameterPack()));
  auto t37 = e.ParameterPackToken();
  b.setVal37(es.EntityId(t37));
  do {
    auto v15 = e.Expansions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeFullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal93(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal93(e.HasAPValueResult());
  b.setVal94(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
  b.setVal93(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t36 = e.Token();
  b.setVal36(es.EntityId(t36));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal93(e.ContainsDuplicateElements());
  auto t36 = e.AccessorToken();
  b.setVal36(es.EntityId(t36));
  b.setVal37(es.EntityId(e.Base()));
  b.setVal94(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal36(es.EntityId(e.QueriedExpression()));
  b.setVal98(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal93(e.Value());
}

void SerializeAttributedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  auto t9 = e.AttributeToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal8(es.EntityId(e.Body()));
  b.setVal9(es.EntityId(e.Condition()));
  auto v10 = e.ConditionVariable();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());    b.setVal12(id12);
    b.setVal14(id12 != mx::kInvalidEntityId);
  } else {
    b.setVal12(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto v13 = e.Initializer();
  if (v13) {
    auto id13 = es.EntityId(v13.value());    b.setVal13(id13);
    b.setVal19(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal19(false);
  }
  auto t16 = e.LParenToken();
  b.setVal16(es.EntityId(t16));
  auto t17 = e.RParenToken();
  b.setVal17(es.EntityId(t17));
  auto v18 = e.FirstSwitchCase();
  if (v18) {
    auto id18 = es.EntityId(v18.value());    b.setVal18(id18);
    b.setVal20(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t25 = e.SwitchToken();
  b.setVal25(es.EntityId(t25));
  b.setVal56(e.HasInitializerStorage());
  b.setVal57(e.HasVariableStorage());
  b.setVal58(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
  SerializeStmt(es, b, e);
  auto t8 = e.ColonToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  auto v10 = e.NextSwitchCase();
  if (v10) {
    auto id10 = es.EntityId(v10.value());    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal12(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  auto t13 = e.DefaultToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeCaseStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
  SerializeSwitchCase(es, b, e);
  b.setVal14(e.CaseStatementIsGNURange());
  auto t13 = e.CaseToken();
  b.setVal13(es.EntityId(t13));
  auto t16 = e.EllipsisToken();
  b.setVal16(es.EntityId(t16));
  b.setVal17(es.EntityId(e.LHS()));
  auto v18 = e.RHS();
  if (v18) {
    auto id18 = es.EntityId(v18.value());    b.setVal18(id18);
    b.setVal19(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal19(false);
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  if (auto r40 = e.Tokens(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.Specialization()));
  b.setVal43(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.ContextParameter()));
  b.setVal43(e.IsNothrow());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal43(e.BlockMissingReturnType());
  b.setVal46(e.CanAvoidCopyToHeap());
  b.setVal47(e.CapturesCXXThis());
  b.setVal48(e.DoesNotEscape());
  auto v42 = e.BlockManglingContextDeclaration();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal49(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal49(false);
  }
  auto t50 = e.CaretToken();
  b.setVal50(es.EntityId(t50));
  b.setVal51(es.EntityId(e.CompoundBody()));
  b.setVal52(es.EntityId(e.SignatureAsWritten()));
  b.setVal53(e.HasCaptures());
  b.setVal54(e.IsConversionFromLambda());
  b.setVal55(e.IsVariadic());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.ParameterDeclarations();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
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

void SerializeAccessSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t42 = e.AccessSpecifierToken();
  b.setVal42(es.EntityId(t42));
  auto t50 = e.ColonToken();
  b.setVal50(es.EntityId(t50));
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
    auto v44 = e.Varlists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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
    auto v44 = e.Varlists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.AssertExpression()));
  b.setVal50(es.EntityId(e.Message()));
  auto t51 = e.RParenToken();
  b.setVal51(es.EntityId(t51));
  b.setVal43(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
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

void SerializePragmaDetectMismatchDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v57 = e.Name();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  auto v58 = e.Value();
  std::string s58(v58.data(), v58.size());
  b.setVal58(s58);
}

void SerializePragmaCommentDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v57 = e.Argument();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal42(es.EntityId(e.GetterCXXConstructor()));
  b.setVal50(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal51(es.EntityId(e.PropertyDeclaration()));
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal52(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t60 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal60(es.EntityId(t60));
  b.setVal61(es.EntityId(e.SetterCXXAssignment()));
  b.setVal62(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal43(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal57(e.Name());
  auto v63 = e.ObjCFStringFormattingFamily();
  if (v63) {
    b.setVal63(static_cast<unsigned char>(v63.value()));
    b.setVal43(true);
  } else {
    b.setVal43(false);
  }
  b.setVal58(e.QualifiedNameAsString());
  b.setVal42(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal46(e.HasExternalFormalLinkage());
  b.setVal47(e.HasLinkage());
  b.setVal48(e.HasLinkageBeenComputed());
  b.setVal49(e.IsCXXClassMember());
  b.setVal53(e.IsCXXInstanceMember());
  b.setVal54(e.IsExternallyDeclarable());
  b.setVal55(e.IsExternallyVisible());
  b.setVal65(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v66 = e.MSAssemblyLabel();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal50(es.EntityId(e.Statement()));
  b.setVal67(e.IsGnuLocal());
  b.setVal68(e.IsMSAssemblyLabel());
  b.setVal69(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v44 = e.Shadows();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal50(es.EntityId(e.EnumDeclaration()));
  auto t51 = e.EnumToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.UsingToken();
  b.setVal52(es.EntityId(t52));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t50 = e.UsingToken();
  b.setVal50(es.EntityId(t50));
  b.setVal67(e.HasTypename());
  b.setVal68(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal50(es.EntityId(e.Type()));
  b.setVal67(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t51 = e.EllipsisToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.UsingToken();
  b.setVal52(es.EntityId(t52));
  b.setVal68(e.IsAccessDeclaration());
  b.setVal69(e.IsPackExpansion());
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
  b.setVal51(es.EntityId(e.Combiner()));
  b.setVal52(es.EntityId(e.CombinerIn()));
  b.setVal60(es.EntityId(e.CombinerOut()));
  b.setVal61(es.EntityId(e.InitializerOriginal()));
  b.setVal62(es.EntityId(e.InitializerPrivate()));
  b.setVal70(es.EntityId(e.Initializer()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
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
    auto v44 = e.Chain();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  auto v51 = e.AnonymousField();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal68(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  auto v52 = e.VariableDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v51 = e.InitializerExpression();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal68(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal68(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t51 = e.FirstInnerToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.FirstOuterToken();
  b.setVal52(es.EntityId(t52));
  auto v60 = e.TrailingRequiresClause();
  if (v60) {
    auto id60 = es.EntityId(v60.value());    b.setVal60(id60);
    b.setVal68(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  auto t61 = e.TypeSpecEndToken();
  b.setVal61(es.EntityId(t61));
  auto t62 = e.TypeSpecStartToken();
  b.setVal62(es.EntityId(t62));
  do {
    auto v72 = e.TemplateParameterLists();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      sv72.set(i72, es.PseudoId(e72));
      ++i72;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.ActingDefinition();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal69(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto v73 = e.Initializer();
  if (v73) {
    auto id73 = es.EntityId(v73.value());    b.setVal73(id73);
    b.setVal74(id73 != mx::kInvalidEntityId);
  } else {
    b.setVal73(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v75 = e.InitializingDeclaration();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal76(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  auto v77 = e.InstantiatedFromStaticDataMember();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal78(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t80 = e.PointOfInstantiation();
  b.setVal80(es.EntityId(t80));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());    b.setVal85(id85);
    b.setVal86(id85 != mx::kInvalidEntityId);
  } else {
    b.setVal85(mx::kInvalidEntityId);
    b.setVal86(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal89(e.HasConstantInitialization());
  b.setVal90(e.HasDependentAlignment());
  b.setVal91(e.HasExternalStorage());
  b.setVal92(e.HasGlobalStorage());
  auto v93 = e.HasICEInitializer();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal95(e.HasInitializer());
  b.setVal96(e.HasLocalStorage());
  b.setVal97(e.IsARCPseudoStrong());
  b.setVal98(e.IsCXXForRangeDeclaration());
  b.setVal99(e.IsConstexpr());
  b.setVal100(e.IsDirectInitializer());
  b.setVal101(e.IsEscapingByref());
  b.setVal102(e.IsExceptionVariable());
  b.setVal103(e.IsExternC());
  b.setVal104(e.IsFileVariableDeclaration());
  b.setVal105(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal106(e.IsInExternCContext());
  b.setVal107(e.IsInExternCXXContext());
  b.setVal108(e.IsInitializerCapture());
  b.setVal109(e.IsInline());
  b.setVal110(e.IsInlineSpecified());
  b.setVal111(e.IsKnownToBeDefined());
  b.setVal112(e.IsLocalVariableDeclaration());
  b.setVal113(e.IsLocalVariableDeclarationOrParm());
  b.setVal114(e.IsNRVOVariable());
  b.setVal115(e.IsNoDestroy());
  b.setVal116(e.IsNonEscapingByref());
  b.setVal117(e.IsObjCForDeclaration());
  b.setVal118(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal119(e.IsStaticDataMember());
  b.setVal120(e.IsStaticLocal());
  b.setVal121(e.IsThisDeclarationADemotedDefinition());
  b.setVal122(e.IsUsableInConstantExpressions());
  b.setVal123(e.MightBeUsableInConstantExpressions());
  b.setVal124(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v125 = e.DefaultArgument();
  if (v125) {
    auto id125 = es.EntityId(v125.value());    b.setVal125(id125);
    b.setVal126(id125 != mx::kInvalidEntityId);
  } else {
    b.setVal125(mx::kInvalidEntityId);
    b.setVal126(false);
  }
  if (auto r127 = e.DefaultArgumentRange(); auto rs127 = r127.Size()) {
    b.setVal127(es.EntityId(r127[0]));
    b.setVal128(es.EntityId(r127[rs127 - 1u]));
  } else {
    b.setVal127(0);
    b.setVal128(0);
  }
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal130(es.EntityId(e.OriginalType()));
  auto v131 = e.UninstantiatedDefaultArgument();
  if (v131) {
    auto id131 = es.EntityId(v131.value());    b.setVal131(id131);
    b.setVal132(id131 != mx::kInvalidEntityId);
  } else {
    b.setVal131(mx::kInvalidEntityId);
    b.setVal132(false);
  }
  b.setVal133(e.HasDefaultArgument());
  b.setVal134(e.HasInheritedDefaultArgument());
  b.setVal135(e.HasUninstantiatedDefaultArgument());
  b.setVal136(e.HasUnparsedDefaultArgument());
  b.setVal137(e.IsDestroyedInCallee());
  b.setVal138(e.IsKNRPromoted());
  b.setVal139(e.IsObjCMethodParameter());
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
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v44 = e.Bindings();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto t125 = e.ExternToken();
  b.setVal125(es.EntityId(t125));
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v140 = e.TemplateArguments();
    auto sv140 = b.initVal140(static_cast<unsigned>(v140.size()));
    auto i140 = 0u;
    for (const auto &e140 : v140) {
      sv140.set(i140, es.PseudoId(e140));
      ++i140;
    }
  } while (false);
  do {
    auto v141 = e.TemplateInstantiationArguments();
    auto sv141 = b.initVal141(static_cast<unsigned>(v141.size()));
    auto i141 = 0u;
    for (const auto &e141 : v141) {
      sv141.set(i141, es.PseudoId(e141));
      ++i141;
    }
  } while (false);
  auto t127 = e.TemplateKeywordToken();
  b.setVal127(es.EntityId(t127));
  b.setVal128(es.EntityId(e.TypeAsWritten()));
  b.setVal126(e.IsClassScopeExplicitSpecialization());
  b.setVal132(e.IsExplicitInstantiationOrSpecialization());
  b.setVal133(e.IsExplicitSpecialization());
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
  b.setVal69(e.DefaultArgumentWasInherited());
  auto v70 = e.DefaultArgument();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal74(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  auto t73 = e.DefaultArgumentToken();
  b.setVal73(es.EntityId(t73));
  auto v142 = e.NumExpansionTypes();
  if (v142) {
    b.setVal142(static_cast<unsigned>(v142.value()));
    b.setVal76(true);
  } else {
    b.setVal76(false);
  }
  auto v75 = e.PlaceholderTypeConstraint();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal78(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal86(e.HasDefaultArgument());
  b.setVal89(e.HasPlaceholderTypeConstraint());
  b.setVal90(e.IsExpandedParameterPack());
  b.setVal91(e.IsPackExpansion());
  do {
    auto v44 = e.ExpansionTypes();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal69(e.HasGetter());
  b.setVal74(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal69(e.UsesFPIntrin());
  auto v74 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v74) {
    b.setVal74(static_cast<bool>(v74.value()));
    b.setVal76(true);
  } else {
    b.setVal76(false);
  }
  b.setVal78(e.DoesThisDeclarationHaveABody());
  b.setVal70(es.EntityId(e.CallResultType()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal73(es.EntityId(e.DeclaredReturnType()));
  auto t75 = e.EllipsisToken();
  b.setVal75(es.EntityId(t75));
  if (auto r77 = e.ExceptionSpecSourceRange(); auto rs77 = r77.Size()) {
    b.setVal77(es.EntityId(r77[0]));
    b.setVal80(es.EntityId(r77[rs77 - 1u]));
  } else {
    b.setVal77(0);
    b.setVal80(0);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v85 = e.InstantiatedFromMemberFunction();
  if (v85) {
    auto id85 = es.EntityId(v85.value());    b.setVal85(id85);
    b.setVal86(id85 != mx::kInvalidEntityId);
  } else {
    b.setVal85(mx::kInvalidEntityId);
    b.setVal86(false);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v142 = e.ODRHash();
  if (v142) {
    b.setVal142(static_cast<unsigned>(v142.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r125 = e.ParametersSourceRange(); auto rs125 = r125.Size()) {
    b.setVal125(es.EntityId(r125[0]));
    b.setVal127(es.EntityId(r125[rs125 - 1u]));
  } else {
    b.setVal125(0);
    b.setVal127(0);
  }
  auto t128 = e.PointOfInstantiation();
  b.setVal128(es.EntityId(t128));
  b.setVal130(es.EntityId(e.ReturnType()));
  if (auto r131 = e.ReturnTypeSourceRange(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal143(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal143(0);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v144 = e.TemplateInstantiationPattern();
  if (v144) {
    auto id144 = es.EntityId(v144.value());    b.setVal144(id144);
    b.setVal90(id144 != mx::kInvalidEntityId);
  } else {
    b.setVal144(mx::kInvalidEntityId);
    b.setVal90(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal124(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
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
  b.setVal126(e.IsMain());
  b.setVal132(e.IsMultiVersion());
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
  b.setVal145(e.IsTargetClonesMultiVersion());
  b.setVal146(e.IsTargetMultiVersion());
  b.setVal147(e.IsTemplateInstantiation());
  b.setVal148(e.IsThisDeclarationADefinition());
  b.setVal149(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal150(e.IsTrivial());
  b.setVal151(e.IsTrivialForCall());
  b.setVal152(e.IsUserProvided());
  b.setVal153(e.IsVariadic());
  b.setVal154(e.IsVirtualAsWritten());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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
  pasta::DeclContext dc45(e);
  auto v45 = dc45.AlreadyLoadedDeclarations();
  auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
  auto i45 = 0u;
  for (const pasta::Decl &e45 : v45) {
    sv45.set(i45, es.EntityId(e45));
    ++i45;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
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
    auto v56 = e.OverriddenMethods();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
    auto v56 = e.ParameterDeclarations();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v70 = e.BitWidth();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal69(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto v73 = e.CapturedVLAType();
  if (v73) {
    auto id73 = es.EntityId(v73.value());    b.setVal73(id73);
    b.setVal74(id73 != mx::kInvalidEntityId);
  } else {
    b.setVal73(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v75 = e.InClassInitializer();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal76(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal78(e.HasCapturedVLAType());
  b.setVal86(e.HasInClassInitializer());
  b.setVal89(e.IsAnonymousStructOrUnion());
  b.setVal90(e.IsBitField());
  b.setVal91(e.IsMutable());
  b.setVal92(e.IsUnnamedBitfield());
  b.setVal93(e.IsZeroLengthBitField());
  b.setVal94(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal77(es.EntityId(e.ContainingInterface()));
  b.setVal80(es.EntityId(e.NextInstanceVariable()));
  b.setVal95(e.Synthesize());
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
  b.setVal51(es.EntityId(e.Binding()));
  b.setVal52(es.EntityId(e.DecomposedDeclaration()));
  b.setVal60(es.EntityId(e.HoldingVariable()));
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
  b.setVal51(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal50(es.EntityId(e.Introducer()));
  auto v51 = e.NextUsingShadowDeclaration();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal67(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal67(false);
  }
  b.setVal52(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal68(e.ConstructsVirtualBase());
  b.setVal60(es.EntityId(e.ConstructedBaseClass()));
  auto v61 = e.ConstructedBaseClassShadowDeclaration();
  if (v61) {
    auto id61 = es.EntityId(v61.value());    b.setVal61(id61);
    b.setVal69(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal62(es.EntityId(e.NominatedBaseClass()));
  auto v70 = e.NominatedBaseClassShadowDeclaration();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal74(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal74(false);
  }
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v44 = e.Expansions();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  b.setVal50(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t50 = e.IdentifierToken();
  b.setVal50(es.EntityId(t50));
  auto t51 = e.NamespaceKeyToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t60 = e.UsingToken();
  b.setVal60(es.EntityId(t60));
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
  auto v50 = e.TypeForDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());    b.setVal50(id50);
    b.setVal67(id50 != mx::kInvalidEntityId);
  } else {
    b.setVal50(mx::kInvalidEntityId);
    b.setVal67(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal68(e.DefaultArgumentWasInherited());
  auto v51 = e.DefaultArgument();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal69(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  auto v52 = e.DefaultArgumentInfo();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal74(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  auto t60 = e.DefaultArgumentToken();
  b.setVal60(es.EntityId(t60));
  b.setVal76(e.HasDefaultArgument());
  b.setVal78(e.HasTypeConstraint());
  b.setVal86(e.IsExpandedParameterPack());
  b.setVal89(e.IsPackExpansion());
  b.setVal90(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r51 = e.BraceRange(); auto rs51 = r51.Size()) {
    b.setVal51(es.EntityId(r51[0]));
    b.setVal52(es.EntityId(r51[rs51 - 1u]));
  } else {
    b.setVal51(0);
    b.setVal52(0);
  }
  auto t60 = e.FirstInnerToken();
  b.setVal60(es.EntityId(t60));
  auto t61 = e.FirstOuterToken();
  b.setVal61(es.EntityId(t61));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v62 = e.TypedefNameForAnonymousDeclaration();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal68(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  b.setVal69(e.HasNameForLinkage());
  b.setVal74(e.IsBeingDefined());
  b.setVal76(e.IsClass());
  b.setVal78(e.IsCompleteDefinition());
  b.setVal86(e.IsCompleteDefinitionRequired());
  b.setVal89(e.IsDependentType());
  b.setVal90(e.IsEmbeddedInDeclarator());
  b.setVal91(e.IsEnum());
  b.setVal92(e.IsFreeStanding());
  b.setVal93(e.IsInterface());
  b.setVal94(e.IsStruct());
  b.setVal95(e.IsThisDeclarationADefinition());
  b.setVal96(e.IsUnion());
  b.setVal97(e.MayHaveOutOfDateDefinition());
  do {
    auto v72 = e.TemplateParameterLists();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      sv72.set(i72, es.PseudoId(e72));
      ++i72;
    }
  } while (false);
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal98(e.CanPassInRegisters());
  do {
    auto v45 = e.Fields();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
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
    auto ov140 = e.Bases();
    if (!ov140) {
      b.setVal119(false);
      break;
    }
    b.setVal119(true);
    auto v140 = std::move(*ov140);
    auto sv140 = b.initVal140(static_cast<unsigned>(v140.size()));
    auto i140 = 0u;
    for (const auto &e140 : v140) {
      sv140.set(i140, es.PseudoId(e140));
      ++i140;
    }
  } while (false);
  auto v81 = e.CalculateInheritanceModel();
  if (v81) {
    b.setVal81(static_cast<unsigned char>(v81.value()));
    b.setVal120(true);
  } else {
    b.setVal120(false);
  }
  do {
    auto v56 = e.Constructors();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
  auto v70 = e.Destructor();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal122(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal122(false);
  }
  auto v142 = e.GenericLambdaTemplateParameterList();
  if (v142) {
    b.setVal142(es.PseudoId(v142.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  auto v73 = e.InstantiatedFromMemberClass();
  if (v73) {
    auto id73 = es.EntityId(v73.value());    b.setVal73(id73);
    b.setVal126(id73 != mx::kInvalidEntityId);
  } else {
    b.setVal73(mx::kInvalidEntityId);
    b.setVal126(false);
  }
  auto v75 = e.LambdaCallOperator();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal132(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal132(false);
  }
  auto v82 = e.LambdaCaptureDefault();
  if (v82) {
    b.setVal82(static_cast<unsigned char>(v82.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  auto v77 = e.LambdaContextDeclaration();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal134(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
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
  auto v80 = e.LambdaType();
  if (v80) {
    auto id80 = es.EntityId(v80.value());    b.setVal80(id80);
    b.setVal137(id80 != mx::kInvalidEntityId);
  } else {
    b.setVal80(mx::kInvalidEntityId);
    b.setVal137(false);
  }
  auto v83 = e.MSInheritanceModel();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
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
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  auto v184 = e.ODRHash();
  if (v184) {
    b.setVal184(static_cast<unsigned>(v184.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());    b.setVal85(id85);
    b.setVal147(id85 != mx::kInvalidEntityId);
  } else {
    b.setVal85(mx::kInvalidEntityId);
    b.setVal147(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
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
  auto v125 = e.IsLocalClass();
  if (v125) {
    auto id125 = es.EntityId(v125.value());    b.setVal125(id125);
    b.setVal295(id125 != mx::kInvalidEntityId);
  } else {
    b.setVal125(mx::kInvalidEntityId);
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
    auto ov141 = e.VirtualBases();
    if (!ov141) {
      b.setVal342(false);
      break;
    }
    b.setVal342(true);
    auto v141 = std::move(*ov141);
    auto sv141 = b.initVal141(static_cast<unsigned>(v141.size()));
    auto i141 = 0u;
    for (const auto &e141 : v141) {
      sv141.set(i141, es.PseudoId(e141));
      ++i141;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t127 = e.ExternToken();
  b.setVal127(es.EntityId(t127));
  auto t128 = e.PointOfInstantiation();
  b.setVal128(es.EntityId(t128));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
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
  auto t130 = e.TemplateKeywordToken();
  b.setVal130(es.EntityId(t130));
  auto v131 = e.TypeAsWritten();
  if (v131) {
    auto id131 = es.EntityId(v131.value());    b.setVal131(id131);
    b.setVal345(id131 != mx::kInvalidEntityId);
  } else {
    b.setVal131(mx::kInvalidEntityId);
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
    auto v45 = e.Enumerators();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  auto v70 = e.InstantiatedFromMemberEnum();
  if (v70) {
    auto id70 = es.EntityId(v70.value());    b.setVal70(id70);
    b.setVal98(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v73 = e.IntegerType();
  if (v73) {
    auto id73 = es.EntityId(v73.value());    b.setVal73(id73);
    b.setVal99(id73 != mx::kInvalidEntityId);
  } else {
    b.setVal73(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  if (auto r75 = e.IntegerTypeRange(); auto rs75 = r75.Size()) {
    b.setVal75(es.EntityId(r75[0]));
    b.setVal77(es.EntityId(r75[rs75 - 1u]));
  } else {
    b.setVal75(0);
    b.setVal77(0);
  }
  auto v142 = e.ODRHash();
  if (v142) {
    b.setVal142(static_cast<unsigned>(v142.value()));
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  b.setVal80(es.EntityId(e.PromotionType()));
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());    b.setVal85(id85);
    b.setVal101(id85 != mx::kInvalidEntityId);
  } else {
    b.setVal85(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
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
  auto t51 = e.EllipsisToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.TypenameToken();
  b.setVal52(es.EntityId(t52));
  auto t60 = e.UsingToken();
  b.setVal60(es.EntityId(t60));
  b.setVal68(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v51 = e.AnonymousDeclarationWithTypedefName();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal68(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  b.setVal52(es.EntityId(e.UnderlyingType()));
  b.setVal69(e.IsModed());
  b.setVal74(e.IsTransparentTag());
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
  auto v60 = e.DescribedAliasTemplate();
  if (v60) {
    auto id60 = es.EntityId(v60.value());    b.setVal60(id60);
    b.setVal76(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal76(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t60 = e.ColonToken();
  b.setVal60(es.EntityId(t60));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t61 = e.VarianceToken();
  b.setVal61(es.EntityId(t61));
  b.setVal76(e.HasExplicitBound());
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
  auto v50 = e.InstantiatedFromMemberTemplate();
  if (v50) {
    auto id50 = es.EntityId(v50.value());    b.setVal50(id50);
    b.setVal67(id50 != mx::kInvalidEntityId);
  } else {
    b.setVal50(mx::kInvalidEntityId);
    b.setVal67(false);
  }
  b.setVal51(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal50(es.EntityId(e.ConstraintExpression()));
  b.setVal67(e.IsTypeConcept());
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
  auto t50 = e.AtToken();
  b.setVal50(es.EntityId(t50));
  b.setVal51(es.EntityId(e.GetterMethodDeclaration()));
  auto t52 = e.GetterNameToken();
  b.setVal52(es.EntityId(t52));
  auto t60 = e.LParenToken();
  b.setVal60(es.EntityId(t60));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal61(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal62(es.EntityId(e.SetterMethodDeclaration()));
  auto t70 = e.SetterNameToken();
  b.setVal70(es.EntityId(t70));
  b.setVal73(es.EntityId(e.Type()));
  b.setVal67(e.IsAtomic());
  b.setVal68(e.IsClassProperty());
  b.setVal69(e.IsDirectProperty());
  b.setVal74(e.IsInstanceProperty());
  b.setVal76(e.IsOptional());
  b.setVal78(e.IsReadOnly());
  b.setVal86(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal67(e.DefinedInNSObject());
  b.setVal50(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal51(es.EntityId(e.Category()));
  b.setVal52(es.EntityId(e.ClassInterface()));
  b.setVal60(es.EntityId(e.CommandDeclaration()));
  auto t61 = e.DeclaratorEndToken();
  b.setVal61(es.EntityId(t61));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal62(es.EntityId(e.ReturnType()));
  if (auto r70 = e.ReturnTypeSourceRange(); auto rs70 = r70.Size()) {
    b.setVal70(es.EntityId(r70[0]));
    b.setVal73(es.EntityId(r70[rs70 - 1u]));
  } else {
    b.setVal70(0);
    b.setVal73(0);
  }
  auto t75 = e.SelectorStartToken();
  b.setVal75(es.EntityId(t75));
  b.setVal77(es.EntityId(e.SelfDeclaration()));
  b.setVal68(e.HasParameterDestroyedInCallee());
  b.setVal69(e.HasRedeclaration());
  b.setVal74(e.HasRelatedResultType());
  b.setVal76(e.HasSkippedBody());
  b.setVal78(e.IsClassMethod());
  b.setVal86(e.IsDefined());
  b.setVal89(e.IsDesignatedInitializerForTheInterface());
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
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.SelectorTokens();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
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

void SerializeObjCContainerDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v44 = e.ClassMethods();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.ClassProperties();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  if (auto r50 = e.AtEndRange(); auto rs50 = r50.Size()) {
    b.setVal50(es.EntityId(r50[0]));
    b.setVal51(es.EntityId(r50[rs50 - 1u]));
  } else {
    b.setVal50(0);
    b.setVal51(0);
  }
  auto t52 = e.AtStartToken();
  b.setVal52(es.EntityId(t52));
  do {
    auto v56 = e.InstanceMethods();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
  b.setVal67(e.IsClassExtension());
  auto t60 = e.CategoryNameToken();
  b.setVal60(es.EntityId(t60));
  b.setVal61(es.EntityId(e.ClassInterface()));
  b.setVal62(es.EntityId(e.Implementation()));
  auto t70 = e.InstanceVariableLBraceToken();
  b.setVal70(es.EntityId(t70));
  auto t73 = e.InstanceVariableRBraceToken();
  b.setVal73(es.EntityId(t73));
  b.setVal75(es.EntityId(e.NextClassCategory()));
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
  auto v66 = e.ObjCRuntimeNameAsString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal67(e.HasDefinition());
  b.setVal68(e.IsNonRuntimeProtocol());
  b.setVal69(e.IsThisDeclarationADefinition());
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
  b.setVal67(e.DeclaresOrInheritsDesignatedInitializers());
  auto t60 = e.EndOfDefinitionToken();
  b.setVal60(es.EntityId(t60));
  b.setVal61(es.EntityId(e.Implementation()));
  auto v66 = e.ObjCRuntimeNameAsString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v62 = e.SuperClass();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal68(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal68(false);
  }
  auto t70 = e.SuperClassToken();
  b.setVal70(es.EntityId(t70));
  auto v73 = e.SuperClassTypeInfo();
  if (v73) {
    auto id73 = es.EntityId(v73.value());    b.setVal73(id73);
    b.setVal69(id73 != mx::kInvalidEntityId);
  } else {
    b.setVal73(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal75(es.EntityId(e.TypeForDeclaration()));
  b.setVal74(e.HasDefinition());
  b.setVal76(e.HasDesignatedInitializers());
  b.setVal78(e.IsArcWeakrefUnavailable());
  b.setVal86(e.IsImplicitInterfaceDeclaration());
  b.setVal77(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal89(e.IsThisDeclarationADefinition());
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
  b.setVal60(es.EntityId(e.ClassInterface()));
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
  b.setVal61(es.EntityId(e.CategoryDeclaration()));
  auto t62 = e.CategoryNameToken();
  b.setVal62(es.EntityId(t62));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t61 = e.InstanceVariableLBraceToken();
  b.setVal61(es.EntityId(t61));
  auto t62 = e.InstanceVariableRBraceToken();
  b.setVal62(es.EntityId(t62));
  auto v66 = e.ObjCRuntimeNameAsString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal70(es.EntityId(e.SuperClass()));
  auto t73 = e.SuperClassToken();
  b.setVal73(es.EntityId(t73));
  b.setVal67(e.HasDestructors());
  b.setVal68(e.HasNonZeroConstructors());
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
  b.setVal50(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeNamespaceAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t50 = e.AliasToken();
  b.setVal50(es.EntityId(t50));
  b.setVal51(es.EntityId(e.AliasedNamespace()));
  auto t52 = e.NamespaceToken();
  b.setVal52(es.EntityId(t52));
  auto t60 = e.TargetNameToken();
  b.setVal60(es.EntityId(t60));
}

void SerializeLinkageSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v44 = e.ChildrenExpression();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  b.setVal42(es.EntityId(e.ExtendingDeclaration()));
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal50(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v44 = e.IdentifierTokens();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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
  auto v42 = e.FriendDeclaration();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal43(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal43(false);
  }
  auto t50 = e.FriendToken();
  b.setVal50(es.EntityId(t50));
  auto v51 = e.FriendType();
  if (v51) {
    auto id51 = es.EntityId(v51.value());    b.setVal51(id51);
    b.setVal46(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal46(false);
  }
  b.setVal47(e.IsUnsupportedFriend());
  do {
    auto v72 = e.FriendTypeTemplateParameterLists();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      sv72.set(i72, es.PseudoId(e72));
      ++i72;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t42 = e.AssemblyToken();
  b.setVal42(es.EntityId(t42));
  b.setVal50(es.EntityId(e.AssemblyString()));
  auto t51 = e.RParenToken();
  b.setVal51(es.EntityId(t51));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc44(e);
  auto v44 = dc44.AlreadyLoadedDeclarations();
  auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
  auto i44 = 0u;
  for (const pasta::Decl &e44 : v44) {
    sv44.set(i44, es.EntityId(e44));
    ++i44;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t42 = e.ExportToken();
  b.setVal42(es.EntityId(t42));
  auto t50 = e.RBraceToken();
  b.setVal50(es.EntityId(t50));
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

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
