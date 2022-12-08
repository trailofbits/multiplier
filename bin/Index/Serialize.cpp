// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Serialize.h"

#include <multiplier/RPC.capnp.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include <glog/logging.h>
#include "EntityMapper.h"
#include "PASTA.h"
#include "Util.h"
namespace indexer {

void SerializeDesignator(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::Designator &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kDesignator));
  b.setVal1(e.IsFieldDesignator());
  b.setVal2(e.IsArrayDesignator());
  b.setVal3(e.IsArrayRangeDesignator());
  auto v4 = e.Field();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
    b.setVal5(id4 != mx::kInvalidEntityId);
  } else {
    b.setVal4(mx::kInvalidEntityId);
    b.setVal5(false);
  }
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal7(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal7(0);
  }
  auto t8 = e.DotToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.FieldToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.LeftBracketToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.RightBracketToken();
  b.setVal11(es.EntityId(t11));
  auto t12 = e.EllipsisToken();
  b.setVal12(es.EntityId(t12));
  auto v13 = e.FirstExpressionIndex();
  if (v13) {
    b.setVal13(static_cast<unsigned>(v13.value()));
    b.setVal14(true);
  } else {
    b.setVal14(false);
  }
}

void SerializeTemplateParameterList(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateParameterList));
  b.setVal13(e.NumParameters());
  b.setVal15(e.NumRequiredParameters());
  b.setVal16(e.Depth());
  b.setVal1(e.HasUnexpandedParameterPack());
  b.setVal2(e.HasParameterPack());
  auto v4 = e.RequiresClause();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
    b.setVal3(id4 != mx::kInvalidEntityId);
  } else {
    b.setVal4(mx::kInvalidEntityId);
    b.setVal3(false);
  }
  auto t6 = e.TemplateKeywordToken();
  b.setVal6(es.EntityId(t6));
  auto t7 = e.LeftAngleToken();
  b.setVal7(es.EntityId(t7));
  auto t8 = e.RightAngleToken();
  b.setVal8(es.EntityId(t8));
  if (auto r9 = e.Tokens(); auto rs9 = r9.Size()) {
    b.setVal9(es.EntityId(r9[0]));
    b.setVal10(es.EntityId(r9[rs9 - 1u]));
  } else {
    b.setVal9(0);
    b.setVal10(0);
  }
  do {
    auto v17 = e.Parameters();
    auto sv17 = b.initVal17(static_cast<unsigned>(v17.size()));
    auto i17 = 0u;
    for (const auto &e17 : v17) {
      sv17.set(i17, es.EntityId(e17));
      ++i17;
    }
  } while (false);
}

void SerializeTemplateArgument(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateArgument));
  b.setVal18(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal1(e.IsNull());
  b.setVal2(e.IsDependent());
  b.setVal3(e.IsInstantiationDependent());
  b.setVal5(e.ContainsUnexpandedParameterPack());
  b.setVal14(e.IsPackExpansion());
  auto v4 = e.AsDeclaration();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
    b.setVal19(id4 != mx::kInvalidEntityId);
  } else {
    b.setVal4(mx::kInvalidEntityId);
    b.setVal19(false);
  }
  auto v6 = e.AsType();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
    b.setVal20(id6 != mx::kInvalidEntityId);
  } else {
    b.setVal6(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto v7 = e.ParameterTypeForDeclaration();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
    b.setVal21(id7 != mx::kInvalidEntityId);
  } else {
    b.setVal7(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  auto v8 = e.NullPointerType();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
    b.setVal22(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal22(false);
  }
}

void SerializeCXXBaseSpecifier(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kCXXBaseSpecifier));
  if (auto r4 = e.Tokens(); auto rs4 = r4.Size()) {
    b.setVal4(es.EntityId(r4[0]));
    b.setVal6(es.EntityId(r4[rs4 - 1u]));
  } else {
    b.setVal4(0);
    b.setVal6(0);
  }
  auto t7 = e.BaseTypeToken();
  b.setVal7(es.EntityId(t7));
  b.setVal1(e.IsVirtual());
  b.setVal18(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal2(e.IsPackExpansion());
  b.setVal3(e.ConstructorsAreInherited());
  auto v8 = e.EllipsisToken();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
    b.setVal5(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal5(false);
  }
  b.setVal23(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal24(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal9(es.EntityId(e.BaseType()));
}

void SerializeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  auto t0 = e.Token();
  b.setVal0(es.EntityId(t0));
  b.setVal1(e.IsImplicit());
  b.setVal2(e.IsInherited());
  b.setVal3(e.IsLateParsed());
  b.setVal4(e.IsPackExpansion());
  b.setVal5(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal7(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal7(0);
  }
}

void SerializeAlignValueAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignValueAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal8(es.EntityId(e.Alignment()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAliasAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeAbiTagAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AbiTagAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
}

void SerializeSPtrAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SPtrAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtr64Attr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr64Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtr32Attr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr32Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLPrivateAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLPrivateAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLLocalAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLLocalAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalHostAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalHostAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalDeviceAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalDeviceAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGenericAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGenericAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLConstantAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLConstantAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCKindOfAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCKindOfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCInertUnsafeUnretainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCInertUnsafeUnretainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCGCAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCGCAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDerefAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDerefAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCmseNSCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBTFTypeTagAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFTypeTagAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.BTFTypeTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeArmMveStrictPolymorphismAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmMveStrictPolymorphismAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnnotateTypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeAddressSpaceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUPtrAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UPtrAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullableResultAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullUnspecifiedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullUnspecifiedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNonNullAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeThreadAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThreadAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftObjCMembersAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftObjCMembersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStmtAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StmtAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
}

void SerializeOpenCLUnrollHintAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLUnrollHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMustTailAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MustTailAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLikelyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LikelyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFallThroughAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FallThroughAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnlikelyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnlikelyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSuppressAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SuppressAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRenderScriptKernelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RenderScriptKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOverloadableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverloadableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLAccessAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLAccessAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal12(e.IsReadOnly());
  b.setVal13(e.IsReadWrite());
  b.setVal14(e.IsWriteOnly());
}

void SerializeObjCRuntimeVisibleAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeVisibleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRuntimeNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.MetadataName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeObjCNonRuntimeProtocolAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonRuntimeProtocolAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNonLazyClassAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonLazyClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDirectMembersAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectMembersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDirectAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDesignatedInitializerAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDesignatedInitializerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCClassStubAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCClassStubAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBoxableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBoxableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPReferencedVarAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPReferencedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal8(es.EntityId(e.Reference()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPDeclareSimdDeclAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareSimdDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.BranchState())));
  b.setVal8(es.EntityId(e.Simdlen()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPCaptureKindAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureKindAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoEscapeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoEscapeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoBuiltinAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoBuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeModeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ModeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLoopHintAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoopHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Option())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal16(static_cast<unsigned char>(mx::FromPasta(e.State())));
  b.setVal8(es.EntityId(e.Value()));
}

void SerializeLoaderUninitializedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoaderUninitializedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInitSegAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitSegAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Section();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeInheritableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal12(e.ShouldInheritEvenIfAlreadyPresent());
}

void SerializeIBOutletCollectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletCollectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Interface()));
  b.setVal17(es.EntityId(e.InterfaceToken()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIBOutletAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIBActionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBActionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHotAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HotAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHLSLShaderAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLShaderAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeHLSLSV_GroupIndexAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_GroupIndexAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHLSLNumThreadsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLNumThreadsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHIPManagedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HIPManagedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGuardedVarAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGuardedByAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedByAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGNUInlineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GNUInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFunctionReturnThunksAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FunctionReturnThunksAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ThunkType())));
}

void SerializeFormatAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFormatArgAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatArgAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFlattenAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlattenAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFlagEnumAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlagEnumAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFinalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FinalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsSpelledAsSealed());
}

void SerializeFastCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FastCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeExternalSourceSymbolAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExternalSourceSymbolAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.DefinedIn();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.GeneratedDeclaration());
  auto v10 = e.Language();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  auto v18 = e.Spelling();
  std::string s18(v18.data(), v18.size());
  b.setVal18(s18);
}

void SerializeExclusiveTrylockFunctionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExclusiveTrylockFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeExcludeFromExplicitInstantiationAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExcludeFromExplicitInstantiationAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeErrorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ErrorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.UserDiagnostic();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  b.setVal13(e.IsError());
  b.setVal14(e.IsWarning());
}

void SerializeEnumExtensibilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnumExtensibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Extensibility())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnforceTCBLeafAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBLeafAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.TCBName();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeEnforceTCBAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.TCBName();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeEnableIfAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnableIfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Condition()));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeEmptyBasesAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EmptyBasesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDisableTailCallsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableTailCallsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDisableSanitizerInstrumentationAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableSanitizerInstrumentationAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDiagnoseIfAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseIfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.ArgumentDependent());
  b.setVal8(es.EntityId(e.Condition()));
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.DiagnosticType())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal17(es.EntityId(e.Parent()));
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  b.setVal14(e.IsError());
  b.setVal19(e.IsWarning());
}

void SerializeDiagnoseAsBuiltinAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseAsBuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Function()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDestructorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DestructorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDeprecatedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeprecatedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Replacement();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  auto v18 = e.Spelling();
  std::string s18(v18.data(), v18.size());
  b.setVal18(s18);
}

void SerializeDeclOrStmtAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeclOrStmtAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
}

void SerializeAlwaysInlineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsClangAlwaysInline());
}

void SerializeNoMergeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMergeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoInlineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsClangNoInline());
}

void SerializeDLLImportStaticLocalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportStaticLocalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLImportAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLExportStaticLocalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportStaticLocalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLExportAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConvergentAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConvergentAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableSetOnReadAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableSetOnReadAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableAutoCastAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAutoCastAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.DefaultState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConstructorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstructorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConstInitAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstInitAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsConstinit());
}

void SerializeConstAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCommonAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CommonAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeColdAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ColdAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCodeSegAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeSegAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeCmseNSEntryAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSEntryAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCleanupAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CleanupAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.FunctionDeclaration()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCapturedRecordAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapturedRecordAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  b.setVal13(e.IsShared());
}

void SerializeCallbackAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallbackAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCallableWhenAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallableWhenAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCXX11NoReturnAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CXX11NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDASharedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDASharedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDALaunchBoundsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDALaunchBoundsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.MaxThreads()));
  b.setVal17(es.EntityId(e.MinBlocks()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAInvalidTargetAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAInvalidTargetAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAHostAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAHostAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAGlobalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAGlobalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceBuiltinTextureTypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinTextureTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceBuiltinSurfaceTypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinSurfaceTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAConstantAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAConstantAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCPUSpecificAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUSpecificAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCPUDispatchAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUDispatchAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFUnknownTransferAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFUnknownTransferAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFReturnsRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFReturnsNotRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFICanonicalJumpTableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFICanonicalJumpTableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFGuardAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFGuardAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Guard())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFAuditedTransferAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFAuditedTransferAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCDeclAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeC11NoReturnAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::C11NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBuiltinAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBlocksAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BlocksAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeBTFDeclTagAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFDeclTagAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.BTFDeclTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeBPFPreserveAccessIndexAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BPFPreserveAccessIndexAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAvailabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AvailabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Replacement();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  auto v18 = e.Spelling();
  std::string s18(v18.data(), v18.size());
  b.setVal18(s18);
  b.setVal13(e.Strict());
  b.setVal14(e.Unavailable());
}

void SerializeAssumptionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumptionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Assumption();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeAssumeAlignedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumeAlignedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Alignment()));
  auto v17 = e.Offset();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
    b.setVal13(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssertSharedLockAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertSharedLockAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssertExclusiveLockAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertExclusiveLockAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssertCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertCapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsShared());
}

void SerializeAsmLabelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AsmLabelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.IsLiteralLabel());
  auto v9 = e.Label();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeArtificialAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArtificialAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArmBuiltinAliasAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmBuiltinAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArgumentWithTypeTagAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArgumentWithTypeTagAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.IsPointer());
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArcWeakrefUnavailableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArcWeakrefUnavailableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86NoCfCheckAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCfCheckAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86NoCallerSavedRegistersAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCallerSavedRegistersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86InterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86InterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnalyzerNoReturnAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnalyzerNoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlwaysDestroyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysDestroyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAllocSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAllocAlignAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocAlignAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlignedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v8 = e.AlignmentExpression();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
    b.setVal13(id8 != mx::kInvalidEntityId);
  } else {
    b.setVal8(mx::kInvalidEntityId);
    b.setVal13(false);
  }
  auto v17 = e.AlignmentType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
    b.setVal14(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal19(e.IsAlignas());
  b.setVal20(e.IsAlignmentDependent());
  b.setVal21(e.IsAlignmentErrorDependent());
  b.setVal22(e.IsAlignmentExpression());
  b.setVal23(e.IsC11());
  b.setVal24(e.IsDeclspec());
  b.setVal25(e.IsGNU());
}

void SerializeAlignNaturalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignNaturalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlignMac68kAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignMac68kAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquiredBeforeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredBeforeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquiredAfterAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredAfterAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquireHandleAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireHandleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeAcquireCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireCapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsShared());
}

void SerializeAVRSignalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRSignalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAVRInterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeARMInterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ARMInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUWavesPerEUAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUWavesPerEUAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal17(es.EntityId(e.Min()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUNumVGPRAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumVGPRAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUNumSGPRAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumSGPRAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUKernelCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUKernelCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUFlatWorkGroupSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUFlatWorkGroupSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal17(es.EntityId(e.Min()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAArch64VectorPcsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64VectorPcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAArch64SVEPcsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64SVEPcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeZeroCallUsedRegsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ZeroCallUsedRegsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ZeroCallUsedRegs())));
}

void SerializeXRayLogArgsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayLogArgsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeXRayInstrumentAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayInstrumentAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.AlwaysXRayInstrument());
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal14(e.NeverXRayInstrument());
}

