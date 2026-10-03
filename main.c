#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "TDA_Usuario.h"

int main()
{
    int tipo;

    FILE* archUsers = fopen("Usuarios.bin", "r+b");  //abrir arch si existe
    if (archUsers == NULL)
        archUsers = fopen("Usuarios.bin", "w+b");   //crearlo si no existe

    tipo = Menu_Principal(archUsers);               //pantalla principal

    while (tipo == NONE)                            //hasta q no sea NONE
        tipo = Menu_Principal(archUsers);           //obtengo tipo usuario

    fclose (archUsers);

    //Menu segun tipo de usuario
    if (tipo == ADMIN)
        Menu_Admin();
    else
        Menu_User();

    return 0;
}
