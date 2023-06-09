#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

#define MAXTAM 5 // tamanho maximo da pilha
#define INICIO 0 // posicao inicial da pilha

typedef int TChave; // tipo de dados da chave

typedef struct TCelula_str *TApontador; // ponteiro para TCelula

typedef struct{
    TChave codigo; // codigo do projeto
    char nome[30]; // nome do projeto
    int horas;     // numero de horas trabalhas no projeto
} TProjeto;

typedef struct{

    TProjeto item[MAXTAM]; // vetor dos projetos
    int primeiro;          // primeiro da lista
    int ultimo;            // ultimo da lista
} TListaSequencial;

typedef struct{

    TChave codfuncionario;     // codigo do funcionario
    char nomefuncionario[40];  // nome do funcionario
    char endereco[40];         // endereco do funcionario
    int dependentes;           // numero de dependentes do funcionario
    TListaSequencial projetos; // Lista Sequencial que guarda os projetos nos quais o funcionario trabalha
} TFuncionario;

typedef struct TCelula_str{    // Struct de cada celula da lista

    TFuncionario item; // item da celula funcionario
    TApontador prox;   // TApontador para o proximo da celula
} TCelula;

typedef struct{          // Struct da lista
    TApontador primeiro; // TApontador para o primeiro da lista
    TApontador ultimo;   // TApontador para o ultimo da lista
} TListaEncadeada;

void menu(); // imprime menu

// Funções TAD
void Cria_List_Encad_Vazia(TListaEncadeada *lista);                // Cria uma lista encadeada vazia
int Verif_List_Encad_Vazia(TListaEncadeada lista);                 // Verifica se a lista encadeada está vazia
void Cria_List_Sequenc_Vazia(TListaSequencial *Lista);             // Cria uma lista sequencial vazia
int Verif_List_Sequenc_Vazia(TListaSequencial lista);              // Verifica se a lista sequencial está vazia
void Insere_List_Encad(TFuncionario f, TListaEncadeada *lista);    // Insere a lista encadeada
void Insere_List_Sequenc(TProjeto x, TListaSequencial *lista);     // Insere a lista sequencial
int Busca_Encad(TChave cod, TListaEncadeada lista, TApontador *p); // Busca a lista encadeada
int Busca_Sequenc(int cod, TListaSequencial lista, int *p);        // Busca a lista sequencial

// Funções específicas
void Cadadastro_de_funcionarios(TListaEncadeada *lista);      // Cadastra os funcionarios
void Cadastro_de_Projetos(TListaEncadeada *lista);           // Cadastra os projetos
void Mostra_Projetos(TListaSequencial Lista);               // Imprime os projetos
void Exclusao_de_Projeto(TListaEncadeada *lista);          // Exclui os projetos
void Busca_Funcionario(TListaEncadeada lista);            // Consulta os funcionarios
void Free_Func_S_Projetos(TListaEncadeada *lista);       // Exclui funcionarios sem projetos
void Exclui_Funcionario(TListaEncadeada *lista);        // Exclui funcionario
void Mostra_Contracheques(TListaEncadeada *lista);     // Imprime o contra cheque
void Remove_Funcionario(int p, TListaSequencial *lista, TProjeto *Proj); // Remove funcionarios

