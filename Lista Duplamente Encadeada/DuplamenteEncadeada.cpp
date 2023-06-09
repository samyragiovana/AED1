#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

typedef struct TipoItem{
    int id;
    char titulo[20];
    char descricao[300];
    char dataEntrega[10];
} TipoItem;

typedef struct TipoElemento* Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
    struct TipoElemento *ant;
} TipoElemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
} TipoLista;

void Menu();
void MenuRemocao();
void MenuPesquisa();
void CabecalhoCadastro();
void CabecalhoRemocaoPorCodigo();
void CabecalhoPesquisaPorCodigo();
void CabecalhoPesquisaPorTitulo();
void CabecalhoListagemCompleta(); 

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item);
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int idEleX);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void RemoveListaPrimeiro(TipoLista *lista, TipoItem *item);
void RemoveListaUltimo(TipoLista *lista, TipoItem *item);
void RemoveElementoXbyId(TipoLista *lista, TipoItem *item, int idEle);
bool PesquisaElementoXbyId(TipoLista *lista, TipoItem *item, int idEle);
bool PesquisaElementoXbyTitulo(TipoLista *lista, TipoItem *item, char titulo[]);
void ImprimeLista(TipoLista *lista);

int CadastraTrabalho(TipoLista *lista);
int RemoveTrabalho(TipoLista *lista);
void RemovePorCodigo(TipoLista *lista);
void PesquisaTrabalho(TipoLista *lista);
void PesquisaPorCodigo(TipoLista *lista);
void PesquisaPorTitulo(TipoLista *lista);  
void ListaTrabalhos(TipoLista *lista);
void ImprimePrimeiroTrabalho(TipoLista *lista);
void ImprimeProximoTrabalho(TipoLista *lista, TipoElemento *ptr);
void ImprimeTrabalhoAnterior(TipoLista *lista, TipoElemento *ptr);
void ListaTodosTrabalhos(TipoLista *lista);

 
int main() {
    // Double-Threaded List
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
 
    TipoLista lista;
   
    CriaListaVazia(&lista);
    
    int opcao_menu;
    do {
        Menu();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu)) {
            cout << "  \n        Digite um valor válido."; 
            cin.clear(); 
            cin.ignore();
            Sleep(1000);
            system ("cls");
            Menu();
        }
        system ("cls");
        switch (opcao_menu) {
              case 1: CadastraTrabalho(&lista); break;   
              case 2: RemoveTrabalho(&lista); break; 
              case 3: ListaTrabalhos(&lista); break;
              case 4: PesquisaTrabalho(&lista); break;
              case 5: ListaTodosTrabalhos(&lista); break;
              case 6: cout << "Aguardamos você em breve novamente\n\n"; break;
         }
    } while (opcao_menu!=6); 

    return 0;
}


void Menu() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     TRABALHOS ACADÊMICOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INCLUIR NOVO TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - REMOVER UM TRABALHO                                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - NAVEGAR PELOS TRABALHOS                                  �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - PESQUISAR UM TRABALHO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 5 - LISTAR TODOS OS TRABALHOS                                �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 6 - SAIR                                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void MenuRemocao() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                       EXCLUIR TRABALHO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - PRIMEIRO DA LISTA                                        �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - ÚLTIMO DA LISTA                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - POR CÓDIGO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - VOLTAR                                                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void MenuPesquisa() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                      PESQUISAR TRABALHO                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - POR CÓDIGO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - POR TÍTULO                                               �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - VOLTAR                                                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoCadastro() {    
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     CADASTRO DE TRABALHO                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoListagemCompleta() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    TRABALHOS CADASTRADOS                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CabecalhoRemocaoPorCodigo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    EXCLUSÃO DE TRABALHO                      �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoPesquisaPorCodigo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    PESQUISA POR CÓDIGO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}

void CabecalhoPesquisaPorTitulo() {
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                    PESQUISA POR TÍTULO                       �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
}


void CriaListaVazia(TipoLista *lista){
    lista->primeiro = new TipoElemento;
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
}

bool VerificaListaVazia(TipoLista * lista){
    return (lista->primeiro == lista->ultimo);
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new TipoElemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    aux->ant = lista->primeiro->prox;
    lista->primeiro->prox->ant = lista->primeiro;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int idEleX) {
    Apontador aux, x, itemAnterior;
    x = lista->primeiro; // Célula cabeça

    while(x->prox != NULL) { 
        if (x->prox->item.id == idEleX) { 
            itemAnterior = x->prox; 
            break;
        }
        x = x->prox;
    }

    aux = itemAnterior->prox; 
    itemAnterior->prox = new TipoElemento; 
    itemAnterior->prox->item = *item; 
    itemAnterior->prox->prox = aux; 
    aux->ant = itemAnterior->prox; 
    aux->ant->ant = itemAnterior;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item) { 
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->ultimo->ant = aux;
}

void RemoveListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    
    if (VerificaListaVazia(lista)){
        return ;
    }
    *item = lista->primeiro->prox->item;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    lista->primeiro->prox->ant = lista->primeiro;
    free(aux);
}

void RemoveListaUltimo(TipoLista *lista, TipoItem *item){
    Apontador aux, anterior, x;
    
    if (VerificaListaVazia(lista)) {
        return ;
    }
 
    x = lista->primeiro;
    while(x != NULL){
        if (x->prox == lista->ultimo){
            anterior = x;
        break;
        }
        x = x->prox;
    }
 
    aux = lista->ultimo;
    lista->ultimo = anterior;
    *item = aux->item;
    lista->ultimo->prox = NULL;
    free(aux);
}

void RemoveElementoXbyId(TipoLista *lista, TipoItem *item, int idEle){
    Apontador aux, anterior, x;
    
    if (VerificaListaVazia(lista)){
        return;
    }
    
    x = lista->primeiro;
    
    while (x != NULL){
        if (x->prox->item.id == idEle){
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    *item = aux->item;
    free(aux);
}

bool PesquisaElementoXbyId(TipoLista *lista, TipoItem *item, int idEle) {
    Apontador x;
    
    if (VerificaListaVazia(lista)){
        return false;
    }
    
    x = lista->primeiro;
    
    while (x != NULL) {
        if (x->prox->item.id == idEle){
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

bool PesquisaElementoXbyTitulo(TipoLista *lista, TipoItem *item, char titulo[]) {
    Apontador x;
    
    if (VerificaListaVazia(lista)){
        return false;
    }
    
    x = lista->primeiro;
    
    while (x != NULL) {
        if (strcmpi(x->prox->item.titulo, titulo) == 0){
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

void ImprimeLista(TipoLista *lista){
    Apontador x;
    
    x = lista->primeiro->prox;
    
    while (x != NULL){
        cout << "Código: " << x->item.id << endl;
        cout << "Título: " << x->item.titulo << endl;
        cout << "Descrição: " << x->item.descricao << endl;
        cout << "Data de Entrega: " << x->item.dataEntrega << endl << endl;
        x = x->prox;
    }
}


int CadastraTrabalho(TipoLista *lista) {
    system("cls");
    CabecalhoCadastro();

    TipoItem item;

    while((cout << "\n\n1. Código: ") && !(cin >> item.id)) {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();

    cout << "2. Título: ";
    gets(item.titulo);
    cout << "3. Descrição: ";
    gets(item.descricao);
    cout << "4. Data de Entrega: ";
    gets(item.dataEntrega);

    InsereListaUltimo(lista, &item);

    cout << "\nTrabalho cadastrado com sucesso!\n\n";
    system("pause");
    system("cls");
}

int RemoveTrabalho(TipoLista *lista) {
    system("cls");
    
    TipoItem item;

    int opcao_menu;
    do {
        MenuRemocao();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu)) {
            cout << "  \n        Digite um valor válido."; 
            cin.clear(); 
            cin.ignore();
            Sleep(1000);
            system ("cls");
            MenuRemocao();
        }
        system ("cls");
        switch (opcao_menu) {
              case 1: RemoveListaPrimeiro(lista, &item); 
                      MenuRemocao();
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break;   
              case 2: RemoveListaUltimo(lista, &item); 
                      MenuRemocao();
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break; 
              case 3: RemovePorCodigo(lista);
                      cout << "\n\nTrabalho removido com sucesso!\n\n";
                      system("pause");
                      system("cls");
                      break;
              case 4: system("cls"); break;
              default: RemoveTrabalho(lista);
         }
    } while (opcao_menu>4 && opcao_menu<1); 
}

void RemovePorCodigo(TipoLista *lista) {
    TipoItem item;
    int cod;
    CabecalhoRemocaoPorCodigo();
    while((cout << "  \n        Informe o código do trabalho a ser removido: ") && !(cin >> cod)) {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    RemoveElementoXbyId(lista, &item, cod);
}

void PesquisaTrabalho(TipoLista *lista) {
    system("cls");

    int opcao_menu;
    do {
        MenuPesquisa();
        while ((cout << "  \n        Escolha uma opção: ") && !(cin >> opcao_menu)) {
            cout << "  \n        Digite um valor válido."; 
            cin.clear(); 
            cin.ignore();
            Sleep(1000);
            system ("cls");
            MenuPesquisa();
        }
        system ("cls");
        switch (opcao_menu) {
              case 1: PesquisaPorCodigo(lista); 
                      system("pause");
                      system("cls");
                      break;   
              case 2: PesquisaPorTitulo(lista);
                      system("pause");
                      system("cls");
                      break; 
              case 3: system("cls");
                      break;
              default: PesquisaTrabalho(lista);
         }
    } while (opcao_menu>3 && opcao_menu<1);
}

void PesquisaPorCodigo(TipoLista *lista) {
    TipoItem item;
    int cod;
    CabecalhoPesquisaPorCodigo();
    while((cout << "  \n\n        Informe o código do trabalho a ser pesquisado: ") && !(cin >> cod)) {
        cout << "Digite um valor numérico.\n";
        cin.clear();
        cin.ignore();
    }
    if (PesquisaElementoXbyId(lista, &item, cod)) {
        cout << endl << endl << "Código: " << item.id << endl;
        cout << "Título: " << item.titulo << endl;
        cout << "Descrição: " << item.descricao << endl;
        cout << "Data de Entrega: " << item.dataEntrega << endl << endl;
    } else {
        cout << "\n\nCódigo não encontrado.\n\n";
    }
}

void PesquisaPorTitulo(TipoLista *lista) {
    TipoItem item;
    char titulo[20];
    CabecalhoPesquisaPorTitulo();
    cin.ignore();
    cout << "  \n\n        Informe o título do trabalho a ser pesquisado: ";
    gets(titulo);
    
    if (PesquisaElementoXbyTitulo(lista, &item, titulo)) {
        cout << endl << endl << "Código: " << item.id << endl;
        cout << "Título: " << item.titulo << endl;
        cout << "Descrição: " << item.descricao << endl;
        cout << "Data de Entrega: " << item.dataEntrega << endl << endl;
    } else {
        cout << "\n\nTítulo não encontrado.\n\n";
    }
}

void ListaTrabalhos(TipoLista *lista) {
    system("cls");
    char nav;
    CabecalhoListagemCompleta();

    if (VerificaListaVazia(lista)) {
        cout << "Nenhum trabalho cadastrado.\n\n";
        system("pause");
        system("cls");
        return;
    }
   
    ImprimePrimeiroTrabalho(lista);
    while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav)) {
        cout << "Digite um valor válido.\n"; 
        cin.clear(); 
        cin.ignore();
    }

    if (nav == 'p') {
        Apontador p = lista->primeiro->prox->prox;
        ImprimeProximoTrabalho(lista, p);
    } else if (nav == 'a') {
        Apontador p = lista->primeiro;
        ImprimeTrabalhoAnterior(lista, p);
    }
    else {
        system("cls");
        return;
    }
}

void ImprimePrimeiroTrabalho(TipoLista *lista) {
    Apontador x;
    
    x = lista->primeiro->prox;
    
    cout << "Código: " << x->item.id << endl;
    cout << "Título: " << x->item.titulo << endl;
    cout << "Descrição: " << x->item.descricao << endl;
    cout << "Data de Entrega: " << x->item.dataEntrega << endl << endl;
}

void ImprimeProximoTrabalho(TipoLista *lista, TipoElemento *ptr) {
    Apontador p;
    char nav;
    
    for (p=ptr; p!=NULL; p=p->prox) {
        system("cls");
        CabecalhoListagemCompleta();
        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.titulo << endl;
        cout << "Descrição: " << p->item.descricao << endl;
        cout << "Data de Entrega: " << p->item.dataEntrega << endl << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav)) {
            cout << "Digite um valor válido.\n"; 
            cin.clear(); 
            cin.ignore();
        }
        if (nav == 'p') {
            continue;
        } else if (nav == 'a') {
            ImprimeTrabalhoAnterior(lista, p->ant);
        } else { 
            system("cls");
            return;
        }
    }
    
    if (p == NULL) {
        cout << "\nNão há mais trabalhos cadastrados.\n\n";
        system("pause");
        system("cls");
        return;
    }
}

void ImprimeTrabalhoAnterior(TipoLista *lista, TipoElemento *ptr) {
    Apontador p;
    char nav;

    if (ptr == lista->primeiro) {
        cout << "\nNão há trabalhos cadastrados anteriores a este.\n\n";
        system("pause");
        system("cls");
        return;
    }
    
    for (p=ptr; p!=NULL; p=p->ant) {
        system("cls");
        CabecalhoListagemCompleta();
        cout << endl << endl;
        cout << "Código: " << p->item.id << endl;
        cout << "Título: " << p->item.titulo << endl;
        cout << "Descrição: " << p->item.descricao << endl;
        cout << "Data de Entrega: " << p->item.dataEntrega << endl << endl;
        while ((cout << "(a) anterior || (p) próximo || (c) cancelar: ") && !(cin >> nav)) {
            cout << "Digite um valor válido.\n"; 
            cin.clear(); 
            cin.ignore();
        }
        if (nav == 'a') {
            if (p == lista->primeiro->prox) {
                return;
            } else {
                continue;
            }
        } else if (nav == 'p') {
            ImprimeProximoTrabalho(lista, p->prox);
        }
        else {
            system("cls");
            return;
        }
    }
}

void ListaTodosTrabalhos(TipoLista *lista) {
    system("cls");
    CabecalhoListagemCompleta();

    if (VerificaListaVazia(lista)) {
        cout << "Nenhum trabalho cadastrado.\n\n";
        system("pause");
        system("cls");
        return;
    }

    ImprimeLista(lista);
    
    cout << endl << endl;
    system("pause");
    system("cls");
}