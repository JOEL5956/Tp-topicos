#include "TDA_Usuario.h"

int Usuario_Nuevo (FILE *archivo, char user[TAM_USER])
{
    tUsuario usuario;
    rewind(archivo);
    while (fread(&usuario, sizeof(tUsuario), 1, archivo) == 1)
        if (strcmp(usuario.usuario, user) == 0)
            return 0;
    return 1;
}

int Crear_Usuario(FILE* arch)
{
    tUsuario usuario;
    char user[TAM_USER], tipo;

    printf("\n--- Crear Usuario ---\n");
    printf("\nUsuario: ");
    scanf("%s",user);
    while(!Usuario_Nuevo (arch, user))
    {
        printf("\nUsuario ya existente, reintente: ");
        printf("\nUsuario: ");
        scanf("%s",user);
    }
    strcpy(usuario.usuario, user);
    printf("Contrasena: ");
    scanf("%s",usuario.contrasenia);
    printf("Es un administrador (A) o un  usuario (U): ");
    scanf(" %c", &tipo);
    tipo = toupper(tipo);

    if (tipo == 'A')
    {
        usuario.tipo = ADMIN;
        printf("\nAdministrador ");
    }
    else
    {
        usuario.tipo = USER;
        printf("\nUsuario ");
    }

    fseek(arch, 0, SEEK_END);
    if (fwrite(&usuario, sizeof(tUsuario), 1, arch))
        printf("creado correctamente.\n");
    else
        printf("no se pudo guardar.\n");

    return tipo;
}

int Validar_Usuario (FILE* arch, char user[TAM_USER], char password[TAM_PASS])
{
    tUsuario usuario;
    int tipo = NONE;
    rewind(arch);
    while(tipo == NONE && fread(&usuario, sizeof(tUsuario), 1, arch) == 1)
        if(strcmp(usuario.usuario, user) == 0)
            if(strcmp(usuario.contrasenia, password) == 0)
                tipo = usuario.tipo;
    return tipo;
}

int Iniciar_Sesion (FILE* arch)
{
    char user[TAM_USER];
    char password [TAM_PASS];
    int tipo;

    printf("\n--- Inicie Sesion ---");
    printf("\n\tUsuario: ");
    scanf("%s",user);
    printf("\n\tContraseña: ");
    scanf("%s",password);

    tipo = Validar_Usuario(arch, user, password);

    if (tipo == NONE)
        printf("\nError, Usuario o contraseña incorrectos...");
    return tipo;
}


