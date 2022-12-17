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
#include <pasta/AST/Macro.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>

#include <glog/logging.h>
#include "EntityMapper.h"
#include "PASTA.h"
#include "TokenTree.h"
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
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  if (auto r5 = e.Tokens(); auto rs5 = r5.Size()) {
    b.setVal5(es.EntityId(r5[0]));
    b.setVal6(es.EntityId(r5[rs5 - 1u]));
  } else {
    b.setVal5(0);
    b.setVal6(0);
  }
  auto t7 = e.DotToken();
  b.setVal7(es.EntityId(t7));
  auto t8 = e.FieldToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.LeftBracketToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.RightBracketToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.EllipsisToken();
  b.setVal11(es.EntityId(t11));
  auto v12 = e.FirstExpressionIndex();
  if (v12) {
    b.setVal12(static_cast<unsigned>(v12.value()));
    b.setVal13(true);
  } else {
    b.setVal13(false);
  }
}

void SerializeTemplateParameterList(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateParameterList));
  b.setVal12(e.NumParameters());
  b.setVal14(e.NumRequiredParameters());
  b.setVal15(e.Depth());
  b.setVal1(e.HasUnexpandedParameterPack());
  b.setVal2(e.HasParameterPack());
  auto v4 = e.RequiresClause();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  auto t5 = e.TemplateKeywordToken();
  b.setVal5(es.EntityId(t5));
  auto t6 = e.LeftAngleToken();
  b.setVal6(es.EntityId(t6));
  auto t7 = e.RightAngleToken();
  b.setVal7(es.EntityId(t7));
  if (auto r8 = e.Tokens(); auto rs8 = r8.Size()) {
    b.setVal8(es.EntityId(r8[0]));
    b.setVal9(es.EntityId(r8[rs8 - 1u]));
  } else {
    b.setVal8(0);
    b.setVal9(0);
  }
  do {
    auto v16 = e.Parameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeTemplateArgument(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kTemplateArgument));
  b.setVal17(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal1(e.IsNull());
  b.setVal2(e.IsDependent());
  b.setVal3(e.IsInstantiationDependent());
  b.setVal13(e.ContainsUnexpandedParameterPack());
  b.setVal18(e.IsPackExpansion());
  auto v4 = e.AsDeclaration();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  auto v5 = e.AsType();
  if (v5) {
    auto id5 = es.EntityId(v5.value());
    b.setVal5(id5);
  } else {
    b.setVal5(mx::kInvalidEntityId);
  }
  auto v6 = e.ParameterTypeForDeclaration();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  auto v7 = e.NullPointerType();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
}

