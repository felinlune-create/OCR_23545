// Created by mrsb75 on 05/10/2020.
#include "cstnts.h"
#include "convertion.h"
#include "image.h"

struct Matrix *convertTheImageToMatrix(SDL_Surface *image)
{
    struct Matrix *matrix = matrix_alloc(image->i * image->w, 1);
    for (int i = 0; i < image->i; i ++)
    {
        for (int j = 0; j < image->j; j++)
        {
            float val = (is_white_pixel(image, i ,  j )) ? 0. : 1.;
            matrix_set(matrix, i * image->w +  j , 0, val);
        }
    }
    return matrix;
}

struct Matrix *convertTheLettreToMatrix(char c)
{
    struct Matrix *matrix = matrix_alloc(g_charset_size, 1);
    for (size_t pos = 0; pos < g_charset_size; pos++)
        if (g_charset[pos] == c)
            matrix_set(matrix, pos, 0, 1.);
    return matrix;
}

char convertTheMatrixToLettre(struct Matrix *char_matrix)
{
    int pos = matrix_argmax(char_matrix);
    return g_charset[pos];
}

