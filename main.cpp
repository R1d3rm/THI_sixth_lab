#include "UI/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("Image Editor — ЛР №5");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}