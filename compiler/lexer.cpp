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
    int curPriority = -1;
    for (int i = 0; i < s.length(); ) {
        //curPriority = symbolPriority(s[i], mode);
        if (s[i] != lexer::SYMBOL_SPACE) {
            if (lexer::NOMODE == mode) {
                mode = (lexer::LexerMode)symbolType(s[i], mode);
                curPriority = symbolPriority(s[i], mode);
            } else {
                if ((lexer::SymbolType)mode == symbolType(s[i], mode)) {
                    str += s[i];
                } else {
                    if (!str.isEmpty()) {
                        //lexems.append(str);
                        lexems.push_back(new Lexem(str, mode, curPriority));
                        str.clear();
                    }
                    str += s[i];
                    mode = (lexer::LexerMode)symbolType(s[i], mode);
                    curPriority = symbolPriority(s[i], mode);
                }
                i++;
            }
        } else {
            if (!str.isEmpty()) {
                //lexems.append(str);
                lexems.push_back(new Lexem(str, mode, curPriority));
                str.clear();
            }
            mode = lexer::NOMODE;
            i++;
        }
    }
    if (!str.isEmpty()) {        
        //lexems.append(str);
        lexems.push_back(new Lexem(str, mode, curPriority));
    }
}

lexer::SymbolType Lexer::symbolType(QChar symbol, lexer::LexerMode mode) {
    if (metasymbols.contains(symbol)) {
        return lexer::METASYMBOL;
    }
    if (symbol.isDigit()) {
        //qDebug() << "is digit: " << symbol;
        if (lexer::WORD == mode) {
            return lexer::LETTER;
        } else {
            return lexer::DIGIT;
        }
    }
    if (symbol.isLetter()) {
        return lexer::LETTER;
    }
    return lexer::OTHER;
}

int Lexer::symbolPriority(QChar symbol, lexer::LexerMode mode) {
    //if (lexer::META == mode) {
    if (metasymbols.contains(symbol)) {
        return metasymbols.value(symbol);
    }
    if (lexer::WORD == mode) {
        return metasymbols.size() + 1;
    }
    if (lexer::NUMBER == mode) {
        return metasymbols.size();
    }
    return -1;
}

void Lexer::print() {
    //qDebug() << "metasymbols" << endl;
    //qDebug() << metasymbols << endl;
    //qDebug() << "lexems" << endl;
    qDebug() << endl;
    for (int i = 0; i < lexems.size(); i++) {
        qDebug() << lexems[i]->toString();
    }
}

QVector <Lexem*> Lexer::getLexems() {
    return lexems;
}

