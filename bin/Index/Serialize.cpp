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
  std::optional<const void *> v1 = nullptr;
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
  auto v9 = e.Name();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
  if (true) {
    auto v3 = e.Body();
    auto sv3 = b.initVal3(static_cast<unsigned>(v3.size()));
    auto i3 = 0u;
    for (const auto &e3 : v3) {
      sv3.set(i3, es.EntityId(e3));
      ++i3;
    }
  }
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

void SerializeHLSLSV_GroupIndexAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLSV_GroupIndexAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
}

void SerializeHLSLNumThreadsAttr(const EntityMapper &es, mx::ast::Attr::Builder b, const pasta::HLSLNumThreadsAttr &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeInheritableAttr(es, b, e, nullptr);
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
  b.setVal185(e.IsPromotableIntegerType());
  b.setVal186(e.IsQueueT());
  b.setVal187(e.IsRValueReferenceType());
  b.setVal188(e.IsRealFloatingType());
  b.setVal189(e.IsRealType());
  b.setVal190(e.IsRecordType());
  b.setVal191(e.IsReferenceType());
  b.setVal192(e.IsReserveIDT());
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

void SerializeTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateTypeParmType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
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

void SerializeTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TemplateSpecializationType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
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

void SerializeTagType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TagType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Declaration()));
  b.setVal230(e.IsBeingDefined());
}

void SerializeRecordType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RecordType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.HasConstFields());
  b.setVal232(e.IsSugared());
}

void SerializeEnumType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::EnumType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal231(e.IsSugared());
}

void SerializeSubstTemplateTypeParmType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ReplacedParameter()));
  b.setVal234(es.EntityId(e.ReplacementType()));
  b.setVal230(e.IsSugared());
}

void SerializeSubstTemplateTypeParmPackType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::SubstTemplateTypeParmPackType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ReplacedParameter()));
  b.setVal230(e.IsSugared());
}

void SerializeReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.PointeeTypeAsWritten()));
  b.setVal230(e.IsInnerReference());
  b.setVal231(e.IsSpelledAsLValue());
}

void SerializeRValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::RValueReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal232(e.IsSugared());
}

void SerializeLValueReferenceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::LValueReferenceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeReferenceType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal232(e.IsSugared());
}

void SerializeQualifiedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::QualifiedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.AddressSpace())));
  b.setVal228(es.EntityId(e.AtomicUnqualifiedType()));
  b.setVal230(e.HasAddressSpace());
  b.setVal231(e.HasNonTrivialObjCLifetime());
  b.setVal232(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal236(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal237(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal238(e.HasQualifiers());
  b.setVal239(e.HasStrongOrWeakObjCLifetime());
  b.setVal240(e.IsCForbiddenLValueType());
  b.setVal241(e.IsCXX11PODType());
  b.setVal242(e.IsCXX98PODType());
  b.setVal243(e.IsCanonical());
  b.setVal244(e.IsCanonicalAsParameter());
  b.setVal245(e.IsConstQualified());
  b.setVal246(e.IsConstant());
  b.setVal247(e.IsLocalConstQualified());
  b.setVal248(e.IsLocalRestrictQualified());
  b.setVal249(e.IsLocalVolatileQualified());
  b.setVal250(e.IsNonWeakInMRRWithObjCWeak());
  b.setVal251(e.IsNull());
  b.setVal252(e.IsObjCGCStrong());
  b.setVal253(e.IsObjCGCWeak());
  b.setVal254(e.IsPODType());
  b.setVal255(e.IsRestrictQualified());
  b.setVal256(e.IsTrivialType());
  b.setVal257(e.IsTriviallyCopyableType());
  b.setVal258(e.IsTriviallyRelocatableType());
  b.setVal259(e.IsVolatileQualified());
  b.setVal260(e.MayBeDynamicClass());
  b.setVal261(e.MayBeNotDynamicClass());
}

void SerializePointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializePipeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PipeType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsReadOnly());
  b.setVal231(e.IsSugared());
}

void SerializeParenType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ParenType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.InnerType()));
  b.setVal230(e.IsSugared());
}

void SerializePackExpansionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::PackExpansionType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Pattern()));
  b.setVal230(e.IsSugared());
}

void SerializeObjCTypeParamType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCTypeParamType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
}

void SerializeObjCObjectType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.BaseType()));
  b.setVal234(es.EntityId(e.Interface()));
  auto v262 = e.SuperClassType();
  if (v262) {
    auto id262 = es.EntityId(v262.value());
    b.setVal262(id262);
  } else {
    b.setVal262(mx::kInvalidEntityId);
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
    auto v263 = e.TypeArgumentsAsWritten();
    auto sv263 = b.initVal263(static_cast<unsigned>(v263.size()));
    auto i263 = 0u;
    for (const auto &e263 : v263) {
      sv263.set(i263, es.EntityId(e263));
      ++i263;
    }
  } while (false);
  b.setVal230(e.IsKindOfType());
  b.setVal231(e.IsKindOfTypeAsWritten());
  b.setVal232(e.IsObjCClass());
  b.setVal236(e.IsObjCId());
  b.setVal237(e.IsObjCQualifiedClass());
  b.setVal238(e.IsObjCQualifiedId());
  b.setVal239(e.IsObjCUnqualifiedClass());
  b.setVal240(e.IsObjCUnqualifiedId());
  b.setVal241(e.IsObjCUnqualifiedIdOrClass());
  b.setVal242(e.IsSpecialized());
  b.setVal243(e.IsSpecializedAsWritten());
  b.setVal244(e.IsSugared());
  b.setVal245(e.IsUnspecialized());
  b.setVal246(e.IsUnspecializedAsWritten());
  b.setVal264(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
}

void SerializeObjCInterfaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCInterfaceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCObjectType(es, b, e, nullptr);
  b.setVal265(es.EntityId(e.Declaration()));
}

void SerializeObjCObjectPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ObjCObjectPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.InterfaceDeclaration()));
  b.setVal234(es.EntityId(e.InterfaceType()));
  b.setVal262(es.EntityId(e.ObjectType()));
  b.setVal264(es.EntityId(e.SuperClassType()));
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
    auto v263 = e.TypeArgumentsAsWritten();
    auto sv263 = b.initVal263(static_cast<unsigned>(v263.size()));
    auto i263 = 0u;
    for (const auto &e263 : v263) {
      sv263.set(i263, es.EntityId(e263));
      ++i263;
    }
  } while (false);
  b.setVal230(e.IsKindOfType());
  b.setVal231(e.IsObjCIdOrClassType());
  b.setVal232(e.IsSpecialized());
  b.setVal236(e.IsSpecializedAsWritten());
  b.setVal237(e.IsSugared());
  b.setVal238(e.IsUnspecialized());
  b.setVal239(e.IsUnspecializedAsWritten());
  do {
    auto v266 = e.Qualifiers();
    auto sv266 = b.initVal266(static_cast<unsigned>(v266.size()));
    auto i266 = 0u;
    for (const auto &e266 : v266) {
      sv266.set(i266, es.EntityId(e266));
      ++i266;
    }
  } while (false);
  b.setVal265(es.EntityId(e.StripObjCKindOfTypeAndQualifiers()));
  do {
    auto v267 = e.Protocols();
    auto sv267 = b.initVal267(static_cast<unsigned>(v267.size()));
    auto i267 = 0u;
    for (const auto &e267 : v267) {
      sv267.set(i267, es.EntityId(e267));
      ++i267;
    }
  } while (false);
}

void SerializeMemberPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MemberPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Class()));
  b.setVal234(es.EntityId(e.MostRecentCXXRecordDeclaration()));
  b.setVal230(e.IsMemberDataPointer());
  b.setVal231(e.IsMemberFunctionPointer());
  b.setVal232(e.IsSugared());
}

void SerializeMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::MatrixType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedMatrixType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedMatrixType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeMatrixType(es, b, e, nullptr);
  auto t234 = e.AttributeToken();
  b.setVal234(es.EntityId(t234));
  b.setVal262(es.EntityId(e.ColumnExpression()));
  b.setVal264(es.EntityId(e.RowExpression()));
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
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ModifiedType()));
  b.setVal234(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeInjectedClassNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::InjectedClassNameType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal234(es.EntityId(e.InjectedSpecializationType()));
  b.setVal262(es.EntityId(e.InjectedTST()));
  b.setVal230(e.IsSugared());
}

void SerializeFunctionType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.CallConv())));
  b.setVal228(es.EntityId(e.CallResultType()));
  b.setVal230(e.CmseNSCallAttribute());
  b.setVal231(e.HasRegParm());
  b.setVal232(e.NoReturnAttribute());
  b.setVal229(es.EntityId(e.ReturnType()));
  b.setVal236(e.IsConst());
  b.setVal237(e.IsRestrict());
  b.setVal238(e.IsVolatile());
}

void SerializeFunctionProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionProtoType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e, nullptr);
  auto v268 = e.CanThrow();
  if (v268) {
    b.setVal268(static_cast<unsigned char>(v268.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  b.setVal234(es.EntityId(e.Desugar()));
  auto t262 = e.EllipsisToken();
  b.setVal262(es.EntityId(t262));
  auto v264 = e.ExceptionSpecDeclaration();
  if (v264) {
    auto id264 = es.EntityId(v264.value());
    b.setVal264(id264);
  } else {
    b.setVal264(mx::kInvalidEntityId);
  }
  auto v265 = e.ExceptionSpecTemplate();
  if (v265) {
    auto id265 = es.EntityId(v265.value());
    b.setVal265(id265);
  } else {
    b.setVal265(mx::kInvalidEntityId);
  }
  b.setVal269(static_cast<unsigned char>(mx::FromPasta(e.ExceptionSpecType())));
  auto v270 = e.NoexceptExpression();
  if (v270) {
    auto id270 = es.EntityId(v270.value());
    b.setVal270(id270);
  } else {
    b.setVal270(mx::kInvalidEntityId);
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
  b.setVal271(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
  b.setVal240(e.HasDependentExceptionSpec());
  b.setVal241(e.HasDynamicExceptionSpec());
  b.setVal242(e.HasExceptionSpec());
  b.setVal243(e.HasExtParameterInfos());
  b.setVal244(e.HasInstantiationDependentExceptionSpec());
  b.setVal245(e.HasNoexceptExceptionSpec());
  b.setVal246(e.HasTrailingReturn());
  auto v247 = e.IsNothrow();
  if (v247) {
    b.setVal247(static_cast<bool>(v247.value()));
    b.setVal248(true);
  } else {
    b.setVal248(false);
  }
  b.setVal249(e.IsSugared());
  b.setVal250(e.IsTemplateVariadic());
  b.setVal251(e.IsVariadic());
  do {
    auto v263 = e.ExceptionTypes();
    auto sv263 = b.initVal263(static_cast<unsigned>(v263.size()));
    auto i263 = 0u;
    for (const auto &e263 : v263) {
      sv263.set(i263, es.EntityId(e263));
      ++i263;
    }
  } while (false);
}

void SerializeFunctionNoProtoType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::FunctionNoProtoType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionType(es, b, e, nullptr);
  b.setVal234(es.EntityId(e.Desugar()));
  b.setVal239(e.IsSugared());
}

void SerializeDependentVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentVectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto t229 = e.AttributeToken();
  b.setVal229(es.EntityId(t229));
  b.setVal234(es.EntityId(e.ElementType()));
  b.setVal262(es.EntityId(e.SizeExpression()));
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedExtVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedExtVectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  auto t229 = e.AttributeToken();
  b.setVal229(es.EntityId(t229));
  b.setVal234(es.EntityId(e.ElementType()));
  b.setVal262(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentBitIntType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.NumBitsExpression()));
  b.setVal230(e.IsSigned());
  b.setVal231(e.IsSugared());
  b.setVal232(e.IsUnsigned());
}

void SerializeDependentAddressSpaceType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentAddressSpaceType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.AddressSpaceExpression()));
  auto t234 = e.AttributeToken();
  b.setVal234(es.EntityId(t234));
  b.setVal230(e.IsSugared());
}

void SerializeDeducedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DeducedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
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
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
  do {
    auto v233 = e.TypeConstraintArguments();
    auto sv233 = b.initVal233(static_cast<unsigned>(v233.size()));
    auto i233 = 0u;
    for (const auto &e233 : v233) {
      sv233.set(i233, es.EntityId(e233));
      ++i233;
    }
  } while (false);
  auto v234 = e.TypeConstraintConcept();
  if (v234) {
    auto id234 = es.EntityId(v234.value());
    b.setVal234(id234);
  } else {
    b.setVal234(mx::kInvalidEntityId);
  }
  b.setVal232(e.IsConstrained());
  b.setVal236(e.IsDecltypeAuto());
  b.setVal237(e.IsGNUAutoType());
}

void SerializeDecltypeType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DecltypeType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.UnderlyingExpression()));
  b.setVal234(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeComplexType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ComplexType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal230(e.IsSugared());
}

void SerializeBuiltinType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BuiltinType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  b.setVal230(e.IsFloatingPoint());
  b.setVal231(e.IsInteger());
  b.setVal232(e.IsSVEBool());
  b.setVal236(e.IsSignedInteger());
  b.setVal237(e.IsSugared());
  b.setVal238(e.IsUnsignedInteger());
}

