#include <iostream>
#include <windows.h>
using namespace std;
#define MAXTAM 5

/*2- Escreva uma função que receba como parâmetro duas pilhas e verifique se elas são iguais.
Duas pilhas são iguais se possuem os mesmos elementos, na mesma ordem.*/

typedef struct TipoItem {
    int id1;
    int id2;
} TipoItem;

typedef struct Pilha {
    TipoItem itens[MAXTAM];
    int topo;
} TipoPilha;

void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

    TipoItem item;
    TipoPilha pilha, pilha2;    

    FazPilhaVazia(&pilha);
    FazPilhaVazia(&pilha2);

    cout << "Digite o numero: ";
    cin >> item.id1;
    Empilha(&pilha, item);

    cout << "Digite o numero: ";
    cin >> item.id1;
    Empilha(&pilha, item);
   
    cout << "Digite o numero: ";
    cin >> item.id1;
    Empilha(&pilha, item);

    cout << "Digite o numero: ";
    cin >> item.id1;
    Empilha(&pilha, item);
 
    cout << "Digite o numero: ";
    cin >> item.id1;
    Empilha(&pilha, item);

    cout << endl << endl;

    cout << "Pilha 2: " << endl;

    cout << "Digite o numero: ";
    cin >> item.id2;
    Empilha(&pilha2, item);

    cout << "Digite o numero: ";
    cin >> item.id2;
    Empilha(&pilha2, item);

    cout << "Digite o numero: ";
    cin >> item.id2;
    Empilha(&pilha2, item);

    cout << "Digite o numero: ";
    cin >> item.id2;
    Empilha(&pilha2, item);

    cout << "Digite o numero: ";
    cin >> item.id2;
    Empilha(&pilha2, item);

    cout << endl << endl;

    if(item.id1 == item.id2){
    cout << "Pilhas iguais";
    }else{
    cout << "Pilhas diferentes";
    }

    cout << endl << endl;

    cout << endl << endl;
    system("pause");
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



