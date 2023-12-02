// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>

#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::Expr;

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
  if (tp < &(gTypes[560]) || tp >= &(gTypes[692])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      tp = gType;
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
  if (0 != PyModule_AddObjectRef(module, "Expr", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyMethodDef gMethods[] = {
  {
    "contained_in",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'contained_in'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Expr::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Expr::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<mx::EntityId>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Expr::by_id"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Expr::from_base"),
  },
  {
    "cast",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Reference>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenContext>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'cast'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Expr::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyGetSetDef gProperties[] = {
  {
    "has_side_effects",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_side_effects());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::has_side_effects"),
    nullptr,
  },
  {
    "ignore_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_casts"),
    nullptr,
  },
  {
    "ignore_conversion_operator_single_step",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_conversion_operator_single_step());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_conversion_operator_single_step"),
    nullptr,
  },
  {
    "ignore_implicit_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit_casts"),
    nullptr,
  },
  {
    "ignore_implicit",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit"),
    nullptr,
  },
  {
    "ignore_implicit_as_written",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit_as_written());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit_as_written"),
    nullptr,
  },
  {
    "ignore_parenthesis_base_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_base_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_base_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_implicit_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_implicit_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_implicit_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_l_value_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_l_value_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_l_value_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_noop_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_noop_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_noop_casts"),
    nullptr,
  },
  {
    "ignore_parentheses",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parentheses());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parentheses"),
    nullptr,
  },
  {
    "ignore_unless_spelled_in_source",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_unless_spelled_in_source());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_unless_spelled_in_source"),
    nullptr,
  },
  {
    "contains_errors",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_errors());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::contains_errors"),
    nullptr,
  },
  {
    "contains_unexpanded_parameter_pack",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_unexpanded_parameter_pack());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::contains_unexpanded_parameter_pack"),
    nullptr,
  },
  {
    "dependence",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->dependence());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::dependence"),
    nullptr,
  },
  {
    "expression_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->expression_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::expression_token"),
    nullptr,
  },
  {
    "obj_c_property",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->obj_c_property());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::obj_c_property"),
    nullptr,
  },
  {
    "object_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->object_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::object_kind"),
    nullptr,
  },
  {
    "referenced_declaration_of_callee",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->referenced_declaration_of_callee());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::referenced_declaration_of_callee"),
    nullptr,
  },
  {
    "source_bit_field",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->source_bit_field());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::source_bit_field"),
    nullptr,
  },
  {
    "type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::type"),
    nullptr,
  },
  {
    "value_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->value_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::value_kind"),
    nullptr,
  },
  {
    "has_non_trivial_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::has_non_trivial_call"),
    nullptr,
  },
  {
    "is_default_argument",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_default_argument());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_default_argument"),
    nullptr,
  },
  {
    "is_gl_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_gl_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_gl_value"),
    nullptr,
  },
  {
    "is_implicit_cxx_this",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicit_cxx_this());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_implicit_cxx_this"),
    nullptr,
  },
  {
    "is_instantiation_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_instantiation_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_instantiation_dependent"),
    nullptr,
  },
  {
    "is_integer_constant_expression",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_integer_constant_expression());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_integer_constant_expression"),
    nullptr,
  },
  {
    "is_known_to_have_boolean_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_known_to_have_boolean_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_known_to_have_boolean_value"),
    nullptr,
  },
  {
    "is_l_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_l_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_l_value"),
    nullptr,
  },
  {
    "is_objcgc_candidate",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_objcgc_candidate());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_objcgc_candidate"),
    nullptr,
  },
  {
    "is_obj_c_self_expression",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_obj_c_self_expression());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_obj_c_self_expression"),
    nullptr,
  },
  {
    "is_ordinary_or_bit_field_object",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_ordinary_or_bit_field_object());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_ordinary_or_bit_field_object"),
    nullptr,
  },
  {
    "is_pr_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_pr_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_pr_value"),
    nullptr,
  },
  {
    "is_read_if_discarded_in_c_plus_plus11",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_read_if_discarded_in_c_plus_plus11());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_read_if_discarded_in_c_plus_plus11"),
    nullptr,
  },
  {
    "is_type_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_type_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_type_dependent"),
    nullptr,
  },
  {
    "is_value_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_value_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_value_dependent"),
    nullptr,
  },
  {
    "is_x_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_x_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_x_value"),
    nullptr,
  },
  {
    "refers_to_bit_field",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_bit_field());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_bit_field"),
    nullptr,
  },
  {
    "refers_to_global_register_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_global_register_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_global_register_variable"),
    nullptr,
  },
  {
    "refers_to_matrix_element",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_matrix_element());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_matrix_element"),
    nullptr,
  },
  {
    "refers_to_vector_element",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_vector_element());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_vector_element"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[560]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.Expr";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Expr");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PythonBinding<mx::ValueStmt>::type()->tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;  // TODO
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<mx::ValueStmt>::type();
  tp->tp_init = [] (BorrowedPyObject *, BorrowedPyObject *, BorrowedPyObject *) -> int {
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Expr' cannot be directly instantiated";
    return -1;
  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;  // Don't allow instantiation.

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
