#include <iostream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/*3 Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e 
telefone de 5 pessoas e os imprima em ordem alfabética.*/

#define QTDE_PESSOAS 5 //quantidade de pessoas que irá participar

struct PESSOAS //estrutura com variáveis
{
  char nome[20];
  char endereco[50];
  char telefone[20];
};

PESSOAS p[QTDE_PESSOAS]; //chamando a struct
PESSOAS auxiliar;        //variável

void cadastro(PESSOAS[]);  //escopo da função de cadastrar
void ordem(PESSOAS[]);     //escopo da função de ordenar
void resultado(PESSOAS[]); //escopo da função para mostrar o resultado

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls"); //limpa tela

  cadastro(p);   //chamando a função de cadastro
  system("cls"); //limpa tela
  ordem(p);      //chamando a função de ordenar em ordem alfábetica
  resultado(p);  //chamando a função para exibir o resultado ao usuário
  return 0;
}

void cadastro(struct PESSOAS p[QTDE_PESSOAS]) //cadastro dos usuários
{
  cout << "CADASTRO" << endl;
  for (int i = 0; i < QTDE_PESSOAS; i++)
  {
    cout << "NOME: ";
    gets(p[i].nome);

    cout << "ENDEREÇO: ";
    gets(p[i].endereco);

    cout << "TELEFONE: ";
    gets(p[i].telefone);

    cout << endl;
  }
}

void ordem(struct PESSOAS p[QTDE_PESSOAS]) //colocando o nome dos usuários em ordem alfábetica
{
  int retorno;
  for (int i = 0; i < QTDE_PESSOAS; i++)
  {
    for (int j = i + 1; j < QTDE_PESSOAS; j++)
    {
      retorno = strcmp(p[i].nome, p[j].nome); //strcmp função que coloca na ordem alfábetica
      if (retorno > 0)
      {
        auxiliar = p[j];
        p[j] = p[i];
        p[i] = auxiliar;
      }
    }
  }
}

void resultado(struct PESSOAS p[QTDE_PESSOAS]) //mostrando o resultado ao usuário
{
  cout << "Dados Cadastrados" << endl;
  for (int i = 0; i < QTDE_PESSOAS; i++)
  {
    cout << "NOME: " << p[i].nome << endl;
    cout << "ENDEREÇO: " << p[i].endereco << endl;
    cout << "TELEFONE: " << p[i].telefone << endl;
  }
}