void SerializeX86ForceAlignArgPointerAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::X86ForceAlignArgPointerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWorkGroupSizeHintAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WorkGroupSizeHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyImportNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.ImportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeWebAssemblyImportModuleAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportModuleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.ImportModule();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeWebAssemblyExportNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyExportNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.ExportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeWeakRefAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakRefAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeWeakImportAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakImportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWarnUnusedResultAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.IsCXX11NoDiscard());
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeWarnUnusedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeVisibilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VisibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeVectorCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VectorCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeVecTypeHintAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecTypeHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.TypeHint()));
  b.setVal17(es.EntityId(e.TypeHintToken()));
}

void SerializeVecReturnAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUuidAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UuidAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Guid();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.GuidDeclaration()));
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeUsingIfExistsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsingIfExistsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUsedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnusedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnusedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUninitializedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UninitializedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnavailableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnavailableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ImplicitReason())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeTypeVisibilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeVisibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeTypeTagForDatatypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeTagForDatatypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.LayoutCompatible());
  b.setVal8(es.EntityId(e.MatchingCType()));
  b.setVal17(es.EntityId(e.MatchingCTypeToken()));
  b.setVal14(e.MustBeNull());
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTryAcquireCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TryAcquireCapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.SuccessValue()));
  b.setVal13(e.IsShared());
}

void SerializeTrivialABIAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TrivialABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTransparentUnionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TransparentUnionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeThisCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThisCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTestTypestateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TestTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.TestState())));
}

void SerializeTargetClonesAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetClonesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTargetAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Architecture();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.FeaturesString();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
  auto v18 = e.Spelling();
  std::string s18(v18.data(), v18.size());
  b.setVal18(s18);
  b.setVal13(e.IsDefaultVersion());
}

void SerializeTLSModelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TLSModelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Model();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeSysVABIAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SysVABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftPrivateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftPrivateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftNewTypeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNewTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.NewtypeKind())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeSwiftErrorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftBridgedTypedefAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgedTypedefAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftBridgeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.SwiftType();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeSwiftAttrAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAttrAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Attribute();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeSwiftAsyncNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeSwiftAsyncErrorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncErrorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStrictFPAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictFPAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStdCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StdCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStandaloneDebugAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StandaloneDebugAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSpeculativeLoadHardeningAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SpeculativeLoadHardeningAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSharedTrylockFunctionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SharedTrylockFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeSetTypestateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SetTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.NewState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSentinelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SentinelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSelectAnyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SelectAnyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeScopedLockableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ScopedLockableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSYCLSpecialClassAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLSpecialClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSYCLKernelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnsTwiceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsTwiceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnsNonNullAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsNonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnTypestateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.State())));
}

void SerializeRetainAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RetainAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRestrictAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RestrictAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRequiresCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RequiresCapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsShared());
}

void SerializeReqdWorkGroupSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReqdWorkGroupSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReleaseCapabilityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseCapabilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsGeneric());
  b.setVal14(e.IsShared());
}

void SerializeReinitializesAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReinitializesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRegCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RegCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRandomizeLayoutAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RandomizeLayoutAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRISCVInterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RISCVInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePureAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PureAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtGuardedVarAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtGuardedByAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedByAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreserveMostAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveMostAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreserveAllAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveAllAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreferredNameAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredNameAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.TypedefType()));
  b.setVal17(es.EntityId(e.TypedefTypeToken()));
}

void SerializePragmaClangTextSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangTextSectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePragmaClangRodataSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRodataSectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePragmaClangRelroSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRelroSectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePragmaClangDataSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangDataSectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePragmaClangBSSSectionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangBSSSectionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePointerAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PointerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal17(es.EntityId(e.DerefTypeToken()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePcsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.PCS())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePatchableFunctionEntryAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PatchableFunctionEntryAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePascalAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PascalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeParamTypestateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParamTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ParameterState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePackedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PackedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOwnershipAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnershipAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.OwnKind())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsHolds());
  b.setVal14(e.IsReturns());
  b.setVal19(e.IsTakes());
}

void SerializeOwnerAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal17(es.EntityId(e.DerefTypeToken()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOverrideAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverrideAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOptimizeNoneAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OptimizeNoneAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLKernelAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLIntelReqdSubGroupSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLIntelReqdSubGroupSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCSubclassingRestrictedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCSubclassingRestrictedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRootClassAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRootClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCReturnsInnerPointerAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCReturnsInnerPointerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRequiresSuperAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresSuperAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRequiresPropertyDefsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresPropertyDefsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCPreciseLifetimeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCPreciseLifetimeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCOwnershipAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCOwnershipAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNSObjectAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNSObjectAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCMethodFamilyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCMethodFamilyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Family())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCIndependentClassAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCIndependentClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExternallyRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExternallyRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExplicitProtocolImplAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExplicitProtocolImplAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExceptionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExceptionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeRelatedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeRelatedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeMutableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeMutableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedOnZeroAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnZeroAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedOnNonZeroAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnNonZeroAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsNotRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSConsumesThisAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumesThisAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPThreadPrivateDeclAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPThreadPrivateDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPDeclareVariantAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareVariantAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.VariantFuncReference()));
}

void SerializeOMPDeclareTargetDeclAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareTargetDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.DevType())));
  b.setVal13(e.Indirect());
  b.setVal8(es.EntityId(e.IndirectExpression()));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.MapType())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPCaptureNoInitAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureNoInitAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPAllocateDeclAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPAllocateDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Alignment()));
  b.setVal17(es.EntityId(e.Allocator()));
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.AllocatorType())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNotTailCalledAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NotTailCalledAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoUniqueAddressAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUniqueAddressAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoThrowAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThrowAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoThreadSafetyAnalysisAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThreadSafetyAnalysisAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoStackProtectorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoStackProtectorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSplitStackAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSplitStackAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSpeculativeLoadHardeningAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSpeculativeLoadHardeningAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSanitizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSanitizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.HasCoverage());
}

void SerializeNoReturnAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoRandomizeLayoutAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoRandomizeLayoutAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoProfileFunctionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoProfileFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoMips16Attr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMips16Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoMicroMipsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMicroMipsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoInstrumentFunctionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInstrumentFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDuplicateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDuplicateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDestroyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDestroyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDebugAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDebugAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoCommonAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoCommonAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoAliasAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNakedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NakedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsNotRetainedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsAutoreleasedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsAutoreleasedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSErrorDomainAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSErrorDomainAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.ErrorDomain()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSConsumesSelfAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumesSelfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsShortCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsShortCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsLongCallAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsLongCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsInterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMips16Attr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Mips16Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMinVectorWidthAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinVectorWidthAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMinSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMicroMipsAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MicroMipsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMayAliasAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MayAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMaxFieldAlignmentAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaxFieldAlignmentAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSVtorDispAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSVtorDispAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.VtorDispMode())));
}

void SerializeMSStructAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSStructAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSP430InterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSP430InterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSNoVTableAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSNoVTableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSInheritanceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSInheritanceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal13(e.BestCase());
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.InheritanceModel())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSAllocatorAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSAllocatorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSABIAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMIGServerRoutineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MIGServerRoutineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeM68kInterruptAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::M68kInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLocksExcludedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LocksExcludedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLockReturnedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LockReturnedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLifetimeBoundAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LifetimeBoundAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLeafAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LeafAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLayoutVersionAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LayoutVersionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLTOVisibilityPublicAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LTOVisibilityPublicAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInternalLinkageAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InternalLinkageAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIntelOclBiccAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IntelOclBiccAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInitPriorityAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitPriorityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInheritableParamAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableParamAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
}

void SerializeCarriesDependencyAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CarriesDependencyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFConsumedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnnotateAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeUseHandleAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UseHandleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeReleaseHandleAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseHandleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializePassObjectSizeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PassObjectSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsDynamic());
}

void SerializeParameterABIAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParameterABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ABI())));
}

void SerializeSwiftIndirectResultAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftIndirectResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftErrorResultAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftContextAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftContextAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncContextAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncContextAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSConsumedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNonNullAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSConsumedAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIFuncAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IFuncAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Resolver();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v10 = e.Spelling();
  std::string s10(v10.data(), v10.size());
  b.setVal10(s10);
}

void SerializeCalledOnceAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CalledOnceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBuiltinAliasAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
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
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
    b.setVal8(id7 != mx::kInvalidEntityId);
  } else {
    b.setVal7(mx::kInvalidEntityId);
    b.setVal8(false);
  }
  auto v9 = e.AsCXXRecordDeclaration();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
    b.setVal10(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal10(false);
  }
  auto v11 = e.AsComplexIntegerType();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.AsObjCInterfacePointerType();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
    b.setVal14(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  auto v15 = e.AsObjCInterfaceType();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
    b.setVal16(id15 != mx::kInvalidEntityId);
  } else {
    b.setVal15(mx::kInvalidEntityId);
    b.setVal16(false);
  }
  auto v17 = e.AsObjCQualifiedClassType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
    b.setVal18(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal18(false);
  }
  auto v19 = e.AsObjCQualifiedIdType();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
    b.setVal20(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto v21 = e.AsObjCQualifiedInterfaceType();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
    b.setVal22(id21 != mx::kInvalidEntityId);
  } else {
    b.setVal21(mx::kInvalidEntityId);
    b.setVal22(false);
  }
  auto v23 = e.AsPlaceholderType();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
    b.setVal24(id23 != mx::kInvalidEntityId);
  } else {
    b.setVal23(mx::kInvalidEntityId);
    b.setVal24(false);
  }
  auto v25 = e.AsRecordDeclaration();
  if (v25) {
    auto id25 = es.EntityId(v25.value());
    b.setVal25(id25);
    b.setVal26(id25 != mx::kInvalidEntityId);
  } else {
    b.setVal25(mx::kInvalidEntityId);
    b.setVal26(false);
  }
  auto v27 = e.AsStructureType();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
    b.setVal28(id27 != mx::kInvalidEntityId);
  } else {
    b.setVal27(mx::kInvalidEntityId);
    b.setVal28(false);
  }
  auto v29 = e.AsTagDeclaration();
  if (v29) {
    auto id29 = es.EntityId(v29.value());
    b.setVal29(id29);
    b.setVal30(id29 != mx::kInvalidEntityId);
  } else {
    b.setVal29(mx::kInvalidEntityId);
    b.setVal30(false);
  }
  auto v31 = e.AsUnionType();
  if (v31) {
    auto id31 = es.EntityId(v31.value());
    b.setVal31(id31);
    b.setVal32(id31 != mx::kInvalidEntityId);
  } else {
    b.setVal31(mx::kInvalidEntityId);
    b.setVal32(false);
  }
  auto v33 = e.ContainedAutoType();
  if (v33) {
    auto id33 = es.EntityId(v33.value());
    b.setVal33(id33);
    b.setVal34(id33 != mx::kInvalidEntityId);
  } else {
    b.setVal33(mx::kInvalidEntityId);
    b.setVal34(false);
  }
  auto v35 = e.ContainedDeducedType();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
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
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
    b.setVal42(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal42(false);
  }
  auto v43 = e.PointeeOrArrayElementType();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal44(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal44(false);
  }
  auto v45 = e.PointeeType();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
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
    auto id49 = es.EntityId(v49.value());
    b.setVal49(id49);
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
  b.setVal102(e.IsExtVectorBooleanType());
  b.setVal103(e.IsExtVectorType());
  b.setVal104(e.IsFixedPointOrIntegerType());
  b.setVal105(e.IsFixedPointType());
  b.setVal106(e.IsFloat128Type());
  b.setVal107(e.IsFloat16Type());
  b.setVal108(e.IsFloatingType());
  b.setVal109(e.IsFromAST());
  b.setVal110(e.IsFunctionNoProtoType());
  b.setVal111(e.IsFunctionPointerType());
  b.setVal112(e.IsFunctionProtoType());
  b.setVal113(e.IsFunctionReferenceType());
  b.setVal114(e.IsFunctionType());
  b.setVal115(e.IsFundamentalType());
  b.setVal116(e.IsHalfType());
  b.setVal117(e.IsIbm128Type());
  b.setVal118(e.IsImageType());
  b.setVal119(e.IsIncompleteArrayType());
  b.setVal120(e.IsIncompleteOrObjectType());
  b.setVal121(e.IsIncompleteType());
  b.setVal122(e.IsInstantiationDependentType());
  b.setVal123(e.IsIntegerType());
  b.setVal124(e.IsIntegralOrEnumerationType());
  b.setVal125(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal126(e.IsIntegralType());
  b.setVal127(e.IsInterfaceType());
  b.setVal128(e.IsLValueReferenceType());
  b.setVal129(e.IsLinkageValid());
  auto v130 = e.IsLiteralType();
  if (v130) {
    b.setVal130(static_cast<bool>(v130.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  b.setVal132(e.IsMatrixType());
  b.setVal133(e.IsMemberDataPointerType());
  b.setVal134(e.IsMemberFunctionPointerType());
  b.setVal135(e.IsMemberPointerType());
  b.setVal136(e.IsNonOverloadPlaceholderType());
  b.setVal137(e.IsNothrowT());
  b.setVal138(e.IsNullPointerType());
  b.setVal139(e.IsOCLExtOpaqueType());
  b.setVal140(e.IsOCLImage1dArrayROType());
  b.setVal141(e.IsOCLImage1dArrayRWType());
  b.setVal142(e.IsOCLImage1dArrayWOType());
  b.setVal143(e.IsOCLImage1dBufferROType());
  b.setVal144(e.IsOCLImage1dBufferRWType());
  b.setVal145(e.IsOCLImage1dBufferWOType());
  b.setVal146(e.IsOCLImage1dROType());
  b.setVal147(e.IsOCLImage1dRWType());
  b.setVal148(e.IsOCLImage1dWOType());
  b.setVal149(e.IsOCLImage2dArrayDepthROType());
  b.setVal150(e.IsOCLImage2dArrayDepthRWType());
  b.setVal151(e.IsOCLImage2dArrayDepthWOType());
  b.setVal152(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal153(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal154(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal155(e.IsOCLImage2dArrayMSAAROType());
  b.setVal156(e.IsOCLImage2dArrayMSAARWType());
  b.setVal157(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal158(e.IsOCLImage2dArrayROType());
  b.setVal159(e.IsOCLImage2dArrayRWType());
  b.setVal160(e.IsOCLImage2dArrayWOType());
  b.setVal161(e.IsOCLImage2dDepthROType());
  b.setVal162(e.IsOCLImage2dDepthRWType());
  b.setVal163(e.IsOCLImage2dDepthWOType());
  b.setVal164(e.IsOCLImage2dMSAADepthROType());
  b.setVal165(e.IsOCLImage2dMSAADepthRWType());
  b.setVal166(e.IsOCLImage2dMSAADepthWOType());
  b.setVal167(e.IsOCLImage2dMSAAROType());
  b.setVal168(e.IsOCLImage2dMSAARWType());
  b.setVal169(e.IsOCLImage2dMSAAWOType());
  b.setVal170(e.IsOCLImage2dROType());
  b.setVal171(e.IsOCLImage2dRWType());
  b.setVal172(e.IsOCLImage2dWOType());
  b.setVal173(e.IsOCLImage3dROType());
  b.setVal174(e.IsOCLImage3dRWType());
  b.setVal175(e.IsOCLImage3dWOType());
  b.setVal176(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal177(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal178(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal179(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal180(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal181(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal182(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal183(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal184(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal185(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal186(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal187(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal188(e.IsOCLIntelSubgroupAVCType());
  b.setVal189(e.IsObjCARCBridgableType());
  auto v190 = e.IsObjCARCImplicitlyUnretainedType();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  b.setVal192(e.IsObjCBoxableRecordType());
  b.setVal193(e.IsObjCBuiltinType());
  b.setVal194(e.IsObjCClassOrClassKindOfType());
  b.setVal195(e.IsObjCClassType());
  b.setVal196(e.IsObjCIdType());
  b.setVal197(e.IsObjCIndependentClassType());
  b.setVal198(e.IsObjCIndirectLifetimeType());
  b.setVal199(e.IsObjCInertUnsafeUnretainedType());
  b.setVal200(e.IsObjCLifetimeType());
  b.setVal201(e.IsObjCNSObjectType());
  b.setVal202(e.IsObjCObjectOrInterfaceType());
  b.setVal203(e.IsObjCObjectPointerType());
  b.setVal204(e.IsObjCObjectType());
  b.setVal205(e.IsObjCQualifiedClassType());
  b.setVal206(e.IsObjCQualifiedIdType());
  b.setVal207(e.IsObjCQualifiedInterfaceType());
  b.setVal208(e.IsObjCRetainableType());
  b.setVal209(e.IsObjCSelType());
  b.setVal210(e.IsObjectPointerType());
  b.setVal211(e.IsObjectType());
  b.setVal212(e.IsOpenCLSpecificType());
  b.setVal213(e.IsOverloadableType());
  b.setVal214(e.IsPipeType());
  b.setVal215(e.IsPlaceholderType());
  b.setVal216(e.IsPointerType());
  b.setVal217(e.IsPromotableIntegerType());
  b.setVal218(e.IsQueueT());
  b.setVal219(e.IsRValueReferenceType());
  b.setVal220(e.IsRealFloatingType());
  b.setVal221(e.IsRealType());
  b.setVal222(e.IsRecordType());
  b.setVal223(e.IsReferenceType());
  b.setVal224(e.IsReserveIDT());
  b.setVal225(e.IsSamplerT());
  b.setVal226(e.IsSaturatedFixedPointType());
  b.setVal227(e.IsScalarType());
  b.setVal228(e.IsScopedEnumeralType());
  b.setVal229(e.IsSignedFixedPointType());
  b.setVal230(e.IsSignedIntegerOrEnumerationType());
  b.setVal231(e.IsSignedIntegerType());
  b.setVal232(e.IsSizelessBuiltinType());
  b.setVal233(e.IsSizelessType());
  b.setVal234(e.IsSpecifierType());
  auto v235 = e.IsStandardLayoutType();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  b.setVal237(e.IsStdByteType());
  auto v238 = e.IsStructuralType();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  b.setVal240(e.IsStructureOrClassType());
  b.setVal241(e.IsStructureType());
  b.setVal242(e.IsTemplateTypeParmType());
  b.setVal243(e.IsTypedefNameType());
  b.setVal244(e.IsUndeducedAutoType());
  b.setVal245(e.IsUndeducedType());
  b.setVal246(e.IsUnionType());
  b.setVal247(e.IsUnsaturatedFixedPointType());
  b.setVal248(e.IsUnscopedEnumerationType());
  b.setVal249(e.IsUnsignedFixedPointType());
  b.setVal250(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal251(e.IsUnsignedIntegerType());
  b.setVal252(e.IsVLSTBuiltinType());
  b.setVal253(e.IsVariableArrayType());
  b.setVal254(e.IsVariablyModifiedType());
  b.setVal255(e.IsVectorType());
  b.setVal256(e.IsVisibilityExplicit());
  b.setVal257(e.IsVoidPointerType());
  b.setVal258(e.IsVoidType());
  b.setVal259(e.IsWideCharacterType());
  b.setVal260(es.EntityId(e.IgnoreParentheses()));
  b.setVal261(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal262(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal263(es.EntityId(e.CanonicalType()));
  b.setVal264(es.EntityId(e.DesugaredType()));
  b.setVal265(es.EntityId(e.LocalUnqualifiedType()));
  b.setVal266(es.EntityId(e.NonLValueExpressionType()));
  b.setVal267(es.EntityId(e.NonPackExpansionType()));
  b.setVal268(es.EntityId(e.NonReferenceType()));
  b.setVal269(es.EntityId(e.SingleStepDesugaredType()));
  b.setVal270(e.HasAddressSpace());
  b.setVal271(e.HasLocalNonFastQualifiers());
  b.setVal272(e.HasLocalQualifiers());
  b.setVal273(e.HasNonTrivialObjCLifetime());
  b.setVal274(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal275(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal276(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal277(e.HasQualifiers());
  b.setVal278(e.HasStrongOrWeakObjCLifetime());
  b.setVal279(e.IsCForbiddenLValueType());
  b.setVal280(e.IsCXX11PODType());
  b.setVal281(e.IsCXX98PODType());
  b.setVal282(e.IsCanonical());
  b.setVal283(e.IsCanonicalAsParameter());
  b.setVal284(e.IsConstQualified());
  b.setVal285(e.IsConstant());
  b.setVal286(static_cast<unsigned char>(mx::FromPasta(e.IsDestructedType())));
  b.setVal287(e.IsLocalConstQualified());
  b.setVal288(e.IsLocalRestrictQualified());
  b.setVal289(e.IsLocalVolatileQualified());
  b.setVal290(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveCopy())));
  b.setVal291(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDefaultInitialize())));
  b.setVal292(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDestructiveMove())));
  b.setVal293(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal294(e.IsNull());
  b.setVal295(e.IsObjCGCStrong());
  b.setVal296(e.IsObjCGCWeak());
  b.setVal297(e.IsPODType());
  b.setVal298(e.IsRestrictQualified());
  b.setVal299(e.IsTrivialType());
  b.setVal300(e.IsTriviallyCopyableType());
  b.setVal301(e.IsTriviallyRelocatableType());
  b.setVal302(e.IsVolatileQualified());
  b.setVal303(e.MayBeDynamicClass());
  b.setVal304(e.MayBeNotDynamicClass());
  b.setVal305(es.EntityId(e.StripObjCKindOfType()));
  b.setVal306(es.EntityId(e.WithConst()));
  b.setVal307(es.EntityId(e.WithRestrict()));
  b.setVal308(es.EntityId(e.WithVolatile()));
  b.setVal309(es.EntityId(e.WithoutLocalFastQualifiers()));
}

void SerializeTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto v311 = e.Declaration();
  if (v311) {
    auto id311 = es.EntityId(v311.value());
    b.setVal311(id311);
    b.setVal312(id311 != mx::kInvalidEntityId);
  } else {
    b.setVal311(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  b.setVal313(e.IsParameterPack());
  b.setVal314(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto v311 = e.AliasedType();
  if (v311) {
    auto id311 = es.EntityId(v311.value());
    b.setVal311(id311);
    b.setVal312(id311 != mx::kInvalidEntityId);
  } else {
    b.setVal311(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  b.setVal313(e.IsCurrentInstantiation());
  b.setVal314(e.IsSugared());
  b.setVal315(e.IsTypeAlias());
  do {
    auto v316 = e.TemplateArguments();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.PseudoId(e316));
      ++i316;
    }
  } while (false);
}

void SerializeTagType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Declaration()));
  b.setVal312(e.IsBeingDefined());
}

void SerializeRecordType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal313(e.HasConstFields());
  b.setVal314(e.IsSugared());
}

void SerializeEnumType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal313(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ReplacedParameter()));
  b.setVal317(es.EntityId(e.ReplacementType()));
  b.setVal312(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ReplacedParameter()));
  b.setVal312(e.IsSugared());
}

void SerializeReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal312(e.IsInnerReference());
  b.setVal313(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal314(e.IsSugared());
}

void SerializeLValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal314(e.IsSugared());
}

void SerializePointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializePipeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal312(e.IsReadOnly());
  b.setVal313(e.IsSugared());
}

void SerializeParenType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.InnerType()));
  b.setVal312(e.IsSugared());
}

void SerializePackExpansionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto v318 = e.NumExpansions();
  if (v318) {
    b.setVal318(static_cast<unsigned>(v318.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  b.setVal311(es.EntityId(e.Pattern()));
  b.setVal313(e.IsSugared());
}

void SerializeObjCTypeParamType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Declaration()));
  b.setVal312(e.IsSugared());
}

void SerializeObjCObjectType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.BaseType()));
  b.setVal317(es.EntityId(e.Interface()));
  auto v319 = e.SuperClassType();
  if (v319) {
    auto id319 = es.EntityId(v319.value());
    b.setVal319(id319);
    b.setVal312(id319 != mx::kInvalidEntityId);
  } else {
    b.setVal319(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  do {
    auto v320 = e.TypeArguments();
    auto sv320 = b.initVal320(static_cast<unsigned>(v320.size()));
    auto i320 = 0u;
    for (const auto &e320 : v320) {
      sv320.set(i320, es.EntityId(e320));
      ++i320;
    }
  } while (false);
  do {
    auto v321 = e.TypeArgumentsAsWritten();
    auto sv321 = b.initVal321(static_cast<unsigned>(v321.size()));
    auto i321 = 0u;
    for (const auto &e321 : v321) {
      sv321.set(i321, es.EntityId(e321));
      ++i321;
    }
  } while (false);
  b.setVal313(e.IsKindOfType());
  b.setVal314(e.IsKindOfTypeAsWritten());
  b.setVal315(e.IsObjCClass());
  b.setVal322(e.IsObjCId());
  b.setVal323(e.IsObjCQualifiedClass());
  b.setVal324(e.IsObjCQualifiedId());
  b.setVal325(e.IsObjCUnqualifiedClass());
  b.setVal326(e.IsObjCUnqualifiedId());
  b.setVal327(e.IsObjCUnqualifiedIdOrClass());
  b.setVal328(e.IsSpecialized());
  b.setVal329(e.IsSpecializedAsWritten());
  b.setVal330(e.IsSugared());
  b.setVal331(e.IsUnspecialized());
  b.setVal332(e.IsUnspecializedAsWritten());
  b.setVal333(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal334(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.InterfaceDeclaration()));
  b.setVal317(es.EntityId(e.InterfaceType()));
  b.setVal319(es.EntityId(e.ObjectType()));
  b.setVal333(es.EntityId(e.SuperClassType()));
  do {
    auto v320 = e.TypeArguments();
    auto sv320 = b.initVal320(static_cast<unsigned>(v320.size()));
    auto i320 = 0u;
    for (const auto &e320 : v320) {
      sv320.set(i320, es.EntityId(e320));
      ++i320;
    }
  } while (false);
  do {
    auto v321 = e.TypeArgumentsAsWritten();
    auto sv321 = b.initVal321(static_cast<unsigned>(v321.size()));
    auto i321 = 0u;
    for (const auto &e321 : v321) {
      sv321.set(i321, es.EntityId(e321));
      ++i321;
    }
  } while (false);
  b.setVal312(e.IsKindOfType());
  b.setVal313(e.IsObjCIdOrClassType());
  b.setVal314(e.IsSpecialized());
  b.setVal315(e.IsSpecializedAsWritten());
  b.setVal322(e.IsSugared());
  b.setVal323(e.IsUnspecialized());
  b.setVal324(e.IsUnspecializedAsWritten());
  do {
    auto v335 = e.Qualifiers();
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
  b.setVal334(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v336 = e.Protocols();
    auto sv336 = b.initVal336(static_cast<unsigned>(v336.size()));
    auto i336 = 0u;
    for (const auto &e336 : v336) {
      sv336.set(i336, es.EntityId(e336));
      ++i336;
    }
  } while (false);
}

void SerializeMemberPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Class()));
  b.setVal317(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal312(e.IsMemberDataPointer());
  b.setVal313(e.IsMemberFunctionPointer());
  b.setVal314(e.IsSugared());
}

void SerializeMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal312(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  auto t317 = e.AttributeToken();
  b.setVal317(es.EntityId(t317));
  b.setVal319(es.EntityId(e.ColumnExpression()));
  b.setVal333(es.EntityId(e.RowExpression()));
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
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ModifiedType()));
  b.setVal317(es.EntityId(e.UnderlyingType()));
  b.setVal312(e.IsSugared());
}

void SerializeInjectedClassNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Declaration()));
  b.setVal317(es.EntityId(e.InjectedSpecializationType()));
  b.setVal319(es.EntityId(e.InjectedTST()));
  b.setVal312(e.IsSugared());
}

void SerializeFunctionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal310(es.EntityId(e.CallResultType()));
  b.setVal312(e.CmseNSCallAttribute());
  b.setVal313(e.HasRegParm());
  b.setVal314(e.NoReturnAttribute());
  b.setVal311(es.EntityId(e.ReturnType()));
  b.setVal315(e.IsConst());
  b.setVal322(e.IsRestrict());
  b.setVal323(e.IsVolatile());
}

void SerializeFunctionProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  auto v338 = e.CanThrow();
  if (v338) {
    b.setVal338(static_cast<unsigned char>(v338.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  b.setVal317(es.EntityId(e.Desugar()));
  auto t319 = e.EllipsisToken();
  b.setVal319(es.EntityId(t319));
  auto v333 = e.ExceptionSpecDeclaration();
  if (v333) {
    auto id333 = es.EntityId(v333.value());
    b.setVal333(id333);
    b.setVal325(id333 != mx::kInvalidEntityId);
  } else {
    b.setVal333(mx::kInvalidEntityId);
    b.setVal325(false);
  }
  auto v334 = e.ExceptionSpecTemplate();
  if (v334) {
    auto id334 = es.EntityId(v334.value());
    b.setVal334(id334);
    b.setVal326(id334 != mx::kInvalidEntityId);
  } else {
    b.setVal334(mx::kInvalidEntityId);
    b.setVal326(false);
  }
  b.setVal339(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v340 = e.NoexceptExpression();
  if (v340) {
    auto id340 = es.EntityId(v340.value());
    b.setVal340(id340);
    b.setVal327(id340 != mx::kInvalidEntityId);
  } else {
    b.setVal340(mx::kInvalidEntityId);
    b.setVal327(false);
  }
  do {
    auto v320 = e.ParameterTypes();
    auto sv320 = b.initVal320(static_cast<unsigned>(v320.size()));
    auto i320 = 0u;
    for (const auto &e320 : v320) {
      sv320.set(i320, es.EntityId(e320));
      ++i320;
    }
  } while (false);
  b.setVal341(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal328(e.HasDependentExceptionSpec());
  b.setVal329(e.HasDynamicExceptionSpec());
  b.setVal330(e.HasExceptionSpec());
  b.setVal331(e.HasExtParameterInfos());
  b.setVal332(e.HasInstantiationDependentExceptionSpec());
  b.setVal342(e.HasNoexceptExceptionSpec());
  b.setVal343(e.HasTrailingReturn());
  auto v344 = e.IsNothrow();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  b.setVal346(e.IsSugared());
  b.setVal347(e.IsTemplateVariadic());
  b.setVal348(e.IsVariadic());
  do {
    auto v321 = e.ExceptionTypes();
    auto sv321 = b.initVal321(static_cast<unsigned>(v321.size()));
    auto i321 = 0u;
    for (const auto &e321 : v321) {
      sv321.set(i321, es.EntityId(e321));
      ++i321;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal317(es.EntityId(e.Desugar()));
  b.setVal324(e.IsSugared());
}

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto t311 = e.AttributeToken();
  b.setVal311(es.EntityId(t311));
  b.setVal317(es.EntityId(e.ElementType()));
  b.setVal319(es.EntityId(e.SizeExpression()));
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal312(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto t311 = e.AttributeToken();
  b.setVal311(es.EntityId(t311));
  b.setVal317(es.EntityId(e.ElementType()));
  b.setVal319(es.EntityId(e.SizeExpression()));
  b.setVal312(e.IsSugared());
}

void SerializeDependentBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.NumBitsExpression()));
  b.setVal312(e.IsSigned());
  b.setVal313(e.IsSugared());
  b.setVal314(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.AddressSpaceExpression()));
  auto t317 = e.AttributeToken();
  b.setVal317(es.EntityId(t317));
  b.setVal312(e.IsSugared());
}

void SerializeDeducedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  auto v311 = e.ResolvedType();
  if (v311) {
    auto id311 = es.EntityId(v311.value());
    b.setVal311(id311);
    b.setVal312(id311 != mx::kInvalidEntityId);
  } else {
    b.setVal311(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  b.setVal313(e.IsDeduced());
  b.setVal314(e.IsSugared());
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
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v316 = e.TypeConstraintArguments();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.PseudoId(e316));
      ++i316;
    }
  } while (false);
  auto v317 = e.TypeConstraintConcept();
  if (v317) {
    auto id317 = es.EntityId(v317.value());
    b.setVal317(id317);
    b.setVal315(id317 != mx::kInvalidEntityId);
  } else {
    b.setVal317(mx::kInvalidEntityId);
    b.setVal315(false);
  }
  b.setVal322(e.IsConstrained());
  b.setVal323(e.IsDecltypeAuto());
  b.setVal324(e.IsGNUAutoType());
}

void SerializeDecltypeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.UnderlyingExpression()));
  b.setVal317(es.EntityId(e.UnderlyingType()));
  b.setVal312(e.IsSugared());
}

