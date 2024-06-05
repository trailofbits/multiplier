// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Decl.h"
#include <iostream>

#include <multiplier/AST/ClassTemplateDecl.h>
#include <multiplier/AST/ClassTemplatePartialSpecializationDecl.h>
#include <multiplier/AST/CXXMethodDecl.h>
#include <multiplier/AST/CXXRecordDecl.h>
#include <multiplier/AST/FunctionTemplateDecl.h>
#include <multiplier/AST/ImplicitConceptSpecializationDecl.h>
#include <multiplier/AST/NamespaceDecl.h>
#include <multiplier/AST/ParmVarDecl.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/AST/VarTemplateDecl.h>
#include <multiplier/AST/VarTemplatePartialSpecializationDecl.h>
#include <multiplier/Frontend/MacroSubstitution.h>
#include <multiplier/Index.h>

#include "Fragment.h"
#include "Reference.h"
#include "Types.h"
#include "Util.h"
#include "DeclStmtUtil.h"

namespace mx {
namespace {

static thread_local RawEntityIdList tIgnoredRedecls;

}  // namespace

DeclImpl::DeclImpl(FragmentImplPtr frag_,
                   ast::Decl::Reader reader_,
                   RawEntityId id_)
    : FragmentEntityImpl<ast::Decl>(std::move(frag_), kj::mv(reader_)),
      fragment_id(FragmentIdFromEntityId(id_).value()),
      offset(FragmentOffsetFromEntityId(id_).value()),
      definition_id(kInvalidEntityId),
      canonical_id(kInvalidEntityId) {}

SpecificEntityId<DeclId> Decl::id(void) const {
  DeclId eid;
  eid.fragment_id = impl->fragment_id.Unpack().fragment_id;
  eid.is_definition = is_definition();
  eid.kind = kind();
  eid.offset = impl->offset;
  return eid;
}

// Get the definition of a declaration.
std::optional<Decl> Decl::definition(void) const {
  const EntityProviderPtr &ep = impl->ep;

  // If we've stored the canonical ID already, then we've also computed the
  // definition ID, if any.
  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    RawEntityId definition_id =
        impl->definition_id.load(std::memory_order_acquire);
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      return Decl(std::move(def));
    } else {
      return std::nullopt;
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  impl->canonical_id.store(min_id, std::memory_order_release);
  return std::nullopt;
}

// Get the canonical declaration. This is the declaration with the minimum-
// valued ID, where all definition IDs are less than all declaration IDs, and
// so preference is given to definition IDs.
Decl Decl::canonical_declaration(void) const {
  const EntityProviderPtr &ep = impl->ep;

  RawEntityId min_id = impl->canonical_id.load(std::memory_order_acquire);
  if (min_id != kInvalidEntityId) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, min_id)) {
      return Decl(std::move(redecl));
    }
  }

  min_id = std::numeric_limits<RawEntityId>::max();
  RawEntityId definition_id = min_id;
  RawEntityId this_id = id().Pack();
  bool found_def = false;

#ifndef NDEBUG
  bool seen_this_id = false;
#endif

  for (RawEntityId raw_id : ep->Redeclarations(ep, this_id)) {
    VariantId vid = EntityId(raw_id).Unpack();
    if (!std::holds_alternative<DeclId>(vid)) {
      assert(false);
      continue;
    }

    DeclId did = std::get<DeclId>(vid);
    if (did.is_definition) {
      definition_id = std::min(definition_id, raw_id);
      found_def = true;
    }
    min_id = std::min(min_id, raw_id);

#ifndef NDEBUG
    if (raw_id == this_id) {
      seen_this_id = true;
    }
#endif
  }

  assert(seen_this_id);

  if (found_def) {
    if (DeclImplPtr def = ep->DeclFor(ep, definition_id)) {
      impl->canonical_id.store(definition_id, std::memory_order_release);
      impl->definition_id.store(definition_id, std::memory_order_release);
      return Decl(std::move(def));
    }
  }

  min_id = std::min(min_id, this_id);
  if (DeclImplPtr decl = ep->DeclFor(ep, min_id)) {
    impl->canonical_id.store(min_id, std::memory_order_release);
    return Decl(std::move(decl));

  } else {
    assert(false);
    impl->canonical_id.store(this_id, std::memory_order_release);
    return *this;
  }
}

