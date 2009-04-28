TEMPLATE = app
TARGET = Buddies
QT += core \
    gui \
    sql \
    xml \
    xmlpatterns \
    network \
    svg \
    webkit \
    script \
    qt3support
HEADERS += notes.h \
    wall.h \
    chat.h \
    buddies.h
SOURCES += notes.cpp \
    wall.cpp \
    chat.cpp \
    main.cpp \
    buddies.cpp
FORMS += notes.ui \
    wall.ui \
    chat.ui \
    buddies.ui
RESOURCES += Buddies.qrc
