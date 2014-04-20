#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QVector>
#include <QString>

#include "parser.h"

class ByteCode {
    ByteCode(QString cmd, QString value) {
        this->cmd = cmd;
        this->value = value;
    }

private:
    QString cmd;
    QString value;
};

class Translator
{
public:
    Translator();

    void print();

private:
    QVector <ByteCode> tree;
};

#endif // TRANSLATOR_H
