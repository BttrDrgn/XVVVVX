#pragma once

//#include <SDL_mixer.h>
#include <xtl.h>
#include <dmusici.h>

class MusicTrack
{
public:
	MusicTrack(const char* fileName);
	MusicTrack(SDL_RWops *rw);
	//Mix_Music *m_music;
	bool m_isValid;
};

class SoundTrack
{
public:
	SoundTrack(const char* fileName);
	//Mix_Chunk *sound;
};

class SoundSystem
{
public:
	SoundSystem();
	void playMusic(MusicTrack* music);
};

//help from http://www.xbdev.net/tuts/subpages/prt9/index.php
 class CSound
{
protected:
      IDirectMusicSegment8* m_pSoundSegment;

public:

      void Create(int t, int p);
      void playsound();
      void Release(); 
	  CSound();

protected:
      static IDirectMusicLoader8* m_pLoader;
      static IDirectMusicPerformance8* m_pPerformance;
	  void LoadSound(char* filename);
      void SetupSound();

};