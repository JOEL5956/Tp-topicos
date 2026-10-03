#ifndef TDA_SECTOR_H_INCLUDED
#define TDA_SECTOR_H_INCLUDED

#include "TDA_Ubicacion.h"

#define MAX_F 30
#define MAX_C 45

typedef struct
{
    unsigned id;
    char nommbre[15];
    unsigned capacidad;
    float precio;
    int filas;
    int columnas;
    tUbicacion ubicaciones[MAX_F][MAX_C];
} tSectores;

#endif // TDA_SECTOR_H_INCLUDED
