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

  // Click to open something in the file view.
  config.file.declaration_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::Action::kOpenCodeBrowser);

  // If we click on something in file view, then add it as a child to our
  // history view.
  config.file.declaration_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::Action::kAddToHistoryAsChild);

  // Ctrl-click / Cmd-click to open something in the references view.
  config.file.declaration_actions.emplace_back(
      mx::gui::Event{Qt::KeyboardModifier::ControlModifier,
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::Action::kOpenReferenceBrowser);

  // Ctrl-click / Cmd-click to open something from the reference view in the
  // references view.
  config.reference_browser.code_preview.declaration_actions.emplace_back(
      mx::gui::Event{Qt::KeyboardModifier::ControlModifier,
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::Action::kOpenReferenceBrowser);

  // Double click in the code preview of a reference browser opens in
  // the code browser.
  config.reference_browser.code_preview.declaration_actions.emplace_back(
      mx::gui::Event{{},
                     Qt::MouseButton::LeftButton,
                     mx::gui::EventKind::kClick},
      mx::gui::Action::kOpenCodeBrowser);

  qRegisterMetaType<uint8_t>("uint8_t");
  qRegisterMetaType<uint16_t>("uint16_t");
  qRegisterMetaType<uint32_t>("uint32_t");
  qRegisterMetaType<uint64_t>("uint64_t");
  qRegisterMetaType<mx::gui::Event>("Event");
  qRegisterMetaType<std::optional<mx::Decl>>("std::optional<Decl>");
  qRegisterMetaType<std::optional<mx::Stmt>>("std::optional<Stmt>");
  qRegisterMetaType<std::optional<mx::Type>>("std::optional<Type>");
  qRegisterMetaType<std::optional<mx::Token>>("std::optional<Token>");
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
