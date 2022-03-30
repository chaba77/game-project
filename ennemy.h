#ifndef fonn_H_INCLUDED
#define fonn_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef enum STATE STATE;
enum STATE{WAITING ,FOLLOWING, ATTACKING};

typedef struct 
{
	SDL_Surface *image[2][4]; 
	int speed;
	int dir;
	int attack;
	SDL_Rect pos; // Ennemi Position
}ennemi;


void initEnnemi();
void afficherEnnemi(ennemi e, SDL_Surface *screen);
void animerEnnemi(ennemi *e);
void deplacerEnnemi(ennemi *e);
int collisionBb(Personne p, ennemi e);
void deplacerIA(ennemi *e);
void libererennemi(ennemi e);

#endif
