#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <SDL2/SDL.h>

int preprocessing(const char *image_path);

void binarization(SDL_Surface *image);
void grayscale(SDL_Surface *image);

#endif
