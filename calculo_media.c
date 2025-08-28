#include <stdio.h>
#include <string.h>
#define TAMANHO_MAX_PRIMEIRO_NOME 15

int main()
{
//declarando variáveis    
float media, nota;
char nome[TAMANHO_MAX_PRIMEIRO_NOME];
int i;

//inicializando variáveis;
media = 0;
i = 1;

//lendo nome e limpando o newline automático da função fgets;
printf("Digite seu primeiro nome.\n");
fgets(nome, sizeof nome, stdin);
nome[strcspn(nome, "\n")] = '\0';

//lendo notas;
for (int i = 1; i < 4; i++) {
    printf("Digite a sua nota na %d° prova.\n", i);
    scanf("%f", &nota);
    media += nota;
}

//dividindo a soma das notas pela quantidade de provas;
media = media/3;

//resultado final'
printf("%s, sua nota final é: %.1f.\n", nome, media);

//checando se está aprovado
if (media >= 7) {
    printf("Parabéns, você foi aprovado!\n");
}
else {
printf("Sinto muito, você foi reprovado.\n");
}
return 0;
}