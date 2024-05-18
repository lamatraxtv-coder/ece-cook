#include "librairies.h"



void affichagechargement() {
    set_trans_blender(0, 255, 0, 0);
    BITMAP *imagechargement = load_bitmap("../images/ece cook chargement.bmp", NULL);
    if (!imagechargement) {
        allegro_message("Erreur de chargement de l'image");
        return;
    }
    blit(imagechargement, screen, 0, 0, (SCREEN_W - imagechargement->w) / 2, (SCREEN_H - imagechargement->h) / 2, imagechargement->w, imagechargement->h);
    textprintf_ex(screen, font, 320, 750, makecol(0, 0, 0), -1, "Appuyez sur ESPACE pour continuer");
    while (!key[KEY_SPACE]) {
        rest(100);
    }
    destroy_bitmap(imagechargement);
}

void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]) {
    PERSO1_O[0] = load_bitmap("../images/perso1O1.bmp", NULL);
    PERSO1_O[1] = load_bitmap("../images/perso1O2.bmp", NULL);
    PERSO1_O[2] = load_bitmap("../images/perso1O3.bmp", NULL);
    PERSO1_O[3] = load_bitmap("../images/perso1O4.bmp", NULL);

    PERSO2_O[0] = load_bitmap("../images/perso2O1.bmp", NULL);
    PERSO2_O[1] = load_bitmap("../images/perso2O2.bmp", NULL);
    PERSO2_O[2] = load_bitmap("../images/perso2O3.bmp", NULL);
    PERSO2_O[3] = load_bitmap("../images/perso2O4.bmp", NULL);
}

void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], Joueur joueur1, Joueur joueur2) {
    if (joueur1.orientation >= 1 && joueur1.orientation <= 4) {
        draw_sprite(buffer, PERSO1_O[joueur1.orientation - 1], joueur1.posx, joueur1.posy);
    }
    if (joueur2.orientation >= 1 && joueur2.orientation <= 4) {
        draw_sprite(buffer, PERSO2_O[joueur2.orientation - 1], joueur2.posx, joueur2.posy);
    }
}

int gerer_commandes(BITMAP *buffer, int recettes, BITMAP *recette1, BITMAP *recette2, BITMAP *recette3, int recette[MAX_COMMANDES], int index) {
    BITMAP *recettesDisponibles[3] = {recette1, recette2, recette3};
    int random = rand() % 200;
    if (random == 1 && recettes < MAX_COMMANDES) {
        recette[recettes] = rand() % 3;
        recettes++;
    }

    if (key[KEY_U]) {
        if (index < 0 || index >= recettes) {
            allegro_message("Index invalide pour la suppression: %d\n", index);
            return recettes;
        }
        for (int i = index; i < recettes - 1; i++) {
            recette[i] = recette[i + 1];
        }
        recettes--;
    }
    for (int i = 0; i < recettes; i++) {
        draw_sprite(buffer, recettesDisponibles[recette[i]], 20 + (200 * i), -100);
    }
    return recettes;
}

int menu_cru(BITMAP *buffer, int nivchoisi, int combinaison, int capte) {
    BITMAP *A0 = load_bitmap("../images/menucru niv1.bmp", NULL);
    BITMAP *A1 = load_bitmap("../images/menucru niv1_1.bmp", NULL);
    BITMAP *A2 = load_bitmap("../images/menucru niv1_2.bmp", NULL);
    BITMAP *A3 = load_bitmap("../images/menucru niv1_3.bmp", NULL);

    if (nivchoisi == 1) {
        draw_sprite(buffer, A0, 450, 400);
        if (mouse_y >= 480 && mouse_y <= 513) {
            draw_sprite(buffer, A1, 450, 400);
            if (mouse_b & 1) {
                combinaison = 1;
                allegro_message("vous avez pris un thon");
            }
        }
        if (mouse_y >= 513 && mouse_y <= 600) {
            draw_sprite(buffer, A2, 450, 400);
            if (mouse_b & 1) {
                combinaison = 2;
                allegro_message("vous avez pris un saumon");
            }
        }
        if (mouse_y >= 600 && mouse_y <= 700) {
            draw_sprite(buffer, A3, 450, 400);
            if (mouse_b & 1) {
                combinaison = 3;
                allegro_message("vous avez pris du riz cru");
            }
        }
    }

    destroy_bitmap(A0);
    destroy_bitmap(A1);
    destroy_bitmap(A2);
    destroy_bitmap(A3);

    return combinaison;
}

