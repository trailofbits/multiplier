# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

from argparse import ArgumentParser
import collections
import hashlib
import os
from pypasta import *
from lift import SchemaLifter, find_tags_in_namespace
from schema import *
from typing import DefaultDict, Dict, Iterable, List, Set, Tuple, Type
import sys

MX_BIN_BOOSTRAP_DIR = os.path.dirname(os.path.abspath(__file__))
MX_BIN_DIR = os.path.dirname(MX_BIN_BOOSTRAP_DIR)
MX_DIR = os.path.dirname(MX_BIN_DIR)
MX_INCLUDE_DIR = os.path.join(MX_DIR, "include")
MX_BINDINGS_DIR = os.path.join(MX_DIR, "bindings")
MX_BINDINGS_PYTHON_DIR = os.path.join(MX_BINDINGS_DIR, "Python")

TYPES_CPP = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "Types.h"

namespace mx {{

// Size is defined in the auto-generated `Types.cpp` file.
PyTypeObject gTypes[{}] = {{}};

}}  // namespace mx
"""


FORWARD_H_PREFIX = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#pragma once

#include <cstdint>

namespace mx {
"""


FORWARD_DECL_CLASS = "{} {};\n"


FORWARD_DECL_ENUM = "enum {enum_scope}{enum_name} : {stdint_type_name};\n"


FORWARD_H_SUFFIX = "}  // namespace mx\n"


STUB_PREFIX = """#
# Copyright (c) 2023-present, Trail of Bits, Inc.
# All rights reserved.
#
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

# Auto-generated file; do not modify!

from abc import ABC
from enum import IntEnum
from typing import Generator, Iterable, Mapping, Optional, overload, Sequence, Tuple
import pathlib
"""


STUB_IMPORT = "import {}\n"


ENTITY_STUB = """

DeclId = int
StmtId = int
TypeId = int
MacroId = int
DesignatorId = int
CXXBaseSpecifierId = int
TemplateArgumentId = int
TemplateParameterListId = int
FileTokenId = int
MacroTokenId = int
ParsedTokenId = int
TypeTokenId = int

class Entity(object, ABC):
  id: int

"""


ENUM_STUB_HEADER = """
class {}(IntEnum):
"""

ENUM_STUB_ITEM = "  {} = {}\n"


CLASS_STUB_HEADER = """
class {}({}{}{}):
"""


CLASS_PROPERTY_STUB = "  {}: {}\n"


CLASS_OVERLOAD_STUB = "  @overload\n"


CLASS_STATIC_STUB = "  @staticmethod\n"


CLASS_METHOD_STUB = """
{}{}  def {}({}) -> {}:
    ...
"""


BOOL_STUB = """
  def __bool__(self) -> bool:
    ...
"""


ITER_STUB = """
  def __iter__(self) -> Iterable[{}]:
    ...
"""


SEQUENCE_STUB = """
  def __getitem__(self, index: int) -> {}:
    ...
"""


CLASS_STUB_FOOTER = "  pass\n"


MODULE_CPP_PREFIX = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <cstdint>

#include "Binding.h"
#include "Forward.h"

