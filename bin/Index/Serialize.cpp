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
  auto v13 = e.FunctionType();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
    b.setVal14(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal14(false);
  }
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v16 = e.NonClosureContext();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
    b.setVal17(id16 != mx::kInvalidEntityId);
  } else {
    b.setVal16(mx::kInvalidEntityId);
    b.setVal17(false);
  }
  b.setVal18(e.HasAttributes());
  b.setVal19(e.HasDefiningAttribute());
  b.setVal20(e.HasOwningModule());
  b.setVal21(e.HasTagIdentifierNamespace());
  b.setVal22(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal23(e.IsDeprecated());
  b.setVal24(e.IsDiscardedInGlobalModuleFragment());
  b.setVal25(e.IsFunctionOrFunctionTemplate());
  b.setVal26(e.IsImplicit());
  b.setVal27(e.IsInAnonymousNamespace());
  b.setVal28(e.IsInExportDeclarationContext());
  b.setVal29(e.IsInLocalScopeForInstantiation());
  b.setVal30(e.IsInStdNamespace());
  b.setVal31(e.IsInvalidDeclaration());
  b.setVal32(e.IsInvisibleOutsideTheOwningModule());
  b.setVal33(e.IsModulePrivate());
  b.setVal34(e.IsOutOfLine());
  b.setVal35(e.IsParameterPack());
  b.setVal36(e.IsReachable());
  b.setVal37(e.IsTemplateDeclaration());
  b.setVal38(e.IsTemplateParameter());
  b.setVal39(e.IsTemplateParameterPack());
  b.setVal40(e.IsTemplated());
  b.setVal41(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal42(e.IsUnavailable());
  b.setVal43(e.IsUnconditionallyVisible());
  b.setVal44(e.IsWeakImported());
  do {
    auto v45 = e.Redeclarations();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal46(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal47(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto t48 = e.Token();
  b.setVal48(es.EntityId(t48));
  if (auto r49 = e.Tokens(); auto rs49 = r49.Size()) {
    b.setVal49(es.EntityId(r49[0]));
    b.setVal50(es.EntityId(r49[rs49 - 1u]));
  } else {
    b.setVal49(0);
    b.setVal50(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.Specialization()));
  b.setVal52(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.ContextParameter()));
  b.setVal52(e.IsNothrow());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal52(e.BlockMissingReturnType());
  b.setVal55(e.CanAvoidCopyToHeap());
  b.setVal56(e.CapturesCXXThis());
  b.setVal57(e.DoesNotEscape());
  auto v51 = e.BlockManglingContextDeclaration();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
    b.setVal58(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto t59 = e.CaretToken();
  b.setVal59(es.EntityId(t59));
  b.setVal60(es.EntityId(e.CompoundBody()));
  b.setVal61(es.EntityId(e.SignatureAsWritten()));
  b.setVal62(e.HasCaptures());
  b.setVal63(e.IsConversionFromLambda());
  b.setVal64(e.IsVariadic());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v54 = e.ParameterDeclarations();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  pasta::DeclContext dc65(e);
  auto v65 = dc65.AlreadyLoadedDeclarations();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const pasta::Decl &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeAccessSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t51 = e.AccessSpecifierToken();
  b.setVal51(es.EntityId(t51));
  auto t59 = e.ColonToken();
  b.setVal59(es.EntityId(t59));
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
    auto v53 = e.Varlists();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
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
    auto v53 = e.Varlists();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.AssertExpression()));
  b.setVal59(es.EntityId(e.Message()));
  auto t60 = e.RParenToken();
  b.setVal60(es.EntityId(t60));
  b.setVal52(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializePragmaDetectMismatchDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v66 = e.Name();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v67 = e.Value();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
}

void SerializePragmaCommentDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v66 = e.Argument();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal51(es.EntityId(e.GetterCXXConstructor()));
  b.setVal59(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal60(es.EntityId(e.PropertyDeclaration()));
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal61(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t69 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal69(es.EntityId(t69));
  b.setVal70(es.EntityId(e.SetterCXXAssignment()));
  b.setVal71(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal52(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal66(e.Name());
  auto v72 = e.ObjCFStringFormattingFamily();
  if (v72) {
    b.setVal72(static_cast<unsigned char>(v72.value()));
    b.setVal52(true);
  } else {
    b.setVal52(false);
  }
  b.setVal67(e.QualifiedNameAsString());
  b.setVal51(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal55(e.HasExternalFormalLinkage());
  b.setVal56(e.HasLinkage());
  b.setVal57(e.HasLinkageBeenComputed());
  b.setVal58(e.IsCXXClassMember());
  b.setVal62(e.IsCXXInstanceMember());
  b.setVal63(e.IsExternallyDeclarable());
  b.setVal64(e.IsExternallyVisible());
  b.setVal74(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v75 = e.MSAssemblyLabel();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal59(es.EntityId(e.Statement()));
  b.setVal76(e.IsGnuLocal());
  b.setVal77(e.IsMSAssemblyLabel());
  b.setVal78(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v53 = e.Shadows();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
}

void SerializeUsingEnumDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  b.setVal59(es.EntityId(e.EnumDeclaration()));
  auto t60 = e.EnumToken();
  b.setVal60(es.EntityId(t60));
  auto t61 = e.UsingToken();
  b.setVal61(es.EntityId(t61));
}

void SerializeUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t59 = e.UsingToken();
  b.setVal59(es.EntityId(t59));
  b.setVal76(e.HasTypename());
  b.setVal77(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal59(es.EntityId(e.Type()));
  b.setVal76(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t60 = e.EllipsisToken();
  b.setVal60(es.EntityId(t60));
  auto t61 = e.UsingToken();
  b.setVal61(es.EntityId(t61));
  b.setVal77(e.IsAccessDeclaration());
  b.setVal78(e.IsPackExpansion());
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
  b.setVal60(es.EntityId(e.Combiner()));
  b.setVal61(es.EntityId(e.CombinerIn()));
  b.setVal69(es.EntityId(e.CombinerOut()));
  b.setVal70(es.EntityId(e.InitializerOriginal()));
  b.setVal71(es.EntityId(e.InitializerPrivate()));
  b.setVal79(es.EntityId(e.Initializer()));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
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
    auto v53 = e.Chain();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  auto v60 = e.AnonymousField();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal77(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  auto v61 = e.VariableDeclaration();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
    b.setVal78(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal78(false);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v60 = e.InitializerExpression();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal77(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal77(false);
  }
}

void SerializeDeclaratorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t60 = e.FirstInnerToken();
  b.setVal60(es.EntityId(t60));
  auto t61 = e.FirstOuterToken();
  b.setVal61(es.EntityId(t61));
  auto v69 = e.TrailingRequiresClause();
  if (v69) {
    auto id69 = es.EntityId(v69.value());
    b.setVal69(id69);
    b.setVal77(id69 != mx::kInvalidEntityId);
  } else {
    b.setVal69(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  auto t70 = e.TypeSpecEndToken();
  b.setVal70(es.EntityId(t70));
  auto t71 = e.TypeSpecStartToken();
  b.setVal71(es.EntityId(t71));
  do {
    auto v81 = e.TemplateParameterLists();
    auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
    auto i81 = 0u;
    for (const auto &e81 : v81) {
      sv81.set(i81, es.PseudoId(e81));
      ++i81;
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
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal78(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  auto v82 = e.Initializer();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
    b.setVal83(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal83(false);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v84 = e.InitializingDeclaration();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
    b.setVal85(id84 != mx::kInvalidEntityId);
  } else {
    b.setVal84(mx::kInvalidEntityId);
    b.setVal85(false);
  }
  auto v86 = e.InstantiatedFromStaticDataMember();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
    b.setVal87(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal87(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t89 = e.PointOfInstantiation();
  b.setVal89(es.EntityId(t89));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v94 = e.TemplateInstantiationPattern();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
    b.setVal95(id94 != mx::kInvalidEntityId);
  } else {
    b.setVal94(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal98(e.HasConstantInitialization());
  b.setVal99(e.HasDependentAlignment());
  b.setVal100(e.HasExternalStorage());
  auto v101 = e.HasFlexibleArrayInitializer();
  if (v101) {
    b.setVal101(static_cast<bool>(v101.value()));
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
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

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v136 = e.DefaultArgument();
  if (v136) {
    auto id136 = es.EntityId(v136.value());
    b.setVal136(id136);
    b.setVal137(id136 != mx::kInvalidEntityId);
  } else {
    b.setVal136(mx::kInvalidEntityId);
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
  b.setVal141(es.EntityId(e.OriginalType()));
  auto v142 = e.UninstantiatedDefaultArgument();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
    b.setVal143(id142 != mx::kInvalidEntityId);
  } else {
    b.setVal142(mx::kInvalidEntityId);
    b.setVal143(false);
  }
  b.setVal144(e.HasDefaultArgument());
  b.setVal145(e.HasInheritedDefaultArgument());
  b.setVal146(e.HasUninstantiatedDefaultArgument());
  b.setVal147(e.HasUnparsedDefaultArgument());
  b.setVal148(e.IsDestroyedInCallee());
  b.setVal149(e.IsKNRPromoted());
  b.setVal150(e.IsObjCMethodParameter());
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
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v53 = e.Bindings();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto t136 = e.ExternToken();
  b.setVal136(es.EntityId(t136));
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v151 = e.TemplateArguments();
    auto sv151 = b.initVal151(static_cast<unsigned>(v151.size()));
    auto i151 = 0u;
    for (const auto &e151 : v151) {
      sv151.set(i151, es.PseudoId(e151));
      ++i151;
    }
  } while (false);
  do {
    auto v152 = e.TemplateInstantiationArguments();
    auto sv152 = b.initVal152(static_cast<unsigned>(v152.size()));
    auto i152 = 0u;
    for (const auto &e152 : v152) {
      sv152.set(i152, es.PseudoId(e152));
      ++i152;
    }
  } while (false);
  auto t138 = e.TemplateKeywordToken();
  b.setVal138(es.EntityId(t138));
  b.setVal139(es.EntityId(e.TypeAsWritten()));
  b.setVal137(e.IsClassScopeExplicitSpecialization());
  b.setVal143(e.IsExplicitInstantiationOrSpecialization());
  b.setVal144(e.IsExplicitSpecialization());
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
  b.setVal78(e.DefaultArgumentWasInherited());
  auto v79 = e.DefaultArgument();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal83(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal83(false);
  }
  auto t82 = e.DefaultArgumentToken();
  b.setVal82(es.EntityId(t82));
  auto v153 = e.NumExpansionTypes();
  if (v153) {
    b.setVal153(static_cast<unsigned>(v153.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  auto v84 = e.PlaceholderTypeConstraint();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
    b.setVal87(id84 != mx::kInvalidEntityId);
  } else {
    b.setVal84(mx::kInvalidEntityId);
    b.setVal87(false);
  }
  b.setVal95(e.HasDefaultArgument());
  b.setVal98(e.HasPlaceholderTypeConstraint());
  b.setVal99(e.IsExpandedParameterPack());
  b.setVal100(e.IsPackExpansion());
  do {
    auto v53 = e.ExpansionTypes();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
}

void SerializeMSPropertyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal78(e.HasGetter());
  b.setVal83(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal78(e.UsesFPIntrin());
  auto v83 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v83) {
    b.setVal83(static_cast<bool>(v83.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  b.setVal87(e.DoesThisDeclarationHaveABody());
  b.setVal79(es.EntityId(e.CallResultType()));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal82(es.EntityId(e.DeclaredReturnType()));
  auto t84 = e.EllipsisToken();
  b.setVal84(es.EntityId(t84));
  if (auto r86 = e.ExceptionSpecSourceRange(); auto rs86 = r86.Size()) {
    b.setVal86(es.EntityId(r86[0]));
    b.setVal89(es.EntityId(r86[rs86 - 1u]));
  } else {
    b.setVal86(0);
    b.setVal89(0);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v94 = e.InstantiatedFromDeclaration();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
    b.setVal95(id94 != mx::kInvalidEntityId);
  } else {
    b.setVal94(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v136 = e.InstantiatedFromMemberFunction();
  if (v136) {
    auto id136 = es.EntityId(v136.value());
    b.setVal136(id136);
    b.setVal98(id136 != mx::kInvalidEntityId);
  } else {
    b.setVal136(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v153 = e.ODRHash();
  if (v153) {
    b.setVal153(static_cast<unsigned>(v153.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r138 = e.ParametersSourceRange(); auto rs138 = r138.Size()) {
    b.setVal138(es.EntityId(r138[0]));
    b.setVal139(es.EntityId(r138[rs138 - 1u]));
  } else {
    b.setVal138(0);
    b.setVal139(0);
  }
  auto t141 = e.PointOfInstantiation();
  b.setVal141(es.EntityId(t141));
  b.setVal142(es.EntityId(e.ReturnType()));
  if (auto r154 = e.ReturnTypeSourceRange(); auto rs154 = r154.Size()) {
    b.setVal154(es.EntityId(r154[0]));
    b.setVal155(es.EntityId(r154[rs154 - 1u]));
  } else {
    b.setVal154(0);
    b.setVal155(0);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v156 = e.TemplateInstantiationPattern();
  if (v156) {
    auto id156 = es.EntityId(v156.value());
    b.setVal156(id156);
    b.setVal100(id156 != mx::kInvalidEntityId);
  } else {
    b.setVal156(mx::kInvalidEntityId);
    b.setVal100(false);
  }
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal101(e.HasImplicitReturnZero());
  b.setVal102(e.HasInheritedPrototype());
  b.setVal103(e.HasOneParameterOrDefaultArguments());
  b.setVal104(e.HasPrototype());
  b.setVal105(e.HasSkippedBody());
  b.setVal106(e.HasTrivialBody());
  b.setVal107(e.HasWrittenPrototype());
  b.setVal108(e.InstantiationIsPending());
  b.setVal109(e.IsCPUDispatchMultiVersion());
  b.setVal110(e.IsCPUSpecificMultiVersion());
  b.setVal111(e.IsConsteval());
  b.setVal112(e.IsConstexpr());
  b.setVal113(e.IsConstexprSpecified());
  b.setVal114(e.IsDefaulted());
  b.setVal115(e.IsDeleted());
  b.setVal116(e.IsDeletedAsWritten());
  b.setVal117(e.IsDestroyingOperatorDelete());
  b.setVal118(e.IsExplicitlyDefaulted());
  b.setVal119(e.IsExternC());
  b.setVal120(e.IsFunctionTemplateSpecialization());
  b.setVal121(e.IsGlobal());
  b.setVal122(e.IsImplicitlyInstantiable());
  b.setVal123(e.IsInExternCContext());
  b.setVal124(e.IsInExternCXXContext());
  b.setVal125(e.IsIneligibleOrNotSelected());
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
  b.setVal143(e.IsMultiVersion());
  b.setVal144(e.IsNoReturn());
  b.setVal145(e.IsOverloadedOperator());
  b.setVal146(e.IsPure());
  b.setVal147(e.IsReplaceableGlobalAllocationFunction());
  auto v148 = e.IsReservedGlobalPlacementOperator();
  if (v148) {
    b.setVal148(static_cast<bool>(v148.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  b.setVal150(e.IsStatic());
  b.setVal157(e.IsTargetClonesMultiVersion());
  b.setVal158(e.IsTargetMultiVersion());
  b.setVal159(e.IsTemplateInstantiation());
  b.setVal160(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal161(e.IsTrivial());
  b.setVal162(e.IsTrivialForCall());
  b.setVal163(e.IsUserProvided());
  b.setVal164(e.IsVariadic());
  b.setVal165(e.IsVirtualAsWritten());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  b.setVal166(e.UsesSEHTry());
  b.setVal167(e.WillHaveBody());
  auto v168 = e.Body();
  if (v168) {
    auto id168 = es.EntityId(v168.value());
    b.setVal168(id168);
    b.setVal169(id168 != mx::kInvalidEntityId);
  } else {
    b.setVal168(mx::kInvalidEntityId);
    b.setVal169(false);
  }
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal140(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v170 = e.ThisObjectType();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
    b.setVal171(id170 != mx::kInvalidEntityId);
  } else {
    b.setVal170(mx::kInvalidEntityId);
    b.setVal171(false);
  }
  auto v172 = e.ThisType();
  if (v172) {
    auto id172 = es.EntityId(v172.value());
    b.setVal172(id172);
    b.setVal173(id172 != mx::kInvalidEntityId);
  } else {
    b.setVal172(mx::kInvalidEntityId);
    b.setVal173(false);
  }
  b.setVal174(e.HasInlineBody());
  b.setVal175(e.IsConst());
  b.setVal176(e.IsCopyAssignmentOperator());
  b.setVal177(e.IsInstance());
  b.setVal178(e.IsLambdaStaticInvoker());
  b.setVal179(e.IsMoveAssignmentOperator());
  b.setVal180(e.IsVirtual());
  b.setVal181(e.IsVolatile());
  do {
    auto v65 = e.OverriddenMethods();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
  do {
    auto v182 = e.ParameterDeclarations();
    auto sv182 = b.initVal182(static_cast<unsigned>(v182.size()));
    auto i182 = 0u;
    for (const auto &e182 : v182) {
      sv182.set(i182, es.EntityId(e182));
      ++i182;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v183 = e.OperatorDelete();
  if (v183) {
    auto id183 = es.EntityId(v183.value());
    b.setVal183(id183);
    b.setVal184(id183 != mx::kInvalidEntityId);
  } else {
    b.setVal183(mx::kInvalidEntityId);
    b.setVal184(false);
  }
  auto v185 = e.OperatorDeleteThisArgument();
  if (v185) {
    auto id185 = es.EntityId(v185.value());
    b.setVal185(id185);
    b.setVal186(id185 != mx::kInvalidEntityId);
  } else {
    b.setVal185(mx::kInvalidEntityId);
    b.setVal186(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal183(es.EntityId(e.ConversionType()));
  b.setVal184(e.IsExplicit());
  b.setVal186(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v183 = e.TargetConstructor();
  if (v183) {
    auto id183 = es.EntityId(v183.value());
    b.setVal183(id183);
    b.setVal184(id183 != mx::kInvalidEntityId);
  } else {
    b.setVal183(mx::kInvalidEntityId);
    b.setVal184(false);
  }
  b.setVal186(e.IsDefaultConstructor());
  b.setVal187(e.IsDelegatingConstructor());
  b.setVal188(e.IsExplicit());
  b.setVal189(e.IsInheritingConstructor());
  b.setVal190(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal170(es.EntityId(e.CorrespondingConstructor()));
  b.setVal171(e.IsCopyDeductionCandidate());
  b.setVal173(e.IsExplicit());
  do {
    auto v65 = e.ParameterDeclarations();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
}

void SerializeFieldDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v79 = e.BitWidth();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal78(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  auto v82 = e.CapturedVLAType();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
    b.setVal83(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal83(false);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v84 = e.InClassInitializer();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
    b.setVal85(id84 != mx::kInvalidEntityId);
  } else {
    b.setVal84(mx::kInvalidEntityId);
    b.setVal85(false);
  }
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
  b.setVal86(es.EntityId(e.ContainingInterface()));
  b.setVal89(es.EntityId(e.NextInstanceVariable()));
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
  b.setVal60(es.EntityId(e.Binding()));
  b.setVal61(es.EntityId(e.DecomposedDeclaration()));
  b.setVal69(es.EntityId(e.HoldingVariable()));
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
  b.setVal60(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal59(es.EntityId(e.Introducer()));
  auto v60 = e.NextUsingShadowDeclaration();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal76(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal61(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal77(e.ConstructsVirtualBase());
  b.setVal69(es.EntityId(e.ConstructedBaseClass()));
  auto v70 = e.ConstructedBaseClassShadowDeclaration();
  if (v70) {
    auto id70 = es.EntityId(v70.value());
    b.setVal70(id70);
    b.setVal78(id70 != mx::kInvalidEntityId);
  } else {
    b.setVal70(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal71(es.EntityId(e.NominatedBaseClass()));
  auto v79 = e.NominatedBaseClassShadowDeclaration();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal83(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal83(false);
  }
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v53 = e.Expansions();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  b.setVal59(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t59 = e.IdentifierToken();
  b.setVal59(es.EntityId(t59));
  auto t60 = e.NamespaceKeyToken();
  b.setVal60(es.EntityId(t60));
  b.setVal61(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t69 = e.UsingToken();
  b.setVal69(es.EntityId(t69));
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
  auto v59 = e.TypeForDeclaration();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
    b.setVal76(id59 != mx::kInvalidEntityId);
  } else {
    b.setVal59(mx::kInvalidEntityId);
    b.setVal76(false);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal77(e.DefaultArgumentWasInherited());
  auto v60 = e.DefaultArgument();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal78(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  auto v61 = e.DefaultArgumentInfo();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
    b.setVal83(id61 != mx::kInvalidEntityId);
  } else {
    b.setVal61(mx::kInvalidEntityId);
    b.setVal83(false);
  }
  auto t69 = e.DefaultArgumentToken();
  b.setVal69(es.EntityId(t69));
  b.setVal85(e.HasDefaultArgument());
  b.setVal87(e.HasTypeConstraint());
  b.setVal95(e.IsExpandedParameterPack());
  b.setVal98(e.IsPackExpansion());
  b.setVal99(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  if (auto r60 = e.BraceRange(); auto rs60 = r60.Size()) {
    b.setVal60(es.EntityId(r60[0]));
    b.setVal61(es.EntityId(r60[rs60 - 1u]));
  } else {
    b.setVal60(0);
    b.setVal61(0);
  }
  auto t69 = e.FirstInnerToken();
  b.setVal69(es.EntityId(t69));
  auto t70 = e.FirstOuterToken();
  b.setVal70(es.EntityId(t70));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v71 = e.TypedefNameForAnonymousDeclaration();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
    b.setVal77(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  b.setVal78(e.HasNameForLinkage());
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
  b.setVal104(e.IsThisDeclarationADemotedDefinition());
  b.setVal105(e.IsUnion());
  b.setVal106(e.MayHaveOutOfDateDefinition());
  do {
    auto v81 = e.TemplateParameterLists();
    auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
    auto i81 = 0u;
    for (const auto &e81 : v81) {
      sv81.set(i81, es.PseudoId(e81));
      ++i81;
    }
  } while (false);
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal107(e.CanPassInRegisters());
  do {
    auto v54 = e.Fields();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal108(e.HasFlexibleArrayMember());
  b.setVal109(e.HasLoadedFieldsFromExternalStorage());
  b.setVal110(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal111(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal112(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal113(e.HasObjectMember());
  b.setVal114(e.HasVolatileMember());
  b.setVal115(e.IsAnonymousStructOrUnion());
  b.setVal116(e.IsCapturedRecord());
  b.setVal117(e.IsInjectedClassName());
  b.setVal118(e.IsLambda());
  b.setVal119(e.IsMsStruct());
  b.setVal120(e.IsNonTrivialToPrimitiveCopy());
  b.setVal121(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal122(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal123(e.IsOrContainsUnion());
  b.setVal124(e.IsParameterDestroyedInCallee());
  b.setVal125(e.IsRandomized());
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
    auto ov151 = e.Bases();
    if (!ov151) {
      b.setVal129(false);
      break;
    }
    b.setVal129(true);
    auto v151 = std::move(*ov151);
    auto sv151 = b.initVal151(static_cast<unsigned>(v151.size()));
    auto i151 = 0u;
    for (const auto &e151 : v151) {
      sv151.set(i151, es.PseudoId(e151));
      ++i151;
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
    auto v65 = e.Constructors();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
  do {
    auto ov182 = e.Friends();
    if (!ov182) {
      b.setVal131(false);
      break;
    }
    b.setVal131(true);
    auto v182 = std::move(*ov182);
    auto sv182 = b.initVal182(static_cast<unsigned>(v182.size()));
    auto i182 = 0u;
    for (const auto &e182 : v182) {
      sv182.set(i182, es.EntityId(e182));
      ++i182;
    }
  } while (false);
  auto v79 = e.Destructor();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal132(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal132(false);
  }
  auto v153 = e.GenericLambdaTemplateParameterList();
  if (v153) {
    b.setVal153(es.PseudoId(v153.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  auto v82 = e.InstantiatedFromMemberClass();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
    b.setVal134(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal134(false);
  }
  auto v84 = e.LambdaCallOperator();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
    b.setVal137(id84 != mx::kInvalidEntityId);
  } else {
    b.setVal84(mx::kInvalidEntityId);
    b.setVal137(false);
  }
  auto v91 = e.LambdaCaptureDefault();
  if (v91) {
    b.setVal91(static_cast<unsigned char>(v91.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v86 = e.LambdaContextDeclaration();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
    b.setVal144(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal144(false);
  }
  do {
    auto ov191 = e.LambdaExplicitTemplateParameters();
    if (!ov191) {
      b.setVal145(false);
      break;
    }
    b.setVal145(true);
    auto v191 = std::move(*ov191);
    auto sv191 = b.initVal191(static_cast<unsigned>(v191.size()));
    auto i191 = 0u;
    for (const auto &e191 : v191) {
      sv191.set(i191, es.EntityId(e191));
      ++i191;
    }
  } while (false);
  auto v192 = e.LambdaManglingNumber();
  if (v192) {
    b.setVal192(static_cast<unsigned>(v192.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v89 = e.LambdaType();
  if (v89) {
    auto id89 = es.EntityId(v89.value());
    b.setVal89(id89);
    b.setVal147(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
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
  auto v193 = e.NumBases();
  if (v193) {
    b.setVal193(static_cast<unsigned>(v193.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v194 = e.NumVirtualBases();
  if (v194) {
    b.setVal194(static_cast<unsigned>(v194.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  auto v195 = e.ODRHash();
  if (v195) {
    b.setVal195(static_cast<unsigned>(v195.value()));
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v94 = e.TemplateInstantiationPattern();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
    b.setVal158(id94 != mx::kInvalidEntityId);
  } else {
    b.setVal94(mx::kInvalidEntityId);
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
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasCopyAssignmentWithConstParameter();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal169(true);
  } else {
    b.setVal169(false);
  }
  auto v171 = e.HasCopyConstructorWithConstParameter();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasDefaultConstructor();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v176 = e.HasDefinition();
  if (v176) {
    b.setVal176(static_cast<bool>(v176.value()));
    b.setVal177(true);
  } else {
    b.setVal177(false);
  }
  auto v178 = e.HasDirectFields();
  if (v178) {
    b.setVal178(static_cast<bool>(v178.value()));
    b.setVal179(true);
  } else {
    b.setVal179(false);
  }
  auto v180 = e.HasFriends();
  if (v180) {
    b.setVal180(static_cast<bool>(v180.value()));
    b.setVal181(true);
  } else {
    b.setVal181(false);
  }
  auto v184 = e.HasInClassInitializer();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v187 = e.HasInheritedAssignment();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasInheritedConstructor();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v196 = e.HasInitializerMethod();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasIrrelevantDestructor();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasKnownLambdaInternalLinkage();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasMoveAssignment();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasMoveConstructor();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasMutableFields();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonLiteralTypeFieldsOrBases();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialCopyAssignment();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialCopyConstructor();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasNonTrivialCopyConstructorForCall();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasNonTrivialDefaultConstructor();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasNonTrivialDestructor();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasNonTrivialDestructorForCall();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasNonTrivialMoveAssignment();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasNonTrivialMoveConstructor();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasNonTrivialMoveConstructorForCall();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasPrivateFields();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasProtectedFields();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasSimpleCopyAssignment();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasSimpleCopyConstructor();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasSimpleDestructor();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasSimpleMoveAssignment();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasSimpleMoveConstructor();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialCopyAssignment();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialCopyConstructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasTrivialCopyConstructorForCall();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasTrivialDefaultConstructor();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasTrivialDestructor();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasTrivialDestructorForCall();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasTrivialMoveAssignment();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasTrivialMoveConstructor();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasTrivialMoveConstructorForCall();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUninitializedReferenceMember();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserDeclaredConstructor();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasUserDeclaredCopyAssignment();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.HasUserDeclaredCopyConstructor();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.HasUserDeclaredDestructor();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.HasUserDeclaredMoveAssignment();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.HasUserDeclaredMoveConstructor();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.HasUserDeclaredMoveOperation();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.HasUserProvidedDefaultConstructor();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.HasVariantMembers();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  auto v280 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  auto v282 = e.ImplicitCopyConstructorHasConstParameter();
  if (v282) {
    b.setVal282(static_cast<bool>(v282.value()));
    b.setVal283(true);
  } else {
    b.setVal283(false);
  }
  auto v284 = e.IsAbstract();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  auto v286 = e.IsAggregate();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v288 = e.IsAnyDestructorNoReturn();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  auto v290 = e.IsCLike();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v292 = e.IsCXX11StandardLayout();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  b.setVal294(e.IsDependentLambda());
  auto v295 = e.IsDynamicClass();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsEffectivelyFinal();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsEmpty();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  b.setVal301(e.IsGenericLambda());
  auto v302 = e.IsInterfaceLike();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsLiteral();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v136 = e.IsLocalClass();
  if (v136) {
    auto id136 = es.EntityId(v136.value());
    b.setVal136(id136);
    b.setVal306(id136 != mx::kInvalidEntityId);
  } else {
    b.setVal136(mx::kInvalidEntityId);
    b.setVal306(false);
  }
  b.setVal307(e.IsNeverDependentLambda());
  auto v308 = e.IsPOD();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.IsPolymorphic();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.IsStandardLayout();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.IsStructural();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.IsTrivial();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.IsTriviallyCopyable();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.MayBeAbstract();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.MayBeDynamicClass();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.MayBeNonDynamicClass();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  do {
    auto ov328 = e.Methods();
    if (!ov328) {
      b.setVal329(false);
      break;
    }
    b.setVal329(true);
    auto v328 = std::move(*ov328);
    auto sv328 = b.initVal328(static_cast<unsigned>(v328.size()));
    auto i328 = 0u;
    for (const auto &e328 : v328) {
      sv328.set(i328, es.EntityId(e328));
      ++i328;
    }
  } while (false);
  auto v330 = e.NeedsImplicitCopyAssignment();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsImplicitCopyConstructor();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsImplicitDefaultConstructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsImplicitDestructor();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsImplicitMoveAssignment();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsImplicitMoveConstructor();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  auto v344 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  auto v346 = e.NeedsOverloadResolutionForDestructor();
  if (v346) {
    b.setVal346(static_cast<bool>(v346.value()));
    b.setVal347(true);
  } else {
    b.setVal347(false);
  }
  auto v348 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v348) {
    b.setVal348(static_cast<bool>(v348.value()));
    b.setVal349(true);
  } else {
    b.setVal349(false);
  }
  auto v350 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v350) {
    b.setVal350(static_cast<bool>(v350.value()));
    b.setVal351(true);
  } else {
    b.setVal351(false);
  }
  auto v352 = e.NullFieldOffsetIsZero();
  if (v352) {
    b.setVal352(static_cast<bool>(v352.value()));
    b.setVal353(true);
  } else {
    b.setVal353(false);
  }
  do {
    auto ov152 = e.VirtualBases();
    if (!ov152) {
      b.setVal354(false);
      break;
    }
    b.setVal354(true);
    auto v152 = std::move(*ov152);
    auto sv152 = b.initVal152(static_cast<unsigned>(v152.size()));
    auto i152 = 0u;
    for (const auto &e152 : v152) {
      sv152.set(i152, es.PseudoId(e152));
      ++i152;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t138 = e.ExternToken();
  b.setVal138(es.EntityId(t138));
  auto t139 = e.PointOfInstantiation();
  b.setVal139(es.EntityId(t139));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v355 = e.TemplateArguments();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.PseudoId(e355));
      ++i355;
    }
  } while (false);
  do {
    auto v356 = e.TemplateInstantiationArguments();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.PseudoId(e356));
      ++i356;
    }
  } while (false);
  auto t141 = e.TemplateKeywordToken();
  b.setVal141(es.EntityId(t141));
  auto v142 = e.TypeAsWritten();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
    b.setVal357(id142 != mx::kInvalidEntityId);
  } else {
    b.setVal142(mx::kInvalidEntityId);
    b.setVal357(false);
  }
  b.setVal358(e.IsClassScopeExplicitSpecialization());
  b.setVal359(e.IsExplicitInstantiationOrSpecialization());
  b.setVal360(e.IsExplicitSpecialization());
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
    auto v54 = e.Enumerators();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  auto v79 = e.InstantiatedFromMemberEnum();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal107(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal107(false);
  }
  auto v82 = e.IntegerType();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
    b.setVal108(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal108(false);
  }
  if (auto r84 = e.IntegerTypeRange(); auto rs84 = r84.Size()) {
    b.setVal84(es.EntityId(r84[0]));
    b.setVal86(es.EntityId(r84[rs84 - 1u]));
  } else {
    b.setVal84(0);
    b.setVal86(0);
  }
  auto v153 = e.ODRHash();
  if (v153) {
    b.setVal153(static_cast<unsigned>(v153.value()));
    b.setVal109(true);
  } else {
    b.setVal109(false);
  }
  auto v89 = e.PromotionType();
  if (v89) {
    auto id89 = es.EntityId(v89.value());
    b.setVal89(id89);
    b.setVal110(id89 != mx::kInvalidEntityId);
  } else {
    b.setVal89(mx::kInvalidEntityId);
    b.setVal110(false);
  }
  auto v94 = e.TemplateInstantiationPattern();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
    b.setVal111(id94 != mx::kInvalidEntityId);
  } else {
    b.setVal94(mx::kInvalidEntityId);
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
  auto t60 = e.EllipsisToken();
  b.setVal60(es.EntityId(t60));
  auto t61 = e.TypenameToken();
  b.setVal61(es.EntityId(t61));
  auto t69 = e.UsingToken();
  b.setVal69(es.EntityId(t69));
  b.setVal77(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v60 = e.AnonymousDeclarationWithTypedefName();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal77(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  b.setVal61(es.EntityId(e.UnderlyingType()));
  b.setVal78(e.IsModed());
  b.setVal83(e.IsTransparentTag());
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
  auto v69 = e.DescribedAliasTemplate();
  if (v69) {
    auto id69 = es.EntityId(v69.value());
    b.setVal69(id69);
    b.setVal85(id69 != mx::kInvalidEntityId);
  } else {
    b.setVal69(mx::kInvalidEntityId);
    b.setVal85(false);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t69 = e.ColonToken();
  b.setVal69(es.EntityId(t69));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t70 = e.VarianceToken();
  b.setVal70(es.EntityId(t70));
  b.setVal85(e.HasExplicitBound());
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
  auto v59 = e.InstantiatedFromMemberTemplate();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
    b.setVal76(id59 != mx::kInvalidEntityId);
  } else {
    b.setVal59(mx::kInvalidEntityId);
    b.setVal76(false);
  }
  b.setVal60(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal59(es.EntityId(e.ConstraintExpression()));
  b.setVal76(e.IsTypeConcept());
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
  auto t59 = e.AtToken();
  b.setVal59(es.EntityId(t59));
  b.setVal60(es.EntityId(e.GetterMethodDeclaration()));
  auto t61 = e.GetterNameToken();
  b.setVal61(es.EntityId(t61));
  auto t69 = e.LParenToken();
  b.setVal69(es.EntityId(t69));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal70(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal71(es.EntityId(e.SetterMethodDeclaration()));
  auto t79 = e.SetterNameToken();
  b.setVal79(es.EntityId(t79));
  b.setVal82(es.EntityId(e.Type()));
  b.setVal76(e.IsAtomic());
  b.setVal77(e.IsClassProperty());
  b.setVal78(e.IsDirectProperty());
  b.setVal83(e.IsInstanceProperty());
  b.setVal85(e.IsOptional());
  b.setVal87(e.IsReadOnly());
  b.setVal95(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal76(e.DefinedInNSObject());
  b.setVal59(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal60(es.EntityId(e.ClassInterface()));
  b.setVal61(es.EntityId(e.CommandDeclaration()));
  auto t69 = e.DeclaratorEndToken();
  b.setVal69(es.EntityId(t69));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal70(es.EntityId(e.ReturnType()));
  if (auto r71 = e.ReturnTypeSourceRange(); auto rs71 = r71.Size()) {
    b.setVal71(es.EntityId(r71[0]));
    b.setVal79(es.EntityId(r71[rs71 - 1u]));
  } else {
    b.setVal71(0);
    b.setVal79(0);
  }
  auto t82 = e.SelectorStartToken();
  b.setVal82(es.EntityId(t82));
  b.setVal84(es.EntityId(e.SelfDeclaration()));
  b.setVal77(e.HasParameterDestroyedInCallee());
  b.setVal78(e.HasRedeclaration());
  b.setVal83(e.HasRelatedResultType());
  b.setVal85(e.HasSkippedBody());
  b.setVal87(e.IsClassMethod());
  b.setVal95(e.IsDefined());
  b.setVal98(e.IsDesignatedInitializerForTheInterface());
  b.setVal99(e.IsDirectMethod());
  b.setVal100(e.IsInstanceMethod());
  b.setVal101(e.IsOptional());
  b.setVal102(e.IsOverriding());
  b.setVal103(e.IsPropertyAccessor());
  b.setVal104(e.IsRedeclaration());
  b.setVal105(e.IsSynthesizedAccessorStub());
  b.setVal106(e.IsThisDeclarationADesignatedInitializer());
  b.setVal107(e.IsVariadic());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v54 = e.SelectorTokens();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  pasta::DeclContext dc65(e);
  auto v65 = dc65.AlreadyLoadedDeclarations();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const pasta::Decl &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeObjCContainerDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v53 = e.ClassMethods();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v54 = e.ClassProperties();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  if (auto r59 = e.AtEndRange(); auto rs59 = r59.Size()) {
    b.setVal59(es.EntityId(r59[0]));
    b.setVal60(es.EntityId(r59[rs59 - 1u]));
  } else {
    b.setVal59(0);
    b.setVal60(0);
  }
  auto t61 = e.AtStartToken();
  b.setVal61(es.EntityId(t61));
  do {
    auto v65 = e.InstanceMethods();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
  do {
    auto v182 = e.InstanceProperties();
    auto sv182 = b.initVal182(static_cast<unsigned>(v182.size()));
    auto i182 = 0u;
    for (const auto &e182 : v182) {
      sv182.set(i182, es.EntityId(e182));
      ++i182;
    }
  } while (false);
  do {
    auto v191 = e.Methods();
    auto sv191 = b.initVal191(static_cast<unsigned>(v191.size()));
    auto i191 = 0u;
    for (const auto &e191 : v191) {
      sv191.set(i191, es.EntityId(e191));
      ++i191;
    }
  } while (false);
  do {
    auto v328 = e.Properties();
    auto sv328 = b.initVal328(static_cast<unsigned>(v328.size()));
    auto i328 = 0u;
    for (const auto &e328 : v328) {
      sv328.set(i328, es.EntityId(e328));
      ++i328;
    }
  } while (false);
  pasta::DeclContext dc361(e);
  auto v361 = dc361.AlreadyLoadedDeclarations();
  auto sv361 = b.initVal361(static_cast<unsigned>(v361.size()));
  auto i361 = 0u;
  for (const pasta::Decl &e361 : v361) {
    sv361.set(i361, es.EntityId(e361));
    ++i361;
  }
}

void SerializeObjCCategoryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal76(e.IsClassExtension());
  auto t69 = e.CategoryNameToken();
  b.setVal69(es.EntityId(t69));
  b.setVal70(es.EntityId(e.ClassInterface()));
  b.setVal71(es.EntityId(e.Implementation()));
  auto t79 = e.InstanceVariableLBraceToken();
  b.setVal79(es.EntityId(t79));
  auto t82 = e.InstanceVariableRBraceToken();
  b.setVal82(es.EntityId(t82));
  b.setVal84(es.EntityId(e.NextClassCategory()));
  do {
    auto v362 = e.InstanceVariables();
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
}

void SerializeObjCProtocolDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal76(e.HasDefinition());
  b.setVal77(e.IsNonRuntimeProtocol());
  do {
    auto v362 = e.ProtocolTokens();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
  do {
    auto v363 = e.Protocols();
    auto sv363 = b.initVal363(static_cast<unsigned>(v363.size()));
    auto i363 = 0u;
    for (const auto &e363 : v363) {
      sv363.set(i363, es.EntityId(e363));
      ++i363;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v362 = e.AllReferencedProtocols();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
  b.setVal76(e.DeclaresOrInheritsDesignatedInitializers());
  auto t69 = e.EndOfDefinitionToken();
  b.setVal69(es.EntityId(t69));
  b.setVal70(es.EntityId(e.Implementation()));
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  auto v71 = e.SuperClass();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
    b.setVal77(id71 != mx::kInvalidEntityId);
  } else {
    b.setVal71(mx::kInvalidEntityId);
    b.setVal77(false);
  }
  auto t79 = e.SuperClassToken();
  b.setVal79(es.EntityId(t79));
  auto v82 = e.SuperClassTypeInfo();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
    b.setVal78(id82 != mx::kInvalidEntityId);
  } else {
    b.setVal82(mx::kInvalidEntityId);
    b.setVal78(false);
  }
  b.setVal84(es.EntityId(e.TypeForDeclaration()));
  b.setVal83(e.HasDefinition());
  b.setVal85(e.HasDesignatedInitializers());
  b.setVal87(e.IsArcWeakrefUnavailable());
  b.setVal95(e.IsImplicitInterfaceDeclaration());
  b.setVal86(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  do {
    auto v363 = e.InstanceVariables();
    auto sv363 = b.initVal363(static_cast<unsigned>(v363.size()));
    auto i363 = 0u;
    for (const auto &e363 : v363) {
      sv363.set(i363, es.EntityId(e363));
      ++i363;
    }
  } while (false);
  do {
    auto v364 = e.KnownCategories();
    auto sv364 = b.initVal364(static_cast<unsigned>(v364.size()));
    auto i364 = 0u;
    for (const auto &e364 : v364) {
      sv364.set(i364, es.EntityId(e364));
      ++i364;
    }
  } while (false);
  do {
    auto v365 = e.KnownExtensions();
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
  do {
    auto v368 = e.VisibleCategories();
    auto sv368 = b.initVal368(static_cast<unsigned>(v368.size()));
    auto i368 = 0u;
    for (const auto &e368 : v368) {
      sv368.set(i368, es.EntityId(e368));
      ++i368;
    }
  } while (false);
  do {
    auto v369 = e.VisibleExtensions();
    auto sv369 = b.initVal369(static_cast<unsigned>(v369.size()));
    auto i369 = 0u;
    for (const auto &e369 : v369) {
      sv369.set(i369, es.EntityId(e369));
      ++i369;
    }
  } while (false);
}

void SerializeObjCImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal69(es.EntityId(e.ClassInterface()));
  do {
    auto v362 = e.PropertyImplementations();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal70(es.EntityId(e.CategoryDeclaration()));
  auto t71 = e.CategoryNameToken();
  b.setVal71(es.EntityId(t71));
}

void SerializeObjCImplementationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t70 = e.InstanceVariableLBraceToken();
  b.setVal70(es.EntityId(t70));
  auto t71 = e.InstanceVariableRBraceToken();
  b.setVal71(es.EntityId(t71));
  auto v75 = e.ObjCRuntimeNameAsString();
  std::string s75(v75.data(), v75.size());
  b.setVal75(s75);
  b.setVal79(es.EntityId(e.SuperClass()));
  auto t82 = e.SuperClassToken();
  b.setVal82(es.EntityId(t82));
  b.setVal76(e.HasDestructors());
  b.setVal77(e.HasNonZeroConstructors());
  do {
    auto v363 = e.InstanceVariables();
    auto sv363 = b.initVal363(static_cast<unsigned>(v363.size()));
    auto i363 = 0u;
    for (const auto &e363 : v363) {
      sv363.set(i363, es.EntityId(e363));
      ++i363;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal59(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeNamespaceAliasDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto t59 = e.AliasToken();
  b.setVal59(es.EntityId(t59));
  b.setVal60(es.EntityId(e.AliasedNamespace()));
  auto t61 = e.NamespaceToken();
  b.setVal61(es.EntityId(t61));
  auto t69 = e.TargetNameToken();
  b.setVal69(es.EntityId(t69));
}

void SerializeLinkageSpecDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v53 = e.Children();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  b.setVal51(es.EntityId(e.ExtendingDeclaration()));
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal59(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v53 = e.IdentifierTokens();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
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
  auto v51 = e.FriendDeclaration();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
    b.setVal52(id51 != mx::kInvalidEntityId);
  } else {
    b.setVal51(mx::kInvalidEntityId);
    b.setVal52(false);
  }
  auto t59 = e.FriendToken();
  b.setVal59(es.EntityId(t59));
  auto v60 = e.FriendType();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
    b.setVal55(id60 != mx::kInvalidEntityId);
  } else {
    b.setVal60(mx::kInvalidEntityId);
    b.setVal55(false);
  }
  b.setVal56(e.IsUnsupportedFriend());
  do {
    auto v81 = e.FriendTypeTemplateParameterLists();
    auto sv81 = b.initVal81(static_cast<unsigned>(v81.size()));
    auto i81 = 0u;
    for (const auto &e81 : v81) {
      sv81.set(i81, es.PseudoId(e81));
      ++i81;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t51 = e.AssemblyToken();
  b.setVal51(es.EntityId(t51));
  b.setVal59(es.EntityId(e.AssemblyString()));
  auto t60 = e.RParenToken();
  b.setVal60(es.EntityId(t60));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t51 = e.ExportToken();
  b.setVal51(es.EntityId(t51));
  auto t59 = e.RBraceToken();
  b.setVal59(es.EntityId(t59));
  b.setVal52(e.HasBraces());
  pasta::DeclContext dc53(e);
  auto v53 = dc53.AlreadyLoadedDeclarations();
  auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
  auto i53 = 0u;
  for (const pasta::Decl &e53 : v53) {
    sv53.set(i53, es.EntityId(e53));
    ++i53;
  }
}

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
