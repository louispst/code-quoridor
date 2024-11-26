
int main() {
    int choix;
    t_joueur joueurs[4];
    int nombre_joueurs = 0;
    int joueur_courant;
    EtatJeu etat_courant, etat_precedent;
    int partie_terminee = 0;
    int plateau_barriere[9][9]={0};

    srand(time(NULL));

    while (1) {
        afficher_menu();
        if (scanf("%d", &choix) != 1) {
            printf("Entree invalide. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');  // Vider le buffer
            continue;
        }
        while (getchar() != '\n');  // Vider le buffer après une lecture réussie

        switch (choix) {
            case 1: {
                demander_nombre_de_joueurs(&nombre_joueurs, joueurs);
                choisir_pions(joueurs, nombre_joueurs);
                positionner_joueurs(joueurs, nombre_joueurs);
                initialiser_barrieres(joueurs, nombre_joueurs);  // Initialise les barrières


                joueur_courant = choisir_joueur_au_hasard(nombre_joueurs);
                printf("\nLe joueur %s commence la partie.\n", joueurs[joueur_courant].prenom);

                etat_courant.nombre_joueurs = nombre_joueurs;
                for (int i = 0; i < nombre_joueurs; i++) {
                    etat_courant.joueurs[i] = joueurs[i];
                }
                copier_etat(&etat_precedent, &etat_courant);

                afficher_plateau(joueurs, nombre_joueurs, plateau_barriere);
                printf("\nLa partie commence !\n");

                partie_terminee = 0;
                while (!partie_terminee) {
                    printf("\nC'est au tour de %s de jouer !\n", joueurs[joueur_courant].prenom);
                    afficher_menu_joueur();

                    if (scanf("%d", &choix) != 1) {
                        printf("Entree invalide. Veuillez entrer un nombre.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');  // Vider le buffer après une lecture réussie

                    switch (choix) {
                        case 1:
                            copier_etat(&etat_precedent, &etat_courant);
                            deplacer_pion(&joueurs[joueur_courant], plateau_barriere, nombre_joueurs, joueurs);

                            afficher_plateau(joueurs, nombre_joueurs, plateau_barriere);
                            // Vérification de victoire après le déplacement
                            if (verifier_victoire(joueurs, nombre_joueurs)) {
                                partie_terminee = 1;
                                break;
                            }
                        break;

                        case 2:
                            if (joueurs[joueur_courant].murs_restants > 0) {
                                poser_barriere( plateau_barriere, &joueurs[joueur_courant],nombre_joueurs, joueurs);
                                afficher_plateau(joueurs, nombre_joueurs, plateau_barriere);
                            } else {
                                printf("Vous n'avez plus de barrieres restantes !\n");
                            }

                        break;

                        case 3:
                            printf("%s a passe son tour.\n", joueurs[joueur_courant].prenom);
                            break;

                        case 4:
                            copier_etat(&etat_courant, &etat_precedent);
                            afficher_plateau(etat_courant.joueurs, etat_courant.nombre_joueurs, plateau_barriere);
                            printf("Le dernier coup a ete annule.\n");
                            passer_au_suivant(joueurs,&joueur_courant,nombre_joueurs);
                            continue;

                        default:
                            printf("Choix invalide, veuillez reessayer.\n");
                            continue;
                    }

                    if (partie_terminee) {
                        break;  // Sortir de la boucle si la partie est terminée
                    }

                    passer_au_suivant(joueurs, &joueur_courant, nombre_joueurs);
                }
                break;
            }

            case 2:
                poser_barriere(plateau_barriere, &joueurs[joueur_courant], nombre_joueurs, joueurs);
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