int main(){

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls"); // limpa tela

    TListaEncadeada lista; // Apélidando a struct de lista
    TApontador p;
    TFuncionario f;

    Cria_List_Encad_Vazia(&lista); // chamando cria lista encadeada vazia

    FILE *arquivo;
    arquivo = fopen("Funcionario.bin", "a+b"); // a+b = Acrescenta dados ou cria o arquivo binario p leitura e escrita. 
    p = lista.primeiro;

    if (arquivo != NULL)
    {
        while (fread(&f, sizeof(TFuncionario), 1, arquivo)){

            Insere_List_Encad(f, &lista);
        }
        fclose(arquivo);
    }
    else{
        cout << "ERRO !!! ARQUIVO INEXISTENTE ...";
        getch();
        system("cls"); // limpa tela
    }

    int opcao;
    do{
        menu();                         // chamando menu
        cout << "ESCOLHA SUA OPÇÃO: "; // escolha sua opção
        cin >> opcao;                 // lendo opção
        system("cls");
        switch (opcao){ // escolha caso

        case 1:
             Cadadastro_de_funcionarios(&lista); //novo funcionario
        cout << "\n\n\nDESEJA CADASTRAR PROJETOS PARA O FUNCIONARIO  ?  1 - Sim | 2 - Não -> "; 
        cin >> opcao;

        if( opcao == 1){
            Cadastro_de_Projetos(&lista); //se o funcionário quiser cadastrar projetos 

        }
        if(opcao == 2){
            system("cls");
            cout << "\n\nPRESIONE ENTER PARA VOLTAR AO MENU";
            getch(); //Espera digitar o  ENTER para prosseguir
        }
        system("cls"); // limpa tela  
        break;

        case 2:
            Cadastro_de_Projetos(&lista);
            break;

        case 3:
            Exclusao_de_Projeto(&lista);
            break;

        case 4:
            Free_Func_S_Projetos(&lista);
            break;

        case 5:
            Exclui_Funcionario(&lista);
            break;
            
        case 6:
            Busca_Funcionario(lista);
            break;

        case 7:
            Mostra_Contracheques(&lista);
            break;
        }
    } while (opcao != 8);   //opção roda enquanto for diferente de 8.

    arquivo = fopen("Funcionario.bin", "wb");

    while (p->prox != NULL){
        f = p->prox->item;
        fwrite(&f, sizeof(TFuncionario), 1, arquivo);
        p = p->prox;
    }
    fclose(arquivo);

   
    system("cls");
    return 0;
}

void menu(){            //chamando menu
    system("color 0A"); //colocando cor ver!
   
                   
    cout << "\n------------------MENU-----------------" <<endl;      //imprimir menu
    cout << "       1-Incluir novo funcionario"         <<endl;      //inclusão de funcionário
    cout << "       2-Incluir novos projetos"           <<endl;      //inclusão de projetos
    cout << "       3-Excluir Projeto"                  <<endl;      //excluir projetos
    cout << "       4-Excluir funcionario S/Projeto"    <<endl;      //excluir funcionário sem projeto       
    cout << "       5-Excluir Funcionário"              <<endl;      //excluir funcionario completamente 
    cout << "       6-Consulta Funcionário"             <<endl;      //Consultar funcionario
    cout << "       7-Imprimir Contra-Cheque"           <<endl;      //mostrar contra-cheque do funcionario
    cout << "       8-Sair"                             <<endl;      //sair do programa
    cout << "---------------------------------------"   <<endl<<endl;

}

void Cria_List_Encad_Vazia(TListaEncadeada *lista){ //criando a lista encadeada vazia
    lista->primeiro = new TCelula;   //Primeira posição recebe uma nova celula
    lista->ultimo = lista->primeiro; //Lista Ultima recebe Posição de lista Primeiro
    lista->primeiro->prox = NULL;    //Lista primeiro proximo recebendo NULL
}

int Verif_List_Encad_Vazia(TListaEncadeada lista){ // Verifica se a lista encadeada está vazia
    return (lista.primeiro == lista.ultimo); // retornando se lista primeiro for igual a ultimo
}

int Verif_List_Sequenc_Vazia(TListaSequencial lista){// Verifica se a lista sequencial está vazia
    return (lista.primeiro == lista.ultimo); // retornando se lista primeiro for igual a ultimo
}

void Cria_List_Sequenc_Vazia(TListaSequencial *Lista){// criando lista sequencial vazia
    Lista->primeiro = INICIO;        // apontando se lista primeiro for igual inicio no caso 0
    Lista->ultimo = Lista->primeiro; // apontando se lista ultimo for igual lista primeiro
}

void Insere_List_Encad(TFuncionario f, TListaEncadeada *lista){// Insere lista encadeada
    lista->ultimo->prox = new TCelula;   // apontando lista ultimo proximo para new TCelula
    lista->ultimo = lista->ultimo->prox; // apontando lista ultimo igual lista ultimo proximo
    lista->ultimo->item = f;             // apontando lista ultimo item igual f do TFuncionario
    lista->ultimo->prox = NULL;          // apontando lista ultimo proximo para NULL
}

void Insere_List_Sequenc(TProjeto x, TListaSequencial *Lista){ // Insere lista sequencial
    if (Lista->ultimo == MAXTAM) // lista apontando para o ultimo == MAXTAM tamanho definido
        cout << " ERRO !!! TODOS PROJETOS JÁ ESTÃO CADASTRADOS ...";
    else{// se não
        Lista->item[Lista->ultimo] = x; // lista item apontando para lista ultimo igual x
        Lista->ultimo++;                // lista ultimo ++ prosseguindo
    }
}

