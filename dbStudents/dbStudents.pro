QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customlineedit.cpp \
    main.cpp \
    mainwindow.cpp \
    markswindow.cpp \
    specializationwindow.cpp \
    studentswindow.cpp \
    subjectwindow.cpp \
    tablewindow.cpp

HEADERS += \
    Db_Connection.h \
    customlineedit.h \
    mainwindow.h \
    markswindow.h \
    specializationwindow.h \
    studentswindow.h \
    subjectwindow.h \
    tablewindow.h

FORMS += \
    mainwindow.ui \
    markswindow.ui \
    specializationwindow.ui \
    studentswindow.ui \
    subjectwindow.ui \
    tablewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
