// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <multiplier/Fragment.h>
#include <multiplier/Frontend/Compilation.h>
#include <multiplier/Frontend/File.h>
#include <multiplier/Frontend/Macro.h>
#include <multiplier/Frontend/Token.h>
#include <multiplier/IR/Operation.h>
#include <multiplier/AST/Attr.h>
#include <multiplier/AST/CXXBaseSpecifier.h>
#include <multiplier/AST/CXXCtorInitializer.h>
#include <multiplier/AST/Decl.h>
#include <multiplier/AST/Designator.h>
#include <multiplier/AST/Stmt.h>
#include <multiplier/AST/TemplateArgument.h>
#include <multiplier/AST/TemplateParameterList.h>
#include <multiplier/AST/Type.h>

#include "Error.h"

namespace mx {
namespace {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"

static PyGetSetDef gProperties[] = {
  {
    "id",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *, void * /* closure */) {
          return ::mx::to_python<RawEntityId>(kInvalidEntityId);
        }),
    nullptr,
    PyDoc_STR("Return the unique identifier of this entity in its corresponding index database"),
    nullptr,
  },
  {}  // Sentinel.
};

static PyTypeObject gTypeDef = {
  .tp_name = "multiplier.Entity",
  .tp_hash = PyObject_HashNotImplemented,
  .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION |
              Py_TPFLAGS_BASETYPE | Py_TPFLAGS_IMMUTABLETYPE,
  .tp_doc = PyDoc_STR("Abstract base classes for entities, e.g. Decl, Stmt, etc."),
  .tp_getset = gProperties,
  .tp_base = &PyBaseObject_Type,
  .tp_init = [] (BorrowedPyObject *, BorrowedPyObject *, BorrowedPyObject *) -> int {
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Entity' cannot be directly instantiated";
    return -1;
  },
  .tp_alloc = PyType_GenericAlloc,
  .tp_new = nullptr,
};

static PyTypeObject *gType = nullptr;

#pragma GCC diagnostic pop
}  // namespace

PyTypeObject *PythonBinding<VariantEntity>::type(void) noexcept {
  return gType;
}

std::optional<VariantEntity> PythonBinding<VariantEntity>::from_python(
    BorrowedPyObject *obj) noexcept {

  if (obj == Py_None) {
    return std::monostate{};
  }

#define MX_CONVERT_FROM_PYTHON(ns_path, type_name, lower_name, enum_name, category) \
    if (auto lower_name ## _ = ::mx::from_python<ns_path type_name>(obj)) { \
      ns_path type_name val = std::move(lower_name ## _.value()); \
      return val; \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON,
                            MX_CONVERT_FROM_PYTHON)
#undef MX_CONVERT_FROM_PYTHON

  return std::nullopt;
}

SharedPyObject *PythonBinding<VariantEntity>::to_python(
    VariantEntity val) noexcept {

#define MX_CONVERT_TO_PYTHON(ns_path, type_name, lower_name, enum_name, category) \
    if (const auto *lower_name ## _ = std::get_if<ns_path type_name>(&val)) { \
      return ::mx::to_python<ns_path type_name>(std::move(*lower_name ## _)); \
    }

MX_FOR_EACH_ENTITY_CATEGORY(MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON,
                            MX_CONVERT_TO_PYTHON)
#undef MX_CONVERT_TO_PYTHON
  
  Py_RETURN_NONE;
}

bool PythonBinding<VariantEntity>::load(BorrowedPyObject *module) noexcept {
  if (!gType) {
    if (0 != PyType_Ready(&gTypeDef)) {
      return false;
    }
    gType = &gTypeDef;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "Entity", tp_obj)) {
    return false;
  }

  return true;
}

}  // namespace mx