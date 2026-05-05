/* 
-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/ 
2 /* FATEC - Ipiranga */ 
3 /* ADS - Estrutura de Dados */ 
4 /* Id da Atividade : N2 -1 */ 
5 /* Objetivo :  Explorar de forma prática e teórica a anatomia de uma Árvore Binária*/ 
7 /* Autor : Yan Kevin de SOusa Costa */ 
8 /* Data :05/05/2026 */ 
9 /* 
-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/ 

#include <minhalib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

No* criarArvoreDinamica() {
    No* raiz = NULL;
    int valor;

    printf("Digite valores (-1 para parar):\n");

    while (1) {
        scanf("%d", &valor);

        if (valor == -1)
            break;

        raiz = inserir(raiz, valor);
    }

    return raiz;
}

void mostrarRaiz(No* raiz) {
    if (raiz)
        printf("Raiz: %d\n", raiz->valor);
}

void nosInternos(No* raiz) {
    if (!raiz) return;

    if (raiz->esq || raiz->dir)
        printf("%d ", raiz->valor);

    nosInternos(raiz->esq);
    nosInternos(raiz->dir);
}

void nosFolhas(No* raiz) {
    if (!raiz) return;

    if (!raiz->esq && !raiz->dir)
        printf("%d ", raiz->valor);

    nosFolhas(raiz->esq);
    nosFolhas(raiz->dir);
}

int altura(No* raiz) {
    if (!raiz) return -1;

    int e = altura(raiz->esq);
    int d = altura(raiz->dir);

    return (e > d ? e : d) + 1;
}

void mostrarNivel(No* raiz, int nivel) {
    if (!raiz) return;

    if (nivel == 0)
        printf("%d ", raiz->valor);
    else {
        mostrarNivel(raiz->esq, nivel - 1);
        mostrarNivel(raiz->dir, nivel - 1);
    }
}

void mostrarTodosNiveis(No* raiz) {
    int h = altura(raiz);

    for (int i = 0; i <= h; i++) {
        printf("\nNivel %d: ", i);
        mostrarNivel(raiz, i);
    }
}

int grau(No* no) {
    int g = 0;
    if (no->esq) g++;
    if (no->dir) g++;
    return g;
}

No* buscar(No* raiz, int valor) {
    if (!raiz || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

int ancestrais(No* raiz, int valor) {
    if (!raiz) return 0;

    if (raiz->valor == valor)
        return 1;

    if (ancestrais(raiz->esq, valor) || ancestrais(raiz->dir, valor)) {
        printf("%d ", raiz->valor);
        return 1;
    }

    return 0;
}

void descendentes(No* no) {
    if (!no) return;

    if (no->esq) printf("%d ", no->esq->valor);
    if (no->dir) printf("%d ", no->dir->valor);

    descendentes(no->esq);
    descendentes(no->dir);
}

int profundidade(No* raiz, int valor, int nivel) {
    if (!raiz) return -1;

    if (raiz->valor == valor)
        return nivel;

    if (valor < raiz->valor)
        return profundidade(raiz->esq, valor, nivel + 1);
    else
        return profundidade(raiz->dir, valor, nivel + 1);
}

int alturaNo(No* no) {
    if (!no) return -1;

    int e = alturaNo(no->esq);
    int d = alturaNo(no->dir);

    return (e > d ? e : d) + 1;
}

void mostrarSubArvore(No* raiz) {
    if (!raiz) return;

    printf("%d ", raiz->valor);
    mostrarSubArvore(raiz->esq);
    mostrarSubArvore(raiz->dir);
}