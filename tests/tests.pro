QT += core gui widgets testlib
CONFIG += c++17 testcase

SOURCES += test_oknobot.cpp \
           ../OknoBot.cpp \
           ../GroupBoxControl.cpp \
           ../AutoKeyPresser.cpp \
           ../GlobalKeyListener.cpp

FORMS += ../OknoBot.ui
INCLUDEPATH += ..
