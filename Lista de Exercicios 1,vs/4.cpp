#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/*4- Faça um programa que leia os dados de 10 alunos (Nome, matricula, Media Final), 
armazenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores, 
o vetor dos aprovados e o vetor dos reprovados, considerando a media mínima para a 
aprovação como sendo 6.0. Exiba na tela os dados do vetor de aprovados,seguido dos dados 
do vetor de reprovados.*/

#define NALUNOS 3 //quantidade de pessoas que irá participar

struct ALUNOS //estrutura com variáveis
{
  char nome[15];
  char matricula[30];
  float nota1, nota2, nota3;
  float mediaFinal;
};

void dados(ALUNOS[]);      //escopo da função para cadastrar os dados
void aprovados(ALUNOS[]);  //escopo da função para os alunos aprovados
void reprovados(ALUNOS[]); //escopo da função para os alunos reprovados

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  ALUNOS a[NALUNOS]; //chamando a struct

  dados(a); //chamando a função cadastro

  for (int i = 0; i < NALUNOS; i++)
  {
    a[i].mediaFinal = a[i].nota1 + a[i].nota2 + a[i].nota3 / 3; //cálculo da media final de cada aluno
  }

  system("cls"); //limpa tela

  aprovados(a);  //chamando a função para mostrar os alunos aprovados
  reprovados(a); //chamando a função para mostrar os alunos reprovados

  cout << endl
       << endl;
  system("pause");
  return 0;
}

void dados(struct ALUNOS a[NALUNOS]) //cadastrando os dados
{
  cout << "Nome, matricula, e suas 3 notas";

  for (int i = 0; i < NALUNOS; i++)
  {
    cout << "\nALUNO " << i + 1 << "\n";
    cin >> a[i].nome >> a[i].matricula >> a[i].nota1 >> a[i].nota2 >> a[i].nota3; //leitura dos dados
  }
}

void aprovados(struct ALUNOS a[NALUNOS]) //condição para o aluno ser aprovado e mostrando resultado
{
  cout << "\n------Aprovados:------";
  for (int i = 0; i < NALUNOS; i++)
  {
    if (a[i].mediaFinal >= 6) //condição
    {
      cout << "\nNome: " << a[i].nome;
      cout << "\nSua média final foi: " << a[i].mediaFinal;
      cout << "\nParabéns pela aprovação '-' \n";
    }
  }
}

void reprovados(struct ALUNOS a[NALUNOS]) //condição para o aluno ser reprovado e mostrando resultado
{
  cout << "\n------Reprovados------";
  for (int i = 0; i < NALUNOS; i++)
  {
    if (a[i].mediaFinal < 6) //condição
    {
      cout << "\nNome: " << a[i].nome;
      cout << "\nSua média final foi: " << a[i].mediaFinal;
    }
    cout << endl;
  }
}
