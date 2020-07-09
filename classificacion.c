/***************************************
 *
 * Modulo: Classificacions
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "classificacion.h"

classificacion ORDENAR_classifcacion(classificacion *puntuacio) {
    int i, j;
    classificacion aux;

    j = 0;
    i = j + 1;
    //Aplicamos metodo de ordenacion por seleccion
    /*************************************************/
    while (j < 8) {
        i = j + 1;
        while (i < 8) {
            if (puntuacio[j].temps_carrera > puntuacio[i].temps_carrera) {
                aux = puntuacio[j];
                puntuacio[j] = puntuacio[i];
                puntuacio[i] = aux;
            }
            i++;
        }
        j++;
    }
    /************************************************/
    //Asignamos la puntuacion respectivamente a su posicion
    /************************************************/
    puntuacio[0].punts = 25;
    puntuacio[1].punts = 18;
    puntuacio[2].punts = 15;
    puntuacio[3].punts = 10;
    puntuacio[4].punts = 8;
    puntuacio[5].punts = 6;
    puntuacio[6].punts = 5;
    puntuacio[7].punts = 3;
    /*************************************************/
    return *puntuacio;
}

void mostrarRanking(c puntuacio[4], int num_carrera, General *general) {
    int exit = 0, posicio = num_carrera - 2;

    while (!exit) {
        LS_allegro_clear_and_paint(BLACK);

        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.1, GRAFICA_Y * 0.1, 0,
                      "CLASSIFICACIO DE %s", puntuacio[posicio].nombre_circuito);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.05, GRAFICA_Y * 0.2, 0,
                      "1. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[0].nom, puntuacio[posicio].c[0].temps_carrera,
                      puntuacio[posicio].c[0].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(GRAY), GRAFICA_X * 0.05, GRAFICA_Y * 0.25, 0,
                      "2. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[1].nom, puntuacio[posicio].c[1].temps_carrera,
                      puntuacio[posicio].c[1].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(RED), GRAFICA_X * 0.05, GRAFICA_Y * 0.3, 0,
                      "3. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[2].nom, puntuacio[posicio].c[2].temps_carrera,
                      puntuacio[posicio].c[2].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.35, 0,
                      "4. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[3].nom, puntuacio[posicio].c[3].temps_carrera,
                      puntuacio[posicio].c[3].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.4, 0,
                      "5. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[4].nom, puntuacio[posicio].c[4].temps_carrera,
                      puntuacio[posicio].c[4].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.45, 0,
                      "6. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[5].nom, puntuacio[posicio].c[5].temps_carrera,
                      puntuacio[posicio].c[5].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.5, 0,
                      "7. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[6].nom, puntuacio[posicio].c[6].temps_carrera,
                      puntuacio[posicio].c[6].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.55, 0,
                      "8. %s ( %d S) - %d PUNTS", puntuacio[posicio].c[7].nom, puntuacio[posicio].c[7].temps_carrera,
                      puntuacio[posicio].c[7].punts);

        //Opcion de salida
        /*************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            exit = 1;
        }
        /*************************************************/

        //Control de direcciones
        /*************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
            if (posicio == 0) {
            } else {
                posicio--;
            }
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
            if (num_carrera == 5 && posicio == 3) {
                posicio = mostrarGeneral(general, posicio);
                if (posicio == 10) {
                    exit = 1;
                }
            } else {
                if (posicio >= (num_carrera - 2)) {
                } else {
                    posicio++;
                }
            }
        }
        /***************************************************/
    }
}

