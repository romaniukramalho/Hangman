#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int sortWord(char *wordbank[]);
void printword(char *animal, char *gamearray);
int Game(char *wordbank[], char *animal, char *gamearray);
void menu(char *animal);
int main()
{
    char *wordbank[] =  //banco de 34 palavras disponiveis no jogo da forca//
    {
        " ", "cachorro", "gaviao", "tubarao", "chimpanze", "urso", "papagaio",
        "cobra  marinha", "espaconave", "leao", "raposa", "elefante",
        "rato grande", "rato cumprido", "rato anao", "rato aquatico", "rato voador",
        "alce", "guaxinim", "dinossauro", "galinha", "camelo", "camarao", "polvo",
        "mistura de pato com foca", "caranguejo", "escorpiao", "pelicano", "cisne",
        "filhote de elefante", "bicho preguica", "tartaruga", "pinguim", "crocodilo", "periquito"
    };
    int animalrand = sortWord(wordbank);
    char animal[30], gamearray[30];
    strcpy(animal, wordbank[animalrand]);
    menu(animal);
    printf("o animal sorteado foi %s \n", animal);
    Game(wordbank, animal, gamearray);
}
int sortWord(char *wordbank[])
{
    srand(time(NULL));
    int sorted;

    sorted = (rand() % 34) + 1;
    //printf("o animal sorteado foi %s ", wordbank[sorted]);

    return sorted;
}
int Game(char *wordbank[], char *animal, char *gamearray)
{
    char letra; //letra escolhida pelo usuario
    int loops = 0; //para o entrar no if só quando checar a palavra inteira
    printf("Digite uma letra: \n");
    letra = tolower(letra);
    int tentativas = 0, j, i, k, found = 0; //found = check se achou alguma letra igual, tentativas = se a letra for invalida
    for(j = 0; j < strlen(animal); j++)
    {
        if(animal[k] == ' ')
        {
            gamearray[k] = ' ';
        }
        gamearray[j] = '_';
    }
    while(tentativas < 6)
    {
        fflush(stdin);
        while ((getchar()) != '\n'); // limpa o buffer manualmente
        for(i = 0; i < strlen(animal); i++)
        {
            if(letra == animal[i])
            {
                gamearray[i] = letra;
                found = 1;
            }
            loops++;
            if(loops == strlen(animal) && found != 0)
            {
                tentativas++;
            }
        }

        for(k = 0; k < strlen(animal); k++)
        {
            printf(" %c", gamearray[k]);
        }
    }

}
void menu(char *animal)
{
    system("clear");
    printf("-Bem vindo ao jogo da forca, o objetivo eh tentar adivinhar o nome dos animais antes que acabe as tentativas-\n");
    printf("O tema da partida sera animais, alguns de procedencia duvidosa, boa sorte\n\nAperte Enter para inicar a partida\n");
    
    getchar();

    int i;
    for(i = 0; i < strlen(animal); i++)
    {
        if(animal[i] == ' ')
        {
            printf("  ");
        }
        printf("_ ");
    }
    printf("\n");
}
