#include <iostream>

using namespace std;

typedef struct TipoItem{
    int id;
    string nome;
} TipoItem;

typedef struct TipoElemento* Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
} TipoLista;

//=======================Utilizando Celula Principal============================
void CriaListaVazia(TipoLista *lista){
    lista->primeiro = new TipoElemento;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
}

bool VerificaListaVazia(TipoLista * lista){
    if (lista->primeiro == lista->ultimo) {
        return true;
    } else {
        return false;
 }
 //return (lista->primeiro == lista->ultimo);
}
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new TipoElemento;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int idEleX){
    Apontador aux, pAux, ele_x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL) {
        if (pAux->item.id == idEleX) {
            find = true;
            ele_x = pAux;
            aux = ele_x->prox;
            ele_x->prox = new TipoElemento;
            ele_x->prox->prox = aux;
            ele_x->prox->item = *item;
            break;
        }
    pAux = pAux->prox; /* próxima célula */
    }
    if (find) {
        cout << "Item inserido com sucesso!";
    } else {
        cout << "Elemento anterior não encontrado na lista.";
    }
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item) {
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
}

void RemoveListaPrimeiro(TipoLista *lista, TipoItem *item){
    Apontador aux;
    
    if (VerificaListaVazia(lista)){
        return ;
    }
    *item = lista->primeiro->prox->item;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
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

void ImprimeLista(TipoLista *lista){
    Apontador x;
    
    x = lista->primeiro->prox;
    
    while (x != NULL){
        cout << x->item.id << " ";
        cout << x->item.nome << " ";
        x = x->prox; /* próxima célula */
    }
}

int main (){
    TipoLista lista;
    Apontador x;
    TipoItem item;
    
    item.id = 1;
    item.nome = "Xulambs";
    
    CriaListaVazia(&lista);
    InsereListaPrimeiro(&lista, &item);
    ImprimeLista(&lista);

    return 0;
}