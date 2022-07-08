// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "ReferenceBrowserView.h"

#include <QApplication>
#include <QBrush>
#include <QHeaderView>
#include <QKeyEvent>
#include <QSplitter>
#include <QThreadPool>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstdint>
#include <map>
#include <tuple>
#include <unordered_map>

#include "CodeTheme.h"
#include "CodeView.h"
#include "Configuration.h"
#include "Multiplier.h"
#include "Util.h"

// NOTE(pag): Put last for Qt.
#include <filesystem>

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

struct InitReferenceHierarchyThread::PrivateData {
  Index index;
  const RawEntityId id;
  FileLocationCache line_cache;
  QTreeWidgetItem * const item_parent;
  const uint64_t counter;

  explicit PrivateData(const Index &index_, RawEntityId id_,
                       const FileLocationCache &line_cache_,
                       QTreeWidgetItem *parent_, uint64_t counter_)
      : index(index_),
        id(id_),
        line_cache(line_cache_),
        item_parent(parent_),
        counter(counter_) {}
};

struct ExpandReferenceHierarchyThread::PrivateData {
  Index index;
  const RawEntityId id;
  FileLocationCache line_cache;
  QTreeWidgetItem * const item_parent;
  const uint64_t counter;
  const int depth;

  explicit PrivateData(const Index &index_, RawEntityId id_,
                       const FileLocationCache &line_cache_,
                       QTreeWidgetItem *parent_, uint64_t counter_,
                       int depth_)
      : index(index_),
        id(id_),
        line_cache(line_cache_),
        item_parent(parent_),
        counter(counter_),
        depth(depth_) {}
};

InitReferenceHierarchyThread::~InitReferenceHierarchyThread(void) {}

InitReferenceHierarchyThread::InitReferenceHierarchyThread(
    const Index &index_, RawEntityId id_, const FileLocationCache &line_cache_,
    QTreeWidgetItem *parent_, uint64_t counter_)
    : d(new PrivateData(index_, id_, line_cache_, parent_, counter_)) {}

ExpandReferenceHierarchyThread::~ExpandReferenceHierarchyThread(void) {}

ExpandReferenceHierarchyThread::ExpandReferenceHierarchyThread(
    const Index &index_, RawEntityId id_, const FileLocationCache &line_cache_,
    QTreeWidgetItem *parent_, uint64_t counter_, int depth_)
    : d(new PrivateData(index_, id_, line_cache_, parent_, counter_, depth_)) {}

namespace {
static constexpr size_t kEmitBatchSize = 32;
}  // namespace

void InitReferenceHierarchyThread::run(void) {
  std::optional<Decl> root_decl = NearestDeclFor(d->index, d->id);
  if (!root_decl) {
    return;
  }

  UserLocations users;
  RawEntityId last_fragment_id = kInvalidEntityId;

  for (Reference ref : root_decl->references()) {
    Stmt stmt = ref.statement();
    if (auto decl = DeclContaining(stmt)) {

      // Send them off one batch at a time. Ideally, send them so that we don't
      // split across fragments.
      Fragment frag = Fragment::containing(decl.value());
      if (users.size() >= kEmitBatchSize && frag.id() != last_fragment_id) {

        // Group them by file; they are already grouped by fragment.
        std::stable_sort(users.begin(), users.end(), UserLocationSort);
        emit UsersOfRoot(d->item_parent, d->counter, root_decl.value(),
                         std::make_shared<UserLocations>(std::move(users)));
      }

      // Populate the cache in this background thread to not block the main
      // thread.
      std::ignore = decl->token().nearest_location(d->line_cache);

      users.emplace_back(decl.value(), stmt.tokens());
      last_fragment_id = frag.id();
    }
  }

  // Group them by file; they are already grouped by fragment.
  std::stable_sort(users.begin(), users.end(), UserLocationSort);
  emit UsersOfRoot(d->item_parent, d->counter, root_decl.value(),
                   std::make_shared<UserLocations>(std::move(users)));
}

