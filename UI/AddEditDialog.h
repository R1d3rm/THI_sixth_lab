#pragma once
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AddEditDialog; }
QT_END_NAMESPACE

class AddEditDialog : public QDialog {
    Q_OBJECT
public:
    enum class Mode { Add, Edit };
    
    explicit AddEditDialog(Mode mode, const QString& existingPath = QString(), QWidget *parent = nullptr);
    ~AddEditDialog();
    
    QString getImagePath() const { return imagePath; }

private slots:
    void onBrowseClicked();
    void onPathChanged(const QString& text);

private:
    void validateInput();
    
    Ui::AddEditDialog *ui;
    Mode dialogMode;
    QString imagePath;
};