#ifndef PARSER_H
#define PARSER_H

#include <QHash>
#include <QDebug>

#include "lexer.h"

using namespace lexer;

namespace parser {

    enum KeyWords {PRINT = 1, INT, DOUBLE};
    enum ParseMode {FIND = 0, VAR, ASSIGN, END}; //find, var, "="

    static int maxPriority = 6;

    class Node {
    public:
        Node(QVector <Lexem*> lexems, int begin, int end, int priority, int parent) {
            qDebug() << parent << ", " << priority << ", " << begin << "," << end << endl;
            this->parent = parent;
            this->lexems = lexems;
            //this->nodes = nodes;
            //createChilds(begin, end, priority);
        }

        /*void createChilds(int begin, int end, int priority) {
            for (int curPriority = priority; priority < maxPriority; curPriority++) {
                for (int i = begin; i < end; i++) {
                    if (curPriority == lexems[i]->getPriority()) {
                        int id = nodes.size() + 1;
                        int curPos = i;
                        qDebug() << lexems[i]->toString() << ", " << id << ", " << curPriority << ", " << begin << "," << end << ", " << curPos << endl;
                        Node *left = new Node(nodes, lexems, begin, curPos, curPriority, id);
                        nodes.push_back(left);
                        Node *right = new Node(nodes, lexems, curPos + 1, end, curPriority, id);
                        nodes.push_back(right);

                    }
                }
            }
        }*/

        void print() {
            qDebug() << parent;
        }

    private:
        int parent;
        //Node *left;
        //Node *right;
        QVector <Lexem*> lexems;
        //QVector <Node*> nodes;
    };



    class Parser
    {
    public:
        Parser();

        QHash<QString, int> intvars; //intvars
        QHash<QString, parser::KeyWords> keywords; //keywords
        void parseLine(QString s);
        void calcLine(QString var, QString s);
        parser::ParseMode parseMode;

        void addIntVar(QString s);
        void print();

        void setLexems(QVector<Lexem *> lexems);

    private:
        QVector <Lexem*> lexems;
        QVector <Node*> nodes;

        void createChilds(QVector <Lexem*> lexems, int begin, int end, int priority, int parent);

        //int maxPriority;
    };
}



#endif // PARSER_H
