#include "librairies.h"

void affichagechargement(){
    set_trans_blender(0,255,0,0);
    BITMAP *imagechargement=load_bitmap("../images/ece cook chargement.bmp", NULL);//chargement de l'image
    if (!imagechargement){
        allegro_message("Erreur de chargement de l'image");//message d'erreur
        return;
    }
    blit(imagechargement, screen, 0, 0, (SCREEN_W - imagechargement->w) / 2, (SCREEN_H - imagechargement->h) / 2, imagechargement->w, imagechargement->h);//affichage de l'image
    textprintf_ex(screen, font, 320, 750, makecol(0, 0, 0), -1, "Appuyez sur ESPACE pour continuer");//affichage du texte
    while (!key[KEY_SPACE]){//boucle pour attendre l'appui sur la touche espace
        rest(100);//pause de 100 ms
    }
    destroy_bitmap(imagechargement);//destruction de l'image
}
void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]) {// chargement des images des joueurs

    // Chargement des images pour joueur 1
    PERSO1_O[0] = load_bitmap("../images/perso1O1.bmp", NULL);//chargement de l'image
    PERSO1_O[1] = load_bitmap("../images/perso1O2.bmp", NULL);
    PERSO1_O[2] = load_bitmap("../images/perso1O3.bmp", NULL);
    PERSO1_O[3] = load_bitmap("../images/perso1O4.bmp", NULL);

    // Chargement des images pour joueur 2
    PERSO2_O[0] = load_bitmap("../images/perso2O1.bmp", NULL);//chargement de l'image
    PERSO2_O[1] = load_bitmap("../images/perso2O2.bmp", NULL);
    PERSO2_O[2] = load_bitmap("../images/perso2O3.bmp", NULL);
    PERSO2_O[3] = load_bitmap("../images/perso2O4.bmp", NULL);
}
void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], int j1posx, int j1posy, int j2posx, int j2posy, int orienJ1, int orienJ2){//affichage des joueurs
    // Dessin du joueur 1 avec l'orientation appropriée
    if (orienJ1 >= 1 && orienJ1 <= 4){//affichage du joueur 1
        draw_sprite(buffer, PERSO1_O[orienJ1 - 1], j1posx, j1posy);//affichage de l'image
    }
    if (orienJ2 >= 1 && orienJ2 <= 4){//affichage du joueur 2
        draw_sprite(buffer, PERSO2_O[orienJ2 - 1], j2posx, j2posy);//affichage de l'image
    }
}
int gerer_commandes(BITMAP *buffer, int recettes, BITMAP *recette1, BITMAP *recette2, BITMAP *recette3, int recette[MAX_COMMANDES], int index) {
    BITMAP *recettesDisponibles[3] = {recette1, recette2, recette3};
    int random;

    random=rand() % 200;//ajout de commande
    if (random==1 && recettes < MAX_COMMANDES){
        recette[recettes]=rand() % 3;
        recettes++;
    }

    if (key[KEY_U]){//suppression de commande
        if (index < 0||index >= recettes){//verification de l'index
            allegro_message("Index invalide pour la suppression:%d\n", index);//message d'erreur
            return recettes;//retour de la valeur
        }
        for (int i=index; i<recettes - 1;i++){//suppression de la commande
            recette[i]=recette[i + 1];//suppression de la commande
        }
        recettes--;
    }
    for (int i = 0; i < recettes; i++){//affichage des commandes
        draw_sprite(buffer, recettesDisponibles[recette[i]], 20 + (200 * i), -100);//affichage de l'image
    }
    return recettes;
}
int menu_cru(BITMAP *buffer,int nivchoisi, int combinaison1, int combinaison2){
    BITMAP * A0=  load_bitmap("../images/menucru niv1.bmp", NULL);
    BITMAP * A1=load_bitmap("../images/menucru niv1_1.bmp", NULL);
    BITMAP * A2=load_bitmap("../images/menucru niv1_2.bmp", NULL);
    BITMAP * A3=load_bitmap("../images/menucru niv1_3.bmp", NULL);
  //  load_bitmap("../images/menucru niv2.bmp", NULL);
  //  load_bitmap("../images/menucru niv3.bmp", NULL);
    if (nivchoisi==1){
        draw_sprite(buffer, A0, 450, 400);//affichage de l'image
        if(mouse_y>=480 && mouse_y<=513 )
        {
            draw_sprite(buffer, A1, 450, 400);//affichage de l'image
            if(mouse_b & 1){//verification du clic
                combinaison1=1;
                allegro_message("vous avez pris un thon");
            }

        }
        if(mouse_y>=513 && mouse_y<=600)
        {
            draw_sprite(buffer, A2, 450, 400);//affichage de l'image
            if(mouse_b & 1){//verification du clic
                combinaison1=2;
                allegro_message("vous avez pris un saumon");
            }
        }
        if(mouse_y>=600 && mouse_y<=700)
        {
            draw_sprite(buffer, A3, 450, 400);//affichage de l'image
            if(mouse_b & 1){//verification du clic
                combinaison1=3;
                allegro_message("vous avez pris du riz cru");
            }
        }

    }
//
}

