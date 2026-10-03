#include "TDA_Usuario.h"

int comparar(void *a, void *b)
{
    char *c1 = a;
    char *c2 = b;

    while (*c1 && *c2) {
        if (*c1 != *c2)
            return *c1 - *c2;
        c1++;
        c2++;
    }
    return *c1 - *c2;
}

int BusquedaBinaria(void *vec, int cant, size_t tam, void *buscado)
{
    int pos = -1, izq, der, medio;

    izq = 0;
    der = cant - 1;

    while(izq <= der && pos == -1)
    {
        medio = izq + ((der-izq)/2);

        if(comparar(vec+medio*tam, buscado)== 0)
            pos = medio;
        else
            if(comparar(vec+medio*tam, buscado) < 0)
                izq = medio;
            else
                der = medio;
    }
    return pos;
}

//                      void vec, int cant, size_t tam, void buscado
/*void *BusquedaBinaria(const Vector* v, void* elem, Cmp cmp)
{
    void* li = v->vec;
    void* ls = v->vec + (v->ce - 1) * v->tamElem;
    void* m;
    int comp;
    bool encontrado = false;
    int ind = -1;

    while(!encontrado && li <= ls)
    {
        m = li + (((ls - li) / v->tamElem) / 2) * v->tamElem;

        comp = cmp(elem, m);

        if(comp < 0)
        {
            ls = m - v->tamElem;
        }
        else if(comp > 0)
        {
            li = m + v->tamElem;
        }
        else
        {
            encontrado = true;
            memcpy(elem, m, v->tamElem);
            ind = (m - v->vec) / v->tamElem;
        }
    }

    return ind;
}
*/
