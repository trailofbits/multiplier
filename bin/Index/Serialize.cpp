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
#include "Entity.h"
#include "EntityMapper.h"
#include "PASTA.h"
#include "TokenTree.h"
#include "Util.h"
namespace indexer {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

void SerializeDesignator(const EntityMapper &es, mx::ast::Designator::Builder b, const pasta::Designator &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(e.IsFieldDesignator());
  b.setVal1(e.IsArrayDesignator());
  b.setVal2(e.IsArrayRangeDesignator());
  auto v3 = e.Field();
  if (v3) {
    auto id3 = es.EntityId(v3.value());
    b.setVal3(id3);
  } else {
    b.setVal3(mx::kInvalidEntityId);
  }
  if (auto r4 = e.Tokens(); auto rs4 = r4.Size()) {
    b.setVal4(es.EntityId(r4[0]));
    b.setVal5(es.EntityId(r4[rs4 - 1u]));
  } else {
    b.setVal4(0);
    b.setVal5(0);
  }
  auto t6 = e.DotToken();
  b.setVal6(es.EntityId(t6));
  auto t7 = e.FieldToken();
  b.setVal7(es.EntityId(t7));
  auto t8 = e.LeftBracketToken();
  b.setVal8(es.EntityId(t8));
  auto t9 = e.RightBracketToken();
  b.setVal9(es.EntityId(t9));
  auto t10 = e.EllipsisToken();
  b.setVal10(es.EntityId(t10));
  auto v11 = e.FirstExpressionIndex();
  if (v11) {
    b.setVal11(static_cast<unsigned>(v11.value()));
    b.setVal12(true);
  } else {
    b.setVal12(false);
  }
}

void SerializeCXXBaseSpecifier(const EntityMapper &es, mx::ast::CXXBaseSpecifier::Builder b, const pasta::CXXBaseSpecifier &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  if (auto r0 = e.Tokens(); auto rs0 = r0.Size()) {
    b.setVal0(es.EntityId(r0[0]));
    b.setVal1(es.EntityId(r0[rs0 - 1u]));
  } else {
    b.setVal0(0);
    b.setVal1(0);
  }
  auto t2 = e.BaseTypeToken();
  b.setVal2(es.EntityId(t2));
  b.setVal3(e.IsVirtual());
  b.setVal4(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal5(e.IsPackExpansion());
  b.setVal6(e.ConstructorsAreInherited());
  auto v7 = e.EllipsisToken();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  b.setVal8(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal9(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal10(es.EntityId(e.BaseType()));
}

void SerializeTemplateParameterList(const EntityMapper &es, mx::ast::TemplateParameterList::Builder b, const pasta::TemplateParameterList &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(e.Depth());
  b.setVal1(e.HasUnexpandedParameterPack());
  b.setVal2(e.HasParameterPack());
  auto v3 = e.RequiresClause();
  if (v3) {
    auto id3 = es.EntityId(v3.value());
    b.setVal3(id3);
  } else {
    b.setVal3(mx::kInvalidEntityId);
  }
  auto t4 = e.TemplateKeywordToken();
  b.setVal4(es.EntityId(t4));
  auto t5 = e.LeftAngleToken();
  b.setVal5(es.EntityId(t5));
  auto t6 = e.RightAngleToken();
  b.setVal6(es.EntityId(t6));
  if (auto r7 = e.Tokens(); auto rs7 = r7.Size()) {
    b.setVal7(es.EntityId(r7[0]));
    b.setVal8(es.EntityId(r7[rs7 - 1u]));
  } else {
    b.setVal7(0);
    b.setVal8(0);
  }
  do {
    auto v9 = e.Parameters();
    auto sv9 = b.initVal9(static_cast<unsigned>(v9.size()));
    auto i9 = 0u;
    for (const auto &e9 : v9) {
      sv9.set(i9, es.EntityId(e9));
      ++i9;
    }
  } while (false);
}

void SerializeTemplateArgument(const EntityMapper &es, mx::ast::TemplateArgument::Builder b, const pasta::TemplateArgument &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal1(e.IsNull());
  b.setVal2(e.IsDependent());
  b.setVal3(e.IsInstantiationDependent());
  b.setVal4(e.ContainsUnexpandedParameterPack());
  b.setVal5(e.IsPackExpansion());
  auto v6 = e.AsDeclaration();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  auto v7 = e.AsType();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  auto v8 = e.ParameterTypeForDeclaration();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.NullPointerType();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
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
  std::optional<const void *> v1;
  if (tt) {
    auto x1 = tt->Parent();
    if (x1) {
      v1 = x1->RawNode();
    }
  } else {
    auto x1 = e.Parent();
    if (x1) {
      v1 = x1->RawMacro();
    }
  }
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
  SerializeMacro(es, b, e, tt);
}

void SerializeMacroVAOpt(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOpt &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  b.setVal3(e.ContentsAreElided());
}

void SerializeMacroSubstitution(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroSubstitution &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  if (tt) {
    auto v4 = tt->ReplacementChildren();
    auto sv4 = b.initVal4(static_cast<unsigned>(v4.size()));
    auto i4 = 0u;
    for (auto n4 : v4) {
      sv4.set(i4, es.EntityId(n4.RawNode()));
      ++i4;
    }
  } else {
    auto v4 = e.ReplacementChildren();
    auto sv4 = b.initVal4(static_cast<unsigned>(v4.size()));
    auto i4 = 0u;
    for (const auto &e4 : v4) {
      sv4.set(i4, es.EntityId(e4));
      ++i4;
    }
  }
  std::optional<pasta::Token> v5;
  if (tt) {
    v5 = tt->FirstFullySubstitutedToken();
  } else {
    v5 = e.FirstFullySubstitutedToken();
  }
  if (v5) {
    auto id5 = es.EntityId(v5.value());
    b.setVal5(id5);
  } else {
    b.setVal5(mx::kInvalidEntityId);
  }
  std::optional<pasta::Token> v6;
  if (tt) {
    v6 = tt->LastFullySubstitutedToken();
  } else {
    v6 = e.LastFullySubstitutedToken();
  }
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  std::optional<pasta::MacroToken> v7;
  if (tt) {
    v7 = tt->NameOrOperator();
  } else {
    v7 = e.NameOrOperator();
  }
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
}

void SerializeMacroConcatenate(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroConcatenate &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  auto t8 = e.PastedToken();
  b.setVal8(es.EntityId(t8));
}

void SerializeMacroStringify(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroStringify &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  auto t8 = e.StringifiedToken();
  b.setVal8(es.EntityId(t8));
}

void SerializeMacroExpansion(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroExpansion &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  if (tt) {
    auto v9 = tt->IntermediateChildren();
    auto sv9 = b.initVal9(static_cast<unsigned>(v9.size()));
    auto i9 = 0u;
    for (auto n9 : v9) {
      sv9.set(i9, es.EntityId(n9.RawNode()));
      ++i9;
    }
  } else {
    auto v9 = e.IntermediateChildren();
    auto sv9 = b.initVal9(static_cast<unsigned>(v9.size()));
    auto i9 = 0u;
    for (const auto &e9 : v9) {
      sv9.set(i9, es.EntityId(e9));
      ++i9;
    }
  }
  auto v8 = e.Definition();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  do {
    auto v10 = e.Arguments();
    auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
    auto i10 = 0u;
    for (const auto &e10 : v10) {
      sv10.set(i10, es.EntityId(e10));
      ++i10;
    }
  } while (false);
}

void SerializeMacroParameterSubstitution(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameterSubstitution &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  b.setVal8(es.EntityId(e.Parameter()));
  auto t11 = e.ParameterUse();
  b.setVal11(es.EntityId(t11));
}

void SerializeMacroArgument(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  b.setVal3(e.IsVariadic());
  b.setVal12(e.Index());
}

void SerializeMacroParameter(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameter &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  auto v5 = e.VariadicDots();
  if (v5) {
    auto id5 = es.EntityId(v5.value());
    b.setVal5(id5);
  } else {
    b.setVal5(mx::kInvalidEntityId);
  }
  auto v6 = e.Name();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  b.setVal12(e.Index());
}

void SerializeMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  auto t5 = e.Hash();
  b.setVal5(es.EntityId(t5));
  auto v6 = e.DirectiveName();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
}

void SerializeDefineMacroDirective(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::DefineMacroDirective &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(es, b, e, tt);
  auto v7 = e.Name();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  if (true) {
    auto v4 = e.Body();
    auto sv4 = b.initVal4(static_cast<unsigned>(v4.size()));
    auto i4 = 0u;
    for (const auto &e4 : v4) {
      sv4.set(i4, es.EntityId(e4));
      ++i4;
    }
  }
  b.setVal3(e.IsVariadic());
  b.setVal13(e.IsFunctionLike());
  if (true) {
    auto v9 = e.Parameters();
    auto sv9 = b.initVal9(static_cast<unsigned>(v9.size()));
    auto i9 = 0u;
    for (const auto &e9 : v9) {
      sv9.set(i9, es.EntityId(e9));
      ++i9;
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
  auto v7 = e.IncludedFile();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
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

void SerializeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Attr &e, const TokenTree *) {
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

void SerializeAlignValueAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignValueAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
}

void SerializeAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AliasAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAbiTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AbiTagAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeSPtrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SPtrAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializePtr64Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr64Attr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializePtr32Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr32Attr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeOpenCLPrivateAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLPrivateAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLLocalAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLLocalAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLGlobalHostAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalHostAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeOpenCLGlobalDeviceAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalDeviceAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeOpenCLGlobalAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLGenericAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGenericAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLConstantAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLConstantAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeObjCKindOfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCKindOfAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeObjCInertUnsafeUnretainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCInertUnsafeUnretainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeObjCGCAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCGCAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeNoDerefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDerefAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeHLSLGroupSharedAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLGroupSharedAddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeCmseNSCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeBTFTypeTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFTypeTagAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  auto v9 = e.BTFTypeTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArmMveStrictPolymorphismAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmMveStrictPolymorphismAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeAnnotateTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateTypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAddressSpaceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AddressSpaceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeUPtrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UPtrAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeTypeNullableResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableResultAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeTypeNullableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeTypeNullUnspecifiedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullUnspecifiedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeTypeNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNonNullAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(es, b, e, nullptr);
}

void SerializeThreadAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThreadAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeSwiftObjCMembersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftObjCMembersAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeStmtAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StmtAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeOpenCLUnrollHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLUnrollHintAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeMustTailAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MustTailAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeLikelyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LikelyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeFallThroughAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FallThroughAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeUnlikelyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnlikelyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeSuppressAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SuppressAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(es, b, e, nullptr);
}

void SerializeRenderScriptKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RenderScriptKernelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeOverloadableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverloadableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeOpenCLAccessAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLAccessAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal11(e.IsReadOnly());
  b.setVal12(e.IsReadWrite());
  b.setVal13(e.IsWriteOnly());
}

void SerializeObjCRuntimeVisibleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeVisibleAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCRuntimeNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  auto v9 = e.MetadataName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNonRuntimeProtocolAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonRuntimeProtocolAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCNonLazyClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonLazyClassAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCDirectMembersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectMembersAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCDirectAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCDesignatedInitializerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDesignatedInitializerAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCClassStubAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCClassStubAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeObjCBoxableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBoxableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeOMPReferencedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPReferencedVarAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Reference()));
}

void SerializeOMPDeclareSimdDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareSimdDeclAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.BranchState())));
  b.setVal8(es.EntityId(e.Simdlen()));
}

void SerializeOMPCaptureKindAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureKindAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeNoEscapeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoEscapeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeNoBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoBuiltinAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeModeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ModeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeLoopHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoopHintAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Option())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.State())));
  auto v8 = e.Value();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
}

void SerializeLoaderUninitializedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoaderUninitializedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeInitSegAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitSegAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  auto v9 = e.Section();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInheritableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal11(e.ShouldInheritEvenIfAlreadyPresent());
}

void SerializeIBOutletCollectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletCollectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Interface()));
  b.setVal16(es.EntityId(e.InterfaceToken()));
}

void SerializeIBOutletAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeIBActionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBActionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeHotAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HotAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeHLSLShaderAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLShaderAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeHLSLResourceBindingAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceBindingAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Slot();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Space();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
}

void SerializeHLSLResourceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ResourceShape())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.ResourceType())));
}

void SerializeHLSLNumThreadsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLNumThreadsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeHLSLAnnotationAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLAnnotationAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeHLSLSV_GroupIndexAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_GroupIndexAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeHLSLAnnotationAttr(es, b, e, nullptr);
}

void SerializeHLSLSV_DispatchThreadIDAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_DispatchThreadIDAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeHLSLAnnotationAttr(es, b, e, nullptr);
}

void SerializeHIPManagedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HIPManagedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeGuardedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedVarAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeGuardedByAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedByAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializeGNUInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GNUInlineAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeFunctionReturnThunksAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FunctionReturnThunksAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ThunkType())));
}

void SerializeFormatAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeFormatArgAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatArgAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeFlattenAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlattenAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeFlagEnumAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlagEnumAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeFinalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FinalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsSpelledAsSealed());
}

void SerializeFastCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FastCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeExternalSourceSymbolAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExternalSourceSymbolAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.DefinedIn();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal12(e.GeneratedDeclaration());
  auto v17 = e.Language();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
}

void SerializeExclusiveTrylockFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExclusiveTrylockFunctionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeExcludeFromExplicitInstantiationAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExcludeFromExplicitInstantiationAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ErrorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.UserDiagnostic();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal12(e.IsError());
  b.setVal13(e.IsWarning());
}

void SerializeEnumExtensibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnumExtensibilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Extensibility())));
}

void SerializeEnforceTCBLeafAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBLeafAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.TCBName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnforceTCBAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.TCBName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnableIfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnableIfAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Condition()));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEmptyBasesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EmptyBasesAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDisableTailCallsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableTailCallsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDisableSanitizerInstrumentationAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableSanitizerInstrumentationAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDiagnoseIfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseIfAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.ArgumentDependent());
  b.setVal8(es.EntityId(e.Condition()));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DiagnosticType())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal16(es.EntityId(e.Parent()));
  b.setVal13(e.IsError());
  b.setVal18(e.IsWarning());
}

void SerializeDiagnoseAsBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseAsBuiltinAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Function()));
}

void SerializeDestructorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DestructorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDeprecatedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeprecatedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Replacement();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
}

void SerializeDeclOrStmtAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeclOrStmtAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAlwaysInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysInlineAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsClangAlwaysInline());
}

void SerializeNoMergeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMergeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e, nullptr);
}

void SerializeNoInlineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInlineAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(es, b, e, nullptr);
  b.setVal12(e.IsClangNoInline());
}

void SerializeDLLImportStaticLocalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportStaticLocalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDLLImportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDLLExportStaticLocalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportStaticLocalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeDLLExportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeConvergentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConvergentAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeConsumableSetOnReadAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableSetOnReadAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeConsumableAutoCastAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAutoCastAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeConsumableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DefaultState())));
}

void SerializeConstructorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstructorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeConstInitAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstInitAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsConstinit());
}

void SerializeConstAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCommonAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CommonAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeColdAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ColdAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCodeSegAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeSegAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCmseNSEntryAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSEntryAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCleanupAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CleanupAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.FunctionDeclaration()));
}

void SerializeCapturedRecordAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapturedRecordAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeCallbackAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallbackAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCallableWhenAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallableWhenAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCXX11NoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CXX11NoReturnAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeCUDASharedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDASharedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDALaunchBoundsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDALaunchBoundsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.MaxThreads()));
  b.setVal16(es.EntityId(e.MinBlocks()));
}

void SerializeCUDAInvalidTargetAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAInvalidTargetAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDAHostAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAHostAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDAGlobalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAGlobalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDADeviceBuiltinTextureTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinTextureTypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDADeviceBuiltinSurfaceTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinSurfaceTypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDADeviceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCUDAConstantAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAConstantAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCPUSpecificAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUSpecificAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCPUDispatchAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUDispatchAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCFUnknownTransferAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFUnknownTransferAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCFReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCFReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCFICanonicalJumpTableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFICanonicalJumpTableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCFGuardAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFGuardAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Guard())));
}

void SerializeCFAuditedTransferAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFAuditedTransferAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CDeclAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeC11NoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::C11NoReturnAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeBuiltinAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeBlocksAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BlocksAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeBTFDeclTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFDeclTagAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.BTFDeclTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBPFPreserveAccessIndexAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BPFPreserveAccessIndexAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAvailabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AvailabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Replacement();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.Strict());
  b.setVal13(e.Unavailable());
}

void SerializeAssumptionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumptionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Assumption();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssumeAlignedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumeAlignedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
  auto v16 = e.Offset();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
}

void SerializeAssertSharedLockAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertSharedLockAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAssertExclusiveLockAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertExclusiveLockAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAssertCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertCapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeAsmLabelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AsmLabelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.IsLiteralLabel());
  auto v9 = e.Label();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArtificialAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArtificialAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeArmBuiltinAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmBuiltinAliasAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeArgumentWithTypeTagAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArgumentWithTypeTagAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.IsPointer());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeArcWeakrefUnavailableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArcWeakrefUnavailableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAnyX86NoCfCheckAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCfCheckAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAnyX86NoCallerSavedRegistersAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCallerSavedRegistersAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAnyX86InterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86InterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAnalyzerNoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnalyzerNoReturnAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAlwaysDestroyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysDestroyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAllocSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAllocAlignAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocAlignAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAlignedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v8 = e.AlignmentExpression();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v16 = e.AlignmentType();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsAlignas());
  b.setVal13(e.IsAlignmentDependent());
  b.setVal18(e.IsAlignmentErrorDependent());
  b.setVal19(e.IsAlignmentExpression());
  b.setVal20(e.IsC11());
  b.setVal21(e.IsDeclspec());
  b.setVal22(e.IsGNU());
}

void SerializeAlignNaturalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignNaturalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAlignMac68kAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignMac68kAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAcquiredBeforeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredBeforeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAcquiredAfterAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredAfterAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAcquireHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireHandleAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquireCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireCapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeAVRSignalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRSignalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAVRInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRInterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeARMInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ARMInterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializeAMDGPUWavesPerEUAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUWavesPerEUAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal16(es.EntityId(e.Min()));
}

void SerializeAMDGPUNumVGPRAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumVGPRAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAMDGPUNumSGPRAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumSGPRAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAMDGPUKernelCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUKernelCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAMDGPUFlatWorkGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUFlatWorkGroupSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal16(es.EntityId(e.Min()));
}

void SerializeAArch64VectorPcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64VectorPcsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeAArch64SVEPcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64SVEPcsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeZeroCallUsedRegsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ZeroCallUsedRegsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ZeroCallUsedRegs())));
}

void SerializeXRayLogArgsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayLogArgsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeXRayInstrumentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayInstrumentAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.AlwaysXRayInstrument());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal13(e.NeverXRayInstrument());
}

void SerializeX86ForceAlignArgPointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::X86ForceAlignArgPointerAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeWorkGroupSizeHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WorkGroupSizeHintAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeWebAssemblyImportNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.ImportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyImportModuleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportModuleAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.ImportModule();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyExportNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyExportNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.ExportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakRefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakRefAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakImportAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakImportAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeWeakAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeWarnUnusedResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedResultAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.IsCXX11NoDiscard());
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeWarnUnusedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeVisibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VisibilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeVectorCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VectorCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeVecTypeHintAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecTypeHintAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.TypeHint()));
  b.setVal16(es.EntityId(e.TypeHintToken()));
}

void SerializeVecReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecReturnAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeUuidAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UuidAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Guid();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.GuidDeclaration()));
}

void SerializeUsingIfExistsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsingIfExistsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeUsedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeUnusedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnusedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeUninitializedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UninitializedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeUnavailableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnavailableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ImplicitReason())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeVisibilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeVisibilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeTypeTagForDatatypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeTagForDatatypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.LayoutCompatible());
  b.setVal8(es.EntityId(e.MatchingCType()));
  b.setVal16(es.EntityId(e.MatchingCTypeToken()));
  b.setVal13(e.MustBeNull());
}

void SerializeTryAcquireCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TryAcquireCapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal8(es.EntityId(e.SuccessValue()));
  b.setVal12(e.IsShared());
}

void SerializeTrivialABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TrivialABIAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeTransparentUnionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TransparentUnionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeThisCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThisCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeTestTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TestTypestateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.TestState())));
}

void SerializeTargetVersionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetVersionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.NamesString();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.IsDefaultVersion());
}

void SerializeTargetClonesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetClonesAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeTargetAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Architecture();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.FeaturesString();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.IsDefaultVersion());
}

void SerializeTLSModelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TLSModelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Model();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSysVABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SysVABIAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSwiftPrivateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftPrivateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSwiftNewTypeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNewTypeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.NewtypeKind())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeSwiftNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
}

void SerializeSwiftCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSwiftBridgedTypedefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgedTypedefAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSwiftBridgeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.SwiftType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAttrAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAttrAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Attribute();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncErrorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncErrorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
}

void SerializeSwiftAsyncCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSwiftAsyncAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeStrictGuardStackCheckAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictGuardStackCheckAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeStrictFPAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictFPAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeStdCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StdCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeStandaloneDebugAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StandaloneDebugAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSpeculativeLoadHardeningAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SpeculativeLoadHardeningAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSharedTrylockFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SharedTrylockFunctionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeSetTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SetTypestateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.NewState())));
}

void SerializeSentinelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SentinelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSelectAnyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SelectAnyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeScopedLockableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ScopedLockableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSYCLSpecialClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLSpecialClassAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeSYCLKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLKernelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeReturnsTwiceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsTwiceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeReturnsNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsNonNullAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeReturnTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnTypestateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.State())));
}

void SerializeRetainAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RetainAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeRestrictAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RestrictAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeRequiresCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RequiresCapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeReqdWorkGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReqdWorkGroupSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeReleaseCapabilityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseCapabilityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsGeneric());
  b.setVal13(e.IsShared());
}

void SerializeReinitializesAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReinitializesAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeRegCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RegCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeReadOnlyPlacementAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReadOnlyPlacementAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeRandomizeLayoutAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RandomizeLayoutAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeRISCVInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RISCVInterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializePureAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PureAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializePtGuardedVarAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedVarAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializePtGuardedByAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedByAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializePreserveMostAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveMostAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializePreserveAllAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveAllAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializePreferredNameAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredNameAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.TypedefType()));
  b.setVal16(es.EntityId(e.TypedefTypeToken()));
}

void SerializePragmaClangTextSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangTextSectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangRodataSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRodataSectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangRelroSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRelroSectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangDataSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangDataSectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangBSSSectionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangBSSSectionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PointerAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal16(es.EntityId(e.DerefTypeToken()));
}

void SerializePcsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PcsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.PCS())));
}

void SerializePatchableFunctionEntryAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PatchableFunctionEntryAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializePascalAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PascalAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeParamTypestateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParamTypestateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ParameterState())));
}

void SerializePackedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PackedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOwnershipAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnershipAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.OwnKind())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsHolds());
  b.setVal13(e.IsReturns());
  b.setVal18(e.IsTakes());
}

void SerializeOwnerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnerAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal16(es.EntityId(e.DerefTypeToken()));
}

void SerializeOverrideAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverrideAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOptimizeNoneAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OptimizeNoneAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOpenCLKernelAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLKernelAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOpenCLIntelReqdSubGroupSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLIntelReqdSubGroupSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCSubclassingRestrictedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCSubclassingRestrictedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCRootClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRootClassAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCReturnsInnerPointerAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCReturnsInnerPointerAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCRequiresSuperAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresSuperAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCRequiresPropertyDefsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresPropertyDefsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCPreciseLifetimeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCPreciseLifetimeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCOwnershipAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCOwnershipAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCNSObjectAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNSObjectAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCMethodFamilyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCMethodFamilyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Family())));
}

void SerializeObjCIndependentClassAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCIndependentClassAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCExternallyRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExternallyRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCExplicitProtocolImplAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExplicitProtocolImplAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCExceptionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExceptionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCBridgeRelatedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeRelatedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCBridgeMutableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeMutableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeObjCBridgeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOSReturnsRetainedOnZeroAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnZeroAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOSReturnsRetainedOnNonZeroAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnNonZeroAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOSReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOSReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOSConsumesThisAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumesThisAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOMPThreadPrivateDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPThreadPrivateDeclAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOMPDeclareVariantAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareVariantAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.VariantFuncReference()));
}

void SerializeOMPDeclareTargetDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareTargetDeclAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DevType())));
  b.setVal12(e.Indirect());
  b.setVal8(es.EntityId(e.IndirectExpression()));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.MapType())));
}

void SerializeOMPCaptureNoInitAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureNoInitAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeOMPAllocateDeclAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPAllocateDeclAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
  b.setVal16(es.EntityId(e.Allocator()));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.AllocatorType())));
}

void SerializeNotTailCalledAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NotTailCalledAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoUwtableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUwtableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoUniqueAddressAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUniqueAddressAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoThrowAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThrowAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoThreadSafetyAnalysisAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThreadSafetyAnalysisAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoStackProtectorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoStackProtectorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeNoSplitStackAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSplitStackAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoSpeculativeLoadHardeningAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSpeculativeLoadHardeningAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoSanitizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSanitizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.HasCoverage());
}

void SerializeNoReturnAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoReturnAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoRandomizeLayoutAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoRandomizeLayoutAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoProfileFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoProfileFunctionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoMips16Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMips16Attr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoMicroMipsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMicroMipsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoInstrumentFunctionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInstrumentFunctionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoDuplicateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDuplicateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoDestroyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDestroyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoDebugAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDebugAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoCommonAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoCommonAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNoAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoAliasAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNakedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NakedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNSReturnsRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNSReturnsNotRetainedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNSReturnsAutoreleasedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsAutoreleasedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeNSErrorDomainAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSErrorDomainAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.ErrorDomain()));
}

void SerializeNSConsumesSelfAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumesSelfAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMipsShortCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsShortCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsLongCallAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsLongCallAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsInterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializeMips16Attr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Mips16Attr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMinVectorWidthAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinVectorWidthAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMinSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMicroMipsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MicroMipsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMaybeUndefAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaybeUndefAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMayAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MayAliasAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMaxFieldAlignmentAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaxFieldAlignmentAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMSVtorDispAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSVtorDispAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.VtorDispMode())));
}

void SerializeMSStructAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSStructAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMSP430InterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSP430InterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMSNoVTableAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSNoVTableAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMSInheritanceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSInheritanceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal12(e.BestCase());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.InheritanceModel())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMSAllocatorAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSAllocatorAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMSABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSABIAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeMIGServerRoutineAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MIGServerRoutineAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeM68kInterruptAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::M68kInterruptAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeLocksExcludedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LocksExcludedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeLockReturnedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LockReturnedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializeLifetimeBoundAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LifetimeBoundAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeLeafAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LeafAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeLayoutVersionAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LayoutVersionAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeLTOVisibilityPublicAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LTOVisibilityPublicAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeInternalLinkageAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InternalLinkageAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeIntelOclBiccAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IntelOclBiccAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeInitPriorityAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitPriorityAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeInheritableParamAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableParamAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeCarriesDependencyAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CarriesDependencyAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
}

void SerializeCFConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFConsumedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
}

void SerializeAnnotateAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUseHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UseHandleAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReleaseHandleAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseHandleAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePassObjectSizeAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PassObjectSizeAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsDynamic());
}

void SerializeParameterABIAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParameterABIAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ABI())));
}

void SerializeSwiftIndirectResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftIndirectResultAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e, nullptr);
}

void SerializeSwiftErrorResultAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorResultAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e, nullptr);
}

void SerializeSwiftContextAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftContextAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e, nullptr);
}

void SerializeSwiftAsyncContextAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncContextAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(es, b, e, nullptr);
}

void SerializeOSConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
}

void SerializeNonNullAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NonNullAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
}

void SerializeNSConsumedAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumedAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(es, b, e, nullptr);
}

void SerializeIFuncAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IFuncAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  auto v9 = e.Resolver();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCalledOnceAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CalledOnceAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
}

void SerializeBuiltinAliasAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAliasAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::Type &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.EntityId(e.DesugaredType()));
  b.setVal1(es.EntityId(e.CanonicalType()));
  b.setVal2(e.IsQualified());
  b.setVal3(es.EntityId(e.UnqualifiedType()));
  b.setVal4(e.AcceptsObjCTypeParameters());
  b.setVal5(e.CanDecayToPointerType());
  b.setVal6(e.CanHaveNullability());
  b.setVal7(e.ContainsErrors());
  b.setVal8(e.ContainsUnexpandedParameterPack());
  auto v9 = e.ArrayElementTypeNoTypeQualified();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  auto v11 = e.Nullability();
  if (v11) {
    b.setVal11(static_cast<unsigned char>(v11.value()));
    b.setVal12(true);
  } else {
    b.setVal12(false);
  }
  auto v13 = e.PointeeCXXRecordDeclaration();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.PointeeOrArrayElementType();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v15 = e.PointeeType();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
  } else {
    b.setVal15(mx::kInvalidEntityId);
  }
  auto v16 = e.ScalarTypeKind();
  if (v16) {
    b.setVal16(static_cast<unsigned char>(v16.value()));
    b.setVal17(true);
  } else {
    b.setVal17(false);
  }
  auto v18 = e.SveElementType();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  b.setVal19(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal20(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal22(e.HasAutoForTrailingReturnType());
  b.setVal23(e.HasFloatingRepresentation());
  b.setVal24(e.HasIntegerRepresentation());
  b.setVal25(e.HasObjCPointerRepresentation());
  b.setVal26(e.HasPointerRepresentation());
  b.setVal27(e.HasSignedIntegerRepresentation());
  b.setVal28(e.HasSizedVLAType());
  b.setVal29(e.HasUnnamedOrLocalType());
  b.setVal30(e.HasUnsignedIntegerRepresentation());
  auto v31 = e.IsAggregateType();
  if (v31) {
    b.setVal31(static_cast<bool>(v31.value()));
    b.setVal32(true);
  } else {
    b.setVal32(false);
  }
  b.setVal33(e.IsAlignValueT());
  b.setVal34(e.IsAnyCharacterType());
  b.setVal35(e.IsAnyComplexType());
  b.setVal36(e.IsAnyPointerType());
  b.setVal37(e.IsArithmeticType());
  b.setVal38(e.IsArrayType());
  b.setVal39(e.IsAtomicType());
  b.setVal40(e.IsBFloat16Type());
  b.setVal41(e.IsBitIntType());
  b.setVal42(e.IsBlockCompatibleObjCPointerType());
  b.setVal43(e.IsBlockPointerType());
  b.setVal44(e.IsBooleanType());
  b.setVal45(e.IsBuiltinType());
  b.setVal46(e.IsCARCBridgableType());
  b.setVal47(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal48(e.IsCUDADeviceBuiltinTextureType());
  b.setVal49(e.IsCanonicalUnqualified());
  b.setVal50(e.IsChar16Type());
  b.setVal51(e.IsChar32Type());
  b.setVal52(e.IsChar8Type());
  b.setVal53(e.IsCharacterType());
  b.setVal54(e.IsClassType());
  b.setVal55(e.IsClkEventT());
  b.setVal56(e.IsComplexIntegerType());
  b.setVal57(e.IsComplexType());
  b.setVal58(e.IsCompoundType());
  b.setVal59(e.IsConstantArrayType());
  b.setVal60(e.IsConstantMatrixType());
  auto v61 = e.IsConstantSizeType();
  if (v61) {
    b.setVal61(static_cast<bool>(v61.value()));
    b.setVal62(true);
  } else {
    b.setVal62(false);
  }
  b.setVal63(e.IsDecltypeType());
  b.setVal64(e.IsDependentAddressSpaceType());
  b.setVal65(e.IsDependentSizedArrayType());
  b.setVal66(e.IsDependentType());
  b.setVal67(e.IsElaboratedTypeSpecifier());
  b.setVal68(e.IsEnumeralType());
  b.setVal69(e.IsEventT());
  b.setVal70(e.IsExtVectorBooleanType());
  b.setVal71(e.IsExtVectorType());
  b.setVal72(e.IsFixedPointOrIntegerType());
  b.setVal73(e.IsFixedPointType());
  b.setVal74(e.IsFloat128Type());
  b.setVal75(e.IsFloat16Type());
  b.setVal76(e.IsFloatingType());
  b.setVal77(e.IsFromAST());
  b.setVal78(e.IsFunctionNoProtoType());
  b.setVal79(e.IsFunctionPointerType());
  b.setVal80(e.IsFunctionProtoType());
  b.setVal81(e.IsFunctionReferenceType());
  b.setVal82(e.IsFunctionType());
  b.setVal83(e.IsFundamentalType());
  b.setVal84(e.IsHalfType());
  b.setVal85(e.IsIbm128Type());
  b.setVal86(e.IsImageType());
  b.setVal87(e.IsIncompleteArrayType());
  b.setVal88(e.IsIncompleteOrObjectType());
  b.setVal89(e.IsIncompleteType());
  b.setVal90(e.IsInstantiationDependentType());
  b.setVal91(e.IsIntegerType());
  b.setVal92(e.IsIntegralOrEnumerationType());
  b.setVal93(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal94(e.IsIntegralType());
  b.setVal95(e.IsInterfaceType());
  b.setVal96(e.IsLValueReferenceType());
  b.setVal97(e.IsLinkageValid());
  auto v98 = e.IsLiteralType();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  b.setVal100(e.IsMatrixType());
  b.setVal101(e.IsMemberDataPointerType());
  b.setVal102(e.IsMemberFunctionPointerType());
  b.setVal103(e.IsMemberPointerType());
  b.setVal104(e.IsNonOverloadPlaceholderType());
  b.setVal105(e.IsNothrowT());
  b.setVal106(e.IsNullPointerType());
  b.setVal107(e.IsOCLExtOpaqueType());
  b.setVal108(e.IsOCLImage1dArrayROType());
  b.setVal109(e.IsOCLImage1dArrayRWType());
  b.setVal110(e.IsOCLImage1dArrayWOType());
  b.setVal111(e.IsOCLImage1dBufferROType());
  b.setVal112(e.IsOCLImage1dBufferRWType());
  b.setVal113(e.IsOCLImage1dBufferWOType());
  b.setVal114(e.IsOCLImage1dROType());
  b.setVal115(e.IsOCLImage1dRWType());
  b.setVal116(e.IsOCLImage1dWOType());
  b.setVal117(e.IsOCLImage2dArrayDepthROType());
  b.setVal118(e.IsOCLImage2dArrayDepthRWType());
  b.setVal119(e.IsOCLImage2dArrayDepthWOType());
  b.setVal120(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal121(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal122(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal123(e.IsOCLImage2dArrayMSAAROType());
  b.setVal124(e.IsOCLImage2dArrayMSAARWType());
  b.setVal125(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal126(e.IsOCLImage2dArrayROType());
  b.setVal127(e.IsOCLImage2dArrayRWType());
  b.setVal128(e.IsOCLImage2dArrayWOType());
  b.setVal129(e.IsOCLImage2dDepthROType());
  b.setVal130(e.IsOCLImage2dDepthRWType());
  b.setVal131(e.IsOCLImage2dDepthWOType());
  b.setVal132(e.IsOCLImage2dMSAADepthROType());
  b.setVal133(e.IsOCLImage2dMSAADepthRWType());
  b.setVal134(e.IsOCLImage2dMSAADepthWOType());
  b.setVal135(e.IsOCLImage2dMSAAROType());
  b.setVal136(e.IsOCLImage2dMSAARWType());
  b.setVal137(e.IsOCLImage2dMSAAWOType());
  b.setVal138(e.IsOCLImage2dROType());
  b.setVal139(e.IsOCLImage2dRWType());
  b.setVal140(e.IsOCLImage2dWOType());
  b.setVal141(e.IsOCLImage3dROType());
  b.setVal142(e.IsOCLImage3dRWType());
  b.setVal143(e.IsOCLImage3dWOType());
  b.setVal144(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal145(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal146(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal147(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal148(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal149(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal150(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal151(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal152(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal153(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal154(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal155(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal156(e.IsOCLIntelSubgroupAVCType());
  b.setVal157(e.IsObjCARCBridgableType());
  auto v158 = e.IsObjCARCImplicitlyUnretainedType();
  if (v158) {
    b.setVal158(static_cast<bool>(v158.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  b.setVal160(e.IsObjCBoxableRecordType());
  b.setVal161(e.IsObjCBuiltinType());
  b.setVal162(e.IsObjCClassOrClassKindOfType());
  b.setVal163(e.IsObjCClassType());
  b.setVal164(e.IsObjCIdType());
  b.setVal165(e.IsObjCIndependentClassType());
  b.setVal166(e.IsObjCIndirectLifetimeType());
  b.setVal167(e.IsObjCInertUnsafeUnretainedType());
  b.setVal168(e.IsObjCLifetimeType());
  b.setVal169(e.IsObjCNSObjectType());
  b.setVal170(e.IsObjCObjectOrInterfaceType());
  b.setVal171(e.IsObjCObjectPointerType());
  b.setVal172(e.IsObjCObjectType());
  b.setVal173(e.IsObjCQualifiedClassType());
  b.setVal174(e.IsObjCQualifiedIdType());
  b.setVal175(e.IsObjCQualifiedInterfaceType());
  b.setVal176(e.IsObjCRetainableType());
  b.setVal177(e.IsObjCSelType());
  b.setVal178(e.IsObjectPointerType());
  b.setVal179(e.IsObjectType());
  b.setVal180(e.IsOpenCLSpecificType());
  b.setVal181(e.IsOverloadableType());
  b.setVal182(e.IsPipeType());
  b.setVal183(e.IsPlaceholderType());
  b.setVal184(e.IsPointerType());
  b.setVal185(e.IsQueueT());
  b.setVal186(e.IsRVVType());
  b.setVal187(e.IsRValueReferenceType());
  b.setVal188(e.IsRealFloatingType());
  b.setVal189(e.IsRealType());
  b.setVal190(e.IsRecordType());
  b.setVal191(e.IsReferenceType());
  b.setVal192(e.IsReserveIDT());
  b.setVal193(e.IsSVESizelessBuiltinType());
  b.setVal194(e.IsSamplerT());
  b.setVal195(e.IsSaturatedFixedPointType());
  b.setVal196(e.IsScalarType());
  b.setVal197(e.IsScopedEnumeralType());
  b.setVal198(e.IsSignedFixedPointType());
  b.setVal199(e.IsSignedIntegerOrEnumerationType());
  b.setVal200(e.IsSignedIntegerType());
  b.setVal201(e.IsSizelessBuiltinType());
  b.setVal202(e.IsSizelessType());
  b.setVal203(e.IsSpecifierType());
  auto v204 = e.IsStandardLayoutType();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  b.setVal206(e.IsStdByteType());
  auto v207 = e.IsStructuralType();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  b.setVal209(e.IsStructureOrClassType());
  b.setVal210(e.IsStructureType());
  b.setVal211(e.IsTemplateTypeParmType());
  b.setVal212(e.IsTypedefNameType());
  b.setVal213(e.IsUndeducedAutoType());
  b.setVal214(e.IsUndeducedType());
  b.setVal215(e.IsUnionType());
  b.setVal216(e.IsUnsaturatedFixedPointType());
  b.setVal217(e.IsUnscopedEnumerationType());
  b.setVal218(e.IsUnsignedFixedPointType());
  b.setVal219(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal220(e.IsUnsignedIntegerType());
  b.setVal221(e.IsVLSTBuiltinType());
  b.setVal222(e.IsVariableArrayType());
  b.setVal223(e.IsVariablyModifiedType());
  b.setVal224(e.IsVectorType());
  b.setVal225(e.IsVisibilityExplicit());
  b.setVal226(e.IsVoidPointerType());
  b.setVal227(e.IsVoidType());
  b.setVal228(e.IsWideCharacterType());
}

void SerializeTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto v230 = e.Declaration();
  if (v230) {
    auto id230 = es.EntityId(v230.value());
    b.setVal230(id230);
  } else {
    b.setVal230(mx::kInvalidEntityId);
  }
  b.setVal231(e.IsParameterPack());
  b.setVal232(e.IsSugared());
}

void SerializeTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto v230 = e.AliasedType();
  if (v230) {
    auto id230 = es.EntityId(v230.value());
    b.setVal230(id230);
  } else {
    b.setVal230(mx::kInvalidEntityId);
  }
  b.setVal231(e.IsCurrentInstantiation());
  b.setVal232(e.IsSugared());
  b.setVal233(e.IsTypeAlias());
  do {
    auto v234 = e.TemplateArguments();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
}

void SerializeTagType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal231(e.IsBeingDefined());
}

void SerializeRecordType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  b.setVal232(e.HasConstFields());
  b.setVal233(e.IsSugared());
}

void SerializeEnumType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  b.setVal232(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.AssociatedDeclaration()));
  auto v235 = e.PackIndex();
  if (v235) {
    b.setVal235(static_cast<unsigned>(v235.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  b.setVal236(es.EntityId(e.ReplacedParameter()));
  b.setVal237(es.EntityId(e.ReplacementType()));
  b.setVal232(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.AssociatedDeclaration()));
  b.setVal231(e.Final());
  b.setVal236(es.EntityId(e.ReplacedParameter()));
  b.setVal232(e.IsSugared());
}

void SerializeReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal231(e.IsInnerReference());
  b.setVal232(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  b.setVal233(e.IsSugared());
}

void SerializeLValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  b.setVal233(e.IsSugared());
}

void SerializeQualifiedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal229(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal231(e.HasAddressSpace());
  b.setVal232(e.HasNonTrivialObjCLifetime());
  b.setVal233(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal239(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal240(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal241(e.HasQualifiers());
  b.setVal242(e.HasStrongOrWeakObjCLifetime());
  b.setVal243(e.IsCForbiddenLValueType());
  b.setVal244(e.IsCXX11PODType());
  b.setVal245(e.IsCXX98PODType());
  b.setVal246(e.IsCanonical());
  b.setVal247(e.IsCanonicalAsParameter());
  b.setVal248(e.IsConstQualified());
  b.setVal249(e.IsConstant());
  b.setVal250(e.IsLocalConstQualified());
  b.setVal251(e.IsLocalRestrictQualified());
  b.setVal252(e.IsLocalVolatileQualified());
  b.setVal253(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal254(e.IsNull());
  b.setVal255(e.IsObjCGCStrong());
  b.setVal256(e.IsObjCGCWeak());
  b.setVal257(e.IsPODType());
  b.setVal258(e.IsReferenceable());
  b.setVal259(e.IsRestrictQualified());
  b.setVal260(e.IsTrivialType());
  b.setVal261(e.IsTriviallyCopyableType());
  b.setVal262(e.IsTriviallyRelocatableType());
  b.setVal263(e.IsVolatileQualified());
  b.setVal264(e.MayBeDynamicClass());
  b.setVal265(e.MayBeNotDynamicClass());
}

void SerializePointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializePipeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ElementType()));
  b.setVal231(e.IsReadOnly());
  b.setVal232(e.IsSugared());
}

void SerializeParenType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.InnerType()));
  b.setVal231(e.IsSugared());
}

void SerializePackExpansionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Pattern()));
  b.setVal231(e.IsSugared());
}

void SerializeObjCTypeParamType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Declaration()));
  b.setVal231(e.IsSugared());
}

void SerializeObjCObjectType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.BaseType()));
  b.setVal236(es.EntityId(e.Interface()));
  auto v237 = e.SuperClassType();
  if (v237) {
    auto id237 = es.EntityId(v237.value());
    b.setVal237(id237);
  } else {
    b.setVal237(mx::kInvalidEntityId);
  }
  do {
    auto v234 = e.TypeArguments();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
  do {
    auto v266 = e.TypeArgumentsAsWritten();
    auto sv266 = b.initVal266(static_cast<unsigned>(v266.size()));
    auto i266 = 0u;
    for (const auto &e266 : v266) {
      sv266.set(i266, es.EntityId(e266));
      ++i266;
    }
  } while (false);
  b.setVal231(e.IsKindOfType());
  b.setVal232(e.IsKindOfTypeAsWritten());
  b.setVal233(e.IsObjCClass());
  b.setVal239(e.IsObjCId());
  b.setVal240(e.IsObjCQualifiedClass());
  b.setVal241(e.IsObjCQualifiedId());
  b.setVal242(e.IsObjCUnqualifiedClass());
  b.setVal243(e.IsObjCUnqualifiedId());
  b.setVal244(e.IsObjCUnqualifiedIdOrClass());
  b.setVal245(e.IsSpecialized());
  b.setVal246(e.IsSpecializedAsWritten());
  b.setVal247(e.IsSugared());
  b.setVal248(e.IsUnspecialized());
  b.setVal249(e.IsUnspecializedAsWritten());
  b.setVal267(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e, nullptr);
  b.setVal268(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.InterfaceDeclaration()));
  b.setVal236(es.EntityId(e.InterfaceType()));
  b.setVal237(es.EntityId(e.ObjectType()));
  b.setVal267(es.EntityId(e.SuperClassType()));
  do {
    auto v234 = e.TypeArguments();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
  do {
    auto v266 = e.TypeArgumentsAsWritten();
    auto sv266 = b.initVal266(static_cast<unsigned>(v266.size()));
    auto i266 = 0u;
    for (const auto &e266 : v266) {
      sv266.set(i266, es.EntityId(e266));
      ++i266;
    }
  } while (false);
  b.setVal231(e.IsKindOfType());
  b.setVal232(e.IsObjCIdOrClassType());
  b.setVal233(e.IsSpecialized());
  b.setVal239(e.IsSpecializedAsWritten());
  b.setVal240(e.IsSugared());
  b.setVal241(e.IsUnspecialized());
  b.setVal242(e.IsUnspecializedAsWritten());
  do {
    auto v269 = e.Qualifiers();
    auto sv269 = b.initVal269(static_cast<unsigned>(v269.size()));
    auto i269 = 0u;
    for (const auto &e269 : v269) {
      sv269.set(i269, es.EntityId(e269));
      ++i269;
    }
  } while (false);
  b.setVal268(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v270 = e.Protocols();
    auto sv270 = b.initVal270(static_cast<unsigned>(v270.size()));
    auto i270 = 0u;
    for (const auto &e270 : v270) {
      sv270.set(i270, es.EntityId(e270));
      ++i270;
    }
  } while (false);
}

void SerializeMemberPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Class()));
  b.setVal236(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal231(e.IsMemberDataPointer());
  b.setVal232(e.IsMemberFunctionPointer());
  b.setVal233(e.IsSugared());
}

void SerializeMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ElementType()));
  b.setVal231(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e, nullptr);
  auto t236 = e.AttributeToken();
  b.setVal236(es.EntityId(t236));
  b.setVal237(es.EntityId(e.ColumnExpression()));
  b.setVal267(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e, nullptr);
}

void SerializeMacroQualifiedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ModifiedType()));
  b.setVal236(es.EntityId(e.UnderlyingType()));
  b.setVal231(e.IsSugared());
}

void SerializeInjectedClassNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Declaration()));
  b.setVal236(es.EntityId(e.InjectedSpecializationType()));
  b.setVal237(es.EntityId(e.InjectedTST()));
  b.setVal231(e.IsSugared());
}

void SerializeFunctionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal229(es.EntityId(e.CallResultType()));
  b.setVal231(e.CmseNSCallAttribute());
  b.setVal232(e.HasRegParm());
  b.setVal233(e.NoReturnAttribute());
  b.setVal230(es.EntityId(e.ReturnType()));
  b.setVal239(e.IsConst());
  b.setVal240(e.IsRestrict());
  b.setVal241(e.IsVolatile());
}

void SerializeFunctionProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e, nullptr);
  auto v271 = e.CanThrow();
  if (v271) {
    b.setVal271(static_cast<unsigned char>(v271.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  b.setVal236(es.EntityId(e.Desugar()));
  auto t237 = e.EllipsisToken();
  b.setVal237(es.EntityId(t237));
  auto v267 = e.ExceptionSpecDeclaration();
  if (v267) {
    auto id267 = es.EntityId(v267.value());
    b.setVal267(id267);
  } else {
    b.setVal267(mx::kInvalidEntityId);
  }
  auto v268 = e.ExceptionSpecTemplate();
  if (v268) {
    auto id268 = es.EntityId(v268.value());
    b.setVal268(id268);
  } else {
    b.setVal268(mx::kInvalidEntityId);
  }
  b.setVal272(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v273 = e.NoexceptExpression();
  if (v273) {
    auto id273 = es.EntityId(v273.value());
    b.setVal273(id273);
  } else {
    b.setVal273(mx::kInvalidEntityId);
  }
  do {
    auto v234 = e.ParameterTypes();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
  b.setVal274(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal243(e.HasDependentExceptionSpec());
  b.setVal244(e.HasDynamicExceptionSpec());
  b.setVal245(e.HasExceptionSpec());
  b.setVal246(e.HasExtParameterInfos());
  b.setVal247(e.HasInstantiationDependentExceptionSpec());
  b.setVal248(e.HasNoexceptExceptionSpec());
  b.setVal249(e.HasTrailingReturn());
  auto v250 = e.IsNothrow();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  b.setVal252(e.IsSugared());
  b.setVal253(e.IsTemplateVariadic());
  b.setVal254(e.IsVariadic());
  do {
    auto v266 = e.ExceptionTypes();
    auto sv266 = b.initVal266(static_cast<unsigned>(v266.size()));
    auto i266 = 0u;
    for (const auto &e266 : v266) {
      sv266.set(i266, es.EntityId(e266));
      ++i266;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal242(e.IsSugared());
}

void SerializeDependentVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto t230 = e.AttributeToken();
  b.setVal230(es.EntityId(t230));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal237(es.EntityId(e.SizeExpression()));
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal231(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto t230 = e.AttributeToken();
  b.setVal230(es.EntityId(t230));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal237(es.EntityId(e.SizeExpression()));
  b.setVal231(e.IsSugared());
}

void SerializeDependentBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.NumBitsExpression()));
  b.setVal231(e.IsSigned());
  b.setVal232(e.IsSugared());
  b.setVal233(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.AddressSpaceExpression()));
  auto t236 = e.AttributeToken();
  b.setVal236(es.EntityId(t236));
  b.setVal231(e.IsSugared());
}

void SerializeDeducedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto v230 = e.ResolvedType();
  if (v230) {
    auto id230 = es.EntityId(v230.value());
    b.setVal230(id230);
  } else {
    b.setVal230(mx::kInvalidEntityId);
  }
  b.setVal231(e.IsDeduced());
  b.setVal232(e.IsSugared());
}

void SerializeDeducedTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedTemplateSpecializationType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e, nullptr);
}

void SerializeAutoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AutoType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(es, b, e, nullptr);
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v234 = e.TypeConstraintArguments();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
  auto v236 = e.TypeConstraintConcept();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal233(e.IsConstrained());
  b.setVal239(e.IsDecltypeAuto());
  b.setVal240(e.IsGNUAutoType());
}

void SerializeDecltypeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.UnderlyingExpression()));
  b.setVal236(es.EntityId(e.UnderlyingType()));
  b.setVal231(e.IsSugared());
}

void SerializeComplexType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ElementType()));
  b.setVal231(e.IsSugared());
}

void SerializeBuiltinType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal231(e.IsFloatingPoint());
  b.setVal232(e.IsInteger());
  b.setVal233(e.IsSVEBool());
  b.setVal239(e.IsSignedInteger());
  b.setVal240(e.IsSugared());
  b.setVal241(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializeBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSigned());
  b.setVal232(e.IsSugared());
  b.setVal233(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Attribute()));
  b.setVal236(es.EntityId(e.WrappedType()));
  b.setVal231(e.IsSugared());
}

void SerializeAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal275(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal230(es.EntityId(e.EquivalentType()));
  auto v238 = e.ImmediateNullability();
  if (v238) {
    b.setVal238(static_cast<unsigned char>(v238.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  b.setVal236(es.EntityId(e.ModifiedType()));
  b.setVal232(e.IsCallingConv());
  b.setVal233(e.IsMSTypeSpec());
  b.setVal239(e.IsQualifier());
  b.setVal240(e.IsSugared());
}

void SerializeAtomicType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ValueType()));
  b.setVal231(e.IsSugared());
}

void SerializeArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  if (auto r236 = e.BracketsRange(); auto rs236 = r236.Size()) {
    b.setVal236(es.EntityId(r236[0]));
    b.setVal237(es.EntityId(r236[rs236 - 1u]));
  } else {
    b.setVal236(0);
    b.setVal237(0);
  }
  auto t267 = e.LBracketToken();
  b.setVal267(es.EntityId(t267));
  auto t268 = e.RBracketToken();
  b.setVal268(es.EntityId(t268));
  b.setVal273(es.EntityId(e.SizeExpression()));
  b.setVal231(e.IsSugared());
}

void SerializeIncompleteArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializeDependentSizedArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  if (auto r236 = e.BracketsRange(); auto rs236 = r236.Size()) {
    b.setVal236(es.EntityId(r236[0]));
    b.setVal237(es.EntityId(r236[rs236 - 1u]));
  } else {
    b.setVal236(0);
    b.setVal237(0);
  }
  auto t267 = e.LBracketToken();
  b.setVal267(es.EntityId(t267));
  auto t268 = e.RBracketToken();
  b.setVal268(es.EntityId(t268));
  b.setVal273(es.EntityId(e.SizeExpression()));
  b.setVal231(e.IsSugared());
}

void SerializeConstantArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal230(es.EntityId(e.Desugar()));
  auto v236 = e.SizeExpression();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal231(e.IsSugared());
}

void SerializeAdjustedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ResolvedType()));
  b.setVal236(es.EntityId(e.OriginalType()));
  b.setVal231(e.IsSugared());
}

void SerializeDecayedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(es, b, e, nullptr);
}

void SerializeTypeWithKeyword(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.NamedType()));
  auto v236 = e.OwnedTagDeclaration();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal231(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
  do {
    auto v234 = e.TemplateArguments();
    auto sv234 = b.initVal234(static_cast<unsigned>(v234.size()));
    auto i234 = 0u;
    for (const auto &e234 : v234) {
      sv234.set(i234, es.EntityId(e234));
      ++i234;
    }
  } while (false);
}

void SerializeDependentNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializeVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.ElementType()));
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal231(e.IsSugared());
}

void SerializeExtVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(es, b, e, nullptr);
}

void SerializeUsingType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UsingType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.FoundDeclaration()));
  b.setVal236(es.EntityId(e.UnderlyingType()));
  b.setVal231(e.IsSugared());
  b.setVal232(e.TypeMatchesDeclaration());
}

void SerializeUnresolvedUsingType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Declaration()));
  b.setVal231(e.IsSugared());
}

void SerializeUnaryTransformType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.BaseType()));
  b.setVal238(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal236(es.EntityId(e.UnderlyingType()));
  b.setVal231(e.IsSugared());
}

void SerializeTypedefType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.Declaration()));
  b.setVal231(e.IsSugared());
  b.setVal232(e.TypeMatchesDeclaration());
}

void SerializeTypeOfType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.UnmodifiedType()));
  b.setVal231(e.IsSugared());
}

void SerializeTypeOfExprType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(es.EntityId(e.UnderlyingExpression()));
  b.setVal231(e.IsSugared());
}

void SerializeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e, const TokenTree *) {
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  if (auto r2 = ReferencedDecl(e)) {
    b.setVal2(es.EntityId(r2.value()));
  }
  do {
    auto v3 = e.AlignedSubstitutions();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  } while (false);
  b.setVal4(es.EntityId(e.IgnoreContainers()));
  do {
    auto v5 = e.Children();
    auto sv5 = b.initVal5(static_cast<unsigned>(v5.size()));
    auto i5 = 0u;
    for (const auto &e5 : v5) {
      sv5.set(i5, es.EntityId(e5));
      ++i5;
    }
  } while (false);
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

void SerializeSEHTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.ExceptHandler()));
  b.setVal11(es.EntityId(e.FinallyHandler()));
  b.setVal12(es.EntityId(e.Handler()));
  b.setVal13(e.IsCXXTry());
  b.setVal14(es.EntityId(e.TryBlock()));
  auto t15 = e.TryToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeSEHLeaveStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.LeaveToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeSEHFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Block()));
  auto t11 = e.FinallyToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeSEHExceptStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Block()));
  auto t11 = e.ExceptToken();
  b.setVal11(es.EntityId(t11));
  b.setVal12(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v10 = e.NRVOCandidate();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.ReturnValue();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto t12 = e.ReturnToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeObjCForCollectionStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Collection()));
  b.setVal12(es.EntityId(e.Element()));
  auto t14 = e.ForToken();
  b.setVal14(es.EntityId(t14));
  auto t15 = e.RParenToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeObjCAutoreleasePoolStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.AtToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.AtTryToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FinallyStatement()));
  b.setVal12(es.EntityId(e.TryBody()));
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

void SerializeObjCAtThrowStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.ThrowExpression()));
  auto t11 = e.ThrowToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeObjCAtSynchronizedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.AtSynchronizedToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SynchBody()));
  b.setVal12(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.AtFinallyToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.AtCatchToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.CatchBody()));
  b.setVal12(es.EntityId(e.CatchParameterDeclaration()));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
  b.setVal13(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.AssociatedStatement()));
  b.setVal11(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal12(es.EntityId(e.RawStatement()));
  b.setVal14(es.EntityId(e.StructuredBlock()));
  b.setVal13(e.HasAssociatedStatement());
  b.setVal17(e.IsStandaloneDirective());
}

void SerializeOMPErrorDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPErrorDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPDispatchDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  auto t15 = e.TargetCallToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeOMPDepobjDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCriticalDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCancellationPointDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCancelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPBarrierDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPAtomicDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.ConditionExpression()));
  b.setVal18(es.EntityId(e.D()));
  b.setVal19(es.EntityId(e.Expression()));
  b.setVal20(es.EntityId(e.R()));
  b.setVal21(es.EntityId(e.UpdateExpression()));
  b.setVal22(es.EntityId(e.V()));
  b.setVal23(es.EntityId(e.X()));
  b.setVal24(e.IsFailOnly());
  b.setVal25(e.IsPostfixUpdate());
  b.setVal26(e.IsXLHSInRHSPart());
}

void SerializeOMPTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTaskyieldDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTaskwaitDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTaskgroupDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetEnterDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetDataDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPSingleDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPSectionDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPScanDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPParallelSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPOrderedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.IfStatement()));
}

void SerializeOMPMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPLoopBasedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPLoopTransformationDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e, const TokenTree *) {
  SerializeOMPLoopBasedDirective(es, b, e, nullptr);
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPUnrollDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e, const TokenTree *) {
  SerializeOMPLoopTransformationDirective(es, b, e, nullptr);
}

void SerializeOMPTileDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e, const TokenTree *) {
  SerializeOMPLoopTransformationDirective(es, b, e, nullptr);
}

void SerializeOMPLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopBasedDirective(es, b, e, nullptr);
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
    auto v27 = e.DependentCounters();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
    }
  } while (false);
  do {
    auto v28 = e.DependentInitializers();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
  do {
    auto v29 = e.Finals();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  do {
    auto v30 = e.FinalsConditions();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  b.setVal15(es.EntityId(e.Body()));
  b.setVal18(es.EntityId(e.CalculateLastIteration()));
  b.setVal19(es.EntityId(e.CombinedCondition()));
  b.setVal20(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal21(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal22(es.EntityId(e.CombinedInitializer()));
  b.setVal23(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal31(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal32(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal33(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal34(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal35(es.EntityId(e.Condition()));
  b.setVal36(es.EntityId(e.DistanceIncrement()));
  b.setVal37(es.EntityId(e.EnsureUpperBound()));
  b.setVal38(es.EntityId(e.Increment()));
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.IsLastIterationVariable()));
  b.setVal41(es.EntityId(e.IterationVariable()));
  b.setVal42(es.EntityId(e.LastIteration()));
  b.setVal43(es.EntityId(e.LowerBoundVariable()));
  b.setVal44(es.EntityId(e.NextLowerBound()));
  b.setVal45(es.EntityId(e.NextUpperBound()));
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

void SerializeOMPGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTeamsGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPTargetTeamsGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPInteropDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPFlushDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCanonicalLoop(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.DistanceFunc()));
  b.setVal11(es.EntityId(e.LoopStatement()));
  b.setVal12(es.EntityId(e.LoopVariableFunc()));
  b.setVal14(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.SemiToken();
  b.setVal10(es.EntityId(t10));
  b.setVal13(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.KeywordToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsIfExists());
  b.setVal17(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v10 = e.ConstantTarget();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto t11 = e.GotoToken();
  b.setVal11(es.EntityId(t11));
  auto t12 = e.StarToken();
  b.setVal12(es.EntityId(t12));
  b.setVal14(es.EntityId(e.Target()));
}

void SerializeIfStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.ConditionVariable();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v12 = e.ConditionVariableDeclarationStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v14 = e.Else();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto t15 = e.ElseToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.IfToken();
  b.setVal18(es.EntityId(t18));
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto t20 = e.LParenToken();
  b.setVal20(es.EntityId(t20));
  auto v21 = e.NondiscardedCase();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  auto t22 = e.RParenToken();
  b.setVal22(es.EntityId(t22));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal23(es.EntityId(e.Then()));
  b.setVal13(e.HasElseStorage());
  b.setVal17(e.HasInitializerStorage());
  b.setVal24(e.HasVariableStorage());
  b.setVal25(e.IsConsteval());
  b.setVal26(e.IsConstexpr());
  b.setVal58(e.IsNegatedConsteval());
  b.setVal59(e.IsNonNegatedConsteval());
  b.setVal60(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.GotoToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.Label()));
  auto t12 = e.LabelToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeForStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  auto v11 = e.Condition();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v12 = e.ConditionVariable();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto t15 = e.ForToken();
  b.setVal15(es.EntityId(t15));
  auto v18 = e.Increment();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto t20 = e.LParenToken();
  b.setVal20(es.EntityId(t20));
  auto t21 = e.RParenToken();
  b.setVal21(es.EntityId(t21));
}

void SerializeDoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto t12 = e.DoToken();
  b.setVal12(es.EntityId(t12));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
  auto t15 = e.WhileToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeDeclStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  do {
    auto v16 = e.Declarations();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto v10 = e.SingleDeclaration();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  b.setVal13(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Allocate()));
  b.setVal11(es.EntityId(e.Body()));
  b.setVal12(es.EntityId(e.Deallocate()));
  b.setVal14(es.EntityId(e.ExceptionHandler()));
  b.setVal15(es.EntityId(e.FallthroughHandler()));
  b.setVal18(es.EntityId(e.FinalSuspendStatement()));
  b.setVal19(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v16 = e.ParameterMoves();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal20(es.EntityId(e.PromiseDeclaration()));
  b.setVal21(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal22(es.EntityId(e.ReturnStatement()));
  b.setVal23(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal31(es.EntityId(e.ReturnValue()));
  b.setVal32(es.EntityId(e.ReturnValueInitializer()));
  b.setVal13(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.KeywordToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.Operand()));
  b.setVal12(es.EntityId(e.PromiseCall()));
  b.setVal13(e.IsImplicit());
}

void SerializeContinueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.ContinueToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeCompoundStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.LeftBraceToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.RightBraceToken();
  b.setVal11(es.EntityId(t11));
  auto v12 = e.StatementExpressionResult();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal13(e.HasStoredFPFeatures());
}

void SerializeCapturedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.CapturedDeclaration()));
  b.setVal11(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal12(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.TryBlock()));
  auto t11 = e.TryToken();
  b.setVal11(es.EntityId(t11));
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

void SerializeCXXForRangeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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
  auto v21 = e.Initializer();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  b.setVal22(es.EntityId(e.LoopVariableStatement()));
  b.setVal23(es.EntityId(e.LoopVariable()));
  auto t31 = e.RParenToken();
  b.setVal31(es.EntityId(t31));
  b.setVal32(es.EntityId(e.RangeInitializer()));
  b.setVal33(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.CatchToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.CaughtType()));
  auto v12 = e.ExceptionDeclaration();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal14(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.BreakToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal61(e.GenerateAssemblyString());
  auto t10 = e.AssemblyToken();
  b.setVal10(es.EntityId(t10));
  do {
    auto v16 = e.Inputs();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal13(e.IsSimple());
  b.setVal17(e.IsVolatile());
  do {
    auto v27 = e.Outputs();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
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
    auto v28 = e.OutputExpressions();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
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
    auto v29 = e.InputExpressions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
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

void SerializeMSAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
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
    auto v30 = e.AllExpressions();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  auto v66 = e.AssemblyString();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t11 = e.LBraceToken();
  b.setVal11(es.EntityId(t11));
  b.setVal24(e.HasBraces());
}

void SerializeGCCAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
  b.setVal11(es.EntityId(e.AssemblyString()));
  auto t12 = e.RParenToken();
  b.setVal12(es.EntityId(t12));
  b.setVal24(e.IsAssemblyGoto());
  do {
    auto v30 = e.Labels();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
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

void SerializeWhileStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto v12 = e.ConditionVariable();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto t15 = e.LParenToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.RParenToken();
  b.setVal18(es.EntityId(t18));
  auto t19 = e.WhileToken();
  b.setVal19(es.EntityId(t19));
  b.setVal13(e.HasVariableStorage());
}

void SerializeValueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v10 = e.ExpressionStatement();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  b.setVal11(es.EntityId(e.Declaration()));
  auto t12 = e.IdentifierToken();
  b.setVal12(es.EntityId(t12));
  auto v61 = e.Name();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal14(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsSideEntry());
}

void SerializeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  b.setVal13(e.HasSideEffects());
  b.setVal11(es.EntityId(e.IgnoreCasts()));
  b.setVal12(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal14(es.EntityId(e.IgnoreImplicitCasts()));
  b.setVal15(es.EntityId(e.IgnoreImplicit()));
  b.setVal18(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal19(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal20(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal21(es.EntityId(e.IgnoreParenthesisImplicitCasts()));
  b.setVal22(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal23(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal31(es.EntityId(e.IgnoreParentheses()));
  b.setVal32(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal17(e.ContainsErrors());
  b.setVal24(e.ContainsUnexpandedParameterPack());
  b.setVal33(es.EntityId(e.BestDynamicClassTypeExpression()));
  b.setVal57(static_cast<unsigned char>(mx::FromPasta(e.Dependence())));
  auto t34 = e.ExpressionToken();
  b.setVal34(es.EntityId(t34));
  auto v35 = e.ObjCProperty();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
  } else {
    b.setVal35(mx::kInvalidEntityId);
  }
  b.setVal70(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v36 = e.ReferencedDeclarationOfCallee();
  if (v36) {
    auto id36 = es.EntityId(v36.value());
    b.setVal36(id36);
  } else {
    b.setVal36(mx::kInvalidEntityId);
  }
  auto v37 = e.SourceBitField();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto v38 = e.Type();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal25(e.HasNonTrivialCall());
  auto v26 = e.IsCXX98IntegralConstantExpression();
  if (v26) {
    b.setVal26(static_cast<bool>(v26.value()));
    b.setVal58(true);
  } else {
    b.setVal58(false);
  }
  b.setVal59(e.IsDefaultArgument());
  b.setVal60(e.IsGLValue());
  b.setVal72(e.IsImplicitCXXThis());
  b.setVal73(e.IsInstantiationDependent());
  auto v74 = e.IsIntegerConstantExpression();
  if (v74) {
    b.setVal74(static_cast<bool>(v74.value()));
    b.setVal75(true);
  } else {
    b.setVal75(false);
  }
  b.setVal76(e.IsKnownToHaveBooleanValue());
  b.setVal77(e.IsLValue());
  b.setVal78(e.IsOBJCGCCandidate());
  b.setVal79(e.IsObjCSelfExpression());
  b.setVal80(e.IsOrdinaryOrBitFieldObject());
  b.setVal81(e.IsPRValue());
  b.setVal82(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal83(e.IsTypeDependent());
  b.setVal84(e.IsValueDependent());
  b.setVal85(e.IsXValue());
  b.setVal86(e.RefersToBitField());
  b.setVal87(e.RefersToGlobalRegisterVariable());
  b.setVal88(e.RefersToMatrixElement());
  b.setVal89(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.Designators();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
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
  b.setVal90(e.IsDirectInitializer());
  b.setVal91(e.UsesGNUSyntax());
  do {
    auto v27 = e.SubExpressions();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.TemplateKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.KeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Operand()));
  b.setVal41(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Declaration()));
  b.setVal40(es.EntityId(e.FoundDeclaration()));
  auto t41 = e.LAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal94(e.HasTemplateKeyword());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal96(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.CommonExpression()));
  auto t40 = e.KeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.OpaqueValue()));
  b.setVal42(es.EntityId(e.Operand()));
  b.setVal43(es.EntityId(e.ReadyExpression()));
  b.setVal44(es.EntityId(e.ResumeExpression()));
  b.setVal45(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
  b.setVal90(e.IsImplicit());
}

void SerializeCoyieldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SpecializationDeclaration()));
  do {
    auto v16 = e.TemplateArguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal90(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Initializer()));
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal90(e.IsFileScope());
}

void SerializeChooseExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.ChosenSubExpression()));
  b.setVal41(es.EntityId(e.Condition()));
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal90(e.IsConditionDependent());
  b.setVal91(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v61 = e.CastKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto v39 = e.ConversionFunction();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.SubExpressionAsWritten()));
  auto v42 = e.TargetUnionField();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  b.setVal90(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal91(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal43(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  if (auto r44 = e.AngleBrackets(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  auto v66 = e.CastName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.RParenToken();
  b.setVal47(es.EntityId(t47));
}

void SerializeCXXDynamicCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
  b.setVal91(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
}

void SerializeCXXAddrspaceCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
}

void SerializeCXXStaticCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
}

void SerializeCXXReinterpretCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
}

void SerializeCXXFunctionalCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal91(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeBuiltinBitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t44 = e.BridgeKeywordToken();
  b.setVal44(es.EntityId(t44));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v66 = e.BridgeKindName();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto t45 = e.LParenToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal39(es.EntityId(e.CallReturnType()));
  b.setVal40(es.EntityId(e.Callee()));
  auto v41 = e.CalleeDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.DirectCallee();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  auto v44 = e.UnusedResultAttribute();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.HasUnusedResultAttribute());
  b.setVal92(e.IsBuiltinAssumeFalse());
  b.setVal93(e.IsCallToStdMove());
  b.setVal94(e.IsUnevaluatedBuiltinCall());
  b.setVal96(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  b.setVal98(e.IsAssignmentOperation());
  b.setVal99(e.IsComparisonOperation());
  b.setVal100(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.ImplicitObjectArgument()));
  auto v46 = e.MethodDeclaration();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal47(es.EntityId(e.ObjectType()));
  b.setVal48(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.CookedLiteral()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t46 = e.UDSuffixToken();
  b.setVal46(es.EntityId(t46));
}

void SerializeCXXUuidofExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.GuidDeclaration()));
  b.setVal41(es.EntityId(e.TypeOperand()));
  b.setVal42(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal90(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
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
  b.setVal41(es.EntityId(e.TypeAsWritten()));
  b.setVal90(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.TypeOperand()));
  b.setVal41(es.EntityId(e.TypeOperandSourceInfo()));
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

void SerializeCXXThrowExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.SubExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto t40 = e.ThrowToken();
  b.setVal40(es.EntityId(t40));
  b.setVal90(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXRewrittenBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.SemanticForm()));
  b.setVal90(e.IsAssignmentOperation());
  b.setVal91(e.IsComparisonOperation());
  b.setVal92(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.ColonColonToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.DestroyedType()));
  auto t42 = e.DestroyedTypeToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  auto v44 = e.ScopeType();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto t45 = e.TildeToken();
  b.setVal45(es.EntityId(t45));
  b.setVal90(e.HasQualifier());
  b.setVal91(e.IsArrow());
}

void SerializeCXXParenListInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXParenListInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ArrayFiller()));
  auto t40 = e.InitializerToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.InitializedFieldInUnion()));
}

void SerializeCXXNullPtrLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeCXXNoexceptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal90(e.Value());
}

void SerializeCXXNewExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal39(es.EntityId(e.AllocatedType()));
  auto v40 = e.ArraySize();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto v41 = e.ConstructExpression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  if (auto r42 = e.DirectInitializerRange(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v44 = e.Initializer();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
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
  b.setVal91(e.HasInitializer());
  b.setVal92(e.IsArray());
  b.setVal93(e.IsGlobalNew());
  b.setVal94(e.IsParenthesisTypeId());
  b.setVal96(e.PassAlignment());
  do {
    auto v16 = e.PlacementArguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal98(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.ConstructsVirtualBase());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal39(es.EntityId(e.Constructor()));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  b.setVal91(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Callee()));
  auto t40 = e.EllipsisToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.Initializer()));
  b.setVal42(es.EntityId(e.LHS()));
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal44(es.EntityId(e.Pattern()));
  b.setVal45(es.EntityId(e.RHS()));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
  b.setVal90(e.IsLeftFold());
  b.setVal91(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.Base();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.BaseType()));
  auto v41 = e.FirstQualifierFoundInScope();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
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
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.DoesUsualArrayDeleteWantSize());
  b.setVal39(es.EntityId(e.Argument()));
  b.setVal40(es.EntityId(e.DestroyedType()));
  b.setVal41(es.EntityId(e.OperatorDelete()));
  b.setVal91(e.IsArrayForm());
  b.setVal92(e.IsArrayFormAsWritten());
  b.setVal93(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.Expression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.Field()));
  b.setVal41(es.EntityId(e.RewrittenExpression()));
  auto t42 = e.UsedToken();
  b.setVal42(es.EntityId(t42));
  b.setVal90(e.HasRewrittenInitializer());
}

void SerializeCXXDefaultArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AdjustedRewrittenExpression()));
  b.setVal40(es.EntityId(e.Expression()));
  b.setVal41(es.EntityId(e.Parameter()));
  b.setVal42(es.EntityId(e.RewrittenExpression()));
  auto t43 = e.UsedToken();
  b.setVal43(es.EntityId(t43));
  b.setVal90(e.HasRewrittenInitializer());
}

void SerializeCXXConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.IsElidable());
  b.setVal92(e.IsListInitialization());
  b.setVal93(e.IsStdInitializerListInitialization());
  b.setVal94(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  SerializeCXXConstructExpr(es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.Value());
}

void SerializeCXXBindTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.BlockDeclaration()));
  b.setVal40(es.EntityId(e.Body()));
  auto t41 = e.CaretToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v61 = e.OpcodeString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.IsAdditiveOperation());
  b.setVal92(e.IsAssignmentOperation());
  b.setVal93(e.IsBitwiseOperation());
  b.setVal94(e.IsCommaOperation());
  b.setVal96(e.IsComparisonOperation());
  b.setVal98(e.IsCompoundAssignmentOperation());
  b.setVal99(e.IsEqualityOperation());
  b.setVal100(e.IsLogicalOperation());
  b.setVal101(e.IsMultiplicativeOperation());
  b.setVal102(e.IsPointerMemoryOperation());
  b.setVal103(e.IsRelationalOperation());
  b.setVal104(e.IsShiftAssignOperation());
  b.setVal105(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  SerializeBinaryOperator(es, b, e, nullptr);
  b.setVal42(es.EntityId(e.ComputationLHSType()));
  b.setVal43(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal40(es.EntityId(e.Order()));
  auto v41 = e.OrderFail();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.Pointer()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  auto v44 = e.Scope();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto v45 = e.Value1();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto v46 = e.Value2();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal47(es.EntityId(e.ValueType()));
  auto v48 = e.Weak();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  b.setVal90(e.IsCmpXChg());
  b.setVal91(e.IsOpenCL());
  b.setVal92(e.IsVolatile());
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

void SerializeAsTypeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.DimensionExpression()));
  b.setVal40(es.EntityId(e.QueriedType()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  b.setVal41(es.EntityId(e.LHS()));
  auto t42 = e.RBracketToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.CommonExpression()));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AmpAmpToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Label()));
  auto t41 = e.LabelToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeAbstractConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.ColonToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.FalseExpression()));
  auto t42 = e.QuestionToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.LHS()));
  b.setVal45(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.Common()));
  b.setVal45(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal42(es.EntityId(e.WrittenType()));
  b.setVal90(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.CanOverflow());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal91(e.HasStoredFPFeatures());
  b.setVal92(e.IsArithmeticOperation());
  b.setVal93(e.IsDecrementOperation());
  b.setVal94(e.IsIncrementDecrementOperation());
  b.setVal96(e.IsIncrementOperation());
  b.setVal98(e.IsPostfix());
  b.setVal99(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.ArgumentExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.ArgumentType();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.TypeOfArgument()));
  b.setVal90(e.IsArgumentType());
}

void SerializeTypoExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v90 = e.Value();
  if (v90) {
    b.setVal90(static_cast<bool>(v90.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
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

void SerializeSubstNonTypeTemplateParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AssociatedDeclaration()));
  b.setVal40(es.EntityId(e.ParameterPack()));
  auto t41 = e.ParameterPackToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeSubstNonTypeTemplateParmExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AssociatedDeclaration()));
  auto t40 = e.NameToken();
  b.setVal40(es.EntityId(t40));
  auto v106 = e.PackIndex();
  if (v106) {
    b.setVal106(static_cast<unsigned>(v106.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal41(es.EntityId(e.Parameter()));
  b.setVal42(es.EntityId(e.ParameterType()));
  b.setVal43(es.EntityId(e.Replacement()));
  b.setVal91(e.IsReferenceParameter());
}

void SerializeStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal101(e.IsUTF8());
  b.setVal102(e.IsWide());
}

void SerializeStmtExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v61 = e.BuiltinString();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsIntType());
}

void SerializeSizeOfPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Pack()));
  auto v106 = e.PackLength();
  if (v106) {
    b.setVal106(static_cast<unsigned>(v106.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  auto t41 = e.PackToken();
  b.setVal41(es.EntityId(t41));
  do {
    auto ov16 = e.PartialArguments();
    if (!ov16) {
      b.setVal91(false);
      break;
    }
    b.setVal91(true);
    auto v16 = std::move(*ov16);
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal92(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.BuiltinToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeSYCLUniqueStableNameExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal61(e.ComputeName());
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeRequiresExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Body()));
  do {
    auto v16 = e.LocalParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t40 = e.RBraceToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RequiresKeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal90(e.IsSatisfied());
}

void SerializeRecoveryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializePseudoObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ResultExpression()));
  b.setVal40(es.EntityId(e.SyntacticForm()));
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
    auto v27 = e.SemanticExpressions();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
    }
  } while (false);
}

void SerializePredefinedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.FunctionName()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v61 = e.IdentifierKindName();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
}

void SerializeParenListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
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

void SerializeParenExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.EllipsisToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.LAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.NameToken();
  b.setVal40(es.EntityId(t40));
  auto v41 = e.NamingClass();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.Base()));
  b.setVal45(es.EntityId(e.BaseType()));
  auto t46 = e.MemberToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.OperatorToken();
  b.setVal47(es.EntityId(t47));
  b.setVal92(e.HasUnresolvedUsing());
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal92(e.IsOverloaded());
  b.setVal93(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SourceExpression()));
  b.setVal90(e.IsUnique());
}

void SerializeOffsetOfExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCSubscriptRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal40(es.EntityId(e.BaseExpression()));
  b.setVal41(es.EntityId(e.KeyExpression()));
  auto t42 = e.RBracketToken();
  b.setVal42(es.EntityId(t42));
  b.setVal90(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCProtocolExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Protocol()));
  auto t41 = e.ProtocolIdToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeObjCPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal90(e.IsClassReceiver());
  b.setVal91(e.IsExplicitProperty());
  b.setVal92(e.IsImplicitProperty());
  b.setVal93(e.IsMessagingGetter());
  b.setVal94(e.IsMessagingSetter());
  b.setVal96(e.IsObjectReceiver());
  b.setVal98(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal39(es.EntityId(e.CallReturnType()));
  b.setVal40(es.EntityId(e.ClassReceiver()));
  b.setVal41(es.EntityId(e.ClassReceiverType()));
  b.setVal42(es.EntityId(e.InstanceReceiver()));
  auto t43 = e.LeftToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.MethodDeclaration()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal45(es.EntityId(e.ReceiverInterface()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  b.setVal90(e.IsClassMessage());
  b.setVal91(e.IsDelegateInitializerCall());
  b.setVal92(e.IsImplicit());
  b.setVal93(e.IsInstanceMessage());
  do {
    auto v27 = e.SelectorTokens();
    auto sv27 = b.initVal27(static_cast<unsigned>(v27.size()));
    auto i27 = 0u;
    for (const auto &e27 : v27) {
      sv27.set(i27, es.EntityId(e27));
      ++i27;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Declaration()));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperationToken();
  b.setVal42(es.EntityId(t42));
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto t40 = e.BaseTokenEnd();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.IsaMemberToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.OperationToken();
  b.setVal42(es.EntityId(t42));
  b.setVal90(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal90(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.EncodedType()));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeObjCDictionaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.AtToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.BoxingMethod()));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.HasVersion());
}

void SerializeObjCArrayLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ArrayWithObjectsMethod()));
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

void SerializeOMPIteratorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.IteratorKwToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeOMPArrayShapingExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  do {
    auto v16 = e.Dimensions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto t40 = e.LParenToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeOMPArraySectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeNoInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal90(e.HadMultipleCandidates());
  b.setVal91(e.HasExplicitTemplateArguments());
  b.setVal92(e.HasQualifier());
  b.setVal93(e.HasTemplateKeyword());
  b.setVal94(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.ColumnIndex()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.RowIndex()));
  b.setVal90(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.ExtendingDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.LifetimeExtendedTemporaryDeclaration();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal90(e.IsBoundToLvalueReference());
  b.setVal91(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeMSPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.BaseExpression()));
  auto t40 = e.MemberToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.PropertyDeclaration()));
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Body()));
  b.setVal40(es.EntityId(e.CallOperator()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t41 = e.CaptureDefaultToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.CompoundStatementBody()));
  auto v43 = e.DependentCallOperator();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  do {
    auto v16 = e.ExplicitTemplateParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  if (auto r44 = e.IntroducerRange(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal46(es.EntityId(e.LambdaClass()));
  auto v47 = e.TemplateParameterList();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  auto v48 = e.TrailingRequiresClause();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  b.setVal90(e.HasExplicitParameters());
  b.setVal91(e.HasExplicitResultType());
  b.setVal92(e.IsGenericLambda());
  b.setVal93(e.IsMutable());
}

void SerializeIntegerLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeInitListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v39 = e.ArrayFiller();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.InitializedFieldInUnion();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto t41 = e.LBraceToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RBraceToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.SemanticForm();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto v44 = e.SyntacticForm();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal90(e.HadArrayRangeDesignator());
  b.setVal91(e.HasArrayFiller());
  do {
    auto v16 = e.Initializers();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
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

void SerializeImplicitValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v16 = e.AssociationExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
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
  b.setVal90(e.IsResultDependent());
}

void SerializeGNUNullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.TokenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeFunctionParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ParameterPack()));
  auto t40 = e.ParameterPackToken();
  b.setVal40(es.EntityId(t40));
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

void SerializeFullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal90(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal90(e.HasAPValueResult());
  b.setVal91(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal90(e.IsExact());
}

void SerializeFixedPointLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeExtVectorElementExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal90(e.ContainsDuplicateElements());
  auto t39 = e.AccessorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Base()));
  b.setVal91(e.IsArrow());
}

void SerializeExpressionTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal39(es.EntityId(e.QueriedExpression()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal90(e.Value());
}

void SerializeAttributedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  auto t11 = e.AttributeToken();
  b.setVal11(es.EntityId(t11));
  do {
    auto v16 = e.Attributes();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal12(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto v12 = e.ConditionVariable();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v15 = e.Initializer();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
  } else {
    b.setVal15(mx::kInvalidEntityId);
  }
  auto t18 = e.LParenToken();
  b.setVal18(es.EntityId(t18));
  auto t19 = e.RParenToken();
  b.setVal19(es.EntityId(t19));
  auto v20 = e.FirstSwitchCase();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  auto t21 = e.SwitchToken();
  b.setVal21(es.EntityId(t21));
  b.setVal13(e.HasInitializerStorage());
  b.setVal17(e.HasVariableStorage());
  b.setVal24(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t10 = e.ColonToken();
  b.setVal10(es.EntityId(t10));
  auto t11 = e.KeywordToken();
  b.setVal11(es.EntityId(t11));
  auto v12 = e.NextSwitchCase();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal14(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
  auto t15 = e.DefaultToken();
  b.setVal15(es.EntityId(t15));
}

void SerializeCaseStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
  b.setVal13(e.CaseStatementIsGNURange());
  auto t15 = e.CaseToken();
  b.setVal15(es.EntityId(t15));
  auto t18 = e.EllipsisToken();
  b.setVal18(es.EntityId(t18));
  b.setVal19(es.EntityId(e.LHS()));
  auto v20 = e.RHS();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
}

void SerializeDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e, const TokenTree *) {
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
  auto v7 = e.DescribedTemplate();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  auto v8 = e.DescribedTemplateParameters();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.ExternalSourceSymbolAttribute();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v11 = e.MaxAlignment();
  if (v11) {
    b.setVal11(static_cast<unsigned>(v11.value()));
    b.setVal12(true);
  } else {
    b.setVal12(false);
  }
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v14 = e.NonClosureContext();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  b.setVal15(e.HasAttributes());
  b.setVal16(e.HasOwningModule());
  b.setVal17(e.HasTagIdentifierNamespace());
  b.setVal18(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal19(e.IsDeprecated());
  b.setVal20(e.IsDiscardedInGlobalModuleFragment());
  b.setVal21(e.IsFileContextDeclaration());
  b.setVal22(e.IsFunctionOrFunctionTemplate());
  b.setVal23(e.IsImplicit());
  b.setVal24(e.IsInAnonymousNamespace());
  b.setVal25(e.IsInExportDeclarationContext());
  auto v26 = e.IsInLocalScopeForInstantiation();
  if (v26) {
    b.setVal26(static_cast<bool>(v26.value()));
    b.setVal27(true);
  } else {
    b.setVal27(false);
  }
  b.setVal28(e.IsInStdNamespace());
  b.setVal29(e.IsInvalidDeclaration());
  b.setVal30(e.IsInvisibleOutsideTheOwningModule());
  b.setVal31(e.IsLocalExternDeclaration());
  b.setVal32(e.IsModulePrivate());
  b.setVal33(e.IsOutOfLine());
  b.setVal34(e.IsParameterPack());
  b.setVal35(e.IsReachable());
  b.setVal36(e.IsTemplateDeclaration());
  b.setVal37(e.IsTemplateParameter());
  b.setVal38(e.IsTemplateParameterPack());
  b.setVal39(e.IsTemplated());
  b.setVal40(e.IsThisDeclarationReferenced());
  b.setVal41(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal42(e.IsUnavailable());
  b.setVal43(e.IsUnconditionallyVisible());
  b.setVal44(e.IsWeakImported());
  b.setVal45(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal46(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto t47 = e.Token();
  b.setVal47(es.EntityId(t47));
  if (auto r48 = e.Tokens(); auto rs48 = r48.Size()) {
    b.setVal48(es.EntityId(r48[0]));
    b.setVal49(es.EntityId(r48[rs48 - 1u]));
  } else {
    b.setVal48(0);
    b.setVal49(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.Specialization()));
  b.setVal51(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.ContextParameter()));
  b.setVal51(e.IsNothrow());
  do {
    auto v52 = e.Parameters();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
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

void SerializeBlockDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal51(e.BlockMissingReturnType());
  b.setVal54(e.CanAvoidCopyToHeap());
  b.setVal55(e.CapturesCXXThis());
  b.setVal56(e.DoesNotEscape());
  auto v50 = e.BlockManglingContextDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  auto t57 = e.CaretToken();
  b.setVal57(es.EntityId(t57));
  b.setVal58(es.EntityId(e.CompoundBody()));
  b.setVal59(es.EntityId(e.SignatureAsWritten()));
  b.setVal60(e.HasCaptures());
  b.setVal61(e.IsConversionFromLambda());
  b.setVal62(e.IsVariadic());
  do {
    auto v52 = e.Parameters();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v53 = e.ParameterDeclarations();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  pasta::DeclContext dc63(e);
  auto v63 = dc63.AlreadyLoadedDeclarations();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const pasta::Decl &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeAccessSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t50 = e.AccessSpecifierToken();
  b.setVal50(es.EntityId(t50));
  auto t57 = e.ColonToken();
  b.setVal57(es.EntityId(t57));
}

void SerializeOMPDeclarativeDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
}

void SerializeOMPThreadPrivateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Varlists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeOMPRequiresDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e, nullptr);
}

void SerializeOMPAllocateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Varlists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeTopLevelStmtDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.Statement()));
}

void SerializeStaticAssertDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.AssertExpression()));
  b.setVal57(es.EntityId(e.Message()));
  auto t58 = e.RParenToken();
  b.setVal58(es.EntityId(t58));
  b.setVal51(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializePragmaDetectMismatchDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v64 = e.Name();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto v65 = e.Value();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
}

void SerializePragmaCommentDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v64 = e.Argument();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.GetterCXXConstructor()));
  b.setVal57(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal58(es.EntityId(e.PropertyDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal59(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t67 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal67(es.EntityId(t67));
  b.setVal68(es.EntityId(e.SetterCXXAssignment()));
  b.setVal69(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal51(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal64(e.Name());
  auto v70 = e.ObjCFStringFormattingFamily();
  if (v70) {
    b.setVal70(static_cast<unsigned char>(v70.value()));
    b.setVal51(true);
  } else {
    b.setVal51(false);
  }
  b.setVal65(e.QualifiedNameAsString());
  b.setVal50(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal71(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal54(e.HasExternalFormalLinkage());
  b.setVal55(e.HasLinkage());
  b.setVal56(e.HasLinkageBeenComputed());
  b.setVal60(e.IsCXXClassMember());
  b.setVal61(e.IsCXXInstanceMember());
  b.setVal62(e.IsExternallyDeclarable());
  b.setVal72(e.IsExternallyVisible());
  b.setVal73(e.IsLinkageValid());
}

void SerializeLabelDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v74 = e.MSAssemblyLabel();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal57(es.EntityId(e.Statement()));
  b.setVal75(e.IsGnuLocal());
  b.setVal76(e.IsMSAssemblyLabel());
  b.setVal77(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t57 = e.LBraceToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.TokenStart();
  b.setVal58(es.EntityId(t58));
  auto t59 = e.RBraceToken();
  b.setVal59(es.EntityId(t59));
  b.setVal75(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Shadows();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeUsingEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  b.setVal57(es.EntityId(e.EnumDeclaration()));
  auto t58 = e.EnumToken();
  b.setVal58(es.EntityId(t58));
  b.setVal59(es.EntityId(e.EnumType()));
  auto t67 = e.UsingToken();
  b.setVal67(es.EntityId(t67));
}

void SerializeUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  auto t57 = e.UsingToken();
  b.setVal57(es.EntityId(t57));
  b.setVal75(e.HasTypename());
  b.setVal76(e.IsAccessDeclaration());
}

void SerializeValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v57 = e.PotentiallyDecomposedVariableDeclaration();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
  b.setVal58(es.EntityId(e.Type()));
  b.setVal75(e.IsInitializerCapture());
  b.setVal76(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto t59 = e.EllipsisToken();
  b.setVal59(es.EntityId(t59));
  auto t67 = e.UsingToken();
  b.setVal67(es.EntityId(t67));
  b.setVal77(e.IsAccessDeclaration());
  b.setVal78(e.IsPackExpansion());
}

void SerializeUnnamedGlobalConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnnamedGlobalConstantDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
}

void SerializeTemplateParamObjectDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
}

void SerializeOMPDeclareReductionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  b.setVal59(es.EntityId(e.Combiner()));
  b.setVal67(es.EntityId(e.CombinerIn()));
  b.setVal68(es.EntityId(e.CombinerOut()));
  b.setVal69(es.EntityId(e.InitializerOriginal()));
  b.setVal79(es.EntityId(e.InitializerPrivate()));
  b.setVal80(es.EntityId(e.Initializer()));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeMSGuidDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
}

void SerializeIndirectFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Chain();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  auto v59 = e.AnonymousField();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
  auto v67 = e.VariableDeclaration();
  if (v67) {
    auto id67 = es.EntityId(v67.value());
    b.setVal67(id67);
  } else {
    b.setVal67(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto v59 = e.InitializerExpression();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto t59 = e.FirstInnerToken();
  b.setVal59(es.EntityId(t59));
  auto t67 = e.FirstOuterToken();
  b.setVal67(es.EntityId(t67));
  auto v68 = e.TrailingRequiresClause();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
  } else {
    b.setVal68(mx::kInvalidEntityId);
  }
  auto t69 = e.TypeSpecEndToken();
  b.setVal69(es.EntityId(t69));
  auto t79 = e.TypeSpecStartToken();
  b.setVal79(es.EntityId(t79));
  do {
    auto v52 = e.TemplateParameterLists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v80 = e.ActingDefinition();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v82 = e.DescribedVariableTemplate();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v83 = e.Initializer();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v84 = e.InitializingDeclaration();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v85 = e.InstantiatedFromStaticDataMember();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t87 = e.PointOfInstantiation();
  b.setVal87(es.EntityId(t87));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v92 = e.TemplateInstantiationPattern();
  if (v92) {
    auto id92 = es.EntityId(v92.value());
    b.setVal92(id92);
  } else {
    b.setVal92(mx::kInvalidEntityId);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal77(e.HasConstantInitialization());
  b.setVal78(e.HasDependentAlignment());
  b.setVal95(e.HasExternalStorage());
  auto v96 = e.HasFlexibleArrayInitializer();
  if (v96) {
    b.setVal96(static_cast<bool>(v96.value()));
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
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
  b.setVal114(e.IsInline());
  b.setVal115(e.IsInlineSpecified());
  b.setVal116(e.IsKnownToBeDefined());
  b.setVal117(e.IsLocalVariableDeclaration());
  b.setVal118(e.IsLocalVariableDeclarationOrParm());
  b.setVal119(e.IsNRVOVariable());
  b.setVal120(e.IsNoDestroy());
  b.setVal121(e.IsNonEscapingByref());
  b.setVal122(e.IsObjCForDeclaration());
  b.setVal123(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal124(e.IsStaticDataMember());
  b.setVal125(e.IsStaticLocal());
  b.setVal126(e.IsThisDeclarationADemotedDefinition());
  b.setVal127(e.IsUsableInConstantExpressions());
  b.setVal128(e.MightBeUsableInConstantExpressions());
}

void SerializeParmVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  auto v129 = e.DefaultArgument();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  if (auto r130 = e.DefaultArgumentRange(); auto rs130 = r130.Size()) {
    b.setVal130(es.EntityId(r130[0]));
    b.setVal131(es.EntityId(r130[rs130 - 1u]));
  } else {
    b.setVal130(0);
    b.setVal131(0);
  }
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal133(es.EntityId(e.OriginalType()));
  auto v134 = e.UninstantiatedDefaultArgument();
  if (v134) {
    auto id134 = es.EntityId(v134.value());
    b.setVal134(id134);
  } else {
    b.setVal134(mx::kInvalidEntityId);
  }
  b.setVal135(e.HasDefaultArgument());
  b.setVal136(e.HasInheritedDefaultArgument());
  b.setVal137(e.HasUninstantiatedDefaultArgument());
  b.setVal138(e.HasUnparsedDefaultArgument());
  b.setVal139(e.IsDestroyedInCallee());
  b.setVal140(e.IsKNRPromoted());
  b.setVal141(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
}

void SerializeImplicitParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
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

void SerializeVarTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  auto t129 = e.ExternToken();
  b.setVal129(es.EntityId(t129));
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal130(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v53 = e.TemplateArguments();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  do {
    auto v63 = e.TemplateInstantiationArguments();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      sv63.set(i63, es.EntityId(e63));
      ++i63;
    }
  } while (false);
  auto t131 = e.TemplateKeywordToken();
  b.setVal131(es.EntityId(t131));
  b.setVal133(es.EntityId(e.TypeAsWritten()));
  b.setVal135(e.IsClassScopeExplicitSpecialization());
  b.setVal136(e.IsExplicitInstantiationOrSpecialization());
  b.setVal137(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal134(es.EntityId(e.InstantiatedFromMember()));
  b.setVal142(es.EntityId(e.TemplateParameters()));
  b.setVal138(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal77(e.DefaultArgumentWasInherited());
  auto v80 = e.DefaultArgument();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto t82 = e.DefaultArgumentToken();
  b.setVal82(es.EntityId(t82));
  auto v83 = e.PlaceholderTypeConstraint();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  b.setVal78(e.HasDefaultArgument());
  b.setVal95(e.HasPlaceholderTypeConstraint());
  b.setVal96(e.IsExpandedParameterPack());
  b.setVal97(e.IsPackExpansion());
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

void SerializeMSPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal77(e.HasGetter());
  b.setVal78(e.HasSetter());
}

void SerializeFunctionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal77(e.FriendConstraintRefersToEnclosingTemplate());
  b.setVal78(e.UsesFPIntrin());
  auto v95 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal97(e.DoesThisDeclarationHaveABody());
  b.setVal80(es.EntityId(e.CallResultType()));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal82(es.EntityId(e.DeclaredReturnType()));
  auto t83 = e.DefaultToken();
  b.setVal83(es.EntityId(t83));
  auto v84 = e.DescribedFunctionTemplate();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto t85 = e.EllipsisToken();
  b.setVal85(es.EntityId(t85));
  if (auto r87 = e.ExceptionSpecSourceRange(); auto rs87 = r87.Size()) {
    b.setVal87(es.EntityId(r87[0]));
    b.setVal92(es.EntityId(r87[rs87 - 1u]));
  } else {
    b.setVal87(0);
    b.setVal92(0);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v129 = e.InstantiatedFromDeclaration();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  auto v130 = e.InstantiatedFromMemberFunction();
  if (v130) {
    auto id130 = es.EntityId(v130.value());
    b.setVal130(id130);
  } else {
    b.setVal130(mx::kInvalidEntityId);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v143 = e.ODRHash();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r131 = e.ParametersSourceRange(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal133(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal133(0);
  }
  auto t134 = e.PointOfInstantiation();
  b.setVal134(es.EntityId(t134));
  auto v142 = e.PrimaryTemplate();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
  } else {
    b.setVal142(mx::kInvalidEntityId);
  }
  b.setVal144(es.EntityId(e.ReturnType()));
  if (auto r145 = e.ReturnTypeSourceRange(); auto rs145 = r145.Size()) {
    b.setVal145(es.EntityId(r145[0]));
    b.setVal146(es.EntityId(r145[rs145 - 1u]));
  } else {
    b.setVal145(0);
    b.setVal146(0);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v147 = e.TemplateInstantiationPattern();
  if (v147) {
    auto id147 = es.EntityId(v147.value());
    b.setVal147(id147);
  } else {
    b.setVal147(mx::kInvalidEntityId);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal99(e.HasImplicitReturnZero());
  b.setVal100(e.HasInheritedPrototype());
  b.setVal101(e.HasOneParameterOrDefaultArguments());
  b.setVal102(e.HasPrototype());
  b.setVal103(e.HasSkippedBody());
  b.setVal104(e.HasTrivialBody());
  b.setVal105(e.HasWrittenPrototype());
  b.setVal106(e.InstantiationIsPending());
  b.setVal107(e.IsCPUDispatchMultiVersion());
  b.setVal108(e.IsCPUSpecificMultiVersion());
  b.setVal109(e.IsConsteval());
  b.setVal110(e.IsConstexpr());
  b.setVal111(e.IsConstexprSpecified());
  b.setVal112(e.IsDefaulted());
  b.setVal113(e.IsDeleted());
  b.setVal114(e.IsDeletedAsWritten());
  b.setVal115(e.IsDestroyingOperatorDelete());
  b.setVal116(e.IsExplicitlyDefaulted());
  b.setVal117(e.IsExternC());
  b.setVal118(e.IsFunctionTemplateSpecialization());
  b.setVal119(e.IsGlobal());
  b.setVal120(e.IsImplicitlyInstantiable());
  b.setVal121(e.IsInExternCContext());
  b.setVal122(e.IsInExternCXXContext());
  b.setVal123(e.IsIneligibleOrNotSelected());
  b.setVal124(e.IsInlineBuiltinDeclaration());
  auto v125 = e.IsInlineDefinitionExternallyVisible();
  if (v125) {
    b.setVal125(static_cast<bool>(v125.value()));
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  b.setVal127(e.IsInlineSpecified());
  b.setVal128(e.IsInlined());
  b.setVal135(e.IsLateTemplateParsed());
  auto v136 = e.IsMSExternInline();
  if (v136) {
    b.setVal136(static_cast<bool>(v136.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  b.setVal138(e.IsMSVCRTEntryPoint());
  b.setVal139(e.IsMain());
  b.setVal140(e.IsMultiVersion());
  b.setVal141(e.IsNoReturn());
  b.setVal148(e.IsOverloadedOperator());
  b.setVal149(e.IsPure());
  b.setVal150(e.IsReplaceableGlobalAllocationFunction());
  auto v151 = e.IsReservedGlobalPlacementOperator();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  b.setVal153(e.IsStatic());
  b.setVal154(e.IsTargetClonesMultiVersion());
  b.setVal155(e.IsTargetMultiVersion());
  b.setVal156(e.IsTemplateInstantiation());
  b.setVal157(e.IsThisDeclarationADefinition());
  b.setVal158(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal159(e.IsTrivial());
  b.setVal160(e.IsTrivialForCall());
  b.setVal161(e.IsUserProvided());
  b.setVal162(e.IsVariadic());
  b.setVal163(e.IsVirtualAsWritten());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  b.setVal164(e.UsesSEHTry());
  b.setVal165(e.WillHaveBody());
  auto v166 = e.Body();
  if (v166) {
    auto id166 = es.EntityId(v166.value());
    b.setVal166(id166);
  } else {
    b.setVal166(mx::kInvalidEntityId);
  }
  pasta::DeclContext dc63(e);
  auto v63 = dc63.AlreadyLoadedDeclarations();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const pasta::Decl &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeCXXMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal167(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v168 = e.ThisObjectType();
  if (v168) {
    auto id168 = es.EntityId(v168.value());
    b.setVal168(id168);
  } else {
    b.setVal168(mx::kInvalidEntityId);
  }
  auto v169 = e.ThisType();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
  } else {
    b.setVal169(mx::kInvalidEntityId);
  }
  b.setVal170(e.HasInlineBody());
  b.setVal171(e.IsConst());
  b.setVal172(e.IsCopyAssignmentOperator());
  b.setVal173(e.IsInstance());
  b.setVal174(e.IsLambdaStaticInvoker());
  b.setVal175(e.IsMoveAssignmentOperator());
  b.setVal176(e.IsVirtual());
  b.setVal177(e.IsVolatile());
  do {
    auto v178 = e.OverriddenMethods();
    auto sv178 = b.initVal178(static_cast<unsigned>(v178.size()));
    auto i178 = 0u;
    for (const auto &e178 : v178) {
      sv178.set(i178, es.EntityId(e178));
      ++i178;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  auto v179 = e.OperatorDelete();
  if (v179) {
    auto id179 = es.EntityId(v179.value());
    b.setVal179(id179);
  } else {
    b.setVal179(mx::kInvalidEntityId);
  }
  auto v180 = e.OperatorDeleteThisArgument();
  if (v180) {
    auto id180 = es.EntityId(v180.value());
    b.setVal180(id180);
  } else {
    b.setVal180(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  b.setVal179(es.EntityId(e.ConversionType()));
  b.setVal181(e.IsExplicit());
  b.setVal182(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  auto v179 = e.TargetConstructor();
  if (v179) {
    auto id179 = es.EntityId(v179.value());
    b.setVal179(id179);
  } else {
    b.setVal179(mx::kInvalidEntityId);
  }
  b.setVal181(e.IsDefaultConstructor());
  b.setVal182(e.IsDelegatingConstructor());
  b.setVal183(e.IsExplicit());
  b.setVal184(e.IsInheritingConstructor());
  b.setVal185(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal168(es.EntityId(e.CorrespondingConstructor()));
  b.setVal169(es.EntityId(e.DeducedTemplate()));
  b.setVal170(e.IsCopyDeductionCandidate());
  b.setVal171(e.IsExplicit());
}

void SerializeFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v80 = e.BitWidth();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v82 = e.CapturedVLAType();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v83 = e.InClassInitializer();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  b.setVal77(e.HasCapturedVLAType());
  b.setVal78(e.HasInClassInitializer());
  b.setVal95(e.IsAnonymousStructOrUnion());
  b.setVal96(e.IsBitField());
  b.setVal97(e.IsMutable());
  b.setVal98(e.IsUnnamedBitfield());
  b.setVal99(e.IsZeroLengthBitField());
  b.setVal100(e.IsZeroSize());
}

void SerializeObjCIvarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e, nullptr);
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal84(es.EntityId(e.ContainingInterface()));
  b.setVal85(es.EntityId(e.NextInstanceVariable()));
  b.setVal101(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e, nullptr);
}

void SerializeBindingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  b.setVal59(es.EntityId(e.Binding()));
  b.setVal67(es.EntityId(e.DecomposedDeclaration()));
  b.setVal68(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
}

void SerializeOMPDeclareMapperDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveValueDecl(es, b, e, nullptr);
  b.setVal59(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal57(es.EntityId(e.Introducer()));
  auto v58 = e.NextUsingShadowDeclaration();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
  } else {
    b.setVal58(mx::kInvalidEntityId);
  }
  b.setVal59(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e, nullptr);
  b.setVal75(e.ConstructsVirtualBase());
  b.setVal67(es.EntityId(e.ConstructedBaseClass()));
  auto v68 = e.ConstructedBaseClassShadowDeclaration();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
  } else {
    b.setVal68(mx::kInvalidEntityId);
  }
  b.setVal69(es.EntityId(e.NominatedBaseClass()));
  auto v79 = e.NominatedBaseClassShadowDeclaration();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Expansions();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  b.setVal57(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t57 = e.IdentifierToken();
  b.setVal57(es.EntityId(t57));
  auto t58 = e.NamespaceKeyToken();
  b.setVal58(es.EntityId(t58));
  b.setVal59(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t67 = e.UsingToken();
  b.setVal67(es.EntityId(t67));
}

void SerializeUnresolvedUsingIfExistsDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
}

void SerializeTypeDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v57 = e.TypeForDeclaration();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  b.setVal75(e.DefaultArgumentWasInherited());
  auto v58 = e.DefaultArgument();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
  } else {
    b.setVal58(mx::kInvalidEntityId);
  }
  auto v59 = e.DefaultArgumentInfo();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
  auto t67 = e.DefaultArgumentToken();
  b.setVal67(es.EntityId(t67));
  b.setVal76(e.HasDefaultArgument());
  b.setVal77(e.HasTypeConstraint());
  b.setVal78(e.IsExpandedParameterPack());
  b.setVal95(e.IsPackExpansion());
  b.setVal96(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  if (auto r58 = e.BraceRange(); auto rs58 = r58.Size()) {
    b.setVal58(es.EntityId(r58[0]));
    b.setVal59(es.EntityId(r58[rs58 - 1u]));
  } else {
    b.setVal58(0);
    b.setVal59(0);
  }
  auto t67 = e.FirstInnerToken();
  b.setVal67(es.EntityId(t67));
  auto t68 = e.FirstOuterToken();
  b.setVal68(es.EntityId(t68));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v69 = e.TypedefNameForAnonymousDeclaration();
  if (v69) {
    auto id69 = es.EntityId(v69.value());
    b.setVal69(id69);
  } else {
    b.setVal69(mx::kInvalidEntityId);
  }
  b.setVal75(e.HasNameForLinkage());
  b.setVal76(e.IsBeingDefined());
  b.setVal77(e.IsClass());
  b.setVal78(e.IsCompleteDefinition());
  b.setVal95(e.IsCompleteDefinitionRequired());
  b.setVal96(e.IsDependentType());
  b.setVal97(e.IsEmbeddedInDeclarator());
  b.setVal98(e.IsEnum());
  b.setVal99(e.IsFreeStanding());
  b.setVal100(e.IsInterface());
  b.setVal101(e.IsStruct());
  b.setVal102(e.IsThisDeclarationADefinition());
  b.setVal103(e.IsThisDeclarationADemotedDefinition());
  b.setVal104(e.IsUnion());
  b.setVal105(e.MayHaveOutOfDateDefinition());
  do {
    auto v52 = e.TemplateParameterLists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
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

void SerializeRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  b.setVal106(e.CanPassInRegisters());
  do {
    auto v63 = e.Fields();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      sv63.set(i63, es.EntityId(e63));
      ++i63;
    }
  } while (false);
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal107(e.HasFlexibleArrayMember());
  b.setVal108(e.HasLoadedFieldsFromExternalStorage());
  b.setVal109(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal110(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal111(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal112(e.HasObjectMember());
  b.setVal113(e.HasVolatileMember());
  b.setVal114(e.IsAnonymousStructOrUnion());
  b.setVal115(e.IsCapturedRecord());
  b.setVal116(e.IsInjectedClassName());
  b.setVal117(e.IsLambda());
  b.setVal118(e.IsMsStruct());
  b.setVal119(e.IsNonTrivialToPrimitiveCopy());
  b.setVal120(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal121(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal122(e.IsOrContainsUnion());
  b.setVal123(e.IsParameterDestroyedInCallee());
  b.setVal124(e.IsRandomized());
  b.setVal125(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e, nullptr);
  auto v126 = e.AllowConstDefaultInitializer();
  if (v126) {
    b.setVal126(static_cast<bool>(v126.value()));
    b.setVal127(true);
  } else {
    b.setVal127(false);
  }
  do {
    auto ov178 = e.Bases();
    if (!ov178) {
      b.setVal128(false);
      break;
    }
    b.setVal128(true);
    auto v178 = std::move(*ov178);
    auto sv178 = b.initVal178(static_cast<unsigned>(v178.size()));
    auto i178 = 0u;
    for (const auto &e178 : v178) {
      sv178.set(i178, es.EntityId(e178));
      ++i178;
    }
  } while (false);
  auto v88 = e.CalculateInheritanceModel();
  if (v88) {
    b.setVal88(static_cast<unsigned char>(v88.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  do {
    auto v186 = e.Constructors();
    auto sv186 = b.initVal186(static_cast<unsigned>(v186.size()));
    auto i186 = 0u;
    for (const auto &e186 : v186) {
      sv186.set(i186, es.EntityId(e186));
      ++i186;
    }
  } while (false);
  do {
    auto ov187 = e.Friends();
    if (!ov187) {
      b.setVal136(false);
      break;
    }
    b.setVal136(true);
    auto v187 = std::move(*ov187);
    auto sv187 = b.initVal187(static_cast<unsigned>(v187.size()));
    auto i187 = 0u;
    for (const auto &e187 : v187) {
      sv187.set(i187, es.EntityId(e187));
      ++i187;
    }
  } while (false);
  auto v79 = e.DependentLambdaCallOperator();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v80 = e.DescribedClassTemplate();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v82 = e.Destructor();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v83 = e.GenericLambdaTemplateParameterList();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  auto v84 = e.InstantiatedFromMemberClass();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v85 = e.LambdaCallOperator();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  auto v89 = e.LambdaCaptureDefault();
  if (v89) {
    b.setVal89(static_cast<unsigned char>(v89.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  auto v87 = e.LambdaContextDeclaration();
  if (v87) {
    auto id87 = es.EntityId(v87.value());
    b.setVal87(id87);
  } else {
    b.setVal87(mx::kInvalidEntityId);
  }
  do {
    auto ov188 = e.LambdaExplicitTemplateParameters();
    if (!ov188) {
      b.setVal138(false);
      break;
    }
    b.setVal138(true);
    auto v188 = std::move(*ov188);
    auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
    auto i188 = 0u;
    for (const auto &e188 : v188) {
      sv188.set(i188, es.EntityId(e188));
      ++i188;
    }
  } while (false);
  auto v143 = e.LambdaManglingNumber();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  auto v92 = e.LambdaType();
  if (v92) {
    auto id92 = es.EntityId(v92.value());
    b.setVal92(id92);
  } else {
    b.setVal92(mx::kInvalidEntityId);
  }
  auto v90 = e.MSInheritanceModel();
  if (v90) {
    b.setVal90(static_cast<unsigned char>(v90.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v189 = e.ODRHash();
  if (v189) {
    b.setVal189(static_cast<unsigned>(v189.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v129 = e.TemplateInstantiationPattern();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
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
    b.setVal157(true);
  } else {
    b.setVal157(false);
  }
  auto v158 = e.HasCopyConstructorWithConstParameter();
  if (v158) {
    b.setVal158(static_cast<bool>(v158.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v160 = e.HasDefaultConstructor();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
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
  auto v170 = e.HasFriends();
  if (v170) {
    b.setVal170(static_cast<bool>(v170.value()));
    b.setVal171(true);
  } else {
    b.setVal171(false);
  }
  auto v172 = e.HasInClassInitializer();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasInheritedAssignment();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v176 = e.HasInheritedConstructor();
  if (v176) {
    b.setVal176(static_cast<bool>(v176.value()));
    b.setVal177(true);
  } else {
    b.setVal177(false);
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
  auto v130 = e.IsLocalClass();
  if (v130) {
    auto id130 = es.EntityId(v130.value());
    b.setVal130(id130);
  } else {
    b.setVal130(mx::kInvalidEntityId);
  }
  b.setVal295(e.IsNeverDependentLambda());
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
    auto ov342 = e.VirtualBases();
    if (!ov342) {
      b.setVal343(false);
      break;
    }
    b.setVal343(true);
    auto v342 = std::move(*ov342);
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e, nullptr);
  auto t131 = e.ExternToken();
  b.setVal131(es.EntityId(t131));
  auto t133 = e.PointOfInstantiation();
  b.setVal133(es.EntityId(t133));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal134(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v344 = e.TemplateArguments();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
  do {
    auto v345 = e.TemplateInstantiationArguments();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
  auto t142 = e.TemplateKeywordToken();
  b.setVal142(es.EntityId(t142));
  auto v144 = e.TypeAsWritten();
  if (v144) {
    auto id144 = es.EntityId(v144.value());
    b.setVal144(id144);
  } else {
    b.setVal144(mx::kInvalidEntityId);
  }
  b.setVal346(e.IsClassScopeExplicitSpecialization());
  b.setVal347(e.IsExplicitInstantiationOrSpecialization());
  b.setVal348(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal145(es.EntityId(e.InjectedSpecializationType()));
  b.setVal146(es.EntityId(e.InstantiatedFromMember()));
  b.setVal147(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal166(es.EntityId(e.TemplateParameters()));
  b.setVal349(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  do {
    auto v63 = e.Enumerators();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      sv63.set(i63, es.EntityId(e63));
      ++i63;
    }
  } while (false);
  auto v79 = e.InstantiatedFromMemberEnum();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v80 = e.IntegerType();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  if (auto r82 = e.IntegerTypeRange(); auto rs82 = r82.Size()) {
    b.setVal82(es.EntityId(r82[0]));
    b.setVal83(es.EntityId(r82[rs82 - 1u]));
  } else {
    b.setVal82(0);
    b.setVal83(0);
  }
  auto v143 = e.ODRHash();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal106(true);
  } else {
    b.setVal106(false);
  }
  auto v84 = e.PromotionType();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v85 = e.TemplateInstantiationPattern();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal107(e.IsClosed());
  b.setVal108(e.IsClosedFlag());
  b.setVal109(e.IsClosedNonFlag());
  b.setVal110(e.IsComplete());
  b.setVal111(e.IsFixed());
  b.setVal112(e.IsScoped());
  b.setVal113(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  auto t58 = e.EllipsisToken();
  b.setVal58(es.EntityId(t58));
  auto t59 = e.TypenameToken();
  b.setVal59(es.EntityId(t59));
  auto t67 = e.UsingToken();
  b.setVal67(es.EntityId(t67));
  b.setVal75(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  auto v58 = e.AnonymousDeclarationWithTypedefName();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
  } else {
    b.setVal58(mx::kInvalidEntityId);
  }
  b.setVal59(es.EntityId(e.Type()));
  b.setVal67(es.EntityId(e.UnderlyingType()));
  b.setVal75(e.IsModed());
  b.setVal76(e.IsTransparentTag());
}

void SerializeTypedefDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e, nullptr);
}

void SerializeTypeAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e, nullptr);
  auto v68 = e.DescribedAliasTemplate();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
  } else {
    b.setVal68(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e, nullptr);
  auto t68 = e.ColonToken();
  b.setVal68(es.EntityId(t68));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t69 = e.VarianceToken();
  b.setVal69(es.EntityId(t69));
  b.setVal77(e.HasExplicitBound());
}

void SerializeTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal57(es.EntityId(e.TemplateParameters()));
  b.setVal58(es.EntityId(e.TemplatedDeclaration()));
  b.setVal75(e.HasAssociatedConstraints());
  b.setVal76(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
  b.setVal59(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal77(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal78(e.IsAbbreviated());
  b.setVal95(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal78(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal78(e.IsThisDeclarationADefinition());
}

void SerializeTypeAliasTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
}

void SerializeConceptDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
  b.setVal59(es.EntityId(e.ConstraintExpression()));
  b.setVal77(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
}

void SerializeTemplateTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
  b.setVal77(e.DefaultArgumentWasInherited());
  auto t59 = e.DefaultArgumentToken();
  b.setVal59(es.EntityId(t59));
  b.setVal78(e.HasDefaultArgument());
  b.setVal95(e.IsExpandedParameterPack());
  b.setVal96(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t57 = e.AtToken();
  b.setVal57(es.EntityId(t57));
  b.setVal58(es.EntityId(e.GetterMethodDeclaration()));
  auto t59 = e.GetterNameToken();
  b.setVal59(es.EntityId(t59));
  auto t67 = e.LParenToken();
  b.setVal67(es.EntityId(t67));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal68(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal69(es.EntityId(e.SetterMethodDeclaration()));
  auto t79 = e.SetterNameToken();
  b.setVal79(es.EntityId(t79));
  b.setVal80(es.EntityId(e.Type()));
  b.setVal75(e.IsAtomic());
  b.setVal76(e.IsClassProperty());
  b.setVal77(e.IsDirectProperty());
  b.setVal78(e.IsInstanceProperty());
  b.setVal95(e.IsOptional());
  b.setVal96(e.IsReadOnly());
  b.setVal97(e.IsRetaining());
}

void SerializeObjCMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal75(e.DefinedInNSObject());
  b.setVal57(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal58(es.EntityId(e.ClassInterface()));
  b.setVal59(es.EntityId(e.CommandDeclaration()));
  auto t67 = e.DeclaratorEndToken();
  b.setVal67(es.EntityId(t67));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal68(es.EntityId(e.ReturnType()));
  if (auto r69 = e.ReturnTypeSourceRange(); auto rs69 = r69.Size()) {
    b.setVal69(es.EntityId(r69[0]));
    b.setVal79(es.EntityId(r69[rs69 - 1u]));
  } else {
    b.setVal69(0);
    b.setVal79(0);
  }
  auto t80 = e.SelectorStartToken();
  b.setVal80(es.EntityId(t80));
  b.setVal82(es.EntityId(e.SelfDeclaration()));
  b.setVal76(e.HasParameterDestroyedInCallee());
  b.setVal77(e.HasRedeclaration());
  b.setVal78(e.HasRelatedResultType());
  b.setVal95(e.HasSkippedBody());
  b.setVal96(e.IsClassMethod());
  b.setVal97(e.IsDefined());
  b.setVal98(e.IsDesignatedInitializerForTheInterface());
  b.setVal99(e.IsDirectMethod());
  b.setVal100(e.IsInstanceMethod());
  b.setVal101(e.IsOptional());
  b.setVal102(e.IsOverriding());
  b.setVal103(e.IsPropertyAccessor());
  b.setVal104(e.IsRedeclaration());
  b.setVal105(e.IsSynthesizedAccessorStub());
  b.setVal106(e.IsThisDeclarationADefinition());
  b.setVal107(e.IsThisDeclarationADesignatedInitializer());
  b.setVal108(e.IsVariadic());
  do {
    auto v52 = e.Parameters();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v53 = e.SelectorTokens();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  pasta::DeclContext dc63(e);
  auto v63 = dc63.AlreadyLoadedDeclarations();
  auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
  auto i63 = 0u;
  for (const pasta::Decl &e63 : v63) {
    sv63.set(i63, es.EntityId(e63));
    ++i63;
  }
}

void SerializeObjCContainerDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v52 = e.ClassMethods();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v53 = e.ClassProperties();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  if (auto r57 = e.AtEndRange(); auto rs57 = r57.Size()) {
    b.setVal57(es.EntityId(r57[0]));
    b.setVal58(es.EntityId(r57[rs57 - 1u]));
  } else {
    b.setVal57(0);
    b.setVal58(0);
  }
  auto t59 = e.AtStartToken();
  b.setVal59(es.EntityId(t59));
  do {
    auto v63 = e.InstanceMethods();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      sv63.set(i63, es.EntityId(e63));
      ++i63;
    }
  } while (false);
  do {
    auto v178 = e.InstanceProperties();
    auto sv178 = b.initVal178(static_cast<unsigned>(v178.size()));
    auto i178 = 0u;
    for (const auto &e178 : v178) {
      sv178.set(i178, es.EntityId(e178));
      ++i178;
    }
  } while (false);
  do {
    auto v186 = e.Methods();
    auto sv186 = b.initVal186(static_cast<unsigned>(v186.size()));
    auto i186 = 0u;
    for (const auto &e186 : v186) {
      sv186.set(i186, es.EntityId(e186));
      ++i186;
    }
  } while (false);
  do {
    auto v187 = e.Properties();
    auto sv187 = b.initVal187(static_cast<unsigned>(v187.size()));
    auto i187 = 0u;
    for (const auto &e187 : v187) {
      sv187.set(i187, es.EntityId(e187));
      ++i187;
    }
  } while (false);
  pasta::DeclContext dc188(e);
  auto v188 = dc188.AlreadyLoadedDeclarations();
  auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
  auto i188 = 0u;
  for (const pasta::Decl &e188 : v188) {
    sv188.set(i188, es.EntityId(e188));
    ++i188;
  }
}

void SerializeObjCCategoryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal75(e.IsClassExtension());
  auto t67 = e.CategoryNameToken();
  b.setVal67(es.EntityId(t67));
  b.setVal68(es.EntityId(e.ClassInterface()));
  b.setVal69(es.EntityId(e.Implementation()));
  auto t79 = e.InstanceVariableLBraceToken();
  b.setVal79(es.EntityId(t79));
  auto t80 = e.InstanceVariableRBraceToken();
  b.setVal80(es.EntityId(t80));
  b.setVal82(es.EntityId(e.NextClassCategory()));
  do {
    auto v316 = e.InstanceVariables();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  do {
    auto v342 = e.ProtocolTokens();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
  do {
    auto v344 = e.Protocols();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  auto v74 = e.ObjCRuntimeNameAsString();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal75(e.HasDefinition());
  b.setVal76(e.IsNonRuntimeProtocol());
  b.setVal77(e.IsThisDeclarationADefinition());
  do {
    auto v316 = e.ProtocolTokens();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  do {
    auto v342 = e.Protocols();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  do {
    auto v316 = e.AllReferencedProtocols();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
  b.setVal75(e.DeclaresOrInheritsDesignatedInitializers());
  auto t67 = e.EndOfDefinitionToken();
  b.setVal67(es.EntityId(t67));
  b.setVal68(es.EntityId(e.Implementation()));
  auto v74 = e.ObjCRuntimeNameAsString();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  auto v69 = e.SuperClass();
  if (v69) {
    auto id69 = es.EntityId(v69.value());
    b.setVal69(id69);
  } else {
    b.setVal69(mx::kInvalidEntityId);
  }
  auto t79 = e.SuperClassToken();
  b.setVal79(es.EntityId(t79));
  auto v80 = e.SuperClassTypeInfo();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  b.setVal82(es.EntityId(e.TypeForDeclaration()));
  b.setVal76(e.HasDefinition());
  b.setVal77(e.HasDesignatedInitializers());
  b.setVal78(e.IsArcWeakrefUnavailable());
  b.setVal95(e.IsImplicitInterfaceDeclaration());
  b.setVal83(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal96(e.IsThisDeclarationADefinition());
  do {
    auto v342 = e.InstanceVariables();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
  do {
    auto v344 = e.KnownCategories();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
  do {
    auto v345 = e.KnownExtensions();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
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

void SerializeObjCImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal67(es.EntityId(e.ClassInterface()));
  do {
    auto v316 = e.PropertyImplementations();
    auto sv316 = b.initVal316(static_cast<unsigned>(v316.size()));
    auto i316 = 0u;
    for (const auto &e316 : v316) {
      sv316.set(i316, es.EntityId(e316));
      ++i316;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  b.setVal68(es.EntityId(e.CategoryDeclaration()));
  auto t69 = e.CategoryNameToken();
  b.setVal69(es.EntityId(t69));
}

void SerializeObjCImplementationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  auto t68 = e.InstanceVariableLBraceToken();
  b.setVal68(es.EntityId(t68));
  auto t69 = e.InstanceVariableRBraceToken();
  b.setVal69(es.EntityId(t69));
  auto v74 = e.ObjCRuntimeNameAsString();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal79(es.EntityId(e.SuperClass()));
  auto t80 = e.SuperClassToken();
  b.setVal80(es.EntityId(t80));
  b.setVal75(e.HasDestructors());
  b.setVal76(e.HasNonZeroConstructors());
  do {
    auto v342 = e.InstanceVariables();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal57(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeNamespaceAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t57 = e.AliasToken();
  b.setVal57(es.EntityId(t57));
  b.setVal58(es.EntityId(e.AliasedNamespace()));
  auto t59 = e.NamespaceToken();
  b.setVal59(es.EntityId(t59));
  auto t67 = e.TargetNameToken();
  b.setVal67(es.EntityId(t67));
}

void SerializeLinkageSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v52 = e.Children();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  b.setVal50(es.EntityId(e.ExtendingDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal57(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v52 = e.IdentifierTokens();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeImplicitConceptSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitConceptSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v52 = e.TemplateArguments();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal50(es.EntityId(e.FriendDeclaration()));
  auto t57 = e.FriendToken();
  b.setVal57(es.EntityId(t57));
  b.setVal58(es.EntityId(e.FriendType()));
  do {
    auto v52 = e.TemplateParameterLists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeFriendDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v50 = e.FriendDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  auto t57 = e.FriendToken();
  b.setVal57(es.EntityId(t57));
  auto v58 = e.FriendType();
  if (v58) {
    auto id58 = es.EntityId(v58.value());
    b.setVal58(id58);
  } else {
    b.setVal58(mx::kInvalidEntityId);
  }
  b.setVal51(e.IsUnsupportedFriend());
  do {
    auto v52 = e.FriendTypeTemplateParameterLists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t50 = e.AssemblyToken();
  b.setVal50(es.EntityId(t50));
  b.setVal57(es.EntityId(e.AssemblyString()));
  auto t58 = e.RParenToken();
  b.setVal58(es.EntityId(t58));
}

void SerializeExternCContextDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeExportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t50 = e.ExportToken();
  b.setVal50(es.EntityId(t50));
  auto t57 = e.RBraceToken();
  b.setVal57(es.EntityId(t57));
  b.setVal51(e.HasBraces());
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializeEmptyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
}

#pragma GCC diagnostic pop
}  // namespace indexer
