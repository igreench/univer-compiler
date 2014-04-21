#include "compiler.h"

Compiler::Compiler()
{
    qDebug() << "Example" << endl;
    qDebug() << "2 + 1 * 8/3-4";

    lexer::Lexer *lexer = new lexer::Lexer();
    lexer->parseLine("2 + 1 * 8/3-4");
    qDebug() << endl << "Lexer" << endl;
    lexer->print();

    parser::Parser *parser = new parser::Parser();
    parser->setLexems(lexer->getLexems());
    qDebug() << endl << "Parser" << endl;
    parser->print();

    translator::Translator *translator = new translator::Translator();
    translator->setMaxPriority(parser->getMaxPriority());
    translator->setNodes(parser->getNodes());
    qDebug() << endl << "Translator" << endl;
    translator->print();
}
