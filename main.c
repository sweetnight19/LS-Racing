/***************************************
 *
 * Modulo: Main
 * Definicio: En este módulo transcurren
 *            todos los procesos principales
 *            del proyecto
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

//Librerias del sistema
#include <stdio.h>
#include <string.h>

//Librerias propias
#include "LS_allegro.h"
#include "menu.h"
#include "peces.h"
#include "fitxers.h"
#include "corredores.h"
#include "gp.h"
#include "base.h"
#include "classificacion.h"
#include "grafica.h"
#include "usuario.h"

void main(int argc, char *argv[]) {
    int fitxers, check = 0, num_carrera = 1;
    char opcio[5];
    FILE *peces, *gp, *pilots, *base;
    cotxe cotxe;
    ListaOrd l;
    Pilotos p;
    Base b;
    Usuario u;
    Gp circuito;
    Configuracio *conf;
    Puntuacio puntuacio;
    General *general;

    //Control de errores
    /*******************************************/
    if (argc != 5) {
        printf("Error. El programa tiene que recibir 4 argumentos\n");
    } else {

        //Lectura de los ficheros de entrada por argumentos
        /*******************************************/

        peces = fopen(argv[1], "r");
        fitxers = llegirFitxer(peces, &cotxe, &l, &p, &b, 1);
        if (fitxers == 0) {

            //Inicializamos la lista
            l = LISTAORD_crea();

            gp = fopen(argv[2], "r");
            fitxers = llegirFitxer(gp, &cotxe, &l, &p, &b, 2);
        }
        if (fitxers == 0) {
            pilots = fopen(argv[3], "rb");
            fitxers = llegirFitxer(pilots, &cotxe, &l, &p, &b, 3);
        }
        if (fitxers == 0) {
            base = fopen(argv[4], "rb");
            fitxers = llegirFitxer(base, &cotxe, &l, &p, &b, 4);
        }
        /*******************************************/

        if (fitxers == 0) {

            //Creacion de memoria dinamica
            /*******************************************/
            conf = (Configuracio *) malloc(sizeof(Configuracio) * NUM_PIEZAS);
            puntuacio[0].c = (classificacion *) malloc(sizeof(classificacion) * NUM_PILOTS);
            puntuacio[1].c = (classificacion *) malloc(sizeof(classificacion) * NUM_PILOTS);
            puntuacio[2].c = (classificacion *) malloc(sizeof(classificacion) * NUM_PILOTS);
            puntuacio[3].c = (classificacion *) malloc(sizeof(classificacion) * NUM_PILOTS);
            general = (General *) malloc(sizeof(General) * NUM_PILOTS);
            /*******************************************/

            //Aplicamos las inicializaciones
            CONFIGURACIO_inicial(conf);
            u = USUARIO_crearUsuario();

            while (strcmp(opcio, "exit") != 0) {
                printarMenu();
                llegirOpcio(opcio);
                if (strcmp("exit", opcio) != 0 && strlen(opcio) == 1) {
                    switch (opcio[0]) {
                        case '1':
                            u = USUARIO_pedirInformacion(u);

                            //Inicializamos la general
                            *general = INICIALIZAR_general(general, p, u);

                            printf("\nCargando configurador ...\n");

                            //Cargamos la ventana grafica y pasamos a escoger las piezas del motor
                            LS_allegro_init(GRAFICA_X, GRAFICA_Y, "LS Racing");
                            check = GRAFICA_escogerPieza(cotxe, conf);
                            break;
                        case '2':
                            if (check == 0) {
                                printf("\nAun no has configurado el coche\n");
                            } else {
                                //Escogemos la carrera pertinente
                                /*******************************************/
                                if (num_carrera <= l.total) {
                                    LISTAORD_vesInicio(l);
                                    circuito = LISTAORD_consulta(l);
                                    while (num_carrera != circuito.posicion) {
                                        l = LISTAORD_avanza(l);
                                        circuito = LISTAORD_consulta(l);
                                    }
                                    /*******************************************/

                                    //Cargamos la suma de todas las piezas al usuario
                                    u = ACTUALITZAR_cotxe(u, conf, cotxe);

                                    printf("\nPreparando carrera #%d: %s\n", num_carrera, circuito.nom);

                                    //Inicializamos la carrera
                                    LS_allegro_init(GRAFICA_X, GRAFICA_Y, "LS Racing");
                                    *(puntuacio[num_carrera - 1].c) = GRAFICA_semaforo(circuito, u, &p,
                                                                                       puntuacio[num_carrera - 1].c);
                                    LS_allegro_exit();

                                    //Ordenamos la classificacion de la carrera
                                    *(puntuacio[num_carrera - 1].c) = ORDENAR_classifcacion(
                                            puntuacio[num_carrera - 1].c);
                                    strcpy(puntuacio[num_carrera - 1].nombre_circuito, circuito.nom);

                                    //Actualizamos la general
                                    *general = ACTUALIZAR_classificacio(general, puntuacio[num_carrera - 1].c);

                                    num_carrera++;
                                } else {
                                    printf("\nYa has finalizado la temporada.\n");
                                }
                            }
                            break;
                        case '3':
                            if (num_carrera == 1) {
                                printf("\nLa temporada aun no ha empezado.\n");
                            } else {
                                LS_allegro_init(GRAFICA_X, GRAFICA_Y, "LS Racing");
                                mostrarRanking(puntuacio, num_carrera, general);
                                LS_allegro_exit();
                            }
                            break;
                        case '4':
                            if (num_carrera == 5) {
                                CLASSIFICACION_guardarLog(general, puntuacio);
                            } else {
                                printf("\nAun no has finalizado la temporada\n");
                            }
                            break;
                        default:
                            printf("Introudeix un 1,2,3,4 o exit per sortir, gracies\n");
                    }
                }
                if (strcmp("exit", opcio) != 0 && strlen(opcio) > 1) {
                    printf("Introudeix un 1,2,3,4 o exit per sortir, gracies\n");
                }
            }

            //Liberacion de la memoria dinámica
            /*******************************************/
            free(cotxe.neumatics);
            free(cotxe.aero.frontal);
            free(cotxe.aero.mitj);
            free(cotxe.aero.posterior);
            free(cotxe.gasolina);
            free(cotxe.motor);
            free(conf);
            LISTAORD_destruye(l);
            free(p.c);
            free(puntuacio[0].c);
            free(puntuacio[1].c);
            free(puntuacio[2].c);
            free(puntuacio[3].c);
            free(general);
            /*******************************************/
        }
    }
}