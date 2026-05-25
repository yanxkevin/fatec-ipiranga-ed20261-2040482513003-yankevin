/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio02.c
*/

#include <stdio.h>

float calcularMedia(float *vet, int n) {

    float soma = 0;

    float *ptr = vet;

    for (int i = 0; i < n; i++) {

        soma += *ptr;

        ptr++;
    }

    return soma / n;
}

void encontrarExtremos(float *vet, int n, float *maior, float *menor) {

    float *ptr = vet;

    *maior = *ptr;
    *menor = *ptr;

    ptr++;

    for (int i = 1; i < n; i++) {

        if (*ptr > *maior) {
            *maior = *ptr;
        }

        if (*ptr < *menor) {
            *menor = *ptr;
        }

        ptr++;
    }
}

void normalizar(float *vet, int n) {

    float maior = *vet;

    float *ptr = vet;

    for (int i = 0; i < n; i++) {

        if (*ptr > maior) {
            maior = *ptr;
        }

        ptr++;
    }

    ptr = vet;

    for (int i = 0; i < n; i++) {

        *ptr = *ptr / maior;

        ptr++;
    }
}

void imprimirVetor(float *vet, int n, const char *titulo) {

    printf("\n%s\n", titulo);

    float *ptr = vet;

    for (int i = 0; i < n; i++) {

        printf("%.2f ", *ptr);

        ptr++;
    }

    printf("\n");
}

int main() {

    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    int n = sizeof(notas) / sizeof(float);

    float media;
    float maior;
    float menor;

    imprimirVetor(notas, n, "ANTES DA NORMALIZACAO");

    media = calcularMedia(notas, n);

    encontrarExtremos(notas, n, &maior, &menor);

    printf("\nMedia = %.2f\n", media);
    printf("Maior = %.2f\n", maior);
    printf("Menor = %.2f\n", menor);

    normalizar(notas, n);

    imprimirVetor(notas, n, "DEPOIS DA NORMALIZACAO");

    return 0;
}