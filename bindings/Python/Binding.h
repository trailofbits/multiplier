// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <filesystem>
#include <map>
#include <new>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>

#include <Python.h>
#include <multiplier/Bindings/Python.h>
#include <multiplier/Entity.h>

#include "Error.h"
#include "TokenTreeVisitor.h"

namespace mx {

class RegexQueryMatch;
class TokenRange;

template <typename T>
struct PythonBinding {
 public:
  // The type of this python object.
  static PyTypeObject *type(void) noexcept;

  // Load this type into its parent module.
  static bool load(BorrowedPyObject *module) noexcept;

  // Convert a python object to its unwrapped form.
  static std::optional<T> from_python(BorrowedPyObject *obj) noexcept;

  // Wrap a value of type `T` as a python object.
  static SharedPyObject *to_python(T val) noexcept;
};

template <typename T>
struct PythonBinding<const T &> : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<const T> : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<T &> : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<T *>  /* No definition */;

template <typename T>
struct PythonBinding<std::optional<T>> {
 public:

  // Convert a python object to its unwrapped form.
  inline static std::optional<std::optional<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    if (Py_IsNone(obj)) {
      return std::optional<T>{};
    } else if (auto val = PythonBinding<T>::from_python(obj)) {
      return std::move(val.value());
    } else {
      return std::nullopt;
    }
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(std::optional<T> val) noexcept {
    if (!val) {
      Py_RETURN_NONE;
    }
    return PythonBinding<T>::to_python(std::move(val.value()));
  }
};

#define MX_DECLARE_BUILTIN_BINDING(type_name) \
    template <> \
    struct PythonBinding<type_name> { \
     public: \
      static std::optional<type_name> from_python( \
          BorrowedPyObject *obj) noexcept; \
      \
      static SharedPyObject *to_python(type_name val) noexcept; \
    };

MX_DECLARE_BUILTIN_BINDING(bool)
MX_DECLARE_BUILTIN_BINDING(char)
MX_DECLARE_BUILTIN_BINDING(short)
MX_DECLARE_BUILTIN_BINDING(int)
MX_DECLARE_BUILTIN_BINDING(long)
MX_DECLARE_BUILTIN_BINDING(long long)
MX_DECLARE_BUILTIN_BINDING(unsigned char)
MX_DECLARE_BUILTIN_BINDING(unsigned short)
MX_DECLARE_BUILTIN_BINDING(unsigned)
MX_DECLARE_BUILTIN_BINDING(unsigned long)
MX_DECLARE_BUILTIN_BINDING(unsigned long long)
MX_DECLARE_BUILTIN_BINDING(float)
MX_DECLARE_BUILTIN_BINDING(double)
MX_DECLARE_BUILTIN_BINDING(std::monostate)

// Variant entity IDs are unpacked entities, which we can pack down into
// integers in Python to simply not expose them.
MX_DECLARE_BUILTIN_BINDING(VariantId)

#undef MX_DECLARE_BUILTIN_BINDING

// Implements a generic base class for Multiplier's entity types. This doesn't
// actually exist in the C++ API.
template <>
struct PythonBinding<VariantEntity> {
 public:
  // The type of this python object.
  static PyTypeObject *type(void) noexcept;

  // Load this type into its parent module.
  static bool load(BorrowedPyObject *module) noexcept;

  // Convert a python object to its unwrapped form.
  static std::optional<VariantEntity> from_python(BorrowedPyObject *obj) noexcept;

  // Wrap a value of type `VariantEntity` as a python object.
  static SharedPyObject *to_python(VariantEntity val) noexcept;
};

// Entity IDs are integer like.
template <>
struct PythonBinding<EntityId> {
 public:
  inline static std::optional<EntityId> from_python(
      BorrowedPyObject *obj) noexcept {
    if (auto ret = PythonBinding<RawEntityId>::from_python(obj)) {
      return EntityId(ret.value());
    }
    return std::nullopt;
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(EntityId val) noexcept {
    return PythonBinding<RawEntityId>::to_python(val.Pack());
  }
};

// Packed or specific entity IDs are known to be of a specific category, and the
// category is carried in the template type parameter.
template <typename T>
struct PythonBinding<SpecificEntityId<T>> {
 public:
  inline static std::optional<SpecificEntityId<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    if (auto ret = PythonBinding<EntityId>::from_python(obj)) {
      if (auto id = ret->Extract<T>()) {
        return SpecificEntityId<T>(id.value());
      }
    }
    return std::nullopt;
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(SpecificEntityId<T> val) noexcept {
    return PythonBinding<RawEntityId>::to_python(val.Pack());
  }
};

// Handle token tree visitors. These have virtual methods, so when we convert
// from Python, we actually return a `ProxyTokenTreeVisitor`.
//
// NOTE(pag): The methods are implemented in `TokenTreeVisitor.cpp`.
template <>
struct PythonBinding<ProxyTokenTreeVisitor> {
 public:
  // Load this type into its parent module.
  static bool load(BorrowedPyObject *module) noexcept;

