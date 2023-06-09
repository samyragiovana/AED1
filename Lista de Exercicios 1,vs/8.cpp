#include <iostream>
#include <windows.h>

using namespace std;

/*8- Faça um programa para armazenar um livro de receitas e:
• Crie um vetor de 5 receitas, que deve ter nome (máximo 25 letras), quantidade de 
ingredientes e ingredientes.
• Para cada receita, leia seu nome e a quantidade de ingredientes.
• Crie e leia o vetor de ingredientes, sendo que cada ingrediente contém nome e quantidade.
• Implemente a busca de receita por nome, mostrando seus ingredientes, se encontrar.
*/

#define QTDE 2  //quantidade de receita a ser cadastrada

struct RECEITAS   //estrutura com as variáveis
{
  char nome[25];
  float qtdeing;
  char ingred[200];
};

void menu();  //escopo da função para mostrar o menu
void cadastramentodereceita(RECEITAS[]); //escopo da função para cadastrar as receitas
void resultado(RECEITAS[]); //escopo da função para mostar o resultado da receita desejada

RECEITAS r[QTDE];   //chamando e denominando a struct
int opcao;  //variável

int main()
{
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  menu(); //chamando a função menu
  system("cls"); //limpa tela

  if (opcao == 1) //execução de acordo com o que a pessoa escolheu no menu
  {
    cadastramentodereceita(r);  //cadastrando a receita
    system("cls"); // limpa tela
    return main(); //retornando ao menu
  }

  if (opcao == 2)//execução de acordo com o que a pessoa escolheu no menu
  {
    resultado(r); //mostrando o resultado
    system("pause");  //pausa para leitura
    system("cls");  //limpa tela
    return 0;//finaliza
  }

  if (opcao == 3)//execução de acordo com o que a pessoa escolheu no menu
  {
    return 0;
  }

  cout << endl
       << endl;
  system("pause");
  return 0;
}

void menu() //menu de escolhas,opções
{
  cout << "**MENU**" << endl;
  cout << "1-Cadastrar receita" << endl;
  cout << "2-Pesquisar receita" << endl;
  cout << "3-Sair" << endl;
  cin >> opcao;
}

void cadastramentodereceita(struct RECEITAS r[QTDE]) //cadastro das receitas
{
  for (int i = 0; i < QTDE; i++)
  { system("cls");
    cout << "****RECEITA " << i + 1 << "****";
    cout << "\nNome da receita: ";
    cin >> r[i].nome;
    cout << "Quantidade de ingredientes:";
    cin >> r[i].qtdeing;
    if (r[i].qtdeing > 0)
    {
      for (int j = 0; j < r[i].qtdeing; j++)
      {
        cout << "Ingrediente " << j + 1 << " :";
        cin >> gets(r[j].ingred);
      }
    }
  }
}

void resultado(struct RECEITAS r[QTDE]) //resultado do que o usuário deseja
{
  char pesquisa[25];
  cout << "Qual receita deseja procurar? ";
  cin >> pesquisa;
  for (int i = 0; i < QTDE; i++)
  {
    if (strcmp(pesquisa,r[i].nome) == 0)
    {
      cout << "\nNome: " << r[i].nome;
      cout << "\nIngredientes: ";
      for (int j = 0; j < r[i].qtdeing; j++)
      {
        cout << "\n" << "  " << r[j].ingred;
      }
    }
  }
  cout << endl << endl;
}
