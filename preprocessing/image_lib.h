/*
 * =====================================================================================
 *
 *       Filename:  image_lib.h
 *
 *    Description:  header image_lib.h
 *
 *        Version:  1.0
 *        Created:  07/10/2020 19:31:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imad
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef image_lib_h 
#define image_lib_h
   
#include <SDL2/SDL.h>

SDL_Surface* load(const char* path);
SDL_Surface* NewImage(const int height, const int width);

Uint32 get_pixel(SDL_Surface* image, int h, int w);
void set_pixel(SDL_Surface* image, int h, int w, Uint32 pixel);
   
 #endif

