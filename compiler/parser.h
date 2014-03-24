#ifndef PARSER_H
#define PARSER_H

#include <QHash>

namespace parser {
    enum KeyWords {PRINT = 1, INT, DOUBLE};
    enum ParseMode {FIND = 0, VAR, ASSIGN, END}; //find, var, "="
}

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
};

#endif // PARSER_H