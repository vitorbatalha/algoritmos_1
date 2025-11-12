#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
using namespace std;

#define TAMANHO_MAX_NOME 70

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    string nome;
    Data data_nascimento;
    string curso;
    string cpf;
    string email;
} Aluno;

void static limpar_entrada()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Data cadastrar_data_nascimento(Aluno a)
{
    cout << "Digite a data de nascimento do aluno no formato: (DIA MÊS ANO): " << endl;
    while (1)
    {
        if (cin >> a.data_nascimento.dia >> a.data_nascimento.mes >> a.data_nascimento.ano)
        {
            if (a.data_nascimento.dia >= 1 && a.data_nascimento.dia <= 31 &&
                a.data_nascimento.mes >= 1 && a.data_nascimento.mes <= 12 &&
                a.data_nascimento.ano > 1900 && a.data_nascimento.ano <= 2025)
            {
                return a.data_nascimento;
            }
            else
            {
                cout << "Data inválida. Por favor, digite novamente, no formato: (DIA MÊS ANO): ";
            }
        }
        else
        {
            cout << "Entrada inválida. Por favor, digite novamente, no formato: (DIA MÊS ANO): ";
            limpar_entrada();
        }
    }
}

string cadastrar_nome(Aluno a)
{
    cout << "Digite o nome do aluno: " << endl;
    while (1)
    {
        getline(cin >> ws, a.nome);
        if (a.nome.length() > 0 && a.nome.length() <= TAMANHO_MAX_NOME)
        {
            return a.nome;
        }
        else
        {
            cout << "Nome inválido. Por favor, digite novamente o nome do aluno: " << endl;
        }
    }
}

string cadastrar_curso(Aluno a)
{
    cout << "Digite o curso do aluno: " << endl;
    if (cin >> a.curso)
    {
        return a.curso;
    }
    else
    {
        cout << "Entrada inválida. Por favor, digite novamente o curso do aluno: " << endl;
        limpar_entrada();
    }
    return a.curso;
}

string cadastrar_email(Aluno a)
{
    cout << "Digite o email do aluno: " << endl;
    if (cin >> a.email)
    {
        return a.email;
    }
    else
    {
        cout << "Entrada inválida. Por favor, digite novamente o email do aluno: " << endl;
        limpar_entrada();
    }
    return a.email;
}

string cadastrar_cpf(Aluno a)
{
    cout << "Digite o CPF do aluno (somente números): " << endl;
    if (cin >> a.cpf)
    {
        if (a.cpf.size() == 11)
        {
            return a.cpf;
        }
        else
        {
            cout << "CPF inválido. Por favor, digite um CPF com 11 dígitos." << endl;
            limpar_entrada();
        }
    }
    else
    {
        cout << "Entrada inválida. Por favor, digite novamente o CPF do aluno: " << endl;
        limpar_entrada();
    }
    return a.cpf;
}

void static imprimir_header()
{
    cout << "-------- Sistema de Cadastro de Alunos --------" << endl << endl;
    cout << "1. Cadastrar novo aluno" << endl;
    cout << "2. Imprimir resultados" << endl;
    cout << "3. Sair" << endl << endl;
    cout << "Digite o número da opção que deseja escolher." << endl;
    cout << "-----------------------------------------------" << endl;
}

Aluno cadastrar_aluno(Aluno a)
{
    a.nome = cadastrar_nome(a);
    a.data_nascimento = cadastrar_data_nascimento(a);
    a.curso = cadastrar_curso(a);
    a.email = cadastrar_email(a);
    a.cpf = cadastrar_cpf(a);
    cout << "Aluno cadastrado com sucesso!" << endl;
    return a;
}

int main()
{
    int escolha;
    Aluno a;

    while (1)
    {
        imprimir_header();
        if (cin >> escolha)
        {
            switch (escolha)
            {
            case 1:
                cout << "Opção de cadastrar novo aluno selecionada." << endl;
                cadastrar_aluno(a);
                break;
            case 2:
                cout << "Opção de imprimir resultados selecionada." << endl;
                break;
            case 3:
                cout << "Desligando o sistema." << endl;
                return 0;
            default:
                cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
                break;
            }
        }
        else
        {
            cout << "Entrada inválida. Por favor, digite um número correspondente à opção desejada." << endl;
            limpar_entrada();
        }
    }
}