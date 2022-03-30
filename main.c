#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "Functions.h"
#include "music.h"
#include "text.h"
int main(int argc, char** argv){

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();

    SDL_Surface *screen;
    int done = 0;
    Image buttonv1,buttonv2, buttonv3;
    Image buttonv1_s,buttonv2_s, buttonv3_s;
    Image buttonv1_a,buttonv2_a, buttonv3_a;
    Image soundBar1, plus_sound, minus_sound;
    Image soundBar2,soundBar3,soundBar4,soundBar5,soundBar6;
    Image soundBar;
    Image no_music, yes_music;
    Image Backg1;
    Image musicon,musicoff,soundfxoff,soundfxon;
    SDL_Event event;
    Text tv1,tv2,tv3;
    Text tv1_s,tv2_s,tv3_s;
    char s_tv1[5] = "Play";
    char s_tv2[8] = "Options";
    char s_tv3[5] = "Quit";
    atexit(SDL_Quit);

    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_SRCALPHA);
    if (!screen)
    {
        return 1;
    }
    initBackground(&Backg1,SCREEN_W,SCREEN_H, "back1.png");
    initImage(&buttonv1, 590, 390, "button normal.png");
    initImage(&buttonv2, 590, 490, "button normal.png");
    initImage(&buttonv3, 590, 590, "button normal.png");
    initImage(&buttonv1_s, 590, 390, "button selectione.png");
    initImage(&buttonv2_s, 590, 490, "button selectione.png");
    initImage(&buttonv3_s, 590, 590, "button selectione.png");
    initImage(&buttonv1_a, 590, 390, "bouton play appuier.png");
    initImage(&buttonv2_a, 590, 490, "bouton play appuier.png");
    initImage(&buttonv3_a, 590, 590, "bouton play appuier.png");
    initText(&tv1, 680, 430, s_tv1, 0,0, 0);
    initText(&tv2, 680, 530, s_tv2, 0,0, 0);
    initText(&tv3, 680, 630, s_tv3, 0,0, 0);
    initText(&tv1_s, 680, 430, s_tv1, 255, 255, 255);
    initText(&tv2_s, 680, 530, s_tv2, 255, 255, 255);
    initText(&tv3_s, 680, 630, s_tv3, 255, 255, 255);
    // SETTINGS 
    initImage(&soundBar1, 500,200, "6.png");            
    initImage(&soundBar2, 500,200, "5.png");            
    initImage(&soundBar3, 500,200, "4.png");            
    initImage(&soundBar4, 500,200, "3.png");            
    initImage(&soundBar5, 500,200, "2.png");            
    initImage(&soundBar6, 500,200, "1.png");            
    initImage(&plus_sound, 900,250,"+.png");
    initImage(&minus_sound, 900,350,"-.png");
    // sound 
    initImage(&musicon, 900, 500, "music on.png");
    initImage(&musicoff, 900, 500, "music off.png");
    initImage(&soundfxon, 900, 600, "sound fx on.png");
    initImage(&soundfxoff, 900, 600, "sound fx off.png");
    // starting audio 
    initaudio();
    //loading my song 
    Mix_Chunk *backgroundmusic = Mix_LoadWAV("song.wav");
    Mix_Chunk *click = Mix_LoadWAV("click.wav");
    // putting the war song on repeat 
    initMusic(backgroundmusic, -1);
    Image StartBackg;
    initImage(&StartBackg, 0,0,"startbackground.png");
    Image SettingsBackg;
    initImage(&SettingsBackg, 0,0, "back1_settings.png");
    int numback =1;
    int clicked=0;
    int numsettings =0;
    int plus_count_music =0;
    int count_music =0;
    int soundfx =1;
    int music=1;
    int mouseover=0;
    int mousedown = 0;
    char file_num[5];
    while (!done){

        SDL_Flip(screen);

        switch(numback){
        case 1:
            ShowOnScreen((Image[]){Backg1, buttonv1, buttonv2, buttonv3},4,screen);
            DisplayOnScreen((Text[]){tv1,tv2,tv3},3,screen);
            switch(mouseover){
                case 1:
                    ShowOnScreen((Image[]){Backg1, buttonv1_s, buttonv2, buttonv3},4,screen);
                    DisplayOnScreen((Text[]){tv1_s,tv2,tv3},3, screen);
                    mouseover = -1;
                    break;
                case 2:
                    ShowOnScreen((Image[]){Backg1, buttonv1, buttonv2_s, buttonv3},4,screen);
                    DisplayOnScreen((Text[]){tv1,tv2_s,tv3},3, screen);
                    mouseover = -1;
                    break;
                    break;
                case 3:
                    ShowOnScreen((Image[]){Backg1, buttonv1, buttonv2, buttonv3_s},4,screen);
                    DisplayOnScreen((Text[]){tv1,tv2,tv3_s},3, screen);
                    mouseover = -1;
                    break;

            }
            switch(mousedown){
                case 1:
                    ShowOnScreen((Image[]){Backg1, buttonv1_a, buttonv2, buttonv3},4,screen);
                    DisplayOnScreen((Text[]){tv1,tv2,tv3},3, screen);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    numback = 2;
                    mousedown = -1;
                    break;
                    break;
                case 2:
                    ShowOnScreen((Image[]){Backg1, buttonv1, buttonv2_a, buttonv3},4,screen);
                    DisplayOnScreen((Text[]){tv1,tv2,tv3},3, screen);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    numback = 3;
                    mousedown = -1;
                    break;
                case 3:
                    ShowOnScreen((Image[]){Backg1, buttonv1, buttonv2, buttonv3_a},4,screen);
                    DisplayOnScreen((Text[]){tv1,tv2,tv3},3, screen);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    done = 1;
                    mousedown = -1;
                    break;

                


            }
            break;
        case 2:
            ShowOnScreen((Image[]){StartBackg},1,screen);
            break;
        case 3:
            sprintf(file_num, "%d", (6-count_music*-1));
            strcat(file_num, ".png");
            initImage(&soundBar,500,200,file_num);
            ShowOnScreen((Image[]){SettingsBackg,soundBar,plus_sound,minus_sound},4,screen);
            if(music)
                afficher(musicon, screen);
            else
                afficher(musicoff, screen);
            if(soundfx)
                afficher(soundfxon, screen);
            else
                afficher(soundfxoff, screen);
            Mix_VolumeChunk(backgroundmusic, MIX_MAX_VOLUME - ((MIX_MAX_VOLUME * 0.2) * (count_music*-1)));
            break;
            

        }

        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                done = 1;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE)
                    done =1;
                else if (event.key.keysym.sym == SDLK_a){
                    numback = 1;
                }
                else if (event.key.keysym.sym == SDLK_F5)
                {
                    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);

                }
                else if (event.key.keysym.sym == SDLK_F6)
                {
                    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_SRCALPHA);
                }
                break;
            case SDL_MOUSEMOTION:
                if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 390 && event.motion.y <= 390 + 124)
                {
                    mouseover = 1;
                }
                else if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 490 && event.motion.y <= 490 + 124)
                {
                    mouseover = 2;
                }
                else if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 590 && event.motion.y <= 590 + 124 )
                {
                    mouseover = 3;
                }
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if(soundfx){
                    initMusic(click, 0);
                }
                if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 390 && event.motion.y <= 390 + 124 )
                {
                    mousedown = 1;
                }
                else if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 490 && event.motion.y <= 490 + 124 )
                {
                    mousedown = 2;
                }
                else if (event.motion.x >= 590 && event.motion.x <= 590 + 300 &&
                    event.motion.y >= 590 && event.motion.y <= 590 + 124)
                {
                    mousedown = 3;
                }
                else if (event.motion.x >= 900 && event.motion.x <= 900 + 200 &&
                    event.motion.y >= 250 && event.motion.y <= 250 + 82 )
                {
                    SDL_Delay(100);
                    if(count_music == 0)
                        count_music = 0;
                    else
                        count_music++;
                }
                else if (event.motion.x >= 900 && event.motion.x <= 900 + 200 &&
                    event.motion.y >= 350 && event.motion.y <= 350 + 82 )
                {
                    SDL_Delay(100);
                    if(count_music == -5)
                        count_music = -5;
                    else
                        count_music--;

                }
                else if (event.motion.x >= 900 && event.motion.x <= 900 + 200 &&
                    event.motion.y >= 500 && event.motion.y <= 500 + 82 )
                {
                    if (music){
                        music = 0;
                        SDL_PauseAudio(1);
                    }
                    else{
                        music = 1;
                        SDL_PauseAudio(0);

                    }

                }
                else if (event.motion.x >= 900 && event.motion.x <= 900 + 200 &&
                    event.motion.y >= 600 && event.motion.y <= 600 + 82 )
                {
                    if (soundfx)
                        soundfx = 0;
                    else
                        soundfx = 1;
                }
                break;
            }
            
    }
    liberer(buttonv1);
    liberer(buttonv2);
    liberer(buttonv3);
    liberer(buttonv1_s);
    liberer(buttonv2_s);
    liberer(buttonv3_s);
    liberer(Backg1);
    freeText(tv1);
    freeText(tv2);
    freeText(tv3);
    freeText(tv1_s);
    freeText(tv2_s);
    freeText(tv3_s);
    Mix_CloseAudio();
    TTF_Quit();
}