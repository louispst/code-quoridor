#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_PLATEAU 9
#define MAX_MURS 20

// Définition de structures
typedef struct {
    char prenom[50];
    int position_x;
    int position_y;
    int murs_restants;
    int score;
    char pion; // Représente le pion du joueur
} t_joueur;

typedef struct {
    t_joueur joueurs[4];
    int nombre_joueurs;
} EtatJeu;

// Fonction pour copier l'état du jeu
void copier_etat(EtatJeu *destination, EtatJeu *source) {
    *destination = *source; // Copie directe
}

// Fonction pour afficher le menu principal
void afficher_menu() {
    printf("---- Menu Principal Quoridor ----\n");
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Reprendre une partie sauvegardee\n");
    printf("3. Afficher l'aide\n");
    printf("4. Afficher les scores des joueurs\n");
    printf("5. Quitter le jeu\n");
    printf("Entrez votre choix: ");
}

// Fonction pour afficher le plateau
void afficher_plateau(t_joueur joueurs[], int nombre_joueurs) {
    printf("    ");
    for (int i = 1; i <= TAILLE_PLATEAU; i++) {
        printf(" %d  ", i);
    }
    printf("\n");

    for (int y = 0; y < TAILLE_PLATEAU; y++) {
        printf("   +---+---+---+---+---+---+---+---+---+\n");
        printf("%2d |", y + 1);
        for (int x = 0; x < TAILLE_PLATEAU; x++) {
            int joueur_present = 0;
            for (int i = 0; i < nombre_joueurs; i++) {
                if (x == joueurs[i].position_x && y == joueurs[i].position_y) {
                    printf(" %c |", joueurs[i].pion);
                    joueur_present = 1;
                    break;
                }
            }
            if (!joueur_present) {
                printf(" . |");
            }
        }
        printf("\n");
    }
    printf("   +---+---+---+---+---+---+---+---+---+\n");
}
int choisir_joueur_au_hasard(int nombre_joueurs) {
    srand(time(NULL));
    return rand() % nombre_joueurs;
}

// Fonction pour demander le nombre de joueurs et leurs prénoms
void demander_nombre_de_joueurs(int *nombre_joueurs, t_joueur joueurs[]) {
    while (1) {
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs): ");
        scanf("%d", nombre_joueurs);
        if (*nombre_joueurs == 2 || *nombre_joueurs == 4) {
            break;
        } else {
            printf("Le nombre de joueurs doit être 2 ou 4. Veuillez réessayer.\n");
        }
    }

    for (int i = 0; i < *nombre_joueurs; i++) {
        printf("Entrez le prenom du joueur %d: ", i + 1);
        scanf("%s", joueurs[i].prenom);
        joueurs[i].murs_restants = MAX_MURS;
        joueurs[i].score = 0;
    }
}

// Fonction pour choisir les pions des joueurs
void choisir_pions(t_joueur joueurs[], int nombre_joueurs) {
    char choix_pion;
    for (int i = 0; i < nombre_joueurs; i++) {
        printf("Joueur %s, choisissez votre pion : ", joueurs[i].prenom);
        scanf(" %c", &choix_pion);
        joueurs[i].pion = choix_pion;
    }
}

// Fonction pour positionner les joueurs
void positionner_joueurs(t_joueur joueurs[], int nombre_joueurs) {
    if (nombre_joueurs == 2) {
        joueurs[0].position_x = TAILLE_PLATEAU / 2;
        joueurs[0].position_y = 0;

        joueurs[1].position_x = TAILLE_PLATEAU / 2;
        joueurs[1].position_y = TAILLE_PLATEAU - 1;
    } else if (nombre_joueurs == 4) {
        joueurs[0].position_x = 4;
        joueurs[0].position_y = 0;

        joueurs[1].position_x = 4;
        joueurs[1].position_y = 8;

        joueurs[2].position_x = 0;
        joueurs[2].position_y = 4;

        joueurs[3].position_x = 8;
        joueurs[3].position_y = 4;
    }
}

// Fonction pour afficher l'aide
void afficher_aide() {
    printf("---- Aide du Jeu Quoridor ----\n");
    printf("Quoridor est un jeu de strategie où deux ou quatre joueurs s'affrontent.\n");
    printf("1. Le plateau est une grille de 9x9 cases.\n");
    printf("2. Chaque joueur peut se deplacer ou poser une barriere pour gener ses adversaires.\n");
    printf("3. Le premier joueur a atteindre le cote oppose gagne.\n");
    printf("4. Les murs doivent laisser un chemin accessible a tous.\n");
}

// Fonction pour afficher les scores
void afficher_scores(t_joueur joueurs[], int nombre_joueurs) {
    printf("---- Scores des Joueurs ----\n");
    for (int i = 0; i < nombre_joueurs; i++) {
        printf("Joueur %d (%s) : %d points\n", i + 1, joueurs[i].prenom, joueurs[i].score);
    }
}