int mostrarGeneral(General *general, int posicio) {

    LS_allegro_console_clear_screen();
    while (!LS_allegro_key_pressed(ALLEGRO_KEY_LEFT) || !LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
        LS_allegro_clear_and_paint(BLACK);

        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.025, GRAFICA_Y * 0.1, 0,
                      "CLASSIFICACIO FINAL DE LA TEMPORADA");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.05, GRAFICA_Y * 0.2, 0,
                      "1. %s (#%d) - %d PUNTS", general[0].nom, general[0].dorsal,
                      general[0].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(GRAY), GRAFICA_X * 0.05, GRAFICA_Y * 0.25, 0,
                      "2. %s (#%d) - %d PUNTS", general[1].nom, general[1].dorsal,
                      general[1].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(RED), GRAFICA_X * 0.05, GRAFICA_Y * 0.3, 0,
                      "3. %s (#%d) - %d PUNTS", general[2].nom, general[2].dorsal,
                      general[2].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.35, 0,
                      "4. %s (#%d) - %d PUNTS", general[3].nom, general[3].dorsal,
                      general[3].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.4, 0,
                      "5. %s (#%d) - %d PUNTS", general[4].nom, general[4].dorsal,
                      general[4].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.45, 0,
                      "6. %s (#%d) - %d PUNTS", general[5].nom, general[5].dorsal,
                      general[0].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.5, 0,
                      "7. %s (#%d) - %d PUNTS", general[6].nom, general[6].dorsal,
                      general[6].punts);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.05, GRAFICA_Y * 0.55, 0,
                      "8. %s (#%d) - %d PUNTS", general[7].nom, general[7].dorsal,
                      general[7].punts);

        //Opcion de salir
        /*****************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            return 10;
        }
        /****************************************************/

        //Control de direccion para regresar
        /****************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
            return posicio;
        }
        /****************************************************/
    }
}

General INICIALIZAR_general(General *general, Pilotos pilots, Usuario usuario) {
    int i = 0;

    //Inicializamos la estructura general con los
    //nombres de los pilotos, sus dorsales y puntos a 0
    /*********************************************/
    while (i < NUM_PILOTOS) {
        strcpy(general[i].nom, pilots.c[i].nombre);
        general[i].punts = 0;
        general[i].dorsal = pilots.c[i].dorsal;
        i++;
    }
    strcpy(general[7].nom, usuario.nombre);
    general[7].punts = 0;
    general[7].dorsal = usuario.dorsal;
    /*********************************************/
    return *general;
}

General ACTUALIZAR_classificacio(General *general, classificacion *puntuacio) {
    int i, j;
    General aux;

    i = 0;
    j = 0;
    //Actualizamos la classificacion general despues de cada carrera
    /****************************************************************/
    while (i < 8) {
        j = 0;
        while (j < 8) {
            if (strcmp(general[i].nom, puntuacio[j].nom) == 0) {
                general[i].punts = general[i].punts + puntuacio[j].punts;
            }
            j++;
        }
        i++;
    }
    /***************************************************************/

    //Aplicamos el metodo de selecion para ordenar la general
    //despues de actualizar sus puntos
    /**************************************************************/
    i = 0;
    while (i < 8) {
        j = i + 1;
        while (j < 8) {
            if (general[j].punts > general[i].punts) {
                aux = general[i];
                general[i] = general[j];
                general[j] = aux;
            }
            j++;
        }
        i++;
    }
    /*****************************************************************/
    return *general;
}

void CLASSIFICACION_guardarLog(General *general, c *puntuacio) {
    int i, j;
    FILE *out;

    out = fopen("../ficheros/log_temporada.txt", "w");
    i = j = 0;

    //Escritura de cada gran premio
    /*******************************************************************/
    while (i < 4) {
        fprintf(out, "Classificacio del %s\n", puntuacio[i].nombre_circuito);
        j = 0;
        while (j < 8) {
            fprintf(out, "%d. %s amb %d segons. Punts: %d\n", j + 1, puntuacio[i].c[j].nom,
                    puntuacio[i].c[j].temps_carrera, puntuacio[i].c[j].punts);
            j++;
        }
        i++;
    }
    /*******************************************************************/

    //Escritura de la classificacion final
    /******************************************************************/
    fprintf(out, "Classificacio final de la temporada\n");
    j = 0;
    while (j < 8) {
        fprintf(out, "%d. %s (#%d) Punts: %d\n", j + 1, general[j].nom, general[j].dorsal, general[j].punts);
        j++;
    }
    /********************************************************************/
    fclose(out);
    printf("\nDocumento generado en la carpeta ../ficheros/log_temporada.txt\n");
}