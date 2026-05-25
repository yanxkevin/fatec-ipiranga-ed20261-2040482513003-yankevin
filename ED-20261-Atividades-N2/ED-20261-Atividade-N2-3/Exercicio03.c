/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio03.c
*/

#include <stdio.h>

int movimentos = 0;

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {

    if (n == 1) {

        for (int i = 0; i < nivel * 2; i++) {
            printf(" ");
        }

        printf("[Nivel %d] Mover disco 1 de %c para %c\n",
               nivel, origem, destino);

        movimentos++;

        return;
    }

    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    for (int i = 0; i < nivel * 2; i++) {
        printf(" ");
    }

    printf("[Nivel %d] Mover disco %d de %c para %c\n",
           nivel, n, origem, destino);

    movimentos++;

    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main() {

    int testes[] = {1, 3, 4};

    for (int i = 0; i < 3; i++) {

        int n = testes[i];

        movimentos = 0;

        printf("\nTORRES DE HANOI - n = %d\n\n", n);

        hanoi(n, 'A', 'C', 'B', 0);

        printf("\nMovimentos realizados: %d\n", movimentos);

        printf("Esperado: %d\n", (1 << n) - 1);
    }

    return 0;
}