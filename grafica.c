/***************************************
 *
 * Modulo: Gráfica
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "grafica.h"

int timer(int segons) {
    float time1, time0;
    int cops = 0;
    // Capturem el temps inicial t0
    time0 = (float) clock();
    while (cops < (segons * 2)) {
        // Capturem el temps final t1
        time1 = (float) clock();
        // Calculem la diferència de temps i transformem a secs
        if ((time1 - time0) / (float) CLOCKS_PER_SEC >= 0.5) {
            //printf(“Ha passat mig segon!\n”);
            cops++;
            // Si ha passat mig segon, restablim temps inicial t0
            time0 = (float) clock();
        }
    }
    return 1;
}

void CONFIGURACIO_inicial(Configuracio *conf) {
    int i = 0;

    //Inicializamos la configuracio a 0 de todas las categorias
    while (i < NUM_PIEZAS) {
        conf[i].opcio = 0;
        i++;
    }
}

void GRAFICA_drawArrow(float x, float y) {
    al_draw_filled_rectangle(x, y, x + SQUARE, y + SQUARE, LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(x - SQUARE / 2, y, x + SQUARE + SQUARE / 2, y, x + SQUARE / 2, y - SQUARE / 2,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(x, y + 70, x + SQUARE, y + 70 + SQUARE, LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(x - SQUARE / 2, y + 70 + SQUARE, x + SQUARE + SQUARE / 2, y + 70 + SQUARE, x + SQUARE / 2,
                            y + 100, LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(x - 10, y + 40, x - SQUARE - 10, y + SQUARE + 40, LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(x - 40, y + 49, x + SQUARE - 50, y + SQUARE + 6, x + SQUARE - 50, y + 75,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(x + 60, y + 40, x - SQUARE + 60, y + SQUARE + 40, LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(x - SQUARE + 92, y + SQUARE + 30, x + SQUARE + 40, y + SQUARE + 6, x + SQUARE + 40, y + 75,
                            LS_allegro_get_color(WHITE));
}

void GRAFICA_menuArrows(float x, float y) {

    GRAFICA_drawArrow(x - RADIO / 2, y - RADIO - SQUARE - 5);
}

void GRAFICA_pintarBox(cotxe c) {
    ALLEGRO_BITMAP *img1, *img2;

    img1 = al_load_bitmap("../img/boxes.png");
    img2 = al_load_bitmap("../img/rdb.png");
    al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1), 0, 0, GRAFICA_X * 0.6,
                          GRAFICA_Y, 0);
    al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2) * 2, al_get_bitmap_height(img2) * 4, GRAFICA_X * 0.3, 0,
                          GRAFICA_X * 0.6,
                          GRAFICA_Y, 0);
    GRAFICA_menuArrows((GRAFICA_X * 0.6) + (GRAFICA_X * 0.4 * 0.25), GRAFICA_Y * 0.20);
    LS_allegro_clear_and_paint(BLACK);
}

void GRAFICA_confActual(cotxe c, Configuracio *conf) {
    int i = 0;

    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.7, 0,
                  "CONFIGURACION ACTUAL");
    while (i < 6) {
        if (i == 0) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.73,
                          0, "NEUMATICOS: %s", c.neumatics[conf[i].opcio].compost);
        }
        if (i == 1) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.76,
                          0, "AERO FRONTAL: %s", c.aero.frontal[conf[i].opcio].compost);
        }
        if (i == 2) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.79,
                          0, "AERO ZONA MEDIA: %s", c.aero.mitj[conf[i].opcio].compost);
        }
        if (i == 3) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.82,
                          0, "AERO POSTERIOR: %s", c.aero.posterior[conf[i].opcio].compost);
        }
        if (i == 4) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.85,
                          0, "GASOLINA: %s", c.gasolina[conf[i].opcio].compost);
        }
        if (i == 5) {
            al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.61, GRAFICA_Y * 0.88,
                          0, "MOTOR: %s", c.motor[conf[i].opcio].compost);
        }
        i++;
    }
}

void GRAFICA_aeroFrontal(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img1;

    img1 = al_load_bitmap("../img/aleron.png");
    al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "AERO FRONTAL");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.aero.frontal[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.aero.frontal[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.aero.frontal[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.aero.frontal[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.aero.frontal[opcio].fiabilitat);
}

void GRAFICA_aeroMitj(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img1;

    img1 = al_load_bitmap("../img/mitj.png");
    al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "AERO ZONA MEDIA");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.aero.mitj[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.aero.mitj[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.aero.mitj[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.aero.mitj[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.aero.mitj[opcio].fiabilitat);
}

void GRAFICA_aeroPosterior(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img1;

    img1 = al_load_bitmap("../img/aleron.png");
    al_draw_scaled_bitmap(img1, 0, 0, al_get_bitmap_width(img1), al_get_bitmap_height(img1),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "AERO POSTERIOR");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.aero.posterior[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.aero.posterior[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.aero.posterior[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.aero.posterior[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.aero.posterior[opcio].fiabilitat);
}

void GRAFICA_gasolina(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img2;

    img2 = al_load_bitmap("../img/gasolina.png");
    al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2), al_get_bitmap_height(img2),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "GASOLINA");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.gasolina[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.gasolina[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.gasolina[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.gasolina[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.gasolina[opcio].fiabilitat);
}

void GRAFICA_motor(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img2;

    img2 = al_load_bitmap("../img/motor.png");
    al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2), al_get_bitmap_height(img2),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "MOTOR");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.motor[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.motor[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.motor[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.motor[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.motor[opcio].fiabilitat);
}

void GRAFICA_neumaticos(cotxe c, int opcio) {
    ALLEGRO_BITMAP *img2;

    img2 = al_load_bitmap("../img/neumaticos.png");
    al_draw_scaled_bitmap(img2, 0, 0, al_get_bitmap_width(img2), al_get_bitmap_height(img2),
                          GRAFICA_X * 0.6 + GRAFICA_X * 0.4 * 0.2, GRAFICA_Y * 0.17, RADIO * 2, RADIO * 2, 0);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.7, GRAFICA_Y * 0.025, 0,
                  "NEUMATICOS");
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.13, 0, "%s",
                  c.neumatics[opcio].compost);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.16, 0,
                  "VELOCITAT: %d", c.neumatics[opcio].velocitat);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.19, 0,
                  "ACCELERACIO: %d", c.neumatics[opcio].acceleracio);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.22, 0,
                  "CONSUM: %d", c.neumatics[opcio].consum);
    al_draw_textf(LS_allegro_get_font(SMALL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.82, GRAFICA_Y * 0.25, 0,
                  "FIABILITAT: %d", c.neumatics[opcio].fiabilitat);
}

int GRAFICA_escogerPieza(cotxe c, Configuracio *conf) {
    int pieza, opcion, exit, tecla;

    pieza = opcion = tecla = 0;
    GRAFICA_neumaticos(c, opcion);
    GRAFICA_confActual(c, conf);
    GRAFICA_pintarBox(c);
    exit = 0;

    while (!exit) {

        //Esperamos a que el usuario pulse una tecla
        /*******************************************************/
        while (!tecla) {
            LS_allegro_console_fflush();

            if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
                opcion++;
                tecla = 1;
                LS_allegro_console_clear_screen();
            }
            if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
                opcion--;
                tecla = 1;
                LS_allegro_console_clear_screen();
            }
            if (LS_allegro_key_pressed(ALLEGRO_KEY_UP)) {
                pieza--;
                tecla = 1;
                LS_allegro_console_clear_screen();
            }
            if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)) {
                pieza++;
                tecla = 1;
                LS_allegro_console_clear_screen();
            }
            if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
                LS_allegro_console_clear_screen();
                exit = 1;
                tecla = 1;
            }

        }
        /****************************************************/


        //Control de errores
        /******************************/
        if (pieza <= -1 && exit == 0) {
            pieza = 5;
        }
        if (pieza >= 6 && exit == 0) {
            pieza = 0;
        }
        /******************************/

        if (pieza == 0 && exit == 0) {
            if (opcion < 0) {
                opcion = c.num_neumatics - 1;
            }
            if (opcion >= c.num_neumatics) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_neumaticos(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);
        }
        if (pieza == 1 && exit == 0) {
            if (opcion < 0) {
                opcion = c.aero.num_frontal - 1;
            }
            if (opcion >= c.aero.num_frontal) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_aeroFrontal(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);

        }
        if (pieza == 2 && exit == 0) {
            if (opcion < 0) {
                opcion = c.aero.num_mitj - 1;
            }
            if (opcion >= c.aero.num_mitj) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_aeroMitj(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);
        }
        if (pieza == 3 && exit == 0) {
            if (opcion < 0) {
                opcion = c.aero.num_posterior - 1;
            }
            if (opcion >= c.aero.num_posterior) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_aeroPosterior(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);
        }
        if (pieza == 4 && exit == 0) {
            if (opcion < 0) {
                opcion = c.num_gasolina - 1;
            }
            if (opcion >= c.num_gasolina) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_gasolina(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);
        }
        if (pieza == 5 && exit == 0) {
            if (opcion < 0) {
                opcion = c.num_motor - 1;
            }
            if (opcion >= c.num_motor) {
                opcion = 0;
            }
            GRAFICA_pintarBox(c);
            GRAFICA_motor(c, opcion);
            conf[pieza].opcio = opcion;
            GRAFICA_confActual(c, conf);
        }
        if (!exit) {
            GRAFICA_pintarBox(c);
        }
        tecla = 0;
    }
    LS_allegro_exit();
    return 1;
}

