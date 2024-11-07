QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    jjchat_msg.potato.cc \
    main.cpp \
    mainwindow.cpp \
    msg_header.potato.cc \
    my_client.cpp \
    runnable_task.cpp \
    tcp_client.cpp \
    widget_chat.cpp \
    widget_chat_label.cpp \
    widget_friends.cpp \
    widget_login.cpp \
    widget_message.cpp \
    widget_myself.cpp

HEADERS += \
    jjchat_msg.potato.h \
    mainwindow.h \
    msg_header.potato.h \
    my_client.h \
    runnable_task.h \
    stink_potatobuf/stink_potatobuf.h \
    tcp_client.h \
    widget_chat.h \
    widget_chat_label.h \
    widget_friends.h \
    widget_login.h \
    widget_message.h \
    widget_myself.h

FORMS += \
    mainwindow.ui \
    widget_chat.ui \
    widget_chat_label.ui \
    widget_friends.ui \
    widget_login.ui \
    widget_message.ui \
    widget_myself.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
