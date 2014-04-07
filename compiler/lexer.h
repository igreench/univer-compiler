#ifndef LEXER_H
#define LEXER_H

#include <QHash>
#include <QStringList>
#include <QVector>

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
        QString toString() {
            return str + ", " + QString::number(mode);
        }
    private:
        QString str;
        LexerMode mode;
    };

    class Lexer
    {
    public:
        Lexer();

        QHash<QChar, lexer::MetaSymbols> metasymbols; //metasymbols

        //QStringList lexems;
        QVector <Lexem*> lexems;
        void parseLine(QString s);
        void print();

        lexer::SymbolType symbolType(QChar symbol, lexer::LexerMode mode);
        lexer::LexerMode mode;
    };
}

#endif // LEXER_H
