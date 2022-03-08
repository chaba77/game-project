#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "music.h"
void initaudio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}
void initMusic(Mix_Chunk* music, int times)
{
	Mix_PlayChannel(-1, music, times);
}