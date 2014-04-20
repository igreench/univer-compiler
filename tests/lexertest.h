#ifndef LEXERTEST_H
#define LEXERTEST_H

#include "autotest.h"
#include "../compiler/lexer.h"

using namespace lexer;

class LexerTest : public QObject
{
Q_OBJECT
private slots:
    void simpleTest();
};

void LexerTest::simpleTest() {
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));

    Lexer *lexer = new Lexer();
    lexer->parseLine("int a = 0");
    //lexer->parseLine("int a = bdf123 + sdf /* fsdf */ / f-4++88-2435-234+1+134++314");
    lexer->print();
}

DECLARE_TEST(LexerTest)

#endif // LEXERTEST_H
