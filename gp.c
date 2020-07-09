/***************************************
 *
 * Modulo: Grandes Premios
 * Autores: David Marquet / Joan Casals
 *
 **************************************/

#include "gp.h"

ListaOrd LISTAORD_crea() {
    ListaOrd l;

    l.pri = (Nodo *) malloc(sizeof(Nodo));
    if (l.pri == NULL) {
        printf("\nError al crear la lista...\n");
    } else {
        l.ant = l.pri;
        l.pri->sig = NULL;
        l.pri->elemento.velocitat = -1; // FANTASMA, ELEMENTO_indefinido();
    }

    return l;
}

ListaOrd LISTAORD_insertaOrd(ListaOrd l, Gp elemento) {
    Nodo *aux, *tmp;

    aux = (Nodo *) malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al insertar en la lista...\n");
    } else {
        aux->elemento = elemento;
        tmp = l.ant; // para conservar el PDI
        l.ant = l.pri; // movemos PDI al 1er elemento
        // buscamos el sitio donde insertar
        // opcion 1
        while (l.ant->sig != NULL && l.ant->sig->elemento.posicion < elemento.posicion) {
            l.ant = l.ant->sig;
        }
        // opcion 2
/*		fin = 0;
		while (fin == 0) {
			if (l.ant->sig!=NULL) {
				if (l.ant->sig->elemento < elemento) {
					l.ant = l.ant->sig;
				} else {
					fin = 1;
				}
			} else {
				fin = 1;
			}
		}
*/
        // insertamos
        aux->sig = l.ant->sig;
        l.ant->sig = aux;
        l.ant = tmp; // restauramos el PDI
    }
    return l;
}

ListaOrd LISTAORD_inserta(ListaOrd l, Gp elemento) {
    Nodo *aux;

    aux = (Nodo *) malloc(sizeof(Nodo));
    if (aux == NULL) {
        printf("\nError al insertar en la lista...\n");
    } else {
        aux->elemento = elemento;
        aux->sig = l.ant->sig;
        l.ant->sig = aux;
        l.ant = aux; // para mantener el PDI
    }
    return l;
}

ListaOrd LISTAORD_elimina(ListaOrd l) {
    Nodo *aux;

    if (l.ant->sig == NULL) {
        printf("\nError al eliminar, el PDI está al final...\n");
    } else {
        aux = l.ant->sig;
        l.ant->sig = aux->sig; // l.ant->sig->sig;
        free(aux);
    }
    return l;
}

Gp LISTAORD_consulta(ListaOrd l) {
    Gp elemento;
    if (l.ant->sig == NULL) {
        printf("\nError al consultar, el PDI está al final...\n");
    } else {
        elemento = l.ant->sig->elemento;
    }
    return elemento;
}

ListaOrd LISTAORD_avanza(ListaOrd l) {
    if (l.ant->sig == NULL) {
        printf("\nError al avanzar, el PDI está al final...\n");
    } else {
        l.ant = l.ant->sig;
    }
    return l;
}

ListaOrd LISTAORD_vesInicio(ListaOrd l) {
    l.ant = l.pri;
    return l;
}

int LISTAORD_final(ListaOrd l) {
    return l.ant->sig == NULL;
}

int LISTAORD_vacia(ListaOrd l) {
    return l.pri->sig == NULL;
}

ListaOrd LISTAORD_destruye(ListaOrd l) {
    Nodo *aux;

    while (l.pri != NULL) {
        aux = l.pri;
        l.pri = l.pri->sig;
        free(aux);
    }

/*

	l = LISTAORD_vesInicio(l);
	
	while (!LISTAORD_vacia(l)) {
		l = LISTAORD_elimina(l);
	}
	
	free(l.pri); // borramos el fantasma
	l.pri = l.ant = NULL;
*/
    return l;
}


