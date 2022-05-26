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
  b.setVal72(e.IsBitIntType());
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
  b.setVal115(e.IsIbm128Type());
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
  auto t312 = e.AttributeToken();
  b.setVal312(es.EntityId(t312));
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
  auto t314 = e.EllipsisToken();
  b.setVal314(es.EntityId(t314));
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

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  auto t307 = e.AttributeToken();
  b.setVal307(es.EntityId(t307));
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
  auto t307 = e.AttributeToken();
  b.setVal307(es.EntityId(t307));
  b.setVal312(es.EntityId(e.ElementType()));
  b.setVal314(es.EntityId(e.SizeExpression()));
  b.setVal308(e.IsSugared());
}

void SerializeDependentBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e) {
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
  auto t312 = e.AttributeToken();
  b.setVal312(es.EntityId(t312));
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
  b.setVal333(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
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

void SerializeBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal308(e.IsSigned());
  b.setVal309(e.IsSugared());
  b.setVal310(e.IsUnsigned());
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
  auto t329 = e.LBracketToken();
  b.setVal329(es.EntityId(t329));
  auto t330 = e.RBracketToken();
  b.setVal330(es.EntityId(t330));
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
  auto t329 = e.LBracketToken();
  b.setVal329(es.EntityId(t329));
  auto t330 = e.RBracketToken();
  b.setVal330(es.EntityId(t330));
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

void SerializeUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal306(es.EntityId(e.Desugar()));
  b.setVal307(es.EntityId(e.FoundDeclaration()));
  b.setVal312(es.EntityId(e.UnderlyingType()));
  b.setVal308(e.IsSugared());
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

void SerializeOMPMetaDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal15(es.EntityId(e.IfStatement()));
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
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
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

void SerializeOMPGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
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
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal28(es.EntityId(e.Then()));
  b.setVal58(e.HasElseStorage());
  b.setVal59(e.HasInitializerStorage());
  b.setVal60(e.HasVariableStorage());
  b.setVal61(e.IsConsteval());
  b.setVal62(e.IsConstexpr());
  b.setVal63(e.IsNegatedConsteval());
  b.setVal64(e.IsNonNegatedConsteval());
  b.setVal65(e.IsObjCAvailabilityCheck());
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
    b.setVal58(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal58(false);
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
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
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
  b.setVal66(e.GenerateAssemblyString());
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
    auto v67 = e.OutputConstraints();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
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
    auto v68 = e.InputConstraints();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
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
    auto v69 = e.Clobbers();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
    }
  } while (false);
}

void SerializeMSAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  do {
    auto v70 = e.AllConstraints();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      std::string se70(e70.data(), e70.size());
      sv70.set(i70, se70);
      ++i70;
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
  auto v71 = e.AssemblyString();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
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
    auto v70 = e.OutputNames();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      std::string se70(e70.data(), e70.size());
      sv70.set(i70, se70);
      ++i70;
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
    auto v72 = e.InputNames();
    auto sv72 = b.initVal72(static_cast<unsigned>(v72.size()));
    auto i72 = 0u;
    for (const auto &e72 : v72) {
      std::string se72(e72.data(), e72.size());
      sv72.set(i72, se72);
      ++i72;
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
    auto v73 = e.LabelExpressions();
    auto sv73 = b.initVal73(static_cast<unsigned>(v73.size()));
    auto i73 = 0u;
    for (const auto &e73 : v73) {
      sv73.set(i73, es.EntityId(e73));
      ++i73;
    }
  } while (false);
  do {
    auto v74 = e.LabelNames();
    auto sv74 = b.initVal74(static_cast<unsigned>(v74.size()));
    auto i74 = 0u;
    for (const auto &e74 : v74) {
      std::string se74(e74.data(), e74.size());
      sv74.set(i74, se74);
      ++i74;
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
  auto v66 = e.Name();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
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
  b.setVal32(es.EntityId(e.AsBuiltinConstantDeclarationReference()));
  b.setVal33(es.EntityId(e.BestDynamicClassTypeExpression()));
  auto t34 = e.ExpressionToken();
  b.setVal34(es.EntityId(t34));
  auto v35 = e.ObjCProperty();
  if (v35) {
    auto id35 = es.EntityId(v35.value());    b.setVal35(id35);
    b.setVal58(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v36 = e.ReferencedDeclarationOfCallee();
  if (v36) {
    auto id36 = es.EntityId(v36.value());    b.setVal36(id36);
    b.setVal59(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal59(false);
  }
  auto v37 = e.SourceBitField();
  if (v37) {
    auto id37 = es.EntityId(v37.value());    b.setVal37(id37);
    b.setVal60(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal60(false);
  }
  b.setVal38(es.EntityId(e.Type()));
  b.setVal75(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal61(e.HasNonTrivialCall());
  auto v62 = e.IsCXX11ConstantExpression();
  if (v62) {
    b.setVal62(static_cast<bool>(v62.value()));
    b.setVal63(true);
  } else {
    b.setVal63(false);
  }
  auto v64 = e.IsCXX98IntegralConstantExpression();
  if (v64) {
    b.setVal64(static_cast<bool>(v64.value()));
    b.setVal65(true);
  } else {
    b.setVal65(false);
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
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  if (auto r39 = e.DesignatorsSourceRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  auto t41 = e.EqualOrColonToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Initializer()));
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
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.TemplateKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.KeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Operand()));
  b.setVal41(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Declaration()));
  b.setVal40(es.EntityId(e.FoundDeclaration()));
  auto t41 = e.LAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal98(e.HadMultipleCandidates());
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasQualifier());
  b.setVal101(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal102(e.HasTemplateKeyword());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal104(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.CommonExpression()));
  auto t40 = e.KeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.OpaqueValue()));
  b.setVal42(es.EntityId(e.ReadyExpression()));
  b.setVal43(es.EntityId(e.ResumeExpression()));
  b.setVal44(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal45(es.EntityId(e.Operand()));
  b.setVal98(e.IsImplicit());
}

void SerializeCoyieldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal45(es.EntityId(e.Operand()));
}

void SerializeConvertVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SrcExpression()));
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
  b.setVal39(es.EntityId(e.Initializer()));
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal98(e.IsFileScope());
}

void SerializeChooseExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.ChosenSubExpression()));
  b.setVal41(es.EntityId(e.Condition()));
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal98(e.IsConditionDependent());
  b.setVal99(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v66 = e.CastKindName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v39 = e.ConversionFunction();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.SubExpressionAsWritten()));
  auto v42 = e.TargetUnionField();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal99(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
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
  b.setVal43(es.EntityId(e.TypeAsWritten()));
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
  auto v71 = e.CastName();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.RParenToken();
  b.setVal47(es.EntityId(t47));
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
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal101(e.IsListInitialization());
}

void SerializeCStyleCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeBuiltinBitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t44 = e.BridgeKeywordToken();
  b.setVal44(es.EntityId(t44));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v71 = e.BridgeKindName();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  auto t45 = e.LParenToken();
  b.setVal45(es.EntityId(t45));
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
  b.setVal39(es.EntityId(e.CallReturnType()));
  b.setVal40(es.EntityId(e.Callee()));
  auto v41 = e.CalleeDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal98(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v42 = e.DirectCallee();
  if (v42) {
    auto id42 = es.EntityId(v42.value());    b.setVal42(id42);
    b.setVal99(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
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
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal109(e.IsAssignmentOperation());
  b.setVal110(e.IsComparisonOperation());
  b.setVal111(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.ImplicitObjectArgument()));
  auto v45 = e.MethodDeclaration();
  if (v45) {
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal109(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal109(false);
  }
  b.setVal46(es.EntityId(e.ObjectType()));
  b.setVal47(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.CookedLiteral()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t45 = e.UDSuffixToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.GuidDeclaration()));
  b.setVal41(es.EntityId(e.TypeOperand()));
  b.setVal42(es.EntityId(e.TypeOperandSourceInfo()));
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
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.TypeAsWritten()));
  b.setVal98(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.TypeOperand()));
  b.setVal41(es.EntityId(e.TypeOperandSourceInfo()));
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
  auto v39 = e.SubExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto t40 = e.ThrowToken();
  b.setVal40(es.EntityId(t40));
  b.setVal99(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXRewrittenBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v66 = e.OpcodeString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.SemanticForm()));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.ColonColonToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.DestroyedType()));
  auto t42 = e.DestroyedTypeToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.ScopeTypeInfo()));
  auto t45 = e.TildeToken();
  b.setVal45(es.EntityId(t45));
  b.setVal98(e.HasQualifier());
  b.setVal99(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal98(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal39(es.EntityId(e.AllocatedType()));
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
  b.setVal39(es.EntityId(e.Constructor()));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  b.setVal99(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Callee()));
  auto t40 = e.EllipsisToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.Initializer()));
  b.setVal42(es.EntityId(e.LHS()));
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal44(es.EntityId(e.Pattern()));
  b.setVal45(es.EntityId(e.RHS()));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
  b.setVal99(e.IsLeftFold());
  b.setVal100(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.BaseType()));
  auto v41 = e.FirstQualifierFoundInScope();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal98(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto t42 = e.LAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.MemberToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RAngleToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.TemplateKeywordToken();
  b.setVal46(es.EntityId(t46));
  b.setVal99(e.HasExplicitTemplateArguments());
  b.setVal100(e.HasTemplateKeyword());
  b.setVal101(e.IsArrow());
  b.setVal102(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.DoesUsualArrayDeleteWantSize());
  b.setVal39(es.EntityId(e.Argument()));
  b.setVal40(es.EntityId(e.DestroyedType()));
  b.setVal41(es.EntityId(e.OperatorDelete()));
  b.setVal99(e.IsArrayForm());
  b.setVal100(e.IsArrayFormAsWritten());
  b.setVal101(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v39 = e.Expression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.Field()));
  auto t41 = e.UsedToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeCXXDefaultArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Expression()));
  b.setVal40(es.EntityId(e.Parameter()));
  auto t41 = e.UsedToken();
  b.setVal41(es.EntityId(t41));
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
  b.setVal39(es.EntityId(e.Constructor()));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  if (auto r41 = e.ParenthesisOrBraceRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.Value());
}

void SerializeCXXBindTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.BlockDeclaration()));
  b.setVal40(es.EntityId(e.Body()));
  auto t41 = e.CaretToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v66 = e.OpcodeString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RHS()));
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
  b.setVal42(es.EntityId(e.ComputationLHSType()));
  b.setVal43(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal40(es.EntityId(e.Order()));
  auto v41 = e.OrderFail();
  if (v41) {
    auto id41 = es.EntityId(v41.value());    b.setVal41(id41);
    b.setVal98(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal42(es.EntityId(e.Pointer()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  auto v44 = e.Scope();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal99(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto v45 = e.Value1();
  if (v45) {
    auto id45 = es.EntityId(v45.value());    b.setVal45(id45);
    b.setVal100(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  auto v46 = e.Value2();
  if (v46) {
    auto id46 = es.EntityId(v46.value());    b.setVal46(id46);
    b.setVal101(id46 != mx::kInvalidEntityId);
  } else {
    b.setVal46(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  b.setVal47(es.EntityId(e.ValueType()));
  auto v48 = e.Weak();
  if (v48) {
    auto id48 = es.EntityId(v48.value());    b.setVal48(id48);
    b.setVal102(id48 != mx::kInvalidEntityId);
  } else {
    b.setVal48(mx::kInvalidEntityId);
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
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.DimensionExpression()));
  b.setVal40(es.EntityId(e.QueriedType()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  b.setVal41(es.EntityId(e.LHS()));
  auto t42 = e.RBracketToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.CommonExpression()));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AmpAmpToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Label()));
  auto t41 = e.LabelToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeAbstractConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.ColonToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.FalseExpression()));
  auto t42 = e.QuestionToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal44(es.EntityId(e.LHS()));
  b.setVal45(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal44(es.EntityId(e.Common()));
  b.setVal45(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal42(es.EntityId(e.WrittenTypeInfo()));
  b.setVal98(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.CanOverflow());
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
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
  auto v39 = e.ArgumentExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v40 = e.ArgumentType();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal99(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.TypeOfArgument()));
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
  b.setVal39(es.EntityId(e.ParameterPack()));
  auto t40 = e.ParameterPackToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeSubstNonTypeTemplateParmExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.NameToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Parameter()));
  b.setVal41(es.EntityId(e.ParameterType()));
  b.setVal42(es.EntityId(e.Replacement()));
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
  auto v66 = e.Bytes();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v71 = e.String();
  if (v71) {
    if (v71->empty()) {
      b.setVal71("");
    } else {
      std::string s71(v71->data(), v71->size());
      b.setVal71(s71);
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
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v66 = e.BuiltinString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.IsIntType());
  b.setVal99(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Pack()));
  auto v112 = e.PackLength();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto t41 = e.PackToken();
  b.setVal41(es.EntityId(t41));
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
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal100(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeSYCLUniqueStableNameExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal66(e.ComputeName());
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeRequiresExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Body()));
  do {
    auto v17 = e.LocalParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  auto t40 = e.RBraceToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RequiresKeywordToken();
  b.setVal41(es.EntityId(t41));
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
  b.setVal39(es.EntityId(e.ResultExpression()));
  b.setVal40(es.EntityId(e.SyntacticForm()));
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
  b.setVal39(es.EntityId(e.FunctionName()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v66 = e.IdentifierKindName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
}

void SerializeParenListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
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
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.EllipsisToken();
  b.setVal39(es.EntityId(t39));
  auto v112 = e.NumExpansions();
  if (v112) {
    b.setVal112(static_cast<unsigned>(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal40(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.NameToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.NamingClass()));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal98(e.HasExplicitTemplateArguments());
  b.setVal99(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal44(es.EntityId(e.Base()));
  b.setVal45(es.EntityId(e.BaseType()));
  auto t46 = e.MemberToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.OperatorToken();
  b.setVal47(es.EntityId(t47));
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SourceExpression()));
  b.setVal98(e.IsUnique());
}

void SerializeOffsetOfExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCSubscriptRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal40(es.EntityId(e.BaseExpression()));
  b.setVal41(es.EntityId(e.KeyExpression()));
  auto t42 = e.RBracketToken();
  b.setVal42(es.EntityId(t42));
  b.setVal98(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCProtocolExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Protocol()));
  auto t41 = e.ProtocolIdToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeObjCPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.ClassReceiver()));
  b.setVal41(es.EntityId(e.ExplicitProperty()));
  b.setVal42(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal43(es.EntityId(e.ImplicitPropertySetter()));
  auto t44 = e.Token();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.ReceiverToken();
  b.setVal45(es.EntityId(t45));
  b.setVal46(es.EntityId(e.ReceiverType()));
  b.setVal47(es.EntityId(e.SuperReceiverType()));
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
  b.setVal39(es.EntityId(e.CallReturnType()));
  b.setVal40(es.EntityId(e.ClassReceiver()));
  b.setVal41(es.EntityId(e.ClassReceiverTypeInfo()));
  b.setVal42(es.EntityId(e.InstanceReceiver()));
  auto t43 = e.LeftToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.MethodDeclaration()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal45(es.EntityId(e.ReceiverInterface()));
  b.setVal106(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r46 = e.ReceiverRange(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
  }
  b.setVal48(es.EntityId(e.ReceiverType()));
  auto t49 = e.RightToken();
  b.setVal49(es.EntityId(t49));
  auto t50 = e.SelectorStartToken();
  b.setVal50(es.EntityId(t50));
  auto t51 = e.SuperToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.SuperType()));
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
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Declaration()));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperationToken();
  b.setVal42(es.EntityId(t42));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.BaseTokenEnd();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.IsaMemberToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperationToken();
  b.setVal42(es.EntityId(t42));
  b.setVal98(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal98(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.EncodedType()));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeObjCDictionaryLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.BoxingMethod()));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal98(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.ArrayWithObjectsMethod()));
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
  auto t39 = e.IteratorKwToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeOMPArrayShapingExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  do {
    auto v17 = e.Dimensions();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeOMPArraySectionExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.FirstColonToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.SecondColonToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Length()));
  b.setVal43(es.EntityId(e.LowerBound()));
  auto t44 = e.RBracketToken();
  b.setVal44(es.EntityId(t44));
  b.setVal45(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.LAngleToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.MemberDeclaration()));
  auto t42 = e.MemberToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RAngleToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.TemplateKeywordToken();
  b.setVal45(es.EntityId(t45));
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
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.ColumnIndex()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.RowIndex()));
  b.setVal98(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v39 = e.ExtendingDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v40 = e.LifetimeExtendedTemporaryDeclaration();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal99(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal100(e.IsBoundToLvalueReference());
  b.setVal101(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeMSPropertyRefExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.BaseExpression()));
  auto t40 = e.MemberToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.PropertyDeclaration()));
  b.setVal98(e.IsArrow());
  b.setVal99(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.Body()));
  b.setVal40(es.EntityId(e.CallOperator()));
  b.setVal103(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t41 = e.CaptureDefaultToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v17 = e.ExplicitTemplateParameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
  if (auto r43 = e.IntroducerRange(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  b.setVal45(es.EntityId(e.LambdaClass()));
  auto v112 = e.TemplateParameterList();
  if (v112) {
    b.setVal112(es.PseudoId(v112.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto v46 = e.TrailingRequiresClause();
  if (v46) {
    auto id46 = es.EntityId(v46.value());    b.setVal46(id46);
    b.setVal99(id46 != mx::kInvalidEntityId);
  } else {
    b.setVal46(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  b.setVal100(e.HasExplicitParameters());
  b.setVal101(e.HasExplicitResultType());
  b.setVal102(e.IsGenericLambda());
  b.setVal104(e.IsMutable());
}

void SerializeIntegerLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeInitListExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
  SerializeExpr(es, b, e);
  auto v39 = e.ArrayFiller();
  if (v39) {
    auto id39 = es.EntityId(v39.value());    b.setVal39(id39);
    b.setVal98(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  auto v40 = e.InitializedFieldInUnion();
  if (v40) {
    auto id40 = es.EntityId(v40.value());    b.setVal40(id40);
    b.setVal99(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  auto t41 = e.LBraceToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RBraceToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.SemanticForm();
  if (v43) {
    auto id43 = es.EntityId(v43.value());    b.setVal43(id43);
    b.setVal100(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  auto v44 = e.SyntacticForm();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal101(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
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
  b.setVal39(es.EntityId(e.SubExpression()));
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
  b.setVal39(es.EntityId(e.ControllingExpression()));
  auto t40 = e.DefaultToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.GenericToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.ResultExpression()));
  b.setVal98(e.IsResultDependent());
}

void SerializeGNUNullExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.TokenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeFunctionParmPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.ParameterPack()));
  auto t40 = e.ParameterPackToken();
  b.setVal40(es.EntityId(t40));
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
  b.setVal39(es.EntityId(e.SubExpression()));
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
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal98(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal98(e.ContainsDuplicateElements());
  auto t39 = e.AccessorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Base()));
  b.setVal99(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal39(es.EntityId(e.QueriedExpression()));
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
  b.setVal58(e.HasInitializerStorage());
  b.setVal59(e.HasVariableStorage());
  b.setVal60(e.IsAllEnumCasesCovered());
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
  b.setVal24(e.IsInExportDeclarationContext());
  b.setVal25(e.IsInLocalScopeForInstantiation());
  b.setVal26(e.IsInStdNamespace());
  b.setVal27(e.IsInvalidDeclaration());
  b.setVal28(e.IsModulePrivate());
  b.setVal29(e.IsOutOfLine());
  b.setVal30(e.IsParameterPack());
  b.setVal31(e.IsTemplateDeclaration());
  b.setVal32(e.IsTemplateParameter());
  b.setVal33(e.IsTemplateParameterPack());
  b.setVal34(e.IsTemplated());
  b.setVal35(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal36(e.IsUnavailable());
  b.setVal37(e.IsUnconditionallyVisible());
  b.setVal38(e.IsWeakImported());
  do {
    auto v39 = e.Redeclarations();
    auto sv39 = b.initVal39(static_cast<unsigned>(v39.size()));
    auto i39 = 0u;
    for (const auto &e39 : v39) {
      sv39.set(i39, es.EntityId(e39));
      ++i39;
    }
  } while (false);
  b.setVal40(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  if (auto r42 = e.Tokens(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.Specialization()));
  b.setVal45(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.ContextParameter()));
  b.setVal45(e.IsNothrow());
  do {
    auto v46 = e.Parameters();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal45(e.BlockMissingReturnType());
  b.setVal48(e.CanAvoidCopyToHeap());
  b.setVal49(e.CapturesCXXThis());
  b.setVal50(e.DoesNotEscape());
  auto v44 = e.BlockManglingContextDeclaration();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal51(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal51(false);
  }
  auto t52 = e.CaretToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.CompoundBody()));
  b.setVal54(es.EntityId(e.SignatureAsWritten()));
  b.setVal55(e.HasCaptures());
  b.setVal56(e.IsConversionFromLambda());
  b.setVal57(e.IsVariadic());
  do {
    auto v46 = e.Parameters();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  do {
    auto v47 = e.ParameterDeclarations();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  pasta::DeclContext dc58(e);
  auto v58 = dc58.AlreadyLoadedDeclarations();
  auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
  auto i58 = 0u;
  for (const pasta::Decl &e58 : v58) {
    sv58.set(i58, es.EntityId(e58));
    ++i58;
  }
}

void SerializeAccessSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.AccessSpecifierToken();
  b.setVal44(es.EntityId(t44));
  auto t52 = e.ColonToken();
  b.setVal52(es.EntityId(t52));
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
    auto v46 = e.Varlists();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
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
    auto v46 = e.Varlists();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.AssertExpression()));
  b.setVal52(es.EntityId(e.Message()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
  b.setVal45(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializePragmaDetectMismatchDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v59 = e.Name();
  std::string s59(v59.data(), v59.size());
  b.setVal59(s59);
  auto v60 = e.Value();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
}

void SerializePragmaCommentDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v59 = e.Argument();
  std::string s59(v59.data(), v59.size());
  b.setVal59(s59);
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.GetterCXXConstructor()));
  b.setVal52(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal53(es.EntityId(e.PropertyDeclaration()));
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal54(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t62 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.SetterCXXAssignment()));
  b.setVal64(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal45(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal59(e.Name());
  auto v65 = e.ObjCFStringFormattingFamily();
  if (v65) {
    b.setVal65(static_cast<unsigned char>(v65.value()));
    b.setVal45(true);
  } else {
    b.setVal45(false);
  }
  b.setVal60(e.QualifiedNameAsString());
  b.setVal44(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal48(e.HasExternalFormalLinkage());
  b.setVal49(e.HasLinkage());
  b.setVal50(e.HasLinkageBeenComputed());
  b.setVal51(e.IsCXXClassMember());
  b.setVal55(e.IsCXXInstanceMember());
  b.setVal56(e.IsExternallyDeclarable());
  b.setVal57(e.IsExternallyVisible());
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
  b.setVal52(es.EntityId(e.Statement()));
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
    auto v46 = e.Shadows();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal52(es.EntityId(e.EnumDeclaration()));
  auto t53 = e.EnumToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.UsingToken();
  b.setVal54(es.EntityId(t54));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t52 = e.UsingToken();
  b.setVal52(es.EntityId(t52));
  b.setVal69(e.HasTypename());
  b.setVal70(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal52(es.EntityId(e.Type()));
  b.setVal69(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t53 = e.EllipsisToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.UsingToken();
  b.setVal54(es.EntityId(t54));
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
  b.setVal53(es.EntityId(e.Combiner()));
  b.setVal54(es.EntityId(e.CombinerIn()));
  b.setVal62(es.EntityId(e.CombinerOut()));
  b.setVal63(es.EntityId(e.InitializerOriginal()));
  b.setVal64(es.EntityId(e.InitializerPrivate()));
  b.setVal72(es.EntityId(e.Initializer()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
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
    auto v46 = e.Chain();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  auto v53 = e.AnonymousField();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal70(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto v54 = e.VariableDeclaration();
  if (v54) {
    auto id54 = es.EntityId(v54.value());    b.setVal54(id54);
    b.setVal71(id54 != mx::kInvalidEntityId);
  } else {
    b.setVal54(mx::kInvalidEntityId);
    b.setVal71(false);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v53 = e.InitializerExpression();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal70(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal70(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t53 = e.FirstInnerToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.FirstOuterToken();
  b.setVal54(es.EntityId(t54));
  auto v62 = e.TrailingRequiresClause();
  if (v62) {
    auto id62 = es.EntityId(v62.value());    b.setVal62(id62);
    b.setVal70(id62 != mx::kInvalidEntityId);
  } else {
    b.setVal62(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto t63 = e.TypeSpecEndToken();
  b.setVal63(es.EntityId(t63));
  auto t64 = e.TypeSpecStartToken();
  b.setVal64(es.EntityId(t64));
  do {
    auto v74 = e.TemplateParameterLists();
    auto sv74 = b.initVal74(static_cast<unsigned>(v74.size()));
    auto i74 = 0u;
    for (const auto &e74 : v74) {
      sv74.set(i74, es.PseudoId(e74));
      ++i74;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.ActingDefinition();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal71(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  auto v75 = e.Initializer();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal76(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v77 = e.InitializingDeclaration();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal78(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  auto v79 = e.InstantiatedFromStaticDataMember();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal80(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t82 = e.PointOfInstantiation();
  b.setVal82(es.EntityId(t82));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v87 = e.TemplateInstantiationPattern();
  if (v87) {
    auto id87 = es.EntityId(v87.value());    b.setVal87(id87);
    b.setVal88(id87 != mx::kInvalidEntityId);
  } else {
    b.setVal87(mx::kInvalidEntityId);
    b.setVal88(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal91(e.HasConstantInitialization());
  b.setVal92(e.HasDependentAlignment());
  b.setVal93(e.HasExternalStorage());
  b.setVal94(e.HasGlobalStorage());
  auto v95 = e.HasICEInitializer();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal97(e.HasInitializer());
  b.setVal98(e.HasLocalStorage());
  b.setVal99(e.IsARCPseudoStrong());
  b.setVal100(e.IsCXXForRangeDeclaration());
  b.setVal101(e.IsConstexpr());
  b.setVal102(e.IsDirectInitializer());
  b.setVal103(e.IsEscapingByref());
  b.setVal104(e.IsExceptionVariable());
  b.setVal105(e.IsExternC());
  b.setVal106(e.IsFileVariableDeclaration());
  b.setVal107(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal108(e.IsInExternCContext());
  b.setVal109(e.IsInExternCXXContext());
  b.setVal110(e.IsInitializerCapture());
  b.setVal111(e.IsInline());
  b.setVal112(e.IsInlineSpecified());
  b.setVal113(e.IsKnownToBeDefined());
  b.setVal114(e.IsLocalVariableDeclaration());
  b.setVal115(e.IsLocalVariableDeclarationOrParm());
  b.setVal116(e.IsNRVOVariable());
  b.setVal117(e.IsNoDestroy());
  b.setVal118(e.IsNonEscapingByref());
  b.setVal119(e.IsObjCForDeclaration());
  b.setVal120(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal121(e.IsStaticDataMember());
  b.setVal122(e.IsStaticLocal());
  b.setVal123(e.IsThisDeclarationADemotedDefinition());
  b.setVal124(e.IsUsableInConstantExpressions());
  b.setVal125(e.MightBeUsableInConstantExpressions());
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v127 = e.DefaultArgument();
  if (v127) {
    auto id127 = es.EntityId(v127.value());    b.setVal127(id127);
    b.setVal128(id127 != mx::kInvalidEntityId);
  } else {
    b.setVal127(mx::kInvalidEntityId);
    b.setVal128(false);
  }
  if (auto r129 = e.DefaultArgumentRange(); auto rs129 = r129.Size()) {
    b.setVal129(es.EntityId(r129[0]));
    b.setVal130(es.EntityId(r129[rs129 - 1u]));
  } else {
    b.setVal129(0);
    b.setVal130(0);
  }
  b.setVal131(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal132(es.EntityId(e.OriginalType()));
  auto v133 = e.UninstantiatedDefaultArgument();
  if (v133) {
    auto id133 = es.EntityId(v133.value());    b.setVal133(id133);
    b.setVal134(id133 != mx::kInvalidEntityId);
  } else {
    b.setVal133(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  b.setVal135(e.HasDefaultArgument());
  b.setVal136(e.HasInheritedDefaultArgument());
  b.setVal137(e.HasUninstantiatedDefaultArgument());
  b.setVal138(e.HasUnparsedDefaultArgument());
  b.setVal139(e.IsDestroyedInCallee());
  b.setVal140(e.IsKNRPromoted());
  b.setVal141(e.IsObjCMethodParameter());
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
  b.setVal131(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v46 = e.Bindings();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto t127 = e.ExternToken();
  b.setVal127(es.EntityId(t127));
  b.setVal131(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v142 = e.TemplateArguments();
    auto sv142 = b.initVal142(static_cast<unsigned>(v142.size()));
    auto i142 = 0u;
    for (const auto &e142 : v142) {
      sv142.set(i142, es.PseudoId(e142));
      ++i142;
    }
  } while (false);
  do {
    auto v143 = e.TemplateInstantiationArguments();
    auto sv143 = b.initVal143(static_cast<unsigned>(v143.size()));
    auto i143 = 0u;
    for (const auto &e143 : v143) {
      sv143.set(i143, es.PseudoId(e143));
      ++i143;
    }
  } while (false);
  auto t129 = e.TemplateKeywordToken();
  b.setVal129(es.EntityId(t129));
  b.setVal130(es.EntityId(e.TypeAsWritten()));
  b.setVal128(e.IsClassScopeExplicitSpecialization());
  b.setVal134(e.IsExplicitInstantiationOrSpecialization());
  b.setVal135(e.IsExplicitSpecialization());
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
  b.setVal71(e.DefaultArgumentWasInherited());
  b.setVal72(es.EntityId(e.DefaultArgument()));
  auto t75 = e.DefaultArgumentToken();
  b.setVal75(es.EntityId(t75));
  b.setVal77(es.EntityId(e.PlaceholderTypeConstraint()));
  b.setVal76(e.HasDefaultArgument());
  b.setVal78(e.HasPlaceholderTypeConstraint());
  b.setVal80(e.IsExpandedParameterPack());
  b.setVal88(e.IsPackExpansion());
  do {
    auto v46 = e.ExpansionTypes();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  do {
    auto v47 = e.ExpansionTypeSourceInfos();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal71(e.HasGetter());
  b.setVal76(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal71(e.UsesFPIntrin());
  auto v76 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v76) {
    b.setVal76(static_cast<bool>(v76.value()));
    b.setVal78(true);
  } else {
    b.setVal78(false);
  }
  b.setVal80(e.DoesThisDeclarationHaveABody());
  b.setVal72(es.EntityId(e.CallResultType()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal75(es.EntityId(e.DeclaredReturnType()));
  auto t77 = e.EllipsisToken();
  b.setVal77(es.EntityId(t77));
  if (auto r79 = e.ExceptionSpecSourceRange(); auto rs79 = r79.Size()) {
    b.setVal79(es.EntityId(r79[0]));
    b.setVal82(es.EntityId(r79[rs79 - 1u]));
  } else {
    b.setVal79(0);
    b.setVal82(0);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v87 = e.InstantiatedFromMemberFunction();
  if (v87) {
    auto id87 = es.EntityId(v87.value());    b.setVal87(id87);
    b.setVal88(id87 != mx::kInvalidEntityId);
  } else {
    b.setVal87(mx::kInvalidEntityId);
    b.setVal88(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v144 = e.ODRHash();
  if (v144) {
    b.setVal144(static_cast<unsigned>(v144.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r127 = e.ParametersSourceRange(); auto rs127 = r127.Size()) {
    b.setVal127(es.EntityId(r127[0]));
    b.setVal129(es.EntityId(r127[rs127 - 1u]));
  } else {
    b.setVal127(0);
    b.setVal129(0);
  }
  auto t130 = e.PointOfInstantiation();
  b.setVal130(es.EntityId(t130));
  b.setVal132(es.EntityId(e.ReturnType()));
  if (auto r133 = e.ReturnTypeSourceRange(); auto rs133 = r133.Size()) {
    b.setVal133(es.EntityId(r133[0]));
    b.setVal145(es.EntityId(r133[rs133 - 1u]));
  } else {
    b.setVal133(0);
    b.setVal145(0);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v146 = e.TemplateInstantiationPattern();
  if (v146) {
    auto id146 = es.EntityId(v146.value());    b.setVal146(id146);
    b.setVal92(id146 != mx::kInvalidEntityId);
  } else {
    b.setVal146(mx::kInvalidEntityId);
    b.setVal92(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal93(e.HasImplicitReturnZero());
  b.setVal94(e.HasInheritedPrototype());
  b.setVal95(e.HasOneParameterOrDefaultArguments());
  b.setVal96(e.HasPrototype());
  b.setVal97(e.HasSkippedBody());
  b.setVal98(e.HasTrivialBody());
  b.setVal99(e.HasWrittenPrototype());
  b.setVal100(e.InstantiationIsPending());
  b.setVal101(e.IsCPUDispatchMultiVersion());
  b.setVal102(e.IsCPUSpecificMultiVersion());
  b.setVal103(e.IsConsteval());
  b.setVal104(e.IsConstexpr());
  b.setVal105(e.IsConstexprSpecified());
  b.setVal106(e.IsDefaulted());
  b.setVal107(e.IsDeleted());
  b.setVal108(e.IsDeletedAsWritten());
  b.setVal109(e.IsDestroyingOperatorDelete());
  b.setVal110(e.IsExplicitlyDefaulted());
  b.setVal111(e.IsExternC());
  b.setVal112(e.IsFunctionTemplateSpecialization());
  b.setVal113(e.IsGlobal());
  b.setVal114(e.IsImplicitlyInstantiable());
  b.setVal115(e.IsInExternCContext());
  b.setVal116(e.IsInExternCXXContext());
  b.setVal117(e.IsInlineBuiltinDeclaration());
  auto v118 = e.IsInlineDefinitionExternallyVisible();
  if (v118) {
    b.setVal118(static_cast<bool>(v118.value()));
    b.setVal119(true);
  } else {
    b.setVal119(false);
  }
  b.setVal120(e.IsInlineSpecified());
  b.setVal121(e.IsInlined());
  b.setVal122(e.IsLateTemplateParsed());
  auto v123 = e.IsMSExternInline();
  if (v123) {
    b.setVal123(static_cast<bool>(v123.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  b.setVal125(e.IsMSVCRTEntryPoint());
  b.setVal128(e.IsMain());
  b.setVal134(e.IsMultiVersion());
  b.setVal135(e.IsNoReturn());
  b.setVal136(e.IsOverloadedOperator());
  b.setVal137(e.IsPure());
  b.setVal138(e.IsReplaceableGlobalAllocationFunction());
  auto v139 = e.IsReservedGlobalPlacementOperator();
  if (v139) {
    b.setVal139(static_cast<bool>(v139.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  b.setVal141(e.IsStatic());
  b.setVal147(e.IsTargetClonesMultiVersion());
  b.setVal148(e.IsTargetMultiVersion());
  b.setVal149(e.IsTemplateInstantiation());
  b.setVal150(e.IsThisDeclarationADefinition());
  b.setVal151(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal152(e.IsTrivial());
  b.setVal153(e.IsTrivialForCall());
  b.setVal154(e.IsUserProvided());
  b.setVal155(e.IsVariadic());
  b.setVal156(e.IsVirtualAsWritten());
  do {
    auto v46 = e.Parameters();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal157(e.UsesSEHTry());
  b.setVal158(e.WillHaveBody());
  auto v159 = e.Body();
  if (v159) {
    auto id159 = es.EntityId(v159.value());    b.setVal159(id159);
    b.setVal160(id159 != mx::kInvalidEntityId);
  } else {
    b.setVal159(mx::kInvalidEntityId);
    b.setVal160(false);
  }
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal131(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
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
    auto v58 = e.OverriddenMethods();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
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
  b.setVal161(es.EntityId(e.CorrespondingConstructor()));
  b.setVal163(e.IsCopyDeductionCandidate());
  b.setVal164(e.IsExplicit());
  do {
    auto v58 = e.ParameterDeclarations();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
    }
  } while (false);
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.BitWidth();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal71(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  auto v75 = e.CapturedVLAType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal76(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v77 = e.InClassInitializer();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal78(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal80(e.HasCapturedVLAType());
  b.setVal88(e.HasInClassInitializer());
  b.setVal91(e.IsAnonymousStructOrUnion());
  b.setVal92(e.IsBitField());
  b.setVal93(e.IsMutable());
  b.setVal94(e.IsUnnamedBitfield());
  b.setVal95(e.IsZeroLengthBitField());
  b.setVal96(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal79(es.EntityId(e.ContainingInterface()));
  b.setVal82(es.EntityId(e.NextInstanceVariable()));
  b.setVal97(e.Synthesize());
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
  b.setVal53(es.EntityId(e.Binding()));
  b.setVal54(es.EntityId(e.DecomposedDeclaration()));
  b.setVal62(es.EntityId(e.HoldingVariable()));
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
  b.setVal53(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal52(es.EntityId(e.Introducer()));
  auto v53 = e.NextUsingShadowDeclaration();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal69(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal69(false);
  }
  b.setVal54(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal70(e.ConstructsVirtualBase());
  b.setVal62(es.EntityId(e.ConstructedBaseClass()));
  auto v63 = e.ConstructedBaseClassShadowDeclaration();
  if (v63) {
    auto id63 = es.EntityId(v63.value());    b.setVal63(id63);
    b.setVal71(id63 != mx::kInvalidEntityId);
  } else {
    b.setVal63(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  b.setVal64(es.EntityId(e.NominatedBaseClass()));
  auto v72 = e.NominatedBaseClassShadowDeclaration();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal76(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal76(false);
  }
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v46 = e.Expansions();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal52(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t52 = e.IdentifierToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.NamespaceKeyToken();
  b.setVal53(es.EntityId(t53));
  b.setVal54(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t62 = e.UsingToken();
  b.setVal62(es.EntityId(t62));
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
  auto v52 = e.TypeForDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());    b.setVal52(id52);
    b.setVal69(id52 != mx::kInvalidEntityId);
  } else {
    b.setVal52(mx::kInvalidEntityId);
    b.setVal69(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal70(e.DefaultArgumentWasInherited());
  b.setVal53(es.EntityId(e.DefaultArgument()));
  b.setVal54(es.EntityId(e.DefaultArgumentInfo()));
  auto t62 = e.DefaultArgumentToken();
  b.setVal62(es.EntityId(t62));
  b.setVal71(e.HasDefaultArgument());
  b.setVal76(e.HasTypeConstraint());
  b.setVal78(e.IsExpandedParameterPack());
  b.setVal80(e.IsPackExpansion());
  b.setVal88(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r53 = e.BraceRange(); auto rs53 = r53.Size()) {
    b.setVal53(es.EntityId(r53[0]));
    b.setVal54(es.EntityId(r53[rs53 - 1u]));
  } else {
    b.setVal53(0);
    b.setVal54(0);
  }
  auto t62 = e.FirstInnerToken();
  b.setVal62(es.EntityId(t62));
  auto t63 = e.FirstOuterToken();
  b.setVal63(es.EntityId(t63));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v64 = e.TypedefNameForAnonymousDeclaration();
  if (v64) {
    auto id64 = es.EntityId(v64.value());    b.setVal64(id64);
    b.setVal70(id64 != mx::kInvalidEntityId);
  } else {
    b.setVal64(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal71(e.HasNameForLinkage());
  b.setVal76(e.IsBeingDefined());
  b.setVal78(e.IsClass());
  b.setVal80(e.IsCompleteDefinition());
  b.setVal88(e.IsCompleteDefinitionRequired());
  b.setVal91(e.IsDependentType());
  b.setVal92(e.IsEmbeddedInDeclarator());
  b.setVal93(e.IsEnum());
  b.setVal94(e.IsFreeStanding());
  b.setVal95(e.IsInterface());
  b.setVal96(e.IsStruct());
  b.setVal97(e.IsThisDeclarationADefinition());
  b.setVal98(e.IsUnion());
  b.setVal99(e.MayHaveOutOfDateDefinition());
  do {
    auto v74 = e.TemplateParameterLists();
    auto sv74 = b.initVal74(static_cast<unsigned>(v74.size()));
    auto i74 = 0u;
    for (const auto &e74 : v74) {
      sv74.set(i74, es.PseudoId(e74));
      ++i74;
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

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal100(e.CanPassInRegisters());
  do {
    auto v47 = e.Fields();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal101(e.HasFlexibleArrayMember());
  b.setVal102(e.HasLoadedFieldsFromExternalStorage());
  b.setVal103(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal104(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal105(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal106(e.HasObjectMember());
  b.setVal107(e.HasVolatileMember());
  b.setVal108(e.IsAnonymousStructOrUnion());
  b.setVal109(e.IsCapturedRecord());
  b.setVal110(e.IsInjectedClassName());
  b.setVal111(e.IsLambda());
  b.setVal112(e.IsMsStruct());
  b.setVal113(e.IsNonTrivialToPrimitiveCopy());
  b.setVal114(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal115(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal116(e.IsOrContainsUnion());
  b.setVal117(e.IsParameterDestroyedInCallee());
  b.setVal118(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v119 = e.AllowConstDefaultInitializer();
  if (v119) {
    b.setVal119(static_cast<bool>(v119.value()));
    b.setVal120(true);
  } else {
    b.setVal120(false);
  }
  do {
    auto ov142 = e.Bases();
    if (!ov142) {
      b.setVal121(false);
      break;
    }
    b.setVal121(true);
    auto v142 = std::move(*ov142);
    auto sv142 = b.initVal142(static_cast<unsigned>(v142.size()));
    auto i142 = 0u;
    for (const auto &e142 : v142) {
      sv142.set(i142, es.PseudoId(e142));
      ++i142;
    }
  } while (false);
  auto v83 = e.CalculateInheritanceModel();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal122(true);
  } else {
    b.setVal122(false);
  }
  do {
    auto v58 = e.Constructors();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
    }
  } while (false);
  do {
    auto ov171 = e.Friends();
    if (!ov171) {
      b.setVal123(false);
      break;
    }
    b.setVal123(true);
    auto v171 = std::move(*ov171);
    auto sv171 = b.initVal171(static_cast<unsigned>(v171.size()));
    auto i171 = 0u;
    for (const auto &e171 : v171) {
      sv171.set(i171, es.EntityId(e171));
      ++i171;
    }
  } while (false);
  auto v72 = e.Destructor();
  if (v72) {
    auto id72 = es.EntityId(v72.value());    b.setVal72(id72);
    b.setVal124(id72 != mx::kInvalidEntityId);
  } else {
    b.setVal72(mx::kInvalidEntityId);
    b.setVal124(false);
  }
  auto v144 = e.GenericLambdaTemplateParameterList();
  if (v144) {
    b.setVal144(es.PseudoId(v144.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
  }
  auto v75 = e.InstantiatedFromMemberClass();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal128(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal128(false);
  }
  auto v77 = e.LambdaCallOperator();
  if (v77) {
    auto id77 = es.EntityId(v77.value());    b.setVal77(id77);
    b.setVal134(id77 != mx::kInvalidEntityId);
  } else {
    b.setVal77(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  auto v84 = e.LambdaCaptureDefault();
  if (v84) {
    b.setVal84(static_cast<unsigned char>(v84.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  auto v79 = e.LambdaContextDeclaration();
  if (v79) {
    auto id79 = es.EntityId(v79.value());    b.setVal79(id79);
    b.setVal136(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal136(false);
  }
  do {
    auto ov180 = e.LambdaExplicitTemplateParameters();
    if (!ov180) {
      b.setVal137(false);
      break;
    }
    b.setVal137(true);
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
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  auto v82 = e.LambdaTypeInfo();
  if (v82) {
    auto id82 = es.EntityId(v82.value());    b.setVal82(id82);
    b.setVal139(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal139(false);
  }
  auto v85 = e.MSInheritanceModel();
  if (v85) {
    b.setVal85(static_cast<unsigned char>(v85.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v182 = e.NumBases();
  if (v182) {
    b.setVal182(static_cast<unsigned>(v182.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v183 = e.NumVirtualBases();
  if (v183) {
    b.setVal183(static_cast<unsigned>(v183.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v184 = e.ODRHash();
  if (v184) {
    b.setVal184(static_cast<unsigned>(v184.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  auto v87 = e.TemplateInstantiationPattern();
  if (v87) {
    auto id87 = es.EntityId(v87.value());    b.setVal87(id87);
    b.setVal149(id87 != mx::kInvalidEntityId);
  } else {
    b.setVal87(mx::kInvalidEntityId);
    b.setVal149(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v150 = e.HasAnyDependentBases();
  if (v150) {
    b.setVal150(static_cast<bool>(v150.value()));
    b.setVal151(true);
  } else {
    b.setVal151(false);
  }
  auto v152 = e.HasConstexprDefaultConstructor();
  if (v152) {
    b.setVal152(static_cast<bool>(v152.value()));
    b.setVal153(true);
  } else {
    b.setVal153(false);
  }
  auto v154 = e.HasConstexprDestructor();
  if (v154) {
    b.setVal154(static_cast<bool>(v154.value()));
    b.setVal155(true);
  } else {
    b.setVal155(false);
  }
  auto v156 = e.HasConstexprNonCopyMoveConstructor();
  if (v156) {
    b.setVal156(static_cast<bool>(v156.value()));
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v158 = e.HasCopyAssignmentWithConstParameter();
  if (v158) {
    b.setVal158(static_cast<bool>(v158.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v163 = e.HasCopyConstructorWithConstParameter();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasDefaultConstructor();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasDefinition();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasDirectFields();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v173 = e.HasFriends();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v176 = e.HasInClassInitializer();
  if (v176) {
    b.setVal176(static_cast<bool>(v176.value()));
    b.setVal177(true);
  } else {
    b.setVal177(false);
  }
  auto v178 = e.HasInheritedAssignment();
  if (v178) {
    b.setVal178(static_cast<bool>(v178.value()));
    b.setVal179(true);
  } else {
    b.setVal179(false);
  }
  auto v185 = e.HasInheritedConstructor();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  b.setVal187(e.HasInitializerMethod());
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
  auto v127 = e.IsLocalClass();
  if (v127) {
    auto id127 = es.EntityId(v127.value());    b.setVal127(id127);
    b.setVal296(id127 != mx::kInvalidEntityId);
  } else {
    b.setVal127(mx::kInvalidEntityId);
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
    auto ov143 = e.VirtualBases();
    if (!ov143) {
      b.setVal343(false);
      break;
    }
    b.setVal343(true);
    auto v143 = std::move(*ov143);
    auto sv143 = b.initVal143(static_cast<unsigned>(v143.size()));
    auto i143 = 0u;
    for (const auto &e143 : v143) {
      sv143.set(i143, es.PseudoId(e143));
      ++i143;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t129 = e.ExternToken();
  b.setVal129(es.EntityId(t129));
  auto t130 = e.PointOfInstantiation();
  b.setVal130(es.EntityId(t130));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
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
  auto t132 = e.TemplateKeywordToken();
  b.setVal132(es.EntityId(t132));
  b.setVal133(es.EntityId(e.TypeAsWritten()));
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
    auto v47 = e.Enumerators();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
  auto v75 = e.IntegerType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal101(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal101(false);
  }
  if (auto r77 = e.IntegerTypeRange(); auto rs77 = r77.Size()) {
    b.setVal77(es.EntityId(r77[0]));
    b.setVal79(es.EntityId(r77[rs77 - 1u]));
  } else {
    b.setVal77(0);
    b.setVal79(0);
  }
  auto v144 = e.ODRHash();
  if (v144) {
    b.setVal144(static_cast<unsigned>(v144.value()));
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
  b.setVal82(es.EntityId(e.PromotionType()));
  auto v87 = e.TemplateInstantiationPattern();
  if (v87) {
    auto id87 = es.EntityId(v87.value());    b.setVal87(id87);
    b.setVal103(id87 != mx::kInvalidEntityId);
  } else {
    b.setVal87(mx::kInvalidEntityId);
    b.setVal103(false);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal104(e.IsClosed());
  b.setVal105(e.IsClosedFlag());
  b.setVal106(e.IsClosedNonFlag());
  b.setVal107(e.IsComplete());
  b.setVal108(e.IsFixed());
  b.setVal109(e.IsScoped());
  b.setVal110(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto t53 = e.EllipsisToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.TypenameToken();
  b.setVal54(es.EntityId(t54));
  auto t62 = e.UsingToken();
  b.setVal62(es.EntityId(t62));
  b.setVal70(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v53 = e.AnonymousDeclarationWithTypedefName();
  if (v53) {
    auto id53 = es.EntityId(v53.value());    b.setVal53(id53);
    b.setVal70(id53 != mx::kInvalidEntityId);
  } else {
    b.setVal53(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  b.setVal54(es.EntityId(e.TypeSourceInfo()));
  b.setVal62(es.EntityId(e.UnderlyingType()));
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
  auto v63 = e.DescribedAliasTemplate();
  if (v63) {
    auto id63 = es.EntityId(v63.value());    b.setVal63(id63);
    b.setVal78(id63 != mx::kInvalidEntityId);
  } else {
    b.setVal63(mx::kInvalidEntityId);
    b.setVal78(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t63 = e.ColonToken();
  b.setVal63(es.EntityId(t63));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t64 = e.VarianceToken();
  b.setVal64(es.EntityId(t64));
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
  b.setVal52(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal53(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal52(es.EntityId(e.ConstraintExpression()));
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
  auto t52 = e.AtToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.GetterMethodDeclaration()));
  auto t54 = e.GetterNameToken();
  b.setVal54(es.EntityId(t54));
  auto t62 = e.LParenToken();
  b.setVal62(es.EntityId(t62));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal63(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal64(es.EntityId(e.SetterMethodDeclaration()));
  auto t72 = e.SetterNameToken();
  b.setVal72(es.EntityId(t72));
  b.setVal75(es.EntityId(e.Type()));
  b.setVal69(e.IsAtomic());
  b.setVal70(e.IsClassProperty());
  b.setVal71(e.IsDirectProperty());
  b.setVal76(e.IsInstanceProperty());
  b.setVal78(e.IsOptional());
  b.setVal80(e.IsReadOnly());
  b.setVal88(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal69(e.DefinedInNSObject());
  b.setVal52(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal53(es.EntityId(e.Category()));
  b.setVal54(es.EntityId(e.ClassInterface()));
  b.setVal62(es.EntityId(e.CommandDeclaration()));
  auto t63 = e.DeclaratorEndToken();
  b.setVal63(es.EntityId(t63));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal64(es.EntityId(e.ReturnType()));
  if (auto r72 = e.ReturnTypeSourceRange(); auto rs72 = r72.Size()) {
    b.setVal72(es.EntityId(r72[0]));
    b.setVal75(es.EntityId(r72[rs72 - 1u]));
  } else {
    b.setVal72(0);
    b.setVal75(0);
  }
  auto t77 = e.SelectorStartToken();
  b.setVal77(es.EntityId(t77));
  b.setVal79(es.EntityId(e.SelfDeclaration()));
  b.setVal70(e.HasParameterDestroyedInCallee());
  b.setVal71(e.HasRedeclaration());
  b.setVal76(e.HasRelatedResultType());
  b.setVal78(e.HasSkippedBody());
  b.setVal80(e.IsClassMethod());
  b.setVal88(e.IsDefined());
  b.setVal91(e.IsDesignatedInitializerForTheInterface());
  b.setVal92(e.IsDirectMethod());
  b.setVal93(e.IsInstanceMethod());
  b.setVal94(e.IsOptional());
  b.setVal95(e.IsOverriding());
  b.setVal96(e.IsPropertyAccessor());
  b.setVal97(e.IsRedeclaration());
  b.setVal98(e.IsSynthesizedAccessorStub());
  b.setVal99(e.IsThisDeclarationADefinition());
  b.setVal100(e.IsThisDeclarationADesignatedInitializer());
  b.setVal101(e.IsVariadic());
  do {
    auto v46 = e.Parameters();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  do {
    auto v47 = e.SelectorTokens();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  pasta::DeclContext dc58(e);
  auto v58 = dc58.AlreadyLoadedDeclarations();
  auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
  auto i58 = 0u;
  for (const pasta::Decl &e58 : v58) {
    sv58.set(i58, es.EntityId(e58));
    ++i58;
  }
}

void SerializeObjCContainerDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v46 = e.ClassMethods();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  do {
    auto v47 = e.ClassProperties();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  if (auto r52 = e.AtEndRange(); auto rs52 = r52.Size()) {
    b.setVal52(es.EntityId(r52[0]));
    b.setVal53(es.EntityId(r52[rs52 - 1u]));
  } else {
    b.setVal52(0);
    b.setVal53(0);
  }
  auto t54 = e.AtStartToken();
  b.setVal54(es.EntityId(t54));
  do {
    auto v58 = e.InstanceMethods();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
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
    auto v317 = e.Properties();
    auto sv317 = b.initVal317(static_cast<unsigned>(v317.size()));
    auto i317 = 0u;
    for (const auto &e317 : v317) {
      sv317.set(i317, es.EntityId(e317));
      ++i317;
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
  b.setVal69(e.IsClassExtension());
  auto t62 = e.CategoryNameToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.ClassInterface()));
  b.setVal64(es.EntityId(e.Implementation()));
  auto t72 = e.InstanceVariableLBraceToken();
  b.setVal72(es.EntityId(t72));
  auto t75 = e.InstanceVariableRBraceToken();
  b.setVal75(es.EntityId(t75));
  b.setVal77(es.EntityId(e.NextClassCategory()));
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
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal69(e.HasDefinition());
  b.setVal70(e.IsNonRuntimeProtocol());
  b.setVal71(e.IsThisDeclarationADefinition());
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
  b.setVal69(e.DeclaresOrInheritsDesignatedInitializers());
  auto t62 = e.EndOfDefinitionToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.Implementation()));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto v64 = e.SuperClass();
  if (v64) {
    auto id64 = es.EntityId(v64.value());    b.setVal64(id64);
    b.setVal70(id64 != mx::kInvalidEntityId);
  } else {
    b.setVal64(mx::kInvalidEntityId);
    b.setVal70(false);
  }
  auto t72 = e.SuperClassToken();
  b.setVal72(es.EntityId(t72));
  auto v75 = e.SuperClassTypeInfo();
  if (v75) {
    auto id75 = es.EntityId(v75.value());    b.setVal75(id75);
    b.setVal71(id75 != mx::kInvalidEntityId);
  } else {
    b.setVal75(mx::kInvalidEntityId);
    b.setVal71(false);
  }
  b.setVal77(es.EntityId(e.TypeForDeclaration()));
  b.setVal76(e.HasDefinition());
  b.setVal78(e.HasDesignatedInitializers());
  b.setVal80(e.IsArcWeakrefUnavailable());
  b.setVal88(e.IsImplicitInterfaceDeclaration());
  b.setVal79(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal91(e.IsThisDeclarationADefinition());
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
  b.setVal62(es.EntityId(e.ClassInterface()));
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
  b.setVal63(es.EntityId(e.CategoryDeclaration()));
  auto t64 = e.CategoryNameToken();
  b.setVal64(es.EntityId(t64));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t63 = e.InstanceVariableLBraceToken();
  b.setVal63(es.EntityId(t63));
  auto t64 = e.InstanceVariableRBraceToken();
  b.setVal64(es.EntityId(t64));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal72(es.EntityId(e.SuperClass()));
  auto t75 = e.SuperClassToken();
  b.setVal75(es.EntityId(t75));
  b.setVal69(e.HasDestructors());
  b.setVal70(e.HasNonZeroConstructors());
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
  b.setVal52(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeNamespaceAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t52 = e.AliasToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.AliasedNamespace()));
  auto t54 = e.NamespaceToken();
  b.setVal54(es.EntityId(t54));
  auto t62 = e.TargetNameToken();
  b.setVal62(es.EntityId(t62));
}

void SerializeLinkageSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v46 = e.ChildrenExpression();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal44(es.EntityId(e.ExtendingDeclaration()));
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal52(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v46 = e.IdentifierTokens();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
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
  auto v44 = e.FriendDeclaration();
  if (v44) {
    auto id44 = es.EntityId(v44.value());    b.setVal44(id44);
    b.setVal45(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal45(false);
  }
  auto t52 = e.FriendToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.FriendType()));
  b.setVal48(e.IsUnsupportedFriend());
  do {
    auto v74 = e.FriendTypeTemplateParameterLists();
    auto sv74 = b.initVal74(static_cast<unsigned>(v74.size()));
    auto i74 = 0u;
    for (const auto &e74 : v74) {
      sv74.set(i74, es.PseudoId(e74));
      ++i74;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.AssemblyToken();
  b.setVal44(es.EntityId(t44));
  b.setVal52(es.EntityId(e.AssemblyString()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.ExportToken();
  b.setVal44(es.EntityId(t44));
  auto t52 = e.RBraceToken();
  b.setVal52(es.EntityId(t52));
  b.setVal45(e.HasBraces());
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
