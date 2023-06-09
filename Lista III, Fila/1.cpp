#include <iostream>
#include <windows.h>
#include <stack>
#include <queue>
using namespace std;
#define MAXTAM 5

/*1- Dado uma pilha P vazia e uma fila F não vazia, utilizando apenas os testes de fila e pilha vazias,
as operações Enfileira, Desenfileira, Empilha, Desempilha, e uma variável auxiliar, escreva uma
função que inverta a ordem dos elementos da fila.*/

void exibirFilaNormal(queue<int> fila);
void exibirPilhaInvertida(stack<int> pilha);

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  queue<int> fila;
  int numero = 0;

  cout << "Insira 5 numeros na pilha: " << endl;

  for (int i = 0; i <= MAXTAM; i++)
  {
    cin >> numero;
    fila.push(numero);
  }

  system("cls");

  exibirFilaNormal(fila);

  cout << endl
       << endl;
  system("pause");
  return 0;
}

void exibirFilaNormal(queue<int> fila)
{
  stack<int> pilha;
  cout << "Fila Normal:" << endl;
  while (fila.size())
  {
    cout << fila.front() << " ";
    pilha.push(fila.front());
    fila.pop();
  }
  exibirPilhaInvertida(pilha);
}

void exibirPilhaInvertida(stack<int> pilha)
{
  cout << "\nFila Invertida: " << endl;
  while (pilha.size())
  {
    cout << pilha.top() << " ";
    pilha.pop();
  }
}
