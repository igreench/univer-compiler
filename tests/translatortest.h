#ifndef TRANSLATORTEST_H
#define TRANSLATORTEST_H

#include "autotest.h"
#include "../compiler/translator.h"

//using namespace translator;

class TranslatorTest : public QObject
{
Q_OBJECT
private slots:
    void simpleTest();
};

void TranslatorTest::simpleTest() {
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

DECLARE_TEST(TranslatorTest)

#endif // TRANSLATORTEST_H
