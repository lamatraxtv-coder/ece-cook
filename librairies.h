#ifndef ALLEGRO_LIBRAIRIES_H
#define ALLEGRO_LIBRAIRIES_H

#endif //ALLEGRO_LIBRAIRIES_H
#define MAX_COMMANDES 4
// Path: librairies.h
#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


// Prototypes des fonctions
void affichagechargement();
void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]);
void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], int j1posx, int j1posy, int j2posx, int j2posy, int orienJ1, int orienJ2);
int menu();
int selectniv(int niv_fini);
int jeu(int nivchoisi);
void tuto();
void imagefin();
int ajout_commande(BITMAP * buffer,int nivchoisi, int recettes, BITMAP * recette1, BITMAP* recette2,BITMAP * recette3,int recette[MAX_COMMANDES]);