void GRAFICA_pintarCarrera(Usuario usuario, int num_parades, int temps, Pilotos *p, int paradas_hechas) {
    int i;

    al_draw_line(GRAFICA_X * 0.7, 0, GRAFICA_X * 0.7, GRAFICA_Y * 0.9, LS_allegro_get_color(WHITE), 1);
    al_draw_line(0, GRAFICA_Y * 0.9, GRAFICA_X * 0.7, GRAFICA_Y * 0.9, LS_allegro_get_color(WHITE), 1);
    al_draw_filled_rectangle(0, 0, GRAFICA_X * 0.7, GRAFICA_Y * 0.9, LS_allegro_get_color(WHITE));
    //INFERIOR DE LA CARRERA
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.02, GRAFICA_Y * 0.94, 0,
                  "RADIO (R)");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.53, GRAFICA_Y * 0.94, 0,
                  "PIT BOX (P)");
    //PANEL DE LA DERECHA
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.72, GRAFICA_Y * 0.05, 0,
                  "PILOT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.12, 0,
                  "NOM");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.17, 0,
                  "%s", usuario.nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.22, 0,
                  "ESCUDERIA");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.27, 0,
                  "%s", usuario.escuderia);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.32, 0,
                  "DORSAL");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.37, 0,
                  "%d", usuario.dorsal);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.72, GRAFICA_Y * 0.42, 0,
                  "COTXE");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.49, 0,
                  "VELOCITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.54, 0,
                  "%d", usuario.cotxe_velocitat);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.59, 0,
                  "ACCELERACIO");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.64, 0,
                  "%d", usuario.cotxe_acceleracio);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.69, 0,
                  "CONSUM");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.74, 0,
                  "%d", usuario.cotxe_consum);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), GRAFICA_X * 0.73, GRAFICA_Y * 0.79, 0,
                  "FIABILITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), GRAFICA_X * 0.75, GRAFICA_Y * 0.84, 0,
                  "%d", usuario.cotxe_fiabilitat);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.9, GRAFICA_Y * 0.85, 0,
                  "%d", temps);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.72, GRAFICA_Y * 0.93, 0,
                  "STOP: %d/%d", paradas_hechas, num_parades);
    //DORSALES
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), GRAFICA_X * 0.7 * 0.04,
                  GRAFICA_Y * 0.9 * 0.095, 0, "%d", usuario.dorsal);

    for (i = 0; i < 8; i++) {
        //LINEA
        al_draw_line((GRAFICA_X * 0.7) * 0.1, ((GRAFICA_Y * 0.9) * 0.1) * (i + 1),
                     GRAFICA_X * 0.7 - (GRAFICA_X * 0.7) * 0.1, ((GRAFICA_Y * 0.9) * 0.1) * (i + 1),
                     LS_allegro_get_color(BLACK), 1);
        //DORSALES
        if (i < 7) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), GRAFICA_X * 0.7 * 0.04,
                          GRAFICA_Y * 0.9 * 0.095 * (i + 2.1), 0, "%d", p->c[i].dorsal);
        }
    }
}