void SerializeCXXBaseSpecifier(EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
  b.setVal0(static_cast<uint8_t>(pasta::PseudoKind::kCXXBaseSpecifier));
  if (auto r4 = e.Tokens(); auto rs4 = r4.Size()) {
    b.setVal4(es.EntityId(r4[0]));
    b.setVal5(es.EntityId(r4[rs4 - 1u]));
  } else {
    b.setVal4(0);
    b.setVal5(0);
  }
  auto t6 = e.BaseTypeToken();
  b.setVal6(es.EntityId(t6));
  b.setVal1(e.IsVirtual());
  b.setVal17(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal2(e.IsPackExpansion());
  b.setVal3(e.ConstructorsAreInherited());
  auto v7 = e.EllipsisToken();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  b.setVal19(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal20(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal8(es.EntityId(e.BaseType()));
}

void SerializeMacro(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::Macro &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  if (tt) {
    b.setVal0(static_cast<unsigned char>(tt->Kind()));
  } else {
    b.setVal0(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  }
  auto v1 = e.Parent();
  if (v1) {
    auto id1 = es.EntityId(v1.value());
    b.setVal1(id1);
  } else {
    b.setVal1(mx::kInvalidEntityId);
  }
  if (tt) {
    auto v2 = tt->Children();
    auto sv2 = b.initVal2(static_cast<unsigned>(v2.size()));
    auto i2 = 0u;
    for (auto n2 : v2) {
      sv2.set(i2, es.EntityId(n2.RawNode()));
      ++i2;
    }
  } else {
    auto v2 = e.Children();
    auto sv2 = b.initVal2(static_cast<unsigned>(v2.size()));
    auto i2 = 0u;
    for (const auto &e2 : v2) {
      sv2.set(i2, es.EntityId(e2));
      ++i2;
    }
  }
}

void SerializeMacroVAOptArgument(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOptArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroSubstitution(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroSubstitution &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  if (tt) {
    auto v3 = tt->ReplacementChildren();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (auto n3 : v3) {
      sv3.set(i3, es.EntityId(n3.RawNode()));
      ++i3;
    }
  } else {
    auto v3 = e.ReplacementChildren();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  }
}

void SerializeMacroVAOpt(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOpt &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroConcatenate(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroConcatenate &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroStringify(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroStringify &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroExpansion(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroExpansion &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  auto v4 = e.Definition();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  do {
    auto v5 = e.Arguments();
    auto sv5 = b.initVal5(static_cast<unsigned>(v5.size()));
    auto i5 = 0u;
    for (const auto &e5 : v5) {
      sv5.set(i5, es.EntityId(e5));
      ++i5;
    }
  } while (false);
}

void SerializeMacroArgument(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  b.setVal6(e.IsVariadic());
  b.setVal7(e.Index());
}

void SerializeMacroParameter(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameter &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  auto v4 = e.VariadicDots();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  auto v8 = e.Name();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  b.setVal7(e.Index());
}

void SerializeMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  auto t4 = e.Hash();
  b.setVal4(es.EntityId(t4));
  auto v8 = e.Name();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
}

void SerializeDefineMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::DefineMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
  if (true) {
    auto v3 = e.Body();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  }
  b.setVal7(e.NumExplicitParameters());
  b.setVal6(e.IsVariadic());
  b.setVal9(e.IsFunctionLike());
  if (true) {
    auto v5 = e.Parameters();
    auto sv5 = b.initVal5(static_cast<unsigned>(v5.size()));
    auto i5 = 0u;
    for (const auto &e5 : v5) {
      sv5.set(i5, es.EntityId(e5));
      ++i5;
    }
  }
}

void SerializePragmaMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::PragmaMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeUndefineMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::UndefineMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeEndIfMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::EndIfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeElseMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeElseIfNotDefinedMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeElseIfDefinedMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeElseIfMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeIfNotDefinedMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeIfDefinedMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeIfMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeOtherMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::OtherMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeIncludeLikeMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeLikeMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
  auto f10 = e.IncludedFile();
  b.setVal10(es.FileId(f10));
}

void SerializeImportMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ImportMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeMacrosMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacrosMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeNextMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeNextMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeMacroDirective(EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
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
  } else {
    b.setVal17(mx::kInvalidEntityId);
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
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v17 = e.AlignmentType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsAlignas());
  b.setVal14(e.IsAlignmentDependent());
  b.setVal19(e.IsAlignmentErrorDependent());
  b.setVal20(e.IsAlignmentExpression());
  b.setVal21(e.IsC11());
  b.setVal22(e.IsDeclspec());
  b.setVal23(e.IsGNU());
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
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  auto v8 = e.AsCXXRecordDeclaration();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.AsComplexIntegerType();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  auto v10 = e.AsObjCInterfacePointerType();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.AsObjCInterfaceType();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v12 = e.AsObjCQualifiedClassType();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v13 = e.AsObjCQualifiedIdType();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.AsObjCQualifiedInterfaceType();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v15 = e.AsPlaceholderType();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
  } else {
    b.setVal15(mx::kInvalidEntityId);
  }
  auto v16 = e.AsRecordDeclaration();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto v17 = e.AsStructureType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  auto v18 = e.AsTagDeclaration();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto v19 = e.AsUnionType();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto v20 = e.ContainedAutoType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  auto v21 = e.ContainedDeducedType();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  b.setVal22(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  b.setVal23(es.EntityId(e.LocallyUnqualifiedSingleStepDesugaredType()));
  auto v24 = e.Nullability();
  if (v24) {
    b.setVal24(static_cast<unsigned char>(v24.value()));
    b.setVal25(true);
  } else {
    b.setVal25(false);
  }
  auto v26 = e.PointeeCXXRecordDeclaration();
  if (v26) {
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
  } else {
    b.setVal26(mx::kInvalidEntityId);
  }
  auto v27 = e.PointeeOrArrayElementType();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  auto v28 = e.PointeeType();
  if (v28) {
    auto id28 = es.EntityId(v28.value());
    b.setVal28(id28);
  } else {
    b.setVal28(mx::kInvalidEntityId);
  }
  auto v29 = e.ScalarTypeKind();
  if (v29) {
    b.setVal29(static_cast<unsigned char>(v29.value()));
    b.setVal30(true);
  } else {
    b.setVal30(false);
  }
  auto v31 = e.SveElementType();
  if (v31) {
    auto id31 = es.EntityId(v31.value());
    b.setVal31(id31);
  } else {
    b.setVal31(mx::kInvalidEntityId);
  }
  b.setVal32(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal33(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal34(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal35(e.HasAutoForTrailingReturnType());
  b.setVal36(e.HasFloatingRepresentation());
  b.setVal37(e.HasIntegerRepresentation());
  b.setVal38(e.HasObjCPointerRepresentation());
  b.setVal39(e.HasPointerRepresentation());
  b.setVal40(e.HasSignedIntegerRepresentation());
  b.setVal41(e.HasSizedVLAType());
  b.setVal42(e.HasUnnamedOrLocalType());
  b.setVal43(e.HasUnsignedIntegerRepresentation());
  auto v44 = e.IsAggregateType();
  if (v44) {
    b.setVal44(static_cast<bool>(v44.value()));
    b.setVal45(true);
  } else {
    b.setVal45(false);
  }
  b.setVal46(e.IsAlignValueT());
  b.setVal47(e.IsAnyCharacterType());
  b.setVal48(e.IsAnyComplexType());
  b.setVal49(e.IsAnyPointerType());
  b.setVal50(e.IsArithmeticType());
  b.setVal51(e.IsArrayType());
  b.setVal52(e.IsAtomicType());
  b.setVal53(e.IsBFloat16Type());
  b.setVal54(e.IsBitIntType());
  b.setVal55(e.IsBlockCompatibleObjCPointerType());
  b.setVal56(e.IsBlockPointerType());
  b.setVal57(e.IsBooleanType());
  b.setVal58(e.IsBuiltinType());
  b.setVal59(e.IsCARCBridgableType());
  b.setVal60(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal61(e.IsCUDADeviceBuiltinTextureType());
  b.setVal62(e.IsCanonicalUnqualified());
  b.setVal63(e.IsChar16Type());
  b.setVal64(e.IsChar32Type());
  b.setVal65(e.IsChar8Type());
  b.setVal66(e.IsCharacterType());
  b.setVal67(e.IsClassType());
  b.setVal68(e.IsClkEventT());
  b.setVal69(e.IsComplexIntegerType());
  b.setVal70(e.IsComplexType());
  b.setVal71(e.IsCompoundType());
  b.setVal72(e.IsConstantArrayType());
  b.setVal73(e.IsConstantMatrixType());
  auto v74 = e.IsConstantSizeType();
  if (v74) {
    b.setVal74(static_cast<bool>(v74.value()));
    b.setVal75(true);
  } else {
    b.setVal75(false);
  }
  b.setVal76(e.IsDecltypeType());
  b.setVal77(e.IsDependentAddressSpaceType());
  b.setVal78(e.IsDependentSizedArrayType());
  b.setVal79(e.IsDependentType());
  b.setVal80(e.IsElaboratedTypeSpecifier());
  b.setVal81(e.IsEnumeralType());
  b.setVal82(e.IsEventT());
  b.setVal83(e.IsExtVectorBooleanType());
  b.setVal84(e.IsExtVectorType());
  b.setVal85(e.IsFixedPointOrIntegerType());
  b.setVal86(e.IsFixedPointType());
  b.setVal87(e.IsFloat128Type());
  b.setVal88(e.IsFloat16Type());
  b.setVal89(e.IsFloatingType());
  b.setVal90(e.IsFromAST());
  b.setVal91(e.IsFunctionNoProtoType());
  b.setVal92(e.IsFunctionPointerType());
  b.setVal93(e.IsFunctionProtoType());
  b.setVal94(e.IsFunctionReferenceType());
  b.setVal95(e.IsFunctionType());
  b.setVal96(e.IsFundamentalType());
  b.setVal97(e.IsHalfType());
  b.setVal98(e.IsIbm128Type());
  b.setVal99(e.IsImageType());
  b.setVal100(e.IsIncompleteArrayType());
  b.setVal101(e.IsIncompleteOrObjectType());
  b.setVal102(e.IsIncompleteType());
  b.setVal103(e.IsInstantiationDependentType());
  b.setVal104(e.IsIntegerType());
  b.setVal105(e.IsIntegralOrEnumerationType());
  b.setVal106(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal107(e.IsIntegralType());
  b.setVal108(e.IsInterfaceType());
  b.setVal109(e.IsLValueReferenceType());
  b.setVal110(e.IsLinkageValid());
  auto v111 = e.IsLiteralType();
  if (v111) {
    b.setVal111(static_cast<bool>(v111.value()));
    b.setVal112(true);
  } else {
    b.setVal112(false);
  }
  b.setVal113(e.IsMatrixType());
  b.setVal114(e.IsMemberDataPointerType());
  b.setVal115(e.IsMemberFunctionPointerType());
  b.setVal116(e.IsMemberPointerType());
  b.setVal117(e.IsNonOverloadPlaceholderType());
  b.setVal118(e.IsNothrowT());
  b.setVal119(e.IsNullPointerType());
  b.setVal120(e.IsOCLExtOpaqueType());
  b.setVal121(e.IsOCLImage1dArrayROType());
  b.setVal122(e.IsOCLImage1dArrayRWType());
  b.setVal123(e.IsOCLImage1dArrayWOType());
  b.setVal124(e.IsOCLImage1dBufferROType());
  b.setVal125(e.IsOCLImage1dBufferRWType());
  b.setVal126(e.IsOCLImage1dBufferWOType());
  b.setVal127(e.IsOCLImage1dROType());
  b.setVal128(e.IsOCLImage1dRWType());
  b.setVal129(e.IsOCLImage1dWOType());
  b.setVal130(e.IsOCLImage2dArrayDepthROType());
  b.setVal131(e.IsOCLImage2dArrayDepthRWType());
  b.setVal132(e.IsOCLImage2dArrayDepthWOType());
  b.setVal133(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal134(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal135(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal136(e.IsOCLImage2dArrayMSAAROType());
  b.setVal137(e.IsOCLImage2dArrayMSAARWType());
  b.setVal138(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal139(e.IsOCLImage2dArrayROType());
  b.setVal140(e.IsOCLImage2dArrayRWType());
  b.setVal141(e.IsOCLImage2dArrayWOType());
  b.setVal142(e.IsOCLImage2dDepthROType());
  b.setVal143(e.IsOCLImage2dDepthRWType());
  b.setVal144(e.IsOCLImage2dDepthWOType());
  b.setVal145(e.IsOCLImage2dMSAADepthROType());
  b.setVal146(e.IsOCLImage2dMSAADepthRWType());
  b.setVal147(e.IsOCLImage2dMSAADepthWOType());
  b.setVal148(e.IsOCLImage2dMSAAROType());
  b.setVal149(e.IsOCLImage2dMSAARWType());
  b.setVal150(e.IsOCLImage2dMSAAWOType());
  b.setVal151(e.IsOCLImage2dROType());
  b.setVal152(e.IsOCLImage2dRWType());
  b.setVal153(e.IsOCLImage2dWOType());
  b.setVal154(e.IsOCLImage3dROType());
  b.setVal155(e.IsOCLImage3dRWType());
  b.setVal156(e.IsOCLImage3dWOType());
  b.setVal157(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal158(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal159(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal160(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal161(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal162(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal163(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal164(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal165(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal166(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal167(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal168(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal169(e.IsOCLIntelSubgroupAVCType());
  b.setVal170(e.IsObjCARCBridgableType());
  auto v171 = e.IsObjCARCImplicitlyUnretainedType();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  b.setVal173(e.IsObjCBoxableRecordType());
  b.setVal174(e.IsObjCBuiltinType());
  b.setVal175(e.IsObjCClassOrClassKindOfType());
  b.setVal176(e.IsObjCClassType());
  b.setVal177(e.IsObjCIdType());
  b.setVal178(e.IsObjCIndependentClassType());
  b.setVal179(e.IsObjCIndirectLifetimeType());
  b.setVal180(e.IsObjCInertUnsafeUnretainedType());
  b.setVal181(e.IsObjCLifetimeType());
  b.setVal182(e.IsObjCNSObjectType());
  b.setVal183(e.IsObjCObjectOrInterfaceType());
  b.setVal184(e.IsObjCObjectPointerType());
  b.setVal185(e.IsObjCObjectType());
  b.setVal186(e.IsObjCQualifiedClassType());
  b.setVal187(e.IsObjCQualifiedIdType());
  b.setVal188(e.IsObjCQualifiedInterfaceType());
  b.setVal189(e.IsObjCRetainableType());
  b.setVal190(e.IsObjCSelType());
  b.setVal191(e.IsObjectPointerType());
  b.setVal192(e.IsObjectType());
  b.setVal193(e.IsOpenCLSpecificType());
  b.setVal194(e.IsOverloadableType());
  b.setVal195(e.IsPipeType());
  b.setVal196(e.IsPlaceholderType());
  b.setVal197(e.IsPointerType());
  b.setVal198(e.IsPromotableIntegerType());
  b.setVal199(e.IsQueueT());
  b.setVal200(e.IsRValueReferenceType());
  b.setVal201(e.IsRealFloatingType());
  b.setVal202(e.IsRealType());
  b.setVal203(e.IsRecordType());
  b.setVal204(e.IsReferenceType());
  b.setVal205(e.IsReserveIDT());
  b.setVal206(e.IsSamplerT());
  b.setVal207(e.IsSaturatedFixedPointType());
  b.setVal208(e.IsScalarType());
  b.setVal209(e.IsScopedEnumeralType());
  b.setVal210(e.IsSignedFixedPointType());
  b.setVal211(e.IsSignedIntegerOrEnumerationType());
  b.setVal212(e.IsSignedIntegerType());
  b.setVal213(e.IsSizelessBuiltinType());
  b.setVal214(e.IsSizelessType());
  b.setVal215(e.IsSpecifierType());
  auto v216 = e.IsStandardLayoutType();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  b.setVal218(e.IsStdByteType());
  auto v219 = e.IsStructuralType();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  b.setVal221(e.IsStructureOrClassType());
  b.setVal222(e.IsStructureType());
  b.setVal223(e.IsTemplateTypeParmType());
  b.setVal224(e.IsTypedefNameType());
  b.setVal225(e.IsUndeducedAutoType());
  b.setVal226(e.IsUndeducedType());
  b.setVal227(e.IsUnionType());
  b.setVal228(e.IsUnsaturatedFixedPointType());
  b.setVal229(e.IsUnscopedEnumerationType());
  b.setVal230(e.IsUnsignedFixedPointType());
  b.setVal231(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal232(e.IsUnsignedIntegerType());
  b.setVal233(e.IsVLSTBuiltinType());
  b.setVal234(e.IsVariableArrayType());
  b.setVal235(e.IsVariablyModifiedType());
  b.setVal236(e.IsVectorType());
  b.setVal237(e.IsVisibilityExplicit());
  b.setVal238(e.IsVoidPointerType());
  b.setVal239(e.IsVoidType());
  b.setVal240(e.IsWideCharacterType());
  b.setVal241(es.EntityId(e.IgnoreParentheses()));
  b.setVal242(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal243(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal244(es.EntityId(e.CanonicalType()));
  b.setVal245(es.EntityId(e.DesugaredType()));
  b.setVal246(es.EntityId(e.LocalUnqualifiedType()));
  b.setVal247(es.EntityId(e.NonLValueExpressionType()));
  b.setVal248(es.EntityId(e.NonPackExpansionType()));
  b.setVal249(es.EntityId(e.NonReferenceType()));
  b.setVal250(es.EntityId(e.SingleStepDesugaredType()));
  b.setVal251(e.HasAddressSpace());
  b.setVal252(e.HasLocalNonFastQualifiers());
  b.setVal253(e.HasLocalQualifiers());
  b.setVal254(e.HasNonTrivialObjCLifetime());
  b.setVal255(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal256(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal257(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal258(e.HasQualifiers());
  b.setVal259(e.HasStrongOrWeakObjCLifetime());
  b.setVal260(e.IsCForbiddenLValueType());
  b.setVal261(e.IsCXX11PODType());
  b.setVal262(e.IsCXX98PODType());
  b.setVal263(e.IsCanonical());
  b.setVal264(e.IsCanonicalAsParameter());
  b.setVal265(e.IsConstQualified());
  b.setVal266(e.IsConstant());
  b.setVal267(static_cast<unsigned char>(mx::FromPasta(e.IsDestructedType())));
  b.setVal268(e.IsLocalConstQualified());
  b.setVal269(e.IsLocalRestrictQualified());
  b.setVal270(e.IsLocalVolatileQualified());
  b.setVal271(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveCopy())));
  b.setVal272(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDefaultInitialize())));
  b.setVal273(static_cast<unsigned char>(mx::FromPasta(e.IsNonTrivialToPrimitiveDestructiveMove())));
  b.setVal274(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal275(e.IsNull());
  b.setVal276(e.IsObjCGCStrong());
  b.setVal277(e.IsObjCGCWeak());
  b.setVal278(e.IsPODType());
  b.setVal279(e.IsRestrictQualified());
  b.setVal280(e.IsTrivialType());
  b.setVal281(e.IsTriviallyCopyableType());
  b.setVal282(e.IsTriviallyRelocatableType());
  b.setVal283(e.IsVolatileQualified());
  b.setVal284(e.MayBeDynamicClass());
  b.setVal285(e.MayBeNotDynamicClass());
  b.setVal286(es.EntityId(e.StripObjCKindOfType()));
  b.setVal287(es.EntityId(e.WithConst()));
  b.setVal288(es.EntityId(e.WithRestrict()));
  b.setVal289(es.EntityId(e.WithVolatile()));
  b.setVal290(es.EntityId(e.WithoutLocalFastQualifiers()));
}

void SerializeTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto v292 = e.Declaration();
  if (v292) {
    auto id292 = es.EntityId(v292.value());
    b.setVal292(id292);
  } else {
    b.setVal292(mx::kInvalidEntityId);
  }
  b.setVal293(e.IsParameterPack());
  b.setVal294(e.IsSugared());
}

void SerializeTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto v292 = e.AliasedType();
  if (v292) {
    auto id292 = es.EntityId(v292.value());
    b.setVal292(id292);
  } else {
    b.setVal292(mx::kInvalidEntityId);
  }
  b.setVal293(e.IsCurrentInstantiation());
  b.setVal294(e.IsSugared());
  b.setVal295(e.IsTypeAlias());
  do {
    auto v296 = e.TemplateArguments();
    auto sv296 = b.initVal296(static_cast<unsigned>(v296.size()));
    auto i296 = 0u;
    for (const auto &e296 : v296) {
      sv296.set(i296, es.PseudoId(e296));
      ++i296;
    }
  } while (false);
}

void SerializeTagType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Declaration()));
  b.setVal293(e.IsBeingDefined());
}

void SerializeRecordType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal294(e.HasConstFields());
  b.setVal295(e.IsSugared());
}

void SerializeEnumType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal294(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ReplacedParameter()));
  b.setVal297(es.EntityId(e.ReplacementType()));
  b.setVal293(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ReplacedParameter()));
  b.setVal293(e.IsSugared());
}

void SerializeReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal293(e.IsInnerReference());
  b.setVal294(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal295(e.IsSugared());
}

void SerializeLValueReferenceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal295(e.IsSugared());
}

void SerializePointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializePipeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsReadOnly());
  b.setVal294(e.IsSugared());
}

void SerializeParenType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.InnerType()));
  b.setVal293(e.IsSugared());
}

void SerializePackExpansionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto v298 = e.NumExpansions();
  if (v298) {
    b.setVal298(static_cast<unsigned>(v298.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  b.setVal292(es.EntityId(e.Pattern()));
  b.setVal294(e.IsSugared());
}

void SerializeObjCTypeParamType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeObjCObjectType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.BaseType()));
  b.setVal297(es.EntityId(e.Interface()));
  auto v299 = e.SuperClassType();
  if (v299) {
    auto id299 = es.EntityId(v299.value());
    b.setVal299(id299);
  } else {
    b.setVal299(mx::kInvalidEntityId);
  }
  do {
    auto v300 = e.TypeArguments();
    auto sv300 = b.initVal300(static_cast<unsigned>(v300.size()));
    auto i300 = 0u;
    for (const auto &e300 : v300) {
      sv300.set(i300, es.EntityId(e300));
      ++i300;
    }
  } while (false);
  do {
    auto v301 = e.TypeArgumentsAsWritten();
    auto sv301 = b.initVal301(static_cast<unsigned>(v301.size()));
    auto i301 = 0u;
    for (const auto &e301 : v301) {
      sv301.set(i301, es.EntityId(e301));
      ++i301;
    }
  } while (false);
  b.setVal293(e.IsKindOfType());
  b.setVal294(e.IsKindOfTypeAsWritten());
  b.setVal295(e.IsObjCClass());
  b.setVal302(e.IsObjCId());
  b.setVal303(e.IsObjCQualifiedClass());
  b.setVal304(e.IsObjCQualifiedId());
  b.setVal305(e.IsObjCUnqualifiedClass());
  b.setVal306(e.IsObjCUnqualifiedId());
  b.setVal307(e.IsObjCUnqualifiedIdOrClass());
  b.setVal308(e.IsSpecialized());
  b.setVal309(e.IsSpecializedAsWritten());
  b.setVal310(e.IsSugared());
  b.setVal311(e.IsUnspecialized());
  b.setVal312(e.IsUnspecializedAsWritten());
  b.setVal313(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal314(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.InterfaceDeclaration()));
  b.setVal297(es.EntityId(e.InterfaceType()));
  b.setVal299(es.EntityId(e.ObjectType()));
  b.setVal313(es.EntityId(e.SuperClassType()));
  do {
    auto v300 = e.TypeArguments();
    auto sv300 = b.initVal300(static_cast<unsigned>(v300.size()));
    auto i300 = 0u;
    for (const auto &e300 : v300) {
      sv300.set(i300, es.EntityId(e300));
      ++i300;
    }
  } while (false);
  do {
    auto v301 = e.TypeArgumentsAsWritten();
    auto sv301 = b.initVal301(static_cast<unsigned>(v301.size()));
    auto i301 = 0u;
    for (const auto &e301 : v301) {
      sv301.set(i301, es.EntityId(e301));
      ++i301;
    }
  } while (false);
  b.setVal293(e.IsKindOfType());
  b.setVal294(e.IsObjCIdOrClassType());
  b.setVal295(e.IsSpecialized());
  b.setVal302(e.IsSpecializedAsWritten());
  b.setVal303(e.IsSugared());
  b.setVal304(e.IsUnspecialized());
  b.setVal305(e.IsUnspecializedAsWritten());
  do {
    auto v315 = e.Qualifiers();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal314(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v316 = e.Protocols();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
}

void SerializeMemberPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Class()));
  b.setVal297(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal293(e.IsMemberDataPointer());
  b.setVal294(e.IsMemberFunctionPointer());
  b.setVal295(e.IsSugared());
}

void SerializeMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsSugared());
}

void SerializeDependentSizedMatrixType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  auto t297 = e.AttributeToken();
  b.setVal297(es.EntityId(t297));
  b.setVal299(es.EntityId(e.ColumnExpression()));
  b.setVal313(es.EntityId(e.RowExpression()));
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
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ModifiedType()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeInjectedClassNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal297(es.EntityId(e.InjectedSpecializationType()));
  b.setVal299(es.EntityId(e.InjectedTST()));
  b.setVal293(e.IsSugared());
}

void SerializeFunctionType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal291(es.EntityId(e.CallResultType()));
  b.setVal293(e.CmseNSCallAttribute());
  b.setVal294(e.HasRegParm());
  b.setVal295(e.NoReturnAttribute());
  b.setVal292(es.EntityId(e.ReturnType()));
  b.setVal302(e.IsConst());
  b.setVal303(e.IsRestrict());
  b.setVal304(e.IsVolatile());
}

void SerializeFunctionProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  auto v318 = e.CanThrow();
  if (v318) {
    b.setVal318(static_cast<unsigned char>(v318.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  b.setVal297(es.EntityId(e.Desugar()));
  auto t299 = e.EllipsisToken();
  b.setVal299(es.EntityId(t299));
  auto v313 = e.ExceptionSpecDeclaration();
  if (v313) {
    auto id313 = es.EntityId(v313.value());
    b.setVal313(id313);
  } else {
    b.setVal313(mx::kInvalidEntityId);
  }
  auto v314 = e.ExceptionSpecTemplate();
  if (v314) {
    auto id314 = es.EntityId(v314.value());
    b.setVal314(id314);
  } else {
    b.setVal314(mx::kInvalidEntityId);
  }
  b.setVal319(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v320 = e.NoexceptExpression();
  if (v320) {
    auto id320 = es.EntityId(v320.value());
    b.setVal320(id320);
  } else {
    b.setVal320(mx::kInvalidEntityId);
  }
  do {
    auto v300 = e.ParameterTypes();
    auto sv300 = b.initVal300(static_cast<unsigned>(v300.size()));
    auto i300 = 0u;
    for (const auto &e300 : v300) {
      sv300.set(i300, es.EntityId(e300));
      ++i300;
    }
  } while (false);
  b.setVal321(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal306(e.HasDependentExceptionSpec());
  b.setVal307(e.HasDynamicExceptionSpec());
  b.setVal308(e.HasExceptionSpec());
  b.setVal309(e.HasExtParameterInfos());
  b.setVal310(e.HasInstantiationDependentExceptionSpec());
  b.setVal311(e.HasNoexceptExceptionSpec());
  b.setVal312(e.HasTrailingReturn());
  auto v322 = e.IsNothrow();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  b.setVal324(e.IsSugared());
  b.setVal325(e.IsTemplateVariadic());
  b.setVal326(e.IsVariadic());
  do {
    auto v301 = e.ExceptionTypes();
    auto sv301 = b.initVal301(static_cast<unsigned>(v301.size()));
    auto i301 = 0u;
    for (const auto &e301 : v301) {
      sv301.set(i301, es.EntityId(e301));
      ++i301;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal297(es.EntityId(e.Desugar()));
  b.setVal305(e.IsSugared());
}

void SerializeDependentVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto t292 = e.AttributeToken();
  b.setVal292(es.EntityId(t292));
  b.setVal297(es.EntityId(e.ElementType()));
  b.setVal299(es.EntityId(e.SizeExpression()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal293(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto t292 = e.AttributeToken();
  b.setVal292(es.EntityId(t292));
  b.setVal297(es.EntityId(e.ElementType()));
  b.setVal299(es.EntityId(e.SizeExpression()));
  b.setVal293(e.IsSugared());
}

void SerializeDependentBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.NumBitsExpression()));
  b.setVal293(e.IsSigned());
  b.setVal294(e.IsSugared());
  b.setVal295(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.AddressSpaceExpression()));
  auto t297 = e.AttributeToken();
  b.setVal297(es.EntityId(t297));
  b.setVal293(e.IsSugared());
}

void SerializeDeducedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  auto v292 = e.ResolvedType();
  if (v292) {
    auto id292 = es.EntityId(v292.value());
    b.setVal292(id292);
  } else {
    b.setVal292(mx::kInvalidEntityId);
  }
  b.setVal293(e.IsDeduced());
  b.setVal294(e.IsSugared());
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
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v296 = e.TypeConstraintArguments();
    auto sv296 = b.initVal296(static_cast<unsigned>(v296.size()));
    auto i296 = 0u;
    for (const auto &e296 : v296) {
      sv296.set(i296, es.PseudoId(e296));
      ++i296;
    }
  } while (false);
  auto v297 = e.TypeConstraintConcept();
  if (v297) {
    auto id297 = es.EntityId(v297.value());
    b.setVal297(id297);
  } else {
    b.setVal297(mx::kInvalidEntityId);
  }
  b.setVal295(e.IsConstrained());
  b.setVal302(e.IsDecltypeAuto());
  b.setVal303(e.IsGNUAutoType());
}

void SerializeDecltypeType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingExpression()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeComplexType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsSugared());
}

void SerializeBuiltinType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal293(e.IsFloatingPoint());
  b.setVal294(e.IsInteger());
  b.setVal295(e.IsSVEBool());
  b.setVal302(e.IsSignedInteger());
  b.setVal303(e.IsSugared());
  b.setVal304(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeBitIntType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSigned());
  b.setVal294(e.IsSugared());
  b.setVal295(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Attribute()));
  b.setVal297(es.EntityId(e.WrappedType()));
  b.setVal293(e.IsSugared());
}

void SerializeAttributedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal327(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal292(es.EntityId(e.EquivalentType()));
  auto v317 = e.ImmediateNullability();
  if (v317) {
    b.setVal317(static_cast<unsigned char>(v317.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  b.setVal297(es.EntityId(e.ModifiedType()));
  b.setVal294(e.IsCallingConv());
  b.setVal295(e.IsMSTypeSpec());
  b.setVal302(e.IsQualifier());
  b.setVal303(e.IsSugared());
}

void SerializeAtomicType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ValueType()));
  b.setVal293(e.IsSugared());
}

void SerializeArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.ElementType()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  if (auto r297 = e.BracketsRange(); auto rs297 = r297.Size()) {
    b.setVal297(es.EntityId(r297[0]));
    b.setVal299(es.EntityId(r297[rs297 - 1u]));
  } else {
    b.setVal297(0);
    b.setVal299(0);
  }
  auto t313 = e.LBracketToken();
  b.setVal313(es.EntityId(t313));
  auto t314 = e.RBracketToken();
  b.setVal314(es.EntityId(t314));
  b.setVal320(es.EntityId(e.SizeExpression()));
  b.setVal293(e.IsSugared());
}

void SerializeIncompleteArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeDependentSizedArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  if (auto r297 = e.BracketsRange(); auto rs297 = r297.Size()) {
    b.setVal297(es.EntityId(r297[0]));
    b.setVal299(es.EntityId(r297[rs297 - 1u]));
  } else {
    b.setVal297(0);
    b.setVal299(0);
  }
  auto t313 = e.LBracketToken();
  b.setVal313(es.EntityId(t313));
  auto t314 = e.RBracketToken();
  b.setVal314(es.EntityId(t314));
  b.setVal320(es.EntityId(e.SizeExpression()));
  b.setVal293(e.IsSugared());
}

void SerializeConstantArrayType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  auto v297 = e.SizeExpression();
  if (v297) {
    auto id297 = es.EntityId(v297.value());
    b.setVal297(id297);
  } else {
    b.setVal297(mx::kInvalidEntityId);
  }
  b.setVal293(e.IsSugared());
}

void SerializeAdjustedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ResolvedType()));
  b.setVal297(es.EntityId(e.OriginalType()));
  b.setVal293(e.IsSugared());
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
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.NamedType()));
  auto v297 = e.OwnedTagDeclaration();
  if (v297) {
    auto id297 = es.EntityId(v297.value());
    b.setVal297(id297);
  } else {
    b.setVal297(mx::kInvalidEntityId);
  }
  b.setVal293(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
  do {
    auto v296 = e.TemplateArguments();
    auto sv296 = b.initVal296(static_cast<unsigned>(v296.size()));
    auto i296 = 0u;
    for (const auto &e296 : v296) {
      sv296.set(i296, es.PseudoId(e296));
      ++i296;
    }
  } while (false);
}

