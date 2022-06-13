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

enum class EventSource : int {
  kReferenceBrowserCodePreview  = 1 << 0,
  kReferenceBrowser             = 1 << 1,
  kCodeBrowser                  = 1 << 2,
};

Q_DECLARE_FLAGS(EventSources, EventSource)

enum class Action : int {
  // Open the declaration or tokens in the code browser. This will render the
  // containing file, then try to navigate to the relevant line.
  kOpenCodeBrowser              = 1 << 0,

  // Open the declaration or nearest containing declaration in the reference
  // browser. This will also auto-open the first level of references.
  kOpenReferenceBrowser         = 1 << 1,

  // Add a declaration to the history.
  kAddToHistoryAsChild          = 1 << 2,
  kAddToHistoryAsSibling        = 1 << 3,
  kAddToHistoryUnderRoot        = 1 << 4,
  kAddToHistoryAsRoots          = 1 << 5,
};

Q_DECLARE_FLAGS(Actions, Action)

struct Event {
  Qt::KeyboardModifiers modifiers;
  Qt::MouseButtons buttons;
  EventKind kind{};

  bool operator==(const Event &) const = default;
  bool operator!=(const Event &) const = default;
};

using EventAction = std::tuple<Event, EventSources, Actions>;

}  // namespace mx::gui