int menu() {
    install_mouse();
    show_mouse(screen);
    BITMAP *menuneutre = load_bitmap("../images/menuneutre.bmp", NULL);
    BITMAP *menu1 = load_bitmap("../images/menu1.bmp", NULL);
    BITMAP *menu2 = load_bitmap("../images/menu2.bmp", NULL);
    BITMAP *menu3 = load_bitmap("../images/menu3.bmp", NULL);
    int a = 0;
    int selection;
    blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);

    while (a == 0) {
        if (mouse_x >= 155 && mouse_x <= 313 && mouse_y >= 572 && mouse_y <= 658) {
            blit(menu1, screen, 0, 0, (SCREEN_W - menu1->w) / 2, (SCREEN_H - menu1->h) / 2, menu1->w, menu1->h);
            if (mouse_b & 1) {
                a = 1;
                selection = 1;
            }
        }
        if (mouse_x >= 368 && mouse_x <= 538 && mouse_y >= 572 && mouse_y <= 658) {
            blit(menu2, screen, 0, 0, (SCREEN_W - menu2->w) / 2, (SCREEN_H - menu2->h) / 2, menu2->w, menu2->h);
            if (mouse_b & 1) {
                a = 1;
                selection = 2;
            }
        }

        if (mouse_x >= 585 && mouse_x <= 752 && mouse_y >= 572 && mouse_y <= 658) {
            blit(menu3, screen, 0, 0, (SCREEN_W - menu3->w) / 2, (SCREEN_H - menu3->h) / 2, menu3->w, menu3->h);
            if (mouse_b & 1) {
                a = 1;
                selection = 3;
            }
        }
        if (mouse_x >= 487 && mouse_x <= 634 && mouse_y >= 715 && mouse_y <= 762) {
            if (mouse_b & 1) {
                allegro_exit();
            }
        }
        if (!(mouse_x >= 155 && mouse_x <= 313 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 368 && mouse_x <= 538 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 585 && mouse_x <= 752 && mouse_y >= 572 && mouse_y <= 658) &&
            !(mouse_x >= 487 && mouse_x <= 634 && mouse_y >= 715 && mouse_y <= 762)) {
            blit(menuneutre, screen, 0, 0, (SCREEN_W - menuneutre->w) / 2, (SCREEN_H - menuneutre->h) / 2, menuneutre->w, menuneutre->h);
        }
    }

    destroy_bitmap(menuneutre);
    destroy_bitmap(menu1);
    destroy_bitmap(menu2);
    destroy_bitmap(menu3);

    return selection;
}

