/***************************************
 *
 * Modulo: Gráfica
 * Definicion: Módulo encargado de printear
 *             por pantalla todos los gráficos
 *             necesarios para el uso del juego
 *             y del funcionamiento de la lógica
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_GRAFICA_H
#define GRUPO_3_GRAFICA_H

//Librerias del sistema
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <time.h>

//Librerias propias
#include "LS_allegro.h"
#include "peces.h"
#include "gp.h"
#include "usuario.h"
#include "corredores.h"
#include "classificacion.h"
#include "general.h"

//Constantes
#define GRAFICA_X 800
#define GRAFICA_Y 600
#define RADIO 20
#define SQUARE 20
#define LINEA 448
#define NUM_PIEZAS 6

//Tipos propios
typedef struct {
    int opcio;
} Configuracio;


/**********
 *
 * 	Descripción: Se encarga de calcular el tiempo transcurrido en la carrera.
 *	Entrada: Recibe el tiempo deseado para el clock de la carrera.
 *	Salida: Hace un return cuando ha pasado el tiempo indicado.
 *
 **********/
int timer(int segons);

/**********
 *
 *  Descripción: Restablece la configuración del coche por defecto.
 *	Entrada: Recibe por parámetro la estructura de la configuración del coche.
 *	Salida: No retorna nada.
 *
 **********/
void CONFIGURACIO_inicial(Configuracio *conf);

/**********
 *
 *  Descripción: Muestra por pantalla una imagen de un box, donde el usuario procederá a modificar el coche.
 *	Entrada: Recibe la estructura de coche.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_pintarBox(cotxe c);

/**********
 *
 * 	Descripción: Permite al usuario moverse entre las distintas piezas de las partes del monoplaza para escoger a la más favorable.
 *	Entrada: Recibe la estructura del coche junto con la configuración del coche.
 *	Salida: Retorna un “1” cuando la selección de la pieza se ha efectuado.
 *
 **********/
int GRAFICA_escogerPieza(cotxe c, Configuracio *conf);

/**********
 *
 * 	Descripción: Muestra por pantalla el dibujo de unos neumaticos y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_neumaticos(cotxe c, int opcio);

/**********
 *
 * 	Descripción: Muestra por pantalla el dibujo de gasolina y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_gasolina(cotxe c, int opcion);

/**********
 *
 *  Descripción: Muestra por pantalla el dibujo de “aero frontal” y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_aeroFrontal(cotxe c, int opcio);

/**********
 *
 *  Descripción: Muestra por pantalla el dibujo de “aero medio” y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_aeroMitj(cotxe c, int opcio);

/**********
 *
 * 	Descripción: Muestra por pantalla el dibujo de “aero posterior” y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_aeroPosterior(cotxe c, int opcio);

/**********
 *
 * 	Descripción: Muestra por pantalla el dibujo del motor y las características de la configuración seleccionada.
 *	Entrada: Recibe la estructura del coche y el número de la categoría.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_motor(cotxe c, int opcio);

/**********
 *
 *  Descripción: Posiciona a las flechas dibujadas anteriormente en la posición correspondiente.
 *	Entrada: Recibe las coordenadas de las flechas.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_menuArrows(float x, float y);

/**********
 *
 * 	Descripción: Printea por pantalla cuatro flechas compuestas por un cuadrado y un triángulo para poder modificar las opciones del coche.
 *	Entrada: Recibe las coordenadas de las flechas.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_drawArrow(float x, float y);

/**********
 *
 * 	Descripción: Muestra por pantalla los 5 semáforos para simular la cuenta atrás para empezar la carrera.
 *	Entrada: Recibe la estructura del usuario, de los pilotos, los circuitos que forman las carreras y la estructura de la puntuación.
 *	Salida: Retorna la puntuación.
 *
 **********/
classificacion GRAFICA_semaforo(Gp circuito, Usuario u, Pilotos *p, classificacion *puntuacio);

/**********
 *
 * 	Descripción: Muestra por pantalla los parámetros actuales del coche.
 *	Entrada: Recibe la estructura del coche y de la configuración del coche.
 *	Salida: No retorna nada.
 *
 **********/
void GRAFICA_confActual(cotxe c, Configuracio *conf);

/**********
 *
 * 	Descripción: Muestra por pantalla una representación de la carrera actual y el progreso de los coches. También se muestran los datos del circuito y del piloto que el usuario controla.
 *	Entrada: Recibe la estructura del usuario, de los pilotos, de los circuitos que forman las carreras y la estructura de la clasificación.
 *	Salida: Retorna la clasificación.
 *
 **********/
classificacion GRAFICA_carrera(Usuario usuario, Gp circuito, Pilotos *p, classificacion *classificacion1);

/**********
 *
 * 	Descripción: Esta función actualiza los parámetros del coche del usuario teniendo en cuenta las piezas seleccionadas.
 *	Entrada: Recibe la estructura de datos del usuario, del coche y la configuración que va a usar.
 *	Salida: Retorna el usuario.
 *
 **********/
Usuario ACTUALITZAR_cotxe(Usuario u, Configuracio *conf, cotxe cotxe);

/**********
 *
 * 	Descripción: Muestra por pantalla el progreso de la carrera actual.
 *	Entradas: Recibe las estructuras de usuario y los pilotos, el integrer num_parades, el tiempo y paradas_hechas.
 *	Salidas: No retorna nada.
 *
 **********/
void GRAFICA_pintarCarrera(Usuario usuario, int num_parades, int temps, Pilotos *p, int paradas_hechas);

/**********
 *
 * Descripción: Calcula el tiempo que le toma a cada corredor completar el circuito.
 *	Entradas: Recibe las estructuras de pilotos, gp y clasificación.
 *	Salidas: No retorna nada.
 *
 **********/
void CALCULAR_temps(Pilotos *p, Gp carrera, classificacion *classificacion1);

#endif //GRUPO_3_GRAFICA_H
