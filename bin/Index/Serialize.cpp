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
#include "Pseudo.h"
#include "TokenTree.h"
#include "Util.h"
namespace indexer {

void SerializeDesignator(const EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::Designator &e) {
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

void SerializeTemplateParameterList(const EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateParameterList &e) {
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

void SerializeTemplateArgument(const EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::TemplateArgument &e) {
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

void SerializeCXXBaseSpecifier(const EntityMapper &es, mx::ast::Pseudo::Builder b, const pasta::CXXBaseSpecifier &e) {
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

void SerializeMacro(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::Macro &e, const TokenTree *tt) {
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

void SerializeMacroVAOptArgument(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOptArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroSubstitution(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroSubstitution &e, const TokenTree *tt) {
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

void SerializeMacroVAOpt(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOpt &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroConcatenate(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroConcatenate &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroStringify(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroStringify &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeMacroExpansion(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroExpansion &e, const TokenTree *tt) {
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

void SerializeMacroArgument(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  b.setVal6(e.IsVariadic());
  b.setVal7(e.Index());
}

void SerializeMacroParameter(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameter &e, const TokenTree *tt) {
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

void SerializeMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  auto t4 = e.Hash();
  b.setVal4(es.EntityId(t4));
  auto v8 = e.DirectiveName();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
}

void SerializeDefineMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::DefineMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
  auto t9 = e.Name();
  b.setVal9(es.EntityId(t9));
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
  b.setVal10(e.IsFunctionLike());
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

void SerializePragmaMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::PragmaMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeUndefineMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::UndefineMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeOtherMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::OtherMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeConditionalMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ConditionalMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
}

void SerializeEndIfMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::EndIfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeElseMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeElseIfNotDefinedMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeElseIfDefinedMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeElseIfMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeIfNotDefinedMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeIfDefinedMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeIfMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(es, b, e, tt);
}

void SerializeIncludeLikeMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeLikeMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
  auto v9 = e.IncludedFile();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
}

void SerializeImportMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ImportMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeMacrosMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacrosMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeNextMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeNextMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeIncludeMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(es, b, e, tt);
}

void SerializeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Attr &e) {
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

void SerializeAlignValueAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignValueAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal8(es.EntityId(e.Alignment()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AliasAttr &e) {
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

void SerializeAbiTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AbiTagAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
}

void SerializeSPtrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SPtrAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtr64Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr64Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtr32Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr32Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLPrivateAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLPrivateAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLLocalAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLLocalAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalHostAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalHostAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalDeviceAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalDeviceAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGlobalAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLGenericAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGenericAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLConstantAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLConstantAddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCKindOfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCKindOfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCInertUnsafeUnretainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCInertUnsafeUnretainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCGCAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCGCAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDerefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDerefAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCmseNSCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBTFTypeTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFTypeTagAttr &e) {
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

void SerializeArmMveStrictPolymorphismAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmMveStrictPolymorphismAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnnotateTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateTypeAttr &e) {
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

void SerializeAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AddressSpaceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUPtrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UPtrAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullableResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNullUnspecifiedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullUnspecifiedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeThreadAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThreadAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftObjCMembersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftObjCMembersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStmtAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StmtAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
}

void SerializeOpenCLUnrollHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLUnrollHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMustTailAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MustTailAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLikelyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LikelyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFallThroughAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FallThroughAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnlikelyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnlikelyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSuppressAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SuppressAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRenderScriptKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RenderScriptKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOverloadableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverloadableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLAccessAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLAccessAttr &e) {
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

void SerializeObjCRuntimeVisibleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeVisibleAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRuntimeNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeNameAttr &e) {
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

void SerializeObjCNonRuntimeProtocolAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonRuntimeProtocolAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNonLazyClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonLazyClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDirectMembersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectMembersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDirectAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCDesignatedInitializerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDesignatedInitializerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCClassStubAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCClassStubAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBoxableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBoxableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPReferencedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPReferencedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal8(es.EntityId(e.Reference()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPDeclareSimdDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareSimdDeclAttr &e) {
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

void SerializeOMPCaptureKindAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureKindAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoEscapeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoEscapeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoBuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeModeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ModeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLoopHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoopHintAttr &e) {
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

void SerializeLoaderUninitializedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoaderUninitializedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInitSegAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitSegAttr &e) {
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

void SerializeInheritableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal12(e.ShouldInheritEvenIfAlreadyPresent());
}

void SerializeIBOutletCollectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletCollectionAttr &e) {
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

void SerializeIBOutletAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIBActionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBActionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHotAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HotAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHLSLShaderAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLShaderAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeHLSLSV_GroupIndexAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_GroupIndexAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHLSLNumThreadsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLNumThreadsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeHIPManagedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HIPManagedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGuardedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGuardedByAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedByAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeGNUInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GNUInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFunctionReturnThunksAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FunctionReturnThunksAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ThunkType())));
}

void SerializeFormatAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFormatArgAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatArgAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFlattenAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlattenAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFlagEnumAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlagEnumAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeFinalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FinalAttr &e) {
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

void SerializeFastCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FastCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeExternalSourceSymbolAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExternalSourceSymbolAttr &e) {
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

void SerializeExclusiveTrylockFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExclusiveTrylockFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeExcludeFromExplicitInstantiationAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExcludeFromExplicitInstantiationAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ErrorAttr &e) {
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

void SerializeEnumExtensibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnumExtensibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Extensibility())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnforceTCBLeafAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBLeafAttr &e) {
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

void SerializeEnforceTCBAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBAttr &e) {
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

void SerializeEnableIfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnableIfAttr &e) {
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

void SerializeEmptyBasesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EmptyBasesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDisableTailCallsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableTailCallsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDisableSanitizerInstrumentationAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableSanitizerInstrumentationAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDiagnoseIfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseIfAttr &e) {
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

void SerializeDiagnoseAsBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseAsBuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Function()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDestructorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DestructorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDeprecatedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeprecatedAttr &e) {
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

void SerializeDeclOrStmtAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeclOrStmtAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
}

void SerializeAlwaysInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysInlineAttr &e) {
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

void SerializeNoMergeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMergeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInlineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.IsClangNoInline());
}

void SerializeDLLImportStaticLocalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportStaticLocalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLImportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLExportStaticLocalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportStaticLocalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeDLLExportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConvergentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConvergentAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableSetOnReadAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableSetOnReadAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableAutoCastAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAutoCastAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConsumableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.DefaultState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConstructorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstructorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeConstInitAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstInitAttr &e) {
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

void SerializeConstAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCommonAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CommonAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeColdAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ColdAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCodeSegAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeSegAttr &e) {
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

void SerializeCmseNSEntryAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSEntryAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCleanupAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CleanupAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.FunctionDeclaration()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCapturedRecordAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapturedRecordAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapabilityAttr &e) {
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

void SerializeCallbackAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallbackAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCallableWhenAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallableWhenAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCXX11NoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CXX11NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDASharedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDASharedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDALaunchBoundsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDALaunchBoundsAttr &e) {
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

void SerializeCUDAInvalidTargetAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAInvalidTargetAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAHostAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAHostAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAGlobalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAGlobalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceBuiltinTextureTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinTextureTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceBuiltinSurfaceTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinSurfaceTypeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDADeviceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCUDAConstantAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAConstantAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCPUSpecificAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUSpecificAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCPUDispatchAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUDispatchAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFUnknownTransferAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFUnknownTransferAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFICanonicalJumpTableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFICanonicalJumpTableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFGuardAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFGuardAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Guard())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFAuditedTransferAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFAuditedTransferAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeC11NoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::C11NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBlocksAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BlocksAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeBTFDeclTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFDeclTagAttr &e) {
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

void SerializeBPFPreserveAccessIndexAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BPFPreserveAccessIndexAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAvailabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AvailabilityAttr &e) {
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

void SerializeAssumptionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumptionAttr &e) {
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

void SerializeAssumeAlignedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumeAlignedAttr &e) {
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

void SerializeAssertSharedLockAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertSharedLockAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssertExclusiveLockAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertExclusiveLockAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssertCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertCapabilityAttr &e) {
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

void SerializeAsmLabelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AsmLabelAttr &e) {
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

void SerializeArtificialAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArtificialAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArmBuiltinAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmBuiltinAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArgumentWithTypeTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArgumentWithTypeTagAttr &e) {
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

void SerializeArcWeakrefUnavailableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArcWeakrefUnavailableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86NoCfCheckAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCfCheckAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86NoCallerSavedRegistersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCallerSavedRegistersAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnyX86InterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86InterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnalyzerNoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnalyzerNoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlwaysDestroyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysDestroyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAllocSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAllocAlignAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocAlignAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlignedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignedAttr &e) {
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

void SerializeAlignNaturalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignNaturalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAlignMac68kAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignMac68kAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquiredBeforeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredBeforeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquiredAfterAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredAfterAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquireHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireHandleAttr &e) {
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

void SerializeAcquireCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireCapabilityAttr &e) {
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

void SerializeAVRSignalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRSignalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAVRInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeARMInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ARMInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUWavesPerEUAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUWavesPerEUAttr &e) {
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

void SerializeAMDGPUNumVGPRAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumVGPRAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUNumSGPRAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumSGPRAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUKernelCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUKernelCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAMDGPUFlatWorkGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUFlatWorkGroupSizeAttr &e) {
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

void SerializeAArch64VectorPcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64VectorPcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAArch64SVEPcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64SVEPcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeZeroCallUsedRegsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ZeroCallUsedRegsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ZeroCallUsedRegs())));
}

void SerializeXRayLogArgsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayLogArgsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeXRayInstrumentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayInstrumentAttr &e) {
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

void SerializeX86ForceAlignArgPointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::X86ForceAlignArgPointerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWorkGroupSizeHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WorkGroupSizeHintAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyImportNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportNameAttr &e) {
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

void SerializeWebAssemblyImportModuleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportModuleAttr &e) {
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

void SerializeWebAssemblyExportNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyExportNameAttr &e) {
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

void SerializeWeakRefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakRefAttr &e) {
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

void SerializeWeakImportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakImportAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWarnUnusedResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedResultAttr &e) {
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

void SerializeWarnUnusedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeVisibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VisibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeVectorCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VectorCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeVecTypeHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecTypeHintAttr &e) {
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

void SerializeVecReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUuidAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UuidAttr &e) {
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

void SerializeUsingIfExistsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsingIfExistsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUsedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnusedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnusedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUninitializedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UninitializedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUnavailableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnavailableAttr &e) {
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

void SerializeTypeVisibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeVisibilityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeTypeTagForDatatypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeTagForDatatypeAttr &e) {
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

void SerializeTryAcquireCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TryAcquireCapabilityAttr &e) {
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

void SerializeTrivialABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TrivialABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTransparentUnionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TransparentUnionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeThisCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThisCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTestTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TestTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.TestState())));
}

void SerializeTargetClonesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetClonesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTargetAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetAttr &e) {
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

void SerializeTLSModelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TLSModelAttr &e) {
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

void SerializeSysVABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SysVABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftPrivateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftPrivateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftNewTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNewTypeAttr &e) {
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

void SerializeSwiftNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNameAttr &e) {
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

void SerializeSwiftErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftBridgedTypedefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgedTypedefAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftBridgeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgeAttr &e) {
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

void SerializeSwiftAttrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAttrAttr &e) {
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

void SerializeSwiftAsyncNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncNameAttr &e) {
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

void SerializeSwiftAsyncErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncErrorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStrictFPAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictFPAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStdCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StdCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeStandaloneDebugAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StandaloneDebugAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSpeculativeLoadHardeningAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SpeculativeLoadHardeningAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSharedTrylockFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SharedTrylockFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeSetTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SetTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.NewState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSentinelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SentinelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSelectAnyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SelectAnyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SectionAttr &e) {
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

void SerializeScopedLockableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ScopedLockableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSYCLSpecialClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLSpecialClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSYCLKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnsTwiceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsTwiceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnsNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsNonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReturnTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.State())));
}

void SerializeRetainAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RetainAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRestrictAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RestrictAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRequiresCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RequiresCapabilityAttr &e) {
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

void SerializeReqdWorkGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReqdWorkGroupSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReleaseCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseCapabilityAttr &e) {
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

void SerializeReinitializesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReinitializesAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRegCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RegCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRandomizeLayoutAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RandomizeLayoutAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeRISCVInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RISCVInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePureAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PureAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtGuardedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedVarAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePtGuardedByAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedByAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreserveMostAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveMostAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreserveAllAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveAllAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePreferredNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredNameAttr &e) {
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

void SerializePragmaClangTextSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangTextSectionAttr &e) {
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

void SerializePragmaClangRodataSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRodataSectionAttr &e) {
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

void SerializePragmaClangRelroSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRelroSectionAttr &e) {
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

void SerializePragmaClangDataSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangDataSectionAttr &e) {
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

void SerializePragmaClangBSSSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangBSSSectionAttr &e) {
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

void SerializePointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PointerAttr &e) {
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

void SerializePcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PcsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.PCS())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePatchableFunctionEntryAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PatchableFunctionEntryAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePascalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PascalAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeParamTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParamTypestateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ParameterState())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePackedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PackedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOwnershipAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnershipAttr &e) {
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

void SerializeOwnerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnerAttr &e) {
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

void SerializeOverrideAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverrideAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOptimizeNoneAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OptimizeNoneAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLKernelAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOpenCLIntelReqdSubGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLIntelReqdSubGroupSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCSubclassingRestrictedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCSubclassingRestrictedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRootClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRootClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCReturnsInnerPointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCReturnsInnerPointerAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRequiresSuperAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresSuperAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCRequiresPropertyDefsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresPropertyDefsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCPreciseLifetimeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCPreciseLifetimeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCOwnershipAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCOwnershipAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNSObjectAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNSObjectAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCMethodFamilyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCMethodFamilyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Family())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCIndependentClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCIndependentClassAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExternallyRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExternallyRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExplicitProtocolImplAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExplicitProtocolImplAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCExceptionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExceptionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeRelatedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeRelatedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeMutableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeMutableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCBridgeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedOnZeroAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnZeroAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedOnNonZeroAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnNonZeroAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSConsumesThisAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumesThisAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPThreadPrivateDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPThreadPrivateDeclAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPDeclareVariantAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareVariantAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.VariantFuncReference()));
}

void SerializeOMPDeclareTargetDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareTargetDeclAttr &e) {
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

void SerializeOMPCaptureNoInitAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureNoInitAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOMPAllocateDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPAllocateDeclAttr &e) {
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

void SerializeNotTailCalledAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NotTailCalledAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoUniqueAddressAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUniqueAddressAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoThrowAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThrowAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoThreadSafetyAnalysisAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThreadSafetyAnalysisAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoStackProtectorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoStackProtectorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSplitStackAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSplitStackAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSpeculativeLoadHardeningAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSpeculativeLoadHardeningAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoSanitizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSanitizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal13(e.HasCoverage());
}

void SerializeNoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoReturnAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoRandomizeLayoutAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoRandomizeLayoutAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoProfileFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoProfileFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoMips16Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMips16Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoMicroMipsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMicroMipsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoInstrumentFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInstrumentFunctionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDuplicateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDuplicateAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDestroyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDestroyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoDebugAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDebugAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoCommonAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoCommonAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNoAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNakedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NakedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsNotRetainedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSReturnsAutoreleasedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsAutoreleasedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSErrorDomainAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSErrorDomainAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.ErrorDomain()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSConsumesSelfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumesSelfAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsShortCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsShortCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsLongCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsLongCallAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMipsInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMips16Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Mips16Attr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMinVectorWidthAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinVectorWidthAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMinSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinSizeAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMicroMipsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MicroMipsAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMayAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MayAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMaxFieldAlignmentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaxFieldAlignmentAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSVtorDispAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSVtorDispAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.VtorDispMode())));
}

void SerializeMSStructAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSStructAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSP430InterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSP430InterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSNoVTableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSNoVTableAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSInheritanceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSInheritanceAttr &e) {
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

void SerializeMSAllocatorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSAllocatorAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMSABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeMIGServerRoutineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MIGServerRoutineAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeM68kInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::M68kInterruptAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLocksExcludedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LocksExcludedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLockReturnedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LockReturnedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  b.setVal8(es.EntityId(e.Argument()));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLifetimeBoundAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LifetimeBoundAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLeafAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LeafAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLayoutVersionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LayoutVersionAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeLTOVisibilityPublicAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LTOVisibilityPublicAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInternalLinkageAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InternalLinkageAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIntelOclBiccAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IntelOclBiccAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInitPriorityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitPriorityAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInheritableParamAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableParamAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e);
}

void SerializeCarriesDependencyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CarriesDependencyAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCFConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAnnotateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateAttr &e) {
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

void SerializeUseHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UseHandleAttr &e) {
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

void SerializeReleaseHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseHandleAttr &e) {
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

void SerializePassObjectSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PassObjectSizeAttr &e) {
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

void SerializeParameterABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParameterABIAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ABI())));
}

void SerializeSwiftIndirectResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftIndirectResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftErrorResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorResultAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftContextAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftContextAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncContextAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncContextAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeOSConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NonNullAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeNSConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumedAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeIFuncAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IFuncAttr &e) {
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

void SerializeCalledOnceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CalledOnceAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBuiltinAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAliasAttr &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e);
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.Spelling();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::Type &e) {
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

void SerializeTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e) {
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

void SerializeTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e) {
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

void SerializeTagType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Declaration()));
  b.setVal293(e.IsBeingDefined());
}

