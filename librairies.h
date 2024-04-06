#ifndef ALLEGRO_LIBRAIRIES_H
#define ALLEGRO_LIBRAIRIES_H

#endif //ALLEGRO_LIBRAIRIES_H

// Path: librairies.h
#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


BITMAP * PERSO1_O[4];
BITMAP * PERSO2_O[4];


// Prototypes des fonctions
void affichagechargement();
void load_player_images();
void image_joueur( BITMAP * buffer,int j1posx, int j1posy, int j2posx, int j2posy, int orienJ1, int orienJ2);
int menu();
int selectniv(int niv_fini);
int jeu(int nivchoisi);
void tuto();
int ajout_commande(BITMAP * buffer,int nivchoisi, int recettes, BITMAP * commande);

