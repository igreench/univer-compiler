#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T02:39:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = compiler
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lexer.cpp \
    parser.cpp \
    buffer.cpp \
    translator.cpp \
    compiler.cpp

HEADERS += \
    lexer.h \
    parser.h \
    buffer.h \
    translator.h \
    compiler.h
