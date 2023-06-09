#include <iostream>
#include <windows.h>
/*Faça um programa que leia três valores inteiros e chame uma
função que receba estes 3 valores de entrada e retorne eles
ordenados, ou seja, o menor valor na primeira variável, o
segundo menor valor na variável do meio, e o maior valor na
ultima variável. Utilize ponteiros para a função.*/
using namespace std;

void ORDENA(int *, int *, int *);

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  system("cls");

  int A, B, C;
  int *P, *Q, *R;

  cout << "A: ";
  cin >> A;
  P = &A;

  cout << "B: ";
  cin >> B;
  Q = &B;

  cout << "C: ";
  cin >> C;
  R = &C;

  system("cls");

  ORDENA(P, Q, R);

  cout << endl
       << endl;
  system("pause");
  return 0;
}

void ORDENA(int *P, int *Q, int *R)
{
  int AUXILIAR;
  if (*P > *Q)
  {                // 4 > 2
    AUXILIAR = *P; // AUXILIAR = 4
    *P = *Q;       // *P = 2
    *Q = AUXILIAR; // *Q = 4
  }
  if (*Q > *R)
  {
    AUXILIAR = *Q; // AUXILIAR = 4
    *Q = *R;       // *Q = 3
    *R = AUXILIAR; // *R = 4
  }
  if (*P > *R)
  {
    AUXILIAR = *P;
    *P = *R;
    *R = AUXILIAR;
  }

  cout << *P << " " << *Q << " " << *R;
}