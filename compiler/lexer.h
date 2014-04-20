#ifndef LEXER_H
#define LEXER_H

#include <QHash>
#include <QStringList>
#include <QVector>

//#include "buffer.h"

namespace lexer {

    enum MetaSymbols {EQUAL = 0, PLUS, MINUS, MULT, DIV}; //=,+,-,*,/
    enum LexerMode {NUMBER = 0, WORD, META, NOMODE = -1};
    enum SymbolType {DIGIT = 0, LETTER, METASYMBOL, OTHER = -1};
    static const char SYMBOL_SPACE = ' ';
    //static const char SYMBOL_DOT = '.';

    class Lexem {
    public:
        Lexem(QString str, LexerMode mode) {
            this->str = str;
            this->mode = mode;
        }

        Lexem(QString str, LexerMode mode, int type) {
            this->str = str;
            this->mode = mode;
            this->type = type;
        }
        QString toString() {
            return str + ", " + QString::number(mode) + ", " + QString::number(type);
        }
    private:
        QString str;
        LexerMode mode;
        int type;
    };

    class Lexer
    {
    public:
        Lexer();

        void parseLine(QString s);
        void print();
        QVector <Lexem*> getLexems();

    private:
        QHash<QChar, lexer::MetaSymbols> metasymbols; //metasymbols

        //QStringList lexems;
        QVector <Lexem*> lexems;

        lexer::SymbolType symbolType(QChar symbol, lexer::LexerMode mode);
        lexer::LexerMode mode;
    };
}

#endif // LEXER_H
