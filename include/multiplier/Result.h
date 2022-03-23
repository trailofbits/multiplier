// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <stdexcept>
#include <variant>

namespace mx {

template <typename ValueType, typename ErrorType>
class Result final {
 private:
  bool destroyed{true};
  mutable bool checked{false};
  std::variant<ValueType, ErrorType> data;

 public:
  Result(void);
  ~Result(void) = default;

  bool Succeeded(void) const;

  const ErrorType &Error(void) const;
  ErrorType TakeError(void);

  const ValueType &Value(void) const;
  ValueType TakeValue(void);

  const ValueType *operator->(void) const;

  Result(const ValueType &value);
  Result(ValueType &&value): destroyed(false), data(std::forward<ValueType>(value)) {}

  Result(const ErrorType &error);
  Result(ErrorType &&error):  destroyed(false), data(std::forward<ErrorType>(error)) {}

  Result(Result &&other) noexcept;
  Result &operator=(Result &&other) noexcept;

  Result(const Result &) = delete;
  Result &operator=(const Result &) = delete;

 private:
  void VerifyState(void) const;
  void VerifyChecked(void) const;
  void VerifyFailed(void) const;
  void VerifySucceeded(void) const;
};

template <typename ValueType, typename ErrorType>
Result<ValueType, ErrorType>::Result(void)
    : checked(true),
      data(ErrorType()) {}

template <typename ValueType, typename ErrorType>
bool Result<ValueType, ErrorType>::Succeeded(void) const {
  VerifyState();

  checked = true;
  return std::holds_alternative<ValueType>(data);
}

template <typename ValueType, typename ErrorType>
const ErrorType &Result<ValueType, ErrorType>::Error(void) const {
  VerifyState();
  VerifyChecked();
  VerifyFailed();

  return std::get<ErrorType>(data);
}

template <typename ValueType, typename ErrorType>
ErrorType Result<ValueType, ErrorType>::TakeError(void) {
  VerifyState();
  VerifyChecked();
  VerifyFailed();

  auto error = std::move(std::get<ErrorType>(data));
  destroyed = true;

  return error;
}

template <typename ValueType, typename ErrorType>
const ValueType &Result<ValueType, ErrorType>::Value(void) const {
  VerifyState();
  VerifyChecked();
  VerifySucceeded();

  return std::get<ValueType>(data);
}

template <typename ValueType, typename ErrorType>
ValueType Result<ValueType, ErrorType>::TakeValue(void) {
  VerifyState();
  VerifyChecked();
  VerifySucceeded();

  auto value = std::move(std::get<ValueType>(data));
  destroyed = true;

  return value;
}

template <typename ValueType, typename ErrorType>
const ValueType *Result<ValueType, ErrorType>::operator->(void) const {
  return &Value();
}

template <typename ValueType, typename ErrorType>
Result<ValueType, ErrorType>::Result(const ValueType &value)
    : destroyed(false),
      data(value) {}

template <typename ValueType, typename ErrorType>
Result<ValueType, ErrorType>::Result(const ErrorType &error)
    : destroyed(false),
      data(error) {}

template <typename ValueType, typename ErrorType>
Result<ValueType, ErrorType>::Result(Result &&other) noexcept
    : destroyed(std::exchange(other.destroyed, false)),
      checked(std::exchange(other.checked, true)),
      data(std::exchange(other.data, ErrorType())) {}

template <typename ValueType, typename ErrorType>
Result<ValueType, ErrorType> &
Result<ValueType, ErrorType>::operator=(Result &&other) noexcept {
  Result that(std::forward<Result>(other));
  data = std::exchange(that.data, ErrorType());
  checked = std::exchange(that.checked, true);
  destroyed = std::exchange(that.destroyed, false);
  return *this;
}

template <typename ValueType, typename ErrorType>
void Result<ValueType, ErrorType>::VerifyState(void) const {
  if (!destroyed) {
    return;
  }
#ifndef NDEBUG
  throw std::logic_error(
      "The Result<ValueType, ErrorType> object no longer contains its internal data because it has been moved with TakeError/TakeValue");
#else
  __builtin_trap();
  __builtin_unreachable();
#endif
}

template <typename ValueType, typename ErrorType>
void Result<ValueType, ErrorType>::VerifyChecked(void) const {
  if (checked) {
    return;
  }

#ifndef NDEBUG
  throw std::logic_error(
      "The Result<ValueType, ErrorType> object was not checked for success");
#else
  __builtin_trap();
  __builtin_unreachable();
#endif
}

template <typename ValueType, typename ErrorType>
void Result<ValueType, ErrorType>::VerifySucceeded(void) const {
  if (std::holds_alternative<ValueType>(data)) {
    return;
  }

#ifndef NDEBUG
  throw std::logic_error(
      "The Result<ValueType, ErrorType> object has not succeeded");
#else
  __builtin_trap();
  __builtin_unreachable();
#endif
}

template <typename ValueType, typename ErrorType>
void Result<ValueType, ErrorType>::VerifyFailed(void) const {
  if (std::holds_alternative<ErrorType>(data)) {
    return;
  }
#ifndef NDEBUG
  throw std::logic_error(
      "The Result<ValueType, ErrorType> object has not failed");
#else
  __builtin_trap();
  __builtin_unreachable();
#endif
}

}  // namespace mx
