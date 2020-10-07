/*
 * =====================================================================================
 *
 *       Filename:  image_lib.c
 *
 *    Description:  s'occupe des images entrée
 *
 *        Version:  1.0
 *        Created:  06/10/2020 15:04:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sdl2>
#include "image_lib.h"
#include <stdio.h>

int affiche(char path)
{
	SDL_Surface* image = SDL_LoadBMP(path);
	if(!image)
	{
    	printf("Erreur de chargement de l'image : %s",SDL_GetError());
    	return -1;
	}
	SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,image);  
	SDL_FreeSurface(image);
	return 0;
}