gap::generator<Decl> Decl::redeclarations(void) const & {
  auto any = false;
  EntityProviderPtr ep = impl->ep;
  for (RawEntityId raw_id : ep->Redeclarations(ep, id().Pack())) {
    if (DeclImplPtr redecl = ep->DeclFor(ep, raw_id)) {
      any = true;
      co_yield Decl(std::move(redecl));
    }
  }
  if (!any) {
    assert(false);
    co_yield Decl(impl);
  }
}

// Grab all callers of this function. These are `CallExpr` or
// `CxxConstructExpr`s.
//
// TODO(pag): Handle `CXXNewExpr` that doesn't contain a `CxxConstructExpr`.
gap::generator<Stmt> FunctionDecl::callers(void) const & {
  static constexpr auto kCallerKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::CALLS);

  auto ep = impl->ep;
  auto is_constructor = kind() == DeclKind::CXX_CONSTRUCTOR;

  for (auto [from_id, context_id] : ep->SpecificReferences(
                                        ep, id().Pack(), kCallerKindId,
                                        EntityProvider::kReferenceTo)) {

    // The `context_id` should point to a `CallExpr`.
    if (auto context_stmt_id = EntityId(context_id).Extract<StmtId>()) {
      if (context_stmt_id->kind == StmtKind::CALL_EXPR ||
          context_stmt_id->kind == StmtKind::CXX_NEW_EXPR ||
          context_stmt_id->kind == StmtKind::CXX_DELETE_EXPR) {
        if (auto eptr = ep->StmtFor(ep, context_id)) {
          co_yield Stmt(std::move(eptr));
          continue;
        }
      }

      if (context_stmt_id->kind == StmtKind::CXX_CONSTRUCT_EXPR &&
          is_constructor) {
        if (auto eptr = ep->StmtFor(ep, context_id)) {
          co_yield Stmt(std::move(eptr));
          continue;
        } 
      }
    }

    // If it doesn't, then `from_id` is probably pointing to a `DeclRefExpr`,
    // so go and search for a `CallExpr` containing the `DeclRefExpr`.
    auto stmt_id = EntityId(from_id).Extract<StmtId>();
    if (!stmt_id) {
      continue;
    }

    auto eptr = ep->StmtFor(ep, from_id);
    if (!eptr) {
      assert(false);
      continue;
    }

    Stmt func_ref(std::move(eptr));
    for (auto call : Stmt::containing(func_ref)) {
      auto ck = call.kind();

      if (ck == StmtKind::CXX_CONSTRUCT_EXPR) {
        if (is_constructor) {
          co_yield std::move(call);
        }
        break;
      }

      if (ck == StmtKind::CALL_EXPR) {
        co_yield std::move(call);
        break;
      }

      if (IsNonValueStatement(ck)) {
        break;
      }
    }
  }
}

gap::generator<CXXRecordDecl> CXXRecordDecl::base_classes(void) const & {
  return BuiltinDeclReferences<CXXRecordDecl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::EXTENDS,
      EntityProvider::kReferenceFrom);
}

gap::generator<CXXRecordDecl> CXXRecordDecl::derived_classes(void) const & {
  return BuiltinDeclReferences<CXXRecordDecl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::EXTENDS,
      EntityProvider::kReferenceTo);
}

gap::generator<CXXMethodDecl> CXXRecordDecl::methods(void) const & {
  return BuiltinDeclReferences<CXXMethodDecl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::CONTAINS,
      EntityProvider::kReferenceFrom, false  /* redecls */);
}

gap::generator<CXXMethodDecl>
CXXMethodDecl::overridden_by_methods(void) const & {
  return BuiltinDeclReferences<CXXMethodDecl>(
      impl->ep, id().Pack(), BuiltinReferenceKind::OVERRIDES,
      EntityProvider::kReferenceTo);
}

