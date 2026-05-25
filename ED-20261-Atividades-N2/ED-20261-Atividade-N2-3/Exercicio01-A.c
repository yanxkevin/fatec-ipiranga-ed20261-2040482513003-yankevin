/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio01-A.c
Exercício 01 — Ponteiros em C
*/

#include <stdio.h>

void trocar(int *a, int *b) {

    *a = *a + *b;

    *b = *a - *b;

    *a = *a - *b;
}

int main() {
    int x = 10;
    int y = 20;

    printf("ANTES DA TROCA:\n");

    printf("Endereco de x: %p\n", (void*)&x);

    printf("Endereco de y: %p\n", (void*)&y);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    trocar(&x, &y);

    printf("\nDEPOIS DA TROCA:\n");

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}