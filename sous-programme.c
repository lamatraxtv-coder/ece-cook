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
int selectniv(int fini){
    install_mouse();
    show_mouse(screen);
    int a=0;
    int choixniv;
    BITMAP *choix1= load_bitmap("choix_niv_1U.bmp",NULL);
    BITMAP *choix1_1= load_bitmap("choix_niv_1U_niv1.bmp",NULL);
    BITMAP *choix2= load_bitmap("choix_niv_2U.bmp",NULL);
    BITMAP *choix2_1= load_bitmap("choix_niv_2U_niv1.bmp",NULL);
    BITMAP *choix2_2= load_bitmap("choix_niv_2U_niv2.bmp",NULL);
    BITMAP *choix3= load_bitmap("choix_niv_3U.bmp",NULL);
    BITMAP *choix3_1= load_bitmap("choix_niv_3U_niv1.bmp",NULL);
    BITMAP *choix3_2= load_bitmap("choix_niv_3U_niv2.bmp",NULL);
    BITMAP *choix3_3= load_bitmap("choix_niv_3U_niv3.bmp",NULL);
    BITMAP *choix1_M= load_bitmap("choix_niv_1U_M.bmp",NULL);
    BITMAP *choix2_M= load_bitmap("choix_niv_2U_M.bmp",NULL);
    BITMAP *choix3_M= load_bitmap("choix_niv_3U_M.bmp",NULL);
    while(a==0){
        if(fini==0){
            if(mouse_x>38 && mouse_x<292 && mouse_y>237 && mouse_y<739){
                blit(choix1_1, screen, 0, 0, (SCREEN_W - choix1_1->w) / 2, (SCREEN_H - choix1_1->h) / 2, choix1_1->w, choix1_1->h);
                if(mouse_b & 1){
                    choixniv=1;
                    a=1;
                }
            }
            if(mouse_x>793 && mouse_x<863 && mouse_y>27 && mouse_y<112){
                blit(choix1_M, screen, 0, 0, (SCREEN_W - choix1_M->w) / 2, (SCREEN_H - choix1_M->h) / 2, choix1_M->w, choix1_M->h);
                if(mouse_b & 1){
                    choixniv=0;
                    a=1;
                }
            }
            if(!(mouse_x>38 && mouse_x<292||mouse_x>793 && mouse_x<863 && mouse_y>237 && mouse_y<739 ||mouse_y>27 && mouse_y<112)){
                blit(choix1, screen, 0, 0, (SCREEN_W - choix1->w) / 2, (SCREEN_H - choix1->h) / 2, choix1->w, choix1->h);
            }
            textprintf_ex(screen, font, 60, 100, makecol(0, 0, 0), -1, "p1 : %4d %4d", mouse_x, mouse_y);
            if(key[KEY_ESC]){
                fini=fini+1;
                sleep(1);
            }

        }
        if(fini==1){

            if(mouse_x>38 && mouse_x<292 && mouse_y>237 && mouse_y<739){
                blit(choix2_1, screen, 0, 0, (SCREEN_W - choix2_1->w) / 2, (SCREEN_H - choix2_1->h) / 2, choix2_1->w, choix2_1->h);
                if(mouse_b & 1){
                    choixniv=1;
                    a=1;
                }
            }
            if(mouse_x>335 && mouse_x<583 && mouse_y>237 && mouse_y<739){
                blit(choix2_2, screen, 0, 0, (SCREEN_W - choix2_2->w) / 2, (SCREEN_H - choix2_2->h) / 2, choix2_2->w, choix2_2->h);
                if(mouse_b & 1){
                    choixniv=2;
                    a=1;
                }
            }
            if(mouse_x>793 && mouse_x<863 && mouse_y>27 && mouse_y<112){
                blit(choix2_M, screen, 0, 0, (SCREEN_W - choix2_M->w) / 2, (SCREEN_H - choix2_M->h) / 2, choix2_M->w, choix2_M->h);
                if(mouse_b & 1){
                    choixniv=0;
                    a=1;
                }
            }
            if(!(mouse_x>38 && mouse_x<292  || mouse_x>335 && mouse_x<583 || mouse_x>793 && mouse_x<863 && mouse_y>237 && mouse_y<739||mouse_y>27 && mouse_y<112)) {
                blit(choix2, screen, 0, 0, (SCREEN_W - choix2->w) / 2, (SCREEN_H - choix2->h) / 2, choix2->w,choix2->h);
            }
            if(key[KEY_ESC]){
                fini=fini+1;
            }
        }
        if(fini==2){
            if(mouse_x>38 && mouse_x<292 && mouse_y>237 && mouse_y<739){
                blit(choix3_1, screen, 0, 0, (SCREEN_W - choix3_1->w) / 2, (SCREEN_H - choix3_1->h) / 2, choix3_1->w, choix3_1->h);
                if(mouse_b & 1){
                    choixniv=1;
                    a=1;
                }
            }
            if(mouse_x>335 && mouse_x<583 && mouse_y>237 && mouse_y<739) {
                blit(choix3_2, screen, 0, 0, (SCREEN_W - choix3_2->w) / 2, (SCREEN_H - choix3_2->h) / 2, choix3_2->w,choix3_2->h);
                if (mouse_b & 1) {
                    choixniv = 2;
                    a = 1;
                }
            }
            if (mouse_x > 625 && mouse_x < 876 && mouse_y>237 && mouse_y<739) {
                blit(choix3_3, screen, 0, 0, (SCREEN_W - choix3_3->w) / 2, (SCREEN_H - choix3_3->h) / 2,choix3_3->w, choix3_3->h);
                if (mouse_b & 1) {
                    choixniv = 3;
                    a = 1;
                }
            }
            if(mouse_x>793 && mouse_x<863 && mouse_y>27 && mouse_y<112){
                blit(choix3_M, screen, 0, 0, (SCREEN_W - choix3_M->w) / 2, (SCREEN_H - choix3_M->h) / 2, choix3_M->w, choix3_M->h);
                if(mouse_b & 1){
                    choixniv=0;
                    a=1;
                }
            }
            if(!(mouse_x>38 && mouse_x<292  || mouse_x>335 && mouse_x<583 || mouse_x > 625 && mouse_x < 876|| mouse_x>793 && mouse_x<863 && mouse_y>237 && mouse_y<739 ||mouse_y>27 && mouse_y<112)) {
                blit(choix3, screen, 0, 0, (SCREEN_W - choix3->w) / 2, (SCREEN_H - choix3->h) / 2, choix3->w,choix3->h);
            }
        }
    }

    return choixniv;

}

