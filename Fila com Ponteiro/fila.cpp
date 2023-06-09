#include<iostream>
#include "fila.hpp"

using namespace std;

void InicializaFila(TipoFila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila) {
    if (fila->inicio == NULL) { // Ninguém na fila
        return true;        
    } else {
        return false;
    }
}

void Enfileira(TipoFila *fila, TipoItem i) {
    Apontador novo;
    novo = new TipoElemento;
    novo->item = i;
    novo->prox = NULL;
    
    /* Caso a fila esteja vazia, o elemento inserido será o primeiro e último */
    if (VerificaFilaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    
    /* Caso a fila já possua algum elemento, o novo elemento será inserido no fim */
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    cout << novo->item.valor << " inserido na fila.\n";
    fila->tamanho++;
}

void Desenfileira(TipoFila *fila) {
    Apontador aux; // Elemento a ser removido
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    }
    
    aux = fila->inicio;
    cout << endl << fila->inicio->item.valor << " removido da fila.\n";
    fila->inicio = fila->inicio->prox;
    free(aux);
    fila->tamanho--;
}

void EsvaziaFila(TipoFila *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    }
    
    aux = fila->inicio;
    do {
        fila->inicio = fila->inicio->prox;
        free(aux);
        aux = fila->inicio;
    } while (aux != NULL);
    cout << "\nFila esvaziada.\n";
    fila->tamanho = 0;
    fila->inicio = NULL;
    fila->fim = NULL;
}

void ImprimeFila(TipoFila *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.\n\n";
    } else {
        aux = fila->inicio;
        cout << "\nFila: ";
        do {
            cout << aux->item.valor << " ";
            aux = aux->prox;
        } while (aux != NULL);
    }
}

