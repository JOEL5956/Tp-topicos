#ifndef TDA_COMPRA_H_INCLUDED
#define TDA_COMPRA_H_INCLUDED

#define MAX_ENTRADAS_POR_COMPRA 5

#include "TDA_Entrada.h"

typedef struct
{
    char id[10];
    char idUsuario;
    char idEvento;
    tEntrada entradas[MAX_ENTRADAS_POR_COMPRA];
    int cantEntradas;
    float ImporteTotal;
    unsigned long long fechaCompra;
} tCompra;

#endif // TDA_COMPRA_H_INCLUDED
