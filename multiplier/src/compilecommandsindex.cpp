/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "compilecommandsindex.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <array>
#include <iostream>

#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Command.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileManager.h>

namespace multiplier {
namespace {

pasta::Compiler CreateHostCompiler(pasta::FileManager fm,
                                   pasta::TargetLanguage lang) {
  auto compiler = pasta::Compiler::CreateHostCompiler(fm, lang);
  if (compiler.Failed()) {
    abort();
  } else {
    return compiler.TakeValue();
  }
}

}  // namespace

struct CompileCommandsIndex::PrivateData final {
  PrivateData(void)
      : file_system(pasta::FileSystem::CreateNative()),
        file_manager(file_system),
        c_compiler(CreateHostCompiler(file_manager, pasta::TargetLanguage::kC)),
        cxx_compiler(CreateHostCompiler(file_manager, pasta::TargetLanguage::kCXX)) {}

  std::shared_ptr<pasta::FileSystem> file_system;
  pasta::FileManager file_manager;
  pasta::Compiler c_compiler;
  pasta::Compiler cxx_compiler;
  QTreeWidget *source_file_tree{nullptr};
};

CompileCommandsIndex::CompileCommandsIndex(QWidget *parent)
    : QFrame(parent), d(new PrivateData) {
  setWindowTitle(tr("Compile Commands"));

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  d->source_file_tree = new QTreeWidget();
  d->source_file_tree->setHeaderHidden(true);
  layout->addWidget(d->source_file_tree);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &CompileCommandsIndex::onTreeWidgetItemActivated);
}

CompileCommandsIndex::~CompileCommandsIndex() {}

bool CompileCommandsIndex::setCompileCommands(const QJsonDocument &json_document) {
  static const std::array<const char *, 3> kExpectedFileObjectEntries = {
      "directory",
      "command",
      "file",
  };

  if (!json_document.isArray()) {
    return false;
  }

  QMap<QString, QTreeWidgetItem *> root_item_map;

  const auto &file_obj_array = json_document.array();
  for (const auto &file_obj_value : file_obj_array) {
    if (!file_obj_value.isObject()) {
      return false;
    }

    const auto &file_obj = file_obj_value.toObject();
    for (const auto &entry_name : kExpectedFileObjectEntries) {
      if (!file_obj.contains(entry_name) || !file_obj[entry_name].isString()) {
        return false;
      }
    }

    auto directory_path = file_obj["directory"].toString();
    auto compile_command = file_obj["command"].toString();
    auto source_file = file_obj["file"].toString();

    auto path_component_list = source_file.split(QChar('/'));

    auto parent_name = path_component_list.takeFirst();
    if (!parent_name.isEmpty()) {
      // This is not an absolute path
      return false;
    }

    parent_name = path_component_list.takeFirst();
    if (parent_name.isEmpty()) {
      return false;
    }

    auto file_name = path_component_list.takeLast();

    auto root_item_map_it = root_item_map.find(parent_name);
    if (root_item_map_it == root_item_map.end()) {
      auto item = new QTreeWidgetItem();
      item->setText(0, parent_name);

      root_item_map_it = root_item_map.insert(parent_name, item);
    }

    auto parent = *root_item_map_it;

    for (const auto &path_component : path_component_list) {
      auto found{false};

      for (auto i = 0; i < parent->childCount(); ++i) {
        auto child = parent->child(i);
        if (child->text(0) == path_component) {
          found = true;
          parent = child;
        }
      }

      if (!found) {
        auto child = new QTreeWidgetItem();
        child->setText(0, path_component);

        parent->addChild(child);
        parent = child;
      }
    }

    auto file_name_item = new QTreeWidgetItem();
    file_name_item->setText(0, file_name);
    file_name_item->setText(1, directory_path);
    file_name_item->setText(2, source_file);
    file_name_item->setText(3, compile_command);

    parent->addChild(file_name_item);
  }

  for (auto item : root_item_map) {
    for (;;) {
      if (item->childCount() == 0) {
        break;

      } else if (item->childCount() == 1) {
        item = item->child(0);

      } else {
        break;
      }
    }

    auto root_item = new QTreeWidgetItem();
    root_item->setText(0, item->text(0));
    root_item->addChildren(item->takeChildren());
    delete item;

    d->source_file_tree->addTopLevelItem(root_item);
  }

  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);
  return true;
}

void CompileCommandsIndex::reset() {
  d->source_file_tree->reset();
}

void CompileCommandsIndex::onTreeWidgetItemActivated(QTreeWidgetItem *item, int) {

  if (item->childCount() != 0 || item->columnCount() != 4) {
    return;
  }

  auto working_directory = item->text(1);
  auto source_file_path = item->text(2);
  auto compile_command = item->text(3);

  auto cwd = d->file_system->CurrentWorkingDirectory();
  if (cwd.Failed()) {
    std::cerr << cwd.TakeError().message() << std::endl;
    return;  // TODO(pag): Log error.
  }

  auto working_directory_path = d->file_system->ParsePath(
      working_directory.toStdString(), cwd.TakeValue(),
      d->file_system->PathKind());

  pasta::ArgumentVector argv(compile_command.toStdString());
  auto cmd = pasta::CompileCommand::CreateFromArguments(
      argv, working_directory_path);

  if (cmd.Failed()) {
    std::cerr << cmd.TakeError() << std::endl;
    return;  // TODO(pag): Log error.
  }

  auto compiler = d->c_compiler;

  if (source_file_path.endsWith(".cc", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cp", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cpp", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".cxx", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".c++", Qt::CaseInsensitive) ||
      source_file_path.endsWith(".C", Qt::CaseSensitive)) {
    compiler = d->cxx_compiler;
  }

  auto jobs = compiler.CreateJobsForCommand(cmd.TakeValue());
  if (jobs.Failed()) {
    std::cerr << jobs.TakeError() << std::endl;
    return;  // TODO(pag): Log error.
  }

  for (auto job : jobs.TakeValue()) {
    emit sourceFileDoubleClicked(job);
  }
}

} // namespace multiplier
