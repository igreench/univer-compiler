#ifndef BUFFER_H
#define BUFFER_H

#include "QChar"

class Buffer
{
public:
    Buffer();

    QChar getChar();
    QChar pickChar();
};

#endif // BUFFER_H
