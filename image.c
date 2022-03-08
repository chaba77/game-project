#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "image.h"
void initImage(Image *A, int x, int y, char filename[])
{
	A->img=IMG_Load(filename);
	if(A->img==NULL){
	return;
}
	A->pos1.x=x;
	A->pos1.y=y;
	A->pos1.w=A->img->w;
	A->pos1.h=A->img->h;
	
	A->pos2.x=0;
	A->pos2.y=0;
	A->pos2.w=A->img->w;
	A->pos2.h=A->img->h;
}
void initBackground(Image *Backg,int w,int h, char filename[])
{
Backg->img= IMG_Load(filename);
	if(Backg->img == NULL){
		printf("Unable to load : %s\n",SDL_GetError());
return;
}
Backg->pos1.x=0;
Backg->pos1.y=0;
Backg->pos2.x=0;
Backg->pos2.y=0;
Backg->pos2.w=(w);
Backg->pos2.h=h;
}
void liberer(Image A)
{
	SDL_FreeSurface(A.img);
}
void afficher(Image p,SDL_Surface *screen)
{
SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);
}
void Delay(int time){
	int start = SDL_GetTicks();
	int run = 1;
	while(run){
		if ((SDL_GetTicks() - start) == time)
			run = 0;

	} 
}