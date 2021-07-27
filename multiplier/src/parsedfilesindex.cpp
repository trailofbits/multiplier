/*
  Copyright (c) 2021-present, Trail of Bits, Inc.
  All rights reserved.

  This source code is licensed in accordance with the terms specified in
  the LICENSE file found in the root directory of this source tree.
*/

#include "parsedfilesindex.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <array>
#include <iostream>

#include <pasta/AST/AST.h>
#include <pasta/Util/File.h>

namespace multiplier {

struct ParsedFilesIndex::PrivateData final {
  QTreeWidget *source_file_tree{nullptr};
};

ParsedFilesIndex::ParsedFilesIndex(QWidget *parent)
    : QFrame(parent), d(new PrivateData) {
  setWindowTitle(tr("Parsed Files"));

  auto layout = new QVBoxLayout();
  layout->setContentsMargins(0, 0, 0, 0);
  setLayout(layout);

  d->source_file_tree = new QTreeWidget();
  d->source_file_tree->setHeaderHidden(true);
  d->source_file_tree->setExpandsOnDoubleClick(false);
  layout->addWidget(d->source_file_tree);

  connect(d->source_file_tree, &QTreeWidget::itemActivated, this,
          &ParsedFilesIndex::onTreeWidgetItemActivated);
}

ParsedFilesIndex::~ParsedFilesIndex() {}

void ParsedFilesIndex::gotAST(std::shared_ptr<pasta::AST> ast) {
  QMap<QString, QTreeWidgetItem *> root_item_map;

  QTreeWidgetItem *root_item = new QTreeWidgetItem();

  for (const pasta::File &file : ast->ParsedFiles()) {

    QTreeWidgetItem *parent = nullptr;

    std::filesystem::path path = file.Path();
    std::filesystem::path accumulated_path = path.root_path();
    std::filesystem::path rel_path = path.relative_path();

    for (auto parent_name : rel_path) {
      accumulated_path /= parent_name;
      QString path_name = QString::fromStdString(accumulated_path.generic_string());
      QTreeWidgetItem *&item = root_item_map[path_name];
      if (!item) {
        item = new QTreeWidgetItem();
        item->setText(0, QString::fromStdString(parent_name.generic_string()));
        if (parent) {
          parent->addChild(item);
        } else {
          root_item->setText(
              0, QString::fromStdString(path.root_path().generic_string()));
          root_item->addChild(item);
        }
      }
      parent = item;
    }

    parent->setText(1, QString::fromStdString(path.generic_string()));
  }

  d->source_file_tree->addTopLevelItem(root_item);
  d->source_file_tree->expandAll();
  d->source_file_tree->sortItems(0, Qt::AscendingOrder);
}

void ParsedFilesIndex::reset() { d->source_file_tree->reset(); }

void ParsedFilesIndex::onTreeWidgetItemActivated(QTreeWidgetItem *item, int) {

  if (item->childCount() != 0 || item->columnCount() != 4) {
    return;
  }

  auto source_file_path = item->text(1);
  std::cerr << "Clicked " << source_file_path.toStdString() << std::endl;
#if 0
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
#endif
}

} // namespace multiplier
