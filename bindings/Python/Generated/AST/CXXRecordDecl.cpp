// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/CXXRecordDecl.h>

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
using T = mx::CXXRecordDecl;

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
  if (tp < &(gTypes[783]) || tp >= &(gTypes[786])) {
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

    case mx::CXXRecordDecl::static_kind():
      tp = &(gTypes[783]);
      break;

    case mx::ClassTemplateSpecializationDecl::static_kind():
      tp = &(gTypes[784]);
      break;

    case mx::ClassTemplatePartialSpecializationDecl::static_kind():
      tp = &(gTypes[785]);
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
  if (0 != PyModule_AddObjectRef(module, "CXXRecordDecl", tp_obj)) {
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::canonical_declaration"),
    nullptr,
  },
  {
    "definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::definition"),
    nullptr,
  },
  {
    "redeclarations",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::redeclarations);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::redeclarations"),
    nullptr,
  },
  {
    "allow_const_default_initializer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->allow_const_default_initializer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::allow_const_default_initializer"),
    nullptr,
  },
  {
    "bases",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->bases());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::bases"),
    nullptr,
  },
  {
    "inheritance_model",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->inheritance_model());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::inheritance_model"),
    nullptr,
  },
  {
    "num_constructors",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_constructors());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::num_constructors"),
    nullptr,
  },
  {
    "constructors",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::constructors);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::constructors"),
    nullptr,
  },
  {
    "friends",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->friends());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::friends"),
    nullptr,
  },
  {
    "dependent_lambda_call_operator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->dependent_lambda_call_operator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::dependent_lambda_call_operator"),
    nullptr,
  },
  {
    "described_class_template",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->described_class_template());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::described_class_template"),
    nullptr,
  },
  {
    "destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::destructor"),
    nullptr,
  },
  {
    "generic_lambda_template_parameter_list",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->generic_lambda_template_parameter_list());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::generic_lambda_template_parameter_list"),
    nullptr,
  },
  {
    "instantiated_from_member_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->instantiated_from_member_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::instantiated_from_member_class"),
    nullptr,
  },
  {
    "lambda_call_operator",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_call_operator());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_call_operator"),
    nullptr,
  },
  {
    "lambda_capture_default",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_capture_default());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_capture_default"),
    nullptr,
  },
  {
    "lambda_context_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_context_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_context_declaration"),
    nullptr,
  },
  {
    "lambda_explicit_template_parameters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_explicit_template_parameters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_explicit_template_parameters"),
    nullptr,
  },
  {
    "lambda_mangling_number",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_mangling_number());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_mangling_number"),
    nullptr,
  },
  {
    "lambda_static_invoker",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_static_invoker());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_static_invoker"),
    nullptr,
  },
  {
    "ms_inheritance_model",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ms_inheritance_model());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::ms_inheritance_model"),
    nullptr,
  },
  {
    "ms_vtor_disp_mode",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ms_vtor_disp_mode());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::ms_vtor_disp_mode"),
    nullptr,
  },
  {
    "has_any_dependent_bases",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_any_dependent_bases());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_any_dependent_bases"),
    nullptr,
  },
  {
    "has_constexpr_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_constexpr_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_constexpr_default_constructor"),
    nullptr,
  },
  {
    "has_constexpr_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_constexpr_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_constexpr_destructor"),
    nullptr,
  },
  {
    "has_constexpr_non_copy_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_constexpr_non_copy_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_constexpr_non_copy_move_constructor"),
    nullptr,
  },
  {
    "has_copy_assignment_with_const_parameter",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_copy_assignment_with_const_parameter());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_copy_assignment_with_const_parameter"),
    nullptr,
  },
  {
    "has_copy_constructor_with_const_parameter",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_copy_constructor_with_const_parameter());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_copy_constructor_with_const_parameter"),
    nullptr,
  },
  {
    "has_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_default_constructor"),
    nullptr,
  },
  {
    "has_definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_definition"),
    nullptr,
  },
  {
    "has_direct_fields",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_direct_fields());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_direct_fields"),
    nullptr,
  },
  {
    "has_friends",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_friends());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_friends"),
    nullptr,
  },
  {
    "has_in_class_initializer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_in_class_initializer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_in_class_initializer"),
    nullptr,
  },
  {
    "has_inherited_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_inherited_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_inherited_assignment"),
    nullptr,
  },
  {
    "has_inherited_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_inherited_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_inherited_constructor"),
    nullptr,
  },
  {
    "has_initializer_method",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_initializer_method());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_initializer_method"),
    nullptr,
  },
  {
    "has_irrelevant_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_irrelevant_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_irrelevant_destructor"),
    nullptr,
  },
  {
    "has_known_lambda_internal_linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_known_lambda_internal_linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_known_lambda_internal_linkage"),
    nullptr,
  },
  {
    "has_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_move_assignment"),
    nullptr,
  },
  {
    "has_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_move_constructor"),
    nullptr,
  },
  {
    "has_mutable_fields",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_mutable_fields());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_mutable_fields"),
    nullptr,
  },
  {
    "has_non_literal_type_fields_or_bases",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_literal_type_fields_or_bases());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_literal_type_fields_or_bases"),
    nullptr,
  },
  {
    "has_non_trivial_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_copy_assignment"),
    nullptr,
  },
  {
    "has_non_trivial_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_copy_constructor"),
    nullptr,
  },
  {
    "has_non_trivial_copy_constructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_copy_constructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_copy_constructor_for_call"),
    nullptr,
  },
  {
    "has_non_trivial_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_default_constructor"),
    nullptr,
  },
  {
    "has_non_trivial_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_destructor"),
    nullptr,
  },
  {
    "has_non_trivial_destructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_destructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_destructor_for_call"),
    nullptr,
  },
  {
    "has_non_trivial_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_move_assignment"),
    nullptr,
  },
  {
    "has_non_trivial_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_move_constructor"),
    nullptr,
  },
  {
    "has_non_trivial_move_constructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_move_constructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_non_trivial_move_constructor_for_call"),
    nullptr,
  },
  {
    "has_private_fields",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_private_fields());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_private_fields"),
    nullptr,
  },
  {
    "has_protected_fields",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_protected_fields());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_protected_fields"),
    nullptr,
  },
  {
    "has_simple_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_simple_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_simple_copy_assignment"),
    nullptr,
  },
  {
    "has_simple_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_simple_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_simple_copy_constructor"),
    nullptr,
  },
  {
    "has_simple_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_simple_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_simple_destructor"),
    nullptr,
  },
  {
    "has_simple_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_simple_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_simple_move_assignment"),
    nullptr,
  },
  {
    "has_simple_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_simple_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_simple_move_constructor"),
    nullptr,
  },
  {
    "has_trivial_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_copy_assignment"),
    nullptr,
  },
  {
    "has_trivial_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_copy_constructor"),
    nullptr,
  },
  {
    "has_trivial_copy_constructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_copy_constructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_copy_constructor_for_call"),
    nullptr,
  },
  {
    "has_trivial_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_default_constructor"),
    nullptr,
  },
  {
    "has_trivial_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_destructor"),
    nullptr,
  },
  {
    "has_trivial_destructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_destructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_destructor_for_call"),
    nullptr,
  },
  {
    "has_trivial_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_move_assignment"),
    nullptr,
  },
  {
    "has_trivial_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_move_constructor"),
    nullptr,
  },
  {
    "has_trivial_move_constructor_for_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_trivial_move_constructor_for_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_trivial_move_constructor_for_call"),
    nullptr,
  },
  {
    "has_uninitialized_reference_member",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_uninitialized_reference_member());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_uninitialized_reference_member"),
    nullptr,
  },
  {
    "has_user_declared_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_constructor"),
    nullptr,
  },
  {
    "has_user_declared_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_copy_assignment"),
    nullptr,
  },
  {
    "has_user_declared_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_copy_constructor"),
    nullptr,
  },
  {
    "has_user_declared_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_destructor"),
    nullptr,
  },
  {
    "has_user_declared_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_move_assignment"),
    nullptr,
  },
  {
    "has_user_declared_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_move_constructor"),
    nullptr,
  },
  {
    "has_user_declared_move_operation",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_declared_move_operation());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_declared_move_operation"),
    nullptr,
  },
  {
    "has_user_provided_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_user_provided_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_user_provided_default_constructor"),
    nullptr,
  },
  {
    "has_variant_members",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_variant_members());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_variant_members"),
    nullptr,
  },
  {
    "implicit_copy_assignment_has_const_parameter",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->implicit_copy_assignment_has_const_parameter());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::implicit_copy_assignment_has_const_parameter"),
    nullptr,
  },
  {
    "implicit_copy_constructor_has_const_parameter",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->implicit_copy_constructor_has_const_parameter());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::implicit_copy_constructor_has_const_parameter"),
    nullptr,
  },
  {
    "is_abstract",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_abstract());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_abstract"),
    nullptr,
  },
  {
    "is_aggregate",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_aggregate());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_aggregate"),
    nullptr,
  },
  {
    "is_any_destructor_no_return",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_any_destructor_no_return());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_any_destructor_no_return"),
    nullptr,
  },
  {
    "is_c_like",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_c_like());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_c_like"),
    nullptr,
  },
  {
    "is_cxx11_standard_layout",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_cxx11_standard_layout());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_cxx11_standard_layout"),
    nullptr,
  },
  {
    "is_captureless_lambda",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_captureless_lambda());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_captureless_lambda"),
    nullptr,
  },
  {
    "is_dependent_lambda",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_dependent_lambda());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_dependent_lambda"),
    nullptr,
  },
  {
    "is_dynamic_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_dynamic_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_dynamic_class"),
    nullptr,
  },
  {
    "is_effectively_final",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_effectively_final());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_effectively_final"),
    nullptr,
  },
  {
    "is_empty",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_empty());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_empty"),
    nullptr,
  },
  {
    "is_generic_lambda",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_generic_lambda());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_generic_lambda"),
    nullptr,
  },
  {
    "is_interface_like",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_interface_like());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_interface_like"),
    nullptr,
  },
  {
    "is_literal",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_literal());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_literal"),
    nullptr,
  },
  {
    "is_local_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_local_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_local_class"),
    nullptr,
  },
  {
    "is_never_dependent_lambda",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_never_dependent_lambda());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_never_dependent_lambda"),
    nullptr,
  },
  {
    "is_pod",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_pod());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_pod"),
    nullptr,
  },
  {
    "is_polymorphic",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_polymorphic());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_polymorphic"),
    nullptr,
  },
  {
    "is_standard_layout",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_standard_layout());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_standard_layout"),
    nullptr,
  },
  {
    "is_structural",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_structural());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_structural"),
    nullptr,
  },
  {
    "is_trivial",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_trivial());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_trivial"),
    nullptr,
  },
  {
    "is_trivially_copy_constructible",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_trivially_copy_constructible());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_trivially_copy_constructible"),
    nullptr,
  },
  {
    "is_trivially_copyable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_trivially_copyable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::is_trivially_copyable"),
    nullptr,
  },
  {
    "lambda_is_default_constructible_and_assignable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lambda_is_default_constructible_and_assignable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::lambda_is_default_constructible_and_assignable"),
    nullptr,
  },
  {
    "may_be_abstract",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->may_be_abstract());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::may_be_abstract"),
    nullptr,
  },
  {
    "may_be_dynamic_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->may_be_dynamic_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::may_be_dynamic_class"),
    nullptr,
  },
  {
    "may_be_non_dynamic_class",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->may_be_non_dynamic_class());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::may_be_non_dynamic_class"),
    nullptr,
  },
  {
    "needs_implicit_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_copy_assignment"),
    nullptr,
  },
  {
    "needs_implicit_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_copy_constructor"),
    nullptr,
  },
  {
    "needs_implicit_default_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_default_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_default_constructor"),
    nullptr,
  },
  {
    "needs_implicit_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_destructor"),
    nullptr,
  },
  {
    "needs_implicit_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_move_assignment"),
    nullptr,
  },
  {
    "needs_implicit_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_implicit_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_implicit_move_constructor"),
    nullptr,
  },
  {
    "needs_overload_resolution_for_copy_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_overload_resolution_for_copy_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_overload_resolution_for_copy_assignment"),
    nullptr,
  },
  {
    "needs_overload_resolution_for_copy_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_overload_resolution_for_copy_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_overload_resolution_for_copy_constructor"),
    nullptr,
  },
  {
    "needs_overload_resolution_for_destructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_overload_resolution_for_destructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_overload_resolution_for_destructor"),
    nullptr,
  },
  {
    "needs_overload_resolution_for_move_assignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_overload_resolution_for_move_assignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_overload_resolution_for_move_assignment"),
    nullptr,
  },
  {
    "needs_overload_resolution_for_move_constructor",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->needs_overload_resolution_for_move_constructor());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::needs_overload_resolution_for_move_constructor"),
    nullptr,
  },
  {
    "null_field_offset_is_zero",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->null_field_offset_is_zero());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::null_field_offset_is_zero"),
    nullptr,
  },
  {
    "virtual_bases",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->virtual_bases());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::virtual_bases"),
    nullptr,
  },
  {
    "size_without_virtual_bases",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->size_without_virtual_bases());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::size_without_virtual_bases"),
    nullptr,
  },
  {
    "primary_base",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->primary_base());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::primary_base"),
    nullptr,
  },
  {
    "has_own_virtual_function_table_pointer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_own_virtual_function_table_pointer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_own_virtual_function_table_pointer"),
    nullptr,
  },
  {
    "has_extendable_virtual_function_table_pointer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_extendable_virtual_function_table_pointer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_extendable_virtual_function_table_pointer"),
    nullptr,
  },
  {
    "has_virtual_base_table_pointer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_virtual_base_table_pointer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_virtual_base_table_pointer"),
    nullptr,
  },
  {
    "has_own_virtual_base_table_pointer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_own_virtual_base_table_pointer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::has_own_virtual_base_table_pointer"),
    nullptr,
  },
  {
    "derived_classes",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::derived_classes);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::derived_classes"),
    nullptr,
  },
  {
    "base_classes",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::base_classes);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::base_classes"),
    nullptr,
  },
  {
    "methods",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::generator_to_python(*T_cast(self), &T::methods);
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::methods"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::in"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::containing"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::by_id"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::from"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::static_kind"),
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
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::from_base"),
  },
  {
    "nth_constructor",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_constructor(std::move(arg_0.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_constructor'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::CXXRecordDecl::nth_constructor"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[783]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.CXXRecordDecl";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::CXXRecordDecl");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[782].tp_hash;
  tp->tp_richcompare = gTypes[782].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[782]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'CXXRecordDecl.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'CXXRecordDecl.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'CXXRecordDecl' cannot be directly instantiated";
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
