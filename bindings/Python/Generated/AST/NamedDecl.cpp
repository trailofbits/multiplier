// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/NamedDecl.h>

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
using T = mx::NamedDecl;

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
  if (tp < &(gTypes[713]) || tp >= &(gTypes[788])) {
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

    case mx::LabelDecl::static_kind():
      tp = &(gTypes[714]);
      break;

    case mx::HLSLBufferDecl::static_kind():
      tp = &(gTypes[715]);
      break;

    case mx::UsingEnumDecl::static_kind():
      tp = &(gTypes[717]);
      break;

    case mx::UsingDecl::static_kind():
      tp = &(gTypes[718]);
      break;

    case mx::UnresolvedUsingValueDecl::static_kind():
      tp = &(gTypes[720]);
      break;

    case mx::UnnamedGlobalConstantDecl::static_kind():
      tp = &(gTypes[721]);
      break;

    case mx::TemplateParamObjectDecl::static_kind():
      tp = &(gTypes[722]);
      break;

    case mx::OMPDeclareReductionDecl::static_kind():
      tp = &(gTypes[723]);
      break;

    case mx::MSGuidDecl::static_kind():
      tp = &(gTypes[724]);
      break;

    case mx::IndirectFieldDecl::static_kind():
      tp = &(gTypes[725]);
      break;

    case mx::EnumConstantDecl::static_kind():
      tp = &(gTypes[726]);
      break;

    case mx::VarDecl::static_kind():
      tp = &(gTypes[728]);
      break;

    case mx::ParmVarDecl::static_kind():
      tp = &(gTypes[729]);
      break;

    case mx::OMPCapturedExprDecl::static_kind():
      tp = &(gTypes[730]);
      break;

    case mx::ImplicitParamDecl::static_kind():
      tp = &(gTypes[731]);
      break;

    case mx::DecompositionDecl::static_kind():
      tp = &(gTypes[732]);
      break;

    case mx::VarTemplateSpecializationDecl::static_kind():
      tp = &(gTypes[733]);
      break;

    case mx::VarTemplatePartialSpecializationDecl::static_kind():
      tp = &(gTypes[734]);
      break;

    case mx::NonTypeTemplateParmDecl::static_kind():
      tp = &(gTypes[735]);
      break;

    case mx::MSPropertyDecl::static_kind():
      tp = &(gTypes[736]);
      break;

    case mx::FunctionDecl::static_kind():
      tp = &(gTypes[737]);
      break;

    case mx::CXXMethodDecl::static_kind():
      tp = &(gTypes[738]);
      break;

    case mx::CXXDestructorDecl::static_kind():
      tp = &(gTypes[739]);
      break;

    case mx::CXXConversionDecl::static_kind():
      tp = &(gTypes[740]);
      break;

    case mx::CXXConstructorDecl::static_kind():
      tp = &(gTypes[741]);
      break;

    case mx::CXXDeductionGuideDecl::static_kind():
      tp = &(gTypes[742]);
      break;

    case mx::FieldDecl::static_kind():
      tp = &(gTypes[743]);
      break;

    case mx::ObjCIvarDecl::static_kind():
      tp = &(gTypes[744]);
      break;

    case mx::ObjCAtDefsFieldDecl::static_kind():
      tp = &(gTypes[745]);
      break;

    case mx::BindingDecl::static_kind():
      tp = &(gTypes[746]);
      break;

    case mx::OMPDeclareMapperDecl::static_kind():
      tp = &(gTypes[748]);
      break;

    case mx::UsingShadowDecl::static_kind():
      tp = &(gTypes[749]);
      break;

    case mx::ConstructorUsingShadowDecl::static_kind():
      tp = &(gTypes[750]);
      break;

    case mx::UsingPackDecl::static_kind():
      tp = &(gTypes[751]);
      break;

    case mx::UsingDirectiveDecl::static_kind():
      tp = &(gTypes[752]);
      break;

    case mx::UnresolvedUsingIfExistsDecl::static_kind():
      tp = &(gTypes[753]);
      break;

    case mx::TemplateTypeParmDecl::static_kind():
      tp = &(gTypes[755]);
      break;

    case mx::RecordDecl::static_kind():
      tp = &(gTypes[757]);
      break;

    case mx::CXXRecordDecl::static_kind():
      tp = &(gTypes[758]);
      break;

    case mx::ClassTemplateSpecializationDecl::static_kind():
      tp = &(gTypes[759]);
      break;

    case mx::ClassTemplatePartialSpecializationDecl::static_kind():
      tp = &(gTypes[760]);
      break;

    case mx::EnumDecl::static_kind():
      tp = &(gTypes[761]);
      break;

    case mx::UnresolvedUsingTypenameDecl::static_kind():
      tp = &(gTypes[762]);
      break;

    case mx::TypedefDecl::static_kind():
      tp = &(gTypes[764]);
      break;

    case mx::TypeAliasDecl::static_kind():
      tp = &(gTypes[765]);
      break;

    case mx::ObjCTypeParamDecl::static_kind():
      tp = &(gTypes[766]);
      break;

    case mx::FunctionTemplateDecl::static_kind():
      tp = &(gTypes[769]);
      break;

    case mx::ClassTemplateDecl::static_kind():
      tp = &(gTypes[770]);
      break;

    case mx::VarTemplateDecl::static_kind():
      tp = &(gTypes[771]);
      break;

    case mx::TypeAliasTemplateDecl::static_kind():
      tp = &(gTypes[772]);
      break;

    case mx::ConceptDecl::static_kind():
      tp = &(gTypes[773]);
      break;

    case mx::BuiltinTemplateDecl::static_kind():
      tp = &(gTypes[774]);
      break;

    case mx::TemplateTemplateParmDecl::static_kind():
      tp = &(gTypes[775]);
      break;

    case mx::ObjCPropertyDecl::static_kind():
      tp = &(gTypes[776]);
      break;

    case mx::ObjCMethodDecl::static_kind():
      tp = &(gTypes[777]);
      break;

    case mx::ObjCCategoryDecl::static_kind():
      tp = &(gTypes[779]);
      break;

    case mx::ObjCProtocolDecl::static_kind():
      tp = &(gTypes[780]);
      break;

    case mx::ObjCInterfaceDecl::static_kind():
      tp = &(gTypes[781]);
      break;

    case mx::ObjCCategoryImplDecl::static_kind():
      tp = &(gTypes[783]);
      break;

    case mx::ObjCImplementationDecl::static_kind():
      tp = &(gTypes[784]);
      break;

    case mx::ObjCCompatibleAliasDecl::static_kind():
      tp = &(gTypes[785]);
      break;

    case mx::NamespaceDecl::static_kind():
      tp = &(gTypes[786]);
      break;

    case mx::NamespaceAliasDecl::static_kind():
      tp = &(gTypes[787]);
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
  if (0 != PyModule_AddObjectRef(module, "NamedDecl", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "canonical_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->canonical_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::canonical_declaration"),
    nullptr,
  },
  {
    "definition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->definition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::definition"),
    nullptr,
  },
  {
    "redeclarations",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->redeclarations());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::redeclarations"),
    nullptr,
  },
  {
    "formal_linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->formal_linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::formal_linkage"),
    nullptr,
  },
  {
    "name",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->name());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::name"),
    nullptr,
  },
  {
    "obj_cf_string_formatting_family",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->obj_cf_string_formatting_family());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::obj_cf_string_formatting_family"),
    nullptr,
  },
  {
    "qualified_name_as_string",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->qualified_name_as_string());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::qualified_name_as_string"),
    nullptr,
  },
  {
    "underlying_declaration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->underlying_declaration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::underlying_declaration"),
    nullptr,
  },
  {
    "visibility",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->visibility());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::visibility"),
    nullptr,
  },
  {
    "has_external_formal_linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_external_formal_linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::has_external_formal_linkage"),
    nullptr,
  },
  {
    "has_linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::has_linkage"),
    nullptr,
  },
  {
    "has_linkage_been_computed",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_linkage_been_computed());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::has_linkage_been_computed"),
    nullptr,
  },
  {
    "is_cxx_class_member",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_cxx_class_member());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::is_cxx_class_member"),
    nullptr,
  },
  {
    "is_cxx_instance_member",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_cxx_instance_member());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::is_cxx_instance_member"),
    nullptr,
  },
  {
    "is_externally_declarable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_externally_declarable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::is_externally_declarable"),
    nullptr,
  },
  {
    "is_externally_visible",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_externally_visible());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::is_externally_visible"),
    nullptr,
  },
  {
    "is_linkage_valid",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_linkage_valid());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::NamedDecl::is_linkage_valid"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "IN",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Compilation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::NamedDecl::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
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
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
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
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::NamedDecl::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<EntityId>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::NamedDecl::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::hl::Operation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Reference>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenContext>(args[0]);
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
    PyDoc_STR("Wrapper for mx::NamedDecl::from"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::NamedDecl::from_base"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[713]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.NamedDecl";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::NamedDecl");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[697].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[697]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'NamedDecl.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'NamedDecl.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'NamedDecl' cannot be directly instantiated";
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
