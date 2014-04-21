#include "parser.h"

#include <QString>


using namespace parser;

Parser::Parser() {
    /*keywords.insert("print", parser::PRINT);
    keywords.insert("int", parser::INT);
    keywords.insert("double", parser::DOUBLE);
    parseMode = parser::FIND;*/

    //maxPriority = 6; //don't right realization

    nodes.clear();

    //
}

void Parser::parseLine(QString s) {
    QString str;
    QString var = "empty";
    for (int i = 0; i < s.length()/*, parseMode != END*/; i++) {
        if (s[i] != ' ') {
            str += s[i];
        } else {
            if (!str.isEmpty()) {
                if (parser::ASSIGN == parseMode) {
                    if (str == "=") {
                        //qDebug() << "str"
                        qDebug() << "s.mid(i, s.length() - i) : " << s.mid(i, s.length() - i);
                        calcLine(var, s.mid(i, s.length() - i));
                        parseMode = parser::END;//break!
                        break;
                        qDebug() << "ENDING??";
                    }
                }
                if (parser::VAR == parseMode) {
                    addIntVar(str);
                    //str = " ";
                    parseMode = parser::ASSIGN;
                }
                if (parser::FIND == parseMode) {
                    //qDebug() << "keywords.value(str) : " << keywords.value(str);
                    //qDebug() << "keywords.take(str) : " << keywords.take(str);
                    if (keywords.take(str) > 0) {

                        parseMode = parser::VAR;

                    }

                    /*for (int j = 0; j < keywords.size(); j++) {
                        //if (str == keywords.take(str))
                    }*/
                }
                str = " ";
            }
        }
        qDebug() << "str : " << str;

    }
    parseMode = parser::FIND;
}

void Parser::calcLine(QString var, QString s) {
    Q_UNUSED(s)
    qDebug() << "intvars[var] : " << intvars[var];
    intvars[var] = 1;
    qDebug() << "intvars[var] : " << intvars[var];
}

void Parser::addIntVar(QString s) {
    intvars[s] = -2;
}

void Parser::print() {
    qDebug() << "intvars" << endl;
    qDebug() << intvars << endl;
    qDebug() << "keywords" << endl;
    qDebug() << keywords << endl;
}

void Parser::setLexems(QVector <Lexem*> lexems) {
    this->lexems = lexems;

    //Node *node = new Node(0, lexems.size(), 1);
    //nodes.push_back(node);
    createChilds(lexems, 0, lexems.size(), 1, 0);
}

void Parser::createChilds(QVector <Lexem*> lexems, int begin, int end, int priority, int parent) {
    qDebug() << priority << begin << end << parent << endl;
    Node *node = new Node(lexems, begin, end, priority, parent);
    nodes.push_back(node);
    if (priority <= maxPriority) {
        for (int curPriority = priority; priority < maxPriority; curPriority++) {
            for (int i = begin; i < end; i++) {
                qDebug() << lexems[i]->toString() << i << endl;
                if (curPriority == lexems[i]->getPriority()) {
                    int id = nodes.size() + 1;
                    int curPos = i;
                    qDebug() << lexems[i]->toString() << ", " << id << ", " << curPriority << ", " << begin << "," << end << ", " << curPos << endl;
                    createChilds(lexems, begin, curPos, curPriority, id);
                    createChilds(lexems, curPos + 1, end, curPriority, id);

                }
            }
        }
    }
}
