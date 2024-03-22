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
int menu(){
    install_mouse();
    show_mouse(screen);
    BITMAP *menuneutre= load_bitmap("menuneutre.bmp",NULL);
    BITMAP *menu1= load_bitmap("menu1.bmp",NULL);
    BITMAP *menu2= load_bitmap("menu2.bmp",NULL);
    BITMAP *menu3= load_bitmap("menu3.bmp",NULL);
    BITMAP *menu4= load_bitmap("menu4.bmp", NULL);
    int a=0;
    int selection;
    blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);
    while(a==0){

        if(mouse_x>=155 && mouse_x<=313 && mouse_y>=572 && mouse_y<=658){
            blit(menu1, screen, 0, 0, (SCREEN_W - menu1->w) / 2, (SCREEN_H - menu1->h) / 2, menu1->w, menu1->h);
            if(mouse_b & 1){
                a=1;
                selection=1;
            }
        }
        if(mouse_x>=368 && mouse_x<=538 && mouse_y>=572 && mouse_y<=658){
            blit(menu2, screen, 0, 0, (SCREEN_W - menu2->w) / 2, (SCREEN_H - menu2->h) / 2, menu2->w, menu2->h);
            if(mouse_b & 1){
                a=1;
                selection=2;
            }
        }

        if(mouse_x>=585 && mouse_x<=752 && mouse_y>=572 && mouse_y<=658){
            blit(menu3, screen, 0, 0, (SCREEN_W - menu3->w) / 2, (SCREEN_H - menu3->h) / 2, menu3->w, menu3->h);
            if(mouse_b & 1){
                a=1;
                selection=3;
            }
        }
        if(mouse_x>=487 && mouse_x<=634 && mouse_y>=715 && mouse_y <=762){
            if(mouse_b & 1){
                allegro_exit();
            }
        }
        if(!(mouse_x>=585 && mouse_x<=752 && mouse_x>=368 && mouse_x<=538 &&mouse_x>=155 && mouse_x<=313) && mouse_y<572 && mouse_y>658 && mouse_x < 155 && mouse_x >313 && mouse_x<368 && mouse_x>538 && mouse_x<585 && mouse_x > 753){
            blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);
        }

    }
    return selection;

}