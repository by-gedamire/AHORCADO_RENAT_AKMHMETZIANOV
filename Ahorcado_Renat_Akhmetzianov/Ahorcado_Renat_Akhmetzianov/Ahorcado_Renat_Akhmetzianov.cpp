#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void printMap(char map[SIZE][SIZE], int playerX, int playerY) {
    system("cls"); 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("X ");
            }
            else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int ahorcado() {
    char palabra[20] = "coche";  
    char intento[20];
    printf("Has encontrado el reto del ahorcado. Adivina la palabra: ");

    fgets(intento, 20, stdin);

    intento[strcspn(intento, "\n")] = 0;

    if (strcmp(intento, palabra) == 0) {
        printf("Correcto! Has adivinado la palabra.\n");
        return 1;
    }
    else {
        printf("Incorrecto. Perdiste 1 vida.\n");
        return 0; 
    }
}

int main() {
    char map[SIZE][SIZE];
    int playerX = 0, playerY = 0;  
    int vidas = 3;
    int gameOver = 0;
    char buffer[10]; 

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = '-';
        }
    }

    map[4][4] = 'R';

    while (!gameOver) {
        printMap(map, playerX, playerY);
        printf("Tienes %d vidas.\n", vidas);
        printf("Moverte con W (arriba), A (izquierda), S (abajo), D (derecha): ");

        fgets(buffer, 10, stdin); 
        char movimiento = buffer[0]; 

        if (movimiento == 'W' || movimiento == 'w') {
            if (playerX > 0) playerX--;
        }
        else if (movimiento == 'S' || movimiento == 's') {
            if (playerX < SIZE - 1) playerX++;
        }
        else if (movimiento == 'A' || movimiento == 'a') {
            if (playerY > 0) playerY--;
        }
        else if (movimiento == 'D' || movimiento == 'd') {
            if (playerY < SIZE - 1) playerY++;
        }

        if (playerX == 4 && playerY == 4) {
            if (ahorcado()) {
                gameOver = 1;  
            }
            else {
                vidas--; 
                if (vidas == 0) {
                    printf("Te has quedado sin vidas. Fin del juego.\n");
                    gameOver = 1;  
                }
            }
        }
    }

    return 0;
}
