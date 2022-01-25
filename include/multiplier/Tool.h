// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <functional>
#include <new>
#include <string>
#include <type_traits>

#include <multiplier/Datalog.h>

namespace mx {

class Executor;
class FunctionManager;
class MemoryManager;
class ObjectManager;
class OutputMessage;
class InternalTool;

// Represents a generic tool within IRENE.
class Tool {
 private:
  Tool(const Tool &) = delete;
  Tool(Tool &&) noexcept = delete;
  Tool &operator=(const Tool &) = delete;
  Tool &operator=(Tool &&) noexcept = delete;

 public:
  const Executor &executor;
  const DatalogClient &client;

  inline /* implicit */ Tool(const Executor &executor_,
                             const DatalogClient &client_)
      : executor(executor_),
        client(client_) {}

  virtual ~Tool(void);

  // Return tool name.
  virtual const char *Name(void) const = 0;

  // Tear down this tool.
  virtual void Stop(void);

  // This method is invoked each time we receive an update from the server.
  virtual void Update(DatalogClientMessagePtr);

  // Start all tools; returns a pointer to the first tool.
  static Tool *StartAll(const Executor &, const DatalogClient &);
  static void UpdateAll(const DatalogClientMessagePtr &);
  static void StopAll(void);
  static void DestroyAll(void);
};

namespace internal {

class RegisteredToolBase {
 private:
  friend class ::mx::FunctionManager;
  friend class ::mx::MemoryManager;
  friend class ::mx::ObjectManager;
  friend class ::mx::Tool;

  static RegisteredToolBase *gFirstTool;

  RegisteredToolBase(void) = delete;
  RegisteredToolBase(const RegisteredToolBase &) = delete;
  RegisteredToolBase(RegisteredToolBase &&) noexcept = delete;
  RegisteredToolBase &operator=(const RegisteredToolBase &) = delete;
  RegisteredToolBase &operator=(RegisteredToolBase &&) noexcept = delete;

  void (* const destroyer)(Tool *);
  RegisteredToolBase *next;

 protected:
  Tool *tool{nullptr};

  virtual Tool *Allocate(const Executor &, const DatalogClient &client) = 0;

 public:
  virtual ~RegisteredToolBase(void);
  explicit RegisteredToolBase(void (*destroyer_)(Tool *));
};

}  // namespace internal

// Static registration of tools in pre-main initializers.
template <typename T>
class RegisteredTool final : public internal::RegisteredToolBase {
 private:
  friend class ::mx::FunctionManager;
  friend class ::mx::MemoryManager;

  std::aligned_storage_t<sizeof(T), alignof(T)> storage;

  // Stop the tool upon destruction.
  static void Destroy(Tool *tool_ptr) {
    if (auto derived_tool = dynamic_cast<T *>(tool_ptr)) {
      derived_tool->~T();
    }
  }

 public:
  virtual ~RegisteredTool(void) = default;

  RegisteredTool(void)
      : internal::RegisteredToolBase(Destroy) {}

 private:
  Tool *Allocate(const Executor &exe, const DatalogClient &client) final {
    if (!tool) {
      tool = new (&storage) T(exe, client);
    }
    return tool;
  }
};

}  // namespace mx
