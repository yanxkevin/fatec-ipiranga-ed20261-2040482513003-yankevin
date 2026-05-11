-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/
2 /* FATEC - Ipiranga */
3 /* ADS - Estrutura de Dados */
4 /* Id da Atividade : N2 -2 */
5 /* Objetivo :  Entender como a informação da Altura (H) viaja abaixo para cima na estrutura */
7 /* Autor : Yan Kevin de SOusa Costa */
8 /* Data :12/05/2026 */
9 /*
-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/
#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    struct No *esq;
    struct No *dir;
};


struct No* criarNo(int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


int calcularAltura(struct No* n) {
    if (n == NULL) {
        return -1;     }


    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    if (alturaEsq > alturaDir) {
        return 1 + alturaEsq;
    } else {
        return 1 + alturaDir;
    }
}


int obterFB(struct No* n) {
    if (n == NULL) {
        return 0;
    }


    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);


    return alturaEsq - alturaDir;
}


int main() {


    struct No* n20 = criarNo(20);
    struct No* n10 = criarNo(10);
    struct No* n5  = criarNo(5);
    struct No* n2  = criarNo(2);


    n20->esq = n10;
    n10->esq = n5;
    n5->esq = n2;


        int fb = obterFB(n20);


    printf("Fator de Balanceamento da raiz: %d\n", fb);


    return 0;
}
