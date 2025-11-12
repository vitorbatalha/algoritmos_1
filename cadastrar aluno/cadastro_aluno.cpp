#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

#define TAMANHO_MAX_NOME 70

const string RESET = "\033[0m";
const string VERMELHO = "\033[31m";
const string VERDE = "\033[32m";
const string AMARELO = "\033[33m";
const string AZUL = "\033[34m";
const string MAGENTA = "\033[35m";
const string CIANO = "\033[36m";

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

Data cadastrar_data_nascimento()
{
    Data data;
    cout << AMARELO << "Digite a data de nascimento do aluno no formato: (DIA MÊS ANO): " << RESET << endl;
    while (1)
    {
        if (cin >> data.dia >> data.mes >> data.ano)
        {
            if (data.dia >= 1 && data.dia <= 31 &&
                data.mes >= 1 && data.mes <= 12 &&
                data.ano > 1900 && data.ano <= 2025)
            {
                return data;
            }
            else
            {
                cout << VERMELHO << "Data inválida. Por favor, digite novamente, no formato: (DIA MÊS ANO): " << RESET;
            }
        }
        else
        {
            cout << VERMELHO << "Entrada inválida. Por favor, digite novamente, no formato: (DIA MÊS ANO): " << RESET;
            limpar_entrada();
        }
    }
}

string cadastrar_nome()
{
    string nome;
    cout << AMARELO << "Digite o nome do aluno: " << RESET << endl;
    while (1)
    {
        getline(cin >> ws, nome);
        if (nome.length() > 0 && nome.length() <= TAMANHO_MAX_NOME)
        {
            return nome;
        }
        else
        {
            cout << VERMELHO << "Nome inválido. Por favor, digite novamente o nome do aluno: " << RESET << endl;
        }
    }
}

string cadastrar_curso()
{
    string curso;
    cout << AMARELO << "Digite o nome do curso do aluno: " << RESET << endl;
    while (1)
    {
        getline(cin >> ws, curso);
        if (curso.length() > 0)
        {
            return curso;
        }
        else
        {
            cout << VERMELHO << "Entrada inválida. Por favor, digite novamente o nome do curso do aluno: " << RESET << endl;
        }
    }
}

string cadastrar_email()
{
    string email;
    cout << AMARELO << "Digite o email do aluno: " << RESET << endl;
    while (1)
    {
        getline(cin >> ws, email);
        if (email.size() > 0 && email.find('@') != string::npos)
        {
            return email;
        }
        else
        {
            cout << VERMELHO << "Email inválido. Por favor, digite novamente o email do aluno: " << RESET << endl;
        }
    }
}

