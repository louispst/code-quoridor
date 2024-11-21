//Contient les constantes et structures liées au jeu, ainsi que les prototypes des fonctions pour initialiser, gérer et terminer le jeu. Pour Dory
#ifndef
#define
void deplacer_pion(t_joueur *joueur);
void afficher_scores(t_joueur joueurs[], int nombre_joueurs);
void charger_scores(t_joueur joueurs[], int *nombre_joueurs);
void reinitialiser_partie(t_joueur joueurs[], int nombre_joueurs, int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void sauvegarder_scores(t_joueur joueurs[], int nombre_joueurs);
void verifier_fin_de_partie(t_joueur joueurs[], int nombre_joueurs);
void reinitialiser_plateau(int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]);
void calculer_score_final(t_joueur joueurs[], int nombre_joueurs, int gagnant);
#endif
