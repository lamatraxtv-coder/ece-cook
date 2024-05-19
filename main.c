#include "librairies.h"

// Fonction principale
int main() {
    allegro_init();//initialisation de allegro
    install_keyboard();//initialisation du clavier
    set_color_depth(desktop_color_depth());//définition de la profondeur de couleur
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 800, 0, 0) != 0){//initialisation du mode graphique
        allegro_message("problème de mode graphique");//affichage d'un message d'erreur
        allegro_exit();//sortie de allegro
        exit(EXIT_FAILURE);//sortie du programme
    }
    int niv_fini=0;
    int select=0;
    int nivchoisi=0;
    int infinite=1;
    srand(time(NULL));
    do {
        select=menu();//fonction qui affiche le menu
        if (select==1){//lance le jeu
            nivchoisi=selectniv(niv_fini);//fonction qui affiche les niveaux
            if (nivchoisi!=0){//si le joueur a choisi un niveau
                jeu(nivchoisi);
            }
        } else if (select==2){//affiche le score
            affiche_score();//fonction qui affiche le score
            continue;//continue la boucle
            break;//sortie de boucle
        }
        else if(select==3){//affiche le tutoriel
            tuto();//fonction qui affiche le tutoriel
            continue;//continue la boucle
            break;//sortie de boucle
        }
    } while (infinite=1);//boucle infinie
    allegro_exit();
    return 0;
}
END_OF_MAIN();