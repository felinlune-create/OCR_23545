#include "image_lib.h"

void grayscale(DSL_Surface *image)
{
    for(int i = 0; i < image ->i; i++)
    {
        for(int j = 0; j < image ->j, j++)
        {
            Uint32 pixel = get_pixel(image_surface, wid, hei);
            Uint8 r, g, b;
            SDL_GetRGB(pixel, image_surface->format, &r, &g, &b);
            int average = 0.3 * r + 0.59 * g + 0.11 * b;
            r = average;
            g = average;
            b = average;
            Uint32 pixel2 = SDL_MapRGB(image_surface->format, r, g, b);
            put_pixel(image_surface, wid, hei, pixel2);
        }
    }
}