int Busca_Encad(TChave cod, TListaEncadeada lista, TApontador *p){ // Busca encadeada
    TApontador aux = lista.primeiro; // TApontador auxiliar igual lista chamando primeiro
    int achou = 0;                   // declaração de variaveis

    while ((!achou) && (aux->prox != NULL)) // while para auxiliar caso achar retonar
        if (aux->prox->item.codfuncionario == cod)
            achou = 1; // se for 1 verdadeiro achou
        else
            aux = aux->prox;
    *p = aux;
    return (achou); // retornando achou
}

int Busca_Sequenc(int cod, TListaSequencial lista, int *p){// busca sequencial
    int i = lista.primeiro; // int i = lista para primeiro
    int achou = 0;          // declaração de variaveis

    while ((!achou) && (i < lista.ultimo)) // while para auxiliar caso achar retonar
        if (lista.item[i].codigo == cod)
            achou = 1; // se for 1 verdadeiro achou
         else
            i++;
    *p = i;
    return (achou); // retornando achou
}

void Cadadastro_de_funcionarios(TListaEncadeada *lista){// cadastrando funcionario
    TFuncionario f; // TFuncionario declarado como f

    cout << "*******************************************\n"; // cadastrando funcionario
    cout << "*        CADASTRO DE FUNCIONÁRIO          *\n";
    cout << "*******************************************\n\n";
    cout << "CÓDIGO.....: "; // informar codigo
    cin >> f.codfuncionario;
    cin.ignore();
    fflush(stdin);
    cout << "NOME.......: "; // informar nome
    gets(f.nomefuncionario);
    cout << "ENDEREÇO...: "; // informar endereço
    gets(f.endereco);
    cout << "DEPENDENTES: "; // informar dependentes
    cin >> f.dependentes;

    Cria_List_Sequenc_Vazia(&f.projetos); // para cadastro de projetos
    Insere_List_Encad(f, lista);             // inserindo lista encadeada

    cout << "\n\nFUNCIONÁRIO CADASTRADO COM SUCESSO !!!";
    
}

void Cadastro_de_Projetos(TListaEncadeada *lista){ // cadastro de projetos
    TProjeto x;   // TProjeto declarado como X
    TApontador p; // TApontador declarado como P
    TChave cod;   // TChave declarado como COD
    int j, ret;   // declaração variaveis

    system("cls");

    cout << " ***************************************\n";
    cout << " *         CADASTRO DE PROJETOS        *\n";
    cout << " ***************************************\n\n";
    cout << "CODIGO DO FUNCIONARIO: ";
    cin >> cod;

    ret = Busca_Encad(cod, *lista, &p);

    if (ret == 1){
        cout << "\n\nDIGITE UM CODIGO PARA O PROJETO: ";
        cin >> x.codigo;
        if (Busca_Sequenc(x.codigo, p->prox->item.projetos, &j)){
            cout << "\nO CODIGO DIGITADO EXISTENTE\n\n";
            system("pause");
            system("cls");
        }
        else{ // se encontrou
            cout << "\nNOME DO PROJETO: ";
            cin >> x.nome;
            cout << "\nQUANTIDADE DE HORAS TRABALHADAS: ";
            cin >> x.horas;
            Insere_List_Sequenc(x, &(p->prox->item.projetos));
            system("cls");

            cout << "\nPROJETO FOI CADASTRADO COM SUCESSO !!!";
            system("pause");
            system("cls");
        }
    }
    else{ // se não encontrou
        cout << "\nERRO !!! CODIGGO DE FUNCIONARIO DIGITADO AINDA NÃO FOI CADASTRADO !!!\n\n";
        system("pause");
        system("cls");
    }
}

void ApagaFuncionario(TApontador x, TListaEncadeada *lista, TFuncionario *f){ // apaga funcionario
    TApontador q;

    if ((Verif_List_Encad_Vazia(*lista)) || (x == NULL) || (x->prox == NULL)){
        cout << "ERRO !!! LISTA ESTÁ VAZIA"; // verificando a lista encadeada se está vazia
    }
    else{
        q = x->prox;
        *f = q->item;
        x->prox = q->prox;

        if (x->prox == NULL){
            lista->ultimo = x;
        }
        delete q;
    }
}

