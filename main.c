#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
	printf("/*****************/\n");
	printf("/* Jogo de Forca */\n");
	printf("/*****************/\n\n");
}

void chuta() {
	char chute;
	printf("Qual letra? \n");
    printf("___________________\n");
	scanf(" %c", &chute);

	chutes[chutesdados] = chute;
	(chutesdados)++;
}

int jachou (char letra)
    {
        int achou = 0;

			for(int y= 0; y < chutesdados; y++) {
				if(chutes[y] == letra) {
					achou = 1;
					break;
				}
			}
                return achou;
    }   

void desenhaforca()
{
printf("___________________\n");
printf("\nVocê já deu %d chutes\n", chutesdados);
    for(int x = 0; x < strlen(palavrasecreta); x++) {
int achou=jachou(palavrasecreta[x]);

if(achou) {
        printf("%c ", palavrasecreta[x]);}
             else {
				printf("_ ");
			}
		}

}
void escolhepalavra()
{   
    FILE* f;
    f=fopen("palavras.txt","r");
        int qtdepalavras;
    fscanf(f, "%d", &qtdepalavras);

srand(time(0));
int randomico =rand() % qtdepalavras;

    for (int i=0;i<=randomico;i++)
{
    fscanf(f, "%s", palavrasecreta);
}
    fclose(f);
}

int enforcou ()
{ int erros=0;
    for(int x=0;x<chutesdados;x++)
    {
        int existe=0;
        for (int y=0;y<strlen(palavrasecreta);y++)
        {
            if (chutes[x]==palavrasecreta[y])
            {
                existe=1;
                break;
            }
        }
        if(!existe)
        {
            erros++;
        }
    }
return erros >=5;
}
int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}
int main() {

	escolhepalavra(palavrasecreta);	
abertura();

	do {
		desenhaforca(palavrasecreta,chutes,chutesdados);
			
		    printf("\n");

		chuta(chutes, &chutesdados);


	} while (!acertou() && !enforcou());

}