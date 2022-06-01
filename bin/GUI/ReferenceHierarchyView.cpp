// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ReferenceHierarchyView.h"

#include <QBrush>
#include <QHeaderView>
#include <QSplitter>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <filesystem>
#include <map>
#include <unordered_map>

#include "CodeView.h"
#include "Util.h"

#include <iostream>

namespace mx::gui {
namespace {

template <typename T>
static std::optional<Decl> DeclContaining(const T &thing) {
  if (auto func = FunctionDecl::containing(thing)) {
    return func.value();

  } else if (auto field = FieldDecl::containing(thing)) {
    return field.value();

  } else if (auto var = VarDecl::containing(thing)) {
    if (var->is_local_variable_declaration()) {
      return DeclContaining<Decl>(var.value());

    } else {
      return var.value();
    }
  } else {
    return std::nullopt;
  }
};

static bool UserLocationSort(const UserLocation &a, const UserLocation &b) {
  if (!a.second && !b.second) {
    return false;
  } else if (!a.second && b.second) {
    return false;
  } else if (a.second && !b.second) {
    return false;
  }

  return std::less<EntityBaseOffsetPair>{}(GetFileOffset(a.second[0].id()),
                                           GetFileOffset(b.second[0].id()));
}

}  // namespace

InitReferenceHierarchyThread::~InitReferenceHierarchyThread(void) {}
ExpandReferenceHierarchyThread::~ExpandReferenceHierarchyThread(void) {}

void InitReferenceHierarchyThread::run(void) {

  auto entity = index.entity(id);
  if (!std::holds_alternative<Decl>(entity)) {
    return;
  }

  UserLocations users;

  const Decl &root_decl = std::get<Decl>(entity);
  for (Reference ref : root_decl.references()) {
    Stmt stmt = ref.statement();
    if (auto decl = DeclContaining(stmt)) {

      // Populate the cache in this background thread to not block the main
      // thread.
      (void) decl->token().nearest_location(line_cache);

      users.emplace_back(decl.value(),
                         stmt.tokens().file_tokens().strip_whitespace());
    }
  }

  // Group them by file; they are already grouped by fragment.
  std::stable_sort(users.begin(), users.end(), UserLocationSort);

  emit UsersOfRoot(item_parent, root_decl, std::move(users));
}

void ExpandReferenceHierarchyThread::run(void) {
  auto entity = index.entity(id);
  if (!std::holds_alternative<Decl>(entity)) {
    return;
  }

  UserLocations users;

  for (Reference ref : std::get<Decl>(entity).references()) {
    Stmt stmt = ref.statement();
    if (auto decl = DeclContaining(stmt)) {

      // Populate the cache in this background thread to not block the main
      // thread.
      (void) decl->token().nearest_location(line_cache);

      users.emplace_back(decl.value(), stmt.tokens().file_tokens());
    }
  }

  // Group them by file; they are already grouped by fragment.
  std::stable_sort(users.begin(), users.end(), UserLocationSort);

  emit UsersOfLevel(item_parent, std::move(users));
}

struct ReferenceHierarchyView::PrivateData {
 public:
  Index index;
  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};
  QTreeWidget *reference_tree{nullptr};
  HighlightRangeTheme theme;
  CodeView *code{nullptr};
  QTreeWidgetItem *active_item{nullptr};
  FileLocationCache line_cache;

  struct ItemInfo {
    const Decl decl;
    TokenRange tokens;  // For scrolling and highlighting.
    bool has_been_expanded{false};

    inline explicit ItemInfo(Decl decl_)
        : decl(std::move(decl_)) {}
  };

  std::unordered_map<QTreeWidgetItem *, ItemInfo> item_to_info;
  std::unordered_map<FileId, QString> file_id_to_path;

  inline PrivateData(const CodeTheme &theme_)
      : theme(theme_) {}
};

ReferenceHierarchyView::~ReferenceHierarchyView(void) {}

ReferenceHierarchyView::ReferenceHierarchyView(const CodeTheme &theme_,
                                               QWidget *parent)
    : QWidget(parent),
      d(new PrivateData(theme_)) {
  InitializeWidgets();
}

