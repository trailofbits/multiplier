// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/File.h>

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
using T = mx::File;

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
  if (tp < &(gTypes[804]) || tp >= &(gTypes[805])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
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
  if (0 != PyModule_AddObjectRef(module, "File", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::id"),
    nullptr,
  },
  {
    "fragments",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->fragments());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::fragments"),
    nullptr,
  },
  {
    "paths",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->paths());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::paths"),
    nullptr,
  },
  {
    "fragment_ids",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->fragment_ids());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::fragment_ids"),
    nullptr,
  },
  {
    "tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::tokens"),
    nullptr,
  },
  {
    "data",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->data());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::File::data"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::RegexQueryMatch>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
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
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Attr>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Macro>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TemplateArgument>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TemplateParameterList>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::CXXBaseSpecifier>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Designator>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Operation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenRange>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenTree>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation, mx::ir::Operation>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::File::containing"),
  },
  {
    "entity_category",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(T::entity_category());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'entity_category'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::File::entity_category"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[804]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.frontend.File";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::File");
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
          << "'File.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'File.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'File' cannot be directly instantiated";
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
