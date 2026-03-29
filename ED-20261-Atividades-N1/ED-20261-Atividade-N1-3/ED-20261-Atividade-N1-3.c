#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Estrutura da pilha
typedef struct {
    float itens[MAX];
    int topo;
} Pilha;

// Inicializar pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se está vazia
int vazia(Pilha *p) {
    return p->topo == -1;
}

// Empilhar
void push(Pilha *p, float valor) {
    if (p->topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
    p->itens[++(p->topo)] = valor;
}

// Desempilhar
float pop(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

// Função principal
int main() {
    Pilha p;
    inicializar(&p);

    char expressao[100];
    printf("Digite a expressao RPN (ex: 5 1 2 + 4 * + 3 -):\n");
    fgets(expressao, sizeof(expressao), stdin);

    char *token = strtok(expressao, " \n");

    while (token != NULL) {

        // Se for número
        if (isdigit(token[0])) {
            push(&p, atof(token));
        }
        // Se for operador
        else {
            float b = pop(&p);
            float a = pop(&p);

            switch (token[0]) {
                case '+':
                    push(&p, a + b);
                    break;
                case '-':
                    push(&p, a - b);
                    break;
                case '*':
                    push(&p, a * b);
                    break;
                case '/':
                    push(&p, a / b);
                    break;
                default:
                    printf("Operador inválido: %s\n", token);
                    return 1;
            }
        }

        token = strtok(NULL, " \n");
    }

    printf("Resultado: %.2f\n", pop(&p));

    return 0;
}