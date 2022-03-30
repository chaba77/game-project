#include "image.h"
#include "text.h"
#include <stdio.h>
#include <SDL/SDL.h>

void ShowOnScreen(Image images[],int length, SDL_Surface *screen)
{
    for (int i = 0; i < length; i++)
    {
        afficher(images[i], screen);
    }
}

void DisplayOnScreen(Text textes[], int length, SDL_Surface *screen){
    for(int i = 0; i<length; i++)
        displayText(textes[i],screen);

}
