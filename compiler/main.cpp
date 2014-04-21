#include <QCoreApplication>
#include "compiler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Compiler *compiler = new Compiler();

    return a.exec();
}