  static std::optional<ProxyTokenTreeVisitor> from_python( 
      BorrowedPyObject *obj) noexcept;
};

// Handle a pair.
template <typename A, typename B>
struct PythonBinding<std::pair<A, B>> {
 public:
  inline static std::optional<std::pair<A, B>> from_python(
      BorrowedPyObject *obj) noexcept {
    if (!PySequence_Check(obj) || 2 != PySequence_Size(obj)) {
      return std::nullopt;
    }

    SharedPyObject *a_obj = PySequence_GetItem(obj, 0);
    SharedPyObject *b_obj = PySequence_GetItem(obj, 1);

    auto a = PythonBinding<A>::from_python(a_obj);
    auto b = PythonBinding<B>::from_python(b_obj);

    Py_DECREF(a_obj);
    Py_DECREF(b_obj);

    if (!a || !b) {
      return std::nullopt;
    }

    return std::make_pair<A, B>(std::move(a.value()), std::move(b.value()));
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(std::pair<A, B> val) noexcept {
    SharedPyObject *a_obj = PythonBinding<A>::to_python(std::move(val.first));
    SharedPyObject *b_obj = PythonBinding<B>::to_python(std::move(val.second));
    auto ret = PyTuple_Pack(2, a_obj, b_obj);
    Py_DECREF(a_obj);
    Py_DECREF(b_obj);
    return ret;
  }
};

// Generic variants. Note that we handle `VariantId` and `VariantEntity`
// above.
template <typename... Types>
struct PythonBinding<std::variant<Types...>> {
 public:
  inline static std::optional<std::variant<Types...>> from_python(
      BorrowedPyObject *obj) noexcept {

    auto set_item = [] (auto &ret, auto opt_val) {
      if (opt_val) {
        ret.emplace(std::move(opt_val.value()));
      }
      return 1;
    };

    std::optional<std::variant<Types...>> ret;
    (void) (1 + ... + set_item(ret, PythonBinding<Types>::from_python(obj)));

    return ret;
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(std::variant<Types...> val) noexcept {
    return std::visit([] (auto &&arg) -> SharedPyObject * {
      using T = std::decay_t<decltype(arg)>;
      return PythonBinding<T>::to_python(std::move(arg));
    }, std::move(val));
  }
};

// Conversions for strings. Note that we use `std::string_view` as the
// input type for `to_python`.
template <>
struct PythonBinding<std::string> {
 public:
  static std::optional<std::string> from_python(BorrowedPyObject *obj) noexcept;
  static SharedPyObject *to_python(std::string_view val) noexcept;
};

// Conversions for string views.
template <>
struct PythonBinding<std::string_view> : public PythonBinding<std::string> {};

// Conversions for paths.
template <>
struct PythonBinding<std::filesystem::path> {
 public:
  static PyTypeObject *type;
  static std::optional<std::filesystem::path> from_python(
      BorrowedPyObject *obj) noexcept;
  static SharedPyObject *to_python(std::filesystem::path val) noexcept;
};

// Conversions for vectors.
template <typename T>
struct PythonBinding<std::vector<T>> {
 public:
  static std::optional<std::vector<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    auto iter = PyObject_GetIter(obj);
    if (!iter) {
      PyErr_Clear();
      return std::nullopt;
    }

    std::vector<T> elements;
    while (auto item = PyIter_Next(iter)) {
      auto elem = PythonBinding<T>::from_python(item);
      Py_DECREF(item);
      if (!elem) {
        Py_DECREF(iter);
        return std::nullopt;
      }

      elements.emplace_back(std::move(elem.value()));
    }

    Py_DECREF(iter);
    return elements;
  }

