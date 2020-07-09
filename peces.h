/***************************************
 *
 * Modulo: Piezas
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_TIPOS_H
#define GRUPO_3_TIPOS_H

//Constantes
#define MAX 25

//Tipos propios
typedef struct {
    char compost[MAX];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} neumatics;

typedef struct {
    char compost[MAX];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} zonaAero;

typedef struct {
    zonaAero *frontal;
    int num_frontal;
    zonaAero *mitj;
    int num_mitj;
    zonaAero *posterior;
    int num_posterior;
} aero;

typedef struct {
    char compost[MAX];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} gasolina;

typedef struct {
    char compost[MAX];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} motor;

typedef struct {
    neumatics *neumatics;
    int num_neumatics;
    aero aero;
    gasolina *gasolina;
    int num_gasolina;
    motor *motor;
    int num_motor;
} cotxe;

#endif //GRUPO_3_TIPOS_H