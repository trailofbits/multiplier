// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/FunctionDecl.h>

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
using T = mx::FunctionDecl;

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
  if (tp < &(gTypes[737]) || tp >= &(gTypes[743])) {
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

    case mx::FunctionDecl::static_kind():
      tp = &(gTypes[737]);
      break;

    case mx::CXXMethodDecl::static_kind():
      tp = &(gTypes[738]);
      break;

    case mx::CXXDestructorDecl::static_kind():
      tp = &(gTypes[739]);
      break;

    case mx::CXXConversionDecl::static_kind():
      tp = &(gTypes[740]);
      break;

    case mx::CXXConstructorDecl::static_kind():
      tp = &(gTypes[741]);
      break;

    case mx::CXXDeductionGuideDecl::static_kind():
      tp = &(gTypes[742]);
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
  if (0 != PyModule_AddObjectRef(module, "FunctionDecl", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "canonical_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->canonical_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::canonical_declaration"),
    nullptr,
  },
  {
    "definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::definition"),
    nullptr,
  },
  {
    "redeclarations",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->redeclarations());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::redeclarations"),
    nullptr,
  },
  {
    "body_contains_immediate_escalating_expressions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->body_contains_immediate_escalating_expressions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::body_contains_immediate_escalating_expressions"),
    nullptr,
  },
  {
    "friend_constraint_refers_to_enclosing_template",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->friend_constraint_refers_to_enclosing_template());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::friend_constraint_refers_to_enclosing_template"),
    nullptr,
  },
  {
    "uses_fp_intrin",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->uses_fp_intrin());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::uses_fp_intrin"),
    nullptr,
  },
  {
    "does_declaration_force_externally_visible_definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->does_declaration_force_externally_visible_definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::does_declaration_force_externally_visible_definition"),
    nullptr,
  },
  {
    "does_this_declaration_have_a_body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->does_this_declaration_have_a_body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::does_this_declaration_have_a_body"),
    nullptr,
  },
  {
    "call_result_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->call_result_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::call_result_type"),
    nullptr,
  },
  {
    "constexpr_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->constexpr_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::constexpr_kind"),
    nullptr,
  },
  {
    "declared_return_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->declared_return_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::declared_return_type"),
    nullptr,
  },
  {
    "default_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->default_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::default_token"),
    nullptr,
  },
  {
    "described_function_template",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->described_function_template());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::described_function_template"),
    nullptr,
  },
  {
    "ellipsis_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ellipsis_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::ellipsis_token"),
    nullptr,
  },
  {
    "exception_spec_tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->exception_spec_tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::exception_spec_tokens"),
    nullptr,
  },
  {
    "exception_spec_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->exception_spec_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::exception_spec_type"),
    nullptr,
  },
  {
    "instantiated_from_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->instantiated_from_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::instantiated_from_declaration"),
    nullptr,
  },
  {
    "instantiated_from_member_function",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->instantiated_from_member_function());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::instantiated_from_member_function"),
    nullptr,
  },
  {
    "language_linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->language_linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::language_linkage"),
    nullptr,
  },
  {
    "multi_version_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->multi_version_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::multi_version_kind"),
    nullptr,
  },
  {
    "odr_hash",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->odr_hash());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::odr_hash"),
    nullptr,
  },
  {
    "overloaded_operator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->overloaded_operator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::overloaded_operator"),
    nullptr,
  },
  {
    "parameters_tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parameters_tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::parameters_tokens"),
    nullptr,
  },
  {
    "point_of_instantiation",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->point_of_instantiation());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::point_of_instantiation"),
    nullptr,
  },
  {
    "primary_template",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->primary_template());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::primary_template"),
    nullptr,
  },
  {
    "return_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->return_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::return_type"),
    nullptr,
  },
  {
    "storage_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->storage_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::storage_class"),
    nullptr,
  },
  {
    "template_instantiation_pattern",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->template_instantiation_pattern());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::template_instantiation_pattern"),
    nullptr,
  },
  {
    "template_specialization_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->template_specialization_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::template_specialization_kind"),
    nullptr,
  },
  {
    "template_specialization_kind_for_instantiation",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->template_specialization_kind_for_instantiation());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::template_specialization_kind_for_instantiation"),
    nullptr,
  },
  {
    "templated_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->templated_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::templated_kind"),
    nullptr,
  },
  {
    "has_implicit_return_zero",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_implicit_return_zero());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_implicit_return_zero"),
    nullptr,
  },
  {
    "has_inherited_prototype",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_inherited_prototype());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_inherited_prototype"),
    nullptr,
  },
  {
    "has_one_parameter_or_default_arguments",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_one_parameter_or_default_arguments());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_one_parameter_or_default_arguments"),
    nullptr,
  },
  {
    "has_prototype",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_prototype());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_prototype"),
    nullptr,
  },
  {
    "has_skipped_body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_skipped_body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_skipped_body"),
    nullptr,
  },
  {
    "has_trivial_body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_trivial_body"),
    nullptr,
  },
  {
    "has_written_prototype",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_written_prototype());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::has_written_prototype"),
    nullptr,
  },
  {
    "instantiation_is_pending",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->instantiation_is_pending());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::instantiation_is_pending"),
    nullptr,
  },
  {
    "is_cpu_dispatch_multi_version",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_cpu_dispatch_multi_version());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_cpu_dispatch_multi_version"),
    nullptr,
  },
  {
    "is_cpu_specific_multi_version",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_cpu_specific_multi_version());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_cpu_specific_multi_version"),
    nullptr,
  },
  {
    "is_consteval",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_consteval());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_consteval"),
    nullptr,
  },
  {
    "is_constexpr",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_constexpr());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_constexpr"),
    nullptr,
  },
  {
    "is_constexpr_specified",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_constexpr_specified());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_constexpr_specified"),
    nullptr,
  },
  {
    "is_defaulted",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_defaulted());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_defaulted"),
    nullptr,
  },
  {
    "is_deleted",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_deleted());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_deleted"),
    nullptr,
  },
  {
    "is_deleted_as_written",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_deleted_as_written());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_deleted_as_written"),
    nullptr,
  },
  {
    "is_destroying_operator_delete",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_destroying_operator_delete());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_destroying_operator_delete"),
    nullptr,
  },
  {
    "is_explicitly_defaulted",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_explicitly_defaulted());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_explicitly_defaulted"),
    nullptr,
  },
  {
    "is_extern_c",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_extern_c());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_extern_c"),
    nullptr,
  },
  {
    "is_function_template_specialization",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_function_template_specialization());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_function_template_specialization"),
    nullptr,
  },
  {
    "is_global",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_global());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_global"),
    nullptr,
  },
  {
    "is_immediate_escalating",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_immediate_escalating());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_immediate_escalating"),
    nullptr,
  },
  {
    "is_immediate_function",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_immediate_function());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_immediate_function"),
    nullptr,
  },
  {
    "is_implicitly_instantiable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicitly_instantiable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_implicitly_instantiable"),
    nullptr,
  },
  {
    "is_in_extern_c_context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_extern_c_context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_in_extern_c_context"),
    nullptr,
  },
  {
    "is_in_extern_cxx_context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_in_extern_cxx_context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_in_extern_cxx_context"),
    nullptr,
  },
  {
    "is_ineligible_or_not_selected",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_ineligible_or_not_selected());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_ineligible_or_not_selected"),
    nullptr,
  },
  {
    "is_inline_builtin_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_inline_builtin_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_inline_builtin_declaration"),
    nullptr,
  },
  {
    "is_inline_definition_externally_visible",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_inline_definition_externally_visible());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_inline_definition_externally_visible"),
    nullptr,
  },
  {
    "is_inline_specified",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_inline_specified());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_inline_specified"),
    nullptr,
  },
  {
    "is_inlined",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_inlined());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_inlined"),
    nullptr,
  },
  {
    "is_late_template_parsed",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_late_template_parsed());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_late_template_parsed"),
    nullptr,
  },
  {
    "is_ms_extern_inline",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_ms_extern_inline());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_ms_extern_inline"),
    nullptr,
  },
  {
    "is_msvcrt_entry_point",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_msvcrt_entry_point());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_msvcrt_entry_point"),
    nullptr,
  },
  {
    "is_main",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_main());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_main"),
    nullptr,
  },
  {
    "is_member_like_constrained_friend",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_member_like_constrained_friend());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_member_like_constrained_friend"),
    nullptr,
  },
  {
    "is_multi_version",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_multi_version());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_multi_version"),
    nullptr,
  },
  {
    "is_no_return",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_no_return());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_no_return"),
    nullptr,
  },
  {
    "is_overloaded_operator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_overloaded_operator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_overloaded_operator"),
    nullptr,
  },
  {
    "is_pure",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_pure());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_pure"),
    nullptr,
  },
  {
    "is_replaceable_global_allocation_function",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_replaceable_global_allocation_function());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_replaceable_global_allocation_function"),
    nullptr,
  },
  {
    "is_reserved_global_placement_operator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_reserved_global_placement_operator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_reserved_global_placement_operator"),
    nullptr,
  },
  {
    "is_static",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_static());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_static"),
    nullptr,
  },
  {
    "is_target_clones_multi_version",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_target_clones_multi_version());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_target_clones_multi_version"),
    nullptr,
  },
  {
    "is_target_multi_version",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_target_multi_version());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_target_multi_version"),
    nullptr,
  },
  {
    "is_template_instantiation",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_template_instantiation());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_template_instantiation"),
    nullptr,
  },
  {
    "is_this_declaration_a_definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_this_declaration_a_definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_this_declaration_a_definition"),
    nullptr,
  },
  {
    "is_this_declaration_instantiated_from_a_friend_definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_this_declaration_instantiated_from_a_friend_definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_this_declaration_instantiated_from_a_friend_definition"),
    nullptr,
  },
  {
    "is_trivial",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_trivial());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_trivial"),
    nullptr,
  },
  {
    "is_trivial_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_trivial_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_trivial_for_call"),
    nullptr,
  },
  {
    "is_user_provided",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_user_provided());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_user_provided"),
    nullptr,
  },
  {
    "is_variadic",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_variadic());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_variadic"),
    nullptr,
  },
  {
    "is_virtual_as_written",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_virtual_as_written());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::is_virtual_as_written"),
    nullptr,
  },
  {
    "num_parameters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_parameters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::num_parameters"),
    nullptr,
  },
  {
    "parameters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parameters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::parameters"),
    nullptr,
  },
  {
    "uses_seh_try",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->uses_seh_try());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::uses_seh_try"),
    nullptr,
  },
  {
    "will_have_body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->will_have_body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::will_have_body"),
    nullptr,
  },
  {
    "body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::body"),
    nullptr,
  },
  {
    "declarations_in_context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->declarations_in_context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::declarations_in_context"),
    nullptr,
  },
  {
    "callers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->callers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::FunctionDecl::callers"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
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

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::FunctionDecl::in"),
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
    PyDoc_STR("Wrapper for mx::FunctionDecl::containing"),
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

            return ::mx::to_python(T::by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::FunctionDecl::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::hl::Operation>(args[0]);
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
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::FunctionDecl::from"),
  },
  {
    "static_kind",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(T::static_kind());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'static_kind'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::FunctionDecl::static_kind"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::FunctionDecl::from_base"),
  },
  {
    "nth_parameter",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_parameter(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_parameter'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::FunctionDecl::nth_parameter"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[737]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.FunctionDecl";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::FunctionDecl");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[727].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[727]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'FunctionDecl.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'FunctionDecl.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'FunctionDecl' cannot be directly instantiated";
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