void ReferenceHierarchyView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->splitter = new QSplitter(Qt::Horizontal);

  d->layout->setContentsMargins(0, 0, 0, 0);
  d->layout->addWidget(d->splitter);

  d->reference_tree = new QTreeWidget;
  d->layout->addWidget(d->reference_tree);

  setWindowTitle(tr("Reference Hierarchy"));
  setLayout(d->layout);

  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);

  d->splitter->addWidget(d->reference_tree);

  d->reference_tree->setHeaderHidden(true);
  d->reference_tree->setColumnCount(1);
  d->reference_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->reference_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->reference_tree->header()->setStretchLastSection(false);

  connect(d->reference_tree, &QTreeWidget::itemExpanded,
          this, &ReferenceHierarchyView::OnTreeWidgetItemExpanded);

  connect(d->reference_tree, &QTreeWidget::itemPressed,
          this, &ReferenceHierarchyView::OnItemPressed);

  connect(d->reference_tree, &QTreeWidget::itemSelectionChanged,
          this, &ReferenceHierarchyView::OnItemSelectionChanged);
}

void ReferenceHierarchyView::Clear(void) {
  d->item_to_info.clear();
  d->reference_tree->clear();
  d->active_item = nullptr;
  update();
}

void ReferenceHierarchyView::SetIndex(Index index) {
  d->file_id_to_path.clear();
  d->index = std::move(index);
  for (auto &[path, index] : d->index.file_paths()) {
    d->file_id_to_path.emplace(
        index, QString::fromStdString(path.generic_string()));
  }
  Clear();
}

void ReferenceHierarchyView::AddRoot(RawEntityId root_id) {
  QTreeWidgetItem *root_item = new QTreeWidgetItem;
  root_item->setText(0, tr("Downloading entity %1 references...").arg(root_id));
  d->reference_tree->addTopLevelItem(root_item);

  auto expander = new InitReferenceHierarchyThread(
      d->index, root_id, d->line_cache, root_item);

  expander->setAutoDelete(true);

  connect(expander, &InitReferenceHierarchyThread::UsersOfRoot,
          this, &ReferenceHierarchyView::OnUsersOfFirstLevel);

  QThreadPool::globalInstance()->start(expander);
}

void ReferenceHierarchyView::OnTreeWidgetItemExpanded(QTreeWidgetItem *item) {

  item->setExpanded(true);

  auto it = d->item_to_info.find(item);
  if (it == d->item_to_info.end()) {
    return;  // Weird.
  }

  if (it->second.has_been_expanded) {
    item->setExpanded(true);
    return;  // Already attempted to expand.
  }

  // Mark as having previously been expanded.
  it->second.has_been_expanded = true;

  auto expander = new ExpandReferenceHierarchyThread(
      d->index, it->second.decl.id(), d->line_cache, item);

  expander->setAutoDelete(true);

  connect(expander, &ExpandReferenceHierarchyThread::UsersOfLevel,
          this, &ReferenceHierarchyView::OnUsersOfLevel);

  QThreadPool::globalInstance()->start(expander);
}

QString ReferenceHierarchyView::RowName(
    const Decl &decl, const Token &use) const {
  QString decl_name;
  if (auto nd = NamedDecl::from(decl)) {
    if (auto name_data = nd->name(); !name_data.empty()) {
      decl_name = QString::fromUtf8(name_data.data(),
                                    static_cast<int>(name_data.size()));
    } else {
      decl_name = QString("%1(%2)").arg(EnumeratorName(decl.category()))
                                   .arg(decl.id());
    }
  } else {
    decl_name = QString("%1(%2)").arg(EnumeratorName(decl.category()))
                                 .arg(decl.id());
  }
  if (auto loc = use.nearest_location(d->line_cache)) {
    decl_name.append(QString(":%1:%2").arg(loc->first)
                                                .arg(loc->second));
  }
  return decl_name;
}

