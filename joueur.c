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
void passer_au_suivant(t_joueur joueurs[], int *joueur_courant, int nombre_joueurs) {
    *joueur_courant = (*joueur_courant + 1) % nombre_joueurs;  // Passer au joueur suivant
    printf("\nC'est au tour de %s de jouer !\n", joueurs[*joueur_courant].prenom);
    afficher_menu_joueur();
}

