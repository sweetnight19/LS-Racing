/***************************************
 *
 * Modulo: Menu
 * Definicion: Encargado de mostrar el menú
 *             principal antes y después de
 *             la ejecución de cualquier opción
 *             escogida
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_MENU_H
#define GRUPO_3_MENU_H

//Librerias del sistema
#include <stdio.h>

/**********
*   Descripción: Muestra el menú por pantalla.
*	Entrada: No recibe nada.
*   Salida: No retorna nada.
***********/
void printarMenu();

/**********
 *
 *  Descripción: Lee la opción que el usuario desea ejecutar.
 *  Entrada: Recibe la opción a escoger.
 *  Salida: No retorna nada.
 *
 **********/
void llegirOpcio(char opcio[5]);

#endif //GRUPO_3_MENU_H
