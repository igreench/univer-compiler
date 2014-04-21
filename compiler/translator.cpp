#include "translator.h"

#include <QDebug>

Translator::Translator()
{
    lexer::Lexer *lexer = new lexer::Lexer();
    //lexer->parseLine("int a = 0");
    //qDebug() << "int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314";
    //lexer->parseLine("int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314");


    //qDebug() << "int a = 2 * 8/3-4" << endl;
    //lexer->parseLine("int a = 2 + 1 * 8/3-4");

    qDebug() << "2 + 1 * 8/3-4" << endl;
    lexer->parseLine("2 + 1 * 8/3-4");
   // qDebug() << "4 - 3 + 2" << endl;
    //lexer->parseLine("4 - 3 + 2");
    lexer->print();

    //

    parser::Parser *parser = new parser::Parser();
    parser->setLexems(lexer->getLexems());
    //parser->print();

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