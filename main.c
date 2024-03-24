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
        affichagechargement();
        load_player_images();
        int j1posx = SCREEN_W / 2, j1posy = SCREEN_H / 2;
        int j2posx = SCREEN_W / 2, j2posy = SCREEN_H / 2;
        int deplacement = 10;
        int orienJ1=1;
        int orienJ2=1;

        while (!key[KEY_ESC]) {
            clear_to_color(screen, makecol(0, 0, 0));

            if (key[KEY_UP]) {j1posy -= deplacement; orienJ1=1;}
            if (key[KEY_DOWN]) {j1posy += deplacement; orienJ1=3;}
            if (key[KEY_LEFT]) {j1posx -= deplacement; orienJ1=4;}
            if (key[KEY_RIGHT]) {j1posx += deplacement; orienJ1=2;}

            if (key[KEY_W]) {j2posy -= deplacement; orienJ2=1;}
            if (key[KEY_S]) {j2posy += deplacement; orienJ2=3;}
            if (key[KEY_A]) {j2posx -= deplacement; orienJ2=4;}
            if (key[KEY_D]) {j2posx += deplacement; orienJ2=2;}

            if (j1posx < 0) j1posx = 0;
            if (j1posx > SCREEN_W-70) j1posx = SCREEN_W-70;
            if (j1posy < 0) j1posy = 0;
            if (j1posy > SCREEN_H-70) j1posy = SCREEN_H-70;

            if (j2posx < 0) j2posx = 0;
            if (j2posx > SCREEN_W-70) j2posx = SCREEN_W-70;
            if (j2posy < 0) j2posy = 0;//
            if (j2posy > SCREEN_H-70) j2posy = SCREEN_H-70;


            // Remplacement des putpixel par image_joueur
            image_joueur(screen, j1posx, j1posy, j2posx, j2posy,orienJ1,orienJ2);

            textprintf_ex(screen, font, 60, 100, makecol(0, 255, 0), -1, "p1 : %4d %4d", j1posx, j1posy);
            textprintf_ex(screen, font, 60, 120, makecol(0, 255, 0), -1, "p2 : %4d %4d", j2posx, j2posy);

            rest(40);
        }

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