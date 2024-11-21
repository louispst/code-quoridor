/*Déclare les structures représentant les joueurs, ainsi que les prototypes des fonctions pour gérer les actions des joueurs, 
comme le déplacement ou la construction de barrières. Pour Alexandre*/
#ifndef
#define
void afficher_menu_joueur();
void afficher_menu_direction();
int joueur_suivant(int joueur_actuel, int nombre_joueurs);
void annuler_coup(EtatJeu *etat_courant, EtatJeu *etat_precedent);
void passer_au_suivant(t_joueur joueurs[], int *joueur_courant, int nombre_joueurs);
#endif
