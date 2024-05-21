// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <multiplier/Index.h>

#include "Error.h"

namespace mx {
namespace {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"

using T = QualifiedNameRenderOptions;

struct O final : public ::PyObject {

  // When initialized, points to `backing_storage`.
  T *data{nullptr};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
};

static PyTypeObject gTypeDef = {
  .tp_name = "multiplier.ast.QualifiedNameRenderOptions",
  .tp_hash = PyObject_HashNotImplemented,
  .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
  .tp_doc = PyDoc_STR("Name rendering options to be used by NamedDecl.qualified_name."),
  .tp_base = &PyBaseObject_Type,
  .tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args,
                 BorrowedPyObject *kwargs) -> int {
    if (args && (!PySequence_Check(args) || PySequence_Size(args))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'QualifiedNameRenderOptions.__init__' does not take any positional arguments";
      return -1;
    }

    if (!kwargs || !PyMapping_Check(kwargs) || !PyMapping_Size(kwargs)) {
      PyErrorStreamer(PyExc_TypeError)
          << "'QualifiedNameRenderOptions.__init__' requires at least one keyword argument";
      return -1;
    }

    // Initialize the options.
    auto obj = reinterpret_cast<O *>(self);
    obj->data = new (obj->backing_storage) T;

 #define FOR_EACH_OPTIONS(m) \
    m(fully_qualified) \
    m(render_anonymous_classes) \
    m(render_anonymous_structs) \
    m(render_anonymous_fields) \
    m(render_anonymous_unions) \
    m(render_anonymous_enums) \
    m(render_anonymous_namespaces) \
    m(render_anonymous_parameters) \
    m(render_inline_namespaces) \
    m(render_template_parameters) \
    m(render_template_arguments) \
    m(find_name_in_redeclaration) \
    m(include_function_parameter_types)

  #define GET_SET_OPTION(opt) \
      { \
        SharedPyPtr val(PyMapping_GetItemString(kwargs, #opt)); \
        PyErr_Clear(); \
        if (val) { \
          auto maybe_bool = ::mx::from_python<bool>(val); \
          if (!maybe_bool) { \
            PyErrorStreamer(PyExc_TypeError) \
                << "Value to '" #opt "' argument of 'QualifiedNameRenderOptions.__init__' must be convertible to bool."; \
            return -1; \
          } \
          obj->data->opt = maybe_bool.value(); \
        } \
      }

    FOR_EACH_OPTIONS(GET_SET_OPTION)

#undef FOR_EACH_OPTIONS
#undef GET_SET_OPTION

    return 0;
  },
  .tp_alloc = PyType_GenericAlloc,
  .tp_new = PyType_GenericNew,
};

static PyTypeObject *gType = nullptr;

#pragma GCC diagnostic pop
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <> std::optional<T> PythonBinding<T>::from_python(
    BorrowedPyObject *obj) noexcept {

  if (!obj || Py_TYPE(obj) != gType) {
    return std::nullopt;
  }

  return *(reinterpret_cast<O *>(obj)->data);
}

template <>
::mx::SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
  if (auto obj = reinterpret_cast<O *>(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    if (0 != PyType_Ready(&gTypeDef)) {
      return false;
    }
    gType = &gTypeDef;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "QualifiedNameRenderOptions", tp_obj)) {
    return false;
  }

  return true;
}

}  // namespace mx
