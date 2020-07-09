#include "LS_allegro.h"

//Constants internes del mòdul
#define MAX_KEYS 226
#define MAX_COLORS 17
#define MAX_FONTS 4
#define MAX_ERRORS 10
#define FPS 100

//Variables internes del mòdul
static ALLEGRO_DISPLAY *pDisplay = NULL;
static ALLEGRO_EVENT_QUEUE *pEventQueue = NULL;
static ALLEGRO_COLOR aColors[MAX_COLORS];
static ALLEGRO_FONT *aFonts[MAX_FONTS];
static ALLEGRO_THREAD *pThread = NULL;
static ALLEGRO_MUTEX *pMutex = NULL;
static int aKeys[MAX_KEYS];
static char sFontPath[500];

//--------------------------------------------- PRIVADES ---------------------------------------------//

//Pre: Cap
//Post: Cap
static void *LS_allegro_worker(ALLEGRO_THREAD *thr, void *arg) {

    //Declarem variables
    ALLEGRO_EVENT event;

    while (!al_get_thread_should_stop(thr)) {

        //Blocked fins que arribi un event a la cua
        al_wait_for_event(pEventQueue, &event);

        //Processem segons el tipus d'event
        switch (event.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                exit(0);
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                al_lock_mutex(pMutex);
                aKeys[event.keyboard.keycode - 1] = 1;
                al_unlock_mutex(pMutex);
                break;
        }
    }
    return NULL;
}

//Pre: Width i Height marquen la mida de la finestra gràfica a crear. sName especifica el nom de la finestra gràfica (si val NULL el nom queda a càrrec del sistema operatiu)
//Post: Retorna 1 (CERT) si s'ha pogut crear la finestra gràfica correctament. Altrament, retorna 0 (FALS).
static int LS_allegro_init_display(int nAmplada, int nAltura, char *sNomFinestra) {
    //Provem de crear la finestra gràfica
    pDisplay = al_create_display(nAmplada, nAltura);
    if (pDisplay != NULL) {
        if (sNomFinestra != NULL) al_set_window_title(pDisplay, sNomFinestra);
        return 1;
    }
    return 0;
}

//Pre: La finestra gràfica ha d'estar inicialitzada correctament
//Post: Retorna 1 (CERT) si s'ha pogut crear la cua d'esdeveniments amb els seus events pertinents. Altrament, retorna 0 (FALS).
static int LS_allegro_init_event_queue() {
    pEventQueue = al_create_event_queue();
    if (pEventQueue != NULL) {
        al_register_event_source(pEventQueue, (void *) al_get_keyboard_event_source());
        al_register_event_source(pEventQueue, (void *) pDisplay);
        return 1;
    }
    return 0;
}

//Pre: Cap
//Post: Inicialitza la matriu de colors disponibles a l'API LS Allegro
static int LS_allegro_init_colors() {
    aColors[0] = al_map_rgb(0, 0, 0);
    aColors[1] = al_map_rgb(0, 0, 51);
    aColors[2] = al_map_rgb(21, 51, 0);
    aColors[3] = al_map_rgb(0, 176, 246);
    aColors[4] = al_map_rgb(255, 0, 0);
    aColors[5] = al_map_rgb(255, 153, 153);
    aColors[6] = al_map_rgb(255, 128, 0);
    aColors[7] = al_map_rgb(192, 192, 192);
    aColors[8] = al_map_rgb(128, 128, 128);
    aColors[9] = al_map_rgb(0, 0, 255);
    aColors[10] = al_map_rgb(51, 255, 51);
    aColors[11] = al_map_rgb(153, 204, 255);
    aColors[12] = al_map_rgb(153, 0, 0);
    aColors[13] = al_map_rgb(255, 204, 204);
    aColors[14] = al_map_rgb(255, 255, 0);
    aColors[15] = al_map_rgb(255, 255, 255);
    aColors[16] = al_map_rgb(0, 255, 0);
    return 1;
}

