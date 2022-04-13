#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "image.h"
#include "text.h"
#include <SDL/SDL.h>

void ShowOnScreen(Image images[],int length, SDL_Surface *screen);
void DisplayOnScreen(Text textes[], int length, SDL_Surface *screen);
#endif