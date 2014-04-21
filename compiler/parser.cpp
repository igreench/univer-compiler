#include "parser.h"

#include <QString>

using namespace parser;

Parser::Parser() {
    maxPriority = 6;
}

void Parser::print() {
    for (int i = 0; i < nodes.size(); i++) {
        qDebug() << "id" << i;
        nodes[i]->print();
    }
}

void Parser::setLexems(QVector <Lexem*> lexems) {
    this->lexems = lexems;
    createChilds(0, lexems.size(), 1, -1);
}

void Parser::createChilds(int begin, int end, int priority, int parent) {
    if (priority <= maxPriority) {
        for (int curPriority = priority; curPriority <= maxPriority; curPriority++) {
            for (int i = begin; i < end; i++) {
                if (curPriority == lexems[i]->getPriority()) {
                    Node *node = new Node(lexems[i], parent);
                    nodes.push_back(node);
                    createChilds(begin, i, curPriority, nodes.size() - 1);
                    createChilds(i + 1, end, curPriority, nodes.size() - 1);
                    return;
                }
            }
        }
    }
}