namespace mx {

class FileLocationCache;
class ProxyTokenTreeVisitor;
class UserToken;

namespace {

using LoaderFunc = bool (BorrowedPyObject *);

static PyMethodDef gEmptyMethods[] = {
  {}   // Sentinel.
};
"""


BEGIN_NAMESPACE = "namespace {} {{\n"


END_NAMESPACE = "}}  // namespace {}\n"


MODULE_CPP_TYPE_ROW = "  PythonBinding<{}{}>::load,\n"


BEGIN_MODULE_CPP_DEF = """
// multiplier{dot_name}
static PyModuleDef g{upper_name}Module = {{
  .m_name = "{lower_name}",
  .m_doc = PyDoc_STR("{py_doc}"),
  .m_size = 0,
  .m_methods = gEmptyMethods,
  .m_slots = {{}},
  .m_traverse = {{}},
  .m_clear = {{}},
  .m_free = {{}},
}};

static LoaderFunc * const g{upper_name}Loaders[] = {{
"""


END_MODULE_CPP_DEF = "};\n"


MODULE_CPP_MIDDLE = """
}  // namespace
}  // namespace mx

PyMODINIT_FUNC PyInit_multiplier(void) {
  PyObject * const dummym = nullptr;
"""


MODULE_CPP_LOADER_LOOP = """
  auto {lower_name}m = PyModule_Create(&mx::g{upper_name}Module);
  if (!{lower_name}m) {{
    return nullptr;
  }}
{load_entity}
  for (auto loader : mx::g{upper_name}Loaders) {{
    if (!loader({lower_name}m)) {{
      Py_DECREF(m);
      return nullptr;
    }}
  }}

  if ({parent_name}m) {{
    if (0 != PyModule_AddObjectRef({parent_name}m, "{lower_name}", {lower_name}m)) {{
      Py_DECREF({lower_name}m);
      Py_DECREF(m);
      return nullptr;
    }}
  }}
"""


MODULE_CPP_LOAD_VARIANT_ENTITY = """
  // Fake injected base class for `Decl`, `Stmt`, etc.
  if (!mx::PythonBinding<mx::VariantEntity>::load(m)) {
    Py_DECREF(m);
    return nullptr;
  }
"""


MODULE_CPP_SUFFIX = """
  // Doesn't have any methods, so no schema is made for it. We manually inject
  // this so that we can handle `Token::location`.
  if (!mx::PythonBinding<mx::FileLocationCache>::load(frontendm)) {
    Py_DECREF(m);
    return nullptr;
  }

  // Doesn't have any methods, so no schema is made for it. We manually inject
  // this so that we can handle `TokenRange::create`.
  if (!mx::PythonBinding<mx::UserToken>::load(frontendm)) {
    Py_DECREF(m);
    return nullptr;
  }

  // Has virtual methods that we need to manually trampoline.
  if (!mx::PythonBinding<mx::ProxyTokenTreeVisitor>::load(frontendm)) {
    Py_DECREF(m);
    return nullptr;
  }

  return m;
}
"""


CLASS_HEADER = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <{}>

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

"""


ENUM_HEADER = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <{}>
#include <multiplier/Iterator.h>

#include "Binding.h"
#include "Error.h"
#include "Types.h"

namespace mx {{
namespace {{
using T = {}{};
}}  // namespace
"""


ENUM_FOOTER = """
}  // namespace mx
"""


DISABLE_DIAGNOSTICS = """
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
"""


ENABLE_DIAGNOSTICS = "#pragma GCC diagnostic pop\n"


BEGIN_MX_NAMESPACE = "namespace mx {\n"
END_MX_NAMESPACE = "}  // namespace mx\n"


METHOD_LIST_PREFIX = """
namespace {
static PyMethodDef gMethods[] = {
"""


METHOD_LIST_SUFFIX = """  {}  // Sentinel.
};
}  // namespace
"""


METHOD_SPEC_PREFIX = """  {{
    "{}",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {{
          T *obj = T_cast(self);
          (void) args;
"""


STATIC_METHOD_SPEC_PREFIX = """  {{
    "{}",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {{
          (void) args;
"""


METHOD_SPEC_CHECK_ARGCOUNT_BEGIN = "          while (num_args == {num_args}) {{\n"


METHOD_SPEC_GET_ARG = """            auto arg_{arg_num} = ::mx::from_python<{arg_type}>(args[{arg_num}]);
            if (!arg_{arg_num}.has_value()) {{
              break;
            }}
"""


METHOD_SPEC_CALL_ARG = "arg_{}.value()"
METHOD_SPEC_CALL_VALUE_ARG = "std::move(arg_{}.value())"


METHOD_SPEC_CALL = """
            return ::mx::to_python({this}{method_name}({args}));
"""


METHOD_SPEC_CHECK_ARGCOUNT_END = "          }\n"


METHOD_SPEC_STATIC_FLAG = " | METH_STATIC"


METHOD_SPEC_SUFFIX = """
          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to '{py_method_name}'";
          return nullptr;
        }}),
    METH_FASTCALL{extra_method_flags},
    PyDoc_STR("Wrapper for {cxx_namespace}{cxx_class_name}::{cxx_method_name}"),
  }},
"""


PROPERTY_LIST_PREFIX = """
namespace {
static PyGetSetDef gProperties[] = {
"""


PROPERTY_SPEC = """  {{
    "{py_method_name}",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {{
          return ::mx::to_python(T_cast(self)->{cxx_method_name}());
        }}),
    nullptr,
    PyDoc_STR("Wrapper for {cxx_namespace}{cxx_class_name}::{cxx_method_name}"),
    nullptr,
  }},
"""


PROPERTY_LIST_SUFFIX = """  {}  // Sentinel.
};
}  // namespace
"""


CLASS_TYPEDEF = """namespace {{
using T = {}{};

struct O final : public ::PyObject {{

  // When initialized, points to `backing_storage`.
  T *data{{nullptr}};

  // Aligned storage for `T`. Pointed to by `data`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
}};

inline static O *O_cast(void *obj) noexcept {{
  return reinterpret_cast<O *>(obj);
}}

inline static const O *O_cast(const void *obj) noexcept {{
  return reinterpret_cast<const O *>(obj);
}}

inline static T *T_cast(void *obj) noexcept {{
  return O_cast(obj)->data;
}}

inline static const T *T_cast(const void *obj) noexcept {{
  return O_cast(obj)->data;
}}

}}  // namespace
"""


IR_TYPE_HASH = """[] (BorrowedPyObject *obj) -> Py_hash_t {{
    return static_cast<Py_hash_t>(reinterpret_cast<uintptr_t>(T_cast(obj)->underlying_{}()));
  }}"""


TYPE_HASH = """[] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(EntityId(T_cast(obj)->id()).Pack());
  }"""


RICH_COMPARE = """[] (BorrowedPyObject *a_obj, BorrowedPyObject *b_obj, int op) -> SharedPyObject * {
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
  }"""


NUMBER_METHODS = """
namespace {

static PyNumberMethods gNumberMethods = {
  .nb_bool = [] (BorrowedPyObject *obj) -> int {
    return !!*T_cast(obj);
  }
};

}  // namespace
"""


SEQUENCE_SIZE = """[] (BorrowedPyObject *obj) -> Py_ssize_t {{
        return static_cast<Py_ssize_t>(T_cast(obj)->{len_func}());
      }}"""


SEQUENCE_ITEM = """[] (BorrowedPyObject *obj, Py_ssize_t index) -> SharedPyObject * {{
        auto len = static_cast<Py_ssize_t>(T_cast(obj)->{len_func}());
        if (index >= len) {{
          PyErrorStreamer(PyExc_IndexError)
              << "Invalid index '" << index << "'";
          return nullptr;
        }}
        return ::mx::to_python(T_cast(obj)->{item_func}(static_cast<unsigned>(index)));
      }}"""


SEQUENCE_METHODS = """
namespace {{

static PySequenceMethods gSequenceMethods = {{
  .sq_length = {py_seq_length},
  .sq_item = {py_seq_item},
}};

}}  // namespace
"""


PYTHON_BINDING_TYPE = """
namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}
"""


PYTHON_BINDING_FROM_PYTHON = """
template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {{
  if (!obj) {{
    return std::nullopt;
  }}

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[{type_offset}]) || tp >= &(gTypes[{type_offset_upper_bound}])) {{
    return std::nullopt;
  }}

