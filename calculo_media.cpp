#include <iostream>
#include <limits>
#include <string>
using namespace std;
#define TAMANHO_MAX_PRIMEIRO_NOME 15

int main()
{
    // declarando variáveis
    float media, nota;
    string nome;

    // inicializando variáveis;
    media = 0;

    // lendo nome
    cout << "Digite seu primeiro nome." << endl;
    cin >> nome;
    while (nome.size() > TAMANHO_MAX_PRIMEIRO_NOME)
    {
        cout << "Por favor, digite um nome com ate " << TAMANHO_MAX_PRIMEIRO_NOME << " caracteres." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> nome;
    }

    // lendo notas;
    for (int i = 1; i < 6; i++)
    {
        cout << "Digite a sua nota na " << i << " prova." << endl;
        if (cin >> nota)
        {
            if (nota >= 0 && nota <= 10) {
                media += nota;
            }
            else
            {
                cout << "Escreva um numero entre 0 e 10." << endl;
                i--;
            }
        }
        else
        {
            cout << "Por favor, digite um numero." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
    }

    // dividindo a soma das notas pela quantidade de provas;
    media = media / 5;

    // resultado final
    cout << nome << ", sua nota final eh: " << media << endl;

    // checando se está aprovado
    if (media >= 7)
    {
        cout << "Parabens, voce foi aprovado!" << endl;
    }
    else
    {
        cout << "Sinto muito, voce foi reprovado." << endl;
    }
    return 0;
}