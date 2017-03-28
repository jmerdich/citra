// Copyright 2016 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "citra_qt/config.h"
#include "citra_qt/configure_dialog.h"
#include "core/settings.h"
#include "ui_configure.h"

ConfigureDialog::ConfigureDialog(QWidget* parent) : QDialog(parent), ui(new Ui::ConfigureDialog) {
    ui->setupUi(this);
    this->setConfiguration();
}

ConfigureDialog::~ConfigureDialog() {}

void ConfigureDialog::setConfiguration() {}

void ConfigureDialog::applyConfiguration() {
    // apply each, but don't commit the ini file (and trigger
    //  associated changes) until the end
    ui->generalTab->applyConfiguration(false);
    ui->inputTab->applyConfiguration(false);
    ui->graphicsTab->applyConfiguration(false);
    ui->audioTab->applyConfiguration(false);
    ui->debugTab->applyConfiguration(false);

    Settings::Apply();
    // system settings doesn't actually put settings in the ini file
    ui->systemTab->applyConfiguration();
}
