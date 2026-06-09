/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *controlsLayout;
    QComboBox *itemsCombo;
    QPushButton *addBtn;
    QPushButton *editBtn;
    QPushButton *deleteBtn;
    QHBoxLayout *settingsLayout;
    QLabel *filterLabel;
    QComboBox *filterCombo;
    QLabel *brightnessLabel;
    QSlider *brightnessSlider;
    QLabel *imageLabel;
    QLabel *resultLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        itemsCombo = new QComboBox(centralwidget);
        itemsCombo->setObjectName("itemsCombo");

        controlsLayout->addWidget(itemsCombo);

        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName("addBtn");

        controlsLayout->addWidget(addBtn);

        editBtn = new QPushButton(centralwidget);
        editBtn->setObjectName("editBtn");

        controlsLayout->addWidget(editBtn);

        deleteBtn = new QPushButton(centralwidget);
        deleteBtn->setObjectName("deleteBtn");

        controlsLayout->addWidget(deleteBtn);


        verticalLayout->addLayout(controlsLayout);

        settingsLayout = new QHBoxLayout();
        settingsLayout->setObjectName("settingsLayout");
        filterLabel = new QLabel(centralwidget);
        filterLabel->setObjectName("filterLabel");

        settingsLayout->addWidget(filterLabel);

        filterCombo = new QComboBox(centralwidget);
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->setObjectName("filterCombo");

        settingsLayout->addWidget(filterCombo);

        brightnessLabel = new QLabel(centralwidget);
        brightnessLabel->setObjectName("brightnessLabel");

        settingsLayout->addWidget(brightnessLabel);

        brightnessSlider = new QSlider(centralwidget);
        brightnessSlider->setObjectName("brightnessSlider");
        brightnessSlider->setOrientation(Qt::Horizontal);
        brightnessSlider->setMinimum(-100);
        brightnessSlider->setMaximum(100);

        settingsLayout->addWidget(brightnessSlider);


        verticalLayout->addLayout(settingsLayout);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setMinimumSize(QSize(400, 300));
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(imageLabel);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Image Editor \342\200\224 \320\233\320\240 \342\204\2265", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        editBtn->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        filterLabel->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200:", nullptr));
        filterCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\320\235\320\265\321\202", nullptr));
        filterCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\320\247/\320\221", nullptr));
        filterCombo->setItemText(2, QCoreApplication::translate("MainWindow", "\320\235\320\265\320\263\320\260\321\202\320\270\320\262", nullptr));
        filterCombo->setItemText(3, QCoreApplication::translate("MainWindow", "\320\241\320\265\320\277\320\270\321\217", nullptr));

        brightnessLabel->setText(QCoreApplication::translate("MainWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214:", nullptr));
        imageLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202: -", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
