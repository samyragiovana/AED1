#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

///4. Utilizando a função sizeof(), implemente o programa abaixo.

int main()
{
    ofstream arqSaida; //inpressao do exercicio no arquivo
    arqSaida.open("size.txt");

    //mensagem exibida caso o arquivo falhe ou execute
    if (arqSaida.fail())
    {
        cerr << "ERRO! Nao foi possivel criar o arquivo.";
        arqSaida.clear();
    }
    else
    {
        clog << "Arquivo criado com sucesso!\n";
    }

    //comandos que serão impressos
    arqSaida << "--- TIPO --- | --- BYTES ---" << endl;
    arqSaida << "char ........: "
             << "  " << sizeof(char) << " bytes" << endl;
    arqSaida << "int .........: "
             << "  " << sizeof(int) << " bytes" << endl;
    arqSaida << "short .......: "
             << "  " << sizeof(short) << " bytes" << endl;
    arqSaida << "long ........: "
             << "  " << sizeof(long) << " bytes" << endl;
    arqSaida << "float .......: "
             << "  " << sizeof(float) << " bytes" << endl;
    arqSaida << "double ......: "
             << "  " << sizeof(double) << " bytes" << endl;
    arqSaida << "long double  : "
             << "  " << sizeof(long double) << " bytes" << endl;

    arqSaida.clear(); //limpando o arquivo
    arqSaida.close(); //fechando o arquivo
}