// Fonction pour passer au joueur suivant
void passer_au_suivant(t_joueur joueurs[], int *joueur_courant, int nombre_joueurs) {
    *joueur_courant = (*joueur_courant + 1) % nombre_joueurs;  // Passer au joueur suivant
    printf("\nC'est au tour de %s de jouer !\n", joueurs[*joueur_courant].prenom);
    afficher_menu_joueur();
}

// Fonction pour annuler un coup
void annuler_coup(EtatJeu *etat_courant, EtatJeu *etat_precedent) {
    copier_etat(etat_courant, etat_precedent);
    printf("Le dernier coup a ete annule.\n");
}

// Menu d'actions pour un joueur
void afficher_menu_joueur() {
    printf("\n--- Menu du joueur ---\n");
    printf("1. Deplacer le pion\n");
    printf("2. Poser une barriere\n");
    printf("3. Passer son tour\n");
    printf("4. Annuler le coup\n");
    printf("Entrez votre choix: ");
}

// Fonction pour afficher le menu des directions
void afficher_menu_direction() {
    printf("\nOù voulez-vous aller ?\n");
    printf("1. Aller en haut\n");
    printf("2. Aller en bas\n");
    printf("3. Aller à gauche\n");
    printf("4. Aller à droite\n");
    printf("Entrez votre choix : ");
}

// Fonction pour déplacer le pion du joueur
void deplacer_pion(t_joueur *joueur) {
    int direction;
    afficher_menu_direction();
    scanf("%d", &direction);

    switch (direction) {
        case 1:
            if (joueur->position_y > 0) {
                joueur->position_y--;
            } else {
                printf("Vous ne pouvez pas aller plus haut !\n");
            }
            break;
        case 2:
            if (joueur->position_y < TAILLE_PLATEAU - 1) {
                joueur->position_y++;
            } else {
                printf("Vous ne pouvez pas aller plus bas !\n");
            }
            break;
        case 3:
            if (joueur->position_x > 0) {
                joueur->position_x--;
            } else {
                printf("Vous ne pouvez pas aller plus à gauche !\n");
            }
            break;
        case 4:
            if (joueur->position_x < TAILLE_PLATEAU - 1) {
                joueur->position_x++;
            } else {
                printf("Vous ne pouvez pas aller plus à droite !\n");
            }
            break;
        default:
            printf("Choix invalide !\n");
    }
}

int main() {
    int choix;
    t_joueur joueurs[4];
    int nombre_joueurs = 0;
    int joueur_courant;
    EtatJeu etat_courant, etat_precedent;

    srand(time(NULL));

    while (1) {

        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Nouvelle partie
                demander_nombre_de_joueurs(&nombre_joueurs, joueurs);
                choisir_pions(joueurs, nombre_joueurs);
                positionner_joueurs(joueurs, nombre_joueurs);

                copier_etat(&etat_courant, &(EtatJeu){.joueurs = joueurs, .nombre_joueurs = nombre_joueurs});
                joueur_courant = choisir_joueur__au_hasard(nombre_joueur)

                afficher_plateau(joueurs, nombre_joueurs);
                printf("\nla partie commence!\n")

                while (1) {
                    printf("C'est au tour de %s de jouer !\n", joueurs[joueur_courant].prenom);
                    copier_etat(&etat_precedent, &etat_courant);
                    afficher_menu_joueur();
                    scanf("%d", &choix);

                    if (choix == 1) {
                        // Déplacer le pion 
                    printf("\nC'est au tour de %s de jouer !\n", joueurs[joueur_courant].prenom);
                    afficher_menu_joueur();
                    scanf("%d", &choix);

                    if (choix == 1) {
                        deplacer_pion(&joueurs[joueur_courant]);
                        afficher_plateau(joueurs, nombre_joueurs);
                    }

                    passer_au_suivant(joueurs, &joueur_courant, nombre_joueurs);  // Passer au joueur suivant
                }
                break;
                    } else if (choix == 2) {
                        // Poser une barrière (à implémenter)
                    } else if (choix == 3) {
                        // Passer son tour
                        joueur_courant = joueur_suivant(joueur_courant, nombre_joueurs);
                        printf("%s a passé son tour.\n", joueurs[joueur_courant].prenom);
                    } else if (choix == 4) {
                        // Annuler le coup
                        annuler_coup(&etat_courant, &etat_precedent);
                        afficher_plateau(etat_courant.joueurs, etat_courant.nombre_joueurs);
                    } else {
                        printf("Choix invalide.\n");
                    }
                }
                break;

            case 2:
                printf("Fonction non implémentee pour l'instant.\n");
                break;

            case 3:
                afficher_aide();
                break;

            case 4:
                afficher_scores(joueurs, nombre_joueurs);
                break;

            case 5:
                printf("Merci d'avoir joue ! A bientot !\n");
                return 0;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    }
    return 0;
}
