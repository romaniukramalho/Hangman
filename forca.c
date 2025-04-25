#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void printword(char *animal, char *gamearray);
int Game(char *wordbank[], char *animal, char *gamearray);
void menu(char *animal);
int win(int erradas, char *animal, char *gamearray);
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
    srand(time(NULL));
    int sorted;
    sorted = (rand() % 34) + 1;
    char animal[30], gamearray[30];
    strcpy(animal, wordbank[sorted]); //copia o animal sorteado pra uma string
    strcpy(gamearray, animal); //copia o animal para o gamearray tbm
    int i, x;
    for(i = 0; i < strlen(animal); i++) //aqui o gamearray recebe tudo de "_"
    {
        if(animal[i] == ' ')
        {
            gamearray[i] = ' ';
        }
        else
        {
            gamearray[i] = '_';
        }
    }
    menu(animal);
    printf("o animal sorteado foi %s \n", animal);
    while(!win(x, animal, gamearray))
    {
        x = Game(wordbank, animal, gamearray);
        printword(animal, gamearray);
    }
}

int Game(char *wordbank[], char *animal, char *gamearray)
{
    char letra;  //letra escaneada e gamearray é o animal só que só de "_"
    printf("Chute uma letra\n");
    fflush(stdin);
    scanf("%c", &letra);
    letra = tolower(letra); //garantir q a letra ta em minusculo
    int i, verify = 0, erradas = 0;
    for(i = 0; i < strlen(animal); i++)
    {
        if(animal[i] == letra)
        {
            gamearray[i] = letra;
            verify++;
        }
    }
    if(verify = 0)
    {
        erradas++;
        printf("%d", verify);
        verify = 0;
    }
    return erradas;
}
    
void menu(char *animal)
{
    system("clear");
    printf("-Bem vindo ao jogo da forca, o objetivo eh tentar adivinhar o nome dos animais antes que acabe as tentativas-\n");
    printf("O tema da partida sera animais, alguns de procedencia duvidosa, boa sorte\n\nAperte Enter para inicar a partida\n");
    
    getchar();
    system("clear");

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

void printword(char *animal, char* gamearray)
{
    //system("clear");
    int i;
    for(i = 0; i < strlen(gamearray); i++)
    {
        printf("%c ", gamearray[i]);
    }
}

int win(int x, char *animal, char* gamearray)
{
    while(x < 5 || strcmp(animal, gamearray) != 0)
    {
        return 0;
    }
    return 1;
}