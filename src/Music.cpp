#include <SDL.h>
#include <stdio.h>
#include "Music.h"
#include "BinaryBlob.h"

MusicClass::MusicClass()
{
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\jump.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\jump2.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\hurt.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\souleyeminijingle.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\coin.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\save.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crumble.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\vanish.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\blip.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\preteleport.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\teleport.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew1.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew2.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew3.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew4.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew5.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crew6.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\terminal.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\gamesaved.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crashing.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\blip2.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\countdown.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\go.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\crash.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\combine.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\newrecord.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\trophy.wav" ));
	soundTracks.push_back(SoundTrack( "D:\\data\\sounds\\rescue.wav" ));
#ifdef VVV_COMPILEMUSIC
	binaryBlob musicWriteBlob;
	musicWriteBlob.AddFileToBinaryBlob("data/music/0levelcomplete.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/1pushingonwards.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/2positiveforce.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/3potentialforanything.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/4passionforexploring.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/5intermission.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/6presentingvvvvvv.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/7gamecomplete.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/8predestinedfate.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/9positiveforcereversed.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/10popularpotpourri.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/11pipedream.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/12pressurecooker.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/13pacedenergy.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/14piercingthesky.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/predestinedfatefinallevel.ogg");

	musicWriteBlob.writeBinaryBlob("D:\\data\\BinaryMusic.vvv");
#endif

	binaryBlob musicReadBlob;
	if (!musicReadBlob.unPackBinary("mmmmmm.vvv"))
	{
		mmmmmm = false;
		usingmmmmmm=false;
		bool ohCrap = musicReadBlob.unPackBinary("D:\\data\\vvvvvvmusic.vvv");
		//SDL_assert(ohCrap && "Music not found!");
	}
	else
	{
		mmmmmm = true;
		usingmmmmmm = true;
		int index = musicReadBlob.getIndex("D:\\data\\music\\0levelcomplete.ogg");
		SDL_RWops *rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\1pushingonwards.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\2positiveforce.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\3potentialforanything.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\4passionforexploring.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\5intermission.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\6presentingvvvvvv.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\7gamecomplete.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\8predestinedfate.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\9positiveforcereversed.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\10popularpotpourri.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\11pipedream.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\12pressurecooker.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\13pacedenergy.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\14piercingthesky.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		index = musicReadBlob.getIndex("D:\\data\\music\\predestinedfatefinallevel.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(MusicTrack( rw ));

		bool ohCrap = musicReadBlob.unPackBinary("vvvvvvmusic.vvv");
		//SDL_assert(ohCrap && "Music not found!");
	}

	int index = musicReadBlob.getIndex("D:\\data\\music\\0levelcomplete.ogg");
	SDL_RWops *rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\1pushingonwards.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\2positiveforce.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\3potentialforanything.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\4passionforexploring.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\5intermission.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\6presentingvvvvvv.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\7gamecomplete.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\8predestinedfate.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\9positiveforcereversed.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\10popularpotpourri.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\11pipedream.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\12pressurecooker.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\13pacedenergy.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\14piercingthesky.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	index = musicReadBlob.getIndex("D:\\data\\music\\predestinedfatefinallevel.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(MusicTrack( rw ));

	safeToProcessMusic= false;
	m_doFadeInVol = false;
	musicVolume = 128;
	FadeVolAmountPerFrame = 0;

	custompd = false;

	currentsong = 0;
	musicfade = 0;
	musicfadein = 0;
	nicechange = 0;
	nicefade = 0;
	resumesong = 0;
	volume = 0.0f;
}

void MusicClass::play(int t)
{
  t = (t % 16);

	if(mmmmmm)
	{
		if(!usingmmmmmm)
		{
			t += 16;
		}
	}
	safeToProcessMusic = true;
	//Mix_VolumeMusic(128);
	if (currentsong !=t)
	{
		if (currentsong != -1)
		{
			// Stop the old song first
			// musicchannel.stop();
			if (currentsong != 0)
			{
				// musicchannel.removeEventListener(Event.SOUND_COMPLETE, loopmusic);
			}
		}
		if (t != -1)
		{
			// musicfade = 0;
			currentsong = t;
			if (currentsong == 0 || currentsong == 7)
			{
				// Level Complete theme, no fade in or repeat
				// musicchannel = musicchan[currentsong].play(0);
				// musicchannel.soundTransform = new SoundTransform(1.0);
				/*
				if(Mix_FadeInMusic(musicTracks[t].m_music, 0, 0)==-1)
				{
					printf("Mix_PlayMusic: %s\n", Mix_GetError());
				}
				*/
			}
			else
			{
				// musicfadein = 90;
				// musicchannel = musicchan[currentsong].play(0);
				// musicchannel.soundTransform = new SoundTransform(0);
				// musicchannel.addEventListener(Event.SOUND_COMPLETE, loopmusic);
				/*
				if(Mix_FadeInMusic(musicTracks[t].m_music, -1, 3000)==-1)
				{
					printf("Mix_FadeInMusic: %s\n", Mix_GetError());
				}
				*/
			}
		}
		else
		{
			currentsong = -1;
		}
	}
}

void MusicClass::loopmusic()
{
	//musicchannel.removeEventListener(Event.SOUND_COMPLETE, loopmusic);
	//if(currentsong>-1){
	//	musicchannel = musicchan[currentsong].play();
	//	musicchannel.addEventListener(Event.SOUND_COMPLETE, loopmusic);
	//}
}

void MusicClass::stopmusic()
{
	// musicchannel.removeEventListener(Event.SOUND_COMPLETE, stopmusic);
	// musicchannel.stop();
	//Mix_HaltMusic();
	currentsong = -1;
}

void MusicClass::haltdasmusik()
{
	// musicchannel.removeEventListener(Event.SOUND_COMPLETE, stopmusic);
	// musicchannel.stop();
	// resumesong = currentsong;
	//Mix_HaltMusic();
	currentsong = -1;
}

void MusicClass::silencedasmusik()
{
	//if(currentsong>-1){
	//	musicchannel.soundTransform = new SoundTransform(0);
	//}
	//Mix_VolumeMusic(0) ;
	musicVolume = 0;
}

void MusicClass::fadeMusicVolumeIn(int ms)
{
	m_doFadeInVol = true;
	//FadeVolAmountPerFrame =  MIX_MAX_VOLUME / (ms / 33);
	FadeVolAmountPerFrame = NULL;
}

void MusicClass::fadeout()
{
	//if(currentsong>-1){
	//	if (musicfade == 0) {
	//		musicchannel.removeEventListener(Event.SOUND_COMPLETE, stopmusic);
	//		musicfade = 61;
	//	}
	//}

	//Mix_FadeOutMusic(2000);
	currentsong = -1;
}

void MusicClass::processmusicfade()
{
	//musicfade--;
	//if (musicfade > 0) {
	//	musicchannel.soundTransform = new SoundTransform(musicfade / 60);
	//}else {
	//	musicchannel.stop();
	//	currentsong = -1;
	//}
}

void MusicClass::processmusicfadein()
{
	musicVolume += FadeVolAmountPerFrame;
	/*
	Mix_VolumeMusic(musicVolume);
	if (musicVolume >= MIX_MAX_VOLUME)
	{
		m_doFadeInVol = false;
	}
	*/
}

void MusicClass::processmusic()
{
	if(!safeToProcessMusic)
	{
		return;
	}

	//if (musicfade > 0) processmusicfade();
	//if (musicfadein > 0) processmusicfadein();
	/*
	if (nicefade == 1 && Mix_PlayingMusic() == 0)
	{
		play(nicechange);
		nicechange = -1; nicefade = 0;
	}
	*/
	if(m_doFadeInVol)
	{
		processmusicfadein();
	}

	//musicstopother--;
	//if (musicstopother == 1) {
	//	musicstopother = 0;
	//	if (currentmusicchan == 0) musicchannel2.stop();
	//	if (currentmusicchan == 1) musicchannel.stop();
	//}
	//if (musicstopother < 0) musicstopother = 0;

	//musicchancur--;
	//if (musicchancur <= 0 && currentsong > -1 && musicchanlen > 0) {
	//	musicchancur = musicchanlen;
	//	if (currentmusicchan == 0) {
	//		musicchannel2 = musicchan[currentsong].play();
	//		musicstopother = 3;
	//		currentmusicchan = 1;
	//	}else {
	//		musicchannel = musicchan[currentsong].play();
	//		musicstopother = 3;
	//		currentmusicchan = 0;
	//	}
	//}
}


void MusicClass::niceplay(int t)
{
	// important: do nothing if the correct song is playing!
	if(currentsong!=t)
	{
		if(currentsong!=-1) fadeout();
		nicefade = 1;
		nicechange = t;
	}
}

void MusicClass::changemusicarea(int x, int y)
{
	switch(musicroom(x, y))
	{
	case musicroom(11, 4):
		niceplay(2);
		break;

	case musicroom(2, 4):
	case musicroom(7, 15):
		niceplay(3);
		break;

	case musicroom(18, 1):
	case musicroom(15, 0):
		niceplay(12);
		break;

	case musicroom(0, 0):
	case musicroom(0, 16):
	case musicroom(2, 11):
	case musicroom(7, 9):
	case musicroom(8, 11):
	case musicroom(13, 2):
	case musicroom(17, 12):
	case musicroom(14, 19):
	case musicroom(17, 17):
		niceplay(4);
		break;

	default:
		niceplay(1);
		break;
	}
}

void MusicClass::initefchannels()
{
	// for (var i:int = 0; i < 16; i++) efchannel.push(new SoundChannel);
}

void MusicClass::playef(int t, int offset)
{
	// efchannel[currentefchan] = efchan[t].play(offset);
	// currentefchan++;
	// if (currentefchan > 15) currentefchan -= 16;
	int channel;

	//channel = Mix_PlayChannel(-1, soundTracks[t].sound, 0);
	channel = -1;
	if(channel == -1)
	{
		//fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
	}
}
