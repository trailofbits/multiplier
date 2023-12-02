// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

// Auto-generated file; do not modify!

#include <multiplier/AST.h>
#include <multiplier/Fragment.h>
#include <multiplier/Frontend.h>
#include <multiplier/Index.h>
#include <multiplier/IR.h>

#include <new>

#include "Binding.h"
#include "Error.h"
#include "Types.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc99-extensions"
#pragma GCC diagnostic ignored "-Wunused-function"
namespace {
using T = mx::OMPLoopDirective;

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
  if (tp < &(gTypes[498]) || tp >= &(gTypes[534])) {
    return std::nullopt;
  }

  return *T_cast(obj);
}

template <>
SharedPyObject *PythonBinding<T>::to_python(T val) noexcept {
  PyTypeObject *tp = nullptr;
  switch (val.kind()) {
    default:
      tp = gType;
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
  if (0 != PyModule_AddObjectRef(module, "OMPLoopDirective", tp_obj)) {
    return false;
  }

  return true;
}

namespace {
static PyMethodDef gMethods[] = {
  {
    "contained_in",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Fragment>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::File>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->in(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'contained_in'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::in"),
  },
  {
    "containing",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Token>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Decl>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Decl>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->containing(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'containing'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::containing"),
  },
  {
    "by_id",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 2) {
            auto arg_0 = ::mx::from_python<mx::Index>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }
            auto arg_1 = ::mx::from_python<mx::EntityId>(args[1]);
            if (!arg_1.has_value()) {
              break;
            }

            return ::mx::to_python(obj->by_id(arg_0.value(), arg_1.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'by_id'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::by_id"),
  },
  {
    "from_base",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from_base(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'from_base'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::from_base"),
  },
  {
    "cast",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Stmt>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::optional<mx::Stmt>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::Reference>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<std::variant<std::monostate, mx::Fragment, mx::Decl, mx::Stmt, mx::Attr, mx::Macro, mx::Type, mx::File, mx::Token, mx::TemplateArgument, mx::TemplateParameterList, mx::CXXBaseSpecifier, mx::Designator, mx::Compilation>>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<mx::TokenContext>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->from(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'cast'";
          return nullptr;
        }),
    METH_FASTCALL | METH_STATIC,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::from"),
  },
  {
    "nth_counter",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_counter(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_counter'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_counter"),
  },
  {
    "nth_dependent_counter",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_dependent_counter(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_dependent_counter'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_dependent_counter"),
  },
  {
    "nth_dependent_initializer",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_dependent_initializer(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_dependent_initializer'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_dependent_initializer"),
  },
  {
    "nth_final",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_final(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_final'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_final"),
  },
  {
    "nth_finals_condition",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_finals_condition(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_finals_condition'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_finals_condition"),
  },
  {
    "nth_initializer",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_initializer(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_initializer'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_initializer"),
  },
  {
    "nth_private_counter",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_private_counter(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_private_counter'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_private_counter"),
  },
  {
    "nth_update",
    reinterpret_cast<PyCFunction>(
        +[] (BorrowedPyObject *self, BorrowedPyObject * const *args, int num_args) -> SharedPyObject * {
          auto obj = T_cast(self);
          (void) args;
          while (num_args == 1) {
            auto arg_0 = ::mx::from_python<uint32_t>(args[0]);
            if (!arg_0.has_value()) {
              break;
            }

            return ::mx::to_python(obj->nth_update(arg_0.value()));
          }

          PyErrorStreamer(PyExc_TypeError)
              << "Invalid arguments passed to 'nth_update'";
          return nullptr;
        }),
    METH_FASTCALL,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::nth_update"),
  },
  {}  // Sentinel.
};
}  // namespace

namespace {
static PyGetSetDef gProperties[] = {
  {
    "num_counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_counters"),
    nullptr,
  },
  {
    "counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::counters"),
    nullptr,
  },
  {
    "num_dependent_counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_dependent_counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_dependent_counters"),
    nullptr,
  },
  {
    "dependent_counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->dependent_counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::dependent_counters"),
    nullptr,
  },
  {
    "num_dependent_initializers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_dependent_initializers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_dependent_initializers"),
    nullptr,
  },
  {
    "dependent_initializers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->dependent_initializers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::dependent_initializers"),
    nullptr,
  },
  {
    "num_finals",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_finals());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_finals"),
    nullptr,
  },
  {
    "finals",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->finals());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::finals"),
    nullptr,
  },
  {
    "num_finals_conditions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_finals_conditions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_finals_conditions"),
    nullptr,
  },
  {
    "finals_conditions",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->finals_conditions());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::finals_conditions"),
    nullptr,
  },
  {
    "body",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->body());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::body"),
    nullptr,
  },
  {
    "calculate_last_iteration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->calculate_last_iteration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::calculate_last_iteration"),
    nullptr,
  },
  {
    "combined_condition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_condition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_condition"),
    nullptr,
  },
  {
    "combined_distance_condition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_distance_condition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_distance_condition"),
    nullptr,
  },
  {
    "combined_ensure_upper_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_ensure_upper_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_ensure_upper_bound"),
    nullptr,
  },
  {
    "combined_initializer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_initializer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_initializer"),
    nullptr,
  },
  {
    "combined_lower_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_lower_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_lower_bound_variable"),
    nullptr,
  },
  {
    "combined_next_lower_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_next_lower_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_next_lower_bound"),
    nullptr,
  },
  {
    "combined_next_upper_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_next_upper_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_next_upper_bound"),
    nullptr,
  },
  {
    "combined_parallel_for_in_distance_condition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_parallel_for_in_distance_condition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_parallel_for_in_distance_condition"),
    nullptr,
  },
  {
    "combined_upper_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->combined_upper_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::combined_upper_bound_variable"),
    nullptr,
  },
  {
    "condition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->condition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::condition"),
    nullptr,
  },
  {
    "distance_increment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->distance_increment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::distance_increment"),
    nullptr,
  },
  {
    "ensure_upper_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->ensure_upper_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::ensure_upper_bound"),
    nullptr,
  },
  {
    "increment",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->increment());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::increment"),
    nullptr,
  },
  {
    "initializer",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->initializer());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::initializer"),
    nullptr,
  },
  {
    "is_last_iteration_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->is_last_iteration_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::is_last_iteration_variable"),
    nullptr,
  },
  {
    "iteration_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->iteration_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::iteration_variable"),
    nullptr,
  },
  {
    "last_iteration",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->last_iteration());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::last_iteration"),
    nullptr,
  },
  {
    "lower_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->lower_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::lower_bound_variable"),
    nullptr,
  },
  {
    "next_lower_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->next_lower_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::next_lower_bound"),
    nullptr,
  },
  {
    "next_upper_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->next_upper_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::next_upper_bound"),
    nullptr,
  },
  {
    "pre_condition",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->pre_condition());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::pre_condition"),
    nullptr,
  },
  {
    "pre_initializers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->pre_initializers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::pre_initializers"),
    nullptr,
  },
  {
    "prev_ensure_upper_bound",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->prev_ensure_upper_bound());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::prev_ensure_upper_bound"),
    nullptr,
  },
  {
    "prev_lower_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->prev_lower_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::prev_lower_bound_variable"),
    nullptr,
  },
  {
    "prev_upper_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->prev_upper_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::prev_upper_bound_variable"),
    nullptr,
  },
  {
    "stride_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->stride_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::stride_variable"),
    nullptr,
  },
  {
    "upper_bound_variable",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->upper_bound_variable());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::upper_bound_variable"),
    nullptr,
  },
  {
    "num_initializers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_initializers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_initializers"),
    nullptr,
  },
  {
    "initializers",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->initializers());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::initializers"),
    nullptr,
  },
  {
    "num_private_counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_private_counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_private_counters"),
    nullptr,
  },
  {
    "private_counters",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->private_counters());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::private_counters"),
    nullptr,
  },
  {
    "num_updates",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->num_updates());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::num_updates"),
    nullptr,
  },
  {
    "updates",
    reinterpret_cast<getter>(
        +[] (BorrowedPyObject *self, void * /* closure */) -> SharedPyObject * {
          return ::mx::to_python(T_cast(self)->updates());
        }),
    nullptr,
    PyDoc_STR("Wrapper for mx::OMPLoopDirective::updates"),
    nullptr,
  },
  {}  // Sentinel.
};
}  // namespace