void ExpandReferenceHierarchyThread::run(void) {
  auto entity = d->index.entity(d->id);
  if (!std::holds_alternative<Decl>(entity)) {
    return;
  }

  UserLocations users;
  RawEntityId last_fragment_id = kInvalidEntityId;

  for (Reference ref : std::get<Decl>(entity).references()) {
    Stmt stmt = ref.statement();
    if (auto decl = DeclContaining(stmt)) {

      // Send them off one batch at a time. Ideally, send them so that we don't
      // split across fragments.
      Fragment frag = Fragment::containing(decl.value());
      if (users.size() >= kEmitBatchSize && frag.id() != last_fragment_id) {

        // Group them by file; they are already grouped by fragment.
        std::stable_sort(users.begin(), users.end(), UserLocationSort);
        emit UsersOfLevel(d->item_parent, d->counter,
                          std::make_shared<UserLocations>(std::move(users)),
                          d->depth);
      }

      // Populate the cache in this background thread to not block the main
      // thread.
      std::ignore = decl->token().nearest_location(d->line_cache);

      users.emplace_back(decl.value(), stmt.tokens());
      last_fragment_id = frag.id();
    }
  }

  // Group them by file; they are already grouped by fragment.
  std::stable_sort(users.begin(), users.end(), UserLocationSort);
  emit UsersOfLevel(d->item_parent, d->counter,
                    std::make_shared<UserLocations>(std::move(users)),
                    d->depth);
}

struct ReferenceBrowserView::PrivateData {
 public:
  Multiplier &multiplier;

  QVBoxLayout *layout{nullptr};
  QSplitter *splitter{nullptr};

  QTreeWidget *reference_tree{nullptr};

  // Theme used in `code` to highlight the tokens associated with the reference.
  HighlightRangeTheme theme;

  // Code preview.
  CodeView *code{nullptr};
  QTreeWidgetItem *active_item{nullptr};

  // Used to detect re-entrancy issues when the underlying view is swapped out.
  std::atomic<uint64_t> counter;

  struct ItemInfo {
    const Decl decl;

    // We need to be able to scroll the code preview area to the relevant spot.
    // We also configure `PrivateData::theme` to highlight these tokens when
    // this reference is selected. Finally, the contexts of the first token in
    // this range is used for the breadcrumbs.
    TokenRange tokens;
    TokenRange file_tokens;

    // Have we expanded this item yet? When we first create an reference item,
    // we add a "Downloading..." child under it that is hidden, and leave this
    // as `false`. Then, when we first expand this entry, if we transition from
    // `false` to `true`, then we know to remove the dummy downloading item and
    // leave the item empty or populate with the discovered references.
    bool has_been_expanded{false};

    // Is this the first expansion?
    bool is_first_expansion{true};

    // Pending request for expansion. We have to store whether or not there's
    // an outstanding request, because we only get children asynchronously.
    int pending_expansion_request{0};

    inline explicit ItemInfo(Decl decl_)
        : decl(std::move(decl_)) {}
  };

  std::unordered_map<QTreeWidgetItem *, ItemInfo> item_to_info;
  std::unordered_map<RawEntityId, std::filesystem::path> file_id_to_path;

  inline PrivateData(Multiplier &multiplier_)
      : multiplier(multiplier_),
        theme(multiplier.CodeTheme()) {}
};

ReferenceBrowserView::~ReferenceBrowserView(void) {}

ReferenceBrowserView::ReferenceBrowserView(Multiplier &multiplier,
                                           QWidget *parent)
    : QWidget(parent),
      d(new PrivateData(multiplier)) {
  InitializeWidgets();
}

enum : int {
  kEntityColumnIndex,
  kPathColumnIndex,
  kFileColumnIndex,
  kLineColumnIndex,
  kColumnColumnIndex,
  kContextColumnIndex,

