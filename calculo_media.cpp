#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
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
     cout << "Por favor, digite o nome do aluno." << endl;
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
        cout << "Digite a nota do aluno na " << j+1 << "ª prova." << endl;

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

static void imprimir_resultados(Aluno a, int quantidade_notas)
{
    cout << "\n======================================" << endl;
    cout << "Aluno: " << a.nome << endl;
    cout << "--------------------------------------" << endl;
    cout << "Notas:       ";
            

    for (int i = 0; i < quantidade_notas; i++)
    {
        cout << fixed << setprecision(1) << a.nota[i];
        if (i < quantidade_notas - 1) cout << " | ";
    }
    cout << endl;

    cout << "Maior nota:  " << fixed << setprecision(1) << a.maior_nota << endl;
    cout << "Média:       " << fixed << setprecision(2) << a.media << endl;
    cout << "Status:      " 
         << (a.status == "Aprovado" ? "\033[32mAprovado\033[0m" : "\033[31mReprovado\033[0m")
         << endl;
    cout << "======================================\n" << endl;
}

void imprimir_melhores_alunos(Aluno* alunos, int quantidade_alunos) 
{

    float maior_geral = alunos[0].maior_nota;

    for (int i = 1; i < quantidade_alunos; i++) {
        if (alunos[i].maior_nota > maior_geral) {
            maior_geral = alunos[i].maior_nota;
        }
    }

    string magenta = "\033[35m";
    string reset = "\033[0m";

    cout << magenta;
    cout << "\n================== MELHORES ALUNOS ==================\n";
    cout << setw(20) << "Nome do Aluno      " << setw(10) << "Maior Nota" << endl;
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < quantidade_alunos; i++) {
        if (alunos[i].maior_nota == maior_geral) {
            cout << setw(20) << alunos[i].nome
                 << setw(10) << fixed << setprecision(2)
                 << alunos[i].maior_nota << endl;
        }
    }

    cout << "====================================================\n";
    cout << reset; 
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

    for (int j = 0; j < quantidade_alunos; j++)
    {
        imprimir_resultados(a[j], quantidade_notas);
    }

    imprimir_melhores_alunos(a, quantidade_alunos);

    return 0;

}