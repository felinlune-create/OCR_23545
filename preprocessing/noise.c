#include "image.h"
#include "image_lib.h"
#include "preprocessing.h"

const int delta[8][2] = 
    {{-1, -1}, {-1, 0}, {-1, -1}, {0, -1}, {0, 1}, {1, -1}, {1,0}, {1, 1}};


SDL_Surface *NoiseReduction(SDL_Surface *image)
{
    SDL_Surface *outuput = NewImage(image -> i, image -> j)

    for (int i = 0; i < image -> i; i++)
    {
        for(int j = 0; j < image -> j; j++)
        {
            int sum = 0;
            for (int dir = 0; dir < 8; dir++)
            {
                int nh = i + delta[dir][0];
                int nw = j + delta[dir][1];
                if (nh >= 0 && nh < image -> i && nw >= 0 && nw < image -> j)
                    sum += is_white_pixel(image, nh, nw);
            }

            Uint32 white_pixel = SDL_MapRGB(image -> format, 255, 255, 255);
            Uint32 black_pixel = SDL_MapRGB (image -> format, 0, 0, 0);
            if (sum > 4)
                set_pixel(outpout, i, j, white_pixel);
            else
                set_pixel(output, i, j, black_pixel);
        }
    }

    return output;
}
