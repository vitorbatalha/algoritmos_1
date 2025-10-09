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

int main()
{
    // declarando variáveis: media (para armazenar a média das notas), nota (para armazenar cada nota individualmente) e nome (para armazenar o nome do aluno).
    // media e nota são do tipo float (números com ponto decimal) e nome é do tipo string (cadeia de caracteres).

    float media, nota, maior_nota;
    string nome, nome_maior_nota;
    
    maior_nota = 0;

    // inicializando variáveis:
    // Vamos iniciar a variável media com 0, para garantir que a soma das notas comece do zero.
    // Caso não façamos isso, a variável pode conter um valor lixo (um valor aleatório que estava na memória) e isso afetaria o cálculo da média.

    for (int i = 1; i < 4; i++) 
    {
    
    media = 0;

    // lendo nome do aluno;
    // utilizamos a função cout para exibir uma mensagem no terminal, pedindo ao usuário para digitar seu nome.
    // Em seguida, usamos a função cin para ler a entrada do usuário e armazená-la na variável nome.

    cout << "Aluno " << i << ", digite seu primeiro nome." << endl;
    cin >> nome;

    // A função while é um loop, que repete o bloco de código dentro dela enquanto a condição for verdadeira.
    // Nesse caso, a condição é que o tamanho do nome seja maior que o valor definido em TAMANHO_MAX_PRIMEIRO_NOME (15 caracteres).
    // Ou seja, enquanto o nome for maior que 15 caracteres, o programa continuará pedindo para o usuário digitar um nome válido.

    while (nome.size() > TAMANHO_MAX_PRIMEIRO_NOME)
    {
        // Se o nome for muito grande, exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
        // As funções cin.clear() e cin.ignore() são usadas para limpar o estado de erro do cin e ignorar qualquer entrada inválida que possa ter sido digitada anteriormente.

        cout << "Por favor, digite um nome com ate " << TAMANHO_MAX_PRIMEIRO_NOME << " caracteres." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Agora que limpamos a entrada, tentamos ler novamente a entrada.

        cin >> nome;
    }

    // lendo notas:
    // Aqui, usamos um loop for para repetir o processo de leitura das notas.
    // O loop for funciona da seguinte maneira: começamos com i igual a 1, e enquanto i for menor que 6, repetimos o bloco de código dentro do loop.
    // A cada loop, incrementamos i em 1 (i++ é o mesmo que i = i + 1).
    // Isso significa que o loop será executado 5 vezes (para i = 1, 2, 3, 4 e 5), permitindo que o usuário digite 5 notas.

    for (int i = 1; i < 6; i++)
    {
        // Dentro do loop, pedimos para o usuário digitar a nota da prova atual (usando o valor de i para indicar qual prova é).

        cout << "Digite a sua nota na " << i << " prova." << endl;

        // Aqui, usamos uma estrutura condicional if para verificar se a entrada do usuário é válida. 
        if (cin >> nota)
        {
            // Se a entrada for um número, verificamos se a nota está entre 0 e 10.
            if (nota >= 0 && nota <= 10)
            {
                // Se a nota for válida, adicionamos essa nota à variável media (que está sendo usada para acumular a soma das notas), e o loop se repete.
                media += nota;
                if (nota > maior_nota)
                {
                    maior_nota = nota;
                    nome_maior_nota = nome;
                }
                
            }
            else
            {
                // Se a nota não estiver entre 0 e 10, exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
                // Também decrementamos i em 1 (i--) para garantir que o loop repita a iteração atual, permitindo que o usuário digite a nota correta para a mesma prova.
                cout << "Escreva um numero entre 0 e 10." << endl;
                i--;
            }
        }
        else
        {
            // Se a entrada não for um número (por exemplo, se o usuário digitar uma letra), exibimos uma mensagem de erro e pedimos para o usuário digitar novamente.
            // Novamente, decrementamos i em 1 para repetir a iteração atual.
            // Também usamos cin.clear() e cin.ignore() para limpar o estado de erro do cin e ignorar a entrada inválida.
            cout << "Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
    }

    // dividindo a soma das notas pela quantidade de provas;
    // Após o loop, a variável media contém a soma das 5 notas. Para calcular a média, dividimos essa soma por 5.

    media = media / 5;

    // resultado final
    // Finalmente, exibimos a média final do aluno usando cout.

    cout << nome << ", sua media final eh: " << media << endl;

    // checando se está aprovado
    // Usamos outra estrutura condicional if para verificar se a média é maior ou igual a 7.
    // Se for, exibimos uma mensagem parabenizando o aluno pela aprovação.
    // Se a média for menor que 7, exibimos uma mensagem informando que o aluno foi reprovado.
    
    if (media >= 7)
    {
        cout << "Parabens, voce foi aprovado!" << endl;
    }
    else
    {
        cout << "Sinto muito, voce foi reprovado." << endl;
    }
    }
    cout << "A maior nota foi de " << nome_maior_nota << ", que tirou " << maior_nota << endl;

    return 0;
}