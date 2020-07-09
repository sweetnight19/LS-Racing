/***************************************
 *
 * Modulo: Ficheros
 * Definicion: Se procede a la lectura de
 *              todos los demás ficheros.
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_FITXERS_H
#define GRUPO_3_FITXERS_H

//librerias del sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Librerias propias
#include "peces.h"
#include "gp.h"
#include "corredores.h"
#include "base.h"
#include "LS_allegro.h"

//Constantes
#define NUM_PILOTOS 7

/**********
 *
 *  Descripción: Lee el archivo donde se encuentran almacenada la información de los parámetros base.
 *  Entradas: Recibe el puntero del fichero a leer y la estructura de tipo base.
 *  Salidas: No retorna nada.
 *
 ***********/
void llegirBase(FILE *fitxer, Base *b);

/**********
 *
 * Descripción: Se encarga de leer los diferentes componentes de los monoplazas para que luego el usuario pueda modificarlo.
 *  Entradas: Recibe el archivo de las piezas junto con el del coche.
 *	Salidas: No retorna nada
 *
 **********/
void llegirPeces(FILE *peces, cotxe *cotxe);

/**********
 *
 *	Descripción: Se encarga de abrir los ficheros,redirigir las lecturas y en el caso de que falte o se encuentre vacio uno (o más) de ellos, notificar el error.
 *	Entradas: Recibe el archivo a leer, la estructura del coche, una lista ordenada, la estructura de los pilotos, atributos de tipo base y la opción a escoger.
 *	Salidas: Retorna un '0' para indicar que el programa ha finalizado o un '1' si ha habido algun erro
 *
 **********/
int llegirFitxer(FILE *fitxer, cotxe *cotxe, ListaOrd *l, Pilotos *p, Base *b, int opcio);

/**********
 *
 *	Descripción: Esta función se dedica a leer y rellenar la información pertinente a todos los circuitos.
 *	Entradas: Recibe el archivo de los circuitos y una lista ordenada.
 *	Salidas: No retorna nada.
 *
 **********/
void llegirGP(FILE *gp, ListaOrd *l);

/**********
 *  Descripción: La función se dedica a leer el archivo donde se encuentra la información de los corredores con los que el usuario se va a enfrentar.
 *	Entradas: Recibe el fichero a leer y la estructura de los pilotos.
 *	Salidas: No retorna nada.
***********/
void llegirCorredors(FILE *fitxer, Pilotos *p);

#endif //GRUPO_3_FITXERS_H
