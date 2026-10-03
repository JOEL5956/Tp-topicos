#include "Menu.h"
#include "TDA_Usuario.h"
#include "TDA_Evento.h"
#include "TDA_Establecimiento.h"

int Menu_Principal (FILE* arch)
{
    int opcion;
    int tipo;

    printf("\n--- Sistema de gestion de entradas ---");
    printf("\n\tBienvenido!");
    printf("\n\t1..........Iniciar sesion");
    printf("\n\t2..........Registrarse\n\t");
    scanf("%d",&opcion);

    if(opcion == 1)
        tipo = Iniciar_Sesion(arch);
    else
        tipo = Crear_Usuario(arch);

    return tipo;
}

//recibir un evento
void Menu_Mod_Eventos ()
{
    int opcion;

    printf("\nBienvenido admin");
    printf("\n%d-Ver ventas",OP_VER_VENTAS);
    printf("\n%d-Ver cantidad de entradas",OP_VER_ENTRADAS);
    printf("\n%d-Ver Reporte",OP_VER_REPORTE);
    scanf("%d",&opcion);

     switch(opcion)
    {
        case OP_VER_VENTAS:
        {
            Ver_Ventas();
            break;
        }
        case OP_VER_ENTRADAS:
        {
            Ver_Entradas();
            break;
        }
        case OP_VER_REPORTE:
        {
            Ver_Reporte();
            break;
        }
    }
}

void Menu_Admin ()
{
    int opcion;

    printf("\nBienvenido admin");
    printf("\n%d-Crear Evento",OP_CREAR_EV);
    printf("\n%d-Crear Establecimiento",OP_CREAR_EST);
    printf("\n%d-Ver Evento",OP_VER_EV);
    scanf("%d",&opcion);

    switch(opcion)
    {
        case OP_CREAR_EV:
        {
            FILE* archEventos = fopen("Eventos.bin", "r+b");  //abrir arch si existe
            if (archEventos == NULL)
                archEventos = fopen("Eventos.bin", "w+b");   //crearlo si no existe
            Crear_Evento(archEventos);
            fclose(archEventos);
            break;
        }
        case OP_CREAR_EST:
        {
            FILE* archEstab = fopen("Establecimientos.bin", "r+b");  //abrir arch si existe
            if (archEstab == NULL)
                archEstab = fopen("Establecimientos.bin", "w+b");   //crearlo si no existe
            Crear_Establecimiento(archEstab);
            fclose(archEstab);
            break;
        }
        case OP_VER_EV:
        {
            //fc ver eventos y devuelve un ev en concreto
            Menu_Mod_Eventos();
            break;
        }
    }
}

void Menu_User ()
{
    int opcion;
    printf("Bienvenido user");
    printf("\n%d-Consultar Eventos",OP_CONSULTAR_EVENTOS);
    printf("\n%d-Concultar entradas",OP_CONSULTAR_ENTRADAS);
    scanf("%d",&opcion);

    switch(opcion)
    {
        case OP_CONSULTAR_EVENTOS:
        {
            Consultar_Evento();
            break;
        }
        case OP_CONSULTAR_ENTRADAS:
        {
            Consultar_Entradas();
            break;
        }
    }
}
