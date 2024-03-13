#include <allegro.h>
#include <stdio.h>

// Déclaration de la fonction draw_grid (inchangée)
void draw_grid(BITMAP *bmp, int width, int height, int cell_width, int cell_height) {
    int i;
    for (i = 0; i <= width; i += cell_width) {
        vline(bmp, i, 0, height, makecol(255, 255, 255));
    }
    for (i = 0; i <= height; i += cell_height) {
        hline(bmp, 0, i, width, makecol(255, 255, 255));
    }
}

// Déclaration de la fonction affichagechargement (inchangée)
void affichagechargement(){
    set_trans_blender(0,255,0,0);
    BITMAP *imagechargement = load_bitmap("ece cook chargement.bmp", NULL);
    if (!imagechargement) {
        allegro_message("Erreur de chargement de l'image");
        return;
    }
    blit(imagechargement, screen, 0, 0, (SCREEN_W - imagechargement->w) / 2, (SCREEN_H - imagechargement->h) / 2, imagechargement->w, imagechargement->h);
    textprintf_ex(screen, font, 60, 120, makecol(0, 0, 0), -1, "Appuyez sur ESPACE pour continuer");
    while (!key[KEY_SPACE]) {
        rest(100);
    }
}

// Ajout de la fonction image_joueur
void image_joueur(BITMAP *screen, BITMAP *image_joueur1, BITMAP *image_joueur2, int j1posx, int j1posy, int j2posx, int j2posy) {
    draw_sprite(screen, image_joueur1, j1posx, j1posy);
    draw_sprite(screen, image_joueur2, j2posx, j2posy);
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

    // Chargement des images des joueurs
    BITMAP *PERSO1 = load_bitmap("perso1.bmp", NULL);
    BITMAP *PERSO2 = load_bitmap("perso2.bmp", NULL);

    // Vérification du chargement
    if (!PERSO1 || !PERSO2) {
        allegro_message("Erreur de chargement des images des joueurs");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int j1posx = SCREEN_W / 2, j1posy = SCREEN_H / 2;
    int j2posx = SCREEN_W / 2, j2posy = SCREEN_H / 2;
    int deplacement = 10;

    while (!key[KEY_ESC]) {
        clear_to_color(screen, makecol(0, 0, 0));

        if (key[KEY_UP]) j1posy -= deplacement;
        if (key[KEY_DOWN]) j1posy += deplacement;
        if (key[KEY_LEFT]) j1posx -= deplacement;
        if (key[KEY_RIGHT]) j1posx += deplacement;

        if (key[KEY_W]) j2posy -= deplacement;
        if (key[KEY_S]) j2posy += deplacement;
        if (key[KEY_A]) j2posx -= deplacement;
        if (key[KEY_D]) j2posx += deplacement;

        if (j1posx < 0) j1posx = 0;
        if (j1posx > SCREEN_W) j1posx = SCREEN_W;
        if (j1posy < 0) j1posy = 0;
        if (j1posy > SCREEN_H) j1posy = SCREEN_H;

        if (j2posx < 0) j2posx = 0;
        if (j2posx > SCREEN_W) j2posx = SCREEN_W;
        if (j2posy < 0) j2posy = 0;
        if (j2posy > SCREEN_H) j2posy = SCREEN_H;


        // Remplacement des putpixel par image_joueur
        image_joueur(screen, PERSO1, PERSO2, j1posx, j1posy, j2posx, j2posy);

        textprintf_ex(screen, font, 60, 100, makecol(0, 255, 0), -1, "p1 : %4d %4d", j1posx, j1posy);
        textprintf_ex(screen, font, 60, 120, makecol(0, 255, 0), -1, "p2 : %4d %4d", j2posx, j2posy);

        rest(40);
    }

    return 0;
}
END_OF_MAIN();