int jeu(int nivchoisi){
    int j1posx = SCREEN_W / 2, j1posy = SCREEN_H / 2;
    int j2posx = SCREEN_W / 2, j2posy = SCREEN_H / 2;
    int deplacement = 15;
    int orienJ1=1;//
    int orienJ2=1;
    affichagechargement();
    load_player_images();

    while (!key[KEY_ESC]) {
        clear_to_color(screen, makecol(0, 0, 0));
        if(nivchoisi==1){
        //blit et load du nieau associé
            if (j1posx < 0) j1posx = 0;
            if (j1posx > SCREEN_W-70) j1posx = SCREEN_W-70;
            if (j1posy < 0) j1posy = 0;
            if (j1posy > SCREEN_H-70) j1posy = SCREEN_H-70;

            if (j2posx < 0) j2posx = 0;
            if (j2posx > SCREEN_W-70) j2posx = SCREEN_W-70;
            if (j2posy < 0) j2posy = 0;//
            if (j2posy > SCREEN_H-70) j2posy = SCREEN_H-70;
        }
        if(nivchoisi==2){
        //blit et load du niveau associé
            if (j1posx < 0) j1posx = 0;
            if (j1posx > SCREEN_W-70) j1posx = SCREEN_W-70;
            if (j1posy < 0) j1posy = 0;
            if (j1posy > SCREEN_H-70) j1posy = SCREEN_H-70;

            if (j2posx < 0) j2posx = 0;
            if (j2posx > SCREEN_W-70) j2posx = SCREEN_W-70;
            if (j2posy < 0) j2posy = 0;//
            if (j2posy > SCREEN_H-70) j2posy = SCREEN_H-70;
        }
        if(nivchoisi==3){
        //blit et load du niveau associé
            if (j1posx < 0) j1posx = 0;
            if (j1posx > SCREEN_W-70) j1posx = SCREEN_W-70;
            if (j1posy < 0) j1posy = 0;
            if (j1posy > SCREEN_H-70) j1posy = SCREEN_H-70;

            if (j2posx < 0) j2posx = 0;
            if (j2posx > SCREEN_W-70) j2posx = SCREEN_W-70;
            if (j2posy < 0) j2posy = 0;//
            if (j2posy > SCREEN_H-70) j2posy = SCREEN_H-70;
        }

        if (key[KEY_UP]) {j1posy -= deplacement; orienJ1=1;}
        if (key[KEY_DOWN]) {j1posy += deplacement; orienJ1=3;}
        if (key[KEY_LEFT]) {j1posx -= deplacement; orienJ1=4;}
        if (key[KEY_RIGHT]) {j1posx += deplacement; orienJ1=2;}

        if (key[KEY_W]) {j2posy -= deplacement; orienJ2=1;}
        if (key[KEY_S]) {j2posy += deplacement; orienJ2=3;}
        if (key[KEY_A]) {j2posx -= deplacement; orienJ2=4;}
        if (key[KEY_D]) {j2posx += deplacement; orienJ2=2;}


        image_joueur(screen, j1posx, j1posy, j2posx, j2posy,orienJ1,orienJ2);

        textprintf_ex(screen, font, 60, 100, makecol(0, 255, 0), -1, "p1 : %4d %4d", j1posx, j1posy);
        textprintf_ex(screen, font, 60, 120, makecol(0, 255, 0), -1, "p2 : %4d %4d", j2posx, j2posy);

        rest(40);
    }
}
void tuto(){

}//
