#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

#include "../include/affichage.h"


void SDL_ExitWithError(const char *message){
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_InitWithExit(void){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_ExitWithError("Initialisation SDL");
    }
}

void SDL_WindowAndRendererWithExit(int width, int height, SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_CreateWindowAndRenderer(width, height, 0, window, renderer) != 0){
        SDL_ExitWithError("Creation fenetre et renderer echouee");
    }
}

bool SDL_HITBOX(SDL_Event event, int top_left, int top_right, int bottom_left, int bottom_right)
{   
    if (event.button.x >= top_left
        && event.button.x <= top_right
        && event.button.y >= bottom_left 
        && event.button.y <= bottom_right)
        return true;
    else
        return false;
}

SDL_Texture *SDL_CreateIMG(SDL_Renderer *renderer, const char *path){
    SDL_Surface *surface = SDL_LoadBMP(path); // Chargement de l'image
    if (surface == NULL) {SDL_ExitWithError("Chargement image echouee");} // On gère l'erreur

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface); // Chargement de la texture
    if (texture == NULL) {SDL_ExitWithError("Creation texture echouee");} // On gère l'erreur

    SDL_FreeSurface(surface); // On libère la surface
    return texture;
}