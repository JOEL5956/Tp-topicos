#ifndef TDA_ESTABLECIMIENTO_H_INCLUDED
#define TDA_ESTABLECIMIENTO_H_INCLUDED

#include "TDA_Sector.h"
#include <stdio.h>

#define MAX_SECTORES 15

typedef struct
{
    unsigned id;
    char nommbre[30];
    char direccion[30];
    unsigned capacidad_total;
    tSectores sectores[MAX_SECTORES];
} tEstablecimiento;

void Crear_Establecimiento(FILE*);

#endif // TDA_ESTABLECIMIENTO_H_INCLUDED
