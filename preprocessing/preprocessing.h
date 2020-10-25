#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <SDL2/SDL.h>

void preprocessing(const char *image_path);

void grayscale(SDL_Surface *image);
void binarization(SDL_Surface *image);

#endif