void CALCULAR_temps(Pilotos *p, Gp carrera, classificacion *classificacion1) {
    int i;

    //Calculamos el tiempo de cada piloto de la IA
    for (i = 0; i < 7; ++i) {
        classificacion1[i].temps_carrera = carrera.tiempo_base * 60 + (carrera.velocitat - p->c[i].velocidad) +
                                           (carrera.acceleracio - p->c[i].aceleracion) +
                                           (carrera.consum - p->c[i].consumo) +
                                           (carrera.fiabilitat - p->c[i].fiabilidad);
        classificacion1[i].num_parades = carrera.num_pit_stop;
        if (p->c[i].consumo < carrera.consum) {
            classificacion1[i].num_parades = carrera.num_pit_stop - 1;
            classificacion1[i].temps_carrera =
                    classificacion1[i].temps_carrera + classificacion1[i].num_parades * carrera.tiempo_pit_stop;
        }
        if (p->c[i].consumo > carrera.consum) {
            classificacion1[i].num_parades = carrera.num_pit_stop + 1;
            classificacion1[i].temps_carrera =
                    classificacion1[i].temps_carrera + classificacion1[i].num_parades * carrera.tiempo_pit_stop;
        } else {
            classificacion1[i].temps_carrera =
                    classificacion1[i].temps_carrera + classificacion1[i].num_parades * carrera.tiempo_pit_stop;
        }
        classificacion1[i].temps_carrera = classificacion1[i].temps_carrera -
                                           ((p->c[i].reflejos + p->c[i].condicion_fisica + p->c[i].temperamento +
                                             p->c[i].gestion_neumaticos) / 4) / 2;
        classificacion1[i].xcirculo = LINEA / classificacion1[i].temps_carrera;
        classificacion1[i].velocitat = GRAFICA_X * 0.7 * 0.1 + classificacion1[i].xcirculo;
    }
}