gap::generator<CXXMethodDecl>
CXXMethodDecl::transitive_overridden_by_methods(void) const & {
  static constexpr auto kOverridesKindId =
      static_cast<RawEntityId>(BuiltinReferenceKind::OVERRIDES);

  std::vector<RawEntityId> found_ids;

  found_ids.push_back(id().Pack());

  auto ep = impl->ep;
  for (auto i = 0u; i < found_ids.size(); ++i) {
    for (auto [from_id, context_id] : ep->SpecificReferences(
                                          ep, found_ids[i], kOverridesKindId,
                                          EntityProvider::kReferenceTo)) {

      auto decl_id = EntityId(from_id).Extract<DeclId>();
      if (!decl_id) {
        continue;
      }

      switch (decl_id->kind) {
        case mx::DeclKind::CXX_CONVERSION:
        case mx::DeclKind::CXX_CONSTRUCTOR:
        case mx::DeclKind::CXX_DEDUCTION_GUIDE:
        case mx::DeclKind::CXX_DESTRUCTOR:
        case mx::DeclKind::CXX_METHOD:
          break;
        default:
          continue;
      }

      if (std::find(found_ids.begin(), found_ids.end(), from_id) !=
          found_ids.end()) {
        continue;
      }

      auto eptr = ep->DeclFor(ep, from_id);
      if (!eptr) {
        assert(false);
        continue;
      }

      Decl method_ref(std::move(eptr));
      co_yield std::move(reinterpret_cast<CXXMethodDecl &>(method_ref));
      found_ids.push_back(from_id);
    }
  }
}

gap::generator<Decl> Decl::specializations(void) const & {
  // If `this` is a pattern, then go and get the entity ID for the template.
  auto self_id = id().Pack();
  switch (kind()) {
    case DeclKind::CXX_RECORD: {
      const auto &self = reinterpret_cast<const CXXRecordDecl &>(*this);
      if (auto tpl = self.described_class_template()) {
        self_id = tpl->id().Pack();
      }
      break;
    }

    case DeclKind::VAR: {
      const auto &self = reinterpret_cast<const VarDecl &>(*this);
      if (auto tpl = self.described_variable_template()) {
        self_id = tpl->id().Pack();
      }
      break;
    }

    case DeclKind::CXX_CONSTRUCTOR:
    case DeclKind::CXX_CONVERSION:
    case DeclKind::CXX_DESTRUCTOR:
    case DeclKind::CXX_DEDUCTION_GUIDE:
    case DeclKind::CXX_METHOD:
    case DeclKind::FUNCTION: {
      const auto &self = reinterpret_cast<const FunctionDecl &>(*this);
      if (auto tpl = self.described_function_template()) {
        self_id = tpl->id().Pack();
      }
      break;
    }

    default:
      break;
  }

  return BuiltinDeclReferences<Decl>(
      impl->ep, self_id, BuiltinReferenceKind::SPECIALIZES,
      EntityProvider::kReferenceTo);
}

