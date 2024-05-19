#include "librairies.h"



void affichagechargement(){//fonction qui affiche l'image de charg
    set_trans_blender(0, 255, 0, 0);//définition de la couleur de transparence
    BITMAP *imagechargement = load_bitmap("../images/ece cook chargement.bmp", NULL);//chargement de l'image
    if (!imagechargement){//si l'image n'est pas chargée
        allegro_message("Erreur de chargement de l'image");//affichage d'un message d'erreur
        return;//sortie de la fonction
    }
    blit(imagechargement, screen, 0, 0, (SCREEN_W - imagechargement->w) / 2, (SCREEN_H - imagechargement->h) / 2, imagechargement->w, imagechargement->h);//affichage de l'image
    textprintf_ex(screen, font, 320, 750, makecol(0, 0, 0), -1, "Appuyez sur ESPACE pour continuer");//affichage d'un message
    while (!key[KEY_SPACE]){//tant que la touche ESPACE n'est pas appuyée
        rest(100);//pause de 100 ms
    }
    destroy_bitmap(imagechargement);//libération de la mémoire
}

void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]){//fonction qui charge les images des joueurs
    PERSO1_O[0] = load_bitmap("../images/perso1O1.bmp", NULL);//chargement de l'image
    PERSO1_O[1] = load_bitmap("../images/perso1O2.bmp", NULL);
    PERSO1_O[2] = load_bitmap("../images/perso1O3.bmp", NULL);
    PERSO1_O[3] = load_bitmap("../images/perso1O4.bmp", NULL);

    PERSO2_O[0] = load_bitmap("../images/perso2O1.bmp", NULL);
    PERSO2_O[1] = load_bitmap("../images/perso2O2.bmp", NULL);
    PERSO2_O[2] = load_bitmap("../images/perso2O3.bmp", NULL);
    PERSO2_O[3] = load_bitmap("../images/perso2O4.bmp", NULL);
}

void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], Joueur joueur1, Joueur joueur2){//fonction qui affiche les images des joueurs
    if (joueur1.orientation >= 1 && joueur1.orientation <= 4){//si l'orientation du joueur est valide
        draw_sprite(buffer, PERSO1_O[joueur1.orientation - 1], joueur1.posx, joueur1.posy);//affichage de l'image du joueur
    }
    if (joueur2.orientation >= 1 && joueur2.orientation <= 4){//si l'orientation du joueur est valide
        draw_sprite(buffer, PERSO2_O[joueur2.orientation - 1], joueur2.posx, joueur2.posy);//affichage de l'image du joueur
    }
}

int gerer_commandes(BITMAP *buffer, int recettes, BITMAP *recette1, BITMAP *recette2, BITMAP *recette3, int recette[MAX_COMMANDES], int index,int fonction,int combinaison,int score){//fonction qui gère les commandes
    if(fonction==1) {
        BITMAP *recettesDisponibles[3] = {recette1, recette2, recette3};//tableau des recettes
        int random = rand() % 250;//génération d'un nombre aléatoire
        if (random == 1 && recettes <MAX_COMMANDES) {//si le nombre aléatoire est égal à 1 et qu'il y a moins de commandes que le nombre maximal de commandes
            recette[recettes] = rand() % 3;//génération d'un nombre aléatoire
            recettes++;//incrémentation du nombre de commandes
        }

        if (key[KEY_U]) {//si la touche U est appuyée
            if (index < 0 || index >= recettes) {//si l'index est invalide
                allegro_message("Index invalide pour la suppression: %d\n", index);//affichage d'un message d'erreur
                return recettes;//retourne le nombre de commandes
            }
            for (int i = index; i < recettes - 1; i++) {//pour chaque commande
                recette[i] = recette[i + 1];//décalage des commandes
            }
            recettes--;//décrémentation du nombre de commandes
        }
        for (int i = 0; i < recettes; i++) {//pour chaque commande
            draw_sprite(buffer, recettesDisponibles[recette[i]], 20 + (200 * i), -100);//affichage de la commande
        }
        return recettes;
    }
    if (fonction == 2) {
        for (int i = 0; i < recettes; i++) {
            int commande = recette[i];

            if ((commande == 0 && combinaison == 4) ||
                (commande == 2 && combinaison == 5) ||
                (commande == 1 && combinaison == 6)) {

                // Supprimer la commande associée à la combinaison
                for (int j = i; j < recettes - 1; j++) {
                    recette[j] = recette[j + 1];
                }
                recettes--; // Décrémente le nombre de commandes
                combinaison = 0; // Réinitialiser la combinaison
                sleep(1);
                // Sortir de la boucle car nous avons trouvé et supprimé la commande associée
                score=+100;

                return score;
            }
        }
    }

}

