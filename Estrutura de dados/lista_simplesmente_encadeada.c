#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    int valor;
    struct sNo* prox;
} No;

void inserir_inicio(No **lista, int n) {
    No *novo = (struct sNo *) malloc(sizeof(struct sNo));
    if (novo != NULL) {
        novo->valor = n;
        novo->prox = *lista;
        *lista = novo;
        printf("O elemento foi inserido com sucesso!\n");
    } else {
        printf("Nao foi possivel alocar memoria\n");
    }
}

void inserir_final(No **lista, int n) {
    No *novo = (struct sNo *) malloc(sizeof(struct sNo));
    if (novo != NULL) {
        novo->valor = n;
        novo->prox = NULL;

        if (*lista == NULL) {
            *lista = novo;
        } else {
            No *ultimo = *lista;
            while (ultimo->prox != NULL) {
                ultimo = ultimo->prox;
            }
            ultimo->prox = novo;
        }
        printf("O elemento foi inserido com sucesso!\n");
    } else {
        printf("Nao foi possivel alocar memoria\n");
    }
}

void remover_final(No **lista) {
    if (*lista == NULL) {
        printf("A lista esta vazia\n");
        return;
    }
    
    No *temporario = *lista;
    No *anterior = NULL;

    while (temporario->prox != NULL) {
        anterior = temporario;
        temporario = temporario->prox;
    }

    if (anterior != NULL) {
        anterior->prox = NULL;
    } else {
        *lista = NULL;
    }

    free(temporario);
    printf("O elemento foi removido com sucesso!\n");
}

void remover_inicio(No **lista) {
    if (*lista == NULL) {
        printf("A lista esta vazia\n");
        return;
    }
    
    No *temporario = *lista;
    *lista = temporario->prox;
    free(temporario);
    printf("O elemento foi removido com sucesso!\n");
}

void mostrar(No *lista) {
    if (lista == NULL) {
        printf("A lista esta vazia\n");
        return;
    }
    
    int posicao = 1;
    No *mostrar = lista;
    while (mostrar != NULL) {
        printf("O elemento %d tem o valor %d\n", posicao, mostrar->valor);
        mostrar = mostrar->prox;
        posicao++;
    }
}

int main() {
    No *lista = NULL;
    int esc = 0;
    int valor;

    do {
        printf("Selecione uma das opcoes abaixo\n");
        printf("1. Inserir elemento no inicio\n2. Inserir no elemento no final\n3. Remover elemento\n4. Exibir elementos na lista\n0. sair do programa\n");
        scanf("%d", &esc);

        switch (esc) {
            case 1:
                printf("Digite o valor da informacao\n");
                scanf("%d", &valor);
                inserir_inicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor da informação\n");
                scanf("%d", &valor);
                inserir_final(&lista, valor);
                break;
            case 3:
                printf("Digite (1) para remover o primeiro elemento. (2) para remover o ultimo elemento\n");
                scanf("%d", &esc);
                if (esc != 1 && esc != 2) {
                    printf("Opcao invalida, por favor escolha uma das opcoes\n");
                } else {
                    if (esc == 1) {
                        remover_inicio(&lista);
                    } else {
                        remover_final(&lista);
                    }
                }
                break;
            case 4:
                mostrar(lista);
                break;
            case 0:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida, por favor escolha uma das opcoes\n");
                break;
        }
    } while (esc != 0);
    
    // Libera memória
    while (lista != NULL) {
        No *temporario = lista;
        lista = lista->prox;
        free(temporario);
    }

    return 0;
}