  kNumColumns
};

void ReferenceBrowserView::InitializeWidgets(void) {

  d->layout = new QVBoxLayout;
  d->splitter = new QSplitter(Qt::Vertical);

  d->layout->setContentsMargins(0, 0, 0, 0);
  d->layout->addWidget(d->splitter);

  d->reference_tree = new QTreeWidget;
  d->layout->addWidget(d->reference_tree);

  // Add the column headers.
  QHeaderView *header = d->reference_tree->header();
  QTreeWidgetItem *header_item = d->reference_tree->headerItem();
  d->reference_tree->setColumnCount(kNumColumns);
  header_item->setText(kEntityColumnIndex, tr("Entity"));
  header_item->setText(kPathColumnIndex, tr("Path"));
  header_item->setText(kFileColumnIndex, tr("File"));
  header_item->setText(kLineColumnIndex, tr("Line"));
  header_item->setText(kColumnColumnIndex, tr("Column"));
  header_item->setText(kContextColumnIndex, tr("Context"));

  // Customize visibility of columns.
  ReferenceBrowserConfiguration &config =
      d->multiplier.Configuration().reference_browser;
  d->reference_tree->setColumnHidden(kPathColumnIndex, !config.show_file_path);
  d->reference_tree->setColumnHidden(kFileColumnIndex, !config.show_file_name);
  d->reference_tree->setColumnHidden(kLineColumnIndex,
                                     !config.show_line_numbers);
  d->reference_tree->setColumnHidden(kColumnColumnIndex,
                                     !config.show_column_numbers);
  d->reference_tree->setColumnHidden(kContextColumnIndex,
                                     !config.breadcrumbs.visible);

  setWindowTitle(tr("Reference Browser"));
  setLayout(d->layout);

  QList<int> splitter_sizes;
  splitter_sizes.push_back(d->splitter->width() / 2);
  splitter_sizes.push_back(splitter_sizes.back());
  d->splitter->setSizes(splitter_sizes);
  d->splitter->addWidget(d->reference_tree);

  // We'll potentially have a bunch of columns depending on the configuration,
  // so make sure they span to use all available space.
  header->setStretchLastSection(true);
  header->setSectionResizeMode(
      QHeaderView::ResizeToContents);

  // Don't let double click expand things in three; we capture double click so
  // that we can make it open up the use in the code.
  d->reference_tree->setExpandsOnDoubleClick(false);

  // Try to capture keypresses when items are selected.
  d->reference_tree->viewport()->installEventFilter(&(d->multiplier));
  d->reference_tree->installEventFilter(this);

  // Enable sorting. We want to be able to sort by context (breadcrumbs) so that
  // it's easy to pick out when a given thing is used differently among many
  // common uses, e.g. every use but one is inside two nested `if` statements.
  d->reference_tree->setSortingEnabled(true);

  // Disallow multiple selection. If we have grouping by file enabled, then when
  // a user clicks on a file name, we instead jump down to the first entry
  // grouped under that file. This is to make using the up/down arrows easier.
  d->reference_tree->setSelectionMode(
      QAbstractItemView::SelectionMode::SingleSelection);

  // Hide the header.
  d->reference_tree->setHeaderHidden(false);

  // When a user clicks on a cell, we don't want to randomly scroll to the
  // beginning of a cell. That can be jarring.
  d->reference_tree->setAutoScroll(false);

  // Smooth scrolling.
  d->reference_tree->setHorizontalScrollMode(
      QAbstractItemView::ScrollPerPixel);
  d->reference_tree->setVerticalScrollMode(
      QAbstractItemView::ScrollPerPixel);

  // Create and connect the code preview.
  if (config.code_preview.visible) {
    d->code = new CodeView(d->theme, d->multiplier.FileLocationCache());
    d->code->viewport()->installEventFilter(&(d->multiplier));
    d->splitter->addWidget(d->code);

    connect(d->code, &CodeView::TokenPressEvent,
            this, &ReferenceBrowserView::ActOnTokenPressEvent);
  }

  connect(d->reference_tree, &QTreeWidget::itemExpanded,
          this, &ReferenceBrowserView::OnTreeWidgetItemExpanded);

  connect(d->reference_tree, &QTreeWidget::itemPressed,
          this, &ReferenceBrowserView::OnItemClicked);

//  connect(d->reference_tree, &QTreeWidget::itemDoubleClicked,
//          this, &ReferenceBrowserView::OnItemDoubleClicked);

  connect(d->reference_tree, &QTreeWidget::itemSelectionChanged,
          this, &ReferenceBrowserView::OnItemSelectionChanged);

  connect(this, &ReferenceBrowserView::TokenPressEvent,
          &d->multiplier, &Multiplier::ActOnTokenPressEvent);
}