  return *T_cast(obj);
}}
"""


PYTHON_BINDING_TO_PYTHON_STATIC = """
template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  auto ret = gType->tp_alloc(gType, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}
"""

PYTHON_BINDING_TO_PYTHON_DYNAMIC_BEGIN = """
template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      assert(false);
      tp = gType;
      break;
"""

PYTHON_BINDING_TO_PYTHON_DYNAMIC_CASE = """
    case {cxx_namespace}{cxx_class_name}::static_kind():
      tp = &(gTypes[{type_offset}]);
      break;
"""


PYTHON_BINDING_TO_PYTHON_DYNAMIC_END = """
  }
  auto ret = tp->tp_alloc(tp, 0);
  if (auto obj = O_cast(ret)) {
    obj->data = new (obj->backing_storage) T(std::move(val));
  }
  return ret;
}
"""


LOAD_CLASS = """
namespace {{
static PyTypeObject *InitType(void) noexcept;
}}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {{
  if (!gType) {{
    gType = InitType();
    if (!gType) {{
      return false;
    }}
  }}

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, "{py_class_name}", tp_obj)) {{
    return false;
  }}

  return true;
}}
"""


INIT_TYPE = """
namespace {{

PyTypeObject *InitType(void) noexcept {{
  PyTypeObject * const tp = &(gTypes[{type_offset}]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {{
    if (auto *data = T_cast(obj)) {{
      data->~T();
    }}
    PyObject_Free(obj);
  }};
  tp->tp_name = "{py_namespace_path}{py_class_name}";
  tp->tp_flags = Py_TPFLAGS_DEFAULT{py_flag_instantiation}{py_flag_sequencing};
  tp->tp_doc = PyDoc_STR("Wrapper for {cxx_namespace}::{cxx_class_name}");
  tp->tp_as_number = {py_number};
  tp->tp_as_sequence = {py_sequence};
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = {py_hash};
  tp->tp_richcompare = {py_rich_compare};
  tp->tp_iter = {py_iter};
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = {py_base_class};
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {{
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {{
      PyErrorStreamer(PyExc_TypeError)
          << "'{py_class_name}.__init__' does not take any keyword arguments";
      return -1;
    }}

    if (!args || !PySequence_Check(args)) {{
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to '{py_class_name}.__init__'";
      return -1;
    }}

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    {py_constructor}
  }};
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = {py_new};

  if (0 != PyType_Ready(tp)) {{
    return nullptr;
  }}

  return tp;
}}

}}  // namespace

"""


ITER_FUNC = """[] (BorrowedPyObject *self) {{
    auto generator_func = [] (BorrowedPyObject *self_) {{
      T *obj = T_cast(self_);
      for (auto val : *(obj->data)) {{
        co_yield val;
      }}
      Py_DECREF(self);
    }};

    Py_INCREF(self);
    return ::mx::to_python<gap::generator<{cxx_value_type}>(generator_func(self));
  }}"""


NOT_CONSTRUCTIBLE = """
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class '{py_class_name}' cannot be directly instantiated";
    return -1;
"""


INIT_SPEC_CHECK_ARGCOUNT_BEGIN = """
    while (num_args == {num_args}) {{"""


INIT_SPEC_CHECK_ARGCOUNT_END = """    }
"""


INIT_SPEC_GET_ARG = """
      auto obj_{arg_num} = PySequence_GetItem(args, {arg_num});
      PyErr_Clear();
      if (!obj_{arg_num}) {{
        break;
      }}
      auto arg_{arg_num} = ::mx::from_python<{arg_type}>(obj_{arg_num});
      Py_DECREF(obj_{arg_num});
      if (!arg_{arg_num}.has_value()) {{
        break;
      }}
"""


INIT_SPEC_CALL = """
      obj->data = new (obj->backing_storage) {cxx_class_name}({args});
      return 0;
"""


INIT_SPEC_ERROR = """
    PyErrorStreamer(PyExc_TypeError)
        << "Invalid arguments to '{py_class_name}.__init__'";
    return -1;
"""


# From: https://stackoverflow.com/questions/68131786/how-to-create-an-enum-object-in-python-c-api
ENUM_DEF = """
namespace {
static PyTypeObject *gType = nullptr;
}  // namespace

template <>
PyTypeObject *PythonBinding<T>::type(void) noexcept {
  return gType;
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  return PyObject_GetAttrString(reinterpret_cast<BorrowedPyObject *>(gType),
                                EnumeratorName(val));
}

template <>
std::optional<T> PythonBinding<T>::from_python(BorrowedPyObject *obj) noexcept {
  if (!obj) {
    return std::nullopt;
  }

  if (Py_TYPE(obj) != gType) {
    return std::nullopt;
  }

  auto long_val = PyObject_GetAttrString(obj, "value");
  if (!long_val) {
    PyErr_Clear();
    return std::nullopt;
  }

  if (!PyLong_Check(long_val)) {
    Py_DECREF(long_val);
    return std::nullopt;
  }

  int did_overflow = 0;
  const auto ret = static_cast<T>(
      PyLong_AsLongLongAndOverflow(obj, &did_overflow));
  if (did_overflow) {
    Py_DECREF(long_val);
    return std::nullopt;
  }

  return ret;
}

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {
  const char * const enum_name = EnumerationName(T{});
  bool created = false;

  if (!gType) {
    auto enum_module = PyImport_ImportModule("enum");
    if (!enum_module) {
      return false;
    }

    auto int_enum = PyObject_GetAttrString(enum_module, "IntEnum");
    Py_DECREF(enum_module);
    if (!int_enum) {
      return false;
    }

    auto enum_meta = PyObject_Type(int_enum);
    auto prepare = PyObject_GetAttrString(enum_meta, "__prepare__");
    if (!prepare) {
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Get the `enum._EnumDict` for what we're making.
    auto ns_dict = PyObject_CallFunction(prepare, "s(N)", enum_name, int_enum);
    Py_DECREF(prepare);
    if (!ns_dict) {
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Assign each enumerator.
    for (T val : EnumerationRange<T>()) {
      auto iname = PyUnicode_FromString(EnumeratorName(val));
      auto ival = PyLong_FromUnsignedLongLong(static_cast<uint64_t>(val));
      if (ival) {
        if (!PyObject_SetItem(ns_dict, iname, ival)) {
          continue;
        }
        Py_DECREF(ival);
      }

      Py_DECREF(ns_dict);
      Py_DECREF(enum_meta);
      Py_DECREF(int_enum);
      return false;
    }

    // Create the type.
    auto enum_class = PyObject_CallFunction(
        enum_meta, "s(N)N", enum_name, int_enum, ns_dict);
    Py_DECREF(ns_dict);
    Py_DECREF(enum_meta);
    Py_DECREF(int_enum);

    if (!enum_class) {
      return false;
    }

    if (!PyType_Check(enum_class)) {
      Py_DECREF(enum_class);

      PyErrorStreamer(PyExc_ImportError)
          << "Created enum class for enumerator '" << enum_name
          << "' is not a python type";
      return false;
    }

    gType = reinterpret_cast<PyTypeObject *>(enum_class);
    created = true;
  }

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(gType);
  if (0 != PyModule_AddObjectRef(module, enum_name, tp_obj)) {
    return false;
  }

  if (created) {
    Py_DECREF(tp_obj);
  }

  return true;
}
"""


BINDING_CPP_HEADER = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include "../Binding.h"

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>
#include <multiplier/Re2.h>
#include <multiplier/Reference.h>

namespace mx {

// This one is manually added; needed by `TokenTreeVisitor` which is manually
// wrapped.
template MX_EXPORT SharedPyObject *mx::to_python<std::vector<mx::Fragment>>(std::vector<mx::Fragment>) noexcept;

// The rest are auto-generated...
"""


TEMPLATE_SPEC_FROM_PYTHON = """
template MX_EXPORT std::optional<FromPythonReturnType<{0}>::Type>
from_python<{0}>(BorrowedPyObject *obj) noexcept;
"""


TEMPLATE_SPEC_TO_PYTHON = """
template MX_EXPORT SharedPyObject *to_python<{0}>({0}) noexcept;
"""


BINDING_CPP_FOOTER = """}  // namespace mx
"""


class UserTokenSchema(Schema):
  def __init__(self, *args):
    super().__init__()

  def __str__(self) -> str:
    return f"UserToken"

  @property
  def python_value_name(self):
    return "multiplier.frontend.UserToken"

  @property
  def cxx_value_name(self):
    return "UserToken"


class FileLocationCacheSchema(Schema):
  def __init__(self, *args):
    super().__init__()

  def __str__(self) -> str:
    return f"FileLocationCache"

  @property
  def python_value_name(self):
    return "multiplier.frontend.FileLocationCache"

  @property
  def cxx_value_name(self):
    return "FileLocationCache"


class TokenTreeVisitorSchema(Schema):
  def __init__(self, *args):
    super().__init__()

  def __str__(self) -> str:
    return f"TokenTreeVisitor"

  @property
  def python_value_name(self):
    return "multiplier.frontend.TokenTreeVisitor"

  @property
  def cxx_value_name(self):
    return "ProxyTokenTreeVisitor"


class EntityIdSchema(Schema):
  def __init__(self):
    super().__init__()

  def __str__(self) -> str:
    return f"EntityId"

  @property
  def python_value_name(self):
    return "int"

  @property
  def cxx_value_name(self):
    return "EntityId"


class RawEntityIdSchema(EntityIdSchema):
  def __init__(self):
    super().__init__()

  def __str__(self) -> str:
    return f"RawEntityId"

  @property
  def python_value_name(self):
    return "int"

  @property
  def cxx_value_name(self):
    return "RawEntityId"


class SpecificEntityIdSchema(EntityIdSchema):
  specific_type: Schema

  def __init__(self, specific_type: Schema):
    super().__init__()
    self.specific_type = specific_type

  def __str__(self) -> str:
    return f"SpecificEntityId[{self.specific_type}]"

  @property
  def python_value_name(self):
    return self.specific_type.python_value_name

  @property
  def cxx_value_name(self):
    return "SpecificEntityId<{}>".format(self.specific_type.cxx_name)


def make_schema_class_instance(cxx_name, py_name, base):
  return make_schema_class(cxx_name, py_name, base)()


def make_schema_class(cxx_name, py_name, base) -> type[Schema]:
  class NamedEntitySchema(base):
    def __init__(self, *args):
      super().__init__(*args)

    def __str__(self):
      return cxx_name

    @property
    def python_value_name(self):
      return f"multiplier.{py_name}"

    @property
    def cxx_value_name(self):
      return f"{cxx_name}"

    def __reduce__(self):
      return (make_schema_class_instance, (cxx_name, py_name, base))

  NamedEntitySchema.__name__ = cxx_name + "Schema"
  return NamedEntitySchema


class Renamer:
  def rename_class(self, class_schema:ClassSchema) -> str:
    return class_schema.name

  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return method_schema.name


ARGUMENT_RENAMES = {
  "from": "from_",
}

class BasicRenamer(Renamer):
  METHOD_RENAMES = {
    "from": "FROM",
    "in": "IN",
    "as": "AS",
  }

  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return self.METHOD_RENAMES.get(method_schema.name, method_schema.name)


FROM_EXPORTS: Set[Schema] = set()
TO_EXPORTS: Set[Schema] = set()


def _wrap_method_impl(class_schema: ClassSchema, schema: MethodSchema,
                      is_static: bool, is_overload: bool, out: List[str],
                      stubs_out: List[str]):
  global FROM_EXPORTS, TO_EXPORTS

  if isinstance(schema.return_type, UnknownSchema):
    return

  TO_EXPORTS.add(schema.return_type)
  num_args = len(schema.parameters)
  out.append(METHOD_SPEC_CHECK_ARGCOUNT_BEGIN.format(num_args=num_args))

  py_args = []
  cxx_args = []

  if not is_static:
    py_args.append("self")

  for i, arg in enumerate(schema.parameters):
    FROM_EXPORTS.add(arg.element_type)
    out.append(METHOD_SPEC_GET_ARG.format(
        arg_num=i,
        arg_type=arg.element_type.cxx_value_name))
    arg_name = ARGUMENT_RENAMES.get(arg.name, arg.name) or f"arg_{i}"
    py_args.append(f"{arg_name}: {arg.element_type.python_value_name}")

    if not isinstance(arg.element_type, ReferenceSchema):
      cxx_args.append(METHOD_SPEC_CALL_VALUE_ARG.format(i))
    else:
      cxx_args.append(METHOD_SPEC_CALL_ARG.format(i))

  out.append(METHOD_SPEC_CALL.format(
      this=is_static and "T::" or "obj->",
      method_name=schema.name,
      args=", ".join(cxx_args)))

  out.append(METHOD_SPEC_CHECK_ARGCOUNT_END)

  stubs_out.append(CLASS_METHOD_STUB.format(
      is_overload and CLASS_OVERLOAD_STUB or "",
      is_static and CLASS_STATIC_STUB or "",
      renamer.rename_method(class_schema, schema),
      ", ".join(py_args),
      schema.return_type.python_value_name))


def _wrap_constructor_impl(class_schema: ClassSchema, schema: MethodSchema,
                           out: List[str]):
  global FROM_EXPORTS

  num_args = len(schema.parameters)
  out.append(INIT_SPEC_CHECK_ARGCOUNT_BEGIN.format(num_args=num_args))

  cxx_args = []

  for i, arg in enumerate(schema.parameters):
    FROM_EXPORTS.add(arg.element_type)
    out.append(INIT_SPEC_GET_ARG.format(
        arg_num=i,
        arg_type=arg.element_type.cxx_value_name))

    if not isinstance(arg.element_type, ReferenceSchema):
      cxx_args.append(METHOD_SPEC_CALL_VALUE_ARG.format(i))
    else:
      cxx_args.append(METHOD_SPEC_CALL_ARG.format(i))

  out.append(INIT_SPEC_CALL.format(
      cxx_class_name=class_schema.name,
      args=", ".join(cxx_args)))

  out.append(INIT_SPEC_CHECK_ARGCOUNT_END)


def _wrap_method(class_schema: ClassSchema, schema: NamedSchema,
                 renamer: Renamer, is_static: bool, out: List[str],
                 stubs_out: List[str]):
  """Create Python bindings for a method. This skips over methods that have no
  arguments and can be implemented with Python properties."""
  assert isinstance(schema, (MethodSchema, OverloadSetSchema))

  rel_ns = _relative_namespace(class_schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
  py_method_name = renamer.rename_method(class_schema, schema)

  if is_static:
    out.append(STATIC_METHOD_SPEC_PREFIX.format(py_method_name))
  else:
    out.append(METHOD_SPEC_PREFIX.format(py_method_name))

  if isinstance(schema, OverloadSetSchema):
    for method in schema.overloads:
      _wrap_method_impl(class_schema, method, is_static, True, out, stubs_out)
  elif isinstance(schema, MethodSchema):
    _wrap_method_impl(class_schema, schema, is_static, False, out, stubs_out)
  else:
    assert False

  out.append(
      METHOD_SPEC_SUFFIX.format(
          cxx_namespace=cxx_namespace,
          cxx_class_name=class_schema.name,
          cxx_method_name=schema.name,
          py_method_name=py_method_name,
          extra_method_flags=(is_static and METHOD_SPEC_STATIC_FLAG or "")))


def _wrap_property(class_schema: ClassSchema, schema: NamedSchema,
                   renamer: Renamer, out: List[str]):
  """Creates Python bindings for an instance method with no arguments. These are
  implemented as Python properties."""
  global TO_EXPORTS

  TO_EXPORTS.add(schema.return_type)

  rel_ns = _relative_namespace(class_schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"

  out.append(PROPERTY_SPEC.format(
      py_method_name=renamer.rename_method(class_schema, schema),
      cxx_class_name=class_schema.name,
      cxx_method_name=schema.name,
      cxx_namespace=cxx_namespace))


def _relative_namespace(schema: ClassSchema | EnumSchema) -> str:
  return schema.namespaces and "::".join(schema.namespaces[1:]) or ""


def _relative_dir(schema: ClassSchema | EnumSchema) -> str:
  path = list(schema.location.split("/"))
  while len(path):
    if path.pop(0) == "multiplier":
      break

  assert len(path)
  assert path[-1].endswith(".h")
  path.pop()
  return "/".join(path)


def _get_method(schema: ClassSchema, method_name: str) -> Optional[MethodSchema | OverloadSetSchema]:
  if method_name in schema.methods:
    return schema.methods[method_name]

  for base in schema.bases:
    method_schema = _get_method(base, method_name)
    if method_schema:
      return method_schema

  return None


def _is_id_method(schema: Optional[MethodSchema | OverloadSetSchema]) -> bool:
  return isinstance(schema, MethodSchema) and schema.name == "id" and \
         isinstance(schema.return_type, EntityIdSchema)


def _has_id_method(schema: ClassSchema) -> bool:
  return _is_id_method(_get_method(schema, "id"))


def _dynamic_case(schema: ClassSchema,
                  offsets: Dict[ClassSchema, Tuple[int, int]],
                  children: Dict[ClassSchema, List[ClassSchema]],
                  out: List[str]):

  if "static_kind" in schema.static_methods:
    type_offsets = offsets[schema]
    rel_ns = _relative_namespace(schema)
    cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
    cxx_class_name = schema.name
    out.append(PYTHON_BINDING_TO_PYTHON_DYNAMIC_CASE.format(
        cxx_namespace=cxx_namespace,
        cxx_class_name=cxx_class_name,
        type_offset=type_offsets[0]))

  for child_schema in children[schema]:
    _dynamic_case(child_schema, offsets, children, out)


def _strip_optional_const_ref(schema: Schema) -> Schema:
  if isinstance(schema, (StdOptionalSchema, ConstReferenceSchema)):
    return _strip_optional_const_ref(schema.element_type)
  else:
    return schema


_IR_BASE_CLASSES = ("Operation", "Region", "Block", "Type",
                    "Attribute", "Value", "Operand")


def _is_mlir_base_class(schema: ClassSchema) -> bool:
  if schema.name not in _IR_BASE_CLASSES:
    return False

  return schema.namespaces and len(schema.namespaces) and \
         schema.namespaces[-1] == 'ir'


def wrap_class(schema: ClassSchema,
               offsets: Dict[ClassSchema, Tuple[int, int]],
               children: Dict[ClassSchema, List[ClassSchema]],
               renamer: Renamer, stubs_out: List[str]):
  """Create Python bindings for a class schema."""
  global FROM_EXPORTS, TO_EXPORTS

  FROM_EXPORTS.add(schema)
  TO_EXPORTS.add(schema)

  type_offsets = offsets[schema]

  out: List[str] = []
  out.append(CLASS_HEADER.format(schema.location))

  rel_ns = _relative_namespace(schema)
  rel_dir = _relative_dir(schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
  cxx_class_name = schema.name
  py_class_name = renamer.rename_class(schema)

  py_namespace_path = rel_dir and f"multiplier.{rel_dir.lower().replace('/', '.')}." or "multiplier."

  type_hash = "PyObject_HashNotImplemented"
  type_compare = "nullptr"
  base_class = "nullptr"
  py_base_class = "object"

  is_entity_type = _has_id_method(schema)
  
  if schema.bases:
    assert len(schema.bases) == 1
    base_schema = schema.bases[0]
    assert base_schema in offsets
    base_offsets = offsets[base_schema]
    base_class = "&(gTypes[{}])".format(base_offsets[0])
    type_hash = "gTypes[{}].tp_hash".format(base_offsets[0])
    type_compare = "gTypes[{}].tp_richcompare".format(base_offsets[0])
    py_base_class = base_schema.python_value_name.strip("'")

  # In the Python API, we give all of the entities a common base class.
  elif is_entity_type:
    base_class = "PythonBinding<VariantEntity>::type()";
    py_base_class = "multiplier.Entity"

  has_unique_generated_type = schema.generated_type and \
     (not schema.indexed_type or 
      (_strip_optional_const_ref(schema.indexed_type) != \
       _strip_optional_const_ref(schema.generated_type)))

  sequence_stub = ""
  iterable_stub = ""

  if schema.indexed_type:
    sequence_stub = ", Sequence[{}]".format(schema.indexed_type)

  if schema.generated_type:
    iterable_stub = ", Iterable[{}]".format(schema.generated_type)

  stubs_out.append(CLASS_STUB_HEADER.format(
      py_class_name, py_base_class, sequence_stub, iterable_stub))

  old_stubs_len = len(stubs_out)

  # Figure out if we can override `__hash__` using the `id` method.
  if "id" in schema.methods:
    id_method = schema.methods["id"]
    if _is_id_method(id_method):
      type_hash = TYPE_HASH

  elif _is_mlir_base_class(schema):
    type_hash = IR_TYPE_HASH.format(schema.name.lower())

  assert schema.location is not None
  out.append(DISABLE_DIAGNOSTICS)
  out.append(CLASS_TYPEDEF.format(cxx_namespace, cxx_class_name))
  out.append(BEGIN_MX_NAMESPACE)
  out.append(PYTHON_BINDING_TYPE)
  out.append(PYTHON_BINDING_FROM_PYTHON.format(
      type_offset=type_offsets[0],
      type_offset_upper_bound=type_offsets[1]))
  
  # Figure out if this class can use kind-based dispatch.
  kind_method = _get_method(schema, "kind")
  if isinstance(kind_method, MethodSchema) and \
     isinstance(kind_method.return_type, EnumSchema) and \
     schema.name != "Token":
    out.append(PYTHON_BINDING_TO_PYTHON_DYNAMIC_BEGIN)
    _dynamic_case(schema, offsets, children, out)
    out.append(PYTHON_BINDING_TO_PYTHON_DYNAMIC_END)
  else:
    out.append(PYTHON_BINDING_TO_PYTHON_STATIC)

  out.append(LOAD_CLASS.format(
      py_class_name=py_class_name))

  # Add in the properties.
  out.append(PROPERTY_LIST_PREFIX)

  for method in schema.methods.values():
    if isinstance(method, OverloadSetSchema):
      method = method.overloads[0]

    if not isinstance(method, MethodSchema) or \
       not method.is_const or \
       0 < method.max_num_parameters:
       continue
    
    # Output the properties. Skip `id` if this is an entity.    
    if not is_entity_type or method.name != "id":
      stubs_out.append(CLASS_PROPERTY_STUB.format(
          renamer.rename_method(schema, method),
          method.return_type.python_value_name))

    _wrap_property(schema, method, renamer, out)
  
  out.append(PROPERTY_LIST_SUFFIX)

  # Add in the methods.
  out.append(METHOD_LIST_PREFIX)

  for method in schema.static_methods.values():
    _wrap_method(schema, method, renamer, True, out, stubs_out)

  for method in schema.methods.values():
    if not method.is_const:
      continue

    if isinstance(schema, OverloadSetSchema) or method.max_num_parameters:
      _wrap_method(schema, method, renamer, False, out, stubs_out)

  out.append(METHOD_LIST_SUFFIX)

  if schema.has_boolean_conversion:
    out.append(NUMBER_METHODS)
    stubs_out.append(BOOL_STUB)

  if schema.indexed_type:
    stubs_out.append(SEQUENCE_STUB.format(schema.indexed_type))

  if schema.generated_type:
    stubs_out.append(ITER_STUB.format(schema.indexed_type))

  if schema.indexed_type:
    size_name: Optional[str] = None
    for method_name in schema.methods:
      if method_name.lower() in ("len", "length", "size", "count"):
        assert size_name is None, "More than one size-like method"
        size_name = method_name
    assert size_name is not None

    out.append(SEQUENCE_METHODS.format(
        py_seq_length=SEQUENCE_SIZE.format(
            len_func=size_name),
        py_seq_item=SEQUENCE_ITEM.format(
            len_func=size_name,
            item_func="operator[]")))

  py_constructor = NOT_CONSTRUCTIBLE.format(py_class_name=py_class_name)
  constructors: List[MethodSchema] = _non_copy_constructors(schema)
  if len(constructors):
    constructor_out: List[str] = []
    for method in constructors:
      _wrap_constructor_impl(schema, method, constructor_out)

    constructor_out.append(INIT_SPEC_ERROR.format(py_class_name=py_class_name))
    py_constructor = "".join(constructor_out)

  py_iter = "nullptr"
  if has_unique_generated_type:
    py_iter = ITER_FUNC.format(schema.generated_type.cxx_value_name)

  out.append(INIT_TYPE.format(
      cxx_namespace=cxx_namespace,
      cxx_class_name=schema.name,
      py_namespace_path=py_namespace_path,
      py_class_name=py_class_name,
      py_constructor=py_constructor,
      py_new=len(constructors) == 0 and "nullptr" or "PyType_GenericNew",
      py_flag_instantiation=len(constructors) == 0 and " | Py_TPFLAGS_DISALLOW_INSTANTIATION" or "",
      py_flag_sequencing=schema.indexed_type and " | Py_TPFLAGS_SEQUENCE " or "",
      py_hash=type_hash,
      py_rich_compare=(
          schema.has_equivalence_relation and RICH_COMPARE or type_compare),
      py_base_class=base_class,
      py_number=schema.has_boolean_conversion and "&gNumberMethods" or "nullptr",
      py_sequence=schema.indexed_type and "&gSequenceMethods" or "nullptr",
      py_iter=py_iter,
      type_offset=type_offsets[0],
      type_offset_upper_bound=type_offsets[1]))

  out.append(ENABLE_DIAGNOSTICS)
  out.append(END_MX_NAMESPACE)

  if len(stubs_out) == old_stubs_len:
    stubs_out.append(CLASS_STUB_FOOTER)

  _save_output(schema, out)


def wrap_enum(schema: EnumSchema, renamer: Renamer, stubs_out: List[str]):
  """Wrap an enumeration and its enumerators."""
  global FROM_EXPORTS, TO_EXPORTS

  FROM_EXPORTS.add(schema)
  TO_EXPORTS.add(schema)

  rel_ns = _relative_namespace(schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
  cxx_enum_name = schema.name

  out: List[str] = []
  out.append(ENUM_HEADER.format(schema.location, cxx_namespace, cxx_enum_name))
  out.append(ENUM_DEF)
  out.append(ENUM_FOOTER)
  _save_output(schema, out)

  stubs_out.append(ENUM_STUB_HEADER.format(cxx_enum_name))
  for i, enumerator in enumerate(schema.enumerators):
    stubs_out.append(ENUM_STUB_ITEM.format(enumerator, i))


def _save_output_file(out_path: str, out: List[str]):
  os.makedirs(os.path.dirname(out_path), exist_ok=True)
  new_output = "".join(out).encode('utf-8')

  # Avoid overwriting the file if we won't change anything.
  if os.path.exists(out_path):
    with open(out_path, "r") as f:
      old_output = f.read().encode('utf-8')
      if hashlib.sha1(new_output).hexdigest() == hashlib.sha1(old_output).hexdigest():
        return

  with open(out_path, "w") as f:
    f.write("".join(out))


def _save_output(schema: ClassSchema | EnumSchema, out: List[str]):
  out_path = os.path.join(MX_BINDINGS_PYTHON_DIR, "Generated",
                        _relative_dir(schema),
                        schema.name + ".cpp")
  _save_output_file(out_path, out)


def _non_copy_constructors(schema: ClassSchema) -> List[MethodSchema]:
  constructors: List[MethodSchema] = []

  if isinstance(schema.constructor, OverloadSetSchema):
    constructors.extend(schema.constructor.overloads)

  elif isinstance(schema.constructor, MethodSchema):
    constructors.append(schema.constructor)

  non_copy_constructors: List[MethodSchema] = []
  for method in constructors:
    assert isinstance(method.return_type, UnknownSchema)

    if method.min_num_parameters == 0 or 1 < method.min_num_parameters:
      non_copy_constructors.append(method)
      continue

    only_param_type = method.parameters[0].element_type
    assert not isinstance(only_param_type, UnknownSchema)

    if isinstance(only_param_type, ConstReferenceSchema) and \
       only_param_type.element_type == schema:
      continue

    non_copy_constructors.append(method)

  return non_copy_constructors


def _fill_into(schema: ClassSchema, children: Dict[ClassSchema, List[ClassSchema]],
              offsets: Dict[ClassSchema, Tuple[int, int]], classes: List[ClassSchema]):
  begin_offset = len(classes)
  classes.append(schema)
  for derived_schema in children[schema]:
    _fill_into(derived_schema, children, offsets, classes)
  end_offset = len(classes)
  offsets[schema] = (begin_offset, end_offset)


def wrap(schemas: Iterable[Schema], renamer: Renamer):
  global FROM_EXPORTS, TO_EXPORTS

  work_list: List[ClassSchema] = []
  children: Dict[ClassSchema, List[ClassSchema]] = {}
  enums: List[EnumSchema] = []
  namespaces: DefaultDict[str, List[Schema]] = collections.defaultdict(list)
  directories: DefaultDict[str, List[Schema]] = collections.defaultdict(list)
  stubs: DefaultDict[str, List[str]] = collections.defaultdict(
      lambda: [STUB_PREFIX])

  stubs[""].append(ENTITY_STUB)

  # Collect all `EnumSchema`s and `ClassSchema`s, and keep track of root
  # classes (that have no base classes) in `work_list` and the list of children
  # of each class in `children` so that we can topologically sort the classes.
  for schema in schemas:
    rel_dir = _relative_dir(schema)

    namespaces[_relative_namespace(schema)].append(schema)
    directories[rel_dir].append(schema)

    if isinstance(schema, ClassSchema):
      if schema not in children:
        children[schema] = []

      for parent_schema in schema.bases:
        if parent_schema not in children:
          children[parent_schema] = []

        children[parent_schema].append(schema)

      if not len(schema.bases):
        work_list.append(schema)

    elif isinstance(schema, EnumSchema):
      enums.append(schema)

    else:
      assert False

  # Topologically sort all the classes.
  classes: List[ClassSchema] = []
  offsets: Dict[ClassSchema, Tuple[int, int]] = {}
  for schema in work_list:
    _fill_into(schema, children, offsets, classes)

  # Fill in `Types.cpp`. This defines the size of the `gTypes` array.
  _save_output_file(os.path.join(MX_BINDINGS_PYTHON_DIR, "Types.cpp"),
                    [TYPES_CPP.format(len(classes))])

  # Fill in `Forward.h`. This forward declares all the various classes and
  # enums.
  forward_out: List[str] = []
  forward_out.append(FORWARD_H_PREFIX)

  # Forward declare the classes/enums.
  for namespace, schemas in namespaces.items():
    if len(namespace):
      forward_out.append(BEGIN_NAMESPACE.format(namespace))
    for schema in schemas:
      if isinstance(schema, ClassSchema):
        forward_out.append(FORWARD_DECL_CLASS.format(schema.elaborator, schema.name))
      elif isinstance(schema, EnumSchema):
        assert schema.is_explicitly_typed
        enum_scope = schema.is_scoped and "class " or ""
        forward_out.append(FORWARD_DECL_ENUM.format(
            enum_scope=enum_scope,
            enum_name=schema.name,
            stdint_type_name=schema.base_type.cxx_value_name))
    if len(namespace):
      forward_out.append(END_NAMESPACE.format(namespace))

  forward_out.append(FORWARD_H_SUFFIX)
  _save_output_file(os.path.join(MX_BINDINGS_PYTHON_DIR, "Forward.h"),
                    forward_out)

  # Fill in `Module.cpp`. This defines the main module, and invokes all of the
  # class initializers.
  module_out: List[str] = []
  module_out.append(MODULE_CPP_PREFIX)

  sorted_directories = list(directories.keys())
  sorted_directories.sort(key=len)

  # Make everything import everything. This helps with stubs.
  for dir_name in sorted_directories:
    for other_dir_name in sorted_directories:
      stubs[dir_name].append(STUB_IMPORT.format(
          f"multiplier.{other_dir_name}".lower().replace("/", ".").strip(".")))

  # Define the modules, and make lists of the wrappers.
  for rel_dir in sorted_directories:
    doc = rel_dir and f"Wrapper of {rel_dir}" or "Multiplier source code auditing API"
    dot_name = rel_dir and "." + rel_dir.replace("/", ".").lower() or ""
    upper_name = rel_dir and rel_dir.split("/")[-1] or ""
    lower_name = upper_name.lower()

    module_out.append(BEGIN_MODULE_CPP_DEF.format(
        dot_name=dot_name,
        lower_name=lower_name,
        upper_name=upper_name,
        py_doc=doc))

    for schema in directories[rel_dir]:
      rel_ns = _relative_namespace(schema)
      cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
      module_out.append(MODULE_CPP_TYPE_ROW.format(cxx_namespace, schema.name))

    module_out.append(END_MODULE_CPP_DEF)

  module_out.append(MODULE_CPP_MIDDLE)
  load_entity = MODULE_CPP_LOAD_VARIANT_ENTITY

  # Define the modules, and make lists of the wrappers.
  for rel_dir in sorted_directories:
    rel_dir_parts = rel_dir.split("/")
    upper_name = rel_dir and rel_dir_parts[-1] or ""
    lower_name = upper_name.lower()

    if rel_dir == "":
      parent_name = "dummy"
    elif 1 == len(rel_dir_parts):
      parent_name = ""
    elif 1 < len(rel_dir_parts):
      parent_name = rel_dir_parts[-2].lower()

    module_out.append(MODULE_CPP_LOADER_LOOP.format(
        lower_name=lower_name,
        upper_name=upper_name,
        parent_name=parent_name,
        load_entity=load_entity))

    load_entity = ""

  module_out.append(MODULE_CPP_SUFFIX)
  _save_output_file(os.path.join(MX_BINDINGS_PYTHON_DIR, "Module.cpp"), module_out)

  for schema in enums:
    rel_dir = _relative_dir(schema)
    wrap_enum(schema, renamer, stubs[rel_dir])

  for schema in classes:
    rel_dir = _relative_dir(schema)
    wrap_class(schema, offsets, children, renamer, stubs[rel_dir])

  # Save the stubs.
  for rel_dir, stubs_out in stubs.items():
    init_path = os.path.join(MX_BINDINGS_PYTHON_DIR, "multiplier-stubs",
                             rel_dir.lower(), "__init__.py")
    _save_output_file(init_path, stubs_out)

  bindings_out = [BINDING_CPP_HEADER]
  seen_bindings = set()

  for schema in FROM_EXPORTS:
    line = TEMPLATE_SPEC_FROM_PYTHON.format(schema.cxx_value_name)
    if line not in seen_bindings:
      bindings_out.append(line)
      seen_bindings.add(line)
  
  for schema in TO_EXPORTS:
    line = TEMPLATE_SPEC_TO_PYTHON.format(schema.cxx_value_name)
    if line not in seen_bindings:
      bindings_out.append(line)
      seen_bindings.add(line)
  
  bindings_out.append(BINDING_CPP_FOOTER)
  _save_output_file(os.path.join(MX_BINDINGS_PYTHON_DIR, "Generated", "Bindings.cpp"), bindings_out)



ENTITY_KINDS: Tuple[str] = (
  "File",
  "Fragment",
  "Compilation",
  "Decl",
  "Stmt",
  "Attr",
  "Type",
  "Designator",
  "CXXBaseSpecifier",
  "TemplateArgument",
  "TemplateParameterList",
  "Macro",
  "Operation",
)

VariantEntitySchema = make_schema_class("VariantEntity", "Entity", Schema)
FileTokenIdSchema = make_schema_class("FileTokenId", "FileTokenId", EntityIdSchema)
MacroTokenIdSchema = make_schema_class("MacroTokenId", "MacroTokenId", EntityIdSchema)
ParsedTokenIdSchema = make_schema_class("ParsedTokenId", "ParsedTokenId", EntityIdSchema)
VariantIdSchema = make_schema_class("VariantId", "EntityId", EntityIdSchema)

for entity in ENTITY_KINDS:
  globals()[f"{entity}IdSchema"] = make_schema_class(f"{entity}Id", f"{entity}Id", EntityIdSchema)
  globals()[f"Packed{entity}IdSchema"] = make_schema_class(f"Packed{entity}Id", f"{entity}Id", EntityIdSchema)

def run_on_ast(ast: AST, ns_name: str):
  schemas: List[Schema] = []
  lifter: SchemaLifter = SchemaLifter()
  lifter.add_lifter("mx::FileLocationCache", FileLocationCacheSchema)
  lifter.add_lifter("mx::TokenTreeVisitor", TokenTreeVisitorSchema)
  lifter.add_lifter("mx::UserToken", UserTokenSchema)
  lifter.add_lifter("mx::VariantEntity", VariantEntitySchema)
  lifter.add_lifter("mx::EntityId", EntityIdSchema)
  lifter.add_lifter("mx::RawEntityId", RawEntityIdSchema)
  lifter.add_lifter("mx::FileTokenId", FileTokenIdSchema)
  lifter.add_lifter("mx::MacroTokenId", MacroTokenIdSchema)
  lifter.add_lifter("mx::ParsedTokenId", ParsedTokenIdSchema)
  lifter.add_lifter("mx::VariantId", VariantIdSchema)

  for entity in ENTITY_KINDS:
    lifter.add_lifter(f"mx::{entity}Id", globals()[f"{entity}IdSchema"])
    lifter.add_lifter(f"mx::Packed{entity}Id", globals()[f"Packed{entity}IdSchema"])

  lifter.add_parameterized_lifter("mx::SpecificEntityId", 1,
                                  SpecificEntityIdSchema)

  # Filter out all tag decls that aren't private `*Impl` classes, and also
  # only look at the definitions.
  for tag in find_tags_in_namespace(ast.translation_unit, ns_name):
    if not tag.name.endswith("Impl") and tag.is_this_declaration_a_definition:
      schema: Schema = lifter.lift_decl(tag)
      if isinstance(schema, NamedSchema):
        yield schema


if __name__ == "__main__":

  parser = ArgumentParser(description='Wrap the API surface area of the classes / enumerator within a namespace')
  parser.add_argument('--namespace', default="mx")
  parser.add_argument('--local_include_dir', default=MX_INCLUDE_DIR)
  parser.add_argument('--system_include_dir', required=True)
  parser.add_argument('--working_dir', default=MX_BIN_BOOSTRAP_DIR)
  parser.add_argument('--source_file', default="Python.cpp")
  parser.add_argument('--dump_only', default=False, action='store_true')
  parser.add_argument('--pickle_file', default='')
  args = parser.parse_args()
  fs: FileSystem = FileSystem.create_native()
  fm: FileManager = FileManager(fs)
  cxx: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.CXX)
  argv = ArgumentVector([
      str(cxx.executable_path),
      "-x", "c++",
      "-std=c++20",
      "-isystem", str(args.local_include_dir),
      "-isystem", str(args.system_include_dir),
      "-fsyntax-only",
      "-DGAP_ENABLE_COROUTINES",
      str(args.source_file)])

  renamer = BasicRenamer()
  cmd = CompileCommand.create_from_arguments(argv, args.working_dir)
  maybe_jobs = cxx.create_jobs_for_command(cmd)
  
  if isinstance(maybe_jobs, str):
    print(maybe_jobs)
    sys.exit(1)

  for job in maybe_jobs:
    maybe_ast = job.run()
    if isinstance(maybe_ast, str):
      print(maybe_ast)
      sys.exit(1)

    elif isinstance(maybe_ast, AST):
      schemas = run_on_ast(maybe_ast, args.namespace)
      if args.dump_only:
        pickle_schemas = []
        for schema in schemas:
          schema.dump("")
          print()
          if args.pickle_file:
            pickle_schemas.append(schema)

        if args.pickle_file:
          import pickle
          with open(args.pickle_file, "wb") as f:
            pickle.dump(pickle_schemas, f)

          with open(args.pickle_file, "rb") as f:
            pickle.load(f)

      else:
        wrap(schemas, renamer)