bool validar_cpf(string cpf)
{
    if (cpf.size() != 11 || cpf.find_first_not_of("0123456789") != string::npos)
    {
        return false;
    }

    bool todos_iguais = true;
    for (int i = 1; i < 11; i++)
    {
        if (cpf[i] != cpf[0])
        {
            todos_iguais = false;
            break;
        }
    }

    if (todos_iguais)
    {
        return false;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++)
    {
        soma += (cpf[i] - '0') * (10 - i);
    }

    int resto = (soma * 10) % 11;
    int digito_verificador1 = (resto == 10) ? 0 : resto;

    if (digito_verificador1 != (cpf[9] - '0'))
    {
        return false;
    }

    soma = 0;
    for (int i = 0; i < 10; i++)
    {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = (soma * 10) % 11;
    int digito_verificador2 = (resto == 10) ? 0 : resto;

    if (digito_verificador2 != (cpf[10] - '0'))
    {
        return false;
    }

    return true;
}

string cadastrar_cpf()
{
    string cpf;
    cout << AMARELO << "Digite o CPF do aluno (somente números): " << RESET << endl;
    while (1)
    {
        getline(cin >> ws, cpf);

       
        if (validar_cpf(cpf))
        {
            return cpf; 
        }
        else
        {
            cout << VERMELHO << "CPF inválido (formato ou dígitos verificadores incorretos). "
                << "Por favor, digite novamente (11 números): " << RESET << endl;
        }
    }
}

void static imprimir_header()
{
    cout << AZUL << "-------------- Sistema de Cadastro de Alunos --------------" << RESET << endl
         << endl;
    cout << CIANO << "1. Cadastrar novo aluno" << RESET << endl;
    cout << CIANO << "2. Imprimir todos os alunos cadastrados" << RESET << endl;
    cout << CIANO << "3. Sair" << RESET << endl
         << endl;
    cout << AMARELO << "Digite o número da opção que deseja escolher." << RESET << endl;
    cout << AZUL << "-----------------------------------------------------------" << RESET << endl;
}

void static imprimir_aluno(Aluno a)
{
    cout << AZUL << "---------------------- Dados do Aluno ---------------------" << RESET << endl;
    cout << MAGENTA << "Nome: " << RESET << a.nome << endl;
    cout << MAGENTA << "Data de Nascimento: " << RESET << setw(2) << setfill('0') << a.data_nascimento.dia << "/"
         << setw(2) << setfill('0') << a.data_nascimento.mes << "/"
         << a.data_nascimento.ano << endl;
    cout << MAGENTA << "Curso: " << RESET << a.curso << endl;
    cout << MAGENTA << "CPF: " << RESET << a.cpf << endl;
    cout << MAGENTA << "Email: " << RESET << a.email << endl;
    cout << AZUL << "-----------------------------------------------------------" << RESET << endl;
}

Aluno cadastrar_aluno()
{
    Aluno novo_aluno;

    novo_aluno.nome = cadastrar_nome();
    novo_aluno.data_nascimento = cadastrar_data_nascimento();
    novo_aluno.curso = cadastrar_curso();
    novo_aluno.email = cadastrar_email();
    novo_aluno.cpf = cadastrar_cpf();

    cout << VERDE << "Aluno cadastrado com sucesso!" << RESET << endl;
    cout << AMARELO << "Verifique os dados cadastrados abaixo:" << RESET << endl;

    imprimir_aluno(novo_aluno);

    cout << AMARELO << "Deseja alterar algum dado?" << RESET << endl;
    cout << CIANO << "1. Alterar nome" << RESET << endl;
    cout << CIANO << "2. Alterar data de nascimento" << RESET << endl;
    cout << CIANO << "3. Alterar curso" << RESET << endl;
    cout << CIANO << "4. Alterar email" << RESET << endl;
    cout << CIANO << "5. Alterar CPF" << RESET << endl;
    cout << CIANO << "6. Nenhuma alteração, finalizar cadastro" << RESET << endl;

    int escolha;

    while (!(cin >> escolha))
    {
        cout << VERMELHO << "Entrada inválida. Por favor, digite um número (1-6): " << RESET;
        limpar_entrada();
    }

    switch (escolha)
    {
    case 1:
        novo_aluno.nome = cadastrar_nome();
        break;
    case 2:
        novo_aluno.data_nascimento = cadastrar_data_nascimento();
        break;
    case 3:
        novo_aluno.curso = cadastrar_curso();
        break;
    case 4:
        novo_aluno.email = cadastrar_email();
        break;
    case 5:
        novo_aluno.cpf = cadastrar_cpf();
        break;
    case 6:
        cout << VERDE << "Cadastro finalizado." << RESET << endl;
        break;
    default:
        cout << VERMELHO << "Opção inválida. Finalizando cadastro sem alterações." << RESET << endl;
        break;
    }

    limpar_entrada();

    return novo_aluno;
}

int main()
{
    int escolha;
    vector<Aluno> lista_de_alunos;

    while (1)
    {
        imprimir_header();
        if (cin >> escolha)
        {
            switch (escolha)
            {
            case 1:
            {
                cout << AMARELO << "Opção de cadastrar novo aluno selecionada." << RESET << endl;

                Aluno aluno_novo = cadastrar_aluno();
                lista_de_alunos.push_back(aluno_novo);

                cout << VERDE << "\nAluno adicionado à lista. Voltando ao menu principal." << RESET << endl;
                break;
            }
            case 2:
                cout << AMARELO << "Opção de imprimir resultados selecionada." << RESET << endl;

                if (lista_de_alunos.empty())
                {
                    cout << AMARELO << "Nenhum aluno cadastrado no sistema." << RESET << endl;
                }
                else
                {
                    cout << AZUL << "\n------------- Imprimindo lista de " << lista_de_alunos.size() << " aluno(s) --------------" << RESET << endl;

                    for (const Aluno &aluno_da_lista : lista_de_alunos)
                    {
                        imprimir_aluno(aluno_da_lista);
                    }
                    cout << AZUL << "---------------------- Fim da lista -----------------------" << RESET << endl;
                }

                break;
            case 3:
                cout << AMARELO << "Desligando o sistema." << RESET << endl;
                return 0;
            default:
                cout << VERMELHO << "Opção inválida. Por favor, escolha uma opção válida." << RESET << endl;
                break;
            }
        }
        else
        {
            cout << VERMELHO << "Entrada inválida. Por favor, digite um número correspondente à opção desejada." << RESET << endl;
            limpar_entrada();
        }
    }
}