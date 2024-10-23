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