int menu_cru(BITMAP *buffer, int nivchoisi, int combinaison, int capte){//fonction qui gère le menu des ingrédients crus
    BITMAP *A0 = load_bitmap("../images/menucru niv1.bmp", NULL);//chargement de l'image
    BITMAP *A1 = load_bitmap("../images/menucru niv1_1.bmp", NULL);
    BITMAP *A2 = load_bitmap("../images/menucru niv1_2.bmp", NULL);
    BITMAP *A3 = load_bitmap("../images/menucru niv1_3.bmp", NULL);

    if (nivchoisi==1){//si le niveau choisi est le niveau 1
        draw_sprite(buffer, A0, 450, 400);//affichage de l'image
        if (mouse_y >= 480 && mouse_y <= 513){//si la souris est sur la zone de l'image
            draw_sprite(buffer, A1, 450, 400);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                combinaison=1;//définition de la combinaison
                allegro_message("vous avez pris un thon");//affichage d'un message
            }
        }
        if (mouse_y >= 513 && mouse_y <= 600){//si la souris est sur la zone de l'image
            draw_sprite(buffer, A2, 450, 400);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                combinaison=2;//définition de la combinaison
                allegro_message("vous avez pris un saumon");//affichage d'un message
            }
        }
        if (mouse_y >= 600 && mouse_y <= 700){//si la souris est sur la zone de l'image
            draw_sprite(buffer, A3, 450, 400);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                combinaison=3;//définition de la combinaison
                allegro_message("vous avez pris du riz cru");//affichage d'un message
            }
        }
    }
    destroy_bitmap(A0);//libération de la mémoire
    destroy_bitmap(A1);
    destroy_bitmap(A2);
    destroy_bitmap(A3);

    return combinaison;//retourne la combinaison
}

int menu(){//fonction qui affiche le menu
    install_mouse();//initialisation de la souris
    show_mouse(screen);//affichage de la souris
    BITMAP *menuneutre = load_bitmap("../images/menuneutre.bmp", NULL);//chargement de l'image
    BITMAP *menu1 = load_bitmap("../images/menu1.bmp", NULL);
    BITMAP *menu2 = load_bitmap("../images/menu2.bmp", NULL);
    BITMAP *menu3 = load_bitmap("../images/menu3.bmp", NULL);
    int a=0;//initialisation de la variable
    int selection;//initialisation de la variable
    blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);//affichage de l'image

    while (a==0){//tant que a est égal à 0
        if (mouse_x >= 155 && mouse_x <= 313 && mouse_y >= 572 && mouse_y <= 658){//si la souris est sur la zone de l'image
            blit(menu1, screen, 0, 0, (SCREEN_W - menu1->w) / 2, (SCREEN_H - menu1->h) / 2, menu1->w, menu1->h);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                a=1;//définition de la variable
                selection=1;//définition de la variable
            }
        }
        if (mouse_x >= 368 && mouse_x <= 538 && mouse_y >= 572 && mouse_y <= 658){//si la souris est sur la zone de l'image
            blit(menu2, screen, 0, 0, (SCREEN_W - menu2->w) / 2, (SCREEN_H - menu2->h) / 2, menu2->w, menu2->h);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                a=1;//définition de la variable
                selection=2;//définition de la variable
            }
        }
        if (mouse_x >= 585 && mouse_x <= 752 && mouse_y >= 572 && mouse_y <= 658){//si la souris est sur la zone de l'image
            blit(menu3, screen, 0, 0, (SCREEN_W - menu3->w) / 2, (SCREEN_H - menu3->h) / 2, menu3->w, menu3->h);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                a=1;//définition de la variable
                selection=3;//définition de la variable
            }
        }
        if (mouse_x >= 487 && mouse_x <= 634 && mouse_y >= 715 && mouse_y <= 762){//si la souris est sur la zone de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                allegro_exit();//sortie de allegro
            }
        }
        if (!(mouse_x >= 155 && mouse_x <= 313 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 368 && mouse_x <= 538 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 585 && mouse_x <= 752 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 487 && mouse_x <= 634 && mouse_y >= 715 && mouse_y <= 762)) {
            blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);//affichage de l'image
        }
    }
    destroy_bitmap(menuneutre);//libération de la mémoire
    destroy_bitmap(menu1);
    destroy_bitmap(menu2);
    destroy_bitmap(menu3);
    return selection;
}

