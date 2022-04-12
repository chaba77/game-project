#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "en.h"
void initImage(Image *A, int x, int y, char filename[])
{
	A->img=IMG_Load("cgpng.png");
	if(A->img==NULL){
	return;
}
	A->pos1.x=0; 
	A->pos1.y=185;
	A->pos1.w=A->img->w; 
	A->pos1.h=A->img->h;
	
	A->pos2.x=0; 
	A->pos2.y=0;
	A->pos2.w=A->img->w;
	A->pos2.h=A->img->h;
}


void initBackground(Image *Backg)
{
Backg ->img=IMG_Load("bc.jpg");

	if(Backg->img==NULL){
		printf("Unable to load bmp : %s\n",SDL_GetError());
return;
}

Backg->pos1.x=0; 
Backg->pos1.y=0;
Backg->pos2.x=0;
Backg->pos2.y=0;
Backg->pos2.w=(SCREEN_W);
Backg->pos2.h=SCREEN_H;
}
void liberer(Image A)
{
	SDL_FreeSurface(A.img);
}
void afficher(Image p,SDL_Surface *screen)
{
SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1); 
}

int 
frame=12,
ennemie_h=200,
ennemie_w=200,
ennemie_y=100,
ennemie_x=200;

void tab_anim(SDL_Rect* tab,Ennemie *e)
{		
	for (int i=0;i<frame;i++)
	{
	tab[i].h=ennemie_h;
	tab[i].w=ennemie_w;
	tab[i].x =i*ennemie_x;
	tab[i].y =0;
        }  
}




void init_perso(personnage *p)
{
    p->perso= IMG_Load("cgpng.png");
    p->perso_pos.x = 50;
    p->perso_pos.y = 350;
    p->perso_pos.h = p->perso->h;
    p->perso_pos.w = p->perso->w;  
}

void afficher_perso(personnage p ,SDL_Surface *screen)
{
   SDL_BlitSurface(p.perso,NULL, screen, &p.perso_pos);

}


void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("spr.png");

    e->pos_ennemie.x = 850;
    e->pos_ennemie.y = 318;
    tab_anim(e->anim_ennemie,e);
    e->pos_ennemie.h = e->ennemie->h;
    e->pos_ennemie.w = e->ennemie->w;
    e->fennemie=0;
    e->coll=0;
    e->dir=0;  
    
    
    
}



void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.fennemie], screen, &e.pos_ennemie);
   //SDL_BlitSurface(e.ennemie,NULL, screen, &e.pos_ennemie);
  
  

}
void initentity(Ennemie *c)
{

    c->ennemie = IMG_Load("ak.png");

    c->pos_ennemie.x = 400;
    c->pos_ennemie.y = 380;
    c->pos_ennemie.h = c->ennemie->h;
    c->pos_ennemie.w = c->ennemie->w;
    c->fennemie=0;
    c->coll=0;
    c->dir=0; 
}
void afficherentity(Ennemie c , SDL_Surface *screen)
{
   
   //SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
   SDL_BlitSurface(c.ennemie,NULL, screen, &c.pos_ennemie);
}

void animerEnnemi(Ennemie *e)
{   if (e->fennemie >=0 && e->fennemie <(frame)) 
 e->fennemie++;
    if ( e->fennemie ==(frame)) 
       e->fennemie=0;
}

    
   

int collision_ennemie(personnage *p, Ennemie *e)
{
	

if ((p->perso_pos.x + p->perso_pos. w< e->pos_ennemie. x) || (p->perso_pos.x> e->pos_ennemie. x + e->pos_ennemie. w) ||
(p->perso_pos.y + p->perso_pos.h< e->pos_ennemie. y) || (p->perso_pos.y> e->pos_ennemie. y + e->pos_ennemie. h ))
return 0;
else 
return 1;
 
}
void deplacer(Ennemie *e)
{	

if(e->pos_ennemie.x>= 890)
{e->dir=1;}
if(e->pos_ennemie.x<=740)
{e->dir =0;}
if(e->dir==1)
{e->pos_ennemie.x-=3;}
if(e->dir==0)
{e->pos_ennemie.x+=3;}
}

void init_win(personnage *w)
{
    w->perso= IMG_Load("energie 2.png");
    w->perso_pos.x = 120;
    w->perso_pos.y = 20;
    w->perso_pos.h = w->perso->h;
    w->perso_pos.w = w->perso->w;  
}

void afficher_win(personnage w ,SDL_Surface *screen)
{
   SDL_BlitSurface(w.perso,NULL, screen, &w.perso_pos);

}
void init_lost(personnage *z)

{
    z->perso= IMG_Load("lst.png");
    z->perso_pos.x = 220;
    z->perso_pos.y = 220;
    z->perso_pos.h = z->perso->h;
    z->perso_pos.w = z->perso->w;  
}

void afficher_lost(personnage z ,SDL_Surface *screen)
{
   SDL_BlitSurface(z.perso,NULL, screen, &z.perso_pos);
}
