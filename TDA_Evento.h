#ifndef TDA_EVENTO_H_INCLUDED
#define TDA_EVENTO_H_INCLUDED

#define DISPONIBLE 1
#define CANCELADO -1
#define fINALIZADO 2

#define TAM_ID 11
#define TAM_NOMBRE 11
#define TAM_TIPO 11

#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[TAM_ID];
    char nombre[TAM_NOMBRE];
    char tipoEvento[TAM_TIPO];
    unsigned idEstablecimiento;
    unsigned long long fecha;
    unsigned long long hora;
    int estado;
} tEvento;

int Evento_Nuevo();
void Crear_Evento ();
void Consultar_Evento ();
void Ver_Ventas ();
void Ver_Entradas();
void Ver_Reporte ();
void Consultar_Entradas ();

#endif // TDA_EVENTO_H_INCLUDED
