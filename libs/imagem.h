#ifndef IMAGEM_H
#define IMAGEM_H

typedef struct {
	int r,g,b;
} Pixel;

typedef struct {
	Pixel **pixels;
	int width,height;
	char code[10];
	int pixelMax;
	char *filename;
} Image;

Image * newImage(int width, int height, char *code);
Image * openImagefile(const char *filename);
void saveImage(Image *image, char *filename);
#endif
