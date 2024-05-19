#ifndef ALLEGRO_LIBRAIRIES_H
#define ALLEGRO_LIBRAIRIES_H

#endif //ALLEGRO_LIBRAIRIES_H
#define MAX_COMMANDES 4
#define MAX_PAGE_TUTO 4
//librairies.h
#include <allegro.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


typedef struct{//structure pour les joueurs
    int posx, posy;//position x et y
    int combinaison;//combinaison de touches
    int orientation;//orientation du joueur
} Joueur;

void affichagechargement();//fonction qui affiche le chargement
void animation_bouil(int nivchoisi, BITMAP * buffer,int occupation);//fonction qui affiche l'animation de la bouilloire
void load_player_images(BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4]);//fonction qui charge les images des joueurs
void image_joueur(BITMAP *buffer, BITMAP *PERSO1_O[4], BITMAP *PERSO2_O[4], Joueur joueur1, Joueur joueur2);//fonction qui affiche les joueurs
int menu();//fonction qui affiche le menu
int selectniv(int niv_fini);//fonction qui affiche les niveaux
int jeu(int nivchoisi);//fonction qui lance le jeu
void tuto();//fonction qui affiche le tutoriel
void affiche_score();//fonction qui affiche le score
void imagefin();//fonction qui affiche l'image de fin
int gerer_commandes(BITMAP *buffer, int recettes, BITMAP *recette1, BITMAP *recette2, BITMAP *recette3, int recette[MAX_COMMANDES], int index,int fonction,int combinaison,int score);//fonction qui gère les commandes
int menu_cru(BITMAP *buffer,int nivchoisi, int combinaison,int capte);//fonction qui affiche le menu des ingrédients crus
void affiche_commandes(BITMAP *buffer, int recette[MAX_COMMANDES], BITMAP *recette1, BITMAP *recette2, BITMAP *recette3);//fonction qui affiche les commandes
void affiche_page_tuto(BITMAP *buffer, int page, BITMAP *tuto1, BITMAP *tuto2, BITMAP *tuto3, BITMAP *tuto4);//fonction qui affiche les pages du tutoriel
void affiche_score();//fonction qui affiche le score//
void score();//fonction qui gère le score
void tables(Joueur *joueur, int *table, int nivchoisi);//fonction qui gère les tables