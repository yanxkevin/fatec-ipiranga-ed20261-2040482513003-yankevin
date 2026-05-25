/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio04.c
*/

#include <stdio.h>

int chamadasBusca = 0;

int buscaBinaria(int *vet, int inicio, int fim, int alvo) {

    chamadasBusca++;

    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vet[meio] == alvo) {
        return meio;
    }

    if (alvo < vet[meio]) {
        return buscaBinaria(vet, inicio, meio - 1, alvo);
    }

    return buscaBinaria(vet, meio + 1, fim, alvo);
}

long long potenciaRapida(long long base, int exp) {

    // Caso base
    if (exp == 0) {
        return 1;
    }

    // Caso recursivo
    if (exp % 2 == 0) {

        long long metade = potenciaRapida(base, exp / 2);

        return metade * metade;
    }

    return base * potenciaRapida(base, exp - 1);
}

int main() {

    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};

    int tamanho = sizeof(dados) / sizeof(int);

    int buscas[] = {23, 100, 2};

    for (int i = 0; i < 3; i++) {

        chamadasBusca = 0;

        int resultado = buscaBinaria(dados, 0, tamanho - 1, buscas[i]);

        printf("Busca por %d\n", buscas[i]);

        printf("Resultado = %d\n", resultado);

        printf("Chamadas recursivas = %d\n\n", chamadasBusca);
    }

    printf("2^10 = %lld\n", potenciaRapida(2, 10));
    printf("3^7 = %lld\n", potenciaRapida(3, 7));
    printf("5^0 = %lld\n", potenciaRapida(5, 0));
    printf("7^12 = %lld\n", potenciaRapida(7, 12));

    return 0;
}