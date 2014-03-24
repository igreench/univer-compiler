#include <QCoreApplication>
#include "lexer.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    lexer::Lexer *lexer = new lexer::Lexer();
    lexer->parseLine("int a = 0");
    //lexer->parseLine("int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314");
    lexer->print();

    /*Parser *parser = new Parser();
    parser->parseLine("int a = 0");
    parser->print();
    parser->parseLine("print a = 0");
    parser->print();
    parser->parseLine("double a = 0");
    parser->print();*/

    return a.exec();
}
