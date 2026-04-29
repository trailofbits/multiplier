// Copyright (c) 2023-present, Trail of Bits, Inc.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/ValueStmt.h>

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
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
using T = mx::ValueStmt;

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
  if (tp < &(gTypes[640]) || tp >= &(gTypes[775])) {
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

    case mx::LabelStmt::static_kind():
      tp = &(gTypes[641]);
      break;

    case mx::DesignatedInitUpdateExpr::static_kind():
      tp = &(gTypes[643]);
      break;

    case mx::DesignatedInitExpr::static_kind():
      tp = &(gTypes[644]);
      break;

    case mx::DependentScopeDeclRefExpr::static_kind():
      tp = &(gTypes[645]);
      break;

    case mx::DependentCoawaitExpr::static_kind():
      tp = &(gTypes[646]);
      break;

    case mx::DeclRefExpr::static_kind():
      tp = &(gTypes[647]);
      break;

    case mx::CoawaitExpr::static_kind():
      tp = &(gTypes[649]);
      break;

    case mx::CoyieldExpr::static_kind():
      tp = &(gTypes[650]);
      break;

    case mx::ConvertVectorExpr::static_kind():
      tp = &(gTypes[651]);
      break;

    case mx::ConceptSpecializationExpr::static_kind():
      tp = &(gTypes[652]);
      break;

    case mx::CompoundLiteralExpr::static_kind():
      tp = &(gTypes[653]);
      break;

    case mx::ChooseExpr::static_kind():
      tp = &(gTypes[654]);
      break;

    case mx::CharacterLiteral::static_kind():
      tp = &(gTypes[655]);
      break;

    case mx::ImplicitCastExpr::static_kind():
      tp = &(gTypes[657]);
      break;

    case mx::CXXDynamicCastExpr::static_kind():
      tp = &(gTypes[660]);
      break;

    case mx::CXXConstCastExpr::static_kind():
      tp = &(gTypes[661]);
      break;

    case mx::CXXAddrspaceCastExpr::static_kind():
      tp = &(gTypes[662]);
      break;

    case mx::CXXStaticCastExpr::static_kind():
      tp = &(gTypes[663]);
      break;

    case mx::CXXReinterpretCastExpr::static_kind():
      tp = &(gTypes[664]);
      break;

    case mx::CXXFunctionalCastExpr::static_kind():
      tp = &(gTypes[665]);
      break;

    case mx::CStyleCastExpr::static_kind():
      tp = &(gTypes[666]);
      break;

    case mx::BuiltinBitCastExpr::static_kind():
      tp = &(gTypes[667]);
      break;

    case mx::ObjCBridgedCastExpr::static_kind():
      tp = &(gTypes[668]);
      break;

    case mx::CallExpr::static_kind():
      tp = &(gTypes[669]);
      break;

    case mx::CXXOperatorCallExpr::static_kind():
      tp = &(gTypes[670]);
      break;

    case mx::CXXMemberCallExpr::static_kind():
      tp = &(gTypes[671]);
      break;

    case mx::CUDAKernelCallExpr::static_kind():
      tp = &(gTypes[672]);
      break;

    case mx::UserDefinedLiteral::static_kind():
      tp = &(gTypes[673]);
      break;

    case mx::CXXUuidofExpr::static_kind():
      tp = &(gTypes[674]);
      break;

    case mx::CXXUnresolvedConstructExpr::static_kind():
      tp = &(gTypes[675]);
      break;

    case mx::CXXTypeidExpr::static_kind():
      tp = &(gTypes[676]);
      break;

    case mx::CXXThrowExpr::static_kind():
      tp = &(gTypes[677]);
      break;

    case mx::CXXThisExpr::static_kind():
      tp = &(gTypes[678]);
      break;

    case mx::CXXStdInitializerListExpr::static_kind():
      tp = &(gTypes[679]);
      break;

    case mx::CXXScalarValueInitExpr::static_kind():
      tp = &(gTypes[680]);
      break;

    case mx::CXXRewrittenBinaryOperator::static_kind():
      tp = &(gTypes[681]);
      break;

    case mx::CXXPseudoDestructorExpr::static_kind():
      tp = &(gTypes[682]);
      break;

    case mx::CXXParenListInitExpr::static_kind():
      tp = &(gTypes[683]);
      break;

    case mx::CXXNullPtrLiteralExpr::static_kind():
      tp = &(gTypes[684]);
      break;

    case mx::CXXNoexceptExpr::static_kind():
      tp = &(gTypes[685]);
      break;

    case mx::CXXNewExpr::static_kind():
      tp = &(gTypes[686]);
      break;

    case mx::CXXInheritedCtorInitExpr::static_kind():
      tp = &(gTypes[687]);
      break;

    case mx::CXXFoldExpr::static_kind():
      tp = &(gTypes[688]);
      break;

    case mx::CXXDependentScopeMemberExpr::static_kind():
      tp = &(gTypes[689]);
      break;

    case mx::CXXDeleteExpr::static_kind():
      tp = &(gTypes[690]);
      break;

    case mx::CXXDefaultInitExpr::static_kind():
      tp = &(gTypes[691]);
      break;

    case mx::CXXDefaultArgExpr::static_kind():
      tp = &(gTypes[692]);
      break;

    case mx::CXXConstructExpr::static_kind():
      tp = &(gTypes[693]);
      break;

    case mx::CXXTemporaryObjectExpr::static_kind():
      tp = &(gTypes[694]);
      break;

    case mx::CXXBoolLiteralExpr::static_kind():
      tp = &(gTypes[695]);
      break;

    case mx::CXXBindTemporaryExpr::static_kind():
      tp = &(gTypes[696]);
      break;

    case mx::BlockExpr::static_kind():
      tp = &(gTypes[697]);
      break;

    case mx::BinaryOperator::static_kind():
      tp = &(gTypes[698]);
      break;

    case mx::CompoundAssignOperator::static_kind():
      tp = &(gTypes[699]);
      break;

    case mx::AtomicExpr::static_kind():
      tp = &(gTypes[700]);
      break;

    case mx::AsTypeExpr::static_kind():
      tp = &(gTypes[701]);
      break;

    case mx::ArrayTypeTraitExpr::static_kind():
      tp = &(gTypes[702]);
      break;

    case mx::ArraySubscriptExpr::static_kind():
      tp = &(gTypes[703]);
      break;

    case mx::ArrayInitLoopExpr::static_kind():
      tp = &(gTypes[704]);
      break;

    case mx::ArrayInitIndexExpr::static_kind():
      tp = &(gTypes[705]);
      break;

    case mx::AddrLabelExpr::static_kind():
      tp = &(gTypes[706]);
      break;

    case mx::ConditionalOperator::static_kind():
      tp = &(gTypes[708]);
      break;

    case mx::BinaryConditionalOperator::static_kind():
      tp = &(gTypes[709]);
      break;

    case mx::VAArgExpr::static_kind():
      tp = &(gTypes[710]);
      break;

    case mx::UnaryOperator::static_kind():
      tp = &(gTypes[711]);
      break;

    case mx::UnaryExprOrTypeTraitExpr::static_kind():
      tp = &(gTypes[712]);
      break;

    case mx::TypoExpr::static_kind():
      tp = &(gTypes[713]);
      break;

    case mx::TypeTraitExpr::static_kind():
      tp = &(gTypes[714]);
      break;

    case mx::SubstNonTypeTemplateParmPackExpr::static_kind():
      tp = &(gTypes[715]);
      break;

    case mx::SubstNonTypeTemplateParmExpr::static_kind():
      tp = &(gTypes[716]);
      break;

    case mx::StringLiteral::static_kind():
      tp = &(gTypes[717]);
      break;

    case mx::StmtExpr::static_kind():
      tp = &(gTypes[718]);
      break;

    case mx::SourceLocExpr::static_kind():
      tp = &(gTypes[719]);
      break;

    case mx::SizeOfPackExpr::static_kind():
      tp = &(gTypes[720]);
      break;

    case mx::ShuffleVectorExpr::static_kind():
      tp = &(gTypes[721]);
      break;

    case mx::SYCLUniqueStableNameExpr::static_kind():
      tp = &(gTypes[722]);
      break;

    case mx::RequiresExpr::static_kind():
      tp = &(gTypes[723]);
      break;

    case mx::RecoveryExpr::static_kind():
      tp = &(gTypes[724]);
      break;

    case mx::PseudoObjectExpr::static_kind():
      tp = &(gTypes[725]);
      break;

    case mx::PredefinedExpr::static_kind():
      tp = &(gTypes[726]);
      break;

    case mx::ParenListExpr::static_kind():
      tp = &(gTypes[727]);
      break;

    case mx::ParenExpr::static_kind():
      tp = &(gTypes[728]);
      break;

    case mx::PackExpansionExpr::static_kind():
      tp = &(gTypes[729]);
      break;

    case mx::UnresolvedMemberExpr::static_kind():
      tp = &(gTypes[731]);
      break;

    case mx::UnresolvedLookupExpr::static_kind():
      tp = &(gTypes[732]);
      break;

    case mx::OpaqueValueExpr::static_kind():
      tp = &(gTypes[733]);
      break;

    case mx::OffsetOfExpr::static_kind():
      tp = &(gTypes[734]);
      break;

    case mx::ObjCSubscriptRefExpr::static_kind():
      tp = &(gTypes[735]);
      break;

    case mx::ObjCStringLiteral::static_kind():
      tp = &(gTypes[736]);
      break;

    case mx::ObjCSelectorExpr::static_kind():
      tp = &(gTypes[737]);
      break;

    case mx::ObjCProtocolExpr::static_kind():
      tp = &(gTypes[738]);
      break;

    case mx::ObjCPropertyRefExpr::static_kind():
      tp = &(gTypes[739]);
      break;

    case mx::ObjCMessageExpr::static_kind():
      tp = &(gTypes[740]);
      break;

    case mx::ObjCIvarRefExpr::static_kind():
      tp = &(gTypes[741]);
      break;

    case mx::ObjCIsaExpr::static_kind():
      tp = &(gTypes[742]);
      break;

    case mx::ObjCIndirectCopyRestoreExpr::static_kind():
      tp = &(gTypes[743]);
      break;

    case mx::ObjCEncodeExpr::static_kind():
      tp = &(gTypes[744]);
      break;

    case mx::ObjCDictionaryLiteral::static_kind():
      tp = &(gTypes[745]);
      break;

    case mx::ObjCBoxedExpr::static_kind():
      tp = &(gTypes[746]);
      break;

    case mx::ObjCBoolLiteralExpr::static_kind():
      tp = &(gTypes[747]);
      break;

    case mx::ObjCAvailabilityCheckExpr::static_kind():
      tp = &(gTypes[748]);
      break;

    case mx::ObjCArrayLiteral::static_kind():
      tp = &(gTypes[749]);
      break;

    case mx::OMPIteratorExpr::static_kind():
      tp = &(gTypes[750]);
      break;

    case mx::OMPArrayShapingExpr::static_kind():
      tp = &(gTypes[751]);
      break;

    case mx::OMPArraySectionExpr::static_kind():
      tp = &(gTypes[752]);
      break;

    case mx::NoInitExpr::static_kind():
      tp = &(gTypes[753]);
      break;

    case mx::MemberExpr::static_kind():
      tp = &(gTypes[754]);
      break;

    case mx::MatrixSubscriptExpr::static_kind():
      tp = &(gTypes[755]);
      break;

    case mx::MaterializeTemporaryExpr::static_kind():
      tp = &(gTypes[756]);
      break;

    case mx::MSPropertySubscriptExpr::static_kind():
      tp = &(gTypes[757]);
      break;

    case mx::MSPropertyRefExpr::static_kind():
      tp = &(gTypes[758]);
      break;

    case mx::LambdaExpr::static_kind():
      tp = &(gTypes[759]);
      break;

    case mx::IntegerLiteral::static_kind():
      tp = &(gTypes[760]);
      break;

    case mx::InitListExpr::static_kind():
      tp = &(gTypes[761]);
      break;

    case mx::ImplicitValueInitExpr::static_kind():
      tp = &(gTypes[762]);
      break;

    case mx::ImaginaryLiteral::static_kind():
      tp = &(gTypes[763]);
      break;

    case mx::GenericSelectionExpr::static_kind():
      tp = &(gTypes[764]);
      break;

    case mx::GNUNullExpr::static_kind():
      tp = &(gTypes[765]);
      break;

    case mx::FunctionParmPackExpr::static_kind():
      tp = &(gTypes[766]);
      break;

    case mx::ExprWithCleanups::static_kind():
      tp = &(gTypes[768]);
      break;

    case mx::ConstantExpr::static_kind():
      tp = &(gTypes[769]);
      break;

    case mx::FloatingLiteral::static_kind():
      tp = &(gTypes[770]);
      break;

    case mx::FixedPointLiteral::static_kind():
      tp = &(gTypes[771]);
      break;

    case mx::ExtVectorElementExpr::static_kind():
      tp = &(gTypes[772]);
      break;

    case mx::ExpressionTraitExpr::static_kind():
      tp = &(gTypes[773]);
      break;

    case mx::AttributedStmt::static_kind():
      tp = &(gTypes[774]);
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
  if (0 != PyModule_AddObjectRef(module, "ValueStmt", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "expression_statement",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->expression_statement());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::ValueStmt::expression_statement"),
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
    PyDoc_STR("Wrapper for mx::ValueStmt::in"),
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
    PyDoc_STR("Wrapper for mx::ValueStmt::containing"),
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
    PyDoc_STR("Wrapper for mx::ValueStmt::by_id"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
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
    PyDoc_STR("Wrapper for mx::ValueStmt::from_base"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
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
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::CXXCtorInitializer, mx::Compilation, mx::IRFunction, mx::IRBlock, mx::IRInstruction, mx::IRObject, mx::IRStructure>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::ValueStmt::from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[640]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.ValueStmt";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::ValueStmt");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[529].tp_hash;
  tp->tp_richcompare = gTypes[529].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[529]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'ValueStmt.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'ValueStmt.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'ValueStmt' cannot be directly instantiated";
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
