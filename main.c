#include <stdio.h>
#include <string.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta() {
	char chute;
	printf("Qual letra? \n");
    printf("___________________\n");
	scanf(" %c", &chute);

	chutes[tentativas] = chute;
	(tentativas)++;
}

int jachou (char letra, char chutes[26], int tentativas)
    {
        int achou = 0;

			for(int y= 0; y < tentativas; y++) {
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
printf("\nVocê já deu %d chutes\n", tentativas);
    for(int x = 0; x < strlen(palavrasecreta); x++) {
int achou=jachou(palavrasecreta[x],chutes,tentativas);

if(achou) {
        printf("%c ", palavrasecreta[x]);}
             else {
				printf("_ ");
			}
		}

}
void escolhepalavra()
{
sprintf(palavrasecreta, "MELANCIA");
}

int enforcou ()
{ int erros=0;
    for(int x=0;x<tentativas;x++)
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
int main() {

		int acertou = 0;


	escolhepalavra(palavrasecreta);	
abertura();

	do {
		desenhaforca(palavrasecreta,chutes,tentativas);
			
		    printf("\n");

		chuta(chutes, &tentativas);


	} while (!acertou && !enforcou());

}