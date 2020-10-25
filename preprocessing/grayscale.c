#include "image_lib.h"

void grayscale(SDL_Surface *image)
{
    for(int i = 0; i < image->h; i++)
    {
        for(int j = 0; j < image->w; j++)
        {
            Uint32 pixel = get_pixel(image, i, j);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, image->format, &r, &g, &b);
            int average = 0.3 * r + 0.59 * g + 0.11 * b;
            r = average;
            g = average;
            b = average;
            Uint32 pixel2 = SDL_MapRGB(image->format, r, g, b);
            set_pixel(image, i, j, pixel2);
        }
    }
}
