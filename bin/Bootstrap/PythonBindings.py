# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

import os
from pypasta import *
from lift import *
from schema import *
from typing import Dict, Iterable, List, Set, Tuple

MX_BIN_BOOSTRAP_DIR = os.path.dirname(__file__)
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


MODULE_CPP_PREFIX = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/Bindings/Python.h>

namespace mx {
"""


MODULE_CPP_FORWARD_DECL = "{} {};\n"


MODULE_CPP_MIDDLE = """
namespace {

using LoaderFunc = bool ()(BorrowedPyObject *);

static const LoaderFunc *gLoaders[] = {
"""


MODULE_CPP_TYPE_ROW = "  PyObject<{}::{}>::load,\n"


MODULE_CPP_SUFFIX = """};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc99-extensions"

static PyMethodDef gMethods[] = {
  {}   // Sentinel.
};

static PyModuleDef gModule = {
  PyModuleDef_HEAD_INIT,
  .m_name = "multiplier",
  .m_doc = PyDoc_STR("Multiplier source code auditing API"),
  .m_size = 0,
  .m_methods = gMethods,
  .m_slots = {,
  .m_traverse = {},
  .m_clear = {},
  .m_free = {},
};

#pragma clang diagnostic pop

}  // namespace
}  // namespace mx

PyMODINIT_FUNC PyInit_multiplier(void) {
  auto m = PyModule_Create(&gModule);
  if (!m) {
    return nullptr;
  }

  for (auto loader : gLoaders) {
    if (!loader(m)) {
      return nullptr;
    }
  }

  return m;
}
"""


HEADER = """// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/include/Bindings/Python.h>

#include "Error.h"
#include "Types.h"

"""


DISABLE_DIAGNOSTICS = """
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc99-extensions"
"""


ENABLE_DIAGNOSTICS = """
#pragma clang diagnostic pop
"""


INCLUDE = "#include <{}>\n"


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
        [] (PyObject *self, PyObject * const *args, int num_args) -> PyObject * {{
          (void) self;
          (void) args;
          (void) num_args;
"""


METHOD_SPEC_SUFFIX = """        }}),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for {}:{}"),
  }},
"""


STATIC_METHOD_SPEC_SUFFIX = """        }}),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for {}:{}"),
  }},
"""


PROPERTY_LIST_PREFIX = """
namespace {
static PyGetSetDef gProperties[] = {
"""


PROPERTY_SPEC_PREFIX = """  {{
    "{}",
    reinterpret_cast<getter>(
        [] (PyObject *self, void * /* closure */) {{
"""


PROPERTY_SPEC_SUFFIX = """        }}),
    nullptr,
    PyDoc_STR("Wrapper for {}::{}"),
    nullptr,
  }},
"""


PROPERTY_LIST_SUFFIX = """  {}  // Sentinel.
};
}  // namespace
"""


CLASS_TYPEDEF = """namespace {{
using T = {}::{};
struct O final : public mx::PyObject<T> {{

  // Data sufficiently sized and aligned to store a type `T`.
  alignas(alignof(T)) char backing_storage[sizeof(T)];  
}};

}}  // namespace
"""


RICH_COMPARE = """[] (BorrowedPyObject *a_obj, BorrowedPyObject *b_obj, int op) -> SharedPyObject * {
    do {
      if (Py_EQ != op && Py_NE != op) break;

      auto a = O::from_python(a_obj);
      if (!a.has_value()) break;

      auto b = O::from_python(b_obj);
      if (!b.has_value()) break;

      auto ret = (a.value() == b.value()) == (Py_EQ == op) ? Py_True : Py_False;
      Py_INCREF(ret);
      return ret;
    } while (false);

    static constexpr const char *kOperators[] = {"<", "<=", "==", "!=", ">", ">="};
    PyErrorStreamer(PyExc_TypeError)
        << "'" << kOperators[op] << "' not supported between instances of '"
        << Py_TYPE(a_obj)->tp_name "' and '" << Py_TYPE(b_obj)->tp_name << "'";
    return nullptr;
  }"""


NUMBER_METHODS = """
namespace {

static PyNumberMethods gNumberMethods = {
  .nb_bool = [] (BorredPyObject *obj) -> int {
    return !!*(reinterpret_cast<O *>(obj)->data);
  }
};

}  // namespace
"""


SEQUENCE_METHODS = """
namespace {{

static PySequenceMethods gSequenceMethods = {{
  
}};

}}  // namespace
"""


TYPE_GETTER = """
template <>
PyTypeObject * const PyObject<T>::type = nullptr;

template <>
bool PyObject<T>::load(BorredPyObject *module) noexcept {{
  if (type) {{
    return true;
  }}

  PyTypeObject * const tp = &(gTypes[{type_offset}]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_dealloc = [] (::PyObject *obj) {{
    auto *self = reinterpret_cast<O *>(obj);
    if (self->data) {{
      self->data->~T();
    }}
    PyObject_Free(obj);
  }};
  tp->tp_name = "{py_class_name}";
  tp->tp_flags = Py_TPFLAGS_DISALLOW_INSTANTIATION{py_flag_sequencing};
  tp->tp_doc = PyDoc_STR("Wrapper for {cxx_namespace}::{cxx_class_name}");
  tp->tp_as_number = {py_number};
  tp->tp_as_sequence = {py_sequence};
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = nullptr;  // TODO
  tp->tp_richcompare = {py_rich_compare};
  tp->tp_iter = nullptr;  // TODO
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = {py_base_class};
  tp->tp_init = [] (::PyObject *, ::PyObject *, ::PyObject *) -> int {{
    PyErrorStreamer(PyExc_TypeError)
        << "Class '{py_class_name}' cannot be directly instantiated";
    return -1;
  }};
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;  // Don't allow instantiation.

  if (0 != PyType_Ready(tp)) {{
    return false;
  }}

  Py_INCREF(tp);
  type = tp;  // Expose it.
  return true;
}};

template <>
const std::optional<T> PyObject<T>::from_python(const BorredPyObject *obj) noexcept {{
  if (!obj) {{
    return std::nullopt;
  }}

  PyTypeObject * const tp = Py_TYPE(obj);
  if (tp < &(gTypes[{type_offset}]) || tp >= &(gTypes[{type_offset_upper_bound}])) {{
    return std::nullopt;
  }}

  return *(reinterpret_cast<const O *>(obj)->data);
}}

template <>
PyTypeObject *PyObject<T>::classify_type(const T &val) noexcept {{
  return nullptr;
}}

template <>
SharedPyObject *PyObject<T>::to_python(const T &val) noexcept {{
  return nullptr;
}}
"""


class Renamer:
  def rename_class(self, class_schema:ClassSchema) -> str:
    return class_schema.name

  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return method_schema.name


def _wrap_method(class_schema: ClassSchema, schema: NamedSchema,
                 renamer: Renamer, is_static: bool, out: List[str]):
  """Create Python bindings for a method. This skips over methods that have no
  arguments and can be implemented with Python properties."""
  assert isinstance(schema, (MethodSchema, OverloadSetSchema))

