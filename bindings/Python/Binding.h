// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <cstdint>
#include <span>
#include <string>
#include <string_view>
#include <vector>

#include <multiplier/Bindings/Python.h>
#include <multiplier/Types.h>

#pragma GCC visibility push(hidden)
namespace mx {

template <typename T>
struct PythonBinding {
 public:
  // The type of this python object.
  static PyTypeObject *type;

  // Load this type into its parent module.
  static bool load(BorrowedPyObject *module) noexcept;

  // Convert a python object to its unwrapped form.
  static std::optional<T> from_python(BorrowedPyObject *obj) noexcept;

  // Wrap a value of type `T` as a python object.
  static SharedPyObject *to_python(const T &val) noexcept;
};

template <typename T>
struct PythonBinding<const T &> final : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<const T> final : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<T &> final : public PythonBinding<T> {};

template <typename T>
struct PythonBinding<std::optional<T>> final : protected PythonBinding<T> {
 public:
  using PythonBinding<T>::type;

  // Convert a python object to its unwrapped form.
  inline static std::optional<std::optional<T>> from_python(
      BorrowedPyObject *obj) noexcept {
    std::optional<T> ret;
    if (Py_IsNone(obj)) {
      return ret;
    } else {
      ret.emplace(PythonBinding<T>::from_python(obj));
    }
    return ret;
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(const std::optional<T> &val) noexcept {
    if (!val) {
      Py_RETURN_NONE;
    }
    return PythonBinding<T>::to_python(val.value());
  }
};

#define MX_DECLARE_BUILTIN_BINDING(type_name, py_type) \
    template <> \
    struct PythonBinding<type_name> { \
     public: \
      static constexpr PyTypeObject * const type = &py_type; \
      \
      static std::optional<type_name> from_python( \
          BorrowedPyObject *obj) noexcept; \
      \
      static SharedPyObject *to_python(type_name val) noexcept; \
    };

MX_DECLARE_BUILTIN_BINDING(int8_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(int16_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(int32_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(int64_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(uint8_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(uint16_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(uint32_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(uint64_t, PyLong_Type)
MX_DECLARE_BUILTIN_BINDING(float, PyFloat_Type)
MX_DECLARE_BUILTIN_BINDING(double, PyFloat_Type)

#undef MX_DECLARE_BUILTIN_BINDING

// Entity IDs are integer like.
template <>
struct PythonBinding<EntityId> : protected PythonBinding<RawEntityId> {
 public:
  using PythonBinding<RawEntityId>::type;

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
struct PythonBinding<SpecificEntityId<T>> final 
    : protected PythonBinding<EntityId> {
 public:
  using PythonBinding<EntityId>::type;

  inline static std::optional<EntityId> from_python(
      BorrowedPyObject *obj) noexcept {
    if (auto ret = PythonBinding<EntityId>::from_python(obj)) {
      return ret->Extract<T>();
    }
    return std::nullopt;
  }

  // Wrap a value of type `T` as a python object.
  inline static SharedPyObject *to_python(SpecificEntityId<T> val) noexcept {
    return PythonBinding<RawEntityId>::to_python(val.Pack());
  }
};

// Conversions for strings. Note that we use `std::string_view` as the
// input type for `to_python`.
template <>
struct PythonBinding<std::string> {
 public:
  static constexpr PyTypeObject * const type = &PyUnicode_Type;
  static std::optional<std::string> from_python(BorrowedPyObject *obj) noexcept;
  static SharedPyObject *to_python(std::string_view val) noexcept;
};

// Conversions for string views.
template <>
struct PythonBinding<std::string_view> final
    : public PythonBinding<std::string> {};

// Conversions for vectors.
template <typename T>
struct PythonBinding<std::vector<T>> {
 public:
  static constexpr PyTypeObject * const type = &PyList_Type;

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

  static SharedPyObject *to_python(std::span<T> val) noexcept {
    std::vector<SharedPyObject *> new_elements;
    SharedPyObject *list = nullptr;
    Py_ssize_t i = 0;

    for (const T &elem : val) {
      auto elem_obj = PythonBinding<T>::to_python(elem);
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
struct PythonBinding<std::span<T>> final
    : public PythonBinding<std::vector<T>> {};

}  // namespace mx
#pragma GCC visibility pop

// Implementations of `to_python` and `from_python` are visible outside of
// this shared library.
namespace mx {

template <typename T>
SharedPyObject *to_python(const T &val) noexcept {
  return PythonBinding<T>::to_python(val);
}

template <typename T>
std::optional<T> from_python(BorrowedPyObject *obj) noexcept {
  return PythonBinding<T>::from_python(obj);
}

}  // namespace mx
