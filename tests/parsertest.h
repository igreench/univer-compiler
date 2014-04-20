#ifndef PARSERTEST_H
#define PARSERTEST_H

#include "autotest.h"
#include "../compiler/parser.h"

using namespace parser;

class ParserTest : public QObject
{
Q_OBJECT
private slots:
    void simpleTest();
};

void ParserTest::simpleTest() {
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

DECLARE_TEST(ParserTest)

#endif // PARSERTEST_H