void Exclui_Funcionario(TListaEncadeada *lista){ // excluir funcionario
    TFuncionario f;
    TApontador x = lista->primeiro;
    int cont = 0;

    while (x->prox != NULL){
        ApagaFuncionario(x, lista, &f); // função apaga funcionario
        cont++;
    }

    system("cls"); // limpa tela

    cout << "*******************************************\n";
    cout << "*        EXCLUSÃO DE FUNCIONÁRIOS         *\n";
    cout << "*******************************************\n\n";
    cout << "\n"
         << cont << " FUNCIONARIO(S) EXCLUÍDO(S) COM SUCESSO!\n\n";
    system("pause");
    system("cls");
}

void ListaFuncionario(TListaEncadeada *lista){ // lista de funcionario função
    TApontador aux = lista->primeiro->prox;

    system("cls");

    cout << "*******************************************\n";
    cout << "*        LISTAGEM DE FUNCIONÁRIOS         *\n";
    cout << "*******************************************\n\n";

    while (aux){ // fazendo um while para auxiliar
        cout << "\nCODIGO.....: " << aux->item.codfuncionario;
        cout << "\nNOME.......: " << aux->item.nomefuncionario;
        cout << "\nENDERECO...: " << aux->item.endereco;
        cout << "\nDEPENDENTES: " << aux->item.dependentes << endl
             << endl;
        aux = aux->prox;
    }
    system("pause");
    system("cls");
}

void Busca_Funcionario(TListaEncadeada lista){ // consultando o funcionario
    TChave cod;
    TApontador p;
    system("cls");
    int ret;

    cout << "*******************************************\n";
    cout << "*        CONSULTA DE FUNCIONÁRIO          *\n";
    cout << "*******************************************\n\n";
    cout << "INFORME O CODIGO DO FUNCIONARIO: ";
    cin >> cod;

    ret = Busca_Encad(cod, lista, &p); // ret recebendo a função busca encadeada

    if (ret == 1){
        cout << "\nCODIGO: " << p->prox->item.codfuncionario;
        cout << "\nNOME: " << p->prox->item.nomefuncionario;
        cout << "\nENDEREÇO: " << p->prox->item.endereco;
        cout << "\nDEPENDENTES: " << p->prox->item.dependentes << endl
             << endl;
        cout << "\nO FUNCIONARIO SOLICITADO POSSUI O(S) SEGUINTE(S) PROJETO(S): \n";

        Mostra_Projetos(p->prox->item.projetos); // função sendo chamada para imprimir os projetos

        system("pause");
        system("cls");
        cout << endl;
    }
    else{
        cout << "\nERRO !!! O CODIGO QUE VC DIGITOU AINDA NÃO FOI CADASTRADO !!!\n\n";
        system("pause");
        system("cls");
    }
}

void Mostra_Projetos(TListaSequencial Lista){ // imprime projetos
    int i;
    for (i = 0; i < Lista.ultimo; i++){
        cout << "\n CODIGO DO PROJETO:        " << Lista.item[i].codigo;         // para digitar codigo
        cout << "\n NOME DO PROJETO:          " << Lista.item[i].nome;          // para digitar nome
        cout << "\n HORAS TRABALHADAS:        " << Lista.item[i].horas << "\n";// para digitar horas trabalhadas
    }
}

void Free_Func_S_Projetos(TListaEncadeada *lista){ // exclui um funcionario

    TApontador p, ant; // Tapontador sendo declarado como P e ANT
    TChave cod;        // Tchave sendo declarado como COD
    int ret;           // Declaração de variaveis

    system("cls");

    cout << "*******************************************\n";
    cout << "*   EXCLUSÃO DE FUNCIONÁRIO  SEM PROJETO   *\n";
    cout << "*******************************************\n\n";
    cout << "DIGITE O CODIGO DO FUNCIONARIO: ";
    cin >> cod;
    ret = Busca_Encad(cod, *lista, &p);
    if (ret == 1){

        if (p->prox->item.projetos.primeiro == p->prox->item.projetos.ultimo){ // Se a lista estiver vazia
            ant = p;
            p = p->prox;
            ant->prox = p->prox;
            delete p; // Exclui o funcionario
            cout << "\nFUNCIONARIO EXCLUIDO COM SUCESSO !!!\n\n";
            system("pause");
            system("cls");
        }
        else{ // Se a lista não estiver vazia
            cout << "\nFUNCIONARIO NÃO PODE SER EXCLUIDO POIS ELE JÁ POSSUI PROJETOS !!!\n\n";
            system("pause");
            system("cls");
        }
    }
    else{ // Se não encontrou
        cout << "\nERRO !!! O CODIGO QUE VC DIGITOU AINDA NÃO FOI CADASTRADO !!!\n\n";
        system("pause");
        system("cls");
    }
}