  static SharedPyObject *to_python(std::vector<T> val) noexcept {
    std::vector<SharedPyObject *> new_elements;
    SharedPyObject *list = nullptr;
    Py_ssize_t i = 0;

    for (T &elem : val) {
      auto elem_obj = PythonBinding<T>::to_python(std::move(elem));
      if (!elem_obj) {
        goto unwind;
      }
      
      new_elements.emplace_back(elem_obj);
    }

    list = PyList_New(static_cast<Py_ssize_t>(new_elements.size()));
    for (auto elem_obj : new_elements) {
      PyList_SetItem(list, i++, elem_obj);
    }
    return list;

  unwind:
    while (!new_elements.empty()) {
      Py_DECREF(new_elements.back());
      new_elements.pop_back();
    }
    return nullptr;
  }
};

// Conversions for spans.
template <typename T>
struct PythonBinding<std::span<T>> {
 public:
  static std::optional<std::vector<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    return PythonBinding<std::vector<T>>::from_python(obj);
  }
};

// Conversions for spans.
template <typename T>
struct PythonBinding<std::span<const T>> {
 public:
  static std::optional<std::vector<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    return PythonBinding<std::vector<T>>::from_python(obj);
  }
};

// Conversions for maps.
template <typename KVMap, typename K, typename V>
struct MapPythonBinding {
 public:
  static std::optional<KVMap> from_python(BorrowedPyObject *obj) noexcept {
    Py_ssize_t i = 0;
    PyObject *key = nullptr;
    PyObject *val = nullptr;

    KVMap elements;
    while (PyDict_Next(obj, &i, &key, &val)) {
      auto k = PythonBinding<K>::from_python(key);
      auto v = PythonBinding<V>::from_python(val);
      if (!k || !v) {
        return std::nullopt;
      }
      elements.emplace(std::move(k.value()), std::move(v.value()));
    }

    return elements;
  }

  static SharedPyObject *to_python(KVMap elements) noexcept {
    SharedPyObject *map = PyDict_New();

    for (auto &entry : elements) {
      auto key = PythonBinding<K>::to_python(std::move(entry.first));
      if (!key) {
        Py_DECREF(map);
        return nullptr;
      }
      
      auto val = PythonBinding<V>::to_python(std::move(entry.second));
      if (!val) {
        Py_DECREF(key);
        Py_DECREF(map);
        return nullptr;
      }
      
      auto ret = PyDict_SetItem(map, key, val);
      Py_DECREF(val);
      if (-1 == ret) {
        Py_DECREF(map);
        return nullptr;
      }
    }

    return map;
  }
};

template <typename K, typename V>
struct PythonBinding<std::map<K, V>>
    : public MapPythonBinding<std::map<K, V>, K, V> {};

template <typename K, typename V>
struct PythonBinding<std::unordered_map<K, V>>
    : public MapPythonBinding<std::unordered_map<K, V>, K, V> {};

// Conversions for maps.
template <typename Set, typename T>
struct SetPythonBinding {
 public:
  static std::optional<Set> from_python(BorrowedPyObject *obj) noexcept {
    auto iter = PyObject_GetIter(obj);
    if (!iter) {
      PyErr_Clear();
      return std::nullopt;
    }

    Set elements;
    while (auto item = PyIter_Next(iter)) {
      auto elem = PythonBinding<T>::from_python(item);
      Py_DECREF(item);
      if (!elem) {
        Py_DECREF(iter);
        return std::nullopt;
      }

      elements.emplace_back(std::move(elem.value()));
    }

    Py_DECREF(iter);
    return elements;
  }

  static SharedPyObject *to_python(Set val) noexcept {
    SharedPyObject *set = PySet_New(nullptr);

    for (auto &entry : val) {
      auto key = PythonBinding<T>::to_python(std::move(entry));
      if (!key) {
        Py_DECREF(set);
        return nullptr;
      }

      if (-1 == PySet_Add(set, key)) {
        Py_DECREF(set);
        return nullptr;
      }
    }

    return set;
  }
};

template <typename K>
struct PythonBinding<std::set<K>> : public SetPythonBinding<std::set<K>, K> {};

template <typename K>
struct PythonBinding<std::unordered_set<K>>
    : public SetPythonBinding<std::unordered_set<K>, K> {};

template<typename T>
concept ForwardIteratorProtocol = requires(T x) {

  // Multiplier-specific restrictions, i.e. that this isn't a `TokenRange`,
  // because we'll wrap that specifically.
  std::enable_if_t<!std::is_same_v<T, TokenRange>, int>(1);
  std::enable_if_t<!std::is_same_v<T, RegexQueryMatch>, int>(1);

  // General forward iterator protocol compatible with ranged `for` loops.
  x.begin();
  x.end();
  x.begin() != x.end();
  *std::declval<decltype(x.begin())>();
  ++std::declval<decltype(x.begin())>();
};

template <typename RangeType>
struct RangePythonBinding {
  using BeginType = std::decay_t<decltype(std::declval<RangeType>().begin())>;
  using EndType = std::decay_t<decltype(std::declval<RangeType>().end())>;

