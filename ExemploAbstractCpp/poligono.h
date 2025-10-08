#include <iostream>
#include <string.h>

#ifndef POLIGONO_H
#define POLIGONO_H

class poligono
{
private:
    /* data */
public:
    poligono(int lados, float comprimento);
    ~poligono();
    virtual calculaArea (int lados);
};

poligono::poligono(/* args */)
{
}

poligono::~poligono()
{
}


#endif