#ifndef LEXER_H
#define LEXER_H

#include <QHash>
#include <QStringList>

namespace lexer {
    enum MetaSymbols {EQUAL = 0, PLUS, MINUS, MULT, DIV}; //=,+,-,*,/
    enum LexerMode {NUMBER = 0, WORD, META, NOMODE = -1};
    enum SymbolType {DIGIT = 0, LETTER, METASYMBOL, OTHER = -1};
    static char SYMBOL_SPACE = ' ';

    class Lexer
    {
    public:
        Lexer();

        QHash<QChar, lexer::MetaSymbols> metasymbols; //metasymbols

        QStringList lexems;
        void parseLine(QString s);
        void print();

        lexer::SymbolType symbolType(QChar symbol, lexer::LexerMode mode);
        lexer::LexerMode mode;
    };
}

#endif // LEXER_H
