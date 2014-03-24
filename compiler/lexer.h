#ifndef LEXER_H
#define LEXER_H

#include <QHash>
#include <QStringList>

enum KeyWords {PRINT = 1, INT, DOUBLE};
enum ParseMode {FIND = 0, VAR, ASSIGN, END}; //find, var, "="

namespace lexer {
    enum MetaSymbols {EQUAL = 0, PLUS, MINUS, MULT, DIV}; //=,+,-,*,/
    enum LexerMode {NUMBER = 0, WORD, META, NOMODE = -1};
    enum SymbolType {DIGIT = 0, LETTER, METASYMBOL, OTHER = -1};
    static char SYMBOL_SPACE = ' ';
    enum SymbolCount {EVERY = 0, FIRST};
}

class Lexer
{
public:
    Lexer();

    QHash<QString, int> intvars; //intvars
    QHash<QString, KeyWords> keywords; //keywords
    QHash<QChar, lexer::MetaSymbols> metasymbols; //metasymbols

    QStringList lexems;
    void parseLine(QString s);
    void print();

    lexer::SymbolType symbolType(QChar symbol, lexer::LexerMode mode);
    lexer::LexerMode mode;

    void updateModeBySymbolType(lexer::SymbolType symbolType);
};

class Parser
{
public:
    Parser();

    QHash<QString, int> intvars; //intvars
    QHash<QString, KeyWords> keywords; //keywords
    void parseLine(QString s);
    void calcLine(QString var, QString s);
    ParseMode parseMode;

    void addIntVar(QString s);
    void print();
};



#endif // LEXER_H
