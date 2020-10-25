
#include "image_lib.h"
#include "preprocessing.h"
#include <SDL2/SDL.h>
SDL_Surface* display_image(SDL_Surface *img)
{
    SDL_Surface *screen;

    // Set the window to the same size as the image
    screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE);
    if (screen == NULL)
    {
        // error management
        errx(1, "Couldn't set %dx%d video mode: %s\n",
             img->w, img->h, SDL_GetError());
    }

    // Blit onto the screen surface
    if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
        warnx("BlitSurface error: %s\n", SDL_GetError());

    // Update the screen
    SDL_UpdateRect(screen, 0, 0, img->w, img->h);

    // return the screen for further uses
    return screen;
}

int preprocessing(const char *image_path)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *image;
    image = load(image_path);
    SDL_Surface *screen =  display_image(image);

    grayscale(image);
    SDL_SaveBMP(image, "output/grayscaled_image.bmp");

    binarization(image);
    SDL_SaveBMP(image, "output/binarized_image.bmp");


    SDL_FreeSurface(image);
    SDL_Quit();

    return 0;
}
