/***************************************
 *
 * Modulo: General
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_GENERAL_H
#define GRUPO_3_GENERAL_H

//CONSTANTES
#define NUM_PILOTS 8

//Tipos propios
typedef struct {
    char nom[NOMBRE];
    int temps_carrera;
    int num_parades;
    int xcirculo;
    int velocitat;
    int punts;
} classificacion;

typedef struct {
    char nom[NOMBRE];
    int dorsal;
    int punts;
} General;

#endif //GRUPO_3_GENERAL_H
