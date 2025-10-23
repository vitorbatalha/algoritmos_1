/* Código feito para a disciplina de Algoritmos, de segundo período no curso de Engenharia de Computação na Multivix - Vila Velha.
    Data de entrega: 01/10/2025
    Objetivo: Ler o nome e as notas de um aluno, calcular a média e informar se ele foi aprovado ou reprovado.
*/

// Abaixo, os includes: bibliotecas necessárias para o funcionamento do código. 
// Bibliotecas são conjuntos de funções prontas, que facilitam a programação.
// A biblioteca <iostream> é usada para entrada e saída de dados.
//  <limits> para manipulação de limites numéricos (que permite limpar a entrada quando o usuário digitar algo errado), e <string> para trabalhar com strings.
// O comando "using namespace std;" é usado para evitar a necessidade de prefixar os elementos da biblioteca padrão com "std::". Assim, posso escrever "cout" em vez de "std::cout".
// A diretiva "#define TAMANHO_MAX_PRIMEIRO_NOME 15" define uma constante que limita o tamanho máximo do nome do aluno a 15 caracteres. É mais fácil alterar esse valor aqui do que em várias partes do código.

#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define TAMANHO_MAX_PRIMEIRO_NOME 15

// Abaixo, a nossa função principal "main", onde o programa começa a ser executado.

typedef struct {
    string nome;
    float nota;
    float media = 0;
    float maior_nota = 0;
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
        // Se o nome for muito grande, exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
        // As funções cin.clear() e cin.ignore() são usadas para limpar o estado de erro do cin e ignorar qualquer entrada inválida que possa ter sido digitada anteriormente.

        cout << "Por favor, digite um nome com ate " << TAMANHO_MAX_PRIMEIRO_NOME << " caracteres." << endl;
        limpar_entrada();

        // Agora que limpamos a entrada, tentamos ler novamente a entrada.

        cin >> a.nome;
    }
    return a;
}

Aluno ler_notas (int quantidade_notas, Aluno a)
{ 
     for (int j = 0; j < quantidade_notas; j++)
        {
        cout << "Digite a sua nota na " << j+1 << " prova." << endl;

        // Aqui, usamos uma estrutura condicional if para verificar se a entrada do usuário é válida. 
        if (cin >> a.nota)
        {
            // Se a entrada for um número, verificamos se a nota está entre 0 e 10.
            if (a.nota >= 0 && a.nota <= 10)
            {
                // Se a nota for válida, adicionamos essa nota à variável media (que está sendo usada para acumular a soma das notas), e o loop se repete.
                a.media += a.nota;
                if (a.nota > a.maior_nota)
                {
                    a.maior_nota = a.nota;
                }
            }
            else
            {
                // Se a nota não estiver entre 0 e 10, exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
                // Também decrementamos i em 1 (i--) para garantir que o loop repita a iteração atual, permitindo que o usuário digite a nota correta para a mesma prova.
                cout << "Escreva um numero entre 0 e 10." << endl;
                j--;
            }
        }
        else
        {
            // Se a entrada não for um número (por exemplo, se o usuário digitar uma letra), exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
            // Novamente, decrementamos i em 1 para repetir a iteração atual.
            // Também usamos cin.clear() e cin.ignore() para limpar o estado de erro do cin e ignorar a entrada inválida.
            cout << "Por favor, digite um numero." << endl;
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

int main()
{
    int quantidade_alunos;
    int quantidade_notas;
    float maior_nota = 0;

    
    cout << "Por favor, escreva o número de alunos." << endl;
    cin >> quantidade_alunos;
    while (cin.fail())
    {
        limpar_entrada();
        cout << "Por favor, escreva um numero valido." << endl;
    }
    
    cout << "Por favor, escreva o número de notas." << endl;
    cin >> quantidade_notas;
    while (cin.fail())
    {
        limpar_entrada();
        cout << "Por favor, escreva um numero valido." << endl;
    }
    
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