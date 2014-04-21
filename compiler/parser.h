#ifndef PARSER_H
#define PARSER_H

#include <QHash>
#include <QDebug>

#include "lexer.h"

using namespace lexer;

namespace parser {

    class Node {
    public:
        Node(Lexem *lexem, int parent) {
            this->parent = parent;
            this->lexem = lexem;
        }

        void print() {
            qDebug() << lexem->toString() << parent;
        }

        int getPriority() {
            return lexem->getPriority();
        }

        Lexem *getLexem() {
            return lexem;
        }

        int getParent() {
            return parent;
        }

    private:
        int parent;
        Lexem *lexem;
    };

    class Parser
    {
    public:
        Parser();

        void setLexems(QVector<Lexem *> lexems);
        void print();

        QVector <Node*> getNodes() {
            return nodes;
        }

        int getMaxPriority() {
            return maxPriority;
        }

    private:
        QVector <Lexem*> lexems;
        QVector <Node*> nodes;

        void createChilds(int begin, int end, int priority, int parent);

        int maxPriority;
    };
}

#endif // PARSER_H
