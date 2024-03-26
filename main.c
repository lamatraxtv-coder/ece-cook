#include "librairies.h"

// Fonction principale
int main() {
    allegro_init();//initialisation de allegro
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 800, 0, 0) != 0) {
        allegro_message("problème de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);//sortie du programme
    }

    int niv_fini = 0;
    int select = 0;
    int nivchoisi = 0;
    int infinite=1;

    do {
        select = menu();
        if (select == 1) {
            nivchoisi = selectniv(niv_fini);
            if (nivchoisi != 0) {
                jeu(nivchoisi);
            }

        } else if (select == 2) {
            allegro_exit();
            break;
        }
        else if(select == 3){
            tuto();
            break;
        }


    } while (infinite=1);

    allegro_exit();
    return 0;
}
END_OF_MAIN();
//