#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QVector>
#include <QString>

#include "parser.h"

using namespace parser;

class ByteCode {
public:
    ByteCode(QString cmd, QString value) {
        this->cmd = cmd;
        this->value = value;
    }

    void print() {
        qDebug() << cmd << value;
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

    void setNodes(QVector <Node*> nodes) {
        this->nodes = nodes;
    }

private:
    QVector <ByteCode*> code;
    QVector <Node*> nodes;
};

#endif // TRANSLATOR_H
