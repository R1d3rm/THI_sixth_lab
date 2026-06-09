#include "AddEditDialog.h"
#include "ui_AddEditDialog.h"
#include <QFileDialog>
#include <QFileInfo>

AddEditDialog::AddEditDialog(Mode mode, const QString& existingPath, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddEditDialog), dialogMode(mode) {
    ui->setupUi(this);
    
    if (mode == Mode::Edit && !existingPath.isEmpty()) {
        setWindowTitle("Редактировать объект");
        ui->pathEdit->setText(existingPath);
        imagePath = existingPath;
    } else {
        setWindowTitle("Добавить объект");
    }
    
    connect(ui->browseBtn, &QPushButton::clicked, this, &AddEditDialog::onBrowseClicked);
    connect(ui->pathEdit, &QLineEdit::textChanged, this, &AddEditDialog::onPathChanged);
    
    validateInput();
}

AddEditDialog::~AddEditDialog() {
    delete ui;
}

void AddEditDialog::onBrowseClicked() {
    QString path = QFileDialog::getOpenFileName(this, "Выберите изображение", "",
        "Изображения (*.png *.jpg *.jpeg *.bmp *.tif)");
    if (!path.isEmpty()) {
        ui->pathEdit->setText(path);
    }
}

void AddEditDialog::onPathChanged(const QString& text) {
    imagePath = text;
    validateInput();
}

void AddEditDialog::validateInput() {
    bool valid = !imagePath.isEmpty() && QFileInfo(imagePath).exists();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(valid);
}