int selectniv(int fini) {
    install_mouse();
    show_mouse(screen);
    int a = 0;
    int choixniv;
    BITMAP *choix1 = load_bitmap("../images/choix_niv_1U.bmp", NULL);
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

    while (a == 0) {
        if (fini == 0) {
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739) {
                blit(choix1_1, screen, 0, 0, (SCREEN_W - choix1_1->w) / 2, (SCREEN_H - choix1_1->h) / 2, choix1_1->w, choix1_1->h);
                if (mouse_b & 1) {
                    choixniv = 1;
                    a = 1;
                }
            }
            if (mouse_x > 793 && mouse_x < 863 && mouse_y > 27 && mouse_y < 112) {
                blit(choix1_M, screen, 0, 0, (SCREEN_W - choix1_M->w) / 2, (SCREEN_H - choix1_M->h) / 2, choix1_M->w, choix1_M->h);
                if (mouse_b & 1) {
                    choixniv = 0;
                    a = 1;
                }
            }
            if (!(mouse_x > 38 && mouse_x < 292 || mouse_x > 793 && mouse_x < 863 && mouse_y > 237 && mouse_y < 739 || mouse_y > 27 && mouse_y < 112)) {
                blit(choix1, screen, 0, 0, (SCREEN_W - choix1->w) / 2, (SCREEN_H - choix1->h) / 2, choix1->w, choix1->h);
            }

            if (key[KEY_UP]) {
                fini = fini + 1;
                sleep(1);
            }
        }
        if (fini == 1) {
            if (mouse_x > 38 && mouse_x < 292 && mouse_y > 237 && mouse_y < 739) {
                blit(choix2_1, screen, 0, 0, (SCREEN_W - choix2_1->w) / 2, (SCREEN_H - choix2_1->h) / 2, choix2_1->w, choix2_1->h);
                if (mouse_b & 1) {
                    choixniv = 1;
                    a = 1;
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
            *table = 0;
            joueur->combinaison = 0;
        } else if (joueur->combinaison == 6) {
            allegro_message("vous avez combiné un sushi saumon");
            *table = 0;
            joueur->combinaison = 0;
        }
    } else if ((joueur->combinaison == 1 || joueur->combinaison == 2) && *table == 4) {
        joueur->combinaison += *table;
        if (joueur->combinaison == 5) {
            allegro_message("vous avez combiné un sushi thon");
            *table = 0;
            joueur->combinaison = 0;
        } else if (joueur->combinaison == 6) {
            allegro_message("vous avez combiné un sushi saumon");
            *table = 0;
            joueur->combinaison = 0;
        }
    } else if (*table == 3) {
        allegro_message("vous ne pouvez pas poser du riz cru");
        *table = 0;
        joueur->combinaison = 3;
    }
    if(key[KEY_H]){
        joueur->combinaison = 0;
        *table = 0;
    }
}
//
int jeu(int nivchoisi) {
    Joueur joueur1, joueur2;
    int nbrecette = 0;
    int deplacement = 10;
    int recette[MAX_COMMANDES];
    int fin = 0;
    int occupation = 0;
    int table = 0;

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
                if (key[KEY_RSHIFT] && joueur1.orientation == 4) {
                    joueur1.combinaison = menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);
                }
            }

            putpixel(buffer, joueur2.posx, joueur2.posy, makecol(0, 0, 0));

            if (joueur1.posx >= 140 && joueur1.posx <= 500 && joueur1.posy >= 530 && joueur1.posy <= 700) {
                joueur1.posy = 530;
                if (key[KEY_RSHIFT] && joueur1.orientation == 3) {
                    if (joueur1.combinaison == 3) {
                        occupation++;
                        if (occupation < 0) {
                            occupation = 0;
                        }
                        if (occupation > 2) {
                            occupation = 2;
                        }
                        joueur1.combinaison = 0;
                    }
                }
            }
            if (joueur1.posx >= 315 && joueur1.posx <= 500 && joueur1.posy >= 180 && joueur1.posy <= 600) {
                joueur1.posx = 315;
                if (key[KEY_RSHIFT] && joueur1.orientation == 2) {
                    tables(&joueur1, &table, nivchoisi);
                }
            }
            if (joueur1.posx >= 160 && joueur1.posx <= 780 && joueur1.posy >= 188 && joueur1.posy <= 240) {
                joueur1.posy = 240;
                if (key[KEY_RSHIFT] && joueur1.orientation == 1) {
                    allegro_message("prise");
                }
            }
            if (joueur2.posx >= 160 && joueur2.posx <= 450 && joueur2.posy >= 530 && joueur2.posy <= 700) {
                joueur2.posy = 470;
                if (key[KEY_Q]) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }
            if (joueur2.posy >= 400 && joueur2.posy <= 600 && joueur2.posx == 470) {
                if (key[KEY_Q]) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }

            if (joueur2.posx >= 315 && joueur2.posx <= 470 && joueur2.posy >= 180 && joueur2.posy <= 600) {
                joueur2.posx = 470;
                if (key[KEY_Q]) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }

            if (joueur2.posx >= 160 && joueur2.posx <= 780 && joueur2.posy >= 188 && joueur2.posy <= 260) {
                joueur2.posy = 260;
                if (key[KEY_Q] && joueur2.orientation == 1) {
                    allegro_message("prise3");
                }
            }
            if (joueur2.posx >= 610 && joueur2.posx <= 705 && joueur2.posy >= 340 && joueur2.posy <= 550) {
                joueur2.posx = 610;
                if (key[KEY_Q]) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }
        }

        if (nivchoisi == 2) {
            if (occupation == 0) {
                blit(NIV2, buffer, 0, 0, (SCREEN_W - NIV2->w) / 2, (SCREEN_H - NIV2->h) / 2, NIV2->w, NIV2->h);
            }
            if (occupation == 1) {
                blit(NIV2B1, buffer, 0, 0, (SCREEN_W - NIV2B1->w) / 2, (SCREEN_H - NIV2B1->h) / 2, NIV2B1->w, NIV2B1->h);
            }
            if (occupation == 2) {
                blit(NIV2B2, buffer, 0, 0, (SCREEN_W - NIV2B2->w) / 2, (SCREEN_H - NIV2B2->h) / 2, NIV2B2->w, NIV2B2->h);
            }

            if (joueur1.posx <= 20) joueur1.posx = 20;
            if (joueur1.posx >= 705) joueur1.posx = 705;
            if (joueur1.posy <= 175) joueur1.posy = 175;
            if (joueur1.posy >= 625) joueur1.posy = 625;

            if (joueur2.posx <= 20) joueur2.posx = 20;
            if (joueur2.posx >= 705) joueur2.posx = 705;
            if (joueur2.posy <= 175) joueur2.posy = 175;
            if (joueur2.posy >= 625) joueur2.posy = 625;

            if (joueur1.posx >= 0 && joueur1.posx <= 270 && joueur1.posy >= 400 && joueur1.posy <= 600) {
                joueur1.posx = 270;
                if (key[KEY_RSHIFT]) {
                    joueur1.combinaison = menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);
                }
            }

            if (joueur1.posx >= 200 && joueur1.posx <= 420 && joueur1.posy >= 100 && joueur1.posy <= 372) {
                joueur1.posy = 372;
                if (key[KEY_RSHIFT]) {
                    tables(&joueur1, &table, nivchoisi);
                }
            }

            if (joueur1.posx >= 530 && joueur1.posx <= 800 && joueur1.posy >= 320 && joueur1.posy <= 480) {
                joueur1.posx = 530;
                if (key[KEY_RSHIFT]) {
                    occupation++;
                    if (occupation < 0) {
                        occupation = 0;
                    }
                    if (occupation > 2) {
                        occupation = 2;
                    }
                }
            }
            if (joueur2.posx >= 0 && joueur2.posx <= 270 && joueur2.posy >= 400 && joueur2.posy <= 600) {
                joueur2.posx = 270;
                if (key[KEY_Q]) {
                    joueur2.combinaison = menu_cru(buffer, nivchoisi, joueur2.combinaison, 1);
                }
            }

            if (joueur2.posx >= 200 && joueur2.posx <= 420 && joueur2.posy >= 100 && joueur2.posy <= 372) {
                joueur2.posy = 372;
                if (key[KEY_Q]) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }

            if (joueur2.posx >= 530 && joueur2.posx <= 800 && joueur2.posy >= 320 && joueur2.posy <= 480) {
                joueur2.posx = 530;
                if (key[KEY_Q]) {
                    occupation++;
                    if (occupation < 0) {
                        occupation = 0;
                    }
                    if (occupation > 2) {
                        occupation = 2;
                    }
                }
            }
        }

        if (nivchoisi == 3) {
            if (occupation == 0) {
                blit(NIV3, buffer, 0, 0, (SCREEN_W - NIV3->w) / 2, (SCREEN_H - NIV3->h) / 2, NIV3->w, NIV3->h);
            }
            if (occupation == 1) {
                blit(NIV3B1, buffer, 0, 0, (SCREEN_W - NIV3B1->w) / 2, (SCREEN_H - NIV3B1->h) / 2, NIV3B1->w, NIV3B1->h);
            }
            if (occupation == 2) {
                blit(NIV3B2, buffer, 0, 0, (SCREEN_W - NIV3B2->w) / 2, (SCREEN_H - NIV3B2->h) / 2, NIV3B2->w, NIV3B2->h);
            }
            textprintf_ex(buffer, font, 60, 120, makecol(0, 0, 0), -1, "j1 : %4d %4d", joueur1.posx, joueur1.posy);
            textprintf_ex(buffer, font, 60, 100, makecol(0, 0, 0), -1, "j2 : %4d %4d", joueur2.posx, joueur2.posy);

            if (joueur1.posx <= 60) joueur1.posx = 60;
            if (joueur1.posx >= 705) joueur1.posx = 705;
            if (joueur1.posy <= 175) joueur1.posy = 175;
            if (joueur1.posy >= 625) joueur1.posy = 625;

            if (joueur2.posx <= 60) joueur2.posx = 60;
            if (joueur2.posx >= 705) joueur2.posx = 705;
            if (joueur2.posy <= 175) joueur2.posy = 175;
            if (joueur2.posy >= 625) joueur2.posy = 625;

            if (joueur1.posx >= 640) {
                joueur1.posx = 640;
                if (key[KEY_RSHIFT] && joueur1.orientation == 2) {
                    joueur1.combinaison = menu_cru(buffer, nivchoisi, joueur1.combinaison, 1);
                }
            }
            if (joueur1.posx <= 170) {
                joueur1.posx = 170;
                if (key[KEY_RSHIFT] && joueur1.orientation == 4) {
                    tables(&joueur1, &table, nivchoisi);
                }
            }
            if (joueur1.posy <= 275) {
                joueur1.posy = 275;
                if (key[KEY_RSHIFT] && joueur1.orientation == 1) {
                    if (joueur1.posx >= 230 && joueur1.posx <= 260) {
                        occupation++;
                        if (occupation < 0) {
                            occupation = 0;
                        }
                        if (occupation > 2) {
                            occupation = 2;
                        }
                    }
                }
            }
            if (joueur1.posy >= 575) {
                joueur1.posy = 575;
                if (key[KEY_RSHIFT] && joueur1.orientation == 3) {
                    if (joueur1.posx >= 230 && joueur1.posx <= 260) {
                        occupation++;
                        if (occupation < 0) {
                            occupation = 0;
                        }
                        if (occupation > 2) {
                            occupation = 2;
                        }
                    }
                }
            }
            if (joueur2.posx >= 640) {
                joueur2.posx = 640;
                if (key[KEY_Q] && joueur2.orientation == 2) {
                    joueur2.combinaison = menu_cru(buffer, nivchoisi, joueur2.combinaison, 1);
                }
            }
            if (joueur2.posx <= 170) {
                joueur2.posx = 170;
                if (key[KEY_Q] && joueur2.orientation == 4) {
                    tables(&joueur2, &table, nivchoisi);
                }
            }
            if (joueur2.posy <= 275) {
                joueur2.posy = 275;
                if (key[KEY_Q] && joueur2.orientation == 1) {
                    if (joueur2.posx >= 230 && joueur2.posx <= 260) {
                        occupation++;
                        if (occupation < 0) {
                            occupation = 0;
                        }
                        if (occupation > 2) {
                            occupation = 2;
                        }
                    }
                }
            }
            if (joueur2.posy >= 575) {
                joueur2.posy = 575;
                if (key[KEY_Q] && joueur2.orientation == 3) {
                    if (joueur2.posx >= 230 && joueur2.posx <= 260) {
                        occupation++;
                        if (occupation < 0) {
                            occupation = 0;
                        }
                        if (occupation > 2) {
                            occupation = 2;
                        }
                    }
                }
            }
        }

        if (key[KEY_E]) {
            occupation--;
            if (occupation < 0) {
                occupation = 0;
            }
            if (occupation > 2) {
                occupation = 2;
            }
            joueur1.combinaison = 4;
            allegro_message("vous avez fait du riz cuit");
        }

        if (key[KEY_UP]) { joueur1.posy -= deplacement; joueur1.orientation = 1; }
        if (key[KEY_DOWN]) { joueur1.posy += deplacement; joueur1.orientation = 3; }
        if (key[KEY_LEFT]) { joueur1.posx -= deplacement; joueur1.orientation = 4; }
        if (key[KEY_RIGHT]) { joueur1.posx += deplacement; joueur1.orientation = 2; }
        if (key[KEY_W]) { joueur2.posy -= deplacement; joueur2.orientation = 1; }
        if (key[KEY_S]) { joueur2.posy += deplacement; joueur2.orientation = 3; }
        if (key[KEY_A]) { joueur2.posx -= deplacement; joueur2.orientation = 4; }
        if (key[KEY_D]) { joueur2.posx += deplacement; joueur2.orientation = 2; }

        image_joueur(buffer, PERSO1_O, PERSO2_O, joueur1, joueur2);
        if (nivchoisi == 1) {
            nbrecette = gerer_commandes(buffer, nbrecette, bouf1_1comm, bouf2_1comm, bouf3_1comm, recette, 0);
        }
        if (nivchoisi == 2) {
            nbrecette = gerer_commandes(buffer, nbrecette, bouf1_2comm, bouf2_2comm, bouf3_2comm, recette, 0);
        }
        if (nivchoisi == 3) {
            nbrecette = gerer_commandes(buffer, nbrecette, bouf1_3comm, bouf2_3comm, bouf3_3comm, recette, 0);
        }
        textprintf_ex(buffer, font, 60, 100, makecol(0, 0, 0), -1, "J1 : %4d %4d", joueur1.posx, joueur1.posy);
        textprintf_ex(buffer, font, 60, 120, makecol(0, 0, 0), -1, " j2 : %4d %4d", joueur2.posx, joueur2.posy);
        textprintf_ex(buffer, font, 60, 140, makecol(0, 0, 0), -1, "mouse : %4d %4d", mouse_x, mouse_y);
        textprintf_ex(buffer, font, 700, 700, makecol(255, 255, 255), -1, "%.1f / 180", seconde);
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        rest(40);
        if (seconde >= 180) {
            fin = 1;
        }
    }

    destroy_bitmap(buffer);
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

