/***************************************
 *
 * Modulo: Classificacions
 * Definicion: Se encarga de guardar la
 *             información de la clasificación
 *             de los corredores de las carreras.
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_CLASSIFICACION_H
#define GRUPO_3_CLASSIFICACION_H

//Librerias del sistema
#include <stdio.h>

//Librerias propias
#include "classificacion.h"
#include "corredores.h"
#include "gp.h"
#include "LS_allegro.h"
#include "grafica.h"
#include "general.h"
#include "usuario.h"

//CONSTANTES
#define NUM_PILOTOS 7

//Tipos propios
typedef struct {
    classificacion *c;
    char nombre_circuito[MAXIMO];
} c;
typedef c Puntuacio[4];


/**********
 *
 *	Descripción: Otorga a los corredores la puntuación pertinente según su tiempo final en la carrera.
 *	Entrada: Recibe la estructura de clasificación de la carrera actual.
 *	Salida: Retorna la estructura de clasificación ordenada.
 *
 **********/
classificacion ORDENAR_classifcacion(classificacion *puntuacio);

/**********
 *
 *	Descripción: Muestra por pantalla el ranking de los corredores de cada carrera.
 *	Entrada: Recibe la clasificación de las 4 carreas, el número de las carreras y la clasificación general.
 *	Salida: No retorna nada.
 *
 **********/
void mostrarRanking(c puntuacio[4], int num_carrera, General *general);

/**********
 *
 *	Descripción: Muestra la clasificación general de los corredores al acabar todas las carreras.
 *  Entrada: Recibe la clasificación general junto con la posición del puntero del ranking.
 *	Salida: Retorna la posición donde se encuentra el puntero de ranking.
 *
 **********/
int mostrarGeneral(General *general, int posicio);

/**********
 *
 *	Descripción: Inicializa la clasificación general con el nombre y el dorsal de los pilotos con puntuación = 0.
 *	Entrada: Recibe la clasificación general junto con la estructura de los pilotos y del usuario.
 *	Salida: Retorna el array dinámico ordenado.
 *
 **********/
General INICIALIZAR_general(General *general, Pilotos pilots, Usuario u);

/**********
 *
 *	Descripción: Actualiza el array dinámico ordenado después de cada carrera.
 *	Entrada: Recibe la clasificación general juntamente con la clasificación de la última carrera que se ha realizado.
 *	Salida: Retorna el array dinámico ordenado.
 *
 **********/
General ACTUALIZAR_classificacio(General *general, classificacion *puntuacio);

/**********
 *
 * 	Descripción: Genera el log de la clasificación del final de temporada en forma de un fichero de texto.
 *	Entrada: Recibe la clasificación general juntamente con la clasificación de todas las carreras por separado.
 *	Salida: No retorna nada.
 *
 **********/
void CLASSIFICACION_guardarLog(General *general, c *puntuacio);

#endif //GRUPO_3_CLASSIFICACION_H
