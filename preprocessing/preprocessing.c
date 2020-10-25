
#include "image_lib.h"
#include "preprocessing.h"
#include <SDL2/SDL.h>

void preprocessing(const char *image_path)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Rect positionFond;
    SDL_Surface *ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    
    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Surface *image = load(image_path);

    grayscale(image);
    SDL_SaveBMP(image, "output/grayscaled_image.bmp");

    binarization(image);
    SDL_SaveBMP(image, "output/binarized_image.bmp");

    SDL_BlitSurface(image, NULL, ecran, &positionFond);

    SDL_FreeSurface(image);
    SDL_Quit();

    return EXIT_SUCCESS;
}
