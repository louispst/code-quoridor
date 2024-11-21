// Fonction pour afficher le menu principal
void afficher_menu() {
    printf("---- Menu Principal Quoridor ----\n");
    printf("1. Lancer une nouvelle partie\n");
    printf("2. Reprendre une partie sauvegardee\n");
    printf("3. Afficher l'aide\n");
    printf("4. Afficher les scores des joueurs\n");
    printf("5. Quitter le jeu\n");
    printf("Entrez votre choix: ");

// Fonction pour demander le nombre de joueurs et leurs prénoms
void demander_nombre_de_joueurs(int *nombre_joueurs, t_joueur joueurs[]) {
    while (1) {
        printf("Entrez le nombre de joueurs (2 ou 4 joueurs): ");
        scanf("%d", nombre_joueurs);
        if (*nombre_joueurs == 2 || *nombre_joueurs == 4) {
            break;
        } else {
            printf("Le nombre de joueurs doit etre 2 ou 4. Veuillez reessayer.\n");
        }
    }

    for (int i = 0; i < *nombre_joueurs; i++) {
        printf("Entrez le prenom du joueur : %d\n ", i + 1);
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

