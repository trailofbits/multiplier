// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST/Expr.h>

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
using T = mx::Expr;

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
  if (tp < &(gTypes[560]) || tp >= &(gTypes[692])) {
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

    case mx::DesignatedInitUpdateExpr::static_kind():
      tp = &(gTypes[561]);
      break;

    case mx::DesignatedInitExpr::static_kind():
      tp = &(gTypes[562]);
      break;

    case mx::DependentScopeDeclRefExpr::static_kind():
      tp = &(gTypes[563]);
      break;

    case mx::DependentCoawaitExpr::static_kind():
      tp = &(gTypes[564]);
      break;

    case mx::DeclRefExpr::static_kind():
      tp = &(gTypes[565]);
      break;

    case mx::CoawaitExpr::static_kind():
      tp = &(gTypes[567]);
      break;

    case mx::CoyieldExpr::static_kind():
      tp = &(gTypes[568]);
      break;

    case mx::ConvertVectorExpr::static_kind():
      tp = &(gTypes[569]);
      break;

    case mx::ConceptSpecializationExpr::static_kind():
      tp = &(gTypes[570]);
      break;

    case mx::CompoundLiteralExpr::static_kind():
      tp = &(gTypes[571]);
      break;

    case mx::ChooseExpr::static_kind():
      tp = &(gTypes[572]);
      break;

    case mx::CharacterLiteral::static_kind():
      tp = &(gTypes[573]);
      break;

    case mx::ImplicitCastExpr::static_kind():
      tp = &(gTypes[575]);
      break;

    case mx::CXXDynamicCastExpr::static_kind():
      tp = &(gTypes[578]);
      break;

    case mx::CXXConstCastExpr::static_kind():
      tp = &(gTypes[579]);
      break;

    case mx::CXXAddrspaceCastExpr::static_kind():
      tp = &(gTypes[580]);
      break;

    case mx::CXXStaticCastExpr::static_kind():
      tp = &(gTypes[581]);
      break;

    case mx::CXXReinterpretCastExpr::static_kind():
      tp = &(gTypes[582]);
      break;

    case mx::CXXFunctionalCastExpr::static_kind():
      tp = &(gTypes[583]);
      break;

    case mx::CStyleCastExpr::static_kind():
      tp = &(gTypes[584]);
      break;

    case mx::BuiltinBitCastExpr::static_kind():
      tp = &(gTypes[585]);
      break;

    case mx::ObjCBridgedCastExpr::static_kind():
      tp = &(gTypes[586]);
      break;

    case mx::CallExpr::static_kind():
      tp = &(gTypes[587]);
      break;

    case mx::CXXOperatorCallExpr::static_kind():
      tp = &(gTypes[588]);
      break;

    case mx::CXXMemberCallExpr::static_kind():
      tp = &(gTypes[589]);
      break;

    case mx::CUDAKernelCallExpr::static_kind():
      tp = &(gTypes[590]);
      break;

    case mx::UserDefinedLiteral::static_kind():
      tp = &(gTypes[591]);
      break;

    case mx::CXXUuidofExpr::static_kind():
      tp = &(gTypes[592]);
      break;

    case mx::CXXUnresolvedConstructExpr::static_kind():
      tp = &(gTypes[593]);
      break;

    case mx::CXXTypeidExpr::static_kind():
      tp = &(gTypes[594]);
      break;

    case mx::CXXThrowExpr::static_kind():
      tp = &(gTypes[595]);
      break;

    case mx::CXXThisExpr::static_kind():
      tp = &(gTypes[596]);
      break;

    case mx::CXXStdInitializerListExpr::static_kind():
      tp = &(gTypes[597]);
      break;

    case mx::CXXScalarValueInitExpr::static_kind():
      tp = &(gTypes[598]);
      break;

    case mx::CXXRewrittenBinaryOperator::static_kind():
      tp = &(gTypes[599]);
      break;

    case mx::CXXPseudoDestructorExpr::static_kind():
      tp = &(gTypes[600]);
      break;

    case mx::CXXParenListInitExpr::static_kind():
      tp = &(gTypes[601]);
      break;

    case mx::CXXNullPtrLiteralExpr::static_kind():
      tp = &(gTypes[602]);
      break;

    case mx::CXXNoexceptExpr::static_kind():
      tp = &(gTypes[603]);
      break;

    case mx::CXXNewExpr::static_kind():
      tp = &(gTypes[604]);
      break;

    case mx::CXXInheritedCtorInitExpr::static_kind():
      tp = &(gTypes[605]);
      break;

    case mx::CXXFoldExpr::static_kind():
      tp = &(gTypes[606]);
      break;

    case mx::CXXDependentScopeMemberExpr::static_kind():
      tp = &(gTypes[607]);
      break;

    case mx::CXXDeleteExpr::static_kind():
      tp = &(gTypes[608]);
      break;

    case mx::CXXDefaultInitExpr::static_kind():
      tp = &(gTypes[609]);
      break;

    case mx::CXXDefaultArgExpr::static_kind():
      tp = &(gTypes[610]);
      break;

    case mx::CXXConstructExpr::static_kind():
      tp = &(gTypes[611]);
      break;

    case mx::CXXTemporaryObjectExpr::static_kind():
      tp = &(gTypes[612]);
      break;

    case mx::CXXBoolLiteralExpr::static_kind():
      tp = &(gTypes[613]);
      break;

    case mx::CXXBindTemporaryExpr::static_kind():
      tp = &(gTypes[614]);
      break;

    case mx::BlockExpr::static_kind():
      tp = &(gTypes[615]);
      break;

    case mx::BinaryOperator::static_kind():
      tp = &(gTypes[616]);
      break;

    case mx::CompoundAssignOperator::static_kind():
      tp = &(gTypes[617]);
      break;

    case mx::AtomicExpr::static_kind():
      tp = &(gTypes[618]);
      break;

    case mx::AsTypeExpr::static_kind():
      tp = &(gTypes[619]);
      break;

    case mx::ArrayTypeTraitExpr::static_kind():
      tp = &(gTypes[620]);
      break;

    case mx::ArraySubscriptExpr::static_kind():
      tp = &(gTypes[621]);
      break;

    case mx::ArrayInitLoopExpr::static_kind():
      tp = &(gTypes[622]);
      break;

    case mx::ArrayInitIndexExpr::static_kind():
      tp = &(gTypes[623]);
      break;

    case mx::AddrLabelExpr::static_kind():
      tp = &(gTypes[624]);
      break;

    case mx::ConditionalOperator::static_kind():
      tp = &(gTypes[626]);
      break;

    case mx::BinaryConditionalOperator::static_kind():
      tp = &(gTypes[627]);
      break;

    case mx::VAArgExpr::static_kind():
      tp = &(gTypes[628]);
      break;

    case mx::UnaryOperator::static_kind():
      tp = &(gTypes[629]);
      break;

    case mx::UnaryExprOrTypeTraitExpr::static_kind():
      tp = &(gTypes[630]);
      break;

    case mx::TypoExpr::static_kind():
      tp = &(gTypes[631]);
      break;

    case mx::TypeTraitExpr::static_kind():
      tp = &(gTypes[632]);
      break;

    case mx::SubstNonTypeTemplateParmPackExpr::static_kind():
      tp = &(gTypes[633]);
      break;

    case mx::SubstNonTypeTemplateParmExpr::static_kind():
      tp = &(gTypes[634]);
      break;

    case mx::StringLiteral::static_kind():
      tp = &(gTypes[635]);
      break;

    case mx::StmtExpr::static_kind():
      tp = &(gTypes[636]);
      break;

    case mx::SourceLocExpr::static_kind():
      tp = &(gTypes[637]);
      break;

    case mx::SizeOfPackExpr::static_kind():
      tp = &(gTypes[638]);
      break;

    case mx::ShuffleVectorExpr::static_kind():
      tp = &(gTypes[639]);
      break;

    case mx::SYCLUniqueStableNameExpr::static_kind():
      tp = &(gTypes[640]);
      break;

    case mx::RequiresExpr::static_kind():
      tp = &(gTypes[641]);
      break;

    case mx::RecoveryExpr::static_kind():
      tp = &(gTypes[642]);
      break;

    case mx::PseudoObjectExpr::static_kind():
      tp = &(gTypes[643]);
      break;

    case mx::PredefinedExpr::static_kind():
      tp = &(gTypes[644]);
      break;

    case mx::ParenListExpr::static_kind():
      tp = &(gTypes[645]);
      break;

    case mx::ParenExpr::static_kind():
      tp = &(gTypes[646]);
      break;

    case mx::PackExpansionExpr::static_kind():
      tp = &(gTypes[647]);
      break;

    case mx::UnresolvedMemberExpr::static_kind():
      tp = &(gTypes[649]);
      break;

    case mx::UnresolvedLookupExpr::static_kind():
      tp = &(gTypes[650]);
      break;

    case mx::OpaqueValueExpr::static_kind():
      tp = &(gTypes[651]);
      break;

    case mx::OffsetOfExpr::static_kind():
      tp = &(gTypes[652]);
      break;

    case mx::ObjCSubscriptRefExpr::static_kind():
      tp = &(gTypes[653]);
      break;

    case mx::ObjCStringLiteral::static_kind():
      tp = &(gTypes[654]);
      break;

    case mx::ObjCSelectorExpr::static_kind():
      tp = &(gTypes[655]);
      break;

    case mx::ObjCProtocolExpr::static_kind():
      tp = &(gTypes[656]);
      break;

    case mx::ObjCPropertyRefExpr::static_kind():
      tp = &(gTypes[657]);
      break;

    case mx::ObjCMessageExpr::static_kind():
      tp = &(gTypes[658]);
      break;

    case mx::ObjCIvarRefExpr::static_kind():
      tp = &(gTypes[659]);
      break;

    case mx::ObjCIsaExpr::static_kind():
      tp = &(gTypes[660]);
      break;

    case mx::ObjCIndirectCopyRestoreExpr::static_kind():
      tp = &(gTypes[661]);
      break;

    case mx::ObjCEncodeExpr::static_kind():
      tp = &(gTypes[662]);
      break;

    case mx::ObjCDictionaryLiteral::static_kind():
      tp = &(gTypes[663]);
      break;

    case mx::ObjCBoxedExpr::static_kind():
      tp = &(gTypes[664]);
      break;

    case mx::ObjCBoolLiteralExpr::static_kind():
      tp = &(gTypes[665]);
      break;

    case mx::ObjCAvailabilityCheckExpr::static_kind():
      tp = &(gTypes[666]);
      break;

    case mx::ObjCArrayLiteral::static_kind():
      tp = &(gTypes[667]);
      break;

    case mx::OMPIteratorExpr::static_kind():
      tp = &(gTypes[668]);
      break;

    case mx::OMPArrayShapingExpr::static_kind():
      tp = &(gTypes[669]);
      break;

    case mx::OMPArraySectionExpr::static_kind():
      tp = &(gTypes[670]);
      break;

    case mx::NoInitExpr::static_kind():
      tp = &(gTypes[671]);
      break;

    case mx::MemberExpr::static_kind():
      tp = &(gTypes[672]);
      break;

    case mx::MatrixSubscriptExpr::static_kind():
      tp = &(gTypes[673]);
      break;

    case mx::MaterializeTemporaryExpr::static_kind():
      tp = &(gTypes[674]);
      break;

    case mx::MSPropertySubscriptExpr::static_kind():
      tp = &(gTypes[675]);
      break;

    case mx::MSPropertyRefExpr::static_kind():
      tp = &(gTypes[676]);
      break;

    case mx::LambdaExpr::static_kind():
      tp = &(gTypes[677]);
      break;

    case mx::IntegerLiteral::static_kind():
      tp = &(gTypes[678]);
      break;

    case mx::InitListExpr::static_kind():
      tp = &(gTypes[679]);
      break;

    case mx::ImplicitValueInitExpr::static_kind():
      tp = &(gTypes[680]);
      break;

    case mx::ImaginaryLiteral::static_kind():
      tp = &(gTypes[681]);
      break;

    case mx::GenericSelectionExpr::static_kind():
      tp = &(gTypes[682]);
      break;

    case mx::GNUNullExpr::static_kind():
      tp = &(gTypes[683]);
      break;

    case mx::FunctionParmPackExpr::static_kind():
      tp = &(gTypes[684]);
      break;

    case mx::ExprWithCleanups::static_kind():
      tp = &(gTypes[686]);
      break;

    case mx::ConstantExpr::static_kind():
      tp = &(gTypes[687]);
      break;

    case mx::FloatingLiteral::static_kind():
      tp = &(gTypes[688]);
      break;

    case mx::FixedPointLiteral::static_kind():
      tp = &(gTypes[689]);
      break;

    case mx::ExtVectorElementExpr::static_kind():
      tp = &(gTypes[690]);
      break;

    case mx::ExpressionTraitExpr::static_kind():
      tp = &(gTypes[691]);
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
  if (0 != PyModule_AddObjectRef(module, "Expr", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {
    "has_side_effects",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_side_effects());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::has_side_effects"),
    nullptr,
  },
  {
    "ignore_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_casts"),
    nullptr,
  },
  {
    "ignore_conversion_operator_single_step",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_conversion_operator_single_step());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_conversion_operator_single_step"),
    nullptr,
  },
  {
    "ignore_implicit_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit_casts"),
    nullptr,
  },
  {
    "ignore_implicit",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit"),
    nullptr,
  },
  {
    "ignore_implicit_as_written",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_implicit_as_written());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_implicit_as_written"),
    nullptr,
  },
  {
    "ignore_parenthesis_base_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_base_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_base_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_implicit_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_implicit_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_implicit_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_l_value_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_l_value_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_l_value_casts"),
    nullptr,
  },
  {
    "ignore_parenthesis_noop_casts",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parenthesis_noop_casts());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parenthesis_noop_casts"),
    nullptr,
  },
  {
    "ignore_parentheses",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_parentheses());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_parentheses"),
    nullptr,
  },
  {
    "ignore_unless_spelled_in_source",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ignore_unless_spelled_in_source());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::ignore_unless_spelled_in_source"),
    nullptr,
  },
  {
    "contains_errors",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_errors());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::contains_errors"),
    nullptr,
  },
  {
    "contains_unexpanded_parameter_pack",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->contains_unexpanded_parameter_pack());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::contains_unexpanded_parameter_pack"),
    nullptr,
  },
  {
    "expression_token",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->expression_token());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::expression_token"),
    nullptr,
  },
  {
    "obj_c_property",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->obj_c_property());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::obj_c_property"),
    nullptr,
  },
  {
    "object_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->object_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::object_kind"),
    nullptr,
  },
  {
    "referenced_declaration_of_callee",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->referenced_declaration_of_callee());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::referenced_declaration_of_callee"),
    nullptr,
  },
  {
    "source_bit_field",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->source_bit_field());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::source_bit_field"),
    nullptr,
  },
  {
    "type",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->type());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::type"),
    nullptr,
  },
  {
    "value_kind",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->value_kind());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::value_kind"),
    nullptr,
  },
  {
    "has_non_trivial_call",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->has_non_trivial_call());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::has_non_trivial_call"),
    nullptr,
  },
  {
    "is_default_argument",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_default_argument());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_default_argument"),
    nullptr,
  },
  {
    "is_gl_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_gl_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_gl_value"),
    nullptr,
  },
  {
    "is_implicit_cxx_this",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_implicit_cxx_this());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_implicit_cxx_this"),
    nullptr,
  },
  {
    "is_instantiation_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_instantiation_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_instantiation_dependent"),
    nullptr,
  },
  {
<<<<<<< HEAD
=======
    "is_known_to_have_boolean_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_known_to_have_boolean_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_known_to_have_boolean_value"),
    nullptr,
  },
  {
>>>>>>> 5fb8049e8 (Update python bindings.)
    "is_l_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_l_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_l_value"),
    nullptr,
  },
  {
    "is_objcgc_candidate",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_objcgc_candidate());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_objcgc_candidate"),
    nullptr,
  },
  {
    "is_obj_c_self_expression",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_obj_c_self_expression());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_obj_c_self_expression"),
    nullptr,
  },
  {
    "is_ordinary_or_bit_field_object",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_ordinary_or_bit_field_object());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_ordinary_or_bit_field_object"),
    nullptr,
  },
  {
    "is_pr_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_pr_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_pr_value"),
    nullptr,
  },
  {
    "is_read_if_discarded_in_c_plus_plus11",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_read_if_discarded_in_c_plus_plus11());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_read_if_discarded_in_c_plus_plus11"),
    nullptr,
  },
  {
    "is_type_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_type_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_type_dependent"),
    nullptr,
  },
  {
    "is_value_dependent",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_value_dependent());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_value_dependent"),
    nullptr,
  },
  {
    "is_x_value",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_x_value());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::is_x_value"),
    nullptr,
  },
  {
    "refers_to_bit_field",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_bit_field());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_bit_field"),
    nullptr,
  },
  {
    "refers_to_global_register_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_global_register_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_global_register_variable"),
    nullptr,
  },
  {
    "refers_to_matrix_element",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_matrix_element());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_matrix_element"),
    nullptr,
  },
  {
    "refers_to_vector_element",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->refers_to_vector_element());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::Expr::refers_to_vector_element"),
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
    PyDoc_STR("Wrapper for mx::Expr::in"),
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
    PyDoc_STR("Wrapper for mx::Expr::containing"),
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
    PyDoc_STR("Wrapper for mx::Expr::by_id"),
  },
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::ir::Operation>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(T::from(arg_0.value()));
          }
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
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation, mx::ir::Operation>>(args[0]);
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
    PyDoc_STR("Wrapper for mx::Expr::from"),
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
    PyDoc_STR("Wrapper for mx::Expr::from_base"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[560]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.Expr";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::Expr");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[558].tp_hash;
  tp->tp_richcompare = gTypes[558].tp_richcompare;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[558]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Expr.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Expr.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Expr' cannot be directly instantiated";
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
