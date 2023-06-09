#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls");

  ifstream leitor;

  char v[1000];

  leitor.open("ListaAleatoria-1000.txt");

  if (!leitor.is_open())
  {
    cerr << "ERRO! NÃO FOI POSSÍVEL ABRIR O ARQUIVO";
    leitor.clear();
  }

  while (leitor.getline(v, 1000))
  {
    cout << v << "\n";
  }
  leitor.close();

  cout << endl << endl;
  system("pause");
  return 0;
}