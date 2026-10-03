#ifndef FUNCIONES_GENERALES_H_INCLUDED
#define FUNCIONES_GENERALES_H_INCLUDED

#include <stdio.h>

int comparar_char(void*, void*);
void *BusquedaBinaria();

/*
void ordenarInsercion(Vector* v)
{
    int* ult = v->vec + (v->ce - 1);
    int* j;
    int elemAIns;

    for(int* i = v->vec + 1; i <= ult; i++)
    {
        elemAIns = *i;
        j = i - 1;
        while(j >= v->vec && elemAIns < *j)
        {
            *(j + 1) = *j;
            j--;
        }

        *(j + 1) = elemAIns;
    }
}
*/

#endif // FUNCIONES_GENERALES_H_INCLUDED
