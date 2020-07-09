/***************************************
 *
 * Modulo: Menu
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "menu.h"

void printarMenu() {
    printf("\nBienvenido a LS Racing!\n\n");
    printf("\t1. Configurar coche\n");
    printf("\t2. Carrera\n");
    printf("\t3. Ver clasificacion\n");
    printf("\t4. Guardar temporada\n");
}

void llegirOpcio(char opcio[5]) {
    printf("\nQue opcion quieres ejecutar? ");
    scanf("\n%s", opcio);
}