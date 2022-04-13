#include <stdio.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "image.h"
#include "Functions.h"
#include "music.h"
#include "text.h"
#include "background.h"
#include "perso.h"

int main(int argc, char** argv){

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();

    SDL_Surface *screen;
    SDL_Surface *masklvl1;
    SDL_Surface *masklvl2;
    SDL_Surface *masklvl3;
    masklvl1 = IMG_Load("level 1 background mask.png");
    masklvl2 = IMG_Load("level 2 background mask.png");
    masklvl3 = IMG_Load("full back 3 with door mask .png");
    //otthers 
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
    Personne personage;
    SDL_Event event;
    Text tv1,tv2,tv3;
    Text tv1_s,tv2_s,tv3_s;
    // camera 
    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.w=SCREEN_W;
    camera.y=SCREEN_H;
    // popping the image gonna be like 
    // 
    // --
    char s_tv1[5] = "Play";
    char s_tv2[8] = "Options";
    char s_tv3[5] = "Quit";
    atexit(SDL_Quit);

    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_SRCALPHA);
    if (!screen)
    {
        return 1;
    }
    initImage(&buttonv1, 590, 390, "button normal.png");
    initBackground(&Backg1,0,0, "back1.png");
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
    initImage(&plus_sound, 900,250,"+.png");
    initImage(&minus_sound, 900,350,"-.png");
    // sound 
    initImage(&musicon, 900, 500, "music on.png");
    initImage(&musicoff, 900, 500, "music off.png");
    initImage(&soundfxon, 900, 600, "sound fx on.png");
    initImage(&soundfxoff, 900, 600, "sound fx off.png");
    //init backgrounds
    Background thirdBackg,thirdBackgdoors1,thirdBackgdoors2,thirdBackgdoors3;
    Background StartBackg,peageopen1,peageopen2;
    Background secondBackg;
    StartBackg.pos2.x = 0;
    StartBackg.pos2.y = 0;
    thirdBackg.pos2.x = 0;
    thirdBackg.pos2.y = 0;
    secondBackg.pos2.x = 0;
    secondBackg.pos2.y = 0;
    initBack(&StartBackg, "level 1 background 3.png");
    initBack(&peageopen1, "level 1 background 1.png");
    initBack(&peageopen2, "level 1 background 2.png");
    initBack(&thirdBackg,"full back 3 with door 1.png");
    initBack(&thirdBackgdoors1, "full back 3 with door 2.png");
    initBack(&thirdBackgdoors2, "full back 3 with door 3.png");
    initBack(&thirdBackgdoors3, "full back 3 with door 4.png");
    initBack(&secondBackg,"level 2 background x.png");
    // starting audio 
    initaudio();
    //loading my song 
    Mix_Chunk *backgroundmusic = Mix_LoadWAV("song.wav");
    Mix_Chunk *click = Mix_LoadWAV("click.wav");
    // putting the war song on repeat 
    initMusic(backgroundmusic, -1);
    Image SettingsBackg;
    initImage(&SettingsBackg, 0,0, "back1_settings.png");
    int numback =1;
    int answer = 1;
    int numsettings =0;
    int plus_count_music =0;
    int count_music =0;
    int soundfx =1;
    int music=1;
    int mouseover=0;
    int mousedown = 0;
    char file_num[5];
    int pos_x = 100 ,pos_y =567,dx=0,dy=0;
    char fn[3];
    int ingameBackg = 1;
    int delay = 0;
    //StartBackg.img= IMG_Load("startbackground.png");
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
            switch(ingameBackg){
                case 1:
                    afficherBack(StartBackg, screen);
                    pos_x += dx;
                    pos_y += dy;
                    dx =0;
                    initialiserperso(&personage, pos_x, pos_y);
                    afficher_perso(screen, personage);
                    printf("%d\n", StartBackg.pos2.y);
                    if((pos_x > 675 && pos_x < 775) && StartBackg.pos2.x <= 11997 - 1450)
                        scrolling(&StartBackg.pos2,1,5);
                    else 
                        dx += 5;
                    if (collisionparfaite(masklvl1,&StartBackg.pos2,personage, 0, 0, 0) != 10)
                    {
                        pos_x = 100;
                        pos_y =567;
                        dx=0;
                        dy=0;
                        StartBackg.pos2.x = 0;
                        StartBackg.pos2.y = 0;
                    }
                    else if (collisionparfaite(masklvl1, &StartBackg.pos2,personage,255,0,0) !=10){
                        // here goes the Question 
                        if(answer == 1){
                            peageopen1.pos2.x = StartBackg.pos2.x;
                            peageopen1.pos2.y = StartBackg.pos2.y;
                            peageopen2.pos2.x = StartBackg.pos2.x;
                            peageopen2.pos2.y = StartBackg.pos2.y;
                            // TODO = just slow the process !!!!!!!!
                            //SDL_Delay(1000);
                            afficherBack(peageopen1, screen);
                            SDL_Delay(1000);
                            afficherBack(peageopen2, screen);
                            //SDL_Delay(1000);
                            StartBackg = peageopen2;
                            masklvl1 = IMG_Load("level 1 background mask open peage.png");
                        }
                    }
                    dy =0;
                    break;
                case 2:
                    afficherBack(secondBackg, screen);
                    pos_x += dx;
                    pos_y += dy;
                    initialiserperso(&personage, pos_x, pos_y);
                    afficher_perso(screen, personage);
                    dx =0;
                    dy =0;
                    if((pos_x > 675 && pos_x < 775) && secondBackg.pos2.x <= 11997 - 1450)
                        scrolling(&secondBackg.pos2,1,5);
                    else 
                        dx += 5;
                    if (collisionparfaite(masklvl2,&secondBackg.pos2,personage, 0, 0, 0) != 10)
                    {
                        pos_x = 100;
                        pos_y =567;
                        dx=0;
                        dy=0;
                        secondBackg.pos2.x = 0;
                        secondBackg.pos2.y = 0;
                    }
                    break;

                case 3:
                    afficherBack(thirdBackg, screen);
                    pos_x += dx;
                    pos_y += dy;
                    initialiserperso(&personage, pos_x, pos_y);
                    afficher_perso(screen, personage);
                    dx =0;
                    dy =0;
                    if (collisionparfaite(masklvl3, &thirdBackg.pos2, personage, 0, 0, 0) != 10)
                    {
                        pos_x = 100;
                        pos_y =567;
                        dx=0;
                        dy=0;
                        thirdBackg.pos2.x = 0;
                        thirdBackg.pos2.y = 0;


                    }
                    //collision(masklvl3,&personage,&thirdBackg.pos2);
                    int i =collisionparfaite(masklvl3,&thirdBackg.pos2,personage,0,85,255);
                    switch (i)
                    {
                        case 0 :
                                pos_x=pos_x+21;
                                break;
                        case 1 :pos_y=pos_y+21;
                                 break;
                        case 2 :pos_x=pos_x-21;
                                break;
                        case 3 :pos_x=pos_x+21;
                                break;
                        case 4 :pos_x=pos_x+21;
                                break;
                        case 5 :pos_y=pos_y-21; 
                                break;
                        case 6 :pos_x=pos_x-21; 
                                break;
                        case 7 :pos_x=pos_x-21;
                                break;
                    }
                    if (pos_x+thirdBackg.pos2.x >= 14000)
                    {
                        printf("aaaaahere here aa");
                        thirdBackgdoors1.pos2 = thirdBackg.pos2;
                        thirdBackgdoors2.pos2 = thirdBackg.pos2;
                        thirdBackgdoors3.pos2 = thirdBackg.pos2;
                        animerBackground((Background[]){thirdBackgdoors1,thirdBackgdoors2,thirdBackgdoors3},3,screen);
                        thirdBackg = thirdBackgdoors3;

                    }
            }
            
            
            
            
            
            
            
            
            

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
                ingameBackg = -1;
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
                else if (event.key.keysym.sym == SDLK_n)
                {
                    SDL_Delay(100);
                    if(ingameBackg<3)
                        ingameBackg++;
                    pos_x = 100;
                    pos_y = 567;

                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    SDL_Delay(100);
                    dy -= 21;
                    if(pos_y <= 100)
                        scrolling(&StartBackg.pos2,3,30);
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    SDL_Delay(100);
                    dy += 21;
                    if(pos_y >= 700)
                        scrolling(&StartBackg.pos2,4,30);
                }
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    SDL_Delay(100);
                    printf("\n this is --%d", pos_x);
                    if(pos_x >= 750)
                        scrolling(&thirdBackg.pos2,1,21);
                    else 
                        dx += 21;


                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    SDL_Delay(100);
                    if(pos_x <= 150)
                        scrolling(&thirdBackg.pos2,2,21);
                    else
                        dx -= 21;

                }

                else if (event.key.keysym.sym == SDLK_p)
                {
                    SDL_Delay(100);
                    scrolling(&StartBackg.pos2,3,30);
                    dy += 30;
                }
                else if (event.key.keysym.sym == SDLK_m)
                {
                    SDL_Delay(100);
                    scrolling(&StartBackg.pos2,4,30);
                    dy -= 30;
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
