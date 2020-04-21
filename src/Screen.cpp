#include "Screen.h"

#include "FileSystemUtils.h"
#include "GraphicsUtil.h"

#include <stdlib.h>

// Used to create the window icon

Screen::Screen()
{
    m_window = NULL;
    m_renderer = NULL;
    m_screenTexture = NULL;
    m_screen = NULL;
    isWindowed = false;
    stretchMode = 0;
    isFiltered = false;
    filterSubrect.x = 1;
    filterSubrect.y = 1;
    filterSubrect.w = 318;
    filterSubrect.h = 238;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);

	// Uncomment this next line when you need to debug -flibit
	// SDL_SetHintWithPriority(SDL_HINT_RENDER_DRIVER, "direct3d", SDL_HINT_OVERRIDE);
		SDL_CreateWindowAndRenderer(
			0,
			0,
			SDL_WINDOW_FULLSCREEN,
			&m_window,
			&m_renderer
		);

	// FIXME: This surface should be the actual backbuffer! -flibit
	m_screen = SDL_CreateRGBSurface(
		0,
		320,
		240,
		32,
		0x00FF0000,
		0x0000FF00,
		0x000000FF,
		0xFF000000
	);
	m_screenTexture = SDL_CreateTexture(
		m_renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		320,
		240
	);

    glScreen = true;
}

void Screen::ResizeScreen(int x , int y)
{
	SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN_DESKTOP);

	if (stretchMode == 1)
	{
		int winX, winY;
		SDL_GetWindowSize(m_window, &winX, &winY);
		SDL_RenderSetLogicalSize(m_renderer, winX, winY);
		SDL_RenderSetIntegerScale(m_renderer, SDL_FALSE);
	}
	else
	{
		SDL_RenderSetLogicalSize(m_renderer, 320, 240);
		SDL_RenderSetIntegerScale(m_renderer, (SDL_bool) (stretchMode == 2));
	}
	SDL_ShowWindow(m_window);
}

void Screen::GetWindowSize(int* x, int* y)
{
	SDL_GetWindowSize(m_window, x, y);
}

void Screen::UpdateScreen(SDL_Surface* buffer, SDL_Rect* rect )
{
    if((buffer == NULL) && (m_screen == NULL) )
    {
        return;
    }


    FillRect(m_screen, 0x000);
    BlitSurfaceStandard(buffer,NULL,m_screen,rect);

}

const SDL_PixelFormat* Screen::GetFormat()
{
    return m_screen->format;
}

void Screen::FlipScreen()
{
	SDL_UpdateTexture(
		m_screenTexture,
		NULL,
		m_screen->pixels,
		m_screen->pitch
	);
	SDL_RenderCopy(
		m_renderer,
		m_screenTexture,
		isFiltered ? &filterSubrect : NULL,
		NULL
	);
	SDL_RenderPresent(m_renderer);
	SDL_RenderClear(m_renderer);
	SDL_FillRect(m_screen, NULL, 0x00000000);
}

void Screen::toggleFullScreen()
{
	isWindowed = !isWindowed;
	ResizeScreen(-1, -1);
}

void Screen::toggleStretchMode()
{
	stretchMode = (stretchMode + 1) % 3;
	ResizeScreen(-1, -1);
}

void Screen::toggleLinearFilter()
{
	isFiltered = !isFiltered;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, isFiltered ? "linear" : "nearest");
	SDL_DestroyTexture(m_screenTexture);
	m_screenTexture = SDL_CreateTexture(
		m_renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		320,
		240
	);
}

void Screen::ClearScreen( int colour )
{
    //FillRect(m_screen, colour) ;
}