namespace {

static void AddSimpleToken(CustomTokenReader &tr, std::string_view data,
                           TokenKind kind, TokenCategory category) {

  tr.data.insert(tr.data.end(), data.begin(), data.end());
  tr.data_offset.push_back(static_cast<EntityOffset>(tr.data.size()));
  tr.derived_token_ids.push_back(kInvalidEntityId);
  tr.parsed_token_ids.push_back(kInvalidEntityId);
  tr.containing_macro_ids.push_back(kInvalidEntityId);
  tr.token_ids.push_back(kInvalidEntityId);
  tr.token_kinds.push_back(kind);
  tr.token_categories.push_back(category);
  tr.file_token_ids.push_back(kInvalidEntityId);
  tr.related_entities.emplace_back(NotAnEntity{});
}

static void RenderQualifiedNameInto(
    CustomTokenReader &tr, const NamedDecl &nd,
    const QualifiedNameRenderOptions &options);

static void RenderTemplateParametersInto(
    CustomTokenReader &tr, const TemplateParameterList &params,
    const QualifiedNameRenderOptions &options) {
  // TODO(pag): Implement this.
  (void) tr;
  (void) params;
  (void) options;
}

static void RenderTemplateArgumentInto(
    CustomTokenReader &tr, const TemplateArgument &arg,
    const QualifiedNameRenderOptions &options) {

  bool needs_comma = tr.token_kinds.back() != TokenKind::L_ANGLE;
  auto maybe_add_comma = [&] (void) {
    if (needs_comma) {
      AddSimpleToken(tr, ",", TokenKind::COMMA, TokenCategory::PUNCTUATION);
      AddSimpleToken(tr, " ", TokenKind::WHITESPACE, TokenCategory::WHITESPACE);
      needs_comma = false;
    }
  };

  switch (arg.kind()) {
    case TemplateArgumentKind::EMPTY:
      return;
    case TemplateArgumentKind::TYPE:
      if (auto ty = arg.type()) {
        for (auto tok : ty->tokens()) {
          maybe_add_comma();
          tr.Append(std::move(tok));
        }
      }
      break;
    case TemplateArgumentKind::DECLARATION:
      if (auto vd = arg.declaration()) {
        if (auto nvd = NamedDecl::from(vd.value())) {
          maybe_add_comma();
          RenderQualifiedNameInto(tr, nvd.value(), options);
        } else {
          auto max = 16;
          for (auto tok : vd->tokens()) {
            maybe_add_comma();
            tr.Append(std::move(tok));
            if (!--max) {
              AddSimpleToken(tr, "...", TokenKind::ELLIPSIS,
                             TokenCategory::PUNCTUATION);
              break;
            }
          }
        }
      }
      break;
    case TemplateArgumentKind::NULL_POINTER:
      maybe_add_comma();
      AddSimpleToken(tr, "nullptr", TokenKind::KEYWORD_NULLPTR,
                     TokenCategory::KEYWORD);
      break;

    case TemplateArgumentKind::INTEGRAL:
      maybe_add_comma();
      AddSimpleToken(tr, "?", TokenKind::UNKNOWN, TokenCategory::ERROR);
      break;

    case TemplateArgumentKind::EXPRESSION:
      if (auto expr = arg.expression()) {
        for (auto tok : expr->tokens()) {
          maybe_add_comma();
          tr.Append(std::move(tok));
        }
      }
      break;

    case TemplateArgumentKind::PACK:
      for (const auto &sub_arg : arg.pack_arguments()) {
        RenderTemplateArgumentInto(tr, sub_arg, options);
      }
      break;

    // TODO(pag): Handle these.
    case TemplateArgumentKind::TEMPLATE:
    case TemplateArgumentKind::TEMPLATE_EXPANSION:
    case TemplateArgumentKind::STRUCTURAL_VALUE:
      maybe_add_comma();
      AddSimpleToken(tr, "?", TokenKind::UNKNOWN, TokenCategory::ERROR);
      break;
  }
}

static void RenderTemplateArgumentsInto(
    CustomTokenReader &tr, gap::generator<TemplateArgument> args,
    const QualifiedNameRenderOptions &options) {

  AddSimpleToken(tr, "<", TokenKind::L_ANGLE, TokenCategory::PUNCTUATION);

  for (const auto &arg : args) {
    RenderTemplateArgumentInto(tr, arg, options);
  }

  AddSimpleToken(tr, ">", TokenKind::R_ANGLE, TokenCategory::PUNCTUATION);
}

static void RenderParametersInto(
    CustomTokenReader &tr, const NamedDecl &nd,
    const QualifiedNameRenderOptions &options) {
  switch (nd.kind()) {
    case DeclKind::FUNCTION:
    case DeclKind::CXX_CONSTRUCTOR:
    case DeclKind::CXX_CONVERSION:
    case DeclKind::CXX_DEDUCTION_GUIDE:
    case DeclKind::CXX_DESTRUCTOR:
    case DeclKind::CXX_METHOD:
      break;
    default:
      return;
  }

  bool needs_comma = false;
  auto maybe_add_comma = [&] (void) {
    if (needs_comma) {
      AddSimpleToken(tr, ",", TokenKind::COMMA, TokenCategory::PUNCTUATION);
      AddSimpleToken(tr, " ", TokenKind::WHITESPACE, TokenCategory::WHITESPACE);
      needs_comma = true;
    }
  };

  const auto &fd = reinterpret_cast<const FunctionDecl &>(nd);
  AddSimpleToken(tr, "(", TokenKind::L_PARENTHESIS, TokenCategory::PUNCTUATION);

  auto params = fd.parameters();
  for (const auto &pd : params) {
    maybe_add_comma();
    for (auto tok : pd.type().tokens()) {
      tr.Append(std::move(tok));
    }
  }

  if (fd.is_variadic()) {
    maybe_add_comma();
    AddSimpleToken(tr, "...", TokenKind::ELLIPSIS, TokenCategory::PUNCTUATION);
  }

  AddSimpleToken(tr, ")", TokenKind::R_PARENTHESIS, TokenCategory::PUNCTUATION);
}

void RenderQualifiedNameInto(
    CustomTokenReader &tr, const NamedDecl &nd,
    const QualifiedNameRenderOptions &options) {

  if (options.fully_qualified) {
    if (auto pd = NamedDecl::from(nd.parent_declaration())) {
      RenderQualifiedNameInto(tr, pd.value(), options);

      if (options.include_function_parameter_types) {
        RenderParametersInto(tr, nd, options);
      }

      // The parent is a template declaration; we don't need to print `nd`
      // because `pd` has the same name.
      if (auto td = TemplateDecl::from(pd.value())) {
        if (auto pattern = td->templated_declaration()) {
          if (pattern->id() == nd.id()) {
            return;
          }
        }
      }
    }
  }

  auto kind = nd.kind();
  auto category = ConvertDeclCategoryToTokenCategory(nd.category());

  // Add in the name.
  auto name = nd.name();
  bool should_print = true;

  // Scan for alternative names in redeclarations.
  if (options.find_name_in_redeclaration && name.empty()) {
    switch (category) {
      case TokenCategory::PARAMETER_VARIABLE:
        for (auto redecl : nd.redeclarations()) {
          name = redecl.name();
          if (name.empty()) {
            break;
          }
        }
        break;
      default:
        break;
    }
  }

  if (kind == DeclKind::CXX_RECORD) {
    const auto &record = reinterpret_cast<const CXXRecordDecl &>(nd);
    if (record.is_lambda()) {
      name = "(lambda)";
      should_print = true;
    }
  }

  if (name.empty()) {
    switch (category) {
      case TokenCategory::ENUM:
        name = "(anonymous enum)";
        should_print = options.render_anonymous_enums;
        break;

      case TokenCategory::CLASS:
        name = "(anonymous class)";
        should_print = options.render_anonymous_classes;
        break;

      case TokenCategory::STRUCT:
        name = "(anonymous struct)";
        should_print = options.render_anonymous_structs;
        break;

      case TokenCategory::UNION:
        name = "(anonymous union)";
        should_print = options.render_anonymous_unions;
        break;

      case TokenCategory::INSTANCE_MEMBER:
        name = "(anonymous field)";
        should_print = options.render_anonymous_fields;
        break;

      case TokenCategory::PARAMETER_VARIABLE:
        name = "(anonymous parameter)";
        should_print = options.render_anonymous_parameters;
        break;

      case TokenCategory::NAMESPACE:
        name = "(anonymous namespace)";
        should_print = options.render_anonymous_namespaces;
        break;

      default:
        should_print = false;
        break;
    }
  }

  if (should_print && kind == DeclKind::NAMESPACE) {
    const auto &ns = reinterpret_cast<const NamespaceDecl &>(nd);
    if (ns.is_inline()) {
      should_print = options.render_inline_namespaces;
    }
  }

  if (!should_print || name.empty()) {
    return;
  }

  // Add in a leading `::` to separate from parent declaration names.
  if (!tr.token_kinds.empty() &&
      tr.token_kinds.back() != TokenKind::COLON_COLON) {
    AddSimpleToken(tr, "::", TokenKind::COLON_COLON,
                   TokenCategory::PUNCTUATION);
  }

  // Add in the declaration.
  tr.data.insert(tr.data.end(), name.begin(), name.end());
  tr.data_offset.push_back(static_cast<EntityOffset>(tr.data.size()));
  tr.derived_token_ids.push_back(kInvalidEntityId);
  tr.parsed_token_ids.push_back(kInvalidEntityId);
  tr.containing_macro_ids.push_back(kInvalidEntityId);
  tr.token_ids.push_back(kInvalidEntityId);
  tr.token_kinds.push_back(TokenKind::IDENTIFIER);
  tr.token_categories.push_back(category);
  tr.file_token_ids.push_back(kInvalidEntityId);
  tr.related_entities.emplace_back(nd);

  if (options.render_template_parameters) {
    switch (kind) {
      case DeclKind::CLASS_TEMPLATE:
      case DeclKind::VAR_TEMPLATE:
      case DeclKind::FRIEND_TEMPLATE:
      case DeclKind::CONCEPT:
      case DeclKind::FUNCTION_TEMPLATE:
        RenderTemplateParametersInto(
            tr,
            reinterpret_cast<const TemplateDecl &>(nd).template_parameters(),
            options);
        break;
      case DeclKind::VAR_TEMPLATE_PARTIAL_SPECIALIZATION:
      case DeclKind::CLASS_TEMPLATE_PARTIAL_SPECIALIZATION:
      default:
        break;
    }
  }

  if (options.render_template_arguments) {
    switch (kind) {
      case DeclKind::FUNCTION:
      case DeclKind::CXX_CONSTRUCTOR:
      case DeclKind::CXX_CONVERSION:
      case DeclKind::CXX_DEDUCTION_GUIDE:
      case DeclKind::CXX_DESTRUCTOR:
      case DeclKind::CXX_METHOD: {
        const auto &func = reinterpret_cast<const FunctionDecl &>(nd);
        switch (func.templated_kind()) {
          case FunctionDeclTemplatedKind::FUNCTION_TEMPLATE_SPECIALIZATION:
          case FunctionDeclTemplatedKind::DEPENDENT_FUNCTION_TEMPLATE_SPECIALIZATION:
            RenderTemplateArgumentsInto(tr, func.template_arguments(), options);
            break;
          default:
            break;
        }
        break;
      }
      case DeclKind::CLASS_TEMPLATE_SPECIALIZATION: {
        const auto &cls = reinterpret_cast<const ClassTemplateSpecializationDecl &>(nd);
        RenderTemplateArgumentsInto(tr, cls.template_arguments(), options);
        break;
      }
      case DeclKind::VAR_TEMPLATE_SPECIALIZATION: {
        const auto &var = reinterpret_cast<const VarTemplateSpecializationDecl &>(nd);
        RenderTemplateArgumentsInto(tr, var.template_arguments(), options);
        break;
      }
      case DeclKind::IMPLICIT_CONCEPT_SPECIALIZATION: {
        const auto &cpt = reinterpret_cast<const ImplicitConceptSpecializationDecl &>(nd);
        RenderTemplateArgumentsInto(tr, cpt.template_arguments(), options);
        break;
      }
      default:
        break;
    }

    // TODO(pag): Implement this.
  }

  if (options.include_function_parameter_types) {
    RenderParametersInto(tr, nd, options);
  }
}

}  // namespace

