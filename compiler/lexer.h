#ifndef LEXER_H
#define LEXER_H

#include <QHash>
#include <QStringList>

enum KEYWORDS {PRINT = 1, INT, DOUBLE};
enum PARSERMODE {FIND = 0, VAR, ASSIGN, END}; //find, var, "="

namespace lexer {
    enum METASYMBOLS {EQUAL = 0, PLUS, MINUS, MULT, DIV}; //=,+,-,*,/
    enum LEXERMODE {NUMBER = 0, WORD, META, NOMODE = -1};
    enum SYMBOL_TYPE {DIGIT = 0, LETTER, METASYMBOL, OTHER = -1};
    static char SYMBOL_SPACE = ' ';
}

class Lexer
{
public:
    Lexer();

    QHash<QString, int> intvars; //intvars
    QHash<QString, KEYWORDS> keywords; //keywords
    QHash<QChar, lexer::METASYMBOLS> metasymbols; //metasymbols

    QStringList lexems;
    void parseLine(QString s);
    void print();

    lexer::SYMBOL_TYPE symbolType(QChar symbol);
    lexer::LEXERMODE mode;

    void updateModeBySymbolType(lexer::SYMBOL_TYPE symbolType);
};

class Parser
{
public:
    Parser();

    QHash<QString, int> intvars; //intvars
    QHash<QString, KEYWORDS> keywords; //keywords
    void parseLine(QString s);
    void calcLine(QString var, QString s);
    PARSERMODE parseMode;

    void addIntVar(QString s);
    void print();
};



#endif // LEXER_H
