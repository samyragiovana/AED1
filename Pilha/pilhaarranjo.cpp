#include <iostream>
#include <windows.h>
 
using namespace std;

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

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");    

    TipoItem item;
    TipoPilha pilha, pilha2;    

    FazPilhaVazia(&pilha);
    FazPilhaVazia(&pilha2);

    item.id = 3;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 5;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 6;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 1;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    item.id = 2;
    Empilha(&pilha, item);
    Empilha(&pilha2, item);

    // VerificaPilhaVazia(&pilha);
    
    ExibePilha(&pilha);
    //cout << "Tamanho: " << Tamanho(&pilha);

    Desempilha(&pilha, &item);

    cout << endl << endl;

    ExibePilha(&pilha);
    cout << endl << endl;

    ExibePilha(&pilha);
   
   cout << endl << endl;

    ExibePilha(&pilha2);
   
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
        //cout << "\nItem empilhado com sucesso!\n";
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