void ReferenceBrowserView::ActOnTokenPressEvent(EventLocations locs) {
  for (EventLocation loc : locs) {
    emit TokenPressEvent(EventSource::kReferenceBrowserPreviewClickSource, loc);
    if (loc.UnpackDeclarationId()) {
      loc.SetFragmentTokenId(kInvalidEntityId);
      loc.SetFileTokenId(kInvalidEntityId);
      emit TokenPressEvent(EventSource::kReferenceBrowserPreviewClickDest, loc);
    }
  }
}

bool ReferenceBrowserView::eventFilter(QObject *watched, QEvent *event) {
  if (event->type() != QEvent::KeyRelease) {
    return false;
  }

  QKeyEvent *kevent = dynamic_cast<QKeyEvent *>(event);
  if (!kevent) {
    return false;
  }

  QTreeWidgetItem *item = d->reference_tree->currentItem();
  if (!item) {
    return false;
  }

  switch (kevent->key()) {
    case Qt::Key_0:
      item->setExpanded(false);
      return true;
    case Qt::Key_1:
      ExpandSubTreeUpTo(item, 1);
      return true;
    case Qt::Key_2:
      ExpandSubTreeUpTo(item, 2);
      return true;
    case Qt::Key_3:
      ExpandSubTreeUpTo(item, 3);
      return true;
    case Qt::Key_4:
      ExpandSubTreeUpTo(item, 4);
      return true;
    case Qt::Key_5:
      ExpandSubTreeUpTo(item, 5);
      return true;
    case Qt::Key_6:
      ExpandSubTreeUpTo(item, 6);
      return true;
    case Qt::Key_7:
      ExpandSubTreeUpTo(item, 7);
      return true;
    case Qt::Key_8:
      ExpandSubTreeUpTo(item, 8);
      return true;
    case Qt::Key_9:
      ExpandSubTreeUpTo(item, 9);
      return true;
    default:
      return false;
  }
}

void ReferenceBrowserView::SetRoots(const EventLocations &new_root_ids) {
  Clear();
  for (const EventLocation &loc : new_root_ids) {
    AddRoot(loc);
  }
}

void ReferenceBrowserView::SetCodePreviewHorizontal(void) {
  d->splitter->setOrientation(Qt::Orientation::Horizontal);
}

void ReferenceBrowserView::SetCodePreviewVertical(void) {
  d->splitter->setOrientation(Qt::Orientation::Vertical);
}

void ReferenceBrowserView::Clear(void) {
  d->item_to_info.clear();
  d->reference_tree->clear();
  d->active_item = nullptr;
  d->counter.fetch_add(1u);
  if (d->code) {
    d->code->Clear();
    d->code->hide();
  }
  update();
}

void ReferenceBrowserView::Focus(void) {
  d->reference_tree->setFocus();
}

void ReferenceBrowserView::OnDownloadedFileList(FilePathList files) {
  for (auto &[path, index] : files) {
    d->file_id_to_path.emplace(index, std::move(path));
  }
}

