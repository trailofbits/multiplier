// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/MemberExpr.h>

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
using T = mx::MemberExpr;

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
  if (tp < &(gTypes[672]) || tp >= &(gTypes[673])) {
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

    case mx::MemberExpr::static_kind():
      tp = &(gTypes[672]);
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
  if (0 != PyModule_AddObjectRef(module, "MemberExpr", tp_obj)) {
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
    PyDoc_STR("Wrapper for mx::MemberExpr::in"),
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
    PyDoc_STR("Wrapper for mx::MemberExpr::containing"),
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
    PyDoc_STR("Wrapper for mx::MemberExpr::by_id"),
  },
  {
    "static_kind",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(obj->static_kind());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'static_kind'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::MemberExpr::static_kind"),
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
    PyDoc_STR("Wrapper for mx::MemberExpr::from_base"),
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
    PyDoc_STR("Wrapper for mx::MemberExpr::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyGetSetDef gProperties[] = {
  {
    "base",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->base());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::base"),
    nullptr,
  },
  {
    "l_angle_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->l_angle_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::l_angle_token"),
    nullptr,
  },
  {
    "member_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->member_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::member_declaration"),
    nullptr,
  },
  {
    "member_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->member_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::member_token"),
    nullptr,
  },
  {
    "operator_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->operator_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::operator_token"),
    nullptr,
  },
  {
    "r_angle_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->r_angle_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::r_angle_token"),
    nullptr,
  },
  {
    "template_keyword_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->template_keyword_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::template_keyword_token"),
    nullptr,
  },
  {
    "had_multiple_candidates",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->had_multiple_candidates());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::had_multiple_candidates"),
    nullptr,
  },
  {
    "has_explicit_template_arguments",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_explicit_template_arguments());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::has_explicit_template_arguments"),
    nullptr,
  },
  {
    "has_qualifier",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_qualifier());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::has_qualifier"),
    nullptr,
  },
  {
    "has_template_keyword",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_template_keyword());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::has_template_keyword"),
    nullptr,
  },
  {
    "is_arrow",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_arrow());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::is_arrow"),
    nullptr,
  },
  {
    "is_implicit_access",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicit_access());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::is_implicit_access"),
    nullptr,
  },
  {
    "is_non_odr_use",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_non_odr_use());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::MemberExpr::is_non_odr_use"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[672]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.MemberExpr";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::MemberExpr");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PythonBinding<mx::Expr>::type()->tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;  // TODO
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<mx::Expr>::type();
  tp->tp_init = [] (BorrowedPyObject *, BorrowedPyObject *, BorrowedPyObject *) -> int {
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'MemberExpr' cannot be directly instantiated";
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
