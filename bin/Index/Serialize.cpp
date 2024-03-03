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
#include "References.h"
#include "PendingFragment.h"
#include "TokenTree.h"
#include "Util.h"
namespace indexer {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"

void SerializeCXXCtorInitializer(const PendingFragment &pf, const EntityMapper &es, mx::ast::CXXCtorInitializer::Builder b, const pasta::CXXCtorInitializer &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(e.IsBaseInitializer());
  b.setVal1(e.IsMemberInitializer());
  b.setVal2(e.IsAnyMemberInitializer());
  b.setVal3(e.IsIndirectMemberInitializer());
  b.setVal4(e.IsInClassMemberInitializer());
  b.setVal5(e.IsDelegatingInitializer());
  b.setVal6(e.IsPackExpansion());
  b.setVal7(e.IsBaseVirtual());
  auto v8 = e.Member();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.AnyMember();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  auto v10 = e.IndirectMember();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.Initializer();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto et12 = es.EntityId(e.EllipsisToken());
  b.setVal12(et12);
  auto et13 = es.EntityId(e.MemberToken());
  b.setVal13(et13);
  auto et14 = es.EntityId(e.LeftAngleToken());
  b.setVal14(et14);
  auto et15 = es.EntityId(e.RightAngleToken());
  b.setVal15(et15);
  if (auto r16 = e.Tokens(); auto rs16 = r16.Size()) {
    b.setVal16(es.EntityId(r16[0]));
    b.setVal17(es.EntityId(r16[rs16 - 1u]));
  } else {
    b.setVal16(0);
    b.setVal17(0);
  }
}

void SerializeDesignator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Designator::Builder b, const pasta::Designator &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(e.IsFieldDesignator());
  b.setVal3(e.IsArrayDesignator());
  b.setVal4(e.IsArrayRangeDesignator());
  auto v5 = e.Field();
  if (v5) {
    auto id5 = es.EntityId(v5.value());
    b.setVal5(id5);
  } else {
    b.setVal5(mx::kInvalidEntityId);
  }
  if (auto r6 = e.Tokens(); auto rs6 = r6.Size()) {
    b.setVal6(es.EntityId(r6[0]));
    b.setVal7(es.EntityId(r6[rs6 - 1u]));
  } else {
    b.setVal6(0);
    b.setVal7(0);
  }
  auto et8 = es.EntityId(e.DotToken());
  b.setVal8(et8);
  auto et9 = es.EntityId(e.FieldToken());
  b.setVal9(et9);
  auto et10 = es.EntityId(e.LeftBracketToken());
  b.setVal10(et10);
  auto et11 = es.EntityId(e.RightBracketToken());
  b.setVal11(et11);
  auto et12 = es.EntityId(e.EllipsisToken());
  b.setVal12(et12);
}

void SerializeCXXBaseSpecifier(const PendingFragment &pf, const EntityMapper &es, mx::ast::CXXBaseSpecifier::Builder b, const pasta::CXXBaseSpecifier &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  if (auto r1 = e.Tokens(); auto rs1 = r1.Size()) {
    b.setVal1(es.EntityId(r1[0]));
    b.setVal2(es.EntityId(r1[rs1 - 1u]));
  } else {
    b.setVal1(0);
    b.setVal2(0);
  }
  auto et3 = es.EntityId(e.BaseTypeToken());
  b.setVal3(et3);
  b.setVal4(e.IsVirtual());
  b.setVal5(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal6(e.IsPackExpansion());
  b.setVal7(e.ConstructorsAreInherited());
  auto v8 = e.EllipsisToken();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  b.setVal9(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal11(es.EntityId(e.BaseType()));
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
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal3(e.IsEmpty());
  b.setVal4(e.IsDependent());
  b.setVal5(e.IsInstantiationDependent());
  b.setVal6(e.ContainsUnexpandedParameterPack());
  b.setVal7(e.IsPackExpansion());
  auto v8 = e.AsDeclaration();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.AsType();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  auto v10 = e.ParameterTypeForDeclaration();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.NullPointerType();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  do {
    auto ov12 = e.PackElements();
    if (!ov12) {
      b.setVal13(false);
      break;
    }
    b.setVal13(true);
    auto v12 = std::move(*ov12);
    auto sv12 = b.initVal12(static_cast<unsigned>(v12.size()));
    auto i12 = 0u;
    for (const auto &e12 : v12) {
      sv12.set(i12, es.EntityId(e12));
      ++i12;
    }
  } while (false);
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

void SerializeArmStreamingAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmStreamingAttr &e, const TokenTree *) {
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
  auto v8 = e.DereferencedType();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v16 = e.DereferencedTypeToken();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
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
  auto v8 = e.DereferencedType();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v16 = e.DereferencedTypeToken();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
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
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal15(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal16(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal17(e.IsUnresolvedType());
  b.setVal18(e.IsVLSTBuiltinType());
}

void SerializeTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto v20 = e.Declaration();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsParameterPack());
  b.setVal22(e.IsSugared());
}

void SerializeTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto v20 = e.AliasedType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsCurrentInstantiation());
  b.setVal22(e.IsSugared());
  b.setVal23(e.IsTypeAlias());
  do {
    auto v24 = e.TemplateArguments();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
}

void SerializeTagType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Declaration()));
  b.setVal21(e.IsBeingDefined());
}

void SerializeRecordType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  b.setVal22(e.HasConstFields());
  b.setVal23(e.IsSugared());
}

void SerializeEnumType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  b.setVal22(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.AssociatedDeclaration()));
  auto v25 = e.PackIndex();
  if (v25) {
    b.setVal25(static_cast<uint32_t>(v25.value()));
    b.setVal21(true);
  } else {
    b.setVal21(false);
  }
  b.setVal26(es.EntityId(e.ReplacedParameter()));
  b.setVal27(es.EntityId(e.ReplacementType()));
  b.setVal22(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.AssociatedDeclaration()));
  b.setVal21(e.Final());
  b.setVal26(es.EntityId(e.ReplacedParameter()));
  b.setVal22(e.IsSugared());
}

void SerializeReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.PointeeType()));
  b.setVal20(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal21(e.IsInnerReference());
  b.setVal22(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal26(es.EntityId(e.Desugar()));
  b.setVal23(e.IsSugared());
}

void SerializeLValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal26(es.EntityId(e.Desugar()));
  b.setVal23(e.IsSugared());
}

void SerializeQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal19(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal21(e.HasAddressSpace());
  b.setVal22(e.HasNonTrivialObjCLifetime());
  b.setVal23(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal29(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal30(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal31(e.HasQualifiers());
  b.setVal32(e.HasStrongOrWeakObjCLifetime());
  b.setVal33(e.IsCForbiddenLValueType());
  b.setVal34(e.IsCXX11PODType());
  b.setVal35(e.IsCXX98PODType());
  b.setVal36(e.IsCanonical());
  b.setVal37(e.IsCanonicalAsParameter());
  b.setVal38(e.IsConstQualified());
  b.setVal39(e.IsConstant());
  b.setVal40(e.IsLocalConstQualified());
  b.setVal41(e.IsLocalRestrictQualified());
  b.setVal42(e.IsLocalVolatileQualified());
  b.setVal43(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal44(e.IsNull());
  b.setVal45(e.IsObjCGCStrong());
  b.setVal46(e.IsObjCGCWeak());
  b.setVal47(e.IsPODType());
  b.setVal48(e.IsReferenceable());
  b.setVal49(e.IsRestrictQualified());
  b.setVal50(e.IsTrivialType());
  b.setVal51(e.IsTriviallyCopyableType());
  b.setVal52(e.IsTriviallyEqualityComparableType());
  b.setVal53(e.IsTriviallyRelocatableType());
  b.setVal54(e.IsVolatileQualified());
  b.setVal55(e.IsWebAssemblyFuncrefType());
  b.setVal56(e.IsWebAssemblyReferenceType());
  b.setVal57(e.MayBeDynamicClass());
  b.setVal58(e.MayBeNotDynamicClass());
}

void SerializePointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.PointeeType()));
  b.setVal21(e.IsSugared());
}

void SerializePipeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal21(e.IsReadOnly());
  b.setVal22(e.IsSugared());
}

void SerializeParenType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.InnerType()));
  b.setVal21(e.IsSugared());
}

void SerializePackExpansionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Pattern()));
  b.setVal21(e.IsSugared());
}

void SerializeObjCTypeParamType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal21(e.IsSugared());
}

void SerializeObjCObjectType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.BaseType()));
  b.setVal26(es.EntityId(e.Interface()));
  auto v27 = e.SuperClassType();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  do {
    auto v24 = e.TypeArguments();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  do {
    auto v59 = e.TypeArgumentsAsWritten();
    auto sv59 = b.initVal59(static_cast<unsigned>(v59.size()));
    auto i59 = 0u;
    for (const auto &e59 : v59) {
      sv59.set(i59, es.EntityId(e59));
      ++i59;
    }
  } while (false);
  b.setVal21(e.IsKindOfType());
  b.setVal22(e.IsKindOfTypeAsWritten());
  b.setVal23(e.IsObjCClass());
  b.setVal29(e.IsObjCId());
  b.setVal30(e.IsObjCQualifiedClass());
  b.setVal31(e.IsObjCQualifiedId());
  b.setVal32(e.IsObjCUnqualifiedClass());
  b.setVal33(e.IsObjCUnqualifiedId());
  b.setVal34(e.IsObjCUnqualifiedIdOrClass());
  b.setVal35(e.IsSpecialized());
  b.setVal36(e.IsSpecializedAsWritten());
  b.setVal37(e.IsSugared());
  b.setVal38(e.IsUnspecialized());
  b.setVal39(e.IsUnspecializedAsWritten());
  b.setVal60(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(pf, es, b, e, nullptr);
  b.setVal61(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.InterfaceDeclaration()));
  b.setVal26(es.EntityId(e.InterfaceType()));
  b.setVal27(es.EntityId(e.ObjectType()));
  b.setVal60(es.EntityId(e.PointeeType()));
  b.setVal61(es.EntityId(e.SuperClassType()));
  do {
    auto v24 = e.TypeArguments();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  do {
    auto v59 = e.TypeArgumentsAsWritten();
    auto sv59 = b.initVal59(static_cast<unsigned>(v59.size()));
    auto i59 = 0u;
    for (const auto &e59 : v59) {
      sv59.set(i59, es.EntityId(e59));
      ++i59;
    }
  } while (false);
  b.setVal21(e.IsKindOfType());
  b.setVal22(e.IsObjCIdOrClassType());
  b.setVal23(e.IsSpecialized());
  b.setVal29(e.IsSpecializedAsWritten());
  b.setVal30(e.IsSugared());
  b.setVal31(e.IsUnspecialized());
  b.setVal32(e.IsUnspecializedAsWritten());
  do {
    auto v62 = e.Qualifiers();
    auto sv62 = b.initVal62(static_cast<unsigned>(v62.size()));
    auto i62 = 0u;
    for (const auto &e62 : v62) {
      sv62.set(i62, es.EntityId(e62));
      ++i62;
    }
  } while (false);
  b.setVal63(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v64 = e.Protocols();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      sv64.set(i64, es.EntityId(e64));
      ++i64;
    }
  } while (false);
}

void SerializeMemberPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Class()));
  b.setVal26(es.EntityId(e.PointeeType()));
  b.setVal21(e.IsMemberDataPointer());
  b.setVal22(e.IsMemberFunctionPointer());
  b.setVal23(e.IsSugared());
}

void SerializeMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal21(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
  auto et26 = es.EntityId(e.AttributeToken());
  b.setVal26(et26);
  b.setVal27(es.EntityId(e.ColumnExpression()));
  b.setVal60(es.EntityId(e.RowExpression()));
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
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ModifiedType()));
  b.setVal26(es.EntityId(e.UnderlyingType()));
  b.setVal21(e.IsSugared());
}

void SerializeInjectedClassNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal26(es.EntityId(e.InjectedSpecializationType()));
  b.setVal27(es.EntityId(e.InjectedTST()));
  b.setVal21(e.IsSugared());
}

void SerializeFunctionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal19(es.EntityId(e.CallResultType()));
  b.setVal21(e.CmseNSCallAttribute());
  b.setVal22(e.HasRegParm());
  b.setVal23(e.NoReturnAttribute());
  b.setVal20(es.EntityId(e.ReturnType()));
  b.setVal29(e.IsConst());
  b.setVal30(e.IsRestrict());
  b.setVal31(e.IsVolatile());
}

void SerializeFunctionProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  auto v65 = e.CanThrow();
  if (v65) {
    b.setVal65(static_cast<unsigned char>(v65.value()));
    b.setVal32(true);
  } else {
    b.setVal32(false);
  }
  b.setVal26(es.EntityId(e.Desugar()));
  auto et27 = es.EntityId(e.EllipsisToken());
  b.setVal27(et27);
  auto v60 = e.ExceptionSpecDeclaration();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  auto v61 = e.ExceptionSpecTemplate();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  b.setVal66(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v63 = e.NoexceptExpression();
  if (v63) {
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  do {
    auto v24 = e.ParameterTypes();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  b.setVal67(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal33(e.HasDependentExceptionSpec());
  b.setVal34(e.HasDynamicExceptionSpec());
  b.setVal35(e.HasExceptionSpec());
  b.setVal36(e.HasExtParameterInfos());
  b.setVal37(e.HasInstantiationDependentExceptionSpec());
  b.setVal38(e.HasNoexceptExceptionSpec());
  b.setVal39(e.HasTrailingReturn());
  auto v40 = e.IsNothrow();
  if (v40) {
    b.setVal40(static_cast<bool>(v40.value()));
    b.setVal41(true);
  } else {
    b.setVal41(false);
  }
  b.setVal42(e.IsSugared());
  b.setVal43(e.IsTemplateVariadic());
  b.setVal44(e.IsVariadic());
  do {
    auto v59 = e.ExceptionTypes();
    auto sv59 = b.initVal59(static_cast<unsigned>(v59.size()));
    auto i59 = 0u;
    for (const auto &e59 : v59) {
      sv59.set(i59, es.EntityId(e59));
      ++i59;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  b.setVal26(es.EntityId(e.Desugar()));
  b.setVal32(e.IsSugared());
}

void SerializeDependentVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto et20 = es.EntityId(e.AttributeToken());
  b.setVal20(et20);
  b.setVal26(es.EntityId(e.ElementType()));
  b.setVal27(es.EntityId(e.SizeExpression()));
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal21(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto et20 = es.EntityId(e.AttributeToken());
  b.setVal20(et20);
  b.setVal26(es.EntityId(e.ElementType()));
  b.setVal27(es.EntityId(e.SizeExpression()));
  b.setVal21(e.IsSugared());
}

void SerializeDependentBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.NumBitsExpression()));
  b.setVal21(e.IsSigned());
  b.setVal22(e.IsSugared());
  b.setVal23(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.AddressSpaceExpression()));
  auto et26 = es.EntityId(e.AttributeToken());
  b.setVal26(et26);
  b.setVal27(es.EntityId(e.PointeeType()));
  b.setVal21(e.IsSugared());
}

void SerializeDeducedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto v20 = e.ResolvedType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsDeduced());
  b.setVal22(e.IsSugared());
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
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v24 = e.TypeConstraintArguments();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
  auto v26 = e.TypeConstraintConcept();
  if (v26) {
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
  } else {
    b.setVal26(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsConstrained());
  b.setVal29(e.IsDecltypeAuto());
  b.setVal30(e.IsGNUAutoType());
}

void SerializeDecltypeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.UnderlyingExpression()));
  b.setVal26(es.EntityId(e.UnderlyingType()));
  b.setVal21(e.IsSugared());
}

void SerializeComplexType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal21(e.IsSugared());
}

void SerializeBuiltinType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.BuiltinKind())));
  b.setVal21(e.IsFloatingPoint());
  b.setVal22(e.IsInteger());
  b.setVal23(e.IsSVEBool());
  b.setVal29(e.IsSVECount());
  b.setVal30(e.IsSignedInteger());
  b.setVal31(e.IsSugared());
  b.setVal32(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.PointeeType()));
  b.setVal21(e.IsSugared());
}

void SerializeBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal21(e.IsSigned());
  b.setVal22(e.IsSugared());
  b.setVal23(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Attribute()));
  b.setVal26(es.EntityId(e.WrappedType()));
  b.setVal21(e.IsSugared());
}

void SerializeAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  auto v20 = e.Attribute();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal68(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal26(es.EntityId(e.EquivalentType()));
  auto v28 = e.ImmediateNullability();
  if (v28) {
    b.setVal28(static_cast<unsigned char>(v28.value()));
    b.setVal21(true);
  } else {
    b.setVal21(false);
  }
  b.setVal27(es.EntityId(e.ModifiedType()));
  b.setVal22(e.HasAttribute());
  b.setVal23(e.IsCallingConv());
  b.setVal29(e.IsMSTypeSpec());
  b.setVal30(e.IsQualifier());
  b.setVal31(e.IsSugared());
  b.setVal32(e.IsWebAssemblyFuncrefSpec());
}

void SerializeAtomicType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ValueType()));
  b.setVal21(e.IsSugared());
}

void SerializeArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.ElementType()));
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  if (auto r26 = e.BracketsRange(); auto rs26 = r26.Size()) {
    b.setVal26(es.EntityId(r26[0]));
    b.setVal27(es.EntityId(r26[rs26 - 1u]));
  } else {
    b.setVal26(0);
    b.setVal27(0);
  }
  auto et60 = es.EntityId(e.LBracketToken());
  b.setVal60(et60);
  auto et61 = es.EntityId(e.RBracketToken());
  b.setVal61(et61);
  b.setVal63(es.EntityId(e.SizeExpression()));
  b.setVal21(e.IsSugared());
}

void SerializeIncompleteArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  b.setVal21(e.IsSugared());
}

void SerializeDependentSizedArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  if (auto r26 = e.BracketsRange(); auto rs26 = r26.Size()) {
    b.setVal26(es.EntityId(r26[0]));
    b.setVal27(es.EntityId(r26[rs26 - 1u]));
  } else {
    b.setVal26(0);
    b.setVal27(0);
  }
  auto et60 = es.EntityId(e.LBracketToken());
  b.setVal60(et60);
  auto et61 = es.EntityId(e.RBracketToken());
  b.setVal61(et61);
  auto v63 = e.SizeExpression();
  if (v63) {
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsSugared());
}

void SerializeConstantArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Desugar()));
  auto v26 = e.SizeExpression();
  if (v26) {
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
  } else {
    b.setVal26(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsSugared());
}

void SerializeAdjustedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ResolvedType()));
  b.setVal26(es.EntityId(e.OriginalType()));
  b.setVal21(e.IsSugared());
}

void SerializeDecayedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(pf, es, b, e, nullptr);
  b.setVal27(es.EntityId(e.PointeeType()));
}

void SerializeTypeWithKeyword(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.NamedType()));
  auto v26 = e.OwnedTagDeclaration();
  if (v26) {
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
  } else {
    b.setVal26(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal21(e.IsSugared());
  do {
    auto v24 = e.TemplateArguments();
    auto sv24 = b.initVal24(static_cast<unsigned>(v24.size()));
    auto i24 = 0u;
    for (const auto &e24 : v24) {
      sv24.set(i24, es.EntityId(e24));
      ++i24;
    }
  } while (false);
}

void SerializeDependentNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal21(e.IsSugared());
}

void SerializeVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal21(e.IsSugared());
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
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.FoundDeclaration()));
  b.setVal26(es.EntityId(e.UnderlyingType()));
  b.setVal21(e.IsSugared());
  b.setVal22(e.TypeMatchesDeclaration());
}

void SerializeUnresolvedUsingType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal21(e.IsSugared());
}

void SerializeUnaryTransformType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v19 = e.Desugar();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto v20 = e.BaseType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  auto v26 = e.UnderlyingType();
  if (v26) {
    auto id26 = es.EntityId(v26.value());
    b.setVal26(id26);
  } else {
    b.setVal26(mx::kInvalidEntityId);
  }
  b.setVal21(e.IsSugared());
}

void SerializeTypedefType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal21(e.IsSugared());
  b.setVal22(e.TypeMatchesDeclaration());
}

void SerializeTypeOfType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal20(es.EntityId(e.UnmodifiedType()));
  b.setVal21(e.IsSugared());
}