int selectniv(int fini){//fonction qui affiche les niveaux
    install_mouse();//initialisation de la souris
    show_mouse(screen);//affichage de la souris
    int a=0;//initialisation de la variable
    int choixniv;//initialisation de la variable
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

    while (a == 0){//tant que a est égal à 0
        if (fini == 0){//si fini est égal à 0
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739){//si la souris est sur la zone de l'image
                blit(choix1_1, screen, 0, 0, (SCREEN_W - choix1_1->w) / 2, (SCREEN_H - choix1_1->h) / 2, choix1_1->w, choix1_1->h);//affichage de l'image
                if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                    choixniv=1;//définition de la variable
                    a=1;//définition de la variable
                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112){//si la souris est sur la zone de l'image
                blit(choix1_M, screen, 0, 0, (SCREEN_W - choix1_M->w) / 2, (SCREEN_H - choix1_M->h) / 2, choix1_M->w, choix1_M->h);//affichage de l'image
                if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                    choixniv=0;//définition de la variable
                    a=1;//définition de la variable
                }
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)){//si la souris n'est pas sur la zone de l'image
                blit(choix1, screen, 0, 0, (SCREEN_W - choix1->w) / 2, (SCREEN_H - choix1->h) / 2, choix1->w, choix1->h);//affichage de l'image
            }

            if (key[KEY_UP]){//si la touche HAUT est appuyée
                fini=fini+1;//incrémentation de la variable
                sleep(1);//pause de 1 seconde
            }
        }
        if (fini == 1){//si fini est égal à 1
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739){//si la souris est sur la zone de l'image
                blit(choix2_1, screen, 0, 0, (SCREEN_W - choix2_1->w) / 2, (SCREEN_H - choix2_1->h) / 2, choix2_1->w, choix2_1->h);
                if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                    choixniv=1;//définition de la variable
                    a=1;//définition de la variable
                }
            }
            if (mouse_x > 335 && mouse_x < 583 && mouse_y > 237 && mouse_y < 739) {
                blit(choix2_2, screen, 0, 0, (SCREEN_W - choix2_2->w) / 2, (SCREEN_H - choix2_2->h) / 2, choix2_2->w, choix2_2->h);
                if (mouse_b & 1) {
                    choixniv = 2;
                    a = 1;
                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112) {
                blit(choix2_M, screen, 0, 0, (SCREEN_W - choix2_M->w) / 2, (SCREEN_H - choix2_M->h) / 2, choix2_M->w, choix2_M->h);
                if (mouse_b & 1) {
                    choixniv = 0;
                    a = 1;
                }
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 335 && mouse_x < 583 || mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)) {
                blit(choix2, screen, 0, 0, (SCREEN_W - choix2->w) / 2, (SCREEN_H - choix2->h) / 2, choix2->w, choix2->h);
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
                blit(choix3_1, screen, 0, 0, (SCREEN_W - choix3_1->w) / 2, (SCREEN_H - choix3_1->h) / 2, choix3_1->w, choix3_1->h);
                if (mouse_b & 1) {
                    choixniv = 1;
                    a = 1;
                }
            }
            if (mouse_x > 335 && mouse_x < 583 && mouse_y > 237 && mouse_y < 739) {
                blit(choix3_2, screen, 0, 0, (SCREEN_W - choix3_2->w) / 2, (SCREEN_H - choix3_2->h) / 2, choix3_2->w, choix3_2->h);
                if (mouse_b & 1) {
                    choixniv = 2;
                    a = 1;
                }
            }
            if (mouse_x > 625 && mouse_x < 876 && mouse_y > 237 && mouse_y < 739) {
                blit(choix3_3, screen, 0, 0, (SCREEN_W - choix3_3->w) / 2, (SCREEN_H - choix3_3->h) / 2, choix3_3->w, choix3_3->h);
                if (mouse_b & 1) {
                    choixniv = 3;
                    a = 1;
                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112) {
                blit(choix3_M, screen, 0, 0, (SCREEN_W - choix3_M->w) / 2, (SCREEN_H - choix3_M->h) / 2, choix3_M->w, choix3_M->h);
                if (mouse_b & 1) {
                    choixniv = 0;
                    a = 1;
                }
            }
            if (key[KEY_DOWN]) {
                fini = fini - 1;
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 335 && mouse_x < 583 || mouse_x > 625 && mouse_x < 876 || mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)) {
                blit(choix3, screen, 0, 0, (SCREEN_W - choix3->w) / 2, (SCREEN_H - choix3->h) / 2, choix3->w, choix3->h);
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

void tables(Joueur *joueur, int *table, int nivchoisi) {
    if (joueur->combinaison == 0 && *table != 0) {
        printf("rentrez");
        joueur->combinaison = *table;
        if (joueur->combinaison == 1) {
            allegro_message("thon pris");
            *table = 0;
        } else if (joueur->combinaison == 2) {
            allegro_message("saumon pris");
            *table = 0;
        } else if (joueur->combinaison == 4) {
            allegro_message("riz cuit pris");
            *table = 0;
        } else if (joueur->combinaison == 5) {
            allegro_message("sushi thon pris");
            *table = 0;
        } else if (joueur->combinaison == 6) {
            allegro_message("sushi saumon pris");
            *table = 0;
        }
    } else if (*table == 0 && joueur->combinaison != 3) {
        *table = joueur->combinaison;
        if (*table == 1) {
            allegro_message("vous avez posé du thon");
            joueur->combinaison = 0;
        } else if (*table == 2) {
            allegro_message("vous avez posé du saumon");
            joueur->combinaison = 0;
        } else if (*table == 4) {
            allegro_message("vous avez posé du riz cuit");
            joueur->combinaison = 0;
        }
    } else if ((*table == 1 || *table == 2) && joueur->combinaison == 4) {
        joueur->combinaison += *table;
        if (joueur->combinaison == 5) {
            allegro_message("vous avez combiné un sushi thon");
            joueur->combinaison = 0;
            *table=5;
        } else if (joueur->combinaison == 6) {
            allegro_message("vous avez combiné un sushi saumon");
            joueur->combinaison = 0;
            *table=6;
        }
    } else if ((joueur->combinaison == 1 || joueur->combinaison == 2) && *table == 4) {
        joueur->combinaison += *table;
        if (joueur->combinaison == 5) {
            allegro_message("vous avez combiné un sushi thon");
            joueur->combinaison = 0;
            *table=5;
        } else if (joueur->combinaison == 6) {
            allegro_message("vous avez combiné un sushi saumon");
            joueur->combinaison = 0;
            *table= 6;
        }
    }else if (*table == 3) {
        allegro_message("vous ne pouvez pas poser du riz cru");
        *table = 0;
        joueur->combinaison = 3;
    }
    if(key[KEY_H]){
        joueur->combinaison = 0;
        *table = 0;
    }
}

int jeu(int nivchoisi) {
    Joueur joueur1, joueur2;
    int nbrecette = 0;
    int deplacement = 10;
    int recette[MAX_COMMANDES];
    int fin = 0;
    int occupation = 0;
    int table = 0;
    int score = 0;

    time_t debut, actuel;
    double seconde;
    time(&debut);
    BITMAP *bouf1_1comm = load_bitmap("../images/commande riz.bmp", NULL);
    BITMAP *bouf2_1comm = load_bitmap("../images/commande sushi saumon.bmp", NULL);
    BITMAP *bouf3_1comm = load_bitmap("../images/commande sushi thon.bmp", NULL);
    BITMAP *bouf1_2comm = load_bitmap("../images/commande PTOMATE.bmp", NULL);
    BITMAP *bouf2_2comm = load_bitmap("../images/commande soupe.bmp", NULL);
    BITMAP *bouf3_2comm = load_bitmap("../images/commande stkfrt.bmp", NULL);
    BITMAP *bouf1_3comm = load_bitmap("../images/commande crepe nutella.bmp", NULL);
    BITMAP *bouf2_3comm = load_bitmap("../images/commande crepe au sucre.bmp", NULL);
    BITMAP *bouf3_3comm = load_bitmap("../images/commande crepe.bmp", NULL);

    BITMAP *buffer;
    BITMAP *PERSO1_O[4];
    BITMAP *PERSO2_O[4];

    if (nivchoisi == 1) {
        joueur1.posx = 255;
        joueur1.posy = 370;
        joueur2.posx = 555;
        joueur2.posy = 370;
    }
    if (nivchoisi == 2) {
        joueur1.posx = SCREEN_W / 2;
        joueur1.posy = SCREEN_H / 2;
        joueur2.posx = SCREEN_W / 2;
        joueur2.posy = SCREEN_H / 2;
    }
    if (nivchoisi == 3) {
        joueur1.posx = SCREEN_W / 2;
        joueur1.posy = SCREEN_H / 2;
        joueur2.posx = SCREEN_W / 2;
        joueur2.posy = SCREEN_H / 2;
    }

    joueur1.combinaison = 0;
    joueur2.combinaison = 0;
    joueur1.orientation = 1;
    joueur2.orientation = 1;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    show_mouse(screen);
    affichagechargement();
    load_player_images(PERSO1_O, PERSO2_O);

    BITMAP *NIV1 = load_bitmap("../images/niv1.BMP", NULL);
    BITMAP *NIV2 = load_bitmap("../images/niv2.BMP", NULL);
    BITMAP *NIV3 = load_bitmap("../images/niv3.BMP", NULL);
    BITMAP *NIV1B1 = load_bitmap("../images/niv1B1.BMP", NULL);
    BITMAP *NIV1B2 = load_bitmap("../images/niv1B2.BMP", NULL);
    BITMAP *NIV2B1 = load_bitmap("../images/niv2B1.BMP", NULL);
    BITMAP *NIV2B2 = load_bitmap("../images/niv2B2.BMP", NULL);
    BITMAP *NIV3B1 = load_bitmap("../images/niv3B1.BMP", NULL);
    BITMAP *NIV3B2 = load_bitmap("../images/niv3B2.BMP", NULL);

    while (!key[KEY_DEL] && !fin) {
        time(&actuel);
        seconde = difftime(actuel, debut);

        fflush(stdout);

        if (nivchoisi == 1) {
            if (occupation == 0) {
                blit(NIV1, buffer, 0, 0, (SCREEN_W - NIV1->w) / 2, (SCREEN_H - NIV1->h) / 2, NIV1->w, NIV1->h);
            }
            if (occupation == 1) {
                blit(NIV1B1, buffer, 0, 0, (SCREEN_W - NIV1B1->w) / 2, (SCREEN_H - NIV1B1->h) / 2, NIV1B1->w, NIV1B1->h);
            }
            if (occupation == 2) {
                blit(NIV1B2, buffer, 0, 0, (SCREEN_W - NIV1B2->w) / 2, (SCREEN_H - NIV1B2->h) / 2, NIV1B2->w, NIV1B2->h);
            }
            if (joueur1.posx <= 60) joueur1.posx = 60;
            if (joueur1.posx >= 705) joueur1.posx = 705;
            if (joueur1.posy <= 175) joueur1.posy = 175;
            if (joueur1.posy >= 625) joueur1.posy = 625;

            if (joueur2.posx <= 60) joueur2.posx = 60;
            if (joueur2.posx >= 705) joueur2.posx = 705;
            if (joueur2.posy <= 175) joueur2.posy = 175;
            if (joueur2.posy >= 625) joueur2.posy = 625;

            if (joueur1.posx >= 60 && joueur1.posx <= 150 && joueur1.posy >= 205 && joueur1.posy <= 520) {
                joueur1.posx = 150;
                if (key[KEY_1_PAD] && joueur1.orientation == 4) {
                    joueur1.combinaison = menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);
                }
            }

            putpixel(buffer, joueur2.posx, joueur2.posy, makecol(0, 0, 0));

            if (joueur1.posx >= 140 && joueur1.posx <= 500 && joueur1.posy >= 530 && joueur1.posy <= 700){//si la position du joueur est comprise entre 140 et 500 et entre 530 et 700
                joueur1.posy = 530;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==3){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 3
                    if (joueur1.combinaison==3){//si la combinaison du joueur est égale à 3
                        occupation++;//incrémentation de la variable
                        if (occupation<0){//si l'occupation est inférieure à 0
                            occupation=0;//définition de la variable
                        }
                        if (occupation>2){//si l'occupation est supérieure à 2
                            occupation=2;//définition de la variable
                        }
                        joueur1.combinaison=0;//définition de la combinaison du joueur
                    }
                }
            }
            if (joueur1.posx>=315 && joueur1.posx <= 500 && joueur1.posy >= 180 && joueur1.posy <= 600){//si la position du joueur est comprise entre 315 et 500 et entre 180 et 600
                joueur1.posx=315;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==2){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 2
                    tables(&joueur1, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur1.posx >= 160 && joueur1.posx <= 780 && joueur1.posy >= 188 && joueur1.posy <= 240){//si la position du joueur est comprise entre 160 et 780 et entre 188 et 240
                joueur1.posy = 240;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==1){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 1
                    allegro_message("prise");//affichage d'un message
                }
            }
            if (joueur2.posx >= 160 && joueur2.posx <= 450 && joueur2.posy >= 530 && joueur2.posy <= 700){//si la position du joueur est comprise entre 160 et 450 et entre 530 et 700
                joueur2.posy=470;
                if (key[KEY_C]){//si la touche C est appuyée
                    tables(&joueur2, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur2.posy >= 400 && joueur2.posy <= 600 && joueur2.posx==470){//si la position du joueur est comprise entre 400 et 600 et que la position du joueur est égale à 470
                if (key[KEY_C]){//si la touche C est appuyée
                    tables(&joueur2, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur2.posx >= 315 && joueur2.posx <= 470 && joueur2.posy >= 180 && joueur2.posy <= 600){//si la position du joueur est comprise entre 315 et 470 et entre 180 et 600
                joueur2.posx=470;//définition de la position du joueur
                if (key[KEY_C]){//si la touche C est appuyée
                    tables(&joueur2, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur2.posx >= 160 && joueur2.posx <= 780 && joueur2.posy >= 188 && joueur2.posy <= 260){//si la position du joueur est comprise entre 160 et 780 et entre 188 et 260
                joueur2.posy = 260;//définition de la position du joueur
                if (key[KEY_C] && joueur2.orientation==1){//si la touche C est appuyée et que l'orientation du joueur est égale à 1
                    allegro_message("prise3");
                }
            }
            if (joueur2.posx >= 610 && joueur2.posx <= 705 && joueur2.posy >= 340 && joueur2.posy <= 550){//si la position du joueur est comprise entre 610 et 705 et entre 340 et 550
                joueur2.posx = 610;//définition de la position du joueur
                if (key[KEY_C]){//si la touche C est appuyée
                    score=gerer_commandes(buffer, nbrecette, bouf1_1comm, bouf2_1comm, bouf3_1comm, recette, 0,2,joueur2.combinaison,score);
                }
            }
        }
        if (nivchoisi==2){//si le niveau choisi est le niveau 2
            if (occupation==0){//si l'occupation est égale à 0
                blit(NIV2, buffer, 0, 0, (SCREEN_W - NIV2->w) / 2, (SCREEN_H - NIV2->h) / 2, NIV2->w, NIV2->h);//affichage de l'image
            }
            if (occupation==1){//si l'occupation est égale à 1
                blit(NIV2B1, buffer, 0, 0, (SCREEN_W - NIV2B1->w) / 2, (SCREEN_H - NIV2B1->h) / 2, NIV2B1->w, NIV2B1->h);//affichage de l'image
            }
            if (occupation==2){//si l'occupation est égale à 2
                blit(NIV2B2, buffer, 0, 0, (SCREEN_W - NIV2B2->w) / 2, (SCREEN_H - NIV2B2->h) / 2, NIV2B2->w, NIV2B2->h);//affichage de l'image
            }
            if (joueur1.posx <= 20) joueur1.posx = 20;//si la position du joueur est inférieure à 20
            if (joueur1.posx >= 705) joueur1.posx = 705;//si la position du joueur est supérieure à 705
            if (joueur1.posy <= 175) joueur1.posy = 175;//si la position du joueur est inférieure à 175
            if (joueur1.posy >= 625) joueur1.posy = 625;//si la position du joueur est supérieure à 625

            if (joueur2.posx <= 20) joueur2.posx = 20;//si la position du joueur est inférieure à 20
            if (joueur2.posx >= 705) joueur2.posx = 705;//si la position du joueur est supérieure à 705
            if (joueur2.posy <= 175) joueur2.posy = 175;//si la position du joueur est inférieure à 175
            if (joueur2.posy >= 625) joueur2.posy = 625;//si la position du joueur est supérieure à 625

            if (joueur1.posx >= 0 && joueur1.posx <= 270 && joueur1.posy >= 400 && joueur1.posy <= 600){//si la position du joueur est comprise entre 0 et 270 et entre 400 et 600
                joueur1.posx = 270;//définition de la position du joueur
                if (key[KEY_1_PAD]){//si la touche 1 du pavé numérique est appuyée
                    joueur1.combinaison=menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);//définition de la combinaison du joueur
                }
            }
            if (joueur1.posx >= 200 && joueur1.posx <= 420 && joueur1.posy >= 100 && joueur1.posy <= 372){//si la position du joueur est comprise entre 200 et 420 et entre 100 et 372
                joueur1.posy = 372;//définition de la position du joueur
                if (key[KEY_1_PAD]){//si la touche 1 du pavé numérique est appuyée
                    tables(&joueur1, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur1.posx >= 530 && joueur1.posx <= 800 && joueur1.posy >= 320 && joueur1.posy <= 480){//si la position du joueur est comprise entre 530 et 800 et entre 320 et 480
                joueur1.posx = 530;//définition de la position du joueur
                if (key[KEY_1_PAD]){//si la touche 1 du pavé numérique est appuyée
                    occupation++;//incrémentation de la variable
                    if (occupation < 0){//si l'occupation est inférieure à 0
                        occupation = 0;//définition de la variable
                    }
                    if (occupation > 2){//si l'occupation est supérieure à 2
                        occupation = 2;//définition de la variable
                    }
                }
            }
            if (joueur2.posx >= 0 && joueur2.posx <= 270 && joueur2.posy >= 400 && joueur2.posy <= 600){//si la position du joueur est comprise entre 0 et 270 et entre 400 et 600
                joueur2.posx = 270;//définition de la position du joueur
                if (key[KEY_C]){//si la touche C est appuyée
                    joueur2.combinaison = menu_cru(buffer, nivchoisi, joueur2.combinaison, 1);//définition de la combinaison du joueur
                }
            }
            if (joueur2.posx >= 200 && joueur2.posx <= 420 && joueur2.posy >= 100 && joueur2.posy <= 372){//si la position du joueur est comprise entre 200 et 420 et entre 100 et 372
                joueur2.posy = 372;//définition de la position du joueur
                if (key[KEY_C]){//si la touche C est appuyée
                    tables(&joueur2, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur2.posx >= 530 && joueur2.posx <= 800 && joueur2.posy >= 320 && joueur2.posy <= 480){//si la position du joueur est comprise entre 530 et 800 et entre 320 et 480
                joueur2.posx = 530;//définition de la position du joueur
                if (key[KEY_C]){//si la touche C est appuyée
                    occupation++;//incrémentation de la variable
                    if (occupation < 0){//si l'occupation est inférieure à 0
                        occupation = 0;//définition de la variable
                    }
                    if (occupation > 2){//si l'occupation est supérieure à 2
                        occupation = 2;//définition de la variable
                    }
                }
            }
        }
        if (nivchoisi==3){//si le niveau choisi est le niveau 3
            if (occupation==0){//si l'occupation est égale à 0
                blit(NIV3, buffer, 0, 0, (SCREEN_W - NIV3->w) / 2, (SCREEN_H - NIV3->h) / 2, NIV3->w, NIV3->h);//affichage de l'image
            }
            if (occupation==1){//si l'occupation est égale à 1
                blit(NIV3B1, buffer, 0, 0, (SCREEN_W - NIV3B1->w) / 2, (SCREEN_H - NIV3B1->h) / 2, NIV3B1->w, NIV3B1->h);//affichage de l'image
            }
            if (occupation==2){//si l'occupation est égale à 2
                blit(NIV3B2, buffer, 0, 0, (SCREEN_W - NIV3B2->w) / 2, (SCREEN_H - NIV3B2->h) / 2, NIV3B2->w, NIV3B2->h);//affichage de l'image
            }
            textprintf_ex(buffer, font, 60, 120, makecol(0, 0, 0), -1, "j1 : %4d %4d", joueur1.posx, joueur1.posy);//affichage du texte
            textprintf_ex(buffer, font, 60, 100, makecol(0, 0, 0), -1, "j2 : %4d %4d", joueur2.posx, joueur2.posy);

            if (joueur1.posx <= 60) joueur1.posx = 60;//si la position du joueur est inférieure à 60
            if (joueur1.posx >= 705) joueur1.posx = 705;//si la position du joueur est supérieure à 705
            if (joueur1.posy <= 175) joueur1.posy = 175;//si la position du joueur est inférieure à 175
            if (joueur1.posy >= 625) joueur1.posy = 625;//si la position du joueur est supérieure à 625

            if (joueur2.posx <= 60) joueur2.posx = 60;//si la position du joueur est inférieure à 60
            if (joueur2.posx >= 705) joueur2.posx = 705;//si la position du joueur est supérieure à 705
            if (joueur2.posy <= 175) joueur2.posy = 175;//si la position du joueur est inférieure à 175
            if (joueur2.posy >= 625) joueur2.posy = 625;//si la position du joueur est supérieure à 625

            if (joueur1.posx >= 640){//si la position du joueur est supérieure à 640
                joueur1.posx = 640;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation == 2){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 2
                    joueur1.combinaison = menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);//définition de la combinaison du joueur
                }
            }
            if (joueur1.posx <= 170){//si la position du joueur est inférieure à 170
                joueur1.posx = 170;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==4){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 4
                    tables(&joueur1, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur1.posy <= 275){//si la position du joueur est inférieure à 275
                joueur1.posy = 275;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==1){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 1
                    if (joueur1.posx >= 230 && joueur1.posx <= 260){//si la position du joueur est comprise entre 230 et 260
                        occupation++;//incrémentation de la variable
                        if (occupation<0){//si l'occupation est inférieure à 0
                            occupation=0;//définition de la variable
                        }
                        if (occupation>2){//si l'occupation est supérieure à 2
                            occupation=2;//définition de la variable
                        }
                    }
                }
            }
            if (joueur1.posy>=575){//si la position du joueur est supérieure à 575
                joueur1.posy=575;//définition de la position du joueur
                if (key[KEY_1_PAD] && joueur1.orientation==3){//si la touche 1 du pavé numérique est appuyée et que l'orientation du joueur est égale à 3
                    if (joueur1.posx >= 230 && joueur1.posx<=260){//si la position du joueur est comprise entre 230 et 260
                        occupation++;//incrémentation de la variable
                        if (occupation<0){//si l'occupation est inférieure à 0
                            occupation=0;//définition de la variable
                        }
                        if (occupation>2){//si l'occupation est supérieure à 2
                            occupation=2;//définition de la variable
                        }
                    }
                }
            }
            if (joueur2.posx>=640){//si la position du joueur est supérieure à 640
                joueur2.posx=640;//définition de la position du joueur
                if (key[KEY_V] && joueur2.orientation==2){//si la touche V est appuyée et que l'orientation du joueur est égale à 2
                    joueur2.combinaison = menu_cru(buffer, nivchoisi, joueur2.combinaison, 1);//définition de la combinaison du joueur
                }
            }
            if (joueur2.posx<=170){//si la position du joueur est inférieure à 170
                joueur2.posx=170;//définition de la position du joueur
                if (key[KEY_V] && joueur2.orientation==4){//si la touche V est appuyée et que l'orientation du joueur est égale à 4
                    tables(&joueur2, &table, nivchoisi);//appel de la fonction tables
                }
            }
            if (joueur2.posy<=275){//si la position du joueur est inférieure à 275
                joueur2.posy=275;//définition de la position du joueur
                if (key[KEY_V] && joueur2.orientation==1){//si la touche V est appuyée et que l'orientation du joueur est égale à 1
                    if (joueur2.posx>=230 && joueur2.posx<=260){//si la position du joueur est comprise entre 230 et 260
                        occupation++;//incrémentation de la variable
                        if (occupation<0){//si l'occupation est inférieure à 0
                            occupation=0;//définition de la variable
                        }
                        if (occupation>2){//si l'occupation est supérieure à 2
                            occupation=2;//définition de la variable
                        }
                    }
                }
            }
            //
            if (joueur2.posy>=575){//si la position du joueur est supérieure à 575
                joueur2.posy=575;//définition de la position du joueur
                if (key[KEY_V] && joueur2.orientation==3){//si la touche V est appuyée et que l'orientation du joueur est égale à 3
                    if (joueur2.posx >= 230 && joueur2.posx<=260){//si la position du joueur est comprise entre 230 et 260
                        occupation++;//incrémentation de la variable
                        if (occupation<0){//si l'occupation est inférieure à 0
                            occupation=0;//définition de la variable
                        }
                        if (occupation>2){//si l'occupation est supérieure à 2
                            occupation=2;//définition de la variable
                        }
                    }
                }
            }
        }
        if (key[KEY_E]){//si la touche E est appuyée
            if(occupation!=0){
                occupation--;//décrémentation de la variable
                if (occupation<0){//si l'occupation est inférieure à 0
                    occupation=0;//définition de la variable
                }
                if (occupation>2){//si l'occupation est supérieure à 2
                    occupation=2;//définition de la variable
                }
                joueur1.combinaison=4;//définition de la combinaison du joueur
                allegro_message("vous avez fait du riz cuit");//affichage d'un message
                score=+25;
            }

        }

        if (key[KEY_UP]) { joueur1.posy -= deplacement; joueur1.orientation=1;}//si la touche HAUT est appuyée
        if (key[KEY_DOWN]) { joueur1.posy += deplacement; joueur1.orientation=3;}//si la touche BAS est appuyée
        if (key[KEY_LEFT]) { joueur1.posx -= deplacement; joueur1.orientation=4;}//si la touche GAUCHE est appuyée
        if (key[KEY_RIGHT]) { joueur1.posx += deplacement; joueur1.orientation=2;}//si la touche DROITE est appuyée
        if (key[KEY_W]) { joueur2.posy -= deplacement; joueur2.orientation=1;}//si la touche W est appuyée
        if (key[KEY_S]) { joueur2.posy += deplacement; joueur2.orientation=3;}//si la touche S est appuyée
        if (key[KEY_A]) { joueur2.posx -= deplacement; joueur2.orientation=4;}//si la touche A est appuyée
        if (key[KEY_D]) { joueur2.posx += deplacement; joueur2.orientation =2;}//si la touche D est appuyée

        image_joueur(buffer, PERSO1_O, PERSO2_O, joueur1, joueur2);//appel de la fonction image_joueur
        if (nivchoisi==1){//si le niveau choisi est le niveau 1
            nbrecette=gerer_commandes(buffer, nbrecette, bouf1_1comm, bouf2_1comm, bouf3_1comm, recette, 0,1,0,0);//appel de la fonction gerer_commandes
        }
        if (nivchoisi==2){//si le niveau choisi est le niveau 2
            nbrecette=gerer_commandes(buffer, nbrecette, bouf1_2comm, bouf2_2comm, bouf3_2comm, recette, 0,1,0,0);
        }
        if (nivchoisi==3){//si le niveau choisi est le niveau 3
            nbrecette = gerer_commandes(buffer, nbrecette, bouf1_3comm, bouf2_3comm, bouf3_3comm, recette, 0,1,0,0);
        }
        textprintf_ex(buffer, font, 60, 100, makecol(0, 0, 0), -1, "J1 : %4d %4d", joueur1.posx, joueur1.posy);//affichage du texte
        textprintf_ex(buffer, font, 60, 120, makecol(0, 0, 0), -1, " j2 : %4d %4d", joueur2.posx, joueur2.posy);
        textprintf_ex(buffer, font, 60, 140, makecol(0, 0, 0), -1, "mouse : %4d %4d", mouse_x, mouse_y);
        textprintf_ex(buffer, font, 700, 700, makecol(255, 255, 255), -1, "%.1f / 180", seconde);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);//affichage de l'image
        rest(40);//pause
        if (seconde>=180){//si la variable seconde est supérieure ou égale à 180
            fin=1;//définition de la variable
        }
    }
    destroy_bitmap(buffer);//libération de la mémoire
    destroy_bitmap(bouf1_1comm);
    destroy_bitmap(bouf2_1comm);
    destroy_bitmap(bouf3_1comm);
    destroy_bitmap(bouf1_2comm);
    destroy_bitmap(bouf2_2comm);
    destroy_bitmap(bouf3_2comm);
    destroy_bitmap(NIV1);
    destroy_bitmap(NIV1B1);
    destroy_bitmap(NIV1B2);
    destroy_bitmap(NIV2);
    destroy_bitmap(NIV2B1);
    destroy_bitmap(NIV2B2);
    destroy_bitmap(NIV3);
    imagefin();
    return 0;
}

void imagefin(){//fonction imagefin
    install_mouse();//initialisation de la souris
    show_mouse(screen);//affichage de la souris
    int verif=0;//définition de la variable
    BITMAP *imagefin=load_bitmap("../images/imagefin.bmp", NULL);//chargement des images
    BITMAP *imagefinselect=load_bitmap("../images/imagefinselect.bmp", NULL);//chargement des images
    while (!verif){//tant que la variable verif est fausse
        if (mouse_x > 390 && mouse_x < 530 && mouse_y > 650 && mouse_y < 715){//si la position de la souris est comprise entre 390 et 530 et entre 650 et 715
            blit(imagefinselect, screen, 0, 0, (SCREEN_W - imagefinselect->w) / 2, (SCREEN_H - imagefinselect->h) / 2, imagefinselect->w, imagefinselect->h);//affichage de l'image
            if (mouse_b & 1){//si le bouton gauche de la souris est appuyé
                verif=1;//définition de la variable
            }
        }
        if (!(mouse_x > 390 && mouse_x < 530 && mouse_y > 650 && mouse_y < 715)){//si la position de la souris n'est pas comprise entre 390 et 530 et entre 650 et 715
            blit(imagefin, screen, 0, 0, (SCREEN_W - imagefin->w) / 2, (SCREEN_H - imagefin->h) / 2, imagefin->w, imagefin->h);//affichage de l'image
        }
    }
    destroy_bitmap(imagefinselect);//libération de la mémoire
    destroy_bitmap(imagefin);
}

void tuto(){//fonction tuto
    BITMAP *tutoP1=load_bitmap("../images/tuto1.bmp", NULL);//chargement des images
    BITMAP *tutoP2=load_bitmap("../images/tuto2.bmp", NULL);
    BITMAP *tutoP3=load_bitmap("../images/tuto3.bmp", NULL);
    BITMAP *tutoP4=load_bitmap("../images/tuto4.bmp", NULL);
    int compteur_page_tuto=1;//définition de la variable
    install_keyboard();//initialisation du clavier
    while (compteur_page_tuto<=MAX_PAGE_TUTO+1){//tant que le compteur est inférieur ou égal à MAX_PAGE_TUTO + 1
        rest(100);//pause
        if (key[KEY_RIGHT]){//si la touche DROITE est appuyée
            compteur_page_tuto +=1;//incrémentation de la variable
        }
        if (key[KEY_LEFT]){//si la touche GAUCHE est appuyée
            compteur_page_tuto -= 1;//décrémentation de la variable
        }
        if (key[KEY_SPACE] || key[KEY_ESC]){//si la touche ESPACE ou ECHAP est appuyée
            destroy_bitmap(tutoP1);//libération de la mémoire
            destroy_bitmap(tutoP2);
            destroy_bitmap(tutoP3);
            destroy_bitmap(tutoP4);
            return;
        }
        if (compteur_page_tuto>MAX_PAGE_TUTO){//si le compteur est supérieur à MAX_PAGE_TUTO
            compteur_page_tuto=MAX_PAGE_TUTO;//définition de la variable
        }
        if (compteur_page_tuto<0){//si le compteur est inférieur à 0
            compteur_page_tuto=0;//définition de la variable
        }

        switch (compteur_page_tuto){//selon la variable
            case 1:
                blit(tutoP1, screen, 0, 0, (SCREEN_W - tutoP1->w) / 2, (SCREEN_H - tutoP1->h) / 2, tutoP1->w, tutoP1->h);//affichage de l'image
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");//affichage du texte
                break;//sortie de la boucle
            case 2:
                blit(tutoP2, screen, 0, 0, (SCREEN_W - tutoP2->w) / 2, (SCREEN_H - tutoP2->h) / 2, tutoP2->w, tutoP2->h);//affichage de l'image
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");//affichage du texte
                break;
            case 3:
                blit(tutoP3, screen, 0, 0, (SCREEN_W - tutoP3->w) / 2, (SCREEN_H - tutoP3->h) / 2, tutoP3->w, tutoP3->h);//affichage de l'image
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");//affichage du texte
                break;
            case 4:
                blit(tutoP4, screen, 0, 0, (SCREEN_W - tutoP4->w) / 2, (SCREEN_H - tutoP4->h) / 2, tutoP4->w, tutoP4->h);//affichage de l'image
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");//affichage du texte
                break;
        }
    }
}

void affiche_score(){//fonction affiche_score
    BITMAP *Score=load_bitmap("../images/Score.bmp", NULL);//chargement de l'image
    while (key[KEY_SPACE]==0){//tant que la touche ESPACE n'est pas appuyée
        blit(Score, screen, 0, 0, (SCREEN_W - Score->w) / 2, (SCREEN_H - Score->h) / 2, Score->w, Score->h);//affichage de l'image
    }
    destroy_bitmap(Score);//libération de la mémoire
}
