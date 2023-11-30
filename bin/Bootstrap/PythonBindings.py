# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

import collections
import os
from pypasta import *
from lift import *
from schema import *
from typing import DefaultDict, Dict, Iterable, List, Set, Tuple

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

#include <cstdint>

#include "Binding.h"

namespace mx {
"""


BEGIN_NAMESPACE = "namespace {} {{\n"


END_NAMESPACE = "}}  // namespace {}\n"


MODULE_CPP_FORWARD_DECL_CLASS = "{} {};\n"


MODULE_CPP_FORWARD_DECL_ENUM = "enum {enum_scope}{enum_name} : {stdint_type_name};\n"


MODULE_CPP_MIDDLE = """
namespace {

using LoaderFunc = bool (BorrowedPyObject *);

static PyMethodDef gEmptyMethods[] = {
  {}   // Sentinel.
};

"""


MODULE_CPP_TYPE_ROW = "  PythonBinding<{}{}>::load,\n"


BEGIN_MODULE_CPP_DEF = """
// multiplier{dot_name}
static PyModuleDef g{upper_name}Module = {{
  PyModuleDef_HEAD_INIT,
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


MODULE_CPP_SUFFIX = """
}  // namespace
}  // namespace mx

PyMODINIT_FUNC PyInit_multiplier(void) {
  auto m = PyModule_Create(&mx::gModule);
  if (!m) {
    return nullptr;
  }

  for (auto loader : mx::gLoaders) {
    if (!loader(m)) {
      Py_DECREF(m);
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

#include <multiplier/Types.h>

#include "Binding.h"
#include "Error.h"
#include "Types.h"

"""


DISABLE_DIAGNOSTICS = """
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
"""


ENABLE_DIAGNOSTICS = """
#pragma GCC diagnostic pop
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
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {{
          (void) self;
          (void) args;
          (void) num_args;
"""


METHOD_SPEC_SUFFIX = """          return nullptr;
        }}),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for {}{}::{}"),
  }},
"""


STATIC_METHOD_SPEC_SUFFIX = """          return nullptr;
        }}),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for {}{}::{}"),
  }},
"""


PROPERTY_LIST_PREFIX = """
namespace {
static PyGetSetDef gProperties[] = {
"""


PROPERTY_SPEC_PREFIX = """  {{
    "{}",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) {{
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


TYPE_HASH = """[] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(EntityId(T_cast(obj)->id()).Pack());
  }"""


RICH_COMPARE = """[] (BorrowedPyObject *a_obj, BorrowedPyObject *b_obj, int op) -> SharedPyObject * {
    do {
      if (Py_EQ != op && Py_NE != op) {
        break;
      }

      auto a = PythonBinding<T>::from_python(a_obj);
      if (!a.has_value()) {
        break;
      }

      auto b = PythonBinding<T>::from_python(b_obj);
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
        return static_cast<Py_ssize_t>(T_cast(obj)->{}());
      }}"""


OPTIONAL_SEQUENCE_ITEM = """[] (BorrowedPyObject *obj, Py_ssize_t index) -> SharedPyObject * {{
        auto val = T_cast(obj)->{}();
        if (!val.has_value()) {{
          PyErrorStreamer(PyExc_IndexError)
              << "Invalid index '" << index << "'";
          return nullptr;
        }}
        return PythonBinding<
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
template <>
PyTypeObject *PythonBinding<T>::type = nullptr;
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


PYTHON_BINDING_TO_PYTHON = """
template <>
SharedPyObject *PythonBinding<T>::to_python(const T &val) noexcept {{
  (void) val;
  return nullptr;
}}
"""


PYTHON_BINDING_LOAD = """
namespace {{
static PyTypeObject *InitType(void) noexcept;
}}  // namespace

template <>
bool PythonBinding<T>::load(BorrowedPyObject *module) noexcept {{
  if (!type) {{
    type = InitType();
    if (!type) {{
      return false;
    }}
  }}

  auto tp_obj = reinterpret_cast<BorrowedPyObject *>(PythonBinding<T>::type);
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
  tp->tp_name = "{py_class_name}";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION{py_flag_sequencing};
  tp->tp_doc = PyDoc_STR("Wrapper for {cxx_namespace}::{cxx_class_name}");
  tp->tp_as_number = {py_number};
  tp->tp_as_sequence = {py_sequence};
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = {py_hash};
  tp->tp_richcompare = {py_rich_compare};
  tp->tp_iter = nullptr;  // TODO
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = {py_base_class};
  tp->tp_init = [] (BorrowedPyObject *, BorrowedPyObject *, BorrowedPyObject *) -> int {{
    PyErrorStreamer(PyExc_TypeError)
        << "Class '{py_class_name}' cannot be directly instantiated";
    return -1;
  }};
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;  // Don't allow instantiation.

  if (0 != PyType_Ready(tp)) {{
    return nullptr;
  }}

  return tp;
}}

}}  // namespace

"""


class Renamer:
  def rename_class(self, class_schema:ClassSchema) -> str:
    return class_schema.name

  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return method_schema.name


class BasicRenamer(Renamer):
  METHOD_RENAMES = {
    "from": "cast",
    "in": "contained_in",
  }
  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return self.METHOD_RENAMES.get(method_schema.name, method_schema.name)


class EntityIdSchema(Schema):
  def __init__(self, *args):
    super().__init__()


def _wrap_method(class_schema: ClassSchema, schema: NamedSchema,
                 renamer: Renamer, is_static: bool, out: List[str]):
  """Create Python bindings for a method. This skips over methods that have no
  arguments and can be implemented with Python properties."""
  assert isinstance(schema, (MethodSchema, OverloadSetSchema))

  rel_ns = _relative_namespace(class_schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"

  out.append(METHOD_SPEC_PREFIX.format(
      renamer.rename_method(class_schema, schema)))

  out.append(
      (is_static and STATIC_METHOD_SPEC_SUFFIX or METHOD_SPEC_SUFFIX).format(
          cxx_namespace, class_schema.name, schema.name))


def _wrap_property(class_schema: ClassSchema, schema: NamedSchema,
                   renamer: Renamer, out: List[str]):
  """Creates Python bindings for an instance method with no arguments. These are
  implemented as Python properties."""
  out.append(PROPERTY_SPEC_PREFIX.format(
      renamer.rename_method(class_schema, schema)))
  out.append(PROPERTY_SPEC_SUFFIX.format(class_schema.name, schema.name))


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


def wrap_class(schema: ClassSchema, type_offsets: Tuple[int, int],
               renamer: Renamer):
  """Create Python bindings for a class schema."""

  out: List[str] = []
  out.append(HEADER)

  rel_ns = _relative_namespace(schema)
  cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
  cxx_class_name = schema.name
  py_class_name = renamer.rename_class(schema)

  type_hash = "PyObject_HashNotImplemented"
  base_class = "nullptr"
  if schema.bases:
    assert len(schema.bases) == 1
    base_schema = schema.bases[0]
    rel_ns = _relative_namespace(schema)
    base_cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
    base_cxx_class_name = schema.name
    base_class = "PythonBinding<{}{}>::type".format(base_cxx_namespace, base_cxx_class_name)
    type_hash = "PythonBinding<{}{}>::type->tp_hash".format(base_cxx_namespace, base_cxx_class_name)

  for method in schema.methods.values():
    if isinstance(method, MethodSchema) and \
       method.name == "id" and \
       isinstance(method.return_type, EntityIdSchema):
      type_hash = TYPE_HASH
      break

  assert schema.location is not None
  out.append(INCLUDE.format(schema.location))
  out.append(DISABLE_DIAGNOSTICS)
  out.append(CLASS_TYPEDEF.format(cxx_namespace, cxx_class_name))
  out.append(BEGIN_MX_NAMESPACE)
  out.append(PYTHON_BINDING_TYPE)
  out.append(PYTHON_BINDING_FROM_PYTHON.format(
      type_offset=type_offsets[0],
      type_offset_upper_bound=type_offsets[1]))
  out.append(PYTHON_BINDING_TO_PYTHON.format())
  out.append(PYTHON_BINDING_LOAD.format(
      py_class_name=py_class_name))
  out.append(METHOD_LIST_PREFIX)

  for method in schema.static_methods.values():
    _wrap_method(schema, method, renamer, True, out)

  for method in schema.methods.values():
    if not method.is_const:
      continue

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
    
    py_seq_item = "nullptr"
    if isinstance(schema.indexed_type, StdOptionalSchema):
      py_seq_item = OPTIONAL_SEQUENCE_ITEM
    elif schema.has_boolean_conversion:
      pass
    else:
      pass

    out.append(SEQUENCE_METHODS.format(
        py_seq_length=SEQUENCE_SIZE.format(size_name),
        py_seq_item=py_seq_item))

  out.append(INIT_TYPE.format(
      cxx_namespace=cxx_namespace,
      cxx_class_name=schema.name,
      py_class_name=py_class_name,
      py_flag_sequencing=schema.indexed_type and " | Py_TPFLAGS_SEQUENCE " or "",
      py_hash=type_hash,
      py_rich_compare=(
          schema.has_equivalence_relation and RICH_COMPARE or "nullptr"),
      py_base_class=base_class,
      py_number=schema.has_boolean_conversion and "&gNumberMethods" or "nullptr",
      py_sequence=schema.indexed_type and "&gSequenceMethods" or "nullptr",
      type_offset=type_offsets[0],
      type_offset_upper_bound=type_offsets[1]))

  out.append(ENABLE_DIAGNOSTICS)
  out.append(END_MX_NAMESPACE)

  out_path = os.path.join(MX_BINDINGS_PYTHON_DIR, "Generated",
                          _relative_dir(schema),
                          cxx_class_name + ".cpp")
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
  namespaces: DefaultDict[str, List[Schema]] = collections.defaultdict(list)
  directories: DefaultDict[str, List[Schema]] = collections.defaultdict(list)

  # Collect all `EnumSchema`s and `ClassSchema`s, and keep track of root
  # classes (that have no base classes) in `work_list` and the list of children
  # of each class in `children` so that we can topologically sort the classes.
  for schema in schemas:

    namespaces[_relative_namespace(schema)].append(schema)
    directories[_relative_dir(schema)].append(schema)

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

    f.write(MODULE_CPP_PREFIX)

    # Forward declare the classes/enums.
    for namespace, schemas in namespaces.items():
      if len(namespace):
        f.write(BEGIN_NAMESPACE.format(namespace))
      for schema in schemas:
        if isinstance(schema, ClassSchema):
          f.write(MODULE_CPP_FORWARD_DECL_CLASS.format(schema.elaborator, schema.name))
        elif isinstance(schema, EnumSchema):
          assert schema.is_explicitly_typed
          enum_scope = schema.is_scoped and "class " or ""
          f.write(MODULE_CPP_FORWARD_DECL_ENUM.format(
              enum_scope=enum_scope,
              enum_name=schema.name,
              stdint_type_name=schema.base_type.stdint_type_name))
      if len(namespace):
        f.write(END_NAMESPACE.format(namespace))

    f.write(MODULE_CPP_MIDDLE)

    sorted_directories = list(directories.keys())
    sorted_directories.sort(key=len)

    # Define the modules, and make lists of the wrappers.
    for rel_dir in sorted_directories:
      doc = rel_dir and f"Wrapper of {rel_dir}" or "Multiplier source code auditing API"
      dot_name = rel_dir and "." + rel_dir.replace("/", ".").lower() or ""
      upper_name = rel_dir and rel_dir.split("/")[-1] or ""
      lower_name = upper_name.lower()

      f.write(BEGIN_MODULE_CPP_DEF.format(
          dot_name=dot_name,
          lower_name=lower_name,
          upper_name=upper_name,
          py_doc=doc))

      for schema in directories[rel_dir]:
        rel_ns = _relative_namespace(schema)
        cxx_namespace = rel_ns and f"mx::{rel_ns}::" or "mx::"
        f.write(MODULE_CPP_TYPE_ROW.format(cxx_namespace, schema.name))

      f.write(END_MODULE_CPP_DEF)

    f.write(MODULE_CPP_SUFFIX)

  for schema in classes:
    wrap_class(schema, offsets[schema], renamer)


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
)


def run_on_ast(ast: AST, ns_name: str):
  schemas: List[Schema] = []
  lifter = SchemaLifter()
  lifter.add_lifter("mx::EntityId", EntityIdSchema)
  lifter.add_lifter("mx::RawEntityId", EntityIdSchema)
  lifter.add_lifter("mx::FileTokenId", EntityIdSchema)
  lifter.add_lifter("mx::MacroTokenId", EntityIdSchema)
  lifter.add_lifter("mx::ParsedTokenId", EntityIdSchema)

  for entity in ENTITY_KINDS:
    lifter.add_lifter(f"mx::{entity}Id", EntityIdSchema)
    lifter.add_lifter(f"mx::Packed{entity}Id", EntityIdSchema)

  lifter.add_parameterized_lifter("mx::SpecificEntityId", 1, EntityIdSchema)

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
