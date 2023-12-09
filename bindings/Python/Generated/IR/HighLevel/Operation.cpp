// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/IR/HighLevel/Operation.h>

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
using T = mx::ir::hl::Operation;

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
  if (tp < &(gTypes[1241]) || tp >= &(gTypes[1354])) {
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

    case mx::ir::hl::AccessSpecifierOp::static_kind():
      tp = &(gTypes[1242]);
      break;

    case mx::ir::hl::AddFAssignOp::static_kind():
      tp = &(gTypes[1243]);
      break;

    case mx::ir::hl::AddFOp::static_kind():
      tp = &(gTypes[1244]);
      break;

    case mx::ir::hl::AddIAssignOp::static_kind():
      tp = &(gTypes[1245]);
      break;

    case mx::ir::hl::AddIOp::static_kind():
      tp = &(gTypes[1246]);
      break;

    case mx::ir::hl::AddrLabelExprOp::static_kind():
      tp = &(gTypes[1247]);
      break;

    case mx::ir::hl::AddressOfOp::static_kind():
      tp = &(gTypes[1248]);
      break;

    case mx::ir::hl::AlignOfExprOp::static_kind():
      tp = &(gTypes[1249]);
      break;

    case mx::ir::hl::AlignOfTypeOp::static_kind():
      tp = &(gTypes[1250]);
      break;

    case mx::ir::hl::AsmOp::static_kind():
      tp = &(gTypes[1251]);
      break;

    case mx::ir::hl::AssignOp::static_kind():
      tp = &(gTypes[1252]);
      break;

    case mx::ir::hl::BinAShrAssignOp::static_kind():
      tp = &(gTypes[1253]);
      break;

    case mx::ir::hl::BinAShrOp::static_kind():
      tp = &(gTypes[1254]);
      break;

    case mx::ir::hl::BinAndAssignOp::static_kind():
      tp = &(gTypes[1255]);
      break;

    case mx::ir::hl::BinAndOp::static_kind():
      tp = &(gTypes[1256]);
      break;

    case mx::ir::hl::BinCommaOp::static_kind():
      tp = &(gTypes[1257]);
      break;

    case mx::ir::hl::BinLAndOp::static_kind():
      tp = &(gTypes[1258]);
      break;

    case mx::ir::hl::BinLOrOp::static_kind():
      tp = &(gTypes[1259]);
      break;

    case mx::ir::hl::BinLShrAssignOp::static_kind():
      tp = &(gTypes[1260]);
      break;

    case mx::ir::hl::BinLShrOp::static_kind():
      tp = &(gTypes[1261]);
      break;

    case mx::ir::hl::BinOrAssignOp::static_kind():
      tp = &(gTypes[1262]);
      break;

    case mx::ir::hl::BinOrOp::static_kind():
      tp = &(gTypes[1263]);
      break;

    case mx::ir::hl::BinShlAssignOp::static_kind():
      tp = &(gTypes[1264]);
      break;

    case mx::ir::hl::BinShlOp::static_kind():
      tp = &(gTypes[1265]);
      break;

    case mx::ir::hl::BinXorAssignOp::static_kind():
      tp = &(gTypes[1266]);
      break;

    case mx::ir::hl::BinXorOp::static_kind():
      tp = &(gTypes[1267]);
      break;

    case mx::ir::hl::BuiltinBitCastOp::static_kind():
      tp = &(gTypes[1268]);
      break;

    case mx::ir::hl::CStyleCastOp::static_kind():
      tp = &(gTypes[1269]);
      break;

    case mx::ir::hl::CallOp::static_kind():
      tp = &(gTypes[1270]);
      break;

    case mx::ir::hl::ClassDeclOp::static_kind():
      tp = &(gTypes[1271]);
      break;

    case mx::ir::hl::CmpOp::static_kind():
      tp = &(gTypes[1272]);
      break;

    case mx::ir::hl::ConstantOp::static_kind():
      tp = &(gTypes[1273]);
      break;

    case mx::ir::hl::CxxBaseSpecifierOp::static_kind():
      tp = &(gTypes[1274]);
      break;

    case mx::ir::hl::CxxStructDeclOp::static_kind():
      tp = &(gTypes[1275]);
      break;

    case mx::ir::hl::DeclRefOp::static_kind():
      tp = &(gTypes[1276]);
      break;

    case mx::ir::hl::DerefOp::static_kind():
      tp = &(gTypes[1277]);
      break;

    case mx::ir::hl::DivFAssignOp::static_kind():
      tp = &(gTypes[1278]);
      break;

    case mx::ir::hl::DivFOp::static_kind():
      tp = &(gTypes[1279]);
      break;

    case mx::ir::hl::DivSAssignOp::static_kind():
      tp = &(gTypes[1280]);
      break;

    case mx::ir::hl::DivSOp::static_kind():
      tp = &(gTypes[1281]);
      break;

    case mx::ir::hl::DivUAssignOp::static_kind():
      tp = &(gTypes[1282]);
      break;

    case mx::ir::hl::DivUOp::static_kind():
      tp = &(gTypes[1283]);
      break;

    case mx::ir::hl::EnumConstantOp::static_kind():
      tp = &(gTypes[1284]);
      break;

    case mx::ir::hl::EnumDeclOp::static_kind():
      tp = &(gTypes[1285]);
      break;

    case mx::ir::hl::EnumRefOp::static_kind():
      tp = &(gTypes[1286]);
      break;

    case mx::ir::hl::ExprOp::static_kind():
      tp = &(gTypes[1287]);
      break;

    case mx::ir::hl::ExtensionOp::static_kind():
      tp = &(gTypes[1288]);
      break;

    case mx::ir::hl::FCmpOp::static_kind():
      tp = &(gTypes[1289]);
      break;

    case mx::ir::hl::FieldDeclOp::static_kind():
      tp = &(gTypes[1290]);
      break;

    case mx::ir::hl::FuncRefOp::static_kind():
      tp = &(gTypes[1291]);
      break;

    case mx::ir::hl::GlobalRefOp::static_kind():
      tp = &(gTypes[1292]);
      break;

    case mx::ir::hl::BreakOp::static_kind():
      tp = &(gTypes[1293]);
      break;

    case mx::ir::hl::CaseOp::static_kind():
      tp = &(gTypes[1294]);
      break;

    case mx::ir::hl::CondOp::static_kind():
      tp = &(gTypes[1295]);
      break;

    case mx::ir::hl::CondYieldOp::static_kind():
      tp = &(gTypes[1296]);
      break;

    case mx::ir::hl::ContinueOp::static_kind():
      tp = &(gTypes[1297]);
      break;

    case mx::ir::hl::DefaultOp::static_kind():
      tp = &(gTypes[1298]);
      break;

    case mx::ir::hl::DoOp::static_kind():
      tp = &(gTypes[1299]);
      break;

    case mx::ir::hl::EmptyDeclOp::static_kind():
      tp = &(gTypes[1300]);
      break;

    case mx::ir::hl::ForOp::static_kind():
      tp = &(gTypes[1301]);
      break;

    case mx::ir::hl::FuncOp::static_kind():
      tp = &(gTypes[1302]);
      break;

    case mx::ir::hl::GotoStmtOp::static_kind():
      tp = &(gTypes[1303]);
      break;

    case mx::ir::hl::IfOp::static_kind():
      tp = &(gTypes[1304]);
      break;

    case mx::ir::hl::LabelDeclOp::static_kind():
      tp = &(gTypes[1305]);
      break;

    case mx::ir::hl::LabelStmtOp::static_kind():
      tp = &(gTypes[1306]);
      break;

    case mx::ir::hl::SkipStmtOp::static_kind():
      tp = &(gTypes[1307]);
      break;

    case mx::ir::hl::SwitchOp::static_kind():
      tp = &(gTypes[1308]);
      break;

    case mx::ir::hl::TypeYieldOp::static_kind():
      tp = &(gTypes[1309]);
      break;

    case mx::ir::hl::ValueYieldOp::static_kind():
      tp = &(gTypes[1310]);
      break;

    case mx::ir::hl::VarDeclOp::static_kind():
      tp = &(gTypes[1311]);
      break;

    case mx::ir::hl::WhileOp::static_kind():
      tp = &(gTypes[1312]);
      break;

    case mx::ir::hl::ImplicitCastOp::static_kind():
      tp = &(gTypes[1313]);
      break;

    case mx::ir::hl::IndirectCallOp::static_kind():
      tp = &(gTypes[1314]);
      break;

    case mx::ir::hl::InitListExprOp::static_kind():
      tp = &(gTypes[1315]);
      break;

    case mx::ir::hl::LNotOp::static_kind():
      tp = &(gTypes[1316]);
      break;

    case mx::ir::hl::MinusOp::static_kind():
      tp = &(gTypes[1317]);
      break;

    case mx::ir::hl::MulFAssignOp::static_kind():
      tp = &(gTypes[1318]);
      break;

    case mx::ir::hl::MulFOp::static_kind():
      tp = &(gTypes[1319]);
      break;

    case mx::ir::hl::MulIAssignOp::static_kind():
      tp = &(gTypes[1320]);
      break;

    case mx::ir::hl::MulIOp::static_kind():
      tp = &(gTypes[1321]);
      break;

    case mx::ir::hl::NotOp::static_kind():
      tp = &(gTypes[1322]);
      break;

    case mx::ir::hl::PlusOp::static_kind():
      tp = &(gTypes[1323]);
      break;

    case mx::ir::hl::PostDecOp::static_kind():
      tp = &(gTypes[1324]);
      break;

    case mx::ir::hl::PostIncOp::static_kind():
      tp = &(gTypes[1325]);
      break;

    case mx::ir::hl::PreDecOp::static_kind():
      tp = &(gTypes[1326]);
      break;

    case mx::ir::hl::PreIncOp::static_kind():
      tp = &(gTypes[1327]);
      break;

    case mx::ir::hl::PredefinedExprOp::static_kind():
      tp = &(gTypes[1328]);
      break;

    case mx::ir::hl::RecordMemberOp::static_kind():
      tp = &(gTypes[1329]);
      break;

    case mx::ir::hl::RemFAssignOp::static_kind():
      tp = &(gTypes[1330]);
      break;

    case mx::ir::hl::RemFOp::static_kind():
      tp = &(gTypes[1331]);
      break;

    case mx::ir::hl::RemSAssignOp::static_kind():
      tp = &(gTypes[1332]);
      break;

    case mx::ir::hl::RemSOp::static_kind():
      tp = &(gTypes[1333]);
      break;

    case mx::ir::hl::RemUAssignOp::static_kind():
      tp = &(gTypes[1334]);
      break;

    case mx::ir::hl::RemUOp::static_kind():
      tp = &(gTypes[1335]);
      break;

    case mx::ir::hl::ReturnOp::static_kind():
      tp = &(gTypes[1336]);
      break;

    case mx::ir::hl::SizeOfExprOp::static_kind():
      tp = &(gTypes[1337]);
      break;

    case mx::ir::hl::SizeOfTypeOp::static_kind():
      tp = &(gTypes[1338]);
      break;

    case mx::ir::hl::StmtExprOp::static_kind():
      tp = &(gTypes[1339]);
      break;

    case mx::ir::hl::StructDeclOp::static_kind():
      tp = &(gTypes[1340]);
      break;

    case mx::ir::hl::SubFAssignOp::static_kind():
      tp = &(gTypes[1341]);
      break;

    case mx::ir::hl::SubFOp::static_kind():
      tp = &(gTypes[1342]);
      break;

    case mx::ir::hl::SubIAssignOp::static_kind():
      tp = &(gTypes[1343]);
      break;

    case mx::ir::hl::SubIOp::static_kind():
      tp = &(gTypes[1344]);
      break;

    case mx::ir::hl::SubscriptOp::static_kind():
      tp = &(gTypes[1345]);
      break;

    case mx::ir::hl::ThisOp::static_kind():
      tp = &(gTypes[1346]);
      break;

    case mx::ir::hl::TranslationUnitOp::static_kind():
      tp = &(gTypes[1347]);
      break;

    case mx::ir::hl::TypeDeclOp::static_kind():
      tp = &(gTypes[1348]);
      break;

    case mx::ir::hl::TypeDefOp::static_kind():
      tp = &(gTypes[1349]);
      break;

    case mx::ir::hl::TypeOfExprOp::static_kind():
      tp = &(gTypes[1350]);
      break;

    case mx::ir::hl::TypeOfTypeOp::static_kind():
      tp = &(gTypes[1351]);
      break;

    case mx::ir::hl::UnionDeclOp::static_kind():
      tp = &(gTypes[1352]);
      break;

    case mx::ir::hl::UnreachableOp::static_kind():
      tp = &(gTypes[1353]);
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
  if (0 != PyModule_AddObjectRef(module, "Operation", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyGetSetDef gProperties[] = {
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyMethodDef gMethods[] = {
  {
    "FROM",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::ir::Operation>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'FROM'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::hl::Operation::from"),
  },
  {
    "first_from",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Decl>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->first_from(arg_0.value()));
          }
          while (num_args == 2) {
            auto arg_0 = PythonBinding<mx::Decl>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = PythonBinding<mx::ir::OperationKind>::from_python(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->first_from(arg_0.value(), arg_1.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->first_from(arg_0.value()));
          }
          while (num_args == 2) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = PythonBinding<mx::ir::OperationKind>::from_python(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->first_from(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'first_from'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::hl::Operation::first_from"),
  },
  {
    "all_from",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Decl>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->all_from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = PythonBinding<mx::Stmt>::from_python(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->all_from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'all_from'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::ir::hl::Operation::all_from"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[1241]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ir.highlevel.Operation";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::ir::hl::::Operation");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = gTypes[931].tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = &(gTypes[931]);
  tp->tp_init = [] (BorrowedPyObject *self, BorrowedPyObject *args, BorrowedPyObject *kwargs) -> int {
    if (kwargs && (!PyMapping_Check(kwargs) || PyMapping_Size(kwargs))) {
      PyErrorStreamer(PyExc_TypeError)
          << "'Operation.__init__' does not take any keyword arguments";
      return -1;
    }

    if (!args || !PySequence_Check(args)) {
      PyErrorStreamer(PyExc_TypeError)
          << "Invalid positional arguments passed to 'Operation.__init__'";
      return -1;
    }

    auto obj = O_cast(self);
    auto num_args = PySequence_Size(args);
    
    (void) obj;
    (void) num_args;
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'Operation' cannot be directly instantiated";
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
