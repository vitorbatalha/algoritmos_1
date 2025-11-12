#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
#include <vector>

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

Data cadastrar_data_nascimento()
{
    Data data;
    cout << "Digite a data de nascimento do aluno no formato: (DIA MÊS ANO): " << endl;
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

string cadastrar_nome()
{
    string nome;
    cout << "Digite o nome do aluno: " << endl;
    while (1)
    {
        getline(cin >> ws, nome);
        if (nome.length() > 0 && nome.length() <= TAMANHO_MAX_NOME)
        {
            return nome;
        }
        else
        {
            cout << "Nome inválido. Por favor, digite novamente o nome do aluno: " << endl;
        }
    }
}

string cadastrar_curso()
{
    string curso;
    cout << "Digite o nome do curso do aluno: " << endl;
    while (1)
    {
        getline(cin >> ws, curso);
        if (curso.length() > 0)
        {
            return curso;
        }
        else
        {
            cout << "Entrada inválida. Por favor, digite novamente o nome do curso do aluno: " << endl;
        }
    }
}

string cadastrar_email()
{
    string email;
    cout << "Digite o email do aluno: " << endl;
    while (1)
    {
        getline(cin >> ws, email);
        if (email.size() > 0 && email.find('@') != string::npos)
        {
            return email;
        }
        else
        {
            cout << "Email inválido. Por favor, digite novamente o email do aluno: " << endl;
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
    cout << "Digite o CPF do aluno (somente números): " << endl;
    while (1)
    {
        getline(cin >> ws, cpf);

       
        if (validar_cpf(cpf))
        {
            return cpf; 
        }
        else
        {
            cout << "CPF inválido (formato ou dígitos verificadores incorretos). "
                << "Por favor, digite novamente (11 números): " << endl;
        }
    }
}

void static imprimir_header()
{
    cout << "-------- Sistema de Cadastro de Alunos --------" << endl
         << endl;
    cout << "1. Cadastrar novo aluno" << endl;
    cout << "2. Imprimir todos os alunos cadastrados" << endl;
    cout << "3. Sair" << endl
         << endl;
    cout << "Digite o número da opção que deseja escolher." << endl;
    cout << "-----------------------------------------------" << endl;
}

void static imprimir_aluno(Aluno a)
{
    cout << "---------------------- Dados do Aluno ---------------------" << endl;
    cout << "Nome: " << a.nome << endl;
    cout << "Data de Nascimento: " << setw(2) << setfill('0') << a.data_nascimento.dia << "/"
         << setw(2) << setfill('0') << a.data_nascimento.mes << "/"
         << a.data_nascimento.ano << endl;
    cout << "Curso: " << a.curso << endl;
    cout << "CPF: " << a.cpf << endl;
    cout << "Email: " << a.email << endl;
    cout << "-----------------------------------------------------------" << endl;
}

Aluno cadastrar_aluno()
{
    Aluno novo_aluno;

    novo_aluno.nome = cadastrar_nome();
    novo_aluno.data_nascimento = cadastrar_data_nascimento();
    novo_aluno.curso = cadastrar_curso();
    novo_aluno.email = cadastrar_email();
    novo_aluno.cpf = cadastrar_cpf();

    cout << "Aluno cadastrado com sucesso!" << endl;
    cout << "Verifique os dados cadastrados abaixo:" << endl;

    imprimir_aluno(novo_aluno);

    cout << "Deseja alterar algum dado?" << endl;
    cout << "1. Alterar nome" << endl;
    cout << "2. Alterar data de nascimento" << endl;
    cout << "3. Alterar curso" << endl;
    cout << "4. Alterar email" << endl;
    cout << "5. Alterar CPF" << endl;
    cout << "6. Nenhuma alteração, finalizar cadastro" << endl;

    int escolha;

    while (!(cin >> escolha))
    {
        cout << "Entrada inválida. Por favor, digite um número (1-6): ";
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
        cout << "Cadastro finalizado." << endl;
        break;
    default:
        cout << "Opção inválida. Finalizando cadastro sem alterações." << endl;
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
                cout << "Opção de cadastrar novo aluno selecionada." << endl;

                Aluno aluno_novo = cadastrar_aluno();
                lista_de_alunos.push_back(aluno_novo);

                cout << "\nAluno adicionado à lista. Voltando ao menu principal." << endl;
                break;
            }
            case 2:
                cout << "Opção de imprimir resultados selecionada." << endl;

                if (lista_de_alunos.empty())
                {
                    cout << "Nenhum aluno cadastrado no sistema." << endl;
                }
                else
                {
                    cout << "\n---------- Imprimindo lista de " << lista_de_alunos.size() << " aluno(s) -----------" << endl;

                    for (const Aluno &aluno_da_lista : lista_de_alunos)
                    {
                        imprimir_aluno(aluno_da_lista);
                    }
                    cout << "------------------- Fim da lista --------------------" << endl;
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