// Created by mrsb75 on 05/10/2020.
#ifndef UTILS_CONVERT_H
#define UTILS_CONVERT_H

#include <SDL2/SDL.h>

#include "matrix.h"

struct Matrix *convertTheImageToMatrix(SDL_Surface *image);
struct Matrix *convertTheLettreToMatrix(char c);
char convertTheMatrixToLettre(struct Matrix *char_matrix);

#endif

