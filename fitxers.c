/***************************************
 *
 * Modulo: Ficheros
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "fitxers.h"

void llegirBase(FILE *fitxer, Base *b) {

    //Lectura del fichero base
    /*********************************/
    fread(&b, sizeof(Base), 1, fitxer);
    /*********************************/
}

void llegirCorredors(FILE *fitxer, Pilotos *p) {
    int i = 0;

    //Creamos un array dinamico para pilotos segun el numero de corredores de la IA
    /***************************************************/
    p->c = (corredores *) malloc(sizeof(corredores) * NUM_PILOTOS);
    /***************************************************/


    //Lecuta del fichero corredores
    /****************************************************/
    while (i < NUM_PILOTOS) {
        fread(&p->c[i], sizeof(corredores), 1, fitxer);
        i++;
    }
    /*****************************************************/
}

void llegirGP(FILE *gps, ListaOrd *l) {
    int num, i, total, j;
    float tiempo;
    char aux[MAX];
    Gp campeonato;

    //Lectura del total de carrera
    /****************************************/
    fgets(aux, MAX, gps); //4
    total = i = 0;
    while (aux[i] != '\n') {
        if (aux[i] >= '0' && aux[i] <= '9') {
            total = total * 10 + aux[i] - '0';
        }
        i++;
    }
    l->total = total;
    /****************************************/

    j = 0;
    while (j < total) {
        //Posicion de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.posicion = num;

        //Nombre del Gran Premio
        fgets(aux, MAX, gps);
        strcpy(campeonato.nom, aux);
        campeonato.nom[strlen(campeonato.nom) - 1] = '\0';

        //Velocidad de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.velocitat = num;

        //Acceleracion de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.acceleracio = num;

        //Consumo de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.consum = num;

        //Fiabilidad de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.fiabilitat = num;

        //Tiempo base de la carrera
        fscanf(gps, "%f", &tiempo);
        fgets(aux, MAX, gps);
        campeonato.tiempo_base = tiempo;

        //Tiempo pit-stop de la carrera
        fgets(aux, MAX, gps); //7
        num = i = 0;
        while (aux[i] != '\n') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.tiempo_pit_stop = num;

        //Numero de pit stops de la carrera
        fgets(aux, MAX, gps);
        num = i = 0;
        while (aux[i] != '\n' && aux[i] != '\0') {
            if (aux[i] >= '0' && aux[i] <= '9') {
                num = num * 10 + aux[i] - '0';
            }
            i++;
        }
        campeonato.num_pit_stop = num;

        //Inserim la carrera a la llista ordenada
        LISTAORD_insertaOrd(*l, campeonato);

        j++;
    }
}

