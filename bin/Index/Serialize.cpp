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
}

void SerializeMacroConcatenate(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroConcatenate &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  auto t7 = e.PastedToken();
  b.setVal7(es.EntityId(t7));
}

void SerializeMacroStringify(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroStringify &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  auto t7 = e.StringifiedToken();
  b.setVal7(es.EntityId(t7));
}

void SerializeMacroExpansion(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroExpansion &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  if (tt) {
    auto v8 = tt->IntermediateChildren();
    auto sv8 = b.initVal8(static_cast<unsigned>(v8.size()));
    auto i8 = 0u;
    for (auto n8 : v8) {
      sv8.set(i8, es.EntityId(n8.RawNode()));
      ++i8;
    }
  } else {
    auto v8 = e.IntermediateChildren();
    auto sv8 = b.initVal8(static_cast<unsigned>(v8.size()));
    auto i8 = 0u;
    for (const auto &e8 : v8) {
      sv8.set(i8, es.EntityId(e8));
      ++i8;
    }
  }
  auto v7 = e.Definition();
  if (v7) {
    auto id7 = es.EntityId(v7.value());
    b.setVal7(id7);
  } else {
    b.setVal7(mx::kInvalidEntityId);
  }
  do {
    auto v9 = e.Arguments();
    auto sv9 = b.initVal9(static_cast<unsigned>(v9.size()));
    auto i9 = 0u;
    for (const auto &e9 : v9) {
      sv9.set(i9, es.EntityId(e9));
      ++i9;
    }
  } while (false);
}

void SerializeMacroParameterSubstitution(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroParameterSubstitution &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacroSubstitution(es, b, e, tt);
  b.setVal7(es.EntityId(e.Parameter()));
  auto t10 = e.ParameterUse();
  b.setVal10(es.EntityId(t10));
}

void SerializeMacroArgument(const EntityMapper &es, mx::ast::Macro::Builder b, const pasta::MacroArgument &e, const TokenTree *tt) {
  (void) tt;
  (void) es;
  (void) b;
  (void) e;
  SerializeMacro(es, b, e, tt);
  b.setVal3(e.IsVariadic());
  b.setVal11(e.Index());
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
  b.setVal11(e.Index());
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
  b.setVal12(e.IsFunctionLike());
  if (true) {
    auto v8 = e.Parameters();
    auto sv8 = b.initVal8(static_cast<unsigned>(v8.size()));
    auto i8 = 0u;
    for (const auto &e8 : v8) {
      sv8.set(i8, es.EntityId(e8));
      ++i8;
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
  auto v3 = e.HighestContainingSubstitution();
  if (v3) {
    auto id3 = es.EntityId(v3.value());
    b.setVal3(id3);
  } else {
    b.setVal3(mx::kInvalidEntityId);
  }
  auto v4 = e.LowestContainingMacroArgument();
  if (v4) {
    auto id4 = es.EntityId(v4.value());
    b.setVal4(id4);
  } else {
    b.setVal4(mx::kInvalidEntityId);
  }
  do {
    auto v5 = e.CoveringMacros();
    auto sv5 = b.initVal5(static_cast<unsigned>(v5.size()));
    auto i5 = 0u;
    for (const auto &e5 : v5) {
      sv5.set(i5, es.EntityId(e5));
      ++i5;
    }
  } while (false);
  b.setVal6(es.EntityId(e.IgnoreContainers()));
  do {
    auto v7 = e.Children();
    auto sv7 = b.initVal7(static_cast<unsigned>(v7.size()));
    auto i7 = 0u;
    for (const auto &e7 : v7) {
      sv7.set(i7, es.EntityId(e7));
      ++i7;
    }
  } while (false);
  if (auto r8 = e.Tokens(); auto rs8 = r8.Size()) {
    b.setVal8(es.EntityId(r8[0]));
    b.setVal9(es.EntityId(r8[rs8 - 1u]));
  } else {
    b.setVal8(0);
    b.setVal9(0);
  }
  b.setVal10(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal11(es.EntityId(e.StripLabelLikeStatements()));
}

void SerializeSEHTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.ExceptHandler()));
  b.setVal13(es.EntityId(e.FinallyHandler()));
  b.setVal14(es.EntityId(e.Handler()));
  b.setVal15(e.IsCXXTry());
  b.setVal16(es.EntityId(e.TryBlock()));
  auto t17 = e.TryToken();
  b.setVal17(es.EntityId(t17));
}

void SerializeSEHLeaveStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.LeaveToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeSEHFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Block()));
  auto t13 = e.FinallyToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeSEHExceptStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Block()));
  auto t13 = e.ExceptToken();
  b.setVal13(es.EntityId(t13));
  b.setVal14(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v12 = e.NRVOCandidate();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto v13 = e.ReturnValue();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto t14 = e.ReturnToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeObjCForCollectionStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Body()));
  b.setVal13(es.EntityId(e.Collection()));
  b.setVal14(es.EntityId(e.Element()));
  auto t16 = e.ForToken();
  b.setVal16(es.EntityId(t16));
  auto t17 = e.RParenToken();
  b.setVal17(es.EntityId(t17));
}

void SerializeObjCAutoreleasePoolStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.AtToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.AtTryToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.FinallyStatement()));
  b.setVal14(es.EntityId(e.TryBody()));
  do {
    auto v18 = e.CatchStatements();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeObjCAtThrowStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.ThrowExpression()));
  auto t13 = e.ThrowToken();
  b.setVal13(es.EntityId(t13));
}

void SerializeObjCAtSynchronizedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.AtSynchronizedToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.SynchBody()));
  b.setVal14(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.AtFinallyToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.AtCatchToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.CatchBody()));
  b.setVal14(es.EntityId(e.CatchParameterDeclaration()));
  auto t16 = e.RParenToken();
  b.setVal16(es.EntityId(t16));
  b.setVal15(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.AssociatedStatement()));
  b.setVal13(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal14(es.EntityId(e.RawStatement()));
  b.setVal16(es.EntityId(e.StructuredBlock()));
  b.setVal15(e.HasAssociatedStatement());
  b.setVal19(e.IsStandaloneDirective());
}

void SerializeOMPErrorDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPErrorDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPDispatchDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  auto t17 = e.TargetCallToken();
  b.setVal17(es.EntityId(t17));
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
  b.setVal17(es.EntityId(e.ConditionExpression()));
  b.setVal20(es.EntityId(e.D()));
  b.setVal21(es.EntityId(e.Expression()));
  b.setVal22(es.EntityId(e.R()));
  b.setVal23(es.EntityId(e.UpdateExpression()));
  b.setVal24(es.EntityId(e.V()));
  b.setVal25(es.EntityId(e.X()));
  b.setVal26(e.IsFailOnly());
  b.setVal27(e.IsPostfixUpdate());
  b.setVal28(e.IsXLHSInRHSPart());
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
  b.setVal17(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
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
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPSectionDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPScanDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPParallelSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPOrderedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal17(es.EntityId(e.IfStatement()));
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
  b.setVal17(es.EntityId(e.PreInitializers()));
  b.setVal20(es.EntityId(e.TransformedStatement()));
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
    auto v18 = e.Counters();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  do {
    auto v29 = e.DependentCounters();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  do {
    auto v30 = e.DependentInitializers();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  do {
    auto v31 = e.Finals();
    auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
    auto i31 = 0u;
    for (const auto &e31 : v31) {
      sv31.set(i31, es.EntityId(e31));
      ++i31;
    }
  } while (false);
  do {
    auto v32 = e.FinalsConditions();
    auto sv32 = b.initVal32(static_cast<unsigned>(v32.size()));
    auto i32 = 0u;
    for (const auto &e32 : v32) {
      sv32.set(i32, es.EntityId(e32));
      ++i32;
    }
  } while (false);
  b.setVal17(es.EntityId(e.Body()));
  b.setVal20(es.EntityId(e.CalculateLastIteration()));
  b.setVal21(es.EntityId(e.CombinedCondition()));
  b.setVal22(es.EntityId(e.CombinedDistanceCondition()));
  b.setVal23(es.EntityId(e.CombinedEnsureUpperBound()));
  b.setVal24(es.EntityId(e.CombinedInitializer()));
  b.setVal25(es.EntityId(e.CombinedLowerBoundVariable()));
  b.setVal33(es.EntityId(e.CombinedNextLowerBound()));
  b.setVal34(es.EntityId(e.CombinedNextUpperBound()));
  b.setVal35(es.EntityId(e.CombinedParallelForInDistanceCondition()));
  b.setVal36(es.EntityId(e.CombinedUpperBoundVariable()));
  b.setVal37(es.EntityId(e.Condition()));
  b.setVal38(es.EntityId(e.DistanceIncrement()));
  b.setVal39(es.EntityId(e.EnsureUpperBound()));
  b.setVal40(es.EntityId(e.Increment()));
  b.setVal41(es.EntityId(e.Initializer()));
  b.setVal42(es.EntityId(e.IsLastIterationVariable()));
  b.setVal43(es.EntityId(e.IterationVariable()));
  b.setVal44(es.EntityId(e.LastIteration()));
  b.setVal45(es.EntityId(e.LowerBoundVariable()));
  b.setVal46(es.EntityId(e.NextLowerBound()));
  b.setVal47(es.EntityId(e.NextUpperBound()));
  b.setVal48(es.EntityId(e.PreCondition()));
  b.setVal49(es.EntityId(e.PreInitializers()));
  b.setVal50(es.EntityId(e.PrevEnsureUpperBound()));
  b.setVal51(es.EntityId(e.PrevLowerBoundVariable()));
  b.setVal52(es.EntityId(e.PrevUpperBoundVariable()));
  b.setVal53(es.EntityId(e.StrideVariable()));
  b.setVal54(es.EntityId(e.UpperBoundVariable()));
  do {
    auto v55 = e.Initializers();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v56 = e.PrivateCounters();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v57 = e.Updates();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
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
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
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
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
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
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
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
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal58(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal26(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal26(e.HasCancel());
}

void SerializeOMPInteropDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPFlushDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCanonicalLoop(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.DistanceFunc()));
  b.setVal13(es.EntityId(e.LoopStatement()));
  b.setVal14(es.EntityId(e.LoopVariableFunc()));
  b.setVal16(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.SemiToken();
  b.setVal12(es.EntityId(t12));
  b.setVal15(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.KeywordToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.SubStatement()));
  b.setVal15(e.IsIfExists());
  b.setVal19(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v12 = e.ConstantTarget();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  auto t13 = e.GotoToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.StarToken();
  b.setVal14(es.EntityId(t14));
  b.setVal16(es.EntityId(e.Target()));
}

void SerializeIfStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Condition()));
  auto v13 = e.ConditionVariable();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.ConditionVariableDeclarationStatement();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v16 = e.Else();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto t17 = e.ElseToken();
  b.setVal17(es.EntityId(t17));
  auto t20 = e.IfToken();
  b.setVal20(es.EntityId(t20));
  auto v21 = e.Initializer();
  if (v21) {
    auto id21 = es.EntityId(v21.value());
    b.setVal21(id21);
  } else {
    b.setVal21(mx::kInvalidEntityId);
  }
  auto t22 = e.LParenToken();
  b.setVal22(es.EntityId(t22));
  auto v23 = e.NondiscardedCase();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
  }
  auto t24 = e.RParenToken();
  b.setVal24(es.EntityId(t24));
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal25(es.EntityId(e.Then()));
  b.setVal15(e.HasElseStorage());
  b.setVal19(e.HasInitializerStorage());
  b.setVal26(e.HasVariableStorage());
  b.setVal27(e.IsConsteval());
  b.setVal28(e.IsConstexpr());
  b.setVal60(e.IsNegatedConsteval());
  b.setVal61(e.IsNonNegatedConsteval());
  b.setVal62(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.GotoToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.Label()));
  auto t14 = e.LabelToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeForStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Body()));
  auto v13 = e.Condition();
  if (v13) {
    auto id13 = es.EntityId(v13.value());
    b.setVal13(id13);
  } else {
    b.setVal13(mx::kInvalidEntityId);
  }
  auto v14 = e.ConditionVariable();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v16 = e.ConditionVariableDeclarationStatement();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto t17 = e.ForToken();
  b.setVal17(es.EntityId(t17));
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
  auto t22 = e.LParenToken();
  b.setVal22(es.EntityId(t22));
  auto t23 = e.RParenToken();
  b.setVal23(es.EntityId(t23));
}

void SerializeDoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Body()));
  b.setVal13(es.EntityId(e.Condition()));
  auto t14 = e.DoToken();
  b.setVal14(es.EntityId(t14));
  auto t16 = e.RParenToken();
  b.setVal16(es.EntityId(t16));
  auto t17 = e.WhileToken();
  b.setVal17(es.EntityId(t17));
}

void SerializeDeclStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  do {
    auto v18 = e.Declarations();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  auto v12 = e.SingleDeclaration();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
  b.setVal15(e.IsSingleDeclaration());
}

void SerializeCoroutineBodyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Allocate()));
  b.setVal13(es.EntityId(e.Body()));
  b.setVal14(es.EntityId(e.Deallocate()));
  b.setVal16(es.EntityId(e.ExceptionHandler()));
  b.setVal17(es.EntityId(e.FallthroughHandler()));
  b.setVal20(es.EntityId(e.FinalSuspendStatement()));
  b.setVal21(es.EntityId(e.InitializerSuspendStatement()));
  do {
    auto v18 = e.ParameterMoves();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal22(es.EntityId(e.PromiseDeclaration()));
  b.setVal23(es.EntityId(e.PromiseDeclarationStatement()));
  b.setVal24(es.EntityId(e.ReturnStatement()));
  b.setVal25(es.EntityId(e.ReturnStatementOnAllocFailure()));
  b.setVal33(es.EntityId(e.ReturnValue()));
  b.setVal34(es.EntityId(e.ReturnValueInitializer()));
  b.setVal15(e.HasDependentPromiseType());
}

void SerializeCoreturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.KeywordToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.Operand()));
  b.setVal14(es.EntityId(e.PromiseCall()));
  b.setVal15(e.IsImplicit());
}

void SerializeContinueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.ContinueToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeCompoundStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.LeftBraceToken();
  b.setVal12(es.EntityId(t12));
  auto t13 = e.RightBraceToken();
  b.setVal13(es.EntityId(t13));
  auto v14 = e.StatementExpressionResult();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  b.setVal15(e.HasStoredFPFeatures());
}

void SerializeCapturedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.CapturedDeclaration()));
  b.setVal13(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal14(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.TryBlock()));
  auto t13 = e.TryToken();
  b.setVal13(es.EntityId(t13));
  do {
    auto v18 = e.Handlers();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeCXXForRangeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.BeginStatement()));
  b.setVal13(es.EntityId(e.Body()));
  auto t14 = e.CoawaitToken();
  b.setVal14(es.EntityId(t14));
  auto t16 = e.ColonToken();
  b.setVal16(es.EntityId(t16));
  b.setVal17(es.EntityId(e.Condition()));
  b.setVal20(es.EntityId(e.EndStatement()));
  auto t21 = e.ForToken();
  b.setVal21(es.EntityId(t21));
  b.setVal22(es.EntityId(e.Increment()));
  auto v23 = e.Initializer();
  if (v23) {
    auto id23 = es.EntityId(v23.value());
    b.setVal23(id23);
  } else {
    b.setVal23(mx::kInvalidEntityId);
  }
  b.setVal24(es.EntityId(e.LoopVariableStatement()));
  b.setVal25(es.EntityId(e.LoopVariable()));
  auto t33 = e.RParenToken();
  b.setVal33(es.EntityId(t33));
  b.setVal34(es.EntityId(e.RangeInitializer()));
  b.setVal35(es.EntityId(e.RangeStatement()));
}

void SerializeCXXCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.CatchToken();
  b.setVal12(es.EntityId(t12));
  b.setVal13(es.EntityId(e.CaughtType()));
  auto v14 = e.ExceptionDeclaration();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  b.setVal16(es.EntityId(e.HandlerBlock()));
}

void SerializeBreakStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.BreakToken();
  b.setVal12(es.EntityId(t12));
}

void SerializeAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal63(e.GenerateAssemblyString());
  auto t12 = e.AssemblyToken();
  b.setVal12(es.EntityId(t12));
  do {
    auto v18 = e.Inputs();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal15(e.IsSimple());
  b.setVal19(e.IsVolatile());
  do {
    auto v29 = e.Outputs();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
  do {
    auto v64 = e.OutputConstraints();
    auto sv64 = b.initVal64(static_cast<unsigned>(v64.size()));
    auto i64 = 0u;
    for (const auto &e64 : v64) {
      std::string se64(e64.data(), e64.size());
      sv64.set(i64, se64);
      ++i64;
    }
  } while (false);
  do {
    auto v30 = e.OutputExpressions();
    auto sv30 = b.initVal30(static_cast<unsigned>(v30.size()));
    auto i30 = 0u;
    for (const auto &e30 : v30) {
      sv30.set(i30, es.EntityId(e30));
      ++i30;
    }
  } while (false);
  do {
    auto v65 = e.InputConstraints();
    auto sv65 = b.initVal65(static_cast<unsigned>(v65.size()));
    auto i65 = 0u;
    for (const auto &e65 : v65) {
      std::string se65(e65.data(), e65.size());
      sv65.set(i65, se65);
      ++i65;
    }
  } while (false);
  do {
    auto v31 = e.InputExpressions();
    auto sv31 = b.initVal31(static_cast<unsigned>(v31.size()));
    auto i31 = 0u;
    for (const auto &e31 : v31) {
      sv31.set(i31, es.EntityId(e31));
      ++i31;
    }
  } while (false);
  do {
    auto v66 = e.Clobbers();
    auto sv66 = b.initVal66(static_cast<unsigned>(v66.size()));
    auto i66 = 0u;
    for (const auto &e66 : v66) {
      std::string se66(e66.data(), e66.size());
      sv66.set(i66, se66);
      ++i66;
    }
  } while (false);
}

void SerializeMSAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
  do {
    auto v67 = e.AllConstraints();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
  do {
    auto v32 = e.AllExpressions();
    auto sv32 = b.initVal32(static_cast<unsigned>(v32.size()));
    auto i32 = 0u;
    for (const auto &e32 : v32) {
      sv32.set(i32, es.EntityId(e32));
      ++i32;
    }
  } while (false);
  auto v68 = e.AssemblyString();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto t13 = e.LBraceToken();
  b.setVal13(es.EntityId(t13));
  b.setVal26(e.HasBraces());
}

void SerializeGCCAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
  b.setVal13(es.EntityId(e.AssemblyString()));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
  b.setVal26(e.IsAssemblyGoto());
  do {
    auto v32 = e.Labels();
    auto sv32 = b.initVal32(static_cast<unsigned>(v32.size()));
    auto i32 = 0u;
    for (const auto &e32 : v32) {
      sv32.set(i32, es.EntityId(e32));
      ++i32;
    }
  } while (false);
  do {
    auto v55 = e.OutputConstraintLiterals();
    auto sv55 = b.initVal55(static_cast<unsigned>(v55.size()));
    auto i55 = 0u;
    for (const auto &e55 : v55) {
      sv55.set(i55, es.EntityId(e55));
      ++i55;
    }
  } while (false);
  do {
    auto v67 = e.OutputNames();
    auto sv67 = b.initVal67(static_cast<unsigned>(v67.size()));
    auto i67 = 0u;
    for (const auto &e67 : v67) {
      std::string se67(e67.data(), e67.size());
      sv67.set(i67, se67);
      ++i67;
    }
  } while (false);
  do {
    auto v56 = e.InputConstraintLiterals();
    auto sv56 = b.initVal56(static_cast<unsigned>(v56.size()));
    auto i56 = 0u;
    for (const auto &e56 : v56) {
      sv56.set(i56, es.EntityId(e56));
      ++i56;
    }
  } while (false);
  do {
    auto v69 = e.InputNames();
    auto sv69 = b.initVal69(static_cast<unsigned>(v69.size()));
    auto i69 = 0u;
    for (const auto &e69 : v69) {
      std::string se69(e69.data(), e69.size());
      sv69.set(i69, se69);
      ++i69;
    }
  } while (false);
  do {
    auto v57 = e.ClobberStringLiterals();
    auto sv57 = b.initVal57(static_cast<unsigned>(v57.size()));
    auto i57 = 0u;
    for (const auto &e57 : v57) {
      sv57.set(i57, es.EntityId(e57));
      ++i57;
    }
  } while (false);
  do {
    auto v70 = e.LabelExpressions();
    auto sv70 = b.initVal70(static_cast<unsigned>(v70.size()));
    auto i70 = 0u;
    for (const auto &e70 : v70) {
      sv70.set(i70, es.EntityId(e70));
      ++i70;
    }
  } while (false);
  do {
    auto v71 = e.LabelNames();
    auto sv71 = b.initVal71(static_cast<unsigned>(v71.size()));
    auto i71 = 0u;
    for (const auto &e71 : v71) {
      std::string se71(e71.data(), e71.size());
      sv71.set(i71, se71);
      ++i71;
    }
  } while (false);
}

void SerializeWhileStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Body()));
  b.setVal13(es.EntityId(e.Condition()));
  auto v14 = e.ConditionVariable();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v16 = e.ConditionVariableDeclarationStatement();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto t17 = e.LParenToken();
  b.setVal17(es.EntityId(t17));
  auto t20 = e.RParenToken();
  b.setVal20(es.EntityId(t20));
  auto t21 = e.WhileToken();
  b.setVal21(es.EntityId(t21));
  b.setVal15(e.HasVariableStorage());
}

void SerializeValueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v12 = e.ExpressionStatement();
  if (v12) {
    auto id12 = es.EntityId(v12.value());
    b.setVal12(id12);
  } else {
    b.setVal12(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  b.setVal13(es.EntityId(e.Declaration()));
  auto t14 = e.IdentifierToken();
  b.setVal14(es.EntityId(t14));
  auto v63 = e.Name();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal16(es.EntityId(e.SubStatement()));
  b.setVal15(e.IsSideEntry());
}

void SerializeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  b.setVal15(e.HasSideEffects());
  b.setVal13(es.EntityId(e.IgnoreCasts()));
  b.setVal14(es.EntityId(e.IgnoreConversionOperatorSingleStep()));
  b.setVal16(es.EntityId(e.IgnoreImplicitCasts()));
  b.setVal17(es.EntityId(e.IgnoreImplicit()));
  b.setVal20(es.EntityId(e.IgnoreImplicitAsWritten()));
  b.setVal21(es.EntityId(e.IgnoreParenthesisBaseCasts()));
  b.setVal22(es.EntityId(e.IgnoreParenthesisCasts()));
  b.setVal23(es.EntityId(e.IgnoreParenthesisImplicitCasts()));
  b.setVal24(es.EntityId(e.IgnoreParenthesisLValueCasts()));
  b.setVal25(es.EntityId(e.IgnoreParenthesisNoopCasts()));
  b.setVal33(es.EntityId(e.IgnoreParentheses()));
  b.setVal34(es.EntityId(e.IgnoreUnlessSpelledInSource()));
  b.setVal19(e.ContainsErrors());
  b.setVal26(e.ContainsUnexpandedParameterPack());
  b.setVal35(es.EntityId(e.BestDynamicClassTypeExpression()));
  b.setVal59(static_cast<unsigned char>(mx::FromPasta(e.Dependence())));
  auto t36 = e.ExpressionToken();
  b.setVal36(es.EntityId(t36));
  auto v37 = e.ObjCProperty();
  if (v37) {
    auto id37 = es.EntityId(v37.value());
    b.setVal37(id37);
  } else {
    b.setVal37(mx::kInvalidEntityId);
  }
  b.setVal72(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
  auto v38 = e.ReferencedDeclarationOfCallee();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto v39 = e.SourceBitField();
  if (v39) {
    auto id39 = es.EntityId(v39.value());
    b.setVal39(id39);
  } else {
    b.setVal39(mx::kInvalidEntityId);
  }
  auto v40 = e.Type();
  if (v40) {
    auto id40 = es.EntityId(v40.value());
    b.setVal40(id40);
  } else {
    b.setVal40(mx::kInvalidEntityId);
  }
  b.setVal73(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
  b.setVal27(e.HasNonTrivialCall());
  auto v28 = e.IsCXX98IntegralConstantExpression();
  if (v28) {
    b.setVal28(static_cast<bool>(v28.value()));
    b.setVal60(true);
  } else {
    b.setVal60(false);
  }
  b.setVal61(e.IsDefaultArgument());
  b.setVal62(e.IsGLValue());
  b.setVal74(e.IsImplicitCXXThis());
  b.setVal75(e.IsInstantiationDependent());
  auto v76 = e.IsIntegerConstantExpression();
  if (v76) {
    b.setVal76(static_cast<bool>(v76.value()));
    b.setVal77(true);
  } else {
    b.setVal77(false);
  }
  b.setVal78(e.IsKnownToHaveBooleanValue());
  b.setVal79(e.IsLValue());
  b.setVal80(e.IsOBJCGCCandidate());
  b.setVal81(e.IsObjCSelfExpression());
  b.setVal82(e.IsOrdinaryOrBitFieldObject());
  b.setVal83(e.IsPRValue());
  b.setVal84(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal85(e.IsTypeDependent());
  b.setVal86(e.IsValueDependent());
  b.setVal87(e.IsXValue());
  b.setVal88(e.RefersToBitField());
  b.setVal89(e.RefersToGlobalRegisterVariable());
  b.setVal90(e.RefersToMatrixElement());
  b.setVal91(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.Designators();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  if (auto r41 = e.DesignatorsSourceRange(); auto rs41 = r41.Size()) {
    b.setVal41(es.EntityId(r41[0]));
    b.setVal42(es.EntityId(r41[rs41 - 1u]));
  } else {
    b.setVal41(0);
    b.setVal42(0);
  }
  auto t43 = e.EqualOrColonToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.Initializer()));
  b.setVal92(e.IsDirectInitializer());
  b.setVal93(e.UsesGNUSyntax());
  do {
    auto v29 = e.SubExpressions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
}

void SerializeDependentScopeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.LAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RAngleToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.TemplateKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal92(e.HasExplicitTemplateArguments());
  b.setVal93(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.KeywordToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Operand()));
  b.setVal43(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Declaration()));
  b.setVal42(es.EntityId(e.FoundDeclaration()));
  auto t43 = e.LAngleToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RAngleToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.TemplateKeywordToken();
  b.setVal45(es.EntityId(t45));
  b.setVal92(e.HadMultipleCandidates());
  b.setVal93(e.HasExplicitTemplateArguments());
  b.setVal94(e.HasQualifier());
  b.setVal95(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal96(e.HasTemplateKeyword());
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal98(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.CommonExpression()));
  auto t42 = e.KeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.OpaqueValue()));
  b.setVal44(es.EntityId(e.Operand()));
  b.setVal45(es.EntityId(e.ReadyExpression()));
  b.setVal46(es.EntityId(e.ResumeExpression()));
  b.setVal47(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
  b.setVal92(e.IsImplicit());
}

void SerializeCoyieldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SpecializationDeclaration()));
  do {
    auto v18 = e.TemplateArguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal92(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Initializer()));
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal92(e.IsFileScope());
}

void SerializeChooseExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.ChosenSubExpression()));
  b.setVal43(es.EntityId(e.Condition()));
  b.setVal44(es.EntityId(e.LHS()));
  b.setVal45(es.EntityId(e.RHS()));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
  b.setVal92(e.IsConditionDependent());
  b.setVal93(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
}

void SerializeCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v63 = e.CastKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto v41 = e.ConversionFunction();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.SubExpression()));
  b.setVal43(es.EntityId(e.SubExpressionAsWritten()));
  auto v44 = e.TargetUnionField();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  b.setVal92(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal93(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  if (auto r46 = e.AngleBrackets(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
  }
  auto v68 = e.CastName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto t48 = e.OperatorToken();
  b.setVal48(es.EntityId(t48));
  auto t49 = e.RParenToken();
  b.setVal49(es.EntityId(t49));
}

void SerializeCXXDynamicCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
  b.setVal93(e.IsAlwaysNull());
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
  auto t46 = e.LParenToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.RParenToken();
  b.setVal47(es.EntityId(t47));
  b.setVal93(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t46 = e.LParenToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.RParenToken();
  b.setVal47(es.EntityId(t47));
}

void SerializeBuiltinBitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t46 = e.BridgeKeywordToken();
  b.setVal46(es.EntityId(t46));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v68 = e.BridgeKindName();
  std::string s68(v68.data(), v68.size());
  b.setVal68(s68);
  auto t47 = e.LParenToken();
  b.setVal47(es.EntityId(t47));
}

void SerializeCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.Arguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
  b.setVal41(es.EntityId(e.CallReturnType()));
  b.setVal42(es.EntityId(e.Callee()));
  auto v43 = e.CalleeDeclaration();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto v44 = e.DirectCallee();
  if (v44) {
    auto id44 = es.EntityId(v44.value());
    b.setVal44(id44);
  } else {
    b.setVal44(mx::kInvalidEntityId);
  }
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  auto v46 = e.UnusedResultAttribute();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal92(e.HasStoredFPFeatures());
  b.setVal93(e.HasUnusedResultAttribute());
  b.setVal94(e.IsBuiltinAssumeFalse());
  b.setVal95(e.IsCallToStdMove());
  b.setVal96(e.IsUnevaluatedBuiltinCall());
  b.setVal98(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t47 = e.OperatorToken();
  b.setVal47(es.EntityId(t47));
  b.setVal100(e.IsAssignmentOperation());
  b.setVal101(e.IsComparisonOperation());
  b.setVal102(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.ImplicitObjectArgument()));
  auto v48 = e.MethodDeclaration();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  b.setVal49(es.EntityId(e.ObjectType()));
  b.setVal50(es.EntityId(e.RecordDeclaration()));
}

void SerializeCUDAKernelCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.CookedLiteral()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t48 = e.UDSuffixToken();
  b.setVal48(es.EntityId(t48));
}

void SerializeCXXUuidofExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.ExpressionOperand();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.GuidDeclaration()));
  b.setVal43(es.EntityId(e.TypeOperand()));
  b.setVal44(es.EntityId(e.TypeOperandSourceInfo()));
  b.setVal92(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.Arguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.TypeAsWritten()));
  b.setVal92(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.ExpressionOperand();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.TypeOperand()));
  b.setVal43(es.EntityId(e.TypeOperandSourceInfo()));
  auto v92 = e.IsMostDerived();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.IsPotentiallyEvaluated());
  b.setVal95(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.SubExpression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto t42 = e.ThrowToken();
  b.setVal42(es.EntityId(t42));
  b.setVal92(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeCXXRewrittenBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.RHS()));
  b.setVal44(es.EntityId(e.SemanticForm()));
  b.setVal92(e.IsAssignmentOperation());
  b.setVal93(e.IsComparisonOperation());
  b.setVal94(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  auto t42 = e.ColonColonToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.DestroyedType()));
  auto t44 = e.DestroyedTypeToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto v46 = e.ScopeType();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  auto t47 = e.TildeToken();
  b.setVal47(es.EntityId(t47));
  b.setVal92(e.HasQualifier());
  b.setVal93(e.IsArrow());
}

void SerializeCXXParenListInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXParenListInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ArrayFiller()));
  auto t42 = e.InitializerToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.InitializedFieldInUnion()));
}

void SerializeCXXNullPtrLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
}

void SerializeCXXNoexceptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Operand()));
  b.setVal92(e.Value());
}

void SerializeCXXNewExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.DoesUsualArrayDeleteWantSize());
  b.setVal41(es.EntityId(e.AllocatedType()));
  auto v42 = e.ArraySize();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto v43 = e.ConstructExpression();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  if (auto r44 = e.DirectInitializerRange(); auto rs44 = r44.Size()) {
    b.setVal44(es.EntityId(r44[0]));
    b.setVal45(es.EntityId(r44[rs44 - 1u]));
  } else {
    b.setVal44(0);
    b.setVal45(0);
  }
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
  auto v46 = e.Initializer();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal47(es.EntityId(e.OperatorDelete()));
  b.setVal48(es.EntityId(e.OperatorNew()));
  if (auto r49 = e.TypeIdParentheses(); auto rs49 = r49.Size()) {
    b.setVal49(es.EntityId(r49[0]));
    b.setVal50(es.EntityId(r49[rs49 - 1u]));
  } else {
    b.setVal49(0);
    b.setVal50(0);
  }
  b.setVal93(e.HasInitializer());
  b.setVal94(e.IsArray());
  b.setVal95(e.IsGlobalNew());
  b.setVal96(e.IsParenthesisTypeId());
  b.setVal98(e.PassAlignment());
  do {
    auto v18 = e.PlacementArguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal100(e.ShouldNullCheckAllocation());
}

void SerializeCXXInheritedCtorInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.ConstructsVirtualBase());
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal41(es.EntityId(e.Constructor()));
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
  b.setVal93(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Callee()));
  auto t42 = e.EllipsisToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.Initializer()));
  b.setVal44(es.EntityId(e.LHS()));
  auto t45 = e.LParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal46(es.EntityId(e.Pattern()));
  b.setVal47(es.EntityId(e.RHS()));
  auto t48 = e.RParenToken();
  b.setVal48(es.EntityId(t48));
  b.setVal92(e.IsLeftFold());
  b.setVal93(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.Base();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.BaseType()));
  auto v43 = e.FirstQualifierFoundInScope();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto t44 = e.LAngleToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.MemberToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.RAngleToken();
  b.setVal47(es.EntityId(t47));
  auto t48 = e.TemplateKeywordToken();
  b.setVal48(es.EntityId(t48));
  b.setVal92(e.HasExplicitTemplateArguments());
  b.setVal93(e.HasTemplateKeyword());
  b.setVal94(e.IsArrow());
  b.setVal95(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.DoesUsualArrayDeleteWantSize());
  b.setVal41(es.EntityId(e.Argument()));
  b.setVal42(es.EntityId(e.DestroyedType()));
  b.setVal43(es.EntityId(e.OperatorDelete()));
  b.setVal93(e.IsArrayForm());
  b.setVal94(e.IsArrayFormAsWritten());
  b.setVal95(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.Expression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  b.setVal42(es.EntityId(e.Field()));
  b.setVal43(es.EntityId(e.RewrittenExpression()));
  auto t44 = e.UsedToken();
  b.setVal44(es.EntityId(t44));
  b.setVal92(e.HasRewrittenInitializer());
}

void SerializeCXXDefaultArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.AdjustedRewrittenExpression()));
  b.setVal42(es.EntityId(e.Expression()));
  b.setVal43(es.EntityId(e.Parameter()));
  b.setVal44(es.EntityId(e.RewrittenExpression()));
  auto t45 = e.UsedToken();
  b.setVal45(es.EntityId(t45));
  b.setVal92(e.HasRewrittenInitializer());
}

void SerializeCXXConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.Arguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal41(es.EntityId(e.Constructor()));
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
  if (auto r43 = e.ParenthesisOrBraceRange(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  b.setVal92(e.HadMultipleCandidates());
  b.setVal93(e.IsElidable());
  b.setVal94(e.IsListInitialization());
  b.setVal95(e.IsStdInitializerListInitialization());
  b.setVal96(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  SerializeCXXConstructExpr(es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.Value());
}

void SerializeCXXBindTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.BlockDeclaration()));
  b.setVal42(es.EntityId(e.Body()));
  auto t43 = e.CaretToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v63 = e.OpcodeString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto t42 = e.OperatorToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.RHS()));
  b.setVal92(e.HasStoredFPFeatures());
  b.setVal93(e.IsAdditiveOperation());
  b.setVal94(e.IsAssignmentOperation());
  b.setVal95(e.IsBitwiseOperation());
  b.setVal96(e.IsCommaOperation());
  b.setVal98(e.IsComparisonOperation());
  b.setVal100(e.IsCompoundAssignmentOperation());
  b.setVal101(e.IsEqualityOperation());
  b.setVal102(e.IsLogicalOperation());
  b.setVal103(e.IsMultiplicativeOperation());
  b.setVal104(e.IsPointerMemoryOperation());
  b.setVal105(e.IsRelationalOperation());
  b.setVal106(e.IsShiftAssignOperation());
  b.setVal107(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  SerializeBinaryOperator(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.ComputationLHSType()));
  b.setVal45(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
  b.setVal42(es.EntityId(e.Order()));
  auto v43 = e.OrderFail();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  b.setVal44(es.EntityId(e.Pointer()));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  auto v46 = e.Scope();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  auto v47 = e.Value1();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  auto v48 = e.Value2();
  if (v48) {
    auto id48 = es.EntityId(v48.value());
    b.setVal48(id48);
  } else {
    b.setVal48(mx::kInvalidEntityId);
  }
  b.setVal49(es.EntityId(e.ValueType()));
  auto v50 = e.Weak();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal92(e.IsCmpXChg());
  b.setVal93(e.IsOpenCL());
  b.setVal94(e.IsVolatile());
  do {
    auto v18 = e.SubExpressions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeAsTypeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.DimensionExpression()));
  b.setVal42(es.EntityId(e.QueriedType()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.Index()));
  b.setVal43(es.EntityId(e.LHS()));
  auto t44 = e.RBracketToken();
  b.setVal44(es.EntityId(t44));
  b.setVal45(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.CommonExpression()));
  b.setVal42(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AmpAmpToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Label()));
  auto t43 = e.LabelToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeAbstractConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.ColonToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Condition()));
  b.setVal43(es.EntityId(e.FalseExpression()));
  auto t44 = e.QuestionToken();
  b.setVal44(es.EntityId(t44));
  b.setVal45(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal46(es.EntityId(e.LHS()));
  b.setVal47(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal46(es.EntityId(e.Common()));
  b.setVal47(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.SubExpression()));
  b.setVal44(es.EntityId(e.WrittenType()));
  b.setVal92(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.CanOverflow());
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.SubExpression()));
  b.setVal93(e.HasStoredFPFeatures());
  b.setVal94(e.IsArithmeticOperation());
  b.setVal95(e.IsDecrementOperation());
  b.setVal96(e.IsIncrementDecrementOperation());
  b.setVal98(e.IsIncrementOperation());
  b.setVal100(e.IsPostfix());
  b.setVal101(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.ArgumentExpression();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.ArgumentType();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t43 = e.OperatorToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal45(es.EntityId(e.TypeOfArgument()));
  b.setVal92(e.IsArgumentType());
}

void SerializeTypoExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v92 = e.Value();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  do {
    auto v18 = e.Arguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeSubstNonTypeTemplateParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.AssociatedDeclaration()));
  b.setVal42(es.EntityId(e.ParameterPack()));
  auto t43 = e.ParameterPackToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeSubstNonTypeTemplateParmExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.AssociatedDeclaration()));
  auto t42 = e.NameToken();
  b.setVal42(es.EntityId(t42));
  auto v108 = e.PackIndex();
  if (v108) {
    b.setVal108(static_cast<unsigned>(v108.value()));
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  b.setVal43(es.EntityId(e.Parameter()));
  b.setVal44(es.EntityId(e.ParameterType()));
  b.setVal45(es.EntityId(e.Replacement()));
  b.setVal93(e.IsReferenceParameter());
}

void SerializeStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v92 = e.ContainsNonAscii();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  auto v94 = e.ContainsNonAsciiOrNull();
  if (v94) {
    b.setVal94(static_cast<bool>(v94.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  auto v63 = e.Bytes();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto v68 = e.String();
  if (v68) {
    if (v68->empty()) {
      b.setVal68("");
    } else {
      std::string s68(v68->data(), v68->size());
      b.setVal68(s68);
    }
    b.setVal96(true);
  } else {
    b.setVal96(false);
  }
  b.setVal98(e.IsOrdinary());
  b.setVal100(e.IsPascal());
  b.setVal101(e.IsUTF16());
  b.setVal102(e.IsUTF32());
  b.setVal103(e.IsUTF8());
  b.setVal104(e.IsWide());
}

void SerializeStmtExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v63 = e.BuiltinString();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.IsIntType());
}

void SerializeSizeOfPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Pack()));
  auto v108 = e.PackLength();
  if (v108) {
    b.setVal108(static_cast<unsigned>(v108.value()));
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  auto t43 = e.PackToken();
  b.setVal43(es.EntityId(t43));
  do {
    auto ov18 = e.PartialArguments();
    if (!ov18) {
      b.setVal93(false);
      break;
    }
    b.setVal93(true);
    auto v18 = std::move(*ov18);
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal94(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.BuiltinToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeSYCLUniqueStableNameExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal63(e.ComputeName());
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeRequiresExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Body()));
  do {
    auto v18 = e.LocalParameters();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  auto t42 = e.RBraceToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RequiresKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal92(e.IsSatisfied());
}

void SerializeRecoveryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.SubExpressions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializePseudoObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ResultExpression()));
  b.setVal42(es.EntityId(e.SyntacticForm()));
  do {
    auto v18 = e.Semantics();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  do {
    auto v29 = e.SemanticExpressions();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
}

void SerializePredefinedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.FunctionName()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v63 = e.IdentifierKindName();
  std::string s63(v63.data(), v63.size());
  b.setVal63(s63);
  auto t42 = e.Token();
  b.setVal42(es.EntityId(t42));
}

void SerializeParenListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  do {
    auto v18 = e.Expressions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeParenExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.LParenToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.EllipsisToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.LAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.NameToken();
  b.setVal42(es.EntityId(t42));
  auto v43 = e.NamingClass();
  if (v43) {
    auto id43 = es.EntityId(v43.value());
    b.setVal43(id43);
  } else {
    b.setVal43(mx::kInvalidEntityId);
  }
  auto t44 = e.RAngleToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.TemplateKeywordToken();
  b.setVal45(es.EntityId(t45));
  b.setVal92(e.HasExplicitTemplateArguments());
  b.setVal93(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal46(es.EntityId(e.Base()));
  b.setVal47(es.EntityId(e.BaseType()));
  auto t48 = e.MemberToken();
  b.setVal48(es.EntityId(t48));
  auto t49 = e.OperatorToken();
  b.setVal49(es.EntityId(t49));
  b.setVal94(e.HasUnresolvedUsing());
  b.setVal95(e.IsArrow());
  b.setVal96(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal94(e.IsOverloaded());
  b.setVal95(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.SourceExpression()));
  b.setVal92(e.IsUnique());
}

void SerializeOffsetOfExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.OperatorToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeObjCSubscriptRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal42(es.EntityId(e.BaseExpression()));
  b.setVal43(es.EntityId(e.KeyExpression()));
  auto t44 = e.RBracketToken();
  b.setVal44(es.EntityId(t44));
  b.setVal92(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AtToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AtToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.RParenToken();
  b.setVal42(es.EntityId(t42));
}

void SerializeObjCProtocolExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AtToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Protocol()));
  auto t43 = e.ProtocolIdToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeObjCPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.ClassReceiver()));
  b.setVal43(es.EntityId(e.ExplicitProperty()));
  b.setVal44(es.EntityId(e.ImplicitPropertyGetter()));
  b.setVal45(es.EntityId(e.ImplicitPropertySetter()));
  auto t46 = e.Token();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.ReceiverToken();
  b.setVal47(es.EntityId(t47));
  b.setVal48(es.EntityId(e.ReceiverType()));
  b.setVal49(es.EntityId(e.SuperReceiverType()));
  b.setVal92(e.IsClassReceiver());
  b.setVal93(e.IsExplicitProperty());
  b.setVal94(e.IsImplicitProperty());
  b.setVal95(e.IsMessagingGetter());
  b.setVal96(e.IsMessagingSetter());
  b.setVal98(e.IsObjectReceiver());
  b.setVal100(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.Arguments();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal41(es.EntityId(e.CallReturnType()));
  b.setVal42(es.EntityId(e.ClassReceiver()));
  b.setVal43(es.EntityId(e.ClassReceiverType()));
  b.setVal44(es.EntityId(e.InstanceReceiver()));
  auto t45 = e.LeftToken();
  b.setVal45(es.EntityId(t45));
  b.setVal46(es.EntityId(e.MethodDeclaration()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal47(es.EntityId(e.ReceiverInterface()));
  b.setVal99(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
  if (auto r48 = e.ReceiverRange(); auto rs48 = r48.Size()) {
    b.setVal48(es.EntityId(r48[0]));
    b.setVal49(es.EntityId(r48[rs48 - 1u]));
  } else {
    b.setVal48(0);
    b.setVal49(0);
  }
  b.setVal50(es.EntityId(e.ReceiverType()));
  auto t51 = e.RightToken();
  b.setVal51(es.EntityId(t51));
  auto t52 = e.SelectorStartToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.SuperToken();
  b.setVal53(es.EntityId(t53));
  b.setVal54(es.EntityId(e.SuperType()));
  b.setVal92(e.IsClassMessage());
  b.setVal93(e.IsDelegateInitializerCall());
  b.setVal94(e.IsImplicit());
  b.setVal95(e.IsInstanceMessage());
  do {
    auto v29 = e.SelectorTokens();
    auto sv29 = b.initVal29(static_cast<unsigned>(v29.size()));
    auto i29 = 0u;
    for (const auto &e29 : v29) {
      sv29.set(i29, es.EntityId(e29));
      ++i29;
    }
  } while (false);
}

void SerializeObjCIvarRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.Declaration()));
  auto t43 = e.Token();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.OperationToken();
  b.setVal44(es.EntityId(t44));
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  auto t42 = e.BaseTokenEnd();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.IsaMemberToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.OperationToken();
  b.setVal44(es.EntityId(t44));
  b.setVal92(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SubExpression()));
  b.setVal92(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AtToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.EncodedType()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeObjCDictionaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.AtToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.BoxingMethod()));
  b.setVal43(es.EntityId(e.SubExpression()));
  b.setVal92(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.HasVersion());
}

void SerializeObjCArrayLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ArrayWithObjectsMethod()));
  do {
    auto v18 = e.Elements();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeOMPIteratorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.IteratorKwToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeOMPArrayShapingExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  do {
    auto v18 = e.Dimensions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeOMPArraySectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  auto t42 = e.FirstColonToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.SecondColonToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.Length()));
  b.setVal45(es.EntityId(e.LowerBound()));
  auto t46 = e.RBracketToken();
  b.setVal46(es.EntityId(t46));
  b.setVal47(es.EntityId(e.Stride()));
}

void SerializeNoInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  auto t42 = e.LAngleToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.MemberDeclaration()));
  auto t44 = e.MemberToken();
  b.setVal44(es.EntityId(t44));
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.RAngleToken();
  b.setVal46(es.EntityId(t46));
  auto t47 = e.TemplateKeywordToken();
  b.setVal47(es.EntityId(t47));
  b.setVal92(e.HadMultipleCandidates());
  b.setVal93(e.HasExplicitTemplateArguments());
  b.setVal94(e.HasQualifier());
  b.setVal95(e.HasTemplateKeyword());
  b.setVal96(e.IsArrow());
  b.setVal98(e.IsImplicitAccess());
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.ColumnIndex()));
  auto t43 = e.RBracketToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.RowIndex()));
  b.setVal92(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.ExtendingDeclaration();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.LifetimeExtendedTemporaryDeclaration();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal43(es.EntityId(e.SubExpression()));
  b.setVal92(e.IsBoundToLvalueReference());
  b.setVal93(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Base()));
  b.setVal42(es.EntityId(e.Index()));
  auto t43 = e.RBracketToken();
  b.setVal43(es.EntityId(t43));
}

void SerializeMSPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.BaseExpression()));
  auto t42 = e.MemberToken();
  b.setVal42(es.EntityId(t42));
  b.setVal43(es.EntityId(e.PropertyDeclaration()));
  b.setVal92(e.IsArrow());
  b.setVal93(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.Body()));
  b.setVal42(es.EntityId(e.CallOperator()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t43 = e.CaptureDefaultToken();
  b.setVal43(es.EntityId(t43));
  b.setVal44(es.EntityId(e.CompoundStatementBody()));
  auto v45 = e.DependentCallOperator();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  do {
    auto v18 = e.ExplicitTemplateParameters();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  if (auto r46 = e.IntroducerRange(); auto rs46 = r46.Size()) {
    b.setVal46(es.EntityId(r46[0]));
    b.setVal47(es.EntityId(r46[rs46 - 1u]));
  } else {
    b.setVal46(0);
    b.setVal47(0);
  }
  b.setVal48(es.EntityId(e.LambdaClass()));
  auto v49 = e.TemplateParameterList();
  if (v49) {
    auto id49 = es.EntityId(v49.value());
    b.setVal49(id49);
  } else {
    b.setVal49(mx::kInvalidEntityId);
  }
  auto v50 = e.TrailingRequiresClause();
  if (v50) {
    auto id50 = es.EntityId(v50.value());
    b.setVal50(id50);
  } else {
    b.setVal50(mx::kInvalidEntityId);
  }
  b.setVal92(e.HasExplicitParameters());
  b.setVal93(e.HasExplicitResultType());
  b.setVal94(e.IsGenericLambda());
  b.setVal95(e.IsMutable());
}

void SerializeIntegerLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
}

void SerializeInitListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v41 = e.ArrayFiller();
  if (v41) {
    auto id41 = es.EntityId(v41.value());
    b.setVal41(id41);
  } else {
    b.setVal41(mx::kInvalidEntityId);
  }
  auto v42 = e.InitializedFieldInUnion();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
  }
  auto t43 = e.LBraceToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RBraceToken();
  b.setVal44(es.EntityId(t44));
  auto v45 = e.SemanticForm();
  if (v45) {
    auto id45 = es.EntityId(v45.value());
    b.setVal45(id45);
  } else {
    b.setVal45(mx::kInvalidEntityId);
  }
  auto v46 = e.SyntacticForm();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  b.setVal92(e.HadArrayRangeDesignator());
  b.setVal93(e.HasArrayFiller());
  do {
    auto v18 = e.Initializers();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal94(e.IsExplicit());
  b.setVal95(e.IsSemanticForm());
  b.setVal96(e.IsStringLiteralInitializer());
  b.setVal98(e.IsSyntacticForm());
  auto v100 = e.IsTransparent();
  if (v100) {
    b.setVal100(static_cast<bool>(v100.value()));
    b.setVal101(true);
  } else {
    b.setVal101(false);
  }
}

void SerializeImplicitValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v18 = e.AssociationExpressions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal41(es.EntityId(e.ControllingExpression()));
  auto t42 = e.DefaultToken();
  b.setVal42(es.EntityId(t42));
  auto t43 = e.GenericToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal45(es.EntityId(e.ResultExpression()));
  b.setVal92(e.IsResultDependent());
}

void SerializeGNUNullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.TokenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeFunctionParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ParameterPack()));
  auto t42 = e.ParameterPackToken();
  b.setVal42(es.EntityId(t42));
  do {
    auto v18 = e.Expansions();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
}

void SerializeFullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal92(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal92(e.HasAPValueResult());
  b.setVal93(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
  b.setVal92(e.IsExact());
}

void SerializeFixedPointLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t41 = e.Token();
  b.setVal41(es.EntityId(t41));
}

void SerializeExtVectorElementExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal92(e.ContainsDuplicateElements());
  auto t41 = e.AccessorToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.Base()));
  b.setVal93(e.IsArrow());
}

void SerializeExpressionTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.QueriedExpression()));
  b.setVal97(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal92(e.Value());
}

void SerializeAttributedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  auto t13 = e.AttributeToken();
  b.setVal13(es.EntityId(t13));
  do {
    auto v18 = e.Attributes();
    auto sv18 = b.initVal18(static_cast<unsigned>(v18.size()));
    auto i18 = 0u;
    for (const auto &e18 : v18) {
      sv18.set(i18, es.EntityId(e18));
      ++i18;
    }
  } while (false);
  b.setVal14(es.EntityId(e.SubStatement()));
}

void SerializeSwitchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal12(es.EntityId(e.Body()));
  b.setVal13(es.EntityId(e.Condition()));
  auto v14 = e.ConditionVariable();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  auto v16 = e.ConditionVariableDeclarationStatement();
  if (v16) {
    auto id16 = es.EntityId(v16.value());
    b.setVal16(id16);
  } else {
    b.setVal16(mx::kInvalidEntityId);
  }
  auto v17 = e.Initializer();
  if (v17) {
    auto id17 = es.EntityId(v17.value());
    b.setVal17(id17);
  } else {
    b.setVal17(mx::kInvalidEntityId);
  }
  auto t20 = e.LParenToken();
  b.setVal20(es.EntityId(t20));
  auto t21 = e.RParenToken();
  b.setVal21(es.EntityId(t21));
  auto v22 = e.FirstSwitchCase();
  if (v22) {
    auto id22 = es.EntityId(v22.value());
    b.setVal22(id22);
  } else {
    b.setVal22(mx::kInvalidEntityId);
  }
  auto t23 = e.SwitchToken();
  b.setVal23(es.EntityId(t23));
  b.setVal15(e.HasInitializerStorage());
  b.setVal19(e.HasVariableStorage());
  b.setVal26(e.IsAllEnumCasesCovered());
}

void SerializeSwitchCase(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t12 = e.ColonToken();
  b.setVal12(es.EntityId(t12));
  auto t13 = e.KeywordToken();
  b.setVal13(es.EntityId(t13));
  auto v14 = e.NextSwitchCase();
  if (v14) {
    auto id14 = es.EntityId(v14.value());
    b.setVal14(id14);
  } else {
    b.setVal14(mx::kInvalidEntityId);
  }
  b.setVal16(es.EntityId(e.SubStatement()));
}

void SerializeDefaultStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
  auto t17 = e.DefaultToken();
  b.setVal17(es.EntityId(t17));
}

void SerializeCaseStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
  b.setVal15(e.CaseStatementIsGNURange());
  auto t17 = e.CaseToken();
  b.setVal17(es.EntityId(t17));
  auto t20 = e.EllipsisToken();
  b.setVal20(es.EntityId(t20));
  b.setVal21(es.EntityId(e.LHS()));
  auto v22 = e.RHS();
  if (v22) {
    auto id22 = es.EntityId(v22.value());
    b.setVal22(id22);
  } else {
    b.setVal22(mx::kInvalidEntityId);
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
  b.setVal19(e.IsFileContextDeclaration());
  b.setVal20(e.IsFunctionOrFunctionTemplate());
  b.setVal21(e.IsImplicit());
  b.setVal22(e.IsInAnonymousNamespace());
  b.setVal23(e.IsInExportDeclarationContext());
  b.setVal24(e.IsInLocalScopeForInstantiation());
  b.setVal25(e.IsInStdNamespace());
  b.setVal26(e.IsInvalidDeclaration());
  b.setVal27(e.IsInvisibleOutsideTheOwningModule());
  b.setVal28(e.IsLocalExternDeclaration());
  b.setVal29(e.IsModulePrivate());
  b.setVal30(e.IsOutOfLine());
  b.setVal31(e.IsParameterPack());
  b.setVal32(e.IsReachable());
  b.setVal33(e.IsTemplateDeclaration());
  b.setVal34(e.IsTemplateParameter());
  b.setVal35(e.IsTemplateParameterPack());
  b.setVal36(e.IsTemplated());
  b.setVal37(e.IsThisDeclarationReferenced());
  b.setVal38(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal39(e.IsUnavailable());
  b.setVal40(e.IsUnconditionallyVisible());
  b.setVal41(e.IsWeakImported());
  b.setVal42(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal43(static_cast<unsigned char>(mx::FromPasta(e.Category())));
  auto t44 = e.Token();
  b.setVal44(es.EntityId(t44));
  if (auto r45 = e.Tokens(); auto rs45 = r45.Size()) {
    b.setVal45(es.EntityId(r45[0]));
    b.setVal46(es.EntityId(r45[rs45 - 1u]));
  } else {
    b.setVal45(0);
    b.setVal46(0);
  }
}

void SerializeClassScopeFunctionSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.Specialization()));
  b.setVal48(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.ContextParameter()));
  b.setVal48(e.IsNothrow());
  do {
    auto v49 = e.Parameters();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
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

void SerializeBlockDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal48(e.BlockMissingReturnType());
  b.setVal51(e.CanAvoidCopyToHeap());
  b.setVal52(e.CapturesCXXThis());
  b.setVal53(e.DoesNotEscape());
  auto v47 = e.BlockManglingContextDeclaration();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  auto t54 = e.CaretToken();
  b.setVal54(es.EntityId(t54));
  b.setVal55(es.EntityId(e.CompoundBody()));
  b.setVal56(es.EntityId(e.SignatureAsWritten()));
  b.setVal57(e.HasCaptures());
  b.setVal58(e.IsConversionFromLambda());
  b.setVal59(e.IsVariadic());
  do {
    auto v49 = e.Parameters();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  do {
    auto v50 = e.ParameterDeclarations();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  pasta::DeclContext dc60(e);
  auto v60 = dc60.AlreadyLoadedDeclarations();
  auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
  auto i60 = 0u;
  for (const pasta::Decl &e60 : v60) {
    sv60.set(i60, es.EntityId(e60));
    ++i60;
  }
}

void SerializeAccessSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t47 = e.AccessSpecifierToken();
  b.setVal47(es.EntityId(t47));
  auto t54 = e.ColonToken();
  b.setVal54(es.EntityId(t54));
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
    auto v49 = e.Varlists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
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
    auto v49 = e.Varlists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializeTopLevelStmtDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TopLevelStmtDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.Statement()));
}

void SerializeStaticAssertDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.AssertExpression()));
  b.setVal54(es.EntityId(e.Message()));
  auto t55 = e.RParenToken();
  b.setVal55(es.EntityId(t55));
  b.setVal48(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializePragmaDetectMismatchDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v61 = e.Name();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  auto v62 = e.Value();
  std::string s62(v62.data(), v62.size());
  b.setVal62(s62);
}

void SerializePragmaCommentDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v61 = e.Argument();
  std::string s61(v61.data(), v61.size());
  b.setVal61(s61);
  b.setVal63(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.GetterCXXConstructor()));
  b.setVal54(es.EntityId(e.GetterMethodDeclaration()));
  b.setVal55(es.EntityId(e.PropertyDeclaration()));
  b.setVal63(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal56(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  auto t64 = e.PropertyInstanceVariableDeclarationToken();
  b.setVal64(es.EntityId(t64));
  b.setVal65(es.EntityId(e.SetterCXXAssignment()));
  b.setVal66(es.EntityId(e.SetterMethodDeclaration()));
  b.setVal48(e.IsInstanceVariableNameSpecified());
}

void SerializeNamedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal63(static_cast<unsigned char>(mx::FromPasta(e.FormalLinkage())));
  b.setVal61(e.Name());
  auto v67 = e.ObjCFStringFormattingFamily();
  if (v67) {
    b.setVal67(static_cast<unsigned char>(v67.value()));
    b.setVal48(true);
  } else {
    b.setVal48(false);
  }
  b.setVal62(e.QualifiedNameAsString());
  b.setVal47(es.EntityId(e.UnderlyingDeclaration()));
  b.setVal68(static_cast<unsigned char>(mx::FromPasta(e.Visibility())));
  b.setVal51(e.HasExternalFormalLinkage());
  b.setVal52(e.HasLinkage());
  b.setVal53(e.HasLinkageBeenComputed());
  b.setVal57(e.IsCXXClassMember());
  b.setVal58(e.IsCXXInstanceMember());
  b.setVal59(e.IsExternallyDeclarable());
  b.setVal69(e.IsExternallyVisible());
  b.setVal70(e.IsLinkageValid());
}

void SerializeLabelDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v71 = e.MSAssemblyLabel();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  b.setVal54(es.EntityId(e.Statement()));
  b.setVal72(e.IsGnuLocal());
  b.setVal73(e.IsMSAssemblyLabel());
  b.setVal74(e.IsResolvedMSAssemblyLabel());
}

void SerializeHLSLBufferDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::HLSLBufferDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t54 = e.LBraceToken();
  b.setVal54(es.EntityId(t54));
  auto t55 = e.TokenStart();
  b.setVal55(es.EntityId(t55));
  auto t56 = e.RBraceToken();
  b.setVal56(es.EntityId(t56));
  b.setVal72(e.IsCBuffer());
}

void SerializeBaseUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v49 = e.Shadows();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeUsingEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  b.setVal54(es.EntityId(e.EnumDeclaration()));
  auto t55 = e.EnumToken();
  b.setVal55(es.EntityId(t55));
  b.setVal56(es.EntityId(e.EnumType()));
  auto t64 = e.UsingToken();
  b.setVal64(es.EntityId(t64));
}

void SerializeUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  auto t54 = e.UsingToken();
  b.setVal54(es.EntityId(t54));
  b.setVal72(e.HasTypename());
  b.setVal73(e.IsAccessDeclaration());
}

void SerializeValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v54 = e.PotentiallyDecomposedVariableDeclaration();
  if (v54) {
    auto id54 = es.EntityId(v54.value());
    b.setVal54(id54);
  } else {
    b.setVal54(mx::kInvalidEntityId);
  }
  b.setVal55(es.EntityId(e.Type()));
  b.setVal72(e.IsInitializerCapture());
  b.setVal73(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto t56 = e.EllipsisToken();
  b.setVal56(es.EntityId(t56));
  auto t64 = e.UsingToken();
  b.setVal64(es.EntityId(t64));
  b.setVal74(e.IsAccessDeclaration());
  b.setVal75(e.IsPackExpansion());
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
  b.setVal56(es.EntityId(e.Combiner()));
  b.setVal64(es.EntityId(e.CombinerIn()));
  b.setVal65(es.EntityId(e.CombinerOut()));
  b.setVal66(es.EntityId(e.InitializerOriginal()));
  b.setVal76(es.EntityId(e.InitializerPrivate()));
  b.setVal77(es.EntityId(e.Initializer()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InitializerKind())));
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
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
    auto v49 = e.Chain();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  auto v56 = e.AnonymousField();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  auto v64 = e.VariableDeclaration();
  if (v64) {
    auto id64 = es.EntityId(v64.value());
    b.setVal64(id64);
  } else {
    b.setVal64(mx::kInvalidEntityId);
  }
}

void SerializeEnumConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto v56 = e.InitializerExpression();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto t56 = e.FirstInnerToken();
  b.setVal56(es.EntityId(t56));
  auto t64 = e.FirstOuterToken();
  b.setVal64(es.EntityId(t64));
  auto v65 = e.TrailingRequiresClause();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
  auto t66 = e.TypeSpecEndToken();
  b.setVal66(es.EntityId(t66));
  auto t76 = e.TypeSpecStartToken();
  b.setVal76(es.EntityId(t76));
  do {
    auto v49 = e.TemplateParameterLists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v77 = e.ActingDefinition();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v79 = e.DescribedVariableTemplate();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v80 = e.Initializer();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InitializerStyle())));
  auto v81 = e.InitializingDeclaration();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto v82 = e.InstantiatedFromStaticDataMember();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  auto t84 = e.PointOfInstantiation();
  b.setVal84(es.EntityId(t84));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TLSKind())));
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.TSCSpec())));
  auto v89 = e.TemplateInstantiationPattern();
  if (v89) {
    auto id89 = es.EntityId(v89.value());
    b.setVal89(id89);
  } else {
    b.setVal89(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal74(e.HasConstantInitialization());
  b.setVal75(e.HasDependentAlignment());
  b.setVal92(e.HasExternalStorage());
  auto v93 = e.HasFlexibleArrayInitializer();
  if (v93) {
    b.setVal93(static_cast<bool>(v93.value()));
    b.setVal94(true);
  } else {
    b.setVal94(false);
  }
  b.setVal95(e.HasGlobalStorage());
  auto v96 = e.HasICEInitializer();
  if (v96) {
    b.setVal96(static_cast<bool>(v96.value()));
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
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

void SerializeParmVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
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
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
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

void SerializeVarTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  auto t126 = e.ExternToken();
  b.setVal126(es.EntityId(t126));
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal127(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v50 = e.TemplateArguments();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  do {
    auto v60 = e.TemplateInstantiationArguments();
    auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
    auto i60 = 0u;
    for (const auto &e60 : v60) {
      sv60.set(i60, es.EntityId(e60));
      ++i60;
    }
  } while (false);
  auto t128 = e.TemplateKeywordToken();
  b.setVal128(es.EntityId(t128));
  b.setVal130(es.EntityId(e.TypeAsWritten()));
  b.setVal132(e.IsClassScopeExplicitSpecialization());
  b.setVal133(e.IsExplicitInstantiationOrSpecialization());
  b.setVal134(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal131(es.EntityId(e.InstantiatedFromMember()));
  b.setVal139(es.EntityId(e.TemplateParameters()));
  b.setVal135(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal74(e.DefaultArgumentWasInherited());
  auto v77 = e.DefaultArgument();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto t79 = e.DefaultArgumentToken();
  b.setVal79(es.EntityId(t79));
  auto v80 = e.PlaceholderTypeConstraint();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  b.setVal75(e.HasDefaultArgument());
  b.setVal92(e.HasPlaceholderTypeConstraint());
  b.setVal93(e.IsExpandedParameterPack());
  b.setVal94(e.IsPackExpansion());
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

void SerializeMSPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal74(e.HasGetter());
  b.setVal75(e.HasSetter());
}

void SerializeFunctionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal74(e.FriendConstraintRefersToEnclosingTemplate());
  b.setVal75(e.UsesFPIntrin());
  auto v92 = e.DoesDeclarationForceExternallyVisibleDefinition();
  if (v92) {
    b.setVal92(static_cast<bool>(v92.value()));
    b.setVal93(true);
  } else {
    b.setVal93(false);
  }
  b.setVal94(e.DoesThisDeclarationHaveABody());
  b.setVal77(es.EntityId(e.CallResultType()));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ConstexprKind())));
  b.setVal79(es.EntityId(e.DeclaredReturnType()));
  auto t80 = e.DefaultToken();
  b.setVal80(es.EntityId(t80));
  auto v81 = e.DescribedFunctionTemplate();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto t82 = e.EllipsisToken();
  b.setVal82(es.EntityId(t82));
  if (auto r84 = e.ExceptionSpecSourceRange(); auto rs84 = r84.Size()) {
    b.setVal84(es.EntityId(r84[0]));
    b.setVal89(es.EntityId(r84[rs84 - 1u]));
  } else {
    b.setVal84(0);
    b.setVal89(0);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
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
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v140 = e.ODRHash();
  if (v140) {
    b.setVal140(static_cast<unsigned>(v140.value()));
    b.setVal95(true);
  } else {
    b.setVal95(false);
  }
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r128 = e.ParametersSourceRange(); auto rs128 = r128.Size()) {
    b.setVal128(es.EntityId(r128[0]));
    b.setVal130(es.EntityId(r128[rs128 - 1u]));
  } else {
    b.setVal128(0);
    b.setVal130(0);
  }
  auto t131 = e.PointOfInstantiation();
  b.setVal131(es.EntityId(t131));
  auto v139 = e.PrimaryTemplate();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
  } else {
    b.setVal139(mx::kInvalidEntityId);
  }
  b.setVal141(es.EntityId(e.ReturnType()));
  if (auto r142 = e.ReturnTypeSourceRange(); auto rs142 = r142.Size()) {
    b.setVal142(es.EntityId(r142[0]));
    b.setVal143(es.EntityId(r142[rs142 - 1u]));
  } else {
    b.setVal142(0);
    b.setVal143(0);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v144 = e.TemplateInstantiationPattern();
  if (v144) {
    auto id144 = es.EntityId(v144.value());
    b.setVal144(id144);
  } else {
    b.setVal144(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal129(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
  b.setVal96(e.HasImplicitReturnZero());
  b.setVal97(e.HasInheritedPrototype());
  b.setVal98(e.HasOneParameterOrDefaultArguments());
  b.setVal99(e.HasPrototype());
  b.setVal100(e.HasSkippedBody());
  b.setVal101(e.HasTrivialBody());
  b.setVal102(e.HasWrittenPrototype());
  b.setVal103(e.InstantiationIsPending());
  b.setVal104(e.IsCPUDispatchMultiVersion());
  b.setVal105(e.IsCPUSpecificMultiVersion());
  b.setVal106(e.IsConsteval());
  b.setVal107(e.IsConstexpr());
  b.setVal108(e.IsConstexprSpecified());
  b.setVal109(e.IsDefaulted());
  b.setVal110(e.IsDeleted());
  b.setVal111(e.IsDeletedAsWritten());
  b.setVal112(e.IsDestroyingOperatorDelete());
  b.setVal113(e.IsExplicitlyDefaulted());
  b.setVal114(e.IsExternC());
  b.setVal115(e.IsFunctionTemplateSpecialization());
  b.setVal116(e.IsGlobal());
  b.setVal117(e.IsImplicitlyInstantiable());
  b.setVal118(e.IsInExternCContext());
  b.setVal119(e.IsInExternCXXContext());
  b.setVal120(e.IsIneligibleOrNotSelected());
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
  b.setVal132(e.IsLateTemplateParsed());
  auto v133 = e.IsMSExternInline();
  if (v133) {
    b.setVal133(static_cast<bool>(v133.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  b.setVal135(e.IsMSVCRTEntryPoint());
  b.setVal136(e.IsMain());
  b.setVal137(e.IsMultiVersion());
  b.setVal138(e.IsNoReturn());
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
  b.setVal151(e.IsTargetClonesMultiVersion());
  b.setVal152(e.IsTargetMultiVersion());
  b.setVal153(e.IsTemplateInstantiation());
  b.setVal154(e.IsThisDeclarationADefinition());
  b.setVal155(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal156(e.IsTrivial());
  b.setVal157(e.IsTrivialForCall());
  b.setVal158(e.IsUserProvided());
  b.setVal159(e.IsVariadic());
  b.setVal160(e.IsVirtualAsWritten());
  do {
    auto v50 = e.Parameters();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  b.setVal161(e.UsesSEHTry());
  b.setVal162(e.WillHaveBody());
  auto v163 = e.Body();
  if (v163) {
    auto id163 = es.EntityId(v163.value());
    b.setVal163(id163);
  } else {
    b.setVal163(mx::kInvalidEntityId);
  }
  pasta::DeclContext dc60(e);
  auto v60 = dc60.AlreadyLoadedDeclarations();
  auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
  auto i60 = 0u;
  for (const pasta::Decl &e60 : v60) {
    sv60.set(i60, es.EntityId(e60));
    ++i60;
  }
}

void SerializeCXXMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal164(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  auto v165 = e.ThisObjectType();
  if (v165) {
    auto id165 = es.EntityId(v165.value());
    b.setVal165(id165);
  } else {
    b.setVal165(mx::kInvalidEntityId);
  }
  auto v166 = e.ThisType();
  if (v166) {
    auto id166 = es.EntityId(v166.value());
    b.setVal166(id166);
  } else {
    b.setVal166(mx::kInvalidEntityId);
  }
  b.setVal167(e.HasInlineBody());
  b.setVal168(e.IsConst());
  b.setVal169(e.IsCopyAssignmentOperator());
  b.setVal170(e.IsInstance());
  b.setVal171(e.IsLambdaStaticInvoker());
  b.setVal172(e.IsMoveAssignmentOperator());
  b.setVal173(e.IsVirtual());
  b.setVal174(e.IsVolatile());
  do {
    auto v175 = e.OverriddenMethods();
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  auto v176 = e.OperatorDelete();
  if (v176) {
    auto id176 = es.EntityId(v176.value());
    b.setVal176(id176);
  } else {
    b.setVal176(mx::kInvalidEntityId);
  }
  auto v177 = e.OperatorDeleteThisArgument();
  if (v177) {
    auto id177 = es.EntityId(v177.value());
    b.setVal177(id177);
  } else {
    b.setVal177(mx::kInvalidEntityId);
  }
}

void SerializeCXXConversionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  b.setVal176(es.EntityId(e.ConversionType()));
  b.setVal178(e.IsExplicit());
  b.setVal179(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  auto v176 = e.TargetConstructor();
  if (v176) {
    auto id176 = es.EntityId(v176.value());
    b.setVal176(id176);
  } else {
    b.setVal176(mx::kInvalidEntityId);
  }
  b.setVal178(e.IsDefaultConstructor());
  b.setVal179(e.IsDelegatingConstructor());
  b.setVal180(e.IsExplicit());
  b.setVal181(e.IsInheritingConstructor());
  b.setVal182(e.IsSpecializationCopyingObject());
}

void SerializeCXXDeductionGuideDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal165(es.EntityId(e.CorrespondingConstructor()));
  b.setVal166(es.EntityId(e.DeducedTemplate()));
  b.setVal167(e.IsCopyDeductionCandidate());
  b.setVal168(e.IsExplicit());
}

void SerializeFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v77 = e.BitWidth();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v79 = e.CapturedVLAType();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v80 = e.InClassInitializer();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  b.setVal74(e.HasCapturedVLAType());
  b.setVal75(e.HasInClassInitializer());
  b.setVal92(e.IsAnonymousStructOrUnion());
  b.setVal93(e.IsBitField());
  b.setVal94(e.IsMutable());
  b.setVal95(e.IsUnnamedBitfield());
  b.setVal96(e.IsZeroLengthBitField());
  b.setVal97(e.IsZeroSize());
}

void SerializeObjCIvarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e, nullptr);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal81(es.EntityId(e.ContainingInterface()));
  b.setVal82(es.EntityId(e.NextInstanceVariable()));
  b.setVal98(e.Synthesize());
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
  b.setVal56(es.EntityId(e.Binding()));
  b.setVal64(es.EntityId(e.DecomposedDeclaration()));
  b.setVal65(es.EntityId(e.HoldingVariable()));
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
  b.setVal56(es.EntityId(e.MapperVariableReference()));
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializeUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal54(es.EntityId(e.Introducer()));
  auto v55 = e.NextUsingShadowDeclaration();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  b.setVal56(es.EntityId(e.TargetDeclaration()));
}

void SerializeConstructorUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e, nullptr);
  b.setVal72(e.ConstructsVirtualBase());
  b.setVal64(es.EntityId(e.ConstructedBaseClass()));
  auto v65 = e.ConstructedBaseClassShadowDeclaration();
  if (v65) {
    auto id65 = es.EntityId(v65.value());
    b.setVal65(id65);
  } else {
    b.setVal65(mx::kInvalidEntityId);
  }
  b.setVal66(es.EntityId(e.NominatedBaseClass()));
  auto v76 = e.NominatedBaseClassShadowDeclaration();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
}

void SerializeUsingPackDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v49 = e.Expansions();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  b.setVal54(es.EntityId(e.InstantiatedFromUsingDeclaration()));
}

void SerializeUsingDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t54 = e.IdentifierToken();
  b.setVal54(es.EntityId(t54));
  auto t55 = e.NamespaceKeyToken();
  b.setVal55(es.EntityId(t55));
  b.setVal56(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t64 = e.UsingToken();
  b.setVal64(es.EntityId(t64));
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
  auto v54 = e.TypeForDeclaration();
  if (v54) {
    auto id54 = es.EntityId(v54.value());
    b.setVal54(id54);
  } else {
    b.setVal54(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  b.setVal72(e.DefaultArgumentWasInherited());
  auto v55 = e.DefaultArgument();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  auto v56 = e.DefaultArgumentInfo();
  if (v56) {
    auto id56 = es.EntityId(v56.value());
    b.setVal56(id56);
  } else {
    b.setVal56(mx::kInvalidEntityId);
  }
  auto t64 = e.DefaultArgumentToken();
  b.setVal64(es.EntityId(t64));
  b.setVal73(e.HasDefaultArgument());
  b.setVal74(e.HasTypeConstraint());
  b.setVal75(e.IsExpandedParameterPack());
  b.setVal92(e.IsPackExpansion());
  b.setVal93(e.WasDeclaredWithTypename());
}

void SerializeTagDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  if (auto r55 = e.BraceRange(); auto rs55 = r55.Size()) {
    b.setVal55(es.EntityId(r55[0]));
    b.setVal56(es.EntityId(r55[rs55 - 1u]));
  } else {
    b.setVal55(0);
    b.setVal56(0);
  }
  auto t64 = e.FirstInnerToken();
  b.setVal64(es.EntityId(t64));
  auto t65 = e.FirstOuterToken();
  b.setVal65(es.EntityId(t65));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.TagKind())));
  auto v66 = e.TypedefNameForAnonymousDeclaration();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
  } else {
    b.setVal66(mx::kInvalidEntityId);
  }
  b.setVal72(e.HasNameForLinkage());
  b.setVal73(e.IsBeingDefined());
  b.setVal74(e.IsClass());
  b.setVal75(e.IsCompleteDefinition());
  b.setVal92(e.IsCompleteDefinitionRequired());
  b.setVal93(e.IsDependentType());
  b.setVal94(e.IsEmbeddedInDeclarator());
  b.setVal95(e.IsEnum());
  b.setVal96(e.IsFreeStanding());
  b.setVal97(e.IsInterface());
  b.setVal98(e.IsStruct());
  b.setVal99(e.IsThisDeclarationADefinition());
  b.setVal100(e.IsThisDeclarationADemotedDefinition());
  b.setVal101(e.IsUnion());
  b.setVal102(e.MayHaveOutOfDateDefinition());
  do {
    auto v49 = e.TemplateParameterLists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
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

void SerializeRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  b.setVal103(e.CanPassInRegisters());
  do {
    auto v60 = e.Fields();
    auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
    auto i60 = 0u;
    for (const auto &e60 : v60) {
      sv60.set(i60, es.EntityId(e60));
      ++i60;
    }
  } while (false);
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
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
  b.setVal121(e.IsRandomized());
  b.setVal122(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e, nullptr);
  auto v123 = e.AllowConstDefaultInitializer();
  if (v123) {
    b.setVal123(static_cast<bool>(v123.value()));
    b.setVal124(true);
  } else {
    b.setVal124(false);
  }
  do {
    auto ov175 = e.Bases();
    if (!ov175) {
      b.setVal125(false);
      break;
    }
    b.setVal125(true);
    auto v175 = std::move(*ov175);
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
  auto v85 = e.CalculateInheritanceModel();
  if (v85) {
    b.setVal85(static_cast<unsigned char>(v85.value()));
    b.setVal132(true);
  } else {
    b.setVal132(false);
  }
  do {
    auto v183 = e.Constructors();
    auto sv183 = b.initVal183(static_cast<unsigned>(v183.size()));
    auto i183 = 0u;
    for (const auto &e183 : v183) {
      sv183.set(i183, es.EntityId(e183));
      ++i183;
    }
  } while (false);
  do {
    auto ov184 = e.Friends();
    if (!ov184) {
      b.setVal133(false);
      break;
    }
    b.setVal133(true);
    auto v184 = std::move(*ov184);
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  auto v76 = e.DependentLambdaCallOperator();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v77 = e.DescribedClassTemplate();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v79 = e.Destructor();
  if (v79) {
    auto id79 = es.EntityId(v79.value());
    b.setVal79(id79);
  } else {
    b.setVal79(mx::kInvalidEntityId);
  }
  auto v80 = e.GenericLambdaTemplateParameterList();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v81 = e.InstantiatedFromMemberClass();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto v82 = e.LambdaCallOperator();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  auto v86 = e.LambdaCaptureDefault();
  if (v86) {
    b.setVal86(static_cast<unsigned char>(v86.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  auto v84 = e.LambdaContextDeclaration();
  if (v84) {
    auto id84 = es.EntityId(v84.value());
    b.setVal84(id84);
  } else {
    b.setVal84(mx::kInvalidEntityId);
  }
  do {
    auto ov185 = e.LambdaExplicitTemplateParameters();
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
  auto v140 = e.LambdaManglingNumber();
  if (v140) {
    b.setVal140(static_cast<unsigned>(v140.value()));
    b.setVal136(true);
  } else {
    b.setVal136(false);
  }
  auto v89 = e.LambdaType();
  if (v89) {
    auto id89 = es.EntityId(v89.value());
    b.setVal89(id89);
  } else {
    b.setVal89(mx::kInvalidEntityId);
  }
  auto v87 = e.MSInheritanceModel();
  if (v87) {
    b.setVal87(static_cast<unsigned char>(v87.value()));
    b.setVal137(true);
  } else {
    b.setVal137(false);
  }
  b.setVal88(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v186 = e.ODRHash();
  if (v186) {
    b.setVal186(static_cast<unsigned>(v186.value()));
    b.setVal138(true);
  } else {
    b.setVal138(false);
  }
  auto v126 = e.TemplateInstantiationPattern();
  if (v126) {
    auto id126 = es.EntityId(v126.value());
    b.setVal126(id126);
  } else {
    b.setVal126(mx::kInvalidEntityId);
  }
  b.setVal90(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
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
  auto v167 = e.HasFriends();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
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
  auto v178 = e.HasInitializerMethod();
  if (v178) {
    b.setVal178(static_cast<bool>(v178.value()));
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
  auto v127 = e.IsLocalClass();
  if (v127) {
    auto id127 = es.EntityId(v127.value());
    b.setVal127(id127);
  } else {
    b.setVal127(mx::kInvalidEntityId);
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
}

void SerializeClassTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e, nullptr);
  auto t128 = e.ExternToken();
  b.setVal128(es.EntityId(t128));
  auto t130 = e.PointOfInstantiation();
  b.setVal130(es.EntityId(t130));
  b.setVal91(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal131(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v341 = e.TemplateArguments();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
  do {
    auto v342 = e.TemplateInstantiationArguments();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
    }
  } while (false);
  auto t139 = e.TemplateKeywordToken();
  b.setVal139(es.EntityId(t139));
  auto v141 = e.TypeAsWritten();
  if (v141) {
    auto id141 = es.EntityId(v141.value());
    b.setVal141(id141);
  } else {
    b.setVal141(mx::kInvalidEntityId);
  }
  b.setVal343(e.IsClassScopeExplicitSpecialization());
  b.setVal344(e.IsExplicitInstantiationOrSpecialization());
  b.setVal345(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal142(es.EntityId(e.InjectedSpecializationType()));
  b.setVal143(es.EntityId(e.InstantiatedFromMember()));
  b.setVal144(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal163(es.EntityId(e.TemplateParameters()));
  b.setVal346(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  do {
    auto v60 = e.Enumerators();
    auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
    auto i60 = 0u;
    for (const auto &e60 : v60) {
      sv60.set(i60, es.EntityId(e60));
      ++i60;
    }
  } while (false);
  auto v76 = e.InstantiatedFromMemberEnum();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v77 = e.IntegerType();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  if (auto r79 = e.IntegerTypeRange(); auto rs79 = r79.Size()) {
    b.setVal79(es.EntityId(r79[0]));
    b.setVal80(es.EntityId(r79[rs79 - 1u]));
  } else {
    b.setVal79(0);
    b.setVal80(0);
  }
  auto v140 = e.ODRHash();
  if (v140) {
    b.setVal140(static_cast<unsigned>(v140.value()));
    b.setVal103(true);
  } else {
    b.setVal103(false);
  }
  auto v81 = e.PromotionType();
  if (v81) {
    auto id81 = es.EntityId(v81.value());
    b.setVal81(id81);
  } else {
    b.setVal81(mx::kInvalidEntityId);
  }
  auto v82 = e.TemplateInstantiationPattern();
  if (v82) {
    auto id82 = es.EntityId(v82.value());
    b.setVal82(id82);
  } else {
    b.setVal82(mx::kInvalidEntityId);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal104(e.IsClosed());
  b.setVal105(e.IsClosedFlag());
  b.setVal106(e.IsClosedNonFlag());
  b.setVal107(e.IsComplete());
  b.setVal108(e.IsFixed());
  b.setVal109(e.IsScoped());
  b.setVal110(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  auto t55 = e.EllipsisToken();
  b.setVal55(es.EntityId(t55));
  auto t56 = e.TypenameToken();
  b.setVal56(es.EntityId(t56));
  auto t64 = e.UsingToken();
  b.setVal64(es.EntityId(t64));
  b.setVal72(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  auto v55 = e.AnonymousDeclarationWithTypedefName();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  b.setVal56(es.EntityId(e.UnderlyingType()));
  b.setVal72(e.IsModed());
  b.setVal73(e.IsTransparentTag());
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
  auto v64 = e.DescribedAliasTemplate();
  if (v64) {
    auto id64 = es.EntityId(v64.value());
    b.setVal64(id64);
  } else {
    b.setVal64(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e, nullptr);
  auto t64 = e.ColonToken();
  b.setVal64(es.EntityId(t64));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t65 = e.VarianceToken();
  b.setVal65(es.EntityId(t65));
  b.setVal74(e.HasExplicitBound());
}

void SerializeTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal54(es.EntityId(e.TemplateParameters()));
  b.setVal55(es.EntityId(e.TemplatedDeclaration()));
  b.setVal72(e.HasAssociatedConstraints());
  b.setVal73(e.IsTypeAlias());
}

void SerializeRedeclarableTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
  b.setVal56(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal74(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal75(e.IsAbbreviated());
  b.setVal92(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal75(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal75(e.IsThisDeclarationADefinition());
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
  b.setVal56(es.EntityId(e.ConstraintExpression()));
  b.setVal74(e.IsTypeConcept());
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
  b.setVal74(e.DefaultArgumentWasInherited());
  auto t56 = e.DefaultArgumentToken();
  b.setVal56(es.EntityId(t56));
  b.setVal75(e.HasDefaultArgument());
  b.setVal92(e.IsExpandedParameterPack());
  b.setVal93(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t54 = e.AtToken();
  b.setVal54(es.EntityId(t54));
  b.setVal55(es.EntityId(e.GetterMethodDeclaration()));
  auto t56 = e.GetterNameToken();
  b.setVal56(es.EntityId(t56));
  auto t64 = e.LParenToken();
  b.setVal64(es.EntityId(t64));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.PropertyImplementation())));
  b.setVal65(es.EntityId(e.PropertyInstanceVariableDeclaration()));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.QueryKind())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.SetterKind())));
  b.setVal66(es.EntityId(e.SetterMethodDeclaration()));
  auto t76 = e.SetterNameToken();
  b.setVal76(es.EntityId(t76));
  b.setVal77(es.EntityId(e.Type()));
  b.setVal72(e.IsAtomic());
  b.setVal73(e.IsClassProperty());
  b.setVal74(e.IsDirectProperty());
  b.setVal75(e.IsInstanceProperty());
  b.setVal92(e.IsOptional());
  b.setVal93(e.IsReadOnly());
  b.setVal94(e.IsRetaining());
}

void SerializeObjCMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal72(e.DefinedInNSObject());
  b.setVal54(es.EntityId(e.FindPropertyDeclaration()));
  b.setVal55(es.EntityId(e.ClassInterface()));
  b.setVal56(es.EntityId(e.CommandDeclaration()));
  auto t64 = e.DeclaratorEndToken();
  b.setVal64(es.EntityId(t64));
  b.setVal78(static_cast<unsigned char>(mx::FromPasta(e.ImplementationControl())));
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal85(static_cast<unsigned char>(mx::FromPasta(e.ObjCDeclQualifier())));
  b.setVal65(es.EntityId(e.ReturnType()));
  if (auto r66 = e.ReturnTypeSourceRange(); auto rs66 = r66.Size()) {
    b.setVal66(es.EntityId(r66[0]));
    b.setVal76(es.EntityId(r66[rs66 - 1u]));
  } else {
    b.setVal66(0);
    b.setVal76(0);
  }
  auto t77 = e.SelectorStartToken();
  b.setVal77(es.EntityId(t77));
  b.setVal79(es.EntityId(e.SelfDeclaration()));
  b.setVal73(e.HasParameterDestroyedInCallee());
  b.setVal74(e.HasRedeclaration());
  b.setVal75(e.HasRelatedResultType());
  b.setVal92(e.HasSkippedBody());
  b.setVal93(e.IsClassMethod());
  b.setVal94(e.IsDefined());
  b.setVal95(e.IsDesignatedInitializerForTheInterface());
  b.setVal96(e.IsDirectMethod());
  b.setVal97(e.IsInstanceMethod());
  b.setVal98(e.IsOptional());
  b.setVal99(e.IsOverriding());
  b.setVal100(e.IsPropertyAccessor());
  b.setVal101(e.IsRedeclaration());
  b.setVal102(e.IsSynthesizedAccessorStub());
  b.setVal103(e.IsThisDeclarationADefinition());
  b.setVal104(e.IsThisDeclarationADesignatedInitializer());
  b.setVal105(e.IsVariadic());
  do {
    auto v49 = e.Parameters();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  do {
    auto v50 = e.SelectorTokens();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  pasta::DeclContext dc60(e);
  auto v60 = dc60.AlreadyLoadedDeclarations();
  auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
  auto i60 = 0u;
  for (const pasta::Decl &e60 : v60) {
    sv60.set(i60, es.EntityId(e60));
    ++i60;
  }
}

void SerializeObjCContainerDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  do {
    auto v49 = e.ClassMethods();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  do {
    auto v50 = e.ClassProperties();
    auto sv50 = b.initVal50(static_cast<unsigned>(v50.size()));
    auto i50 = 0u;
    for (const auto &e50 : v50) {
      sv50.set(i50, es.EntityId(e50));
      ++i50;
    }
  } while (false);
  if (auto r54 = e.AtEndRange(); auto rs54 = r54.Size()) {
    b.setVal54(es.EntityId(r54[0]));
    b.setVal55(es.EntityId(r54[rs54 - 1u]));
  } else {
    b.setVal54(0);
    b.setVal55(0);
  }
  auto t56 = e.AtStartToken();
  b.setVal56(es.EntityId(t56));
  do {
    auto v60 = e.InstanceMethods();
    auto sv60 = b.initVal60(static_cast<unsigned>(v60.size()));
    auto i60 = 0u;
    for (const auto &e60 : v60) {
      sv60.set(i60, es.EntityId(e60));
      ++i60;
    }
  } while (false);
  do {
    auto v175 = e.InstanceProperties();
    auto sv175 = b.initVal175(static_cast<unsigned>(v175.size()));
    auto i175 = 0u;
    for (const auto &e175 : v175) {
      sv175.set(i175, es.EntityId(e175));
      ++i175;
    }
  } while (false);
  do {
    auto v183 = e.Methods();
    auto sv183 = b.initVal183(static_cast<unsigned>(v183.size()));
    auto i183 = 0u;
    for (const auto &e183 : v183) {
      sv183.set(i183, es.EntityId(e183));
      ++i183;
    }
  } while (false);
  do {
    auto v184 = e.Properties();
    auto sv184 = b.initVal184(static_cast<unsigned>(v184.size()));
    auto i184 = 0u;
    for (const auto &e184 : v184) {
      sv184.set(i184, es.EntityId(e184));
      ++i184;
    }
  } while (false);
  pasta::DeclContext dc185(e);
  auto v185 = dc185.AlreadyLoadedDeclarations();
  auto sv185 = b.initVal185(static_cast<unsigned>(v185.size()));
  auto i185 = 0u;
  for (const pasta::Decl &e185 : v185) {
    sv185.set(i185, es.EntityId(e185));
    ++i185;
  }
}

void SerializeObjCCategoryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal72(e.IsClassExtension());
  auto t64 = e.CategoryNameToken();
  b.setVal64(es.EntityId(t64));
  b.setVal65(es.EntityId(e.ClassInterface()));
  b.setVal66(es.EntityId(e.Implementation()));
  auto t76 = e.InstanceVariableLBraceToken();
  b.setVal76(es.EntityId(t76));
  auto t77 = e.InstanceVariableRBraceToken();
  b.setVal77(es.EntityId(t77));
  b.setVal79(es.EntityId(e.NextClassCategory()));
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
    auto v341 = e.Protocols();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  auto v71 = e.ObjCRuntimeNameAsString();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  b.setVal72(e.HasDefinition());
  b.setVal73(e.IsNonRuntimeProtocol());
  b.setVal74(e.IsThisDeclarationADefinition());
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

void SerializeObjCInterfaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  do {
    auto v313 = e.AllReferencedProtocols();
    auto sv313 = b.initVal313(static_cast<unsigned>(v313.size()));
    auto i313 = 0u;
    for (const auto &e313 : v313) {
      sv313.set(i313, es.EntityId(e313));
      ++i313;
    }
  } while (false);
  b.setVal72(e.DeclaresOrInheritsDesignatedInitializers());
  auto t64 = e.EndOfDefinitionToken();
  b.setVal64(es.EntityId(t64));
  b.setVal65(es.EntityId(e.Implementation()));
  auto v71 = e.ObjCRuntimeNameAsString();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  auto v66 = e.SuperClass();
  if (v66) {
    auto id66 = es.EntityId(v66.value());
    b.setVal66(id66);
  } else {
    b.setVal66(mx::kInvalidEntityId);
  }
  auto t76 = e.SuperClassToken();
  b.setVal76(es.EntityId(t76));
  auto v77 = e.SuperClassTypeInfo();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  b.setVal79(es.EntityId(e.TypeForDeclaration()));
  b.setVal73(e.HasDefinition());
  b.setVal74(e.HasDesignatedInitializers());
  b.setVal75(e.IsArcWeakrefUnavailable());
  b.setVal92(e.IsImplicitInterfaceDeclaration());
  b.setVal80(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal93(e.IsThisDeclarationADefinition());
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
    auto v341 = e.KnownCategories();
    auto sv341 = b.initVal341(static_cast<unsigned>(v341.size()));
    auto i341 = 0u;
    for (const auto &e341 : v341) {
      sv341.set(i341, es.EntityId(e341));
      ++i341;
    }
  } while (false);
  do {
    auto v342 = e.KnownExtensions();
    auto sv342 = b.initVal342(static_cast<unsigned>(v342.size()));
    auto i342 = 0u;
    for (const auto &e342 : v342) {
      sv342.set(i342, es.EntityId(e342));
      ++i342;
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
  do {
    auto v349 = e.VisibleCategories();
    auto sv349 = b.initVal349(static_cast<unsigned>(v349.size()));
    auto i349 = 0u;
    for (const auto &e349 : v349) {
      sv349.set(i349, es.EntityId(e349));
      ++i349;
    }
  } while (false);
  do {
    auto v350 = e.VisibleExtensions();
    auto sv350 = b.initVal350(static_cast<unsigned>(v350.size()));
    auto i350 = 0u;
    for (const auto &e350 : v350) {
      sv350.set(i350, es.EntityId(e350));
      ++i350;
    }
  } while (false);
}

void SerializeObjCImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal64(es.EntityId(e.ClassInterface()));
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

void SerializeObjCCategoryImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  b.setVal65(es.EntityId(e.CategoryDeclaration()));
  auto t66 = e.CategoryNameToken();
  b.setVal66(es.EntityId(t66));
}

void SerializeObjCImplementationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  auto t65 = e.InstanceVariableLBraceToken();
  b.setVal65(es.EntityId(t65));
  auto t66 = e.InstanceVariableRBraceToken();
  b.setVal66(es.EntityId(t66));
  auto v71 = e.ObjCRuntimeNameAsString();
  std::string s71(v71.data(), v71.size());
  b.setVal71(s71);
  b.setVal76(es.EntityId(e.SuperClass()));
  auto t77 = e.SuperClassToken();
  b.setVal77(es.EntityId(t77));
  b.setVal72(e.HasDestructors());
  b.setVal73(e.HasNonZeroConstructors());
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

void SerializeObjCCompatibleAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal54(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializeNamespaceAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t54 = e.AliasToken();
  b.setVal54(es.EntityId(t54));
  b.setVal55(es.EntityId(e.AliasedNamespace()));
  auto t56 = e.NamespaceToken();
  b.setVal56(es.EntityId(t56));
  auto t64 = e.TargetNameToken();
  b.setVal64(es.EntityId(t64));
}

void SerializeLinkageSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializeLifetimeExtendedTemporaryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v49 = e.Children();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
  b.setVal47(es.EntityId(e.ExtendingDeclaration()));
  b.setVal63(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal54(es.EntityId(e.TemporaryExpression()));
}

void SerializeImportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v49 = e.IdentifierTokens();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeImplicitConceptSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImplicitConceptSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  do {
    auto v49 = e.TemplateArguments();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeFriendTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal47(es.EntityId(e.FriendDeclaration()));
  auto t54 = e.FriendToken();
  b.setVal54(es.EntityId(t54));
  b.setVal55(es.EntityId(e.FriendType()));
  do {
    auto v49 = e.TemplateParameterLists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeFriendDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v47 = e.FriendDeclaration();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  auto t54 = e.FriendToken();
  b.setVal54(es.EntityId(t54));
  auto v55 = e.FriendType();
  if (v55) {
    auto id55 = es.EntityId(v55.value());
    b.setVal55(id55);
  } else {
    b.setVal55(mx::kInvalidEntityId);
  }
  b.setVal48(e.IsUnsupportedFriend());
  do {
    auto v49 = e.FriendTypeTemplateParameterLists();
    auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
    auto i49 = 0u;
    for (const auto &e49 : v49) {
      sv49.set(i49, es.EntityId(e49));
      ++i49;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t47 = e.AssemblyToken();
  b.setVal47(es.EntityId(t47));
  b.setVal54(es.EntityId(e.AssemblyString()));
  auto t55 = e.RParenToken();
  b.setVal55(es.EntityId(t55));
}

void SerializeExternCContextDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
  }
}

void SerializeExportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t47 = e.ExportToken();
  b.setVal47(es.EntityId(t47));
  auto t54 = e.RBraceToken();
  b.setVal54(es.EntityId(t54));
  b.setVal48(e.HasBraces());
  pasta::DeclContext dc49(e);
  auto v49 = dc49.AlreadyLoadedDeclarations();
  auto sv49 = b.initVal49(static_cast<unsigned>(v49.size()));
  auto i49 = 0u;
  for (const pasta::Decl &e49 : v49) {
    sv49.set(i49, es.EntityId(e49));
    ++i49;
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
