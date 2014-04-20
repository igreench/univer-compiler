#include <QCoreApplication>
#include "translator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Translator *tr = new Translator();
    tr->print();


    return a.exec();
}
