/***************************************
 *
 * Modulo: Usuario
 * Definicion: En este módulo se pide la
 *             información correspondiente
 *             del corredor que el usuario
 *             va a controlar en el transcurso
 *             de la partida
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_USUARIO_H
#define GRUPO_3_USUARIO_H

//Librerias del sistema
#include <stdio.h>
#include <string.h>

//Librerias propias
#include "LS_allegro.h"
//#include "grafica.h"

//Constantes
#define MAX_CHAR 25

//Tipos propios
typedef struct {
    char nombre[MAX_CHAR];
    char escuderia[MAX_CHAR];
    int dorsal;
    int reflejos;
    int condicion_fisica;
    int temperamento;
    int gestion_neumaticos;
    int check;
    int cotxe_velocitat;
    int cotxe_acceleracio;
    int cotxe_consum;
    int cotxe_fiabilitat;
} Usuario;


/**********
 *
 *	Descripción: Crea la estructura de datos para introducir la información del usuario.
 *	Entradas: No recibe nada.
 *	Salidas: Retorna la estructura del usuario.
 *
 ***********/
Usuario USUARIO_crearUsuario();

/**********
 *
 *	Descripción: Rellena la estructura de datos creada anteriormente con la información pertinente.
 *	Entradas: Recibe la estructura del usuario.
 *	Salidas: Retorna la estructura del usuario.
 *
 ***********/
Usuario USUARIO_pedirInformacion(Usuario u);

#endif //GRUPO_3_USUARIO_H