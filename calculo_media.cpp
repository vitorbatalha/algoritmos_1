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

        if (cin >> a.notas[j])
        {
            if (a.notas[j] >= 0 && a.notas[j] <= 10)
            {
                a.media += a.notas[j];
                if (a.notas[j] > a.maior_nota)
                {
                    a.maior_nota = a.notas[j];
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

static void imprimir_resultados (Aluno a)
{
    cout << a.nome << ", sua média foi " << a.media << ", e sua maior nota foi " << a.maior_nota << endl;
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
    float maior_nota = 0;

    quantidade_alunos = ler_quantidade_alunos();    
    quantidade_notas = ler_quantidade_notas();
    
    Aluno a[quantidade_alunos];
    for (int i = 0; i < quantidade_alunos; i++)
    {
        a[i] = ler_nome(a[i]);
        a[i] = ler_notas(quantidade_notas, a[i]);
    }

    for (int k = 0; k < quantidade_alunos; k++)
    {
        cout << "-----------------------------" << endl;
        imprimir_resultados(a[k]);
        if (maior_nota < a[k].maior_nota)
        {
            maior_nota = a[k].maior_nota;
        }
    }

    cout << "-----------------------------" << endl;
    cout << "Quem tirou a maior nota (" << maior_nota << ") foi:" << endl;
    for (int k = 0; k < quantidade_alunos; k++)
    {
        if (a[k].maior_nota == maior_nota)
        {
            cout << a[k].nome << endl;
        }
    }
    return 0;
}