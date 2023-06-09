#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <math.h>

using namespace std;

/*5-Faça um programa que apresente um menu inicial com no mínimo duas opções: Cadastro e
Pesquisa. Quando o usuário desejar cadastrar, registre o nome, a altura, o peso, o cpf e o
sexo em uma struct. Com os dados cadastrados, implemente a função Pesquisa onde,através do
CPF,localize os dados de uma pessoa no registro e imprima o respectivo IMC.*/

#define PESSOAS 3 //quantidade de pessoas que irá participar

struct LISTAS //estrutura com as variáveis
{
  char nome[15];
  float altura, peso;
  long double cpf;
  char sexo;
};

LISTAS c[PESSOAS]; //chamando a struct
int opcao;         //variável

void menu();                  //escopo da função para mostrar o menu
void cadastramento(LISTAS[]); //escopo da função para cadastrar os usuários
void IMC(LISTAS[]);           //escopo da função para calcular o imc

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  menu();        //chamando a função menu
  system("cls"); //limpa tela

  if (opcao == 1) //execução de acordo com o que a pessoa escolheu no menu
  {
    cadastramento(c); //chamando a função cadastro
    system("cls");    //limpa tela
    return main();    //retornando ao menu
  }

  if (opcao == 2) //execução de acordo com o que a pessoa escolheu no menu
  {
    system("cls"); //limpa tela
    IMC(c);        //chamando a função imc e exibindo resultado
    return 0;
  }

  if (opcao == 3) //execução de acordo com o que a pessoa escolheu no menu
  {
    return 0;
  }
}

void menu() //menu de escolhas,opções
{
  cout << "**MENU**" << endl;
  cout << "1-Cadastrar" << endl;
  cout << "2-Pesquisar" << endl;
  cout << "3-Sair" << endl
       << endl;
  cin >> opcao;
}

void cadastramento(struct LISTAS c[PESSOAS]) //cadastro dos usuários
{
  cout << "CADASTRO DE DADOS DA PESSOA " << endl;
  for (int i = 0; i < PESSOAS; i++)
  {
    cout << "\nNome: ";
    cin >> c[i].nome;
    cout << "Altura: ";
    cin >> c[i].altura;
    cout << "Peso: ";
    cin >> c[i].peso;
    cout << "Sexo: ";
    cin >> c[i].sexo;
    cout << "CPF(somente números): ";
    cin >> c[i].cpf;
  }
}

void IMC(struct LISTAS c[PESSOAS]) //calculando o imc
{
  long double pesquisacpf;
  float massacorporal;

  cout << "\n Digite o CPF de quem tu quer saber o IMC: ";
  cin >> pesquisacpf;

  for (int i = 0; i < PESSOAS; i++)
  {
    if (pesquisacpf == c[i].cpf)
    {
      massacorporal = c[i].peso / (pow(c[i].altura, 2)); // fórmula do IMC
      system("cls");

      //resultados
      cout << "Nome: " << c[i].nome << endl;
      cout << "\nO IMC de " << c[i].nome << " é: " << setprecision(4) << massacorporal;
      //setprecision = arredondamento

      if (massacorporal < 18.5) // condições para a pessoa saber como está a situação do seu peso
      {
        cout << "\nAbaixo do peso";
      }
      else if (massacorporal <= 24.9)
      {
        cout << "\nPeso normal";
      }
      else if (massacorporal <= 29.9)
      {
        cout << "\nSobrepeso";
      }
      else if (massacorporal <= 34.9)
      {
        cout << "\nObesidade grau I";
      }
      else if (massacorporal <= 39.9)
      {
        cout << "\nObesidade grau II";
      }
      else
      {
        cout << "\nObesidade grau III ou Mórbida";
      }
      cout << endl;
    }
  }
}
