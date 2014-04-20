#ifndef BUFFER_H
#define BUFFER_H

#include <QChar>
#include <QString>

class Buffer
{
public:
    Buffer(QString filename);

    QChar getChar();
    QChar pickChar();
};

#endif // BUFFER_H
