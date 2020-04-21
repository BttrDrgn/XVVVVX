/*

	TODO: Redo the entire SoundSystem and merge it with Music

		  Get base game maps loading in a way that the VS 2003 compiler respects

		  Optimize performance of rendering (maybe redo renderer in DirectX so it
											 will be hardware accelerated)

*/

#include <SDL.h>
#include <xtl.h>
#include "filesystem.h"

#include "states/Preloader.h"

#include "SoundSystem.h"

#include "Utility.h"
#include "Game.h"
#include "Graphics.h"
#include "KeyPoll.h"
#include "titlerender.h"

#include "Map.h"

#include "Screen.h"

#include "Script.h"

#include "Logic.h"

#include "Input.h"
#include "Editor.h"

#include "FileSystemUtils.h"


#include <stdio.h>
#include <string.h>
#include <time.h>

ScriptClass script;
edentities edentity[3000];

EditorClass ed;


int main()
{
	if(!FILESYSTEM_init()) fs::log("FATAL ERROR!!!");
	srand(time(NULL));


    SDL_Init(
        SDL_INIT_VIDEO |
        SDL_INIT_AUDIO |
        SDL_INIT_JOYSTICK |
        SDL_INIT_GAMECONTROLLER
    );

	SDL_JoystickOpen(0);
	SDL_GameControllerOpen(0);

	

    Screen gameScreen;

	/* This looked cool and I didn't want to just get rid of it */
	fs::log("\t\t\n");
	fs::log("\t\t\n");
	fs::log("\t\t       VVVVVV\n");
	fs::log("\t\t\n");
	fs::log("\t\t\n");
	fs::log("\t\t  8888888888888888  \n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t888888    8888    88\n");
	fs::log("\t\t888888    8888    88\n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t888888            88\n");
	fs::log("\t\t88888888        8888\n");
	fs::log("\t\t  8888888888888888  \n");
	fs::log("\t\t      88888888      \n");
	fs::log("\t\t  8888888888888888  \n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t88888888888888888888\n");
	fs::log("\t\t8888  88888888  8888\n");
	fs::log("\t\t8888  88888888  8888\n");
	fs::log("\t\t    888888888888    \n");
	fs::log("\t\t    8888    8888    \n");
	fs::log("\t\t  888888    888888  \n");
	fs::log("\t\t  888888    888888  \n");
	fs::log("\t\t  888888    888888  \n");
	fs::log("\t\t\n");
	fs::log("\t\t\n");

    Graphics graphics;
    MusicClass music;
    Game game;
    game.infocus = true;

    graphics.MakeTileArray();
    graphics.MakeSpriteArray();
    graphics.maketelearray();

    graphics.images.push_back(graphics.grphx.im_image0);
    graphics.images.push_back(graphics.grphx.im_image1);
    graphics.images.push_back(graphics.grphx.im_image2);
    graphics.images.push_back(graphics.grphx.im_image3);
    graphics.images.push_back(graphics.grphx.im_image4);
    graphics.images.push_back(graphics.grphx.im_image5);
    graphics.images.push_back(graphics.grphx.im_image6);

    graphics.images.push_back(graphics.grphx.im_image7);
    graphics.images.push_back(graphics.grphx.im_image8);
    graphics.images.push_back(graphics.grphx.im_image9);
    graphics.images.push_back(graphics.grphx.im_image10);
    graphics.images.push_back(graphics.grphx.im_image11);
    graphics.images.push_back(graphics.grphx.im_image12);

    const SDL_PixelFormat* fmt = gameScreen.GetFormat();
    graphics.backBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, 32, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_SetSurfaceBlendMode(graphics.backBuffer, SDL_BLENDMODE_NONE);
    graphics.Makebfont();

    graphics.foregroundBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_SetSurfaceBlendMode(graphics.foregroundBuffer, SDL_BLENDMODE_NONE);

    graphics.screenbuffer = &gameScreen;

    graphics.menubuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_SetSurfaceBlendMode(graphics.menubuffer, SDL_BLENDMODE_NONE);

    graphics.towerbuffer =  SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_SetSurfaceBlendMode(graphics.towerbuffer, SDL_BLENDMODE_NONE);

	graphics.tempBuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, 320, 240, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
    SDL_SetSurfaceBlendMode(graphics.tempBuffer, SDL_BLENDMODE_NONE);

    game.gamestate = PRELOADER;

    game.menustart = false;
    game.mainmenu = 0;
    game.shouldQuit = false;

    KeyPoll key;
    MapClass map;

    map.ypos = (700 - 29) * 8;
    map.bypos = map.ypos / 2;

    game.loadstats(map, graphics);

    if (game.usingmmmmmm == 0) music.usingmmmmmm = false;
    if (game.usingmmmmmm == 1) music.usingmmmmmm = true;
    if (game.slowdown == 0) game.slowdown = 30;

	//Divided by 5 because the xbox only runs the game at like 20 fps.
	//Speeding up the game feels more natural.
    switch (game.slowdown){
        case 30:
            game.gameframerate = 34/5;
            break;

        case 24:
            game.gameframerate = 41/5;
            break;

        case 18:
            game.gameframerate = 55/5;
            break;

        case 12:
            game.gameframerate = 83/5;
            break;
        
        default:
            game.gameframerate = 34/5;
            break;
    }

    EntityClass obj;
    obj.init();

    volatile Uint32 time, timePrev = 0;
    game.infocus = true;
    key.isActive = true;

    while(!key.quitProgram)
    {
        time = SDL_GetTicks();

        //framerate limit to 30
        Uint32 timetaken = time - timePrev;

        if (game.gamestate == EDITORMODE)
		{
            if (timetaken < 24)
            {
                volatile Uint32 delay = 24 - timetaken;
                SDL_Delay( delay );
                time = SDL_GetTicks();
            }
            timePrev = time;
        }
        else
        {
            if (timetaken < game.gameframerate)
            {
                volatile Uint32 delay = game.gameframerate - timetaken;
                SDL_Delay( delay );
                time = SDL_GetTicks();
            }
            timePrev = time;
        }

        key.Poll();

        game.infocus = true;

        switch (game.gamestate)
        {
            case PRELOADER:
                states::Preloader::input(key, game);
                states::Preloader::render(graphics, game);
                break;

            case EDITORMODE:
                graphics.flipmode = false;
                editorinput(key, graphics, game, map, obj, music);
                editorrender(key, graphics, game, map, obj);
                editorlogic(key, graphics, game, obj, music, map);
                break;

            case TITLEMODE:
                titleinput(key, graphics, map, game, obj, music);
                titlerender(graphics, map, game, obj, music);
                titlelogic(graphics, game, obj, music, map);
                break;

            case GAMEMODE:
                if (map.towermode)
                {
                    gameinput(key, graphics, game, map, obj, music);
                    towerrender(graphics, game, map, obj);
                    towerlogic(graphics, game, obj, music, map);
                }
                else
                {
                    if (script.running)
                    {
                        script.run(key, graphics, game, map, obj, music);
                    }

                    gameinput(key, graphics, game, map, obj, music);
                    gamerender(graphics,map, game, obj);
                    gamelogic(graphics, game, obj, music, map);
                }
                break;

            case MAPMODE:
                mapinput(key, graphics, game, map, obj, music);
                maprender(graphics, game, map, obj);
                maplogic(graphics, game, obj, music, map);
                break;

            case TELEPORTERMODE:
                if(game.useteleporter)
                {
                    teleporterinput(key, graphics, game, map, obj, music);
                }
                else
                {
                    if (script.running)
                    {
                        script.run(key, graphics, game, map, obj, music);
                    }

                    gameinput(key, graphics, game, map, obj, music);
                }
                teleporterrender(graphics, game, map, obj);
                maplogic(graphics, game, obj, music, map);
                break;

            case GAMECOMPLETE:
                gamecompleteinput(key, graphics, game, map, obj, music);
                gamecompleterender(graphics, game, obj, map);
                gamecompletelogic(graphics, game, obj, music, map);
                break;

            case GAMECOMPLETE2:
                gamecompleteinput2(key, graphics, game, map, obj, music);
                gamecompleterender2(graphics, game, obj);
                gamecompletelogic2(graphics, game, obj, music, map);
                break;

            case CLICKTOSTART:
                vvvvvv::Utility::updateGlow();
                break;

            default:
                break;
        }

        if (game.savemystats)
        {
            game.savemystats = false;
            game.savestats(map, graphics);
        }

        music.processmusic();
        graphics.processfade();
        game.gameclock();
        gameScreen.FlipScreen();
    }

    SDL_Quit();

    return 0;
}