void llegirPeces(FILE *peces, cotxe *cotxe) {
    int num, i, j, z;
    char aux[MAX];

    //Numero de piezas
    fgets(aux, MAX, peces);

    //Categoria 1: Neumaticos
    fgets(aux, MAX, peces);

    //Numero de piezas en la categoria
    fgets(aux, MAX, peces); //7
    num = i = 0;
    while (aux[i] != '\n') {
        if (aux[i] >= '0' && aux[i] <= '9') {
            num = num * 10 + aux[i] - '0';
        }
        i++;
    }

    //Creamos memoria necesaria para el numero de piezas
    cotxe->neumatics = (neumatics *) malloc(sizeof(neumatics) * num);
    cotxe->num_neumatics = num;
    i = 0;
    while (i < num) {

        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->neumatics[i].compost, aux);
        cotxe->neumatics[i].compost[strlen(cotxe->neumatics[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->neumatics[i].velocitat = z;

        //Aceleracion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->neumatics[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->neumatics[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->neumatics[i].fiabilitat = z;
        i++;
    }

    //Categoria 2: Aero frontal
    fgets(aux, MAX, peces); //Aero frontal

    //Numero de piezas
    fgets(aux, MAX, peces); // 3
    num = 0;
    i = 0;
    while (aux[i] != '\n') {
        if (aux[i] >= '0' && aux[i] <= '9') {
            num = num * 10 + aux[i] - '0';
        }
        i++;
    }

    //Creamos memoria por el numero de piezas
    cotxe->aero.frontal = (zonaAero *) malloc(sizeof(zonaAero) * num);
    cotxe->aero.num_frontal = num;
    i = 0;
    while (i < num) {

        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->aero.frontal[i].compost, aux);
        cotxe->aero.frontal[i].compost[strlen(cotxe->aero.frontal[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.frontal[i].velocitat = z;

        //Aceleracion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.frontal[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.frontal[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.frontal[i].fiabilitat = z;
        i++;
    }

    //Gategoria 3: Aero Zona media
    fgets(aux, MAX, peces);

    //Numero de piezas
    fgets(aux, MAX, peces);
    num = i = 0;
    while (aux[i] != '\n') {
        if (aux[i] >= '0' && aux[i] <= '9') {
            num = num * 10 + aux[i] - '0';
        }
        i++;
    }

    //Creamos memoria por el numero de piezas
    cotxe->aero.mitj = (zonaAero *) malloc(sizeof(zonaAero) * num);
    cotxe->aero.num_mitj = num;

    i = 0;
    while (i < num) {
        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->aero.mitj[i].compost, aux);
        cotxe->aero.mitj[i].compost[strlen(cotxe->aero.mitj[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.mitj[i].velocitat = z;

        //Aceleracion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.mitj[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.mitj[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.mitj[i].fiabilitat = z;
        i++;
    }

    //Categoria 4: Aero posterior
    fgets(aux, MAX, peces);
    //Numero de piezas
    fgets(aux, MAX, peces);
    num = i = 0;
    while (aux[i] != '\n') {
        num = num * 10 + aux[i] - '0';
        i++;
    }

    //Creamos memoria segun el numero de piezas
    cotxe->aero.posterior = (zonaAero *) malloc(sizeof(zonaAero) * num);
    cotxe->aero.num_posterior = num;
    i = 0;
    while (i < num) {

        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->aero.posterior[i].compost, aux);
        cotxe->aero.posterior[i].compost[strlen(cotxe->aero.posterior[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.posterior[i].velocitat = z;

        //Acerelacion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.posterior[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.posterior[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->aero.posterior[i].fiabilitat = z;
        i++;
    }

    //Categoria 5: Gasolina
    fgets(aux, MAX, peces);

    //Numero de piezas
    fgets(aux, MAX, peces);
    num = i = 0;
    while (aux[i] != '\n') {
        num = num * 10 + aux[i] - '0';
        i++;
    }

    //Creamos memoria segun el numero de piezas
    cotxe->gasolina = (gasolina *) malloc(sizeof(gasolina) * num);
    cotxe->num_gasolina = num;

    i = 0;
    while (i < num) {
        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->gasolina[i].compost, aux);
        cotxe->gasolina[i].compost[strlen(cotxe->gasolina[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->gasolina[i].velocitat = z;

        //Aceleracion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->gasolina[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->gasolina[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->gasolina[i].fiabilitat = z;
        i++;
    }

    //Categoria 6: Motor
    fgets(aux, MAX, peces);

    //Numero de piezas
    fgets(aux, MAX, peces);
    num = i = 0;
    while (aux[i] != '\n') {
        num = num * 10 + aux[i] - '0';
        i++;
    }

    //Creamos memoria segun el numero de piezas
    cotxe->motor = (motor *) malloc(sizeof(motor) * num);
    cotxe->num_motor = num;

    i = 0;
    while (i < num) {
        //Compuesto
        fgets(aux, MAX, peces);
        strcpy(cotxe->motor[i].compost, aux);
        cotxe->motor[i].compost[strlen(cotxe->motor[i].compost) - 1] = '\0';

        //Velocidad
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = 0;
            j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->motor[i].velocitat = z;

        //Aceleracion
        fgets(aux, MAX, peces);
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            z = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            z = j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->motor[i].acceleracio = z;

        //Consumo
        fgets(aux, MAX, peces);
        z = 0;
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
            z = z * (-1);
        } else {
            j = 0;
            while (aux[j] != '\n') {
                z = z * 10 + aux[j] - '0';
                j++;
            }
        }
        cotxe->motor[i].consum = z;

        //Fiabilidad
        fgets(aux, MAX, peces);
        z = 0;
        if (aux[0] < '0' || aux[0] > '9') {
            j = 1;
            while (aux[j] != '\n') {
                if (aux[j] >= '0' && aux[j] <= '9') {
                    z = z * 10 + aux[j] - '0';
                }
                j++;
            }
            z = z * (-1);
        } else {
            j = 0;
            while (aux[j] != '\n') {
                if (aux[j] >= '0' && aux[j] <= '9') {
                    z = z * 10 + aux[j] - '0';
                }
                j++;
            }
        }
        cotxe->motor[i].fiabilitat = z;
        i++;
    }
}

int llegirFitxer(FILE *fitxer, cotxe *cotxe, ListaOrd *l, Pilotos *p, Base *b, int opcio) {

    //Comprobacion de errores
    /***********************************************/
    if (fitxer == NULL) {
        printf("ERROR: Ha ocurrido un error durante el procesamiento de los ficheros.\n");
        return 1;
    } else {
        if (feof(fitxer)) {
            printf("ERROR: Hay un fichero vacio\n");
            fclose(fitxer);
            return 1;
        }
    }
    /************************************************/

    switch (opcio) {
        case 1:
            llegirPeces(fitxer, cotxe);
            fclose(fitxer);
            break;
        case 2:
            llegirGP(fitxer, l);
            fclose(fitxer);
            break;
        case 3:
            llegirCorredors(fitxer, p);
            fclose(fitxer);
            break;
        case 4:
            llegirBase(fitxer, b);
            fclose(fitxer);
            break;
    }
    return 0;
}