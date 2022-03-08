#ifndef MUSIC_H
#define MUSIC_H
#include <SDL/SDL_mixer.h>
void initMusic(Mix_Chunk *music, int times);
void initaudio();
void FreeMusic(Mix_Chunk *music);
#endif