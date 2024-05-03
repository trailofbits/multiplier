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
using T = mx::Token;

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
  if (tp < &(gTypes[826]) || tp >= &(gTypes[827])) {
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
  if (0 != PyModule_AddObjectRef(module, "Token", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::kind"),
    nullptr,
  },
  {
    "data",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->data());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::data"),
    nullptr,
  },
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::id"),
    nullptr,
  },
  {
    "context",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->context());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::context"),
    nullptr,
  },
  {
    "parsed_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->parsed_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::parsed_token"),
    nullptr,
  },
  {
    "derived_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->derived_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::derived_token"),
    nullptr,
  },
  {
    "file_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->file_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::file_token"),
    nullptr,
  },
  {
    "nearest_file_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->nearest_file_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::nearest_file_token"),
    nullptr,
  },
  {
    "related_entity",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->related_entity());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::related_entity"),
    nullptr,
  },
  {
    "related_entity_id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->related_entity_id());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::related_entity_id"),
    nullptr,
  },
  {
    "category",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->category());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::category"),
    nullptr,
  },
  {
    "containing_macro",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->containing_macro());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Token::containing_macro"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation, mx::ir::Operation>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::Token::from"),
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
    PyDoc_STR("Wrapper for mx::Token::entity_category"),
  },
  {
    "categorize",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation, mx::ir::Operation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::categorize(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'categorize'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Token::categorize"),
  },
  {
    "location",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<FileLocationCache>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->location(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'location'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Token::location"),
  },
  {
    "next_location",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<FileLocationCache>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->next_location(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'next_location'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Token::next_location"),
  },
  {
    "nearest_location",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<FileLocationCache>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nearest_location(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nearest_location'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Token::nearest_location"),
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

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[826]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.frontend.Token";
  tp->tp_flags = Py_TPFLAGS_DEFAULT;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Token");
  tp->tp_as_number = &gNumberMethods;
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
          << "'Token.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Token.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    while (num_args == 0) {
      obj->data = new (obj->backing_storage) Token();
      return 0;
    }

    PyErrorStreamer(PyExc_TypeError)
        << "Invalid arguments to 'Token.__init__'";
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
