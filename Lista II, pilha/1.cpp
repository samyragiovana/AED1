#include <iostream>
#include <windows.h>
using namespace std;

/*1- Implemente uma função que receba como parâmetro uma pilha. A pilha deve estar 
preenchida por números inteiros. A função deve retornar o maior elemento da pilha.*/

#define MAXTAM 5

typedef struct TipoItem {
    int id;
} TipoItem;

typedef struct Pilha {
    TipoItem itens[MAXTAM];
    int topo;
} TipoPilha;

void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);
void Desempilha(TipoPilha *pilha, TipoItem *item);
void ExibePilha(TipoPilha *pilha);
int Tamanho(TipoPilha *pilha);
int maiorElemento(TipoPilha *pilha, TipoItem item);

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    TipoItem item;
    TipoPilha pilha;

    int retorno; 

    FazPilhaVazia(&pilha);

    item.id = 30;
    Empilha(&pilha, item);

    item.id = 80;
    Empilha(&pilha, item);

    item.id = 61;
    Empilha(&pilha, item);

    item.id = 12;
    Empilha(&pilha, item);

    item.id = 10;
    Empilha(&pilha, item);

    ExibePilha(&pilha);
  
    retorno = maiorElemento(&pilha,item);

    cout << "Maior numero da pilha: " << retorno;
  
    return 0;
}

void FazPilhaVazia(TipoPilha *pilha) {
   pilha->topo = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == 0) {
        return true;
    } else return false;
}

void Empilha(TipoPilha *pilha, TipoItem item) {
    if (pilha->topo == MAXTAM) {
        cout << "\nPilha cheia\n";
    } else {
        pilha->itens[pilha->topo] = item;
        pilha->topo++;
    }
}

void ExibePilha(TipoPilha *pilha) { 
    for (int i=pilha->topo-1; i>=0; i--) {
        cout << pilha->itens[i].id << "\n";
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item) {
    if (VerificaPilhaVazia(pilha)) {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(TipoPilha *pilha) {
    return pilha->topo;
}

int maiorElemento(TipoPilha *pilha, TipoItem item){
   int maior,aux;
   maior = item.id;

  while(!VerificaPilhaVazia(pilha)){
    aux = item.id;
    Desempilha(pilha,&item);
    if(aux >= maior){
      maior = aux;
    }
  }
  return maior;
}