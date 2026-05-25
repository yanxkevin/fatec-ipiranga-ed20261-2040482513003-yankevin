/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio05.c
Exercício 05 — Construção e Propriedades Estruturais da Árvore
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    int dado;

    struct No *esq;

    struct No *dir;

} No;

No *criarNo(int valor) {

    No *novo = (No *) malloc(sizeof(No));

    novo->dado = valor;

    novo->esq = NULL;

    novo->dir = NULL;

    return novo;
}

No *inserir(No *raiz, int valor) {

    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->dado) {

        raiz->esq = inserir(raiz->esq, valor);

    } else {

        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

No *buscar(No *raiz, int valor) {

    if (raiz == NULL || raiz->dado == valor) {
        return raiz;
    }

    if (valor < raiz->dado) {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}

int alturaNo(No *no) {

    if (no == NULL) {
        return -1;
    }

    int alturaEsq = alturaNo(no->esq);

    int alturaDir = alturaNo(no->dir);

    if (alturaEsq > alturaDir) {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

int profundidadeNo(No *raiz, int valor, int prof) {

    if (raiz == NULL) {
        return -1;
    }

    if (raiz->dado == valor) {
        return prof;
    }

    if (valor < raiz->dado) {

        return profundidadeNo(raiz->esq, valor, prof + 1);

    } else {

        return profundidadeNo(raiz->dir, valor, prof + 1);
    }
}

int grauNo(No *no) {

    if (no == NULL) {
        return 0;
    }

    int grau = 0;

    if (no->esq != NULL) {
        grau++;
    }

    if (no->dir != NULL) {
        grau++;
    }

    return grau;
}

void imprimirGraus(No *raiz) {

    if (raiz != NULL) {

        imprimirGraus(raiz->esq);

        printf("No %d -> Grau %d\n",
               raiz->dado,
               grauNo(raiz));

        imprimirGraus(raiz->dir);
    }
}

void liberarArvore(No *raiz) {

    if (raiz != NULL) {

        liberarArvore(raiz->esq);

        liberarArvore(raiz->dir);

        free(raiz);
    }
}

int main() {

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int tamanho = sizeof(valores) / sizeof(int);

    No *raiz = NULL;

    for (int i = 0; i < tamanho; i++) {

        raiz = inserir(raiz, valores[i]);
    }

    printf("=== ALTURA DOS NOS ===\n");

    int alturas[] = {50, 30, 70, 20, 10};

    for (int i = 0; i < 5; i++) {

        No *no = buscar(raiz, alturas[i]);

        printf("No %d -> Altura %d\n",
               alturas[i],
               alturaNo(no));
    }

    printf("\n=== PROFUNDIDADE DOS NOS ===\n");

    int profundidades[] = {50, 30, 70, 45, 10};

    for (int i = 0; i < 5; i++) {

        printf("No %d -> Profundidade %d\n",
               profundidades[i],
               profundidadeNo(raiz, profundidades[i], 0));
    }

    printf("\n=== GRAU DOS NOS ===\n");

    imprimirGraus(raiz);

    printf("\n=== ALTURA TOTAL DA ARVORE ===\n");

    printf("Altura da arvore = %d\n",
           alturaNo(raiz));

    liberarArvore(raiz);

    return 0;
}