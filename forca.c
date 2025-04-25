#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void printword(char *animal, char *gamearray, int *vidas, char *usedletras);
void Game(char *wordbank[], char *animal, char *gamearray, int *vidas, int *numletras, char *usedletras);
void menu(char *animal);
int win(char *animal, char *gamearray);
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
    char animal[30], gamearray[30], usedletras[26];
    strcpy(animal, wordbank[sorted]); //copia o animal sorteado pra uma string
    strcpy(gamearray, animal); //copia o animal para o gamearray tbm
    int i, vidas = 6, numletras = 0;
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
    //printf("o animal sorteado foi %s \n", animal);

    while(!win(animal, gamearray) && vidas != 0)
    {
        Game(wordbank, animal, gamearray, &vidas, &numletras, usedletras);
        printword(animal, gamearray, &vidas, usedletras);
    }
    if(strcmp(animal, gamearray) == 0)
    {
        printf("Varabens voce ganhou");
    }
    else
    {
        printf("Voce perdeu, a palavra era %s", animal);
    }
}

void Game(char *wordbank[], char *animal, char *gamearray, int *vidas, int *numletras, char *usedletras)
{
    char letra;  //letra escaneada e gamearray é o animal só que só de "_"
    int i, verify = 0, x = 0;
    printf("Chute uma letra\n");
    scanf(" %c", &letra);
    letra = tolower(letra); //garantir q a letra ta em minusculo
    for(i = 0; i < *numletras; i++)
    {
        if(usedletras[i] == letra)
        {
            x = 1;
        }
    }
    if(x == 1)
    {
        
    }

    else
    {
        usedletras[*numletras] = letra;
        (*numletras)++;
        for(i = 0; i < strlen(animal); i++)
        {
            if(animal[i] == letra)
            {
                gamearray[i] = letra;
                verify = 1;
            }
        }
        if(verify == 0)
        {
            (*vidas)--;
        }
    }
}
    
void menu(char *animal)
{
    system("clear");
    printf("-Bem vindo ao jogo da forca, o objetivo eh tentar adivinhar o nome dos animais antes que acabe as tentativas-\n");
    printf("O tema da partida sera animais, alguns de procedencia duvidosa, boa sorte\n\nAperte Enter para inicar a partida\n");
    
    getchar();
    system("clear");

    int i;
    printf(" +---+\n |   |\n     |\n     |\n     |\n     |\n\n");
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

void printword(char *animal, char* gamearray, int *vidas, char *usedletras)
{
    system("clear");
    int i;
    if(*vidas == 6)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 5)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 4)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf(" |   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 3)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|   |\n");
        printf("     |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 2)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("     |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 1)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("/    |\n");
        printf("     |\n");
        printf("\n");
    }
    if(*vidas == 0)
    {
        printf(" +---+\n");
        printf(" |   |\n");
        printf(" O   |\n");
        printf("/|\\  |\n");
        printf("/ \\  |\n");
        printf("     |\n");
        printf("\n");
    }
    for(i = 0; i < strlen(gamearray); i++)
    {
        printf("%c ", gamearray[i]);
    }
    printf("\n");
    printf("Letras usadas: %s\n", usedletras);
}

int win(char *animal, char *gamearray)
{
    for (int i = 0; i < strlen(animal); i++) 
    {
        if (gamearray[i] != animal[i])
        {
            return 0; //quebra o loop, não deixando ganhar
        }
    }
    return 1; //ganhou
}