void Exclusao_de_Projeto(TListaEncadeada *lista){                 // Excluir projetos
    TChave cod;   // Tchave sendo nomeado como COD
    TApontador p; // Tapontador sendo nomeado como P
    TProjeto Proj;
    int codExcluido, y, ret; // Variaveis sendo declaradas

    system("cls");

    cout << "*******************************************\n";
    cout << "*        EXCLUSÃO DE PROJETO              *\n";
    cout << "*******************************************\n\n";
    cout << "DIGITE O CODIGO DO FUNCIONARIO: ";
    cin >> cod;
    ret = Busca_Encad(cod, *lista, &p); // Busca encadeada
    
    if (ret == 1){
        p = p->prox;
        cout << "\nDIGITE O CODIGO DO PROJETO PARA SER EXCLUIDO: ";
        cin >> codExcluido;
        
        if (Busca_Sequenc(codExcluido, p->item.projetos, &y)){
            Remove_Funcionario(y, &(p->item.projetos), &Proj); // Busca sequencial

            cout << "\nPROJETO EXCLUIDO COM SUCESSO\n\n"; // projeto excluido com sucesso
            system("pause");
            system("cls");

        }
        else{ // Projeto não existe
            cout << "\nCODIGO DIGITADO NÃO EXISTE\n\n";
            system("pause");
            system("cls");
        }
    }
    else{ // Se não encontrou
        cout << "\nERRO !!! O CODIGO QUE VC DIGITOU AINDA NÃO FOI CADASTRADO !!!\n\n";
        system("pause");
        system("cls");
    }
}

void Mostra_Contracheques(TListaEncadeada *lista){
    TApontador Aux = lista->primeiro->prox;
    int Total_de_Horas = 0; // declaração variaveis
    float Sal_Bruto, Sal_Liquido, INSS, IRPF;

    system("cls");

    cout << "*******************************************\n";
    cout << "*         IMPRIMIR CONTRA-CHEQUE          *\n";
    cout << "*******************************************\n\n";

    while (Aux){
        cout << "\nCODIGO: " << Aux->item.codfuncionario;
        cout << "\nNOME: " << Aux->item.nomefuncionario;

        for (int i = 0; i < Aux->item.projetos.ultimo; i++){ // mostra contra cheque

            Total_de_Horas = Total_de_Horas + Aux->item.projetos.item[i].horas;
        }
        // declaração das contas para o resultado de ambas
        Sal_Bruto = (Total_de_Horas * 45) + (35 * Aux->item.dependentes);
        INSS = Sal_Bruto * 0.085;
        IRPF = Sal_Bruto * 0.15;
        Sal_Liquido = Sal_Bruto - (INSS + IRPF);

        cout << "\nTotal de Horas: " << Total_de_Horas; // imprime total de horas trabalhadas
        cout << "\nSalario Bruto: " << Sal_Bruto ;          // imprime salario bruto
        cout << "\nDesconto Inss: " << INSS;                  // imprime INSS
        cout << "\nDesconto IRPF: " << IRPF;               // imprime imposto de renda                                                                                                                                                                                                                                        
        cout << "\nSalario Liquido: " << Sal_Liquido << endl << endl; // imprime salario liquido

        // reseta os salarios para entrada de novos valores
        Sal_Bruto = 0;
        Sal_Liquido = 0;
        INSS = 0;
        Total_de_Horas = 0;
        IRPF = 0;
        Aux = Aux->prox;
    }
    system("pause");
    system("cls");
}

void Remove_Funcionario(int p, TListaSequencial *lista, TProjeto *Proj){
    if (Verif_List_Sequenc_Vazia(*lista)){
        cout << "ERRO !!! LISTA VAZIA...";
    }
    *Proj = lista->item[p];
    lista->ultimo--;
    for (int i = p; i < lista->ultimo; i++){
        lista->item[i] = lista->item[i + 1];
    }
}