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
    cout << "Digite o nome do curso do aluno: " << endl;
    while (1)
    {
        getline(cin >> ws, a.curso);
        if (a.curso.length() > 0)
        {
            return a.curso;
        }
        else
        {
            cout << "Entrada inválida. Por favor, digite novamente o nome do curso do aluno: " << endl;
        }
    }
}

string cadastrar_email(Aluno a)
{
    cout << "Digite o email do aluno: " << endl;
    while(1)
    {
        getline(cin >> ws, a.email);
        if (a.email.size() > 0 && a.email.find('@') != string::npos)
        {
            return a.email;
        }
        else
        {
            cout << "Email inválido. Por favor, digite novamente o email do aluno: " << endl;
        }
    }
}

string cadastrar_cpf(Aluno a)
{
    cout << "Digite o CPF do aluno (somente números): " << endl;
    while (1)
    {
        getline(cin >> ws, a.cpf);
        if (a.cpf.size() == 11 && a.cpf.find_first_not_of("0123456789") == string::npos)
        {
            return a.cpf;
        }
        else
        {
            cout << "CPF inválido. Por favor, digite novamente o CPF do aluno (somente números): " << endl;
        }
    }
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

void static imprimir_aluno(Aluno a)
{
    cout << "------------------- Dados do Aluno ------------------" << endl;
    cout << "Nome: " << a.nome << endl;
    cout << "Data de Nascimento: " << setw(2) << setfill('0') << a.data_nascimento.dia << "/"
         << setw(2) << setfill('0') << a.data_nascimento.mes << "/"
         << a.data_nascimento.ano << endl;
    cout << "Curso: " << a.curso << endl;
    cout << "CPF: " << a.cpf << endl;
    cout << "Email: " << a.email << endl;
    cout << "-----------------------------------------------------" << endl;
}

Aluno cadastrar_aluno(Aluno a)
{
    a.nome = cadastrar_nome(a);
    a.data_nascimento = cadastrar_data_nascimento(a);
    a.curso = cadastrar_curso(a);
    a.email = cadastrar_email(a);
    a.cpf = cadastrar_cpf(a);

    cout << "Aluno cadastrado com sucesso!" << endl;
    cout << "Verifique os dados cadastrados abaixo:" << endl;

    imprimir_aluno(a);

    cout << "Deseja alterar algum dado?" << endl;
    cout << "1. Alterar nome" << endl;
    cout << "2. Alterar data de nascimento" << endl;
    cout << "3. Alterar curso" << endl;
    cout << "4. Alterar email" << endl;
    cout << "5. Alterar CPF" << endl;
    cout << "6. Nenhuma alteração, finalizar cadastro" << endl;

    int escolha;

    switch (cin >> escolha, escolha)
    {
    case 1:
        a.nome = cadastrar_nome(a);
        break;
    case 2:
        a.data_nascimento = cadastrar_data_nascimento(a);
        break;
    case 3:
        a.curso = cadastrar_curso(a);
        break;
    case 4:
        a.email = cadastrar_email(a);
        break;
    case 5:
        a.cpf = cadastrar_cpf(a);
        break;
    case 6:
        cout << "Cadastro finalizado." << endl;
        break;
    default:
        cout << "Opção inválida. Finalizando cadastro." << endl;
        break;
    }
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
                a = cadastrar_aluno(a);
                break;
            case 2:
                cout << "Opção de imprimir resultados selecionada." << endl;
                imprimir_aluno(a);
                cout << "Deseja continuar cadastrando alunos?" << endl;
                char continuar;
                cout << "Digite 's' para sim ou 'n' para não: ";
                cin >> continuar;
                if (continuar == 's' || continuar == 'S')
                {
                    continue;
                }
                else
                {
                    cout << "Encerrando o sistema." << endl;
                    return 0;
                }
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