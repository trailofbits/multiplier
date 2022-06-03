// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <vector>

#include "Event.h"

namespace mx::gui {

// TODO(pag): All of this would probably make more sense as a protobuf format.

class CodeTheme;

// Configuration for a single file view, which presents the source code of
// a file.
struct FileConfiguration {

  // If one or more declarations are hovered/clicked, then we evaluate these
  // bindings are trigger the relevant actions.
  std::vector<EventAction> declaration_actions;
};

// Configuration for the file browser, which presents a tree view of all files
// indexed by Multiplier.
struct FileBrowserConfiguration {

};

// Configuration for the code preview pane within the reference browser view.
struct ReferenceBrowserCodeConfiguration {
  // Should a code preview be shown when an item in the reference view is
  // selected?
  bool visible{true};

  // If one or more declarations are hovered/clicked, then we evaluate these
  // bindings are trigger the relevant actions.
  std::vector<EventAction> declaration_actions;
};

// Configuration for the breadcrumb cell of the reference browser view.
//
// This will show a trail of usage-specific contextual information for each
// entry in the reference tree. For example, if the user code was:
//
//    int user() {
//      if (...) {
//        return global->field;
//      }
//      ...
//    }
//
// And if we were asking for references of `field`, then the context would
// look like:
//
//    MEMBER > RETURN > IF > FUNCTION
struct ReferenceBrowserBreadcrumbsConfiguration {

  // Should the breadcrumbs be shown at all?
  bool visible{true};

  // Should the entries be run-length encoded? If so, then instead of seeing
  // something like `IF > IF > IF`, you will see `IF^3` (using a superscript
  // number `3`). When the repetitions exceeds `9`, a `+` will be shown.
  bool run_length_encode{true};
};

// Configuration for the reference browser, which presents a tree view of
// the references / call hierarchy of a particular entity.
struct ReferenceBrowserConfiguration {
  // Should entries in the reference tree be grouped under a containing file?
  // If `true`, then what is shown is something like:
  //
  //    +- /path/to/file1
  //    |  +- ref1
  //    |  `- ref2
  //    `- /path/to/file2
  //       `- ref3
  //
  // If `false`, then what is shown is something like:
  //
  //    +- ref1
  //    +- ref2
  //    `- ref3
  //
  // In all cases, the references are still logically grouped and ordered
  // by their relative locations within their containing files. This option
  // affects whether or not those file paths appear as entries in the references
  // tree.
  bool group_under_containing_file{true};

  // Should line and column numbers show up as additional cells in the reference
  // tree.
  bool show_line_numbers{true};
  bool show_column_numbers{true};

  ReferenceBrowserBreadcrumbsConfiguration breadcrumbs;
  ReferenceBrowserCodeConfiguration code_preview;
};

struct Configuration {
  const char *style{"Fusion"};

  const CodeTheme *theme;

  ReferenceBrowserConfiguration reference_browser;
  FileBrowserConfiguration file_browser;
  FileConfiguration file;

  Configuration(void);
};

}  // namespace mx::gui
