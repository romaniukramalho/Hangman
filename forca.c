#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int sortWord(char *wordbank[]);
void Game(char *wordbank[],int animalrand, char *animal);
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
    char animal[30];
    strcpy(animal, wordbank[animalrand]);
    menu(animal);
    //printf("o animal sorteado foi %s \n", animal);
    printGame(wordbank, animalrand, animal);
}
int sortWord(char *wordbank[])
{
    srand(time(NULL));
    int sorted;

    sorted = (rand() % 34) + 1;
    //printf("o animal sorteado foi %s ", wordbank[sorted]);

    return sorted;
}
void Game(char *wordbank[],int animalrand, char *animal)
{
    int letra;
    prinf("Digite uma letra: \n")
    scanf("%c", &letra);
    letra = tolower(letra);
    int i;
    char comp = 'a'
    for(i = 0; i < 25; i++)
    {
        if(letra == (comp + i))
        {
            //termino depois
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