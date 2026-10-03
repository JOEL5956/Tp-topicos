#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>

#define OP_CREAR_EV 1
#define OP_CREAR_EST 2
#define OP_VER_EV 3
#define OP_VER_VENTAS 4
#define OP_VER_ENTRADAS 5
#define OP_VER_REPORTE 6
#define OP_CONSULTAR_EVENTOS 7
#define OP_CONSULTAR_ENTRADAS 8

int Menu_Principal (FILE*); //seleccionar iniciar sesion o crear usuario
void Menu_Mod_Eventos ();
void Menu_Admin ();          //fcs de admin
void Menu_User ();           //fcs user

#endif // MENU_H_INCLUDED
