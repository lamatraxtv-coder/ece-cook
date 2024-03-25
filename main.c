#include "librairies.h"


// Fonction principale
int main() {
    allegro_init();

    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 800, 0, 0) != 0) {
        allegro_message("problème de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int niv_fini=0;
    int select;
    int nivchoisi=0;
    select= menu();

    if (select==1){
        nivchoisi=selectniv(niv_fini);
        jeu(nivchoisi);
    }
    if(select==2){
        allegro_exit();
    }
    if(select==3){
        allegro_exit();
    }
    return 0;
}
END_OF_MAIN();



//test