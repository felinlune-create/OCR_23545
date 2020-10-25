/*
 * =====================================================================================
 *
 *       Filename:  image_lib.c
 *
 *    Description:  s'occupe des images à gere
 *
 *        Version:  1.0
 *        Created:  06/10/2020 15:04:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imad
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "image_lib.h"
#include <stdio.h>
#include <err.h>
#include <SDL2/SDL_image.h>




//load une image et la renvoie.
SDL_Surface *load(const char *path)
{
	SDL_Surface *image = SDL_LoadBMP(path);
	if(!image)
	{
    	    errx(3,"Erreur de chargement de l'image : %s",IMG_GetError());
	}
	return image;
}

 
//
SDL_Surface *NewImage(const int height, const int width)
{
	SDL_Rect dim;
	dim.y = 0;
	dim.x = 0;
	dim.h = height;
	dim.w = width;
	SDL_Surface* surface =
		SDL_CreateRGBSurface(0, dim.w, dim.h, 32, 0, 0, 0, 0);
	return surface;
}

static Uint8* _get_pixel(SDL_Surface *image, int h, int w)
{
    int bpp = image->format->BytesPerPixel;
    Uint8 *pixels = image->pixels;
    return pixels + h * image->pitch + w * bpp;
}

//get the value of a pixel
Uint32 get_pixel(SDL_Surface* image, int h, int w)
{
	Uint8* p = _get_pixel(image, h, w);

	switch (image->format->BytesPerPixel)
	{
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16*)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32*)p;
		break;

	default:
		return 0;
	}
}

//set de new value to a pixel
void set_pixel(SDL_Surface* image, int h, int w, Uint32 pixel)
{
	Uint8* p = _get_pixel(image, h, w);

	switch (image->format->BytesPerPixel)
	{
	case 1:
		*p = pixel;
		break;

	case 2:
		*(Uint16*)p = pixel;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
		break;

	case 4:
		*(Uint32*)p = pixel;
		break;

	default:
		break;
	}
}
