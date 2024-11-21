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
void verifier_score(t_joueur *joueur) {
    // Vérifier si le pion a atteint les coordonnées finales
    if ((joueur->pion == 'A' && joueur->position_x == 5 && joueur->position_y == 9) ||
        (joueur->pion == 'B' && joueur->position_x == 5 && joueur->position_y == 1) ||
        (joueur->pion == 'C' && joueur->position_x == 1 && joueur->position_y == 5) ||
        (joueur->pion == 'D' && joueur->position_x == 9 && joueur->position_y == 5)) {
        joueur->score += 1; // Ajouter 1 au score
        printf("BRAVO, %s a atteint sa destination finale ! Score : %d\n", joueur->prenom, joueur->score);
    }
}

void charger_scores(t_joueur joueurs[], int *nombre_joueurs) {
    FILE *fichier = fopen("scores.txt", "r");  		// Ouvrir le fichier en lecture
    if (fichier == NULL) return;  		// Si le fichier n'existe pas, on sort de la fonction

    char prenom[50];
    int score;
    if (fscanf(fichier, "%s %d", prenom, &score)    == 2) {      // Si fscanf a réussi à lire les deux valeurs dans le fichier
        // Chercher si le joueur existe déjà
        int trouve = 0;
        for (int i = 0; i < *nombre_joueurs; i++) {
            if (strcmp(joueurs[i].prenom, prenom)   == 0) {         	//on compare le prenom avec les prenoms existants
                joueurs[i].score += score; 		 // Ajouter le score existant
                trouve = 1;
                break;
            }
        }
        // Si le joueur n'existe pas, l'ajouter
        if (trouve == 0 && *nombre_joueurs < 4) {			//si le prenom n’a pas été trouvé et que le nombre de joueurs est inferieur a 4
            strcpy(joueurs[*nombre_joueurs].prenom, prenom); 	// copie son prenom dans la structure joueur
            joueurs[*nombre_joueurs].score = score;     		//assigne son score
            (*nombre_joueurs)++;					//ajoute 1 joueur en plus
        }
    } else {
        printf( "Erreur, impossible d’ouvrir le fichier") ;
    }
    fclose(fichier);
}
void reinitialiser_partie(t_joueur joueurs[], int nombre_joueurs, int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    // Réinitialiser les positions et attributs des joueurs
    for (int i = 0; i < nombre_joueurs; i++) {
        // Réinitialiser la position du joueur à sa position de départ
        if (nombre_joueurs == 2) {
            // Joueur 1 au centre en haut, Joueur 2 au centre en bas
            joueurs[0].position_y = 1;
            joueurs[0].position_x = 5;
            joueurs[1].position_y = 9;
            joueurs[1].position_x = 5;
        } else if (nombre_joueurs == 4) {
            // Joueur 1 en haut au centre, Joueur 2 en bas au centre, Joueur 3 au centre à gauche, Joueur 4 au centre à droite
            joueurs[0].position_y = 1;
            joueurs[0].position_x = 5;
            joueurs[1].position_y = 9;
            joueurs[1].position_x = 5;
            joueurs[2].position_y = 5;
            joueurs[2].position_x = 1;
            joueurs[3].position_y = 5;
            joueurs[3].position_x = 9;
        }
        // Parcourir chaque case du plateau et la réinitialiser à 0 (case vide)
        for (int y = 0; y < TAILLE_PLATEAU; y++) {
            for (int x = 0; x < TAILLE_PLATEAU; x++) {
                plateau[y][x] = '.'; // ‘.’ représente une case vide, sans barrière
            }
        }
                // Réinitialiser les autres attributs comme le score et le nombre de murs
                joueurs[i].murs_restants = MAX_MURS;
    }
}
void sauvegarder_scores(t_joueur joueurs[], int nombre_joueurs) {
    FILE *fichier = fopen("scores.txt", "a");  // "a" pour ajouter à la fin du fichier
    if (fichier == NULL) {		// Si le fichier n'existe pas, on sort de la fonction
        printf("Erreur lors de l'ouverture du fichier pour la sauvegarde des scores.\n");
        return;
    }
    for (int i = 0; i < nombre_joueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].prenom, joueurs[i].score);     // Sauvegarder le prénom et le score
    }
    fclose(fichier);
}
// Fonction pour vérifier si la partie est terminée
void verifier_fin_de_partie(t_joueur joueurs[], int nombre_joueurs) {
    for (int i = 0; i < nombre_joueurs; i++) {
        if (joueurs[i].score == 5) {			//si le score d’un joueur est egal a 5
            printf("Fin de partie ! Le joueur %s a gagné avec un score de 5 !\n", joueurs[i].prenom);
        }
    }
}
void reinitialiser_plateau(int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]) {
    // Parcourir chaque case du plateau et la réinitialiser à 0 (case vide)
    for (int y = 0; y < TAILLE_PLATEAU; y++) {
        for (int x = 0; x < TAILLE_PLATEAU; x++) {
            plateau[y][x] = 0; // 0 représente une case vide, sans barrière
        }
    }
}
//fonction qui calcule le score finale
void calculer_score_final(t_joueur joueurs[], int nombre_joueurs, int gagnant){
    joueurs[gagnant].score += 5; 			// Ajouter 5 points au gagnant
printf("Le gagnant est %s, il a gagné 5 points. Score final : %d\n", joueurs[gagnant].prenom, joueurs[gagnant].score);
sauvegarder_scores(joueurs, nombre_joueurs);     // Sauvegarder les scores après la partie
}

