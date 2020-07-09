/*
    Mòdul de simplificació i adaptació de l'API de la llibreria
    Allegro 5 per al desenvolupament senzill de jocs 2D a l'assignatura
    de Programació 1. Aquesta adaptació només facilita el desenvolupament
    estalviant a l'alumne haver de tenir coneixements avançats sobre
    listeners i events que utilitza aquesta llibreria per realitzar tasques
    com l'escoltat del teclat, la inicialització o el pintat de la pantalla.

    Autor : Albert Lloveras Carbonell
    Data Última Revisió : 05/09/2014
    CopyRight : Distribució lliure sense cap limitació

*/

#ifndef _ALLEGRO_LA_SALLE_H_
#define _ALLEGRO_LA_SALLE_H_

//Operating System Includes
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Operating System Depending Includes
#if defined(__linux__)
#include <pthread.h>
#endif

//Includes Allegro5include
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

//--------------- COLORS DISPONIBLES -------- //
#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define CYAN 3
#define RED 4
#define PINK 5
#define ORANGE 6
#define LIGHT_GRAY 7
#define GRAY 8
#define BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_BLUE 11
#define GARNET 12
#define LIGHT_PINK 13
#define YELLOW 14
#define WHITE 15
#define GREEN 16
//--------------- TAMANYS DE FONT DISPONIBLES ---- //
#define SMALL 0
#define NORMAL 1
#define LARGE 2
#define EXTRA_LARGE 3

//Pre : Cap
//Post: Retorna 1 (CERT) si s'ha pogut inicialitzar correctament el Framework d'Allegro5. En cas contrari es retornarà 0 (FALS).
int LS_allegro_init(int nAmplitud, int nAltura, char *sNomFinestra);

//Pre : El valor del paràmetre nKey ha de ser una constant del tipus ALLEGRO_KEY_XXXXXX
//Post : Retorna 1 (Cert) si s'ha premut la tecla rebuda al paràmetre nKey. En cas contrari, es retornarà 0 (FALS). ATENCIÓ!! LECTURA DESTRUCTIVA!
int LS_allegro_key_pressed(int nKey);

//Pre : El valor de nColor ha d'estar entre 0 i 16 ambdós inclosos.
//Post : Retorna una variable del tipus ALLEGRO_COLOR corresponent al color demanat.
ALLEGRO_COLOR LS_allegro_get_color(int nColor);

//Pre : El valor de nSize ha d'estar dins l'interval [0,MAX_FONTS)
//Post : Retorna una variable del tipus ALLEGRO_FONT * per poder usar la funció al_draw_textf més facilment.
ALLEGRO_FONT *LS_allegro_get_font(int nSize);

//Pre : El framework d'Allegro 5 ha d'estar inicialitzat prèviament. (LS_allegro_init() ha d'haver retornat 1)
//Post : Allibera la memòria que s'havia reservat per a les variables necessàries per fer funcionar Allegro5.
void LS_allegro_exit();

//Pre : nColor ha d'estar dins l'interval [0,MAX_COLORS)
//Post : Fixa el color de fons de la finestra gràfica.
void LS_allegro_clear_and_paint(int nColor);

//Pre : Cap	
//Post: Neteja els buffers del teclat perquè no hi quedi cap tecla emmagatzemada.
void LS_allegro_console_fflush();

//Pre : Cap
//Post: Neteja la pantalla de la consola
void LS_allegro_console_clear_screen();

#endif // _ALLEGRO_LA_SALLE_H_
