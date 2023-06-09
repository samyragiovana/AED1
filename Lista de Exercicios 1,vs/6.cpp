#include <iostream>
#include <windows.h>

using namespace std;

/*6 Utilizando funções e struct, faça um programa em C/C++ que cadastre vários produtos 
(utilize Menu). Em seguida, imprima uma lista com o código e nome da cada produto. 
Por fim, consulte o preço de um produto através de seu código.*/

#define QTDE 3 //quantidade de produtos

struct LISTAS //estrutura com as variáveis
{
    char produto[15];
    long double id;
    float preco;
};

LISTAS l[QTDE]; //chamando a struct
int opcao;      //variável

void menu();                  //escopo da função para mostrar o menu
void cadastro(LISTAS[]);      //escopo da função para cadastro
void money(LISTAS[]);         //escopo da função para pesquisar o preço
void todosprodutos(LISTAS[]); //escopo da função para mostrar os produtos

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    menu();        //chamando a função menu
    system("cls"); //limpa tela

    if (opcao == 1) //execução de acordo com o que a pessoa escolheu no menu
    {
        cadastro(l);   //chamando a função cadastro
        system("cls"); //limpa tela
        return main(); //retornando ao menu
    }

    if (opcao == 2) //execução de acordo com o que a pessoa escolheu no menu
    {
        system("cls");    //limpa tela
        todosprodutos(l); //chamando a função para mostrar todos os produtos
        money(l);         //chamando a função para pesquisar o preço do produto
        return 0;
    }

    if (opcao == 3) //execução de acordo com o que a pessoa escolheu no menu
    {
        return 0;
    }
}

void menu() //menu de opções
{
    cout << "**MENU**" << endl;
    cout << "1-Cadastrar produto" << endl;
    cout << "2-Pesquisar preço" << endl;
    cout << "3-Sair" << endl;
    cin >> opcao;
}

void cadastro(struct LISTAS l[QTDE]) //cadastrando os produtos
{
    for (int i = 0; i < QTDE; i++)
    {
        cout << "Nome do produto: ";
        cin >> l[i].produto;
        cout << "ID do produto: ";
        cin >> l[i].id;
        cout << "Informe o preço: ";
        cin >> l[i].preco;
    }
}

void money(struct LISTAS l[QTDE]) //função para o usuário pesquisar o preço do produto
{
    long double pesquisapreco;

    cout << "\n\n\nDigite o Id do produto que você quer ver o preço: ";
    cin >> pesquisapreco;

    for (int i = 0; i < QTDE; i++)
    {
        if (pesquisapreco == l[i].id)
        {
            system("cls");
            //resultado sendo mostrado
            cout << "O produto é " << l[i].produto << " e custa " << l[i].preco << " reais o kg";
            cout << endl;
        }
    }
}

void todosprodutos(struct LISTAS l[QTDE])
{ //mostrando todos os produtos ao usuário
    cout << "Produtos Cadastrados\n";
    for (int i = 0; i < QTDE; i++)
    {
        cout << "\nProduto: " << l[i].produto;
        cout << "\nID do produto: " << l[i].id;
    }
}