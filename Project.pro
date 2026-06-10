QT += core gui widgets testlib
CONFIG += c++17 console

SOURCES += \
    main.cpp \
    UI/MainWindow.cpp \
    UI/AddEditDialog.cpp \
    Core/Model.cpp \
    Core/Controller.cpp \
    Core/ImageFilter.cpp \
    Core/FilterFactory.cpp

HEADERS += \
    UI/MainWindow.h \
    UI/AddEditDialog.h \
    Core/Model.h \
    Core/Controller.h \
    Core/ImageFilter.h \
    Core/FilterFactory.h

FORMS += \
    UI/MainWindow.ui \
    UI/AddEditDialog.ui

INCLUDEPATH += "C:/msys64/mingw64/include/opencv4"
LIBS += -LC:/msys64/mingw64/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_imgcodecs \
    -lopencv_highgui \
    -lopencv_videoio
