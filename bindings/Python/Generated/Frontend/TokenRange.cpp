// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Frontend/Token.h>

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
using T = mx::TokenRange;

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
  if (tp < &(gTypes[827]) || tp >= &(gTypes[829])) {
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
  if (0 != PyModule_AddObjectRef(module, "TokenRange", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "empty",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->empty());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::empty"),
    nullptr,
  },
  {
    "size",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->size());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::size"),
    nullptr,
  },
  {
    "front",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->front());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::front"),
    nullptr,
  },
  {
    "back",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->back());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::back"),
    nullptr,
  },
  {
    "data",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->data());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::data"),
    nullptr,
  },
  {
    "file_tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->file_tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::file_tokens"),
    nullptr,
  },
  {
    "strip_whitespace",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->strip_whitespace());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::TokenRange::strip_whitespace"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "create",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::vector<std::variant<UserToken, mx::Token>>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::create(std::move(arg_0.value())));
          }
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<mx::Token>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::create(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'create'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::TokenRange::create"),
  },
  {
    "slice",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<uint64_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<uint64_t>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->slice(std::move(arg_0.value()), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'slice'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::TokenRange::slice"),
  },
  {
    "index_of",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->index_of(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'index_of'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::TokenRange::index_of"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

static PyNumberMethods gNumberMethods = {
  .nb_bool = [] (BorrowedPyObject *obj) -> int {
    return !!*T_cast(obj);
  }
};

}  // namespace

namespace {

static PySequenceMethods gSequenceMethods = {
  .sq_length = [] (BorrowedPyObject *obj) -> Py_ssize_t {
        return static_cast<Py_ssize_t>(T_cast(obj)->size());
      },
  .sq_item = [] (BorrowedPyObject *obj, Py_ssize_t index) -> SharedPyObject * {
        auto len = static_cast<Py_ssize_t>(T_cast(obj)->size());
        if (index >= len) {
          PyErrorStreamer(PyExc_IndexError)
              << "Invalid index '" << index << "'";
          return nullptr;
        }
        return ::mx::to_python(T_cast(obj)->operator[](static_cast<unsigned>(index)));
      },
};

}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[827]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.frontend.TokenRange";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_SEQUENCE ;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::TokenRange");
  tp->tp_as_number = &gNumberMethods;
  tp->tp_as_sequence = &gSequenceMethods;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PyObject_HashNotImplemented;
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
  tp->tp_base = nullptr;
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'TokenRange.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'TokenRange.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    while (num_args == 0) {
      obj->data = new (obj->backing_storage) TokenRange();
      return 0;
    }

    while (num_args == 1) {
      SharedPyPtr obj_0(PySequence_GetItem(args, 0));
      PyErr_Clear();
      if (!obj_0) {
        break;
      }
      auto arg_0 = ::mx::from_python<mx::Token>(obj_0.Get());
      if (!arg_0.has_value()) {
        break;
      }

      obj->data = new (obj->backing_storage) TokenRange(arg_0.value());
      return 0;
    }

    PyErrorStreamer(PyExc_TypeError)
        << "Invalid arguments to 'TokenRange.__init__'";
    return -1;

  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = PyType_GenericNew;

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
