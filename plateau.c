// Implémente les fonctions définies dans plateau.h, gérant la création, l'affichage et la mise à jour de l'état du plateau de jeu. Pour Louis
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
