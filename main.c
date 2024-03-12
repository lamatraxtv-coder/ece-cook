#include <allegro.h>
#include <stdio.h>

int main() {
    int boolcolision = 0;
    int j1posx, j1posy; // coordonnées du joueur 1
    int j2posx, j2posy; // coordonnées du joueur 2
    int deplacement = 10; // amplitude des déplacements, initialisée à 10
    int j1_orientation =1; // 1 = haut 2 = droite 3 bas 4 gauche
    int j2_orientation =1; // 1 = haut 2 = droite 3 bas 4 gauche

    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 800, 0, 0) != 0) {
        allegro_message("problème de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Initialisation des positions initiales au centre de l'écran
    j1posx = SCREEN_W / 2;
    j1posy = SCREEN_H / 2;

    j2posx = SCREEN_W / 2;
    j2posy = SCREEN_H / 2;

    // fin si appuie sur echap
    while (!key[KEY_ESC]) {
        // Efface l'écran à chaque itération de la boucle
        clear_to_color(screen, makecol(0, 0, 0));

        // Logique de déplacement pour le joueur 1
        if (key[KEY_UP]) {
            j1posy -= deplacement;
            j1_orientation=1;
        }
        if (key[KEY_DOWN]){
            j1posy += deplacement;
            j1_orientation=3;
        }
        if (key[KEY_LEFT]){
            j1posx -= deplacement;
            j1_orientation=4;
        }
        if (key[KEY_RIGHT]) {
            j1posx += deplacement;
            j1_orientation=2;
        }

        // Logique de déplacement pour le joueur 2
        if (key[KEY_W]) {
            j2posy -= deplacement;
            j2_orientation=1;
        }
        if (key[KEY_S]) {
            j2posy += deplacement;
            j2_orientation=3;
        }
        if (key[KEY_A]) {
            j2posx -= deplacement;
            j2_orientation=4;
        }
        if (key[KEY_D]) {
            j2posx += deplacement;
            j2_orientation=1;
        }

        // Contrôle des bords pour empêcher les points de sortir de l'écran
        if (j1posx < 0) j1posx = 0;
        if (j1posx > SCREEN_W) j1posx = SCREEN_W;
        if (j1posy < 0) j1posy = 0;
        if (j1posy > SCREEN_H) j1posy = SCREEN_H;

        if (j2posx < 0) j2posx = 0;
        if (j2posx > SCREEN_W) j2posx = SCREEN_W;
        if (j2posy < 0) j2posy = 0;
        if (j2posy > SCREEN_H) j2posy = SCREEN_H;

        // Dessin des points pour chaque joueur
        putpixel(screen, j1posx, j1posy, makecol(255, 255, 51));
        putpixel(screen, j2posx, j2posy, makecol(0, 255, 0));



        // Affichage des positions des joueurs
        textprintf_ex(screen, font, 60, 100, makecol(0, 255, 0), -1, "p1 : %4d %4d", j1posx, j1posy);
        textprintf_ex(screen, font, 60, 120, makecol(0, 255, 0), -1, "p2 : %4d %4d", j2posx, j2posy);

        rest(40); // Petite pause pour rendre le jeu jouable
    }

    return 0;
}
END_OF_MAIN();