void imagefin() {
    install_mouse();
    show_mouse(screen);
    int verif = 0;
    BITMAP *imagefin = load_bitmap("../images/imagefin.bmp", NULL);
    BITMAP *imagefinselect = load_bitmap("../images/imagefinselect.bmp", NULL);
    while (!verif) {
        if (mouse_x > 390 && mouse_x < 530 && mouse_y > 650 && mouse_y < 715) {
            blit(imagefinselect, screen, 0, 0, (SCREEN_W - imagefinselect->w) / 2, (SCREEN_H - imagefinselect->h) / 2, imagefinselect->w, imagefinselect->h);
            if (mouse_b & 1) {
                verif = 1;
            }
        }
        if (!(mouse_x > 390 && mouse_x < 530 && mouse_y > 650 && mouse_y < 715)) {
            blit(imagefin, screen, 0, 0, (SCREEN_W - imagefin->w) / 2, (SCREEN_H - imagefin->h) / 2, imagefin->w, imagefin->h);
        }
    }
    destroy_bitmap(imagefinselect);
    destroy_bitmap(imagefin);
}

void tuto() {
    BITMAP *tutoP1 = load_bitmap("../images/tuto1.bmp", NULL);
    BITMAP *tutoP2 = load_bitmap("../images/tuto2.bmp", NULL);
    BITMAP *tutoP3 = load_bitmap("../images/tuto3.bmp", NULL);
    BITMAP *tutoP4 = load_bitmap("../images/tuto4.bmp", NULL);
    int compteur_page_tuto = 1;
    install_keyboard();
    while (compteur_page_tuto <= MAX_PAGE_TUTO + 1) {
        rest(100);
        if (key[KEY_RIGHT]) {
            compteur_page_tuto += 1;
        }
        if (key[KEY_LEFT]) {
            compteur_page_tuto -= 1;
        }
        if (key[KEY_SPACE] || key[KEY_ESC]) {
            destroy_bitmap(tutoP1);
            destroy_bitmap(tutoP2);
            destroy_bitmap(tutoP3);
            destroy_bitmap(tutoP4);
            return;
        }
        if (compteur_page_tuto > MAX_PAGE_TUTO) {
            compteur_page_tuto = MAX_PAGE_TUTO;
        }
        if (compteur_page_tuto < 0) {
            compteur_page_tuto = 0;
        }

        switch (compteur_page_tuto) {
            case 1:
                blit(tutoP1, screen, 0, 0, (SCREEN_W - tutoP1->w) / 2, (SCREEN_H - tutoP1->h) / 2, tutoP1->w, tutoP1->h);
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 2:
                blit(tutoP2, screen, 0, 0, (SCREEN_W - tutoP2->w) / 2, (SCREEN_H - tutoP2->h) / 2, tutoP2->w, tutoP2->h);
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 3:
                blit(tutoP3, screen, 0, 0, (SCREEN_W - tutoP3->w) / 2, (SCREEN_H - tutoP3->h) / 2, tutoP3->w, tutoP3->h);
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
            case 4:
                blit(tutoP4, screen, 0, 0, (SCREEN_W - tutoP4->w) / 2, (SCREEN_H - tutoP4->h) / 2, tutoP4->w, tutoP4->h);
                textprintf_ex(screen, font, SCREEN_W / 2 - 90, 100, makecol(0, 0, 0), -1, "espace pour revenir au menu");
                break;
        }
    }
}

void affiche_score() {
    BITMAP *Score = load_bitmap("../images/Score.bmp", NULL);
    while (key[KEY_SPACE] == 0) {
        blit(Score, screen, 0, 0, (SCREEN_W - Score->w) / 2, (SCREEN_H - Score->h) / 2, Score->w, Score->h);
    }
    destroy_bitmap(Score);
}
