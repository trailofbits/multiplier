// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ReferenceHierarchyView.h"

#include <QHeaderView>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <unordered_map>

namespace mx::gui {
namespace {

static RawEntityId CanonicalId(Decl decl) {
  for (auto redecl : decl.redeclarations()) {
    return redecl.id();
  }
  return decl.id();
}

using FragmentOffset = std::pair<FragmentId, uint32_t>;

static FragmentOffset GetFragmentOffset(RawEntityId id) {
  VariantId vid = EntityId(id).Unpack();
  if (std::holds_alternative<DeclarationId>(vid)) {
    auto eid = std::get<DeclarationId>(vid);
    return {eid.fragment_id, eid.offset};

  } else if (std::holds_alternative<StatementId>(vid)) {
    auto eid = std::get<StatementId>(vid);
    return {eid.fragment_id, eid.offset};

  } else if (std::holds_alternative<TypeId>(vid)) {
    auto eid = std::get<TypeId>(vid);
    return {eid.fragment_id, eid.offset};

  } else if (std::holds_alternative<FragmentTokenId>(vid)) {
    auto eid = std::get<FragmentTokenId>(vid);
    return {eid.fragment_id, eid.offset};

  } else if (std::holds_alternative<TokenSubstitutionId>(vid)) {
    auto eid = std::get<TokenSubstitutionId>(vid);
    return {eid.fragment_id, eid.offset};

  } else {
    return {0ul, 0u};
  }
}

}  // namespace

ExpandReferenceHierarchyThread::~ExpandReferenceHierarchyThread(void) {}

void ExpandReferenceHierarchyThread::run(void) {
  std::vector<RawEntityId> users;

  auto entity = index.entity(id);

  if (std::holds_alternative<Decl>(entity)) {
    auto found = false;
    auto decl = std::get<Decl>(entity);
    for (Reference ref : decl.references()) {
      users.push_back(ref.statement().id());
      found = true;
    }

    if (!found) {
      if (auto containing_stmt = Stmt::containing(decl)) {
        users.push_back(containing_stmt->id());

      } else if (auto containing_decl = Decl::containing(decl)) {
        users.push_back(CanonicalId(std::move(containing_decl.value())));
      }
    }

  } else if (std::holds_alternative<Stmt>(entity)) {
    auto stmt = std::get<Stmt>(entity);
    if (auto containing_decl = Decl::containing(stmt)) {
      users.push_back(CanonicalId(std::move(containing_decl.value())));

    } else if (auto containing_stmt = Stmt::containing(stmt)) {
      users.push_back(containing_stmt->id());
    }

  } else if (std::holds_alternative<Token>(entity)) {
    auto tok = std::get<Token>(entity);
    if (auto containing_decl = Decl::containing(tok)) {
      users.push_back(CanonicalId(std::move(containing_decl.value())));

    } else if (auto containing_stmt = Stmt::containing(tok)) {
      users.push_back(containing_stmt->id());
    }

  } else if (std::holds_alternative<Type>(entity)) {
    auto type = std::get<Type>(entity);
    if (auto typedef_type = TypedefType::from(type)) {
      users.push_back(CanonicalId(typedef_type->declaration()));

    } else if (auto tag_decl = type.as_tag_declaration()) {
      users.push_back(CanonicalId(std::move(tag_decl.value())));

    } else if (auto deduced_type = DeducedType::from(type)) {
      if (auto deduced_typedef = TypedefType::from(deduced_type.value())) {
        users.push_back(CanonicalId(deduced_typedef->declaration()));

      } else if (auto deduced_tag_decl = deduced_type->as_tag_declaration()) {
        users.push_back(CanonicalId(std::move(deduced_tag_decl.value())));
      }
    }
  }

  // Keep only unique ones.
  std::sort(users.begin(), users.end());
  auto it = std::unique(users.begin(), users.end());
  users.erase(it, users.end());

  // Group them by fragment.
  std::stable_sort(
      users.begin(), users.end(), [] (RawEntityId a, RawEntityId b) {
        return std::less<FragmentOffset>{}(GetFragmentOffset(a),
                                           GetFragmentOffset(b));
      });

  emit UsersOfLevel(item_parent, id, std::move(users));
}

struct ReferenceHierarchyView::PrivateData {
 public:
  Index index;
  QTreeWidgetItem *counter{nullptr};
  QVBoxLayout *layout{nullptr};
  QTreeWidget *reference_tree{nullptr};

