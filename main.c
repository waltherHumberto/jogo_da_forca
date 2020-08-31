#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[Tamanho_plv];
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
    int erros = chuteserrados();
   printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");


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
void adicionapalavra()
{ 
    char quer;
        printf("voce deseja adicionar uma nova palavra no jogo ? (S/N)\n\n");
            scanf(" %c",&quer);

        if (quer =='S')
        {
        char novapalvra[Tamanho_plv];
            printf("qual a nova palavra?");
               scanf("%s", novapalvra);

               FILE* f;
               f=fopen("palavras.txt","r+");
                if (f==0)
    {
        printf("desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }
            int qtd;
            fscanf(f,"%d",&qtd);
                 qtd++;
                 fseek(f,0,SEEK_SET);
                    fprintf(f,"%d",qtd);

                fseek(f,0,SEEK_END);
                 fprintf(f,"\n%s",novapalvra);
                     fclose(f);
        }
}
void escolhepalavra()
{   
    FILE* f;
    f=fopen("palavras.txt","r");
    if (f==0)
    {
        printf("desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }
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
int chuteserrados()
{
    int erros=0;
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
 return erros;
}
int enforcou ()
{ 
return chuteserrados() >=5;
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

    //adicionapalavra();
     abertura();
    escolhepalavra();	
   

	do {
		desenhaforca();
			
		    printf("\n");

		chuta();


	} while (!acertou() && !enforcou());

 if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }



        adicionapalavra();


}