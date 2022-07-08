// Copyright (c) 2021-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#include "OpenConnectionDialog.h"

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSpacerItem>
#include <QKeyEvent>

namespace mx::gui {
namespace {

static const QString kDefaultHost{"localhost"};
static const QString kDefaultPort{"50051"};

}  // namespace

struct OpenConnectionDialog::PrivateData final {
  ConnectionSettings connection_settings;

  QLineEdit *host_input{nullptr};
  QLineEdit *port_input{nullptr};
  QLineEdit *input_file_path{nullptr};
};

std::optional<ConnectionSettings> OpenConnectionDialog::Run(
    const QString &title) {
  OpenConnectionDialog dialog;
  dialog.setWindowTitle(title);

  if (dialog.exec() == QDialog::Accepted) {
    return dialog.d->connection_settings;
  } else {
    return std::nullopt;
  }
}

OpenConnectionDialog::OpenConnectionDialog(void) : d(new PrivateData) {
  resize(400, 150);

  // Connection parameters and input file
  auto input_layout = new QGridLayout();

  d->host_input = new QLineEdit();
  d->host_input->setText(kDefaultHost);

  d->port_input = new QLineEdit();
  d->port_input->setText(kDefaultPort);

  input_layout->addWidget(new QLabel(tr("Host")), 0, 0);
  input_layout->addWidget(d->host_input, 0, 1, 1, 2);

  input_layout->addWidget(new QLabel(tr("Port")), 1, 0);
  input_layout->addWidget(d->port_input, 1, 1, 1, 2);

  // Dialog buttons
  auto buttons_layout = new QHBoxLayout();

  auto cancel_button = new QPushButton(tr("Cancel"));
  connect(cancel_button, &QPushButton::pressed, this,
          &OpenConnectionDialog::reject);

  auto connect_button = new QPushButton(tr("Connect"));
  connect_button->setDefault(true);

  connect(connect_button, &QPushButton::pressed, this,
          &OpenConnectionDialog::OnConnectButtonPress);

  buttons_layout->addItem(new QSpacerItem(1, 1, QSizePolicy::Expanding));
  buttons_layout->addWidget(cancel_button);
  buttons_layout->addWidget(connect_button);

  // Main layout
  auto layout = new QVBoxLayout();

  layout->addLayout(input_layout);
  layout->addItem(
      new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding));

  layout->addLayout(buttons_layout);

  setLayout(layout);
}

OpenConnectionDialog::~OpenConnectionDialog(void) {}

void OpenConnectionDialog::keyPressEvent(QKeyEvent *event) {
  // Allow the user to accept the dialog through
  // the Conect button handler
  if (event->key() == Qt::Key_Return ||
      event->key() == Qt::Key_Enter) {

    OnConnectButtonPress();
    return;
  }

  QDialog::keyPressEvent(event);
}

void OpenConnectionDialog::OnConnectButtonPress(void) {
  if (d->host_input->text().isEmpty()) {
    QMessageBox::critical(this, tr("Error"), tr("No host provided"));
  } else if (d->port_input->text().isEmpty()) {
    QMessageBox::critical(this, tr("Error"), tr("No port provided"));
  } else {
    d->connection_settings.host = d->host_input->text();
    d->connection_settings.port = d->port_input->text();
    accept();
  }
}

}  // namespace mx::gui
