//complémente les fonctions définies dans jeu.h, y compris la logique principale du jeu, la gestion des tours, et les conditions de victoire. Pour Dory

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
// Fonction pour afficher les scores et informations des joueurs
void afficher_scores(t_joueur joueurs[], int nombre_joueurs) {
    // Vérification si des joueurs sont définis
    if (nombre_joueurs <= 0) {
        printf("Aucun joueur n'a été défini. Veuillez lancer une partie.\n");
        return;

        printf("---- Scores et Informations des Joueurs ----\n");
        printf("| %10s | %10s | %15s | %5s |\n", "Joueur", "Score", "Murs Restants", "Pion");  //affichage du joueur, du score, des murs restants a chaque joueurs et du pion
        for (int i = 0; i < nombre_joueurs; i++) {
            printf("| %10s | %10d | %15d | %5c |\n",
                   joueurs[i].prenom, joueurs[i].score, joueurs[i].murs_restants, joueurs[i].pion);
        }
    }
}