  out.append(METHOD_SPEC_PREFIX.format(
      renamer.rename_method(class_schema, schema)))

  out.append(
      (is_static and STATIC_METHOD_SPEC_SUFFIX or METHOD_SPEC_SUFFIX).format(
          class_schema.name, schema.name))


def _wrap_property(class_schema: ClassSchema, schema: NamedSchema,
                   renamer: Renamer, out: List[str]):
  """Creates Python bindings for an instance method with no arguments. These are
  implemented as Python properties."""
  out.append(PROPERTY_SPEC_PREFIX.format(
      renamer.rename_method(class_schema, schema)))
  out.append(PROPERTY_SPEC_SUFFIX.format(class_schema.name, schema.name))


def wrap_class(schema: ClassSchema, type_offsets: Tuple[int, int],
               renamer: Renamer):
  """Create Python bindings for a class schema."""
  out: List[str] = []
  out.append(HEADER)

  cxx_namespace = schema.namespaces and "::".join(schema.namespaces) or ""
  cxx_class_name = schema.name
  py_class_name = renamer.rename_class(schema)

  base_class = "nullptr"
  if schema.bases:
    assert len(schema.bases) == 1
    base_schema = schema.bases[0]
    base_cxx_namespace = schema.namespaces and "::".join(schema.namespaces) or ""
    base_cxx_class_name = schema.name
    base_class = "PyObject<{}::{}>::type".format(base_cxx_namespace, base_cxx_class_name)

  assert schema.location is not None
  out.append(INCLUDE.format(schema.location))

  out.append(CLASS_TYPEDEF.format(cxx_namespace, cxx_class_name))
  out.append(BEGIN_MX_NAMESPACE)
  out.append(DISABLE_DIAGNOSTICS)
  out.append(METHOD_LIST_PREFIX)

  for method in schema.static_methods.values():
    _wrap_method(schema, method, renamer, True, out)

  for method in schema.methods.values():
    if isinstance(schema, OverloadSetSchema) or method.max_num_parameters:
      _wrap_method(schema, method, renamer, False, out)

  out.append(METHOD_LIST_SUFFIX)
  out.append(PROPERTY_LIST_PREFIX)

  for method in schema.methods.values():
    if isinstance(schema, MethodSchema) and not method.max_num_parameters:
      _wrap_property(schema, method, renamer, out)

  out.append(PROPERTY_LIST_SUFFIX)