void SerializeDependentNameType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeVectorType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal293(e.IsSugared());
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
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.FoundDeclaration()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeUnresolvedUsingType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeUnaryTransformType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.BaseType()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeTypedefType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeTypeOfType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeTypeOfExprType(EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingExpression()));
  b.setVal293(e.IsSugared());
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
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  auto v10 = e.ReturnValue();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
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
  b.setVal16(e.IsStandaloneDirective());
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
    auto v15 = e.Counters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ConstantTarget();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
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
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.ConditionVariableDeclarationStatement();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v13 = e.Else();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto t14 = e.ElseToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.IfToken();
  b.setVal17(es.EntityId(t17));
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto t19 = e.LParenToken();
  b.setVal19(es.EntityId(t19));
  auto t20 = e.RParenToken();
  b.setVal20(es.EntityId(t20));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal21(es.EntityId(e.Then()));
  b.setVal12(e.HasElseStorage());
  b.setVal16(e.HasInitializerStorage());
  b.setVal23(e.HasVariableStorage());
  b.setVal24(e.IsConsteval());
  b.setVal25(e.IsConstexpr());
  b.setVal58(e.IsNegatedConsteval());
  b.setVal59(e.IsNonNegatedConsteval());
  b.setVal60(e.IsObjCAvailabilityCheck());
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
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto v17 = e.Increment();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
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
    auto v15 = e.Declarations();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto v9 = e.SingleDeclaration();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  b.setVal12(e.IsSingleDeclaration());
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
    auto v15 = e.ParameterMoves();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  b.setVal12(e.HasStoredFPFeatures());
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
  } else {
    b.setVal20(mx::kInvalidEntityId);
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
  } else {
    b.setVal11(mx::kInvalidEntityId);
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
  b.setVal61(e.GenerateAssemblyString());
  auto t9 = e.AssemblyToken();
  b.setVal9(es.EntityId(t9));
  do {
    auto v15 = e.Inputs();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal12(e.IsSimple());
  b.setVal16(e.IsVolatile());
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
    auto v62 = e.OutputConstraints();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      std::string se62(e62.data(), e62.size());
      sv62.set(i62, se62);
      ++i62;
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
    auto v63 = e.InputConstraints();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      std::string se63(e63.data(), e63.size());
      sv63.set(i63, se63);
      ++i63;
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
    auto v64 = e.Clobbers();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
    }
  } while (false);
}

void SerializeMSAsmStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
  SerializeAsmStmt(es, b, e);
  do {
    auto v65 = e.AllConstraints();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
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
  auto v66 = e.AssemblyString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
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
    auto v65 = e.OutputNames();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
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
    auto v67 = e.InputNames();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
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
    auto v68 = e.LabelExpressions();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      sv68.set(i68, es.EntityId(e68));
      ++i68;
    }
  } while (false);
  do {
    auto v69 = e.LabelNames();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
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
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto t14 = e.LParenToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.RParenToken();
  b.setVal17(es.EntityId(t17));
  auto t18 = e.WhileToken();
  b.setVal18(es.EntityId(t18));
  b.setVal12(e.HasVariableStorage());
}

void SerializeValueStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
  SerializeValueStmt(es, b, e);
  b.setVal10(es.EntityId(e.Declaration()));
  auto t11 = e.IdentifierToken();
  b.setVal11(es.EntityId(t11));
  auto v61 = e.Name();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal13(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsSideEntry());
}

void SerializeExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
  SerializeValueStmt(es, b, e);
  b.setVal12(e.HasSideEffects());
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
  b.setVal16(e.ContainsErrors());
  b.setVal23(e.ContainsUnexpandedParameterPack());
  b.setVal32(es.EntityId(e.BestDynamicClassTypeExpression()));
  auto t33 = e.ExpressionToken();
  b.setVal33(es.EntityId(t33));
  auto v34 = e.ObjCProperty();
  if (v34) {
    auto id34 = es.EntityId(v34.value());
    b.setVal34(id34);
  } else {
    b.setVal34(mx::kInvalidEntityId);
  }
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v35 = e.ReferencedDeclarationOfCallee();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
  } else {
    b.setVal35(mx::kInvalidEntityId);
  }
  auto v36 = e.SourceBitField();
  if (v36) {
    auto id36 = es.EntityId(v36.value());
    b.setVal36(id36);
  } else {
    b.setVal36(mx::kInvalidEntityId);
  }
  auto v37 = e.Type();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal70(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal24(e.HasNonTrivialCall());
  auto v25 = e.IsCXX98IntegralConstantExpression();
  if (v25) {
    b.setVal25(static_cast<bool>(v25.value()));
    b.setVal58(true);
  } else {
    b.setVal58(false);
  }
  b.setVal59(e.IsDefaultArgument());
  b.setVal60(e.IsGLValue());
  b.setVal71(e.IsImplicitCXXThis());
  b.setVal72(e.IsInstantiationDependent());
  auto v73 = e.IsIntegerConstantExpression();
  if (v73) {
    b.setVal73(static_cast<bool>(v73.value()));
    b.setVal74(true);
  } else {
    b.setVal74(false);
  }
  b.setVal75(e.IsKnownToHaveBooleanValue());
  b.setVal76(e.IsLValue());
  b.setVal77(e.IsOBJCGCCandidate());
  b.setVal78(e.IsObjCSelfExpression());
  b.setVal79(e.IsOrdinaryOrBitFieldObject());
  b.setVal80(e.IsPRValue());
  b.setVal81(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal82(e.IsTypeDependent());
  b.setVal83(e.IsValueDependent());
  b.setVal84(e.IsXValue());
  b.setVal85(e.RefersToBitField());
  b.setVal86(e.RefersToGlobalRegisterVariable());
  b.setVal87(e.RefersToMatrixElement());
  b.setVal88(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
  SerializeExpr(es, b, e);
  do {
    auto v89 = e.Designators();
    auto sv89 = b.initVal89(static_cast<unsigned>(v89.size()));
    auto i89 = 0u;
    for (const auto &e89 : v89) {
      sv89.set(i89, es.PseudoId(e89));
      ++i89;
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
  b.setVal90(e.IsDirectInitializer());
  b.setVal91(e.UsesGNUSyntax());
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
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
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
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal94(e.HasTemplateKeyword());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal96(e.RefersToEnclosingVariableOrCapture());
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
  b.setVal90(e.IsImplicit());
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
    auto v89 = e.TemplateArguments();
    auto sv89 = b.initVal89(static_cast<unsigned>(v89.size()));
    auto i89 = 0u;
    for (const auto &e89 : v89) {
      sv89.set(i89, es.PseudoId(e89));
      ++i89;
    }
  } while (false);
  b.setVal90(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Initializer()));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsFileScope());
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
  b.setVal90(e.IsConditionDependent());
  b.setVal91(e.IsConditionTrue());
}

void SerializeCharacterLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v61 = e.CastKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto v38 = e.ConversionFunction();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.SubExpressionAsWritten()));
  auto v41 = e.TargetUnionField();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal90(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal91(e.IsPartOfExplicitCast());
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
  auto v66 = e.CastName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
}

void SerializeCXXDynamicCastExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal91(e.IsAlwaysNull());
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
  b.setVal91(e.IsListInitialization());
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
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v66 = e.BridgeKindName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.Callee()));
  auto v40 = e.CalleeDeclaration();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto v41 = e.DirectCallee();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.UnusedResultAttribute();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.HasUnusedResultAttribute());
  b.setVal92(e.IsBuiltinAssumeFalse());
  b.setVal93(e.IsCallToStdMove());
  b.setVal94(e.IsUnevaluatedBuiltinCall());
  b.setVal96(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.ImplicitObjectArgument()));
  auto v45 = e.MethodDeclaration();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
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
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t45 = e.UDSuffixToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXUuidofExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal39(es.EntityId(e.GuidDeclaration()));
  b.setVal40(es.EntityId(e.TypeOperand()));
  b.setVal41(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal90(e.IsTypeOperand());
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
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.TypeAsWritten()));
  b.setVal90(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExpressionOperand();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
  auto v90 = e.IsMostDerived();
  if (v90) {
    b.setVal90(static_cast<bool>(v90.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
  }
  b.setVal92(e.IsPotentiallyEvaluated());
  b.setVal93(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.SubExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto t39 = e.ThrowToken();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsImplicit());
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal41(es.EntityId(e.SemanticForm()));
  b.setVal90(e.IsAssignmentOperation());
  b.setVal91(e.IsComparisonOperation());
  b.setVal92(e.IsReversed());
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
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto t44 = e.TildeToken();
  b.setVal44(es.EntityId(t44));
  b.setVal90(e.HasQualifier());
  b.setVal91(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXNoexceptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal90(e.Value());
}

void SerializeCXXNewExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.AllocatedType()));
  auto v39 = e.ArraySize();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.ConstructExpression();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  if (auto r41 = e.DirectInitializerRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v43 = e.Initializer();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
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
  b.setVal91(e.HasInitializer());
  b.setVal92(e.IsArray());
  b.setVal93(e.IsGlobalNew());
  b.setVal94(e.IsParenthesisTypeId());
  b.setVal96(e.PassAlignment());
  do {
    auto v15 = e.PlacementArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal98(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ConstructsVirtualBase());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal38(es.EntityId(e.Constructor()));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal91(e.InheritedFromVirtualBase());
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
  auto v101 = e.NumExpansions();
  if (v101) {
    b.setVal101(static_cast<unsigned>(v101.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal43(es.EntityId(e.Pattern()));
  b.setVal44(es.EntityId(e.RHS()));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal91(e.IsLeftFold());
  b.setVal92(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.Base();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal39(es.EntityId(e.BaseType()));
  auto v40 = e.FirstQualifierFoundInScope();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
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
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal91(e.IsArrayForm());
  b.setVal92(e.IsArrayFormAsWritten());
  b.setVal93(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.Expression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
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
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.IsElidable());
  b.setVal92(e.IsListInitialization());
  b.setVal93(e.IsStdInitializerListInitialization());
  b.setVal94(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.Value());
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.IsAdditiveOperation());
  b.setVal92(e.IsAssignmentOperation());
  b.setVal93(e.IsBitwiseOperation());
  b.setVal94(e.IsCommaOperation());
  b.setVal96(e.IsComparisonOperation());
  b.setVal98(e.IsCompoundAssignmentOperation());
  b.setVal99(e.IsEqualityOperation());
  b.setVal100(e.IsLogicalOperation());
  b.setVal102(e.IsMultiplicativeOperation());
  b.setVal103(e.IsPointerMemoryOperation());
  b.setVal104(e.IsRelationalOperation());
  b.setVal105(e.IsShiftAssignOperation());
  b.setVal106(e.IsShiftOperation());
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal39(es.EntityId(e.Order()));
  auto v40 = e.OrderFail();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal41(es.EntityId(e.Pointer()));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.Scope();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto v44 = e.Value1();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto v45 = e.Value2();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  b.setVal46(es.EntityId(e.ValueType()));
  auto v47 = e.Weak();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  b.setVal90(e.IsCmpXChg());
  b.setVal91(e.IsOpenCL());
  b.setVal92(e.IsVolatile());
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  b.setVal90(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.CanOverflow());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal91(e.HasStoredFPFeatures());
  b.setVal92(e.IsArithmeticOperation());
  b.setVal93(e.IsDecrementOperation());
  b.setVal94(e.IsIncrementDecrementOperation());
  b.setVal96(e.IsIncrementOperation());
  b.setVal98(e.IsPostfix());
  b.setVal99(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ArgumentExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.ArgumentType();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TypeOfArgument()));
  b.setVal90(e.IsArgumentType());
}

void SerializeTypoExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v90 = e.Value();
  if (v90) {
    b.setVal90(static_cast<bool>(v90.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
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
  b.setVal90(e.IsReferenceParameter());
}

void SerializeStringLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
  SerializeExpr(es, b, e);
  auto v90 = e.ContainsNonAscii();
  if (v90) {
    b.setVal90(static_cast<bool>(v90.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
  }
  auto v92 = e.ContainsNonAsciiOrNull();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  auto v61 = e.Bytes();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto v66 = e.String();
  if (v66) {
    if (v66->empty()) {
      b.setVal66("");
    } else {
      std::string s66(v66->data(), v66->size());
      b.setVal66(s66);
    }
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal96(e.IsOrdinary());
  b.setVal98(e.IsPascal());
  b.setVal99(e.IsUTF16());
  b.setVal100(e.IsUTF32());
  b.setVal102(e.IsUTF8());
  b.setVal103(e.IsWide());
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
  auto v61 = e.BuiltinString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsIntType());
}

void SerializeSizeOfPackExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Pack()));
  auto v101 = e.PackLength();
  if (v101) {
    b.setVal101(static_cast<unsigned>(v101.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  auto t40 = e.PackToken();
  b.setVal40(es.EntityId(t40));
  do {
    auto ov89 = e.PartialArguments();
    if (!ov89) {
      b.setVal91(false);
      break;
    }
    b.setVal91(true);
    auto v89 = std::move(*ov89);
    auto sv89 = b.initVal89(static_cast<unsigned>(v89.size()));
    auto i89 = 0u;
    for (const auto &e89 : v89) {
      sv89.set(i89, es.PseudoId(e89));
      ++i89;
    }
  } while (false);
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.IsPartiallySubstituted());
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
  b.setVal61(e.ComputeName());
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
    auto v15 = e.LocalParameters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto t39 = e.RBraceToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RequiresKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal90(e.IsSatisfied());
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
  b.setVal38(es.EntityId(e.ResultExpression()));
  b.setVal39(es.EntityId(e.SyntacticForm()));
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
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v61 = e.IdentifierKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
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
  auto v101 = e.NumExpansions();
  if (v101) {
    b.setVal101(static_cast<unsigned>(v101.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
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
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  auto t45 = e.MemberToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  b.setVal92(e.HasUnresolvedUsing());
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal92(e.IsOverloaded());
  b.setVal93(e.RequiresADL());
}

void SerializeOpaqueValueExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal90(e.IsUnique());
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
  b.setVal90(e.IsArraySubscriptReferenceExpression());
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
  b.setVal90(e.IsClassReceiver());
  b.setVal91(e.IsExplicitProperty());
  b.setVal92(e.IsImplicitProperty());
  b.setVal93(e.IsMessagingGetter());
  b.setVal94(e.IsMessagingSetter());
  b.setVal96(e.IsObjectReceiver());
  b.setVal98(e.IsSuperReceiver());
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
  b.setVal38(es.EntityId(e.CallReturnType()));
  b.setVal39(es.EntityId(e.ClassReceiver()));
  b.setVal40(es.EntityId(e.ClassReceiverType()));
  b.setVal41(es.EntityId(e.InstanceReceiver()));
  auto t42 = e.LeftToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.MethodDeclaration()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal44(es.EntityId(e.ReceiverInterface()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  b.setVal90(e.IsClassMessage());
  b.setVal91(e.IsDelegateInitializerCall());
  b.setVal92(e.IsImplicit());
  b.setVal93(e.IsInstanceMessage());
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
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsFreeInstanceVariable());
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
  b.setVal90(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal90(e.ShouldCopy());
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
  b.setVal90(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.HasVersion());
}

void SerializeObjCArrayLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ArrayWithObjectsMethod()));
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
    auto v15 = e.Dimensions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKeyword());
  b.setVal94(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal90(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  auto v38 = e.ExtendingDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.LifetimeExtendedTemporaryDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsBoundToLvalueReference());
  b.setVal91(e.IsUsableInConstantExpressions());
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
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeLambdaExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CallOperator()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t40 = e.CaptureDefaultToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.CompoundStatementBody()));
  do {
    auto v15 = e.ExplicitTemplateParameters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  auto v101 = e.TemplateParameterList();
  if (v101) {
    b.setVal101(es.PseudoId(v101.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  auto v45 = e.TrailingRequiresClause();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  b.setVal91(e.HasExplicitParameters());
  b.setVal92(e.HasExplicitResultType());
  b.setVal93(e.IsGenericLambda());
  b.setVal94(e.IsMutable());
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
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.InitializedFieldInUnion();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto t40 = e.LBraceToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RBraceToken();
  b.setVal41(es.EntityId(t41));
  auto v42 = e.SemanticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto v43 = e.SyntacticForm();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  b.setVal90(e.HadArrayRangeDesignator());
  b.setVal91(e.HasArrayFiller());
  do {
    auto v15 = e.Initializers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal92(e.IsExplicit());
  b.setVal93(e.IsSemanticForm());
  b.setVal94(e.IsStringLiteralInitializer());
  b.setVal96(e.IsSyntacticForm());
  auto v98 = e.IsTransparent();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
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
    auto v15 = e.AssociationExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  b.setVal90(e.IsResultDependent());
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
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal90(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal90(e.HasAPValueResult());
  b.setVal91(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsExact());
}

void SerializeFixedPointLiteral(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeExtVectorElementExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ContainsDuplicateElements());
  auto t38 = e.AccessorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal91(e.IsArrow());
}

void SerializeExpressionTraitExpr(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.QueriedExpression()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal90(e.Value());
}

void SerializeAttributedStmt(EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
  SerializeValueStmt(es, b, e);
  auto t10 = e.AttributeToken();
  b.setVal10(es.EntityId(t10));
  do {
    auto v15 = e.Attributes();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v13 = e.ConditionVariableDeclarationStatement();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.Initializer();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto t17 = e.LParenToken();
  b.setVal17(es.EntityId(t17));
  auto t18 = e.RParenToken();
  b.setVal18(es.EntityId(t18));
  auto v19 = e.FirstSwitchCase();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto t20 = e.SwitchToken();
  b.setVal20(es.EntityId(t20));
  b.setVal12(e.HasInitializerStorage());
  b.setVal16(e.HasVariableStorage());
  b.setVal23(e.IsAllEnumCasesCovered());
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
  } else {
    b.setVal11(mx::kInvalidEntityId);
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
  b.setVal12(e.CaseStatementIsGNURange());
  auto t14 = e.CaseToken();
  b.setVal14(es.EntityId(t14));
  auto t17 = e.EllipsisToken();
  b.setVal17(es.EntityId(t17));
  b.setVal18(es.EntityId(e.LHS()));
  auto v19 = e.RHS();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
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
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  auto v7 = e.DescribedTemplateParameters();
  if (v7) {
    b.setVal7(es.PseudoId(v7.value()));
    b.setVal8(true);
  } else {
    b.setVal8(false);
  }
  auto v9 = e.ExternalSourceSymbolAttribute();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v12 = e.NonClosureContext();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal13(e.HasAttributes());
  b.setVal14(e.HasOwningModule());
  b.setVal15(e.HasTagIdentifierNamespace());
  b.setVal16(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal17(e.IsDeprecated());
  b.setVal18(e.IsDiscardedInGlobalModuleFragment());
  b.setVal19(e.IsFunctionOrFunctionTemplate());
  b.setVal20(e.IsImplicit());
  b.setVal21(e.IsInAnonymousNamespace());
  b.setVal22(e.IsInExportDeclarationContext());
  b.setVal23(e.IsInLocalScopeForInstantiation());
  b.setVal24(e.IsInStdNamespace());
  b.setVal25(e.IsInvalidDeclaration());
  b.setVal26(e.IsInvisibleOutsideTheOwningModule());
  b.setVal27(e.IsModulePrivate());
  b.setVal28(e.IsOutOfLine());
  b.setVal29(e.IsParameterPack());
  b.setVal30(e.IsReachable());
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
  b.setVal41(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
  if (auto r43 = e.Tokens(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal45(es.EntityId(e.Specialization()));
  b.setVal46(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal45(es.EntityId(e.ContextParameter()));
  b.setVal46(e.IsNothrow());
  do {
    auto v47 = e.Parameters();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  pasta::DeclContext dc48(e);
  auto v48 = dc48.AlreadyLoadedDeclarations();
  auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
  auto i48 = 0u;
  for (const pasta::Decl &e48 : v48) {
    sv48.set(i48, es.EntityId(e48));
    ++i48;
  }
}

void SerializeBlockDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal46(e.BlockMissingReturnType());
  b.setVal49(e.CanAvoidCopyToHeap());
  b.setVal50(e.CapturesCXXThis());
  b.setVal51(e.DoesNotEscape());
  auto v45 = e.BlockManglingContextDeclaration();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto t52 = e.CaretToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.CompoundBody()));
  b.setVal54(es.EntityId(e.SignatureAsWritten()));
  b.setVal55(e.HasCaptures());
  b.setVal56(e.IsConversionFromLambda());
  b.setVal57(e.IsVariadic());
  do {
    auto v47 = e.Parameters();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  do {
    auto v48 = e.ParameterDeclarations();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
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
  auto t45 = e.AccessSpecifierToken();
  b.setVal45(es.EntityId(t45));
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
    auto v47 = e.Varlists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
    auto v47 = e.Varlists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeStaticAssertDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal45(es.EntityId(e.AssertExpression()));
  b.setVal52(es.EntityId(e.Message()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
  b.setVal46(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
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
  b.setVal45(es.EntityId(e.GetterCXXConstructor()));
  b.setVal52(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal53(es.EntityId(e.PropertyDeclaration()));
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal54(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t62 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.SetterCXXAssignment()));
  b.setVal64(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal46(e.IsInstanceVariableNameSpecified());
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
    b.setVal46(true);
  } else {
    b.setVal46(false);
  }
  b.setVal60(e.QualifiedNameAsString());
  b.setVal45(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal49(e.HasExternalFormalLinkage());
  b.setVal50(e.HasLinkage());
  b.setVal51(e.HasLinkageBeenComputed());
  b.setVal55(e.IsCXXClassMember());
  b.setVal56(e.IsCXXInstanceMember());
  b.setVal57(e.IsExternallyDeclarable());
  b.setVal67(e.IsExternallyVisible());
  b.setVal68(e.IsLinkageValid());
}

void SerializeLabelDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v69 = e.MSAssemblyLabel();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal52(es.EntityId(e.Statement()));
  b.setVal70(e.IsGnuLocal());
  b.setVal71(e.IsMSAssemblyLabel());
  b.setVal72(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v47 = e.Shadows();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
  b.setVal70(e.HasTypename());
  b.setVal71(e.IsAccessDeclaration());
}

void SerializeValueDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal52(es.EntityId(e.Type()));
  b.setVal70(e.IsWeak());
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
  b.setVal71(e.IsAccessDeclaration());
  b.setVal72(e.IsPackExpansion());
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
  b.setVal53(es.EntityId(e.Combiner()));
  b.setVal54(es.EntityId(e.CombinerIn()));
  b.setVal62(es.EntityId(e.CombinerOut()));
  b.setVal63(es.EntityId(e.InitializerOriginal()));
  b.setVal64(es.EntityId(e.InitializerPrivate()));
  b.setVal73(es.EntityId(e.Initializer()));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
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
    auto v47 = e.Chain();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  auto v53 = e.AnonymousField();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
  auto v54 = e.VariableDeclaration();
  if (v54) {
    auto id54 = es.EntityId(v54.value());
    b.setVal54(id54);
  } else {
    b.setVal54(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v53 = e.InitializerExpression();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
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
    auto id62 = es.EntityId(v62.value());
    b.setVal62(id62);
  } else {
    b.setVal62(mx::kInvalidEntityId);
  }
  auto t63 = e.TypeSpecEndToken();
  b.setVal63(es.EntityId(t63));
  auto t64 = e.TypeSpecStartToken();
  b.setVal64(es.EntityId(t64));
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
  auto v73 = e.ActingDefinition();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v76 = e.Initializer();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v77 = e.InitializingDeclaration();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v78 = e.InstantiatedFromStaticDataMember();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
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
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal71(e.HasConstantInitialization());
  b.setVal72(e.HasDependentAlignment());
  b.setVal88(e.HasExternalStorage());
  auto v89 = e.HasFlexibleArrayInitializer();
  if (v89) {
    b.setVal89(static_cast<bool>(v89.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal91(e.HasGlobalStorage());
  auto v92 = e.HasICEInitializer();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.HasInitializer());
  b.setVal95(e.HasLocalStorage());
  b.setVal96(e.IsARCPseudoStrong());
  b.setVal97(e.IsCXXForRangeDeclaration());
  b.setVal98(e.IsConstexpr());
  b.setVal99(e.IsDirectInitializer());
  b.setVal100(e.IsEscapingByref());
  b.setVal101(e.IsExceptionVariable());
  b.setVal102(e.IsExternC());
  b.setVal103(e.IsFileVariableDeclaration());
  b.setVal104(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal105(e.IsInExternCContext());
  b.setVal106(e.IsInExternCXXContext());
  b.setVal107(e.IsInitializerCapture());
  b.setVal108(e.IsInline());
  b.setVal109(e.IsInlineSpecified());
  b.setVal110(e.IsKnownToBeDefined());
  b.setVal111(e.IsLocalVariableDeclaration());
  b.setVal112(e.IsLocalVariableDeclarationOrParm());
  b.setVal113(e.IsNRVOVariable());
  b.setVal114(e.IsNoDestroy());
  b.setVal115(e.IsNonEscapingByref());
  b.setVal116(e.IsObjCForDeclaration());
  b.setVal117(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal118(e.IsStaticDataMember());
  b.setVal119(e.IsStaticLocal());
  b.setVal120(e.IsThisDeclarationADemotedDefinition());
  b.setVal121(e.IsUsableInConstantExpressions());
  b.setVal122(e.MightBeUsableInConstantExpressions());
  b.setVal123(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v124 = e.DefaultArgument();
  if (v124) {
    auto id124 = es.EntityId(v124.value());
    b.setVal124(id124);
  } else {
    b.setVal124(mx::kInvalidEntityId);
  }
  if (auto r125 = e.DefaultArgumentRange(); auto rs125 = r125.Size()) {
    b.setVal125(es.EntityId(r125[0]));
    b.setVal126(es.EntityId(r125[rs125 - 1u]));
  } else {
    b.setVal125(0);
    b.setVal126(0);
  }
  b.setVal127(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal128(es.EntityId(e.OriginalType()));
  auto v129 = e.UninstantiatedDefaultArgument();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  b.setVal130(e.HasDefaultArgument());
  b.setVal131(e.HasInheritedDefaultArgument());
  b.setVal132(e.HasUninstantiatedDefaultArgument());
  b.setVal133(e.HasUnparsedDefaultArgument());
  b.setVal134(e.IsDestroyedInCallee());
  b.setVal135(e.IsKNRPromoted());
  b.setVal136(e.IsObjCMethodParameter());
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
  b.setVal127(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  do {
    auto v47 = e.Bindings();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto t124 = e.ExternToken();
  b.setVal124(es.EntityId(t124));
  b.setVal127(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v137 = e.TemplateArguments();
    auto sv137 = b.initVal137(static_cast<unsigned>(v137.size()));
    auto i137 = 0u;
    for (const auto &e137 : v137) {
      sv137.set(i137, es.PseudoId(e137));
      ++i137;
    }
  } while (false);
  do {
    auto v138 = e.TemplateInstantiationArguments();
    auto sv138 = b.initVal138(static_cast<unsigned>(v138.size()));
    auto i138 = 0u;
    for (const auto &e138 : v138) {
      sv138.set(i138, es.PseudoId(e138));
      ++i138;
    }
  } while (false);
  auto t125 = e.TemplateKeywordToken();
  b.setVal125(es.EntityId(t125));
  b.setVal126(es.EntityId(e.TypeAsWritten()));
  b.setVal130(e.IsClassScopeExplicitSpecialization());
  b.setVal131(e.IsExplicitInstantiationOrSpecialization());
  b.setVal132(e.IsExplicitSpecialization());
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
  auto v73 = e.DefaultArgument();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto t76 = e.DefaultArgumentToken();
  b.setVal76(es.EntityId(t76));
  auto v139 = e.NumExpansionTypes();
  if (v139) {
    b.setVal139(static_cast<unsigned>(v139.value()));
    b.setVal72(true);
  } else {
    b.setVal72(false);
  }
  auto v77 = e.PlaceholderTypeConstraint();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  b.setVal88(e.HasDefaultArgument());
  b.setVal89(e.HasPlaceholderTypeConstraint());
  b.setVal90(e.IsExpandedParameterPack());
  b.setVal91(e.IsPackExpansion());
  do {
    auto v47 = e.ExpansionTypes();
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
  b.setVal72(e.HasSetter());
}

void SerializeFunctionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal71(e.UsesFPIntrin());
  auto v72 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v72) {
    b.setVal72(static_cast<bool>(v72.value()));
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  b.setVal89(e.DoesThisDeclarationHaveABody());
  b.setVal73(es.EntityId(e.CallResultType()));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal76(es.EntityId(e.DeclaredReturnType()));
  auto t77 = e.EllipsisToken();
  b.setVal77(es.EntityId(t77));
  if (auto r78 = e.ExceptionSpecSourceRange(); auto rs78 = r78.Size()) {
    b.setVal78(es.EntityId(r78[0]));
    b.setVal80(es.EntityId(r78[rs78 - 1u]));
  } else {
    b.setVal78(0);
    b.setVal80(0);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v85 = e.InstantiatedFromDeclaration();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  auto v124 = e.InstantiatedFromMemberFunction();
  if (v124) {
    auto id124 = es.EntityId(v124.value());
    b.setVal124(id124);
  } else {
    b.setVal124(mx::kInvalidEntityId);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v139 = e.ODRHash();
  if (v139) {
    b.setVal139(static_cast<unsigned>(v139.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r125 = e.ParametersSourceRange(); auto rs125 = r125.Size()) {
    b.setVal125(es.EntityId(r125[0]));
    b.setVal126(es.EntityId(r125[rs125 - 1u]));
  } else {
    b.setVal125(0);
    b.setVal126(0);
  }
  auto t128 = e.PointOfInstantiation();
  b.setVal128(es.EntityId(t128));
  b.setVal129(es.EntityId(e.ReturnType()));
  if (auto r140 = e.ReturnTypeSourceRange(); auto rs140 = r140.Size()) {
    b.setVal140(es.EntityId(r140[0]));
    b.setVal141(es.EntityId(r140[rs140 - 1u]));
  } else {
    b.setVal140(0);
    b.setVal141(0);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v142 = e.TemplateInstantiationPattern();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
  } else {
    b.setVal142(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal123(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
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
  b.setVal115(e.IsIneligibleOrNotSelected());
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
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  b.setVal131(e.IsMSVCRTEntryPoint());
  b.setVal132(e.IsMain());
  b.setVal133(e.IsMultiVersion());
  b.setVal134(e.IsNoReturn());
  b.setVal135(e.IsOverloadedOperator());
  b.setVal136(e.IsPure());
  b.setVal143(e.IsReplaceableGlobalAllocationFunction());
  auto v144 = e.IsReservedGlobalPlacementOperator();
  if (v144) {
    b.setVal144(static_cast<bool>(v144.value()));
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  b.setVal146(e.IsStatic());
  b.setVal147(e.IsTargetClonesMultiVersion());
  b.setVal148(e.IsTargetMultiVersion());
  b.setVal149(e.IsTemplateInstantiation());
  b.setVal150(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal151(e.IsTrivial());
  b.setVal152(e.IsTrivialForCall());
  b.setVal153(e.IsUserProvided());
  b.setVal154(e.IsVariadic());
  b.setVal155(e.IsVirtualAsWritten());
  do {
    auto v47 = e.Parameters();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  b.setVal156(e.UsesSEHTry());
  b.setVal157(e.WillHaveBody());
  auto v158 = e.Body();
  if (v158) {
    auto id158 = es.EntityId(v158.value());
    b.setVal158(id158);
  } else {
    b.setVal158(mx::kInvalidEntityId);
  }
  pasta::DeclContext dc48(e);
  auto v48 = dc48.AlreadyLoadedDeclarations();
  auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
  auto i48 = 0u;
  for (const pasta::Decl &e48 : v48) {
    sv48.set(i48, es.EntityId(e48));
    ++i48;
  }
}

void SerializeCXXMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal127(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v159 = e.ThisObjectType();
  if (v159) {
    auto id159 = es.EntityId(v159.value());
    b.setVal159(id159);
  } else {
    b.setVal159(mx::kInvalidEntityId);
  }
  auto v160 = e.ThisType();
  if (v160) {
    auto id160 = es.EntityId(v160.value());
    b.setVal160(id160);
  } else {
    b.setVal160(mx::kInvalidEntityId);
  }
  b.setVal161(e.HasInlineBody());
  b.setVal162(e.IsConst());
  b.setVal163(e.IsCopyAssignmentOperator());
  b.setVal164(e.IsInstance());
  b.setVal165(e.IsLambdaStaticInvoker());
  b.setVal166(e.IsMoveAssignmentOperator());
  b.setVal167(e.IsVirtual());
  b.setVal168(e.IsVolatile());
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
    auto v169 = e.ParameterDeclarations();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v170 = e.OperatorDelete();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
  }
  auto v171 = e.OperatorDeleteThisArgument();
  if (v171) {
    auto id171 = es.EntityId(v171.value());
    b.setVal171(id171);
  } else {
    b.setVal171(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal170(es.EntityId(e.ConversionType()));
  b.setVal172(e.IsExplicit());
  b.setVal173(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v170 = e.TargetConstructor();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
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
  b.setVal159(es.EntityId(e.CorrespondingConstructor()));
  b.setVal161(e.IsCopyDeductionCandidate());
  b.setVal162(e.IsExplicit());
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
  auto v73 = e.BitWidth();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v76 = e.CapturedVLAType();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v77 = e.InClassInitializer();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  b.setVal71(e.HasCapturedVLAType());
  b.setVal72(e.HasInClassInitializer());
  b.setVal88(e.IsAnonymousStructOrUnion());
  b.setVal89(e.IsBitField());
  b.setVal90(e.IsMutable());
  b.setVal91(e.IsUnnamedBitfield());
  b.setVal92(e.IsZeroLengthBitField());
  b.setVal93(e.IsZeroSize());
}

void SerializeObjCIvarDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal78(es.EntityId(e.ContainingInterface()));
  b.setVal80(es.EntityId(e.NextInstanceVariable()));
  b.setVal94(e.Synthesize());
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
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
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
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
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
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  b.setVal64(es.EntityId(e.NominatedBaseClass()));
  auto v73 = e.NominatedBaseClassShadowDeclaration();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  do {
    auto v47 = e.Expansions();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal70(e.DefaultArgumentWasInherited());
  auto v53 = e.DefaultArgument();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
  auto v54 = e.DefaultArgumentInfo();
  if (v54) {
    auto id54 = es.EntityId(v54.value());
    b.setVal54(id54);
  } else {
    b.setVal54(mx::kInvalidEntityId);
  }
  auto t62 = e.DefaultArgumentToken();
  b.setVal62(es.EntityId(t62));
  b.setVal71(e.HasDefaultArgument());
  b.setVal72(e.HasTypeConstraint());
  b.setVal88(e.IsExpandedParameterPack());
  b.setVal89(e.IsPackExpansion());
  b.setVal90(e.WasDeclaredWithTypename());
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
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v64 = e.TypedefNameForAnonymousDeclaration();
  if (v64) {
    auto id64 = es.EntityId(v64.value());
    b.setVal64(id64);
  } else {
    b.setVal64(mx::kInvalidEntityId);
  }
  b.setVal70(e.HasNameForLinkage());
  b.setVal71(e.IsBeingDefined());
  b.setVal72(e.IsClass());
  b.setVal88(e.IsCompleteDefinition());
  b.setVal89(e.IsCompleteDefinitionRequired());
  b.setVal90(e.IsDependentType());
  b.setVal91(e.IsEmbeddedInDeclarator());
  b.setVal92(e.IsEnum());
  b.setVal93(e.IsFreeStanding());
  b.setVal94(e.IsInterface());
  b.setVal95(e.IsStruct());
  b.setVal96(e.IsThisDeclarationADemotedDefinition());
  b.setVal97(e.IsUnion());
  b.setVal98(e.MayHaveOutOfDateDefinition());
  do {
    auto v75 = e.TemplateParameterLists();
    auto sv75 = b.initVal75(static_cast<unsigned>(v75.size()));
    auto i75 = 0u;
    for (const auto &e75 : v75) {
      sv75.set(i75, es.PseudoId(e75));
      ++i75;
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

void SerializeRecordDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal99(e.CanPassInRegisters());
  do {
    auto v48 = e.Fields();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
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
  b.setVal117(e.IsRandomized());
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
    auto ov137 = e.Bases();
    if (!ov137) {
      b.setVal121(false);
      break;
    }
    b.setVal121(true);
    auto v137 = std::move(*ov137);
    auto sv137 = b.initVal137(static_cast<unsigned>(v137.size()));
    auto i137 = 0u;
    for (const auto &e137 : v137) {
      sv137.set(i137, es.PseudoId(e137));
      ++i137;
    }
  } while (false);
  auto v81 = e.CalculateInheritanceModel();
  if (v81) {
    b.setVal81(static_cast<unsigned char>(v81.value()));
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
    auto ov169 = e.Friends();
    if (!ov169) {
      b.setVal130(false);
      break;
    }
    b.setVal130(true);
    auto v169 = std::move(*ov169);
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
  auto v73 = e.Destructor();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v139 = e.GenericLambdaTemplateParameterList();
  if (v139) {
    b.setVal139(es.PseudoId(v139.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  auto v76 = e.InstantiatedFromMemberClass();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v77 = e.LambdaCallOperator();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v82 = e.LambdaCaptureDefault();
  if (v82) {
    b.setVal82(static_cast<unsigned char>(v82.value()));
    b.setVal132(true);
  } else {
    b.setVal132(false);
  }
  auto v78 = e.LambdaContextDeclaration();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
  }
  do {
    auto ov177 = e.LambdaExplicitTemplateParameters();
    if (!ov177) {
      b.setVal133(false);
      break;
    }
    b.setVal133(true);
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
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  auto v80 = e.LambdaType();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v83 = e.MSInheritanceModel();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v179 = e.NumBases();
  if (v179) {
    b.setVal179(static_cast<unsigned>(v179.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v180 = e.NumVirtualBases();
  if (v180) {
    b.setVal180(static_cast<unsigned>(v180.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v181 = e.ODRHash();
  if (v181) {
    b.setVal181(static_cast<unsigned>(v181.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v145 = e.HasAnyDependentBases();
  if (v145) {
    b.setVal145(static_cast<bool>(v145.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v147 = e.HasConstexprDefaultConstructor();
  if (v147) {
    b.setVal147(static_cast<bool>(v147.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  auto v149 = e.HasConstexprDestructor();
  if (v149) {
    b.setVal149(static_cast<bool>(v149.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  auto v151 = e.HasConstexprNonCopyMoveConstructor();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v153 = e.HasCopyAssignmentWithConstParameter();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasCopyConstructorWithConstParameter();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v157 = e.HasDefaultConstructor();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v162 = e.HasDefinition();
  if (v162) {
    b.setVal162(static_cast<bool>(v162.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v164 = e.HasDirectFields();
  if (v164) {
    b.setVal164(static_cast<bool>(v164.value()));
    b.setVal165(true);
  } else {
    b.setVal165(false);
  }
  auto v166 = e.HasFriends();
  if (v166) {
    b.setVal166(static_cast<bool>(v166.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v168 = e.HasInClassInitializer();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  auto v173 = e.HasInheritedAssignment();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasInheritedConstructor();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v182 = e.HasInitializerMethod();
  if (v182) {
    b.setVal182(static_cast<bool>(v182.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
  }
  auto v184 = e.HasIrrelevantDestructor();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v186 = e.HasKnownLambdaInternalLinkage();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v188 = e.HasMoveAssignment();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  auto v190 = e.HasMoveConstructor();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasMutableFields();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasNonLiteralTypeFieldsOrBases();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasNonTrivialCopyAssignment();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonTrivialCopyConstructor();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialCopyConstructorForCall();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialDefaultConstructor();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialDestructor();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialDestructorForCall();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialMoveAssignment();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialMoveConstructor();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialMoveConstructorForCall();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasPrivateFields();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasProtectedFields();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasSimpleCopyAssignment();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasSimpleCopyConstructor();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasSimpleDestructor();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasSimpleMoveAssignment();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasSimpleMoveConstructor();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasTrivialCopyAssignment();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasTrivialCopyConstructor();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialCopyConstructorForCall();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialDefaultConstructor();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialDestructor();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialDestructorForCall();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialMoveAssignment();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialMoveConstructor();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialMoveConstructorForCall();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasUninitializedReferenceMember();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasUserDeclaredConstructor();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUserDeclaredCopyAssignment();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserDeclaredCopyConstructor();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUserDeclaredDestructor();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredMoveAssignment();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserDeclaredMoveConstructor();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUserDeclaredMoveOperation();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserProvidedDefaultConstructor();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasVariantMembers();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.ImplicitCopyConstructorHasConstParameter();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.IsAbstract();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.IsAggregate();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsAnyDestructorNoReturn();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.IsCLike();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.IsCXX11StandardLayout();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  b.setVal280(e.IsDependentLambda());
  auto v281 = e.IsDynamicClass();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsEffectivelyFinal();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsEmpty();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  b.setVal287(e.IsGenericLambda());
  auto v288 = e.IsInterfaceLike();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  auto v290 = e.IsLiteral();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v124 = e.IsLocalClass();
  if (v124) {
    auto id124 = es.EntityId(v124.value());
    b.setVal124(id124);
  } else {
    b.setVal124(mx::kInvalidEntityId);
  }
  b.setVal292(e.IsNeverDependentLambda());
  auto v293 = e.IsPOD();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v295 = e.IsPolymorphic();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsStandardLayout();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsStructural();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.IsTrivial();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsTriviallyCopyable();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.MayBeAbstract();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.MayBeDynamicClass();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.MayBeNonDynamicClass();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  do {
    auto ov313 = e.Methods();
    if (!ov313) {
      b.setVal314(false);
      break;
    }
    b.setVal314(true);
    auto v313 = std::move(*ov313);
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  auto v315 = e.NeedsImplicitCopyAssignment();
  if (v315) {
    b.setVal315(static_cast<bool>(v315.value()));
    b.setVal316(true);
  } else {
    b.setVal316(false);
  }
  auto v317 = e.NeedsImplicitCopyConstructor();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.NeedsImplicitDefaultConstructor();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.NeedsImplicitDestructor();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.NeedsImplicitMoveAssignment();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsImplicitMoveConstructor();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsOverloadResolutionForDestructor();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NullFieldOffsetIsZero();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  do {
    auto ov138 = e.VirtualBases();
    if (!ov138) {
      b.setVal339(false);
      break;
    }
    b.setVal339(true);
    auto v138 = std::move(*ov138);
    auto sv138 = b.initVal138(static_cast<unsigned>(v138.size()));
    auto i138 = 0u;
    for (const auto &e138 : v138) {
      sv138.set(i138, es.PseudoId(e138));
      ++i138;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t125 = e.ExternToken();
  b.setVal125(es.EntityId(t125));
  auto t126 = e.PointOfInstantiation();
  b.setVal126(es.EntityId(t126));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v340 = e.TemplateArguments();
    auto sv340 = b.initVal340(static_cast<unsigned>(v340.size()));
    auto i340 = 0u;
    for (const auto &e340 : v340) {
      sv340.set(i340, es.PseudoId(e340));
      ++i340;
    }
  } while (false);
  do {
    auto v341 = e.TemplateInstantiationArguments();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.PseudoId(e341));
      ++i341;
    }
  } while (false);
  auto t128 = e.TemplateKeywordToken();
  b.setVal128(es.EntityId(t128));
  auto v129 = e.TypeAsWritten();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  b.setVal342(e.IsClassScopeExplicitSpecialization());
  b.setVal343(e.IsExplicitInstantiationOrSpecialization());
  b.setVal344(e.IsExplicitSpecialization());
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
    auto v48 = e.Enumerators();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
  auto v73 = e.InstantiatedFromMemberEnum();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v76 = e.IntegerType();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  if (auto r77 = e.IntegerTypeRange(); auto rs77 = r77.Size()) {
    b.setVal77(es.EntityId(r77[0]));
    b.setVal78(es.EntityId(r77[rs77 - 1u]));
  } else {
    b.setVal77(0);
    b.setVal78(0);
  }
  auto v139 = e.ODRHash();
  if (v139) {
    b.setVal139(static_cast<unsigned>(v139.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  auto v80 = e.PromotionType();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal100(e.IsClosed());
  b.setVal101(e.IsClosedFlag());
  b.setVal102(e.IsClosedNonFlag());
  b.setVal103(e.IsComplete());
  b.setVal104(e.IsFixed());
  b.setVal105(e.IsScoped());
  b.setVal106(e.IsScopedUsingClassTag());
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
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
  b.setVal54(es.EntityId(e.UnderlyingType()));
  b.setVal70(e.IsModed());
  b.setVal71(e.IsTransparentTag());
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
    auto id62 = es.EntityId(v62.value());
    b.setVal62(id62);
  } else {
    b.setVal62(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t62 = e.ColonToken();
  b.setVal62(es.EntityId(t62));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t63 = e.VarianceToken();
  b.setVal63(es.EntityId(t63));
  b.setVal72(e.HasExplicitBound());
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
  auto v52 = e.InstantiatedFromMemberTemplate();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  b.setVal53(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal52(es.EntityId(e.ConstraintExpression()));
  b.setVal70(e.IsTypeConcept());
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
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal63(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal64(es.EntityId(e.SetterMethodDeclaration()));
  auto t73 = e.SetterNameToken();
  b.setVal73(es.EntityId(t73));
  b.setVal76(es.EntityId(e.Type()));
  b.setVal70(e.IsAtomic());
  b.setVal71(e.IsClassProperty());
  b.setVal72(e.IsDirectProperty());
  b.setVal88(e.IsInstanceProperty());
  b.setVal89(e.IsOptional());
  b.setVal90(e.IsReadOnly());
  b.setVal91(e.IsRetaining());
}

void SerializeObjCMethodDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal70(e.DefinedInNSObject());
  b.setVal52(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal53(es.EntityId(e.ClassInterface()));
  b.setVal54(es.EntityId(e.CommandDeclaration()));
  auto t62 = e.DeclaratorEndToken();
  b.setVal62(es.EntityId(t62));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal63(es.EntityId(e.ReturnType()));
  if (auto r64 = e.ReturnTypeSourceRange(); auto rs64 = r64.Size()) {
    b.setVal64(es.EntityId(r64[0]));
    b.setVal73(es.EntityId(r64[rs64 - 1u]));
  } else {
    b.setVal64(0);
    b.setVal73(0);
  }
  auto t76 = e.SelectorStartToken();
  b.setVal76(es.EntityId(t76));
  b.setVal77(es.EntityId(e.SelfDeclaration()));
  b.setVal71(e.HasParameterDestroyedInCallee());
  b.setVal72(e.HasRedeclaration());
  b.setVal88(e.HasRelatedResultType());
  b.setVal89(e.HasSkippedBody());
  b.setVal90(e.IsClassMethod());
  b.setVal91(e.IsDefined());
  b.setVal92(e.IsDesignatedInitializerForTheInterface());
  b.setVal93(e.IsDirectMethod());
  b.setVal94(e.IsInstanceMethod());
  b.setVal95(e.IsOptional());
  b.setVal96(e.IsOverriding());
  b.setVal97(e.IsPropertyAccessor());
  b.setVal98(e.IsRedeclaration());
  b.setVal99(e.IsSynthesizedAccessorStub());
  b.setVal100(e.IsThisDeclarationADesignatedInitializer());
  b.setVal101(e.IsVariadic());
  do {
    auto v47 = e.Parameters();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  do {
    auto v48 = e.SelectorTokens();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
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
    auto v47 = e.ClassMethods();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  do {
    auto v48 = e.ClassProperties();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
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
    auto v169 = e.InstanceProperties();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
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
    auto v313 = e.Properties();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  pasta::DeclContext dc345(e);
  auto v345 = dc345.AlreadyLoadedDeclarations();
  auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
  auto i345 = 0u;
  for (const pasta::Decl &e345 : v345) {
    sv345.set(i345, es.EntityId(e345));
    ++i345;
  }
}

void SerializeObjCCategoryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal70(e.IsClassExtension());
  auto t62 = e.CategoryNameToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.ClassInterface()));
  b.setVal64(es.EntityId(e.Implementation()));
  auto t73 = e.InstanceVariableLBraceToken();
  b.setVal73(es.EntityId(t73));
  auto t76 = e.InstanceVariableRBraceToken();
  b.setVal76(es.EntityId(t76));
  b.setVal77(es.EntityId(e.NextClassCategory()));
  do {
    auto v346 = e.InstanceVariables();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
  do {
    auto v347 = e.ProtocolTokens();
    auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
    auto i347 = 0u;
    for (const auto &e347 : v347) {
      sv347.set(i347, es.EntityId(e347));
      ++i347;
    }
  } while (false);
  do {
    auto v348 = e.Protocols();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  auto v69 = e.ObjCRuntimeNameAsString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal70(e.HasDefinition());
  b.setVal71(e.IsNonRuntimeProtocol());
  do {
    auto v346 = e.ProtocolTokens();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
  do {
    auto v347 = e.Protocols();
    auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
    auto i347 = 0u;
    for (const auto &e347 : v347) {
      sv347.set(i347, es.EntityId(e347));
      ++i347;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v346 = e.AllReferencedProtocols();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
  b.setVal70(e.DeclaresOrInheritsDesignatedInitializers());
  auto t62 = e.EndOfDefinitionToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.Implementation()));
  auto v69 = e.ObjCRuntimeNameAsString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  auto v64 = e.SuperClass();
  if (v64) {
    auto id64 = es.EntityId(v64.value());
    b.setVal64(id64);
  } else {
    b.setVal64(mx::kInvalidEntityId);
  }
  auto t73 = e.SuperClassToken();
  b.setVal73(es.EntityId(t73));
  auto v76 = e.SuperClassTypeInfo();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal77(es.EntityId(e.TypeForDeclaration()));
  b.setVal71(e.HasDefinition());
  b.setVal72(e.HasDesignatedInitializers());
  b.setVal88(e.IsArcWeakrefUnavailable());
  b.setVal89(e.IsImplicitInterfaceDeclaration());
  b.setVal78(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  do {
    auto v347 = e.InstanceVariables();
    auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
    auto i347 = 0u;
    for (const auto &e347 : v347) {
      sv347.set(i347, es.EntityId(e347));
      ++i347;
    }
  } while (false);
  do {
    auto v348 = e.KnownCategories();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
  do {
    auto v349 = e.KnownExtensions();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
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
  do {
    auto v352 = e.VisibleCategories();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.VisibleExtensions();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.EntityId(e353));
      ++i353;
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
    auto v346 = e.PropertyImplementations();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
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
  auto v69 = e.ObjCRuntimeNameAsString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal73(es.EntityId(e.SuperClass()));
  auto t76 = e.SuperClassToken();
  b.setVal76(es.EntityId(t76));
  b.setVal70(e.HasDestructors());
  b.setVal71(e.HasNonZeroConstructors());
  do {
    auto v347 = e.InstanceVariables();
    auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
    auto i347 = 0u;
    for (const auto &e347 : v347) {
      sv347.set(i347, es.EntityId(e347));
      ++i347;
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
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
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
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v47 = e.Children();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  b.setVal45(es.EntityId(e.ExtendingDeclaration()));
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal52(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v47 = e.IdentifierTokens();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
  auto v45 = e.FriendDeclaration();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto t52 = e.FriendToken();
  b.setVal52(es.EntityId(t52));
  auto v53 = e.FriendType();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
  b.setVal46(e.IsUnsupportedFriend());
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
  auto t45 = e.AssemblyToken();
  b.setVal45(es.EntityId(t45));
  b.setVal52(es.EntityId(e.AssemblyString()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
}

void SerializeExternCContextDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeExportDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t45 = e.ExportToken();
  b.setVal45(es.EntityId(t45));
  auto t52 = e.RBraceToken();
  b.setVal52(es.EntityId(t52));
  b.setVal46(e.HasBraces());
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializeEmptyDecl(EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
