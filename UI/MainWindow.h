#pragma once
#include <QMainWindow>
#include "Core/Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onFilterChanged(int index);
    void onBrightnessChanged(int value);
    void onItemsComboChanged(int index);

private:
    void setupConnections();
    void updateImageDisplay();
    void updateResultLabel();
    QImage matToQImage(const cv::Mat& mat);
    
    Ui::MainWindow *ui;
    ImageController controller;
    QStringList imagePaths;
};