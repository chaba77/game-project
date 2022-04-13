#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
#include "perso.h"
#define SCREEN_W 1450
#define SCREEN_H 900
typedef struct Image Background;


void initBack(Background *b, char filename[]);
void afficherBack(Background b, SDL_Surface * screen);
void animerBackground(Background backgrounds[],int length, SDL_Surface *screen);
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y);
int  collisionparfaite(SDL_Surface *psurface,SDL_Rect *back,Personne p, int r, int g , int b);
void scrolling(SDL_Rect *b,  int direction, int pasAvancement);
void collision(SDL_Surface *psurface,Personne *p,SDL_Rect *b);

#endif