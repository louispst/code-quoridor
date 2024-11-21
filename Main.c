//Le point d'entrée du programme. Il initialise le jeu et appelle les sous-programmes nécessaires pour gérer le déroulement de la partie. Pour Juliette
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
                joueur_courant = rand() % nombre_joueurs;

                afficher_plateau(joueurs, nombre_joueurs);

                while (1) {
                    printf("C'est au tour de %s de jouer !\n", joueurs[joueur_courant].prenom);
                    copier_etat(&etat_precedent, &etat_courant);
                    afficher_menu_joueur();
                    scanf("%d", &choix);

                    if (choix == 1) {
                        // Déplacer le pion (à implémenter)
                    } else if (choix == 2) {
                        // Poser une barrière (à implémenter)
                    } else if (choix == 3) {
                        // Passer son tour
                        joueur_courant = joueur_suivant(joueur_courant, nombre_joueurs);
                        printf("%s a passe son tour.\n", joueurs[joueur_courant].prenom);
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
                printf("Fonction non implementee pour l'instant.\n");
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
