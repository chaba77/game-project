#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdbool.h>



typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}Personne;

void initialiserperso(Personne *perso, int x , int y);
void afficher_perso(SDL_Surface *screen,Personne perso);








#endif

