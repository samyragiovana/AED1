#ifndef PILHA_H
#define PILHA_H

typedef struct TipoItem{
    int valor;
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoPilha {
    Apontador topo;
    int tamanho;
} TipoPilha;

void fazPilhaVazia(TipoPilha *pilha);

bool verificaPilhaVazia(TipoPilha *pilha);

void empilha(TipoPilha *pilha, TipoItem item);

void desempilha(TipoPilha *pilha, TipoItem *item);

void exibePilha (TipoPilha *pilha);

int getTamanho(TipoPilha *pilha);

#endif