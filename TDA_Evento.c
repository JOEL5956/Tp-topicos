#include "TDA_Evento.h"
#include "Funciones_Generales.h"

int Evento_Nuevo(FILE *archivo, char ID[TAM_ID])
{
    tEvento evento;
    rewind(archivo);
    while (fread(&evento, sizeof(tEvento), 1, archivo) == 1)
    {
        if (strcmp(evento.id, ID) == 0)
            return 0;
    }
    return 1;
}

void Crear_Evento (FILE *arch)
{
    tEvento evento;
    int estEncontrado = 0;
    char ID[TAM_ID];
    unsigned idest;

    printf("\n--- Crear Evento ---\n");
    printf("\nID: ");
    scanf("%s",ID);

    while(!Evento_Nuevo (arch, ID))
    {
        printf("\nEvento ya existente, reintente: ");
        scanf("%s",ID);
    }
    strcpy(evento.id, ID);
    printf("\nNombre evento: ");
    scanf("%s",evento.nombre);
    printf("\nIngresar tipo de evento: ");
    scanf("%s",evento.tipoEvento);
    printf("\nID establecimiento: ");
    scanf("%u",&idest);
/*
    while(!estEncontrado)
    {
        fseek(arch, 0, SEEK_SET);
        //mem din bajar id a vec
        if (BusquedaBinaria())
           estEncontrado = 1;
    }
*/
//validar formatos
    printf("\nFecha (DD/MM/AAAA): ");
    scanf("%llu",&evento.fecha);
    printf("\nHora (HH:MM): ");
    scanf("%llu",&evento.hora);

    evento.estado = DISPONIBLE;

    fseek(arch, 0, SEEK_END);
    if (fwrite(&evento, sizeof(tEvento), 1, arch) == 1)
        printf("\nEvento creado correctamente.\n");
    else
        printf("\nError al guardar el evento.\n");

    fclose(arch);
}

void Consultar_Evento(FILE *arch)
{
    tEvento Evento;
    printf("\n--- Eventos ---");
    fseek(arch, 0, SEEK_SET);
    while(fread(&Evento,sizeof(tEvento),1,arch))
    {
        if(Evento.estado == DISPONIBLE)
        {
            printf("\nID evento: %s", Evento.id);
            printf("\nNombre evento: %s", Evento.nombre);
            printf("\nTipo de evento: %s", Evento.tipoEvento);
            printf("\nFecha: %llu", Evento.fecha);
            printf("\nHora: %llu", Evento.hora);

            //printf("\nEstablecimiento: %s", Establecimiento.nombre);
        }
    }
}

void Ver_Ventas ()
{

}
void Ver_Entradas()
{

}
void Ver_Reporte ()
{

}
void Consultar_Entradas ()
{

}
