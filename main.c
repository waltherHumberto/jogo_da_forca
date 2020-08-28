#include <stdio.h>
#include <string.h>

void abertura() {
	printf("/****************/\n");
	printf("/ Jogo de Forca */\n");
	printf("/****************/\n\n");
}

void chuta(char chutes[], int* tentativas) {
	char chute;
	printf("Qual letra? \n");
	scanf(" %c", &chute);

	chutes[*tentativas] = chute;
	(*tentativas)++;
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

int main() {

	char palavrasecreta[20];
	sprintf(palavrasecreta, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	char chutes[26];
	int tentativas = 0;

	abertura();

	do {
		
		printf("Você já deu %d chutes\n", tentativas);
		
		for(int x = 0; x < strlen(palavrasecreta); x++) {
			int achou=jachou(palavrasecreta[x],chutes,tentativas);

			if(achou) {
				printf("%c ", palavrasecreta[x]);
			} else {
				printf("_ ");
			}
		}
		printf("\n");

		chuta(chutes, &tentativas);


	} while (!acertou && !enforcou);

}