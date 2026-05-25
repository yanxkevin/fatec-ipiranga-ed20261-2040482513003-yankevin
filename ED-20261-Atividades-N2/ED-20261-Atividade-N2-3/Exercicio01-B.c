/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio01-B.c
Exercício 01 — Parte B
*/

#include <stdio.h>

int main() {
    int v[] = {10, 20, 30, 40, 50};

    int *inicio = v;

    int *fim = v + 4;

    int soma = 0;

    printf("VETOR ORIGINAL:\n");

    while (inicio <= fim) {

        printf("Valor: %d | Endereco: %p\n", *inicio, (void*)inicio);

        soma += *inicio;

        inicio++;
    }

    printf("\nSoma = %d\n", soma);

    inicio = v;
    fim = v + 4;

    while (inicio < fim) {

        int temp = *inicio;

        *inicio = *fim;

        *fim = temp;

        inicio++;
        fim--;
    }

    printf("\nVETOR INVERTIDO:\n");

    inicio = v;

    while (inicio < v + 5) {

        printf("%d ", *inicio);

        inicio++;
    }

    printf("\n");

    return 0;
}