void SerializeRecordType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal294(e.HasConstFields());
  b.setVal295(e.IsSugared());
}

void SerializeEnumType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal294(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ReplacedParameter()));
  b.setVal297(es.EntityId(e.ReplacementType()));
  b.setVal293(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ReplacedParameter()));
  b.setVal293(e.IsSugared());
}

void SerializeReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal293(e.IsInnerReference());
  b.setVal294(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal295(e.IsSugared());
}

void SerializeLValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal295(e.IsSugared());
}

void SerializePointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializePipeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsReadOnly());
  b.setVal294(e.IsSugared());
}

void SerializeParenType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.InnerType()));
  b.setVal293(e.IsSugared());
}

void SerializePackExpansionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e) {
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

void SerializeObjCTypeParamType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeObjCObjectType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e) {
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

void SerializeObjCInterfaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e);
  b.setVal314(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e) {
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

void SerializeMemberPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e) {
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

void SerializeMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
  auto t297 = e.AttributeToken();
  b.setVal297(es.EntityId(t297));
  b.setVal299(es.EntityId(e.ColumnExpression()));
  b.setVal313(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e);
}

void SerializeMacroQualifiedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ModifiedType()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeInjectedClassNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e) {
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

void SerializeFunctionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e) {
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

void SerializeFunctionProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e) {
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

void SerializeFunctionNoProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e);
  b.setVal297(es.EntityId(e.Desugar()));
  b.setVal305(e.IsSugared());
}

void SerializeDependentVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e) {
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

void SerializeDependentSizedExtVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e) {
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

void SerializeDependentBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e) {
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

void SerializeDependentAddressSpaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e) {
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

void SerializeDeducedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e) {
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

void SerializeDeducedTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedTemplateSpecializationType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e);
}

void SerializeAutoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AutoType &e) {
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

void SerializeDecltypeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingExpression()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeComplexType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal293(e.IsSugared());
}

void SerializeBuiltinType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e) {
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

void SerializeBlockPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSigned());
  b.setVal294(e.IsSugared());
  b.setVal295(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Attribute()));
  b.setVal297(es.EntityId(e.WrappedType()));
  b.setVal293(e.IsSugared());
}

void SerializeAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e) {
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

void SerializeAtomicType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ValueType()));
  b.setVal293(e.IsSugared());
}

void SerializeArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.ElementType()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e) {
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

void SerializeIncompleteArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e);
  b.setVal292(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeDependentSizedArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e) {
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

void SerializeConstantArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e) {
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

void SerializeAdjustedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ResolvedType()));
  b.setVal297(es.EntityId(e.OriginalType()));
  b.setVal293(e.IsSugared());
}

void SerializeDecayedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(es, b, e);
}

void SerializeTypeWithKeyword(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e) {
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

void SerializeDependentTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e) {
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

void SerializeDependentNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal293(e.IsSugared());
}

void SerializeVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.ElementType()));
  b.setVal317(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal293(e.IsSugared());
}

void SerializeExtVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(es, b, e);
}

void SerializeUsingType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.FoundDeclaration()));
  b.setVal297(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeUnresolvedUsingType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeUnaryTransformType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e) {
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

void SerializeTypedefType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.Declaration()));
  b.setVal293(e.IsSugared());
}

void SerializeTypeOfType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingType()));
  b.setVal293(e.IsSugared());
}

void SerializeTypeOfExprType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e);
  b.setVal291(es.EntityId(e.Desugar()));
  b.setVal292(es.EntityId(e.UnderlyingExpression()));
  b.setVal293(e.IsSugared());
}

void SerializeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e) {
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

void SerializeSEHTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ExceptHandler()));
  b.setVal10(es.EntityId(e.FinallyHandler()));
  b.setVal11(es.EntityId(e.Handler()));
  b.setVal12(e.IsCXXTry());
  b.setVal13(es.EntityId(e.TryBlock()));
  auto t14 = e.TryToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeSEHLeaveStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.LeaveToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeSEHFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.FinallyToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeSEHExceptStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.ExceptToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e) {
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

void SerializeObjCForCollectionStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Collection()));
  b.setVal11(es.EntityId(e.Element()));
  auto t13 = e.ForToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeObjCAutoreleasePoolStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e) {
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

void SerializeObjCAtThrowStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.ThrowExpression()));
  auto t10 = e.ThrowToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeObjCAtSynchronizedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtSynchronizedToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SynchBody()));
  b.setVal11(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtFinallyToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.AtCatchToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.CatchBody()));
  b.setVal11(es.EntityId(e.CatchParameterDeclaration()));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
  b.setVal12(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.AssociatedStatement()));
  b.setVal10(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal11(es.EntityId(e.RawStatement()));
  b.setVal13(es.EntityId(e.StructuredBlock()));
  b.setVal12(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  auto t14 = e.TargetCallToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeOMPDepobjDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCriticalDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancellationPointDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCancelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPBarrierDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPAtomicDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e) {
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

void SerializeOMPTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskyieldDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskwaitDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTaskgroupDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetEnterDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPTargetDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSingleDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSectionDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPScanDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPParallelSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPOrderedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMetaDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
  b.setVal14(es.EntityId(e.IfStatement()));
}

void SerializeOMPMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPLoopBasedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPLoopTransformationDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e) {
  SerializeOMPLoopBasedDirective(es, b, e);
  b.setVal14(es.EntityId(e.PreInitializers()));
  b.setVal17(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPUnrollDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e) {
  SerializeOMPLoopTransformationDirective(es, b, e);
}

void SerializeOMPTileDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e) {
  SerializeOMPLoopTransformationDirective(es, b, e);
}

void SerializeOMPLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e) {
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

void SerializeOMPGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTeamsDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPTargetParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
}

void SerializeOMPMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e) {
  SerializeOMPLoopDirective(es, b, e);
  b.setVal23(e.HasCancel());
}

void SerializeOMPInteropDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPFlushDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e) {
  SerializeOMPExecutableDirective(es, b, e);
}

void SerializeOMPCanonicalLoop(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal10(es.EntityId(e.LoopStatement()));
  b.setVal11(es.EntityId(e.LoopVariableFunc()));
  b.setVal13(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.SemiToken();
  b.setVal9(es.EntityId(t9));
  b.setVal12(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e) {
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

void SerializeIfStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e) {
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

void SerializeGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.GotoToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Label()));
  auto t11 = e.LabelToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeForStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e) {
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

void SerializeDoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e) {
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

void SerializeDeclStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e) {
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

void SerializeCoroutineBodyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e) {
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

void SerializeCoreturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Operand()));
  b.setVal11(es.EntityId(e.PromiseCall()));
  b.setVal12(e.IsImplicit());
}

void SerializeContinueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.ContinueToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeCompoundStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e) {
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

void SerializeCapturedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e) {
  SerializeStmt(es, b, e);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal11(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e) {
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

void SerializeCXXForRangeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e) {
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

void SerializeCXXCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e) {
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

void SerializeBreakStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e) {
  SerializeStmt(es, b, e);
  auto t9 = e.BreakToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e) {
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

void SerializeMSAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e) {
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

void SerializeGCCAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e) {
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

void SerializeWhileStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e) {
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

void SerializeValueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e) {
  SerializeStmt(es, b, e);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e) {
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

void SerializeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e) {
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

void SerializeDesignatedInitUpdateExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e) {
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

void SerializeDependentScopeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e) {
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

void SerializeDependentCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.KeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal40(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e) {
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

void SerializeCoroutineSuspendExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e) {
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

void SerializeCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
  b.setVal90(e.IsImplicit());
}

void SerializeCoyieldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e) {
  SerializeCoroutineSuspendExpr(es, b, e);
}

void SerializeConvertVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e) {
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

void SerializeCompoundLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Initializer()));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsFileScope());
}

void SerializeChooseExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e) {
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

void SerializeCharacterLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e) {
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

void SerializeImplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal91(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e) {
  SerializeCastExpr(es, b, e);
  b.setVal42(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e) {
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

void SerializeCXXDynamicCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
  b.setVal91(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXAddrspaceCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXStaticCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXReinterpretCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e) {
  SerializeCXXNamedCastExpr(es, b, e);
}

void SerializeCXXFunctionalCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal91(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeBuiltinBitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e) {
  SerializeExplicitCastExpr(es, b, e);
}

void SerializeObjCBridgedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e) {
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

void SerializeCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e) {
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

void SerializeCXXOperatorCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e) {
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

void SerializeCUDAKernelCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e) {
  SerializeCallExpr(es, b, e);
  b.setVal44(es.EntityId(e.CookedLiteral()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t45 = e.UDSuffixToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXUuidofExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e) {
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

void SerializeCXXUnresolvedConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e) {
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

void SerializeCXXTypeidExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e) {
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

void SerializeCXXThrowExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e) {
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

void SerializeCXXThisExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXRewrittenBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e) {
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

void SerializeCXXPseudoDestructorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e) {
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

void SerializeCXXNullPtrLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXNoexceptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal90(e.Value());
}

void SerializeCXXNewExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e) {
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

void SerializeCXXInheritedCtorInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ConstructsVirtualBase());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal38(es.EntityId(e.Constructor()));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal91(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e) {
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

void SerializeCXXDependentScopeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e) {
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

void SerializeCXXDeleteExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal91(e.IsArrayForm());
  b.setVal92(e.IsArrayFormAsWritten());
  b.setVal93(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e) {
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

void SerializeCXXDefaultArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  auto t40 = e.UsedToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeCXXConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e) {
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

void SerializeCXXTemporaryObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e) {
  SerializeCXXConstructExpr(es, b, e);
}

void SerializeCXXBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.Value());
}

void SerializeCXXBindTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BlockDeclaration()));
  b.setVal39(es.EntityId(e.Body()));
  auto t40 = e.CaretToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e) {
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

void SerializeCompoundAssignOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e) {
  SerializeBinaryOperator(es, b, e);
  b.setVal41(es.EntityId(e.ComputationLHSType()));
  b.setVal42(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e) {
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

void SerializeAsTypeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DimensionExpression()));
  b.setVal39(es.EntityId(e.QueriedType()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.LHS()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeAddrLabelExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AmpAmpToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Label()));
  auto t40 = e.LabelToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeAbstractConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.ColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.FalseExpression()));
  auto t41 = e.QuestionToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.LHS()));
  b.setVal44(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e) {
  SerializeAbstractConditionalOperator(es, b, e);
  b.setVal43(es.EntityId(e.Common()));
  b.setVal44(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.WrittenType()));
  b.setVal90(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e) {
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

void SerializeUnaryExprOrTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e) {
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

void SerializeTypoExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e) {
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

void SerializeSubstNonTypeTemplateParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.ParameterPack()));
  auto t39 = e.ParameterPackToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSubstNonTypeTemplateParmExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.NameToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
  b.setVal90(e.IsReferenceParameter());
}

void SerializeStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e) {
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

void SerializeStmtExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e) {
  SerializeExpr(es, b, e);
  auto v61 = e.BuiltinString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsIntType());
}

void SerializeSizeOfPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e) {
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

void SerializeShuffleVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSYCLUniqueStableNameExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal61(e.ComputeName());
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeRequiresExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e) {
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

void SerializeRecoveryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e) {
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

void SerializePseudoObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e) {
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

void SerializePredefinedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.FunctionName()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v61 = e.IdentifierKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeParenListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e) {
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

void SerializeParenExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e) {
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

void SerializeOverloadExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e) {
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

void SerializeUnresolvedMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e) {
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

void SerializeUnresolvedLookupExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e) {
  SerializeOverloadExpr(es, b, e);
  b.setVal92(e.IsOverloaded());
  b.setVal93(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal90(e.IsUnique());
}

void SerializeOffsetOfExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCSubscriptRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal39(es.EntityId(e.BaseExpression()));
  b.setVal40(es.EntityId(e.KeyExpression()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal90(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCProtocolExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Protocol()));
  auto t40 = e.ProtocolIdToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeObjCPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e) {
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

void SerializeObjCMessageExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e) {
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

void SerializeObjCIvarRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e) {
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

void SerializeObjCIsaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e) {
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

void SerializeObjCIndirectCopyRestoreExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal90(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.EncodedType()));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCDictionaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.BoxingMethod()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.HasVersion());
}

void SerializeObjCArrayLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e) {
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

void SerializeOMPIteratorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.IteratorKwToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeOMPArrayShapingExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e) {
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

void SerializeOMPArraySectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e) {
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

void SerializeNoInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e) {
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

void SerializeMatrixSubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal90(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e) {
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

void SerializeMSPropertySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeMSPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.BaseExpression()));
  auto t39 = e.MemberToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.PropertyDeclaration()));
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e) {
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

void SerializeIntegerLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeInitListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e) {
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

void SerializeImplicitValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e) {
  SerializeExpr(es, b, e);
}

void SerializeImaginaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e) {
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

void SerializeGNUNullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.TokenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeFunctionParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e) {
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

void SerializeFullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e) {
  SerializeFullExpr(es, b, e);
  b.setVal90(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e) {
  SerializeFullExpr(es, b, e);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal90(e.HasAPValueResult());
  b.setVal91(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal90(e.IsExact());
}

void SerializeFixedPointLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e) {
  SerializeExpr(es, b, e);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeExtVectorElementExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal90(e.ContainsDuplicateElements());
  auto t38 = e.AccessorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal91(e.IsArrow());
}

void SerializeExpressionTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e) {
  SerializeExpr(es, b, e);
  b.setVal38(es.EntityId(e.QueriedExpression()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal90(e.Value());
}

void SerializeAttributedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e) {
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

void SerializeSwitchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e) {
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

void SerializeSwitchCase(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e) {
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

void SerializeDefaultStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e) {
  SerializeSwitchCase(es, b, e);
  auto t14 = e.DefaultToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeCaseStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e) {
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

void SerializeDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e) {
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
  b.setVal39(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal40(static_cast<unsigned char>(mx::FromPasta(e.Category())));
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

void SerializeClassScopeFunctionSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.Specialization()));
  b.setVal45(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e) {
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

void SerializeBlockDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e) {
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
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto t51 = e.CaretToken();
  b.setVal51(es.EntityId(t51));
  b.setVal52(es.EntityId(e.CompoundBody()));
  b.setVal53(es.EntityId(e.SignatureAsWritten()));
  b.setVal54(e.HasCaptures());
  b.setVal55(e.IsConversionFromLambda());
  b.setVal56(e.IsVariadic());
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
  pasta::DeclContext dc57(e);
  auto v57 = dc57.AlreadyLoadedDeclarations();
  auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
  auto i57 = 0u;
  for (const pasta::Decl &e57 : v57) {
    sv57.set(i57, es.EntityId(e57));
    ++i57;
  }
}

void SerializeAccessSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.AccessSpecifierToken();
  b.setVal44(es.EntityId(t44));
  auto t51 = e.ColonToken();
  b.setVal51(es.EntityId(t51));
}

void SerializeOMPDeclarativeDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

void SerializeOMPThreadPrivateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e) {
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

void SerializeOMPRequiresDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e);
}

void SerializeOMPAllocateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e) {
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

void SerializeTranslationUnitDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e) {
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

void SerializeStaticAssertDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.AssertExpression()));
  b.setVal51(es.EntityId(e.Message()));
  auto t52 = e.RParenToken();
  b.setVal52(es.EntityId(t52));
  b.setVal45(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e) {
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

void SerializePragmaDetectMismatchDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e) {
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

void SerializePragmaCommentDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v58 = e.Argument();
  std::string s58(v58.data(), v58.size());
  b.setVal58(s58);
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal44(es.EntityId(e.GetterCXXConstructor()));
  b.setVal51(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal52(es.EntityId(e.PropertyDeclaration()));
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal53(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t61 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal61(es.EntityId(t61));
  b.setVal62(es.EntityId(e.SetterCXXAssignment()));
  b.setVal63(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal45(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal58(e.Name());
  auto v64 = e.ObjCFStringFormattingFamily();
  if (v64) {
    b.setVal64(static_cast<unsigned char>(v64.value()));
    b.setVal45(true);
  } else {
    b.setVal45(false);
  }
  b.setVal59(e.QualifiedNameAsString());
  b.setVal44(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal65(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal48(e.HasExternalFormalLinkage());
  b.setVal49(e.HasLinkage());
  b.setVal50(e.HasLinkageBeenComputed());
  b.setVal54(e.IsCXXClassMember());
  b.setVal55(e.IsCXXInstanceMember());
  b.setVal56(e.IsExternallyDeclarable());
  b.setVal66(e.IsExternallyVisible());
  b.setVal67(e.IsLinkageValid());
}

void SerializeLabelDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e) {
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

void SerializeBaseUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e) {
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

void SerializeUsingEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e) {
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

void SerializeUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e);
  auto t51 = e.UsingToken();
  b.setVal51(es.EntityId(t51));
  b.setVal69(e.HasTypename());
  b.setVal70(e.IsAccessDeclaration());
}

void SerializeValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.Type()));
  b.setVal69(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto t52 = e.EllipsisToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.UsingToken();
  b.setVal53(es.EntityId(t53));
  b.setVal70(e.IsAccessDeclaration());
  b.setVal71(e.IsPackExpansion());
}

void SerializeUnnamedGlobalConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnnamedGlobalConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeTemplateParamObjectDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareReductionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e) {
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
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeMSGuidDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeIndirectFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e) {
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
  auto v52 = e.AnonymousField();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  auto v53 = e.VariableDeclaration();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  auto v52 = e.InitializerExpression();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e) {
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
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  auto t62 = e.TypeSpecEndToken();
  b.setVal62(es.EntityId(t62));
  auto t63 = e.TypeSpecStartToken();
  b.setVal63(es.EntityId(t63));
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

void SerializeVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.ActingDefinition();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v75 = e.Initializer();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v76 = e.InitializingDeclaration();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v77 = e.InstantiatedFromStaticDataMember();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t79 = e.PointOfInstantiation();
  b.setVal79(es.EntityId(t79));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v84 = e.TemplateInstantiationPattern();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal70(e.HasConstantInitialization());
  b.setVal71(e.HasDependentAlignment());
  b.setVal87(e.HasExternalStorage());
  auto v88 = e.HasFlexibleArrayInitializer();
  if (v88) {
    b.setVal88(static_cast<bool>(v88.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal90(e.HasGlobalStorage());
  auto v91 = e.HasICEInitializer();
  if (v91) {
    b.setVal91(static_cast<bool>(v91.value()));
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  b.setVal93(e.HasInitializer());
  b.setVal94(e.HasLocalStorage());
  b.setVal95(e.IsARCPseudoStrong());
  b.setVal96(e.IsCXXForRangeDeclaration());
  b.setVal97(e.IsConstexpr());
  b.setVal98(e.IsDirectInitializer());
  b.setVal99(e.IsEscapingByref());
  b.setVal100(e.IsExceptionVariable());
  b.setVal101(e.IsExternC());
  b.setVal102(e.IsFileVariableDeclaration());
  b.setVal103(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal104(e.IsInExternCContext());
  b.setVal105(e.IsInExternCXXContext());
  b.setVal106(e.IsInitializerCapture());
  b.setVal107(e.IsInline());
  b.setVal108(e.IsInlineSpecified());
  b.setVal109(e.IsKnownToBeDefined());
  b.setVal110(e.IsLocalVariableDeclaration());
  b.setVal111(e.IsLocalVariableDeclarationOrParm());
  b.setVal112(e.IsNRVOVariable());
  b.setVal113(e.IsNoDestroy());
  b.setVal114(e.IsNonEscapingByref());
  b.setVal115(e.IsObjCForDeclaration());
  b.setVal116(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal117(e.IsStaticDataMember());
  b.setVal118(e.IsStaticLocal());
  b.setVal119(e.IsThisDeclarationADemotedDefinition());
  b.setVal120(e.IsUsableInConstantExpressions());
  b.setVal121(e.MightBeUsableInConstantExpressions());
  b.setVal122(static_cast<unsigned char>(mx::FromPasta(e.NeedsDestruction())));
}

void SerializeParmVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto v123 = e.DefaultArgument();
  if (v123) {
    auto id123 = es.EntityId(v123.value());
    b.setVal123(id123);
  } else {
    b.setVal123(mx::kInvalidEntityId);
  }
  if (auto r124 = e.DefaultArgumentRange(); auto rs124 = r124.Size()) {
    b.setVal124(es.EntityId(r124[0]));
    b.setVal125(es.EntityId(r124[rs124 - 1u]));
  } else {
    b.setVal124(0);
    b.setVal125(0);
  }
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal127(es.EntityId(e.OriginalType()));
  auto v128 = e.UninstantiatedDefaultArgument();
  if (v128) {
    auto id128 = es.EntityId(v128.value());
    b.setVal128(id128);
  } else {
    b.setVal128(mx::kInvalidEntityId);
  }
  b.setVal129(e.HasDefaultArgument());
  b.setVal130(e.HasInheritedDefaultArgument());
  b.setVal131(e.HasUninstantiatedDefaultArgument());
  b.setVal132(e.HasUnparsedDefaultArgument());
  b.setVal133(e.IsDestroyedInCallee());
  b.setVal134(e.IsKNRPromoted());
  b.setVal135(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
}

void SerializeImplicitParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e) {
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

void SerializeVarTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e);
  auto t123 = e.ExternToken();
  b.setVal123(es.EntityId(t123));
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v136 = e.TemplateArguments();
    auto sv136 = b.initVal136(static_cast<unsigned>(v136.size()));
    auto i136 = 0u;
    for (const auto &e136 : v136) {
      sv136.set(i136, es.PseudoId(e136));
      ++i136;
    }
  } while (false);
  do {
    auto v137 = e.TemplateInstantiationArguments();
    auto sv137 = b.initVal137(static_cast<unsigned>(v137.size()));
    auto i137 = 0u;
    for (const auto &e137 : v137) {
      sv137.set(i137, es.PseudoId(e137));
      ++i137;
    }
  } while (false);
  auto t124 = e.TemplateKeywordToken();
  b.setVal124(es.EntityId(t124));
  b.setVal125(es.EntityId(e.TypeAsWritten()));
  b.setVal129(e.IsClassScopeExplicitSpecialization());
  b.setVal130(e.IsExplicitInstantiationOrSpecialization());
  b.setVal131(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeNonTypeTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal70(e.DefaultArgumentWasInherited());
  auto v72 = e.DefaultArgument();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto t75 = e.DefaultArgumentToken();
  b.setVal75(es.EntityId(t75));
  auto v138 = e.NumExpansionTypes();
  if (v138) {
    b.setVal138(static_cast<unsigned>(v138.value()));
    b.setVal71(true);
  } else {
    b.setVal71(false);
  }
  auto v76 = e.PlaceholderTypeConstraint();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal87(e.HasDefaultArgument());
  b.setVal88(e.HasPlaceholderTypeConstraint());
  b.setVal89(e.IsExpandedParameterPack());
  b.setVal90(e.IsPackExpansion());
  do {
    auto v46 = e.ExpansionTypes();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
}

void SerializeMSPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal70(e.HasGetter());
  b.setVal71(e.HasSetter());
}

void SerializeFunctionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  b.setVal70(e.UsesFPIntrin());
  auto v71 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v71) {
    b.setVal71(static_cast<bool>(v71.value()));
    b.setVal87(true);
  } else {
    b.setVal87(false);
  }
  b.setVal88(e.DoesThisDeclarationHaveABody());
  b.setVal72(es.EntityId(e.CallResultType()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal75(es.EntityId(e.DeclaredReturnType()));
  auto t76 = e.EllipsisToken();
  b.setVal76(es.EntityId(t76));
  if (auto r77 = e.ExceptionSpecSourceRange(); auto rs77 = r77.Size()) {
    b.setVal77(es.EntityId(r77[0]));
    b.setVal79(es.EntityId(r77[rs77 - 1u]));
  } else {
    b.setVal77(0);
    b.setVal79(0);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v84 = e.InstantiatedFromDeclaration();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v123 = e.InstantiatedFromMemberFunction();
  if (v123) {
    auto id123 = es.EntityId(v123.value());
    b.setVal123(id123);
  } else {
    b.setVal123(mx::kInvalidEntityId);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v138 = e.ODRHash();
  if (v138) {
    b.setVal138(static_cast<unsigned>(v138.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r124 = e.ParametersSourceRange(); auto rs124 = r124.Size()) {
    b.setVal124(es.EntityId(r124[0]));
    b.setVal125(es.EntityId(r124[rs124 - 1u]));
  } else {
    b.setVal124(0);
    b.setVal125(0);
  }
  auto t127 = e.PointOfInstantiation();
  b.setVal127(es.EntityId(t127));
  b.setVal128(es.EntityId(e.ReturnType()));
  if (auto r139 = e.ReturnTypeSourceRange(); auto rs139 = r139.Size()) {
    b.setVal139(es.EntityId(r139[0]));
    b.setVal140(es.EntityId(r139[rs139 - 1u]));
  } else {
    b.setVal139(0);
    b.setVal140(0);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v141 = e.TemplateInstantiationPattern();
  if (v141) {
    auto id141 = es.EntityId(v141.value());
    b.setVal141(id141);
  } else {
    b.setVal141(mx::kInvalidEntityId);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal122(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal90(e.HasImplicitReturnZero());
  b.setVal91(e.HasInheritedPrototype());
  b.setVal92(e.HasOneParameterOrDefaultArguments());
  b.setVal93(e.HasPrototype());
  b.setVal94(e.HasSkippedBody());
  b.setVal95(e.HasTrivialBody());
  b.setVal96(e.HasWrittenPrototype());
  b.setVal97(e.InstantiationIsPending());
  b.setVal98(e.IsCPUDispatchMultiVersion());
  b.setVal99(e.IsCPUSpecificMultiVersion());
  b.setVal100(e.IsConsteval());
  b.setVal101(e.IsConstexpr());
  b.setVal102(e.IsConstexprSpecified());
  b.setVal103(e.IsDefaulted());
  b.setVal104(e.IsDeleted());
  b.setVal105(e.IsDeletedAsWritten());
  b.setVal106(e.IsDestroyingOperatorDelete());
  b.setVal107(e.IsExplicitlyDefaulted());
  b.setVal108(e.IsExternC());
  b.setVal109(e.IsFunctionTemplateSpecialization());
  b.setVal110(e.IsGlobal());
  b.setVal111(e.IsImplicitlyInstantiable());
  b.setVal112(e.IsInExternCContext());
  b.setVal113(e.IsInExternCXXContext());
  b.setVal114(e.IsIneligibleOrNotSelected());
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
    b.setVal129(true);
  } else {
    b.setVal129(false);
  }
  b.setVal130(e.IsMSVCRTEntryPoint());
  b.setVal131(e.IsMain());
  b.setVal132(e.IsMultiVersion());
  b.setVal133(e.IsNoReturn());
  b.setVal134(e.IsOverloadedOperator());
  b.setVal135(e.IsPure());
  b.setVal142(e.IsReplaceableGlobalAllocationFunction());
  auto v143 = e.IsReservedGlobalPlacementOperator();
  if (v143) {
    b.setVal143(static_cast<bool>(v143.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  b.setVal145(e.IsStatic());
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
    auto v46 = e.Parameters();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal155(e.UsesSEHTry());
  b.setVal156(e.WillHaveBody());
  auto v157 = e.Body();
  if (v157) {
    auto id157 = es.EntityId(v157.value());
    b.setVal157(id157);
  } else {
    b.setVal157(mx::kInvalidEntityId);
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

void SerializeCXXMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e);
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v158 = e.ThisObjectType();
  if (v158) {
    auto id158 = es.EntityId(v158.value());
    b.setVal158(id158);
  } else {
    b.setVal158(mx::kInvalidEntityId);
  }
  auto v159 = e.ThisType();
  if (v159) {
    auto id159 = es.EntityId(v159.value());
    b.setVal159(id159);
  } else {
    b.setVal159(mx::kInvalidEntityId);
  }
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

void SerializeCXXDestructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v169 = e.OperatorDelete();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
  } else {
    b.setVal169(mx::kInvalidEntityId);
  }
  auto v170 = e.OperatorDeleteThisArgument();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  b.setVal169(es.EntityId(e.ConversionType()));
  b.setVal171(e.IsExplicit());
  b.setVal172(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e);
  auto v169 = e.TargetConstructor();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
  } else {
    b.setVal169(mx::kInvalidEntityId);
  }
  b.setVal171(e.IsDefaultConstructor());
  b.setVal172(e.IsDelegatingConstructor());
  b.setVal173(e.IsExplicit());
  b.setVal174(e.IsInheritingConstructor());
  b.setVal175(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e) {
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

void SerializeFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e);
  auto v72 = e.BitWidth();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v75 = e.CapturedVLAType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v76 = e.InClassInitializer();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal70(e.HasCapturedVLAType());
  b.setVal71(e.HasInClassInitializer());
  b.setVal87(e.IsAnonymousStructOrUnion());
  b.setVal88(e.IsBitField());
  b.setVal89(e.IsMutable());
  b.setVal90(e.IsUnnamedBitfield());
  b.setVal91(e.IsZeroLengthBitField());
  b.setVal92(e.IsZeroSize());
}

void SerializeObjCIvarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal77(es.EntityId(e.ContainingInterface()));
  b.setVal79(es.EntityId(e.NextInstanceVariable()));
  b.setVal93(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e);
}

void SerializeBindingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
  b.setVal52(es.EntityId(e.Binding()));
  b.setVal53(es.EntityId(e.DecomposedDeclaration()));
  b.setVal61(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e);
}

void SerializeOMPDeclareMapperDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e);
  b.setVal52(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc46(e);
  auto v46 = dc46.AlreadyLoadedDeclarations();
  auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
  auto i46 = 0u;
  for (const pasta::Decl &e46 : v46) {
    sv46.set(i46, es.EntityId(e46));
    ++i46;
  }
}

void SerializeUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.Introducer()));
  auto v52 = e.NextUsingShadowDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  b.setVal53(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e);
  b.setVal69(e.ConstructsVirtualBase());
  b.setVal61(es.EntityId(e.ConstructedBaseClass()));
  auto v62 = e.ConstructedBaseClassShadowDeclaration();
  if (v62) {
    auto id62 = es.EntityId(v62.value());
    b.setVal62(id62);
  } else {
    b.setVal62(mx::kInvalidEntityId);
  }
  b.setVal63(es.EntityId(e.NominatedBaseClass()));
  auto v72 = e.NominatedBaseClassShadowDeclaration();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e) {
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
  b.setVal51(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e) {
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

void SerializeUnresolvedUsingIfExistsDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
}

void SerializeTypeDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  auto v51 = e.TypeForDeclaration();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  b.setVal69(e.DefaultArgumentWasInherited());
  auto v52 = e.DefaultArgument();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  auto v53 = e.DefaultArgumentInfo();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
  auto t61 = e.DefaultArgumentToken();
  b.setVal61(es.EntityId(t61));
  b.setVal70(e.HasDefaultArgument());
  b.setVal71(e.HasTypeConstraint());
  b.setVal87(e.IsExpandedParameterPack());
  b.setVal88(e.IsPackExpansion());
  b.setVal89(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e) {
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
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v63 = e.TypedefNameForAnonymousDeclaration();
  if (v63) {
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  b.setVal69(e.HasNameForLinkage());
  b.setVal70(e.IsBeingDefined());
  b.setVal71(e.IsClass());
  b.setVal87(e.IsCompleteDefinition());
  b.setVal88(e.IsCompleteDefinitionRequired());
  b.setVal89(e.IsDependentType());
  b.setVal90(e.IsEmbeddedInDeclarator());
  b.setVal91(e.IsEnum());
  b.setVal92(e.IsFreeStanding());
  b.setVal93(e.IsInterface());
  b.setVal94(e.IsStruct());
  b.setVal95(e.IsThisDeclarationADemotedDefinition());
  b.setVal96(e.IsUnion());
  b.setVal97(e.MayHaveOutOfDateDefinition());
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

void SerializeRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e);
  b.setVal98(e.CanPassInRegisters());
  do {
    auto v47 = e.Fields();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
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
  b.setVal116(e.IsRandomized());
  b.setVal117(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e) {
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
    auto ov136 = e.Bases();
    if (!ov136) {
      b.setVal120(false);
      break;
    }
    b.setVal120(true);
    auto v136 = std::move(*ov136);
    auto sv136 = b.initVal136(static_cast<unsigned>(v136.size()));
    auto i136 = 0u;
    for (const auto &e136 : v136) {
      sv136.set(i136, es.PseudoId(e136));
      ++i136;
    }
  } while (false);
  auto v80 = e.CalculateInheritanceModel();
  if (v80) {
    b.setVal80(static_cast<unsigned char>(v80.value()));
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
      b.setVal129(false);
      break;
    }
    b.setVal129(true);
    auto v168 = std::move(*ov168);
    auto sv168 = b.initVal168(static_cast<unsigned>(v168.size()));
    auto i168 = 0u;
    for (const auto &e168 : v168) {
      sv168.set(i168, es.EntityId(e168));
      ++i168;
    }
  } while (false);
  auto v72 = e.Destructor();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v138 = e.GenericLambdaTemplateParameterList();
  if (v138) {
    b.setVal138(es.PseudoId(v138.value()));
    b.setVal130(true);
  } else {
    b.setVal130(false);
  }
  auto v75 = e.InstantiatedFromMemberClass();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  auto v76 = e.LambdaCallOperator();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v81 = e.LambdaCaptureDefault();
  if (v81) {
    b.setVal81(static_cast<unsigned char>(v81.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  auto v77 = e.LambdaContextDeclaration();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  do {
    auto ov176 = e.LambdaExplicitTemplateParameters();
    if (!ov176) {
      b.setVal132(false);
      break;
    }
    b.setVal132(true);
    auto v176 = std::move(*ov176);
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  auto v177 = e.LambdaManglingNumber();
  if (v177) {
    b.setVal177(static_cast<unsigned>(v177.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  auto v79 = e.LambdaType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v82 = e.MSInheritanceModel();
  if (v82) {
    b.setVal82(static_cast<unsigned char>(v82.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v178 = e.NumBases();
  if (v178) {
    b.setVal178(static_cast<unsigned>(v178.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  auto v179 = e.NumVirtualBases();
  if (v179) {
    b.setVal179(static_cast<unsigned>(v179.value()));
    b.setVal142(true);
  } else {
    b.setVal142(false);
  }
  auto v180 = e.ODRHash();
  if (v180) {
    b.setVal180(static_cast<unsigned>(v180.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v84 = e.TemplateInstantiationPattern();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v144 = e.HasAnyDependentBases();
  if (v144) {
    b.setVal144(static_cast<bool>(v144.value()));
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  auto v146 = e.HasConstexprDefaultConstructor();
  if (v146) {
    b.setVal146(static_cast<bool>(v146.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v148 = e.HasConstexprDestructor();
  if (v148) {
    b.setVal148(static_cast<bool>(v148.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v150 = e.HasConstexprNonCopyMoveConstructor();
  if (v150) {
    b.setVal150(static_cast<bool>(v150.value()));
    b.setVal151(true);
  } else {
    b.setVal151(false);
  }
  auto v152 = e.HasCopyAssignmentWithConstParameter();
  if (v152) {
    b.setVal152(static_cast<bool>(v152.value()));
    b.setVal153(true);
  } else {
    b.setVal153(false);
  }
  auto v154 = e.HasCopyConstructorWithConstParameter();
  if (v154) {
    b.setVal154(static_cast<bool>(v154.value()));
    b.setVal155(true);
  } else {
    b.setVal155(false);
  }
  auto v156 = e.HasDefaultConstructor();
  if (v156) {
    b.setVal156(static_cast<bool>(v156.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v161 = e.HasDefinition();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v163 = e.HasDirectFields();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasFriends();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasInClassInitializer();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal171(true);
  } else {
    b.setVal171(false);
  }
  auto v172 = e.HasInheritedAssignment();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasInheritedConstructor();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v181 = e.HasInitializerMethod();
  if (v181) {
    b.setVal181(static_cast<bool>(v181.value()));
    b.setVal182(true);
  } else {
    b.setVal182(false);
  }
  auto v183 = e.HasIrrelevantDestructor();
  if (v183) {
    b.setVal183(static_cast<bool>(v183.value()));
    b.setVal184(true);
  } else {
    b.setVal184(false);
  }
  auto v185 = e.HasKnownLambdaInternalLinkage();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v187 = e.HasMoveAssignment();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasMoveConstructor();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal190(true);
  } else {
    b.setVal190(false);
  }
  auto v191 = e.HasMutableFields();
  if (v191) {
    b.setVal191(static_cast<bool>(v191.value()));
    b.setVal192(true);
  } else {
    b.setVal192(false);
  }
  auto v193 = e.HasNonLiteralTypeFieldsOrBases();
  if (v193) {
    b.setVal193(static_cast<bool>(v193.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasNonTrivialCopyAssignment();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasNonTrivialCopyConstructor();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasNonTrivialCopyConstructorForCall();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasNonTrivialDefaultConstructor();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasNonTrivialDestructor();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonTrivialDestructorForCall();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialMoveAssignment();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialMoveConstructor();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialMoveConstructorForCall();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasPrivateFields();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasProtectedFields();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasSimpleCopyAssignment();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasSimpleCopyConstructor();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasSimpleDestructor();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasSimpleMoveAssignment();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasSimpleMoveConstructor();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasTrivialCopyAssignment();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasTrivialCopyConstructor();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasTrivialCopyConstructorForCall();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasTrivialDefaultConstructor();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasTrivialDestructor();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasTrivialDestructorForCall();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialMoveAssignment();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialMoveConstructor();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialMoveConstructorForCall();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasUninitializedReferenceMember();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasUserDeclaredConstructor();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasUserDeclaredCopyAssignment();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasUserDeclaredCopyConstructor();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasUserDeclaredDestructor();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasUserDeclaredMoveAssignment();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUserDeclaredMoveConstructor();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredMoveOperation();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserProvidedDefaultConstructor();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasVariantMembers();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.ImplicitCopyConstructorHasConstParameter();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.IsAbstract();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.IsAggregate();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.IsAnyDestructorNoReturn();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.IsCLike();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.IsCXX11StandardLayout();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  b.setVal279(e.IsDependentLambda());
  auto v280 = e.IsDynamicClass();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  auto v282 = e.IsEffectivelyFinal();
  if (v282) {
    b.setVal282(static_cast<bool>(v282.value()));
    b.setVal283(true);
  } else {
    b.setVal283(false);
  }
  auto v284 = e.IsEmpty();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  b.setVal286(e.IsGenericLambda());
  auto v287 = e.IsInterfaceLike();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  auto v289 = e.IsLiteral();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  auto v123 = e.IsLocalClass();
  if (v123) {
    auto id123 = es.EntityId(v123.value());
    b.setVal123(id123);
  } else {
    b.setVal123(mx::kInvalidEntityId);
  }
  b.setVal291(e.IsNeverDependentLambda());
  auto v292 = e.IsPOD();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v294 = e.IsPolymorphic();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  auto v296 = e.IsStandardLayout();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  auto v298 = e.IsStructural();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v300 = e.IsTrivial();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsTriviallyCopyable();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.MayBeAbstract();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.MayBeDynamicClass();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.MayBeNonDynamicClass();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  do {
    auto ov312 = e.Methods();
    if (!ov312) {
      b.setVal313(false);
      break;
    }
    b.setVal313(true);
    auto v312 = std::move(*ov312);
    auto sv312 = b.initVal312(static_cast<unsigned>(v312.size()));
    auto i312 = 0u;
    for (const auto &e312 : v312) {
      sv312.set(i312, es.EntityId(e312));
      ++i312;
    }
  } while (false);
  auto v314 = e.NeedsImplicitCopyAssignment();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.NeedsImplicitCopyConstructor();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.NeedsImplicitDefaultConstructor();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.NeedsImplicitDestructor();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.NeedsImplicitMoveAssignment();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.NeedsImplicitMoveConstructor();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsOverloadResolutionForDestructor();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NullFieldOffsetIsZero();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  do {
    auto ov137 = e.VirtualBases();
    if (!ov137) {
      b.setVal338(false);
      break;
    }
    b.setVal338(true);
    auto v137 = std::move(*ov137);
    auto sv137 = b.initVal137(static_cast<unsigned>(v137.size()));
    auto i137 = 0u;
    for (const auto &e137 : v137) {
      sv137.set(i137, es.PseudoId(e137));
      ++i137;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e);
  auto t124 = e.ExternToken();
  b.setVal124(es.EntityId(t124));
  auto t125 = e.PointOfInstantiation();
  b.setVal125(es.EntityId(t125));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  do {
    auto v339 = e.TemplateArguments();
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.PseudoId(e339));
      ++i339;
    }
  } while (false);
  do {
    auto v340 = e.TemplateInstantiationArguments();
    auto sv340 = b.initVal340(static_cast<unsigned>(v340.size()));
    auto i340 = 0u;
    for (const auto &e340 : v340) {
      sv340.set(i340, es.PseudoId(e340));
      ++i340;
    }
  } while (false);
  auto t127 = e.TemplateKeywordToken();
  b.setVal127(es.EntityId(t127));
  auto v128 = e.TypeAsWritten();
  if (v128) {
    auto id128 = es.EntityId(v128.value());
    b.setVal128(id128);
  } else {
    b.setVal128(mx::kInvalidEntityId);
  }
  b.setVal341(e.IsClassScopeExplicitSpecialization());
  b.setVal342(e.IsExplicitInstantiationOrSpecialization());
  b.setVal343(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e) {
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
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v75 = e.IntegerType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  if (auto r76 = e.IntegerTypeRange(); auto rs76 = r76.Size()) {
    b.setVal76(es.EntityId(r76[0]));
    b.setVal77(es.EntityId(r76[rs76 - 1u]));
  } else {
    b.setVal76(0);
    b.setVal77(0);
  }
  auto v138 = e.ODRHash();
  if (v138) {
    b.setVal138(static_cast<unsigned>(v138.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  auto v79 = e.PromotionType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v84 = e.TemplateInstantiationPattern();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal99(e.IsClosed());
  b.setVal100(e.IsClosedFlag());
  b.setVal101(e.IsClosedNonFlag());
  b.setVal102(e.IsComplete());
  b.setVal103(e.IsFixed());
  b.setVal104(e.IsScoped());
  b.setVal105(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e) {
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

void SerializeTypedefNameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e);
  auto v52 = e.AnonymousDeclarationWithTypedefName();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  b.setVal53(es.EntityId(e.UnderlyingType()));
  b.setVal69(e.IsModed());
  b.setVal70(e.IsTransparentTag());
}

void SerializeTypedefDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
}

void SerializeTypeAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto v61 = e.DescribedAliasTemplate();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e);
  auto t61 = e.ColonToken();
  b.setVal61(es.EntityId(t61));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t62 = e.VarianceToken();
  b.setVal62(es.EntityId(t62));
  b.setVal71(e.HasExplicitBound());
}

void SerializeTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeRedeclarableTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFunctionTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeClassTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeVarTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTypeAliasTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e);
  auto v51 = e.InstantiatedFromMemberTemplate();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
  b.setVal52(es.EntityId(e.TemplatedDeclaration()));
}

void SerializeConceptDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e);
  b.setVal51(es.EntityId(e.ConstraintExpression()));
  b.setVal69(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTemplateTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeObjCPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e) {
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
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal62(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal63(es.EntityId(e.SetterMethodDeclaration()));
  auto t72 = e.SetterNameToken();
  b.setVal72(es.EntityId(t72));
  b.setVal75(es.EntityId(e.Type()));
  b.setVal69(e.IsAtomic());
  b.setVal70(e.IsClassProperty());
  b.setVal71(e.IsDirectProperty());
  b.setVal87(e.IsInstanceProperty());
  b.setVal88(e.IsOptional());
  b.setVal89(e.IsReadOnly());
  b.setVal90(e.IsRetaining());
}

void SerializeObjCMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal69(e.DefinedInNSObject());
  b.setVal51(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal52(es.EntityId(e.ClassInterface()));
  b.setVal53(es.EntityId(e.CommandDeclaration()));
  auto t61 = e.DeclaratorEndToken();
  b.setVal61(es.EntityId(t61));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal62(es.EntityId(e.ReturnType()));
  if (auto r63 = e.ReturnTypeSourceRange(); auto rs63 = r63.Size()) {
    b.setVal63(es.EntityId(r63[0]));
    b.setVal72(es.EntityId(r63[rs63 - 1u]));
  } else {
    b.setVal63(0);
    b.setVal72(0);
  }
  auto t75 = e.SelectorStartToken();
  b.setVal75(es.EntityId(t75));
  b.setVal76(es.EntityId(e.SelfDeclaration()));
  b.setVal70(e.HasParameterDestroyedInCallee());
  b.setVal71(e.HasRedeclaration());
  b.setVal87(e.HasRelatedResultType());
  b.setVal88(e.HasSkippedBody());
  b.setVal89(e.IsClassMethod());
  b.setVal90(e.IsDefined());
  b.setVal91(e.IsDesignatedInitializerForTheInterface());
  b.setVal92(e.IsDirectMethod());
  b.setVal93(e.IsInstanceMethod());
  b.setVal94(e.IsOptional());
  b.setVal95(e.IsOverriding());
  b.setVal96(e.IsPropertyAccessor());
  b.setVal97(e.IsRedeclaration());
  b.setVal98(e.IsSynthesizedAccessorStub());
  b.setVal99(e.IsThisDeclarationADesignatedInitializer());
  b.setVal100(e.IsVariadic());
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
  pasta::DeclContext dc57(e);
  auto v57 = dc57.AlreadyLoadedDeclarations();
  auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
  auto i57 = 0u;
  for (const pasta::Decl &e57 : v57) {
    sv57.set(i57, es.EntityId(e57));
    ++i57;
  }
}

void SerializeObjCContainerDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e) {
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
    auto v176 = e.Methods();
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  do {
    auto v312 = e.Properties();
    auto sv312 = b.initVal312(static_cast<unsigned>(v312.size()));
    auto i312 = 0u;
    for (const auto &e312 : v312) {
      sv312.set(i312, es.EntityId(e312));
      ++i312;
    }
  } while (false);
  pasta::DeclContext dc344(e);
  auto v344 = dc344.AlreadyLoadedDeclarations();
  auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
  auto i344 = 0u;
  for (const pasta::Decl &e344 : v344) {
    sv344.set(i344, es.EntityId(e344));
    ++i344;
  }
}

void SerializeObjCCategoryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal69(e.IsClassExtension());
  auto t61 = e.CategoryNameToken();
  b.setVal61(es.EntityId(t61));
  b.setVal62(es.EntityId(e.ClassInterface()));
  b.setVal63(es.EntityId(e.Implementation()));
  auto t72 = e.InstanceVariableLBraceToken();
  b.setVal72(es.EntityId(t72));
  auto t75 = e.InstanceVariableRBraceToken();
  b.setVal75(es.EntityId(t75));
  b.setVal76(es.EntityId(e.NextClassCategory()));
  do {
    auto v345 = e.InstanceVariables();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
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

void SerializeObjCProtocolDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e) {
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
    auto v345 = e.ProtocolTokens();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
  do {
    auto v346 = e.Protocols();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  do {
    auto v345 = e.AllReferencedProtocols();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
  b.setVal69(e.DeclaresOrInheritsDesignatedInitializers());
  auto t61 = e.EndOfDefinitionToken();
  b.setVal61(es.EntityId(t61));
  b.setVal62(es.EntityId(e.Implementation()));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto v63 = e.SuperClass();
  if (v63) {
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  auto t72 = e.SuperClassToken();
  b.setVal72(es.EntityId(t72));
  auto v75 = e.SuperClassTypeInfo();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal76(es.EntityId(e.TypeForDeclaration()));
  b.setVal70(e.HasDefinition());
  b.setVal71(e.HasDesignatedInitializers());
  b.setVal87(e.IsArcWeakrefUnavailable());
  b.setVal88(e.IsImplicitInterfaceDeclaration());
  b.setVal77(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
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
    auto v347 = e.KnownCategories();
    auto sv347 = b.initVal347(static_cast<unsigned>(v347.size()));
    auto i347 = 0u;
    for (const auto &e347 : v347) {
      sv347.set(i347, es.EntityId(e347));
      ++i347;
    }
  } while (false);
  do {
    auto v348 = e.KnownExtensions();
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
  do {
    auto v351 = e.VisibleCategories();
    auto sv351 = b.initVal351(static_cast<unsigned>(v351.size()));
    auto i351 = 0u;
    for (const auto &e351 : v351) {
      sv351.set(i351, es.EntityId(e351));
      ++i351;
    }
  } while (false);
  do {
    auto v352 = e.VisibleExtensions();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
}

void SerializeObjCImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e);
  b.setVal61(es.EntityId(e.ClassInterface()));
  do {
    auto v345 = e.PropertyImplementations();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  b.setVal62(es.EntityId(e.CategoryDeclaration()));
  auto t63 = e.CategoryNameToken();
  b.setVal63(es.EntityId(t63));
}

void SerializeObjCImplementationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e);
  auto t62 = e.InstanceVariableLBraceToken();
  b.setVal62(es.EntityId(t62));
  auto t63 = e.InstanceVariableRBraceToken();
  b.setVal63(es.EntityId(t63));
  auto v68 = e.ObjCRuntimeNameAsString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  b.setVal72(es.EntityId(e.SuperClass()));
  auto t75 = e.SuperClassToken();
  b.setVal75(es.EntityId(t75));
  b.setVal69(e.HasDestructors());
  b.setVal70(e.HasNonZeroConstructors());
  do {
    auto v346 = e.InstanceVariables();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e);
  b.setVal51(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e) {
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

void SerializeNamespaceAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e) {
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

void SerializeLinkageSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e) {
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

void SerializeLifetimeExtendedTemporaryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  do {
    auto v46 = e.Children();
    auto sv46 = b.initVal46(static_cast<unsigned>(v46.size()));
    auto i46 = 0u;
    for (const auto &e46 : v46) {
      sv46.set(i46, es.EntityId(e46));
      ++i46;
    }
  } while (false);
  b.setVal44(es.EntityId(e.ExtendingDeclaration()));
  b.setVal60(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal51(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e) {
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

void SerializeFriendTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e) {
  (void) es;
  (void) b;
  (void) e;
}

void SerializeFriendDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto v44 = e.FriendDeclaration();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto t51 = e.FriendToken();
  b.setVal51(es.EntityId(t51));
  auto v52 = e.FriendType();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  b.setVal45(e.IsUnsupportedFriend());
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

void SerializeFileScopeAsmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.AssemblyToken();
  b.setVal44(es.EntityId(t44));
  b.setVal51(es.EntityId(e.AssemblyString()));
  auto t52 = e.RParenToken();
  b.setVal52(es.EntityId(t52));
}

void SerializeExternCContextDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e) {
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

void SerializeExportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
  auto t44 = e.ExportToken();
  b.setVal44(es.EntityId(t44));
  auto t51 = e.RBraceToken();
  b.setVal51(es.EntityId(t51));
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

void SerializeEmptyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e);
}

}  // namespace indexer
