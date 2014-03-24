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
    qDebug() << s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != lexer::SYMBOL_SPACE) {
            if (lexer::NOMODE == mode) {
                updateModeBySymbolType(symbolType(s[i]));
            }
            if (lexer::NOMODE != mode) {
                switch (mode) {
                case lexer::NUMBER:
                    if (lexer::DIGIT == symbolType(s[i])) {
                        str += s[i];
                    } else {
                        lexems.append(str);
                        str.clear();
                        str += s[i];
                        updateModeBySymbolType(symbolType(s[i]));
                    }
                    break;
                case lexer::WORD:
                    if ((lexer::DIGIT == symbolType(s[i])) ||
                         (lexer::LETTER == symbolType(s[i]))) {
                        str += s[i];
                    } else {
                        lexems.append(str);
                        str.clear();
                        str += s[i];
                        updateModeBySymbolType(symbolType(s[i]));
                    }

                    break;
                case lexer::META:
                    if (lexer::METASYMBOL == symbolType(s[i])) {
                        str += s[i];
                    } else {
                        lexems.append(str);
                        str.clear();
                        str += s[i];
                        updateModeBySymbolType(symbolType(s[i]));
                    }
                    break;
                }
            }
        } else {
            mode = lexer::NOMODE;
            if (!str.isEmpty()) {
                lexems.append(str);
                str.clear();
            }
        }
    }
    if (!str.isEmpty()) {
        lexems.append(str);
    }
}

void Lexer::updateModeBySymbolType(lexer::SYMBOL_TYPE symbolType) {
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

lexer::SYMBOL_TYPE Lexer::symbolType(QChar symbol) {
    if (metasymbols.contains(symbol)) {
        return lexer::METASYMBOL;
    }
    if (symbol.isDigit()) {
        return lexer::DIGIT;
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
