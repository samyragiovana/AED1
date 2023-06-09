#include <iostream>
#include <windows.h>

#define MAXTAM 3
 
using namespace std;

struct ListaVetor {
    int Item[MAXTAM]; // Lista de inteiros com tamanho máximo definido
    int tamanho; // Controla o tamanho atual da lista após criada
};

bool listaCriada = false;

// Funções para Lista com Vetor
void CriaListaVazia(ListaVetor &MinhaLista); // Cria uma lista vazia
int VerificaListaVazia(ListaVetor &MinhaLista); // Retorna TRUE se lista vazia, FALSE caso contrário
int InsereItem(ListaVetor &MinhaLista, int valor); // Insere ITEM (valor) na LISTAVETOR (MinhaLista)
void ImprimeLista(ListaVetor &MinhaLista); // Imprime a lista
int PesquisaItem(ListaVetor &MinhaLista, int valor); // Pesquisa um ITEM (valor) na LISTAVETOR (MinhaLista)
void RetiraItem(ListaVetor &MinhaLista, int valor); // Remove um número do vetor
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    ListaVetor MinhaLista;
    int opcao, ret, num;

    do {
        system("cls");
        cout << "TAD Lista com Vetor \n";
        cout << "1. Criar Lista\n";
        cout << "2. Verifica Lista\n";
        cout << "3. Insere Item\n";
        cout << "4. Imprime Lista\n";
        cout << "5. Pesquisa Item\n";
        cout << "6. Retira Item\n";
        cout << "0. Sair\n\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (!listaCriada) {
                    CriaListaVazia(MinhaLista);
                } else {
                    cout << "Lista já criada.";
                    Sleep(1000);
                }
                break;
            case 2:
                ret = VerificaListaVazia(MinhaLista);
                if (ret == 1) 
                    cout << "Lista vazia!";
                else if (ret == -1)
                    cout << "Crie a lista primeiramente."; 
                else cout << "Lista não vazia.";
                Sleep(1500);
                break;
            case 3:
                if (listaCriada) {
                    cout << "Número: ";
                    cin >> num;
                    ret = InsereItem(MinhaLista, num);
                    if (ret == 1) {
                        cout << "Número inserido com sucesso!";
                        Sleep(500);
                    } else {
                        cerr << "ERRO ao inserir o número. Lista cheia.";
                        Sleep(1000);
                    }
                } else {
                    cout << "Crie a lista primeiramente."; 
                    Sleep(1000);
                }
                break;
            case 4:
                ImprimeLista(MinhaLista);
                break;
            case 5:
                if (listaCriada) {
                    cout << "Número: ";
                    cin >> num;
                    ret = PesquisaItem(MinhaLista, num);
                    if (ret >= 0) {
                        cout << "Número encontrado na posição " << ret;
                        Sleep(1000);
                    } else {
                        cout << "O número não está na lista.";
                        Sleep(1000);
                    }
                } else {
                    cout << "Crie a lista primeiramente."; 
                    Sleep(1000);
                }
                break;
            case 6:
                if (listaCriada) {
                    cout << "Número: ";
                    cin >> num;
                    RetiraItem(MinhaLista, num);
                } else {
                    cout << "Crie a lista primeiramente."; 
                    Sleep(1000);
                }
                break;
            default:
                break;
        }

    } while (opcao != 0);

    return 0;
}

void CriaListaVazia(ListaVetor &MinhaLista) {
    MinhaLista.tamanho = 0;
    listaCriada = true;
    cout << "Lista criada com sucesso!";
    Sleep(1500);
}

int VerificaListaVazia(ListaVetor &MinhaLista) {
    if (MinhaLista.tamanho == 0 && listaCriada) {
        return 1;
    } else if (!listaCriada) {
        return -1;
    } else return 0;
}

int InsereItem(ListaVetor &MinhaLista, int valor) {
    if (MinhaLista.tamanho < MAXTAM) {
        MinhaLista.Item[MinhaLista.tamanho] = valor;
        MinhaLista.tamanho++;
        return 1;
    } else return -1;
}

void ImprimeLista(ListaVetor &MinhaLista) {
    if (listaCriada) {
        for (int i=0; i<MinhaLista.tamanho; i++) {
            cout << MinhaLista.Item[i] << " ";
        }
        cout << endl << endl;
        system("Pause");
    } else {
        cout << "Crie a lista primeiramente.";
        Sleep(1000);
    }
}

int PesquisaItem(ListaVetor &MinhaLista, int valor) {
    for (int i=0; i<MinhaLista.tamanho; i++) {
        if (valor == MinhaLista.Item[i]) {
            return i;
        }
    }
    return -1;
}

void RetiraItem(ListaVetor &MinhaLista, int valor) {
    int indice;
    indice = PesquisaItem(MinhaLista, valor);
    if (indice >= 0) { // encontrou a posição do valor
        for (int i=indice; i<MinhaLista.tamanho-1; i++) {
            MinhaLista.Item[i] = MinhaLista.Item[i+1];
        }
        MinhaLista.tamanho--;
        cout << "Número excluído com sucesso!";
        Sleep(1000);
    } else {
        cout << "O número informado não está na lista";
        Sleep(1000);
    }
}