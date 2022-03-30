#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct 
{
SDL_Surface *perso ;
SDL_Rect positionperso ;
int dir ;
}perso;


typedef struct 
{
SDL_Surface *point;
SDL_Rect posistionpoint ;
SDL_Surface *minimap;
SDL_Rect posistionminimap ;
}minimap;

void initmap (minimap *M ) ;
void affichage(minimap M , SDL_Surface * screen );
void affichaget( int *temps , SDL_Surface * screen, TTF_Font *police);
int collisionpp( Perso p, SDL_Surface * Masque);
void Liberer (minimap *M);
SDL_Color GetPixel (SDL_Surface* masque,int x,int y);
SDL_Rect MAJMinimap (SDL_Rect Posjoueur,int redemensionement);

#endif
