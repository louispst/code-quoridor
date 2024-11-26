// Fonction pour positionner les joueurs sur le plateau
void positionner_joueurs(t_joueur joueurs[], int nombre_joueurs) {
    if (nombre_joueurs == 2) {
        joueurs[0].position_y = 0;
        joueurs[0].position_x = TAILLE_PLATEAU / 2;

        joueurs[1].position_y = TAILLE_PLATEAU - 1;
        joueurs[1].position_x = TAILLE_PLATEAU / 2;

    } else if (nombre_joueurs == 4) {

        joueurs[0].position_y = 0;
        joueurs[0].position_x = 4;

        joueurs[1].position_y = 8;
        joueurs[1].position_x = 4;

        joueurs[2].position_y = 4;
        joueurs[2].position_x = 0;

        joueurs[3].position_y = 4;
        joueurs[3].position_x = 8;

    }
}
void afficher_plateau(t_joueur joueurs[], int nombre_joueurs, int plateau_barriere[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
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
                    // Appliquer une couleur spécifique à chaque joueur
                    switch (i) {
                        case 0: // Premier joueur en rouge
                            Color(12, 0);
                        break;
                        case 1: // Deuxième joueur en bleu
                            Color(9, 0);
                        break;
                        case 2: // Troisième joueur en vert
                            Color(10, 0);
                        break;
                        case 3: // Quatrième joueur en jaune
                            Color(14, 0);
                        break;
                        default:
                            Color(7, 0); // Par défaut en blanc
                    }
                    printf(" %c ", joueurs[i].pion);
                    Color(7, 0); // Réinitialiser la couleur
                    printf("|");
                    joueur_present = 1;
                    break;
                }
            }
            if (!joueur_present && plateau_barriere[y][x]==1) {
                printf(" B |");
            }

            else if (!joueur_present ) {
                printf(" . |");
            }
        }
        printf("\n");
    }
    printf("   +---+---+---+---+---+---+---+---+---+\n");
    afficher_barrieres_restantes(joueurs, nombre_joueurs);
}
