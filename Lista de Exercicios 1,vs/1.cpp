    #include <iostream>
    #include <windows.h>
    
    using namespace std;

    /*1- Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e armazene os
    dados em uma estrutura. Mostre os dados após o cadastro*/

    //Estrutura
    struct DADOS{
        string nome;
        int idade;
        string rua;
        float numeroCasa;
        string bairro;
    };

    int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");  //limpa tela
    
    DADOS p;    //chamando a struct

    //pedindo o usuário os dados
    cout << "Nome Completo: ";
    getline(cin, p.nome);

    cout << "Idade: ";
    cin >> p.idade;

    cout << "Rua: ";
    cin.ignore();
    getline(cin, p.rua);

    cout << "Número da casa: ";
    cin >> p.numeroCasa;

    cout << "Bairro: ";
    cin.ignore();
    getline(cin, p.bairro);

    system("cls");  //limpa tela

    //exibindo o resultado para o usuario
    cout << "DADOS INFORMADOS\n";
    cout << "\nNome: " << p.nome; 
    cout << "\nIdade: " << p.idade; 
    cout << "\nEndereço: " << p.rua << ", " << p.numeroCasa << ", " << p.bairro;

    cout << endl << endl;
    system("pause");
    return 0;
    }

