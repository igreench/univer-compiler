#include "lexer.h"

#include <QString>
#include <QDebug>

using namespace lexer;

Lexer::Lexer() {
    metasymbols.insert('=', lexer::EQUAL);
    metasymbols.insert('+', lexer::PLUS);
    metasymbols.insert('-', lexer::MINUS);
    metasymbols.insert('*', lexer::MULT);
    metasymbols.insert('/', lexer::DIV);
}

void Lexer::parseLine(QString s) {
    mode = lexer::NOMODE;
    QString str;
    for (int i = 0; i < s.length(); ) {
        if (s[i] != lexer::SYMBOL_SPACE) {
            if (lexer::NOMODE == mode) {
                mode = (lexer::LexerMode)symbolType(s[i], mode);
            } else {
                if ((lexer::SymbolType)mode == symbolType(s[i], mode)) {
                    str += s[i];
                } else {
                    if (!str.isEmpty()) {
                        lexems.append(str);
                        str.clear();
                    }
                    str += s[i];
                    mode = (lexer::LexerMode)symbolType(s[i], mode);
                }
                i++;
            }
        } else {
            mode = lexer::NOMODE;
            if (!str.isEmpty()) {
                lexems.append(str);
                str.clear();
            }
            i++;
        }
    }
    if (!str.isEmpty()) {
        lexems.append(str);
    }
}

lexer::SymbolType Lexer::symbolType(QChar symbol, lexer::LexerMode mode) {
    if (metasymbols.contains(symbol)) {
        return lexer::METASYMBOL;
    }
    if (symbol.isDigit()) {
        if (lexer::NOMODE == mode) {
            return lexer::DIGIT;
        } else {
            return lexer::LETTER;
        }
    }
    if (symbol.isLetter()) {
        return lexer::LETTER;
    }
    return lexer::OTHER;
}

void Lexer::print() {
    qDebug() << "metasymbols" << endl;
    qDebug() << metasymbols << endl;
    qDebug() << "lexems" << endl;
    qDebug() << lexems << endl;
}

