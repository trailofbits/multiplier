// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Decl.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>
#include <multiplier/Re2.h>

#include <cassert>
#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::Decl;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

inline static O *O_cast(void *obj) noexcept {
  return reinterpret_cast<O *>(obj);
}

inline static const O *O_cast(const void *obj) noexcept {
  return reinterpret_cast<const O *>(obj);
}

inline static T *T_cast(void *obj) noexcept {
  return O_cast(obj)->data;
}

inline static const T *T_cast(const void *obj) noexcept {
  return O_cast(obj)->data;
}

}  // namespace
namespace mx {

namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[723]) || tp >= &(gTypes[823])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      assert(false);
      tp = gType;
      break;

    case mx::CapturedDecl::static_kind():
      tp = &(gTypes[724]);
      break;

    case mx::BlockDecl::static_kind():
      tp = &(gTypes[725]);
      break;

    case mx::AccessSpecDecl::static_kind():
      tp = &(gTypes[726]);
      break;

    case mx::OMPThreadPrivateDecl::static_kind():
      tp = &(gTypes[728]);
      break;

    case mx::OMPRequiresDecl::static_kind():
      tp = &(gTypes[729]);
      break;

    case mx::OMPAllocateDecl::static_kind():
      tp = &(gTypes[730]);
      break;

    case mx::TranslationUnitDecl::static_kind():
      tp = &(gTypes[731]);
      break;

    case mx::TopLevelStmtDecl::static_kind():
      tp = &(gTypes[732]);
      break;

    case mx::StaticAssertDecl::static_kind():
      tp = &(gTypes[733]);
      break;

    case mx::RequiresExprBodyDecl::static_kind():
      tp = &(gTypes[734]);
      break;

    case mx::PragmaDetectMismatchDecl::static_kind():
      tp = &(gTypes[735]);
      break;

    case mx::PragmaCommentDecl::static_kind():
      tp = &(gTypes[736]);
      break;

    case mx::ObjCPropertyImplDecl::static_kind():
      tp = &(gTypes[737]);
      break;

    case mx::LabelDecl::static_kind():
      tp = &(gTypes[739]);
      break;

    case mx::HLSLBufferDecl::static_kind():
      tp = &(gTypes[740]);
      break;

    case mx::UsingEnumDecl::static_kind():
      tp = &(gTypes[742]);
      break;

    case mx::UsingDecl::static_kind():
      tp = &(gTypes[743]);
      break;

    case mx::UnresolvedUsingValueDecl::static_kind():
      tp = &(gTypes[745]);
      break;

    case mx::UnnamedGlobalConstantDecl::static_kind():
      tp = &(gTypes[746]);
      break;

    case mx::TemplateParamObjectDecl::static_kind():
      tp = &(gTypes[747]);
      break;

    case mx::OMPDeclareReductionDecl::static_kind():
      tp = &(gTypes[748]);
      break;

    case mx::MSGuidDecl::static_kind():
      tp = &(gTypes[749]);
      break;

    case mx::IndirectFieldDecl::static_kind():
      tp = &(gTypes[750]);
      break;

    case mx::EnumConstantDecl::static_kind():
      tp = &(gTypes[751]);
      break;

    case mx::VarDecl::static_kind():
      tp = &(gTypes[753]);
      break;

    case mx::ParmVarDecl::static_kind():
      tp = &(gTypes[754]);
      break;

    case mx::OMPCapturedExprDecl::static_kind():
      tp = &(gTypes[755]);
      break;

    case mx::ImplicitParamDecl::static_kind():
      tp = &(gTypes[756]);
      break;

    case mx::DecompositionDecl::static_kind():
      tp = &(gTypes[757]);
      break;

    case mx::VarTemplateSpecializationDecl::static_kind():
      tp = &(gTypes[758]);
      break;

    case mx::VarTemplatePartialSpecializationDecl::static_kind():
      tp = &(gTypes[759]);
      break;

    case mx::NonTypeTemplateParmDecl::static_kind():
      tp = &(gTypes[760]);
      break;

    case mx::MSPropertyDecl::static_kind():
      tp = &(gTypes[761]);
      break;

    case mx::FunctionDecl::static_kind():
      tp = &(gTypes[762]);
      break;

    case mx::CXXMethodDecl::static_kind():
      tp = &(gTypes[763]);
      break;

    case mx::CXXDestructorDecl::static_kind():
      tp = &(gTypes[764]);
      break;

    case mx::CXXConversionDecl::static_kind():
      tp = &(gTypes[765]);
      break;

    case mx::CXXConstructorDecl::static_kind():
      tp = &(gTypes[766]);
      break;

    case mx::CXXDeductionGuideDecl::static_kind():
      tp = &(gTypes[767]);
      break;

    case mx::FieldDecl::static_kind():
      tp = &(gTypes[768]);
      break;

    case mx::ObjCIvarDecl::static_kind():
      tp = &(gTypes[769]);
      break;

    case mx::ObjCAtDefsFieldDecl::static_kind():
      tp = &(gTypes[770]);
      break;

    case mx::BindingDecl::static_kind():
      tp = &(gTypes[771]);
      break;

    case mx::OMPDeclareMapperDecl::static_kind():
      tp = &(gTypes[773]);
      break;

    case mx::UsingShadowDecl::static_kind():
      tp = &(gTypes[774]);
      break;

    case mx::ConstructorUsingShadowDecl::static_kind():
      tp = &(gTypes[775]);
      break;

    case mx::UsingPackDecl::static_kind():
      tp = &(gTypes[776]);
      break;

    case mx::UsingDirectiveDecl::static_kind():
      tp = &(gTypes[777]);
      break;

    case mx::UnresolvedUsingIfExistsDecl::static_kind():
      tp = &(gTypes[778]);
      break;

    case mx::TemplateTypeParmDecl::static_kind():
      tp = &(gTypes[780]);
      break;

    case mx::RecordDecl::static_kind():
      tp = &(gTypes[782]);
      break;

    case mx::CXXRecordDecl::static_kind():
      tp = &(gTypes[783]);
      break;

    case mx::ClassTemplateSpecializationDecl::static_kind():
      tp = &(gTypes[784]);
      break;

    case mx::ClassTemplatePartialSpecializationDecl::static_kind():
      tp = &(gTypes[785]);
      break;

    case mx::EnumDecl::static_kind():
      tp = &(gTypes[786]);
      break;

    case mx::UnresolvedUsingTypenameDecl::static_kind():
      tp = &(gTypes[787]);
      break;

    case mx::TypedefDecl::static_kind():
      tp = &(gTypes[789]);
      break;

    case mx::TypeAliasDecl::static_kind():
      tp = &(gTypes[790]);
      break;

    case mx::ObjCTypeParamDecl::static_kind():
      tp = &(gTypes[791]);
      break;

    case mx::FunctionTemplateDecl::static_kind():
      tp = &(gTypes[794]);
      break;

    case mx::ClassTemplateDecl::static_kind():
      tp = &(gTypes[795]);
      break;

    case mx::VarTemplateDecl::static_kind():
      tp = &(gTypes[796]);
      break;

    case mx::TypeAliasTemplateDecl::static_kind():
      tp = &(gTypes[797]);
      break;

    case mx::ConceptDecl::static_kind():
      tp = &(gTypes[798]);
      break;

    case mx::BuiltinTemplateDecl::static_kind():
      tp = &(gTypes[799]);
      break;

    case mx::TemplateTemplateParmDecl::static_kind():
      tp = &(gTypes[800]);
      break;

    case mx::ObjCPropertyDecl::static_kind():
      tp = &(gTypes[801]);
      break;

    case mx::ObjCMethodDecl::static_kind():
      tp = &(gTypes[802]);
      break;

    case mx::ObjCCategoryDecl::static_kind():
      tp = &(gTypes[804]);
      break;

    case mx::ObjCProtocolDecl::static_kind():
      tp = &(gTypes[805]);
      break;

    case mx::ObjCInterfaceDecl::static_kind():
      tp = &(gTypes[806]);
      break;

    case mx::ObjCCategoryImplDecl::static_kind():
      tp = &(gTypes[808]);
      break;

    case mx::ObjCImplementationDecl::static_kind():
      tp = &(gTypes[809]);
      break;

    case mx::ObjCCompatibleAliasDecl::static_kind():
      tp = &(gTypes[810]);
      break;

    case mx::NamespaceDecl::static_kind():
      tp = &(gTypes[811]);
      break;

    case mx::NamespaceAliasDecl::static_kind():
      tp = &(gTypes[812]);
      break;

    case mx::LinkageSpecDecl::static_kind():
      tp = &(gTypes[813]);
      break;

    case mx::LifetimeExtendedTemporaryDecl::static_kind():
      tp = &(gTypes[814]);
      break;

    case mx::ImportDecl::static_kind():
      tp = &(gTypes[815]);
      break;

    case mx::ImplicitConceptSpecializationDecl::static_kind():
      tp = &(gTypes[816]);
      break;

    case mx::FriendTemplateDecl::static_kind():
      tp = &(gTypes[817]);
      break;

    case mx::FriendDecl::static_kind():
      tp = &(gTypes[818]);
      break;

    case mx::FileScopeAsmDecl::static_kind():
      tp = &(gTypes[819]);
      break;

    case mx::ExternCContextDecl::static_kind():
      tp = &(gTypes[820]);
      break;

    case mx::ExportDecl::static_kind():
      tp = &(gTypes[821]);
      break;

    case mx::EmptyDecl::static_kind():
      tp = &(gTypes[822]);
      break;

  }
  auto ret = tp->tp_alloc(tp, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

namespace {
static PyTypeObject *InitType(void) noexcept;
}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    gType = InitType();
    if (!gType) {
      return false;
    }
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "Decl", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "parent_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parent_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::parent_declaration"),
    nullptr,
  },
  {
    "parent_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parent_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::parent_statement"),
    nullptr,
  },
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::id"),
    nullptr,
  },
  {
    "definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::definition"),
    nullptr,
  },
  {
    "is_definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_definition"),
    nullptr,
  },
  {
    "canonical_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->canonical_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::canonical_declaration"),
    nullptr,
  },
  {
    "redeclarations",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::redeclarations);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::redeclarations"),
    nullptr,
  },
  {
    "specializations",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::specializations);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::specializations"),
    nullptr,
  },
  {
    "num_attributes",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_attributes());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::num_attributes"),
    nullptr,
  },
  {
    "attributes",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::attributes);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::attributes"),
    nullptr,
  },
  {
    "availability",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->availability());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::availability"),
    nullptr,
  },
  {
    "defining_attribute",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->defining_attribute());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::defining_attribute"),
    nullptr,
  },
  {
    "external_source_symbol_attribute",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->external_source_symbol_attribute());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::external_source_symbol_attribute"),
    nullptr,
  },
  {
    "friend_object_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->friend_object_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::friend_object_kind"),
    nullptr,
  },
  {
    "max_alignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->max_alignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::max_alignment"),
    nullptr,
  },
  {
    "module_ownership_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->module_ownership_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::module_ownership_kind"),
    nullptr,
  },
  {
    "non_closure_context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->non_closure_context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::non_closure_context"),
    nullptr,
  },
  {
    "is_deprecated",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_deprecated());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_deprecated"),
    nullptr,
  },
  {
    "is_file_context_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_file_context_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_file_context_declaration"),
    nullptr,
  },
  {
    "is_function_or_function_template",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_function_or_function_template());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_function_or_function_template"),
    nullptr,
  },
  {
    "is_implicit",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicit());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_implicit"),
    nullptr,
  },
  {
    "is_in_anonymous_namespace",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_anonymous_namespace());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_in_anonymous_namespace"),
    nullptr,
  },
  {
    "is_in_another_module_unit",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_another_module_unit());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_in_another_module_unit"),
    nullptr,
  },
  {
    "is_in_export_declaration_context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_export_declaration_context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_in_export_declaration_context"),
    nullptr,
  },
  {
    "is_in_std_namespace",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_std_namespace());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_in_std_namespace"),
    nullptr,
  },
  {
    "is_invisible_outside_the_owning_module",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_invisible_outside_the_owning_module());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_invisible_outside_the_owning_module"),
    nullptr,
  },
  {
    "is_local_extern_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_local_extern_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_local_extern_declaration"),
    nullptr,
  },
  {
    "is_module_private",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_module_private());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_module_private"),
    nullptr,
  },
  {
    "is_out_of_line",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_out_of_line());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_out_of_line"),
    nullptr,
  },
  {
    "is_parameter_pack",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_parameter_pack());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_parameter_pack"),
    nullptr,
  },
  {
    "is_template_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_template_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_template_declaration"),
    nullptr,
  },
  {
    "is_template_parameter",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_template_parameter());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_template_parameter"),
    nullptr,
  },
  {
    "is_template_parameter_pack",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_template_parameter_pack());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_template_parameter_pack"),
    nullptr,
  },
  {
    "is_templated",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_templated());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_templated"),
    nullptr,
  },
  {
    "is_top_level_declaration_in_obj_c_container",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_top_level_declaration_in_obj_c_container());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_top_level_declaration_in_obj_c_container"),
    nullptr,
  },
  {
    "is_unavailable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_unavailable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_unavailable"),
    nullptr,
  },
  {
    "is_unconditionally_visible",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_unconditionally_visible());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_unconditionally_visible"),
    nullptr,
  },
  {
    "is_weak_imported",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_weak_imported());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::is_weak_imported"),
    nullptr,
  },
  {
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::kind"),
    nullptr,
  },
  {
    "category",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->category());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::category"),
    nullptr,
  },
  {
    "token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::token"),
    nullptr,
  },
  {
    "tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Decl::tokens"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "static_category",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(T::static_category());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'static_category'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Decl::static_category"),
  },
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::DeclKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::DeclKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::DeclKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Compilation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Compilation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<mx::DeclKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Decl::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Decl::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<EntityId>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::by_id(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Decl::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Operation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Reference>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation, mx::ir::Operation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenContext>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Decl::from"),
  },
  {
    "nth_attribute",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_attribute(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_attribute'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Decl::nth_attribute"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[723]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.Decl";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Decl");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = [] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(EntityId(T_cast(obj)->id()).Pack());
  };
  tp->tp_richcompare = [] (BorrowedPyObject *a_obj, BorrowedPyObject *b_obj, int op) -> SharedPyObject * {
    do {
      if (Py_EQ != op && Py_NE != op) {
        break;
      }

      auto a = ::mx::from_python<T>(a_obj);
      if (!a.has_value()) {
        break;
      }

      auto b = ::mx::from_python<T>(b_obj);
      if (!b.has_value()) {
        break;
      }

      auto ret = (a.value() == b.value()) == (Py_EQ == op) ? Py_True : Py_False;
      Py_INCREF(ret);
      return ret;
    } while (false);

    static constexpr const char *kOperators[] = {"<", "<=", "==", "!=", ">", ">="};
    PyErrorStreamer(PyExc_TypeError)
        << "'" << kOperators[op] << "' not supported between instances of '"
        << Py_TYPE(a_obj)->tp_name << "' and '" << Py_TYPE(b_obj)->tp_name << "'";
    return nullptr;
  };
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<VariantEntity>::type();
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Decl.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Decl.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Decl' cannot be directly instantiated";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