void ReferenceBrowserView::AddRoot(EventLocation loc) {
  auto decl_id = loc.UnpackDeclarationId();
  if (!decl_id) {
    return;
  }

  RawEntityId eid = EntityId(decl_id.value());
  QTreeWidgetItem *root_item = new QTreeWidgetItem;
  root_item->setText(
      0,
      tr("Downloading entity %1 references...").arg(eid));
  d->reference_tree->addTopLevelItem(root_item);

  const Index &index = d->multiplier.Index();
  auto expander = new InitReferenceHierarchyThread(
      index, eid, d->multiplier.FileLocationCache(),
      root_item, d->counter.load());

  expander->setAutoDelete(true);

  connect(expander, &InitReferenceHierarchyThread::UsersOfRoot,
          this, &ReferenceBrowserView::OnUsersOfFirstLevel);

  QThreadPool::globalInstance()->start(expander);
}

void ReferenceBrowserView::OnTreeWidgetItemExpanded(QTreeWidgetItem *item) {

  // Weird; might be a re-entrancy issue, or might be expanding a file entry.
  auto it = d->item_to_info.find(item);
  if (it == d->item_to_info.end()) {
    return;
  }

  auto &info = it->second;
  auto depth = info.pending_expansion_request;
  info.pending_expansion_request = 0;

  if (info.has_been_expanded) {
    return;  // Already attempted to expand.
  }

  // Mark as having previously been expanded.
  it->second.has_been_expanded = true;

  const Index &index = d->multiplier.Index();
  auto expander = new ExpandReferenceHierarchyThread(
      index, it->second.decl.id(), d->multiplier.FileLocationCache(),
      item, d->counter.load(), depth);

  expander->setAutoDelete(true);

  connect(expander, &ExpandReferenceHierarchyThread::UsersOfLevel,
          this, &ReferenceBrowserView::OnUsersOfLevel);

  QThreadPool::globalInstance()->start(expander);
}

void ReferenceBrowserView::FillRow(
    QTreeWidgetItem *item, const Decl &decl, const Token &use) const {

  ReferenceBrowserConfiguration &config =
      d->multiplier.Configuration().reference_browser;

  // Format the declaration column. If we have a name then use it, otherwise
  // use the stringized enumerator name for the declaration kind, coupled with
  // the entity ID.
  //
  // TODO(pag): Eventually use symbol names in here.
  item->setText(0, DeclName(decl));

  auto color = qApp->palette().text().color();
  color = QColor::fromRgbF(
      color.redF(), color.greenF(), color.blueF(), color.alphaF() * 0.75);

  // Show the line and column numbers.
  if (auto loc = use.nearest_location(d->multiplier.FileLocationCache())) {
    auto file = File::containing(use);
    RawEntityId file_id = file ? file->id() : kInvalidEntityId;

    if (auto fp_it = d->file_id_to_path.find(file_id);
        fp_it != d->file_id_to_path.end()) {
      item->setForeground(kPathColumnIndex, color);
      item->setTextAlignment(kPathColumnIndex, Qt::AlignRight);
      item->setText(
          kPathColumnIndex,
          QString::fromStdString(fp_it->second.generic_string()));

      item->setForeground(kFileColumnIndex, color);
      item->setTextAlignment(kFileColumnIndex, Qt::AlignRight);
      item->setText(
          kFileColumnIndex,
          QString::fromStdString(fp_it->second.filename().string()));

#ifndef QT_NO_TOOLTIP
      item->setToolTip(
          kFileColumnIndex,
          QString::fromStdString(fp_it->second.generic_string()));
#endif
    }

    item->setForeground(kLineColumnIndex, color);
    item->setText(kLineColumnIndex, QString::number(loc->first));  // Line.
#ifndef QT_NO_TOOLTIP
    item->setToolTip(kLineColumnIndex, tr("Line %1").arg(loc->first));
#endif

    item->setForeground(kColumnColumnIndex, color);
    item->setText(kColumnColumnIndex, QString::number(loc->second));  // Column.
#ifndef QT_NO_TOOLTIP
    item->setToolTip(kColumnColumnIndex, tr("Column %1").arg(loc->second));
#endif
  }

  // Show the context breadcrumbs. This is a chain of stringized enumerators
  // derived from the token contexts.
  item->setForeground(kContextColumnIndex, color);
  item->setText(
      kContextColumnIndex,
      TokenBreadCrumbs(use, config.breadcrumbs.run_length_encode));
}