namespace {

PyTypeObject *InitType(void) noexcept {
  PyTypeObject * const tp = &(gTypes[498]);
  tp->tp_basicsize = sizeof(O);
  tp->tp_itemsize = 0;
  tp->tp_dealloc = [] (::PyObject *obj) {
    if (auto *data = T_cast(obj)) {
      data->~T();
    }
    PyObject_Free(obj);
  };
  tp->tp_name = "multiplier.ast.OMPLoopDirective";
  tp->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_DISALLOW_INSTANTIATION;
  tp->tp_doc = PyDoc_STR("Wrapper for mx::::OMPLoopDirective");
  tp->tp_as_number = nullptr;
  tp->tp_as_sequence = nullptr;
  tp->tp_as_mapping = nullptr;
  tp->tp_hash = PythonBinding<mx::OMPLoopBasedDirective>::type()->tp_hash;
  tp->tp_richcompare = nullptr;
  tp->tp_iter = nullptr;  // TODO
  tp->tp_methods = gMethods;
  tp->tp_getset = gProperties;
  tp->tp_base = PythonBinding<mx::OMPLoopBasedDirective>::type();
  tp->tp_init = [] (BorrowedPyObject *, BorrowedPyObject *, BorrowedPyObject *) -> int {
    PyErrorStreamer(PyExc_TypeError)
        << "Class 'OMPLoopDirective' cannot be directly instantiated";
    return -1;
  };
  tp->tp_alloc = PyType_GenericAlloc;
  tp->tp_new = nullptr;  // Don't allow instantiation.

  if (0 != PyType_Ready(tp)) {
    return nullptr;
  }

  return tp;
}

}  // namespace

#pragma GCC diagnostic pop
}  // namespace mx
