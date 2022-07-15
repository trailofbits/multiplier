// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <QFlags>
#include <QKeySequence>
#include <Qt>

#include <algorithm>
#include <cassert>
#include <cstring>
#include <multiplier/Types.h>
#include <optional>
#include <new>
#include <type_traits>
#include <utility>

namespace mx::gui {

class EventLocations;
class EventLocationsImpl;

class EventLocation {
 private:
  friend class EventLocations;
  friend class EventLocationsImpl;

  // The referenced declaration.
  RawEntityId referenced_decl_id{kInvalidEntityId};

  // Location of the referenced declaration in the fragment and the token.
  RawEntityId fragment_token_id{kInvalidEntityId};
  RawEntityId file_token_id{kInvalidEntityId};

  // Tells us if this location is present. Zero means not present, 1 means
  // present, and a value greater than 1 means we're interpreting this as
  // the number of elements in an event locations list.
  unsigned is_present{0u};

  // An opaque handle to a history item inside of the history view.
  unsigned history_item{0u};

 public:

  EventLocation(void) = default;
  EventLocation(const EventLocation &) = default;
  EventLocation(EventLocation &&) noexcept = default;
  EventLocation &operator=(const EventLocation &) = default;
  EventLocation &operator=(EventLocation &&) noexcept = default;

  inline std::optional<unsigned> HistoryItem(void) const {
    if (history_item) {
      return history_item - 1u;
    } else {
      return std::nullopt;
    }
  }

  void SetHistoryItem(unsigned history_item_) {
    history_item = history_item_ + 1u;
    assert(IsSane());
  }

  void SetReferencedDeclarationId(RawEntityId ent_id) {
    referenced_decl_id = ent_id;
    is_present = !!(referenced_decl_id | fragment_token_id | file_token_id);
  }

  void SetFragmentTokenId(RawEntityId ent_id) {
    fragment_token_id = ent_id;
    is_present = !!(referenced_decl_id | fragment_token_id | file_token_id);
  }

  void SetFileTokenId(RawEntityId ent_id) {
    file_token_id = ent_id;
    is_present = !!(referenced_decl_id | fragment_token_id | file_token_id);
  }

  bool IsSane(void) const;

  inline RawEntityId FileTokenId(void) const {
    return file_token_id;
  }

  inline RawEntityId FragmentTokenId(void) const {
    return fragment_token_id;
  }

  inline RawEntityId DeclarationId(void) const {
    return referenced_decl_id;
  }

  std::optional<struct FileTokenId> UnpackFileTokenId(void) const;
  std::optional<struct FragmentTokenId> UnpackFragmentTokenId(void) const;
  std::optional<struct DeclarationId> UnpackDeclarationId(void) const;
};

// Most of the time, we'll only ever have one location in our list, so we'll
// use a special inline data structure for that.
class EventLocations {
 private:
  std::aligned_storage_t<sizeof(EventLocation), alignof(EventLocation)> u;

  const EventLocationsImpl *AsList(void) const & noexcept;

  const EventLocation *AsLoc(void) const & noexcept {
    return std::launder(reinterpret_cast<const EventLocation *>(&u));
  }

  // Range-based copy constructor.
  explicit EventLocations(const EventLocation *b, const EventLocation *e);

 public:
  EventLocations(void) {
    __builtin_memset(this, 0, sizeof(*this));
  }

  ~EventLocations(void);

  inline EventLocations(EventLocation loc) {
    new (&u) EventLocation(loc);
  }

  inline EventLocations(EventLocations &&that) noexcept {
    __builtin_memcpy(this, &that, sizeof(that));
    __builtin_memset(&that, 0, sizeof(that));
  }

  // Copy constructor.
  inline EventLocations(const EventLocations &range)
      : EventLocations(std::addressof(*range.begin()),
                       std::addressof(*range.end())) {}

  // Constructs from a vector, for example.
  template <typename T>
  inline EventLocations(const T &range)
      : EventLocations(std::addressof(range.front()),
                       std::addressof(range.back()) + 1u) {}

  EventLocations &operator=(EventLocations &&that_) noexcept;
  EventLocations &operator=(const EventLocations &that_);

  inline bool IsEmpty(void) const & {
    return !AsLoc()->is_present;
  }

  inline size_t Size(void) const & {
    return AsLoc()->is_present;
  }

  const EventLocation &front(void) const &;
  const EventLocation &back(void) const &;

  const EventLocation *begin(void) const &;
  const EventLocation *end(void) const &;
};

enum class MouseClickKind : int {
  kNotClicked                   = 0,
  kLeftClick                    = 1 << 0,
  kRightClick                   = 1 << 1,
  kLeftDoubleClick              = 1 << 2,
  kRightDoubleClick             = 1 << 3,
};

Q_DECLARE_FLAGS(MouseClickKinds, MouseClickKind)

enum class EventSource : int {
  kReferenceBrowserPreviewClickSource  = 1 << 0,
  kReferenceBrowserPreviewClickDest    = 1 << 1,
  kReferenceBrowser                    = 1 << 2,
  kCodeBrowserClickSource              = 1 << 3,
  kCodeBrowserClickDest                = 1 << 4,

  // When we select a visual item, the location is published.
  kHistoryBrowserVisualItemSelected    = 1 << 5,

  // When we go back/forward through the linear history.
  kHistoryBrowserLinearItemChanged     = 1 << 6,

  // When we click on a token in a code search result.
  kCodeSearchResult                    = 1 << 7,
  kCodeSearchResultPreviewClickSource  = 1 << 8,
  kCodeSearchResultPreviewClickDest    = 1 << 9,

  // When we click on an entity name from the entity symbol search.
  kEntitySearchResult                  = 1 << 10,
};

Q_DECLARE_FLAGS(EventSources, EventSource)

enum class Action : int {
  kDoNothing,

  // Open the declaration or tokens in the code browser. This will render the
  // containing file, then try to navigate to the relevant line.
  kOpenCodeBrowser,

  // Open the declaration or nearest containing declaration in the reference
  // browser. This will also auto-open the first level of references.
  kOpenReferenceBrowser,

  // Add a declaration to the history.
  kAddToVisualHistoryAsChild,
  kAddToVisualHistoryAsSibling,
  kAddToVisualHistoryUnderRoot,
  kAddToVisualHistoryAsRoots,

  kAddToLinearHistory,

  kGoBackLinearHistory,

  kOpenEntitySearch,
  kOpenRegexSearch,
  kOpenWeggliSearch,
};

struct EventAction {
  const char *description;

  // All of these keys must be matched.
  Qt::Key match_key{Qt::Key_unknown};

  // The exact type of click needs to be matched.
  MouseClickKind match_click{MouseClickKind::kNotClicked};

  // The mouse modifiers to match.
  Qt::KeyboardModifiers match_modifiers{};

  // Any of the sources are allowed to match.
  EventSources match_sources;

  // Do this action.
  Action do_action{Action::kDoNothing};

  // The last time this event was triggered.
  mutable uint64_t last_triggered{0u};
};

}  // namespace mx::gui
