#include <iostream>
#include "Pilha.hpp"

using namespace std;

void fazPilhaVazia(TipoPilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

bool verificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == NULL) {
        return true;
    } else return false;
}

void empilha(TipoPilha *pilha, TipoItem item) {
    Apontador novo;
    novo = new TipoElemento;
    novo->item = item;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

void desempilha(TipoPilha *pilha, TipoItem *item) {
    Apontador aux; /* celula a ser removida */
    
    if (verificaPilhaVazia(pilha)) {
        return ;
    }
 
    if (pilha->tamanho == 1) {
        aux = pilha->topo;
        *item = aux->item;
        pilha->topo = NULL;
        free(aux);
        pilha->tamanho--;
    } else {
        aux = pilha->topo;
        pilha->topo = aux->prox; //pilha->topo->prox
        *item = aux->item;
        free(aux);
        pilha->tamanho--;
    }
}

void exibePilha (TipoPilha *pilha) {
    Apontador x;
    x = pilha->topo;
    int cont = pilha->tamanho;
    while (cont > 0) {
        cout << x->item.valor;
        cont--;
        x = x->prox;
    }
}

int getTamanho(TipoPilha *pilha) {
    return pilha->tamanho;
}