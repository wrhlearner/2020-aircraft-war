HEADERS += \
    aircraft.h \
    bloodsupply.h \
    bomb.h \
    bombsupply.h \
    bossnpc.h \
    bullet.h \
    flyertypecast.h \
    flyingobject.h \
    gamebackground.h \
    generatebullet.h \
    generatenpc.h \
    global.h \
    menu.h \
    normalnpc.h \
    npc.h \
    npcbullet.h \
    player.h \
    playerbullet.h \
    randalg.h \
    supply.h

SOURCES += \
    aircraft.cpp \
    bloodsupply.cpp \
    bomb.cpp \
    bombsupply.cpp \
    bossnpc.cpp \
    bullet.cpp \
    flyertypecast.cpp \
    flyingobject.cpp \
    gamebackground.cpp \
    generatebullet.cpp \
    generatenpc.cpp \
    main.cpp \
    menu.cpp \
    normalnpc.cpp \
    npc.cpp \
    npcbullet.cpp \
    player.cpp \
    playerbullet.cpp \
    randalg.cpp \
    supply.cpp
QT += widgets

RESOURCES += \
    myimage/images.qrc

DISTFILES += \
    icon.ico
RC_ICONS = icon.ico
