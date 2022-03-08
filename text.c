#include <SDL/SDL.h>
#include <string.h>
#include "text.h"
#include <SDL/SDL_image.h>

void initText(Text *A, int x, int y, char texte[], int r, int g, int b)
{
    A->position.x=x;
    A->position.y=y;
    A->textColor.r=r;
    A->textColor.g=g;
    A->textColor.b=b; 
    strcpy(A->texte,texte);
    A->font = TTF_OpenFont("war.ttf", 40);
}
void freeText(Text A){
    SDL_FreeSurface(A.surfaceTexte);
}
void displayText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, t.texte, t.textColor);
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}