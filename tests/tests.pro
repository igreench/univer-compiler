QT       += core testlib
QT       -= gui

TARGET = tests
CONFIG   += console
CONFIG   += dirs
CONFIG   -= app_bundle

LEVEL = ""

TEMPLATE = app

SOURCES += main.cpp \
    ../compiler/lexer.cpp \
    ../compiler/translator.cpp \
    ../compiler/parser.cpp \
    ../compiler/buffer.cpp

HEADERS += lexertest.h \
    stringtest.h \
    autotest.h \
    ../compiler/lexer.h \
    ../compiler/translator.h \
    ../compiler/parser.h \
    ../compiler/buffer.h \
    buffertest.h \
    parsertest.h \
    translatortest.h
