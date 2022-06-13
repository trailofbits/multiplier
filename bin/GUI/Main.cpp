// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include <cstdint>
#include <cstdlib>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <memory>
#include <multiplier/Index.h>
#include <QApplication>
#include <QMetaType>

#include "CodeView.h"
#include "Configuration.h"
#include "Multiplier.h"
#include "ReferenceBrowserView.h"

namespace {

} // namespace

int main(int argc, char *argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, false);
  google::InitGoogleLogging(argv[0]);
  QApplication application(argc, argv);

  mx::gui::Configuration config;

  if (getenv("MX_NO_CUSTOM_THEME") == nullptr) {
    qApp->setStyle(config.style);
  }

  // Per Josh Hofing:
  //
  //    You spend a lot of time clicking stuff to go deeper and deeper while
  //    auditing, so that should be as easy as possible.
  //
  //    There's a finite number of times that I'll be able to click in my life
  //    before I get arthritis, so I don't want to halve it.

  // Click to open something in the code browser view, or in the code preview
  // view of the refernce browser, should open the thing in the code browser.
  config.declaration_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::EventSources{mx::gui::EventSource::kCodeBrowser,
                            mx::gui::EventSource::kReferenceBrowserCodePreview},
      mx::gui::Actions{mx::gui::Action::kOpenCodeBrowser,
                       mx::gui::Action::kAddToHistoryUnderRoot});

  // Ctrl-click / Cmd-click to open something in the references view.
  config.declaration_actions.emplace_back(
      mx::gui::Event{Qt::KeyboardModifier::ControlModifier,
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::EventSources{mx::gui::EventSource::kCodeBrowser,
                            mx::gui::EventSource::kReferenceBrowserCodePreview},
      mx::gui::Actions{mx::gui::Action::kOpenReferenceBrowser});

  // Double-clicking an item in the reference browser should open it up in the
  // code browser. This is a declaration action, because we want to go to the
  // declaration containing the reference.
  config.declaration_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kDoubleClick},
      mx::gui::EventSources{mx::gui::EventSource::kReferenceBrowser},
      mx::gui::Actions{mx::gui::Action::kAddToHistoryUnderRoot});

  // Double-clicking an item in the reference browser should open it up in the
  // code browser. This is a token action because we want to go to the token
  // where the reference is.
  config.token_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kDoubleClick},
      mx::gui::EventSources{mx::gui::EventSource::kReferenceBrowser},
      mx::gui::Actions{mx::gui::Action::kOpenCodeBrowser});

  qRegisterMetaType<mx::gui::EventSource>("EventSource");
  qRegisterMetaType<mx::gui::EventSources>("EventSources");
  qRegisterMetaType<uint8_t>("uint8_t");
  qRegisterMetaType<uint16_t>("uint16_t");
  qRegisterMetaType<uint32_t>("uint32_t");
  qRegisterMetaType<uint64_t>("uint64_t");
  qRegisterMetaType<mx::gui::Event>("Event");
  qRegisterMetaType<std::optional<mx::Decl>>("std::optional<Decl>");
  qRegisterMetaType<std::optional<mx::Stmt>>("std::optional<Stmt>");
  qRegisterMetaType<std::optional<mx::Type>>("std::optional<Type>");
  qRegisterMetaType<std::optional<mx::Token>>("std::optional<Token>");
  qRegisterMetaType<mx::gui::UserLocationsPtr>("UserLocationsPtr");
  qRegisterMetaType<mx::gui::UserLocations>("UserLocations");
  qRegisterMetaType<mx::RawEntityId>("RawEntityId");
  qRegisterMetaType<mx::FileId>("FileId");
  qRegisterMetaType<mx::FragmentId>("FragmentId");
  qRegisterMetaType<mx::EntityId>("EntityId");
  qRegisterMetaType<mx::FilePathList>("FilePathList");
  qRegisterMetaType<mx::Token>("Token");
  qRegisterMetaType<mx::TokenRange>("TokenRange");
  qRegisterMetaType<mx::TokenList>("TokenList");
  qRegisterMetaType<std::optional<mx::File>>("std::optional<File>");
  qRegisterMetaType<std::optional<mx::Fragment>>("std::optional<Fragment>");
  qRegisterMetaType<std::optional<mx::Decl>>("std::optional<Decl>");
  qRegisterMetaType<std::optional<mx::Stmt>>("std::optional<Stmt>");
  qRegisterMetaType<std::optional<mx::Type>>("std::optional<Type>");
  qRegisterMetaType<std::optional<mx::Token>>("std::optional<Token>");
  qRegisterMetaType<std::vector<mx::Fragment>>("std::vector<Fragment>");
  qRegisterMetaType<std::vector<mx::RawEntityId>>("std::vector<RawEntityId>");

  mx::gui::Multiplier main_window(config);
  main_window.show();

  return application.exec();
}