void SerializeTypeOfExprType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal19(es.EntityId(e.Desugar()));
  b.setVal28(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal20(es.EntityId(e.UnderlyingExpression()));
  b.setVal21(e.IsSugared());
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
  auto v9 = e.BeginStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  b.setVal10(es.EntityId(e.Body()));
  auto et11 = es.EntityId(e.CoawaitToken());
  b.setVal11(et11);
  auto et13 = es.EntityId(e.ColonToken());
  b.setVal13(et13);
  auto v14 = e.Condition();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v17 = e.EndStatement();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
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
  auto v10 = e.CaughtType();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
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
  auto et32 = es.EntityId(e.ExpressionToken());
  b.setVal32(et32);
  auto v33 = e.ObjCProperty();
  if (v33) {
    auto id33 = es.EntityId(v33.value());
    b.setVal33(id33);
  } else {
    b.setVal33(mx::kInvalidEntityId);
  }
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
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
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal24(e.HasNonTrivialCall());
  b.setVal25(e.IsDefaultArgument());
  b.setVal57(e.IsGLValue());
  b.setVal58(e.IsImplicitCXXThis());
  b.setVal59(e.IsInstantiationDependent());
  b.setVal70(e.IsLValue());
  b.setVal71(e.IsOBJCGCCandidate());
  b.setVal72(e.IsObjCSelfExpression());
  b.setVal73(e.IsOrdinaryOrBitFieldObject());
  b.setVal74(e.IsPRValue());
  auto v75 = e.IsReadIfDiscardedInCPlusPlus11();
  if (v75) {
    b.setVal75(static_cast<bool>(v75.value()));
    b.setVal76(true);
  } else {
    b.setVal76(false);
  }
  b.setVal77(e.IsTypeDependent());
  b.setVal78(e.IsValueDependent());
  b.setVal79(e.IsXValue());
  b.setVal80(e.RefersToBitField());
  b.setVal81(e.RefersToGlobalRegisterVariable());
  b.setVal82(e.RefersToMatrixElement());
  b.setVal83(e.RefersToVectorElement());
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
  b.setVal84(e.IsDirectInitializer());
  b.setVal85(e.UsesGNUSyntax());
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
  b.setVal84(e.HasExplicitTemplateArguments());
  b.setVal85(e.HasTemplateKeyword());
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
  b.setVal84(e.HadMultipleCandidates());
  b.setVal85(e.HasExplicitTemplateArguments());
  b.setVal86(e.HasQualifier());
  b.setVal87(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal88(e.HasTemplateKeyword());
  b.setVal89(e.IsImmediateEscalating());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal91(e.RefersToEnclosingVariableOrCapture());
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
  b.setVal84(e.IsImplicit());
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
}

void SerializeCompoundLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Initializer()));
  auto et38 = es.EntityId(e.LParenToken());
  b.setVal38(et38);
  b.setVal84(e.IsFileScope());
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
  b.setVal84(e.IsConditionDependent());
  b.setVal85(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
}

void SerializeCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
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
  b.setVal84(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal85(e.IsPartOfExplicitCast());
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
  b.setVal85(e.IsAlwaysNull());
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
  b.setVal85(e.IsListInitialization());
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
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
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
  b.setVal84(e.HasStoredFPFeatures());
  b.setVal85(e.HasUnusedResultAttribute());
  b.setVal86(e.IsBuiltinAssumeFalse());
  b.setVal87(e.IsCallToStdMove());
  b.setVal88(e.IsUnevaluatedBuiltinCall());
  b.setVal89(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et42 = es.EntityId(e.OperatorToken());
  b.setVal42(et42);
  b.setVal91(e.IsAssignmentOperation());
  b.setVal93(e.IsComparisonOperation());
  b.setVal94(e.IsInfixBinaryOperation());
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
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
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
  b.setVal84(e.IsTypeOperand());
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
  b.setVal84(e.IsListInitialization());
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
  auto v84 = e.IsMostDerived();
  if (v84) {
    b.setVal84(static_cast<bool>(v84.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  b.setVal86(e.IsPotentiallyEvaluated());
  b.setVal87(e.IsTypeOperand());
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
  b.setVal84(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal84(e.IsImplicit());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et38 = es.EntityId(e.OperatorToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal40(es.EntityId(e.SemanticForm()));
  b.setVal84(e.IsAssignmentOperation());
  b.setVal85(e.IsComparisonOperation());
  b.setVal86(e.IsReversed());
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
  auto et42 = es.EntityId(e.TildeToken());
  b.setVal42(et42);
  b.setVal84(e.HasQualifier());
  b.setVal85(e.IsArrow());
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
  b.setVal84(e.Value());
}

void SerializeCXXNewExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal84(e.DoesUsualArrayDeleteWantSize());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v42 = e.Initializer();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto v43 = e.OperatorDelete();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto v44 = e.OperatorNew();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  if (auto r45 = e.TypeIdParentheses(); auto rs45 = r45.Size()) {
    b.setVal45(es.EntityId(r45[0]));
    b.setVal46(es.EntityId(r45[rs45 - 1u]));
  } else {
    b.setVal45(0);
    b.setVal46(0);
  }
  b.setVal85(e.HasInitializer());
  b.setVal86(e.IsArray());
  b.setVal87(e.IsGlobalNew());
  b.setVal88(e.IsParenthesisTypeId());
  b.setVal89(e.PassAlignment());
  do {
    auto v15 = e.PlacementArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
}

void SerializeCXXInheritedCtorInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal84(e.ConstructsVirtualBase());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal37(es.EntityId(e.Constructor()));
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  b.setVal85(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v37 = e.Callee();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto et38 = es.EntityId(e.EllipsisToken());
  b.setVal38(et38);
  auto v39 = e.Initializer();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.LHS();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto et41 = es.EntityId(e.LParenToken());
  b.setVal41(et41);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal42(es.EntityId(e.Pattern()));
  auto v43 = e.RHS();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto et44 = es.EntityId(e.RParenToken());
  b.setVal44(et44);
  b.setVal84(e.IsLeftFold());
  b.setVal85(e.IsRightFold());
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
  b.setVal84(e.HasExplicitTemplateArguments());
  b.setVal85(e.HasTemplateKeyword());
  b.setVal86(e.IsArrow());
  b.setVal87(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal84(e.DoesUsualArrayDeleteWantSize());
  b.setVal37(es.EntityId(e.Argument()));
  auto v38 = e.DestroyedType();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.OperatorDelete();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal85(e.IsArrayForm());
  b.setVal86(e.IsArrayFormAsWritten());
  b.setVal87(e.IsGlobalDelete());
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
  b.setVal84(e.HasRewrittenInitializer());
}

void SerializeCXXDefaultArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Expression()));
  b.setVal38(es.EntityId(e.Parameter()));
  auto v39 = e.RewrittenExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto et40 = es.EntityId(e.UsedToken());
  b.setVal40(et40);
  b.setVal84(e.HasRewrittenInitializer());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal84(e.HadMultipleCandidates());
  b.setVal85(e.IsElidable());
  b.setVal86(e.IsImmediateEscalating());
  b.setVal87(e.IsListInitialization());
  b.setVal88(e.IsStdInitializerListInitialization());
  b.setVal89(e.RequiresZeroInitialization());
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
  b.setVal84(e.Value());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto et38 = es.EntityId(e.OperatorToken());
  b.setVal38(et38);
  b.setVal39(es.EntityId(e.RHS()));
  b.setVal84(e.HasStoredFPFeatures());
  b.setVal85(e.IsAdditiveOperation());
  b.setVal86(e.IsAssignmentOperation());
  b.setVal87(e.IsBitwiseOperation());
  b.setVal88(e.IsCommaOperation());
  b.setVal89(e.IsComparisonOperation());
  b.setVal91(e.IsCompoundAssignmentOperation());
  b.setVal93(e.IsEqualityOperation());
  b.setVal94(e.IsLogicalOperation());
  b.setVal95(e.IsMultiplicativeOperation());
  b.setVal96(e.IsPointerMemoryOperation());
  b.setVal97(e.IsRelationalOperation());
  b.setVal98(e.IsShiftAssignOperation());
  b.setVal99(e.IsShiftOperation());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
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
  b.setVal84(e.IsCmpXChg());
  b.setVal85(e.IsOpenCL());
  b.setVal86(e.IsVolatile());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
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
  b.setVal84(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal84(e.CanOverflow());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal85(e.HasStoredFPFeatures());
  b.setVal86(e.IsArithmeticOperation());
  b.setVal87(e.IsDecrementOperation());
  b.setVal88(e.IsIncrementDecrementOperation());
  b.setVal89(e.IsIncrementOperation());
  b.setVal91(e.IsPostfix());
  b.setVal93(e.IsPrefix());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.KeywordKind())));
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.TypeOfArgument()));
  b.setVal84(e.IsArgumentType());
}

void SerializeTypoExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v84 = e.Value();
  if (v84) {
    b.setVal84(static_cast<bool>(v84.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
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
  auto v100 = e.PackIndex();
  if (v100) {
    b.setVal100(static_cast<uint32_t>(v100.value()));
    b.setVal84(true);
  } else {
    b.setVal84(false);
  }
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
  b.setVal85(e.IsReferenceParameter());
}

void SerializeStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v84 = e.ContainsNonAscii();
  if (v84) {
    b.setVal84(static_cast<bool>(v84.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  auto v86 = e.ContainsNonAsciiOrNull();
  if (v86) {
    b.setVal86(static_cast<bool>(v86.value()));
    b.setVal87(true);
  } else {
    b.setVal87(false);
  }
  auto v60 = e.Bytes();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto v65 = e.String();
  if (v65) {
    if (v65->empty()) {
      b.setVal65("");
    } else {
      std::string s65(v65->data(), v65->size());
      b.setVal65(s65);
    }
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  b.setVal89(e.IsOrdinary());
  b.setVal91(e.IsPascal());
  b.setVal93(e.IsUTF16());
  b.setVal94(e.IsUTF32());
  b.setVal95(e.IsUTF8());
  b.setVal96(e.IsUnevaluated());
  b.setVal97(e.IsWide());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal84(e.IsIntType());
}

void SerializeSizeOfPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.OperatorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Pack()));
  auto v100 = e.PackLength();
  if (v100) {
    b.setVal100(static_cast<uint32_t>(v100.value()));
    b.setVal84(true);
  } else {
    b.setVal84(false);
  }
  auto et39 = es.EntityId(e.PackToken());
  b.setVal39(et39);
  do {
    auto ov15 = e.PartialArguments();
    if (!ov15) {
      b.setVal85(false);
      break;
    }
    b.setVal85(true);
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
  b.setVal86(e.IsPartiallySubstituted());
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
  auto v37 = e.FunctionName();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v60 = e.IdentifierKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto et38 = es.EntityId(e.Token());
  b.setVal38(et38);
  b.setVal84(e.IsTransparent());
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
  b.setVal84(e.HasExplicitTemplateArguments());
  b.setVal85(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.BaseType()));
  auto et43 = es.EntityId(e.MemberToken());
  b.setVal43(et43);
  auto et44 = es.EntityId(e.OperatorToken());
  b.setVal44(et44);
  b.setVal86(e.HasUnresolvedUsing());
  b.setVal87(e.IsArrow());
  b.setVal88(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal86(e.IsOverloaded());
  b.setVal87(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  auto v38 = e.SourceExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal84(e.IsUnique());
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
  b.setVal84(e.IsArraySubscriptReferenceExpression());
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
  b.setVal84(e.IsClassReceiver());
  b.setVal85(e.IsExplicitProperty());
  b.setVal86(e.IsImplicitProperty());
  b.setVal87(e.IsMessagingGetter());
  b.setVal88(e.IsMessagingSetter());
  b.setVal89(e.IsObjectReceiver());
  b.setVal91(e.IsSuperReceiver());
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
  b.setVal39(es.EntityId(e.InstanceReceiver()));
  auto et40 = es.EntityId(e.LeftToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.MethodDeclaration()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal42(es.EntityId(e.ReceiverInterface()));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r43 = e.ReceiverRange(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  b.setVal45(es.EntityId(e.ReceiverType()));
  auto et46 = es.EntityId(e.RightToken());
  b.setVal46(et46);
  auto et47 = es.EntityId(e.SelectorStartToken());
  b.setVal47(et47);
  auto et48 = es.EntityId(e.SuperToken());
  b.setVal48(et48);
  b.setVal49(es.EntityId(e.SuperType()));
  b.setVal84(e.IsClassMessage());
  b.setVal85(e.IsDelegateInitializerCall());
  b.setVal86(e.IsImplicit());
  b.setVal87(e.IsInstanceMessage());
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
  b.setVal84(e.IsArrow());
  b.setVal85(e.IsFreeInstanceVariable());
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
  b.setVal84(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.SubExpression()));
  b.setVal84(e.ShouldCopy());
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
  b.setVal84(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal84(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal84(e.HasVersion());
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
  b.setVal84(e.HadMultipleCandidates());
  b.setVal85(e.HasExplicitTemplateArguments());
  b.setVal86(e.HasQualifier());
  b.setVal87(e.HasTemplateKeyword());
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsImplicitAccess());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Base()));
  b.setVal38(es.EntityId(e.ColumnIndex()));
  auto et39 = es.EntityId(e.RBracketToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.RowIndex()));
  b.setVal84(e.IsIncomplete());
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal84(e.IsBoundToLvalueReference());
  b.setVal85(e.IsUsableInConstantExpressions());
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
  b.setVal84(e.IsArrow());
  b.setVal85(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.Body()));
  b.setVal38(es.EntityId(e.CallOperator()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
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
  b.setVal84(e.HasExplicitParameters());
  b.setVal85(e.HasExplicitResultType());
  b.setVal86(e.IsGenericLambda());
  b.setVal87(e.IsMutable());
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
  b.setVal84(e.HadArrayRangeDesignator());
  b.setVal85(e.HasArrayFiller());
  b.setVal86(e.HasDesignatedInitializer());
  do {
    auto v15 = e.Initializers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal87(e.IsExplicit());
  b.setVal88(e.IsSemanticForm());
  b.setVal89(e.IsStringLiteralInitializer());
  b.setVal91(e.IsSyntacticForm());
  auto v93 = e.IsTransparent();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
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
  auto v37 = e.ControllingExpression();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  auto v38 = e.ControllingType();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto et39 = es.EntityId(e.DefaultToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.GenericToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
  auto v42 = e.ResultExpression();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  b.setVal84(e.IsExpressionPredicate());
  b.setVal85(e.IsResultDependent());
  b.setVal86(e.IsTypePredicate());
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
  b.setVal84(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  (void) pf;
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal84(e.HasAPValueResult());
  b.setVal85(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et37 = es.EntityId(e.Token());
  b.setVal37(et37);
  b.setVal84(e.IsExact());
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
  b.setVal84(e.ContainsDuplicateElements());
  auto et37 = es.EntityId(e.AccessorToken());
  b.setVal37(et37);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal85(e.IsArrow());
}

void SerializeExpressionTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal37(es.EntityId(e.QueriedExpression()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal84(e.Value());
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
  b.setVal4(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  auto v5 = e.DefiningAttribute();
  if (v5) {
    auto id5 = es.EntityId(v5.value());
    b.setVal5(id5);
  } else {
    b.setVal5(mx::kInvalidEntityId);
  }
  auto v6 = e.DescribedTemplate();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  auto v7 = e.DescribedTemplateParameters();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  auto v8 = e.ExternalSourceSymbolAttribute();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  b.setVal9(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v10 = e.MaxAlignment();
  if (v10) {
    b.setVal10(static_cast<uint32_t>(v10.value()));
    b.setVal11(true);
  } else {
    b.setVal11(false);
  }
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v13 = e.NonClosureContext();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  b.setVal14(e.HasAttributes());
  b.setVal15(e.HasOwningModule());
  b.setVal16(e.HasTagIdentifierNamespace());
  b.setVal17(e.IsDefinedOutsideFunctionOrMethod());
  b.setVal18(e.IsDeprecated());
  b.setVal19(e.IsDiscardedInGlobalModuleFragment());
  b.setVal20(e.IsFileContextDeclaration());
  b.setVal21(e.IsFunctionOrFunctionTemplate());
  b.setVal22(e.IsFunctionPointerType());
  b.setVal23(e.IsImplicit());
  b.setVal24(e.IsInAnonymousNamespace());
  b.setVal25(e.IsInAnotherModuleUnit());
  b.setVal26(e.IsInExportDeclarationContext());
  auto v27 = e.IsInLocalScopeForInstantiation();
  if (v27) {
    b.setVal27(static_cast<bool>(v27.value()));
    b.setVal28(true);
  } else {
    b.setVal28(false);
  }
  b.setVal29(e.IsInStdNamespace());
  b.setVal30(e.IsInvisibleOutsideTheOwningModule());
  b.setVal31(e.IsLocalExternDeclaration());
  b.setVal32(e.IsModulePrivate());
  b.setVal33(e.IsOutOfLine());
  b.setVal34(e.IsParameterPack());
  b.setVal35(e.IsTemplateDeclaration());
  b.setVal36(e.IsTemplateParameter());
  b.setVal37(e.IsTemplateParameterPack());
  b.setVal38(e.IsTemplated());
  b.setVal39(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal40(e.IsUnavailable());
  b.setVal41(e.IsUnconditionallyVisible());
  b.setVal42(e.IsWeakImported());
  b.setVal43(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal44(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto et45 = es.EntityId(e.Token());
  if (!et45) {
    et45 = pf.DeclTokenEntityId(e);
  }
  b.setVal45(et45);
  if (auto r46 = e.Tokens(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal48(es.EntityId(e.Specialization()));
  b.setVal49(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeBlockDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal49(e.BlockMissingReturnType());
  b.setVal52(e.CanAvoidCopyToHeap());
  b.setVal53(e.CapturesCXXThis());
  b.setVal54(e.DoesNotEscape());
  auto v48 = e.BlockManglingContextDeclaration();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  auto et55 = es.EntityId(e.CaretToken());
  b.setVal55(et55);
  b.setVal56(es.EntityId(e.CompoundBody()));
  b.setVal57(es.EntityId(e.SignatureAsWritten()));
  b.setVal58(e.HasCaptures());
  b.setVal59(e.IsConversionFromLambda());
  b.setVal60(e.IsVariadic());
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
  pasta::DeclContext dc61(e);
  auto v61 = dc61.AlreadyLoadedDeclarations();
  auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
  auto i61 = 0u;
  for (const pasta::Decl &e61 : v61) {
    sv61.set(i61, es.EntityId(e61));
    ++i61;
  }
}

void SerializeAccessSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et48 = es.EntityId(e.AccessSpecifierToken());
  b.setVal48(et48);
  auto et55 = es.EntityId(e.ColonToken());
  b.setVal55(et55);
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
    auto v50 = e.Varlists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
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
    auto v50 = e.Varlists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeTopLevelStmtDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal48(es.EntityId(e.Statement()));
  b.setVal49(e.IsSemiMissing());
}

void SerializeStaticAssertDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal48(es.EntityId(e.AssertExpression()));
  auto v55 = e.Message();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  auto et56 = es.EntityId(e.RParenToken());
  b.setVal56(et56);
  b.setVal49(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
  }
}

void SerializePragmaDetectMismatchDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v62 = e.Name();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  auto v63 = e.Value();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
}

void SerializePragmaCommentDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v62 = e.Argument();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal48(es.EntityId(e.GetterCXXConstructor()));
  b.setVal55(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal56(es.EntityId(e.PropertyDeclaration()));
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal57(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto et65 = es.EntityId(e.PropertyInstanceVariableDeclarationToken());
  b.setVal65(et65);
  b.setVal66(es.EntityId(e.SetterCXXAssignment()));
  b.setVal67(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal49(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal62(e.Name());
  auto v68 = e.ObjCFStringFormattingFamily();
  if (v68) {
    b.setVal68(static_cast<unsigned char>(v68.value()));
    b.setVal49(true);
  } else {
    b.setVal49(false);
  }
  b.setVal63(e.QualifiedNameAsString());
  b.setVal48(es.EntityId(e.UnderlyingDeclaration()));
  auto v69 = e.Visibility();
  if (v69) {
    b.setVal69(static_cast<unsigned char>(v69.value()));
    b.setVal52(true);
  } else {
    b.setVal52(false);
  }
  b.setVal53(e.HasExternalFormalLinkage());
  b.setVal54(e.HasLinkage());
  b.setVal58(e.HasLinkageBeenComputed());
  b.setVal59(e.IsCXXClassMember());
  b.setVal60(e.IsCXXInstanceMember());
  b.setVal70(e.IsExternallyDeclarable());
  b.setVal71(e.IsExternallyVisible());
  b.setVal72(e.IsLinkageValid());
}

void SerializeLabelDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v73 = e.MSAssemblyLabel();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal55(es.EntityId(e.Statement()));
  b.setVal74(e.IsGnuLocal());
  b.setVal75(e.IsMSAssemblyLabel());
  b.setVal76(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et55 = es.EntityId(e.LBraceToken());
  b.setVal55(et55);
  auto et56 = es.EntityId(e.TokenStart());
  b.setVal56(et56);
  auto et57 = es.EntityId(e.RBraceToken());
  b.setVal57(et57);
  b.setVal74(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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

void SerializeUsingEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.EnumDeclaration()));
  auto et56 = es.EntityId(e.EnumToken());
  b.setVal56(et56);
  b.setVal57(es.EntityId(e.EnumType()));
  auto et65 = es.EntityId(e.UsingToken());
  b.setVal65(et65);
}

void SerializeUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  auto et55 = es.EntityId(e.UsingToken());
  b.setVal55(et55);
  b.setVal74(e.HasTypename());
  b.setVal75(e.IsAccessDeclaration());
}

void SerializeValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v55 = e.PotentiallyDecomposedVariableDeclaration();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  b.setVal56(es.EntityId(e.Type()));
  b.setVal74(e.IsInitializerCapture());
  b.setVal75(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.EllipsisToken());
  b.setVal57(et57);
  auto et65 = es.EntityId(e.UsingToken());
  b.setVal65(et65);
  b.setVal76(e.IsAccessDeclaration());
  b.setVal77(e.IsPackExpansion());
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
  b.setVal57(es.EntityId(e.Combiner()));
  b.setVal65(es.EntityId(e.CombinerIn()));
  b.setVal66(es.EntityId(e.CombinerOut()));
  b.setVal67(es.EntityId(e.InitializerOriginal()));
  b.setVal78(es.EntityId(e.InitializerPrivate()));
  b.setVal79(es.EntityId(e.Initializer()));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc50(e);
  auto v50 = dc50.AlreadyLoadedDeclarations();
  auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
  auto i50 = 0u;
  for (const pasta::Decl &e50 : v50) {
    sv50.set(i50, es.EntityId(e50));
    ++i50;
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
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
  auto v65 = e.VariableDeclaration();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto v57 = e.InitializerExpression();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et57 = es.EntityId(e.FirstInnerToken());
  b.setVal57(et57);
  auto et65 = es.EntityId(e.FirstOuterToken());
  b.setVal65(et65);
  auto v66 = e.TrailingRequiresClause();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
  } else {
    b.setVal66(mx::kInvalidEntityId);
  }
  auto et67 = es.EntityId(e.TypeSpecEndToken());
  b.setVal67(et67);
  auto et78 = es.EntityId(e.TypeSpecStartToken());
  b.setVal78(et78);
  do {
    auto v50 = e.TemplateParameterLists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v79 = e.ActingDefinition();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v81 = e.DescribedVariableTemplate();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto v82 = e.Initializer();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v83 = e.InitializingDeclaration();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  auto v84 = e.InstantiatedFromStaticDataMember();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto et86 = es.EntityId(e.PointOfInstantiation());
  b.setVal86(et86);
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v91 = e.TemplateInstantiationPattern();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
  } else {
    b.setVal91(mx::kInvalidEntityId);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal76(e.HasConstantInitialization());
  b.setVal77(e.HasDependentAlignment());
  b.setVal94(e.HasExternalStorage());
  auto v95 = e.HasFlexibleArrayInitializer();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal97(e.HasGlobalStorage());
  b.setVal98(e.HasInitializer());
  b.setVal99(e.HasLocalStorage());
  b.setVal100(e.IsARCPseudoStrong());
  b.setVal101(e.IsCXXForRangeDeclaration());
  b.setVal102(e.IsConstexpr());
  b.setVal103(e.IsDirectInitializer());
  b.setVal104(e.IsEscapingByref());
  b.setVal105(e.IsExceptionVariable());
  b.setVal106(e.IsExternC());
  b.setVal107(e.IsFileVariableDeclaration());
  b.setVal108(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal109(e.IsInExternCContext());
  b.setVal110(e.IsInExternCXXContext());
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
}

void SerializeParmVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto v126 = e.DefaultArgument();
  if (v126) {
    auto id126 = es.EntityId(v126.value());
    b.setVal126(id126);
  } else {
    b.setVal126(mx::kInvalidEntityId);
  }
  if (auto r127 = e.DefaultArgumentRange(); auto rs127 = r127.Size()) {
    b.setVal127(es.EntityId(r127[0]));
    b.setVal128(es.EntityId(r127[rs127 - 1u]));
  } else {
    b.setVal127(0);
    b.setVal128(0);
  }
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal130(es.EntityId(e.OriginalType()));
  auto v131 = e.UninstantiatedDefaultArgument();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  b.setVal132(e.HasDefaultArgument());
  b.setVal133(e.HasInheritedDefaultArgument());
  b.setVal134(e.HasUninstantiatedDefaultArgument());
  b.setVal135(e.HasUnparsedDefaultArgument());
  b.setVal136(e.IsDestroyedInCallee());
  b.setVal137(e.IsKNRPromoted());
  b.setVal138(e.IsObjCMethodParameter());
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
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  do {
    auto v51 = e.Bindings();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto et126 = es.EntityId(e.ExternToken());
  b.setVal126(et126);
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal127(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v51 = e.TemplateArguments();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  do {
    auto v61 = e.TemplateInstantiationArguments();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
    }
  } while (false);
  auto et128 = es.EntityId(e.TemplateKeywordToken());
  b.setVal128(et128);
  auto v130 = e.TypeAsWritten();
  if (v130) {
    auto id130 = es.EntityId(v130.value());
    b.setVal130(id130);
  } else {
    b.setVal130(mx::kInvalidEntityId);
  }
  b.setVal132(e.IsClassScopeExplicitSpecialization());
  b.setVal133(e.IsExplicitInstantiationOrSpecialization());
  b.setVal134(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(pf, es, b, e, nullptr);
  auto v131 = e.InstantiatedFromMember();
  if (v131) {
    auto id131 = es.EntityId(v131.value());
    b.setVal131(id131);
  } else {
    b.setVal131(mx::kInvalidEntityId);
  }
  b.setVal139(es.EntityId(e.TemplateParameters()));
  b.setVal135(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal76(e.DefaultArgumentWasInherited());
  auto v79 = e.DefaultArgument();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto et81 = es.EntityId(e.DefaultArgumentToken());
  b.setVal81(et81);
  auto v82 = e.PlaceholderTypeConstraint();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal77(e.HasDefaultArgument());
  b.setVal94(e.HasPlaceholderTypeConstraint());
  b.setVal95(e.IsExpandedParameterPack());
  b.setVal96(e.IsPackExpansion());
  do {
    auto v51 = e.ExpansionTypes();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
}

void SerializeMSPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal76(e.HasGetter());
  b.setVal77(e.HasSetter());
}

void SerializeFunctionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal76(e.BodyContainsImmediateEscalatingExpressions());
  b.setVal77(e.FriendConstraintRefersToEnclosingTemplate());
  b.setVal94(e.UsesFPIntrin());
  auto v95 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v95) {
    b.setVal95(static_cast<bool>(v95.value()));
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal97(e.DoesThisDeclarationHaveABody());
  b.setVal79(es.EntityId(e.CallResultType()));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal81(es.EntityId(e.DeclaredReturnType()));
  auto et82 = es.EntityId(e.DefaultToken());
  b.setVal82(et82);
  auto v83 = e.DescribedFunctionTemplate();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  auto et84 = es.EntityId(e.EllipsisToken());
  b.setVal84(et84);
  if (auto r86 = e.ExceptionSpecTokens(); auto rs86 = r86.Size()) {
    b.setVal86(es.EntityId(r86[0]));
    b.setVal91(es.EntityId(r86[rs86 - 1u]));
  } else {
    b.setVal86(0);
    b.setVal91(0);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v126 = e.InstantiatedFromDeclaration();
  if (v126) {
    auto id126 = es.EntityId(v126.value());
    b.setVal126(id126);
  } else {
    b.setVal126(mx::kInvalidEntityId);
  }
  auto v127 = e.InstantiatedFromMemberFunction();
  if (v127) {
    auto id127 = es.EntityId(v127.value());
    b.setVal127(id127);
  } else {
    b.setVal127(mx::kInvalidEntityId);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v140 = e.ODRHash();
  if (v140) {
    b.setVal140(static_cast<uint32_t>(v140.value()));
    b.setVal98(true);
  } else {
    b.setVal98(false);
  }
  b.setVal89(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r128 = e.ParametersTokens(); auto rs128 = r128.Size()) {
    b.setVal128(es.EntityId(r128[0]));
    b.setVal130(es.EntityId(r128[rs128 - 1u]));
  } else {
    b.setVal128(0);
    b.setVal130(0);
  }
  auto et131 = es.EntityId(e.PointOfInstantiation());
  b.setVal131(et131);
  auto v139 = e.PrimaryTemplate();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
  } else {
    b.setVal139(mx::kInvalidEntityId);
  }
  b.setVal141(es.EntityId(e.ReturnType()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v142 = e.TemplateInstantiationPattern();
  if (v142) {
    auto id142 = es.EntityId(v142.value());
    b.setVal142(id142);
  } else {
    b.setVal142(mx::kInvalidEntityId);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
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
  b.setVal120(e.IsImmediateEscalating());
  b.setVal121(e.IsImmediateFunction());
  b.setVal122(e.IsImplicitlyInstantiable());
  b.setVal123(e.IsInExternCContext());
  b.setVal124(e.IsInExternCXXContext());
  b.setVal125(e.IsIneligibleOrNotSelected());
  b.setVal132(e.IsInlineBuiltinDeclaration());
  auto v133 = e.IsInlineDefinitionExternallyVisible();
  if (v133) {
    b.setVal133(static_cast<bool>(v133.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  b.setVal135(e.IsInlineSpecified());
  b.setVal136(e.IsInlined());
  b.setVal137(e.IsLateTemplateParsed());
  auto v138 = e.IsMSExternInline();
  if (v138) {
    b.setVal138(static_cast<bool>(v138.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  b.setVal144(e.IsMSVCRTEntryPoint());
  b.setVal145(e.IsMain());
  b.setVal146(e.IsMemberLikeConstrainedFriend());
  b.setVal147(e.IsMultiVersion());
  b.setVal148(e.IsNoReturn());
  b.setVal149(e.IsOverloadedOperator());
  b.setVal150(e.IsPure());
  b.setVal151(e.IsReplaceableGlobalAllocationFunction());
  auto v152 = e.IsReservedGlobalPlacementOperator();
  if (v152) {
    b.setVal152(static_cast<bool>(v152.value()));
    b.setVal153(true);
  } else {
    b.setVal153(false);
  }
  b.setVal154(e.IsStatic());
  b.setVal155(e.IsTargetClonesMultiVersion());
  b.setVal156(e.IsTargetMultiVersion());
  b.setVal157(e.IsTemplateInstantiation());
  b.setVal158(e.IsThisDeclarationADefinition());
  b.setVal159(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal160(e.IsTrivial());
  b.setVal161(e.IsTrivialForCall());
  b.setVal162(e.IsUserProvided());
  b.setVal163(e.IsVariadic());
  b.setVal164(e.IsVirtualAsWritten());
  do {
    auto v51 = e.Parameters();
    auto sv51 = b.initVal51(static_cast<unsigned>(v51.size()));
    auto i51 = 0u;
    for (const auto &e51 : v51) {
      sv51.set(i51, es.EntityId(e51));
      ++i51;
    }
  } while (false);
  b.setVal165(e.UsesSEHTry());
  b.setVal166(e.WillHaveBody());
  auto v167 = e.Body();
  if (v167) {
    auto id167 = es.EntityId(v167.value());
    b.setVal167(id167);
  } else {
    b.setVal167(mx::kInvalidEntityId);
  }
  pasta::DeclContext dc61(e);
  auto v61 = dc61.AlreadyLoadedDeclarations();
  auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
  auto i61 = 0u;
  for (const pasta::Decl &e61 : v61) {
    sv61.set(i61, es.EntityId(e61));
    ++i61;
  }
}

void SerializeCXXMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal168(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v169 = e.ThisObjectType();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
  } else {
    b.setVal169(mx::kInvalidEntityId);
  }
  auto v170 = e.ThisType();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
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
    auto v179 = e.OverriddenMethods();
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v180 = e.OperatorDelete();
  if (v180) {
    auto id180 = es.EntityId(v180.value());
    b.setVal180(id180);
  } else {
    b.setVal180(mx::kInvalidEntityId);
  }
  auto v181 = e.OperatorDeleteThisArgument();
  if (v181) {
    auto id181 = es.EntityId(v181.value());
    b.setVal181(id181);
  } else {
    b.setVal181(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  b.setVal180(es.EntityId(e.ConversionType()));
  b.setVal182(e.IsExplicit());
  b.setVal183(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v180 = e.TargetConstructor();
  if (v180) {
    auto id180 = es.EntityId(v180.value());
    b.setVal180(id180);
  } else {
    b.setVal180(mx::kInvalidEntityId);
  }
  do {
    auto v184 = e.Initializers();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  b.setVal182(e.IsDefaultConstructor());
  b.setVal183(e.IsDelegatingConstructor());
  b.setVal185(e.IsExplicit());
  b.setVal186(e.IsInheritingConstructor());
  b.setVal187(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  auto v169 = e.CorrespondingConstructor();
  if (v169) {
    auto id169 = es.EntityId(v169.value());
    b.setVal169(id169);
  } else {
    b.setVal169(mx::kInvalidEntityId);
  }
  b.setVal170(es.EntityId(e.DeducedTemplate()));
  b.setVal168(static_cast<unsigned char>(mx::FromPasta(e.DeductionCandidateKind())));
  b.setVal171(e.IsExplicit());
}

void SerializeFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v79 = e.BitWidth();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v81 = e.CapturedVLAType();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v82 = e.InClassInitializer();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal76(e.HasCapturedVLAType());
  b.setVal77(e.HasInClassInitializer());
  b.setVal94(e.HasNonNullInClassInitializer());
  b.setVal95(e.IsAnonymousStructOrUnion());
  b.setVal96(e.IsBitField());
  b.setVal97(e.IsMutable());
  b.setVal98(e.IsPotentiallyOverlapping());
  b.setVal99(e.IsUnnamedBitfield());
  b.setVal100(e.IsZeroLengthBitField());
  b.setVal101(e.IsZeroSize());
  auto v83 = e.OffsetInBits();
  if (v83) {
    b.setVal83(static_cast<uint64_t>(v83.value()));
    b.setVal102(true);
  } else {
    b.setVal102(false);
  }
}

void SerializeObjCIvarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(pf, es, b, e, nullptr);
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal84(es.EntityId(e.ContainingInterface()));
  b.setVal86(es.EntityId(e.NextInstanceVariable()));
  b.setVal103(e.Synthesize());
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
  b.setVal57(es.EntityId(e.Binding()));
  b.setVal65(es.EntityId(e.DecomposedDeclaration()));
  b.setVal66(es.EntityId(e.HoldingVariable()));
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

void SerializeUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.Introducer()));
  auto v56 = e.NextUsingShadowDeclaration();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  b.setVal57(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(pf, es, b, e, nullptr);
  b.setVal74(e.ConstructsVirtualBase());
  b.setVal65(es.EntityId(e.ConstructedBaseClass()));
  auto v66 = e.ConstructedBaseClassShadowDeclaration();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
  } else {
    b.setVal66(mx::kInvalidEntityId);
  }
  b.setVal67(es.EntityId(e.NominatedBaseClass()));
  auto v78 = e.NominatedBaseClassShadowDeclaration();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v50 = e.Expansions();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal55(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et55 = es.EntityId(e.IdentifierToken());
  b.setVal55(et55);
  auto et56 = es.EntityId(e.NamespaceKeyToken());
  b.setVal56(et56);
  b.setVal57(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto et65 = es.EntityId(e.UsingToken());
  b.setVal65(et65);
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
  auto v55 = e.TypeForDeclaration();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  b.setVal74(e.DefaultArgumentWasInherited());
  auto v56 = e.DefaultArgument();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  auto v57 = e.DefaultArgumentInfo();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
  auto et65 = es.EntityId(e.DefaultArgumentToken());
  b.setVal65(et65);
  b.setVal75(e.HasDefaultArgument());
  b.setVal76(e.HasTypeConstraint());
  b.setVal77(e.IsExpandedParameterPack());
  b.setVal94(e.IsPackExpansion());
  b.setVal95(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  if (auto r56 = e.BraceRange(); auto rs56 = r56.Size()) {
    b.setVal56(es.EntityId(r56[0]));
    b.setVal57(es.EntityId(r56[rs56 - 1u]));
  } else {
    b.setVal56(0);
    b.setVal57(0);
  }
  auto et65 = es.EntityId(e.FirstInnerToken());
  b.setVal65(et65);
  auto et66 = es.EntityId(e.FirstOuterToken());
  b.setVal66(et66);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v67 = e.TypedefNameForAnonymousDeclaration();
  if (v67) {
    auto id67 = es.EntityId(v67.value());
    b.setVal67(id67);
  } else {
    b.setVal67(mx::kInvalidEntityId);
  }
  b.setVal74(e.HasNameForLinkage());
  b.setVal75(e.IsBeingDefined());
  b.setVal76(e.IsClass());
  b.setVal77(e.IsCompleteDefinition());
  b.setVal94(e.IsCompleteDefinitionRequired());
  b.setVal95(e.IsDependentType());
  b.setVal96(e.IsEnum());
  b.setVal97(e.IsFreeStanding());
  b.setVal98(e.IsInterface());
  b.setVal99(e.IsStruct());
  b.setVal100(e.IsThisDeclarationADefinition());
  b.setVal101(e.IsThisDeclarationADemotedDefinition());
  b.setVal102(e.IsUnion());
  b.setVal103(e.MayHaveOutOfDateDefinition());
  do {
    auto v50 = e.TemplateParameterLists();
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

void SerializeRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  b.setVal104(e.CanPassInRegisters());
  do {
    auto v61 = e.Fields();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
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
  auto v78 = e.Size();
  if (v78) {
    b.setVal78(static_cast<uint64_t>(v78.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  auto v79 = e.Alignment();
  if (v79) {
    b.setVal79(static_cast<uint64_t>(v79.value()));
    b.setVal125(true);
  } else {
    b.setVal125(false);
  }
  auto v81 = e.SizeWithoutTrailingPadding();
  if (v81) {
    b.setVal81(static_cast<uint64_t>(v81.value()));
    b.setVal132(true);
  } else {
    b.setVal132(false);
  }
}

void SerializeCXXRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(pf, es, b, e, nullptr);
  auto v133 = e.AllowConstDefaultInitializer();
  if (v133) {
    b.setVal133(static_cast<bool>(v133.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  do {
    auto ov179 = e.Bases();
    if (!ov179) {
      b.setVal135(false);
      break;
    }
    b.setVal135(true);
    auto v179 = std::move(*ov179);
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  auto v87 = e.CalculateInheritanceModel();
  if (v87) {
    b.setVal87(static_cast<unsigned char>(v87.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
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
    auto ov188 = e.Friends();
    if (!ov188) {
      b.setVal137(false);
      break;
    }
    b.setVal137(true);
    auto v188 = std::move(*ov188);
    auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
    auto i188 = 0u;
    for (const auto &e188 : v188) {
      sv188.set(i188, es.EntityId(e188));
      ++i188;
    }
  } while (false);
  auto v82 = e.DependentLambdaCallOperator();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v83 = e.DescribedClassTemplate();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  auto v84 = e.Destructor();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  auto v86 = e.GenericLambdaTemplateParameterList();
  if (v86) {
    auto id86 = es.EntityId(v86.value());
    b.setVal86(id86);
  } else {
    b.setVal86(mx::kInvalidEntityId);
  }
  auto v91 = e.InstantiatedFromMemberClass();
  if (v91) {
    auto id91 = es.EntityId(v91.value());
    b.setVal91(id91);
  } else {
    b.setVal91(mx::kInvalidEntityId);
  }
  auto v126 = e.LambdaCallOperator();
  if (v126) {
    auto id126 = es.EntityId(v126.value());
    b.setVal126(id126);
  } else {
    b.setVal126(mx::kInvalidEntityId);
  }
  auto v88 = e.LambdaCaptureDefault();
  if (v88) {
    b.setVal88(static_cast<unsigned char>(v88.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  auto v127 = e.LambdaContextDeclaration();
  if (v127) {
    auto id127 = es.EntityId(v127.value());
    b.setVal127(id127);
  } else {
    b.setVal127(mx::kInvalidEntityId);
  }
  do {
    auto ov189 = e.LambdaExplicitTemplateParameters();
    if (!ov189) {
      b.setVal143(false);
      break;
    }
    b.setVal143(true);
    auto v189 = std::move(*ov189);
    auto sv189 = b.initVal189(static_cast<unsigned>(v189.size()));
    auto i189 = 0u;
    for (const auto &e189 : v189) {
      sv189.set(i189, es.EntityId(e189));
      ++i189;
    }
  } while (false);
  auto v140 = e.LambdaManglingNumber();
  if (v140) {
    b.setVal140(static_cast<uint32_t>(v140.value()));
    b.setVal144(true);
  } else {
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
  auto v190 = e.ODRHash();
  if (v190) {
    b.setVal190(static_cast<uint32_t>(v190.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v128 = e.TemplateInstantiationPattern();
  if (v128) {
    auto id128 = es.EntityId(v128.value());
    b.setVal128(id128);
  } else {
    b.setVal128(mx::kInvalidEntityId);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v147 = e.HasAnyDependentBases();
  if (v147) {
    b.setVal147(static_cast<bool>(v147.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  auto v149 = e.HasConstexprDefaultConstructor();
  if (v149) {
    b.setVal149(static_cast<bool>(v149.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  auto v151 = e.HasConstexprDestructor();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v153 = e.HasConstexprNonCopyMoveConstructor();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasCopyAssignmentWithConstParameter();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
  }
  auto v157 = e.HasCopyConstructorWithConstParameter();
  if (v157) {
    b.setVal157(static_cast<bool>(v157.value()));
    b.setVal158(true);
  } else {
    b.setVal158(false);
  }
  auto v159 = e.HasDefaultConstructor();
  if (v159) {
    b.setVal159(static_cast<bool>(v159.value()));
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
  auto v171 = e.HasInClassInitializer();
  if (v171) {
    b.setVal171(static_cast<bool>(v171.value()));
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
  auto v177 = e.HasInitializerMethod();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v182 = e.HasIrrelevantDestructor();
  if (v182) {
    b.setVal182(static_cast<bool>(v182.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
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
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasMoveConstructor();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasMutableFields();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasNonLiteralTypeFieldsOrBases();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonTrivialCopyAssignment();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialCopyConstructor();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialCopyConstructorForCall();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialDefaultConstructor();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialDestructor();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialDestructorForCall();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasNonTrivialMoveAssignment();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasNonTrivialMoveConstructor();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasNonTrivialMoveConstructorForCall();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasPrivateFields();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasProtectedFields();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasSimpleCopyAssignment();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasSimpleCopyConstructor();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasSimpleDestructor();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasSimpleMoveAssignment();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasSimpleMoveConstructor();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasTrivialCopyAssignment();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialCopyConstructor();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialCopyConstructorForCall();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialDefaultConstructor();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialDestructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialDestructorForCall();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasTrivialMoveAssignment();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasTrivialMoveConstructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasTrivialMoveConstructorForCall();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasUninitializedReferenceMember();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUserDeclaredConstructor();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserDeclaredCopyAssignment();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUserDeclaredCopyConstructor();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredDestructor();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserDeclaredMoveAssignment();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasUserDeclaredMoveConstructor();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.HasUserDeclaredMoveOperation();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.HasUserProvidedDefaultConstructor();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.HasVariantMembers();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.ImplicitCopyConstructorHasConstParameter();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.IsAbstract();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsAggregate();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.IsAnyDestructorNoReturn();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  auto v278 = e.IsCLike();
  if (v278) {
    b.setVal278(static_cast<bool>(v278.value()));
    b.setVal279(true);
  } else {
    b.setVal279(false);
  }
  auto v280 = e.IsCXX11StandardLayout();
  if (v280) {
    b.setVal280(static_cast<bool>(v280.value()));
    b.setVal281(true);
  } else {
    b.setVal281(false);
  }
  b.setVal282(e.IsDependentLambda());
  auto v283 = e.IsDynamicClass();
  if (v283) {
    b.setVal283(static_cast<bool>(v283.value()));
    b.setVal284(true);
  } else {
    b.setVal284(false);
  }
  auto v285 = e.IsEffectivelyFinal();
  if (v285) {
    b.setVal285(static_cast<bool>(v285.value()));
    b.setVal286(true);
  } else {
    b.setVal286(false);
  }
  auto v287 = e.IsEmpty();
  if (v287) {
    b.setVal287(static_cast<bool>(v287.value()));
    b.setVal288(true);
  } else {
    b.setVal288(false);
  }
  b.setVal289(e.IsGenericLambda());
  auto v290 = e.IsInterfaceLike();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v292 = e.IsLiteral();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v130 = e.IsLocalClass();
  if (v130) {
    auto id130 = es.EntityId(v130.value());
    b.setVal130(id130);
  } else {
    b.setVal130(mx::kInvalidEntityId);
  }
  b.setVal294(e.IsNeverDependentLambda());
  auto v295 = e.IsPOD();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsPolymorphic();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsStandardLayout();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.IsStructural();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.IsTrivial();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.IsTriviallyCopyable();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  auto v309 = e.MayBeAbstract();
  if (v309) {
    b.setVal309(static_cast<bool>(v309.value()));
    b.setVal310(true);
  } else {
    b.setVal310(false);
  }
  auto v311 = e.MayBeDynamicClass();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.MayBeNonDynamicClass();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  do {
    auto ov315 = e.Methods();
    if (!ov315) {
      b.setVal316(false);
      break;
    }
    b.setVal316(true);
    auto v315 = std::move(*ov315);
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  auto v317 = e.NeedsImplicitCopyAssignment();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.NeedsImplicitCopyConstructor();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.NeedsImplicitDefaultConstructor();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.NeedsImplicitDestructor();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsImplicitMoveAssignment();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsImplicitMoveConstructor();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NeedsOverloadResolutionForDestructor();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.NullFieldOffsetIsZero();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
  do {
    auto ov341 = e.VirtualBases();
    if (!ov341) {
      b.setVal342(false);
      break;
    }
    b.setVal342(true);
    auto v341 = std::move(*ov341);
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
  auto v131 = e.SizeWithoutVirtualBases();
  if (v131) {
    b.setVal131(static_cast<uint64_t>(v131.value()));
    b.setVal343(true);
  } else {
    b.setVal343(false);
  }
  auto v139 = e.PrimaryBase();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
  } else {
    b.setVal139(mx::kInvalidEntityId);
  }
  auto v344 = e.HasOwnVirtualFunctionTablePointer();
  if (v344) {
    b.setVal344(static_cast<bool>(v344.value()));
    b.setVal345(true);
  } else {
    b.setVal345(false);
  }
  auto v346 = e.HasExtendableVirtualFunctionTablePointer();
  if (v346) {
    b.setVal346(static_cast<bool>(v346.value()));
    b.setVal347(true);
  } else {
    b.setVal347(false);
  }
  auto v348 = e.HasVirtualBaseTablePointer();
  if (v348) {
    b.setVal348(static_cast<bool>(v348.value()));
    b.setVal349(true);
  } else {
    b.setVal349(false);
  }
  auto v350 = e.HasOwnVirtualBaseTablePointer();
  if (v350) {
    b.setVal350(static_cast<bool>(v350.value()));
    b.setVal351(true);
  } else {
    b.setVal351(false);
  }
}

void SerializeClassTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(pf, es, b, e, nullptr);
  auto et141 = es.EntityId(e.ExternToken());
  b.setVal141(et141);
  auto et142 = es.EntityId(e.PointOfInstantiation());
  b.setVal142(et142);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal167(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v352 = e.TemplateArguments();
    auto sv352 = b.initVal352(static_cast<unsigned>(v352.size()));
    auto i352 = 0u;
    for (const auto &e352 : v352) {
      sv352.set(i352, es.EntityId(e352));
      ++i352;
    }
  } while (false);
  do {
    auto v353 = e.TemplateInstantiationArguments();
    auto sv353 = b.initVal353(static_cast<unsigned>(v353.size()));
    auto i353 = 0u;
    for (const auto &e353 : v353) {
      sv353.set(i353, es.EntityId(e353));
      ++i353;
    }
  } while (false);
  auto et169 = es.EntityId(e.TemplateKeywordToken());
  b.setVal169(et169);
  auto v170 = e.TypeAsWritten();
  if (v170) {
    auto id170 = es.EntityId(v170.value());
    b.setVal170(id170);
  } else {
    b.setVal170(mx::kInvalidEntityId);
  }
  b.setVal354(e.IsClassScopeExplicitSpecialization());
  b.setVal355(e.IsExplicitInstantiationOrSpecialization());
  b.setVal356(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal180(es.EntityId(e.InjectedSpecializationType()));
  auto v181 = e.InstantiatedFromMember();
  if (v181) {
    auto id181 = es.EntityId(v181.value());
    b.setVal181(id181);
  } else {
    b.setVal181(mx::kInvalidEntityId);
  }
  auto v357 = e.InstantiatedFromMemberTemplate();
  if (v357) {
    auto id357 = es.EntityId(v357.value());
    b.setVal357(id357);
  } else {
    b.setVal357(mx::kInvalidEntityId);
  }
  b.setVal358(es.EntityId(e.TemplateParameters()));
  b.setVal359(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  do {
    auto v61 = e.Enumerators();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
    }
  } while (false);
  auto v78 = e.InstantiatedFromMemberEnum();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
  }
  auto v79 = e.IntegerType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  if (auto r81 = e.IntegerTypeRange(); auto rs81 = r81.Size()) {
    b.setVal81(es.EntityId(r81[0]));
    b.setVal82(es.EntityId(r81[rs81 - 1u]));
  } else {
    b.setVal81(0);
    b.setVal82(0);
  }
  auto v140 = e.ODRHash();
  if (v140) {
    b.setVal140(static_cast<uint32_t>(v140.value()));
    b.setVal104(true);
  } else {
    b.setVal104(false);
  }
  auto v83 = e.PromotionType();
  if (v83) {
    auto id83 = es.EntityId(v83.value());
    b.setVal83(id83);
  } else {
    b.setVal83(mx::kInvalidEntityId);
  }
  auto v84 = e.TemplateInstantiationPattern();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal105(e.IsClosed());
  b.setVal106(e.IsClosedFlag());
  b.setVal107(e.IsClosedNonFlag());
  b.setVal108(e.IsComplete());
  b.setVal109(e.IsFixed());
  b.setVal110(e.IsScoped());
  b.setVal111(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto et56 = es.EntityId(e.EllipsisToken());
  b.setVal56(et56);
  auto et57 = es.EntityId(e.TypenameToken());
  b.setVal57(et57);
  auto et65 = es.EntityId(e.UsingToken());
  b.setVal65(et65);
  b.setVal74(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto v56 = e.AnonymousDeclarationWithTypedefName();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  b.setVal57(es.EntityId(e.UnderlyingType()));
  b.setVal74(e.IsModed());
  b.setVal75(e.IsTransparentTag());
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
  auto v65 = e.DescribedAliasTemplate();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
  auto et65 = es.EntityId(e.ColonToken());
  b.setVal65(et65);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto et66 = es.EntityId(e.VarianceToken());
  b.setVal66(et66);
  b.setVal76(e.HasExplicitBound());
}

void SerializeTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TemplateParameters()));
  auto v56 = e.TemplatedDeclaration();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  b.setVal74(e.HasAssociatedConstraints());
  b.setVal75(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  auto v57 = e.InstantiatedFromMemberTemplate();
  if (v57) {
    auto id57 = es.EntityId(v57.value());
    b.setVal57(id57);
  } else {
    b.setVal57(mx::kInvalidEntityId);
  }
  b.setVal76(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal77(e.IsAbbreviated());
  b.setVal94(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal77(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal77(e.IsThisDeclarationADefinition());
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
  b.setVal57(es.EntityId(e.ConstraintExpression()));
  b.setVal76(e.IsTypeConcept());
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
  b.setVal76(e.DefaultArgumentWasInherited());
  auto et57 = es.EntityId(e.DefaultArgumentToken());
  b.setVal57(et57);
  b.setVal77(e.HasDefaultArgument());
  b.setVal94(e.IsExpandedParameterPack());
  b.setVal95(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et55 = es.EntityId(e.AtToken());
  b.setVal55(et55);
  b.setVal56(es.EntityId(e.GetterMethodDeclaration()));
  auto et57 = es.EntityId(e.GetterNameToken());
  b.setVal57(et57);
  auto et65 = es.EntityId(e.LParenToken());
  b.setVal65(et65);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal66(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal67(es.EntityId(e.SetterMethodDeclaration()));
  auto et78 = es.EntityId(e.SetterNameToken());
  b.setVal78(et78);
  b.setVal79(es.EntityId(e.Type()));
  b.setVal74(e.IsAtomic());
  b.setVal75(e.IsClassProperty());
  b.setVal76(e.IsDirectProperty());
  b.setVal77(e.IsInstanceProperty());
  b.setVal94(e.IsOptional());
  b.setVal95(e.IsReadOnly());
  b.setVal96(e.IsRetaining());
}

void SerializeObjCMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal74(e.DefinedInNSObject());
  b.setVal55(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal56(es.EntityId(e.ClassInterface()));
  b.setVal57(es.EntityId(e.CommandDeclaration()));
  auto et65 = es.EntityId(e.DeclaratorEndToken());
  b.setVal65(et65);
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal66(es.EntityId(e.ReturnType()));
  if (auto r67 = e.ReturnTypeTokens(); auto rs67 = r67.Size()) {
    b.setVal67(es.EntityId(r67[0]));
    b.setVal78(es.EntityId(r67[rs67 - 1u]));
  } else {
    b.setVal67(0);
    b.setVal78(0);
  }
  auto et79 = es.EntityId(e.SelectorStartToken());
  b.setVal79(et79);
  b.setVal81(es.EntityId(e.SelfDeclaration()));
  b.setVal75(e.HasParameterDestroyedInCallee());
  b.setVal76(e.HasRedeclaration());
  b.setVal77(e.HasRelatedResultType());
  b.setVal94(e.HasSkippedBody());
  b.setVal95(e.IsClassMethod());
  b.setVal96(e.IsDefined());
  b.setVal97(e.IsDesignatedInitializerForTheInterface());
  b.setVal98(e.IsDirectMethod());
  b.setVal99(e.IsInstanceMethod());
  b.setVal100(e.IsOptional());
  b.setVal101(e.IsOverriding());
  b.setVal102(e.IsPropertyAccessor());
  b.setVal103(e.IsRedeclaration());
  b.setVal104(e.IsSynthesizedAccessorStub());
  b.setVal105(e.IsThisDeclarationADefinition());
  b.setVal106(e.IsThisDeclarationADesignatedInitializer());
  b.setVal107(e.IsVariadic());
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
  pasta::DeclContext dc61(e);
  auto v61 = dc61.AlreadyLoadedDeclarations();
  auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
  auto i61 = 0u;
  for (const pasta::Decl &e61 : v61) {
    sv61.set(i61, es.EntityId(e61));
    ++i61;
  }
}

void SerializeObjCContainerDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
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
  if (auto r55 = e.AtEndRange(); auto rs55 = r55.Size()) {
    b.setVal55(es.EntityId(r55[0]));
    b.setVal56(es.EntityId(r55[rs55 - 1u]));
  } else {
    b.setVal55(0);
    b.setVal56(0);
  }
  auto et57 = es.EntityId(e.AtStartToken());
  b.setVal57(et57);
  do {
    auto v61 = e.InstanceMethods();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
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
    auto v184 = e.Methods();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  do {
    auto v188 = e.Properties();
    auto sv188 = b.initVal188(static_cast<unsigned>(v188.size()));
    auto i188 = 0u;
    for (const auto &e188 : v188) {
      sv188.set(i188, es.EntityId(e188));
      ++i188;
    }
  } while (false);
  pasta::DeclContext dc189(e);
  auto v189 = dc189.AlreadyLoadedDeclarations();
  auto sv189 = b.initVal189(static_cast<unsigned>(v189.size()));
  auto i189 = 0u;
  for (const pasta::Decl &e189 : v189) {
    sv189.set(i189, es.EntityId(e189));
    ++i189;
  }
}

void SerializeObjCCategoryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal74(e.IsClassExtension());
  auto et65 = es.EntityId(e.CategoryNameToken());
  b.setVal65(et65);
  b.setVal66(es.EntityId(e.ClassInterface()));
  b.setVal67(es.EntityId(e.Implementation()));
  auto et78 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal78(et78);
  auto et79 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal79(et79);
  b.setVal81(es.EntityId(e.NextClassCategory()));
  do {
    auto v315 = e.InstanceVariables();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  do {
    auto v341 = e.ProtocolTokens();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
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

void SerializeObjCProtocolDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal74(e.HasDefinition());
  b.setVal75(e.IsNonRuntimeProtocol());
  b.setVal76(e.IsThisDeclarationADefinition());
  do {
    auto v315 = e.ProtocolTokens();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  do {
    auto v341 = e.Protocols();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
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
    auto v315 = e.AllReferencedProtocols();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
  b.setVal74(e.DeclaresOrInheritsDesignatedInitializers());
  auto et65 = es.EntityId(e.EndOfDefinitionToken());
  b.setVal65(et65);
  b.setVal66(es.EntityId(e.Implementation()));
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  auto v67 = e.SuperClass();
  if (v67) {
    auto id67 = es.EntityId(v67.value());
    b.setVal67(id67);
  } else {
    b.setVal67(mx::kInvalidEntityId);
  }
  auto et78 = es.EntityId(e.SuperClassToken());
  b.setVal78(et78);
  auto v79 = e.SuperClassTypeInfo();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  b.setVal81(es.EntityId(e.TypeForDeclaration()));
  b.setVal75(e.HasDefinition());
  b.setVal76(e.HasDesignatedInitializers());
  b.setVal77(e.IsArcWeakrefUnavailable());
  b.setVal94(e.IsImplicitInterfaceDeclaration());
  b.setVal82(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal95(e.IsThisDeclarationADefinition());
  do {
    auto v341 = e.InstanceVariables();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
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
  do {
    auto v362 = e.VisibleCategories();
    auto sv362 = b.initVal362(static_cast<unsigned>(v362.size()));
    auto i362 = 0u;
    for (const auto &e362 : v362) {
      sv362.set(i362, es.EntityId(e362));
      ++i362;
    }
  } while (false);
  do {
    auto v363 = e.VisibleExtensions();
    auto sv363 = b.initVal363(static_cast<unsigned>(v363.size()));
    auto i363 = 0u;
    for (const auto &e363 : v363) {
      sv363.set(i363, es.EntityId(e363));
      ++i363;
    }
  } while (false);
}

void SerializeObjCImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal65(es.EntityId(e.ClassInterface()));
  do {
    auto v315 = e.PropertyImplementations();
    auto sv315 = b.initVal315(static_cast<unsigned>(v315.size()));
    auto i315 = 0u;
    for (const auto &e315 : v315) {
      sv315.set(i315, es.EntityId(e315));
      ++i315;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  b.setVal66(es.EntityId(e.CategoryDeclaration()));
  auto et67 = es.EntityId(e.CategoryNameToken());
  b.setVal67(et67);
}

void SerializeObjCImplementationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  auto et66 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal66(et66);
  auto et67 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal67(et67);
  auto v73 = e.ObjCRuntimeNameAsString();
  std::string s73(v73.data(), v73.size());
  b.setVal73(s73);
  b.setVal78(es.EntityId(e.SuperClass()));
  auto et79 = es.EntityId(e.SuperClassToken());
  b.setVal79(et79);
  b.setVal74(e.HasDestructors());
  b.setVal75(e.HasNonZeroConstructors());
  do {
    auto v341 = e.Initializers();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
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

void SerializeObjCCompatibleAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal55(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeNamespaceAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et55 = es.EntityId(e.AliasToken());
  b.setVal55(et55);
  b.setVal56(es.EntityId(e.AliasedNamespace()));
  auto et57 = es.EntityId(e.NamespaceToken());
  b.setVal57(et57);
  auto et65 = es.EntityId(e.TargetNameToken());
  b.setVal65(et65);
}

void SerializeLinkageSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeLifetimeExtendedTemporaryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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
  b.setVal64(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal55(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
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

void SerializeImplicitConceptSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitConceptSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v50 = e.TemplateArguments();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal48(es.EntityId(e.FriendDeclaration()));
  auto et55 = es.EntityId(e.FriendToken());
  b.setVal55(et55);
  b.setVal56(es.EntityId(e.FriendType()));
  do {
    auto v50 = e.TemplateParameterLists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeFriendDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v48 = e.FriendDeclaration();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  auto et55 = es.EntityId(e.FriendToken());
  b.setVal55(et55);
  auto v56 = e.FriendType();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  b.setVal49(e.IsUnsupportedFriend());
  do {
    auto v50 = e.FriendTypeTemplateParameterLists();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et48 = es.EntityId(e.AssemblyToken());
  b.setVal48(et48);
  b.setVal55(es.EntityId(e.AssemblyString()));
  auto et56 = es.EntityId(e.RParenToken());
  b.setVal56(et56);
}

void SerializeExternCContextDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) pf;
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

void SerializeExportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et48 = es.EntityId(e.ExportToken());
  b.setVal48(et48);
  auto et55 = es.EntityId(e.RBraceToken());
  b.setVal55(et55);
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

void SerializeEmptyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

#pragma GCC diagnostic pop
}  // namespace indexer
