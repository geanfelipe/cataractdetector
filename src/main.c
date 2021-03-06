#include <stdio.h>
#include <stdlib.h>
#include "../libs/imagem.h"

typedef struct {
	int r,g,b;
} Pixel;


void ler(Pixel imagem[500][500], char *code, int *max, int *coluna, int *linha) {
	int i,j;
	FILE *arquivo;

	char nome_arqv[30];
	printf("\n nome do arquivo: ");
	scanf("%s",nome_arqv);
	printf("\n%s\n",nome_arqv);

	arquivo = fopen(nome_arqv,"r");

	if(arquivo==NULL) {
		printf("\n\tnão foi possível ler o arquivo %s\n",nome_arqv);
		exit(1);
	}

	fscanf(arquivo, "%s",code);
	fscanf(arquivo, "%d",coluna);
	fscanf(arquivo, "%d",linha);
	fscanf(arquivo, "%d",max);


	printf("%s %d %d %d ", code, *coluna, *linha, *max);

	for(i=0; i< *linha; i++) {
		for(j=0;j< *coluna; j++) {
			fscanf(arquivo,"%d",&imagem[i][j].r);
			fscanf(arquivo,"%d",&imagem[i][j].g);
			fscanf(arquivo,"%d",&imagem[i][j].b);
			printf("\nlendo.......");
			
		}
	}
	printf("\ncabou!");
	fclose(arquivo);
}

void salvar(Pixel imagem[500][500], char *code, int max, int coluna, int linha) {
	int i,j;
	FILE *arquivo;

	char nome_arqv[30];
	printf("\nnome do arquivo: ");
	scanf("%s",nome_arqv);

	arquivo = fopen(nome_arqv,"w");

	if(arquivo==NULL) {
		printf("\n\t não foi possível criar o arquivo\n");
		exit(1);
	}

	fprintf(arquivo, "P3\n");
	fprintf(arquivo, "%d\n",coluna);
	fprintf(arquivo,"%d\n",linha);
	fprintf(arquivo,"%d\n",max);
	

	for(i=0; i< linha; i++) {
		for(j=0; j< coluna; j++) {
			fprintf(arquivo,"%d ", imagem[i][j].r);
			fprintf(arquivo,"%d ", imagem[i][j].g);
			fprintf(arquivo,"%d\n", imagem[i][j].b);
			
		}
	}

	fclose(arquivo);
}


void aplicarCinza(Pixel imagem[500][500], int coluna, int linha) {
	int i,j;
	for(i=0; i<linha; i++) {
		for(j=0; j<coluna; j++) {
			imagem[i][j].r = (int) ( (0.299 * imagem[i][j].r) + (0.587 *imagem[i][j].g) + (0.144*imagem[i][j].b) );
			imagem[i][j].g = imagem[i][j].r;
			imagem[i][j].b = imagem[i][j].r; 
			
		
			if(imagem[i][j].r > 255) {
				imagem[i][j].r = 255;
				imagem[i][j].g = 255;
				imagem[i][j].b = 255;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	
	Pixel imagem[500][500];
	char code[3];
	int max;
	int larg, alt;

	ler(imagem, code, &max, &larg, &alt);

	aplicarCinza(imagem,larg,alt);
	salvar(imagem,code,max,larg,alt);
	
	return 0;	
}
