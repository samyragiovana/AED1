#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/*2. Implemente uma função que leia um valor inteiro no arquivo
"soma.txt". Retorne o valor que foi lido no arquivo.*/

void leitura(); //escopo da função

int main()
{
    system("cls"); //limpa a tela

    leitura(); //chamando a função

    return 0;
}

//função para imprimir a leitura do arquivo
void leitura()
{
    int numero; //variável

    ifstream arqEntrada; //entrada do arquivo

    arqEntrada.open("soma.txt"); //abrindo o arquivo

    //mensagens que serão se caso o arquivo abrir ou não
    if (!arqEntrada.is_open())
    {
        cerr << "ERRO! NÃO FOI POSSIVEL ABRIR O ARQUIVO !. \n\n";
    }
    else
    {
        clog << "ARQUIVO ABERTO COM SUCESSO !\n\n";
    }

    arqEntrada >> numero; //imprime o resultado no arquivo
    cout << numero;       //imprime o resultado no terminal

    arqEntrada.clear(); //limpa o arquivo
    arqEntrada.close(); //fecha o arquivo
}

//cout,cerr e clog basicamente significa escrever na tela, ambos tem a mesma função