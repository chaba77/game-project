#include "background.h"
#include "image.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

void initBack(Background *b, char filename[])
{

    b->img= IMG_Load(filename);
    	if(b->img == NULL){
    		printf("Unable to load : %s\n",SDL_GetError());
    return;
    }
    b->pos1.x=0;
    b->pos1.y=0;
    b->pos1.w=SCREEN_W;
    b->pos1.h=SCREEN_H;

    //b->pos2.x=0;
    //b->pos2.y=0;
    b->pos2.w=SCREEN_W;
    b->pos2.h=SCREEN_H;
}
void afficherBack(Background b, SDL_Surface *screen)
{
    SDL_BlitSurface(b.img,&b.pos2,screen,&b.pos1);
}

void scrolling(SDL_Rect *b, int direction, int pasAvancement)
{
    // direction 1 is right
    if (direction == 1)
        b->x += pasAvancement;
    // direction 2 is left
    else if (direction == 2)
        b->x -= pasAvancement;
    // direction 3 is up 
    else if(direction == 3)
        b->y -= pasAvancement;
        
    // direction 4 si down
    else if(direction == 4)
        b->y += pasAvancement; 

}

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{
        SDL_Color color;
        Uint32 col=0;
        char* pPosition=(char* ) pSurface->pixels;
        pPosition+= (pSurface->pitch * y);
        pPosition+= (pSurface->format->BytesPerPixel *x);
        memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
        SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
        return (color);
}
int  collisionparfaite(SDL_Surface *psurface,SDL_Rect *back,Personne p, int r, int g , int b)
{
        int tabx[7],taby[7],i;
        SDL_Color color1,color;
        color1.r = r;
        color1.g = g;
        color1.b = b;
        p.pos_perso.x += back->x;
        tabx[0]=p.pos_perso.x+5;   
        tabx[1]=(p.pos_perso.x)+((p.pos_perso.w)/2);
        tabx[2]=(p.pos_perso.x+p.pos_perso.w-5);
        tabx[3]=p.pos_perso.x;
        tabx[4]=p.pos_perso.x;
        tabx[5]=(p.pos_perso.x)+((p.pos_perso.w)/2);
        tabx[6]=(p.pos_perso.x+p.pos_perso.w);
        tabx[7]=(p.pos_perso.x+p.pos_perso.w);
        taby[0]=p.pos_perso.y;
        taby[1]=p.pos_perso.y;
        taby[2]=p.pos_perso.y;
        taby[3]=(p.pos_perso.y)+((p.pos_perso.h)/2);
        taby[4]=(p.pos_perso.y+p.pos_perso.h-5);
        taby[5]=(p.pos_perso.y+p.pos_perso.h);
        taby[6]=(p.pos_perso.y+p.pos_perso.h-5);
        taby[7]=(p.pos_perso.y)+((p.pos_perso.h)/2);
  // 0 : fou9 al  isar ama mouch el coin bethabt 9balo chwaya (5pixels)
  // 1 : fou9 fel west 
  // 2 : fou9 al imin ama mouch el coin bethabt 9balo chwaya (5pixels)
  // 3 : al isar fel west 
  // 4 : louta al isar ama mouch el coin bethabt 9balo chwaya (5pixels)
  // 5 : louta fel west 
  // 6 : louta al imin ama mouch el coin bethabt 9balo chwaya (5pixels)
  // 7 : imin fel west

        for(i=0;i<8;i++)
        {
        color=getpixel(psurface,tabx[i],taby[i]);
        if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
        {
                return i;

        }
        }
        return 10;

}
void animerBackground(Background backgrounds[],int length, SDL_Surface *screen)
{
    int start = SDL_GetTicks();
    for (int i = 0; i < length; i++)
    {
        if(SDL_GetTicks()-start == 1000)
            afficherBack(backgrounds[i], screen);
    }
}


































































































































































































