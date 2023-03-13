/**
 * \file affichage.h
 * \brief fichier d'entête pour avec des fonction pour l'affichage ( SDL )
 * 
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <SDL.h>
#include <stdbool.h>
#include "../include/monstre.h"
#include "../include/joueur.h"
#include "../include/inventaire.h"

/**
 * \brief fonction pour quitter le programme avec une erreur
 * 
 * \param message : message d'erreur
 */
void SDL_ExitWithError(const char *message);

/**
 * \brief fonction pour initialiser SDL
 * 
 */
void SDL_InitWithExit(void);

/**
 * \brief fonction qui permet de crée des hitbox
 * 
 * \param event : event de SDL
 * \param top_left : coordonnée du coin haut gauche
 * \param top_right : coordonnée du coin haut droit
 * \param bottom_left : coordonnée du coin bas gauche
 * \param bottom_right : coordonnée du coin bas droit
 * \return true : la souris est dans la hitbox
 * \return false : la souris n'est pas dans la hitbox
 */
bool SDL_RectHitbox(SDL_Event event, int top_left, int top_right, int bottom_left, int bottom_right);

/**
 * \brief procedure pour crée une fenetre et un renderer
 * 
 * \param width : largeur de la fenetre
 * \param height : hauteur de la fenetre
 * \param window : pointeur sur la fenetre SDL
 * \param renderer : pointeur sur le renderer SDL
 */
void SDL_WindowAndRendererWithExit(int width, int height, SDL_Window **window, SDL_Renderer **renderer);

/**
 * \brief fonction pour crée une image
 * 
 * \param renderer : pointeur sur le renderer SDL
 * \param path : chemin de l'image
 * \return SDL_Texture* 
 */
SDL_Texture *SDL_CreateIMG(SDL_Renderer *renderer, const char *path);

/**
 * \brief fonction pour afficher une image
 * 
 * \param renderer : pointeur sur le renderer SDL
 * \param texture : pointeur sur la texture SDL
 * \param x : coordonnée x
 * \param y : coordonnée y
 * \param w : largeur de l'image
 * \param h : hauteur de l'image
 */
void SDL_RenderIMG(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

/**
 * \brief procedure pour crée une barre de vie
 * 
 * \param renderer : pointeur sur le renderer SDL
 * \param x : coordonnée x
 * \param y : coordonnée y
 * \param w : largeur de la barre
 * \param h : hauteur de la barre
 * \param pv : point de vie
 */
void CreationBarDeVie(SDL_Renderer *renderer, int x, int y, int w, int h, int pv);

/**
 * \brief procedure pour afficher les monstres
 * 
 * \param renderer : pointeur sur le renderer SDL
 * \param texture : pointeur sur la texture SDL
 * \param w : largeur de l'image
 * \param h : hauteur de l'image
 * \param listeM : pointeur sur la liste de monstre
 * \param joueur : pointeur sur le joueur
 * \param inventaire : pointeur sur l'inventaire
 */
void SDL_RenderMonstre(SDL_Renderer *renderer, SDL_Texture *texture, int w, int h, monstreListe_t *listeM, joueur_t *joueur, inv *inventaire);

/**
 * \brief procedure pour afficher l'inventaire
 * 
 * \param inv : pointeur sur l'inventaire
 * \param renderer : pointeur sur le renderer SDL
 */
void SDL_RenderINV(inv * inv, SDL_Renderer * renderer);

#endif