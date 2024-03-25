#ifndef ALLEGRO_LIBRAIRIES_H
#define ALLEGRO_LIBRAIRIES_H

#endif //ALLEGRO_LIBRAIRIES_H

// Path: librairies.h
#include <allegro.h>
#include <stdio.h>
#include <unistd.h>


BITMAP *PERSO1_O[4]; // Tableau pour les 4 orientations du joueur 1
BITMAP *PERSO2_O[4]; // Tableau pour les 4 orientations du joueur 2

// Prototypes des fonctions
void affichagechargement();
void load_player_images();
void image_joueur(BITMAP *screen, int j1posx, int j1posy, int j2posx, int j2posy, int orienJ1, int orienJ2);
int menu();
int selectniv(int niv_fini);
int jeu(int nivchoisi);