void SerializeComplexType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal312(e.IsSugared());
}

void SerializeBuiltinType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal312(e.IsFloatingPoint());
  b.setVal313(e.IsInteger());
  b.setVal314(e.IsSVEBool());
  b.setVal315(e.IsSignedInteger());
  b.setVal322(e.IsSugared());
  b.setVal323(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializeBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSigned());
  b.setVal313(e.IsSugared());
  b.setVal314(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Attribute()));
  b.setVal317(es.EntityId(e.WrappedType()));
  b.setVal312(e.IsSugared());
}

void SerializeAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal349(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal311(es.EntityId(e.EquivalentType()));
  auto v337 = e.ImmediateNullability();
  if (v337) {
    b.setVal337(static_cast<unsigned char>(v337.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  b.setVal317(es.EntityId(e.ModifiedType()));
  b.setVal313(e.IsCallingConv());
  b.setVal314(e.IsMSTypeSpec());
  b.setVal315(e.IsQualifier());
  b.setVal322(e.IsSugared());
}

void SerializeAtomicType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ValueType()));
  b.setVal312(e.IsSugared());
}

void SerializeArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.ElementType()));
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  if (auto r317 = e.BracketsRange(); auto rs317 = r317.Size()) {
    b.setVal317(es.EntityId(r317[0]));
    b.setVal319(es.EntityId(r317[rs317 - 1u]));
  } else {
    b.setVal317(0);
    b.setVal319(0);
  }
  auto t333 = e.LBracketToken();
  b.setVal333(es.EntityId(t333));
  auto t334 = e.RBracketToken();
  b.setVal334(es.EntityId(t334));
  b.setVal340(es.EntityId(e.SizeExpression()));
  b.setVal312(e.IsSugared());
}

void SerializeIncompleteArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  if (auto r317 = e.BracketsRange(); auto rs317 = r317.Size()) {
    b.setVal317(es.EntityId(r317[0]));
    b.setVal319(es.EntityId(r317[rs317 - 1u]));
  } else {
    b.setVal317(0);
    b.setVal319(0);
  }
  auto t333 = e.LBracketToken();
  b.setVal333(es.EntityId(t333));
  auto t334 = e.RBracketToken();
  b.setVal334(es.EntityId(t334));
  b.setVal340(es.EntityId(e.SizeExpression()));
  b.setVal312(e.IsSugared());
}

void SerializeConstantArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal311(es.EntityId(e.Desugar()));
  auto v317 = e.SizeExpression();
  if (v317) {
    auto id317 = es.EntityId(v317.value());
    b.setVal317(id317);
    b.setVal312(id317 != mx::kInvalidEntityId);
  } else {
    b.setVal317(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  b.setVal313(e.IsSugared());
}

void SerializeAdjustedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ResolvedType()));
  b.setVal317(es.EntityId(e.OriginalType()));
  b.setVal312(e.IsSugared());
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
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.NamedType()));
  auto v317 = e.OwnedTagDeclaration();
  if (v317) {
    auto id317 = es.EntityId(v317.value());
    b.setVal317(id317);
    b.setVal312(id317 != mx::kInvalidEntityId);
  } else {
    b.setVal317(mx::kInvalidEntityId);
    b.setVal312(false);
  }
  b.setVal313(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
  do {
    auto v316 = e.TemplateArguments();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.PseudoId(e316));
      ++i316;
    }
  } while (false);
}

void SerializeDependentNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal312(e.IsSugared());
}

void SerializeVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.ElementType()));
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal312(e.IsSugared());
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
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.FoundDeclaration()));
  b.setVal317(es.EntityId(e.UnderlyingType()));
  b.setVal312(e.IsSugared());
}

void SerializeUnresolvedUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Declaration()));
  b.setVal312(e.IsSugared());
}

void SerializeUnaryTransformType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.BaseType()));
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal317(es.EntityId(e.UnderlyingType()));
  b.setVal312(e.IsSugared());
}

void SerializeTypedefType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.Declaration()));
  b.setVal312(e.IsSugared());
}

void SerializeTypeOfType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.UnderlyingType()));
  b.setVal312(e.IsSugared());
}