classificacion GRAFICA_carrera(Usuario usuario, Gp carrera, Pilotos *p, classificacion *classificacion1) {
    int exit = 0, i, j;
    int xcirculo, velocitat;
    int temps = 0, radio = 0, contador_pit_box = 0, temps_carrera;
    int paradas_hechas = 0, num_parades;
    ALLEGRO_BITMAP *piloto;


    piloto = al_load_bitmap("../img/cotxe.png");
    LS_allegro_console_clear_screen();
    LS_allegro_clear_and_paint(BLACK);

    //Hacemos los calculos pertinentes al usuario
    /**************************************************************/
    temps_carrera = carrera.tiempo_base * 60 + (carrera.velocitat - usuario.cotxe_velocitat) +
                    (carrera.acceleracio - usuario.cotxe_acceleracio) + (carrera.consum - usuario.cotxe_consum) +
                    (carrera.fiabilitat - usuario.cotxe_fiabilitat);
    num_parades = carrera.num_pit_stop;
    if (usuario.cotxe_consum < carrera.consum) {
        num_parades = carrera.num_pit_stop - 1;
        temps_carrera = temps_carrera + num_parades * carrera.tiempo_pit_stop;
    }
    if (usuario.cotxe_consum > carrera.consum) {
        num_parades = carrera.num_pit_stop + 1;
        temps_carrera = temps_carrera + num_parades * carrera.tiempo_pit_stop;
    } else {
        temps_carrera = temps_carrera + num_parades * carrera.tiempo_pit_stop;
    }
    temps_carrera = temps_carrera -
                    ((usuario.reflejos + usuario.condicion_fisica + usuario.temperamento + usuario.gestion_neumaticos) /
                     4) / 2;
    xcirculo = LINEA / temps_carrera;
    CALCULAR_temps(p, carrera, classificacion1);
    velocitat = GRAFICA_X * 0.7 * 0.1 + xcirculo;
    /********************************************************************/

    while (!exit) {
        LS_allegro_console_clear_screen();
        GRAFICA_pintarCarrera(usuario, num_parades, temps, p, paradas_hechas);
        //Usuario
        //Avanzar el coche
        /***********************************************************/
        if (velocitat < LINEA) {
            al_draw_scaled_bitmap(piloto, 0, 0, al_get_bitmap_width(piloto), al_get_bitmap_height(piloto),
                                  velocitat,
                                  ((GRAFICA_Y * 0.9) * 0.1) - al_get_bitmap_height(piloto) / 2,
                                  al_get_bitmap_width(piloto),
                                  al_get_bitmap_height(piloto), 0);
            velocitat = velocitat + xcirculo;
        } else {
            al_draw_scaled_bitmap(piloto, 0, 0, al_get_bitmap_width(piloto), al_get_bitmap_height(piloto),
                                  velocitat,
                                  ((GRAFICA_Y * 0.9) * 0.1) - al_get_bitmap_height(piloto) / 2,
                                  al_get_bitmap_width(piloto),
                                  al_get_bitmap_height(piloto), 0);
        }
        /***************************************************************/

        //Corredores
        //Avanzar los coches
        /******************************************************************/
        for (i = 0; i < 7; i++) {
            if (classificacion1[i].velocitat < LINEA) {
                al_draw_scaled_bitmap(piloto, 0, 0, al_get_bitmap_width(piloto), al_get_bitmap_height(piloto),
                                      classificacion1[i].velocitat,
                                      ((GRAFICA_Y * 0.9) * 0.1) * (i + 2) - al_get_bitmap_height(piloto) / 2,
                                      al_get_bitmap_width(piloto),
                                      al_get_bitmap_height(piloto), 0);
                classificacion1[i].velocitat = classificacion1[i].velocitat + classificacion1[i].xcirculo;
            } else {
                al_draw_scaled_bitmap(piloto, 0, 0, al_get_bitmap_width(piloto), al_get_bitmap_height(piloto),
                                      classificacion1[i].velocitat,
                                      ((GRAFICA_Y * 0.9) * 0.1) * (i + 2) - al_get_bitmap_height(piloto) / 2,
                                      al_get_bitmap_width(piloto),
                                      al_get_bitmap_height(piloto), 0);
            }
        }
        /*******************************************************************/

        //CLOCK de la carrera
        temps += timer(1);

        //Control del pit-box
        /*********************************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            radio = 1;
        }
        if (contador_pit_box >= 1 || LS_allegro_key_pressed(ALLEGRO_KEY_P)) {
            if (radio == 1) {
                xcirculo = 0;
                if (contador_pit_box < carrera.tiempo_pit_stop) {
                    contador_pit_box++;
                    velocitat = velocitat;
                } else {
                    contador_pit_box = 0;
                    radio = 0;
                    xcirculo = LINEA / temps_carrera;
                    if (paradas_hechas < num_parades) {
                        paradas_hechas++;
                    }
                }
            } else {
                xcirculo = 0;
                if (contador_pit_box < carrera.tiempo_pit_stop) {
                    contador_pit_box++;
                    velocitat = velocitat;
                } else {
                    contador_pit_box = 0;
                    radio = 0;
                    xcirculo = LINEA / temps_carrera;
                }
            }
        }
        /********************************************************************/
        LS_allegro_clear_and_paint(BLACK);

        //Control del final
        /********************************************************************/
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE) || temps > temps_carrera) {
            exit = 1;
        }
        /********************************************************************/
    }
    exit = 0;

    //Aplicamos si existe penalizacion
    /*************************************************************************/
    if (paradas_hechas != num_parades) {
        temps_carrera = temps_carrera + (carrera.tiempo_pit_stop * 5);
    }
    /**************************************************************************/

    classificacion1[7].temps_carrera = temps_carrera;

    //Buscamos el ganador con menor tiempo de carrera
    /**************************************************************************/
    i = 0;
    j = 0;
    LS_allegro_console_fflush();
    while (i < 8) {
        if (classificacion1[i].temps_carrera < classificacion1[j].temps_carrera) {
            j = i;
        }
        i++;
    }
    /***************************************************************************/

    while (!exit) {
        LS_allegro_clear_and_paint(BLACK);
        if (j < 7) {
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.1, GRAFICA_Y * 0.4, 0,
                          "%s HA FINALITZAT", p->c[j].nombre);
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.45, 0,
                          "EN LA POSICIO 1");
        } else {
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.1, GRAFICA_Y * 0.4, 0,
                          "%s HA FINALITZAT ", usuario.nombre);
            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.45, 0,
                          "EN LA POSICIO 1");
        }
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.1, GRAFICA_Y * 0.85, 0,
                      "PULSA ENTER PER TORNAR AL MENU");
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)) {
            exit = 1;
        }
    }
    strcpy(classificacion1[0].nom, p->c[0].nombre);
    strcpy(classificacion1[1].nom, p->c[1].nombre);
    strcpy(classificacion1[2].nom, p->c[2].nombre);
    strcpy(classificacion1[3].nom, p->c[3].nombre);
    strcpy(classificacion1[4].nom, p->c[4].nombre);
    strcpy(classificacion1[5].nom, p->c[5].nombre);
    strcpy(classificacion1[6].nom, p->c[6].nombre);
    strcpy(classificacion1[7].nom, usuario.nombre);
    return *classificacion1;
}

