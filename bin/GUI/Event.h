// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QFlags>
#include <Qt>

namespace mx::gui {

enum class EventKind : int {
  kClick,
  kDoubleClick,
  kHover,
};

enum class Action : int {
  kDoNothing,
  kPropagate,
  kOpenCodeBrowser,
  kOpenReferenceBrowser,
  kAddToHistory,
};

struct Event {
  Qt::KeyboardModifiers modifiers;
  Qt::MouseButtons buttons;
  EventKind kind{};

  bool operator==(const Event &) const = default;
  bool operator!=(const Event &) const = default;
};

using EventAction = std::pair<Event, Action>;

#define MX_DECLARE_DECLARATION_SLOTS \
    void OnDeclarationEvent(Event event, std::vector<RawEntityId> ids); \

#define MX_DECLARE_DECLARATION_SIGNALS \
    void DeclarationEvent(Event event, std::vector<RawEntityId> ids); \
    void ActOnDeclarations(Action action, std::vector<RawEntityId> ids);

#define MX_DEFINE_DECLARATION_SLOTS(cls, config) \
    void cls::OnDeclarationEvent(Event event, \
                                 std::vector<RawEntityId> ids) { \
      for (const auto &[mevent, action] : config.declaration_actions) { \
        if (mevent != event) { \
          continue; \
        } \
        switch (action) { \
          case Action::kDoNothing: break; \
          case Action::kPropagate: \
            emit DeclarationEvent(event, ids); \
            break; \
          default: \
            emit ActOnDeclarations(action, ids); \
            break; \
        } \
      } \
    }

#define MX_CONNECT_CHILD_ACTIONS(config, this_cls, that_cls_ptr, that_cls) \
    if (!config.declaration_actions.empty()) { \
      connect(that_cls_ptr, &that_cls::DeclarationEvent, \
              this, &this_cls::OnDeclarationEvent); \
    }

#define MX_ROUTE_ACTIONS(config, this_cls, multiplier) \
    if (!config.declaration_actions.empty()) { \
      connect(this, &this_cls::ActOnDeclarations, \
              &multiplier, &Multiplier::OnActOnDeclarations); \
    }

}  // namespace mx::gui
