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
  auto v11 = e.FirstExpressionIndex();
  if (v11) {
    b.setVal11(static_cast<unsigned>(v11.value()));
    b.setVal12(true);
  } else {
    b.setVal12(false);
  }
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
  b.setVal18(e.IsWarning());
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
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal12(e.IsAlignas());
  b.setVal13(e.IsAlignmentDependent());
  b.setVal18(e.IsAlignmentErrorDependent());
  b.setVal19(e.IsAlignmentExpression());
  b.setVal20(e.IsC11());
  b.setVal21(e.IsDeclspec());
  b.setVal22(e.IsGNU());
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
  b.setVal18(e.IsTakes());
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
  b.setVal4(e.AcceptsObjCTypeParameters());
  b.setVal5(e.CanDecayToPointerType());
  b.setVal6(e.CanHaveNullability());
  b.setVal7(e.ContainsErrors());
  b.setVal8(e.ContainsUnexpandedParameterPack());
  b.setVal9(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  auto v10 = e.Nullability();
  if (v10) {
    b.setVal10(static_cast<unsigned char>(v10.value()));
    b.setVal11(true);
  } else {
    b.setVal11(false);
  }
  auto v12 = e.PointeeCXXRecordDeclaration();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v13 = e.PointeeOrArrayElementType();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.PointeeType();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v15 = e.ScalarTypeKind();
  if (v15) {
    b.setVal15(static_cast<unsigned char>(v15.value()));
    b.setVal16(true);
  } else {
    b.setVal16(false);
  }
  auto v17 = e.SveElementType();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  b.setVal18(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal19(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal20(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal21(e.HasAutoForTrailingReturnType());
  b.setVal22(e.HasFloatingRepresentation());
  b.setVal23(e.HasIntegerRepresentation());
  b.setVal24(e.HasObjCPointerRepresentation());
  b.setVal25(e.HasPointerRepresentation());
  b.setVal26(e.HasSignedIntegerRepresentation());
  b.setVal27(e.HasSizedVLAType());
  b.setVal28(e.HasUnnamedOrLocalType());
  b.setVal29(e.HasUnsignedIntegerRepresentation());
  auto v30 = e.IsAggregateType();
  if (v30) {
    b.setVal30(static_cast<bool>(v30.value()));
    b.setVal31(true);
  } else {
    b.setVal31(false);
  }
  b.setVal32(e.IsAlignValueT());
  b.setVal33(e.IsAnyCharacterType());
  b.setVal34(e.IsAnyComplexType());
  b.setVal35(e.IsAnyPointerType());
  b.setVal36(e.IsArithmeticType());
  b.setVal37(e.IsArrayType());
  b.setVal38(e.IsAtomicType());
  b.setVal39(e.IsBFloat16Type());
  b.setVal40(e.IsBitIntType());
  b.setVal41(e.IsBlockCompatibleObjCPointerType());
  b.setVal42(e.IsBlockPointerType());
  b.setVal43(e.IsBooleanType());
  b.setVal44(e.IsBuiltinType());
  b.setVal45(e.IsCARCBridgableType());
  b.setVal46(e.IsCUDADeviceBuiltinSurfaceType());
  b.setVal47(e.IsCUDADeviceBuiltinTextureType());
  b.setVal48(e.IsCanonicalUnqualified());
  b.setVal49(e.IsChar16Type());
  b.setVal50(e.IsChar32Type());
  b.setVal51(e.IsChar8Type());
  b.setVal52(e.IsCharacterType());
  b.setVal53(e.IsClassType());
  b.setVal54(e.IsClkEventT());
  b.setVal55(e.IsComplexIntegerType());
  b.setVal56(e.IsComplexType());
  b.setVal57(e.IsCompoundType());
  b.setVal58(e.IsConstantArrayType());
  b.setVal59(e.IsConstantMatrixType());
  auto v60 = e.IsConstantSizeType();
  if (v60) {
    b.setVal60(static_cast<bool>(v60.value()));
    b.setVal61(true);
  } else {
    b.setVal61(false);
  }
  b.setVal62(e.IsDecltypeType());
  b.setVal63(e.IsDependentAddressSpaceType());
  b.setVal64(e.IsDependentSizedArrayType());
  b.setVal65(e.IsDependentType());
  b.setVal66(e.IsElaboratedTypeSpecifier());
  b.setVal67(e.IsEnumeralType());
  b.setVal68(e.IsEventT());
  b.setVal69(e.IsExtVectorBooleanType());
  b.setVal70(e.IsExtVectorType());
  b.setVal71(e.IsFixedPointOrIntegerType());
  b.setVal72(e.IsFixedPointType());
  b.setVal73(e.IsFloat128Type());
  b.setVal74(e.IsFloat16Type());
  b.setVal75(e.IsFloatingType());
  b.setVal76(e.IsFromAST());
  b.setVal77(e.IsFunctionNoProtoType());
  b.setVal78(e.IsFunctionPointerType());
  b.setVal79(e.IsFunctionProtoType());
  b.setVal80(e.IsFunctionReferenceType());
  b.setVal81(e.IsFunctionType());
  b.setVal82(e.IsFundamentalType());
  b.setVal83(e.IsHalfType());
  b.setVal84(e.IsIbm128Type());
  b.setVal85(e.IsImageType());
  b.setVal86(e.IsIncompleteArrayType());
  b.setVal87(e.IsIncompleteOrObjectType());
  b.setVal88(e.IsIncompleteType());
  b.setVal89(e.IsInstantiationDependentType());
  b.setVal90(e.IsIntegerType());
  b.setVal91(e.IsIntegralOrEnumerationType());
  b.setVal92(e.IsIntegralOrUnscopedEnumerationType());
  b.setVal93(e.IsIntegralType());
  b.setVal94(e.IsInterfaceType());
  b.setVal95(e.IsLValueReferenceType());
  b.setVal96(e.IsLinkageValid());
  auto v97 = e.IsLiteralType();
  if (v97) {
    b.setVal97(static_cast<bool>(v97.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal99(e.IsMatrixType());
  b.setVal100(e.IsMemberDataPointerType());
  b.setVal101(e.IsMemberFunctionPointerType());
  b.setVal102(e.IsMemberPointerType());
  b.setVal103(e.IsNonOverloadPlaceholderType());
  b.setVal104(e.IsNothrowT());
  b.setVal105(e.IsNullPointerType());
  b.setVal106(e.IsOCLExtOpaqueType());
  b.setVal107(e.IsOCLImage1dArrayROType());
  b.setVal108(e.IsOCLImage1dArrayRWType());
  b.setVal109(e.IsOCLImage1dArrayWOType());
  b.setVal110(e.IsOCLImage1dBufferROType());
  b.setVal111(e.IsOCLImage1dBufferRWType());
  b.setVal112(e.IsOCLImage1dBufferWOType());
  b.setVal113(e.IsOCLImage1dROType());
  b.setVal114(e.IsOCLImage1dRWType());
  b.setVal115(e.IsOCLImage1dWOType());
  b.setVal116(e.IsOCLImage2dArrayDepthROType());
  b.setVal117(e.IsOCLImage2dArrayDepthRWType());
  b.setVal118(e.IsOCLImage2dArrayDepthWOType());
  b.setVal119(e.IsOCLImage2dArrayMSAADepthROType());
  b.setVal120(e.IsOCLImage2dArrayMSAADepthRWType());
  b.setVal121(e.IsOCLImage2dArrayMSAADepthWOType());
  b.setVal122(e.IsOCLImage2dArrayMSAAROType());
  b.setVal123(e.IsOCLImage2dArrayMSAARWType());
  b.setVal124(e.IsOCLImage2dArrayMSAAWOType());
  b.setVal125(e.IsOCLImage2dArrayROType());
  b.setVal126(e.IsOCLImage2dArrayRWType());
  b.setVal127(e.IsOCLImage2dArrayWOType());
  b.setVal128(e.IsOCLImage2dDepthROType());
  b.setVal129(e.IsOCLImage2dDepthRWType());
  b.setVal130(e.IsOCLImage2dDepthWOType());
  b.setVal131(e.IsOCLImage2dMSAADepthROType());
  b.setVal132(e.IsOCLImage2dMSAADepthRWType());
  b.setVal133(e.IsOCLImage2dMSAADepthWOType());
  b.setVal134(e.IsOCLImage2dMSAAROType());
  b.setVal135(e.IsOCLImage2dMSAARWType());
  b.setVal136(e.IsOCLImage2dMSAAWOType());
  b.setVal137(e.IsOCLImage2dROType());
  b.setVal138(e.IsOCLImage2dRWType());
  b.setVal139(e.IsOCLImage2dWOType());
  b.setVal140(e.IsOCLImage3dROType());
  b.setVal141(e.IsOCLImage3dRWType());
  b.setVal142(e.IsOCLImage3dWOType());
  b.setVal143(e.IsOCLIntelSubgroupAVCImeDualReferenceStreaminType());
  b.setVal144(e.IsOCLIntelSubgroupAVCImePayloadType());
  b.setVal145(e.IsOCLIntelSubgroupAVCImeResultDualReferenceStreamoutType());
  b.setVal146(e.IsOCLIntelSubgroupAVCImeResultSingleReferenceStreamoutType());
  b.setVal147(e.IsOCLIntelSubgroupAVCImeResultType());
  b.setVal148(e.IsOCLIntelSubgroupAVCImeSingleReferenceStreaminType());
  b.setVal149(e.IsOCLIntelSubgroupAVCMcePayloadType());
  b.setVal150(e.IsOCLIntelSubgroupAVCMceResultType());
  b.setVal151(e.IsOCLIntelSubgroupAVCRefPayloadType());
  b.setVal152(e.IsOCLIntelSubgroupAVCRefResultType());
  b.setVal153(e.IsOCLIntelSubgroupAVCSicPayloadType());
  b.setVal154(e.IsOCLIntelSubgroupAVCSicResultType());
  b.setVal155(e.IsOCLIntelSubgroupAVCType());
  b.setVal156(e.IsObjCARCBridgableType());
  auto v157 = e.IsObjCARCImplicitlyUnretainedType();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  b.setVal159(e.IsObjCBoxableRecordType());
  b.setVal160(e.IsObjCBuiltinType());
  b.setVal161(e.IsObjCClassOrClassKindOfType());
  b.setVal162(e.IsObjCClassType());
  b.setVal163(e.IsObjCIdType());
  b.setVal164(e.IsObjCIndependentClassType());
  b.setVal165(e.IsObjCIndirectLifetimeType());
  b.setVal166(e.IsObjCInertUnsafeUnretainedType());
  b.setVal167(e.IsObjCLifetimeType());
  b.setVal168(e.IsObjCNSObjectType());
  b.setVal169(e.IsObjCObjectOrInterfaceType());
  b.setVal170(e.IsObjCObjectPointerType());
  b.setVal171(e.IsObjCObjectType());
  b.setVal172(e.IsObjCQualifiedClassType());
  b.setVal173(e.IsObjCQualifiedIdType());
  b.setVal174(e.IsObjCQualifiedInterfaceType());
  b.setVal175(e.IsObjCRetainableType());
  b.setVal176(e.IsObjCSelType());
  b.setVal177(e.IsObjectPointerType());
  b.setVal178(e.IsObjectType());
  b.setVal179(e.IsOpenCLSpecificType());
  b.setVal180(e.IsOverloadableType());
  b.setVal181(e.IsPipeType());
  b.setVal182(e.IsPlaceholderType());
  b.setVal183(e.IsPointerType());
  b.setVal184(e.IsQueueT());
  b.setVal185(e.IsRVVType());
  b.setVal186(e.IsRValueReferenceType());
  b.setVal187(e.IsRealFloatingType());
  b.setVal188(e.IsRealType());
  b.setVal189(e.IsRecordType());
  b.setVal190(e.IsReferenceType());
  b.setVal191(e.IsReserveIDT());
  b.setVal192(e.IsSVESizelessBuiltinType());
  b.setVal193(e.IsSamplerT());
  b.setVal194(e.IsSaturatedFixedPointType());
  b.setVal195(e.IsScalarType());
  b.setVal196(e.IsScopedEnumeralType());
  b.setVal197(e.IsSignedFixedPointType());
  b.setVal198(e.IsSignedIntegerOrEnumerationType());
  b.setVal199(e.IsSignedIntegerType());
  b.setVal200(e.IsSizelessBuiltinType());
  b.setVal201(e.IsSizelessType());
  b.setVal202(e.IsSpecifierType());
  auto v203 = e.IsStandardLayoutType();
  if (v203) {
    b.setVal203(static_cast<bool>(v203.value()));
    b.setVal204(true);
  } else {
    b.setVal204(false);
  }
  b.setVal205(e.IsStdByteType());
  auto v206 = e.IsStructuralType();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  b.setVal208(e.IsStructureOrClassType());
  b.setVal209(e.IsStructureType());
  b.setVal210(e.IsTemplateTypeParmType());
  b.setVal211(e.IsTypedefNameType());
  b.setVal212(e.IsUndeducedAutoType());
  b.setVal213(e.IsUndeducedType());
  b.setVal214(e.IsUnionType());
  b.setVal215(e.IsUnsaturatedFixedPointType());
  b.setVal216(e.IsUnscopedEnumerationType());
  b.setVal217(e.IsUnsignedFixedPointType());
  b.setVal218(e.IsUnsignedIntegerOrEnumerationType());
  b.setVal219(e.IsUnsignedIntegerType());
  b.setVal220(e.IsVLSTBuiltinType());
  b.setVal221(e.IsVariableArrayType());
  b.setVal222(e.IsVariablyModifiedType());
  b.setVal223(e.IsVectorType());
  b.setVal224(e.IsVisibilityExplicit());
  b.setVal225(e.IsVoidPointerType());
  b.setVal226(e.IsVoidType());
  b.setVal227(e.IsWideCharacterType());
}

void SerializeTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto v229 = e.Declaration();
  if (v229) {
    auto id229 = es.EntityId(v229.value());
    b.setVal229(id229);
  } else {
    b.setVal229(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsParameterPack());
  b.setVal231(e.IsSugared());
}

void SerializeTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto v229 = e.AliasedType();
  if (v229) {
    auto id229 = es.EntityId(v229.value());
    b.setVal229(id229);
  } else {
    b.setVal229(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsCurrentInstantiation());
  b.setVal231(e.IsSugared());
  b.setVal232(e.IsTypeAlias());
  do {
    auto v233 = e.TemplateArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
}

void SerializeTagType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Declaration()));
  b.setVal230(e.IsBeingDefined());
}

void SerializeRecordType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.HasConstFields());
  b.setVal232(e.IsSugared());
}

void SerializeEnumType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.AssociatedDeclaration()));
  auto v234 = e.PackIndex();
  if (v234) {
    b.setVal234(static_cast<unsigned>(v234.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  b.setVal235(es.EntityId(e.ReplacedParameter()));
  b.setVal236(es.EntityId(e.ReplacementType()));
  b.setVal231(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.AssociatedDeclaration()));
  b.setVal230(e.Final());
  b.setVal235(es.EntityId(e.ReplacedParameter()));
  b.setVal231(e.IsSugared());
}

void SerializeReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal230(e.IsInnerReference());
  b.setVal231(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal232(e.IsSugared());
}

void SerializeLValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal232(e.IsSugared());
}

void SerializeQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal228(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal230(e.HasAddressSpace());
  b.setVal231(e.HasNonTrivialObjCLifetime());
  b.setVal232(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal238(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal239(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal240(e.HasQualifiers());
  b.setVal241(e.HasStrongOrWeakObjCLifetime());
  b.setVal242(e.IsCForbiddenLValueType());
  b.setVal243(e.IsCXX11PODType());
  b.setVal244(e.IsCXX98PODType());
  b.setVal245(e.IsCanonical());
  b.setVal246(e.IsCanonicalAsParameter());
  b.setVal247(e.IsConstQualified());
  b.setVal248(e.IsConstant());
  b.setVal249(e.IsLocalConstQualified());
  b.setVal250(e.IsLocalRestrictQualified());
  b.setVal251(e.IsLocalVolatileQualified());
  b.setVal252(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal253(e.IsNull());
  b.setVal254(e.IsObjCGCStrong());
  b.setVal255(e.IsObjCGCWeak());
  b.setVal256(e.IsPODType());
  b.setVal257(e.IsReferenceable());
  b.setVal258(e.IsRestrictQualified());
  b.setVal259(e.IsTrivialType());
  b.setVal260(e.IsTriviallyCopyableType());
  b.setVal261(e.IsTriviallyRelocatableType());
  b.setVal262(e.IsVolatileQualified());
  b.setVal263(e.MayBeDynamicClass());
  b.setVal264(e.MayBeNotDynamicClass());
}

void SerializePointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializePipeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsReadOnly());
  b.setVal231(e.IsSugared());
}

void SerializeParenType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.InnerType()));
  b.setVal230(e.IsSugared());
}

void SerializePackExpansionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Pattern()));
  b.setVal230(e.IsSugared());
}

void SerializeObjCTypeParamType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
}

void SerializeObjCObjectType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.BaseType()));
  b.setVal235(es.EntityId(e.Interface()));
  auto v236 = e.SuperClassType();
  if (v236) {
    auto id236 = es.EntityId(v236.value());
    b.setVal236(id236);
  } else {
    b.setVal236(mx::kInvalidEntityId);
  }
  do {
    auto v233 = e.TypeArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
  do {
    auto v265 = e.TypeArgumentsAsWritten();
    auto sv265 = b.initVal265(static_cast<unsigned>(v265.size()));
    auto i265 = 0u;
    for (const auto &e265 : v265) {
      sv265.set(i265, es.EntityId(e265));
      ++i265;
    }
  } while (false);
  b.setVal230(e.IsKindOfType());
  b.setVal231(e.IsKindOfTypeAsWritten());
  b.setVal232(e.IsObjCClass());
  b.setVal238(e.IsObjCId());
  b.setVal239(e.IsObjCQualifiedClass());
  b.setVal240(e.IsObjCQualifiedId());
  b.setVal241(e.IsObjCUnqualifiedClass());
  b.setVal242(e.IsObjCUnqualifiedId());
  b.setVal243(e.IsObjCUnqualifiedIdOrClass());
  b.setVal244(e.IsSpecialized());
  b.setVal245(e.IsSpecializedAsWritten());
  b.setVal246(e.IsSugared());
  b.setVal247(e.IsUnspecialized());
  b.setVal248(e.IsUnspecializedAsWritten());
  b.setVal266(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(pf, es, b, e, nullptr);
  b.setVal267(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.InterfaceDeclaration()));
  b.setVal235(es.EntityId(e.InterfaceType()));
  b.setVal236(es.EntityId(e.ObjectType()));
  b.setVal266(es.EntityId(e.SuperClassType()));
  do {
    auto v233 = e.TypeArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
  do {
    auto v265 = e.TypeArgumentsAsWritten();
    auto sv265 = b.initVal265(static_cast<unsigned>(v265.size()));
    auto i265 = 0u;
    for (const auto &e265 : v265) {
      sv265.set(i265, es.EntityId(e265));
      ++i265;
    }
  } while (false);
  b.setVal230(e.IsKindOfType());
  b.setVal231(e.IsObjCIdOrClassType());
  b.setVal232(e.IsSpecialized());
  b.setVal238(e.IsSpecializedAsWritten());
  b.setVal239(e.IsSugared());
  b.setVal240(e.IsUnspecialized());
  b.setVal241(e.IsUnspecializedAsWritten());
  do {
    auto v268 = e.Qualifiers();
    auto sv268 = b.initVal268(static_cast<unsigned>(v268.size()));
    auto i268 = 0u;
    for (const auto &e268 : v268) {
      sv268.set(i268, es.EntityId(e268));
      ++i268;
    }
  } while (false);
  b.setVal267(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v269 = e.Protocols();
    auto sv269 = b.initVal269(static_cast<unsigned>(v269.size()));
    auto i269 = 0u;
    for (const auto &e269 : v269) {
      sv269.set(i269, es.EntityId(e269));
      ++i269;
    }
  } while (false);
}

void SerializeMemberPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Class()));
  b.setVal235(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal230(e.IsMemberDataPointer());
  b.setVal231(e.IsMemberFunctionPointer());
  b.setVal232(e.IsSugared());
}

void SerializeMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
  auto et235 = es.EntityId(e.AttributeToken());
  b.setVal235(et235);
  b.setVal236(es.EntityId(e.ColumnExpression()));
  b.setVal266(es.EntityId(e.RowExpression()));
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
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ModifiedType()));
  b.setVal235(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeInjectedClassNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal235(es.EntityId(e.InjectedSpecializationType()));
  b.setVal236(es.EntityId(e.InjectedTST()));
  b.setVal230(e.IsSugared());
}

void SerializeFunctionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal228(es.EntityId(e.CallResultType()));
  b.setVal230(e.CmseNSCallAttribute());
  b.setVal231(e.HasRegParm());
  b.setVal232(e.NoReturnAttribute());
  b.setVal229(es.EntityId(e.ReturnType()));
  b.setVal238(e.IsConst());
  b.setVal239(e.IsRestrict());
  b.setVal240(e.IsVolatile());
}

void SerializeFunctionProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  auto v270 = e.CanThrow();
  if (v270) {
    b.setVal270(static_cast<unsigned char>(v270.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  b.setVal235(es.EntityId(e.Desugar()));
  auto et236 = es.EntityId(e.EllipsisToken());
  b.setVal236(et236);
  auto v266 = e.ExceptionSpecDeclaration();
  if (v266) {
    auto id266 = es.EntityId(v266.value());
    b.setVal266(id266);
  } else {
    b.setVal266(mx::kInvalidEntityId);
  }
  auto v267 = e.ExceptionSpecTemplate();
  if (v267) {
    auto id267 = es.EntityId(v267.value());
    b.setVal267(id267);
  } else {
    b.setVal267(mx::kInvalidEntityId);
  }
  b.setVal271(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v272 = e.NoexceptExpression();
  if (v272) {
    auto id272 = es.EntityId(v272.value());
    b.setVal272(id272);
  } else {
    b.setVal272(mx::kInvalidEntityId);
  }
  do {
    auto v233 = e.ParameterTypes();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
  b.setVal273(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal242(e.HasDependentExceptionSpec());
  b.setVal243(e.HasDynamicExceptionSpec());
  b.setVal244(e.HasExceptionSpec());
  b.setVal245(e.HasExtParameterInfos());
  b.setVal246(e.HasInstantiationDependentExceptionSpec());
  b.setVal247(e.HasNoexceptExceptionSpec());
  b.setVal248(e.HasTrailingReturn());
  auto v249 = e.IsNothrow();
  if (v249) {
    b.setVal249(static_cast<bool>(v249.value()));
    b.setVal250(true);
  } else {
    b.setVal250(false);
  }
  b.setVal251(e.IsSugared());
  b.setVal252(e.IsTemplateVariadic());
  b.setVal253(e.IsVariadic());
  do {
    auto v265 = e.ExceptionTypes();
    auto sv265 = b.initVal265(static_cast<unsigned>(v265.size()));
    auto i265 = 0u;
    for (const auto &e265 : v265) {
      sv265.set(i265, es.EntityId(e265));
      ++i265;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  b.setVal235(es.EntityId(e.Desugar()));
  b.setVal241(e.IsSugared());
}

void SerializeDependentVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto et229 = es.EntityId(e.AttributeToken());
  b.setVal229(et229);
  b.setVal235(es.EntityId(e.ElementType()));
  b.setVal236(es.EntityId(e.SizeExpression()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto et229 = es.EntityId(e.AttributeToken());
  b.setVal229(et229);
  b.setVal235(es.EntityId(e.ElementType()));
  b.setVal236(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.NumBitsExpression()));
  b.setVal230(e.IsSigned());
  b.setVal231(e.IsSugared());
  b.setVal232(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.AddressSpaceExpression()));
  auto et235 = es.EntityId(e.AttributeToken());
  b.setVal235(et235);
  b.setVal230(e.IsSugared());
}

void SerializeDeducedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto v229 = e.ResolvedType();
  if (v229) {
    auto id229 = es.EntityId(v229.value());
    b.setVal229(id229);
  } else {
    b.setVal229(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsDeduced());
  b.setVal231(e.IsSugared());
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
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v233 = e.TypeConstraintArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
  auto v235 = e.TypeConstraintConcept();
  if (v235) {
    auto id235 = es.EntityId(v235.value());
    b.setVal235(id235);
  } else {
    b.setVal235(mx::kInvalidEntityId);
  }
  b.setVal232(e.IsConstrained());
  b.setVal238(e.IsDecltypeAuto());
  b.setVal239(e.IsGNUAutoType());
}

void SerializeDecltypeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.UnderlyingExpression()));
  b.setVal235(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeComplexType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsSugared());
}

void SerializeBuiltinType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.BuiltinKind())));
  b.setVal230(e.IsFloatingPoint());
  b.setVal231(e.IsInteger());
  b.setVal232(e.IsSVEBool());
  b.setVal238(e.IsSignedInteger());
  b.setVal239(e.IsSugared());
  b.setVal240(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSigned());
  b.setVal231(e.IsSugared());
  b.setVal232(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Attribute()));
  b.setVal235(es.EntityId(e.WrappedType()));
  b.setVal230(e.IsSugared());
}

void SerializeAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto v229 = e.Attribute();
  if (v229) {
    auto id229 = es.EntityId(v229.value());
    b.setVal229(id229);
  } else {
    b.setVal229(mx::kInvalidEntityId);
  }
  b.setVal274(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal235(es.EntityId(e.EquivalentType()));
  auto v237 = e.ImmediateNullability();
  if (v237) {
    b.setVal237(static_cast<unsigned char>(v237.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  b.setVal236(es.EntityId(e.ModifiedType()));
  b.setVal231(e.HasAttribute());
  b.setVal232(e.IsCallingConv());
  b.setVal238(e.IsMSTypeSpec());
  b.setVal239(e.IsQualifier());
  b.setVal240(e.IsSugared());
}

void SerializeAtomicType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ValueType()));
  b.setVal230(e.IsSugared());
}

void SerializeArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.ElementType()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  if (auto r235 = e.BracketsRange(); auto rs235 = r235.Size()) {
    b.setVal235(es.EntityId(r235[0]));
    b.setVal236(es.EntityId(r235[rs235 - 1u]));
  } else {
    b.setVal235(0);
    b.setVal236(0);
  }
  auto et266 = es.EntityId(e.LBracketToken());
  b.setVal266(et266);
  auto et267 = es.EntityId(e.RBracketToken());
  b.setVal267(et267);
  b.setVal272(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeIncompleteArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  if (auto r235 = e.BracketsRange(); auto rs235 = r235.Size()) {
    b.setVal235(es.EntityId(r235[0]));
    b.setVal236(es.EntityId(r235[rs235 - 1u]));
  } else {
    b.setVal235(0);
    b.setVal236(0);
  }
  auto et266 = es.EntityId(e.LBracketToken());
  b.setVal266(et266);
  auto et267 = es.EntityId(e.RBracketToken());
  b.setVal267(et267);
  b.setVal272(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeConstantArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto v235 = e.SizeExpression();
  if (v235) {
    auto id235 = es.EntityId(v235.value());
    b.setVal235(id235);
  } else {
    b.setVal235(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsSugared());
}

void SerializeAdjustedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ResolvedType()));
  b.setVal235(es.EntityId(e.OriginalType()));
  b.setVal230(e.IsSugared());
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
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.NamedType()));
  auto v235 = e.OwnedTagDeclaration();
  if (v235) {
    auto id235 = es.EntityId(v235.value());
    b.setVal235(id235);
  } else {
    b.setVal235(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
  do {
    auto v233 = e.TemplateArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
}

void SerializeDependentNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal230(e.IsSugared());
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
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.FoundDeclaration()));
  b.setVal235(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
  b.setVal231(e.TypeMatchesDeclaration());
}

void SerializeUnresolvedUsingType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
}

void SerializeUnaryTransformType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.BaseType()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal235(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeTypedefType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
  b.setVal231(e.TypeMatchesDeclaration());
}

void SerializeTypeOfType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal229(es.EntityId(e.UnmodifiedType()));
  b.setVal230(e.IsSugared());
}

void SerializeTypeOfExprType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal237(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal229(es.EntityId(e.UnderlyingExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.LeaveToken());
  b.setVal9(et9);
}

void SerializeSEHFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto et10 = es.EntityId(e.FinallyToken());
  b.setVal10(et10);
}

void SerializeSEHExceptStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto et10 = es.EntityId(e.ExceptToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.ThrowExpression()));
  auto et10 = es.EntityId(e.ThrowToken());
  b.setVal10(et10);
}

void SerializeObjCAtSynchronizedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtSynchronizedToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SynchBody()));
  b.setVal11(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.AtFinallyToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.AssociatedStatement()));
  b.setVal10(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal11(es.EntityId(e.RawStatement()));
  b.setVal13(es.EntityId(e.StructuredBlock()));
  b.setVal12(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPErrorDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPErrorDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDispatchDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  auto et14 = es.EntityId(e.TargetCallToken());
  b.setVal14(et14);
}

void SerializeOMPDepobjDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDepobjDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCriticalDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCriticalDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCancellationPointDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancellationPointDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCancelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCancelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPBarrierDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPBarrierDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPAtomicDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPAtomicDirective &e, const TokenTree *) {
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
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskyieldDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskyieldDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskwaitDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskwaitDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskgroupDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskgroupDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetExitDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetExitDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetEnterDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetEnterDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetDataDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetDataDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPSingleDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSingleDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPSectionsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSectionDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPScanDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelSectionsDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPOrderedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.IfStatement()));
}

void SerializeOMPMasterDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMaskedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopBasedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopBasedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopTransformationDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e, const TokenTree *) {
  SerializeOMPLoopBasedDirective(pf, es, b, e, nullptr);
  b.setVal14(es.EntityId(e.PreInitializers()));
  b.setVal17(es.EntityId(e.TransformedStatement()));
}

void SerializeOMPUnrollDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPUnrollDirective &e, const TokenTree *) {
  SerializeOMPLoopTransformationDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTileDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTileDirective &e, const TokenTree *) {
  SerializeOMPLoopTransformationDirective(pf, es, b, e, nullptr);
}

void SerializeOMPLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopDirective &e, const TokenTree *) {
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
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTeamsDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDistributeParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetTeamsDistributeDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPTargetParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelForSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelForDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPInteropDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPFlushDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPCanonicalLoop(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal10(es.EntityId(e.LoopStatement()));
  b.setVal11(es.EntityId(e.LoopVariableFunc()));
  b.setVal13(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.SemiToken());
  b.setVal9(et9);
  b.setVal12(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.KeywordToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.GotoToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.Label()));
  auto et11 = es.EntityId(e.LabelToken());
  b.setVal11(et11);
}

void SerializeForStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
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

void SerializeCoreturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.KeywordToken());
  b.setVal9(et9);
  b.setVal10(es.EntityId(e.Operand()));
  b.setVal11(es.EntityId(e.PromiseCall()));
  b.setVal12(e.IsImplicit());
}

void SerializeContinueStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.ContinueToken());
  b.setVal9(et9);
}

void SerializeCompoundStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal11(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
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
  SerializeStmt(pf, es, b, e, nullptr);
  auto et9 = es.EntityId(e.BreakToken());
  b.setVal9(et9);
}

void SerializeAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.KeywordToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal39(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal95(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
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
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
  b.setVal89(e.IsImplicit());
}

void SerializeCoyieldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SpecializationDeclaration()));
  do {
    auto v15 = e.TemplateArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal89(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Initializer()));
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  b.setVal89(e.IsFileScope());
}

void SerializeChooseExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
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
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal90(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
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
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
  b.setVal90(e.IsAlwaysNull());
}

void SerializeCXXConstCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXAddrspaceCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXAddrspaceCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXStaticCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStaticCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXReinterpretCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXReinterpretCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
}

void SerializeCXXFunctionalCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFunctionalCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.LParenToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
  b.setVal90(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.LParenToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
}

void SerializeBuiltinBitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et42 = es.EntityId(e.BridgeKeywordToken());
  b.setVal42(et42);
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v65 = e.BridgeKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto et43 = es.EntityId(e.LParenToken());
  b.setVal43(et43);
}

void SerializeCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
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
  b.setVal95(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et42 = es.EntityId(e.OperatorToken());
  b.setVal42(et42);
  b.setVal97(e.IsAssignmentOperation());
  b.setVal98(e.IsComparisonOperation());
  b.setVal99(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
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
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.CookedLiteral()));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto et43 = es.EntityId(e.UDSuffixToken());
  b.setVal43(et43);
}

void SerializeCXXUuidofExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.RParenToken());
  b.setVal37(et37);
}

void SerializeCXXRewrittenBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et38 = es.EntityId(e.OperatorToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal89(e.IsAssignmentOperation());
  b.setVal90(e.IsComparisonOperation());
  b.setVal91(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.ArrayFiller()));
  auto et38 = es.EntityId(e.InitializerToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.InitializedFieldInUnion()));
}

void SerializeCXXNullPtrLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeCXXNoexceptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Operand()));
  b.setVal89(e.Value());
}

void SerializeCXXNewExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
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
  b.setVal95(e.PassAlignment());
  do {
    auto v15 = e.PlacementArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal97(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.ConstructsVirtualBase());
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  b.setVal90(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Callee()));
  auto et38 = es.EntityId(e.EllipsisToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.Initializer()));
  b.setVal40(es.EntityId(e.LHS()));
  auto et41 = es.EntityId(e.LParenToken());
  b.setVal41(et41);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  b.setVal43(es.EntityId(e.RHS()));
  auto et44 = es.EntityId(e.RParenToken());
  b.setVal44(et44);
  b.setVal89(e.IsLeftFold());
  b.setVal90(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal91(e.IsListInitialization());
  b.setVal92(e.IsStdInitializerListInitialization());
  b.setVal93(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  SerializeCXXConstructExpr(pf, es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.Value());
}

void SerializeCXXBindTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.BlockDeclaration()));
  b.setVal38(es.EntityId(e.Body()));
  auto et39 = es.EntityId(e.CaretToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.LHS()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
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
  b.setVal95(e.IsComparisonOperation());
  b.setVal97(e.IsCompoundAssignmentOperation());
  b.setVal98(e.IsEqualityOperation());
  b.setVal99(e.IsLogicalOperation());
  b.setVal100(e.IsMultiplicativeOperation());
  b.setVal101(e.IsPointerMemoryOperation());
  b.setVal102(e.IsRelationalOperation());
  b.setVal103(e.IsShiftAssignOperation());
  b.setVal104(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  SerializeBinaryOperator(pf, es, b, e, nullptr);
  b.setVal40(es.EntityId(e.ComputationLHSType()));
  b.setVal41(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.DimensionExpression()));
  b.setVal38(es.EntityId(e.QueriedType()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  b.setVal39(es.EntityId(e.LHS()));
  auto et40 = es.EntityId(e.RBracketToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.CommonExpression()));
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AmpAmpToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Label()));
  auto et39 = es.EntityId(e.LabelToken());
  b.setVal39(et39);
}

void SerializeAbstractConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
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
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.Common()));
  b.setVal43(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.CanOverflow());
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal90(e.HasStoredFPFeatures());
  b.setVal91(e.IsArithmeticOperation());
  b.setVal92(e.IsDecrementOperation());
  b.setVal93(e.IsIncrementDecrementOperation());
  b.setVal95(e.IsIncrementOperation());
  b.setVal97(e.IsPostfix());
  b.setVal98(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.KeywordKind())));
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.TypeOfArgument()));
  b.setVal89(e.IsArgumentType());
}

void SerializeTypoExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AssociatedDeclaration()));
  b.setVal38(es.EntityId(e.ParameterPack()));
  auto et39 = es.EntityId(e.ParameterPackToken());
  b.setVal39(et39);
}

void SerializeSubstNonTypeTemplateParmExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AssociatedDeclaration()));
  auto et38 = es.EntityId(e.NameToken());
  b.setVal38(et38);
  auto v105 = e.PackIndex();
  if (v105) {
    b.setVal105(static_cast<unsigned>(v105.value()));
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
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
  b.setVal95(e.IsOrdinary());
  b.setVal97(e.IsPascal());
  b.setVal98(e.IsUTF16());
  b.setVal99(e.IsUTF32());
  b.setVal100(e.IsUTF8());
  b.setVal101(e.IsWide());
}

void SerializeStmtExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto v60 = e.BuiltinString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsIntType());
}

void SerializeSizeOfPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Pack()));
  auto v105 = e.PackLength();
  if (v105) {
    b.setVal105(static_cast<unsigned>(v105.value()));
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.BuiltinToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeSYCLUniqueStableNameExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.FunctionName()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v60 = e.IdentifierKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
}

void SerializeParenListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.LParenToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.EllipsisToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
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
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal91(e.IsOverloaded());
  b.setVal92(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.SourceExpression()));
  b.setVal89(e.IsUnique());
}

void SerializeOffsetOfExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeObjCSubscriptRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal38(es.EntityId(e.BaseExpression()));
  b.setVal39(es.EntityId(e.KeyExpression()));
  auto et40 = es.EntityId(e.RBracketToken());
  b.setVal40(et40);
  b.setVal89(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.RParenToken());
  b.setVal38(et38);
}

void SerializeObjCProtocolExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
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
  b.setVal95(e.IsObjectReceiver());
  b.setVal97(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal43(es.EntityId(e.ReceiverInterface()));
  b.setVal96(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal89(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.EncodedType()));
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeObjCDictionaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.AtToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.BoxingMethod()));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal89(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.HasVersion());
}

void SerializeObjCArrayLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.IteratorKwToken());
  b.setVal37(et37);
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeOMPArrayShapingExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
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
  b.setVal95(e.IsImplicitAccess());
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  auto et39 = es.EntityId(e.RBracketToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal89(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
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
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal89(e.IsBoundToLvalueReference());
  b.setVal90(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.Index()));
  auto et39 = es.EntityId(e.RBracketToken());
  b.setVal39(et39);
}

void SerializeMSPropertyRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.BaseExpression()));
  auto et38 = es.EntityId(e.MemberToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.PropertyDeclaration()));
  b.setVal89(e.IsArrow());
  b.setVal90(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
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
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeInitListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
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
  do {
    auto v15 = e.Initializers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal91(e.IsExplicit());
  b.setVal92(e.IsSemanticForm());
  b.setVal93(e.IsStringLiteralInitializer());
  b.setVal95(e.IsSyntacticForm());
  auto v97 = e.IsTransparent();
  if (v97) {
    b.setVal97(static_cast<bool>(v97.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
}

void SerializeImplicitValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
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
  auto et38 = es.EntityId(e.DefaultToken());
  b.setVal38(et38);
  auto et39 = es.EntityId(e.GenericToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.ResultExpression()));
  b.setVal89(e.IsResultDependent());
}

void SerializeGNUNullExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.TokenToken());
  b.setVal37(et37);
}

void SerializeFunctionParmPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
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
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal89(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal89(e.HasAPValueResult());
  b.setVal90(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal89(e.IsExact());
}

void SerializeFixedPointLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeExtVectorElementExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal89(e.ContainsDuplicateElements());
  auto et37 = es.EntityId(e.AccessorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal90(e.IsArrow());
}

void SerializeExpressionTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal89(e.Value());
}

void SerializeAttributedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
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
  SerializeSwitchCase(pf, es, b, e, nullptr);
  auto et14 = es.EntityId(e.DefaultToken());
  b.setVal14(et14);
}

void SerializeCaseStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
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
  auto et47 = es.EntityId(e.Token());
  if (!et47) {
    et47 = pf.DeclTokenEntityId(e);
  }
  b.setVal47(et47);
  if (auto r48 = e.Tokens(); auto rs48 = r48.Size()) {
    b.setVal48(es.EntityId(r48[0]));
    b.setVal49(es.EntityId(r48[rs48 - 1u]));
  } else {
    b.setVal48(0);
    b.setVal49(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal50(es.EntityId(e.Specialization()));
  b.setVal51(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeBlockDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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
  auto et57 = es.EntityId(e.CaretToken());
  b.setVal57(et57);
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

void SerializeAccessSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et50 = es.EntityId(e.AccessSpecifierToken());
  b.setVal50(et50);
  auto et57 = es.EntityId(e.ColonToken());
  b.setVal57(et57);
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
    auto v52 = e.Varlists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
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
    auto v52 = e.Varlists();
    auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
    auto i52 = 0u;
    for (const auto &e52 : v52) {
      sv52.set(i52, es.EntityId(e52));
      ++i52;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeTopLevelStmtDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal50(es.EntityId(e.Statement()));
}

void SerializeStaticAssertDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal50(es.EntityId(e.AssertExpression()));
  b.setVal57(es.EntityId(e.Message()));
  auto et58 = es.EntityId(e.RParenToken());
  b.setVal58(et58);
  b.setVal51(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  pasta::DeclContext dc52(e);
  auto v52 = dc52.AlreadyLoadedDeclarations();
  auto sv52 = b.initVal52(static_cast<unsigned>(v52.size()));
  auto i52 = 0u;
  for (const pasta::Decl &e52 : v52) {
    sv52.set(i52, es.EntityId(e52));
    ++i52;
  }
}

void SerializePragmaDetectMismatchDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v64 = e.Name();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  auto v65 = e.Value();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
}

void SerializePragmaCommentDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v64 = e.Argument();
  std::string s64(v64.data(), v64.size());
  b.setVal64(s64);
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal50(es.EntityId(e.GetterCXXConstructor()));
  b.setVal57(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal58(es.EntityId(e.PropertyDeclaration()));
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal59(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto et67 = es.EntityId(e.PropertyInstanceVariableDeclarationToken());
  b.setVal67(et67);
  b.setVal68(es.EntityId(e.SetterCXXAssignment()));
  b.setVal69(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal51(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeLabelDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v74 = e.MSAssemblyLabel();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal57(es.EntityId(e.Statement()));
  b.setVal75(e.IsGnuLocal());
  b.setVal76(e.IsMSAssemblyLabel());
  b.setVal77(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.LBraceToken());
  b.setVal57(et57);
  auto et58 = es.EntityId(e.TokenStart());
  b.setVal58(et58);
  auto et59 = es.EntityId(e.RBraceToken());
  b.setVal59(et59);
  b.setVal75(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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

void SerializeUsingEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  b.setVal57(es.EntityId(e.EnumDeclaration()));
  auto et58 = es.EntityId(e.EnumToken());
  b.setVal58(et58);
  b.setVal59(es.EntityId(e.EnumType()));
  auto et67 = es.EntityId(e.UsingToken());
  b.setVal67(et67);
}

void SerializeUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.UsingToken());
  b.setVal57(et57);
  b.setVal75(e.HasTypename());
  b.setVal76(e.IsAccessDeclaration());
}

void SerializeValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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

void SerializeUnresolvedUsingValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.EllipsisToken());
  b.setVal59(et59);
  auto et67 = es.EntityId(e.UsingToken());
  b.setVal67(et67);
  b.setVal77(e.IsAccessDeclaration());
  b.setVal78(e.IsPackExpansion());
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

void SerializeEnumConstantDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto v59 = e.InitializerExpression();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.FirstInnerToken());
  b.setVal59(et59);
  auto et67 = es.EntityId(e.FirstOuterToken());
  b.setVal67(et67);
  auto v68 = e.TrailingRequiresClause();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
  } else {
    b.setVal68(mx::kInvalidEntityId);
  }
  auto et69 = es.EntityId(e.TypeSpecEndToken());
  b.setVal69(et69);
  auto et79 = es.EntityId(e.TypeSpecStartToken());
  b.setVal79(et79);
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

void SerializeVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
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
  auto et87 = es.EntityId(e.PointOfInstantiation());
  b.setVal87(et87);
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

void SerializeParmVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
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
  b.setVal132(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
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

void SerializeVarTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto et129 = es.EntityId(e.ExternToken());
  b.setVal129(et129);
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
  auto et131 = es.EntityId(e.TemplateKeywordToken());
  b.setVal131(et131);
  b.setVal133(es.EntityId(e.TypeAsWritten()));
  b.setVal135(e.IsClassScopeExplicitSpecialization());
  b.setVal136(e.IsExplicitInstantiationOrSpecialization());
  b.setVal137(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal134(es.EntityId(e.InstantiatedFromMember()));
  b.setVal142(es.EntityId(e.TemplateParameters()));
  b.setVal138(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal77(e.DefaultArgumentWasInherited());
  auto v80 = e.DefaultArgument();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto et82 = es.EntityId(e.DefaultArgumentToken());
  b.setVal82(et82);
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

void SerializeMSPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal77(e.HasGetter());
  b.setVal78(e.HasSetter());
}

void SerializeFunctionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
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
  auto et83 = es.EntityId(e.DefaultToken());
  b.setVal83(et83);
  auto v84 = e.DescribedFunctionTemplate();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto et85 = es.EntityId(e.EllipsisToken());
  b.setVal85(et85);
  if (auto r87 = e.ExceptionSpecTokens(); auto rs87 = r87.Size()) {
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
  if (auto r131 = e.ParametersTokens(); auto rs131 = r131.Size()) {
    b.setVal131(es.EntityId(r131[0]));
    b.setVal133(es.EntityId(r131[rs131 - 1u]));
  } else {
    b.setVal131(0);
    b.setVal133(0);
  }
  auto et134 = es.EntityId(e.PointOfInstantiation());
  b.setVal134(et134);
  auto v142 = e.PrimaryTemplate();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
  } else {
    b.setVal142(mx::kInvalidEntityId);
  }
  b.setVal144(es.EntityId(e.ReturnType()));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v145 = e.TemplateInstantiationPattern();
  if (v145) {
    auto id145 = es.EntityId(v145.value());
    b.setVal145(id145);
  } else {
    b.setVal145(mx::kInvalidEntityId);
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
  b.setVal146(e.IsOverloadedOperator());
  b.setVal147(e.IsPure());
  b.setVal148(e.IsReplaceableGlobalAllocationFunction());
  auto v149 = e.IsReservedGlobalPlacementOperator();
  if (v149) {
    b.setVal149(static_cast<bool>(v149.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  b.setVal151(e.IsStatic());
  b.setVal152(e.IsTargetClonesMultiVersion());
  b.setVal153(e.IsTargetMultiVersion());
  b.setVal154(e.IsTemplateInstantiation());
  b.setVal155(e.IsThisDeclarationADefinition());
  b.setVal156(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal157(e.IsTrivial());
  b.setVal158(e.IsTrivialForCall());
  b.setVal159(e.IsUserProvided());
  b.setVal160(e.IsVariadic());
  b.setVal161(e.IsVirtualAsWritten());
  do {
    auto v53 = e.Parameters();
    auto sv53 = b.initVal53(static_cast<unsigned>(v53.size()));
    auto i53 = 0u;
    for (const auto &e53 : v53) {
      sv53.set(i53, es.EntityId(e53));
      ++i53;
    }
  } while (false);
  b.setVal162(e.UsesSEHTry());
  b.setVal163(e.WillHaveBody());
  auto v164 = e.Body();
  if (v164) {
    auto id164 = es.EntityId(v164.value());
    b.setVal164(id164);
  } else {
    b.setVal164(mx::kInvalidEntityId);
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

void SerializeCXXMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal165(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v166 = e.ThisObjectType();
  if (v166) {
    auto id166 = es.EntityId(v166.value());
    b.setVal166(id166);
  } else {
    b.setVal166(mx::kInvalidEntityId);
  }
  auto v167 = e.ThisType();
  if (v167) {
    auto id167 = es.EntityId(v167.value());
    b.setVal167(id167);
  } else {
    b.setVal167(mx::kInvalidEntityId);
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
    auto v176 = e.OverriddenMethods();
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v177 = e.OperatorDelete();
  if (v177) {
    auto id177 = es.EntityId(v177.value());
    b.setVal177(id177);
  } else {
    b.setVal177(mx::kInvalidEntityId);
  }
  auto v178 = e.OperatorDeleteThisArgument();
  if (v178) {
    auto id178 = es.EntityId(v178.value());
    b.setVal178(id178);
  } else {
    b.setVal178(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  b.setVal177(es.EntityId(e.ConversionType()));
  b.setVal179(e.IsExplicit());
  b.setVal180(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v177 = e.TargetConstructor();
  if (v177) {
    auto id177 = es.EntityId(v177.value());
    b.setVal177(id177);
  } else {
    b.setVal177(mx::kInvalidEntityId);
  }
  b.setVal179(e.IsDefaultConstructor());
  b.setVal180(e.IsDelegatingConstructor());
  b.setVal181(e.IsExplicit());
  b.setVal182(e.IsInheritingConstructor());
  b.setVal183(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal166(es.EntityId(e.CorrespondingConstructor()));
  b.setVal167(es.EntityId(e.DeducedTemplate()));
  b.setVal168(e.IsCopyDeductionCandidate());
  b.setVal169(e.IsExplicit());
}

void SerializeFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
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

void SerializeObjCIvarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(pf, es, b, e, nullptr);
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal84(es.EntityId(e.ContainingInterface()));
  b.setVal85(es.EntityId(e.NextInstanceVariable()));
  b.setVal101(e.Synthesize());
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
  b.setVal59(es.EntityId(e.Binding()));
  b.setVal67(es.EntityId(e.DecomposedDeclaration()));
  b.setVal68(es.EntityId(e.HoldingVariable()));
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

void SerializeUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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

void SerializeConstructorUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(pf, es, b, e, nullptr);
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

void SerializeUsingPackDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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

void SerializeUsingDirectiveDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.IdentifierToken());
  b.setVal57(et57);
  auto et58 = es.EntityId(e.NamespaceKeyToken());
  b.setVal58(et58);
  b.setVal59(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto et67 = es.EntityId(e.UsingToken());
  b.setVal67(et67);
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
  auto v57 = e.TypeForDeclaration();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
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
  auto et67 = es.EntityId(e.DefaultArgumentToken());
  b.setVal67(et67);
  b.setVal76(e.HasDefaultArgument());
  b.setVal77(e.HasTypeConstraint());
  b.setVal78(e.IsExpandedParameterPack());
  b.setVal95(e.IsPackExpansion());
  b.setVal96(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  if (auto r58 = e.BraceRange(); auto rs58 = r58.Size()) {
    b.setVal58(es.EntityId(r58[0]));
    b.setVal59(es.EntityId(r58[rs58 - 1u]));
  } else {
    b.setVal58(0);
    b.setVal59(0);
  }
  auto et67 = es.EntityId(e.FirstInnerToken());
  b.setVal67(et67);
  auto et68 = es.EntityId(e.FirstOuterToken());
  b.setVal68(et68);
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
  b.setVal97(e.IsEnum());
  b.setVal98(e.IsFreeStanding());
  b.setVal99(e.IsInterface());
  b.setVal100(e.IsStruct());
  b.setVal101(e.IsThisDeclarationADefinition());
  b.setVal102(e.IsThisDeclarationADemotedDefinition());
  b.setVal103(e.IsUnion());
  b.setVal104(e.MayHaveOutOfDateDefinition());
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

void SerializeRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  b.setVal105(e.CanPassInRegisters());
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
  b.setVal106(e.HasFlexibleArrayMember());
  b.setVal107(e.HasLoadedFieldsFromExternalStorage());
  b.setVal108(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal109(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal110(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal111(e.HasObjectMember());
  b.setVal112(e.HasVolatileMember());
  b.setVal113(e.IsAnonymousStructOrUnion());
  b.setVal114(e.IsCapturedRecord());
  b.setVal115(e.IsInjectedClassName());
  b.setVal116(e.IsLambda());
  b.setVal117(e.IsMsStruct());
  b.setVal118(e.IsNonTrivialToPrimitiveCopy());
  b.setVal119(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal120(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal121(e.IsOrContainsUnion());
  b.setVal122(e.IsParameterDestroyedInCallee());
  b.setVal123(e.IsRandomized());
  b.setVal124(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(pf, es, b, e, nullptr);
  auto v125 = e.AllowConstDefaultInitializer();
  if (v125) {
    b.setVal125(static_cast<bool>(v125.value()));
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  do {
    auto ov176 = e.Bases();
    if (!ov176) {
      b.setVal127(false);
      break;
    }
    b.setVal127(true);
    auto v176 = std::move(*ov176);
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  auto v88 = e.CalculateInheritanceModel();
  if (v88) {
    b.setVal88(static_cast<unsigned char>(v88.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  do {
    auto v184 = e.Constructors();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  do {
    auto ov185 = e.Friends();
    if (!ov185) {
      b.setVal135(false);
      break;
    }
    b.setVal135(true);
    auto v185 = std::move(*ov185);
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
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
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v87 = e.LambdaContextDeclaration();
  if (v87) {
    auto id87 = es.EntityId(v87.value());
    b.setVal87(id87);
  } else {
    b.setVal87(mx::kInvalidEntityId);
  }
  do {
    auto ov186 = e.LambdaExplicitTemplateParameters();
    if (!ov186) {
      b.setVal137(false);
      break;
    }
    b.setVal137(true);
    auto v186 = std::move(*ov186);
    auto sv186 = b.initVal186(static_cast<unsigned>(v186.size()));
    auto i186 = 0u;
    for (const auto &e186 : v186) {
      sv186.set(i186, es.EntityId(e186));
      ++i186;
    }
  } while (false);
  auto v143 = e.LambdaManglingNumber();
  if (v143) {
    b.setVal143(static_cast<unsigned>(v143.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
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
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v187 = e.ODRHash();
  if (v187) {
    b.setVal187(static_cast<unsigned>(v187.value()));
    b.setVal140(true);
  } else {
    b.setVal140(false);
  }
  auto v129 = e.TemplateInstantiationPattern();
  if (v129) {
    auto id129 = es.EntityId(v129.value());
    b.setVal129(id129);
  } else {
    b.setVal129(mx::kInvalidEntityId);
  }
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v141 = e.HasAnyDependentBases();
  if (v141) {
    b.setVal141(static_cast<bool>(v141.value()));
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
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  auto v159 = e.HasDefinition();
  if (v159) {
    b.setVal159(static_cast<bool>(v159.value()));
    b.setVal160(true);
  } else {
    b.setVal160(false);
  }
  auto v161 = e.HasDirectFields();
  if (v161) {
    b.setVal161(static_cast<bool>(v161.value()));
    b.setVal162(true);
  } else {
    b.setVal162(false);
  }
  auto v163 = e.HasFriends();
  if (v163) {
    b.setVal163(static_cast<bool>(v163.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v169 = e.HasInClassInitializer();
  if (v169) {
    b.setVal169(static_cast<bool>(v169.value()));
    b.setVal170(true);
  } else {
    b.setVal170(false);
  }
  auto v171 = e.HasInheritedAssignment();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
    b.setVal172(true);
  } else {
    b.setVal172(false);
  }
  auto v173 = e.HasInheritedConstructor();
  if (v173) {
    b.setVal173(static_cast<bool>(v173.value()));
    b.setVal174(true);
  } else {
    b.setVal174(false);
  }
  auto v175 = e.HasInitializerMethod();
  if (v175) {
    b.setVal175(static_cast<bool>(v175.value()));
    b.setVal179(true);
  } else {
    b.setVal179(false);
  }
  auto v180 = e.HasIrrelevantDestructor();
  if (v180) {
    b.setVal180(static_cast<bool>(v180.value()));
    b.setVal181(true);
  } else {
    b.setVal181(false);
  }
  auto v182 = e.HasKnownLambdaInternalLinkage();
  if (v182) {
    b.setVal182(static_cast<bool>(v182.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
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
  auto v130 = e.IsLocalClass();
  if (v130) {
    auto id130 = es.EntityId(v130.value());
    b.setVal130(id130);
  } else {
    b.setVal130(mx::kInvalidEntityId);
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
    auto ov339 = e.VirtualBases();
    if (!ov339) {
      b.setVal340(false);
      break;
    }
    b.setVal340(true);
    auto v339 = std::move(*ov339);
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.EntityId(e339));
      ++i339;
    }
  } while (false);
  auto v131 = e.PrimaryBase();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  auto v341 = e.HasOwnVirtualFunctionTablePointer();
  if (v341) {
    b.setVal341(static_cast<bool>(v341.value()));
    b.setVal342(true);
  } else {
    b.setVal342(false);
  }
  auto v343 = e.HasExtendableVirtualFunctionTablePointer();
  if (v343) {
    b.setVal343(static_cast<bool>(v343.value()));
    b.setVal344(true);
  } else {
    b.setVal344(false);
  }
  auto v345 = e.HasVirtualBaseTablePointer();
  if (v345) {
    b.setVal345(static_cast<bool>(v345.value()));
    b.setVal346(true);
  } else {
    b.setVal346(false);
  }
  auto v347 = e.HasOwnVirtualBaseTablePointer();
  if (v347) {
    b.setVal347(static_cast<bool>(v347.value()));
    b.setVal348(true);
  } else {
    b.setVal348(false);
  }
}

void SerializeClassTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(pf, es, b, e, nullptr);
  auto et133 = es.EntityId(e.ExternToken());
  b.setVal133(et133);
  auto et134 = es.EntityId(e.PointOfInstantiation());
  b.setVal134(et134);
  b.setVal94(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal142(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v349 = e.TemplateArguments();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
  do {
    auto v350 = e.TemplateInstantiationArguments();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
  auto et144 = es.EntityId(e.TemplateKeywordToken());
  b.setVal144(et144);
  auto v145 = e.TypeAsWritten();
  if (v145) {
    auto id145 = es.EntityId(v145.value());
    b.setVal145(id145);
  } else {
    b.setVal145(mx::kInvalidEntityId);
  }
  b.setVal351(e.IsClassScopeExplicitSpecialization());
  b.setVal352(e.IsExplicitInstantiationOrSpecialization());
  b.setVal353(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal164(es.EntityId(e.InjectedSpecializationType()));
  b.setVal166(es.EntityId(e.InstantiatedFromMember()));
  b.setVal167(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal177(es.EntityId(e.TemplateParameters()));
  b.setVal354(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
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
    b.setVal105(true);
  } else {
    b.setVal105(false);
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
  b.setVal106(e.IsClosed());
  b.setVal107(e.IsClosedFlag());
  b.setVal108(e.IsClosedNonFlag());
  b.setVal109(e.IsComplete());
  b.setVal110(e.IsFixed());
  b.setVal111(e.IsScoped());
  b.setVal112(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto et58 = es.EntityId(e.EllipsisToken());
  b.setVal58(et58);
  auto et59 = es.EntityId(e.TypenameToken());
  b.setVal59(et59);
  auto et67 = es.EntityId(e.UsingToken());
  b.setVal67(et67);
  b.setVal75(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
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
  auto v68 = e.DescribedAliasTemplate();
  if (v68) {
    auto id68 = es.EntityId(v68.value());
    b.setVal68(id68);
  } else {
    b.setVal68(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
  auto et68 = es.EntityId(e.ColonToken());
  b.setVal68(et68);
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto et69 = es.EntityId(e.VarianceToken());
  b.setVal69(et69);
  b.setVal77(e.HasExplicitBound());
}

void SerializeTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal57(es.EntityId(e.TemplateParameters()));
  b.setVal58(es.EntityId(e.TemplatedDeclaration()));
  b.setVal75(e.HasAssociatedConstraints());
  b.setVal76(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal77(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal78(e.IsAbbreviated());
  b.setVal95(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal78(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal78(e.IsThisDeclarationADefinition());
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
  b.setVal59(es.EntityId(e.ConstraintExpression()));
  b.setVal77(e.IsTypeConcept());
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
  b.setVal77(e.DefaultArgumentWasInherited());
  auto et59 = es.EntityId(e.DefaultArgumentToken());
  b.setVal59(et59);
  b.setVal78(e.HasDefaultArgument());
  b.setVal95(e.IsExpandedParameterPack());
  b.setVal96(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.AtToken());
  b.setVal57(et57);
  b.setVal58(es.EntityId(e.GetterMethodDeclaration()));
  auto et59 = es.EntityId(e.GetterNameToken());
  b.setVal59(et59);
  auto et67 = es.EntityId(e.LParenToken());
  b.setVal67(et67);
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal68(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal69(es.EntityId(e.SetterMethodDeclaration()));
  auto et79 = es.EntityId(e.SetterNameToken());
  b.setVal79(et79);
  b.setVal80(es.EntityId(e.Type()));
  b.setVal75(e.IsAtomic());
  b.setVal76(e.IsClassProperty());
  b.setVal77(e.IsDirectProperty());
  b.setVal78(e.IsInstanceProperty());
  b.setVal95(e.IsOptional());
  b.setVal96(e.IsReadOnly());
  b.setVal97(e.IsRetaining());
}

void SerializeObjCMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal75(e.DefinedInNSObject());
  b.setVal57(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal58(es.EntityId(e.ClassInterface()));
  b.setVal59(es.EntityId(e.CommandDeclaration()));
  auto et67 = es.EntityId(e.DeclaratorEndToken());
  b.setVal67(et67);
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal68(es.EntityId(e.ReturnType()));
  if (auto r69 = e.ReturnTypeTokens(); auto rs69 = r69.Size()) {
    b.setVal69(es.EntityId(r69[0]));
    b.setVal79(es.EntityId(r69[rs69 - 1u]));
  } else {
    b.setVal69(0);
    b.setVal79(0);
  }
  auto et80 = es.EntityId(e.SelectorStartToken());
  b.setVal80(et80);
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

void SerializeObjCContainerDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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
  auto et59 = es.EntityId(e.AtStartToken());
  b.setVal59(et59);
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
    auto v176 = e.InstanceProperties();
    auto sv176 = b.initVal176(static_cast<unsigned>(v176.size()));
    auto i176 = 0u;
    for (const auto &e176 : v176) {
      sv176.set(i176, es.EntityId(e176));
      ++i176;
    }
  } while (false);
  do {
    auto v184 = e.Methods();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  do {
    auto v185 = e.Properties();
    auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
    auto i185 = 0u;
    for (const auto &e185 : v185) {
      sv185.set(i185, es.EntityId(e185));
      ++i185;
    }
  } while (false);
  pasta::DeclContext dc186(e);
  auto v186 = dc186.AlreadyLoadedDeclarations();
  auto sv186 = b.initVal186(static_cast<unsigned>(v186.size()));
  auto i186 = 0u;
  for (const pasta::Decl &e186 : v186) {
    sv186.set(i186, es.EntityId(e186));
    ++i186;
  }
}

void SerializeObjCCategoryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal75(e.IsClassExtension());
  auto et67 = es.EntityId(e.CategoryNameToken());
  b.setVal67(et67);
  b.setVal68(es.EntityId(e.ClassInterface()));
  b.setVal69(es.EntityId(e.Implementation()));
  auto et79 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal79(et79);
  auto et80 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal80(et80);
  b.setVal82(es.EntityId(e.NextClassCategory()));
  do {
    auto v313 = e.InstanceVariables();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  do {
    auto v339 = e.ProtocolTokens();
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.EntityId(e339));
      ++i339;
    }
  } while (false);
  do {
    auto v349 = e.Protocols();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  auto v74 = e.ObjCRuntimeNameAsString();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal75(e.HasDefinition());
  b.setVal76(e.IsNonRuntimeProtocol());
  b.setVal77(e.IsThisDeclarationADefinition());
  do {
    auto v313 = e.ProtocolTokens();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  do {
    auto v339 = e.Protocols();
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.EntityId(e339));
      ++i339;
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
    auto v313 = e.AllReferencedProtocols();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  b.setVal75(e.DeclaresOrInheritsDesignatedInitializers());
  auto et67 = es.EntityId(e.EndOfDefinitionToken());
  b.setVal67(et67);
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
  auto et79 = es.EntityId(e.SuperClassToken());
  b.setVal79(et79);
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
    auto v339 = e.InstanceVariables();
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.EntityId(e339));
      ++i339;
    }
  } while (false);
  do {
    auto v349 = e.KnownCategories();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
  do {
    auto v350 = e.KnownExtensions();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
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

void SerializeObjCImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal67(es.EntityId(e.ClassInterface()));
  do {
    auto v313 = e.PropertyImplementations();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  b.setVal68(es.EntityId(e.CategoryDeclaration()));
  auto et69 = es.EntityId(e.CategoryNameToken());
  b.setVal69(et69);
}

void SerializeObjCImplementationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  auto et68 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal68(et68);
  auto et69 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal69(et69);
  auto v74 = e.ObjCRuntimeNameAsString();
  std::string s74(v74.data(), v74.size());
  b.setVal74(s74);
  b.setVal79(es.EntityId(e.SuperClass()));
  auto et80 = es.EntityId(e.SuperClassToken());
  b.setVal80(et80);
  b.setVal75(e.HasDestructors());
  b.setVal76(e.HasNonZeroConstructors());
  do {
    auto v339 = e.InstanceVariables();
    auto sv339 = b.initVal339(static_cast<unsigned>(v339.size()));
    auto i339 = 0u;
    for (const auto &e339 : v339) {
      sv339.set(i339, es.EntityId(e339));
      ++i339;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal57(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeNamespaceAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.AliasToken());
  b.setVal57(et57);
  b.setVal58(es.EntityId(e.AliasedNamespace()));
  auto et59 = es.EntityId(e.NamespaceToken());
  b.setVal59(et59);
  auto et67 = es.EntityId(e.TargetNameToken());
  b.setVal67(et67);
}

void SerializeLinkageSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeLifetimeExtendedTemporaryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeImportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeImplicitConceptSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitConceptSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeFriendTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal50(es.EntityId(e.FriendDeclaration()));
  auto et57 = es.EntityId(e.FriendToken());
  b.setVal57(et57);
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

void SerializeFriendDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v50 = e.FriendDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  auto et57 = es.EntityId(e.FriendToken());
  b.setVal57(et57);
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

void SerializeFileScopeAsmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et50 = es.EntityId(e.AssemblyToken());
  b.setVal50(et50);
  b.setVal57(es.EntityId(e.AssemblyString()));
  auto et58 = es.EntityId(e.RParenToken());
  b.setVal58(et58);
}

void SerializeExternCContextDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeExportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et50 = es.EntityId(e.ExportToken());
  b.setVal50(et50);
  auto et57 = es.EntityId(e.RBraceToken());
  b.setVal57(et57);
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

void SerializeEmptyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

#pragma GCC diagnostic pop
}  // namespace indexer
