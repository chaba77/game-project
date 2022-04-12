#ifndef EN_H_INCLUDED
#define EN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>
#define SCREEN_W 1200 
#define SCREEN_H 600 


typedef struct Image Image;


typedef struct
{
SDL_Surface *perso; 
SDL_Rect perso_pos ;
}personnage ;

typedef struct {
	SDL_Surface *ennemie ;  
	SDL_Rect pos_ennemie; 
	SDL_Rect anim_ennemie[20]; 
	int fennemie;
	int coll;	
	int dir;
	
	
	

}Ennemie;
struct Image{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface * img;
};
typedef struct Image Image;

void initBackground(Image *backg);
void liberer(Image A);
void afficher(Image p,SDL_Surface *screen);
void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void deplacer(Ennemie *e);
int collision_ennemie(personnage *p, Ennemie *e);
void tab_anim(SDL_Rect* tab,Ennemie *e);
void initentity(Ennemie *c);
void afficherentity(Ennemie e , SDL_Surface *screen);
void init_perso(personnage *p);
void afficher_perso(personnage p , SDL_Surface *screen);
void init_win(personnage *w);
void afficher_win(personnage w ,SDL_Surface *screen);
void init_lost(personnage *z);
void afficher_lost(personnage z ,SDL_Surface *screen);

#endif
