// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/Attribute.h>

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
using T = mx::ir::Attribute;

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
  if (tp < &(gTypes[835]) || tp >= &(gTypes[926])) {
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

    case mx::ir::builtin::TypedAttr::static_kind():
      tp = &(gTypes[837]);
      break;

    case mx::ir::builtin::ElementsAttr::static_kind():
      tp = &(gTypes[838]);
      break;

    case mx::ir::builtin::AffineMapAttr::static_kind():
      tp = &(gTypes[839]);
      break;

    case mx::ir::builtin::ArrayAttr::static_kind():
      tp = &(gTypes[840]);
      break;

    case mx::ir::builtin::DenseArrayAttr::static_kind():
      tp = &(gTypes[841]);
      break;

    case mx::ir::builtin::DenseIntOrFPElementsAttr::static_kind():
      tp = &(gTypes[842]);
      break;

    case mx::ir::builtin::DenseResourceElementsAttr::static_kind():
      tp = &(gTypes[843]);
      break;

    case mx::ir::builtin::DenseStringElementsAttr::static_kind():
      tp = &(gTypes[844]);
      break;

    case mx::ir::builtin::DictionaryAttr::static_kind():
      tp = &(gTypes[845]);
      break;

    case mx::ir::builtin::FloatAttr::static_kind():
      tp = &(gTypes[846]);
      break;

    case mx::ir::builtin::IntegerAttr::static_kind():
      tp = &(gTypes[847]);
      break;

    case mx::ir::builtin::IntegerSetAttr::static_kind():
      tp = &(gTypes[848]);
      break;

    case mx::ir::builtin::OpaqueAttr::static_kind():
      tp = &(gTypes[849]);
      break;

    case mx::ir::builtin::SparseElementsAttr::static_kind():
      tp = &(gTypes[850]);
      break;

    case mx::ir::builtin::StringAttr::static_kind():
      tp = &(gTypes[851]);
      break;

    case mx::ir::builtin::SymbolRefAttr::static_kind():
      tp = &(gTypes[852]);
      break;

    case mx::ir::builtin::TypeAttr::static_kind():
      tp = &(gTypes[853]);
      break;

    case mx::ir::builtin::UnitAttr::static_kind():
      tp = &(gTypes[854]);
      break;

    case mx::ir::builtin::StridedLayoutAttr::static_kind():
      tp = &(gTypes[855]);
      break;

    case mx::ir::builtin::BoolAttr::static_kind():
      tp = &(gTypes[856]);
      break;

    case mx::ir::builtin::FlatSymbolRefAttr::static_kind():
      tp = &(gTypes[857]);
      break;

    case mx::ir::builtin::DenseIntElementsAttr::static_kind():
      tp = &(gTypes[858]);
      break;

    case mx::ir::llvm::CConvAttr::static_kind():
      tp = &(gTypes[860]);
      break;

    case mx::ir::llvm::ComdatAttr::static_kind():
      tp = &(gTypes[861]);
      break;

    case mx::ir::llvm::AccessGroupAttr::static_kind():
      tp = &(gTypes[862]);
      break;

    case mx::ir::llvm::AliasScopeAttr::static_kind():
      tp = &(gTypes[863]);
      break;

    case mx::ir::llvm::AliasScopeDomainAttr::static_kind():
      tp = &(gTypes[864]);
      break;

    case mx::ir::llvm::DIBasicTypeAttr::static_kind():
      tp = &(gTypes[865]);
      break;

    case mx::ir::llvm::DICompileUnitAttr::static_kind():
      tp = &(gTypes[866]);
      break;

    case mx::ir::llvm::DICompositeTypeAttr::static_kind():
      tp = &(gTypes[867]);
      break;

    case mx::ir::llvm::DIDerivedTypeAttr::static_kind():
      tp = &(gTypes[868]);
      break;

    case mx::ir::llvm::DIFileAttr::static_kind():
      tp = &(gTypes[869]);
      break;

    case mx::ir::llvm::DILabelAttr::static_kind():
      tp = &(gTypes[870]);
      break;

    case mx::ir::llvm::DILexicalBlockAttr::static_kind():
      tp = &(gTypes[871]);
      break;

    case mx::ir::llvm::DILexicalBlockFileAttr::static_kind():
      tp = &(gTypes[872]);
      break;

    case mx::ir::llvm::DILocalVariableAttr::static_kind():
      tp = &(gTypes[873]);
      break;

    case mx::ir::llvm::DINamespaceAttr::static_kind():
      tp = &(gTypes[874]);
      break;

    case mx::ir::llvm::DINullTypeAttr::static_kind():
      tp = &(gTypes[875]);
      break;

    case mx::ir::llvm::DISubprogramAttr::static_kind():
      tp = &(gTypes[876]);
      break;

    case mx::ir::llvm::DISubrangeAttr::static_kind():
      tp = &(gTypes[877]);
      break;

    case mx::ir::llvm::DISubroutineTypeAttr::static_kind():
      tp = &(gTypes[878]);
      break;

    case mx::ir::llvm::FastmathFlagsAttr::static_kind():
      tp = &(gTypes[879]);
      break;

    case mx::ir::llvm::MemoryEffectsAttr::static_kind():
      tp = &(gTypes[880]);
      break;

    case mx::ir::llvm::TBAAMemberAttr::static_kind():
      tp = &(gTypes[881]);
      break;

    case mx::ir::llvm::TBAARootAttr::static_kind():
      tp = &(gTypes[882]);
      break;

    case mx::ir::llvm::TBAATagAttr::static_kind():
      tp = &(gTypes[883]);
      break;

    case mx::ir::llvm::TBAATypeDescriptorAttr::static_kind():
      tp = &(gTypes[884]);
      break;

    case mx::ir::llvm::LinkageAttr::static_kind():
      tp = &(gTypes[885]);
      break;

    case mx::ir::llvm::LoopAnnotationAttr::static_kind():
      tp = &(gTypes[886]);
      break;

    case mx::ir::llvm::LoopDistributeAttr::static_kind():
      tp = &(gTypes[887]);
      break;

    case mx::ir::llvm::LoopInterleaveAttr::static_kind():
      tp = &(gTypes[888]);
      break;

    case mx::ir::llvm::LoopLICMAttr::static_kind():
      tp = &(gTypes[889]);
      break;

    case mx::ir::llvm::LoopPeeledAttr::static_kind():
      tp = &(gTypes[890]);
      break;

    case mx::ir::llvm::LoopPipelineAttr::static_kind():
      tp = &(gTypes[891]);
      break;

    case mx::ir::llvm::LoopUnrollAndJamAttr::static_kind():
      tp = &(gTypes[892]);
      break;

    case mx::ir::llvm::LoopUnrollAttr::static_kind():
      tp = &(gTypes[893]);
      break;

    case mx::ir::llvm::LoopUnswitchAttr::static_kind():
      tp = &(gTypes[894]);
      break;

    case mx::ir::llvm::LoopVectorizeAttr::static_kind():
      tp = &(gTypes[895]);
      break;

    case mx::ir::hl::AllocAlignAttr::static_kind():
      tp = &(gTypes[897]);
      break;

    case mx::ir::hl::AllocSizeAttr::static_kind():
      tp = &(gTypes[898]);
      break;

    case mx::ir::hl::AnnotationAttr::static_kind():
      tp = &(gTypes[899]);
      break;

    case mx::ir::hl::AsmLabelAttr::static_kind():
      tp = &(gTypes[900]);
      break;

    case mx::ir::hl::BuiltinAttr::static_kind():
      tp = &(gTypes[901]);
      break;

    case mx::ir::hl::CVQualifiersAttr::static_kind():
      tp = &(gTypes[902]);
      break;

    case mx::ir::hl::CVRQualifiersAttr::static_kind():
      tp = &(gTypes[903]);
      break;

    case mx::ir::hl::ConstAttr::static_kind():
      tp = &(gTypes[904]);
      break;

    case mx::ir::hl::FormatAttr::static_kind():
      tp = &(gTypes[905]);
      break;

    case mx::ir::hl::LoaderUninitializedAttr::static_kind():
      tp = &(gTypes[906]);
      break;

    case mx::ir::hl::ModeAttr::static_kind():
      tp = &(gTypes[907]);
      break;

    case mx::ir::hl::NoInstrumentFunctionAttr::static_kind():
      tp = &(gTypes[908]);
      break;

    case mx::ir::hl::NoThrowAttr::static_kind():
      tp = &(gTypes[909]);
      break;

    case mx::ir::hl::NonNullAttr::static_kind():
      tp = &(gTypes[910]);
      break;

    case mx::ir::hl::PackedAttr::static_kind():
      tp = &(gTypes[911]);
      break;

    case mx::ir::hl::PureAttr::static_kind():
      tp = &(gTypes[912]);
      break;

    case mx::ir::hl::RestrictAttr::static_kind():
      tp = &(gTypes[913]);
      break;

    case mx::ir::hl::SectionAttr::static_kind():
      tp = &(gTypes[914]);
      break;

    case mx::ir::hl::UCVQualifiersAttr::static_kind():
      tp = &(gTypes[915]);
      break;

    case mx::ir::hl::WarnUnusedResultAttr::static_kind():
      tp = &(gTypes[916]);
      break;

    case mx::ir::core::BooleanAttr::static_kind():
      tp = &(gTypes[918]);
      break;

    case mx::ir::core::FloatAttr::static_kind():
      tp = &(gTypes[919]);
      break;

    case mx::ir::core::IntegerAttr::static_kind():
      tp = &(gTypes[920]);
      break;

    case mx::ir::core::SourceLanguageAttr::static_kind():
      tp = &(gTypes[921]);
      break;

    case mx::ir::core::StringLiteralAttr::static_kind():
      tp = &(gTypes[922]);
      break;

    case mx::ir::core::VoidAttr::static_kind():
      tp = &(gTypes[923]);
      break;

    case mx::ir::meta::IdentifierAttr::static_kind():
      tp = &(gTypes[925]);
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
  if (0 != PyModule_AddObjectRef(module, "Attribute", tp_obj)) {
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
    PyDoc_STR("Wrapper for mx::ir::Attribute::kind"),
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
  PyTypeObject * const tp = &(gTypes[835]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.Attribute";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::::Attribute");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PyObject_HashNotImplemented;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = nullptr;
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Attribute.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Attribute.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Attribute' cannot be directly instantiated";
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
