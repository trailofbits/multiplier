// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <glog/logging.h>
#include <multiplier/Executor.h>
#include <multiplier/Tool.h>
#include <multiplier/Types.h>

#include "Context.h"
#include "IndexCompileCommand.h"

namespace indexer {

class IndexCompileCommandTool final : public mx::Tool {
 public:
  using mx::Tool::Tool;

  virtual ~IndexCompileCommandTool(void) = default;

  // Return tool name.
  const char *Name(void) const final {
    return "compile-command-indexer";
  }

  void Update(mx::DatalogClientMessagePtr message) final {
    auto context = std::make_shared<Context>(client);
    if (auto added = message->added()) {
      if (auto commands = added->new_compile_command_1()) {
        for (auto raw_command : *commands) {
          CompileCommandPtr command(message, raw_command->CC_nested_root());
          executor.EmplaceAction<IndexCompileCommandAction>(
              context, std::move(command));
        }
      }
    }
  }
};

[[gnu::used]] mx::RegisteredTool<IndexCompileCommandTool> gTool;

}  // namespace indexer
