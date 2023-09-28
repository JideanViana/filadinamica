#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void destruirFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(fila);
}

void inserir(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    printf("\nElemento %d inserido na fila.\n", valor);
}

void remover(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\nA fila esta vazia. Não ha elementos para remover.\n");
        return;
    }

    No* noRemovido = fila->inicio;
    int valorRemovido = noRemovido->valor;

    fila->inicio = fila->inicio->proximo;
    free(noRemovido);

    printf("\nElemento %d removido da fila.\n", valorRemovido);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
}

int buscar(Fila* fila, int valor) {
    No* atual = fila->inicio;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("\nValor %d encontrado na posicao %d da fila.\n", valor, posicao);
            return posicao;
        }

        atual = atual->proximo;
        posicao++;
    }

    printf("\nValor %d não encontrado na fila.\n", valor);
    return -1;
}

void imprimir(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    printf("\nFila: ");
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

int main() {
    Fila* fila = criarFila();
    int opcao, valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir fila\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(fila, valor);
                break;
            case 2:
                remover(fila);
                break;
            case 3:
                printf("\nDigite o valor a ser buscado: ");
                scanf("%d", &valor);
                buscar(fila, valor);
                break;
            case 4:
                imprimir(fila);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    destruirFila(fila);

    return 0;
}
