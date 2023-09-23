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
#include "PendingFragment.h"
#include "TokenTree.h"
#include "Util.h"
namespace indexer {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

void SerializeDesignator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Designator::Builder b, const pasta::Designator &e, const TokenTree *) {
  (void) pf;
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
  auto et6 = es.EntityId(e.DotToken());
  b.setVal6(et6);
  auto et7 = es.EntityId(e.FieldToken());
  b.setVal7(et7);
  auto et8 = es.EntityId(e.LeftBracketToken());
  b.setVal8(et8);
  auto et9 = es.EntityId(e.RightBracketToken());
  b.setVal9(et9);
  auto et10 = es.EntityId(e.EllipsisToken());
  b.setVal10(et10);
}

void SerializeCXXBaseSpecifier(const PendingFragment &pf, const EntityMapper &es, mx::ast::CXXBaseSpecifier::Builder b, const pasta::CXXBaseSpecifier &e, const TokenTree *) {
  (void) pf;
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
  auto et2 = es.EntityId(e.BaseTypeToken());
  b.setVal2(et2);
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

void SerializeTemplateParameterList(const PendingFragment &pf, const EntityMapper &es, mx::ast::TemplateParameterList::Builder b, const pasta::TemplateParameterList &e, const TokenTree *) {
  (void) pf;
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
  auto et4 = es.EntityId(e.TemplateKeywordToken());
  b.setVal4(et4);
  auto et5 = es.EntityId(e.LeftAngleToken());
  b.setVal5(et5);
  auto et6 = es.EntityId(e.RightAngleToken());
  b.setVal6(et6);
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

void SerializeTemplateArgument(const PendingFragment &pf, const EntityMapper &es, mx::ast::TemplateArgument::Builder b, const pasta::TemplateArgument &e, const TokenTree *) {
  (void) pf;
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

void SerializeMacro(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::Macro &e, const TokenTree *tt) {
  (void) pf;
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

void SerializeMacroVAOptArgument(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOptArgument &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
}

void SerializeMacroVAOpt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroVAOpt &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
  b.setVal3(e.ContentsAreElided());
}

void SerializeMacroSubstitution(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroSubstitution &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
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

void SerializeMacroConcatenate(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroConcatenate &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(pf, es, b, e, tt);
  auto et8 = es.EntityId(e.PastedToken());
  b.setVal8(et8);
}

void SerializeMacroStringify(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroStringify &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(pf, es, b, e, tt);
  auto et8 = es.EntityId(e.StringifiedToken());
  b.setVal8(et8);
}

void SerializeMacroExpansion(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroExpansion &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(pf, es, b, e, tt);
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

void SerializeMacroParameterSubstitution(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameterSubstitution &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(pf, es, b, e, tt);
  b.setVal8(es.EntityId(e.Parameter()));
  auto et11 = es.EntityId(e.ParameterUse());
  b.setVal11(et11);
}

void SerializeMacroArgument(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroArgument &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
  b.setVal3(e.IsVariadic());
  b.setVal12(e.Index());
}

void SerializeMacroParameter(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameter &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
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

void SerializeMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(pf, es, b, e, tt);
  auto et5 = es.EntityId(e.Hash());
  b.setVal5(et5);
  auto v6 = e.DirectiveName();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
}

void SerializeDefineMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::DefineMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
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

void SerializePragmaMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::PragmaMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
}

void SerializeUndefineMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::UndefineMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
}

void SerializeOtherMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::OtherMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
}

void SerializeConditionalMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ConditionalMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
}

void SerializeEndIfMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::EndIfMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeElseMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeElseIfNotDefinedMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeElseIfDefinedMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeElseIfMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ElseIfMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeIfNotDefinedMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfNotDefinedMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeIfDefinedMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfDefinedMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeIfMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IfMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeConditionalMacroDirective(pf, es, b, e, tt);
}

void SerializeIncludeLikeMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeLikeMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroDirective(pf, es, b, e, tt);
  auto v7 = e.IncludedFile();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
}

void SerializeImportMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::ImportMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(pf, es, b, e, tt);
}

void SerializeIncludeMacrosMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacrosMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(pf, es, b, e, tt);
}

void SerializeIncludeNextMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeNextMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(pf, es, b, e, tt);
}

void SerializeIncludeMacroDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::IncludeMacroDirective &e, const TokenTree *tt) {
  (void) pf;
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeIncludeLikeMacroDirective(pf, es, b, e, tt);
}

void SerializeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Attr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  auto et0 = es.EntityId(e.Token());
  b.setVal0(et0);
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

void SerializeAlignValueAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignValueAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
}

void SerializeAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAbiTagAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AbiTagAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeSPtrAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SPtrAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializePtr64Attr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr64Attr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializePtr32Attr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Ptr32Attr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLPrivateAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLPrivateAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLLocalAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLLocalAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLGlobalHostAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalHostAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLGlobalDeviceAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalDeviceAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLGlobalAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGlobalAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLGenericAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGenericAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLConstantAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLConstantAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeObjCKindOfAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCKindOfAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCInertUnsafeUnretainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCInertUnsafeUnretainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCGCAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCGCAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeNoDerefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDerefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeHLSLGroupSharedAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLGroupSharedAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeCmseNSCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeBTFTypeTagAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFTypeTagAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  auto v9 = e.BTFTypeTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArmStreamingCompatibleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmStreamingCompatibleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmStreamingAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmStreamingAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmSharedZAAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmSharedZAAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmPreservesZAAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmPreservesZAAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmMveStrictPolymorphismAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmMveStrictPolymorphismAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeAnnotateTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeWebAssemblyFuncrefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyFuncrefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeUPtrAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UPtrAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeTypeNullableResultAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableResultAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeTypeNullableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeTypeNullUnspecifiedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNullUnspecifiedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeTypeNonNullAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeNonNullAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeThreadAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThreadAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftObjCMembersAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftObjCMembersAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeStmtAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StmtAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLUnrollHintAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLUnrollHintAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeMustTailAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MustTailAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeLikelyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LikelyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeFallThroughAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FallThroughAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeUnlikelyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnlikelyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeSuppressAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SuppressAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
}

void SerializeRenderScriptKernelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RenderScriptKernelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeOverloadableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverloadableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLAccessAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLAccessAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal11(e.IsReadOnly());
  b.setVal12(e.IsReadWrite());
  b.setVal13(e.IsWriteOnly());
}

void SerializeObjCRuntimeVisibleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeVisibleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCRuntimeNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRuntimeNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  auto v9 = e.MetadataName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeObjCNonRuntimeProtocolAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonRuntimeProtocolAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCNonLazyClassAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNonLazyClassAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCDirectMembersAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectMembersAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCDirectAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDirectAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCDesignatedInitializerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCDesignatedInitializerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCClassStubAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCClassStubAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeObjCBoxableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBoxableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeOMPReferencedVarAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPReferencedVarAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Reference()));
}

void SerializeOMPDeclareSimdDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareSimdDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.BranchState())));
  b.setVal8(es.EntityId(e.Simdlen()));
}

void SerializeOMPCaptureKindAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureKindAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeNoEscapeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoEscapeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeNoBuiltinAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoBuiltinAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeModeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ModeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeLoopHintAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoopHintAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
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

void SerializeLoaderUninitializedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LoaderUninitializedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeInitSegAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitSegAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  auto v9 = e.Section();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeInheritableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal11(e.ShouldInheritEvenIfAlreadyPresent());
}

void SerializeIBOutletCollectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletCollectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Interface()));
  b.setVal16(es.EntityId(e.InterfaceToken()));
}

void SerializeIBOutletAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeIBActionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBActionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeHotAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HotAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeHLSLShaderAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLShaderAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeHLSLResourceBindingAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceBindingAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Slot();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Space();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
}

void SerializeHLSLResourceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ResourceShape())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.ResourceType())));
}

void SerializeHLSLNumThreadsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLNumThreadsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeHLSLAnnotationAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLAnnotationAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeHLSLSV_GroupIndexAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_GroupIndexAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeHLSLAnnotationAttr(pf, es, b, e, nullptr);
}

void SerializeHLSLSV_DispatchThreadIDAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_DispatchThreadIDAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeHLSLAnnotationAttr(pf, es, b, e, nullptr);
}

void SerializeHIPManagedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HIPManagedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeGuardedVarAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedVarAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeGuardedByAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GuardedByAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializeGNUInlineAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::GNUInlineAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeFunctionReturnThunksAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FunctionReturnThunksAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ThunkType())));
}

void SerializeFormatAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeFormatArgAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FormatArgAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeFlattenAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlattenAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeFlagEnumAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FlagEnumAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeFinalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FinalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsSpelledAsSealed());
}

void SerializeFastCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::FastCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeExternalSourceSymbolAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExternalSourceSymbolAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.DefinedIn();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal12(e.GeneratedDeclaration());
  auto v17 = e.Language();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  auto v18 = e.USR();
  std::string s18(v18.data(), v18.size());
  b.setVal18(s18);
}

void SerializeExclusiveTrylockFunctionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExclusiveTrylockFunctionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeExcludeFromExplicitInstantiationAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExcludeFromExplicitInstantiationAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeErrorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ErrorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v9 = e.UserDiagnostic();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal12(e.IsError());
  b.setVal13(e.IsWarning());
}

void SerializeEnumExtensibilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnumExtensibilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Extensibility())));
}

void SerializeEnforceTCBLeafAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBLeafAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.TCBName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnforceTCBAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.TCBName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEnableIfAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnableIfAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Condition()));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeEmptyBasesAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EmptyBasesAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDisableTailCallsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableTailCallsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDisableSanitizerInstrumentationAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DisableSanitizerInstrumentationAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDiagnoseIfAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseIfAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.ArgumentDependent());
  b.setVal8(es.EntityId(e.Condition()));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DiagnosticType())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal16(es.EntityId(e.Parent()));
  b.setVal13(e.IsError());
  b.setVal19(e.IsWarning());
}

void SerializeDiagnoseAsBuiltinAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseAsBuiltinAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Function()));
}

void SerializeDestructorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DestructorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDeprecatedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeprecatedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Replacement();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
}

void SerializeDeclOrStmtAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DeclOrStmtAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAlwaysInlineAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysInlineAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsClangAlwaysInline());
}

void SerializeNoMergeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMergeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(pf, es, b, e, nullptr);
}

void SerializeNoInlineAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInlineAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(pf, es, b, e, nullptr);
  b.setVal12(e.IsClangNoInline());
}

void SerializeDLLImportStaticLocalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportStaticLocalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDLLImportAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLImportAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDLLExportStaticLocalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportStaticLocalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeDLLExportAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DLLExportAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeConvergentAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConvergentAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeConsumableSetOnReadAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableSetOnReadAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeConsumableAutoCastAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAutoCastAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeConsumableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConsumableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DefaultState())));
}

void SerializeConstructorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstructorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeConstInitAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstInitAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsConstinit());
}

void SerializeConstAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ConstAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCommonAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CommonAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeColdAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ColdAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCodeSegAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeSegAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCmseNSEntryAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CmseNSEntryAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCleanupAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CleanupAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.FunctionDeclaration()));
}

void SerializeCapturedRecordAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapturedRecordAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeCallbackAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallbackAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCallableWhenAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CallableWhenAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCXX11NoReturnAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CXX11NoReturnAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeCUDASharedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDASharedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDALaunchBoundsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDALaunchBoundsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.MaxThreads()));
  b.setVal16(es.EntityId(e.MinBlocks()));
}

void SerializeCUDAInvalidTargetAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAInvalidTargetAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDAHostAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAHostAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDAGlobalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAGlobalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDADeviceBuiltinTextureTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinTextureTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDADeviceBuiltinSurfaceTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceBuiltinSurfaceTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDADeviceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDADeviceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCUDAConstantAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CUDAConstantAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCPUSpecificAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUSpecificAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCPUDispatchAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CPUDispatchAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCFUnknownTransferAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFUnknownTransferAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCFReturnsRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCFReturnsNotRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCFICanonicalJumpTableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFICanonicalJumpTableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCFGuardAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFGuardAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Guard())));
}

void SerializeCFAuditedTransferAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFAuditedTransferAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeC11NoReturnAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::C11NoReturnAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeBuiltinAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeBlocksAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BlocksAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeBTFDeclTagAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFDeclTagAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.BTFDeclTag();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeBPFPreserveAccessIndexAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BPFPreserveAccessIndexAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAvailableOnlyInDefaultEvalMethodAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AvailableOnlyInDefaultEvalMethodAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAvailabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AvailabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.Replacement();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.Strict());
  b.setVal13(e.Unavailable());
}

void SerializeAssumptionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumptionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Assumption();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAssumeAlignedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumeAlignedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
  auto v16 = e.Offset();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
}

void SerializeAssertSharedLockAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertSharedLockAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAssertExclusiveLockAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertExclusiveLockAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAssertCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssertCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeAsmLabelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AsmLabelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.IsLiteralLabel());
  auto v9 = e.Label();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeArtificialAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArtificialAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeArmNewZAAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmNewZAAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeArmLocallyStreamingAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmLocallyStreamingAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeArmBuiltinAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmBuiltinAliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeArgumentWithTypeTagAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArgumentWithTypeTagAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.IsPointer());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeArcWeakrefUnavailableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArcWeakrefUnavailableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAnyX86NoCfCheckAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCfCheckAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAnyX86NoCallerSavedRegistersAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86NoCallerSavedRegistersAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAnyX86InterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnyX86InterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAnalyzerNoReturnAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnalyzerNoReturnAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAlwaysDestroyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlwaysDestroyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAllocSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAllocAlignAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AllocAlignAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAlignedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
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
  auto v20 = e.CachedAlignmentValue();
  if (v20) {
    b.setVal20(static_cast<uint32_t>(v20.value()));
    b.setVal12(true);
  } else {
    b.setVal12(false);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal13(e.IsAlignas());
  b.setVal19(e.IsAlignmentDependent());
  b.setVal21(e.IsAlignmentErrorDependent());
  b.setVal22(e.IsAlignmentExpression());
  b.setVal23(e.IsC11());
  b.setVal24(e.IsDeclspec());
  b.setVal25(e.IsGNU());
}

void SerializeAlignNaturalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignNaturalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAlignMac68kAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignMac68kAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAcquiredBeforeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredBeforeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAcquiredAfterAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquiredAfterAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAcquireHandleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireHandleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeAcquireCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeAVRSignalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRSignalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAVRInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AVRInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeARMInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ARMInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializeAMDGPUWavesPerEUAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUWavesPerEUAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal16(es.EntityId(e.Min()));
}

void SerializeAMDGPUNumVGPRAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumVGPRAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAMDGPUNumSGPRAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumSGPRAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAMDGPUKernelCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUKernelCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAMDGPUFlatWorkGroupSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUFlatWorkGroupSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Max()));
  b.setVal16(es.EntityId(e.Min()));
}

void SerializeAArch64VectorPcsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64VectorPcsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeAArch64SVEPcsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AArch64SVEPcsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeZeroCallUsedRegsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ZeroCallUsedRegsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ZeroCallUsedRegs())));
}

void SerializeXRayLogArgsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayLogArgsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeXRayInstrumentAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayInstrumentAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.AlwaysXRayInstrument());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal13(e.NeverXRayInstrument());
}

void SerializeX86ForceAlignArgPointerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::X86ForceAlignArgPointerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeWorkGroupSizeHintAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WorkGroupSizeHintAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeWebAssemblyImportNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.ImportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyImportModuleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportModuleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.ImportModule();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWebAssemblyExportNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyExportNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.ExportName();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakRefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakRefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Aliasee();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeWeakImportAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakImportAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeWeakAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeWarnUnusedResultAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedResultAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.IsCXX11NoDiscard());
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeWarnUnusedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WarnUnusedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeVisibilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VisibilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeVectorCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VectorCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeVecTypeHintAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecTypeHintAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.TypeHint()));
  b.setVal16(es.EntityId(e.TypeHintToken()));
}

void SerializeVecReturnAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::VecReturnAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeUuidAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UuidAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Guid();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal8(es.EntityId(e.GuidDeclaration()));
}

void SerializeUsingIfExistsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsingIfExistsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeUsedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UsedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeUnusedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnusedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeUnsafeBufferUsageAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnsafeBufferUsageAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeUninitializedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UninitializedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeUnavailableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnavailableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ImplicitReason())));
  auto v9 = e.Message();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeTypeVisibilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeVisibilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeTypeTagForDatatypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeTagForDatatypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.LayoutCompatible());
  b.setVal8(es.EntityId(e.MatchingCType()));
  b.setVal16(es.EntityId(e.MatchingCTypeToken()));
  b.setVal13(e.MustBeNull());
}

void SerializeTryAcquireCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TryAcquireCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal8(es.EntityId(e.SuccessValue()));
  b.setVal12(e.IsShared());
}

void SerializeTrivialABIAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TrivialABIAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeTransparentUnionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TransparentUnionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeThisCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ThisCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeTestTypestateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TestTypestateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.TestState())));
}

void SerializeTargetVersionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetVersionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.NamesString();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.IsDefaultVersion());
}

void SerializeTargetClonesAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetClonesAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeTargetAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Architecture();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  auto v17 = e.FeaturesString();
  std::string s17(v17.data(), v17.size());
  b.setVal17(s17);
  b.setVal12(e.IsDefaultVersion());
}

void SerializeTLSModelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TLSModelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Model();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSysVABIAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SysVABIAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftPrivateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftPrivateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftNewTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNewTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.NewtypeKind())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeSwiftNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftErrorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
}

void SerializeSwiftCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftBridgedTypedefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgedTypedefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftBridgeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftBridgeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.SwiftType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAttrAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAttrAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Attribute();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeSwiftAsyncErrorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncErrorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
}

void SerializeSwiftAsyncCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftAsyncAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.AttributeKind())));
}

void SerializeStrictGuardStackCheckAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictGuardStackCheckAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeStrictFPAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StrictFPAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeStdCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StdCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeStandaloneDebugAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::StandaloneDebugAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSpeculativeLoadHardeningAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SpeculativeLoadHardeningAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSharedTrylockFunctionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SharedTrylockFunctionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.SuccessValue()));
}

void SerializeSetTypestateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SetTypestateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.NewState())));
}

void SerializeSentinelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SentinelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSelectAnyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SelectAnyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeScopedLockableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ScopedLockableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSYCLSpecialClassAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLSpecialClassAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSYCLKernelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SYCLKernelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeReturnsTwiceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsTwiceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeReturnsNonNullAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnsNonNullAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeReturnTypestateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReturnTypestateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.State())));
}

void SerializeRetainAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RetainAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeRestrictAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RestrictAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeRequiresCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RequiresCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsShared());
}

void SerializeReqdWorkGroupSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReqdWorkGroupSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeReleaseCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsGeneric());
  b.setVal13(e.IsShared());
}

void SerializeReinitializesAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReinitializesAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeRegCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RegCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeReadOnlyPlacementAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReadOnlyPlacementAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeRandomizeLayoutAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RandomizeLayoutAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeRISCVInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RISCVInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializePureAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PureAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializePtGuardedVarAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedVarAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializePtGuardedByAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PtGuardedByAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializePreserveMostAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveMostAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializePreserveAllAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreserveAllAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializePreferredNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.TypedefType()));
  b.setVal16(es.EntityId(e.TypedefTypeToken()));
}

void SerializePragmaClangTextSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangTextSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangRodataSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRodataSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangRelroSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRelroSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangDataSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangDataSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePragmaClangBSSSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangBSSSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v9 = e.Name();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePointerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PointerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal16(es.EntityId(e.DerefTypeToken()));
}

void SerializePcsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PcsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.PCS())));
}

void SerializePatchableFunctionEntryAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PatchableFunctionEntryAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializePascalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PascalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeParamTypestateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParamTypestateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ParameterState())));
}

void SerializePackedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PackedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOwnershipAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnershipAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.OwnKind())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsHolds());
  b.setVal13(e.IsReturns());
  b.setVal19(e.IsTakes());
}

void SerializeOwnerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.DerefType()));
  b.setVal16(es.EntityId(e.DerefTypeToken()));
}

void SerializeOverrideAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OverrideAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOptimizeNoneAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OptimizeNoneAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLKernelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLKernelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOpenCLIntelReqdSubGroupSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLIntelReqdSubGroupSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCSubclassingRestrictedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCSubclassingRestrictedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCRootClassAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRootClassAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCReturnsInnerPointerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCReturnsInnerPointerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCRequiresSuperAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresSuperAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCRequiresPropertyDefsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCRequiresPropertyDefsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCPreciseLifetimeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCPreciseLifetimeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCOwnershipAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCOwnershipAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCNSObjectAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCNSObjectAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCMethodFamilyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCMethodFamilyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Family())));
}

void SerializeObjCIndependentClassAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCIndependentClassAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCExternallyRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExternallyRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCExplicitProtocolImplAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExplicitProtocolImplAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCExceptionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCExceptionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgeRelatedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeRelatedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgeMutableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeMutableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ObjCBridgeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOSReturnsRetainedOnZeroAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnZeroAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOSReturnsRetainedOnNonZeroAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedOnNonZeroAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOSReturnsRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOSReturnsNotRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOSConsumesThisAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumesThisAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOMPThreadPrivateDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPThreadPrivateDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOMPDeclareVariantAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareVariantAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.VariantFuncReference()));
}

void SerializeOMPDeclareTargetDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareTargetDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.DevType())));
  b.setVal12(e.Indirect());
  b.setVal8(es.EntityId(e.IndirectExpression()));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.MapType())));
}

void SerializeOMPCaptureNoInitAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureNoInitAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeOMPAllocateDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPAllocateDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Alignment()));
  b.setVal16(es.EntityId(e.Allocator()));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.AllocatorType())));
}

void SerializeNotTailCalledAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NotTailCalledAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoUwtableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUwtableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoUniqueAddressAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoUniqueAddressAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoThrowAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThrowAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoThreadSafetyAnalysisAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoThreadSafetyAnalysisAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoStackProtectorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoStackProtectorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeNoSplitStackAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSplitStackAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoSpeculativeLoadHardeningAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSpeculativeLoadHardeningAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoSanitizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoSanitizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.HasCoverage());
}

void SerializeNoReturnAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoReturnAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoRandomizeLayoutAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoRandomizeLayoutAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoProfileFunctionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoProfileFunctionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoMips16Attr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMips16Attr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoMicroMipsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoMicroMipsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoInstrumentFunctionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoInstrumentFunctionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoDuplicateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDuplicateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoDestroyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDestroyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoDebugAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoDebugAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoCommonAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoCommonAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNoAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NoAliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNakedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NakedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNVPTXKernelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NVPTXKernelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNSReturnsRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNSReturnsNotRetainedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsNotRetainedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNSReturnsAutoreleasedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSReturnsAutoreleasedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeNSErrorDomainAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSErrorDomainAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.ErrorDomain()));
}

void SerializeNSConsumesSelfAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumesSelfAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMipsShortCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsShortCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsLongCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsLongCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializeMips16Attr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::Mips16Attr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMinVectorWidthAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinVectorWidthAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMinSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MinSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMicroMipsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MicroMipsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMaybeUndefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaybeUndefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMayAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MayAliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMaxFieldAlignmentAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MaxFieldAlignmentAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMSVtorDispAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSVtorDispAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.VtorDispMode())));
}

void SerializeMSStructAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSStructAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMSP430InterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSP430InterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMSNoVTableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSNoVTableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMSInheritanceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSInheritanceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.BestCase());
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.InheritanceModel())));
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMSAllocatorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSAllocatorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMSABIAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSABIAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeMIGServerRoutineAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MIGServerRoutineAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeM68kInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::M68kInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeLocksExcludedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LocksExcludedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeLockReturnedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LockReturnedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal8(es.EntityId(e.Argument()));
}

void SerializeLifetimeBoundAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LifetimeBoundAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeLeafAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LeafAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeLayoutVersionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LayoutVersionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeLTOVisibilityPublicAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::LTOVisibilityPublicAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeInternalLinkageAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InternalLinkageAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeIntelOclBiccAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IntelOclBiccAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeInitPriorityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InitPriorityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeInheritableParamAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableParamAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCarriesDependencyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CarriesDependencyAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
}

void SerializeCFConsumedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CFConsumedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
}

void SerializeAnnotateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AnnotateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  auto v9 = e.Annotation();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeUseHandleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UseHandleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeReleaseHandleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseHandleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  auto v9 = e.HandleType();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializePassObjectSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PassObjectSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsDynamic());
}

void SerializeParameterABIAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParameterABIAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.ABI())));
}

void SerializeSwiftIndirectResultAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftIndirectResultAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftErrorResultAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorResultAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftContextAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftContextAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftAsyncContextAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncContextAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeParameterABIAttr(pf, es, b, e, nullptr);
}

void SerializeOSConsumedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OSConsumedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
}

void SerializeNonNullAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NonNullAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
}

void SerializeNSConsumedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::NSConsumedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
}

void SerializeIFuncAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IFuncAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  auto v9 = e.Resolver();
  std::string s9(v9.data(), v9.size());
  b.setVal9(s9);
}

void SerializeCalledOnceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CalledOnceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
}

void SerializeBuiltinAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BuiltinAliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::Type &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.EntityId(e.DesugaredType()));
  b.setVal1(es.EntityId(e.CanonicalType()));
  b.setVal2(e.IsQualified());
  b.setVal3(es.EntityId(e.UnqualifiedType()));
  auto v4 = e.SizeInBits();
  if (v4) {
    b.setVal4(static_cast<uint64_t>(v4.value()));
    b.setVal5(true);
  } else {
    b.setVal5(false);
  }
  auto v6 = e.Alignment();
  if (v6) {
    b.setVal6(static_cast<uint64_t>(v6.value()));
    b.setVal7(true);
  } else {
    b.setVal7(false);
  }
  b.setVal8(e.AcceptsObjCTypeParameters());
  b.setVal9(e.CanDecayToPointerType());
  b.setVal10(e.CanHaveNullability());
  b.setVal11(e.ContainsErrors());
  b.setVal12(e.ContainsUnexpandedParameterPack());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  auto v14 = e.Nullability();
  if (v14) {
    b.setVal14(static_cast<unsigned char>(v14.value()));
    b.setVal15(true);
  } else {
    b.setVal15(false);
  }
  auto v16 = e.PointeeCXXRecordDeclaration();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto v17 = e.PointeeOrArrayElementType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  auto v18 = e.PointeeType();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto v19 = e.ScalarTypeKind();
  if (v19) {
    b.setVal19(static_cast<unsigned char>(v19.value()));
    b.setVal20(true);
  } else {
    b.setVal20(false);
  }
  auto v21 = e.SveElementType();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  b.setVal22(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal23(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal24(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal25(e.HasAutoForTrailingReturnType());
  b.setVal26(e.HasFloatingRepresentation());
  b.setVal27(e.HasIntegerRepresentation());
  b.setVal28(e.HasObjCPointerRepresentation());
  b.setVal29(e.HasPointerRepresentation());
  b.setVal30(e.HasSignedIntegerRepresentation());
  b.setVal31(e.HasSizedVLAType());
  b.setVal32(e.HasUnnamedOrLocalType());
  b.setVal33(e.HasUnsignedIntegerRepresentation());
  auto v34 = e.IsAggregateType();
  if (v34) {
    b.setVal34(static_cast<bool>(v34.value()));
    b.setVal35(true);
  } else {
    b.setVal35(false);
  }
  b.setVal36(e.IsAlignValueT());
  b.setVal37(e.IsAnyCharacterType());
  b.setVal38(e.IsAnyComplexType());
  b.setVal39(e.IsAnyPointerType());
  b.setVal40(e.IsArithmeticType());
  b.setVal41(e.IsArrayType());
  b.setVal42(e.IsAtomicType());
  b.setVal43(e.IsBFloat16Type());
  b.setVal44(e.IsBitIntType());
  b.setVal45(e.IsBlockCompatibleObjCPointerType());
  b.setVal46(e.IsBlockPointerType());
  b.setVal47(e.IsBooleanType());
  b.setVal48(e.IsBuiltinType());
  b.setVal49(e.IsCARCBridgableType());
  b.setVal50(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal51(e.IsCUDADeviceBuiltinTextureType());
  b.setVal52(e.IsCanonicalUnqualified());
  b.setVal53(e.IsChar16Type());
  b.setVal54(e.IsChar32Type());
  b.setVal55(e.IsChar8Type());
  b.setVal56(e.IsCharacterType());
  b.setVal57(e.IsClassType());
  b.setVal58(e.IsClkEventT());
  b.setVal59(e.IsComplexIntegerType());
  b.setVal60(e.IsComplexType());
  b.setVal61(e.IsCompoundType());
  b.setVal62(e.IsConstantArrayType());
  b.setVal63(e.IsConstantMatrixType());
  auto v64 = e.IsConstantSizeType();
  if (v64) {
    b.setVal64(static_cast<bool>(v64.value()));
    b.setVal65(true);
  } else {
    b.setVal65(false);
  }
  b.setVal66(e.IsDecltypeType());
  b.setVal67(e.IsDependentAddressSpaceType());
  b.setVal68(e.IsDependentSizedArrayType());
  b.setVal69(e.IsDependentType());
  b.setVal70(e.IsElaboratedTypeSpecifier());
  b.setVal71(e.IsEnumeralType());
  b.setVal72(e.IsEventT());
  b.setVal73(e.IsExtVectorBooleanType());
  b.setVal74(e.IsExtVectorType());
  b.setVal75(e.IsFixedPointOrIntegerType());
  b.setVal76(e.IsFixedPointType());
  b.setVal77(e.IsFloat128Type());
  b.setVal78(e.IsFloat16Type());
  b.setVal79(e.IsFloatingType());
  b.setVal80(e.IsFromAST());
  b.setVal81(e.IsFunctionNoProtoType());
  b.setVal82(e.IsFunctionPointerType());
  b.setVal83(e.IsFunctionProtoType());
  b.setVal84(e.IsFunctionReferenceType());
  b.setVal85(e.IsFunctionType());
  b.setVal86(e.IsFundamentalType());
  b.setVal87(e.IsHalfType());
  b.setVal88(e.IsIbm128Type());
  b.setVal89(e.IsImageType());
  b.setVal90(e.IsIncompleteArrayType());
  b.setVal91(e.IsIncompleteOrObjectType());
  b.setVal92(e.IsIncompleteType());
  b.setVal93(e.IsInstantiationDependentType());
  b.setVal94(e.IsIntegerType());
  b.setVal95(e.IsIntegralOrEnumerationType());
  b.setVal96(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal97(e.IsIntegralType());
  b.setVal98(e.IsInterfaceType());
  b.setVal99(e.IsLValueReferenceType());
  b.setVal100(e.IsLinkageValid());
  auto v101 = e.IsLiteralType();
  if (v101) {
    b.setVal101(static_cast<bool>(v101.value()));
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
  b.setVal103(e.IsMatrixType());
  b.setVal104(e.IsMemberDataPointerType());
  b.setVal105(e.IsMemberFunctionPointerType());
  b.setVal106(e.IsMemberPointerType());
  b.setVal107(e.IsNonOverloadPlaceholderType());
  b.setVal108(e.IsNothrowT());
  b.setVal109(e.IsNullPointerType());
  b.setVal110(e.IsOCLExtOpaqueType());
  b.setVal111(e.IsOCLImage1dArrayROType());
  b.setVal112(e.IsOCLImage1dArrayRWType());
  b.setVal113(e.IsOCLImage1dArrayWOType());
  b.setVal114(e.IsOCLImage1dBufferROType());
  b.setVal115(e.IsOCLImage1dBufferRWType());
  b.setVal116(e.IsOCLImage1dBufferWOType());
  b.setVal117(e.IsOCLImage1dROType());
  b.setVal118(e.IsOCLImage1dRWType());
  b.setVal119(e.IsOCLImage1dWOType());
  b.setVal120(e.IsOCLImage2dArrayDepthROType());
  b.setVal121(e.IsOCLImage2dArrayDepthRWType());
  b.setVal122(e.IsOCLImage2dArrayDepthWOType());
  b.setVal123(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal124(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal125(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal126(e.IsOCLImage2dArrayMSAAROType());
  b.setVal127(e.IsOCLImage2dArrayMSAARWType());
  b.setVal128(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal129(e.IsOCLImage2dArrayROType());
  b.setVal130(e.IsOCLImage2dArrayRWType());
  b.setVal131(e.IsOCLImage2dArrayWOType());
  b.setVal132(e.IsOCLImage2dDepthROType());
  b.setVal133(e.IsOCLImage2dDepthRWType());
  b.setVal134(e.IsOCLImage2dDepthWOType());
  b.setVal135(e.IsOCLImage2dMSAADepthROType());
  b.setVal136(e.IsOCLImage2dMSAADepthRWType());
  b.setVal137(e.IsOCLImage2dMSAADepthWOType());
  b.setVal138(e.IsOCLImage2dMSAAROType());
  b.setVal139(e.IsOCLImage2dMSAARWType());
  b.setVal140(e.IsOCLImage2dMSAAWOType());
  b.setVal141(e.IsOCLImage2dROType());
  b.setVal142(e.IsOCLImage2dRWType());
  b.setVal143(e.IsOCLImage2dWOType());
  b.setVal144(e.IsOCLImage3dROType());
  b.setVal145(e.IsOCLImage3dRWType());
  b.setVal146(e.IsOCLImage3dWOType());
  b.setVal147(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal148(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal149(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal150(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal151(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal152(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal153(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal154(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal155(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal156(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal157(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal158(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal159(e.IsOCLIntelSubgroupAVCType());
  b.setVal160(e.IsObjCARCBridgableType());
  auto v161 = e.IsObjCARCImplicitlyUnretainedType();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  b.setVal163(e.IsObjCBoxableRecordType());
  b.setVal164(e.IsObjCBuiltinType());
  b.setVal165(e.IsObjCClassOrClassKindOfType());
  b.setVal166(e.IsObjCClassType());
  b.setVal167(e.IsObjCIdType());
  b.setVal168(e.IsObjCIndependentClassType());
  b.setVal169(e.IsObjCIndirectLifetimeType());
  b.setVal170(e.IsObjCInertUnsafeUnretainedType());
  b.setVal171(e.IsObjCLifetimeType());
  b.setVal172(e.IsObjCNSObjectType());
  b.setVal173(e.IsObjCObjectOrInterfaceType());
  b.setVal174(e.IsObjCObjectPointerType());
  b.setVal175(e.IsObjCObjectType());
  b.setVal176(e.IsObjCQualifiedClassType());
  b.setVal177(e.IsObjCQualifiedIdType());
  b.setVal178(e.IsObjCQualifiedInterfaceType());
  b.setVal179(e.IsObjCRetainableType());
  b.setVal180(e.IsObjCSelType());
  b.setVal181(e.IsObjectPointerType());
  b.setVal182(e.IsObjectType());
  b.setVal183(e.IsOpenCLSpecificType());
  b.setVal184(e.IsOverloadableType());
  b.setVal185(e.IsPipeType());
  b.setVal186(e.IsPlaceholderType());
  b.setVal187(e.IsPointerType());
  b.setVal188(e.IsQueueT());
  b.setVal189(e.IsRVVSizelessBuiltinType());
  b.setVal190(e.IsRVVVLSBuiltinType());
  b.setVal191(e.IsRValueReferenceType());
  b.setVal192(e.IsRealFloatingType());
  b.setVal193(e.IsRealType());
  b.setVal194(e.IsRecordType());
  b.setVal195(e.IsReferenceType());
  b.setVal196(e.IsReserveIDT());
  b.setVal197(e.IsSVESizelessBuiltinType());
  b.setVal198(e.IsSamplerT());
  b.setVal199(e.IsSaturatedFixedPointType());
  b.setVal200(e.IsScalarType());
  b.setVal201(e.IsScopedEnumeralType());
  b.setVal202(e.IsSignedFixedPointType());
  b.setVal203(e.IsSignedIntegerOrEnumerationType());
  b.setVal204(e.IsSignedIntegerType());
  b.setVal205(e.IsSizelessBuiltinType());
  b.setVal206(e.IsSizelessType());
  b.setVal207(e.IsSpecifierType());
  auto v208 = e.IsStandardLayoutType();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  b.setVal210(e.IsStdByteType());
  auto v211 = e.IsStructuralType();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  b.setVal213(e.IsStructureOrClassType());
  b.setVal214(e.IsStructureType());
  b.setVal215(e.IsSveVLSBuiltinType());
  b.setVal216(e.IsTemplateTypeParmType());
  b.setVal217(e.IsTypedefNameType());
  b.setVal218(e.IsUndeducedAutoType());
  b.setVal219(e.IsUndeducedType());
  b.setVal220(e.IsUnionType());
  b.setVal221(e.IsUnsaturatedFixedPointType());
  b.setVal222(e.IsUnscopedEnumerationType());
  b.setVal223(e.IsUnsignedFixedPointType());
  b.setVal224(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal225(e.IsUnsignedIntegerType());
  b.setVal226(e.IsVariableArrayType());
  b.setVal227(e.IsVariablyModifiedType());
  b.setVal228(e.IsVectorType());
  b.setVal229(e.IsVisibilityExplicit());
  b.setVal230(e.IsVoidPointerType());
  b.setVal231(e.IsVoidType());
  b.setVal232(e.IsWebAssemblyExternrefType());
  b.setVal233(e.IsWebAssemblyTableType());
  b.setVal234(e.IsWideCharacterType());
}

void SerializeTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto v236 = e.Declaration();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal237(e.IsParameterPack());
  b.setVal238(e.IsSugared());
}

void SerializeTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto v236 = e.AliasedType();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal237(e.IsCurrentInstantiation());
  b.setVal238(e.IsSugared());
  b.setVal239(e.IsTypeAlias());
  do {
    auto v240 = e.TemplateArguments();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
}

void SerializeTagType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Declaration()));
  b.setVal237(e.IsBeingDefined());
}

void SerializeRecordType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal238(e.HasConstFields());
  b.setVal239(e.IsSugared());
}

void SerializeEnumType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal238(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.AssociatedDeclaration()));
  auto v241 = e.PackIndex();
  if (v241) {
    b.setVal241(static_cast<uint32_t>(v241.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  b.setVal242(es.EntityId(e.ReplacedParameter()));
  b.setVal243(es.EntityId(e.ReplacementType()));
  b.setVal238(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.AssociatedDeclaration()));
  b.setVal237(e.Final());
  b.setVal242(es.EntityId(e.ReplacedParameter()));
  b.setVal238(e.IsSugared());
}

void SerializeReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal237(e.IsInnerReference());
  b.setVal238(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal239(e.IsSugared());
}

void SerializeLValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal239(e.IsSugared());
}

void SerializeQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal235(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal237(e.HasAddressSpace());
  b.setVal238(e.HasNonTrivialObjCLifetime());
  b.setVal239(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal245(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal246(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal247(e.HasQualifiers());
  b.setVal248(e.HasStrongOrWeakObjCLifetime());
  b.setVal249(e.IsCForbiddenLValueType());
  b.setVal250(e.IsCXX11PODType());
  b.setVal251(e.IsCXX98PODType());
  b.setVal252(e.IsCanonical());
  b.setVal253(e.IsCanonicalAsParameter());
  b.setVal254(e.IsConstQualified());
  b.setVal255(e.IsConstant());
  b.setVal256(e.IsLocalConstQualified());
  b.setVal257(e.IsLocalRestrictQualified());
  b.setVal258(e.IsLocalVolatileQualified());
  b.setVal259(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal260(e.IsNull());
  b.setVal261(e.IsObjCGCStrong());
  b.setVal262(e.IsObjCGCWeak());
  b.setVal263(e.IsPODType());
  b.setVal264(e.IsReferenceable());
  b.setVal265(e.IsRestrictQualified());
  b.setVal266(e.IsTrivialType());
  b.setVal267(e.IsTriviallyCopyableType());
  b.setVal268(e.IsTriviallyEqualityComparableType());
  b.setVal269(e.IsTriviallyRelocatableType());
  b.setVal270(e.IsVolatileQualified());
  b.setVal271(e.IsWebAssemblyFuncrefType());
  b.setVal272(e.IsWebAssemblyReferenceType());
  b.setVal273(e.MayBeDynamicClass());
  b.setVal274(e.MayBeNotDynamicClass());
}

void SerializePointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSugared());
}

void SerializePipeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal237(e.IsReadOnly());
  b.setVal238(e.IsSugared());
}

void SerializeParenType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.InnerType()));
  b.setVal237(e.IsSugared());
}

void SerializePackExpansionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Pattern()));
  b.setVal237(e.IsSugared());
}

void SerializeObjCTypeParamType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Declaration()));
  b.setVal237(e.IsSugared());
}

void SerializeObjCObjectType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.BaseType()));
  b.setVal242(es.EntityId(e.Interface()));
  auto v243 = e.SuperClassType();
  if (v243) {
    auto id243 = es.EntityId(v243.value());
    b.setVal243(id243);
  } else {
    b.setVal243(mx::kInvalidEntityId);
  }
  do {
    auto v240 = e.TypeArguments();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
  do {
    auto v275 = e.TypeArgumentsAsWritten();
    auto sv275 = b.initVal275(static_cast<unsigned>(v275.size()));
    auto i275 = 0u;
    for (const auto &e275 : v275) {
      sv275.set(i275, es.EntityId(e275));
      ++i275;
    }
  } while (false);
  b.setVal237(e.IsKindOfType());
  b.setVal238(e.IsKindOfTypeAsWritten());
  b.setVal239(e.IsObjCClass());
  b.setVal245(e.IsObjCId());
  b.setVal246(e.IsObjCQualifiedClass());
  b.setVal247(e.IsObjCQualifiedId());
  b.setVal248(e.IsObjCUnqualifiedClass());
  b.setVal249(e.IsObjCUnqualifiedId());
  b.setVal250(e.IsObjCUnqualifiedIdOrClass());
  b.setVal251(e.IsSpecialized());
  b.setVal252(e.IsSpecializedAsWritten());
  b.setVal253(e.IsSugared());
  b.setVal254(e.IsUnspecialized());
  b.setVal255(e.IsUnspecializedAsWritten());
  b.setVal276(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(pf, es, b, e, nullptr);
  b.setVal277(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.InterfaceDeclaration()));
  b.setVal242(es.EntityId(e.InterfaceType()));
  b.setVal243(es.EntityId(e.ObjectType()));
  b.setVal276(es.EntityId(e.SuperClassType()));
  do {
    auto v240 = e.TypeArguments();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
  do {
    auto v275 = e.TypeArgumentsAsWritten();
    auto sv275 = b.initVal275(static_cast<unsigned>(v275.size()));
    auto i275 = 0u;
    for (const auto &e275 : v275) {
      sv275.set(i275, es.EntityId(e275));
      ++i275;
    }
  } while (false);
  b.setVal237(e.IsKindOfType());
  b.setVal238(e.IsObjCIdOrClassType());
  b.setVal239(e.IsSpecialized());
  b.setVal245(e.IsSpecializedAsWritten());
  b.setVal246(e.IsSugared());
  b.setVal247(e.IsUnspecialized());
  b.setVal248(e.IsUnspecializedAsWritten());
  do {
    auto v278 = e.Qualifiers();
    auto sv278 = b.initVal278(static_cast<unsigned>(v278.size()));
    auto i278 = 0u;
    for (const auto &e278 : v278) {
      sv278.set(i278, es.EntityId(e278));
      ++i278;
    }
  } while (false);
  b.setVal277(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v279 = e.Protocols();
    auto sv279 = b.initVal279(static_cast<unsigned>(v279.size()));
    auto i279 = 0u;
    for (const auto &e279 : v279) {
      sv279.set(i279, es.EntityId(e279));
      ++i279;
    }
  } while (false);
}

void SerializeMemberPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Class()));
  b.setVal242(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal237(e.IsMemberDataPointer());
  b.setVal238(e.IsMemberFunctionPointer());
  b.setVal239(e.IsSugared());
}

void SerializeMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal237(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
  auto et242 = es.EntityId(e.AttributeToken());
  b.setVal242(et242);
  b.setVal243(es.EntityId(e.ColumnExpression()));
  b.setVal276(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
}

void SerializeMacroQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ModifiedType()));
  b.setVal242(es.EntityId(e.UnderlyingType()));
  b.setVal237(e.IsSugared());
}

void SerializeInjectedClassNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Declaration()));
  b.setVal242(es.EntityId(e.InjectedSpecializationType()));
  b.setVal243(es.EntityId(e.InjectedTST()));
  b.setVal237(e.IsSugared());
}

void SerializeFunctionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal235(es.EntityId(e.CallResultType()));
  b.setVal237(e.CmseNSCallAttribute());
  b.setVal238(e.HasRegParm());
  b.setVal239(e.NoReturnAttribute());
  b.setVal236(es.EntityId(e.ReturnType()));
  b.setVal245(e.IsConst());
  b.setVal246(e.IsRestrict());
  b.setVal247(e.IsVolatile());
}

void SerializeFunctionProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  auto v280 = e.CanThrow();
  if (v280) {
    b.setVal280(static_cast<unsigned char>(v280.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  b.setVal242(es.EntityId(e.Desugar()));
  auto et243 = es.EntityId(e.EllipsisToken());
  b.setVal243(et243);
  auto v276 = e.ExceptionSpecDeclaration();
  if (v276) {
    auto id276 = es.EntityId(v276.value());
    b.setVal276(id276);
  } else {
    b.setVal276(mx::kInvalidEntityId);
  }
  auto v277 = e.ExceptionSpecTemplate();
  if (v277) {
    auto id277 = es.EntityId(v277.value());
    b.setVal277(id277);
  } else {
    b.setVal277(mx::kInvalidEntityId);
  }
  b.setVal281(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v282 = e.NoexceptExpression();
  if (v282) {
    auto id282 = es.EntityId(v282.value());
    b.setVal282(id282);
  } else {
    b.setVal282(mx::kInvalidEntityId);
  }
  do {
    auto v240 = e.ParameterTypes();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
  b.setVal283(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal249(e.HasDependentExceptionSpec());
  b.setVal250(e.HasDynamicExceptionSpec());
  b.setVal251(e.HasExceptionSpec());
  b.setVal252(e.HasExtParameterInfos());
  b.setVal253(e.HasInstantiationDependentExceptionSpec());
  b.setVal254(e.HasNoexceptExceptionSpec());
  b.setVal255(e.HasTrailingReturn());
  auto v256 = e.IsNothrow();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  b.setVal258(e.IsSugared());
  b.setVal259(e.IsTemplateVariadic());
  b.setVal260(e.IsVariadic());
  do {
    auto v275 = e.ExceptionTypes();
    auto sv275 = b.initVal275(static_cast<unsigned>(v275.size()));
    auto i275 = 0u;
    for (const auto &e275 : v275) {
      sv275.set(i275, es.EntityId(e275));
      ++i275;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  b.setVal242(es.EntityId(e.Desugar()));
  b.setVal248(e.IsSugared());
}

void SerializeDependentVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto et236 = es.EntityId(e.AttributeToken());
  b.setVal236(et236);
  b.setVal242(es.EntityId(e.ElementType()));
  b.setVal243(es.EntityId(e.SizeExpression()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal237(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto et236 = es.EntityId(e.AttributeToken());
  b.setVal236(et236);
  b.setVal242(es.EntityId(e.ElementType()));
  b.setVal243(es.EntityId(e.SizeExpression()));
  b.setVal237(e.IsSugared());
}

void SerializeDependentBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.NumBitsExpression()));
  b.setVal237(e.IsSigned());
  b.setVal238(e.IsSugared());
  b.setVal239(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.AddressSpaceExpression()));
  auto et242 = es.EntityId(e.AttributeToken());
  b.setVal242(et242);
  b.setVal237(e.IsSugared());
}

void SerializeDeducedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto v236 = e.ResolvedType();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal237(e.IsDeduced());
  b.setVal238(e.IsSugared());
}

void SerializeDeducedTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedTemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(pf, es, b, e, nullptr);
}

void SerializeAutoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AutoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeducedType(pf, es, b, e, nullptr);
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v240 = e.TypeConstraintArguments();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
  auto v242 = e.TypeConstraintConcept();
  if (v242) {
    auto id242 = es.EntityId(v242.value());
    b.setVal242(id242);
  } else {
    b.setVal242(mx::kInvalidEntityId);
  }
  b.setVal239(e.IsConstrained());
  b.setVal245(e.IsDecltypeAuto());
  b.setVal246(e.IsGNUAutoType());
}

void SerializeDecltypeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.UnderlyingExpression()));
  b.setVal242(es.EntityId(e.UnderlyingType()));
  b.setVal237(e.IsSugared());
}

void SerializeComplexType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal237(e.IsSugared());
}

void SerializeBuiltinType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal284(static_cast<unsigned short>(mx::FromPasta(e.BuiltinKind())));
  b.setVal237(e.IsFloatingPoint());
  b.setVal238(e.IsInteger());
  b.setVal239(e.IsSVEBool());
  b.setVal245(e.IsSVECount());
  b.setVal246(e.IsSignedInteger());
  b.setVal247(e.IsSugared());
  b.setVal248(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSugared());
}

void SerializeBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSigned());
  b.setVal238(e.IsSugared());
  b.setVal239(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Attribute()));
  b.setVal242(es.EntityId(e.WrappedType()));
  b.setVal237(e.IsSugared());
}

void SerializeAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  auto v236 = e.Attribute();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  b.setVal284(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal242(es.EntityId(e.EquivalentType()));
  auto v244 = e.ImmediateNullability();
  if (v244) {
    b.setVal244(static_cast<unsigned char>(v244.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  b.setVal243(es.EntityId(e.ModifiedType()));
  b.setVal238(e.HasAttribute());
  b.setVal239(e.IsCallingConv());
  b.setVal245(e.IsMSTypeSpec());
  b.setVal246(e.IsQualifier());
  b.setVal247(e.IsSugared());
  b.setVal248(e.IsWebAssemblyFuncrefSpec());
}

void SerializeAtomicType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ValueType()));
  b.setVal237(e.IsSugared());
}

void SerializeArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.ElementType()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  if (auto r242 = e.BracketsRange(); auto rs242 = r242.Size()) {
    b.setVal242(es.EntityId(r242[0]));
    b.setVal243(es.EntityId(r242[rs242 - 1u]));
  } else {
    b.setVal242(0);
    b.setVal243(0);
  }
  auto et276 = es.EntityId(e.LBracketToken());
  b.setVal276(et276);
  auto et277 = es.EntityId(e.RBracketToken());
  b.setVal277(et277);
  b.setVal282(es.EntityId(e.SizeExpression()));
  b.setVal237(e.IsSugared());
}

void SerializeIncompleteArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSugared());
}

void SerializeDependentSizedArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  if (auto r242 = e.BracketsRange(); auto rs242 = r242.Size()) {
    b.setVal242(es.EntityId(r242[0]));
    b.setVal243(es.EntityId(r242[rs242 - 1u]));
  } else {
    b.setVal242(0);
    b.setVal243(0);
  }
  auto et276 = es.EntityId(e.LBracketToken());
  b.setVal276(et276);
  auto et277 = es.EntityId(e.RBracketToken());
  b.setVal277(et277);
  b.setVal282(es.EntityId(e.SizeExpression()));
  b.setVal237(e.IsSugared());
}

void SerializeConstantArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal236(es.EntityId(e.Desugar()));
  auto v242 = e.SizeExpression();
  if (v242) {
    auto id242 = es.EntityId(v242.value());
    b.setVal242(id242);
  } else {
    b.setVal242(mx::kInvalidEntityId);
  }
  b.setVal237(e.IsSugared());
}

void SerializeAdjustedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ResolvedType()));
  b.setVal242(es.EntityId(e.OriginalType()));
  b.setVal237(e.IsSugared());
}

void SerializeDecayedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(pf, es, b, e, nullptr);
}

void SerializeTypeWithKeyword(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.NamedType()));
  auto v242 = e.OwnedTagDeclaration();
  if (v242) {
    auto id242 = es.EntityId(v242.value());
    b.setVal242(id242);
  } else {
    b.setVal242(mx::kInvalidEntityId);
  }
  b.setVal237(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSugared());
  do {
    auto v240 = e.TemplateArguments();
    auto sv240 = b.initVal240(static_cast<unsigned>(v240.size()));
    auto i240 = 0u;
    for (const auto &e240 : v240) {
      sv240.set(i240, es.EntityId(e240));
      ++i240;
    }
  } while (false);
}

void SerializeDependentNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal237(e.IsSugared());
}

void SerializeVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.ElementType()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal237(e.IsSugared());
}

void SerializeExtVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ExtVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVectorType(pf, es, b, e, nullptr);
}

void SerializeUsingType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UsingType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.FoundDeclaration()));
  b.setVal242(es.EntityId(e.UnderlyingType()));
  b.setVal237(e.IsSugared());
  b.setVal238(e.TypeMatchesDeclaration());
}

void SerializeUnresolvedUsingType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Declaration()));
  b.setVal237(e.IsSugared());
}

void SerializeUnaryTransformType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.BaseType()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal242(es.EntityId(e.UnderlyingType()));
  b.setVal237(e.IsSugared());
}

void SerializeTypedefType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal236(es.EntityId(e.Declaration()));
  b.setVal237(e.IsSugared());
  b.setVal238(e.TypeMatchesDeclaration());
}

void SerializeTypeOfType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal236(es.EntityId(e.UnmodifiedType()));
  b.setVal237(e.IsSugared());
}

void SerializeTypeOfExprType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal244(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal236(es.EntityId(e.UnderlyingExpression()));
  b.setVal237(e.IsSugared());
}

void SerializeStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e, const TokenTree *) {
  (void) pf;
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

void SerializeSEHTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.ExceptHandler()));
  b.setVal10(es.EntityId(e.FinallyHandler()));
  b.setVal11(es.EntityId(e.Handler()));
  b.setVal12(e.IsCXXTry());
  b.setVal13(es.EntityId(e.TryBlock()));
  auto et14 = es.EntityId(e.TryToken());
  b.setVal14(et14);
}

void SerializeSEHLeaveStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.LeaveToken());
  b.setVal9(et9);
}

void SerializeSEHFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto et10 = es.EntityId(e.FinallyToken());
  b.setVal10(et10);
}

void SerializeSEHExceptStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto et10 = es.EntityId(e.ExceptToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et11 = es.EntityId(e.ReturnToken());
  b.setVal11(et11);
}

void SerializeObjCForCollectionStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Collection()));
  b.setVal11(es.EntityId(e.Element()));
  auto et13 = es.EntityId(e.ForToken());
  b.setVal13(et13);
  auto et14 = es.EntityId(e.RParenToken());
  b.setVal14(et14);
}

void SerializeObjCAutoreleasePoolStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtTryToken());
  b.setVal9(et9);
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

void SerializeObjCAtThrowStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.ThrowExpression()));
  auto et10 = es.EntityId(e.ThrowToken());
  b.setVal10(et10);
}

void SerializeObjCAtSynchronizedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtSynchronizedToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SynchBody()));
  b.setVal11(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtFinallyToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtCatchToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.CatchBody()));
  b.setVal11(es.EntityId(e.CatchParameterDeclaration()));
  auto et13 = es.EntityId(e.RParenToken());
  b.setVal13(et13);
  b.setVal12(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.AssociatedStatement()));
  b.setVal10(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal11(es.EntityId(e.RawStatement()));
  b.setVal13(es.EntityId(e.StructuredBlock()));
  b.setVal12(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPErrorDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPErrorDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDispatchDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  auto et14 = es.EntityId(e.TargetCallToken());
  b.setVal14(et14);
}

void SerializeOMPDepobjDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCriticalDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCancellationPointDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCancelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPBarrierDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPAtomicDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
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

void SerializeOMPTeamsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskyieldDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskwaitDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskgroupDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetEnterDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPSingleDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPSectionsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSectionDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPScopeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScopeDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPScanDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelSectionsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPOrderedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.IfStatement()));
}

void SerializeOMPMasterDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMaskedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopBasedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopTransformationDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopBasedDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.PreInitializers()));
  b.setVal17(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPUnrollDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopTransformationDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTileDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopTransformationDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopBasedDirective(pf, es, b, e, nullptr);
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

void SerializeOMPGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsGenericLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsGenericLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelGenericLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPInteropDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPFlushDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCanonicalLoop(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal10(es.EntityId(e.LoopStatement()));
  b.setVal11(es.EntityId(e.LoopVariableFunc()));
  b.setVal13(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.SemiToken());
  b.setVal9(et9);
  b.setVal12(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.KeywordToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto v9 = e.ConstantTarget();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  auto et10 = es.EntityId(e.GotoToken());
  b.setVal10(et10);
  auto et11 = es.EntityId(e.StarToken());
  b.setVal11(et11);
  b.setVal13(es.EntityId(e.Target()));
}

void SerializeIfStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et14 = es.EntityId(e.ElseToken());
  b.setVal14(et14);
  auto et17 = es.EntityId(e.IfToken());
  b.setVal17(et17);
  auto v18 = e.Initializer();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto et19 = es.EntityId(e.LParenToken());
  b.setVal19(et19);
  auto v20 = e.NondiscardedCase();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  auto et21 = es.EntityId(e.RParenToken());
  b.setVal21(et21);
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal22(es.EntityId(e.Then()));
  b.setVal12(e.HasElseStorage());
  b.setVal16(e.HasInitializerStorage());
  b.setVal23(e.HasVariableStorage());
  b.setVal24(e.IsConsteval());
  b.setVal25(e.IsConstexpr());
  b.setVal57(e.IsNegatedConsteval());
  b.setVal58(e.IsNonNegatedConsteval());
  b.setVal59(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.GotoToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.Label()));
  auto et11 = es.EntityId(e.LabelToken());
  b.setVal11(et11);
}

void SerializeForStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et14 = es.EntityId(e.ForToken());
  b.setVal14(et14);
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
  auto et19 = es.EntityId(e.LParenToken());
  b.setVal19(et19);
  auto et20 = es.EntityId(e.RParenToken());
  b.setVal20(et20);
}

void SerializeDoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto et11 = es.EntityId(e.DoToken());
  b.setVal11(et11);
  auto et13 = es.EntityId(e.RParenToken());
  b.setVal13(et13);
  auto et14 = es.EntityId(e.WhileToken());
  b.setVal14(et14);
}

void SerializeDeclStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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

void SerializeCoroutineBodyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  do {
    auto v15 = e.ChildrenExclBody();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal9(es.EntityId(e.Allocate()));
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Deallocate()));
  b.setVal13(es.EntityId(e.ExceptionHandler()));
  b.setVal14(es.EntityId(e.FallthroughHandler()));
  b.setVal17(es.EntityId(e.FinalSuspendStatement()));
  b.setVal18(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v26 = e.ParameterMoves();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  b.setVal19(es.EntityId(e.PromiseDeclaration()));
  b.setVal20(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal21(es.EntityId(e.ResultDeclaration()));
  b.setVal22(es.EntityId(e.ReturnStatement()));
  b.setVal30(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal31(es.EntityId(e.ReturnValue()));
  b.setVal32(es.EntityId(e.ReturnValueInitializer()));
  b.setVal12(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.KeywordToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.Operand()));
  b.setVal11(es.EntityId(e.PromiseCall()));
  b.setVal12(e.IsImplicit());
}

void SerializeContinueStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.ContinueToken());
  b.setVal9(et9);
}

void SerializeCompoundStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.LeftBraceToken());
  b.setVal9(et9);
  auto et10 = es.EntityId(e.RightBraceToken());
  b.setVal10(et10);
  auto v11 = e.StatementExpressionResult();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  b.setVal12(e.HasStoredFPFeatures());
}

void SerializeCapturedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal11(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.TryBlock()));
  auto et10 = es.EntityId(e.TryToken());
  b.setVal10(et10);
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

void SerializeCXXForRangeStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.BeginStatement()));
  b.setVal10(es.EntityId(e.Body()));
  auto et11 = es.EntityId(e.CoawaitToken());
  b.setVal11(et11);
  auto et13 = es.EntityId(e.ColonToken());
  b.setVal13(et13);
  b.setVal14(es.EntityId(e.Condition()));
  b.setVal17(es.EntityId(e.EndStatement()));
  auto et18 = es.EntityId(e.ForToken());
  b.setVal18(et18);
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
  auto et30 = es.EntityId(e.RParenToken());
  b.setVal30(et30);
  b.setVal31(es.EntityId(e.RangeInitializer()));
  b.setVal32(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.CatchToken());
  b.setVal9(et9);
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

void SerializeBreakStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.BreakToken());
  b.setVal9(et9);
}

void SerializeAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal60(e.GenerateAssemblyString());
  auto et9 = es.EntityId(e.AssemblyToken());
  b.setVal9(et9);
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
    auto v61 = e.OutputConstraints();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      std::string se61(e61.data(), e61.size());
      sv61.set(i61, se61);
      ++i61;
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
    auto v62 = e.InputConstraints();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      std::string se62(e62.data(), e62.size());
      sv62.set(i62, se62);
      ++i62;
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
    auto v63 = e.Clobbers();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      std::string se63(e63.data(), e63.size());
      sv63.set(i63, se63);
      ++i63;
    }
  } while (false);
}

void SerializeMSAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeAsmStmt(pf, es, b, e, nullptr);
  do {
    auto v64 = e.AllConstraints();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
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
  auto v65 = e.AssemblyString();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto et10 = es.EntityId(e.LBraceToken());
  b.setVal10(et10);
  b.setVal23(e.HasBraces());
}

void SerializeGCCAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeAsmStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.AssemblyString()));
  auto et11 = es.EntityId(e.RParenToken());
  b.setVal11(et11);
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
    auto v52 = e.OutputConstraintLiterals();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
  do {
    auto v64 = e.OutputNames();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
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
    auto v66 = e.InputNames();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
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
    auto v67 = e.LabelExpressions();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      sv67.set(i67, es.EntityId(e67));
      ++i67;
    }
  } while (false);
  do {
    auto v68 = e.LabelNames();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
    }
  } while (false);
}

void SerializeWhileStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et14 = es.EntityId(e.LParenToken());
  b.setVal14(et14);
  auto et17 = es.EntityId(e.RParenToken());
  b.setVal17(et17);
  auto et18 = es.EntityId(e.WhileToken());
  b.setVal18(et18);
  b.setVal12(e.HasVariableStorage());
}

void SerializeValueStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Declaration()));
  auto et11 = es.EntityId(e.IdentifierToken());
  b.setVal11(et11);
  auto v60 = e.Name();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal13(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsSideEntry());
}

void SerializeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
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
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.Dependence())));
  auto et32 = es.EntityId(e.ExpressionToken());
  b.setVal32(et32);
  auto v33 = e.ObjCProperty();
  if (v33) {
    auto id33 = es.EntityId(v33.value());
    b.setVal33(id33);
  } else {
    b.setVal33(mx::kInvalidEntityId);
  }
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v34 = e.ReferencedDeclarationOfCallee();
  if (v34) {
    auto id34 = es.EntityId(v34.value());
    b.setVal34(id34);
  } else {
    b.setVal34(mx::kInvalidEntityId);
  }
  auto v35 = e.SourceBitField();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
  } else {
    b.setVal35(mx::kInvalidEntityId);
  }
  auto v36 = e.Type();
  if (v36) {
    auto id36 = es.EntityId(v36.value());
    b.setVal36(id36);
  } else {
    b.setVal36(mx::kInvalidEntityId);
  }
  b.setVal70(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal24(e.HasNonTrivialCall());
  auto v25 = e.IsCXX98IntegralConstantExpression();
  if (v25) {
    b.setVal25(static_cast<bool>(v25.value()));
    b.setVal57(true);
  } else {
    b.setVal57(false);
  }
  b.setVal58(e.IsDefaultArgument());
  b.setVal59(e.IsGLValue());
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

void SerializeDesignatedInitUpdateExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v15 = e.Designators();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  if (auto r37 = e.DesignatorsTokens(); auto rs37 = r37.Size()) {
    b.setVal37(es.EntityId(r37[0]));
    b.setVal38(es.EntityId(r37[rs37 - 1u]));
  } else {
    b.setVal37(0);
    b.setVal38(0);
  }
  auto et39 = es.EntityId(e.EqualOrColonToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal89(e.IsDirectInitializer());
  b.setVal90(e.UsesGNUSyntax());
  do {
    auto v26 = e.SubExpressions();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LAngleToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RAngleToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.TemplateKeywordToken());
  b.setVal39(et39);
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.KeywordToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal39(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Declaration()));
  b.setVal38(es.EntityId(e.FoundDeclaration()));
  auto et39 = es.EntityId(e.LAngleToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RAngleToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.TemplateKeywordToken());
  b.setVal41(et41);
  b.setVal89(e.HadMultipleCandidates());
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasQualifier());
  b.setVal92(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal93(e.HasTemplateKeyword());
  b.setVal94(e.IsImmediateEscalating());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal96(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.CommonExpression()));
  auto et38 = es.EntityId(e.KeywordToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.OpaqueValue()));
  b.setVal40(es.EntityId(e.Operand()));
  b.setVal41(es.EntityId(e.ReadyExpression()));
  b.setVal42(es.EntityId(e.ResumeExpression()));
  b.setVal43(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
  b.setVal89(e.IsImplicit());
}

void SerializeCoyieldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.ConceptNameToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.FoundDeclaration()));
  b.setVal39(es.EntityId(e.NamedConcept()));
  b.setVal40(es.EntityId(e.SpecializationDeclaration()));
  do {
    auto v15 = e.TemplateArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto et41 = es.EntityId(e.TemplateKeywordToken());
  b.setVal41(et41);
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Initializer()));
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  b.setVal89(e.IsFileScope());
}

void SerializeChooseExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.ChosenSubExpression()));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.LHS()));
  b.setVal41(es.EntityId(e.RHS()));
  auto et42 = es.EntityId(e.RParenToken());
  b.setVal42(et42);
  b.setVal89(e.IsConditionDependent());
  b.setVal90(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v60 = e.CastKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto v37 = e.ConversionFunction();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal39(es.EntityId(e.SubExpressionAsWritten()));
  auto v40 = e.TargetUnionField();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal89(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal90(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  if (auto r42 = e.AngleBrackets(); auto rs42 = r42.Size()) {
    b.setVal42(es.EntityId(r42[0]));
    b.setVal43(es.EntityId(r42[rs42 - 1u]));
  } else {
    b.setVal42(0);
    b.setVal43(0);
  }
  auto v65 = e.CastName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto et44 = es.EntityId(e.OperatorToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.RParenToken());
  b.setVal45(et45);
}

void SerializeCXXDynamicCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
  b.setVal90(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXAddrspaceCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXStaticCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXReinterpretCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXFunctionalCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.LParenToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
  b.setVal90(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.LParenToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
}

void SerializeBuiltinBitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.BridgeKeywordToken());
  b.setVal42(et42);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v65 = e.BridgeKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto et43 = es.EntityId(e.LParenToken());
  b.setVal43(et43);
}

void SerializeCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.Callee()));
  auto v39 = e.CalleeDeclaration();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.DirectCallee();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
  b.setVal89(e.HasStoredFPFeatures());
  b.setVal90(e.HasUnusedResultAttribute());
  b.setVal91(e.IsBuiltinAssumeFalse());
  b.setVal92(e.IsCallToStdMove());
  b.setVal93(e.IsUnevaluatedBuiltinCall());
  b.setVal94(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et42 = es.EntityId(e.OperatorToken());
  b.setVal42(et42);
  b.setVal96(e.IsAssignmentOperation());
  b.setVal98(e.IsComparisonOperation());
  b.setVal99(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.ImplicitObjectArgument()));
  auto v43 = e.MethodDeclaration();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  b.setVal44(es.EntityId(e.ObjectType()));
  b.setVal45(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.CookedLiteral()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto et43 = es.EntityId(e.UDSuffixToken());
  b.setVal43(et43);
}

void SerializeCXXUuidofExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal38(es.EntityId(e.GuidDeclaration()));
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal89(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.TypeAsWritten()));
  b.setVal89(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.ExpressionOperand();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal38(es.EntityId(e.TypeOperand()));
  b.setVal39(es.EntityId(e.TypeOperandSourceInfo()));
  auto v89 = e.IsMostDerived();
  if (v89) {
    b.setVal89(static_cast<bool>(v89.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal91(e.IsPotentiallyEvaluated());
  b.setVal92(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.SubExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto et38 = es.EntityId(e.ThrowToken());
  b.setVal38(et38);
  b.setVal89(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.RParenToken());
  b.setVal37(et37);
}

void SerializeCXXRewrittenBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et38 = es.EntityId(e.OperatorToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal89(e.IsAssignmentOperation());
  b.setVal90(e.IsComparisonOperation());
  b.setVal91(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  auto et38 = es.EntityId(e.ColonColonToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.DestroyedType()));
  auto et40 = es.EntityId(e.DestroyedTypeToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.OperatorToken());
  b.setVal41(et41);
  auto v42 = e.ScopeType();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto et43 = es.EntityId(e.TildeToken());
  b.setVal43(et43);
  b.setVal89(e.HasQualifier());
  b.setVal90(e.IsArrow());
}

void SerializeCXXParenListInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXParenListInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.ArrayFiller()));
  auto et38 = es.EntityId(e.InitializerToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.InitializedFieldInUnion()));
}

void SerializeCXXNullPtrLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeCXXNoexceptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal89(e.Value());
}

void SerializeCXXNewExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.AllocatedType()));
  auto v38 = e.ArraySize();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.ConstructExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  if (auto r40 = e.DirectInitializerRange(); auto rs40 = r40.Size()) {
    b.setVal40(es.EntityId(r40[0]));
    b.setVal41(es.EntityId(r40[rs40 - 1u]));
  } else {
    b.setVal40(0);
    b.setVal41(0);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v42 = e.Initializer();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
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
  b.setVal90(e.HasInitializer());
  b.setVal91(e.IsArray());
  b.setVal92(e.IsGlobalNew());
  b.setVal93(e.IsParenthesisTypeId());
  b.setVal94(e.PassAlignment());
  do {
    auto v15 = e.PlacementArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal96(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.ConstructsVirtualBase());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  b.setVal90(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Callee()));
  auto et38 = es.EntityId(e.EllipsisToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.LHS()));
  auto et41 = es.EntityId(e.LParenToken());
  b.setVal41(et41);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  auto et44 = es.EntityId(e.RParenToken());
  b.setVal44(et44);
  b.setVal89(e.IsLeftFold());
  b.setVal90(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.Base();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal38(es.EntityId(e.BaseType()));
  auto v39 = e.FirstQualifierFoundInScope();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto et40 = es.EntityId(e.LAngleToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.MemberToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.OperatorToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RAngleToken());
  b.setVal43(et43);
  auto et44 = es.EntityId(e.TemplateKeywordToken());
  b.setVal44(et44);
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasTemplateKeyword());
  b.setVal91(e.IsArrow());
  b.setVal92(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  b.setVal38(es.EntityId(e.DestroyedType()));
  b.setVal39(es.EntityId(e.OperatorDelete()));
  b.setVal90(e.IsArrayForm());
  b.setVal91(e.IsArrayFormAsWritten());
  b.setVal92(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.Expression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal38(es.EntityId(e.Field()));
  b.setVal39(es.EntityId(e.RewrittenExpression()));
  auto et40 = es.EntityId(e.UsedToken());
  b.setVal40(et40);
  b.setVal89(e.HasRewrittenInitializer());
}

void SerializeCXXDefaultArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AdjustedRewrittenExpression()));
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.RewrittenExpression()));
  auto et41 = es.EntityId(e.UsedToken());
  b.setVal41(et41);
  b.setVal89(e.HasRewrittenInitializer());
}

void SerializeCXXConstructExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  b.setVal37(es.EntityId(e.Constructor()));
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  if (auto r39 = e.ParenthesisOrBraceRange(); auto rs39 = r39.Size()) {
    b.setVal39(es.EntityId(r39[0]));
    b.setVal40(es.EntityId(r39[rs39 - 1u]));
  } else {
    b.setVal39(0);
    b.setVal40(0);
  }
  b.setVal89(e.HadMultipleCandidates());
  b.setVal90(e.IsElidable());
  b.setVal91(e.IsImmediateEscalating());
  b.setVal92(e.IsListInitialization());
  b.setVal93(e.IsStdInitializerListInitialization());
  b.setVal94(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXConstructExpr(pf, es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.Value());
}

void SerializeCXXBindTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.BlockDeclaration()));
  b.setVal38(es.EntityId(e.Body()));
  auto et39 = es.EntityId(e.CaretToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto et38 = es.EntityId(e.OperatorToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal89(e.HasStoredFPFeatures());
  b.setVal90(e.IsAdditiveOperation());
  b.setVal91(e.IsAssignmentOperation());
  b.setVal92(e.IsBitwiseOperation());
  b.setVal93(e.IsCommaOperation());
  b.setVal94(e.IsComparisonOperation());
  b.setVal96(e.IsCompoundAssignmentOperation());
  b.setVal98(e.IsEqualityOperation());
  b.setVal99(e.IsLogicalOperation());
  b.setVal100(e.IsMultiplicativeOperation());
  b.setVal101(e.IsPointerMemoryOperation());
  b.setVal102(e.IsRelationalOperation());
  b.setVal103(e.IsShiftAssignOperation());
  b.setVal104(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  (void) pf;
  SerializeBinaryOperator(pf, es, b, e, nullptr);
  b.setVal40(es.EntityId(e.ComputationLHSType()));
  b.setVal41(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  auto v60 = e.OperationAsString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal38(es.EntityId(e.Order()));
  auto v39 = e.OrderFail();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.Pointer()));
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
  auto v42 = e.Scope();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto v43 = e.Value1();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto v44 = e.Value2();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal45(es.EntityId(e.ValueType()));
  auto v46 = e.Weak();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal89(e.IsCmpXChg());
  b.setVal90(e.IsOpenCL());
  b.setVal91(e.IsVolatile());
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

void SerializeAsTypeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.DimensionExpression()));
  b.setVal38(es.EntityId(e.QueriedType()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  b.setVal39(es.EntityId(e.LHS()));
  auto et40 = es.EntityId(e.RBracketToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.CommonExpression()));
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AmpAmpToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Label()));
  auto et39 = es.EntityId(e.LabelToken());
  b.setVal39(et39);
}

void SerializeAbstractConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.ColonToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Condition()));
  b.setVal39(es.EntityId(e.FalseExpression()));
  auto et40 = es.EntityId(e.QuestionToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.Common()));
  b.setVal43(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal40(es.EntityId(e.WrittenType()));
  b.setVal89(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.CanOverflow());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.IsArithmeticOperation());
  b.setVal92(e.IsDecrementOperation());
  b.setVal93(e.IsIncrementDecrementOperation());
  b.setVal94(e.IsIncrementOperation());
  b.setVal96(e.IsPostfix());
  b.setVal98(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.ArgumentExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto v38 = e.ArgumentType();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.KeywordKind())));
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.TypeOfArgument()));
  b.setVal89(e.IsArgumentType());
}

void SerializeTypoExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v89 = e.Value();
  if (v89) {
    b.setVal89(static_cast<bool>(v89.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
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

void SerializeSubstNonTypeTemplateParmPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AssociatedDeclaration()));
  b.setVal38(es.EntityId(e.ParameterPack()));
  auto et39 = es.EntityId(e.ParameterPackToken());
  b.setVal39(et39);
}

void SerializeSubstNonTypeTemplateParmExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AssociatedDeclaration()));
  auto et38 = es.EntityId(e.NameToken());
  b.setVal38(et38);
  auto v105 = e.PackIndex();
  if (v105) {
    b.setVal105(static_cast<uint32_t>(v105.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
  b.setVal90(e.IsReferenceParameter());
}

void SerializeStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v89 = e.ContainsNonAscii();
  if (v89) {
    b.setVal89(static_cast<bool>(v89.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  auto v91 = e.ContainsNonAsciiOrNull();
  if (v91) {
    b.setVal91(static_cast<bool>(v91.value()));
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  auto v60 = e.Bytes();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto v65 = e.String();
  if (v65) {
    if (v65->empty()) {
      b.setVal65("");
    } else {
      std::string s65(v65->data(), v65->size());
      b.setVal65(s65);
    }
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.IsOrdinary());
  b.setVal96(e.IsPascal());
  b.setVal98(e.IsUTF16());
  b.setVal99(e.IsUTF32());
  b.setVal100(e.IsUTF8());
  b.setVal101(e.IsUnevaluated());
  b.setVal102(e.IsWide());
}

void SerializeStmtExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v60 = e.BuiltinString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsIntType());
}

void SerializeSizeOfPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Pack()));
  auto v105 = e.PackLength();
  if (v105) {
    b.setVal105(static_cast<uint32_t>(v105.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  auto et39 = es.EntityId(e.PackToken());
  b.setVal39(et39);
  do {
    auto ov15 = e.PartialArguments();
    if (!ov15) {
      b.setVal90(false);
      break;
    }
    b.setVal90(true);
    auto v15 = std::move(*ov15);
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal91(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeSYCLUniqueStableNameExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal60(e.ComputeName());
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeRequiresExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Body()));
  do {
    auto v15 = e.LocalParameters();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto et38 = es.EntityId(e.RBraceToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.RequiresKeywordToken());
  b.setVal39(et39);
  b.setVal89(e.IsSatisfied());
}

void SerializeRecoveryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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

void SerializePseudoObjectExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.ResultExpression()));
  b.setVal38(es.EntityId(e.SyntacticForm()));
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

void SerializePredefinedExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.FunctionName()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v60 = e.IdentifierKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  b.setVal89(e.IsTransparent());
}

void SerializeParenListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
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

void SerializeParenExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.EllipsisToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LAngleToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.NameToken());
  b.setVal38(et38);
  auto v39 = e.NamingClass();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto et40 = es.EntityId(e.RAngleToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.TemplateKeywordToken());
  b.setVal41(et41);
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.Base()));
  b.setVal43(es.EntityId(e.BaseType()));
  auto et44 = es.EntityId(e.MemberToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.OperatorToken());
  b.setVal45(et45);
  b.setVal91(e.HasUnresolvedUsing());
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal91(e.IsOverloaded());
  b.setVal92(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal89(e.IsUnique());
}

void SerializeOffsetOfExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeObjCSubscriptRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.KeyExpression()));
  auto et40 = es.EntityId(e.RBracketToken());
  b.setVal40(et40);
  b.setVal89(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeObjCProtocolExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Protocol()));
  auto et39 = es.EntityId(e.ProtocolIdToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
}

void SerializeObjCPropertyRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ExplicitProperty()));
  b.setVal40(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal41(es.EntityId(e.ImplicitPropertySetter()));
  auto et42 = es.EntityId(e.Token());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.ReceiverToken());
  b.setVal43(et43);
  b.setVal44(es.EntityId(e.ReceiverType()));
  b.setVal45(es.EntityId(e.SuperReceiverType()));
  b.setVal89(e.IsClassReceiver());
  b.setVal90(e.IsExplicitProperty());
  b.setVal91(e.IsImplicitProperty());
  b.setVal92(e.IsMessagingGetter());
  b.setVal93(e.IsMessagingSetter());
  b.setVal94(e.IsObjectReceiver());
  b.setVal96(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal37(es.EntityId(e.CallReturnType()));
  b.setVal38(es.EntityId(e.ClassReceiver()));
  b.setVal39(es.EntityId(e.ClassReceiverType()));
  b.setVal40(es.EntityId(e.InstanceReceiver()));
  auto et41 = es.EntityId(e.LeftToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.MethodDeclaration()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal43(es.EntityId(e.ReceiverInterface()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r44 = e.ReceiverRange(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal46(es.EntityId(e.ReceiverType()));
  auto et47 = es.EntityId(e.RightToken());
  b.setVal47(et47);
  auto et48 = es.EntityId(e.SelectorStartToken());
  b.setVal48(et48);
  auto et49 = es.EntityId(e.SuperToken());
  b.setVal49(et49);
  b.setVal50(es.EntityId(e.SuperType()));
  b.setVal89(e.IsClassMessage());
  b.setVal90(e.IsDelegateInitializerCall());
  b.setVal91(e.IsImplicit());
  b.setVal92(e.IsInstanceMessage());
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

void SerializeObjCIvarRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Declaration()));
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.OperationToken());
  b.setVal40(et40);
  b.setVal89(e.IsArrow());
  b.setVal90(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  auto et38 = es.EntityId(e.BaseTokenEnd());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.IsaMemberToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.OperationToken());
  b.setVal40(et40);
  b.setVal89(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal89(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.EncodedType()));
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeObjCDictionaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.BoxingMethod()));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal89(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.HasVersion());
}

void SerializeObjCArrayLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.ArrayWithObjectsMethod()));
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

void SerializeOMPIteratorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.IteratorKwToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeOMPArrayShapingExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  do {
    auto v15 = e.Dimensions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeOMPArraySectionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  auto et38 = es.EntityId(e.FirstColonToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.SecondColonToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Length()));
  b.setVal41(es.EntityId(e.LowerBound()));
  auto et42 = es.EntityId(e.RBracketToken());
  b.setVal42(et42);
  b.setVal43(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  auto et38 = es.EntityId(e.LAngleToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.MemberDeclaration()));
  auto et40 = es.EntityId(e.MemberToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.OperatorToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.RAngleToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.TemplateKeywordToken());
  b.setVal43(et43);
  b.setVal89(e.HadMultipleCandidates());
  b.setVal90(e.HasExplicitTemplateArguments());
  b.setVal91(e.HasQualifier());
  b.setVal92(e.HasTemplateKeyword());
  b.setVal93(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  auto et39 = es.EntityId(e.RBracketToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal89(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.ExtendingDeclaration();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto v38 = e.LifetimeExtendedTemporaryDeclaration();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal89(e.IsBoundToLvalueReference());
  b.setVal90(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  auto et39 = es.EntityId(e.RBracketToken());
  b.setVal39(et39);
}

void SerializeMSPropertyRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.BaseExpression()));
  auto et38 = es.EntityId(e.MemberToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.PropertyDeclaration()));
  b.setVal89(e.IsArrow());
  b.setVal90(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto et39 = es.EntityId(e.CaptureDefaultToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.CompoundStatementBody()));
  auto v41 = e.DependentCallOperator();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
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
  auto v45 = e.TemplateParameterList();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto v46 = e.TrailingRequiresClause();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal89(e.HasExplicitParameters());
  b.setVal90(e.HasExplicitResultType());
  b.setVal91(e.IsGenericLambda());
  b.setVal92(e.IsMutable());
}

void SerializeIntegerLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeInitListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.ArrayFiller();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto v38 = e.InitializedFieldInUnion();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto et39 = es.EntityId(e.LBraceToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RBraceToken());
  b.setVal40(et40);
  auto v41 = e.SemanticForm();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.SyntacticForm();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  b.setVal89(e.HadArrayRangeDesignator());
  b.setVal90(e.HasArrayFiller());
  b.setVal91(e.HasDesignatedInitializer());
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

void SerializeImplicitValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v15 = e.AssociationExpressions();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal37(es.EntityId(e.ControllingExpression()));
  b.setVal38(es.EntityId(e.ControllingType()));
  auto et39 = es.EntityId(e.DefaultToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.GenericToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.ResultExpression()));
  b.setVal89(e.IsExpressionPredicate());
  b.setVal90(e.IsResultDependent());
  b.setVal91(e.IsTypePredicate());
}

void SerializeGNUNullExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.TokenToken());
  b.setVal37(et37);
}

void SerializeFunctionParmPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.ParameterPack()));
  auto et38 = es.EntityId(e.ParameterPackToken());
  b.setVal38(et38);
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

void SerializeFullExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  (void) pf;
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal89(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  (void) pf;
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal89(e.HasAPValueResult());
  b.setVal90(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsExact());
}

void SerializeFixedPointLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeExtVectorElementExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.ContainsDuplicateElements());
  auto et37 = es.EntityId(e.AccessorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal90(e.IsArrow());
}

void SerializeExpressionTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal89(e.Value());
}

void SerializeAttributedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AttributeToken());
  b.setVal10(et10);
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

void SerializeSwitchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et17 = es.EntityId(e.LParenToken());
  b.setVal17(et17);
  auto et18 = es.EntityId(e.RParenToken());
  b.setVal18(et18);
  auto v19 = e.FirstSwitchCase();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto et20 = es.EntityId(e.SwitchToken());
  b.setVal20(et20);
  b.setVal12(e.HasInitializerStorage());
  b.setVal16(e.HasVariableStorage());
  b.setVal23(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.ColonToken());
  b.setVal9(et9);
  auto et10 = es.EntityId(e.KeywordToken());
  b.setVal10(et10);
  auto v11 = e.NextSwitchCase();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  b.setVal13(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e, const TokenTree *) {
  (void) pf;
  SerializeSwitchCase(pf, es, b, e, nullptr);
  auto et14 = es.EntityId(e.DefaultToken());
  b.setVal14(et14);
}

void SerializeCaseStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
  (void) pf;
  SerializeSwitchCase(pf, es, b, e, nullptr);
  b.setVal12(e.CaseStatementIsGNURange());
  auto et14 = es.EntityId(e.CaseToken());
  b.setVal14(et14);
  auto et17 = es.EntityId(e.EllipsisToken());
  b.setVal17(et17);
  b.setVal18(es.EntityId(e.LHS()));
  auto v19 = e.RHS();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
}

void SerializeDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e, const TokenTree *) {
  (void) pf;
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
    b.setVal11(static_cast<uint32_t>(v11.value()));
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
  b.setVal23(e.IsFunctionPointerType());
  b.setVal24(e.IsImplicit());
  b.setVal25(e.IsInAnonymousNamespace());
  b.setVal26(e.IsInAnotherModuleUnit());
  b.setVal27(e.IsInExportDeclarationContext());
  auto v28 = e.IsInLocalScopeForInstantiation();
  if (v28) {
    b.setVal28(static_cast<bool>(v28.value()));
    b.setVal29(true);
  } else {
    b.setVal29(false);
  }
  b.setVal30(e.IsInStdNamespace());
  b.setVal31(e.IsInvalidDeclaration());
  b.setVal32(e.IsInvisibleOutsideTheOwningModule());
  b.setVal33(e.IsLocalExternDeclaration());
  b.setVal34(e.IsModulePrivate());
  b.setVal35(e.IsOutOfLine());
  b.setVal36(e.IsParameterPack());
  b.setVal37(e.IsReachable());
  b.setVal38(e.IsTemplateDeclaration());
  b.setVal39(e.IsTemplateParameter());
  b.setVal40(e.IsTemplateParameterPack());
  b.setVal41(e.IsTemplated());
  b.setVal42(e.IsThisDeclarationReferenced());
  b.setVal43(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal44(e.IsUnavailable());
  b.setVal45(e.IsUnconditionallyVisible());
  b.setVal46(e.IsWeakImported());
  b.setVal47(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal48(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto et49 = es.EntityId(e.Token());
  if (!et49) {
    et49 = pf.DeclTokenEntityId(e);
  }
  b.setVal49(et49);
  if (auto r50 = e.Tokens(); auto rs50 = r50.Size()) {
    b.setVal50(es.EntityId(r50[0]));
    b.setVal51(es.EntityId(r50[rs50 - 1u]));
  } else {
    b.setVal50(0);
    b.setVal51(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.Specialization()));
  b.setVal53(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.ContextParameter()));
  b.setVal53(e.IsNothrow());
  do {
    auto v54 = e.Parameters();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeBlockDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal53(e.BlockMissingReturnType());
  b.setVal56(e.CanAvoidCopyToHeap());
  b.setVal57(e.CapturesCXXThis());
  b.setVal58(e.DoesNotEscape());
  auto v52 = e.BlockManglingContextDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  auto et59 = es.EntityId(e.CaretToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.CompoundBody()));
  b.setVal61(es.EntityId(e.SignatureAsWritten()));
  b.setVal62(e.HasCaptures());
  b.setVal63(e.IsConversionFromLambda());
  b.setVal64(e.IsVariadic());
  do {
    auto v54 = e.Parameters();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v55 = e.ParameterDeclarations();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
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

void SerializeAccessSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et52 = es.EntityId(e.AccessSpecifierToken());
  b.setVal52(et52);
  auto et59 = es.EntityId(e.ColonToken());
  b.setVal59(et59);
}

void SerializeOMPDeclarativeDirectiveDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

void SerializeOMPThreadPrivateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPThreadPrivateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Varlists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeOMPRequiresDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPRequiresDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(pf, es, b, e, nullptr);
}

void SerializeOMPAllocateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPAllocateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Varlists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeTopLevelStmtDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.Statement()));
  b.setVal53(e.IsSemiMissing());
}

void SerializeStaticAssertDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.AssertExpression()));
  b.setVal59(es.EntityId(e.Message()));
  auto et60 = es.EntityId(e.RParenToken());
  b.setVal60(et60);
  b.setVal53(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializePragmaDetectMismatchDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v66 = e.Name();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  auto v67 = e.Value();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
}

void SerializePragmaCommentDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v66 = e.Argument();
  std::string s66(v66.data(), v66.size());
  b.setVal66(s66);
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.GetterCXXConstructor()));
  b.setVal59(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal60(es.EntityId(e.PropertyDeclaration()));
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal61(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto et69 = es.EntityId(e.PropertyInstanceVariableDeclarationToken());
  b.setVal69(et69);
  b.setVal70(es.EntityId(e.SetterCXXAssignment()));
  b.setVal71(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal53(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal66(e.Name());
  auto v72 = e.ObjCFStringFormattingFamily();
  if (v72) {
    b.setVal72(static_cast<unsigned char>(v72.value()));
    b.setVal53(true);
  } else {
    b.setVal53(false);
  }
  b.setVal67(e.QualifiedNameAsString());
  b.setVal52(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal56(e.HasExternalFormalLinkage());
  b.setVal57(e.HasLinkage());
  b.setVal58(e.HasLinkageBeenComputed());
  b.setVal62(e.IsCXXClassMember());
  b.setVal63(e.IsCXXInstanceMember());
  b.setVal64(e.IsExternallyDeclarable());
  b.setVal74(e.IsExternallyVisible());
  b.setVal75(e.IsLinkageValid());
}

void SerializeLabelDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v76 = e.MSAssemblyLabel();
  std::string s76(v76.data(), v76.size());
  b.setVal76(s76);
  b.setVal59(es.EntityId(e.Statement()));
  b.setVal77(e.IsGnuLocal());
  b.setVal78(e.IsMSAssemblyLabel());
  b.setVal79(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.LBraceToken());
  b.setVal59(et59);
  auto et60 = es.EntityId(e.TokenStart());
  b.setVal60(et60);
  auto et61 = es.EntityId(e.RBraceToken());
  b.setVal61(et61);
  b.setVal77(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Shadows();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeUsingEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.EnumDeclaration()));
  auto et60 = es.EntityId(e.EnumToken());
  b.setVal60(et60);
  b.setVal61(es.EntityId(e.EnumType()));
  auto et69 = es.EntityId(e.UsingToken());
  b.setVal69(et69);
}

void SerializeUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.UsingToken());
  b.setVal59(et59);
  b.setVal77(e.HasTypename());
  b.setVal78(e.IsAccessDeclaration());
}

void SerializeValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v59 = e.PotentiallyDecomposedVariableDeclaration();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
  b.setVal60(es.EntityId(e.Type()));
  b.setVal77(e.IsInitializerCapture());
  b.setVal78(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et61 = es.EntityId(e.EllipsisToken());
  b.setVal61(et61);
  auto et69 = es.EntityId(e.UsingToken());
  b.setVal69(et69);
  b.setVal79(e.IsAccessDeclaration());
  b.setVal80(e.IsPackExpansion());
}

void SerializeUnnamedGlobalConstantDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnnamedGlobalConstantDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
}

void SerializeTemplateParamObjectDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateParamObjectDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
}

void SerializeOMPDeclareReductionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareReductionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.Combiner()));
  b.setVal69(es.EntityId(e.CombinerIn()));
  b.setVal70(es.EntityId(e.CombinerOut()));
  b.setVal71(es.EntityId(e.InitializerOriginal()));
  b.setVal81(es.EntityId(e.InitializerPrivate()));
  b.setVal82(es.EntityId(e.Initializer()));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeMSGuidDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSGuidDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
}

void SerializeIndirectFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::IndirectFieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Chain();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  auto v61 = e.AnonymousField();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  auto v69 = e.VariableDeclaration();
  if (v69) {
    auto id69 = es.EntityId(v69.value());
    b.setVal69(id69);
  } else {
    b.setVal69(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto v61 = e.InitializerExpression();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et61 = es.EntityId(e.FirstInnerToken());
  b.setVal61(et61);
  auto et69 = es.EntityId(e.FirstOuterToken());
  b.setVal69(et69);
  auto v70 = e.TrailingRequiresClause();
  if (v70) {
    auto id70 = es.EntityId(v70.value());
    b.setVal70(id70);
  } else {
    b.setVal70(mx::kInvalidEntityId);
  }
  auto et71 = es.EntityId(e.TypeSpecEndToken());
  b.setVal71(et71);
  auto et81 = es.EntityId(e.TypeSpecStartToken());
  b.setVal81(et81);
  do {
    auto v54 = e.TemplateParameterLists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v82 = e.ActingDefinition();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v84 = e.DescribedVariableTemplate();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v85 = e.Initializer();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v86 = e.InitializingDeclaration();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
  } else {
    b.setVal86(mx::kInvalidEntityId);
  }
  auto v87 = e.InstantiatedFromStaticDataMember();
  if (v87) {
    auto id87 = es.EntityId(v87.value());
    b.setVal87(id87);
  } else {
    b.setVal87(mx::kInvalidEntityId);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto et89 = es.EntityId(e.PointOfInstantiation());
  b.setVal89(et89);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v94 = e.TemplateInstantiationPattern();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
  } else {
    b.setVal94(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal79(e.HasConstantInitialization());
  b.setVal80(e.HasDependentAlignment());
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
  b.setVal116(e.IsInline());
  b.setVal117(e.IsInlineSpecified());
  b.setVal118(e.IsKnownToBeDefined());
  b.setVal119(e.IsLocalVariableDeclaration());
  b.setVal120(e.IsLocalVariableDeclarationOrParm());
  b.setVal121(e.IsNRVOVariable());
  b.setVal122(e.IsNoDestroy());
  b.setVal123(e.IsNonEscapingByref());
  b.setVal124(e.IsObjCForDeclaration());
  b.setVal125(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal126(e.IsStaticDataMember());
  b.setVal127(e.IsStaticLocal());
  b.setVal128(e.IsThisDeclarationADemotedDefinition());
  b.setVal129(e.IsUsableInConstantExpressions());
  b.setVal130(e.MightBeUsableInConstantExpressions());
}

void SerializeParmVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto v131 = e.DefaultArgument();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  if (auto r132 = e.DefaultArgumentRange(); auto rs132 = r132.Size()) {
    b.setVal132(es.EntityId(r132[0]));
    b.setVal133(es.EntityId(r132[rs132 - 1u]));
  } else {
    b.setVal132(0);
    b.setVal133(0);
  }
  b.setVal134(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal135(es.EntityId(e.OriginalType()));
  auto v136 = e.UninstantiatedDefaultArgument();
  if (v136) {
    auto id136 = es.EntityId(v136.value());
    b.setVal136(id136);
  } else {
    b.setVal136(mx::kInvalidEntityId);
  }
  b.setVal137(e.HasDefaultArgument());
  b.setVal138(e.HasInheritedDefaultArgument());
  b.setVal139(e.HasUninstantiatedDefaultArgument());
  b.setVal140(e.HasUnparsedDefaultArgument());
  b.setVal141(e.IsDestroyedInCallee());
  b.setVal142(e.IsKNRPromoted());
  b.setVal143(e.IsObjCMethodParameter());
}

void SerializeOMPCapturedExprDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPCapturedExprDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
}

void SerializeImplicitParamDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitParamDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  b.setVal134(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  do {
    auto v55 = e.Bindings();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto et131 = es.EntityId(e.ExternToken());
  b.setVal131(et131);
  b.setVal134(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal132(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v55 = e.TemplateArguments();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v65 = e.TemplateInstantiationArguments();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
  auto et133 = es.EntityId(e.TemplateKeywordToken());
  b.setVal133(et133);
  b.setVal135(es.EntityId(e.TypeAsWritten()));
  b.setVal137(e.IsClassScopeExplicitSpecialization());
  b.setVal138(e.IsExplicitInstantiationOrSpecialization());
  b.setVal139(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal136(es.EntityId(e.InstantiatedFromMember()));
  b.setVal144(es.EntityId(e.TemplateParameters()));
  b.setVal140(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal79(e.DefaultArgumentWasInherited());
  auto v82 = e.DefaultArgument();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto et84 = es.EntityId(e.DefaultArgumentToken());
  b.setVal84(et84);
  auto v85 = e.PlaceholderTypeConstraint();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal80(e.HasDefaultArgument());
  b.setVal97(e.HasPlaceholderTypeConstraint());
  b.setVal98(e.IsExpandedParameterPack());
  b.setVal99(e.IsPackExpansion());
  do {
    auto v55 = e.ExpansionTypes();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
}

void SerializeMSPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal79(e.HasGetter());
  b.setVal80(e.HasSetter());
}

void SerializeFunctionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal79(e.BodyContainsImmediateEscalatingExpressions());
  b.setVal80(e.FriendConstraintRefersToEnclosingTemplate());
  b.setVal97(e.UsesFPIntrin());
  auto v98 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v98) {
    b.setVal98(static_cast<bool>(v98.value()));
    b.setVal99(true);
  } else {
    b.setVal99(false);
  }
  b.setVal100(e.DoesThisDeclarationHaveABody());
  b.setVal82(es.EntityId(e.CallResultType()));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal84(es.EntityId(e.DeclaredReturnType()));
  auto et85 = es.EntityId(e.DefaultToken());
  b.setVal85(et85);
  auto v86 = e.DescribedFunctionTemplate();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
  } else {
    b.setVal86(mx::kInvalidEntityId);
  }
  auto et87 = es.EntityId(e.EllipsisToken());
  b.setVal87(et87);
  if (auto r89 = e.ExceptionSpecTokens(); auto rs89 = r89.Size()) {
    b.setVal89(es.EntityId(r89[0]));
    b.setVal94(es.EntityId(r89[rs89 - 1u]));
  } else {
    b.setVal89(0);
    b.setVal94(0);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v131 = e.InstantiatedFromDeclaration();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  auto v132 = e.InstantiatedFromMemberFunction();
  if (v132) {
    auto id132 = es.EntityId(v132.value());
    b.setVal132(id132);
  } else {
    b.setVal132(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v145 = e.ODRHash();
  if (v145) {
    b.setVal145(static_cast<uint32_t>(v145.value()));
    b.setVal101(true);
  } else {
    b.setVal101(false);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r133 = e.ParametersTokens(); auto rs133 = r133.Size()) {
    b.setVal133(es.EntityId(r133[0]));
    b.setVal135(es.EntityId(r133[rs133 - 1u]));
  } else {
    b.setVal133(0);
    b.setVal135(0);
  }
  auto et136 = es.EntityId(e.PointOfInstantiation());
  b.setVal136(et136);
  auto v144 = e.PrimaryTemplate();
  if (v144) {
    auto id144 = es.EntityId(v144.value());
    b.setVal144(id144);
  } else {
    b.setVal144(mx::kInvalidEntityId);
  }
  b.setVal146(es.EntityId(e.ReturnType()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v147 = e.TemplateInstantiationPattern();
  if (v147) {
    auto id147 = es.EntityId(v147.value());
    b.setVal147(id147);
  } else {
    b.setVal147(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal134(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal102(e.HasImplicitReturnZero());
  b.setVal103(e.HasInheritedPrototype());
  b.setVal104(e.HasOneParameterOrDefaultArguments());
  b.setVal105(e.HasPrototype());
  b.setVal106(e.HasSkippedBody());
  b.setVal107(e.HasTrivialBody());
  b.setVal108(e.HasWrittenPrototype());
  b.setVal109(e.InstantiationIsPending());
  b.setVal110(e.IsCPUDispatchMultiVersion());
  b.setVal111(e.IsCPUSpecificMultiVersion());
  b.setVal112(e.IsConsteval());
  b.setVal113(e.IsConstexpr());
  b.setVal114(e.IsConstexprSpecified());
  b.setVal115(e.IsDefaulted());
  b.setVal116(e.IsDeleted());
  b.setVal117(e.IsDeletedAsWritten());
  b.setVal118(e.IsDestroyingOperatorDelete());
  b.setVal119(e.IsExplicitlyDefaulted());
  b.setVal120(e.IsExternC());
  b.setVal121(e.IsFunctionTemplateSpecialization());
  b.setVal122(e.IsGlobal());
  b.setVal123(e.IsImmediateEscalating());
  b.setVal124(e.IsImmediateFunction());
  b.setVal125(e.IsImplicitlyInstantiable());
  b.setVal126(e.IsInExternCContext());
  b.setVal127(e.IsInExternCXXContext());
  b.setVal128(e.IsIneligibleOrNotSelected());
  b.setVal129(e.IsInlineBuiltinDeclaration());
  auto v130 = e.IsInlineDefinitionExternallyVisible();
  if (v130) {
    b.setVal130(static_cast<bool>(v130.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  b.setVal138(e.IsInlineSpecified());
  b.setVal139(e.IsInlined());
  b.setVal140(e.IsLateTemplateParsed());
  auto v141 = e.IsMSExternInline();
  if (v141) {
    b.setVal141(static_cast<bool>(v141.value()));
    b.setVal142(true);
  } else {
    b.setVal142(false);
  }
  b.setVal143(e.IsMSVCRTEntryPoint());
  b.setVal148(e.IsMain());
  b.setVal149(e.IsMemberLikeConstrainedFriend());
  b.setVal150(e.IsMultiVersion());
  b.setVal151(e.IsNoReturn());
  b.setVal152(e.IsOverloadedOperator());
  b.setVal153(e.IsPure());
  b.setVal154(e.IsReplaceableGlobalAllocationFunction());
  auto v155 = e.IsReservedGlobalPlacementOperator();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  b.setVal157(e.IsStatic());
  b.setVal158(e.IsTargetClonesMultiVersion());
  b.setVal159(e.IsTargetMultiVersion());
  b.setVal160(e.IsTemplateInstantiation());
  b.setVal161(e.IsThisDeclarationADefinition());
  b.setVal162(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal163(e.IsTrivial());
  b.setVal164(e.IsTrivialForCall());
  b.setVal165(e.IsUserProvided());
  b.setVal166(e.IsVariadic());
  b.setVal167(e.IsVirtualAsWritten());
  do {
    auto v55 = e.Parameters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  b.setVal168(e.UsesSEHTry());
  b.setVal169(e.WillHaveBody());
  auto v170 = e.Body();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
  }
  pasta::DeclContext dc65(e);
  auto v65 = dc65.AlreadyLoadedDeclarations();
  auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
  auto i65 = 0u;
  for (const pasta::Decl &e65 : v65) {
    sv65.set(i65, es.EntityId(e65));
    ++i65;
  }
}

void SerializeCXXMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal171(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v172 = e.ThisObjectType();
  if (v172) {
    auto id172 = es.EntityId(v172.value());
    b.setVal172(id172);
  } else {
    b.setVal172(mx::kInvalidEntityId);
  }
  auto v173 = e.ThisType();
  if (v173) {
    auto id173 = es.EntityId(v173.value());
    b.setVal173(id173);
  } else {
    b.setVal173(mx::kInvalidEntityId);
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
    auto v182 = e.OverriddenMethods();
    auto sv182 = b.initVal182(static_cast<unsigned>(v182.size()));
    auto i182 = 0u;
    for (const auto &e182 : v182) {
      sv182.set(i182, es.EntityId(e182));
      ++i182;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v183 = e.OperatorDelete();
  if (v183) {
    auto id183 = es.EntityId(v183.value());
    b.setVal183(id183);
  } else {
    b.setVal183(mx::kInvalidEntityId);
  }
  auto v184 = e.OperatorDeleteThisArgument();
  if (v184) {
    auto id184 = es.EntityId(v184.value());
    b.setVal184(id184);
  } else {
    b.setVal184(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  b.setVal183(es.EntityId(e.ConversionType()));
  b.setVal185(e.IsExplicit());
  b.setVal186(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v183 = e.TargetConstructor();
  if (v183) {
    auto id183 = es.EntityId(v183.value());
    b.setVal183(id183);
  } else {
    b.setVal183(mx::kInvalidEntityId);
  }
  b.setVal185(e.IsDefaultConstructor());
  b.setVal186(e.IsDelegatingConstructor());
  b.setVal187(e.IsExplicit());
  b.setVal188(e.IsInheritingConstructor());
  b.setVal189(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal172(es.EntityId(e.CorrespondingConstructor()));
  b.setVal173(es.EntityId(e.DeducedTemplate()));
  b.setVal171(static_cast<unsigned char>(mx::FromPasta(e.DeductionCandidateKind())));
  b.setVal174(e.IsExplicit());
}

void SerializeFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v82 = e.BitWidth();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v84 = e.CapturedVLAType();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v85 = e.InClassInitializer();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  b.setVal79(e.HasCapturedVLAType());
  b.setVal80(e.HasInClassInitializer());
  b.setVal97(e.HasNonNullInClassInitializer());
  b.setVal98(e.IsAnonymousStructOrUnion());
  b.setVal99(e.IsBitField());
  b.setVal100(e.IsMutable());
  b.setVal101(e.IsPotentiallyOverlapping());
  b.setVal102(e.IsUnnamedBitfield());
  b.setVal103(e.IsZeroLengthBitField());
  b.setVal104(e.IsZeroSize());
  auto v86 = e.OffsetInBits();
  if (v86) {
    b.setVal86(static_cast<uint64_t>(v86.value()));
    b.setVal105(true);
  } else {
    b.setVal105(false);
  }
}

void SerializeObjCIvarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(pf, es, b, e, nullptr);
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal87(es.EntityId(e.ContainingInterface()));
  b.setVal89(es.EntityId(e.NextInstanceVariable()));
  b.setVal106(e.Synthesize());
}

void SerializeObjCAtDefsFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCAtDefsFieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(pf, es, b, e, nullptr);
}

void SerializeBindingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BindingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.Binding()));
  b.setVal69(es.EntityId(e.DecomposedDeclaration()));
  b.setVal70(es.EntityId(e.HoldingVariable()));
}

void SerializeOMPDeclarativeDirectiveValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclarativeDirectiveValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
}

void SerializeOMPDeclareMapperDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::OMPDeclareMapperDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeOMPDeclarativeDirectiveValueDecl(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.Introducer()));
  auto v60 = e.NextUsingShadowDeclaration();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  b.setVal61(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(pf, es, b, e, nullptr);
  b.setVal77(e.ConstructsVirtualBase());
  b.setVal69(es.EntityId(e.ConstructedBaseClass()));
  auto v70 = e.ConstructedBaseClassShadowDeclaration();
  if (v70) {
    auto id70 = es.EntityId(v70.value());
    b.setVal70(id70);
  } else {
    b.setVal70(mx::kInvalidEntityId);
  }
  b.setVal71(es.EntityId(e.NominatedBaseClass()));
  auto v81 = e.NominatedBaseClassShadowDeclaration();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Expansions();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  b.setVal59(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.IdentifierToken());
  b.setVal59(et59);
  auto et60 = es.EntityId(e.NamespaceKeyToken());
  b.setVal60(et60);
  b.setVal61(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto et69 = es.EntityId(e.UsingToken());
  b.setVal69(et69);
}

void SerializeUnresolvedUsingIfExistsDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingIfExistsDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
}

void SerializeTypeDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v59 = e.TypeForDeclaration();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  b.setVal77(e.DefaultArgumentWasInherited());
  auto v60 = e.DefaultArgument();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  auto v61 = e.DefaultArgumentInfo();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  auto et69 = es.EntityId(e.DefaultArgumentToken());
  b.setVal69(et69);
  b.setVal78(e.HasDefaultArgument());
  b.setVal79(e.HasTypeConstraint());
  b.setVal80(e.IsExpandedParameterPack());
  b.setVal97(e.IsPackExpansion());
  b.setVal98(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  if (auto r60 = e.BraceRange(); auto rs60 = r60.Size()) {
    b.setVal60(es.EntityId(r60[0]));
    b.setVal61(es.EntityId(r60[rs60 - 1u]));
  } else {
    b.setVal60(0);
    b.setVal61(0);
  }
  auto et69 = es.EntityId(e.FirstInnerToken());
  b.setVal69(et69);
  auto et70 = es.EntityId(e.FirstOuterToken());
  b.setVal70(et70);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v71 = e.TypedefNameForAnonymousDeclaration();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
  } else {
    b.setVal71(mx::kInvalidEntityId);
  }
  b.setVal77(e.HasNameForLinkage());
  b.setVal78(e.IsBeingDefined());
  b.setVal79(e.IsClass());
  b.setVal80(e.IsCompleteDefinition());
  b.setVal97(e.IsCompleteDefinitionRequired());
  b.setVal98(e.IsDependentType());
  b.setVal99(e.IsEnum());
  b.setVal100(e.IsFreeStanding());
  b.setVal101(e.IsInterface());
  b.setVal102(e.IsStruct());
  b.setVal103(e.IsThisDeclarationADefinition());
  b.setVal104(e.IsThisDeclarationADemotedDefinition());
  b.setVal105(e.IsUnion());
  b.setVal106(e.MayHaveOutOfDateDefinition());
  do {
    auto v54 = e.TemplateParameterLists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  pasta::DeclContext dc55(e);
  auto v55 = dc55.AlreadyLoadedDeclarations();
  auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
  auto i55 = 0u;
  for (const pasta::Decl &e55 : v55) {
    sv55.set(i55, es.EntityId(e55));
    ++i55;
  }
}

void SerializeRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  b.setVal107(e.CanPassInRegisters());
  do {
    auto v65 = e.Fields();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
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
  auto v81 = e.Size();
  if (v81) {
    b.setVal81(static_cast<uint64_t>(v81.value()));
    b.setVal127(true);
  } else {
    b.setVal127(false);
  }
  auto v82 = e.Alignment();
  if (v82) {
    b.setVal82(static_cast<uint64_t>(v82.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  auto v84 = e.SizeWithoutTrailingPadding();
  if (v84) {
    b.setVal84(static_cast<uint64_t>(v84.value()));
    b.setVal129(true);
  } else {
    b.setVal129(false);
  }
}

void SerializeCXXRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(pf, es, b, e, nullptr);
  auto v130 = e.AllowConstDefaultInitializer();
  if (v130) {
    b.setVal130(static_cast<bool>(v130.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  do {
    auto ov182 = e.Bases();
    if (!ov182) {
      b.setVal138(false);
      break;
    }
    b.setVal138(true);
    auto v182 = std::move(*ov182);
    auto sv182 = b.initVal182(static_cast<unsigned>(v182.size()));
    auto i182 = 0u;
    for (const auto &e182 : v182) {
      sv182.set(i182, es.EntityId(e182));
      ++i182;
    }
  } while (false);
  auto v90 = e.CalculateInheritanceModel();
  if (v90) {
    b.setVal90(static_cast<unsigned char>(v90.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  do {
    auto v190 = e.Constructors();
    auto sv190 = b.initVal190(static_cast<unsigned>(v190.size()));
    auto i190 = 0u;
    for (const auto &e190 : v190) {
      sv190.set(i190, es.EntityId(e190));
      ++i190;
    }
  } while (false);
  do {
    auto ov191 = e.Friends();
    if (!ov191) {
      b.setVal140(false);
      break;
    }
    b.setVal140(true);
    auto v191 = std::move(*ov191);
    auto sv191 = b.initVal191(static_cast<unsigned>(v191.size()));
    auto i191 = 0u;
    for (const auto &e191 : v191) {
      sv191.set(i191, es.EntityId(e191));
      ++i191;
    }
  } while (false);
  auto v85 = e.DependentLambdaCallOperator();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  auto v86 = e.DescribedClassTemplate();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
  } else {
    b.setVal86(mx::kInvalidEntityId);
  }
  auto v87 = e.Destructor();
  if (v87) {
    auto id87 = es.EntityId(v87.value());
    b.setVal87(id87);
  } else {
    b.setVal87(mx::kInvalidEntityId);
  }
  auto v89 = e.GenericLambdaTemplateParameterList();
  if (v89) {
    auto id89 = es.EntityId(v89.value());
    b.setVal89(id89);
  } else {
    b.setVal89(mx::kInvalidEntityId);
  }
  auto v94 = e.InstantiatedFromMemberClass();
  if (v94) {
    auto id94 = es.EntityId(v94.value());
    b.setVal94(id94);
  } else {
    b.setVal94(mx::kInvalidEntityId);
  }
  auto v131 = e.LambdaCallOperator();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  auto v91 = e.LambdaCaptureDefault();
  if (v91) {
    b.setVal91(static_cast<unsigned char>(v91.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v132 = e.LambdaContextDeclaration();
  if (v132) {
    auto id132 = es.EntityId(v132.value());
    b.setVal132(id132);
  } else {
    b.setVal132(mx::kInvalidEntityId);
  }
  do {
    auto ov192 = e.LambdaExplicitTemplateParameters();
    if (!ov192) {
      b.setVal142(false);
      break;
    }
    b.setVal142(true);
    auto v192 = std::move(*ov192);
    auto sv192 = b.initVal192(static_cast<unsigned>(v192.size()));
    auto i192 = 0u;
    for (const auto &e192 : v192) {
      sv192.set(i192, es.EntityId(e192));
      ++i192;
    }
  } while (false);
  auto v145 = e.LambdaManglingNumber();
  if (v145) {
    b.setVal145(static_cast<uint32_t>(v145.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v133 = e.LambdaType();
  if (v133) {
    auto id133 = es.EntityId(v133.value());
    b.setVal133(id133);
  } else {
    b.setVal133(mx::kInvalidEntityId);
  }
  auto v92 = e.MSInheritanceModel();
  if (v92) {
    b.setVal92(static_cast<unsigned char>(v92.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v193 = e.ODRHash();
  if (v193) {
    b.setVal193(static_cast<uint32_t>(v193.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v135 = e.TemplateInstantiationPattern();
  if (v135) {
    auto id135 = es.EntityId(v135.value());
    b.setVal135(id135);
  } else {
    b.setVal135(mx::kInvalidEntityId);
  }
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
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
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v160 = e.HasCopyConstructorWithConstParameter();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v162 = e.HasDefaultConstructor();
  if (v162) {
    b.setVal162(static_cast<bool>(v162.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v164 = e.HasDefinition();
  if (v164) {
    b.setVal164(static_cast<bool>(v164.value()));
    b.setVal165(true);
  } else {
    b.setVal165(false);
  }
  auto v166 = e.HasDirectFields();
  if (v166) {
    b.setVal166(static_cast<bool>(v166.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v168 = e.HasFriends();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
    b.setVal169(true);
  } else {
    b.setVal169(false);
  }
  auto v174 = e.HasInClassInitializer();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
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
  auto v180 = e.HasInitializerMethod();
  if (v180) {
    b.setVal180(static_cast<bool>(v180.value()));
    b.setVal181(true);
  } else {
    b.setVal181(false);
  }
  auto v185 = e.HasIrrelevantDestructor();
  if (v185) {
    b.setVal185(static_cast<bool>(v185.value()));
    b.setVal186(true);
  } else {
    b.setVal186(false);
  }
  auto v187 = e.HasKnownLambdaInternalLinkage();
  if (v187) {
    b.setVal187(static_cast<bool>(v187.value()));
    b.setVal188(true);
  } else {
    b.setVal188(false);
  }
  auto v189 = e.HasMoveAssignment();
  if (v189) {
    b.setVal189(static_cast<bool>(v189.value()));
    b.setVal194(true);
  } else {
    b.setVal194(false);
  }
  auto v195 = e.HasMoveConstructor();
  if (v195) {
    b.setVal195(static_cast<bool>(v195.value()));
    b.setVal196(true);
  } else {
    b.setVal196(false);
  }
  auto v197 = e.HasMutableFields();
  if (v197) {
    b.setVal197(static_cast<bool>(v197.value()));
    b.setVal198(true);
  } else {
    b.setVal198(false);
  }
  auto v199 = e.HasNonLiteralTypeFieldsOrBases();
  if (v199) {
    b.setVal199(static_cast<bool>(v199.value()));
    b.setVal200(true);
  } else {
    b.setVal200(false);
  }
  auto v201 = e.HasNonTrivialCopyAssignment();
  if (v201) {
    b.setVal201(static_cast<bool>(v201.value()));
    b.setVal202(true);
  } else {
    b.setVal202(false);
  }
  auto v203 = e.HasNonTrivialCopyConstructor();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  auto v205 = e.HasNonTrivialCopyConstructorForCall();
  if (v205) {
    b.setVal205(static_cast<bool>(v205.value()));
    b.setVal206(true);
  } else {
    b.setVal206(false);
  }
  auto v207 = e.HasNonTrivialDefaultConstructor();
  if (v207) {
    b.setVal207(static_cast<bool>(v207.value()));
    b.setVal208(true);
  } else {
    b.setVal208(false);
  }
  auto v209 = e.HasNonTrivialDestructor();
  if (v209) {
    b.setVal209(static_cast<bool>(v209.value()));
    b.setVal210(true);
  } else {
    b.setVal210(false);
  }
  auto v211 = e.HasNonTrivialDestructorForCall();
  if (v211) {
    b.setVal211(static_cast<bool>(v211.value()));
    b.setVal212(true);
  } else {
    b.setVal212(false);
  }
  auto v213 = e.HasNonTrivialMoveAssignment();
  if (v213) {
    b.setVal213(static_cast<bool>(v213.value()));
    b.setVal214(true);
  } else {
    b.setVal214(false);
  }
  auto v215 = e.HasNonTrivialMoveConstructor();
  if (v215) {
    b.setVal215(static_cast<bool>(v215.value()));
    b.setVal216(true);
  } else {
    b.setVal216(false);
  }
  auto v217 = e.HasNonTrivialMoveConstructorForCall();
  if (v217) {
    b.setVal217(static_cast<bool>(v217.value()));
    b.setVal218(true);
  } else {
    b.setVal218(false);
  }
  auto v219 = e.HasPrivateFields();
  if (v219) {
    b.setVal219(static_cast<bool>(v219.value()));
    b.setVal220(true);
  } else {
    b.setVal220(false);
  }
  auto v221 = e.HasProtectedFields();
  if (v221) {
    b.setVal221(static_cast<bool>(v221.value()));
    b.setVal222(true);
  } else {
    b.setVal222(false);
  }
  auto v223 = e.HasSimpleCopyAssignment();
  if (v223) {
    b.setVal223(static_cast<bool>(v223.value()));
    b.setVal224(true);
  } else {
    b.setVal224(false);
  }
  auto v225 = e.HasSimpleCopyConstructor();
  if (v225) {
    b.setVal225(static_cast<bool>(v225.value()));
    b.setVal226(true);
  } else {
    b.setVal226(false);
  }
  auto v227 = e.HasSimpleDestructor();
  if (v227) {
    b.setVal227(static_cast<bool>(v227.value()));
    b.setVal228(true);
  } else {
    b.setVal228(false);
  }
  auto v229 = e.HasSimpleMoveAssignment();
  if (v229) {
    b.setVal229(static_cast<bool>(v229.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  auto v231 = e.HasSimpleMoveConstructor();
  if (v231) {
    b.setVal231(static_cast<bool>(v231.value()));
    b.setVal232(true);
  } else {
    b.setVal232(false);
  }
  auto v233 = e.HasTrivialCopyAssignment();
  if (v233) {
    b.setVal233(static_cast<bool>(v233.value()));
    b.setVal234(true);
  } else {
    b.setVal234(false);
  }
  auto v235 = e.HasTrivialCopyConstructor();
  if (v235) {
    b.setVal235(static_cast<bool>(v235.value()));
    b.setVal236(true);
  } else {
    b.setVal236(false);
  }
  auto v237 = e.HasTrivialCopyConstructorForCall();
  if (v237) {
    b.setVal237(static_cast<bool>(v237.value()));
    b.setVal238(true);
  } else {
    b.setVal238(false);
  }
  auto v239 = e.HasTrivialDefaultConstructor();
  if (v239) {
    b.setVal239(static_cast<bool>(v239.value()));
    b.setVal240(true);
  } else {
    b.setVal240(false);
  }
  auto v241 = e.HasTrivialDestructor();
  if (v241) {
    b.setVal241(static_cast<bool>(v241.value()));
    b.setVal242(true);
  } else {
    b.setVal242(false);
  }
  auto v243 = e.HasTrivialDestructorForCall();
  if (v243) {
    b.setVal243(static_cast<bool>(v243.value()));
    b.setVal244(true);
  } else {
    b.setVal244(false);
  }
  auto v245 = e.HasTrivialMoveAssignment();
  if (v245) {
    b.setVal245(static_cast<bool>(v245.value()));
    b.setVal246(true);
  } else {
    b.setVal246(false);
  }
  auto v247 = e.HasTrivialMoveConstructor();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  auto v249 = e.HasTrivialMoveConstructorForCall();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  auto v251 = e.HasUninitializedReferenceMember();
  if (v251) {
    b.setVal251(static_cast<bool>(v251.value()));
    b.setVal252(true);
  } else {
    b.setVal252(false);
  }
  auto v253 = e.HasUserDeclaredConstructor();
  if (v253) {
    b.setVal253(static_cast<bool>(v253.value()));
    b.setVal254(true);
  } else {
    b.setVal254(false);
  }
  auto v255 = e.HasUserDeclaredCopyAssignment();
  if (v255) {
    b.setVal255(static_cast<bool>(v255.value()));
    b.setVal256(true);
  } else {
    b.setVal256(false);
  }
  auto v257 = e.HasUserDeclaredCopyConstructor();
  if (v257) {
    b.setVal257(static_cast<bool>(v257.value()));
    b.setVal258(true);
  } else {
    b.setVal258(false);
  }
  auto v259 = e.HasUserDeclaredDestructor();
  if (v259) {
    b.setVal259(static_cast<bool>(v259.value()));
    b.setVal260(true);
  } else {
    b.setVal260(false);
  }
  auto v261 = e.HasUserDeclaredMoveAssignment();
  if (v261) {
    b.setVal261(static_cast<bool>(v261.value()));
    b.setVal262(true);
  } else {
    b.setVal262(false);
  }
  auto v263 = e.HasUserDeclaredMoveConstructor();
  if (v263) {
    b.setVal263(static_cast<bool>(v263.value()));
    b.setVal264(true);
  } else {
    b.setVal264(false);
  }
  auto v265 = e.HasUserDeclaredMoveOperation();
  if (v265) {
    b.setVal265(static_cast<bool>(v265.value()));
    b.setVal266(true);
  } else {
    b.setVal266(false);
  }
  auto v267 = e.HasUserProvidedDefaultConstructor();
  if (v267) {
    b.setVal267(static_cast<bool>(v267.value()));
    b.setVal268(true);
  } else {
    b.setVal268(false);
  }
  auto v269 = e.HasVariantMembers();
  if (v269) {
    b.setVal269(static_cast<bool>(v269.value()));
    b.setVal270(true);
  } else {
    b.setVal270(false);
  }
  auto v271 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v271) {
    b.setVal271(static_cast<bool>(v271.value()));
    b.setVal272(true);
  } else {
    b.setVal272(false);
  }
  auto v273 = e.ImplicitCopyConstructorHasConstParameter();
  if (v273) {
    b.setVal273(static_cast<bool>(v273.value()));
    b.setVal274(true);
  } else {
    b.setVal274(false);
  }
  auto v275 = e.IsAbstract();
  if (v275) {
    b.setVal275(static_cast<bool>(v275.value()));
    b.setVal276(true);
  } else {
    b.setVal276(false);
  }
  auto v277 = e.IsAggregate();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.IsAnyDestructorNoReturn();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsCLike();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v283 = e.IsCXX11StandardLayout();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  b.setVal285(e.IsDependentLambda());
  auto v286 = e.IsDynamicClass();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v288 = e.IsEffectivelyFinal();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  auto v290 = e.IsEmpty();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  b.setVal292(e.IsGenericLambda());
  auto v293 = e.IsInterfaceLike();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v295 = e.IsLiteral();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v136 = e.IsLocalClass();
  if (v136) {
    auto id136 = es.EntityId(v136.value());
    b.setVal136(id136);
  } else {
    b.setVal136(mx::kInvalidEntityId);
  }
  b.setVal297(e.IsNeverDependentLambda());
  auto v298 = e.IsPOD();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v300 = e.IsPolymorphic();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.IsStandardLayout();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.IsStructural();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.IsTrivial();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.IsTriviallyCopyable();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.MayBeAbstract();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.MayBeDynamicClass();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.MayBeNonDynamicClass();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  do {
    auto ov318 = e.Methods();
    if (!ov318) {
      b.setVal319(false);
      break;
    }
    b.setVal319(true);
    auto v318 = std::move(*ov318);
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  auto v320 = e.NeedsImplicitCopyAssignment();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.NeedsImplicitCopyConstructor();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.NeedsImplicitDefaultConstructor();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsImplicitDestructor();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NeedsImplicitMoveAssignment();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  auto v330 = e.NeedsImplicitMoveConstructor();
  if (v330) {
    b.setVal330(static_cast<bool>(v330.value()));
    b.setVal331(true);
  } else {
    b.setVal331(false);
  }
  auto v332 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v332) {
    b.setVal332(static_cast<bool>(v332.value()));
    b.setVal333(true);
  } else {
    b.setVal333(false);
  }
  auto v334 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v334) {
    b.setVal334(static_cast<bool>(v334.value()));
    b.setVal335(true);
  } else {
    b.setVal335(false);
  }
  auto v336 = e.NeedsOverloadResolutionForDestructor();
  if (v336) {
    b.setVal336(static_cast<bool>(v336.value()));
    b.setVal337(true);
  } else {
    b.setVal337(false);
  }
  auto v338 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v338) {
    b.setVal338(static_cast<bool>(v338.value()));
    b.setVal339(true);
  } else {
    b.setVal339(false);
  }
  auto v340 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v340) {
    b.setVal340(static_cast<bool>(v340.value()));
    b.setVal341(true);
  } else {
    b.setVal341(false);
  }
  auto v342 = e.NullFieldOffsetIsZero();
  if (v342) {
    b.setVal342(static_cast<bool>(v342.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  do {
    auto ov344 = e.VirtualBases();
    if (!ov344) {
      b.setVal345(false);
      break;
    }
    b.setVal345(true);
    auto v344 = std::move(*ov344);
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
  auto v144 = e.SizeWithoutVirtualBases();
  if (v144) {
    b.setVal144(static_cast<uint64_t>(v144.value()));
    b.setVal346(true);
  } else {
    b.setVal346(false);
  }
  auto v146 = e.PrimaryBase();
  if (v146) {
    auto id146 = es.EntityId(v146.value());
    b.setVal146(id146);
  } else {
    b.setVal146(mx::kInvalidEntityId);
  }
  auto v347 = e.HasOwnVirtualFunctionTablePointer();
  if (v347) {
    b.setVal347(static_cast<bool>(v347.value()));
    b.setVal348(true);
  } else {
    b.setVal348(false);
  }
  auto v349 = e.HasExtendableVirtualFunctionTablePointer();
  if (v349) {
    b.setVal349(static_cast<bool>(v349.value()));
    b.setVal350(true);
  } else {
    b.setVal350(false);
  }
  auto v351 = e.HasVirtualBaseTablePointer();
  if (v351) {
    b.setVal351(static_cast<bool>(v351.value()));
    b.setVal352(true);
  } else {
    b.setVal352(false);
  }
  auto v353 = e.HasOwnVirtualBaseTablePointer();
  if (v353) {
    b.setVal353(static_cast<bool>(v353.value()));
    b.setVal354(true);
  } else {
    b.setVal354(false);
  }
}

void SerializeClassTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(pf, es, b, e, nullptr);
  auto et147 = es.EntityId(e.ExternToken());
  b.setVal147(et147);
  auto et170 = es.EntityId(e.PointOfInstantiation());
  b.setVal170(et170);
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal172(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v355 = e.TemplateArguments();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
  do {
    auto v356 = e.TemplateInstantiationArguments();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
  auto et173 = es.EntityId(e.TemplateKeywordToken());
  b.setVal173(et173);
  auto v183 = e.TypeAsWritten();
  if (v183) {
    auto id183 = es.EntityId(v183.value());
    b.setVal183(id183);
  } else {
    b.setVal183(mx::kInvalidEntityId);
  }
  b.setVal357(e.IsClassScopeExplicitSpecialization());
  b.setVal358(e.IsExplicitInstantiationOrSpecialization());
  b.setVal359(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal184(es.EntityId(e.InjectedSpecializationType()));
  b.setVal360(es.EntityId(e.InstantiatedFromMember()));
  b.setVal361(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal362(es.EntityId(e.TemplateParameters()));
  b.setVal363(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  do {
    auto v65 = e.Enumerators();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      sv65.set(i65, es.EntityId(e65));
      ++i65;
    }
  } while (false);
  auto v81 = e.InstantiatedFromMemberEnum();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto v82 = e.IntegerType();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  if (auto r84 = e.IntegerTypeRange(); auto rs84 = r84.Size()) {
    b.setVal84(es.EntityId(r84[0]));
    b.setVal85(es.EntityId(r84[rs84 - 1u]));
  } else {
    b.setVal84(0);
    b.setVal85(0);
  }
  auto v145 = e.ODRHash();
  if (v145) {
    b.setVal145(static_cast<uint32_t>(v145.value()));
    b.setVal107(true);
  } else {
    b.setVal107(false);
  }
  auto v86 = e.PromotionType();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
  } else {
    b.setVal86(mx::kInvalidEntityId);
  }
  auto v87 = e.TemplateInstantiationPattern();
  if (v87) {
    auto id87 = es.EntityId(v87.value());
    b.setVal87(id87);
  } else {
    b.setVal87(mx::kInvalidEntityId);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal108(e.IsClosed());
  b.setVal109(e.IsClosedFlag());
  b.setVal110(e.IsClosedNonFlag());
  b.setVal111(e.IsComplete());
  b.setVal112(e.IsFixed());
  b.setVal113(e.IsScoped());
  b.setVal114(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto et60 = es.EntityId(e.EllipsisToken());
  b.setVal60(et60);
  auto et61 = es.EntityId(e.TypenameToken());
  b.setVal61(et61);
  auto et69 = es.EntityId(e.UsingToken());
  b.setVal69(et69);
  b.setVal77(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto v60 = e.AnonymousDeclarationWithTypedefName();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  b.setVal61(es.EntityId(e.Type()));
  b.setVal69(es.EntityId(e.UnderlyingType()));
  b.setVal77(e.IsModed());
  b.setVal78(e.IsTransparentTag());
}

void SerializeTypedefDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
}

void SerializeTypeAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
  auto v70 = e.DescribedAliasTemplate();
  if (v70) {
    auto id70 = es.EntityId(v70.value());
    b.setVal70(id70);
  } else {
    b.setVal70(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
  auto et70 = es.EntityId(e.ColonToken());
  b.setVal70(et70);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto et71 = es.EntityId(e.VarianceToken());
  b.setVal71(et71);
  b.setVal79(e.HasExplicitBound());
}

void SerializeTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.TemplateParameters()));
  b.setVal60(es.EntityId(e.TemplatedDeclaration()));
  b.setVal77(e.HasAssociatedConstraints());
  b.setVal78(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal79(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal80(e.IsAbbreviated());
  b.setVal97(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal80(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal80(e.IsThisDeclarationADefinition());
}

void SerializeTypeAliasTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypeAliasTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
}

void SerializeConceptDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConceptDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.ConstraintExpression()));
  b.setVal79(e.IsTypeConcept());
}

void SerializeBuiltinTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BuiltinTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
}

void SerializeTemplateTemplateParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTemplateParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  b.setVal79(e.DefaultArgumentWasInherited());
  auto et61 = es.EntityId(e.DefaultArgumentToken());
  b.setVal61(et61);
  b.setVal80(e.HasDefaultArgument());
  b.setVal97(e.IsExpandedParameterPack());
  b.setVal98(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.AtToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.GetterMethodDeclaration()));
  auto et61 = es.EntityId(e.GetterNameToken());
  b.setVal61(et61);
  auto et69 = es.EntityId(e.LParenToken());
  b.setVal69(et69);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal70(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal71(es.EntityId(e.SetterMethodDeclaration()));
  auto et81 = es.EntityId(e.SetterNameToken());
  b.setVal81(et81);
  b.setVal82(es.EntityId(e.Type()));
  b.setVal77(e.IsAtomic());
  b.setVal78(e.IsClassProperty());
  b.setVal79(e.IsDirectProperty());
  b.setVal80(e.IsInstanceProperty());
  b.setVal97(e.IsOptional());
  b.setVal98(e.IsReadOnly());
  b.setVal99(e.IsRetaining());
}

void SerializeObjCMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal77(e.DefinedInNSObject());
  b.setVal59(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal60(es.EntityId(e.ClassInterface()));
  b.setVal61(es.EntityId(e.CommandDeclaration()));
  auto et69 = es.EntityId(e.DeclaratorEndToken());
  b.setVal69(et69);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal70(es.EntityId(e.ReturnType()));
  if (auto r71 = e.ReturnTypeTokens(); auto rs71 = r71.Size()) {
    b.setVal71(es.EntityId(r71[0]));
    b.setVal81(es.EntityId(r71[rs71 - 1u]));
  } else {
    b.setVal71(0);
    b.setVal81(0);
  }
  auto et82 = es.EntityId(e.SelectorStartToken());
  b.setVal82(et82);
  b.setVal84(es.EntityId(e.SelfDeclaration()));
  b.setVal78(e.HasParameterDestroyedInCallee());
  b.setVal79(e.HasRedeclaration());
  b.setVal80(e.HasRelatedResultType());
  b.setVal97(e.HasSkippedBody());
  b.setVal98(e.IsClassMethod());
  b.setVal99(e.IsDefined());
  b.setVal100(e.IsDesignatedInitializerForTheInterface());
  b.setVal101(e.IsDirectMethod());
  b.setVal102(e.IsInstanceMethod());
  b.setVal103(e.IsOptional());
  b.setVal104(e.IsOverriding());
  b.setVal105(e.IsPropertyAccessor());
  b.setVal106(e.IsRedeclaration());
  b.setVal107(e.IsSynthesizedAccessorStub());
  b.setVal108(e.IsThisDeclarationADefinition());
  b.setVal109(e.IsThisDeclarationADesignatedInitializer());
  b.setVal110(e.IsVariadic());
  do {
    auto v54 = e.Parameters();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v55 = e.SelectorTokens();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
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

void SerializeObjCContainerDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.ClassMethods();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v55 = e.ClassProperties();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  if (auto r59 = e.AtEndRange(); auto rs59 = r59.Size()) {
    b.setVal59(es.EntityId(r59[0]));
    b.setVal60(es.EntityId(r59[rs59 - 1u]));
  } else {
    b.setVal59(0);
    b.setVal60(0);
  }
  auto et61 = es.EntityId(e.AtStartToken());
  b.setVal61(et61);
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
    auto v190 = e.Methods();
    auto sv190 = b.initVal190(static_cast<unsigned>(v190.size()));
    auto i190 = 0u;
    for (const auto &e190 : v190) {
      sv190.set(i190, es.EntityId(e190));
      ++i190;
    }
  } while (false);
  do {
    auto v191 = e.Properties();
    auto sv191 = b.initVal191(static_cast<unsigned>(v191.size()));
    auto i191 = 0u;
    for (const auto &e191 : v191) {
      sv191.set(i191, es.EntityId(e191));
      ++i191;
    }
  } while (false);
  pasta::DeclContext dc192(e);
  auto v192 = dc192.AlreadyLoadedDeclarations();
  auto sv192 = b.initVal192(static_cast<unsigned>(v192.size()));
  auto i192 = 0u;
  for (const pasta::Decl &e192 : v192) {
    sv192.set(i192, es.EntityId(e192));
    ++i192;
  }
}

void SerializeObjCCategoryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal77(e.IsClassExtension());
  auto et69 = es.EntityId(e.CategoryNameToken());
  b.setVal69(et69);
  b.setVal70(es.EntityId(e.ClassInterface()));
  b.setVal71(es.EntityId(e.Implementation()));
  auto et81 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal81(et81);
  auto et82 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal82(et82);
  b.setVal84(es.EntityId(e.NextClassCategory()));
  do {
    auto v318 = e.InstanceVariables();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  do {
    auto v344 = e.ProtocolTokens();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
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
}

void SerializeObjCProtocolDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  auto v76 = e.ObjCRuntimeNameAsString();
  std::string s76(v76.data(), v76.size());
  b.setVal76(s76);
  b.setVal77(e.HasDefinition());
  b.setVal78(e.IsNonRuntimeProtocol());
  b.setVal79(e.IsThisDeclarationADefinition());
  do {
    auto v318 = e.ProtocolTokens();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
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

void SerializeObjCInterfaceDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  do {
    auto v318 = e.AllReferencedProtocols();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
  b.setVal77(e.DeclaresOrInheritsDesignatedInitializers());
  auto et69 = es.EntityId(e.EndOfDefinitionToken());
  b.setVal69(et69);
  b.setVal70(es.EntityId(e.Implementation()));
  auto v76 = e.ObjCRuntimeNameAsString();
  std::string s76(v76.data(), v76.size());
  b.setVal76(s76);
  auto v71 = e.SuperClass();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
  } else {
    b.setVal71(mx::kInvalidEntityId);
  }
  auto et81 = es.EntityId(e.SuperClassToken());
  b.setVal81(et81);
  auto v82 = e.SuperClassTypeInfo();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal84(es.EntityId(e.TypeForDeclaration()));
  b.setVal78(e.HasDefinition());
  b.setVal79(e.HasDesignatedInitializers());
  b.setVal80(e.IsArcWeakrefUnavailable());
  b.setVal97(e.IsImplicitInterfaceDeclaration());
  b.setVal85(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal98(e.IsThisDeclarationADefinition());
  do {
    auto v344 = e.InstanceVariables();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
  do {
    auto v355 = e.KnownCategories();
    auto sv355 = b.initVal355(static_cast<unsigned>(v355.size()));
    auto i355 = 0u;
    for (const auto &e355 : v355) {
      sv355.set(i355, es.EntityId(e355));
      ++i355;
    }
  } while (false);
  do {
    auto v356 = e.KnownExtensions();
    auto sv356 = b.initVal356(static_cast<unsigned>(v356.size()));
    auto i356 = 0u;
    for (const auto &e356 : v356) {
      sv356.set(i356, es.EntityId(e356));
      ++i356;
    }
  } while (false);
  do {
    auto v364 = e.ProtocolTokens();
    auto sv364 = b.initVal364(static_cast<unsigned>(v364.size()));
    auto i364 = 0u;
    for (const auto &e364 : v364) {
      sv364.set(i364, es.EntityId(e364));
      ++i364;
    }
  } while (false);
  do {
    auto v365 = e.Protocols();
    auto sv365 = b.initVal365(static_cast<unsigned>(v365.size()));
    auto i365 = 0u;
    for (const auto &e365 : v365) {
      sv365.set(i365, es.EntityId(e365));
      ++i365;
    }
  } while (false);
  do {
    auto v366 = e.VisibleCategories();
    auto sv366 = b.initVal366(static_cast<unsigned>(v366.size()));
    auto i366 = 0u;
    for (const auto &e366 : v366) {
      sv366.set(i366, es.EntityId(e366));
      ++i366;
    }
  } while (false);
  do {
    auto v367 = e.VisibleExtensions();
    auto sv367 = b.initVal367(static_cast<unsigned>(v367.size()));
    auto i367 = 0u;
    for (const auto &e367 : v367) {
      sv367.set(i367, es.EntityId(e367));
      ++i367;
    }
  } while (false);
}

void SerializeObjCImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal69(es.EntityId(e.ClassInterface()));
  do {
    auto v318 = e.PropertyImplementations();
    auto sv318 = b.initVal318(static_cast<unsigned>(v318.size()));
    auto i318 = 0u;
    for (const auto &e318 : v318) {
      sv318.set(i318, es.EntityId(e318));
      ++i318;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  b.setVal70(es.EntityId(e.CategoryDeclaration()));
  auto et71 = es.EntityId(e.CategoryNameToken());
  b.setVal71(et71);
}

void SerializeObjCImplementationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  auto et70 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal70(et70);
  auto et71 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal71(et71);
  auto v76 = e.ObjCRuntimeNameAsString();
  std::string s76(v76.data(), v76.size());
  b.setVal76(s76);
  b.setVal81(es.EntityId(e.SuperClass()));
  auto et82 = es.EntityId(e.SuperClassToken());
  b.setVal82(et82);
  b.setVal77(e.HasDestructors());
  b.setVal78(e.HasNonZeroConstructors());
  do {
    auto v344 = e.InstanceVariables();
    auto sv344 = b.initVal344(static_cast<unsigned>(v344.size()));
    auto i344 = 0u;
    for (const auto &e344 : v344) {
      sv344.set(i344, es.EntityId(e344));
      ++i344;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeNamespaceAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.AliasToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.AliasedNamespace()));
  auto et61 = es.EntityId(e.NamespaceToken());
  b.setVal61(et61);
  auto et69 = es.EntityId(e.TargetNameToken());
  b.setVal69(et69);
}

void SerializeLinkageSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.Children();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  b.setVal52(es.EntityId(e.ExtendingDeclaration()));
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal59(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.IdentifierTokens();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeImplicitConceptSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitConceptSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v54 = e.TemplateArguments();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal52(es.EntityId(e.FriendDeclaration()));
  auto et59 = es.EntityId(e.FriendToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.FriendType()));
  do {
    auto v54 = e.TemplateParameterLists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeFriendDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v52 = e.FriendDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
  auto et59 = es.EntityId(e.FriendToken());
  b.setVal59(et59);
  auto v60 = e.FriendType();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  b.setVal53(e.IsUnsupportedFriend());
  do {
    auto v54 = e.FriendTypeTemplateParameterLists();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et52 = es.EntityId(e.AssemblyToken());
  b.setVal52(et52);
  b.setVal59(es.EntityId(e.AssemblyString()));
  auto et60 = es.EntityId(e.RParenToken());
  b.setVal60(et60);
}

void SerializeExternCContextDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeExportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et52 = es.EntityId(e.ExportToken());
  b.setVal52(et52);
  auto et59 = es.EntityId(e.RBraceToken());
  b.setVal59(et59);
  b.setVal53(e.HasBraces());
  pasta::DeclContext dc54(e);
  auto v54 = dc54.AlreadyLoadedDeclarations();
  auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
  auto i54 = 0u;
  for (const pasta::Decl &e54 : v54) {
    sv54.set(i54, es.EntityId(e54));
    ++i54;
  }
}

void SerializeEmptyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

#pragma GCC diagnostic pop
}  // namespace indexer
