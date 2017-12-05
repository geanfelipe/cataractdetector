#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libs/imagem.h"
#include "../libs/filtros.h"

int main(int argc, char *argv[]) {
		
	char *file_name = argv[2];
	char *format = 	argv[4];

	if(file_name==NULL || format==NULL) {
		printf("ERROR: ./catarata -i imagem.ppm -f bmp -o diagnostico.txt\n");
		exit(1);
	}

	Image *image = openImagefile(file_name);
	applyGrayScale(image);
	saveImage(image, "images/result/gray.ppm");

	applyGaussianFiltering(image);
	saveImage(image,"images/result/gaussian.ppm");

	applyToBinaryImage(image);
	saveImage(image,"images/result/binary.ppm");

	return 0;	
}
