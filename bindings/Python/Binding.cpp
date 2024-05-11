// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <cmath>

#include <multiplier/Entity.h>

namespace mx {

std::optional<bool> PythonBinding<bool>::from_python(
    BorrowedPyObject *obj) noexcept {

  auto truthy = PyObject_IsTrue(obj);
  if (-1 == truthy) {
    PyErr_Clear();
    return std::nullopt;
  }

  return !!truthy;
}

SharedPyObject *PythonBinding<bool>::to_python(bool val) noexcept {
  if (val) {
    Py_RETURN_TRUE;
  } else {
    Py_RETURN_FALSE;
  }
}

#define MAKE_INTEGRAL_CONVERTER(type_name, longest_type, from_func) \
    std::optional<type_name> PythonBinding<type_name>::from_python( \
        BorrowedPyObject *obj) noexcept { \
      \
      if (!PyLong_Check(obj)) { \
        return std::nullopt; \
      } \
      \
      int did_overflow = 0; \
      const auto ret = static_cast<longest_type>( \
          PyLong_AsLongLongAndOverflow(obj, &did_overflow)); \
      if (did_overflow) { \
        PyErr_Clear(); \
      } \
      const auto ret_casted = static_cast<type_name>(ret); \
      if (ret != ret_casted) { \
        return std::nullopt; \
      } \
      \
      return ret_casted; \
    } \
    \
    SharedPyObject *PythonBinding<type_name>::to_python( \
        type_name val) noexcept { \
      return from_func(static_cast<longest_type>(val)); \
    }


MAKE_INTEGRAL_CONVERTER(char, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(short, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(int, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(long, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(long long, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(unsigned char, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(unsigned short, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(unsigned, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(unsigned long, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(unsigned long long, uint64_t, PyLong_FromUnsignedLongLong)

std::optional<float> PythonBinding<float>::from_python(
    BorrowedPyObject *obj) noexcept {
  PyErr_Clear();
  auto ret = PyFloat_AsDouble(obj);
  if (PyErr_Occurred()) {
    PyErr_Clear();
    return std::nullopt;
  }

  auto ret_float = static_cast<float>(ret);
  auto residual = ret - static_cast<double>(ret_float);
  if (fabs(residual) >= 0.1) {  // YOLO.
    return std::nullopt;
  }

  return ret_float;
}

SharedPyObject *PythonBinding<float>::to_python(float val) noexcept {
  return PyFloat_FromDouble(static_cast<double>(val));
}

std::optional<double> PythonBinding<double>::from_python(
    BorrowedPyObject *obj) noexcept {
  PyErr_Clear();
  auto ret = PyFloat_AsDouble(obj);
  if (PyErr_Occurred()) {
    PyErr_Clear();
    return std::nullopt;
  }

  return ret;
}

SharedPyObject *PythonBinding<double>::to_python(double val) noexcept {
  return PyFloat_FromDouble(val);
}

std::optional<std::monostate> PythonBinding<std::monostate>::from_python(
    BorrowedPyObject *obj) noexcept {
  if (obj != Py_None) {
    return std::nullopt;
  }

  return std::monostate{};
}

SharedPyObject *PythonBinding<std::monostate>::to_python(
    std::monostate) noexcept {
  Py_RETURN_NONE;
}

std::optional<VariantId> PythonBinding<VariantId>::from_python(
    BorrowedPyObject *obj) noexcept {
  auto int_val = PythonBinding<RawEntityId>::from_python(obj);
  if (!int_val) {
    return std::nullopt;
  }

  return EntityId(int_val.value()).Unpack();
}

SharedPyObject *PythonBinding<VariantId>::to_python(VariantId val) noexcept {
  return PythonBinding<RawEntityId>::to_python(EntityId(val).Pack());
}

std::optional<std::string> PythonBinding<std::string>::from_python(
    BorrowedPyObject *obj) noexcept {
  if (PyBytes_Check(obj)) {
    const auto size = PyBytes_Size(obj);
    const auto data = PyBytes_AsString(obj);
    return std::string(data, &(data[size]));

  } else if (PyUnicode_Check(obj)) {
    auto utf8 = PyUnicode_AsUTF8String(obj);
    if (!utf8) {
      return std::nullopt;
    }

    char *data = nullptr;
    Py_ssize_t size = 0;
    if (PyBytes_AsStringAndSize(utf8, &data, &size)) {
      Py_DECREF(utf8);
      return std::nullopt;
    }

    std::string ret(data, &(data[size]));
    Py_DECREF(utf8);
    return ret;

  } else {
    return std::nullopt;
  }
}

SharedPyObject *PythonBinding<std::string>::to_python(
    std::string_view val) noexcept {

  auto val_data = "";
  Py_ssize_t val_len = static_cast<Py_ssize_t>(val.size());
  if (val_len) {
    val_data = val.data();
  }

  PyErr_Clear();
  SharedPyObject *ret = ::PyUnicode_DecodeUTF8(val_data, val_len, nullptr);
  if (ret && !PyErr_Occurred()) {
    return ret;
  }

  PyErr_Clear();
  ret = PyUnicode_DecodeLocaleAndSize(val_data, val_len, nullptr);
  if (ret && !PyErr_Occurred()) {
    auto new_ret = PyUnicode_AsUTF8String(ret);
    Py_DECREF(ret);
    return new_ret;
  }

  PyErr_Clear();
  ret = PyUnicode_DecodeLatin1(val_data, val_len, nullptr);
  if (ret && !PyErr_Occurred()) {
    auto new_ret = PyUnicode_AsUTF8String(ret);
    Py_DECREF(ret);
    return new_ret;
  }

  return nullptr;
}

namespace {

struct PermRef {
  SharedPyObject *object{nullptr};

  inline ~PermRef(void) {
    // Py_XDECREF(object);  // NOTE(pag): Crashes.
    object = nullptr;
  }

  inline operator bool(void) const noexcept {
    return object;
  }
};

static PermRef gPurePath;
static PermRef gPathLib;

static void InitPurePath(void) {
  if (!gPathLib) {
    gPathLib.object = PyImport_ImportModule("pathlib");
  }

  if (!gPurePath) {
    gPurePath.object = PyObject_GetAttrString(gPathLib.object, "PurePath");
  }
}

}  // namespace

std::optional<std::filesystem::path>
PythonBinding<std::filesystem::path>::from_python(
    BorrowedPyObject *obj) noexcept {
  InitPurePath();
  if (PyObject_IsInstance(obj, gPurePath.object)) {
    if (auto str_obj = PyObject_Str(obj)) {
      if (auto str = ::mx::from_python<std::string>(str_obj)) {
        Py_DECREF(str_obj);
        return std::filesystem::path(std::move(str.value()));
      }
      Py_DECREF(str_obj);
    }

  } else if (auto str = ::mx::from_python<std::string>(obj)) {
    return std::filesystem::path(std::move(str.value()));
  }

  PyErr_Clear();
  return std::nullopt;
}

SharedPyObject *PythonBinding<std::filesystem::path>::to_python(
    std::filesystem::path val) noexcept {
  InitPurePath();
  return PyObject_CallFunction(gPurePath.object, "s",
                               val.generic_string().c_str());
}

}  // namespace mx
