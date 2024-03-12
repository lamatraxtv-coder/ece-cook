#include <allegro.h>

int main()
{
    int boolcolision=0;
    int j1posx, j1posy; // coordonnées du joueur 1
    int j2posx, j2posy; // coordonnées du joueur 2
    int tx, ty;         // taille (largeur et hauteur)
    int deplacement = 10; // amplitude des déplacements, initialisée à 10

    srand(time(NULL));

    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0)
    {
        allegro_message("problème de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // Initialisation des variables de la forme
    tx = 60;
    ty = 40;
    j1posx = SCREEN_W / 2 - tx / 2;
    j1posy = SCREEN_H / 2 - ty / 2;

    j2posx = SCREEN_W / 2 - tx / 2;
    j2posy = SCREEN_H / 2 - ty / 2;

    // Boucle interactive
    while (!key[KEY_ESC])
    {
        rectfill(screen, j1posx, j1posy, j1posx + tx, j1posy + ty, makecol(0, 0, 0));
        rectfill(screen, j2posx, j2posy, j2posx + tx, j2posy + ty, makecol(0, 0, 0));

        if (key[KEY_UP])
            j1posy -= deplacement;
        if (key[KEY_DOWN])
            j1posy += deplacement;
        if (key[KEY_LEFT])
            j1posx -= deplacement;
        if (key[KEY_RIGHT])
            j1posx += deplacement;

        if (key[KEY_Z])
            j2posy -= deplacement;
        if (key[KEY_S])
            j2posy += deplacement;
        if (key[KEY_Q])
            j2posx -= deplacement;
        if (key[KEY_D])
            j2posx += deplacement;

        if (key[KEY_W]) // Utiliser W au lieu de Z
            j2posy -= deplacement;
        if (key[KEY_S])
            j2posy += deplacement;
        if (key[KEY_A]) // Utiliser A au lieu de Q
            j2posx -= deplacement;
        if (key[KEY_D])
            j2posx += deplacement;


        // Contrôle des bords pour empêcher l'objet de sortir de l'écran
        if (j1posx < 0) j1posx = 0;
        if (j1posx + tx > SCREEN_W) j1posx = SCREEN_W - tx;
        if (j1posy < 0) j1posy = 0;
        if (j1posy + ty > SCREEN_H) j1posy = SCREEN_H - ty;

        if (j2posx < 0) j2posx = 0;
        if (j2posx + tx > SCREEN_W) j2posx = SCREEN_W - tx;
        if (j2posy < 0) j2posy = 0;
        if (j2posy + ty > SCREEN_H) j2posy = SCREEN_H - ty;

        rectfill(screen, j1posx, j1posy, j1posx + tx, j1posy + ty, makecol(255, 128, 128));
        rectfill(screen, j2posx, j2posy, j2posx + tx, j2posy + ty, makecol(255, 128, 128));

        textprintf_ex(screen,font,60,300,makecol(0,255,0),makecol(0,0,0),"%4d %4d",j1posx,j1posy);
        textprintf_ex(screen,font,60,100,makecol(0,255,0),makecol(0,0,0),"%4d %4d",j2posx,j2posy);

        rest(40); // Petite pause pour rendre le jeu jouable

    }

    return 0;
}
END_OF_MAIN();
