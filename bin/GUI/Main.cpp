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
  // view of the reference browser, should open the thing in the code browser.
  config.actions.emplace_back(mx::gui::EventAction{
    .description = "When clicked, code should add to the history",
    .match_click = mx::gui::MouseClickKind::kLeftClick,
    .match_sources = {mx::gui::EventSource::kCodeBrowser,
                      mx::gui::EventSource::kReferenceBrowserCodePreview},
    .do_action = mx::gui::Action::kAddToHistoryUnderRoot,
  });

  config.immediate_actions.emplace_back(mx::gui::EventAction{
    .description = "A change in the selected history item should navigate to the entity",
    .match_sources = {mx::gui::EventSource::kHistoryBrowser},
    .do_action = mx::gui::Action::kOpenCodeBrowser,
  });

  config.actions.emplace_back(mx::gui::EventAction{
    .description = "A meta-click on an entity should open up the references view",
    .match_click = mx::gui::MouseClickKind::kLeftClick,
    .match_modifiers = {Qt::KeyboardModifier::MetaModifier},
    .match_sources = {mx::gui::EventSource::kHistoryBrowser,
                      mx::gui::EventSource::kCodeBrowser,
                      mx::gui::EventSource::kReferenceBrowser,
                      mx::gui::EventSource::kReferenceBrowserCodePreview},
    .do_action = mx::gui::Action::kOpenReferenceBrowser,
  });

  config.actions.emplace_back(mx::gui::EventAction{
    .description = "A double click in the reference browser adds to the history",
    .match_click = mx::gui::MouseClickKind::kLeftDoubleClick,
    .match_sources = {mx::gui::EventSource::kReferenceBrowser},
    .do_action = mx::gui::Action::kAddToHistoryUnderRoot,
  });


  config.actions.emplace_back(mx::gui::EventAction{
    .description = "Pressing ESC should go back in linear history",
    .match_key = Qt::Key_Escape,
    .match_sources = {mx::gui::EventSource::kHistoryBrowser,
                      mx::gui::EventSource::kCodeBrowser,
                      mx::gui::EventSource::kReferenceBrowser,
                      mx::gui::EventSource::kReferenceBrowserCodePreview},
    .do_action = mx::gui::Action::kGoBackLinearHistory,
  });

  qRegisterMetaType<mx::gui::EventLocation>("EventLocation");
  qRegisterMetaType<mx::gui::EventLocations>("EventLocations");
  qRegisterMetaType<mx::gui::EventSource>("EventSource");
  qRegisterMetaType<mx::gui::EventSources>("EventSources");
  qRegisterMetaType<uint8_t>("uint8_t");
  qRegisterMetaType<uint16_t>("uint16_t");
  qRegisterMetaType<uint32_t>("uint32_t");
  qRegisterMetaType<uint64_t>("uint64_t");
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
