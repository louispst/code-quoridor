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
