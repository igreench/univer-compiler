#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QVector>
#include <QString>
#include <QFile>

#include "parser.h"

using namespace parser;

namespace translator {

    class ByteCode {
    public:
        ByteCode(QString cmd, QString value) {
            this->cmd = cmd;
            this->value = value;
        }

        ByteCode(int priority, QString value) {
            this->value = value;

            switch (priority) {
            case 1:
                this->cmd = "   iadd\n";
                break;
            case 2:
                //this->cmd = "   ineg\n";
                this->cmd = "   isub\n";
                break;
            case 3:
                this->cmd = "   imul\n";
                break;
            case 4:
                this->cmd = "   idiv\n";
                break;
            case 5:
                this->cmd = "   sipush ";
                break;
            }
        }

        void print() {
            if (value.isEmpty()) {
                qDebug() << cmd;
            } else {
                qDebug() << cmd << value << "\n";
            }
        }

        QString toString() {
            //return cmd + value;
            if (value.isEmpty()) {
                return cmd;
            }
            return cmd + value + "\n";
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

        void setMaxPriority(int maxPriority) {
            this->maxPriority = maxPriority;
        }

        void createFile();
        void createHelloWorld();

        void analyze();

    private:
        QVector <ByteCode*> code;
        QVector <Node*> nodes;
        int maxPriority;
    };

}

#endif // TRANSLATOR_H
