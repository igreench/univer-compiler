#ifndef BUFFERTEST_H
#define BUFFERTEST_H

#include "autotest.h"
#include "../compiler/buffer.h"

//using namespace buffer;

class BufferTest : public QObject
{
Q_OBJECT
private slots:
    void simpleTest();
};

void BufferTest::simpleTest() {
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

DECLARE_TEST(BufferTest)

#endif // BUFFERTEST_H