void SerializeTypeOfExprType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal310(es.EntityId(e.Desugar()));
  b.setVal311(es.EntityId(e.UnderlyingExpression()));
  b.setVal312(e.IsSugared());
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
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
    b.setVal12(id9 != mx::kInvalidEntityId);
  } else {
    b.setVal9(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v10 = e.ReturnValue();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
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
  b.setVal14(es.EntityId(e.ConditionExpression()));
  b.setVal17(es.EntityId(e.D()));
  b.setVal18(es.EntityId(e.Expression()));
  b.setVal19(es.EntityId(e.R()));
  b.setVal20(es.EntityId(e.UpdateExpression()));
  b.setVal21(es.EntityId(e.V()));
  b.setVal22(es.EntityId(e.X()));
  b.setVal23(e.IsFailOnly());
  b.setVal24(e.IsPostfixUpdate());
  b.setVal25(e.IsXLHSInRHSPart());
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
  b.setVal23(e.HasCancel());
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
  b.setVal23(e.HasCancel());
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
  b.setVal23(e.HasCancel());
}

void SerializeOMPSectionDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPScanDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
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
    auto v26 = e.DependentCounters();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  do {
    auto v27 = e.DependentInitializers();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
    }
  } while (false);
  do {
    auto v28 = e.Finals();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
  do {
    auto v29 = e.FinalsConditions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  b.setVal14(es.EntityId(e.Body()));
  b.setVal17(es.EntityId(e.CalculateLastIteration()));
  b.setVal18(es.EntityId(e.CombinedCondition()));
  b.setVal19(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal20(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal21(es.EntityId(e.CombinedInitializer()));
  b.setVal22(es.EntityId(e.CombinedLowerBoundVariable()));
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
  b.setVal23(e.HasCancel());
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
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsGenericLoopDirective &e) {
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
  b.setVal23(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
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
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMaskedTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMaskedTaskLoopDirective(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
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
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
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
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
    b.setVal12(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v11 = e.ConditionVariableDeclarationStatement();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal15(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v13 = e.Else();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
    b.setVal23(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal23(false);
  }
  auto t14 = e.ElseToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.IfToken();
  b.setVal17(es.EntityId(t17));
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
    b.setVal24(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal24(false);
  }
  auto t19 = e.LParenToken();
  b.setVal19(es.EntityId(t19));
  auto t20 = e.RParenToken();
  b.setVal20(es.EntityId(t20));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal21(es.EntityId(e.Then()));
  b.setVal25(e.HasElseStorage());
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
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
    b.setVal12(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal15(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
    b.setVal23(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal23(false);
  }
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto v17 = e.Increment();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
    b.setVal24(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal24(false);
  }
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
    b.setVal25(id18 != mx::kInvalidEntityId);
  } else {
    b.setVal18(mx::kInvalidEntityId);
    b.setVal25(false);
  }
  auto t19 = e.LParenToken();
  b.setVal19(es.EntityId(t19));
  auto t20 = e.RParenToken();
  b.setVal20(es.EntityId(t20));
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
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
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
  b.setVal20(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal21(es.EntityId(e.ReturnStatement()));
  b.setVal22(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal30(es.EntityId(e.ReturnValue()));
  b.setVal31(es.EntityId(e.ReturnValueInitializer()));
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
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal15(e.HasStoredFPFeatures());
}

void SerializeCapturedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
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
  auto v20 = e.Initializer();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
    b.setVal12(id20 != mx::kInvalidEntityId);
  } else {
    b.setVal20(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  b.setVal21(es.EntityId(e.LoopVariableStatement()));
  b.setVal22(es.EntityId(e.LoopVariable()));
  auto t30 = e.RParenToken();
  b.setVal30(es.EntityId(t30));
  b.setVal31(es.EntityId(e.RangeInitializer()));
  b.setVal32(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.CatchToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.CaughtType()));
  auto v11 = e.ExceptionDeclaration();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
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
    auto v26 = e.Outputs();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
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
    auto v27 = e.OutputExpressions();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
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
    auto v28 = e.InputExpressions();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
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
    auto v29 = e.AllExpressions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  auto v70 = e.AssemblyString();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t10 = e.LBraceToken();
  b.setVal10(es.EntityId(t10));
  b.setVal23(e.HasBraces());
}

void SerializeGCCAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  b.setVal10(es.EntityId(e.AssemblyString()));
  auto t11 = e.RParenToken();
  b.setVal11(es.EntityId(t11));
  b.setVal23(e.IsAssemblyGoto());
  do {
    auto v29 = e.Labels();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
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
    auto v54 = e.InputConstraintLiterals();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
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
    auto v55 = e.ClobberStringLiterals();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
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
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
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
  b.setVal23(e.HasVariableStorage());
}

void SerializeValueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
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
  b.setVal13(es.EntityId(e.IgnoreImplicitCasts()));
  b.setVal14(es.EntityId(e.IgnoreImplicit()));
  b.setVal17(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal18(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal19(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal20(es.EntityId(e.IgnoreParenthesisImplicitCasts()));
  b.setVal21(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal22(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal30(es.EntityId(e.IgnoreParentheses()));
  b.setVal31(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal23(e.ContainsErrors());
  b.setVal24(e.ContainsUnexpandedParameterPack());
  b.setVal32(es.EntityId(e.BestDynamicClassTypeExpression()));
  auto t33 = e.ExpressionToken();
  b.setVal33(es.EntityId(t33));
  auto v34 = e.ObjCProperty();
  if (v34) {
    auto id34 = es.EntityId(v34.value());
    b.setVal34(id34);
    b.setVal25(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal25(false);
  }
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v35 = e.ReferencedDeclarationOfCallee();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
    b.setVal58(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto v36 = e.SourceBitField();
  if (v36) {
    auto id36 = es.EntityId(v36.value());
    b.setVal36(id36);
    b.setVal59(id36 != mx::kInvalidEntityId);
  } else {
    b.setVal36(mx::kInvalidEntityId);
    b.setVal59(false);
  }
  auto v37 = e.Type();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal60(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
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
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v94 = e.Designators();
    auto sv94 = b.initVal94(static_cast<unsigned>(v94.size()));
    auto i94 = 0u;
    for (const auto &e94 : v94) {
      sv94.set(i94, es.PseudoId(e94));
      ++i94;
    }
  } while (false);
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
  b.setVal95(e.IsDirectInitializer());
  b.setVal96(e.UsesGNUSyntax());
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
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasTemplateKeyword());
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
  b.setVal95(e.HadMultipleCandidates());
  b.setVal96(e.HasExplicitTemplateArguments());
  b.setVal97(e.HasQualifier());
  b.setVal98(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal99(e.HasTemplateKeyword());
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal101(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.CommonExpression()));
  auto t39 = e.KeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.OpaqueValue()));
  b.setVal41(es.EntityId(e.Operand()));
  b.setVal42(es.EntityId(e.ReadyExpression()));
  b.setVal43(es.EntityId(e.ResumeExpression()));
  b.setVal44(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal95(e.IsImplicit());
}

void SerializeCoyieldExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
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
    auto v94 = e.TemplateArguments();
    auto sv94 = b.initVal94(static_cast<unsigned>(v94.size()));
    auto i94 = 0u;
    for (const auto &e94 : v94) {
      sv94.set(i94, es.PseudoId(e94));
      ++i94;
    }
  } while (false);
  b.setVal95(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Initializer()));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal95(e.IsFileScope());
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
  b.setVal95(e.IsConditionDependent());
  b.setVal96(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v65 = e.CastKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto v38 = e.ConversionFunction();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.SubExpressionAsWritten()));
  auto v41 = e.TargetUnionField();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
    b.setVal96(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal97(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal98(e.IsPartOfExplicitCast());
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
  auto v70 = e.CastName();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
}

void SerializeCXXDynamicCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal98(e.IsAlwaysNull());
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
  b.setVal98(e.IsListInitialization());
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
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v70 = e.BridgeKindName();
  std::string s70(v70.data(), v70.size());
  b.setVal70(s70);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.Callee()));
  auto v40 = e.CalleeDeclaration();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v41 = e.DirectCallee();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
    b.setVal96(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.UnusedResultAttribute();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal97(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal98(e.HasStoredFPFeatures());
  b.setVal99(e.HasUnusedResultAttribute());
  b.setVal101(e.IsBuiltinAssumeFalse());
  b.setVal103(e.IsCallToStdMove());
  b.setVal104(e.IsUnevaluatedBuiltinCall());
  b.setVal105(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal106(e.IsAssignmentOperation());
  b.setVal107(e.IsComparisonOperation());
  b.setVal108(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.ImplicitObjectArgument()));
  auto v45 = e.MethodDeclaration();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
    b.setVal106(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal106(false);
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
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t45 = e.UDSuffixToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal39(es.EntityId(e.GuidDeclaration()));
  b.setVal40(es.EntityId(e.TypeOperand()));
  b.setVal41(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal96(e.IsTypeOperand());
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
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.TypeAsWritten()));
  b.setVal95(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
  auto v96 = e.IsMostDerived();
  if (v96) {
    b.setVal96(static_cast<bool>(v96.value()));
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
  b.setVal98(e.IsPotentiallyEvaluated());
  b.setVal99(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.SubExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t39 = e.ThrowToken();
  b.setVal39(es.EntityId(t39));
  b.setVal96(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.IsImplicit());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal41(es.EntityId(e.SemanticForm()));
  b.setVal95(e.IsAssignmentOperation());
  b.setVal96(e.IsComparisonOperation());
  b.setVal97(e.IsReversed());
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
  auto v43 = e.ScopeType();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal95(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t44 = e.TildeToken();
  b.setVal44(es.EntityId(t44));
  b.setVal96(e.HasQualifier());
  b.setVal97(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal95(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.AllocatedType()));
  auto v39 = e.ArraySize();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v40 = e.ConstructExpression();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal97(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  if (auto r41 = e.DirectInitializerRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v43 = e.Initializer();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal98(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal98(false);
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
  b.setVal99(e.HasInitializer());
  b.setVal101(e.IsArray());
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
  b.setVal95(e.ConstructsVirtualBase());
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal38(es.EntityId(e.Constructor()));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal96(e.InheritedFromVirtualBase());
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
  auto v109 = e.NumExpansions();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal43(es.EntityId(e.Pattern()));
  b.setVal44(es.EntityId(e.RHS()));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal96(e.IsLeftFold());
  b.setVal97(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.Base();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal39(es.EntityId(e.BaseType()));
  auto v40 = e.FirstQualifierFoundInScope();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal96(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal96(false);
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
  b.setVal97(e.HasExplicitTemplateArguments());
  b.setVal98(e.HasTemplateKeyword());
  b.setVal99(e.IsArrow());
  b.setVal101(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal96(e.IsArrayForm());
  b.setVal97(e.IsArrayFormAsWritten());
  b.setVal98(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.Expression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
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
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal95(e.HadMultipleCandidates());
  b.setVal96(e.IsElidable());
  b.setVal97(e.IsListInitialization());
  b.setVal98(e.IsStdInitializerListInitialization());
  b.setVal99(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.Value());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal95(e.HasStoredFPFeatures());
  b.setVal96(e.IsAdditiveOperation());
  b.setVal97(e.IsAssignmentOperation());
  b.setVal98(e.IsBitwiseOperation());
  b.setVal99(e.IsCommaOperation());
  b.setVal101(e.IsComparisonOperation());
  b.setVal103(e.IsCompoundAssignmentOperation());
  b.setVal104(e.IsEqualityOperation());
  b.setVal105(e.IsLogicalOperation());
  b.setVal106(e.IsMultiplicativeOperation());
  b.setVal107(e.IsPointerMemoryOperation());
  b.setVal108(e.IsRelationalOperation());
  b.setVal110(e.IsShiftAssignOperation());
  b.setVal111(e.IsShiftOperation());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal39(es.EntityId(e.Order()));
  auto v40 = e.OrderFail();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal41(es.EntityId(e.Pointer()));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.Scope();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal96(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v44 = e.Value1();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
    b.setVal97(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  auto v45 = e.Value2();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
    b.setVal98(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal46(es.EntityId(e.ValueType()));
  auto v47 = e.Weak();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
    b.setVal99(id47 != mx::kInvalidEntityId);
  } else {
    b.setVal47(mx::kInvalidEntityId);
    b.setVal99(false);
  }
  b.setVal101(e.IsCmpXChg());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  b.setVal41(es.EntityId(e.WrittenType()));
  b.setVal95(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.CanOverflow());
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal96(e.HasStoredFPFeatures());
  b.setVal97(e.IsArithmeticOperation());
  b.setVal98(e.IsDecrementOperation());
  b.setVal99(e.IsIncrementDecrementOperation());
  b.setVal101(e.IsIncrementOperation());
  b.setVal103(e.IsPostfix());
  b.setVal104(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ArgumentExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v39 = e.ArgumentType();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TypeOfArgument()));
  b.setVal97(e.IsArgumentType());
}

void SerializeTypoExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v95 = e.Value();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
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
  b.setVal95(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  auto v95 = e.ContainsNonAscii();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  auto v97 = e.ContainsNonAsciiOrNull();
  if (v97) {
    b.setVal97(static_cast<bool>(v97.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto v65 = e.Bytes();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto v70 = e.String();
  if (v70) {
    if (v70->empty()) {
      b.setVal70("");
    } else {
      std::string s70(v70->data(), v70->size());
      b.setVal70(s70);
    }
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  b.setVal101(e.IsOrdinary());
  b.setVal103(e.IsPascal());
  b.setVal104(e.IsUTF16());
  b.setVal105(e.IsUTF32());
  b.setVal106(e.IsUTF8());
  b.setVal107(e.IsWide());
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
  auto v65 = e.BuiltinString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.IsIntType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Pack()));
  auto v109 = e.PackLength();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto t40 = e.PackToken();
  b.setVal40(es.EntityId(t40));
  do {
    auto ov94 = e.PartialArguments();
    if (!ov94) {
      b.setVal96(false);
      break;
    }
    b.setVal96(true);
    auto v94 = std::move(*ov94);
    auto sv94 = b.initVal94(static_cast<unsigned>(v94.size()));
    auto i94 = 0u;
    for (const auto &e94 : v94) {
      sv94.set(i94, es.PseudoId(e94));
      ++i94;
    }
  } while (false);
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal97(e.IsPartiallySubstituted());
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
  b.setVal65(e.ComputeName());
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
    auto v16 = e.LocalParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t39 = e.RBraceToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RequiresKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal95(e.IsSatisfied());
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
  b.setVal38(es.EntityId(e.ResultExpression()));
  b.setVal39(es.EntityId(e.SyntacticForm()));
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
    auto v26 = e.SemanticExpressions();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
}

void SerializePredefinedExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.FunctionName()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v65 = e.IdentifierKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
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
  auto v109 = e.NumExpansions();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal39(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.NameToken();
  b.setVal39(es.EntityId(t39));
  auto v40 = e.NamingClass();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal95(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal96(e.HasExplicitTemplateArguments());
  b.setVal97(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  auto t45 = e.MemberToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  b.setVal98(e.HasUnresolvedUsing());
  b.setVal99(e.IsArrow());
  b.setVal101(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal98(e.IsOverloaded());
  b.setVal99(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal95(e.IsUnique());
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
  b.setVal95(e.IsArraySubscriptReferenceExpression());
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
  b.setVal95(e.IsClassReceiver());
  b.setVal96(e.IsExplicitProperty());
  b.setVal97(e.IsImplicitProperty());
  b.setVal98(e.IsMessagingGetter());
  b.setVal99(e.IsMessagingSetter());
  b.setVal101(e.IsObjectReceiver());
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
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.ClassReceiver()));
  b.setVal40(es.EntityId(e.ClassReceiverType()));
  b.setVal41(es.EntityId(e.InstanceReceiver()));
  auto t42 = e.LeftToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.MethodDeclaration()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal44(es.EntityId(e.ReceiverInterface()));
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  b.setVal95(e.IsClassMessage());
  b.setVal96(e.IsDelegateInitializerCall());
  b.setVal97(e.IsImplicit());
  b.setVal98(e.IsInstanceMessage());
  do {
    auto v26 = e.SelectorTokens();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
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
  b.setVal95(e.IsArrow());
  b.setVal96(e.IsFreeInstanceVariable());
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
  b.setVal95(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal95(e.ShouldCopy());
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
  b.setVal95(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ArrayWithObjectsMethod()));
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
    auto v16 = e.Dimensions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
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
  b.setVal95(e.HadMultipleCandidates());
  b.setVal96(e.HasExplicitTemplateArguments());
  b.setVal97(e.HasQualifier());
  b.setVal98(e.HasTemplateKeyword());
  b.setVal99(e.IsArrow());
  b.setVal101(e.IsImplicitAccess());
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal95(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExtendingDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v39 = e.LifetimeExtendedTemporaryDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal97(e.IsBoundToLvalueReference());
  b.setVal98(e.IsUsableInConstantExpressions());
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
  b.setVal95(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CallOperator()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t40 = e.CaptureDefaultToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v16 = e.ExplicitTemplateParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
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
  auto v109 = e.TemplateParameterList();
  if (v109) {
    b.setVal109(es.PseudoId(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto v45 = e.TrailingRequiresClause();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
    b.setVal96(id45 != mx::kInvalidEntityId);
  } else {
    b.setVal45(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal97(e.HasExplicitParameters());
  b.setVal98(e.HasExplicitResultType());
  b.setVal99(e.IsGenericLambda());
  b.setVal101(e.IsMutable());
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
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal95(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v39 = e.InitializedFieldInUnion();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto t40 = e.LBraceToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RBraceToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.SemanticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal97(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  auto v43 = e.SyntacticForm();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal98(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal99(e.HadArrayRangeDesignator());
  b.setVal101(e.HasArrayFiller());
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
  b.setVal38(es.EntityId(e.SubExpression()));
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
  b.setVal38(es.EntityId(e.ControllingExpression()));
  auto t39 = e.DefaultToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.GenericToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.ResultExpression()));
  b.setVal95(e.IsResultDependent());
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
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal95(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal95(e.HasAPValueResult());
  b.setVal96(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.ContainsDuplicateElements());
  auto t38 = e.AccessorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal96(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.QueriedExpression()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal95(e.Value());
}

void SerializeAttributedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  auto t10 = e.AttributeToken();
  b.setVal10(es.EntityId(t10));
  do {
    auto v16 = e.Attributes();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
    b.setVal12(id11 != mx::kInvalidEntityId);
  } else {
    b.setVal11(mx::kInvalidEntityId);
    b.setVal12(false);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
    b.setVal15(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  auto v14 = e.Initializer();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
    b.setVal23(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal23(false);
  }
  auto t17 = e.LParenToken();
  b.setVal17(es.EntityId(t17));
  auto t18 = e.RParenToken();
  b.setVal18(es.EntityId(t18));
  auto v19 = e.FirstSwitchCase();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
    b.setVal24(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal24(false);
  }
  auto t20 = e.SwitchToken();
  b.setVal20(es.EntityId(t20));
  b.setVal25(e.HasInitializerStorage());
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
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
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
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
    b.setVal23(id19 != mx::kInvalidEntityId);
  } else {
    b.setVal19(mx::kInvalidEntityId);
    b.setVal23(false);
  }
}

void SerializeDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(IsDefinition(e));
  do {
    auto v3 = e.Attributes();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  } while (false);
  b.setVal4(static_cast<unsigned char>(mx::FromPasta(e.Access())));
  b.setVal5(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  auto v6 = e.DefiningAttribute();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
    b.setVal7(id6 != mx::kInvalidEntityId);
  } else {
    b.setVal6(mx::kInvalidEntityId);
    b.setVal7(false);
  }
  auto v8 = e.DescribedTemplateParameters();
  if (v8) {
    b.setVal8(es.PseudoId(v8.value()));
    b.setVal9(true);
  } else {
    b.setVal9(false);
  }
  auto v10 = e.ExternalSourceSymbolAttribute();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
    b.setVal11(id10 != mx::kInvalidEntityId);
  } else {
    b.setVal10(mx::kInvalidEntityId);
    b.setVal11(false);
  }
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v14 = e.NonClosureContext();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
    b.setVal15(id14 != mx::kInvalidEntityId);
  } else {
    b.setVal14(mx::kInvalidEntityId);
    b.setVal15(false);
  }
  b.setVal16(e.HasAttributes());
  b.setVal17(e.HasOwningModule());
  b.setVal18(e.HasTagIdentifierNamespace());
  b.setVal19(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal20(e.IsDeprecated());
  b.setVal21(e.IsDiscardedInGlobalModuleFragment());
  b.setVal22(e.IsFunctionOrFunctionTemplate());
  b.setVal23(e.IsImplicit());
  b.setVal24(e.IsInAnonymousNamespace());
  b.setVal25(e.IsInExportDeclarationContext());
  b.setVal26(e.IsInLocalScopeForInstantiation());
  b.setVal27(e.IsInStdNamespace());
  b.setVal28(e.IsInvalidDeclaration());
  b.setVal29(e.IsInvisibleOutsideTheOwningModule());
  b.setVal30(e.IsModulePrivate());
  b.setVal31(e.IsOutOfLine());
  b.setVal32(e.IsParameterPack());
  b.setVal33(e.IsReachable());
  b.setVal34(e.IsTemplateDeclaration());
  b.setVal35(e.IsTemplateParameter());
  b.setVal36(e.IsTemplateParameterPack());
  b.setVal37(e.IsTemplated());
  b.setVal38(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal39(e.IsUnavailable());
  b.setVal40(e.IsUnconditionallyVisible());
  b.setVal41(e.IsWeakImported());
  do {
    auto v42 = e.Redeclarations();
    auto sv42 = b.initVal42(static_cast<unsigned>(v42.size()));
    auto i42 = 0u;
    for (const auto &e42 : v42) {
      sv42.set(i42, es.EntityId(e42));
      ++i42;
    }
  } while (false);
  b.setVal43(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal44(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto t45 = e.Token();
  b.setVal45(es.EntityId(t45));
  if (auto r46 = e.Tokens(); auto rs46 = r46.Size()) {
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
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
    b.setVal55(id48 != mx::kInvalidEntityId);
  } else {
    b.setVal48(mx::kInvalidEntityId);
    b.setVal55(false);
  }
  auto t56 = e.CaretToken();
  b.setVal56(es.EntityId(t56));
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
  auto t48 = e.AccessSpecifierToken();
  b.setVal48(es.EntityId(t48));
  auto t56 = e.ColonToken();
  b.setVal56(es.EntityId(t56));
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
  auto t57 = e.RParenToken();
  b.setVal57(es.EntityId(t57));
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
  auto t66 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal66(es.EntityId(t66));
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
  b.setVal63(e.Name());
  auto v69 = e.ObjCFStringFormattingFamily();
  if (v69) {
    b.setVal69(static_cast<unsigned char>(v69.value()));
    b.setVal49(true);
  } else {
    b.setVal49(false);
  }
  b.setVal64(e.QualifiedNameAsString());
  b.setVal48(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal70(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal52(e.HasExternalFormalLinkage());
  b.setVal53(e.HasLinkage());
  b.setVal54(e.HasLinkageBeenComputed());
  b.setVal55(e.IsCXXClassMember());
  b.setVal59(e.IsCXXInstanceMember());
  b.setVal60(e.IsExternallyDeclarable());
  b.setVal61(e.IsExternallyVisible());
  b.setVal71(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v72 = e.MSAssemblyLabel();
  std::string s72(v72.data(), v72.size());
  b.setVal72(s72);
  b.setVal56(es.EntityId(e.Statement()));
  b.setVal73(e.IsGnuLocal());
  b.setVal74(e.IsMSAssemblyLabel());
  b.setVal75(e.IsResolvedMSAssemblyLabel());
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
  auto t57 = e.EnumToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.UsingToken();
  b.setVal58(es.EntityId(t58));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t56 = e.UsingToken();
  b.setVal56(es.EntityId(t56));
  b.setVal73(e.HasTypename());
  b.setVal74(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal56(es.EntityId(e.Type()));
  b.setVal73(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t57 = e.EllipsisToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.UsingToken();
  b.setVal58(es.EntityId(t58));
  b.setVal74(e.IsAccessDeclaration());
  b.setVal75(e.IsPackExpansion());
}

void SerializeUnnamedGlobalConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnnamedGlobalConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
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
  b.setVal76(es.EntityId(e.Initializer()));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
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
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal74(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  auto v58 = e.VariableDeclaration();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
    b.setVal75(id58 != mx::kInvalidEntityId);
  } else {
    b.setVal58(mx::kInvalidEntityId);
    b.setVal75(false);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v57 = e.InitializerExpression();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal74(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal74(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t57 = e.FirstInnerToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.FirstOuterToken();
  b.setVal58(es.EntityId(t58));
  auto v66 = e.TrailingRequiresClause();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
    b.setVal74(id66 != mx::kInvalidEntityId);
  } else {
    b.setVal66(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  auto t67 = e.TypeSpecEndToken();
  b.setVal67(es.EntityId(t67));
  auto t68 = e.TypeSpecStartToken();
  b.setVal68(es.EntityId(t68));
  do {
    auto v78 = e.TemplateParameterLists();
    auto sv78 = b.initVal78(static_cast<unsigned>(v78.size()));
    auto i78 = 0u;
    for (const auto &e78 : v78) {
      sv78.set(i78, es.PseudoId(e78));
      ++i78;
    }
  } while (false);
}

void SerializeVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v76 = e.ActingDefinition();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal75(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  auto v79 = e.Initializer();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal80(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v81 = e.InitializingDeclaration();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
    b.setVal82(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal82(false);
  }
  auto v83 = e.InstantiatedFromStaticDataMember();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
    b.setVal84(id83 != mx::kInvalidEntityId);
  } else {
    b.setVal83(mx::kInvalidEntityId);
    b.setVal84(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t86 = e.PointOfInstantiation();
  b.setVal86(es.EntityId(t86));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal92(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal92(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal95(e.HasConstantInitialization());
  b.setVal96(e.HasDependentAlignment());
  b.setVal97(e.HasExternalStorage());
  auto v98 = e.HasFlexibleArrayInitializer();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  b.setVal100(e.HasGlobalStorage());
  auto v101 = e.HasICEInitializer();
  if (v101) {
    b.setVal101(static_cast<bool>(v101.value()));
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
  b.setVal103(e.HasInitializer());
  b.setVal104(e.HasLocalStorage());
  b.setVal105(e.IsARCPseudoStrong());
  b.setVal106(e.IsCXXForRangeDeclaration());
  b.setVal107(e.IsConstexpr());
  b.setVal108(e.IsDirectInitializer());
  b.setVal109(e.IsEscapingByref());
  b.setVal110(e.IsExceptionVariable());
  b.setVal111(e.IsExternC());
  b.setVal112(e.IsFileVariableDeclaration());
  b.setVal113(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal114(e.IsInExternCContext());
  b.setVal115(e.IsInExternCXXContext());
  b.setVal116(e.IsInitializerCapture());
  b.setVal117(e.IsInline());
  b.setVal118(e.IsInlineSpecified());
  b.setVal119(e.IsKnownToBeDefined());
  b.setVal120(e.IsLocalVariableDeclaration());
  b.setVal121(e.IsLocalVariableDeclarationOrParm());
  b.setVal122(e.IsNRVOVariable());
  b.setVal123(e.IsNoDestroy());
  b.setVal124(e.IsNonEscapingByref());
  b.setVal125(e.IsObjCForDeclaration());
  b.setVal126(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal127(e.IsStaticDataMember());
  b.setVal128(e.IsStaticLocal());
  b.setVal129(e.IsThisDeclarationADemotedDefinition());
  b.setVal130(e.IsUsableInConstantExpressions());
  b.setVal131(e.MightBeUsableInConstantExpressions());
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v133 = e.DefaultArgument();
  if (v133) {
    auto id133 = es.EntityId(v133.value());
    b.setVal133(id133);
    b.setVal134(id133 != mx::kInvalidEntityId);
  } else {
    b.setVal133(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  if (auto r135 = e.DefaultArgumentRange(); auto rs135 = r135.Size()) {
    b.setVal135(es.EntityId(r135[0]));
    b.setVal136(es.EntityId(r135[rs135 - 1u]));
  } else {
    b.setVal135(0);
    b.setVal136(0);
  }
  b.setVal137(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal138(es.EntityId(e.OriginalType()));
  auto v139 = e.UninstantiatedDefaultArgument();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
    b.setVal140(id139 != mx::kInvalidEntityId);
  } else {
    b.setVal139(mx::kInvalidEntityId);
    b.setVal140(false);
  }
  b.setVal141(e.HasDefaultArgument());
  b.setVal142(e.HasInheritedDefaultArgument());
  b.setVal143(e.HasUninstantiatedDefaultArgument());
  b.setVal144(e.HasUnparsedDefaultArgument());
  b.setVal145(e.IsDestroyedInCallee());
  b.setVal146(e.IsKNRPromoted());
  b.setVal147(e.IsObjCMethodParameter());
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
  b.setVal137(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
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
  auto t133 = e.ExternToken();
  b.setVal133(es.EntityId(t133));
  b.setVal137(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v148 = e.TemplateArguments();
    auto sv148 = b.initVal148(static_cast<unsigned>(v148.size()));
    auto i148 = 0u;
    for (const auto &e148 : v148) {
      sv148.set(i148, es.PseudoId(e148));
      ++i148;
    }
  } while (false);
  do {
    auto v149 = e.TemplateInstantiationArguments();
    auto sv149 = b.initVal149(static_cast<unsigned>(v149.size()));
    auto i149 = 0u;
    for (const auto &e149 : v149) {
      sv149.set(i149, es.PseudoId(e149));
      ++i149;
    }
  } while (false);
  auto t135 = e.TemplateKeywordToken();
  b.setVal135(es.EntityId(t135));
  b.setVal136(es.EntityId(e.TypeAsWritten()));
  b.setVal134(e.IsClassScopeExplicitSpecialization());
  b.setVal140(e.IsExplicitInstantiationOrSpecialization());
  b.setVal141(e.IsExplicitSpecialization());
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
  b.setVal75(e.DefaultArgumentWasInherited());
  auto v76 = e.DefaultArgument();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal80(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  auto t79 = e.DefaultArgumentToken();
  b.setVal79(es.EntityId(t79));
  auto v150 = e.NumExpansionTypes();
  if (v150) {
    b.setVal150(static_cast<unsigned>(v150.value()));
    b.setVal82(true);
  } else {
    b.setVal82(false);
  }
  auto v81 = e.PlaceholderTypeConstraint();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
    b.setVal84(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal84(false);
  }
  b.setVal92(e.HasDefaultArgument());
  b.setVal95(e.HasPlaceholderTypeConstraint());
  b.setVal96(e.IsExpandedParameterPack());
  b.setVal97(e.IsPackExpansion());
  do {
    auto v50 = e.ExpansionTypes();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal75(e.HasGetter());
  b.setVal80(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal75(e.UsesFPIntrin());
  auto v80 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v80) {
    b.setVal80(static_cast<bool>(v80.value()));
    b.setVal82(true);
  } else {
    b.setVal82(false);
  }
  b.setVal84(e.DoesThisDeclarationHaveABody());
  b.setVal76(es.EntityId(e.CallResultType()));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal79(es.EntityId(e.DeclaredReturnType()));
  auto t81 = e.EllipsisToken();
  b.setVal81(es.EntityId(t81));
  if (auto r83 = e.ExceptionSpecSourceRange(); auto rs83 = r83.Size()) {
    b.setVal83(es.EntityId(r83[0]));
    b.setVal86(es.EntityId(r83[rs83 - 1u]));
  } else {
    b.setVal83(0);
    b.setVal86(0);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v91 = e.InstantiatedFromDeclaration();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal92(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal92(false);
  }
  auto v133 = e.InstantiatedFromMemberFunction();
  if (v133) {
    auto id133 = es.EntityId(v133.value());
    b.setVal133(id133);
    b.setVal95(id133 != mx::kInvalidEntityId);
  } else {
    b.setVal133(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v150 = e.ODRHash();
  if (v150) {
    b.setVal150(static_cast<unsigned>(v150.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r135 = e.ParametersSourceRange(); auto rs135 = r135.Size()) {
    b.setVal135(es.EntityId(r135[0]));
    b.setVal136(es.EntityId(r135[rs135 - 1u]));
  } else {
    b.setVal135(0);
    b.setVal136(0);
  }
  auto t138 = e.PointOfInstantiation();
  b.setVal138(es.EntityId(t138));
  b.setVal139(es.EntityId(e.ReturnType()));
  if (auto r151 = e.ReturnTypeSourceRange(); auto rs151 = r151.Size()) {
    b.setVal151(es.EntityId(r151[0]));
    b.setVal152(es.EntityId(r151[rs151 - 1u]));
  } else {
    b.setVal151(0);
    b.setVal152(0);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v153 = e.TemplateInstantiationPattern();
  if (v153) {
    auto id153 = es.EntityId(v153.value());
    b.setVal153(id153);
    b.setVal97(id153 != mx::kInvalidEntityId);
  } else {
    b.setVal153(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal98(e.HasImplicitReturnZero());
  b.setVal99(e.HasInheritedPrototype());
  b.setVal100(e.HasOneParameterOrDefaultArguments());
  b.setVal101(e.HasPrototype());
  b.setVal102(e.HasSkippedBody());
  b.setVal103(e.HasTrivialBody());
  b.setVal104(e.HasWrittenPrototype());
  b.setVal105(e.InstantiationIsPending());
  b.setVal106(e.IsCPUDispatchMultiVersion());
  b.setVal107(e.IsCPUSpecificMultiVersion());
  b.setVal108(e.IsConsteval());
  b.setVal109(e.IsConstexpr());
  b.setVal110(e.IsConstexprSpecified());
  b.setVal111(e.IsDefaulted());
  b.setVal112(e.IsDeleted());
  b.setVal113(e.IsDeletedAsWritten());
  b.setVal114(e.IsDestroyingOperatorDelete());
  b.setVal115(e.IsExplicitlyDefaulted());
  b.setVal116(e.IsExternC());
  b.setVal117(e.IsFunctionTemplateSpecialization());
  b.setVal118(e.IsGlobal());
  b.setVal119(e.IsImplicitlyInstantiable());
  b.setVal120(e.IsInExternCContext());
  b.setVal121(e.IsInExternCXXContext());
  b.setVal122(e.IsIneligibleOrNotSelected());
  b.setVal123(e.IsInlineBuiltinDeclaration());
  auto v124 = e.IsInlineDefinitionExternallyVisible();
  if (v124) {
    b.setVal124(static_cast<bool>(v124.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
  }
  b.setVal126(e.IsInlineSpecified());
  b.setVal127(e.IsInlined());
  b.setVal128(e.IsLateTemplateParsed());
  auto v129 = e.IsMSExternInline();
  if (v129) {
    b.setVal129(static_cast<bool>(v129.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  b.setVal131(e.IsMSVCRTEntryPoint());
  b.setVal134(e.IsMain());
  b.setVal140(e.IsMultiVersion());
  b.setVal141(e.IsNoReturn());
  b.setVal142(e.IsOverloadedOperator());
  b.setVal143(e.IsPure());
  b.setVal144(e.IsReplaceableGlobalAllocationFunction());
  auto v145 = e.IsReservedGlobalPlacementOperator();
  if (v145) {
    b.setVal145(static_cast<bool>(v145.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  b.setVal147(e.IsStatic());
  b.setVal154(e.IsTargetClonesMultiVersion());
  b.setVal155(e.IsTargetMultiVersion());
  b.setVal156(e.IsTemplateInstantiation());
  b.setVal157(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal158(e.IsTrivial());
  b.setVal159(e.IsTrivialForCall());
  b.setVal160(e.IsUserProvided());
  b.setVal161(e.IsVariadic());
  b.setVal162(e.IsVirtualAsWritten());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal163(e.UsesSEHTry());
  b.setVal164(e.WillHaveBody());
  auto v165 = e.Body();
  if (v165) {
    auto id165 = es.EntityId(v165.value());
    b.setVal165(id165);
    b.setVal166(id165 != mx::kInvalidEntityId);
  } else {
    b.setVal165(mx::kInvalidEntityId);
    b.setVal166(false);
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
  b.setVal137(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v167 = e.ThisObjectType();
  if (v167) {
    auto id167 = es.EntityId(v167.value());
    b.setVal167(id167);
    b.setVal168(id167 != mx::kInvalidEntityId);
  } else {
    b.setVal167(mx::kInvalidEntityId);
    b.setVal168(false);
  }
  auto v169 = e.ThisType();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
    b.setVal170(id169 != mx::kInvalidEntityId);
  } else {
    b.setVal169(mx::kInvalidEntityId);
    b.setVal170(false);
  }
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
  do {
    auto v179 = e.ParameterDeclarations();
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v180 = e.OperatorDelete();
  if (v180) {
    auto id180 = es.EntityId(v180.value());
    b.setVal180(id180);
    b.setVal181(id180 != mx::kInvalidEntityId);
  } else {
    b.setVal180(mx::kInvalidEntityId);
    b.setVal181(false);
  }
  auto v182 = e.OperatorDeleteThisArgument();
  if (v182) {
    auto id182 = es.EntityId(v182.value());
    b.setVal182(id182);
    b.setVal183(id182 != mx::kInvalidEntityId);
  } else {
    b.setVal182(mx::kInvalidEntityId);
    b.setVal183(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal180(es.EntityId(e.ConversionType()));
  b.setVal181(e.IsExplicit());
  b.setVal183(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v180 = e.TargetConstructor();
  if (v180) {
    auto id180 = es.EntityId(v180.value());
    b.setVal180(id180);
    b.setVal181(id180 != mx::kInvalidEntityId);
  } else {
    b.setVal180(mx::kInvalidEntityId);
    b.setVal181(false);
  }
  b.setVal183(e.IsDefaultConstructor());
  b.setVal184(e.IsDelegatingConstructor());
  b.setVal185(e.IsExplicit());
  b.setVal186(e.IsInheritingConstructor());
  b.setVal187(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal167(es.EntityId(e.CorrespondingConstructor()));
  b.setVal168(e.IsCopyDeductionCandidate());
  b.setVal170(e.IsExplicit());
  do {
    auto v62 = e.ParameterDeclarations();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      sv62.set(i62, es.EntityId(e62));
      ++i62;
    }
  } while (false);
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v76 = e.BitWidth();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal75(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  auto v79 = e.CapturedVLAType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal80(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v81 = e.InClassInitializer();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
    b.setVal82(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal82(false);
  }
  b.setVal84(e.HasCapturedVLAType());
  b.setVal92(e.HasInClassInitializer());
  b.setVal95(e.IsAnonymousStructOrUnion());
  b.setVal96(e.IsBitField());
  b.setVal97(e.IsMutable());
  b.setVal98(e.IsUnnamedBitfield());
  b.setVal99(e.IsZeroLengthBitField());
  b.setVal100(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal83(es.EntityId(e.ContainingInterface()));
  b.setVal86(es.EntityId(e.NextInstanceVariable()));
  b.setVal101(e.Synthesize());
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
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal73(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal73(false);
  }
  b.setVal58(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal74(e.ConstructsVirtualBase());
  b.setVal66(es.EntityId(e.ConstructedBaseClass()));
  auto v67 = e.ConstructedBaseClassShadowDeclaration();
  if (v67) {
    auto id67 = es.EntityId(v67.value());
    b.setVal67(id67);
    b.setVal75(id67 != mx::kInvalidEntityId);
  } else {
    b.setVal67(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  b.setVal68(es.EntityId(e.NominatedBaseClass()));
  auto v76 = e.NominatedBaseClassShadowDeclaration();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal80(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal80(false);
  }
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
  auto t56 = e.IdentifierToken();
  b.setVal56(es.EntityId(t56));
  auto t57 = e.NamespaceKeyToken();
  b.setVal57(es.EntityId(t57));
  b.setVal58(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t66 = e.UsingToken();
  b.setVal66(es.EntityId(t66));
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
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
    b.setVal73(id56 != mx::kInvalidEntityId);
  } else {
    b.setVal56(mx::kInvalidEntityId);
    b.setVal73(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal74(e.DefaultArgumentWasInherited());
  auto v57 = e.DefaultArgument();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal75(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  auto v58 = e.DefaultArgumentInfo();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
    b.setVal80(id58 != mx::kInvalidEntityId);
  } else {
    b.setVal58(mx::kInvalidEntityId);
    b.setVal80(false);
  }
  auto t66 = e.DefaultArgumentToken();
  b.setVal66(es.EntityId(t66));
  b.setVal82(e.HasDefaultArgument());
  b.setVal84(e.HasTypeConstraint());
  b.setVal92(e.IsExpandedParameterPack());
  b.setVal95(e.IsPackExpansion());
  b.setVal96(e.WasDeclaredWithTypename());
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
  auto t66 = e.FirstInnerToken();
  b.setVal66(es.EntityId(t66));
  auto t67 = e.FirstOuterToken();
  b.setVal67(es.EntityId(t67));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v68 = e.TypedefNameForAnonymousDeclaration();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
    b.setVal74(id68 != mx::kInvalidEntityId);
  } else {
    b.setVal68(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  b.setVal75(e.HasNameForLinkage());
  b.setVal80(e.IsBeingDefined());
  b.setVal82(e.IsClass());
  b.setVal84(e.IsCompleteDefinition());
  b.setVal92(e.IsCompleteDefinitionRequired());
  b.setVal95(e.IsDependentType());
  b.setVal96(e.IsEmbeddedInDeclarator());
  b.setVal97(e.IsEnum());
  b.setVal98(e.IsFreeStanding());
  b.setVal99(e.IsInterface());
  b.setVal100(e.IsStruct());
  b.setVal101(e.IsThisDeclarationADemotedDefinition());
  b.setVal102(e.IsUnion());
  b.setVal103(e.MayHaveOutOfDateDefinition());
  do {
    auto v78 = e.TemplateParameterLists();
    auto sv78 = b.initVal78(static_cast<unsigned>(v78.size()));
    auto i78 = 0u;
    for (const auto &e78 : v78) {
      sv78.set(i78, es.PseudoId(e78));
      ++i78;
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
  b.setVal104(e.CanPassInRegisters());
  do {
    auto v51 = e.Fields();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal105(e.HasFlexibleArrayMember());
  b.setVal106(e.HasLoadedFieldsFromExternalStorage());
  b.setVal107(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal108(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal109(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal110(e.HasObjectMember());
  b.setVal111(e.HasVolatileMember());
  b.setVal112(e.IsAnonymousStructOrUnion());
  b.setVal113(e.IsCapturedRecord());
  b.setVal114(e.IsInjectedClassName());
  b.setVal115(e.IsLambda());
  b.setVal116(e.IsMsStruct());
  b.setVal117(e.IsNonTrivialToPrimitiveCopy());
  b.setVal118(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal119(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal120(e.IsOrContainsUnion());
  b.setVal121(e.IsParameterDestroyedInCallee());
  b.setVal122(e.IsRandomized());
  b.setVal123(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v124 = e.AllowConstDefaultInitializer();
  if (v124) {
    b.setVal124(static_cast<bool>(v124.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
  }
  do {
    auto ov148 = e.Bases();
    if (!ov148) {
      b.setVal126(false);
      break;
    }
    b.setVal126(true);
    auto v148 = std::move(*ov148);
    auto sv148 = b.initVal148(static_cast<unsigned>(v148.size()));
    auto i148 = 0u;
    for (const auto &e148 : v148) {
      sv148.set(i148, es.PseudoId(e148));
      ++i148;
    }
  } while (false);
  auto v87 = e.CalculateInheritanceModel();
  if (v87) {
    b.setVal87(static_cast<unsigned char>(v87.value()));
    b.setVal127(true);
  } else {
    b.setVal127(false);
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
    auto ov179 = e.Friends();
    if (!ov179) {
      b.setVal128(false);
      break;
    }
    b.setVal128(true);
    auto v179 = std::move(*ov179);
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  auto v76 = e.Destructor();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal129(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal129(false);
  }
  auto v150 = e.GenericLambdaTemplateParameterList();
  if (v150) {
    b.setVal150(es.PseudoId(v150.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  auto v79 = e.InstantiatedFromMemberClass();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal131(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal131(false);
  }
  auto v81 = e.LambdaCallOperator();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
    b.setVal134(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  auto v88 = e.LambdaCaptureDefault();
  if (v88) {
    b.setVal88(static_cast<unsigned char>(v88.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  auto v83 = e.LambdaContextDeclaration();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
    b.setVal141(id83 != mx::kInvalidEntityId);
  } else {
    b.setVal83(mx::kInvalidEntityId);
    b.setVal141(false);
  }
  do {
    auto ov188 = e.LambdaExplicitTemplateParameters();
    if (!ov188) {
      b.setVal142(false);
      break;
    }
    b.setVal142(true);
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
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v86 = e.LambdaType();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
    b.setVal144(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal144(false);
  }
  auto v89 = e.MSInheritanceModel();
  if (v89) {
    b.setVal89(static_cast<unsigned char>(v89.value()));
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v190 = e.NumBases();
  if (v190) {
    b.setVal190(static_cast<unsigned>(v190.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v191 = e.NumVirtualBases();
  if (v191) {
    b.setVal191(static_cast<unsigned>(v191.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v192 = e.ODRHash();
  if (v192) {
    b.setVal192(static_cast<unsigned>(v192.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal155(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal155(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v156 = e.HasAnyDependentBases();
  if (v156) {
    b.setVal156(static_cast<bool>(v156.value()));
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v158 = e.HasConstexprDefaultConstructor();
  if (v158) {
    b.setVal158(static_cast<bool>(v158.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v160 = e.HasConstexprDestructor();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v162 = e.HasConstexprNonCopyMoveConstructor();
  if (v162) {
    b.setVal162(static_cast<bool>(v162.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v164 = e.HasCopyAssignmentWithConstParameter();
  if (v164) {
    b.setVal164(static_cast<bool>(v164.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v168 = e.HasCopyConstructorWithConstParameter();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
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
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasFriends();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v181 = e.HasInClassInitializer();
  if (v181) {
    b.setVal181(static_cast<bool>(v181.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
  }
  auto v184 = e.HasInheritedAssignment();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v186 = e.HasInheritedConstructor();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v193 = e.HasInitializerMethod();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasIrrelevantDestructor();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasKnownLambdaInternalLinkage();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasMoveAssignment();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasMoveConstructor();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasMutableFields();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonLiteralTypeFieldsOrBases();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialCopyAssignment();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialCopyConstructor();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialCopyConstructorForCall();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialDefaultConstructor();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialDestructor();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialDestructorForCall();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasNonTrivialMoveAssignment();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasNonTrivialMoveConstructor();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasNonTrivialMoveConstructorForCall();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasPrivateFields();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasProtectedFields();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasSimpleCopyAssignment();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasSimpleCopyConstructor();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasSimpleDestructor();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasSimpleMoveAssignment();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasSimpleMoveConstructor();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialCopyAssignment();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialCopyConstructor();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialCopyConstructorForCall();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialDefaultConstructor();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialDestructor();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialDestructorForCall();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasTrivialMoveAssignment();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasTrivialMoveConstructor();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasTrivialMoveConstructorForCall();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUninitializedReferenceMember();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredConstructor();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredCopyAssignment();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredCopyConstructor();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserDeclaredDestructor();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserDeclaredMoveAssignment();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasUserDeclaredMoveConstructor();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.HasUserDeclaredMoveOperation();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.HasUserProvidedDefaultConstructor();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.HasVariantMembers();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.ImplicitCopyConstructorHasConstParameter();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsAbstract();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsAggregate();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsAnyDestructorNoReturn();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsCLike();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  auto v289 = e.IsCXX11StandardLayout();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  b.setVal291(e.IsDependentLambda());
  auto v292 = e.IsDynamicClass();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v294 = e.IsEffectivelyFinal();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  auto v296 = e.IsEmpty();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  b.setVal298(e.IsGenericLambda());
  auto v299 = e.IsInterfaceLike();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.IsLiteral();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v133 = e.IsLocalClass();
  if (v133) {
    auto id133 = es.EntityId(v133.value());
    b.setVal133(id133);
    b.setVal303(id133 != mx::kInvalidEntityId);
  } else {
    b.setVal133(mx::kInvalidEntityId);
    b.setVal303(false);
  }
  b.setVal304(e.IsNeverDependentLambda());
  auto v305 = e.IsPOD();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.IsPolymorphic();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.IsStandardLayout();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.IsStructural();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.IsTrivial();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  auto v315 = e.IsTriviallyCopyable();
  if (v315) {
    b.setVal315(static_cast<bool>(v315.value()));
    b.setVal316(true);
  } else {
    b.setVal316(false);
  }
  auto v317 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.MayBeAbstract();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.MayBeDynamicClass();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.MayBeNonDynamicClass();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  do {
    auto ov325 = e.Methods();
    if (!ov325) {
      b.setVal326(false);
      break;
    }
    b.setVal326(true);
    auto v325 = std::move(*ov325);
    auto sv325 = b.initVal325(static_cast<unsigned>(v325.size()));
    auto i325 = 0u;
    for (const auto &e325 : v325) {
      sv325.set(i325, es.EntityId(e325));
      ++i325;
    }
  } while (false);
  auto v327 = e.NeedsImplicitCopyAssignment();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsImplicitCopyConstructor();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsImplicitDefaultConstructor();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsImplicitDestructor();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsImplicitMoveAssignment();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NeedsImplicitMoveConstructor();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
  auto v341 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v341) {
    b.setVal341(static_cast<bool>(v341.value()));
    b.setVal342(true);
  } else {
    b.setVal342(false);
  }
  auto v343 = e.NeedsOverloadResolutionForDestructor();
  if (v343) {
    b.setVal343(static_cast<bool>(v343.value()));
    b.setVal344(true);
  } else {
    b.setVal344(false);
  }
  auto v345 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v345) {
    b.setVal345(static_cast<bool>(v345.value()));
    b.setVal346(true);
  } else {
    b.setVal346(false);
  }
  auto v347 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v347) {
    b.setVal347(static_cast<bool>(v347.value()));
    b.setVal348(true);
  } else {
    b.setVal348(false);
  }
  auto v349 = e.NullFieldOffsetIsZero();
  if (v349) {
    b.setVal349(static_cast<bool>(v349.value()));
    b.setVal350(true);
  } else {
    b.setVal350(false);
  }
  do {
    auto ov149 = e.VirtualBases();
    if (!ov149) {
      b.setVal351(false);
      break;
    }
    b.setVal351(true);
    auto v149 = std::move(*ov149);
    auto sv149 = b.initVal149(static_cast<unsigned>(v149.size()));
    auto i149 = 0u;
    for (const auto &e149 : v149) {
      sv149.set(i149, es.PseudoId(e149));
      ++i149;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t135 = e.ExternToken();
  b.setVal135(es.EntityId(t135));
  auto t136 = e.PointOfInstantiation();
  b.setVal136(es.EntityId(t136));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v352 = e.TemplateArguments();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.PseudoId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.TemplateInstantiationArguments();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.PseudoId(e353));
      ++i353;
    }
  } while (false);
  auto t138 = e.TemplateKeywordToken();
  b.setVal138(es.EntityId(t138));
  auto v139 = e.TypeAsWritten();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
    b.setVal354(id139 != mx::kInvalidEntityId);
  } else {
    b.setVal139(mx::kInvalidEntityId);
    b.setVal354(false);
  }
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
  auto v76 = e.InstantiatedFromMemberEnum();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal104(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal104(false);
  }
  auto v79 = e.IntegerType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal105(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal105(false);
  }
  if (auto r81 = e.IntegerTypeRange(); auto rs81 = r81.Size()) {
    b.setVal81(es.EntityId(r81[0]));
    b.setVal83(es.EntityId(r81[rs81 - 1u]));
  } else {
    b.setVal81(0);
    b.setVal83(0);
  }
  auto v150 = e.ODRHash();
  if (v150) {
    b.setVal150(static_cast<unsigned>(v150.value()));
    b.setVal106(true);
  } else {
    b.setVal106(false);
  }
  auto v86 = e.PromotionType();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
    b.setVal107(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal107(false);
  }
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal108(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal108(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal109(e.IsClosed());
  b.setVal110(e.IsClosedFlag());
  b.setVal111(e.IsClosedNonFlag());
  b.setVal112(e.IsComplete());
  b.setVal113(e.IsFixed());
  b.setVal114(e.IsScoped());
  b.setVal115(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto t57 = e.EllipsisToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.TypenameToken();
  b.setVal58(es.EntityId(t58));
  auto t66 = e.UsingToken();
  b.setVal66(es.EntityId(t66));
  b.setVal74(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v57 = e.AnonymousDeclarationWithTypedefName();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal74(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  b.setVal58(es.EntityId(e.UnderlyingType()));
  b.setVal75(e.IsModed());
  b.setVal80(e.IsTransparentTag());
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
  auto v66 = e.DescribedAliasTemplate();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
    b.setVal82(id66 != mx::kInvalidEntityId);
  } else {
    b.setVal66(mx::kInvalidEntityId);
    b.setVal82(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t66 = e.ColonToken();
  b.setVal66(es.EntityId(t66));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t67 = e.VarianceToken();
  b.setVal67(es.EntityId(t67));
  b.setVal82(e.HasExplicitBound());
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
  auto v56 = e.InstantiatedFromMemberTemplate();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
    b.setVal73(id56 != mx::kInvalidEntityId);
  } else {
    b.setVal56(mx::kInvalidEntityId);
    b.setVal73(false);
  }
  b.setVal57(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal56(es.EntityId(e.ConstraintExpression()));
  b.setVal73(e.IsTypeConcept());
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
  auto t56 = e.AtToken();
  b.setVal56(es.EntityId(t56));
  b.setVal57(es.EntityId(e.GetterMethodDeclaration()));
  auto t58 = e.GetterNameToken();
  b.setVal58(es.EntityId(t58));
  auto t66 = e.LParenToken();
  b.setVal66(es.EntityId(t66));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal67(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal68(es.EntityId(e.SetterMethodDeclaration()));
  auto t76 = e.SetterNameToken();
  b.setVal76(es.EntityId(t76));
  b.setVal79(es.EntityId(e.Type()));
  b.setVal73(e.IsAtomic());
  b.setVal74(e.IsClassProperty());
  b.setVal75(e.IsDirectProperty());
  b.setVal80(e.IsInstanceProperty());
  b.setVal82(e.IsOptional());
  b.setVal84(e.IsReadOnly());
  b.setVal92(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal73(e.DefinedInNSObject());
  b.setVal56(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal57(es.EntityId(e.ClassInterface()));
  b.setVal58(es.EntityId(e.CommandDeclaration()));
  auto t66 = e.DeclaratorEndToken();
  b.setVal66(es.EntityId(t66));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal67(es.EntityId(e.ReturnType()));
  if (auto r68 = e.ReturnTypeSourceRange(); auto rs68 = r68.Size()) {
    b.setVal68(es.EntityId(r68[0]));
    b.setVal76(es.EntityId(r68[rs68 - 1u]));
  } else {
    b.setVal68(0);
    b.setVal76(0);
  }
  auto t79 = e.SelectorStartToken();
  b.setVal79(es.EntityId(t79));
  b.setVal81(es.EntityId(e.SelfDeclaration()));
  b.setVal74(e.HasParameterDestroyedInCallee());
  b.setVal75(e.HasRedeclaration());
  b.setVal80(e.HasRelatedResultType());
  b.setVal82(e.HasSkippedBody());
  b.setVal84(e.IsClassMethod());
  b.setVal92(e.IsDefined());
  b.setVal95(e.IsDesignatedInitializerForTheInterface());
  b.setVal96(e.IsDirectMethod());
  b.setVal97(e.IsInstanceMethod());
  b.setVal98(e.IsOptional());
  b.setVal99(e.IsOverriding());
  b.setVal100(e.IsPropertyAccessor());
  b.setVal101(e.IsRedeclaration());
  b.setVal102(e.IsSynthesizedAccessorStub());
  b.setVal103(e.IsThisDeclarationADesignatedInitializer());
  b.setVal104(e.IsVariadic());
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
  auto t58 = e.AtStartToken();
  b.setVal58(es.EntityId(t58));
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
    auto v179 = e.InstanceProperties();
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
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
    auto v325 = e.Properties();
    auto sv325 = b.initVal325(static_cast<unsigned>(v325.size()));
    auto i325 = 0u;
    for (const auto &e325 : v325) {
      sv325.set(i325, es.EntityId(e325));
      ++i325;
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
  b.setVal73(e.IsClassExtension());
  auto t66 = e.CategoryNameToken();
  b.setVal66(es.EntityId(t66));
  b.setVal67(es.EntityId(e.ClassInterface()));
  b.setVal68(es.EntityId(e.Implementation()));
  auto t76 = e.InstanceVariableLBraceToken();
  b.setVal76(es.EntityId(t76));
  auto t79 = e.InstanceVariableRBraceToken();
  b.setVal79(es.EntityId(t79));
  b.setVal81(es.EntityId(e.NextClassCategory()));
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
  auto v72 = e.ObjCRuntimeNameAsString();
  std::string s72(v72.data(), v72.size());
  b.setVal72(s72);
  b.setVal73(e.HasDefinition());
  b.setVal74(e.IsNonRuntimeProtocol());
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
  b.setVal73(e.DeclaresOrInheritsDesignatedInitializers());
  auto t66 = e.EndOfDefinitionToken();
  b.setVal66(es.EntityId(t66));
  b.setVal67(es.EntityId(e.Implementation()));
  auto v72 = e.ObjCRuntimeNameAsString();
  std::string s72(v72.data(), v72.size());
  b.setVal72(s72);
  auto v68 = e.SuperClass();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
    b.setVal74(id68 != mx::kInvalidEntityId);
  } else {
    b.setVal68(mx::kInvalidEntityId);
    b.setVal74(false);
  }
  auto t76 = e.SuperClassToken();
  b.setVal76(es.EntityId(t76));
  auto v79 = e.SuperClassTypeInfo();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal75(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal75(false);
  }
  b.setVal81(es.EntityId(e.TypeForDeclaration()));
  b.setVal80(e.HasDefinition());
  b.setVal82(e.HasDesignatedInitializers());
  b.setVal84(e.IsArcWeakrefUnavailable());
  b.setVal92(e.IsImplicitInterfaceDeclaration());
  b.setVal83(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
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
  auto t68 = e.CategoryNameToken();
  b.setVal68(es.EntityId(t68));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t67 = e.InstanceVariableLBraceToken();
  b.setVal67(es.EntityId(t67));
  auto t68 = e.InstanceVariableRBraceToken();
  b.setVal68(es.EntityId(t68));
  auto v72 = e.ObjCRuntimeNameAsString();
  std::string s72(v72.data(), v72.size());
  b.setVal72(s72);
  b.setVal76(es.EntityId(e.SuperClass()));
  auto t79 = e.SuperClassToken();
  b.setVal79(es.EntityId(t79));
  b.setVal73(e.HasDestructors());
  b.setVal74(e.HasNonZeroConstructors());
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
  auto t56 = e.AliasToken();
  b.setVal56(es.EntityId(t56));
  b.setVal57(es.EntityId(e.AliasedNamespace()));
  auto t58 = e.NamespaceToken();
  b.setVal58(es.EntityId(t58));
  auto t66 = e.TargetNameToken();
  b.setVal66(es.EntityId(t66));
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
    auto v50 = e.Children();
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
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
    b.setVal49(id48 != mx::kInvalidEntityId);
  } else {
    b.setVal48(mx::kInvalidEntityId);
    b.setVal49(false);
  }
  auto t56 = e.FriendToken();
  b.setVal56(es.EntityId(t56));
  auto v57 = e.FriendType();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
    b.setVal52(id57 != mx::kInvalidEntityId);
  } else {
    b.setVal57(mx::kInvalidEntityId);
    b.setVal52(false);
  }
  b.setVal53(e.IsUnsupportedFriend());
  do {
    auto v78 = e.FriendTypeTemplateParameterLists();
    auto sv78 = b.initVal78(static_cast<unsigned>(v78.size()));
    auto i78 = 0u;
    for (const auto &e78 : v78) {
      sv78.set(i78, es.PseudoId(e78));
      ++i78;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t48 = e.AssemblyToken();
  b.setVal48(es.EntityId(t48));
  b.setVal56(es.EntityId(e.AssemblyString()));
  auto t57 = e.RParenToken();
  b.setVal57(es.EntityId(t57));
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
  auto t48 = e.ExportToken();
  b.setVal48(es.EntityId(t48));
  auto t56 = e.RBraceToken();
  b.setVal56(es.EntityId(t56));
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
