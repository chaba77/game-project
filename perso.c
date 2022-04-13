#include "perso.h"

void initialiserperso(Personne *perso, int x,int y)
{	
	perso->image_p=IMG_Load("perso.png");
	perso->pos_perso.x=x;
	perso->pos_perso.y=y;
	perso->pos_perso.w=40;
	perso->pos_perso.h=100;
}

void afficher_perso(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}
