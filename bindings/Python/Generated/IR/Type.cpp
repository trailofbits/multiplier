// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Type.h>

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
using T = mx::ir::Type;

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
  if (tp < &(gTypes[1366]) || tp >= &(gTypes[1436])) {
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

    case mx::ir::builtin::ShapedType::static_kind():
      tp = &(gTypes[1368]);
      break;

    case mx::ir::builtin::FloatType::static_kind():
      tp = &(gTypes[1369]);
      break;

    case mx::ir::builtin::BFloat16Type::static_kind():
      tp = &(gTypes[1370]);
      break;

    case mx::ir::builtin::ComplexType::static_kind():
      tp = &(gTypes[1371]);
      break;

    case mx::ir::builtin::Float8E4M3B11FNUZType::static_kind():
      tp = &(gTypes[1372]);
      break;

    case mx::ir::builtin::Float8E4M3FNType::static_kind():
      tp = &(gTypes[1373]);
      break;

    case mx::ir::builtin::Float8E4M3FNUZType::static_kind():
      tp = &(gTypes[1374]);
      break;

    case mx::ir::builtin::Float8E5M2Type::static_kind():
      tp = &(gTypes[1375]);
      break;

    case mx::ir::builtin::Float8E5M2FNUZType::static_kind():
      tp = &(gTypes[1376]);
      break;

    case mx::ir::builtin::Float16Type::static_kind():
      tp = &(gTypes[1377]);
      break;

    case mx::ir::builtin::Float32Type::static_kind():
      tp = &(gTypes[1378]);
      break;

    case mx::ir::builtin::Float64Type::static_kind():
      tp = &(gTypes[1379]);
      break;

    case mx::ir::builtin::Float80Type::static_kind():
      tp = &(gTypes[1380]);
      break;

    case mx::ir::builtin::Float128Type::static_kind():
      tp = &(gTypes[1381]);
      break;

    case mx::ir::builtin::FloatTF32Type::static_kind():
      tp = &(gTypes[1382]);
      break;

    case mx::ir::builtin::FunctionType::static_kind():
      tp = &(gTypes[1383]);
      break;

    case mx::ir::builtin::IndexType::static_kind():
      tp = &(gTypes[1384]);
      break;

    case mx::ir::builtin::IntegerType::static_kind():
      tp = &(gTypes[1385]);
      break;

    case mx::ir::builtin::MemRefType::static_kind():
      tp = &(gTypes[1386]);
      break;

    case mx::ir::builtin::NoneType::static_kind():
      tp = &(gTypes[1387]);
      break;

    case mx::ir::builtin::OpaqueType::static_kind():
      tp = &(gTypes[1388]);
      break;

    case mx::ir::builtin::RankedTensorType::static_kind():
      tp = &(gTypes[1389]);
      break;

    case mx::ir::builtin::TupleType::static_kind():
      tp = &(gTypes[1390]);
      break;

    case mx::ir::builtin::UnrankedMemRefType::static_kind():
      tp = &(gTypes[1391]);
      break;

    case mx::ir::builtin::UnrankedTensorType::static_kind():
      tp = &(gTypes[1392]);
      break;

    case mx::ir::builtin::VectorType::static_kind():
      tp = &(gTypes[1393]);
      break;

    case mx::ir::llvm::ArrayType::static_kind():
      tp = &(gTypes[1395]);
      break;

    case mx::ir::llvm::FixedVectorType::static_kind():
      tp = &(gTypes[1396]);
      break;

    case mx::ir::llvm::FunctionType::static_kind():
      tp = &(gTypes[1397]);
      break;

    case mx::ir::llvm::PointerType::static_kind():
      tp = &(gTypes[1398]);
      break;

    case mx::ir::llvm::ScalableVectorType::static_kind():
      tp = &(gTypes[1399]);
      break;

    case mx::ir::llvm::TargetExtType::static_kind():
      tp = &(gTypes[1400]);
      break;

    case mx::ir::hl::AdjustedType::static_kind():
      tp = &(gTypes[1402]);
      break;

    case mx::ir::hl::ArrayType::static_kind():
      tp = &(gTypes[1403]);
      break;

    case mx::ir::hl::AttributedType::static_kind():
      tp = &(gTypes[1404]);
      break;

    case mx::ir::hl::BFloat16Type::static_kind():
      tp = &(gTypes[1405]);
      break;

    case mx::ir::hl::BoolType::static_kind():
      tp = &(gTypes[1406]);
      break;

    case mx::ir::hl::CharType::static_kind():
      tp = &(gTypes[1407]);
      break;

    case mx::ir::hl::DecayedType::static_kind():
      tp = &(gTypes[1408]);
      break;

    case mx::ir::hl::DoubleType::static_kind():
      tp = &(gTypes[1409]);
      break;

    case mx::ir::hl::ElaboratedType::static_kind():
      tp = &(gTypes[1410]);
      break;

    case mx::ir::hl::EnumType::static_kind():
      tp = &(gTypes[1411]);
      break;

    case mx::ir::hl::Float128Type::static_kind():
      tp = &(gTypes[1412]);
      break;

    case mx::ir::hl::FloatType::static_kind():
      tp = &(gTypes[1413]);
      break;

    case mx::ir::hl::HalfType::static_kind():
      tp = &(gTypes[1414]);
      break;

    case mx::ir::hl::Int128Type::static_kind():
      tp = &(gTypes[1415]);
      break;

    case mx::ir::hl::IntType::static_kind():
      tp = &(gTypes[1416]);
      break;

    case mx::ir::hl::LValueType::static_kind():
      tp = &(gTypes[1417]);
      break;

    case mx::ir::hl::LabelType::static_kind():
      tp = &(gTypes[1418]);
      break;

    case mx::ir::hl::LongDoubleType::static_kind():
      tp = &(gTypes[1419]);
      break;

    case mx::ir::hl::LongLongType::static_kind():
      tp = &(gTypes[1420]);
      break;

    case mx::ir::hl::LongType::static_kind():
      tp = &(gTypes[1421]);
      break;

    case mx::ir::hl::ParenType::static_kind():
      tp = &(gTypes[1422]);
      break;

    case mx::ir::hl::PointerType::static_kind():
      tp = &(gTypes[1423]);
      break;

    case mx::ir::hl::RValueType::static_kind():
      tp = &(gTypes[1424]);
      break;

    case mx::ir::hl::RecordType::static_kind():
      tp = &(gTypes[1425]);
      break;

    case mx::ir::hl::ReferenceType::static_kind():
      tp = &(gTypes[1426]);
      break;

    case mx::ir::hl::ShortType::static_kind():
      tp = &(gTypes[1427]);
      break;

    case mx::ir::hl::TypeOfExprType::static_kind():
      tp = &(gTypes[1428]);
      break;

    case mx::ir::hl::TypeOfTypeType::static_kind():
      tp = &(gTypes[1429]);
      break;

    case mx::ir::hl::TypedefType::static_kind():
      tp = &(gTypes[1430]);
      break;

    case mx::ir::hl::VoidType::static_kind():
      tp = &(gTypes[1431]);
      break;

    case mx::ir::core::FunctionType::static_kind():
      tp = &(gTypes[1433]);
      break;

    case mx::ir::unsup::UnsupportedType::static_kind():
      tp = &(gTypes[1435]);
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
    "kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ir::Type::kind"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1366]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.Type";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::::Type");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = [] (BorrowedPyObject *obj) -> Py_hash_t {
    return static_cast<Py_hash_t>(reinterpret_cast<uintptr_t>(T_cast(obj)->underlying_type()));
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
  tp->tp_base = nullptr;
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
