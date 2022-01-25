// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Database.h"

#include <cassert>
#include <glog/logging.h>

namespace mx {
namespace {

static std::unique_ptr<internal::RegisteredToolBase> gDatabaseTool;

}  // namespace

Tool::~Tool(void) {}

void Tool::Stop(void) {}

void Tool::Update(DatalogClientMessagePtr) {}

namespace internal {

RegisteredToolBase *RegisteredToolBase::gFirstTool = nullptr;

RegisteredToolBase::RegisteredToolBase(void (*stopper_)(Tool *))
    : destroyer(stopper_),
      next(gFirstTool) {
  gFirstTool = this;
}

RegisteredToolBase::~RegisteredToolBase(void) {
  if (tool) {
    destroyer(tool);
    tool = nullptr;
  }
}

}  // namespace internal

Tool *Tool::StartAll(const Executor &exe, const DatalogClient &client) {

  if (!gDatabaseTool) {
    gDatabaseTool.reset(new RegisteredTool<DatabaseTool>);
  }

  for (auto tr = internal::RegisteredToolBase::gFirstTool;
       tr != nullptr; tr = tr->next) {
    if (!tr->tool) {
      Tool *tool = tr->Allocate(exe, client);
      LOG(INFO) << "Started tool " << tool->Name();
    }
  }

  return internal::RegisteredToolBase::gFirstTool->tool;
}

void Tool::UpdateAll(const DatalogClientMessagePtr &message) {
  for (auto tr = internal::RegisteredToolBase::gFirstTool;
       tr != nullptr; tr = tr->next) {
    if (tr->tool) {
      DLOG(INFO) << "Updating tool " << tr->tool->Name();
      tr->tool->Update(message);
      DLOG(INFO) << "Updated tool " << tr->tool->Name();
    }
  }
}

void Tool::StopAll(void) {
  for (auto tr = internal::RegisteredToolBase::gFirstTool;
       tr != nullptr; tr = tr->next) {
    if (tr->tool) {
      LOG(INFO) << "Stopping tool " << tr->tool->Name();
      tr->tool->Stop();
      LOG(INFO) << "Stopped tool " << tr->tool->Name();
    }
  }
}

// Destroy all tools, in reverse order of their registry.
void Tool::DestroyAll(void) {

  struct Destroyer {
    static void Run(internal::RegisteredToolBase *tb) {
      if (tb->next) {
        Run(tb->next);
      }
      if (tb->tool) {
        auto tool_name = tb->tool->Name();
        LOG(INFO) << "Destroying tool " << tool_name;
        tb->destroyer(tb->tool);
        LOG(INFO) << "Destroyed tool " << tool_name;
        tb->tool = nullptr;
      }
    }
  };

  if (auto tool = internal::RegisteredToolBase::gFirstTool) {
    Destroyer::Run(tool);
  }
}

}  // namespace mx
