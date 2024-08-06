// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Type.h>

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
using T = mx::Type;

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
  if (tp < &(gTypes[410]) || tp >= &(gTypes[473])) {
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

    case mx::TemplateTypeParmType::static_kind():
      tp = &(gTypes[411]);
      break;

    case mx::TemplateSpecializationType::static_kind():
      tp = &(gTypes[412]);
      break;

    case mx::RecordType::static_kind():
      tp = &(gTypes[414]);
      break;

    case mx::EnumType::static_kind():
      tp = &(gTypes[415]);
      break;

    case mx::SubstTemplateTypeParmType::static_kind():
      tp = &(gTypes[416]);
      break;

    case mx::SubstTemplateTypeParmPackType::static_kind():
      tp = &(gTypes[417]);
      break;

    case mx::RValueReferenceType::static_kind():
      tp = &(gTypes[419]);
      break;

    case mx::LValueReferenceType::static_kind():
      tp = &(gTypes[420]);
      break;

    case mx::QualifiedType::static_kind():
      tp = &(gTypes[421]);
      break;

    case mx::PointerType::static_kind():
      tp = &(gTypes[422]);
      break;

    case mx::PipeType::static_kind():
      tp = &(gTypes[423]);
      break;

    case mx::ParenType::static_kind():
      tp = &(gTypes[424]);
      break;

    case mx::PackExpansionType::static_kind():
      tp = &(gTypes[425]);
      break;

    case mx::ObjCTypeParamType::static_kind():
      tp = &(gTypes[426]);
      break;

    case mx::ObjCObjectType::static_kind():
      tp = &(gTypes[427]);
      break;

    case mx::ObjCInterfaceType::static_kind():
      tp = &(gTypes[428]);
      break;

    case mx::ObjCObjectPointerType::static_kind():
      tp = &(gTypes[429]);
      break;

    case mx::MemberPointerType::static_kind():
      tp = &(gTypes[430]);
      break;

    case mx::DependentSizedMatrixType::static_kind():
      tp = &(gTypes[432]);
      break;

    case mx::ConstantMatrixType::static_kind():
      tp = &(gTypes[433]);
      break;

    case mx::MacroQualifiedType::static_kind():
      tp = &(gTypes[434]);
      break;

    case mx::InjectedClassNameType::static_kind():
      tp = &(gTypes[435]);
      break;

    case mx::FunctionProtoType::static_kind():
      tp = &(gTypes[437]);
      break;

    case mx::FunctionNoProtoType::static_kind():
      tp = &(gTypes[438]);
      break;

    case mx::DependentVectorType::static_kind():
      tp = &(gTypes[439]);
      break;

    case mx::DependentSizedExtVectorType::static_kind():
      tp = &(gTypes[440]);
      break;

    case mx::DependentBitIntType::static_kind():
      tp = &(gTypes[441]);
      break;

    case mx::DependentAddressSpaceType::static_kind():
      tp = &(gTypes[442]);
      break;

    case mx::DeducedTemplateSpecializationType::static_kind():
      tp = &(gTypes[444]);
      break;

    case mx::AutoType::static_kind():
      tp = &(gTypes[445]);
      break;

    case mx::DecltypeType::static_kind():
      tp = &(gTypes[446]);
      break;

    case mx::ComplexType::static_kind():
      tp = &(gTypes[447]);
      break;

    case mx::BuiltinType::static_kind():
      tp = &(gTypes[448]);
      break;

    case mx::BlockPointerType::static_kind():
      tp = &(gTypes[449]);
      break;

    case mx::BitIntType::static_kind():
      tp = &(gTypes[450]);
      break;

    case mx::BTFTagAttributedType::static_kind():
      tp = &(gTypes[451]);
      break;

    case mx::AttributedType::static_kind():
      tp = &(gTypes[452]);
      break;

    case mx::AtomicType::static_kind():
      tp = &(gTypes[453]);
      break;

    case mx::VariableArrayType::static_kind():
      tp = &(gTypes[455]);
      break;

    case mx::IncompleteArrayType::static_kind():
      tp = &(gTypes[456]);
      break;

    case mx::DependentSizedArrayType::static_kind():
      tp = &(gTypes[457]);
      break;

    case mx::ConstantArrayType::static_kind():
      tp = &(gTypes[458]);
      break;

    case mx::AdjustedType::static_kind():
      tp = &(gTypes[459]);
      break;

    case mx::DecayedType::static_kind():
      tp = &(gTypes[460]);
      break;

    case mx::ElaboratedType::static_kind():
      tp = &(gTypes[462]);
      break;

    case mx::DependentTemplateSpecializationType::static_kind():
      tp = &(gTypes[463]);
      break;

    case mx::DependentNameType::static_kind():
      tp = &(gTypes[464]);
      break;

    case mx::VectorType::static_kind():
      tp = &(gTypes[465]);
      break;

    case mx::ExtVectorType::static_kind():
      tp = &(gTypes[466]);
      break;

    case mx::UsingType::static_kind():
      tp = &(gTypes[467]);
      break;

    case mx::UnresolvedUsingType::static_kind():
      tp = &(gTypes[468]);
      break;

    case mx::UnaryTransformType::static_kind():
      tp = &(gTypes[469]);
      break;

    case mx::TypedefType::static_kind():
      tp = &(gTypes[470]);
      break;

    case mx::TypeOfType::static_kind():
      tp = &(gTypes[471]);
      break;

    case mx::TypeOfExprType::static_kind():
      tp = &(gTypes[472]);
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
  if (0 != PyModule_AddObjectRef(module, "Type", tp_obj)) {
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
    PyDoc_STR("Wrapper for mx::Type::id"),
    nullptr,
  },
  {
    "tokens",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->tokens());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::tokens"),
    nullptr,
  },
  {
    "raw_qualifiers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->raw_qualifiers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::raw_qualifiers"),
    nullptr,
  },
  {
    "desugared_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->desugared_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::desugared_type"),
    nullptr,
  },
  {
    "canonical_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->canonical_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::canonical_type"),
    nullptr,
  },
  {
    "is_qualified",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_qualified());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::is_qualified"),
    nullptr,
  },
  {
    "unqualified_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->unqualified_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::unqualified_type"),
    nullptr,
  },
  {
    "size_in_bits",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->size_in_bits());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::size_in_bits"),
    nullptr,
  },
  {
    "alignment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->alignment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::alignment"),
    nullptr,
  },
  {
    "accepts_obj_c_type_parameters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->accepts_obj_c_type_parameters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::accepts_obj_c_type_parameters"),
    nullptr,
  },
  {
    "can_decay_to_pointer_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->can_decay_to_pointer_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::can_decay_to_pointer_type"),
    nullptr,
  },
  {
    "can_have_nullability",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->can_have_nullability());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::can_have_nullability"),
    nullptr,
  },
  {
    "contains_errors",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_errors());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::contains_errors"),
    nullptr,
  },
  {
    "contains_unexpanded_parameter_pack",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_unexpanded_parameter_pack());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::contains_unexpanded_parameter_pack"),
    nullptr,
  },
  {
    "linkage",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->linkage());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::linkage"),
    nullptr,
  },
  {
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::kind"),
    nullptr,
  },
  {
    "unqualified_desugared_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->unqualified_desugared_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::unqualified_desugared_type"),
    nullptr,
  },
  {
    "visibility",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->visibility());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::visibility"),
    nullptr,
  },
  {
    "is_sizeless_vector_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_sizeless_vector_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::is_sizeless_vector_type"),
    nullptr,
  },
  {
    "is_unresolved_type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_unresolved_type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Type::is_unresolved_type"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "static_category",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 0) {

            return ::mx::to_python(T::static_category());
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'static_category'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Type::static_category"),
  },
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
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<std::span<const mx::TypeKind>>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(T::in(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'IN'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Type::in"),
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

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Type::containing"),
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

            return ::mx::to_python(T::by_id(arg_0.value(), std::move(arg_1.value())));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::Type::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Type>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Type>>(args[0]);
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
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation, mx::ir::Operation>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::Type::from"),
  },
  {
    "contains",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          T *obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->contains(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'contains'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::Type::contains"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[410]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.Type";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Type");
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
          << "'Type.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Type.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Type' cannot be directly instantiated";
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