//Pre: Cap
//Post: Retorna 1 (CERT) si s'han pogut carregar les fonts des del fitxer font.ttf. Altrament, retorna 0 (FALS).
static int LS_allegro_init_fonts() {

    //Declarem variables
    int nCounter = 0;

    //Obtenim el directori on es troba l'executable per poder-hi buscar el fitxer font.ttf
    getcwd(sFontPath, sizeof(sFontPath));
    strcat(sFontPath, "/font.ttf");

    //Provem de carregar els diferents tamanys de lletra
    aFonts[SMALL] = al_load_ttf_font(sFontPath, 8, 0);
    aFonts[NORMAL] = al_load_ttf_font(sFontPath, 12, 0);
    aFonts[LARGE] = al_load_ttf_font(sFontPath, 22, 0);
    aFonts[EXTRA_LARGE] = al_load_ttf_font(sFontPath, 32, 0);

    //Comprovem si hi ha hagut errors
    for (nCounter = 0; nCounter < MAX_FONTS; nCounter++) {
        if (aFonts[nCounter] == NULL) {
            return 0;
        }
    }

    return 1;
}

//Pre: Cap
//Posr: Retorna 1 (CERT) si s'ha pogut inicialitzar i llançar el thread d'escolta de teclat i pintat per pantalla. Altrament, retorna 0 (FALS).
static int LS_allegro_init_thread() {
    pMutex = al_create_mutex();
    pThread = al_create_thread(LS_allegro_worker, NULL);

    //Comprovem que s'han correctament el semàfor i el thread
    if (pMutex != NULL && pThread != NULL) {
        al_start_thread(pThread);
        return 1;
    }
    return 0;
}

//--------------------------------------------- PÚBLIQUES ---------------------------------------------//

//Pre : Cap
//Post: Retorna 1 (CERT) si s'ha pogut inicialitzar correctament el Framework d'Allegro5. En cas contrari es retornarà 0 (FALS).
int LS_allegro_init(int nAmplitud, int nAltura, char *sNomFinestra) {

    //Declarem varaibles locals
    int aErrors[MAX_ERRORS];
    int nCounter = 0;

    //Inicialitzem array d'errors a 0 (flags desactivats)
    memset(aErrors, 0, sizeof(int) * MAX_ERRORS);
    //Inicialitzem array de tecles premudes
    memset(aErrors, 0, sizeof(int) * MAX_ERRORS);

    //Provem d'inicialitzar tots els mòduls d'Allegro5
    aErrors[0] = al_init();
    aErrors[1] = al_init_primitives_addon();
    aErrors[2] = al_install_keyboard();
    aErrors[3] = al_install_mouse();
    al_init_font_addon();
    aErrors[4] = al_init_ttf_addon();
    al_init_image_addon();
    aErrors[5] = LS_allegro_init_display(nAmplitud, nAltura, sNomFinestra);
    aErrors[6] = LS_allegro_init_event_queue();
    aErrors[7] = LS_allegro_init_colors();
    aErrors[8] = LS_allegro_init_fonts();
    aErrors[9] = LS_allegro_init_thread();

    //Comprovem els flags d'error abans de continuar
    for (nCounter = 0; nCounter < MAX_ERRORS; nCounter++) {
        if (aErrors[nCounter] == 0) {
            switch (nCounter) {
                case 0:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar l'Allegro 5.\n");
                    break;
                case 1:
                    printf("LS Allegro Error: No s'ha pogut carregar el modul de primitives d'Allegro 5.\n");
                    break;
                case 2:
                    printf("LS Allegro Error: No s'ha pogut carregar el modul de teclat d'Allegro 5.\n");
                    break;
                case 3:
                    printf("LS Allegro Error: No s'ha pogut carregar el modul de ratolí d'Allegro 5.\n");
                    break;
                case 4:
                    printf("LS Allegro Error: No s'ha pogut carregar el modul de fonts ttf d'Allegro 5.\n");
                    break;
                case 5:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar la finestra grafica d'LS Allegro.\n");
                    break;
                case 6:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar la cua d'esdeveniments d'LS Allegro.\n");
                    break;
                case 7:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar la paleta de colors d'LS Allegro.\n");
                    break;
                case 8:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar el repositori de fonts d'LS Allegro.\n");
                    break;
                case 9:
                    printf("LS Allegro Error: No s'ha pogut inicialitzar el thread d'LS Allegro.\n");
                    break;
                default:
                    printf("LS Allegro Error: S'ha produit un error inesperat!\n");
                    break;
            }
            return 0;
        }
    }

    return 1;
}

