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
  b.setVal149(e.IsThisDeclarationADefinition());
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
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v160 = e.ThisObjectType();
  if (v160) {
    auto id160 = es.EntityId(v160.value());    b.setVal160(id160);
    b.setVal161(id160 != mx::kInvalidEntityId);
  } else {
    b.setVal160(mx::kInvalidEntityId);
    b.setVal161(false);
  }
  auto v162 = e.ThisType();
  if (v162) {
    auto id162 = es.EntityId(v162.value());    b.setVal162(id162);
    b.setVal163(id162 != mx::kInvalidEntityId);
  } else {
    b.setVal162(mx::kInvalidEntityId);
    b.setVal163(false);
  }
  b.setVal164(e.HasInlineBody());
  b.setVal165(e.IsConst());
  b.setVal166(e.IsCopyAssignmentOperator());
  b.setVal167(e.IsInstance());
  b.setVal168(e.IsLambdaStaticInvoker());
  b.setVal169(e.IsMoveAssignmentOperator());
  b.setVal170(e.IsVirtual());
  b.setVal171(e.IsVolatile());
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
    auto v172 = e.ParameterDeclarations();
    auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
    auto i172 = 0u;
    for (const auto &e172 : v172) {
      sv172.set(i172, es.EntityId(e172));
      ++i172;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v173 = e.OperatorDelete();
  if (v173) {
    auto id173 = es.EntityId(v173.value());    b.setVal173(id173);
    b.setVal174(id173 != mx::kInvalidEntityId);
  } else {
    b.setVal173(mx::kInvalidEntityId);
    b.setVal174(false);
  }
  auto v175 = e.OperatorDeleteThisArgument();
  if (v175) {
    auto id175 = es.EntityId(v175.value());    b.setVal175(id175);
    b.setVal176(id175 != mx::kInvalidEntityId);
  } else {
    b.setVal175(mx::kInvalidEntityId);
    b.setVal176(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal173(es.EntityId(e.ConversionType()));
  b.setVal174(e.IsExplicit());
  b.setVal176(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v173 = e.TargetConstructor();
  if (v173) {
    auto id173 = es.EntityId(v173.value());    b.setVal173(id173);
    b.setVal174(id173 != mx::kInvalidEntityId);
  } else {
    b.setVal173(mx::kInvalidEntityId);
    b.setVal174(false);
  }
  b.setVal176(e.IsDefaultConstructor());
  b.setVal177(e.IsDelegatingConstructor());
  b.setVal178(e.IsExplicit());
  b.setVal179(e.IsInheritingConstructor());
  b.setVal180(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal160(es.EntityId(e.CorrespondingConstructor()));
  b.setVal161(e.IsCopyDeductionCandidate());
  b.setVal163(e.IsExplicit());
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
    auto ov172 = e.Friends();
    if (!ov172) {
      b.setVal122(false);
      break;
    }
    b.setVal122(true);
    auto v172 = std::move(*ov172);
    auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
    auto i172 = 0u;
    for (const auto &e172 : v172) {
      sv172.set(i172, es.EntityId(e172));
      ++i172;
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
    auto ov181 = e.LambdaExplicitTemplateParameters();
    if (!ov181) {
      b.setVal136(false);
      break;
    }
    b.setVal136(true);
    auto v181 = std::move(*ov181);
    auto sv181 = b.initVal181(static_cast<unsigned>(v181.size()));
    auto i181 = 0u;
    for (const auto &e181 : v181) {
      sv181.set(i181, es.EntityId(e181));
      ++i181;
    }
  } while (false);
  auto v182 = e.LambdaManglingNumber();
  if (v182) {
    b.setVal182(static_cast<unsigned>(v182.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  auto v81 = e.LambdaType();
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
  auto v183 = e.NumBases();
  if (v183) {
    b.setVal183(static_cast<unsigned>(v183.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  auto v184 = e.NumVirtualBases();
  if (v184) {
    b.setVal184(static_cast<unsigned>(v184.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v185 = e.ODRHash();
  if (v185) {
    b.setVal185(static_cast<unsigned>(v185.value()));
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
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v157 = e.HasCopyAssignmentWithConstParameter();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v161 = e.HasCopyConstructorWithConstParameter();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
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
  auto v168 = e.HasDirectFields();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
    b.setVal169(true);
  } else {
    b.setVal169(false);
  }
  auto v170 = e.HasFriends();
  if (v170) {
    b.setVal170(static_cast<bool>(v170.value()));
    b.setVal171(true);
  } else {
    b.setVal171(false);
  }
  auto v174 = e.HasInClassInitializer();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasInheritedAssignment();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v179 = e.HasInheritedConstructor();
  if (v179) {
    b.setVal179(static_cast<bool>(v179.value()));
    b.setVal180(true);
  } else {
    b.setVal180(false);
  }
  auto v186 = e.HasInitializerMethod();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v188 = e.HasIrrelevantDestructor();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  auto v190 = e.HasKnownLambdaInternalLinkage();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasMoveAssignment();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasMoveConstructor();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasMutableFields();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonLiteralTypeFieldsOrBases();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialCopyAssignment();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialCopyConstructor();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialCopyConstructorForCall();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialDefaultConstructor();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialDestructor();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialDestructorForCall();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialMoveAssignment();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasNonTrivialMoveConstructor();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasNonTrivialMoveConstructorForCall();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasPrivateFields();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasProtectedFields();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasSimpleCopyAssignment();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasSimpleCopyConstructor();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasSimpleDestructor();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasSimpleMoveAssignment();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasSimpleMoveConstructor();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialCopyAssignment();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialCopyConstructor();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialCopyConstructorForCall();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialDefaultConstructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialDestructor();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialDestructorForCall();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialMoveAssignment();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasTrivialMoveConstructor();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasTrivialMoveConstructorForCall();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUninitializedReferenceMember();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserDeclaredConstructor();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUserDeclaredCopyAssignment();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredCopyConstructor();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserDeclaredDestructor();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUserDeclaredMoveAssignment();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserDeclaredMoveConstructor();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasUserDeclaredMoveOperation();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.HasUserProvidedDefaultConstructor();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.HasVariantMembers();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.ImplicitCopyConstructorHasConstParameter();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsAbstract();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.IsAggregate();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.IsAnyDestructorNoReturn();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  auto v280 = e.IsCLike();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  auto v282 = e.IsCXX11StandardLayout();
  if (v282) {
    b.setVal282(static_cast<bool>(v282.value()));
    b.setVal283(true);
  } else {
    b.setVal283(false);
  }
  b.setVal284(e.IsDependentLambda());
  auto v285 = e.IsDynamicClass();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsEffectivelyFinal();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  auto v289 = e.IsEmpty();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  b.setVal291(e.IsGenericLambda());
  auto v292 = e.IsInterfaceLike();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v294 = e.IsLiteral();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  auto v126 = e.IsLocalClass();
  if (v126) {
    auto id126 = es.EntityId(v126.value());    b.setVal126(id126);
    b.setVal296(id126 != mx::kInvalidEntityId);
  } else {
    b.setVal126(mx::kInvalidEntityId);
    b.setVal296(false);
  }
  auto v297 = e.IsPOD();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsPolymorphic();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.IsStandardLayout();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsStructural();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.IsTrivial();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.IsTriviallyCopyable();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.MayBeAbstract();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.MayBeDynamicClass();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  auto v315 = e.MayBeNonDynamicClass();
  if (v315) {
    b.setVal315(static_cast<bool>(v315.value()));
    b.setVal316(true);
  } else {
    b.setVal316(false);
  }
  do {
    auto ov317 = e.Methods();
    if (!ov317) {
      b.setVal318(false);
      break;
    }
    b.setVal318(true);
    auto v317 = std::move(*ov317);
    auto sv317 = b.initVal317(static_cast<unsigned>(v317.size()));
    auto i317 = 0u;
    for (const auto &e317 : v317) {
      sv317.set(i317, es.EntityId(e317));
      ++i317;
    }
  } while (false);
  auto v319 = e.NeedsImplicitCopyAssignment();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.NeedsImplicitCopyConstructor();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.NeedsImplicitDefaultConstructor();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsImplicitDestructor();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsImplicitMoveAssignment();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsImplicitMoveConstructor();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsOverloadResolutionForDestructor();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
  auto v341 = e.NullFieldOffsetIsZero();
  if (v341) {
    b.setVal341(static_cast<bool>(v341.value()));
    b.setVal342(true);
  } else {
    b.setVal342(false);
  }
  do {
    auto ov142 = e.VirtualBases();
    if (!ov142) {
      b.setVal343(false);
      break;
    }
    b.setVal343(true);
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
    auto v344 = e.TemplateArguments();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.PseudoId(e344));
      ++i344;
    }
  } while (false);
  do {
    auto v345 = e.TemplateInstantiationArguments();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.PseudoId(e345));
      ++i345;
    }
  } while (false);
  auto t131 = e.TemplateKeywordToken();
  b.setVal131(es.EntityId(t131));
  auto v132 = e.TypeAsWritten();
  if (v132) {
    auto id132 = es.EntityId(v132.value());    b.setVal132(id132);
    b.setVal346(id132 != mx::kInvalidEntityId);
  } else {
    b.setVal132(mx::kInvalidEntityId);
    b.setVal346(false);
  }
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
  b.setVal98(e.IsThisDeclarationADefinition());
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
    auto v172 = e.InstanceProperties();
    auto sv172 = b.initVal172(static_cast<unsigned>(v172.size()));
    auto i172 = 0u;
    for (const auto &e172 : v172) {
      sv172.set(i172, es.EntityId(e172));
      ++i172;
    }
  } while (false);
  do {
    auto v181 = e.Methods();
    auto sv181 = b.initVal181(static_cast<unsigned>(v181.size()));
    auto i181 = 0u;
    for (const auto &e181 : v181) {
      sv181.set(i181, es.EntityId(e181));
      ++i181;
    }
  } while (false);
  do {
    auto v317 = e.Properties();
    auto sv317 = b.initVal317(static_cast<unsigned>(v317.size()));
    auto i317 = 0u;
    for (const auto &e317 : v317) {
      sv317.set(i317, es.EntityId(e317));
      ++i317;
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
  auto v67 = e.ObjCRuntimeNameAsString();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  b.setVal68(e.HasDefinition());
  b.setVal69(e.IsNonRuntimeProtocol());
  b.setVal70(e.IsThisDeclarationADefinition());
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
