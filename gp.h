/***************************************
 *
 * Modulo: Grandes Premios
 * Definicion: Se encarga de guardar la
 *             información necesaria para
 *             el gran premio
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef _LISTAORD_H_
#define _LISTAORD_H_

//Librerias del sistema
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define MAXIMO 25

//Tipos propios
typedef struct {
    char nom[MAXIMO];
    int posicion;
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
    float tiempo_base;
    int tiempo_pit_stop;
    int num_pit_stop;
} Gp;

typedef struct N {
    Gp elemento;
    struct N *sig;
} Nodo;

typedef struct {
    Nodo *pri;
    Nodo *ant;
    int total;
} ListaOrd;


/**********
 *
 * 	Descripción: Crea una lista ordenada para guardar datos dentro.
 *	Entrada: No recibe nada.
 *	Salida: Retorna una lista ordenada.
 *
 **********/
ListaOrd LISTAORD_crea();

/**********
 *
 * 	Descripción: Inserta de manera ordenada un elemento a la lista.
 *	Entrada: Recibe una lista ordenada y un elemento.
 *	Salida: Retorna la lista ordenada actualizada.
 *
 **********/
ListaOrd LISTAORD_insertaOrd(ListaOrd l, Gp elemento);

/**********
 *
 * 	Descripción: Inserta un elemento a la lista.
 *	Entrada: Recibe una lista ordenada y un elemento.
 *	Salida: Retorna la lista actualizada.
 *
 ***********/
ListaOrd LISTAORD_inserta(ListaOrd l, Gp elemento);

/**********
 *
 *	Descripción: Elimina un elemento de la lista.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la lista actualizada.
 *
 **********/
ListaOrd LISTAORD_elimina(ListaOrd l);

/**********
 *
 *	Descripción: Consulta la información de un elemento de la lista.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna un elemento.
 *
 **********/
Gp LISTAORD_consulta(ListaOrd l);

/**********
 *
 *	Descripción: Mueve la posición del cursor de la lista una posición para adelante.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la lista.
 *
 **********/
ListaOrd LISTAORD_avanza(ListaOrd l);

/**********
 *
 *	Descripción: Mueve la posición del cursor de la lista al principio de ésta.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la lista.
 *
 **********/
ListaOrd LISTAORD_vesInicio(ListaOrd l);

/**********
 *
 * 	Descripción: Comprueba si se ha llegado al final de la lista.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la siguiente posición del cursor.
 *
 **********/
int LISTAORD_final(ListaOrd l);

/**********
 *
 * 	Descripción: Comprueba si hay algún elemento en la lista.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la posición anterior del cursor.
 *
 ***********/
int LISTAORD_vacia(ListaOrd l);

/**********
 *
 * Descripción: Borra la lista de la memoria.
 *	Entrada: Recibe una lista ordenada.
 *	Salida: Retorna la lista destruida.
 *
 ***********/
ListaOrd LISTAORD_destruye(ListaOrd l);

#endif
