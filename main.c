#include <allegro.h>
#include <stdio.h>


BITMAP *PERSO1_O[4]; // Tableau pour les 4 orientations du joueur 1
BITMAP *PERSO2_O[4]; // Tableau pour les 4 orientations du joueur 2
// Déclaration de la fonction affichagechargement (inchangée)
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

void load_player_images() {
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

int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 800, 0, 0) != 0) {
        allegro_message("problème de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    affichagechargement();
    load_player_images();


    // Vérification du chargement


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
        if (j2posy < 0) j2posy = 0;
        if (j2posy > SCREEN_H-70) j2posy = SCREEN_H-70;


        // Remplacement des putpixel par image_joueur
        image_joueur(screen, j1posx, j1posy, j2posx, j2posy,orienJ1,orienJ2);

        textprintf_ex(screen, font, 60, 100, makecol(0, 255, 0), -1, "p1 : %4d %4d", j1posx, j1posy);
        textprintf_ex(screen, font, 60, 120, makecol(0, 255, 0), -1, "p2 : %4d %4d", j2posx, j2posy);

        rest(40);
    }

    return 0;
}
END_OF_MAIN();


//test