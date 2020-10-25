// Created by mrsb75 on 24/10/2020.
#include <stdio.h>
#include "segmentation.h"


int main()
{

    segmentation(input);
    SDL_Window* fenetre;
    SDL_Renderer* renderer;//Déclaration du renderer

    if(SDL_VideoInit(NULL) < 0) // Initialisation de la SDL
    {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

// Création de la fenêtre :
    fenetre = SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 600 , 600 , SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // Gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Surface* image = SDL_LoadBMP("../../output/testocr.bmp");
    if(!image)
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        return -1;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(renderer,image);  //La texture monImage contient maintenant l'image importée
    SDL_FreeSurface(image);
    return 0;
}
