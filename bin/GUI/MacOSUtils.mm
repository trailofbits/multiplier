// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#import <Cocoa/Cocoa.h>
#include <QWidget>

namespace mx::gui {

void setTitleBarColor(WId window_handle, const QColor color, bool transparent) {
  if (window_handle == 0) {
    return;
  }

  auto view = reinterpret_cast<NSView *>(window_handle);
  auto window = [view window];

  window.appearance = [NSAppearance appearanceNamed:NSAppearanceNameDarkAqua];

  window.titlebarAppearsTransparent = transparent ? YES : NO;
  window.backgroundColor = [NSColor colorWithRed:color.redF()
                                           green:color.greenF()
                                            blue:color.blueF()
                                           alpha:1.0];
}

}