classificacion GRAFICA_semaforo(Gp circuito, Usuario u, Pilotos *p, classificacion *puntuacio) {
    int nSortir = 0;
    float time1, time0;

    time0 = (float) clock();

    //Introduccion a la carrera
    /**********************/
    while (!nSortir) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            nSortir = 1;
        }
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.15, GRAFICA_Y * 0.3, 0,
                      "Benvingut al %s", circuito.nom);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.4, 0,
                      "Velocitat: %d", circuito.velocitat);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.45, 0,
                      "Acceleracio: %d", circuito.acceleracio);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.50, 0,
                      "Consum: %d", circuito.consum);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.3, GRAFICA_Y * 0.55, 0,
                      "Fiabilitat: %d", circuito.fiabilitat);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), GRAFICA_X * 0.03, GRAFICA_Y * 0.7, 0,
                      "PULSA LA R PER COMENCAR LA CARRERA");
        LS_allegro_clear_and_paint(BLACK);
    }
    /*********************/

    LS_allegro_clear_and_paint(WHITE);

    //Primer semáforo
    /**********************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 1.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /**********************/

    //Segundo semáforo
    /***********************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 1.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /**********************/

    //Tercer semaforo
    /************************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 1.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /***********************/

    //Cuarto semáforo
    /***********************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 1.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /**********************/

    //Quinto semáforo
    /***********************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 1.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /************************/

    //Todos encendidos por 2 segundos
    /************************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 2.0) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(RED));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(RED));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /***********************/

    //Preparacion para la salida
    /**************************/
    time0 = (float) clock();
    while ((time1 - time0) / (float) CLOCKS_PER_SEC < 0.5) {
        al_draw_filled_rectangle(GRAFICA_X * 0.15, GRAFICA_Y * 0.2, GRAFICA_X * 0.25, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.2, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.3, GRAFICA_Y * 0.2, GRAFICA_X * 0.4, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.35, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.45, GRAFICA_Y * 0.2, GRAFICA_X * 0.55, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.5, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.6, GRAFICA_Y * 0.2, GRAFICA_X * 0.7, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.65, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(GRAFICA_X * 0.75, GRAFICA_Y * 0.2, GRAFICA_X * 0.85, GRAFICA_Y * 0.8,
                                 LS_allegro_get_color(BLACK));

        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.33, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.45, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.57, 25, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(GRAFICA_X * 0.8, GRAFICA_Y * 0.69, 25, LS_allegro_get_color(GRAY));

        LS_allegro_clear_and_paint(WHITE);
        time1 = (float) clock();
    }
    /**************************/

    *puntuacio = GRAFICA_carrera(u, circuito, p, puntuacio);
    return *puntuacio;
}