void SerializeBlockPointerType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BlockPointerType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeBitIntType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BitIntType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSigned());
  b.setVal231(e.IsSugared());
  b.setVal232(e.IsUnsigned());
}

void SerializeBTFTagAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::BTFTagAttributedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Attribute()));
  b.setVal234(es.EntityId(e.WrappedType()));
  b.setVal230(e.IsSugared());
}

void SerializeAttributedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AttributedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal272(static_cast<unsigned short>(mx::FromPasta(e.AttributeKind())));
  b.setVal229(es.EntityId(e.EquivalentType()));
  auto v235 = e.ImmediateNullability();
  if (v235) {
    b.setVal235(static_cast<unsigned char>(v235.value()));
    b.setVal230(true);
  } else {
    b.setVal230(false);
  }
  b.setVal234(es.EntityId(e.ModifiedType()));
  b.setVal231(e.IsCallingConv());
  b.setVal232(e.IsMSTypeSpec());
  b.setVal236(e.IsQualifier());
  b.setVal237(e.IsSugared());
}

void SerializeAtomicType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AtomicType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ValueType()));
  b.setVal230(e.IsSugared());
}

void SerializeArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.ElementType()));
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.SizeModifier())));
}

void SerializeVariableArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VariableArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  if (auto r234 = e.BracketsRange(); auto rs234 = r234.Size()) {
    b.setVal234(es.EntityId(r234[0]));
    b.setVal262(es.EntityId(r234[rs234 - 1u]));
  } else {
    b.setVal234(0);
    b.setVal262(0);
  }
  auto t264 = e.LBracketToken();
  b.setVal264(es.EntityId(t264));
  auto t265 = e.RBracketToken();
  b.setVal265(es.EntityId(t265));
  b.setVal270(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeIncompleteArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::IncompleteArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeDependentSizedArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentSizedArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  if (auto r234 = e.BracketsRange(); auto rs234 = r234.Size()) {
    b.setVal234(es.EntityId(r234[0]));
    b.setVal262(es.EntityId(r234[rs234 - 1u]));
  } else {
    b.setVal234(0);
    b.setVal262(0);
  }
  auto t264 = e.LBracketToken();
  b.setVal264(es.EntityId(t264));
  auto t265 = e.RBracketToken();
  b.setVal265(es.EntityId(t265));
  b.setVal270(es.EntityId(e.SizeExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeConstantArrayType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ConstantArrayType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeArrayType(es, b, e, nullptr);
  b.setVal229(es.EntityId(e.Desugar()));
  auto v234 = e.SizeExpression();
  if (v234) {
    auto id234 = es.EntityId(v234.value());
    b.setVal234(id234);
  } else {
    b.setVal234(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsSugared());
}

void SerializeAdjustedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::AdjustedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ResolvedType()));
  b.setVal234(es.EntityId(e.OriginalType()));
  b.setVal230(e.IsSugared());
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
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.Keyword())));
}

void SerializeElaboratedType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::ElaboratedType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.NamedType()));
  auto v234 = e.OwnedTagDeclaration();
  if (v234) {
    auto id234 = es.EntityId(v234.value());
    b.setVal234(id234);
  } else {
    b.setVal234(mx::kInvalidEntityId);
  }
  b.setVal230(e.IsSugared());
}

void SerializeDependentTemplateSpecializationType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentTemplateSpecializationType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
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

void SerializeDependentNameType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::DependentNameType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeWithKeyword(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal230(e.IsSugared());
}

void SerializeVectorType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::VectorType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.ElementType()));
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.VectorKind())));
  b.setVal230(e.IsSugared());
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
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.FoundDeclaration()));
  b.setVal234(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeUnresolvedUsingType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnresolvedUsingType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
}

void SerializeUnaryTransformType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::UnaryTransformType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.BaseType()));
  b.setVal235(static_cast<unsigned char>(mx::FromPasta(e.UTTKind())));
  b.setVal234(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeTypedefType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypedefType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.Declaration()));
  b.setVal230(e.IsSugared());
}

void SerializeTypeOfType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.UnderlyingType()));
  b.setVal230(e.IsSugared());
}

void SerializeTypeOfExprType(const EntityMapper &es, mx::ast::Type::Builder b, const pasta::TypeOfExprType &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeType(es, b, e, nullptr);
  b.setVal228(es.EntityId(e.Desugar()));
  b.setVal229(es.EntityId(e.UnderlyingExpression()));
  b.setVal230(e.IsSugared());
}

void SerializeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Stmt &e, const TokenTree *) {
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

void SerializeSEHTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.ExceptHandler()));
  b.setVal10(es.EntityId(e.FinallyHandler()));
  b.setVal11(es.EntityId(e.Handler()));
  b.setVal12(e.IsCXXTry());
  b.setVal13(es.EntityId(e.TryBlock()));
  auto t14 = e.TryToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeSEHLeaveStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHLeaveStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.LeaveToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeSEHFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.FinallyToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeSEHExceptStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SEHExceptStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Block()));
  auto t10 = e.ExceptToken();
  b.setVal10(es.EntityId(t10));
  b.setVal11(es.EntityId(e.FilterExpression()));
}

void SerializeReturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ReturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeObjCForCollectionStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCForCollectionStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Collection()));
  b.setVal11(es.EntityId(e.Element()));
  auto t13 = e.ForToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.RParenToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeObjCAutoreleasePoolStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAutoreleasePoolStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.AtToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
}

void SerializeObjCAtTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeObjCAtThrowStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtThrowStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.ThrowExpression()));
  auto t10 = e.ThrowToken();
  b.setVal10(es.EntityId(t10));
}

void SerializeObjCAtSynchronizedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtSynchronizedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.AtSynchronizedToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SynchBody()));
  b.setVal11(es.EntityId(e.SynchExpression()));
}

void SerializeObjCAtFinallyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtFinallyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.AtFinallyToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.FinallyBody()));
}

void SerializeObjCAtCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAtCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.AtCatchToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.CatchBody()));
  b.setVal11(es.EntityId(e.CatchParameterDeclaration()));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
  b.setVal12(e.HasEllipsis());
}

void SerializeOMPExecutableDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPExecutableDirective &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.AssociatedStatement()));
  b.setVal10(es.EntityId(e.InnermostCapturedStatement()));
  b.setVal11(es.EntityId(e.RawStatement()));
  b.setVal13(es.EntityId(e.StructuredBlock()));
  b.setVal12(e.HasAssociatedStatement());
  b.setVal16(e.IsStandaloneDirective());
}

void SerializeOMPDispatchDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDispatchDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  auto t14 = e.TargetCallToken();
  b.setVal14(es.EntityId(t14));
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
  b.setVal14(es.EntityId(e.ReductionReference()));
}

void SerializeOMPTaskDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPTargetUpdateDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetUpdateDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetTeamsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetTeamsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPTargetParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTargetParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
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
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSectionDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSectionDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPScanDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPScanDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPParallelSectionsDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelSectionsDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMasterDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelMaskedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
}

void SerializeOMPParallelDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPOrderedDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPOrderedDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPMetaDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMetaDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
  b.setVal14(es.EntityId(e.IfStatement()));
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
  b.setVal14(es.EntityId(e.PreInitializers()));
  b.setVal17(es.EntityId(e.TransformedStatement()));
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

void SerializeOMPGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPDistributeSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPDistributeParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPDistributeParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
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
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPTeamsDistributeDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTeamsDistributeDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
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
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
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
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPParallelGenericLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelGenericLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPParallelForDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPParallelForDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal55(es.EntityId(e.TaskReductionReferenceExpression()));
  b.setVal23(e.HasCancel());
}

void SerializeOMPMasterTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMasterTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMasterTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPMaskedTaskLoopSimdDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopSimdDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
}

void SerializeOMPMaskedTaskLoopDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPMaskedTaskLoopDirective &e, const TokenTree *) {
  SerializeOMPLoopDirective(es, b, e, nullptr);
  b.setVal23(e.HasCancel());
}

void SerializeOMPInteropDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPInteropDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPFlushDirective(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPFlushDirective &e, const TokenTree *) {
  SerializeOMPExecutableDirective(es, b, e, nullptr);
}

void SerializeOMPCanonicalLoop(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPCanonicalLoop &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.DistanceFunc()));
  b.setVal10(es.EntityId(e.LoopStatement()));
  b.setVal11(es.EntityId(e.LoopVariableFunc()));
  b.setVal13(es.EntityId(e.LoopVariableReference()));
}

void SerializeNullStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NullStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.SemiToken();
  b.setVal9(es.EntityId(t9));
  b.setVal12(e.HasLeadingEmptyMacro());
}

void SerializeMSDependentExistsStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSDependentExistsStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsIfExists());
  b.setVal16(e.IsIfNotExists());
}

void SerializeIndirectGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IndirectGotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeIfStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IfStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.StatementKind())));
  b.setVal21(es.EntityId(e.Then()));
  b.setVal12(e.HasElseStorage());
  b.setVal16(e.HasInitializerStorage());
  b.setVal23(e.HasVariableStorage());
  b.setVal24(e.IsConsteval());
  b.setVal25(e.IsConstexpr());
  b.setVal57(e.IsNegatedConsteval());
  b.setVal58(e.IsNonNegatedConsteval());
  b.setVal59(e.IsObjCAvailabilityCheck());
}

void SerializeGotoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GotoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.GotoToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Label()));
  auto t11 = e.LabelToken();
  b.setVal11(es.EntityId(t11));
}

void SerializeForStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ForStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeDoStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DoStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.Body()));
  b.setVal10(es.EntityId(e.Condition()));
  auto t11 = e.DoToken();
  b.setVal11(es.EntityId(t11));
  auto t13 = e.RParenToken();
  b.setVal13(es.EntityId(t13));
  auto t14 = e.WhileToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeDeclStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeCoroutineBodyStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineBodyStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeCoreturnStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoreturnStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.KeywordToken();
  b.setVal9(es.EntityId(t9));
  b.setVal10(es.EntityId(e.Operand()));
  b.setVal11(es.EntityId(e.PromiseCall()));
  b.setVal12(e.IsImplicit());
}

void SerializeContinueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ContinueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.ContinueToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeCompoundStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeCapturedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CapturedStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal9(es.EntityId(e.CapturedDeclaration()));
  b.setVal10(es.EntityId(e.CapturedRecordDeclaration()));
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.CapturedRegionKind())));
  b.setVal11(es.EntityId(e.CapturedStatement()));
}

void SerializeCXXTryStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTryStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeCXXForRangeStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXForRangeStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeCXXCatchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXCatchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeBreakStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BreakStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto t9 = e.BreakToken();
  b.setVal9(es.EntityId(t9));
}

void SerializeAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsmStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  b.setVal60(e.GenerateAssemblyString());
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

void SerializeMSAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
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
  auto t10 = e.LBraceToken();
  b.setVal10(es.EntityId(t10));
  b.setVal23(e.HasBraces());
}

void SerializeGCCAsmStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GCCAsmStmt &e, const TokenTree *) {
  SerializeAsmStmt(es, b, e, nullptr);
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

void SerializeWhileStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::WhileStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeValueStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ValueStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
  auto v9 = e.ExpressionStatement();
  if (v9) {
    auto id9 = es.EntityId(v9.value());
    b.setVal9(id9);
  } else {
    b.setVal9(mx::kInvalidEntityId);
  }
}

void SerializeLabelStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LabelStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
  b.setVal10(es.EntityId(e.Declaration()));
  auto t11 = e.IdentifierToken();
  b.setVal11(es.EntityId(t11));
  auto v60 = e.Name();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal13(es.EntityId(e.SubStatement()));
  b.setVal12(e.IsSideEntry());
}

void SerializeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::Expr &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
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
  b.setVal56(static_cast<unsigned char>(mx::FromPasta(e.ObjectKind())));
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
  b.setVal69(static_cast<unsigned char>(mx::FromPasta(e.ValueKind())));
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
  b.setVal70(e.IsImplicitCXXThis());
  b.setVal71(e.IsInstantiationDependent());
  auto v72 = e.IsIntegerConstantExpression();
  if (v72) {
    b.setVal72(static_cast<bool>(v72.value()));
    b.setVal73(true);
  } else {
    b.setVal73(false);
  }
  b.setVal74(e.IsKnownToHaveBooleanValue());
  b.setVal75(e.IsLValue());
  b.setVal76(e.IsOBJCGCCandidate());
  b.setVal77(e.IsObjCSelfExpression());
  b.setVal78(e.IsOrdinaryOrBitFieldObject());
  b.setVal79(e.IsPRValue());
  b.setVal80(e.IsReadIfDiscardedInCPlusPlus11());
  b.setVal81(e.IsTypeDependent());
  b.setVal82(e.IsValueDependent());
  b.setVal83(e.IsXValue());
  b.setVal84(e.RefersToBitField());
  b.setVal85(e.RefersToGlobalRegisterVariable());
  b.setVal86(e.RefersToMatrixElement());
  b.setVal87(e.RefersToVectorElement());
}

void SerializeDesignatedInitUpdateExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitUpdateExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Updater()));
}

void SerializeDesignatedInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DesignatedInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v15 = e.Designators();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
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
  b.setVal88(e.IsDirectInitializer());
  b.setVal89(e.UsesGNUSyntax());
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

void SerializeDependentScopeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentScopeDeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.LAngleToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RAngleToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.TemplateKeywordToken();
  b.setVal40(es.EntityId(t40));
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
}

void SerializeDependentCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DependentCoawaitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.KeywordToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Operand()));
  b.setVal40(es.EntityId(e.OperatorCoawaitLookup()));
}

void SerializeDeclRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DeclRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Declaration()));
  b.setVal39(es.EntityId(e.FoundDeclaration()));
  auto t40 = e.LAngleToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RAngleToken();
  b.setVal41(es.EntityId(t41));
  auto t42 = e.TemplateKeywordToken();
  b.setVal42(es.EntityId(t42));
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasQualifier());
  b.setVal91(e.HasTemplateKeywordAndArgumentsInfo());
  b.setVal92(e.HasTemplateKeyword());
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
  b.setVal94(e.RefersToEnclosingVariableOrCapture());
}

void SerializeCoroutineSuspendExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoroutineSuspendExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.CommonExpression()));
  auto t39 = e.KeywordToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.OpaqueValue()));
  b.setVal41(es.EntityId(e.Operand()));
  b.setVal42(es.EntityId(e.ReadyExpression()));
  b.setVal43(es.EntityId(e.ResumeExpression()));
  b.setVal44(es.EntityId(e.SuspendExpression()));
}

void SerializeCoawaitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoawaitExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
  b.setVal88(e.IsImplicit());
}

void SerializeCoyieldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CoyieldExpr &e, const TokenTree *) {
  SerializeCoroutineSuspendExpr(es, b, e, nullptr);
}

void SerializeConvertVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConvertVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeConceptSpecializationExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConceptSpecializationExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v15 = e.TemplateArguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal88(e.IsSatisfied());
}

void SerializeCompoundLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Initializer()));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal88(e.IsFileScope());
}

void SerializeChooseExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ChooseExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.ChosenSubExpression()));
  b.setVal40(es.EntityId(e.Condition()));
  b.setVal41(es.EntityId(e.LHS()));
  b.setVal42(es.EntityId(e.RHS()));
  auto t43 = e.RParenToken();
  b.setVal43(es.EntityId(t43));
  b.setVal88(e.IsConditionDependent());
  b.setVal89(e.IsConditionTrue());
}

void SerializeCharacterLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CharacterLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CastExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.CastKind())));
  auto v60 = e.CastKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
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
  b.setVal88(e.HasStoredFPFeatures());
}

void SerializeImplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal89(e.IsPartOfExplicitCast());
}

void SerializeExplicitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExplicitCastExpr &e, const TokenTree *) {
  SerializeCastExpr(es, b, e, nullptr);
  b.setVal42(es.EntityId(e.TypeAsWritten()));
}

void SerializeCXXNamedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNamedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  if (auto r43 = e.AngleBrackets(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  auto v65 = e.CastName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t45 = e.OperatorToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.RParenToken();
  b.setVal46(es.EntityId(t46));
}

void SerializeCXXDynamicCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDynamicCastExpr &e, const TokenTree *) {
  SerializeCXXNamedCastExpr(es, b, e, nullptr);
  b.setVal89(e.IsAlwaysNull());
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
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
  b.setVal89(e.IsListInitialization());
}

void SerializeCStyleCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CStyleCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t43 = e.LParenToken();
  b.setVal43(es.EntityId(t43));
  auto t44 = e.RParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeBuiltinBitCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BuiltinBitCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
}

void SerializeObjCBridgedCastExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBridgedCastExpr &e, const TokenTree *) {
  SerializeExplicitCastExpr(es, b, e, nullptr);
  auto t43 = e.BridgeKeywordToken();
  b.setVal43(es.EntityId(t43));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.BridgeKind())));
  auto v65 = e.BridgeKindName();
  std::string s65(v65.data(), v65.size());
  b.setVal65(s65);
  auto t44 = e.LParenToken();
  b.setVal44(es.EntityId(t44));
}

void SerializeCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CallExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ADLCallKind())));
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
  b.setVal88(e.HasStoredFPFeatures());
  b.setVal89(e.HasUnusedResultAttribute());
  b.setVal90(e.IsBuiltinAssumeFalse());
  b.setVal91(e.IsCallToStdMove());
  b.setVal92(e.IsUnevaluatedBuiltinCall());
  b.setVal94(e.UsesADL());
}

void SerializeCXXOperatorCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXOperatorCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t44 = e.OperatorToken();
  b.setVal44(es.EntityId(t44));
  b.setVal96(e.IsAssignmentOperation());
  b.setVal97(e.IsComparisonOperation());
  b.setVal98(e.IsInfixBinaryOperation());
}

void SerializeCXXMemberCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXMemberCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
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

void SerializeCUDAKernelCallExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CUDAKernelCallExpr &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.Config()));
}

void SerializeUserDefinedLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UserDefinedLiteral &e, const TokenTree *) {
  SerializeCallExpr(es, b, e, nullptr);
  b.setVal44(es.EntityId(e.CookedLiteral()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.LiteralOperatorKind())));
  auto t45 = e.UDSuffixToken();
  b.setVal45(es.EntityId(t45));
}

void SerializeCXXUuidofExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUuidofExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.IsTypeOperand());
}

void SerializeCXXUnresolvedConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXUnresolvedConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.IsListInitialization());
}

void SerializeCXXTypeidExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTypeidExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v38 = e.ExpressionOperand();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  b.setVal39(es.EntityId(e.TypeOperand()));
  b.setVal40(es.EntityId(e.TypeOperandSourceInfo()));
  auto v88 = e.IsMostDerived();
  if (v88) {
    b.setVal88(static_cast<bool>(v88.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  b.setVal90(e.IsPotentiallyEvaluated());
  b.setVal91(e.IsTypeOperand());
}

void SerializeCXXThrowExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThrowExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v38 = e.SubExpression();
  if (v38) {
    auto id38 = es.EntityId(v38.value());
    b.setVal38(id38);
  } else {
    b.setVal38(mx::kInvalidEntityId);
  }
  auto t39 = e.ThrowToken();
  b.setVal39(es.EntityId(t39));
  b.setVal88(e.IsThrownVariableInScope());
}

void SerializeCXXThisExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXThisExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal88(e.IsImplicit());
}

void SerializeCXXStdInitializerListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXStdInitializerListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeCXXScalarValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXScalarValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.RParenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXRewrittenBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXRewrittenBinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal41(es.EntityId(e.SemanticForm()));
  b.setVal88(e.IsAssignmentOperation());
  b.setVal89(e.IsComparisonOperation());
  b.setVal90(e.IsReversed());
}

void SerializeCXXPseudoDestructorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXPseudoDestructorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.HasQualifier());
  b.setVal89(e.IsArrow());
}

void SerializeCXXNullPtrLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNullPtrLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeCXXNoexceptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNoexceptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Operand()));
  b.setVal88(e.Value());
}

void SerializeCXXNewExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXNewExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.DoesUsualArrayDeleteWantSize());
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
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.InitializationStyle())));
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
  b.setVal89(e.HasInitializer());
  b.setVal90(e.IsArray());
  b.setVal91(e.IsGlobalNew());
  b.setVal92(e.IsParenthesisTypeId());
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

void SerializeCXXInheritedCtorInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXInheritedCtorInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.ConstructsVirtualBase());
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
  b.setVal38(es.EntityId(e.Constructor()));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  b.setVal89(e.InheritedFromVirtualBase());
}

void SerializeCXXFoldExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXFoldExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Callee()));
  auto t39 = e.EllipsisToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.Initializer()));
  b.setVal41(es.EntityId(e.LHS()));
  auto t42 = e.LParenToken();
  b.setVal42(es.EntityId(t42));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Operator())));
  b.setVal43(es.EntityId(e.Pattern()));
  b.setVal44(es.EntityId(e.RHS()));
  auto t45 = e.RParenToken();
  b.setVal45(es.EntityId(t45));
  b.setVal88(e.IsLeftFold());
  b.setVal89(e.IsRightFold());
}

void SerializeCXXDependentScopeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDependentScopeMemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
  b.setVal90(e.IsArrow());
  b.setVal91(e.IsImplicitAccess());
}

void SerializeCXXDeleteExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDeleteExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.DoesUsualArrayDeleteWantSize());
  b.setVal38(es.EntityId(e.Argument()));
  b.setVal39(es.EntityId(e.DestroyedType()));
  b.setVal40(es.EntityId(e.OperatorDelete()));
  b.setVal89(e.IsArrayForm());
  b.setVal90(e.IsArrayFormAsWritten());
  b.setVal91(e.IsGlobalDelete());
}

void SerializeCXXDefaultInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeCXXDefaultArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXDefaultArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Expression()));
  b.setVal39(es.EntityId(e.Parameter()));
  auto t40 = e.UsedToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeCXXConstructExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXConstructExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  do {
    auto v15 = e.Arguments();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ConstructionKind())));
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
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.IsElidable());
  b.setVal90(e.IsListInitialization());
  b.setVal91(e.IsStdInitializerListInitialization());
  b.setVal92(e.RequiresZeroInitialization());
}

void SerializeCXXTemporaryObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXTemporaryObjectExpr &e, const TokenTree *) {
  SerializeCXXConstructExpr(es, b, e, nullptr);
}

void SerializeCXXBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal88(e.Value());
}

void SerializeCXXBindTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CXXBindTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeBlockExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BlockExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.BlockDeclaration()));
  b.setVal39(es.EntityId(e.Body()));
  auto t40 = e.CaretToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.FunctionType()));
}

void SerializeBinaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.LHS()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto v60 = e.OpcodeString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto t39 = e.OperatorToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.RHS()));
  b.setVal88(e.HasStoredFPFeatures());
  b.setVal89(e.IsAdditiveOperation());
  b.setVal90(e.IsAssignmentOperation());
  b.setVal91(e.IsBitwiseOperation());
  b.setVal92(e.IsCommaOperation());
  b.setVal94(e.IsComparisonOperation());
  b.setVal96(e.IsCompoundAssignmentOperation());
  b.setVal97(e.IsEqualityOperation());
  b.setVal98(e.IsLogicalOperation());
  b.setVal99(e.IsMultiplicativeOperation());
  b.setVal100(e.IsPointerMemoryOperation());
  b.setVal101(e.IsRelationalOperation());
  b.setVal102(e.IsShiftAssignOperation());
  b.setVal103(e.IsShiftOperation());
}

void SerializeCompoundAssignOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CompoundAssignOperator &e, const TokenTree *) {
  SerializeBinaryOperator(es, b, e, nullptr);
  b.setVal41(es.EntityId(e.ComputationLHSType()));
  b.setVal42(es.EntityId(e.ComputationResultType()));
}

void SerializeAtomicExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AtomicExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Operation())));
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
  b.setVal88(e.IsCmpXChg());
  b.setVal89(e.IsOpenCL());
  b.setVal90(e.IsVolatile());
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

void SerializeAsTypeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AsTypeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SrcExpression()));
}

void SerializeArrayTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.DimensionExpression()));
  b.setVal39(es.EntityId(e.QueriedType()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
}

void SerializeArraySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArraySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  b.setVal40(es.EntityId(e.LHS()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.RHS()));
}

void SerializeArrayInitLoopExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitLoopExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.CommonExpression()));
  b.setVal39(es.EntityId(e.SubExpression()));
}

void SerializeArrayInitIndexExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ArrayInitIndexExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeAddrLabelExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AddrLabelExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AmpAmpToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Label()));
  auto t40 = e.LabelToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeAbstractConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AbstractConditionalOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.ColonToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Condition()));
  b.setVal40(es.EntityId(e.FalseExpression()));
  auto t41 = e.QuestionToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TrueExpression()));
}

void SerializeConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal43(es.EntityId(e.LHS()));
  b.setVal44(es.EntityId(e.RHS()));
}

void SerializeBinaryConditionalOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::BinaryConditionalOperator &e, const TokenTree *) {
  SerializeAbstractConditionalOperator(es, b, e, nullptr);
  b.setVal43(es.EntityId(e.Common()));
  b.setVal44(es.EntityId(e.OpaqueValue()));
}

void SerializeVAArgExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::VAArgExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal41(es.EntityId(e.WrittenType()));
  b.setVal88(e.IsMicrosoftABI());
}

void SerializeUnaryOperator(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryOperator &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.CanOverflow());
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Opcode())));
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SubExpression()));
  b.setVal89(e.HasStoredFPFeatures());
  b.setVal90(e.IsArithmeticOperation());
  b.setVal91(e.IsDecrementOperation());
  b.setVal92(e.IsIncrementDecrementOperation());
  b.setVal94(e.IsIncrementOperation());
  b.setVal96(e.IsPostfix());
  b.setVal97(e.IsPrefix());
}

void SerializeUnaryExprOrTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnaryExprOrTypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto t40 = e.OperatorToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal42(es.EntityId(e.TypeOfArgument()));
  b.setVal88(e.IsArgumentType());
}

void SerializeTypoExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypoExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeTypeTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::TypeTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  auto v88 = e.Value();
  if (v88) {
    b.setVal88(static_cast<bool>(v88.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
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

void SerializeSubstNonTypeTemplateParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.ParameterPack()));
  auto t39 = e.ParameterPackToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSubstNonTypeTemplateParmExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SubstNonTypeTemplateParmExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.NameToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Parameter()));
  b.setVal40(es.EntityId(e.ParameterType()));
  b.setVal41(es.EntityId(e.Replacement()));
  b.setVal88(e.IsReferenceParameter());
}

void SerializeStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v88 = e.ContainsNonAscii();
  if (v88) {
    b.setVal88(static_cast<bool>(v88.value()));
    b.setVal89(true);
  } else {
    b.setVal89(false);
  }
  auto v90 = e.ContainsNonAsciiOrNull();
  if (v90) {
    b.setVal90(static_cast<bool>(v90.value()));
    b.setVal91(true);
  } else {
    b.setVal91(false);
  }
  auto v60 = e.Bytes();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Kind())));
  auto v65 = e.String();
  if (v65) {
    if (v65->empty()) {
      b.setVal65("");
    } else {
      std::string s65(v65->data(), v65->size());
      b.setVal65(s65);
    }
    b.setVal92(true);
  } else {
    b.setVal92(false);
  }
  b.setVal94(e.IsOrdinary());
  b.setVal96(e.IsPascal());
  b.setVal97(e.IsUTF16());
  b.setVal98(e.IsUTF32());
  b.setVal99(e.IsUTF8());
  b.setVal100(e.IsWide());
}

void SerializeStmtExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::StmtExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubStatement()));
}

void SerializeSourceLocExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SourceLocExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto v60 = e.BuiltinString();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal88(e.IsIntType());
}

void SerializeSizeOfPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SizeOfPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Pack()));
  auto v104 = e.PackLength();
  if (v104) {
    b.setVal104(static_cast<unsigned>(v104.value()));
    b.setVal88(true);
  } else {
    b.setVal88(false);
  }
  auto t40 = e.PackToken();
  b.setVal40(es.EntityId(t40));
  do {
    auto ov15 = e.PartialArguments();
    if (!ov15) {
      b.setVal89(false);
      break;
    }
    b.setVal89(true);
    auto v15 = std::move(*ov15);
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
  b.setVal90(e.IsPartiallySubstituted());
}

void SerializeShuffleVectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ShuffleVectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.BuiltinToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeSYCLUniqueStableNameExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SYCLUniqueStableNameExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal60(e.ComputeName());
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeRequiresExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RequiresExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.IsSatisfied());
}

void SerializeRecoveryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::RecoveryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializePseudoObjectExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PseudoObjectExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializePredefinedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PredefinedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.FunctionName()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.IdentifierKind())));
  auto v60 = e.IdentifierKindName();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
  auto t39 = e.Token();
  b.setVal39(es.EntityId(t39));
}

void SerializeParenListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeParenExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ParenExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.LParenToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.SubExpression()));
}

void SerializePackExpansionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::PackExpansionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.EllipsisToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Pattern()));
}

void SerializeOverloadExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OverloadExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.HasExplicitTemplateArguments());
  b.setVal89(e.HasTemplateKeyword());
}

void SerializeUnresolvedMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedMemberExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal43(es.EntityId(e.Base()));
  b.setVal44(es.EntityId(e.BaseType()));
  auto t45 = e.MemberToken();
  b.setVal45(es.EntityId(t45));
  auto t46 = e.OperatorToken();
  b.setVal46(es.EntityId(t46));
  b.setVal90(e.HasUnresolvedUsing());
  b.setVal91(e.IsArrow());
  b.setVal92(e.IsImplicitAccess());
}

void SerializeUnresolvedLookupExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::UnresolvedLookupExpr &e, const TokenTree *) {
  SerializeOverloadExpr(es, b, e, nullptr);
  b.setVal90(e.IsOverloaded());
  b.setVal91(e.RequiresADL());
}

void SerializeOpaqueValueExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OpaqueValueExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.SourceExpression()));
  b.setVal88(e.IsUnique());
}

void SerializeOffsetOfExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OffsetOfExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.OperatorToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCSubscriptRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSubscriptRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.AtIndexMethodDeclaration()));
  b.setVal39(es.EntityId(e.BaseExpression()));
  b.setVal40(es.EntityId(e.KeyExpression()));
  auto t41 = e.RBracketToken();
  b.setVal41(es.EntityId(t41));
  b.setVal88(e.IsArraySubscriptReferenceExpression());
}

void SerializeObjCStringLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCStringLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.String()));
}

void SerializeObjCSelectorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCSelectorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.RParenToken();
  b.setVal39(es.EntityId(t39));
}

void SerializeObjCProtocolExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCProtocolExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Protocol()));
  auto t40 = e.ProtocolIdToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.RParenToken();
  b.setVal41(es.EntityId(t41));
}

void SerializeObjCPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.IsClassReceiver());
  b.setVal89(e.IsExplicitProperty());
  b.setVal90(e.IsImplicitProperty());
  b.setVal91(e.IsMessagingGetter());
  b.setVal92(e.IsMessagingSetter());
  b.setVal94(e.IsObjectReceiver());
  b.setVal96(e.IsSuperReceiver());
}

void SerializeObjCMessageExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCMessageExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.MethodFamily())));
  b.setVal44(es.EntityId(e.ReceiverInterface()));
  b.setVal95(static_cast<unsigned char>(mx::FromPasta(e.ReceiverKind())));
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
  b.setVal88(e.IsClassMessage());
  b.setVal89(e.IsDelegateInitializerCall());
  b.setVal90(e.IsImplicit());
  b.setVal91(e.IsInstanceMessage());
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

void SerializeObjCIvarRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIvarRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Declaration()));
  auto t40 = e.Token();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperationToken();
  b.setVal41(es.EntityId(t41));
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsFreeInstanceVariable());
}

void SerializeObjCIsaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIsaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  auto t39 = e.BaseTokenEnd();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.IsaMemberToken();
  b.setVal40(es.EntityId(t40));
  auto t41 = e.OperationToken();
  b.setVal41(es.EntityId(t41));
  b.setVal88(e.IsArrow());
}

void SerializeObjCIndirectCopyRestoreExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCIndirectCopyRestoreExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.SubExpression()));
  b.setVal88(e.ShouldCopy());
}

void SerializeObjCEncodeExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCEncodeExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.EncodedType()));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeObjCDictionaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCDictionaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.DictionaryWithObjectsMethod()));
}

void SerializeObjCBoxedExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoxedExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.AtToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.BoxingMethod()));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal88(e.IsExpressibleAsConstantInitializer());
}

void SerializeObjCBoolLiteralExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCBoolLiteralExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal88(e.Value());
}

void SerializeObjCAvailabilityCheckExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCAvailabilityCheckExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.HasVersion());
}

void SerializeObjCArrayLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ObjCArrayLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeOMPIteratorExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPIteratorExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.IteratorKwToken();
  b.setVal38(es.EntityId(t38));
  auto t39 = e.LParenToken();
  b.setVal39(es.EntityId(t39));
  auto t40 = e.RParenToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeOMPArrayShapingExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArrayShapingExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeOMPArraySectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::OMPArraySectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeNoInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::NoInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeMemberExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MemberExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.HadMultipleCandidates());
  b.setVal89(e.HasExplicitTemplateArguments());
  b.setVal90(e.HasQualifier());
  b.setVal91(e.HasTemplateKeyword());
  b.setVal92(e.IsArrow());
  b.setVal94(e.IsImplicitAccess());
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.IsNonOdrUse())));
}

void SerializeMatrixSubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MatrixSubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.ColumnIndex()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.RowIndex()));
  b.setVal88(e.IsIncomplete());
}

void SerializeMaterializeTemporaryExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MaterializeTemporaryExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.StorageDuration())));
  b.setVal40(es.EntityId(e.SubExpression()));
  b.setVal88(e.IsBoundToLvalueReference());
  b.setVal89(e.IsUsableInConstantExpressions());
}

void SerializeMSPropertySubscriptExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertySubscriptExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Base()));
  b.setVal39(es.EntityId(e.Index()));
  auto t40 = e.RBracketToken();
  b.setVal40(es.EntityId(t40));
}

void SerializeMSPropertyRefExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::MSPropertyRefExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.BaseExpression()));
  auto t39 = e.MemberToken();
  b.setVal39(es.EntityId(t39));
  b.setVal40(es.EntityId(e.PropertyDeclaration()));
  b.setVal88(e.IsArrow());
  b.setVal89(e.IsImplicitAccess());
}

void SerializeLambdaExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::LambdaExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.Body()));
  b.setVal39(es.EntityId(e.CallOperator()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.CaptureDefault())));
  auto t40 = e.CaptureDefaultToken();
  b.setVal40(es.EntityId(t40));
  b.setVal41(es.EntityId(e.CompoundStatementBody()));
  auto v42 = e.DependentCallOperator();
  if (v42) {
    auto id42 = es.EntityId(v42.value());
    b.setVal42(id42);
  } else {
    b.setVal42(mx::kInvalidEntityId);
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
  if (auto r43 = e.IntroducerRange(); auto rs43 = r43.Size()) {
    b.setVal43(es.EntityId(r43[0]));
    b.setVal44(es.EntityId(r43[rs43 - 1u]));
  } else {
    b.setVal43(0);
    b.setVal44(0);
  }
  b.setVal45(es.EntityId(e.LambdaClass()));
  auto v46 = e.TemplateParameterList();
  if (v46) {
    auto id46 = es.EntityId(v46.value());
    b.setVal46(id46);
  } else {
    b.setVal46(mx::kInvalidEntityId);
  }
  auto v47 = e.TrailingRequiresClause();
  if (v47) {
    auto id47 = es.EntityId(v47.value());
    b.setVal47(id47);
  } else {
    b.setVal47(mx::kInvalidEntityId);
  }
  b.setVal88(e.HasExplicitParameters());
  b.setVal89(e.HasExplicitResultType());
  b.setVal90(e.IsGenericLambda());
  b.setVal91(e.IsMutable());
}

void SerializeIntegerLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::IntegerLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeInitListExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::InitListExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.HadArrayRangeDesignator());
  b.setVal89(e.HasArrayFiller());
  do {
    auto v15 = e.Initializers();
    auto sv15 = b.initVal15(static_cast<unsigned>(v15.size()));
    auto i15 = 0u;
    for (const auto &e15 : v15) {
      sv15.set(i15, es.EntityId(e15));
      ++i15;
    }
  } while (false);
  b.setVal90(e.IsExplicit());
  b.setVal91(e.IsSemanticForm());
  b.setVal92(e.IsStringLiteralInitializer());
  b.setVal94(e.IsSyntacticForm());
  auto v96 = e.IsTransparent();
  if (v96) {
    b.setVal96(static_cast<bool>(v96.value()));
    b.setVal97(true);
  } else {
    b.setVal97(false);
  }
}

void SerializeImplicitValueInitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImplicitValueInitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
}

void SerializeImaginaryLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ImaginaryLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeGenericSelectionExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GenericSelectionExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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
  b.setVal88(e.IsResultDependent());
}

void SerializeGNUNullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::GNUNullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.TokenToken();
  b.setVal38(es.EntityId(t38));
}

void SerializeFunctionParmPackExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FunctionParmPackExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
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

void SerializeFullExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FullExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.SubExpression()));
}

void SerializeExprWithCleanups(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExprWithCleanups &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal88(e.CleanupsHaveSideEffects());
}

void SerializeConstantExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ConstantExpr &e, const TokenTree *) {
  SerializeFullExpr(es, b, e, nullptr);
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.ResultStorageKind())));
  b.setVal88(e.HasAPValueResult());
  b.setVal89(e.IsImmediateInvocation());
}

void SerializeFloatingLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FloatingLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
  b.setVal88(e.IsExact());
}

void SerializeFixedPointLiteral(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::FixedPointLiteral &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  auto t38 = e.Token();
  b.setVal38(es.EntityId(t38));
}

void SerializeExtVectorElementExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExtVectorElementExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal88(e.ContainsDuplicateElements());
  auto t38 = e.AccessorToken();
  b.setVal38(es.EntityId(t38));
  b.setVal39(es.EntityId(e.Base()));
  b.setVal89(e.IsArrow());
}

void SerializeExpressionTraitExpr(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::ExpressionTraitExpr &e, const TokenTree *) {
  SerializeExpr(es, b, e, nullptr);
  b.setVal38(es.EntityId(e.QueriedExpression()));
  b.setVal93(static_cast<unsigned char>(mx::FromPasta(e.Trait())));
  b.setVal88(e.Value());
}

void SerializeAttributedStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::AttributedStmt &e, const TokenTree *) {
  SerializeValueStmt(es, b, e, nullptr);
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

void SerializeSwitchStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchStmt &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeSwitchCase(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::SwitchCase &e, const TokenTree *) {
  SerializeStmt(es, b, e, nullptr);
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

void SerializeDefaultStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::DefaultStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
  auto t14 = e.DefaultToken();
  b.setVal14(es.EntityId(t14));
}

void SerializeCaseStmt(const EntityMapper &es, mx::ast::Stmt::Builder b, const pasta::CaseStmt &e, const TokenTree *) {
  SerializeSwitchCase(es, b, e, nullptr);
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
  b.setVal35(e.IsThisDeclarationReferenced());
  b.setVal36(e.IsTopLevelDeclarationInObjCContainer());
  b.setVal37(e.IsUnavailable());
  b.setVal38(e.IsUnconditionallyVisible());
  b.setVal39(e.IsWeakImported());
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

void SerializeClassScopeFunctionSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassScopeFunctionSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.Specialization()));
  b.setVal46(e.HasExplicitTemplateArguments());
}

void SerializeCapturedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CapturedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeBlockDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BlockDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeAccessSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::AccessSpecDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t45 = e.AccessSpecifierToken();
  b.setVal45(es.EntityId(t45));
  auto t52 = e.ColonToken();
  b.setVal52(es.EntityId(t52));
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
    auto v47 = e.Varlists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
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
    auto v47 = e.Varlists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeTranslationUnitDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TranslationUnitDecl &e, const TokenTree *) {
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

void SerializeStaticAssertDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::StaticAssertDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.AssertExpression()));
  b.setVal52(es.EntityId(e.Message()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
  b.setVal46(e.IsFailed());
}

void SerializeRequiresExprBodyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RequiresExprBodyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  pasta::DeclContext dc47(e);
  auto v47 = dc47.AlreadyLoadedDeclarations();
  auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
  auto i47 = 0u;
  for (const pasta::Decl &e47 : v47) {
    sv47.set(i47, es.EntityId(e47));
    ++i47;
  }
}

void SerializePragmaDetectMismatchDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaDetectMismatchDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v59 = e.Name();
  std::string s59(v59.data(), v59.size());
  b.setVal59(s59);
  auto v60 = e.Value();
  std::string s60(v60.data(), v60.size());
  b.setVal60(s60);
}

void SerializePragmaCommentDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::PragmaCommentDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto v59 = e.Argument();
  std::string s59(v59.data(), v59.size());
  b.setVal59(s59);
  b.setVal61(static_cast<unsigned char>(mx::FromPasta(e.CommentKind())));
}

void SerializeObjCPropertyImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeNamedDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamedDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeLabelDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LabelDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto v69 = e.MSAssemblyLabel();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal52(es.EntityId(e.Statement()));
  b.setVal70(e.IsGnuLocal());
  b.setVal71(e.IsMSAssemblyLabel());
  b.setVal72(e.IsResolvedMSAssemblyLabel());
}

void SerializeBaseUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::BaseUsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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

void SerializeUsingEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingEnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  b.setVal52(es.EntityId(e.EnumDeclaration()));
  auto t53 = e.EnumToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.UsingToken();
  b.setVal54(es.EntityId(t54));
}

void SerializeUsingDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeBaseUsingDecl(es, b, e, nullptr);
  auto t52 = e.UsingToken();
  b.setVal52(es.EntityId(t52));
  b.setVal70(e.HasTypename());
  b.setVal71(e.IsAccessDeclaration());
}

void SerializeValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal52(es.EntityId(e.Type()));
  b.setVal70(e.IsWeak());
}

void SerializeUnresolvedUsingValueDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingValueDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto t53 = e.EllipsisToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.UsingToken();
  b.setVal54(es.EntityId(t54));
  b.setVal71(e.IsAccessDeclaration());
  b.setVal72(e.IsPackExpansion());
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

void SerializeEnumConstantDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumConstantDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
  auto v53 = e.InitializerExpression();
  if (v53) {
    auto id53 = es.EntityId(v53.value());
    b.setVal53(id53);
  } else {
    b.setVal53(mx::kInvalidEntityId);
  }
}

void SerializeDeclaratorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DeclaratorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeValueDecl(es, b, e, nullptr);
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
    auto v47 = e.TemplateParameterLists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v73 = e.ActingDefinition();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v75 = e.DescribedVariableTemplate();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
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
}

void SerializeParmVarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ParmVarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
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
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.ParameterKind())));
}

void SerializeDecompositionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::DecompositionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  do {
    auto v48 = e.Bindings();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
}

void SerializeVarTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarDecl(es, b, e, nullptr);
  auto t123 = e.ExternToken();
  b.setVal123(es.EntityId(t123));
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal124(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v48 = e.TemplateArguments();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
  do {
    auto v58 = e.TemplateInstantiationArguments();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
    }
  } while (false);
  auto t125 = e.TemplateKeywordToken();
  b.setVal125(es.EntityId(t125));
  b.setVal127(es.EntityId(e.TypeAsWritten()));
  b.setVal129(e.IsClassScopeExplicitSpecialization());
  b.setVal130(e.IsExplicitInstantiationOrSpecialization());
  b.setVal131(e.IsExplicitSpecialization());
}

void SerializeVarTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeVarTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal128(es.EntityId(e.InstantiatedFromMember()));
  b.setVal136(es.EntityId(e.TemplateParameters()));
  b.setVal132(e.HasAssociatedConstraints());
}

void SerializeNonTypeTemplateParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NonTypeTemplateParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal71(e.DefaultArgumentWasInherited());
  auto v73 = e.DefaultArgument();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto t75 = e.DefaultArgumentToken();
  b.setVal75(es.EntityId(t75));
  auto v76 = e.PlaceholderTypeConstraint();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  b.setVal72(e.HasDefaultArgument());
  b.setVal88(e.HasPlaceholderTypeConstraint());
  b.setVal89(e.IsExpandedParameterPack());
  b.setVal90(e.IsPackExpansion());
  do {
    auto v48 = e.ExpansionTypes();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
    }
  } while (false);
}

void SerializeMSPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::MSPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  b.setVal71(e.HasGetter());
  b.setVal72(e.HasSetter());
}

void SerializeFunctionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
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
  b.setVal75(es.EntityId(e.DeclaredReturnType()));
  auto v76 = e.DescribedFunctionTemplate();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
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
  auto v123 = e.InstantiatedFromMemberFunction();
  if (v123) {
    auto id123 = es.EntityId(v123.value());
    b.setVal123(id123);
  } else {
    b.setVal123(mx::kInvalidEntityId);
  }
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.LanguageLinkage())));
  b.setVal82(static_cast<unsigned char>(mx::FromPasta(e.MultiVersionKind())));
  auto v137 = e.ODRHash();
  if (v137) {
    b.setVal137(static_cast<unsigned>(v137.value()));
    b.setVal90(true);
  } else {
    b.setVal90(false);
  }
  b.setVal83(static_cast<unsigned char>(mx::FromPasta(e.OverloadedOperator())));
  if (auto r124 = e.ParametersSourceRange(); auto rs124 = r124.Size()) {
    b.setVal124(es.EntityId(r124[0]));
    b.setVal125(es.EntityId(r124[rs124 - 1u]));
  } else {
    b.setVal124(0);
    b.setVal125(0);
  }
  auto t127 = e.PointOfInstantiation();
  b.setVal127(es.EntityId(t127));
  auto v128 = e.PrimaryTemplate();
  if (v128) {
    auto id128 = es.EntityId(v128.value());
    b.setVal128(id128);
  } else {
    b.setVal128(mx::kInvalidEntityId);
  }
  b.setVal136(es.EntityId(e.ReturnType()));
  if (auto r138 = e.ReturnTypeSourceRange(); auto rs138 = r138.Size()) {
    b.setVal138(es.EntityId(r138[0]));
    b.setVal139(es.EntityId(r138[rs138 - 1u]));
  } else {
    b.setVal138(0);
    b.setVal139(0);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.StorageClass())));
  auto v140 = e.TemplateInstantiationPattern();
  if (v140) {
    auto id140 = es.EntityId(v140.value());
    b.setVal140(id140);
  } else {
    b.setVal140(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKindForInstantiation())));
  b.setVal126(static_cast<unsigned char>(mx::FromPasta(e.TemplatedKind())));
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
  b.setVal141(e.IsReplaceableGlobalAllocationFunction());
  auto v142 = e.IsReservedGlobalPlacementOperator();
  if (v142) {
    b.setVal142(static_cast<bool>(v142.value()));
    b.setVal143(true);
  } else {
    b.setVal143(false);
  }
  b.setVal144(e.IsStatic());
  b.setVal145(e.IsTargetClonesMultiVersion());
  b.setVal146(e.IsTargetMultiVersion());
  b.setVal147(e.IsTemplateInstantiation());
  b.setVal148(e.IsThisDeclarationADefinition());
  b.setVal149(e.IsThisDeclarationInstantiatedFromAFriendDefinition());
  b.setVal150(e.IsTrivial());
  b.setVal151(e.IsTrivialForCall());
  b.setVal152(e.IsUserProvided());
  b.setVal153(e.IsVariadic());
  b.setVal154(e.IsVirtualAsWritten());
  do {
    auto v48 = e.Parameters();
    auto sv48 = b.initVal48(static_cast<unsigned>(v48.size()));
    auto i48 = 0u;
    for (const auto &e48 : v48) {
      sv48.set(i48, es.EntityId(e48));
      ++i48;
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
  pasta::DeclContext dc58(e);
  auto v58 = dc58.AlreadyLoadedDeclarations();
  auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
  auto i58 = 0u;
  for (const pasta::Decl &e58 : v58) {
    sv58.set(i58, es.EntityId(e58));
    ++i58;
  }
}

void SerializeCXXMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal158(static_cast<unsigned char>(mx::FromPasta(e.ReferenceQualifier())));
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
    auto v169 = e.OverriddenMethods();
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
}

void SerializeCXXDestructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDestructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
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

void SerializeCXXConversionDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConversionDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
  b.setVal170(es.EntityId(e.ConversionType()));
  b.setVal172(e.IsExplicit());
  b.setVal173(e.IsLambdaToBlockPointerConversion());
}

void SerializeCXXConstructorDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXConstructorDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXMethodDecl(es, b, e, nullptr);
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

void SerializeCXXDeductionGuideDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXDeductionGuideDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFunctionDecl(es, b, e, nullptr);
  b.setVal159(es.EntityId(e.CorrespondingConstructor()));
  b.setVal160(es.EntityId(e.DeducedTemplate()));
  b.setVal161(e.IsCopyDeductionCandidate());
  b.setVal162(e.IsExplicit());
}

void SerializeFieldDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FieldDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDeclaratorDecl(es, b, e, nullptr);
  auto v73 = e.BitWidth();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v75 = e.CapturedVLAType();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.InClassInitializerStyle())));
  auto v76 = e.InClassInitializer();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
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

void SerializeObjCIvarDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCIvarDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeFieldDecl(es, b, e, nullptr);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.AccessControl())));
  b.setVal81(static_cast<unsigned char>(mx::FromPasta(e.CanonicalAccessControl())));
  b.setVal77(es.EntityId(e.ContainingInterface()));
  b.setVal78(es.EntityId(e.NextInstanceVariable()));
  b.setVal94(e.Synthesize());
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
  b.setVal53(es.EntityId(e.Binding()));
  b.setVal54(es.EntityId(e.DecomposedDeclaration()));
  b.setVal62(es.EntityId(e.HoldingVariable()));
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

void SerializeUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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

void SerializeConstructorUsingShadowDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ConstructorUsingShadowDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeUsingShadowDecl(es, b, e, nullptr);
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

void SerializeUsingPackDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingPackDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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

void SerializeUsingDirectiveDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UsingDirectiveDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t52 = e.IdentifierToken();
  b.setVal52(es.EntityId(t52));
  auto t53 = e.NamespaceKeyToken();
  b.setVal53(es.EntityId(t53));
  b.setVal54(es.EntityId(e.NominatedNamespaceAsWritten()));
  auto t62 = e.UsingToken();
  b.setVal62(es.EntityId(t62));
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
  auto v52 = e.TypeForDeclaration();
  if (v52) {
    auto id52 = es.EntityId(v52.value());
    b.setVal52(id52);
  } else {
    b.setVal52(mx::kInvalidEntityId);
  }
}

void SerializeTemplateTypeParmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateTypeParmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
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

void SerializeTagDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TagDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
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
  b.setVal96(e.IsThisDeclarationADefinition());
  b.setVal97(e.IsThisDeclarationADemotedDefinition());
  b.setVal98(e.IsUnion());
  b.setVal99(e.MayHaveOutOfDateDefinition());
  do {
    auto v47 = e.TemplateParameterLists();
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

void SerializeRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  b.setVal100(e.CanPassInRegisters());
  do {
    auto v58 = e.Fields();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
    }
  } while (false);
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.ArgumentPassingRestrictions())));
  b.setVal101(e.HasFlexibleArrayMember());
  b.setVal102(e.HasLoadedFieldsFromExternalStorage());
  b.setVal103(e.HasNonTrivialToPrimitiveCopyCUnion());
  b.setVal104(e.HasNonTrivialToPrimitiveDefaultInitializeCUnion());
  b.setVal105(e.HasNonTrivialToPrimitiveDestructCUnion());
  b.setVal106(e.HasObjectMember());
  b.setVal107(e.HasVolatileMember());
  b.setVal108(e.IsAnonymousStructOrUnion());
  b.setVal109(e.IsCapturedRecord());
  b.setVal110(e.IsInjectedClassName());
  b.setVal111(e.IsLambda());
  b.setVal112(e.IsMsStruct());
  b.setVal113(e.IsNonTrivialToPrimitiveCopy());
  b.setVal114(e.IsNonTrivialToPrimitiveDefaultInitialize());
  b.setVal115(e.IsNonTrivialToPrimitiveDestroy());
  b.setVal116(e.IsOrContainsUnion());
  b.setVal117(e.IsParameterDestroyedInCallee());
  b.setVal118(e.IsRandomized());
  b.setVal119(e.MayInsertExtraPadding());
}

void SerializeCXXRecordDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::CXXRecordDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRecordDecl(es, b, e, nullptr);
  auto v120 = e.AllowConstDefaultInitializer();
  if (v120) {
    b.setVal120(static_cast<bool>(v120.value()));
    b.setVal121(true);
  } else {
    b.setVal121(false);
  }
  do {
    auto ov169 = e.Bases();
    if (!ov169) {
      b.setVal122(false);
      break;
    }
    b.setVal122(true);
    auto v169 = std::move(*ov169);
    auto sv169 = b.initVal169(static_cast<unsigned>(v169.size()));
    auto i169 = 0u;
    for (const auto &e169 : v169) {
      sv169.set(i169, es.EntityId(e169));
      ++i169;
    }
  } while (false);
  auto v81 = e.CalculateInheritanceModel();
  if (v81) {
    b.setVal81(static_cast<unsigned char>(v81.value()));
    b.setVal129(true);
  } else {
    b.setVal129(false);
  }
  do {
    auto v177 = e.Constructors();
    auto sv177 = b.initVal177(static_cast<unsigned>(v177.size()));
    auto i177 = 0u;
    for (const auto &e177 : v177) {
      sv177.set(i177, es.EntityId(e177));
      ++i177;
    }
  } while (false);
  do {
    auto ov178 = e.Friends();
    if (!ov178) {
      b.setVal130(false);
      break;
    }
    b.setVal130(true);
    auto v178 = std::move(*ov178);
    auto sv178 = b.initVal178(static_cast<unsigned>(v178.size()));
    auto i178 = 0u;
    for (const auto &e178 : v178) {
      sv178.set(i178, es.EntityId(e178));
      ++i178;
    }
  } while (false);
  auto v73 = e.DependentLambdaCallOperator();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
  }
  auto v75 = e.DescribedClassTemplate();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  auto v76 = e.Destructor();
  if (v76) {
    auto id76 = es.EntityId(v76.value());
    b.setVal76(id76);
  } else {
    b.setVal76(mx::kInvalidEntityId);
  }
  auto v77 = e.GenericLambdaTemplateParameterList();
  if (v77) {
    auto id77 = es.EntityId(v77.value());
    b.setVal77(id77);
  } else {
    b.setVal77(mx::kInvalidEntityId);
  }
  auto v78 = e.InstantiatedFromMemberClass();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
  }
  auto v80 = e.LambdaCallOperator();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  auto v82 = e.LambdaCaptureDefault();
  if (v82) {
    b.setVal82(static_cast<unsigned char>(v82.value()));
    b.setVal131(true);
  } else {
    b.setVal131(false);
  }
  auto v85 = e.LambdaContextDeclaration();
  if (v85) {
    auto id85 = es.EntityId(v85.value());
    b.setVal85(id85);
  } else {
    b.setVal85(mx::kInvalidEntityId);
  }
  do {
    auto ov179 = e.LambdaExplicitTemplateParameters();
    if (!ov179) {
      b.setVal132(false);
      break;
    }
    b.setVal132(true);
    auto v179 = std::move(*ov179);
    auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
    auto i179 = 0u;
    for (const auto &e179 : v179) {
      sv179.set(i179, es.EntityId(e179));
      ++i179;
    }
  } while (false);
  auto v137 = e.LambdaManglingNumber();
  if (v137) {
    b.setVal137(static_cast<unsigned>(v137.value()));
    b.setVal133(true);
  } else {
    b.setVal133(false);
  }
  auto v123 = e.LambdaType();
  if (v123) {
    auto id123 = es.EntityId(v123.value());
    b.setVal123(id123);
  } else {
    b.setVal123(mx::kInvalidEntityId);
  }
  auto v83 = e.MSInheritanceModel();
  if (v83) {
    b.setVal83(static_cast<unsigned char>(v83.value()));
    b.setVal134(true);
  } else {
    b.setVal134(false);
  }
  b.setVal84(static_cast<unsigned char>(mx::FromPasta(e.MSVtorDispMode())));
  auto v180 = e.ODRHash();
  if (v180) {
    b.setVal180(static_cast<unsigned>(v180.value()));
    b.setVal135(true);
  } else {
    b.setVal135(false);
  }
  auto v124 = e.TemplateInstantiationPattern();
  if (v124) {
    auto id124 = es.EntityId(v124.value());
    b.setVal124(id124);
  } else {
    b.setVal124(mx::kInvalidEntityId);
  }
  b.setVal86(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  auto v141 = e.HasAnyDependentBases();
  if (v141) {
    b.setVal141(static_cast<bool>(v141.value()));
    b.setVal142(true);
  } else {
    b.setVal142(false);
  }
  auto v143 = e.HasConstexprDefaultConstructor();
  if (v143) {
    b.setVal143(static_cast<bool>(v143.value()));
    b.setVal144(true);
  } else {
    b.setVal144(false);
  }
  auto v145 = e.HasConstexprDestructor();
  if (v145) {
    b.setVal145(static_cast<bool>(v145.value()));
    b.setVal146(true);
  } else {
    b.setVal146(false);
  }
  auto v147 = e.HasConstexprNonCopyMoveConstructor();
  if (v147) {
    b.setVal147(static_cast<bool>(v147.value()));
    b.setVal148(true);
  } else {
    b.setVal148(false);
  }
  auto v149 = e.HasCopyAssignmentWithConstParameter();
  if (v149) {
    b.setVal149(static_cast<bool>(v149.value()));
    b.setVal150(true);
  } else {
    b.setVal150(false);
  }
  auto v151 = e.HasCopyConstructorWithConstParameter();
  if (v151) {
    b.setVal151(static_cast<bool>(v151.value()));
    b.setVal152(true);
  } else {
    b.setVal152(false);
  }
  auto v153 = e.HasDefaultConstructor();
  if (v153) {
    b.setVal153(static_cast<bool>(v153.value()));
    b.setVal154(true);
  } else {
    b.setVal154(false);
  }
  auto v155 = e.HasDefinition();
  if (v155) {
    b.setVal155(static_cast<bool>(v155.value()));
    b.setVal156(true);
  } else {
    b.setVal156(false);
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
    b.setVal164(true);
  } else {
    b.setVal164(false);
  }
  auto v165 = e.HasInClassInitializer();
  if (v165) {
    b.setVal165(static_cast<bool>(v165.value()));
    b.setVal166(true);
  } else {
    b.setVal166(false);
  }
  auto v167 = e.HasInheritedAssignment();
  if (v167) {
    b.setVal167(static_cast<bool>(v167.value()));
    b.setVal168(true);
  } else {
    b.setVal168(false);
  }
  auto v172 = e.HasInheritedConstructor();
  if (v172) {
    b.setVal172(static_cast<bool>(v172.value()));
    b.setVal173(true);
  } else {
    b.setVal173(false);
  }
  auto v174 = e.HasInitializerMethod();
  if (v174) {
    b.setVal174(static_cast<bool>(v174.value()));
    b.setVal175(true);
  } else {
    b.setVal175(false);
  }
  auto v176 = e.HasIrrelevantDestructor();
  if (v176) {
    b.setVal176(static_cast<bool>(v176.value()));
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
  auto v184 = e.HasMoveAssignment();
  if (v184) {
    b.setVal184(static_cast<bool>(v184.value()));
    b.setVal185(true);
  } else {
    b.setVal185(false);
  }
  auto v186 = e.HasMoveConstructor();
  if (v186) {
    b.setVal186(static_cast<bool>(v186.value()));
    b.setVal187(true);
  } else {
    b.setVal187(false);
  }
  auto v188 = e.HasMutableFields();
  if (v188) {
    b.setVal188(static_cast<bool>(v188.value()));
    b.setVal189(true);
  } else {
    b.setVal189(false);
  }
  auto v190 = e.HasNonLiteralTypeFieldsOrBases();
  if (v190) {
    b.setVal190(static_cast<bool>(v190.value()));
    b.setVal191(true);
  } else {
    b.setVal191(false);
  }
  auto v192 = e.HasNonTrivialCopyAssignment();
  if (v192) {
    b.setVal192(static_cast<bool>(v192.value()));
    b.setVal193(true);
  } else {
    b.setVal193(false);
  }
  auto v194 = e.HasNonTrivialCopyConstructor();
  if (v194) {
    b.setVal194(static_cast<bool>(v194.value()));
    b.setVal195(true);
  } else {
    b.setVal195(false);
  }
  auto v196 = e.HasNonTrivialCopyConstructorForCall();
  if (v196) {
    b.setVal196(static_cast<bool>(v196.value()));
    b.setVal197(true);
  } else {
    b.setVal197(false);
  }
  auto v198 = e.HasNonTrivialDefaultConstructor();
  if (v198) {
    b.setVal198(static_cast<bool>(v198.value()));
    b.setVal199(true);
  } else {
    b.setVal199(false);
  }
  auto v200 = e.HasNonTrivialDestructor();
  if (v200) {
    b.setVal200(static_cast<bool>(v200.value()));
    b.setVal201(true);
  } else {
    b.setVal201(false);
  }
  auto v202 = e.HasNonTrivialDestructorForCall();
  if (v202) {
    b.setVal202(static_cast<bool>(v202.value()));
    b.setVal203(true);
  } else {
    b.setVal203(false);
  }
  auto v204 = e.HasNonTrivialMoveAssignment();
  if (v204) {
    b.setVal204(static_cast<bool>(v204.value()));
    b.setVal205(true);
  } else {
    b.setVal205(false);
  }
  auto v206 = e.HasNonTrivialMoveConstructor();
  if (v206) {
    b.setVal206(static_cast<bool>(v206.value()));
    b.setVal207(true);
  } else {
    b.setVal207(false);
  }
  auto v208 = e.HasNonTrivialMoveConstructorForCall();
  if (v208) {
    b.setVal208(static_cast<bool>(v208.value()));
    b.setVal209(true);
  } else {
    b.setVal209(false);
  }
  auto v210 = e.HasPrivateFields();
  if (v210) {
    b.setVal210(static_cast<bool>(v210.value()));
    b.setVal211(true);
  } else {
    b.setVal211(false);
  }
  auto v212 = e.HasProtectedFields();
  if (v212) {
    b.setVal212(static_cast<bool>(v212.value()));
    b.setVal213(true);
  } else {
    b.setVal213(false);
  }
  auto v214 = e.HasSimpleCopyAssignment();
  if (v214) {
    b.setVal214(static_cast<bool>(v214.value()));
    b.setVal215(true);
  } else {
    b.setVal215(false);
  }
  auto v216 = e.HasSimpleCopyConstructor();
  if (v216) {
    b.setVal216(static_cast<bool>(v216.value()));
    b.setVal217(true);
  } else {
    b.setVal217(false);
  }
  auto v218 = e.HasSimpleDestructor();
  if (v218) {
    b.setVal218(static_cast<bool>(v218.value()));
    b.setVal219(true);
  } else {
    b.setVal219(false);
  }
  auto v220 = e.HasSimpleMoveAssignment();
  if (v220) {
    b.setVal220(static_cast<bool>(v220.value()));
    b.setVal221(true);
  } else {
    b.setVal221(false);
  }
  auto v222 = e.HasSimpleMoveConstructor();
  if (v222) {
    b.setVal222(static_cast<bool>(v222.value()));
    b.setVal223(true);
  } else {
    b.setVal223(false);
  }
  auto v224 = e.HasTrivialCopyAssignment();
  if (v224) {
    b.setVal224(static_cast<bool>(v224.value()));
    b.setVal225(true);
  } else {
    b.setVal225(false);
  }
  auto v226 = e.HasTrivialCopyConstructor();
  if (v226) {
    b.setVal226(static_cast<bool>(v226.value()));
    b.setVal227(true);
  } else {
    b.setVal227(false);
  }
  auto v228 = e.HasTrivialCopyConstructorForCall();
  if (v228) {
    b.setVal228(static_cast<bool>(v228.value()));
    b.setVal229(true);
  } else {
    b.setVal229(false);
  }
  auto v230 = e.HasTrivialDefaultConstructor();
  if (v230) {
    b.setVal230(static_cast<bool>(v230.value()));
    b.setVal231(true);
  } else {
    b.setVal231(false);
  }
  auto v232 = e.HasTrivialDestructor();
  if (v232) {
    b.setVal232(static_cast<bool>(v232.value()));
    b.setVal233(true);
  } else {
    b.setVal233(false);
  }
  auto v234 = e.HasTrivialDestructorForCall();
  if (v234) {
    b.setVal234(static_cast<bool>(v234.value()));
    b.setVal235(true);
  } else {
    b.setVal235(false);
  }
  auto v236 = e.HasTrivialMoveAssignment();
  if (v236) {
    b.setVal236(static_cast<bool>(v236.value()));
    b.setVal237(true);
  } else {
    b.setVal237(false);
  }
  auto v238 = e.HasTrivialMoveConstructor();
  if (v238) {
    b.setVal238(static_cast<bool>(v238.value()));
    b.setVal239(true);
  } else {
    b.setVal239(false);
  }
  auto v240 = e.HasTrivialMoveConstructorForCall();
  if (v240) {
    b.setVal240(static_cast<bool>(v240.value()));
    b.setVal241(true);
  } else {
    b.setVal241(false);
  }
  auto v242 = e.HasUninitializedReferenceMember();
  if (v242) {
    b.setVal242(static_cast<bool>(v242.value()));
    b.setVal243(true);
  } else {
    b.setVal243(false);
  }
  auto v244 = e.HasUserDeclaredConstructor();
  if (v244) {
    b.setVal244(static_cast<bool>(v244.value()));
    b.setVal245(true);
  } else {
    b.setVal245(false);
  }
  auto v246 = e.HasUserDeclaredCopyAssignment();
  if (v246) {
    b.setVal246(static_cast<bool>(v246.value()));
    b.setVal247(true);
  } else {
    b.setVal247(false);
  }
  auto v248 = e.HasUserDeclaredCopyConstructor();
  if (v248) {
    b.setVal248(static_cast<bool>(v248.value()));
    b.setVal249(true);
  } else {
    b.setVal249(false);
  }
  auto v250 = e.HasUserDeclaredDestructor();
  if (v250) {
    b.setVal250(static_cast<bool>(v250.value()));
    b.setVal251(true);
  } else {
    b.setVal251(false);
  }
  auto v252 = e.HasUserDeclaredMoveAssignment();
  if (v252) {
    b.setVal252(static_cast<bool>(v252.value()));
    b.setVal253(true);
  } else {
    b.setVal253(false);
  }
  auto v254 = e.HasUserDeclaredMoveConstructor();
  if (v254) {
    b.setVal254(static_cast<bool>(v254.value()));
    b.setVal255(true);
  } else {
    b.setVal255(false);
  }
  auto v256 = e.HasUserDeclaredMoveOperation();
  if (v256) {
    b.setVal256(static_cast<bool>(v256.value()));
    b.setVal257(true);
  } else {
    b.setVal257(false);
  }
  auto v258 = e.HasUserProvidedDefaultConstructor();
  if (v258) {
    b.setVal258(static_cast<bool>(v258.value()));
    b.setVal259(true);
  } else {
    b.setVal259(false);
  }
  auto v260 = e.HasVariantMembers();
  if (v260) {
    b.setVal260(static_cast<bool>(v260.value()));
    b.setVal261(true);
  } else {
    b.setVal261(false);
  }
  auto v262 = e.ImplicitCopyAssignmentHasConstParameter();
  if (v262) {
    b.setVal262(static_cast<bool>(v262.value()));
    b.setVal263(true);
  } else {
    b.setVal263(false);
  }
  auto v264 = e.ImplicitCopyConstructorHasConstParameter();
  if (v264) {
    b.setVal264(static_cast<bool>(v264.value()));
    b.setVal265(true);
  } else {
    b.setVal265(false);
  }
  auto v266 = e.IsAbstract();
  if (v266) {
    b.setVal266(static_cast<bool>(v266.value()));
    b.setVal267(true);
  } else {
    b.setVal267(false);
  }
  auto v268 = e.IsAggregate();
  if (v268) {
    b.setVal268(static_cast<bool>(v268.value()));
    b.setVal269(true);
  } else {
    b.setVal269(false);
  }
  auto v270 = e.IsAnyDestructorNoReturn();
  if (v270) {
    b.setVal270(static_cast<bool>(v270.value()));
    b.setVal271(true);
  } else {
    b.setVal271(false);
  }
  auto v272 = e.IsCLike();
  if (v272) {
    b.setVal272(static_cast<bool>(v272.value()));
    b.setVal273(true);
  } else {
    b.setVal273(false);
  }
  auto v274 = e.IsCXX11StandardLayout();
  if (v274) {
    b.setVal274(static_cast<bool>(v274.value()));
    b.setVal275(true);
  } else {
    b.setVal275(false);
  }
  b.setVal276(e.IsDependentLambda());
  auto v277 = e.IsDynamicClass();
  if (v277) {
    b.setVal277(static_cast<bool>(v277.value()));
    b.setVal278(true);
  } else {
    b.setVal278(false);
  }
  auto v279 = e.IsEffectivelyFinal();
  if (v279) {
    b.setVal279(static_cast<bool>(v279.value()));
    b.setVal280(true);
  } else {
    b.setVal280(false);
  }
  auto v281 = e.IsEmpty();
  if (v281) {
    b.setVal281(static_cast<bool>(v281.value()));
    b.setVal282(true);
  } else {
    b.setVal282(false);
  }
  b.setVal283(e.IsGenericLambda());
  auto v284 = e.IsInterfaceLike();
  if (v284) {
    b.setVal284(static_cast<bool>(v284.value()));
    b.setVal285(true);
  } else {
    b.setVal285(false);
  }
  auto v286 = e.IsLiteral();
  if (v286) {
    b.setVal286(static_cast<bool>(v286.value()));
    b.setVal287(true);
  } else {
    b.setVal287(false);
  }
  auto v125 = e.IsLocalClass();
  if (v125) {
    auto id125 = es.EntityId(v125.value());
    b.setVal125(id125);
  } else {
    b.setVal125(mx::kInvalidEntityId);
  }
  b.setVal288(e.IsNeverDependentLambda());
  auto v289 = e.IsPOD();
  if (v289) {
    b.setVal289(static_cast<bool>(v289.value()));
    b.setVal290(true);
  } else {
    b.setVal290(false);
  }
  auto v291 = e.IsPolymorphic();
  if (v291) {
    b.setVal291(static_cast<bool>(v291.value()));
    b.setVal292(true);
  } else {
    b.setVal292(false);
  }
  auto v293 = e.IsStandardLayout();
  if (v293) {
    b.setVal293(static_cast<bool>(v293.value()));
    b.setVal294(true);
  } else {
    b.setVal294(false);
  }
  auto v295 = e.IsStructural();
  if (v295) {
    b.setVal295(static_cast<bool>(v295.value()));
    b.setVal296(true);
  } else {
    b.setVal296(false);
  }
  auto v297 = e.IsTrivial();
  if (v297) {
    b.setVal297(static_cast<bool>(v297.value()));
    b.setVal298(true);
  } else {
    b.setVal298(false);
  }
  auto v299 = e.IsTriviallyCopyable();
  if (v299) {
    b.setVal299(static_cast<bool>(v299.value()));
    b.setVal300(true);
  } else {
    b.setVal300(false);
  }
  auto v301 = e.LambdaIsDefaultConstructibleAndAssignable();
  if (v301) {
    b.setVal301(static_cast<bool>(v301.value()));
    b.setVal302(true);
  } else {
    b.setVal302(false);
  }
  auto v303 = e.MayBeAbstract();
  if (v303) {
    b.setVal303(static_cast<bool>(v303.value()));
    b.setVal304(true);
  } else {
    b.setVal304(false);
  }
  auto v305 = e.MayBeDynamicClass();
  if (v305) {
    b.setVal305(static_cast<bool>(v305.value()));
    b.setVal306(true);
  } else {
    b.setVal306(false);
  }
  auto v307 = e.MayBeNonDynamicClass();
  if (v307) {
    b.setVal307(static_cast<bool>(v307.value()));
    b.setVal308(true);
  } else {
    b.setVal308(false);
  }
  do {
    auto ov309 = e.Methods();
    if (!ov309) {
      b.setVal310(false);
      break;
    }
    b.setVal310(true);
    auto v309 = std::move(*ov309);
    auto sv309 = b.initVal309(static_cast<unsigned>(v309.size()));
    auto i309 = 0u;
    for (const auto &e309 : v309) {
      sv309.set(i309, es.EntityId(e309));
      ++i309;
    }
  } while (false);
  auto v311 = e.NeedsImplicitCopyAssignment();
  if (v311) {
    b.setVal311(static_cast<bool>(v311.value()));
    b.setVal312(true);
  } else {
    b.setVal312(false);
  }
  auto v313 = e.NeedsImplicitCopyConstructor();
  if (v313) {
    b.setVal313(static_cast<bool>(v313.value()));
    b.setVal314(true);
  } else {
    b.setVal314(false);
  }
  auto v315 = e.NeedsImplicitDefaultConstructor();
  if (v315) {
    b.setVal315(static_cast<bool>(v315.value()));
    b.setVal316(true);
  } else {
    b.setVal316(false);
  }
  auto v317 = e.NeedsImplicitDestructor();
  if (v317) {
    b.setVal317(static_cast<bool>(v317.value()));
    b.setVal318(true);
  } else {
    b.setVal318(false);
  }
  auto v319 = e.NeedsImplicitMoveAssignment();
  if (v319) {
    b.setVal319(static_cast<bool>(v319.value()));
    b.setVal320(true);
  } else {
    b.setVal320(false);
  }
  auto v321 = e.NeedsImplicitMoveConstructor();
  if (v321) {
    b.setVal321(static_cast<bool>(v321.value()));
    b.setVal322(true);
  } else {
    b.setVal322(false);
  }
  auto v323 = e.NeedsOverloadResolutionForCopyAssignment();
  if (v323) {
    b.setVal323(static_cast<bool>(v323.value()));
    b.setVal324(true);
  } else {
    b.setVal324(false);
  }
  auto v325 = e.NeedsOverloadResolutionForCopyConstructor();
  if (v325) {
    b.setVal325(static_cast<bool>(v325.value()));
    b.setVal326(true);
  } else {
    b.setVal326(false);
  }
  auto v327 = e.NeedsOverloadResolutionForDestructor();
  if (v327) {
    b.setVal327(static_cast<bool>(v327.value()));
    b.setVal328(true);
  } else {
    b.setVal328(false);
  }
  auto v329 = e.NeedsOverloadResolutionForMoveAssignment();
  if (v329) {
    b.setVal329(static_cast<bool>(v329.value()));
    b.setVal330(true);
  } else {
    b.setVal330(false);
  }
  auto v331 = e.NeedsOverloadResolutionForMoveConstructor();
  if (v331) {
    b.setVal331(static_cast<bool>(v331.value()));
    b.setVal332(true);
  } else {
    b.setVal332(false);
  }
  auto v333 = e.NullFieldOffsetIsZero();
  if (v333) {
    b.setVal333(static_cast<bool>(v333.value()));
    b.setVal334(true);
  } else {
    b.setVal334(false);
  }
  do {
    auto ov335 = e.VirtualBases();
    if (!ov335) {
      b.setVal336(false);
      break;
    }
    b.setVal336(true);
    auto v335 = std::move(*ov335);
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
}

void SerializeClassTemplateSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeCXXRecordDecl(es, b, e, nullptr);
  auto t127 = e.ExternToken();
  b.setVal127(es.EntityId(t127));
  auto t128 = e.PointOfInstantiation();
  b.setVal128(es.EntityId(t128));
  b.setVal87(static_cast<unsigned char>(mx::FromPasta(e.SpecializationKind())));
  b.setVal136(es.EntityId(e.SpecializedTemplate()));
  do {
    auto v337 = e.TemplateArguments();
    auto sv337 = b.initVal337(static_cast<unsigned>(v337.size()));
    auto i337 = 0u;
    for (const auto &e337 : v337) {
      sv337.set(i337, es.EntityId(e337));
      ++i337;
    }
  } while (false);
  do {
    auto v338 = e.TemplateInstantiationArguments();
    auto sv338 = b.initVal338(static_cast<unsigned>(v338.size()));
    auto i338 = 0u;
    for (const auto &e338 : v338) {
      sv338.set(i338, es.EntityId(e338));
      ++i338;
    }
  } while (false);
  auto t138 = e.TemplateKeywordToken();
  b.setVal138(es.EntityId(t138));
  auto v139 = e.TypeAsWritten();
  if (v139) {
    auto id139 = es.EntityId(v139.value());
    b.setVal139(id139);
  } else {
    b.setVal139(mx::kInvalidEntityId);
  }
  b.setVal339(e.IsClassScopeExplicitSpecialization());
  b.setVal340(e.IsExplicitInstantiationOrSpecialization());
  b.setVal341(e.IsExplicitSpecialization());
}

void SerializeClassTemplatePartialSpecializationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplatePartialSpecializationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeClassTemplateSpecializationDecl(es, b, e, nullptr);
  b.setVal140(es.EntityId(e.InjectedSpecializationType()));
  b.setVal157(es.EntityId(e.InstantiatedFromMember()));
  b.setVal159(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal160(es.EntityId(e.TemplateParameters()));
  b.setVal342(e.HasAssociatedConstraints());
}

void SerializeEnumDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EnumDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTagDecl(es, b, e, nullptr);
  do {
    auto v58 = e.Enumerators();
    auto sv58 = b.initVal58(static_cast<unsigned>(v58.size()));
    auto i58 = 0u;
    for (const auto &e58 : v58) {
      sv58.set(i58, es.EntityId(e58));
      ++i58;
    }
  } while (false);
  auto v73 = e.InstantiatedFromMemberEnum();
  if (v73) {
    auto id73 = es.EntityId(v73.value());
    b.setVal73(id73);
  } else {
    b.setVal73(mx::kInvalidEntityId);
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
  auto v137 = e.ODRHash();
  if (v137) {
    b.setVal137(static_cast<unsigned>(v137.value()));
    b.setVal100(true);
  } else {
    b.setVal100(false);
  }
  auto v78 = e.PromotionType();
  if (v78) {
    auto id78 = es.EntityId(v78.value());
    b.setVal78(id78);
  } else {
    b.setVal78(mx::kInvalidEntityId);
  }
  auto v80 = e.TemplateInstantiationPattern();
  if (v80) {
    auto id80 = es.EntityId(v80.value());
    b.setVal80(id80);
  } else {
    b.setVal80(mx::kInvalidEntityId);
  }
  b.setVal79(static_cast<unsigned char>(mx::FromPasta(e.TemplateSpecializationKind())));
  b.setVal101(e.IsClosed());
  b.setVal102(e.IsClosedFlag());
  b.setVal103(e.IsClosedNonFlag());
  b.setVal104(e.IsComplete());
  b.setVal105(e.IsFixed());
  b.setVal106(e.IsScoped());
  b.setVal107(e.IsScopedUsingClassTag());
}

void SerializeUnresolvedUsingTypenameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::UnresolvedUsingTypenameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
  auto t53 = e.EllipsisToken();
  b.setVal53(es.EntityId(t53));
  auto t54 = e.TypenameToken();
  b.setVal54(es.EntityId(t54));
  auto t62 = e.UsingToken();
  b.setVal62(es.EntityId(t62));
  b.setVal70(e.IsPackExpansion());
}

void SerializeTypedefNameDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TypedefNameDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypeDecl(es, b, e, nullptr);
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
  auto v62 = e.DescribedAliasTemplate();
  if (v62) {
    auto id62 = es.EntityId(v62.value());
    b.setVal62(id62);
  } else {
    b.setVal62(mx::kInvalidEntityId);
  }
}

void SerializeObjCTypeParamDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCTypeParamDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTypedefNameDecl(es, b, e, nullptr);
  auto t62 = e.ColonToken();
  b.setVal62(es.EntityId(t62));
  b.setVal74(static_cast<unsigned char>(mx::FromPasta(e.Variance())));
  auto t63 = e.VarianceToken();
  b.setVal63(es.EntityId(t63));
  b.setVal72(e.HasExplicitBound());
}

void SerializeTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::TemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal52(es.EntityId(e.TemplateParameters()));
  b.setVal53(es.EntityId(e.TemplatedDeclaration()));
  b.setVal70(e.HasAssociatedConstraints());
}

void SerializeRedeclarableTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::RedeclarableTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeTemplateDecl(es, b, e, nullptr);
  b.setVal54(es.EntityId(e.InstantiatedFromMemberTemplate()));
  b.setVal71(e.IsMemberSpecialization());
}

void SerializeFunctionTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FunctionTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal72(e.IsAbbreviated());
  b.setVal88(e.IsThisDeclarationADefinition());
}

void SerializeClassTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ClassTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal72(e.IsThisDeclarationADefinition());
}

void SerializeVarTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::VarTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeRedeclarableTemplateDecl(es, b, e, nullptr);
  b.setVal72(e.IsThisDeclarationADefinition());
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
  b.setVal54(es.EntityId(e.ConstraintExpression()));
  b.setVal71(e.IsTypeConcept());
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
  b.setVal71(e.DefaultArgumentWasInherited());
  auto t54 = e.DefaultArgumentToken();
  b.setVal54(es.EntityId(t54));
  b.setVal72(e.HasDefaultArgument());
  b.setVal88(e.IsExpandedParameterPack());
  b.setVal89(e.IsPackExpansion());
}

void SerializeObjCPropertyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCPropertyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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
  b.setVal75(es.EntityId(e.Type()));
  b.setVal70(e.IsAtomic());
  b.setVal71(e.IsClassProperty());
  b.setVal72(e.IsDirectProperty());
  b.setVal88(e.IsInstanceProperty());
  b.setVal89(e.IsOptional());
  b.setVal90(e.IsReadOnly());
  b.setVal91(e.IsRetaining());
}

void SerializeObjCMethodDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCMethodDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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
  auto t75 = e.SelectorStartToken();
  b.setVal75(es.EntityId(t75));
  b.setVal76(es.EntityId(e.SelfDeclaration()));
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
  b.setVal100(e.IsThisDeclarationADefinition());
  b.setVal101(e.IsThisDeclarationADesignatedInitializer());
  b.setVal102(e.IsVariadic());
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

void SerializeObjCContainerDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCContainerDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
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
    auto v178 = e.Properties();
    auto sv178 = b.initVal178(static_cast<unsigned>(v178.size()));
    auto i178 = 0u;
    for (const auto &e178 : v178) {
      sv178.set(i178, es.EntityId(e178));
      ++i178;
    }
  } while (false);
  pasta::DeclContext dc179(e);
  auto v179 = dc179.AlreadyLoadedDeclarations();
  auto sv179 = b.initVal179(static_cast<unsigned>(v179.size()));
  auto i179 = 0u;
  for (const pasta::Decl &e179 : v179) {
    sv179.set(i179, es.EntityId(e179));
    ++i179;
  }
}

void SerializeObjCCategoryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal70(e.IsClassExtension());
  auto t62 = e.CategoryNameToken();
  b.setVal62(es.EntityId(t62));
  b.setVal63(es.EntityId(e.ClassInterface()));
  b.setVal64(es.EntityId(e.Implementation()));
  auto t73 = e.InstanceVariableLBraceToken();
  b.setVal73(es.EntityId(t73));
  auto t75 = e.InstanceVariableRBraceToken();
  b.setVal75(es.EntityId(t75));
  b.setVal76(es.EntityId(e.NextClassCategory()));
  do {
    auto v309 = e.InstanceVariables();
    auto sv309 = b.initVal309(static_cast<unsigned>(v309.size()));
    auto i309 = 0u;
    for (const auto &e309 : v309) {
      sv309.set(i309, es.EntityId(e309));
      ++i309;
    }
  } while (false);
  do {
    auto v335 = e.ProtocolTokens();
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
  do {
    auto v337 = e.Protocols();
    auto sv337 = b.initVal337(static_cast<unsigned>(v337.size()));
    auto i337 = 0u;
    for (const auto &e337 : v337) {
      sv337.set(i337, es.EntityId(e337));
      ++i337;
    }
  } while (false);
}

void SerializeObjCProtocolDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCProtocolDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  auto v69 = e.ObjCRuntimeNameAsString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal70(e.HasDefinition());
  b.setVal71(e.IsNonRuntimeProtocol());
  b.setVal72(e.IsThisDeclarationADefinition());
  do {
    auto v309 = e.ProtocolTokens();
    auto sv309 = b.initVal309(static_cast<unsigned>(v309.size()));
    auto i309 = 0u;
    for (const auto &e309 : v309) {
      sv309.set(i309, es.EntityId(e309));
      ++i309;
    }
  } while (false);
  do {
    auto v335 = e.Protocols();
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
}

void SerializeObjCInterfaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCInterfaceDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  do {
    auto v309 = e.AllReferencedProtocols();
    auto sv309 = b.initVal309(static_cast<unsigned>(v309.size()));
    auto i309 = 0u;
    for (const auto &e309 : v309) {
      sv309.set(i309, es.EntityId(e309));
      ++i309;
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
  auto v75 = e.SuperClassTypeInfo();
  if (v75) {
    auto id75 = es.EntityId(v75.value());
    b.setVal75(id75);
  } else {
    b.setVal75(mx::kInvalidEntityId);
  }
  b.setVal76(es.EntityId(e.TypeForDeclaration()));
  b.setVal71(e.HasDefinition());
  b.setVal72(e.HasDesignatedInitializers());
  b.setVal88(e.IsArcWeakrefUnavailable());
  b.setVal89(e.IsImplicitInterfaceDeclaration());
  b.setVal77(es.EntityId(e.IsObjCRequiresPropertyDefinitions()));
  b.setVal90(e.IsThisDeclarationADefinition());
  do {
    auto v335 = e.InstanceVariables();
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
  do {
    auto v337 = e.KnownCategories();
    auto sv337 = b.initVal337(static_cast<unsigned>(v337.size()));
    auto i337 = 0u;
    for (const auto &e337 : v337) {
      sv337.set(i337, es.EntityId(e337));
      ++i337;
    }
  } while (false);
  do {
    auto v338 = e.KnownExtensions();
    auto sv338 = b.initVal338(static_cast<unsigned>(v338.size()));
    auto i338 = 0u;
    for (const auto &e338 : v338) {
      sv338.set(i338, es.EntityId(e338));
      ++i338;
    }
  } while (false);
  do {
    auto v343 = e.ProtocolTokens();
    auto sv343 = b.initVal343(static_cast<unsigned>(v343.size()));
    auto i343 = 0u;
    for (const auto &e343 : v343) {
      sv343.set(i343, es.EntityId(e343));
      ++i343;
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
  do {
    auto v345 = e.VisibleCategories();
    auto sv345 = b.initVal345(static_cast<unsigned>(v345.size()));
    auto i345 = 0u;
    for (const auto &e345 : v345) {
      sv345.set(i345, es.EntityId(e345));
      ++i345;
    }
  } while (false);
  do {
    auto v346 = e.VisibleExtensions();
    auto sv346 = b.initVal346(static_cast<unsigned>(v346.size()));
    auto i346 = 0u;
    for (const auto &e346 : v346) {
      sv346.set(i346, es.EntityId(e346));
      ++i346;
    }
  } while (false);
}

void SerializeObjCImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCContainerDecl(es, b, e, nullptr);
  b.setVal62(es.EntityId(e.ClassInterface()));
  do {
    auto v309 = e.PropertyImplementations();
    auto sv309 = b.initVal309(static_cast<unsigned>(v309.size()));
    auto i309 = 0u;
    for (const auto &e309 : v309) {
      sv309.set(i309, es.EntityId(e309));
      ++i309;
    }
  } while (false);
}

void SerializeObjCCategoryImplDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCategoryImplDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  b.setVal63(es.EntityId(e.CategoryDeclaration()));
  auto t64 = e.CategoryNameToken();
  b.setVal64(es.EntityId(t64));
}

void SerializeObjCImplementationDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCImplementationDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeObjCImplDecl(es, b, e, nullptr);
  auto t63 = e.InstanceVariableLBraceToken();
  b.setVal63(es.EntityId(t63));
  auto t64 = e.InstanceVariableRBraceToken();
  b.setVal64(es.EntityId(t64));
  auto v69 = e.ObjCRuntimeNameAsString();
  std::string s69(v69.data(), v69.size());
  b.setVal69(s69);
  b.setVal73(es.EntityId(e.SuperClass()));
  auto t75 = e.SuperClassToken();
  b.setVal75(es.EntityId(t75));
  b.setVal70(e.HasDestructors());
  b.setVal71(e.HasNonZeroConstructors());
  do {
    auto v335 = e.InstanceVariables();
    auto sv335 = b.initVal335(static_cast<unsigned>(v335.size()));
    auto i335 = 0u;
    for (const auto &e335 : v335) {
      sv335.set(i335, es.EntityId(e335));
      ++i335;
    }
  } while (false);
}

void SerializeObjCCompatibleAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ObjCCompatibleAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  b.setVal52(es.EntityId(e.ClassInterface()));
}

void SerializeNamespaceDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceDecl &e, const TokenTree *) {
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

void SerializeNamespaceAliasDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::NamespaceAliasDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeNamedDecl(es, b, e, nullptr);
  auto t52 = e.AliasToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.AliasedNamespace()));
  auto t54 = e.NamespaceToken();
  b.setVal54(es.EntityId(t54));
  auto t62 = e.TargetNameToken();
  b.setVal62(es.EntityId(t62));
}

void SerializeLinkageSpecDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LinkageSpecDecl &e, const TokenTree *) {
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

void SerializeLifetimeExtendedTemporaryDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::LifetimeExtendedTemporaryDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeImportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ImportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeFriendTemplateDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendTemplateDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  b.setVal45(es.EntityId(e.FriendDeclaration()));
  auto t52 = e.FriendToken();
  b.setVal52(es.EntityId(t52));
  b.setVal53(es.EntityId(e.FriendType()));
  do {
    auto v47 = e.TemplateParameterLists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeFriendDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FriendDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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
    auto v47 = e.FriendTypeTemplateParameterLists();
    auto sv47 = b.initVal47(static_cast<unsigned>(v47.size()));
    auto i47 = 0u;
    for (const auto &e47 : v47) {
      sv47.set(i47, es.EntityId(e47));
      ++i47;
    }
  } while (false);
}

void SerializeFileScopeAsmDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::FileScopeAsmDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
  auto t45 = e.AssemblyToken();
  b.setVal45(es.EntityId(t45));
  b.setVal52(es.EntityId(e.AssemblyString()));
  auto t53 = e.RParenToken();
  b.setVal53(es.EntityId(t53));
}

void SerializeExternCContextDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExternCContextDecl &e, const TokenTree *) {
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

void SerializeExportDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::ExportDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
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

void SerializeEmptyDecl(const EntityMapper &es, mx::ast::Decl::Builder b, const pasta::EmptyDecl &e, const TokenTree *) {
  (void) es;
  (void) b;
  (void) e;
  SerializeDecl(es, b, e, nullptr);
}

#pragma GCC diagnostic pop
}  // namespace indexer