void ReferenceBrowserView::OnUsersOfFirstLevel(
    QTreeWidgetItem *root_item, uint64_t counter, std::optional<Decl> root_decl,
    UserLocationsPtr users) {

  // Something else was requested before the background thread returned.
  if (counter != d->counter.load() ||
      0 < d->reference_tree->indexOfTopLevelItem(root_item)) {
    return;
  }

  // This is the first batch of results for this root.
  auto id_it = d->item_to_info.find(root_item);
  auto is_first_batch_of_first_root = false;
  auto was_initialized = false;
  if (id_it == d->item_to_info.end()) {

    FillRow(root_item, root_decl.value(), root_decl->token());
    d->item_to_info.clear();

    is_first_batch_of_first_root = d->item_to_info.empty();
    was_initialized = true;

    auto &item = d->item_to_info.emplace(
        root_item, std::move(root_decl.value())).first->second;

    item.tokens = item.decl.token();
    item.file_tokens = item.tokens.file_tokens().strip_whitespace();
  }

  OnUsersOfLevel(root_item, counter, std::move(users), 0);

  // If this is the first time that we're adding items to the root (as we may
  // have multiple batches of child items to add to the root, or we might have
  // multiple roots), then we want to shift the cursor focus to the first
  // `root_item`, so that if the user subsequently presses a key, e.g. `3`, then
  // the `eventFilter` will trigger recursive expansion of the references
  // tree up to depth 3.
  if (is_first_batch_of_first_root) {
    d->reference_tree->setFocus();
    root_item->setSelected(true);
    d->reference_tree->setCurrentItem(root_item);
  }

  // By default, if we've just initialized this root, then trigger an expansion
  // of its immediate children.
  if (was_initialized) {
    OnItemClicked(root_item, 0);
  }
}

int ReferenceBrowserView::ExpandSubTreeUpTo(
    QTreeWidgetItem *item, int depth, int count) {
  if (0 >= depth) {
    return count;
  }

  auto id_it = d->item_to_info.find(item);
  if (id_it == d->item_to_info.end()) {
    return count;
  }

  auto &info = id_it->second;

  depth = std::max(depth, info.pending_expansion_request);
  info.pending_expansion_request = 0;

  if (!info.has_been_expanded) {
    info.pending_expansion_request = depth;
    OnTreeWidgetItemExpanded(item);
    item->setExpanded(true);
    return count;
  }

  item->setExpanded(true);
  for (auto i = 0, max_i = item->childCount(); i < max_i; ++i, ++count) {
    QTreeWidgetItem *child_item = item->child(i);
    count = ExpandSubTreeUpTo(child_item, depth - 1, count);

    // Trigger re-rendering.
    if (count >= 20) {
      update();
    }
  }

  return count;
}

