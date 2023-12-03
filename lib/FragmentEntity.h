// Copyright (c) 2023-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include "Fragment.h"

namespace mx {

template <typename Root>
class FragmentEntityImpl {
 public:
  using Reader = typename Root::Reader;

  // Needed for us to be able to look up the file containing this fragment,
  // or look up entities related to other fragments.
  //
  // NOTE(pag): This aliases a `FragmentImpl` reference count.
  const EntityProviderPtr ep;

  // The reader used to read all things from inside of this entity.
  const Reader reader;

  // This is a fragment-specific entity, where the fragment shared pointer holds
  // onto the entity pointer shared pointer, so we can transitively keep the
  // entity provider alive via keeping the fragment alive. But we need to keep
  // the fragment alive because the data backed by `reader` is owned by the
  // fragment, hence why we alias the entity provider pointer to the reference
  // count of the fragment.
  FragmentEntityImpl(FragmentImplPtr frag_, Reader reader_)
      : ep(frag_, frag_->ep.get()),
        reader(kj::mv(reader_)) {}
};

}  // namespace mx
