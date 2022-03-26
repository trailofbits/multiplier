// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <filesystem>
#include <memory>
#include <multiplier/API.h>
#include <optional>
#include <QPaintEvent>
#include <QRunnable>
#include <QTabWidget>

namespace mx::gui {

class DownloadFileThread final : public QObject, public QRunnable {
  Q_OBJECT

 private:
  const EntityProvider::Ptr ep;
  const FileId file_id;
  void run(void);

 public:
  virtual ~DownloadFileThread(void);
  inline explicit DownloadFileThread(EntityProvider::Ptr ep_,
                                     FileId file_id_)
      : ep(std::move(ep_)),
        file_id(file_id_) {}

 signals:
  void DownloadedFile(std::optional<File> file);
};

class FileView final : public QTabWidget {
  Q_OBJECT

  struct PrivateData;
  std::unique_ptr<PrivateData> d;

 public:
  virtual ~FileView(void);
  FileView(EntityProvider::Ptr ep_, std::filesystem::path file_path,
           FileId file_id, QWidget *parent = nullptr);

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  void DownloadFileInBackground(EntityProvider::Ptr ep, FileId file_id);
  void InitializeWidgets(void);

 private slots:
  void OnDownloadedFile(std::optional<File> file);
};

//class SourceCodeView final : public ITextView {
//  Q_OBJECT
//  Q_INTERFACES(irene::gui::ITextView)
//
// private:
//  using ITextView::SetModel;
//
// public:
//  virtual ~SourceCodeView(void);
//
//  SourceCodeView(QWidget *parent=nullptr);
//
//  template <typename T>
//  inline void SetModel(std::shared_ptr<T> model) {
//    if constexpr (std::is_same_v<T, ITextModel>) {
//      this->ITextView::SetModel(std::move(model));
//      return;
//    } else if constexpr (std::is_convertible_v<T *, ITextModel *>) {
//      auto model_ptr = model.get();
//      std::shared_ptr<T> model_alias(std::move(model), model_ptr);
//      this->ITextView::SetModel(std::move(model_alias));
//    } else {
//      throw std::runtime_error("Bad type to `SetModel`.");
//    }
//  }
//};

}  // namespace mx::gui
