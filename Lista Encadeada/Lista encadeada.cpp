#include <iostream>
#include <windows.h>
#include <conio.h>

#define MAXTAM 3

typedef int TChave;

typedef struct TCelula_str *TApontador;

typedef struct {
    TChave codFuncionario;
    char nomeFuncionario[40];
    char cpf[15];
    char endereco[40];
    char telefone[15];
} TFuncionario;

typedef struct TCelula_str {
    TFuncionario Item;
    TApontador prox;
} TCelula;

typedef struct {
    TApontador Primeiro;
    TApontador Ultimo;
} TListaEncadeada;
 
using namespace std;

void menu();
void CriaListaVazia(TListaEncadeada *lista);
void Insere(TFuncionario f, TListaEncadeada *lista);
int Pesquisa(TChave cod, TListaEncadeada lista, TApontador *p);
void CadastraFuncionario(TListaEncadeada *lista);
void ConsultaFuncionario(TListaEncadeada *lista);
void ExcluiFuncionario(TListaEncadeada *lista);
void ListaFuncionario(TListaEncadeada *lista);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    TListaEncadeada lista;
    CriaListaVazia(&lista);
    int opcao;
    
    system("cls");

    do {
        menu();
        cout << "Escolha a opção: ";
        cin >> opcao;
        system("cls");
        switch(opcao) {
            case 1:
                CadastraFuncionario(&lista);
                break;
            case 2:
                ConsultaFuncionario(&lista);
                break;
            case 3: 
                ExcluiFuncionario(&lista);
                break;
            case 4:
                ListaFuncionario(&lista);
                break;
        }
    } while(opcao != 7);
    
    return 0;
}

void menu( ) {    
     system("color 0B");
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     DEPARTAMENTO PESSOAL                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INCLUIR NOVO FUNCIONÁRIO                                 �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - CONSULTAR FUNCIONÁRIO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - EXCLUIR FUNCIONÁRIOS                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - LISTAGEM DE FUNCIONÁRIOS                                 �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 7 - SAIR                                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CriaListaVazia(TListaEncadeada *lista) {
    lista->Primeiro = new TCelula;
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

int VerificaListaVazia(TListaEncadeada lista) {
    return (lista.Primeiro == lista.Ultimo);
}

void Insere(TFuncionario f, TListaEncadeada *lista) {
    lista->Ultimo->prox = new TCelula;
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->Item = f;
    lista->Ultimo->prox = NULL;
}

void CadastraFuncionario(TListaEncadeada *lista) {
    TFuncionario f;
    cout << "*******************************************\n";
    cout << "*        CADASTRO DE FUNCIONÁRIO          *\n";
    cout << "*******************************************\n\n";
    cout << "Código: ";
    cin >> f.codFuncionario;
    cin.ignore();
    cout << "Nome: ";
    gets(f.nomeFuncionario);
    cout << "CPF: ";
    gets(f.cpf);
    cout << "Endereço: ";
    gets(f.endereco);
    cout << "Telefone: ";
    gets(f.telefone);
    
    Insere(f, lista);

    cout << "\nFuncionário cadastrado com sucesso!\n\n";
    Sleep(1000);
    system("cls");
}

int Pesquisa(TChave cod, TListaEncadeada lista, TApontador *p) {
    TApontador aux = lista.Primeiro;
    while (aux->prox != NULL) {
        if (aux->prox->Item.codFuncionario == cod) {
            *p = aux;
            return 1;
        } else {
            aux = aux->prox;
            *p = aux;
        }
    }
    return 0;
}

void ListaFuncionario(TListaEncadeada *lista) {
    TApontador aux = lista->Primeiro->prox;

    system("cls");
    cout << "*******************************************\n";
    cout << "*        LISTAGEM DE FUNCIONÁRIOS         *\n";
    cout << "*******************************************\n\n";

    while (aux) {  
        cout << "\nCódigo: " << aux->Item.codFuncionario;
        cout << "\nNome: " << aux->Item.nomeFuncionario;
        cout << "\nCPF: " << aux->Item.cpf;
        cout << "\nEndereço: " << aux->Item.endereco;
        cout << "\nTelefone: " << aux->Item.telefone << endl << endl;
        aux = aux->prox;
    }

    system("pause");
    system("cls");
}

void ConsultaFuncionario(TListaEncadeada *lista) {
    TChave cod;
    TApontador p;
    int ret;
    cout << "*******************************************\n";
    cout << "*        CONSULTA DE FUNCIONÁRIO          *\n";
    cout << "*******************************************\n\n";
    cout << "Informe o código do funcionário: ";
    cin >> cod;

    ret = Pesquisa(cod, *lista, &p);

    if (ret == 1) {
        cout << "\nCódigo: " << p->prox->Item.codFuncionario;
        cout << "\nNome: " << p->prox->Item.nomeFuncionario;
        cout << "\nCPF: " << p->prox->Item.cpf;
        cout << "\nEndereço: " << p->prox->Item.endereco;
        cout << "\nTelefone: " << p->prox->Item.telefone << endl << endl;
    } else {
        cout << "\nFuncionário não encontrado.\n";
    }

    system("pause");
    system("cls");
}

void ApagaFuncionario(TApontador x, TListaEncadeada *lista, TFuncionario *f) {
    TApontador q;

    if ((VerificaListaVazia(*lista)) || (x == NULL) || (x->prox == NULL)) {
        cout << "Erro. Lista vazia";
    } else {
        q = x->prox;
        *f = q->Item;
        x->prox = q->prox;
        if (x->prox == NULL) {
            lista->Ultimo = x;
        }
        delete q;
    }
}

void ExcluiFuncionario(TListaEncadeada *lista) {
    TFuncionario f;
    TApontador x = lista->Primeiro;
    int cont=0;

    while (x->prox != NULL) {
        // if ( Trabalho: Verificar se funcionário não possui projetos) 
        ApagaFuncionario(x, lista, &f);
        cont ++;
    }
    system("cls");
    cout << "*******************************************\n";
    cout << "*        EXCLUSÃO DE FUNCIONÁRIOS         *\n";
    cout << "*******************************************\n\n";
    cout << "\n" << cont << " funcionário(s) excluído(s) com sucesso!\n\n";
    system("pause");
    system("cls");
}