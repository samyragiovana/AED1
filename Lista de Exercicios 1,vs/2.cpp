#include <iostream>
#include <windows.h>

using namespace std;

/*2- Escreva um programa em C/C++ utilizando struct que cadastre o nome, a matrícula e duas notas
de vários alunos. Em seguida imprima a matrícula, o nome e a média de cada um deles.*/

#define ALUNOS 3 //definindo a quantidade de pessoas que participarão

struct NOTAS //estrutura dos dados
{
  char nome[30];
  char matricula[15];
  float nota1;
  float nota2;
};

NOTAS n[ALUNOS]; //chamando a struct

void dadosAlunos(NOTAS[]); //escopo da função dos dados dos alunos
void resultado(NOTAS[]);   //escopo da função do resultado

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls"); //limpa tela

  dadosAlunos(n); //chamando a função para preencher os dados
  system("cls");  //limpa tela
  resultado(n);   //chamando a função resultado

  cout << endl
       << endl;
  system("pause");
  return 0;
}

void dadosAlunos(NOTAS[]) //pedindo os dados dos alunos
{
  for (int i = 0; i < ALUNOS; i++)
  {
    cout << "Nome: ";
    cin >> n[i].nome;

    cout << "Matricula: ";
    cin >> n[i].matricula;

    cout << "Nota 1: ";
    cin >> n[i].nota1;

    cout << "Nota 2: ";
    cin >> n[i].nota2;
  }
}

void resultado(NOTAS[]) //exibindo o resultado para o usuário
{ 
  float media;
  cout << "RESULTADOS\n";
  for (int i = 0; i < ALUNOS; i++)
  {
    media = (n[i].nota1 + n[i].nota1) / 2; //calculando a media de cada aluno

    cout << "\nNome: " << n[i].nome;
    cout << "\nMatricula: " << n[i].matricula;
    cout << "\nMedia: " << media;
  }
}