/* Código feito para a disciplina de Algoritmos, de segundo período no curso de Engenharia de Computação na Multivix - Vila Velha.
    Data de entrega: 01/10/2025
    Objetivo: Ler o nome e as notas de um aluno, calcular a média e informar se ele foi aprovado ou reprovado.
*/

#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define TAMANHO_MAX_PRIMEIRO_NOME 15

typedef struct {
    string nome;
    float* nota;
    float media;
    float maior_nota;
    string status; 
} Aluno;

void static limpar_entrada () 
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Aluno ler_nome (Aluno a)
{
     cout << "Por favor, digite seu primeiro nome." << endl;
     cin >> a.nome;
     while (a.nome.size() > TAMANHO_MAX_PRIMEIRO_NOME)
    {
        cout << "Por favor, digite um nome com ate " << TAMANHO_MAX_PRIMEIRO_NOME << " caracteres." << endl;
        limpar_entrada();
        cin >> a.nome;
    }
    return a;
}

Aluno ler_notas (int quantidade_notas, Aluno a)
{ 
    a.nota = new float[quantidade_notas];
    a.media = 0;
    a.maior_nota = 0;

    for (int j = 0; j < quantidade_notas; j++)
    {
        cout << "Digite a sua nota na " << j+1 << "ª prova." << endl;

        if (cin >> a.nota[j])
        {
            if (a.nota[j] >= 0 && a.nota[j] <= 10)
            {
                a.media += a.nota[j];
                if (a.nota[j] > a.maior_nota)
                {
                    a.maior_nota = a.nota[j];
                }
            }
            else
            {
                cout << "Escreva um número entre 0 e 10." << endl;
                j--;
            }
        }
        else
        {
            cout << "Por favor, digite um número." << endl;
            limpar_entrada();
            j--;
        }
    }
    a.media = a.media/quantidade_notas;
    return a;
}

Aluno checar_status(Aluno a)
{
    if (a.media >= 7.0)
        a.status = "Aprovado";
    else
        a.status = "Reprovado";

    return a;
}

static void imprimir_resultados (Aluno a, int quantidade_notas)
{
    cout << "-------------------------------" << endl;
    cout << "Aluno: " << a.nome << endl;
    cout << "Notas: ";
    for (int i = 0; i < quantidade_notas; i++)
    {
        cout << a.nota[i];
        if (i < quantidade_notas - 1) cout << " | ";
    }
    cout << endl;

    cout << "Maior nota: " << a.maior_nota << endl;
    cout << "Média: " << a.media << endl;
    cout << "Status: " << a.status << endl;
}

int ler_quantidade_alunos()
{
    int quantidade;

    while (true)
    {
        cout << "Por favor, escreva o número de alunos." << endl;
        
        if (cin >> quantidade && quantidade > 0)
        {
            return quantidade; 
        }
        else
        {
            cout << "Por favor, escreva um número inteiro positivo." << endl;
            limpar_entrada(); 
        }
    }
}

int ler_quantidade_notas()
{
    int quantidade;

    while (true)
    {
        cout << "Por favor, escreva o número de notas." << endl;
        
        if (cin >> quantidade && quantidade > 0)
        {
            return quantidade; 
        }
        else
        {
            cout << "Por favor, escreva um número inteiro positivo." << endl;
            limpar_entrada(); 
        }
    }
}

int main()
{
    int quantidade_alunos;
    int quantidade_notas;

    quantidade_alunos = ler_quantidade_alunos();    
    quantidade_notas = ler_quantidade_notas();
    
    Aluno a[quantidade_alunos];

    for (int i = 0; i < quantidade_alunos; i++)
    {
        a[i] = ler_nome(a[i]);
        a[i] = ler_notas(quantidade_notas, a[i]);
        a[i] = checar_status(a[i]);
    }

for (int k = 0; k < quantidade_alunos; k++)
{
    imprimir_resultados(a[k], quantidade_notas);
    return 0;
}

}