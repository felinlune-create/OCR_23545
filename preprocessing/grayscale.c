#include "sdl.h"

void grayscale(DSL_Surface *image)
{
    for(int i = 0; i < image ->i; i++)
    {
        for(int j = 0; j < image ->j, j++)
        {
            Uint8 r, g, b;
            Uint32 pixel = image_get_pixel(image, i, j)
            SDL_GetRGB(pixel, image-> format, &r, &g, &b);
            Uint avg = 0.2126*r + 0.7152*g + 0.0722*b; //formula of luminance
            Uint32 new_pixel = SDL_MapRGB(image->format, avg, avg, avg);
            image_set_pixel(image, h, w, new_pixel);
        }
    }
}
