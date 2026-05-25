/* 
RA: 2040482513003 - Yan Kevin de Sousa Costa
Exercicio06.c
Exercício 06 — Ancestrais, Descendentes e Relatório Completo
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

    int esq = alturaNo(no->esq);

    int dir = alturaNo(no->dir);

    if (esq > dir) {
        return esq + 1;
    }

    return dir + 1;
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

void imprimirAncestral(No *raiz, int valor) {

    if (raiz == NULL) {
        return;
    }

    if (valor < raiz->dado) {

        printf("%d ", raiz->dado);

        imprimirAncestral(raiz->esq, valor);

    } else if (valor > raiz->dado) {

        printf("%d ", raiz->dado);

        imprimirAncestral(raiz->dir, valor);
    }
}

void imprimirDescendentesAux(No *no) {

    if (no != NULL) {

        imprimirDescendentesAux(no->esq);

        printf("%d ", no->dado);

        imprimirDescendentesAux(no->dir);
    }
}

void imprimirDescendentes(No *raiz, int valor) {

    No *no = buscar(raiz, valor);

    if (no == NULL) {
        return;
    }

    imprimirDescendentesAux(no->esq);

    imprimirDescendentesAux(no->dir);
}

int contarDescendentes(No *no) {

    if (no == NULL) {
        return 0;
    }

    return contarDescendentes(no->esq)
         + contarDescendentes(no->dir)
         + 1;
}

void relatorioNo(No *raiz, int valor) {

    No *no = buscar(raiz, valor);

    if (no == NULL) {

        printf("ERRO: No nao encontrado.\n");

        return;
    }

    printf("\n+----------------------------------+\n");

    printf("| RELATORIO DO NO: %d\n", valor);

    printf("+----------------------------------+\n");

    printf("| Profundidade : %d\n",
           profundidadeNo(raiz, valor, 0));

    printf("| Altura       : %d\n",
           alturaNo(no));

    printf("| Grau         : %d\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(raiz, valor);

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(raiz, valor);

    printf("\n");

    printf("| Qtd Descend. : %d\n",
           contarDescendentes(no) - 1);

    printf("+----------------------------------+\n");
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

    relatorioNo(raiz, 50);

    relatorioNo(raiz, 30);

    relatorioNo(raiz, 10);

    relatorioNo(raiz, 70);

    liberarArvore(raiz);

    return 0;
}