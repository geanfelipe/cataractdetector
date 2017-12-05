#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../libs/imagem.h"
#include "../libs/filtros.h"

void applyGrayScale(Image *image) {
	int jHeight, iWidth;	
	
	for(jHeight=0; jHeight< image->height; jHeight++) {
		for(iWidth=0; iWidth< image->width; iWidth++) {
			Pixel *pixel = &(image->pixels[jHeight][iWidth]);
			pixel->r = (int) ((0.299 * pixel->r) + (0.587 * pixel->g) + (0.144 * pixel->b));
			pixel->g = pixel->r;
			pixel->b = pixel->r;

			if(pixel->r > 255) {
				pixel->r = 255; 
				pixel->g = 255; 
				pixel->b = 255; 
			}
		}
	}
}


Pixel * validPixel(Image *image, int height, int width) {
	
	if(width >= image->width) 
		width = image->width -1;
	if(height >= image->height)
		height = image->height -1;
	if(width<0 )
		width = 0;
	if(height<0)
		height = 0;

	return &image->pixels[height][width];

}

void applyGaussianFiltering(Image *image) {
	/*o kernel é uma "Máscara Espacial" para a manipulação dos pixels da imagem*/
	const int kernel[5][5] = { {1,  4,  7,  4, 1},
				   {4, 16, 26, 16, 4},
			   	   {7, 26, 41, 26, 7},
			   	   {4, 16, 26, 16, 4},
			    	   {1,  4,  7,  4, 1}
			 };

	int jHeight, iWidth, iKernel, jKernel,count, divisor, value;
	Pixel *pixel;
	
	
	printf("Aplicando filtro gaussiano.......\n");	
	for(jHeight=0; jHeight< image->height; jHeight++) {
		for(iWidth=0; iWidth< image->width; iWidth++) {
			count = 0;
			divisor = 0;

			for(iKernel=0; iKernel<5; iKernel++) {
				for(jKernel=0; jKernel<5; jKernel++) {
					pixel = validPixel(image, jHeight + (iKernel - 2), iWidth + (jKernel -2));

					count += pixel->r * kernel[iKernel][jKernel];
					divisor += kernel[iKernel][jKernel];
				}
			}

			value =  count/divisor;
			image->pixels[jHeight][iWidth].r = value;
			image->pixels[jHeight][iWidth].g = value;
			image->pixels[jHeight][iWidth].b = value;
		}
	}
}


void applyToBinaryImage(Image *image) {
	const int Threshold = 127;
	int jHeight, iWidth;
	int rmin = 80, rmax = 255; //maximum and mininum value for red pixel
	int gmin = 30, gmax=150;
	int bmin = 0, bmax=20;

	for(jHeight=0; jHeight< image->height; jHeight++) {
		for(iWidth=0; iWidth< image->width; iWidth++) {
			Pixel *pixel = &(image->pixels[jHeight][iWidth]);

			if(pixel->r >= Threshold) pixel->r = 255;
			else pixel->r=0;
			
			if(pixel->g >= Threshold) pixel->g = 255;
			else pixel->g=0;

			if(pixel->b >= Threshold) pixel->b = 255;
			else pixel->b=0;
	         }
	}

}
