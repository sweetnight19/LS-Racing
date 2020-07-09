/***************************************
 *
 * Modulo: Usuario
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "usuario.h"

Usuario USUARIO_crearUsuario() {
    Usuario u;

    u.check = 0;
    return u;
}

Usuario USUARIO_pedirInformacion(Usuario u) {
    int aux;
    char cadena[MAX_CHAR];

    //Control si es la primera vez
    /*************************************/
    if (u.check == 0) {
        LS_allegro_console_fflush();

        //Nombre del piloto
        printf("\nNombre del piloto? ");
        fgets(u.nombre, MAX_CHAR, stdin);
        u.nombre[strlen(u.nombre) - 1] = '\0';

        //Nombre de la escuderia
        printf("\nNombre de la escuderia? ");
        fgets(u.escuderia, MAX_CHAR, stdin);
        u.escuderia[strlen(u.escuderia) - 1] = '\0';
        aux = 0;

        //Dorsal
        /*******************************************/
        while ((strlen(cadena) > 2) || (aux < 1 || aux > 99)) {
            printf("Dorsal ");
            scanf("%s", cadena);
            LS_allegro_console_fflush();
            if (strlen(cadena) == 1) {
                if (cadena[0] >= '0' && cadena[0] <= '9') {
                    aux = cadena[0] - '0';
                }
            }
            if (strlen(cadena) == 2) {
                aux = (cadena[0] - '0') * 10 + cadena[1] - '0';
            }
            if ((strlen(cadena) > 2) || (aux < 1 || aux > 99)) {
                printf("Error, el dorsal tiene que ser entre 1 y 99\n");
            }
        }
        u.dorsal = aux;
        /*******************************************/

        //Reflejos
        /*******************************************/
        aux = 100;
        while ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
            printf("Reflejos? ");
            scanf("%s", cadena);
            LS_allegro_console_fflush();
            if (strlen(cadena) == 1) {
                aux = cadena[0] - '0';
            }
            if (strlen(cadena) == 2) {
                aux = (cadena[0] - '0') * 10 + cadena[1] - '0';
            }
            if ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
                printf("Error, los reflejos tienen que ser entre 0 y 10\n");
            }
        }
        u.reflejos = aux;
        /*******************************************/

        //Condicion fisica
        /*******************************************/
        aux = 100;
        while ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
            printf("Condicion fisica? ");
            scanf("%s", cadena);
            LS_allegro_console_fflush();
            if (strlen(cadena) == 1) {
                aux = cadena[0] - '0';
            }
            if (strlen(cadena) == 2) {
                aux = (cadena[0] - '0') * 10 + cadena[1] - '0';
            }
            if ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
                printf("Error, la condicion fisica tiene que ser entre 0 y 10\n");
            }
        }
        u.condicion_fisica = aux;
        /*******************************************/

        //Temperamento
        /*******************************************/
        aux = 100;
        while ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
            printf("Temperamento? ");
            scanf("%s", cadena);
            LS_allegro_console_fflush();
            if (strlen(cadena) == 1) {
                aux = cadena[0] - '0';
            }
            if (strlen(cadena) == 2) {
                aux = (cadena[0] - '0') * 10 + cadena[1] - '0';
            }
            if ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
                printf("Error, el temperamento tiene que ser entre 0 y 10\n");
            }
        }
        u.temperamento = aux;
        /*******************************************/

        //Gestion de neumaticos
        /*******************************************/
        aux = 100;
        while ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
            printf("Gestion de neumaticos? ");
            scanf("%s", cadena);
            LS_allegro_console_fflush();
            if (strlen(cadena) == 1) {
                aux = cadena[0] - '0';
            }
            if (strlen(cadena) == 2) {
                aux = (cadena[0] - '0') * 10 + cadena[1] - '0';
            }
            if ((strlen(cadena) > 2) || (aux < 0 || aux > 10)) {
                printf("Error, la gestion de neumaticos tiene que ser entre 0 y 10\n");
            }
        }
        u.gestion_neumaticos = aux;
        /*******************************************/

        //Control de que se ha realizado ya
        u.check = 1;
    }
    /*************************************/

    return u;
}