#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
#define A 5

struct ALUNOS
{
  char nome[30];
  char matricula[25];
  float n1, n2, n3, n4;
  float media_bimestral, notafinal;
};

ALUNOS d[A];

void cadastro(ALUNOS[]);

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  cadastro(d);

  return 0;
}

void cadastro(ALUNOS[])
{
  ofstream arqSaida;
  arqSaida.open("NotasAlunos.txt");

  if (arqSaida.fail())
  {
    cerr << "ERRO! Nao foi possivel criar o arquivo.";
    arqSaida.clear();
  }
  cout << "DADOS: " << endl;
  for (int i = 0; i < A; i++)
  {
    cout << endl;
    cout << "Escreva seu nome : ";
    gets(d[i].nome);
    cout << "Digite sua matricula: ";
    cin >> d[i].matricula;
    cout << "Digite as notas: ";
    cin >> d[i].n1 >> d[i].n2 >> d[i].n3 >> d[i].n4;
    cin.ignore();
    cout << endl;
  }

  arqSaida << "Matricula"
           << "\t\t Nome "
           << "\t\tMedia "
           << "\t\tNota Final "
           << "\t\tSituação ";
  for (int i = 0; i < A; i++)
  {

    d[i].media_bimestral = (d[i].n1 + d[i].n2 + d[i].n3 + d[i].n1) / 4;

    d[i].notafinal = d[i].media_bimestral * 4;

    if (d[i].notafinal >= 60)
    {
      arqSaida << "\n"
               << d[i].matricula << "\t\t\t" << d[i].nome << "\t\t\t" << d[i].media_bimestral << "\t\t\t" << d[i].notafinal << "\t\t\t      APROVADO";
    }
    else
    {
      arqSaida << "\n"
               << d[i].matricula << "\t\t\t" << d[i].nome << "\t\t\t" << d[i].media_bimestral << "\t\t\t" << d[i].notafinal << "\t\t\t      REPROVADO";
    }
    arqSaida.close();
  }
}
