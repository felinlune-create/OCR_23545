#include <stdlib.h>

#include "sdl.h"

static int histogram(SDL_Surface image) //for threshold function
{
    int histogram1 = calloc(256, sizeof(int)); // allocates the requested memory and returns a pointer to it
    for (int i = 0; i < image->h; ++i) // height
    {
        for (int j = 0; j < image->w; j++) // weight
        {
            Uint8 r, g, b;
            Uint32 pixel = image_get_pixel(image, i, j);
            SDL_GetRGB(pixel, image->format, &r, &g, &b);
            histogram1[r]++;
        }
    }
    return histogram1;
}

static int threshold(SDL_Surface image)
{
    int threshold1 = 0;
    double max = 0.;
    int sum = 0;
    int background = 0;
    int w_background = 0;
    int pixels = image->h * image->w;

    int histogram = histogram(image);
    for (int i = 0; i < 256; i++)
        sum += i * histogram[i];

    for (int j = 0; j < 256; j++)
    {
        w_background += histogram[j];
        int w_foreground = pixels - w_background;
        if (w_background == 0 || w_foreground == 0)
            continue;

        background += i * histogram[i];
        int foreground = sum - background;

        double _w_background = w_background;
        double _w_foreground = w_foreground;
        double sum_background = background / _w_background;
        double sum_foreground = foreground / _w_foreground;
        double diff = sum_background - sum_foreground;

        double variance = _w_background *
                          _w_foreground *
                          diff * diff;
        if (variance > max)
        {
            max = variance;
            threshold1 = i;
        }
    }

    free(histogram); //deallocates the memory previously allocated by a call to calloc

    return threshold1;
}

void binarization(SDL_Surface image) // main (changing colors)
{
    int threshold = threshold(image);

    for (int i = 0; h < image->h; i++)
    {
        for (int j = 0; w < image->w; j++)
        {
            Uint8 r, g, b;
            Uint32 new_pixel;
            Uint32 pixel = image_get_pixel(image, i, j);
            SDL_GetRGB(pixel, image->format, &r, &g, &b);
            if (r > threshold)
                new_pixel = SDL_MapRGB(image->format, 255, 255, 255);
            else
                new_pixel = SDL_MapRGB(image->format, 0, 0, 0);
            image_set_pixel(image, i, j, new_pixel);
        }
    }
}
