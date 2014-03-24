#include "lexer.h"

#include <QString>
#include <QDebug>

Lexer::Lexer() {
    keywords.insert("print", PRINT);
    keywords.insert("int", INT);
    keywords.insert("double", DOUBLE);

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

void Lexer::updateModeBySymbolType(lexer::SymbolType symbolType) {
    switch (symbolType) {
    case lexer::DIGIT:
        mode = lexer::NUMBER;
        break;
    case lexer::LETTER:
        mode = lexer::WORD;
        break;
    case lexer::METASYMBOL:
        mode = lexer::META;
        break;
    case lexer::OTHER:
        mode = lexer::NOMODE;
        break;
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
    qDebug() << "intvars" << endl;
    qDebug() << intvars << endl;
    qDebug() << "keywords" << endl;
    qDebug() << keywords << endl;
    qDebug() << "metasymbols" << endl;
    qDebug() << metasymbols << endl;
    qDebug() << "lexems" << endl;
    qDebug() << lexems << endl;
}

Parser::Parser() {
    keywords.insert("print", PRINT);
    keywords.insert("int", INT);
    keywords.insert("double", DOUBLE);
    parseMode = FIND;
}

void Parser::parseLine(QString s) {
    QString str;
    QString var = "empty";
    for (int i = 0; i < s.length()/*, parseMode != END*/; i++) {
        if (s[i] != ' ') {
            str += s[i];
        } else {
            if (!str.isEmpty()) {
                if (ASSIGN == parseMode) {
                    if (str == "=") {
                        //qDebug() << "str"
                        qDebug() << "s.mid(i, s.length() - i) : " << s.mid(i, s.length() - i);
                        calcLine(var, s.mid(i, s.length() - i));
                        parseMode = END;//break!
                        break;
                        qDebug() << "ENDING??";
                    }
                }
                if (VAR == parseMode) {
                    addIntVar(str);
                    //str = " ";
                    parseMode = ASSIGN;
                }
                if (FIND == parseMode) {
                    //qDebug() << "keywords.value(str) : " << keywords.value(str);
                    //qDebug() << "keywords.take(str) : " << keywords.take(str);
                    if (keywords.take(str) > 0) {

                        parseMode = VAR;

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
    parseMode = FIND;
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
