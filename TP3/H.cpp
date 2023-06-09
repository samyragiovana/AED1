#include <iostream>
#include <windows.h>
#include <ctime>
 
using namespace std;

typedef struct TipoItem{
  char nome [15];
  int Cod;
};

typedef struct TipoElemento* Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoFila{
    Apontador front, back;
    Apontador size;
} TipoFila;


//TADs

void CriaFilaVazia(TipoFila *Fila);
bool VerificaFilaVazia(TipoFila *Fila);
void Enfileira(TipoFila *Fila, TipoItem *item);
void Desinfileira(TipoFila *Fila);
void ImprimeFila(TipoFila *Fila);
void EsvaziaFila(TipoFila *Fila);

 
char Matriz [5][15] = {{'H','e','l','i','o',' ','J','r',NULL,NULL,NULL,NULL,NULL,NULL,NULL},
                      {'G','a','b','r','i','e','l',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL},
                      {'J','o','a','o',' ','P','e','d','r','o',NULL,NULL,NULL,NULL,NULL},
                      {'P','o','z','e',' ','d','o',' ','R','o','d','o',NULL,NULL,NULL},
                      {'M','a','t','u','e',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}};

int Vetor [5] = {11777,21533,31215,45465,57865};


void Menu();
void sorteio(TipoFila *Fila);
void atende(TipoFila *Fila);

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  
  TipoFila Fila;
  TipoItem item;
  int op;

  CriaFilaVazia(&Fila);


  do{
    Menu();
    cout << "  opção: ";
    cin >> op;
    system("cls");

    switch (op){

    case 1:
      sorteio(&Fila);
      break;
    case 2:
      if (VerificaFilaVazia(&Fila))
      {
        cout << "\nFila vazia !!";
        Sleep(1000);
        system("cls");
      }else{
        atende(&Fila);
      }
      break;
    case 3:
      ImprimeFila(&Fila);
      break;
      
    default:
      break;
    }
  } while (op != 4);
 
 
  cout << endl << endl;
  system("pause");
  return 0;
}

void CriaFilaVazia(TipoFila *Fila){
    Fila->front = NULL;
    Fila->back = Fila->front;
    Fila->size = 0;
}

bool VerificaFilaVazia(TipoFila *Fila){
    if (Fila->front == NULL ) {
        return  true ;
    } else  return  false ;
}

void Enfileira(TipoFila *Fila, TipoItem *item) { 
    Apontador aux;
    aux = new TipoElemento;
    aux->item = *item;
    aux->prox = NULL;
    if (VerificaFilaVazia(Fila))
    {
        Fila->front = aux;
        Fila->back = aux;
    }else{
        Fila->back->prox = aux;
        Fila->back = Fila->back->prox;
    }
    Fila->size++;
    
}

void Desinfileira(TipoFila *Fila){
    Apontador aux;
    
    if (VerificaFilaVazia(Fila)){
        return ;
    }

    aux = Fila->front;
    Fila->front = Fila->front->prox;
    free(aux);
    Fila->size--;
    
}


void ImprimeFila(TipoFila *Fila){
    Apontador x;
    if (VerificaFilaVazia(Fila))
    {
        cout << "\nFila vazia !!";
    }

    x = Fila->front;
    
    system("cls");

    do{
        cout << "RA: " <<  x->item.Cod << endl;
        cout << "Nome: " << x->item.nome << endl << endl;
             
        x = x->prox;
    } while(x != NULL);

    system("pause");
    system("cls");
}

void EsvaziaFila(TipoFila *Fila){
    Apontador x;
    if (VerificaFilaVazia(Fila))
    {
        cout << "\nFila vazia !!";
    }

    x = Fila->front;
    
    system("cls");

    do{
        Fila->front = Fila->front->prox;
        free(x); 
        x = Fila->front;
    } while(x != NULL);
    cout << "Fila esvaziada\n";
    Fila->size = 0;
}


void Menu() {    
     cout<<"  \n  ����������������������������������������������������������������";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  �                           MENU                               �";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  ����������������������������������������������������������������";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  � 1 - NOVO ALUNO NA FILA                                       �";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  � 2 - ATENDE UM ALUNO                                          �";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  � 3 - EXIBE FILA                                               �";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  � 4 - SAIR                                                     �";
     cout<<"  \n  �                                                              �";
     cout<<"  \n  ����������������������������������������������������������������\n\n";
}

void sorteio(TipoFila *Fila){
  char nom[15];
  int n;
  TipoItem item;

  unsigned seed = time(0);
  srand(seed);
  n = rand()%5;

  for (int i = 0; i < 15; i++)
    {
        item.nome[i] =  Matriz[n][i]; 
    }
  item.Cod = Vetor[n];
  Enfileira(Fila, &item);
  cout << item.nome << " entrou na fila.";
  Sleep(1000);
  system("cls");
}

void atende(TipoFila *Fila){
  TipoItem item;
  Apontador aux;

  aux = Fila->front;

  cout << aux->item.nome << " foi atendido" ;
  Desinfileira(Fila);

  Sleep(1000);
  system("cls");
}