  std::unordered_map<QTreeWidgetItem *, std::pair<RawEntityId, bool>>
      item_to_id;
};

ReferenceHierarchyView::~ReferenceHierarchyView(void) {}

ReferenceHierarchyView::ReferenceHierarchyView(QWidget *parent)
    : QWidget(parent),
      d(new PrivateData) {
  InitializeWidgets();
}

void ReferenceHierarchyView::InitializeWidgets(void) {
  d->layout = new QVBoxLayout;
  d->layout->setContentsMargins(0, 0, 0, 0);

  d->reference_tree = new QTreeWidget;
  d->layout->addWidget(d->reference_tree);

  setWindowTitle(tr("Reference Hierarchy"));
  setLayout(d->layout);

  d->reference_tree->setHeaderHidden(true);
  d->reference_tree->setColumnCount(1);
  d->reference_tree->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
  d->reference_tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
  d->reference_tree->header()->setStretchLastSection(false);

  connect(d->reference_tree, &QTreeWidget::itemExpanded,
          this, &ReferenceHierarchyView::OnTreeWidgetItemExpanded);
}

void ReferenceHierarchyView::Clear(void) {
  d->item_to_id.clear();
  d->counter = &(d->counter[1]);
  d->reference_tree->clear();
  update();
}

void ReferenceHierarchyView::SetIndex(Index index) {
  d->index = std::move(index);
  Clear();
}

void ReferenceHierarchyView::AddRoot(RawEntityId root_id) {
  auto expander = new ExpandReferenceHierarchyThread(
      d->index, root_id, d->counter);

  expander->setAutoDelete(true);

  connect(expander, &ExpandReferenceHierarchyThread::UsersOfLevel,
          this, &ReferenceHierarchyView::OnUsersOfFirstLevel);

  QThreadPool::globalInstance()->start(expander);
}

void ReferenceHierarchyView::OnTreeWidgetItemExpanded(QTreeWidgetItem *item) {

  item->setExpanded(true);

  auto it = d->item_to_id.find(item);
  if (it == d->item_to_id.end()) {
    return;  // Weird.
  }

  if (it->second.second) {
    item->setExpanded(true);
    return;  // Already attempted to expand.
  }

  it->second.second = true;  // Mark as having previously been expanded.

  auto expander = new ExpandReferenceHierarchyThread(
      d->index, it->second.first, item);

  expander->setAutoDelete(true);

  connect(expander, &ExpandReferenceHierarchyThread::UsersOfLevel,
          this, &ReferenceHierarchyView::OnUsersOfLevel);

  QThreadPool::globalInstance()->start(expander);
}

void ReferenceHierarchyView::OnUsersOfFirstLevel(
    QTreeWidgetItem *counter, RawEntityId use_id,
    std::vector<RawEntityId> users) {

  // Something else was requested before the background thread returned.
  if (counter != d->counter) {
    return;
  }

  QTreeWidgetItem *root_item = new QTreeWidgetItem;
  root_item->setText(0, QString::number(use_id));
  d->reference_tree->addTopLevelItem(root_item);

  // Record the ID of this item, and mark it as expanded.
  auto &root_id = d->item_to_id[root_item];
  root_id.first = use_id;
  root_id.second = true;  // Mark as prevously expanded.

  OnUsersOfLevel(root_item, use_id, std::move(users));
}

void ReferenceHierarchyView::OnUsersOfLevel(
    QTreeWidgetItem *parent_item, RawEntityId use_id,
    std::vector<RawEntityId> users) {

  // Something else was requested before the background thread returned.
  if (d->item_to_id.find(parent_item) == d->item_to_id.end()) {
    return;
  }

  // Remove the `Downloading...` item.
  while (parent_item->childCount()) {
    parent_item->removeChild(parent_item->child(0));
  }

  // Nothing to show.
  if (users.empty()) {
    update();
    return;
  }

  for (auto user_id : users) {
    QTreeWidgetItem *user_item = new QTreeWidgetItem;
    user_item->setText(0, QString::number(user_id));
    parent_item->addChild(user_item);

    auto &child_id = d->item_to_id[user_item];
    child_id.first = user_id;
    child_id.second = false;  // Mark as not yet expanded.

    QTreeWidgetItem *download_item = new QTreeWidgetItem;
    download_item->setText(0, tr("Downloading..."));

    user_item->addChild(download_item);
    user_item->setExpanded(false);
  }
  update();
}

}  // namespace mx::gui
