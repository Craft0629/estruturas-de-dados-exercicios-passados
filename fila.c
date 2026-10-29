#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 5

typedef struct {
    int elementos[CAPACIDADE];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void criarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int isEmpty(Fila *fila) {
    return fila->quantidade == 0;
}

int isFull(Fila *fila) {
    return fila->quantidade == CAPACIDADE;
}

void enfileirar(Fila *fila, int valor) {
    if (isFull(fila)) {
        printf("Fila cheia! Nao e possivel inserir.\n");
        return;
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % CAPACIDADE;
    fila->quantidade++;
    printf("Valor %d inserido na fila.\n", valor);
}

void desenfileirar(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia! Nao ha elementos para remover.\n");
        return;
    }
    int removido = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % CAPACIDADE;
    fila->quantidade--;
    printf("Valor %d removido da fila.\n", removido);
}

void mostrar(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia! Nao ha elementos para mostrar.\n");
        return;
    }
    printf("Fila (inicio -> fim): ");
    for (int i = 0; i < fila->quantidade; i++) {
        int posicao = (fila->inicio + i) % CAPACIDADE;
        printf("%d ", fila->elementos[posicao]);
    }
    printf("\n");
}

int main(void) {
    Fila fila;
    int opcao, valor;
    criarFila(&fila);

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }
                enfileirar(&fila, valor);
                break;
            case 2:
                desenfileirar(&fila);
                break;
            case 3:
                mostrar(&fila);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
