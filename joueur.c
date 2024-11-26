//Implémente les fonctions définies dans joueur.h, gérant les actions des joueurs et leurs interactions avec le jeu. Pour Juliette
/ Fonction pour afficher le menu d'actions d'un joueur
void afficher_menu_joueur() {
    printf("\n--- Menu du joueur ---\n");
    printf("1. Deplacer le pion\n");
    printf("2. Poser une barrire\n");
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

// Fonction pour passer au joueur suivant
int joueur_suivant(int joueur_actuel, int nombre_joueurs) {
    return (joueur_actuel + 1) % nombre_joueurs;
}

// Fonction pour annuler un coup
void annuler_coup(EtatJeu *etat_courant, EtatJeu *etat_precedent) {
    copier_etat(etat_courant, etat_precedent);
    printf("Le dernier coup a ete annule.\n");
}

// Fonction pour passer au joueur suivant
void passer_au_suivant(t_joueur joueurs[], int *joueur_courant, int nombre_joueurs) {
    *joueur_courant = (*joueur_courant + 1) % nombre_joueurs;  // Passer au joueur suivant
    printf("\nC'est au tour de %s de jouer !\n", joueurs[*joueur_courant].prenom);
    afficher_menu_joueur();
}

void deplacer_pion(t_joueur *joueur, int plateau_barriere[TAILLE_PLATEAU][TAILLE_PLATEAU], int nombre_joueurs, t_joueur joueurs[]) {
    int direction;
    int deplacement_valide = 0;

    while (!deplacement_valide) {
        afficher_menu_direction();
        scanf("%d", &direction);

        switch (direction) {
            case 1:
                if (joueur->position_y > 0 && plateau_barriere[joueur->position_y - 1][joueur->position_x] == 0) {
                    // Vérifier qu'il n'y a pas d'autre joueur sur la case
                    int joueur_present = 0;
                    for (int i = 0; i < nombre_joueurs; i++) {
                        if (joueur->position_y - 1 == joueurs[i].position_y && joueur->position_x == joueurs[i].position_x) {
                            joueur_present++;
                        }
                    }
                    if (joueur_present == 0) {
                        joueur->position_y--; // Déplacement valide
                        deplacement_valide = 1;
                    } else {
                        printf("Un autre joueur est deja sur cette case !\n");
                    }
                } else {
                    printf("Vous ne pouvez pas aller plus haut !\n");
                }
                break;

            case 2:
                if (joueur->position_y < TAILLE_PLATEAU - 1 && plateau_barriere[joueur->position_y + 1][joueur->position_x] == 0) {
                    joueur->position_y++;
                    deplacement_valide = 1;
                } else {
                    printf("Vous ne pouvez pas aller plus bas !\n");
                }
                break;

            case 3:
                if (joueur->position_x > 0 && plateau_barriere[joueur->position_y][joueur->position_x - 1] == 0) {
                    joueur->position_x--;
                    deplacement_valide = 1;
                } else {
                    printf("Vous ne pouvez pas aller plus a gauche !\n");
                }
                break;

            case 4:
                if (joueur->position_x < TAILLE_PLATEAU - 1 && plateau_barriere[joueur->position_y][joueur->position_x + 1] == 0) {
                    joueur->position_x++;
                    deplacement_valide = 1;
                } else {
                    printf("Vous ne pouvez pas aller plus a droite !\n");
                }
                break;

            default:
                printf("Choix invalide !\n");
        }

        if (!deplacement_valide) {
            direction = faire_rejouer(); // Appeler la fonction pour obtenir une nouvelle direction
        }
    }
}

int faire_rejouer() {
    int nouvelle_direction;
    printf("Deplacement invalide. Veuillez choisir une nouvelle direction :\n");
    afficher_menu_direction(); // On réaffiche le menu des directions
    scanf("%d", &nouvelle_direction);
    return nouvelle_direction;
}



