#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

/*3. Implemente uma função que leia três números do arquivo
"numeros.txt", e realize a soma destes números. Escreva o
resultado no arquivo "soma.dat".*/

int main()
{
    system("cls");                  //limpa a tela
    int vetor[3];                   //tamanho do vetor
    ifstream arqEntrada;            //entrada do arquivo
    arqEntrada.open("numeros.txt"); //função para abrir o arquivo

    //condição para se o arquivo não abrir, mostrar ao usuário esta mensagem
    if (!arqEntrada.is_open())
    {
        cerr << "ERRO ! NÃO FOI POSSIVEL ABRIR O ARQUIVO !";
        arqEntrada.clear(); //limpar o arquivo
    }

    //quando o arquivo é aberto, resultado
    for (int i = 0; i < 3; i++)
    {
        arqEntrada >> vetor[i];

        cout << vetor[i] << "\n";
    }

    arqEntrada.close(); //fechar o arquivo

    system("pause");
    
    return 0;
}