  if schema.has_boolean_conversion:
    out.append(NUMBER_METHODS)

  if schema.indexed_type:
    size_name: Optional[str] = None
    for method_name in schema.methods:
      if method_name.lower() in ("len", "length", "size", "count"):
        assert size_name is None, "More than one size-like method"
        size_name = method_name
    assert size_name is not None
    out.append(SEQUENCE_METHODS)

  out.append(TYPE_GETTER.format(
      cxx_namespace=cxx_namespace,
      cxx_class_name=schema.name,
      py_class_name=py_class_name,
      py_flag_sequencing=schema.indexed_type and " | Py_TPFLAGS_SEQUENCE " or "",
      py_rich_compare=(
          schema.has_equivalence_relation and RICH_COMPARE or "nullptr"),
      py_base_class=base_class,
      py_number=schema.has_boolean_conversion and "&gNumberMethods" or "nullptr",
      py_sequence=schema.indexed_type and "&gSequenceMethods" or "nullptr",
      type_offset=type_offsets[0],
      type_offset_upper_bound=type_offsets[1]))

  out.append(ENABLE_DIAGNOSTICS)
  out.append(END_MX_NAMESPACE)

  path = list(schema.location.split("/"))
  while len(path):
    if path.pop(0) == "multiplier":
      break

  assert len(path)
  assert path[-1].endswith(".h")
  path[-1] = path[-1][:-2] + ".cpp"
  out_path = os.path.join(MX_BINDINGS_PYTHON_DIR, "Generated", *path)
  os.makedirs(os.path.dirname(out_path), exist_ok=True)

  with open(out_path, "w") as f:
    f.write("".join(out))


def wrap_enum(schema: EnumSchema, renamer: Renamer):
  pass

def _fill_into(schema: ClassSchema, children: Dict[ClassSchema, List[ClassSchema]],
              offsets: Dict[ClassSchema, Tuple[int, int]], classes: List[ClassSchema]):
  begin_offset = len(classes)
  classes.append(schema)
  for derived_schema in children[schema]:
    _fill_into(derived_schema, children, offsets, classes)
  end_offset = len(classes)
  offsets[schema] = (begin_offset, end_offset)

def wrap(schemas: Iterable[Schema], renamer: Renamer):
  work_list: List[ClassSchema] = []
  children: Dict[ClassSchema, List[ClassSchema]] = {}
  enums: List[EnumSchema] = []
  namespaces: Set[str] = set()

  # Collect all `EnumSchema`s and `ClassSchema`s, and keep track of root
  # classes (that have no base classes) in `work_list` and the list of children
  # of each class in `children` so that we can topologically sort the classes.
  for schema in schemas:
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
  with open(os.path.join(MX_BINDINGS_PYTHON_DIR, "Types.cpp"), "w") as f:
    f.write(TYPES_CPP.format(len(classes)))

  # Fill in `Module.cpp`. This defines the main module, and invokes all of the
  # class initializers.
  with open(os.path.join(MX_BINDINGS_PYTHON_DIR, "Module.cpp"), "w") as f:
    
    # TODO: forward declare things

    f.write(MODULE_CPP_PREFIX)

    f.write(MODULE_CPP_MIDDLE)
    for schema in classes:
      cxx_namespace = schema.namespaces and "::".join(schema.namespaces) or ""
      f.write(MODULE_CPP_TYPE_ROW.format(cxx_namespace, schema.name))
    f.write(MODULE_CPP_SUFFIX)

  for schema in classes:
    wrap_class(schema, offsets[schema], renamer)


def run_on_ast(ast: AST, ns_name: str):
  schemas: List[Schema] = []
  lifter = SchemaLifter()

  # Filter out all tag decls that aren't private `*Impl` classes, and also
  # only look at the definitions.
  for tag in find_tags_in_namespace(ast.translation_unit, ns_name):
    if not tag.name.endswith("Impl") and tag.is_this_declaration_a_definition:
      schema: Schema = lifter.lift_decl(tag)
      if isinstance(schema, NamedSchema):
        yield schema


class BasicRenamer(Renamer):
  METHOD_RENAMES = {
    "from": "cast",
    "in": "contained_in",
  }
  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return self.METHOD_RENAMES.get(method_schema.name, method_schema.name)


if __name__ == "__main__":

  parser = ArgumentParser(description='Wrap the API surface area of the classes / enumerator within a namespace')
  parser.add_argument('--namespace', default="mx")
  parser.add_argument('--local_include_dir', default=MX_INCLUDE_DIR)
  parser.add_argument('--system_include_dir', required=True)
  parser.add_argument('--working_dir', default=MX_BIN_BOOSTRAP_DIR)
  parser.add_argument('--source_file', default="Python.cpp")
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
      wrap(run_on_ast(maybe_ast, args.namespace), renamer)