TokenRange NamedDecl::qualified_name(
    const QualifiedNameRenderOptions &options) const {
  auto tr = std::make_shared<CustomTokenReader>(FragmentImpl::Ptr{});
  RenderQualifiedNameInto(*tr, *this, options);
  auto num_tokens = static_cast<unsigned>(tr->token_ids.size());
  return TokenRange(std::move(tr), 0u, num_tokens);
}

gap::generator<Decl> Decl::overlapping(const MacroSubstitution sub) {
  return EntityOverlapping<Decl>(sub);
}

gap::generator<Decl> Decl::overlapping(const std::optional<MacroSubstitution> &macro) {
  if (macro.has_value()) {
    for (auto decl : overlapping(macro.value())) {
      co_yield decl;
    }
  }
}

std::optional<Decl> Decl::covering(const MacroSubstitution sub) {
  auto first = sub.first_fully_substituted_token().parsed_token();
  auto last = sub.last_fully_substituted_token().parsed_token();
  for (auto decl : EntityOverlapping<Decl>(sub)) {
    if (!decl.tokens().index_of(first) || !decl.tokens().index_of(last)) {
      continue;
    }
    return decl;
  }
  return std::nullopt;
}

std::optional<Decl> Decl::covering(const std::optional<MacroSubstitution> &macro) {
  if (macro.has_value()) {
    return covering(macro.value());
  }
  return std::nullopt;
}

}  // namespace mx