int menu(){
    install_mouse();//installation de la souris
    show_mouse(screen);//affichage de la souris
    BITMAP *menuneutre= load_bitmap("../images/menuneutre.bmp",NULL);//chargement de l'image
    BITMAP *menu1= load_bitmap("../images/menu1.bmp",NULL);
    BITMAP *menu2= load_bitmap("../images/menu2.bmp",NULL);
    BITMAP *menu3= load_bitmap("../images/menu3.bmp",NULL);
    int a=0;
    int selection;//initialisation de la selection
    blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);//affichage de l'image
    while(a==0){

        if(mouse_x>=155 && mouse_x<=313 && mouse_y>=572 && mouse_y<=658){//verification de la position de la souris
            blit(menu1, screen, 0, 0, (SCREEN_W - menu1->w) / 2, (SCREEN_H - menu1->h) / 2, menu1->w, menu1->h);//affichage de l'image
            if(mouse_b & 1){//verification du clic
                a=1;//sortie de la boucle
                selection=1;//selection du menu
            }
        }
        if(mouse_x>=368 && mouse_x<=538 && mouse_y>=572 && mouse_y<=658){//verification de la position de la souris
            blit(menu2, screen, 0, 0, (SCREEN_W - menu2->w) / 2, (SCREEN_H - menu2->h) / 2, menu2->w, menu2->h);
            if(mouse_b & 1){//verification du clic
                a=1;
                selection=2;
            }
        }

        if(mouse_x>=585 && mouse_x<=752 && mouse_y>=572 && mouse_y<=658){//verification de la position de la souris
            blit(menu3, screen, 0, 0, (SCREEN_W - menu3->w) / 2, (SCREEN_H - menu3->h) / 2, menu3->w, menu3->h);
            if(mouse_b & 1){//verification du clic
                a=1;
                selection=3;
            }
        }
        if(mouse_x>=487 && mouse_x<=634 && mouse_y>=715 && mouse_y <=762){//verification de la position de la souris
            if(mouse_b & 1){//verification du clic
                allegro_exit();
            }
        }
        if(!(mouse_x>=155 && mouse_x<=313 && mouse_y>=572 && mouse_y<=658) &&//verification de la position de la souris
           !(mouse_x>=368 && mouse_x<=538 && mouse_y>=572 && mouse_y<=658) &&
           !(mouse_x>=585 && mouse_x<=752 && mouse_y>=572 && mouse_y<=658) &&
           !(mouse_x>=487 && mouse_x<=634 && mouse_y>=715 && mouse_y <=762)) {
            blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);//affichage de l'image
        }
    }
    return selection;
}
int selectniv(int fini){//selection du niveau
    install_mouse();//installation de la souris
    show_mouse(screen);//affichage de la souris
    int a=0;//initialisation de la variable
    int choixniv;
    BITMAP *choix1 = load_bitmap("../images/choix_niv_1U.bmp", NULL);//chargement de l'image
    BITMAP *choix1_1 = load_bitmap("../images/choix_niv_1U_niv1.bmp", NULL);
    BITMAP *choix2 = load_bitmap("../images/choix_niv_2U.bmp", NULL);
    BITMAP *choix2_1 = load_bitmap("../images/choix_niv_2U_niv1.bmp", NULL);
    BITMAP *choix2_2 = load_bitmap("../images/choix_niv_2U_niv2.bmp", NULL);
    BITMAP *choix3 = load_bitmap("../images/choix_niv_3U.bmp", NULL);
    BITMAP *choix3_1 = load_bitmap("../images/choix_niv_3U_niv1.bmp", NULL);
    BITMAP *choix3_2 = load_bitmap("../images/choix_niv_3U_niv2.bmp", NULL);
    BITMAP *choix3_3 = load_bitmap("../images/choix_niv_3U_niv3.bmp", NULL);
    BITMAP *choix1_M = load_bitmap("../images/choix_niv_1U_M.bmp", NULL);
    BITMAP *choix2_M = load_bitmap("../images/choix_niv_2U_M.bmp", NULL);
    BITMAP *choix3_M = load_bitmap("../images/choix_niv_3U_M.bmp", NULL);
    while (a == 0){//boucle pour la selection du niveau
        if (fini == 0){//verification de la variable
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739){//verification de la position de la souris
                blit(choix1_1, screen, 0, 0, (SCREEN_W - choix1_1->w) / 2, (SCREEN_H - choix1_1->h) / 2, choix1_1->w,//affichage de l'image
                     choix1_1->h);//affichage de l'image
                if (mouse_b & 1){//verification du clic
                    choixniv=1;//selection du niveau
                    a=1;//sortie de la boucle
                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112){//verification de la position de la souris
                blit(choix1_M, screen, 0, 0, (SCREEN_W - choix1_M->w) / 2, (SCREEN_H - choix1_M->h) / 2, choix1_M->w,//affichage de l'image
                     choix1_M->h);//affichage de l'image
                if (mouse_b & 1){//verification du clic
                    choixniv=0;//selection du niveau
                    a=1;//sortie de la boucle

                }
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 ||//verification de la position de la souris
                  mouse_y > 27 && mouse_y < 112)){//verification de la position de la souris
                blit(choix1, screen, 0, 0, (SCREEN_W - choix1->w) / 2, (SCREEN_H - choix1->h) / 2, choix1->w,//affichage de l'image
                     choix1->h);//affichage de l'image
            }

            if (key[KEY_UP]) {//verification de l'appui sur la touche
                fini = fini + 1;//incrementation de la variable
                sleep(1);//pause de 1 seconde
            }

        }
        if (fini == 1){//verification de la variable
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739){//verification de la position de la souris
                blit(choix2_1, screen, 0, 0, (SCREEN_W - choix2_1->w) / 2, (SCREEN_H - choix2_1->h) / 2, choix2_1->w,//affichage de l'image
                     choix2_1->h);//affichage de l'image
                if (mouse_b & 1){//verification du clic
                    choixniv=1;//selection du niveau
                    a=1;//sortie de la boucle
                }
            }
            if (mouse_x > 335 && mouse_x < 583 && mouse_y > 237 && mouse_y < 739){//verification de la position de la souris
                blit(choix2_2, screen, 0, 0, (SCREEN_W - choix2_2->w) / 2, (SCREEN_H - choix2_2->h) / 2, choix2_2->w,//affichage de l'image
                     choix2_2->h);//affichage de l'image
                if (mouse_b & 1){//verification du clic
                    choixniv =2;//selection du niveau
                    a=1;//sortie de la boucle

                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112) {
                blit(choix2_M, screen, 0, 0, (SCREEN_W - choix2_M->w) / 2, (SCREEN_H - choix2_M->h) / 2, choix2_M->w,
                     choix2_M->h);
                if (mouse_b & 1) {
                    choixniv = 0;
                    a = 1;

                }
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 335 && mouse_x < 583 ||
                  mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)) {
                blit(choix2, screen, 0, 0, (SCREEN_W - choix2->w) / 2, (SCREEN_H - choix2->h) / 2, choix2->w,
                     choix2->h);
            }
            if (key[KEY_UP]) {
                fini = fini + 1;
            }
            if (key[KEY_DOWN]) {
                fini = fini - 1;
            }
        }
        if (fini == 2) {
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739) {
                blit(choix3_1, screen, 0, 0, (SCREEN_W - choix3_1->w) / 2, (SCREEN_H - choix3_1->h) / 2, choix3_1->w,
                     choix3_1->h);
                if (mouse_b & 1) {
                    choixniv = 1;
                    a = 1;

                }
            }
            if (mouse_x > 335 && mouse_x < 583 && mouse_y > 237 && mouse_y < 739) {
                blit(choix3_2, screen, 0, 0, (SCREEN_W - choix3_2->w) / 2, (SCREEN_H - choix3_2->h) / 2, choix3_2->w,
                     choix3_2->h);
                if (mouse_b & 1) {
                    choixniv = 2;
                    a = 1;

                }
            }
            if (mouse_x > 625 && mouse_x < 876 && mouse_y > 237 && mouse_y < 739) {
                blit(choix3_3, screen, 0, 0, (SCREEN_W - choix3_3->w) / 2, (SCREEN_H - choix3_3->h) / 2, choix3_3->w,
                     choix3_3->h);
                if (mouse_b & 1) {
                    choixniv = 3;
                    a = 1;

                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112) {
                blit(choix3_M, screen, 0, 0, (SCREEN_W - choix3_M->w) / 2, (SCREEN_H - choix3_M->h) / 2, choix3_M->w,
                     choix3_M->h);
                if (mouse_b & 1) {
                    choixniv = 0;
                    a = 1;
                }
            }
            if (key[KEY_DOWN]) {
                fini = fini - 1;
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 335 && mouse_x < 583 || mouse_x > 625 && mouse_x < 876 ||
                  mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)) {
                blit(choix3, screen, 0, 0, (SCREEN_W - choix3->w) / 2, (SCREEN_H - choix3->h) / 2, choix3->w,
                     choix3->h);
            }
        }
    }
    destroy_bitmap(choix1);
    destroy_bitmap(choix1_1);
    destroy_bitmap(choix2);
    destroy_bitmap(choix2_1);
    destroy_bitmap(choix2_2);
    destroy_bitmap(choix3);
    destroy_bitmap(choix3_1);
    destroy_bitmap(choix3_2);
    destroy_bitmap(choix3_3);
    destroy_bitmap(choix1_M);
    destroy_bitmap(choix2_M);
    destroy_bitmap(choix3_M);
    show_mouse(NULL);

    return choixniv;


}
void imagefin(){
    install_mouse();
    show_mouse(screen);
    int verif=0;
    BITMAP * imagefin= load_bitmap("../images/imagefin.bmp", NULL);
    BITMAP * imagefinselect= load_bitmap("../images/imagefinselect.bmp", NULL);
    while(!verif){
        if(mouse_x>390&&mouse_x<530 && mouse_y>650 && mouse_y<715){
            blit(imagefinselect, screen, 0, 0, (SCREEN_W - imagefinselect->w) / 2, (SCREEN_H - imagefinselect->h) / 2, imagefinselect->w,imagefinselect->h);
            if(mouse_b & 1){
                verif=1;
            }
        }
        if(!(mouse_x>390&&mouse_x<530 && mouse_y>650 && mouse_y<715)){
            blit(imagefin, screen, 0, 0, (SCREEN_W - imagefin->w) / 2, (SCREEN_H - imagefin->h) / 2, imagefin->w,imagefin->h);
        }

    }
    destroy_bitmap(imagefinselect);
    destroy_bitmap(imagefin);


}
int jeu(int nivchoisi){
    int j1posx, j1posy;
    int j2posx, j2posy;
    int nbrecette=0;
    int deplacement = 10;
    int orienJ1=1;//
    int orienJ2=1;
    int recette[MAX_COMMANDES];
    int fin=0;
    int occupation=0;
    int fonction;
    int combinaison1=0;
    int combinaison2=0;

    time_t debut,actuel;
    double seconde;
    time(&debut);
    BITMAP * bouf1_1comm=load_bitmap("../images/commande riz.bmp",NULL);
    BITMAP * bouf2_1comm=load_bitmap("../images/commande sushi saumon.bmp",NULL);
    BITMAP * bouf3_1comm=load_bitmap("../images/commande sushi thon.bmp",NULL);
    BITMAP * bouf1_2comm=load_bitmap("../images/commande PTOMATE.bmp",NULL);
    BITMAP * bouf2_2comm=load_bitmap("../images/commande soupe.bmp",NULL);
    BITMAP * bouf3_2comm=load_bitmap("../images/commande stkfrt.bmp",NULL);
    BITMAP * bouf1_3comm=load_bitmap("../images/commande crepe nutella.bmp",NULL);
    BITMAP * bouf2_3comm=load_bitmap("../images/commande crepe au sucre.bmp",NULL);
    BITMAP * bouf3_3comm=load_bitmap("../images/commande crepe.bmp",NULL);

    BITMAP * buffer;
    BITMAP * PERSO1_O[4];
    BITMAP * PERSO2_O[4];



    if(nivchoisi==1){
        j1posx = 255, j1posy = 370;
        j2posx = 555, j2posy = 370;

    }
    if(nivchoisi==2){
        j1posx = SCREEN_W / 2, j1posy = SCREEN_H / 2;
        j2posx = SCREEN_W / 2, j2posy = SCREEN_H / 2;


    }
    if(nivchoisi==3){
        j1posx = SCREEN_W / 2, j1posy = SCREEN_H / 2;
        j2posx = SCREEN_W / 2, j2posy = SCREEN_H / 2;
    }
    //install_mouse();
    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    show_mouse(screen);
    affichagechargement();
    load_player_images(PERSO1_O,PERSO2_O);

    BITMAP * NIV1 = load_bitmap("../images/niv1.BMP",NULL);
    BITMAP * NIV2 = load_bitmap("../images/niv2.BMP",NULL);
    BITMAP * NIV3 = load_bitmap("../images/niv3.BMP",NULL);
    BITMAP * NIV1B1 = load_bitmap("../images/niv1B1.BMP",NULL);
    BITMAP * NIV1B2 = load_bitmap("../images/niv1B2.BMP",NULL);
    BITMAP * NIV2B1 = load_bitmap("../images/niv2B1.BMP",NULL);
    BITMAP * NIV2B2 = load_bitmap("../images/niv2B2.BMP",NULL);
    BITMAP * NIV3B1 = load_bitmap("../images/niv3B1.BMP",NULL);
    BITMAP * NIV3B2 = load_bitmap("../images/niv3B2.BMP",NULL);

    while (!key[KEY_DEL] && !fin) {

        time(&actuel);
        seconde = difftime(actuel, debut);

        fflush(stdout);

        if(nivchoisi==1){
            if(occupation==0){
                blit(NIV1, buffer, 0, 0, (SCREEN_W - NIV1->w) / 2, (SCREEN_H - NIV1->h) / 2, NIV1->w,NIV1->h);
            }
            if(occupation==1){
                blit(NIV1B1, buffer, 0, 0, (SCREEN_W - NIV1B1->w) / 2, (SCREEN_H - NIV1B1->h) / 2, NIV1B1->w,NIV1B1->h);
            }
            if(occupation==2){
                blit(NIV1B2, buffer, 0, 0, (SCREEN_W - NIV1B2->w) / 2, (SCREEN_H - NIV1B2->h) / 2, NIV1B2->w,NIV1B2->h);
            }
            if (j1posx <= 60) j1posx = 60;
            if (j1posx >= 705) j1posx = 705;        // collision tour de cuissine (commun a tous les niveaux)
            if (j1posy <= 175) j1posy = 175;
            if (j1posy >=625) j1posy = 625;

            if (j2posx <= 60) j2posx = 60;
            if (j2posx >= 705) j2posx = 705;
            if (j2posy <= 175) j2posy = 175;        // collision tour de cuissine (commun a tous les niveaux)
            if (j2posy >=625) j2posy = 625;

            if (j1posx >= 60 && j1posx <= 150 && j1posy >= 205 && j1posy <= 520) {
                j1posx = 150;
                if(key[KEY_L] && orienJ1==4){
                    menu_cru(buffer,nivchoisi, combinaison1, combinaison2);
                }
            }

            putpixel(buffer, j1posx,j1posy, makecol(0,0,0));

            if (j1posx >= 140 && j1posx <= 500 && j1posy >= 530 && j1posy <= 700) {
                j1posy = 530;
                if(key[KEY_L] && orienJ1==3){

                    occupation++;
                    if(occupation<0){
                        occupation=0;
                    }
                    if (occupation>2){
                        occupation=2;
                    }
                }
            }
            if (j1posx >= 315 && j1posx <= 500 && j1posy >= 180 && j1posy <= 600) {
                j1posx = 315;
                if(key[KEY_L] && orienJ1==2){
                    allegro_message("prise");
                }
            }
            if (j1posx >= 160 && j1posx <= 780 && j1posy >= 188 && j1posy <= 240) {
                j1posy = 240;
                if(key[KEY_L] && orienJ1==1){
                    allegro_message("prise");
                }
            }
            if (j2posx >= 160 && j2posx <= 450 && j2posy >= 530 && j2posy <= 700) {
                j2posy = 470;
                if(key[KEY_C]){
                    allegro_message("prise");
                }
            }
            if (j2posx >= 315 && j2posx <= 470 && j2posy >= 180 && j2posy <= 600) {
                j2posx = 470;
                if(key[KEY_C]){
                    allegro_message("prise");
                }
            }
            if (j2posx >= 160 && j2posx <= 780 && j2posy >= 188 && j2posy <= 260) {
                j2posy = 260;
                if(key[KEY_C] && orienJ2==1){
                    allegro_message("prise");
                }
            }
            if (j2posx >= 610 && j2posx <= 705 && j2posy >= 340 && j2posy <= 550) {
                j2posx = 610;
                if(key[KEY_C]){
                    allegro_message("prise");
                }
            }

        }

        if(nivchoisi==2){
            if(occupation == 0){
                blit(NIV2, buffer, 0, 0, (SCREEN_W - NIV2->w) / 2, (SCREEN_H - NIV2->h) / 2, NIV2->w, NIV2->h);
            }
            if(occupation == 1){
                blit(NIV2B1, buffer, 0, 0, (SCREEN_W - NIV2B1->w) / 2, (SCREEN_H - NIV2B1->h) / 2, NIV2B1->w, NIV2B1->h);
            }
            if(occupation == 2){
                blit(NIV2B2, buffer, 0, 0, (SCREEN_W - NIV2B2->w) / 2, (SCREEN_H - NIV2B2->h) / 2, NIV2B2->w, NIV2B2->h);
            }

            if (j1posx <= 20) j1posx = 20;
            if (j1posx >= 705) j1posx = 705;        // collision tour de cuissine (commun a tous les niveaux)
            if (j1posy <= 175) j1posy = 175;
            if (j1posy >=625) j1posy = 625;

            if (j2posx <= 20) j2posx = 20;
            if (j2posx >= 705) j2posx = 705;
            if (j2posy <= 175) j2posy = 175;        // pour le j2
            if (j2posy >=625) j2posy = 625;



            if (j1posx >= 0 && j1posx <= 270 && j1posy >= 400 && j1posy <= 600) {
                j1posx = 270;
                if(key[KEY_L]){
                    allegro_message("prise");
                }
            }

            if (j1posx >= 200 && j1posx <= 420 && j1posy >= 100 && j1posy <= 372) {
                j1posy = 372;
                if(key[KEY_L]){
                    allegro_message("prise");

                }
            }

            if (j1posx >= 530 && j1posx <= 800 && j1posy >= 320 && j1posy <= 480) {
                j1posx = 530;
                if(key[KEY_L]){

                    occupation++;
                    if(occupation<0){
                        occupation=0;
                    }
                    if (occupation>2){
                        occupation=2;
                    }
                }
            }
            if (j2posx >= 0 && j2posx <= 270 && j2posy >= 400 && j2posy <= 600) {
                j2posx = 270;
                if(key[KEY_C]){
                    allegro_message("prise");
                }
            }

            if (j2posx >= 200 && j2posx <= 420 && j2posy >= 100 && j2posy <= 372) {
                j2posy = 372;
                if(key[KEY_C]){
                    allegro_message("prise");
                }
            }

            if (j2posx >= 530 && j2posx <= 800 && j2posy >= 320 && j2posy <= 480) {
                j2posx = 530;
                if(key[KEY_C]){

                    occupation++;
                    if(occupation<0){
                        occupation=0;
                    }
                    if (occupation>2){
                        occupation=2;
                    }
                }
            }
        }


        if(nivchoisi==3){
            if(occupation == 0){
                blit(NIV3, buffer, 0, 0, (SCREEN_W - NIV3->w) / 2, (SCREEN_H - NIV3->h) / 2, NIV3->w, NIV3->h);
            }
            if(occupation == 1){
                blit(NIV3B1, buffer, 0, 0, (SCREEN_W - NIV3B1->w) / 2, (SCREEN_H - NIV3B1->h) / 2, NIV3B1->w, NIV3B1->h);
            }
            if(occupation == 2){
                blit(NIV3B2, buffer, 0, 0, (SCREEN_W - NIV3B2->w) / 2, (SCREEN_H - NIV3B2->h) / 2, NIV3B2->w, NIV3B2->h);
            }
            textprintf_ex(buffer, font, 60, 120, makecol(0, 0, 0), -1, "j1 : %4d %4d", j1posx, j1posy);
            textprintf_ex(buffer, font, 60, 100, makecol(0, 0, 0), -1, "j2 : %4d %4d", j2posx, j2posy);

            if (j1posx <= 60) j1posx = 60;
            if (j1posx >= 705) j1posx = 705; // collision tour de cuisine (commun a tous les niveaux)
            if (j1posy <= 175) j1posy = 175;
            if (j1posy >=625) j1posy = 625;

            if (j2posx <= 60) j2posx = 60;
            if (j2posx >= 705) j2posx = 705;
            if (j2posy <= 175) j2posy = 175; // collision tour de cuisine (commun a tous les niveaux)
            if (j2posy >=625) j2posy = 625;

            if (j1posx >= 640){
                j1posx = 640;
                if(key[KEY_L] && orienJ1==2){
                    allegro_message("prise");
                }
            }
            if (j1posx <= 170){
                j1posx = 170;
                if(key[KEY_L] && orienJ1==4){
                    allegro_message("prise");
                }

            }
            if (j1posy <= 275){
                j1posy = 275;
                if(key[KEY_L] && orienJ1==1){

                    if(j1posx>=230 && j1posx<=260){
                        occupation++;
                        if(occupation<0){
                            occupation=0;
                        }
                        if (occupation>2){
                            occupation=2;
                        }
                    }
                }
            }
            if (j1posy >= 575){
                j1posy = 575;
                if(key[KEY_L] && orienJ1==3){

                    if(j1posx>=230 && j1posx<=260){
                        occupation++;
                        if(occupation<0){
                            occupation=0;
                        }
                        if (occupation>2){
                            occupation=2;
                        }
                    }
                }
            }
            if (j2posx >= 640){
                j2posx = 640;
                if(key[KEY_C] && orienJ2 == 2){
                    allegro_message("prise");
                }
            }
            if (j2posx <= 170){
                j2posx = 170;
                if(key[KEY_C] && orienJ2 == 4){
                    allegro_message("prise");
                }
            }
            if (j2posy <= 275){
                j2posy = 275;
                if(key[KEY_C] && orienJ2 == 1){

                    if(j2posx>=230 && j2posx<=260){
                        occupation++;
                        if(occupation<0){
                            occupation=0;
                        }
                        if (occupation>2){
                            occupation=2;
                        }
                    }
                }
            }
            if (j2posy >= 575){
                j2posy = 575;
                if(key[KEY_C] && orienJ2 == 3){

                    if(j2posx>=230 && j2posx<=260){
                        occupation++;
                        if(occupation<0){
                            occupation=0;
                        }
                        if (occupation>2){
                            occupation=2;
                        }
                    }
                }
            }
        }
        if(key[KEY_E]){
            occupation--;
            if(occupation<0){
                occupation=0;
            }
            if (occupation>2){
                occupation=2;
            }
        }

        if (key[KEY_UP]) {j1posy -= deplacement; orienJ1=1; }
        if (key[KEY_DOWN]) {j1posy += deplacement; orienJ1=3;}
        if (key[KEY_LEFT]) {j1posx -= deplacement; orienJ1=4;}
        if (key[KEY_RIGHT]) {j1posx += deplacement; orienJ1=2;}
        // déplacement des joueurs sur la bord
        if (key[KEY_W]) {j2posy -= deplacement; orienJ2=1;}
        if (key[KEY_S]) {j2posy += deplacement; orienJ2=3;}
        if (key[KEY_A]) {j2posx -= deplacement; orienJ2=4;}
        if (key[KEY_D]) {j2posx += deplacement; orienJ2=2;}


        image_joueur(buffer,PERSO1_O,PERSO2_O,j1posx, j1posy, j2posx, j2posy,orienJ1,orienJ2);
        if(nivchoisi==1){
            nbrecette=gerer_commandes(buffer,nbrecette,bouf1_1comm,bouf2_1comm,bouf3_1comm,recette,0);
        }
        if(nivchoisi==2){
            nbrecette=gerer_commandes(buffer,nbrecette,bouf1_2comm,bouf2_2comm,bouf3_2comm,recette,0);
        }
        if (nivchoisi==3){
            nbrecette=gerer_commandes(buffer,nbrecette,bouf1_3comm,bouf2_3comm,bouf3_3comm,recette,0);
        }

        textprintf_ex(buffer, font, 60, 140, makecol(0, 0, 0), -1, "mouse : %4d %4d", mouse_x, mouse_y);
        textprintf_ex(buffer,font,700,700, makecol(255,255,255),-1,"%.1f / 180", seconde);
        blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(40);
        if (seconde >= 180){
            fin = 1;
        }
    }
    // Destruction des bitmaps chargés
    destroy_bitmap(buffer);
    destroy_bitmap(bouf1_1comm);
    destroy_bitmap(bouf2_1comm);
    destroy_bitmap(bouf3_1comm);
    destroy_bitmap(bouf1_2comm);
    destroy_bitmap(bouf2_2comm);
    destroy_bitmap(bouf3_2comm);
    destroy_bitmap(NIV1);destroy_bitmap(NIV1B1);destroy_bitmap(NIV1B2);
    destroy_bitmap(NIV2);destroy_bitmap(NIV2B1);destroy_bitmap(NIV2B2);
    destroy_bitmap(NIV3);
    imagefin();
    return 0;
}
void tuto(){
    BITMAP *tutoP1= load_bitmap("../images/tuto1.bmp",NULL);
    BITMAP *tutoP2= load_bitmap("../images/tuto2.bmp",NULL);
    BITMAP *tutoP3= load_bitmap("../images/tuto3.bmp",NULL);
    BITMAP *tutoP4= load_bitmap("../images/tuto4.bmp",NULL);
    int compteur_page_tuto=1;
    install_keyboard();
    while(compteur_page_tuto<=MAX_PAGE_TUTO+1){
        rest(100);
        if(key[KEY_RIGHT]){
            compteur_page_tuto+=1;
        }
        if(key[KEY_LEFT]){
            compteur_page_tuto-=1;
        }
        if(key[KEY_SPACE] || key[KEY_ESC]){
            destroy_bitmap(tutoP1);//on détruit les bitmaps
            destroy_bitmap(tutoP2);//on détruit les bitmaps
            destroy_bitmap(tutoP3);//on détruit les bitmaps
            destroy_bitmap(tutoP4);//on détruit les bitmaps
            return;
        }
        if(compteur_page_tuto>MAX_PAGE_TUTO){
            compteur_page_tuto=MAX_PAGE_TUTO;//on ne peut pas aller au dessus de 4
        }
        if(compteur_page_tuto<0){
            compteur_page_tuto=0;//on ne peut pas aller en dessous de 0
        }

        switch(compteur_page_tuto){
            case 1:
                blit(tutoP1, screen, 0, 0, (SCREEN_W - tutoP1->w) / 2, (SCREEN_H - tutoP1->h) / 2, tutoP1->w,tutoP1->h);
                textprintf_ex(screen, font, SCREEN_W/2 -90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 2:
                blit(tutoP2, screen, 0, 0, (SCREEN_W - tutoP2->w) / 2, (SCREEN_H - tutoP2->h) / 2, tutoP2->w, tutoP2->h);
                textprintf_ex(screen, font, SCREEN_W/2 -90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 3:
                blit(tutoP3, screen, 0, 0, (SCREEN_W - tutoP3->w) / 2, (SCREEN_H - tutoP3->h) / 2, tutoP3->w, tutoP3->h);
                textprintf_ex(screen, font, SCREEN_W/2 -90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 4:
                blit(tutoP4, screen, 0, 0, (SCREEN_W - tutoP4->w) / 2, (SCREEN_H - tutoP4->h) / 2, tutoP4->w, tutoP4->h);
                textprintf_ex(screen, font, SCREEN_W/2 -90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
        }
    }
}
void affiche_score(){
    BITMAP *Score= load_bitmap("../images/Score.bmp",NULL);//on charge l'image du score
    while(key[KEY_SPACE]==0){//tant que la touche espace n'est pas appuyé
        blit(Score, screen, 0, 0, (SCREEN_W - Score->w) / 2, (SCREEN_H - Score->h) / 2, Score->w,Score->h);
    }
    destroy_bitmap(Score);//on détruit l'image du score
}

    //commsss

/*void score(){
    FILE *saveScore = NULL;
    saveScore = fopen("SauvegardeScore.txt", "r");
    int score;
    int niveau;
    if (saveScore != NULL) {
        while (!feof(saveScore)) {
            fscanf(saveScore, "%d\n%d\n", &niveau, &score);
            printf("niveau : %d score : %d\n", niveau, score);
        }
        fclose(saveScore);
    } else {
        printf("impossible de lire le fichier");
    }
}


/*
    // on affiche un menu pour demande si le joueur veut enregistrer son score
    printf("enregistrer Score :");
    locate(3,14);
    printf("oui(o) ou non(n)");
    int reponse;        // on initialise un entier 'reponse'
    do {                // on execute la boucle une première fois même si la condition n'est pas respecté
        reponse = getch();      // on la touche appuyé dans la variable 'reponse'
        if (reponse == 111) {   // si la touche appuyé est 'o'
            FILE *saveScore = NULL; // on inititalise un pointeur sur NULL
            saveScore = fopen("SauvegardeScore.txt", "a"); //on ouvre le ficher de sauvegarde des scores sur ce pointeur en mode ajout
            if (saveScore != NULL) {
                fprintf(saveScore, "%d\n%d\n", niveau, score);      // on écrit à la suite du fichier le niveau et le score sur 2 lignes différentes
                fclose(saveScore);                                            // on referme ensuite le fichier
            } else {                //sinon c'est que le fichier n'a pas réussi à être ouvert
                locate(0, 18);
                printf("impossible de sauvegarder le score");       // on affcihe donc un message d'erreur
            }
        }
    }while(reponse != 111 && reponse != 110);       //boucle que l'on répète tant que la touche appuyé est autre que 'n' ou 'o'
}*/
/*void affichagechargement(){
    BITMAP *chargement= load_bitmap("../images/chargement.bmp",NULL);
    blit(chargement, screen, 0, 0, (SCREEN_W - chargement->w) / 2, (SCREEN_H - chargement->h) / 2, chargement->w,chargement->h);
    rest(2000);
    destroy_bitmap(chargement);
}
void load_player_images(BITMAP *PERSO1_O[],BITMAP *PERSO2_O[]){
    PERSO1_O[0] = load_bitmap("../images/PERSO1_O1.bmp", NULL);
    PERSO1_O[1] = load_bitmap("../images/PERSO1_O2.bmp", NULL);
    PERSO1_O[2] = load_bitmap("../images/PERSO1_O3.bmp", NULL);
    PERSO1_O[3] = load_bitmap("../images/PERSO1_O4.bmp", NULL);
    PERSO2_O[0] = load_bitmap("../images/PERSO2_O1.bmp", NULL);
    PERSO2_O[1] = load_bitmap("../images/PERSO2_O2.bmp", NULL);
    PERSO2_O[2] = load_bitmap("../images/PERSO2_O3.bmp", NULL);
    PERSO2_O[3] = load_bitmap("../images/PERSO2_O4.bmp", NULL);
}*/