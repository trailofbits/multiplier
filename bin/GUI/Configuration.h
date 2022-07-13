// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <optional>
#include <QString>
#include <vector>

#include "Event.h"

namespace mx::gui {

// TODO(pag): All of this would probably make more sense as a protobuf format.

class CodeTheme;

// Configuration for the code preview pane within the reference browser view,
// or the code search view.
struct CodePreviewConfiguration {
  // Should a code preview be shown when an item in the reference view is
  // selected?
  bool visible{true};

};

struct EntitySearchResultsConfiguration {

  // Should the declaration kind be shown?
  bool show_declaration_kind{true};

  // Should the full file path be shown?
  bool show_file_path{false};

  // Should the file name be shown?
  bool show_file_name{true};

  // Should line and column numbers show up as additional cells in the reference
  // tree.
  bool show_line_numbers{true};
  bool show_column_numbers{true};
};

struct CodeSearchResultsConfiguration {

  // Apply syntax highlighting to code search results?
  bool highlight_syntax{true};

  // Should the capture groups be highlighted? This manifests in highlighting
  // with a background color on the tokens, where the background color for the
  // `N`th capture group is the `N`th theme highlight background color.
  bool highlight_captures{true};

  CodePreviewConfiguration code_preview;
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
struct BreadcrumbsConfiguration {

  // Should the breadcrumbs be shown at all?
  bool visible{true};

  // Should the entries be run-length encoded? If so, then instead of seeing
  // something like `IF > IF > IF`, you will see `IF^3` (using a superscript
  // number `3`). When the repetitions exceeds `9`, a `+` will be shown.
  bool run_length_encode{true};
};


// Configuration for a single file view, which presents the source code of
// a file.
struct FileConfiguration {

};

// The configuration for the history browser.
struct HistoryBrowserConfiguration {

  // Should the full file path be shown?
  bool show_file_path{false};

  // Should the file name be shown?
  bool show_file_name{true};

  // Should line and column numbers show up as additional cells in the reference
  // tree.
  bool show_line_numbers{true};
  bool show_column_numbers{true};

  BreadcrumbsConfiguration breadcrumbs;
};

// Configuration for the file browser, which presents a tree view of all files
// indexed by Multiplier.
struct FileBrowserConfiguration {

};

// Configuration for the reference browser, which presents a tree view of
// the references / call hierarchy of a particular entity.
struct ReferenceBrowserConfiguration {

  // Should the full file path be shown?
  bool show_file_path{false};

  // Should the file name be shown?
  bool show_file_name{true};

  // Should line and column numbers show up as additional cells in the reference
  // tree.
  bool show_line_numbers{true};
  bool show_column_numbers{true};

  BreadcrumbsConfiguration breadcrumbs;
  CodePreviewConfiguration code_preview;

};

struct Configuration {
  const char *style{"Fusion"};

  const CodeTheme *theme;

  EntitySearchResultsConfiguration entity_search_results;
  CodeSearchResultsConfiguration code_search_results;
  HistoryBrowserConfiguration history_browser;
  ReferenceBrowserConfiguration reference_browser;
  FileBrowserConfiguration file_browser;
  FileConfiguration file;

  // These actions are evaluated during event filterings. If you want to check
  // clicks or keys, then do so here.
  std::vector<EventAction> actions;

  // These actions are evaluated immediately upon receipt of an event. If you
  // always want an event to fire, then do it here. The only tested thing for
  // these is the source; the modifiers/click/key constraints are ignored.
  std::vector<EventAction> immediate_actions;

  QString gui_exe_path;
  QString indexer_exe_path;
  QString importer_exe_path;

  Configuration(void);
};

}  // namespace mx::gui
