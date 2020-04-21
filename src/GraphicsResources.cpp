#include "GraphicsResources.h"
#include "FileSystemUtils.h"
#include "filesystem.h"
#include "../lodepng/lodepng.h"
#include "../lodepng/lodepng.c"
#include <stdio.h>
#include <stdlib.h>

SDL_Surface* LoadImage(const char *filename, bool noBlend = true, bool noAlpha = false)
{
	/* https://www.gbgames.com/blog/2012/01/integrating-lodepng-with-an-sdl-project/ stolen from here shhh */
	std::vector<unsigned char> image;
    unsigned width, height;
    unsigned error = lodepng::decode(image, width, height, filename); //load the image file with given filename

    SDL_Surface * surface = 0;
    if (error == 0)
    {
        Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
#else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
#endif
        int depth = 32;
        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, depth, rmask, gmask, bmask, amask);

        // Lock the surface, then store the pixel data.
        SDL_LockSurface(surface);

        unsigned char * pixelPointer = static_cast<unsigned char *>(surface->pixels);
        for (std::vector<unsigned char>::iterator iter = image.begin();
                    iter != image.end();
                    ++iter)
        {
            *pixelPointer = *iter;
            ++pixelPointer;
        }

        SDL_UnlockSurface(surface);

		/*
        SDL_Surface * convertedSurface = SDL_DisplayFormatAlpha(surface);
        if (convertedSurface != NULL)
        {
            SDL_FreeSurface(surface);
            surface = convertedSurface;
        }
		*/
    }

    return surface;
}

GraphicsResources::GraphicsResources(void)
{
	im_tiles =		LoadImage("D:\\data\\graphics\\tiles.png");
	im_tiles2 =		LoadImage("D:\\data\\graphics\\tiles2.png");
	im_tiles3 =		LoadImage("D:\\data\\graphics\\tiles3.png");
	im_entcolours =		LoadImage("D:\\data\\graphics\\entcolours.png");
	im_sprites =		LoadImage("D:\\data\\graphics\\sprites.png");
	im_flipsprites =	LoadImage("D:\\data\\graphics\\flipsprites.png");
	im_bfont =		LoadImage("D:\\data\\graphics\\font.png");
	im_bfontmask =		LoadImage("D:\\data\\graphics\\fontmask.png");
	im_teleporter =		LoadImage("D:\\data\\graphics\\teleporter.png");

	im_image0 =		LoadImage("D:\\data\\graphics\\levelcomplete.png", false);
	im_image1 =		LoadImage("D:\\data\\graphics\\minimap.png", true, true);
	im_image2 =		LoadImage("D:\\data\\graphics\\covered.png", true, true);
	im_image3 =		LoadImage("D:\\data\\graphics\\elephant.png");
	im_image4 =		LoadImage("D:\\data\\graphics\\gamecomplete.png", false);
	im_image5 =		LoadImage("D:\\data\\graphics\\fliplevelcomplete.png", false);
	im_image6 =		LoadImage("D:\\data\\graphics\\flipgamecomplete.png", false);
	im_image7 =		LoadImage("D:\\data\\graphics\\site.png", false);
	im_image8 =		LoadImage("D:\\data\\graphics\\site2.png");
	im_image9 =		LoadImage("D:\\data\\graphics\\site3.png");
	im_image10 =		LoadImage("D:\\data\\graphics\\ending.png");
	im_image11 =		LoadImage("D:\\data\\graphics\\site4.png");
	im_image12 =		LoadImage("D:\\data\\graphics\\minimap.png");
}


GraphicsResources::~GraphicsResources(void)
{
}
