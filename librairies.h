#ifndef ALLEGRO_LIBRAIRIES_H
#define ALLEGRO_LIBRAIRIES_H

#endif //ALLEGRO_LIBRAIRIES_H
#define MAX_COMMANDES 4
#define MAX_PAGE_TUTO 4
// Path: librairies.h
#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int posx, posy;
    int combinaison;
    int orientation;
} Joueur;

// Prototypes des fonctions
void affichagechargement();
void animation_bouil(int nivchoisi, BITMAP * buffer,int occupation);
void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]);
void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], Joueur joueur1, Joueur joueur2);
int menu();
int selectniv(int niv_fini);
int jeu(int nivchoisi);
void tuto();
void affiche_score();
void imagefin();
int gerer_commandes(BITMAP *buffer, int recettes, BITMAP *recette1, BITMAP *recette2, BITMAP *recette3, int recette[MAX_COMMANDES], int index);
int menu_cru(BITMAP *buffer,int nivchoisi, int combinaison,int capte);
void affiche_commandes(BITMAP *buffer, int recette[MAX_COMMANDES], BITMAP *recette1, BITMAP *recette2, BITMAP *recette3);
void affiche_page_tuto(BITMAP *buffer, int page, BITMAP *tuto1, BITMAP *tuto2, BITMAP *tuto3, BITMAP *tuto4);
void affiche_score();
void score();
void tables(Joueur *joueur, int *table, int nivchoisi);