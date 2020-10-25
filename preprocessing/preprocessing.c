
#include "image_lib.h"
#include "preprocessing.h"
#include <SDL2/SDL.h>


int preprocessing(const char *image_path)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *image;
    image = load(image_path);

    grayscale(image);
    SDL_SaveBMP(image, "grayscaled_image.bmp");

    binarization(image);
    SDL_SaveBMP(image, "binarized_image.bmp");


    SDL_FreeSurface(image);
    SDL_Quit();

}

int main()
{        
    preprocessing("test.bmp");
    return 0;
}