//Pre : El framework d'Allegro 5 ha d'estar inicialitzat prèviament. (LS_allegro_init() ha d'haver retornat 1)
//Post : Allibera la memòria que s'havia reservat per a les variables necessàries per fer funcionar Allegro5.
void LS_allegro_exit() {

    //Declarem variables
    int nCounter = 0;

    //Tanquem el thread i el semàfor
    al_join_thread(pThread, NULL);
    if (pThread != NULL) al_destroy_thread(pThread);
    if (pMutex != NULL) al_destroy_mutex(pMutex);

    //Alliberem la memòria de les fonts
    for (nCounter = 0; nCounter < MAX_FONTS; nCounter++) {
        if (aFonts[nCounter] != NULL) al_destroy_font(aFonts[nCounter]);
    }

    //Tanquem la cua d'esdeveniments
    if (pEventQueue != NULL) {
        al_flush_event_queue(pEventQueue);
        al_destroy_event_queue(pEventQueue);
    }

    //Tanquem la finestra gràfica
    if (pDisplay != NULL) al_destroy_display(pDisplay);

    //Resetegem la array de tecles premudes
    memset(aKeys, 0, sizeof(int) * MAX_KEYS);

}

//Pre : El valor del paràmetre nKey ha de ser una constant del tipus ALLEGRO_KEY_XXXXXX
//Post : Retorna 1 (Cert) si s'ha premut la tecla rebuda al paràmetre nKey. En cas contrari, es retornarà 0 (FALS). ATENCIÓ!! LECTURA DESTRUCTIVA!
int LS_allegro_key_pressed(int nKey) {
    al_lock_mutex(pMutex);
    if (aKeys[nKey - 1] == 1) {
        aKeys[nKey - 1] = 0;
        al_unlock_mutex(pMutex);
        return 1;
    }
    al_unlock_mutex(pMutex);
    return 0;
}

//Pre : El valor de nColor ha d'estar entre 0 i 16 ambdós inclosos.
//Post : Retorna una variable del tipus ALLEGRO_COLOR corresponent al color demanat.
ALLEGRO_COLOR LS_allegro_get_color(int nColor) {
    ALLEGRO_COLOR color_return;
    if (nColor >= 0 && nColor < MAX_COLORS) {
        color_return = aColors[nColor];
    }
    return color_return;
}

//Pre : nSize ha d'estar dins l'interval [0,MAX_FONTS)
//Post : Retorna una variable del tipus ALLEGRO_FONT * per poder usar la funció al_draw_textf més facilment.
ALLEGRO_FONT *LS_allegro_get_font(int nSize) {
    if (nSize >= 0 && nSize < MAX_FONTS) {
        return aFonts[nSize];
    }
    return NULL;
}

//Pre : nColor ha d'estar dins l'interval [0,MAX_COLORS)
//Post : Fixa el color de fons de la finestra gràfica.
void LS_allegro_clear_and_paint(int nColor) {
    if (nColor >= 0 && nColor < MAX_COLORS) {
        al_flip_display();
        al_clear_to_color(LS_allegro_get_color(nColor));
    }
    usleep(1000);
}

//Pre : Cap	
//Post: Neteja els buffers del teclat perquè no hi quedi cap tecla emmagatzemada.
void LS_allegro_console_fflush() {
#if defined(__linux__)
    fflush(stdout);
    stdin->_IO_read_ptr = stdin->_IO_read_base;
    stdin->_IO_read_end = stdin->_IO_read_base;
    fflush(stdin);
#endif
#if (defined(__APPLE__) && defined(__MACH__))
    fpurge(stdin);
    fpurge(stdout);
#endif
#if defined(_WIN64) || defined(_WIN32)
    fflush(stdin);
    fflush(stdout);
#endif
}

//Pre : Cap
//Post: Neteja la pantalla de la consola
void LS_allegro_console_clear_screen() {
#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#endif
#if defined(_WIN64) || defined(_WIN32)
    system("cls");
#endif
}