// Copyright (c) 2022-present, Trail of Bits, Inc.
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
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(e.IsBaseInitializer());
  b.setVal2(e.IsMemberInitializer());
  b.setVal3(e.IsAnyMemberInitializer());
  b.setVal4(e.IsIndirectMemberInitializer());
  b.setVal5(e.IsInClassMemberInitializer());
  b.setVal6(e.IsDelegatingInitializer());
  b.setVal7(e.IsPackExpansion());
  auto v8 = e.IsBaseVirtual();
  if (v8) {
    b.setVal8(static_cast<bool>(v8.value()));
    b.setVal9(true);
  } else {
    b.setVal9(false);
  }
  auto v10 = e.Member();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v11 = e.AnyMember();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v12 = e.IndirectMember();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v13 = e.Initializer();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto et14 = es.EntityId(e.EllipsisToken());
  b.setVal14(et14);
  auto et15 = es.EntityId(e.MemberToken());
  b.setVal15(et15);
  auto et16 = es.EntityId(e.LeftAngleToken());
  b.setVal16(et16);
  auto et17 = es.EntityId(e.RightAngleToken());
  b.setVal17(et17);
  auto p18 = es.EntityIds(e.Tokens());
  b.setVal18(p18.first);
  b.setVal19(p18.second);
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
  auto p6 = es.EntityIds(e.Tokens());
  b.setVal6(p6.first);
  b.setVal7(p6.second);
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
  if (auto v1 = es.BaseOffset(e)) {
    b.setVal2(true);
    b.setVal1(v1.value());
  } else {
    b.setVal2(false);
    b.setVal1(0u);
  }
  auto p4 = es.EntityIds(e.Tokens());
  b.setVal4(p4.first);
  b.setVal5(p4.second);
  auto et6 = es.EntityId(e.BaseTypeToken());
  b.setVal6(et6);
  auto v7 = e.EllipsisToken();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  b.setVal8(e.IsVirtual());
  b.setVal9(e.IsPackExpansion());
  b.setVal10(e.ConstructorsAreInherited());
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.BaseKind())));
  b.setVal12(static_cast<unsigned char>(mx::FromPasta(e.SemanticAccessSpecifier())));
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.LexicalAccessSpecifier())));
  b.setVal14(es.EntityId(e.BaseType()));
  auto v15 = e.BaseClass();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
  } else {
    b.setVal15(mx::kInvalidEntityId);
  }
}

void SerializeTemplateParameterList(const PendingFragment &pf, const EntityMapper &es, mx::ast::TemplateParameterList::Builder b, const pasta::TemplateParameterList &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(e.Depth());
  b.setVal2(e.HasUnexpandedParameterPack());
  b.setVal3(e.HasParameterPack());
  auto v4 = e.RequiresClause();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  auto et5 = es.EntityId(e.TemplateKeywordToken());
  b.setVal5(et5);
  auto et6 = es.EntityId(e.LeftAngleToken());
  b.setVal6(et6);
  auto et7 = es.EntityId(e.RightAngleToken());
  b.setVal7(et7);
  auto p8 = es.EntityIds(e.Tokens());
  b.setVal8(p8.first);
  b.setVal9(p8.second);
  do {
    auto v10 = e.Parameters();
    auto sv10 = b.initVal10(static_cast<unsigned>(v10.size()));
    auto i10 = 0u;
    for (const auto &e10 : v10) {
      sv10.set(i10, es.EntityId(e10));
      ++i10;
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
  auto v8 = e.Declaration();
  if (v8) {
    auto id8 = es.EntityId(v8.value());
    b.setVal8(id8);
  } else {
    b.setVal8(mx::kInvalidEntityId);
  }
  auto v9 = e.Type();
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
  auto v12 = e.Expression();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  do {
    auto v13 = e.PackArguments();
    auto sv13 = b.initVal13(static_cast<unsigned>(v13.size()));
    auto i13 = 0u;
    for (const auto &e13 : v13) {
      sv13.set(i13, es.EntityId(e13));
      ++i13;
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
  std::optional<pasta::MacroToken> v5;
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
  std::optional<pasta::MacroToken> v6;
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
  b.setVal14(e.IsBuiltin());
  b.setVal15(e.IsCommandLine());
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
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  auto et2 = es.EntityId(e.Token());
  b.setVal2(et2);
  b.setVal3(e.IsImplicit());
  b.setVal4(e.IsInherited());
  b.setVal5(e.IsLateParsed());
  b.setVal6(e.IsPackExpansion());
  b.setVal7(static_cast<unsigned short>(mx::FromPasta(e.Kind())));
  auto p8 = es.EntityIds(e.Tokens());
  b.setVal8(p8.first);
  b.setVal9(p8.second);
}

void SerializeAlignValueAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AlignValueAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Alignment()));
}

void SerializeAliasAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AliasAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  auto v11 = e.Aliasee();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AliaseeLength());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLLocalAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLLocalAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLGenericAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLGenericAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeOpenCLConstantAddressSpaceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OpenCLConstantAddressSpaceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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

void SerializeHLSLParamModifierAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLParamModifierAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
  b.setVal14(e.MergedSpelling());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsAnyIn());
  b.setVal16(e.IsAnyOut());
  b.setVal17(e.IsIn());
  b.setVal18(e.IsInOut());
  b.setVal19(e.IsOut());
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
  auto v11 = e.BTFTypeTag();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.BTFTypeTagLength());
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

void SerializeArmPreservesAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmPreservesAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmOutAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmOutAttr &e, const TokenTree *) {
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

void SerializeArmInOutAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmInOutAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeAttr(pf, es, b, e, nullptr);
}

void SerializeArmInAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmInAttr &e, const TokenTree *) {
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
  auto v11 = e.Annotation();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AnnotationLength());
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

void SerializeSwiftVersionedRemovalAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftVersionedRemovalAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal20(static_cast<unsigned short>(mx::FromPasta(e.AttributeKindToRemove())));
  b.setVal14(e.IsReplacedByActive());
  b.setVal12(e.RawKind());
}

void SerializeSwiftVersionedAdditionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftVersionedAdditionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.AdditionalAttribute()));
  b.setVal14(e.IsReplacedByActive());
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
  b.setVal12(e.UnrollHint());
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

void SerializeCodeAlignAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeAlignAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeStmtAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Alignment()));
}

void SerializeUnlikelyAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UnlikelyAttr &e, const TokenTree *) {
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal14(e.IsReadOnly());
  b.setVal15(e.IsReadWrite());
  b.setVal16(e.IsWriteOnly());
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
  auto v11 = e.MetadataName();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MetadataNameLength());
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
  b.setVal10(es.EntityId(e.Reference()));
}

void SerializeOMPDeclareSimdDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareSimdDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.BranchState())));
  b.setVal10(es.EntityId(e.Simdlen()));
}

void SerializeOMPCaptureKindAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPCaptureKindAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal12(e.CaptureKindValue());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Option())));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal22(static_cast<unsigned char>(mx::FromPasta(e.State())));
  auto v10 = e.Value();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
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
  auto v11 = e.Section();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.SectionLength());
}

void SerializeInheritableAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::InheritableAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAttr(pf, es, b, e, nullptr);
  b.setVal14(e.ShouldInheritEvenIfAlreadyPresent());
}

void SerializeIBOutletCollectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::IBOutletCollectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Interface()));
  b.setVal23(es.EntityId(e.InterfaceToken()));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeHLSLResourceBindingAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceBindingAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Slot();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.SlotLength());
  auto v24 = e.Space();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal25(e.SpaceLength());
}

void SerializeHLSLResourceAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLResourceAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal15(e.IsROV());
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
  b.setVal10(es.EntityId(e.Argument()));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ThunkType())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsSpelledAsSealed());
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
  auto v11 = e.DefinedIn();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.DefinedInLength());
  b.setVal15(e.GeneratedDeclaration());
  auto v24 = e.Language();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal25(e.LanguageLength());
  auto v26 = e.USR();
  std::string s26(v26.data(), v26.size());
  b.setVal26(s26);
  b.setVal27(e.USRLength());
}

void SerializeExclusiveTrylockFunctionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ExclusiveTrylockFunctionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.SuccessValue()));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  auto v11 = e.UserDiagnostic();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.UserDiagnosticLength());
  b.setVal15(e.IsError());
  b.setVal16(e.IsWarning());
}

void SerializeEnumExtensibilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnumExtensibilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Extensibility())));
}

void SerializeEnforceTCBLeafAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBLeafAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.TCBName();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.TCBNameLength());
}

void SerializeEnforceTCBAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnforceTCBAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.TCBName();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.TCBNameLength());
}

void SerializeEnableIfAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::EnableIfAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Condition()));
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
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
  b.setVal15(e.ArgumentDependent());
  b.setVal10(es.EntityId(e.Condition()));
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.DiagnosticType())));
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
  b.setVal23(es.EntityId(e.Parent()));
  b.setVal16(e.IsError());
  b.setVal17(e.IsWarning());
}

void SerializeDiagnoseAsBuiltinAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::DiagnoseAsBuiltinAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Function()));
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
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
  auto v24 = e.Replacement();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal25(e.ReplacementLength());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsClangAlwaysInline());
}

void SerializeSuppressAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SuppressAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclOrStmtAttr(pf, es, b, e, nullptr);
  b.setVal15(e.IsGSL());
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
  b.setVal15(e.IsClangNoInline());
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

void SerializeCountedByAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CountedByAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto p10 = es.EntityIds(e.CountedByFieldToken());
  b.setVal10(p10.first);
  b.setVal23(p10.second);
}

void SerializeCoroWrapperAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CoroWrapperAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCoroReturnTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CoroReturnTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCoroOnlyDestroyWhenCompleteAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CoroOnlyDestroyWhenCompleteAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCoroLifetimeBoundAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CoroLifetimeBoundAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeCoroDisableLifetimeBoundAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CoroDisableLifetimeBoundAttr &e, const TokenTree *) {
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.DefaultState())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsConstinit());
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
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializeCodeModelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::CodeModelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
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
  b.setVal10(es.EntityId(e.FunctionDeclaration()));
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
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsShared());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal10(es.EntityId(e.MaxBlocks()));
  b.setVal23(es.EntityId(e.MaxThreads()));
  b.setVal28(es.EntityId(e.MinBlocks()));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Guard())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Type())));
}

void SerializeBTFDeclTagAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BTFDeclTagAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.BTFDeclTag();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.BTFDeclTagLength());
}

void SerializeBPFPreserveStaticOffsetAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::BPFPreserveStaticOffsetAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
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
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
  auto v24 = e.Replacement();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal25(e.ReplacementLength());
  b.setVal15(e.Strict());
  b.setVal16(e.Unavailable());
}

void SerializeAssumptionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumptionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Assumption();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AssumptionLength());
}

void SerializeAssumeAlignedAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AssumeAlignedAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Alignment()));
  auto v23 = e.Offset();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsShared());
}

void SerializeAsmLabelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AsmLabelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal15(e.IsLiteralLabel());
  auto v11 = e.Label();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.LabelLength());
}

void SerializeArtificialAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArtificialAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeArmNewAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ArmNewAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal15(e.IsNewZA());
  b.setVal16(e.IsNewZT0());
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
  b.setVal15(e.IsPointer());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  auto v12 = e.Alignment();
  if (v12) {
    b.setVal12(static_cast<uint32_t>(v12.value()));
    b.setVal15(true);
  } else {
    b.setVal15(false);
  }
  auto v10 = e.AlignmentExpression();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v23 = e.AlignmentType();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
  }
  auto v25 = e.CachedAlignmentValue();
  if (v25) {
    b.setVal25(static_cast<uint32_t>(v25.value()));
    b.setVal16(true);
  } else {
    b.setVal16(false);
  }
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal17(e.IsAlignas());
  b.setVal18(e.IsAlignmentDependent());
  b.setVal19(e.IsAlignmentErrorDependent());
  b.setVal29(e.IsAlignmentExpression());
  b.setVal30(e.IsC11());
  b.setVal31(e.IsDeclspec());
  b.setVal32(e.IsGNU());
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
  auto v11 = e.HandleType();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.HandleTypeLength());
}

void SerializeAcquireCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AcquireCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsShared());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
}

void SerializeAMDGPUWavesPerEUAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUWavesPerEUAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Max()));
  b.setVal23(es.EntityId(e.Min()));
}

void SerializeAMDGPUNumVGPRAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumVGPRAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.NumVGPR());
}

void SerializeAMDGPUNumSGPRAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::AMDGPUNumSGPRAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.NumSGPR());
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
  b.setVal10(es.EntityId(e.Max()));
  b.setVal23(es.EntityId(e.Min()));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ZeroCallUsedRegs())));
}

void SerializeXRayLogArgsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayLogArgsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.ArgumentCount());
}

void SerializeXRayInstrumentAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::XRayInstrumentAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal15(e.AlwaysXRayInstrument());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal16(e.NeverXRayInstrument());
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
  b.setVal12(e.XDim());
  b.setVal25(e.YDim());
  b.setVal27(e.ZDim());
}

void SerializeWebAssemblyImportNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.ImportName();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.ImportNameLength());
}

void SerializeWebAssemblyImportModuleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyImportModuleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.ImportModule();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.ImportModuleLength());
}

void SerializeWebAssemblyExportNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WebAssemblyExportNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.ExportName();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.ExportNameLength());
}

void SerializeWeakRefAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::WeakRefAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Aliasee();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AliaseeLength());
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
  b.setVal15(e.IsCXX11NoDiscard());
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
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
  b.setVal10(es.EntityId(e.TypeHint()));
  b.setVal23(es.EntityId(e.TypeHintToken()));
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
  auto v11 = e.Guid();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal10(es.EntityId(e.GuidDeclaration()));
  b.setVal12(e.GuidLength());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ImplicitReason())));
  auto v11 = e.Message();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.MessageLength());
}

void SerializeTypeVisibilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeVisibilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
}

void SerializeTypeTagForDatatypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TypeTagForDatatypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal15(e.LayoutCompatible());
  b.setVal10(es.EntityId(e.MatchingCType()));
  b.setVal23(es.EntityId(e.MatchingCTypeToken()));
  b.setVal16(e.MustBeNull());
}

void SerializeTryAcquireCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TryAcquireCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal10(es.EntityId(e.SuccessValue()));
  b.setVal15(e.IsShared());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.TestState())));
}

void SerializeTargetVersionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TargetVersionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  auto v24 = e.NamesString();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal12(e.NamesStringLength());
  b.setVal15(e.IsDefaultVersion());
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
  auto v11 = e.Architecture();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  auto v24 = e.FeaturesString();
  std::string s24(v24.data(), v24.size());
  b.setVal24(s24);
  b.setVal12(e.FeaturesStringLength());
  b.setVal15(e.IsDefaultVersion());
}

void SerializeTLSModelAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::TLSModelAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Model();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.ModelLength());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.NewtypeKind())));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeSwiftNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializeSwiftImportPropertyAsAccessorsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftImportPropertyAsAccessorsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftImportAsNonGenericAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftImportAsNonGenericAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
}

void SerializeSwiftErrorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftErrorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
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
  auto v11 = e.SwiftType();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.SwiftTypeLength());
}

void SerializeSwiftAttrAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAttrAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Attribute();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AttributeLength());
}

void SerializeSwiftAsyncNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializeSwiftAsyncErrorAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SwiftAsyncErrorAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Convention())));
  b.setVal12(e.HandlerParameterIndex());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.AttributeKind())));
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
  b.setVal10(es.EntityId(e.SuccessValue()));
}

void SerializeSetTypestateAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::SetTypestateAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.NewState())));
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
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.State())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeRequiresCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::RequiresCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsShared());
}

void SerializeReqdWorkGroupSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReqdWorkGroupSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.XDim());
  b.setVal25(e.YDim());
  b.setVal27(e.ZDim());
}

void SerializeReleaseCapabilityAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseCapabilityAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsGeneric());
  b.setVal16(e.IsShared());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
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
  b.setVal10(es.EntityId(e.Argument()));
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

void SerializePreferredTypeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredTypeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Type()));
  b.setVal23(es.EntityId(e.TypeToken()));
}

void SerializePreferredNameAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PreferredNameAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.TypedefType()));
  b.setVal23(es.EntityId(e.TypedefTypeToken()));
}

void SerializePragmaClangTextSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangTextSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializePragmaClangRodataSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRodataSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializePragmaClangRelroSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangRelroSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializePragmaClangDataSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangDataSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializePragmaClangBSSSectionAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PragmaClangBSSSectionAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v11 = e.Name();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.NameLength());
}

void SerializePointerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PointerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v10 = e.DereferencedType();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v23 = e.DereferencedTypeToken();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
  }
}

void SerializePcsAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PcsAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.PCS())));
}

void SerializePatchableFunctionEntryAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PatchableFunctionEntryAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.Count());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ParameterState())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.OwnKind())));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsHolds());
  b.setVal16(e.IsReturns());
  b.setVal17(e.IsTakes());
}

void SerializeOwnerAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OwnerAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  auto v10 = e.DereferencedType();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto v23 = e.DereferencedTypeToken();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
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
  b.setVal12(e.SubGroupSize());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Family())));
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
  b.setVal10(es.EntityId(e.VariantFuncReference()));
}

void SerializeOMPDeclareTargetDeclAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::OMPDeclareTargetDeclAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.DevType())));
  b.setVal15(e.Indirect());
  b.setVal10(es.EntityId(e.IndirectExpression()));
  b.setVal12(e.Level());
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.MapType())));
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
  b.setVal10(es.EntityId(e.Alignment()));
  b.setVal23(es.EntityId(e.Allocator()));
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.AllocatorType())));
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
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
  b.setVal15(e.HasCoverage());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsLongCallAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsLongCallAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMipsInterruptAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MipsInterruptAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.Interrupt())));
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
  b.setVal12(e.VectorWidth());
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
  b.setVal12(e.Alignment());
}

void SerializeMSVtorDispAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSVtorDispAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
  b.setVal12(e.Vdm());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.VtorDispMode())));
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
  b.setVal12(e.Number());
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
  b.setVal15(e.BestCase());
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.InheritanceModel())));
  b.setVal21(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeMSConstexprAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::MSConstexprAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(pf, es, b, e, nullptr);
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

void SerializeM68kRTDAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::M68kRTDAttr &e, const TokenTree *) {
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
  b.setVal12(e.Number());
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
  b.setVal10(es.EntityId(e.Argument()));
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
  b.setVal12(e.Version());
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
  b.setVal12(e.Priority());
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
  auto v11 = e.Annotation();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.AnnotationLength());
}

void SerializeUseHandleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::UseHandleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  auto v11 = e.HandleType();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.HandleTypeLength());
}

void SerializeReleaseHandleAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ReleaseHandleAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  auto v11 = e.HandleType();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.HandleTypeLength());
}

void SerializePassObjectSizeAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::PassObjectSizeAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
  b.setVal15(e.IsDynamic());
}

void SerializeParameterABIAttr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::ParameterABIAttr &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableParamAttr(pf, es, b, e, nullptr);
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.ABI())));
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
  auto v11 = e.Resolver();
  std::string s11(v11.data(), v11.size());
  b.setVal11(s11);
  b.setVal12(e.ResolverLength());
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
  b.setVal13(static_cast<unsigned char>(mx::FromPasta(e.SemanticSpelling())));
}

void SerializeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::Type &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(e.RawQualifiers());
  b.setVal1(es.EntityId(e.DesugaredType()));
  b.setVal2(es.EntityId(e.CanonicalType()));
  b.setVal3(e.IsQualified());
  b.setVal4(es.EntityId(e.UnqualifiedType()));
  auto v5 = e.SizeInBits();
  if (v5) {
    b.setVal5(static_cast<uint64_t>(v5.value()));
    b.setVal6(true);
  } else {
    b.setVal6(false);
  }
  auto v7 = e.Alignment();
  if (v7) {
    b.setVal7(static_cast<uint64_t>(v7.value()));
    b.setVal8(true);
  } else {
    b.setVal8(false);
  }
  b.setVal9(e.AcceptsObjCTypeParameters());
  b.setVal10(e.CanDecayToPointerType());
  b.setVal11(e.CanHaveNullability());
  b.setVal12(e.ContainsErrors());
  b.setVal13(e.ContainsUnexpandedParameterPack());
  b.setVal14(static_cast<unsigned char>(mx::FromPasta(e.Linkage())));
  b.setVal15(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal16(es.EntityId(e.UnqualifiedDesugaredType()));
  b.setVal17(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal18(e.IsSizelessVectorType());
  b.setVal19(e.IsUnresolvedType());
}

void SerializeTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v20 = e.Declaration();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal21(e.Depth());
  b.setVal22(e.Index());
  b.setVal23(e.IsParameterPack());
  b.setVal24(e.IsSugared());
}

void SerializeTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v20 = e.AliasedType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsCurrentInstantiation());
  b.setVal24(e.IsSugared());
  b.setVal25(e.IsTypeAlias());
  do {
    auto v26 = e.TemplateArguments();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
}

void SerializeTagType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal23(e.IsBeingDefined());
}

void SerializeRecordType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal24(e.HasConstFields());
  b.setVal25(e.IsSugared());
}

void SerializeEnumType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(pf, es, b, e, nullptr);
  b.setVal24(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.AssociatedDeclaration()));
  b.setVal21(e.Index());
  auto v22 = e.PackIndex();
  if (v22) {
    b.setVal22(static_cast<uint32_t>(v22.value()));
    b.setVal23(true);
  } else {
    b.setVal23(false);
  }
  b.setVal27(es.EntityId(e.ReplacedParameter()));
  b.setVal28(es.EntityId(e.ReplacementType()));
  b.setVal24(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.AssociatedDeclaration()));
  b.setVal23(e.Final());
  b.setVal21(e.Index());
  b.setVal27(es.EntityId(e.ReplacedParameter()));
  b.setVal24(e.IsSugared());
}

void SerializeReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.PointeeType()));
  b.setVal27(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal23(e.IsInnerReference());
  b.setVal24(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal25(e.IsSugared());
}

void SerializeLValueReferenceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(pf, es, b, e, nullptr);
  b.setVal25(e.IsSugared());
}

void SerializeQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal20(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal23(e.HasAddressSpace());
  b.setVal24(e.HasNonTrivialObjCLifetime());
  b.setVal25(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal30(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal31(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal32(e.HasQualifiers());
  b.setVal33(e.HasStrongOrWeakObjCLifetime());
  b.setVal34(e.IsCForbiddenLValueType());
  b.setVal35(e.IsCXX11PODType());
  b.setVal36(e.IsCXX98PODType());
  b.setVal37(e.IsCanonical());
  b.setVal38(e.IsCanonicalAsParameter());
  b.setVal39(e.IsConstQualified());
  b.setVal40(e.IsConstant());
  b.setVal41(e.IsLocalConstQualified());
  b.setVal42(e.IsLocalRestrictQualified());
  b.setVal43(e.IsLocalVolatileQualified());
  b.setVal44(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal45(e.IsNull());
  b.setVal46(e.IsObjCGCStrong());
  b.setVal47(e.IsObjCGCWeak());
  b.setVal48(e.IsPODType());
  b.setVal49(e.IsReferenceable());
  b.setVal50(e.IsRestrictQualified());
  b.setVal51(e.IsTrivialType());
  b.setVal52(e.IsTriviallyCopyConstructibleType());
  b.setVal53(e.IsTriviallyCopyableType());
  b.setVal54(e.IsTriviallyEqualityComparableType());
  b.setVal55(e.IsTriviallyRelocatableType());
  b.setVal56(e.IsVolatileQualified());
  b.setVal57(e.IsWebAssemblyFuncrefType());
  b.setVal58(e.IsWebAssemblyReferenceType());
  b.setVal59(e.MayBeDynamicClass());
  b.setVal60(e.MayBeNotDynamicClass());
}

void SerializePointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.PointeeType()));
  b.setVal23(e.IsSugared());
}

void SerializePipeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal23(e.IsReadOnly());
  b.setVal24(e.IsSugared());
}

void SerializeParenType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.InnerType()));
  b.setVal23(e.IsSugared());
}

void SerializePackExpansionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Pattern()));
  b.setVal23(e.IsSugared());
}

void SerializeObjCTypeParamType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal23(e.IsSugared());
}

void SerializeObjCObjectType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.BaseType()));
  b.setVal27(es.EntityId(e.Interface()));
  auto v28 = e.SuperClassType();
  if (v28) {
    auto id28 = es.EntityId(v28.value());
    b.setVal28(id28);
  } else {
    b.setVal28(mx::kInvalidEntityId);
  }
  do {
    auto v26 = e.TypeArguments();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  do {
    auto v61 = e.TypeArgumentsAsWritten();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
    }
  } while (false);
  b.setVal23(e.IsKindOfType());
  b.setVal24(e.IsKindOfTypeAsWritten());
  b.setVal25(e.IsObjCClass());
  b.setVal30(e.IsObjCId());
  b.setVal31(e.IsObjCQualifiedClass());
  b.setVal32(e.IsObjCQualifiedId());
  b.setVal33(e.IsObjCUnqualifiedClass());
  b.setVal34(e.IsObjCUnqualifiedId());
  b.setVal35(e.IsObjCUnqualifiedIdOrClass());
  b.setVal36(e.IsSpecialized());
  b.setVal37(e.IsSpecializedAsWritten());
  b.setVal38(e.IsSugared());
  b.setVal39(e.IsUnspecialized());
  b.setVal40(e.IsUnspecializedAsWritten());
  b.setVal62(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(pf, es, b, e, nullptr);
  b.setVal63(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.InterfaceDeclaration()));
  b.setVal27(es.EntityId(e.InterfaceType()));
  b.setVal28(es.EntityId(e.ObjectType()));
  b.setVal62(es.EntityId(e.PointeeType()));
  b.setVal63(es.EntityId(e.SuperClassType()));
  do {
    auto v26 = e.TypeArguments();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  do {
    auto v61 = e.TypeArgumentsAsWritten();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
    }
  } while (false);
  b.setVal23(e.IsKindOfType());
  b.setVal24(e.IsObjCIdOrClassType());
  b.setVal25(e.IsSpecialized());
  b.setVal30(e.IsSpecializedAsWritten());
  b.setVal31(e.IsSugared());
  b.setVal32(e.IsUnspecialized());
  b.setVal33(e.IsUnspecializedAsWritten());
  do {
    auto v64 = e.Qualifiers();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      sv64.set(i64, es.EntityId(e64));
      ++i64;
    }
  } while (false);
  b.setVal65(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v66 = e.Protocols();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      sv66.set(i66, es.EntityId(e66));
      ++i66;
    }
  } while (false);
}

void SerializeMemberPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Class()));
  b.setVal27(es.EntityId(e.PointeeType()));
  b.setVal23(e.IsMemberDataPointer());
  b.setVal24(e.IsMemberFunctionPointer());
  b.setVal25(e.IsSugared());
}

void SerializeMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal23(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
  auto et27 = es.EntityId(e.AttributeToken());
  b.setVal27(et27);
  b.setVal28(es.EntityId(e.ColumnExpression()));
  b.setVal62(es.EntityId(e.RowExpression()));
}

void SerializeConstantMatrixType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantMatrixType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(pf, es, b, e, nullptr);
  b.setVal21(e.NumElementsFlattened());
}

void SerializeMacroQualifiedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MacroQualifiedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ModifiedType()));
  b.setVal27(es.EntityId(e.UnderlyingType()));
  b.setVal23(e.IsSugared());
}

void SerializeInjectedClassNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal27(es.EntityId(e.InjectedSpecializationType()));
  b.setVal28(es.EntityId(e.InjectedTST()));
  b.setVal23(e.IsSugared());
}

void SerializeFunctionType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal20(es.EntityId(e.CallResultType()));
  b.setVal23(e.CmseNSCallAttribute());
  b.setVal24(e.HasRegParm());
  b.setVal25(e.NoReturnAttribute());
  b.setVal21(e.RegParmType());
  b.setVal27(es.EntityId(e.ReturnType()));
  b.setVal30(e.IsConst());
  b.setVal31(e.IsRestrict());
  b.setVal32(e.IsVolatile());
}

void SerializeFunctionProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  auto v67 = e.CanThrow();
  if (v67) {
    b.setVal67(static_cast<unsigned char>(v67.value()));
    b.setVal33(true);
  } else {
    b.setVal33(false);
  }
  b.setVal22(e.AArch64SMEAttributes());
  auto et28 = es.EntityId(e.EllipsisToken());
  b.setVal28(et28);
  auto v62 = e.ExceptionSpecDeclaration();
  if (v62) {
    auto id62 = es.EntityId(v62.value());
    b.setVal62(id62);
  } else {
    b.setVal62(mx::kInvalidEntityId);
  }
  auto v63 = e.ExceptionSpecTemplate();
  if (v63) {
    auto id63 = es.EntityId(v63.value());
    b.setVal63(id63);
  } else {
    b.setVal63(mx::kInvalidEntityId);
  }
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v65 = e.NoexceptExpression();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
  do {
    auto v26 = e.ParameterTypes();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal34(e.HasDependentExceptionSpec());
  b.setVal35(e.HasDynamicExceptionSpec());
  b.setVal36(e.HasExceptionSpec());
  b.setVal37(e.HasExtParameterInfos());
  b.setVal38(e.HasInstantiationDependentExceptionSpec());
  b.setVal39(e.HasNoexceptExceptionSpec());
  b.setVal40(e.HasTrailingReturn());
  auto v41 = e.IsNothrow();
  if (v41) {
    b.setVal41(static_cast<bool>(v41.value()));
    b.setVal42(true);
  } else {
    b.setVal42(false);
  }
  b.setVal43(e.IsSugared());
  b.setVal44(e.IsTemplateVariadic());
  b.setVal45(e.IsVariadic());
  do {
    auto v61 = e.ExceptionTypes();
    auto sv61 = b.initVal61(static_cast<unsigned>(v61.size()));
    auto i61 = 0u;
    for (const auto &e61 : v61) {
      sv61.set(i61, es.EntityId(e61));
      ++i61;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(pf, es, b, e, nullptr);
  b.setVal33(e.IsSugared());
}

void SerializeDependentVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto et20 = es.EntityId(e.AttributeToken());
  b.setVal20(et20);
  b.setVal27(es.EntityId(e.ElementType()));
  b.setVal28(es.EntityId(e.SizeExpression()));
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal23(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto et20 = es.EntityId(e.AttributeToken());
  b.setVal20(et20);
  b.setVal27(es.EntityId(e.ElementType()));
  b.setVal28(es.EntityId(e.SizeExpression()));
  b.setVal23(e.IsSugared());
}

void SerializeDependentBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.NumBitsExpression()));
  b.setVal23(e.IsSigned());
  b.setVal24(e.IsSugared());
  b.setVal25(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.AddressSpaceExpression()));
  auto et27 = es.EntityId(e.AttributeToken());
  b.setVal27(et27);
  b.setVal28(es.EntityId(e.PointeeType()));
  b.setVal23(e.IsSugared());
}

void SerializeDeducedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v20 = e.ResolvedType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsDeduced());
  b.setVal24(e.IsSugared());
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
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v26 = e.TypeConstraintArguments();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
  auto v27 = e.TypeConstraintConcept();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  b.setVal25(e.IsConstrained());
  b.setVal30(e.IsDecltypeAuto());
  b.setVal31(e.IsGNUAutoType());
}

void SerializeDecltypeType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.UnderlyingExpression()));
  b.setVal27(es.EntityId(e.UnderlyingType()));
  b.setVal23(e.IsSugared());
}

void SerializeComplexType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal23(e.IsSugared());
}

void SerializeBuiltinType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal70(static_cast<unsigned short>(mx::FromPasta(e.BuiltinKind())));
  b.setVal23(e.IsFloatingPoint());
  b.setVal24(e.IsInteger());
  b.setVal25(e.IsSVEBool());
  b.setVal30(e.IsSVECount());
  b.setVal31(e.IsSignedInteger());
  b.setVal32(e.IsSugared());
  b.setVal33(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.PointeeType()));
  b.setVal23(e.IsSugared());
}

void SerializeBitIntType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal23(e.IsSigned());
  b.setVal24(e.IsSugared());
  b.setVal25(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Attribute()));
  b.setVal27(es.EntityId(e.WrappedType()));
  b.setVal23(e.IsSugared());
}

void SerializeAttributedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v20 = e.Attribute();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal70(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal27(es.EntityId(e.EquivalentType()));
  auto v29 = e.ImmediateNullability();
  if (v29) {
    b.setVal29(static_cast<unsigned char>(v29.value()));
    b.setVal23(true);
  } else {
    b.setVal23(false);
  }
  b.setVal28(es.EntityId(e.ModifiedType()));
  b.setVal24(e.HasAttribute());
  b.setVal25(e.IsCallingConv());
  b.setVal30(e.IsMSTypeSpec());
  b.setVal31(e.IsQualifier());
  b.setVal32(e.IsSugared());
  b.setVal33(e.IsWebAssemblyFuncrefSpec());
}

void SerializeAtomicType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ValueType()));
  b.setVal23(e.IsSugared());
}

void SerializeArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal21(e.IndexTypeCVRQualifiers());
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  auto p27 = es.EntityIds(e.BracketsRange());
  b.setVal27(p27.first);
  b.setVal28(p27.second);
  auto et62 = es.EntityId(e.LBracketToken());
  b.setVal62(et62);
  auto et63 = es.EntityId(e.RBracketToken());
  b.setVal63(et63);
  b.setVal65(es.EntityId(e.SizeExpression()));
  b.setVal23(e.IsSugared());
}

void SerializeIncompleteArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  b.setVal23(e.IsSugared());
}

void SerializeDependentSizedArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  auto p27 = es.EntityIds(e.BracketsRange());
  b.setVal27(p27.first);
  b.setVal28(p27.second);
  auto et62 = es.EntityId(e.LBracketToken());
  b.setVal62(et62);
  auto et63 = es.EntityId(e.RBracketToken());
  b.setVal63(et63);
  auto v65 = e.SizeExpression();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsSugared());
}

void SerializeConstantArrayType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(pf, es, b, e, nullptr);
  auto v27 = e.SizeExpression();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsSugared());
}

void SerializeAdjustedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ResolvedType()));
  b.setVal27(es.EntityId(e.OriginalType()));
  b.setVal23(e.IsSugared());
}

void SerializeDecayedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecayedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeAdjustedType(pf, es, b, e, nullptr);
  b.setVal28(es.EntityId(e.PointeeType()));
}

void SerializeTypeWithKeyword(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeWithKeyword &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.NamedType()));
  auto v27 = e.OwnedTagDeclaration();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal23(e.IsSugared());
  do {
    auto v26 = e.TemplateArguments();
    auto sv26 = b.initVal26(static_cast<unsigned>(v26.size()));
    auto i26 = 0u;
    for (const auto &e26 : v26) {
      sv26.set(i26, es.EntityId(e26));
      ++i26;
    }
  } while (false);
}

void SerializeDependentNameType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(pf, es, b, e, nullptr);
  b.setVal23(e.IsSugared());
}

void SerializeVectorType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.ElementType()));
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal23(e.IsSugared());
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
  b.setVal20(es.EntityId(e.FoundDeclaration()));
  b.setVal27(es.EntityId(e.UnderlyingType()));
  b.setVal23(e.IsSugared());
  b.setVal24(e.TypeMatchesDeclaration());
}

void SerializeUnresolvedUsingType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal23(e.IsSugared());
}

void SerializeUnaryTransformType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  auto v20 = e.BaseType();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  auto v27 = e.UnderlyingType();
  if (v27) {
    auto id27 = es.EntityId(v27.value());
    b.setVal27(id27);
  } else {
    b.setVal27(mx::kInvalidEntityId);
  }
  b.setVal23(e.IsSugared());
}

void SerializeTypedefType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal20(es.EntityId(e.Declaration()));
  b.setVal23(e.IsSugared());
  b.setVal24(e.TypeMatchesDeclaration());
}

void SerializeTypeOfType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal20(es.EntityId(e.UnmodifiedType()));
  b.setVal23(e.IsSugared());
}

void SerializeTypeOfExprType(const PendingFragment &pf, const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeType(pf, es, b, e, nullptr);
  b.setVal29(static_cast<unsigned char>(mx::FromPasta(e.TypeKind())));
  b.setVal20(es.EntityId(e.UnderlyingExpression()));
  b.setVal23(e.IsSugared());
}

void SerializeStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e, const TokenTree *) {
  (void) pf;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(es.IREntityId(e));
  if (auto r3 = ReferencedDecl(e)) {
    b.setVal3(es.EntityId(r3.value()));
  }
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
  auto p6 = es.EntityIds(e.Tokens());
  b.setVal6(p6.first);
  b.setVal7(p6.second);
  b.setVal8(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal9(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.ExceptHandler()));
  b.setVal11(es.EntityId(e.FinallyHandler()));
  b.setVal12(es.EntityId(e.Handler()));
  b.setVal13(e.IsCXXTry());
  b.setVal14(es.EntityId(e.TryBlock()));
  auto et15 = es.EntityId(e.TryToken());
  b.setVal15(et15);
}

void SerializeSEHLeaveStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.LeaveToken());
  b.setVal10(et10);
}

void SerializeSEHFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Block()));
  auto et11 = es.EntityId(e.FinallyToken());
  b.setVal11(et11);
}

void SerializeSEHExceptStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Block()));
  auto et11 = es.EntityId(e.ExceptToken());
  b.setVal11(et11);
  b.setVal12(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et12 = es.EntityId(e.ReturnToken());
  b.setVal12(et12);
}

void SerializeObjCForCollectionStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Collection()));
  b.setVal12(es.EntityId(e.Element()));
  auto et14 = es.EntityId(e.ForToken());
  b.setVal14(et14);
  auto et15 = es.EntityId(e.RParenToken());
  b.setVal15(et15);
}

void SerializeObjCAutoreleasePoolStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AtToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AtTryToken());
  b.setVal10(et10);
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

void SerializeObjCAtThrowStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.ThrowExpression()));
  auto et11 = es.EntityId(e.ThrowToken());
  b.setVal11(et11);
}

void SerializeObjCAtSynchronizedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AtSynchronizedToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.SynchBody()));
  b.setVal12(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AtFinallyToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.AtCatchToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.CatchBody()));
  b.setVal12(es.EntityId(e.CatchParameterDeclaration()));
  auto et14 = es.EntityId(e.RParenToken());
  b.setVal14(et14);
  b.setVal13(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.AssociatedStatement()));
  b.setVal11(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal12(es.EntityId(e.RawStatement()));
  b.setVal14(es.EntityId(e.StructuredBlock()));
  b.setVal13(e.HasAssociatedStatement());
  b.setVal17(e.IsStandaloneDirective());
}

void SerializeOMPErrorDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPErrorDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPDispatchDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  auto et15 = es.EntityId(e.TargetCallToken());
  b.setVal15(et15);
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
  b.setVal15(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal24(e.HasCancel());
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
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPSectionDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal24(e.HasCancel());
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
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal15(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPOrderedDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPExecutableDirective(pf, es, b, e, nullptr);
  b.setVal15(es.EntityId(e.IfStatement()));
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
  b.setVal27(e.LoopsNumber());
}

void SerializeOMPLoopTransformationDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPLoopTransformationDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopBasedDirective(pf, es, b, e, nullptr);
  b.setVal15(es.EntityId(e.PreInitializers()));
  b.setVal18(es.EntityId(e.TransformedStatement()));
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
    auto v16 = e.Counters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  do {
    auto v28 = e.DependentCounters();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
  do {
    auto v29 = e.DependentInitializers();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  do {
    auto v30 = e.Finals();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  do {
    auto v31 = e.FinalsConditions();
    auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
    auto i31 = 0u;
    for (const auto &e31 : v31) {
      sv31.set(i31, es.EntityId(e31));
      ++i31;
    }
  } while (false);
  b.setVal15(es.EntityId(e.Body()));
  b.setVal18(es.EntityId(e.CalculateLastIteration()));
  b.setVal19(es.EntityId(e.CombinedCondition()));
  b.setVal20(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal21(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal22(es.EntityId(e.CombinedInitializer()));
  b.setVal23(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal32(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal33(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal34(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal35(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal36(es.EntityId(e.Condition()));
  b.setVal37(es.EntityId(e.DistanceIncrement()));
  b.setVal38(es.EntityId(e.EnsureUpperBound()));
  b.setVal39(es.EntityId(e.Increment()));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal41(es.EntityId(e.IsLastIterationVariable()));
  b.setVal42(es.EntityId(e.IterationVariable()));
  b.setVal43(es.EntityId(e.LastIteration()));
  b.setVal44(es.EntityId(e.LowerBoundVariable()));
  b.setVal45(es.EntityId(e.NextLowerBound()));
  b.setVal46(es.EntityId(e.NextUpperBound()));
  b.setVal47(es.EntityId(e.PreCondition()));
  b.setVal48(es.EntityId(e.PreInitializers()));
  b.setVal49(es.EntityId(e.PrevEnsureUpperBound()));
  b.setVal50(es.EntityId(e.PrevLowerBoundVariable()));
  b.setVal51(es.EntityId(e.PrevUpperBoundVariable()));
  b.setVal52(es.EntityId(e.StrideVariable()));
  b.setVal53(es.EntityId(e.UpperBoundVariable()));
  do {
    auto v54 = e.Initializers();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v55 = e.PrivateCounters();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v56 = e.Updates();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal24(e.HasCancel());
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
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
  b.setVal24(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal24(e.HasCancel());
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
  b.setVal57(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal24(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal24(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  (void) pf;
  SerializeOMPLoopDirective(pf, es, b, e, nullptr);
  b.setVal24(e.HasCancel());
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
  b.setVal10(es.EntityId(e.DistanceFunc()));
  b.setVal11(es.EntityId(e.LoopStatement()));
  b.setVal12(es.EntityId(e.LoopVariableFunc()));
  b.setVal14(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.SemiToken());
  b.setVal10(et10);
  b.setVal13(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.KeywordToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsIfExists());
  b.setVal17(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto v10 = e.ConstantTarget();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  auto et11 = es.EntityId(e.GotoToken());
  b.setVal11(et11);
  auto et12 = es.EntityId(e.StarToken());
  b.setVal12(et12);
  b.setVal14(es.EntityId(e.Target()));
}

void SerializeIfStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et15 = es.EntityId(e.ElseToken());
  b.setVal15(et15);
  auto et18 = es.EntityId(e.IfToken());
  b.setVal18(et18);
  auto v19 = e.Initializer();
  if (v19) {
    auto id19 = es.EntityId(v19.value());
    b.setVal19(id19);
  } else {
    b.setVal19(mx::kInvalidEntityId);
  }
  auto et20 = es.EntityId(e.LParenToken());
  b.setVal20(et20);
  auto v21 = e.NondiscardedCase();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  auto et22 = es.EntityId(e.RParenToken());
  b.setVal22(et22);
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal23(es.EntityId(e.Then()));
  b.setVal13(e.HasElseStorage());
  b.setVal17(e.HasInitializerStorage());
  b.setVal24(e.HasVariableStorage());
  b.setVal25(e.IsConsteval());
  b.setVal26(e.IsConstexpr());
  b.setVal59(e.IsNegatedConsteval());
  b.setVal60(e.IsNonNegatedConsteval());
  b.setVal61(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.GotoToken());
  b.setVal10(et10);
  b.setVal11(es.EntityId(e.Label()));
  auto et12 = es.EntityId(e.LabelToken());
  b.setVal12(et12);
}

void SerializeForStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et15 = es.EntityId(e.ForToken());
  b.setVal15(et15);
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
  auto et20 = es.EntityId(e.LParenToken());
  b.setVal20(et20);
  auto et21 = es.EntityId(e.RParenToken());
  b.setVal21(et21);
}

void SerializeDoStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Body()));
  b.setVal11(es.EntityId(e.Condition()));
  auto et12 = es.EntityId(e.DoToken());
  b.setVal12(et12);
  auto et14 = es.EntityId(e.RParenToken());
  b.setVal14(et14);
  auto et15 = es.EntityId(e.WhileToken());
  b.setVal15(et15);
}

void SerializeDeclStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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

void SerializeCoroutineBodyStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  do {
    auto v16 = e.ChildrenExclBody();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal10(es.EntityId(e.Allocate()));
  b.setVal11(es.EntityId(e.Body()));
  b.setVal12(es.EntityId(e.Deallocate()));
  b.setVal14(es.EntityId(e.ExceptionHandler()));
  b.setVal15(es.EntityId(e.FallthroughHandler()));
  b.setVal18(es.EntityId(e.FinalSuspendStatement()));
  b.setVal19(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v28 = e.ParameterMoves();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
  b.setVal20(es.EntityId(e.PromiseDeclaration()));
  b.setVal21(es.EntityId(e.PromiseDeclarationStatement()));
  auto v22 = e.ResultDeclaration();
  if (v22) {
    auto id22 = es.EntityId(v22.value());
    b.setVal22(id22);
  } else {
    b.setVal22(mx::kInvalidEntityId);
  }
  b.setVal23(es.EntityId(e.ReturnStatement()));
  auto v32 = e.ReturnStatementOnAllocFailure();
  if (v32) {
    auto id32 = es.EntityId(v32.value());
    b.setVal32(id32);
  } else {
    b.setVal32(mx::kInvalidEntityId);
  }
  b.setVal33(es.EntityId(e.ReturnValue()));
  b.setVal34(es.EntityId(e.ReturnValueInitializer()));
  b.setVal13(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.KeywordToken());
  b.setVal10(et10);
  auto v11 = e.Operand();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  b.setVal12(es.EntityId(e.PromiseCall()));
  b.setVal13(e.IsImplicit());
}

void SerializeContinueStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.ContinueToken());
  b.setVal10(et10);
}

void SerializeCompoundStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.LeftBraceToken());
  b.setVal10(et10);
  auto et11 = es.EntityId(e.RightBraceToken());
  b.setVal11(et11);
  auto v12 = e.StatementExpressionResult();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal13(e.HasStoredFPFeatures());
  b.setVal27(e.Size());
}

void SerializeCapturedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.CapturedDeclaration()));
  b.setVal11(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal12(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal10(es.EntityId(e.TryBlock()));
  auto et11 = es.EntityId(e.TryToken());
  b.setVal11(et11);
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

void SerializeCXXForRangeStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto v10 = e.BeginStatement();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
  b.setVal11(es.EntityId(e.Body()));
  auto et12 = es.EntityId(e.CoawaitToken());
  b.setVal12(et12);
  auto et14 = es.EntityId(e.ColonToken());
  b.setVal14(et14);
  auto v15 = e.Condition();
  if (v15) {
    auto id15 = es.EntityId(v15.value());
    b.setVal15(id15);
  } else {
    b.setVal15(mx::kInvalidEntityId);
  }
  auto v18 = e.EndStatement();
  if (v18) {
    auto id18 = es.EntityId(v18.value());
    b.setVal18(id18);
  } else {
    b.setVal18(mx::kInvalidEntityId);
  }
  auto et19 = es.EntityId(e.ForToken());
  b.setVal19(et19);
  auto v20 = e.Increment();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  auto v21 = e.Initializer();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  b.setVal22(es.EntityId(e.LoopVariableStatement()));
  b.setVal23(es.EntityId(e.LoopVariable()));
  auto et32 = es.EntityId(e.RParenToken());
  b.setVal32(et32);
  b.setVal33(es.EntityId(e.RangeInitializer()));
  b.setVal34(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.CatchToken());
  b.setVal10(et10);
  auto v11 = e.CaughtType();
  if (v11) {
    auto id11 = es.EntityId(v11.value());
    b.setVal11(id11);
  } else {
    b.setVal11(mx::kInvalidEntityId);
  }
  auto v12 = e.ExceptionDeclaration();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal14(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.BreakToken());
  b.setVal10(et10);
}

void SerializeAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  b.setVal62(e.GenerateAssemblyString());
  auto et10 = es.EntityId(e.AssemblyToken());
  b.setVal10(et10);
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
    auto v28 = e.Outputs();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
  do {
    auto v63 = e.OutputConstraints();
    auto sv63 = b.initVal63(static_cast<unsigned>(v63.size()));
    auto i63 = 0u;
    for (const auto &e63 : v63) {
      std::string se63(e63.data(), e63.size());
      sv63.set(i63, se63);
      ++i63;
    }
  } while (false);
  do {
    auto v29 = e.OutputExpressions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  do {
    auto v64 = e.InputConstraints();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
    }
  } while (false);
  do {
    auto v30 = e.InputExpressions();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  do {
    auto v65 = e.Clobbers();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
    }
  } while (false);
}

void SerializeMSAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeAsmStmt(pf, es, b, e, nullptr);
  do {
    auto v66 = e.AllConstraints();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
  do {
    auto v31 = e.AllExpressions();
    auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
    auto i31 = 0u;
    for (const auto &e31 : v31) {
      sv31.set(i31, es.EntityId(e31));
      ++i31;
    }
  } while (false);
  auto v67 = e.AssemblyString();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  auto et11 = es.EntityId(e.LBraceToken());
  b.setVal11(et11);
  b.setVal24(e.HasBraces());
}

void SerializeGCCAsmStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e, const TokenTree *) {
  (void) pf;
  SerializeAsmStmt(pf, es, b, e, nullptr);
  b.setVal11(es.EntityId(e.AssemblyString()));
  auto et12 = es.EntityId(e.RParenToken());
  b.setVal12(et12);
  b.setVal24(e.IsAssemblyGoto());
  do {
    auto v31 = e.Labels();
    auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
    auto i31 = 0u;
    for (const auto &e31 : v31) {
      sv31.set(i31, es.EntityId(e31));
      ++i31;
    }
  } while (false);
  do {
    auto v54 = e.OutputConstraintLiterals();
    auto sv54 = b.initVal54(static_cast<unsigned>(v54.size()));
    auto i54 = 0u;
    for (const auto &e54 : v54) {
      sv54.set(i54, es.EntityId(e54));
      ++i54;
    }
  } while (false);
  do {
    auto v66 = e.OutputNames();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
  do {
    auto v55 = e.InputConstraintLiterals();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v68 = e.InputNames();
    auto sv68 = b.initVal68(static_cast<unsigned>(v68.size()));
    auto i68 = 0u;
    for (const auto &e68 : v68) {
      std::string se68(e68.data(), e68.size());
      sv68.set(i68, se68);
      ++i68;
    }
  } while (false);
  do {
    auto v56 = e.ClobberStringLiterals();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v69 = e.LabelExpressions();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      sv69.set(i69, es.EntityId(e69));
      ++i69;
    }
  } while (false);
  do {
    auto v70 = e.LabelNames();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      std::string se70(e70.data(), e70.size());
      sv70.set(i70, se70);
      ++i70;
    }
  } while (false);
}

void SerializeWhileStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et15 = es.EntityId(e.LParenToken());
  b.setVal15(et15);
  auto et18 = es.EntityId(e.RParenToken());
  b.setVal18(et18);
  auto et19 = es.EntityId(e.WhileToken());
  b.setVal19(et19);
  b.setVal13(e.HasVariableStorage());
}

void SerializeValueStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto v10 = e.ExpressionStatement();
  if (v10) {
    auto id10 = es.EntityId(v10.value());
    b.setVal10(id10);
  } else {
    b.setVal10(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
  b.setVal11(es.EntityId(e.Declaration()));
  auto et12 = es.EntityId(e.IdentifierToken());
  b.setVal12(et12);
  auto v62 = e.Name();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal14(es.EntityId(e.SubStatement()));
  b.setVal13(e.IsSideEntry());
}

void SerializeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
  b.setVal11(es.EntityId(e.IgnoreCasts()));
  b.setVal12(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal14(es.EntityId(e.IgnoreImplicitCasts()));
  b.setVal15(es.EntityId(e.IgnoreImplicit()));
  b.setVal18(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal19(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal20(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal21(es.EntityId(e.IgnoreParenthesisImplicitCasts()));
  b.setVal22(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  auto v23 = e.IgnoreParenthesisNoopCasts();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
  }
  b.setVal32(es.EntityId(e.IgnoreParentheses()));
  b.setVal33(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal13(e.ContainsErrors());
  b.setVal17(e.ContainsUnexpandedParameterPack());
  auto et34 = es.EntityId(e.ExpressionToken());
  b.setVal34(et34);
  auto v35 = e.ObjCProperty();
  if (v35) {
    auto id35 = es.EntityId(v35.value());
    b.setVal35(id35);
  } else {
    b.setVal35(mx::kInvalidEntityId);
  }
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
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
  b.setVal24(e.HasNonTrivialCall());
  b.setVal25(e.IsDefaultArgument());
  b.setVal26(e.IsGLValue());
  b.setVal59(e.IsImplicitCXXThis());
  b.setVal60(e.IsInstantiationDependent());
  b.setVal61(e.IsLValue());
  b.setVal72(e.IsOBJCGCCandidate());
  b.setVal73(e.IsObjCSelfExpression());
  b.setVal74(e.IsOrdinaryOrBitFieldObject());
  b.setVal75(e.IsPRValue());
  auto v76 = e.IsReadIfDiscardedInCPlusPlus11();
  if (v76) {
    b.setVal76(static_cast<bool>(v76.value()));
    b.setVal77(true);
  } else {
    b.setVal77(false);
  }
  b.setVal78(e.IsTypeDependent());
  b.setVal79(e.IsValueDependent());
  b.setVal80(e.IsXValue());
  b.setVal81(e.RefersToBitField());
  b.setVal82(e.RefersToGlobalRegisterVariable());
  b.setVal83(e.RefersToMatrixElement());
  b.setVal84(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.Designators();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto p39 = es.EntityIds(e.DesignatorsTokens());
  b.setVal39(p39.first);
  b.setVal40(p39.second);
  auto et41 = es.EntityId(e.EqualOrColonToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.Initializer()));
  b.setVal85(e.IsDirectInitializer());
  b.setVal27(e.Size());
  b.setVal86(e.UsesGNUSyntax());
  do {
    auto v28 = e.SubExpressions();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.LAngleToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RAngleToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.TemplateKeywordToken());
  b.setVal41(et41);
  b.setVal85(e.HasExplicitTemplateArguments());
  b.setVal86(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.KeywordToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Operand()));
  b.setVal41(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Declaration()));
  auto et40 = es.EntityId(e.LAngleToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RAngleToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.TemplateKeywordToken());
  b.setVal42(et42);
  b.setVal85(e.HadMultipleCandidates());
  b.setVal86(e.HasExplicitTemplateArguments());
  b.setVal87(e.HasQualifier());
  b.setVal88(e.IsCapturedByCopyInLambdaWithExplicitObjectParameter());
  b.setVal89(e.IsImmediateEscalating());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal91(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.CommonExpression()));
  auto et40 = es.EntityId(e.KeywordToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.OpaqueValue()));
  b.setVal42(es.EntityId(e.Operand()));
  b.setVal43(es.EntityId(e.ReadyExpression()));
  b.setVal44(es.EntityId(e.ResumeExpression()));
  b.setVal45(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
  b.setVal85(e.IsImplicit());
}

void SerializeCoyieldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCoroutineSuspendExpr(pf, es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.ConceptNameToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.FoundDeclaration()));
  b.setVal41(es.EntityId(e.NamedConcept()));
  b.setVal42(es.EntityId(e.SpecializationDeclaration()));
  do {
    auto v16 = e.TemplateArguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto et43 = es.EntityId(e.TemplateKeywordToken());
  b.setVal43(et43);
  b.setVal85(e.HasExplicitTemplateArguments());
}

void SerializeCompoundLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Initializer()));
  auto et40 = es.EntityId(e.LParenToken());
  b.setVal40(et40);
  b.setVal85(e.IsFileScope());
}

void SerializeChooseExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.ChosenSubExpression()));
  b.setVal41(es.EntityId(e.Condition()));
  b.setVal42(es.EntityId(e.LHS()));
  b.setVal43(es.EntityId(e.RHS()));
  auto et44 = es.EntityId(e.RParenToken());
  b.setVal44(et44);
  b.setVal85(e.IsConditionDependent());
  b.setVal86(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal27(e.Value());
}

void SerializeCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.ChangesVolatileQualification());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v62 = e.CastKindName();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
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
  b.setVal86(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal87(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCastExpr(pf, es, b, e, nullptr);
  b.setVal43(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto p44 = es.EntityIds(e.AngleBrackets());
  b.setVal44(p44.first);
  b.setVal45(p44.second);
  auto v67 = e.CastName();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  auto et46 = es.EntityId(e.OperatorToken());
  b.setVal46(et46);
  auto et47 = es.EntityId(e.RParenToken());
  b.setVal47(et47);
}

void SerializeCXXDynamicCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXNamedCastExpr(pf, es, b, e, nullptr);
  b.setVal87(e.IsAlwaysNull());
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
  auto et44 = es.EntityId(e.LParenToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.RParenToken());
  b.setVal45(et45);
  b.setVal87(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et44 = es.EntityId(e.LParenToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.RParenToken());
  b.setVal45(et45);
}

void SerializeBuiltinBitCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExplicitCastExpr(pf, es, b, e, nullptr);
  auto et44 = es.EntityId(e.BridgeKeywordToken());
  b.setVal44(et44);
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v67 = e.BridgeKindName();
  std::string s67(v67.data(), v67.size());
  b.setVal67(s67);
  auto et45 = es.EntityId(e.LParenToken());
  b.setVal45(et45);
}

void SerializeCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal27(e.BuiltinCallee());
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
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
  b.setVal85(e.HasStoredFPFeatures());
  b.setVal86(e.HasUnusedResultAttribute());
  b.setVal87(e.IsBuiltinAssumeFalse());
  b.setVal88(e.IsCallToStdMove());
  b.setVal89(e.IsUnevaluatedBuiltinCall());
  b.setVal91(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et44 = es.EntityId(e.OperatorToken());
  b.setVal44(et44);
  b.setVal93(e.IsAssignmentOperation());
  b.setVal94(e.IsComparisonOperation());
  b.setVal95(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
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

void SerializeCUDAKernelCallExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  b.setVal44(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeCallExpr(pf, es, b, e, nullptr);
  auto v44 = e.CookedLiteral();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto et45 = es.EntityId(e.UDSuffixToken());
  b.setVal45(et45);
}

void SerializeCXXUuidofExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.GuidDeclaration()));
  auto v41 = e.TypeOperand();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal85(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto et39 = es.EntityId(e.LParenToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.TypeAsWritten()));
  b.setVal85(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.ExpressionOperand();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.TypeOperand();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto v41 = e.TypeOperandSourceInfo();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v85 = e.IsMostDerived();
  if (v85) {
    b.setVal85(static_cast<bool>(v85.value()));
    b.setVal86(true);
  } else {
    b.setVal86(false);
  }
  b.setVal87(e.IsPotentiallyEvaluated());
  b.setVal88(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.SubExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto et40 = es.EntityId(e.ThrowToken());
  b.setVal40(et40);
  b.setVal85(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal85(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.RParenToken());
  b.setVal39(et39);
}

void SerializeCXXRewrittenBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v62 = e.OpcodeString();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto et40 = es.EntityId(e.OperatorToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal42(es.EntityId(e.SemanticForm()));
  b.setVal85(e.IsAssignmentOperation());
  b.setVal86(e.IsComparisonOperation());
  b.setVal87(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto et40 = es.EntityId(e.ColonColonToken());
  b.setVal40(et40);
  auto v41 = e.DestroyedType();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto et42 = es.EntityId(e.DestroyedTypeToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.OperatorToken());
  b.setVal43(et43);
  auto et44 = es.EntityId(e.TildeToken());
  b.setVal44(et44);
  b.setVal85(e.HasQualifier());
  b.setVal86(e.IsArrow());
}

void SerializeCXXParenListInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXParenListInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ArrayFiller()));
  auto et40 = es.EntityId(e.InitializerToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.InitializedFieldInUnion()));
}

void SerializeCXXNullPtrLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
}

void SerializeCXXNoexceptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal85(e.Value());
}

void SerializeCXXNewExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.DoesUsualArrayDeleteWantSize());
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
  auto p42 = es.EntityIds(e.DirectInitializerRange());
  b.setVal42(p42.first);
  b.setVal43(p42.second);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v44 = e.Initializer();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto v45 = e.OperatorDelete();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto v46 = e.OperatorNew();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  auto p47 = es.EntityIds(e.TypeIdParentheses());
  b.setVal47(p47.first);
  b.setVal48(p47.second);
  b.setVal86(e.HasInitializer());
  b.setVal87(e.IsArray());
  b.setVal88(e.IsGlobalNew());
  b.setVal89(e.IsParenthesisTypeId());
  b.setVal91(e.PassAlignment());
  do {
    auto v16 = e.PlacementArguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
}

void SerializeCXXInheritedCtorInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.ConstructsVirtualBase());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal39(es.EntityId(e.Constructor()));
  auto et40 = es.EntityId(e.Token());
  b.setVal40(et40);
  b.setVal86(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.Callee();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto et40 = es.EntityId(e.EllipsisToken());
  b.setVal40(et40);
  auto v41 = e.Initializer();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.LHS();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto et43 = es.EntityId(e.LParenToken());
  b.setVal43(et43);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal44(es.EntityId(e.Pattern()));
  auto v45 = e.RHS();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto et46 = es.EntityId(e.RParenToken());
  b.setVal46(et46);
  b.setVal85(e.IsLeftFold());
  b.setVal86(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  auto et42 = es.EntityId(e.LAngleToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.MemberToken());
  b.setVal43(et43);
  auto et44 = es.EntityId(e.OperatorToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.RAngleToken());
  b.setVal45(et45);
  auto et46 = es.EntityId(e.TemplateKeywordToken());
  b.setVal46(et46);
  b.setVal85(e.HasExplicitTemplateArguments());
  b.setVal86(e.HasTemplateKeyword());
  b.setVal87(e.IsArrow());
  b.setVal88(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.DoesUsualArrayDeleteWantSize());
  b.setVal39(es.EntityId(e.Argument()));
  auto v40 = e.DestroyedType();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto v41 = e.OperatorDelete();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal86(e.IsArrayForm());
  b.setVal87(e.IsArrayFormAsWritten());
  b.setVal88(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.Expression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal40(es.EntityId(e.Field()));
  b.setVal41(es.EntityId(e.RewrittenExpression()));
  auto et42 = es.EntityId(e.UsedToken());
  b.setVal42(et42);
  b.setVal85(e.HasRewrittenInitializer());
}

void SerializeCXXDefaultArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Expression()));
  b.setVal40(es.EntityId(e.Parameter()));
  auto v41 = e.RewrittenExpression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto et42 = es.EntityId(e.UsedToken());
  b.setVal42(et42);
  b.setVal85(e.HasRewrittenInitializer());
}

void SerializeCXXConstructExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.Arguments();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal39(es.EntityId(e.Constructor()));
  auto et40 = es.EntityId(e.Token());
  b.setVal40(et40);
  auto p41 = es.EntityIds(e.ParenthesisOrBraceRange());
  b.setVal41(p41.first);
  b.setVal42(p41.second);
  b.setVal85(e.HadMultipleCandidates());
  b.setVal86(e.IsElidable());
  b.setVal87(e.IsImmediateEscalating());
  b.setVal88(e.IsListInitialization());
  b.setVal89(e.IsStdInitializerListInitialization());
  b.setVal91(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  (void) pf;
  SerializeCXXConstructExpr(pf, es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal85(e.Value());
}

void SerializeCXXBindTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.BlockDeclaration()));
  b.setVal40(es.EntityId(e.Body()));
  auto et41 = es.EntityId(e.CaretToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.LHS()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v62 = e.OpcodeString();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  auto et40 = es.EntityId(e.OperatorToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.RHS()));
  b.setVal85(e.HasStoredFPFeatures());
  b.setVal86(e.IsAdditiveOperation());
  b.setVal87(e.IsAssignmentOperation());
  b.setVal88(e.IsBitwiseOperation());
  b.setVal89(e.IsCommaOperation());
  b.setVal91(e.IsComparisonOperation());
  b.setVal93(e.IsCompoundAssignmentOperation());
  b.setVal94(e.IsEqualityOperation());
  b.setVal95(e.IsLogicalOperation());
  b.setVal96(e.IsMultiplicativeOperation());
  b.setVal97(e.IsPointerMemoryOperation());
  b.setVal98(e.IsRelationalOperation());
  b.setVal99(e.IsShiftAssignOperation());
  b.setVal100(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  (void) pf;
  SerializeBinaryOperator(pf, es, b, e, nullptr);
  b.setVal42(es.EntityId(e.ComputationLHSType()));
  b.setVal43(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  auto v62 = e.OperationAsString();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal40(es.EntityId(e.Order()));
  auto v41 = e.OrderFail();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.Pointer()));
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
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
  b.setVal85(e.IsCmpXChg());
  b.setVal86(e.IsOpenCL());
  b.setVal87(e.IsVolatile());
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

void SerializeAsTypeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.DimensionExpression()));
  b.setVal40(es.EntityId(e.QueriedType()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal41(e.Value());
}

void SerializeArraySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  b.setVal41(es.EntityId(e.LHS()));
  auto et42 = es.EntityId(e.RBracketToken());
  b.setVal42(et42);
  b.setVal43(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.CommonExpression()));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AmpAmpToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Label()));
  auto et41 = es.EntityId(e.LabelToken());
  b.setVal41(et41);
}

void SerializeAbstractConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.ColonToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.FalseExpression()));
  auto et42 = es.EntityId(e.QuestionToken());
  b.setVal42(et42);
  b.setVal43(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal44(es.EntityId(e.LHS()));
  b.setVal45(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  (void) pf;
  SerializeAbstractConditionalOperator(pf, es, b, e, nullptr);
  b.setVal44(es.EntityId(e.Common()));
  b.setVal45(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal85(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.CanOverflow());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal86(e.HasStoredFPFeatures());
  b.setVal87(e.IsArithmeticOperation());
  b.setVal88(e.IsDecrementOperation());
  b.setVal89(e.IsIncrementDecrementOperation());
  b.setVal91(e.IsIncrementOperation());
  b.setVal93(e.IsPostfix());
  b.setVal94(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.KeywordKind())));
  auto et41 = es.EntityId(e.OperatorToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.RParenToken());
  b.setVal42(et42);
  b.setVal43(es.EntityId(e.TypeOfArgument()));
  b.setVal85(e.IsArgumentType());
}

void SerializeTypoExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v85 = e.Value();
  if (v85) {
    b.setVal85(static_cast<bool>(v85.value()));
    b.setVal86(true);
  } else {
    b.setVal86(false);
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

void SerializeSubstNonTypeTemplateParmPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AssociatedDeclaration()));
  b.setVal27(e.Index());
  b.setVal40(es.EntityId(e.ParameterPack()));
  auto et41 = es.EntityId(e.ParameterPackToken());
  b.setVal41(et41);
}

void SerializeSubstNonTypeTemplateParmExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AssociatedDeclaration()));
  b.setVal27(e.Index());
  auto et40 = es.EntityId(e.NameToken());
  b.setVal40(et40);
  auto v101 = e.PackIndex();
  if (v101) {
    b.setVal101(static_cast<uint32_t>(v101.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  b.setVal41(es.EntityId(e.Parameter()));
  b.setVal42(es.EntityId(e.ParameterType()));
  b.setVal43(es.EntityId(e.Replacement()));
  b.setVal86(e.IsReferenceParameter());
}

void SerializeStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v85 = e.ContainsNonAscii();
  if (v85) {
    b.setVal85(static_cast<bool>(v85.value()));
    b.setVal86(true);
  } else {
    b.setVal86(false);
  }
  auto v87 = e.ContainsNonAsciiOrNull();
  if (v87) {
    b.setVal87(static_cast<bool>(v87.value()));
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  b.setVal27(e.ByteLength());
  auto v62 = e.Bytes();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal101(e.CharacterByteWidth());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.LiteralKind())));
  b.setVal102(e.Length());
  b.setVal103(e.NumConcatenated());
  auto v67 = e.String();
  if (v67) {
    if (v67->empty()) {
      b.setVal67("");
    } else {
      std::string s67(v67->data(), v67->size());
      b.setVal67(s67);
    }
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal91(e.IsOrdinary());
  b.setVal93(e.IsPascal());
  b.setVal94(e.IsUTF16());
  b.setVal95(e.IsUTF32());
  b.setVal96(e.IsUTF8());
  b.setVal97(e.IsUnevaluated());
  b.setVal98(e.IsWide());
}

void SerializeStmtExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.LParenToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.SubStatement()));
  b.setVal27(e.TemplateDepth());
}

void SerializeSourceLocExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v62 = e.BuiltinString();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal85(e.IsIntType());
}

void SerializeSizeOfPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Pack()));
  auto v27 = e.PackLength();
  if (v27) {
    b.setVal27(static_cast<uint32_t>(v27.value()));
    b.setVal85(true);
  } else {
    b.setVal85(false);
  }
  auto et41 = es.EntityId(e.PackToken());
  b.setVal41(et41);
  do {
    auto ov16 = e.PartialArguments();
    if (!ov16) {
      b.setVal86(false);
      break;
    }
    b.setVal86(true);
    auto v16 = std::move(*ov16);
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto et42 = es.EntityId(e.RParenToken());
  b.setVal42(et42);
  b.setVal87(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.BuiltinToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
}

void SerializeSYCLUniqueStableNameExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal62(e.ComputeName());
  auto et39 = es.EntityId(e.LParenToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.Token());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
}

void SerializeRequiresExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Body()));
  auto et40 = es.EntityId(e.LParenToken());
  b.setVal40(et40);
  do {
    auto v16 = e.LocalParameters();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto et41 = es.EntityId(e.RBraceToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.RParenToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RequiresKeywordToken());
  b.setVal43(et43);
}

void SerializeRecoveryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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

void SerializePseudoObjectExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ResultExpression()));
  b.setVal27(e.ResultExpressionIndex());
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
    auto v28 = e.SemanticExpressions();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
}

void SerializePredefinedExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto v39 = e.FunctionName();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v62 = e.IdentifierKindName();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
  auto et40 = es.EntityId(e.Token());
  b.setVal40(et40);
  b.setVal85(e.IsTransparent());
}

void SerializeParenListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.LParenToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
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

void SerializeParenExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.LParenToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.EllipsisToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.Declarations();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto et39 = es.EntityId(e.LAngleToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.NameToken());
  b.setVal40(et40);
  auto v41 = e.NamingClass();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto et42 = es.EntityId(e.RAngleToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.TemplateKeywordToken());
  b.setVal43(et43);
  b.setVal85(e.HasExplicitTemplateArguments());
  b.setVal86(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal44(es.EntityId(e.BaseType()));
  auto et45 = es.EntityId(e.MemberToken());
  b.setVal45(et45);
  auto et46 = es.EntityId(e.OperatorToken());
  b.setVal46(et46);
  b.setVal87(e.HasUnresolvedUsing());
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  (void) pf;
  SerializeOverloadExpr(pf, es, b, e, nullptr);
  b.setVal87(e.IsOverloaded());
  b.setVal88(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  auto v40 = e.SourceExpression();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal85(e.IsUnique());
}

void SerializeOffsetOfExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.OperatorToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
}

void SerializeObjCSubscriptRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal40(es.EntityId(e.BaseExpression()));
  b.setVal41(es.EntityId(e.KeyExpression()));
  auto et42 = es.EntityId(e.RBracketToken());
  b.setVal42(et42);
  b.setVal85(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AtToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AtToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.RParenToken());
  b.setVal40(et40);
}

void SerializeObjCProtocolExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AtToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Protocol()));
  auto et41 = es.EntityId(e.ProtocolIdToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.RParenToken());
  b.setVal42(et42);
}

void SerializeObjCPropertyRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.ClassReceiver()));
  b.setVal41(es.EntityId(e.ExplicitProperty()));
  b.setVal42(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal43(es.EntityId(e.ImplicitPropertySetter()));
  auto et44 = es.EntityId(e.Token());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.ReceiverToken());
  b.setVal45(et45);
  b.setVal46(es.EntityId(e.ReceiverType()));
  b.setVal47(es.EntityId(e.SuperReceiverType()));
  b.setVal85(e.IsClassReceiver());
  b.setVal86(e.IsExplicitProperty());
  b.setVal87(e.IsImplicitProperty());
  b.setVal88(e.IsMessagingGetter());
  b.setVal89(e.IsMessagingSetter());
  b.setVal91(e.IsObjectReceiver());
  b.setVal93(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  b.setVal41(es.EntityId(e.InstanceReceiver()));
  auto et42 = es.EntityId(e.LeftToken());
  b.setVal42(et42);
  b.setVal43(es.EntityId(e.MethodDeclaration()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal44(es.EntityId(e.ReceiverInterface()));
  b.setVal92(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  auto p45 = es.EntityIds(e.ReceiverRange());
  b.setVal45(p45.first);
  b.setVal46(p45.second);
  b.setVal47(es.EntityId(e.ReceiverType()));
  auto et48 = es.EntityId(e.RightToken());
  b.setVal48(et48);
  auto et49 = es.EntityId(e.SelectorStartToken());
  b.setVal49(et49);
  auto et50 = es.EntityId(e.SuperToken());
  b.setVal50(et50);
  b.setVal51(es.EntityId(e.SuperType()));
  b.setVal85(e.IsClassMessage());
  b.setVal86(e.IsDelegateInitializerCall());
  b.setVal87(e.IsImplicit());
  b.setVal88(e.IsInstanceMessage());
  do {
    auto v28 = e.SelectorTokens();
    auto sv28 = b.initVal28(static_cast<unsigned>(v28.size()));
    auto i28 = 0u;
    for (const auto &e28 : v28) {
      sv28.set(i28, es.EntityId(e28));
      ++i28;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Declaration()));
  auto et41 = es.EntityId(e.Token());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.OperationToken());
  b.setVal42(et42);
  b.setVal85(e.IsArrow());
  b.setVal86(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto et40 = es.EntityId(e.BaseTokenEnd());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.IsaMemberToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.OperationToken());
  b.setVal42(et42);
  b.setVal85(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal85(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AtToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.EncodedType()));
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
}

void SerializeObjCDictionaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.AtToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.BoxingMethod()));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal85(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal85(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.HasVersion());
}

void SerializeObjCArrayLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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

void SerializeOMPIteratorExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.IteratorKwToken());
  b.setVal39(et39);
  auto et40 = es.EntityId(e.LParenToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
}

void SerializeOMPArrayShapingExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  auto et40 = es.EntityId(e.LParenToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.RParenToken());
  b.setVal41(et41);
}

void SerializeOMPArraySectionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto et40 = es.EntityId(e.FirstColonToken());
  b.setVal40(et40);
  auto et41 = es.EntityId(e.SecondColonToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.Length()));
  b.setVal43(es.EntityId(e.LowerBound()));
  auto et44 = es.EntityId(e.RBracketToken());
  b.setVal44(et44);
  b.setVal45(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeMemberExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  auto et40 = es.EntityId(e.LAngleToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.MemberDeclaration()));
  auto et42 = es.EntityId(e.MemberToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.OperatorToken());
  b.setVal43(et43);
  auto et44 = es.EntityId(e.RAngleToken());
  b.setVal44(et44);
  auto et45 = es.EntityId(e.TemplateKeywordToken());
  b.setVal45(et45);
  b.setVal85(e.HadMultipleCandidates());
  b.setVal86(e.HasExplicitTemplateArguments());
  b.setVal87(e.HasQualifier());
  b.setVal88(e.HasTemplateKeyword());
  b.setVal89(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.ColumnIndex()));
  auto et41 = es.EntityId(e.RBracketToken());
  b.setVal41(et41);
  b.setVal42(es.EntityId(e.RowIndex()));
  b.setVal85(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  b.setVal27(e.ManglingNumber());
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal85(e.IsBoundToLvalueReference());
  b.setVal86(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Base()));
  b.setVal40(es.EntityId(e.Index()));
  auto et41 = es.EntityId(e.RBracketToken());
  b.setVal41(et41);
}

void SerializeMSPropertyRefExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.BaseExpression()));
  auto et40 = es.EntityId(e.MemberToken());
  b.setVal40(et40);
  b.setVal41(es.EntityId(e.PropertyDeclaration()));
  b.setVal85(e.IsArrow());
  b.setVal86(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.Body()));
  b.setVal40(es.EntityId(e.CallOperator()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto et41 = es.EntityId(e.CaptureDefaultToken());
  b.setVal41(et41);
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
  auto p44 = es.EntityIds(e.IntroducerRange());
  b.setVal44(p44.first);
  b.setVal45(p44.second);
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
  b.setVal85(e.HasExplicitParameters());
  b.setVal86(e.HasExplicitResultType());
  b.setVal87(e.IsGenericLambda());
  b.setVal88(e.IsMutable());
}

void SerializeIntegerLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
}

void SerializeInitListExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
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
  auto et41 = es.EntityId(e.LBraceToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.RBraceToken());
  b.setVal42(et42);
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
  b.setVal85(e.HadArrayRangeDesignator());
  b.setVal86(e.HasArrayFiller());
  b.setVal87(e.HasDesignatedInitializer());
  do {
    auto v16 = e.Initializers();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  b.setVal88(e.IsExplicit());
  b.setVal89(e.IsSemanticForm());
  b.setVal91(e.IsStringLiteralInitializer());
  b.setVal93(e.IsSyntacticForm());
  auto v94 = e.IsTransparent();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
}

void SerializeImplicitValueInitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  do {
    auto v16 = e.AssociationExpressions();
    auto sv16 = b.initVal16(static_cast<unsigned>(v16.size()));
    auto i16 = 0u;
    for (const auto &e16 : v16) {
      sv16.set(i16, es.EntityId(e16));
      ++i16;
    }
  } while (false);
  auto v39 = e.ControllingExpression();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.ControllingType();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  auto et41 = es.EntityId(e.DefaultToken());
  b.setVal41(et41);
  auto et42 = es.EntityId(e.GenericToken());
  b.setVal42(et42);
  auto et43 = es.EntityId(e.RParenToken());
  b.setVal43(et43);
  auto v44 = e.ResultExpression();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal27(e.ResultIndex());
  b.setVal85(e.IsExpressionPredicate());
  b.setVal86(e.IsResultDependent());
  b.setVal87(e.IsTypePredicate());
}

void SerializeGNUNullExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.TokenToken());
  b.setVal39(et39);
}

void SerializeFunctionParmPackExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.ParameterPack()));
  auto et40 = es.EntityId(e.ParameterPackToken());
  b.setVal40(et40);
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

void SerializeFullExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  (void) pf;
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal85(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  (void) pf;
  SerializeFullExpr(pf, es, b, e, nullptr);
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal85(e.HasAPValueResult());
  b.setVal86(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal85(e.IsExact());
}

void SerializeFixedPointLiteral(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  auto et39 = es.EntityId(e.Token());
  b.setVal39(et39);
  b.setVal27(e.Scale());
}

void SerializeExtVectorElementExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal85(e.ContainsDuplicateElements());
  auto et39 = es.EntityId(e.AccessorToken());
  b.setVal39(et39);
  b.setVal40(es.EntityId(e.Base()));
  b.setVal86(e.IsArrow());
}

void SerializeExpressionTraitExpr(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  (void) pf;
  SerializeExpr(pf, es, b, e, nullptr);
  b.setVal39(es.EntityId(e.QueriedExpression()));
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal85(e.Value());
}

void SerializeAttributedStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
  (void) pf;
  SerializeValueStmt(pf, es, b, e, nullptr);
  auto et11 = es.EntityId(e.AttributeToken());
  b.setVal11(et11);
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

void SerializeSwitchStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
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
  auto et18 = es.EntityId(e.LParenToken());
  b.setVal18(et18);
  auto et19 = es.EntityId(e.RParenToken());
  b.setVal19(et19);
  auto v20 = e.FirstSwitchCase();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
  auto et21 = es.EntityId(e.SwitchToken());
  b.setVal21(et21);
  b.setVal13(e.HasInitializerStorage());
  b.setVal17(e.HasVariableStorage());
  b.setVal24(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e, const TokenTree *) {
  (void) pf;
  SerializeStmt(pf, es, b, e, nullptr);
  auto et10 = es.EntityId(e.ColonToken());
  b.setVal10(et10);
  auto et11 = es.EntityId(e.KeywordToken());
  b.setVal11(et11);
  auto v12 = e.NextSwitchCase();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal14(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e, const TokenTree *) {
  (void) pf;
  SerializeSwitchCase(pf, es, b, e, nullptr);
  auto et15 = es.EntityId(e.DefaultToken());
  b.setVal15(et15);
}

void SerializeCaseStmt(const PendingFragment &pf, const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
  (void) pf;
  SerializeSwitchCase(pf, es, b, e, nullptr);
  b.setVal13(e.CaseStatementIsGNURange());
  auto et15 = es.EntityId(e.CaseToken());
  b.setVal15(et15);
  auto et18 = es.EntityId(e.EllipsisToken());
  b.setVal18(et18);
  b.setVal19(es.EntityId(e.LHS()));
  auto v20 = e.RHS();
  if (v20) {
    auto id20 = es.EntityId(v20.value());
    b.setVal20(id20);
  } else {
    b.setVal20(mx::kInvalidEntityId);
  }
}

void SerializeDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::Decl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  b.setVal0(es.ParentDeclId(e));
  b.setVal1(es.ParentStmtId(e));
  b.setVal2(es.IREntityId(e));
  b.setVal3(IsDefinition(e));
  do {
    auto v4 = e.Attributes();
    auto sv4 = b.initVal4(static_cast<unsigned>(v4.size()));
    auto i4 = 0u;
    for (const auto &e4 : v4) {
      sv4.set(i4, es.EntityId(e4));
      ++i4;
    }
  } while (false);
  b.setVal5(static_cast<unsigned char>(mx::FromPasta(e.Availability())));
  auto v6 = e.DefiningAttribute();
  if (v6) {
    auto id6 = es.EntityId(v6.value());
    b.setVal6(id6);
  } else {
    b.setVal6(mx::kInvalidEntityId);
  }
  auto v7 = e.ExternalSourceSymbolAttribute();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  b.setVal8(static_cast<unsigned char>(mx::FromPasta(e.FriendObjectKind())));
  auto v9 = e.MaxAlignment();
  if (v9) {
    b.setVal9(static_cast<uint32_t>(v9.value()));
    b.setVal10(true);
  } else {
    b.setVal10(false);
  }
  b.setVal11(static_cast<unsigned char>(mx::FromPasta(e.ModuleOwnershipKind())));
  auto v12 = e.NonClosureContext();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal13(e.OwningModuleID());
  b.setVal14(e.TemplateDepth());
  b.setVal15(e.IsDeprecated());
  b.setVal16(e.IsFileContextDeclaration());
  b.setVal17(e.IsFunctionOrFunctionTemplate());
  b.setVal18(e.IsImplicit());
  b.setVal19(e.IsInAnonymousNamespace());
  b.setVal20(e.IsInAnotherModuleUnit());
  b.setVal21(e.IsInExportDeclarationContext());
  b.setVal22(e.IsInStdNamespace());
  b.setVal23(e.IsInvisibleOutsideTheOwningModule());
  b.setVal24(e.IsLocalExternDeclaration());
  b.setVal25(e.IsModulePrivate());
  b.setVal26(e.IsOutOfLine());
  b.setVal27(e.IsParameterPack());
  b.setVal28(e.IsTemplateDeclaration());
  b.setVal29(e.IsTemplateParameter());
  b.setVal30(e.IsTemplateParameterPack());
  b.setVal31(e.IsTemplated());
  b.setVal32(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal33(e.IsUnavailable());
  b.setVal34(e.IsUnconditionallyVisible());
  b.setVal35(e.IsWeakImported());
  b.setVal36(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal37(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto et38 = pf.DeclTokenEntityId(e);
  b.setVal38(et38);
  auto p39 = es.EntityIds(e.Tokens());
  b.setVal39(p39.first);
  b.setVal40(p39.second);
}

void SerializeCapturedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ContextParameter()));
  b.setVal42(e.ContextParameterPosition());
  b.setVal43(e.IsNothrow());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeBlockDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal43(e.BlockMissingReturnType());
  b.setVal46(e.CanAvoidCopyToHeap());
  b.setVal47(e.CapturesCXXThis());
  b.setVal48(e.DoesNotEscape());
  auto v41 = e.BlockManglingContextDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(e.BlockManglingNumber());
  auto et49 = es.EntityId(e.CaretToken());
  b.setVal49(et49);
  b.setVal50(es.EntityId(e.CompoundBody()));
  b.setVal51(es.EntityId(e.SignatureAsWritten()));
  b.setVal52(e.HasCaptures());
  b.setVal53(e.IsConversionFromLambda());
  b.setVal54(e.IsVariadic());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.ParameterDeclarations();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeAccessSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et41 = es.EntityId(e.AccessSpecifierToken());
  b.setVal41(et41);
  auto et49 = es.EntityId(e.ColonToken());
  b.setVal49(et49);
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
    auto v44 = e.Varlists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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
    auto v44 = e.Varlists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
}

void SerializeTopLevelStmtDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Statement()));
  b.setVal43(e.IsSemiMissing());
}

void SerializeStaticAssertDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.AssertExpression()));
  auto v49 = e.Message();
  if (v49) {
    auto id49 = es.EntityId(v49.value());
    b.setVal49(id49);
  } else {
    b.setVal49(mx::kInvalidEntityId);
  }
  auto et50 = es.EntityId(e.RParenToken());
  b.setVal50(et50);
  b.setVal43(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

void SerializePragmaDetectMismatchDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v56 = e.Name();
  std::string s56(v56.data(), v56.size());
  b.setVal56(s56);
  auto v57 = e.Value();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
}

void SerializePragmaCommentDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v56 = e.Argument();
  std::string s56(v56.data(), v56.size());
  b.setVal56(s56);
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.GetterCXXConstructor()));
  b.setVal49(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal50(es.EntityId(e.PropertyDeclaration()));
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal51(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto et59 = es.EntityId(e.PropertyInstanceVariableDeclarationToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.SetterCXXAssignment()));
  b.setVal61(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal43(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal56(Name(e));
  auto v62 = e.ObjCFStringFormattingFamily();
  if (v62) {
    b.setVal62(static_cast<unsigned char>(v62.value()));
    b.setVal43(true);
  } else {
    b.setVal43(false);
  }
  b.setVal41(es.EntityId(e.UnderlyingDeclaration()));
  auto v63 = e.Visibility();
  if (v63) {
    b.setVal63(static_cast<unsigned char>(v63.value()));
    b.setVal46(true);
  } else {
    b.setVal46(false);
  }
  b.setVal47(e.HasExternalFormalLinkage());
  b.setVal48(e.HasLinkage());
  b.setVal52(e.HasLinkageBeenComputed());
  b.setVal53(e.IsCXXClassMember());
  b.setVal54(e.IsCXXInstanceMember());
  b.setVal64(e.IsExternallyDeclarable());
  b.setVal65(e.IsExternallyVisible());
  b.setVal66(e.IsLinkageValid());
}

void SerializeLabelDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v57 = e.MSAssemblyLabel();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  b.setVal49(es.EntityId(e.Statement()));
  b.setVal67(e.IsGnuLocal());
  b.setVal68(e.IsMSAssemblyLabel());
  b.setVal69(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.LBraceToken());
  b.setVal49(et49);
  auto et50 = es.EntityId(e.TokenStart());
  b.setVal50(et50);
  auto et51 = es.EntityId(e.RBraceToken());
  b.setVal51(et51);
  b.setVal67(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v44 = e.Shadows();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeUsingEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  b.setVal49(es.EntityId(e.EnumDeclaration()));
  auto et50 = es.EntityId(e.EnumToken());
  b.setVal50(et50);
  b.setVal51(es.EntityId(e.EnumType()));
  auto et59 = es.EntityId(e.UsingToken());
  b.setVal59(et59);
}

void SerializeUsingDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.UsingToken());
  b.setVal49(et49);
  b.setVal67(e.HasTypename());
  b.setVal68(e.IsAccessDeclaration());
}

void SerializeValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto v49 = e.PotentiallyDecomposedVariableDeclaration();
  if (v49) {
    auto id49 = es.EntityId(v49.value());
    b.setVal49(id49);
  } else {
    b.setVal49(mx::kInvalidEntityId);
  }
  b.setVal50(es.EntityId(e.Type()));
  b.setVal67(e.IsInitializerCapture());
  b.setVal68(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et51 = es.EntityId(e.EllipsisToken());
  b.setVal51(et51);
  auto et59 = es.EntityId(e.UsingToken());
  b.setVal59(et59);
  b.setVal69(e.IsAccessDeclaration());
  b.setVal70(e.IsPackExpansion());
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
  b.setVal51(es.EntityId(e.Combiner()));
  b.setVal59(es.EntityId(e.CombinerIn()));
  b.setVal60(es.EntityId(e.CombinerOut()));
  b.setVal61(es.EntityId(e.InitializerOriginal()));
  b.setVal71(es.EntityId(e.InitializerPrivate()));
  b.setVal72(es.EntityId(e.Initializer()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
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
    auto v44 = e.Chain();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  auto v51 = e.AnonymousField();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
  b.setVal42(e.ChainingSize());
  auto v59 = e.VariableDeclaration();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto v51 = e.InitializerExpression();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(pf, es, b, e, nullptr);
  auto et51 = es.EntityId(e.FirstInnerToken());
  b.setVal51(et51);
  auto et59 = es.EntityId(e.FirstOuterToken());
  b.setVal59(et59);
  auto v60 = e.TrailingRequiresClause();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  auto et61 = es.EntityId(e.TypeSpecEndToken());
  b.setVal61(et61);
  auto et71 = es.EntityId(e.TypeSpecStartToken());
  b.setVal71(et71);
  do {
    auto v44 = e.TemplateParameterLists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v72 = e.ActingDefinition();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v74 = e.DescribedVariableTemplate();
  if (v74) {
    auto id74 = es.EntityId(v74.value());
    b.setVal74(id74);
  } else {
    b.setVal74(mx::kInvalidEntityId);
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
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  b.setVal69(e.HasConstantInitialization());
  b.setVal70(e.HasDependentAlignment());
  b.setVal82(e.HasExternalStorage());
  auto v83 = e.HasFlexibleArrayInitializer();
  if (v83) {
    b.setVal83(static_cast<bool>(v83.value()));
    b.setVal84(true);
  } else {
    b.setVal84(false);
  }
  b.setVal85(e.HasGlobalStorage());
  b.setVal86(e.HasInitializer());
  b.setVal87(e.HasLocalStorage());
  b.setVal88(e.IsARCPseudoStrong());
  b.setVal89(e.IsCXXForRangeDeclaration());
  b.setVal90(e.IsConstexpr());
  b.setVal91(e.IsDirectInitializer());
  b.setVal92(e.IsEscapingByref());
  b.setVal93(e.IsExceptionVariable());
  b.setVal94(e.IsExternC());
  b.setVal95(e.IsFileVariableDeclaration());
  b.setVal96(e.IsFunctionOrMethodVariableDeclaration());
  b.setVal97(e.IsInExternCContext());
  b.setVal98(e.IsInExternCXXContext());
  b.setVal99(e.IsInline());
  b.setVal100(e.IsInlineSpecified());
  b.setVal101(e.IsKnownToBeDefined());
  b.setVal102(e.IsLocalVariableDeclaration());
  b.setVal103(e.IsLocalVariableDeclarationOrParm());
  b.setVal104(e.IsNRVOVariable());
  b.setVal105(e.IsNoDestroy());
  b.setVal106(e.IsNonEscapingByref());
  b.setVal107(e.IsObjCForDeclaration());
  b.setVal108(e.IsPreviousDeclarationInSameBlockScope());
  b.setVal109(e.IsStaticDataMember());
  b.setVal110(e.IsStaticLocal());
  b.setVal111(e.IsThisDeclarationADemotedDefinition());
  b.setVal112(e.IsUsableInConstantExpressions());
  b.setVal113(e.MightBeUsableInConstantExpressions());
}

void SerializeParmVarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto v114 = e.DefaultArgument();
  if (v114) {
    auto id114 = es.EntityId(v114.value());
    b.setVal114(id114);
  } else {
    b.setVal114(mx::kInvalidEntityId);
  }
  auto p115 = es.EntityIds(e.DefaultArgumentRange());
  b.setVal115(p115.first);
  b.setVal116(p115.second);
  auto et117 = es.EntityId(e.ExplicitObjectParameterThisToken());
  b.setVal117(et117);
  b.setVal42(e.FunctionScopeDepth());
  b.setVal118(e.FunctionScopeIndex());
  b.setVal119(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal120(es.EntityId(e.OriginalType()));
  auto v121 = e.UninstantiatedDefaultArgument();
  if (v121) {
    auto id121 = es.EntityId(v121.value());
    b.setVal121(id121);
  } else {
    b.setVal121(mx::kInvalidEntityId);
  }
  b.setVal122(e.HasDefaultArgument());
  b.setVal123(e.HasInheritedDefaultArgument());
  b.setVal124(e.HasUninstantiatedDefaultArgument());
  b.setVal125(e.HasUnparsedDefaultArgument());
  b.setVal126(e.IsDestroyedInCallee());
  b.setVal127(e.IsExplicitObjectParameter());
  b.setVal128(e.IsKNRPromoted());
  b.setVal129(e.IsObjCMethodParameter());
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
  b.setVal119(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  do {
    auto v45 = e.Bindings();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(pf, es, b, e, nullptr);
  auto et114 = es.EntityId(e.ExternToken());
  b.setVal114(et114);
  b.setVal119(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal115(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v45 = e.TemplateArguments();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  auto et116 = es.EntityId(e.TemplateKeywordToken());
  b.setVal116(et116);
  b.setVal122(e.IsClassScopeExplicitSpecialization());
  b.setVal123(e.IsExplicitInstantiationOrSpecialization());
  b.setVal124(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal117(es.EntityId(e.TemplateParameters()));
  b.setVal125(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal69(e.DefaultArgumentWasInherited());
  auto v72 = e.DefaultArgument();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto et74 = es.EntityId(e.DefaultArgumentToken());
  b.setVal74(et74);
  auto v75 = e.PlaceholderTypeConstraint();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal70(e.HasDefaultArgument());
  b.setVal82(e.HasPlaceholderTypeConstraint());
  b.setVal83(e.IsExpandedParameterPack());
  b.setVal84(e.IsPackExpansion());
  do {
    auto v45 = e.ExpansionTypes();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeMSPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal69(e.HasGetter());
  b.setVal70(e.HasSetter());
}

void SerializeFunctionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  b.setVal69(e.BodyContainsImmediateEscalatingExpressions());
  b.setVal70(e.FriendConstraintRefersToEnclosingTemplate());
  b.setVal82(e.UsesFPIntrin());
  auto v83 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v83) {
    b.setVal83(static_cast<bool>(v83.value()));
    b.setVal84(true);
  } else {
    b.setVal84(false);
  }
  b.setVal85(e.DoesThisDeclarationHaveABody());
  b.setVal42(e.BuiltinID());
  b.setVal72(es.EntityId(e.CallResultType()));
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal74(es.EntityId(e.DeclaredReturnType()));
  auto et75 = es.EntityId(e.DefaultToken());
  b.setVal75(et75);
  auto v76 = e.DescribedFunctionTemplate();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto et114 = es.EntityId(e.EllipsisToken());
  b.setVal114(et114);
  auto p115 = es.EntityIds(e.ExceptionSpecTokens());
  b.setVal115(p115.first);
  b.setVal116(p115.second);
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal118(e.MemoryFunctionKind());
  b.setVal130(e.MinRequiredArguments());
  b.setVal131(e.MinRequiredExplicitArguments());
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  b.setVal80(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  auto p117 = es.EntityIds(e.ParametersTokens());
  b.setVal117(p117.first);
  b.setVal120(p117.second);
  b.setVal121(es.EntityId(e.ReturnType()));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal119(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal86(e.HasCXXExplicitFunctionObjectParameter());
  b.setVal87(e.HasImplicitReturnZero());
  b.setVal88(e.HasInheritedPrototype());
  b.setVal89(e.HasOneParameterOrDefaultArguments());
  b.setVal90(e.HasPrototype());
  b.setVal91(e.HasSkippedBody());
  b.setVal92(e.HasTrivialBody());
  b.setVal93(e.HasWrittenPrototype());
  b.setVal94(e.InstantiationIsPending());
  b.setVal95(e.IsCPUDispatchMultiVersion());
  b.setVal96(e.IsCPUSpecificMultiVersion());
  b.setVal97(e.IsConsteval());
  b.setVal98(e.IsConstexpr());
  b.setVal99(e.IsConstexprSpecified());
  b.setVal100(e.IsDefaulted());
  b.setVal101(e.IsDeleted());
  b.setVal102(e.IsDeletedAsWritten());
  b.setVal103(e.IsDestroyingOperatorDelete());
  b.setVal104(e.IsExplicitlyDefaulted());
  b.setVal105(e.IsExternC());
  b.setVal106(e.IsFunctionTemplateSpecialization());
  b.setVal107(e.IsGlobal());
  b.setVal108(e.IsImmediateEscalating());
  b.setVal109(e.IsImmediateFunction());
  b.setVal110(e.IsImplicitlyInstantiable());
  b.setVal111(e.IsInExternCContext());
  b.setVal112(e.IsInExternCXXContext());
  b.setVal113(e.IsIneligibleOrNotSelected());
  b.setVal122(e.IsInlineBuiltinDeclaration());
  auto v123 = e.IsInlineDefinitionExternallyVisible();
  if (v123) {
    b.setVal123(static_cast<bool>(v123.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  b.setVal125(e.IsInlineSpecified());
  b.setVal126(e.IsInlined());
  b.setVal127(e.IsLateTemplateParsed());
  auto v128 = e.IsMSExternInline();
  if (v128) {
    b.setVal128(static_cast<bool>(v128.value()));
    b.setVal129(true);
  } else {
    b.setVal129(false);
  }
  b.setVal132(e.IsMSVCRTEntryPoint());
  b.setVal133(e.IsMain());
  b.setVal134(e.IsMemberLikeConstrainedFriend());
  b.setVal135(e.IsMultiVersion());
  b.setVal136(e.IsNoReturn());
  b.setVal137(e.IsOverloadedOperator());
  b.setVal138(e.IsPureVirtual());
  b.setVal139(e.IsReplaceableGlobalAllocationFunction());
  auto v140 = e.IsReservedGlobalPlacementOperator();
  if (v140) {
    b.setVal140(static_cast<bool>(v140.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  b.setVal142(e.IsStatic());
  b.setVal143(e.IsTargetClonesMultiVersion());
  b.setVal144(e.IsTargetMultiVersion());
  b.setVal145(e.IsTemplateInstantiation());
  b.setVal146(e.IsThisDeclarationADefinition());
  b.setVal147(e.IsTrivial());
  b.setVal148(e.IsTrivialForCall());
  b.setVal149(e.IsUserProvided());
  b.setVal150(e.IsVariadic());
  b.setVal151(e.IsVirtualAsWritten());
  do {
    auto v45 = e.Parameters();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  b.setVal152(e.UsesSEHTry());
  auto v153 = e.Body();
  if (v153) {
    auto id153 = es.EntityId(v153.value());
    b.setVal153(id153);
  } else {
    b.setVal153(mx::kInvalidEntityId);
  }
  do {
    auto v55 = e.TemplateArguments();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
}

void SerializeCXXMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  b.setVal155(es.EntityId(e.FunctionObjectParameterReferenceType()));
  b.setVal156(es.EntityId(e.FunctionObjectParameterType()));
  b.setVal157(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v158 = e.ThisType();
  if (v158) {
    auto id158 = es.EntityId(v158.value());
    b.setVal158(id158);
  } else {
    b.setVal158(mx::kInvalidEntityId);
  }
  b.setVal159(e.HasInlineBody());
  b.setVal160(e.IsConst());
  b.setVal161(e.IsCopyAssignmentOperator());
  b.setVal162(e.IsExplicitObjectMemberFunction());
  b.setVal163(e.IsImplicitObjectMemberFunction());
  b.setVal164(e.IsInstance());
  b.setVal165(e.IsLambdaStaticInvoker());
  b.setVal166(e.IsMoveAssignmentOperator());
  b.setVal167(e.IsVirtual());
  b.setVal168(e.IsVolatile());
  do {
    auto v169 = e.OverriddenMethods();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
  b.setVal170(e.SizeOverriddenMethods());
}

void SerializeCXXDestructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v171 = e.OperatorDelete();
  if (v171) {
    auto id171 = es.EntityId(v171.value());
    b.setVal171(id171);
  } else {
    b.setVal171(mx::kInvalidEntityId);
  }
  auto v172 = e.OperatorDeleteThisArgument();
  if (v172) {
    auto id172 = es.EntityId(v172.value());
    b.setVal172(id172);
  } else {
    b.setVal172(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  b.setVal171(es.EntityId(e.ConversionType()));
  b.setVal173(e.IsExplicit());
  b.setVal174(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(pf, es, b, e, nullptr);
  auto v171 = e.TargetConstructor();
  if (v171) {
    auto id171 = es.EntityId(v171.value());
    b.setVal171(id171);
  } else {
    b.setVal171(mx::kInvalidEntityId);
  }
  do {
    auto v175 = e.Initializers();
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
  b.setVal173(e.IsDefaultConstructor());
  b.setVal174(e.IsDelegatingConstructor());
  b.setVal176(e.IsExplicit());
  b.setVal177(e.IsInheritingConstructor());
  b.setVal178(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(pf, es, b, e, nullptr);
  auto v155 = e.CorrespondingConstructor();
  if (v155) {
    auto id155 = es.EntityId(v155.value());
    b.setVal155(id155);
  } else {
    b.setVal155(mx::kInvalidEntityId);
  }
  b.setVal156(es.EntityId(e.DeducedTemplate()));
  b.setVal157(static_cast<unsigned char>(mx::FromPasta(e.DeductionCandidateKind())));
  b.setVal159(e.IsExplicit());
}

void SerializeFieldDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(pf, es, b, e, nullptr);
  auto v72 = e.BitWidth();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  auto v74 = e.CapturedVLAType();
  if (v74) {
    auto id74 = es.EntityId(v74.value());
    b.setVal74(id74);
  } else {
    b.setVal74(mx::kInvalidEntityId);
  }
  b.setVal42(e.FieldIndex());
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v75 = e.InClassInitializer();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal69(e.HasCapturedVLAType());
  b.setVal70(e.HasInClassInitializer());
  b.setVal82(e.HasNonNullInClassInitializer());
  b.setVal83(e.IsAnonymousStructOrUnion());
  b.setVal84(e.IsBitField());
  b.setVal85(e.IsMutable());
  b.setVal86(e.IsPotentiallyOverlapping());
  b.setVal87(e.IsUnnamedBitfield());
  b.setVal88(e.IsZeroLengthBitField());
  b.setVal89(e.IsZeroSize());
  auto v76 = e.OffsetInBits();
  if (v76) {
    b.setVal76(static_cast<uint64_t>(v76.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
}

void SerializeObjCIvarDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(pf, es, b, e, nullptr);
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal114(es.EntityId(e.ContainingInterface()));
  b.setVal115(es.EntityId(e.NextInstanceVariable()));
  b.setVal91(e.Synthesize());
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
  auto v51 = e.Binding();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
  b.setVal59(es.EntityId(e.DecomposedDeclaration()));
  auto v60 = e.HoldingVariable();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
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
  b.setVal51(es.EntityId(e.MapperVariableReference()));
}

void SerializeUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal49(es.EntityId(e.Introducer()));
  auto v50 = e.NextUsingShadowDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal51(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(pf, es, b, e, nullptr);
  b.setVal67(e.ConstructsVirtualBase());
  b.setVal59(es.EntityId(e.ConstructedBaseClass()));
  auto v60 = e.ConstructedBaseClassShadowDeclaration();
  if (v60) {
    auto id60 = es.EntityId(v60.value());
    b.setVal60(id60);
  } else {
    b.setVal60(mx::kInvalidEntityId);
  }
  b.setVal61(es.EntityId(e.NominatedBaseClass()));
  auto v71 = e.NominatedBaseClassShadowDeclaration();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
  } else {
    b.setVal71(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v44 = e.Expansions();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeUsingDirectiveDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.IdentifierToken());
  b.setVal49(et49);
  auto et50 = es.EntityId(e.NamespaceKeyToken());
  b.setVal50(et50);
  b.setVal51(es.EntityId(e.NominatedNamespace()));
  b.setVal59(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto et60 = es.EntityId(e.UsingToken());
  b.setVal60(et60);
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
  auto v49 = e.TypeForDeclaration();
  if (v49) {
    auto id49 = es.EntityId(v49.value());
    b.setVal49(id49);
  } else {
    b.setVal49(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  b.setVal67(e.DefaultArgumentWasInherited());
  auto v50 = e.DefaultArgument();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  auto v51 = e.DefaultArgumentInfo();
  if (v51) {
    auto id51 = es.EntityId(v51.value());
    b.setVal51(id51);
  } else {
    b.setVal51(mx::kInvalidEntityId);
  }
  auto et59 = es.EntityId(e.DefaultArgumentToken());
  b.setVal59(et59);
  b.setVal42(e.Depth());
  b.setVal118(e.Index());
  b.setVal68(e.HasDefaultArgument());
  b.setVal69(e.HasTypeConstraint());
  b.setVal70(e.IsExpandedParameterPack());
  b.setVal82(e.IsPackExpansion());
  b.setVal83(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto p50 = es.EntityIds(e.BraceRange());
  b.setVal50(p50.first);
  b.setVal51(p50.second);
  auto et59 = es.EntityId(e.FirstInnerToken());
  b.setVal59(et59);
  auto et60 = es.EntityId(e.FirstOuterToken());
  b.setVal60(et60);
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v61 = e.TypedefNameForAnonymousDeclaration();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  b.setVal67(e.HasNameForLinkage());
  b.setVal68(e.IsBeingDefined());
  b.setVal69(e.IsClass());
  b.setVal70(e.IsCompleteDefinition());
  b.setVal82(e.IsCompleteDefinitionRequired());
  b.setVal83(e.IsDependentType());
  b.setVal84(e.IsEnum());
  b.setVal85(e.IsFreeStanding());
  b.setVal86(e.IsInterface());
  b.setVal87(e.IsStruct());
  b.setVal88(e.IsThisDeclarationADefinition());
  b.setVal89(e.IsThisDeclarationADemotedDefinition());
  b.setVal90(e.IsUnion());
  b.setVal91(e.MayHaveOutOfDateDefinition());
  do {
    auto v44 = e.TemplateParameterLists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  b.setVal92(e.CanPassInRegisters());
  do {
    auto v55 = e.Fields();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal93(e.HasFlexibleArrayMember());
  b.setVal94(e.HasLoadedFieldsFromExternalStorage());
  b.setVal95(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal96(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal97(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal98(e.HasObjectMember());
  b.setVal99(e.HasVolatileMember());
  b.setVal100(e.IsAnonymousStructOrUnion());
  b.setVal101(e.IsCapturedRecord());
  b.setVal102(e.IsInjectedClassName());
  b.setVal103(e.IsLambda());
  b.setVal104(e.IsMsStruct());
  b.setVal105(e.IsNonTrivialToPrimitiveCopy());
  b.setVal106(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal107(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal108(e.IsOrContainsUnion());
  b.setVal109(e.IsParameterDestroyedInCallee());
  b.setVal110(e.IsRandomized());
  b.setVal111(e.MayInsertExtraPadding());
  auto v71 = e.Size();
  if (v71) {
    b.setVal71(static_cast<uint64_t>(v71.value()));
    b.setVal112(true);
  } else {
    b.setVal112(false);
  }
  auto v72 = e.Alignment();
  if (v72) {
    b.setVal72(static_cast<uint64_t>(v72.value()));
    b.setVal113(true);
  } else {
    b.setVal113(false);
  }
  auto v74 = e.SizeWithoutTrailingPadding();
  if (v74) {
    b.setVal74(static_cast<uint64_t>(v74.value()));
    b.setVal122(true);
  } else {
    b.setVal122(false);
  }
}

void SerializeCXXRecordDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(pf, es, b, e, nullptr);
  auto v123 = e.AllowConstDefaultInitializer();
  if (v123) {
    b.setVal123(static_cast<bool>(v123.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  do {
    auto ov154 = e.Bases();
    if (!ov154) {
      b.setVal125(false);
      break;
    }
    b.setVal125(true);
    auto v154 = std::move(*ov154);
    auto sv154 = b.initVal154(static_cast<unsigned>(v154.size()));
    auto i154 = 0u;
    for (const auto &e154 : v154) {
      sv154.set(i154, es.EntityId(e154));
      ++i154;
    }
  } while (false);
  auto v78 = e.CalculateInheritanceModel();
  if (v78) {
    b.setVal78(static_cast<unsigned char>(v78.value()));
    b.setVal126(true);
  } else {
    b.setVal126(false);
  }
  do {
    auto v169 = e.Constructors();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
  do {
    auto ov175 = e.Friends();
    if (!ov175) {
      b.setVal127(false);
      break;
    }
    b.setVal127(true);
    auto v175 = std::move(*ov175);
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
  auto v75 = e.DependentLambdaCallOperator();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  auto v76 = e.DescribedClassTemplate();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v114 = e.Destructor();
  if (v114) {
    auto id114 = es.EntityId(v114.value());
    b.setVal114(id114);
  } else {
    b.setVal114(mx::kInvalidEntityId);
  }
  auto v115 = e.GenericLambdaTemplateParameterList();
  if (v115) {
    auto id115 = es.EntityId(v115.value());
    b.setVal115(id115);
  } else {
    b.setVal115(mx::kInvalidEntityId);
  }
  auto v116 = e.InstantiatedFromMemberClass();
  if (v116) {
    auto id116 = es.EntityId(v116.value());
    b.setVal116(id116);
  } else {
    b.setVal116(mx::kInvalidEntityId);
  }
  auto v117 = e.LambdaCallOperator();
  if (v117) {
    auto id117 = es.EntityId(v117.value());
    b.setVal117(id117);
  } else {
    b.setVal117(mx::kInvalidEntityId);
  }
  auto v79 = e.LambdaCaptureDefault();
  if (v79) {
    b.setVal79(static_cast<unsigned char>(v79.value()));
    b.setVal128(true);
  } else {
    b.setVal128(false);
  }
  auto v120 = e.LambdaContextDeclaration();
  if (v120) {
    auto id120 = es.EntityId(v120.value());
    b.setVal120(id120);
  } else {
    b.setVal120(mx::kInvalidEntityId);
  }
  b.setVal42(e.LambdaDependencyKind());
  do {
    auto ov179 = e.LambdaExplicitTemplateParameters();
    if (!ov179) {
      b.setVal129(false);
      break;
    }
    b.setVal129(true);
    auto v179 = std::move(*ov179);
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  auto v118 = e.LambdaManglingNumber();
  if (v118) {
    b.setVal118(static_cast<uint32_t>(v118.value()));
    b.setVal132(true);
  } else {
    b.setVal132(false);
  }
  auto v121 = e.LambdaStaticInvoker();
  if (v121) {
    auto id121 = es.EntityId(v121.value());
    b.setVal121(id121);
  } else {
    b.setVal121(mx::kInvalidEntityId);
  }
  auto v80 = e.MSInheritanceModel();
  if (v80) {
    b.setVal80(static_cast<unsigned char>(v80.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v134 = e.HasAnyDependentBases();
  if (v134) {
    b.setVal134(static_cast<bool>(v134.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  auto v136 = e.HasConstexprDefaultConstructor();
  if (v136) {
    b.setVal136(static_cast<bool>(v136.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  auto v138 = e.HasConstexprDestructor();
  if (v138) {
    b.setVal138(static_cast<bool>(v138.value()));
    b.setVal139(true);
  } else {
    b.setVal139(false);
  }
  auto v140 = e.HasConstexprNonCopyMoveConstructor();
  if (v140) {
    b.setVal140(static_cast<bool>(v140.value()));
    b.setVal141(true);
  } else {
    b.setVal141(false);
  }
  auto v142 = e.HasCopyAssignmentWithConstParameter();
  if (v142) {
    b.setVal142(static_cast<bool>(v142.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  auto v144 = e.HasCopyConstructorWithConstParameter();
  if (v144) {
    b.setVal144(static_cast<bool>(v144.value()));
    b.setVal145(true);
  } else {
    b.setVal145(false);
  }
  auto v146 = e.HasDefaultConstructor();
  if (v146) {
    b.setVal146(static_cast<bool>(v146.value()));
    b.setVal147(true);
  } else {
    b.setVal147(false);
  }
  auto v148 = e.HasDefinition();
  if (v148) {
    b.setVal148(static_cast<bool>(v148.value()));
    b.setVal149(true);
  } else {
    b.setVal149(false);
  }
  auto v150 = e.HasDirectFields();
  if (v150) {
    b.setVal150(static_cast<bool>(v150.value()));
    b.setVal151(true);
  } else {
    b.setVal151(false);
  }
  auto v152 = e.HasFriends();
  if (v152) {
    b.setVal152(static_cast<bool>(v152.value()));
    b.setVal159(true);
  } else {
    b.setVal159(false);
  }
  auto v160 = e.HasInClassInitializer();
  if (v160) {
    b.setVal160(static_cast<bool>(v160.value()));
    b.setVal161(true);
  } else {
    b.setVal161(false);
  }
  auto v162 = e.HasInheritedAssignment();
  if (v162) {
    b.setVal162(static_cast<bool>(v162.value()));
    b.setVal163(true);
  } else {
    b.setVal163(false);
  }
  auto v164 = e.HasInheritedConstructor();
  if (v164) {
    b.setVal164(static_cast<bool>(v164.value()));
    b.setVal165(true);
  } else {
    b.setVal165(false);
  }
  auto v166 = e.HasInitializerMethod();
  if (v166) {
    b.setVal166(static_cast<bool>(v166.value()));
    b.setVal167(true);
  } else {
    b.setVal167(false);
  }
  auto v168 = e.HasIrrelevantDestructor();
  if (v168) {
    b.setVal168(static_cast<bool>(v168.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasKnownLambdaInternalLinkage();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal176(true);
  } else {
    b.setVal176(false);
  }
  auto v177 = e.HasMoveAssignment();
  if (v177) {
    b.setVal177(static_cast<bool>(v177.value()));
    b.setVal178(true);
  } else {
    b.setVal178(false);
  }
  auto v180 = e.HasMoveConstructor();
  if (v180) {
    b.setVal180(static_cast<bool>(v180.value()));
    b.setVal181(true);
  } else {
    b.setVal181(false);
  }
  auto v182 = e.HasMutableFields();
  if (v182) {
    b.setVal182(static_cast<bool>(v182.value()));
    b.setVal183(true);
  } else {
    b.setVal183(false);
  }
  auto v184 = e.HasNonLiteralTypeFieldsOrBases();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v186 = e.HasNonTrivialCopyAssignment();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v188 = e.HasNonTrivialCopyConstructor();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  auto v190 = e.HasNonTrivialCopyConstructorForCall();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasNonTrivialDefaultConstructor();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasNonTrivialDestructor();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasNonTrivialDestructorForCall();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonTrivialMoveAssignment();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialMoveConstructor();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialMoveConstructorForCall();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasPrivateFields();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasProtectedFields();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasSimpleCopyAssignment();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasSimpleCopyConstructor();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasSimpleDestructor();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasSimpleMoveAssignment();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasSimpleMoveConstructor();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasTrivialCopyAssignment();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasTrivialCopyConstructor();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasTrivialCopyConstructorForCall();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasTrivialDefaultConstructor();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasTrivialDestructor();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasTrivialDestructorForCall();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasTrivialMoveAssignment();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialMoveConstructor();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialMoveConstructorForCall();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasUninitializedReferenceMember();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasUserDeclaredConstructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasUserDeclaredCopyAssignment();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasUserDeclaredCopyConstructor();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasUserDeclaredDestructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasUserDeclaredMoveAssignment();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasUserDeclaredMoveConstructor();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUserDeclaredMoveOperation();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserProvidedDefaultConstructor();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasVariantMembers();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.ImplicitCopyConstructorHasConstParameter();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.IsAbstract();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.IsAggregate();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.IsAnyDestructorNoReturn();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.IsCLike();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.IsCXX11StandardLayout();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  b.setVal270(e.IsCapturelessLambda());
  b.setVal271(e.IsDependentLambda());
  auto v272 = e.IsDynamicClass();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsEffectivelyFinal();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  auto v276 = e.IsEmpty();
  if (v276) {
    b.setVal276(static_cast<bool>(v276.value()));
    b.setVal277(true);
  } else {
    b.setVal277(false);
  }
  b.setVal278(e.IsGenericLambda());
  auto v279 = e.IsInterfaceLike();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsLiteral();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  auto v153 = e.IsLocalClass();
  if (v153) {
    auto id153 = es.EntityId(v153.value());
    b.setVal153(id153);
  } else {
    b.setVal153(mx::kInvalidEntityId);
  }
  b.setVal283(e.IsNeverDependentLambda());
  auto v284 = e.IsPOD();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  auto v286 = e.IsPolymorphic();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v288 = e.IsStandardLayout();
  if (v288) {
    b.setVal288(static_cast<bool>(v288.value()));
    b.setVal289(true);
  } else {
    b.setVal289(false);
  }
  auto v290 = e.IsStructural();
  if (v290) {
    b.setVal290(static_cast<bool>(v290.value()));
    b.setVal291(true);
  } else {
    b.setVal291(false);
  }
  auto v292 = e.IsTrivial();
  if (v292) {
    b.setVal292(static_cast<bool>(v292.value()));
    b.setVal293(true);
  } else {
    b.setVal293(false);
  }
  auto v294 = e.IsTriviallyCopyConstructible();
  if (v294) {
    b.setVal294(static_cast<bool>(v294.value()));
    b.setVal295(true);
  } else {
    b.setVal295(false);
  }
  auto v296 = e.IsTriviallyCopyable();
  if (v296) {
    b.setVal296(static_cast<bool>(v296.value()));
    b.setVal297(true);
  } else {
    b.setVal297(false);
  }
  auto v298 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v298) {
    b.setVal298(static_cast<bool>(v298.value()));
    b.setVal299(true);
  } else {
    b.setVal299(false);
  }
  auto v300 = e.MayBeAbstract();
  if (v300) {
    b.setVal300(static_cast<bool>(v300.value()));
    b.setVal301(true);
  } else {
    b.setVal301(false);
  }
  auto v302 = e.MayBeDynamicClass();
  if (v302) {
    b.setVal302(static_cast<bool>(v302.value()));
    b.setVal303(true);
  } else {
    b.setVal303(false);
  }
  auto v304 = e.MayBeNonDynamicClass();
  if (v304) {
    b.setVal304(static_cast<bool>(v304.value()));
    b.setVal305(true);
  } else {
    b.setVal305(false);
  }
  auto v306 = e.NeedsImplicitCopyAssignment();
  if (v306) {
    b.setVal306(static_cast<bool>(v306.value()));
    b.setVal307(true);
  } else {
    b.setVal307(false);
  }
  auto v308 = e.NeedsImplicitCopyConstructor();
  if (v308) {
    b.setVal308(static_cast<bool>(v308.value()));
    b.setVal309(true);
  } else {
    b.setVal309(false);
  }
  auto v310 = e.NeedsImplicitDefaultConstructor();
  if (v310) {
    b.setVal310(static_cast<bool>(v310.value()));
    b.setVal311(true);
  } else {
    b.setVal311(false);
  }
  auto v312 = e.NeedsImplicitDestructor();
  if (v312) {
    b.setVal312(static_cast<bool>(v312.value()));
    b.setVal313(true);
  } else {
    b.setVal313(false);
  }
  auto v314 = e.NeedsImplicitMoveAssignment();
  if (v314) {
    b.setVal314(static_cast<bool>(v314.value()));
    b.setVal315(true);
  } else {
    b.setVal315(false);
  }
  auto v316 = e.NeedsImplicitMoveConstructor();
  if (v316) {
    b.setVal316(static_cast<bool>(v316.value()));
    b.setVal317(true);
  } else {
    b.setVal317(false);
  }
  auto v318 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v318) {
    b.setVal318(static_cast<bool>(v318.value()));
    b.setVal319(true);
  } else {
    b.setVal319(false);
  }
  auto v320 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v320) {
    b.setVal320(static_cast<bool>(v320.value()));
    b.setVal321(true);
  } else {
    b.setVal321(false);
  }
  auto v322 = e.NeedsOverloadResolutionForDestructor();
  if (v322) {
    b.setVal322(static_cast<bool>(v322.value()));
    b.setVal323(true);
  } else {
    b.setVal323(false);
  }
  auto v324 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v324) {
    b.setVal324(static_cast<bool>(v324.value()));
    b.setVal325(true);
  } else {
    b.setVal325(false);
  }
  auto v326 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v326) {
    b.setVal326(static_cast<bool>(v326.value()));
    b.setVal327(true);
  } else {
    b.setVal327(false);
  }
  auto v328 = e.NullFieldOffsetIsZero();
  if (v328) {
    b.setVal328(static_cast<bool>(v328.value()));
    b.setVal329(true);
  } else {
    b.setVal329(false);
  }
  do {
    auto ov330 = e.VirtualBases();
    if (!ov330) {
      b.setVal331(false);
      break;
    }
    b.setVal331(true);
    auto v330 = std::move(*ov330);
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
    }
  } while (false);
  auto v155 = e.SizeWithoutVirtualBases();
  if (v155) {
    b.setVal155(static_cast<uint64_t>(v155.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v156 = e.PrimaryBase();
  if (v156) {
    auto id156 = es.EntityId(v156.value());
    b.setVal156(id156);
  } else {
    b.setVal156(mx::kInvalidEntityId);
  }
  auto v333 = e.HasOwnVirtualFunctionTablePointer();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  auto v335 = e.HasExtendableVirtualFunctionTablePointer();
  if (v335) {
    b.setVal335(static_cast<bool>(v335.value()));
    b.setVal336(true);
  } else {
    b.setVal336(false);
  }
  auto v337 = e.HasVirtualBaseTablePointer();
  if (v337) {
    b.setVal337(static_cast<bool>(v337.value()));
    b.setVal338(true);
  } else {
    b.setVal338(false);
  }
  auto v339 = e.HasOwnVirtualBaseTablePointer();
  if (v339) {
    b.setVal339(static_cast<bool>(v339.value()));
    b.setVal340(true);
  } else {
    b.setVal340(false);
  }
}

void SerializeClassTemplateSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(pf, es, b, e, nullptr);
  auto et158 = es.EntityId(e.ExternToken());
  b.setVal158(et158);
  b.setVal119(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal171(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v341 = e.TemplateArguments();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
  auto et172 = es.EntityId(e.TemplateKeywordToken());
  b.setVal172(et172);
  b.setVal342(e.IsClassScopeExplicitSpecialization());
  b.setVal343(e.IsExplicitInstantiationOrSpecialization());
  b.setVal344(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(pf, es, b, e, nullptr);
  b.setVal345(es.EntityId(e.InjectedSpecializationType()));
  b.setVal346(es.EntityId(e.TemplateParameters()));
  b.setVal347(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(pf, es, b, e, nullptr);
  do {
    auto v55 = e.Enumerators();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  auto v71 = e.IntegerType();
  if (v71) {
    auto id71 = es.EntityId(v71.value());
    b.setVal71(id71);
  } else {
    b.setVal71(mx::kInvalidEntityId);
  }
  auto p72 = es.EntityIds(e.IntegerTypeRange());
  b.setVal72(p72.first);
  b.setVal74(p72.second);
  auto v75 = e.PromotionType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal92(e.IsClosed());
  b.setVal93(e.IsClosedFlag());
  b.setVal94(e.IsClosedNonFlag());
  b.setVal95(e.IsComplete());
  b.setVal96(e.IsFixed());
  b.setVal97(e.IsScoped());
  b.setVal98(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto et50 = es.EntityId(e.EllipsisToken());
  b.setVal50(et50);
  auto et51 = es.EntityId(e.TypenameToken());
  b.setVal51(et51);
  auto et59 = es.EntityId(e.UsingToken());
  b.setVal59(et59);
  b.setVal67(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(pf, es, b, e, nullptr);
  auto v50 = e.AnonymousDeclarationWithTypedefName();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal51(es.EntityId(e.UnderlyingType()));
  b.setVal67(e.IsModed());
  b.setVal68(e.IsTransparentTag());
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
  auto v59 = e.DescribedAliasTemplate();
  if (v59) {
    auto id59 = es.EntityId(v59.value());
    b.setVal59(id59);
  } else {
    b.setVal59(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(pf, es, b, e, nullptr);
  auto et59 = es.EntityId(e.ColonToken());
  b.setVal59(et59);
  b.setVal42(e.Index());
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto et60 = es.EntityId(e.VarianceToken());
  b.setVal60(et60);
  b.setVal69(e.HasExplicitBound());
}

void SerializeTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal49(es.EntityId(e.TemplateParameters()));
  auto v50 = e.TemplatedDeclaration();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal67(e.HasAssociatedConstraints());
  b.setVal68(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(pf, es, b, e, nullptr);
  b.setVal69(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal70(e.IsAbbreviated());
  b.setVal82(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal70(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(pf, es, b, e, nullptr);
  b.setVal70(e.IsThisDeclarationADefinition());
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
  b.setVal51(es.EntityId(e.ConstraintExpression()));
  b.setVal69(e.IsTypeConcept());
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
  b.setVal69(e.DefaultArgumentWasInherited());
  auto et51 = es.EntityId(e.DefaultArgumentToken());
  b.setVal51(et51);
  b.setVal70(e.HasDefaultArgument());
  b.setVal82(e.IsExpandedParameterPack());
  b.setVal83(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.AtToken());
  b.setVal49(et49);
  b.setVal50(es.EntityId(e.GetterMethodDeclaration()));
  auto et51 = es.EntityId(e.GetterNameToken());
  b.setVal51(et51);
  auto et59 = es.EntityId(e.LParenToken());
  b.setVal59(et59);
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal60(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal61(es.EntityId(e.SetterMethodDeclaration()));
  auto et71 = es.EntityId(e.SetterNameToken());
  b.setVal71(et71);
  b.setVal72(es.EntityId(e.Type()));
  b.setVal67(e.IsAtomic());
  b.setVal68(e.IsClassProperty());
  b.setVal69(e.IsDirectProperty());
  b.setVal70(e.IsInstanceProperty());
  b.setVal82(e.IsOptional());
  b.setVal83(e.IsReadOnly());
  b.setVal84(e.IsRetaining());
}

void SerializeObjCMethodDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal67(e.DefinedInNSObject());
  b.setVal49(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal50(es.EntityId(e.ClassInterface()));
  b.setVal51(es.EntityId(e.CommandDeclaration()));
  auto et59 = es.EntityId(e.DeclaratorEndToken());
  b.setVal59(et59);
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal77(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal60(es.EntityId(e.ReturnType()));
  auto p61 = es.EntityIds(e.ReturnTypeTokens());
  b.setVal61(p61.first);
  b.setVal71(p61.second);
  auto et72 = es.EntityId(e.SelectorStartToken());
  b.setVal72(et72);
  b.setVal74(es.EntityId(e.SelfDeclaration()));
  b.setVal68(e.HasParameterDestroyedInCallee());
  b.setVal69(e.HasRedeclaration());
  b.setVal70(e.HasRelatedResultType());
  b.setVal82(e.HasSkippedBody());
  b.setVal83(e.IsClassMethod());
  b.setVal84(e.IsDefined());
  b.setVal85(e.IsDesignatedInitializerForTheInterface());
  b.setVal86(e.IsDirectMethod());
  b.setVal87(e.IsInstanceMethod());
  b.setVal88(e.IsOptional());
  b.setVal89(e.IsOverriding());
  b.setVal90(e.IsPropertyAccessor());
  b.setVal91(e.IsRedeclaration());
  b.setVal92(e.IsSynthesizedAccessorStub());
  b.setVal93(e.IsThisDeclarationADefinition());
  b.setVal94(e.IsThisDeclarationADesignatedInitializer());
  b.setVal95(e.IsVariadic());
  do {
    auto v44 = e.Parameters();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.SelectorTokens();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
}

void SerializeObjCContainerDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  do {
    auto v44 = e.ClassMethods();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  do {
    auto v45 = e.ClassProperties();
    auto sv45 = b.initVal45(static_cast<unsigned>(v45.size()));
    auto i45 = 0u;
    for (const auto &e45 : v45) {
      sv45.set(i45, es.EntityId(e45));
      ++i45;
    }
  } while (false);
  auto p49 = es.EntityIds(e.AtEndRange());
  b.setVal49(p49.first);
  b.setVal50(p49.second);
  auto et51 = es.EntityId(e.AtStartToken());
  b.setVal51(et51);
  do {
    auto v55 = e.InstanceMethods();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v154 = e.InstanceProperties();
    auto sv154 = b.initVal154(static_cast<unsigned>(v154.size()));
    auto i154 = 0u;
    for (const auto &e154 : v154) {
      sv154.set(i154, es.EntityId(e154));
      ++i154;
    }
  } while (false);
  do {
    auto v169 = e.Methods();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
  do {
    auto v175 = e.Properties();
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
}

void SerializeObjCCategoryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal67(e.IsClassExtension());
  auto et59 = es.EntityId(e.CategoryNameToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.ClassInterface()));
  b.setVal61(es.EntityId(e.Implementation()));
  auto et71 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal71(et71);
  auto et72 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal72(et72);
  b.setVal74(es.EntityId(e.NextClassCategory()));
  do {
    auto v330 = e.InstanceVariables();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
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
    auto v348 = e.Protocols();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  auto v57 = e.ObjCRuntimeNameAsString();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  b.setVal67(e.HasDefinition());
  b.setVal68(e.IsNonRuntimeProtocol());
  b.setVal69(e.IsThisDeclarationADefinition());
  do {
    auto v330 = e.ProtocolTokens();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
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
    auto v330 = e.AllReferencedProtocols();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
    }
  } while (false);
  b.setVal67(e.DeclaresOrInheritsDesignatedInitializers());
  auto et59 = es.EntityId(e.EndOfDefinitionToken());
  b.setVal59(et59);
  b.setVal60(es.EntityId(e.Implementation()));
  auto v57 = e.ObjCRuntimeNameAsString();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  auto v61 = e.SuperClass();
  if (v61) {
    auto id61 = es.EntityId(v61.value());
    b.setVal61(id61);
  } else {
    b.setVal61(mx::kInvalidEntityId);
  }
  auto et71 = es.EntityId(e.SuperClassToken());
  b.setVal71(et71);
  auto v72 = e.SuperClassTypeInfo();
  if (v72) {
    auto id72 = es.EntityId(v72.value());
    b.setVal72(id72);
  } else {
    b.setVal72(mx::kInvalidEntityId);
  }
  b.setVal74(es.EntityId(e.TypeForDeclaration()));
  b.setVal68(e.HasDefinition());
  b.setVal69(e.HasDesignatedInitializers());
  b.setVal70(e.IsArcWeakrefUnavailable());
  b.setVal82(e.IsImplicitInterfaceDeclaration());
  b.setVal75(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal83(e.IsThisDeclarationADefinition());
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

void SerializeObjCImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(pf, es, b, e, nullptr);
  b.setVal59(es.EntityId(e.ClassInterface()));
  do {
    auto v330 = e.PropertyImplementations();
    auto sv330 = b.initVal330(static_cast<unsigned>(v330.size()));
    auto i330 = 0u;
    for (const auto &e330 : v330) {
      sv330.set(i330, es.EntityId(e330));
      ++i330;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  b.setVal60(es.EntityId(e.CategoryDeclaration()));
  auto et61 = es.EntityId(e.CategoryNameToken());
  b.setVal61(et61);
}

void SerializeObjCImplementationDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(pf, es, b, e, nullptr);
  auto et60 = es.EntityId(e.InstanceVariableLBraceToken());
  b.setVal60(et60);
  auto et61 = es.EntityId(e.InstanceVariableRBraceToken());
  b.setVal61(et61);
  auto v57 = e.ObjCRuntimeNameAsString();
  std::string s57(v57.data(), v57.size());
  b.setVal57(s57);
  b.setVal71(es.EntityId(e.SuperClass()));
  auto et72 = es.EntityId(e.SuperClassToken());
  b.setVal72(et72);
  b.setVal67(e.HasDestructors());
  b.setVal68(e.HasNonZeroConstructors());
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
    auto v348 = e.InstanceVariables();
    auto sv348 = b.initVal348(static_cast<unsigned>(v348.size()));
    auto i348 = 0u;
    for (const auto &e348 : v348) {
      sv348.set(i348, es.EntityId(e348));
      ++i348;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  b.setVal49(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.RBraceToken());
  b.setVal49(et49);
  b.setVal67(e.IsAnonymousNamespace());
  b.setVal68(e.IsInline());
  b.setVal69(e.IsNested());
}

void SerializeNamespaceAliasDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(pf, es, b, e, nullptr);
  auto et49 = es.EntityId(e.AliasToken());
  b.setVal49(et49);
  b.setVal50(es.EntityId(e.AliasedNamespace()));
  b.setVal51(es.EntityId(e.Namespace()));
  auto et59 = es.EntityId(e.NamespaceToken());
  b.setVal59(et59);
  auto et60 = es.EntityId(e.TargetNameToken());
  b.setVal60(et60);
}

void SerializeLinkageSpecDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et41 = es.EntityId(e.ExternToken());
  b.setVal41(et41);
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.Language())));
  auto et49 = es.EntityId(e.RBraceToken());
  b.setVal49(et49);
  b.setVal43(e.HasBraces());
}

void SerializeLifetimeExtendedTemporaryDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v44 = e.Children();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
  b.setVal41(es.EntityId(e.ExtendingDeclaration()));
  b.setVal42(e.ManglingNumber());
  b.setVal58(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal49(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  do {
    auto v44 = e.IdentifierTokens();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
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
    auto v44 = e.TemplateArguments();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  b.setVal41(es.EntityId(e.FriendDeclaration()));
  auto et49 = es.EntityId(e.FriendToken());
  b.setVal49(et49);
  b.setVal50(es.EntityId(e.FriendType()));
  do {
    auto v44 = e.TemplateParameterLists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeFriendDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto v41 = e.FriendDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto et49 = es.EntityId(e.FriendToken());
  b.setVal49(et49);
  auto v50 = e.FriendType();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal42(e.FriendTypeNumTemplateParameterLists());
  b.setVal43(e.IsUnsupportedFriend());
  do {
    auto v44 = e.FriendTypeTemplateParameterLists();
    auto sv44 = b.initVal44(static_cast<unsigned>(v44.size()));
    auto i44 = 0u;
    for (const auto &e44 : v44) {
      sv44.set(i44, es.EntityId(e44));
      ++i44;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et41 = es.EntityId(e.AssemblyToken());
  b.setVal41(et41);
  b.setVal49(es.EntityId(e.AssemblyString()));
  auto et50 = es.EntityId(e.RParenToken());
  b.setVal50(et50);
}

void SerializeExternCContextDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
}

void SerializeExportDecl(const PendingFragment &pf, const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) pf;
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(pf, es, b, e, nullptr);
  auto et41 = es.EntityId(e.ExportToken());
  b.setVal41(et41);
  auto et49 = es.EntityId(e.RBraceToken());
  b.setVal49(et49);
  b.setVal43(e.HasBraces());
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
