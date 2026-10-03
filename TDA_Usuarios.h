#ifndef TDA_USUARIOS_H_INCLUDED
#define TDA_USUARIOS_H_INCLUDED

typedef struct
{
    char usuario[TAM_USER];
    char password[TAM_PASS];
    int tipo;
} tUsuario;

#endif // TDA_USUARIOS_H_INCLUDED
