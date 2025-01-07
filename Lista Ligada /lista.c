#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

// Função para inicializar a lista
void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

// Função para inserir um elemento na lista ordenada
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    // Criar novo elemento
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    if (!novo) return false; // Falha na alocação de memória

    novo->reg = reg;
    novo->ant = NULL;
    novo->prox = NULL;

    // Caso 1: Lista vazia
    if (l->inicio == NULL) {
        l->inicio = novo;
        return true;
    }

    // Percorrer a lista para encontrar a posição correta
    PONT atual = l->inicio;
    PONT anterior = NULL;

    while (atual != NULL && atual->reg.chave < reg.chave) {
        anterior = atual;
        atual = atual->prox;
    }

    // Caso 2: Verificar duplicação
    if (atual != NULL && atual->reg.chave == reg.chave) {
        free(novo); // Não inserir elementos repetidos
        return false;
    }

    // Caso 3: Inserção no início
    if (anterior == NULL) {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
        return true;
    }

    // Caso 4: Inserção no meio ou no final
    novo->ant = anterior;
    novo->prox = atual;
    anterior->prox = novo;

    if (atual != NULL) { // Atualizar ponteiro 'ant' do próximo elemento, se existir
        atual->ant = novo;
    }

    return true;
}

// Função para exibir os elementos da lista
void exibirLista(LISTA* l) {
    PONT atual = l->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para exibir a lista ao contrário
void exibirListaReversa(LISTA* l) {
    if (l->inicio == NULL) return;

    // Ir para o último elemento
    PONT atual = l->inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Exibir do final para o início
    printf("Lista reversa: ");
    while (atual != NULL) {
        printf("%d ", atual->reg.chave);
        atual = atual->ant;
    }
    printf("\n");
}