void ReferenceBrowserView::OnUsersOfLevel(
    QTreeWidgetItem *parent_item, uint64_t counter, UserLocationsPtr users,
    int depth) {

  // Something else was requested before the background thread returned.
  if (counter != d->counter.load()) {
    return;
  }

  // Something else was requested before the background thread returned.
  auto id_it = d->item_to_info.find(parent_item);
  if (id_it == d->item_to_info.end()) {
    return;
  }

  // Remove the `Downloading...` item.
  auto &info = id_it->second;
  info.has_been_expanded = true;
  if (info.is_first_expansion) {
    info.is_first_expansion = false;
    while (parent_item->childCount()) {
      parent_item->removeChild(parent_item->child(0));
    }
  }

  // Nothing to show.
  if (users->empty()) {
    update();
    return;
  }

  auto add_user = [=, this] (QTreeWidgetItem *parent, Decl decl, TokenRange tokens) {
    QTreeWidgetItem *user_item = new QTreeWidgetItem;
    if (tokens) {
      FillRow(user_item, decl, tokens[0]);
    } else {
      FillRow(user_item, decl, decl.token());
    }
    parent->addChild(user_item);

    PrivateData::ItemInfo &child_id =
        d->item_to_info.emplace(user_item, std::move(decl)).first->second;
    child_id.tokens = std::move(tokens);
    child_id.file_tokens = child_id.tokens.file_tokens().strip_whitespace();
    child_id.has_been_expanded = false;

    QTreeWidgetItem *download_item = new QTreeWidgetItem;
    download_item->setText(0, tr("Downloading..."));

    user_item->addChild(download_item);
    user_item->setExpanded(false);

    ExpandSubTreeUpTo(user_item, depth - 1);
  };

  ReferenceBrowserConfiguration &config =
      d->multiplier.Configuration().reference_browser;

  for (auto &[decl, tokens] : *users) {
    add_user(parent_item, std::move(decl), std::move(tokens));
  }

  parent_item->setExpanded(true);

  update();
}

void ReferenceBrowserView::OnItemSelectionChanged(void) {
  for (QTreeWidgetItem *item : d->reference_tree->selectedItems()) {
    OnItemClicked(item, 0);
    return;
  }
}

//void ReferenceBrowserView::OnItemDoubleClicked(
//    QTreeWidgetItem *item, int column) {
//  auto id_it = d->item_to_info.find(item);
//  if (id_it == d->item_to_info.end()) {
//    return;
//  }
//
//  const PrivateData::ItemInfo &info = id_it->second;
//
//  EventLocation loc;
//  loc.referenced_decl_id = info.decl.id();
//
//  // Try to go to the specific use.
//  for (const Token &tok : info.tokens) {
//    loc.fragment_token_id = tok.id();
//    break;
//  }
//
//  for (const Token &file_tok : info.file_tokens) {
//    loc.file_token_id = file_tok.id();
//    break;
//  }
//
//  emit TokenEvent(EventSource::kReferenceBrowser, loc);
//}

void ReferenceBrowserView::OnItemClicked(
    QTreeWidgetItem *item, int column) {
  auto id_it = d->item_to_info.find(item);
  if (id_it == d->item_to_info.end()) {
    return;
  }

  const PrivateData::ItemInfo &info = id_it->second;

  if (item != d->active_item) {
    d->active_item = item;
    ReferenceBrowserConfiguration &config =
        d->multiplier.Configuration().reference_browser;

    // A human has just clicked on this thing, show the code preview.
    const Index &index = d->multiplier.Index();
    auto [fragment_id, offset] = GetFragmentOffset(info.decl.id());
    if (fragment_id != kInvalidEntityId) {
      if (config.code_preview.visible && d->code) {
        d->code->show();
        d->theme.HighlightFileTokenRange(info.file_tokens);
        d->code->SetFragment(index, fragment_id);
        d->code->ScrollToFileToken(info.file_tokens);
      }
    } else if (d->code) {
      d->code->hide();
    }
  }

  EventLocation loc;
  loc.SetReferencedDeclarationId(info.decl.id());

  // Try to go to the specific use.
  for (const Token &tok : info.tokens) {
    loc.SetFragmentTokenId(tok.id());
    break;
  }

  for (const Token &file_tok : info.file_tokens) {
    loc.SetFileTokenId(file_tok.id());
    break;
  }

  emit TokenPressEvent(EventSource::kReferenceBrowser, loc);
}

}  // namespace mx::gui
