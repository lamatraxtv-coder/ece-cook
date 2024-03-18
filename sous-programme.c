#include "librairies.h"

void affichagechargement(){
    set_trans_blender(0,255,0,0);
    BITMAP *imagechargement = load_bitmap("ece cook chargement.bmp", NULL);
    if (!imagechargement) {
        allegro_message("Erreur de chargement de l'image");
        return;
    }
    blit(imagechargement, screen, 0, 0, (SCREEN_W - imagechargement->w) / 2, (SCREEN_H - imagechargement->h) / 2, imagechargement->w, imagechargement->h);
    textprintf_ex(screen, font, 320, 750, makecol(0, 0, 0), -1, "Appuyez sur ESPACE pour continuer");
    while (!key[KEY_SPACE]) {
        rest(100);
    }
}

void load_player_images() {//
    // Chargement des images pour joueur 1
    PERSO1_O[0] = load_bitmap("perso1O1.bmp", NULL);
    PERSO1_O[1] = load_bitmap("perso1O2.bmp", NULL);
    PERSO1_O[2] = load_bitmap("perso1O3.bmp", NULL);
    PERSO1_O[3] = load_bitmap("perso1O4.bmp", NULL);

    // Chargement des images pour joueur 2
    PERSO2_O[0] = load_bitmap("perso2O1.bmp", NULL);
    PERSO2_O[1] = load_bitmap("perso2O2.bmp", NULL);
    PERSO2_O[2] = load_bitmap("perso2O3.bmp", NULL);
    PERSO2_O[3] = load_bitmap("perso2O4.bmp", NULL);
}


// Ajout de la fonction image_joueur
void image_joueur(BITMAP *screen, int j1posx, int j1posy, int j2posx, int j2posy, int orienJ1, int orienJ2) {
    // Dessin du joueur 1 avec l'orientation appropriée
    if (orienJ1 >= 1 && orienJ1 <= 4) {
        draw_sprite(screen, PERSO1_O[orienJ1 - 1], j1posx, j1posy);
    }

    // Dessin du joueur 2 avec l'orientation appropriée
    if (orienJ2 >= 1 && orienJ2 <= 4) {
        draw_sprite(screen, PERSO2_O[orienJ2 - 1], j2posx, j2posy);
    }
}
