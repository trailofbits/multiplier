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

  std::shared_ptr<GlobalContext> global_context;

  virtual ~IndexCompileCommandTool(void) = default;

  IndexCompileCommandTool(const mx::Executor &executor_,
                          const mx::DatalogClient &client_)
      : mx::Tool(executor_, client_),
        global_context(std::make_shared<GlobalContext>(executor_, client_)) {}

  // Return tool name.
  const char *Name(void) const final {
    return "compile-command-indexer";
  }

  void Update(mx::DatalogClientMessagePtr message) final {
    auto context = std::make_shared<UpdateContext>(client, global_context);
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
