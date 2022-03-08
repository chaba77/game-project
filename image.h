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
typedef struct Image Image;

void initButton(Image *A, int x, int y);
void initBackground(Image *backg,int w, int h, char filename[]);
void liberer(Image A);
void afficher(Image p,SDL_Surface *screen);
void initImage(Image *StartBackg, int x , int y, char filename[]);
void Delay(int time);
#endif