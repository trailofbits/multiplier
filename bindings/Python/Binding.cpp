// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Binding.h"

#include <cmath>

namespace mx {

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
      const auto ret_casted = static_cast<type_name>(ret); \
      if (ret != ret_casted || did_overflow) { \
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

MAKE_INTEGRAL_CONVERTER(int8_t, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(int16_t, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(int32_t, int64_t, PyLong_FromLongLong)
MAKE_INTEGRAL_CONVERTER(int64_t, int64_t, PyLong_FromLongLong)

MAKE_INTEGRAL_CONVERTER(uint8_t, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(uint16_t, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(uint32_t, uint64_t, PyLong_FromUnsignedLongLong)
MAKE_INTEGRAL_CONVERTER(uint64_t, uint64_t, PyLong_FromUnsignedLongLong)

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
  Py_ssize_t val_len = 0;
  if (!val.empty()) {
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

}  // namespace mx