  using T = std::remove_cvref_t<
      decltype(*std::declval<RangeType>().begin())>;

  // Python object that can hold an iterator range.
  struct IterRange final : public ::PyObject {
    RangeType *range{nullptr};
    BeginType *it{nullptr};
    EndType *end{nullptr};
    alignas(alignof(RangeType)) char range_storage[sizeof(RangeType)];
    alignas(alignof(BeginType)) char it_storage[sizeof(BeginType)];
    alignas(alignof(EndType)) char end_storage[sizeof(EndType)];
  };

  static bool gInitialized;
  static bool gSucceeded;
  static PyTypeObject gRangeType;
  static PyTypeObject gIterType;

  static bool InitType(void) {
    if (gInitialized) {
      return gSucceeded;
    }

    gInitialized = true;
    auto module = ::mx::python_module();
    if (!module) {
      return false;
    }

    // Define the range type. It holds the range before Python has asked for
    // iteration.
    gRangeType.tp_name = typeid(RangeType).name();
    gRangeType.tp_basicsize = sizeof(IterRange);
    gRangeType.tp_itemsize = 0;
    gRangeType.tp_init = nullptr;
    gRangeType.tp_new = nullptr;
    gRangeType.tp_flags = Py_TPFLAGS_DEFAULT |
                          Py_TPFLAGS_DISALLOW_INSTANTIATION |
                          Py_TPFLAGS_IMMUTABLETYPE;
    gRangeType.tp_alloc = PyType_GenericAlloc;

    gRangeType.tp_dealloc = [] (BorrowedPyObject *obj) {
      if (auto *data = reinterpret_cast<IterRange *>(obj)) {
        data->it->~BeginType();
        data->end->~EndType();
        data->range->~RangeType();
      }
      PyObject_Free(obj);
    };

    gRangeType.tp_iter = [] (BorrowedPyObject *obj) {
      Py_INCREF(obj);
      return obj;
    };

    gRangeType.tp_iternext = [] (BorrowedPyObject *obj) -> SharedPyObject * {
      auto iter_obj = reinterpret_cast<IterRange *>(obj);
      BeginType &it = *(iter_obj->it);
      EndType &end = *(iter_obj->end);
      if (it == end) {
        PyErr_SetNone(PyExc_StopIteration);
        return nullptr;
      }

      auto ret = ::mx::to_python<T>(*it);
      ++it;
      return ret;
    };

    if (0 != PyType_Ready(&gRangeType)) {
      return false;
    }

    auto rt = reinterpret_cast<BorrowedPyObject *>(&gRangeType);
    if (0 != PyModule_AddObjectRef(module, gRangeType.tp_name, rt)) {
      return false;
    }

    gSucceeded = true;
    return true;
  }

  static SharedPyObject *to_python(RangeType val) noexcept {
    if (!InitType()) {
      if (!PyErr_Occurred()) {
        PyErrorStreamer(PyExc_TypeError)
            << "Unable to wrap iterator range type '"
            << typeid(RangeType).name() << "'";
      }
      return nullptr;
    }

    auto obj = gRangeType.tp_alloc(&gRangeType, 0);
    if (auto range = reinterpret_cast<IterRange *>(obj)) {
      range->range = new (range->range_storage) RangeType(std::move(val));
      range->it = new (range->it_storage) BeginType(range->range->begin());
      range->end = new (range->end_storage) EndType(range->range->end());
    }

    return obj;
  }
};

template <typename RangeType>
bool RangePythonBinding<RangeType>::gInitialized = false;

template <typename RangeType>
bool RangePythonBinding<RangeType>::gSucceeded = false;

template <typename RangeType>
PyTypeObject RangePythonBinding<RangeType>::gRangeType = {};

// Conversions for iterables, e.g. `gap::generator`, or other ones.
//
// NOTE(pag): Separated from `RangePythonBinding` because concepts don't seem to
//            play well with out-of-line static member definitions.
template <ForwardIteratorProtocol RangeType>
struct PythonBinding<RangeType> : public RangePythonBinding<RangeType> {};

template <typename T>
SharedPyObject *to_python(T val) noexcept {
  return PythonBinding<T>::to_python(std::move(val));
}

template <typename T>
std::optional<T> from_python(BorrowedPyObject *obj) noexcept {
  return PythonBinding<T>::from_python(obj);
}

}  // namespace mx
