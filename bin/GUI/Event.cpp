// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "Event.h"

namespace mx::gui {

// The "list" version of an `EventLocation`, whose size/shape matches an
// `EventLocation`, but whose data is interpreted differently.
class EventLocationsImpl {
 public:
  EventLocation * const begin;
  EventLocation * const end;
  const uint64_t zero{0};
  const unsigned length;  // Overlaps with `EventLocation::is_preset`.
  const unsigned zero2{0};  // Overlaps with `EventLocation::history_item`.

  inline EventLocationsImpl(unsigned n, const EventLocation *b,
                           const EventLocation *e)
      : begin(new EventLocation[n]),
        end(&(begin[n])),
        length(n) {
    assert(1 < length);
    for (auto i = 0u; b < e; ++b, ++i) {
      begin[i] = *b;
      assert(begin[i].IsSane());
    }
  }

  inline ~EventLocationsImpl(void) {
    delete [] begin;
  }

  inline size_t Size(void) const noexcept {
    return static_cast<size_t>(end - begin);
  }
};

static_assert(sizeof(EventLocationsImpl) == sizeof(EventLocation));
static_assert(alignof(EventLocationsImpl) == alignof(EventLocation));

std::optional<struct FileTokenId>
EventLocation::UnpackFileTokenId(void) const {
  auto vid = EntityId(file_token_id).Unpack();
  if (std::holds_alternative<struct FileTokenId>(vid)) {
    return std::get<struct FileTokenId>(vid);
  } else {
    return std::nullopt;
  }
}
std::optional<struct FragmentTokenId>
EventLocation::UnpackFragmentTokenId(void) const {
  auto vid = EntityId(fragment_token_id).Unpack();
  if (std::holds_alternative<struct FragmentTokenId>(vid)) {
    return std::get<struct FragmentTokenId>(vid);
  } else {
    return std::nullopt;
  }
}

std::optional<struct DeclarationId>
EventLocation::UnpackDeclarationId(void) const {
  auto vid = EntityId(referenced_decl_id).Unpack();
  if (std::holds_alternative<struct DeclarationId>(vid)) {
    return std::get<struct DeclarationId>(vid);
  } else {
    return std::nullopt;
  }
}

bool EventLocation::IsSane(void) const {
  if (fragment_token_id != kInvalidEntityId) {
    if (!UnpackFragmentTokenId().has_value()) {
      return false;
    }
  }

  if (file_token_id != kInvalidEntityId) {
    if (!UnpackFileTokenId().has_value()) {
      return false;
    }
  }

  if (referenced_decl_id != kInvalidEntityId) {
    if (!UnpackDeclarationId().has_value()) {
      return false;
    }
  }

  return true;
}

EventLocations::~EventLocations(void) {
  if (auto ls = AsList()) {
    ls->~EventLocationsImpl();
  }
}

const EventLocationsImpl *EventLocations::AsList(void) const & noexcept {
  auto ll = std::launder(reinterpret_cast<const EventLocationsImpl *>(&u));
  if (1 < ll->length) {
    assert(ll->begin);
    assert(ll->end);
    assert(!ll->zero);
    assert(!ll->zero2);
    assert(&(ll->begin[ll->length]) == ll->end);
    return ll;
  } else {
    return nullptr;
  }
}

EventLocations::EventLocations(const EventLocation *b, const EventLocation *e) {
  switch (auto d = static_cast<unsigned>(e - b)) {
    case 0u:
      memset(&u, 0, sizeof(u));
      break;
    case 1u:
      assert(b->is_present);
      new (&u) EventLocation(*b);
      break;
    default:
      new (&u) EventLocationsImpl(d, b, e);
      break;
  }
}

EventLocations &EventLocations::operator=(EventLocations &&that_) noexcept {
  EventLocations that(std::forward<EventLocations>(that_));

  if (auto ls = AsList()) {
    ls->~EventLocationsImpl();
  }

  memcpy(this, &that, sizeof(that));
  return *this;
}

EventLocations &EventLocations::operator=(const EventLocations &that_) {
  EventLocations that(that_);
  if (auto ls = AsList()) {
    ls->~EventLocationsImpl();
  }
  memcpy(this, &that, sizeof(that));
  memset(&that, 0, sizeof(that));
  return *this;
}

const EventLocation &EventLocations::front(void) const & {
  if (auto ls = AsList()) {
    return *(ls->begin);
  } else {
    return *AsLoc();
  }
}

const EventLocation &EventLocations::back(void) const & {
  if (auto ls = AsList()) {
    return *&(ls->end[-1]);
  } else {
    return *AsLoc();
  }
}

const EventLocation *EventLocations::begin(void) const & {
  if (auto ls = AsList()) {
    return ls->begin;
  } else {
    return AsLoc();
  }
}

const EventLocation *EventLocations::end(void) const & {
  if (auto ls = AsList()) {
    return ls->end;
  } else {
    auto loc = AsLoc();
    return &(loc[loc->is_present]);
  }
}

}  // namespace mx::gui
