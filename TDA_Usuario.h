#ifndef INICIO_SESION_H_INCLUDED
#define INICIO_SESION_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define TAM_USER 9
#define TAM_PASS 9

#define NONE 0
#define ADMIN 1
#define USER 2

typedef struct
{
    char usuario[TAM_USER];
    char contrasenia[TAM_PASS];
    int tipo;
} tUsuario;

int Usuario_Nuevo (FILE*,char[TAM_USER]);
int Crear_Usuario(FILE*);                                           //si no hay usuarios o se quiere crear uno
int Iniciar_Sesion (FILE*);                                         //devuelve tipo de usuario
int Validar_Usuario (FILE*, char[TAM_USER], char[TAM_PASS]);        //NONE si no existe, detecta tipo si existe

#endif // INICIO_SESION_H_INCLUDED
