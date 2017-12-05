#ifndef IMAGEM_H
#define IMAGEM_H

void applyGrayScale(Image *image);
Pixel *  validPixel(Image *image, int height, int width);
void applyGaussianFiltering(Image *image);
void applyToBinaryImage(Image *image);

#endif
