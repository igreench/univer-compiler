#include "translator.h"

#include <QDebug>

using namespace translator;

Translator::Translator()
{

}

void Translator::print() {
    for (int i = 0; i < code.size(); i++) {
        qDebug() << code[i]->toString();
    }
}

void Translator::analyze() {
    /*int curParent = -1;
    int curPriority = 0;
    while (curPriority < maxPriority) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->getParent() == curParent) {
                curParent++;
                curPriority = nodes[i]->getPriority();
            }
        }
    }*/
}

void Translator::createFile() {
    QFile file("test.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    //begin

    out << ".class public Expr\n";
    out << ".super java/lang/Object\n";

    out << ".method public <init>()V\n";
    out << "   .limit stack 1\n";
    out << "   .limit locals 1\n";
    out << "   aload_0\n";
    out << "   invokespecial java/lang/Object/<init>()V\n";
    out << "   return\n";
    out << ".end method\n";

    out << ".method public static main([Ljava/lang/String;)V\n";
    out << "   .limit stack 10\n";
    out << "   .limit locals 2\n";

    //body

    for (int i = 0; i < code.size(); i++) {
        out << code[i]->toString();
    }

    //end

    out << "   istore_1\n";
    out << "   getstatic java/lang/System/out Ljava/io/PrintStream;\n";
    out << "   iload_1\n";
    out << "   invokevirtual java/io/PrintStream/println(I)V\n";
    out << "   return\n";
    out << ".end method\n";

    file.close();
}

void Translator::createHelloWorld() {
    QFile file("test.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << " .class public HelloWorld.j\n";
    out << "    .super java/lang/Object\n";

    out << "    .method public <init>()V\n";
    out << "       aload_0\n";
    out << "      invokenonvirtual java/lang/Object/<init>()V\n";
    out << "      return\n";
    out << "   .end method\n";

    out << "   .method public static main([Ljava/lang/String;)V\n";
    out << "      .limit stack 2\n";
    out << "      .limit locals 2\n";
    out << "      getstatic      java/lang/System/out Ljava/io/PrintStream;\n";
    out << "      ldc            \"Hello World.\"\n";
    out << "      invokevirtual  java/io/PrintStream/println(Ljava/lang/String;)V\n";
    out << "      return\n";
    out << "   .end method\n";

    file.close();

}
