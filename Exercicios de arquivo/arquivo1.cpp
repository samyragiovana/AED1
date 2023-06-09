#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/*1. Implemente uma função que receba como parâmetro três
números e realize a soma destes números. Implemente outra
função para escrever o resultado no arquivo "soma.txt".*/

int soma(int, int, int); //escopo da função
void escreve(int);       //escopo da função

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int resultado; //variável

  resultado = soma(7, 25, 70); //atribuindo valores para a soma

  escreve(resultado); //chamando a função resultado

  return 0;
}

//função da soma
int soma(int a, int b, int c)
{
  return a + b + c;
}

//função que vai escrever o resultado no arquivo
void escreve(int r)
{
  ofstream arqSaida;

  arqSaida.open("soma.txt"); //abrindo o arquivo

  //caso não seja possível abrir o arquivo
  if (arqSaida.fail())
  {
    cerr << "ERRO  ! NÃO FOI POSSIVEL CRIAR O ARQUIVO\n";
    arqSaida.clear(); //limpa o "arquivo"
  }

  arqSaida << r; //imprimindo resultado dentro do arquivo soma.txt

  arqSaida.close(); //fechando o arquivo
}