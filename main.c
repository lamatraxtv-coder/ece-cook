
#include <allegro.h>

int main()
{
    int boolcolision=0;
    // paramètres de l'élément à animer
    int posx,posy;    // coordonnées
    int tx,ty;        // taille (largeur et hauteur)
    int deplacement;  // amplitude absolu des déplacements

    srand(time(NULL));

    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // initialisation des variables de la forme

    // tailles et position initiale au centre
    tx=60;
    ty=40;
    posx=SCREEN_W/2-tx/2;
    posy=SCREEN_H/2-ty/2;



    // Boucle interactive
    while (!key[KEY_ESC])
    {


        rectfill(screen,posx,posy,posx+tx,posy+ty,makecol(0,0,0));


        if (key[KEY_UP])
            posy = posy-deplacement; // mouvement négatif en ordonnées
        if (key[KEY_DOWN])
            posy = posy+deplacement; // mouvement positif en ordonnées
        if (key[KEY_LEFT])
            posx = posx-deplacement; // mouvement négatif en abscisses
        if (key[KEY_RIGHT])
            posx = posx+deplacement; // mouvement positif en abscisses

        // Contrôle des bords pour empêcher l'objet de sortir de l'écran

        if (posx < 0) posx = 0;
        if (posx + tx > SCREEN_W) posx = SCREEN_W - tx;
        if (posy < 0) posy = 0;
        if (posy + ty > SCREEN_H) posy = SCREEN_H - ty;

        // 3) AFFICHAGE NOUVELLE POSITION
        rectfill(screen,posx,posy,posx+tx,posy+ty,makecol(255,128,128));

        // 4) ON FAIT UNE PETITE PAUSE à chaque fois sinon ça va trop vite...
        rest(20);
    }

    return 0;
}
END_OF_MAIN();
