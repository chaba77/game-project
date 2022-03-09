#ifndef Image_H
#define Image_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define SCREEN_W 1450
#define SCREEN_H 900
struct Image{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface * img;
};
typedef struct Image Background;
typedef struct Image Personnage;


void initBack(Background *b);
void afficherBack(Background b, SDL_Surface * screen);
void animerBackground(Background *e);
int collisionPP(Personnage p, SDL_Surface * Masque);
void scrolling(SDL_Rect *b,  int direction, int pasAvancement);

#endif