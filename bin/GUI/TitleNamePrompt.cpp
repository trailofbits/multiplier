// Copyright (c) 2019-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "TitleNamePrompt.h"

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QTimer>

namespace mx::gui {
struct TitleNamePrompt::PrivateData final {
  QString prompt;
  QLineEdit *new_name{nullptr};
  bool shake_switch{false};
  unsigned num_shakes{0u};
};

TitleNamePrompt::TitleNamePrompt(const QString &prompt, QWidget *parent)
    : QDialog(parent), d(new PrivateData) {
  d->prompt = prompt;

  InitializeWidgets();
}

TitleNamePrompt::~TitleNamePrompt() {}

void TitleNamePrompt::Vacillate(void) {
  QPoint offset(10, 0);
  move((d->shake_switch ? pos() + offset : pos() - offset));
  d->shake_switch = !d->shake_switch;
}

void TitleNamePrompt::Shake(void) {
  d->num_shakes++;

  if (d->num_shakes >= 9u) {
    d->num_shakes = 0u;
    return;
  }

  Vacillate();
  QTimer::singleShot(40, this, &TitleNamePrompt::Shake);
}

QString TitleNamePrompt::NewName(void) const {
  return d->new_name->text();
}

void TitleNamePrompt::accept(void) {
  if (0 < d->new_name->text().size()) {
    this->QDialog::accept();
  } else {
    Shake();
  }
}

void TitleNamePrompt::InitializeWidgets(void) {
  setMinimumSize(400, height());

  d->new_name = new QLineEdit();
  d->new_name->setFocus();

  setWindowTitle(d->prompt);

  auto accept_button = new QPushButton(tr("Apply"));
  connect(accept_button, &QPushButton::pressed, this, &QDialog::accept);
  connect(d->new_name, &QLineEdit::returnPressed, this, &QDialog::accept);

  auto main_layout = new QVBoxLayout();
  setLayout(main_layout);

  main_layout->addWidget(d->new_name);
  main_layout->addWidget(accept_button);
}

}  // namespace mx::gui
