#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct {
    int x, y; // Position du pion
} Player;

char board[SIZE][SIZE]; // Grille du jeu

void initializeBoard() {
    // Remplir le plateau avec des espaces vides
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Placer les murs (pour l'exemple, pas encore implémenté)
    // ...
}

void printBoard(Player players[], int numPlayers) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Afficher les pions des joueurs
            int isPlayer = 0;
            for (int k = 0; k < numPlayers; k++) {
                if (players[k].x == i && players[k].y == j) {
                    printf("%c ", 'A' + k); // Pion du joueur A, B, C, ...
                    isPlayer = 1;
                    break;
                }
            }
            if (!isPlayer) {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int movePlayer(Player *player, char direction) {
    int newX = player->x;
    int newY = player->y;

    // Définir le nouveau mouvement
    switch (direction) {
        case 'w': newX--; break; // Haut
        case 's': newX++; break; // Bas
        case 'a': newY--; break; // Gauche
        case 'd': newY++; break; // Droite
        default: return 0; // Mouvement invalide
    }

    // Vérifier les limites
    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
        return 0; // Mouvement invalide
    }

    player->x = newX;
    player->y = newY;
    return 1; // Mouvement réussi
}

int main() {
    Player players[2] = {{0, 4}, {8, 4}}; // Positions initiales des joueurs
    char direction;
    int currentPlayer = 0;

    initializeBoard();

    while (1) {
        printBoard(players, 2);
        printf("Joueur %c, entrez votre mouvement (w/a/s/d) : ", 'A' + currentPlayer);
        scanf(" %c", &direction);

        if (movePlayer(&players[currentPlayer], direction)) {
            // Vérifier si le joueur a gagné
            if ((currentPlayer == 0 && players[currentPlayer].x == SIZE - 1) || 
                (currentPlayer == 1 && players[currentPlayer].x == 0)) {
                printf("Joueur %c a gagné !\n", 'A' + currentPlayer);
                break;
            }
            currentPlayer = (currentPlayer + 1) % 2; // Passer au joueur suivant
        } else {
            printf("Mouvement invalide !\n");
        }
    }
