// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Serialize.h"

#include <multiplier/PASTA.h>
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

void SerializeNoMergeAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMergeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
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
  b.setVal17(es.EntityId(e.Offset()));
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

void SerializeAlwaysInlineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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

void SerializeNoInlineAttr(EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInlineAttr &e) {
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
    auto id309 = es.EntityId(v309.value());
    b.setVal309(id309);
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
    auto id309 = es.EntityId(v309.value());
    b.setVal309(id309);
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
    auto id317 = es.EntityId(v317.value());
    b.setVal317(id317);
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
  b.setVal331(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
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
    auto v333 = e.Qualifiers();
    auto sv333 = b.initVal333(static_cast<unsigned>(v333.size()));
    auto i333 = 0u;
    for (const auto &e333 : v333) {
      sv333.set(i333, es.EntityId(e333));
      ++i333;
    }
  } while (false);
  b.setVal332(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
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
  auto t317 = e.EllipsisToken();
  b.setVal317(es.EntityId(t317));
  auto v331 = e.ExceptionSpecDeclaration();
  if (v331) {
    auto id331 = es.EntityId(v331.value());
    b.setVal331(id331);
    b.setVal323(id331 != mx::kInvalidEntityId);
  } else {
    b.setVal331(mx::kInvalidEntityId);
    b.setVal323(false);
  }
  auto v332 = e.ExceptionSpecTemplate();
  if (v332) {
    auto id332 = es.EntityId(v332.value());
    b.setVal332(id332);
    b.setVal324(id332 != mx::kInvalidEntityId);
  } else {
    b.setVal332(mx::kInvalidEntityId);
    b.setVal324(false);
  }
  b.setVal337(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v338 = e.NoexceptExpression();
  if (v338) {
    auto id338 = es.EntityId(v338.value());
    b.setVal338(id338);
    b.setVal325(id338 != mx::kInvalidEntityId);
  } else {
    b.setVal338(mx::kInvalidEntityId);
    b.setVal325(false);
  }
  do {
    auto v318 = e.ParameterTypes();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
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
    auto v319 = e.ExceptionTypes();
    auto sv319 = b.initVal319(static_cast<unsigned>(v319.size()));
    auto i319 = 0u;
    for (const auto &e319 : v319) {
      sv319.set(i319, es.EntityId(e319));
      ++i319;
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
  b.setVal309(es.EntityId(e.AddressSpaceExpression()));
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
    auto id309 = es.EntityId(v309.value());
    b.setVal309(id309);
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
    auto id315 = es.EntityId(v315.value());
    b.setVal315(id315);
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
    auto id315 = es.EntityId(v315.value());
    b.setVal315(id315);
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
    auto id315 = es.EntityId(v315.value());
    b.setVal315(id315);
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
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
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
    b.setVal20(id13 != mx::kInvalidEntityId);
  } else {
    b.setVal13(mx::kInvalidEntityId);
    b.setVal20(false);
  }
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto v17 = e.Increment();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
    b.setVal21(id17 != mx::kInvalidEntityId);
  } else {
    b.setVal17(mx::kInvalidEntityId);
    b.setVal21(false);
  }
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
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
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
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
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
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
  b.setVal20(e.HasVariableStorage());
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
    auto id33 = es.EntityId(v33.value());
    b.setVal33(id33);
    b.setVal57(id33 != mx::kInvalidEntityId);
  } else {
    b.setVal33(mx::kInvalidEntityId);
    b.setVal57(false);
  }
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v34 = e.ReferencedDeclarationOfCallee();
  if (v34) {
    auto id34 = es.EntityId(v34.value());
    b.setVal34(id34);
    b.setVal58(id34 != mx::kInvalidEntityId);
  } else {
    b.setVal34(mx::kInvalidEntityId);
    b.setVal58(false);
  }
  auto v35 = e.SourceBitField();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
    b.setVal59(id35 != mx::kInvalidEntityId);
  } else {
    b.setVal35(mx::kInvalidEntityId);
    b.setVal59(false);
  }
  auto v36 = e.Type();
  if (v36) {
    auto id36 = es.EntityId(v36.value());
    b.setVal36(id36);
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
  do {
    auto v94 = e.Designators();
    auto sv94 = b.initVal94(static_cast<unsigned>(v94.size()));
    auto i94 = 0u;
    for (const auto &e94 : v94) {
      sv94.set(i94, es.PseudoId(e94));
      ++i94;
    }
  } while (false);
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
  auto t37 = e.LAngleToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.TemplateKeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal95(e.HasExplicitTemplateArguments());
  b.setVal96(e.HasTemplateKeyword());
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
  b.setVal95(e.IsImplicit());
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
  b.setVal37(es.EntityId(e.Initializer()));
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal95(e.IsFileScope());
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
  b.setVal95(e.IsConditionDependent());
  b.setVal96(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v65 = e.CastKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto v37 = e.ConversionFunction();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.SubExpressionAsWritten()));
  auto v40 = e.TargetUnionField();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal96(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
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
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal98(e.IsListInitialization());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.Callee()));
  auto v39 = e.CalleeDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal95(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v40 = e.DirectCallee();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
    b.setVal96(id40 != mx::kInvalidEntityId);
  } else {
    b.setVal40(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.UnusedResultAttribute();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal97(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
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
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  b.setVal106(e.IsAssignmentOperation());
  b.setVal107(e.IsComparisonOperation());
  b.setVal108(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal43(es.EntityId(e.ImplicitObjectArgument()));
  auto v44 = e.MethodDeclaration();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
    b.setVal106(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal106(false);
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
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t44 = e.UDSuffixToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal38(es.EntityId(e.GuidDeclaration()));
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
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
  auto t37 = e.LParenToken();
  b.setVal37(es.EntityId(t37));
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.TypeAsWritten()));
  b.setVal95(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal38(es.EntityId(e.TypeOperand()));
  b.setVal39(es.EntityId(e.TypeOperandSourceInfo()));
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
  auto v37 = e.SubExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t38 = e.ThrowToken();
  b.setVal38(es.EntityId(t38));
  b.setVal96(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal95(e.IsImplicit());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  b.setVal102(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal95(e.IsAssignmentOperation());
  b.setVal96(e.IsComparisonOperation());
  b.setVal97(e.IsReversed());
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
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal95(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t43 = e.TildeToken();
  b.setVal43(es.EntityId(t43));
  b.setVal96(e.HasQualifier());
  b.setVal97(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal95(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.AllocatedType()));
  auto v38 = e.ArraySize();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal96(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v39 = e.ConstructExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal97(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  if (auto r40 = e.DirectInitializerRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v42 = e.Initializer();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal98(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal98(false);
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
  b.setVal37(es.EntityId(e.Constructor()));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal96(e.InheritedFromVirtualBase());
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
  auto v109 = e.NumExpansions();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal96(e.IsLeftFold());
  b.setVal97(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.Base();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal38(es.EntityId(e.BaseType()));
  auto v39 = e.FirstQualifierFoundInScope();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal96(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal96(false);
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
  b.setVal97(e.HasExplicitTemplateArguments());
  b.setVal98(e.HasTemplateKeyword());
  b.setVal99(e.IsArrow());
  b.setVal101(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  b.setVal38(es.EntityId(e.DestroyedType()));
  b.setVal39(es.EntityId(e.OperatorDelete()));
  b.setVal96(e.IsArrayForm());
  b.setVal97(e.IsArrayFormAsWritten());
  b.setVal98(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.Expression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal95(e.Value());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v65 = e.OpcodeString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.RHS()));
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
  b.setVal40(es.EntityId(e.ComputationLHSType()));
  b.setVal41(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.BuiltinToken();
  b.setVal37(es.EntityId(t37));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal38(es.EntityId(e.Order()));
  auto v39 = e.OrderFail();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal95(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  b.setVal40(es.EntityId(e.Pointer()));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.Scope();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal96(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto v43 = e.Value1();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
    b.setVal97(id43 != mx::kInvalidEntityId);
  } else {
    b.setVal43(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  auto v44 = e.Value2();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
    b.setVal98(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal98(false);
  }
  b.setVal45(es.EntityId(e.ValueType()));
  auto v46 = e.Weak();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
    b.setVal99(id46 != mx::kInvalidEntityId);
  } else {
    b.setVal46(mx::kInvalidEntityId);
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  b.setVal95(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.CanOverflow());
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SubExpression()));
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
  auto v37 = e.ArgumentExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v38 = e.ArgumentType();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal96(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.TypeOfArgument()));
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
  b.setVal101(e.IsAscii());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal95(e.IsIntType());
  b.setVal96(e.IsStringType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.OperatorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Pack()));
  auto v109 = e.PackLength();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto t39 = e.PackToken();
  b.setVal39(es.EntityId(t39));
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
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal97(e.IsPartiallySubstituted());
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
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
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
  auto v109 = e.NumExpansions();
  if (v109) {
    b.setVal109(static_cast<unsigned>(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
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
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
    b.setVal95(id39 != mx::kInvalidEntityId);
  } else {
    b.setVal39(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto t40 = e.RAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.TemplateKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal96(e.HasExplicitTemplateArguments());
  b.setVal97(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal42(es.EntityId(e.Base()));
  b.setVal43(es.EntityId(e.BaseType()));
  auto t44 = e.MemberToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
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
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal95(e.IsUnique());
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
  b.setVal95(e.IsArraySubscriptReferenceExpression());
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
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ClassReceiverType()));
  b.setVal40(es.EntityId(e.InstanceReceiver()));
  auto t41 = e.LeftToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.MethodDeclaration()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
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
  b.setVal95(e.IsClassMessage());
  b.setVal96(e.IsDelegateInitializerCall());
  b.setVal97(e.IsImplicit());
  b.setVal98(e.IsInstanceMessage());
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
  b.setVal95(e.IsArrow());
  b.setVal96(e.IsFreeInstanceVariable());
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
  b.setVal95(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal95(e.ShouldCopy());
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
  b.setVal95(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal95(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.HasVersion());
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
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  auto t39 = e.RBracketToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal95(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v37 = e.ExtendingDeclaration();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v38 = e.LifetimeExtendedTemporaryDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal96(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal97(e.IsBoundToLvalueReference());
  b.setVal98(e.IsUsableInConstantExpressions());
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
  b.setVal95(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal100(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
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
  auto v109 = e.TemplateParameterList();
  if (v109) {
    b.setVal109(es.PseudoId(v109.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto v44 = e.TrailingRequiresClause();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
    b.setVal96(id44 != mx::kInvalidEntityId);
  } else {
    b.setVal44(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal97(e.HasExplicitParameters());
  b.setVal98(e.HasExplicitResultType());
  b.setVal99(e.IsGenericLambda());
  b.setVal101(e.IsMutable());
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
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
    b.setVal95(id37 != mx::kInvalidEntityId);
  } else {
    b.setVal37(mx::kInvalidEntityId);
    b.setVal95(false);
  }
  auto v38 = e.InitializedFieldInUnion();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
    b.setVal96(id38 != mx::kInvalidEntityId);
  } else {
    b.setVal38(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  auto t39 = e.LBraceToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RBraceToken();
  b.setVal40(es.EntityId(t40));
  auto v41 = e.SemanticForm();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
    b.setVal97(id41 != mx::kInvalidEntityId);
  } else {
    b.setVal41(mx::kInvalidEntityId);
    b.setVal97(false);
  }
  auto v42 = e.SyntacticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
    b.setVal98(id42 != mx::kInvalidEntityId);
  } else {
    b.setVal42(mx::kInvalidEntityId);
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
  b.setVal95(e.IsResultDependent());
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
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
  b.setVal95(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t37 = e.Token();
  b.setVal37(es.EntityId(t37));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(e.ContainsDuplicateElements());
  auto t37 = e.AccessorToken();
  b.setVal37(es.EntityId(t37));
  b.setVal38(es.EntityId(e.Base()));
  b.setVal96(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal37(es.EntityId(e.QueriedExpression()));
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
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
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
  b.setVal24(e.IsFunctionOrFunctionTemplate());
  b.setVal25(e.IsImplicit());
  b.setVal26(e.IsInAnonymousNamespace());
  b.setVal27(e.IsInExportDeclarationContext());
  b.setVal28(e.IsInLocalScopeForInstantiation());
  b.setVal29(e.IsInStdNamespace());
  b.setVal30(e.IsInvalidDeclaration());
  b.setVal31(e.IsModulePrivate());
  b.setVal32(e.IsOutOfLine());
  b.setVal33(e.IsParameterPack());
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
  b.setVal98(e.HasGlobalStorage());
  auto v99 = e.HasICEInitializer();
  if (v99) {
    b.setVal99(static_cast<bool>(v99.value()));
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  b.setVal101(e.HasInitializer());
  b.setVal102(e.HasLocalStorage());
  b.setVal103(e.IsARCPseudoStrong());
  b.setVal104(e.IsCXXForRangeDeclaration());
  b.setVal105(e.IsConstexpr());
  b.setVal106(e.IsDirectInitializer());
  b.setVal107(e.IsEscapingByref());
  b.setVal108(e.IsExceptionVariable());
  b.setVal109(e.IsExternC());
  b.setVal110(e.IsFileVariableDeclaration());
  b.setVal111(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal112(e.IsInExternCContext());
  b.setVal113(e.IsInExternCXXContext());
  b.setVal114(e.IsInitializerCapture());
  b.setVal115(e.IsInline());
  b.setVal116(e.IsInlineSpecified());
  b.setVal117(e.IsKnownToBeDefined());
  b.setVal118(e.IsLocalVariableDeclaration());
  b.setVal119(e.IsLocalVariableDeclarationOrParm());
  b.setVal120(e.IsNRVOVariable());
  b.setVal121(e.IsNoDestroy());
  b.setVal122(e.IsNonEscapingByref());
  b.setVal123(e.IsObjCForDeclaration());
  b.setVal124(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal125(e.IsStaticDataMember());
  b.setVal126(e.IsStaticLocal());
  b.setVal127(e.IsThisDeclarationADemotedDefinition());
  b.setVal128(e.IsUsableInConstantExpressions());
  b.setVal129(e.MightBeUsableInConstantExpressions());
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v131 = e.DefaultArgument();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
    b.setVal132(id131 != mx::kInvalidEntityId);
  } else {
    b.setVal131(mx::kInvalidEntityId);
    b.setVal132(false);
  }
  if (auto r133 = e.DefaultArgumentRange(); auto rs133 = r133.Size()) {
    b.setVal133(es.EntityId(r133[0]));
    b.setVal134(es.EntityId(r133[rs133 - 1u]));
  } else {
    b.setVal133(0);
    b.setVal134(0);
  }
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal136(es.EntityId(e.OriginalType()));
  auto v137 = e.UninstantiatedDefaultArgument();
  if (v137) {
    auto id137 = es.EntityId(v137.value());
    b.setVal137(id137);
    b.setVal138(id137 != mx::kInvalidEntityId);
  } else {
    b.setVal137(mx::kInvalidEntityId);
    b.setVal138(false);
  }
  b.setVal139(e.HasDefaultArgument());
  b.setVal140(e.HasInheritedDefaultArgument());
  b.setVal141(e.HasUninstantiatedDefaultArgument());
  b.setVal142(e.HasUnparsedDefaultArgument());
  b.setVal143(e.IsDestroyedInCallee());
  b.setVal144(e.IsKNRPromoted());
  b.setVal145(e.IsObjCMethodParameter());
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
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
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
  auto t131 = e.ExternToken();
  b.setVal131(es.EntityId(t131));
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v146 = e.TemplateArguments();
    auto sv146 = b.initVal146(static_cast<unsigned>(v146.size()));
    auto i146 = 0u;
    for (const auto &e146 : v146) {
      sv146.set(i146, es.PseudoId(e146));
      ++i146;
    }
  } while (false);
  do {
    auto v147 = e.TemplateInstantiationArguments();
    auto sv147 = b.initVal147(static_cast<unsigned>(v147.size()));
    auto i147 = 0u;
    for (const auto &e147 : v147) {
      sv147.set(i147, es.PseudoId(e147));
      ++i147;
    }
  } while (false);
  auto t133 = e.TemplateKeywordToken();
  b.setVal133(es.EntityId(t133));
  b.setVal134(es.EntityId(e.TypeAsWritten()));
  b.setVal132(e.IsClassScopeExplicitSpecialization());
  b.setVal138(e.IsExplicitInstantiationOrSpecialization());
  b.setVal139(e.IsExplicitSpecialization());
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
  auto v148 = e.NumExpansionTypes();
  if (v148) {
    b.setVal148(static_cast<unsigned>(v148.value()));
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
  auto v91 = e.InstantiatedFromMemberFunction();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal92(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal92(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v148 = e.ODRHash();
  if (v148) {
    b.setVal148(static_cast<unsigned>(v148.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r131 = e.ParametersSourceRange(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal133(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal133(0);
  }
  auto t134 = e.PointOfInstantiation();
  b.setVal134(es.EntityId(t134));
  b.setVal136(es.EntityId(e.ReturnType()));
  if (auto r137 = e.ReturnTypeSourceRange(); auto rs137 = r137.Size()) {
    b.setVal137(es.EntityId(r137[0]));
    b.setVal149(es.EntityId(r137[rs137 - 1u]));
  } else {
    b.setVal137(0);
    b.setVal149(0);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v150 = e.TemplateInstantiationPattern();
  if (v150) {
    auto id150 = es.EntityId(v150.value());
    b.setVal150(id150);
    b.setVal96(id150 != mx::kInvalidEntityId);
  } else {
    b.setVal150(mx::kInvalidEntityId);
    b.setVal96(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal130(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal97(e.HasImplicitReturnZero());
  b.setVal98(e.HasInheritedPrototype());
  b.setVal99(e.HasOneParameterOrDefaultArguments());
  b.setVal100(e.HasPrototype());
  b.setVal101(e.HasSkippedBody());
  b.setVal102(e.HasTrivialBody());
  b.setVal103(e.HasWrittenPrototype());
  b.setVal104(e.InstantiationIsPending());
  b.setVal105(e.IsCPUDispatchMultiVersion());
  b.setVal106(e.IsCPUSpecificMultiVersion());
  b.setVal107(e.IsConsteval());
  b.setVal108(e.IsConstexpr());
  b.setVal109(e.IsConstexprSpecified());
  b.setVal110(e.IsDefaulted());
  b.setVal111(e.IsDeleted());
  b.setVal112(e.IsDeletedAsWritten());
  b.setVal113(e.IsDestroyingOperatorDelete());
  b.setVal114(e.IsExplicitlyDefaulted());
  b.setVal115(e.IsExternC());
  b.setVal116(e.IsFunctionTemplateSpecialization());
  b.setVal117(e.IsGlobal());
  b.setVal118(e.IsImplicitlyInstantiable());
  b.setVal119(e.IsInExternCContext());
  b.setVal120(e.IsInExternCXXContext());
  b.setVal121(e.IsInlineBuiltinDeclaration());
  auto v122 = e.IsInlineDefinitionExternallyVisible();
  if (v122) {
    b.setVal122(static_cast<bool>(v122.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  b.setVal124(e.IsInlineSpecified());
  b.setVal125(e.IsInlined());
  b.setVal126(e.IsLateTemplateParsed());
  auto v127 = e.IsMSExternInline();
  if (v127) {
    b.setVal127(static_cast<bool>(v127.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  b.setVal129(e.IsMSVCRTEntryPoint());
  b.setVal132(e.IsMain());
  b.setVal138(e.IsMultiVersion());
  b.setVal139(e.IsNoReturn());
  b.setVal140(e.IsOverloadedOperator());
  b.setVal141(e.IsPure());
  b.setVal142(e.IsReplaceableGlobalAllocationFunction());
  auto v143 = e.IsReservedGlobalPlacementOperator();
  if (v143) {
    b.setVal143(static_cast<bool>(v143.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  b.setVal145(e.IsStatic());
  b.setVal151(e.IsTargetClonesMultiVersion());
  b.setVal152(e.IsTargetMultiVersion());
  b.setVal153(e.IsTemplateInstantiation());
  b.setVal154(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal155(e.IsTrivial());
  b.setVal156(e.IsTrivialForCall());
  b.setVal157(e.IsUserProvided());
  b.setVal158(e.IsVariadic());
  b.setVal159(e.IsVirtualAsWritten());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal160(e.UsesSEHTry());
  b.setVal161(e.WillHaveBody());
  auto v162 = e.Body();
  if (v162) {
    auto id162 = es.EntityId(v162.value());
    b.setVal162(id162);
    b.setVal163(id162 != mx::kInvalidEntityId);
  } else {
    b.setVal162(mx::kInvalidEntityId);
    b.setVal163(false);
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
  b.setVal135(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v164 = e.ThisObjectType();
  if (v164) {
    auto id164 = es.EntityId(v164.value());
    b.setVal164(id164);
    b.setVal165(id164 != mx::kInvalidEntityId);
  } else {
    b.setVal164(mx::kInvalidEntityId);
    b.setVal165(false);
  }
  auto v166 = e.ThisType();
  if (v166) {
    auto id166 = es.EntityId(v166.value());
    b.setVal166(id166);
    b.setVal167(id166 != mx::kInvalidEntityId);
  } else {
    b.setVal166(mx::kInvalidEntityId);
    b.setVal167(false);
  }
  b.setVal168(e.HasInlineBody());
  b.setVal169(e.IsConst());
  b.setVal170(e.IsCopyAssignmentOperator());
  b.setVal171(e.IsInstance());
  b.setVal172(e.IsLambdaStaticInvoker());
  b.setVal173(e.IsMoveAssignmentOperator());
  b.setVal174(e.IsVirtual());
  b.setVal175(e.IsVolatile());
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
    auto v176 = e.ParameterDeclarations();
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v177 = e.OperatorDelete();
  if (v177) {
    auto id177 = es.EntityId(v177.value());
    b.setVal177(id177);
    b.setVal178(id177 != mx::kInvalidEntityId);
  } else {
    b.setVal177(mx::kInvalidEntityId);
    b.setVal178(false);
  }
  auto v179 = e.OperatorDeleteThisArgument();
  if (v179) {
    auto id179 = es.EntityId(v179.value());
    b.setVal179(id179);
    b.setVal180(id179 != mx::kInvalidEntityId);
  } else {
    b.setVal179(mx::kInvalidEntityId);
    b.setVal180(false);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal177(es.EntityId(e.ConversionType()));
  b.setVal178(e.IsExplicit());
  b.setVal180(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v177 = e.TargetConstructor();
  if (v177) {
    auto id177 = es.EntityId(v177.value());
    b.setVal177(id177);
    b.setVal178(id177 != mx::kInvalidEntityId);
  } else {
    b.setVal177(mx::kInvalidEntityId);
    b.setVal178(false);
  }
  b.setVal180(e.IsDefaultConstructor());
  b.setVal181(e.IsDelegatingConstructor());
  b.setVal182(e.IsExplicit());
  b.setVal183(e.IsInheritingConstructor());
  b.setVal184(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal164(es.EntityId(e.CorrespondingConstructor()));
  b.setVal165(e.IsCopyDeductionCandidate());
  b.setVal167(e.IsExplicit());
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
  b.setVal101(e.IsUnion());
  b.setVal102(e.MayHaveOutOfDateDefinition());
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
  b.setVal103(e.CanPassInRegisters());
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
  b.setVal104(e.HasFlexibleArrayMember());
  b.setVal105(e.HasLoadedFieldsFromExternalStorage());
  b.setVal106(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal107(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal108(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal109(e.HasObjectMember());
  b.setVal110(e.HasVolatileMember());
  b.setVal111(e.IsAnonymousStructOrUnion());
  b.setVal112(e.IsCapturedRecord());
  b.setVal113(e.IsInjectedClassName());
  b.setVal114(e.IsLambda());
  b.setVal115(e.IsMsStruct());
  b.setVal116(e.IsNonTrivialToPrimitiveCopy());
  b.setVal117(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal118(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal119(e.IsOrContainsUnion());
  b.setVal120(e.IsParameterDestroyedInCallee());
  b.setVal121(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e);
  auto v122 = e.AllowConstDefaultInitializer();
  if (v122) {
    b.setVal122(static_cast<bool>(v122.value()));
    b.setVal123(true);
  } else {
    b.setVal123(false);
  }
  do {
    auto ov146 = e.Bases();
    if (!ov146) {
      b.setVal124(false);
      break;
    }
    b.setVal124(true);
    auto v146 = std::move(*ov146);
    auto sv146 = b.initVal146(static_cast<unsigned>(v146.size()));
    auto i146 = 0u;
    for (const auto &e146 : v146) {
      sv146.set(i146, es.PseudoId(e146));
      ++i146;
    }
  } while (false);
  auto v87 = e.CalculateInheritanceModel();
  if (v87) {
    b.setVal87(static_cast<unsigned char>(v87.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
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
    auto ov176 = e.Friends();
    if (!ov176) {
      b.setVal126(false);
      break;
    }
    b.setVal126(true);
    auto v176 = std::move(*ov176);
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  auto v76 = e.Destructor();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
    b.setVal127(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal127(false);
  }
  auto v148 = e.GenericLambdaTemplateParameterList();
  if (v148) {
    b.setVal148(es.PseudoId(v148.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  auto v79 = e.InstantiatedFromMemberClass();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal129(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal129(false);
  }
  auto v81 = e.LambdaCallOperator();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
    b.setVal132(id81 != mx::kInvalidEntityId);
  } else {
    b.setVal81(mx::kInvalidEntityId);
    b.setVal132(false);
  }
  auto v88 = e.LambdaCaptureDefault();
  if (v88) {
    b.setVal88(static_cast<unsigned char>(v88.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  auto v83 = e.LambdaContextDeclaration();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
    b.setVal139(id83 != mx::kInvalidEntityId);
  } else {
    b.setVal83(mx::kInvalidEntityId);
    b.setVal139(false);
  }
  do {
    auto ov185 = e.LambdaExplicitTemplateParameters();
    if (!ov185) {
      b.setVal140(false);
      break;
    }
    b.setVal140(true);
    auto v185 = std::move(*ov185);
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
    }
  } while (false);
  auto v186 = e.LambdaManglingNumber();
  if (v186) {
    b.setVal186(static_cast<unsigned>(v186.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v86 = e.LambdaType();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
    b.setVal142(id86 != mx::kInvalidEntityId);
  } else {
    b.setVal86(mx::kInvalidEntityId);
    b.setVal142(false);
  }
  auto v89 = e.MSInheritanceModel();
  if (v89) {
    b.setVal89(static_cast<unsigned char>(v89.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v187 = e.NumBases();
  if (v187) {
    b.setVal187(static_cast<unsigned>(v187.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  auto v188 = e.NumVirtualBases();
  if (v188) {
    b.setVal188(static_cast<unsigned>(v188.value()));
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  auto v189 = e.ODRHash();
  if (v189) {
    b.setVal189(static_cast<unsigned>(v189.value()));
    b.setVal151(true);
  } else {
    b.setVal151(false);
  }
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal152(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal152(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v153 = e.HasAnyDependentBases();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasConstexprDefaultConstructor();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v157 = e.HasConstexprDestructor();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  auto v159 = e.HasConstexprNonCopyMoveConstructor();
  if (v159) {
    b.setVal159(static_cast<bool>(v159.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v161 = e.HasCopyAssignmentWithConstParameter();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v165 = e.HasCopyConstructorWithConstParameter();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v168 = e.HasDefaultConstructor();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
    b.setVal169(true);
  } else {
    b.setVal169(false);
  }
  auto v170 = e.HasDefinition();
  if (v170) {
    b.setVal170(static_cast<bool>(v170.value()));
    b.setVal171(true);
  } else {
    b.setVal171(false);
  }
  auto v172 = e.HasDirectFields();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasFriends();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v178 = e.HasInClassInitializer();
  if (v178) {
    b.setVal178(static_cast<bool>(v178.value()));
    b.setVal180(true);
  } else {
    b.setVal180(false);
  }
  auto v181 = e.HasInheritedAssignment();
  if (v181) {
    b.setVal181(static_cast<bool>(v181.value()));
    b.setVal182(true);
  } else {
    b.setVal182(false);
  }
  auto v183 = e.HasInheritedConstructor();
  if (v183) {
    b.setVal183(static_cast<bool>(v183.value()));
    b.setVal184(true);
  } else {
    b.setVal184(false);
  }
  auto v190 = e.HasInitializerMethod();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasIrrelevantDestructor();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasKnownLambdaInternalLinkage();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasMoveAssignment();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasMoveConstructor();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasMutableFields();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonLiteralTypeFieldsOrBases();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialCopyAssignment();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialCopyConstructor();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialCopyConstructorForCall();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialDefaultConstructor();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialDestructor();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasNonTrivialDestructorForCall();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasNonTrivialMoveAssignment();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasNonTrivialMoveConstructor();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasNonTrivialMoveConstructorForCall();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasPrivateFields();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasProtectedFields();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasSimpleCopyAssignment();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasSimpleCopyConstructor();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasSimpleDestructor();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasSimpleMoveAssignment();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasSimpleMoveConstructor();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialCopyAssignment();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialCopyConstructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialCopyConstructorForCall();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialDefaultConstructor();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialDestructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasTrivialDestructorForCall();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasTrivialMoveAssignment();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasTrivialMoveConstructor();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasTrivialMoveConstructorForCall();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUninitializedReferenceMember();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredConstructor();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserDeclaredCopyAssignment();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUserDeclaredCopyConstructor();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserDeclaredDestructor();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasUserDeclaredMoveAssignment();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.HasUserDeclaredMoveConstructor();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.HasUserDeclaredMoveOperation();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.HasUserProvidedDefaultConstructor();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.HasVariantMembers();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.ImplicitCopyConstructorHasConstParameter();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.IsAbstract();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  auto v280 = e.IsAggregate();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  auto v282 = e.IsAnyDestructorNoReturn();
  if (v282) {
    b.setVal282(static_cast<bool>(v282.value()));
    b.setVal283(true);
  } else {
    b.setVal283(false);
  }
  auto v284 = e.IsCLike();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  auto v286 = e.IsCXX11StandardLayout();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  b.setVal288(e.IsDependentLambda());
  auto v289 = e.IsDynamicClass();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  auto v291 = e.IsEffectivelyFinal();
  if (v291) {
    b.setVal291(static_cast<bool>(v291.value()));
    b.setVal292(true);
  } else {
    b.setVal292(false);
  }
  auto v293 = e.IsEmpty();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  b.setVal295(e.IsGenericLambda());
  auto v296 = e.IsInterfaceLike();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  auto v298 = e.IsLiteral();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v131 = e.IsLocalClass();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
    b.setVal300(id131 != mx::kInvalidEntityId);
  } else {
    b.setVal131(mx::kInvalidEntityId);
    b.setVal300(false);
  }
  auto v301 = e.IsPOD();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsPolymorphic();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.IsStandardLayout();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.IsStructural();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.IsTrivial();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.IsTriviallyCopyable();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  auto v315 = e.MayBeAbstract();
  if (v315) {
    b.setVal315(static_cast<bool>(v315.value()));
    b.setVal316(true);
  } else {
    b.setVal316(false);
  }
  auto v317 = e.MayBeDynamicClass();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.MayBeNonDynamicClass();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  do {
    auto ov321 = e.Methods();
    if (!ov321) {
      b.setVal322(false);
      break;
    }
    b.setVal322(true);
    auto v321 = std::move(*ov321);
    auto sv321 = b.initVal321(static_cast<unsigned>(v321.size()));
    auto i321 = 0u;
    for (const auto &e321 : v321) {
      sv321.set(i321, es.EntityId(e321));
      ++i321;
    }
  } while (false);
  auto v323 = e.NeedsImplicitCopyAssignment();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsImplicitCopyConstructor();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsImplicitDefaultConstructor();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsImplicitDestructor();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsImplicitMoveAssignment();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsImplicitMoveConstructor();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.NeedsOverloadResolutionForDestructor();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
  auto v341 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v341) {
    b.setVal341(static_cast<bool>(v341.value()));
    b.setVal342(true);
  } else {
    b.setVal342(false);
  }
  auto v343 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v343) {
    b.setVal343(static_cast<bool>(v343.value()));
    b.setVal344(true);
  } else {
    b.setVal344(false);
  }
  auto v345 = e.NullFieldOffsetIsZero();
  if (v345) {
    b.setVal345(static_cast<bool>(v345.value()));
    b.setVal346(true);
  } else {
    b.setVal346(false);
  }
  do {
    auto ov147 = e.VirtualBases();
    if (!ov147) {
      b.setVal347(false);
      break;
    }
    b.setVal347(true);
    auto v147 = std::move(*ov147);
    auto sv147 = b.initVal147(static_cast<unsigned>(v147.size()));
    auto i147 = 0u;
    for (const auto &e147 : v147) {
      sv147.set(i147, es.PseudoId(e147));
      ++i147;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t133 = e.ExternToken();
  b.setVal133(es.EntityId(t133));
  auto t134 = e.PointOfInstantiation();
  b.setVal134(es.EntityId(t134));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v348 = e.TemplateArguments();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.PseudoId(e348));
      ++i348;
    }
  } while (false);
  do {
    auto v349 = e.TemplateInstantiationArguments();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.PseudoId(e349));
      ++i349;
    }
  } while (false);
  auto t136 = e.TemplateKeywordToken();
  b.setVal136(es.EntityId(t136));
  auto v137 = e.TypeAsWritten();
  if (v137) {
    auto id137 = es.EntityId(v137.value());
    b.setVal137(id137);
    b.setVal350(id137 != mx::kInvalidEntityId);
  } else {
    b.setVal137(mx::kInvalidEntityId);
    b.setVal350(false);
  }
  b.setVal351(e.IsClassScopeExplicitSpecialization());
  b.setVal352(e.IsExplicitInstantiationOrSpecialization());
  b.setVal353(e.IsExplicitSpecialization());
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
    b.setVal103(id76 != mx::kInvalidEntityId);
  } else {
    b.setVal76(mx::kInvalidEntityId);
    b.setVal103(false);
  }
  auto v79 = e.IntegerType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
    b.setVal104(id79 != mx::kInvalidEntityId);
  } else {
    b.setVal79(mx::kInvalidEntityId);
    b.setVal104(false);
  }
  if (auto r81 = e.IntegerTypeRange(); auto rs81 = r81.Size()) {
    b.setVal81(es.EntityId(r81[0]));
    b.setVal83(es.EntityId(r81[rs81 - 1u]));
  } else {
    b.setVal81(0);
    b.setVal83(0);
  }
  auto v148 = e.ODRHash();
  if (v148) {
    b.setVal148(static_cast<unsigned>(v148.value()));
    b.setVal105(true);
  } else {
    b.setVal105(false);
  }
  b.setVal86(es.EntityId(e.PromotionType()));
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
    b.setVal106(id91 != mx::kInvalidEntityId);
  } else {
    b.setVal91(mx::kInvalidEntityId);
    b.setVal106(false);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal107(e.IsClosed());
  b.setVal108(e.IsClosedFlag());
  b.setVal109(e.IsClosedNonFlag());
  b.setVal110(e.IsComplete());
  b.setVal111(e.IsFixed());
  b.setVal112(e.IsScoped());
  b.setVal113(e.IsScopedUsingClassTag());
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
    auto v176 = e.InstanceProperties();
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  do {
    auto v185 = e.Methods();
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
    }
  } while (false);
  do {
    auto v321 = e.Properties();
    auto sv321 = b.initVal321(static_cast<unsigned>(v321.size()));
    auto i321 = 0u;
    for (const auto &e321 : v321) {
      sv321.set(i321, es.EntityId(e321));
      ++i321;
    }
  } while (false);
  pasta::DeclContext dc354(e);
  auto v354 = dc354.AlreadyLoadedDeclarations();
  auto sv354 = b.initVal354(static_cast<unsigned>(v354.size()));
  auto i354 = 0u;
  for (const pasta::Decl &e354 : v354) {
    sv354.set(i354, es.EntityId(e354));
    ++i354;
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
    auto v355 = e.InstanceVariables();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
  do {
    auto v356 = e.ProtocolTokens();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
  do {
    auto v357 = e.Protocols();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
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
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v355 = e.AllReferencedProtocols();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
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
    auto v356 = e.InstanceVariables();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
  do {
    auto v357 = e.KnownCategories();
    auto sv357 = b.initVal357(static_cast<unsigned>(v357.size()));
    auto i357 = 0u;
    for (const auto &e357 : v357) {
      sv357.set(i357, es.EntityId(e357));
      ++i357;
    }
  } while (false);
  do {
    auto v358 = e.KnownExtensions();
    auto sv358 = b.initVal358(static_cast<unsigned>(v358.size()));
    auto i358 = 0u;
    for (const auto &e358 : v358) {
      sv358.set(i358, es.EntityId(e358));
      ++i358;
    }
  } while (false);
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
  do {
    auto v361 = e.VisibleCategories();
    auto sv361 = b.initVal361(static_cast<unsigned>(v361.size()));
    auto i361 = 0u;
    for (const auto &e361 : v361) {
      sv361.set(i361, es.EntityId(e361));
      ++i361;
    }
  } while (false);
  do {
    auto v362 = e.VisibleExtensions();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
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
    auto v355 = e.PropertyImplementations();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
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
    auto v356 = e.InstanceVariables();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
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
