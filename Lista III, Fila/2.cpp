#include <iostream>
#include <windows.h>
using namespace std;

/*2- Utilizando as TADs implementadas para Filas, acrescidas das funções que julgar pertinente, elabore um programa
que divida uma determinada Fila de n Clientes (n ≤ MAXTAM) em duas filas.
Considerando a estrutura da fila inicial e os dados atribuídos (manualmente ou por sorteio), mova
os(as) clientes gestantes ou maiores de 60 anos para a nova fila chamada Fila Prioritaria. Mostre as duas filas. */

#define MAXTAM 20

typedef struct
{
  int idade;
  bool gestante;
} Cliente;

typedef struct
{
  int inicio, fim;
  Cliente Fila[MAXTAM];
  int tamanho;
} TFila;

void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);
void TFila_Enfileira(TFila *f, Cliente x);
Cliente TFila_Desenfileira(TFila *f);
void TFila_Imprime(TFila *f);

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  TFila Fila1, FilaPrioritaria, FilaNaoPrioritaria;
  TFila_Inicializa(&Fila1);
  TFila_Inicializa(&FilaPrioritaria);
  TFila_Inicializa(&FilaNaoPrioritaria);

  Cliente c;
  c.idade = 50;
  c.gestante = false;

  TFila_Enfileira(&Fila1, c);

  c.idade = 78;
  c.gestante = false;

  TFila_Enfileira(&Fila1, c);

  c.idade = 22;
  c.gestante = false;

  TFila_Enfileira(&Fila1, c);

  c.idade = 36;
  c.gestante = true;

  TFila_Enfileira(&Fila1, c);

  Cliente aux;

  int tamanhoInicial = Fila1.tamanho;

  for (int i = 0; i < tamanhoInicial; i++)
  {
    if (Fila1.Fila[i].gestante == true || Fila1.Fila[i].idade >= 60)
    {
      aux = TFila_Desenfileira(&Fila1);
      TFila_Enfileira(&FilaPrioritaria, aux);
    }
    else
    {
      aux = TFila_Desenfileira(&Fila1);
      TFila_Enfileira(&FilaNaoPrioritaria, aux);
    }
  }

  cout << "Fila Prioritária: \n";
  TFila_Imprime(&FilaPrioritaria);
  cout << "Fila não Prioritária: \n";
  TFila_Imprime(&FilaNaoPrioritaria);

  return 0;
}

void TFila_Inicializa(TFila *f)
{
  f->inicio = 0;
  f->fim = -1;
  f->tamanho = 0;
}

bool TFila_Vazia(TFila *f)
{
  if (f->inicio > f->fim)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool TFila_Cheia(TFila *f)
{
  if (f->fim == MAXTAM - 1)
  {
    return true; // fila cheia
  }
  else
  {
    return false; // 0 fila não cheia
  }
}

void TFila_Enfileira(TFila *f, Cliente x)
{
  if (TFila_Cheia(f))
  {
    cout << "\nFila Cheia.\n";
  }
  else
  {
    f->fim++;
    f->Fila[f->fim] = x;
    f->tamanho++;
    // cout << "Valor enfileirado: " << x << endl;
  }
}

Cliente TFila_Desenfileira(TFila *f)
{
  Cliente aux;
  if (TFila_Vazia(f))
  {
    cout << "Fila vazia.\n";
  }
  else
  {
    aux = f->Fila[f->inicio];
    f->inicio++;
    f->tamanho--;
    return aux;
  }
  Cliente c;
  return c;
}

void TFila_Imprime(TFila *f)
{
  if (TFila_Vazia(f))
  {
    cout << "Fila vazia.\n";
  }
  else
  {
    cout << "Fila: ";
    for (int i = f->inicio; i <= f->fim; i++)
    {
      cout << "\nGESTANTE? " << (f->Fila[i].gestante ? "SIM" : "NAO") << "\n";
      cout << "IDADE: " << f->Fila[i].idade << endl;
    }
    cout << endl;
  }
}
