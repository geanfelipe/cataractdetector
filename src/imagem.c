#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libs/imagem.h"


/*
	@obs vale lembrar, height = linhas e width = coluna

*/


Image * newImage(int width, int height, char code[10]) {
	int i;
	Image *image = (Image *) malloc(sizeof(Image));
	strncpy(image->code, code,10);

	image->pixels = (Pixel *) malloc(sizeof(Pixel) * height);
	
	for(i=0; i<width; i++) {
		image->pixels[i] = (Pixel *) malloc(sizeof(Pixel) * width);
	}

	image->width = width;
	image->height = height;
	
	return image;
}


Image * openImagefile(const char *filename) {
	int iWidth, jHeight;
	int pixelMax, height, width;
	char code[10];
	FILE *file;

	file = fopen(filename,"r");

	if(file==NULL) {
		printf("\n\terro ao ler a imagem \"%s\" \n",filename);
		exit(1);
	}

	fscanf(file,"%s",code);
	fscanf(file,"%d",&width);
	fscanf(file,"%d",&height);
	fscanf(file,"%d",&pixelMax);
	
	Image *image = newImage(width, height, code);
	image->pixelMax = pixelMax;
	image->filename = filename;

	printf("Tipo=%s; largura=%d; altura=%d;\n", image->code, image->width, image->height, image->pixelMax);
	
	for(jHeight=0; jHeight<height; jHeight++) {
		for(iWidth=0; iWidth<width; iWidth++) {

			Pixel *pixel = &(image->pixels[jHeight][iWidth]);
			fscanf(file,"%d",&pixel->r);
			fscanf(file,"%d",&pixel->g);
			fscanf(file,"%d",&pixel->b);
		}
	}
	
	fclose(file);
	return image;

}

void saveImage(Image *image, char *filename) {
	int jHeight, iWidth;

	FILE *file = fopen(filename,"w");
	
	if(file==NULL) {
		printf("\n\terro ao salvar no arquivo \"resultado.ppm\"\n");
	}

	fprintf(file,"%s\n",image->code);
	fprintf(file,"%d ",image->width);
	fprintf(file,"%d\n",image->height);
	fprintf(file,"%d\n",image->pixelMax);

	int length = image->width * image->height;
	
	for(jHeight=0; jHeight< image->height; jHeight++) {
		for(iWidth=0; iWidth< image->width; iWidth++) {

			fprintf(file,"%d\n",image->pixels[jHeight][iWidth].r);		
			fprintf(file,"%d\n",image->pixels[jHeight][iWidth].g);		
			fprintf(file,"%d\n",image->pixels[jHeight][iWidth].b);		
		}
	}

	fclose(file);
}
