/********************************************************************************
** Form generated from reading UI file 'AddEditDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITDIALOG_H
#define UI_ADDEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *pathLabel;
    QHBoxLayout *pathLayout;
    QLineEdit *pathEdit;
    QPushButton *browseBtn;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddEditDialog)
    {
        if (AddEditDialog->objectName().isEmpty())
            AddEditDialog->setObjectName("AddEditDialog");
        AddEditDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(AddEditDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        pathLabel = new QLabel(AddEditDialog);
        pathLabel->setObjectName("pathLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, pathLabel);

        pathLayout = new QHBoxLayout();
        pathLayout->setObjectName("pathLayout");
        pathEdit = new QLineEdit(AddEditDialog);
        pathEdit->setObjectName("pathEdit");

        pathLayout->addWidget(pathEdit);

        browseBtn = new QPushButton(AddEditDialog);
        browseBtn->setObjectName("browseBtn");

        pathLayout->addWidget(browseBtn);


        formLayout->setLayout(0, QFormLayout::ItemRole::FieldRole, pathLayout);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddEditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddEditDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEditDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEditDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEditDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEditDialog)
    {
        AddEditDialog->setWindowTitle(QCoreApplication::translate("AddEditDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214/\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pathLabel->setText(QCoreApplication::translate("AddEditDialog", "\320\237\321\203\321\202\321\214:", nullptr));
        browseBtn->setText(QCoreApplication::translate("AddEditDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEditDialog: public Ui_AddEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITDIALOG_H
