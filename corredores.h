/***************************************
 *
 * Modulo: Pilotos
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#ifndef GRUPO_3_CORREDORES_H
#define GRUPO_3_CORREDORES_H

//Constantes
#define NOMBRE 25

//Tipos propios
typedef struct {
    char nombre[NOMBRE];
    int dorsal;
    char escuderia[NOMBRE];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    int reflejos;
    int condicion_fisica;
    int temperamento;
    int gestion_neumaticos;
} corredores;

typedef struct {
    corredores *c;
} Pilotos;

#endif //GRUPO_3_CORREDORES_H
