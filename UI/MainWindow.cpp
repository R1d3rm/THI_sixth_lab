#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AddEditDialog.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupConnections();
    updateResultLabel();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupConnections() {
    connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(ui->editBtn, &QPushButton::clicked, this, &MainWindow::onEditClicked);
    connect(ui->deleteBtn, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    
    connect(ui->filterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onFilterChanged);
    connect(ui->brightnessSlider, &QSlider::valueChanged,
            this, &MainWindow::onBrightnessChanged);
    connect(ui->itemsCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onItemsComboChanged);
}

void MainWindow::updateImageDisplay() {
    cv::Mat processed = controller.getModel()->getProcessed();
    if (!processed.empty()) {
        QImage img = matToQImage(processed);
        ui->imageLabel->setPixmap(QPixmap::fromImage(img).scaled(
            ui->imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

QImage MainWindow::matToQImage(const cv::Mat& mat) {
    if (mat.type() == CV_8UC3) {
        cv::Mat rgb;
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);
        return QImage(rgb.data, rgb.cols, rgb.rows, rgb.step, QImage::Format_RGB888).copy();
    }
    if (mat.type() == CV_8UC1) {
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8).copy();
    }
    return QImage();
}

void MainWindow::updateResultLabel() {
    int brightness = controller.getModel()->getBrightness();
    ui->resultLabel->setText(QString("Яркость: %1").arg(brightness));
}

void MainWindow::onAddClicked() {
    AddEditDialog dialog(AddEditDialog::Mode::Add, QString(), this);
    if (dialog.exec() == QDialog::Accepted) {
        QString path = dialog.getImagePath();
        if (!path.isEmpty() && controller.loadImage(path.toStdWString())) {
            imagePaths.append(path);
            ui->itemsCombo->addItem(QFileInfo(path).fileName());
            ui->itemsCombo->setCurrentIndex(ui->itemsCombo->count() - 1);
            updateImageDisplay();
            updateResultLabel();
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение");
        }
    }
}

void MainWindow::onEditClicked() {
    int idx = ui->itemsCombo->currentIndex();
    if (idx < 0 || idx >= imagePaths.size()) return;
    
    AddEditDialog dialog(AddEditDialog::Mode::Edit, imagePaths[idx], this);
    if (dialog.exec() == QDialog::Accepted) {
        QString newPath = dialog.getImagePath();
        if (!newPath.isEmpty() && controller.loadImage(newPath.toStdWString())) {
            imagePaths[idx] = newPath;
            ui->itemsCombo->setItemText(idx, QFileInfo(newPath).fileName());
            updateImageDisplay();
            updateResultLabel();
        }
    }
}

void MainWindow::onDeleteClicked() {
    int idx = ui->itemsCombo->currentIndex();
    if (idx < 0) return;
    
    imagePaths.removeAt(idx);
    ui->itemsCombo->removeItem(idx);
    
    if (ui->itemsCombo->count() > 0) {
        ui->itemsCombo->setCurrentIndex(0);
        onItemsComboChanged(0);
    } else {
        ui->imageLabel->clear();
        ui->imageLabel->setText("Изображение");
        controller = ImageController(); // сброс
        updateResultLabel();
    }
}

void MainWindow::onFilterChanged(int index) {
    controller.getModel()->setFilterType(
        static_cast<FilterFactory::FilterType>(index));
    updateImageDisplay();
}

void MainWindow::onBrightnessChanged(int value) {
    controller.getModel()->setBrightness(value);
    updateImageDisplay();
    updateResultLabel();
}

void MainWindow::onItemsComboChanged(int index) {
    if (index >= 0 && index < imagePaths.size()) {
        controller.loadImage(imagePaths[index].toStdWString());
        // Восстанавливаем настройки из модели (если нужно)
        ui->brightnessSlider->setValue(controller.getModel()->getBrightness());
        ui->filterCombo->setCurrentIndex(
            static_cast<int>(controller.getModel()->getFilterType()));
        updateImageDisplay();
        updateResultLabel();
    }
}