void ReferenceHierarchyView::OnUsersOfFirstLevel(
    QTreeWidgetItem *root_item, std::optional<Decl> root_decl,
    UserLocations users) {

  // Something else was requested before the background thread returned.
  if (0 < d->reference_tree->indexOfTopLevelItem(root_item)) {
    return;
  }

  root_item->setText(0, RowName(root_decl.value(), root_decl->token()));
  d->item_to_info.clear();

  auto &item = d->item_to_info.emplace(
      root_item, std::move(root_decl.value())).first->second;

  if (auto ft = item.decl.token().nearest_file_token()) {
    item.tokens = ft.value();
  }

  OnUsersOfLevel(root_item, std::move(users));
  OnItemPressed(root_item, 0);
}

void ReferenceHierarchyView::OnUsersOfLevel(
    QTreeWidgetItem *parent_item, UserLocations users) {

  // Something else was requested before the background thread returned.
  auto id_it = d->item_to_info.find(parent_item);
  if (id_it == d->item_to_info.end()) {
    return;
  }

  id_it->second.has_been_expanded = true;

  // Remove the `Downloading...` item.
  while (parent_item->childCount()) {
    parent_item->removeChild(parent_item->child(0));
  }

  // Nothing to show.
  if (users.empty()) {
    update();
    return;
  }


  auto add_user = [=] (QTreeWidgetItem *parent, Decl decl, TokenRange tokens) {
    QTreeWidgetItem *user_item = new QTreeWidgetItem;
    if (tokens) {
      user_item->setText(0, RowName(decl, tokens[0]));
    } else {
      user_item->setText(0, RowName(decl, decl.token()));
    }
    parent->addChild(user_item);

    PrivateData::ItemInfo &child_id =
        d->item_to_info.emplace(user_item, std::move(decl)).first->second;
    child_id.tokens = std::move(tokens);
    child_id.has_been_expanded = false;

    QTreeWidgetItem *download_item = new QTreeWidgetItem;
    download_item->setText(0, tr("Downloading..."));

    user_item->addChild(download_item);
    user_item->setExpanded(false);
  };

  std::map<QString, QTreeWidgetItem *> file_users;
  UserLocations other_users;
  for (auto &[decl, tokens] : users) {
    if (std::optional<File> file = File::containing(decl)) {
      if (auto id_it = d->file_id_to_path.find(file->id());
          id_it != d->file_id_to_path.end()) {

        QTreeWidgetItem *&file_parent = file_users[id_it->second];
        if (!file_parent) {
          file_parent = new QTreeWidgetItem;
          file_parent->setText(0, id_it->second);
        }

        add_user(file_parent, std::move(decl), std::move(tokens));
        continue;
      }
    }

    add_user(parent_item, std::move(decl), std::move(tokens));
    other_users.emplace_back(std::move(decl), std::move(tokens));
  }

  for (const auto &[path, file_item] : file_users) {
    parent_item->addChild(file_item);
    file_item->setExpanded(true);
  }

  parent_item->setExpanded(true);

  update();
}

void ReferenceHierarchyView::OnItemSelectionChanged(void) {

  for (auto item : d->reference_tree->selectedItems()) {
    auto id_it = d->item_to_info.find(item);
    if (id_it == d->item_to_info.end()) {
      if (item->childCount()) {
        d->reference_tree->clearSelection();
        d->reference_tree->setItemSelected(item, false);
        d->reference_tree->setItemSelected(item->child(0), true);
        return;
      }
    } else {
      OnItemPressed(item, 0);
      return;
    }
  }
}

void ReferenceHierarchyView::OnItemPressed(
    QTreeWidgetItem *item, int column) {
  auto id_it = d->item_to_info.find(item);
  if (id_it == d->item_to_info.end()) {
    return;
  }

  if (item == d->active_item) {
    return;
  }

  d->active_item = item;

  if (!d->code) {
    d->code = new CodeView(CodeViewKind::kMultiLine, d->theme);
    d->splitter->addWidget(d->code);
  }

  const PrivateData::ItemInfo &info = id_it->second;

  auto [fragment_id, offset] = GetFragmentOffset(info.decl.id());
  if (fragment_id != kInvalidEntityId) {
    d->theme.SetRangeToHighlight(info.tokens);
    d->code->show();
    d->code->SetFragment(d->index, fragment_id);
    d->code->ScrollToToken(info.tokens);
  } else {
    d->code->hide();
  }
}

}  // namespace mx::gui
