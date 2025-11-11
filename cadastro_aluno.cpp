#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
using namespace std;

#define TAMANHO_MAX_NOME 70

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    string nome;
    Data data_nascimento;
    string curso;
    int cpf;
    string email;
} Aluno;

void static limpar_entrada () 
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
    if ((cin >> a.nome))
    {
        if (a.nome.size() > TAMANHO_MAX_NOME)
        {
            return a.nome;
        }
        else
        {
            cout << "Por favor, digite um nome com até " << TAMANHO_MAX_NOME << " caracteres." << endl;
            limpar_entrada();
        }
    }
    else
    {
        cout << "Entrada inválida. Por favor, digite novamente o nome do aluno: " << endl;
        limpar_entrada();
    }
    
    return a.nome;
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

int main () 
{
    cout << "Cadastro de Aluno" << endl;

    while (1)
    {
       
    }
}