Usuario ACTUALITZAR_cotxe(Usuario u, Configuracio *conf, cotxe cotxe) {

    u.cotxe_velocitat = cotxe.neumatics[conf[0].opcio].velocitat + cotxe.aero.frontal[conf[1].opcio].velocitat +
                        cotxe.aero.mitj[conf[2].opcio].velocitat + cotxe.aero.posterior[conf[3].opcio].velocitat +
                        cotxe.gasolina[conf[4].opcio].velocitat + cotxe.motor[conf[5].opcio].velocitat;
    u.cotxe_acceleracio = cotxe.neumatics[conf[0].opcio].acceleracio + cotxe.aero.frontal[conf[1].opcio].acceleracio +
                          cotxe.aero.mitj[conf[2].opcio].acceleracio + cotxe.aero.posterior[conf[3].opcio].acceleracio +
                          cotxe.gasolina[conf[4].opcio].acceleracio + cotxe.motor[conf[5].opcio].acceleracio;
    u.cotxe_consum = cotxe.neumatics[conf[0].opcio].consum + cotxe.aero.frontal[conf[1].opcio].consum +
                     cotxe.aero.mitj[conf[2].opcio].consum + cotxe.aero.posterior[conf[3].opcio].consum +
                     cotxe.gasolina[conf[4].opcio].consum + cotxe.motor[conf[5].opcio].consum;
    u.cotxe_fiabilitat = cotxe.neumatics[conf[0].opcio].fiabilitat + cotxe.aero.frontal[conf[1].opcio].fiabilitat +
                         cotxe.aero.mitj[conf[2].opcio].fiabilitat + cotxe.aero.posterior[conf[3].opcio].fiabilitat +
                         cotxe.gasolina[conf[4].opcio].fiabilitat + cotxe.motor[conf[5].opcio].fiabilitat;
    return u;
}