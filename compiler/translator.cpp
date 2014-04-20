#include "translator.h"

#include <QDebug>

Translator::Translator()
{
    lexer::Lexer *lexer = new lexer::Lexer();
    //lexer->parseLine("int a = 0");
    qDebug() << "int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314";
    lexer->parseLine("int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314");
    lexer->print();

    /*tokenizer::Tokenizer *tokenizer = new tokenizer::Tokenizer(lexer->getLexems());
    tokenizer->tokenization();
    tokenizer->print();*/

    /*Parser *parser = new Parser();
    parser->parseLine("int a = 0");
    parser->print();
    parser->parseLine("print a = 0");
    parser->print();
    parser->parseLine("double a = 0");
    parser->print();*/
}

void Translator::print() {
    //qDebug() << tree;
}
